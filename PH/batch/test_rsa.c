
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
           char  filnam[12];
};
static struct sqlcxp sqlfpn =
{
    11,
    "test_rsa.pc"
};


static unsigned int sqlctx = 164307;


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
	int padding = RSA_PKCS1_OAEP_PADDING;
	char* csOutput;
	csOutput = (char*) malloc (MAX_MSG_SIZE + 1 );
	memset(csOutput,0,sizeof(csOutput));

	char *csInput = "out_trade_no=0000000007124837";
	char *csKeyFile = "uni_apyu023_pub.pem";

printf("Start\n");

printf("csInput [%s]\n",csInput);
	BOObjPtr = CreateObj(BOPtr,"BOSecurity","RSAEncryptData_with_mode");

	// encrypt
	int iRet = (unsigned long)(*BOObjPtr)(csKeyFile,csInput,csOutput,PD_FALSE,PD_TRUE,padding,2048);
	if (iRet == PD_OK) {
printf("csOutput [%s]\n",csOutput);
	}

	// decrypt
	char *csInput2 = "BuS2KuvBgNeLBlOW+XG/sDJ7FrFmRpST3E0CFM1sIE3iwcsbgOKwXN9KwqUxSQ1XPjNlGImUhXopzuWU9OOwLGpjS4JoRfbAm2yyTKcQnqcFxfjLFHMhVQKKFfcl99MeD9dDGNqzI1cWDLtvaCCZzTIAWbwjXIjNAQ999mEskLDzH8tT18ibcg3xIONZwtCrrbpK69iXGzSA53ElNE71+tSFlyrwTeZl08VDhhXVEWy0t5FBaHVG40FLDX2W8Gawac7+SX6t3Vn1OuBQ3kO4MLTz+TaSx/xFmpVoMWUlABDxwSWvb/ahQUjJHxXdLqr2KyOzMHYqxdf7LdhEA6GlZQ==";
	char *csKeyFile2 = "uni_default_pri.pem";

	iRet = (unsigned long)(*BOObjPtr)(csKeyFile2,csInput2,csOutput,PD_TRUE,PD_FALSE,padding,2048);
	if (iRet == PD_OK) {
printf("csOutput [%s]\n",csOutput);
	}

	FREE_ME(csOutput);

printf("End\n");
	return 0;
}


int batch_terminate(int argc, char* argv[])
{
    return SUCCESS;
}

