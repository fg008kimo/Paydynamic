
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
           char  filnam[15];
};
static struct sqlcxp sqlfpn =
{
    14,
    "OLSmsFormat.pc"
};


static unsigned int sqlctx = 1287659;


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

 static char *sq0003 = 
"SELECT INTERNAL_BANK_CODE , BANK_NAME , OSMF_KEY_WORD , OSMF_ALERT , OSMT_F\
ORMAT_ID , LOWER ( OSMT_FORMAT_TYPE ) , OSMT_FORMAT_VALUE , OSMT_FORMAT_DESC \
, OSMT_IS_GENERIC , OSMT_DELIMITER , OSMT_DELIMITER_DESC FROM OL_SMS_FORMAT ,\
 OL_SMS_FORMAT_TEMPLATE , BANK_DESC WHERE OSMF_TRUST_SENDER = :b0:b1 AND ( ( \
LENGTH ( :b2:b3 ) - LENGTH ( OSMF_KEY_WORD ) = INSTR ( :b2:b5 , OSMF_KEY_WORD\
 , - 1 , 1 ) - 1 ) OR ( SUBSTR ( :b2:b7 , 1 , LENGTH ( OSMF_KEY_WORD ) ) = OS\
MF_KEY_WORD ) ) AND OSMF_DISABLED = 0 AND OSMF_EFFECT_TIMESTAMP <= SYSDATE AN\
D OSMF_FORMAT_ID = OSMT_FORMAT_ID AND OSMF_INT_BANK_CODE = INTERNAL_BANK_CODE\
 AND OFFLINE_SUPPORT = 1 ORDER BY TO_NUMBER ( SUBSTR ( OSMT_FORMAT_ID , INSTR\
 ( OSMT_FORMAT_ID , '_' , 1 , 1 ) + 1 ) ) , LOWER ( OSMT_FORMAT_TYPE ) , OSMT\
_FORMAT_VALUE            ";

 static char *sq0004 = 
"select osfc_field_tag , osfc_only_digit , osfc_len from ol_sms_field_check \
Where osfc_format_id = :b0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,249,0,4,59,0,0,4,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
36,0,0,2,102,0,4,107,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
59,0,0,3,793,0,9,224,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
90,0,0,3,0,0,13,227,0,0,11,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,
0,0,2,3,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,
149,0,0,3,0,0,15,349,0,0,0,0,0,1,0,
164,0,0,3,0,0,15,376,0,0,0,0,0,1,0,
179,0,0,4,113,0,9,413,0,2049,1,1,0,1,0,1,9,0,0,
198,0,0,4,0,0,13,415,0,0,3,0,0,1,0,2,9,0,0,2,3,0,0,2,3,0,0,
225,0,0,4,0,0,15,448,0,0,0,0,0,1,0,
240,0,0,4,0,0,15,457,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/09/12              [WCS]
Amend sorting                                      2017/03/10              [WCS]
Add GetParam()					   2020/09/07		   [WMC]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlca.h>
#include <time.h>
#include "common.h"
#include "internal.h"
#include "utilitys.h"
#include "dbutility.h"
#include "OLSmsFormat.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define PD_FMT_DESC "desc"
#define PD_IS_GENERIC "is_generic"
#define PD_DELIMITER "delimiter"
#define PD_DELIMITER_DESC "delimiter_desc"

static char cDebug;

void OLSmsFormat(char cdebug)
{
	cDebug = cdebug;
}


