
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
           char  filnam[16];
};
static struct sqlcxp sqlfpn =
{
    15,
    "OLStmtFormat.pc"
};


static unsigned int sqlctx = 2588651;


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
"SELECT OLFT_FORMAT_ID , lower ( OLFT_FORMAT_TYPE ) OLFT_FORMAT_TYPE , OLFT_\
FORMAT_VALUE , OLFT_CONT_DESC , OLFT_CONT_DESC_2 , OLFT_CONT_TEMPLATE , OLFT_\
CONT_NEXT_LVL FROM OL_STMT_FORMAT_TEMPLATE , OL_STMT_FORMAT WHERE OLSF_INT_BA\
NK_CODE = :b0 AND ( OLFT_FORMAT_ID = OLSF_FORMAT_ID or OLFT_FORMAT_ID like OL\
SF_FORMAT_ID || '.%' ) AND OLSF_DISABLED = 0 AND OLSF_EFFECT_TIMESTAMP <= sys\
date ORDER BY OLSF_EFFECT_TIMESTAMP DESC , OLFT_FORMAT_ID ASC , OLFT_FORMAT_T\
YPE ASC , OLFT_FORMAT_VALUE ASC            ";

 static char *sq0002 = 
"SELECT OLFT_FORMAT_ID , lower ( OLFT_FORMAT_TYPE ) OLFT_FORMAT_TYPE , OLFT_\
FORMAT_VALUE , OLFT_CONT_DESC , OLFT_CONT_DESC_2 , OLFT_CONT_TEMPLATE , OLFT_\
CONT_NEXT_LVL FROM OL_STMT_FORMAT_TEMPLATE WHERE OLFT_FORMAT_ID like :b0 || '\
%' ORDER BY OLFT_FORMAT_ID ASC , OLFT_FORMAT_TYPE ASC , OLFT_FORMAT_VALUE ASC\
            ";

 static char *sq0003 = 
"_CCY ) ) OR TR1 . OLFR_INT_BANK_CODE\
 = :b0 ) ) ON OBTC_CODE = OLFR_CODE AND OBTM_RANGE = 1 LEFT JOIN ( SELECT TK \
. OLFK_FORMAT_TXN_CODE , TK . OLFK_DISPLAY_ORDER , TP . OLFT_CONT_DESC , TK .\
 OLFK_FORMAT_TEMPLATE FROM OL_STMT_FORMAT_KEYWORDS TK , OL_STMT_FORMAT_TEMPLA\
TE TP WHERE TK . OLFK_INT_BANK_CODE = :b0 AND TK . OLFK_FORMAT_TYPE = 'TXN_CO\
DE_' || :b1 AND TK . OLFK_DISABLED = 0 AND TK . OLFK_FORMAT_COL_NAME = TP . O\
LFT_CONT_COL_NAME AND TP . OLFT_FORMAT_ID LIKE :b7 || '%' AND TP . OLFT_FORMA\
T_TYPE = 'CONTENT' ) ON OBTC_CODE = OLFK_FORMAT_TXN_CODE AND OBTM_DEFAULT = 0\
 WHERE ( OBTM_DEFAULT = 1 OR OLFK_FORMAT_TEMPLATE IS NOT NULL ) ORDER BY OBTC\
_AMT_TYPE ASC , OBTM_DEFAULT ASC , OBTM_PRIORITY DESC , OLFK_DISPLAY_ORDER AS\
C            ";

 static char *sq0004 = 
"LFR_CCY = TR1 . OLFR_CCY ) ) OR TR1 \
. OLFR_INT_BANK_CODE = :b0 ) ) ON OBTC_CODE = OLFR_CODE AND OBTM_RANGE = 1 LE\
FT JOIN ( SELECT TK . OLFK_FORMAT_TXN_CODE , TK . OLFK_DISPLAY_ORDER , TP . O\
LFT_CONT_DESC , TK . OLFK_FORMAT_TEMPLATE FROM OL_STMT_FORMAT_KEYWORDS TK , O\
L_STMT_FORMAT_TEMPLATE TP WHERE TK . OLFK_INT_BANK_CODE = :b0 AND TK . OLFK_F\
ORMAT_TYPE = 'TXN_CODE_' || :b2 AND TK . OLFK_DISABLED = 0 AND TK . OLFK_FORM\
AT_COL_NAME = TP . OLFT_CONT_COL_NAME AND TP . OLFT_FORMAT_ID LIKE :b8 || '%'\
 AND TP . OLFT_FORMAT_TYPE = 'CONTENT' ) ON OBTC_CODE = OLFK_FORMAT_TXN_CODE \
AND OBTM_DEFAULT = 0 WHERE ( OBTM_DEFAULT = 1 OR OLFK_FORMAT_TEMPLATE IS NOT \
NULL ) ORDER BY OBTC_AMT_TYPE ASC , OBTM_DEFAULT ASC , OBTM_PRIORITY DESC , O\
LFK_DISPLAY_ORDER ASC            ";

 static char *sq0005 = 
"_CCY ) ) OR TR1 . OLFR_INT_BANK_CODE\
 = :b0 ) ) ON OBTC_CODE = OLFR_CODE AND OBTM_RANGE = 1 LEFT JOIN ( SELECT TK \
. OLFK_FORMAT_TXN_CODE , TK . OLFK_DISPLAY_ORDER , TP . OLFT_CONT_DESC , TK .\
 OLFK_FORMAT_TEMPLATE FROM OL_STMT_FORMAT_KEYWORDS TK , OL_STMT_FORMAT_TEMPLA\
TE TP WHERE TK . OLFK_INT_BANK_CODE = :b0 AND TK . OLFK_FORMAT_TYPE = 'TXN_CO\
DE_' || :b1 AND TK . OLFK_DISABLED = 0 AND TK . OLFK_FORMAT_COL_NAME = TP . O\
LFT_CONT_COL_NAME AND TP . OLFT_FORMAT_ID LIKE :b7 || '%' AND TP . OLFT_FORMA\
T_TYPE = 'CONTENT' ) ON OBTC_CODE = OLFK_FORMAT_TXN_CODE WHERE OLFK_FORMAT_TE\
MPLATE IS NOT NULL ORDER BY OBTC_AMT_TYPE ASC , OBTM_DEFAULT ASC , OBTM_PRIOR\
ITY DESC , OLFK_DISPLAY_ORDER ASC            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,503,0,9,98,0,2049,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,13,100,0,0,7,0,0,1,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,3,0,0,
67,0,0,1,0,0,15,235,0,0,0,0,0,1,0,
82,0,0,1,0,0,15,256,0,0,0,0,0,1,0,
97,0,0,2,318,0,9,321,0,2049,1,1,0,1,0,1,9,0,0,
116,0,0,2,0,0,13,323,0,0,7,0,0,1,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,3,0,0,
159,0,0,2,0,0,15,431,0,0,0,0,0,1,0,
174,0,0,2,0,0,15,452,0,0,0,0,0,1,0,
189,0,0,3,1766,0,9,590,0,2049,8,8,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,9,0,0,
236,0,0,3,0,0,13,592,0,0,11,0,0,1,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,4,0,0,2,
4,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,9,0,0,2,9,0,0,
295,0,0,3,0,0,15,728,0,0,0,0,0,1,0,
310,0,0,3,0,0,15,745,0,0,0,0,0,1,0,
325,0,0,4,1786,0,9,891,0,2049,9,9,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
376,0,0,4,0,0,13,893,0,0,11,0,0,1,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,4,0,0,2,
4,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,9,0,0,2,9,0,0,
435,0,0,4,0,0,15,1029,0,0,0,0,0,1,0,
450,0,0,4,0,0,15,1046,0,0,0,0,0,1,0,
465,0,0,5,1721,0,9,1185,0,2049,8,8,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,9,0,0,
512,0,0,5,0,0,13,1187,0,0,11,0,0,1,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,4,0,0,2,
4,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,9,0,0,2,9,0,0,
571,0,0,5,0,0,15,1322,0,0,0,0,0,1,0,
586,0,0,5,0,0,15,1339,0,0,0,0,0,1,0,
601,0,0,6,382,0,6,1467,0,0,10,10,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,9,0,0,
1,9,0,0,1,9,0,0,3,3,0,0,1,3,0,0,1,9,0,0,
656,0,0,7,382,0,6,1642,0,0,10,10,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,9,0,0,
1,9,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,9,0,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/07/17              [STP]
Get update_bal in GetTxnCodeKeywords               2014/07/16              [WCS]
Add GetTxnCodeKeywordsAll			   2018/05/16		   [WCS]
Reduce Log					   2021/05/17		   [WCS]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "OLStmtFormat.h"
#include "internal.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define PD_DEFAULT_DATE_FORMAT          "%Y%m%d"
#define PD_DEFAULT_TIME_FORMAT          "%H%M%S"

static char cDebug;

void OLStmtFormat(char cdebug)
{
	cDebug = cdebug;
}


