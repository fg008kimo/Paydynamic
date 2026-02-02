
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
    "DepositMismatch.pc"
};


static unsigned int sqlctx = 18657867;


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
   unsigned char  *sqhstv[9];
   unsigned long  sqhstl[9];
            int   sqhsts[9];
            short *sqindv[9];
            int   sqinds[9];
   unsigned long  sqharm[9];
   unsigned long  *sqharc[9];
   unsigned short  sqadto[9];
   unsigned short  sqtdso[9];
} sqlstm = {12,9};

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

 static char *sq0006 = 
"select dm_absent from deposit_mismatch where dm_txn_id = :b0 and dm_party_t\
ype = :b1            ";

 static char *sq0007 = 
"select dm_absent from deposit_mismatch where dm_merchant_ref = :b0 and dm_p\
arty_type = :b1            ";

 static char *sq0008 = 
"select dm_absent from deposit_mismatch where dm_psp_tid = :b0 and dm_party_\
type = :b1            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,282,0,6,116,0,0,9,9,0,1,0,2,3,0,0,1,9,0,0,1,1,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,1,9,0,0,1,9,0,0,1,9,0,0,
56,0,0,2,109,0,6,201,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,1,0,0,1,9,0,0,
87,0,0,3,119,0,6,212,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,1,0,0,1,9,0,0,
118,0,0,4,114,0,6,289,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,1,0,0,1,9,0,0,
149,0,0,5,119,0,6,300,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,1,0,0,1,9,0,0,
180,0,0,6,96,0,9,377,0,2049,2,2,0,1,0,1,9,0,0,1,1,0,0,
203,0,0,6,0,0,13,379,0,0,1,0,0,1,0,2,9,0,0,
222,0,0,6,0,0,15,400,0,0,0,0,0,1,0,
237,0,0,7,102,0,9,415,0,2049,2,2,0,1,0,1,9,0,0,1,1,0,0,
260,0,0,7,0,0,13,417,0,0,1,0,0,1,0,2,9,0,0,
279,0,0,7,0,0,15,438,0,0,0,0,0,1,0,
294,0,0,6,0,0,15,449,0,0,0,0,0,1,0,
309,0,0,8,97,0,9,487,0,2049,2,2,0,1,0,1,9,0,0,1,1,0,0,
332,0,0,8,0,0,13,489,0,0,1,0,0,1,0,2,9,0,0,
351,0,0,8,0,0,15,510,0,0,0,0,0,1,0,
366,0,0,7,102,0,9,525,0,2049,2,2,0,1,0,1,9,0,0,1,1,0,0,
389,0,0,7,0,0,13,527,0,0,1,0,0,1,0,2,9,0,0,
408,0,0,7,0,0,15,548,0,0,0,0,0,1,0,
423,0,0,8,0,0,15,559,0,0,0,0,0,1,0,
438,0,0,7,0,0,15,560,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/04/26              LokMan Chow
Add GetDspMismatchByTid and MarkDeletedByTid	   2016/02/24		   Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "DepositMismatch.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define	PD_ABS_LEN  8

char    cDebug;

