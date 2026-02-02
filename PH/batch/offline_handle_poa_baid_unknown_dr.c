
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
           char  filnam[38];
};
static struct sqlcxp sqlfpn =
{
    37,
    "offline_handle_poa_baid_unknown_dr.pc"
};


static unsigned int sqlctx = 29657675;


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
   unsigned char  *sqhstv[1];
   unsigned long  sqhstl[1];
            int   sqhsts[1];
            short *sqindv[1];
            int   sqinds[1];
   unsigned long  sqharm[1];
   unsigned long  *sqharc[1];
   unsigned short  sqadto[1];
   unsigned short  sqtdso[1];
} sqlstm = {12,1};

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
"select obt_txn_id from ol_baid_txn where obt_bank_acct_num = :b0 and obt_tx\
n_code in ( 'UBD' , 'USO' ) and obt_status = 'C' and obt_ar_ind = 'A' and obt\
_sub_status = '118' and obt_txn_id not in ( select baid_txn_id from tmp_exclu\
de_mr_payout_list ) order by obt_approval_timestamp            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,292,0,9,84,0,2049,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,13,89,0,0,1,0,0,1,0,2,9,0,0,
43,0,0,1,0,0,15,152,0,0,0,0,0,1,0,
58,0,0,1,0,0,15,166,0,0,0,0,0,1,0,
73,0,0,2,0,0,32,167,0,0,0,0,0,1,0,
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
char csBankAcctNum[PD_BANK_ACCT_NUM_LEN + 1];

