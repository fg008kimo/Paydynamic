
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
    "offline_set_dsi_baid_init_bal.pc"
};


static unsigned int sqlctx = 953217803;


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
   unsigned char  *sqhstv[5];
   unsigned long  sqhstl[5];
            int   sqhsts[5];
            short *sqindv[5];
            int   sqinds[5];
   unsigned long  sqharm[5];
   unsigned long  *sqharc[5];
   unsigned short  sqadto[5];
   unsigned short  sqtdso[5];
} sqlstm = {12,5};

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
"select obai_baid , ob_acct_ccy , opd_psp_id , country , ob_status_type from\
 ol_bank_acct_id , ol_bank_accts , ol_psp_detail , bank_desc where obai_statu\
s = 'O' and obai_int_bank_code = ob_int_bank_code and obai_bank_acct_num = ob\
_bank_acct_num and obai_psp_id = opd_psp_id and opd_bank_acct_type = :b0 and \
ob_int_bank_code = internal_bank_code            ";

 static char *sq0002 = 
"select obab_bal from ol_baid_bal where obab_baid = :b0 and obab_country_id \
= :b1 and obab_currency_id = :b2            ";

 static char *sq0003 = 
"select olsd_stat_txn_id , olsd_balance from ( select * from ol_statement_de\
tail where olsd_baid = :b0 and olsd_statement_ref is not null and olsd_create\
_timestamp < to_date ( :b1 , 'yyyymmddhh24miss' ) + 1 / 24 / 60 / 60 order by\
 olsd_file_id desc , olsd_statement_seq desc ) where rownum = 1            ";

 static char *sq0004 = 
"select olsd_stat_txn_id , olsd_txn_amount from ol_statement_detail , ol_bai\
d_txn where olsd_baid = :b0 and olsd_input_channel = 'SMS_STMT' and olsd_amt_\
type = 'CR' and olsd_statement_ref is null and olsd_create_timestamp < to_dat\
e ( :b1 , 'yyyymmddhh24miss' ) + 1 / 24 / 60 / 60 and obt_stat_txn_id = olsd_\
stat_txn_id and obt_txn_code = 'OBD' and obt_status = 'C' and obt_ar_ind = 'A\
' and obt_sub_status = '118'            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,355,0,9,99,0,2049,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,13,106,0,0,5,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,1,0,0,
59,0,0,2,119,0,9,171,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
86,0,0,2,0,0,13,173,0,0,1,0,0,1,0,2,4,0,0,
105,0,0,2,0,0,15,179,0,0,0,0,0,1,0,
120,0,0,2,0,0,15,183,0,0,0,0,0,1,0,
135,0,0,3,304,0,9,204,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
158,0,0,3,0,0,13,206,0,0,2,0,0,1,0,2,9,0,0,2,4,0,0,
181,0,0,3,0,0,15,225,0,0,0,0,0,1,0,
196,0,0,3,0,0,15,235,0,0,0,0,0,1,0,
211,0,0,3,0,0,15,240,0,0,0,0,0,1,0,
226,0,0,4,423,0,9,260,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
249,0,0,4,0,0,13,263,0,0,2,0,0,1,0,2,9,0,0,2,4,0,0,
272,0,0,4,0,0,15,291,0,0,0,0,0,1,0,
287,0,0,1,0,0,15,376,0,0,0,0,0,1,0,
302,0,0,1,0,0,15,390,0,0,0,0,0,1,0,
317,0,0,2,0,0,15,391,0,0,0,0,0,1,0,
332,0,0,3,0,0,15,392,0,0,0,0,0,1,0,
347,0,0,5,0,0,32,393,0,0,0,0,0,1,0,
};


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include "common.h"
#include "utilitys.h"
#include "curl/curl.h"
#include "ObjPtr.h"
#include "myrecordset.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

OBJPTR(DB);
OBJPTR(Txn);

char cDebug = 'Y';
char csCutoffDatetime[PD_DATE_LEN + PD_TIME_LEN + 1];