void DepositMismatch(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const char* csTxnId,
	const char cPartyType,
	const char* csPartyId,
	const char* csTid,
	const char* csDate,
	const char* csAbs)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		char		hv_party_type;
		/* varchar		hv_party_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_party_id;

		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		/* varchar		hv_tid[PD_PSP_TID_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_tid;

		/* varchar		hv_merchant_ref[PD_MERCHANT_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_merchant_ref;

		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;

		/* varchar		hv_txn_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_txn_date;

		/* varchar		hv_absent[PD_ABS_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_absent;



		short		ind_party_type = -1;
		short		ind_party_id = -1;
		short		ind_txn_id = -1;
		short		ind_tid = -1;
		short		ind_merchant_ref = -1;
		short		ind_create_user = -1;
		short		ind_txn_date = -1;
		short		ind_absent = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



	DEBUGLOG(("Add: Begin\n"));

	hv_party_type = cPartyType;
	ind_party_type = 0;
DEBUGLOG(("Add:party_type = [%c]\n",hv_party_type));

	hv_party_id.len = strlen(csPartyId);
	strncpy((char *)hv_party_id.arr, csPartyId, hv_party_id.len);
	ind_party_id = 0;
DEBUGLOG(("Add:party_id = [%.*s]\n",hv_party_id.len,hv_party_id.arr));

	hv_txn_id.len = strlen(csTxnId);
	strncpy((char *)hv_txn_id.arr, csTxnId, hv_txn_id.len);
	ind_txn_id = 0;
DEBUGLOG(("Add:txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

	if(cPartyType==PD_TYPE_PSP){
		if(strlen(csTid)){
			hv_tid.len = strlen(csTid);
			strncpy((char *)hv_tid.arr, csTid, hv_tid.len);
			ind_tid = 0;
DEBUGLOG(("Add:tid = [%.*s]\n",hv_tid.len,hv_tid.arr));
		}
	}
	else if(cPartyType==PD_TYPE_MERCHANT){
		if(strlen(csTid)){
                        hv_merchant_ref.len = strlen(csTid);
                        strncpy((char *)hv_merchant_ref.arr, csTid, hv_merchant_ref.len);
                        ind_merchant_ref = 0;
DEBUGLOG(("Add:merchant_ref = [%.*s]\n",hv_merchant_ref.len,hv_merchant_ref.arr));
                }
	}

	hv_create_user.len = strlen(PD_UPDATE_USER);
	strncpy((char *)hv_create_user.arr, PD_UPDATE_USER, hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));

	hv_txn_date.len = strlen(csDate);
	strncpy((char *)hv_txn_date.arr, csDate,hv_txn_date.len);
	ind_txn_date= 0;
DEBUGLOG(("Add:txn_date = [%.*s]\n",hv_txn_date.len,hv_txn_date.arr));

	hv_absent.len = strlen(csAbs);
	strncpy((char *)hv_absent.arr, csAbs, hv_absent.len);
	ind_absent= 0;
DEBUGLOG(("Add:absent = [%.*s]\n",hv_absent.len,hv_absent.arr));


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_dsp_mismatch_insert(
				:hv_txn_id:ind_txn_id,
				:hv_party_type:ind_party_type,
				:hv_party_id:ind_party_id,
				:hv_tid:ind_tid,
				:hv_merchant_ref:ind_merchant_ref,
				:hv_txn_date:ind_txn_date,
				:hv_absent:ind_absent,
				:hv_create_user:ind_create_user);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_dsp_mismatch_insert ( :hv_txn_\
id:ind_txn_id , :hv_party_type:ind_party_type , :hv_party_id:ind_party_id , :\
hv_tid:ind_tid , :hv_merchant_ref:ind_merchant_ref , :hv_txn_date:ind_txn_dat\
e , :hv_absent:ind_absent , :hv_create_user:ind_create_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_txn_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_party_type;
 sqlstm.sqhstl[2] = (unsigned long )1;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_party_type;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_party_id;
 sqlstm.sqhstl[3] = (unsigned long )17;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_party_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_tid;
 sqlstm.sqhstl[4] = (unsigned long )52;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_tid;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_merchant_ref;
 sqlstm.sqhstl[5] = (unsigned long )52;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_merchant_ref;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_txn_date;
 sqlstm.sqhstl[6] = (unsigned long )10;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_txn_date;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_absent;
 sqlstm.sqhstl[7] = (unsigned long )10;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_absent;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[8] = (unsigned long )22;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto add_error;
}




	DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("Add:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("DepositMismatch_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("DepositMismatch_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("DepositMismatch_Add: SP_INTERNAL_ERR TxnAbort\n");
	TxnAbort();
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;


}



int MarkDeleted(const unsigned char* csTxnId, const char cPartyType, const unsigned char* csMatchDate)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO delete_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		/* varchar hv_merchant_ref[PD_MERCHANT_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_merchant_ref;

		/* varchar hv_match_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_match_date;

		char	hv_party_type;

		short	hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_party_type = cPartyType;
DEBUGLOG(("MarkDeleted: party_type = [%c]\n",hv_party_type));

	if(cPartyType == PD_TYPE_PSP){
		hv_txn_id.len = strlen((const char*)csTxnId);
		memcpy(hv_txn_id.arr,csTxnId,hv_txn_id.len);
DEBUGLOG(("MarkDeleted: txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
	}
	else if(cPartyType == PD_TYPE_MERCHANT){
		hv_merchant_ref.len = strlen((const char*)csTxnId);
		memcpy(hv_merchant_ref.arr,csTxnId,hv_merchant_ref.len);
DEBUGLOG(("MarkDeleted: merchant_ref = [%.*s]\n",hv_merchant_ref.len,hv_merchant_ref.arr));
	}

	hv_match_date.len = strlen((const char*)csMatchDate);
	memcpy(hv_match_date.arr,csMatchDate,hv_match_date.len);
DEBUGLOG(("MarkDeleted: match_date = [%.*s]\n",hv_match_date.len,hv_match_date.arr));


	if(cPartyType == PD_TYPE_PSP){
	    /* EXEC SQL EXECUTE
		BEGIN
		
		:hv_return_value := sp_dsp_mismatch_markdelete(
				:hv_txn_id,
				:hv_party_type,
				:hv_match_date);
		END;
	    END-EXEC; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 9;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = "begin :hv_return_value := sp_dsp_mismatch_markdelete ( \
:hv_txn_id , :hv_party_type , :hv_match_date ) ; END ;";
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )56;
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
     sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_id;
     sqlstm.sqhstl[1] = (unsigned long )18;
     sqlstm.sqhsts[1] = (         int  )0;
     sqlstm.sqindv[1] = (         short *)0;
     sqlstm.sqinds[1] = (         int  )0;
     sqlstm.sqharm[1] = (unsigned long )0;
     sqlstm.sqadto[1] = (unsigned short )0;
     sqlstm.sqtdso[1] = (unsigned short )0;
     sqlstm.sqhstv[2] = (unsigned char  *)&hv_party_type;
     sqlstm.sqhstl[2] = (unsigned long )1;
     sqlstm.sqhsts[2] = (         int  )0;
     sqlstm.sqindv[2] = (         short *)0;
     sqlstm.sqinds[2] = (         int  )0;
     sqlstm.sqharm[2] = (unsigned long )0;
     sqlstm.sqadto[2] = (unsigned short )0;
     sqlstm.sqtdso[2] = (unsigned short )0;
     sqlstm.sqhstv[3] = (unsigned char  *)&hv_match_date;
     sqlstm.sqhstl[3] = (unsigned long )10;
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
     if (sqlca.sqlcode < 0) goto delete_error;
}


	}
	else if(cPartyType == PD_TYPE_MERCHANT){
	    /* EXEC SQL EXECUTE
		BEGIN
		
		:hv_return_value := sp_dsp_mismatch_markdelete_ref(
				:hv_merchant_ref,
				:hv_party_type,
				:hv_match_date);
		END;
	    END-EXEC; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 9;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = "begin :hv_return_value := sp_dsp_mismatch_markdelete_re\
f ( :hv_merchant_ref , :hv_party_type , :hv_match_date ) ; END ;";
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )87;
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
     sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_ref;
     sqlstm.sqhstl[1] = (unsigned long )52;
     sqlstm.sqhsts[1] = (         int  )0;
     sqlstm.sqindv[1] = (         short *)0;
     sqlstm.sqinds[1] = (         int  )0;
     sqlstm.sqharm[1] = (unsigned long )0;
     sqlstm.sqadto[1] = (unsigned short )0;
     sqlstm.sqtdso[1] = (unsigned short )0;
     sqlstm.sqhstv[2] = (unsigned char  *)&hv_party_type;
     sqlstm.sqhstl[2] = (unsigned long )1;
     sqlstm.sqhsts[2] = (         int  )0;
     sqlstm.sqindv[2] = (         short *)0;
     sqlstm.sqinds[2] = (         int  )0;
     sqlstm.sqharm[2] = (unsigned long )0;
     sqlstm.sqadto[2] = (unsigned short )0;
     sqlstm.sqtdso[2] = (unsigned short )0;
     sqlstm.sqhstv[3] = (unsigned char  *)&hv_match_date;
     sqlstm.sqhstl[3] = (unsigned long )10;
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
     if (sqlca.sqlcode < 0) goto delete_error;
}


	}


DEBUGLOG(("MarkDeleted:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("MarkDeleted:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("DepositMismatch_Delete: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Delete: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("DepositMismatch_MarkDeleted: SP_ERR TxnAbort\n");
DEBUGLOG(("MarkDeleted: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

delete_error:
DEBUGLOG(("delete_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("DepositMismatch_MarkDeleted: SP_INTERNAL_ERR TxnAbort\n");
	TxnAbort();
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;

}

int MarkDeletedByTid(const unsigned char* csPspTid, const char cPartyType, const unsigned char* csMatchDate)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO deletebytid_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_psp_tid[PD_PSP_TID_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_psp_tid;

		/* varchar hv_merchant_ref[PD_MERCHANT_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_merchant_ref;

		/* varchar hv_match_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_match_date;

		char	hv_party_type;

		short	hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_party_type = cPartyType;
DEBUGLOG(("MarkDeletedByTid: party_type = [%c]\n",hv_party_type));

	if(cPartyType == PD_TYPE_PSP){
		hv_psp_tid.len = strlen((const char*)csPspTid);
		memcpy(hv_psp_tid.arr,csPspTid,hv_psp_tid.len);
DEBUGLOG(("MarkDeletedByTid: psp_tid = [%.*s]\n",hv_psp_tid.len,hv_psp_tid.arr));
	}
	else if(cPartyType == PD_TYPE_MERCHANT){
		hv_merchant_ref.len = strlen((const char*)csPspTid);
		memcpy(hv_merchant_ref.arr,csPspTid,hv_merchant_ref.len);
DEBUGLOG(("MarkDeletedByTid: merchant_ref = [%.*s]\n",hv_merchant_ref.len,hv_merchant_ref.arr));
	}

	hv_match_date.len = strlen((const char*)csMatchDate);
	memcpy(hv_match_date.arr,csMatchDate,hv_match_date.len);
DEBUGLOG(("MarkDeletedByTid: match_date = [%.*s]\n",hv_match_date.len,hv_match_date.arr));


	if(cPartyType == PD_TYPE_PSP){
	    /* EXEC SQL EXECUTE
		BEGIN
		
		:hv_return_value := sp_dsp_mismatch_markdelete_tid(
				:hv_psp_tid,
				:hv_party_type,
				:hv_match_date);
		END;
	    END-EXEC; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 9;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = "begin :hv_return_value := sp_dsp_mismatch_markdelete_ti\
d ( :hv_psp_tid , :hv_party_type , :hv_match_date ) ; END ;";
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )118;
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
     sqlstm.sqhstv[1] = (unsigned char  *)&hv_psp_tid;
     sqlstm.sqhstl[1] = (unsigned long )52;
     sqlstm.sqhsts[1] = (         int  )0;
     sqlstm.sqindv[1] = (         short *)0;
     sqlstm.sqinds[1] = (         int  )0;
     sqlstm.sqharm[1] = (unsigned long )0;
     sqlstm.sqadto[1] = (unsigned short )0;
     sqlstm.sqtdso[1] = (unsigned short )0;
     sqlstm.sqhstv[2] = (unsigned char  *)&hv_party_type;
     sqlstm.sqhstl[2] = (unsigned long )1;
     sqlstm.sqhsts[2] = (         int  )0;
     sqlstm.sqindv[2] = (         short *)0;
     sqlstm.sqinds[2] = (         int  )0;
     sqlstm.sqharm[2] = (unsigned long )0;
     sqlstm.sqadto[2] = (unsigned short )0;
     sqlstm.sqtdso[2] = (unsigned short )0;
     sqlstm.sqhstv[3] = (unsigned char  *)&hv_match_date;
     sqlstm.sqhstl[3] = (unsigned long )10;
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
     if (sqlca.sqlcode < 0) goto deletebytid_error;
}


	}
	else if(cPartyType == PD_TYPE_MERCHANT){
	    /* EXEC SQL EXECUTE
		BEGIN
		
		:hv_return_value := sp_dsp_mismatch_markdelete_ref(
				:hv_merchant_ref,
				:hv_party_type,
				:hv_match_date);
		END;
	    END-EXEC; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 9;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = "begin :hv_return_value := sp_dsp_mismatch_markdelete_re\
f ( :hv_merchant_ref , :hv_party_type , :hv_match_date ) ; END ;";
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )149;
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
     sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_ref;
     sqlstm.sqhstl[1] = (unsigned long )52;
     sqlstm.sqhsts[1] = (         int  )0;
     sqlstm.sqindv[1] = (         short *)0;
     sqlstm.sqinds[1] = (         int  )0;
     sqlstm.sqharm[1] = (unsigned long )0;
     sqlstm.sqadto[1] = (unsigned short )0;
     sqlstm.sqtdso[1] = (unsigned short )0;
     sqlstm.sqhstv[2] = (unsigned char  *)&hv_party_type;
     sqlstm.sqhstl[2] = (unsigned long )1;
     sqlstm.sqhsts[2] = (         int  )0;
     sqlstm.sqindv[2] = (         short *)0;
     sqlstm.sqinds[2] = (         int  )0;
     sqlstm.sqharm[2] = (unsigned long )0;
     sqlstm.sqadto[2] = (unsigned short )0;
     sqlstm.sqtdso[2] = (unsigned short )0;
     sqlstm.sqhstv[3] = (unsigned char  *)&hv_match_date;
     sqlstm.sqhstl[3] = (unsigned long )10;
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
     if (sqlca.sqlcode < 0) goto deletebytid_error;
}


	}


DEBUGLOG(("MarkDeletedByTid:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("MarkDeletedByTid:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("DepositMismatch_MarkDeletedByTid: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("MarkDeletedByTid: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("DepositMismatch_MarkDeletedByTid: SP_ERR TxnAbort\n");
DEBUGLOG(("MarkDeletedByTid: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

deletebytid_error:
DEBUGLOG(("deletebytid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("DepositMismatch_MarkDeletedByTid: SP_INTERNAL_ERR TxnAbort\n");
	TxnAbort();
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;

}

int GetDspMismatch(const char* csTxnId,const char cPartyType, char* csAbs)
{
	int iRet = PD_NOT_FOUND;

        /* EXEC SQL WHENEVER SQLERROR GOTO getdspmismatch_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

                /* varchar         hv_merchant_ref[PD_MERCHANT_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_merchant_ref;

		char		hv_party_type;

                /* varchar         v_absent[PD_ABS_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_absent;


		short		ind_absent = -1;


        /* EXEC SQL END DECLARE SECTION; */ 


	hv_party_type = cPartyType;
