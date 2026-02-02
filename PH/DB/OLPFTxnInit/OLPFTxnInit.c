
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
    "OLPFTxnInit.pc"
};


static unsigned int sqlctx = 1278923;


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
   unsigned char  *sqhstv[13];
   unsigned long  sqhstl[13];
            int   sqhsts[13];
            short *sqindv[13];
            int   sqinds[13];
   unsigned long  sqharm[13];
   unsigned long  *sqharc[13];
   unsigned short  sqadto[13];
   unsigned short  sqtdso[13];
} sqlstm = {12,13};

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
"SELECT OPID_SEQ , OPID_TXN_ID , OPID_BAID , OPID_REPORT_DATE , OPID_CCY , O\
PID_TXN_TYPE , OPID_DEBIT_AMT , OPID_CREDIT_AMT , OPID_BAID_NAME , OPID_REMAR\
K FROM OL_PF_TXN_INIT_DETAIL WHERE OPID_FILE_ID = :b0:b1 ORDER BY OPID_SEQ   \
         ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,168,0,4,59,0,0,5,1,0,1,0,2,9,0,0,2,3,0,0,2,3,0,0,2,1,0,0,1,9,0,0,
40,0,0,2,238,0,9,159,0,2049,1,1,0,1,0,1,9,0,0,
59,0,0,2,0,0,13,161,0,0,10,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,
114,0,0,2,0,0,15,242,0,0,0,0,0,1,0,
129,0,0,2,0,0,15,259,0,0,0,0,0,1,0,
144,0,0,3,84,0,4,351,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
167,0,0,4,245,0,6,452,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,
1,0,0,1,9,0,0,
210,0,0,5,0,0,17,561,0,0,1,1,0,1,0,1,9,0,0,
229,0,0,5,0,0,21,562,0,0,0,0,0,1,0,
244,0,0,6,381,0,6,701,0,0,13,13,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,4,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
311,0,0,5,0,0,17,813,0,0,1,1,0,1,0,1,9,0,0,
330,0,0,5,0,0,21,814,0,0,0,0,0,1,0,
345,0,0,7,168,0,6,891,0,0,5,5,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
380,0,0,8,121,0,4,952,0,0,3,2,0,1,0,2,9,0,0,1,9,0,0,1,1,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/04/29              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "OLPFTxnInit.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char	cDebug;

void OLPFTxnInit(char	cdebug)
{
	cDebug = cdebug;
}


