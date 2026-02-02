
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
           char  filnam[17];
};
static struct sqlcxp sqlfpn =
{
    16,
    "MmsRelatedTxn.pc"
};


static unsigned int sqlctx = 5092747;


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
   unsigned char  *sqhstv[6];
   unsigned long  sqhstl[6];
            int   sqhsts[6];
            short *sqindv[6];
            int   sqinds[6];
   unsigned long  sqharm[6];
   unsigned long  *sqharc[6];
   unsigned short  sqadto[6];
   unsigned short  sqtdso[6];
} sqlstm = {12,6};

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
"select mrt_prev_txn_id , mrt_prev_dtl_txn_id from mms_related_txn where mrt\
_txn_id = :b0 and mrt_dtl_txn_id = :b1 order by mrt_prev_txn_id desc , mrt_pr\
ev_dtl_txn_id desc            ";

 static char *sq0003 = 
"select mrt_txn_id , mrt_dtl_txn_id from mms_related_txn where mrt_prev_txn_\
id = :b0 and mrt_prev_dtl_txn_id = :b1 order by mrt_txn_id desc , mrt_dtl_txn\
_id desc            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,221,0,6,102,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,
44,0,0,2,182,0,9,186,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
67,0,0,2,0,0,13,188,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
90,0,0,2,0,0,15,220,0,0,0,0,0,1,0,
105,0,0,2,0,0,15,236,0,0,0,0,0,1,0,
120,0,0,3,172,0,9,283,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
143,0,0,3,0,0,13,285,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
166,0,0,3,0,0,15,317,0,0,0,0,0,1,0,
181,0,0,3,0,0,15,333,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2021/02/29              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "MmsRelatedTxn.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void MmsRelatedTxn(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const hash_t *hRls)
{
        char    *csTmp;
	//int	iTmp;


        /* EXEC SQL WHENEVER SQLERROR GOTO add_header_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        short   	hv_return_value;

        /* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;
        
        /* varchar		hv_dtl_txn_id[PD_MMS_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[38]; } hv_dtl_txn_id;

        /* varchar		hv_prev_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_prev_txn_id;
        
        /* varchar		hv_prev_dtl_txn_id[PD_MMS_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[38]; } hv_prev_dtl_txn_id;

        /* varchar         hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;



        short           ind_txn_id = -1;
        short           ind_dtl_txn_id = -1;
        short           ind_prev_txn_id = -1;
        short           ind_prev_dtl_txn_id = -1;
        short           ind_add_user = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

/* txn_seq */
        if (GetField_CString(hRls,"txn_seq",&csTmp)) {
                hv_txn_id.len = strlen(csTmp);
                memcpy(hv_txn_id.arr,csTmp,hv_txn_id.len);
                ind_txn_id = 0;
DEBUGLOG(("Add:txn_id = [%.*s][%d]\n",hv_txn_id.len,hv_txn_id.arr,hv_txn_id.len));
        }

/* dtl_txn_id */
        if (GetField_CString(hRls,"dtl_txn_seq",&csTmp)) {
                hv_dtl_txn_id.len = strlen(csTmp);
                memcpy(hv_dtl_txn_id.arr,csTmp,hv_dtl_txn_id.len);
                ind_dtl_txn_id = 0;
DEBUGLOG(("Add:dtl_txn_id = [%.*s][%d]\n",hv_dtl_txn_id.len,hv_dtl_txn_id.arr,hv_dtl_txn_id.len));
        }

/* prev txn_seq */
        if (GetField_CString(hRls,"prev_txn_seq",&csTmp)) {
                hv_prev_txn_id.len = strlen(csTmp);
                memcpy(hv_prev_txn_id.arr,csTmp,hv_prev_txn_id.len);
                ind_prev_txn_id = 0;
DEBUGLOG(("Add:prev_txn_id = [%.*s]\n",hv_prev_txn_id.len,hv_prev_txn_id.arr));
        }


/* prev_dtl_txn_id */
        if (GetField_CString(hRls,"prev_dtl_txn_seq",&csTmp)) {
                hv_prev_dtl_txn_id.len = strlen(csTmp);
                memcpy(hv_prev_dtl_txn_id.arr,csTmp,hv_prev_dtl_txn_id.len);
                ind_prev_dtl_txn_id = 0;
DEBUGLOG(("Add:prev_dtl_txn_id = [%.*s][%d]\n",hv_prev_dtl_txn_id.len,hv_prev_dtl_txn_id.arr,hv_prev_dtl_txn_id.len));
        }

/* add user */
        if (GetField_CString(hRls,"add_user",&csTmp)) {
                hv_add_user.len = strlen(csTmp);
                memcpy(hv_add_user.arr,csTmp,hv_add_user.len);
                ind_add_user = 0;
DEBUGLOG(("Add:add_user = [%.*s]\n",hv_add_user.len,hv_add_user.arr));
        }


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_mms_related_txn_insert(
                                                :hv_txn_id:ind_txn_id,
                                                :hv_dtl_txn_id:ind_dtl_txn_id,
                                                :hv_prev_txn_id:ind_prev_txn_id,
                                                :hv_prev_dtl_txn_id:ind_prev_dtl_txn_id,
                                                :hv_add_user:ind_add_user);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_mms_related_txn_insert \
( :hv_txn_id:ind_txn_id , :hv_dtl_txn_id:ind_dtl_txn_id , :hv_prev_txn_id:ind\
_prev_txn_id , :hv_prev_dtl_txn_id:ind_prev_dtl_txn_id , :hv_add_user:ind_add\
_user ) ; END ;";
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_dtl_txn_id;
        sqlstm.sqhstl[2] = (unsigned long )40;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_dtl_txn_id;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_prev_txn_id;
        sqlstm.sqhstl[3] = (unsigned long )18;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_prev_txn_id;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_prev_dtl_txn_id;
        sqlstm.sqhstl[4] = (unsigned long )40;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_prev_dtl_txn_id;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_add_user;
        sqlstm.sqhstl[5] = (unsigned long )22;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_add_user;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
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



DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK) {
DEBUGLOG(("Add:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MmsRelatedTxn_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
                TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("MmsRelatedTxn_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
                TxnAbort();
                return PD_ERR;
        }

add_header_error:
DEBUGLOG(("add_header_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("MmsRelatedTxn_Add: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;
}


int GetPrevId(const char *csTxnID,
	      const char *csDtlTxnID,
	    recordset_t *myRec)
{

	int	iCnt = 0;

	hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getprevid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

        	/* varchar		hv_dtl_txn_id[PD_MMS_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[38]; } hv_dtl_txn_id;


		/* varchar		v_prev_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_prev_txn_id;

		/* varchar		v_prev_dtl_txn_id[PD_MMS_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[39]; } v_prev_dtl_txn_id;



		short		ind_prev_txn_id= -1;
		short		ind_prev_dtl_txn_id= -1;

        /* EXEC SQL END DECLARE SECTION; */ 

		
	hv_txn_id.len = strlen(csTxnID);
        memcpy(hv_txn_id.arr,csTxnID,hv_txn_id.len);
DEBUGLOG(("GetPrevId txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

	hv_dtl_txn_id.len = strlen(csDtlTxnID);
	memcpy(hv_dtl_txn_id.arr, csDtlTxnID, hv_dtl_txn_id.len);
DEBUGLOG(("GetPrevId dtl_txn_id = [%.*s]\n",hv_dtl_txn_id.len, hv_dtl_txn_id.arr));


	/* EXEC SQL DECLARE c_cursor_getprevid CURSOR FOR
		select mrt_prev_txn_id,
		       mrt_prev_dtl_txn_id
		 from mms_related_txn
		where mrt_txn_id = :hv_txn_id
		  and mrt_dtl_txn_id = :hv_dtl_txn_id
		order by mrt_prev_txn_id desc, mrt_prev_dtl_txn_id desc; */ 


	/* EXEC SQL OPEN c_cursor_getprevid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )44;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_dtl_txn_id;
 sqlstm.sqhstl[1] = (unsigned long )40;
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
 if (sqlca.sqlcode < 0) goto getprevid_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getprevid
		INTO 
			:v_prev_txn_id :ind_prev_txn_id,
			:v_prev_dtl_txn_id:ind_prev_dtl_txn_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )67;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_prev_txn_id;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_prev_txn_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_prev_dtl_txn_id;
  sqlstm.sqhstl[1] = (unsigned long )41;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_prev_dtl_txn_id;
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
  if (sqlca.sqlcode < 0) goto getprevid_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

                iCnt++;

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

/* prev_txn_id */
		if (ind_prev_txn_id >= 0) {
			v_prev_txn_id.arr[v_prev_txn_id.len] ='\0';
			PutField_CString(myHash,"txn_seq",(const char*)v_prev_txn_id.arr);
DEBUGLOG(("GetPrevId txn_id = [%s]\n",v_prev_txn_id.arr));
                }

/* prev_dtl_txn_id */
		if (ind_prev_dtl_txn_id >= 0) {
			v_prev_dtl_txn_id.arr[v_prev_dtl_txn_id.len] = '\0';
			PutField_CString(myHash, "dtl_txn_seq", (const char*) v_prev_dtl_txn_id.arr);
DEBUGLOG(("GetPrevId dtl_txn_id = [%s]\n",v_prev_dtl_txn_id.arr));
		}

		RecordSet_Add(myRec, myHash);
	}
	while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getprevid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )90;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getprevid_error;
}



	if (iCnt > 0 ) {
DEBUGLOG(("GetPrevId Normal Exit\n"));
		return  PD_FOUND;
	}
	else {
DEBUGLOG(("GetPrevId Normal Exit, Not Found\n"));
		return PD_NOT_FOUND;
	}


getprevid_error:
DEBUGLOG(("getprevid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getprevid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )105;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}



int GetNextId(const char *csTxnID,
	    const char *csDtlTxnID,
	    recordset_t *myRec)
{

	int	iCnt = 0;

	hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getnextid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

        	/* varchar		v_dtl_txn_id[PD_MMS_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[39]; } v_dtl_txn_id;


		/* varchar		hv_prev_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_prev_txn_id;

		/* varchar		hv_prev_dtl_txn_id[PD_MMS_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[38]; } hv_prev_dtl_txn_id;


		short		ind_txn_id= -1;
		short		ind_dtl_txn_id= -1;

        /* EXEC SQL END DECLARE SECTION; */ 

		
	hv_prev_txn_id.len = strlen(csTxnID);
        memcpy(hv_prev_txn_id.arr,csTxnID,hv_prev_txn_id.len);
DEBUGLOG(("GetNextId prev_txn_id = [%.*s]\n",hv_prev_txn_id.len,hv_prev_txn_id.arr));

	hv_prev_dtl_txn_id.len = strlen(csDtlTxnID);
	memcpy(hv_prev_dtl_txn_id.arr, csDtlTxnID, hv_prev_dtl_txn_id.len);
DEBUGLOG(("GetNextId prev_dtl_txn_id = [%.*s]\n",hv_prev_dtl_txn_id.len, hv_prev_dtl_txn_id.arr));


	/* EXEC SQL DECLARE c_cursor_getnextid CURSOR FOR
		select mrt_txn_id,
		       mrt_dtl_txn_id
		 from mms_related_txn
		where mrt_prev_txn_id = :hv_prev_txn_id
		  and mrt_prev_dtl_txn_id = :hv_prev_dtl_txn_id
		order by mrt_txn_id desc, mrt_dtl_txn_id desc; */ 


	/* EXEC SQL OPEN c_cursor_getnextid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )120;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_prev_txn_id;
 sqlstm.sqhstl[0] = (unsigned long )18;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_prev_dtl_txn_id;
 sqlstm.sqhstl[1] = (unsigned long )40;
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
 if (sqlca.sqlcode < 0) goto getnextid_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getnextid
		INTO 
			:v_txn_id :ind_txn_id,
			:v_dtl_txn_id:ind_dtl_txn_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )143;
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
  sqlstm.sqhstv[1] = (unsigned char  *)&v_dtl_txn_id;
  sqlstm.sqhstl[1] = (unsigned long )41;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_dtl_txn_id;
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
  if (sqlca.sqlcode < 0) goto getnextid_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

                iCnt++;

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

/* txn_id */
		if (ind_txn_id >= 0) {
			v_txn_id.arr[v_txn_id.len] ='\0';
			PutField_CString(myHash,"txn_seq",(const char*)v_txn_id.arr);
DEBUGLOG(("GetNextId txn_id = [%s]\n",v_txn_id.arr));
                }

/* dtl_txn_id */
		if (ind_dtl_txn_id >= 0) {
			v_dtl_txn_id.arr[v_dtl_txn_id.len] = '\0';
			PutField_CString(myHash, "dtl_txn_seq", (const char*) v_dtl_txn_id.arr);
DEBUGLOG(("GetNextId dtl_txn_id = [%s]\n",v_dtl_txn_id.arr));
		}

		RecordSet_Add(myRec, myHash);
	}
	while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getnextid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )166;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getnextid_error;
}



	if (iCnt > 0 ) {
DEBUGLOG(("GetNextId Normal Exit\n"));
		return  PD_FOUND;
	}
	else {
DEBUGLOG(("GetNextId Normal Exit, Not Found\n"));
		return PD_NOT_FOUND;
	}


getnextid_error:
DEBUGLOG(("getnextid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getnextid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )181;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}
