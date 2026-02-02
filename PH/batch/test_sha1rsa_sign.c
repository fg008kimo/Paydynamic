
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
           char  filnam[21];
};
static struct sqlcxp sqlfpn =
{
    20,
    "test_sha1rsa_sign.pc"
};


static unsigned int sqlctx = 84106459;


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



int batch_proc_tmp(int argc, char* argv[])
{
	int iRet;
	
	char *csOutput;
	csOutput = (char*) malloc (MAX_MSG_SIZE + 1 );
	memset(csOutput, 0, sizeof(csOutput));

	char *csPriKeyFile = "gdp_spyv001_pri.pem";
	char *csPassphrase = "123456";

	char *csInput = "{\"head\":{\"respTime\":\"20180510093426\",\"respMsg\":\"成功\",\"version\":\"1.0\",\"respCode\":\"000000\"},\"body\":{\"mid\":\"11912458\",\"orderCode\":\"0000000002828869\",\"totalAmount\":\"000000001234\",\"orderStatus\":\"1\",\"traceNo\":\"GPV0000001\",\"buyerPayAmount\":\"000000001234\",\"discAmount\":\"000000001234\",\"payTime\":\"20180510120102\",\"clearDate\":\"20180510\",\"refundAmount\":null,\"surplusAmount\":null,\"midFee\":null,\"extend\":null}}";

	hash_t *hContext;
	hContext = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hContext, 0);

	hash_t *hOut;
	hOut = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOut, 0);

/*
printf("Start\n");

printf("csInput [%s]\n",csInput);

	PutField_CString(hOut, "auth_data", csInput);
	PutField_CString(hContext, "psp_privatepem", csPriKeyFile);
	PutField_CString(hContext, "psp_passphrase", csPassphrase);

	BOObjPtr = CreateObj(BOPtr,"BOSecurity","Generate51EpaySign");

	iRet = (unsigned long)(*BOObjPtr)(hContext, hOut);

	if (iRet == PD_OK) {
		if (GetField_CString(hOut, "sign", &csOutput)) {
printf("csOutput [%s]\n",csOutput);
		} else {
printf("no csOutput\n");
		}
	}
*/

printf("\n==========\n\n");
printf("Verify\n");
	
	hash_t *hRequest;
	hRequest = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRequest, 0);

	char *csPubKeyFile = "gdp_spye002_pub.crt";
	char *csInput2 = "{\"head\":{\"respTime\":\"20180605145836\",\"respMsg\":\"成功\",\"version\":\"1.0\",\"respCode\":\"000000\"},\"body\":{\"clearDate\":\"20180605\",\"tradeNo\":\"2018060514582704060856018533\",\"payTime\":\"20180605145835\",\"plMidFee\":\"000000000000\",\"midFee\":\"000000000030\",\"mid\":\"11912458\",\"orderStatus\":\"1\",\"specialFee\":\"000000000000\",\"totalAmount\":\"000000001000\",\"buyerPayAmount\":\"000000001000\",\"orderCode\":\"0000000540315834\",\"bid\":\"SDSMP00000001191245820180605025826819547\",\"discAmount\":\"000000000000\",\"extraFee\":\"000000000000\"}}";
	strcpy(csOutput, "IJRWhKEwgB/UrUnc2CSCI2aMjG0rxO6uBBJWBE2O825fs2X8RxkKeXQwF1I3v22Cl37mG5WRxk0qJgf7MAkpiQFFKC+Pt+7DbGlOaeuAyHAtH+gQwAYnyPwLBclPtYxNUJ38n1p94LEusjIYzhqCDDhwE0L88Yg4dnj6Poj7GozeKl6lUr+S0n9CMClrzZ6JZj7ngG1ulq9gk5ehHayNX5HAJsRI+GiXC5CNX14ce6rCnIqjs/pis6hxikUrforTQv0GxkvuJtd76BhaSvZSCX9IpcTBagxa2ZR6C86A30+IFlFLdoAtHqGrGaKMfe7Fb1lIjfsIgaCvDrlJJQdtug==");

	PutField_CString(hRequest, "auth_data", csInput2);
	PutField_CString(hRequest, "sign", csOutput);
	PutField_CString(hContext, "psp_publiccert", csPubKeyFile);

DEBUGLOG(("%s\n", csInput2));
DEBUGLOG(("%s\n", csOutput));

	BOObjPtr = CreateObj(BOPtr,"BOSecurity","Verify51EpaySign");

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


int batch_proc(int argc, char* argv[])
{
	int iRet;

	char *csOutput;
	csOutput = (char*) malloc (MAX_MSG_SIZE + 1 );
	memset(csOutput, 0, sizeof(csOutput));

	char *csPriKeyFile = "rsa_private_key_pkcs8.pem";
	char *csInput = "amount=7777&merId=300005&seqId=0000000007078403&stat=0000&transDate=20190712&version=2.0";

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

	BOObjPtr = CreateObj(BOPtr,"BOSecurity","GenerateHXPaySign");

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

	char *csInput2 = "amount=6822&merId=300005&seqId=0000000007078372&stat=0000&transDate=20190712&version=2.0";
	char *csSign = "pGV5JQdOrh53PSqXPwVE6F5t52NoNnrMpMSw6PTDOJcltvEn6M74%2FA7GL7Unj4%2BFdFCjU9HmuDLvpOx4JYE16juZBK%2BJxgDh9lFHJZJPhQjm%2FMAvaEvFaW2MtkjkYG1NwbY5aEDslzhnPCu4BhkEADf026wk%2BKiwqIGrhI%2BIH%2Bc%3D";
	char *csPubKeyFile = "rsa_public_key_pkcs8.pem";

printf("csInput2 = [%s]\n",csInput2);
printf("csPubKeyFile = [%s]\n", csPubKeyFile);

	int iLen = 0;
	char csDeSign[PD_TMP_MSG_BUF_LEN];
	urldecode((const unsigned char*)csSign, strlen(csSign), (unsigned char*)csDeSign, &iLen);
	csDeSign[iLen] = '\0';

printf("urldecode(csSign) = [%s]\n",csDeSign);
	PutField_CString(hRequest, "auth_data", csInput2);
	PutField_CString(hRequest, "sign", csDeSign);
	PutField_CString(hContext, "rsa_privatepem", csPubKeyFile);

	BOObjPtr = CreateObj(BOPtr,"BOSecurity","VerifyHXPaySign");

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

