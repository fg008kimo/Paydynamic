
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
    "OLStmtMatchEngine.pc"
};


static unsigned int sqlctx = 82836355;


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
"SELECT OSME_RULE_ID , OSME_FAILED_BAID_TXN_CODE FROM OL_STMT_MATCH_ENGINE W\
HERE OSME_TRIGGER_TYPE = :b0 AND OSME_INPUT_CHANNEL = :b1 AND OSME_BANK_ACCT_\
TYPE = :b2 AND OSME_BAID_TXN_CODE = :b3 AND OSME_DISABLED = 0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,225,0,9,103,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
36,0,0,1,0,0,13,106,0,0,2,0,0,1,0,2,3,0,0,2,9,0,0,
59,0,0,1,0,0,15,132,0,0,0,0,0,1,0,
74,0,0,1,0,0,15,149,0,0,0,0,0,1,0,
89,0,0,2,0,0,17,399,0,0,1,1,0,1,0,1,9,0,0,
108,0,0,2,0,0,45,402,0,0,0,0,0,1,0,
123,0,0,2,0,0,13,404,0,0,1,0,0,1,0,2,9,0,0,
142,0,0,2,0,0,15,428,0,0,0,0,0,1,0,
157,0,0,2,0,0,15,449,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/10/31              Dirk Wong
Rewrite                                            2013/11/??              David Wong
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
#include "OLStmtMatchEngine.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char cDebug;

void OLStmtMatchEngine(char cdebug)
{
	cDebug = cdebug;
}


