
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
    "test_md5rsa_sign.pc"
};


static unsigned int sqlctx = 41995483;


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
#include <stdint.h>
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
#include "myhash.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode
#define MAX_MSG_SIZE 4096
#define RSA_PKCS1_PADDING       1
#define RSA_SSLV23_PADDING      2
#define RSA_NO_PADDING          3
#define RSA_PKCS1_OAEP_PADDING  4
#define RSA_X931_PADDING        5
/* EVP_PKEY_ only */
#define RSA_PKCS1_PSS_PADDING   6

OBJPTR(BO);

char	cDebug='Y';

int batch_init(int argc, char* argv[])
{
        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int iRet;

	int padding = RSA_PKCS1_OAEP_PADDING;
	char *csOutput;
	csOutput = (char*) malloc (MAX_MSG_SIZE + 1 );
	memset(csOutput, 0, sizeof(csOutput));

	char *csInput = "order_id=0000000007125033&order_amount=123.45&order_time=20191218171920";
	char *csPriKeyFile = "ouq_ylptest_pri.pem";

	hash_t *hContext;
	hContext = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hContext, 0);

	hash_t *hOut;
	hOut = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOut, 0);

printf("Start\n");

printf("csInput [%s]\n",csInput);

	PutField_CString(hOut, "auth_data", csInput);
	PutField_CString(hContext, "rsa_key", csPriKeyFile);

	BOObjPtr = CreateObj(BOPtr,"BOSecurity","GenerateDinPaySign");

	iRet = (unsigned long)(*BOObjPtr)(hContext, hOut);

	if (iRet == PD_OK) {
		if (GetField_CString(hOut, "sign", &csOutput)) {
printf("csOutput [%s]\n",csOutput);
		} else {
printf("no csOutput\n");
		}
	}

printf("\n==========\n\n");

	hash_t *hRequest;
	hRequest = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRequest, 0);

	char *csInput2 = "bank_seq_no=11170100011517546873&interface_version=V3.0&merchant_code=101001010801&notify_id=430b7974dd5e4410a1b0ea0a013a64e5&notify_type=offline_notify&order_amount=1&order_no=0000000334213847&order_time=2018-02-02 12:47:51&trade_no=1008406576&trade_status=SUCCESS&trade_time=2018-02-02 12:47:47";
	char *csSign = "gxEBy5ewBSyt/FqZ02Ak1a5v5xENfEX7vwsBuHB8PMQZI0oF23DDPd5EuVFio832ivoWQbcrC8/5LgmbAECQf/wETTwzXjNKRrTqoL2goeHszNgFydVsD7cD3hn01bV7IyNBZJT4ds4Q8sfBOVT0MCRbfEuXOhuCWjrdvc9T8Q4=";
	char *csPubKeyFile = "plk_dpye008_pub.pem";

	PutField_CString(hRequest, "auth_data", csInput2);
	PutField_CString(hRequest, "sign", csSign);
	PutField_CString(hContext, "rsa_privatepem", csPubKeyFile);

	BOObjPtr = CreateObj(BOPtr,"BOSecurity","VerifyDinPaySign");

	iRet = (unsigned long)(*BOObjPtr)(hContext, hRequest);
printf("iRet = [%d]\n", iRet);

	hash_destroy(hContext);
	hash_destroy(hOut);
	hash_destroy(hRequest);
	FREE_ME(hContext);
	FREE_ME(hOut);
	FREE_ME(hRequest);
	FREE_ME(csOutput);

printf("End\n");
	return 0;
}


int batch_terminate(int argc, char* argv[])
{
    return SUCCESS;
}

