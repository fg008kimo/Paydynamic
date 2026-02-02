
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
    "TestZale.pc"
};


static unsigned int sqlctx = 163363;


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
"SELECT tz_txn_code , tz_flag , tz_value , tz_remark FROM test_zale WHERE tz\
_group = :b0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,205,0,6,120,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,1,0,0,1,3,0,0,1,4,0,0,1,9,
0,0,1,9,0,0,
48,0,0,2,127,0,4,229,0,0,5,1,0,1,0,2,1,0,0,2,3,0,0,2,4,0,0,2,9,0,0,1,9,0,0,
83,0,0,3,99,0,9,318,0,2049,1,1,0,1,0,1,1,0,0,
102,0,0,3,0,0,13,321,0,0,4,0,0,1,0,2,9,0,0,2,3,0,0,2,4,0,0,2,9,0,0,
133,0,0,3,0,0,15,367,0,0,0,0,0,1,0,
148,0,0,3,0,0,15,384,0,0,0,0,0,1,0,
163,0,0,4,0,0,17,486,0,0,1,1,0,1,0,1,9,0,0,
182,0,0,4,0,0,21,487,0,0,0,0,0,1,0,
197,0,0,5,200,0,6,558,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,4,0,0,2,1,0,0,2,3,0,0,2,
4,0,0,2,9,0,0,
240,0,0,0,0,0,56,709,0,0,1,1,0,1,0,3,102,0,0,
259,0,0,6,127,0,6,711,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,4,0,0,2,102,0,0,
290,0,0,0,0,0,13,731,0,0,5,1,0,1,0,1,102,0,0,2,1,0,0,2,3,0,0,2,4,0,0,2,9,0,0,
325,0,0,0,0,0,15,821,0,0,1,1,0,1,0,1,102,0,0,
344,0,0,0,0,0,78,822,0,0,1,1,0,1,0,3,102,0,0,
363,0,0,0,0,0,15,830,0,0,1,1,0,1,0,1,102,0,0,
382,0,0,0,0,0,78,831,0,0,1,1,0,1,0,3,102,0,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2019/08/26              Zale Ni
Add UpdateReturn Function                          2020/02/20              [ZBL]
Regex Testing                                      2021/07/30              [ZBL]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlca.h>
#include <regex.h>
#include "TestZale.h"
#include "common.h"
#include "dbutility.h"
#include "internal.h"
#include "utilitys.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char cDebug;

void TestZale(char cdebug)
{
	cDebug = cdebug;
}

