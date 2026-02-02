
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
           char  filnam[23];
};
static struct sqlcxp sqlfpn =
{
    22,
    "OLPayoutApiPregenDT.pc"
};


static unsigned int sqlctx = 326522875;


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
   unsigned char  *sqhstv[34];
   unsigned long  sqhstl[34];
            int   sqhsts[34];
            short *sqindv[34];
            int   sqinds[34];
   unsigned long  sqharm[34];
   unsigned long  *sqharc[34];
   unsigned short  sqadto[34];
   unsigned short  sqtdso[34];
} sqlstm = {12,34};

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
"select oag_seq , oag_txn_id , oag_psp_id , oag_bank_code , oag_file_id from\
 ol_payout_api_pregen_dt where oag_batch_id = :b0 order by oag_seq           \
 ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,244,0,6,118,0,0,8,8,0,1,0,2,3,0,0,1,68,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,1,68,0,0,1,9,0,0,
52,0,0,2,153,0,9,200,0,2049,1,1,0,1,0,1,68,0,0,
71,0,0,2,0,0,13,202,0,0,5,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,
106,0,0,2,0,0,15,254,0,0,0,0,0,1,0,
121,0,0,2,0,0,15,264,0,0,0,0,0,1,0,
136,0,0,3,0,0,17,347,0,0,1,1,0,1,0,1,9,0,0,
155,0,0,3,0,0,21,348,0,0,0,0,0,1,0,
170,0,0,4,81,0,6,379,0,0,2,2,0,1,0,2,3,0,0,1,9,0,0,
193,0,0,3,0,0,17,630,0,0,1,1,0,1,0,1,9,0,0,
212,0,0,3,0,0,21,631,0,0,0,0,0,1,0,
227,0,0,5,123,0,4,670,0,0,3,2,0,1,0,2,9,0,0,1,68,0,0,1,9,0,0,
254,0,0,0,0,0,56,810,0,0,1,1,0,1,0,3,102,0,0,
273,0,0,6,337,0,6,812,0,0,10,10,0,1,0,2,3,0,0,1,68,0,0,1,9,0,0,1,9,0,0,1,3,0,0,
1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,2,102,0,0,
328,0,0,0,0,0,13,839,0,0,4,1,0,1,0,1,102,0,0,2,68,0,0,2,9,0,0,2,4,0,0,
359,0,0,0,0,0,15,873,0,0,1,1,0,1,0,1,102,0,0,
378,0,0,0,0,0,78,874,0,0,1,1,0,1,0,3,102,0,0,
397,0,0,0,0,0,15,884,0,0,1,1,0,1,0,1,102,0,0,
416,0,0,0,0,0,78,885,0,0,1,1,0,1,0,3,102,0,0,
435,0,0,0,0,0,56,936,0,0,1,1,0,1,0,3,102,0,0,
454,0,0,7,105,0,6,938,0,0,3,3,0,1,0,2,3,0,0,1,68,0,0,2,102,0,0,
481,0,0,0,0,0,13,959,0,0,7,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
3,0,0,2,4,0,0,
524,0,0,0,0,0,15,1021,0,0,1,1,0,1,0,1,102,0,0,
543,0,0,0,0,0,78,1022,0,0,1,1,0,1,0,3,102,0,0,
562,0,0,0,0,0,15,1036,0,0,1,1,0,1,0,1,102,0,0,
581,0,0,0,0,0,78,1037,0,0,1,1,0,1,0,3,102,0,0,
600,0,0,0,0,0,56,1086,0,0,1,1,0,1,0,3,102,0,0,
619,0,0,8,112,0,6,1088,0,0,3,3,0,1,0,2,3,0,0,1,68,0,0,2,102,0,0,
646,0,0,0,0,0,13,1108,0,0,6,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,
2,4,0,0,
685,0,0,0,0,0,15,1162,0,0,1,1,0,1,0,1,102,0,0,
704,0,0,0,0,0,78,1163,0,0,1,1,0,1,0,3,102,0,0,
723,0,0,0,0,0,15,1177,0,0,1,1,0,1,0,1,102,0,0,
742,0,0,0,0,0,78,1178,0,0,1,1,0,1,0,3,102,0,0,
761,0,0,0,0,0,56,1283,0,0,1,1,0,1,0,3,102,0,0,
780,0,0,9,109,0,6,1285,0,0,3,3,0,1,0,2,3,0,0,1,68,0,0,2,102,0,0,
807,0,0,0,0,0,13,1334,0,0,34,1,0,1,0,1,102,0,0,2,68,0,0,2,9,0,0,2,3,0,0,2,3,0,
0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,
0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
958,0,0,0,0,0,15,1605,0,0,1,1,0,1,0,1,102,0,0,
977,0,0,0,0,0,78,1606,0,0,1,1,0,1,0,3,102,0,0,
996,0,0,0,0,0,15,1621,0,0,1,1,0,1,0,1,102,0,0,
1015,0,0,0,0,0,78,1622,0,0,1,1,0,1,0,3,102,0,0,
1034,0,0,0,0,0,56,1727,0,0,1,1,0,1,0,3,102,0,0,
1053,0,0,10,106,0,6,1729,0,0,3,3,0,1,0,2,3,0,0,1,68,0,0,2,102,0,0,
1080,0,0,0,0,0,13,1777,0,0,34,1,0,1,0,1,102,0,0,2,68,0,0,2,9,0,0,2,3,0,0,2,3,0,
0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,
0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
1231,0,0,0,0,0,15,2048,0,0,1,1,0,1,0,1,102,0,0,
1250,0,0,0,0,0,78,2049,0,0,1,1,0,1,0,3,102,0,0,
1269,0,0,0,0,0,15,2064,0,0,1,1,0,1,0,1,102,0,0,
1288,0,0,0,0,0,78,2065,0,0,1,1,0,1,0,3,102,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2017/03/14              Dirk Wong
Add GetGenRecords				   2017/06/13		   Elvis Wong
Get pregen info by action_id                       2017/07/06              Elvis Wong
Reduce logs					   2017/11/02		   Dirk Wong
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "OLPayoutApiPregenDT.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "internal.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void OLPayoutApiPregenDT(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const hash_t *hRec)
{
	char            *csTmp;
        int             iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                unsigned long   hv_batch_id;
                int             hv_seq;
		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		/* varchar		hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar		hv_bank_code[PD_AC_BANK_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_bank_code;

		unsigned long	hv_file_id;
		/* varchar		hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;

                
                short           ind_batch_id = -1;
                short           ind_seq = -1;
                short           ind_txn_id = -1;
                short           ind_psp_id = -1;
                short           ind_bank_code = -1;
                short           ind_file_id = -1;
                short           ind_add_user = -1;

                short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

//batch_id
        if(GetField_CString(hRec,"batch_id",&csTmp)){
                hv_batch_id = (unsigned long)ctol((const unsigned char*)csTmp,strlen(csTmp));
                ind_batch_id= 0;
DEBUGLOG(("Add:batch_id= [%ld]\n",hv_batch_id));
        }

//seq
        if(GetField_Int(hRec,"seq",&iTmp)){
                hv_seq = iTmp;
                ind_seq= 0;
DEBUGLOG(("Add:seq= [%d]\n",hv_seq));
        }

//txn_id
        if(GetField_CString(hRec,"txn_id",&csTmp)){
                hv_txn_id.len = strlen(csTmp);
                memcpy(hv_txn_id.arr, csTmp, hv_txn_id.len);
                ind_txn_id= 0;
DEBUGLOG(("Add:txn_id= [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
        }

//psp_id
        if(GetField_CString(hRec,"psp_id",&csTmp)){
                hv_psp_id.len = strlen(csTmp);
                memcpy(hv_psp_id.arr, csTmp, hv_psp_id.len);
                ind_psp_id= 0;
DEBUGLOG(("Add:psp_id= [%.*s]\n",hv_psp_id.len,hv_psp_id.arr));
        }

//bank_code
        if(GetField_CString(hRec,"bank_code",&csTmp)){
                hv_bank_code.len = strlen(csTmp);
                memcpy(hv_bank_code.arr, csTmp, hv_bank_code.len);
                ind_bank_code= 0;
DEBUGLOG(("Add:bank_code= [%.*s]\n",hv_bank_code.len,hv_bank_code.arr));
        }

//file_id
        if(GetField_Int(hRec,"file_id",&iTmp)){
                hv_file_id = iTmp;
                ind_file_id= 0;
DEBUGLOG(("Add:file_id= [%d]\n",hv_file_id));
        }

//user
        if(GetField_CString(hRec,"add_user",&csTmp)){
                hv_add_user.len = strlen(csTmp);
                memcpy(hv_add_user.arr, csTmp, hv_add_user.len);
                ind_add_user= 0;
DEBUGLOG(("Add:add_user= [%.*s]\n",hv_add_user.len,hv_add_user.arr));
        }

	/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_ol_payout_api_pregen_dt_add(
                                        :hv_batch_id:ind_batch_id,
                                        :hv_seq:ind_seq,
					:hv_txn_id:ind_txn_id,
					:hv_psp_id:ind_psp_id,
					:hv_bank_code:ind_bank_code,
					:hv_file_id:ind_file_id,
                                        :hv_add_user:ind_add_user);
                END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_payout_api_pregen_dt_add ( \
:hv_batch_id:ind_batch_id , :hv_seq:ind_seq , :hv_txn_id:ind_txn_id , :hv_psp\
_id:ind_psp_id , :hv_bank_code:ind_bank_code , :hv_file_id:ind_file_id , :hv_\
add_user:ind_add_user ) ; END ;";
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
 sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
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
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[3] = (unsigned long )18;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_txn_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[4] = (unsigned long )12;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_psp_id;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_bank_code;
 sqlstm.sqhstl[5] = (unsigned long )27;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_bank_code;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_file_id;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_add_user;
 sqlstm.sqhstl[7] = (unsigned long )22;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_add_user;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
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
ERRLOG("OLPayoutApiPregenDT_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("OLPayoutApiPregenDT_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPayoutApiPregenDT_Add: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}


int GetDetail(const hash_t* hRec,recordset_t* myRec)
{
        hash_t *myHash;         
        char*   csTmp;          
                
        /* EXEC SQL WHENEVER SQLERROR GOTO getdetail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                unsigned long   hv_batch_id;
                
		int		v_seq;
                /* varchar         v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

                /* varchar         v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

                /* varchar         v_bank_code[PD_AC_BANK_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_bank_code;

                int 		v_file_id;

		short           ind_seq = -1;
		short           ind_txn_id = -1;
		short           ind_psp_id = -1;
		short		ind_bank_code = -1;
		short		ind_file_id = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        if(GetField_CString(hRec,"batch_id",&csTmp)){
                hv_batch_id = (unsigned long)ctol((const unsigned char*)csTmp,strlen(csTmp));
DEBUGLOG(("GetDetail batch_id = [%ld]\n",hv_batch_id));
        }

/* EXEC SQL DECLARE c_cursor_getdetail CURSOR FOR
                select
                        oag_seq,
			oag_txn_id,
			oag_psp_id,
			oag_bank_code,
			oag_file_id
                from    ol_payout_api_pregen_dt
                where   oag_batch_id = :hv_batch_id
		order by oag_seq; */ 


	/* EXEC SQL OPEN  c_cursor_getdetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )52;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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
 if (sqlca.sqlcode < 0) goto getdetail_error;
}


        do{
                /* EXEC SQL FETCH c_cursor_getdetail
                INTO
                        :v_seq:ind_seq,
                        :v_txn_id:ind_txn_id,
                        :v_psp_id:ind_psp_id,
                        :v_bank_code:ind_bank_code,
                        :v_file_id:ind_file_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 8;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )71;
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
                sqlstm.sqhstv[2] = (unsigned char  *)&v_psp_id;
                sqlstm.sqhstl[2] = (unsigned long )13;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_psp_id;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_bank_code;
                sqlstm.sqhstl[3] = (unsigned long )28;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_bank_code;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_file_id;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
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
                if (sqlca.sqlcode < 0) goto getdetail_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

//seq
		if(ind_seq>=0){
			PutField_Int(myHash,"seq",v_seq);
DEBUGLOG(("GetDetail seq= [%d]\n",v_seq));
		}

//txn_id
                if(ind_txn_id>=0){
                        v_txn_id.arr[v_txn_id.len]='\0';
                        PutField_CString(myHash,"txn_id",(const char*)v_txn_id.arr);
DEBUGLOG(("GetDetail txn_id= [%s]\n",v_txn_id.arr));
                }

//psp_id
                if(ind_psp_id>=0){
                        v_psp_id.arr[v_psp_id.len]='\0';
                        PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetDetail psp_id= [%s]\n",v_psp_id.arr));
                }

//bank_code
                if(ind_bank_code>=0){
                        v_bank_code.arr[v_bank_code.len]='\0';
                        PutField_CString(myHash,"bank_code",(const char*)v_bank_code.arr);
DEBUGLOG(("GetDetail bank_code= [%s]\n",v_bank_code.arr));
                }

//file_id
                if(ind_file_id>=0){
                        PutField_Int(myHash,"file_id",v_file_id);
DEBUGLOG(("GetDetail file_id= [%d]\n",v_file_id));
                }

                RecordSet_Add(myRec,myHash);

        }while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )106;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getdetail_error;
}



DEBUGLOG(("GetDetail Normal Exit\n"));
        return  PD_OK;

getdetail_error:
DEBUGLOG(("getdetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPayoutApiPregenDT_Get: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )121;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;

}


int UpdateByBatchId(const hash_t *hRec)
{
        char*   csBuf;
        char*	csBatchId;
        int     iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateByBatchId: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update ol_payout_api_pregen_dt set oag_update_timestamp = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        if(GetField_CString(hRec,"batch_id",&csBatchId)){
DEBUGLOG(("Update:batch_id = [%s]\n",csBatchId));
	}
        else{
                FREE_ME(csBuf);
DEBUGLOG(("UpdateByBatchId batch_id not found\n"));
                return INT_ERR;
        }

	if(GetField_CString(hRec,"txn_id",&csBuf)){
DEBUGLOG(("UpdateByBatchId: txn_id = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oag_txn_id = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	if(GetField_CString(hRec,"psp_id",&csBuf)){
DEBUGLOG(("UpdateByBatchId: psp_id = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oag_psp_id = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	if(GetField_CString(hRec,"bank_code",&csBuf)){
DEBUGLOG(("UpdateByBatchId: bank_code = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oag_bank_code = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Int(hRec,"file_id",&iTmp)){
DEBUGLOG(("UpdateByBatchId: file_id = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",oag_file_id = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	if(GetField_CString(hRec,"update_user",&csBuf)){
DEBUGLOG(("UpdateByBatchId: update_user = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oag_update_user = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	strcat((char*)hv_dynstmt.arr, " WHERE oag_batch_id= ");
        strcat((char*)hv_dynstmt.arr, csBatchId);
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));


        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )136;
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
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )155;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_error;
}



        FREE_ME(csBuf);

DEBUGLOG(("UpdateByBatchId Normal Exit\n"));
        return PD_OK;

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPayoutApiPregenDT_UpdateByBatchId: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int Delete(const unsigned char* batch_id)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO delete_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;


                short   hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_batch_id.len = strlen((const char*)batch_id);
        memcpy(hv_batch_id.arr,batch_id,hv_batch_id.len);
DEBUGLOG(("Delete: batch_id = [%.*s]\n",hv_batch_id.len,hv_batch_id.arr));

        /* EXEC SQL EXECUTE
            BEGIN

                :hv_return_value := sp_ol_payout_api_pregen_dt_del(
                                :hv_batch_id);

            END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_payout_api_pregen_dt\
_del ( :hv_batch_id ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )170;
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
        if (sqlca.sqlcode < 0) goto delete_error;
}




DEBUGLOG(("Delete:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("Delete:Normal Exit\n"));
                return PD_OK;
        }
        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("OLPayoutApiPregenDT_Delete: SP_OTHER_ERR\n");
DEBUGLOG(("Delete: SP_OTHER_ERR\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("OLPayoutApiPregenDT_Delete: SP_ERR\n");
DEBUGLOG(("Delete: SP_ERR\n"));
                return PD_ERR;
        }
delete_error:
DEBUGLOG(("delete_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPayoutApiPregenDT_Delete: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}


/*
int GetDetailByTxnId(const char* csBatchId,const char* csTxnId,recordset_t* myRec)
{               
        hash_t	*myHash;         
                
        EXEC SQL WHENEVER SQLERROR GOTO getdetailbytxnid_error;
        EXEC SQL WHENEVER NOTFOUND CONTINUE;

        EXEC SQL BEGIN DECLARE SECTION;
		unsigned long   hv_batch_id;
                varchar         hv_txn_id[PD_TXN_SEQ_LEN+1];
                
		unsigned long	v_batch_id;
		varchar 	v_txn_id[PD_TXN_SEQ_LEN+1];
		int		v_seq;
		varchar		v_psp_id[PD_PSP_ID_LEN+1];
		varchar		v_bank_code[PD_AC_BANK_LEN+1];
		int		v_file_id;
		char		v_hd_batch_status;

		short           ind_batch_id = -1;
		short           ind_txn_id = -1;
		short           ind_seq = -1;
                short           ind_psp_id = -1;
                short           ind_bank_code = -1;
		short		ind_file_id = -1;
		short		ind_hd_batch_status = -1;
        EXEC SQL END DECLARE SECTION;

	hv_batch_id = (unsigned long)ctol((const unsigned char*)csBatchId,strlen(csBatchId));
DEBUGLOG(("GetDetailByTxnId batch_id= [%ld]\n",hv_batch_id));

	hv_txn_id.len = strlen(csTxnId);
	memcpy(hv_txn_id.arr,csTxnId,hv_txn_id.len);
DEBUGLOG(("GetDetailByTxnId txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

EXEC SQL DECLARE c_cursor_getdetailbytxnid CURSOR FOR
                select	oag_batch_id,
			oag_txn_id,
                        oag_seq,
			oag_psp_id,
			oag_bank_code,
			oag_file_id,
			oap_status
                from    ol_payout_api_pregen_dt,
			ol_payout_api_pregen_hd
                where   oag_txn_id=:hv_txn_id
		  and	oag_batch_id=:hv_batch_id
		  and	oap_batch_id=oag_batch_id;

	EXEC SQL OPEN  c_cursor_getdetailbytxnid;
        do{
                EXEC SQL FETCH c_cursor_getdetailbytxnid
                INTO	:v_batch_id:ind_batch_id,
			:v_txn_id:ind_txn_id,
                        :v_seq:ind_seq,
                        :v_psp_id:ind_psp_id,
			:v_bank_code:ind_bank_code,
			:v_file_id:ind_file_id,
			:v_hd_batch_status:ind_hd_batch_status;

                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

//batch_id
                if(ind_batch_id>=0){
                        PutField_CString(myHash,"batch_id",csBatchId);
DEBUGLOG(("GetDetailByTxnId batch_id= [%s]\n",csBatchId));
                }

//txn_id
                if(ind_txn_id>=0){
			PutField_CString(myHash,"txn_id",csTxnId);
DEBUGLOG(("GetDetailByTxnId txn_id= [%s]\n",csTxnId));
                }

//seq
		if(ind_seq>=0){
			PutField_Int(myHash,"seq",v_seq);
DEBUGLOG(("GetDetailByTxnId seq= [%d]\n",v_seq));
		}

//psp_id
                if(ind_psp_id>=0){
			v_psp_id.arr[v_psp_id.len]= '\0';
                        PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetDetailByTxnId psp_id= [%s]\n",v_psp_id.arr));
                }

//bank_code
                if(ind_bank_code>=0){
			v_bank_code.arr[v_bank_code.len]= '\0';
                        PutField_CString(myHash,"bank_code",(const char*)v_bank_code.arr);
DEBUGLOG(("GetDetailByTxnId bank_code= [%s]\n",v_bank_code.arr));
                }

//file_id
                if(ind_file_id>=0){
                        PutField_Int(myHash,"file_id",v_file_id);
DEBUGLOG(("GetDetailByTxnId file_id= [%d]\n",v_file_id));
                }

//hd_batch_status
                if(ind_hd_batch_status>=0){
                        PutField_Char(myHash,"hd_batch_status",v_hd_batch_status);
DEBUGLOG(("GetDetailByTxnId hd_batch_status= [%c]\n",v_hd_batch_status));
                }

                RecordSet_Add(myRec,myHash);

        }while(PD_TRUE);

        EXEC SQL CLOSE c_cursor_getdetailbytxnid;

DEBUGLOG(("GetDetailByTxnId Normal Exit\n"));
        return  PD_OK;

getdetailbytxnid_error:
DEBUGLOG(("getdetailbytxnid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPayoutApiPregenDT_Get: SP_INTERNAL_ERR\n");
        EXEC SQL WHENEVER SQLERROR CONTINUE;
        EXEC SQL CLOSE c_cursor_getdetailbytxnid;
        return PD_ERR;

}
*/


int UpdateByTxnId(const hash_t *hRec)
{
        char*   csBuf;
        char*	csTxnId;
        char*	csBatchId;
        int     iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO updatebytxnid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateByTxnId: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update ol_payout_api_pregen_dt set oag_update_timestamp = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        if(GetField_CString(hRec,"txn_id",&csTxnId)){
//DEBUGLOG(("txn_id = [%s]\n",csTxnId));
	}
        else{
                FREE_ME(csBuf);
DEBUGLOG(("txn_id not found\n"));
                return INT_ERR;
        }
	if(GetField_CString(hRec,"batch_id",&csBatchId)){
//DEBUGLOG(("batch_id = [%s]\n",csBatchId));
        }
        else{
                FREE_ME(csBuf);
DEBUGLOG(("UpdateByTxnId batch_id not found\n"));
                return INT_ERR;
        }

	if(GetField_CString(hRec,"psp_id",&csBuf)){
//DEBUGLOG(("psp_id = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oag_psp_id = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	if(GetField_CString(hRec,"bank_code",&csBuf)){
//DEBUGLOG(("bank_code = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oag_bank_code = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Int(hRec,"file_id",&iTmp)){
//DEBUGLOG(("file_id = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",oag_file_id = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	if(GetField_CString(hRec,"update_user",&csBuf)){
//DEBUGLOG(("update_user = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oag_update_user = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	strcat((char*)hv_dynstmt.arr, " WHERE oag_txn_id = '");
        strcat((char*)hv_dynstmt.arr, csTxnId);
	strcat((char*)hv_dynstmt.arr, "'");
	strcat((char*)hv_dynstmt.arr, " AND oag_batch_id= ");
        strcat((char*)hv_dynstmt.arr, csBatchId);
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

//DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));


        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )193;
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
        if (sqlca.sqlcode < 0) goto updatebytxnid_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )212;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto updatebytxnid_error;
}



        FREE_ME(csBuf);

