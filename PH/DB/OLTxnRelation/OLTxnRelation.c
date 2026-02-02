
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
    "OLTxnRelation.pc"
};


static unsigned int sqlctx = 5199259;


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

 static char *sq0002 = 
"SELECT otr_p1_txn_id FROM ol_txn_relation WHERE otr_party_type = :b0 AND ot\
r_p2_txn_id = :b1 AND otr_txn_level = :b2 AND otr_relation_type = :b3 ORDER B\
Y otr_relation_timestamp ASC            ";

 static char *sq0003 = 
"SELECT otr_p2_txn_id FROM ol_txn_relation WHERE otr_party_type = :b0 AND ot\
r_p1_txn_id = :b1 AND otr_txn_level = :b2 AND otr_relation_type = :b3 ORDER B\
Y otr_relation_timestamp ASC            ";

 static char *sq0004 = 
"ype != 'V' connect by prior OTR_P1_T\
XN_ID = OTR_P2_TXN_ID            ";

 static char *sq0007 = 
"SELECT otr_p2_txn_id AS otr_txn_id FROM ol_txn_relation WHERE otr_p1_txn_id\
 = :b0 AND otr_relation_type = 'B' UNION SELECT otr_p1_txn_id AS otr_txn_id F\
ROM ol_txn_relation WHERE otr_p2_txn_id = :b0 AND otr_relation_type = 'B'    \
        ";

 static char *sq0008 = 
"SELECT otr_p2_txn_id AS otr_txn_id FROM ol_txn_relation WHERE otr_p1_txn_id\
 = :b0 AND otr_relation_type = 'V' UNION SELECT otr_p1_txn_id AS otr_txn_id F\
ROM ol_txn_relation WHERE otr_p2_txn_id = :b0 AND otr_relation_type = 'V'    \
        ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,245,0,6,105,0,0,7,7,0,1,0,2,3,0,0,1,1,0,0,1,9,0,0,1,9,0,0,1,1,0,0,1,1,