DEBUGLOG(("GetDspMismatch: party_type = [%c]\n",hv_party_type));

	if(cPartyType == PD_TYPE_PSP){
       		hv_txn_id.len = strlen(csTxnId);
        	memcpy(hv_txn_id.arr,csTxnId,hv_txn_id.len);
DEBUGLOG(("GetDspMismatch txn_id = [%d][%.*s]\n",hv_txn_id.len,hv_txn_id.len,hv_txn_id.arr));

        	/* EXEC SQL DECLARE c_cursor_getdspmismatch CURSOR FOR
                select 
			dm_absent
		from deposit_mismatch 
		where dm_txn_id = :hv_txn_id
		and   dm_party_type = :hv_party_type; */ 


        	/* EXEC SQL OPEN c_cursor_getdspmismatch; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 9;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.stmt = sq0006;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )180;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqcmod = (unsigned int )0;
         sqlstm.sqhstv[0] = (unsigned char  *)&hv_txn_id;
         sqlstm.sqhstl[0] = (unsigned long )18;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)0;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&hv_party_type;
         sqlstm.sqhstl[1] = (unsigned long )1;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)0;
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
         if (sqlca.sqlcode < 0) goto getdspmismatch_error;
}


        	do {
                	/* EXEC SQL FETCH c_cursor_getdspmismatch
                	INTO
				:v_absent:ind_absent; */ 

{
                 struct sqlexd sqlstm;
                 sqlstm.sqlvsn = 12;
                 sqlstm.arrsiz = 9;
                 sqlstm.sqladtp = &sqladt;
                 sqlstm.sqltdsp = &sqltds;
                 sqlstm.iters = (unsigned int  )1;
                 sqlstm.offset = (unsigned int  )203;
                 sqlstm.selerr = (unsigned short)1;
                 sqlstm.cud = sqlcud0;
                 sqlstm.sqlest = (unsigned char  *)&sqlca;
                 sqlstm.sqlety = (unsigned short)4352;
                 sqlstm.occurs = (unsigned int  )0;
                 sqlstm.sqfoff = (         int )0;
                 sqlstm.sqfmod = (unsigned int )2;
                 sqlstm.sqhstv[0] = (unsigned char  *)&v_absent;
                 sqlstm.sqhstl[0] = (unsigned long )11;
                 sqlstm.sqhsts[0] = (         int  )0;
                 sqlstm.sqindv[0] = (         short *)&ind_absent;
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
                 if (sqlca.sqlcode < 0) goto getdspmismatch_error;
}



                	if (SQLCODE == SQL_NOT_FOUND) {
                        	break;
                	}


/* absent */
                	if (ind_absent >= 0) {
                        	v_absent.arr[v_absent.len] = '\0';
				strcpy(csAbs,(const char *)v_absent.arr);
DEBUGLOG(("GetDspMismatch absent = [%s]\n",csAbs));
                	}

			iRet = PD_FOUND;

        	}
        	while(PD_TRUE);

        	/* EXEC SQL CLOSE c_cursor_getdspmismatch; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 9;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )222;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
         if (sqlca.sqlcode < 0) goto getdspmismatch_error;
}



	}
	else if(cPartyType == PD_TYPE_MERCHANT){
       		hv_merchant_ref.len = strlen(csTxnId);
        	memcpy(hv_merchant_ref.arr,csTxnId,hv_merchant_ref.len);
DEBUGLOG(("GetDspMismatch merchant_ref = [%d][%.*s]\n",hv_merchant_ref.len,hv_merchant_ref.len,hv_merchant_ref.arr));

        	/* EXEC SQL DECLARE c_cursor_getdspmismatch_ref CURSOR FOR
                select 
			dm_absent
		from deposit_mismatch 
		where dm_merchant_ref = :hv_merchant_ref
		and   dm_party_type = :hv_party_type; */ 


        	/* EXEC SQL OPEN c_cursor_getdspmismatch_ref; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 9;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.stmt = sq0007;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )237;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqcmod = (unsigned int )0;
         sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_ref;
         sqlstm.sqhstl[0] = (unsigned long )52;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)0;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&hv_party_type;
         sqlstm.sqhstl[1] = (unsigned long )1;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)0;
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
         if (sqlca.sqlcode < 0) goto getdspmismatch_error;
}


        	do {
                	/* EXEC SQL FETCH c_cursor_getdspmismatch_ref
                	INTO
				:v_absent:ind_absent; */ 