int GetFormat(const char* csIntBankCode, recordset_t* myRec)
{
	int iRet = PD_OK;
	int iCnt = 0;

	char csFormatId[PD_FORMAT_ID_LEN + 1];
	char csCurrFormatId[PD_FORMAT_ID_LEN + 1];

	char csFormatType[PD_FORMAT_TYPE_LEN + 1];
	char csFormatValue[PD_FORMAT_VALUE_LEN + 1];

	char *csTmp;
	char *csTag = (char*) malloc (64);

	hash_t *myHash;
	myHash = (hash_t*) malloc (sizeof(hash_t));
	hash_init(myHash, 0);

DEBUGLOG(("GetFormat Start\n"));

	/* EXEC SQL WHENEVER SQLERROR GOTO getformat_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_int_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } hv_int_bank_code;

		/* varchar	v_format_id[PD_FORMAT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_format_id;

		/* varchar	v_format_type[PD_FORMAT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_format_type;

		int	v_format_value;
		/* varchar	v_cont_desc[PD_CONT_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_cont_desc;

		/* varchar	v_cont_desc_2[PD_CONT_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_cont_desc_2;

		/* varchar	v_cont_template[PD_CONT_TEMPLATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_cont_template;

		int	v_cont_next_lvl;

		short ind_format_id = -1;
		short ind_format_type = -1;
		short ind_format_value = -1;
		short ind_cont_desc = -1;
		short ind_cont_desc_2 = -1;
		short ind_cont_template = -1;
		short ind_cont_next_lvl = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_int_bank_code.len = strlen(csIntBankCode);
	strncpy((char*)hv_int_bank_code.arr, csIntBankCode, hv_int_bank_code.len);
DEBUGLOG(("int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));

	/* EXEC SQL DECLARE getformatcursor CURSOR FOR
		SELECT	OLFT_FORMAT_ID,
			lower(OLFT_FORMAT_TYPE) OLFT_FORMAT_TYPE,
			OLFT_FORMAT_VALUE,
			OLFT_CONT_DESC,
			OLFT_CONT_DESC_2,
			OLFT_CONT_TEMPLATE,
			OLFT_CONT_NEXT_LVL
		FROM	OL_STMT_FORMAT_TEMPLATE, OL_STMT_FORMAT
		WHERE	OLSF_INT_BANK_CODE = :hv_int_bank_code
		AND	(OLFT_FORMAT_ID = OLSF_FORMAT_ID or OLFT_FORMAT_ID like OLSF_FORMAT_ID||'.%')
		AND	OLSF_DISABLED = 0
		AND	OLSF_EFFECT_TIMESTAMP <= sysdate
		ORDER BY OLSF_EFFECT_TIMESTAMP DESC, OLFT_FORMAT_ID ASC, OLFT_FORMAT_TYPE ASC, OLFT_FORMAT_VALUE ASC; */ 


	/* EXEC SQL OPEN getformatcursor; */ 

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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[0] = (unsigned long )13;
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
 if (sqlca.sqlcode < 0) goto getformat_error;
}


	for (;;) {
		/* EXEC SQL FETCH getformatcursor
		INTO	:v_format_id:ind_format_id,
			:v_format_type:ind_format_type,
			:v_format_value:ind_format_value,
			:v_cont_desc:ind_cont_desc,
			:v_cont_desc_2:ind_cont_desc_2,
			:v_cont_template:ind_cont_template,
			:v_cont_next_lvl:ind_cont_next_lvl; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
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
  sqlstm.sqhstv[0] = (unsigned char  *)&v_format_id;
  sqlstm.sqhstl[0] = (unsigned long )23;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_format_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_format_type;
  sqlstm.sqhstl[1] = (unsigned long )23;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_format_type;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_format_value;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_format_value;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_cont_desc;
  sqlstm.sqhstl[3] = (unsigned long )53;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_cont_desc;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_cont_desc_2;
  sqlstm.sqhstl[4] = (unsigned long )53;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_cont_desc_2;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_cont_template;
  sqlstm.sqhstl[5] = (unsigned long )53;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_cont_template;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_cont_next_lvl;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_cont_next_lvl;
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
  if (sqlca.sqlcode < 0) goto getformat_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

/* format_id */
		if (ind_format_id >= 0) {
			v_format_id.arr[v_format_id.len] = '\0';
			strcpy(csCurrFormatId, (const char*)v_format_id.arr);
			if (iCnt == 1) {
				strcpy(csFormatId, (const char*)v_format_id.arr);
				PutField_CString(myHash, "format_id", csFormatId); //
DEBUGLOG(("read (%s) = [%s]\n", "format_id", csFormatId));
			} else {
				csTmp = mystrtok(csCurrFormatId, ".");
				if (csTmp != NULL && strcmp(csTmp, csFormatId)) {
					RecordSet_Add(myRec, myHash);
DEBUGLOG(("** hash added - (format_id) = [%s]\n", csFormatId));
					myHash = (hash_t*) malloc (sizeof(hash_t));
					hash_init(myHash, 0);
					strcpy(csFormatId, (const char*)v_format_id.arr);
					PutField_CString(myHash, "format_id", csFormatId); //
DEBUGLOG(("read (%s) = [%s]\n", "format_id", csFormatId));
				}
				strcpy(csCurrFormatId, (const char*)v_format_id.arr);
			}
		} else {
			iRet = INT_FORMAT_TEMPLATE_ERROR;
DEBUGLOG(("format_id NOT FOUND!!!\n"));
			break;
		}

/* format_type */
		if (ind_format_type >= 0) {
			v_format_type.arr[v_format_type.len] = '\0';
			sprintf(csFormatType, "%s", (char*)v_format_type.arr);
		} else {
			iRet = INT_FORMAT_TEMPLATE_ERROR;
DEBUGLOG(("format_type NOT FOUND!!!\n"));
			break;
		}

/* format_value - All Except CONTENT */
		if (ind_format_value >= 0) {
			sprintf(csFormatValue,"%d",v_format_value);

			if (strcmp(csFormatType,"content")) {
				if (!strcmp(csFormatType,"delimiter")) {
					sprintf(csTag, "%s_%s", csFormatType, csCurrFormatId);
				} else {
					sprintf(csTag, "%s", csFormatType);
				}
				PutField_CString(myHash, csTag, csFormatValue); //
DEBUGLOG(("(%s) = [%s]\n", csTag, csFormatValue));
			}
		} else {
			iRet = INT_FORMAT_TEMPLATE_ERROR;
DEBUGLOG(("format_value NOT FOUND!!!\n"));
			break;
		}

/* cont_desc - CONTENT */
		if (ind_cont_desc >= 0) { 
			v_cont_desc.arr[v_cont_desc.len] = '\0';
			sprintf(csTag, "%s_desc_%s_%s", csFormatType, csCurrFormatId, csFormatValue);
			PutField_CString(myHash, csTag, (const char *)v_cont_desc.arr); //
DEBUGLOG(("(%s) = [%s]\n", csTag, v_cont_desc.arr));

		/* cont_template - CONTENT */
			if (ind_cont_template >= 0) {
				v_cont_template.arr[v_cont_template.len] = '\0';
				if (!strcmp((char*)v_cont_desc.arr,"statement_date")) {
					PutField_CString(myHash, "DATE_FORMAT", (const char *)v_cont_template.arr); //
DEBUGLOG(("(%s) = [%s]\n", "DATE_FORMAT", (const char *)v_cont_template.arr));
				} else if (!strcmp((char*)v_cont_desc.arr,"statement_time")) {
					PutField_CString(myHash, "TIME_FORMAT", (const char *)v_cont_template.arr); //
DEBUGLOG(("(%s) = [%s]\n", "TIME_FORMAT", (const char *)v_cont_template.arr));
				}
			} else {
				if (!strcmp((char*)v_cont_desc.arr,"statement_date")) {
					PutField_CString(myHash, "DATE_FORMAT", PD_DEFAULT_DATE_FORMAT); //
DEBUGLOG(("(%s) default = [%s]\n", "DATE_FORMAT", PD_DEFAULT_DATE_FORMAT));
				} else if (!strcmp((char*)v_cont_desc.arr,"statement_time")) {
					PutField_CString(myHash, "TIME_FORMAT", PD_DEFAULT_TIME_FORMAT); //
DEBUGLOG(("(%s) default = [%s]\n", "TIME_FORMAT", PD_DEFAULT_TIME_FORMAT));
				}
			}
		}

/* cont_desc_2 - CONTENT */
		if (ind_cont_desc_2 >= 0) { 
			v_cont_desc_2.arr[v_cont_desc_2.len] = '\0';
			sprintf(csTag, "%s_desc_2_%s_%s", csFormatType, csCurrFormatId, csFormatValue);
			PutField_CString(myHash, csTag, (const char *)v_cont_desc_2.arr); //
DEBUGLOG(("(%s) = [%s]\n", csTag, v_cont_desc_2.arr));
		}


/* cont_next_lvl - CONTENT */
		if (ind_cont_next_lvl >= 0) {
			if (v_cont_next_lvl == 1) {
				sprintf(csTag, "%s_nxlv_%s_%s", csFormatType, csCurrFormatId, csFormatValue);
				PutField_Int(myHash, csTag, v_cont_next_lvl); //
DEBUGLOG(("(%s) = [%d]\n", csTag, v_cont_next_lvl));

			/* cont_template - CONTENT */
				if (ind_cont_template >= 0) {
					v_cont_template.arr[v_cont_template.len] = '\0';
					sprintf(csTag, "%s_temp_%s_%s", csFormatType, csCurrFormatId, csFormatValue);
					PutField_CString(myHash, csTag, (const char *)v_cont_template.arr); //
DEBUGLOG(("(%s) = [%s]\n", csTag, v_cont_template.arr));

					if (strlen(csCurrFormatId) >= strlen((char*)v_cont_template.arr)) {
						iRet = INT_FORMAT_TEMPLATE_ERROR;
DEBUGLOG(("cont_template INVALID!!!\n"));
						break;
					}
				} else {
					iRet = INT_FORMAT_TEMPLATE_ERROR;
DEBUGLOG(("cont_template NOT FOUND!!!\n"));
				}
			}
		}

	}
	/* EXEC SQL CLOSE getformatcursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )67;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getformat_error;
}



	if (iCnt > 0) {
		RecordSet_Add(myRec, myHash);
DEBUGLOG(("** hash added - (format_id) = [%s]\n", csFormatId));
	} else {
DEBUGLOG(("NOT FOUND!!!\n"));
ERRLOG("OLStmtFormat::GetFormat NOT FOUND!!!\n");
		iRet = PD_ERR;
	}

	FREE_ME(csTag);

DEBUGLOG(("GetFormat Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getformat_error:
DEBUGLOG(("getformat_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStmtFormat getformat_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL CLOSE getformatcursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )82;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getformat_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int GetByFormatId(const char* csFormatId, recordset_t* myRec)
{
	int iRet = PD_OK;
	int iCnt = 0;

	char csCurrFormatId[PD_FORMAT_ID_LEN + 1];

	char csFormatType[PD_FORMAT_TYPE_LEN + 1];
	char csFormatValue[PD_FORMAT_VALUE_LEN + 1];

	char *csTag = (char*) malloc (64);

	hash_t *myHash;
	myHash = (hash_t*) malloc (sizeof(hash_t));
	hash_init(myHash, 0);

DEBUGLOG(("GetByFormatId Start\n"));

	strcpy(csCurrFormatId,csFormatId);
	PutField_CString(myHash, "format_id", csCurrFormatId); //

	/* EXEC SQL WHENEVER SQLERROR GOTO getformat_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_format_id[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } hv_format_id;

		/* varchar	v_format_id[PD_FORMAT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_format_id;

		/* varchar	v_format_type[PD_FORMAT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_format_type;

		int	v_format_value;
		/* varchar	v_cont_desc[PD_CONT_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_cont_desc;

		/* varchar	v_cont_desc_2[PD_CONT_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_cont_desc_2;

		/* varchar	v_cont_template[PD_CONT_TEMPLATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_cont_template;

		int	v_cont_next_lvl;

		short ind_format_id = -1;
		short ind_format_type = -1;
		short ind_format_value = -1;
		short ind_cont_desc = -1;
		short ind_cont_desc_2 = -1;
		short ind_cont_template = -1;
		short ind_cont_next_lvl = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_format_id.len = strlen(csFormatId);
	strncpy((char*)hv_format_id.arr, csFormatId, hv_format_id.len);
DEBUGLOG(("format_id = [%.*s]\n", hv_format_id.len, hv_format_id.arr));

	/* EXEC SQL DECLARE getbyformatidcursor CURSOR FOR
		SELECT	OLFT_FORMAT_ID,
			lower(OLFT_FORMAT_TYPE) OLFT_FORMAT_TYPE,
			OLFT_FORMAT_VALUE,
			OLFT_CONT_DESC,
			OLFT_CONT_DESC_2,
			OLFT_CONT_TEMPLATE,
			OLFT_CONT_NEXT_LVL
		FROM	OL_STMT_FORMAT_TEMPLATE
		WHERE	OLFT_FORMAT_ID like :hv_format_id||'%'
		ORDER BY OLFT_FORMAT_ID ASC, OLFT_FORMAT_TYPE ASC, OLFT_FORMAT_VALUE ASC; */ 


	/* EXEC SQL OPEN getbyformatidcursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )97;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_format_id;
 sqlstm.sqhstl[0] = (unsigned long )13;
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
 if (sqlca.sqlcode < 0) goto getformat_error;
}


	for (;;) {
		/* EXEC SQL FETCH getbyformatidcursor
		INTO	:v_format_id:ind_format_id,
			:v_format_type:ind_format_type,
			:v_format_value:ind_format_value,
			:v_cont_desc:ind_cont_desc,
			:v_cont_desc_2:ind_cont_desc_2,
			:v_cont_template:ind_cont_template,
			:v_cont_next_lvl:ind_cont_next_lvl; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )116;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_format_id;
  sqlstm.sqhstl[0] = (unsigned long )23;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_format_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_format_type;
  sqlstm.sqhstl[1] = (unsigned long )23;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_format_type;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_format_value;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_format_value;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_cont_desc;
  sqlstm.sqhstl[3] = (unsigned long )53;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_cont_desc;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_cont_desc_2;
  sqlstm.sqhstl[4] = (unsigned long )53;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_cont_desc_2;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_cont_template;
  sqlstm.sqhstl[5] = (unsigned long )53;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_cont_template;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_cont_next_lvl;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_cont_next_lvl;
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
  if (sqlca.sqlcode < 0) goto getformat_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

/* format_type */
		if (ind_format_type >= 0) {
			v_format_type.arr[v_format_type.len] = '\0';
			sprintf(csFormatType, "%s", (char*)v_format_type.arr);
		} else {
			iRet = INT_FORMAT_TEMPLATE_ERROR;
DEBUGLOG(("format_type NOT FOUND!!!\n"));
			break;
		}

