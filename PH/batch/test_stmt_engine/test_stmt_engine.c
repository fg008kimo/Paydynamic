
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
    "test_stmt_engine.pc"
};


static unsigned int sqlctx = 42165635;


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

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
};


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
#include "ObjPtr.h"
#include "dates.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char cDebug = 'Y';

OBJPTR(Txn);
OBJPTR(BO);

int parse_arg(int argc, char **argv);
int process_main();

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}

int batch_proc(int argc, char* argv[])
{
	int iRet;

	iRet = parse_arg(argc, argv);

	if (iRet != SUCCESS) {
		return (iRet);
	}

	iRet = process_main();

DEBUGLOG(("iRet = [%d]\n", iRet));

	return iRet;
}

int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

int process_main()
{
	int iRet = SUCCESS;
	char *csTmp;

	hash_t *hRequest;
	hRequest = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRequest, 0);

DEBUGLOG(("process_main\n"));

/*
	PutField_CString(hRequest, "baid_txn_id_1", "A000000000027841");
	PutField_CString(hRequest, "trigger_type", "system");
	PutField_CString(hRequest, "input_channel", "OMT");
	PutField_CString(hRequest, "bank_acct_type", "POA");
	PutField_CString(hRequest, "baid_txn_code", "OBP");
*/

//	PutField_CString(hRequest, "psp_txn_id_1", "T000000000057624");
//	PutField_CString(hRequest, "psp_txn_id_2", "testing_123");

/*
	PutField_CString(hRequest, "baid_txn_id_1", "A000000000027457");
	PutField_CString(hRequest, "trigger_type", "system");
	PutField_CString(hRequest, "input_channel", "SMS");
	PutField_CString(hRequest, "bank_acct_type", "DSI");
	PutField_CString(hRequest, "baid_txn_code", "OBD");
	PutField_CString(hRequest, "stmt_txn_id_1", "C000000000028142");
*/

	PutField_CString(hRequest, "baid_txn_id_1", "A000000000033579");
	PutField_CString(hRequest, "trigger_type", "system");
	PutField_CString(hRequest, "input_channel", "OMT");
	PutField_CString(hRequest, "bank_acct_type", "POA");
	PutField_CString(hRequest, "baid_txn_code", "SNP");

	PutField_CString(hRequest, "psp_txn_id_1", "testing_123");
	PutField_CString(hRequest, "psp_txn_id_2", "T000000000057784");

	BOObjPtr = CreateObj(BOPtr, "BOOLStmtEngine", "ProcessMatching");
	iRet = (unsigned long)(*BOObjPtr)(hRequest);
DEBUGLOG(("iRet = [%d]\n", iRet));

	if (GetField_CString(hRequest, "baid_txn_id_1", &csTmp)) {
DEBUGLOG(("baid_txn_id_1 = [%s]\n", csTmp));
	}

	if (GetField_CString(hRequest, "psp_txn_id_1", &csTmp)) {
DEBUGLOG(("psp_txn_id_1 = [%s]\n", csTmp));
	}

	if (GetField_CString(hRequest, "baid_txn_id_2", &csTmp)) {
DEBUGLOG(("baid_txn_id_2 = [%s]\n", csTmp));
	}

	if (GetField_CString(hRequest, "psp_txn_id_2", &csTmp)) {
DEBUGLOG(("psp_txn_id_2 = [%s]\n", csTmp));
	}

	if (GetField_CString(hRequest, "stmt_txn_id_2", &csTmp)) {
DEBUGLOG(("stmt_txn_id_2 = [%s]\n", csTmp));
	}

	FREE_ME(hRequest);

	return iRet;
}

int parse_arg(int argc, char **argv)
{
	return SUCCESS;
}

