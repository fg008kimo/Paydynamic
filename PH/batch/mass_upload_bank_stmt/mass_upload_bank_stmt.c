
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
    "mass_upload_bank_stmt.pc"
};


static unsigned int sqlctx = 1272087243;


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
   unsigned char  *sqhstv[2];
   unsigned long  sqhstl[2];
            int   sqhsts[2];
            short *sqindv[2];
            int   sqinds[2];
   unsigned long  sqharm[2];
   unsigned long  *sqharc[2];
   unsigned short  sqadto[2];
   unsigned short  sqtdso[2];
} sqlstm = {12,2};

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
"select internal_bank_code , opd_bank_acct_type from bank_desc , ol_bank_acc\
t_id , ol_psp_detail where bank_abbrev_name = :b0 and obai_int_bank_code = in\
ternal_bank_code and obai_bank_acct_num = :b1 and opd_psp_id = obai_psp_id an\
d offline_support = 1 and obai_status = 'O' and obai_category = 'ITL_GEN' and\
 opd_disabled = 0 and opd_status = 'O'            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,356,0,9,97,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
28,0,0,1,0,0,13,99,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
51,0,0,1,0,0,15,160,0,0,0,0,0,1,0,
66,0,0,1,0,0,15,173,0,0,0,0,0,1,0,
81,0,0,2,0,0,32,174,0,0,0,0,0,1,0,
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
char csBankAbbrevName[PD_BANK_NAME_LEN + 1];
char csBankAcctNum[PD_BANK_ACCT_NUM_LEN + 1];
char csBankStmtFileName[PD_UPLOAD_FILENAME_LEN + 1];

