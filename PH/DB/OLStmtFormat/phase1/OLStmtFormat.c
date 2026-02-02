
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
"SELECT OLFT_FORMAT_ID , lower ( OLFT_FORMAT_TYPE ) OLFT_FORMAT_TYPE , OLFT_\
FORMAT_VALUE , OLFT_CONT_DESC , OLFT_CONT_DESC_2 , OLFT_CONT_TEMPLATE , OLFT_\
CONT_NEXT_LVL FROM OL_STMT_FORMAT_TEMPLATE , OL_STMT_FORMAT WHERE OLSF_INT_BA\
NK_CODE = :b0:b1 AND ( OLFT_FORMAT_ID = OLSF_FORMAT_ID or OLFT_FORMAT_ID like\
 OLSF_FORMAT_ID || '.%' ) AND OLSF_DISABLED = 0 AND OLSF_EFFECT_TIMESTAMP <= \
sysdate ORDER BY OLFT_FORMAT_ID ASC , OLFT_FORMAT_TYPE ASC , OLFT_FORMAT_VALU\
E ASC            ";

 static char *sq0002 = 
"SELECT OBTC_CODE , OBTC_AMT_TYPE , OBTM_FULL_MATCH , OBTM_HOLD_CREDIT_SIDE \
, OBTM_REAL_TIME_POST , OBTM_DEFAULT , OBTM_MIN_AMT , OBTM_MAX_AMT , OBTM_UNI\
QUE_AMT , TK . OLFK_DISPLAY_ORDER , TP . OLFT_CONT_DESC , TK . OLFK_FORMAT_TE\
MPLATE FROM OL_BAID_TXN_CODE , OL_BAID_TXN_CODE_MAPPING LEFT JOIN OL_STMT_FOR\
MAT_KEYWORDS TK ON OBTM_CODE = TK . OLFK_FORMAT_TXN_CODE AND TK . OLFK_INT_BA\
NK_CODE = :b0:b1 AND TK . OLFK_FORMAT_TYPE = 'TXN_CODE' AND TK . OLFK_DISABLE\
D = 0 LEFT JOIN OL_STMT_FORMAT_TEMPLATE TP ON TK . OLFK_FORMAT_COL_NAME = TP \
. OLFT_CONT_COL_NAME AND TP . OLFT_FORMAT_ID LIKE :b2:b3 || '%' AND TP . OLFT\
_FORMAT_TYPE = 'CONTENT' WHERE OBTM_CODE = OBTC_CODE AND OBTM_BANK_ACCT_TYPE \
= :b4:b5 AND ( OBTM_DEFAULT = 1 OR TK . OLFK_FORMAT_TEMPLATE IS NOT NULL ) OR\
DER BY OBTC_AMT_TYPE ASC , OBTM_DEFAULT ASC , OBTM_PRIORITY DESC , TK . OLFK_\
DISPLAY_ORDER ASC            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,477,0,9,95,0,2049,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,13,97,0,0,7,0,0,1,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,2,3,0,0,
67,0,0,1,0,0,15,214,0,0,0,0,0,1,0,
82,0,0,1,0,0,15,236,0,0,0,0,0,1,0,
97,0,0,2,874,0,9,331,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
124,0,0,2,0,0,13,333,0,0,12,0,0,1,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,
3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,9,0,0,2,9,0,0,
187,0,0,2,0,0,15,451,0,0,0,0,0,1,0,
202,0,0,2,0,0,15,469,0,0,0,0,0,1,0,
217,0,0,3,380,0,6,701,0,0,10,10,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,9,0,0,
1,9,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/07/17              Stan Poon
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

char cDebug;

void OLStmtFormat(char cdebug)
{
	cDebug = cdebug;
}


