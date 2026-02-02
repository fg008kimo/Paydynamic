
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
           char  filnam[22];
};
static struct sqlcxp sqlfpn =
{
    21,
    "OLMerchantBankAcct.pc"
};


static unsigned int sqlctx = 161824395;


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
   unsigned char  *sqhstv[9];
   unsigned long  sqhstl[9];
            int   sqhsts[9];
            short *sqindv[9];
            int   sqinds[9];
   unsigned long  sqharm[9];
   unsigned long  *sqharc[9];
   unsigned short  sqadto[9];
   unsigned short  sqtdso[9];
} sqlstm = {12,9};

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
"select omb_merchant_id , omb_service_code , omb_status from ol_merchant_ban\
k_acct where omb_int_bank_code = :b0 and omb_bank_acct_num = :b1            ";

 static char *sq0004 = 
"SELECT ACCT_CCY , SERVICE_CODE , COUNTRY , SHARED_ACCT , OWNER_NAME , BRANC\
H_NAME FROM OL_DEPOSIT_BANK_ACCT_VIEW WHERE MERCHANT_ID = :b0 AND INT_BANK_CO\
DE = :b1 AND BANK_ACCT_NUM = :b2            ";

 static char *sq0005 = 
"select ob_int_bank_code , ob_bank_acct_num , ob_owner_name , ob_branch_name\
 from ol_bank_accts , def_bank , ol_merchant_bank_acct where omb_status = 'O'\
 and omb_merchant_id = :b0:b1 and omb_int_bank_code = :b2:b3 and omb_service_\
code = :b4:b5 and omb_disabled = 0 and omb_int_bank_code = db_int_bank_code a\
nd db_country = :b6:b7 and omb_int_bank_code = ob_int_bank_code and omb_bank_\
acct_num = ob_bank_acct_num and sp_ol_get_bank_acct_type ( ob_int_bank_code ,\
 ob_bank_acct_num ) = 'DSI' and ob_acct_ccy = :b8:b9 and sp_ol_get_allow_acti\
on ( ob_int_bank_code , ob_bank_acct_num , :b10 ) = 1 order by dbms_random . \
value            ";

 static char *sq0006 = 
"select ob_int_bank_code , ob_bank_acct_num , ob_owner_name , ob_branch_name\
 from ol_bank_accts , def_bank , ol_merchant_bank_acct where omb_status = 'O'\
 and omb_merchant_id = :b0:b1 and omb_service_code = :b2:b3 and omb_disabled \
= 0 and omb_int_bank_code = db_int_bank_code and db_country = :b4:b5 and omb_\
int_bank_code = ob_int_bank_code and omb_bank_acct_num = ob_bank_acct_num and\
 sp_ol_get_bank_acct_type ( ob_int_bank_code , ob_bank_acct_num ) = 'DSI' and\
 ob_acct_ccy = :b6:b7 and sp_ol_get_allow_action ( ob_int_bank_code , ob_bank\
_acct_num , :b8 ) = 1 order by dbms_random . value            ";

 static char *sq0007 = 
"SELECT omb_merchant_id , omb_service_code , ob_acct_ccy , country FROM ol_m\
erchant_bank_acct , ol_bank_accts , bank_desc WHERE omb_int_bank_code = :b0:b\
1 AND omb_bank_acct_num = :b2:b3 AND omb_disabled = 0 AND omb_status = 'O' AN\
D omb_int_bank_code = ob_int_bank_code AND omb_bank_acct_num = ob_bank_acct_n\
um AND ob_shared_acct = 0 AND ob_int_bank_code = internal_bank_code AND sp_ol\
_get_allow_action ( :b0:b5 , :b2:b7 , :b8:b9 ) = 1            ";

 static char *sq0008 = 
"select internal_bank_code , bank_name from bank_desc , ol_bank_accts , def_\
bank , ol_merchant_bank_acct where omb_status = 'O' and omb_merchant_id = :b0\
:b1 and omb_disabled = 0 and omb_bank_acct_num = :b2:b3 and omb_int_bank_code\
 = db_int_bank_code and db_country = :b4:b5 and omb_int_bank_code = ob_int_ba\
nk_code and omb_bank_acct_num = ob_bank_acct_num and sp_ol_get_bank_acct_type\
 ( ob_int_bank_code , ob_bank_acct_num ) = 'DSI' and sp_ol_get_allow_action (\
 ob_int_bank_code , ob_bank_acct_num , :b6 ) = 1 and ob_acct_ccy = :b7:b8 and\
 internal_bank_code = ob_int_bank_code            ";

 static char *sq0009 = 
"SELECT INT_BANK_CODE , SERVICE_CODE , COUNTRY FROM OL_DEPOSIT_BANK_ACCT_VIE\
W WHERE MERCHANT_ID = :b0:b1 AND BANK_ACCT_NUM = :b2:b3 AND ACCT_CCY = :b4:b5\
 AND ALLOW_ACTION = 1            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,324,0,6,136,0,0,9,9,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,1,0,0,1,3,
0,0,1,9,0,0,1,9,0,0,1,9,0,0,
56,0,0,2,0,0,17,276,0,0,1,1,0,1,0,1,9,0,0,
75,0,0,2,0,0,21,277,0,0,0,0,0,1,0,
90,0,0,3,151,0,9,337,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
113,0,0,3,0,0,13,339,0,0,3,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,
140,0,0,3,0,0,15,376,0,0,0,0,0,1,0,
155,0,0,3,0,0,15,392,0,0,0,0,0,1,0,
170,0,0,4,196,0,9,453,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
197,0,0,4,0,0,13,455,0,0,6,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,
0,0,
236,0,0,4,0,0,15,508,0,0,0,0,0,1,0,
251,0,0,4,0,0,15,523,0,0,0,0,0,1,0,
266,0,0,5,631,0,9,622,0,2049,6,6,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,
305,0,0,5,0,0,13,624,0,0,4,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
336,0,0,5,0,0,15,666,0,0,0,0,0,1,0,
351,0,0,5,0,0,15,681,0,0,0,0,0,1,0,
366,0,0,6,599,0,9,769,0,2049,5,5,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
401,0,0,6,0,0,13,771,0,0,4,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
432,0,0,6,0,0,15,814,0,0,0,0,0,1,0,
447,0,0,6,0,0,15,829,0,0,0,0,0,1,0,
462,0,0,7,445,0,9,887,0,2049,5,5,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
497,0,0,7,0,0,13,890,0,0,4,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
528,0,0,7,0,0,15,925,0,0,0,0,0,1,0,
543,0,0,7,0,0,15,935,0,0,0,0,0,1,0,
558,0,0,8,587,0,9,1147,0,2049,5,5,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,
593,0,0,8,0,0,13,1149,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
616,0,0,8,0,0,15,1174,0,0,0,0,0,1,0,
631,0,0,8,0,0,15,1191,0,0,0,0,0,1,0,
646,0,0,9,185,0,9,1252,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
673,0,0,9,0,0,13,1254,0,0,3,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,
700,0,0,9,0,0,15,1286,0,0,0,0,0,1,0,
715,0,0,9,0,0,15,1303,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2013. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/08/27              Virginia Yun
Add GetAvaDepositBankAccts,
    GetAvaDepositBankAcctsRandom		   2013/10/10              Virginia Yun