/* format_value - All Except CONTENT */
		if (ind_format_value >= 0) {
			sprintf(csFormatValue,"%d",v_format_value);

			if (strcmp(csFormatType,"content")) {
				if (!strcmp(csFormatType,"delimiter")) {
					sprintf(csTag, "%s_%s", csFormatType, csCurrFormatId);
				} else {
					sprintf(csTag, "%s", csFormatType);
				}
				PutField_CString(myHash, csTag, csFormatValue); //
DEBUGLOG(("(%s) = [%s]\n", csTag, csFormatValue));
			}
		} else {
			iRet = INT_FORMAT_TEMPLATE_ERROR;
DEBUGLOG(("format_value NOT FOUND!!!\n"));
			break;
		}

/* cont_desc - CONTENT */
		if (ind_cont_desc >= 0) { 
			v_cont_desc.arr[v_cont_desc.len] = '\0';
			sprintf(csTag, "%s_desc_%s_%s", csFormatType, csCurrFormatId, csFormatValue);
			PutField_CString(myHash, csTag, (const char *)v_cont_desc.arr); //
DEBUGLOG(("(%s) = [%s]\n", csTag, v_cont_desc.arr));

		/* cont_template - CONTENT */
			if (ind_cont_template >= 0) {
				v_cont_template.arr[v_cont_template.len] = '\0';
				if (!strcmp((char*)v_cont_desc.arr,"statement_date")) {
					PutField_CString(myHash, "DATE_FORMAT", (const char *)v_cont_template.arr); //
DEBUGLOG(("(%s) = [%s]\n", "DATE_FORMAT", (const char *)v_cont_template.arr));
				} else if (!strcmp((char*)v_cont_desc.arr,"statement_time")) {
					PutField_CString(myHash, "TIME_FORMAT", (const char *)v_cont_template.arr); //
DEBUGLOG(("(%s) = [%s]\n", "TIME_FORMAT", (const char *)v_cont_template.arr));
				}
			} else {
				if (!strcmp((char*)v_cont_desc.arr,"statement_date")) {
					PutField_CString(myHash, "DATE_FORMAT", PD_DEFAULT_DATE_FORMAT); //
DEBUGLOG(("(%s) default = [%s]\n", "DATE_FORMAT", PD_DEFAULT_DATE_FORMAT));
				} else if (!strcmp((char*)v_cont_desc.arr,"statement_time")) {
					PutField_CString(myHash, "TIME_FORMAT", PD_DEFAULT_TIME_FORMAT); //
DEBUGLOG(("(%s) default = [%s]\n", "TIME_FORMAT", PD_DEFAULT_TIME_FORMAT));
				}
			}
		}

/* cont_desc_2 - CONTENT */
		if (ind_cont_desc_2 >= 0) { 
			v_cont_desc_2.arr[v_cont_desc_2.len] = '\0';
			sprintf(csTag, "%s_desc_2_%s_%s", csFormatType, csCurrFormatId, csFormatValue);
			PutField_CString(myHash, csTag, (const char *)v_cont_desc_2.arr); //
DEBUGLOG(("(%s) = [%s]\n", csTag, v_cont_desc_2.arr));
		}


/* cont_next_lvl - CONTENT */
		if (ind_cont_next_lvl >= 0) {
			if (v_cont_next_lvl == 1) {
				sprintf(csTag, "%s_nxlv_%s_%s", csFormatType, csCurrFormatId, csFormatValue);
				PutField_Int(myHash, csTag, v_cont_next_lvl); //
DEBUGLOG(("(%s) = [%d]\n", csTag, v_cont_next_lvl));

			/* cont_template - CONTENT */
				if (ind_cont_template >= 0) {
					v_cont_template.arr[v_cont_template.len] = '\0';
					sprintf(csTag, "%s_temp_%s_%s", csFormatType, csCurrFormatId, csFormatValue);
					PutField_CString(myHash, csTag, (const char *)v_cont_template.arr); //
DEBUGLOG(("(%s) = [%s]\n", csTag, v_cont_template.arr));

					if (strlen(csCurrFormatId) >= strlen((char*)v_cont_template.arr)) {
						iRet = INT_FORMAT_TEMPLATE_ERROR;
DEBUGLOG(("cont_template INVALID!!!\n"));
						break;
					}
				} else {
					iRet = INT_FORMAT_TEMPLATE_ERROR;
DEBUGLOG(("cont_template NOT FOUND!!!\n"));
				}
			}
		}

	}
	/* EXEC SQL CLOSE getbyformatidcursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )159;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getformat_error;
}



	if (iCnt > 0) {
		RecordSet_Add(myRec, myHash);
DEBUGLOG(("** hash added - (format_id) = [%s]\n", csFormatId));
	} else {
DEBUGLOG(("NOT FOUND!!!\n"));
ERRLOG("OLStmtFormat::GetByFormatId NOT FOUND!!!\n");
		iRet = PD_ERR;
	}

	FREE_ME(csTag);

DEBUGLOG(("GetByFormatId Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getformat_error:
DEBUGLOG(("getformat_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStmtFormat getformat_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL CLOSE getbyformatidcursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )174;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getformat_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int GetTxnCodeKeywords(const hash_t* hContext, recordset_t* myRec)
{
	int iRet = PD_FOUND;
	int iCnt = 0;
	char *csTmp;

	hash_t *hRec;

DEBUGLOG(("GetTxnCodeKeywords Start\n"));

	/* EXEC SQL WHENEVER SQLERROR GOTO gettxncode_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_format_id[PD_FORMAT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_format_id;

		/* varchar	hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar	hv_bank_acct_type[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_bank_acct_type;

		/* varchar	hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

		/* varchar	v_txn_code[PD_TXN_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

		/* varchar	v_amt_type[PD_AMT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_amt_type;

		int	v_full_match;
		int	v_default;
		double	v_min_amt;
		double	v_max_amt;
		int	v_min_dp;
		int	v_max_dp;
		int	v_display_order;
		/* varchar	v_cont_desc[PD_CONT_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_cont_desc;

		/* varchar	v_format_template[PD_FORMAT_TEMPLATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[501]; } v_format_template;


		short	ind_txn_code = -1;
		short	ind_amt_type = -1;
		short	ind_full_match = -1;
		short	ind_default = -1;
		short	ind_min_amt = -1;
		short	ind_max_amt = -1;
		short	ind_min_dp = -1;
		short	ind_max_dp = -1;
		short	ind_display_order = -1;
		short	ind_cont_desc = -1;
		short	ind_format_template = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hContext,"format_id",&csTmp)) {
		hv_format_id.len = strlen(csTmp);
		strncpy((char*)hv_format_id.arr, csTmp, hv_format_id.len);
DEBUGLOG(("format_id = [%.*s]\n", hv_format_id.len, hv_format_id.arr));
	}

	if (GetField_CString(hContext,"int_bank_code",&csTmp)) {
		hv_int_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_int_bank_code.arr, csTmp, hv_int_bank_code.len);
DEBUGLOG(("int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));
	}

	if (GetField_CString(hContext,"bank_acct_type",&csTmp)) {
		hv_bank_acct_type.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_type.arr, csTmp, hv_bank_acct_type.len);
DEBUGLOG(("bank_acct_type = [%.*s]\n", hv_bank_acct_type.len, hv_bank_acct_type.arr));
	}

	if (GetField_CString(hContext,"acct_ccy",&csTmp)) {
		hv_ccy.len = strlen(csTmp);
		strncpy((char*)hv_ccy.arr, csTmp, hv_ccy.len);
DEBUGLOG(("ccy = [%.*s]\n", hv_ccy.len, hv_ccy.arr));
	}

	/* EXEC SQL DECLARE gettxncodecursor CURSOR FOR
		SELECT	OBTC_CODE,
			OBTC_AMT_TYPE,
			OBTM_FULL_MATCH,
			OBTM_DEFAULT,
			OLFR_MIN_AMT,
			OLFR_MAX_AMT,
			OLFR_MIN_DP,
			OLFR_MAX_DP,
			OLFK_DISPLAY_ORDER,
			OLFT_CONT_DESC,
			OLFK_FORMAT_TEMPLATE
		FROM	(SELECT OBTC_CODE,
				OBTC_AMT_TYPE,
				OBTM_RANGE,
				NVL(OFKO_IS_DEFAULT, OBTM_DEFAULT) OBTM_DEFAULT,
				OBTM_PRIORITY,
				OBTM_FULL_MATCH,
				OBTM_REAL_TIME_POST, //@@
				OBTM_UPDATE_BAL //@@
			FROM	OL_BAID_TXN_CODE,
				OL_BAID_TXN_CODE_MAPPING
				LEFT JOIN OL_STMT_FORMAT_KEYWORDS_OVER
				ON OFKO_INT_BANK_CODE = :hv_int_bank_code
				AND OBTM_BANK_ACCT_TYPE = OFKO_BANK_ACCT_TYPE
				AND OBTM_CODE = OFKO_BAID_TXN_CODE
			WHERE	OBTM_CODE = OBTC_CODE
			AND	OBTM_BANK_ACCT_TYPE = :hv_bank_acct_type
			AND	OBTM_KEYWORDS = 1)
		LEFT JOIN
			(SELECT	OLFR_INT_BANK_CODE,
				OLFR_CODE,
				OLFR_CCY,
				OLFR_MIN_AMT,
				OLFR_MAX_AMT,
				OLFR_MIN_DP,
				OLFR_MAX_DP
			FROM	OL_STMT_FORMAT_RANGE TR1
			WHERE	TR1.OLFR_CCY = :hv_ccy
			AND	((TR1.OLFR_INT_BANK_CODE = '000' AND NOT EXISTS
					(SELECT * FROM OL_STMT_FORMAT_RANGE TR2
					WHERE	TR2.OLFR_INT_BANK_CODE = :hv_int_bank_code
					AND	TR2.OLFR_CODE = TR1.OLFR_CODE
					AND	TR2.OLFR_CCY = TR1.OLFR_CCY))
				OR	TR1.OLFR_INT_BANK_CODE = :hv_int_bank_code))
		ON	OBTC_CODE = OLFR_CODE
		AND	OBTM_RANGE = 1
		LEFT JOIN 
			(SELECT TK.OLFK_FORMAT_TXN_CODE,
				TK.OLFK_DISPLAY_ORDER,
				TP.OLFT_CONT_DESC,
				TK.OLFK_FORMAT_TEMPLATE
			FROM	OL_STMT_FORMAT_KEYWORDS TK,
				OL_STMT_FORMAT_TEMPLATE TP
			WHERE	TK.OLFK_INT_BANK_CODE = :hv_int_bank_code
			AND	TK.OLFK_FORMAT_TYPE = 'TXN_CODE_'||:hv_bank_acct_type
			AND	TK.OLFK_DISABLED = 0
			AND	TK.OLFK_FORMAT_COL_NAME = TP.OLFT_CONT_COL_NAME
			AND	TP.OLFT_FORMAT_ID LIKE :hv_format_id|| '%'
			AND	TP.OLFT_FORMAT_TYPE = 'CONTENT')
		ON	OBTC_CODE = OLFK_FORMAT_TXN_CODE
		AND	OBTM_DEFAULT = 0
		WHERE	(OBTM_DEFAULT = 1 OR OLFK_FORMAT_TEMPLATE IS NOT NULL)
		ORDER BY OBTC_AMT_TYPE ASC, OBTM_DEFAULT ASC, OBTM_PRIORITY DESC, OLFK_DISPLAY_ORDER ASC; */ 


	/* EXEC SQL OPEN gettxncodecursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "SELECT OBTC_CODE , OBTC_AMT_TYPE , OBTM_FULL_MATCH , OBTM_DEFAULT , OLFR\
_MIN_AMT , OLFR_MAX_AMT , OLFR_MIN_DP , OLFR_MAX_DP , OLFK_DISPLAY_ORDER , O\
LFT_CONT_DESC , OLFK_FORMAT_TEMPLATE FROM ( SELECT OBTC_CODE , OBTC_AMT_TYPE\
 , OBTM_RANGE , NVL ( OFKO_IS_DEFAULT , OBTM_DEFAULT ) OBTM_DEFAULT , OBTM_P\
RIORITY , OBTM_FULL_MATCH , OBTM_REAL_TIME_POST , OBTM_UPDATE_BAL FROM OL_BA\
ID_TXN_CODE , OL_BAID_TXN_CODE_MAPPING LEFT JOIN OL_STMT_FORMAT_KEYWORDS_OVE\
R ON OFKO_INT_BANK_CODE = :b0 AND OBTM_BANK_ACCT_TYPE = OFKO_BANK_ACCT_TYPE \
AND OBTM_CODE = OFKO_BAID_TXN_CODE WHERE OBTM_CODE = OBTC_CODE AND OBTM_BANK\
_ACCT_TYPE = :b1 AND OBTM_KEYWORDS = 1 ) LEFT JOIN ( SELECT OLFR_INT_BANK_CO\
DE , OLFR_CODE , OLFR_CCY , OLFR_MIN_AMT , OLFR_MAX_AMT , OLFR_MIN_DP , OLFR\
_MAX_DP FROM OL_STMT_FORMAT_RANGE TR1 WHERE TR1 . OLFR_CCY = :b2 AND ( ( TR1\
 . OLFR_INT_BANK_CODE = '000' AND NOT EXISTS ( SELECT * FROM OL_STMT_FORMAT_\
RANGE TR2 WHERE TR2 . OLFR_INT_BANK_CODE = :b0 AND TR2 . OLFR_CODE = TR1 . O\
LFR_CODE AND TR2 . OLFR_CCY = TR1 . OLFR");
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )189;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[0] = (unsigned long )12;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_acct_type;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_ccy;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[3] = (unsigned long )12;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
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
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[5] = (unsigned long )12;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_bank_acct_type;
 sqlstm.sqhstl[6] = (unsigned long )5;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_format_id;
 sqlstm.sqhstl[7] = (unsigned long )22;
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
 if (sqlca.sqlcode < 0) goto gettxncode_error;
}


	for (;;) {
		/* EXEC SQL FETCH gettxncodecursor
		INTO	:v_txn_code:ind_txn_code,
			:v_amt_type:ind_amt_type,
			:v_full_match:ind_full_match,
			:v_default:ind_default,
			:v_min_amt:ind_min_amt,
			:v_max_amt:ind_max_amt,
			:v_min_dp:ind_min_dp,
			:v_max_dp:ind_max_dp,
			:v_display_order:ind_display_order,
			:v_cont_desc:ind_cont_desc,
			:v_format_template:ind_format_template; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 11;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )236;
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
  sqlstm.sqhstv[1] = (unsigned char  *)&v_amt_type;
  sqlstm.sqhstl[1] = (unsigned long )5;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_amt_type;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_full_match;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_full_match;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_default;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_default;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_min_amt;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_min_amt;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_max_amt;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_max_amt;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_min_dp;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_min_dp;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_max_dp;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_max_dp;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_display_order;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_display_order;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_cont_desc;
  sqlstm.sqhstl[9] = (unsigned long )53;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_cont_desc;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_format_template;
  sqlstm.sqhstl[10] = (unsigned long )503;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_format_template;
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
  if (sqlca.sqlcode < 0) goto gettxncode_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

		hRec = (hash_t*) malloc (sizeof(hash_t));
		hash_init(hRec, 0);

/* txn_code */
		if (ind_txn_code >= 0) {
			v_txn_code.arr[v_txn_code.len] = '\0';
			PutField_CString(hRec, "txn_code", (char*)v_txn_code.arr);
//DEBUGLOG(("txn_code = [%s]\n",v_txn_code.arr));
		} else {
			iRet = INT_FORMAT_KEYWORDS_ERROR;
DEBUGLOG(("txn_code NOT FOUND!!!\n"));
			break;
		}