int parse_arg(int argc, char **argv);

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int iRet = SUCCESS;
	int iTmpRet;

	iRet = parse_arg(argc, argv);

	if (iRet != SUCCESS) {
		printf("Usage: mass_upload_bank_stmt.exec -d hv_bank_abbrev_name -a bank_acct_num -s bank_stmt_file_name\n");
		return FAILURE;
	}

	hash_t *hRequest;
	hRequest = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRequest, 0);

	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_bank_abbrev_name[PD_EXT_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_bank_abbrev_name;

		/* varchar hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;


		/* varchar v_int_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_int_bank_code;

		/* varchar v_bank_acct_type[PD_ACCT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_bank_acct_type;


		short ind_int_bank_code = -1;
		short ind_bank_acct_type = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


        char csTmpDate[PD_DATETIME_LEN + 1];
        DBObjPtr = CreateObj(DBPtr, "DBSystemControl", "FindCode");

        if ((unsigned long)(*DBObjPtr)("CTPHDATE", csTmpDate) == FOUND) {
DEBUGLOG(("mass_upload_bank_stmt: Current Processor Hub Date = [%s]\n", csTmpDate));
                PutField_CString(hRequest, "PHDATE", csTmpDate);
        } else {
DEBUGLOG(("mass_upload_bank_stmt: record not found\n"));
                return FAILURE;
        }

		hv_bank_abbrev_name.len = strlen(csBankAbbrevName);
		memcpy(hv_bank_abbrev_name.arr, csBankAbbrevName, hv_bank_abbrev_name.len);
DEBUGLOG(("mass_upload_bank_stmt: hv_bank_abbrev_name = [%.*s]\n", hv_bank_abbrev_name.len, hv_bank_abbrev_name.arr));

		hv_bank_acct_num.len = strlen(csBankAcctNum);
		memcpy(hv_bank_acct_num.arr, csBankAcctNum, hv_bank_acct_num.len);
DEBUGLOG(("mass_upload_bank_stmt: hv_bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));

		// get int_bank_code, bank_acct_type
		/* EXEC SQL DECLARE c_cursor_get_info CURSOR FOR
			select internal_bank_code, opd_bank_acct_type
			from bank_desc, ol_bank_acct_id, ol_psp_detail
			where bank_abbrev_name = :hv_bank_abbrev_name
			and obai_int_bank_code = internal_bank_code
			and obai_bank_acct_num = :hv_bank_acct_num
			and opd_psp_id = obai_psp_id
			and offline_support = 1
			and obai_status = 'O'
			and obai_category = 'ITL_GEN'
			and opd_disabled = 0
			and opd_status = 'O'; */ 


		/* EXEC SQL OPEN c_cursor_get_info; */ 

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
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_bank_abbrev_name;
  sqlstm.sqhstl[0] = (unsigned long )22;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_acct_num;
  sqlstm.sqhstl[1] = (unsigned long )52;
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



		/* EXEC SQL FETCH c_cursor_get_info
		INTO	:v_int_bank_code:ind_int_bank_code,
			:v_bank_acct_type:ind_bank_acct_type; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 2;
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
  sqlstm.sqhstv[0] = (unsigned char  *)&v_int_bank_code;
  sqlstm.sqhstl[0] = (unsigned long )13;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_int_bank_code;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_bank_acct_type;
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_bank_acct_type;
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
DEBUGLOG(("mass_upload_bank_stmt: BAID not found\n"));
			return FAILURE;
		}

		// int_bank_code
		if (ind_int_bank_code >= 0) {
			v_int_bank_code.arr[v_int_bank_code.len] = '\0';
DEBUGLOG(("mass_upload_bank_stmt: int_bank_code = [%s]\n", (const char*)v_int_bank_code.arr));
		} else {
DEBUGLOG(("mass_upload_bank_stmt: int_bank_code is empty\n"));
			return FAILURE;
		}

		// bank_acct_type
		if (ind_bank_acct_type >= 0) {
			v_bank_acct_type.arr[v_bank_acct_type.len] = '\0';
DEBUGLOG(("mass_upload_bank_stmt: bank_acct_type = [%s]\n", (const char*)v_bank_acct_type.arr));
		} else {
DEBUGLOG(("mass_upload_bank_stmt: bank_acct_type is empty\n"));
			return FAILURE;
		}

		// in_file_path
		PutField_CString(hRequest, "in_file_path", "/nfs/dev/bank_stmt_files/mass_upload/raw");

		// in_file_name
		PutField_CString(hRequest, "in_file_name", csBankStmtFileName);

		// bank_acct_type
		PutField_CString(hRequest, "bank_acct_type", (const char*)v_bank_acct_type.arr);

		// int_bank_code
		PutField_CString(hRequest, "int_bank_code", (const char*)v_int_bank_code.arr);

		// bank_acct_num
		PutField_CString(hRequest, "bank_acct_num", csBankAcctNum);

		// add_user
		PutField_CString(hRequest, "add_user", PD_UPDATE_USER);

		// channel_code
		PutField_CString(hRequest, "channel_code", PD_CHANNEL_OMT); // for BOBankCharge::GetTxnBankCharge()

		// all_unknown
		PutField_CString(hRequest, "all_unknown", "1"); // for mass upload purpose

DEBUGLOG(("mass_upload_bank_stmt: call TxnOmtByUsBSU:Authorize\n"));
		TxnObjPtr = CreateObj(TxnPtr, "TxnOmtByUsBSU", "Authorize");
		iTmpRet = (unsigned long)(*TxnObjPtr)(hRequest, hRequest, hRequest);
		if (iTmpRet != PD_OK) {
DEBUGLOG(("mass_upload_bank_stmt: TxnOmtByUsBSU:Authorize Failed\n"));
ERRLOG("mass_upload_bank_stmt: TxnOmtByUsBSU:Authorize Failed\n");
			printf("********** ERROR: upload failed, code = [%d]\n", iTmpRet);
			iRet = FAILURE;
		}

		/* EXEC SQL CLOSE c_cursor_get_info; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 2;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )51;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto sql_error;
}



	hash_destroy(hRequest);
	FREE_ME(hRequest);

DEBUGLOG(("mass_upload_bank_stmt: Normal Exit() iRet = [%d]\n", iRet));
	return iRet;

sql_error:
DEBUGLOG(("sql_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("mass_upload_bank_stmt:: sql error\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

/* EXEC SQL CLOSE c_cursor_get_info; */ 

{
struct sqlexd sqlstm;
sqlstm.sqlvsn = 12;
sqlstm.arrsiz = 2;
sqlstm.sqladtp = &sqladt;
sqlstm.sqltdsp = &sqltds;
sqlstm.iters = (unsigned int  )1;
sqlstm.offset = (unsigned int  )66;
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
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )81;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	FREE_ME(hRequest);
	return FAILURE;
}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


int parse_arg(int argc, char **argv)
{
	char c;
	strcpy(csBankAbbrevName, "");
	strcpy(csBankAcctNum, "");
	strcpy(csBankStmtFileName, "");

	while ((c = getopt(argc, argv, "b:a:s:")) != EOF) {
		switch (c) {
			case 'b':
				strcpy(csBankAbbrevName, optarg);
				break;
			case 'a':
				strcpy(csBankAcctNum, optarg);
				break;
			case 's':
				strcpy(csBankStmtFileName, optarg);
				break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(csBankAbbrevName, "") || !strcmp(csBankAcctNum, "") || !strcmp(csBankStmtFileName, "")) {
		return FAILURE;
	}

	return SUCCESS;
}