{
                 struct sqlexd sqlstm;
                 sqlstm.sqlvsn = 12;
                 sqlstm.arrsiz = 9;
                 sqlstm.sqladtp = &sqladt;
                 sqlstm.sqltdsp = &sqltds;
                 sqlstm.iters = (unsigned int  )1;
                 sqlstm.offset = (unsigned int  )260;
                 sqlstm.selerr = (unsigned short)1;
                 sqlstm.cud = sqlcud0;
                 sqlstm.sqlest = (unsigned char  *)&sqlca;
                 sqlstm.sqlety = (unsigned short)4352;
                 sqlstm.occurs = (unsigned int  )0;
                 sqlstm.sqfoff = (         int )0;
                 sqlstm.sqfmod = (unsigned int )2;
                 sqlstm.sqhstv[0] = (unsigned char  *)&v_absent;
                 sqlstm.sqhstl[0] = (unsigned long )11;
                 sqlstm.sqhsts[0] = (         int  )0;
                 sqlstm.sqindv[0] = (         short *)&ind_absent;
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
                 if (sqlca.sqlcode < 0) goto getdspmismatch_error;
}



                	if (SQLCODE == SQL_NOT_FOUND) {
                        	break;
                	}


/* absent */
                	if (ind_absent >= 0) {
                        	v_absent.arr[v_absent.len] = '\0';
				strcpy(csAbs,(const char *)v_absent.arr);
DEBUGLOG(("GetDspMismatch absent = [%s]\n",csAbs));
                	}

			iRet = PD_FOUND;

        	}
        	while(PD_TRUE);

        	/* EXEC SQL CLOSE c_cursor_getdspmismatch_ref; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 9;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )279;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
         if (sqlca.sqlcode < 0) goto getdspmismatch_error;
}


	}

DEBUGLOG(("GetDspMismatch Normal Exit\n"));
        return  iRet;

getdspmismatch_error:
DEBUGLOG(("getdspmismatch_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("DepositMismatch_Get: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getdspmismatch; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )294;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int GetDspMismatchByTid(const char* csPspTid,const char cPartyType, char* csAbs)
{
	int iRet = PD_NOT_FOUND;

        /* EXEC SQL WHENEVER SQLERROR GOTO getdspmismatchbytid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_psp_tid[PD_PSP_TID_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_psp_tid;

                /* varchar         hv_merchant_ref[PD_MERCHANT_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_merchant_ref;

		char		hv_party_type;

                /* varchar         v_absent[PD_ABS_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_absent;


		short		ind_absent = -1;


        /* EXEC SQL END DECLARE SECTION; */ 


	hv_party_type = cPartyType;
