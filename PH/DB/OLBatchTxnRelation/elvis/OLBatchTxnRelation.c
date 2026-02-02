
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
    "OLBatchTxnRelation.pc"
};


static unsigned int sqlctx = 158750107;


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
"SELECT obtr_txn_id FROM ol_batch_txn_relation WHERE obtr_batch_type = :b0 A\
ND obtr_batch_sub_type = :b1 AND obtr_batch_id = :b2 AND obtr_txn_level = :b3\
 ORDER BY obtr_relation_timestamp DESC            ";

 static char *sq0003 = 
"SELECT obtr_batch_type , obtr_batch_sub_type , obtr_batch_id FROM ol_batch_\
txn_relation WHERE obtr_txn_level = :b0 AND obtr_txn_id = :b1 ORDER BY obtr_r\
elation_timestamp DESC            ";

 static char *sq0005 = 
"SELECT count ( 1 ) FROM ol_batch_txn_relation LEFT JOIN ol_txn_header ON ob\
tr_txn_id = oth_txn_id WHERE obtr_batch_type = 'G' AND obtr_txn_level = 'T' A\
ND obtr_batch_id = :b0 AND oth_txn_code = 'VOD' UNION SELECT count ( 1 ) FROM\
 ol_batch_txn_relation LEFT JOIN ol_baid_txn ON obtr_txn_id = obt_txn_id WHER\
E obtr_batch_type = 'G' AND obtr_txn_level = 'S' AND obtr_batch_id = :b0 AND \
obt_txn_code = 'VOD'            ";

 static char *sq0006 = 
"SELECT count ( 1 ) FROM ol_batch_txn_relation LEFT JOIN ol_txn_header ON ob\
tr_txn_id = oth_txn_id WHERE obtr_batch_type = 'G' AND obtr_txn_level = 'T' A\
ND obtr_batch_id = :b0 AND oth_txn_code in ( 'OPT' , 'PPT' , 'PST' ) UNION SE\
LECT count ( 1 ) FROM ol_batch_txn_relation LEFT JOIN ol_baid_txn ON obtr_txn\
_id = obt_txn_id WHERE obtr_batch_type = 'G' AND obtr_txn_level = 'S' AND obt\
r_batch_id = :b0 AND obt_txn_code in ( 'OPT' , 'PPT' , 'PST' )            ";

 static char *sq0007 = 
"SELECT count ( 1 ) FROM ol_batch_txn_relation LEFT JOIN ol_txn_header ON ob\
tr_txn_id = oth_txn_id WHERE obtr_batch_type in ( 'G' , 'C' ) AND obtr_txn_le\
vel = 'T' AND obtr_batch_id = :b0 AND oth_txn_code in ( 'CPO' , 'CPD' , 'PPC'\
 , 'CGP' , 'OPR' ) UNION SELECT count ( 1 ) FROM ol_batch_txn_relation LEFT J\
OIN ol_baid_txn ON obtr_txn_id = obt_txn_id WHERE obtr_batch_type in ( 'G' , \
'C' ) AND obtr_txn_level = 'S' AND obtr_batch_id = :b0 AND obt_txn_code in ( \
'CPO' , 'CPD' , 'PPC' , 'CGP' , 'OPR' )            ";

 static char *sq0010 = 
"SELECT obtr_batch_type , obtr_batch_sub_type FROM ol_batch_txn_relation WHE\
RE obtr_batch_id = :b0            ";

 static char *sq0011 = 
