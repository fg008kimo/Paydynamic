
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
           char  filnam[18];
};
static struct sqlcxp sqlfpn =
{
    17,
    "eod_crr_glpost.pc"
};


static unsigned int sqlctx = 9615947;


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
Init Version                                       2012/07/17	             Samson Fung

eod_crr_glpost.exec -d 20120718 -c CN -p HBD -t ONPV
eod_crr_glpost.exec -d 20120718 -c CN -p HBD -t ONPAV
eod_crr_glpost.exec -d 20120718 -c CN -p HBD -t ONPA
eod_crr_glpost.exec -d 20120718 -c CN -p HBD -t ONP
eod_crr_glpost.exec -d 20120718 -c CN -p HBD -t ONMSV
eod_crr_glpost.exec -d 20120718 -c CN -p HBD -t ONMS
eod_crr_glpost.exec -d 20120718 -c CN -p HBD -t ONMTF
eod_crr_glpost.exec -d 20120718 -c CN -p HBD -t ONDV
eod_crr_glpost.exec -d 20120718 -c CN -p HBD -t ONDH
eod_crr_glpost.exec -d 20120718 -c CN -p HBD -t ONDF
eod_crr_glpost.exec -d 20120718 -c CN -p HBD -t ONDA

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
#include "batchcommon.h"
#include "common.h"
#include "utilitys.h"
#include "myhash.h"
#include "eod_crr_glpost.h"
#include "ObjPtr.h"

OBJPTR(BO);

char    cDebug = 'Y';
char    cs_date[PD_DATE_LEN + 1];
char    cs_country[PD_COUNTRY_CODE_LEN + 1];
char    cs_product[PD_PRODUCT_CODE_LEN + 1];
char    cs_jnl_type[PD_JNL_TYPE_PREFIX_LEN + 1];

int parse_arg(int argc,char **argv);
int getPostTxn();

int batch_init(int argc, char* argv[])
{
	if (argc < 4) {
		printf("usage: -d Date -c Country -p Product -t Type\n");
	    return FAILURE;
	}
	else
	    return SUCCESS;
}

int batch_proc(int argc, char* argv[])
{
	int	iRet;
	
	iRet = parse_arg(argc,argv);

	if (iRet != SUCCESS) {
    	printf("*usage: -d Date -c Country -p Product -t Type\n");
		return (iRet);
	}
			
	if (iRet == SUCCESS) {
DEBUGLOG(("Txn Date = [%s]\n",cs_date));
DEBUGLOG(("Country = [%s]\n",cs_country));
DEBUGLOG(("Product = [%s]\n",cs_product));
DEBUGLOG(("Type = [%s]\n",cs_jnl_type));
		
		iRet = getPostTxn();
	}
	
DEBUGLOG(("End = [%d]\n",iRet));
	return iRet;

}

int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}
                     
int parse_arg(int argc,char **argv)
{
	char    c;
	          
	while ((c = getopt(argc,argv,"d:c:p:t:")) != EOF) {
	  switch (c) {
		  case 'd':
				  strcpy(cs_date, optarg);
				  break;
		  case 'c':
				  strcpy(cs_country, optarg);
				  break;
		  case 'p':
				  strcpy(cs_product, optarg);
				  break;
		  case 't':
				  strcpy(cs_jnl_type, optarg);
				  break;				  
		  default:
				  return FAILURE;
	  }
	}       
	
//DEBUGLOG(("[%s]\n",cs_date));
//DEBUGLOG(("[%s]\n",cs_country));
//DEBUGLOG(("[%s]\n",cs_product));
//DEBUGLOG(("[%s]\n",cs_jnl_type));
	
	if ((!strcmp(cs_date,"")) || (!strcmp(cs_country,"")) || (!strcmp(cs_product,""))  || (!strcmp(cs_jnl_type,"")))
	  return FAILURE;
	  
	return SUCCESS; 
}

int getPostTxn() {
	int	iRet = PD_OK;
	hash_t	*hReq;
	hReq = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hReq,0);

	// txn_date //
DEBUGLOG(("getPostTxn(): txn_date = [%s]\n",cs_date));
	PutField_CString(hReq,"txn_date",cs_date);

	// country_code //
DEBUGLOG(("getPostTxn(): country_code = [%s]\n",cs_country));
	PutField_CString(hReq,"country_code",cs_country);

	// product_code //
DEBUGLOG(("getPostTxn(): product_code = [%s]\n",cs_product));
	PutField_CString(hReq,"product_code",cs_product);

	// jnl_type_id //
DEBUGLOG(("getPostTxn(): jnl_type_id = [%s]\n",cs_jnl_type));
	PutField_CString(hReq,"jnl_type_id",cs_jnl_type);

	// post_user //
DEBUGLOG(("getPostTxn(): post_user = [%s]\n",PD_UPDATE_USER));
	PutField_CString(hReq,"post_user",PD_UPDATE_USER);
			
	// Build Journal
	BOObjPtr = CreateObj(BOPtr,"BOCrrJnl","Build");
	iRet = (unsigned long) ((*BOObjPtr)(hReq));		
	
DEBUGLOG(("End getPostTxn and return:[%d]\n",iRet));
	return iRet;
}