0,0,1,9,0,0,
48,0,0,2,192,0,9,201,0,2049,4,4,0,1,0,1,1,0,0,1,9,0,0,1,1,0,0,1,1,0,0,
79,0,0,2,0,0,13,204,0,0,1,0,0,1,0,2,9,0,0,
98,0,0,2,0,0,15,226,0,0,0,0,0,1,0,
113,0,0,2,0,0,15,245,0,0,0,0,0,1,0,
128,0,0,3,192,0,9,307,0,2049,4,4,0,1,0,1,1,0,0,1,9,0,0,1,1,0,0,1,1,0,0,
159,0,0,3,0,0,13,310,0,0,1,0,0,1,0,2,9,0,0,
178,0,0,3,0,0,15,332,0,0,0,0,0,1,0,
193,0,0,3,0,0,15,351,0,0,0,0,0,1,0,
208,0,0,4,1093,0,9,440,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
231,0,0,4,0,0,13,443,0,0,5,0,0,1,0,2,1,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,1,0,0,
266,0,0,4,0,0,15,494,0,0,0,0,0,1,0,
281,0,0,4,0,0,15,513,0,0,0,0,0,1,0,
296,0,0,5,130,0,4,544,0,0,4,3,0,1,0,2,3,0,0,1,1,0,0,1,9,0,0,1,9,0,0,
327,0,0,6,254,0,4,596,0,0,5,4,0,1,0,2,3,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,9,0,0,
362,0,0,7,237,0,9,659,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
385,0,0,7,0,0,13,662,0,0,1,0,0,1,0,2,9,0,0,
404,0,0,7,0,0,15,684,0,0,0,0,0,1,0,
419,0,0,7,0,0,15,703,0,0,0,0,0,1,0,
434,0,0,8,237,0,9,745,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
457,0,0,8,0,0,13,748,0,0,1,0,0,1,0,2,9,0,0,
476,0,0,8,0,0,15,770,0,0,0,0,0,1,0,
491,0,0,8,0,0,15,789,0,0,0,0,0,1,0,
506,0,0,9,127,0,4,821,0,0,4,3,0,1,0,2,3,0,0,1,1,0,0,1,1,0,0,1,9,0,0,
537,0,0,10,127,0,4,872,0,0,4,3,0,1,0,2,3,0,0,1,1,0,0,1,1,0,0,1,9,0,0,
568,0,0,11,103,0,4,922,0,0,3,2,0,1,0,2,3,0,0,1,1,0,0,1,9,0,0,
595,0,0,12,103,0,4,971,0,0,3,2,0,1,0,2,3,0,0,1,1,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/01/09              Dirk Wong
Add GetRelatedTxnId				  
Add GetVoidTxnId	
Add CheckIsBalTransP1TxnId
Add CheckIsBalTransP2TxnId			   2015/02/13              Dirk Wong
Add CheckIsP1VoidTxnId
Add CheckIsP2VoidedTxnId			   2015/05/04		   Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "OLTxnRelation.h"
#include "common.h"
#include "internal.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void OLTxnRelation(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const hash_t *hRls)
{
	char	cTmp;
	char*	csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		char		hv_party;
		/* varchar		hv_p1_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_p1_txn_id;

		/* varchar		hv_p2_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_p2_txn_id;

		char		hv_txn_level;
		char		hv_relation_type;
		/* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_party = -1;
		short		ind_p1_txn_id = -1;
		short		ind_p2_txn_id = -1;
		short		ind_txn_level = -1;
		short		ind_relation_type = -1;
		short		ind_create_user = -1;

		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("Add: Begin\n"));

	if (GetField_Char(hRls,"party",&cTmp)) {
		hv_party = cTmp;
		ind_party = 0;
DEBUGLOG(("Add: party = [%c]\n",hv_party));
	}

	if (GetField_CString(hRls,"p1_txn_id",&csTmp)) {
		hv_p1_txn_id.len = strlen(csTmp);
		strncpy((char*)hv_p1_txn_id.arr, csTmp, hv_p1_txn_id.len);
		ind_p1_txn_id = 0;
DEBUGLOG(("Add: p1_txn_id = [%s]\n",(char*)hv_p1_txn_id.arr));
	}

	if (GetField_CString(hRls,"p2_txn_id",&csTmp)) {
		hv_p2_txn_id.len = strlen(csTmp);
		strncpy((char*)hv_p2_txn_id.arr, csTmp, hv_p2_txn_id.len);
		ind_p2_txn_id = 0;
DEBUGLOG(("Add: p2_txn_id = [%s]\n",(char*)hv_p2_txn_id.arr));
	}

	if (GetField_Char(hRls,"txn_level",&cTmp)) {
		hv_txn_level = cTmp;
		ind_txn_level = 0;
DEBUGLOG(("Add: txn_level =  [%c]\n",hv_txn_level));
	}

	if (GetField_Char(hRls,"relation_type",&cTmp)) {
		hv_relation_type = cTmp;
		ind_relation_type = 0;
DEBUGLOG(("Add: relation_type = [%c]\n",hv_relation_type));
	}

	if(GetField_CString(hRls,"create_user",&csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
	}
DEBUGLOG(("Add: create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_txn_relation_insert(
						:hv_party:ind_party,
						:hv_p1_txn_id:ind_p1_txn_id,
						:hv_p2_txn_id:ind_p2_txn_id,
						:hv_txn_level:ind_txn_level,
						:hv_relation_type:ind_relation_type,
                                                :hv_create_user:ind_create_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_txn_relation_insert ( :hv_p\
arty:ind_party , :hv_p1_txn_id:ind_p1_txn_id , :hv_p2_txn_id:ind_p2_txn_id , \
:hv_txn_level:ind_txn_level , :hv_relation_type:ind_relation_type , :hv_creat\
e_user:ind_create_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_party;
 sqlstm.sqhstl[1] = (unsigned long )1;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_party;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_p1_txn_id;
 sqlstm.sqhstl[2] = (unsigned long )18;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_p1_txn_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_p2_txn_id;
 sqlstm.sqhstl[3] = (unsigned long )18;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_p2_txn_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_level;
 sqlstm.sqhstl[4] = (unsigned long )1;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_txn_level;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_relation_type;
 sqlstm.sqhstl[5] = (unsigned long )1;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_relation_type;
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



	DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("Add:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("OLTxnRelation_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	} 

	if (hv_return_value == SP_ERR)  {
ERRLOG("OLTxnRelation_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLTxnRelation_Add: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int GetP1TxnId(const hash_t* hRls, recordset_t* rRecordSet)
{
	int iRet = PD_FOUND;
        
	int iCnt = 0;

        char *csTmp;
        char cTmp;

        hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getp1txnid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                char            hv_party_type;
                /* varchar         hv_p2_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_p2_txn_id;

                char            hv_txn_level;
                char            hv_relation_type;

                /* varchar         v_p1_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_p1_txn_id;

                short           ind_p1_txn_id = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


/* party_type */
        if (GetField_Char(hRls, "party_type", &cTmp)) {
                hv_party_type = cTmp;
DEBUGLOG(("GetP1TxnId: party_type = [%c]\n", hv_party_type));
        }

/* p2_txn_id */
        if (GetField_CString(hRls,"p2_txn_id",&csTmp)) {
                hv_p2_txn_id.len = strlen(csTmp);
                strncpy((char*)hv_p2_txn_id.arr, csTmp, hv_p2_txn_id.len);
DEBUGLOG(("GetP1TxnId: p2_txn_id = [%s]\n",(char*)hv_p2_txn_id.arr));
        }

/* txn_level */
        if (GetField_Char(hRls, "txn_level", &cTmp)) {
                hv_txn_level = cTmp;
DEBUGLOG(("GetP1TxnId: txn_level = [%c]\n", hv_txn_level));
        }
	
/* relation_type */
        if (GetField_Char(hRls, "relation_type", &cTmp)) {
                hv_relation_type = cTmp;
DEBUGLOG(("GetP1TxnId: relation_type = [%c]\n", hv_relation_type));
        }

	/* EXEC SQL DECLARE c_cursor_getp1txnid CURSOR FOR
                SELECT  otr_p1_txn_id
                FROM    ol_txn_relation
                WHERE   otr_party_type = :hv_party_type
                AND     otr_p2_txn_id = :hv_p2_txn_id
                AND     otr_txn_level = :hv_txn_level
                AND     otr_relation_type = :hv_relation_type
                ORDER BY otr_relation_timestamp ASC; */ 

        /* EXEC SQL OPEN c_cursor_getp1txnid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0002;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )48;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_party_type;
        sqlstm.sqhstl[0] = (unsigned long )1;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_p2_txn_id;
        sqlstm.sqhstl[1] = (unsigned long )18;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_level;
        sqlstm.sqhstl[2] = (unsigned long )1;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_relation_type;
        sqlstm.sqhstl[3] = (unsigned long )1;
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
        if (sqlca.sqlcode < 0) goto getp1txnid_error;
}


	
	for (;;) {
                /* EXEC SQL FETCH c_cursor_getp1txnid
                INTO    :v_p1_txn_id:ind_p1_txn_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 7;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )79;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_p1_txn_id;
                sqlstm.sqhstl[0] = (unsigned long )18;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_p1_txn_id;
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
                if (sqlca.sqlcode < 0) goto getp1txnid_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }
	
		iCnt++;
	
                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash, 0);

                // p1_txn_id
                if (ind_p1_txn_id >= 0) {
                        v_p1_txn_id.arr[v_p1_txn_id.len] = '\0';
                        PutField_CString(myHash, "p1_txn_id", (const char*)v_p1_txn_id.arr);
DEBUGLOG(("GetP1TxnId: p1_txn_id = [%s]\n", (const char*)v_p1_txn_id.arr));
                }

                RecordSet_Add(rRecordSet, myHash);
        }

        /* EXEC SQL CLOSE c_cursor_getp1txnid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )98;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getp1txnid_error;
}



	if (iCnt > 0) {
                iRet = PD_FOUND;
DEBUGLOG(("GetP1TxnId FOUND\n"));
        } else {
                iRet = PD_NOT_FOUND;
DEBUGLOG(("GetP1TxnId NOT FOUND!!!\n"));
        }


DEBUGLOG(("GetP1TxnId: Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

getp1txnid_error:
DEBUGLOG(("getp1txnid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLTxnRelation getp1txnid_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        /* EXEC SQL CLOSE c_cursor_getp1txnid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )113;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getp1txnid_error;
}


        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int GetP2TxnId(const hash_t* hRls, recordset_t* rRecordSet)
{
	int iRet = PD_FOUND;

        int iCnt = 0;

        char *csTmp;
        char cTmp;

        hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getp2txnid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                char            hv_party_type;
                /* varchar         hv_p1_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_p1_txn_id;

                char            hv_txn_level;
                char            hv_relation_type;

                /* varchar         v_p2_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_p2_txn_id;

                short           ind_p2_txn_id = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


/* party_type */
        if (GetField_Char(hRls, "party_type", &cTmp)) {
                hv_party_type = cTmp;
DEBUGLOG(("GetP2TxnId: party_type = [%c]\n", hv_party_type));
        }

/* p1_txn_id */
        if (GetField_CString(hRls,"p1_txn_id",&csTmp)) {
                hv_p1_txn_id.len = strlen(csTmp);
                strncpy((char*)hv_p1_txn_id.arr, csTmp, hv_p1_txn_id.len);
DEBUGLOG(("GetP2TxnId: p1_txn_id = [%s]\n",(char*)hv_p1_txn_id.arr));
        }

/* txn_level */
        if (GetField_Char(hRls, "txn_level", &cTmp)) {
                hv_txn_level = cTmp;
DEBUGLOG(("GetP2TxnId: txn_level = [%c]\n", hv_txn_level));
        }
	
/* relation_type */
        if (GetField_Char(hRls, "relation_type", &cTmp)) {
                hv_relation_type = cTmp;
DEBUGLOG(("GetP2TxnId: relation_type = [%c]\n", hv_relation_type));
        }

	/* EXEC SQL DECLARE c_cursor_getp2txnid CURSOR FOR
                SELECT  otr_p2_txn_id
                FROM    ol_txn_relation
                WHERE   otr_party_type = :hv_party_type
                AND     otr_p1_txn_id = :hv_p1_txn_id
                AND     otr_txn_level = :hv_txn_level
                AND     otr_relation_type = :hv_relation_type
                ORDER BY otr_relation_timestamp ASC; */ 

        /* EXEC SQL OPEN c_cursor_getp2txnid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0003;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )128;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_party_type;
        sqlstm.sqhstl[0] = (unsigned long )1;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_p1_txn_id;
        sqlstm.sqhstl[1] = (unsigned long )18;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_level;
        sqlstm.sqhstl[2] = (unsigned long )1;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_relation_type;
        sqlstm.sqhstl[3] = (unsigned long )1;
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
        if (sqlca.sqlcode < 0) goto getp2txnid_error;
}


	
	for (;;) {
                /* EXEC SQL FETCH c_cursor_getp2txnid
                INTO    :v_p2_txn_id:ind_p2_txn_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 7;
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
                sqlstm.sqhstv[0] = (unsigned char  *)&v_p2_txn_id;
                sqlstm.sqhstl[0] = (unsigned long )18;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_p2_txn_id;
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
                if (sqlca.sqlcode < 0) goto getp2txnid_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		iCnt++;

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash, 0);

                // p2_txn_id
                if (ind_p2_txn_id >= 0) {
                        v_p2_txn_id.arr[v_p2_txn_id.len] = '\0';
                        PutField_CString(myHash, "p2_txn_id", (const char*)v_p2_txn_id.arr);
DEBUGLOG(("GetP2TxnId: p2_txn_id = [%s]\n", (const char*)v_p2_txn_id.arr));
                }

                RecordSet_Add(rRecordSet, myHash);
        }

        /* EXEC SQL CLOSE c_cursor_getp2txnid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )178;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getp2txnid_error;
}



	
        if (iCnt > 0) {
                iRet = PD_FOUND;
DEBUGLOG(("GetP2TxnId FOUND\n"));
        } else {
                iRet = PD_NOT_FOUND;
DEBUGLOG(("GetP2TxnId NOT FOUND!!!\n"));
        }

DEBUGLOG(("GetP2TxnId: Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

getp2txnid_error:
DEBUGLOG(("getp2txnid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLTxnRelation getp2txnid_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        /* EXEC SQL CLOSE c_cursor_getp2txnid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )193;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getp2txnid_error;
}


        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int GetTxnRelationByBatchId(const hash_t* hRls, recordset_t* rRecordSet)
{
	int iRet = PD_FOUND;
        
	int iCnt = 0;

        char *csTmp;

        hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO gettxnrelationbybatchid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;


                char            v_party_type;
		/* varchar		v_p1_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_p1_txn_id;

                /* varchar         v_p2_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_p2_txn_id;

                char            v_txn_level;
                char            v_relation_type;

		short		ind_party_type = -1;
                short           ind_p1_txn_id = -1;
		short		ind_p2_txn_id = -1;
		short		ind_txn_level = -1;
		short		ind_relation_type = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


// batch_id
	if (GetField_CString(hRls, "batch_id", &csTmp)) {
		hv_batch_id.len = strlen(csTmp);
		strncpy((char*)hv_batch_id.arr, csTmp, hv_batch_id.len);
DEBUGLOG(("GetTxnRelationByBatchId batch_id = [%s]\n",(char*)hv_batch_id.arr));
	}

	/* EXEC SQL DECLARE c_cursor_gettxnrelation CURSOR FOR
		select  x1.*
                from    (select otr_party_type,
                                otr_p1_txn_id,
                                otr_p2_txn_id,
                                otr_txn_level,
                                otr_relation_type,
                                oth_txn_code,
                                tc_ofl_is_void
                        from    ol_txn_relation,
                                ol_txn_header,
				txn_code,
				ol_batch_txn_relation
                        where   otr_relation_type != 'V'
                        and     otr_p1_txn_id = oth_txn_id
                        and     oth_txn_code = tc_code
			and 	obtr_batch_id = :hv_batch_id
                        and    	obtr_txn_level = 'T'
                       	and    	obtr_txn_id in (otr_p1_txn_id,otr_p2_txn_id)
			and	otr_party_type = 'P'
			and	otr_txn_level = 'T'			
                        ) x1
                where   otr_relation_type!='V'
                connect by prior OTR_P2_TXN_ID=OTR_P1_TXN_ID
                union
                select  x1.*
                from    (select otr_party_type,
                                otr_p1_txn_id,
                                otr_p2_txn_id,
                                otr_txn_level,
                                otr_relation_type,
                                oth_txn_code,
                                tc_ofl_is_void
                        from    ol_txn_relation,
                                ol_txn_header,
                                txn_code,
				ol_batch_txn_relation
                        where   otr_relation_type != 'V'
                        and     otr_p1_txn_id = oth_txn_id
                        and     oth_txn_code = tc_code
			and	obtr_batch_id = :hv_batch_id
                        and     obtr_txn_level = 'T'
                        and     obtr_txn_id in (otr_p1_txn_id,otr_p2_txn_id)
			and	otr_party_type = 'P'
			and	otr_txn_level = 'T'
                        ) x1
                where   otr_relation_type!='V'
                connect by prior OTR_P1_TXN_ID=OTR_P2_TXN_ID; */ 

	/* EXEC SQL OPEN c_cursor_gettxnrelation; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "select x1 . * from ( select otr_party_type , otr_p1_txn_id , otr_p2_txn_\
id , otr_txn_level , otr_relation_type , oth_txn_code , tc_ofl_is_void from \
ol_txn_relation , ol_txn_header , txn_code , ol_batch_txn_relation where otr\
_relation_type != 'V' and otr_p1_txn_id = oth_txn_id and oth_txn_code = tc_c\
ode and obtr_batch_id = :b0 and obtr_txn_level = 'T' and obtr_txn_id in ( ot\
r_p1_txn_id , otr_p2_txn_id ) and otr_party_type = 'P' and otr_txn_level = '\
T' ) x1 where otr_relation_type != 'V' connect by prior OTR_P2_TXN_ID = OTR_\
P1_TXN_ID union select x1 . * from ( select otr_party_type , otr_p1_txn_id ,\
 otr_p2_txn_id , otr_txn_level , otr_relation_type , oth_txn_code , tc_ofl_i\
s_void from ol_txn_relation , ol_txn_header , txn_code , ol_batch_txn_relati\
on where otr_relation_type != 'V' and otr_p1_txn_id = oth_txn_id and oth_txn\
_code = tc_code and obtr_batch_id = :b0 and obtr_txn_level = 'T' and obtr_tx\
n_id in ( otr_p1_txn_id , otr_p2_txn_id ) and otr_party_type = 'P' and otr_t\
xn_level = 'T' ) x1 where otr_relation_t");
 sqlstm.stmt = sq0004;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )208;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
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
 if (sqlca.sqlcode < 0) goto gettxnrelationbybatchid_error;
}


	
	for (;;) {
                /* EXEC SQL FETCH c_cursor_gettxnrelation
                INTO	:v_party_type:ind_party_type,
			:v_p1_txn_id:ind_p1_txn_id,
			:v_p2_txn_id:ind_p2_txn_id,
			:v_txn_level:ind_txn_level,
			:v_relation_type:ind_relation_type; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 7;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )231;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_party_type;
                sqlstm.sqhstl[0] = (unsigned long )1;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_party_type;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_p1_txn_id;
                sqlstm.sqhstl[1] = (unsigned long )19;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_p1_txn_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_p2_txn_id;
                sqlstm.sqhstl[2] = (unsigned long )19;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_p2_txn_id;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_level;
                sqlstm.sqhstl[3] = (unsigned long )1;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_txn_level;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_relation_type;
                sqlstm.sqhstl[4] = (unsigned long )1;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_relation_type;
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
                if (sqlca.sqlcode < 0) goto gettxnrelationbybatchid_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }
	
		iCnt++;
	
                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash, 0);

		// party_type
		if (ind_party_type >= 0) {
			PutField_Char(myHash, "party_type",v_party_type);
DEBUGLOG(("GetTxnRelationByBatchId party_type = [%c]\n", v_party_type));
		}

                // p1_txn_id
                if (ind_p1_txn_id >= 0) {
                        v_p1_txn_id.arr[v_p1_txn_id.len] = '\0';
                        PutField_CString(myHash, "p1_txn_id", (const char*)v_p1_txn_id.arr);
DEBUGLOG(("GetTxnRelationByBatchId p1_txn_id = [%s]\n", (const char*)v_p1_txn_id.arr));
                }

                // p2_txn_id
                if (ind_p2_txn_id >= 0) {
                        v_p2_txn_id.arr[v_p2_txn_id.len] = '\0';
                        PutField_CString(myHash, "p2_txn_id", (const char*)v_p2_txn_id.arr);
DEBUGLOG(("GetTxnRelationByBatchId p2_txn_id = [%s]\n", (const char*)v_p2_txn_id.arr));
                }

		// txn_leven
		if (ind_txn_level >= 0) {
			PutField_Char(myHash, "txn_level",v_txn_level);
DEBUGLOG(("GetTxnRelationByBatchId txn_level = [%c]\n", v_txn_level));
		}

		// relation_type
		if (ind_relation_type >= 0) {
			PutField_Char(myHash, "relation_type",v_relation_type);
DEBUGLOG(("GetTxnRelationByBatchId relation_type = [%c]\n", v_relation_type));
		}

                RecordSet_Add(rRecordSet, myHash);
        }

        /* EXEC SQL CLOSE c_cursor_gettxnrelation; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )266;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto gettxnrelationbybatchid_error;
}



	if (iCnt > 0) {
                iRet = PD_FOUND;
DEBUGLOG(("GetTxnRelationByBatchId FOUND\n"));
        } else {
                iRet = PD_NOT_FOUND;
DEBUGLOG(("GetTxnRelationByBatchId NOT FOUND!!!\n"));
        }


DEBUGLOG(("GetTxnRelationByBatchId: Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

gettxnrelationbybatchid_error:
DEBUGLOG(("gettxnrelationbybatchid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLTxnRelation getp1txnid_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        /* EXEC SQL CLOSE c_cursor_gettxnrelation; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )281;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto gettxnrelationbybatchid_error;
}


        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int FindVoidTxnCount(const hash_t* hRls)
{
	int iRet = PD_NOT_FOUND;

        char *csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO find_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

                char            hv_relation_type;

                int		vCnt;
        /* EXEC SQL END DECLARE SECTION; */ 


// txn_id 
        if (GetField_CString(hRls,"txn_id",&csTmp)) {
                hv_txn_id.len = strlen(csTmp);
                strncpy((char*)hv_txn_id.arr, csTmp, hv_txn_id.len);
DEBUGLOG(("FindVoidTxnCount: txn_id = [%s]\n",(char*)hv_txn_id.arr));
        }

// relation_type 
        hv_relation_type = 'V';

	/* EXEC SQL	SELECT  count(1)
			INTO	vCnt
			FROM    ol_txn_relation
			WHERE   otr_relation_type = :hv_relation_type
			AND	(otr_p1_txn_id = :hv_txn_id OR
				 otr_p2_txn_id = :hv_txn_id); */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count ( 1 ) INTO :b0 FROM ol_txn_relation WHERE otr_\
relation_type = :b1 AND ( otr_p1_txn_id = :b2 OR otr_p2_txn_id = :b2 ) ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )296;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&vCnt;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_relation_type;
 sqlstm.sqhstl[1] = (unsigned long )1;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[2] = (unsigned long )18;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[3] = (unsigned long )18;
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
 if (sqlca.sqlcode < 0) goto find_error;
}


	
        if (vCnt > 0) {
                iRet = PD_FOUND;
DEBUGLOG(("FindVoidTxnCount FOUND\n"));
        } else {
                iRet = PD_NOT_FOUND;
DEBUGLOG(("FindVoidTxnCount NOT FOUND!!!\n"));
        }

