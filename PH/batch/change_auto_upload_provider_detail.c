
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
           char  filnam[38];
};
static struct sqlcxp sqlfpn =
{
    37,
    "change_auto_upload_provider_detail.pc"
};


static unsigned int sqlctx = 322102741;


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
Init Version                                       2018/07/16              [WMC]
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include "batchcommon.h"
#include "common.h"
#include "internal.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"
#include "dbutility.h"

#define       PD_DETAIL_TAG   "dt"

OBJPTR(Txn);

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char    cDebug='Y';

int parse_arg(int argc,char **argv);


int batch_init(int argc, char* argv[])
{
  	return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int	iRet = SUCCESS;

	int	i = 0;
	int	iTotalCnt = 0;

	char    csTag[PD_TMP_BUF_LEN];

	hash_t  *hContext;
        hash_t  *hRequest;
        hash_t  *hResponse;
        hContext = (hash_t*) malloc (sizeof(hash_t));
        hRequest = (hash_t*) malloc (sizeof(hash_t));
        hResponse = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hContext,0);
        hash_init(hRequest,0);
        hash_init(hResponse,0);

DEBUGLOG(("batch_proc: start\n"));

	PutField_CString(hRequest,"add_user", "elvis.w");
DEBUGLOG(("add_user = [%s]\n", "elvis.w"));

	iTotalCnt = 3;

	PutField_CString(hRequest,"total_cnt", "3");
DEBUGLOG(("total_cnt = [%s]\n", "3"));

	for (i=0;i<iTotalCnt;i++) {
	
		sprintf(csTag, "%s_action_%d", PD_DETAIL_TAG, i+1);
		PutField_CString(hRequest, csTag, "U");
	
		sprintf(csTag, "%s_nature_%d", PD_DETAIL_TAG, i+1);
                PutField_CString(hRequest, csTag, "POA");
	
		sprintf(csTag, "%s_provider_id_%d", PD_DETAIL_TAG, i+1);
		if (i == 0) {
	                PutField_CString(hRequest, csTag, "OCP0000116");
		} else if (i == 1) {
			PutField_CString(hRequest, csTag, "OF00000011");		
		} else if (i == 2) {
			PutField_CString(hRequest, csTag, "OCP0000089");
		}

		sprintf(csTag, "%s_disabled_%d", PD_DETAIL_TAG, i+1);
		PutField_CString(hRequest, csTag, "1");
	}

DEBUGLOG(("batch_proc: TxnOmtByUsAUP: Authorize\n"));
    	TxnObjPtr = CreateObj(TxnPtr,"TxnOmtByUsAUP","Authorize");
      	if ((unsigned long)(TxnObjPtr)(hContext,hRequest,hResponse) == PD_OK) {
DEBUGLOG(("batch_proc: TxnOmtByUsAUP: Authorize Success\n"));
       	} else {
DEBUGLOG(("batch_proc: TxnOmtByUsAUP: Authorize Failed\n"));
              	iRet = FAILURE;
   	}

	hash_destroy(hContext);
        hash_destroy(hRequest);
        hash_destroy(hResponse);
        FREE_ME(hContext);
        FREE_ME(hRequest);
        FREE_ME(hResponse);

DEBUGLOG(("batch_proc: iRet = [%d]\n", iRet));
	return iRet;
}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

