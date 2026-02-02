
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
           char  filnam[28];
};
static struct sqlcxp sqlfpn =
{
    27,
    "OLTxnEngineSpecialAction.pc"
};


static unsigned int sqlctx = 2039201179;


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

 static char *sq0001 = 
"SELECT ESA_SPECIAL_ACTION_DETAIL_ID , ESA_SEQ , ESA_P1_CHECK_TAG , ESA_P2_C\
HECK_TAG , ESA_COMPARE_OPERATOR , ESA_EXPECTED_VALUE , ESA_CHECK_TYPE , ESA_R\
ETURNED_TAG , ESA_RETURNED_VALUE , ESA_RETURNED_FUNCT , ESA_RETURNED_TYPE , E\
SA_TERMINATE_WHEN_ERROR FROM OL_TXN_ENGINE_SPC_ACTION WHERE ESA_SPECIAL_ACTIO\
N_DETAIL_ID = :b0 ORDER BY ESA_SEQ            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,352,0,9,101,0,2049,1,1,0,1,0,1,3,0,0,
24,0,0,1,0,0,13,104,0,0,12,0,0,1,0,2,3,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,
87,0,0,1,0,0,15,208,0,0,0,0,0,1,0,
102,0,0,1,0,0,15,227,0,0,0,0,0,1,0,
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
#include "OLTxnEngineSpecialAction.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void OLTxnEngineSpcAction(char cdebug)
{
        cDebug = cdebug;
}

