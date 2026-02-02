
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
    "OffsetTxnType.pc"
};


static unsigned int sqlctx = 4962275;


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

 static char *sq0004 = 
"select ott_desc , ott_amt_type , ott_bal_type , ott_allow_modify , ott_allo\
w_bal_negative , ott_nature , ott_disabled from offset_txn_type where ott_par\
ty_type = :b0 and ott_txn_code = :b1            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,283,0,6,126,0,0,9,9,0,1,0,2,3,0,0,1,1,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,1,
0,0,1,1,0,0,1,3,0,0,1,9,0,0,
56,0,0,2,367,0,6,263,0,0,11,11,0,1,0,2,3,0,0,1,1,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
1,0,0,1,3,0,0,1,3,0,0,1,1,0,0,1,3,0,0,1,9,0,0,
115,0,0,3,93,0,6,335,0,0,3,3,0,1,0,2,3,0,0,1,1,0,0,1,9,0,0,
142,0,0,4,200,0,9,425,0,2049,2,2,0,1,0,1,1,0,0,1,9,0,0,
165,0,0,4,0,0,13,427,0,0,7,0,0,1,0,2,9,0,0,2,9,0,0,2,1,0,0,2,3,0,0,2,3,0,0,2,1,
0,0,2,3,0,0,
208,0,0,4,0,0,15,495,0,0,0,0,0,1,0,
223,0,0,4,0,0,15,511,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2016/04/14              Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "OffsetTxnType.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void OffsetTxnType(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const hash_t *hRls)
{
        char  cTmp;
        char  *csTmp;
        int   iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		char            hv_party_type;
                /* varchar         hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

                /* varchar         hv_desc[PD_DESC_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_desc;

                /* varchar         hv_amt_type[PD_AMT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_amt_type;

                char            hv_bal_type;
		char            hv_nature;
                int             hv_disabled;
                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



                short           ind_party_type = -1;
                short           ind_txn_code = -1;
                short           ind_desc = -1;
                short           ind_amt_type = -1;
                short           ind_bal_type = -1;
                short           ind_nature = -1;
                short           ind_disabled = -1;
                short           ind_create_user = -1;

                short           hv_return_value;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

// party_type
	if (GetField_Char(hRls, "party_type", &cTmp)) {
                hv_party_type = cTmp;
                ind_party_type = 0;
        }
DEBUGLOG(("Add:party_type = [%c]\n",hv_party_type));

// txn_code
        if(GetField_CString(hRls,"txn_code",&csTmp)) {
                hv_txn_code.len = strlen(csTmp);
                strncpy((char*)hv_txn_code.arr, csTmp, hv_txn_code.len);
                ind_txn_code = 0;
        }
DEBUGLOG(("Add:txn_code = [%.*s]\n",hv_txn_code.len, hv_txn_code.arr));

// desc
        if(GetField_CString(hRls,"desc",&csTmp)) {
                hv_desc.len = strlen(csTmp);
                strncpy((char*)hv_desc.arr, csTmp, hv_desc.len);
                ind_desc = 0;
        }
DEBUGLOG(("Add:desc = [%.*s]\n",hv_desc.len, hv_desc.arr));

// amt_type
        if(GetField_CString(hRls,"amt_type",&csTmp)) {
                hv_amt_type.len = strlen(csTmp);
                strncpy((char*)hv_amt_type.arr, csTmp, hv_amt_type.len);
                ind_amt_type = 0;
        }
DEBUGLOG(("Add:amt_type = [%.*s]\n",hv_amt_type.len, hv_amt_type.arr));

// bal_type
        if(GetField_Char(hRls, "bal_type", &cTmp)) {
                hv_bal_type = cTmp;
                ind_bal_type = 0;
DEBUGLOG(("Add:bal_type = [%c]\n",hv_bal_type));
        }

// nature
        if(GetField_Char(hRls, "nature", &cTmp)) {
                hv_nature = cTmp;
                ind_nature = 0;
DEBUGLOG(("Add:nature = [%c]\n",hv_nature));
        }

// disabled
        if(GetField_Int(hRls, "disabled", &iTmp)) {
                hv_disabled = iTmp;
                ind_disabled = 0;
        }
DEBUGLOG(("Add:disabled = [%d]\n",hv_disabled));

// create_user
        if(GetField_CString(hRls,"create_user",&csTmp))
        {
                hv_create_user.len = strlen(csTmp);
                strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
                ind_create_user = 0;
        }
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_offset_txn_type_insert(
                                                :hv_party_type:ind_party_type,
                                                :hv_txn_code:ind_txn_code,
                                                :hv_desc:ind_desc,
                                                :hv_amt_type:ind_amt_type,
                                                :hv_bal_type:ind_bal_type,
                                                :hv_nature:ind_nature,
                                                :hv_disabled:ind_disabled,
                                                :hv_create_user:ind_create_user
                                                );
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_offset_txn_type_insert \
( :hv_party_type:ind_party_type , :hv_txn_code:ind_txn_code , :hv_desc:ind_de\
sc , :hv_amt_type:ind_amt_type , :hv_bal_type:ind_bal_type , :hv_nature:ind_n\
ature , :hv_disabled:ind_disabled , :hv_create_user:ind_create_user ) ; END ;";
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_party_type;
        sqlstm.sqhstl[1] = (unsigned long )1;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_party_type;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_code;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_txn_code;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_desc;
        sqlstm.sqhstl[3] = (unsigned long )52;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_desc;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_amt_type;
        sqlstm.sqhstl[4] = (unsigned long )4;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_amt_type;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_bal_type;
        sqlstm.sqhstl[5] = (unsigned long )1;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_bal_type;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_nature;
        sqlstm.sqhstl[6] = (unsigned long )1;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_nature;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_disabled;
        sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_disabled;
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
ERRLOG("OffsetTxnType_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("OffsetTxnType_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OffsetTxnType_Add: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int Update(const hash_t *hRls)
{
        char    cTmp;
        char    *csTmp;
        int     iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		char    hv_party_type;
                /* varchar hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

                /* varchar hv_desc[PD_DESC_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_desc;

                /* varchar hv_amt_type[PD_AMT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_amt_type;

                char    hv_bal_type;
        	int     hv_allow_modify;
                int     hv_allow_bal_negative;        
		char    hv_nature;
                int     hv_disabled;
                /* varchar hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;


                short   ind_party_type = -1;
                short   ind_txn_code = -1;
                short   ind_desc = -1;
                short   ind_amt_type = -1;
                short   ind_bal_type = -1;
		short   ind_allow_modify = -1;
                short   ind_allow_bal_negative= -1;	
                short   ind_nature = -1;
		short   ind_disabled = -1;
                short   ind_update_user = -1;

                short   hv_return_value;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update Offset Txn Type: Begin\n"));

	if (GetField_Char(hRls,"party_type",&cTmp)) {
                hv_party_type = cTmp;
                ind_party_type = 0;
DEBUGLOG(("Update: party_type = [%c]\n", hv_party_type));
        }

        if (GetField_CString(hRls,"txn_code",&csTmp)) {
                hv_txn_code.len = strlen((const char*)csTmp);
                memcpy(hv_txn_code.arr, csTmp, hv_txn_code.len);
                ind_txn_code = 0;
        }
DEBUGLOG(("Update:code = [%.*s]\n",hv_txn_code.len, hv_txn_code.arr));

        if (GetField_CString(hRls,"desc",&csTmp)) {
                hv_desc.len = strlen((const char*)csTmp);
                memcpy(hv_desc.arr, csTmp, hv_desc.len);
                ind_desc = 0;
        }
DEBUGLOG(("Update: desc = [%.*s]\n",hv_desc.len, hv_desc.arr));

        if (GetField_CString(hRls,"amt_type",&csTmp)) {
                hv_amt_type.len = strlen((const char*)csTmp);
                memcpy(hv_amt_type.arr, csTmp, hv_amt_type.len);
                ind_amt_type = 0;
        }
DEBUGLOG(("Update: amt_type = [%.*s]\n",hv_amt_type.len, hv_amt_type.arr));

        if (GetField_Char(hRls,"bal_type",&cTmp)) {
                hv_bal_type = cTmp;
                ind_bal_type = 0;
DEBUGLOG(("Update: bal_type = [%c]\n", hv_bal_type));
        }

        if (GetField_Char(hRls,"nature",&cTmp)) {
                hv_nature = cTmp;
                ind_nature = 0;
DEBUGLOG(("Update: nature = [%c]\n", hv_nature));
        }

        if (GetField_Int(hRls,"allow_modify",&iTmp)) {
                hv_allow_modify = iTmp;
                ind_allow_modify = 0;
DEBUGLOG(("Update: allow_modify = [%d]\n", hv_allow_modify));
        }

	if (GetField_Int(hRls,"allow_bal_negative",&iTmp)) {
                hv_allow_bal_negative = iTmp;
                ind_allow_bal_negative = 0;
DEBUGLOG(("Update: allow_bal_negative = [%d]\n", hv_allow_bal_negative));
        }

        if (GetField_Int(hRls,"disabled",&iTmp)) {
                hv_disabled = iTmp;
                ind_disabled = 0;
        }
DEBUGLOG(("Update: disabled = [%d]\n", hv_disabled));

	/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_offset_txn_type_update(
                                                :hv_party_type:ind_party_type,
                                                :hv_txn_code:ind_txn_code,
                                                :hv_desc:ind_desc,
                                                :hv_amt_type:ind_amt_type,
                                                :hv_bal_type:ind_bal_type,
                                                :hv_allow_modify:ind_allow_modify,
                                                :hv_allow_bal_negative:ind_allow_bal_negative,
                                                :hv_nature:ind_nature,
                                                :hv_disabled:ind_disabled,
                                                :hv_update_user:ind_update_user);
                END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_offset_txn_type_update ( :hv_p\
arty_type:ind_party_type , :hv_txn_code:ind_txn_code , :hv_desc:ind_desc , :h\
v_amt_type:ind_amt_type , :hv_bal_type:ind_bal_type , :hv_allow_modify:ind_al\
low_modify , :hv_allow_bal_negative:ind_allow_bal_negative , :hv_nature:ind_n\
ature , :hv_disabled:ind_disabled , :hv_update_user:ind_update_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_party_type;
 sqlstm.sqhstl[1] = (unsigned long )1;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_party_type;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_code;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_txn_code;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_desc;
 sqlstm.sqhstl[3] = (unsigned long )52;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_desc;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_amt_type;
 sqlstm.sqhstl[4] = (unsigned long )4;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_amt_type;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_bal_type;
 sqlstm.sqhstl[5] = (unsigned long )1;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_bal_type;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_allow_modify;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_allow_modify;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_allow_bal_negative;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_allow_bal_negative;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_nature;
 sqlstm.sqhstl[8] = (unsigned long )1;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_nature;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_disabled;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_update_user;
 sqlstm.sqhstl[10] = (unsigned long )22;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_update_user;
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
 if (sqlca.sqlcode < 0) goto update_error;
}



        if (hv_return_value == SP_OK) {
DEBUGLOG(("Update Normal Exit\n"));
                return  PD_OK;
        }

        if (hv_return_value == SP_ERR) {
ERRLOG("OffsetTxnType_Update: SP_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

        if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OffsetTxnType_Update: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }


update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OffsetTxnType_Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;
}

int Delete (const hash_t *hRls)
{
	char    cTmp;
        char    *csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO delete_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                char hv_party_type;
                /* varchar hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;


                short   hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Delete: Begin\n"));

	if (GetField_Char(hRls,"party_type",&cTmp)) {
                hv_party_type = cTmp;
DEBUGLOG(("Delete:party_type = [%c]\n", hv_party_type));
        }

        if(GetField_CString(hRls,"txn_code",&csTmp)) {
                hv_txn_code.len = strlen((const char*)csTmp);
                memcpy(hv_txn_code.arr, csTmp, hv_txn_code.len);
        }
DEBUGLOG(("Delete:txn_code = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_offset_txn_type_delete(
                                                :hv_party_type,
                                                :hv_txn_code
                                                );

                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_offset_txn_type_delete \
( :hv_party_type , :hv_txn_code ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )115;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_party_type;
        sqlstm.sqhstl[1] = (unsigned long )1;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_code;
        sqlstm.sqhstl[2] = (unsigned long )5;
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
        if (sqlca.sqlcode < 0) goto delete_error;
}



DEBUGLOG(("Delete:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("Delete:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("OffsetTxnType_Delete: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Delete: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

	if (hv_return_value == SP_ERR)  {
ERRLOG("OffsetTxnType_Delete: SP_ERR TxnAbort\n");
DEBUGLOG(("Delete: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

delete_error:
DEBUGLOG(("delete_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OffsetTxnType_Delete: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int	GetOffsetTxnRec(const char cPartyType, 
			const char *csTxnCode ,
			recordset_t *myRec)
{
	int 	iCnt = 0;
	hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getoffsettxntype_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		char		hv_party_type;
		/* varchar		hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;


		/* varchar		v_desc[PD_DESC_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_desc;

		/* varchar         v_amt_type[PD_AMT_TYPE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_amt_type;

                char            v_bal_type;
		int             v_allow_modify;
                int             v_allow_bal_negative;
		char            v_nature;
		int		v_disabled;

		short		ind_desc = -1;
		short		ind_amt_type = -1;
		short		ind_bal_type = -1;
		short           ind_allow_modify = -1;
                short           ind_allow_bal_negative= -1;
		short           ind_nature = -1;
		short		ind_disabled = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


// party_type
	hv_party_type = cPartyType;
DEBUGLOG(("GetOffsetTxnRec party_type = [%.c]\n", hv_party_type));

// txn_code
        hv_txn_code.len = strlen(csTxnCode);
        memcpy(hv_txn_code.arr,csTxnCode,hv_txn_code.len);
DEBUGLOG(("GetOffsetTxnRec txn_code = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));

        /* EXEC SQL DECLARE c_cursor_getoffsettxntype CURSOR FOR
		select ott_desc,
		       ott_amt_type,
	               ott_bal_type,
		       ott_allow_modify,
		       ott_allow_bal_negative,
		       ott_nature,
		       ott_disabled
		  from offset_txn_type
		 where ott_party_type = :hv_party_type
		   and ott_txn_code = :hv_txn_code; */ 


        /* EXEC SQL OPEN c_cursor_getoffsettxntype; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0004;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )142;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_code;
        sqlstm.sqhstl[1] = (unsigned long )5;
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
        if (sqlca.sqlcode < 0) goto getoffsettxntype_error;
}


        do {
		/* EXEC SQL FETCH c_cursor_getoffsettxntype
		INTO	:v_desc:ind_desc,
			:v_amt_type:ind_amt_type,
			:v_bal_type:ind_bal_type,
			:v_allow_modify:ind_allow_modify,
                        :v_allow_bal_negative:ind_allow_bal_negative,
			:v_nature:ind_nature,
			:v_disabled:ind_disabled; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 11;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )165;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_desc;
  sqlstm.sqhstl[0] = (unsigned long )53;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_desc;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_amt_type;
  sqlstm.sqhstl[1] = (unsigned long )5;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_amt_type;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_bal_type;
  sqlstm.sqhstl[2] = (unsigned long )1;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_bal_type;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_allow_modify;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_allow_modify;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_allow_bal_negative;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_allow_bal_negative;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_nature;
  sqlstm.sqhstl[5] = (unsigned long )1;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_nature;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_disabled;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_disabled;
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
  if (sqlca.sqlcode < 0) goto getoffsettxntype_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}	

		iCnt++;

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

/* desc */
                if (ind_desc >= 0) {
                        v_desc.arr[v_desc.len] = '\0';
                        PutField_CString(myHash, "desc", (const char *)v_desc.arr);
DEBUGLOG(("GetOffsetTxnRec desc = [%s]\n",v_desc.arr));

                }

/* amt_type */	
		if (ind_amt_type >= 0) {
			v_amt_type.arr[v_amt_type.len] = '\0';
			PutField_CString(myHash, "amt_type", (const char *)v_amt_type.arr);
DEBUGLOG(("GetOffsetTxnRec amt_type = [%s]\n",v_amt_type.arr));

		}

/* bal_type */
                if (ind_bal_type >= 0) {
                        PutField_Char(myHash, "bal_type", v_bal_type);
DEBUGLOG(("GetOffsetTxnRec bal_type = [%c]\n",v_bal_type));
                }

/* allow_modify */
                if (ind_allow_modify >= 0) {
                        PutField_Int(myHash, "allow_modify", v_allow_modify);
DEBUGLOG(("GetOffsetTxnRec allow_modify = [%d]\n", v_allow_modify));
                }

/* allow_bal_negative */
                if (ind_allow_bal_negative >= 0) {
                        PutField_Int(myHash, "allow_bal_negative", v_allow_bal_negative);
DEBUGLOG(("GetOffsetTxnRec allow_bal_negative = [%d]\n", v_allow_bal_negative));
                }

/* nature */
                if (ind_nature >= 0) {
                        PutField_Char(myHash, "nature", v_nature);
DEBUGLOG(("GetOffsetTxnRec nature = [%c]\n", v_nature));
                }

/* disabled */
		if (ind_disabled >= 0) {
			PutField_Int(myHash, "disabled", v_disabled);
DEBUGLOG(("GetOffsetTxnRec disabled = [%d]\n", v_disabled));

		}

		RecordSet_Add(myRec, myHash);
	}
	while (PD_TRUE);
	/* EXEC SQL CLOSE c_cursor_getoffsettxntype; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )208;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getoffsettxntype_error;
}



        if (iCnt > 0 ) {
DEBUGLOG(("GetOffsetTxnRec Normal Exit, Found\n"));
                return  PD_FOUND;
        }
        else {
DEBUGLOG(("GetOffsetTxnRec Normal Exit, Not Found\n"));
                return 	PD_NOT_FOUND;
        }


getoffsettxntype_error:
DEBUGLOG(("getoffsettxntype_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getoffsettxntype; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )223;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;

}


