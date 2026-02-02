
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
           char  filnam[19];
};
static struct sqlcxp sqlfpn =
{
    18,
    "OLTxnRequestRef.pc"
};


static unsigned int sqlctx = 20810715;


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

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,368,0,6,153,0,0,11,11,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,1,9,0,0,1,1,0,0,1,3,0,0,1,9,0,0,
64,0,0,2,0,0,17,282,0,0,1,1,0,1,0,1,9,0,0,
83,0,0,2,0,0,21,283,0,0,0,0,0,1,0,
98,0,0,3,158,0,6,340,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description						Change Date			 Change By
-------------------------------					------------			--------------
Init Version							2018/11/26			  Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "OLTxnRequestRef.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "internal.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char	cDebug;

void OLTxnRequestRef(char	cdebug)
{
	cDebug = cdebug;
}


int Add(const hash_t *hRec)
{
	int	iCommit = PD_TRUE;

	char	*csTmp;
	char	cTmp;
	int	iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_req_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_req_txn_id;

		/* varchar		hv_channel_code[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel_code;

		/* varchar		hv_req_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_req_txn_code;

		/* varchar		hv_req_txn_ref[PD_MERCHANT_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_req_txn_ref;

		/* varchar		hv_version[PD_OL_KEY_VER_LEN]; */ 
struct { unsigned short len; unsigned char arr[5]; } hv_version;

		/* varchar		hv_t1_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_t1_txn_id;

		/* varchar		hv_t2_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_t2_txn_id;

		char            hv_status;
		int		hv_ret_code;
		/* varchar		hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;


		short		ind_req_txn_id = -1;
		short		ind_channel_code = -1;
		short		ind_req_txn_code = -1;
		short		ind_req_txn_ref = -1;
		short		ind_version = -1;
		short		ind_t1_txn_id = -1;
		short		ind_t2_txn_id = -1;
		short		ind_status= -1;
		short		ind_ret_code= -1;
		short		ind_add_user= -1;
				
		short		hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));
	if (GetField_Int(hRec, "db_commit", &iCommit)) {
DEBUGLOG(("Add:db_commit = [%d]\n", iCommit));
	}

// txn_seq
	if (GetField_CString(hRec, "txn_seq", &csTmp)) {
		hv_req_txn_id.len = strlen(csTmp);
		memcpy(hv_req_txn_id.arr, csTmp, hv_req_txn_id.len);
		ind_req_txn_id = 0;
DEBUGLOG(("Add:req_txn_id = [%.*s]\n", hv_req_txn_id.len, hv_req_txn_id.arr));
	}

//channel
	if(GetField_CString(hRec,"channel_code",&csTmp)) {
		hv_channel_code.len = strlen(csTmp);
		memcpy(hv_channel_code.arr, csTmp, hv_channel_code.len);
		ind_channel_code = 0;
DEBUGLOG(("Add:channel_code= [%.*s]\n", hv_channel_code.len, hv_channel_code.arr));
	}


//txn_code
	if(GetField_CString(hRec,"txn_code",&csTmp)) {
		hv_req_txn_code.len = strlen(csTmp);
		memcpy(hv_req_txn_code.arr, csTmp, hv_req_txn_code.len);
		ind_req_txn_code = 0;
DEBUGLOG(("Add:req_txn_code = [%.*s]\n", hv_req_txn_code.len, hv_req_txn_code.arr));
	}

//req_ref
	if(GetField_CString(hRec,"req_ref",&csTmp)) {
		hv_req_txn_ref.len = strlen(csTmp);
		memcpy(hv_req_txn_ref.arr, csTmp, hv_req_txn_ref.len);
		ind_req_txn_ref = 0;
DEBUGLOG(("Add:req_txn_ref = [%.*s]\n", hv_req_txn_ref.len, hv_req_txn_ref.arr));
	}

//version
	if(GetField_CString(hRec,"version",&csTmp)) {
		hv_version.len = strlen(csTmp);
		memcpy(hv_version.arr, csTmp, hv_version.len);
		ind_version = 0;
DEBUGLOG(("Add:version = [%.*s]\n", hv_version.len, hv_version.arr));
	}

//t1_txn_id
	if (GetField_CString(hRec, "t1_txn_id", &csTmp)) {
		hv_t1_txn_id.len = strlen(csTmp);
		memcpy(hv_t1_txn_id.arr, csTmp, hv_t1_txn_id.len);
		ind_t1_txn_id = 0;
DEBUGLOG(("Add:t1_txn_id = [%.*s]\n", hv_t1_txn_id.len, hv_t1_txn_id.arr));
	}

//t2_txn_id
	if (GetField_CString(hRec, "t2_txn_id", &csTmp)) {
		hv_t2_txn_id.len = strlen(csTmp);
		memcpy(hv_t2_txn_id.arr, csTmp, hv_t2_txn_id.len);
		ind_t2_txn_id = 0;
DEBUGLOG(("Add:t2_txn_id = [%.*s]\n", hv_t2_txn_id.len, hv_t2_txn_id.arr));
	}

//status
	if(GetField_Char(hRec,"status",&cTmp)) {
		hv_status = cTmp;
		ind_status = 0;
DEBUGLOG(("Add:status= [%.c]\n",hv_status));
	}

//ret_code
	if(GetField_Int(hRec,"ret_code",&iTmp)) {
		hv_ret_code = iTmp;
		ind_ret_code= 0;
DEBUGLOG(("Add:ret_code= [%d]\n",hv_ret_code));
	}

//user
	if(GetField_CString(hRec,"add_user",&csTmp)) {
		hv_add_user.len = strlen(csTmp);
		memcpy(hv_add_user.arr, csTmp, hv_add_user.len);
		ind_add_user = 0;
DEBUGLOG(("Add:add_user= [%.*s]\n", hv_add_user.len, hv_add_user.arr));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_txn_request_ref_insert (
						:hv_req_txn_id:ind_req_txn_id,
						:hv_channel_code:ind_channel_code,
						:hv_req_txn_code:ind_req_txn_code,
						:hv_req_txn_ref:ind_req_txn_ref,
						:hv_version:ind_version,
						:hv_t1_txn_id:ind_t1_txn_id,
						:hv_t2_txn_id:ind_t2_txn_id,
						:hv_status:ind_status,
						:hv_ret_code:ind_ret_code,
						:hv_add_user:ind_add_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_txn_request_ref_insert ( :h\
v_req_txn_id:ind_req_txn_id , :hv_channel_code:ind_channel_code , :hv_req_txn\
_code:ind_req_txn_code , :hv_req_txn_ref:ind_req_txn_ref , :hv_version:ind_ve\
rsion , :hv_t1_txn_id:ind_t1_txn_id , :hv_t2_txn_id:ind_t2_txn_id , :hv_statu\
s:ind_status , :hv_ret_code:ind_ret_code , :hv_add_user:ind_add_user ) ; END \
;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_req_txn_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_req_txn_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_channel_code;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_channel_code;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_req_txn_code;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_req_txn_code;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_req_txn_ref;
 sqlstm.sqhstl[4] = (unsigned long )52;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_req_txn_ref;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_version;
 sqlstm.sqhstl[5] = (unsigned long )7;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_version;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_t1_txn_id;
 sqlstm.sqhstl[6] = (unsigned long )18;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_t1_txn_id;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_t2_txn_id;
 sqlstm.sqhstl[7] = (unsigned long )18;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_t2_txn_id;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[8] = (unsigned long )1;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_status;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_ret_code;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_ret_code;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_add_user;
 sqlstm.sqhstl[10] = (unsigned long )22;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_add_user;
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
 if (sqlca.sqlcode < 0) goto add_error;
}


				
DEBUGLOG(("Add:Ret = [%d]\n", hv_return_value));
	if (hv_return_value == SP_OK) {
DEBUGLOG(("Add:Normal Exit\n"));
		if (iCommit == PD_TRUE) {
			TxnCommit();
		}
		return PD_OK;
	}
				
	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("OLTxnRequestRef_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("OLTxnRequestRef_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLTxnRequestRef_Add: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
	return PD_ERR;
}


int Update(const hash_t *hRec)
{
	char*	csBuf;
	char*	csTxnId;
	char	cTmp;
	int	iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar		 hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("Update: Begin\n"));
	csBuf = (char*) malloc (128);
	strcpy((char*)hv_dynstmt.arr,"update ol_txn_request_ref set otrr_update_timestamp = sysdate");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	if (GetField_CString(hRec,"txn_seq", &csTxnId)) {
DEBUGLOG(("Update:txn_seq = [%s]\n", csTxnId));
	}
	else{
		FREE_ME(csBuf);
DEBUGLOG(("Update batch_id not found\n"));
		return INT_ERR;
	}

	if (GetField_CString(hRec, "t1_txn_id", &csBuf)) {
DEBUGLOG(("Update: t1_txn_id = [%s]\n", csBuf));
		strcat((char*)hv_dynstmt.arr, ",otrr_t1_txn_id = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	if (GetField_CString(hRec, "t2_txn_id", &csBuf)) {
DEBUGLOG(("Update: t2_txn_id = [%s]\n", csBuf));
		strcat((char*)hv_dynstmt.arr, ",otrr_t2_txn_id = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	if (GetField_Char(hRec, "status", &cTmp)) {
DEBUGLOG(("Update: status = [%c]\n", cTmp));
		sprintf(csBuf, "%c", cTmp);
		strcat((char*)hv_dynstmt.arr, ", otrr_status = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	if (GetField_Int(hRec, "ret_code", &iTmp)) {
DEBUGLOG(("Update: return_code = [%d]\n",iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", otrr_ret_code = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	if (GetField_CString(hRec, "update_user", &csBuf)) {
DEBUGLOG(("Update: update_user = [%s]\n", csBuf));
		strcat((char*)hv_dynstmt.arr, ", otrr_update_user = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	strcat((char*)hv_dynstmt.arr, " WHERE otrr_req_txn_id = '");
	strcat((char*)hv_dynstmt.arr, csTxnId); 
	strcat((char*)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));


	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )64;
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
 if (sqlca.sqlcode < 0) goto update_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )83;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto update_error;
}



	FREE_ME(csBuf);

DEBUGLOG(("UpdateStatus Normal Exit\n"));
	return PD_OK;

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLTxnRequestRef_Update: SP_INTERNAL_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_INTERNAL_ERR;
}

int	MatchRequestRef(const hash_t *hRec)
{
	char	*csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO matchrequestref_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

    
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		short           hv_return_value;

		/* varchar         hv_channel_code[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel_code;

		/* varchar         hv_request_ref[PD_MERCHANT_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_request_ref;

		/* varchar		hv_txn_seq[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_seq;


		short		ind_channel_code = -1;
		short		ind_request_ref = -1;
		short		ind_txn_seq = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRec,"channel_code", &csTmp)) {
		hv_channel_code.len = strlen(csTmp);
		memcpy(hv_channel_code.arr, csTmp, hv_channel_code.len);
		ind_channel_code = 0;
DEBUGLOG(("MatchRequestRef:channel_code= [%.*s]\n", hv_channel_code.len, hv_channel_code.arr));
	}

	if (GetField_CString(hRec,"req_ref", &csTmp)) {
		hv_request_ref.len = strlen(csTmp);
		memcpy(hv_request_ref.arr, csTmp, hv_request_ref.len);
		ind_request_ref = 0;
DEBUGLOG(("MatchRequestRef:request_ref = [%.*s]\n", hv_request_ref.len, hv_request_ref.arr));
	}

	if (GetField_CString(hRec,"txn_seq", &csTmp)) {
		hv_txn_seq.len = strlen(csTmp);
		memcpy(hv_txn_seq.arr, csTmp, hv_txn_seq.len);
		ind_txn_seq = 0;
DEBUGLOG(("MatchRequestRef:txn_seq = [%.*s]\n", hv_txn_seq.len, hv_txn_seq.arr));
	}


	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_txn_request_matchreq(
							:hv_channel_code:ind_channel_code,
							:hv_request_ref:ind_request_ref,
							:hv_txn_seq:ind_txn_seq);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_txn_request_matchreq ( :hv_\
channel_code:ind_channel_code , :hv_request_ref:ind_request_ref , :hv_txn_seq\
:ind_txn_seq ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )98;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_channel_code;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_channel_code;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_request_ref;
 sqlstm.sqhstl[2] = (unsigned long )52;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_request_ref;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_seq;
 sqlstm.sqhstl[3] = (unsigned long )18;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_txn_seq;
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
 if (sqlca.sqlcode < 0) goto matchrequestref_error;
}




	if (hv_return_value > 0)  {
DEBUGLOG(("MatchRequestRef Found\n"));
		return FOUND;
	}
	else {
DEBUGLOG(("MatchRequestRef Not Found\n"));
		return NOT_FOUND;
	}


matchrequestref_error:
DEBUGLOG(("matchrequestref_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

							
}


