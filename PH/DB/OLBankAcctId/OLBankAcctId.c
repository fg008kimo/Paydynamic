
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
    "OLBankAcctId.pc"
};


static unsigned int sqlctx = 2472971;


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
   unsigned char  *sqhstv[17];
   unsigned long  sqhstl[17];
            int   sqhsts[17];
            short *sqindv[17];
            int   sqinds[17];
   unsigned long  sqharm[17];
   unsigned long  *sqharc[17];
   unsigned short  sqadto[17];
   unsigned short  sqtdso[17];
} sqlstm = {12,17};

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

 static char *sq0003 = 
"select obai_baid , obai_baid_name , obai_int_bank_code , obai_bank_acct_num\
 , obai_psp_id , obai_status , obai_category , obai_sub_provider from ol_bank\
_acct_id where obai_baid = :b0            ";

 static char *sq0006 = 
"select opd_bank_acct_type , obai_baid from ol_bank_acct_id obai , ol_psp_de\
tail opd , ( select obai_int_bank_code , obai_bank_acct_num from ol_bank_acct\
_id where obai_baid = :b0 ) obai2 where obai . obai_int_bank_code = obai2 . o\
bai_int_bank_code and obai . obai_bank_acct_num = obai2 . obai_bank_acct_num \
and obai_psp_id = opd_psp_id and opd_bank_acct_type in ( 'UBC' , 'UBD' )     \
       ";

 static char *sq0008 = 
"select NVL ( max ( obai_code_in_num ) , 0 ) + 1 from ol_bank_acct_id       \
     ";

 static char *sq0009 = 
"select NVL ( max ( obai_pid_code ) , 0 ) + 1 from ol_bank_acct_id where oba\
i_psp_id = :b0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,480,0,6,194,0,0,14,14,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,1,3,0,0,1,4,0,0,1,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
76,0,0,2,72,0,6,256,0,0,2,2,0,1,0,2,3,0,0,1,9,0,0,
99,0,0,3,194,0,9,333,0,2049,1,1,0,1,0,1,9,0,0,
118,0,0,3,0,0,13,335,0,0,8,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,
165,0,0,3,0,0,15,409,0,0,0,0,0,1,0,
180,0,0,3,0,0,15,419,0,0,0,0,0,1,0,
195,0,0,4,229,0,4,456,0,0,5,3,0,1,0,2,9,0,0,2,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
230,0,0,5,155,0,4,517,0,0,4,2,0,1,0,2,9,0,0,2,9,0,0,1,9,0,0,1,9,0,0,
261,0,0,6,390,0,9,578,0,2049,1,1,0,1,0,1,9,0,0,
280,0,0,6,0,0,13,580,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
303,0,0,6,0,0,15,609,0,0,0,0,0,1,0,
318,0,0,6,0,0,15,619,0,0,0,0,0,1,0,
333,0,0,7,0,0,17,702,0,0,1,1,0,1,0,1,9,0,0,
352,0,0,7,0,0,21,703,0,0,0,0,0,1,0,
367,0,0,8,80,0,9,739,0,2049,0,0,0,1,0,
382,0,0,8,0,0,13,741,0,0,1,0,0,1,0,2,3,0,0,
401,0,0,8,0,0,15,754,0,0,0,0,0,1,0,
416,0,0,8,0,0,15,763,0,0,0,0,0,1,0,
431,0,0,9,101,0,9,792,0,2049,1,1,0,1,0,1,9,0,0,
450,0,0,9,0,0,13,794,0,0,1,0,0,1,0,2,3,0,0,
469,0,0,9,0,0,15,807,0,0,0,0,0,1,0,
484,0,0,9,0,0,15,816,0,0,0,0,0,1,0,
499,0,0,10,135,0,4,840,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
522,0,0,11,122,0,4,891,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
549,0,0,12,120,0,4,940,0,0,3,2,0,1,0,2,9,0,0,1,9,0,0,1,9,0,0,
576,0,0,13,326,0,4,1004,0,0,6,4,0,1,0,2,9,0,0,2,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,
615,0,0,14,321,0,4,1068,0,0,4,2,0,1,0,2,9,0,0,2,9,0,0,1,9,0,0,1,9,0,0,
646,0,0,15,397,0,4,1147,0,0,6,3,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,
685,0,0,16,122,0,4,1214,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
708,0,0,17,300,0,4,1269,0,0,5,1,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,1,9,0,0,
743,0,0,0,0,0,56,1375,0,0,1,1,0,1,0,3,102,0,0,
762,0,0,18,99,0,6,1376,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,2,102,0,0,
789,0,0,0,0,0,13,1406,0,0,17,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,2,4,0,0,2,4,0,0,
872,0,0,0,0,0,15,1565,0,0,1,1,0,1,0,1,102,0,0,
891,0,0,0,0,0,78,1566,0,0,1,1,0,1,0,3,102,0,0,
910,0,0,0,0,0,15,1573,0,0,1,1,0,1,0,1,102,0,0,
929,0,0,0,0,0,78,1574,0,0,1,1,0,1,0,3,102,0,0,
948,0,0,0,0,0,56,1638,0,0,1,1,0,1,0,3,102,0,0,
967,0,0,19,122,0,6,1639,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,2,102,0,0,
998,0,0,0,0,0,13,1670,0,0,15,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,1,0,
0,
1073,0,0,0,0,0,15,1813,0,0,1,1,0,1,0,1,102,0,0,
1092,0,0,0,0,0,78,1814,0,0,1,1,0,1,0,3,102,0,0,
1111,0,0,0,0,0,15,1821,0,0,1,1,0,1,0,1,102,0,0,
1130,0,0,0,0,0,78,1822,0,0,1,1,0,1,0,3,102,0,0,
1149,0,0,0,0,0,56,1890,0,0,1,1,0,1,0,3,102,0,0,
1168,0,0,20,136,0,6,1891,0,0,5,5,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,2,102,0,
0,
1203,0,0,0,0,0,13,1917,0,0,11,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
1262,0,0,0,0,0,15,2027,0,0,1,1,0,1,0,1,102,0,0,
1281,0,0,0,0,0,78,2028,0,0,1,1,0,1,0,3,102,0,0,
1300,0,0,0,0,0,15,2035,0,0,1,1,0,1,0,1,102,0,0,
1319,0,0,0,0,0,78,2036,0,0,1,1,0,1,0,3,102,0,0,
1338,0,0,0,0,0,56,2088,0,0,1,1,0,1,0,3,102,0,0,
1357,0,0,21,140,0,6,2089,0,0,5,5,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,2,102,0,
0,
1392,0,0,0,0,0,13,2110,0,0,4,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,1,0,0,
1423,0,0,0,0,0,15,2165,0,0,1,1,0,1,0,1,102,0,0,
1442,0,0,0,0,0,78,2166,0,0,1,1,0,1,0,3,102,0,0,
1461,0,0,0,0,0,15,2173,0,0,1,1,0,1,0,1,102,0,0,
1480,0,0,0,0,0,78,2174,0,0,1,1,0,1,0,3,102,0,0,
1499,0,0,0,0,0,56,2230,0,0,1,1,0,1,0,3,102,0,0,
1518,0,0,22,106,0,6,2231,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,2,102,0,0,
1545,0,0,0,0,0,13,2258,0,0,15,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,3,
0,0,
1620,0,0,0,0,0,15,2396,0,0,1,1,0,1,0,1,102,0,0,
1639,0,0,0,0,0,78,2397,0,0,1,1,0,1,0,3,102,0,0,
1658,0,0,0,0,0,15,2404,0,0,1,1,0,1,0,1,102,0,0,
1677,0,0,0,0,0,78,2405,0,0,1,1,0,1,0,3,102,0,0,
1696,0,0,23,238,0,4,2430,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/01/02              David Wong
Add new GetNextBAIDCode                            2014/05/05              Virginia Yun
Add new GetNextBAIDCodeByPSPID			   2014/09/19		   Dirk Wong
get obai_category				   2014/12/10		   LokMan Chow
Add GetBaidByProviderCatAcctType		   2015/01/23		   Virginia Yun
Modify GetBaidByProviderCategory to get psp_id     2015/02/04              Virginia Yun
Modify GetBaidByBankAcct			   2015/02/26		   Elvis Wong
Add GetCategoryByTxnId			   	   2015/03/20		   Elvis Wong
Allow update init balance                          2015/06/26              David Wong
Modify GetDtlByProviderBankAcct			   2015/11/12		   Elvis Wong	
Add new field apply_deposit_cost (PRD130) 	   2018/06/25		   Ethan Yip
Add Functions
	GetBAIDBalDetails
	GetNewBAIDDetails
        GetIntraToBAIDDetails
	GetLastSMSCreationTime			   
	GetAutoUploadStmtSettings	  	   2019/01/10		   Elvis Wong
Add Function
	GetPayoutTempBAIDAcct		   	   2019/05/30		   Elvis Wong		
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "OLBankAcctId.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char    cDebug;


void OLBankAcctId(char cdebug)
{
	cDebug = cdebug;
}