/* amt_type */
		if (ind_amt_type >= 0) {
			v_amt_type.arr[v_amt_type.len] = '\0';
			PutField_CString(hRec, "amt_type", (char*)v_amt_type.arr);
// DEBUGLOG(("amt_type = [%s]\n",v_amt_type.arr));
		} else {
			iRet = INT_FORMAT_KEYWORDS_ERROR;
DEBUGLOG(("amt_type NOT FOUND!!!\n"));
			break;
		}
/* full_match */
		if (ind_full_match >= 0) {
			PutField_Int(hRec, "full_match", v_full_match);
// DEBUGLOG(("full_match = [%d]\n",v_full_match));
		} else {
			iRet = INT_FORMAT_KEYWORDS_ERROR;
DEBUGLOG(("full_match NOT FOUND!!!\n"));
			break;
		}
/* default */
		if (ind_default >= 0) {
			PutField_Int(hRec, "default", v_default);
// DEBUGLOG(("default = [%d]\n",v_default));

			if (v_default == 0) {
				/* cont_desc*/
				if (ind_cont_desc >= 0) {
					v_cont_desc.arr[v_cont_desc.len] = '\0';
					PutField_CString(hRec, "cont_desc", (char*)v_cont_desc.arr);
//DEBUGLOG(("cont_desc = [%s]\n",v_cont_desc.arr));
				} else {
					iRet = INT_FORMAT_KEYWORDS_ERROR;
DEBUGLOG(("cont_desc NOT FOUND!!!\n"));
					break;
				}
				/* format_template */
				if (ind_format_template >= 0) {
					v_format_template.arr[v_format_template.len] = '\0';
					PutField_CString(hRec, "format_template", (char*)v_format_template.arr);
//DEBUGLOG(("format_template = [%s]\n",v_format_template.arr));
				} else {
					iRet = INT_FORMAT_KEYWORDS_ERROR;
DEBUGLOG(("format_template NOT FOUND!!!\n"));
					break;
				}
DEBUGLOG(("txn_code = [%s], amt_type = [%s], full_match = [%d], cont_desc = [%s], format_template = [%s]\n", v_txn_code.arr, v_amt_type.arr, v_full_match, v_cont_desc.arr, v_format_template.arr));
			} else {
DEBUGLOG(("txn_code = [%s], amt_type = [%s], full_match = [%d]\n", v_txn_code.arr, v_amt_type.arr, v_full_match));
			}
		} else {
			iRet = INT_FORMAT_KEYWORDS_ERROR;
DEBUGLOG(("default NOT FOUND!!!\n"));
			break;
		}
/* min_amt */
		if (ind_min_amt >= 0) {
			PutField_Double(hRec, "min_amt", v_min_amt);
//DEBUGLOG(("min_amt = [%.2lf]\n",v_min_amt));
		} else {
			v_min_amt = -1.0;
			PutField_Double(hRec, "min_amt", -1.0);
		}
/* max_amt */
		if (ind_max_amt >= 0) {
			PutField_Double(hRec, "max_amt", v_max_amt);
//DEBUGLOG(("max_amt = [%.2lf]\n",v_max_amt));
		} else {
			v_max_amt = -1.0;
			PutField_Double(hRec, "max_amt", -1.0);
		}
/* min_dp */
		if (ind_min_dp >= 0) {
			PutField_Int(hRec, "min_dp", v_min_dp);
//DEBUGLOG(("min_dp = [%d]\n",v_min_dp));
		} else {
			v_min_dp = -1;
			PutField_Int(hRec, "min_dp", -1);
		}
/* max_dp */
		if (ind_max_dp >= 0) {
			PutField_Int(hRec, "max_dp", v_max_dp);
//DEBUGLOG(("max_dp = [%d]\n",v_max_dp));
		} else {
			v_max_dp = -1;
			PutField_Int(hRec, "max_dp", -1);
		}

		if ((ind_min_amt >= 0) || (ind_max_amt >= 0) || (ind_min_dp >= 0) || (ind_max_dp >= 0))
DEBUGLOG(("min_amt = [%.2lf], max_amt = [%.2lf], min_dp = [%d], max_dp = [%d]\n", v_min_amt, v_max_amt, v_min_dp, v_max_dp));

