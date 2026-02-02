
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
           char  filnam[19];
};
static struct sqlcxp sqlfpn =
{
    18,
    "payout_generate.pc"
};


static unsigned int sqlctx = 20337699;


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
Init Version                                       2014/05/14              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include "batchcommon.h"
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"


#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cs_gen_id[PD_TXN_SEQ_LEN+1];
char    cs_user[PD_USER_LEN + 1];
char    cs_report_date[PD_DATE_LEN + 1];
int	iOnlinePayout;

char cDebug = 'Y';
OBJPTR(BO);
OBJPTR(DB);

int parse_arg(int argc,char **argv);

int batch_init(int argc, char* argv[])
{

    if (argc < 4) {
        printf("usage: -p preview_id -o is_online -d report_date -u user \n");
        return FAILURE;
    }
    else
        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
        int     iRet = PD_OK;

	char    csLocalTxnDateTime[PD_DATETIME_LEN+1];
        char    csTmDate[PD_DATE_LEN+1];
        char    csTmTime[PD_TIME_LEN+1];

	hash_t  *hRequest;
        hRequest = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hRequest,0);

	hash_t  *hContext;
        hContext = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hContext,0);

	hash_t  *hResponse;
        hResponse = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hResponse,0);

	iRet = parse_arg(argc,argv);

        if (iRet != SUCCESS) {
		printf("1. usage: -p preview_id -o is_online -d report_date -u user \n");
                return (iRet);
        }

DEBUGLOG(("Authorize\n"));

DEBUGLOG(("Authorize::preview_id= [%s]\n",cs_gen_id));
	PutField_CString(hRequest,"preview_id",cs_gen_id);

DEBUGLOG(("Authorize::is online payout= [%d]\n",iOnlinePayout));
	PutField_Int(hContext,"online_payout",iOnlinePayout);

DEBUGLOG(("Authorize::report_date= [%s]\n",cs_report_date));
	PutField_CString(hRequest,"report_date",cs_report_date);

DEBUGLOG(("Authorize::add_user= [%s]\n",cs_user));
	PutField_CString(hRequest,"add_user",cs_user);

	char csTmpDate[PD_DATETIME_LEN +1];
        DBObjPtr = CreateObj(DBPtr,"DBSystemControl","FindCode");

        if ((unsigned long)(*DBObjPtr)("CTPHDATE",csTmpDate) == FOUND) {
DEBUGLOG(("Authorize:Current Processor Hub Date= [%s]\n",csTmpDate));
                PutField_CString(hContext,"PHDATE",csTmpDate);
        }
        else {
DEBUGLOG(("Authorize:NOT RECORD\n"));
                iRet = INT_ERR;
ERRLOG("Authorize::Internal Error:WEB Channel:SystemControl Record Not Found\n");
        }

	PutField_CString(hContext,"txn_code",PD_PAYOUT_GENERATE);
	PutField_CString(hContext,"channel_code","MGT");

	strcpy(csLocalTxnDateTime,getdatetime());
	sprintf(csTmDate,"%.*s",PD_DATE_LEN,csLocalTxnDateTime);
	PutField_CString(hContext,"local_tm_date",csTmDate);

	sprintf(csTmTime,"%.*s",PD_TIME_LEN,&csLocalTxnDateTime[PD_DATE_LEN]);
	PutField_CString(hContext,"local_tm_time",csTmTime);

	if(iRet==PD_OK){
DEBUGLOG(("Authorize:Call BOPayout:handle_PayoutGenerate()\n"));
		BOObjPtr = CreateObj(BOPtr,"BOPayout","handle_PayoutGenerate");
		iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest,hResponse);
	}

DEBUGLOG(("payout_generate Normal Exit() iRet = [%d]\n",iRet));
	FREE_ME(hRequest);
	FREE_ME(hContext);
	FREE_ME(hResponse);
	return iRet;
}

int batch_terminate(int argc, char* argv[])
{
        return SUCCESS;
}


int parse_arg(int argc,char **argv)
{
        char    c;
        strcpy(cs_gen_id,"");
        strcpy(cs_report_date,"");
        strcpy(cs_user,"");
	iOnlinePayout = PD_FALSE;

        while ((c = getopt(argc,argv,"p:u:d:o:")) != EOF) {
                switch (c) {
                        case 'p':
                                strcpy(cs_gen_id, optarg);
                                break;
                        case 'd':
                                strcpy(cs_report_date, optarg);
                                break;
                        case 'u':
                                strcpy(cs_user, optarg);
                                break;
                        case 'o':
                                iOnlinePayout=atoi(optarg);
				break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_gen_id,"") || !strcmp(cs_user,"") || !strcmp(cs_report_date,""))
                return FAILURE;

        return SUCCESS;
}