int Add(const hash_t * hRls)
{
	char	cTmp;
	char	* csTmp;
	double	dTmp;
	int	iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

		char		hv_group;
		int		hv_flag;
		double		hv_value;
		/* varchar		hv_remark[PD_REMARK_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_remark;

		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_txn_code = -1;
		short		ind_group = -1;
		short		ind_flag = -1;
		short		ind_value = -1;
		short		ind_remark = -1;
		short		ind_create_user = -1;

		short		hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

	/* txn_code */
	if (GetField_CString(hRls, "txn_code", &csTmp))
	{
		hv_txn_code.len = strlen(csTmp);
		strncpy((char *)hv_txn_code.arr, csTmp, hv_txn_code.len);
		ind_txn_code = 0;

DEBUGLOG(("Add: txn_code = [%.*s]\n", hv_txn_code.len, hv_txn_code.arr));
	}

	/* group */
	if (GetField_Char(hRls, "group", &cTmp))
	{
		hv_group = cTmp;
		ind_group = 0;

DEBUGLOG(("Add: group = [%c]\n", hv_group));
	}

	/* flag */
	if (GetField_Int(hRls, "flag", &iTmp))
	{
		hv_flag = iTmp;
		ind_flag = 0;

DEBUGLOG(("Add: flag = [%d]\n", hv_flag));
	}

	/* value */
	if (GetField_Double(hRls, "value", &dTmp))
	{
		hv_value = dTmp;
		ind_value = 0;

DEBUGLOG(("Add: value = [%lf]\n", hv_value));
	}

	/* remark */
	if (GetField_CString(hRls, "remark", &csTmp))
	{
		hv_remark.len = strlen(csTmp);
		strncpy((char *)hv_remark.arr, csTmp, hv_remark.len);
		ind_remark = 0;

DEBUGLOG(("Add: remark = [%.*s]\n", hv_remark.len, hv_remark.arr));
	}

	/* create_user */
	if (GetField_CString(hRls, "create_user", &csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char *)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;

DEBUGLOG(("Add: create_user = [%.*s]\n", hv_create_user.len, hv_create_user.arr));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_test_zale_insert(
				:hv_txn_code:ind_txn_code,
				:hv_group:ind_group,
				:hv_flag:ind_flag,
				:hv_value:ind_value,
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
 sqlstm.stmt = "begin :hv_return_value := sp_test_zale_insert ( :hv_txn_cod\
e:ind_txn_code , :hv_group:ind_group , :hv_flag:ind_flag , :hv_value:ind_valu\
e , :hv_remark:ind_remark , :hv_create_user:ind_create_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_code;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_txn_code;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_group;
 sqlstm.sqhstl[2] = (unsigned long )1;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_group;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_flag;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_flag;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_value;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_value;
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
ERRLOG("TestZale_Add: SP_OTHER_ERR\n");
DEBUGLOG(("Add: SP_OTHER_ERR\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)
	{
ERRLOG("TestZale_Add: SP_ERR\n");
DEBUGLOG(("Add: SP_ERR\n"));
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("TestZale_Add: SP_INTERNAL_ERR\n");
DEBUGLOG(("Add: SP_INTERNAL_ERR\n"));
	return PD_INTERNAL_ERR;
}

int IsValid()
{
	//const char	* csPattern = "[a-z0-9_-]";
	char		csTarget[PD_TMP_BUF_LEN];
	const char	* csPattern = "[a-z0-9_-\\+]";
	const size_t	sMatch = 1;
	int		iRet = SUCCESS;
	int		iStatus;
	regex_t		rePreg;
	regmatch_t	reResult[1];

	strcpy(csTarget, "99+_ap");
DEBUGLOG(("IsValid: Target = [%s]\n", csTarget));

	iRet = regcomp(&rePreg, csPattern, REG_EXTENDED | REG_ICASE);

	if (iRet != SUCCESS)
		return PD_ERR;

	iStatus = regexec(&rePreg, csTarget, sMatch, reResult, 0);

	if (iStatus == REG_NOMATCH)
	{
DEBUGLOG(("IsValid: Invalid characters within the target = [%s]\n", csTarget));
	}
	else if (iStatus == 0)
	{
DEBUGLOG(("IsValid: Valid target = [%s]\n", csTarget));
	}
	else
	{
		char csErrorMsg[256];

		regerror(iStatus, &rePreg, csErrorMsg, sizeof(csErrorMsg));
DEBUGLOG(("IsValid: Error meessage = [%s]\n", csErrorMsg));
	}

	regfree(&rePreg);

	return PD_OK;
}

int GetByTxnCode(const char * csTxnCode, hash_t * hRec)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO getbytxncode_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;


		char		v_group;
		int		v_flag;
		double		v_value;
		/* varchar		v_remark[PD_REMARK_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;


		short		ind_group = -1;
		short		ind_flag = -1;
		short		ind_value = -1;
		short		ind_remark = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	/* txn_code */
	hv_txn_code.len = strlen(csTxnCode);
	memcpy(hv_txn_code.arr, csTxnCode, hv_txn_code.len);
DEBUGLOG(("GetByTxnCode: csTxnCode = [%.*s]\n", hv_txn_code.len, hv_txn_code.arr));

	/* EXEC SQL SELECT tz_group, 
			tz_flag, 
			tz_value, 
			tz_remark
		INTO	:v_group:ind_group, 
			:v_flag:ind_flag, 
			:v_value:ind_value, 
			:v_remark:ind_remark
		FROM test_zale
		WHERE tz_txn_code = :hv_txn_code; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select tz_group , tz_flag , tz_value , tz_remark INTO :b0:b\
1 , :b2:b3 , :b4:b5 , :b6:b7 FROM test_zale WHERE tz_txn_code = :b8 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )48;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_group;
 sqlstm.sqhstl[0] = (unsigned long )1;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_group;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_flag;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_flag;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_value;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_value;
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
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_code;
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
 if (sqlca.sqlcode < 0) goto getbytxncode_error;
}



	/* group */
	if (ind_group >= 0)
	{
DEBUGLOG(("GetByTxnCode group = [%c]\n", v_group));
		PutField_Char(hRec, "group", v_group);

		/* flag */
		if (ind_flag >= 0)
		{
DEBUGLOG(("GetByTxnCode flag = [%d]\n", v_flag));
			PutField_Int(hRec, "flag", v_flag); 
		}

		/* value */
		if (ind_value >= 0)
		{
DEBUGLOG(("GetByTxnCode value = [%lf]\n", v_value));
			PutField_Double(hRec, "value", v_value);
		}

		/* remark */
		if (ind_remark >= 0)
		{
			v_remark.arr[v_remark.len] = '\0';
DEBUGLOG(("GetByTxnCode remark = [%s]\n", v_remark.arr));
			PutField_CString(hRec, "remark", (const char *)v_remark.arr);
		}

DEBUGLOG(("GetByTxnCode Normal Exit\n"));
		return PD_FOUND;
	}
	else
	{
DEBUGLOG(("GetByTxnCode Not Found\n"));
		return PD_NOT_FOUND;
	}

getbytxncode_error:
DEBUGLOG(("getbytxncode_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int GetByGroup(const char cGroup, recordset_t * myRec)
{
	hash_t  * myHash;
	int	iCnt = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO getbygroup_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		char		hv_group;

		/* varchar		v_txn_code[PD_TXN_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

		int		v_flag;
		double		v_value;
		/* varchar		v_remark[PD_REMARK_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;


		short		ind_txn_code = -1;
		short		ind_flag = -1;
		short		ind_value = -1;
		short		ind_remark = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	/* group */
	hv_group = cGroup;
DEBUGLOG(("GetByGroup: cGroup = [%c]\n", hv_group));

	/* EXEC SQL DECLARE c_cursor_getbygroup CURSOR FOR 
		SELECT  tz_txn_code, 
			tz_flag, 
			tz_value, 
			tz_remark
		FROM test_zale
		WHERE tz_group = :hv_group; */ 


	/* EXEC SQL OPEN c_cursor_getbygroup; */ 

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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_group;
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
 if (sqlca.sqlcode < 0) goto getbygroup_error;
}


	do
	{
		/* EXEC SQL FETCH c_cursor_getbygroup
			INTO	:v_txn_code:ind_txn_code, 
				:v_flag:ind_flag, 
				:v_value:ind_value, 
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
  sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_code;
  sqlstm.sqhstl[0] = (unsigned long )6;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_txn_code;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_flag;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_flag;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_value;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_value;
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
  if (sqlca.sqlcode < 0) goto getbygroup_error;
}



		if (SQLCODE == SQL_NOT_FOUND)
			break;

		myHash = (hash_t *)malloc(sizeof(hash_t));
		hash_init(myHash, 0);

		/* txn_code */
		if (ind_txn_code >= 0)
		{
			v_txn_code.arr[v_txn_code.len] = '\0';
DEBUGLOG(("GetByGroup txn_code = [%s]\n", v_txn_code.arr));
			PutField_CString(myHash, "txn_code", (const char *)v_txn_code.arr);
		}

		/* flag */
		if (ind_flag >= 0)
		{
DEBUGLOG(("GetByGroup flag = [%d]\n", v_flag));
			PutField_Int(myHash, "flag", v_flag);
		}

		/* value */
		if (ind_value >= 0)
		{
DEBUGLOG(("GetByGroup value = [%lf]\n", v_value));
			PutField_Double(myHash, "value", v_value);
		}

		/* remark */
		if (ind_remark >= 0)
		{
			v_remark.arr[v_remark.len] = '\0';
DEBUGLOG(("GetByGroup remark = [%s]\n", v_remark.arr));
			PutField_CString(myHash, "remark", (const char *)v_remark.arr);
		}

		iCnt++;
		RecordSet_Add(myRec, myHash);
	} while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getbygroup; */ 

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
 if (sqlca.sqlcode < 0) goto getbygroup_error;
}



	if (iCnt > 0)
	{
DEBUGLOG(("GetByGroup Normal Exit\n"));
		return PD_FOUND;
	}
	else
	{
DEBUGLOG(("GetByGroup Normal Exit, Not Found\n"));
		return PD_NOT_FOUND;
	}

getbygroup_error:
DEBUGLOG(("getbygroup_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getbygroup; */ 

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

int Update(const hash_t * hRls)
{
	char	cTmp;
	char	* csTmp;
	char	* csTxnCode;
	double	dTmp = 0.0;
	int	iTmp = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));

	csTmp = (char *)malloc(128);

	strcpy((char *)hv_dynstmt.arr, "UPDATE test_zale SET tz_update_timestamp = SYSDATE");
	hv_dynstmt.len = strlen((const char *)hv_dynstmt.arr);

	/* txn_code */
	if (GetField_CString(hRls, "txn_code", &csTxnCode))
	{
DEBUGLOG(("Update: txn_code = [%s]\n", csTxnCode));
	}
	else
	{
		FREE_ME(csTmp);
DEBUGLOG(("Update txn_code not found\n"));

		return INT_ERR;
	}

	/* group */
	if (GetField_Char(hRls, "group", &cTmp))
	{
		sprintf(csTmp, "%c", cTmp);
		strcat((char *)hv_dynstmt.arr, ", tz_group = '");
		strcat((char *)hv_dynstmt.arr, csTmp);
		strcat((char *)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("Update: group = [%c]\n", cTmp));
	}

	/* flag */
	if (GetField_Int(hRls, "flag", &iTmp))
	{
		sprintf(csTmp, "%d", iTmp);
		strcat((char *)hv_dynstmt.arr, ", tz_flag = ");
		strcat((char *)hv_dynstmt.arr, csTmp);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("Update: flag = [%d]\n", iTmp));
	}

	/* value */
	if (GetField_Double(hRls, "value", &dTmp))
	{
		sprintf(csTmp, "%lf", dTmp);
		strcat((char *)hv_dynstmt.arr, ", tz_value = ");
		strcat((char *)hv_dynstmt.arr, csTmp);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("Update: value = [%lf]\n", dTmp));
	}

	/* remark */
	if (GetField_CString(hRls, "remark", &csTmp))
	{
		strcat((char *)hv_dynstmt.arr, ", tz_remark = '");
		strcat((char *)hv_dynstmt.arr, csTmp);
		strcat((char *)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("Update: remark = [%s]\n", csTmp));
	}

	/* update_user */
	if (GetField_CString(hRls, "create_user", &csTmp))
	{
		strcat((char *)hv_dynstmt.arr, ", tz_update_user = '");
		strcat((char *)hv_dynstmt.arr, csTmp);
		strcat((char *)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("Update: update_user = [%s]\n", csTmp));
	}

	strcat((char *)hv_dynstmt.arr, " WHERE tz_txn_code = '");
	strcat((char *)hv_dynstmt.arr, csTxnCode);
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

ERRLOG("TestZale_Update: SP_INTERNAL_ERR\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR\n"));
	return PD_INTERNAL_ERR;
}

int UpdateReturn(const hash_t * hIn, hash_t * hOut)
{
	char	* csTxnCode;
	double	dValue = 0.0;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_return_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

		double		hv_value;

		char		v_group;
		int		v_flag;
		double		v_value;
		/* varchar		v_remark[PD_REMARK_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } v_remark;


		short		ind_txn_code = -1;
		short		ind_group = -1;
		short		ind_flag = -1;
		short		ind_i_value = -1;
		short		ind_o_value = -1;
		short		ind_remark = -1;

		short		hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateReturn: Begin\n"));

	/* txn_code */
	if (GetField_CString(hIn, "txn_code", &csTxnCode))
	{
		hv_txn_code.len = strlen(csTxnCode);
		memcpy(hv_txn_code.arr, csTxnCode, hv_txn_code.len);
		strncpy((char *)hv_txn_code.arr, csTxnCode, hv_txn_code.len);
		ind_txn_code = 0;

DEBUGLOG(("UpdateReturn: txn_code = [%.*s]\n", hv_txn_code.len, hv_txn_code.arr));
	}
	else
	{
DEBUGLOG(("UpdateReturn txn_code not found\n"));

		return INT_ERR;
	}

	/* value */
	if (GetField_Double(hIn, "value", &dValue))
	{
		hv_value = dValue;
		ind_i_value = 0;

DEBUGLOG(("UpdateReturn: value = [%lf]\n", hv_value));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_test_zale_update_return(
				:hv_txn_code:ind_txn_code, 
				:hv_value:ind_i_value, 
				:v_group:ind_group, 
				:v_flag:ind_flag, 
				:v_value:ind_o_value, 
				:v_remark:ind_remark);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_test_zale_update_return ( :hv_\
txn_code:ind_txn_code , :hv_value:ind_i_value , :v_group:ind_group , :v_flag:\
ind_flag , :v_value:ind_o_value , :v_remark:ind_remark ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )197;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_code;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_txn_code;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_value;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_i_value;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&v_group;
 sqlstm.sqhstl[3] = (unsigned long )1;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_group;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&v_flag;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_flag;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&v_value;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_o_value;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&v_remark;
 sqlstm.sqhstl[6] = (unsigned long )257;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_remark;
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
 if (sqlca.sqlcode < 0) goto update_return_error;
}



DEBUGLOG(("UpdateReturn: Ret = [%d]\n", hv_return_value));

	if (hv_return_value == SP_OK)
	{
		if (ind_group >= 0)
		{
DEBUGLOG(("UpdateReturn group = [%c]\n", v_group));
			PutField_Char(hOut, "group", v_group);
		}

		/* flag */
		if (ind_flag >= 0)
		{
DEBUGLOG(("UpdateReturn flag = [%d]\n", v_flag));
			PutField_Int(hOut, "flag", v_flag); 
		}

		/* value */
		if (ind_o_value >= 0)
		{
DEBUGLOG(("UpdateReturn value = [%lf]\n", v_value));
			PutField_Double(hOut, "value", v_value);
		}

		/* remark */
		if (ind_remark >= 0)
		{
			v_remark.arr[v_remark.len] = '\0';
DEBUGLOG(("UpdateReturn remark = [%s]\n", v_remark.arr));
			PutField_CString(hOut, "remark", (const char *)v_remark.arr);
		}

DEBUGLOG(("UpdateReturn: Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)
	{
ERRLOG("TestZale_UpdateReturn: SP_OTHER_ERR\n");
DEBUGLOG(("UpdateReturn: SP_OTHER_ERR\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)
	{
ERRLOG("TestZale_UpdateReturn: SP_ERR\n");
DEBUGLOG(("UpdateReturn: SP_ERR\n"));
		return PD_ERR;
	}

update_return_error:
DEBUGLOG(("update_return_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("TestZale_UpdateReturn: SP_INTERNAL_ERR\n");
DEBUGLOG(("UpdateReturn: SP_INTERNAL_ERR\n"));
	return PD_INTERNAL_ERR;
}

int UpdateReturnCursor(const hash_t * hIn, hash_t * hOut)
{
	char	* csTxnCode;
	double	dValue = 0.0;
	int	iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_return_cursor_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

		double		hv_value;

		SQL_CURSOR	v_cursor;
		/* sp_test_update_return_c2 */
		/*
		struct
		{
			char	v_group;
			int	v_flag;
			double	v_value;
			varchar	v_remark[PD_REMARK_LEN];
		} updated_info;
		*/
		/* sp_test_update_return_c3 */
		char		v_group;
		int			v_flag;
		double		v_value;
		/* varchar		v_remark[PD_REMARK_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } v_remark;


		short		ind_txn_code = -1;
		short		ind_value = -1;
		/* sp_test_update_return_c2 */
		/*
		struct
		{
			short	ind_group;
			short	ind_flag;
			short	ind_value;
			short	ind_remark;
		} updated_info_ind;
		*/
		/* sp_test_update_return_c3 */
		short		ind_group = -1;
		short		ind_flag = -1;
		short		ind_o_value = -1;
		short		ind_remark = -1;

		short		hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateReturnCursor: Begin\n"));

	/* txn_code */
	if (GetField_CString(hIn, "txn_code", &csTxnCode))
	{
		hv_txn_code.len = strlen(csTxnCode);
		memcpy(hv_txn_code.arr, csTxnCode, hv_txn_code.len);
		strncpy((char *)hv_txn_code.arr, csTxnCode, hv_txn_code.len);
		ind_txn_code = 0;

DEBUGLOG(("UpdateReturnCursor: txn_code = [%.*s]\n", hv_txn_code.len, hv_txn_code.arr));
	}
	else
	{
DEBUGLOG(("UpdateReturnCursor txn_code not found\n"));

		return INT_ERR;
	}

	/* value */
	if (GetField_Double(hIn, "value", &dValue))
	{
		hv_value = dValue;
		ind_value = 0;

DEBUGLOG(("UpdateReturnCursor: value = [%lf]\n", hv_value));
	}

	/* Allocate the cursor variable */
	/* EXEC SQL ALLOCATE :v_cursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )240;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cursor;
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
 if (sqlca.sqlcode < 0) goto update_return_cursor_error;
}



	/* EXEC SQL EXECUTE
		BEGIN
//			:hv_return_value := sp_test_zale_update_return_c2(
			:hv_return_value := sp_test_zale_update_return_c3(
				:hv_txn_code:ind_txn_code, 
				:hv_value:ind_value, 
				:v_cursor);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_test_zale_update_return_c3 ( :\
hv_txn_code:ind_txn_code , :hv_value:ind_value , :v_cursor ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )259;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_code;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_txn_code;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_value;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_value;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&v_cursor;
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
 if (sqlca.sqlcode < 0) goto update_return_cursor_error;
}



DEBUGLOG(("UpdateReturnCursor: Ret = [%d]\n", hv_return_value));

	if (hv_return_value == SP_OK)
	{
		/* sp_test_update_return_c2 */
		/*
		EXEC SQL FETCH :v_cursor 
			INTO :updated_info:updated_info_ind;
		*/
		/* sp_test_update_return_c3 */
		/* EXEC SQL FETCH :v_cursor 
			INTO	:v_group:ind_group, 
					:v_flag:ind_flag, 
					:v_value:ind_o_value, 
					:v_remark:ind_remark; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )290;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_cursor;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_group;
  sqlstm.sqhstl[1] = (unsigned long )1;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_group;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_flag;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_flag;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_value;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_o_value;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_remark;
  sqlstm.sqhstl[4] = (unsigned long )257;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_remark;
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
  if (sqlca.sqlcode < 0) goto update_return_cursor_error;
}



		/* sp_test_update_return_c2 */
		/* group */
		/*
		if (updated_info_ind.ind_group >= 0)
		{
DEBUGLOG(("UpdateReturnCursor group = [%c]\n", updated_info.v_group));
			PutField_Char(hOut, "group", updated_info.v_group);
		}
		*/
		/* flag */
		/*
		if (updated_info_ind.ind_flag >= 0)
		{
DEBUGLOG(("UpdateReturnCursor flag = [%d]\n", updated_info.v_flag));
			PutField_Int(hOut, "flag", updated_info.v_flag); 
		}
		*/
		/* value */
		/*
		if (updated_info_ind.ind_value >= 0)
		{
DEBUGLOG(("UpdateReturn value = [%lf]\n", updated_info.v_value));
			PutField_Double(hOut, "value", updated_info.v_value);
		}
		*/
		/* remark */
		/*
		if (updated_info_ind.ind_remark >= 0)
		{
			updated_info.v_remark.arr[updated_info.v_remark.len] = '\0';
DEBUGLOG(("UpdateReturn remark = [%s]\n", updated_info.v_remark.arr));
			PutField_CString(hOut, "remark", (const char *)(updated_info.v_remark.arr));
		}
		*/
		/* sp_test_update_return_c3 */
		/* group */
		if (ind_group >= 0)
		{
DEBUGLOG(("UpdateReturnCursor group = [%c]\n", v_group));
			PutField_Char(hOut, "group", v_group);
		}

		/* flag */
		if (ind_flag >= 0)
		{
DEBUGLOG(("UpdateReturnCursor flag = [%d]\n", v_flag));
			PutField_Int(hOut, "flag", v_flag); 
		}

		/* value */

		if (ind_o_value >= 0)
		{
DEBUGLOG(("UpdateReturn value = [%lf]\n", v_value));
			PutField_Double(hOut, "value", v_value);
		}

		/* remark */
		if (ind_remark >= 0)
		{
			v_remark.arr[v_remark.len] = '\0';
DEBUGLOG(("UpdateReturn remark = [%s]\n", v_remark.arr));
			PutField_CString(hOut, "remark", (const char *)(v_remark.arr));
		}

DEBUGLOG(("UpdateReturnCursor: Normal Exit\n"));
		iRet = PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)
	{
ERRLOG("TestZale_UpdateReturnCursor: SP_OTHER_ERR\n");
DEBUGLOG(("UpdateReturnCursor: SP_OTHER_ERR\n"));
		iRet = PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)
	{
ERRLOG("TestZale_UpdateReturnCursor: SP_ERR\n");
DEBUGLOG(("UpdateReturnCursor: SP_ERR\n"));
		iRet =  PD_ERR;
	}

	/* Close and free the cursor */
	/* EXEC SQL CLOSE :v_cursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )325;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cursor;
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
 if (sqlca.sqlcode < 0) goto update_return_cursor_error;
}


	/* EXEC SQL FREE :v_cursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )344;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cursor;
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
 if (sqlca.sqlcode < 0) goto update_return_cursor_error;
}



	return iRet;

update_return_cursor_error:
DEBUGLOG(("update_return_cursor_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE :v_cursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )363;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cursor;
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


	/* EXEC SQL FREE :v_cursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )382;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cursor;
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


ERRLOG("TestZale_UpdateReturnCursor: SP_INTERNAL_ERR\n");
DEBUGLOG(("UpdateReturnCursor: SP_INTERNAL_ERR\n"));
	return PD_INTERNAL_ERR;
}
