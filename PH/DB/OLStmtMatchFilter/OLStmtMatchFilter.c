
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
    "OLStmtMatchFilter.pc"
};


static unsigned int sqlctx = 82836603;


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
   unsigned char  *sqhstv[11];
   unsigned long  sqhstl[11];
            int   sqhsts[11];
            short *sqindv[11];
            int   sqinds[11];
   unsigned long  sqharm[11];
   unsigned long  *sqharc[11];
   unsigned short  sqadto[11];
   unsigned short  sqtdso[11];
} sqlstm = {12,11};

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
"MF_SEQUENCE , OSMF_GROUP            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,1060,0,9,141,0,2049,7,7,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,3,0,0,
48,0,0,1,0,0,13,144,0,0,11,0,0,1,0,2,3,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,3,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
107,0,0,1,0,0,15,242,0,0,0,0,0,1,0,
122,0,0,1,0,0,15,260,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2014. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/11/24              [WCS]
Reduce Log                                         2021/05/17              [WCS]
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
#include "OLStmtMatchFilter.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


static char cDebug;

void OLStmtMatchFilter(char cdebug)
{
	cDebug = cdebug;
}


int GetStmtMatchFilter(const hash_t *hMatchRule, const hash_t *hMatchAction, recordset_t *myRec)
{
	int iRet = PD_OK;
	int iCnt = 0;
	int iTmp;
	char *csTmp;

	hash_t *myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO getstmtmatchfilter_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_action_type[PD_ENGINE_ACTION_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_action_type;

		int hv_action_filter_id;
		/* varchar hv_first_party[PD_ENGINE_PARTY_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_first_party;

		/* varchar hv_second_party[PD_ENGINE_PARTY_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_second_party;


		int v_sequence;
		int v_group;
		/* varchar v_party[PD_ENGINE_PARTY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_party;

		/* varchar v_filter[PD_STMT_MATCH_FILTER_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_filter;

		/* varchar v_operator[PD_ENGINE_COMPARE_OPERATOR_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_operator;

		/* varchar v_value[PD_STMT_MATCH_VALUE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_value;

		int v_from_input;
		int v_to_output;
		/* varchar v_special_handling[50 + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_special_handling;

		/* varchar v_left_operand[PD_MAX_BUFFER + 1]; */ 
struct { unsigned short len; unsigned char arr[16393]; } v_left_operand;

		/* varchar v_right_operand[PD_MAX_BUFFER + 1]; */ 
struct { unsigned short len; unsigned char arr[16393]; } v_right_operand;


		short ind_sequence = -1;
		short ind_group = -1;
		short ind_party = -1;
		short ind_filter = -1;
		short ind_operator = -1;
		short ind_value = -1;
		short ind_from_input = -1;
		short ind_to_output = -1;
		short ind_special_handling = -1;
		short ind_left_operand = -1;
		short ind_right_operand = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hMatchRule, "action_type", &csTmp)) {
		hv_action_type.len = strlen(csTmp);
		strncpy((char*)hv_action_type.arr, csTmp, hv_action_type.len);
DEBUGLOG(("action_type = [%.*s]\n", hv_action_type.len, (const char*)hv_action_type.arr));
	} else {
DEBUGLOG(("action_type not found!\n"));
		iRet = PD_ERR;
	}

	if (GetField_Int(hMatchRule, "action_filter_id", &iTmp)) {
		hv_action_filter_id = iTmp;
DEBUGLOG(("action_filter_id = [%d]\n", hv_action_filter_id));
	} else {
DEBUGLOG(("action_filter_id not found!\n"));
		iRet = PD_ERR;
	}

	if (GetField_CString(hMatchAction, "first_party", &csTmp)) {
		hv_first_party.len = strlen(csTmp);
		strncpy((char*)hv_first_party.arr, csTmp, hv_first_party.len);
DEBUGLOG(("first_party = [%.*s]\n", hv_first_party.len, (const char*)hv_first_party.arr));
	} else {
DEBUGLOG(("first_party not found!\n"));
		iRet = PD_ERR;
	}

	if (GetField_CString(hMatchAction, "second_party", &csTmp)) {
		hv_second_party.len = strlen(csTmp);
		strncpy((char*)hv_second_party.arr, csTmp, hv_second_party.len);
DEBUGLOG(("second_party = [%.*s]\n", hv_second_party.len, (const char*)hv_second_party.arr));
	} else {
DEBUGLOG(("second_party not found!\n"));
		iRet = PD_ERR;
	}

	/* EXEC SQL DECLARE c_getstmtmatchfilter CURSOR FOR
		SELECT	OSMF_SEQUENCE,
			OSMF_GROUP,
			OSMF_PARTY,
			OSMF_FILTER,
			OSMF_OPERATOR,
			OSMF_VALUE,
			OSMF_FROM_INPUT,
			OSMF_TO_OUTPUT,
			OSMF_SPECIAL_HANDLING,
			DECODE(OSMF_PARTY, 'both',
				(SELECT OSMM_FIELD FROM OL_STMT_MATCH_FILTER_MAP
					WHERE OSMM_ACTION_TYPE = :hv_action_type AND OSMM_PARTY = :hv_first_party AND OSMM_FILTER = OSMF_FILTER),
				(SELECT OSMM_FIELD FROM OL_STMT_MATCH_FILTER_MAP
					WHERE OSMM_ACTION_TYPE = :hv_action_type AND OSMM_PARTY = OSMF_PARTY AND OSMM_FILTER = OSMF_FILTER)
			) LEFT_OPERAND,
			DECODE (OSMF_PARTY, 'both',
				(SELECT OSMM_FIELD FROM OL_STMT_MATCH_FILTER_MAP
					WHERE OSMM_ACTION_TYPE = :hv_action_type AND OSMM_PARTY = :hv_second_party AND OSMM_FILTER = OSMF_FILTER),
				(SELECT DECODE(OSMF_OPERATOR, 'is', OSMF_VALUE, 'is not', OSMF_VALUE, DECODE(OSMM_ADD_SINGLE_QUOTE, 0, OSMF_VALUE, ''''||OSMF_VALUE||'''')) FROM OL_STMT_MATCH_FILTER_MAP
					WHERE OSMM_ACTION_TYPE = :hv_action_type AND OSMM_PARTY = OSMF_PARTY AND OSMM_FILTER = OSMF_FILTER)
			) RIGHT_OPERAND
		FROM	OL_STMT_MATCH_FILTER
		WHERE	OSMF_ACTION_FILTER_ID = :hv_action_filter_id
		AND	OSMF_DISABLED = 0
		ORDER BY	OSMF_SEQUENCE,
				OSMF_GROUP; */ 


	if (iRet == PD_OK) {
		/* EXEC SQL OPEN c_getstmtmatchfilter; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlbuft((void **)0,
    "SELECT OSMF_SEQUENCE , OSMF_GROUP , OSMF_PARTY , OSMF_FILTER , OSMF_OPE\
RATOR , OSMF_VALUE , OSMF_FROM_INPUT , OSMF_TO_OUTPUT , OSMF_SPECIAL_HANDLIN\
G , DECODE ( OSMF_PARTY , 'both' , ( SELECT OSMM_FIELD FROM OL_STMT_MATCH_FI\
LTER_MAP WHERE OSMM_ACTION_TYPE = :b0 AND OSMM_PARTY = :b1 AND OSMM_FILTER =\
 OSMF_FILTER ) , ( SELECT OSMM_FIELD FROM OL_STMT_MATCH_FILTER_MAP WHERE OSM\
M_ACTION_TYPE = :b0 AND OSMM_PARTY = OSMF_PARTY AND OSMM_FILTER = OSMF_FILTE\
R ) ) LEFT_OPERAND , DECODE ( OSMF_PARTY , 'both' , ( SELECT OSMM_FIELD FROM\
 OL_STMT_MATCH_FILTER_MAP WHERE OSMM_ACTION_TYPE = :b0 AND OSMM_PARTY = :b4 \
AND OSMM_FILTER = OSMF_FILTER ) , ( SELECT DECODE ( OSMF_OPERATOR , 'is' , O\
SMF_VALUE , 'is not' , OSMF_VALUE , DECODE ( OSMM_ADD_SINGLE_QUOTE , 0 , OSM\
F_VALUE , '''' || OSMF_VALUE || '''' ) ) FROM OL_STMT_MATCH_FILTER_MAP WHERE\
 OSMM_ACTION_TYPE = :b0 AND OSMM_PARTY = OSMF_PARTY AND OSMM_FILTER = OSMF_F\
ILTER ) ) RIGHT_OPERAND FROM OL_STMT_MATCH_FILTER WHERE OSMF_ACTION_FILTER_I\
D = :b6 AND OSMF_DISABLED = 0 ORDER BY OS");
  sqlstm.stmt = sq0001;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_action_type;
  sqlstm.sqhstl[0] = (unsigned long )52;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_first_party;
  sqlstm.sqhstl[1] = (unsigned long )12;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_action_type;
  sqlstm.sqhstl[2] = (unsigned long )52;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&hv_action_type;
  sqlstm.sqhstl[3] = (unsigned long )52;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&hv_second_party;
  sqlstm.sqhstl[4] = (unsigned long )12;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&hv_action_type;
  sqlstm.sqhstl[5] = (unsigned long )52;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&hv_action_filter_id;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
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
  if (sqlca.sqlcode < 0) goto getstmtmatchfilter_error;
}



		for (;;) {
			/* EXEC SQL FETCH c_getstmtmatchfilter
			INTO	:v_sequence:ind_sequence,
				:v_group:ind_group,
				:v_party:ind_party,
				:v_filter:ind_filter,
				:v_operator:ind_operator,
				:v_value:ind_value,
				:v_from_input:ind_from_input,
				:v_to_output:ind_to_output,
				:v_special_handling:ind_special_handling,
				:v_left_operand:ind_left_operand,
				:v_right_operand:ind_right_operand; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 11;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )48;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_sequence;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_sequence;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_group;
   sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_group;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_party;
   sqlstm.sqhstl[2] = (unsigned long )13;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_party;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_filter;
   sqlstm.sqhstl[3] = (unsigned long )23;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_filter;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_operator;
   sqlstm.sqhstl[4] = (unsigned long )23;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_operator;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_value;
   sqlstm.sqhstl[5] = (unsigned long )53;
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_value;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&v_from_input;
   sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_from_input;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&v_to_output;
   sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         short *)&ind_to_output;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
   sqlstm.sqhstv[8] = (unsigned char  *)&v_special_handling;
   sqlstm.sqhstl[8] = (unsigned long )53;
   sqlstm.sqhsts[8] = (         int  )0;
   sqlstm.sqindv[8] = (         short *)&ind_special_handling;
   sqlstm.sqinds[8] = (         int  )0;
   sqlstm.sqharm[8] = (unsigned long )0;
   sqlstm.sqadto[8] = (unsigned short )0;
   sqlstm.sqtdso[8] = (unsigned short )0;
   sqlstm.sqhstv[9] = (unsigned char  *)&v_left_operand;
   sqlstm.sqhstl[9] = (unsigned long )16395;
   sqlstm.sqhsts[9] = (         int  )0;
   sqlstm.sqindv[9] = (         short *)&ind_left_operand;
   sqlstm.sqinds[9] = (         int  )0;
   sqlstm.sqharm[9] = (unsigned long )0;
   sqlstm.sqadto[9] = (unsigned short )0;
   sqlstm.sqtdso[9] = (unsigned short )0;
   sqlstm.sqhstv[10] = (unsigned char  *)&v_right_operand;
   sqlstm.sqhstl[10] = (unsigned long )16395;
   sqlstm.sqhsts[10] = (         int  )0;
   sqlstm.sqindv[10] = (         short *)&ind_right_operand;
   sqlstm.sqinds[10] = (         int  )0;
   sqlstm.sqharm[10] = (unsigned long )0;
   sqlstm.sqadto[10] = (unsigned short )0;
   sqlstm.sqtdso[10] = (unsigned short )0;
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
   if (sqlca.sqlcode < 0) goto getstmtmatchfilter_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			iCnt++;

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash, 0);

			// sequence
			if (ind_sequence >= 0) {
				PutField_Int(myHash, "sequence", v_sequence);
// DEBUGLOG(("sequence = [%d]\n", v_sequence));
			}

			// group
			if (ind_group >= 0) {
				PutField_Int(myHash, "group", v_group);
// DEBUGLOG(("group = [%d]\n", v_group));
			}

			// party
			if (ind_party >= 0) {
				v_party.arr[v_party.len] = '\0';
				PutField_CString(myHash, "party", (const char*)v_party.arr);
// DEBUGLOG(("party = [%s]\n", (const char*)v_party.arr));
			}

			// filter
			if (ind_filter >= 0) {
				v_filter.arr[v_filter.len] = '\0';
				PutField_CString(myHash, "filter", (const char*)v_filter.arr);
// DEBUGLOG(("filter = [%s]\n", (const char*)v_filter.arr));
			}

			// operator
			if (ind_operator >= 0) {
				v_operator.arr[v_operator.len] = '\0';
				PutField_CString(myHash, "operator", (const char*)v_operator.arr);
// DEBUGLOG(("operator = [%s]\n", (const char*)v_operator.arr));
			}

			// value
			if (ind_value >= 0) {
				v_value.arr[v_value.len] = '\0';
				PutField_CString(myHash, "value", (const char*)v_value.arr);
// DEBUGLOG(("value = [%s]\n", (const char*)v_value.arr));
			}

			// from_input
			if (ind_from_input >= 0) {
				PutField_Int(myHash, "from_input", v_from_input);
// DEBUGLOG(("from_input = [%d]\n", v_from_input));
			}

			// to_output
			if (ind_to_output >= 0) {
				PutField_Int(myHash, "to_output", v_to_output);
// DEBUGLOG(("to_output = [%d]\n", v_to_output));
			}

			// special_handling
			if (ind_special_handling >= 0) {
				v_special_handling.arr[v_special_handling.len] = '\0';
				PutField_CString(myHash, "special_handling", (const char*)v_special_handling.arr);
// DEBUGLOG(("special_handling = [%s]\n", (const char*)v_special_handling.arr));
			}

			// left_operand
			if (ind_left_operand >= 0) {
				v_left_operand.arr[v_left_operand.len] = '\0';
				PutField_CString(myHash, "left_operand", (const char*)v_left_operand.arr);
// DEBUGLOG(("left_operand = [%s]\n", (const char*)v_left_operand.arr));
			}

			// right_operand
			if (ind_right_operand >= 0) {
				v_right_operand.arr[v_right_operand.len] = '\0';
				PutField_CString(myHash, "right_operand", (const char*)v_right_operand.arr);
// DEBUGLOG(("right_operand = [%s]\n", (const char*)v_right_operand.arr));
			}

			RecordSet_Add(myRec, myHash);
		}

		/* EXEC SQL CLOSE c_getstmtmatchfilter; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 11;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )107;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto getstmtmatchfilter_error;
}



		if (iCnt == 0) {
DEBUGLOG(("not found\n"));
ERRLOG("OLStmtMatchFilter:: GetStmtMatchFilter not found\n");
			iRet = PD_ERR;
		}
	}

DEBUGLOG(("Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getstmtmatchfilter_error:
DEBUGLOG(("getstmtmatchfilter_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStmtMatchFilter getstmtmatchfilter_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_getstmtmatchfilter; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )122;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