//DEBUGLOG(("UpdateByTxnId Normal Exit\n"));
DEBUGLOG(("  Normal Exit, txn_id [%s] batch_id [%s]\n",csTxnId,csBatchId));
        return PD_OK;

updatebytxnid_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPayoutApiPregenDT_UpdateByTxnId: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int GetTxnIdForUpdate(const char* csBatchId, const char* csTxnId) 
{
        int iRet = PD_OK;

        /* EXEC SQL WHENEVER SQLERROR GOTO gettxnidforupdate_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		unsigned long   hv_batch_id;
                /* varchar hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

                /* varchar v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

                short ind_txn_id = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


	hv_batch_id = (unsigned long)ctol((const unsigned char*)csBatchId,strlen(csBatchId));
//DEBUGLOG(("GetTxnIdForUpdate batch_id= [%ld]\n",hv_batch_id));

        hv_txn_id.len = strlen(csTxnId);
        memcpy(hv_txn_id.arr, csTxnId, hv_txn_id.len);
//DEBUGLOG(("GetTxnIdForUpdate txn_id = [%.*s]\n", hv_txn_id.len, hv_txn_id.arr));
//DEBUGLOG(("GetTxnIdForUpdate txn_id = [%.*s]\n", hv_txn_id.len, hv_txn_id.arr));

        /* EXEC SQL select oag_txn_id
                into :v_txn_id:ind_txn_id
                from ol_payout_api_pregen_dt
                where oag_batch_id = :hv_batch_id
		and oag_txn_id = :hv_txn_id
                for update nowait; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select oag_txn_id into :b0:b1 from ol_payout_api_pre\
gen_dt where oag_batch_id = :b2 and oag_txn_id = :b3 for update nowait ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )227;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_id;
        sqlstm.sqhstl[0] = (unsigned long )19;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_txn_id;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
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
        if (sqlca.sqlcode < 0) goto gettxnidforupdate_error;
}



        if (ind_txn_id >= 0) {
                iRet = PD_OK;
        } else {
                iRet = PD_ERR;
        }

        return iRet;

gettxnidforupdate_error:
DEBUGLOG(("gettxnidforupdate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int GetRecordByRandomWithPara(const hash_t *hTxn,recordset_t* myRec)
{
        hash_t  *myHash;
	char    csBatchId[PD_TXN_SEQ_LEN+1];
        char    *csTmp;
        int     iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO getrecwp_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short           hv_return_value;

		unsigned long   hv_action_id;
                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_in_bank_name[PD_BANK_NAME_LEN+3]; */ 
struct { unsigned short len; unsigned char arr[153]; } hv_in_bank_name;

                int             hv_status;
                /* varchar         hv_payout_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_payout_ccy;

                /* varchar         hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar         hv_in_merch_grp[PD_OFL_PAYOUT_GROUP_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_in_merch_grp;

                /* varchar         hv_in_psp_grp[PD_OFL_PAYOUT_GROUP_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_in_psp_grp;


		short		ind_action_id = -1;
                short           ind_merchant_id= -1;
                short           ind_in_bank_name= -1;
                short           ind_status= -1;
                short           ind_payout_ccy= -1;
                short           ind_psp_id= -1;
                short           ind_in_psp_grp= -1;
                short           ind_in_merch_grp= -1;

                SQL_CURSOR      c_cursor_rec_random;

		unsigned long   v_batch_id;
                /* varchar         v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

                double          v_payout_amount;
		short		ind_batch_id = -1;
                short           ind_txn_id = -1;
                short           ind_payout_amount = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetRecordByRandomWithPara: Begin\n"));

//status
	hv_status = PAYOUT_MASTER_TRANSACTION_APPROVED;
        ind_status = 0;
DEBUGLOG(("status = [%d]\n",hv_status));

//merchant_id
	if(GetField_CString(hTxn,"merchant_id",&csTmp)){
                hv_merchant_id.len = strlen(csTmp);
                memcpy(hv_merchant_id.arr,csTmp,hv_merchant_id.len);
                ind_merchant_id= 0;
DEBUGLOG(("merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        }

//bank_present
        if(GetField_Int(hTxn,"bank_present",&iTmp)){
                if(iTmp){
//bank_name
                        if(GetField_CString(hTxn,"bank_name",&csTmp)){
                                char    csTmpBank[strlen(csTmp)+3];
                                hv_in_bank_name.len = strlen(csTmp)+2;
                                strcpy(csTmpBank,"%");
                                strcat(csTmpBank,csTmp);
                                strcat(csTmpBank,"%");
                                csTmpBank[strlen(csTmp)+2]='\0';
                                memcpy(hv_in_bank_name.arr,csTmpBank,hv_in_bank_name.len);
                                ind_in_bank_name= 0;
DEBUGLOG(("bank_name = [%.*s]\n",hv_in_bank_name.len,hv_in_bank_name.arr));
                        }
                }
        }

//payout_ccy
        if(GetField_CString(hTxn,"payout_ccy",&csTmp)){
                hv_payout_ccy.len = strlen(csTmp);
                memcpy(hv_payout_ccy.arr,csTmp,hv_payout_ccy.len);
                ind_payout_ccy= 0;
DEBUGLOG(("payout_ccy = [%s]\n",csTmp));
        }

//merchant_group
        if(GetField_CString(hTxn,"merchant_group",&csTmp)){
		hv_in_merch_grp.len = strlen(csTmp);
                memcpy(hv_in_merch_grp.arr,csTmp,hv_in_merch_grp.len);
                ind_in_merch_grp= 0;
DEBUGLOG(("merchant_group = [%s]\n",csTmp));
        }

//psp_group
        if(GetField_CString(hTxn,"psp_group",&csTmp)){
     		hv_in_psp_grp.len = strlen(csTmp);
                memcpy(hv_in_psp_grp.arr,csTmp,hv_in_psp_grp.len);
	       	ind_in_psp_grp= 0;
DEBUGLOG(("psp_group = [%s]\n",csTmp));
        }

//psp_id
	if(GetField_CString(hTxn,"psp_id",&csTmp)){
                hv_psp_id.len = strlen(csTmp);
                memcpy(hv_psp_id.arr,csTmp,hv_psp_id.len);
                ind_psp_id= 0;
DEBUGLOG(("psp_id = [%s]\n",csTmp));
        }

//action_id
        if(GetField_CString(hTxn,"action_id",&csTmp)){
                hv_action_id = (unsigned long)ctol((const unsigned char*)csTmp,strlen(csTmp));
                ind_action_id = 0;
DEBUGLOG(("action_id = [%ld]\n",hv_action_id));
        } else {
DEBUGLOG(("action_id not found\n"));
             	return INT_ERR;
	}	
       	
	/* EXEC SQL ALLOCATE       :c_cursor_rec_random; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )254;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_rec_random;
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
 if (sqlca.sqlcode < 0) goto getrecwp_error;
}



       	/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_ol_po_api_pregen_random_rec(
                                	  	:hv_action_id:ind_action_id,
                                	       	:hv_merchant_id:ind_merchant_id,
                                	       	:hv_in_bank_name:ind_in_bank_name,
                                	       	:hv_status:ind_status,
                                	      	:hv_payout_ccy:ind_payout_ccy,
                                	       	:hv_in_merch_grp:ind_in_merch_grp,
                                	       	:hv_in_psp_grp:ind_in_psp_grp,
                                	       	:hv_psp_id:ind_psp_id,
                                	       	:c_cursor_rec_random);
               	END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_po_api_pregen_random\
_rec ( :hv_action_id:ind_action_id , :hv_merchant_id:ind_merchant_id , :hv_in\
_bank_name:ind_in_bank_name , :hv_status:ind_status , :hv_payout_ccy:ind_payo\
ut_ccy , :hv_in_merch_grp:ind_in_merch_grp , :hv_in_psp_grp:ind_in_psp_grp , \
:hv_psp_id:ind_psp_id , :c_cursor_rec_random ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )273;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_action_id;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_action_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[2] = (unsigned long )17;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_merchant_id;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_in_bank_name;
        sqlstm.sqhstl[3] = (unsigned long )155;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_in_bank_name;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_status;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_payout_ccy;
        sqlstm.sqhstl[5] = (unsigned long )5;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_payout_ccy;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_in_merch_grp;
        sqlstm.sqhstl[6] = (unsigned long )4;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_in_merch_grp;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_in_psp_grp;
        sqlstm.sqhstl[7] = (unsigned long )4;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_in_psp_grp;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_psp_id;
        sqlstm.sqhstl[8] = (unsigned long )12;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_psp_id;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&c_cursor_rec_random;
        sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)0;
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
        if (sqlca.sqlcode < 0) goto getrecwp_error;
}



//DEBUGLOG(("hv_return_value = [%d]\n", hv_return_value));
DEBUGLOG(("hv_return_value = [%d], Start LOOP...\n", hv_return_value));
        if (hv_return_value > 0) {
                for (;;) {
                        myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);

                        ind_batch_id = -1;
                        ind_txn_id = -1;
                        ind_payout_amount = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_rec_random
                        INTO
                        	:v_batch_id:ind_batch_id,
                        	:v_txn_id:ind_txn_id,
                        	:v_payout_amount:ind_payout_amount; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 10;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )328;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_rec_random;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_batch_id;
                        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_batch_id;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_id;
                        sqlstm.sqhstl[2] = (unsigned long )19;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_txn_id;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_payout_amount;
                        sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_payout_amount;
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
                        if (sqlca.sqlcode == 1403) break;
                        if (sqlca.sqlcode < 0) goto getrecwp_error;
}



                        if (SQLCODE == SQL_NOT_FOUND) {
                                break;
                        }

/*batch_id*/
                        if(ind_batch_id>=0){
                                sprintf(csBatchId, "%ld", v_batch_id);
                                PutField_CString(myHash,"batch_id",csBatchId);
//DEBUGLOG(("batch_id= [%s]\n",csBatchId));
                        }

/*txn_id*/
                        if(ind_txn_id>=0){
                                v_txn_id.arr[v_txn_id.len]='\0';
                                PutField_CString(myHash,"txn_seq",(const char*)v_txn_id.arr);
//DEBUGLOG(("txn_id=[%s]\n",v_txn_id.arr));
                        }

/*payout_amount*/
                        if(ind_payout_amount>=0){
                                PutField_Double(myHash,"payout_amount",v_payout_amount);
//DEBUGLOG(("payout_amount = [%lf]\n",v_payout_amount));
                        }

                        RecordSet_Add(myRec,myHash);
                }
        }

        /* EXEC SQL CLOSE :c_cursor_rec_random; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )359;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_rec_random;
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
        if (sqlca.sqlcode < 0) goto getrecwp_error;
}


        /* EXEC SQL FREE :c_cursor_rec_random; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )378;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_rec_random;
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
        if (sqlca.sqlcode < 0) goto getrecwp_error;
}



DEBUGLOG(("GetRecordByRandomWithPara Normal Exit\n"));
        return  PD_OK;

getrecwp_error:
DEBUGLOG(("getrecwp_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPayoutApiPregenDT_GetRecordByRandomWithPara: SP_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE :c_cursor_rec_random; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )397;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_rec_random;
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
}


        /* EXEC SQL FREE :c_cursor_rec_random; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )416;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_rec_random;
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
}


        return PD_ERR;
}


int GetExistingPsp(const hash_t *hRec, recordset_t* myRec)
{
        hash_t *myHash;

        int     iCnt = 0;
	char	*csTmp = NULL;

        /* EXEC SQL WHENEVER SQLERROR GOTO epsp_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		unsigned long   hv_action_id;

		short           ind_action_id = -1;

		short   	hv_return_value;

                /* varchar         v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

                /* varchar         v_psp_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_psp_ccy;

                /* varchar         v_psp_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_psp_country;

                /* varchar         v_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

                int             v_count;
                double          v_amount;

                short           ind_psp_id = -1;
                short           ind_psp_ccy = -1;
                short           ind_psp_country = -1;
                short           ind_bank_code = -1;
                short           ind_count = -1;
                short           ind_amount = -1;

		SQL_CURSOR      c_cursor_psp_id;
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetExistingPsp: Begin"));

	// action_id
        if(GetField_CString(hRec,"action_id",&csTmp)){
                hv_action_id= (unsigned long)ctol((const unsigned char*)csTmp,strlen(csTmp));
		ind_action_id = 0;
DEBUGLOG(("action_id = [%ld]\n",hv_action_id));
	} else {
DEBUGLOG(("action_id not found\n"));
               	return INT_ERR;
	}

	/* EXEC SQL ALLOCATE       :c_cursor_psp_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )435;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_psp_id;
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
 if (sqlca.sqlcode < 0) goto epsp_error;
}


        
	/* EXEC SQL EXECUTE
              	BEGIN
                     	:hv_return_value := sp_ol_po_api_get_psp(:hv_action_id:ind_action_id,
                                                                 :c_cursor_psp_id);
                END;
       	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_po_api_get_psp ( :hv_action\
_id:ind_action_id , :c_cursor_psp_id ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )454;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_action_id;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_action_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&c_cursor_psp_id;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto epsp_error;
}



DEBUGLOG(("hv_return_value = [%d]\n", hv_return_value));	
	if (hv_return_value == 0) {
                for (;;) {
			myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);

                        ind_psp_id = -1;
                        ind_bank_code = -1;
                        ind_psp_ccy = -1;
                        ind_psp_country = -1;
                        ind_count = -1;
                        ind_amount = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_psp_id
                        INTO
                        	:v_psp_id:ind_psp_id,
                        	:v_bank_code:ind_bank_code,
                        	:v_psp_ccy:ind_psp_ccy,
                        	:v_psp_country:ind_psp_country,
                        	:v_count:ind_count,
                        	:v_amount:ind_amount; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 10;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )481;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_psp_id;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_psp_id;
                        sqlstm.sqhstl[1] = (unsigned long )13;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_psp_id;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_bank_code;
                        sqlstm.sqhstl[2] = (unsigned long )13;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_bank_code;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_psp_ccy;
                        sqlstm.sqhstl[3] = (unsigned long )6;
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_psp_ccy;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_psp_country;
                        sqlstm.sqhstl[4] = (unsigned long )5;
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_psp_country;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_count;
                        sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_count;
                        sqlstm.sqinds[5] = (         int  )0;
                        sqlstm.sqharm[5] = (unsigned long )0;
                        sqlstm.sqadto[5] = (unsigned short )0;
                        sqlstm.sqtdso[5] = (unsigned short )0;
                        sqlstm.sqhstv[6] = (unsigned char  *)&v_amount;
                        sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[6] = (         int  )0;
                        sqlstm.sqindv[6] = (         short *)&ind_amount;
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
                        if (sqlca.sqlcode == 1403) break;
                        if (sqlca.sqlcode < 0) goto epsp_error;
}



                	if (SQLCODE == SQL_NOT_FOUND) {
                	        break;
                	}

/*psp_id*/
                	if(ind_psp_id>=0){
                        	v_psp_id.arr[v_psp_id.len]='\0';
                        	PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("psp_id= [%s]\n",v_psp_id.arr));

                	}	
