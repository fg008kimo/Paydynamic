
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
    "hashkey.pc"
};


static unsigned int sqlctx = 73363;


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

#define KEY	"5ebd05cecabb3a81a5a43bfb895605bd"
#define DATA_H	"888000130|3"
//#define DATA_C	"000037|5948522376|123448723164|TW|150"
//#define DATA_C	"000038|5721628731|873121182961|TW|150"
#define DATA_C	"000039|5819717283|298377361938|TW|150"

int batch_init(int argc, char* argv[])
{
/*	if(argc<2)
	{
DEBUGLOG(("Please input enought arguments\n"));
		return FAILURE;
	}
	else  {
		return SUCCESS;
	}
 */
	return SUCCESS;
}




int batch_proc(int argc, char* argv[])
{
	SHA1Context sha;
	int i;
	//int j;
	char csDateTime[PD_DATETIME_LEN + 1];

	strcpy(csDateTime,getdatetime());
	csDateTime[PD_DATETIME_LEN]='\0';



	//if(argc>1)
	//{
		//for (j=1;j<argc;j++)
		//{
			//printf("\nTest : %s\n",argv[j]);
			SHA1Reset(&sha);
			SHA1Input(&sha, (const unsigned char *)csDateTime, strlen(csDateTime));
			//SHA1Input(&sha, (const unsigned char *)argv[1], strlen(argv[1]));
			if (SHA1Result(&sha))
			{
				//printf("\t");
				for(i = 0; i < 4 ; i++)
				{
					printf("%08X ", sha.Message_Digest[i]);
				}
				printf("\n");
			}
			else
			{
				printf("ERROR-- could not compute message digest\n");
			}

		//}
	//}

/*
	//unsigned char *csOut = (unsigned char*)malloc(20);
	char csOut[17];
	BOObjPtr = CreateObj(BOPtr,"BOSecurity","GenerateMAC");
	if ((unsigned long int)(*BOObjPtr)(KEY,DATA_H,(int)strlen(DATA_H),csOut) == PD_OK){
DEBUGLOG(("MAC of Header= [%s]\n",csOut));
printf("GenerateMAC(%s,%s,%d) -> MAC of Header= [%s]\n",KEY,DATA_H,(int)strlen(DATA_H),csOut);
	}
	else {
DEBUGLOG(("Generate MAC(header) failed\n"));
	}

	BOObjPtr = CreateObj(BOPtr,"BOSecurity","GenerateMAC");
        if ((unsigned long int)(*BOObjPtr)(KEY,DATA_C,(int)strlen(DATA_C),csOut) == PD_OK){
DEBUGLOG(("MAC of Content= [%s]\n",csOut));
printf("GenerateMAC(%s,%s,%d) -> MAC of Content= [%s]\n",KEY,DATA_C,(int)strlen(DATA_C),csOut);
        }
        else {
DEBUGLOG(("Generate MAC(content) failed\n"));
	}

//	free (csOut);
*/

	return SUCCESS;


}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}
