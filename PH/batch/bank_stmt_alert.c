
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
           char  filnam[19];
};
static struct sqlcxp sqlfpn =
{
    18,
    "bank_stmt_alert.pc"
};


static unsigned int sqlctx = 18149499;


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
"SELECT OLSD_STAT_TXN_ID , OLSD_STATEMENT_REF , OLSD_STATEMENT_SEQ , OLSD_TF\
R_BANK_NAME , OLSD_TFR_BANK_ACCT_NUM , OLSD_TFR_TYPE , OLSD_TFR_CHANNEL , OLS\
D_TFR_TEXT , OLSD_TFR_CUSTOMER_TEXT , OLSD_SENDER_NAME , OLSD_TXN_REF_NUM , O\
LSD_AMT_TYPE , OLSD_TXN_AMOUNT , OLSD_TXN_CCY , OLSD_BALANCE FROM OL_STATEMEN\
T_DETAIL WHERE OLSD_FILE_ID = :b0 AND OLSD_AMT_TYPE = 'DR' ORDER BY OLSD_STAT\
EMENT_SEQ ASC            ";

 static char *sq0002 = 
"SELECT OLFK_DISPLAY_ORDER , OLFT_CONT_DESC , OLFK_FORMAT_TEMPLATE FROM OL_S\
TATEMENT_HEADER , OL_BANK_ACCT_ID , OL_PSP_DETAIL , OL_STMT_FORMAT_TEMPLATE ,\
 OL_STMT_FORMAT_KEYWORDS WHERE OLSH_FILE_ID = :b0 AND OLSH_BAID = OBAI_BAID A\
ND OPD_PSP_ID = OBAI_PSP_ID AND OLFT_FORMAT_ID like OLSH_FORMAT_ID || '%' AND\
 OLSH_FORMAT_ID is not NULL AND OLFT_FORMAT_TYPE = 'CONTENT' AND OLFK_INT_BAN\
K_CODE = OLSH_INT_BANK_CODE AND OLFK_FORMAT_TYPE = 'ALERT_DR_' || OPD_BANK_AC\
CT_TYPE AND OLFK_DISABLED = 0 AND OLFK_FORMAT_COL_NAME = OLFT_CONT_COL_NAME  \
          ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,408,0,9,197,0,2049,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,13,200,0,0,15,0,0,1,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,
99,0,0,1,0,0,15,447,0,0,0,0,0,1,0,
114,0,0,1,0,0,15,467,0,0,0,0,0,1,0,
129,0,0,2,547,0,9,556,0,2049,1,1,0,1,0,1,9,0,0,
148,0,0,2,0,0,13,558,0,0,3,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,
175,0,0,2,0,0,15,601,0,0,0,0,0,1,0,
190,0,0,2,0,0,15,611,0,0,0,0,0,1,0,
205,0,0,3,599,0,4,653,0,0,7,1,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,1,9,0,0,
248,0,0,4,0,0,32,740,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/07/07		   Stan Poon
Handle Currency and Payout                         2014/07/23		   Stan Poon
Add mask_bank_acct_num into find_bank_info	   2019/05/02		   Michael Chow
Add provider name, bank statement details	   2019/01/31		   Michael Chow
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

#define PD_FULL_MATCH	0

/*int	i_file_id;*/
char	cs_file_id[PD_TXN_SEQ_LEN + 1];
char	cs_int_bank_code[PD_BANK_CODE_LEN + 1];
char	cs_bank_name[PD_BANK_NAME_LEN + 1];
char	cs_owner_name[PD_NAME_LEN + 1];
char	cs_bank_acct_type[PD_ACCT_TYPE_LEN + 1];
char	cs_mask_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1];	
char	cs_client_name[PD_CLIENT_NAME_LEN + 1];
char	cs_tfr_customer_text[PD_TFR_CUSTOMER_TEXT_LONG_LEN + 1];
char	cs_tfr_type[PD_TFR_TYPE_LONG_LEN + 1];
char	cs_tfr_channel[PD_TFR_CHANNEL_LONG_LEN + 1];
char	cs_tfr_text[PD_TFR_TEXT_LEN + 1];
char	cs_sender_name[PD_SENDER_NAME_LEN + 1];








recordset_t	*myRecDb;

#define PD_OPEN_TAG	"<tr><td>"
#define PD_NEXT_TAG	"</td><td>"
#define PD_END_TAG	"</td></tr>"

static char cDebug = 'Y';

int parse_arg(int argc, char **argv);
int process_txn_statement_detail();
int find_bank_info();
int find_alert_keywords();
int MultiKeywordsSearch(const char *csLine, char *csTemplate, int iFullMatch);

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}