"SELECT obtr_batch_type , obtr_batch_sub_type , obtr_batch_id FROM ol_batch_\
txn_relation WHERE obtr_txn_level = :b0 AND obtr_txn_id = :b1 ORDER BY obtr_r\
elation_timestamp ASC            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,326,0,6,148,0,0,9,9,0,1,0,2,3,0,0,1,1,0,0,1,9,0,0,1,1,0,0,1,9,0,0,1,1,
0,0,1,3,0,0,1,3,0,0,1,9,0,0,
56,0,0,2,202,0,9,244,0,2049,4,4,0,1,0,1,1,0,0,1,1,0,0,1,9,0,0,1,1,0,0,
87,0,0,2,0,0,13,247,0,0,1,0,0,1,0,2,9,0,0,
106,0,0,2,0,0,15,267,0,0,0,0,0,1,0,
121,0,0,2,0,0,15,277,0,0,0,0,0,1,0,
136,0,0,3,186,0,9,328,0,2049,2,2,0,1,0,1,1,0,0,1,9,0,0,
159,0,0,3,0,0,13,331,0,0,3,0,0,1,0,2,1,0,0,2,1,0,0,2,9,0,0,
186,0,0,3,0,0,15,365,0,0,0,0,0,1,0,
201,0,0,3,0,0,15,375,0,0,0,0,0,1,0,
216,0,0,4,104,0,4,410,0,0,3,2,0,1,0,2,3,0,0,1,1,0,0,1,9,0,0,
243,0,0,5,415,0,9,470,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
266,0,0,5,0,0,13,473,0,0,1,0,0,1,0,2,3,0,0,
285,0,0,5,0,0,15,483,0,0,0,0,0,1,0,
300,0,0,5,0,0,15,498,0,0,0,0,0,1,0,
315,0,0,6,457,0,9,541,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
338,0,0,6,0,0,13,544,0,0,1,0,0,1,0,2,3,0,0,
357,0,0,6,0,0,15,554,0,0,0,0,0,1,0,
372,0,0,6,0,0,15,569,0,0,0,0,0,1,0,
387,0,0,7,511,0,9,612,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
410,0,0,7,0,0,13,615,0,0,1,0,0,1,0,2,3,0,0,
429,0,0,7,0,0,15,625,0,0,0,0,0,1,0,
444,0,0,7,0,0,15,640,0,0,0,0,0,1,0,
459,0,0,8,212,0,4,701,0,0,7,6,0,1,0,2,3,0,0,1,1,0,0,1,1,0,0,1,9,0,0,1,1,0,0,1,
9,0,0,1,3,0,0,
502,0,0,9,212,0,4,782,0,0,7,6,0,1,0,2,3,0,0,1,1,0,0,1,1,0,0,1,9,0,0,1,1,0,0,1,
9,0,0,1,1,0,0,
545,0,0,10,109,0,9,839,0,2049,1,1,0,1,0,1,9,0,0,
564,0,0,10,0,0,13,842,0,0,2,0,0,1,0,2,1,0,0,2,1,0,0,
587,0,0,10,0,0,15,869,0,0,0,0,0,1,0,
602,0,0,10,0,0,15,887,0,0,0,0,0,1,0,
617,0,0,11,185,0,9,937,0,2049,2,2,0,1,0,1,1,0,0,1,9,0,0,
640,0,0,11,0,0,13,940,0,0,3,0,0,1,0,2,1,0,0,2,1,0,0,2,9,0,0,
667,0,0,11,0,0,15,974,0,0,0,0,0,1,0,
682,0,0,11,0,0,15,984,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/01/09              Dirk Wong
Add GetTxnId, GetBatchId and CheckSingleBatchId	   2015/01/14		   Elvis Wong	
Add CheckIsHoldDepositBatch			   2015/03/20		   Elvis Wong
Add CheckIsPSPSettlementBatch			   2015/03/31		   Elvis Wong
Add CheckIsProviderChargeBatch			   	
Add CheckIsInputTxnId				   
Add CheckIsReviveTxnId				   
Add GetBatchSubType	
Add GetBatchIdByRTAscOrder		  	   
Add GetNumOfBatchId
Del CheckSingleBatchId				   2015/04/28		   Elvis Wong	
Add batch_sub_type and txn_type			 
Modify GetNumOfBatchId
and GetTxnId
and GetBatchId and GetBatchIdByRTAscOrder  	   2015/05/13              Elvis Wong	
Change GetBatchSubType to GetBatchTypeInfo
Modify CheckIsInputTxnId
Change CheckIsReviveTxnId to CheckIsRegenTxnId
Del txn_type
Add is_input_txn and is_regen_txn		   2015/05/14              Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "OLBatchTxnRelation.h"
#include "common.h"
#include "internal.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void OLBatchTxnRelation(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const hash_t *hRls)
{
	int	iTmp;

	char	cTmp;
	char*	csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		char		hv_batch_type;
		char		hv_batch_sub_type;
		/* varchar		hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;

		char		hv_txn_level;
		int		hv_is_input_txn;
		int		hv_is_regen_txn;
		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		/* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_batch_type = -1;
		short		ind_batch_sub_type = -1;
		short		ind_batch_id = -1;
		short		ind_txn_level = -1;
		short		ind_is_input_txn = -1;
		short		ind_is_regen_txn = -1;
		short		ind_txn_id = -1;
		short		ind_create_user = -1;

		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("Add: Begin\n"));

	if (GetField_Char(hRls,"batch_type",&cTmp)) {
		hv_batch_type = cTmp;
		ind_batch_type = 0;
DEBUGLOG(("Add: batch_type = [%c]\n",hv_batch_type));
	}

	if (GetField_CString(hRls,"batch_id",&csTmp)) {
		hv_batch_id.len = strlen(csTmp);
		strncpy((char*)hv_batch_id.arr, csTmp, hv_batch_id.len);
		ind_batch_id = 0;
DEBUGLOG(("Add: batch_id = [%s]\n",(char*)hv_batch_id.arr));
	}

	if (GetField_Char(hRls,"txn_level",&cTmp)) {
		hv_txn_level = cTmp;
		ind_txn_level = 0;
DEBUGLOG(("Add: txn_level =  [%c]\n",hv_txn_level));
	}

	if (GetField_CString(hRls,"txn_id",&csTmp)) {
		hv_txn_id.len = strlen(csTmp);
		strncpy((char*)hv_txn_id.arr, csTmp, hv_txn_id.len);
		ind_txn_id = 0;
DEBUGLOG(("Add: txn_id = [%s]\n",(char*)hv_txn_id.arr));
	}

	if (GetField_Char(hRls,"batch_sub_type",&cTmp)) {
                hv_batch_sub_type = cTmp;
                ind_batch_sub_type = 0;
DEBUGLOG(("Add: batch_sub_type = [%c]\n",hv_batch_sub_type));
        } else {
                hv_batch_sub_type = 'R';
                ind_batch_sub_type = 0;
DEBUGLOG(("Add: batch_sub_type = [%c]\n",hv_batch_sub_type));
        }

	if (GetField_Int(hRls,"is_input_txn",&iTmp)) {
                hv_is_input_txn = iTmp;
                ind_is_input_txn = 0;
DEBUGLOG(("Add: is_input_txn =  [%d]\n",hv_is_input_txn));
        } else {
                hv_is_input_txn = 0;
                ind_is_input_txn = 0;
DEBUGLOG(("Add: is_input_txn =  [%d]\n",hv_is_input_txn));
        }

	if (GetField_Int(hRls,"is_regen_txn",&iTmp)) {
                hv_is_regen_txn = iTmp;
                ind_is_regen_txn = 0;
DEBUGLOG(("Add: is_regen_txn =  [%d]\n",hv_is_regen_txn));
        } else {
                hv_is_regen_txn = 0;
                ind_is_regen_txn = 0;
DEBUGLOG(("Add: is_regen_txn =  [%d]\n",hv_is_regen_txn));
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
			:hv_return_value := sp_ol_batch_tx_relation_insert(
						:hv_batch_type:ind_batch_type,
						:hv_batch_id:ind_batch_id,
						:hv_txn_level:ind_txn_level,
						:hv_txn_id:ind_txn_id,
						:hv_batch_sub_type:ind_batch_sub_type,
						:hv_is_input_txn:ind_is_input_txn,
						:hv_is_regen_txn:ind_is_regen_txn,
                                                :hv_create_user:ind_create_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_batch_tx_relation_insert ( \
:hv_batch_type:ind_batch_type , :hv_batch_id:ind_batch_id , :hv_txn_level:ind\
_txn_level , :hv_txn_id:ind_txn_id , :hv_batch_sub_type:ind_batch_sub_type , \
:hv_is_input_txn:ind_is_input_txn , :hv_is_regen_txn:ind_is_regen_txn , :hv_c\
reate_user:ind_create_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_type;
 sqlstm.sqhstl[1] = (unsigned long )1;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_batch_type;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[2] = (unsigned long )18;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_batch_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_level;
 sqlstm.sqhstl[3] = (unsigned long )1;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_txn_level;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[4] = (unsigned long )18;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_txn_id;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_batch_sub_type;
 sqlstm.sqhstl[5] = (unsigned long )1;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_batch_sub_type;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_is_input_txn;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_is_input_txn;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_is_regen_txn;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_is_regen_txn;
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
ERRLOG("OLBatchTxnRelation_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	} 

	if (hv_return_value == SP_ERR)  {
ERRLOG("OLBatchTxnRelation_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBatchTxnRelation_Add: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int GetTxnId(const hash_t* hRls, recordset_t* rRecordSet)
{
        int iRet = PD_OK;

        char *csTmp;
        char cTmp;

        hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO gettxnid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		char            hv_batch_type;
		char            hv_batch_sub_type;
                /* varchar         hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;

                char            hv_txn_level;

                /* varchar         v_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_txn_id;

                short           ind_txn_id = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


/* batch_type */
	if (GetField_Char(hRls, "batch_type", &cTmp)) {
                hv_batch_type = cTmp;
DEBUGLOG(("GetTxnId: batch_type = [%c]\n", hv_batch_type));
        }

/* batch_sub_type */
        if (GetField_Char(hRls, "batch_sub_type", &cTmp)) {
                hv_batch_sub_type = cTmp;
DEBUGLOG(("GetTxnId: batch_sub_type = [%c]\n", hv_batch_sub_type));
        }

/* batch_id */
        if (GetField_CString(hRls,"batch_id",&csTmp)) {
                hv_batch_id.len = strlen(csTmp);
                strncpy((char*)hv_batch_id.arr, csTmp, hv_batch_id.len);
DEBUGLOG(("GetTxnId: batch_id = [%s]\n",(char*)hv_batch_id.arr));
        }

/* txn_level */
	if (GetField_Char(hRls, "txn_level", &cTmp)) {
                hv_txn_level = cTmp;
DEBUGLOG(("GetTxnId: txn_level = [%c]\n", hv_txn_level));
        }

	/* EXEC SQL DECLARE c_cursor_gettxnid CURSOR FOR
                SELECT  obtr_txn_id
                FROM    ol_batch_txn_relation
                WHERE   obtr_batch_type = :hv_batch_type
                AND   	obtr_batch_sub_type = :hv_batch_sub_type
                AND     obtr_batch_id = :hv_batch_id
		AND	obtr_txn_level = :hv_txn_level
		ORDER BY obtr_relation_timestamp DESC; */ 

        /* EXEC SQL OPEN c_cursor_gettxnid; */ 

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
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_batch_type;
        sqlstm.sqhstl[0] = (unsigned long )1;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_sub_type;
        sqlstm.sqhstl[1] = (unsigned long )1;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[2] = (unsigned long )18;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_level;
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
        if (sqlca.sqlcode < 0) goto gettxnid_error;
}



	for (;;) {
                /* EXEC SQL FETCH c_cursor_gettxnid
                INTO	:v_txn_id:ind_txn_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 9;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )87;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_id;
                sqlstm.sqhstl[0] = (unsigned long )18;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_txn_id;
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
                if (sqlca.sqlcode < 0) goto gettxnid_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash, 0);

		// txn_id
                if (ind_txn_id >= 0) {
                        v_txn_id.arr[v_txn_id.len] = '\0';
                        PutField_CString(myHash, "txn_id", (const char*)v_txn_id.arr);
DEBUGLOG(("GetTxnId: txn_id = [%s]\n", (const char*)v_txn_id.arr));
                }

                RecordSet_Add(rRecordSet, myHash);
        }

	/* EXEC SQL CLOSE c_cursor_gettxnid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )106;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto gettxnid_error;
}



DEBUGLOG(("GetTxnId: Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

gettxnid_error:
DEBUGLOG(("gettxnid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBatchTxnRelation gettxnid_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        /* EXEC SQL CLOSE c_cursor_gettxnid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )121;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto gettxnid_error;
}


        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int GetBatchId(const hash_t* hRls, recordset_t* rRecordSet)
{
        int iRet = PD_OK;

        char *csTmp;
        char cTmp;

        hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getbatchid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                char            hv_txn_level;
                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


                char            v_batch_type;
                char            v_batch_sub_type;
                /* varchar         v_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_batch_id;

                short           ind_batch_type = -1;
                short           ind_batch_sub_type = -1;
                short           ind_batch_id = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


/* txn_level */
	if (GetField_Char(hRls, "txn_level", &cTmp)) {
                hv_txn_level = cTmp;
DEBUGLOG(("GetBatchId: txn_level = [%c]\n", hv_txn_level));
        }

/* txn_id */
        if (GetField_CString(hRls,"txn_id",&csTmp)) {
                hv_txn_id.len = strlen(csTmp);
                strncpy((char*)hv_txn_id.arr, csTmp, hv_txn_id.len);
DEBUGLOG(("GetBatchId: txn_id = [%s]\n",(char*)hv_txn_id.arr));
        }

	/* EXEC SQL DECLARE c_cursor_getbatchid CURSOR FOR
                SELECT  obtr_batch_type,
			obtr_batch_sub_type,
			obtr_batch_id
                FROM    ol_batch_txn_relation
                WHERE   obtr_txn_level = :hv_txn_level
                AND     obtr_txn_id = :hv_txn_id
		ORDER BY obtr_relation_timestamp DESC; */ 

        /* EXEC SQL OPEN c_cursor_getbatchid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0003;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )136;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_txn_level;
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
        if (sqlca.sqlcode < 0) goto getbatchid_error;
}



	for (;;) {
                /* EXEC SQL FETCH c_cursor_getbatchid
                INTO    :v_batch_type:ind_batch_type,
			:v_batch_sub_type:ind_batch_sub_type,
			:v_batch_id:ind_batch_id; */ 

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
                sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_type;
                sqlstm.sqhstl[0] = (unsigned long )1;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_batch_type;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_batch_sub_type;
                sqlstm.sqhstl[1] = (unsigned long )1;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_batch_sub_type;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_batch_id;
                sqlstm.sqhstl[2] = (unsigned long )18;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_batch_id;
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



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash, 0);
		
		// batch_type
		if (ind_batch_type >= 0) {
                        PutField_Char(myHash, "batch_type",v_batch_type);
DEBUGLOG(("GetBatchId batch_type = [%c]\n", v_batch_type));
                }

                // batch_sub_type
                if (ind_batch_sub_type >= 0) {
                        PutField_Char(myHash, "batch_sub_type",v_batch_sub_type);
DEBUGLOG(("GetBatchId batch_sub_type = [%c]\n", v_batch_sub_type));
                }

		// batch_id
                if (ind_batch_id >= 0) {
                        v_batch_id.arr[v_batch_id.len] = '\0';
                        PutField_CString(myHash, "batch_id", (const char*)v_batch_id.arr);
DEBUGLOG(("GetBatchId: batch_id = [%s]\n", (const char*)v_batch_id.arr));
                }

                RecordSet_Add(rRecordSet, myHash);
        }

	/* EXEC SQL CLOSE c_cursor_getbatchid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )186;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getbatchid_error;
}



DEBUGLOG(("GetBatchId: Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

getbatchid_error:
DEBUGLOG(("getbatchid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBatchTxnRelation getbatchid_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        /* EXEC SQL CLOSE c_cursor_getbatchid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )201;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getbatchid_error;
}


        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int GetNumOfBatchId(hash_t* hRls)
{
	int iRet = PD_ERR;

        char *csTmp;
        char cTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO getnumofbatchid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                char            hv_txn_level;
                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


		int     	v_cnt;
        /* EXEC SQL END DECLARE SECTION; */ 


