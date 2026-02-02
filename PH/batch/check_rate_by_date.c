
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
           char  filnam[22];
};
static struct sqlcxp sqlfpn =
{
    21,
    "check_rate_by_date.pc"
};


static unsigned int sqlctx = 145437347;


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


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2018/06/14              [WMC]
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include "common.h"
#include "utilitys.h"
#include "expat.h"
#include "myhash.h"
#include "ObjPtr.h"
#include "myrecordset.h"
#include "numutility.h"
//#include "check_rate_by_date.h"
#include <time.h>

#define MAX_CCY_NUM     20

OBJPTR(DB);

char    cDebug='Y';

int batch_init(int argc, char* argv[])
{
        return SUCCESS;
}

int batch_proc(int argc, char* argv[])
{
        int     iRet = SUCCESS;

        char    csDate[PD_DATE_LEN+1];
        char    csEffectDate[PD_TMP_BUF_LEN];

        memset(csDate, 0, sizeof(csDate));
        memset(csEffectDate, 0, sizeof(csEffectDate));

DEBUGLOG(("batch_proc: Get effect date\n"));
        if(argc>0){
                if(strlen(argv[2])==PD_DATE_LEN && is_numeric(argv[2]) && check_valid_date(argv[2])==PD_OK){
                        strcpy(csDate, argv[2]);
                        csEffectDate[PD_DATE_LEN] = '\0';

                        sprintf(csEffectDate,"%.*s-%.*s-%.*s",PD_MM_LEN,&csDate[PD_YYYY_LEN],PD_DD_LEN,&csDate[PD_YYYYMM_LEN],PD_YYYY_LEN,&csDate[0]);
DEBUGLOG(("batch_proc: effect_date = [%s]\n", csEffectDate));
                }
                else{
DEBUGLOG(("batch_proc: Usage: getrate.exec [yyyymmdd]\n"));
                        return FAILURE;
                }
        }

        if(iRet==SUCCESS){

                hash_t  *hGetRate;
                recordset_t     *rGetRate;
                rGetRate = (recordset_t*) malloc (sizeof(recordset_t));
                recordset_init(rGetRate,0);

                printf("FROM_CCY TO_CCY RATE BID MAX_ASK MED_ASK MIN_ASK MAX_BID MED_BID MIN_BID MIN_MAX MEAN_MIN_MAX\n");

DEBUGLOG(("batch_proc: DBExchangeRate: GetAllExchangeRateByExactDate, effect_date = [%s]\n", csDate));
                DBObjPtr = CreateObj(DBPtr,"DBExchangeRate","GetAllExchangeRateByExactDate");
                if ((unsigned long)(DBObjPtr)(csDate,rGetRate) == PD_OK) {
//DEBUGLOG(("batch_proc: DBExchangeRate: GetAllExchangeRateByExactDate Success\n"));
                } else {
DEBUGLOG(("batch_proc: DBExchangeRate: GetAllExchangeRateByExactDate Failed\n"));
                        iRet = FAILURE;
                }

		if (iRet == SUCCESS) {

                        int     iCnt = 0;

                        hGetRate = RecordSet_GetFirst(rGetRate);
                        while(hGetRate) {

                                double  dRate = 0.0;
                                double  dBid = 0.0;
                                double  dMaxAsk = 0.0;
                                double  dMedAsk = 0.0;
                                double  dMinAsk = 0.0;
                                double  dMaxBid = 0.0;
                                double  dMedBid = 0.0;
                                double  dMinBid = 0.0;
                                double  dMinMax = 0.0;
                                double  dMeanMinMax = 0.0;

                                char    *cs_from_ccy = NULL;
                                char    *cs_to_ccy = NULL;
                                char    *cs_effect_date = NULL;

                                if (GetField_CString(hGetRate,"effect_date", &cs_effect_date)) {

                                        GetField_CString(hGetRate,"from_ccy", &cs_from_ccy);
                                        GetField_CString(hGetRate,"to_ccy", &cs_to_ccy);
                                        GetField_Double(hGetRate,"rate", &dRate);
                                        GetField_Double(hGetRate,"bid", &dBid);
                                        GetField_Double(hGetRate,"max_ask", &dMaxAsk);
                                        GetField_Double(hGetRate,"med_ask", &dMedAsk);
                                        GetField_Double(hGetRate,"min_ask", &dMinAsk);
                                        GetField_Double(hGetRate,"max_bid", &dMaxBid);
                                        GetField_Double(hGetRate,"med_bid", &dMedBid);
                                        GetField_Double(hGetRate,"min_bid", &dMinBid);
                                        GetField_Double(hGetRate,"min_max", &dMinMax);
                                        GetField_Double(hGetRate,"mean_min_max", &dMeanMinMax);

                                        printf("%s %s %s %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",cs_from_ccy,cs_to_ccy,cs_effect_date,dRate,dBid,dMaxAsk,dMedAsk,dMinAsk,dMaxBid,dMedBid,dMinBid,dMinMax,dMeanMinMax);
DEBUGLOG(("batch_proc: DBExchangeRate: GetAllExchangeRateByExactDate [%s] from [%s] to [%s] [found]\n", cs_effect_date, cs_from_ccy, cs_to_ccy));

                                        iCnt++;
                                }

                                hGetRate = RecordSet_GetNext(rGetRate);
                        }

                        printf("TOTAL_CNT = [%d]\n", iCnt);
DEBUGLOG(("batch_proc: DBExchangeRate: GetAllExchangeRateByExactDate total_cnt = [%d]\n", iCnt));

                        if (iCnt == 0) {
                                iRet = FAILURE;
                        }

		}

                RecordSet_Destroy(rGetRate);
                FREE_ME(rGetRate);
        }

DEBUGLOG(("batch_proc: iRet[%d]\n", iRet));
        return iRet;
}

int batch_terminate(int argc, char* argv[])
{
    return SUCCESS;
}

