
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
    "MiBatchDetail.pc"
};


static unsigned int sqlctx = 4839467;


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

 static char *sq0002 = 
"SELECT unique bd_batch_id FROM mi_batch_header , mi_batch_detail WHERE bh_b\
atch_id = bd_batch_id AND bh_status = :b0 AND bd_txn_id = :b1 AND bd_txn_oper\
_ind = :b2            ";

 static char *sq0003 = 
"SELECT bd_batch_id , bd_seq , bd_entity_id , bd_party_type , bd_party_id , \
bd_txn_id FROM mi_batch_detail WHERE bd_batch_id in ( SELECT bd_batch_id FROM\
 mi_batch_detail WHERE bd_txn_id = :b0 AND bd_txn_oper_ind = decode ( :b1 , '\
X' , bd_txn_oper_ind , :b1 ) ) ORDER BY bd_seq asc            ";

 static char *sq0004 = 
"SELECT bd_batch_id , bh_process_type FROM mi_batch_header , mi_batch_detail\
 WHERE bh_batch_id = bd_batch_id AND bh_status = :b0 AND bd_txn_id = :b1 AND \
bd_batch_id NOT IN ( SELECT br_org_batch_id FROM mi_batch_relation , mi_batch\
_header WHERE br_batch_id = bh_batch_id AND bh_status = :b0 AND br_relation_t\
ype = :b3 ) AND bd_batch_id NOT IN ( SELECT br_batch_id FROM mi_batch_relatio\
n WHERE br_relation_type = :b4 ) ORDER BY bd_create_timestamp            ";

 static char *sq0005 = 
"SELECT bd_seq , bd_entity_id , bd_party_type , bd_party_id , bd_txn_oper_in\
d , bd_txn_id FROM mi_batch_detail WHERE bd_batch_id = :b0 ORDER BY bd_seq AS\
C            ";

 static char *sq0006 = 
"SELECT unique bd_batch_id , bh_process_type FROM mi_batch_header , mi_batch\
_detail WHERE bh_batch_id = bd_batch_id AND bd_txn_oper_ind = :b0 AND bd_txn_\
id = :b1            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,285,0,6,137,0,0,9,9,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,1,9,0,0,1,1,0,0,1,9,0,0,
56,0,0,2,174,0,9,217,0,2049,3,3,0,1,0,1,1,0,0,1,9,0,0,1,1,0,0,
83,0,0,2,0,0,13,219,0,0,1,0,0,1,0,2,9,0,0,
102,0,0,2,0,0,15,239,0,0,0,0,0,1,0,
117,0,0,2,0,0,15,249,0,0,0,0,0,1,0,
132,0,0,3,291,0,9,322,0,2049,3,3,0,1,0,1,9,0,0,1,1,0,0,1,1,0,0,
159,0,0,3,0,0,13,324,0,0,6,0,0,1,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,
198,0,0,3,0,0,15,386,0,0,0,0,0,1,0,
213,0,0,3,0,0,15,396,0,0,0,0,0,1,0,
228,0,0,4,456,0,9,461,0,2049,5,5,0,1,0,1,1,0,0,1,9,0,0,1,1,0,0,1,1,0,0,1,1,0,0,
263,0,0,4,0,0,13,463,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
286,0,0,4,0,0,15,491,0,0,0,0,0,1,0,
301,0,0,4,0,0,15,501,0,0,0,0,0,1,0,
316,0,0,5,165,0,9,550,0,2049,1,1,0,1,0,1,9,0,0,
335,0,0,5,0,0,13,552,0,0,6,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,9,
0,0,
374,0,0,5,0,0,15,613,0,0,0,0,0,1,0,
389,0,0,5,0,0,15,623,0,0,0,0,0,1,0,
404,0,0,6,172,0,9,662,0,2049,2,2,0,1,0,1,1,0,0,1,9,0,0,
427,0,0,6,0,0,13,664,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
450,0,0,6,0,0,15,692,0,0,0,0,0,1,0,
465,0,0,6,0,0,15,702,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/11/06              LokMan Chow
Add function GetAllDetailByTxnId                   2015/11/18              David Wong
Add function GetLastBatchIdByTxnId		   2015/11/25		   Dirk Wong
Add function GetAllDetailByBatchId                 2015/11/25              Elvis Wong
Add function GetInitBatchDtByTxnId		   2015/11/26		   LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "internal.h"
#include "MiBatchDetail.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char    cDebug;