int CheckBank(const char* csText)
{
	int iRet = PD_FOUND;

	/* EXEC SQL WHENEVER SQLERROR GOTO checkbank_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_text[PD_MAX_BUFFER + 1]; */ 
struct { unsigned short len; unsigned char arr[16393]; } hv_text;

		int v_cnt;

		short ind_text = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	// text
	hv_text.len = strlen(csText);
	strncpy((char*)hv_text.arr, csText, hv_text.len);
	ind_text = 0;
DEBUGLOG(("CheckBank:: text = [%.*s]\n", hv_text.len, hv_text.arr));

	/* EXEC SQL SELECT count(*)
			INTO :v_cnt
			FROM ol_sms_format
			WHERE (
				(length(:hv_text:ind_text) - length(osmf_key_word) = instr(:hv_text:ind_text, osmf_key_word, -1, 1) - 1)
				OR
				(substr(:hv_text:ind_text, 1, length(osmf_key_word)) = osmf_key_word)
			)
			AND osmf_disabled = 0; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count ( * ) INTO :b0 FROM ol_sms_format WHERE ( ( le\
ngth ( :b1:b2 ) - length ( osmf_key_word ) = instr ( :b1:b4 , osmf_key_word ,\
 - 1 , 1 ) - 1 ) OR ( substr ( :b1:b6 , 1 , length ( osmf_key_word ) ) = osmf\
_key_word ) ) AND osmf_disabled = 0 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_text;
 sqlstm.sqhstl[1] = (unsigned long )16395;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_text;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_text;
 sqlstm.sqhstl[2] = (unsigned long )16395;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_text;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_text;
 sqlstm.sqhstl[3] = (unsigned long )16395;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_text;
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
 if (sqlca.sqlcode < 0) goto checkbank_error;
}



	if (v_cnt <= 0) {
DEBUGLOG(("CheckBank:: unsupported bank\n"));
		iRet = PD_NOT_FOUND;
	}

DEBUGLOG(("CheckBank Normal Exit iRet = [%d]\n", iRet));
	return iRet;

checkbank_error:
DEBUGLOG(("checkbank_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("CheckBank checkbank_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int CheckSender(const char* csSender)
{
	int iRet = PD_FOUND;

	/* EXEC SQL WHENEVER SQLERROR GOTO checksender_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_sender[PD_SMS_SENDER_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_sender;

		int v_cnt;

		short ind_sender = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	// sender
	hv_sender.len = strlen(csSender);
	strncpy((char*)hv_sender.arr, csSender, hv_sender.len);
	ind_sender = 0;
DEBUGLOG(("CheckSender:: sender = [%.*s]\n", hv_sender.len, hv_sender.arr));

	/* EXEC SQL SELECT count(*)
			INTO :v_cnt
			FROM ol_sms_format
			WHERE osmf_trust_sender = :hv_sender:ind_sender
			AND osmf_disabled = 0; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count ( * ) INTO :b0 FROM ol_sms_format WHERE osmf_t\
rust_sender = :b1:b2 AND osmf_disabled = 0 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )36;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_sender;
 sqlstm.sqhstl[1] = (unsigned long )23;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_sender;
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
 if (sqlca.sqlcode < 0) goto checksender_error;
}



	if (v_cnt <= 0) {
DEBUGLOG(("CheckSender:: untrusted sender\n"));
		iRet = PD_NOT_FOUND;
	}

DEBUGLOG(("CheckSender Normal Exit iRet = [%d]\n", iRet));
	return iRet;

checksender_error:
DEBUGLOG(("checksender_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("CheckSender checksender_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int GetFormat(const char* csSender, const char* csText, recordset_t* rRecordSet)
{
	int iRet = PD_OK;
	int iCnt = 0;

	char csIntBankCode[PD_BANK_CODE_LEN + 1];
	char csBankName[PD_BANK_NAME_LEN + 1];
	char csKeyWord[PD_TMP_BUF_LEN + 1];
	int iAlert;

	char csLastFormatId[PD_FORMAT_ID_LEN + 1];
	char csCurrFormatId[PD_FORMAT_ID_LEN + 1];

	char csFormatType[PD_FORMAT_TYPE_LEN + 1];
	char *csFormatValue = (char*) malloc (64);

	char *csTag = (char*) malloc (64);

	hash_t *myHash;
	myHash = (hash_t*) malloc (sizeof(hash_t));
	hash_init(myHash, 0);

	/* EXEC SQL WHENEVER SQLERROR GOTO getformat_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_sender[PD_SMS_SENDER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_sender;

		/* varchar hv_text[PD_MAX_BUFFER]; */ 
struct { unsigned short len; unsigned char arr[16392]; } hv_text;

		/* varchar v_int_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_int_bank_code;

		/* varchar v_bank_name[PD_BANK_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

		/* varchar v_key_word[PD_TMP_BUF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_key_word;

		int	v_alert;
		/* varchar v_id[PD_FORMAT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_id;

		/* varchar v_type[PD_FORMAT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_type;

		int	v_value;
		/* varchar v_desc[PD_FORMAT_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_desc;

		int	v_is_generic;
		/* varchar v_delimiter[PD_FORMAT_DELIMITER_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[501]; } v_delimiter;

		/* varchar v_delimiter_desc[PD_FORMAT_DELIMITER_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_delimiter_desc;


		short ind_sender = -1;
		short ind_text = -1;
		short ind_int_bank_code = -1;
		short ind_bank_name = -1;
		short ind_key_word = -1;
		short ind_alert = -1;
		short ind_id = -1;
		short ind_type = -1;
		short ind_value = -1;
		short ind_desc = -1;
		short ind_is_generic = -1;
		short ind_delimiter = -1;
		short ind_delimiter_desc = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	// sender
	hv_sender.len = strlen(csSender);
	strncpy((char*)hv_sender.arr, csSender, hv_sender.len);
	ind_sender = 0;
DEBUGLOG(("GetFormat: sender = [%.*s]\n", hv_sender.len, hv_sender.arr));

	// text
	hv_text.len = strlen(csText);
	strncpy((char*)hv_text.arr, csText, hv_text.len);
	ind_text = 0;
DEBUGLOG(("GetFormat: text = [%.*s]\n", hv_text.len, hv_text.arr));

	/* EXEC SQL DECLARE c_cursor_getformat CURSOR FOR
		SELECT INTERNAL_BANK_CODE,
			BANK_NAME,
			OSMF_KEY_WORD,
			OSMF_ALERT,
			OSMT_FORMAT_ID,
			LOWER(OSMT_FORMAT_TYPE),
			OSMT_FORMAT_VALUE,
			OSMT_FORMAT_DESC,
			OSMT_IS_GENERIC,
			OSMT_DELIMITER,
			OSMT_DELIMITER_DESC
		FROM OL_SMS_FORMAT, OL_SMS_FORMAT_TEMPLATE, BANK_DESC
		WHERE OSMF_TRUST_SENDER = :hv_sender:ind_sender
		AND (
			(LENGTH(:hv_text:ind_text) - LENGTH(OSMF_KEY_WORD) = INSTR(:hv_text:ind_text, OSMF_KEY_WORD, -1, 1) - 1)
			OR
			(SUBSTR(:hv_text:ind_text, 1, LENGTH(OSMF_KEY_WORD)) = OSMF_KEY_WORD)
		)
		AND OSMF_DISABLED = 0
		AND OSMF_EFFECT_TIMESTAMP <= SYSDATE
		AND OSMF_FORMAT_ID = OSMT_FORMAT_ID
		AND OSMF_INT_BANK_CODE = INTERNAL_BANK_CODE
		AND OFFLINE_SUPPORT = 1
		ORDER BY TO_NUMBER(SUBSTR(OSMT_FORMAT_ID, INSTR(OSMT_FORMAT_ID, '_', 1, 1) + 1)), LOWER(OSMT_FORMAT_TYPE), OSMT_FORMAT_VALUE; */ 


	/* EXEC SQL OPEN c_cursor_getformat; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )59;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_sender;
 sqlstm.sqhstl[0] = (unsigned long )22;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_sender;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_text;
 sqlstm.sqhstl[1] = (unsigned long )16394;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_text;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_text;
 sqlstm.sqhstl[2] = (unsigned long )16394;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_text;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_text;
 sqlstm.sqhstl[3] = (unsigned long )16394;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_text;
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
 if (sqlca.sqlcode < 0) goto getformat_error;
}



	for (;;) {
		/* EXEC SQL FETCH c_cursor_getformat
		INTO :v_int_bank_code:ind_int_bank_code,
			:v_bank_name:ind_bank_name,
			:v_key_word:ind_key_word,
			:v_alert:ind_alert,
			:v_id:ind_id,
			:v_type:ind_type,
			:v_value:ind_value,
			:v_desc:ind_desc,
			:v_is_generic:ind_is_generic,
			:v_delimiter:ind_delimiter,
			:v_delimiter_desc:ind_delimiter_desc; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 11;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )90;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_int_bank_code;
  sqlstm.sqhstl[0] = (unsigned long )13;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_int_bank_code;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_bank_name;
  sqlstm.sqhstl[1] = (unsigned long )153;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_bank_name;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_key_word;
  sqlstm.sqhstl[2] = (unsigned long )259;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_key_word;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_alert;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_alert;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_id;
  sqlstm.sqhstl[4] = (unsigned long )23;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_id;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_type;
  sqlstm.sqhstl[5] = (unsigned long )23;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_type;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_value;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_value;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_desc;
  sqlstm.sqhstl[7] = (unsigned long )53;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_desc;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_is_generic;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_is_generic;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_delimiter;
  sqlstm.sqhstl[9] = (unsigned long )503;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_delimiter;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_delimiter_desc;
  sqlstm.sqhstl[10] = (unsigned long )53;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_delimiter_desc;
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
  if (sqlca.sqlcode < 0) goto getformat_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

/* int bank code */
		if (ind_int_bank_code >= 0) {
			v_int_bank_code.arr[v_int_bank_code.len] = '\0';
DEBUGLOG(("GetFormat: int_bank_code = [%s]\n", (const char*)v_int_bank_code.arr));
			strcpy(csIntBankCode, (const char*)v_int_bank_code.arr);
		}

/* bank name */
		if (ind_bank_name >= 0) {
			v_bank_name.arr[v_bank_name.len] = '\0';
DEBUGLOG(("GetFormat: bank_name = [%s]\n", (const char*)v_bank_name.arr));
			strcpy(csBankName, (const char*)v_bank_name.arr);
		}

/* key word */
		if (ind_key_word >= 0) {
			v_key_word.arr[v_key_word.len] = '\0';
DEBUGLOG(("GetFormat: key_word = [%s]\n", (const char*)v_key_word.arr));
			strcpy(csKeyWord, (const char*)v_key_word.arr);
		}

/* id */
		if (ind_id >= 0) {
			v_id.arr[v_id.len] = '\0';
DEBUGLOG(("GetFormat: id = [%s]\n", (const char*)v_id.arr));
			strcpy(csCurrFormatId, (const char*)v_id.arr);
			if (iCnt == 1) {
				PutField_CString(myHash, "id", csCurrFormatId);
				strcpy(csLastFormatId, csCurrFormatId);
			} else {
				if (strcmp(csCurrFormatId, csLastFormatId)) {
					PutField_CString(myHash, "int_bank_code", csIntBankCode);
					PutField_CString(myHash, "bank_name", csBankName);
					PutField_CString(myHash, "key_word", csKeyWord);
					PutField_Int(myHash, "alert", iAlert);
					RecordSet_Add(rRecordSet, myHash);
DEBUGLOG(("GetFormat hash added - id = [%s]\n", csLastFormatId));
					myHash = (hash_t*) malloc (sizeof(hash_t));
					hash_init(myHash, 0);
					PutField_CString(myHash, "id", csCurrFormatId);
					strcpy(csLastFormatId, csCurrFormatId);
				}
			}
		}


/* alert */
		if (ind_alert >= 0) {
DEBUGLOG(("GetFormat: alert = [%d]\n", v_alert));
			iAlert = v_alert;
		}

/* type */
		if (ind_type >= 0) {
			v_type.arr[v_type.len] = '\0';
DEBUGLOG(("GetFormat: type = [%s]\n", (const char*)v_type.arr));
			strcpy(csFormatType, (const char*)v_type.arr);
		}

/* value */
		if (ind_value >= 0) {
DEBUGLOG(("GetFormat: value = [%d]\n", v_value));
			sprintf(csFormatValue, "%d", v_value);
		}

		if (strcmp(csFormatType, "content_cnt") == 0) {
DEBUGLOG(("GetFormat: %s = [%d]\n", csFormatType, v_value));
			PutField_Int(myHash, csFormatType, v_value);
			continue;
		}

/* desc */
		if (ind_desc >= 0) {
			v_desc.arr[v_desc.len] = '\0';
DEBUGLOG(("GetFormat: %s = [%s]\n", PD_FMT_DESC, (const char*)v_desc.arr));
			sprintf(csTag, "%s_%s_%s", csFormatType, PD_FMT_DESC, csFormatValue);
			PutField_CString(myHash, csTag, (const char*)v_desc.arr);
		}

/* is generic */
		if (ind_is_generic >= 0) {
DEBUGLOG(("GetFormat: %s = [%d]\n", PD_IS_GENERIC, v_is_generic));
			sprintf(csTag, "%s_%s_%s", csFormatType, PD_IS_GENERIC, csFormatValue);
			PutField_Int(myHash, csTag, v_is_generic);
		}

/* delimiter */
		if (ind_delimiter >= 0) {
			v_delimiter.arr[v_delimiter.len] = '\0';
DEBUGLOG(("GetFormat: %s = [%s]\n", PD_DELIMITER, (const char*)v_delimiter.arr));
			sprintf(csTag, "%s_%s_%s", csFormatType, PD_DELIMITER, csFormatValue);
			PutField_CString(myHash, csTag, (const char*)v_delimiter.arr);
		}

/* delimiter desc */
		if (ind_delimiter_desc >= 0) {
			v_delimiter_desc.arr[v_delimiter_desc.len] = '\0';
DEBUGLOG(("GetFormat: %s = [%s]\n", PD_DELIMITER_DESC, (const char*)v_delimiter_desc.arr));
			sprintf(csTag, "%s_%s_%s", csFormatType, PD_DELIMITER_DESC, csFormatValue);
			PutField_CString(myHash, csTag, (const char*)v_delimiter_desc.arr);
		}
	}

	/* EXEC SQL CLOSE c_cursor_getformat; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )149;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getformat_error;
}



	if (iCnt > 0 ) {
		PutField_CString(myHash, "int_bank_code", csIntBankCode);
		PutField_CString(myHash, "bank_name", csBankName);
		PutField_CString(myHash, "key_word", csKeyWord);
		PutField_Int(myHash, "alert", iAlert);
		RecordSet_Add(rRecordSet, myHash);
DEBUGLOG(("GetFormat hash added - id = [%s]\n", csCurrFormatId));
		iRet = PD_OK;
	} else {
DEBUGLOG(("GetFormat not found\n"));
ERRLOG("OLSmsFormat:: GetFormat not found\n");
		iRet = PD_ERR;
	}

	FREE_ME(csFormatValue);
	FREE_ME(csTag);

DEBUGLOG(("GetFormat Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getformat_error:
DEBUGLOG(("getformat_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLSmsFormat getformat_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL CLOSE c_cursor_getformat; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )164;
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


int GetParam(const char* csFormatId, recordset_t* rRecordSet)
{
        int iRet = PD_OK;
        hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getparam_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_format_id[PD_FORMAT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_format_id;


                /* varchar v_field_tag[PD_TAG_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_field_tag;

                int     v_only_digit;
                int     v_len;

                short   ind_field_tag = -1;
                short   ind_only_digit = -1;
                short   ind_len = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_format_id.len = strlen(csFormatId);
        memcpy(hv_format_id.arr,csFormatId,hv_format_id.len);
DEBUGLOG(("GetParam: txn code = [%.*s][%d]\n",hv_format_id.len,hv_format_id.arr,hv_format_id.len));

        /* EXEC SQL DECLARE c_cursor_getparam CURSOR FOR
                 select osfc_field_tag,
                        osfc_only_digit,
                        osfc_len
                   from ol_sms_field_check
                  Where osfc_format_id = :hv_format_id; */ 


        /* EXEC SQL OPEN c_cursor_getparam; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0004;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )179;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_format_id;
        sqlstm.sqhstl[0] = (unsigned long )23;
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
        if (sqlca.sqlcode < 0) goto getparam_error;
}


	do {
                /* EXEC SQL FETCH c_cursor_getparam
                INTO
                        :v_field_tag:ind_field_tag,
                        :v_only_digit:ind_only_digit,
                        :v_len:ind_len; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 11;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )198;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_field_tag;
                sqlstm.sqhstl[0] = (unsigned long )28;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_field_tag;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_only_digit;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_only_digit;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_len;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_len;
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
                if (sqlca.sqlcode < 0) goto getparam_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

                if (ind_field_tag >= 0) {
                        v_field_tag.arr[v_field_tag.len] ='\0';
                        PutField_CString(myHash,"field_tag",(const char*)v_field_tag.arr);
DEBUGLOG((" field_tag = [%s]\n",v_field_tag.arr));
                }

		if (ind_only_digit >= 0) {
                        PutField_Int(myHash,"only_digit",v_only_digit);
DEBUGLOG((" only_digit = [%d]\n",v_only_digit));
                }

                if (ind_len >= 0) {
                        PutField_Int(myHash,"len",v_len);
DEBUGLOG((" len = [%d]\n",v_len));
                }

                RecordSet_Add(rRecordSet,myHash);

        }while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getparam; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )225;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getparam_error;
}



DEBUGLOG(("GetParam Normal Exit iRet[%d]\n",iRet));
        return iRet;

getparam_error:
DEBUGLOG(("getparam_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getparam; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 11;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )240;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}

