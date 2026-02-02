
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
           char  filnam[25];
};
static struct sqlcxp sqlfpn =
{
    24,
    "deposit_edit_fallback.pc"
};


static unsigned int sqlctx = 1194984643;


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
"select rec_no , new_txn_id , merch_ref , to_char ( deposit_amt ) , cust_dep\
osit_datetime , bank_code , bank_acct_num , deposit_ref , deposit_bank from t\
mp_ol_odi_edit_final where rec_date = :b0 and NVL ( error_code , - 1 ) = 0 an\
d new_txn_id is not null order by rec_no            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,281,0,9,129,0,2049,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,13,131,0,0,9,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,
75,0,0,1,0,0,15,215,0,0,0,0,0,1,0,
90,0,0,1,0,0,15,233,0,0,0,0,0,1,0,
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
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define MY_PARSE_TOKEN            "&"
#define MY_PARSE_FIELD_TOKEN      "="
#define MY_OUT_TOKEN              ","

OBJPTR(DB);
OBJPTR(Txn);

char cDebug = 'Y';

char csProcessDate[PD_DATE_LEN + 1];

int parse_arg(int argc, char **argv);
int Process();


int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int iRet = SUCCESS;

	iRet = parse_arg(argc, argv);

	if (iRet != SUCCESS) {
		printf("Usage: deposit_edit_fallback.exec -d process_date \n");
		return FAILURE;
	}

	iRet = Process();

	if (iRet == FAILURE) {
DEBUGLOG(("process Abort\n")); 
		TxnAbort();		
	} else {
DEBUGLOG(("process Completed\n")); 
		//TxnAbort();
	}

	return iRet;
}