/* display_order */
		if (ind_display_order >= 0) {
			PutField_Int(hRec, "display_order", v_display_order);
// DEBUGLOG(("display_order = [%d]\n",v_display_order));
		} else if (ind_default >= 0) {
			if (v_default == 0) {
				iRet = INT_FORMAT_KEYWORDS_ERROR;
DEBUGLOG(("default NOT FOUND!!!\n"));
				break;
			}
		}

		RecordSet_Add(myRec,hRec);
	}
	/* EXEC SQL CLOSE gettxncodecursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )295;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto gettxncode_error;
}



	if (iCnt > 0) {
DEBUGLOG(("FOUND\n"));
	} else {
		iRet = PD_NOT_FOUND;
DEBUGLOG(("NOT FOUND!!!\n"));
	}

DEBUGLOG(("GetTxnCodeKeywords Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

gettxncode_error:
DEBUGLOG(("gettxncode_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStmtFormat gettxncode_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL CLOSE gettxncodecursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )310;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto gettxncode_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int GetTxnCodeKeywordsSingle(const hash_t* hContext, recordset_t* myRec)
{
	int iRet = PD_FOUND;
	int iCnt = 0;
	char *csTmp;

	hash_t *hRec;

DEBUGLOG(("GetTxnCodeKeywordsSingle Start\n"));

	/* EXEC SQL WHENEVER SQLERROR GOTO getkeywords_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_format_id[PD_FORMAT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_format_id;

		/* varchar	hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar	hv_bank_acct_type[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_bank_acct_type;

		/* varchar	hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

		/* varchar hv_baid_txn_code[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid_txn_code;

		/* varchar	v_txn_code[PD_TXN_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

		/* varchar	v_amt_type[PD_AMT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_amt_type;

		int	v_full_match;
		int	v_default;
		double	v_min_amt;
		double	v_max_amt;
		int	v_min_dp;
		int	v_max_dp;
		int	v_display_order;
		/* varchar	v_cont_desc[PD_CONT_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_cont_desc;

		/* varchar	v_format_template[PD_FORMAT_TEMPLATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[501]; } v_format_template;


		short	ind_txn_code = -1;
		short	ind_amt_type = -1;
		short	ind_full_match = -1;
		short	ind_default = -1;
		short	ind_min_amt = -1;
		short	ind_max_amt = -1;
		short	ind_min_dp = -1;
		short	ind_max_dp = -1;
		short	ind_display_order = -1;
		short	ind_cont_desc = -1;
		short	ind_format_template = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hContext,"format_id",&csTmp)) {
		hv_format_id.len = strlen(csTmp);
		strncpy((char*)hv_format_id.arr, csTmp, hv_format_id.len);
DEBUGLOG(("format_id = [%.*s]\n", hv_format_id.len, hv_format_id.arr));
	}

	if (GetField_CString(hContext,"int_bank_code",&csTmp)) {
		hv_int_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_int_bank_code.arr, csTmp, hv_int_bank_code.len);
DEBUGLOG(("int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));
	}

	if (GetField_CString(hContext,"bank_acct_type",&csTmp)) {
		hv_bank_acct_type.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_type.arr, csTmp, hv_bank_acct_type.len);
DEBUGLOG(("bank_acct_type = [%.*s]\n", hv_bank_acct_type.len, hv_bank_acct_type.arr));
	}

	if (GetField_CString(hContext,"acct_ccy",&csTmp)) {
		hv_ccy.len = strlen(csTmp);
		strncpy((char*)hv_ccy.arr, csTmp, hv_ccy.len);
DEBUGLOG(("ccy = [%.*s]\n", hv_ccy.len, hv_ccy.arr));
	}

	if (GetField_CString(hContext,"baid_txn_code",&csTmp)) {
		hv_baid_txn_code.len = strlen(csTmp);
		strncpy((char*)hv_baid_txn_code.arr, csTmp, hv_baid_txn_code.len);
DEBUGLOG(("baid_txn_code = [%.*s]\n", hv_baid_txn_code.len, hv_baid_txn_code.arr));
	}

	/* EXEC SQL DECLARE getkeywordscursor CURSOR FOR
		SELECT	OBTC_CODE,
			OBTC_AMT_TYPE,
			OBTM_FULL_MATCH,
			OBTM_DEFAULT,
			OLFR_MIN_AMT,
			OLFR_MAX_AMT,
			OLFR_MIN_DP,
			OLFR_MAX_DP,
			OLFK_DISPLAY_ORDER,
			OLFT_CONT_DESC,
			OLFK_FORMAT_TEMPLATE
		FROM	(SELECT OBTC_CODE,
				OBTC_AMT_TYPE,
				OBTM_RANGE,
				NVL(OFKO_IS_DEFAULT, OBTM_DEFAULT) OBTM_DEFAULT,
				OBTM_PRIORITY,
				OBTM_FULL_MATCH,
				OBTM_REAL_TIME_POST, //@@
				OBTM_UPDATE_BAL //@@
			FROM	OL_BAID_TXN_CODE,
				OL_BAID_TXN_CODE_MAPPING
				LEFT JOIN OL_STMT_FORMAT_KEYWORDS_OVER
				ON OFKO_INT_BANK_CODE = :hv_int_bank_code
				AND OBTM_BANK_ACCT_TYPE = OFKO_BANK_ACCT_TYPE
				AND OBTM_CODE = OFKO_BAID_TXN_CODE
			WHERE	OBTM_CODE = OBTC_CODE
			AND	OBTC_CODE = :hv_baid_txn_code
			AND	OBTM_BANK_ACCT_TYPE = :hv_bank_acct_type
			AND	OBTM_KEYWORDS = 1)
		LEFT JOIN
			(SELECT	OLFR_INT_BANK_CODE,
				OLFR_CODE,
				OLFR_CCY,
				OLFR_MIN_AMT,
				OLFR_MAX_AMT,
				OLFR_MIN_DP,
				OLFR_MAX_DP
			FROM	OL_STMT_FORMAT_RANGE TR1
			WHERE	TR1.OLFR_CCY = :hv_ccy
			AND	((TR1.OLFR_INT_BANK_CODE = '000' AND NOT EXISTS
					(SELECT * FROM OL_STMT_FORMAT_RANGE TR2
					WHERE	TR2.OLFR_INT_BANK_CODE = :hv_int_bank_code
					AND	TR2.OLFR_CODE = TR1.OLFR_CODE
					AND	TR2.OLFR_CCY = TR1.OLFR_CCY))
				OR	TR1.OLFR_INT_BANK_CODE = :hv_int_bank_code))
		ON	OBTC_CODE = OLFR_CODE
		AND	OBTM_RANGE = 1
		LEFT JOIN 
			(SELECT TK.OLFK_FORMAT_TXN_CODE,
				TK.OLFK_DISPLAY_ORDER,
				TP.OLFT_CONT_DESC,
				TK.OLFK_FORMAT_TEMPLATE
			FROM	OL_STMT_FORMAT_KEYWORDS TK,
				OL_STMT_FORMAT_TEMPLATE TP
			WHERE	TK.OLFK_INT_BANK_CODE = :hv_int_bank_code
			AND	TK.OLFK_FORMAT_TYPE = 'TXN_CODE_'||:hv_bank_acct_type
			AND	TK.OLFK_DISABLED = 0
			AND	TK.OLFK_FORMAT_COL_NAME = TP.OLFT_CONT_COL_NAME
			AND	TP.OLFT_FORMAT_ID LIKE :hv_format_id|| '%'
			AND	TP.OLFT_FORMAT_TYPE = 'CONTENT')
		ON	OBTC_CODE = OLFK_FORMAT_TXN_CODE
		AND	OBTM_DEFAULT = 0
		WHERE	(OBTM_DEFAULT = 1 OR OLFK_FORMAT_TEMPLATE IS NOT NULL)
		ORDER BY OBTC_AMT_TYPE ASC, OBTM_DEFAULT ASC, OBTM_PRIORITY DESC, OLFK_DISPLAY_ORDER ASC; */ 


	/* EXEC SQL OPEN getkeywordscursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "SELECT OBTC_CODE , OBTC_AMT_TYPE , OBTM_FULL_MATCH , OBTM_DEFAULT , OLFR\
_MIN_AMT , OLFR_MAX_AMT , OLFR_MIN_DP , OLFR_MAX_DP , OLFK_DISPLAY_ORDER , O\
LFT_CONT_DESC , OLFK_FORMAT_TEMPLATE FROM ( SELECT OBTC_CODE , OBTC_AMT_TYPE\
 , OBTM_RANGE , NVL ( OFKO_IS_DEFAULT , OBTM_DEFAULT ) OBTM_DEFAULT , OBTM_P\
RIORITY , OBTM_FULL_MATCH , OBTM_REAL_TIME_POST , OBTM_UPDATE_BAL FROM OL_BA\
ID_TXN_CODE , OL_BAID_TXN_CODE_MAPPING LEFT JOIN OL_STMT_FORMAT_KEYWORDS_OVE\
R ON OFKO_INT_BANK_CODE = :b0 AND OBTM_BANK_ACCT_TYPE = OFKO_BANK_ACCT_TYPE \
AND OBTM_CODE = OFKO_BAID_TXN_CODE WHERE OBTM_CODE = OBTC_CODE AND OBTC_CODE\
 = :b1 AND OBTM_BANK_ACCT_TYPE = :b2 AND OBTM_KEYWORDS = 1 ) LEFT JOIN ( SEL\
ECT OLFR_INT_BANK_CODE , OLFR_CODE , OLFR_CCY , OLFR_MIN_AMT , OLFR_MAX_AMT \
, OLFR_MIN_DP , OLFR_MAX_DP FROM OL_STMT_FORMAT_RANGE TR1 WHERE TR1 . OLFR_C\
CY = :b3 AND ( ( TR1 . OLFR_INT_BANK_CODE = '000' AND NOT EXISTS ( SELECT * \
FROM OL_STMT_FORMAT_RANGE TR2 WHERE TR2 . OLFR_INT_BANK_CODE = :b0 AND TR2 .\
 OLFR_CODE = TR1 . OLFR_CODE AND TR2 . O");
 sqlstm.stmt = sq0004;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )325;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[0] = (unsigned long )12;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_baid_txn_code;
 sqlstm.sqhstl[1] = (unsigned long )22;
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
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
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
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[5] = (unsigned long )12;
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
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_bank_acct_type;
 sqlstm.sqhstl[7] = (unsigned long )5;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)0;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_format_id;
 sqlstm.sqhstl[8] = (unsigned long )22;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)0;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto getkeywords_error;
}


	for (;;) {
		/* EXEC SQL FETCH getkeywordscursor
		INTO	:v_txn_code:ind_txn_code,
			:v_amt_type:ind_amt_type,
			:v_full_match:ind_full_match,
			:v_default:ind_default,
			:v_min_amt:ind_min_amt,
			:v_max_amt:ind_max_amt,
			:v_min_dp:ind_min_dp,
			:v_max_dp:ind_max_dp,
			:v_display_order:ind_display_order,
			:v_cont_desc:ind_cont_desc,
			:v_format_template:ind_format_template; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 11;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )376;
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
  sqlstm.sqhstv[1] = (unsigned char  *)&v_amt_type;
  sqlstm.sqhstl[1] = (unsigned long )5;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_amt_type;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_full_match;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_full_match;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_default;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_default;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_min_amt;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_min_amt;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_max_amt;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_max_amt;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_min_dp;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_min_dp;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_max_dp;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_max_dp;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_display_order;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_display_order;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_cont_desc;
  sqlstm.sqhstl[9] = (unsigned long )53;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_cont_desc;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_format_template;
  sqlstm.sqhstl[10] = (unsigned long )503;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_format_template;
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
  if (sqlca.sqlcode < 0) goto getkeywords_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

		hRec = (hash_t*) malloc (sizeof(hash_t));
		hash_init(hRec, 0);

/* txn_code */
		if (ind_txn_code >= 0) {
			v_txn_code.arr[v_txn_code.len] = '\0';
			PutField_CString(hRec, "txn_code", (char*)v_txn_code.arr);
//DEBUGLOG(("txn_code = [%s]\n",v_txn_code.arr));
		} else {
			iRet = INT_FORMAT_KEYWORDS_ERROR;
DEBUGLOG(("txn_code NOT FOUND!!!\n"));
			break;
		}
/* amt_type */
		if (ind_amt_type >= 0) {
			v_amt_type.arr[v_amt_type.len] = '\0';
			PutField_CString(hRec, "amt_type", (char*)v_amt_type.arr);
//DEBUGLOG(("amt_type = [%s]\n",v_amt_type.arr));
		} else {
			iRet = INT_FORMAT_KEYWORDS_ERROR;
DEBUGLOG(("amt_type NOT FOUND!!!\n"));
			break;
		}
/* full_match */
		if (ind_full_match >= 0) {
			PutField_Int(hRec, "full_match", v_full_match);
//DEBUGLOG(("full_match = [%d]\n",v_full_match));
		} else {
			iRet = INT_FORMAT_KEYWORDS_ERROR;
DEBUGLOG(("full_match NOT FOUND!!!\n"));
			break;
		}