int GetTxnEngineSpcAction(const hash_t *hRls, recordset_t *myRec)
{
	int iRet = PD_OK;

	int iTmp = 0;
	int iCnt = 0;
	
	hash_t *myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO gettxnengspcaction_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int	hv_action_detail_id;

		int	v_action_detail_id;
		int	v_seq;
		/* varchar	v_p1_check_tag[PD_TAG_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_p1_check_tag;

		/* varchar	v_p2_check_tag[PD_TAG_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_p2_check_tag;

		/* varchar	v_compare_operator[PD_ENGINE_COMPARE_OPERATOR_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_compare_operator;

                /* varchar	v_expected_value[PD_ENGINE_VALUE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_expected_value;

                /* varchar	v_check_type[PD_ENGINE_VALUE_TYPE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_check_type;

		/* varchar	v_returned_tag[PD_TAG_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_returned_tag;

		int	v_returned_value;
		/* varchar	v_returned_funct[PD_ENGINE_FUNCT_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_returned_funct;

		/* varchar	v_returned_type[PD_ENGINE_VALUE_TYPE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_returned_type;

                int	v_terminate_when_error;

		short	ind_action_detail_id = -1;
		short	ind_seq = -1;
		short	ind_p1_check_tag = -1;
		short	ind_p2_check_tag = -1;
		short	ind_compare_operator = -1;
		short	ind_expected_value = -1;
		short	ind_check_type = -1;
		short	ind_returned_tag = -1;
		short	ind_returned_value = -1;
		short	ind_returned_funct = -1;
		short	ind_returned_type = -1;
		short	ind_terminate_when_error = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


// spc_action_detail_id
	if (GetField_Int(hRls, "spc_action_detail_id", &iTmp)) {
		hv_action_detail_id = iTmp;
DEBUGLOG(("GetTxnEngineSpcAction:: spc_action_detail_id = [%d]\n", hv_action_detail_id));
	} else {
DEBUGLOG(("GetTxnEngineSpcAction:: spc_action_detail_id not found!\n"));
		iRet = INT_ERR;
	}

	/* EXEC SQL DECLARE c_gettxnengspcaction CURSOR FOR
		SELECT	ESA_SPECIAL_ACTION_DETAIL_ID,
			ESA_SEQ,
			ESA_P1_CHECK_TAG,
			ESA_P2_CHECK_TAG,
			ESA_COMPARE_OPERATOR,
			ESA_EXPECTED_VALUE,
			ESA_CHECK_TYPE,
			ESA_RETURNED_TAG,
			ESA_RETURNED_VALUE,
			ESA_RETURNED_FUNCT,
			ESA_RETURNED_TYPE,
			ESA_TERMINATE_WHEN_ERROR
		FROM	OL_TXN_ENGINE_SPC_ACTION
		WHERE	ESA_SPECIAL_ACTION_DETAIL_ID = :hv_action_detail_id
		ORDER BY ESA_SEQ; */ 


	if (iRet == PD_OK) {
		/* EXEC SQL OPEN c_gettxnengspcaction; */ 

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
  if (sqlca.sqlcode < 0) goto gettxnengspcaction_error;
}



		for (;;) {
			/* EXEC SQL FETCH c_gettxnengspcaction
			INTO	:v_action_detail_id:ind_action_detail_id,
				:v_seq:ind_seq,
				:v_p1_check_tag:ind_p1_check_tag,
				:v_p2_check_tag:ind_p2_check_tag,
				:v_compare_operator:ind_compare_operator,
				:v_expected_value:ind_expected_value,
				:v_check_type:ind_check_type,
				:v_returned_tag:ind_returned_tag,
				:v_returned_value:ind_returned_value,
				:v_returned_funct:ind_returned_funct,
				:v_returned_type:ind_returned_type,
				:v_terminate_when_error:ind_terminate_when_error; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 12;
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
   sqlstm.sqhstv[1] = (unsigned char  *)&v_seq;
   sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_seq;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_p1_check_tag;
   sqlstm.sqhstl[2] = (unsigned long )28;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_p1_check_tag;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_p2_check_tag;
   sqlstm.sqhstl[3] = (unsigned long )28;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_p2_check_tag;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_compare_operator;
   sqlstm.sqhstl[4] = (unsigned long )23;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_compare_operator;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_expected_value;
   sqlstm.sqhstl[5] = (unsigned long )103;
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_expected_value;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&v_check_type;
   sqlstm.sqhstl[6] = (unsigned long )23;
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_check_type;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&v_returned_tag;
   sqlstm.sqhstl[7] = (unsigned long )28;
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         short *)&ind_returned_tag;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
   sqlstm.sqhstv[8] = (unsigned char  *)&v_returned_value;
   sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[8] = (         int  )0;
   sqlstm.sqindv[8] = (         short *)&ind_returned_value;
   sqlstm.sqinds[8] = (         int  )0;
   sqlstm.sqharm[8] = (unsigned long )0;
   sqlstm.sqadto[8] = (unsigned short )0;
   sqlstm.sqtdso[8] = (unsigned short )0;
   sqlstm.sqhstv[9] = (unsigned char  *)&v_returned_funct;
   sqlstm.sqhstl[9] = (unsigned long )53;
   sqlstm.sqhsts[9] = (         int  )0;
   sqlstm.sqindv[9] = (         short *)&ind_returned_funct;
   sqlstm.sqinds[9] = (         int  )0;
   sqlstm.sqharm[9] = (unsigned long )0;
   sqlstm.sqadto[9] = (unsigned short )0;
   sqlstm.sqtdso[9] = (unsigned short )0;
   sqlstm.sqhstv[10] = (unsigned char  *)&v_returned_type;
   sqlstm.sqhstl[10] = (unsigned long )23;
   sqlstm.sqhsts[10] = (         int  )0;
   sqlstm.sqindv[10] = (         short *)&ind_returned_type;
   sqlstm.sqinds[10] = (         int  )0;
   sqlstm.sqharm[10] = (unsigned long )0;
   sqlstm.sqadto[10] = (unsigned short )0;
   sqlstm.sqtdso[10] = (unsigned short )0;
   sqlstm.sqhstv[11] = (unsigned char  *)&v_terminate_when_error;
   sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[11] = (         int  )0;
   sqlstm.sqindv[11] = (         short *)&ind_terminate_when_error;
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
   if (sqlca.sqlcode < 0) goto gettxnengspcaction_error;
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
DEBUGLOG(("GetTxnEngineSpcAction:: spc_action_detail_id = [%d]\n", v_action_detail_id));
			}

/* seq */
			if (ind_seq >= 0) {
				PutField_Int(myHash, "seq", v_seq);
DEBUGLOG(("GetTxnEngineSpcAction:: seq = [%d]\n", v_seq));
			}

/* p1_check_tag */
			if (ind_p1_check_tag >= 0) {
				v_p1_check_tag.arr[v_p1_check_tag.len] = '\0';
				PutField_CString(myHash, "p1_check_tag", (const char*)v_p1_check_tag.arr);
DEBUGLOG(("GetTxnEngineSpcAction:: p1_check_tag = [%s]\n", v_p1_check_tag.arr));
			}

/* p2_check_tag */
			if (ind_p2_check_tag >= 0) {
				v_p2_check_tag.arr[v_p2_check_tag.len] = '\0';
				PutField_CString(myHash, "p2_check_tag", (const char*)v_p2_check_tag.arr);
DEBUGLOG(("GetTxnEngineSpcAction:: p2_check_tag = [%s]\n", v_p2_check_tag.arr));
			}

/* compare_operator */
			if (ind_compare_operator >= 0) {
				v_compare_operator.arr[v_compare_operator.len] = '\0';
				PutField_CString(myHash, "compare_operator", (const char*)v_compare_operator.arr);
DEBUGLOG(("GetTxnEngineSpcAction:: compare_operator = [%s]\n", v_compare_operator.arr));
			}

/* expected_value */
			if (ind_expected_value >= 0) {
				v_expected_value.arr[v_expected_value.len] = '\0';
				PutField_CString(myHash, "expected_value", (const char*)v_expected_value.arr);
DEBUGLOG(("GetTxnEngineSpcAction:: expected_value = [%s]\n", v_expected_value.arr));
			}

/* check_type */
                        if (ind_check_type >= 0) {
                                v_check_type.arr[v_check_type.len] = '\0';
                                PutField_CString(myHash, "check_type", (const char*)v_check_type.arr);
DEBUGLOG(("GetTxnEngineSpcAction:: check_type = [%s]\n", v_check_type.arr));
                        }

/* returned_tag */
			if (ind_returned_tag >= 0) {
				v_returned_tag.arr[v_returned_tag.len] = '\0';
				PutField_CString(myHash, "returned_tag", (const char*)v_returned_tag.arr);
DEBUGLOG(("GetTxnEngineSpcAction:: returned_tag = [%s]\n", v_returned_tag.arr));
			}

/* returned_value */
			if (ind_returned_value >= 0) {
				PutField_Int(myHash, "returned_value", v_returned_value);
DEBUGLOG(("GetTxnEngineSpcAction:: returned_value = [%d]\n", v_returned_value));
			}

/* returned_funct */
                        if (ind_returned_funct >= 0) {
                                v_returned_funct.arr[v_returned_funct.len] = '\0';
                                PutField_CString(myHash, "returned_funct", (const char*)v_returned_funct.arr);
DEBUGLOG(("GetTxnEngineSpcAction:: returned_funct = [%s]\n", v_returned_funct.arr));
                        }

/* returned_type */
                        if (ind_returned_type >= 0) {
                                v_returned_type.arr[v_returned_type.len] = '\0';
                                PutField_CString(myHash, "returned_type", (const char*)v_returned_type.arr);
DEBUGLOG(("GetTxnEngineSpcAction:: returned_type = [%s]\n", v_returned_type.arr));
                        }

/* terminate_when_error */
                        if (ind_terminate_when_error >= 0) {
                                PutField_Int(myHash, "terminate_when_error", v_terminate_when_error);
DEBUGLOG(("GetTxnEngineSpcAction:: terminate_when_error = [%d]\n", v_terminate_when_error));
                        }

			RecordSet_Add(myRec, myHash);
		}
		/* EXEC SQL CLOSE c_gettxnengspcaction; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )87;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto gettxnengspcaction_error;
}



		if (iCnt > 0) {
DEBUGLOG(("GetTxnEngineSpcAction:: hash added\n"));
		} else {
DEBUGLOG(("GetTxnEngineSpcActionLL no record found\n"));
ERRLOG("OLTxnEngineSpcAction:: GetTxnEngineSpcAction:: no record found\n");
			iRet = PD_ERR;
		}
	}

DEBUGLOG(("GetTxnEngineSpcAction:: Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

gettxnengspcaction_error:
DEBUGLOG(("gettxnengspcaction_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLTxnEngineSpcAction:: gettxnengspcaction_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL CLOSE c_gettxnengspcaction; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )102;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto gettxnengspcaction_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}
