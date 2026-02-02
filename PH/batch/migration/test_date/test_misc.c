
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
           char  filnam[13];
};
static struct sqlcxp sqlfpn =
{
    12,
    "test_misc.pc"
};


static unsigned int sqlctx = 328387;


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

OBJPTR(BO);
OBJPTR(DB);

char    cDebug;


int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int 	iRet = PD_OK;

	char	*csTmp;
	int	iTmp;

        hash_t          *hRec;
        hRec = (hash_t*) malloc (sizeof(hash_t));

	hash_init(hRec,0);

printf("START\n");
	PutField_CString(hRec, "bal_trf_type", PD_BAL_TRF_TYPE_SAME_PLATF);
	PutField_CString(hRec, "from_acct_type", PD_NATURE_DEPOSIT);
	//PutField_CString(hRec, "from_acct_type", PD_NATURE_INTERMEDIATE);
	//PutField_CString(hRec, "to_acct_type", PD_NATURE_INTERMEDIATE);
	PutField_CString(hRec, "to_acct_type", PD_NATURE_DEPOSIT);
	PutField_CString(hRec, "to_baid_category", PD_BAID_CAT_INTERNAL);
	PutField_CString(hRec, "bal_trf_txn_code_type", PD_BAL_TRF_TC_TYPE_SWEEP_OUT);


	DBObjPtr = CreateObj(DBPtr, "DBOLTcBalTrfMap", "GetBalTransferTxnCode");
	if ((unsigned long)(*DBObjPtr)(hRec) == PD_FOUND) {
		if (GetField_CString(hRec, "map_txn_code", &csTmp)) {
printf("map_txn_code [%s]\n", csTmp);
		}

		if (GetField_Int(hRec, "allow_fe_init", &iTmp)) {
printf("allow_fe_init [%d]\n", iTmp);
		}
	} else {
printf("ERROR!!!!\n");
	}


	hash_destroy(hRec);
	FREE_ME(hRec);

	return iRet;
}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