/* default */
		if (ind_default >= 0) {
			PutField_Int(hRec, "default", v_default);
//DEBUGLOG(("default = [%d]\n",v_default));

			if (v_default == 0) {
				/* cont_desc*/
				if (ind_cont_desc >= 0) {
					v_cont_desc.arr[v_cont_desc.len] = '\0';
					PutField_CString(hRec, "cont_desc", (char*)v_cont_desc.arr);
//DEBUGLOG(("cont_desc = [%s]\n",v_cont_desc.arr));
				} else {
					iRet = INT_FORMAT_KEYWORDS_ERROR;
DEBUGLOG(("cont_desc NOT FOUND!!!\n"));
					break;
				}
				/* format_template */
				if (ind_format_template >= 0) {
					v_format_template.arr[v_format_template.len] = '\0';
					PutField_CString(hRec, "format_template", (char*)v_format_template.arr);
//DEBUGLOG(("format_template = [%s]\n",v_format_template.arr));
				} else {
					iRet = INT_FORMAT_KEYWORDS_ERROR;
DEBUGLOG(("format_template NOT FOUND!!!\n"));
					break;
				}
DEBUGLOG(("txn_code = [%s], amt_type = [%s], full_match = [%d], cont_desc = [%s], format_template = [%s]\n", v_txn_code.arr, v_amt_type.arr, v_full_match, v_cont_desc.arr, v_format_template.arr));
			} else {
DEBUGLOG(("txn_code = [%s], amt_type = [%s], full_match = [%d]\n", v_txn_code.arr, v_amt_type.arr, v_full_match));
			}
		} else {
			iRet = INT_FORMAT_KEYWORDS_ERROR;
DEBUGLOG(("default NOT FOUND!!!\n"));
			break;
		}
/* min_amt */
		if (ind_min_amt >= 0) {
			PutField_Double(hRec, "min_amt", v_min_amt);
//DEBUGLOG(("min_amt = [%.2lf]\n",v_min_amt));
		} else {
			v_min_amt = -1.0;
			PutField_Double(hRec, "min_amt", -1.0);
		}
/* max_amt */
		if (ind_max_amt >= 0) {
			PutField_Double(hRec, "max_amt", v_max_amt);
//DEBUGLOG(("max_amt = [%.2lf]\n",v_max_amt));
		} else {
			v_max_amt = -1.0;
			PutField_Double(hRec, "max_amt", -1.0);
		}
/* min_dp */
		if (ind_min_dp >= 0) {
			PutField_Int(hRec, "min_dp", v_min_dp);
//DEBUGLOG(("min_dp = [%d]\n",v_min_dp));
		} else {
			v_min_dp = -1;
			PutField_Int(hRec, "min_dp", -1);
		}
/* max_dp */
		if (ind_max_dp >= 0) {
			PutField_Int(hRec, "max_dp", v_max_dp);
//DEBUGLOG(("max_dp = [%d]\n",v_max_dp));
		} else {
			v_max_dp = -1;
			PutField_Int(hRec, "max_dp", -1);
		}

		if ((ind_min_amt >= 0) || (ind_max_amt >= 0) || (ind_min_dp >= 0) || (ind_max_dp >= 0))
DEBUGLOG(("min_amt = [%.2lf], max_amt = [%.2lf], min_dp = [%d], max_dp = [%d]\n", v_min_amt, v_max_amt, v_min_dp, v_max_dp));

/* display_order */
		if (ind_display_order >= 0) {
			PutField_Int(hRec, "display_order", v_display_order);
//DEBUGLOG(("display_order = [%d]\n",v_display_order));
		} else if (ind_default >= 0) {
			if (v_default == 0) {
				iRet = INT_FORMAT_KEYWORDS_ERROR;
DEBUGLOG(("default NOT FOUND!!!\n"));
				break;
			}
		}

		RecordSet_Add(myRec,hRec);
	}
	/* EXEC SQL CLOSE getkeywordscursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )435;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getkeywords_error;
}



	if (iCnt > 0) {
DEBUGLOG(("FOUND\n"));
	} else {
		iRet = PD_NOT_FOUND;
DEBUGLOG(("NOT FOUND!!!\n"));
	}

DEBUGLOG(("GetTxnCodeKeywordsSingle Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getkeywords_error:
DEBUGLOG(("getkeywords_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStmtFormat getkeywords_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL CLOSE getkeywordscursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )450;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getkeywords_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int GetTxnCodeKeywordsAll(const hash_t* hContext, recordset_t* myRec)
{
	int iRet = PD_FOUND;
	int iCnt = 0;
	char *csTmp;

	hash_t *hRec;

DEBUGLOG(("GetTxnCodeKeywordsAll Start\n"));

	/* EXEC SQL WHENEVER SQLERROR GOTO gettxncodeall_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_format_id[PD_FORMAT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_format_id;

		/* varchar	hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar	hv_bank_acct_type[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_bank_acct_type;

		/* varchar	hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

		/* varchar	v_txn_code[PD_TXN_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

		/* varchar	v_amt_type[PD_AMT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_amt_type;

		int	v_full_match;
		int	v_default;
		double	v_min_amt;
		double	v_max_amt;
		int	v_min_dp;
		int	v_max_dp;
		int	v_display_order;
		/* varchar	v_cont_desc[PD_CONT_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_cont_desc;

		/* varchar	v_format_template[PD_FORMAT_TEMPLATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[501]; } v_format_template;


		short	ind_txn_code = -1;
		short	ind_amt_type = -1;
		short	ind_full_match = -1;
		short	ind_default = -1;
		short	ind_min_amt = -1;
		short	ind_max_amt = -1;
		short	ind_min_dp = -1;
		short	ind_max_dp = -1;
		short	ind_display_order = -1;
		short	ind_cont_desc = -1;
		short	ind_format_template = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hContext,"format_id",&csTmp)) {
		hv_format_id.len = strlen(csTmp);
		strncpy((char*)hv_format_id.arr, csTmp, hv_format_id.len);
DEBUGLOG(("format_id = [%.*s]\n", hv_format_id.len, hv_format_id.arr));
	}

	if (GetField_CString(hContext,"int_bank_code",&csTmp)) {
		hv_int_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_int_bank_code.arr, csTmp, hv_int_bank_code.len);
DEBUGLOG(("int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));
	}

	if (GetField_CString(hContext,"bank_acct_type",&csTmp)) {
		hv_bank_acct_type.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_type.arr, csTmp, hv_bank_acct_type.len);
DEBUGLOG(("bank_acct_type = [%.*s]\n", hv_bank_acct_type.len, hv_bank_acct_type.arr));
	}

	if (GetField_CString(hContext,"acct_ccy",&csTmp)) {
		hv_ccy.len = strlen(csTmp);
		strncpy((char*)hv_ccy.arr, csTmp, hv_ccy.len);
DEBUGLOG(("ccy = [%.*s]\n", hv_ccy.len, hv_ccy.arr));
	}

	/* EXEC SQL DECLARE gettxncodeallcursor CURSOR FOR
		SELECT	OBTC_CODE,
			OBTC_AMT_TYPE,
			OBTM_FULL_MATCH,
			OBTM_DEFAULT,
			OLFR_MIN_AMT,
			OLFR_MAX_AMT,
			OLFR_MIN_DP,
			OLFR_MAX_DP,
			OLFK_DISPLAY_ORDER,
			OLFT_CONT_DESC,
			OLFK_FORMAT_TEMPLATE
		FROM	(SELECT OBTC_CODE,
				OBTC_AMT_TYPE,
				OBTM_RANGE,
				NVL(OFKO_IS_DEFAULT, OBTM_DEFAULT) OBTM_DEFAULT,
				OBTM_PRIORITY,
				OBTM_FULL_MATCH,
				OBTM_REAL_TIME_POST, //@@
				OBTM_UPDATE_BAL //@@
			FROM	OL_BAID_TXN_CODE,
				OL_BAID_TXN_CODE_MAPPING
				LEFT JOIN OL_STMT_FORMAT_KEYWORDS_OVER
				ON OFKO_INT_BANK_CODE = :hv_int_bank_code
				AND OBTM_BANK_ACCT_TYPE = OFKO_BANK_ACCT_TYPE
				AND OBTM_CODE = OFKO_BAID_TXN_CODE
			WHERE	OBTM_CODE = OBTC_CODE
			AND	OBTM_BANK_ACCT_TYPE = :hv_bank_acct_type
			AND	OBTM_KEYWORDS = 1)
		LEFT JOIN
			(SELECT	OLFR_INT_BANK_CODE,
				OLFR_CODE,
				OLFR_CCY,
				OLFR_MIN_AMT,
				OLFR_MAX_AMT,
				OLFR_MIN_DP,
				OLFR_MAX_DP
			FROM	OL_STMT_FORMAT_RANGE TR1
			WHERE	TR1.OLFR_CCY = :hv_ccy
			AND	((TR1.OLFR_INT_BANK_CODE = '000' AND NOT EXISTS
					(SELECT * FROM OL_STMT_FORMAT_RANGE TR2
					WHERE	TR2.OLFR_INT_BANK_CODE = :hv_int_bank_code
					AND	TR2.OLFR_CODE = TR1.OLFR_CODE
					AND	TR2.OLFR_CCY = TR1.OLFR_CCY))
				OR	TR1.OLFR_INT_BANK_CODE = :hv_int_bank_code))
		ON	OBTC_CODE = OLFR_CODE
		AND	OBTM_RANGE = 1
		LEFT JOIN 
			(SELECT TK.OLFK_FORMAT_TXN_CODE,
				TK.OLFK_DISPLAY_ORDER,
				TP.OLFT_CONT_DESC,
				TK.OLFK_FORMAT_TEMPLATE
			FROM	OL_STMT_FORMAT_KEYWORDS TK,
				OL_STMT_FORMAT_TEMPLATE TP
			WHERE	TK.OLFK_INT_BANK_CODE = :hv_int_bank_code
			AND	TK.OLFK_FORMAT_TYPE = 'TXN_CODE_'||:hv_bank_acct_type
			AND	TK.OLFK_DISABLED = 0
			AND	TK.OLFK_FORMAT_COL_NAME = TP.OLFT_CONT_COL_NAME
			AND	TP.OLFT_FORMAT_ID LIKE :hv_format_id|| '%'
			AND	TP.OLFT_FORMAT_TYPE = 'CONTENT')
		ON	OBTC_CODE = OLFK_FORMAT_TXN_CODE
		//AND	OBTM_DEFAULT = 0
		//WHERE	(OBTM_DEFAULT = 1 OR OLFK_FORMAT_TEMPLATE IS NOT NULL)
		WHERE	OLFK_FORMAT_TEMPLATE IS NOT NULL
		ORDER BY OBTC_AMT_TYPE ASC, OBTM_DEFAULT ASC, OBTM_PRIORITY DESC, OLFK_DISPLAY_ORDER ASC; */ 


	/* EXEC SQL OPEN gettxncodeallcursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "SELECT OBTC_CODE , OBTC_AMT_TYPE , OBTM_FULL_MATCH , OBTM_DEFAULT , OLFR\
_MIN_AMT , OLFR_MAX_AMT , OLFR_MIN_DP , OLFR_MAX_DP , OLFK_DISPLAY_ORDER , O\
LFT_CONT_DESC , OLFK_FORMAT_TEMPLATE FROM ( SELECT OBTC_CODE , OBTC_AMT_TYPE\
 , OBTM_RANGE , NVL ( OFKO_IS_DEFAULT , OBTM_DEFAULT ) OBTM_DEFAULT , OBTM_P\
RIORITY , OBTM_FULL_MATCH , OBTM_REAL_TIME_POST , OBTM_UPDATE_BAL FROM OL_BA\
ID_TXN_CODE , OL_BAID_TXN_CODE_MAPPING LEFT JOIN OL_STMT_FORMAT_KEYWORDS_OVE\
R ON OFKO_INT_BANK_CODE = :b0 AND OBTM_BANK_ACCT_TYPE = OFKO_BANK_ACCT_TYPE \
AND OBTM_CODE = OFKO_BAID_TXN_CODE WHERE OBTM_CODE = OBTC_CODE AND OBTM_BANK\
_ACCT_TYPE = :b1 AND OBTM_KEYWORDS = 1 ) LEFT JOIN ( SELECT OLFR_INT_BANK_CO\
DE , OLFR_CODE , OLFR_CCY , OLFR_MIN_AMT , OLFR_MAX_AMT , OLFR_MIN_DP , OLFR\
_MAX_DP FROM OL_STMT_FORMAT_RANGE TR1 WHERE TR1 . OLFR_CCY = :b2 AND ( ( TR1\
 . OLFR_INT_BANK_CODE = '000' AND NOT EXISTS ( SELECT * FROM OL_STMT_FORMAT_\
RANGE TR2 WHERE TR2 . OLFR_INT_BANK_CODE = :b0 AND TR2 . OLFR_CODE = TR1 . O\
LFR_CODE AND TR2 . OLFR_CCY = TR1 . OLFR");
 sqlstm.stmt = sq0005;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )465;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[0] = (unsigned long )12;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_acct_type;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_ccy;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[3] = (unsigned long )12;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
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
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[5] = (unsigned long )12;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_bank_acct_type;
 sqlstm.sqhstl[6] = (unsigned long )5;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_format_id;
 sqlstm.sqhstl[7] = (unsigned long )22;
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
 if (sqlca.sqlcode < 0) goto gettxncodeall_error;
}


	for (;;) {
		/* EXEC SQL FETCH gettxncodeallcursor
		INTO	:v_txn_code:ind_txn_code,
			:v_amt_type:ind_amt_type,
			:v_full_match:ind_full_match,
			:v_default:ind_default,
			:v_min_amt:ind_min_amt,
			:v_max_amt:ind_max_amt,
			:v_min_dp:ind_min_dp,
			:v_max_dp:ind_max_dp,
			:v_display_order:ind_display_order,
			:v_cont_desc:ind_cont_desc,
			:v_format_template:ind_format_template; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 11;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )512;
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
  sqlstm.sqhstv[1] = (unsigned char  *)&v_amt_type;
  sqlstm.sqhstl[1] = (unsigned long )5;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_amt_type;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_full_match;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_full_match;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_default;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_default;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_min_amt;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_min_amt;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_max_amt;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_max_amt;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_min_dp;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_min_dp;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_max_dp;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_max_dp;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_display_order;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_display_order;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_cont_desc;
  sqlstm.sqhstl[9] = (unsigned long )53;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_cont_desc;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_format_template;
  sqlstm.sqhstl[10] = (unsigned long )503;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_format_template;
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
  if (sqlca.sqlcode < 0) goto gettxncodeall_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

		hRec = (hash_t*) malloc (sizeof(hash_t));
		hash_init(hRec, 0);

/* txn_code */
		if (ind_txn_code >= 0) {
			v_txn_code.arr[v_txn_code.len] = '\0';
			PutField_CString(hRec, "txn_code", (char*)v_txn_code.arr);
//DEBUGLOG(("txn_code = [%s]\n",v_txn_code.arr));
		} else {
			iRet = INT_FORMAT_KEYWORDS_ERROR;
DEBUGLOG(("txn_code NOT FOUND!!!\n"));
			break;
		}
