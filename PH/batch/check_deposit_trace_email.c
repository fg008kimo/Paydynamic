
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
           char  filnam[29];
};
static struct sqlcxp sqlfpn =
{
    28,
    "check_deposit_trace_email.pc"
};


static unsigned int sqlctx = 1410376555;


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
PDProTech (c)2019. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.
 
Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2019/08/12              [WMC]
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
#include "check_deposit_trace_email.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char cs_email_func[PD_EML_FUNCT_LEN+1];

static char    cDebug='Y';

OBJPTR(DB);
OBJPTR(BO);

int parse_arg(int argc,char **argv);
int CreateAlertEmailTpl(hash_t *hData);

int batch_init(int argc, char* argv[])
{
        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int     iRet = SUCCESS;
	int     iDtlRet = PD_ERR;

	hash_t  *hData = NULL;
        hData = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hData,0);

DEBUGLOG(("batch_proc: Start!\n"));

	iRet = parse_arg(argc,argv);
	if (iRet == SUCCESS) {
DEBUGLOG((" Email Func = [%s][%d]\n",cs_email_func,strlen(cs_email_func)));
	} else {
		printf("*usage: -f EMAIL_FUNC\n");
		return FAILURE;
	}

	// Create Alert Email Template
	if (iRet == SUCCESS) { 

		// Alert Email Funct
		PutField_CString(hData, "funct", cs_email_func);
	
		iDtlRet = CreateAlertEmailTpl(hData);
		if (iDtlRet != PD_OK) {
			iRet = FAILURE;
		} 
	}
	
	hash_destroy(hData);
        FREE_ME(hData);

DEBUGLOG(("batch_proc: normal exit!\n"));

	return iRet;
}


int batch_terminate(int argc, char* argv[])
{
        return SUCCESS;
}


int parse_arg(int argc, char **argv)
{
	char	c;
	strcpy(cs_email_func,"");

	if (argc < 2) {
DEBUGLOG(("argc = [%d]\n",argc));
		return FAILURE;
	}

	while ((c = getopt(argc,argv,"f:")) != EOF) {
		switch (c) {
			case 'f':
                                strcpy(cs_email_func, optarg);
                                break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(cs_email_func,""))
		return FAILURE;

        return SUCCESS;
}


int CreateAlertEmailTpl(hash_t *hData)
{
	int iRet = PD_OK;

	int iDynCnt = 0;

	double dAmt = 0.0;

	char *csFunct = NULL;
	
	char csService[PD_TMP_BUF_LEN+1];
	char csTxnId[PD_TMP_BUF_LEN+1];
	char csPspChannel[PD_TMP_BUF_LEN+1];
	char csAmt[PD_TMP_BUF_LEN+1];
	char csCreateDatetime[PD_TMP_BUF_LEN+1];
	char csMerchRef[PD_TMP_BUF_LEN+1];
	char csTraceResult[PD_TMP_BUF_LEN+1];

	hash_t *hTemplate;
       	hTemplate = (hash_t*) malloc (sizeof(hash_t));
       	hash_init(hTemplate,0);

DEBUGLOG(("CreateAlertEmailTpl: Begin\n"));

	memset(csService, 0, sizeof(csService));
	memset(csTxnId, 0, sizeof(csTxnId));
	memset(csPspChannel, 0, sizeof(csPspChannel));
	memset(csAmt, 0, sizeof(csAmt));
	memset(csCreateDatetime, 0, sizeof(csCreateDatetime));
	memset(csMerchRef, 0, sizeof(csMerchRef));
	memset(csTraceResult, 0, sizeof(csTraceResult));

/* funct */
      	if (GetField_CString(hData,"funct",&csFunct)) {
DEBUGLOG((" funct = [%s]\n",csFunct));
             	PutField_CString(hTemplate, "funct", csFunct);
     	} else {
DEBUGLOG((" funct not exists\n"));
           	iRet = INT_ERR;
     	}

	// Set Template Parameters
	if (iRet == PD_OK) {

		// Testing
		dAmt = 1234567.89;
		strcpy(csService, "Vnet");
		strcpy(csTxnId, "0000000007110571");
		strcpy(csPspChannel, "CUP QR");
		strcpy(csAmt, commaprintdouble(dAmt,PD_DECIMAL_LEN));
		strcpy(csCreateDatetime, "2019-08-09 12:45:00");
		strcpy(csMerchRef, "ec0cf979a1aca9f1f91f5f2be98362");
		strcpy(csTraceResult, "PSP replied success");

		// Global
		iDynCnt = set_tpl_dyn_cstring(hTemplate,iDynCnt,"SERVICE","GLO","STR",csService);
		iDynCnt = set_tpl_dyn_cstring(hTemplate,iDynCnt,"MERCH_REF","GLO","STR",csMerchRef);

		// Section
		iDynCnt = set_tpl_dyn_int(hTemplate, iDynCnt, "stbl_head-0", "SEC", "stbl_head-0", 0);
                iDynCnt = set_tpl_dyn_int(hTemplate, iDynCnt, "stbl_body-0", "SEC", "stbl_body-0", 0);
        
		// Data
	    	iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, "ftxn_id-0", "STR", "stbl_body-0", csTxnId);
            	iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, "fpsp_channel-0", "STR", "stbl_body-0", csPspChannel);
		iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, "famt-0", "STR", "stbl_body-0", csAmt);
            	iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, "fcreate_datetime-0", "STR", "stbl_body-0", csCreateDatetime);
            	iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, "fmerch_ref-0", "STR", "stbl_body-0", csMerchRef);
            	iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, "ftrace_result-0", "STR", "stbl_body-0", csTraceResult);
	}

	// Process Alert Email Template
	if (iRet == PD_OK) {
    		PutField_CString(hTemplate, "source", PD_EML_SOURCE_BATCH);
  		PutField_Char(hTemplate, "party_type", PD_TYPE_GLOBAL);
    		PutField_CString(hTemplate, "party_id", PD_EML_PARTY_ID_BATCH);	
   		PutField_Int(hTemplate, "total_dyn", iDynCnt);

		BOObjPtr = CreateObj(BOPtr, "BOAlertEmail", "ProcessTpl");
		iRet = (unsigned long)((*BOObjPtr)(hTemplate));
            	if (iRet == PD_OK) {
DEBUGLOG((" BOAlertEmail:ProcessTpl Success!!\n"));
		} else {
DEBUGLOG((" BOAlertEmail:ProcessTpl Failure!!\n"));
                   	PutField_Int(hTemplate, "internal_error", iRet);
            	}	
	}

	hash_destroy(hTemplate);
      	FREE_ME(hTemplate);

DEBUGLOG(("CreateAlertEmailTpl: iRet = [%d]\n", iRet));
	return iRet;
}

