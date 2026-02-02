
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
    "ol_vip_payout.pc"
};


static unsigned int sqlctx = 5283883;


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

OBJPTR(BO);

char    cs_payout_amt[PD_AMOUNT_LEN+ 1];
char    cs_base_amt[PD_AMOUNT_LEN+ 1];
char    cs_add_amt[PD_AMOUNT_LEN+ 1];
char    cs_random_idx[PD_AMOUNT_LEN];
int	split_cnt = 0;

char	cDebug='Y';

static int parse_arg(int argc,char **argv);

int batch_init(int argc, char* argv[])
{
        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int iRet = SUCCESS;

	iRet = parse_arg(argc,argv);
        if (iRet != SUCCESS) {
                printf("usage: -p [Payout Amount] -s [Split Count] -i [Random Index] -b [Base Amount] -a [Additional Amount] \n");
                return (iRet);
        }

	double dPayoutAmt = string2double((const unsigned char *)cs_payout_amt);
	int iSplitCnt = split_cnt;
	double dLeftAmt = dPayoutAmt;

	double dBaseAmt = string2double((const unsigned char *)cs_base_amt);
	double dAddAmt= string2double((const unsigned char *)cs_add_amt);
	//sscanf(argv[1],"%lf",&dBaseAmt);
	//double dTotalRandom = dPayoutAmt - (double)dBaseAmt*iSplitCnt;

	int iRandMax = 32767;
	double dIdx = string2double((const unsigned char *)cs_random_idx);
	int iCnt = 0;
	
printf("To split a [%.2f] payout. Split Count = [%d]\n",dPayoutAmt,iSplitCnt);
printf("Base Amount [%.2f], Additional Amount [%.2f]\n",dBaseAmt,dAddAmt);
printf("Random Max Count[32767] Range[0,32766], Random Index[%.2f], Random Range[0,%.2f]\n",dIdx,newround(((double)(iRandMax-1)/dIdx),2));
printf("==================================================\n");

	while(iCnt<iSplitCnt-1){
		struct timeval  tv;
		gettimeofday(&tv, NULL);

		unsigned int time_msec = (tv.tv_sec)*1000 + (tv.tv_usec)/1000;
		srand(time_msec+iCnt);
//printf("srand(time_msec+iCnt), (%d+%d)\n",time_msec,iCnt);

		int iRand = (int)(rand()%iRandMax);
		double dRandAmt = newround(((double)iRand/dIdx),2) + dAddAmt;
//printf("iRand = [%d], dRandAmt = [%f]\n",iRand,dRandAmt);

		double dTmpAmt = dBaseAmt + dRandAmt;
		dLeftAmt = dLeftAmt-dTmpAmt;

		iCnt++;

		if(dTmpAmt>=50000.0)
printf(" [%02d]: Split Amt = [%.2f] ***Too Large!!!\n",iCnt,dTmpAmt);
		else if(dTmpAmt<=0.0)
printf(" [%02d]: Split Amt = [%.2f] ***Negative Amount!!!\n",iCnt,dTmpAmt);
		else
printf(" [%02d]: Split Amt = [%.2f]\n",iCnt,dTmpAmt);

	}

	if(dLeftAmt>=50000.0)
printf(" [%02d]: Split Amt = [%.2f] ***Too Large!!!\n",iCnt+1,dLeftAmt);
	else if (dLeftAmt<=0.0)
printf(" [%02d]: Split Amt = [%.2f] ***Negative Amount!!!\n",iCnt+1,dLeftAmt);
	else if (dLeftAmt<10000.0)
printf(" [%02d]: Split Amt = [%.2f] *May be too small?\n",iCnt+1,dLeftAmt);
	else
printf(" [%02d]: Split Amt = [%.2f]\n",iCnt+1,dLeftAmt);

printf("==================================================\n");

	return iRet;
}

static int parse_arg(int argc,char **argv)
{
        char    c;
        strcpy(cs_payout_amt,"");
        strcpy(cs_base_amt,"");
        strcpy(cs_add_amt,"");
	strcpy(cs_random_idx,"");
	split_cnt = -1;

        while ((c = getopt(argc,argv,"p:s:i:b:a:")) != EOF) {
                switch (c) {
                        case 'p':
                                strcpy(cs_payout_amt,optarg);
                                break;
                        case 's':
                                split_cnt = atoi(optarg);
                                break;
                        case 'i':
				strcpy(cs_random_idx,optarg);
                                break;
                        case 'b':
                                strcpy(cs_base_amt, optarg);
                                break;
                        case 'a':
                                strcpy(cs_add_amt, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_payout_amt,"") || !strcmp(cs_base_amt,"") || !strcmp(cs_add_amt,"") || !strcmp(cs_random_idx,"") || split_cnt <=0) 
                return FAILURE;

        return SUCCESS;
}



int batch_terminate(int argc, char* argv[])
{
    return SUCCESS;
}