/* amt_type */
		if (ind_amt_type >= 0) {
			v_amt_type.arr[v_amt_type.len] = '\0';
			PutField_CString(hRec, "amt_type", (char*)v_amt_type.arr);
// DEBUGLOG(("amt_type = [%s]\n",v_amt_type.arr));
		} else {
			iRet = INT_FORMAT_KEYWORDS_ERROR;
DEBUGLOG(("amt_type NOT FOUND!!!\n"));
			break;
		}
/* full_match */
		if (ind_full_match >= 0) {
			PutField_Int(hRec, "full_match", v_full_match);
// DEBUGLOG(("full_match = [%d]\n",v_full_match));
		} else {
			iRet = INT_FORMAT_KEYWORDS_ERROR;
DEBUGLOG(("full_match NOT FOUND!!!\n"));
			break;
		}
/* default */
		if (ind_default >= 0) {
			PutField_Int(hRec, "default", v_default);
//DEBUGLOG(("default = [%d]\n",v_default));
		} else {
			iRet = INT_FORMAT_KEYWORDS_ERROR;
DEBUGLOG(("default NOT FOUND!!!\n"));
			break;
		}

/* cont_desc */
		if (ind_cont_desc >= 0) {
			v_cont_desc.arr[v_cont_desc.len] = '\0';
			PutField_CString(hRec, "cont_desc", (char*)v_cont_desc.arr);
//DEBUGLOG(("cont_desc = [%s]\n",v_cont_desc.arr));
		} else {
			iRet = INT_FORMAT_KEYWORDS_ERROR;
DEBUGLOG(("cont_desc NOT FOUND!!!\n"));
			break;
		}

/* format_template */
		if (ind_format_template >= 0) {
			v_format_template.arr[v_format_template.len] = '\0';
			PutField_CString(hRec, "format_template", (char*)v_format_template.arr);
//DEBUGLOG(("format_template = [%s]\n",v_format_template.arr));
		} else {
			iRet = INT_FORMAT_KEYWORDS_ERROR;
DEBUGLOG(("format_template NOT FOUND!!!\n"));
			break;
		}

DEBUGLOG(("txn_code = [%s], amt_type = [%s], full_match = [%d], cont_desc = [%s], format_template = [%s]\n", v_txn_code.arr, v_amt_type.arr, v_full_match, v_cont_desc.arr, v_format_template.arr));

/* min_amt */
		if (ind_min_amt >= 0) {
			PutField_Double(hRec, "min_amt", v_min_amt);
//DEBUGLOG(("min_amt = [%.2lf]\n",v_min_amt));
		} else {
			v_min_amt = -1.0;
			PutField_Double(hRec, "min_amt", -1.0);
		}
/* max_amt */
		if (ind_max_amt >= 0) {
			PutField_Double(hRec, "max_amt", v_max_amt);
//DEBUGLOG(("max_amt = [%.2lf]\n",v_max_amt));
		} else {
			v_max_amt = -1.0;
			PutField_Double(hRec, "max_amt", -1.0);
		}
/* min_dp */
		if (ind_min_dp >= 0) {
			PutField_Int(hRec, "min_dp", v_min_dp);
//DEBUGLOG(("min_dp = [%d]\n",v_min_dp));
		} else {
			v_min_dp = -1;
			PutField_Int(hRec, "min_dp", -1);
		}
/* max_dp */
		if (ind_max_dp >= 0) {
			PutField_Int(hRec, "max_dp", v_max_dp);
//DEBUGLOG(("max_dp = [%d]\n",v_max_dp));
		} else {
			v_max_dp = -1;
			PutField_Int(hRec, "max_dp", -1);
		}

		if ((ind_min_amt >= 0) || (ind_max_amt >= 0) || (ind_min_dp >= 0) || (ind_max_dp >= 0))
DEBUGLOG(("min_amt = [%.2lf], max_amt = [%.2lf], min_dp = [%d], max_dp = [%d]\n", v_min_amt, v_max_amt, v_min_dp, v_max_dp));

/* display_order */
		if (ind_display_order >= 0) {
			PutField_Int(hRec, "display_order", v_display_order);
// DEBUGLOG(("display_order = [%d]\n",v_display_order));
		} else if (ind_default >= 0) {
			if (v_default == 0) {
				iRet = INT_FORMAT_KEYWORDS_ERROR;
DEBUGLOG(("default NOT FOUND!!!\n"));
				break;
			}
		}

		RecordSet_Add(myRec,hRec);
	}
	/* EXEC SQL CLOSE gettxncodeallcursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )571;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto gettxncodeall_error;
}



	if (iCnt > 0) {
DEBUGLOG(("FOUND\n"));
	} else {
		iRet = PD_NOT_FOUND;
DEBUGLOG(("NOT FOUND!!!\n"));
	}

DEBUGLOG(("GetTxnCodeKeywordsAll Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

gettxncodeall_error:
DEBUGLOG(("gettxncodeall_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStmtFormat gettxncodeall_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL CLOSE gettxncodeallcursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )586;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto gettxncodeall_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int AddKeywords(hash_t *hRls)
{
	char	*csTmp;
	int	iTmp;

DEBUGLOG(("AddKeywords Start\n"));

	/* EXEC SQL WHENEVER SQLERROR GOTO addkeywords_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_int_bank_code[PD_FORMAT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_int_bank_code;

		/* varchar		hv_format_type[PD_FORMAT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_format_type;

		int		hv_format_value;
		/* varchar		hv_format_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_format_txn_code;

		/* varchar		hv_format_template[PD_FORMAT_TEMPLATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[500]; } hv_format_template;

		/* varchar		hv_format_col_name[PD_COL_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_format_col_name;

		int		hv_display_order;
		int		hv_disabled;
		/* varchar		hv_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_user;


		short		ind_int_bank_code = -1;
		short		ind_format_type = -1;
		short		ind_format_value = -1;
		short		ind_format_txn_code = -1;
		short		ind_format_template = -1;
		short		ind_format_col_name = -1;
		short		ind_display_order = -1;
		short		ind_disabled = -1;
		short		ind_user = -1;

		short		hv_return_value;

	/* EXEC SQL END DECLARE SECTION; */ 


// int_bank_code
	if (GetField_CString(hRls,"int_bank_code",&csTmp)) {
		hv_int_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_int_bank_code.arr, csTmp, hv_int_bank_code.len);
		ind_int_bank_code = 0;
DEBUGLOG(("int_bank_code = [%.*s]\n",hv_int_bank_code.len,hv_int_bank_code.arr));
	} else {
DEBUGLOG(("int_bank_code NOT FOUND!!!\n"));
	}

// format_type
	if (GetField_CString(hRls,"format_type",&csTmp)) {
		hv_format_type.len = strlen(csTmp);
		strncpy((char*)hv_format_type.arr, csTmp, hv_format_type.len);
		ind_format_type = 0;
DEBUGLOG(("format_type = [%.*s]\n",hv_format_type.len,hv_format_type.arr));
	} else {
DEBUGLOG(("format_type NOT FOUND!!!\n"));
	}

// format_value
	if (GetField_Int(hRls,"format_value",&iTmp)) {
		hv_format_value = iTmp;
		ind_format_value = 0;
DEBUGLOG(("format_value = [%d]\n",hv_format_value));
	}

// format_txn_code
	if (GetField_CString(hRls,"format_txn_code",&csTmp)) {
		hv_format_txn_code.len = strlen(csTmp);
		strncpy((char*)hv_format_txn_code.arr, csTmp, hv_format_txn_code.len);
		ind_format_txn_code = 0;
DEBUGLOG(("format_txn_code = [%.*s]\n",hv_format_txn_code.len,hv_format_txn_code.arr));
	} else {
DEBUGLOG(("format_txn_code NOT FOUND!!!\n"));
	}

