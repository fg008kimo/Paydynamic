
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
           char  filnam[23];
};
static struct sqlcxp sqlfpn =
{
    22,
    "OLStmtConvertScript.pc"
};


static unsigned int sqlctx = 331289435;


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
   unsigned char  *sqhstv[8];
   unsigned long  sqhstl[8];
            int   sqhsts[8];
            short *sqindv[8];
            int   sqinds[8];
   unsigned long  sqharm[8];
   unsigned long  *sqharc[8];
   unsigned short  sqadto[8];
   unsigned short  sqtdso[8];
} sqlstm = {12,8};

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
5,0,0,1,437,0,4,61,0,0,8,4,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2013. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/07/17              Stan Poon
Add file ext                                       2013/07/23              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "OLStmtConvertScript.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char cDebug;

void OLStmtConvertScript(char cdebug)
{
	cDebug = cdebug;
}


int GetConvertInfo(const char* csIntBankCode, const char* csInFileExt, char* csScriptName, char* csInFileEncoding, char* csInFilePrefix, char* csInFileCountry)
{
	int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO getconvertinfo_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar hv_in_file_ext[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_in_file_ext;

		/* varchar v_script_name[PD_SCRIPT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_script_name;

		/* varchar v_in_file_encoding[PD_IN_FILE_ENCODING_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_in_file_encoding;

		/* varchar v_in_file_prefix[PD_IN_FILE_PREFIX_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_in_file_prefix;

		/* varchar v_in_file_country[PD_IN_FILE_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_in_file_country;


		short ind_script_name = -1;
		short ind_in_file_encoding = -1;
		short ind_in_file_prefix = -1;
		short ind_in_file_country = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_int_bank_code.len = strlen((const char*)csIntBankCode);
	memcpy(hv_int_bank_code.arr, csIntBankCode, hv_int_bank_code.len);
DEBUGLOG(("GetConvertInfo() int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));

	hv_in_file_ext.len = strlen((const char*)csInFileExt);
	memcpy(hv_in_file_ext.arr, csInFileExt, hv_in_file_ext.len);
DEBUGLOG(("GetConvertInfo() in_file_ext = [%.*s]\n", hv_in_file_ext.len, hv_in_file_ext.arr));

	/* EXEC SQL
		SELECT	OLCS_SCRIPT_NAME,
			OLCS_IN_FILE_ENCODING,
			OLCS_IN_FILE_PREFIX,
			OLCS_IN_FILE_COUNTRY
		INTO	:v_script_name:ind_script_name,
			:v_in_file_encoding:ind_in_file_encoding,
			:v_in_file_prefix:ind_in_file_prefix,
			:v_in_file_country:ind_in_file_country
		FROM	OL_STMT_CONVERT_SCRIPT
		WHERE	OLCS_INT_BANK_CODE = :hv_int_bank_code
		AND	OLCS_IN_FILE_EXT = LOWER(:hv_in_file_ext)
		AND	OLCS_EFFECT_TIMESTAMP = (SELECT	MAX(OLCS_EFFECT_TIMESTAMP)
						FROM	OL_STMT_CONVERT_SCRIPT
						WHERE	OLCS_INT_BANK_CODE = :hv_int_bank_code
						AND	OLCS_IN_FILE_EXT = LOWER(:hv_in_file_ext)
						AND	OLCS_DISABLED = 0)
		AND	OLCS_DISABLED = 0; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select OLCS_SCRIPT_NAME , OLCS_IN_FILE_ENCODING , OLCS_IN_F\
ILE_PREFIX , OLCS_IN_FILE_COUNTRY INTO :b0:b1 , :b2:b3 , :b4:b5 , :b6:b7 FROM\
 OL_STMT_CONVERT_SCRIPT WHERE OLCS_INT_BANK_CODE = :b8 AND OLCS_IN_FILE_EXT =\
 LOWER ( :b9 ) AND OLCS_EFFECT_TIMESTAMP = ( SELECT MAX ( OLCS_EFFECT_TIMESTA\
MP ) FROM OL_STMT_CONVERT_SCRIPT WHERE OLCS_INT_BANK_CODE = :b8 AND OLCS_IN_F\
ILE_EXT = LOWER ( :b9 ) AND OLCS_DISABLED = 0 ) AND OLCS_DISABLED = 0 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_script_name;
 sqlstm.sqhstl[0] = (unsigned long )53;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_script_name;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_in_file_encoding;
 sqlstm.sqhstl[1] = (unsigned long )13;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_in_file_encoding;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_in_file_prefix;
 sqlstm.sqhstl[2] = (unsigned long )13;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_in_file_prefix;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&v_in_file_country;
 sqlstm.sqhstl[3] = (unsigned long )13;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_in_file_country;
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
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_in_file_ext;
 sqlstm.sqhstl[5] = (unsigned long )5;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[6] = (unsigned long )12;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_in_file_ext;
 sqlstm.sqhstl[7] = (unsigned long )5;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto getconvertinfo_error;
}



// script_name
	if (ind_script_name >= 0) {
		v_script_name.arr[v_script_name.len] = '\0';
		strcpy(csScriptName, (char*)v_script_name.arr);
DEBUGLOG(("GetConvertInfo() script_name = [%s]\n", v_script_name.arr));
	} else {
		iRet = PD_ERR;
DEBUGLOG(("GetConvertInfo() script_name not found!\n"));
ERRLOG("OLStmtConvertScript::GetConvertInfo() script_name not found!\n");
	}

// in_file_encoding
	if (iRet == PD_OK) {
		if (ind_in_file_encoding >= 0) {
			v_in_file_encoding.arr[v_in_file_encoding.len] = '\0';
			strcpy(csInFileEncoding, (char*)v_in_file_encoding.arr);
DEBUGLOG(("GetConvertInfo() in_file_encoding = [%s]\n", v_in_file_encoding.arr));
		} else {
			iRet = PD_ERR;
DEBUGLOG(("GetConvertInfo() in_file_encoding not found!\n"));
ERRLOG("OLStmtConvertScript::GetConvertInfo() in_file_encoding not found!\n");
		}
	}

// in_file_prefix
	if (iRet == PD_OK) {
		if (ind_in_file_prefix >= 0) {
			v_in_file_prefix.arr[v_in_file_prefix.len] = '\0';
			strcpy(csInFilePrefix, (char*)v_in_file_prefix.arr);
DEBUGLOG(("GetConvertInfo() in_file_prefix = [%s]\n", v_in_file_prefix.arr));
		} else {
			iRet = PD_ERR;
DEBUGLOG(("GetConvertInfo() in_file_prefix not found!\n"));
ERRLOG("OLStmtConvertScript::GetConvertInfo() in_file_prefix not found!\n");
		}
	}

// in_file_country
	if (iRet == PD_OK) {
		if (ind_in_file_country >= 0) {
			v_in_file_country.arr[v_in_file_country.len] = '\0';
			strcpy(csInFileCountry, (char*)v_in_file_country.arr);
DEBUGLOG(("GetConvertInfo() in_file_country = [%s]\n", v_in_file_country.arr));
		} else {
			iRet = PD_ERR;
DEBUGLOG(("GetConvertInfo() in_file_country not found!\n"));
ERRLOG("OLStmtConvertScript::GetConvertInfo() in_file_country not found!\n");
		}
	}

DEBUGLOG(("GetConvertInfo() Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getconvertinfo_error:
DEBUGLOG(("getconvertinfo_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStmtConvertScript getconvertinfo_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}