DEBUGLOG(("FindVoidTxnCount: Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

find_error:
DEBUGLOG(("find_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLTxnRelation find_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int CheckIsBalTransBatch(const char *csBatchId)
{
	int iRet = PD_FALSE;

	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;

		char	hv_txn_level;
		char	hv_relation_type;
		char	hv_party_type;

		int	vCnt;
	/* EXEC SQL END DECLARE SECTION; */ 


// batch_id
	hv_batch_id.len = strlen(csBatchId);
	strncpy((char*)hv_batch_id.arr, csBatchId, hv_batch_id.len);
DEBUGLOG(("CheckIsBalTransBatch batch_id = [%s]\n",(char*)hv_batch_id.arr));

	hv_txn_level = 'T';
	hv_relation_type = 'B';
	hv_party_type = 'P';

	/* EXEC SQL	SELECT  count(distinct(obtr_batch_id))
			INTO	vCnt
			FROM	OL_TXN_RELATION, OL_BATCH_TXN_RELATION
			WHERE	OTR_TXN_LEVEL = :hv_txn_level
			  AND	OTR_RELATION_TYPE = :hv_relation_type
			  AND	OTR_PARTY_TYPE = :hv_party_type
			  AND	OBTR_BATCH_ID = :hv_batch_id
			  AND	OBTR_TXN_ID IN (OTR_P1_TXN_ID,OTR_P2_TXN_ID); */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count ( distinct ( obtr_batch_id ) ) INTO :b0 FROM O\
L_TXN_RELATION , OL_BATCH_TXN_RELATION WHERE OTR_TXN_LEVEL = :b1 AND OTR_RELA\
TION_TYPE = :b2 AND OTR_PARTY_TYPE = :b3 AND OBTR_BATCH_ID = :b4 AND OBTR_TXN\
_ID IN ( OTR_P1_TXN_ID , OTR_P2_TXN_ID ) ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )327;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&vCnt;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_level;
 sqlstm.sqhstl[1] = (unsigned long )1;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_relation_type;
 sqlstm.sqhstl[2] = (unsigned long )1;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_party_type;
 sqlstm.sqhstl[3] = (unsigned long )1;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[4] = (unsigned long )18;
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
 if (sqlca.sqlcode < 0) goto sql_error;
}



	if (vCnt == 1) {
		iRet = PD_TRUE;
DEBUGLOG(("CheckIsBalTransBatch found one record, it's bal-transfer batch\n"));
	}

DEBUGLOG(("CheckIsBalTransBatch: Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

sql_error:
DEBUGLOG(("sql_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLTxnRelation sql_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int GetRelatedTxnId(const hash_t* hRls, recordset_t* rRecordSet)
{
	int iRet = PD_FOUND;
        
	int iCnt = 0;

        char *csTmp;

        hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getrelatedtxnid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


		/* varchar		v_related_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_related_txn_id;

                short           ind_related_txn_id = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


// txn_id
	if (GetField_CString(hRls, "txn_seq", &csTmp)) {
		hv_txn_id.len = strlen(csTmp);
		strncpy((char*)hv_txn_id.arr, csTmp, hv_txn_id.len);
DEBUGLOG(("GetRelatedTxnId txn_id = [%s]\n",(char*)hv_txn_id.arr));
	}

	/* EXEC SQL DECLARE c_cursor_getrelatedtxnid CURSOR FOR
		SELECT	otr_p2_txn_id AS otr_txn_id
		FROM	ol_txn_relation
		WHERE	otr_p1_txn_id = :hv_txn_id
		AND	otr_relation_type = 'B'
		UNION
		SELECT	otr_p1_txn_id AS otr_txn_id
		FROM	ol_txn_relation
		WHERE	otr_p2_txn_id = :hv_txn_id
		AND	otr_relation_type = 'B'; */ 

	/* EXEC SQL OPEN c_cursor_getrelatedtxnid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0007;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )362;
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
 if (sqlca.sqlcode < 0) goto getrelatedtxnid_error;
}


	
	for (;;) {
                /* EXEC SQL FETCH c_cursor_getrelatedtxnid
                INTO	:v_related_txn_id:ind_related_txn_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 7;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )385;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_related_txn_id;
                sqlstm.sqhstl[0] = (unsigned long )19;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_related_txn_id;
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
                if (sqlca.sqlcode < 0) goto getrelatedtxnid_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }
	
		iCnt++;
	
                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash, 0);

                // related_txn_id
                if (ind_related_txn_id >= 0) {
                        v_related_txn_id.arr[v_related_txn_id.len] = '\0';
                        PutField_CString(myHash, "related_txn_seq", (const char*)v_related_txn_id.arr);
DEBUGLOG(("GetRelatedTxnId related_txn_id = [%s]\n", (const char*)v_related_txn_id.arr));
                }

                RecordSet_Add(rRecordSet, myHash);
        }

        /* EXEC SQL CLOSE c_cursor_getrelatedtxnid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )404;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getrelatedtxnid_error;
}



	if (iCnt > 0) {
                iRet = PD_FOUND;
DEBUGLOG(("GetRelatedTxnId FOUND\n"));
        } else {
                iRet = PD_NOT_FOUND;
DEBUGLOG(("GetRelatedTxnId NOT FOUND!!!\n"));
        }


DEBUGLOG(("GetRelatedTxnId: Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

getrelatedtxnid_error:
DEBUGLOG(("getrelatedtxnid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLTxnRelation getrelatedtxnid_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        /* EXEC SQL CLOSE c_cursor_getrelatedtxnid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )419;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getrelatedtxnid_error;
}


        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int GetVoidTxnId(const hash_t* hRls, recordset_t* rRecordSet)
{
	int iRet = PD_FOUND;
        
	int iCnt = 0;

        char *csTmp;

        hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getvoidtxnid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


		/* varchar		v_void_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_void_txn_id;

                short           ind_void_txn_id = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


// txn_id
	if (GetField_CString(hRls, "txn_seq", &csTmp)) {
		hv_txn_id.len = strlen(csTmp);
		strncpy((char*)hv_txn_id.arr, csTmp, hv_txn_id.len);
DEBUGLOG(("GetVoidTxnId txn_id = [%s]\n",(char*)hv_txn_id.arr));
	}

	/* EXEC SQL DECLARE c_cursor_getvoidtxnid CURSOR FOR
		SELECT	otr_p2_txn_id AS otr_txn_id
		FROM	ol_txn_relation
		WHERE	otr_p1_txn_id = :hv_txn_id
		AND	otr_relation_type = 'V'
		UNION
		SELECT	otr_p1_txn_id AS otr_txn_id
		FROM	ol_txn_relation
		WHERE	otr_p2_txn_id = :hv_txn_id
		AND	otr_relation_type = 'V'; */ 

	/* EXEC SQL OPEN c_cursor_getvoidtxnid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0008;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )434;
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
 if (sqlca.sqlcode < 0) goto getvoidtxnid_error;
}


	
	for (;;) {
                /* EXEC SQL FETCH c_cursor_getvoidtxnid
                INTO	:v_void_txn_id:ind_void_txn_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 7;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )457;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_void_txn_id;
                sqlstm.sqhstl[0] = (unsigned long )19;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_void_txn_id;
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
                if (sqlca.sqlcode < 0) goto getvoidtxnid_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }
	
		iCnt++;
	
                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash, 0);

                // void_txn_id
                if (ind_void_txn_id >= 0) {
                        v_void_txn_id.arr[v_void_txn_id.len] = '\0';
                        PutField_CString(myHash, "void_txn_seq", (const char*)v_void_txn_id.arr);
DEBUGLOG(("GetVoidTxnId void_txn_id = [%s]\n", (const char*)v_void_txn_id.arr));
                }

                RecordSet_Add(rRecordSet, myHash);
        }

        /* EXEC SQL CLOSE c_cursor_getvoidtxnid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )476;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getvoidtxnid_error;
}



	if (iCnt > 0) {
                iRet = PD_FOUND;
DEBUGLOG(("GetVoidTxnId FOUND\n"));
        } else {
                iRet = PD_NOT_FOUND;
DEBUGLOG(("GetVoidTxnId NOT FOUND!!!\n"));
        }


DEBUGLOG(("GetVoidTxnId: Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

getvoidtxnid_error:
DEBUGLOG(("getvoidtxnid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLTxnRelation getrelatedtxnid_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        /* EXEC SQL CLOSE c_cursor_getvoidtxnid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )491;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getvoidtxnid_error;
}


        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int CheckIsBalTransP1TxnId(const hash_t* hRls)
{
	int iRet = PD_FALSE;

	char *csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO checkp1txnid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

                char    hv_txn_level;
                char    hv_relation_type;

                int     vCnt;
        /* EXEC SQL END DECLARE SECTION; */ 


// txn_id
        if (GetField_CString(hRls, "txn_seq", &csTmp)) {
                hv_txn_id.len = strlen(csTmp);
                strncpy((char*)hv_txn_id.arr, csTmp, hv_txn_id.len);
DEBUGLOG(("CheckIsBalTransP1TxnId txn_id = [%s]\n",(char*)hv_txn_id.arr));
	}

        hv_txn_level = 'T';
        hv_relation_type = 'B';

        /* EXEC SQL        SELECT  count(1)
                        INTO    vCnt
                        FROM    OL_TXN_RELATION
                        WHERE   OTR_TXN_LEVEL = :hv_txn_level
                          AND   OTR_RELATION_TYPE = :hv_relation_type
                          AND   OTR_P1_TXN_ID = :hv_txn_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count ( 1 ) INTO :b0 FROM OL_TXN_RELATION WHE\
RE OTR_TXN_LEVEL = :b1 AND OTR_RELATION_TYPE = :b2 AND OTR_P1_TXN_ID = :b3 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )506;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&vCnt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_level;
        sqlstm.sqhstl[1] = (unsigned long )1;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_relation_type;
        sqlstm.sqhstl[2] = (unsigned long )1;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_id;
        sqlstm.sqhstl[3] = (unsigned long )18;
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
        if (sqlca.sqlcode < 0) goto checkp1txnid_error;
}



        if (vCnt == 1) {
                iRet = PD_TRUE;
DEBUGLOG(("CheckIsBalTransP1TxnId found one record!!!\n"));
        }

DEBUGLOG(("CheckIsBalTransP1TxnId: Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

checkp1txnid_error:
DEBUGLOG(("checkp1txnid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLTxnRelation checkp1txnid_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int CheckIsBalTransP2TxnId(const hash_t* hRls)
{
	int iRet = PD_FALSE;

	char *csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO checkp2txnid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

                char    hv_txn_level;
                char    hv_relation_type;

                int     vCnt;
        /* EXEC SQL END DECLARE SECTION; */ 


// txn_id
        if (GetField_CString(hRls, "txn_seq", &csTmp)) {
                hv_txn_id.len = strlen(csTmp);
                strncpy((char*)hv_txn_id.arr, csTmp, hv_txn_id.len);
DEBUGLOG(("CheckIsBalTransP1TxnId txn_id = [%s]\n",(char*)hv_txn_id.arr));
	}

        hv_txn_level = 'T';
        hv_relation_type = 'B';

        /* EXEC SQL        SELECT  count(1)
                        INTO    vCnt
                        FROM    OL_TXN_RELATION
                        WHERE   OTR_TXN_LEVEL = :hv_txn_level
                          AND   OTR_RELATION_TYPE = :hv_relation_type
                          AND   OTR_P2_TXN_ID = :hv_txn_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count ( 1 ) INTO :b0 FROM OL_TXN_RELATION WHE\
RE OTR_TXN_LEVEL = :b1 AND OTR_RELATION_TYPE = :b2 AND OTR_P2_TXN_ID = :b3 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )537;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&vCnt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_level;
        sqlstm.sqhstl[1] = (unsigned long )1;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_relation_type;
        sqlstm.sqhstl[2] = (unsigned long )1;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_id;
        sqlstm.sqhstl[3] = (unsigned long )18;
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
        if (sqlca.sqlcode < 0) goto checkp2txnid_error;
}



        if (vCnt == 1) {
                iRet = PD_TRUE;
DEBUGLOG(("CheckIsBalTransP2TxnId found one record!!!\n"));
        }

DEBUGLOG(("CheckIsBalTransP2TxnId: Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

checkp2txnid_error:
DEBUGLOG(("checkp2txnid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLTxnRelation checkp2txnid_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int CheckIsP1VoidTxnId(const hash_t* hRls)
{
	int iRet = PD_FALSE;

        char *csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO chkisp1voidtxnid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

                char            hv_relation_type;

                int		vCnt;
        /* EXEC SQL END DECLARE SECTION; */ 


// txn_id 
        if (GetField_CString(hRls,"txn_id",&csTmp)) {
                hv_txn_id.len = strlen(csTmp);
                strncpy((char*)hv_txn_id.arr, csTmp, hv_txn_id.len);
DEBUGLOG(("CheckIsP1VoidTxnId: txn_id = [%s]\n",(char*)hv_txn_id.arr));
        }

// relation_type 
        hv_relation_type = 'V';

	/* EXEC SQL	SELECT  count(1)
			INTO	vCnt
			FROM    ol_txn_relation
			WHERE   otr_relation_type = :hv_relation_type
			AND	otr_p1_txn_id = :hv_txn_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count ( 1 ) INTO :b0 FROM ol_txn_relation WHERE otr_\
relation_type = :b1 AND otr_p1_txn_id = :b2 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )568;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&vCnt;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_relation_type;
 sqlstm.sqhstl[1] = (unsigned long )1;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[2] = (unsigned long )18;
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
 if (sqlca.sqlcode < 0) goto chkisp1voidtxnid_error;
}


	
        if (vCnt > 0) {
                iRet = PD_TRUE;
DEBUGLOG(("CheckIsP1VoidTxnId TRUE\n"));
        }

DEBUGLOG(("CheckIsP1VoidTxnId: Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

chkisp1voidtxnid_error:
DEBUGLOG(("find_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLTxnRelation chkisp1voidtxnid_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int CheckIsP2VoidedTxnId(const hash_t* hRls)
{
	int iRet = PD_FALSE;

        char *csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO chkisp2voidedtxnid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

                char            hv_relation_type;

                int		vCnt;
        /* EXEC SQL END DECLARE SECTION; */ 


// txn_id 
        if (GetField_CString(hRls,"txn_id",&csTmp)) {
                hv_txn_id.len = strlen(csTmp);
                strncpy((char*)hv_txn_id.arr, csTmp, hv_txn_id.len);
DEBUGLOG(("CheckIsP2VoidedTxnId: txn_id = [%s]\n",(char*)hv_txn_id.arr));
        }

// relation_type 
        hv_relation_type = 'V';

	/* EXEC SQL	SELECT  count(1)
			INTO	vCnt
			FROM    ol_txn_relation
			WHERE   otr_relation_type = :hv_relation_type
			AND	otr_p2_txn_id = :hv_txn_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count ( 1 ) INTO :b0 FROM ol_txn_relation WHERE otr_\
relation_type = :b1 AND otr_p2_txn_id = :b2 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )595;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&vCnt;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_relation_type;
 sqlstm.sqhstl[1] = (unsigned long )1;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[2] = (unsigned long )18;
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
 if (sqlca.sqlcode < 0) goto chkisp2voidedtxnid_error;
}


	
        if (vCnt > 0) {
                iRet = PD_TRUE;
DEBUGLOG(("CheckIsP2VoidedTxnId TRUE\n"));
        }

DEBUGLOG(("CheckIsP2VoidedTxnId: Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

chkisp2voidedtxnid_error:
DEBUGLOG(("find_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLTxnRelation chkisp2voidedtxnid_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

