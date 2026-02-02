
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
           char  filnam[16];
};
static struct sqlcxp sqlfpn =
{
    15,
    "test_mic_bal.pc"
};


static unsigned int sqlctx = 2627723;


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

Change Description                            Change Date     Change By
------------------------------------------    ------------    --------------
Init Version                                  2020/02/26      Michael Chow
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
#include "ObjPtr.h"



OBJPTR(DB);

static char cDebug = 'Y';

int parse_arg(int argc,char **argv);

int process_data(); 
					

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}

int batch_proc(int argc, char* argv[])
{
	int iRet;

	iRet = process_data();

	return iRet;
}

int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

int process_data()
{               
	
	int     iRet = SUCCESS;
	char    csMerchantId[PD_MERCHANT_ID_LEN+1];
	char    csCountryCode[PD_COUNTRY_CODE_LEN+1];
	char    csCcyId[PD_CCY_ID_LEN+1];
	char    csServiceCode[PD_SERVICE_CODE_LEN+1];
	char	csUser[PD_USER_LEN];
	double	dNetAmt;
	double  dReservedAmt;


	double dTotalFloat;
	double dCurrentBal;
	double dCurrentBalSettlement;
	double dTotalReservedAmount;
	
	hash_t* hResult;
	hResult = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hResult,0);

/* Input Parameter */
	strcpy(csMerchantId,"K000000001");
	strcpy(csCountryCode,"CN");
	strcpy(csCcyId,"CNY");
	strcpy(csServiceCode,"VNC");
	dNetAmt = 110889604.9;
	dReservedAmt = 12197.11;
	strcpy(csUser,"tommy");

	

/* UpdateFloat Insert/update TempMicBal */
	DBObjPtr = CreateObj(DBPtr,"DBTestMicBal","UpdateFloat");
	if ((*DBObjPtr)(csMerchantId,csCountryCode,csCcyId,csServiceCode,dNetAmt,dReservedAmt,csUser,hResult) != PD_OK) 
	{
		iRet = PD_ERR;
	}


	if (iRet == PD_OK)
	{	
/*total_float*/
		GetField_Double(hResult,"total_float",&dTotalFloat);
/*current_bal*/
		GetField_Double(hResult,"current_bal",&dCurrentBal);
/*current_bal_settlement*/
		GetField_Double(hResult,"current_bal_settlement",&dCurrentBalSettlement);
/* total_reserved_amount */
		GetField_Double(hResult,"total_reserved_amount",&dTotalReservedAmount);
	}

	
	if (iRet == PD_OK)
	{	
DEBUGLOG(("process_data::commit: MerchantId[%s] Country[%s] CcyId[%s] ServiceCode[%s] NetAmt[%f] ReservedAmt[%f] User[%s]\n",
		csMerchantId,
		csCountryCode,
		csCcyId,
		csServiceCode,
		dNetAmt,
		dReservedAmt,
		csUser
		));

DEBUGLOG(("process_data::commit: total_float[%f] current_bal[%f] current_bal_settlement[%f] total_reserved_amount[%f]\n",
		dTotalFloat,
		dCurrentBal,
		dCurrentBalSettlement,
		dTotalReservedAmount
		));
		
		//TxnCommit();
	}

	hash_destroy(hResult);

	if (hResult)
	{
		FREE_ME(hResult);
	}

	return PD_ERR;		//test
		
	//iRet = PD_ERR;

		
	return iRet;

}


int parse_arg(int argc,char **argv)
{

	return SUCCESS;
}

