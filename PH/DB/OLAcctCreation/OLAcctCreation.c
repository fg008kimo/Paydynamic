
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
    "OLAcctCreation.pc"
};


static unsigned int sqlctx = 9874587;


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
   unsigned char  *sqhstv[21];
   unsigned long  sqhstl[21];
            int   sqhsts[21];
            short *sqindv[21];
            int   sqinds[21];
   unsigned long  sqharm[21];
   unsigned long  *sqharc[21];
   unsigned short  sqadto[21];
   unsigned short  sqtdso[21];
} sqlstm = {12,21};

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
5,0,0,1,767,0,6,283,0,0,21,21,0,1,0,2,3,0,0,1,68,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,
1,3,0,0,1,9,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
104,0,0,2,206,0,6,414,0,0,6,6,0,1,0,2,3,0,0,1,68,0,0,1,3,0,0,1,3,0,0,1,9,0,0,1,
9,0,0,
143,0,0,3,221,0,4,486,0,0,7,1,0,1,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,1,0,0,2,
3,0,0,1,68,0,0,
186,0,0,4,116,0,4,582,0,0,3,2,0,1,0,2,9,0,0,1,68,0,0,1,1,0,0,
213,0,0,5,0,0,17,721,0,0,1,1,0,1,0,1,9,0,0,
232,0,0,5,0,0,21,722,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2020. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2020/05/29              [ZBL]
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlca.h>
#include "OLAcctCreation.h"
#include "common.h"
#include "dbutility.h"
#include "internal.h"
#include "utilitys.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char cDebug;

void OLAcctCreation(char cdebug)
{
	cDebug = cdebug;
}

