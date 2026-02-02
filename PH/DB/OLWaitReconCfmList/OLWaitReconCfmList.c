
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
           char  filnam[22];
};
static struct sqlcxp sqlfpn =
{
    21,
    "OLWaitReconCfmList.pc"
};


static unsigned int sqlctx = 164042763;


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
   unsigned char  *sqhstv[7];
   unsigned long  sqhstl[7];
            int   sqhsts[7];
            short *sqindv[7];
            int   sqinds[7];
   unsigned long  sqharm[7];
   unsigned long  *sqharc[7];
   unsigned short  sqadto[7];
   unsigned short  sqtdso[7];
} sqlstm = {12,7};

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
5,0,0,1,296,0,6,101,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,1,
0,0,1,9,0,0,
48,0,0,2,142,0,6,297,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
75,0,0,3,100,0,6,348,0,0,2,2,0,1,0,2,3,0,0,1,9,0,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/02/04              [WCS]
Add DeleteOr                                       2021/02/18              [WCS]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "OLWaitReconCfmList.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


static char cDebug;

void OLWaitReconCfmList(char cdebug)
{
	cDebug = cdebug;
}

int Add(const hash_t *hRls)
{
	char *csTmp;
	char cTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_baid_txn_id_1[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_baid_txn_id_1;

		/* varchar hv_bank_acct_type_1[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_bank_acct_type_1;

		/* varchar hv_baid_txn_id_2[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_baid_txn_id_2;

		/* varchar hv_bank_acct_type_2[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_bank_acct_type_2;

		char hv_recon_type;
		/* varchar hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short ind_baid_txn_id_1 = -1;
		short ind_bank_acct_type_1 = -1;
		short ind_baid_txn_id_2 = -1;
		short ind_bank_acct_type_2 = -1;
		short ind_recon_type = -1;
		short ind_create_user = -1;

		short hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

	if (GetField_CString(hRls, "baid_txn_id_1", &csTmp)) {
		hv_baid_txn_id_1.len = strlen(csTmp);
		strncpy((char*)hv_baid_txn_id_1.arr, csTmp, hv_baid_txn_id_1.len);
		ind_baid_txn_id_1 = 0;
	}
DEBUGLOG(("Add: baid_txn_id_1 = [%.*s]\n", hv_baid_txn_id_1.len, hv_baid_txn_id_1.arr));

	if (GetField_CString(hRls, "bank_acct_type_1", &csTmp)) {
		hv_bank_acct_type_1.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_type_1.arr, csTmp, hv_bank_acct_type_1.len);
		ind_bank_acct_type_1 = 0;
	}
DEBUGLOG(("Add: bank_acct_type_1 = [%.*s]\n", hv_bank_acct_type_1.len, hv_bank_acct_type_1.arr));

	if (GetField_CString(hRls, "baid_txn_id_2", &csTmp)) {
		hv_baid_txn_id_2.len = strlen(csTmp);
		strncpy((char*)hv_baid_txn_id_2.arr, csTmp, hv_baid_txn_id_2.len);
		ind_baid_txn_id_2 = 0;
	}
DEBUGLOG(("Add: baid_txn_id_2 = [%.*s]\n", hv_baid_txn_id_2.len, hv_baid_txn_id_2.arr));

	if (GetField_CString(hRls, "bank_acct_type_2", &csTmp)) {
		hv_bank_acct_type_2.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_type_2.arr, csTmp, hv_bank_acct_type_2.len);
		ind_bank_acct_type_2 = 0;
	}
DEBUGLOG(("Add: bank_acct_type_2 = [%.*s]\n", hv_bank_acct_type_2.len, hv_bank_acct_type_2.arr));

	if (GetField_Char(hRls, "recon_type", &cTmp)) {
		hv_recon_type = cTmp;
		ind_recon_type = 0;
	}
DEBUGLOG(("Add: recon_type = [%c]\n", hv_recon_type));

	if (GetField_CString(hRls, "create_user", &csTmp)) {
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
	}
DEBUGLOG(("Add: create_user = [%.*s]\n", hv_create_user.len, hv_create_user.arr));

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_wait_rec_cfm_list_insert(
						:hv_baid_txn_id_1:ind_baid_txn_id_1,
						:hv_bank_acct_type_1:ind_bank_acct_type_1,
						:hv_baid_txn_id_2:ind_baid_txn_id_2,
						:hv_bank_acct_type_2:ind_bank_acct_type_2,
						:hv_recon_type:ind_recon_type,
						:hv_create_user:ind_create_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_wait_rec_cfm_list_insert ( \
:hv_baid_txn_id_1:ind_baid_txn_id_1 , :hv_bank_acct_type_1:ind_bank_acct_type\
_1 , :hv_baid_txn_id_2:ind_baid_txn_id_2 , :hv_bank_acct_type_2:ind_bank_acct\
_type_2 , :hv_recon_type:ind_recon_type , :hv_create_user:ind_create_user ) ;\
 END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_baid_txn_id_1;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_baid_txn_id_1;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_type_1;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_bank_acct_type_1;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_baid_txn_id_2;
 sqlstm.sqhstl[3] = (unsigned long )18;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_baid_txn_id_2;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_bank_acct_type_2;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_bank_acct_type_2;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_recon_type;
 sqlstm.sqhstl[5] = (unsigned long )1;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_recon_type;
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
 if (sqlca.sqlcode < 0) goto add_error;
}



DEBUGLOG(("Add: Ret = [%d]\n", hv_return_value));
	if (hv_return_value == SP_OK) {
DEBUGLOG(("Add: Normal Exit\n"));
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLWaitReconCfmList_Add: SP_OTHER_ERR\n");
DEBUGLOG(("Add: SP_OTHER_ERR\n"));
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLWaitReconCfmList_Add: SP_ERR\n");
DEBUGLOG(("Add: SP_ERR\n"));
	}

	return PD_OK;

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLWaitReconCfmList_Add: SP_INTERNAL_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

/*
int GetPairByStmtTxnId(const char *csStmtTxnId,
			recordset_t *myRec)
{
	int iCnt = 0;
	hash_t *myHash;

	EXEC SQL WHENEVER SQLERROR GOTO getpairbystmttxnid_error;
	EXEC SQL WHENEVER NOTFOUND CONTINUE;

	EXEC SQL BEGIN DECLARE SECTION;
		varchar hv_baid_txn_id_1[PD_TXN_SEQ_LEN];
		varchar v_merch_txn_id[PD_TXN_SEQ_LEN + 1];

		short ind_baid_txn_id_2 = -1;
	EXEC SQL END DECLARE SECTION;

	hv_baid_txn_id_1.len = strlen(csStmtTxnId);
	memcpy(hv_baid_txn_id_1.arr, csStmtTxnId, hv_baid_txn_id_1.len);
DEBUGLOG(("GetPairByStmtTxnId stmt_txn_id = [%.*s]\n", hv_baid_txn_id_1.len, hv_baid_txn_id_1.arr));

	EXEC SQL DECLARE c_cursor_getpairbystmttxnid CURSOR FOR
		select odmp_merch_txn_id
		from ol_deposit_match_pair
		where odmp_stmt_txn_id = :hv_baid_txn_id_1;

	EXEC SQL OPEN c_cursor_getpairbystmttxnid;
	do {
		EXEC SQL FETCH c_cursor_getpairbystmttxnid
		INTO :v_merch_txn_id:ind_baid_txn_id_2;

		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash, 0);

		if (ind_baid_txn_id_2 >= 0) {
			v_merch_txn_id.arr[v_merch_txn_id.len] = '\0';
			PutField_CString(myHash, "merch_txn_id", (const char *)v_merch_txn_id.arr);
DEBUGLOG(("GetPairByStmtTxnId merch_txn_id = [%s]\n", v_merch_txn_id.arr));
		}

		RecordSet_Add(myRec, myHash);
	}
	while (PD_TRUE);

	EXEC SQL CLOSE c_cursor_getpairbystmttxnid;

DEBUGLOG(("GetPairByStmtTxnId Normal Exit\n"));
	return PD_OK;

getpairbystmttxnid_error:
DEBUGLOG(("getpairbystmttxnid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	EXEC SQL WHENEVER SQLERROR CONTINUE;
	EXEC SQL CLOSE c_cursor_getpairbystmttxnid;
	return PD_ERR;
}

int GetPairByMerchTxnId(const char *csMerchTxnId,
			recordset_t *myRec)
{
	int iCnt = 0;
	hash_t *myHash;

	EXEC SQL WHENEVER SQLERROR GOTO getpairbymerchtxnid_error;
	EXEC SQL WHENEVER NOTFOUND CONTINUE;

	EXEC SQL BEGIN DECLARE SECTION;
		varchar hv_baid_txn_id_2[PD_TXN_SEQ_LEN];
		varchar v_stmt_txn_id[PD_TXN_SEQ_LEN + 1];

		short ind_baid_txn_id_1 = -1;
	EXEC SQL END DECLARE SECTION;

	hv_baid_txn_id_2.len = strlen(csMerchTxnId);
	memcpy(hv_baid_txn_id_2.arr, csMerchTxnId, hv_baid_txn_id_2.len);
DEBUGLOG(("GetPairByMerchTxnId merch_txn_id = [%.*s]\n", hv_baid_txn_id_2.len, hv_baid_txn_id_2.arr));

	EXEC SQL DECLARE c_cursor_getpairbymerchtxnid CURSOR FOR
		select odmp_stmt_txn_id
		from ol_deposit_match_pair
		where odmp_merch_txn_id = :hv_baid_txn_id_2;

	EXEC SQL OPEN c_cursor_getpairbymerchtxnid;
	do {
		EXEC SQL FETCH c_cursor_getpairbymerchtxnid
		INTO :v_stmt_txn_id:ind_baid_txn_id_1;

		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash, 0);

		if (ind_baid_txn_id_1 >= 0) {
			v_stmt_txn_id.arr[v_stmt_txn_id.len] = '\0';
			PutField_CString(myHash, "stmt_txn_id", (const char *)v_stmt_txn_id.arr);
DEBUGLOG(("GetPairByMerchTxnId stmt_txn_id = [%s]\n", v_stmt_txn_id.arr));
		}

		RecordSet_Add(myRec, myHash);
	}
	while (PD_TRUE);

	EXEC SQL CLOSE c_cursor_getpairbymerchtxnid;

DEBUGLOG(("GetPairByMerchTxnId Normal Exit\n"));
	return PD_OK;

getpairbymerchtxnid_error:
DEBUGLOG(("getpairbymerchtxnid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	EXEC SQL WHENEVER SQLERROR CONTINUE;
	EXEC SQL CLOSE c_cursor_getpairbymerchtxnid;
	return PD_ERR;
}
*/

int DeleteSingle(const hash_t *hRls)
{
	char *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO deletesingle_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_baid_txn_id_1[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_baid_txn_id_1;

		/* varchar hv_baid_txn_id_2[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_baid_txn_id_2;


		short ind_baid_txn_id_1 = -1;
		short ind_baid_txn_id_2 = -1;

		short hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("DeleteSingle: Begin\n"));

	if (GetField_CString(hRls, "baid_txn_id_1", &csTmp)) {
		hv_baid_txn_id_1.len = strlen(csTmp);
		strncpy((char*)hv_baid_txn_id_1.arr, csTmp, hv_baid_txn_id_1.len);
		ind_baid_txn_id_1 = 0;
	}
DEBUGLOG(("DeleteSingle: baid_txn_id_1 = [%.*s]\n", hv_baid_txn_id_1.len, hv_baid_txn_id_1.arr));

	if (GetField_CString(hRls, "baid_txn_id_2", &csTmp)) {
		hv_baid_txn_id_2.len = strlen(csTmp);
		strncpy((char*)hv_baid_txn_id_2.arr, csTmp, hv_baid_txn_id_2.len);
		ind_baid_txn_id_2 = 0;
	}
DEBUGLOG(("DeleteSingle: baid_txn_id_2 = [%.*s]\n", hv_baid_txn_id_2.len, hv_baid_txn_id_2.arr));

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_wait_rec_cfm_list_delete(
						:hv_baid_txn_id_1:ind_baid_txn_id_1,
						:hv_baid_txn_id_2:ind_baid_txn_id_2);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_wait_rec_cfm_list_delete ( \
:hv_baid_txn_id_1:ind_baid_txn_id_1 , :hv_baid_txn_id_2:ind_baid_txn_id_2 ) ;\
 END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )48;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_baid_txn_id_1;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_baid_txn_id_1;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_baid_txn_id_2;
 sqlstm.sqhstl[2] = (unsigned long )18;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_baid_txn_id_2;
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
 if (sqlca.sqlcode < 0) goto deletesingle_error;
}



DEBUGLOG(("DeleteSingle: Ret = [%d]\n", hv_return_value));

	if (hv_return_value == SP_OK) {
DEBUGLOG(("DeleteSingle: Done\n"));
	} else {
DEBUGLOG(("DeleteSingle: Not exist\n"));
	}

	return PD_OK;

deletesingle_error:
DEBUGLOG(("deletesingle_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("DeleteSingle: SP_INTERNAL_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int DeleteOr(const hash_t *hRls)
{
	char *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO deleteor_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_baid_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_baid_txn_id;


		short ind_baid_txn_id = -1;

		short hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("DeleteOr: Begin\n"));

	if (GetField_CString(hRls, "baid_txn_id", &csTmp)) {
		hv_baid_txn_id.len = strlen(csTmp);
		strncpy((char*)hv_baid_txn_id.arr, csTmp, hv_baid_txn_id.len);
		ind_baid_txn_id = 0;
	}
DEBUGLOG(("DeleteOr: baid_txn_id = [%.*s]\n", hv_baid_txn_id.len, hv_baid_txn_id.arr));

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_wait_rec_cfm_list_del_or(
						:hv_baid_txn_id:ind_baid_txn_id);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_wait_rec_cfm_list_del_or ( \
:hv_baid_txn_id:ind_baid_txn_id ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )75;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_baid_txn_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_baid_txn_id;
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
 if (sqlca.sqlcode < 0) goto deleteor_error;
}



DEBUGLOG(("DeleteOr: Ret = [%d]\n", hv_return_value));

	if (hv_return_value == SP_OK) {
DEBUGLOG(("DeleteOr: Done\n"));
	} else {
DEBUGLOG(("DeleteOr: Not exist\n"));
	}

	return PD_OK;

deleteor_error:
DEBUGLOG(("deleteor_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("DeleteOr: SP_INTERNAL_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

