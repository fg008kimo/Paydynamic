
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
           char  filnam[17];
};
static struct sqlcxp sqlfpn =
{
    16,
    "test_txn_code.pc"
};


static unsigned int sqlctx = 5273635;


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
#include "common.h"
#include "utilitys.h"
#include "expat.h"
#include <curl/curl.h>
#include "myhash.h"
#include "ObjPtr.h"
#include "numutility.h"
#include "myrecordset.h"
#include "dates.h"

#include "TxnSeq.h"
#include "BOSecurity.h"

#include "sha1.h"
#define TESTA   "abc"


OBJPTR(DB);
OBJPTR(BO);
char    cDebug;

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}




int batch_proc(int argc, char* argv[])
{
	int iRet = PD_TRUE;

	char*	csTmpTxnCode;
	char*   csTmpTxnDesc;
        char*   csTxnCode;
        char*   csTxnDesc;

        char*   csProcessType;
        char*   csProcessCode;

        csTmpTxnCode = (char*) malloc (PD_TXN_CODE_LEN +1 );
        csTmpTxnDesc = (char*) malloc (PD_DESC_LEN + 1);
        csTxnCode = (char*) malloc (PD_TXN_CODE_LEN +1 );
        csTxnDesc = (char*) malloc (PD_DESC_LEN + 1);

        csProcessType = (char*) malloc (PD_PROCESS_TYPE_LEN+1 );
        csProcessCode = (char*) malloc (PD_PROCESS_CODE_LEN + 1);

	strcpy(csProcessType, "0200");
	strcpy(csProcessCode, "200102");

printf("start ...\n");
	DBObjPtr = CreateObj(DBPtr,"DBTxnCode","FindTxnCode");
	if (!(*DBObjPtr)(csTmpTxnCode,
			csTmpTxnDesc,
			csProcessType,
			csProcessCode)) {
printf("ERROR 1111\n");
	}  else {
		DBObjPtr = CreateObj(DBPtr,"DBDefTxnCodeMap","GetTxnCodeMap");
		if (!(*DBObjPtr)(csTmpTxnCode,
				csTxnCode,
                                csTxnDesc)) {
printf("ERROR 2222\n");
		} else {
			
printf("csTxnCode = [%s]\n", csTxnCode);
printf("csTxnDesc = [%s]\n", csTxnDesc);
		}
	}

	FREE_ME(csTmpTxnCode);
	FREE_ME(csTxnCode);
	FREE_ME(csTxnDesc);

	FREE_ME(csProcessType);
	FREE_ME(csProcessCode);


	return iRet;
}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}