int Add(const hash_t *hRec)
{
	char *csTmp;
	double dTmp;
	int	iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

 		/* varchar		hv_baid_name[PD_BAID_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_baid_name;

		/* varchar		hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar		hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		/* varchar		hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar		hv_status[PD_ACCOUNT_STATUS_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_status;

		int		hv_apply_deposit_cost;
		double		hv_init_bal;
		int		hv_code_in_num;
		int		hv_pid_code;
		/* varchar		hv_category[PD_BAID_CATEGORY_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_category;

		/* varchar		hv_sub_provider_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_sub_provider_id;

		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_baid = -1;
		short		ind_baid_name = -1;
		short		ind_int_bank_code = -1;
		short		ind_bank_acct_num = -1;
		short		ind_psp_id = -1;
		short		ind_status = -1;
		short		ind_apply_deposit_cost = -1;
		short		ind_init_bal = -1;
		short		ind_code_in_num = -1;
		short		ind_pid_code = -1;
		short		ind_category = -1;
		short		ind_sub_provider_id = -1;
		short		ind_create_user = -1;

		short		hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

	if (GetField_CString(hRec, "baid", &csTmp))
	{
		hv_baid.len = strlen(csTmp);
		strncpy((char*)hv_baid.arr, csTmp, hv_baid.len);
		ind_baid = 0;
	}
DEBUGLOG(("Add: baid = [%.*s]\n", hv_baid.len, hv_baid.arr));

	if (GetField_CString(hRec, "baid_name", &csTmp))
	{
		hv_baid_name.len = strlen(csTmp);
		strncpy((char*)hv_baid_name.arr, csTmp, hv_baid_name.len);
		ind_baid_name = 0;
	}
DEBUGLOG(("Add: baid_name = [%.*s]\n", hv_baid_name.len, hv_baid_name.arr));

	if (GetField_CString(hRec, "int_bank_code", &csTmp))
	{
		hv_int_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_int_bank_code.arr, csTmp, hv_int_bank_code.len);
		ind_int_bank_code = 0;
DEBUGLOG(("Add: int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));
	}

	if (GetField_CString(hRec, "bank_acct_num", &csTmp))
	{
		hv_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_num.arr, csTmp, hv_bank_acct_num.len);
		ind_bank_acct_num = 0;
DEBUGLOG(("Add: bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));
	}

	if (GetField_CString(hRec, "psp_id", &csTmp))
	{
		hv_psp_id.len = strlen(csTmp);
		strncpy((char*)hv_psp_id.arr, csTmp, hv_psp_id.len);
		ind_psp_id = 0;
	}
DEBUGLOG(("Add: psp_id = [%.*s]\n", hv_psp_id.len, hv_psp_id.arr));

	if (GetField_CString(hRec, "status", &csTmp))
	{
		hv_status.len = strlen(csTmp);
		strncpy((char*)hv_status.arr, csTmp, hv_status.len);
		ind_status = 0;
	}
DEBUGLOG(("Add: status = [%.*s]\n", hv_status.len, hv_status.arr));

	if (GetField_Int(hRec, "apply_deposit_cost", &iTmp)) {
		hv_apply_deposit_cost = iTmp;
		ind_apply_deposit_cost = 0;
DEBUGLOG(("Add: apply_deposit_cost = [%d]\n", hv_apply_deposit_cost));
	}

	if (GetField_Double(hRec, "init_bal", &dTmp)) 
	{
		hv_init_bal = dTmp;
		ind_init_bal = 0;
DEBUGLOG(("Add: init_bal = [%lf]\n", hv_init_bal)); 
	}

	if (GetField_Int(hRec, "code_in_num", &iTmp)) {
		hv_code_in_num = iTmp;
                ind_code_in_num= 0;
DEBUGLOG(("Add: code_in_num = [%d]\n", hv_code_in_num));
	}

	if (GetField_Int(hRec, "pid_code", &iTmp)) {
		hv_pid_code = iTmp;
		ind_pid_code = 0;
DEBUGLOG(("Add: pid_code = [%d]\n", hv_pid_code));
	} else {
		hv_pid_code = 0;
		ind_pid_code = 0;
DEBUGLOG(("Add: pid_code = [%d]\n", hv_pid_code));
	}

	if (GetField_CString(hRec, "category", &csTmp)) {
		hv_category.len = strlen(csTmp);
		strncpy((char*)hv_category.arr, csTmp, hv_category.len);
		ind_category = 0;
DEBUGLOG(("Add: category = [%.*s]\n", hv_category.len, hv_category.arr));
	}

	if (GetField_CString(hRec, "sub_provider_id", &csTmp)) {
		hv_sub_provider_id.len = strlen(csTmp);
		strncpy((char*)hv_sub_provider_id.arr, csTmp, hv_sub_provider_id.len);
		ind_sub_provider_id = 0;
DEBUGLOG(("Add: sub_provider_id = [%.*s]\n", hv_sub_provider_id.len, hv_sub_provider_id.arr));
	}

	if (GetField_CString(hRec, "create_user", &csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
	}
DEBUGLOG(("Add: create_user = [%.*s]\n", hv_create_user.len, hv_create_user.arr));

	FREE_ME(csTmp);

	/* EXEC SQL EXECUTE
	BEGIN
		:hv_return_value := sp_ol_bank_acct_id_insert_v2(
				:hv_baid:ind_baid,
				:hv_baid_name:ind_baid_name,
				:hv_int_bank_code:ind_int_bank_code,
				:hv_bank_acct_num:ind_bank_acct_num,
				:hv_psp_id:ind_psp_id,
				:hv_status:ind_status,
				:hv_apply_deposit_cost:ind_apply_deposit_cost,
				:hv_init_bal:ind_init_bal,
				:hv_code_in_num:ind_code_in_num,
				:hv_pid_code:ind_pid_code,
				:hv_category:ind_category,
				:hv_sub_provider_id:ind_sub_provider_id,
				:hv_create_user:ind_create_user);
	END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_bank_acct_id_insert_v2 ( :h\
v_baid:ind_baid , :hv_baid_name:ind_baid_name , :hv_int_bank_code:ind_int_ban\
k_code , :hv_bank_acct_num:ind_bank_acct_num , :hv_psp_id:ind_psp_id , :hv_st\
atus:ind_status , :hv_apply_deposit_cost:ind_apply_deposit_cost , :hv_init_ba\
l:ind_init_bal , :hv_code_in_num:ind_code_in_num , :hv_pid_code:ind_pid_code \
, :hv_category:ind_category , :hv_sub_provider_id:ind_sub_provider_id , :hv_c\
reate_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_baid;
 sqlstm.sqhstl[1] = (unsigned long )22;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_baid;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_baid_name;
 sqlstm.sqhstl[2] = (unsigned long )152;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_baid_name;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[3] = (unsigned long )12;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[4] = (unsigned long )52;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_bank_acct_num;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[5] = (unsigned long )12;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_psp_id;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[6] = (unsigned long )4;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_status;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_apply_deposit_cost;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_apply_deposit_cost;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_init_bal;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_init_bal;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_code_in_num;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_code_in_num;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_pid_code;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_pid_code;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_category;
 sqlstm.sqhstl[11] = (unsigned long )12;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_category;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_sub_provider_id;
 sqlstm.sqhstl[12] = (unsigned long )12;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_sub_provider_id;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[13] = (unsigned long )22;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_create_user;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto add_error;
}



	DEBUGLOG(("Add: Ret = [%d]\n", hv_return_value));
	if (hv_return_value == SP_OK)
	{
		DEBUGLOG(("Add: Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
		ERRLOG("OLBankAcctId_Add: SP_OTHER_ERR TxnAbort\n");
		DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
		ERRLOG("OLBankAcctId_Add: SP_ERR TxnAbort\n");
		DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBankAcctId_Add: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int Delete(const char* csBaid)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO delete_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;


		short hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_baid.len = strlen((const char*)csBaid);
	memcpy(hv_baid.arr, csBaid, hv_baid.len);
DEBUGLOG(("Delete: baid = [%.*s]\n", hv_baid.len, hv_baid.arr));

	/* EXEC SQL EXECUTE
	BEGIN
		:hv_return_value := sp_ol_bank_acct_id_delete(:hv_baid);
	END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_bank_acct_id_delete ( :hv_b\
aid ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )76;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_baid;
 sqlstm.sqhstl[1] = (unsigned long )22;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto delete_error;
}



	DEBUGLOG(("Delete: Ret = [%d]\n", hv_return_value));
	if (hv_return_value == SP_OK)
	{
		DEBUGLOG(("Delete: Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
		ERRLOG("OLBankAcctId_Delete: SP_OTHER_ERR TxnAbort\n");
		DEBUGLOG(("Delete: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
		ERRLOG("OLBankAcctId_Delete: SP_ERR TxnAbort\n");
		DEBUGLOG(("Delete: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

delete_error:
DEBUGLOG(("delete_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBankAcctId_Delete: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int GetBankAcctIdDtl(const char* csBaid, hash_t* hRec)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO getbankacctiddtl_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;


		/* varchar		v_org_baid[PD_BAID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_org_baid;

		/* varchar		v_baid_name[PD_BAID_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_baid_name;

		/* varchar		v_int_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_int_bank_code;

		/* varchar		v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

		/* varchar		v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar		v_status[PD_ACCOUNT_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_status;

		/* varchar		v_category[PD_BAID_CATEGORY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_category;

		/* varchar		v_sub_provider_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_sub_provider_id;


		short		ind_org_baid = -1;
		short		ind_baid_name = -1;
		short		ind_int_bank_code = -1;
		short		ind_bank_acct_num = -1;
		short		ind_psp_id = -1;
		short		ind_status = -1;
		short		ind_category = -1;
		short		ind_sub_provider_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_baid.len = strlen(csBaid);
	memcpy(hv_baid.arr, csBaid, hv_baid.len);
DEBUGLOG(("GetBankAcctIdDtl baid = [%.*s]\n", hv_baid.len, hv_baid.arr));

	/* EXEC SQL DECLARE c_cursor_getbankacctiddtl CURSOR FOR
		select 	obai_baid,
			obai_baid_name,
			obai_int_bank_code,
			obai_bank_acct_num,
			obai_psp_id,
			obai_status,
			obai_category,
			obai_sub_provider
		from ol_bank_acct_id
		where obai_baid = :hv_baid; */ 


	/* EXEC SQL OPEN c_cursor_getbankacctiddtl; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )99;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_baid;
 sqlstm.sqhstl[0] = (unsigned long )22;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getbankacctiddtl_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getbankacctiddtl
		INTO
			:v_org_baid:ind_org_baid,
			:v_baid_name:ind_baid_name,
			:v_int_bank_code:ind_int_bank_code,
			:v_bank_acct_num:ind_bank_acct_num,
			:v_psp_id:ind_psp_id,
			:v_status:ind_status,
			:v_category:ind_category,
			:v_sub_provider_id:ind_sub_provider_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )118;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_org_baid;
  sqlstm.sqhstl[0] = (unsigned long )23;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_org_baid;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_baid_name;
  sqlstm.sqhstl[1] = (unsigned long )153;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_baid_name;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_int_bank_code;
  sqlstm.sqhstl[2] = (unsigned long )13;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_int_bank_code;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_bank_acct_num;
  sqlstm.sqhstl[3] = (unsigned long )53;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_bank_acct_num;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_psp_id;
  sqlstm.sqhstl[4] = (unsigned long )13;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_psp_id;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[5] = (unsigned long )5;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_status;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_category;
  sqlstm.sqhstl[6] = (unsigned long )13;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_category;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_sub_provider_id;
  sqlstm.sqhstl[7] = (unsigned long )13;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_sub_provider_id;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto getbankacctiddtl_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

DEBUGLOG(("GetBankAcctIdDtl found record\n"));

// baid
		if (ind_org_baid >= 0) {
			v_org_baid.arr[v_org_baid.len] = '\0';
			PutField_CString(hRec, "org_baid", (const char*)v_org_baid.arr);
DEBUGLOG(("GetBankAcctIdDtl org_baid = [%s]\n", v_org_baid.arr));
		}

// baid_name
		if (ind_baid_name >= 0) {
			v_baid_name.arr[v_baid_name.len] = '\0';
			PutField_CString(hRec, "baid_name", (const char*)v_baid_name.arr);
DEBUGLOG(("GetBankAcctIdDtl baid_name = [%s]\n", v_baid_name.arr));
		}

// int_bank_code
		if (ind_int_bank_code >= 0) {
			v_int_bank_code.arr[v_int_bank_code.len] = '\0';
			PutField_CString(hRec, "int_bank_code", (const char*)v_int_bank_code.arr);
DEBUGLOG(("GetBankAcctIdDtl int_bank_code = [%s]\n", v_int_bank_code.arr));
		}

// bank_acct_num
		if (ind_bank_acct_num >= 0) {
			v_bank_acct_num.arr[v_bank_acct_num.len] = '\0';
			PutField_CString(hRec, "bank_acct_num", (const char*)v_bank_acct_num.arr);
DEBUGLOG(("GetBankAcctIdDtl bank_acct_num = [%s]\n", v_bank_acct_num.arr));
		}

// psp_id
		if (ind_psp_id >= 0) {
			v_psp_id.arr[v_psp_id.len] = '\0';
			PutField_CString(hRec, "psp_id", (const char*)v_psp_id.arr);
DEBUGLOG(("GetBankAcctIdDtl psp_id = [%s]\n", v_psp_id.arr));
		}

// status
		if (ind_status >= 0) {
			v_status.arr[v_status.len] = '\0';
			PutField_CString(hRec, "status", (const char*)v_status.arr);
DEBUGLOG(("GetBankAcctIdDtl status = [%s]\n", v_status.arr));
		}

// category
		if (ind_category >= 0) {
			v_category.arr[v_category.len] = '\0';
			PutField_CString(hRec, "category", (const char*)v_category.arr);
DEBUGLOG(("GetBankAcctIdDtl category = [%s]\n", v_category.arr));
		}

// sub_provider_id
		if (ind_sub_provider_id >= 0) {
			v_sub_provider_id.arr[v_sub_provider_id.len] = '\0';
			PutField_CString(hRec, "sub_provider_id", (const char*)v_sub_provider_id.arr);
DEBUGLOG(("GetBankAcctIdDtl sub_provider_id = [%s]\n", v_sub_provider_id.arr));
		}
	} while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getbankacctiddtl; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )165;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getbankacctiddtl_error;
}



DEBUGLOG(("GetBankAcctIdDtl Normal Exit\n"));
	return PD_OK;

getbankacctiddtl_error:
DEBUGLOG(("getbankacctiddtl_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBankAcctId_Get: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getbankacctiddtl; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )180;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}


int GetBaidByBankAcct(const char* csIntBankCode, const char* csBankAcctNum,
						const char* csBankAcctType, hash_t* hRec)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO getbaidbybankacct_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar		hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		/* varchar		hv_bank_acct_type[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_bank_acct_type;

		/* varchar		v_baid[PD_BAID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_baid;

		/* varchar		v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;


		short		ind_baid = -1;
		short		ind_psp_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


// input int_bank_code
	hv_int_bank_code.len = strlen(csIntBankCode);
	memcpy(hv_int_bank_code.arr, csIntBankCode, hv_int_bank_code.len);
DEBUGLOG(("GetBaidByBankAcct int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));

// input bank_acct_num
	hv_bank_acct_num.len = strlen(csBankAcctNum);
	memcpy(hv_bank_acct_num.arr, csBankAcctNum, hv_bank_acct_num.len);
DEBUGLOG(("GetBaidByBankAcct bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));

// input bank_acct_type
	hv_bank_acct_type.len = strlen(csBankAcctType);
	memcpy(hv_bank_acct_type.arr, csBankAcctType, hv_bank_acct_type.len);
DEBUGLOG(("GetBaidByBankAcct bank_acct_type = [%.*s]\n", hv_bank_acct_type.len, hv_bank_acct_type.arr));

	/* EXEC SQL select obai_baid, obai_psp_id
			into :v_baid:ind_baid, :v_psp_id:ind_psp_id
			from ol_bank_acct_id, ol_psp_detail
			where obai_int_bank_code = :hv_int_bank_code
/o
			and ((obai_bank_acct_num = :hv_bank_acct_num) or
				(obai_bank_acct_num like '%' || substr(:hv_bank_acct_num, -4, 4)))
o/
			and obai_bank_acct_num = :hv_bank_acct_num
			and obai_status = 'O'
			and obai_psp_id = opd_psp_id
			and opd_bank_acct_type = :hv_bank_acct_type; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select obai_baid , obai_psp_id into :b0:b1 , :b2:b3 from ol\
_bank_acct_id , ol_psp_detail where obai_int_bank_code = :b4 and obai_bank_ac\
ct_num = :b5 and obai_status = 'O' and obai_psp_id = opd_psp_id and opd_bank_\
acct_type = :b6 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )195;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_baid;
 sqlstm.sqhstl[0] = (unsigned long )23;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_baid;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_psp_id;
 sqlstm.sqhstl[1] = (unsigned long )13;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_psp_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[2] = (unsigned long )12;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[3] = (unsigned long )52;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_bank_acct_type;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getbaidbybankacct_error;
}



	if ((ind_baid >= 0) && (ind_psp_id >= 0)) {
		v_baid.arr[v_baid.len] = '\0';
		PutField_CString(hRec, "baid", (const char*)v_baid.arr);
DEBUGLOG(("GetBaidByBankAcct baid = [%s]\n", v_baid.arr));

		v_psp_id.arr[v_psp_id.len] = '\0';
		PutField_CString(hRec, "psp_id", (const char*)v_psp_id.arr);
DEBUGLOG(("GetBaidByBankAcct psp_id = [%s]\n", v_psp_id.arr));

		return PD_OK;
	}

DEBUGLOG(("GetBaidByBankAcct baid not found\n"));
	return PD_ERR;

getbaidbybankacct_error:
DEBUGLOG(("getbaidbybankacct_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBankAcctId_Get: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int GetDtlByBankAcct(const char* csIntBankCode, const char* csBankAcctNum,
						hash_t* hRec)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO getbaidbybankacct_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar		hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		/* varchar		v_baid[PD_BAID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_baid;

		/* varchar		v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;


		short		ind_baid = -1;
		short		ind_psp_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_int_bank_code.len = strlen(csIntBankCode);
	memcpy(hv_int_bank_code.arr, csIntBankCode, hv_int_bank_code.len);
DEBUGLOG(("GetDtlByBankAcct int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));

	hv_bank_acct_num.len = strlen(csBankAcctNum);
	memcpy(hv_bank_acct_num.arr, csBankAcctNum, hv_bank_acct_num.len);
DEBUGLOG(("GetDtlByBankAcct bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));

	/* EXEC SQL	select	obai_baid,
				obai_psp_id
			into 	:v_baid:ind_baid,
				:v_psp_id:ind_psp_id
			from	ol_bank_acct_id
			where	obai_int_bank_code = :hv_int_bank_code
			and	obai_bank_acct_num = :hv_bank_acct_num
			and	obai_status = 'O'; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select obai_baid , obai_psp_id into :b0:b1 , :b2:b3 from ol\
_bank_acct_id where obai_int_bank_code = :b4 and obai_bank_acct_num = :b5 and\
 obai_status = 'O' ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )230;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_baid;
 sqlstm.sqhstl[0] = (unsigned long )23;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_baid;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_psp_id;
 sqlstm.sqhstl[1] = (unsigned long )13;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_psp_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[2] = (unsigned long )12;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[3] = (unsigned long )52;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getbaidbybankacct_error;
}



	if ((ind_baid >= 0) && (ind_psp_id >= 0)) {
		v_baid.arr[v_baid.len] = '\0';
		PutField_CString(hRec, "baid", (const char*)v_baid.arr);
DEBUGLOG(("GetDtlByBankAcct baid = [%s]\n", v_baid.arr));

		v_psp_id.arr[v_psp_id.len] = '\0';
		PutField_CString(hRec, "psp_id", (const char*)v_psp_id.arr);
DEBUGLOG(("GetDtlByBankAcct psp_id = [%s]\n", v_psp_id.arr));

		return PD_OK;
	}

DEBUGLOG(("GetDtlByBankAcct baid not found\n"));
	return PD_ERR;

getbaidbybankacct_error:
DEBUGLOG(("getbaidbybankacct_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBankAcctId_Get: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int GetUnknownCrDrBaid(const char* csBaid, hash_t* hRec)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO getunknowncrdrbaid_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

		/* varchar		v_bank_acct_type[PD_ACCT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_bank_acct_type;

		/* varchar		v_unknown_baid[PD_BAID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_unknown_baid;


		short		ind_bank_acct_type = -1;
		short		ind_unknown_baid = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_baid.len = strlen(csBaid);
	memcpy(hv_baid.arr, csBaid, hv_baid.len);
DEBUGLOG(("GetUnknownCrDrBaid baid = [%.*s]\n", hv_baid.len, hv_baid.arr));

	/* EXEC SQL DECLARE c_cursor_getunknowncrdrbaid CURSOR FOR
		select	opd_bank_acct_type, obai_baid
		from	ol_bank_acct_id obai,
			ol_psp_detail opd,
			(select	obai_int_bank_code, obai_bank_acct_num from ol_bank_acct_id where obai_baid = :hv_baid) obai2
		where	obai.obai_int_bank_code = obai2.obai_int_bank_code
		and	obai.obai_bank_acct_num = obai2.obai_bank_acct_num
		and	obai_psp_id = opd_psp_id
		and	opd_bank_acct_type in ('UBC', 'UBD'); */ 


	/* EXEC SQL OPEN c_cursor_getunknowncrdrbaid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0006;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )261;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_baid;
 sqlstm.sqhstl[0] = (unsigned long )22;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getunknowncrdrbaid_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getunknowncrdrbaid
		INTO
			:v_bank_acct_type:ind_bank_acct_type,
			:v_unknown_baid:ind_unknown_baid; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )280;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_bank_acct_type;
  sqlstm.sqhstl[0] = (unsigned long )6;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_bank_acct_type;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_unknown_baid;
  sqlstm.sqhstl[1] = (unsigned long )23;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_unknown_baid;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto getunknowncrdrbaid_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

DEBUGLOG(("GetUnknownCrDrBaid found record\n"));

// bank_acct_type
		if (ind_bank_acct_type >= 0) {
			v_bank_acct_type.arr[v_bank_acct_type.len] = '\0';
DEBUGLOG(("GetUnknownCrDrBaid bank_acct_type = [%s]\n", v_bank_acct_type.arr));
		}

// unknown_baid
		if (ind_unknown_baid >= 0) {
			v_unknown_baid.arr[v_unknown_baid.len] = '\0';
			if (!strcmp((const char*)v_bank_acct_type.arr, "UKC")) {
				PutField_CString(hRec, "unknown_cr_baid", (const char*)v_unknown_baid.arr);
			} else {
				PutField_CString(hRec, "unknown_dr_baid", (const char*)v_unknown_baid.arr);
			}
DEBUGLOG(("GetUnknownCrDrBaid unknown_cr_baid = [%s]\n", v_unknown_baid.arr));
		}
	} while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getunknowncrdrbaid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )303;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getunknowncrdrbaid_error;
}



DEBUGLOG(("GetUnknownCrDrBaid Normal Exit\n"));
	return PD_OK;

getunknowncrdrbaid_error:
DEBUGLOG(("getunknowncrdrbaid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBankAcctId_Get: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getunknowncrdrbaid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )318;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

int Update(const hash_t *hRls)
{
	char*	csBAID;
        char*   csBuf;
        char*   csTmp;
	double	dTmp = 0.0;
	int	iTmp = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar        hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));

        csBuf = (char*) malloc (512);

        strcpy((char*)hv_dynstmt.arr,"update ol_bank_acct_id set obai_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	GetField_CString(hRls,"baid",&csBAID);
DEBUGLOG(("Update: baid = [%s]\n", csBAID));
	
/* baid_name */
	if (GetField_CString(hRls, "baid_name", &csTmp)) {
DEBUGLOG(("Update: baid_name = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ", obai_baid_name= '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/*status */
        if (GetField_CString(hRls,"status",&csTmp)) {
DEBUGLOG(("Update:status = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ", obai_status = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*apply_deposit_cost*/
	if (GetField_Int(hRls,"apply_deposit_cost", &iTmp)) {
DEBUGLOG(("Update:apply_deposit_cost = [%d]\n", iTmp));
		sprintf(csBuf,"%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", obai_apply_deposit_cost = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/*init bal*/
	if (GetField_Double(hRls,"init_bal",&dTmp)) {
DEBUGLOG(("Update:init_bal = [%lf]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ", obai_init_bal = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/*update_user*/
        if(GetField_CString(hRls,"update_user",&csTmp)){
DEBUGLOG(("Update:update_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",obai_update_user= '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	strcat((char *)hv_dynstmt.arr, " WHERE obai_baid = '");
        strcat((char *)hv_dynstmt.arr, csBAID);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));


        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 14;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )333;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
        sqlstm.sqhstl[0] = (unsigned long )1026;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 14;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )352;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_error;
}



        FREE_ME(csBuf);

DEBUGLOG(("Update Normal Exit\n"));
        return PD_OK;

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLBankAcctId_Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;

}

int GetNextBAIDCode(int  *iNextCodeInNum)
{
	int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO getnextcode_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int     v_code_in_num;

		short   ind_code_in_num = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	/* EXEC SQL DECLARE c_cursor_getnextcode CURSOR FOR
		select NVL(max(obai_code_in_num),0) + 1
		from ol_bank_acct_id; */ 


        /* EXEC SQL OPEN c_cursor_getnextcode; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 14;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0008;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )367;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getnextcode_error;
}



        /* EXEC SQL FETCH c_cursor_getnextcode
        INTO
                :v_code_in_num:ind_code_in_num; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 14;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )382;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_code_in_num;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_code_in_num;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getnextcode_error;
}



        if (ind_code_in_num >=0) {
                *iNextCodeInNum = v_code_in_num;
DEBUGLOG(("GetNextBAIDCode code = [%d]\n",*iNextCodeInNum));
        }
        else {
DEBUGLOG(("GetNextBAIDCode not found\n"));
		iRet = PD_ERR;
        }

	/* EXEC SQL CLOSE c_cursor_getnextcode; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )401;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getnextcode_error;
}



DEBUGLOG(("GetNextBAIDCode Normal Exit iRet =[%d]\n",iRet));
        return iRet;

getnextcode_error:
DEBUGLOG(("getnextcode_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getnextcode; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 14;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )416;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;

}

int GetNextBAIDCodeByPspId(int  *iNextPidCode, const char *csPspId)
{
	int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO getnextcode_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;


		int     v_next_pid_code;
		short   ind_next_pid_code = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_psp_id.len = strlen(csPspId);
	memcpy(hv_psp_id.arr, csPspId, hv_psp_id.len);
DEBUGLOG(("GetNextBAIDCodeByPspId psp_id = [%.*s]\n", hv_psp_id.len, hv_psp_id.arr));

	/* EXEC SQL DECLARE c_cursor_getnextpidcode CURSOR FOR
		select NVL(max(obai_pid_code),0) + 1
		from ol_bank_acct_id
		where obai_psp_id = :hv_psp_id; */ 


        /* EXEC SQL OPEN c_cursor_getnextpidcode; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 14;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0009;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )431;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_psp_id;
        sqlstm.sqhstl[0] = (unsigned long )12;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getnextcode_error;
}



        /* EXEC SQL FETCH c_cursor_getnextpidcode
        INTO
                :v_next_pid_code:ind_next_pid_code; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 14;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )450;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_next_pid_code;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_next_pid_code;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getnextcode_error;
}



        if (ind_next_pid_code >=0) {
                *iNextPidCode = v_next_pid_code;
DEBUGLOG(("GetNextBAIDCodeByPspId code = [%d]\n",v_next_pid_code));
        }
        else {
DEBUGLOG(("GetNextBAIDCodeByPspId not found\n"));
		iRet = PD_ERR;
        }

	/* EXEC SQL CLOSE c_cursor_getnextpidcode; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )469;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getnextcode_error;
}



DEBUGLOG(("GetNextBAIDCodeByPspId Normal Exit iRet =[%d]\n",iRet));
        return iRet;

getnextcode_error:
DEBUGLOG(("getnextcode_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getnextpidcode; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 14;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )484;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;

}

int GetBankAcctIdCountry(const unsigned char* csBaid, unsigned char* csCountry)
{
	int iRet = NOT_FOUND;

	/* EXEC SQL WHENEVER SQLERROR GOTO getbaidcty_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;


		/* varchar	v_country[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;


		short ind_country = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_baid.len = strlen((const char*)csBaid);
	memcpy(hv_baid.arr, csBaid, hv_baid.len);
DEBUGLOG(("GetBankAcctIdCountry baid = [%.*s]\n", hv_baid.len, hv_baid.arr));

	/* EXEC SQL
		select distinct country
		into :v_country:ind_country
		from ol_bank_acct_id, bank_desc
		where obai_baid = :hv_baid
		and obai_int_bank_code = internal_bank_code; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select distinct country into :b0:b1 from ol_bank_acct_id , \
bank_desc where obai_baid = :b2 and obai_int_bank_code = internal_bank_code ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )499;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_country;
 sqlstm.sqhstl[0] = (unsigned long )5;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_country;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_baid;
 sqlstm.sqhstl[1] = (unsigned long )22;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getbaidcty_error;
}



	if (ind_country >= 0) {
		v_country.arr[v_country.len] = '\0';
		strcpy((char*)csCountry, (const char*)v_country.arr);
DEBUGLOG(("country = [%s]\n", csCountry));
		iRet = FOUND;
	}

	if (iRet == FOUND) {
DEBUGLOG(("GetBankAcctIdCountry success [%d]\n", iRet));
	} else {
DEBUGLOG(("GetBankAcctIdCountry failed [%d]\n", iRet));
	}

	return iRet;

getbaidcty_error:
DEBUGLOG(("getbaidcty_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBankAcctId_Get: SP_INTERNAL_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return NOT_FOUND;
}

int CheckPspCategoryExist(const char* csPspId, const char* csCategory)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO checkpspcategoryexist_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar		hv_category[PD_BAID_CATEGORY_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_category;


		int		v_count = -1;
		short		ind_count = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_psp_id.len = strlen(csPspId);
	memcpy(hv_psp_id.arr, csPspId, hv_psp_id.len);
DEBUGLOG(("CheckPspCategoryExist PspId = [%.*s]\n", hv_psp_id.len, hv_psp_id.arr));

	hv_category.len = strlen(csCategory);
	memcpy(hv_category.arr, csCategory, hv_category.len);
DEBUGLOG(("CheckPspCategoryExist Category = [%.*s]\n", hv_category.len, hv_category.arr));

	/* EXEC SQL	select	count(*)
			into 	:v_count:ind_count
			from	ol_bank_acct_id
			where	obai_psp_id = :hv_psp_id
			and	obai_category = :hv_category
			and	obai_status = 'O'; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count ( * ) into :b0:b1 from ol_bank_acct_id where o\
bai_psp_id = :b2 and obai_category = :b3 and obai_status = 'O' ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )522;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_count;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_count;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_category;
 sqlstm.sqhstl[2] = (unsigned long )12;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto checkpspcategoryexist_error;
}



	if (ind_count >= 0) {
		if (v_count > 0) {
DEBUGLOG(("CheckPspCategoryExist count = [%d], Acct Exist, retrun ERR\n", v_count));
			return PD_ERR;
		} else {
DEBUGLOG(("CheckPspCategoryExist count = [%d], Acct not found, retrun normal\n", v_count));
			return PD_OK;
		}
	}

DEBUGLOG(("GetDtlByBankAcct other error\n"));
	return PD_ERR;

checkpspcategoryexist_error:
DEBUGLOG(("checkpspcategoryexist_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBankAcctId_Get: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int GetBaidByPspCategory(const char* csPspId, const char* csCategory, hash_t* hTxn)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO getbaidbypspcat_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar		hv_category[PD_BAID_CATEGORY_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_category;


		/* varchar		v_baid[PD_BAID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_baid;

		short		ind_baid = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_psp_id.len = strlen(csPspId);
	memcpy(hv_psp_id.arr, csPspId, hv_psp_id.len);
DEBUGLOG(("GetBaidByPspCategory PspId = [%.*s]\n", hv_psp_id.len, hv_psp_id.arr));

	hv_category.len = strlen(csCategory);
	memcpy(hv_category.arr, csCategory, hv_category.len);
DEBUGLOG(("GetBaidByPspCategory Category = [%.*s]\n", hv_category.len, hv_category.arr));

	/* EXEC SQL	select	obai_baid
			into 	:v_baid:ind_baid
			from	ol_bank_acct_id
			where	obai_psp_id = :hv_psp_id
			and	obai_category = :hv_category
			and	obai_status = 'O'; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select obai_baid into :b0:b1 from ol_bank_acct_id where oba\
i_psp_id = :b2 and obai_category = :b3 and obai_status = 'O' ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )549;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_baid;
 sqlstm.sqhstl[0] = (unsigned long )23;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_baid;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_category;
 sqlstm.sqhstl[2] = (unsigned long )12;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getbaidbypspcat_error;
}



	if (ind_baid >= 0) {
		v_baid.arr[v_baid.len]= '\0';
		PutField_CString(hTxn,"baid", (const char*)v_baid.arr);
DEBUGLOG(("GetBaidByPspCategory baid = [%s] \n",v_baid.arr));
		return PD_OK;
	} else {
DEBUGLOG(("GetBaidByPspCategory baid not found!!!!!!\n"));
		return PD_ERR;
	}

DEBUGLOG(("GetDtlByBankAcct other error\n"));
	return PD_ERR;

getbaidbypspcat_error:
DEBUGLOG(("getbaidbypspcat_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBankAcctId_Get: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int GetDtlByProviderBankAcct(const char* csProviderId, const char* csBankAcctType,
			const char* csIntBankCode, const char* csBankAcctNum,
			hash_t* hRec)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO getbaidbyproviderbankacct_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_provider_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_provider_id;

		/* varchar		hv_bank_acct_type[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_bank_acct_type;

		/* varchar		hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar		hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		/* varchar		v_baid[PD_BAID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_baid;

		/* varchar		v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;


		short		ind_baid = -1;
		short		ind_psp_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_provider_id.len = strlen(csProviderId);
	memcpy(hv_provider_id.arr, csProviderId, hv_provider_id.len);
DEBUGLOG(("GetDtlByProviderBankAcct provider_id = [%.*s]\n", hv_provider_id.len, hv_provider_id.arr));

	hv_bank_acct_type.len = strlen(csBankAcctType);
	memcpy(hv_bank_acct_type.arr, csBankAcctType, hv_bank_acct_type.len);
DEBUGLOG(("GetDtlByProviderBankAcct bank_acct_type = [%.*s]\n", hv_bank_acct_type.len, hv_bank_acct_type.arr));

	hv_int_bank_code.len = strlen(csIntBankCode);
	memcpy(hv_int_bank_code.arr, csIntBankCode, hv_int_bank_code.len);
DEBUGLOG(("GetDtlByProviderBankAcct int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));

	hv_bank_acct_num.len = strlen(csBankAcctNum);
	memcpy(hv_bank_acct_num.arr, csBankAcctNum, hv_bank_acct_num.len);
DEBUGLOG(("GetDtlByProviderBankAcct bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));

	/* EXEC SQL	select	obai_baid,
				obai_psp_id
			into 	:v_baid:ind_baid,
				:v_psp_id:ind_psp_id
			from	ol_psp_detail, ol_bank_acct_id
			where	opd_client_id = :hv_provider_id
			and	opd_bank_acct_type = :hv_bank_acct_type
			and	opd_disabled = 0
			and	opd_status = 'O'
			and	opd_psp_id = obai_psp_id
			and	obai_int_bank_code = :hv_int_bank_code
			and	obai_bank_acct_num = :hv_bank_acct_num
			and	obai_category = 'ITL_PEND'
			and	obai_status = 'O'; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select obai_baid , obai_psp_id into :b0:b1 , :b2:b3 from ol\
_psp_detail , ol_bank_acct_id where opd_client_id = :b4 and opd_bank_acct_typ\
e = :b5 and opd_disabled = 0 and opd_status = 'O' and opd_psp_id = obai_psp_i\
d and obai_int_bank_code = :b6 and obai_bank_acct_num = :b7 and obai_category\
 = 'ITL_PEND' and obai_status = 'O' ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )576;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_baid;
 sqlstm.sqhstl[0] = (unsigned long )23;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_baid;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_psp_id;
 sqlstm.sqhstl[1] = (unsigned long )13;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_psp_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_provider_id;
 sqlstm.sqhstl[2] = (unsigned long )12;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_bank_acct_type;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[4] = (unsigned long )12;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[5] = (unsigned long )52;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getbaidbyproviderbankacct_error;
}



	if ((ind_baid >= 0) && (ind_psp_id >= 0)) {
		v_baid.arr[v_baid.len] = '\0';
		PutField_CString(hRec, "baid", (const char*)v_baid.arr);
DEBUGLOG(("GetDtlByProviderBankAcct baid = [%s]\n", v_baid.arr));

		v_psp_id.arr[v_psp_id.len] = '\0';
		PutField_CString(hRec, "psp_id", (const char*)v_psp_id.arr);
DEBUGLOG(("GetDtlByProviderBankAcct psp_id = [%s]\n", v_psp_id.arr));

		return PD_OK;
	}

DEBUGLOG(("GetDtlByProviderBankAcct baid not found\n"));
	return PD_ERR;

getbaidbyproviderbankacct_error:
DEBUGLOG(("getbaidbyproviderbankacct_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBankAcctId_Get: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int GetBaidByProviderCategory(const char* csPspId, const char* csCategory, hash_t* hTxn)
{
	int	iRet = PD_ERR;

	/* EXEC SQL WHENEVER SQLERROR GOTO getbaidbypspcat_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar		hv_category[PD_BAID_CATEGORY_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_category;


		/* varchar		v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar		v_baid[PD_BAID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_baid;

		short		ind_psp_id = -1;
		short		ind_baid = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_psp_id.len = strlen(csPspId);
	memcpy(hv_psp_id.arr, csPspId, hv_psp_id.len);
DEBUGLOG(("GetBaidByProviderCategory PspId = [%.*s]\n", hv_psp_id.len, hv_psp_id.arr));

	hv_category.len = strlen(csCategory);
	memcpy(hv_category.arr, csCategory, hv_category.len);
DEBUGLOG(("GetBaidByProviderCategory Category = [%.*s]\n", hv_category.len, hv_category.arr));

	/* EXEC SQL	select	obai_psp_id, obai_baid
			into 	:v_psp_id:ind_psp_id,
				:v_baid:ind_baid
			from ol_bank_acct_id, ol_psp_detail dt_org, ol_psp_detail dt_pend
			where dt_org.opd_psp_id = :hv_psp_id 
			and DT_ORG.OPD_CLIENT_ID = dt_pend.opd_client_id
			and dt_pend.opd_psp_id = obai_psp_id
			and obai_status = 'O'
			and obai_category = :hv_category
			and dt_pend.opd_status = 'O'; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select obai_psp_id , obai_baid into :b0:b1 , :b2:b3 from ol\
_bank_acct_id , ol_psp_detail dt_org , ol_psp_detail dt_pend where dt_org . o\
pd_psp_id = :b4 and DT_ORG . OPD_CLIENT_ID = dt_pend . opd_client_id and dt_p\
end . opd_psp_id = obai_psp_id and obai_status = 'O' and obai_category = :b5 \
and dt_pend . opd_status = 'O' ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )615;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_psp_id;
 sqlstm.sqhstl[0] = (unsigned long )13;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_psp_id;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_baid;
 sqlstm.sqhstl[1] = (unsigned long )23;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_baid;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[2] = (unsigned long )12;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_category;
 sqlstm.sqhstl[3] = (unsigned long )12;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getbaidbypspcat_error;
}



	if (ind_baid >= 0) {
		v_baid.arr[v_baid.len]= '\0';
		PutField_CString(hTxn,"baid", (const char*)v_baid.arr);
DEBUGLOG(("GetBaidByProviderCategory baid = [%s] \n",v_baid.arr));

		iRet = PD_OK;

		if (iRet == PD_OK) {
			v_psp_id.arr[v_psp_id.len]= '\0';
			PutField_CString(hTxn,"new_cat_psp_id", (const char*)v_psp_id.arr);
DEBUGLOG(("GetBaidByProviderCategory psp_id = [%s] \n",v_psp_id.arr));
		}
	} else {
DEBUGLOG(("GetBaidByProviderCategory baid not found!!!!!!\n"));
		iRet = PD_ERR;
	}


	if (iRet == PD_OK)  {
DEBUGLOG(("GetBaidByProviderCategory normal exit\n"));
	} else {
DEBUGLOG(("GetBaidByProviderCategory other error\n"));
	}
	return iRet;

getbaidbypspcat_error:
DEBUGLOG(("getbaidbypspcat_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBankAcctId_Get: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int GetBaidByProviderCatAcctType(const char* csPspId, const char* csCategory, const char* csAcctType, hash_t* hTxn)
{
	int	iRet = PD_ERR;

	/* EXEC SQL WHENEVER SQLERROR GOTO getbaidbypspcataccttype_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar         hv_category[PD_BAID_CATEGORY_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_category;

		/* varchar         hv_acct_type[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_acct_type;


		/* varchar         v_new_baid[PD_BAID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_new_baid;

		/* varchar		v_new_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_new_psp_id;

		/* varchar		v_new_client_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_new_client_id;


		short           ind_new_baid = -1;
		short		ind_new_psp_id = -1;
		short		ind_new_client_id = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_psp_id.len = strlen(csPspId);
	memcpy(hv_psp_id.arr, csPspId, hv_psp_id.len);
DEBUGLOG(("GetBaidByProviderCatAcctType PspId = [%.*s]\n", hv_psp_id.len, hv_psp_id.arr));

	hv_category.len = strlen(csCategory);
	memcpy(hv_category.arr, csCategory, hv_category.len);
DEBUGLOG(("GetBaidByProviderCatAcctType Category = [%.*s]\n", hv_category.len, hv_category.arr));

	hv_acct_type.len = strlen(csAcctType);
	memcpy(hv_acct_type.arr, csAcctType, hv_acct_type.len);
DEBUGLOG(("GetBaidByProviderCatAcctType AcctType = [%.*s]\n", hv_acct_type.len, hv_acct_type.arr));

	/* EXEC SQL        
		select obai_baid, dt_new.opd_psp_id, dt_new.opd_client_id
		into   :v_new_baid:ind_new_baid, 
                       :v_new_psp_id:ind_new_psp_id,
		       :v_new_client_id:ind_new_client_id
		from ol_bank_acct_id, ol_psp_detail dt_new, ol_psp_detail dt_org
		where dt_org.opd_psp_id = :hv_psp_id
		and dt_org.opd_client_id = dt_new.opd_client_id
		and dt_new.opd_bank_acct_type = :hv_acct_type
		and dt_new.opd_psp_id = obai_psp_id
		and obai_category = :hv_category
		and obai_status = 'O'
		and dt_new.opd_status = 'O'; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select obai_baid , dt_new . opd_psp_id , dt_new . opd_clien\
t_id into :b0:b1 , :b2:b3 , :b4:b5 from ol_bank_acct_id , ol_psp_detail dt_ne\
w , ol_psp_detail dt_org where dt_org . opd_psp_id = :b6 and dt_org . opd_cli\
ent_id = dt_new . opd_client_id and dt_new . opd_bank_acct_type = :b7 and dt_\
new . opd_psp_id = obai_psp_id and obai_category = :b8 and obai_status = 'O' \
and dt_new . opd_status = 'O' ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )646;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_new_baid;
 sqlstm.sqhstl[0] = (unsigned long )23;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_new_baid;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_new_psp_id;
 sqlstm.sqhstl[1] = (unsigned long )13;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_new_psp_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_new_client_id;
 sqlstm.sqhstl[2] = (unsigned long )13;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_new_client_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[3] = (unsigned long )12;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_acct_type;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_category;
 sqlstm.sqhstl[5] = (unsigned long )12;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getbaidbypspcataccttype_error;
}




	if (ind_new_baid >= 0) {
		v_new_baid.arr[v_new_baid.len]= '\0';
		PutField_CString(hTxn,"new_baid", (const char*)v_new_baid.arr);
DEBUGLOG(("GetBaidByProviderCatAcctType baid = [%s] \n",v_new_baid.arr));
		iRet = PD_OK;
        } 

	if (ind_new_psp_id >= 0) {
		v_new_psp_id.arr[v_new_psp_id.len]= '\0';
		PutField_CString(hTxn,"new_psp_id", (const char*)v_new_psp_id.arr);
DEBUGLOG(("GetBaidByProviderCatAcctType psp_id = [%s] \n",v_new_psp_id.arr));
        } 

	if (ind_new_client_id >= 0) {
		v_new_client_id.arr[v_new_client_id.len]= '\0';
		PutField_CString(hTxn,"new_client_id", (const char*)v_new_client_id.arr);
DEBUGLOG(("GetBaidByProviderCatAcctType client_id = [%s] \n",v_new_client_id.arr));
        } 


DEBUGLOG(("GetBaidByProviderCatAcctType other error\n"));
        return iRet;

getbaidbypspcataccttype_error:
DEBUGLOG(("getbaidbypspcataccttype_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBankAcctId_GetBaidByProviderCatAcctType: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int GetCategoryByTxnId(const char* csTxnId, char* csCategory)
{
        int     iRet = PD_ERR;

        /* EXEC SQL WHENEVER SQLERROR GOTO getcategorybytxnid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_txn_id;


                /* varchar         v_category[PD_BAID_CATEGORY_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_category;


                short           ind_category = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


// txn_id
        hv_txn_id.len = strlen(csTxnId);
        memcpy(hv_txn_id.arr, csTxnId, hv_txn_id.len);
DEBUGLOG(("GetCategoryByTxnId TxnId = [%.*s]\n", hv_txn_id.len, hv_txn_id.arr));

        /* EXEC SQL
		select  obai_category
		into    :v_category:ind_category 
		from    ol_txn_psp_detail,
        		ol_bank_acct_id
		where   otp_txn_id = :hv_txn_id
		and     otp_baid = obai_baid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 14;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select obai_category into :b0:b1 from ol_txn_psp_det\
ail , ol_bank_acct_id where otp_txn_id = :b2 and otp_baid = obai_baid ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )685;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_category;
        sqlstm.sqhstl[0] = (unsigned long )12;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_category;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_id;
        sqlstm.sqhstl[1] = (unsigned long )22;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getcategorybytxnid_error;
}



/* category */
	if (ind_category >= 0) {
                v_category.arr[v_category.len] = '\0';
                strcpy((char*)csCategory, (const char*)v_category.arr);
DEBUGLOG(("category = [%s]\n", csCategory));
                iRet = PD_OK;
        }

DEBUGLOG(("GetCategoryByTxnId iRet = [%d]\n", iRet));
        return iRet;

getcategorybytxnid_error:
DEBUGLOG(("getcategorybytxnid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBankAcctId_GetCategoryByTxnId: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int GetPFBankAcctByBAIDName(const char* csBAIDName, hash_t* hRec)
{
        int     iRet = PD_NOT_FOUND;

        /* EXEC SQL WHENEVER SQLERROR GOTO getacctbybaidname_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_baid_name[PD_BAID_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_baid_name;


		/* varchar         v_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

		/* varchar         v_bank_acct_num[PD_BANK_ACCT_NUM_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

		/* varchar		v_baid[PD_BAID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_baid;

		/* varchar		v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;


		short           ind_bank_code = -1;
		short           ind_bank_acct_num = -1;
		short           ind_baid = -1;
		short           ind_psp_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


// baid_name
        hv_baid_name.len = strlen(csBAIDName);
        memcpy(hv_baid_name.arr, csBAIDName, hv_baid_name.len);
DEBUGLOG(("GetPFBankAcctByBAIDName BAIDName = [%.*s]\n", hv_baid_name.len, hv_baid_name.arr));

        /* EXEC SQL
		select  obai_int_bank_code,
			obai_bank_acct_num,
			obai_baid,
			obai_psp_id
		into    :v_bank_code:ind_bank_code,
			:v_bank_acct_num:ind_bank_acct_num,
			:v_baid:ind_baid,
			:v_psp_id:ind_psp_id
		from	ol_bank_acct_id, ol_psp_detail
		where   obai_baid_name = :hv_baid_name
		and	obai_status = 'O'
		and	obai_category = 'ITL_PEND'
		and 	obai_psp_id = opd_psp_id
		and	opd_disabled = 0
		and 	opd_status = 'O'; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 14;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select obai_int_bank_code , obai_bank_acct_num , oba\
i_baid , obai_psp_id into :b0:b1 , :b2:b3 , :b4:b5 , :b6:b7 from ol_bank_acct\
_id , ol_psp_detail where obai_baid_name = :b8 and obai_status = 'O' and obai\
_category = 'ITL_PEND' and obai_psp_id = opd_psp_id and opd_disabled = 0 and \
opd_status = 'O' ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )708;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_bank_code;
        sqlstm.sqhstl[0] = (unsigned long )13;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_bank_code;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&v_bank_acct_num;
        sqlstm.sqhstl[1] = (unsigned long )53;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_bank_acct_num;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&v_baid;
        sqlstm.sqhstl[2] = (unsigned long )23;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_baid;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&v_psp_id;
        sqlstm.sqhstl[3] = (unsigned long )13;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_psp_id;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_baid_name;
        sqlstm.sqhstl[4] = (unsigned long )152;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getacctbybaidname_error;
}



/* bank_code  & bank_acct_num */
	if (ind_bank_code >= 0 && ind_bank_acct_num>=0) {
		v_bank_code.arr[v_bank_code.len] = '\0';
		PutField_CString(hRec, "int_bank_code", (const char*)v_bank_code.arr);
DEBUGLOG(("GetPFBankAcctByBAIDName int_bank_code = [%s]\n", v_bank_code.arr));

		v_bank_acct_num.arr[v_bank_acct_num.len] = '\0';
		PutField_CString(hRec, "bank_acct_num", (const char*)v_bank_acct_num.arr);
DEBUGLOG(("GetPFBankAcctByBAIDName bank_acct_num = [%s]\n", v_bank_acct_num.arr));

		iRet = PD_FOUND;
        }
	if (ind_baid >= 0 && ind_psp_id >= 0) {
		v_baid.arr[v_baid.len] = '\0';
		PutField_CString(hRec, "baid", (const char*)v_baid.arr);
DEBUGLOG(("GetPFBankAcctByBAIDName baid = [%s]\n", v_baid.arr));

		v_psp_id.arr[v_psp_id.len] = '\0';
		PutField_CString(hRec, "psp_id", (const char*)v_psp_id.arr);
DEBUGLOG(("GetPFBankAcctByBAIDName psp_id = [%s]\n", v_psp_id.arr));
	}

DEBUGLOG(("GetPFBankAcctByBAIDName iRet = [%d]\n", iRet));
        return iRet;

getacctbybaidname_error:
DEBUGLOG(("getacctbybaidname_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBankAcctId_GetPFBankAcctByBAIDName: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int GetBAIDBalDetails(const char* csBAID, hash_t* hRec)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO getbaidbaldtl_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;


                short           hv_return_value;

		/* varchar         v_provider_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_provider_id;

		/* varchar         v_provider_name[PD_CLIENT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_provider_name;

                /* varchar         v_baid_status[PD_ACCOUNT_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_baid_status;

                /* varchar         v_bank_nature[PD_ACCT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_bank_nature;

		/* varchar         v_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

                /* varchar         v_bank_name[PD_BANK_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

                /* varchar         v_owner_name[PD_OWNER_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_owner_name;

                /* varchar         v_branch_name[PD_BANK_BRANCH_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch_name;

                /* varchar         v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

                /* varchar         v_bank_acct_short_name[PD_BANK_ACCT_SHORT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_bank_acct_short_name;

                /* varchar         v_bank_acct_status[PD_ACCOUNT_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_bank_acct_status;

                /* varchar         v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

                /* varchar         v_country_id[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country_id;

                /* varchar         v_currency_id[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency_id;

                double          v_baid_balance;
                double          v_account_balance;

		short           ind_provider_id = -1;
		short           ind_provider_name = -1;
                short           ind_baid_status = -1;
                short           ind_bank_nature = -1;
                short           ind_bank_code = -1;
                short           ind_bank_name = -1;
                short           ind_owner_name = -1;
                short           ind_branch_name = -1;
                short           ind_bank_acct_num = -1;
                short           ind_bank_acct_short_name = -1;
                short           ind_bank_acct_status = -1;
                short           ind_merchant_id = -1;
                short           ind_country_id = -1;
                short           ind_currency_id = -1;
                short           ind_baid_balance = -1;
                short           ind_account_balance = -1;

                SQL_CURSOR      c_cursor_getbaidbaldtl;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetBAIDBalDetails: Begin\n"));

	// baid
	hv_baid.len = strlen(csBAID);
        memcpy(hv_baid.arr, csBAID, hv_baid.len);
DEBUGLOG(("baid = [%.*s]\n", hv_baid.len, hv_baid.arr));

        /* EXEC SQL ALLOCATE       :c_cursor_getbaidbaldtl; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 14;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )743;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getbaidbaldtl;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getbaidbaldtl_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                                :hv_return_value := sp_ol_get_baid_bal_details(:hv_baid,
                                                                               :c_cursor_getbaidbaldtl);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 14;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_get_baid_bal_details\
 ( :hv_baid , :c_cursor_getbaidbaldtl ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )762;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_baid;
        sqlstm.sqhstl[1] = (unsigned long )22;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&c_cursor_getbaidbaldtl;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getbaidbaldtl_error;
}



DEBUGLOG((" hv_return_value = [%d]\n", hv_return_value));
        if (hv_return_value == SP_OK)
        {
                for (;;) {

			ind_provider_id = -1;
			ind_provider_name = -1;
                        ind_baid_status = -1;
                        ind_bank_nature = -1;
                        ind_bank_code = -1;
                        ind_bank_name = -1;
                        ind_owner_name = -1;
                        ind_branch_name = -1;
                        ind_bank_acct_num = -1;
                        ind_bank_acct_short_name = -1;
                        ind_bank_acct_status = -1;
                        ind_merchant_id = -1;
                        ind_country_id = -1;
                        ind_currency_id = -1;
                        ind_baid_balance = -1;
                        ind_account_balance = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_getbaidbaldtl

                        INTO
				:v_provider_id:ind_provider_id,
				:v_provider_name:ind_provider_name,
                                :v_baid_status:ind_baid_status,
                                :v_bank_nature:ind_bank_nature,
                                :v_bank_code:ind_bank_code,
                                :v_bank_name:ind_bank_name,
                                :v_owner_name:ind_owner_name,
                                :v_branch_name:ind_branch_name,
                                :v_bank_acct_num:ind_bank_acct_num,
                                :v_bank_acct_short_name:ind_bank_acct_short_name,
                                :v_bank_acct_status:ind_bank_acct_status,
                                :v_merchant_id:ind_merchant_id,
                                :v_country_id:ind_country_id,
                                :v_currency_id:ind_currency_id,
                                :v_baid_balance:ind_baid_balance,
                                :v_account_balance:ind_account_balance; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 17;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )789;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getbaidbaldtl;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_provider_id;
                        sqlstm.sqhstl[1] = (unsigned long )13;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_provider_id;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_provider_name;
                        sqlstm.sqhstl[2] = (unsigned long )53;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_provider_name;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_baid_status;
                        sqlstm.sqhstl[3] = (unsigned long )5;
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_baid_status;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_bank_nature;
                        sqlstm.sqhstl[4] = (unsigned long )6;
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_bank_nature;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_bank_code;
                        sqlstm.sqhstl[5] = (unsigned long )13;
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_bank_code;
                        sqlstm.sqinds[5] = (         int  )0;
                        sqlstm.sqharm[5] = (unsigned long )0;
                        sqlstm.sqadto[5] = (unsigned short )0;
                        sqlstm.sqtdso[5] = (unsigned short )0;
                        sqlstm.sqhstv[6] = (unsigned char  *)&v_bank_name;
                        sqlstm.sqhstl[6] = (unsigned long )153;
                        sqlstm.sqhsts[6] = (         int  )0;
                        sqlstm.sqindv[6] = (         short *)&ind_bank_name;
                        sqlstm.sqinds[6] = (         int  )0;
                        sqlstm.sqharm[6] = (unsigned long )0;
                        sqlstm.sqadto[6] = (unsigned short )0;
                        sqlstm.sqtdso[6] = (unsigned short )0;
                        sqlstm.sqhstv[7] = (unsigned char  *)&v_owner_name;
                        sqlstm.sqhstl[7] = (unsigned long )53;
                        sqlstm.sqhsts[7] = (         int  )0;
                        sqlstm.sqindv[7] = (         short *)&ind_owner_name;
                        sqlstm.sqinds[7] = (         int  )0;
                        sqlstm.sqharm[7] = (unsigned long )0;
                        sqlstm.sqadto[7] = (unsigned short )0;
                        sqlstm.sqtdso[7] = (unsigned short )0;
                        sqlstm.sqhstv[8] = (unsigned char  *)&v_branch_name;
                        sqlstm.sqhstl[8] = (unsigned long )153;
                        sqlstm.sqhsts[8] = (         int  )0;
                        sqlstm.sqindv[8] = (         short *)&ind_branch_name;
                        sqlstm.sqinds[8] = (         int  )0;
                        sqlstm.sqharm[8] = (unsigned long )0;
                        sqlstm.sqadto[8] = (unsigned short )0;
                        sqlstm.sqtdso[8] = (unsigned short )0;
                        sqlstm.sqhstv[9] = (unsigned char  *)&v_bank_acct_num;
                        sqlstm.sqhstl[9] = (unsigned long )53;
                        sqlstm.sqhsts[9] = (         int  )0;
                        sqlstm.sqindv[9] = (         short *)&ind_bank_acct_num;
                        sqlstm.sqinds[9] = (         int  )0;
                        sqlstm.sqharm[9] = (unsigned long )0;
                        sqlstm.sqadto[9] = (unsigned short )0;
                        sqlstm.sqtdso[9] = (unsigned short )0;
                        sqlstm.sqhstv[10] = (unsigned char  *)&v_bank_acct_short_name;
                        sqlstm.sqhstl[10] = (unsigned long )23;
                        sqlstm.sqhsts[10] = (         int  )0;
                        sqlstm.sqindv[10] = (         short *)&ind_bank_acct_short_name;
                        sqlstm.sqinds[10] = (         int  )0;
                        sqlstm.sqharm[10] = (unsigned long )0;
                        sqlstm.sqadto[10] = (unsigned short )0;
                        sqlstm.sqtdso[10] = (unsigned short )0;
                        sqlstm.sqhstv[11] = (unsigned char  *)&v_bank_acct_status;
                        sqlstm.sqhstl[11] = (unsigned long )5;
                        sqlstm.sqhsts[11] = (         int  )0;
                        sqlstm.sqindv[11] = (         short *)&ind_bank_acct_status;
                        sqlstm.sqinds[11] = (         int  )0;
                        sqlstm.sqharm[11] = (unsigned long )0;
                        sqlstm.sqadto[11] = (unsigned short )0;
                        sqlstm.sqtdso[11] = (unsigned short )0;
                        sqlstm.sqhstv[12] = (unsigned char  *)&v_merchant_id;
                        sqlstm.sqhstl[12] = (unsigned long )18;
                        sqlstm.sqhsts[12] = (         int  )0;
                        sqlstm.sqindv[12] = (         short *)&ind_merchant_id;
                        sqlstm.sqinds[12] = (         int  )0;
                        sqlstm.sqharm[12] = (unsigned long )0;
                        sqlstm.sqadto[12] = (unsigned short )0;
                        sqlstm.sqtdso[12] = (unsigned short )0;
                        sqlstm.sqhstv[13] = (unsigned char  *)&v_country_id;
                        sqlstm.sqhstl[13] = (unsigned long )5;
                        sqlstm.sqhsts[13] = (         int  )0;
                        sqlstm.sqindv[13] = (         short *)&ind_country_id;
                        sqlstm.sqinds[13] = (         int  )0;
                        sqlstm.sqharm[13] = (unsigned long )0;
                        sqlstm.sqadto[13] = (unsigned short )0;
                        sqlstm.sqtdso[13] = (unsigned short )0;
                        sqlstm.sqhstv[14] = (unsigned char  *)&v_currency_id;
                        sqlstm.sqhstl[14] = (unsigned long )6;
                        sqlstm.sqhsts[14] = (         int  )0;
                        sqlstm.sqindv[14] = (         short *)&ind_currency_id;
                        sqlstm.sqinds[14] = (         int  )0;
                        sqlstm.sqharm[14] = (unsigned long )0;
                        sqlstm.sqadto[14] = (unsigned short )0;
                        sqlstm.sqtdso[14] = (unsigned short )0;
                        sqlstm.sqhstv[15] = (unsigned char  *)&v_baid_balance;
                        sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[15] = (         int  )0;
                        sqlstm.sqindv[15] = (         short *)&ind_baid_balance;
                        sqlstm.sqinds[15] = (         int  )0;
                        sqlstm.sqharm[15] = (unsigned long )0;
                        sqlstm.sqadto[15] = (unsigned short )0;
                        sqlstm.sqtdso[15] = (unsigned short )0;
                        sqlstm.sqhstv[16] = (unsigned char  *)&v_account_balance;
                        sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[16] = (         int  )0;
                        sqlstm.sqindv[16] = (         short *)&ind_account_balance;
                        sqlstm.sqinds[16] = (         int  )0;
                        sqlstm.sqharm[16] = (unsigned long )0;
                        sqlstm.sqadto[16] = (unsigned short )0;
                        sqlstm.sqtdso[16] = (unsigned short )0;
                        sqlstm.sqphsv = sqlstm.sqhstv;
                        sqlstm.sqphsl = sqlstm.sqhstl;
                        sqlstm.sqphss = sqlstm.sqhsts;
                        sqlstm.sqpind = sqlstm.sqindv;
                        sqlstm.sqpins = sqlstm.sqinds;
                        sqlstm.sqparm = sqlstm.sqharm;
                        sqlstm.sqparc = sqlstm.sqharc;
                        sqlstm.sqpadto = sqlstm.sqadto;
                        sqlstm.sqptdso = sqlstm.sqtdso;
                        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
                        if (sqlca.sqlcode == 1403) break;
                        if (sqlca.sqlcode < 0) goto getbaidbaldtl_error;
}



                        if (SQLCODE == SQL_NOT_FOUND) {
                                break;
                        }

/* provider_id */
                        if(ind_provider_id>=0){
                                v_provider_id.arr[v_provider_id.len]='\0';
                                PutField_CString(hRec,"provider_id",(const char*)v_provider_id.arr);
DEBUGLOG((" provider_id = [%s]\n",v_provider_id.arr));
			}

/* provider_name */
                        if(ind_provider_name>=0){
                                v_provider_name.arr[v_provider_name.len]='\0';
                                PutField_CString(hRec,"provider_name",(const char*)v_provider_name.arr);
DEBUGLOG((" provider_name = [%s]\n",v_provider_name.arr));
                        }

/* baid_status */
                        if(ind_baid_status>=0){
                                v_baid_status.arr[v_baid_status.len]='\0';
                                PutField_CString(hRec,"baid_status",(const char*)v_baid_status.arr);
DEBUGLOG((" baid_status = [%s]\n",v_baid_status.arr));
                        }

/* bank_nature */
                        if(ind_bank_nature>=0){
                                v_bank_nature.arr[v_bank_nature.len]='\0';
                                PutField_CString(hRec,"bank_nature",(const char*)v_bank_nature.arr);
DEBUGLOG((" bank_nature = [%s]\n",v_bank_nature.arr));
                        }

/* bank_code */
                        if(ind_bank_code>=0){
                                v_bank_code.arr[v_bank_code.len]='\0';
                                PutField_CString(hRec,"bank_code",(const char*)v_bank_code.arr);
DEBUGLOG((" bank_code = [%s]\n",v_bank_code.arr));
                        }

/* bank_name */
                        if(ind_bank_name>=0){
                                v_bank_name.arr[v_bank_name.len]='\0';
                                PutField_CString(hRec,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG((" bank_name = [%s]\n",v_bank_name.arr));
                        }

/* owner_name */
                        if(ind_owner_name>=0){
                                v_owner_name.arr[v_owner_name.len]='\0';
                                PutField_CString(hRec,"owner_name",(const char*)v_owner_name.arr);
DEBUGLOG((" owner_name = [%s]\n",v_owner_name.arr));
                        }

/* branch_name */
                        if(ind_branch_name>=0){
                                v_branch_name.arr[v_branch_name.len]='\0';
                                PutField_CString(hRec,"branch_name",(const char*)v_branch_name.arr);
DEBUGLOG((" branch_name = [%s]\n",v_branch_name.arr));
                        }

/* bank_acct_num */
                        if(ind_bank_acct_num>=0){
                                v_bank_acct_num.arr[v_bank_acct_num.len]='\0';
                                PutField_CString(hRec,"bank_acct_num",(const char*)v_bank_acct_num.arr);
DEBUGLOG((" bank_acct_num = [%s]\n",v_bank_acct_num.arr));
                        }

/* bank_acct_short_name */
                        if(ind_bank_acct_short_name>=0){
                                v_bank_acct_short_name.arr[v_bank_acct_short_name.len]='\0';
                                PutField_CString(hRec,"bank_acct_short_name",(const char*)v_bank_acct_short_name.arr);
DEBUGLOG((" bank_acct_short_name = [%s]\n",v_bank_acct_short_name.arr));
                        }

/* bank_acct_status */
                        if(ind_bank_acct_status>=0){
                                v_bank_acct_status.arr[v_bank_acct_status.len]='\0';
                                PutField_CString(hRec,"bank_acct_status",(const char*)v_bank_acct_status.arr);
DEBUGLOG((" bank_acct_status = [%s]\n",v_bank_acct_status.arr));
                        }

/* merchant_id */
                        if(ind_merchant_id>=0){
                                v_merchant_id.arr[v_merchant_id.len]='\0';
                                PutField_CString(hRec,"merchant_id",(const char*)v_merchant_id.arr);
DEBUGLOG((" merchant_id = [%s]\n",v_merchant_id.arr));
                        }

/* country_id */
                        if(ind_country_id>=0){
                                v_country_id.arr[v_country_id.len]='\0';
                                PutField_CString(hRec,"country_id",(const char*)v_country_id.arr);
DEBUGLOG((" country_id = [%s]\n",v_country_id.arr));
                        }

/* currency_id */
                        if(ind_currency_id>=0){
                                v_currency_id.arr[v_currency_id.len]='\0';
                                PutField_CString(hRec,"currency_id",(const char*)v_currency_id.arr);
DEBUGLOG((" currency_id = [%s]\n",v_currency_id.arr));
                        }

/* baid_balance */
                        if (ind_baid_balance<0){
                                v_baid_balance = 0;
			}
			PutField_Double(hRec, "baid_balance", v_baid_balance);
DEBUGLOG((" baid_balance = [%f]\n", v_baid_balance));

/* account_balance */
                        if (ind_account_balance<0){
                                v_account_balance = 0;
                        }
			PutField_Double(hRec, "account_balance", v_account_balance);
DEBUGLOG((" account_balance = [%f]\n", v_account_balance));

                }

DEBUGLOG(("GetBAIDBalDetails: Found\n"));
                return PD_FOUND;
        }
        else if (hv_return_value == SP_NOT_FOUND)
        {
DEBUGLOG(("GetBAIDBalDetails: Not Found\n"));
                return PD_NOT_FOUND;
        }
        else if (hv_return_value == SP_OTHER_ERR)
        {
DEBUGLOG(("GetBAIDBalDetails: SP_OTHER_ERR\n"));
ERRLOG("OLBankAcctId::GetBAIDBalDetails: SP_OTHER_ERR\n");
                return PD_OTHER_ERR;
        }
        else if (hv_return_value == SP_ERR)
        {
DEBUGLOG(("GetBAIDBalDetails: SP_ERR\n"));
ERRLOG("OLBankAcctId::GetBAIDBalDetails: SP_ERR\n");
                return PD_ERR;
        }

        /* EXEC SQL CLOSE :c_cursor_getbaidbaldtl; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )872;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getbaidbaldtl;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getbaidbaldtl_error;
}


        /* EXEC SQL FREE :c_cursor_getbaidbaldtl; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )891;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getbaidbaldtl;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getbaidbaldtl_error;
}



getbaidbaldtl_error:
DEBUGLOG(("getbaidbaldtl_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBankAcctId_Get: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE :c_cursor_getbaidbaldtl; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )910;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getbaidbaldtl;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        /* EXEC SQL FREE :c_cursor_getbaidbaldtl; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )929;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getbaidbaldtl;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int GetNewBAIDDetails(const char* csBAID, int iMaxBAIDCnt, recordset_t* myRec)
{
        int     iCnt = 0;
        hash_t  *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getnewbaiddetails_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

		int		hv_max_baid_cnt;		
		
                short           hv_return_value;

		/* varchar         v_baid[PD_BAID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_baid;

		/* varchar         v_provider_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_provider_id;

                /* varchar         v_provider_name[PD_CLIENT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_provider_name;

                /* varchar         v_baid_status[PD_ACCOUNT_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_baid_status;

                /* varchar         v_pid_bank_nature[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_pid_bank_nature;

                /* varchar         v_bank_nature[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_bank_nature;

                /* varchar         v_bank_name[PD_BANK_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

                /* varchar         v_owner_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_owner_name;

		/* varchar         v_branch_name[PD_BANK_BRANCH_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch_name;

                /* varchar         v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

		/* varchar         v_bank_acct_short_name[PD_BANK_ACCT_SHORT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_bank_acct_short_name;

                /* varchar         v_bank_acct_status[PD_ACCOUNT_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_bank_acct_status;

		/* varchar         v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		char            v_rec_end_ind;

                short           ind_baid = -1;
		short           ind_provider_id = -1;
                short           ind_provider_name = -1;
                short           ind_baid_status = -1;
                short           ind_pid_bank_nature = -1;
                short           ind_bank_nature = -1;
                short           ind_bank_name = -1;
                short           ind_owner_name = -1;
		short           ind_branch_name = -1;
                short           ind_bank_acct_num = -1;
		short           ind_bank_acct_short_name = -1;
                short           ind_bank_acct_status = -1;
		short           ind_merchant_id = -1;
		short           ind_rec_end_ind = -1;

                SQL_CURSOR      c_cursor_getnewbaiddetails;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetNewBAIDDetails: Begin\n"));

	// baid
	hv_baid.len = strlen(csBAID);
        memcpy(hv_baid.arr, csBAID, hv_baid.len);
DEBUGLOG(("baid = [%.*s]\n", hv_baid.len, hv_baid.arr));

	// max_baid_cnt
	hv_max_baid_cnt = iMaxBAIDCnt;
DEBUGLOG(("max_baid_cnt = [%d]\n", hv_max_baid_cnt));

        /* EXEC SQL ALLOCATE       :c_cursor_getnewbaiddetails; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )948;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getnewbaiddetails;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getnewbaiddetails_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                                :hv_return_value := sp_ol_get_new_baid_details(:hv_baid,
									       :hv_max_baid_cnt,
                                                                               :c_cursor_getnewbaiddetails);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_get_new_baid_details\
 ( :hv_baid , :hv_max_baid_cnt , :c_cursor_getnewbaiddetails ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )967;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_baid;
        sqlstm.sqhstl[1] = (unsigned long )22;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_max_baid_cnt;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&c_cursor_getnewbaiddetails;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getnewbaiddetails_error;
}



DEBUGLOG((" hv_return_value = [%d]\n", hv_return_value));
	if (hv_return_value == SP_OK)
        {
                for (;;) {
                        myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);

                        ind_baid= -1;
			ind_provider_id = -1;
                        ind_provider_name= -1;
                        ind_baid_status = -1;
                        ind_pid_bank_nature = -1;
                        ind_bank_nature = -1;
                        ind_bank_name = -1;
                        ind_owner_name = -1;
			ind_branch_name = -1;
                        ind_bank_acct_num = -1;
			ind_bank_acct_short_name = -1;
                        ind_bank_acct_status = -1;
			ind_merchant_id = -1;
			ind_rec_end_ind = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_getnewbaiddetails

                        INTO
                                :v_baid:ind_baid,
				:v_provider_id:ind_provider_id,
                                :v_provider_name:ind_provider_name,
                                :v_baid_status:ind_baid_status,
                                :v_pid_bank_nature:ind_pid_bank_nature,
                                :v_bank_nature:ind_bank_nature,
                                :v_bank_name:ind_bank_name,
                                :v_owner_name:ind_owner_name,
				:v_branch_name:ind_branch_name,
                                :v_bank_acct_num:ind_bank_acct_num,
				:v_bank_acct_short_name:ind_bank_acct_short_name,
                                :v_bank_acct_status:ind_bank_acct_status,
				:v_merchant_id:ind_merchant_id,
				:v_rec_end_ind:ind_rec_end_ind; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 17;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )998;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getnewbaiddetails;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_baid;
                        sqlstm.sqhstl[1] = (unsigned long )23;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_baid;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_provider_id;
                        sqlstm.sqhstl[2] = (unsigned long )13;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_provider_id;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_provider_name;
                        sqlstm.sqhstl[3] = (unsigned long )53;
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_provider_name;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_baid_status;
                        sqlstm.sqhstl[4] = (unsigned long )5;
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_baid_status;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_pid_bank_nature;
                        sqlstm.sqhstl[5] = (unsigned long )5;
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_pid_bank_nature;
                        sqlstm.sqinds[5] = (         int  )0;
                        sqlstm.sqharm[5] = (unsigned long )0;
                        sqlstm.sqadto[5] = (unsigned short )0;
                        sqlstm.sqtdso[5] = (unsigned short )0;
                        sqlstm.sqhstv[6] = (unsigned char  *)&v_bank_nature;
                        sqlstm.sqhstl[6] = (unsigned long )5;
                        sqlstm.sqhsts[6] = (         int  )0;
                        sqlstm.sqindv[6] = (         short *)&ind_bank_nature;
                        sqlstm.sqinds[6] = (         int  )0;
                        sqlstm.sqharm[6] = (unsigned long )0;
                        sqlstm.sqadto[6] = (unsigned short )0;
                        sqlstm.sqtdso[6] = (unsigned short )0;
                        sqlstm.sqhstv[7] = (unsigned char  *)&v_bank_name;
                        sqlstm.sqhstl[7] = (unsigned long )153;
                        sqlstm.sqhsts[7] = (         int  )0;
                        sqlstm.sqindv[7] = (         short *)&ind_bank_name;
                        sqlstm.sqinds[7] = (         int  )0;
                        sqlstm.sqharm[7] = (unsigned long )0;
                        sqlstm.sqadto[7] = (unsigned short )0;
                        sqlstm.sqtdso[7] = (unsigned short )0;
                        sqlstm.sqhstv[8] = (unsigned char  *)&v_owner_name;
                        sqlstm.sqhstl[8] = (unsigned long )53;
                        sqlstm.sqhsts[8] = (         int  )0;
                        sqlstm.sqindv[8] = (         short *)&ind_owner_name;
                        sqlstm.sqinds[8] = (         int  )0;
                        sqlstm.sqharm[8] = (unsigned long )0;
                        sqlstm.sqadto[8] = (unsigned short )0;
                        sqlstm.sqtdso[8] = (unsigned short )0;
                        sqlstm.sqhstv[9] = (unsigned char  *)&v_branch_name;
                        sqlstm.sqhstl[9] = (unsigned long )153;
                        sqlstm.sqhsts[9] = (         int  )0;
                        sqlstm.sqindv[9] = (         short *)&ind_branch_name;
                        sqlstm.sqinds[9] = (         int  )0;
                        sqlstm.sqharm[9] = (unsigned long )0;
                        sqlstm.sqadto[9] = (unsigned short )0;
                        sqlstm.sqtdso[9] = (unsigned short )0;
                        sqlstm.sqhstv[10] = (unsigned char  *)&v_bank_acct_num;
                        sqlstm.sqhstl[10] = (unsigned long )53;
                        sqlstm.sqhsts[10] = (         int  )0;
                        sqlstm.sqindv[10] = (         short *)&ind_bank_acct_num;
                        sqlstm.sqinds[10] = (         int  )0;
                        sqlstm.sqharm[10] = (unsigned long )0;
                        sqlstm.sqadto[10] = (unsigned short )0;
                        sqlstm.sqtdso[10] = (unsigned short )0;
                        sqlstm.sqhstv[11] = (unsigned char  *)&v_bank_acct_short_name;
                        sqlstm.sqhstl[11] = (unsigned long )23;
                        sqlstm.sqhsts[11] = (         int  )0;
                        sqlstm.sqindv[11] = (         short *)&ind_bank_acct_short_name;
                        sqlstm.sqinds[11] = (         int  )0;
                        sqlstm.sqharm[11] = (unsigned long )0;
                        sqlstm.sqadto[11] = (unsigned short )0;
                        sqlstm.sqtdso[11] = (unsigned short )0;
                        sqlstm.sqhstv[12] = (unsigned char  *)&v_bank_acct_status;
                        sqlstm.sqhstl[12] = (unsigned long )5;
                        sqlstm.sqhsts[12] = (         int  )0;
                        sqlstm.sqindv[12] = (         short *)&ind_bank_acct_status;
                        sqlstm.sqinds[12] = (         int  )0;
                        sqlstm.sqharm[12] = (unsigned long )0;
                        sqlstm.sqadto[12] = (unsigned short )0;
                        sqlstm.sqtdso[12] = (unsigned short )0;
                        sqlstm.sqhstv[13] = (unsigned char  *)&v_merchant_id;
                        sqlstm.sqhstl[13] = (unsigned long )18;
                        sqlstm.sqhsts[13] = (         int  )0;
                        sqlstm.sqindv[13] = (         short *)&ind_merchant_id;
                        sqlstm.sqinds[13] = (         int  )0;
                        sqlstm.sqharm[13] = (unsigned long )0;
                        sqlstm.sqadto[13] = (unsigned short )0;
                        sqlstm.sqtdso[13] = (unsigned short )0;
                        sqlstm.sqhstv[14] = (unsigned char  *)&v_rec_end_ind;
                        sqlstm.sqhstl[14] = (unsigned long )1;
                        sqlstm.sqhsts[14] = (         int  )0;
                        sqlstm.sqindv[14] = (         short *)&ind_rec_end_ind;
                        sqlstm.sqinds[14] = (         int  )0;
                        sqlstm.sqharm[14] = (unsigned long )0;
                        sqlstm.sqadto[14] = (unsigned short )0;
                        sqlstm.sqtdso[14] = (unsigned short )0;
                        sqlstm.sqphsv = sqlstm.sqhstv;
                        sqlstm.sqphsl = sqlstm.sqhstl;
                        sqlstm.sqphss = sqlstm.sqhsts;
                        sqlstm.sqpind = sqlstm.sqindv;
                        sqlstm.sqpins = sqlstm.sqinds;
                        sqlstm.sqparm = sqlstm.sqharm;
                        sqlstm.sqparc = sqlstm.sqharc;
                        sqlstm.sqpadto = sqlstm.sqadto;
                        sqlstm.sqptdso = sqlstm.sqtdso;
                        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
                        if (sqlca.sqlcode == 1403) break;
                        if (sqlca.sqlcode < 0) goto getnewbaiddetails_error;
}



                        if (SQLCODE == SQL_NOT_FOUND) {
                                break;
                        }
/* baid */
                        if(ind_baid>=0){
                                v_baid.arr[v_baid.len]='\0';
                                PutField_CString(myHash,"baid",(const char*)v_baid.arr);
DEBUGLOG((" baid = [%s]\n",v_baid.arr));
                        }

/* provider_id */
                        if(ind_provider_id>=0){
                                v_provider_id.arr[v_provider_id.len]='\0';
                                PutField_CString(myHash,"provider_id",(const char*)v_provider_id.arr);
DEBUGLOG((" provider_id = [%s]\n",v_provider_id.arr));
			}

/* provider_name */
                        if(ind_provider_name>=0){
                                v_provider_name.arr[v_provider_name.len]='\0';
                                PutField_CString(myHash,"provider_name",(const char*)v_provider_name.arr);
DEBUGLOG((" provider_name = [%s]\n",v_provider_name.arr));
                        }

/* baid_status */
                        if(ind_baid_status>=0){
                                v_baid_status.arr[v_baid_status.len]='\0';
                                PutField_CString(myHash,"baid_status",(const char*)v_baid_status.arr);
DEBUGLOG((" baid_status = [%s]\n",v_baid_status.arr));
                        }

/* pid_bank_nature */
                        if(ind_pid_bank_nature>=0){
                                v_pid_bank_nature.arr[v_pid_bank_nature.len]='\0';
                                PutField_CString(myHash,"pid_bank_nature",(const char*)v_pid_bank_nature.arr);
DEBUGLOG((" pid_bank_nature = [%s]\n",v_pid_bank_nature.arr));
                        }

/* bank_nature */
                        if(ind_bank_nature>=0){
                                v_bank_nature.arr[v_bank_nature.len]='\0';
                                PutField_CString(myHash,"bank_nature",(const char*)v_bank_nature.arr);
DEBUGLOG((" bank_nature = [%s]\n",v_bank_nature.arr));
                        }

/* bank_name */
                        if(ind_bank_name>=0){
                                v_bank_name.arr[v_bank_name.len]='\0';
                                PutField_CString(myHash,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG((" bank_name = [%s]\n",v_bank_name.arr));
                        }

/* owner_name */
                        if(ind_owner_name>=0){
                                v_owner_name.arr[v_owner_name.len]='\0';
                                PutField_CString(myHash,"owner_name",(const char*)v_owner_name.arr);
DEBUGLOG((" owner_name = [%s]\n",v_owner_name.arr));
                        }

/* branch_name */
                        if(ind_branch_name>=0){
                                v_branch_name.arr[v_branch_name.len]='\0';
                                PutField_CString(myHash,"branch_name",(const char*)v_branch_name.arr);
DEBUGLOG((" branch_name = [%s]\n",v_branch_name.arr));
                        }

/* bank_acct_num */
                        if(ind_bank_acct_num>=0){
                                v_bank_acct_num.arr[v_bank_acct_num.len]='\0';
                                PutField_CString(myHash,"bank_acct_num",(const char*)v_bank_acct_num.arr);
DEBUGLOG((" bank_acct_num = [%s]\n",v_bank_acct_num.arr));
                        }

/* bank_acct_short_name */
                        if(ind_bank_acct_short_name>=0){
                                v_bank_acct_short_name.arr[v_bank_acct_short_name.len]='\0';
                                PutField_CString(myHash,"bank_acct_short_name",(const char*)v_bank_acct_short_name.arr);
DEBUGLOG((" bank_acct_short_name = [%s]\n",v_bank_acct_short_name.arr));
                        }

/* bank_acct_status */
                        if(ind_bank_acct_status>=0){
                                v_bank_acct_status.arr[v_bank_acct_status.len]='\0';
                                PutField_CString(myHash,"bank_acct_status",(const char*)v_bank_acct_status.arr);
DEBUGLOG((" bank_acct_status = [%s]\n",v_bank_acct_status.arr));
                        }
			
/* merchant_id */
                        if(ind_merchant_id>=0){
                                v_merchant_id.arr[v_merchant_id.len]='\0';
                                PutField_CString(myHash,"merchant_id",(const char*)v_merchant_id.arr);
DEBUGLOG((" merchant_id = [%s]\n",v_merchant_id.arr));
                        }

/* rec_end_ind */
                        if(ind_rec_end_ind>=0){
                                PutField_Char(myHash,"rec_end_ind",v_rec_end_ind);
DEBUGLOG((" rec_end_ind = [%c]\n",v_rec_end_ind));
                        }

			RecordSet_Add(myRec,myHash);
                        iCnt++;
                }

DEBUGLOG(("GetNewBAIDDetails: Found\n"));
                return PD_FOUND;
        }
	else if (hv_return_value == SP_NOT_FOUND)
        {
DEBUGLOG(("GetNewBAIDDetails: Not Found\n"));
                return PD_NOT_FOUND;
        }
        else if (hv_return_value == SP_OTHER_ERR)
        {
DEBUGLOG(("GetNewBAIDDetails: SP_OTHER_ERR\n"));
ERRLOG("OLBankAcctId::GetNewBAIDDetails: SP_OTHER_ERR\n");
                return PD_OTHER_ERR;
        }
        else if (hv_return_value == SP_ERR)
        {
DEBUGLOG(("GetNewBAIDDetails: SP_ERR\n"));
ERRLOG("OLBankAcctId::GetNewBAIDDetails: SP_ERR\n");
                return PD_ERR;
        }

        /* EXEC SQL CLOSE :c_cursor_getnewbaiddetails; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1073;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getnewbaiddetails;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getnewbaiddetails_error;
}


        /* EXEC SQL FREE :c_cursor_getnewbaiddetails; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1092;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getnewbaiddetails;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getnewbaiddetails_error;
}



getnewbaiddetails_error:
DEBUGLOG(("getnewbaiddetails_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBankAcctId_Get: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE :c_cursor_getnewbaiddetails; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1111;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getnewbaiddetails;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        /* EXEC SQL FREE :c_cursor_getnewbaiddetails; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1130;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getnewbaiddetails;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int GetIntraToBAIDDetails(hash_t* hRec)
{
        char    *csTmp = NULL;

        /* EXEC SQL WHENEVER SQLERROR GOTO getintratobaiddtl_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

                /* varchar         hv_to_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_to_baid;

                /* varchar         hv_currency_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_currency_id;


                short           hv_return_value;

                /* varchar         v_provider_name[PD_CLIENT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_provider_name;

                /* varchar         v_baid_name[PD_BAID_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_baid_name;

                /* varchar         v_bank_name[PD_BANK_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

                /* varchar         v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

                /* varchar         v_owner_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_owner_name;

                /* varchar         v_country_id[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country_id;

                /* varchar         v_currency_id[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency_id;

                double          v_lien;
                double          v_intransit;
                double          v_account_balance;

                short           ind_provider_name = -1;
                short           ind_baid_name = -1;
                short           ind_bank_name = -1;
                short           ind_bank_acct_num = -1;
                short           ind_owner_name = -1;
                short           ind_country_id = -1;
                short           ind_currency_id = -1;
                short           ind_lien = -1;
                short           ind_intransit = -1;
                short           ind_account_balance = -1;

                SQL_CURSOR      c_cursor_getintratobaiddtl;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetIntraToBAIDDetails: Begin\n"));

// baid
	if (GetField_CString(hRec,"baid",&csTmp)) {
                hv_baid.len = strlen(csTmp);
                memcpy(hv_baid.arr, csTmp, hv_baid.len);
DEBUGLOG(("baid = [%.*s]\n", hv_baid.len, hv_baid.arr));
        }

// to_baid
	if (GetField_CString(hRec,"to_baid",&csTmp)) {
                hv_to_baid.len = strlen(csTmp);
                memcpy(hv_to_baid.arr, csTmp, hv_to_baid.len);
DEBUGLOG(("to_baid = [%.*s]\n", hv_to_baid.len, hv_to_baid.arr));
        }

// currency_id
	if (GetField_CString(hRec,"currency_id",&csTmp)) {
                hv_currency_id.len = strlen(csTmp);
                memcpy(hv_currency_id.arr, csTmp, hv_currency_id.len);
DEBUGLOG(("currency_id = [%.*s]\n", hv_currency_id.len, hv_currency_id.arr));
        }

	/* EXEC SQL ALLOCATE       :c_cursor_getintratobaiddtl; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1149;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getintratobaiddtl;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getintratobaiddtl_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                                :hv_return_value := sp_ol_get_intra_to_baid_dtl(:hv_baid,
                                                                                :hv_to_baid,
                                                                                :hv_currency_id,
                                                                                :c_cursor_getintratobaiddtl);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_get_intra_to_baid_dt\
l ( :hv_baid , :hv_to_baid , :hv_currency_id , :c_cursor_getintratobaiddtl ) \
; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1168;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_baid;
        sqlstm.sqhstl[1] = (unsigned long )22;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_to_baid;
        sqlstm.sqhstl[2] = (unsigned long )22;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_currency_id;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&c_cursor_getintratobaiddtl;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getintratobaiddtl_error;
}



DEBUGLOG((" hv_return_value = [%d]\n", hv_return_value));
        if (hv_return_value == SP_OK)
        {
                for (;;) {

                        ind_provider_name= -1;
                        ind_baid_name = -1;
                        ind_bank_name = -1;
                        ind_bank_acct_num = -1;
                        ind_owner_name = -1;
                        ind_country_id = -1;
                        ind_currency_id = -1;
                        ind_lien = -1;
                        ind_intransit = -1;
                        ind_account_balance = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_getintratobaiddtl

                        INTO
                                :v_provider_name:ind_provider_name,
                                :v_baid_name:ind_baid_name,
                                :v_bank_name:ind_bank_name,
                                :v_bank_acct_num:ind_bank_acct_num,
                                :v_owner_name:ind_owner_name,
                                :v_country_id:ind_country_id,
                                :v_currency_id:ind_currency_id,
                                :v_lien:ind_lien,
                                :v_intransit:ind_intransit,
                                :v_account_balance:ind_account_balance; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 17;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )1203;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getintratobaiddtl;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_provider_name;
                        sqlstm.sqhstl[1] = (unsigned long )53;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_provider_name;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_baid_name;
                        sqlstm.sqhstl[2] = (unsigned long )153;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_baid_name;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_bank_name;
                        sqlstm.sqhstl[3] = (unsigned long )153;
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_bank_name;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_bank_acct_num;
                        sqlstm.sqhstl[4] = (unsigned long )53;
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_bank_acct_num;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_owner_name;
                        sqlstm.sqhstl[5] = (unsigned long )53;
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_owner_name;
                        sqlstm.sqinds[5] = (         int  )0;
                        sqlstm.sqharm[5] = (unsigned long )0;
                        sqlstm.sqadto[5] = (unsigned short )0;
                        sqlstm.sqtdso[5] = (unsigned short )0;
                        sqlstm.sqhstv[6] = (unsigned char  *)&v_country_id;
                        sqlstm.sqhstl[6] = (unsigned long )5;
                        sqlstm.sqhsts[6] = (         int  )0;
                        sqlstm.sqindv[6] = (         short *)&ind_country_id;
                        sqlstm.sqinds[6] = (         int  )0;
                        sqlstm.sqharm[6] = (unsigned long )0;
                        sqlstm.sqadto[6] = (unsigned short )0;
                        sqlstm.sqtdso[6] = (unsigned short )0;
                        sqlstm.sqhstv[7] = (unsigned char  *)&v_currency_id;
                        sqlstm.sqhstl[7] = (unsigned long )6;
                        sqlstm.sqhsts[7] = (         int  )0;
                        sqlstm.sqindv[7] = (         short *)&ind_currency_id;
                        sqlstm.sqinds[7] = (         int  )0;
                        sqlstm.sqharm[7] = (unsigned long )0;
                        sqlstm.sqadto[7] = (unsigned short )0;
                        sqlstm.sqtdso[7] = (unsigned short )0;
                        sqlstm.sqhstv[8] = (unsigned char  *)&v_lien;
                        sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[8] = (         int  )0;
                        sqlstm.sqindv[8] = (         short *)&ind_lien;
                        sqlstm.sqinds[8] = (         int  )0;
                        sqlstm.sqharm[8] = (unsigned long )0;
                        sqlstm.sqadto[8] = (unsigned short )0;
                        sqlstm.sqtdso[8] = (unsigned short )0;
                        sqlstm.sqhstv[9] = (unsigned char  *)&v_intransit;
                        sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[9] = (         int  )0;
                        sqlstm.sqindv[9] = (         short *)&ind_intransit;
                        sqlstm.sqinds[9] = (         int  )0;
                        sqlstm.sqharm[9] = (unsigned long )0;
                        sqlstm.sqadto[9] = (unsigned short )0;
                        sqlstm.sqtdso[9] = (unsigned short )0;
                        sqlstm.sqhstv[10] = (unsigned char  *)&v_account_balance;
                        sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[10] = (         int  )0;
                        sqlstm.sqindv[10] = (         short *)&ind_account_balance;
                        sqlstm.sqinds[10] = (         int  )0;
                        sqlstm.sqharm[10] = (unsigned long )0;
                        sqlstm.sqadto[10] = (unsigned short )0;
                        sqlstm.sqtdso[10] = (unsigned short )0;
                        sqlstm.sqphsv = sqlstm.sqhstv;
                        sqlstm.sqphsl = sqlstm.sqhstl;
                        sqlstm.sqphss = sqlstm.sqhsts;
                        sqlstm.sqpind = sqlstm.sqindv;
                        sqlstm.sqpins = sqlstm.sqinds;
                        sqlstm.sqparm = sqlstm.sqharm;
                        sqlstm.sqparc = sqlstm.sqharc;
                        sqlstm.sqpadto = sqlstm.sqadto;
                        sqlstm.sqptdso = sqlstm.sqtdso;
                        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
                        if (sqlca.sqlcode == 1403) break;
                        if (sqlca.sqlcode < 0) goto getintratobaiddtl_error;
}



                        if (SQLCODE == SQL_NOT_FOUND) {
                                break;
                        }

/* provider_name */
                        if(ind_provider_name>=0){
                                v_provider_name.arr[v_provider_name.len]='\0';
                                PutField_CString(hRec,"provider_name",(const char*)v_provider_name.arr);
DEBUGLOG((" provider_name = [%s]\n",v_provider_name.arr));
                        }

/* baid_name */
                        if(ind_baid_name>=0){
                                v_baid_name.arr[v_baid_name.len]='\0';
                                PutField_CString(hRec,"baid_name",(const char*)v_baid_name.arr);
DEBUGLOG((" baid_name = [%s]\n",v_baid_name.arr));
                        }

/* bank_name */
                        if(ind_bank_name>=0){
                                v_bank_name.arr[v_bank_name.len]='\0';
                                PutField_CString(hRec,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG((" bank_name = [%s]\n",v_bank_name.arr));
                        }

/* bank_acct_num */
                        if(ind_bank_acct_num>=0){
                                v_bank_acct_num.arr[v_bank_acct_num.len]='\0';
                                PutField_CString(hRec,"bank_acct_num",(const char*)v_bank_acct_num.arr);
DEBUGLOG((" bank_acct_num = [%s]\n",v_bank_acct_num.arr));
                        }

/* owner_name */
                        if(ind_owner_name>=0){
                                v_owner_name.arr[v_owner_name.len]='\0';
                                PutField_CString(hRec,"owner_name",(const char*)v_owner_name.arr);
DEBUGLOG((" owner_name = [%s]\n",v_owner_name.arr));
                        }

/* country_id */
                        if(ind_country_id>=0){
                                v_country_id.arr[v_country_id.len]='\0';
                                PutField_CString(hRec,"country_id",(const char*)v_country_id.arr);
DEBUGLOG((" country_id = [%s]\n",v_country_id.arr));
                        }

/* currency_id */
                        if(ind_currency_id>=0){
                                v_currency_id.arr[v_currency_id.len]='\0';
                                PutField_CString(hRec,"currency_id",(const char*)v_currency_id.arr);
DEBUGLOG((" currency_id = [%s]\n",v_currency_id.arr));
                        }

/* lien */
                        if (ind_lien < 0){
                                v_lien = 0;
                        }
			PutField_Double(hRec, "lien", v_lien);
DEBUGLOG((" lien = [%f]\n", v_lien));

/* intransit */
                        if (ind_intransit<0){
                                v_intransit = 0;
                        }
			PutField_Double(hRec, "intransit", v_intransit);
DEBUGLOG((" intransit = [%f]\n", v_intransit));

/* account_balance */
                        if (ind_account_balance<0){
                                v_account_balance = 0;
                        }
                        PutField_Double(hRec, "account_balance", v_account_balance);
DEBUGLOG((" account_balance = [%f]\n", v_account_balance));
                }

DEBUGLOG(("GetIntraToBAIDDetails: Found\n"));
                return PD_FOUND;
        }
        else if (hv_return_value == SP_NOT_FOUND)
        {
DEBUGLOG(("GetIntraToBAIDDetails: Not Found\n"));
                return PD_NOT_FOUND;
        }
        else if (hv_return_value == SP_OTHER_ERR)
        {
DEBUGLOG(("GetIntraToBAIDDetails: SP_OTHER_ERR\n"));
ERRLOG("OLBankAcctId::GetIntraToBAIDDetails: SP_OTHER_ERR\n");
                return PD_OTHER_ERR;
        }
        else if (hv_return_value == SP_ERR)
        {
DEBUGLOG(("GetIntraToBAIDDetails: SP_ERR\n"));
ERRLOG("OLBankAcctId::GetIntraToBAIDDetails: SP_ERR\n");
                return PD_ERR;
        }

	/* EXEC SQL CLOSE :c_cursor_getintratobaiddtl; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1262;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getintratobaiddtl;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getintratobaiddtl_error;
}


        /* EXEC SQL FREE :c_cursor_getintratobaiddtl; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1281;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getintratobaiddtl;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getintratobaiddtl_error;
}



getintratobaiddtl_error:
DEBUGLOG(("getintratobaiddtl_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBankAcctId_Get: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE :c_cursor_getintratobaiddtl; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1300;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getintratobaiddtl;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        /* EXEC SQL FREE :c_cursor_getintratobaiddtl; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1319;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getintratobaiddtl;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int GetLastSMSCreationTime(const char* csBAID, const char* csRecDate, int iMaxBAIDCnt, recordset_t* myRec)
{
        int     iCnt = 0;
        hash_t  *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getlastsmscreatedt_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

                /* varchar         hv_rec_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_rec_date;

		int		hv_max_baid_cnt;		
		
                short           hv_return_value;

		/* varchar         v_baid[PD_BAID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_baid;

                /* varchar         v_create_dt[PD_DATETIME_LEN + 1 + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_create_dt;

		char         	v_rec_end_ind;

		short		ind_baid = -1;
                short           ind_create_dt = -1;
		short           ind_rec_end_ind = -1;

                SQL_CURSOR      c_cursor_getlastsmscreatedt;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetLastSMSCreationTime: Begin\n"));

	// baid
	if (csBAID != NULL) {
		hv_baid.len = strlen(csBAID);
        	memcpy(hv_baid.arr, csBAID, hv_baid.len);
DEBUGLOG(("baid = [%.*s]\n", hv_baid.len, hv_baid.arr));
	} else {
DEBUGLOG(("baid = NULL\n"));
	}

	// rec_date
	hv_rec_date.len = strlen(csRecDate);
        memcpy(hv_rec_date.arr, csRecDate, hv_rec_date.len);
DEBUGLOG(("rec_date = [%.*s]\n", hv_rec_date.len, hv_rec_date.arr));

	// max_baid_cnt
	hv_max_baid_cnt = iMaxBAIDCnt;
DEBUGLOG(("max_baid_cnt = [%d]\n", hv_max_baid_cnt));

        /* EXEC SQL ALLOCATE       :c_cursor_getlastsmscreatedt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1338;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getlastsmscreatedt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getlastsmscreatedt_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                                :hv_return_value := sp_ol_get_last_sms_create_dt(:hv_baid,
                                                                                 :hv_rec_date,
									         :hv_max_baid_cnt,
                                                                                 :c_cursor_getlastsmscreatedt);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_get_last_sms_create_\
dt ( :hv_baid , :hv_rec_date , :hv_max_baid_cnt , :c_cursor_getlastsmscreated\
t ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1357;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_baid;
        sqlstm.sqhstl[1] = (unsigned long )22;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_rec_date;
        sqlstm.sqhstl[2] = (unsigned long )10;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_max_baid_cnt;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&c_cursor_getlastsmscreatedt;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getlastsmscreatedt_error;
}



DEBUGLOG((" hv_return_value = [%d]\n", hv_return_value));
	if (hv_return_value == SP_OK)
        {
                for (;;) {
                        myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);

                        ind_baid = -1;
			ind_create_dt = -1;
			ind_rec_end_ind = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_getlastsmscreatedt

                        INTO
                                :v_baid:ind_baid,
				:v_create_dt:ind_create_dt,
				:v_rec_end_ind:ind_rec_end_ind; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 17;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )1392;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getlastsmscreatedt;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_baid;
                        sqlstm.sqhstl[1] = (unsigned long )23;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_baid;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_create_dt;
                        sqlstm.sqhstl[2] = (unsigned long )18;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_create_dt;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_rec_end_ind;
                        sqlstm.sqhstl[3] = (unsigned long )1;
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_rec_end_ind;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqphsv = sqlstm.sqhstv;
                        sqlstm.sqphsl = sqlstm.sqhstl;
                        sqlstm.sqphss = sqlstm.sqhsts;
                        sqlstm.sqpind = sqlstm.sqindv;
                        sqlstm.sqpins = sqlstm.sqinds;
                        sqlstm.sqparm = sqlstm.sqharm;
                        sqlstm.sqparc = sqlstm.sqharc;
                        sqlstm.sqpadto = sqlstm.sqadto;
                        sqlstm.sqptdso = sqlstm.sqtdso;
                        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
                        if (sqlca.sqlcode == 1403) break;
                        if (sqlca.sqlcode < 0) goto getlastsmscreatedt_error;
}



                        if (SQLCODE == SQL_NOT_FOUND) {
                                break;
                        }
/* baid */
                        if(ind_baid>=0){
                                v_baid.arr[v_baid.len]='\0';
                                PutField_CString(myHash,"baid",(const char*)v_baid.arr);
DEBUGLOG((" baid = [%s]\n",v_baid.arr));
                        }

/* create_dt */
                        if(ind_create_dt>=0){
                                v_create_dt.arr[v_create_dt.len]='\0';
                                PutField_CString(myHash,"create_dt",(const char*)v_create_dt.arr);
DEBUGLOG((" create_dt = [%s]\n",v_create_dt.arr));
                        }

/* rec_end_ind */
                        if(ind_rec_end_ind>=0){
                                PutField_Char(myHash,"rec_end_ind",v_rec_end_ind);
DEBUGLOG((" rec_end_ind = [%c]\n",v_rec_end_ind));
                        }

			RecordSet_Add(myRec,myHash);
                        iCnt++;
                }

DEBUGLOG(("GetLastSMSCreationTime: Found\n"));
                return PD_FOUND;
        }
	else if (hv_return_value == SP_NOT_FOUND)
        {
DEBUGLOG(("GetLastSMSCreationTime: Not Found\n"));
                return PD_NOT_FOUND;
        }
        else if (hv_return_value == SP_OTHER_ERR)
        {
DEBUGLOG(("GetLastSMSCreationTime: SP_OTHER_ERR\n"));
ERRLOG("OLBankAcctId::GetLastSMSCreationTime: SP_OTHER_ERR\n");
                return PD_OTHER_ERR;
        }
        else if (hv_return_value == SP_ERR)
        {
DEBUGLOG(("GetLastSMSCreationTime: SP_ERR\n"));
ERRLOG("OLBankAcctId::GetLastSMSCreationTime: SP_ERR\n");
                return PD_ERR;
        }

        /* EXEC SQL CLOSE :c_cursor_getlastsmscreatedt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1423;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getlastsmscreatedt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getlastsmscreatedt_error;
}


        /* EXEC SQL FREE :c_cursor_getlastsmscreatedt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1442;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getlastsmscreatedt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getlastsmscreatedt_error;
}



getlastsmscreatedt_error:
DEBUGLOG(("getlastsmscreatedt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBankAcctId_Get: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE :c_cursor_getlastsmscreatedt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1461;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getlastsmscreatedt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        /* EXEC SQL FREE :c_cursor_getlastsmscreatedt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1480;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getlastsmscreatedt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int GetAutoUploadStmtSettings(const char* csBAID, hash_t* hRec)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO getautouplstmtsett_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;


                short           hv_return_value;

                /* varchar         v_provider_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_provider_id;

                /* varchar         v_provider_status[PD_ACCOUNT_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_provider_status;

                /* varchar         v_bank_nature[PD_ACCT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_bank_nature;

		/* varchar         v_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_psp_id;

                /* varchar         v_pid_status[PD_ACCOUNT_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_pid_status;
	
		/* varchar         v_baid_status[PD_ACCOUNT_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_baid_status;

                /* varchar         v_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

                /* varchar         v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

                /* varchar         v_bank_acct_status[PD_ACCOUNT_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_bank_acct_status;

                int             v_bank_acct_sys_switch_enabled;
                /* varchar         v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		int		v_provider_disabled;
		int		v_bank_disabled;
		int		v_bank_acct_disabled;

                short           ind_provider_id = -1;
                short           ind_provider_status = -1;
		short           ind_bank_nature = -1;
		short 		ind_psp_id = -1;
                short           ind_pid_status = -1;
		short           ind_baid_status = -1;
                short           ind_bank_code = -1;
                short           ind_bank_acct_num = -1;
                short           ind_bank_acct_status = -1;
                short           ind_bank_acct_sys_switch_enabled = -1;
                short           ind_merchant_id = -1;
		short		ind_provider_disabled = -1;
		short		ind_bank_disabled = -1;
		short		ind_bank_acct_disabled = -1;

                SQL_CURSOR      c_cursor_getautouplstmtsett;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetAutoUploadStmtSettings: Begin\n"));

        // baid
        hv_baid.len = strlen(csBAID);
        memcpy(hv_baid.arr, csBAID, hv_baid.len);
DEBUGLOG(("baid = [%.*s]\n", hv_baid.len, hv_baid.arr));

        /* EXEC SQL ALLOCATE       :c_cursor_getautouplstmtsett; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1499;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getautouplstmtsett;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getautouplstmtsett_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                                :hv_return_value := sp_ol_get_auto_upl_stmt_sett(:hv_baid,
                                                                                 :c_cursor_getautouplstmtsett);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_get_auto_upl_stmt_se\
tt ( :hv_baid , :c_cursor_getautouplstmtsett ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1518;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_baid;
        sqlstm.sqhstl[1] = (unsigned long )22;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&c_cursor_getautouplstmtsett;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getautouplstmtsett_error;
}



DEBUGLOG((" hv_return_value = [%d]\n", hv_return_value));
        if (hv_return_value == SP_OK)
        {
                for (;;) {

                        ind_provider_id = -1;
                        ind_provider_status = -1;
			ind_bank_nature = -1;
			ind_psp_id = -1;
                        ind_pid_status = -1;
			ind_baid_status = -1;
                        ind_bank_code = -1;
                        ind_bank_acct_num = -1;
                        ind_bank_acct_sys_switch_enabled = -1;
               	        ind_merchant_id = -1;
			ind_provider_disabled = -1;
			ind_bank_disabled = -1;
			ind_bank_acct_disabled = -1;	

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_getautouplstmtsett

                        INTO
                                :v_provider_id:ind_provider_id,
                                :v_provider_status:ind_provider_status,
                                :v_bank_nature:ind_bank_nature,
				:v_psp_id:ind_psp_id,
				:v_pid_status:ind_pid_status,
				:v_baid_status:ind_baid_status,
                                :v_bank_code:ind_bank_code,
                                :v_bank_acct_num:ind_bank_acct_num,
                                :v_bank_acct_status:ind_bank_acct_status,
                                :v_bank_acct_sys_switch_enabled:ind_bank_acct_sys_switch_enabled,
                                :v_merchant_id:ind_merchant_id,
                                :v_provider_disabled:ind_provider_disabled,
                                :v_bank_disabled:ind_bank_disabled,
                                :v_bank_acct_disabled:ind_bank_acct_disabled; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 17;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )1545;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getautouplstmtsett;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_provider_id;
                        sqlstm.sqhstl[1] = (unsigned long )13;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_provider_id;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_provider_status;
                        sqlstm.sqhstl[2] = (unsigned long )5;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_provider_status;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_bank_nature;
                        sqlstm.sqhstl[3] = (unsigned long )6;
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_bank_nature;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_psp_id;
                        sqlstm.sqhstl[4] = (unsigned long )12;
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_psp_id;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_pid_status;
                        sqlstm.sqhstl[5] = (unsigned long )5;
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_pid_status;
                        sqlstm.sqinds[5] = (         int  )0;
                        sqlstm.sqharm[5] = (unsigned long )0;
                        sqlstm.sqadto[5] = (unsigned short )0;
                        sqlstm.sqtdso[5] = (unsigned short )0;
                        sqlstm.sqhstv[6] = (unsigned char  *)&v_baid_status;
                        sqlstm.sqhstl[6] = (unsigned long )5;
                        sqlstm.sqhsts[6] = (         int  )0;
                        sqlstm.sqindv[6] = (         short *)&ind_baid_status;
                        sqlstm.sqinds[6] = (         int  )0;
                        sqlstm.sqharm[6] = (unsigned long )0;
                        sqlstm.sqadto[6] = (unsigned short )0;
                        sqlstm.sqtdso[6] = (unsigned short )0;
                        sqlstm.sqhstv[7] = (unsigned char  *)&v_bank_code;
                        sqlstm.sqhstl[7] = (unsigned long )13;
                        sqlstm.sqhsts[7] = (         int  )0;
                        sqlstm.sqindv[7] = (         short *)&ind_bank_code;
                        sqlstm.sqinds[7] = (         int  )0;
                        sqlstm.sqharm[7] = (unsigned long )0;
                        sqlstm.sqadto[7] = (unsigned short )0;
                        sqlstm.sqtdso[7] = (unsigned short )0;
                        sqlstm.sqhstv[8] = (unsigned char  *)&v_bank_acct_num;
                        sqlstm.sqhstl[8] = (unsigned long )53;
                        sqlstm.sqhsts[8] = (         int  )0;
                        sqlstm.sqindv[8] = (         short *)&ind_bank_acct_num;
                        sqlstm.sqinds[8] = (         int  )0;
                        sqlstm.sqharm[8] = (unsigned long )0;
                        sqlstm.sqadto[8] = (unsigned short )0;
                        sqlstm.sqtdso[8] = (unsigned short )0;
                        sqlstm.sqhstv[9] = (unsigned char  *)&v_bank_acct_status;
                        sqlstm.sqhstl[9] = (unsigned long )5;
                        sqlstm.sqhsts[9] = (         int  )0;
                        sqlstm.sqindv[9] = (         short *)&ind_bank_acct_status;
                        sqlstm.sqinds[9] = (         int  )0;
                        sqlstm.sqharm[9] = (unsigned long )0;
                        sqlstm.sqadto[9] = (unsigned short )0;
                        sqlstm.sqtdso[9] = (unsigned short )0;
                        sqlstm.sqhstv[10] = (unsigned char  *)&v_bank_acct_sys_switch_enabled;
                        sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[10] = (         int  )0;
                        sqlstm.sqindv[10] = (         short *)&ind_bank_acct_sys_switch_enabled;
                        sqlstm.sqinds[10] = (         int  )0;
                        sqlstm.sqharm[10] = (unsigned long )0;
                        sqlstm.sqadto[10] = (unsigned short )0;
                        sqlstm.sqtdso[10] = (unsigned short )0;
                        sqlstm.sqhstv[11] = (unsigned char  *)&v_merchant_id;
                        sqlstm.sqhstl[11] = (unsigned long )18;
                        sqlstm.sqhsts[11] = (         int  )0;
                        sqlstm.sqindv[11] = (         short *)&ind_merchant_id;
                        sqlstm.sqinds[11] = (         int  )0;
                        sqlstm.sqharm[11] = (unsigned long )0;
                        sqlstm.sqadto[11] = (unsigned short )0;
                        sqlstm.sqtdso[11] = (unsigned short )0;
                        sqlstm.sqhstv[12] = (unsigned char  *)&v_provider_disabled;
                        sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[12] = (         int  )0;
                        sqlstm.sqindv[12] = (         short *)&ind_provider_disabled;
                        sqlstm.sqinds[12] = (         int  )0;
                        sqlstm.sqharm[12] = (unsigned long )0;
                        sqlstm.sqadto[12] = (unsigned short )0;
                        sqlstm.sqtdso[12] = (unsigned short )0;
                        sqlstm.sqhstv[13] = (unsigned char  *)&v_bank_disabled;
                        sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[13] = (         int  )0;
                        sqlstm.sqindv[13] = (         short *)&ind_bank_disabled;
                        sqlstm.sqinds[13] = (         int  )0;
                        sqlstm.sqharm[13] = (unsigned long )0;
                        sqlstm.sqadto[13] = (unsigned short )0;
                        sqlstm.sqtdso[13] = (unsigned short )0;
                        sqlstm.sqhstv[14] = (unsigned char  *)&v_bank_acct_disabled;
                        sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[14] = (         int  )0;
                        sqlstm.sqindv[14] = (         short *)&ind_bank_acct_disabled;
                        sqlstm.sqinds[14] = (         int  )0;
                        sqlstm.sqharm[14] = (unsigned long )0;
                        sqlstm.sqadto[14] = (unsigned short )0;
                        sqlstm.sqtdso[14] = (unsigned short )0;
                        sqlstm.sqphsv = sqlstm.sqhstv;
                        sqlstm.sqphsl = sqlstm.sqhstl;
                        sqlstm.sqphss = sqlstm.sqhsts;
                        sqlstm.sqpind = sqlstm.sqindv;
                        sqlstm.sqpins = sqlstm.sqinds;
                        sqlstm.sqparm = sqlstm.sqharm;
                        sqlstm.sqparc = sqlstm.sqharc;
                        sqlstm.sqpadto = sqlstm.sqadto;
                        sqlstm.sqptdso = sqlstm.sqtdso;
                        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
                        if (sqlca.sqlcode == 1403) break;
                        if (sqlca.sqlcode < 0) goto getautouplstmtsett_error;
}



                        if (SQLCODE == SQL_NOT_FOUND) {
                                break;
                        }

/* provider_id */
                        if(ind_provider_id>=0){
                                v_provider_id.arr[v_provider_id.len]='\0';
                                PutField_CString(hRec,"provider_id",(const char*)v_provider_id.arr);
DEBUGLOG((" provider_id = [%s]\n",v_provider_id.arr));
                        }

/* provider_status */
                        if(ind_provider_status>=0){
                                v_provider_status.arr[v_provider_status.len]='\0';
                                PutField_CString(hRec,"provider_status",(const char*)v_provider_status.arr);
DEBUGLOG((" provider_status = [%s]\n",v_provider_status.arr));
                        }

/* bank_nature */
                        if(ind_bank_nature>=0){
                                v_bank_nature.arr[v_bank_nature.len]='\0';
                                PutField_CString(hRec,"bank_nature",(const char*)v_bank_nature.arr);
DEBUGLOG((" bank_nature = [%s]\n",v_bank_nature.arr));
                        }

/* psp_id */
                        if(ind_psp_id>=0){
                                v_psp_id.arr[v_psp_id.len]='\0';
                                PutField_CString(hRec,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG((" psp_id = [%s]\n",v_psp_id.arr));
                        }

/* pid_status */
                        if(ind_pid_status>=0){
                                v_pid_status.arr[v_pid_status.len]='\0';
                                PutField_CString(hRec,"pid_status",(const char*)v_pid_status.arr);
DEBUGLOG((" pid_status = [%s]\n",v_pid_status.arr));
                        }

/* baid_status */
                        if(ind_baid_status>=0){
                                v_baid_status.arr[v_baid_status.len]='\0';
                                PutField_CString(hRec,"baid_status",(const char*)v_baid_status.arr);
DEBUGLOG((" baid_status = [%s]\n",v_baid_status.arr));
                        }

/* bank_code */
                        if(ind_bank_code>=0){
                                v_bank_code.arr[v_bank_code.len]='\0';
                                PutField_CString(hRec,"bank_code",(const char*)v_bank_code.arr);
DEBUGLOG((" bank_code = [%s]\n",v_bank_code.arr));
                        }

/* bank_acct_num */
                        if(ind_bank_acct_num>=0){
                                v_bank_acct_num.arr[v_bank_acct_num.len]='\0';
                                PutField_CString(hRec,"bank_acct_num",(const char*)v_bank_acct_num.arr);
DEBUGLOG((" bank_acct_num = [%s]\n",v_bank_acct_num.arr));
                        }

/* bank_acct_status */
                        if(ind_bank_acct_status>=0){
                                v_bank_acct_status.arr[v_bank_acct_status.len]='\0';
                                PutField_CString(hRec,"bank_acct_status",(const char*)v_bank_acct_status.arr);
DEBUGLOG((" bank_acct_status = [%s]\n",v_bank_acct_status.arr));
                        }

/* bank_acct_sys_switch_enabled */
                        if(ind_bank_acct_sys_switch_enabled>=0){
                                PutField_Int(hRec,"sys_switch_enabled", v_bank_acct_sys_switch_enabled);
DEBUGLOG((" bank_acct_sys_switch_enabled = [%d]\n", v_bank_acct_sys_switch_enabled));
                        }

/* merchant_id */
                        if(ind_merchant_id>=0){
                                v_merchant_id.arr[v_merchant_id.len]='\0';
                                PutField_CString(hRec,"merchant_id",(const char*)v_merchant_id.arr);
DEBUGLOG((" merchant_id = [%s]\n",v_merchant_id.arr));
                        }

/* provider_disabled */
                        if(ind_provider_disabled>=0){
                                PutField_Int(hRec,"provider_disabled", v_provider_disabled);
DEBUGLOG((" provider_disabled = [%d]\n", v_provider_disabled));
                        }

/* bank_disabled */
                        if(ind_bank_disabled>=0){
                                PutField_Int(hRec,"bank_disabled", v_bank_disabled);
DEBUGLOG((" bank_disabled = [%d]\n", v_bank_disabled));
                        }

/* bank_acct_disabled */
                        if(ind_bank_acct_disabled>=0){
                                PutField_Int(hRec,"bank_acct_disabled", v_bank_acct_disabled);
DEBUGLOG((" bank_acct_disabled = [%d]\n", v_bank_acct_disabled));
                        }

                }
DEBUGLOG(("GetAutoUploadStmtSettings: Found\n"));
                return PD_FOUND;
        }
        else if (hv_return_value == SP_NOT_FOUND)
        {
DEBUGLOG(("GetAutoUploadStmtSettings: Not Found\n"));
                return PD_NOT_FOUND;
        }
        else if (hv_return_value == SP_OTHER_ERR)
        {
DEBUGLOG(("GetAutoUploadStmtSettings: SP_OTHER_ERR\n"));
ERRLOG("OLBankAcctId::GetAutoUploadStmtSettings: SP_OTHER_ERR\n");
                return PD_OTHER_ERR;
        }
        else if (hv_return_value == SP_ERR)
        {
DEBUGLOG(("GetAutoUploadStmtSettings: SP_ERR\n"));
ERRLOG("OLBankAcctId::GetAutoUploadStmtSettings: SP_ERR\n");
                return PD_ERR;
        }

        /* EXEC SQL CLOSE :c_cursor_getautouplstmtsett; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1620;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getautouplstmtsett;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getautouplstmtsett_error;
}


        /* EXEC SQL FREE :c_cursor_getautouplstmtsett; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1639;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getautouplstmtsett;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getautouplstmtsett_error;
}



getautouplstmtsett_error:
DEBUGLOG(("getautouplstmtsett_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBankAcctId_Get: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE :c_cursor_getautouplstmtsett; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1658;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getautouplstmtsett;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        /* EXEC SQL FREE :c_cursor_getautouplstmtsett; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1677;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getautouplstmtsett;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int GetPayoutTempBAIDAcct(const char* csBAID)
{
	int iRet = NOT_FOUND;

        /* EXEC SQL WHENEVER SQLERROR GOTO getpotempbaidacct_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;
  

                int             v_cnt;
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetPayoutTempBAIDAcct: Begin\n"));

 	// baid
        hv_baid.len = strlen(csBAID);
        memcpy(hv_baid.arr, csBAID, hv_baid.len);
DEBUGLOG(("baid = [%.*s]\n", hv_baid.len, hv_baid.arr));

        /* EXEC SQL        SELECT  COUNT(*)
                        INTO    :v_cnt
                        FROM    ol_psp_detail,
				ol_bank_acct_id
			where   obai_baid = :hv_baid
			and     obai_status = 'O'
			and     opd_psp_id = obai_psp_id
                	and     opd_disabled = 0
                	and     opd_status = 'O'
                	and     obai_category = 'TEMP'
                	and     opd_bank_acct_type = 'POA'; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select COUNT ( * ) INTO :b0 FROM ol_psp_detail , ol_\
bank_acct_id where obai_baid = :b1 and obai_status = 'O' and opd_psp_id = oba\
i_psp_id and opd_disabled = 0 and opd_status = 'O' and obai_category = 'TEMP'\
 and opd_bank_acct_type = 'POA' ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1696;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_baid;
        sqlstm.sqhstl[1] = (unsigned long )22;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getpotempbaidacct_error;
}



        if (v_cnt > 0) {
DEBUGLOG(("cnt = [%d]\n", v_cnt));
                iRet = FOUND;
        }

DEBUGLOG(("GetPayoutTempBAIDAcct: iRet = [%d]\n", iRet));
        return iRet;

getpotempbaidacct_error:
DEBUGLOG(("getpotempbaidacct_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

