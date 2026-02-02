
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
    "PaySelection.pc"
};


static unsigned int sqlctx = 2523547;


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
   unsigned char  *sqhstv[12];
   unsigned long  sqhstl[12];
            int   sqhsts[12];
            short *sqindv[12];
            int   sqinds[12];
   unsigned long  sqharm[12];
   unsigned long  *sqharc[12];
   unsigned short  sqadto[12];
   unsigned short  sqtdso[12];
} sqlstm = {12,12};

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
5,0,0,1,387,0,6,172,0,0,12,12,0,1,0,2,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
68,0,0,2,0,0,17,275,0,0,1,1,0,1,0,1,9,0,0,
87,0,0,2,0,0,21,276,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2010/12/15              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "PaySelection.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void PaySelection(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const hash_t *hPaySelection)
{
	char		*csTmp;
	char		cTmp;
	int		iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int		hv_seq_num;
		/* varchar         hv_file_seq[PD_SEQ_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_file_seq;

		/* varchar         hv_merchant_ref[PD_MERCHANT_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_merchant_ref;

		/* varchar         hv_account_num[PD_AC_NO_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_account_num;

		/* varchar         hv_account_name[PD_ACC_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_account_name;

		/* varchar         hv_bank_name[PD_BANK_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_name;

		/* varchar         hv_branch[PD_BANK_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_branch;

		/* varchar         hv_province[PD_PROVINCE_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_province;

		/* varchar		hv_city[PD_CITY_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_city;

		/* varchar		hv_payout_currency[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_payout_currency;

		/* varchar		hv_amount[PD_AMOUNT_LEN]; */ 
struct { unsigned short len; unsigned char arr[12]; } hv_amount;

		char		hv_status;

		short           ind_file_seq = -1;
		short           ind_seq_num = -1;
		short           ind_merchant_ref = -1;
		short           ind_account_num = -1;
		short           ind_account_name = -1;
		short           ind_bank_name = -1;
		short		ind_branch = -1;
		short		ind_province = -1;
		short		ind_city = -1;
		short		ind_payout_currency = -1;
		short		ind_amount = -1;
		short		ind_status = -1;

		short           hv_return_value;
		/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

/*file_seq*/
	if(GetField_CString(hPaySelection,"file_seq",&csTmp)){
		hv_file_seq.len = strlen(csTmp);
		memcpy(hv_file_seq.arr, csTmp, hv_file_seq.len);
		ind_file_seq= 0;
DEBUGLOG(("Add:file_seq= [%.*s]\n",hv_file_seq.len,hv_file_seq.arr));
	}

/*seq_num*/
	if(GetField_Int(hPaySelection,"seq_num",&iTmp)){
		hv_seq_num = iTmp;
		ind_seq_num = 0;
DEBUGLOG(("Add:seq_num = [%d]\n",hv_seq_num));
	}


/*merchant ref no*/
	if(GetField_CString(hPaySelection,"merchant_ref",&csTmp)){
		hv_merchant_ref.len = strlen(csTmp);
		memcpy(hv_merchant_ref.arr, csTmp, hv_merchant_ref.len);
		ind_merchant_ref = 0;
DEBUGLOG(("Add:merchant_ref = [%.*s]\n",hv_merchant_ref.len,hv_merchant_ref.arr));
	}

/*account_num*/
	if(GetField_CString(hPaySelection,"account_num",&csTmp)){
		hv_account_num.len = strlen(csTmp);
		memcpy(hv_account_num.arr, csTmp, hv_account_num.len);
		ind_account_num = 0;
DEBUGLOG(("Add:account_num = [%.*s]\n",hv_account_num.len,hv_account_num.arr));
	}

/*account name*/
	if(GetField_CString(hPaySelection,"account_name",&csTmp)){
		hv_account_name.len = strlen(csTmp);
		memcpy(hv_account_name.arr, csTmp, hv_account_name.len);
		ind_account_name = 0;
DEBUGLOG(("Add:account_name = [%.*s]\n",hv_account_name.len,hv_account_name.arr));
	}

/*bank_name*/
	if(GetField_CString(hPaySelection,"bank_name",&csTmp)){
		hv_bank_name.len = strlen(csTmp);
		memcpy(hv_bank_name.arr, csTmp, hv_bank_name.len);
		ind_bank_name = 0;
DEBUGLOG(("Add:bank_name = [%.*s]\n",hv_bank_name.len,hv_bank_name.arr));
	}


/*branch*/
	if(GetField_CString(hPaySelection,"branch",&csTmp)){
		hv_branch.len = strlen(csTmp);
		memcpy(hv_branch.arr, csTmp, hv_branch.len);
		ind_branch = 0;
DEBUGLOG(("Add:branch = [%.*s]\n",hv_branch.len,hv_branch.arr));
	}


/*province*/
	if(GetField_CString(hPaySelection,"province",&csTmp)){
		hv_province.len = strlen(csTmp);
		memcpy(hv_province.arr, csTmp, hv_province.len);
		ind_province = 0;
DEBUGLOG(("Add:province = [%.*s]\n",hv_province.len,hv_province.arr));
	}

/*city*/
	if(GetField_CString(hPaySelection,"city",&csTmp)){
		hv_city.len = strlen(csTmp);
		memcpy(hv_city.arr, csTmp, hv_city.len);
		ind_city = 0;
DEBUGLOG(("Add:city = [%.*s]\n",hv_city.len,hv_city.arr));
	}

/*payout currency*/
	if(GetField_CString(hPaySelection,"payout_currency",&csTmp)){
		hv_payout_currency.len = strlen(csTmp);
		memcpy(hv_payout_currency.arr, csTmp, hv_payout_currency.len);
		ind_payout_currency = 0;
DEBUGLOG(("Add:payout_currency = [%.*s]\n",hv_payout_currency.len,hv_payout_currency.arr));
	}


/*amount*/
	if (GetField_CString(hPaySelection,"amount",&csTmp)) {
		hv_amount.len = strlen(csTmp);
		memcpy(hv_amount.arr, csTmp, hv_amount.len);
		ind_amount = 0;
DEBUGLOG(("Add:amount = [%.*s]\n",hv_amount.len,hv_amount.arr));
	}


/*status*/
	if(GetField_Char(hPaySelection,"status",&cTmp)){
		hv_status = cTmp;
		ind_status = 0;
DEBUGLOG(("Add:status= [%c]\n",hv_status));
	}

	FREE_ME(csTmp);
	
	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_pay_selection_insert(
					:hv_seq_num:ind_seq_num,
					:hv_file_seq:ind_file_seq,
					:hv_merchant_ref:ind_merchant_ref,
					:hv_account_num:ind_account_num,
					:hv_account_name:ind_account_name,
					:hv_bank_name:ind_bank_name,
					:hv_branch:ind_branch,
					:hv_amount:ind_amount,
					:hv_payout_currency:ind_payout_currency,
					:hv_province:ind_province,
					:hv_city:ind_city);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_pay_selection_insert ( :hv_seq\
_num:ind_seq_num , :hv_file_seq:ind_file_seq , :hv_merchant_ref:ind_merchant_\
ref , :hv_account_num:ind_account_num , :hv_account_name:ind_account_name , :\
hv_bank_name:ind_bank_name , :hv_branch:ind_branch , :hv_amount:ind_amount , \
:hv_payout_currency:ind_payout_currency , :hv_province:ind_province , :hv_cit\
y:ind_city ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_seq_num;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_seq_num;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_file_seq;
 sqlstm.sqhstl[2] = (unsigned long )8;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_file_seq;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_merchant_ref;
 sqlstm.sqhstl[3] = (unsigned long )52;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_merchant_ref;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_account_num;
 sqlstm.sqhstl[4] = (unsigned long )27;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_account_num;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_account_name;
 sqlstm.sqhstl[5] = (unsigned long )27;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_account_name;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_bank_name;
 sqlstm.sqhstl[6] = (unsigned long )52;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_bank_name;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_branch;
 sqlstm.sqhstl[7] = (unsigned long )52;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_branch;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_amount;
 sqlstm.sqhstl[8] = (unsigned long )14;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_amount;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_payout_currency;
 sqlstm.sqhstl[9] = (unsigned long )5;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_payout_currency;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_province;
 sqlstm.sqhstl[10] = (unsigned long )22;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_province;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_city;
 sqlstm.sqhstl[11] = (unsigned long )22;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_city;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
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



DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
		DEBUGLOG(("Add:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
		ERRLOG("PaySelection_Add: SP_OTHER_ERR TxnAbort\n");
		DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
		ERRLOG("PaySelection_Add: SP_ERR TxnAbort\n");
		DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		return PD_ERR; 
	}

add_error:
	DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
	DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;

}


int UpdateStatus(const hash_t *hRls)
{
	char*   csBuf;
	char*	csMerchRef;
	char*	csSeqNum;
	char*	csRespCode;
	char*	csRefNum;
	char	cStatus;

	/* EXEC SQL WHENEVER SQLERROR GOTO updatestatus_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar		hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("Update: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update pay_selection set ");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        
        GetField_CString(hRls,"merchant_ref",&csMerchRef);
DEBUGLOG(("Update:merchant_ref = [%s]\n",csMerchRef));
        
        GetField_CString(hRls,"seq_num",&csSeqNum);
DEBUGLOG(("Update:seq_num = [%s]\n",csSeqNum));

        
        if(GetField_Char(hRls,"status",&cStatus)){
DEBUGLOG(("Update: status = [%c]\n",cStatus));
                sprintf(csBuf,"%c",cStatus);
                strcat((char*)hv_dynstmt.arr, "status = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRls,"ref_num",&csRefNum)){
DEBUGLOG(("Update: ref_num = [%s]\n",csRefNum));
                strcat((char*)hv_dynstmt.arr, ", ref_num = '");
                strcat((char*)hv_dynstmt.arr, csRefNum);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        
        strcat((char*)hv_dynstmt.arr, " WHERE merchant_ref = '");
        strcat((char*)hv_dynstmt.arr, csMerchRef);
        strcat((char*)hv_dynstmt.arr, "' AND seq_num = '");
        strcat((char*)hv_dynstmt.arr, csSeqNum);
        strcat((char*)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )68;
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
 if (sqlca.sqlcode < 0) goto updatestatus_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )87;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto updatestatus_error;
}




DEBUGLOG(("UpdateStatus Normal Exit\n"));
        return PD_OK;

updatestatus_error:
DEBUGLOG(("updatestatus_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_INTERNAL_ERR;
}