int GetStmtMatchEngine(const hash_t *hContext, hash_t *myHash)
{
	int iRet = PD_OK;
	int iCnt = 0;
	char *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO getstmtmatchengine_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_trigger_type[PD_ENGINE_TRIGGER_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_trigger_type;

		/* varchar hv_input_channel[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_input_channel;

		/* varchar hv_bank_acct_type[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_bank_acct_type;

		/* varchar hv_baid_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_baid_txn_code;


		int v_rule_id;
		/* varchar v_failed_baid_txn_code[PD_TXN_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_failed_baid_txn_code;


		short ind_rule_id = -1;
		short ind_failed_baid_txn_code = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hContext, "trigger_type", &csTmp)) {
		hv_trigger_type.len = strlen(csTmp);
		strncpy((char*)hv_trigger_type.arr, csTmp, hv_trigger_type.len);
DEBUGLOG(("GetStmtMatchEngine trigger_type = [%.*s]\n", hv_trigger_type.len, (const char*)hv_trigger_type.arr));
	} else {
DEBUGLOG(("GetStmtMatchEngine trigger_type not found!\n"));
		iRet = PD_ERR;
	}

	if (GetField_CString(hContext, "input_channel", &csTmp)) {
		hv_input_channel.len = strlen(csTmp);
		strncpy((char*)hv_input_channel.arr, csTmp, hv_input_channel.len);
DEBUGLOG(("GetStmtMatchEngine input_channel = [%.*s]\n", hv_input_channel.len, (const char*)hv_input_channel.arr));
	} else {
DEBUGLOG(("GetStmtMatchEngine input_channel not found!\n"));
		iRet = PD_ERR;
	}

	if (GetField_CString(hContext, "bank_acct_type", &csTmp)) {
		hv_bank_acct_type.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_type.arr, csTmp, hv_bank_acct_type.len);
DEBUGLOG(("GetStmtMatchEngine bank_acct_type = [%.*s]\n", hv_bank_acct_type.len, (const char*)hv_bank_acct_type.arr));
	} else {
DEBUGLOG(("GetStmtMatchEngine bank_acct_type not found!\n"));
		iRet = PD_ERR;
	}

	if (GetField_CString(hContext, "baid_txn_code", &csTmp)) {
		hv_baid_txn_code.len = strlen(csTmp);
		strncpy((char*)hv_baid_txn_code.arr, csTmp, hv_baid_txn_code.len);
DEBUGLOG(("GetStmtMatchEngine baid_txn_code = [%.*s]\n", hv_baid_txn_code.len, (const char*)hv_baid_txn_code.arr));
	} else {
DEBUGLOG(("GetStmtMatchEngine baid_txn_code not found!\n"));
		iRet = PD_ERR;
	}

	/* EXEC SQL DECLARE c_getstmtmatchengine CURSOR FOR
		SELECT	OSME_RULE_ID,
			OSME_FAILED_BAID_TXN_CODE
		FROM	OL_STMT_MATCH_ENGINE
		WHERE	OSME_TRIGGER_TYPE = :hv_trigger_type
		AND	OSME_INPUT_CHANNEL = :hv_input_channel
		AND	OSME_BANK_ACCT_TYPE = :hv_bank_acct_type
		AND	OSME_BAID_TXN_CODE = :hv_baid_txn_code
		AND	OSME_DISABLED = 0; */ 


	if (iRet == PD_OK) {
		/* EXEC SQL OPEN c_getstmtmatchengine; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
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
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_trigger_type;
  sqlstm.sqhstl[0] = (unsigned long )12;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_input_channel;
  sqlstm.sqhstl[1] = (unsigned long )5;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_type;
  sqlstm.sqhstl[2] = (unsigned long )5;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&hv_baid_txn_code;
  sqlstm.sqhstl[3] = (unsigned long )5;
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
  if (sqlca.sqlcode < 0) goto getstmtmatchengine_error;
}



		for (;;) {
			/* EXEC SQL FETCH c_getstmtmatchengine
			INTO	:v_rule_id:ind_rule_id,
				:v_failed_baid_txn_code:ind_failed_baid_txn_code; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 4;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )36;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_rule_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_rule_id;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_failed_baid_txn_code;
   sqlstm.sqhstl[1] = (unsigned long )6;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_failed_baid_txn_code;
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
   if (sqlca.sqlcode < 0) goto getstmtmatchengine_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			iCnt++;

			// rule_id
			if (ind_rule_id >= 0) {
				PutField_Int(myHash, "rule_id", v_rule_id);
DEBUGLOG(("GetStmtMatchEngine rule_id = [%d]\n", v_rule_id));
			}

			// failed_baid_txn_code
			if (ind_failed_baid_txn_code >= 0) {
				v_failed_baid_txn_code.arr[v_failed_baid_txn_code.len] = '\0';
				PutField_CString(myHash, "failed_baid_txn_code", (const char*)v_failed_baid_txn_code.arr);
DEBUGLOG(("GetStmtMatchEngine failed_baid_txn_code = [%s]\n", (const char*)v_failed_baid_txn_code.arr));
			}

			break;
		}

		/* EXEC SQL CLOSE c_getstmtmatchengine; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )59;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto getstmtmatchengine_error;
}



		if (iCnt == 0) {
DEBUGLOG(("GetStmtMatchEngine not found\n"));
			iRet = PD_ERR;
		}
	}

DEBUGLOG(("GetStmtMatchEngine Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getstmtmatchengine_error:
DEBUGLOG(("getstmtmatchengine_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStmtMatchEngine getstmtmatchengine_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_getstmtmatchengine; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )74;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}


/*
	important note:
	input and output of dynamic sql must be of string type
*/
int ExecuteSql(hash_t *hContext, recordset_t *rMatchFilter, hash_t *hEngineSql, recordset_t *rMatchResult)
{
	int iRet = PD_OK;
	int iCnt = 0;
	char *csTmp;
	int iTmp;

	hash_t *hMatchFilter;
	hash_t *hMatchResult;

	char *csSql;
	int iSequence = 0, iGroup = 0;
	int iLastSequence = 0, iLastGroup = 0;
	char *csParty, *csFilter, *csOperator, *csLeftOperand, *csRightOperand = NULL;
	int iFromInput, iToOutput;
	char csOutputTag[PD_STMT_MATCH_FILTER_LEN];

	/* EXEC SQL WHENEVER SQLERROR GOTO execute_sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_dynstmt_tmp[PD_MAX_BUFFER]; */ 
struct { unsigned short len; unsigned char arr[16392]; } hv_dynstmt_tmp;

		/* varchar hv_dynstmt[PD_MAX_BUFFER]; */ 
struct { unsigned short len; unsigned char arr[16392]; } hv_dynstmt;


		/* varchar v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;


		short ind_txn_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	if (iRet == PD_OK) {
		// get from_clause
		if (!GetField_CString(hEngineSql, "from_clause", &csSql)) {
DEBUGLOG(("ExecuteSql:: from_clause not found\n"));
			return PD_ERR;
		} else {
// DEBUGLOG(("ExecuteSql:: from_clause = [%s]\n", csSql));
			strcpy((char*)hv_dynstmt_tmp.arr, csSql);
			hv_dynstmt_tmp.len = strlen((const char*)hv_dynstmt_tmp.arr);
		}
	}

	if (iRet == PD_OK) {
		// loop match filter
		hMatchFilter = RecordSet_GetFirst(rMatchFilter);
		while (hMatchFilter) {
			// get sequence
			if (!GetField_Int(hMatchFilter, "sequence", &iSequence)) {
DEBUGLOG(("ExecuteSql:: sequence not found\n"));
				iRet = PD_ERR;
				break;
			} else {
// DEBUGLOG(("ExecuteSql:: sequence = [%d]\n", iSequence));
			}

			// get group
			if (GetField_Int(hMatchFilter, "group", &iGroup)) {
// DEBUGLOG(("ExecuteSql:: group = [%d]\n", iGroup));
			} else {
				iGroup = 0;
			}

			// get party (mandatory)
			if (!GetField_CString(hMatchFilter, "party", &csParty)) {
DEBUGLOG(("ExecuteSql:: party not found\n"));
				iRet = PD_ERR;
				break;
			} else {
// DEBUGLOG(("ExecuteSql:: party = [%s]\n", csParty));
			}

			// get filter (mandatory)
			if (!GetField_CString(hMatchFilter, "filter", &csFilter)) {
DEBUGLOG(("ExecuteSql:: filter not found\n"));
				iRet = PD_ERR;
				break;
			} else {
// DEBUGLOG(("ExecuteSql:: filter = [%s]\n", csFilter));
			}

			// get skip
			if (GetField_Int(hMatchFilter, "skip", &iTmp)) {
// DEBUGLOG(("ExecuteSql:: skip = [%d]\n", iTmp));
				if (iTmp) {
					hMatchFilter = RecordSet_GetNext(rMatchFilter);
					continue;
				}
			}

			// get from_input (mandatory)
			if (!GetField_Int(hMatchFilter, "from_input", &iFromInput)) {
DEBUGLOG(("ExecuteSql:: from_input not found\n"));
				iRet = PD_ERR;
				break;
			} else {
// DEBUGLOG(("ExecuteSql:: from_input = [%d]\n", iFromInput));
			}

			// get to_output (mandatory)
			if (!GetField_Int(hMatchFilter, "to_output", &iToOutput)) {
DEBUGLOG(("ExecuteSql:: to_output not found\n"));
				iRet = PD_ERR;
				break;
			} else {
// DEBUGLOG(("ExecuteSql:: to_output = [%d]\n", iToOutput));
			}

			// get operator (mandatory except output)
			if (!GetField_CString(hMatchFilter, "operator", &csOperator)) {
				if (!iToOutput) {
DEBUGLOG(("ExecuteSql:: operator not found\n"));
					iRet = PD_ERR;
					break;
				}
			} else {
// DEBUGLOG(("ExecuteSql:: operator = [%s]\n", csOperator));
			}

			// get left_operand (mandatory)
			if (!GetField_CString(hMatchFilter, "left_operand", &csLeftOperand)) {
DEBUGLOG(("ExecuteSql:: left_operand not found\n"));
				iRet = PD_ERR;
				break;
			} else {
// DEBUGLOG(("ExecuteSql:: left_operand = [%s]\n", csLeftOperand));
			}

			// get right_operand (mandatory except input & output)
			if (!GetField_CString(hMatchFilter, "right_operand", &csRightOperand)) {
				if (!iFromInput && !iToOutput) {
DEBUGLOG(("ExecuteSql:: right_operand not found\n"));
					iRet = PD_ERR;
					break;
				}
			} else {
// DEBUGLOG(("ExecuteSql:: right_operand = [%s]\n", csRightOperand));
			}

			if (iFromInput) {
				// input from hContext
				if (!GetField_CString(hContext, csFilter, &csTmp)) {
DEBUGLOG(("ExecuteSql:: input [%s] not found\n", csFilter));
					iRet = PD_ERR;
					break;
				} else {
DEBUGLOG(("ExecuteSql:: [%s] = [%s]\n", csFilter, csTmp));
					strcat((char*)hv_dynstmt_tmp.arr, " and ");
					strcat((char*)hv_dynstmt_tmp.arr, csLeftOperand);
					strcat((char*)hv_dynstmt_tmp.arr, " ");
					strcat((char*)hv_dynstmt_tmp.arr, csOperator);
					strcat((char*)hv_dynstmt_tmp.arr, " ");
					if (csRightOperand != NULL) {
						if (!strcmp(csRightOperand, "''")) {
							strcat((char*)hv_dynstmt_tmp.arr, "'");
						}
					}
					strcat((char*)hv_dynstmt_tmp.arr, csTmp);
					if (csRightOperand != NULL) {
						if (!strcmp(csRightOperand, "''")) {
							strcat((char*)hv_dynstmt_tmp.arr, "'");
						}
					}
					hv_dynstmt_tmp.len = strlen((const char*)hv_dynstmt_tmp.arr);
				}
			} else if (iToOutput) {
				// output to hConText
				strcpy((char*)hv_dynstmt.arr, "select ");
				strcat((char*)hv_dynstmt.arr, csLeftOperand);
				hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
				strcpy(csOutputTag, csFilter);
			} else {
				// where condition
				if ((iSequence != iLastSequence) &&
					(iGroup == 0) &&
					(iLastGroup == 0))
				{
					// add nothing
					strcat((char*)hv_dynstmt_tmp.arr, " and ");
				} else if ((iSequence != iLastSequence) &&
							(iGroup != 0) &&
							(iLastGroup == 0))
				{
					strcat((char*)hv_dynstmt_tmp.arr, " and ((");
				} else if ((iSequence == iLastSequence) &&
							(iGroup == iLastGroup))
				{
					// add nothing
					strcat((char*)hv_dynstmt_tmp.arr, " and ");
				} else if ((iSequence == iLastSequence) &&
							(iGroup != iLastGroup))
				{
					strcat((char*)hv_dynstmt_tmp.arr, ") or (");
				} else if ((iSequence != iLastSequence) &&
							(iGroup == 0) &&
							(iLastGroup != 0))
				{
					strcat((char*)hv_dynstmt_tmp.arr, ")) and ");
				} else if ((iSequence != iLastSequence) &&
							(iGroup != 0) &&
							(iLastGroup != 0))
				{
					strcat((char*)hv_dynstmt_tmp.arr, ")) and ((");
				}

				strcat((char*)hv_dynstmt_tmp.arr, csLeftOperand);
				strcat((char*)hv_dynstmt_tmp.arr, " ");
				strcat((char*)hv_dynstmt_tmp.arr, csOperator);
				strcat((char*)hv_dynstmt_tmp.arr, " ");
				strcat((char*)hv_dynstmt_tmp.arr, csRightOperand);
				hv_dynstmt_tmp.len = strlen((const char*)hv_dynstmt_tmp.arr);
			}

			iLastSequence = iSequence;
			iLastGroup = iGroup;

			hMatchFilter = RecordSet_GetNext(rMatchFilter);
		}

		if (iRet == PD_OK) {
			if (iLastGroup != 0) {
				strcat((char*)hv_dynstmt_tmp.arr, "))");
				hv_dynstmt_tmp.len = strlen((const char*)hv_dynstmt_tmp.arr);
			}
		}
	}

	if (iRet == PD_OK) {
		// get order_by_clause
		if (!GetField_CString(hEngineSql, "order_by_clause", &csSql)) {
DEBUGLOG(("ExecuteSql:: order_by_clause not found\n"));
		} else {
// DEBUGLOG(("ExecuteSql:: order_by_clause = [%s]\n", csSql));
			strcat((char*)hv_dynstmt_tmp.arr, csSql);
			hv_dynstmt_tmp.len = strlen((const char*)hv_dynstmt_tmp.arr);
		}
	}

	if (iRet == PD_OK) {
		strcat((char*)hv_dynstmt.arr, (char*)hv_dynstmt_tmp.arr);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("ExecuteSql:: SQL = [%.*s]\n", hv_dynstmt.len, hv_dynstmt.arr));

		/* EXEC SQL PREPARE s1 FROM :hv_dynstmt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )89;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
  sqlstm.sqhstl[0] = (unsigned long )16394;
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
  if (sqlca.sqlcode < 0) goto execute_sql_error;
}


		/* EXEC SQL DECLARE c_execute_sql CURSOR FOR s1; */ 


		/* EXEC SQL OPEN c_execute_sql; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )108;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto execute_sql_error;
}


		for (;;) {
			/* EXEC SQL FETCH c_execute_sql
			INTO :v_txn_id:ind_txn_id; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 4;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )123;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_id;
   sqlstm.sqhstl[0] = (unsigned long )19;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_txn_id;
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
   if (sqlca.sqlcode < 0) goto execute_sql_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			if (ind_txn_id >= 0) {
				iCnt++;

				hMatchResult = (hash_t*) malloc (sizeof(hash_t));
				hash_init(hMatchResult, 0);

				v_txn_id.arr[v_txn_id.len] = '\0';
DEBUGLOG(("ExecuteSql: [%s] = [%s]\n", csOutputTag, (const char*)v_txn_id.arr));
				PutField_CString(hContext, "output_tag", csOutputTag);
				PutField_CString(hMatchResult, csOutputTag, (const char*)v_txn_id.arr);
			} else {
DEBUGLOG(("ExecuteSql: [%s] not found\n", csOutputTag));
				return PD_ERR;
			}

			RecordSet_Add(rMatchResult, hMatchResult);
		}
		/* EXEC SQL CLOSE c_execute_sql; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )142;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto execute_sql_error;
}


	}

	if (iRet == PD_OK) {
		if (iCnt > 0) {
DEBUGLOG(("ExecuteSql record found\n"));
			iRet = PD_FOUND;
		} else {
DEBUGLOG(("ExecuteSql: no record found\n"));
			iRet = PD_NOT_FOUND;
		}
	}

	return iRet;

execute_sql_error:
DEBUGLOG(("execute_sql_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStmtMatchEngine execute_sql_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_execute_sql; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )157;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}


