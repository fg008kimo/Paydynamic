
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
           char  filnam[11];
};
static struct sqlcxp sqlfpn =
{
    10,
    "test_dd.pc"
};


static unsigned int sqlctx = 81755;


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
#include <json-c/json.h>
#include <sys/stat.h>

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char cs_input_file[PD_TMP_BUF_LEN + 1];
char cs_input_file_2[PD_TMP_BUF_LEN + 1];

static char cDebug = 'Y';

OBJPTR(Txn);

int parse_arg(int argc, char **argv);
int process_main();


int batch_init(int argc, char* argv[])
{
printf("argc = [%d]\n", argc);
	if (argc > 10) {
		printf("usage: -f input_file\n");
		return FAILURE;
	}
	else
		return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int iRet = SUCCESS;

/*
	int iTmpRet = PD_OK;
	FILE *fproc;
	char cs_input_buf[PD_MAX_BUFFER + 1];

	hash_t *hContext;
	hContext = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hContext, 0);

	hash_t *hRequest;
	hRequest = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRequest, 0);

	hash_t *hResponse;
	hResponse = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hResponse, 0);
*/

	iRet = parse_arg(argc, argv);

	if (iRet != SUCCESS) {
		printf("usage: -f input_file\n");
		return (iRet);
	}

printf("cs_input_file = [%s]\n", cs_input_file);
printf("cs_input_file_2 = [%s]\n", cs_input_file_2);

DEBUGLOG(("%s", urldecode("~%21%40%23%24%25%5E%26%2A%28%29_%2B%60-%3D%5B%5D%5C%3B%27%2C.%2F%7B%7D%7C%3A%22%3C%3E%3F")));

/*
	fproc = fopen(cs_input_file, "r");
	if (fproc == NULL) {
DEBUGLOG(("batch_proc: Error opening file = [%s]\n", cs_input_file));
ERRLOG("void_recon: batch_proc: Error opening file = [%s]\n", cs_input_file);
		return FAILURE;
	}

	while ((iRet == SUCCESS) && (fgets(cs_input_buf, PD_MAX_BUFFER, fproc) != NULL)) {
		cs_input_buf[strlen(cs_input_buf)-1] = '\0';
DEBUGLOG(("txn_id = [%s](%d)\n", cs_input_buf, strlen(cs_input_buf)));

		PutField_CString(hRequest, "org_txn_seq", cs_input_buf);
		PutField_CString(hRequest, "add_user", PD_UPDATE_USER);
		PutField_CString(hContext, "add_user", PD_UPDATE_USER);

		TxnObjPtr = CreateObj(TxnPtr, "TxnOmtByUsRBT", "Authorize");
		iTmpRet = (unsigned long)(*TxnObjPtr)(hContext, hRequest, hResponse);
		if (iTmpRet == PD_OK) {
DEBUGLOG(("batch_proc: call TxnOmtByUsRBT: Authorize() success, iTmpRet = [%d]\n", iTmpRet));
		}
		else {
DEBUGLOG(("batch_proc: call TxnOmtByUsRBT: Authorize() failed, iTmpRet = [%d]\n", iTmpRet));
ERRLOG("void_recon: batch_proc: call TxnOmtByUsRBT: Authorize() failed, iTmpRet = [%d]\n", iTmpRet);
			iRet = FAILURE;
		}
	}

	FREE_ME(hResponse);
	FREE_ME(hRequest);
	FREE_ME(hContext);

	fclose(fproc);
*/

DEBUGLOG(("iRet = [%d]\n", iRet));
	return iRet;
}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


int parse_arg(int argc, char **argv)
{
	char c;
	strcpy(cs_input_file, "");
	strcpy(cs_input_file_2, "");

	while ((c = getopt(argc, argv, "f:g:")) != EOF) {
		switch (c) {
			case 'f':
				strcpy(cs_input_file, optarg);
				break;
			case 'g':
                                strcpy(cs_input_file_2, optarg);
                                break;
			default:
				return FAILURE;
		}
	}

	if ((!strcmp(cs_input_file, "")) || (!strcmp(cs_input_file_2, "")))
		return FAILURE;

	return SUCCESS;
}