int AddDetail(const hash_t *hIn)
{
	char	*csTmp;
	char	*csFileId;
	double	dTmp;
	int	iTmp;
	int	iRet = PD_ERR;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_detail_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		unsigned long		hv_file_id;
		int		hv_seq;
		/* varchar		hv_provider_name[PD_CLIENT_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_provider_name;

		/* varchar		hv_provider_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_provider_id;

		/* varchar		hv_acct_type[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_acct_type;

		/* varchar		hv_bank_name[PD_BANK_ACCT_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_name;

		/* varchar		hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar		hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		/* varchar		hv_bank_acct_short_name[PD_BANK_ACCT_SHORT_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_bank_acct_short_name;

		/* varchar		hv_owner_name[PD_OWNER_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_owner_name;

		/* varchar		hv_province[PD_PROVINCE_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_province;

		/* varchar		hv_city[PD_CITY_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_city;

		/* varchar		hv_branch_name[PD_BANK_BRANCH_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_branch_name;

		double		hv_init_bal;
		int		hv_support_sms_stmt;
		/* varchar		hv_registered_mobile[PD_CUSTOMER_TEL_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_registered_mobile;

		int		hv_apply_deposit_cost;
		/* varchar		hv_merchant_short_name[PD_MERCH_SHORT_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_merchant_short_name;

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_file_id			= -1;
		short		ind_seq				= -1;
		short		ind_provider_name		= -1;
		short		ind_provider_id			= -1;
		short		ind_acct_type			= -1;
		short		ind_bank_name			= -1;
		short		ind_int_bank_code		= -1;
		short		ind_bank_acct_num		= -1;
		short		ind_bank_acct_short_name	= -1;
		short		ind_owner_name			= -1;
		short		ind_province			= -1;
		short		ind_city			= -1;
		short		ind_branch_name			= -1;
		short		ind_init_bal			= -1;
		short		ind_support_sms_stmt		= -1;
		short		ind_registered_mobile		= -1;
		short		ind_apply_deposit_cost		= -1;
		short		ind_merchant_short_name		= -1;
		short		ind_merchant_id			= -1;
		short		ind_create_user			= -1;

		short		hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("AddDetail: Begin\n"));

	/* file_id */
	if(GetField_CString(hIn,"file_id",&csFileId))
	{
		hv_file_id = (unsigned long)ctol((const unsigned char*)csFileId,strlen(csFileId));
		ind_file_id = 0;

DEBUGLOG(("- file_id = [%lu]\n", hv_file_id));
	}

	/* seq */
	if (GetField_Int(hIn, "seq", &iTmp))
	{
		hv_seq = iTmp;
		ind_seq = 0;

DEBUGLOG(("- seq = [%d]\n", hv_seq));
	}

	/* provider_name */
	if (GetField_CString(hIn, "provider_name", &csTmp))
	{
		hv_provider_name.len = strlen(csTmp);
		memcpy(hv_provider_name.arr, csTmp, hv_provider_name.len);
		ind_provider_name = 0;

DEBUGLOG(("- provider_name = [%.*s]\n", hv_provider_name.len, hv_provider_name.arr));
	}

	/* provider_id */
	if (GetField_CString(hIn, "provider_id", &csTmp))
	{
		hv_provider_id.len = strlen(csTmp);
		memcpy(hv_provider_id.arr, csTmp, hv_provider_id.len);
		ind_provider_id = 0;

DEBUGLOG(("- provider_id = [%.*s]\n", hv_provider_id.len, hv_provider_id.arr));
	}

	/* acct_type */
	if (GetField_CString(hIn, "acct_type", &csTmp))
	{
		hv_acct_type.len = strlen(csTmp);
		memcpy(hv_acct_type.arr, csTmp, hv_acct_type.len);
		ind_acct_type = 0;

DEBUGLOG(("- acct_type = [%.*s]\n", hv_acct_type.len, hv_acct_type.arr));
	}

	/* bank_name */
	if (GetField_CString(hIn, "bank_name", &csTmp))
	{
		hv_bank_name.len = strlen(csTmp);
		memcpy(hv_bank_name.arr, csTmp, hv_bank_name.len);
		ind_bank_name = 0;

DEBUGLOG(("- bank_name = [%.*s]\n", hv_bank_name.len, hv_bank_name.arr));
	}

	/* int_bank_code */
	if (GetField_CString(hIn, "int_bank_code", &csTmp))
	{
		hv_int_bank_code.len = strlen(csTmp);
		memcpy(hv_int_bank_code.arr, csTmp, hv_int_bank_code.len);
		ind_int_bank_code = 0;

DEBUGLOG(("- int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));
	}

	/* bank_acct_num */
	if (GetField_CString(hIn, "bank_acct_num", &csTmp))
	{
		hv_bank_acct_num.len = strlen(csTmp);
		memcpy(hv_bank_acct_num.arr, csTmp, hv_bank_acct_num.len);
		ind_bank_acct_num = 0;

DEBUGLOG(("- bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));
	}

	/* bank_acct_short_name */
	if (GetField_CString(hIn, "bank_acct_short_name", &csTmp))
	{
		hv_bank_acct_short_name.len = strlen(csTmp);
		memcpy(hv_bank_acct_short_name.arr, csTmp, hv_bank_acct_short_name.len);
		ind_bank_acct_short_name = 0;

DEBUGLOG(("- bank_acct_short_name = [%.*s]\n", hv_bank_acct_short_name.len, hv_bank_acct_short_name.arr));
	}

	/* owner_name */
	if (GetField_CString(hIn, "owner_name", &csTmp))
	{
		hv_owner_name.len = strlen(csTmp);
		memcpy(hv_owner_name.arr, csTmp, hv_owner_name.len);
		ind_owner_name = 0;

DEBUGLOG(("- owner_name = [%.*s]\n", hv_owner_name.len, hv_owner_name.arr));
	}

	/* province */
	if (GetField_CString(hIn, "province", &csTmp))
	{
		hv_province.len = strlen(csTmp);
		memcpy(hv_province.arr, csTmp, hv_province.len);
		ind_province = 0;

DEBUGLOG(("- province = [%.*s]\n", hv_province.len, hv_province.arr));
	}

	/* city */
	if (GetField_CString(hIn, "city", &csTmp))
	{
		hv_city.len = strlen(csTmp);
		memcpy(hv_city.arr, csTmp, hv_city.len);
		ind_city = 0;

DEBUGLOG(("- city = [%.*s]\n", hv_city.len, hv_city.arr));
	}

	/* branch_name */
	if (GetField_CString(hIn, "branch_name", &csTmp))
	{
		hv_branch_name.len = strlen(csTmp);
		memcpy(hv_branch_name.arr, csTmp, hv_branch_name.len);
		ind_branch_name = 0;

DEBUGLOG(("- branch_name = [%.*s]\n", hv_branch_name.len, hv_branch_name.arr));
	}

	/* init_bal */
	if (GetField_Double(hIn, "init_bal", &dTmp))
	{
		hv_init_bal = dTmp;
		ind_init_bal = 0;

DEBUGLOG(("- init_bal = [%lf]\n", hv_init_bal));
	}

	/* support_sms_stmt */
	if (GetField_Int(hIn, "support_sms_stmt", &iTmp))
	{
		hv_support_sms_stmt = iTmp;
		ind_support_sms_stmt = 0;

DEBUGLOG(("- support_sms_stmt = [%d]\n", hv_support_sms_stmt));
	}

	/* registered_mobile */
	if (GetField_CString(hIn, "registered_mobile", &csTmp))
	{
		hv_registered_mobile.len = strlen(csTmp);
		memcpy(hv_registered_mobile.arr, csTmp, hv_registered_mobile.len);
		ind_registered_mobile = 0;

DEBUGLOG(("- registered_mobile = [%.*s]\n", hv_registered_mobile.len, hv_registered_mobile.arr));
	}

	/* apply_deposit_cost */
	if (GetField_Int(hIn, "apply_deposit_cost", &iTmp))
	{
		hv_apply_deposit_cost = iTmp;
		ind_apply_deposit_cost = 0;

DEBUGLOG(("- apply_deposit_cost = [%d]\n", hv_apply_deposit_cost));
	}

	/* merchant_short_name */
	if (GetField_CString(hIn, "merchant_short_name", &csTmp))
	{
		hv_merchant_short_name.len = strlen(csTmp);
		memcpy(hv_merchant_short_name.arr, csTmp, hv_merchant_short_name.len);
		ind_merchant_short_name = 0;

DEBUGLOG(("- merchant_short_name = [%.*s]\n", hv_merchant_short_name.len, hv_merchant_short_name.arr));
	}

	/* merchant_id */
	if (GetField_CString(hIn, "merchant_id", &csTmp))
	{
		hv_merchant_id.len = strlen(csTmp);
		memcpy(hv_merchant_id.arr, csTmp, hv_merchant_id.len);
		ind_merchant_id = 0;

DEBUGLOG(("- merchant_id = [%.*s]\n", hv_merchant_id.len, hv_merchant_id.arr));
	}

	/* create_user */
	if (GetField_CString(hIn, "create_user", &csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		memcpy(hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;

DEBUGLOG(("- create_user = [%.*s]\n", hv_create_user.len, hv_create_user.arr));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_acct_file_detail_insert(
				:hv_file_id:ind_file_id, 
				:hv_seq:ind_seq, 
				:hv_provider_name:ind_provider_name, 
				:hv_provider_id:ind_provider_id, 
				:hv_acct_type:ind_acct_type, 
				:hv_bank_name:ind_bank_name, 
				:hv_int_bank_code:ind_int_bank_code, 
				:hv_bank_acct_num:ind_bank_acct_num, 
				:hv_bank_acct_short_name:ind_bank_acct_short_name, 
				:hv_owner_name:ind_owner_name, 
				:hv_province:ind_province, 
				:hv_city:ind_city, 
				:hv_branch_name:ind_branch_name, 
				:hv_init_bal:ind_init_bal, 
				:hv_support_sms_stmt:ind_support_sms_stmt, 
				:hv_registered_mobile:ind_registered_mobile, 
				:hv_apply_deposit_cost:ind_apply_deposit_cost, 
				:hv_merchant_short_name:ind_merchant_short_name, 
				:hv_merchant_id:ind_merchant_id, 
				:hv_create_user:ind_create_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 21;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_acct_file_detail_insert ( :\
hv_file_id:ind_file_id , :hv_seq:ind_seq , :hv_provider_name:ind_provider_nam\
e , :hv_provider_id:ind_provider_id , :hv_acct_type:ind_acct_type , :hv_bank_\
name:ind_bank_name , :hv_int_bank_code:ind_int_bank_code , :hv_bank_acct_num:\
ind_bank_acct_num , :hv_bank_acct_short_name:ind_bank_acct_short_name , :hv_o\
wner_name:ind_owner_name , :hv_province:ind_province , :hv_city:ind_city , :h\
v_branch_name:ind_branch_name , :hv_init_bal:ind_init_bal , :hv_support_sms_s\
tmt:ind_support_sms_stmt , :hv_registered_mobile:ind_registered_mobile , :hv_\
apply_deposit_cost:ind_apply_deposit_cost , :hv_merchant_short_name:ind_merch\
ant_short_name , :hv_merchant_id:ind_merchant_id , :hv_create_user:ind_create\
_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_file_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_seq;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_seq;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_provider_name;
 sqlstm.sqhstl[3] = (unsigned long )52;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_provider_name;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_provider_id;
 sqlstm.sqhstl[4] = (unsigned long )12;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_provider_id;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_acct_type;
 sqlstm.sqhstl[5] = (unsigned long )5;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_acct_type;
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
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[7] = (unsigned long )12;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[8] = (unsigned long )52;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_bank_acct_num;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_bank_acct_short_name;
 sqlstm.sqhstl[9] = (unsigned long )22;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_bank_acct_short_name;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_owner_name;
 sqlstm.sqhstl[10] = (unsigned long )52;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_owner_name;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_province;
 sqlstm.sqhstl[11] = (unsigned long )102;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_province;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_city;
 sqlstm.sqhstl[12] = (unsigned long )102;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_city;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_branch_name;
 sqlstm.sqhstl[13] = (unsigned long )152;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_branch_name;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_init_bal;
 sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_init_bal;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_support_sms_stmt;
 sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_support_sms_stmt;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_registered_mobile;
 sqlstm.sqhstl[16] = (unsigned long )22;
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_registered_mobile;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&hv_apply_deposit_cost;
 sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&ind_apply_deposit_cost;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (unsigned char  *)&hv_merchant_short_name;
 sqlstm.sqhstl[18] = (unsigned long )22;
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)&ind_merchant_short_name;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[19] = (unsigned long )17;
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned long )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[20] = (unsigned long )22;
 sqlstm.sqhsts[20] = (         int  )0;
 sqlstm.sqindv[20] = (         short *)&ind_create_user;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned long )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto add_detail_error;
}



DEBUGLOG(("AddDetail: Ret = [%d]\n", hv_return_value));

	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("AddDetail: Normal Exit\n"));
		iRet = PD_OK;
	}
	else if (hv_return_value == SP_OTHER_ERR)
	{
ERRLOG("OLAcctCreation_AddDetail: SP_OTHER_ERR\n");
DEBUGLOG(("AddDetail: SP_OTHER_ERR\n"));
		iRet = PD_OTHER_ERR;
	}
	else if (hv_return_value == SP_ERR)
	{
ERRLOG("OLAcctCreation_AddDetail: SP_ERR\n");
DEBUGLOG(("AddDetail: SP_ERR\n"));
	}

	return iRet;

add_detail_error:
DEBUGLOG(("add_detail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLAcctCreation_AddDetail: SP_INTERNAL_ERR\n");
DEBUGLOG(("AddDetail: SP_INTERNAL_ERR\n"));
	return PD_ERR;
}

int AddError(const hash_t *hIn)
{
	char	*csTmp;
	char	*csFileId;
	int	iTmp;
	int	iRet = PD_ERR;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		unsigned long		hv_file_id;
		int		hv_seq;
		int		hv_msg_code;
		/* varchar		hv_line_content[PD_CONTENT_LEN]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_line_content;

		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_file_id		= -1;
		short		ind_seq			= -1;
		short		ind_msg_code		= -1;
		short		ind_line_content	= -1;
		short		ind_create_user		= -1;

		short		hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("AddError: Begin\n"));

	/* file_id */
	if(GetField_CString(hIn,"file_id",&csFileId))
	{
		hv_file_id = (unsigned long)ctol((const unsigned char*)csFileId,strlen(csFileId));
		ind_file_id = 0;

DEBUGLOG(("- file_id = [%lu]\n", hv_file_id));
	}

	/* seq */
	if (GetField_Int(hIn, "seq", &iTmp))
	{
		hv_seq = iTmp;
		ind_seq = 0;

DEBUGLOG(("- seq = [%d]\n", hv_seq));
	}

	/* msg_code */
	if (GetField_Int(hIn, "msg_code", &iTmp))
	{
		hv_msg_code = iTmp;
		ind_msg_code = 0;

DEBUGLOG(("- msg_code = [%d]\n", hv_msg_code));
	}

	/* line_content */
	if (GetField_CString(hIn, "line_content", &csTmp))
	{
		hv_line_content.len = strlen(csTmp);
		memcpy(hv_line_content.arr, csTmp, hv_line_content.len);
		ind_line_content = 0;

DEBUGLOG(("- line_content = [%.*s]\n", hv_line_content.len, hv_line_content.arr));
	}

	/* create_user */
	if (GetField_CString(hIn, "create_user", &csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		memcpy(hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;

DEBUGLOG(("- create_user = [%.*s]\n", hv_create_user.len, hv_create_user.arr));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_acct_file_error_insert(
				:hv_file_id:ind_file_id, 
				:hv_seq:ind_seq, 
				:hv_msg_code:ind_msg_code, 
				:hv_line_content:ind_line_content, 
				:hv_create_user:ind_create_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 21;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_acct_file_error_insert ( :h\
v_file_id:ind_file_id , :hv_seq:ind_seq , :hv_msg_code:ind_msg_code , :hv_lin\
e_content:ind_line_content , :hv_create_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )104;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_file_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_seq;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_seq;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_msg_code;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_msg_code;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_line_content;
 sqlstm.sqhstl[4] = (unsigned long )1026;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_line_content;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[5] = (unsigned long )22;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto add_error_error;
}



DEBUGLOG(("AddError: Ret = [%d]\n", hv_return_value));

	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("AddError: Normal Exit\n"));
		iRet = PD_OK;
	}
	else if (hv_return_value == SP_OTHER_ERR)
	{
ERRLOG("OLAcctCreation_AddError: SP_OTHER_ERR\n");
DEBUGLOG(("AddError: SP_OTHER_ERR\n"));
		iRet = PD_OTHER_ERR;
	}
	else if (hv_return_value == SP_ERR)
	{
ERRLOG("OLAcctCreation_AddError: SP_ERR\n");
DEBUGLOG(("AddError: SP_ERR\n"));
	}

	return iRet;

add_error_error:
DEBUGLOG(("add_error_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLAcctCreation_AddError: SP_INTERNAL_ERR\n");
DEBUGLOG(("AddError: SP_INTERNAL_ERR\n"));
	return PD_ERR;
}

int GetHeaderByFileId(unsigned long lFileId, hash_t *hOut)
{
	int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO get_header_by_fileid_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		unsigned long		hv_file_id;

		/* varchar		v_raw_filename[PD_UPLOAD_FILENAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_raw_filename;

		/* varchar		v_convert_filename[PD_UPLOAD_FILENAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_convert_filename;

		int		v_total_count;
		int		v_accept_count;
		char		v_status;
		int		v_msg_code;

		short		ind_raw_filename	= -1;
		short		ind_convert_filename	= -1;
		short		ind_total_count		= -1;
		short		ind_accept_count	= -1;
		short		ind_status		= -1;
		short		ind_msg_code		= -1;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetHeaderByFileId: Begin\n"));

	/* file_id */
	hv_file_id = lFileId;
DEBUGLOG(("- file_id = [%lu]\n", hv_file_id));

	/* EXEC SQL 
		SELECT	afh_raw_filename, 
			afh_convert_filename, 
			afh_total_count, 
			afh_accept_count, 
			afh_status, 
			afh_msg_code 
		INTO	:v_raw_filename:ind_raw_filename, 
			:v_convert_filename:ind_convert_filename, 
			:v_total_count:ind_total_count, 
			:v_accept_count:ind_accept_count, 
			:v_status:ind_status, 
			:v_msg_code:ind_msg_code 
		FROM	ol_acct_file_header 
		WHERE	afh_file_id = :hv_file_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 21;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select afh_raw_filename , afh_convert_filename , afh_total_\
count , afh_accept_count , afh_status , afh_msg_code INTO :b0:b1 , :b2:b3 , :\
b4:b5 , :b6:b7 , :b8:b9 , :b10:b11 FROM ol_acct_file_header WHERE afh_file_id\
 = :b12 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )143;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_raw_filename;
 sqlstm.sqhstl[0] = (unsigned long )103;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_raw_filename;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_convert_filename;
 sqlstm.sqhstl[1] = (unsigned long )103;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_convert_filename;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_total_count;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_total_count;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&v_accept_count;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_accept_count;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&v_status;
 sqlstm.sqhstl[4] = (unsigned long )1;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_status;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&v_msg_code;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_msg_code;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto get_header_by_fileid_error;
}



	/* raw_filename */
	if (ind_raw_filename >= 0)
	{
		v_raw_filename.arr[v_raw_filename.len] = '\0';
DEBUGLOG(("- raw_filename = [%s]\n", v_raw_filename.arr));
		PutField_CString(hOut, "raw_filename", (const char*)v_raw_filename.arr);
	}

	/* convert_filename */
	if (ind_convert_filename >= 0)
	{
		v_convert_filename.arr[v_convert_filename.len] = '\0';
DEBUGLOG(("- convert_filename = [%s]\n", v_convert_filename.arr));
		PutField_CString(hOut, "convert_filename", (const char*)v_convert_filename.arr);
	}

	/* total_count */
	if (ind_total_count >= 0)
	{
DEBUGLOG(("- total_count = [%d]\n", v_total_count));
		PutField_Int(hOut, "total_count", v_total_count);
	}

	/* accept_count */
	if (ind_accept_count >= 0)
	{
DEBUGLOG(("- accept_count = [%d]\n", v_accept_count));
		PutField_Int(hOut, "accept_count", v_accept_count);
	}

	/* status */
	if (ind_status >= 0)
	{
DEBUGLOG(("- status = [%c]\n", v_status));
		PutField_Char(hOut, "status", v_status);
	}

	/* msg_code */
	if (ind_msg_code >= 0)
	{
DEBUGLOG(("- msg_code = [%d]\n", v_msg_code));
		PutField_Int(hOut, "msg_code", v_msg_code);
	}

DEBUGLOG(("GetHeaderByFileId: Normal Exit\n"));
	return iRet;

get_header_by_fileid_error:
DEBUGLOG(("get_header_by_fileid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int MatchHeaderStatusForUpdate(unsigned long lFileId, const char cStatus)
{
	int iRet = PD_NOT_FOUND;

	/* EXEC SQL WHENEVER SQLERROR GOTO match_header_status_for_update_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		unsigned long		hv_file_id;
		char		hv_status;

		/* varchar		v_create_user[PD_USER_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_create_user;


		short		ind_create_user = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("MatchHeaderStatusForUpdate: Begin\n"));

	/* file_id */
	hv_file_id = lFileId;
DEBUGLOG(("- file_id = [%lu]\n", hv_file_id));

	/* status */
	hv_status = cStatus;
DEBUGLOG(("- status = [%c]\n", hv_status));

	/* EXEC SQL 
		SELECT	afh_create_user 
		INTO	:v_create_user:ind_create_user 
		FROM	ol_acct_file_header 
		WHERE	afh_file_id = :hv_file_id AND 
			afh_status = :hv_status 
		FOR UPDATE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 21;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select afh_create_user INTO :b0:b1 FROM ol_acct_file_header\
 WHERE afh_file_id = :b2 AND afh_status = :b3 FOR UPDATE ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )186;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_create_user;
 sqlstm.sqhstl[0] = (unsigned long )23;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_create_user;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[2] = (unsigned long )1;
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
 if (sqlca.sqlcode < 0) goto match_header_status_for_update_error;
}



	/* create_user */
	if (ind_create_user >= 0)
	{
DEBUGLOG(("MatchHeaderStatusForUpdate: Normal Exit\n"));
		iRet = PD_FOUND;
	}
	else
	{
DEBUGLOG(("MatchHeaderStatusForUpdate: Normal Exit, Not Found\n"));
	}

	return iRet;

match_header_status_for_update_error:
DEBUGLOG(("match_header_status_for_update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int UpdateHeader(const hash_t *hIn)
{
	char	cTmp;
	char	*csBuf;
	char	*csTmp;
	char	*csFileId;
	int	iTmp;
	int	iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_header_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_dynstmt[PD_TMP_MSG_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[2048]; } hv_dynstmt;

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateHeader: Begin\n"));

	csBuf = (char*)malloc(PD_TMP_BUF_LEN);

	strcpy((char*)hv_dynstmt.arr, "UPDATE ol_acct_file_header SET afh_update_timestamp = SYSDATE");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	/* file_id */
	if(GetField_CString(hIn,"file_id",&csFileId))
	{
DEBUGLOG(("Update:file_id = [%s]\n",csFileId));
	}
	else
	{
		FREE_ME(csBuf);
DEBUGLOG(("UpdateHeader: file_id not found\n"));

		return INT_ERR;
	}

	/* convert_filename */
	if (GetField_CString(hIn, "convert_filename", &csTmp))
	{
		strcat((char*)hv_dynstmt.arr, ", afh_convert_filename = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- convert_filename = [%s]\n", csTmp));
	}

	/* total_count */
	if (GetField_Int(hIn, "total_count", &iTmp))
	{
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", afh_total_count = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- total_count = [%d]\n", iTmp));
	}

	/* accept_count */
	if (GetField_Int(hIn, "accept_count", &iTmp))
	{
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", afh_accept_count = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- accept_count = [%d]\n", iTmp));
	}

	/* status */
	if (GetField_Char(hIn, "status", &cTmp))
	{
		sprintf(csBuf, "%c", cTmp);
		strcat((char*)hv_dynstmt.arr, ", afh_status = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- status = [%c]\n", cTmp));
	}

	/* msg_code */
	if (GetField_Int(hIn, "msg_code", &iTmp))
	{
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", afh_msg_code = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- msg_code = [%d]\n", iTmp));
	}

	/* update_user */
	if (GetField_CString(hIn, "update_user", &csTmp))
	{
		strcat((char*)hv_dynstmt.arr, ", afh_update_user = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- update_user = [%s]\n", csTmp));
	}

	/* file_id */
	strcat((char*)hv_dynstmt.arr, " WHERE afh_file_id = '");
	strcat((char*)hv_dynstmt.arr, csFileId);
	strcat((char*)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- SQL = [%.*s]\n", hv_dynstmt.len, hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 21;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )213;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
 sqlstm.sqhstl[0] = (unsigned long )2050;
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
 if (sqlca.sqlcode < 0) goto update_header_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 21;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )232;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto update_header_error;
}



	FREE_ME(csBuf);

DEBUGLOG(("UpdateHeader: Normal Exit\n"));
	return iRet;

update_header_error:
DEBUGLOG(("update_header_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLAcctCreation_UpdateHeader: SP_INTERNAL_ERR\n");
DEBUGLOG(("UpdateHeader: SP_INTERNAL_ERR\n"));
	return PD_ERR;
}