/* txn_level */
        if (GetField_Char(hRls, "txn_level", &cTmp)) {
                hv_txn_level = cTmp;
DEBUGLOG(("GetNumOfBatchId: txn_level = [%c]\n", hv_txn_level));
        }

/* txn_id */
        if (GetField_CString(hRls,"txn_id",&csTmp)) {
                hv_txn_id.len = strlen(csTmp);
                strncpy((char*)hv_txn_id.arr, csTmp, hv_txn_id.len);
DEBUGLOG(("GetNumOfBatchId: txn_id = [%s]\n",(char*)hv_txn_id.arr));
        }

        /* EXEC SQL        SELECT  COUNT(*)
                        INTO    :v_cnt
                        FROM    ol_batch_txn_relation
                        WHERE   obtr_txn_level = :hv_txn_level
                	AND     obtr_txn_id = :hv_txn_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select COUNT ( * ) INTO :b0 FROM ol_batch_txn_relati\
on WHERE obtr_txn_level = :b1 AND obtr_txn_id = :b2 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )216;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_level;
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
        if (sqlca.sqlcode < 0) goto getnumofbatchid_error;
}



        if (v_cnt>=0) {
                iRet = PD_OK;
		PutField_Int(hRls, "cnt", v_cnt);
DEBUGLOG(("GetNumOfBatchId: cnt = [%d]\n", v_cnt));
        }

DEBUGLOG(("GetNumOfBatchId() Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

getnumofbatchid_error:
DEBUGLOG(("getnumofbatchid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int CheckIsHoldDepositBatch(const char *csBatchId)
{
        int iRet = PD_FALSE;

        int iCnt = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO chkisholddsibatch_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar 	hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;


		int     vCnt;
        /* EXEC SQL END DECLARE SECTION; */ 


