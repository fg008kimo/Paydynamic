
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
           char  filnam[22];
};
static struct sqlcxp sqlfpn =
{
    21,
    "offline_auto_match.pc"
};


static unsigned int sqlctx = 157707851;


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
   unsigned char  *sqhstv[3];
   unsigned long  sqhstl[3];
            int   sqhsts[3];
            short *sqindv[3];
            int   sqinds[3];
   unsigned long  sqharm[3];
   unsigned long  *sqharc[3];
   unsigned short  sqadto[3];
   unsigned short  sqtdso[3];
} sqlstm = {12,3};

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
"SELECT omb_merchant_id , omb_int_bank_code , omb_bank_acct_num FROM ol_merc\
hant_bank_acct WHERE omb_service_code in ( 'LBP' , 'LBT' , 'QBT' ) AND omb_st\
atus = 'O' AND omb_disabled = 0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,195,0,9,93,0,2049,0,0,0,1,0,
20,0,0,1,0,0,13,95,0,0,3,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,
47,0,0,2,0,0,29,154,0,0,0,0,0,1,0,
62,0,0,1,0,0,15,166,0,0,0,0,0,1,0,
77,0,0,1,0,0,15,179,0,0,0,0,0,1,0,
92,0,0,3,0,0,32,182,0,0,0,0,0,1,0,
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
OBJPTR(BO);

char cDebug = 'Y';

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int iRet = PD_OK;

	hash_t *myHash;
	myHash = (hash_t*) malloc (sizeof(hash_t));

	recordset_t *myRec;
	myRec = (recordset_t*) malloc (sizeof(recordset_t));

	hash_t *hTxn;

	char csBankStmtAuto[PD_SP_VALUE_LEN];
	char csStmtDateRange[PD_SP_VALUE_LEN];

	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar v_int_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_int_bank_code;

		/* varchar v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;


		short ind_merchant_id = -1;
		short ind_int_bank_code = -1;
		short ind_bank_acct_num = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	/* EXEC SQL DECLARE c_cursor CURSOR FOR
		SELECT omb_merchant_id, omb_int_bank_code, omb_bank_acct_num
		FROM ol_merchant_bank_acct
		WHERE omb_service_code in ('LBP', 'LBT', 'QBT')
		AND omb_status = 'O'
		AND omb_disabled = 0; */ 


	if (iRet == PD_OK) {
DEBUGLOG(("offline_auto_match:: call DBSystemParameter::FindCode()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBSystemParameter", "FindCode");
		if ((unsigned long)(*DBObjPtr)(PD_OFL_BANK_STMT_AUTO, csBankStmtAuto) == PD_FOUND) {
DEBUGLOG(("offline_auto_match:: bank_stmt_auto = [%d]\n", atoi(csBankStmtAuto)));
			if (atoi(csBankStmtAuto) != PD_TRUE) {
DEBUGLOG(("offline_auto_match:: auto match disabled\n"));
				iRet = PD_ERR;
			}
		} else {
DEBUGLOG(("offline_auto_match:: cannot find [%s] in system parameter\n", PD_OFL_STMT_DATE_RANGE));
ERRLOG("offline_auto_match:: cannot find [%s] in system parameter\n", PD_OFL_STMT_DATE_RANGE);
			iRet = PD_ERR;
		}
	}

	if (iRet == PD_OK) {
DEBUGLOG(("offline_auto_match:: call DBSystemParameter::FindCode()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBSystemParameter", "FindCode");
		if ((unsigned long)(*DBObjPtr)(PD_OFL_STMT_DATE_RANGE, csStmtDateRange) == PD_FOUND) {
DEBUGLOG(("offline_auto_match:: stmt_date_range = [%d]\n", atoi(csStmtDateRange)));
		} else {
DEBUGLOG(("offline_auto_match:: cannot find [%s] in system parameter\n", PD_OFL_STMT_DATE_RANGE));
ERRLOG("offline_auto_match:: cannot find [%s] in system parameter\n", PD_OFL_STMT_DATE_RANGE);
			iRet = PD_ERR;
		}
	}

	if (iRet == PD_OK) {
		/* EXEC SQL OPEN c_cursor; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 0;
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
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto sql_error;
}


		do {
			/* EXEC SQL FETCH c_cursor
			INTO :v_merchant_id:ind_merchant_id,
					:v_int_bank_code:ind_int_bank_code,
					:v_bank_acct_num:ind_bank_acct_num; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 3;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )20;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_merchant_id;
   sqlstm.sqhstl[0] = (unsigned long )18;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_merchant_id;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_int_bank_code;
   sqlstm.sqhstl[1] = (unsigned long )13;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_int_bank_code;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_bank_acct_num;
   sqlstm.sqhstl[2] = (unsigned long )53;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_bank_acct_num;
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



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			hash_init(myHash, 0);

			// stmt_date_range
			PutField_Int(myHash, "stmt_date_range", atoi(csStmtDateRange));

			// merchant_id
			if (ind_merchant_id >= 0) {
				v_merchant_id.arr[v_merchant_id.len] = '\0';
				PutField_CString(myHash, "merchant_id", (const char*)v_merchant_id.arr);
DEBUGLOG(("merchant_id = [%s]\n", v_merchant_id.arr));
			} else {
DEBUGLOG(("cannot get merchant_id\n"));
				hash_destroy(myHash);
				continue;
			}

			// int_bank_code
			if (ind_int_bank_code >= 0) {
				v_int_bank_code.arr[v_int_bank_code.len] = '\0';
				PutField_CString(myHash, "int_bank_code", (const char*)v_int_bank_code.arr);
DEBUGLOG(("int_bank_code = [%s]\n", v_int_bank_code.arr));
			} else {
DEBUGLOG(("cannot get int_bank_code\n"));
				hash_destroy(myHash);
				continue;
			}

			// bank_acct_num
			if (ind_bank_acct_num >= 0) {
				v_bank_acct_num.arr[v_bank_acct_num.len] = '\0';
				PutField_CString(myHash, "bank_acct_num", (const char*)v_bank_acct_num.arr);
DEBUGLOG(("bank_acct_num = [%s]\n", v_bank_acct_num.arr));
			} else {
DEBUGLOG(("cannot get bank_acct_num\n"));
				hash_destroy(myHash);
				continue;
			}

			recordset_init(myRec, 0);

			BOObjPtr = CreateObj(BOPtr, "BOOLDepositMatch", "GetUnallocatedStmt");
			iRet = (unsigned long)(*BOObjPtr)(myHash, myRec);

			if (iRet == PD_OK) {
				// auto match
				hTxn = RecordSet_GetFirst(myRec);
				while (hTxn) {
					BOObjPtr = CreateObj(BOPtr, "BOOLDepositMatch", "ProcessMatching");
					if ((unsigned long)(*BOObjPtr)(hTxn) == PD_OK) {
						// should commit every txn?
						/* EXEC SQL COMMIT; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 12;
      sqlstm.arrsiz = 3;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )47;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
      if (sqlca.sqlcode < 0) goto sql_error;
}


					}
					hTxn = RecordSet_GetNext(myRec);
				}
			}

			RecordSet_Destroy(myRec);

			hash_destroy(myHash);
		}
		while(PD_TRUE && iRet == PD_OK);

		/* EXEC SQL CLOSE c_cursor; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 3;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )62;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto sql_error;
}


	}

	FREE_ME(myRec);

	FREE_ME(myHash);

	return iRet;

sql_error:
DEBUGLOG(("sql_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )77;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	// FREE_ME(myRec);
	// FREE_ME(myHash);
	/* EXEC SQL ROLLBACK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )92;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return FAILURE;
}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}
