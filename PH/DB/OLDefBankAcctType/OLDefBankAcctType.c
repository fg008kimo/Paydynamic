
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
    "OLDefBankAcctType.pc"
};


static unsigned int sqlctx = 79296483;


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
   unsigned char  *sqhstv[2];
   unsigned long  sqhstl[2];
            int   sqhsts[2];
            short *sqindv[2];
            int   sqinds[2];
   unsigned long  sqharm[2];
   unsigned long  *sqharc[2];
   unsigned short  sqadto[2];
   unsigned short  sqtdso[2];
} sqlstm = {12,2};

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

 static char *sq0002 = 
"select obc_type , obc_display_name from ol_def_bank_acct_type where obc_fe_\
display = 1 order by obc_type            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,86,0,4,49,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
28,0,0,2,116,0,9,105,0,2049,0,0,0,1,0,
43,0,0,2,0,0,13,108,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
66,0,0,2,0,0,15,135,0,0,0,0,0,1,0,
81,0,0,2,0,0,15,146,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/06/19              David Wong
Add function "GetAllFEDisplay"			   2016/07/19		   Dirk Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "OLDefBankAcctType.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char cDebug;

void OLDefBankAcctType(char cdebug)
{
	cDebug = cdebug;
}


int GetBaidNameCode(const unsigned char* csType, hash_t *hRec)
{
	int iRet = NOT_FOUND;

	/* EXEC SQL WHENEVER SQLERROR GOTO baidnamecode_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_type[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_type;

		/* varchar v_baid_name_code[PD_ACCT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_baid_name_code;

		short ind_baid_name_code = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_type.len = strlen((const char*)csType);
	memcpy(hv_type.arr, csType, hv_type.len);
DEBUGLOG(("GetBaidNameCode: type = [%.*s]\n", hv_type.len, hv_type.arr));

	/* EXEC SQL
		select obc_baid_name_code
		into :v_baid_name_code:ind_baid_name_code
		from ol_def_bank_acct_type
		where obc_type = :hv_type; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select obc_baid_name_code into :b0:b1 from ol_def_bank_acct\
_type where obc_type = :b2 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_baid_name_code;
 sqlstm.sqhstl[0] = (unsigned long )6;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_baid_name_code;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_type;
 sqlstm.sqhstl[1] = (unsigned long )5;
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
 if (sqlca.sqlcode < 0) goto baidnamecode_error;
}



	if (ind_baid_name_code >= 0) {
		v_baid_name_code.arr[v_baid_name_code.len] = '\0';
		PutField_CString(hRec, "baid_name_code", (const char*)v_baid_name_code.arr);
DEBUGLOG(("GetBaidNameCode: baid_name_code = [%s]\n", v_baid_name_code.arr));
		iRet = FOUND;
	}

	if (iRet == FOUND) {
DEBUGLOG(("GetBaidNameCode success [%d]\n", iRet));
	} else{
DEBUGLOG(("GetBaidNameCode failed [%d]\n", iRet));
	}

	return iRet;

baidnamecode_error:
DEBUGLOG(("baidnamecode_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLDefBankAcctType:: baidnamecode_error code %d\n", sqlca.sqlcode);
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return NOT_FOUND;
}


int GetAllFEDisplay(recordset_t* rRecordSet)
{
	int iRet = PD_OK;

	hash_t *myHash;
	
	/* EXEC SQL WHENEVER SQLERROR GOTO getallfedisplay_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 



	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar v_acct_type[PD_ACCT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_acct_type;

		/* varchar	v_display_name[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_display_name;


		short	ind_acct_type = -1;
		short	ind_display_name = -1;
	/* EXEC SQL END DECLARE SECTION; */ 



	/* EXEC SQL DECLARE c_cursor_getallfedisplay CURSOR FOR
		select	obc_type,
			obc_display_name
		  from	ol_def_bank_acct_type
		 where	obc_fe_display = 1
		order by
			obc_type; */ 

	/* EXEC SQL OPEN c_cursor_getallfedisplay; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )28;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getallfedisplay_error;
}



	for (;;) {
		/* EXEC SQL FETCH c_cursor_getallfedisplay
		INTO	:v_acct_type:ind_acct_type,
			:v_display_name:ind_display_name; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 2;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )43;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_acct_type;
  sqlstm.sqhstl[0] = (unsigned long )6;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_acct_type;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_display_name;
  sqlstm.sqhstl[1] = (unsigned long )53;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_display_name;
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
  if (sqlca.sqlcode < 0) goto getallfedisplay_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash, 0);

		if (ind_acct_type >= 0) {
			v_acct_type.arr[v_acct_type.len] = '\0';
			PutField_CString(myHash, "acct_type", (const char*)v_acct_type.arr);
DEBUGLOG(("GetAllFEDisplay: acct_type = [%s]\n", v_acct_type.arr));
		}

		if (ind_display_name >= 0) {
			v_display_name.arr[v_display_name.len] = '\0';
			PutField_CString(myHash, "display_name", (const char*)v_display_name.arr);
DEBUGLOG(("GetAllFEDisplay: display_name = [%s]\n", v_display_name.arr));
		}

		RecordSet_Add(rRecordSet, myHash);

	}

	/* EXEC SQL CLOSE c_cursor_getallfedisplay; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )66;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getallfedisplay_error;
}



DEBUGLOG(("GetAllFEDisplay normal exit! iRet = [%d]\n", iRet));

	return iRet;


getallfedisplay_error:
DEBUGLOG(("getallfedisplay_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLDefBankAcctType:: getallfedisplay_error code %d\n", sqlca.sqlcode);
	/* EXEC SQL CLOSE c_cursor_getallfedisplay; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )81;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getallfedisplay_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;

}