// batch_id
        hv_batch_id.len = strlen(csBatchId);
        strncpy((char*)hv_batch_id.arr, csBatchId, hv_batch_id.len);
DEBUGLOG(("CheckIsHoldDepositBatch batch_id = [%s]\n",(char*)hv_batch_id.arr));

        /* EXEC SQL DECLARE c_cursor_chkisholddsibatch CURSOR FOR
 		SELECT  count(1)
		FROM    ol_batch_txn_relation
		LEFT JOIN ol_txn_header
		ON       obtr_txn_id = oth_txn_id
		WHERE    obtr_batch_type = 'G'
		AND      obtr_txn_level = 'T'
		AND      obtr_batch_id = :hv_batch_id
		AND      oth_txn_code = 'VOD'
		UNION
		SELECT  count(1)
		FROM    ol_batch_txn_relation
		LEFT JOIN ol_baid_txn
		ON       obtr_txn_id = obt_txn_id
		WHERE    obtr_batch_type = 'G'
		AND      obtr_txn_level = 'S'
		AND      obtr_batch_id = :hv_batch_id
		AND      obt_txn_code = 'VOD'; */ 

        /* EXEC SQL OPEN c_cursor_chkisholddsibatch; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0005;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )243;
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
        if (sqlca.sqlcode < 0) goto chkisholddsibatch_error;
}



        for (;;) {
                /* EXEC SQL FETCH c_cursor_chkisholddsibatch
                INTO    :vCnt; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 9;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )266;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&vCnt;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
                if (sqlca.sqlcode < 0) goto chkisholddsibatch_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                iCnt += vCnt;
        }
	
	/* EXEC SQL CLOSE c_cursor_chkisholddsibatch; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )285;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto chkisholddsibatch_error;
}



        if (iCnt > 0) {
                iRet = PD_TRUE;
DEBUGLOG(("CheckIsHoldDepositBatch found one record, it's hold deposit batch\n"));
        }

DEBUGLOG(("CheckIsHoldDepositBatch: Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

chkisholddsibatch_error:
DEBUGLOG(("chkisholddsibatch_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBatchTxnRelation chkisholddsibatch_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        /* EXEC SQL CLOSE c_cursor_chkisholddsibatch; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )300;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto chkisholddsibatch_error;
}


        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int CheckIsPSPSettlementBatch(const char *csBatchId)
{
        int iRet = PD_FALSE;

        int iCnt = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO chkispspsettbatch_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar 	hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;


		int     vCnt;
        /* EXEC SQL END DECLARE SECTION; */ 