/*bank_code*/
                	if(ind_bank_code>=0){
                	        v_bank_code.arr[v_bank_code.len]='\0';
                	        PutField_CString(myHash,"bank_code",(const char*)v_bank_code.arr);
DEBUGLOG(("bank_code= [%s]\n",v_bank_code.arr));

                	}
/*psp_ccy*/
                	if(ind_psp_ccy>=0){
                	        v_psp_ccy.arr[v_psp_ccy.len]='\0';
                	        PutField_CString(myHash,"psp_ccy",(const char*)v_psp_ccy.arr);
DEBUGLOG(("psp_ccy= [%s]\n",v_psp_ccy.arr));
                	}

/*psp_country*/
                	if(ind_psp_country>=0){
                        	v_psp_country.arr[v_psp_country.len]='\0';
                        	PutField_CString(myHash,"psp_country",(const char*)v_psp_country.arr);
DEBUGLOG(("psp_country= [%s]\n",v_psp_country.arr));
                	}

/*count*/
	                if(ind_count<0)
        	                v_count = 0;

        		PutField_Int(myHash,"txn_count",v_count);
DEBUGLOG(("txn_count= [%d]\n",v_count));

/*amount*/
	                if(ind_amount<0)
        	                v_amount = 0.0;

                	PutField_Double(myHash,"total_amt",v_amount);
DEBUGLOG(("amount= [%lf]\n",v_amount));


                	iCnt++;

                	RecordSet_Add(myRec,myHash);
		}
	}

	/* EXEC SQL CLOSE :c_cursor_psp_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )524;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_psp_id;
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
 if (sqlca.sqlcode < 0) goto epsp_error;
}


        /* EXEC SQL FREE :c_cursor_psp_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )543;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_psp_id;
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
        if (sqlca.sqlcode < 0) goto epsp_error;
}



	if (iCnt > 0) {
DEBUGLOG(("GetExistingPsp Normal Exit\n"));
                return  PD_OK;
        } else {
DEBUGLOG(("GetExistingPsp Normal Exit, No Record\n"));
                return  PD_ERR;
        }

epsp_error:
DEBUGLOG(("GetExistingPsp_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE :c_cursor_psp_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )562;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_psp_id;
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
}


        /* EXEC SQL FREE :c_cursor_psp_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )581;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_psp_id;
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
}


        return PD_ERR;
}


int GetExistingPspOnlineMode(const hash_t *hRec, recordset_t* myRec)
{
        hash_t *myHash;

        int     iCnt = 0;
	char    *csTmp = NULL;

        /* EXEC SQL WHENEVER SQLERROR GOTO epspom_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		unsigned long   hv_action_id;

		short           ind_action_id = -1;

                short           hv_return_value;

                /* varchar         v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

                /* varchar         v_psp_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_psp_ccy;

                /* varchar         v_psp_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_psp_country;

                int             v_count;
                double          v_amount;

                short           ind_psp_id = -1;
                short           ind_psp_ccy = -1;
                short           ind_psp_country = -1;
                short           ind_count = -1;
                short           ind_amount = -1;

		SQL_CURSOR      c_cursor_psp_id;
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetExistingPspOnlineMode: Begin"));

	// action_id
        if(GetField_CString(hRec,"action_id",&csTmp)){
                hv_action_id = (unsigned long)ctol((const unsigned char*)csTmp,strlen(csTmp));
		ind_action_id = 0;
DEBUGLOG(("action_id = [%ld]\n",hv_action_id));
	} else {
DEBUGLOG(("action_id not found\n"));
               	return INT_ERR;
	}

       	/* EXEC SQL ALLOCATE       :c_cursor_psp_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )600;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_psp_id;
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
        if (sqlca.sqlcode < 0) goto epspom_error;
}


        
	/* EXEC SQL EXECUTE
              	BEGIN
                        :hv_return_value := sp_ol_po_api_get_psp_online(:hv_action_id:ind_action_id,
                                                                   	:c_cursor_psp_id);
               	END;
      	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_po_api_get_psp_online ( :hv\
_action_id:ind_action_id , :c_cursor_psp_id ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )619;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_action_id;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_action_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&c_cursor_psp_id;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto epspom_error;
}



DEBUGLOG(("hv_return_value = [%d]\n", hv_return_value));	
	if (hv_return_value == 0) {
                for (;;) {
                        myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);

			ind_psp_id = -1;
                        ind_psp_ccy = -1;
                        ind_psp_country = -1;
                        ind_count = -1;
                        ind_amount = -1;	

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_psp_id
                        INTO
                        	:v_psp_id:ind_psp_id,
                        	:v_psp_ccy:ind_psp_ccy,
                        	:v_psp_country:ind_psp_country,
                        	:v_count:ind_count,
                        	:v_amount:ind_amount; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 10;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )646;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_psp_id;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_psp_id;
                        sqlstm.sqhstl[1] = (unsigned long )13;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_psp_id;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_psp_ccy;
                        sqlstm.sqhstl[2] = (unsigned long )6;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_psp_ccy;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_psp_country;
                        sqlstm.sqhstl[3] = (unsigned long )5;
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_psp_country;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_count;
                        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_count;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_amount;
                        sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_amount;
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
                        if (sqlca.sqlcode == 1403) break;
                        if (sqlca.sqlcode < 0) goto epspom_error;
}



                	if (SQLCODE == SQL_NOT_FOUND) {
                        	break;
                	}

/*psp_id*/
                	if(ind_psp_id>=0){
                        	v_psp_id.arr[v_psp_id.len]='\0';
                        	PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("psp_id= [%s]\n",v_psp_id.arr));

                	}