int parse_arg(int argc, char **argv);

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int iRet = PD_OK;

	iRet = parse_arg(argc, argv);

	if (iRet != SUCCESS) {
		printf("Usage: offline_set_dsi_baid_init_bal.exec -d cut_off_datetime\n");
		return (PD_ERR);
	}

	int iTmpRet;
	char csNewPspTxnSeq[PD_TXN_SEQ_LEN + 1];
	int iCreateTxn;

	hash_t *myHash;
	myHash = (hash_t*) malloc (sizeof(hash_t));
	hash_init(myHash, 0);

	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_type_deposit[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_type_deposit;

		/* varchar hv_cutoff_datetime[PD_DATE_LEN + PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_cutoff_datetime;


		/* varchar v_baid[PD_BAID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_baid;

		/* varchar v_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ccy;

		/* varchar v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar v_country[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		char v_status_type;
		/* varchar v_stmt_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_stmt_txn_id;

		double v_balance;
		double v_tmp;

		short ind_baid = -1;
		short ind_ccy = -1;
		short ind_psp_id = -1;
		short ind_country = -1;
		short ind_status_type = -1;
		short ind_stmt_txn_id = -1;
		short ind_balance = -1;
		short ind_tmp = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	if (iRet == PD_OK) {
		hv_type_deposit.len = strlen(PD_NATURE_DEPOSIT);
		memcpy(hv_type_deposit.arr, PD_NATURE_DEPOSIT, hv_type_deposit.len);
DEBUGLOG(("offline_set_dsi_baid_init_bal: hv_type_deposit = [%.*s]\n", hv_type_deposit.len, hv_type_deposit.arr));

		hv_cutoff_datetime.len = strlen(csCutoffDatetime);
		memcpy(hv_cutoff_datetime.arr, csCutoffDatetime, hv_cutoff_datetime.len);
DEBUGLOG(("offline_set_dsi_baid_init_bal: hv_cutoff_datetime = [%.*s]\n", hv_cutoff_datetime.len, hv_cutoff_datetime.arr));

DEBUGLOG(("offline_set_dsi_baid_init_bal: ===== ===== ===== ===== =====\n"));

		// get deposit baid
		/* EXEC SQL DECLARE c_cursor_get_deposit_baid CURSOR FOR
			select obai_baid, ob_acct_ccy, opd_psp_id, country, ob_status_type
			from ol_bank_acct_id, ol_bank_accts, ol_psp_detail, bank_desc
			where obai_status = 'O'
			and obai_int_bank_code = ob_int_bank_code
			and obai_bank_acct_num = ob_bank_acct_num
			and obai_psp_id = opd_psp_id
			and opd_bank_acct_type = :hv_type_deposit
			and ob_int_bank_code = internal_bank_code; */ 


		/* EXEC SQL OPEN c_cursor_get_deposit_baid; */ 

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
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_type_deposit;
  sqlstm.sqhstl[0] = (unsigned long )5;
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


		for (;;) {
			v_balance = 0.0;

			hash_destroy(myHash);
			hash_init(myHash, 0);

			/* EXEC SQL FETCH c_cursor_get_deposit_baid
			INTO	:v_baid:ind_baid,
				:v_ccy:ind_ccy,
				:v_psp_id:ind_psp_id,
				:v_country:ind_country,
				:v_status_type:ind_status_type; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 5;
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
   sqlstm.sqhstv[0] = (unsigned char  *)&v_baid;
   sqlstm.sqhstl[0] = (unsigned long )23;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_baid;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_ccy;
   sqlstm.sqhstl[1] = (unsigned long )6;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_ccy;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_psp_id;
   sqlstm.sqhstl[2] = (unsigned long )13;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_psp_id;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_country;
   sqlstm.sqhstl[3] = (unsigned long )5;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_country;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_status_type;
   sqlstm.sqhstl[4] = (unsigned long )1;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_status_type;
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
   if (sqlca.sqlcode < 0) goto sql_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			// baid
			if (ind_baid >= 0) {
				v_baid.arr[v_baid.len] = '\0';
DEBUGLOG(("offline_set_dsi_baid_init_bal: baid = [%s]\n", (const char*)v_baid.arr));
			} else {
DEBUGLOG(("offline_set_dsi_baid_init_bal: baid is empty\n"));
				iRet = PD_ERR;
				break;
			}

			// ccy
			if (ind_ccy >= 0) {
				v_ccy.arr[v_ccy.len] = '\0';
DEBUGLOG(("offline_set_dsi_baid_init_bal: ccy = [%s]\n", (const char*)v_ccy.arr));
			} else {
DEBUGLOG(("offline_set_dsi_baid_init_bal: ccy is empty\n"));
				iRet = PD_ERR;
				break;
			}

			// psp_id
			if (ind_psp_id >= 0) {
				v_psp_id.arr[v_psp_id.len] = '\0';
DEBUGLOG(("offline_set_dsi_baid_init_bal: psp_id = [%s]\n", (const char*)v_psp_id.arr));
			} else {
DEBUGLOG(("offline_set_dsi_baid_init_bal: psp_id is empty\n"));
				iRet = PD_ERR;
				break;
			}

			// country
			if (ind_country >= 0) {
				v_country.arr[v_country.len] = '\0';
DEBUGLOG(("offline_set_dsi_baid_init_bal: country = [%s]\n", (const char*)v_country.arr));
			} else {
DEBUGLOG(("offline_set_dsi_baid_init_bal: country is empty\n"));
				iRet = PD_ERR;
				break;
			}

			// status_type
			if (ind_status_type >= 0) {
DEBUGLOG(("offline_set_dsi_baid_init_bal: status_type = [%c]\n", v_status_type));
			}

			// try to get baid balance
			if (iRet == PD_OK) {
				/* EXEC SQL DECLARE c_cursor_get_baid_bal CURSOR FOR
					select obab_bal
					from ol_baid_bal
					where obab_baid = :v_baid
					and obab_country_id = :v_country
					and obab_currency_id = :v_ccy; */ 


				/* EXEC SQL OPEN c_cursor_get_baid_bal; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0002;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )59;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&v_baid;
    sqlstm.sqhstl[0] = (unsigned long )23;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
    sqlstm.sqhstl[1] = (unsigned long )5;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)&v_ccy;
    sqlstm.sqhstl[2] = (unsigned long )6;
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
    if (sqlca.sqlcode < 0) goto sql_error;
}



				/* EXEC SQL FETCH c_cursor_get_baid_bal
				INTO	:v_tmp:ind_tmp; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )86;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)&v_tmp;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)&ind_tmp;
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



				if (SQLCODE != SQL_NOT_FOUND) {
DEBUGLOG(("offline_set_dsi_baid_init_bal: baid balance already exists, skip\n"));
DEBUGLOG(("offline_set_dsi_baid_init_bal: ===== ===== ===== ===== =====\n"));
					/* EXEC SQL CLOSE c_cursor_get_baid_bal; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 5;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )105;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
     if (sqlca.sqlcode < 0) goto sql_error;
}


					continue;
				}

				/* EXEC SQL CLOSE c_cursor_get_baid_bal; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )120;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) goto sql_error;
}


			}

			if (v_status_type == 'F') {
DEBUGLOG(("offline_set_dsi_baid_init_bal: frozen bank account\n"));
				iCreateTxn = PD_FALSE;
				v_balance = 0.0;
			} else {
				// get balance of last statement record
				if (iRet == PD_OK) {
					/* EXEC SQL DECLARE c_cursor_get_last_stmt CURSOR FOR
						select olsd_stat_txn_id,
							olsd_balance
						from (select *
							from ol_statement_detail
							where olsd_baid = :v_baid
							and olsd_statement_ref is not null
							and olsd_create_timestamp < to_date(:hv_cutoff_datetime, 'yyyymmddhh24miss') + 1/24/60/60
							order by olsd_file_id desc, olsd_statement_seq desc)
						where rownum = 1; */ 


					/* EXEC SQL OPEN c_cursor_get_last_stmt; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 5;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = sq0003;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )135;
     sqlstm.selerr = (unsigned short)1;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqcmod = (unsigned int )0;
     sqlstm.sqhstv[0] = (unsigned char  *)&v_baid;
     sqlstm.sqhstl[0] = (unsigned long )23;
     sqlstm.sqhsts[0] = (         int  )0;
     sqlstm.sqindv[0] = (         short *)0;
     sqlstm.sqinds[0] = (         int  )0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqadto[0] = (unsigned short )0;
     sqlstm.sqtdso[0] = (unsigned short )0;
     sqlstm.sqhstv[1] = (unsigned char  *)&hv_cutoff_datetime;
     sqlstm.sqhstl[1] = (unsigned long )16;
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



					/* EXEC SQL FETCH c_cursor_get_last_stmt
					INTO	:v_stmt_txn_id:ind_stmt_txn_id,
						:v_balance:ind_balance; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 5;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )158;
     sqlstm.selerr = (unsigned short)1;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqfoff = (         int )0;
     sqlstm.sqfmod = (unsigned int )2;
     sqlstm.sqhstv[0] = (unsigned char  *)&v_stmt_txn_id;
     sqlstm.sqhstl[0] = (unsigned long )19;
     sqlstm.sqhsts[0] = (         int  )0;
     sqlstm.sqindv[0] = (         short *)&ind_stmt_txn_id;
     sqlstm.sqinds[0] = (         int  )0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqadto[0] = (unsigned short )0;
     sqlstm.sqtdso[0] = (unsigned short )0;
     sqlstm.sqhstv[1] = (unsigned char  *)&v_balance;
     sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
     sqlstm.sqhsts[1] = (         int  )0;
     sqlstm.sqindv[1] = (         short *)&ind_balance;
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



					if (SQLCODE == SQL_NOT_FOUND) {
DEBUGLOG(("offline_set_dsi_baid_init_bal: no statement record found\n"));
						iCreateTxn = PD_FALSE;
						v_balance = 0.0;
DEBUGLOG(("offline_set_dsi_baid_init_bal: balance = [%lf]\n", v_balance));
					} else {
						iCreateTxn = PD_TRUE;

						// stmt_txn_id
						if (ind_stmt_txn_id >= 0) {
							v_stmt_txn_id.arr[v_stmt_txn_id.len] = '\0';
DEBUGLOG(("offline_set_dsi_baid_init_bal: stmt_txn_id = [%s]\n", (const char*)v_stmt_txn_id.arr));
						} else {
DEBUGLOG(("offline_set_dsi_baid_init_bal: stmt_txn_id is empty\n"));
							iRet = PD_ERR;
							/* EXEC SQL CLOSE c_cursor_get_last_stmt; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 12;
       sqlstm.arrsiz = 5;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )181;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
       if (sqlca.sqlcode < 0) goto sql_error;
}


							break;
						}

						// balance
						if (ind_balance >= 0) {
DEBUGLOG(("offline_set_dsi_baid_init_bal: balance = [%lf]\n", v_balance));
						} else {
DEBUGLOG(("offline_set_dsi_baid_init_bal: balance is empty\n"));
							iRet = PD_ERR;
							/* EXEC SQL CLOSE c_cursor_get_last_stmt; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 12;
       sqlstm.arrsiz = 5;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )196;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
       if (sqlca.sqlcode < 0) goto sql_error;
}


							break;
						}
					}

					/* EXEC SQL CLOSE c_cursor_get_last_stmt; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 5;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )211;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
     if (sqlca.sqlcode < 0) goto sql_error;
}


				}

				// get balance of all standalone sms
				if (iRet == PD_OK) {
					/* EXEC SQL DECLARE c_cursor_get_standalone_sms CURSOR FOR
						select olsd_stat_txn_id,
							olsd_txn_amount
						from ol_statement_detail, ol_baid_txn
						where olsd_baid = :v_baid
						and olsd_input_channel = 'SMS_STMT'
						and olsd_amt_type = 'CR'
						and olsd_statement_ref is null
						and olsd_create_timestamp < to_date(:hv_cutoff_datetime, 'yyyymmddhh24miss') + 1/24/60/60
						and obt_stat_txn_id = olsd_stat_txn_id
						and obt_txn_code = 'OBD'
						and obt_status = 'C'
						and obt_ar_ind = 'A'
						and obt_sub_status = '118'; */ 


					/* EXEC SQL OPEN c_cursor_get_standalone_sms; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 5;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = sq0004;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )226;
     sqlstm.selerr = (unsigned short)1;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqcmod = (unsigned int )0;
     sqlstm.sqhstv[0] = (unsigned char  *)&v_baid;
     sqlstm.sqhstl[0] = (unsigned long )23;
     sqlstm.sqhsts[0] = (         int  )0;
     sqlstm.sqindv[0] = (         short *)0;
     sqlstm.sqinds[0] = (         int  )0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqadto[0] = (unsigned short )0;
     sqlstm.sqtdso[0] = (unsigned short )0;
     sqlstm.sqhstv[1] = (unsigned char  *)&hv_cutoff_datetime;
     sqlstm.sqhstl[1] = (unsigned long )16;
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



					for (;;) {
						/* EXEC SQL FETCH c_cursor_get_standalone_sms
						INTO	:v_stmt_txn_id:ind_stmt_txn_id,
							:v_tmp:ind_tmp; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 5;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )249;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqfoff = (         int )0;
      sqlstm.sqfmod = (unsigned int )2;
      sqlstm.sqhstv[0] = (unsigned char  *)&v_stmt_txn_id;
      sqlstm.sqhstl[0] = (unsigned long )19;
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)&ind_stmt_txn_id;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)&v_tmp;
      sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
      sqlstm.sqhsts[1] = (         int  )0;
      sqlstm.sqindv[1] = (         short *)&ind_tmp;
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



						if (SQLCODE == SQL_NOT_FOUND) {
							break;
						} else {
							iCreateTxn = PD_TRUE;

							// stmt_txn_id
							if (ind_stmt_txn_id >= 0) {
								v_stmt_txn_id.arr[v_stmt_txn_id.len] = '\0';
DEBUGLOG(("offline_set_dsi_baid_init_bal: sms_stmt_txn_id = [%s]\n", (const char*)v_stmt_txn_id.arr));
							} else {
DEBUGLOG(("offline_set_dsi_baid_init_bal: sms_stmt_txn_id is empty\n"));
								continue;
	                                	        }

							// txn_amt
							if (ind_tmp >= 0) {
DEBUGLOG(("offline_set_dsi_baid_init_bal: txn_amt = [%lf]\n", v_tmp));
								v_balance = v_balance + v_tmp;
							} else {
DEBUGLOG(("offline_set_dsi_baid_init_bal: txn_amt is empty\n"));
							}
						}
					}

					/* EXEC SQL CLOSE c_cursor_get_standalone_sms; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 5;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )272;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
     if (sqlca.sqlcode < 0) goto sql_error;
}


				}
			}

DEBUGLOG(("offline_set_dsi_baid_init_bal: iCreateTxn = [%d]\n", iCreateTxn));
DEBUGLOG(("offline_set_dsi_baid_init_bal: v_balance = [%lf]\n", v_balance));

			// create baid balance
			if (iRet == PD_OK) {
DEBUGLOG(("offline_set_dsi_baid_init_bal: Call DBOLBAIDBal:UpdateBalance\n"));
				DBObjPtr = CreateObj(DBPtr, "DBOLBAIDBal", "UpdateBalance");
				iTmpRet = (unsigned long)(*DBObjPtr)((const char*)v_baid.arr, (const char*)v_country.arr, (const char*)v_ccy.arr,
									PD_IND_CREDIT, v_balance, PD_UPDATE_USER);
				if (iTmpRet != PD_OK) {
DEBUGLOG(("offline_set_dsi_baid_init_bal: DBOLBAIDBal:UpdateBalance Failed\n"));
ERRLOG("offline_set_dsi_baid_init_bal: DBOLBAIDBal:UpdateBalance Failed\n");
					iRet = PD_ERR;
					break;
				}
			}

			// create baid txn
			// if (iRet == PD_OK && iCreateTxn) {
			if (iRet == PD_OK) {
				PutField_Int(myHash, "db_commit", PD_FALSE);

DEBUGLOG(("offline_set_dsi_baid_init_bal: Call DBOLTxnSeq:GetNextOmtTxnSeq()\n"));
				DBObjPtr = CreateObj(DBPtr, "DBOLTxnSeq", "GetNextOmtTxnSeq");
				strcpy((char*)csNewPspTxnSeq, (*DBObjPtr)());

DEBUGLOG(("offline_set_dsi_baid_init_bal: txn_seq = [%s]\n", csNewPspTxnSeq));
				PutField_CString(myHash, "txn_seq", csNewPspTxnSeq);

				PutField_Char(myHash, "ar_ind", PD_ACCEPT);

				PutField_Double(myHash, "txn_amt", v_balance);

				PutField_CString(myHash, "add_user", PD_UPDATE_USER);

DEBUGLOG(("offline_set_dsi_baid_init_bal: Call DBOLTransaction:Add()\n"));
				DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "Add");
				iTmpRet = (unsigned long)(*DBObjPtr)(myHash);
				if (iTmpRet != PD_OK) {
DEBUGLOG(("offline_set_dsi_baid_init_bal: DBOLTransaction: Add Error\n"));
ERRLOG("offline_set_dsi_baid_init_bal: DBOLTransaction:Add Error\n");
					iRet = PD_ERR;
					break;
				}

DEBUGLOG(("offline_set_dsi_baid_init_bal: Call DBSystemControl:GetApprovalDT()\n"));
				DBObjPtr = CreateObj(DBPtr, "DBSystemControl", "GetApprovalDT");
				(*DBObjPtr)(myHash);

DEBUGLOG(("offline_set_dsi_baid_init_bal: Call DBOLTransaction:Update()\n"));
				DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "Update");
				iTmpRet = (unsigned long)(*DBObjPtr)(myHash);
				if (iTmpRet != PD_OK) {
DEBUGLOG(("offline_set_dsi_baid_init_bal: DBOLTransaction: Update Error\n"));
ERRLOG("offline_set_dsi_baid_init_bal: DBOLTransaction:Update Error\n");
					iRet = PD_ERR;
					break;
				}

				PutField_CString(myHash, "psp_id", (const char*)v_psp_id.arr);

				PutField_CString(myHash, "baid", (const char*)v_baid.arr);

				PutField_CString(myHash, "txn_ccy", (const char*)v_ccy.arr);

				PutField_Double(myHash, "bal", v_balance);

DEBUGLOG(("offline_set_dsi_baid_init_bal: Call DBOLTxnPspDetail:Add()\n"));
				DBObjPtr = CreateObj(DBPtr, "DBOLTxnPspDetail", "Add");
				iTmpRet = (unsigned long)(*DBObjPtr)(myHash);
				if (iTmpRet != PD_OK) {
DEBUGLOG(("offline_set_dsi_baid_init_bal: DBOLTxnPspDetail: Add Error\n"));
ERRLOG("offline_set_dsi_baid_init_bal: DBOLTxnPspDetail: Add Error\n");
					iRet = PD_ERR;
					break;
				}
			}

DEBUGLOG(("offline_set_dsi_baid_init_bal: ===== ===== ===== ===== =====\n"));
		}

		/* EXEC SQL CLOSE c_cursor_get_deposit_baid; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 5;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )287;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto sql_error;
}


	}

	hash_destroy(myHash);
	FREE_ME(myHash);

DEBUGLOG(("offline_set_dsi_baid_init_bal: Normal Exit() iRet = [%d]\n", iRet));
	return iRet;

sql_error:
DEBUGLOG(("sql_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("offline_set_dsi_baid_init_bal:: sql error\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_get_deposit_baid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )302;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	/* EXEC SQL CLOSE c_cursor_get_baid_bal; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )317;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	/* EXEC SQL CLOSE c_cursor_get_last_stmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )332;
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
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )347;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	FREE_ME(myHash);
	return FAILURE;
}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


int parse_arg(int argc, char **argv)
{
	char c;
	strcpy(csCutoffDatetime, "");

	while ((c = getopt(argc, argv, "d:")) != EOF) {
		switch (c) {
			case 'd':
				strcpy(csCutoffDatetime, optarg);
				break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(csCutoffDatetime, "")) {
		return FAILURE;
	}

	return SUCCESS;
}
