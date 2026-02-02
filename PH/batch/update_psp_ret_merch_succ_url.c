
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
    "update_psp_ret_merch_succ_url.pc"
};


static unsigned int sqlctx = 625761787;


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
PDProTech (c)2020. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2020/10/15              [WMC]
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
#include "utilitys.h"
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"
#include "ObjPtr.h"
#include "internal.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char cs_psp_id[PD_PSP_ID_LEN+1];
int i_ret_merch_succ_url;

static char cDebug = 'Y';

OBJPTR(DB);

int parse_arg(int argc, char **argv);
int process_update();

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}

int batch_proc(int argc, char* argv[])
{
	int iRet = SUCCESS;

DEBUGLOG(("batch_proc()\n"));

	iRet = parse_arg(argc, argv);
	if (iRet != SUCCESS) {
		printf("*usage: -p psp_id -r ret_merch_succ_url\n");
                return FAILURE;
	}

	iRet = process_update();

DEBUGLOG(("batch_proc() iRet = [%d]\n", iRet));
	return iRet;
}

int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

int parse_arg(int argc, char **argv)
{
	char    c;
        strcpy(cs_psp_id,"");

        if (argc < 4) {
DEBUGLOG(("argc = [%d]\n",argc));
                return FAILURE;
        }

        while ((c = getopt(argc,argv,"p:r:")) != EOF) {
                switch (c) {
                        case 'p':
                                strcpy(cs_psp_id, optarg);
                                break;
			case 'r':
				i_ret_merch_succ_url = atoi(optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_psp_id,""))
                return FAILURE;

        return SUCCESS;
}

int process_update()
{
	int iRet = SUCCESS;

	int iRetMerchSuccURL = PD_FALSE;

	hash_t *hRec;
        hRec = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hRec, 0);

DEBUGLOG(("process_update()\n"));

DEBUGLOG((" psp_id = [%s]\n", cs_psp_id));
DEBUGLOG((" ret_merch_succ_url = [%d]\n", i_ret_merch_succ_url));

	// Get Psp Detail
	DBObjPtr = CreateObj(DBPtr, "DBPspDetail", "GetPspDetail");
     	if ((unsigned long)(*DBObjPtr)(cs_psp_id, hRec) == PD_OK) {
		if (GetField_Int(hRec,"ret_merch_succ_url",&iRetMerchSuccURL)) {
DEBUGLOG((" Call DBPspDetail:: GetPspDetail() Found\n"));
		} else {
			iRet = FAILURE;
DEBUGLOG((" Call DBPspDetail:: GetPspDetail() Not Found!!\n"));
ERRLOG("update_psp_ret_merch_succ_url:: process_update:: Call DBPspDetail:: GetPspDetail() Not Found!!\n");			
		}
        } else {
		iRet = FAILURE;
DEBUGLOG((" Call DBPspDetail:: GetPspDetail() Failure!!\n"));
ERRLOG("update_psp_ret_merch_succ_url:: process_update:: Call DBPspDetail:: GetPspDetail() Failure!!\n");
	}
	
	// Update Psp Detail	
	if (iRet == SUCCESS) {
		hash_destroy(hRec);
		hash_init(hRec, 0);

		PutField_CString(hRec, "psp_id", cs_psp_id);
		PutField_Int(hRec, "ret_merch_succ_url", i_ret_merch_succ_url);
		PutField_CString(hRec, "update_user", PD_UPDATE_USER);	

		DBObjPtr = CreateObj(DBPtr, "DBPspDetail", "Update");
       		if ((unsigned long)(*DBObjPtr)(hRec) == PD_OK) {
DEBUGLOG((" Call DBPspDetail:: Update() Success\n"));
		} else {
        	    	iRet = FAILURE;
DEBUGLOG((" Call DBPspDetail:: Update() Failure!!\n"));
ERRLOG("update_psp_ret_merch_succ_url:: process_update:: Call DBPspDetail:: Update() Failure!!\n");
      		}
	}

	hash_destroy(hRec);
	FREE_ME(hRec);

DEBUGLOG(("process_update() iRet = [%d]\n", iRet));
	return iRet;
}