// format_template
	if (GetField_CString(hRls,"format_template",&csTmp)) {
		hv_format_template.len = strlen(csTmp);
		strncpy((char*)hv_format_template.arr, csTmp, hv_format_template.len);
		ind_format_template = 0;
DEBUGLOG(("format_template = [%.*s]\n",hv_format_template.len,hv_format_template.arr));
	} else {
DEBUGLOG(("format_template NOT FOUND!!!\n"));
	}

// format_col_name
	if (GetField_CString(hRls,"format_col_name",&csTmp)) {
		hv_format_col_name.len = strlen(csTmp);
		strncpy((char*)hv_format_col_name.arr, csTmp, hv_format_col_name.len);
		ind_format_col_name = 0;
DEBUGLOG(("format_col_name = [%.*s]\n",hv_format_col_name.len,hv_format_col_name.arr));
	} else {
DEBUGLOG(("format_col_name NOT FOUND!!!\n"));
	}

// display_order
	if (GetField_Int(hRls,"display_order",&iTmp)) {
		hv_display_order = iTmp;
		ind_display_order = 0;
DEBUGLOG(("display_order = [%d]\n",hv_display_order));
	}

// disabled
	hv_disabled = 0;
	if (GetField_Int(hRls,"disabled",&iTmp)) {
		hv_disabled = iTmp;
DEBUGLOG(("disabled = [%d]\n",hv_disabled));
	}
	ind_disabled = 0;

// user
	if (GetField_CString(hRls,"create_user",&csTmp)) {
		hv_user.len = strlen(csTmp);
		strncpy((char*)hv_user.arr, csTmp, hv_user.len);
		ind_user = 0;
DEBUGLOG(("user = [%.*s]\n",hv_user.len,hv_user.arr));
	} else if (GetField_CString(hRls,"update_user",&csTmp)) {
		hv_user.len = strlen(csTmp);
		strncpy((char*)hv_user.arr, csTmp, hv_user.len);
		ind_user = 0;
DEBUGLOG(("user = [%.*s]\n",hv_user.len,hv_user.arr));
	} else {
DEBUGLOG(("user NOT FOUND!!!\n"));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_stmt_keywords_insert(
						:hv_int_bank_code:ind_int_bank_code,
						:hv_format_type:ind_format_type,
						:hv_format_value:ind_format_value,
						:hv_format_txn_code:ind_format_txn_code,
						:hv_format_template:ind_format_template,
						:hv_format_col_name:ind_format_col_name,
						:hv_display_order:ind_display_order,
						:hv_disabled:ind_disabled,
						:hv_user:ind_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_stmt_keywords_insert ( :hv_\
int_bank_code:ind_int_bank_code , :hv_format_type:ind_format_type , :hv_forma\
t_value:ind_format_value , :hv_format_txn_code:ind_format_txn_code , :hv_form\
at_template:ind_format_template , :hv_format_col_name:ind_format_col_name , :\
hv_display_order:ind_display_order , :hv_disabled:ind_disabled , :hv_user:ind\
_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )601;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[1] = (unsigned long )22;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_format_type;
 sqlstm.sqhstl[2] = (unsigned long )22;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_format_type;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_format_value;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_format_value;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_format_txn_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_format_txn_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_format_template;
 sqlstm.sqhstl[5] = (unsigned long )502;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_format_template;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_format_col_name;
 sqlstm.sqhstl[6] = (unsigned long )52;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_format_col_name;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_display_order;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_display_order;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_disabled;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_user;
 sqlstm.sqhstl[9] = (unsigned long )22;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_user;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto addkeywords_error;
}



DEBUGLOG(("Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
		if (ind_display_order >= 0) {
			PutField_Int(hRls,"display_order",hv_display_order);
DEBUGLOG(("display_order = [%d]\n",hv_display_order));
		}
DEBUGLOG(("AddKeywords: Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLStatement_AddKeywords: SP_OTHER_ERR\n");
DEBUGLOG(("AddKeywords: SP_OTHER_ERR\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLStatement_AddKeywords: SP_ERR\n");
DEBUGLOG(("AddKeywords: SP_ERR\n"));
		return PD_ERR;
	}

addkeywords_error:
DEBUGLOG(("update_Header_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLStatement_AddKeywords: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("AddKeywords: SP_INTERNAL_ERR TxnAbort\n"));
	TxnAbort();
	return PD_INTERNAL_ERR;
}


int UpdateKeywords(hash_t *hRls)
{
	char	*csTmp;
	int	iTmp;

DEBUGLOG(("UpdateKeywords Start\n"));

	/* EXEC SQL WHENEVER SQLERROR GOTO updatekeywords_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_int_bank_code[PD_FORMAT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_int_bank_code;

		/* varchar		hv_format_type[PD_FORMAT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_format_type;

		int		hv_format_value;
		/* varchar		hv_format_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_format_txn_code;

		/* varchar		hv_format_template[PD_FORMAT_TEMPLATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[500]; } hv_format_template;

		/* varchar		hv_format_col_name[PD_COL_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_format_col_name;

		int		hv_display_order;
		int		hv_disabled;
		/* varchar		hv_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_user;


		short		ind_int_bank_code = -1;
		short		ind_format_type = -1;
		short		ind_format_value = -1;
		short		ind_format_txn_code = -1;
		short		ind_format_template = -1;
		short		ind_format_col_name = -1;
		short		ind_display_order = -1;
		short		ind_disabled = -1;
		short		ind_user = -1;

		short		hv_return_value;

	/* EXEC SQL END DECLARE SECTION; */ 


// int_bank_code
	if (GetField_CString(hRls,"int_bank_code",&csTmp)) {
		hv_int_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_int_bank_code.arr, csTmp, hv_int_bank_code.len);
		ind_int_bank_code = 0;
DEBUGLOG(("int_bank_code = [%.*s]\n",hv_int_bank_code.len,hv_int_bank_code.arr));
	} else {
DEBUGLOG(("int_bank_code NOT FOUND!!!\n"));
	}

// format_type
	if (GetField_CString(hRls,"format_type",&csTmp)) {
		hv_format_type.len = strlen(csTmp);
		strncpy((char*)hv_format_type.arr, csTmp, hv_format_type.len);
		ind_format_type = 0;
DEBUGLOG(("format_type = [%.*s]\n",hv_format_type.len,hv_format_type.arr));
	} else {
DEBUGLOG(("format_type NOT FOUND!!!\n"));
	}

// format_value
	if (GetField_Int(hRls,"format_value",&iTmp)) {
		hv_format_value = iTmp;
		ind_format_value = 0;
DEBUGLOG(("format_value = [%d]\n",hv_format_value));
	} else {
DEBUGLOG(("format_value NOT FOUND!!!\n"));
	}

// format_txn_code
	if (GetField_CString(hRls,"format_txn_code",&csTmp)) {
		hv_format_txn_code.len = strlen(csTmp);
		strncpy((char*)hv_format_txn_code.arr, csTmp, hv_format_txn_code.len);
		ind_format_txn_code = 0;
DEBUGLOG(("format_txn_code = [%.*s]\n",hv_format_txn_code.len,hv_format_txn_code.arr));
	} else {
DEBUGLOG(("format_txn_code NOT FOUND!!!\n"));
	}

// format_template
	if (GetField_CString(hRls,"format_template",&csTmp)) {
		hv_format_template.len = strlen(csTmp);
		strncpy((char*)hv_format_template.arr, csTmp, hv_format_template.len);
		ind_format_template = 0;
DEBUGLOG(("format_template = [%.*s]\n",hv_format_template.len,hv_format_template.arr));
	} else {
DEBUGLOG(("format_template NOT FOUND!!!\n"));
	}

// format_col_name
	if (GetField_CString(hRls,"format_col_name",&csTmp)) {
		hv_format_col_name.len = strlen(csTmp);
		strncpy((char*)hv_format_col_name.arr, csTmp, hv_format_col_name.len);
		ind_format_col_name = 0;
DEBUGLOG(("format_col_name = [%.*s]\n",hv_format_col_name.len,hv_format_col_name.arr));
	} else {
DEBUGLOG(("format_col_name NOT FOUND!!!\n"));
	}

// display_order
	if (GetField_Int(hRls,"display_order",&iTmp)) {
		hv_display_order = iTmp;
		ind_display_order = 0;
DEBUGLOG(("display_order = [%d]\n",hv_display_order));
	} else {
DEBUGLOG(("display_order NOT FOUND!!!\n"));
	}

// disabled
	hv_disabled = 0;
	if (GetField_Int(hRls,"disabled",&iTmp)) {
		hv_disabled = iTmp;
DEBUGLOG(("disabled = [%d]\n",hv_disabled));
	}
	ind_disabled = 0;

// user
	if (GetField_CString(hRls,"create_user",&csTmp)) {
		hv_user.len = strlen(csTmp);
		strncpy((char*)hv_user.arr, csTmp, hv_user.len);
		ind_user = 0;
DEBUGLOG(("user = [%.*s]\n",hv_user.len,hv_user.arr));
	} else if (GetField_CString(hRls,"update_user",&csTmp)) {
		hv_user.len = strlen(csTmp);
		strncpy((char*)hv_user.arr, csTmp, hv_user.len);
		ind_user = 0;
DEBUGLOG(("user = [%.*s]\n",hv_user.len,hv_user.arr));
	} else {
DEBUGLOG(("user NOT FOUND!!!\n"));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_stmt_keywords_update(
						:hv_int_bank_code:ind_int_bank_code,
						:hv_format_type:ind_format_type,
						:hv_format_value:ind_format_value,
						:hv_format_txn_code:ind_format_txn_code,
						:hv_format_template:ind_format_template,
						:hv_format_col_name:ind_format_col_name,
						:hv_display_order:ind_display_order,
						:hv_disabled:ind_disabled,
						:hv_user:ind_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_stmt_keywords_update ( :hv_\
int_bank_code:ind_int_bank_code , :hv_format_type:ind_format_type , :hv_forma\
t_value:ind_format_value , :hv_format_txn_code:ind_format_txn_code , :hv_form\
at_template:ind_format_template , :hv_format_col_name:ind_format_col_name , :\
hv_display_order:ind_display_order , :hv_disabled:ind_disabled , :hv_user:ind\
_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )656;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[1] = (unsigned long )22;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_format_type;
 sqlstm.sqhstl[2] = (unsigned long )22;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_format_type;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_format_value;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_format_value;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_format_txn_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_format_txn_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_format_template;
 sqlstm.sqhstl[5] = (unsigned long )502;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_format_template;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_format_col_name;
 sqlstm.sqhstl[6] = (unsigned long )52;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_format_col_name;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_display_order;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_display_order;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_disabled;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_user;
 sqlstm.sqhstl[9] = (unsigned long )22;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_user;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto updatekeywords_error;
}



DEBUGLOG(("Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("UpdateKeywords: Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLStatement_UpdateKeywords: SP_OTHER_ERR\n");
DEBUGLOG(("UpdateKeywords: SP_OTHER_ERR\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLStatement_UpdateKeywords: SP_ERR\n");
DEBUGLOG(("UpdateKeywords: SP_ERR\n"));
		return PD_ERR;
	}

updatekeywords_error:
DEBUGLOG(("update_Header_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLStatement_UpdateKeywords: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("UpdateKeywords: SP_INTERNAL_ERR TxnAbort\n"));
	TxnAbort();
	return PD_INTERNAL_ERR;
}


