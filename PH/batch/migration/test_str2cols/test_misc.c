
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
char    cDebug;

int ma_num_of_decimal_places(const char *data);


int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}




int batch_proc(int argc, char* argv[])
{
	int 	iRet = PD_OK;

	char	csBuf[1024];
	char	csBuf_temp[100];
	char	csEncTxnSeq[1024];
	//char    csTxnSeq[PD_TXN_SEQ_LEN +1];


	//double	dAmt = 0.0;


	memset(csBuf, 0, sizeof(csBuf));
	memset(csBuf_temp, 0, sizeof(csBuf_temp));
	memset(csEncTxnSeq, 0, sizeof(csEncTxnSeq));

	/* Part 1 */

/*
	sprintf(csBuf_temp, "%s", "abc\(def\)\,");	
	printf("[%s]\n", csBuf_temp);
*/

/*

	sprintf(csEncTxnSeq, "5476BACBFD45A4D9EFBBC455E9101711");
	BOObjPtr = CreateObj(BOPtr,"BOSecurity","Decrypt3DESTxnSeq");
	(BOObjPtr)(csEncTxnSeq,csTxnSeq);
printf("EncTxnSeq[%s]\n", csEncTxnSeq);
printf("TxnSeq[%s]\n", csTxnSeq);

	
	memset(csBuf, 0, sizeof(csBuf));
	sprintf(csBuf, "19352");
printf("csBuf [%s]\n", csBuf);
//	sscanf(csBuf, "%lf", &dAmt);

        dAmt = myctod((const unsigned char *)csBuf,strlen(csBuf)-PD_DECIMAL_LEN,PD_DECIMAL_LEN);

printf("dAmt [%lf]\n", dAmt);
*/

	/* Part 2 */
	int	iRtn = 0;

	//sprintf(csBuf, "%s", "102.20");
        sprintf(csBuf, "%s", "102.02");
	iRtn = ma_num_of_decimal_places(csBuf);

	printf("iRtn = [%d]\n", iRtn);


	return iRet;
}

int ma_num_of_decimal_places(const char *data)
{
        int i = 0, j = 0;
        int go = 0;

        while (*data) {

printf("[%s] [%c] [%d]\n", data, *data, go);

                if (*data >= '0' && *data <= '9' && go == 1) {
                        if (*data == '0') {
                                j++;
                        } else {
                                i += j + 1;
                                j = 0;
                        }
                } else if (go == 0) {
                        if (*data == '.') {
                                go = 1;
                        }
                } else {
                        return i;
                }
                data++;
        }

        return i;
}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}
