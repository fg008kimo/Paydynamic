
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
           char  filnam[12];
};
static struct sqlcxp sqlfpn =
{
    11,
    "TestAndy.pc"
};


static unsigned int sqlctx = 162211;


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
   unsigned char  *sqhstv[7];
   unsigned long  sqhstl[7];
            int   sqhsts[7];
            short *sqindv[7];
            int   sqinds[7];
   unsigned long  sqharm[7];
   unsigned long  *sqharc[7];
   unsigned short  sqadto[7];
   unsigned short  sqtdso[7];
} sqlstm = {12,7};

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
"SELECT ta_bank_code , ta_support_po , ta_min_amt , ta_remark FROM test_andy\
 WHERE ta_type = :b0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,221,0,6,117,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,1,0,0,1,3,0,0,1,4,0,0,1,9,
0,0,1,9,0,0,
48,0,0,2,135,0,4,184,0,0,5,1,0,1,0,2,1,0,0,2,3,0,0,2,4,0,0,2,9,0,0,1,9,0,0,
83,0,0,3,107,0,9,273,0,2049,1,1,0,1,0,1,1,0,0,
102,0,0,3,0,0,13,276,0,0,4,0,0,1,0,2,9,0,0,2,3,0,0,2,4,0,0,2,9,0,0,
133,0,0,3,0,0,15,322,0,0,0,0,0,1,0,
148,0,0,3,0,0,15,339,0,0,0,0,0,1,0,
163,0,0,4,0,0,17,441,0,0,1,1,0,1,0,1,9,0,0,
182,0,0,4,0,0,21,442,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2019/10/28              [ANC]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlca.h>
#include "TestAndy.h"
#include "common.h"
#include "dbutility.h"
#include "internal.h"
#include "utilitys.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char cDebug;

void TestAndy(char cdebug)
{
	cDebug = cdebug;
}