/*psp_ccy*/
                	if(ind_psp_ccy>=0){
                	        v_psp_ccy.arr[v_psp_ccy.len]='\0';
                	        PutField_CString(myHash,"psp_ccy",(const char*)v_psp_ccy.arr);
DEBUGLOG(("psp_ccy= [%s]\n",v_psp_ccy.arr));
                	}

/*psp_country*/
	                if(ind_psp_country>=0){
	                        v_psp_country.arr[v_psp_country.len]='\0';
	                        PutField_CString(myHash,"psp_country",(const char*)v_psp_country.arr);
DEBUGLOG(("psp_country= [%s]\n",v_psp_country.arr));
	                }

/*count*/
        	        if(ind_count<0)
        	                v_count = 0;

        	        PutField_Int(myHash,"txn_count",v_count);
DEBUGLOG(("txn_count= [%d]\n",v_count));

/*amount*/
        	        if(ind_amount<0)
        	                v_amount = 0.0;

        	        PutField_Double(myHash,"total_amt",v_amount);
DEBUGLOG(("amount= [%lf]\n",v_amount));

			iCnt++;

                        RecordSet_Add(myRec,myHash);
                }
        }

        /* EXEC SQL CLOSE :c_cursor_psp_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )685;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_psp_id;
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
        if (sqlca.sqlcode < 0) goto epspom_error;
}


        /* EXEC SQL FREE :c_cursor_psp_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )704;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_psp_id;
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
        if (sqlca.sqlcode < 0) goto epspom_error;
}



        if (iCnt > 0) {
DEBUGLOG(("GetExistingPspOnlineMode Normal Exit\n"));
                return  PD_OK;
        } else {
DEBUGLOG(("GetExistingPspOnlineMode Normal Exit, No Record\n"));
                return  PD_ERR;
        }

epspom_error:
DEBUGLOG(("GetExistingPspOnlineMode_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE :c_cursor_psp_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )723;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_psp_id;
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
}


        /* EXEC SQL FREE :c_cursor_psp_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )742;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_psp_id;
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
}

	
        return PD_ERR;
}


int GetRecordsForPregen(const hash_t* hRec,recordset_t* myRec)
{
        hash_t *myHash;
	char    csBatchId[PD_TXN_SEQ_LEN+1];
        char*   csTmp;
	int     iCnt = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO getrecforpregen_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 
	
                unsigned long   hv_action_id;

		short 		ind_action_id = -1;

                short   	hv_return_value;

                unsigned long   v_batch_id;
		/* varchar         v_payout_group[PD_OFL_PAYOUT_GROUP_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_payout_group;

		int             v_pregen_ret_code;
		int             v_gen_ret_code;
                int             v_seq;
                /* varchar         v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

                /* varchar         v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

                /* varchar         v_to_bank_code[PD_AC_BANK_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_to_bank_code;

                int             v_file_id;
		/* varchar         v_merchant_payout_grp[PD_OFL_PAYOUT_GROUP_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_merchant_payout_grp;

                /* varchar         v_psp_payout_grp[PD_OFL_PAYOUT_GROUP_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_psp_payout_grp;

                /* varchar         v_request_currency[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_request_currency;

                double          v_request_amount;
                /* varchar         v_payout_currency[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_payout_currency;

                double          v_payout_amount;
                /* varchar         v_merchant_fee_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_merchant_fee_ccy;

                double          v_merchant_fee;
                int             v_status;
		/* varchar         v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

                /* varchar         v_merchant_ref[PD_MERCHANT_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar         v_service_code[PD_SERVICE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		/* varchar         v_txn_country[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_txn_country;

		/* varchar         v_identity_id[PD_IDENTITY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_identity_id;

		/* varchar         v_bank_name[PD_AC_BANK_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

		/* varchar         v_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

		/* varchar         v_branch[PD_BANK_BRANCH_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch;

		/* varchar         v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

		/* varchar         v_account_name[PD_AC_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_account_name;

		/* varchar         v_account_id[PD_AC_NO_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_id;

		/* varchar         v_remark[PD_REMARK_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;

		/* varchar         v_province[PD_PROVINCE_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } v_province;

                /* varchar         v_phone_no[PD_PHONE_NO_LEN]; */ 