// batch_id
        hv_batch_id.len = strlen(csBatchId);
        strncpy((char*)hv_batch_id.arr, csBatchId, hv_batch_id.len);
DEBUGLOG(("CheckIsPSPSettlementBatch batch_id = [%s]\n",(char*)hv_batch_id.arr));

        /* EXEC SQL DECLARE c_cursor_chkispspsettbatch CURSOR FOR
 		SELECT  count(1)
		FROM    ol_batch_txn_relation
		LEFT JOIN ol_txn_header
		ON       obtr_txn_id = oth_txn_id
		WHERE    obtr_batch_type = 'G'
		AND      obtr_txn_level = 'T'
		AND      obtr_batch_id = :hv_batch_id
		AND      oth_txn_code in ('OPT', 'PPT', 'PST')
		UNION
		SELECT  count(1)
		FROM    ol_batch_txn_relation
		LEFT JOIN ol_baid_txn
		ON       obtr_txn_id = obt_txn_id
		WHERE    obtr_batch_type = 'G'
		AND      obtr_txn_level = 'S'
		AND      obtr_batch_id = :hv_batch_id
		AND      obt_txn_code in ('OPT', 'PPT', 'PST'); */ 

        /* EXEC SQL OPEN c_cursor_chkispspsettbatch; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0006;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )315;
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
        if (sqlca.sqlcode < 0) goto chkispspsettbatch_error;
}



        for (;;) {
                /* EXEC SQL FETCH c_cursor_chkispspsettbatch
                INTO    :vCnt; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 9;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )338;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&vCnt;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
                if (sqlca.sqlcode < 0) goto chkispspsettbatch_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                iCnt += vCnt;
        }
	
	/* EXEC SQL CLOSE c_cursor_chkispspsettbatch; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )357;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto chkispspsettbatch_error;
}



        if (iCnt > 0) {
                iRet = PD_TRUE;
DEBUGLOG(("CheckIsPSPSettlementBatch found one record, it's psp settlement batch\n"));
        }

DEBUGLOG(("CheckIsPSPSettlementBatch: Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

chkispspsettbatch_error:
DEBUGLOG(("chkispspsettbatch_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBatchTxnRelation chkispspsettbatch_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        /* EXEC SQL CLOSE c_cursor_chkispspsettbatch; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )372;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto chkispspsettbatch_error;
}


        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int CheckIsProviderChargeBatch(const char *csBatchId)
{
        int iRet = PD_FALSE;

        int iCnt = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO chkispdrchrbatch_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar 	hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;


		int     vCnt;
        /* EXEC SQL END DECLARE SECTION; */ 


// batch_id
        hv_batch_id.len = strlen(csBatchId);
        strncpy((char*)hv_batch_id.arr, csBatchId, hv_batch_id.len);