int Add(const hash_t * hTestAndy)
{
	char	cTmp;
	char	*csTmp;
	double	dTmp;
	int	iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;

		char		hv_type;
		int		hv_support_po;
		double		hv_min_amt;
		/* varchar		hv_remark[PD_REMARK_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_remark;

		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_bank_code = -1;
		short		ind_type = -1;
		short		ind_support_po = -1;
		short		ind_min_amt = -1;
		short		ind_remark = -1;
		short		ind_create_user = -1;

		short		hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

	/* bank_code */
	if (GetField_CString(hTestAndy, "bank_code", &csTmp))
	{
		hv_bank_code.len = strlen(csTmp);
		strncpy((char *)hv_bank_code.arr, csTmp, hv_bank_code.len);
		ind_bank_code = 0;

DEBUGLOG(("Add: bank_code = [%.*s]\n", hv_bank_code.len, hv_bank_code.arr));
	}

	/* type */
	if (GetField_Char(hTestAndy, "type", &cTmp))
	{
		hv_type = cTmp;
		ind_type = 0;

DEBUGLOG(("Add: type = [%c]\n", hv_type));
	}

	/* support_po */
	if (GetField_Int(hTestAndy, "support_po", &iTmp))
	{
		hv_support_po = iTmp;
		ind_support_po = 0;

DEBUGLOG(("Add: support_po = [%d]\n", hv_support_po));
	}

	/* min_amt */
	if (GetField_Double(hTestAndy, "min_amt", &dTmp))
	{
		hv_min_amt = dTmp;
		ind_min_amt = 0;

DEBUGLOG(("Add: min_amt = [%lf]\n", hv_min_amt));
	}

	/* remark */
	if (GetField_CString(hTestAndy, "remark", &csTmp))
	{
		hv_remark.len = strlen(csTmp);
		strncpy((char *)hv_remark.arr, csTmp, hv_remark.len);
		ind_remark = 0;

DEBUGLOG(("Add: remark = [%.*s]\n", hv_remark.len, hv_remark.arr));
	}

	/* create_user */
	if (GetField_CString(hTestAndy, "create_user", &csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char *)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;

DEBUGLOG(("Add: create_user = [%.*s]\n", hv_create_user.len, hv_create_user.arr));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_test_andy_insert(
				:hv_bank_code:ind_bank_code,
				:hv_type:ind_type,
				:hv_support_po:ind_support_po,
				:hv_min_amt:ind_min_amt,
				:hv_remark:ind_remark,
				:hv_create_user:ind_create_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_test_andy_insert ( :hv_bank_co\
de:ind_bank_code , :hv_type:ind_type , :hv_support_po:ind_support_po , :hv_mi\
n_amt:ind_min_amt , :hv_remark:ind_remark , :hv_create_user:ind_create_user )\
 ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_code;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_bank_code;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_type;
 sqlstm.sqhstl[2] = (unsigned long )1;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_type;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_support_po;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_support_po;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_min_amt;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_min_amt;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_remark;
 sqlstm.sqhstl[5] = (unsigned long )257;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_remark;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[6] = (unsigned long )22;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto add_error;
}



DEBUGLOG(("Add: Ret = [%d]\n", hv_return_value));

	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("Add: Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)
	{
ERRLOG("TestAndy_Add: SP_OTHER_ERR\n");
DEBUGLOG(("Add: SP_OTHER_ERR\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)
	{
ERRLOG("TestAndy_Add: SP_ERR\n");
DEBUGLOG(("Add: SP_ERR\n"));
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("TestAndy_Add: SP_INTERNAL_ERR\n");
DEBUGLOG(("Add: SP_INTERNAL_ERR\n"));
	return PD_INTERNAL_ERR;
}

int GetByBankCode(const char * csBankCode, hash_t * hRec)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO getbybankcode_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;


		char		v_type;
		int		v_support_po;
		double		v_min_amt;
		/* varchar		v_remark[PD_REMARK_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;


		short		ind_type = -1;
		short		ind_support_po = -1;
		short		ind_min_amt = -1;
		short		ind_remark = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	/* bank_code */
	hv_bank_code.len = strlen(csBankCode);
	memcpy(hv_bank_code.arr, csBankCode, hv_bank_code.len);
DEBUGLOG(("GetByBankCode: csBankCode = [%.*s]\n", hv_bank_code.len, hv_bank_code.arr));

	/* EXEC SQL SELECT ta_type, 
			ta_support_po, 
			ta_min_amt, 
			ta_remark
		INTO	:v_type:ind_type, 
			:v_support_po:ind_support_po, 
			:v_min_amt:ind_min_amt, 
			:v_remark:ind_remark
		FROM test_andy
		WHERE ta_bank_code = :hv_bank_code; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select ta_type , ta_support_po , ta_min_amt , ta_remark INT\
O :b0:b1 , :b2:b3 , :b4:b5 , :b6:b7 FROM test_andy WHERE ta_bank_code = :b8 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )48;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_type;
 sqlstm.sqhstl[0] = (unsigned long )1;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_type;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_support_po;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_support_po;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_min_amt;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_min_amt;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&v_remark;
 sqlstm.sqhstl[3] = (unsigned long )258;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_remark;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_bank_code;
 sqlstm.sqhstl[4] = (unsigned long )12;
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
 if (sqlca.sqlcode < 0) goto getbybankcode_error;
}



	/* type */
	if (ind_type >= 0)
	{
DEBUGLOG(("GetByBankCode type = [%c]\n", v_type));
		PutField_Char(hRec, "type", v_type);

		/* support_po */
		if (ind_support_po >= 0)
		{
DEBUGLOG(("GetByBankCode support_po = [%d]\n", v_support_po));
			PutField_Int(hRec, "support_po", v_support_po); 
		}

		/* min_amt */
		if (ind_min_amt >= 0)
		{
DEBUGLOG(("GetByBankCode min_amt = [%lf]\n", v_min_amt));
			PutField_Double(hRec, "min_amt", v_min_amt);
		}

		/* remark */
		if (ind_remark >= 0)
		{
			v_remark.arr[v_remark.len] = '\0';
DEBUGLOG(("GetByBankCode remark = [%s]\n", v_remark.arr));
			PutField_CString(hRec, "remark", (const char *)v_remark.arr);
		}

DEBUGLOG(("GetByBankCode Normal Exit\n"));
		return PD_OK;
	}
	else
	{
DEBUGLOG(("GetByBankCode Not Found\n"));
		return PD_NOT_FOUND;
	}

getbybankcode_error:
DEBUGLOG(("getbybankcode_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int GetByType(const char cType, recordset_t * myRec)
{
	hash_t  * myHash;
	int	iCnt = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO getbytype_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		char		hv_type;

		/* varchar		v_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

		int		v_support_po;
		double		v_min_amt;
		/* varchar		v_remark[PD_REMARK_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;


		short		ind_bank_code = -1;
		short		ind_support_po = -1;
		short		ind_min_amt = -1;
		short		ind_remark = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	/* type */
	hv_type = cType;
DEBUGLOG(("GetByType: cType = [%c]\n", hv_type));

	/* EXEC SQL DECLARE c_cursor_getbytype CURSOR FOR 
		SELECT  ta_bank_code, 
			ta_support_po, 
			ta_min_amt, 
			ta_remark
		FROM test_andy
		WHERE ta_type = :hv_type; */ 


	/* EXEC SQL OPEN c_cursor_getbytype; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )83;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_type;
 sqlstm.sqhstl[0] = (unsigned long )1;
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
 if (sqlca.sqlcode < 0) goto getbytype_error;
}


	do
	{
		/* EXEC SQL FETCH c_cursor_getbytype
			INTO	:v_bank_code:ind_bank_code, 
				:v_support_po:ind_support_po, 
				:v_min_amt:ind_min_amt, 
				:v_remark:ind_remark; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )102;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_bank_code;
  sqlstm.sqhstl[0] = (unsigned long )13;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_bank_code;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_support_po;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_support_po;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_min_amt;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_min_amt;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_remark;
  sqlstm.sqhstl[3] = (unsigned long )258;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_remark;
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
  if (sqlca.sqlcode < 0) goto getbytype_error;
}



		if (SQLCODE == SQL_NOT_FOUND)
			break;

		myHash = (hash_t *)malloc(sizeof(hash_t));
		hash_init(myHash, 0);

		/* bank_code */
		if (ind_bank_code >= 0)
		{
			v_bank_code.arr[v_bank_code.len] = '\0';
DEBUGLOG(("GetByType bank_code = [%s]\n", v_bank_code.arr));
			PutField_CString(myHash, "bank_code", (const char *)v_bank_code.arr);
		}

		/* support_po */
		if (ind_support_po >= 0)
		{
DEBUGLOG(("GetByType support_po = [%d]\n", v_support_po));
			PutField_Int(myHash, "support_po", v_support_po);
		}

		/* min_amt */
		if (ind_min_amt >= 0)
		{
DEBUGLOG(("GetByType min_amt = [%lf]\n", v_min_amt));
			PutField_Double(myHash, "min_amt", v_min_amt);
		}

		/* remark */
		if (ind_remark >= 0)
		{
			v_remark.arr[v_remark.len] = '\0';
DEBUGLOG(("GetByType remark = [%s]\n", v_remark.arr));
			PutField_CString(myHash, "remark", (const char *)v_remark.arr);
		}

		iCnt++;
		RecordSet_Add(myRec, myHash);
	} while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getbytype; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )133;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getbytype_error;
}



	if (iCnt > 0)
	{
DEBUGLOG(("GetByType Normal Exit\n"));
		return PD_OK;
	}
	else
	{
DEBUGLOG(("GetByType Normal Exit, Not Found\n"));
		return PD_NOT_FOUND;
	}

getbytype_error:
DEBUGLOG(("getbytype_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getbytype; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )148;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

int Update(const hash_t * hTestAndy)
{
        char    cTmp;
        char    * csTmp;
        char    * csBankCode;
        double  dTmp = 0.0;
        int     iTmp = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));

        csTmp = (char *)malloc(128);

        strcpy((char *)hv_dynstmt.arr, "UPDATE test_andy SET ta_update_timestamp = SYSDATE");
        hv_dynstmt.len = strlen((const char *)hv_dynstmt.arr);

        // bank_code 
        if (GetField_CString(hTestAndy, "bank_code", &csBankCode))
        {
DEBUGLOG(("Update: bank_code = [%s]\n", csBankCode));
        }
        else
        {
                FREE_ME(csTmp);
DEBUGLOG(("Update bank_code not found\n"));

                return INT_ERR;
        }

        // type 
        if (GetField_Char(hTestAndy, "type", &cTmp))
        {
                sprintf(csTmp, "%c", cTmp);
                strcat((char *)hv_dynstmt.arr, ", ta_type = '");
                strcat((char *)hv_dynstmt.arr, csTmp);
                strcat((char *)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("Update: type = [%c]\n", cTmp));
        }

        // support_po 
        if (GetField_Int(hTestAndy, "support_po", &iTmp))
        {
                sprintf(csTmp, "%d", iTmp);
                strcat((char *)hv_dynstmt.arr, ", ta_support_po = ");
                strcat((char *)hv_dynstmt.arr, csTmp);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("Update: support_po = [%d]\n", iTmp));
        }

        // min_amt 
        if (GetField_Double(hTestAndy, "min_amt", &dTmp))
        {
                sprintf(csTmp, "%lf", dTmp);
                strcat((char *)hv_dynstmt.arr, ", ta_min_amt = ");
                strcat((char *)hv_dynstmt.arr, csTmp);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("Update: min_amt = [%lf]\n", dTmp));
        }

        // remark 
        if (GetField_CString(hTestAndy, "remark", &csTmp))
        {
                strcat((char *)hv_dynstmt.arr, ", ta_remark = '");
                strcat((char *)hv_dynstmt.arr, csTmp);
                strcat((char *)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("Update: remark = [%s]\n", csTmp));
        }

        // update_user 
        if (GetField_CString(hTestAndy, "create_user", &csTmp))
        {
                strcat((char *)hv_dynstmt.arr, ", ta_update_user = '");
                strcat((char *)hv_dynstmt.arr, csTmp);
                strcat((char *)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("Update: update_user = [%s]\n", csTmp));
        }

        strcat((char *)hv_dynstmt.arr, " WHERE ta_bank_code = '");
        strcat((char *)hv_dynstmt.arr, csBankCode);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("Update SQL = [%.*s]\n", hv_dynstmt.len, hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )163;
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
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )182;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_error;
}



        FREE_ME(csTmp);

DEBUGLOG(("Update Normal Exit\n"));
        return PD_OK;

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("TestAndy_Update: SP_INTERNAL_ERR\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR\n"));
        return PD_INTERNAL_ERR;
}

/*
int Update(const hash_t * hRls)
{
        char    cTmp;
        char    * csTmp;
        char    * csBankCode;
        double  dTmp = 0.0;
        int     iTmp = 0;

        EXEC SQL WHENEVER SQLERROR GOTO update_error;
        EXEC SQL WHENEVER NOTFOUND CONTINUE;

        EXEC SQL BEGIN DECLARE SECTION;
		        varchar         hv_bank_code[PD_BANK_CODE_LEN];
                char            hv_type;
                int             hv_support_po;
                double          hv_min_amt;
                varchar         hv_remark[PD_REMARK_LEN];
                varchar         hv_update_user[PD_USER_LEN];

                short           ind_bank_code = -1;
                short           ind_type = -1;
                short           ind_support_po = -1;
                short           ind_min_amt = -1;
                short           ind_remark = -1;
                short           ind_update_user = -1;

                short           hv_return_value;
		
        EXEC SQL END DECLARE SECTION;

DEBUGLOG(("Update: Begin\n"));

        // bank_code 
        if (GetField_CString(hRls, "bank_code", &csTmp))
        {
                hv_bank_code.len = strlen(csTmp);
                strncpy((char *)hv_bank_code.arr, csTmp, hv_bank_code.len);
                ind_bank_code = 0;

DEBUGLOG(("Update: bank_code = [%.*s]\n", hv_bank_code.len, hv_bank_code.arr));
        }

        // type 
        if (GetField_Char(hRls, "type", &cTmp))
        {
                hv_type = cTmp;
                ind_type = 0;

DEBUGLOG(("Update: type = [%c]\n", hv_type));
        }

        // support_po 
        if (GetField_Int(hRls, "support_po", &iTmp))
        {
                hv_support_po = iTmp;
                ind_support_po = 0;

DEBUGLOG(("Update: support_po = [%d]\n", hv_support_po));
        }

        // min_amt 
        if (GetField_Double(hRls, "min_amt", &dTmp))
        {
                hv_min_amt = dTmp;
                ind_min_amt = 0;

DEBUGLOG(("Update: min_amt = [%lf]\n", hv_min_amt));
        }

        // remark 
        if (GetField_CString(hRls, "remark", &csTmp))
        {
                hv_remark.len = strlen(csTmp);
                strncpy((char *)hv_remark.arr, csTmp, hv_remark.len);
                ind_remark = 0;

DEBUGLOG(("Update: remark = [%.*s]\n", hv_remark.len, hv_remark.arr));
        }

        // update_user 
        if (GetField_CString(hRls, "create_user", &csTmp))
        {
                hv_update_user.len = strlen(csTmp);
                strncpy((char *)hv_update_user.arr, csTmp, hv_update_user.len);
                ind_update_user = 0;

DEBUGLOG(("Update update_user = [%.*s]\n", hv_update_user.len, hv_update_user.arr));
        }
		
        EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_test_andy_update(
                                :hv_bank_code:ind_bank_code,
                                :hv_type:ind_type,
                                :hv_support_po:ind_support_po,
                                :hv_min_amt:ind_min_amt,
                                :hv_remark:ind_remark,
                                :hv_update_user:ind_update_user);
                END;
        END-EXEC;

DEBUGLOG(("Update: Ret = [%d]\n", hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("Update: Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)
        {
ERRLOG("TestAndy_Add: SP_OTHER_ERR\n");
DEBUGLOG(("Update: SP_OTHER_ERR\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)
        {
ERRLOG("TestAndy_Add: SP_ERR\n");
DEBUGLOG(("Update: SP_ERR\n"));
                return PD_ERR;
        }

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        EXEC SQL WHENEVER SQLERROR CONTINUE;
ERRLOG("TestAndy_Update: SP_INTERNAL_ERR\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR\n"));
        return PD_INTERNAL_ERR;	
}
*/
