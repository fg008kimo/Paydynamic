
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
    "aes_test.pc"
};


static unsigned int sqlctx = 145291;


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

char	cDebug='Y';


int batch_init(int argc, char* argv[])
{
        return SUCCESS;
}


void printBytes(unsigned char *buf, unsigned long len) {
  int cnt = 0;
  printf("Mac in hex: ");
  for(cnt=0; cnt<len; cnt++) {
    printf("%02x ", buf[cnt]);
  }
  printf("\n");
}


int batch_proc(int argc, char* argv[])
{
	if(argc<2){
printf("Usage: [Key Size: 16/32] [Message]\n");
		return FAILURE;
	}

	unsigned char csKey[33] = {
			0x2b,0x7e,0x15,0x16, 
			0x28,0xae,0xd2,0xa6,
			0xab,0xf7,0x15,0x88,
			0x09,0xcf,0x4f,0x3c}; 
	unsigned char csMsg[256] = {
			0x6b,0xc1,0xbe,0xe2, 
			0x2e,0x40,0x9f,0x96, 
			0xe9,0x3d,0x7e,0x11, 
			0x73,0x93,0x17,0x2a
			};
	unsigned char csMac[150] = {0};
	unsigned char csDESMac[150] = {0};
	unsigned long iMacLen = 0;

	int iKeyLen = atoi(argv[1]);
	if(iKeyLen!=16 && iKeyLen!=32){
		return FAILURE;
	}
	else{
		if(iKeyLen==16)
			strcpy((char*)csKey,"FA14A14424610CF5");
		else{
			strcpy((char*)csKey,"BE878741E220C5F26F45E6930578CBD0");
		}
	}
	csKey[iKeyLen] = '\0';

	if(argc>2){
		strcpy((char*)csMsg,argv[2]);
		csMsg[strlen(argv[2])] = '\0';
	}

printf("-----------------------------------\nTest AES-CMAC\n");
printf("Key = [%s], Msg = [%s]\n",csKey,csMsg);
	AES_CMAC(csKey, csMsg, strlen((const char*)csMsg),csMac, &iMacLen);

printf("Mac = [%s], Len = [%ld]\n",csMac,iMacLen);
	printBytes(csMac, iMacLen);

	char * csOutMsg = (char*) malloc (PD_TMP_MSG_BUF_LEN+1);
        memset(csOutMsg,0,sizeof(csOutMsg));
	base64_encode(csMac,strlen((char*)csMac),csOutMsg,PD_MAX_BUFFER);
printf("After base64 encoding: Mac = [%s]\n",csOutMsg);


printf("-----------------------------------\nTest 3DES\n");
	unsigned char csDESKey[25];
	strcpy((char*)csDESKey,"B5A46E1A76EC735DEF044237");
	csDESKey[24] = '\0';

printf("Key = [%s], Msg = [%s]\n",csDESKey,csMsg);
	myECBdes3_encrypt_new(csDESKey, strlen((char*)csDESKey),csMsg,strlen((char*)csMsg),csDESMac);

printf("Mac = [%s], Len = [%ld]\n",csDESMac,strlen((char*)csDESMac));
	printBytes(csDESMac, strlen((char*)csDESMac));

        memset(csOutMsg,0,sizeof(csOutMsg));
	base64_encode(csDESMac,strlen((char*)csDESMac),csOutMsg,PD_MAX_BUFFER);
printf("After base64 encoding: Mac = [%s]\n",csOutMsg);

printf("-----------------------------------\n");

	FREE_ME(csOutMsg);
	return SUCCESS;
}

int batch_terminate(int argc, char* argv[])
{
    return SUCCESS;
}
