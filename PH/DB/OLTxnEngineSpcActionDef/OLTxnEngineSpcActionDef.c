
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
           char  filnam[31];
};
static struct sqlcxp sqlfpn =
{
    30,
    "OLTxnEngineSpecialActionDef.pc"
};


static unsigned int sqlctx = 866258789;


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
"SELECT ESAD_SPECIAL_ACTION_DETAIL_ID , ESAD_SPECIAL_ACTION_DESC , ESAD_RETU\
RNED_TAG , ESAD_RETURNED_VALUE FROM OL_TXN_ENGINE_SPC_ACT_DEF WHERE ESAD_SPEC\
IAL_ACTION_DETAIL_ID = :b0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,190,0,9,77,0,2049,1,1,0,1,0,1,3,0,0,
24,0,0,1,0,0,13,80,0,0,4,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,
55,0,0,1,0,0,15,122,0,0,0,0,0,1,0,
70,0,0,1,0,0,15,141,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/12/03              Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "internal.h"
#include "dbutility.h"
#include "OLTxnEngineSpecialActionDef.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char    cDebug;

void OLTxnEngineSpcActionDef(char cdebug)
{
        cDebug = cdebug;
}

int GetTxnEngineSpcActionDef(const hash_t *hRls, recordset_t *myRec)
{
	int iRet = PD_OK;

	int iTmp = 0;
	int iCnt = 0;

	hash_t *myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO gettxnengspcactiondef_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int	hv_action_detail_id;

		int	v_action_detail_id;
		/* varchar v_action_desc[PD_DESC_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_action_desc;

		/* varchar	v_returned_tag[PD_TAG_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_returned_tag;

		int	v_returned_value;

		short	ind_action_detail_id = -1;
		short	ind_action_desc = -1;
		short	ind_returned_tag = -1;
		short	ind_returned_value = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


// spc_action_detail_id
	if (GetField_CString(hRls, "spc_action_detail_id", &iTmp)) {
		hv_action_detail_id = iTmp;
DEBUGLOG(("GetTxnEngineSpcActionDef:: spc_action_detail_id = [%s]\n", hv_action_detail_id));
	} else {
DEBUGLOG(("GetTxnEngineSpcActionDef:: spc_action_detail_id not found!\n"));
		iRet = INT_ERR;
	}

	/* EXEC SQL DECLARE c_gettxnengspcactiondef CURSOR FOR
		SELECT	ESAD_SPECIAL_ACTION_DETAIL_ID,
			ESAD_SPECIAL_ACTION_DESC,
			ESAD_RETURNED_TAG,
			ESAD_RETURNED_VALUE
		FROM	OL_TXN_ENGINE_SPC_ACT_DEF
		WHERE	ESAD_SPECIAL_ACTION_DETAIL_ID = :hv_action_detail_id; */ 


	if (iRet == PD_OK) {
		/* EXEC SQL OPEN c_gettxnengspcactiondef; */ 

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
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_action_detail_id;
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
  if (sqlca.sqlcode < 0) goto gettxnengspcactiondef_error;
}



		for (;;) {
			/* EXEC SQL FETCH c_gettxnengspcactiondef
			INTO	:v_action_detail_id:ind_action_detail_id,
				:v_action_desc:ind_action_desc,
				:v_returned_tag:ind_returned_tag,
				:v_returned_value:ind_returned_value; */ 

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
   sqlstm.sqhstv[0] = (unsigned char  *)&v_action_detail_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_action_detail_id;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_action_desc;
   sqlstm.sqhstl[1] = (unsigned long )53;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_action_desc;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_returned_tag;
   sqlstm.sqhstl[2] = (unsigned long )28;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_returned_tag;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_returned_value;
   sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_returned_value;
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
   if (sqlca.sqlcode < 0) goto gettxnengspcactiondef_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			iCnt++;
			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash, 0);

/* spc_action_detail_id */
			if (ind_action_detail_id >= 0) {
				PutField_Int(myHash, "spc_action_detail_id", v_action_detail_id);
DEBUGLOG(("GetTxnEngineSpcActionDef:: spc_action_detail_id = [%d]\n", v_action_detail_id));
			}

/* spc_action_desc */
                        if (ind_action_desc >= 0) {
                                v_action_desc.arr[v_action_desc.len] = '\0';
                                PutField_CString(myHash, "spc_action_desc", (const char*)v_action_desc.arr);
DEBUGLOG(("GetTxnEngineSpcActionDef:: spc_action_desc = [%s]\n", v_action_desc.arr));
                        }

/* returned_tag */
			if (ind_returned_tag >= 0) {
				v_returned_tag.arr[v_returned_tag.len] = '\0';
				PutField_CString(myHash, "returned_tag", (const char*)v_returned_tag.arr);
DEBUGLOG(("GetTxnEngineSpcActionDef:: returned_tag = [%s]\n", v_returned_tag.arr));
			}

/* returned_value */
			if (ind_returned_value >= 0) {
				PutField_Int(myHash, "returned_value", v_returned_value);
DEBUGLOG(("GetTxnEngineSpcActionDef:: returned_value = [%d]\n", v_returned_value));
			}

			RecordSet_Add(myRec, myHash);
		}
		/* EXEC SQL CLOSE c_gettxnengspcactiondef; */ 

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
  if (sqlca.sqlcode < 0) goto gettxnengspcactiondef_error;
}



		if (iCnt > 0) {
DEBUGLOG(("GetTxnEngineSpcActionDef:: hash added\n"));
		} else {
DEBUGLOG(("GetTxnEngineSpcActionDef:: no record found\n"));
ERRLOG("OLTxnEngineSpecialActionDef:: GetTxnEngineSpcActionDef:: no record found\n");
			iRet = PD_ERR;
		}
	}

DEBUGLOG(("GetTxnEngineSpcActionDef:: Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

gettxnengspcactiondef_error:
DEBUGLOG(("gettxnengspcactiondef_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLTxnEngineSpecialActionDef:: gettxnengspcactiondef_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL CLOSE c_gettxnengspcactiondef; */ 

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
 if (sqlca.sqlcode < 0) goto gettxnengspcactiondef_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