int parse_arg(int argc, char **argv);

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int iRet = PD_OK;
	int iTmpRet;

	iRet = parse_arg(argc, argv);

	if (iRet != SUCCESS) {
		printf("Usage: offline_handle_poa_baid_unknown_dr.exec -d cut_off_datetime -a bank_acct_num\n");
		return (PD_ERR);
	}

	hash_t *myHash;
	myHash = (hash_t*) malloc (sizeof(hash_t));
	hash_init(myHash, 0);

	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_cutoff_datetime[PD_DATE_LEN + PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_cutoff_datetime;

		/* varchar hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;


		/* varchar v_baid_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_baid_txn_id;


		short ind_baid_txn_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	if (iRet == PD_OK) {
		hv_cutoff_datetime.len = strlen(csCutoffDatetime);
		memcpy(hv_cutoff_datetime.arr, csCutoffDatetime, hv_cutoff_datetime.len);
DEBUGLOG(("offline_handle_poa_baid_unknown_dr: hv_cutoff_datetime = [%.*s]\n", hv_cutoff_datetime.len, hv_cutoff_datetime.arr));

		hv_bank_acct_num.len = strlen(csBankAcctNum);
		memcpy(hv_bank_acct_num.arr, csBankAcctNum, hv_bank_acct_num.len);
DEBUGLOG(("offline_handle_poa_baid_unknown_dr: hv_bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));

DEBUGLOG(("offline_handle_poa_baid_unknown_dr: ===== ===== ===== ===== =====\n"));

		// get baid txn
		/* EXEC SQL DECLARE c_cursor_get_baid_txn CURSOR FOR
			select obt_txn_id
			from ol_baid_txn
			where obt_bank_acct_num = :hv_bank_acct_num
			and obt_txn_code in ('UBD', 'USO')
			and obt_status = 'C'
			and obt_ar_ind = 'A'
			and obt_sub_status = '118'
			and obt_txn_id not in (select baid_txn_id from tmp_exclude_mr_payout_list)
			order by obt_approval_timestamp; */ 


		/* EXEC SQL OPEN c_cursor_get_baid_txn; */ 

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
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_bank_acct_num;
  sqlstm.sqhstl[0] = (unsigned long )52;
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
			hash_destroy(myHash);
			hash_init(myHash, 0);

			/* EXEC SQL FETCH c_cursor_get_baid_txn
			INTO	:v_baid_txn_id:ind_baid_txn_id; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 1;
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
   sqlstm.sqhstv[0] = (unsigned char  *)&v_baid_txn_id;
   sqlstm.sqhstl[0] = (unsigned long )19;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_baid_txn_id;
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



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			// baid_txn_id
			if (ind_baid_txn_id >= 0) {
				v_baid_txn_id.arr[v_baid_txn_id.len] = '\0';
DEBUGLOG(("offline_handle_poa_baid_unknown_dr: baid_txn_id = [%s]\n", (const char*)v_baid_txn_id.arr));
			} else {
DEBUGLOG(("offline_handle_poa_baid_unknown_dr: baid_txn_id is empty\n"));
				continue;
			}

			// activity
			PutField_CString(myHash, "activity", "RECON");

			// bank_stmt_type
			PutField_CString(myHash, "bank_stmt_type", "MR_PAYOUT");

			// trigger_type
			PutField_CString(myHash, "trigger_type", "manual");

			// input_channel
			PutField_CString(myHash, "input_channel", "OMT");

			// recon_type
			PutField_CString(myHash, "recon_type", "SAME");

			// use_pf
			PutField_CString(myHash, "use_pf", "0");

			// have_charge
			PutField_CString(myHash, "have_charge", "0");

			// have_interest
			PutField_CString(myHash, "have_interest", "0");

			// add_user
			PutField_CString(myHash, "add_user", PD_UPDATE_USER);

			// txn_cnt
			PutField_CString(myHash, "txn_cnt", "0");

			// stmt_cnt
			PutField_CString(myHash, "stmt_cnt", "1");

			// stmt_txnid_1
			PutField_CString(myHash, "stmt_txnid_1", (const char*)v_baid_txn_id.arr);

DEBUGLOG(("offline_handle_poa_baid_unknown_dr: call TxnOmtByUsREC:Authorize\n"));
			TxnObjPtr = CreateObj(TxnPtr, "TxnOmtByUsREC", "Authorize");
			iTmpRet = (unsigned long)(*TxnObjPtr)(myHash, myHash, myHash);
			if (iTmpRet != PD_OK) {
DEBUGLOG(("offline_handle_poa_baid_unknown_dr: TxnOmtByUsREC:Authorize [%s] Failed\n", (const char*)v_baid_txn_id.arr));
ERRLOG("offline_handle_poa_baid_unknown_dr: TxnOmtByUsREC:Authorize [%s] Failed\n", (const char*)v_baid_txn_id.arr);
			}

DEBUGLOG(("offline_handle_poa_baid_unknown_dr: ===== ===== ===== ===== =====\n"));
		}

		/* EXEC SQL CLOSE c_cursor_get_baid_txn; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 1;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )43;
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

DEBUGLOG(("offline_handle_poa_baid_unknown_dr: Normal Exit() iRet = [%d]\n", iRet));
	return iRet;

sql_error:
DEBUGLOG(("sql_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("offline_handle_poa_baid_unknown_dr:: sql error\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

/* EXEC SQL CLOSE c_cursor_get_baid_txn; */ 

{
struct sqlexd sqlstm;
sqlstm.sqlvsn = 12;
sqlstm.arrsiz = 1;
sqlstm.sqladtp = &sqladt;
sqlstm.sqltdsp = &sqltds;
sqlstm.iters = (unsigned int  )1;
sqlstm.offset = (unsigned int  )58;
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
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )73;
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
	strcpy(csBankAcctNum, "");

	while ((c = getopt(argc, argv, "d:a:")) != EOF) {
		switch (c) {
			case 'd':
				strcpy(csCutoffDatetime, optarg);
				break;
			case 'a':
				strcpy(csBankAcctNum, optarg);
				break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(csCutoffDatetime, "") || !strcmp(csBankAcctNum, "")) {
		return FAILURE;
	}

	return SUCCESS;
}
