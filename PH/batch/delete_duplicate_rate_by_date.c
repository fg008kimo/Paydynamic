
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
           char  filnam[33];
};
static struct sqlcxp sqlfpn =
{
    32,
    "delete_duplicate_rate_by_date.pc"
};


static unsigned int sqlctx = 384774819;


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
//#include "delete_duplicate_rate_by_date.h"
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

	int     iNumOfCcy = 0;
        
	char    *csTmp = NULL;
        
	char    csDate[PD_DATE_LEN+1];
        char    csEffectDate[PD_TMP_BUF_LEN];
	char    csList[MAX_CCY_NUM][PD_CCY_ID_LEN+1];

	hash_t  *hCurrency;
	recordset_t     *rCurrency;
        rCurrency = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rCurrency,0);

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

	// Get All Support Currency
        if(iRet==SUCCESS){

//DEBUGLOG(("batch_proc: DBCurrency: FindAllCurrency\n"));
		DBObjPtr = CreateObj(DBPtr,"DBCurrency","FindAllCurrency");
                if ((unsigned long)(DBObjPtr)(rCurrency) == PD_OK) {
DEBUGLOG(("batch_proc: DBCurrency: FindAllCurrency Success\n"));
		} else {
DEBUGLOG(("batch_proc: DBCurrency: FindAllCurrency Failed\n"));
ERRLOG("delete_duplicate_rate_by_date: batch_proc: DBCurrency: FindAllCurrency Failed\n");
                        iRet = FAILURE;
                }

                if(iRet==SUCCESS){

                        hCurrency = RecordSet_GetFirst(rCurrency);
                        while(hCurrency){
                                if(GetField_CString(hCurrency,"to_ccy", &csTmp)){
                                        sprintf(csList[iNumOfCcy],"%s",csTmp);
                                }
                                iNumOfCcy ++;
DEBUGLOG(("batch_proc: CCY_ID[%d][%s]\n", iNumOfCcy, csTmp));
                                hCurrency = RecordSet_GetNext(rCurrency);
                        }
                }
	}

	// Delete Duplicate Records
	if(iRet==SUCCESS){

		int	iTmpRet = PD_OK;

		int	iCnt = 0;
		int	iDelCnt = 0;
        	int     iLoop = 0;
        	int     jLoop = 0;

	        char    csFromCcy[PD_CCY_ID_LEN+1];
	        char    csToCcy[PD_TMP_BUF_LEN];

		// From Ccy
		for(iLoop=0; iLoop<iNumOfCcy; iLoop++)
                {
                        memset(csFromCcy, 0, sizeof(csFromCcy));
                        sprintf(csFromCcy, csList[iLoop]);

                        // To Ccy
                        for(jLoop=0; jLoop<iNumOfCcy; jLoop++)
                        {
				memset(csToCcy, 0, sizeof(csToCcy));
				sprintf(csToCcy, csList[jLoop]);	
                        
//DEBUGLOG(("batch_proc: DBExchangeRate: DeleteDuplicateExchangeRateByExactDate\n"));
		                DBObjPtr = CreateObj(DBPtr,"DBExchangeRate","DeleteDuplicateExchangeRateByExactDate");
		                iTmpRet = (unsigned long)(DBObjPtr)(csDate, csFromCcy, csToCcy);
				if (iTmpRet == PD_OK) {
DEBUGLOG(("batch_proc: DBExchangeRate: DeleteDuplicateExchangeRateByExactDate Success\n"));
					iDelCnt++;
        		        } else if (iTmpRet == PD_NOT_FOUND) {
DEBUGLOG(("batch_proc: DBExchangeRate: DeleteDuplicateExchangeRateByExactDate Not Found\n"));
					iRet = FAILURE;
				} else {
DEBUGLOG(("batch_proc: DBExchangeRate: DeleteDuplicateExchangeRateByExactDate Failed\n"));
ERRLOG("delete_duplicate_rate_by_date: batch_proc: DBExchangeRate: DeleteDuplicateExchangeRateByExactDate Failed\n");
                		        iRet = FAILURE;
                		}

				iCnt++;

				if (iRet == FAILURE) {
					break;
				}
			}
	
			if (iRet == FAILURE) {
                       		break;
                       	}
		}

DEBUGLOG(("batch_proc: DBExchangeRate: DeleteDuplicateExchangeRateByExactDate, total_cnt = [%d], del_cnt = [%d]\n", iCnt, iDelCnt));		
        }

DEBUGLOG(("batch_proc: iRet[%d]\n", iRet));
        return iRet;
}

int batch_terminate(int argc, char* argv[])
{
    return SUCCESS;
}