Add GetAllAvaDepositBankAccts                      2013/10/28              David Wong
Add FindDetailByAvaMerchBankAcct by view	   2013/11/11		   Stan Poon
Add GetBeneficiaryBank				   2013/11/12		   Virginia Yun
Modify GetAvaDepositBankAccts
       GetAvaDepositBankAcctsRandom                2014/09/02              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "OLMerchantBankAcct.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void OLMerchantBankAcct(char    cdebug)
{
        cDebug = cdebug;
}


int Add(const hash_t *hOLMerchantBankAcct)
{
	char *csTmp;
	int  iTmp;
	char cTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar		hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar		hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		char		hv_txn_type;
		int		hv_disabled;
		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar		hv_status[PD_ACCOUNT_STATUS_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_status;


		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_merchant_id = -1;
		short		ind_int_bank_code = -1;
		short		ind_bank_acct_num = -1;
		short		ind_txn_type = -1;
		short		ind_disabled = -1;
		short		ind_service_code = -1;
		short		ind_status = -1;
		short		ind_create_user = -1;

		short		hv_return_value;

	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("Add: Begin\n"));

	if(GetField_CString(hOLMerchantBankAcct,"merchant_id",&csTmp))
	{
		hv_merchant_id.len = strlen(csTmp);
		strncpy((char *)hv_merchant_id.arr, csTmp, hv_merchant_id.len);
		ind_merchant_id = 0;
DEBUGLOG(("Add:merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
	}

	if(GetField_CString(hOLMerchantBankAcct,"int_bank_code",&csTmp))
	{
		hv_int_bank_code.len = strlen(csTmp);
		strncpy((char *)hv_int_bank_code.arr, csTmp, hv_int_bank_code.len);
		ind_int_bank_code = 0;
DEBUGLOG(("Add:int_bank_code = [%.*s]\n",hv_int_bank_code.len,hv_int_bank_code.arr));
	}

	if(GetField_CString(hOLMerchantBankAcct,"bank_acct_num",&csTmp))
	{
		hv_bank_acct_num.len = strlen(csTmp);
		strncpy((char *)hv_bank_acct_num.arr, csTmp, hv_bank_acct_num.len);
		ind_bank_acct_num = 0;
DEBUGLOG(("Add:bank_acct_num = [%.*s]\n",hv_bank_acct_num.len,hv_bank_acct_num.arr));
	}

	if (GetField_Char(hOLMerchantBankAcct,"txn_type", &cTmp))
	{
		hv_txn_type = cTmp;
		ind_txn_type = 0;
DEBUGLOG(("Add:txn_type = [%c]\n",hv_txn_type));
	}

	if (GetField_Int(hOLMerchantBankAcct,"disabled", &iTmp))
	{
		hv_disabled = iTmp;
		ind_disabled = 0;
DEBUGLOG(("Add:disabled = [%d]\n",hv_disabled));
	}

	if (GetField_CString(hOLMerchantBankAcct, "service_code",&csTmp))
	{
		hv_service_code.len = strlen(csTmp);
		strncpy((char *)hv_service_code.arr, csTmp, hv_service_code.len);
		ind_service_code = 0;
DEBUGLOG(("Add:service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));
	}

	if (GetField_CString(hOLMerchantBankAcct, "status",&csTmp))
	{
		hv_status.len = strlen(csTmp);
		strncpy((char *)hv_status.arr, csTmp, hv_status.len);
		ind_status= 0;
DEBUGLOG(("Add:status = [%.*s]\n",hv_status.len,hv_status.arr));
	}

	if(GetField_CString(hOLMerchantBankAcct,"create_user",&csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char *)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));
	}

	/* EXEC SQL EXECUTE
		BEGIN

                :hv_return_value := sp_ol_merchant_bank_acct_ins(
                                :hv_merchant_id:ind_merchant_id,
                                :hv_int_bank_code:ind_int_bank_code,
                                :hv_bank_acct_num:ind_bank_acct_num,
                                :hv_txn_type:ind_txn_type,
                                :hv_disabled:ind_disabled,
                                :hv_service_code:ind_service_code,
                                :hv_status:ind_status, 
                                :hv_create_user:ind_create_user);
            END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_merchant_bank_acct_ins ( :h\
v_merchant_id:ind_merchant_id , :hv_int_bank_code:ind_int_bank_code , :hv_ban\
k_acct_num:ind_bank_acct_num , :hv_txn_type:ind_txn_type , :hv_disabled:ind_d\
isabled , :hv_service_code:ind_service_code , :hv_status:ind_status , :hv_cre\
ate_user:ind_create_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[2] = (unsigned long )12;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[3] = (unsigned long )52;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_bank_acct_num;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_type;
 sqlstm.sqhstl[4] = (unsigned long )1;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_txn_type;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_disabled;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[6] = (unsigned long )5;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_service_code;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[7] = (unsigned long )4;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_status;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[8] = (unsigned long )22;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_create_user;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
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
                ERRLOG("OLMerchantBankAcct_Add: SP_OTHER_ERR TxnAbort\n");
                DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
                ERRLOG("OLMerchantBankAcct_Add: SP_ERR TxnAbort\n");
                DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLMerchantBankAcct_Add: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int Update(const hash_t *hRls)
{
        char*     csTmp;
        char*     csBuf;
	char	  cTmp;

	char*     csMerchantId;
	//char*     csServiceCode;
	char*     csBankCode;
	char*     csAcctNum;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar        hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


        csBuf = (char *) malloc(128);

DEBUGLOG(("Update: Begin\n"));

        strcpy((char*)hv_dynstmt.arr,"update ol_merchant_bank_acct set omb_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        GetField_CString(hRls,"merchant_id",&csMerchantId);
DEBUGLOG(("Update: merchant_id = [%s]\n", csMerchantId));

        GetField_CString(hRls,"int_bank_code",&csBankCode);
DEBUGLOG(("Update: int_bank_code = [%s]\n", csBankCode));

        GetField_CString(hRls,"bank_acct_num",&csAcctNum);
DEBUGLOG(("Update: bank_acct_num = [%s]\n", csAcctNum));

/* service_code */
	if (GetField_CString(hRls,"service_code",&csTmp)) {
DEBUGLOG(("Update:service_code = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",omb_service_code = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*txn_type*/
        if (GetField_Char(hRls,"txn_type",&cTmp)) {
		sprintf(csBuf,"%c",cTmp);
DEBUGLOG(("Update:txn_type = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",omb_txn_type = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*status */
        if (GetField_CString(hRls,"status",&csTmp)) {
DEBUGLOG(("Update:status = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",omb_status = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*update_user*/
        if(GetField_CString(hRls,"update_user",&csTmp)){
DEBUGLOG(("Update:update_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",omb_update_user= '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        strcat((char *)hv_dynstmt.arr, " WHERE omb_merchant_id = '");
        strcat((char *)hv_dynstmt.arr, csMerchantId);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	/*
        strcat((char *)hv_dynstmt.arr, " AND omb_service_code = '");
        strcat((char *)hv_dynstmt.arr, csServiceCode);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	*/

        strcat((char *)hv_dynstmt.arr, " AND omb_int_bank_code= '");
        strcat((char *)hv_dynstmt.arr, csBankCode);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        strcat((char *)hv_dynstmt.arr, " AND omb_bank_acct_num= '");
        strcat((char *)hv_dynstmt.arr, csAcctNum);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )56;
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
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )75;
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

ERRLOG("MerantantBalAcct_Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;

}

int     FindDetailByBankAcct(const char* csBankCode,
                             const char* csAcctNum,
                             recordset_t* myRec)
{
	hash_t *myHash;
	int     iCnt = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO bybankacct_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar         hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;

		/* varchar         hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;


		/* varchar		v_merchant_id[PD_MERCHANT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar		v_service_code[PD_SERVICE_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		/* varchar		v_status[PD_ACCOUNT_STATUS_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_status;


		short		ind_merchant_id = -1;
		short		ind_service_code = -1;
		short		ind_status = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_bank_code.len = strlen(csBankCode);
	memcpy(hv_bank_code.arr, csBankCode, hv_bank_code.len);
DEBUGLOG(("FindDetailByBankAcct:int_bank_code = [%.*s]\n",hv_bank_code.len,hv_bank_code.arr));

	hv_bank_acct_num.len = strlen(csAcctNum);
	memcpy(hv_bank_acct_num.arr,csAcctNum, hv_bank_acct_num.len);
DEBUGLOG(("FindDetailByBankAcct:bank_acct_num = [%.*s]\n",hv_bank_acct_num.len,hv_bank_acct_num.arr));

	/* EXEC SQL DECLARE c_cursor_bybankacct CURSOR FOR
                select
			omb_merchant_id,
			omb_service_code,
			omb_status
		from	ol_merchant_bank_acct
		where	omb_int_bank_code = :hv_bank_code
		and	omb_bank_acct_num = :hv_bank_acct_num; */ 


	/* EXEC SQL OPEN c_cursor_bybankacct; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )90;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_bank_code;
 sqlstm.sqhstl[0] = (unsigned long )12;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[1] = (unsigned long )52;
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
 if (sqlca.sqlcode < 0) goto bybankacct_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_bybankacct
		INTO
			:v_merchant_id:ind_merchant_id,
			:v_service_code:ind_service_code,
			:v_status:ind_status; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )113;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_merchant_id;
  sqlstm.sqhstl[0] = (unsigned long )18;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_merchant_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_service_code;
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_service_code;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[2] = (unsigned long )5;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_status;
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
  if (sqlca.sqlcode < 0) goto bybankacct_error;
}




		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		iCnt++;
                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

		if (ind_merchant_id >= 0) {
                        v_merchant_id.arr[v_merchant_id.len] ='\0';
                        PutField_CString(myHash,"merchant_id",(const char*)v_merchant_id.arr);
DEBUGLOG(("FindDetailByBankAcct merchant_id = [%s]\n",v_merchant_id.arr));
                }

		if (ind_service_code >= 0) {
                        v_service_code.arr[v_service_code.len] ='\0';
                        PutField_CString(myHash,"service_code",(const char*)v_service_code.arr);
DEBUGLOG(("FindDetailByBankAcct service_code = [%s]\n",v_service_code.arr));
                }
	
		if (ind_status >= 0) {
			v_status.arr[v_status.len] ='\0';
                        PutField_CString(myHash,"status",(const char*)v_status.arr);
DEBUGLOG(("FindDetailByBankAcct status = [%s]\n",v_status.arr));
                }

		RecordSet_Add(myRec,myHash);

	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_bybankacct; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )140;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto bybankacct_error;
}




        if (iCnt > 0 ) {
DEBUGLOG(("FindDetailByBankAcct Normal Exit\n"));
                return  PD_OK;
        }
        else {
DEBUGLOG(("FindDetailByBankAcct Normal Exit, Not Found\n"));
                return PD_ERR;
        }

bybankacct_error:
DEBUGLOG(("bybankacct_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_bybankacct; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )155;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int     FindDetailByAvaMerchBankAcct(const char* csMerchantID,
				const char* csBankCode,
				const char* csAcctNum,
				hash_t* myHash)
{
	int	iRet = PD_OK;
	int	iCnt=0;

	/* EXEC SQL WHENEVER SQLERROR GOTO detailbyava_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar         hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;

		/* varchar         hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		/* varchar		v_acct_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_acct_ccy;

		/* varchar		v_service_code[PD_SERVICE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		/* varchar		v_country[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		int		v_shared_acct;
		/* varchar		v_owner_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_owner_name;

		/* varchar		v_branch_name[PD_BANK_BRANCH_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch_name;


		short		ind_acct_ccy = -1;
		short		ind_service_code = -1;
		short		ind_country = -1;
		short		ind_shared_acct = -1;
		short		ind_owner_name = -1;
		short		ind_branch_name = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_merchant_id.len = strlen(csMerchantID);
	memcpy(hv_merchant_id.arr, csMerchantID, hv_merchant_id.len);
DEBUGLOG(("FindDetailByAvaMerchBankAcct:int_merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	hv_bank_code.len = strlen(csBankCode);
	memcpy(hv_bank_code.arr, csBankCode, hv_bank_code.len);
DEBUGLOG(("FindDetailByAvaMerchBankAcct:int_bank_code = [%.*s]\n",hv_bank_code.len,hv_bank_code.arr));

	hv_bank_acct_num.len = strlen(csAcctNum);
	memcpy(hv_bank_acct_num.arr,csAcctNum, hv_bank_acct_num.len);
DEBUGLOG(("FindDetailByAvaMerchBankAcct:bank_acct_num = [%.*s]\n",hv_bank_acct_num.len,hv_bank_acct_num.arr));

        /* EXEC SQL DECLARE c_curser_getdtlavabankaccts CURSOR FOR
		SELECT	ACCT_CCY,
			SERVICE_CODE,
			COUNTRY,
			SHARED_ACCT,
			OWNER_NAME,
			BRANCH_NAME
		FROM	OL_DEPOSIT_BANK_ACCT_VIEW
		WHERE	MERCHANT_ID = :hv_merchant_id
		AND	INT_BANK_CODE = :hv_bank_code
		AND	BANK_ACCT_NUM = :hv_bank_acct_num; */ 


	/* EXEC SQL OPEN c_curser_getdtlavabankaccts; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0004;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )170;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[0] = (unsigned long )17;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_code;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[2] = (unsigned long )52;
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
 if (sqlca.sqlcode < 0) goto detailbyava_error;
}


	do {
		/* EXEC SQL FETCH c_curser_getdtlavabankaccts
		INTO	:v_acct_ccy:ind_acct_ccy,
			:v_service_code:ind_service_code,
			:v_country:ind_country,
			:v_shared_acct:ind_shared_acct,
			:v_owner_name:ind_owner_name,
			:v_branch_name:ind_branch_name; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )197;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_acct_ccy;
  sqlstm.sqhstl[0] = (unsigned long )6;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_acct_ccy;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_service_code;
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_service_code;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_country;
  sqlstm.sqhstl[2] = (unsigned long )5;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_country;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_shared_acct;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_shared_acct;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_owner_name;
  sqlstm.sqhstl[4] = (unsigned long )53;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_owner_name;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_branch_name;
  sqlstm.sqhstl[5] = (unsigned long )153;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_branch_name;
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
  if (sqlca.sqlcode < 0) goto detailbyava_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

		if (ind_acct_ccy >= 0) {
			v_acct_ccy.arr[v_acct_ccy.len] ='\0';
			PutField_CString(myHash,"acct_ccy",(const char*)v_acct_ccy.arr);
DEBUGLOG(("FindDetailByAvaMerchBankAcct acct_ccy = [%s]\n",v_acct_ccy.arr));
		}

		if (ind_service_code >= 0) {
			v_service_code.arr[v_service_code.len] ='\0';
			PutField_CString(myHash,"service_code",(const char*)v_service_code.arr);
DEBUGLOG(("FindDetailByAvaMerchBankAcct service_code = [%s]\n",v_service_code.arr));
		}

		if (ind_country >= 0) {
			v_country.arr[v_country.len] ='\0';
			PutField_CString(myHash,"country",(const char*)v_country.arr);
DEBUGLOG(("FindDetailByAvaMerchBankAcct country = [%s]\n",v_country.arr));
		}

		if (ind_shared_acct >= 0) {
			PutField_Int(myHash,"shared_acct",v_shared_acct);
DEBUGLOG(("FindDetailByAvaMerchBankAcct shared_acct = [%d]\n",v_shared_acct));
		}

		if (ind_owner_name >= 0) {
			v_owner_name.arr[v_owner_name.len] ='\0';
			PutField_CString(myHash,"owner_name",(const char*)v_owner_name.arr);
DEBUGLOG(("FindDetailByAvaMerchBankAcct owner_name = [%s]\n",v_owner_name.arr));
		}

		if (ind_branch_name >= 0) {
			v_branch_name.arr[v_branch_name.len] ='\0';
			PutField_CString(myHash,"branch_name",(const char*)v_branch_name.arr);
DEBUGLOG(("FindDetailByAvaMerchBankAcct branch_name = [%s]\n",v_branch_name.arr));
		}

		break; // Only Return 1 record
        }
        while (PD_TRUE);

        /* EXEC SQL CLOSE c_curser_getdtlavabankaccts; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )236;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto detailbyava_error;
}



	if (iCnt > 0 ) {
                iRet = PD_OK;
DEBUGLOG(("FindDetailByAvaMerchBankAcct Normal Exit\n"));
        } else {
		iRet = PD_ERR;
DEBUGLOG(("FindDetailByAvaMerchBankAcct NOT FOUND!!!\n"));
        }
	return iRet;

detailbyava_error:
DEBUGLOG(("detailbyava_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_curser_getdtlavabankaccts; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )251;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}


int     GetAvaDepositBankAccts(const char* csMerchantId,
                                const char* csBankCode,
                                const char* csCountry,
                                const char* csCcy,
				const char* csServiceCode,
				const char* csAction,
                                hash_t *hRec)
{
	int	iRet = PD_ERR;

	int	iCnt = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO getbankaccts_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar	hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

		/* varchar	hv_acct_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_acct_ccy;

		/* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar hv_action[PD_ACCT_ACTION_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_action;


		/* varchar v_out_int_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_out_int_bank_code;

                /* varchar v_out_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_out_bank_acct_num;

		/* varchar v_branch_name[PD_BANK_BRANCH_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch_name;

		/* varchar	v_owner_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_owner_name;


		short	ind_merchant_id = -1;
		short	ind_int_bank_code = -1;
		short	ind_country = -1;
		short	ind_acct_ccy = -1;
		short	ind_service_code = -1;
		short	ind_action = -1;

		short	ind_out_int_bank_code = -1;
		short	ind_out_bank_acct_num = -1;
		short   ind_branch_name = -1;
		short	ind_owner_name = -1;
	
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetAvaDepositBankAccts: Begin\n"));

	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
DEBUGLOG(("GetAvaDepositBankAccts:merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
	ind_merchant_id = 0;

	hv_int_bank_code.len = strlen(csBankCode);
	memcpy(hv_int_bank_code.arr, csBankCode, hv_int_bank_code.len);
DEBUGLOG(("GetAvaDepositBankAccts:int_bank_code = [%.*s]\n",hv_int_bank_code.len,hv_int_bank_code.arr));
	ind_int_bank_code = 0;

	hv_country.len = strlen(csCountry);
	memcpy(hv_country.arr, csCountry, hv_country.len);
DEBUGLOG(("GetAvaDepositBankAccts:country = [%.*s]\n",hv_country.len,hv_country.arr));
	ind_country = 0;

	hv_acct_ccy.len = strlen(csCcy);
	memcpy(hv_acct_ccy.arr, csCcy, hv_acct_ccy.len);
DEBUGLOG(("GetAvaDepositBankAccts:acct_ccy = [%.*s]\n",hv_acct_ccy.len,hv_acct_ccy.arr));
	ind_acct_ccy = 0;

	hv_service_code.len = strlen(csServiceCode);
	memcpy(hv_service_code.arr, csServiceCode, hv_service_code.len);
DEBUGLOG(("GetAvaDepositBankAccts:service_code = [%.*s]\n", hv_service_code.len, hv_service_code.arr));
	ind_service_code = 0;

	hv_action.len = strlen(csAction);
	memcpy(hv_action.arr, csAction, hv_action.len);
DEBUGLOG(("GetAvaDepositBankAccts:action= [%.*s]\n", hv_action.len, hv_action.arr));
	ind_action = 0;

	

        /* EXEC SQL DECLARE c_cursor_getbankaccts CURSOR FOR
		select ob_int_bank_code, ob_bank_acct_num,ob_owner_name,ob_branch_name
		from ol_bank_accts, def_bank, ol_merchant_bank_acct
		where omb_status = 'O'
		and omb_merchant_id = :hv_merchant_id:ind_merchant_id
		and omb_int_bank_code = :hv_int_bank_code:ind_int_bank_code
		and omb_service_code = :hv_service_code:ind_service_code
		and omb_disabled = 0
		and omb_int_bank_code = db_int_bank_code
		and db_country = :hv_country:ind_country
		and omb_int_bank_code = ob_int_bank_code
		and omb_bank_acct_num = ob_bank_acct_num
		and sp_ol_get_bank_acct_type(ob_int_bank_code, ob_bank_acct_num) = 'DSI'
		/oand ob_status_type = 'A'o/
		and ob_acct_ccy = :hv_acct_ccy:ind_acct_ccy
		and sp_ol_get_allow_action(ob_int_bank_code, ob_bank_acct_num, :hv_action) = 1
		order by dbms_random.value; */ 


	/* EXEC SQL OPEN c_cursor_getbankaccts; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0005;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )266;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[0] = (unsigned long )17;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_service_code;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_country;
 sqlstm.sqhstl[3] = (unsigned long )4;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_country;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_acct_ccy;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_acct_ccy;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_action;
 sqlstm.sqhstl[5] = (unsigned long )22;
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
 if (sqlca.sqlcode < 0) goto getbankaccts_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getbankaccts
		INTO 
			:v_out_int_bank_code:ind_out_int_bank_code,
			:v_out_bank_acct_num:ind_out_bank_acct_num,
			:v_owner_name:ind_owner_name,
			:v_branch_name:ind_branch_name; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )305;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_out_int_bank_code;
  sqlstm.sqhstl[0] = (unsigned long )13;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_out_int_bank_code;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_out_bank_acct_num;
  sqlstm.sqhstl[1] = (unsigned long )53;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_out_bank_acct_num;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_owner_name;
  sqlstm.sqhstl[2] = (unsigned long )53;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_owner_name;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_branch_name;
  sqlstm.sqhstl[3] = (unsigned long )153;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_branch_name;
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
  if (sqlca.sqlcode < 0) goto getbankaccts_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;



                if (ind_out_int_bank_code >= 0) {
			v_out_int_bank_code.arr[v_out_int_bank_code.len] = '\0';
			PutField_CString(hRec, "int_bank_code", (const char*)v_out_int_bank_code.arr);
DEBUGLOG(("GetAvaDepositBankAccts: int_bank_code = [%s]\n", v_out_int_bank_code.arr));
		}

		if (ind_out_bank_acct_num >= 0) {
			v_out_bank_acct_num.arr[v_out_bank_acct_num.len] = '\0';
			PutField_CString(hRec, "bank_acct_num", (const char*)v_out_bank_acct_num.arr);
DEBUGLOG(("GetAvaDepositBankAccts: bank_acct_num = [%s]\n", v_out_bank_acct_num.arr));
		}

		if (ind_owner_name >= 0) {
			v_owner_name.arr[v_owner_name.len] = '\0';
			PutField_CString(hRec, "owner_name", (const char*)v_owner_name.arr);
DEBUGLOG(("GetAvaDepositBankAccts: owner_name = [%s]\n", v_owner_name.arr));
		}
		if (ind_branch_name >= 0) {
                        v_branch_name.arr[v_branch_name.len] = '\0';
                        PutField_CString(hRec, "branch_name", (const char*)v_branch_name.arr);
DEBUGLOG(("GetAvaDepositBankAccts: branch_name = [%s]\n", v_branch_name.arr));
                }

		break; // Only Return 1 record
        }
        while (PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getbankaccts; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )336;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getbankaccts_error;
}



	if (iCnt > 0 ) {
DEBUGLOG(("GetAvaDepositBankAccts Normal Exit\n"));
                iRet = PD_OK;
        } else {
DEBUGLOG(("GetAvaDepositBankAccts Normal Exit, Not Found\n"));
        }

	return iRet;

getbankaccts_error:
DEBUGLOG(("getbankaccts_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getbankaccts; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )351;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int     GetAvaDepositBankAcctsRandom(const char* csMerchantId,
                                const char* csCountry,
                                const char* csCcy,
				const char* csServiceCode,
				const char* csAction,
                                hash_t *hRec)
{
	int	iRet = PD_ERR;

	hash_t *myHash;
	int	iCnt = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO getbankacctsrandom_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

		/* varchar	hv_acct_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_acct_ccy;

		/* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar hv_action[PD_ACCT_ACTION_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_action;


		/* varchar v_out_int_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_out_int_bank_code;

                /* varchar v_out_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_out_bank_acct_num;

		/* varchar	v_branch_name[PD_BANK_BRANCH_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch_name;

		/* varchar	v_owner_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_owner_name;


		short	ind_merchant_id = -1;
		short	ind_country = -1;
		short	ind_acct_ccy = -1;
		short	ind_service_code = -1;
		short	ind_action = -1;

		short	ind_out_int_bank_code = -1;
		short	ind_out_bank_acct_num = -1;
		short	ind_branch_name = -1;
		short	ind_owner_name = -1;
	
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetAvaDepositBankAcctsRandom: Begin\n"));

	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
DEBUGLOG(("GetAvaDepositBankAcctsRandom:merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
	ind_merchant_id = 0;

	hv_country.len = strlen(csCountry);
	memcpy(hv_country.arr, csCountry, hv_country.len);
DEBUGLOG(("GetAvaDepositBankAcctsRandom:country = [%.*s]\n",hv_country.len,hv_country.arr));
	ind_country = 0;

	hv_acct_ccy.len = strlen(csCcy);
	memcpy(hv_acct_ccy.arr, csCcy, hv_acct_ccy.len);
DEBUGLOG(("GetAvaDepositBankAcctsRandom:acct_ccy = [%.*s]\n",hv_acct_ccy.len,hv_acct_ccy.arr));
	ind_acct_ccy = 0;

	hv_service_code.len = strlen(csServiceCode);
	memcpy(hv_service_code.arr, csServiceCode, hv_service_code.len);
DEBUGLOG(("GetAvaDepositBankAcctsRandom:service_code = [%.*s]\n", hv_service_code.len, hv_service_code.arr));
	ind_service_code = 0;

	hv_action.len = strlen(csAction);
        memcpy(hv_action.arr, csAction, hv_action.len);
DEBUGLOG(("GetAvaDepositBankAcctsRandom: action= [%.*s]\n",hv_action.len,hv_action.arr));
        ind_action = 0;

        /* EXEC SQL DECLARE c_cursor_getbankacctsrandom CURSOR FOR
		select ob_int_bank_code, ob_bank_acct_num,ob_owner_name,ob_branch_name
		from ol_bank_accts, def_bank, ol_merchant_bank_acct
		where omb_status = 'O'
		and omb_merchant_id = :hv_merchant_id:ind_merchant_id
		and omb_service_code = :hv_service_code:ind_service_code
		and omb_disabled = 0
		and omb_int_bank_code = db_int_bank_code
		and db_country = :hv_country:ind_country
		and omb_int_bank_code = ob_int_bank_code
		and omb_bank_acct_num = ob_bank_acct_num
		and sp_ol_get_bank_acct_type(ob_int_bank_code, ob_bank_acct_num) = 'DSI'
		/oand ob_status_type = 'A'o/
		and ob_acct_ccy = :hv_acct_ccy:ind_acct_ccy
		and sp_ol_get_allow_action(ob_int_bank_code, ob_bank_acct_num, :hv_action) = 1
		order by dbms_random.value; */ 


	/* EXEC SQL OPEN c_cursor_getbankacctsrandom; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0006;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )366;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[0] = (unsigned long )17;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_service_code;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_country;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_country;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_acct_ccy;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_acct_ccy;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_action;
 sqlstm.sqhstl[4] = (unsigned long )22;
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
 if (sqlca.sqlcode < 0) goto getbankacctsrandom_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getbankacctsrandom
		INTO 
			:v_out_int_bank_code:ind_out_int_bank_code,
			:v_out_bank_acct_num:ind_out_bank_acct_num,
			:v_owner_name:ind_owner_name,
			:v_branch_name:ind_branch_name; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )401;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_out_int_bank_code;
  sqlstm.sqhstl[0] = (unsigned long )13;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_out_int_bank_code;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_out_bank_acct_num;
  sqlstm.sqhstl[1] = (unsigned long )53;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_out_bank_acct_num;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_owner_name;
  sqlstm.sqhstl[2] = (unsigned long )53;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_owner_name;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_branch_name;
  sqlstm.sqhstl[3] = (unsigned long )153;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_branch_name;
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
  if (sqlca.sqlcode < 0) goto getbankacctsrandom_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);


                if (ind_out_int_bank_code >= 0) {
			v_out_int_bank_code.arr[v_out_int_bank_code.len] = '\0';
			PutField_CString(hRec, "int_bank_code", (const char*)v_out_int_bank_code.arr);
DEBUGLOG(("GetAvaDepositBankAcctsRandom: int_bank_code = [%s]\n", v_out_int_bank_code.arr));
		}

		if (ind_out_bank_acct_num >= 0) {
			v_out_bank_acct_num.arr[v_out_bank_acct_num.len] = '\0';
			PutField_CString(hRec, "bank_acct_num", (const char*)v_out_bank_acct_num.arr);
DEBUGLOG(("GetAvaDepositBankAcctsRandom: bank_acct_num = [%s]\n", v_out_bank_acct_num.arr));
		}

		if (ind_owner_name >= 0) {
			v_owner_name.arr[v_owner_name.len] = '\0';
			PutField_CString(hRec, "owner_name", (const char*)v_owner_name.arr);
DEBUGLOG(("GetAvaDepositBankAcctsRandom: owner_name = [%s]\n", v_owner_name.arr));
		}
		if (ind_branch_name >= 0) {
			v_branch_name.arr[v_branch_name.len] = '\0';
			PutField_CString(hRec, "branch_name", (const char*)v_branch_name.arr);
DEBUGLOG(("GetAvaDepositBankAcctsRandom: branch_name = [%s]\n", v_branch_name.arr));
		}
		break; // Only Return 1 record
        }
        while (PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getbankacctsrandom; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )432;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getbankacctsrandom_error;
}



	if (iCnt > 0 ) {
DEBUGLOG(("GetAvaDepositBankAcctsRandom Normal Exit\n"));
                iRet = PD_OK;
        } else {
DEBUGLOG(("GetAvaDepositBankAcctsRandom Normal Exit, Not Found\n"));
        }

	return iRet;

getbankacctsrandom_error:
DEBUGLOG(("getbankacctsrandom_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getbankacctsrandom; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )447;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int GetMerchBankAcctDtl(const char* csIntBankCode, const char* csBankAcctNum, const char* csAction, hash_t* hBankAcctDtl)
{
	int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO getmerchbankacctdtl_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		/* varchar hv_action[PD_ACCT_ACTION_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_action;

		/* varchar v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar v_service_code[PD_SERVICE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		/* varchar v_acct_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_acct_ccy;

		/* varchar v_country[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;


		short ind_int_bank_code = -1;
		short ind_bank_acct_num = -1;
		short ind_action = -1;
		short ind_merchant_id = -1;
		short ind_service_code = -1;
		short ind_acct_ccy = -1;
		short ind_country = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_int_bank_code.len = strlen(csIntBankCode);
	memcpy(hv_int_bank_code.arr, csIntBankCode, hv_int_bank_code.len);
	ind_int_bank_code = 0;
DEBUGLOG(("GetMerchBankAcctDtl int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));

	hv_bank_acct_num.len = strlen(csBankAcctNum);
	memcpy(hv_bank_acct_num.arr, csBankAcctNum, hv_bank_acct_num.len);
	ind_bank_acct_num = 0;
DEBUGLOG(("GetMerchBankAcctDtl bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));

	hv_action.len = strlen(csAction);
	memcpy(hv_action.arr, csAction, hv_action.len);
	ind_action = 0;
DEBUGLOG(("GetMerchBankAcctDtl action = [%.*s]\n", hv_action.len, hv_action.arr));

	/* EXEC SQL DECLARE c_cursor_getmerchbankacctdtl CURSOR FOR
		SELECT	omb_merchant_id, omb_service_code, ob_acct_ccy, country
		FROM	ol_merchant_bank_acct, ol_bank_accts, bank_desc
		WHERE	omb_int_bank_code = :hv_int_bank_code:ind_int_bank_code
		AND	omb_bank_acct_num = :hv_bank_acct_num:ind_bank_acct_num
		AND	omb_disabled = 0
		AND	omb_status = 'O'
		AND	omb_int_bank_code = ob_int_bank_code
		AND	omb_bank_acct_num = ob_bank_acct_num
		AND	ob_shared_acct = 0
		AND	ob_int_bank_code = internal_bank_code
		AND	sp_ol_get_allow_action(:hv_int_bank_code:ind_int_bank_code, :hv_bank_acct_num:ind_bank_acct_num, :hv_action:ind_action) = 1; */ 


	/* EXEC SQL OPEN c_cursor_getmerchbankacctdtl; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0007;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )462;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[0] = (unsigned long )12;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[1] = (unsigned long )52;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_bank_acct_num;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[2] = (unsigned long )12;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[3] = (unsigned long )52;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_bank_acct_num;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_action;
 sqlstm.sqhstl[4] = (unsigned long )22;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_action;
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
 if (sqlca.sqlcode < 0) goto getmerchbankacctdtl_error;
}



	for (;;) {
		/* EXEC SQL FETCH c_cursor_getmerchbankacctdtl
		INTO	:v_merchant_id:ind_merchant_id,
			:v_service_code:ind_service_code,
			:v_acct_ccy:ind_acct_ccy,
			:v_country:ind_country; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )497;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_merchant_id;
  sqlstm.sqhstl[0] = (unsigned long )18;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_merchant_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_service_code;
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_service_code;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_acct_ccy;
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_acct_ccy;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_country;
  sqlstm.sqhstl[3] = (unsigned long )5;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_country;
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
  if (sqlca.sqlcode < 0) goto getmerchbankacctdtl_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		if (ind_merchant_id >= 0) {
			v_merchant_id.arr[v_merchant_id.len] = '\0';
			PutField_CString(hBankAcctDtl, "merchant_id", (const char*)v_merchant_id.arr);
DEBUGLOG(("GetMerchBankAcctDtl merchant_id = [%s]\n", (const char*)v_merchant_id.arr));
		}

		if (ind_service_code >= 0) {
			v_service_code.arr[v_service_code.len] = '\0';
			PutField_CString(hBankAcctDtl, "service_code", (const char*)v_service_code.arr);
DEBUGLOG(("GetMerchBankAcctDtl service_code = [%s]\n", (const char*)v_service_code.arr));
		}

		if (ind_acct_ccy >= 0) {
			v_acct_ccy.arr[v_acct_ccy.len] = '\0';
			PutField_CString(hBankAcctDtl, "acct_ccy", (const char*)v_acct_ccy.arr);
DEBUGLOG(("GetMerchBankAcctDtl acct_ccy = [%s]\n", (const char*)v_acct_ccy.arr));
		}

		if (ind_country >= 0) {
			v_country.arr[v_country.len] = '\0';
			PutField_CString(hBankAcctDtl, "country", (const char*)v_country.arr);
DEBUGLOG(("GetMerchBankAcctDtl country = [%s]\n", (const char*)v_country.arr));
		}
	}

	/* EXEC SQL CLOSE c_cursor_getmerchbankacctdtl; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )528;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getmerchbankacctdtl_error;
}



DEBUGLOG(("GetMerchBankAcctDtl Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getmerchbankacctdtl_error:
DEBUGLOG(("getmerchbankacctdtl_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLMerchantBankAcct getmerchbankacctdtl_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL CLOSE c_cursor_getmerchbankacctdtl; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )543;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getmerchbankacctdtl_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


/*
int GetAllAvaDepositBankAccts(const char* csMerchantId, recordset_t* myRec)
{
	int iRet = PD_OK;
	int iCnt = 0;

	hash_t *myHash;

	EXEC SQL WHENEVER SQLERROR GOTO getallavadepositbankaccts_error;
	EXEC SQL WHENEVER NOTFOUND CONTINUE;

	EXEC SQL BEGIN DECLARE SECTION;
		varchar hv_merchant_id[PD_MERCHANT_ID_LEN];

		varchar	v_int_bank_code[PD_BANK_CODE_LEN + 1];
		varchar	v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1];
		varchar v_service_code[PD_SERVICE_CODE_LEN + 1];
		varchar	v_country[PD_COUNTRY_LEN + 1];
		int	v_min_settle_amt;
		double	v_min_settle_amt_applyadmin;

		short ind_merchant_id = -1;

		short ind_int_bank_code = -1;
		short ind_bank_acct_num = -1;
		short ind_service_code = -1;
		short ind_country = -1;
		short ind_min_settle_amt = -1;
		short ind_min_settle_amt_applyadmin = -1;
	EXEC SQL END DECLARE SECTION;

	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("GetAllAvaDepositBankAccts merchant_id = [%.*s]\n", hv_merchant_id.len, hv_merchant_id.arr));
DEBUGLOG(("\n"));

	EXEC SQL DECLARE c_cursor CURSOR FOR
		SELECT	ob_int_bank_code, ob_bank_acct_num, omb_service_code, country, omb_min_settle_amt, omb_min_settle_amt_applyadmin
		FROM	ol_merchant_bank_acct, ol_bank_accts, bank_desc
		WHERE	omb_merchant_id = :hv_merchant_id:ind_merchant_id
		AND	omb_disabled = 0
		AND	omb_status = 'O'
		AND	omb_int_bank_code = ob_int_bank_code
		AND	omb_bank_acct_num = ob_bank_acct_num
		AND     sp_ol_get_bank_acct_type(ob_int_bank_code, ob_bank_acct_num) = 'DSI'
		AND	ob_status_type <> 'I'
		AND	omb_int_bank_code = internal_bank_code
		AND	offline_support = 1
		ORDER BY ob_int_bank_code, ob_bank_acct_num;

	EXEC SQL OPEN c_cursor;
	for (;;) {
		EXEC SQL FETCH c_cursor
		INTO	:v_int_bank_code:ind_int_bank_code,
			:v_bank_acct_num:ind_bank_acct_num,
			:v_service_code:ind_service_code,
			:v_country:ind_country,
			:v_min_settle_amt:ind_min_settle_amt,
			:v_min_settle_amt_applyadmin:ind_min_settle_amt_applyadmin;

		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash, 0);

		iCnt++;

		if (ind_int_bank_code >= 0 && ind_bank_acct_num >= 0 && ind_service_code >= 0 && ind_country >= 0) {
			v_int_bank_code.arr[v_int_bank_code.len] = '\0';
			PutField_CString(myHash, "int_bank_code", (const char*)v_int_bank_code.arr);
DEBUGLOG(("GetAllAvaDepositBankAccts int_bank_code_%d = [%s]\n", iCnt, (const char*)v_int_bank_code.arr));

			v_bank_acct_num.arr[v_bank_acct_num.len] = '\0';
			PutField_CString(myHash, "bank_acct_num", (const char*)v_bank_acct_num.arr);
DEBUGLOG(("GetAllAvaDepositBankAccts bank_acct_num_%d = [%s]\n", iCnt, (const char*)v_bank_acct_num.arr));

			v_service_code.arr[v_service_code.len] = '\0';
			PutField_CString(myHash, "service_code", (const char*)v_service_code.arr);
DEBUGLOG(("GetAllAvaDepositBankAccts service_code_%d = [%s]\n", iCnt, (const char*)v_service_code.arr));

			v_country.arr[v_country.len] = '\0';
			PutField_CString(myHash, "country", (const char*)v_country.arr);
DEBUGLOG(("GetAllAvaDepositBankAccts country_%d = [%s]\n", iCnt, (const char*)v_country.arr));

			if (ind_min_settle_amt >= 0) {
				PutField_Int(myHash, "min_settle_amt", v_min_settle_amt);
DEBUGLOG(("GetAllAvaDepositBankAccts min_settle_amt_%d = [%d]\n", iCnt, v_min_settle_amt));

				if (v_min_settle_amt) {
					if (ind_min_settle_amt_applyadmin >= 0) {
						PutField_Double(myHash, "min_settle_amt_applyadmin", v_min_settle_amt_applyadmin);
DEBUGLOG(("GetAllAvaDepositBankAccts min_settle_amt_applyadmin_%d = [%lf]\n", iCnt, v_min_settle_amt_applyadmin));
					} else {
						PutField_Double(myHash, "min_settle_amt_applyadmin", 0);
DEBUGLOG(("GetAllAvaDepositBankAccts (default) min_settle_amt_applyadmin_%d = [%lf]\n", iCnt, 0));
					}
				}
			} else {
				PutField_Int(myHash, "min_settle_amt", 0);
DEBUGLOG(("GetAllAvaDepositBankAccts (default) min_settle_amt_%d = [%d]\n", iCnt, 0));

			}
DEBUGLOG(("\n"));
		}

		RecordSet_Add(myRec, myHash);
	}

	EXEC SQL CLOSE c_cursor;

DEBUGLOG(("GetAllAvaDepositBankAccts Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getallavadepositbankaccts_error:
DEBUGLOG(("getallavadepositbankaccts_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLMerchantBankAcct getallavadepositbankaccts_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	EXEC SQL CLOSE c_cursor;
	EXEC SQL WHENEVER SQLERROR CONTINUE;
	return PD_ERR;
}
*/


int     GetBeneficiaryBank(const char* csMerchantId,
                        const char* csCountry,
                        const char* csCcy,
                        const char* csAcctNum,
			const char* csAction,
                        hash_t *myHash)
{
        int     iRet = PD_ERR;
	int	iCnt = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO getbenbank_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

		/* varchar hv_acct_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_acct_ccy;

		/* varchar hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		/* varchar	hv_action[PD_ACCT_ACTION_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_action;


		/* varchar v_out_int_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_out_int_bank_code;

		/* varchar v_out_bank_name[PD_BANK_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_out_bank_name;


		short   ind_merchant_id = -1;
		short   ind_country = -1;
		short   ind_acct_ccy = -1;
		short	ind_bank_acct_num = -1;
		short	ind_action = -1;

		short   ind_out_int_bank_code = -1;
		short   ind_out_bank_name = -1; 

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetBeneficiaryBank: Begin\n"));

	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
DEBUGLOG(("GetBeneficiaryBank:merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        ind_merchant_id = 0;

	hv_country.len = strlen(csCountry);
        memcpy(hv_country.arr, csCountry, hv_country.len);
DEBUGLOG(("GetBeneficiaryBank:country = [%.*s]\n",hv_country.len,hv_country.arr));
	ind_country = 0;

	hv_acct_ccy.len = strlen(csCcy);
	memcpy(hv_acct_ccy.arr, csCcy, hv_acct_ccy.len);
DEBUGLOG(("GetBeneficiaryBank:acct_ccy = [%.*s]\n",hv_acct_ccy.len,hv_acct_ccy.arr));
	ind_acct_ccy = 0;

	hv_bank_acct_num.len = strlen(csAcctNum);
	memcpy(hv_bank_acct_num.arr, csAcctNum, hv_bank_acct_num.len);
DEBUGLOG(("GetBeneficiaryBank:bank_acct_num = [%.*s]\n",hv_bank_acct_num.len,hv_bank_acct_num.arr));
	ind_bank_acct_num = 0;

	hv_action.len = strlen(csAction);
	memcpy(hv_action.arr, csAction, hv_action.len);
DEBUGLOG(("GetBeneficiaryBank: action= [%.*s]\n",hv_action.len,hv_action.arr));
	ind_action = 0;

	/* EXEC SQL DECLARE c_cursor_getbenbank CURSOR FOR
		select internal_bank_code, bank_name
		from bank_desc, ol_bank_accts, def_bank, ol_merchant_bank_acct
		where omb_status = 'O'
		and omb_merchant_id = :hv_merchant_id:ind_merchant_id
		and omb_disabled = 0
		and omb_bank_acct_num = :hv_bank_acct_num:ind_bank_acct_num
		and omb_int_bank_code = db_int_bank_code
		and db_country = :hv_country:ind_country
		and omb_int_bank_code = ob_int_bank_code
		and omb_bank_acct_num = ob_bank_acct_num
		and sp_ol_get_bank_acct_type(ob_int_bank_code, ob_bank_acct_num) = 'DSI'
		/oand ob_status_type = 'A' o/
                and sp_ol_get_allow_action(ob_int_bank_code, ob_bank_acct_num, :hv_action) = 1
		and ob_acct_ccy = :hv_acct_ccy:ind_acct_ccy
		and internal_bank_code = ob_int_bank_code; */ 


	/* EXEc SQL OPEN c_cursor_getbenbank; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0008;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )558;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[0] = (unsigned long )17;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[1] = (unsigned long )52;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_bank_acct_num;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_country;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_country;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_action;
 sqlstm.sqhstl[3] = (unsigned long )22;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_acct_ccy;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_acct_ccy;
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
 if (sqlca.sqlcode < 0) goto getbenbank_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getbenbank
		INTO	
			:v_out_int_bank_code:ind_out_int_bank_code,
			:v_out_bank_name:ind_out_bank_name; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )593;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_out_int_bank_code;
  sqlstm.sqhstl[0] = (unsigned long )13;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_out_int_bank_code;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_out_bank_name;
  sqlstm.sqhstl[1] = (unsigned long )153;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_out_bank_name;
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
  if (sqlca.sqlcode < 0) goto getbenbank_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}
		iCnt++;

		if (ind_out_int_bank_code >= 0) {
			v_out_int_bank_code.arr[v_out_int_bank_code.len] = '\0';
			PutField_CString(myHash, "int_bank_code", (const char*)v_out_int_bank_code.arr);
DEBUGLOG(("GetBeneficiaryBank: int_bank_code = [%s]\n", v_out_int_bank_code.arr));
                }

		if (ind_out_bank_name >= 0) {
			v_out_bank_name.arr[v_out_bank_name.len] = '\0';
			PutField_CString(myHash, "bank_name", (const char*)v_out_bank_name.arr);
DEBUGLOG(("GetBeneficiaryBank: bank_name = [%s]\n", v_out_bank_name.arr));
		}

		break;
	} while (PD_TRUE);
	
	/* EXEC SQL CLOSE c_cursor_getbenbank; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )616;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getbenbank_error;
}



	if (iCnt > 0) {
DEBUGLOG(("GetBeneficiaryBank Normal Exit\n")); 
		iRet = PD_OK;
	} else {
DEBUGLOG(("GetBeneficiaryBank Normal Exit, NOT FOUND\n")); 
	}

	return iRet;

getbenbank_error:
DEBUGLOG(("getbenbank_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLMerchantBankAcct::GetBeneficiaryBank:getbenbank_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getbenbank; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )631;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int     GetAvaBeneficiaryBank(const char* csMerchantId,
                        const char* csCcy,
                        const char* csAcctNum,
                        hash_t *myHash)
{
        int     iRet = PD_ERR;
	int	iCnt = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO getavabenbank_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar hv_acct_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_acct_ccy;

		/* varchar hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		/* varchar v_int_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_int_bank_code;

		/* varchar	v_service_code[PD_SERVICE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		/* varchar	v_country[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;


		short   ind_merchant_id = -1;
		short   ind_acct_ccy = -1;
		short	ind_bank_acct_num = -1;
		short	ind_int_bank_code = -1;
		short	ind_service_code = -1;
		short	ind_country = -1;


	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetAvaBeneficiaryBank: Begin\n"));

	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
DEBUGLOG(("GetAvaBeneficiaryBank:merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        ind_merchant_id = 0;

	hv_acct_ccy.len = strlen(csCcy);
	memcpy(hv_acct_ccy.arr, csCcy, hv_acct_ccy.len);
DEBUGLOG(("GetAvaBeneficiaryBank:acct_ccy = [%.*s]\n",hv_acct_ccy.len,hv_acct_ccy.arr));
	ind_acct_ccy = 0;

	hv_bank_acct_num.len = strlen(csAcctNum);
	memcpy(hv_bank_acct_num.arr, csAcctNum, hv_bank_acct_num.len);
DEBUGLOG(("GetAvaBeneficiaryBank:bank_acct_num = [%.*s]\n",hv_bank_acct_num.len,hv_bank_acct_num.arr));
	ind_bank_acct_num = 0;

	/* EXEC SQL DECLARE c_cursor_getavabenbank CURSOR FOR
		SELECT	INT_BANK_CODE,
			SERVICE_CODE,
			COUNTRY
		FROM	OL_DEPOSIT_BANK_ACCT_VIEW
		WHERE	MERCHANT_ID = :hv_merchant_id:ind_merchant_id
		AND	BANK_ACCT_NUM = :hv_bank_acct_num:ind_bank_acct_num
		AND	ACCT_CCY = :hv_acct_ccy:ind_acct_ccy
		AND	ALLOW_ACTION = 1; */ 


	/* EXEc SQL OPEN c_cursor_getavabenbank; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0009;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )646;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[0] = (unsigned long )17;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[1] = (unsigned long )52;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_bank_acct_num;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_acct_ccy;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_acct_ccy;
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
 if (sqlca.sqlcode < 0) goto getavabenbank_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getavabenbank
		INTO	:v_int_bank_code:ind_int_bank_code,
			:v_service_code:ind_service_code,
			:v_country:ind_country; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )673;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_int_bank_code;
  sqlstm.sqhstl[0] = (unsigned long )13;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_int_bank_code;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_service_code;
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_service_code;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_country;
  sqlstm.sqhstl[2] = (unsigned long )5;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_country;
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
  if (sqlca.sqlcode < 0) goto getavabenbank_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}
		iCnt++;

		if (ind_int_bank_code >= 0) {
			v_int_bank_code.arr[v_int_bank_code.len] = '\0';
			PutField_CString(myHash, "int_bank_code", (const char*)v_int_bank_code.arr);
DEBUGLOG(("GetAvaBeneficiaryBank: int_bank_code = [%s]\n", v_int_bank_code.arr));
                }

		if (ind_service_code >= 0) {
			v_service_code.arr[v_service_code.len] ='\0';
			PutField_CString(myHash,"service_code",(const char*)v_service_code.arr);
DEBUGLOG(("FindDetailByAvaMerchBankAcct service_code = [%s]\n",v_service_code.arr));
		}

		if (ind_country >= 0) {
			v_country.arr[v_country.len] ='\0';
			PutField_CString(myHash,"country",(const char*)v_country.arr);
DEBUGLOG(("FindDetailByAvaMerchBankAcct country = [%s]\n",v_country.arr));
		}


		break;
	} while (PD_TRUE);
	
	/* EXEC SQL CLOSE c_cursor_getavabenbank; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )700;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getavabenbank_error;
}



	if (iCnt > 0) {
DEBUGLOG(("GetAvaBeneficiaryBank Normal Exit\n")); 
		iRet = PD_OK;
	} else {
DEBUGLOG(("GetAvaBeneficiaryBank Normal Exit, NOT FOUND\n")); 
	}

	return iRet;

getavabenbank_error:
DEBUGLOG(("getavabenbank_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLMerchantBankAcct::GetAvaBeneficiaryBank:getavabenbank_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getavabenbank; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )715;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