DEBUGLOG(("CheckIsProviderChargeBatch batch_id = [%s]\n",(char*)hv_batch_id.arr));

        /* EXEC SQL DECLARE c_cursor_chkispdrchrbatch CURSOR FOR
 		SELECT  count(1)
		FROM    ol_batch_txn_relation
		LEFT JOIN ol_txn_header
		ON       obtr_txn_id = oth_txn_id
		WHERE    obtr_batch_type in ('G', 'C')
		AND      obtr_txn_level = 'T'
		AND      obtr_batch_id = :hv_batch_id
		AND      oth_txn_code in ('CPO', 'CPD', 'PPC', 'CGP', 'OPR')
		UNION
		SELECT  count(1)
		FROM    ol_batch_txn_relation
		LEFT JOIN ol_baid_txn
		ON       obtr_txn_id = obt_txn_id
		WHERE    obtr_batch_type in ('G', 'C')
		AND      obtr_txn_level = 'S'
		AND      obtr_batch_id = :hv_batch_id
		AND      obt_txn_code in ('CPO', 'CPD', 'PPC', 'CGP', 'OPR'); */ 

        /* EXEC SQL OPEN c_cursor_chkispdrchrbatch; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0007;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )387;
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
        if (sqlca.sqlcode < 0) goto chkispdrchrbatch_error;
}



        for (;;) {
                /* EXEC SQL FETCH c_cursor_chkispdrchrbatch
                INTO    :vCnt; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 9;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )410;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&vCnt;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
                if (sqlca.sqlcode < 0) goto chkispdrchrbatch_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                iCnt += vCnt;
        }
	
	/* EXEC SQL CLOSE c_cursor_chkispdrchrbatch; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )429;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto chkispdrchrbatch_error;
}



        if (iCnt > 0) {
                iRet = PD_TRUE;
DEBUGLOG(("CheckIsProviderChargeBatch found one record, it's provider charge batch\n"));
        }

DEBUGLOG(("CheckIsProviderChargeBatch: Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

chkispdrchrbatch_error:
DEBUGLOG(("chkispdrchrbatch_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBatchTxnRelation chkispdrchrbatch_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        /* EXEC SQL CLOSE c_cursor_chkispdrchrbatch; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )444;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto chkispdrchrbatch_error;
}


        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int CheckIsInputTxnId(const hash_t* hRls)
{
        int iRet = PD_FALSE;

        char *csTmp;
        char cTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO chkisinputtxnid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                char            hv_batch_type;
                char            hv_batch_sub_type;
                /* varchar         hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;

                char            hv_txn_level;
                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		int         	hv_is_input_txn;

                int     	vCnt;	
        /* EXEC SQL END DECLARE SECTION; */ 


/* batch_type */
        if (GetField_Char(hRls, "batch_type", &cTmp)) {
                hv_batch_type = cTmp;
DEBUGLOG(("CheckIsInputTxnId: batch_type = [%c]\n", hv_batch_type));
        }

/* batch_sub_type */
        if (GetField_Char(hRls, "batch_sub_type", &cTmp)) {
                hv_batch_sub_type = cTmp;
DEBUGLOG(("CheckIsInputTxnId: batch_sub_type = [%c]\n", hv_batch_sub_type));
        }

/* batch_id */
        if (GetField_CString(hRls,"batch_id",&csTmp)) {
                hv_batch_id.len = strlen(csTmp);
                strncpy((char*)hv_batch_id.arr, csTmp, hv_batch_id.len);
DEBUGLOG(("CheckIsInputTxnId: batch_id = [%s]\n",(char*)hv_batch_id.arr));
        }

/* txn_level */
        if (GetField_Char(hRls, "txn_level", &cTmp)) {
                hv_txn_level = cTmp;
DEBUGLOG(("CheckIsInputTxnId: txn_level = [%c]\n", hv_txn_level));
        }

/* txn_id */
        if (GetField_CString(hRls,"txn_id",&csTmp)) {
                hv_txn_id.len = strlen(csTmp);
                strncpy((char*)hv_txn_id.arr, csTmp, hv_txn_id.len);
DEBUGLOG(("CheckIsInputTxnId: txn_id = [%s]\n",(char*)hv_txn_id.arr));
        }

/* is_input_txn */
	hv_is_input_txn = 1;	

        /* EXEC SQL        SELECT  count(1)
			INTO	vCnt
                        FROM    ol_batch_txn_relation
                        WHERE   obtr_batch_type = :hv_batch_type	
                       	AND   	obtr_batch_sub_type = :hv_batch_sub_type	
                        AND     obtr_batch_id = :hv_batch_id
			AND	obtr_txn_level = :hv_txn_level
                        AND     obtr_txn_id = :hv_txn_id
			AND	obtr_is_input_txn = :hv_is_input_txn; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count ( 1 ) INTO :b0 FROM ol_batch_txn_relati\
on WHERE obtr_batch_type = :b1 AND obtr_batch_sub_type = :b2 AND obtr_batch_i\
d = :b3 AND obtr_txn_level = :b4 AND obtr_txn_id = :b5 AND obtr_is_input_txn \
= :b6 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )459;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_type;
        sqlstm.sqhstl[1] = (unsigned long )1;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_batch_sub_type;
        sqlstm.sqhstl[2] = (unsigned long )1;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[3] = (unsigned long )18;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_level;
        sqlstm.sqhstl[4] = (unsigned long )1;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_txn_id;
        sqlstm.sqhstl[5] = (unsigned long )18;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_is_input_txn;
        sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)0;
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
        if (sqlca.sqlcode < 0) goto chkisinputtxnid_error;
}



	if (vCnt == 1) {
                iRet = PD_TRUE;
DEBUGLOG(("CheckIsInputTxnId Found!!!\n"));
        }

DEBUGLOG(("CheckIsInputTxnId Normal Exit [%d]\n", iRet));
        return iRet;

chkisinputtxnid_error:
DEBUGLOG(("chkisinputtxnid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int CheckIsRegenTxnId(const hash_t* hRls)
{
        int iRet = PD_FALSE;

        char *csTmp;
        char cTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO chkisregentxnid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                char            hv_batch_type;
                char            hv_batch_sub_type;
                /* varchar         hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;

                char            hv_txn_level;
                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		char         	hv_is_regen_txn;

                int     	vCnt;	
        /* EXEC SQL END DECLARE SECTION; */ 