int GetFormat(const char* csIntBankCode, recordset_t* myRec)
{
	int iRet = PD_OK;
	int iCnt = 0, iValue = 0;

	char csFormatId[PD_FORMAT_ID_LEN + 1];
	char csCurrFormatId[PD_FORMAT_ID_LEN + 1];

	char csFormatType[PD_FORMAT_TYPE_LEN + 1];
	char csFormatValue[PD_FORMAT_VALUE_LEN + 1];

	char *csTmp;
	char *csTag = (char*) malloc (64);

	hash_t *myHash;
	myHash = (hash_t*) malloc (sizeof(hash_t));
	hash_init(myHash, 0);

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

		short ind_int_bank_code = -1;
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
	ind_int_bank_code = 0;
DEBUGLOG(("GetFormat int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));

	/* EXEC SQL DECLARE getformatcursor CURSOR FOR
		SELECT	OLFT_FORMAT_ID,
			lower(OLFT_FORMAT_TYPE) OLFT_FORMAT_TYPE,
			OLFT_FORMAT_VALUE,
			OLFT_CONT_DESC,
			OLFT_CONT_DESC_2,
			OLFT_CONT_TEMPLATE,
			OLFT_CONT_NEXT_LVL
		FROM	OL_STMT_FORMAT_TEMPLATE, OL_STMT_FORMAT
		WHERE	OLSF_INT_BANK_CODE = :hv_int_bank_code:ind_int_bank_code
		AND	(OLFT_FORMAT_ID = OLSF_FORMAT_ID or OLFT_FORMAT_ID like OLSF_FORMAT_ID||'.%')
		AND	OLSF_DISABLED = 0
		AND	OLSF_EFFECT_TIMESTAMP <= sysdate
		ORDER BY OLFT_FORMAT_ID ASC, OLFT_FORMAT_TYPE ASC, OLFT_FORMAT_VALUE ASC; */ 


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
 sqlstm.sqindv[0] = (         short *)&ind_int_bank_code;
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
DEBUGLOG(("GetFormat read (%s) = [%s]\n", "format_id", csFormatId));
			} else {
				csTmp = mystrtok(csCurrFormatId, ".");
				if (csTmp != NULL && strcmp(csTmp, csFormatId)) {
					RecordSet_Add(myRec, myHash);
DEBUGLOG(("GetFormat hash added - (%s) = [%s]\n", "format_id", csFormatId));
					myHash = (hash_t*) malloc (sizeof(hash_t));
					hash_init(myHash, 0);
					strcpy(csFormatId, (const char*)v_format_id.arr);
					PutField_CString(myHash, "format_id", csFormatId); //
DEBUGLOG(("GetFormat read (%s) = [%s]\n", "format_id", csFormatId));
				}
				strcpy(csCurrFormatId, (const char*)v_format_id.arr);
			}
		}

		iValue = 0;
		strcpy(csFormatValue,"");

/* format_type */
		if (ind_format_type >= 0) {
			v_format_type.arr[v_format_type.len] = '\0';
			sprintf(csFormatType, "%s", (char*)v_format_type.arr);
		}

/* format_value - DELIMITER */
		if (ind_format_value >= 0) {
			sprintf(csFormatValue,"%d",v_format_value);

			if (!strcmp(csFormatType,"delimiter")) {
				sprintf(csTag, "%s_%s", csFormatType, csCurrFormatId);
				PutField_CString(myHash, csTag, csFormatValue); //
DEBUGLOG(("GetFormat (%s) = [%s]\n", csTag, csFormatValue));
				iValue = 1;
			}
		}

/* cont_desc - CONTENT */
		if (ind_cont_desc >= 0) { 
			v_cont_desc.arr[v_cont_desc.len] = '\0';
			sprintf(csTag, "%s_desc_%s_%s", csFormatType, csCurrFormatId, csFormatValue);
			PutField_CString(myHash, csTag, (const char *)v_cont_desc.arr); //
DEBUGLOG(("GetFormat (%s) = [%s]\n", csTag, v_cont_desc.arr));
			iValue = 1;
		}

/* cont_desc_2 - CONTENT */
		if (ind_cont_desc_2 >= 0) { 
			v_cont_desc_2.arr[v_cont_desc_2.len] = '\0';
			sprintf(csTag, "%s_desc_2_%s_%s", csFormatType, csCurrFormatId, csFormatValue);
			PutField_CString(myHash, csTag, (const char *)v_cont_desc_2.arr); //
DEBUGLOG(("GetFormat (%s) = [%s]\n", csTag, v_cont_desc_2.arr));
			iValue = 1;
		}

/* cont_template - CONTENT */
		if (ind_cont_template >= 0) {
			v_cont_template.arr[v_cont_template.len] = '\0';
			sprintf(csTag, "%s_temp_%s_%s", csFormatType, csCurrFormatId, csFormatValue);
			PutField_CString(myHash, csTag, (const char *)v_cont_template.arr); //
DEBUGLOG(("GetFormat (%s) = [%s]\n", csTag, v_cont_template.arr));
			iValue = 1;
		} else {
			if (ind_cont_desc >= 0) {
				sprintf(csTag, "%s_temp_%s_%s", csFormatType, csCurrFormatId, csFormatValue);
				if (!strcmp((char*)v_cont_desc.arr,"statement_date")) {
					PutField_CString(myHash, csTag, PD_DEFAULT_DATE_FORMAT); //
DEBUGLOG(("GetFormat (%s) default = [%s]\n", csTag, PD_DEFAULT_DATE_FORMAT));
					iValue = 1;
				} else if (!strcmp((char*)v_cont_desc.arr,"statement_time")) {
					PutField_CString(myHash, csTag, PD_DEFAULT_TIME_FORMAT); //
DEBUGLOG(("GetFormat (%s) default = [%s]\n", csTag, PD_DEFAULT_TIME_FORMAT));
					iValue = 1;
				}
			}
		}

/* cont_next_lvl - CONTENT */
		if (ind_cont_next_lvl >= 0) {
			if (v_cont_next_lvl == 1) {
				sprintf(csTag, "%s_nxlv_%s_%s", csFormatType, csCurrFormatId, csFormatValue);
				PutField_Int(myHash, csTag, v_cont_next_lvl); //
DEBUGLOG(("GetFormat (%s) = [%d]\n", csTag, v_cont_next_lvl));
			}
		}

/* format_value - ELSE */
		if (ind_format_value >= 0) {
			if (iValue == 0) {
				PutField_CString(myHash, csFormatType, csFormatValue); //
DEBUGLOG(("GetFormat (%s) = [%s]\n", csFormatType, csFormatValue));
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
DEBUGLOG(("GetFormat hash added - (format_id) = [%s]\n", csFormatId));
		iRet = PD_OK;
	} else {
DEBUGLOG(("GetFormat NOT FOUND!!!\n"));
ERRLOG("OLStmtFormat::GetFormat NOT FOUND!!!\n");
		iRet = PD_ERR;
	}

	free(csTag);

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


int GetTxnCodeKeywords(const char* csIntBankCode, const char* csFormatID, const char* csBankAcctType,
		recordset_t* myRec)
{
	int iRet = PD_FOUND;
	int iCnt = 0;

	hash_t *myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO gettxncode_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_format_id[PD_FORMAT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_format_id;

		/* varchar	hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar	hv_bank_acct_type[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_bank_acct_type;

		/* varchar	v_txn_code[PD_TXN_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

		/* varchar	v_amt_type[PD_AMT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_amt_type;

		int	v_full_match;
		int	v_hold_credit_side;
		int	v_real_time_post;
		int	v_default;
		int	v_min_amt;
		int	v_max_amt;
		int	v_unique_amt;
		int	v_display_order;
		/* varchar	v_cont_desc[PD_CONT_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_cont_desc;

		/* varchar	v_format_template[PD_FORMAT_TEMPLATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[501]; } v_format_template;


		short	ind_format_id = -1;
		short	ind_int_bank_code = -1;
		short	ind_bank_acct_type = -1;
		short	ind_txn_code = -1;
		short	ind_amt_type = -1;
		short	ind_full_match = -1;
		short	ind_hold_credit_side = -1;
		short	ind_real_time_post = -1;
		short	ind_default = -1;
		short	ind_min_amt = -1;
		short	ind_max_amt = -1;
		short	ind_unique_amt = -1;
		short	ind_display_order = -1;
		short	ind_cont_desc = -1;
		short	ind_format_template = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_format_id.len = strlen(csFormatID);
	strncpy((char*)hv_format_id.arr, csFormatID, hv_format_id.len);
	ind_format_id = 0;
DEBUGLOG(("GetTxnCodeKeywords format_format_id = [%.*s]\n", hv_format_id.len, hv_format_id.arr));

	hv_int_bank_code.len = strlen(csIntBankCode);
	strncpy((char*)hv_int_bank_code.arr, csIntBankCode, hv_int_bank_code.len);
	ind_int_bank_code = 0;
DEBUGLOG(("GetTxnCodeKeywords int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));

	hv_bank_acct_type.len = strlen(csBankAcctType);
	strncpy((char*)hv_bank_acct_type.arr, csBankAcctType, hv_bank_acct_type.len);
	ind_bank_acct_type = 0;
DEBUGLOG(("GetTxnCodeKeywords bank_acct_type = [%.*s]\n", hv_bank_acct_type.len, hv_bank_acct_type.arr));

	/* EXEC SQL DECLARE gettxncodecursor CURSOR FOR
		SELECT	OBTC_CODE,
			OBTC_AMT_TYPE,
			OBTM_FULL_MATCH,
			OBTM_HOLD_CREDIT_SIDE,
			OBTM_REAL_TIME_POST,
			OBTM_DEFAULT,
			OBTM_MIN_AMT,
			OBTM_MAX_AMT,
			OBTM_UNIQUE_AMT,
			TK.OLFK_DISPLAY_ORDER,
			TP.OLFT_CONT_DESC,
			TK.OLFK_FORMAT_TEMPLATE
		FROM	OL_BAID_TXN_CODE,
			OL_BAID_TXN_CODE_MAPPING
			LEFT JOIN OL_STMT_FORMAT_KEYWORDS TK
			ON	OBTM_CODE = TK.OLFK_FORMAT_TXN_CODE
			AND	TK.OLFK_INT_BANK_CODE = :hv_int_bank_code:ind_int_bank_code
			AND	TK.OLFK_FORMAT_TYPE = 'TXN_CODE'
			AND	TK.OLFK_DISABLED = 0
			LEFT JOIN OL_STMT_FORMAT_TEMPLATE TP
			ON	TK.OLFK_FORMAT_COL_NAME = TP.OLFT_CONT_COL_NAME
			AND	TP.OLFT_FORMAT_ID LIKE :hv_format_id:ind_format_id || '%'
			AND	TP.OLFT_FORMAT_TYPE = 'CONTENT'
		WHERE	OBTM_CODE = OBTC_CODE
		AND	OBTM_BANK_ACCT_TYPE = :hv_bank_acct_type:ind_bank_acct_type
		AND	(OBTM_DEFAULT = 1 OR TK.OLFK_FORMAT_TEMPLATE IS NOT NULL)
		ORDER BY OBTC_AMT_TYPE ASC, OBTM_DEFAULT ASC, OBTM_PRIORITY DESC, TK.OLFK_DISPLAY_ORDER ASC; */ 


	/* EXEC SQL OPEN gettxncodecursor; */ 

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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[0] = (unsigned long )12;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_format_id;
 sqlstm.sqhstl[1] = (unsigned long )22;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_format_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_type;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_bank_acct_type;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
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
			:v_hold_credit_side:ind_hold_credit_side,
			:v_real_time_post:ind_real_time_post,
			:v_default:ind_default,
			:v_min_amt:ind_min_amt,
			:v_max_amt:ind_max_amt,
			:v_unique_amt:ind_unique_amt,
			:v_display_order:ind_display_order,
			:v_cont_desc:ind_cont_desc,
			:v_format_template:ind_format_template; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )124;
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
  sqlstm.sqhstv[3] = (unsigned char  *)&v_hold_credit_side;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_hold_credit_side;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_real_time_post;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_real_time_post;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_default;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_default;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_min_amt;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_min_amt;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_max_amt;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_max_amt;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_unique_amt;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_unique_amt;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_display_order;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_display_order;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_cont_desc;
  sqlstm.sqhstl[10] = (unsigned long )53;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_cont_desc;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_format_template;
  sqlstm.sqhstl[11] = (unsigned long )503;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_format_template;
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
  if (sqlca.sqlcode < 0) goto gettxncode_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash, 0);

/* txn_code */
		if (ind_txn_code >= 0) {
			v_txn_code.arr[v_txn_code.len] = '\0';
			PutField_CString(myHash, "txn_code", (char*)v_txn_code.arr);
DEBUGLOG(("GetTxnCodeKeywords txn_code = [%s]\n",v_txn_code.arr));
		} else {
			iRet = INT_FORMAT_KEYWORDS_ERROR;
		}
/* amt_type */
		if (ind_amt_type >= 0) {
			v_amt_type.arr[v_amt_type.len] = '\0';
			PutField_CString(myHash, "amt_type", (char*)v_amt_type.arr);
DEBUGLOG(("GetTxnCodeKeywords amt_type = [%s]\n",v_amt_type.arr));
		} else {
			iRet = INT_FORMAT_KEYWORDS_ERROR;
		}
/* full_match */
		if (ind_full_match >= 0) {
			PutField_Int(myHash, "full_match", v_full_match);
DEBUGLOG(("GetTxnCodeKeywords full_match = [%d]\n",v_full_match));
		} else {
			iRet = INT_FORMAT_KEYWORDS_ERROR;
		}
/* hold_credit_side */
		if (ind_hold_credit_side >= 0) {
			PutField_Int(myHash, "hold_credit_side", v_hold_credit_side);
DEBUGLOG(("GetTxnCodeKeywords hold_credit_side = [%d]\n",v_hold_credit_side));
		} else {
			iRet = INT_FORMAT_KEYWORDS_ERROR;
		}
/* real_time_post */
		if (ind_real_time_post >= 0) {
			PutField_Int(myHash, "real_time_post", v_real_time_post);
DEBUGLOG(("GetTxnCodeKeywords real_time_post = [%d]\n",v_real_time_post));
		} else {
			iRet = INT_FORMAT_KEYWORDS_ERROR;
		}
/* default */
		if (ind_default >= 0) {
			PutField_Int(myHash, "default", v_default);
DEBUGLOG(("GetTxnCodeKeywords default = [%d]\n",v_default));

/* cont_desc format_template */
			if (v_default == 0) {
				if (ind_cont_desc >= 0) {
					v_cont_desc.arr[v_cont_desc.len] = '\0';
					PutField_CString(myHash, "cont_desc", (char*)v_cont_desc.arr);
DEBUGLOG(("GetTxnCodeKeywords cont_desc = [%s]\n",v_cont_desc.arr));
				} else {
					iRet = INT_FORMAT_KEYWORDS_ERROR;
				}
				if (ind_format_template >= 0) {
					v_format_template.arr[v_format_template.len] = '\0';
					PutField_CString(myHash, "format_template", (char*)v_format_template.arr);
DEBUGLOG(("GetTxnCodeKeywords format_template = [%s]\n",v_format_template.arr));
				} else {
					iRet = INT_FORMAT_KEYWORDS_ERROR;
				}
			} else {

			}
		} else {
			iRet = INT_FORMAT_KEYWORDS_ERROR;
		}
/* min_amt */
		if (ind_min_amt >= 0) {
			PutField_Int(myHash, "min_amt", v_min_amt);
DEBUGLOG(("GetTxnCodeKeywords min_amt = [%d]\n",v_min_amt));
		} else {
			iRet = INT_FORMAT_KEYWORDS_ERROR;
		}
/* max_amt */
		if (ind_max_amt >= 0) {
			PutField_Int(myHash, "max_amt", v_max_amt);
DEBUGLOG(("GetTxnCodeKeywords max_amt = [%d]\n",v_max_amt));
		} else {
			iRet = INT_FORMAT_KEYWORDS_ERROR;
		}
/* unique_amt */
		if (ind_unique_amt >= 0) {
			PutField_Int(myHash, "unique_amt", v_unique_amt);
DEBUGLOG(("GetTxnCodeKeywords unique_amt = [%d]\n",v_unique_amt));
		} else {
			iRet = INT_FORMAT_KEYWORDS_ERROR;
		}
/* display_order */
		if (ind_display_order >= 0) {
			PutField_Int(myHash, "display_order", v_display_order);
DEBUGLOG(("GetTxnCodeKeywords display_order = [%d]\n",v_display_order));
		} else {
			iRet = INT_FORMAT_KEYWORDS_ERROR;
		}

		RecordSet_Add(myRec,myHash);
	}
	/* EXEC SQL CLOSE gettxncodecursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )187;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto gettxncode_error;
}



	if (iCnt > 0) {
		iRet = PD_FOUND;
DEBUGLOG(("GetTxnCodeKeywords FOUND\n"));
	} else {
		iRet = PD_NOT_FOUND;
DEBUGLOG(("GetTxnCodeKeywords NOT FOUND!!!\n"));
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
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )202;
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


/*
int GetRestrictKeywords(const char* csIntBankCode, const char* csFormatID,
		recordset_t* myRec)
{
	int iRet = PD_FOUND;
	int iCnt = 0;

	hash_t *myHash;

	EXEC SQL WHENEVER SQLERROR GOTO getrestrict_error;
	EXEC SQL WHENEVER NOTFOUND CONTINUE;

	EXEC SQL BEGIN DECLARE SECTION;
		varchar	hv_format_id[PD_FORMAT_ID_LEN];
		varchar	hv_int_bank_code[PD_BANK_CODE_LEN];
		varchar	v_cont_desc[PD_CONT_DESC_LEN + 1];
		varchar	v_format_template[PD_FORMAT_TEMPLATE_LEN + 1];

		short	ind_format_id = -1;
		short	ind_int_bank_code = -1;
		short	ind_cont_desc = -1;
		short	ind_format_template = -1;
	EXEC SQL END DECLARE SECTION;

	hv_format_id.len = strlen(csFormatID);
	strncpy((char*)hv_format_id.arr, csFormatID, hv_format_id.len);
	ind_format_id = 0;
DEBUGLOG(("GetRestrictKeywords format_format_id = [%.*s]\n", hv_format_id.len, hv_format_id.arr));

	hv_int_bank_code.len = strlen(csIntBankCode);
	strncpy((char*)hv_int_bank_code.arr, csIntBankCode, hv_int_bank_code.len);
	ind_int_bank_code = 0;
DEBUGLOG(("GetRestrictKeywords int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));

	EXEC SQL DECLARE getrestrictcursor CURSOR FOR
		SELECT	TP.OLFT_CONT_DESC,
			OLFK_FORMAT_TEMPLATE
		FROM	OL_STMT_FORMAT_TEMPLATE TP,
			OL_STMT_FORMAT_KEYWORDS TK
		WHERE	TP.OLFT_FORMAT_ID LIKE :hv_format_id:ind_format_id || '%'
		AND	TP.OLFT_FORMAT_TYPE = 'CONTENT'
		AND	TP.OLFT_CONT_COL_NAME = TK.OLFK_FORMAT_COL_NAME
		AND	TK.OLFK_INT_BANK_CODE = :hv_int_bank_code:ind_int_bank_code
		AND	TK.OLFK_FORMAT_TYPE = 'RESTRICT';

	EXEC SQL OPEN getrestrictcursor;
	for (;;) {
		EXEC SQL FETCH getrestrictcursor
		INTO	:v_cont_desc:ind_cont_desc,
			:v_format_template:ind_format_template;

		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash, 0);

// cont_desc
		if (ind_cont_desc >= 0) {
			v_cont_desc.arr[v_cont_desc.len] = '\0';
			PutField_CString(myHash, "cont_desc", (char*)v_cont_desc.arr);
DEBUGLOG(("GetRestrictKeywords cont_desc = [%s]\n",v_cont_desc.arr));
		} else {
			iRet = INT_FORMAT_KEYWORDS_ERROR;
		}

// format_template
		if (ind_format_template >= 0) {
			v_format_template.arr[v_format_template.len] = '\0';
			PutField_CString(myHash, "format_template", (char*)v_format_template.arr);
DEBUGLOG(("GetRestrictKeywords format_template = [%s]\n",v_format_template.arr));
		} else {
			iRet = INT_FORMAT_KEYWORDS_ERROR;
		}

		RecordSet_Add(myRec,myHash);

	}
	EXEC SQL CLOSE getrestrictcursor;

	if (iCnt > 0) {
		iRet = PD_FOUND;
DEBUGLOG(("GetRestrictKeywords FOUND\n"));
	} else {
		iRet = PD_NOT_FOUND;
DEBUGLOG(("GetRestrictKeywords NOT FOUND!!!\n"));
	}

DEBUGLOG(("GetRestrictKeywords Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getrestrict_error:
DEBUGLOG(("getrestrict_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStmtFormat getrestrict_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	EXEC SQL CLOSE getrestrictcursor;
	EXEC SQL WHENEVER SQLERROR CONTINUE;
	return PD_ERR;
}
*/


int AddKeywords(const hash_t *hRls)
{
	char	*csTmp;
	int	iTmp;

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
DEBUGLOG(("AddKeywords:int_bank_code = [%.*s]\n",hv_int_bank_code.len,hv_int_bank_code.arr));
	} else {
DEBUGLOG(("AddKeywords:int_bank_code NOT FOUND!!!\n"));
	}

// format_type
	if (GetField_CString(hRls,"format_type",&csTmp)) {
		hv_format_type.len = strlen(csTmp);
		strncpy((char*)hv_format_type.arr, csTmp, hv_format_type.len);
		ind_format_type = 0;
DEBUGLOG(("AddKeywords:format_type = [%.*s]\n",hv_format_type.len,hv_format_type.arr));
	} else {
DEBUGLOG(("AddKeywords:format_type NOT FOUND!!!\n"));
	}

// format_value
	if (GetField_Int(hRls,"format_value",&iTmp)) {
		hv_format_value = iTmp;
		ind_format_value = 0;
DEBUGLOG(("AddKeywords:format_value = [%d]\n",hv_format_value));
	}

// format_txn_code
	if (GetField_CString(hRls,"format_txn_code",&csTmp)) {
		hv_format_txn_code.len = strlen(csTmp);
		strncpy((char*)hv_format_txn_code.arr, csTmp, hv_format_txn_code.len);
		ind_format_txn_code = 0;
DEBUGLOG(("AddKeywords:format_txn_code = [%.*s]\n",hv_format_txn_code.len,hv_format_txn_code.arr));
	} else {
DEBUGLOG(("AddKeywords:format_txn_code NOT FOUND!!!\n"));
	}

// format_template
	if (GetField_CString(hRls,"format_template",&csTmp)) {
		hv_format_template.len = strlen(csTmp);
		strncpy((char*)hv_format_template.arr, csTmp, hv_format_template.len);
		ind_format_template = 0;
DEBUGLOG(("AddKeywords:format_template = [%.*s]\n",hv_format_template.len,hv_format_template.arr));
	} else {
DEBUGLOG(("AddKeywords:format_template NOT FOUND!!!\n"));
	}

// format_col_name
	if (GetField_CString(hRls,"format_col_name",&csTmp)) {
		hv_format_col_name.len = strlen(csTmp);
		strncpy((char*)hv_format_col_name.arr, csTmp, hv_format_col_name.len);
		ind_format_col_name = 0;
DEBUGLOG(("AddKeywords:format_col_name = [%.*s]\n",hv_format_col_name.len,hv_format_col_name.arr));
	} else {
DEBUGLOG(("AddKeywords:format_col_name NOT FOUND!!!\n"));
	}

// display_order
	if (GetField_Int(hRls,"display_order",&iTmp)) {
		hv_display_order = iTmp;
		ind_display_order = 0;
DEBUGLOG(("AddKeywords:display_order = [%d]\n",hv_display_order));
	}

// disabled
	hv_disabled = 0;
	if (GetField_Int(hRls,"disabled",&iTmp)) {
		hv_disabled = iTmp;
DEBUGLOG(("AddKeywords:disabled = [%d]\n",hv_disabled));
	}
	ind_disabled = 0;

// user
	if (GetField_CString(hRls,"create_user",&csTmp)) {
		hv_user.len = strlen(csTmp);
		strncpy((char*)hv_user.arr, csTmp, hv_user.len);
		ind_user = 0;
DEBUGLOG(("AddKeywords:user = [%.*s]\n",hv_user.len,hv_user.arr));
	} else if (GetField_CString(hRls,"update_user",&csTmp)) {
		hv_user.len = strlen(csTmp);
		strncpy((char*)hv_user.arr, csTmp, hv_user.len);
		ind_user = 0;
DEBUGLOG(("AddKeywords:user = [%.*s]\n",hv_user.len,hv_user.arr));
	} else {
DEBUGLOG(("AddKeywords:user NOT FOUND!!!\n"));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_stmt_format_insert(
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
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_stmt_format_insert ( :hv_in\
t_bank_code:ind_int_bank_code , :hv_format_type:ind_format_type , :hv_format_\
value:ind_format_value , :hv_format_txn_code:ind_format_txn_code , :hv_format\
_template:ind_format_template , :hv_format_col_name:ind_format_col_name , :hv\
_display_order:ind_display_order , :hv_disabled:ind_disabled , :hv_user:ind_u\
ser ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )217;
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



DEBUGLOG(("AddKeywords:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("AddKeywords:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLStatement_AddKeywords: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("AddKeywords: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLStatement_AddKeywords: SP_ERR TxnAbort\n");
DEBUGLOG(("AddKeywords: SP_ERR TxnAbort\n"));
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


/*
int UpdateKeywords(const hash_t *hRls)
{
	char	*csTmp;
	int	iTmp;

	EXEC SQL WHENEVER SQLERROR GOTO updatekeywords_error;
	EXEC SQL WHENEVER NOTFOUND CONTINUE;

	EXEC SQL BEGIN DECLARE SECTION;
		varchar		hv_int_bank_code[PD_FORMAT_ID_LEN];
		varchar		hv_format_type[PD_FORMAT_TYPE_LEN];
		int		hv_format_value;
		varchar		hv_format_txn_code[PD_TXN_CODE_LEN];
		varchar		hv_format_template[PD_FORMAT_TEMPLATE_LEN];
		varchar		hv_format_col_name[PD_COL_NAME_LEN];
		varchar		hv_user[PD_USER_LEN];

		short		ind_int_bank_code = -1;
		short		ind_format_type = -1;
		short		ind_format_value = -1;
		short		ind_format_txn_code = -1;
		short		ind_format_template = -1;
		short		ind_format_col_name = -1;
		short		ind_user = -1;

		short		hv_return_value;

	EXEC SQL END DECLARE SECTION;

// int_bank_code
	if (GetField_CString(hRls,"int_bank_code",&csTmp)) {
		hv_int_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_int_bank_code.arr, csTmp, hv_int_bank_code.len);
		ind_int_bank_code = 0;
DEBUGLOG(("UpdateKeywords:int_bank_code = [%.*s]\n",hv_int_bank_code.len,hv_int_bank_code.arr));
	} else {
DEBUGLOG(("UpdateKeywords:int_bank_code NOT FOUND!!!\n"));
	}

// format_type
	if (GetField_CString(hRls,"format_type",&csTmp)) {
		hv_format_type.len = strlen(csTmp);
		strncpy((char*)hv_format_type.arr, csTmp, hv_format_type.len);
		ind_format_type = 0;
DEBUGLOG(("UpdateKeywords:format_type = [%.*s]\n",hv_format_type.len,hv_format_type.arr));
	} else {
DEBUGLOG(("UpdateKeywords:format_type NOT FOUND!!!\n"));
	}

// format_value
	if (GetField_Int(hRls,"format_value",&iTmp)) {
		hv_format_value = iTmp;
		ind_format_value = 0;
DEBUGLOG(("UpdateKeywords:format_value = [%d]\n",hv_format_value));
	} else {
DEBUGLOG(("UpdateKeywords:format_value NOT FOUND!!!\n"));
	}

// format_txn_code
	if (GetField_CString(hRls,"format_txn_code",&csTmp)) {
		hv_format_txn_code.len = strlen(csTmp);
		strncpy((char*)hv_format_txn_code.arr, csTmp, hv_format_txn_code.len);
		ind_format_txn_code = 0;
DEBUGLOG(("UpdateKeywords:format_txn_code = [%.*s]\n",hv_format_txn_code.len,hv_format_txn_code.arr));
	} else {
DEBUGLOG(("UpdateKeywords:format_txn_code NOT FOUND!!!\n"));
	}

// format_template
	if (GetField_CString(hRls,"format_template",&csTmp)) {
		hv_format_template.len = strlen(csTmp);
		strncpy((char*)hv_format_template.arr, csTmp, hv_format_template.len);
		ind_format_template = 0;
DEBUGLOG(("UpdateKeywords:format_template = [%.*s]\n",hv_format_template.len,hv_format_template.arr));
	} else {
DEBUGLOG(("UpdateKeywords:format_template NOT FOUND!!!\n"));
	}

// format_col_name
	if (GetField_CString(hRls,"format_col_name",&csTmp)) {
		hv_format_col_name.len = strlen(csTmp);
		strncpy((char*)hv_format_col_name.arr, csTmp, hv_format_col_name.len);
		ind_format_col_name = 0;
DEBUGLOG(("UpdateKeywords:format_col_name = [%.*s]\n",hv_format_col_name.len,hv_format_col_name.arr));
	} else {
DEBUGLOG(("UpdateKeywords:format_col_name NOT FOUND!!!\n"));
	}

// user
	if (GetField_CString(hRls,"create_user",&csTmp)) {
		hv_user.len = strlen(csTmp);
		strncpy((char*)hv_user.arr, csTmp, hv_user.len);
		ind_user = 0;
DEBUGLOG(("UpdateKeywords:user = [%.*s]\n",hv_user.len,hv_user.arr));
	} else if (GetField_CString(hRls,"update_user",&csTmp)) {
		hv_user.len = strlen(csTmp);
		strncpy((char*)hv_user.arr, csTmp, hv_user.len);
		ind_user = 0;
DEBUGLOG(("UpdateKeywords:user = [%.*s]\n",hv_user.len,hv_user.arr));
	} else {
DEBUGLOG(("UpdateKeywords:user NOT FOUND!!!\n"));
	}

	EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_stmt_format_update(
						:hv_int_bank_code:ind_int_bank_code,
						:hv_format_type:ind_format_type,
						:hv_format_value:ind_format_value,
						:hv_format_txn_code:ind_format_txn_code,
						:hv_format_template:ind_format_template,
						:hv_format_col_name:ind_format_col_name,
						:hv_user:ind_user);
		END;
	END-EXEC;

DEBUGLOG(("UpdateKeywords:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("UpdateKeywords:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLStatement_UpdateKeywords: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateKeywords: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLStatement_UpdateKeywords: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateKeywords: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

updatekeywords_error:
DEBUGLOG(("update_Header_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	EXEC SQL WHENEVER SQLERROR CONTINUE;
ERRLOG("OLStatement_UpdateKeywords: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("UpdateKeywords: SP_INTERNAL_ERR TxnAbort\n"));
	TxnAbort();
	return PD_INTERNAL_ERR;
}
*/