DEBUGLOG(("GetDspMismatchByTid: party_type = [%c]\n",hv_party_type));

	if(cPartyType == PD_TYPE_PSP){
       		hv_psp_tid.len = strlen(csPspTid);
        	memcpy(hv_psp_tid.arr,csPspTid,hv_psp_tid.len);
DEBUGLOG(("GetDspMismatchByTid psp_tid = [%d][%.*s]\n",hv_psp_tid.len,hv_psp_tid.len,hv_psp_tid.arr));

        	/* EXEC SQL DECLARE c_cursor_getdspmismatch_tid CURSOR FOR
                select 
			dm_absent
		from deposit_mismatch 
		where dm_psp_tid = :hv_psp_tid
		and   dm_party_type = :hv_party_type; */ 


        	/* EXEC SQL OPEN c_cursor_getdspmismatch_tid; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 9;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.stmt = sq0008;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )309;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqcmod = (unsigned int )0;
         sqlstm.sqhstv[0] = (unsigned char  *)&hv_psp_tid;
         sqlstm.sqhstl[0] = (unsigned long )52;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)0;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&hv_party_type;
         sqlstm.sqhstl[1] = (unsigned long )1;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)0;
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
         if (sqlca.sqlcode < 0) goto getdspmismatchbytid_error;
}


        	do {
                	/* EXEC SQL FETCH c_cursor_getdspmismatch_tid
                	INTO
				:v_absent:ind_absent; */ 

{
                 struct sqlexd sqlstm;
                 sqlstm.sqlvsn = 12;
                 sqlstm.arrsiz = 9;
                 sqlstm.sqladtp = &sqladt;
                 sqlstm.sqltdsp = &sqltds;
                 sqlstm.iters = (unsigned int  )1;
                 sqlstm.offset = (unsigned int  )332;
                 sqlstm.selerr = (unsigned short)1;
                 sqlstm.cud = sqlcud0;
                 sqlstm.sqlest = (unsigned char  *)&sqlca;
                 sqlstm.sqlety = (unsigned short)4352;
                 sqlstm.occurs = (unsigned int  )0;
                 sqlstm.sqfoff = (         int )0;
                 sqlstm.sqfmod = (unsigned int )2;
                 sqlstm.sqhstv[0] = (unsigned char  *)&v_absent;
                 sqlstm.sqhstl[0] = (unsigned long )11;
                 sqlstm.sqhsts[0] = (         int  )0;
                 sqlstm.sqindv[0] = (         short *)&ind_absent;
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
                 if (sqlca.sqlcode < 0) goto getdspmismatchbytid_error;
}



                	if (SQLCODE == SQL_NOT_FOUND) {
                        	break;
                	}


/* absent */
                	if (ind_absent >= 0) {
                        	v_absent.arr[v_absent.len] = '\0';
				strcpy(csAbs,(const char *)v_absent.arr);
DEBUGLOG(("GetDspMismatchByTid absent = [%s]\n",csAbs));
                	}

			iRet = PD_FOUND;

        	}
        	while(PD_TRUE);

        	/* EXEC SQL CLOSE c_cursor_getdspmismatch_tid; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 9;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )351;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
         if (sqlca.sqlcode < 0) goto getdspmismatchbytid_error;
}



	}
	else if(cPartyType == PD_TYPE_MERCHANT){
       		hv_merchant_ref.len = strlen(csPspTid);
        	memcpy(hv_merchant_ref.arr,csPspTid,hv_merchant_ref.len);
DEBUGLOG(("GetDspMismatchByTid merchant_ref = [%d][%.*s]\n",hv_merchant_ref.len,hv_merchant_ref.len,hv_merchant_ref.arr));

        	/* EXEC SQL DECLARE c_cursor_getdspmismatch_ref CURSOR FOR
                select 
			dm_absent
		from deposit_mismatch 
		where dm_merchant_ref = :hv_merchant_ref
		and   dm_party_type = :hv_party_type; */ 


        	/* EXEC SQL OPEN c_cursor_getdspmismatch_ref; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 9;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.stmt = sq0007;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )366;
         sqlstm.selerr = (unsigned short)1;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqcmod = (unsigned int )0;
         sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_ref;
         sqlstm.sqhstl[0] = (unsigned long )52;
         sqlstm.sqhsts[0] = (         int  )0;
         sqlstm.sqindv[0] = (         short *)0;
         sqlstm.sqinds[0] = (         int  )0;
         sqlstm.sqharm[0] = (unsigned long )0;
         sqlstm.sqadto[0] = (unsigned short )0;
         sqlstm.sqtdso[0] = (unsigned short )0;
         sqlstm.sqhstv[1] = (unsigned char  *)&hv_party_type;
         sqlstm.sqhstl[1] = (unsigned long )1;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)0;
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
         if (sqlca.sqlcode < 0) goto getdspmismatchbytid_error;
}


        	do {
                	/* EXEC SQL FETCH c_cursor_getdspmismatch_ref
                	INTO
				:v_absent:ind_absent; */ 