int batch_proc(int argc, char* argv[])
{
	int iRet = SUCCESS;

	/*i_file_id = 0;*/
	//strcpy(cs_format_id,"");

	strcpy(cs_file_id, "");
	strcpy(cs_bank_name,"");
	strcpy(cs_owner_name,"");
	strcpy(cs_client_name,"");
	
	
	myRecDb = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(myRecDb,0);

	iRet = parse_arg(argc, argv);

	if (iRet != SUCCESS) {
printf("usage: -f file_id\n");

	} else {
		if (iRet == SUCCESS) {
			//cs_int_bank_code, cs_bank_name, cs_ower_name, cs_bank_acct_type
			iRet = find_bank_info();
		}
		if (iRet == SUCCESS) {
			//myRecDb
			iRet = find_alert_keywords();
		}
		if (iRet == SUCCESS) {
			iRet = process_txn_statement_detail();
		}

		if (iRet != SUCCESS &&
		    iRet != FAILURE) {
printf("<tr><td colspan='10'> fail </td></tr>\n");
		}
	}

	RecordSet_Destroy(myRecDb);
	FREE_ME(myRecDb);

	return iRet;
}

int process_txn_statement_detail()
{
	int	iRet = SUCCESS;
	int	iAltCnt = 0;
	int	iTmp;
	double	dTmp;
	char	*csTmp=NULL;
	char	*csGetAttribute=NULL;
	hash_t	*hDtl = (hash_t*) malloc (sizeof(hash_t));
	hash_t	*hRecDb;

	int	iMatchCount=0, iToMatchCount=0, iMatchNow=0;
	int	iDisplayOrder=0;
	char	*csDesc=NULL, *csTemplate=NULL, *csField=NULL; 

 DEBUGLOG(("process_txn_statement_detail() begin\n"));

	/* EXEC SQL WHENEVER SQLERROR GOTO stmtdetail_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		//int	hv_file_id;
		/* varchar         hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;


		/* varchar	v_stat_txn_id[PD_STMT_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_stat_txn_id;

		/* varchar	v_statement_ref[PD_STMT_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_statement_ref;

		int	v_statement_seq;
		/* varchar	v_tfr_bank_name[PD_TFR_BANK_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_tfr_bank_name;

		/* varchar	v_tfr_bank_acct_num[PD_TFR_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_tfr_bank_acct_num;

		/* varchar	v_tfr_type[PD_TFR_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_tfr_type;

		/* varchar	v_tfr_channel[PD_TFR_CHANNEL_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_tfr_channel;

		/* varchar	v_tfr_text[PD_TFR_TEXT_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_tfr_text;

		/* varchar	v_tfr_customer_text[PD_TFR_TEXT_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_tfr_customer_text;

		/* varchar	v_sender_name[PD_SENDER_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_sender_name;

		/* varchar	v_txn_ref_num[PD_TXN_REF_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_txn_ref_num;

		/* varchar	v_amt_type[PD_AMT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_amt_type;

		double	v_txn_amount;
		/* varchar	v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

		double	v_balance;

		short	ind_stat_txn_id = -1;
		short	ind_statement_ref = -1;
		short	ind_statement_seq = -1;
		short	ind_tfr_bank_name = -1;
		short	ind_tfr_bank_acct_num = -1;
		short	ind_tfr_type = -1;
		short	ind_tfr_channel = -1;
		short	ind_tfr_text = -1;
		short	ind_tfr_customer_text = -1;
		short	ind_sender_name = -1;
		short	ind_txn_ref_num = -1;
		short	ind_amt_type = -1;
		short	ind_txn_amount = -1;
		short	ind_txn_ccy = -1;
		short	ind_balance = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	//hv_file_id = i_file_id;
        hv_file_id.len = strlen(cs_file_id);
        strncpy((char*)hv_file_id.arr,cs_file_id,sizeof(hv_file_id.arr));

	/* EXEC SQL DECLARE c_cursor_stmtdetail CURSOR FOR
		SELECT	OLSD_STAT_TXN_ID,
                        OLSD_STATEMENT_REF,
			OLSD_STATEMENT_SEQ,
			OLSD_TFR_BANK_NAME,
			OLSD_TFR_BANK_ACCT_NUM,
			OLSD_TFR_TYPE,
			OLSD_TFR_CHANNEL,
			OLSD_TFR_TEXT,
			OLSD_TFR_CUSTOMER_TEXT,
			OLSD_SENDER_NAME,
			OLSD_TXN_REF_NUM,
			OLSD_AMT_TYPE,
			OLSD_TXN_AMOUNT,
			OLSD_TXN_CCY,
			OLSD_BALANCE
		FROM	OL_STATEMENT_DETAIL
		WHERE	OLSD_FILE_ID = :hv_file_id
		AND	OLSD_AMT_TYPE = 'DR'
		ORDER BY OLSD_STATEMENT_SEQ ASC; */ 


	/* EXEC SQL OPEN c_cursor_stmtdetail; */ 

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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_file_id;
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
 if (sqlca.sqlcode < 0) goto stmtdetail_error;
}



	for (;;) {
		/* EXEC SQL FETCH c_cursor_stmtdetail
		INTO	:v_stat_txn_id:ind_stat_txn_id,
			:v_statement_ref:ind_statement_ref,
			:v_statement_seq:ind_statement_seq,
			:v_tfr_bank_name:ind_tfr_bank_name,
			:v_tfr_bank_acct_num:ind_tfr_bank_acct_num,
			:v_tfr_type:ind_tfr_type,
			:v_tfr_channel:ind_tfr_channel,
			:v_tfr_text:ind_tfr_text,
			:v_tfr_customer_text:ind_tfr_customer_text,
			:v_sender_name:ind_sender_name,
			:v_txn_ref_num:ind_txn_ref_num,
			:v_amt_type:ind_amt_type,
			:v_txn_amount:ind_txn_amount,
			:v_txn_ccy:ind_txn_ccy,
			:v_balance:ind_balance; */ 

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
  sqlstm.sqhstv[0] = (unsigned char  *)&v_stat_txn_id;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_stat_txn_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_statement_ref;
  sqlstm.sqhstl[1] = (unsigned long )19;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_statement_ref;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_statement_seq;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_statement_seq;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_tfr_bank_name;
  sqlstm.sqhstl[3] = (unsigned long )203;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_tfr_bank_name;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_tfr_bank_acct_num;
  sqlstm.sqhstl[4] = (unsigned long )203;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_tfr_bank_acct_num;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_tfr_type;
  sqlstm.sqhstl[5] = (unsigned long )203;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_tfr_type;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_tfr_channel;
  sqlstm.sqhstl[6] = (unsigned long )203;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_tfr_channel;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_tfr_text;
  sqlstm.sqhstl[7] = (unsigned long )203;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_tfr_text;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_tfr_customer_text;
  sqlstm.sqhstl[8] = (unsigned long )203;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_tfr_customer_text;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_sender_name;
  sqlstm.sqhstl[9] = (unsigned long )203;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_sender_name;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_txn_ref_num;
  sqlstm.sqhstl[10] = (unsigned long )203;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_txn_ref_num;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_amt_type;
  sqlstm.sqhstl[11] = (unsigned long )5;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_amt_type;
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
  sqlstm.sqhstv[14] = (unsigned char  *)&v_balance;
  sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_balance;
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
  if (sqlca.sqlcode < 0) goto stmtdetail_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		hash_init(hDtl,0);

		// stat_txn_id
		if (ind_stat_txn_id >= 0) {
			v_stat_txn_id.arr[v_stat_txn_id.len] = '\0';
			PutField_CString(hDtl, "stat_txn_id", (const char*)v_stat_txn_id.arr);
 DEBUGLOG(("process_txn_statement_detail() stat_txn_id = [%s]\n", (const char*)v_stat_txn_id.arr));
		}

		// statement_ref
		if (ind_statement_ref >= 0) {
			v_statement_ref.arr[v_statement_ref.len] = '\0';
			PutField_CString(hDtl, "stmt_ref", (const char*)v_statement_ref.arr);
 DEBUGLOG(("process_txn_statement_detail() stmt_ref = [%s]\n", (const char*)v_statement_ref.arr));
		}

		// statement_seq
		if (ind_statement_seq >= 0) {
			PutField_Int(hDtl, "statement_seq", v_statement_seq);
 DEBUGLOG(("process_txn_statement_detail() statement_seq = [%d]\n", v_statement_seq));
		}

		// tfr_bank_name
		if (ind_tfr_bank_name >= 0) {
			v_tfr_bank_name.arr[v_tfr_bank_name.len] = '\0';
			PutField_CString(hDtl, "tfr_bank_name", (const char*)v_tfr_bank_name.arr);
 DEBUGLOG(("process_txn_statement_detail() tfr_bank_name = [%s]\n", (const char*)v_tfr_bank_name.arr));
		}

		// tfr_bank_acct_num
		if (ind_tfr_bank_acct_num >= 0) {
			v_tfr_bank_acct_num.arr[v_tfr_bank_acct_num.len] = '\0';
			PutField_CString(hDtl, "tfr_bank_acct_num", (const char*)v_tfr_bank_acct_num.arr);
 DEBUGLOG(("process_txn_statement_detail() tfr_bank_acct_num = [%s]\n", (const char*)v_tfr_bank_acct_num.arr));
		}

		// tfr_type
		if (ind_tfr_type >= 0) {
			v_tfr_type.arr[v_tfr_type.len] = '\0';
			PutField_CString(hDtl, "tfr_type", (const char*)v_tfr_type.arr);
 DEBUGLOG(("process_txn_statement_detail() tfr_type = [%s]\n", (const char*)v_tfr_type.arr));
		}

		// tfr_channel
		if (ind_tfr_channel >= 0) {
			v_tfr_channel.arr[v_tfr_channel.len] = '\0';
			PutField_CString(hDtl, "tfr_channel", (const char*)v_tfr_channel.arr);
 DEBUGLOG(("process_txn_statement_detail() tfr_channel = [%s]\n", (const char*)v_tfr_channel.arr));
		}

		// tfr_text
		if (ind_tfr_text >= 0) {
			v_tfr_text.arr[v_tfr_text.len] = '\0';
			PutField_CString(hDtl, "tfr_text", (const char*)v_tfr_text.arr);
 DEBUGLOG(("process_txn_statement_detail() tfr_text = [%s]\n", (const char*)v_tfr_text.arr));
		}

		// tfr_customer_text
		if (ind_tfr_customer_text >= 0) {
			v_tfr_customer_text.arr[v_tfr_customer_text.len] = '\0';
			PutField_CString(hDtl, "tfr_customer_text", (const char*)v_tfr_customer_text.arr);
 DEBUGLOG(("process_txn_statement_detail() tfr_customer_text = [%s]\n", (const char*)v_tfr_customer_text.arr));
		}

		// sender_name
		if (ind_sender_name >= 0) {
			v_sender_name.arr[v_sender_name.len] = '\0';
			PutField_CString(hDtl, "sender_name", (const char*)v_sender_name.arr);
 DEBUGLOG(("process_txn_statement_detail() sender_name = [%s]\n", (const char*)v_sender_name.arr));
		}

		// txn_ref_num
		if (ind_txn_ref_num >= 0) {
			v_txn_ref_num.arr[v_txn_ref_num.len] = '\0';
			PutField_CString(hDtl, "txn_ref_num", (const char*)v_txn_ref_num.arr);
 DEBUGLOG(("process_txn_statement_detail() txn_ref_num = [%s]\n", (const char*)v_txn_ref_num.arr));
		}

		// amt_type
		if (ind_amt_type >= 0) {
			v_amt_type.arr[v_amt_type.len] = '\0';
			PutField_CString(hDtl, "amt_type", (const char*)v_amt_type.arr);
 DEBUGLOG(("process_txn_statement_detail() amt_type = [%s]\n", (const char*)v_amt_type.arr));
		}

		// txn_amount
		if (ind_txn_amount >= 0) {
			PutField_Double(hDtl, "txn_amount", v_txn_amount);
 DEBUGLOG(("process_txn_statement_detail() txn_amount = [%.2lf]\n", v_txn_amount));
		}

		// txn_ccy
		if (ind_txn_ccy >= 0) {
			v_txn_ccy.arr[v_txn_ccy.len] = '\0';
			PutField_CString(hDtl, "txn_ccy", (const char*)v_txn_ccy.arr);
 DEBUGLOG(("process_txn_statement_detail() txn_ccy = [%s]\n", (const char*)v_txn_ccy.arr));
		}

		// balance
		if (ind_balance >= 0) {
			PutField_Double(hDtl, "balance", v_balance);
 DEBUGLOG(("process_txn_statement_detail() balance = [%.2lf]\n", v_balance));
		}

		GetField_Double(hDtl,"txn_amount",&dTmp);
		GetField_CString(hDtl,"txn_ccy",&csTmp);
		
/*tfr_type*/
		if(GetField_CString(hDtl,"tfr_type",&csGetAttribute)){
			strcpy(cs_tfr_type,(char*)csGetAttribute);
		}
		else{
			strcpy(cs_tfr_type,"");
		}
/*tfr_channel*/
		if(GetField_CString(hDtl,"tfr_channel",&csGetAttribute)){
			strcpy(cs_tfr_channel,(char*)csGetAttribute);
		}
		else{
			strcpy(cs_tfr_channel,"");
		}
/*tfr_text*/
		if(GetField_CString(hDtl,"tfr_text",&csGetAttribute)){
			strcpy(cs_tfr_text,(char*)csGetAttribute);
		}
		else{
			strcpy(cs_tfr_text,"");
		}
/*tfr_customer_text*/
		if(GetField_CString(hDtl,"tfr_customer_text",&csGetAttribute)){
			strcpy(cs_tfr_customer_text,(char*)csGetAttribute);
		}
		else{
			strcpy(cs_tfr_customer_text,"");
		}
/*sender_name*/
		if(GetField_CString(hDtl,"sender_name",&csGetAttribute)){
			strcpy(cs_sender_name,(char*)csGetAttribute);
		}
		else{
			strcpy(cs_sender_name,"");
		}
		
/*
	if txn_amt < 100 & keywords match
	if txn_amt >= 100 & integer
	if txn_amt >= 100 & not integer & keywords match

	then alert
*/

		if (dTmp + 1E-9 >= 100.0 && (long)dTmp + 1E-9 >= dTmp &&
		    !strcmp(csTmp,PD_CCY_ISO_CNY) &&
		    !strcmp(cs_bank_acct_type,"DSI")) {
			iAltCnt++;
	printf("<tr><td>%s</td><td>%s</td><td>%s</td><td>%.2lf</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>\n",
		cs_bank_name,
		cs_owner_name,
		cs_mask_bank_acct_num,
		dTmp,
		cs_client_name,
		cs_tfr_customer_text,
		cs_tfr_type,
		cs_tfr_channel,
		cs_tfr_text,
		cs_sender_name);
 DEBUGLOG(("process_txn_statement_detail() Amount Matched ***\n"));
		} else {
			iMatchCount = 0;
			iToMatchCount = 0;
			hRecDb = RecordSet_GetFirst(myRecDb); // Format Keywords
			while (hRecDb) {
					GetField_Int(hRecDb,"display_order",&iDisplayOrder);

					GetField_CString(hRecDb,"cont_desc",&csDesc);
					GetField_CString(hRecDb,"format_template",&csTemplate);
					if (GetField_CString(hDtl,csDesc,&csField)) {
 DEBUGLOG(("process_txn_statement_detail() (%s)[%s] / [%s]\n",csDesc,csField,csTemplate));
						if (MultiKeywordsSearch(csField,csTemplate,PD_FULL_MATCH) == FOUND) {
							iMatchCount++;
 DEBUGLOG(("process_txn_statement_detail() MultiKeywordsSearch() Matched\n"));
						}
					}

					iToMatchCount++;

					hRecDb = RecordSet_GetNext(myRecDb);
					if (hRecDb != NULL) {
						GetField_Int(hRecDb,"display_order",&iTmp);
						if (iTmp != iDisplayOrder) {
							iMatchNow = 1;
						} else {
							iMatchNow = 0;
						}
					} else {
						iMatchNow = 1;
					}
			/* Keywords Matched */
				if (iMatchCount == iToMatchCount && iMatchNow == 1) {
					iAltCnt++;
	printf("<tr><td>%s</td><td>%s</td><td>%s</td><td>%.2lf</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>\n",
		cs_bank_name,
		cs_owner_name,
		cs_mask_bank_acct_num,
		dTmp,
		cs_client_name,
		cs_tfr_customer_text,
		cs_tfr_type,
		cs_tfr_channel,
		cs_tfr_text,
		cs_sender_name);
 DEBUGLOG(("process_txn_statement_detail() Keywords Matched ***\n"));
					break;
				}

				//Reset Count
				if (iMatchNow == 1) {
					iMatchCount = 0;
					iToMatchCount = 0;
				}
			} // while (hRecDb)

		}

		hash_destroy(hDtl);
	}
	/* EXEC SQL CLOSE c_cursor_stmtdetail; */ 

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
 if (sqlca.sqlcode < 0) goto stmtdetail_error;
}



	if (iAltCnt > 0) {
		iRet = FAILURE; //FOUND 1
 DEBUGLOG(("process_txn_statement_detail() FOUND\n"));
	} else {
		iRet = SUCCESS; //NOT_FOUND 0
 DEBUGLOG(("process_txn_statement_detail() NOT FOUND\n"));
	}

	FREE_ME(hDtl);

 DEBUGLOG(("process_txn_statement_detail() Ret = [%d]\n",iRet));
	return iRet;