void MiBatchDetail(char    cdebug)
{
        cDebug = cdebug;
}



int Add(const hash_t *hRls)
{
	char            *csTmp;
	char          	cTmp;
	int          	iTmp;


	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	short           hv_return_value;

	/* varchar         hv_batch_id[PD_MI_BATCH_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;

	int         	hv_seq;
	/* varchar         hv_entity_id[PD_MMS_ENTITY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_entity_id;

	/* varchar		hv_party_type[PD_MMS_PARTY_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[5]; } hv_party_type;

	/* varchar		hv_party_id[PD_MMS_PARTY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_party_id;

	/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

	char		hv_txn_oper_ind;
	/* varchar         hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;


	short           ind_batch_id = -1;
	short           ind_seq = -1;
	short           ind_entity_id = -1;
	short           ind_party_type = -1;
	short           ind_party_id = -1;
	short           ind_txn_id = -1;
	short           ind_txn_oper_ind = -1;
	short           ind_add_user = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));


/* batch_id */
        if (GetField_CString(hRls,"batch_id",&csTmp)) {
                hv_batch_id.len = strlen(csTmp);
                memcpy(hv_batch_id.arr,csTmp,hv_batch_id.len);
                ind_batch_id = 0;
DEBUGLOG(("Add:batch_id = [%.*s]\n",hv_batch_id.len,hv_batch_id.arr));
        }

/* seq */
        if (GetField_Int(hRls,"seq",&iTmp)) {
                hv_seq = iTmp;
                ind_seq = 0;
DEBUGLOG(("Add:seq = [%d]\n",hv_seq));
        }

/* entity_id */
        if (GetField_CString(hRls,"entity_id",&csTmp)) {
                hv_entity_id.len = strlen(csTmp);
                memcpy(hv_entity_id.arr,csTmp,hv_entity_id.len);
                ind_entity_id = 0;
DEBUGLOG(("Add:entity_id = [%.*s]\n",hv_entity_id.len,hv_entity_id.arr));
        }

/* party_type */
        if (GetField_CString(hRls,"party_type",&csTmp)) {
                hv_party_type.len = strlen(csTmp);
                memcpy(hv_party_type.arr,csTmp,hv_party_type.len);
                ind_party_type = 0;
DEBUGLOG(("Add:party_type = [%.*s]\n",hv_party_type.len,hv_party_type.arr));
        }

/* party_id */
        if (GetField_CString(hRls,"party_id",&csTmp)) {
                hv_party_id.len = strlen(csTmp);
                memcpy(hv_party_id.arr,csTmp,hv_party_id.len);
                ind_party_id = 0;
DEBUGLOG(("Add:party_id = [%.*s]\n",hv_party_id.len,hv_party_id.arr));
        }

/* txn_id */
        if (GetField_CString(hRls,"txn_id",&csTmp)) {
                hv_txn_id.len = strlen(csTmp);
                memcpy(hv_txn_id.arr,csTmp,hv_txn_id.len);
                ind_txn_id = 0;
DEBUGLOG(("Add:txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
        }

/* txn_oper_ind */
        if (GetField_Char(hRls,"txn_oper_ind",&cTmp)) {
                hv_txn_oper_ind= cTmp;
                ind_txn_oper_ind = 0;
DEBUGLOG(("Add:txn_oper_ind = [%c]\n",hv_txn_oper_ind));
        }

/* user */
        if (GetField_CString(hRls,"add_user",&csTmp)) {
                hv_add_user.len = strlen(csTmp);
                memcpy(hv_add_user.arr,csTmp,hv_add_user.len);
                ind_add_user = 0;
DEBUGLOG(("Add:add_user = [%.*s]\n",hv_add_user.len,hv_add_user.arr));
        }

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_mi_batch_detail_insert(
					:hv_batch_id:ind_batch_id,
					:hv_seq:ind_seq,
					:hv_entity_id:ind_entity_id,
					:hv_party_type:ind_party_type,
					:hv_party_id:ind_party_id,
					:hv_txn_id:ind_txn_id,
					:hv_txn_oper_ind:ind_txn_oper_ind,
					:hv_add_user:ind_add_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_mi_batch_detail_insert ( :hv_b\
atch_id:ind_batch_id , :hv_seq:ind_seq , :hv_entity_id:ind_entity_id , :hv_pa\
rty_type:ind_party_type , :hv_party_id:ind_party_id , :hv_txn_id:ind_txn_id ,\
 :hv_txn_oper_ind:ind_txn_oper_ind , :hv_add_user:ind_add_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_batch_id;
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
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_entity_id;
 sqlstm.sqhstl[3] = (unsigned long )22;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_entity_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_party_type;
 sqlstm.sqhstl[4] = (unsigned long )7;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_party_type;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_party_id;
 sqlstm.sqhstl[5] = (unsigned long )17;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_party_id;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[6] = (unsigned long )18;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_txn_id;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_txn_oper_ind;
 sqlstm.sqhstl[7] = (unsigned long )1;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_txn_oper_ind;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_add_user;
 sqlstm.sqhstl[8] = (unsigned long )22;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_add_user;
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
	if (hv_return_value == SP_OK) {
DEBUGLOG(("Add:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MiBatchDetail_Add: SP_OTHER_ERR\n");
DEBUGLOG(("Add: SP_OTHER_ERR\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("MiBatchDetail_Add: SP_ERR\n");
DEBUGLOG(("Add: SP_ERR\n"));
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("MiBatchDetail_Add: SP_INTERNAL_ERR\n");
DEBUGLOG(("Add: SP_INTERNAL_ERR\n"));
        return PD_INTERNAL_ERR;
}


int GetOrgBatchIdByTxnId(const char* csTxnId, char cOperInd, hash_t* hDtl)
{
        int     iRet = PD_NOT_FOUND;
DEBUGLOG(("GetOrgBatchIdByTxnId()\n"));

        /* EXEC SQL WHENEVER SQLERROR GOTO getbatchid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		char		hv_oper_ind;
		char		hv_status;

                /* varchar         v_batch_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_batch_id;


		short		ind_batch_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


/* txn_id */
	hv_txn_id.len = strlen(csTxnId);
	memcpy(hv_txn_id.arr,csTxnId,hv_txn_id.len);
DEBUGLOG(("GetOrgBatchIdByTxnId txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

       	hv_oper_ind = cOperInd;
DEBUGLOG(("GetOrgBatchIdByTxnId oper_ind = [%c]\n",hv_oper_ind));

	hv_status = 'N';

        /* EXEC SQL DECLARE c_cursor_getbatchid CURSOR FOR
		SELECT	unique bd_batch_id
	          FROM	mi_batch_header, mi_batch_detail
		WHERE	bh_batch_id = bd_batch_id
		AND	bh_status = :hv_status
		AND	bd_txn_id = :hv_txn_id
		AND	bd_txn_oper_ind = :hv_oper_ind; */ 


        /* EXEC SQL OPEN c_cursor_getbatchid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0002;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )56;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[0] = (unsigned long )1;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_oper_ind;
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
        if (sqlca.sqlcode < 0) goto getbatchid_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getbatchid
                INTO
			:v_batch_id:ind_batch_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 9;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )83;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
                sqlstm.sqhstl[0] = (unsigned long )19;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_batch_id;
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
                if (sqlca.sqlcode < 0) goto getbatchid_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                iRet = PD_FOUND;

/* batch_id */
                if (ind_batch_id >= 0 ) {
                        v_batch_id.arr[v_batch_id.len] ='\0';
DEBUGLOG(("GetOrgBatchIdByTxnId batch_id = [%s]\n",v_batch_id.arr));
			PutField_CString(hDtl,"batch_id",(const char*) v_batch_id.arr);
                }

        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getbatchid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )102;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getbatchid_error;
}



DEBUGLOG(("GetOrgBatchIdByTxnId() normal return iRet = [%d]\n",iRet));
        return iRet;

getbatchid_error:
DEBUGLOG(("psppartyid_error code %d\n", sqlca.sqlcode));
ERRLOG("DBMiBatchDetail::getbatchid_error code %d\n", sqlca.sqlcode);
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getbatchid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )117;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

/*
	myHash:
		txn_id(mandatory)
		oper_ind(optional)
*/
int GetAllDetailByTxnId(hash_t* myHash, recordset_t* myRec)
{
	int iRet = PD_NOT_FOUND;
	char cTmp;
	char* csTmp;

	hash_t *hTmp;

DEBUGLOG(("GetAllDetailByTxnId() start\n"));

	/* EXEC SQL WHENEVER SQLERROR GOTO getalldtbytxnid_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		char hv_oper_ind;

		/* varchar v_batch_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_batch_id;

		int v_seq;
		/* varchar v_entity_id[PD_MMS_ENTITY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_entity_id;

		/* varchar v_party_type[PD_MMS_ENTITY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_party_type;

		/* varchar v_party_id[PD_MMS_PARTY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;

		/* varchar v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;


		short ind_batch_id = -1;
		short ind_seq = -1;
		short ind_entity_id = -1;
		short ind_party_type = -1;
		short ind_party_id = -1;
		short ind_txn_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


/* txn_id */
	if (GetField_CString(myHash, "txn_id", &csTmp)) {
		hv_txn_id.len = strlen(csTmp);
		memcpy(hv_txn_id.arr, csTmp, hv_txn_id.len);
DEBUGLOG(("GetAllDetailByTxnId txn_id = [%.*s]\n", hv_txn_id.len, hv_txn_id.arr));
	}

/* oper_ind */
	if (GetField_Char(myHash, "oper_ind", &cTmp)) {
		hv_oper_ind = cTmp;
DEBUGLOG(("GetAllDetailByTxnId oper_ind = [%c]\n", hv_oper_ind));
	} else {
		hv_oper_ind = 'X';
DEBUGLOG(("GetAllDetailByTxnId oper_ind = [%c]\n", hv_oper_ind));
	}

	/* EXEC SQL DECLARE c_cursor_getalldtbytxnid CURSOR FOR
		SELECT	bd_batch_id,
			bd_seq,
			bd_entity_id,
			bd_party_type,
			bd_party_id,
			bd_txn_id
		FROM	mi_batch_detail
		WHERE	bd_batch_id in (
				SELECT	bd_batch_id
				FROM	mi_batch_detail
				WHERE	bd_txn_id = :hv_txn_id
				AND	bd_txn_oper_ind = decode(:hv_oper_ind, 'X', bd_txn_oper_ind, :hv_oper_ind)
			)
		ORDER BY bd_seq asc; */ 


	/* EXEC SQL OPEN c_cursor_getalldtbytxnid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )132;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_oper_ind;
 sqlstm.sqhstl[1] = (unsigned long )1;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_oper_ind;
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
 if (sqlca.sqlcode < 0) goto getalldtbytxnid_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getalldtbytxnid
		INTO
			:v_batch_id:ind_batch_id,
			:v_seq:ind_seq,
			:v_entity_id:ind_entity_id,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_txn_id:ind_txn_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )159;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_batch_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_seq;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_seq;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_entity_id;
  sqlstm.sqhstl[2] = (unsigned long )23;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_entity_id;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_party_type;
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_party_type;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_party_id;
  sqlstm.sqhstl[4] = (unsigned long )18;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_party_id;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[5] = (unsigned long )19;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_txn_id;
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
  if (sqlca.sqlcode < 0) goto getalldtbytxnid_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iRet = PD_FOUND;

		hTmp = (hash_t*) malloc (sizeof(hash_t));
		hash_init(hTmp, 0);

		// batch_id
		if (ind_batch_id >= 0) {
			v_batch_id.arr[v_batch_id.len] = '\0';
DEBUGLOG(("GetAllDetailByTxnId batch_id = [%s]\n", v_batch_id.arr));
			PutField_CString(hTmp, "batch_id", (const char*)v_batch_id.arr);
		}

		// seq
		if (ind_seq >= 0) {
DEBUGLOG(("GetAllDetailByTxnId seq = [%d]\n", v_seq));
			PutField_Int(hTmp, "seq", v_seq);
		}

		// entity_id
		if (ind_entity_id >= 0) {
			v_entity_id.arr[v_entity_id.len] = '\0';
DEBUGLOG(("GetAllDetailByTxnId entity_id = [%s]\n", v_entity_id.arr));
			PutField_CString(hTmp, "entity_id", (const char*)v_entity_id.arr);
		}

		// party_type
		if (ind_party_type >= 0) {
			v_party_type.arr[v_party_type.len] = '\0';
DEBUGLOG(("GetAllDetailByTxnId party_type = [%s]\n", v_party_type.arr));
			PutField_CString(hTmp, "party_type", (const char*)v_party_type.arr);
		}

		// party_id
		if (ind_party_id >= 0) {
			v_party_id.arr[v_party_id.len] = '\0';
DEBUGLOG(("GetAllDetailByTxnId party_id = [%s]\n", v_party_id.arr));
			PutField_CString(hTmp, "party_id", (const char*)v_party_id.arr);
		}

		// txn_id
		if (ind_txn_id >= 0) {
			v_txn_id.arr[v_txn_id.len] = '\0';
DEBUGLOG(("GetAllDetailByTxnId txn_id = [%s]\n", v_txn_id.arr));
			PutField_CString(hTmp, "txn_id", (const char*)v_txn_id.arr);
		}

		RecordSet_Add(myRec, hTmp);
	} while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getalldtbytxnid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )198;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getalldtbytxnid_error;
}



DEBUGLOG(("GetAllDetailByTxnId() normal return iRet = [%d]\n", iRet));
	return iRet;

getalldtbytxnid_error:
DEBUGLOG(("getalldtbytxnid_error code %d\n", sqlca.sqlcode));
ERRLOG("DBMiBatchDetail::getalldtbytxnid_error code %d\n", sqlca.sqlcode);
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getalldtbytxnid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )213;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

/*
	myHash:
		txn_id(mandatory)
		oper_ind(optional)
*/
int GetSingleDetailByTxnId(hash_t* myHash, recordset_t* myRec)
{
	int iRet = PD_NOT_FOUND;

	return iRet;
}


int GetLastBatchDtByTxnId(const char* csTxnId, hash_t* hDtl)
{
        int     iRet = PD_NOT_FOUND;
DEBUGLOG(("GetLastBatchDtByTxnId()\n"));

        /* EXEC SQL WHENEVER SQLERROR GOTO getlastbatchdt_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		char		hv_status;
		char		hv_relation_linkage;
		char		hv_relation_void;

                /* varchar         v_batch_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_batch_id;

		/* varchar		v_process_type[PD_MI_PROCESS_TYPE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_process_type;


		short		ind_batch_id = -1;
		short		ind_process_type = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


/* txn_id */
	hv_txn_id.len = strlen(csTxnId);
	memcpy(hv_txn_id.arr,csTxnId,hv_txn_id.len);
DEBUGLOG(("GetOrgBatchIdByTxnId txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

	hv_status = PD_MI_BATCH_STATUS_NORMAL;
	hv_relation_linkage = PD_MI_BATCH_RELATION_TYPE_LINKAGE;
	hv_relation_void = PD_MI_BATCH_RELATION_TYPE_VOID;

        /* EXEC SQL DECLARE c_cursor_getlastbatchdt CURSOR FOR
		SELECT	bd_batch_id, bh_process_type
	        FROM	mi_batch_header, mi_batch_detail
		WHERE	bh_batch_id = bd_batch_id
		AND	bh_status = :hv_status
		AND	bd_txn_id = :hv_txn_id
		AND	bd_batch_id NOT IN (SELECT br_org_batch_id
					    FROM   mi_batch_relation, mi_batch_header
					    WHERE  br_batch_id = bh_batch_id
					    AND    bh_status = :hv_status
					    AND    br_relation_type = :hv_relation_linkage)
		AND	bd_batch_id NOT IN (SELECT br_batch_id
					    FROM   mi_batch_relation
					    WHERE  br_relation_type = :hv_relation_void)
		ORDER BY bd_create_timestamp
		; */ 


        /* EXEC SQL OPEN c_cursor_getlastbatchdt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0004;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )228;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[0] = (unsigned long )1;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[2] = (unsigned long )1;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_relation_linkage;
        sqlstm.sqhstl[3] = (unsigned long )1;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_relation_void;
        sqlstm.sqhstl[4] = (unsigned long )1;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
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
        if (sqlca.sqlcode < 0) goto getlastbatchdt_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getlastbatchdt
                INTO
			:v_batch_id:ind_batch_id,
			:v_process_type:ind_process_type; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 9;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )263;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
                sqlstm.sqhstl[0] = (unsigned long )19;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_batch_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_process_type;
                sqlstm.sqhstl[1] = (unsigned long )23;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_process_type;
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
                if (sqlca.sqlcode < 0) goto getlastbatchdt_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                iRet = PD_FOUND;

/* batch_id */
                if (ind_batch_id >= 0 ) {
                        v_batch_id.arr[v_batch_id.len] ='\0';
DEBUGLOG(("GetLastBatchDtByTxnId batch_id = [%s]\n",v_batch_id.arr));
			PutField_CString(hDtl,"batch_id",(const char*) v_batch_id.arr);
                }

/* process_type */
                if (ind_process_type >= 0 ) {
                        v_process_type.arr[v_process_type.len] ='\0';
DEBUGLOG(("GetLastBatchDtByTxnId process_type = [%s]\n",v_process_type.arr));
			PutField_CString(hDtl,"process_type",(const char*) v_process_type.arr);
                }

        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getlastbatchdt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )286;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getlastbatchdt_error;
}



DEBUGLOG(("GetLastBatchDtByTxnId() normal return iRet = [%d]\n",iRet));
        return iRet;

getlastbatchdt_error:
DEBUGLOG(("getlastbatchdt_error code %d\n", sqlca.sqlcode));
ERRLOG("DBMiBatchDetail::getlastbatchdt_error code %d\n", sqlca.sqlcode);
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getlastbatchdt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )301;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int GetAllDetailByBatchId(const char* csBatchId, recordset_t* myRec)
{
	int iRet = PD_NOT_FOUND;

	hash_t *hTmp;

DEBUGLOG(("GetAllDetailByBatchId() start\n"));

	/* EXEC SQL WHENEVER SQLERROR GOTO getalldtbybatchid_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;


		int v_seq;
		/* varchar v_entity_id[PD_MMS_ENTITY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_entity_id;

		/* varchar v_party_type[PD_MMS_ENTITY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_party_type;

		/* varchar v_party_id[PD_MMS_PARTY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;

		char v_oper_ind;
		/* varchar v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;


		short ind_seq = -1;
		short ind_entity_id = -1;
		short ind_party_type = -1;
		short ind_party_id = -1;
		short ind_oper_ind = -1;
		short ind_txn_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


/* batch_id */
	hv_batch_id.len = strlen(csBatchId);
        memcpy(hv_batch_id.arr,csBatchId,hv_batch_id.len);
DEBUGLOG(("GetAllDetailByBatchId batch_id = [%d][%.*s]\n",hv_batch_id.len,hv_batch_id.len,hv_batch_id.arr));

	/* EXEC SQL DECLARE c_cursor_getalldtbybatchid CURSOR FOR
		SELECT	bd_seq,
			bd_entity_id,
			bd_party_type,
			bd_party_id,
			bd_txn_oper_ind,
			bd_txn_id
		FROM	mi_batch_detail
		WHERE	bd_batch_id = :hv_batch_id
		ORDER BY bd_seq ASC; */ 


	/* EXEC SQL OPEN c_cursor_getalldtbybatchid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0005;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )316;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[0] = (unsigned long )18;
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
 if (sqlca.sqlcode < 0) goto getalldtbybatchid_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getalldtbybatchid
		INTO
			:v_seq:ind_seq,
			:v_entity_id:ind_entity_id,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_oper_ind:ind_oper_ind,
			:v_txn_id:ind_txn_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )335;
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
  sqlstm.sqhstv[1] = (unsigned char  *)&v_entity_id;
  sqlstm.sqhstl[1] = (unsigned long )23;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_entity_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_party_type;
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_party_type;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_party_id;
  sqlstm.sqhstl[3] = (unsigned long )18;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_party_id;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_oper_ind;
  sqlstm.sqhstl[4] = (unsigned long )1;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_oper_ind;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[5] = (unsigned long )19;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_txn_id;
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
  if (sqlca.sqlcode < 0) goto getalldtbybatchid_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iRet = PD_FOUND;

		hTmp = (hash_t*) malloc (sizeof(hash_t));
                hash_init(hTmp, 0);

		// seq
		if (ind_seq >= 0) {
DEBUGLOG(("GetAllDetailByBatchId seq = [%d]\n", v_seq));
			PutField_Int(hTmp, "seq", v_seq);
		}

		// entity_id
		if (ind_entity_id >= 0) {
			v_entity_id.arr[v_entity_id.len] = '\0';
DEBUGLOG(("GetAllDetailByBatchId entity_id = [%s]\n", v_entity_id.arr));
			PutField_CString(hTmp, "entity_id", (const char*)v_entity_id.arr);
		}

		// party_type
		if (ind_party_type >= 0) {
			v_party_type.arr[v_party_type.len] = '\0';
DEBUGLOG(("GetAllDetailByBatchId party_type = [%s]\n", v_party_type.arr));
			PutField_CString(hTmp, "party_type", (const char*)v_party_type.arr);
		}

		// party_id
		if (ind_party_id >= 0) {
			v_party_id.arr[v_party_id.len] = '\0';
DEBUGLOG(("GetAllDetailByBatchId party_id = [%s]\n", v_party_id.arr));
			PutField_CString(hTmp, "party_id", (const char*)v_party_id.arr);
		}

		// oper_ind
                if (ind_oper_ind >= 0) {
                        PutField_Char(hTmp,"oper_ind",v_oper_ind);
DEBUGLOG(("GetAllDetailByBatchId oper_ind = [%c]\n",v_oper_ind));
                }

		// txn_id
		if (ind_txn_id >= 0) {
			v_txn_id.arr[v_txn_id.len] = '\0';
DEBUGLOG(("GetAllDetailByBatchId txn_id = [%s]\n", v_txn_id.arr));
			PutField_CString(hTmp, "txn_id", (const char*)v_txn_id.arr);
		}

		RecordSet_Add(myRec, hTmp);
	} while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getalldtbybatchid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )374;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getalldtbybatchid_error;
}



DEBUGLOG(("GetAllDetailByBatchId() normal return iRet = [%d]\n", iRet));
	return iRet;

getalldtbybatchid_error:
DEBUGLOG(("getalldtbybatchid_error code %d\n", sqlca.sqlcode));
ERRLOG("DBMiBatchDetail::getalldtbybatchid_error code %d\n", sqlca.sqlcode);
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getalldtbybatchid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )389;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}


int GetInitBatchDtByTxnId(const char* csTxnId, hash_t* hDtl)
{
        int     iRet = PD_NOT_FOUND;
DEBUGLOG(("GetInitBatchDtByTxnId()\n"));

        /* EXEC SQL WHENEVER SQLERROR GOTO getinitbatchdt_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		char		hv_oper_ind;

                /* varchar         v_batch_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_batch_id;

		/* varchar		v_process_type[PD_MI_PROCESS_TYPE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_process_type;


		short		ind_batch_id = -1;
		short		ind_process_type = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


/* txn_id */
	hv_txn_id.len = strlen(csTxnId);
	memcpy(hv_txn_id.arr,csTxnId,hv_txn_id.len);
DEBUGLOG(("GetInitBatchDtByTxnId txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

	hv_oper_ind = 'I';

        /* EXEC SQL DECLARE c_cursor_getinitbatchdt CURSOR FOR
		SELECT	unique bd_batch_id, bh_process_type
	        FROM	mi_batch_header, mi_batch_detail
		WHERE	bh_batch_id = bd_batch_id
		AND	bd_txn_oper_ind = :hv_oper_ind
		AND	bd_txn_id = :hv_txn_id; */ 


        /* EXEC SQL OPEN c_cursor_getinitbatchdt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0006;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )404;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_oper_ind;
        sqlstm.sqhstl[0] = (unsigned long )1;
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
        if (sqlca.sqlcode < 0) goto getinitbatchdt_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getinitbatchdt
                INTO
			:v_batch_id:ind_batch_id,
			:v_process_type:ind_process_type; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 9;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )427;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
                sqlstm.sqhstl[0] = (unsigned long )19;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_batch_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_process_type;
                sqlstm.sqhstl[1] = (unsigned long )23;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_process_type;
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
                if (sqlca.sqlcode < 0) goto getinitbatchdt_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                iRet = PD_FOUND;

/* batch_id */
                if (ind_batch_id >= 0 ) {
                        v_batch_id.arr[v_batch_id.len] ='\0';
DEBUGLOG(("GetInitBatchDtByTxnId batch_id = [%s]\n",v_batch_id.arr));
			PutField_CString(hDtl,"batch_id",(const char*) v_batch_id.arr);
                }

/* process_type */
                if (ind_process_type >= 0 ) {
                        v_process_type.arr[v_process_type.len] ='\0';
DEBUGLOG(("GetInitBatchDtByTxnId process_type = [%s]\n",v_process_type.arr));
			PutField_CString(hDtl,"process_type",(const char*) v_process_type.arr);
                }

        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getinitbatchdt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )450;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getinitbatchdt_error;
}



DEBUGLOG(("GetInitBatchDtByTxnId() normal return iRet = [%d]\n",iRet));
        return iRet;

getinitbatchdt_error:
DEBUGLOG(("getinitbatchdt_error code %d\n", sqlca.sqlcode));
ERRLOG("DBMiBatchDetail::getinitbatchdt_error code %d\n", sqlca.sqlcode);
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getinitbatchdt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )465;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}