int GetHeader(const char *csFileId, hash_t *myHash)
{
        int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO getheader_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

		/* varchar		v_filename[PD_UPLOAD_FILENAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_filename;

		int		v_accept_count;
		int		v_total_count;
		char		v_status;

		short		ind_file_id = -1;
		short		ind_filename = -1;
		short		ind_accept_count = -1;
		short		ind_total_count = -1;
		short		ind_status = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_file_id.len = strlen(csFileId);
	strncpy((char*)hv_file_id.arr,csFileId,hv_file_id.len);
	ind_file_id = 0;
DEBUGLOG(("GetHeader file_id = [%.*s]\n",hv_file_id.len,hv_file_id.arr));

	/* EXEC SQL	SELECT	OPIH_FILENAME,
				OPIH_ACCEPT_COUNT,
				OPIH_TOTAL_COUNT,
				OPIH_STATUS
			INTO	:v_filename:ind_filename,
				:v_accept_count:ind_accept_count,
				:v_total_count:ind_total_count,
				:v_status:ind_status
			FROM	OL_PF_TXN_INIT_HEADER
			WHERE	OPIH_FILE_ID = :hv_file_id:ind_file_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select OPIH_FILENAME , OPIH_ACCEPT_COUNT , OPIH_TOTAL_COUNT\
 , OPIH_STATUS INTO :b0:b1 , :b2:b3 , :b4:b5 , :b6:b7 FROM OL_PF_TXN_INIT_HEA\
DER WHERE OPIH_FILE_ID = :b8:b9 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_filename;
 sqlstm.sqhstl[0] = (unsigned long )103;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_filename;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_accept_count;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_accept_count;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_total_count;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_total_count;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&v_status;
 sqlstm.sqhstl[3] = (unsigned long )1;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_status;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[4] = (unsigned long )18;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_file_id;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto getheader_error;
}



	if (ind_filename >= 0) {
		v_filename.arr[v_filename.len] = '\0';
		PutField_CString(myHash,"filename",(char*)v_filename.arr);
DEBUGLOG(("GetHeader filename = [%s]\n",(char*)v_filename.arr));
	}

	if (ind_accept_count >= 0) {
		PutField_Int(myHash,"accept_count",v_accept_count);
DEBUGLOG(("GetHeader accept_count = [%d]\n",v_accept_count));
	}

	if (ind_total_count >= 0) {
		PutField_Int(myHash,"total_count",v_total_count);
DEBUGLOG(("GetHeader total_count = [%d]\n",v_total_count));
	}

	if (ind_status >= 0) {
		PutField_Char(myHash,"status",v_status);
DEBUGLOG(("GetHeader status = [%c]\n",v_status));
	}

DEBUGLOG(("GetHeader Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getheader_error:
DEBUGLOG(("getheader_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int GetDetail(const char *csFileId, recordset_t *myRec)
{
        int iRet = PD_OK;
	int iCnt = 0;

	hash_t *myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO getdetail_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

		int		v_seq;
		/* varchar		v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar		v_baid[PD_BAID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_baid;

		/* varchar		v_report_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_report_date;

		/* varchar		v_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ccy;

		/* varchar		v_txn_type[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_type;

		double		v_debit_amt;
		double		v_credit_amt;
		/* varchar		v_baid_name[PD_BAID_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_baid_name;

		/* varchar		v_remark[PD_REMARK_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;


		short		ind_file_id = -1;
		short		ind_seq = -1;
		short		ind_txn_id = -1;
		short		ind_baid = -1;
		short		ind_report_date = -1;
		short		ind_ccy = -1;
		short		ind_txn_type = -1;
		short		ind_debit_amt = -1;
		short		ind_credit_amt = -1;
		short		ind_baid_name = -1;
		short		ind_remark = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_file_id.len = strlen(csFileId);
	strncpy((char*)hv_file_id.arr,csFileId,hv_file_id.len);
	ind_file_id = 0;
DEBUGLOG(("GetDetail file_id = [%.*s]\n",hv_file_id.len,hv_file_id.arr));

	/* EXEC SQL DECLARE getdetailcursor CURSOR FOR
		SELECT	OPID_SEQ,
			OPID_TXN_ID,
			OPID_BAID,
			OPID_REPORT_DATE,
			OPID_CCY,
			OPID_TXN_TYPE,
			OPID_DEBIT_AMT,
			OPID_CREDIT_AMT,
			OPID_BAID_NAME,
			OPID_REMARK
		FROM	OL_PF_TXN_INIT_DETAIL
		WHERE	OPID_FILE_ID = :hv_file_id:ind_file_id
		ORDER BY OPID_SEQ; */ 


	/* EXEC SQL OPEN getdetailcursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )40;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[0] = (unsigned long )18;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_file_id;
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
 if (sqlca.sqlcode < 0) goto getdetail_error;
}


	for (;;) {
		/* EXEC SQL FETCH getdetailcursor
		INTO	:v_seq:ind_seq,
			:v_txn_id:ind_txn_id,
			:v_baid:ind_baid,
			:v_report_date:ind_report_date,
			:v_ccy:ind_ccy,
			:v_txn_type:ind_txn_type,
			:v_debit_amt:ind_debit_amt,
			:v_credit_amt:ind_credit_amt,
			:v_baid_name:ind_baid_name,
			:v_remark:ind_remark; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 10;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )59;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_seq;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_seq;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[1] = (unsigned long )19;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_txn_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_baid;
  sqlstm.sqhstl[2] = (unsigned long )23;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_baid;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_report_date;
  sqlstm.sqhstl[3] = (unsigned long )11;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_report_date;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_ccy;
  sqlstm.sqhstl[4] = (unsigned long )6;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_ccy;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_txn_type;
  sqlstm.sqhstl[5] = (unsigned long )53;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_txn_type;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_debit_amt;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_debit_amt;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_credit_amt;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_credit_amt;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_baid_name;
  sqlstm.sqhstl[8] = (unsigned long )103;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_baid_name;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_remark;
  sqlstm.sqhstl[9] = (unsigned long )258;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_remark;
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
  if (sqlca.sqlcode < 0) goto getdetail_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

		if (ind_seq >= 0) {
			PutField_Int(myHash,"seq",v_seq);
DEBUGLOG(("GetDetail seq = [%d]\n",v_seq));
		}

		if (ind_txn_id >= 0) {
			v_txn_id.arr[v_txn_id.len] = '\0';
			PutField_CString(myHash,"txn_id",(char*)v_txn_id.arr);
DEBUGLOG(("GetDetail txn_id = [%s]\n",(char*)v_txn_id.arr));
		}

		if (ind_baid >= 0) {
			v_baid.arr[v_baid.len] = '\0';
			PutField_CString(myHash,"baid",(char*)v_baid.arr);
DEBUGLOG(("GetDetail baid = [%s]\n",(char*)v_baid.arr));
		}

		if (ind_report_date >= 0) {
			v_report_date.arr[v_report_date.len] = '\0';
			PutField_CString(myHash,"report_date",(char*)v_report_date.arr);
DEBUGLOG(("GetDetail report_date = [%s]\n",(char*)v_report_date.arr));
		}

		if (ind_ccy >= 0) {
			v_ccy.arr[v_ccy.len] = '\0';
			PutField_CString(myHash,"ccy",(char*)v_ccy.arr);
DEBUGLOG(("GetDetail ccy = [%s]\n",(char*)v_ccy.arr));
		}

		if (ind_txn_type >= 0) {
			v_txn_type.arr[v_txn_type.len] = '\0';
			PutField_CString(myHash,"txn_type",(char*)v_txn_type.arr);
DEBUGLOG(("GetDetail txn_type = [%s]\n",(char*)v_txn_type.arr));
		}

		if (ind_debit_amt >= 0) {
			PutField_Double(myHash,"debit_amt",v_debit_amt);
DEBUGLOG(("GetDetail debit_amt = [%.2f]\n",v_debit_amt));
		}

		if (ind_credit_amt >= 0) {
			PutField_Double(myHash,"credit_amt",v_credit_amt);
DEBUGLOG(("GetDetail credit_amt = [%.2f]\n",v_credit_amt));
		}

		if (ind_baid_name >= 0) {
			v_baid_name.arr[v_baid_name.len] = '\0';
			PutField_CString(myHash,"baid_name",(char*)v_baid_name.arr);
DEBUGLOG(("GetDetail baid_name = [%s]\n",(char*)v_baid_name.arr));
		}

		if (ind_remark >= 0) {
			v_remark.arr[v_remark.len] = '\0';
			PutField_CString(myHash,"remark",(char*)v_remark.arr);
DEBUGLOG(("GetDetail remark = [%s]\n",(char*)v_remark.arr));
		}

		RecordSet_Add(myRec,myHash);

	}
	/* EXEC SQL CLOSE getdetailcursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )114;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getdetail_error;
}



	if (iCnt > 0) {
		iRet = PD_OK;
DEBUGLOG(("GetDetail [%d] records FOUND\n",iCnt));
	} else {
		iRet = PD_ERR;
DEBUGLOG(("GetDetail records NOT FOUND!!!\n"));
ERRLOG("OLPFTxnInit:: GetDetail NOT FOUND!!!\n");
	}

DEBUGLOG(("GetDetail Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getdetail_error:
DEBUGLOG(("getdetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL CLOSE getdetailcursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )129;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getdetail_error;
}


        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

/*
int GetNextFileId(char *csFileId)
{
	EXEC SQL WHENEVER SQLERROR GOTO getnextfileid_error;
	EXEC SQL WHENEVER NOTFOUND CONTINUE;

	EXEC SQL BEGIN DECLARE SECTION;
		varchar	v_file_id[PD_TXN_SEQ_LEN + 1];
		short	ind_file_id = -1;

        EXEC SQL END DECLARE SECTION;

        EXEC SQL SELECT TO_CHAR(PFI_FILE_SEQ.NEXTVAL, 'FM0999999999999999')
        	   INTO :v_file_id:ind_file_id
                 FROM dual;

	if (ind_file_id >= 0) {
		v_file_id.arr[v_file_id.len] = '\0';
		strcpy(csFileId,(const char*)v_file_id.arr);
DEBUGLOG(("GenFileId file_id = [%s]\n", csFileId));
		return PD_OK;
	}

DEBUGLOG(("GetNextFileId FAILURE!!!\n"));
	return PD_ERR;;

getnextfileid_error:
DEBUGLOG(("getnextfileid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        EXEC SQL WHENEVER SQLERROR CONTINUE;
        return PD_ERR;
}


int GetNextErrorId(char *csErrorId)
{
	EXEC SQL WHENEVER SQLERROR GOTO getnexterrorid_error;
	EXEC SQL WHENEVER NOTFOUND CONTINUE;

	EXEC SQL BEGIN DECLARE SECTION;
		varchar	v_error_id[PD_TXN_SEQ_LEN + 1];
		short	ind_error_id = -1;

        EXEC SQL END DECLARE SECTION;

        EXEC SQL SELECT TO_CHAR(PFI_ERROR_SEQ.NEXTVAL, 'FM0999999999999999')
        	   INTO :v_error_id:ind_error_id
                 FROM dual;

	if (ind_error_id >= 0) {
		v_error_id.arr[v_error_id.len] = '\0';
		strcpy(csErrorId,(const char*)v_error_id.arr);
DEBUGLOG(("GenErrorId error_id = [%s]\n", csErrorId));
		return PD_OK;
	}

DEBUGLOG(("GetNextErrorId FAILURE!!!\n"));
	return PD_ERR;;

getnexterrorid_error:
DEBUGLOG(("getnexterrorid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        EXEC SQL WHENEVER SQLERROR CONTINUE;
        return PD_ERR;
}
*/

int CheckFileExist(const char* csFilename)
{
        int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO checkheader_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_filename[PD_UPLOAD_FILENAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_filename;

		int	v_cnt;

		short	ind_filename = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_filename.len = strlen(csFilename);
	strncpy((char*)hv_filename.arr,csFilename,hv_filename.len);
	ind_filename = 0;
DEBUGLOG(("CheckFileExist filename = [%s]\n",csFilename));

	/* EXEC SQL	SELECT	COUNT(*)
			INTO	:v_cnt
			FROM	OL_PF_TXN_INIT_HEADER
			WHERE	OPIH_FILENAME = :hv_filename:ind_filename; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select COUNT ( * ) INTO :b0 FROM OL_PF_TXN_INIT_HEADER WHER\
E OPIH_FILENAME = :b1:b2 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )144;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_filename;
 sqlstm.sqhstl[1] = (unsigned long )102;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_filename;
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
 if (sqlca.sqlcode < 0) goto checkheader_error;
}



	if (v_cnt>0) {
		iRet = FOUND;
DEBUGLOG(("CheckFileExist filename [%s] FOUND\n",csFilename));
	} else {
		iRet = NOT_FOUND;
DEBUGLOG(("CheckFileExist filename [%s] NOT FOUND\n",csFilename));
	}

DEBUGLOG(("CheckFileExist Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

checkheader_error:
DEBUGLOG(("checkheader_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int AddHeader(const hash_t *hRls)
{
	char	*csTmp;
	int	iTmp;
	char	cTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_header_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

		/* varchar		hv_filename[PD_UPLOAD_FILENAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_filename;

		int		hv_accept_count;
		int		hv_total_count;
		char		hv_status;
		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_file_id = -1;
		short		ind_filename = -1;
		short		ind_accept_count = -1;
		short		ind_total_count = -1;
		short		ind_status = -1;
		short		ind_create_user = -1;

		short		hv_return_value;

	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls,"file_id",&csTmp)) {
		hv_file_id.len = strlen(csTmp);
		strncpy((char*)hv_file_id.arr, csTmp, hv_file_id.len);
		ind_file_id = 0;
DEBUGLOG(("AddHeader:file_id = [%.*s]\n",hv_file_id.len, hv_file_id.arr));
	} else {
DEBUGLOG(("AddHeader:file_id NOT FOUND!!!\n"));
	}

	if (GetField_CString(hRls,"filename",&csTmp)) {
		hv_filename.len = strlen(csTmp);
		strncpy((char*)hv_filename.arr, csTmp, hv_filename.len);
		ind_filename = 0;
DEBUGLOG(("AddHeader:filename = [%.*s]\n",hv_filename.len, hv_filename.arr));
	} else {
DEBUGLOG(("AddHeader:filename NOT FOUND!!!\n"));
	}

	hv_accept_count = 0;
	if (GetField_Int(hRls, "accept_count", &iTmp)) {
		hv_accept_count = iTmp;
DEBUGLOG(("AddHeader:accept_count = [%d]\n",hv_accept_count));
	}
	ind_accept_count = 0;

	hv_total_count = 0;
	if (GetField_Int(hRls, "total_count", &iTmp)) {
		hv_total_count = iTmp;
DEBUGLOG(("AddHeader:total_count = [%d]\n",hv_total_count));
	}
	ind_total_count = 0;

	if (GetField_Char(hRls,"status",&cTmp))
	{
		hv_status = cTmp;
		ind_status = 0;
DEBUGLOG(("AddHeader:status = [%c]\n",hv_status));
	}

	if (GetField_CString(hRls,"create_user",&csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
DEBUGLOG(("AddHeader:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));
	} else {
DEBUGLOG(("AddHeader:create_user NOT FOUND!!!\n"));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_pf_txn_init_hd_insert(
						:hv_file_id:ind_file_id,
						:hv_filename:ind_filename,
						:hv_accept_count:ind_accept_count,
						:hv_total_count:ind_total_count,
						:hv_status:ind_status,
						:hv_create_user:ind_create_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_pf_txn_init_hd_insert ( :hv\
_file_id:ind_file_id , :hv_filename:ind_filename , :hv_accept_count:ind_accep\
t_count , :hv_total_count:ind_total_count , :hv_status:ind_status , :hv_creat\
e_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )167;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_file_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_filename;
 sqlstm.sqhstl[2] = (unsigned long )102;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_filename;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_accept_count;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_accept_count;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_total_count;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_total_count;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[5] = (unsigned long )1;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_status;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[6] = (unsigned long )22;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto add_header_error;
}



DEBUGLOG(("AddHeader:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("AddHeader:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLPFTxnInit_AddHeader: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("AddHeader: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLPFTxnInit_AddHeader: SP_ERR TxnAbort\n");
DEBUGLOG(("AddHeader: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

add_header_error:
DEBUGLOG(("add_header_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPFTxnInit_AddHeader: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int UpdateHeader(const hash_t *hRls)
{
	char	*csTmp;
	char	*csFileId;
	int	iTmp;
	char 	cTmp;

	char*	csBuf;
	csBuf = (char *) malloc(128);

        /* EXEC SQL WHENEVER SQLERROR GOTO update_header_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar	hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


        strcpy((char*)hv_dynstmt.arr,"update ol_pf_txn_init_header set opih_update_timestamp = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	if (!GetField_CString(hRls,"file_id",&csFileId)) {
DEBUGLOG(("UpdateHeader: file_id NOT FOUND!!!\n"));
	}

/* update_user */
        if (GetField_CString(hRls,"update_user",&csTmp)) {
DEBUGLOG(("UpdateHeader:update_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",opih_update_user= '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* accept_count */
	if (GetField_Int(hRls,"accept_count",&iTmp)) {
DEBUGLOG(("UpdateHeader:accept_count = [%d]\n",iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ",opih_accept_count = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* total_count */
	if (GetField_Int(hRls,"total_count",&iTmp)) {
DEBUGLOG(("UpdateHeader:total_count = [%d]\n",iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ",opih_total_count = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* status */
	if (GetField_Char(hRls,"status",&cTmp)) {
DEBUGLOG(("UpdateHeader:status = [%c]\n",cTmp));
		sprintf(csBuf, "%c", cTmp);
		strcat((char*)hv_dynstmt.arr, ",opih_status = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

        strcat((char *)hv_dynstmt.arr, " WHERE opih_file_id = '");
        strcat((char *)hv_dynstmt.arr, csFileId);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )210;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
        sqlstm.sqhstl[0] = (unsigned long )1026;
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
        if (sqlca.sqlcode < 0) goto update_header_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )229;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_header_error;
}



	FREE_ME(csBuf);

DEBUGLOG(("UpdateHeader Normal Exit\n"));
        return PD_OK;

update_header_error:
DEBUGLOG(("update_Header_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLPFTxnInit_UpdateHeader: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("UpdateHeader: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;
}


int AddDetail(hash_t *hRls)
{
	int	iTmp;
	char	*csTmp;
	double	dTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_detail_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

		int		hv_seq;
		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		/* varchar		hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

		/* varchar		hv_report_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_report_date;

		/* varchar		hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

		/* varchar		hv_txn_type[PD_DESC_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_txn_type;

		double		hv_debit_amt;
		double		hv_credit_amt;
		/* varchar		hv_baid_name[PD_BAID_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_baid_name;

		/* varchar		hv_remark[PD_REMARK_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_remark;

		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_file_id = -1;
		short		ind_seq = -1;
		short		ind_txn_id = -1;
		short		ind_baid = -1;
		short		ind_report_date = -1;
		short		ind_ccy = -1;
		short		ind_txn_type = -1;
		short		ind_debit_amt = -1;
		short		ind_credit_amt = -1;
		short		ind_baid_name = -1;
		short		ind_remark = -1;
		short		ind_create_user = -1;

		short		hv_return_value;

	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls,"file_id",&csTmp)) {
		hv_file_id.len = strlen(csTmp);
		strncpy((char*)hv_file_id.arr, csTmp, hv_file_id.len);
		ind_file_id = 0;
DEBUGLOG(("AddDetail: file_id = [%.*s]\n",hv_file_id.len, hv_file_id.arr));
	}

	if (GetField_Int(hRls, "seq", &iTmp)) {
		hv_seq = iTmp;
		ind_seq = 0;
DEBUGLOG(("AddDetail: seq = [%d]\n",hv_seq));
	}

	if (GetField_CString(hRls,"txn_id",&csTmp)) {
		hv_txn_id.len = strlen(csTmp);
		strncpy((char*)hv_txn_id.arr, csTmp, hv_txn_id.len);
		ind_txn_id = 0;
DEBUGLOG(("AddDetail: txn_id = [%.*s]\n",hv_txn_id.len, hv_txn_id.arr));
	}

	if (GetField_CString(hRls,"baid",&csTmp)) {
		hv_baid.len = strlen(csTmp);
		strncpy((char*)hv_baid.arr, csTmp, hv_baid.len);
		ind_baid = 0;
DEBUGLOG(("AddDetail: baid = [%.*s]\n",hv_baid.len, hv_baid.arr));
	}

	if (GetField_CString(hRls,"report_date",&csTmp)) {
		hv_report_date.len = strlen(csTmp);
		strncpy((char*)hv_report_date.arr, csTmp, hv_report_date.len);
		ind_report_date = 0;
DEBUGLOG(("AddDetail :report_date = [%.*s]\n",hv_report_date.len, hv_report_date.arr));
	}

	if (GetField_CString(hRls,"ccy",&csTmp)) {
		hv_ccy.len = strlen(csTmp);
		strncpy((char*)hv_ccy.arr, csTmp, hv_ccy.len);
		ind_ccy = 0;
DEBUGLOG(("AddDetail: ccy = [%.*s]\n",hv_ccy.len, hv_ccy.arr));
	}

	if (GetField_CString(hRls,"txn_type",&csTmp)) {
		hv_txn_type.len = strlen(csTmp);
		strncpy((char*)hv_txn_type.arr, csTmp, hv_txn_type.len);
		ind_txn_type = 0;
DEBUGLOG(("AddDetail: txn_type = [%.*s]\n",hv_txn_type.len, hv_txn_type.arr));
	}

	if (GetField_Double(hRls,"debit_amt",&dTmp)) {
		hv_debit_amt = dTmp;
		ind_debit_amt = 0;
DEBUGLOG(("AddDetail: debit_amt = [%.2f]\n",hv_debit_amt));
	}

	if (GetField_Double(hRls,"credit_amt",&dTmp)) {
		hv_credit_amt = dTmp;
		ind_credit_amt = 0;
DEBUGLOG(("AddDetail: credit_amt = [%.2f]\n",hv_credit_amt));
	}

	if (GetField_CString(hRls,"baid_name",&csTmp)) {
		hv_baid_name.len = strlen(csTmp);
		strncpy((char*)hv_baid_name.arr, csTmp, hv_baid_name.len);
		ind_baid_name = 0;
DEBUGLOG(("AddDetail: baid_name = [%.*s]\n",hv_baid_name.len, hv_baid_name.arr));
	}

	if (GetField_CString(hRls,"remark",&csTmp)) {
		hv_remark.len = strlen(csTmp);
		strncpy((char*)hv_remark.arr, csTmp, hv_remark.len);
		ind_remark = 0;
DEBUGLOG(("AddDetail: remark = [%.*s]\n",hv_remark.len, hv_remark.arr));
	}

	if (GetField_CString(hRls,"create_user",&csTmp)) {
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
DEBUGLOG(("AddDetail: create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_pf_txn_init_dt_insert(
						:hv_file_id:ind_file_id,
						:hv_seq:ind_seq,
						:hv_txn_id:ind_txn_id,
						:hv_baid:ind_baid,
						:hv_report_date:ind_report_date,
						:hv_ccy:ind_ccy,
						:hv_txn_type:ind_txn_type,
						:hv_debit_amt:ind_debit_amt,
						:hv_credit_amt:ind_credit_amt,
						:hv_baid_name:ind_baid_name,
						:hv_remark:ind_remark,
						:hv_create_user:ind_create_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_pf_txn_init_dt_insert ( :hv\
_file_id:ind_file_id , :hv_seq:ind_seq , :hv_txn_id:ind_txn_id , :hv_baid:ind\
_baid , :hv_report_date:ind_report_date , :hv_ccy:ind_ccy , :hv_txn_type:ind_\
txn_type , :hv_debit_amt:ind_debit_amt , :hv_credit_amt:ind_credit_amt , :hv_\
baid_name:ind_baid_name , :hv_remark:ind_remark , :hv_create_user:ind_create_\
user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )244;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_file_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_seq;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_seq;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[3] = (unsigned long )18;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_txn_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_baid;
 sqlstm.sqhstl[4] = (unsigned long )22;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_baid;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_report_date;
 sqlstm.sqhstl[5] = (unsigned long )10;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_report_date;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_ccy;
 sqlstm.sqhstl[6] = (unsigned long )5;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_ccy;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_txn_type;
 sqlstm.sqhstl[7] = (unsigned long )52;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_txn_type;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_debit_amt;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_debit_amt;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_credit_amt;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_credit_amt;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_baid_name;
 sqlstm.sqhstl[10] = (unsigned long )102;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_baid_name;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_remark;
 sqlstm.sqhstl[11] = (unsigned long )257;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_remark;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[12] = (unsigned long )22;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_create_user;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto add_detail_error;
}



DEBUGLOG(("AddDetail:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("AddDetail:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLPFTxnInit_AddDetail: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("AddDetail: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLPFTxnInit_AddDetail: SP_ERR TxnAbort\n");
DEBUGLOG(("AddDetail: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

add_detail_error:
DEBUGLOG(("add_detail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPFTxnInit_AddDetail: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int UpdateDetail(const hash_t *hRls)
{
	char	*csTmp;
	char	*csFileId;
	int	iSeq;

	char*	csBuf;
	csBuf = (char *) malloc(128);

        /* EXEC SQL WHENEVER SQLERROR GOTO update_detail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar	hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


        strcpy((char*)hv_dynstmt.arr,"update ol_pf_txn_init_detail set opid_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	if (!GetField_CString(hRls,"file_id",&csFileId)) {
DEBUGLOG(("UpdateDetail: file_id NOT FOUND!!!\n"));
	}

	if (!GetField_Int(hRls,"seq",&iSeq)) {
DEBUGLOG(("UpdateDetail: seq NOT FOUND!!!\n"));
	}

/* update_user */
        if (GetField_CString(hRls,"update_user",&csTmp)) {
DEBUGLOG(("UpdateDetail:update_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",opid_update_user= '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* txn_seq */
        if (GetField_CString(hRls,"txn_seq",&csTmp)) {
DEBUGLOG(("UpdateDetail:txn_seq = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",opid_txn_id= '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* baid */
        if (GetField_CString(hRls,"baid",&csTmp)) {
DEBUGLOG(("UpdateDetail:baid = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",opid_baid= '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        strcat((char *)hv_dynstmt.arr, " WHERE opid_file_id = '");
        strcat((char *)hv_dynstmt.arr, csFileId);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	sprintf(csTmp,"%i",iSeq);
        strcat((char *)hv_dynstmt.arr, " AND opid_seq = ");
        strcat((char *)hv_dynstmt.arr, csTmp);
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )311;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
        sqlstm.sqhstl[0] = (unsigned long )1026;
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
        if (sqlca.sqlcode < 0) goto update_detail_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )330;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_detail_error;
}



	FREE_ME(csBuf);

DEBUGLOG(("UpdateDetail Normal Exit\n"));
        return PD_OK;

update_detail_error:
DEBUGLOG(("update_Detail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLPFTxnInit_UpdateDetail: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("UpdateDetail: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;
}


int AddError(const hash_t *hRls)
{
	char	*csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

		/* varchar		hv_result[PD_REMARK_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_result;

		/* varchar		hv_line[PD_UPLOAD_LINE_LEN]; */ 
struct { unsigned short len; unsigned char arr[511]; } hv_line;

		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_file_id = -1;
		short		ind_result = -1;
		short		ind_line = -1;
		short		ind_create_user = -1;

		short		hv_return_value;

	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls,"file_id",&csTmp)) {
		hv_file_id.len = strlen(csTmp);
		strncpy((char*)hv_file_id.arr, csTmp, hv_file_id.len);
		ind_file_id = 0;
DEBUGLOG(("AddError:file_id = [%.*s]\n",hv_file_id.len, hv_file_id.arr));
	} else {
DEBUGLOG(("AddError:file_id NOT FOUND!!!\n"));
	}

	if (GetField_CString(hRls,"result",&csTmp)) {
		hv_result.len = strlen(csTmp);
		strncpy((char*)hv_result.arr, csTmp, hv_result.len);
		ind_result = 0;
DEBUGLOG(("AddError:result = [%.*s]\n",hv_result.len, hv_result.arr));
	} else {
DEBUGLOG(("AddError:result NOT FOUND!!!\n"));
	}

	if (GetField_CString(hRls,"line",&csTmp)) {
		hv_line.len = strlen(csTmp);
		strncpy((char*)hv_line.arr, csTmp, hv_line.len);
		ind_line = 0;
DEBUGLOG(("AddError:line = [%.*s]\n",hv_line.len, hv_line.arr));
	} else {
DEBUGLOG(("AddError:line NOT FOUND!!!\n"));
	}

	if (GetField_CString(hRls,"create_user",&csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
DEBUGLOG(("AddError:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));
	} else {
DEBUGLOG(("AddError:create_user NOT FOUND!!!\n"));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_pf_txn_init_err_insert(
						:hv_file_id:ind_file_id,
						:hv_result:ind_result,
						:hv_line:ind_line,
						:hv_create_user:ind_create_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_pf_txn_init_err_insert ( :h\
v_file_id:ind_file_id , :hv_result:ind_result , :hv_line:ind_line , :hv_creat\
e_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )345;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_file_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_result;
 sqlstm.sqhstl[2] = (unsigned long )257;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_result;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_line;
 sqlstm.sqhstl[3] = (unsigned long )513;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_line;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[4] = (unsigned long )22;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_create_user;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto add_error_error;
}



DEBUGLOG(("AddError:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("AddError:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLPFTxnInit_AddHeader: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("AddError: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLPFTxnInit_AddHeader: SP_ERR TxnAbort\n");
DEBUGLOG(("AddError: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

add_error_error:
DEBUGLOG(("add_error_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPFTxnInit_AddError: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int MatchHeaderStatusForUpdate(const char *csFileId, const char cStatus)
{
        int iRet = PD_NOT_FOUND;

	/* EXEC SQL WHENEVER SQLERROR GOTO matchheaderstatus_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

		char		hv_status;

		/* varchar		v_user[PD_USER_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_user;

		short		ind_user = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_file_id.len = strlen(csFileId);
	strncpy((char*)hv_file_id.arr,csFileId,hv_file_id.len);
DEBUGLOG(("MatchHeaderStatusForUpdate file_id = [%.*s]\n",hv_file_id.len,hv_file_id.arr));

	hv_status = cStatus;
DEBUGLOG(("MatchHeaderStatusForUpdate status = [%c]\n",hv_status));

	/* EXEC SQL	SELECT	opih_create_user
			INTO	:v_user:ind_user
			FROM	OL_PF_TXN_INIT_HEADER
			WHERE	OPIH_FILE_ID = :hv_file_id
			AND	OPIH_STATUS = :hv_status
			FOR UPDATE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select opih_create_user INTO :b0:b1 FROM OL_PF_TXN_INIT_HEA\
DER WHERE OPIH_FILE_ID = :b2 AND OPIH_STATUS = :b3 FOR UPDATE ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )380;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_user;
 sqlstm.sqhstl[0] = (unsigned long )23;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_user;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[2] = (unsigned long )1;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto matchheaderstatus_error;
}



	if (ind_user>= 0){
DEBUGLOG(("MatchHeaderStatusForUpdate FOUND\n"));
		iRet = PD_FOUND;
	}
	else{
DEBUGLOG(("MatchHeaderStatusForUpdate NOT FOUND\n"));
	}

	return iRet;

matchheaderstatus_error:
DEBUGLOG(("matchheaderstatus_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}