/* batch_type */
        if (GetField_Char(hRls, "batch_type", &cTmp)) {
                hv_batch_type = cTmp;
DEBUGLOG(("CheckIsRegenTxnId: batch_type = [%c]\n", hv_batch_type));
        }

/* batch_sub_type */
        if (GetField_Char(hRls, "batch_sub_type", &cTmp)) {
                hv_batch_sub_type = cTmp;
DEBUGLOG(("CheckIsRegenTxnId: batch_sub_type = [%c]\n", hv_batch_sub_type));
        }

/* batch_id */
        if (GetField_CString(hRls,"batch_id",&csTmp)) {
                hv_batch_id.len = strlen(csTmp);
                strncpy((char*)hv_batch_id.arr, csTmp, hv_batch_id.len);
DEBUGLOG(("CheckIsRegenTxnId: batch_id = [%s]\n",(char*)hv_batch_id.arr));
        }

/* txn_level */
        if (GetField_Char(hRls, "txn_level", &cTmp)) {
                hv_txn_level = cTmp;
DEBUGLOG(("CheckIsRegenTxnId: txn_level = [%c]\n", hv_txn_level));
        }

/* txn_id */
        if (GetField_CString(hRls,"txn_id",&csTmp)) {
                hv_txn_id.len = strlen(csTmp);
                strncpy((char*)hv_txn_id.arr, csTmp, hv_txn_id.len);
DEBUGLOG(("CheckIsRegenTxnId: txn_id = [%s]\n",(char*)hv_txn_id.arr));
        }

/* is_regen_txn */
	hv_is_regen_txn = 1;	

        /* EXEC SQL        SELECT  count(1)
			INTO	vCnt
                        FROM    ol_batch_txn_relation
                        WHERE   obtr_batch_type = :hv_batch_type	
                        AND	obtr_batch_sub_type = :hv_batch_sub_type	
                        AND     obtr_batch_id = :hv_batch_id
			AND	obtr_txn_level = :hv_txn_level
                        AND     obtr_txn_id = :hv_txn_id
			AND	obtr_is_regen_txn = :hv_is_regen_txn; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count ( 1 ) INTO :b0 FROM ol_batch_txn_relati\
on WHERE obtr_batch_type = :b1 AND obtr_batch_sub_type = :b2 AND obtr_batch_i\
d = :b3 AND obtr_txn_level = :b4 AND obtr_txn_id = :b5 AND obtr_is_regen_txn \
= :b6 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )502;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_type;
        sqlstm.sqhstl[1] = (unsigned long )1;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_batch_sub_type;
        sqlstm.sqhstl[2] = (unsigned long )1;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[3] = (unsigned long )18;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_level;
        sqlstm.sqhstl[4] = (unsigned long )1;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_txn_id;
        sqlstm.sqhstl[5] = (unsigned long )18;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_is_regen_txn;
        sqlstm.sqhstl[6] = (unsigned long )1;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)0;
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
        if (sqlca.sqlcode < 0) goto chkisregentxnid_error;
}



	if (vCnt == 1) {
                iRet = PD_TRUE;
DEBUGLOG(("CheckIsRegenTxnId Found!!!\n"));
        }

DEBUGLOG(("CheckIsRegenTxnId Normal Exit [%d]\n", iRet));
        return iRet;

chkisregentxnid_error:
DEBUGLOG(("chkisregentxnid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int GetBatchTypeInfo(hash_t* hRls)
{
        int iRet = PD_NOT_FOUND;

        char *csTmp;

	int iCnt = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO getbatchtypeinfo_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;


		char            v_batch_type;
		char            v_batch_sub_type;
                short           ind_batch_type = -1;
                short           ind_batch_sub_type = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


/* batch_id */
        if (GetField_CString(hRls,"batch_id",&csTmp)) {
                hv_batch_id.len = strlen(csTmp);
                strncpy((char*)hv_batch_id.arr, csTmp, hv_batch_id.len);
DEBUGLOG(("GetBatchTypeInfo: batch_id = [%s]\n",(char*)hv_batch_id.arr));
        }

	/* EXEC SQL DECLARE c_cursor_getbatchtypeinfo CURSOR FOR
                SELECT  obtr_batch_type,
			obtr_batch_sub_type
                FROM    ol_batch_txn_relation
                WHERE   obtr_batch_id = :hv_batch_id; */ 

        /* EXEC SQL OPEN c_cursor_getbatchtypeinfo; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0010;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )545;
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
        if (sqlca.sqlcode < 0) goto getbatchtypeinfo_error;
}



	for (;;) {
                /* EXEC SQL FETCH c_cursor_getbatchtypeinfo
                INTO    :v_batch_type:ind_batch_type,
                	:v_batch_sub_type:ind_batch_sub_type; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 9;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )564;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_type;
                sqlstm.sqhstl[0] = (unsigned long )1;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_batch_type;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_batch_sub_type;
                sqlstm.sqhstl[1] = (unsigned long )1;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_batch_sub_type;
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
                if (sqlca.sqlcode < 0) goto getbatchtypeinfo_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		if (iCnt > 1) {
			break;
		}

		iCnt++;

		// batch_type
                if (ind_batch_type >= 0) {
                        PutField_Char(hRls, "batch_type",v_batch_type);
DEBUGLOG(("GetBatchTypeInfo batch_type = [%c]\n", v_batch_type));
                }

		// batch_sub_type
                if (ind_batch_sub_type >= 0) {
                        PutField_Char(hRls, "batch_sub_type",v_batch_sub_type);
DEBUGLOG(("GetBatchTypeInfo batch_sub_type = [%c]\n", v_batch_sub_type));
		}
        }

	/* EXEC SQL CLOSE c_cursor_getbatchtypeinfo; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )587;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getbatchtypeinfo_error;
}



	if (iCnt > 0) {
                iRet = PD_FOUND;
DEBUGLOG(("GetBatchTypeInfo FOUND\n"));
        } else {
                iRet = PD_NOT_FOUND;
DEBUGLOG(("GetBatchTypeInfo NOT FOUND!!!\n"));
        }

DEBUGLOG(("GetBatchTypeInfo: Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

getbatchtypeinfo_error:
DEBUGLOG(("getbatchtypeinfo_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBatchTxnRelation getbatchtypeinfo_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        /* EXEC SQL CLOSE c_cursor_getbatchtypeinfo; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )602;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getbatchtypeinfo_error;
}


        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int GetBatchIdByRTAscOrder(const hash_t* hRls, recordset_t* rRecordSet)
{
        int iRet = PD_OK;

        char *csTmp;
        char cTmp;

        hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getbatchidbyasc_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                char            hv_txn_level;
                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


                char            v_batch_type;
                char            v_batch_sub_type;
                /* varchar         v_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_batch_id;

                short           ind_batch_type = -1;
                short           ind_batch_sub_type = -1;
                short           ind_batch_id = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


/* txn_level */
	if (GetField_Char(hRls, "txn_level", &cTmp)) {
                hv_txn_level = cTmp;
DEBUGLOG(("GetBatchIdByRTAscOrder: txn_level = [%c]\n", hv_txn_level));
        }