{
                 struct sqlexd sqlstm;
                 sqlstm.sqlvsn = 12;
                 sqlstm.arrsiz = 9;
                 sqlstm.sqladtp = &sqladt;
                 sqlstm.sqltdsp = &sqltds;
                 sqlstm.iters = (unsigned int  )1;
                 sqlstm.offset = (unsigned int  )389;
                 sqlstm.selerr = (unsigned short)1;
                 sqlstm.cud = sqlcud0;
                 sqlstm.sqlest = (unsigned char  *)&sqlca;
                 sqlstm.sqlety = (unsigned short)4352;
                 sqlstm.occurs = (unsigned int  )0;
                 sqlstm.sqfoff = (         int )0;
                 sqlstm.sqfmod = (unsigned int )2;
                 sqlstm.sqhstv[0] = (unsigned char  *)&v_absent;
                 sqlstm.sqhstl[0] = (unsigned long )11;
                 sqlstm.sqhsts[0] = (         int  )0;
                 sqlstm.sqindv[0] = (         short *)&ind_absent;
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
                 if (sqlca.sqlcode < 0) goto getdspmismatchbytid_error;
}



                	if (SQLCODE == SQL_NOT_FOUND) {
                        	break;
                	}


/* absent */
                	if (ind_absent >= 0) {
                        	v_absent.arr[v_absent.len] = '\0';
				strcpy(csAbs,(const char *)v_absent.arr);
DEBUGLOG(("GetDspMismatchByTid absent = [%s]\n",csAbs));
                	}

			iRet = PD_FOUND;

        	}
        	while(PD_TRUE);

        	/* EXEC SQL CLOSE c_cursor_getdspmismatch_ref; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 9;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )408;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
         if (sqlca.sqlcode < 0) goto getdspmismatchbytid_error;
}


	}

DEBUGLOG(("GetDspMismatchByTid Normal Exit\n"));
        return  iRet;

getdspmismatchbytid_error:
DEBUGLOG(("getdspmismatchbytid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("DepositMismatchByTid_Get: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getdspmismatch_tid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )423;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        /* EXEC SQL CLOSE c_cursor_getdspmismatch_ref; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )438;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

