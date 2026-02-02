
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
           char  filnam[21];
};
static struct sqlcxp sqlfpn =
{
    20,
    "EmailFunctExclude.pc"
};


static unsigned int sqlctx = 74617123;


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
   unsigned char  *sqhstv[4];
   unsigned long  sqhstl[4];
            int   sqhsts[4];
            short *sqindv[4];
            int   sqinds[4];
   unsigned long  sqharm[4];
   unsigned long  *sqharc[4];
   unsigned short  sqadto[4];
   unsigned short  sqtdso[4];
} sqlstm = {12,4};

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

 static char *sq0001 = 
"SELECT EFE_TAGNAME , EFE_TYPE , EFE_OPERATOR , EFE_VALUE FROM EMAIL_FUNCT_E\
XCLUDE WHERE EFE_FUNCT = :b0 ORDER BY EFE_TAGNAME , EFE_TYPE , EFE_OPERATOR  \
          ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,162,0,9,71,0,2049,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,13,73,0,0,4,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
55,0,0,1,0,0,15,126,0,0,0,0,0,1,0,
70,0,0,1,0,0,15,134,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/11/03              Stan Poon
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlca.h>
#include "common.h"
#include "internal.h"
#include "utilitys.h"
#include "dbutility.h"
#include "EmailFunctExclude.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char	cDebug;

void EmailFunctExclude(char	cdebug)
{
	cDebug = cdebug;
}


int GetFunctExclude(const hash_t *hRls, recordset_t *myRec)
{
	int iRet = NOT_FOUND;
	char *csTmp;

	hash_t *hRec;

	/* EXEC SQL WHENEVER SQLERROR GOTO getexclude_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_funct[PD_EML_FUNCT_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_funct;

		/* varchar	v_tagname[PD_EML_TAGNAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_tagname;

		/* varchar	v_type[PD_EML_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_type;

		/* varchar	v_operator[PD_EML_OPERATOR_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_operator;

		/* varchar	v_value[PD_EML_VALUE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_value;


		short	ind_tagname = -1;
		short	ind_type = -1;
		short	ind_operator = -1;
		short	ind_value = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls,"funct",&csTmp)) {
		hv_funct.len = strlen(csTmp);
		strncpy((char*)hv_funct.arr, csTmp, hv_funct.len);
DEBUGLOG(("GetFunctExclude funct = [%.*s]\n", hv_funct.len, hv_funct.arr));
	}

	/* EXEC SQL DECLARE getfunctexclude CURSOR FOR
		SELECT	EFE_TAGNAME,
			EFE_TYPE,
			EFE_OPERATOR,
			EFE_VALUE
		FROM	EMAIL_FUNCT_EXCLUDE
		WHERE	EFE_FUNCT = :hv_funct
		ORDER BY EFE_TAGNAME, EFE_TYPE, EFE_OPERATOR; */ 


	/* EXEC SQL OPEN getfunctexclude; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0001;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_funct;
 sqlstm.sqhstl[0] = (unsigned long )17;
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
 if (sqlca.sqlcode < 0) goto getexclude_error;
}


	for (;;) {
		/* EXEC SQL FETCH getfunctexclude
		INTO	:v_tagname:ind_tagname,
			:v_type:ind_type,
			:v_operator:ind_operator,
			:v_value:ind_value; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )24;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_tagname;
  sqlstm.sqhstl[0] = (unsigned long )53;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_tagname;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_type;
  sqlstm.sqhstl[1] = (unsigned long )23;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_type;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_operator;
  sqlstm.sqhstl[2] = (unsigned long )5;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_operator;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_value;
  sqlstm.sqhstl[3] = (unsigned long )53;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_value;
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
  if (sqlca.sqlcode < 0) goto getexclude_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iRet = FOUND;

		hRec = (hash_t*) malloc (sizeof(hash_t));
		hash_init(hRec, 0);

		if (ind_tagname >= 0) {
			v_tagname.arr[v_tagname.len]='\0';
			PutField_CString(hRec,"tagname",(char*)v_tagname.arr);
DEBUGLOG(("GetFunctExclude() tagname = [%s]\n",(char*)v_tagname.arr));
		} else {
			iRet = PD_ERR;
DEBUGLOG(("GetFunctExclude() tagname NOT FOUND!!!\n"));
		}

		if (ind_type >= 0) {
			v_type.arr[v_type.len]='\0';
			PutField_CString(hRec,"type",(char*)v_type.arr);
DEBUGLOG(("GetFunctExclude() type = [%s]\n",(char*)v_type.arr));
		} else {
			iRet = PD_ERR;
DEBUGLOG(("GetFunctExclude() type NOT FOUND!!!\n"));
		}

		if (ind_operator >= 0) {
			v_operator.arr[v_operator.len]='\0';
			PutField_CString(hRec,"operator",(char*)v_operator.arr);
DEBUGLOG(("GetFunctExclude() operator = [%s]\n",(char*)v_operator.arr));
		} else {
			iRet = PD_ERR;
DEBUGLOG(("GetFunctExclude() operator NOT FOUND!!!\n"));
		}

		if (ind_value >= 0) {
			v_value.arr[v_value.len]='\0';
			PutField_CString(hRec,"value",(char*)v_value.arr);
DEBUGLOG(("GetFunctExclude() value = [%s]\n",(char*)v_value.arr));
		} else {
			iRet = PD_ERR;
DEBUGLOG(("GetFunctExclude() value NOT FOUND!!!\n"));
		}

		RecordSet_Add(myRec,hRec);
	}
	/* EXEC SQL CLOSE getfunctexclude; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )55;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getexclude_error;
}



DEBUGLOG(("GetFunctExclude() Normal Exit iRet = [%d]\n",iRet));
	return iRet;

getexclude_error:
DEBUGLOG(("getexclude_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL CLOSE getfunctexclude; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )70;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getexclude_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

