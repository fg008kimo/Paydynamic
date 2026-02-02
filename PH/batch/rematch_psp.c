
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
           char  filnam[15];
};
static struct sqlcxp sqlfpn =
{
    14,
    "rematch_psp.pc"
};


static unsigned int sqlctx = 1259019;


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
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/07/12              LokMan Chow
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
#include "common.h"
#include "utilitys.h"
#include "batchcommon.h"
#include "internal.h"
#include "ObjPtr.h"
#include "myrecordset.h"

char    cDebug='Y';

OBJPTR(DB);
char	csDate[PD_DATE_LEN+1];
char	csPspId[PD_PSP_ID_LEN+1];

static int parse_arg(int argc,char **argv);

int batch_init(int argc, char* argv[])
{

    if (argc < 2) {
        printf("usage: -p psp_id -d date\n");
        return FAILURE;
    }
    else
        return SUCCESS;
}

int batch_terminate(int argc, char* argv[])
{
        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int	iRet = PD_OK;
	char*   csTmp;
        char*   csChannelCode;
        char*   csCode;
        char*   csValue;
        char    csCmd[PD_TMP_BUF_LEN+1];
        csChannelCode= (char*) malloc (128);

        hash_t *hRec, *hTxn;
        hTxn = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTxn,0);
        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);


	iRet = parse_arg(argc,argv);
        if (iRet != SUCCESS) {
                printf("usage:  -p psp_id -d date\n");
                return (iRet);
        }

	DBObjPtr = CreateObj(DBPtr,"DBSystemControl","GetAllCodes");
        if ((*DBObjPtr)(rRecordSet) == PD_OK) {
                hRec = RecordSet_GetFirst(rRecordSet);
                while (hRec) {
                        if (GetField_CString(hRec,"code",&csCode)) {
                                if (GetField_CString(hRec,"value",&csValue)) {
                                        if (!strcmp(csCode,"CTEODDATE")) {
DEBUGLOG(("Authorize::current EOD DATE = [%s]\n",csValue));
                                                break;
                                        }
                                }
                        }
                        hRec = RecordSet_GetNext(rRecordSet);
                }
        }
        else {
                iRet = FAILURE;
ERRLOG("TxnMgtByUsREM::Authorize:Unable to find EOD DATE\n");
        }
	
	if(iRet==PD_OK){
                DBObjPtr = CreateObj(DBPtr,"DBPspDetail","GetPspDetail");
                if ((unsigned long)(*DBObjPtr)(csPspId,hTxn) == PD_OK) {
                        if (GetField_CString(hTxn,"psp_channel_code",&csTmp)) {
DEBUGLOG(("Authorize: channel_code  = [%s]\n",csTmp));
                                U2L(csTmp,strlen(csTmp),csChannelCode);
                        }
                }
                else{
                        iRet = FAILURE;
ERRLOG("TxnMgtByUsREM::Authorize: Unable to find channel code\n");
                }
        }


	if(iRet==PD_OK){
                if(!strncmp(csValue,csDate,PD_DATE_LEN)){
                        sprintf(csCmd,"extract_%s_data.sh",csChannelCode);
DEBUGLOG(("Authorize: run command = [%s]\n",csCmd));
                        system(csCmd);
                        sprintf(csCmd,"match_%s_dsp.sh",csChannelCode);
DEBUGLOG(("Authorize: run command = [%s]\n",csCmd));
                        system(csCmd);
                        sprintf(csCmd,"%s_to_cms_report.sh",csChannelCode);
DEBUGLOG(("Authorize: run command = [%s]\n",csCmd));
                        system(csCmd);
                }
                else{
                        sprintf(csCmd,"extract_%s_data_by_date.sh %s",csChannelCode,csDate);
DEBUGLOG(("Authorize: run command = [%s]\n",csCmd));
                        system(csCmd);
                        sprintf(csCmd,"match_%s_dsp_by_date.sh %s",csChannelCode,csDate);
DEBUGLOG(("Authorize: run command = [%s]\n",csCmd));
                        system(csCmd);
                        sprintf(csCmd,"%s_to_cms_report_by_date.sh %s",csChannelCode,csDate);
DEBUGLOG(("Authorize: run command = [%s]\n",csCmd));
                        system(csCmd);
                }

        }

        FREE_ME(hTxn);
        FREE_ME(csChannelCode);
        RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);

	if(iRet==PD_OK)
		return SUCCESS;

	return FAILURE;
}



static int parse_arg(int argc,char **argv)
{
        char    c;
        strcpy(csDate,"");
	strcpy(csPspId,"");

        while ((c = getopt(argc,argv,"p:d:")) != EOF) {
                switch (c) {
                        case 'p':
                                strcpy(csPspId, optarg);
                                break;
                        case 'd':
                                strcpy(csDate, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(csDate,"") || !strcmp(csPspId,""))
                return FAILURE;

        return SUCCESS;
}