stmtdetail_error:
DEBUGLOG(("stmtdetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStatement stmtdetail_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL CLOSE c_cursor_stmtdetail; */ 

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
 if (sqlca.sqlcode < 0) goto stmtdetail_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int find_alert_keywords()
{
	int iRet = SUCCESS;
	int iCnt = 0;

	hash_t *myHash;

 DEBUGLOG(("find_alert_keywords() begin\n"));

	/* EXEC SQL WHENEVER SQLERROR GOTO getkeywordserror; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/*int	hv_file_id;*/
		/* varchar         hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

/*
		varchar	hv_int_bank_code[PD_BANK_CODE_LEN];
		varchar	hv_bank_acct_type[PD_ACCT_TYPE_LEN];
*/
		int	v_display_order;
		/* varchar	v_cont_desc[PD_CONT_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_cont_desc;

		/* varchar	v_format_template[PD_FORMAT_TEMPLATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[501]; } v_format_template;


		short	ind_display_order = -1;
		short	ind_cont_desc = -1;
		short	ind_format_template = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	//hv_file_id = i_file_id;
// file_id
        hv_file_id.len = strlen(cs_file_id);
        strncpy((char*)hv_file_id.arr,cs_file_id,sizeof(hv_file_id.arr));


/*
	hv_int_bank_code.len = strlen(cs_int_bank_code);
	memcpy(hv_int_bank_code.arr,cs_int_bank_code,hv_int_bank_code.len);

	hv_bank_acct_type.len = strlen(cs_bank_acct_type);
	memcpy(hv_bank_acct_type.arr,cs_bank_acct_type,hv_bank_acct_type.len);
*/

	/* EXEC SQL DECLARE getkeywordscursor CURSOR FOR
		SELECT	OLFK_DISPLAY_ORDER,
			OLFT_CONT_DESC,
			OLFK_FORMAT_TEMPLATE
		FROM	OL_STATEMENT_HEADER,
			OL_BANK_ACCT_ID,
			OL_PSP_DETAIL,
			OL_STMT_FORMAT_TEMPLATE,
			OL_STMT_FORMAT_KEYWORDS
		WHERE	OLSH_FILE_ID = :hv_file_id
		AND	OLSH_BAID = OBAI_BAID
		AND	OPD_PSP_ID = OBAI_PSP_ID
		AND	OLFT_FORMAT_ID like OLSH_FORMAT_ID || '%'
		AND	OLSH_FORMAT_ID is not NULL --in case format_id not updated
		AND	OLFT_FORMAT_TYPE = 'CONTENT'
		AND	OLFK_INT_BANK_CODE = OLSH_INT_BANK_CODE
		AND	OLFK_FORMAT_TYPE = 'ALERT_DR_'||OPD_BANK_ACCT_TYPE
		AND	OLFK_DISABLED = 0
		AND	OLFK_FORMAT_COL_NAME = OLFT_CONT_COL_NAME; */ 

/*
		SELECT	TK.OLFK_DISPLAY_ORDER,
			TP.OLFT_CONT_DESC,
			TK.OLFK_FORMAT_TEMPLATE
		FROM	(SELECT	OLFT_CONT_DESC,
				OLFT_CONT_COL_NAME
			FROM	OL_STMT_FORMAT,
				OL_STMT_FORMAT_TEMPLATE
			WHERE	OLSF_INT_BANK_CODE = :hv_int_bank_code
			AND	OLSF_DISABLED = 0
			AND	OLSF_EFFECT_TIMESTAMP <= sysdate
			AND	(OLFT_FORMAT_ID = OLSF_FORMAT_ID or OLFT_FORMAT_ID like OLSF_FORMAT_ID||'.%')
			AND	OLFT_FORMAT_TYPE = 'CONTENT'
			group by OLFT_CONT_DESC,OLFT_CONT_COL_NAME) TP,
			OL_STMT_FORMAT_KEYWORDS TK
		WHERE	TK.OLFK_INT_BANK_CODE = :hv_int_bank_code
		AND	TK.OLFK_FORMAT_TYPE = 'ALERT_DR_'||:hv_bank_acct_type
		AND	TK.OLFK_DISABLED = 0
		AND	TK.OLFK_FORMAT_COL_NAME = TP.OLFT_CONT_COL_NAME
		ORDER BY TK.OLFK_DISPLAY_ORDER ASC;
*/

	/* EXEC SQL OPEN getkeywordscursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )129;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_file_id;
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
 if (sqlca.sqlcode < 0) goto getkeywordserror;
}


	for (;;) {
		/* EXEC SQL FETCH getkeywordscursor
		INTO	:v_display_order:ind_display_order,
			:v_cont_desc:ind_cont_desc,
			:v_format_template:ind_format_template; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )148;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_display_order;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_display_order;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_cont_desc;
  sqlstm.sqhstl[1] = (unsigned long )53;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_cont_desc;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_format_template;
  sqlstm.sqhstl[2] = (unsigned long )503;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_format_template;
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
  if (sqlca.sqlcode < 0) goto getkeywordserror;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash, 0);


/* display_order */
		if (ind_display_order >= 0) {
			PutField_Int(myHash, "display_order", v_display_order);
 DEBUGLOG(("find_alert_keywords() display_order = [%d]\n",v_display_order));
		} else {
			iRet = PD_ERR;
		}

/* cont_desc */
		if (ind_cont_desc >= 0) {
			v_cont_desc.arr[v_cont_desc.len] = '\0';
			PutField_CString(myHash, "cont_desc", (char*)v_cont_desc.arr);
 DEBUGLOG(("find_alert_keywords() cont_desc = [%s]\n",v_cont_desc.arr));
		} else {
			iRet = PD_ERR;
		}

/* format_template */
		if (ind_format_template >= 0) {
			v_format_template.arr[v_format_template.len] = '\0';
			PutField_CString(myHash, "format_template", (char*)v_format_template.arr);
 DEBUGLOG(("find_alert_keywords() format_template = [%s]\n",v_format_template.arr));
		} else {
			iRet = PD_ERR;
		}

		RecordSet_Add(myRecDb,myHash);
	}
	/* EXEC SQL CLOSE getkeywordscursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )175;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getkeywordserror;
}



 DEBUGLOG(("find_alert_keywords() Ret = [%d]\n",iRet));
	return iRet;

getkeywordserror:
DEBUGLOG(("getkeywordserror code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStmtFormat getkeywordserror code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL CLOSE getkeywordscursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )190;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getkeywordserror;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int find_bank_info()
{
	int     iRet = SUCCESS;

 DEBUGLOG(("find_bank_info() begin\n"));

	/* EXEC SQL WHENEVER SQLERROR GOTO find_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		//int	hv_file_id;
		/* varchar	hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;


		/* varchar	v_int_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_int_bank_code;

		/* varchar	v_bank_name[PD_BANK_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

		/* varchar	v_owner_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_owner_name;

		/* varchar v_mask_bank_acct_num[PD_BANK_ACCT_NUM_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_mask_bank_acct_num;
		
		/* varchar v_bank_acct_type[PD_ACCT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_bank_acct_type;

		/* varchar v_client_name[PD_CLIENT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_client_name;


		short	ind_int_bank_code = -1;
		short	ind_bank_name = -1;
		short	ind_owner_name = -1;
		short	ind_mask_bank_acct_num = -1;				
		short	ind_bank_acct_type = -1;
		short	ind_client_name = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	/*
	hv_file_id = i_file_id;
	*/
	hv_file_id.len = strlen(cs_file_id);
        strncpy((char*)hv_file_id.arr,cs_file_id,sizeof(hv_file_id.arr));

	/* EXEC SQL
		SELECT	OLSH_INT_BANK_CODE,
			BANK_NAME,
			sp_mask_owner_name(OB_INT_BANK_CODE,OB_OWNER_NAME),		
			sp_mask_bank_acct_num(OB_INT_BANK_CODE,OB_BANK_ACCT_NUM),	
			OPD_BANK_ACCT_TYPE,
			PM_CLIENT_NAME
		INTO	:v_int_bank_code:ind_int_bank_code,
			:v_bank_name:ind_bank_name,
			:v_owner_name:ind_owner_name,
			:v_mask_bank_acct_num:ind_mask_bank_acct_num,		
			:v_bank_acct_type:ind_bank_acct_type,
			:v_client_name:ind_client_name
		FROM	OL_STATEMENT_HEADER,
			OL_BANK_ACCTS,
			OL_BANK_ACCT_ID,
			BANK_DESC,
			OL_PSP_DETAIL,
			PSP_MASTER
		WHERE	OLSH_FILE_ID = :hv_file_id
		AND	OLSH_INT_BANK_CODE = OB_INT_BANK_CODE
		AND	OLSH_BANK_ACCT_NUM = OB_BANK_ACCT_NUM
		AND	OLSH_BAID = OBAI_BAID
		AND	OLSH_INT_BANK_CODE = INTERNAL_BANK_CODE
		AND	OPD_PSP_ID = OBAI_PSP_ID
		AND OPD_CLIENT_ID = PM_CLIENT_ID
		; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select OLSH_INT_BANK_CODE , BANK_NAME , sp_mask_owner_name \
( OB_INT_BANK_CODE , OB_OWNER_NAME ) , sp_mask_bank_acct_num ( OB_INT_BANK_CO\
DE , OB_BANK_ACCT_NUM ) , OPD_BANK_ACCT_TYPE , PM_CLIENT_NAME INTO :b0:b1 , :\
b2:b3 , :b4:b5 , :b6:b7 , :b8:b9 , :b10:b11 FROM OL_STATEMENT_HEADER , OL_BAN\
K_ACCTS , OL_BANK_ACCT_ID , BANK_DESC , OL_PSP_DETAIL , PSP_MASTER WHERE OLSH\
_FILE_ID = :b12 AND OLSH_INT_BANK_CODE = OB_INT_BANK_CODE AND OLSH_BANK_ACCT_\
NUM = OB_BANK_ACCT_NUM AND OLSH_BAID = OBAI_BAID AND OLSH_INT_BANK_CODE = INT\
ERNAL_BANK_CODE AND OPD_PSP_ID = OBAI_PSP_ID AND OPD_CLIENT_ID = PM_CLIENT_ID\
 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )205;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_int_bank_code;
 sqlstm.sqhstl[0] = (unsigned long )13;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_bank_name;
 sqlstm.sqhstl[1] = (unsigned long )153;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_bank_name;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_owner_name;
 sqlstm.sqhstl[2] = (unsigned long )53;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_owner_name;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&v_mask_bank_acct_num;
 sqlstm.sqhstl[3] = (unsigned long )53;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_mask_bank_acct_num;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&v_bank_acct_type;
 sqlstm.sqhstl[4] = (unsigned long )6;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_bank_acct_type;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&v_client_name;
 sqlstm.sqhstl[5] = (unsigned long )53;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_client_name;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[6] = (unsigned long )18;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto find_error;
}



	if (ind_int_bank_code >= 0) {
		v_int_bank_code.arr[v_int_bank_code.len]='\0';
		strcpy(cs_int_bank_code,(char*)v_int_bank_code.arr);
 DEBUGLOG(("find_bank_info() int_bank_code = [%s]\n",v_int_bank_code.arr));
	} else {
		iRet = PD_ERR;
	}

	if (ind_bank_name >= 0) {
		v_bank_name.arr[v_bank_name.len]='\0';
		strcpy(cs_bank_name,(char*)v_bank_name.arr);
 DEBUGLOG(("find_bank_info() bank_name = [%s]\n",v_bank_name.arr));
	} else {
		iRet = PD_ERR;
	}

	if (ind_owner_name >= 0) {
		v_owner_name.arr[v_owner_name.len]='\0';
		strcpy(cs_owner_name,(char*)v_owner_name.arr);
 DEBUGLOG(("find_bank_info() owner_name = [%s]\n",v_owner_name.arr));
	} else {
		iRet = PD_ERR;
	}

	if (ind_mask_bank_acct_num >= 0) {
		v_mask_bank_acct_num.arr[v_mask_bank_acct_num.len]='\0';
		strcpy(cs_mask_bank_acct_num,(char*)v_mask_bank_acct_num.arr);
 DEBUGLOG(("find_bank_info() mask_bank_acct_num = [%s]\n",v_mask_bank_acct_num.arr));
	} else {
		iRet = PD_ERR;
	}

	if (ind_bank_acct_type >= 0) {
		v_bank_acct_type.arr[v_bank_acct_type.len]='\0';
		strcpy(cs_bank_acct_type,(char*)v_bank_acct_type.arr);
 DEBUGLOG(("find_bank_info() bank_acct_type = [%s]\n",v_bank_acct_type.arr));
	} else {
		iRet = PD_ERR;
	}

	if (ind_client_name >= 0) {
		v_client_name.arr[v_client_name.len]='\0';
		strcpy(cs_client_name,(char*)v_client_name.arr);
 DEBUGLOG(("find_bank_info() client_name = [%s]\n",v_client_name.arr));
	} else {
		iRet = PD_ERR;
	}
	
	
	
	
	
 DEBUGLOG(("find_bank_info() Ret = [%d]\n",iRet));
	return iRet;

find_error:
DEBUGLOG(("find_bank_info() error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 15;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )248;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

int parse_arg(int argc, char **argv)
{
	if (argc < 3) {
		return PD_ERR;
	}

	char    c;

	while ((c = getopt(argc,argv,"f:")) != EOF) {
		switch (c) {
			case 'f':
				/*
				i_file_id = atoi(optarg);
 DEBUGLOG(("parse_arg() file_id = [%s] \n",optarg));
				*/

				strcpy(cs_file_id, optarg);
 DEBUGLOG(("parse_arg() file_id = [%s] \n",cs_file_id));
				break;
			default:
				return PD_ERR;
		}
	}

	return SUCCESS;
}

int MultiKeywordsSearch(const char *csLine, char *csTemplate, int iFullMatch)
{
	char *csTemplateField;
	csTemplateField = mystrtok(csTemplate, ",");
	while (csTemplateField != NULL) {

		if (!strcmp(csTemplateField,"")) continue;

		if (iFullMatch == 0 && strstr(csLine, csTemplateField) != NULL) {
DEBUGLOG(("MultiKeywordsSearch() Contains\n"));
			return FOUND;

		} else if (iFullMatch == 1 && !strcmp(csLine, csTemplateField)) {
DEBUGLOG(("MultiKeywordsSearch() Full Match\n"));
			return FOUND;

		} else if (!strcmp(csTemplateField,"NOTNULL") && strcmp(csLine,"")) {
DEBUGLOG(("MultiKeywordsSearch() NOTNULL Match\n"));
			return FOUND;

		} else if (!strcmp(csTemplateField,"NULL") && !strcmp(csLine,"")) {
DEBUGLOG(("MultiKeywordsSearch() NULL Match\n"));
			return FOUND;
		}
		csTemplateField = mystrtok(NULL, ",");
	}
	return NOT_FOUND;
}