int	Process () {

	int iRet = SUCCESS;
	int iTmpRet;

        hash_t *hRequest;
	hash_t *hContext;
	hash_t *hResponse;

	hRequest = (hash_t *)malloc(sizeof(hash_t));
        hContext = (hash_t*) malloc (sizeof(hash_t));
        hResponse= (hash_t*) malloc (sizeof(hash_t));

        hash_init(hContext, 0);
        hash_init(hResponse, 0);

        /* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


DEBUGLOG(("process edit start\n")); 
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_process_date [PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_process_date;


		int	v_rec_no;
		/* varchar	v_new_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_new_txn_id;

                /* varchar v_merch_ref[PD_MERCHANT_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merch_ref;

                /* varchar	v_deposit_amt [20 + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_deposit_amt;

                /* varchar v_cust_deposit_datetime[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_cust_deposit_datetime;

                /* varchar v_bank_code[PD_AC_BANK_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_bank_code;

                /* varchar v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

                /* varchar v_deposit_ref[PD_BANK_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } v_deposit_ref;

                /* varchar v_deposit_bank[PD_BANK_DESC_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } v_deposit_bank;


		short ind_rec_no = -1;
		short ind_new_txn_id = -1;
                short ind_merch_ref = -1;
                short ind_deposit_amt = -1;
                short ind_cust_deposit_datetime = -1;
                short ind_bank_code = -1;
                short ind_bank_acct_num = -1;
                short ind_deposit_ref = -1;
                short ind_deposit_bank= -1;
        /* EXEC SQL END DECLARE SECTION; */ 



	hv_process_date.len = strlen(csProcessDate);
	memcpy(hv_process_date.arr, csProcessDate, hv_process_date.len);
DEBUGLOG(("deposit_edit_fallback:: Process process_date [%.*s]\n", hv_process_date.len, hv_process_date.arr)); 

        /* EXEC SQL DECLARE c_cursor_get_list CURSOR FOR
                select rec_no,
                       new_txn_id,
                       merch_ref,
                       to_char(deposit_amt),
                       cust_deposit_datetime,
                       bank_code,
                       bank_acct_num,
                       deposit_ref,
                       deposit_bank
                  from tmp_ol_odi_edit_final
                 where rec_date = :hv_process_date
                   and NVL(error_code , -1) = 0
                   and new_txn_id is not null
                  order by rec_no; */ 


	/* EXEC SQL OPEN c_cursor_get_list; */ 

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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_process_date;
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
		/* EXEC SQL FETCH c_cursor_get_list
		INTO
                	:v_rec_no:ind_rec_no,
                	:v_new_txn_id:ind_new_txn_id,
	                :v_merch_ref:ind_merch_ref,
			:v_deposit_amt:ind_deposit_amt,
			:v_cust_deposit_datetime:ind_cust_deposit_datetime,
			:v_bank_code:ind_bank_code,
			:v_bank_acct_num:ind_bank_acct_num,
			:v_deposit_ref:ind_deposit_ref,
			:v_deposit_bank:ind_deposit_bank; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
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
  sqlstm.sqhstv[0] = (unsigned char  *)&v_rec_no;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_rec_no;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_new_txn_id;
  sqlstm.sqhstl[1] = (unsigned long )19;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_new_txn_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_merch_ref;
  sqlstm.sqhstl[2] = (unsigned long )53;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_merch_ref;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_deposit_amt;
  sqlstm.sqhstl[3] = (unsigned long )23;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_deposit_amt;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_cust_deposit_datetime;
  sqlstm.sqhstl[4] = (unsigned long )17;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_cust_deposit_datetime;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_bank_code;
  sqlstm.sqhstl[5] = (unsigned long )28;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_bank_code;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_bank_acct_num;
  sqlstm.sqhstl[6] = (unsigned long )53;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_bank_acct_num;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_deposit_ref;
  sqlstm.sqhstl[7] = (unsigned long )152;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_deposit_ref;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_deposit_bank;
  sqlstm.sqhstl[8] = (unsigned long )152;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_deposit_bank;
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
  if (sqlca.sqlcode < 0) goto sql_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		hash_init(hRequest, 0);

                if (ind_rec_no >= 0) {
DEBUGLOG(("get_list: rec_no = [%d]\n", v_rec_no));
                }

		if (ind_new_txn_id >= 0) {
                        v_new_txn_id.arr[v_new_txn_id.len] = '\0';
DEBUGLOG(("get_list: [%d] txn_seq = [%s]\n", v_rec_no, (const char*)v_new_txn_id.arr));
			PutField_CString(hRequest, "org_txn_seq", (const char*)v_new_txn_id.arr);
                }  

		if (ind_bank_code >= 0) {
                        v_bank_code.arr[v_bank_code.len] = '\0';
DEBUGLOG(("get_list: [%d] bank_code = [%s]\n", v_rec_no, (const char*)v_bank_code.arr));
			PutField_CString(hRequest, "int_bank_code", (const char*)v_bank_code.arr);
		}

		if (ind_bank_acct_num >= 0) {
                        v_bank_acct_num.arr[v_bank_acct_num.len] = '\0';
DEBUGLOG(("get_list: [%d] bank_acct_num = [%s]\n", v_rec_no, (const char*)v_bank_acct_num.arr));
			PutField_CString(hRequest, "bank_acct_num", (const char*)v_bank_acct_num.arr);
		}

		if (ind_deposit_amt >= 0) {
                        v_deposit_amt.arr[v_deposit_amt.len] = '\0';
DEBUGLOG(("get_list: [%d] deposit_amt = [%s]\n", v_rec_no, (const char*)v_deposit_amt.arr));
			PutField_CString(hRequest, "deposit_amt", (const char*)v_deposit_amt.arr);
		}

		if (ind_cust_deposit_datetime >= 0) {
                        v_cust_deposit_datetime.arr[v_cust_deposit_datetime.len] = '\0';
DEBUGLOG(("get_list: [%d] cust_deposit_datetime = [%s]\n", v_rec_no, (const char*)v_cust_deposit_datetime.arr));
			PutField_CString(hRequest, "cust_deposit_datetime", (const char*)v_cust_deposit_datetime.arr);
		}

		if (ind_deposit_bank >= 0) {
                        v_deposit_bank.arr[v_deposit_bank.len] = '\0';
DEBUGLOG(("get_list: [%d] deposit_bank = [%s]\n", v_rec_no, (const char*)v_deposit_bank.arr));
			PutField_CString(hRequest, "deposit_bank", (const char*)v_deposit_bank.arr);
		}
	
		if (ind_deposit_ref >= 0) {
                        v_deposit_ref.arr[v_deposit_ref.len] = '\0';
DEBUGLOG(("get_list: [%d] deposit_ref = [%s]\n", v_rec_no, (const char*)v_deposit_ref.arr));
			PutField_CString(hRequest, "deposit_ref", (const char*)v_deposit_ref.arr);
		}

		PutField_CString(hRequest, "add_user", PD_UPDATE_USER);


DEBUGLOG(("deposit_edit_fallback: call TxnOmtByUsDRE:Authorize\n"));

                TxnObjPtr = CreateObj(TxnPtr, "TxnOmtByUsDRE", "Authorize");
                iTmpRet = (unsigned long)(*TxnObjPtr)(hContext , hRequest, hResponse);
                if (iTmpRet != PD_OK) {
DEBUGLOG(("deposit_edit_fallback: TxnOmtByUsDRE:Authorize Failed\n"));
ERRLOG("deposit_edit_fallback: TxnOmtByUsDRE:Authorize Failed\n");
                        iRet = FAILURE;
			break;
                } else {
DEBUGLOG(("deposit_edit_fallback: [%d] Authorize Succ\n", v_rec_no));
		}

		hash_destroy(hRequest);

	} while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_get_list; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
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



	hash_destroy(hRequest);
	FREE_ME(hRequest);

	hash_destroy(hContext);
	hash_destroy(hResponse);

	FREE_ME(hContext);
	FREE_ME(hResponse);

	return iRet;

sql_error:
DEBUGLOG(("get_list_error: code %d\n", sqlca.sqlcode));
ERRLOG("deposit_edit_fallback get_list_error code %d\n", sqlca.sqlcode);
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_get_list; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
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


        return PD_ERR;

}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


int parse_arg(int argc, char **argv)
{
	char c;

	while ((c = getopt(argc, argv, "d:")) != EOF) {
		switch (c) {
			case 'd':
				strcpy(csProcessDate, optarg);
				break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(csProcessDate, "") ) {
		return FAILURE;
	}

	return SUCCESS;
}