struct { unsigned short len; unsigned char arr[30]; } v_phone_no;

                /* varchar         v_city[PD_CITY_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } v_city;

	
                short 		ind_batch_id = -1;
                short           ind_payout_group = -1;
                short           ind_pregen_ret_code = -1;
                short           ind_gen_ret_code = -1;
                short           ind_seq = -1;
                short           ind_txn_id = -1;
                short           ind_psp_id = -1;
                short           ind_to_bank_code = -1;
                short           ind_file_id = -1;
		short		ind_merchant_payout_grp = -1;
		short		ind_psp_payout_grp = -1;
		short		ind_request_currency = -1;
		short		ind_request_amount = -1;
		short		ind_payout_currency = -1;
		short		ind_payout_amount = -1;
		short		ind_merchant_fee_ccy = -1;
		short		ind_merchant_fee = -1;
		short		ind_status = -1;
		short           ind_merchant_id = -1;
                short           ind_merchant_ref = -1;
		short           ind_service_code = -1;
		short           ind_txn_country = -1;
		short           ind_identity_id= -1;
		short           ind_bank_name = -1;
		short           ind_bank_code = -1;
		short           ind_branch= -1;
                short           ind_bank_acct_num = -1;
		short           ind_account_name= -1;
                short           ind_account_id= -1;
		short           ind_remark = -1;
		short           ind_province = -1;
                short           ind_phone_no = -1;
                short           ind_city = -1;

		SQL_CURSOR      c_cursor_rec;
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetRecordsForPregen: Begin\n"));

	// action_id
        if(GetField_CString(hRec,"action_id",&csTmp)){
                hv_action_id = (unsigned long)ctol((const unsigned char*)csTmp,strlen(csTmp));
		ind_action_id = 0;
DEBUGLOG(("action_id = [%ld]\n",hv_action_id));
	} else {
DEBUGLOG(("action_id not found\n"));
             	return INT_ERR;
        }

	/* EXEC SQL ALLOCATE       :c_cursor_rec; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )761;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_rec;
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
 if (sqlca.sqlcode < 0) goto getrecforpregen_error;
}



      	/* EXEC SQL EXECUTE
             	BEGIN
                     	:hv_return_value := sp_ol_po_api_pregen_get_rec(:hv_action_id:ind_action_id,
                                                                        :c_cursor_rec);
            	END;
      	END-EXEC; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 12;
       sqlstm.arrsiz = 10;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.stmt = "begin :hv_return_value := sp_ol_po_api_pregen_get_rec\
 ( :hv_action_id:ind_action_id , :c_cursor_rec ) ; END ;";
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )780;
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
       sqlstm.sqhstv[1] = (unsigned char  *)&hv_action_id;
       sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
       sqlstm.sqhsts[1] = (         int  )0;
       sqlstm.sqindv[1] = (         short *)&ind_action_id;
       sqlstm.sqinds[1] = (         int  )0;
       sqlstm.sqharm[1] = (unsigned long )0;
       sqlstm.sqadto[1] = (unsigned short )0;
       sqlstm.sqtdso[1] = (unsigned short )0;
       sqlstm.sqhstv[2] = (unsigned char  *)&c_cursor_rec;
       sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
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
       if (sqlca.sqlcode < 0) goto getrecforpregen_error;
}



//DEBUGLOG(("hv_return_value = [%d]\n", hv_return_value));
DEBUGLOG(("hv_return_value = [%d], Start LOOP...\n", hv_return_value));
	if (hv_return_value > 0) {
                for (;;) {
			myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);

                        ind_batch_id = -1;
			ind_payout_group = -1;
			ind_pregen_ret_code = -1;
			ind_gen_ret_code = -1;
                        ind_seq = -1;
                        ind_txn_id = -1;
                        ind_psp_id = -1;
                        ind_to_bank_code = -1;
                        ind_file_id = -1;
			ind_merchant_payout_grp = -1;
               		ind_psp_payout_grp = -1;
               		ind_request_currency = -1;
               		ind_request_amount = -1;
             		ind_payout_currency = -1;
            		ind_payout_amount = -1;
             		ind_merchant_fee_ccy = -1;
               		ind_merchant_fee = -1;
                	ind_status = -1;
			ind_merchant_id = -1;
			ind_merchant_ref = -1;
			ind_service_code = -1;
			ind_txn_country = -1;
               		ind_identity_id= -1;
               		ind_bank_name = -1;
                	ind_bank_code = -1;
              		ind_branch= -1;
              		ind_bank_acct_num = -1;
                	ind_account_name= -1;
               		ind_account_id= -1;
             		ind_remark = -1;
             		ind_province = -1;
              		ind_phone_no = -1;
                	ind_city = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_rec
                        INTO
				:v_batch_id:ind_batch_id,
				:v_payout_group:ind_payout_group,
				:v_pregen_ret_code:ind_pregen_ret_code,
				:v_gen_ret_code:ind_gen_ret_code,
                        	:v_seq:ind_seq,
                        	:v_txn_id:ind_txn_id,
                        	:v_psp_id:ind_psp_id,
                        	:v_to_bank_code:ind_to_bank_code,
                        	:v_file_id:ind_file_id,
                        	:v_merchant_payout_grp:ind_merchant_payout_grp,
                        	:v_psp_payout_grp:ind_psp_payout_grp,
                        	:v_request_currency:ind_request_currency,
                        	:v_request_amount:ind_request_amount,
                        	:v_payout_currency:ind_payout_currency,
                        	:v_payout_amount:ind_payout_amount,
                        	:v_merchant_fee_ccy:ind_merchant_fee_ccy,
                        	:v_merchant_fee:ind_merchant_fee,
                        	:v_status:ind_status,
				:v_merchant_id:ind_merchant_id,
				:v_merchant_ref:ind_merchant_ref,
				:v_service_code:ind_service_code,
				:v_txn_country:ind_txn_country,
                        	:v_identity_id:ind_identity_id,
                        	:v_bank_name:ind_bank_name,
                        	:v_bank_code:ind_bank_code,
                        	:v_branch:ind_branch,
                        	:v_bank_acct_num:ind_bank_acct_num,
                        	:v_account_name:ind_account_name,
                        	:v_account_id:ind_account_id,
                        	:v_remark:ind_remark,
                        	:v_province:ind_province,
                        	:v_phone_no:ind_phone_no,
                        	:v_city:ind_city; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 34;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )807;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_rec;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_batch_id;
                        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_batch_id;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_payout_group;
                        sqlstm.sqhstl[2] = (unsigned long )5;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_payout_group;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_pregen_ret_code;
                        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_pregen_ret_code;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_gen_ret_code;
                        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_gen_ret_code;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_seq;
                        sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_seq;
                        sqlstm.sqinds[5] = (         int  )0;
                        sqlstm.sqharm[5] = (unsigned long )0;
                        sqlstm.sqadto[5] = (unsigned short )0;
                        sqlstm.sqtdso[5] = (unsigned short )0;
                        sqlstm.sqhstv[6] = (unsigned char  *)&v_txn_id;
                        sqlstm.sqhstl[6] = (unsigned long )19;
                        sqlstm.sqhsts[6] = (         int  )0;
                        sqlstm.sqindv[6] = (         short *)&ind_txn_id;
                        sqlstm.sqinds[6] = (         int  )0;
                        sqlstm.sqharm[6] = (unsigned long )0;
                        sqlstm.sqadto[6] = (unsigned short )0;
                        sqlstm.sqtdso[6] = (unsigned short )0;
                        sqlstm.sqhstv[7] = (unsigned char  *)&v_psp_id;
                        sqlstm.sqhstl[7] = (unsigned long )13;
                        sqlstm.sqhsts[7] = (         int  )0;
                        sqlstm.sqindv[7] = (         short *)&ind_psp_id;
                        sqlstm.sqinds[7] = (         int  )0;
                        sqlstm.sqharm[7] = (unsigned long )0;
                        sqlstm.sqadto[7] = (unsigned short )0;
                        sqlstm.sqtdso[7] = (unsigned short )0;
                        sqlstm.sqhstv[8] = (unsigned char  *)&v_to_bank_code;
                        sqlstm.sqhstl[8] = (unsigned long )28;
                        sqlstm.sqhsts[8] = (         int  )0;
                        sqlstm.sqindv[8] = (         short *)&ind_to_bank_code;
                        sqlstm.sqinds[8] = (         int  )0;
                        sqlstm.sqharm[8] = (unsigned long )0;
                        sqlstm.sqadto[8] = (unsigned short )0;
                        sqlstm.sqtdso[8] = (unsigned short )0;
                        sqlstm.sqhstv[9] = (unsigned char  *)&v_file_id;
                        sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[9] = (         int  )0;
                        sqlstm.sqindv[9] = (         short *)&ind_file_id;
                        sqlstm.sqinds[9] = (         int  )0;
                        sqlstm.sqharm[9] = (unsigned long )0;
                        sqlstm.sqadto[9] = (unsigned short )0;
                        sqlstm.sqtdso[9] = (unsigned short )0;
                        sqlstm.sqhstv[10] = (unsigned char  *)&v_merchant_payout_grp;
                        sqlstm.sqhstl[10] = (unsigned long )5;
                        sqlstm.sqhsts[10] = (         int  )0;
                        sqlstm.sqindv[10] = (         short *)&ind_merchant_payout_grp;
                        sqlstm.sqinds[10] = (         int  )0;
                        sqlstm.sqharm[10] = (unsigned long )0;
                        sqlstm.sqadto[10] = (unsigned short )0;
                        sqlstm.sqtdso[10] = (unsigned short )0;
                        sqlstm.sqhstv[11] = (unsigned char  *)&v_psp_payout_grp;
                        sqlstm.sqhstl[11] = (unsigned long )5;
                        sqlstm.sqhsts[11] = (         int  )0;
                        sqlstm.sqindv[11] = (         short *)&ind_psp_payout_grp;
                        sqlstm.sqinds[11] = (         int  )0;
                        sqlstm.sqharm[11] = (unsigned long )0;
                        sqlstm.sqadto[11] = (unsigned short )0;
                        sqlstm.sqtdso[11] = (unsigned short )0;
                        sqlstm.sqhstv[12] = (unsigned char  *)&v_request_currency;
                        sqlstm.sqhstl[12] = (unsigned long )6;
                        sqlstm.sqhsts[12] = (         int  )0;
                        sqlstm.sqindv[12] = (         short *)&ind_request_currency;
                        sqlstm.sqinds[12] = (         int  )0;
                        sqlstm.sqharm[12] = (unsigned long )0;
                        sqlstm.sqadto[12] = (unsigned short )0;
                        sqlstm.sqtdso[12] = (unsigned short )0;
                        sqlstm.sqhstv[13] = (unsigned char  *)&v_request_amount;
                        sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[13] = (         int  )0;
                        sqlstm.sqindv[13] = (         short *)&ind_request_amount;
                        sqlstm.sqinds[13] = (         int  )0;
                        sqlstm.sqharm[13] = (unsigned long )0;
                        sqlstm.sqadto[13] = (unsigned short )0;
                        sqlstm.sqtdso[13] = (unsigned short )0;
                        sqlstm.sqhstv[14] = (unsigned char  *)&v_payout_currency;
                        sqlstm.sqhstl[14] = (unsigned long )6;
                        sqlstm.sqhsts[14] = (         int  )0;
                        sqlstm.sqindv[14] = (         short *)&ind_payout_currency;
                        sqlstm.sqinds[14] = (         int  )0;
                        sqlstm.sqharm[14] = (unsigned long )0;
                        sqlstm.sqadto[14] = (unsigned short )0;
                        sqlstm.sqtdso[14] = (unsigned short )0;
                        sqlstm.sqhstv[15] = (unsigned char  *)&v_payout_amount;
                        sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[15] = (         int  )0;
                        sqlstm.sqindv[15] = (         short *)&ind_payout_amount;
                        sqlstm.sqinds[15] = (         int  )0;
                        sqlstm.sqharm[15] = (unsigned long )0;
                        sqlstm.sqadto[15] = (unsigned short )0;
                        sqlstm.sqtdso[15] = (unsigned short )0;
                        sqlstm.sqhstv[16] = (unsigned char  *)&v_merchant_fee_ccy;
                        sqlstm.sqhstl[16] = (unsigned long )6;
                        sqlstm.sqhsts[16] = (         int  )0;
                        sqlstm.sqindv[16] = (         short *)&ind_merchant_fee_ccy;
                        sqlstm.sqinds[16] = (         int  )0;
                        sqlstm.sqharm[16] = (unsigned long )0;
                        sqlstm.sqadto[16] = (unsigned short )0;
                        sqlstm.sqtdso[16] = (unsigned short )0;
                        sqlstm.sqhstv[17] = (unsigned char  *)&v_merchant_fee;
                        sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[17] = (         int  )0;
                        sqlstm.sqindv[17] = (         short *)&ind_merchant_fee;
                        sqlstm.sqinds[17] = (         int  )0;
                        sqlstm.sqharm[17] = (unsigned long )0;
                        sqlstm.sqadto[17] = (unsigned short )0;
                        sqlstm.sqtdso[17] = (unsigned short )0;
                        sqlstm.sqhstv[18] = (unsigned char  *)&v_status;
                        sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[18] = (         int  )0;
                        sqlstm.sqindv[18] = (         short *)&ind_status;
                        sqlstm.sqinds[18] = (         int  )0;
                        sqlstm.sqharm[18] = (unsigned long )0;
                        sqlstm.sqadto[18] = (unsigned short )0;
                        sqlstm.sqtdso[18] = (unsigned short )0;
                        sqlstm.sqhstv[19] = (unsigned char  *)&v_merchant_id;
                        sqlstm.sqhstl[19] = (unsigned long )18;
                        sqlstm.sqhsts[19] = (         int  )0;
                        sqlstm.sqindv[19] = (         short *)&ind_merchant_id;
                        sqlstm.sqinds[19] = (         int  )0;
                        sqlstm.sqharm[19] = (unsigned long )0;
                        sqlstm.sqadto[19] = (unsigned short )0;
                        sqlstm.sqtdso[19] = (unsigned short )0;
                        sqlstm.sqhstv[20] = (unsigned char  *)&v_merchant_ref;
                        sqlstm.sqhstl[20] = (unsigned long )53;
                        sqlstm.sqhsts[20] = (         int  )0;
                        sqlstm.sqindv[20] = (         short *)&ind_merchant_ref;
                        sqlstm.sqinds[20] = (         int  )0;
                        sqlstm.sqharm[20] = (unsigned long )0;
                        sqlstm.sqadto[20] = (unsigned short )0;
                        sqlstm.sqtdso[20] = (unsigned short )0;
                        sqlstm.sqhstv[21] = (unsigned char  *)&v_service_code;
                        sqlstm.sqhstl[21] = (unsigned long )6;
                        sqlstm.sqhsts[21] = (         int  )0;
                        sqlstm.sqindv[21] = (         short *)&ind_service_code;
                        sqlstm.sqinds[21] = (         int  )0;
                        sqlstm.sqharm[21] = (unsigned long )0;
                        sqlstm.sqadto[21] = (unsigned short )0;
                        sqlstm.sqtdso[21] = (unsigned short )0;
                        sqlstm.sqhstv[22] = (unsigned char  *)&v_txn_country;
                        sqlstm.sqhstl[22] = (unsigned long )5;
                        sqlstm.sqhsts[22] = (         int  )0;
                        sqlstm.sqindv[22] = (         short *)&ind_txn_country;
                        sqlstm.sqinds[22] = (         int  )0;
                        sqlstm.sqharm[22] = (unsigned long )0;
                        sqlstm.sqadto[22] = (unsigned short )0;
                        sqlstm.sqtdso[22] = (unsigned short )0;
                        sqlstm.sqhstv[23] = (unsigned char  *)&v_identity_id;
                        sqlstm.sqhstl[23] = (unsigned long )28;
                        sqlstm.sqhsts[23] = (         int  )0;
                        sqlstm.sqindv[23] = (         short *)&ind_identity_id;
                        sqlstm.sqinds[23] = (         int  )0;
                        sqlstm.sqharm[23] = (unsigned long )0;
                        sqlstm.sqadto[23] = (unsigned short )0;
                        sqlstm.sqtdso[23] = (unsigned short )0;
                        sqlstm.sqhstv[24] = (unsigned char  *)&v_bank_name;
                        sqlstm.sqhstl[24] = (unsigned long )153;
                        sqlstm.sqhsts[24] = (         int  )0;
                        sqlstm.sqindv[24] = (         short *)&ind_bank_name;
                        sqlstm.sqinds[24] = (         int  )0;
                        sqlstm.sqharm[24] = (unsigned long )0;
                        sqlstm.sqadto[24] = (unsigned short )0;
                        sqlstm.sqtdso[24] = (unsigned short )0;
                        sqlstm.sqhstv[25] = (unsigned char  *)&v_bank_code;
                        sqlstm.sqhstl[25] = (unsigned long )13;
                        sqlstm.sqhsts[25] = (         int  )0;
                        sqlstm.sqindv[25] = (         short *)&ind_bank_code;
                        sqlstm.sqinds[25] = (         int  )0;
                        sqlstm.sqharm[25] = (unsigned long )0;
                        sqlstm.sqadto[25] = (unsigned short )0;
                        sqlstm.sqtdso[25] = (unsigned short )0;
                        sqlstm.sqhstv[26] = (unsigned char  *)&v_branch;
                        sqlstm.sqhstl[26] = (unsigned long )153;
                        sqlstm.sqhsts[26] = (         int  )0;
                        sqlstm.sqindv[26] = (         short *)&ind_branch;
                        sqlstm.sqinds[26] = (         int  )0;
                        sqlstm.sqharm[26] = (unsigned long )0;
                        sqlstm.sqadto[26] = (unsigned short )0;
                        sqlstm.sqtdso[26] = (unsigned short )0;
                        sqlstm.sqhstv[27] = (unsigned char  *)&v_bank_acct_num;
                        sqlstm.sqhstl[27] = (unsigned long )53;
                        sqlstm.sqhsts[27] = (         int  )0;
                        sqlstm.sqindv[27] = (         short *)&ind_bank_acct_num;
                        sqlstm.sqinds[27] = (         int  )0;
                        sqlstm.sqharm[27] = (unsigned long )0;
                        sqlstm.sqadto[27] = (unsigned short )0;
                        sqlstm.sqtdso[27] = (unsigned short )0;
                        sqlstm.sqhstv[28] = (unsigned char  *)&v_account_name;
                        sqlstm.sqhstl[28] = (unsigned long )103;
                        sqlstm.sqhsts[28] = (         int  )0;
                        sqlstm.sqindv[28] = (         short *)&ind_account_name;
                        sqlstm.sqinds[28] = (         int  )0;
                        sqlstm.sqharm[28] = (unsigned long )0;
                        sqlstm.sqadto[28] = (unsigned short )0;
                        sqlstm.sqtdso[28] = (unsigned short )0;
                        sqlstm.sqhstv[29] = (unsigned char  *)&v_account_id;
                        sqlstm.sqhstl[29] = (unsigned long )28;
                        sqlstm.sqhsts[29] = (         int  )0;
                        sqlstm.sqindv[29] = (         short *)&ind_account_id;
                        sqlstm.sqinds[29] = (         int  )0;
                        sqlstm.sqharm[29] = (unsigned long )0;
                        sqlstm.sqadto[29] = (unsigned short )0;
                        sqlstm.sqtdso[29] = (unsigned short )0;
                        sqlstm.sqhstv[30] = (unsigned char  *)&v_remark;
                        sqlstm.sqhstl[30] = (unsigned long )258;
                        sqlstm.sqhsts[30] = (         int  )0;
                        sqlstm.sqindv[30] = (         short *)&ind_remark;
                        sqlstm.sqinds[30] = (         int  )0;
                        sqlstm.sqharm[30] = (unsigned long )0;
                        sqlstm.sqadto[30] = (unsigned short )0;
                        sqlstm.sqtdso[30] = (unsigned short )0;
                        sqlstm.sqhstv[31] = (unsigned char  *)&v_province;
                        sqlstm.sqhstl[31] = (unsigned long )102;
                        sqlstm.sqhsts[31] = (         int  )0;
                        sqlstm.sqindv[31] = (         short *)&ind_province;
                        sqlstm.sqinds[31] = (         int  )0;
                        sqlstm.sqharm[31] = (unsigned long )0;
                        sqlstm.sqadto[31] = (unsigned short )0;
                        sqlstm.sqtdso[31] = (unsigned short )0;
                        sqlstm.sqhstv[32] = (unsigned char  *)&v_phone_no;
                        sqlstm.sqhstl[32] = (unsigned long )32;
                        sqlstm.sqhsts[32] = (         int  )0;
                        sqlstm.sqindv[32] = (         short *)&ind_phone_no;
                        sqlstm.sqinds[32] = (         int  )0;
                        sqlstm.sqharm[32] = (unsigned long )0;
                        sqlstm.sqadto[32] = (unsigned short )0;
                        sqlstm.sqtdso[32] = (unsigned short )0;
                        sqlstm.sqhstv[33] = (unsigned char  *)&v_city;
                        sqlstm.sqhstl[33] = (unsigned long )102;
                        sqlstm.sqhsts[33] = (         int  )0;
                        sqlstm.sqindv[33] = (         short *)&ind_city;
                        sqlstm.sqinds[33] = (         int  )0;
                        sqlstm.sqharm[33] = (unsigned long )0;
                        sqlstm.sqadto[33] = (unsigned short )0;
                        sqlstm.sqtdso[33] = (unsigned short )0;
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
                        if (sqlca.sqlcode == 1403) break;
                        if (sqlca.sqlcode < 0) goto getrecforpregen_error;
}



                	if (SQLCODE == SQL_NOT_FOUND) {
                	        break;
                	}

//batch_id
			if(ind_batch_id>=0){
				sprintf(csBatchId, "%ld", v_batch_id);
        	                PutField_CString(myHash,"batch_id",csBatchId);
//DEBUGLOG(("batch_id= [%s]\n",csBatchId));
        	        }

//payout_group
                	if(ind_payout_group>=0){
                        	v_payout_group.arr[v_payout_group.len]='\0';
                        	PutField_CString(myHash,"payout_group",(const char*)v_payout_group.arr);
//DEBUGLOG(("payout_group= [%s]\n",v_payout_group.arr));
                	}

//pregen_ret_code
                	if(ind_pregen_ret_code>=0){
                        	PutField_Int(myHash,"pregen_ret_code",v_pregen_ret_code);
//DEBUGLOG(("pregen_ret_code= [%d]\n",v_pregen_ret_code));
                	}

//gen_ret_code
                        if(ind_gen_ret_code>=0){
                                PutField_Int(myHash,"gen_ret_code",v_gen_ret_code);
//DEBUGLOG(("gen_ret_code= [%d]\n",v_gen_ret_code));
                        }

//seq
	                if(ind_seq>=0){
	                        PutField_Int(myHash,"seq",v_seq);
//DEBUGLOG(("seq= [%d]\n",v_seq));
	                }

//txn_id
	                if(ind_txn_id>=0){
	                        v_txn_id.arr[v_txn_id.len]='\0';
	                        PutField_CString(myHash,"txn_id",(const char*)v_txn_id.arr);
//DEBUGLOG(("txn_id= [%s]\n",v_txn_id.arr));
	                }

//psp_id
        	        if(ind_psp_id>=0){
        	                v_psp_id.arr[v_psp_id.len]='\0';
        	                PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
//DEBUGLOG(("psp_id= [%s]\n",v_psp_id.arr));
        	        }

//to_bank_code
        	        if(ind_to_bank_code>=0){
        	                v_to_bank_code.arr[v_to_bank_code.len]='\0';
        	                PutField_CString(myHash,"to_bank_code",(const char*)v_to_bank_code.arr);
//DEBUGLOG(("to_bank_code= [%s]\n",v_to_bank_code.arr));
        	        }

//file_id
        	        if(ind_file_id>=0){
        	                PutField_Int(myHash,"file_id",v_file_id);
//DEBUGLOG(("file_id= [%d]\n",v_file_id));
        	        }

//merchant_payout_grp
                	if (ind_merchant_payout_grp >= 0) {
                        	v_merchant_payout_grp.arr[v_merchant_payout_grp.len] = '\0';
                        	PutField_CString(myHash, "merchant_payout_grp", (const char*)v_merchant_payout_grp.arr);
//DEBUGLOG(("merchant_payout_grp = [%s]\n", v_merchant_payout_grp.arr));
                	}

//psp_payout_grp
                	if (ind_psp_payout_grp >= 0) {
                        	v_psp_payout_grp.arr[v_psp_payout_grp.len] = '\0';
                        	PutField_CString(myHash, "psp_payout_grp", (const char*)v_psp_payout_grp.arr);
//DEBUGLOG(("psp_payout_grp = [%s]\n", v_psp_payout_grp.arr));
                	}

//request_currency
                	if (ind_request_currency >= 0) {
                        	v_request_currency.arr[v_request_currency.len] = '\0';
                        	PutField_CString(myHash, "request_currency", (const char*)v_request_currency.arr);
//DEBUGLOG(("request_currency = [%s]\n", v_request_currency.arr));
                	}
	
//request_amount
                	if (ind_request_amount >= 0) {
                        	PutField_Double(myHash, "request_amount", v_request_amount);
//DEBUGLOG(("request_amount = [%f]\n", v_request_amount));
                	}

//payout_currency
                	if (ind_payout_currency >= 0) {
                        	v_payout_currency.arr[v_payout_currency.len] = '\0';
                        	PutField_CString(myHash, "payout_currency", (const char*)v_payout_currency.arr);
//DEBUGLOG(("payout_currency = [%s]\n", v_payout_currency.arr));
                	}

//payout_amount
                	if (ind_payout_amount >= 0) {
                        	PutField_Double(myHash, "payout_amount", v_payout_amount);
//DEBUGLOG(("payout_amount = [%f]\n", v_payout_amount));
                	}

//merchant_fee_ccy
                	if (ind_merchant_fee_ccy >= 0) {
                        	v_merchant_fee_ccy.arr[v_merchant_fee_ccy.len] = '\0';
                        	PutField_CString(myHash, "merchant_fee_ccy", (const char*)v_merchant_fee_ccy.arr);
//DEBUGLOG(("merchant_fee_ccy = [%s]\n", v_merchant_fee_ccy.arr));
                	}

//merchant_fee
                	if (ind_merchant_fee >= 0) {
                	        PutField_Double(myHash, "merchant_fee", v_merchant_fee);
//DEBUGLOG(("merchant_fee = [%f]\n", v_merchant_fee));
                	}

//status
                	if (ind_status >= 0) {
                	        PutField_Int(myHash, "status", v_status);
//DEBUGLOG(("status = [%f]\n", v_status));
                	}

//merchant_id
			if (ind_merchant_id >= 0) {
                        	v_merchant_id.arr[v_merchant_id.len] ='\0';
                        	PutField_CString(myHash,"merchant_id",(const char*)v_merchant_id.arr);
//DEBUGLOG(("merchant_id = [%s]\n",v_merchant_id.arr));
                	}

//merchant_ref 
                	if (ind_merchant_ref >= 0) {
                        	v_merchant_ref.arr[v_merchant_ref.len] ='\0';
                        	PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
//DEBUGLOG(("merchant_ref = [%s]\n",v_merchant_ref.arr));
                	}

//service_code
			if (ind_service_code >= 0) {
                        	v_service_code.arr[v_service_code.len] ='\0';
                        	PutField_CString(myHash,"service_code",(const char*)v_service_code.arr);
//DEBUGLOG(("service_code = [%s]\n",v_service_code.arr));
                	}

//txn country
                	if (ind_txn_country  >=  0) {
                        	v_txn_country.arr[v_txn_country.len] = '\0';
                        	PutField_CString(myHash,"txn_country",(const char*)v_txn_country.arr);
//DEBUGLOG(("txn_country = [%s]\n",v_txn_country.arr));
                	}

//identity_id
			if (ind_identity_id>=  0) {
                 	       v_identity_id.arr[v_identity_id.len] = '\0';
                 	       PutField_CString(myHash,"identity_id",(const char*)v_identity_id.arr);
//DEBUGLOG(("identity_id = [%s]\n",v_identity_id.arr));
                	}

//bank_name
			if (ind_bank_name >= 0) {
                        	v_bank_name.arr[v_bank_name.len] = '\0';
                        	PutField_CString(myHash,"bank_name",(const char*)v_bank_name.arr);
//DEBUGLOG(("bank_name = [%s]\n",v_bank_name.arr));
                	}

//bank_code
			if (ind_bank_code  >=  0) {
                        	v_bank_code.arr[v_bank_code.len] = '\0';
                        	PutField_CString(myHash,"bank_code",(const char*)v_bank_code.arr);
//DEBUGLOG(("bank_code = [%s]\n",v_bank_code.arr));
                	}	

//branch
			if (ind_branch>=  0) {
                        	v_branch.arr[v_branch.len] = '\0';
                        	PutField_CString(myHash,"branch",(const char*)v_branch.arr);
//DEBUGLOG(("branch = [%s]\n",v_branch.arr));
                	}

//bank_acct_num
			if (ind_bank_acct_num>=  0) {
                        	v_bank_acct_num.arr[v_bank_acct_num.len] = '\0';
                        	PutField_CString(myHash,"bank_acct_num",(const char*)v_bank_acct_num.arr);
//DEBUGLOG(("bank_acct_num = [%s]\n",v_bank_acct_num.arr));
                	}

//account_name
			if (ind_account_name>=  0) {
                        	v_account_name.arr[v_account_name.len] = '\0';
                        	PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
//DEBUGLOG(("account_name = [%s]\n",v_account_name.arr));
                	}

//account_id
			if (ind_account_id>=  0) {
                        	v_account_id.arr[v_account_id.len] = '\0';
                        	PutField_CString(myHash,"account_id",(const char*)v_account_id.arr);
//DEBUGLOG(("account_id = [%s]\n",v_account_id.arr));
                	}

//remark
			if (ind_remark>=  0) {
                        	v_remark.arr[v_remark.len] = '\0';
                        	PutField_CString(myHash,"remark",(const char*)v_remark.arr);
//DEBUGLOG(("remark = [%s]\n",v_remark.arr));
               	 	}

//province
			if (ind_province >= 0) {
                        	v_province.arr[v_province.len] = '\0';
                        	PutField_CString(myHash,"province",(const char*)v_province.arr);
//DEBUGLOG(("province = [%s]\n",v_province.arr));
                	}

//phone_no
			if (ind_phone_no >= 0) {
                        	v_phone_no.arr[v_phone_no.len] = '\0';
                        	PutField_CString(myHash,"phone_no",(const char*)v_phone_no.arr);
//DEBUGLOG(("phone_no = [%s]\n",v_phone_no.arr));
                	}


//city
			if (ind_city >= 0) {
                        	v_city.arr[v_city.len] = '\0';
                        	PutField_CString(myHash,"city",(const char*)v_city.arr);
//DEBUGLOG(("city = [%s]\n",v_city.arr));
                	}


			iCnt++;
			
			RecordSet_Add(myRec,myHash);
                }
	}

        /* EXEC SQL CLOSE :c_cursor_rec; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 34;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )958;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_rec;
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
        if (sqlca.sqlcode < 0) goto getrecforpregen_error;
}


        /* EXEC SQL FREE :c_cursor_rec; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 34;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )977;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_rec;
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
        if (sqlca.sqlcode < 0) goto getrecforpregen_error;
}


	
        if (iCnt > 0) {
DEBUGLOG(("GetRecordsForPregen Normal Exit\n"));
                return  PD_OK;
        } else {
DEBUGLOG(("GetRecordsForPregen No Records Found!!\n"));
                return  PD_ERR;
        }	

getrecforpregen_error:
DEBUGLOG(("getrecforpregen_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPayoutApiPregenDT_GetRecordsForPregen: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE :c_cursor_rec; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 34;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )996;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_rec;
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
}


        /* EXEC SQL FREE :c_cursor_rec; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 34;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1015;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_rec;
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
}


        return PD_ERR;
}


int GetRecordsForGen(const hash_t* hRec,recordset_t* myRec)
{
        hash_t *myHash;
	char    csBatchId[PD_TXN_SEQ_LEN+1];
        char*   csTmp;
        int     iCnt = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO getrecforgen_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                unsigned long   hv_action_id;

		short           ind_action_id = -1;

                short           hv_return_value;

                unsigned long   v_batch_id;
		/* varchar         v_payout_group[PD_OFL_PAYOUT_GROUP_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_payout_group;

                int             v_pregen_ret_code;
                int             v_gen_ret_code;
                int             v_seq;
                /* varchar         v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

                /* varchar         v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

                /* varchar         v_to_bank_code[PD_AC_BANK_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_to_bank_code;

                int             v_file_id;
		/* varchar         v_merchant_payout_grp[PD_OFL_PAYOUT_GROUP_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_merchant_payout_grp;

                /* varchar         v_psp_payout_grp[PD_OFL_PAYOUT_GROUP_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_psp_payout_grp;

                /* varchar         v_request_currency[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_request_currency;

                double          v_request_amount;
                /* varchar         v_payout_currency[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_payout_currency;

                double          v_payout_amount;
                /* varchar         v_merchant_fee_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_merchant_fee_ccy;

                double          v_merchant_fee;
                int             v_status;
                /* varchar         v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

                /* varchar         v_merchant_ref[PD_MERCHANT_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

                /* varchar         v_service_code[PD_SERVICE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

                /* varchar         v_txn_country[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_txn_country;

                /* varchar         v_identity_id[PD_IDENTITY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_identity_id;

                /* varchar         v_bank_name[PD_AC_BANK_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

                /* varchar         v_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

                /* varchar         v_branch[PD_BANK_BRANCH_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch;

                /* varchar         v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

                /* varchar         v_account_name[PD_AC_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_account_name;

                /* varchar         v_account_id[PD_AC_NO_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_id;

                /* varchar         v_remark[PD_REMARK_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;

                /* varchar         v_province[PD_PROVINCE_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } v_province;

                /* varchar         v_phone_no[PD_PHONE_NO_LEN]; */ 