/* txn_id */
        if (GetField_CString(hRls,"txn_id",&csTmp)) {
                hv_txn_id.len = strlen(csTmp);
                strncpy((char*)hv_txn_id.arr, csTmp, hv_txn_id.len);
DEBUGLOG(("GetBatchIdByRTAscOrder: txn_id = [%s]\n",(char*)hv_txn_id.arr));
        }

	/* EXEC SQL DECLARE c_cursor_getbatchidbyasc CURSOR FOR
                SELECT  obtr_batch_type,
			obtr_batch_sub_type,
			obtr_batch_id
                FROM    ol_batch_txn_relation
                WHERE   obtr_txn_level = :hv_txn_level
                AND     obtr_txn_id = :hv_txn_id
		ORDER BY obtr_relation_timestamp ASC; */ 

        /* EXEC SQL OPEN c_cursor_getbatchidbyasc; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0011;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )617;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_txn_level;
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
        if (sqlca.sqlcode < 0) goto getbatchidbyasc_error;
}



	for (;;) {
                /* EXEC SQL FETCH c_cursor_getbatchidbyasc
                INTO    :v_batch_type:ind_batch_type,
			:v_batch_sub_type:ind_batch_sub_type,
			:v_batch_id:ind_batch_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 9;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )640;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_type;
                sqlstm.sqhstl[0] = (unsigned long )1;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_batch_type;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_batch_sub_type;
                sqlstm.sqhstl[1] = (unsigned long )1;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_batch_sub_type;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_batch_id;
                sqlstm.sqhstl[2] = (unsigned long )18;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_batch_id;
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
                if (sqlca.sqlcode < 0) goto getbatchidbyasc_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash, 0);

		// batch_type
                if (ind_batch_type >= 0) {
                        PutField_Char(myHash, "batch_type",v_batch_type);
DEBUGLOG(("GetBatchIdByRTAscOrder batch_type = [%c]\n", v_batch_type));
                }

                // batch_sub_type
                if (ind_batch_sub_type >= 0) {
                        PutField_Char(myHash, "batch_sub_type",v_batch_sub_type);
DEBUGLOG(("GetBatchIdByRTAscOrder batch_sub_type = [%c]\n", v_batch_sub_type));
                }

		// batch_id
                if (ind_batch_id >= 0) {
                        v_batch_id.arr[v_batch_id.len] = '\0';
                        PutField_CString(myHash, "batch_id", (const char*)v_batch_id.arr);
DEBUGLOG(("GetBatchIdByRTAscOrder: batch_id = [%s]\n", (const char*)v_batch_id.arr));
                }

                RecordSet_Add(rRecordSet, myHash);
        }

	/* EXEC SQL CLOSE c_cursor_getbatchidbyasc; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )667;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getbatchidbyasc_error;
}



DEBUGLOG(("GetBatchIdByRTAscOrder: Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

getbatchidbyasc_error:
DEBUGLOG(("getbatchidbyasc_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBatchTxnRelation getbatchidbyasc_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        /* EXEC SQL CLOSE c_cursor_getbatchidbyasc; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )682;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getbatchidbyasc_error;
}


        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