struct { unsigned short len; unsigned char arr[30]; } v_phone_no;

                /* varchar         v_city[PD_CITY_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } v_city;


                short           ind_batch_id = -1;
		short           ind_payout_group = -1;
                short           ind_pregen_ret_code = -1;
                short           ind_gen_ret_code = -1;
                short           ind_seq = -1;
                short           ind_txn_id = -1;
                short           ind_psp_id = -1;
                short           ind_to_bank_code = -1;
                short           ind_file_id = -1;
		short           ind_merchant_payout_grp = -1;
                short           ind_psp_payout_grp = -1;
                short           ind_request_currency = -1;
                short           ind_request_amount = -1;
                short           ind_payout_currency = -1;
                short           ind_payout_amount = -1;
                short           ind_merchant_fee_ccy = -1;
                short           ind_merchant_fee = -1;
                short           ind_status = -1;
                short           ind_merchant_id = -1;
                short           ind_merchant_ref = -1;
                short           ind_service_code = -1;
                short           ind_txn_country = -1;
                short           ind_identity_id= -1;
                short           ind_bank_name = -1;
                short           ind_bank_code = -1;
                short           ind_branch= -1;
                short           ind_bank_acct_num = -1;
                short           ind_account_name= -1;
                short           ind_account_id= -1;
                short           ind_remark = -1;
                short           ind_province = -1;
                short           ind_phone_no = -1;
                short           ind_city = -1;

		SQL_CURSOR      c_cursor_rec;
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetRecordsForGen: Begin"));

        // action_id
        if(GetField_CString(hRec,"action_id",&csTmp)){
                hv_action_id = (unsigned long)ctol((const unsigned char*)csTmp,strlen(csTmp));
		ind_action_id = 0;
DEBUGLOG(("action_id = [%ld]\n",hv_action_id));
	} else {
DEBUGLOG(("action_id not found\n"));
               	return INT_ERR;
        }

	/* EXEC SQL ALLOCATE       :c_cursor_rec; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 34;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1034;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_rec;
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
 if (sqlca.sqlcode < 0) goto getrecforgen_error;
}



      	/* EXEC SQL EXECUTE
            	BEGIN
                     	:hv_return_value := sp_ol_po_api_gen_get_rec(:hv_action_id:ind_action_id,
                                                                     :c_cursor_rec);
              	END;
       	END-EXEC; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 12;
       sqlstm.arrsiz = 34;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.stmt = "begin :hv_return_value := sp_ol_po_api_gen_get_rec ( \
:hv_action_id:ind_action_id , :c_cursor_rec ) ; END ;";
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )1053;
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
       sqlstm.sqhstv[1] = (unsigned char  *)&hv_action_id;
       sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
       sqlstm.sqhsts[1] = (         int  )0;
       sqlstm.sqindv[1] = (         short *)&ind_action_id;
       sqlstm.sqinds[1] = (         int  )0;
       sqlstm.sqharm[1] = (unsigned long )0;
       sqlstm.sqadto[1] = (unsigned short )0;
       sqlstm.sqtdso[1] = (unsigned short )0;
       sqlstm.sqhstv[2] = (unsigned char  *)&c_cursor_rec;
       sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
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
       if (sqlca.sqlcode < 0) goto getrecforgen_error;
}



DEBUGLOG(("hv_return_value = [%d]\n", hv_return_value));
	if (hv_return_value > 0) {
                for (;;) {
                        myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);

			ind_batch_id = -1;
			ind_payout_group = -1;
                        ind_pregen_ret_code = -1;
                        ind_gen_ret_code = -1;
                        ind_seq = -1;
                        ind_txn_id = -1;
                        ind_psp_id = -1;
                        ind_to_bank_code = -1;
                        ind_file_id = -1;
			ind_merchant_payout_grp = -1;
                        ind_psp_payout_grp = -1;
                        ind_request_currency = -1;
                        ind_request_amount = -1;
                        ind_payout_currency = -1;
                        ind_payout_amount = -1;
                        ind_merchant_fee_ccy = -1;
                        ind_merchant_fee = -1;
                        ind_status = -1;
                        ind_merchant_id = -1;
                        ind_merchant_ref = -1;
                        ind_service_code = -1;
                        ind_txn_country = -1;
                        ind_identity_id= -1;
                        ind_bank_name = -1;
                        ind_bank_code = -1;
                        ind_branch= -1;
                        ind_bank_acct_num = -1;
                        ind_account_name= -1;
                        ind_account_id= -1;
                        ind_remark = -1;
                        ind_province = -1;
                        ind_phone_no = -1;
                        ind_city = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_rec
                        INTO
                                :v_batch_id:ind_batch_id,
				:v_payout_group:ind_payout_group,
                                :v_pregen_ret_code:ind_pregen_ret_code,
                                :v_gen_ret_code:ind_gen_ret_code,
                                :v_seq:ind_seq,
                                :v_txn_id:ind_txn_id,
                                :v_psp_id:ind_psp_id,
                                :v_to_bank_code:ind_to_bank_code,
                                :v_file_id:ind_file_id,
				:v_merchant_payout_grp:ind_merchant_payout_grp,
                                :v_psp_payout_grp:ind_psp_payout_grp,
                                :v_request_currency:ind_request_currency,
                                :v_request_amount:ind_request_amount,
                                :v_payout_currency:ind_payout_currency,
                                :v_payout_amount:ind_payout_amount,
                                :v_merchant_fee_ccy:ind_merchant_fee_ccy,
                                :v_merchant_fee:ind_merchant_fee,
                                :v_status:ind_status,
                                :v_merchant_id:ind_merchant_id,
                                :v_merchant_ref:ind_merchant_ref,
                                :v_service_code:ind_service_code,
                                :v_txn_country:ind_txn_country,
                                :v_identity_id:ind_identity_id,
                                :v_bank_name:ind_bank_name,
                                :v_bank_code:ind_bank_code,
                                :v_branch:ind_branch,
                                :v_bank_acct_num:ind_bank_acct_num,
                                :v_account_name:ind_account_name,
                                :v_account_id:ind_account_id,
                                :v_remark:ind_remark,
                                :v_province:ind_province,
                                :v_phone_no:ind_phone_no,
                                :v_city:ind_city; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 34;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )1080;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_rec;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_batch_id;
                        sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_batch_id;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_payout_group;
                        sqlstm.sqhstl[2] = (unsigned long )5;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_payout_group;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_pregen_ret_code;
                        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_pregen_ret_code;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_gen_ret_code;
                        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_gen_ret_code;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_seq;
                        sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_seq;
                        sqlstm.sqinds[5] = (         int  )0;
                        sqlstm.sqharm[5] = (unsigned long )0;
                        sqlstm.sqadto[5] = (unsigned short )0;
                        sqlstm.sqtdso[5] = (unsigned short )0;
                        sqlstm.sqhstv[6] = (unsigned char  *)&v_txn_id;
                        sqlstm.sqhstl[6] = (unsigned long )19;
                        sqlstm.sqhsts[6] = (         int  )0;
                        sqlstm.sqindv[6] = (         short *)&ind_txn_id;
                        sqlstm.sqinds[6] = (         int  )0;
                        sqlstm.sqharm[6] = (unsigned long )0;
                        sqlstm.sqadto[6] = (unsigned short )0;
                        sqlstm.sqtdso[6] = (unsigned short )0;
                        sqlstm.sqhstv[7] = (unsigned char  *)&v_psp_id;
                        sqlstm.sqhstl[7] = (unsigned long )13;
                        sqlstm.sqhsts[7] = (         int  )0;
                        sqlstm.sqindv[7] = (         short *)&ind_psp_id;
                        sqlstm.sqinds[7] = (         int  )0;
                        sqlstm.sqharm[7] = (unsigned long )0;
                        sqlstm.sqadto[7] = (unsigned short )0;
                        sqlstm.sqtdso[7] = (unsigned short )0;
                        sqlstm.sqhstv[8] = (unsigned char  *)&v_to_bank_code;
                        sqlstm.sqhstl[8] = (unsigned long )28;
                        sqlstm.sqhsts[8] = (         int  )0;
                        sqlstm.sqindv[8] = (         short *)&ind_to_bank_code;
                        sqlstm.sqinds[8] = (         int  )0;
                        sqlstm.sqharm[8] = (unsigned long )0;
                        sqlstm.sqadto[8] = (unsigned short )0;
                        sqlstm.sqtdso[8] = (unsigned short )0;
                        sqlstm.sqhstv[9] = (unsigned char  *)&v_file_id;
                        sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[9] = (         int  )0;
                        sqlstm.sqindv[9] = (         short *)&ind_file_id;
                        sqlstm.sqinds[9] = (         int  )0;
                        sqlstm.sqharm[9] = (unsigned long )0;
                        sqlstm.sqadto[9] = (unsigned short )0;
                        sqlstm.sqtdso[9] = (unsigned short )0;
                        sqlstm.sqhstv[10] = (unsigned char  *)&v_merchant_payout_grp;
                        sqlstm.sqhstl[10] = (unsigned long )5;
                        sqlstm.sqhsts[10] = (         int  )0;
                        sqlstm.sqindv[10] = (         short *)&ind_merchant_payout_grp;
                        sqlstm.sqinds[10] = (         int  )0;
                        sqlstm.sqharm[10] = (unsigned long )0;
                        sqlstm.sqadto[10] = (unsigned short )0;
                        sqlstm.sqtdso[10] = (unsigned short )0;
                        sqlstm.sqhstv[11] = (unsigned char  *)&v_psp_payout_grp;
                        sqlstm.sqhstl[11] = (unsigned long )5;
                        sqlstm.sqhsts[11] = (         int  )0;
                        sqlstm.sqindv[11] = (         short *)&ind_psp_payout_grp;
                        sqlstm.sqinds[11] = (         int  )0;
                        sqlstm.sqharm[11] = (unsigned long )0;
                        sqlstm.sqadto[11] = (unsigned short )0;
                        sqlstm.sqtdso[11] = (unsigned short )0;
                        sqlstm.sqhstv[12] = (unsigned char  *)&v_request_currency;
                        sqlstm.sqhstl[12] = (unsigned long )6;
                        sqlstm.sqhsts[12] = (         int  )0;
                        sqlstm.sqindv[12] = (         short *)&ind_request_currency;
                        sqlstm.sqinds[12] = (         int  )0;
                        sqlstm.sqharm[12] = (unsigned long )0;
                        sqlstm.sqadto[12] = (unsigned short )0;
                        sqlstm.sqtdso[12] = (unsigned short )0;
                        sqlstm.sqhstv[13] = (unsigned char  *)&v_request_amount;
                        sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[13] = (         int  )0;
                        sqlstm.sqindv[13] = (         short *)&ind_request_amount;
                        sqlstm.sqinds[13] = (         int  )0;
                        sqlstm.sqharm[13] = (unsigned long )0;
                        sqlstm.sqadto[13] = (unsigned short )0;
                        sqlstm.sqtdso[13] = (unsigned short )0;
                        sqlstm.sqhstv[14] = (unsigned char  *)&v_payout_currency;
                        sqlstm.sqhstl[14] = (unsigned long )6;
                        sqlstm.sqhsts[14] = (         int  )0;
                        sqlstm.sqindv[14] = (         short *)&ind_payout_currency;
                        sqlstm.sqinds[14] = (         int  )0;
                        sqlstm.sqharm[14] = (unsigned long )0;
                        sqlstm.sqadto[14] = (unsigned short )0;
                        sqlstm.sqtdso[14] = (unsigned short )0;
                        sqlstm.sqhstv[15] = (unsigned char  *)&v_payout_amount;
                        sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[15] = (         int  )0;
                        sqlstm.sqindv[15] = (         short *)&ind_payout_amount;
                        sqlstm.sqinds[15] = (         int  )0;
                        sqlstm.sqharm[15] = (unsigned long )0;
                        sqlstm.sqadto[15] = (unsigned short )0;
                        sqlstm.sqtdso[15] = (unsigned short )0;
                        sqlstm.sqhstv[16] = (unsigned char  *)&v_merchant_fee_ccy;
                        sqlstm.sqhstl[16] = (unsigned long )6;
                        sqlstm.sqhsts[16] = (         int  )0;
                        sqlstm.sqindv[16] = (         short *)&ind_merchant_fee_ccy;
                        sqlstm.sqinds[16] = (         int  )0;
                        sqlstm.sqharm[16] = (unsigned long )0;
                        sqlstm.sqadto[16] = (unsigned short )0;
                        sqlstm.sqtdso[16] = (unsigned short )0;
                        sqlstm.sqhstv[17] = (unsigned char  *)&v_merchant_fee;
                        sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[17] = (         int  )0;
                        sqlstm.sqindv[17] = (         short *)&ind_merchant_fee;
                        sqlstm.sqinds[17] = (         int  )0;
                        sqlstm.sqharm[17] = (unsigned long )0;
                        sqlstm.sqadto[17] = (unsigned short )0;
                        sqlstm.sqtdso[17] = (unsigned short )0;
                        sqlstm.sqhstv[18] = (unsigned char  *)&v_status;
                        sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[18] = (         int  )0;
                        sqlstm.sqindv[18] = (         short *)&ind_status;
                        sqlstm.sqinds[18] = (         int  )0;
                        sqlstm.sqharm[18] = (unsigned long )0;
                        sqlstm.sqadto[18] = (unsigned short )0;
                        sqlstm.sqtdso[18] = (unsigned short )0;
                        sqlstm.sqhstv[19] = (unsigned char  *)&v_merchant_id;
                        sqlstm.sqhstl[19] = (unsigned long )18;
                        sqlstm.sqhsts[19] = (         int  )0;
                        sqlstm.sqindv[19] = (         short *)&ind_merchant_id;
                        sqlstm.sqinds[19] = (         int  )0;
                        sqlstm.sqharm[19] = (unsigned long )0;
                        sqlstm.sqadto[19] = (unsigned short )0;
                        sqlstm.sqtdso[19] = (unsigned short )0;
                        sqlstm.sqhstv[20] = (unsigned char  *)&v_merchant_ref;
                        sqlstm.sqhstl[20] = (unsigned long )53;
                        sqlstm.sqhsts[20] = (         int  )0;
                        sqlstm.sqindv[20] = (         short *)&ind_merchant_ref;
                        sqlstm.sqinds[20] = (         int  )0;
                        sqlstm.sqharm[20] = (unsigned long )0;
                        sqlstm.sqadto[20] = (unsigned short )0;
                        sqlstm.sqtdso[20] = (unsigned short )0;
                        sqlstm.sqhstv[21] = (unsigned char  *)&v_service_code;
                        sqlstm.sqhstl[21] = (unsigned long )6;
                        sqlstm.sqhsts[21] = (         int  )0;
                        sqlstm.sqindv[21] = (         short *)&ind_service_code;
                        sqlstm.sqinds[21] = (         int  )0;
                        sqlstm.sqharm[21] = (unsigned long )0;
                        sqlstm.sqadto[21] = (unsigned short )0;
                        sqlstm.sqtdso[21] = (unsigned short )0;
                        sqlstm.sqhstv[22] = (unsigned char  *)&v_txn_country;
                        sqlstm.sqhstl[22] = (unsigned long )5;
                        sqlstm.sqhsts[22] = (         int  )0;
                        sqlstm.sqindv[22] = (         short *)&ind_txn_country;
                        sqlstm.sqinds[22] = (         int  )0;
                        sqlstm.sqharm[22] = (unsigned long )0;
                        sqlstm.sqadto[22] = (unsigned short )0;
                        sqlstm.sqtdso[22] = (unsigned short )0;
                        sqlstm.sqhstv[23] = (unsigned char  *)&v_identity_id;
                        sqlstm.sqhstl[23] = (unsigned long )28;
                        sqlstm.sqhsts[23] = (         int  )0;
                        sqlstm.sqindv[23] = (         short *)&ind_identity_id;
                        sqlstm.sqinds[23] = (         int  )0;
                        sqlstm.sqharm[23] = (unsigned long )0;
                        sqlstm.sqadto[23] = (unsigned short )0;
                        sqlstm.sqtdso[23] = (unsigned short )0;
                        sqlstm.sqhstv[24] = (unsigned char  *)&v_bank_name;
                        sqlstm.sqhstl[24] = (unsigned long )153;
                        sqlstm.sqhsts[24] = (         int  )0;
                        sqlstm.sqindv[24] = (         short *)&ind_bank_name;
                        sqlstm.sqinds[24] = (         int  )0;
                        sqlstm.sqharm[24] = (unsigned long )0;
                        sqlstm.sqadto[24] = (unsigned short )0;
                        sqlstm.sqtdso[24] = (unsigned short )0;
                        sqlstm.sqhstv[25] = (unsigned char  *)&v_bank_code;
                        sqlstm.sqhstl[25] = (unsigned long )13;
                        sqlstm.sqhsts[25] = (         int  )0;
                        sqlstm.sqindv[25] = (         short *)&ind_bank_code;
                        sqlstm.sqinds[25] = (         int  )0;
                        sqlstm.sqharm[25] = (unsigned long )0;
                        sqlstm.sqadto[25] = (unsigned short )0;
                        sqlstm.sqtdso[25] = (unsigned short )0;
                        sqlstm.sqhstv[26] = (unsigned char  *)&v_branch;
                        sqlstm.sqhstl[26] = (unsigned long )153;
                        sqlstm.sqhsts[26] = (         int  )0;
                        sqlstm.sqindv[26] = (         short *)&ind_branch;
                        sqlstm.sqinds[26] = (         int  )0;
                        sqlstm.sqharm[26] = (unsigned long )0;
                        sqlstm.sqadto[26] = (unsigned short )0;
                        sqlstm.sqtdso[26] = (unsigned short )0;
                        sqlstm.sqhstv[27] = (unsigned char  *)&v_bank_acct_num;
                        sqlstm.sqhstl[27] = (unsigned long )53;
                        sqlstm.sqhsts[27] = (         int  )0;
                        sqlstm.sqindv[27] = (         short *)&ind_bank_acct_num;
                        sqlstm.sqinds[27] = (         int  )0;
                        sqlstm.sqharm[27] = (unsigned long )0;
                        sqlstm.sqadto[27] = (unsigned short )0;
                        sqlstm.sqtdso[27] = (unsigned short )0;
                        sqlstm.sqhstv[28] = (unsigned char  *)&v_account_name;
                        sqlstm.sqhstl[28] = (unsigned long )103;
                        sqlstm.sqhsts[28] = (         int  )0;
                        sqlstm.sqindv[28] = (         short *)&ind_account_name;
                        sqlstm.sqinds[28] = (         int  )0;
                        sqlstm.sqharm[28] = (unsigned long )0;
                        sqlstm.sqadto[28] = (unsigned short )0;
                        sqlstm.sqtdso[28] = (unsigned short )0;
                        sqlstm.sqhstv[29] = (unsigned char  *)&v_account_id;
                        sqlstm.sqhstl[29] = (unsigned long )28;
                        sqlstm.sqhsts[29] = (         int  )0;
                        sqlstm.sqindv[29] = (         short *)&ind_account_id;
                        sqlstm.sqinds[29] = (         int  )0;
                        sqlstm.sqharm[29] = (unsigned long )0;
                        sqlstm.sqadto[29] = (unsigned short )0;
                        sqlstm.sqtdso[29] = (unsigned short )0;
                        sqlstm.sqhstv[30] = (unsigned char  *)&v_remark;
                        sqlstm.sqhstl[30] = (unsigned long )258;
                        sqlstm.sqhsts[30] = (         int  )0;
                        sqlstm.sqindv[30] = (         short *)&ind_remark;
                        sqlstm.sqinds[30] = (         int  )0;
                        sqlstm.sqharm[30] = (unsigned long )0;
                        sqlstm.sqadto[30] = (unsigned short )0;
                        sqlstm.sqtdso[30] = (unsigned short )0;
                        sqlstm.sqhstv[31] = (unsigned char  *)&v_province;
                        sqlstm.sqhstl[31] = (unsigned long )102;
                        sqlstm.sqhsts[31] = (         int  )0;
                        sqlstm.sqindv[31] = (         short *)&ind_province;
                        sqlstm.sqinds[31] = (         int  )0;
                        sqlstm.sqharm[31] = (unsigned long )0;
                        sqlstm.sqadto[31] = (unsigned short )0;
                        sqlstm.sqtdso[31] = (unsigned short )0;
                        sqlstm.sqhstv[32] = (unsigned char  *)&v_phone_no;
                        sqlstm.sqhstl[32] = (unsigned long )32;
                        sqlstm.sqhsts[32] = (         int  )0;
                        sqlstm.sqindv[32] = (         short *)&ind_phone_no;
                        sqlstm.sqinds[32] = (         int  )0;
                        sqlstm.sqharm[32] = (unsigned long )0;
                        sqlstm.sqadto[32] = (unsigned short )0;
                        sqlstm.sqtdso[32] = (unsigned short )0;
                        sqlstm.sqhstv[33] = (unsigned char  *)&v_city;
                        sqlstm.sqhstl[33] = (unsigned long )102;
                        sqlstm.sqhsts[33] = (         int  )0;
                        sqlstm.sqindv[33] = (         short *)&ind_city;
                        sqlstm.sqinds[33] = (         int  )0;
                        sqlstm.sqharm[33] = (unsigned long )0;
                        sqlstm.sqadto[33] = (unsigned short )0;
                        sqlstm.sqtdso[33] = (unsigned short )0;
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
                        if (sqlca.sqlcode == 1403) break;
                        if (sqlca.sqlcode < 0) goto getrecforgen_error;
}



                        if (SQLCODE == SQL_NOT_FOUND) {
                                break;
                        }

//batch_id
                	if(ind_batch_id>=0){
				sprintf(csBatchId, "%ld", v_batch_id);
                        	PutField_CString(myHash,"batch_id",csBatchId);
DEBUGLOG(("batch_id= [%s]\n",csBatchId));
                	}

//payout_group
                        if(ind_payout_group>=0){
                                v_payout_group.arr[v_payout_group.len]='\0';
                                PutField_CString(myHash,"payout_group",(const char*)v_payout_group.arr);
DEBUGLOG(("payout_group= [%s]\n",v_payout_group.arr));
                        }

//pregen_ret_code
                        if(ind_pregen_ret_code>=0){
                                PutField_Int(myHash,"pregen_ret_code",v_pregen_ret_code);
DEBUGLOG(("pregen_ret_code= [%d]\n",v_pregen_ret_code));
                        }

//gen_ret_code
                        if(ind_gen_ret_code>=0){
                                PutField_Int(myHash,"gen_ret_code",v_gen_ret_code);
DEBUGLOG(("gen_ret_code= [%d]\n",v_gen_ret_code));
                        }

//seq
                	if(ind_seq>=0){
                	        PutField_Int(myHash,"seq",v_seq);
DEBUGLOG(("seq= [%d]\n",v_seq));
                	}

//txn_id
                	if(ind_txn_id>=0){
                	        v_txn_id.arr[v_txn_id.len]='\0';
                	        PutField_CString(myHash,"txn_id",(const char*)v_txn_id.arr);
DEBUGLOG(("txn_id= [%s]\n",v_txn_id.arr));
                	}

//psp_id
                	if(ind_psp_id>=0){
                	        v_psp_id.arr[v_psp_id.len]='\0';
                	        PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("psp_id= [%s]\n",v_psp_id.arr));
                	}

//to_bank_code
                	if(ind_to_bank_code>=0){
                	        v_to_bank_code.arr[v_to_bank_code.len]='\0';
                	        PutField_CString(myHash,"to_bank_code",(const char*)v_to_bank_code.arr);
DEBUGLOG(("to_bank_code= [%s]\n",v_to_bank_code.arr));
                	}

//file_id
                	if(ind_file_id>=0){
                	        PutField_Int(myHash,"file_id",v_file_id);
DEBUGLOG(("file_id= [%d]\n",v_file_id));
                	}


//merchant_payout_grp
                        if (ind_merchant_payout_grp >= 0) {
                                v_merchant_payout_grp.arr[v_merchant_payout_grp.len] = '\0';
                                PutField_CString(myHash, "merchant_payout_grp", (const char*)v_merchant_payout_grp.arr);
DEBUGLOG(("merchant_payout_grp = [%s]\n", v_merchant_payout_grp.arr));
                        }

//psp_payout_grp
                        if (ind_psp_payout_grp >= 0) {
                                v_psp_payout_grp.arr[v_psp_payout_grp.len] = '\0';
                                PutField_CString(myHash, "psp_payout_grp", (const char*)v_psp_payout_grp.arr);
DEBUGLOG(("psp_payout_grp = [%s]\n", v_psp_payout_grp.arr));
                        }

//request_currency
                        if (ind_request_currency >= 0) {
                                v_request_currency.arr[v_request_currency.len] = '\0';
                                PutField_CString(myHash, "request_currency", (const char*)v_request_currency.arr);
DEBUGLOG(("request_currency = [%s]\n", v_request_currency.arr));
                        }

//request_amount
                        if (ind_request_amount >= 0) {
                                PutField_Double(myHash, "request_amount", v_request_amount);
DEBUGLOG(("request_amount = [%f]\n", v_request_amount));
                        }

//payout_currency
                        if (ind_payout_currency >= 0) {
                                v_payout_currency.arr[v_payout_currency.len] = '\0';
                                PutField_CString(myHash, "payout_currency", (const char*)v_payout_currency.arr);
DEBUGLOG(("payout_currency = [%s]\n", v_payout_currency.arr));
                        }

//payout_amount
                        if (ind_payout_amount >= 0) {
                                PutField_Double(myHash, "payout_amount", v_payout_amount);
DEBUGLOG(("payout_amount = [%f]\n", v_payout_amount));
                        }

//merchant_fee_ccy
                        if (ind_merchant_fee_ccy >= 0) {
                                v_merchant_fee_ccy.arr[v_merchant_fee_ccy.len] = '\0';
                                PutField_CString(myHash, "merchant_fee_ccy", (const char*)v_merchant_fee_ccy.arr);
DEBUGLOG(("merchant_fee_ccy = [%s]\n", v_merchant_fee_ccy.arr));
                        }

//merchant_fee
                        if (ind_merchant_fee >= 0) {
                                PutField_Double(myHash, "merchant_fee", v_merchant_fee);
DEBUGLOG(("merchant_fee = [%f]\n", v_merchant_fee));
                        }

//status
                        if (ind_status >= 0) {
                                PutField_Int(myHash, "status", v_status);
DEBUGLOG(("status = [%f]\n", v_status));
                        }

//merchant_id
                        if (ind_merchant_id >= 0) {
                                v_merchant_id.arr[v_merchant_id.len] ='\0';
                                PutField_CString(myHash,"merchant_id",(const char*)v_merchant_id.arr);
DEBUGLOG(("merchant_id = [%s]\n",v_merchant_id.arr));
                        }

//merchant_ref
                        if (ind_merchant_ref >= 0) {
                                v_merchant_ref.arr[v_merchant_ref.len] ='\0';
                                PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
DEBUGLOG(("merchant_ref = [%s]\n",v_merchant_ref.arr));
                        }

//service_code
                        if (ind_service_code >= 0) {
                                v_service_code.arr[v_service_code.len] ='\0';
                                PutField_CString(myHash,"service_code",(const char*)v_service_code.arr);
DEBUGLOG(("service_code = [%s]\n",v_service_code.arr));
                        }

//txn country
                        if (ind_txn_country  >=  0) {
                                v_txn_country.arr[v_txn_country.len] = '\0';
                                PutField_CString(myHash,"txn_country",(const char*)v_txn_country.arr);
DEBUGLOG(("txn_country = [%s]\n",v_txn_country.arr));
                        }

//identity_id
                        if (ind_identity_id>=  0) {
                               v_identity_id.arr[v_identity_id.len] = '\0';
                               PutField_CString(myHash,"identity_id",(const char*)v_identity_id.arr);
DEBUGLOG(("identity_id = [%s]\n",v_identity_id.arr));
                        }

//bank_name
                        if (ind_bank_name >= 0) {
                                v_bank_name.arr[v_bank_name.len] = '\0';
                                PutField_CString(myHash,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG(("bank_name = [%s]\n",v_bank_name.arr));
                        }

//bank_code
                        if (ind_bank_code  >=  0) {
                                v_bank_code.arr[v_bank_code.len] = '\0';
                                PutField_CString(myHash,"bank_code",(const char*)v_bank_code.arr);
DEBUGLOG(("bank_code = [%s]\n",v_bank_code.arr));
                        }

//branch
                        if (ind_branch>=  0) {
                                v_branch.arr[v_branch.len] = '\0';
                                PutField_CString(myHash,"branch",(const char*)v_branch.arr);
DEBUGLOG(("branch = [%s]\n",v_branch.arr));
                        }

//bank_acct_num
                        if (ind_bank_acct_num>=  0) {
                                v_bank_acct_num.arr[v_bank_acct_num.len] = '\0';
                                PutField_CString(myHash,"bank_acct_num",(const char*)v_bank_acct_num.arr);
DEBUGLOG(("bank_acct_num = [%s]\n",v_bank_acct_num.arr));
                        }

//account_name
                        if (ind_account_name>=  0) {
                                v_account_name.arr[v_account_name.len] = '\0';
                                PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
DEBUGLOG(("account_name = [%s]\n",v_account_name.arr));
                        }

//account_id
                        if (ind_account_id>=  0) {
                                v_account_id.arr[v_account_id.len] = '\0';
                                PutField_CString(myHash,"account_id",(const char*)v_account_id.arr);
DEBUGLOG(("account_id = [%s]\n",v_account_id.arr));
                        }

//remark
                        if (ind_remark>=  0) {
                                v_remark.arr[v_remark.len] = '\0';
                                PutField_CString(myHash,"remark",(const char*)v_remark.arr);
DEBUGLOG(("remark = [%s]\n",v_remark.arr));
                        }

//province
                        if (ind_province >= 0) {
                                v_province.arr[v_province.len] = '\0';
                                PutField_CString(myHash,"province",(const char*)v_province.arr);
DEBUGLOG(("province = [%s]\n",v_province.arr));
                        }

//phone_no
                        if (ind_phone_no >= 0) {
                                v_phone_no.arr[v_phone_no.len] = '\0';
                                PutField_CString(myHash,"phone_no",(const char*)v_phone_no.arr);
DEBUGLOG(("phone_no = [%s]\n",v_phone_no.arr));
                        }


//city
                        if (ind_city >= 0) {
                                v_city.arr[v_city.len] = '\0';
                                PutField_CString(myHash,"city",(const char*)v_city.arr);
DEBUGLOG(("city = [%s]\n",v_city.arr));
                        }

			iCnt++;

                	RecordSet_Add(myRec,myHash);
		}
	}

	/* EXEC SQL CLOSE :c_cursor_rec; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 34;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1231;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_rec;
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
 if (sqlca.sqlcode < 0) goto getrecforgen_error;
}


        /* EXEC SQL FREE :c_cursor_rec; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 34;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1250;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_rec;
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
        if (sqlca.sqlcode < 0) goto getrecforgen_error;
}



        if (iCnt > 0) {
DEBUGLOG(("GetRecordsForGen Normal Exit\n"));
        	return  PD_OK;
	} else {
DEBUGLOG(("GetRecordsForGen No Records Found!!\n"));
                return  PD_ERR;
	}		

getrecforgen_error:
DEBUGLOG(("getrecforgen_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPayoutApiPregenDT_GetRecordsForGen: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE :c_cursor_rec; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 34;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1269;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_rec;
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
}


        /* EXEC SQL FREE :c_cursor_rec; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 34;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1288;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_rec;
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
}


	return PD_ERR;
}		

