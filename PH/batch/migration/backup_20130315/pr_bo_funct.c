
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
    "pr_bo_funct.pc"
};


static unsigned int sqlctx = 1337195;


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
   unsigned char  *sqhstv[10];
   unsigned long  sqhstl[10];
            int   sqhsts[10];
            short *sqindv[10];
            int   sqinds[10];
   unsigned long  sqharm[10];
   unsigned long  *sqharc[10];
   unsigned short  sqadto[10];
   unsigned short  sqtdso[10];
} sqlstm = {12,10};

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

 static char *sq0005 = 
"select m_total_float ,m_current_bal ,m_total_reserved_amount ,m_total_hold \
,m_total_float_settlement ,m_current_bal_settlement ,m_total_hold_settlement \
,m_total_float_after_payout ,m_fundin_payout ,m_reserved_payout  from merchan\
t_balance where (((m_merchant_id=:b0 and m_currency_id=:b1) and m_country_id=\
:b2) and m_service_code=:b3)           ";

 static char *sq0006 = 
"select m_current_bal ,m_total_float ,m_total_hold ,m_current_bal_settlement\
 ,m_total_float_settlement ,m_total_hold_settlement ,m_total_float_after_payo\
ut ,m_total_reserved_amount ,m_fundin_payout ,m_reserved_payout  from merchan\
t_balance where (((m_merchant_id=:b0 and m_currency_id=:b1) and m_country_id=\
:b2) and m_service_code=:b3) for update ";

 static char *sq0016 = 
"select pc_precal_type ,pc_precal_value ,pc_precal_additional_value ,pc_prec\
al_min_value ,pc_precal_max_value ,pc_value_type ,pc_scale  from psp_costs wh\
ere (((pc_effect_date=(select max(pc_effect_date)  from psp_costs where (((pc\
_effect_date<sysdate and pc_psp_id=:b0) and pc_txn_type=:b1) and pc_disabled=\
:b2)) and pc_psp_id=:b0) and pc_txn_type=:b1) and pc_disabled=:b2)           ";

 static char *sq0018 = 
"select m_current_bal_settlement ,m_total_float_settlement ,m_total_hold_set\
tlement ,m_total_reserved_amount ,m_current_bal  from merchant_balance where \
(((m_merchant_id=:b0 and m_currency_id=:b1) and m_country_id=:b2) and m_servi\
ce_code=:b3) for update ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,77,0,4,41,0,0,1,0,0,1,0,2,9,0,0,
24,0,0,2,89,0,4,71,0,0,1,0,0,1,0,2,9,0,0,
43,0,0,3,110,0,4,99,0,0,1,0,0,1,0,2,9,0,0,
62,0,0,4,94,0,4,130,0,0,1,0,0,1,0,2,9,0,0,
81,0,0,5,345,0,9,863,0,0,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
112,0,0,5,0,0,13,865,0,0,10,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,
4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
167,0,0,5,0,0,15,949,0,0,0,0,0,1,0,
182,0,0,5,0,0,15,958,0,0,0,0,0,1,0,
197,0,0,6,346,0,9,1051,0,0,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
228,0,0,6,0,0,13,1053,0,0,10,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,
4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
283,0,0,6,0,0,15,1117,0,0,0,0,0,1,0,
298,0,0,6,0,0,15,1149,0,0,0,0,0,1,0,
313,0,0,7,287,0,6,1230,0,0,8,8,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
4,0,0,1,4,0,0,1,9,0,0,
360,0,0,8,269,0,6,1340,0,0,8,8,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
4,0,0,1,9,0,0,2,4,0,0,
407,0,0,9,247,0,6,1451,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
4,0,0,1,9,0,0,
450,0,0,10,228,0,6,1558,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
493,0,0,11,197,0,6,1665,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,
1,9,0,0,
532,0,0,12,201,0,6,1680,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,
1,9,0,0,
571,0,0,13,196,0,6,1782,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,
1,9,0,0,
610,0,0,14,200,0,6,1797,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,
1,9,0,0,
649,0,0,15,157,0,4,1880,0,0,6,3,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,
688,0,0,16,383,0,9,2107,0,0,6,6,0,1,0,1,9,0,0,1,1,0,0,1,3,0,0,1,9,0,0,1,1,0,0,
1,3,0,0,
727,0,0,16,0,0,13,2109,0,0,7,0,0,1,0,2,1,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,
1,0,0,2,3,0,0,
770,0,0,16,0,0,15,2175,0,0,0,0,0,1,0,
785,0,0,16,0,0,15,2186,0,0,0,0,0,1,0,
800,0,0,17,276,0,6,2542,0,0,9,9,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,1,0,0,1,4,0,0,
1,9,0,0,1,9,0,0,1,4,0,0,1,9,0,0,
851,0,0,18,253,0,9,2827,0,0,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
882,0,0,18,0,0,13,2829,0,0,5,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
917,0,0,18,0,0,15,2861,0,0,0,0,0,1,0,
932,0,0,18,0,0,15,2870,0,0,0,0,0,1,0,
947,0,0,19,227,0,6,2940,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/07/03              LokMan Chow

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlca.h>
#include <sqlcpr.h>
#include "common.h"
#include "internal.h"
#include "utilitys.h"
#include "dbutility.h"
#include "../batchcommon.h"
#include "pr_bo_funct.h"

char	cDebug;
#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


///////////////////////////////////////////////
//////////////////Txn Seq//////////////////////
char* prbo_GetNextTxnSeq()
{
        /* EXEC SQL WHENEVER SQLERROR GOTO get_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_txn_seq_no[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } hv_txn_seq_no;

                short   ind_txn_seq_no;
        /* EXEC SQL END DECLARE SECTION; */ 


//DEBUGLOG(("GetNextTxnSeq()\n"));
        /* EXEC SQL SELECT TO_CHAR(txn_seq.NEXTVAL, 'FM0999999999999999')
                   INTO :hv_txn_seq_no:ind_txn_seq_no
                 FROM dual; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select TO_CHAR(txn_seq.nextval ,'FM0999999999999999'\
) into :b0:b1  from dual ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )5;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_txn_seq_no;
        sqlstm.sqhstl[0] = (unsigned long )19;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_txn_seq_no;
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
        if (sqlca.sqlcode < 0) goto get_error;
}



        if (ind_txn_seq_no >= 0)  {
                hv_txn_seq_no.arr[hv_txn_seq_no.len] = '\0';
                return strdup((const char *) hv_txn_seq_no.arr);
        }
        else
                return strdup("");

get_error:
DEBUGLOG(("get_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return strdup("");
}

char* prbo_GetNextBatchTxnSeq()
{

        /* EXEC SQL WHENEVER SQLERROR GOTO get_batchid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_txn_seq_no[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } hv_txn_seq_no;

                short   ind_txn_seq_no;
        /* EXEC SQL END DECLARE SECTION; */ 


//DEBUGLOG(("GetNextBatchTxnSeq()\n"));
        /* EXEC SQL SELECT 'B' || TO_CHAR(txn_batch_seq.NEXTVAL, 'FM099999999999999')
                   INTO :hv_txn_seq_no:ind_txn_seq_no
                 FROM dual; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select ('B'||TO_CHAR(txn_batch_seq.nextval ,'FM09999\
9999999999')) into :b0:b1  from dual ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )24;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_txn_seq_no;
        sqlstm.sqhstl[0] = (unsigned long )19;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_txn_seq_no;
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
        if (sqlca.sqlcode < 0) goto get_batchid_error;
}



        if (ind_txn_seq_no >= 0)  {
                hv_txn_seq_no.arr[hv_txn_seq_no.len] = '\0';
                return strdup((const char *) hv_txn_seq_no.arr);
        }
        else
                return strdup("");

get_batchid_error:
DEBUGLOG(("get_batchid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return strdup("");
}

char* prbo_GetNextMgtTxnSeq()
{
        /* EXEC SQL WHENEVER SQLERROR GOTO get_mgttxnseq_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_txn_seq_no[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } hv_txn_seq_no;

                short   ind_txn_seq_no;
        /* EXEC SQL END DECLARE SECTION; */ 


        /* EXEC SQL SELECT 'G' || TO_CHAR(mgt_txn_seq.NEXTVAL, 'FM0999999999') || TO_CHAR(sysdate,'SSSSS')
                   INTO :hv_txn_seq_no:ind_txn_seq_no
                 FROM dual; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select (('G'||TO_CHAR(mgt_txn_seq.nextval ,'FM099999\
9999'))||TO_CHAR(sysdate,'SSSSS')) into :b0:b1  from dual ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )43;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_txn_seq_no;
        sqlstm.sqhstl[0] = (unsigned long )19;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_txn_seq_no;
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
        if (sqlca.sqlcode < 0) goto get_mgttxnseq_error;
}



        if (ind_txn_seq_no >= 0)  {
                hv_txn_seq_no.arr[hv_txn_seq_no.len] = '\0';
                return strdup((const char *) hv_txn_seq_no.arr);
        }
        else
                return strdup("");

get_mgttxnseq_error:
DEBUGLOG(("get_mgttxnseq_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return strdup("");
}


char* prbo_GetNextPayoutTxnSeq()
{

        /* EXEC SQL WHENEVER SQLERROR GOTO get_payoutid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_txn_seq_no[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } hv_txn_seq_no;

                short   ind_txn_seq_no;
        /* EXEC SQL END DECLARE SECTION; */ 


//DEBUGLOG(("GetNextPayoutTxnSeq()\n"));
        /* EXEC SQL SELECT 'P' || TO_CHAR(txn_payout_gen_seq.NEXTVAL, 'FM099999999999999')
                   INTO :hv_txn_seq_no:ind_txn_seq_no
                 FROM dual; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select ('P'||TO_CHAR(txn_payout_gen_seq.nextval ,'FM\
099999999999999')) into :b0:b1  from dual ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )62;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_txn_seq_no;
        sqlstm.sqhstl[0] = (unsigned long )19;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_txn_seq_no;
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
        if (sqlca.sqlcode < 0) goto get_payoutid_error;
}



        if (ind_txn_seq_no >= 0)  {
                hv_txn_seq_no.arr[hv_txn_seq_no.len] = '\0';
                return strdup((const char *) hv_txn_seq_no.arr);
        }
        else
                return strdup("");

get_payoutid_error:
DEBUGLOG(("get_payoutid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return strdup("");
}






/////////////////////////////////////////////////
//////////////////Deposit////////////////////////







////////////////////////////////////////////////
//////////////////Payout////////////////////////
int prbo_UpdatePayoutAmount(hash_t* hContext)
{
        char    *csOrgTxnCountry;
        char    *csOrgTxnCcy;
        char    *csOrgMerchantId;
        char    *csOrgServiceCode;
        char    *csOrgDstCcy;
        char    *csOrgPspId;
        char    cRespMode;
        char    cParty;
        //double        dOrgTxnAmt=0.0;
        double  dOrgNetAmt=0.0;
        double  dOrgDstTxnAmt=0.0;
        double  dPrecalFee=0.0;
        double  dTmp;
        int     iDayOfWeek=0;
        hash_t* hVal;

        int iRet = PD_OK;

/*org txn country */
        if (GetField_CString(hContext,"country",&csOrgTxnCountry)) {
DEBUGLOG(("UpdatePayoutAmount() country = [%s]\n",csOrgTxnCountry));
        }
        else {
DEBUGLOG(("UpdatePayoutAmount() country is missing!!!\n"));
        }

/*org txn ccy */
        if (GetField_CString(hContext,"ccy",&csOrgTxnCcy)) {
DEBUGLOG(("UpdatePayoutAmount() ccy = [%s]\n",csOrgTxnCcy));
        }
        else {
DEBUGLOG(("UpdatePayoutAmount() ccy is missing!!!\n"));
        }
/*org service code */
        if (GetField_CString(hContext,"service",&csOrgServiceCode)) {
DEBUGLOG(("UpdatePayoutAmount() service = [%s]\n",csOrgServiceCode));
        }
        else {
DEBUGLOG(("UpdatePayoutAmount() service is missing!!!\n"));
        }

/*org merchant id */
        if (GetField_CString(hContext,"merchant_id",&csOrgMerchantId)) {
DEBUGLOG(("UpdatePayoutAmount() merchant_id = [%s]\n",csOrgMerchantId));
        }
        else {
DEBUGLOG(("UpdatePayoutAmount() merchant_id is missing!!!\n"));
        }


/*org net amount */
        if (GetField_Double(hContext,"net_amt",&dOrgNetAmt)) {
DEBUGLOG(("UpdatePayoutAmount() net_amt = [%lf]\n",dOrgNetAmt));
        }
        else {
                if (GetField_Double(hContext,"org_net_amt",&dOrgNetAmt)) {
DEBUGLOG(("UpdatePayoutAmount() org_net_amt = [%lf]\n",dOrgNetAmt));
                }
                else {
DEBUGLOG(("UpdatePayoutAmount() org_net_amt is missing!!!\n"));
                }
        }

/*response_mode*/
        if (GetField_Char(hContext,"response_mode",&cRespMode)) {
DEBUGLOG(("UpdatePayoutAmount() response_mode = [%c]\n",cRespMode));
        }
        else {
DEBUGLOG(("UpdatePayoutAmount() response_mode is missing!!!\n"));
        }

/*party_type*/
        if(GetField_Char(hContext,"party_type",&cParty)){
DEBUGLOG(("UpdatePayoutAmount() party_type = [%c]\n",cParty));
        }
        else{
                cParty = PD_TYPE_GLOBAL;
        }

/*org psp id */
        if (GetField_CString(hContext,"psp_id",&csOrgPspId)) {
DEBUGLOG(("UpdatePayoutAmount() psp_id = [%s]\n",csOrgPspId));
        }
        else {
                if(cParty==PD_TYPE_MERCHANT){
                        csOrgPspId = strdup("NA");
                }
                else{
DEBUGLOG(("UpdatePayoutAmount() psp_id is missing!!!\n"));
                }
        }

/*org psp ccy */
        if (GetField_CString(hContext,"to_ccy",&csOrgDstCcy)) {
DEBUGLOG(("UpdatePayoutAmount() to_ccy = [%s]\n",csOrgDstCcy));
        }
        else {
DEBUGLOG(("UpdatePayoutAmount() psp_txn_ccy is missing!!!\n"));
        }

/*org psp txn amount */
        if (GetField_Double(hContext,"dst_net_amt",&dOrgDstTxnAmt)) {
DEBUGLOG(("UpdatePayoutAmount() dst_net_amt = [%lf]\n",dOrgDstTxnAmt));
        }
        else {
DEBUGLOG(("UpdatePayoutAmount() dst_net_amt is missing!!!\n"));
        }

/*org psp precal fee*/
        if (GetField_Double(hContext,"precal_fee",&dPrecalFee)) {
DEBUGLOG(("UpdatePayoutAmount() psp precal_fee = [%lf]\n",dPrecalFee));
        }

/*DayOfWeek*/
        if (GetField_Int(hContext,"day_of_week",&iDayOfWeek)) {
DEBUGLOG(("UpdatePayoutAmount() day_of_week = [%d]\n",iDayOfWeek));
        }

        if(cRespMode==PD_ACCEPT){
                iRet = prbo_PayoutSuccess(hContext,
                                        csOrgTxnCountry,
                                        csOrgServiceCode,
                                        csOrgTxnCcy,
                                        csOrgMerchantId,
                                        dOrgNetAmt,
                                        csOrgDstCcy,
                                        csOrgPspId,
                                        dOrgDstTxnAmt+dPrecalFee,
                                        cParty,
                                        iDayOfWeek);
        }
        else if(cRespMode==PD_REVERSED){
                iRet = prbo_PayoutVoided(hContext,
                                        csOrgTxnCountry,
                                        csOrgServiceCode,
                                        csOrgTxnCcy,
                                        csOrgMerchantId,
                                        dOrgNetAmt,
                                        csOrgDstCcy,
                                        csOrgPspId,
                                        dOrgDstTxnAmt+dPrecalFee,
                                        cParty,
                                        iDayOfWeek);
        }

	if((iRet==PD_OK) && (cParty!=PD_TYPE_PSP)){
                hVal = (hash_t*) malloc (sizeof(hash_t));
                hash_init(hVal,0);

                if(prbo_GetCurrentValues(csOrgMerchantId,csOrgTxnCcy,csOrgTxnCountry,csOrgServiceCode,hVal)!=PD_ERR){
                        if(GetField_Double(hVal,"current_bal",&dTmp)){
                                PutField_Double(hContext,"current_bal",dTmp);
DEBUGLOG(("pr_bo_funct: current_bal= [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"total_float",&dTmp)){
                                PutField_Double(hContext,"total_float",dTmp);
DEBUGLOG(("pr_bo_funct: total_float= [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"total_reserved_amount",&dTmp)){
                                PutField_Double(hContext,"total_reserved_amount",dTmp);
DEBUGLOG(("pr_bo_funct: total_reserved_amount= [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"total_hold",&dTmp)){
                                PutField_Double(hContext,"total_hold",dTmp);
DEBUGLOG(("pr_bo_funct: total_hold= [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"total_float_after_payout",&dTmp)){
                                PutField_Double(hContext,"total_float_after_payout",dTmp);
DEBUGLOG(("pr_bo_funct: total_float_after_payout= [%f]\n",dTmp));
                        }

                        if(GetField_Double(hVal,"current_bal_settlement",&dTmp)){
                                PutField_Double(hContext,"current_bal_settlement",dTmp);
DEBUGLOG(("pr_bo_funct: current_bal_settlement= [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"total_float_settlement",&dTmp)){
                                PutField_Double(hContext,"total_float_settlement",dTmp);
DEBUGLOG(("pr_bo_funct: total_float_settlement= [%f]\n",dTmp));
                        }
			if(GetField_Double(hVal,"total_hold_settlement",&dTmp)){
                                PutField_Double(hContext,"total_hold_settlement",dTmp);
DEBUGLOG(("pr_bo_funct: total_hold_settlement= [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"fundin_payout",&dTmp)){
                                PutField_Double(hContext,"fundin_payout",dTmp);
DEBUGLOG(("pr_bo_funct: fundin_payout= [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"reserved_payout",&dTmp)){
                                PutField_Double(hContext,"reserved_payout",dTmp);
DEBUGLOG(("pr_bo_funct: reserved_payout= [%f]\n",dTmp));
                        }
                }

                FREE_ME(hVal);

                if(cParty==PD_TYPE_MERCHANT)
                        FREE_ME(csOrgPspId);
        }


	if((iRet==PD_OK) && (cParty!=PD_TYPE_MERCHANT)){

                hVal = (hash_t*) malloc (sizeof(hash_t));
                hash_init(hVal,0);

                if(prbo_GetBalance(csOrgPspId,csOrgTxnCountry,csOrgDstCcy,hVal)!=PD_ERR){
                        if(GetField_Double(hVal,"balance",&dTmp)){
                                PutField_Double(hContext,"psp_balance",dTmp);
DEBUGLOG(("pr_bo_funct:psp_balance = [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"total_float",&dTmp)){
                                PutField_Double(hContext,"psp_total_float",dTmp);
DEBUGLOG(("pr_bo_funct:psp_total_float = [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"total_hold",&dTmp)){
                                PutField_Double(hContext,"psp_total_hold",dTmp);
DEBUGLOG(("pr_bo_funct:psp_total_hold = [%f]\n",dTmp));
                        }
                }

                FREE_ME(hVal);
        }

DEBUGLOG(("pr_bo_funct:UpdatePayoutAmount() iRet = [%d]\n",iRet));


        return iRet;

}

int prbo_PayoutSuccess(hash_t* hContext,
                        const char* csCountry,
                        const char* csServiceCode,
                        const char* csMerchantCCY,
                        const char* csMerchantID,
                        double dNetAmount,
                        const char* csPspCCY,
                        const char* csPspID,
                        double dPspAmount,
                        char   cParty,
                        const int iDayOfWeek)
{
        int iRet = PD_OK;

	//double  dTmp = 0.0;
        //double  dRemainDailyCap = 0.0;
        //double  dDailyCap = 0.0;
        char    *csEffectDate;
        csEffectDate = (char*) malloc (PD_DATETIME_LEN +1 );

        hash_t* hTxn;
        hTxn = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTxn,0);

DEBUGLOG(("pr_bo_funct:PayoutSuccess()\n"));
DEBUGLOG(("pr_bo_funct:PayoutSuccess() merchant = [%lf], psp = [%lf]\n",dNetAmount,dPspAmount));

/* lock opening balance */
        if (cParty!=PD_TYPE_PSP) {
                if (prbo_GetOpenBalanceForUpdate(hContext,
                                csMerchantID,
                                csMerchantCCY,
                                csCountry,
                                csServiceCode) != PD_OK) {
                        iRet = INT_ERR;
DEBUGLOG(("pr_bo_funct:PayoutSuccess() GetOpenBalanceForUpdate Failed\n"));
                        return iRet;
                }
        }

	if (cParty==PD_TYPE_MERCHANT || cParty==PD_TYPE_GLOBAL) {
                if (prbo_UpdateSettBal(csMerchantID,
                                csCountry,
                                csMerchantCCY,
                                csServiceCode,
                                dNetAmount,
				0,
				PD_IND_DEBIT,
                                PD_UPDATE_USER) != PD_OK) {
                        iRet = INT_ERR;
DEBUGLOG(("pr_bo_funct:DBMerchantBalance::UpdateSettBal()  Failed\n"));
                        return iRet;
                }
        }

	if (cParty==PD_TYPE_PSP || cParty==PD_TYPE_GLOBAL) {
DEBUGLOG(("pr_bo_funct:PayoutSuccess DebitPSP AvalBalance\n"));
                if (prbo_DebitBalance(csPspID,
                                csCountry,
                                csPspCCY,
                                PD_PSP_BAL,
                                dPspAmount,
                                PD_UPDATE_USER) != PD_OK) {
                        iRet = INT_ERR;
DEBUGLOG(("pr_bo_funct:DBPspBalance::DebitBalance() Failed\n"));
                }
        }

        FREE_ME(csEffectDate);
        FREE_ME(hTxn);

DEBUGLOG(("PayoutSuccess() iRet = [%d]\n",iRet));
        return iRet;
}


int prbo_PayoutVoided(hash_t* hContext,
                const char* csCountry,
                const char* csServiceCode,
                const char* csMerchantCCY,
                const char* csMerchantID,
                double dNetAmount,
                const char* csPspCCY,
                const char* csPspID,
                double dPspAmount,
                char   cParty,
                const int iDayOfWeek)
{
        int iRet = PD_OK;

	int iSameDate = PD_FALSE;
        //double  dRemainDailyCap = 0.0;
        //double  dDailyCap = 0.0;
        //char    *csPostingDate;
        char    *csEffectDate;
        csEffectDate = (char*) malloc (PD_DATETIME_LEN +1 );

        hash_t* hTxn;
        hTxn = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTxn,0);

DEBUGLOG(("pr_bo_funct:PayoutVoided()\n"));
DEBUGLOG(("pr_bo_funct:PayoutVoided() merchant = [%lf], psp = [%lf]\n",dNetAmount,dPspAmount));

        if(GetField_Int(hContext,"same_date_cancel",&iSameDate)){
DEBUGLOG(("pr_bo_funct:PayoutVoided() same_date_cancel [%d]\n",iSameDate));
        }


/* lock opening balance */
        if (cParty!=PD_TYPE_PSP) {
                if (prbo_GetOpenBalanceForUpdate(hContext,
                                csMerchantID,
                                csMerchantCCY,
                                csCountry,
                                csServiceCode) != PD_OK) {
                        iRet = INT_ERR;
DEBUGLOG(("pr_bo_funct:PayoutVoided() GetOpenBalanceForUpdate Failed\n"));
                        return iRet;
                }
        }

        if (cParty==PD_TYPE_MERCHANT || cParty==PD_TYPE_GLOBAL) {
                if (prbo_UpdateSettBal(csMerchantID,
                                csCountry,
                                csMerchantCCY,
                                csServiceCode,
                                dNetAmount,
				0,
				PD_IND_CREDIT,
                                PD_UPDATE_USER) != PD_OK) {
                        iRet = INT_ERR;
DEBUGLOG(("pr_bo_funct:DBMerchantBalance::UpdateSettBal() Failed\n"));
                }
	}

        if (cParty==PD_TYPE_PSP || cParty==PD_TYPE_GLOBAL) {
DEBUGLOG(("pr_bo_funct:PayoutVoided CreditPSP AvalBalance\n"));
                if (prbo_CreditBalance(csPspID,
                                csCountry,
                                csPspCCY,
                                PD_PSP_BAL,
                                dPspAmount,
                                PD_UPDATE_USER) != PD_OK) {
                        iRet = INT_ERR;
DEBUGLOG(("pr_bo_funct:DBPspBalance::CreditBalance() Failed\n"));
                }
        }

        FREE_ME(csEffectDate);
        FREE_ME(hTxn);


DEBUGLOG(("PayoutVoided() iRet = [%d]\n",iRet));
        return iRet;
}




////////////////////////////////////////////////
////////////////////Settlement//////////////////


int prbo_UpdateSettlementAmount(hash_t *hContext)
{
        int     iRet = PD_OK;
        char    *csTxnCode;
	char    *csSubTxnCode;
        char    *csOrgTxnSeq;
        char    *csOrgTxnCountry;
        char    *csOrgTxnCcy;
        char    *csOrgMerchantId;
        char    *csOrgServiceCode;
        double  dOrgNetAmt=0.0;
        double  dFee=0.0;
        double  dTmp;
        hash_t* hVal;


DEBUGLOG(("UpdateSettlementAmount()\n"));

//txn code
        if (GetField_CString(hContext,"txn_code",&csTxnCode)) {
DEBUGLOG(("UpdateSettlementAmount() txn_code = [%s]\n",csTxnCode));
        }
        else {
DEBUGLOG(("UpdateSettlementAmount() txn_code is missing!!!\n"));
        }
//org txn seq
        if (GetField_CString(hContext,"txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("UpdateSettlementAmount() txn_seq = [%s]\n",csOrgTxnSeq));
        }
        else {
DEBUGLOG(("UpdateSettlementAmount() txn_seq is missing!!!\n"));
        }

//org txn country
        if (GetField_CString(hContext,"txn_country",&csOrgTxnCountry)) {
DEBUGLOG(("UpdateSettlementAmount() txn_country = [%s]\n",csOrgTxnCountry));
        }
        else {
DEBUGLOG(("UpdateSettlementAmount() txn_country is missing!!!\n"));
        }
///org txn ccy
        if (GetField_CString(hContext,"request_ccy",&csOrgTxnCcy)) {
DEBUGLOG(("UpdateSettlementAmount() txn_ccy = [%s]\n",csOrgTxnCcy));
        }
        else {
                if (GetField_CString(hContext,"txn_ccy",&csOrgTxnCcy)) {
DEBUGLOG(("UpdateSettlementAmount() txn_ccy = [%s]\n",csOrgTxnCcy));
                }
                else{
DEBUGLOG(("UpdateSettlementAmount() txn_ccy is missing!!!\n"));
                }
        }
///org service Code
        if (GetField_CString(hContext,"service_code",&csOrgServiceCode)) {
DEBUGLOG(("UpdateSettlementAmount() service_code = [%s]\n",csOrgServiceCode));
        }
        else {
DEBUGLOG(("UpdateSettlementAmount() service_code is missing!!!\n"));
        }

///org merchant id
        if (GetField_CString(hContext,"merchant_id",&csOrgMerchantId)) {
DEBUGLOG(("UpdateSettlementAmount() merchant_id = [%s]\n",csOrgMerchantId));
        }
        else {
DEBUGLOG(("UpdateSettlementAmount() merchant_id is missing!!!\n"));
        }
///org net amount //
        if (GetField_Double(hContext,"net_amt",&dOrgNetAmt)) {
DEBUGLOG(("UpdateSettlementAmount() net_amt = [%lf]\n",dOrgNetAmt));
        }
        else {
DEBUGLOG(("UpdateSettlementAmount() net_amt is missing!!!\n"));
        }
///fee//
        if (GetField_Double(hContext,"src_txn_fee",&dFee)) {
DEBUGLOG(("UpdateSettlementAmount() fee = [%lf]\n",dFee));
        }

// sub_txn_code 
	if (GetField_CString(hContext,"sub_txn_code",&csSubTxnCode)) {
DEBUGLOG(("UpdateSettlementAmount() sub_txn_code = [%s]\n",csSubTxnCode));
        }
        else {
DEBUGLOG(("UpdateSettlementAmount() sub_txn_code is missing!!!\n"));
        }




DEBUGLOG(("UpdateSettlementAmount() Update Avi Settlement Balance\n"));

        if(!strcmp(csTxnCode,PD_SETTLEMENT_REQUEST)){
                iRet = PD_OK;
        }

        else if(!strcmp(csTxnCode,PD_SETTLEMENT_CANCEL)){
                iRet = PD_OK;
        }
        else if(!strcmp(csTxnCode,PD_SETTLEMENT_DELIVERY)){
		iRet = PD_OK;
	}
        else if(!strcmp(csTxnCode,PD_SETTLEMENT_APPROVAL)){

/* lock opening balance */
                if (prbo_GetOpenBalanceForUpdate(hContext,
                                csOrgMerchantId,
                                csOrgTxnCcy,
                                csOrgTxnCountry,
                                csOrgServiceCode) != PD_OK) {
                        iRet = INT_ERR;
DEBUGLOG(("UpdateSettlementAmount() GetOpenBalanceForUpdate Failed\n"));
                }
                else {
                        /* merchant_open_bal */
                        if (GetField_Double(hContext, "merchant_open_bal", &dTmp)) {
DEBUGLOG(("UpdateSettlementAmount() merchant_open_bal = [%lf]\n",dTmp));
                                PutField_Double(hContext, "open_bal", dTmp);
                        }

                        /* merchant_open_bal_settlement */     
                        if (GetField_Double(hContext, "merchant_open_bal_settlement", &dTmp)) {
DEBUGLOG(("UpdateSettlementAmount() merchant_open_bal_settlement = [%lf]\n",dTmp));
                                PutField_Double(hContext, "open_bal_settlement", dTmp);
                        }
                }

DEBUGLOG(("UpdateSettlementAmount() Call DBMerchantBalance:UpdateSettBal[%c]\n",PD_IND_DEBIT));
                iRet = prbo_UpdateSettBal(csOrgMerchantId,
                                                csOrgTxnCountry,
                                                csOrgTxnCcy,
                                                csOrgServiceCode,
                                                dOrgNetAmt,
                                                dFee,
                                                PD_IND_DEBIT,
                                                PD_UPDATE_USER);
        }
        else if (!strcmp(csTxnCode, PD_VOID_TXN_CODE) && !strcmp(csSubTxnCode, PD_SETTLEMENT_VOID))  {
/* lock opening balance */
                if (prbo_GetOpenBalanceForUpdate(hContext,
                                csOrgMerchantId,
                                csOrgTxnCcy,
                                csOrgTxnCountry,
                                csOrgServiceCode) != PD_OK) {
                        iRet = INT_ERR;
DEBUGLOG(("UpdateSettlementAmount() GetOpenBalanceForUpdate Failed\n"));
                }

DEBUGLOG(("UpdateSettlementAmount() Call DBMerchantBalance:UpdateSettBal[%c]\n",PD_IND_CREDIT));
                iRet = prbo_UpdateSettBal(csOrgMerchantId,
                                                csOrgTxnCountry,
                                                csOrgTxnCcy,
                                                csOrgServiceCode,
                                                dOrgNetAmt,
                                                dFee,
                                                PD_IND_CREDIT,
                                                PD_UPDATE_USER);
        }
        else {
DEBUGLOG(("None Settlement txn\n"));
                return iRet;
        }

	hVal = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hVal,0);

DEBUGLOG(("UpdateSettlementAmount() Call GetCurrentValues\n"));
	if(prbo_GetCurrentValues(csOrgMerchantId,csOrgTxnCcy,csOrgTxnCountry,csOrgServiceCode,hVal)!=PD_ERR){
		if(GetField_Double(hVal,"current_bal",&dTmp)){
			PutField_Double(hContext,"current_bal",dTmp);
DEBUGLOG(("UpdateSettlementAmount()  current_bal= [%f]\n",dTmp));
		}
		if(GetField_Double(hVal,"current_bal_settlement",&dTmp)){
			PutField_Double(hContext,"current_bal_settlement",dTmp);
DEBUGLOG(("UpdateSettlementAmount()  current_bal_settlement = [%f]\n",dTmp));
		}
		if(GetField_Double(hVal,"total_float",&dTmp)){
			PutField_Double(hContext,"total_float",dTmp);
DEBUGLOG(("UpdateSettlementAmount()  total_float= [%f]\n",dTmp));
		}
		if(GetField_Double(hVal,"total_float_after_payout",&dTmp)){
			PutField_Double(hContext,"total_float_after_payout",dTmp);
DEBUGLOG(("UpdateSettlementAmount() total_float_after_payout= [%f]\n",dTmp));
		}
		if(GetField_Double(hVal,"total_float_settlement",&dTmp)){
			PutField_Double(hContext,"total_float_settlement",dTmp);
DEBUGLOG(("UpdateSettlementAmount() total_float_settlement= [%f]\n",dTmp));
		}
		if(GetField_Double(hVal,"total_reserved_amount",&dTmp)){
			PutField_Double(hContext,"total_reserved_amount",dTmp);
DEBUGLOG(("UpdateSettlementAmount()  total_reserved_amount= [%f]\n",dTmp));
		}
		if(GetField_Double(hVal,"total_hold",&dTmp)){
			PutField_Double(hContext,"total_hold",dTmp);
DEBUGLOG(("UpdateSettlementAmount()  total_hold= [%f]\n",dTmp));
		}
		if(GetField_Double(hVal,"total_hold_settlement",&dTmp)){
			PutField_Double(hContext,"total_hold_settlement",dTmp);
DEBUGLOG(("UpdateSettlementAmount()  total_hold_settlement= [%f]\n",dTmp));
		}

		if(GetField_Double(hVal,"fundin_payout",&dTmp)){
			PutField_Double(hContext,"fundin_payout",dTmp);
DEBUGLOG(("UpdateSettlementAmount() fundin_payout= [%f]\n",dTmp));
		}
		if(GetField_Double(hVal,"reserved_payout",&dTmp)){
			PutField_Double(hContext,"reserved_payout",dTmp);
DEBUGLOG(("UpdateSettlementAmount() reserved_payout= [%f]\n",dTmp));
		}

	}

	FREE_ME(hVal);

DEBUGLOG(("iRet=[%d]\n",iRet));
        return iRet;
}




//////////////////////////////////////////////////////////////
////////////////////////Merchant Balance//////////////////////

int prbo_GetCurrentValues(const char* csMerchantID,
                        const char* csCurrencyId,
                        const char* csCountryId,
                        const char* csServiceCode,
                        hash_t *hVal)
{
        int iRet = PD_OK;

        /* EXEC SQL WHENEVER SQLERROR GOTO getcurrval_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;


                double          v_total_float;
                double          v_current_bal;
                double          v_total_reserved_amount;
                double          v_total_hold;

                double          v_total_float_settlement;
                double          v_current_bal_settlement;
                double          v_total_hold_settlement;

                double          v_fundin_payout;
                double          v_reserved_payout;
                double          v_total_float_after_payout;

                short           ind_total_float = -1;
                short           ind_current_bal= -1;
                short           ind_total_reserved_amount= -1;
                short           ind_total_hold= -1;

                short           ind_total_float_settlement = -1;
                short           ind_current_bal_settlement= -1;
                short           ind_total_hold_settlement= -1;

                short           ind_total_float_after_payout = -1;
                short           ind_fundin_payout = -1;
                short           ind_reserved_payout = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_merchant_id.len = strlen(csMerchantID);
        memcpy(hv_merchant_id.arr,csMerchantID,hv_merchant_id.len);
DEBUGLOG(("GetCurrentValues merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

        hv_ccy_id.len = strlen(csCurrencyId);
        memcpy(hv_ccy_id.arr,csCurrencyId,hv_ccy_id.len);
DEBUGLOG(("GetCurrentValues ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

        hv_country_id.len = strlen(csCountryId);
        memcpy(hv_country_id.arr,csCountryId,hv_country_id.len);
DEBUGLOG(("GetCurrentValues country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

        hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("GetCurrentValues service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

        /* EXEC SQL DECLARE c_cursor_getcurrval CURSOR FOR
                select  m_total_float,
                        m_current_bal,
                        m_total_reserved_amount,
                        m_total_hold,
                        m_total_float_settlement,
                        m_current_bal_settlement,
                        m_total_hold_settlement,
                        m_total_float_after_payout,
                        m_fundin_payout,
                        m_reserved_payout
                  from  merchant_balance
                 where  m_merchant_id = :hv_merchant_id
                   and  m_currency_id = :hv_ccy_id
                   and  m_country_id = :hv_country_id
                   and  m_service_code = :hv_service_code; */ 



        /* EXEC SQL OPEN c_cursor_getcurrval; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0005;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )81;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[0] = (unsigned long )17;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_ccy_id;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
        sqlstm.sqhstl[2] = (unsigned long )4;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
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
        if (sqlca.sqlcode < 0) goto getcurrval_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getcurrval
                INTO
                        :v_total_float:ind_total_float,
                        :v_current_bal:ind_current_bal,
                        :v_total_reserved_amount:ind_total_reserved_amount,
                        :v_total_hold:ind_total_hold,
                        :v_total_float_settlement:ind_total_float_settlement,
                        :v_current_bal_settlement:ind_current_bal_settlement,
                        :v_total_hold_settlement:ind_total_hold_settlement,
                        :v_total_float_after_payout:ind_total_float_after_payout,
                        :v_fundin_payout:ind_fundin_payout,
                        :v_reserved_payout:ind_reserved_payout; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )112;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_total_float;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_total_float;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_current_bal;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_current_bal;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_total_reserved_amount;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_total_reserved_amount;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_total_hold;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_total_hold;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_total_float_settlement;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_total_float_settlement;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_current_bal_settlement;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_current_bal_settlement;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_total_hold_settlement;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_total_hold_settlement;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_total_float_after_payout;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_total_float_after_payout;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_fundin_payout;
                sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_fundin_payout;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_reserved_payout;
                sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_reserved_payout;
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
                if (sqlca.sqlcode < 0) goto getcurrval_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

//total_float
                if(ind_total_float<0)
                        v_total_float = 0;
                PutField_Double(hVal,"total_float",v_total_float);
DEBUGLOG(("GetCurrentValues float = [%f]\n",v_total_float));

//current_bal
                if(ind_current_bal<0)
                        v_current_bal = 0;
                PutField_Double(hVal,"current_bal",v_current_bal);
DEBUGLOG(("GetCurrentValues current_bal = [%f]\n",v_current_bal));


//total_reserved_amount
                if(ind_total_reserved_amount<0)
                        v_total_reserved_amount= 0;
                PutField_Double(hVal,"total_reserved_amount",v_total_reserved_amount);
DEBUGLOG(("GetCurrentValues total_reserved_amount = [%f]\n",v_total_reserved_amount));

//total_hold
                if(ind_total_hold<0)
                        v_total_hold= 0;
                PutField_Double(hVal,"total_hold",v_total_hold);
DEBUGLOG(("GetCurrentValues total_hold = [%f]\n",v_total_hold));

//total_float_settlement
                if(ind_total_float_settlement<0)
                        v_total_float_settlement = 0.0;
                PutField_Double(hVal,"total_float_settlement",v_total_float_settlement);
DEBUGLOG(("GetCurrentValues float_settlement = [%f]\n",v_total_float_settlement));

//current_bal_settlement
                if(ind_current_bal_settlement<0)
                        v_current_bal_settlement = 0.0;
                PutField_Double(hVal,"current_bal_settlement",v_current_bal_settlement);
DEBUGLOG(("GetCurrentValues current_bal_settlement = [%f]\n",v_current_bal_settlement));

//total_hold_settlement
                if(ind_total_hold_settlement<0)
                        v_total_hold_settlement= 0;
                PutField_Double(hVal,"total_hold_settlement",v_total_hold_settlement);
DEBUGLOG(("GetCurrentValues total_hold_settlement = [%f]\n",v_total_hold_settlement));

//total_float_after_payout
                if(ind_total_float_after_payout<0)
                        v_total_float_after_payout = 0.0;
                PutField_Double(hVal,"total_float_after_payout",v_total_float_after_payout);
DEBUGLOG(("GetCurrentValues float_after_payout = [%f]\n",v_total_float_after_payout));

//fundin payout
                if(ind_fundin_payout<0)
                        v_fundin_payout= 0;
                PutField_Double(hVal,"fundin_payout",v_fundin_payout);
DEBUGLOG(("GetCurrentValues fundin_payout = [%f]\n",v_fundin_payout));


//reserved payout
                if(ind_reserved_payout<0)
                        v_reserved_payout= 0;
                PutField_Double(hVal,"reserved_payout",v_reserved_payout);
DEBUGLOG(("GetCurrentValues reserved_payout = [%f]\n",v_reserved_payout));


        }

        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getcurrval; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )167;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getcurrval_error;
}



DEBUGLOG(("GetCurrentValues Normal Exit\n"));
        return iRet;

getcurrval_error:
DEBUGLOG(("getcurrval_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getcurrval; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )182;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int prbo_GetOpenBalanceForUpdate(hash_t* hContext,
                const char* csMerchantID,
                const char* csCurrencyId,
                const char* csCountryId,
                const char* csServiceCode)
{
        int iRet = PD_OK;
        double dBal = 0.0;
        double dFloat = 0.0;
        double dHold = 0.0;
        double dBalSettlement = 0.0;
        double dFloatSettlement = 0.0;
        double dHoldSettlement = 0.0;
        double dFloatAfterPayout = 0.0;
        double dReservedAmount = 0.0;
        double dFundInPayout = 0.0;
        double dReservedPayout = 0.0;

        /* EXEC SQL WHENEVER SQLERROR GOTO getopenbalforupdate_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;


                double          v_current_bal;
                double          v_total_float;
                double          v_total_hold;

                double          v_current_bal_settlement;
                double          v_total_float_settlement;
                double          v_total_hold_settlement;

                double          v_total_float_after_payout;
                double          v_total_reserved_amount;
                double          v_fundin_payout;
                double          v_reserved_payout;

                short           ind_current_bal= -1;
                short           ind_total_float= -1;
                short           ind_total_hold= -1;

                short           ind_current_bal_settlement= -1;
                short           ind_total_float_settlement= -1;
                short           ind_total_hold_settlement = -1;

                short           ind_total_float_after_payout = -1;
                short           ind_total_reserved_amount = -1;
                short           ind_fundin_payout = -1;
                short           ind_reserved_payout = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_merchant_id.len = strlen(csMerchantID);
        memcpy(hv_merchant_id.arr,csMerchantID,hv_merchant_id.len);
DEBUGLOG(("GetOpenBalanceForUpdate merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

        hv_ccy_id.len = strlen(csCurrencyId);
        memcpy(hv_ccy_id.arr,csCurrencyId,hv_ccy_id.len);
DEBUGLOG(("GetOpenBalanceForUpdate ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

        hv_country_id.len = strlen(csCountryId);
        memcpy(hv_country_id.arr,csCountryId,hv_country_id.len);
DEBUGLOG(("GetOpenBalanceForUpdate country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

        hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("GetOpenBalanceForUpdate service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

        /* EXEC SQL DECLARE c_cursor_getopenbalforupdate CURSOR FOR
                select  m_current_bal,
                        m_total_float,
                        m_total_hold,
                        m_current_bal_settlement,
                        m_total_float_settlement,
                        m_total_hold_settlement,
                        m_total_float_after_payout,
                        m_total_reserved_amount,
                        m_fundin_payout,
                        m_reserved_payout
                  from merchant_balance
                 where m_merchant_id = :hv_merchant_id
                   and m_currency_id = :hv_ccy_id
                   and m_country_id = :hv_country_id
                   and m_service_code = :hv_service_code
                 for update; */ 


        /* EXEC SQL OPEN c_cursor_getopenbalforupdate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0006;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )197;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[0] = (unsigned long )17;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_ccy_id;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
        sqlstm.sqhstl[2] = (unsigned long )4;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
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
        if (sqlca.sqlcode < 0) goto getopenbalforupdate_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getopenbalforupdate
                INTO
                        :v_current_bal:ind_current_bal,
                        :v_total_float:ind_total_float,
                        :v_total_hold:ind_total_hold,
                        :v_current_bal_settlement:ind_current_bal_settlement,
                        :v_total_float_settlement:ind_total_float_settlement,
                        :v_total_hold_settlement:ind_total_hold_settlement,
                        :v_total_float_after_payout:ind_total_float_after_payout,
                        :v_total_reserved_amount:ind_total_reserved_amount,
                        :v_fundin_payout:ind_fundin_payout,
                        :v_reserved_payout:ind_reserved_payout; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )228;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_current_bal;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_current_bal;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_total_float;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_total_float;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_total_hold;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_total_hold;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_current_bal_settlement;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_current_bal_settlement;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_total_float_settlement;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_total_float_settlement;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_total_hold_settlement;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_total_hold_settlement;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_total_float_after_payout;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_total_float_after_payout;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_total_reserved_amount;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_total_reserved_amount;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_fundin_payout;
                sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_fundin_payout;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_reserved_payout;
                sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_reserved_payout;
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
                if (sqlca.sqlcode < 0) goto getopenbalforupdate_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                if(ind_current_bal<0) {
                        v_current_bal = 0.0;
                }
                if(ind_total_float<0) {
                        v_total_float= 0.0;
                }
                if(ind_total_hold<0) {
                        v_total_hold= 0.0;
                }
                if(ind_current_bal_settlement<0) {
                        v_current_bal_settlement = 0.0;
                }
                if(ind_total_float_settlement<0) {
                        v_total_float_settlement= 0.0;
                }
                if(ind_total_hold_settlement<0) {
                        v_total_hold_settlement= 0.0;
                }

                if(ind_total_float_after_payout<0) {
                        v_total_float_after_payout= 0.0;
                }
                if(ind_total_reserved_amount <0) {
                        v_total_reserved_amount= 0.0;
                }
                if(ind_fundin_payout <0) {
                        v_fundin_payout = 0.0;
                }
                if(ind_reserved_payout <0) {
                        v_reserved_payout = 0.0;
                }

                dBal = v_current_bal;
                dFloat = v_total_float;
                dHold = v_total_hold;

                dBalSettlement = v_current_bal_settlement;
                dFloatSettlement = v_total_float_settlement;
                dHoldSettlement = v_total_hold_settlement;

                dFloatAfterPayout = v_total_float_after_payout;
                dReservedAmount = v_total_reserved_amount;
                dFundInPayout = v_fundin_payout;
                dReservedPayout = v_reserved_payout;
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getopenbalforupdate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )283;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getopenbalforupdate_error;
}



DEBUGLOG(("GetOpenBalanceForUpdate open_bal = [%f]\n",dBal));
                PutField_Double(hContext,"merchant_open_bal",dBal);
DEBUGLOG(("GetOpenBalanceForUpdate total_float = [%f]\n",dFloat));
                PutField_Double(hContext,"total_float",dFloat);
DEBUGLOG(("GetOpenBalanceForUpdate total_hold = [%f]\n",dHold));
                PutField_Double(hContext,"total_hold",dHold);

DEBUGLOG(("GetOpenBalanceForUpdate open_bal_settlement = [%f]\n",dBalSettlement));
                PutField_Double(hContext,"merchant_open_bal_settlement",dBalSettlement);
DEBUGLOG(("GetOpenBalanceForUpdate total_float_settlement = [%f]\n",dFloatSettlement));
                PutField_Double(hContext,"total_float_settlement",dFloatSettlement);
DEBUGLOG(("GetOpenBalanceForUpdate total_hold_settlement = [%f]\n",dHoldSettlement));
                PutField_Double(hContext,"total_hold_settlement",dHoldSettlement);

DEBUGLOG(("GetOpenBalanceForUpdate total_float_after_payout = [%f]\n",dFloatAfterPayout));
                PutField_Double(hContext,"total_float_after_payout",dFloatAfterPayout);
DEBUGLOG(("GetOpenBalanceForUpdate total_reserved_amount = [%f]\n",dReservedAmount));
                PutField_Double(hContext,"reserved_amount",dReservedAmount);
DEBUGLOG(("GetOpenBalanceForUpdate fundin_payout = [%f]\n",dFundInPayout));
                PutField_Double(hContext,"fundin_payout",dFundInPayout);
DEBUGLOG(("GetOpenBalanceForUpdate reserved_payout = [%f]\n",dReservedPayout));
                PutField_Double(hContext,"reserved_payout",dReservedPayout);

DEBUGLOG(("GetOpenBalanceForUpdate Normal Exit\n"));
        return iRet;

getopenbalforupdate_error:
DEBUGLOG(("getopenbalforupdate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getopenbalforupdate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )298;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        TxnAbort();
        return PD_ERR;


}



int prbo_UpdateFloat(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
		double  dNetAmt,
		double	dReservedAmt,
                const char* csUser)

{

        /* EXEC SQL WHENEVER SQLERROR GOTO updatefloat_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		double		hv_net_amt;
		double		hv_reserved_amt;
                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



                short           ind_merchant_id = -1;
                short           ind_country_id = -1;
                short           ind_ccy_id = -1;
                short           ind_service_code = -1;
		short		ind_net_amt = -1;
		short		ind_reserved_amt = -1;
                short           ind_create_user = -1;

                short           hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateFloat: Begin\n"));

        hv_merchant_id.len = strlen(csMerchantId);
        strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
        ind_merchant_id = 0;
DEBUGLOG(("UpdateFloat:merchant id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

        hv_country_id.len = strlen(csCountryId);
        strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
        ind_country_id = 0;
DEBUGLOG(("UpdateFloat:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

        hv_ccy_id.len = strlen(csCcy);
        strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
        ind_ccy_id = 0;
DEBUGLOG(("UpdateFloat:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

        hv_service_code.len = strlen(csServiceCode);
        strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
        ind_service_code = 0;
DEBUGLOG(("UpdateFloat:ccy_id = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

	hv_net_amt = dNetAmt;
	ind_net_amt = 0;
DEBUGLOG(("UpdatFloat:net_amt = [%f]\n",hv_net_amt));

        hv_reserved_amt= dReservedAmt;
        ind_reserved_amt= 0;
DEBUGLOG(("UpdatFloat:resreved_amt = [%f]\n",hv_reserved_amt));


        hv_create_user.len = strlen(csUser);
        strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
        ind_create_user = 0;
DEBUGLOG(("UpdateFloat:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


	
        /* EXEC SQL EXECUTE
            BEGIN

                :hv_return_value := sp_par_merchant_bal_insert_fl(
                                :hv_merchant_id:ind_merchant_id,
                                :hv_country_id:ind_country_id,
                                :hv_ccy_id:ind_ccy_id,
                                :hv_service_code:ind_service_code,
				:hv_net_amt:ind_net_amt,
				:hv_reserved_amt:ind_reserved_amt,
                                :hv_create_user:ind_create_user);

            END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_par_merchant_bal_insert\
_fl ( :hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_c\
cy_id:ind_ccy_id , :hv_service_code:ind_service_code , :hv_net_amt:ind_net_am\
t , :hv_reserved_amt:ind_reserved_amt , :hv_create_user:ind_create_user ) ; E\
ND ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )313;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[1] = (unsigned long )17;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
        sqlstm.sqhstl[2] = (unsigned long )4;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_country_id;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[4] = (unsigned long )5;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_service_code;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_net_amt;
        sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_net_amt;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_reserved_amt;
        sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_reserved_amt;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_create_user;
        sqlstm.sqhstl[7] = (unsigned long )22;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_create_user;
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
        if (sqlca.sqlcode < 0) goto updatefloat_error;
}




DEBUGLOG(("UpdateFloat:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("UpdateFloat:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("pr_bo_funct::UpdateFloat: SP_OTHER_ERR \n");
DEBUGLOG(("UpdateFloat: SP_OTHER_ERR \n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("pr_bo_funct::UpdateFloat: SP_ERR \n");
DEBUGLOG(("UpdateFloat: SP_ERR \n"));
                return PD_ERR;
        }

updatefloat_error:
DEBUGLOG(("updatefloat_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int prbo_UpdateAvalBal(hash_t* hContext,
                const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
                const char* csUser)

{

        /* EXEC SQL WHENEVER SQLERROR GOTO updateavalbal_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                double          hv_amt;
                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


                double          v_open_bal;

                short           ind_merchant_id = -1;
                short           ind_country_id = -1;
                short           ind_ccy_id = -1;
                short           ind_service_code = -1;
                short           ind_amt = -1;
                short           ind_create_user = -1;

                short           ind_open_bal = -1;
                short           hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateAvalBal: Begin\n"));

        hv_merchant_id.len = strlen(csMerchantId);
        strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
        ind_merchant_id = 0;
DEBUGLOG(("UpdateAvalBal:merchant id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

        hv_country_id.len = strlen(csCountryId);
        strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
        ind_country_id = 0;
DEBUGLOG(("UpdateAvalBal:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

        hv_ccy_id.len = strlen(csCcy);
        strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
        ind_ccy_id = 0;
DEBUGLOG(("UpdateAvalBal:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

        hv_service_code.len = strlen(csServiceCode);
        strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
        ind_service_code = 0;
DEBUGLOG(("UpdateAvalBal:service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

        hv_amt= dAmt;
        ind_amt= 0;
DEBUGLOG(("UpdateAvalBal:amt = [%f]\n",hv_amt));


        hv_create_user.len = strlen(csUser);
        strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
        ind_create_user = 0;
DEBUGLOG(("UpdateAvalBal:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


        /* EXEC SQL EXECUTE
            BEGIN

                :hv_return_value := sp_merch_balance_update_aval(
                                :hv_merchant_id:ind_merchant_id,
                                :hv_country_id:ind_country_id,
                                :hv_ccy_id:ind_ccy_id,
                                :hv_service_code:ind_service_code,
                                :hv_amt:ind_amt,
                                :hv_create_user:ind_create_user,
                                :v_open_bal:ind_open_bal);

            END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_merch_balance_update_av\
al ( :hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_cc\
y_id:ind_ccy_id , :hv_service_code:ind_service_code , :hv_amt:ind_amt , :hv_c\
reate_user:ind_create_user , :v_open_bal:ind_open_bal ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )360;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[1] = (unsigned long )17;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
        sqlstm.sqhstl[2] = (unsigned long )4;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_country_id;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[4] = (unsigned long )5;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_service_code;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_amt;
        sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_amt;
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
        sqlstm.sqhstv[7] = (unsigned char  *)&v_open_bal;
        sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_open_bal;
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
        if (sqlca.sqlcode < 0) goto updateavalbal_error;
}



DEBUGLOG(("UpdateAvalBal:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
                if (ind_open_bal < 0) {
                        v_open_bal = 0.0;
                }
DEBUGLOG(("UpdateAvalBal: open bal = [%f]\n",v_open_bal));
                PutField_Double(hContext,"merchant_open_bal",v_open_bal);
DEBUGLOG(("UpdateAvalBal:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("pr_bo_funct::UpdateAvalBal: SP_OTHER_ERR \n");
DEBUGLOG(("UpdateAvalBal: SP_OTHER_ERR \n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("pr_bo_funct::UpdateAvalBal: SP_ERR \n");
DEBUGLOG(("UpdateAvalBal: SP_ERR \n"));
                return PD_ERR;
        }

updateavalbal_error:
DEBUGLOG(("updateavalbal_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}



int prbo_UpdateReserved(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dFloat,
                const char* csUser)

{

        /* EXEC SQL WHENEVER SQLERROR GOTO updatereserved_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                double          hv_float;
                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



                short           ind_merchant_id = -1;
                short           ind_country_id = -1;
                short           ind_ccy_id = -1;
                short           ind_service_code = -1;
                short           ind_float = -1;
                short           ind_create_user = -1;

                short           hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateReserved: Begin\n"));

        hv_merchant_id.len = strlen(csMerchantId);
        strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
        ind_merchant_id = 0;
DEBUGLOG(("UpdateReserved:merchant id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

        hv_country_id.len = strlen(csCountryId);
        strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
        ind_country_id = 0;
DEBUGLOG(("UpdateReserved:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

        hv_ccy_id.len = strlen(csCcy);
        strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
        ind_ccy_id = 0;
DEBUGLOG(("UpdateReserved:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

        hv_service_code.len = strlen(csServiceCode);
        strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
        ind_service_code = 0;
DEBUGLOG(("UpdateReserved:ccy_id = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

        hv_float = dFloat;
        ind_float = 0;
DEBUGLOG(("UpdatReserved:float = [%f]\n",hv_float));

        hv_create_user.len = strlen(csUser);
        strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
        ind_create_user = 0;
DEBUGLOG(("UpdateReserved:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));

	/* EXEC SQL EXECUTE
		BEGIN

			:hv_return_value := sp_merchant_balance_insert_rs(
                                :hv_merchant_id:ind_merchant_id,
                                :hv_country_id:ind_country_id,
                                :hv_ccy_id:ind_ccy_id,
                                :hv_service_code:ind_service_code,
                                :hv_float:ind_float,
                                :hv_create_user:ind_create_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merchant_balance_insert_rs ( :\
hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy_id:i\
nd_ccy_id , :hv_service_code:ind_service_code , :hv_float:ind_float , :hv_cre\
ate_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )407;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_country_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_service_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_float;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_float;
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
 if (sqlca.sqlcode < 0) goto updatereserved_error;
}



DEBUGLOG(("UpdateReserved:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("UpdateReserved:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("pr_bo_funct::UpdateReserved: SP_OTHER_ERR \n");
DEBUGLOG(("UpdateReserved: SP_OTHER_ERR \n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("pr_bo_funct::UpdateReserved: SP_ERR \n");
DEBUGLOG(("UpdateReserved: SP_ERR \n"));
                return PD_ERR;
        }

updatereserved_error:
DEBUGLOG(("updateReserved_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int prbo_UpdateSettBal(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
                double  dFee,
                char    cType,
                const char* csUser)

{

        /* EXEC SQL WHENEVER SQLERROR GOTO upd_sett_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                double          hv_amt;
                /* varchar         hv_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_user;


                short           ind_merchant_id = -1;
                short           ind_country_id = -1;
                short           ind_ccy_id = -1;
                short           ind_service_code = -1;
                short           ind_amt = -1;
                short           ind_user = -1;

                short           hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateSettBal: Begin\n"));

        hv_merchant_id.len = strlen(csMerchantId);
        strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
        ind_merchant_id = 0;

        hv_country_id.len = strlen(csCountryId);
        strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
        ind_country_id = 0;

        hv_ccy_id.len = strlen(csCcy);
        strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
        ind_ccy_id = 0;

        hv_service_code.len = strlen(csServiceCode);
        strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
        ind_service_code = 0;

        if(cType==PD_IND_DEBIT){
                hv_amt = (-1)*(dAmt + dFee);
                ind_amt= 0;
        }
        else{
                hv_amt = dAmt - dFee;
                ind_amt= 0;
        }
DEBUGLOG(("UpdateSettBal:amt = [%f]\n",dAmt));
DEBUGLOG(("UpdateSettBal:fee = [%f]\n",dFee));
DEBUGLOG(("UpdateSettBal:net_amt = [%f]\n",hv_amt));
DEBUGLOG(("UpdateSettBal:type => [%c]\n",cType));

        hv_user.len = strlen(csUser);
        strncpy((char *)hv_user.arr, csUser, hv_user.len);
        ind_user = 0;

                /* EXEC SQL EXECUTE
                   BEGIN

                        :hv_return_value := sp_merchant_bal_upd_sett_bal(
                                :hv_merchant_id:ind_merchant_id,
                                :hv_country_id:ind_country_id,
                                :hv_ccy_id:ind_ccy_id,
                                :hv_service_code:ind_service_code,
                                :hv_amt:ind_amt,
                                :hv_user:ind_user);

                   END;
                END-EXEC; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "begin :hv_return_value := sp_merchant_bal_up\
d_sett_bal ( :hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id \
, :hv_ccy_id:ind_ccy_id , :hv_service_code:ind_service_code , :hv_amt:ind_amt\
 , :hv_user:ind_user ) ; END ;";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )450;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
                sqlstm.sqhstl[1] = (unsigned long )17;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
                sqlstm.sqhstl[2] = (unsigned long )4;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_country_id;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
                sqlstm.sqhstl[3] = (unsigned long )5;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
                sqlstm.sqhstl[4] = (unsigned long )5;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_service_code;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&hv_amt;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_amt;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&hv_user;
                sqlstm.sqhstl[6] = (unsigned long )22;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_user;
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
                if (sqlca.sqlcode < 0) goto upd_sett_error;
}



        if (hv_return_value == SP_OK)        {
DEBUGLOG(("UpdateSettBal:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("pr_bo_funct::UpdateSettBal: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateSettBal: SP_OTHER_ERR TxnAbort\n"));
                TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("pr_bo_funct::UpdateSettBal: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateSettBal: SP_ERR TxnAbort\n"));
                TxnAbort();
                return PD_ERR;
        }
upd_sett_error:
DEBUGLOG(("upd_sett_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        TxnAbort();
        return PD_ERR;
}





//////////////////////////////////////////////////////////////////////////////
///////////////////////////////////Psp Balance////////////////////////////////

int prbo_CreditBalance(const char* csPsp,
                const char* csCountryId,
                const char* csCcy,
                char  cType,
                double dAmt,
                char* csUpdateUser)

{

        /* EXEC SQL WHENEVER SQLERROR GOTO creditbal_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                double          hv_balance;
                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



                short           ind_psp_id = -1;
                short           ind_country_id = -1;
                short           ind_ccy_id = -1;
                short           ind_balance = -1;
                short           ind_create_user = -1;

                short           hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("CreditBalance: Begin\n"));

        hv_psp_id.len = strlen(csPsp);
        strncpy((char*)hv_psp_id.arr, csPsp, hv_psp_id.len);
        ind_psp_id = 0;
DEBUGLOG(("CreditBalance:psp_id = [%.*s]\n",hv_psp_id.len,hv_psp_id.arr));

        hv_country_id.len = strlen(csCountryId);
        strncpy((char*)hv_country_id.arr, csCountryId, hv_country_id.len);
        ind_country_id = 0;
DEBUGLOG(("CreditBalance:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

        hv_ccy_id.len = strlen(csCcy);
        strncpy((char*)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
        ind_ccy_id = 0;
DEBUGLOG(("CreditBalance:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

        hv_balance= dAmt;
        ind_balance= 0;
DEBUGLOG(("CreditBalance:balance = [%f]\n",hv_balance));


        hv_create_user.len = strlen(csUpdateUser);
        strncpy((char*)hv_create_user.arr, csUpdateUser, hv_create_user.len);
        ind_create_user = 0;
DEBUGLOG(("CreditBalance:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


        if(cType==PD_PSP_FLOAT){

                /* EXEC SQL EXECUTE
                    BEGIN

                        :hv_return_value := sp_psp_balance_credit(
                                :hv_psp_id:ind_psp_id,
                                :hv_country_id:ind_country_id,
                                :hv_ccy_id:ind_ccy_id,
                                :hv_balance:ind_balance,
                                :hv_create_user:ind_create_user);

                    END;
                END-EXEC; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "begin :hv_return_value := sp_psp_balance_cre\
dit ( :hv_psp_id:ind_psp_id , :hv_country_id:ind_country_id , :hv_ccy_id:ind_\
ccy_id , :hv_balance:ind_balance , :hv_create_user:ind_create_user ) ; END ;";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )493;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&hv_psp_id;
                sqlstm.sqhstl[1] = (unsigned long )12;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_psp_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
                sqlstm.sqhstl[2] = (unsigned long )4;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_country_id;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
                sqlstm.sqhstl[3] = (unsigned long )5;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&hv_balance;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_balance;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&hv_create_user;
                sqlstm.sqhstl[5] = (unsigned long )22;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_create_user;
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
                if (sqlca.sqlcode < 0) goto creditbal_error;
}


        }
        else{

                /* EXEC SQL EXECUTE
                    BEGIN

                        :hv_return_value := sp_psp_balance_credit_bal(
                                :hv_psp_id:ind_psp_id,
                                :hv_country_id:ind_country_id,
                                :hv_ccy_id:ind_ccy_id,
                                :hv_balance:ind_balance,
                                :hv_create_user:ind_create_user);

                    END;
                END-EXEC; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "begin :hv_return_value := sp_psp_balance_cre\
dit_bal ( :hv_psp_id:ind_psp_id , :hv_country_id:ind_country_id , :hv_ccy_id:\
ind_ccy_id , :hv_balance:ind_balance , :hv_create_user:ind_create_user ) ; EN\
D ;";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )532;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&hv_psp_id;
                sqlstm.sqhstl[1] = (unsigned long )12;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_psp_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
                sqlstm.sqhstl[2] = (unsigned long )4;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_country_id;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
                sqlstm.sqhstl[3] = (unsigned long )5;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&hv_balance;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_balance;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&hv_create_user;
                sqlstm.sqhstl[5] = (unsigned long )22;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_create_user;
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
                if (sqlca.sqlcode < 0) goto creditbal_error;
}


        }


DEBUGLOG(("CreditBalance:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("CreditBalance:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("pr_bo_funct CreditBalance: SP_OTHER_ERR \n");
DEBUGLOG(("CreditBalance: SP_OTHER_ERR \n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("pr_bo_funct CreditBalance: SP_ERR \n");
DEBUGLOG(("CreditBalance: SP_ERR \n"));
                return PD_ERR;
        }

creditbal_error:
DEBUGLOG(("creditbal_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("pr_bo_funct CreditBalance: SP_ERR \n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int prbo_DebitBalance(const char* csPsp,
                const char* csCountryId,
                const char* csCcy,
                char  cType,
                double dAmt,
                char* csUpdateUser)

{

        /* EXEC SQL WHENEVER SQLERROR GOTO debit_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                double          hv_balance;
                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



                short           ind_psp_id = -1;
                short           ind_country_id = -1;
                short           ind_ccy_id = -1;
                short           ind_balance = -1;
                short           ind_create_user = -1;

                short           hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("DebitBalance: Begin\n"));

        hv_psp_id.len = strlen(csPsp);
        strncpy((char*)hv_psp_id.arr, csPsp, hv_psp_id.len);
        ind_psp_id = 0;
DEBUGLOG(("DebitBalance:psp_id = [%.*s]\n",hv_psp_id.len,hv_psp_id.arr));

        hv_country_id.len = strlen(csCountryId);
        strncpy((char*)hv_country_id.arr, csCountryId, hv_country_id.len);
        ind_country_id = 0;
DEBUGLOG(("DebitBalance:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

        hv_ccy_id.len = strlen(csCcy);
        strncpy((char*)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
        ind_ccy_id = 0;
DEBUGLOG(("DebitBalance:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

        hv_balance= dAmt;
        ind_balance= 0;
DEBUGLOG(("DebitBalance:balance = [%f]\n",hv_balance));


        hv_create_user.len = strlen(csUpdateUser);
        strncpy((char*)hv_create_user.arr, csUpdateUser, hv_create_user.len);
        ind_create_user = 0;
DEBUGLOG(("DebitBalance:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


        if(cType==PD_PSP_FLOAT){

                /* EXEC SQL EXECUTE
                    BEGIN

                        :hv_return_value := sp_psp_balance_debit(
                                :hv_psp_id:ind_psp_id,
                                :hv_country_id:ind_country_id,
                                :hv_ccy_id:ind_ccy_id,
                                :hv_balance:ind_balance,
                                :hv_create_user:ind_create_user);

                    END;
                END-EXEC; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "begin :hv_return_value := sp_psp_balance_deb\
it ( :hv_psp_id:ind_psp_id , :hv_country_id:ind_country_id , :hv_ccy_id:ind_c\
cy_id , :hv_balance:ind_balance , :hv_create_user:ind_create_user ) ; END ;";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )571;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&hv_psp_id;
                sqlstm.sqhstl[1] = (unsigned long )12;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_psp_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
                sqlstm.sqhstl[2] = (unsigned long )4;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_country_id;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
                sqlstm.sqhstl[3] = (unsigned long )5;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&hv_balance;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_balance;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&hv_create_user;
                sqlstm.sqhstl[5] = (unsigned long )22;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_create_user;
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
                if (sqlca.sqlcode < 0) goto debit_error;
}


        }
        else{

                /* EXEC SQL EXECUTE
                    BEGIN

                        :hv_return_value := sp_psp_balance_debit_bal(
                                :hv_psp_id:ind_psp_id,
                                :hv_country_id:ind_country_id,
                                :hv_ccy_id:ind_ccy_id,
                                :hv_balance:ind_balance,
                                :hv_create_user:ind_create_user);

                    END;
                END-EXEC; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "begin :hv_return_value := sp_psp_balance_deb\
it_bal ( :hv_psp_id:ind_psp_id , :hv_country_id:ind_country_id , :hv_ccy_id:i\
nd_ccy_id , :hv_balance:ind_balance , :hv_create_user:ind_create_user ) ; END\
 ;";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )610;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&hv_psp_id;
                sqlstm.sqhstl[1] = (unsigned long )12;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_psp_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
                sqlstm.sqhstl[2] = (unsigned long )4;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_country_id;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
                sqlstm.sqhstl[3] = (unsigned long )5;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&hv_balance;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_balance;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&hv_create_user;
                sqlstm.sqhstl[5] = (unsigned long )22;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_create_user;
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
                if (sqlca.sqlcode < 0) goto debit_error;
}


        }


DEBUGLOG(("DebitBalance:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("DebitBalance:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("pr_bo_funct DebitBalance: SP_OTHER_ERR \n");
DEBUGLOG(("DebitBalance: SP_OTHER_ERR \n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("pr_bo_funct DebitBalance: SP_ERR \n");
DEBUGLOG(("DebitBalance: SP_ERR \n"));
                return PD_ERR;
        }

debit_error:
DEBUGLOG(("debit_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("pr_bo_funct DebitBalance: SP_ERR \n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;

}



int prbo_GetBalance(const char* csPspID,
                const char* csCountryId,
                const char* csCurrencyId,
                hash_t *hVal)
{
        int iRet = PD_OK;

        /* EXEC SQL WHENEVER SQLERROR GOTO get_bal_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;


                double          v_balance;
                double          v_total_float;
                double          v_total_hold;

                short           ind_balance= -1;
                short           ind_total_float= -1;
                short           ind_total_hold= -1;


        /* EXEC SQL END DECLARE SECTION; */ 


        hv_psp_id.len = strlen(csPspID);
        memcpy(hv_psp_id.arr,csPspID,hv_psp_id.len);
DEBUGLOG(("GetBalance psp_id = [%.*s]\n",hv_psp_id.len,hv_psp_id.arr));

        hv_country_id.len = strlen(csCountryId);
        memcpy(hv_country_id.arr,csCountryId,hv_country_id.len);
DEBUGLOG(("GetBalance country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

        hv_ccy_id.len = strlen(csCurrencyId);
        memcpy(hv_ccy_id.arr,csCurrencyId,hv_ccy_id.len);
DEBUGLOG(("GetBalance ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

        /* EXEC SQL select pb_bal,
                        pb_total_float,
                        pb_total_hold
                 into   :v_balance:ind_balance,
                        :v_total_float:ind_total_float,
                        :v_total_hold:ind_total_hold
                 from   psp_balance
                 where  pb_psp_id = :hv_psp_id
                 and    pb_country_id = :hv_country_id
                 and    pb_currency_id = :hv_ccy_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select pb_bal ,pb_total_float ,pb_total_hold into :b\
0:b1,:b2:b3,:b4:b5  from psp_balance where ((pb_psp_id=:b6 and pb_country_id=\
:b7) and pb_currency_id=:b8)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )649;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_balance;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_balance;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&v_total_float;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_total_float;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&v_total_hold;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_total_hold;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_psp_id;
        sqlstm.sqhstl[3] = (unsigned long )12;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_country_id;
        sqlstm.sqhstl[4] = (unsigned long )4;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_ccy_id;
        sqlstm.sqhstl[5] = (unsigned long )5;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
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
        if (sqlca.sqlcode < 0) goto get_bal_error;
}




// balance
        if(ind_balance<0)
                v_balance = 0;
        PutField_Double(hVal,"balance",v_balance);
DEBUGLOG(("GetBalance balance = [%f]\n",v_balance));

        if(ind_total_float<0)
                v_total_float = 0;
        PutField_Double(hVal,"total_float",v_total_float);
DEBUGLOG(("GetBalance total_float = [%f]\n",v_total_float));

        if(ind_total_hold<0)
                v_total_hold = 0;
        PutField_Double(hVal,"total_hold",v_total_hold);
DEBUGLOG(("GetBalance total_hold = [%f]\n",v_total_hold));


DEBUGLOG(("GetBalance Normal Exit\n"));
        return iRet;

get_bal_error:
DEBUGLOG(("get_bal_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("pr_bo_funct GetBalance: SP_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int prbo_CalPspCosts(hash_t *hContext,
                const hash_t* hRequest)
{
        int     iRet = PD_OK;
        hash_t  *hRec;

        char    *csOrgPspId;
        char    cPreCalType;
        double  dPreCalValue=0.0;
        double  dPreCalAddValue=0.0;
        double  dPreCalMinValue=0.0;
        double  dPreCalMaxValue=0.0;
        char    cValueType;
        char    cType;
        int     iScale = 0;
        double  dOrgTxnAmt;
        double  dFee=0.0;

        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

DEBUGLOG(("CalPspCosts()\n"));

        if (GetField_Double(hContext,"org_dst_net_amt",&dOrgTxnAmt)) {
DEBUGLOG(("CalPspCosts() org_dst_net_amt = [%f]\n",dOrgTxnAmt));
        }
        else {
DEBUGLOG(("CalPspCosts() org_dst_net_amt not found!!!\n"));
        }

/*org psp id */
        if (GetField_CString(hContext,"org_psp_id",&csOrgPspId)) {
DEBUGLOG(("CalPspCosts() org_psp_id = [%s]\n",csOrgPspId));
        }
        else {
DEBUGLOG(("CalPspCosts() org_psp_id is missing!!!\n"));
        }
/*txn type*/
        if (GetField_Char(hContext,"txn_type",&cType)) {
DEBUGLOG(("CalPspCosts() txn_type = [%c]\n",cType));
        }
        else {
DEBUGLOG(("CalPspCosts() txn_type is missing!!!\n"));
        }

        if (prbo_GetPspCosts(csOrgPspId, cType, rRecordSet)==PD_FOUND) {
                hRec = RecordSet_GetFirst(rRecordSet);
                while(hRec){
                        if (GetField_Char(hRec,"type",&cPreCalType)) {
DEBUGLOG(("CalPspCosts() Precal_type = [%c]\n",cPreCalType));
                        }
                        if (GetField_Double(hRec,"value",&dPreCalValue)) {
DEBUGLOG(("CalPspCosts() Precal_value = [%f]\n",dPreCalValue));
                        }
                        if (GetField_Double(hRec,"add_value",&dPreCalAddValue)) {
DEBUGLOG(("CalPspCosts() Precal_additional_value = [%f]\n",dPreCalAddValue));
                        }
                        if (GetField_Double(hRec,"min_value",&dPreCalMinValue)) {
DEBUGLOG(("CalPspCosts() Precal_min_value = [%f]\n",dPreCalMinValue));
                        }
                        if (GetField_Double(hRec,"max_value",&dPreCalMaxValue)) {
DEBUGLOG(("CalPspCosts() Precal_max_value = [%f]\n",dPreCalMaxValue));
                        }

                        if (GetField_Char(hRec,"value_type",&cValueType)) {
DEBUGLOG(("CalPspCosts() value_type = [%c]\n",cValueType));
                        }

                        if (GetField_Int(hRec,"scale",&iScale)) {
DEBUGLOG(("CalPspCosts() scale = [%d]\n",iScale));
                        }
DEBUGLOG(("CalPspCosts() Precal costs Now!!!\n"));
                        double dTmp = 0;
                        if (cPreCalType == PD_PRECENTAGE) {
                                dTmp = dOrgTxnAmt * (dPreCalValue/100);
                        }
                        else if (cPreCalType == PD_FIXED_AMOUNT) {
                                dTmp = dPreCalValue;
                        }
                        else if(cPreCalType == PD_PRECENT_WITH_FIX){
                                dTmp = dOrgTxnAmt * (dPreCalValue/100);
                                dTmp += dPreCalAddValue;
                        }
DEBUGLOG(("CalPspCosts() costs before rounding = [%f]\n",dTmp));
                        if (cValueType == PD_ROUNDING) {
                                dFee = newround(dTmp,iScale);
                        }
                        else if (cValueType == PD_TRUNC) {
                                dFee = newtrunc(dTmp,iScale);
                        }
                        else if (cValueType == PD_CELING) {
                                dFee = newceling(dTmp,iScale);
                        }
                        else {
DEBUGLOG(("CalPspCosts() undefine value_type = [%c]\n",cValueType));
ERRLOG("pr_bo_funct CalPspCosts() undefine value_type = [%c]\n",cValueType);
                        }

                        if(dFee<dPreCalMinValue && dPreCalMinValue>0){
                                dFee = dPreCalMinValue;
                        }
                        if(dFee>dPreCalMaxValue && dPreCalMaxValue>0){
                                dFee = dPreCalMaxValue;
                        }

                        hRec = RecordSet_GetNext(rRecordSet);
                }

DEBUGLOG(("CalPspCosts() Precal fee = [%f]\n",dFee));
                PutField_Double(hContext,"precal_fee",dFee);
        }


        RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);

DEBUGLOG(("CalPspCosts() exit = [%d]\n",iRet));
        return iRet;

}


int prbo_GetPspCosts(const char* csPspId,
                const char  cType,
                recordset_t* myRec)
{

        int iRet = PD_NOT_FOUND;
        hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getpspcosts_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

                char            hv_type;
                int             hv_disabled;

                char            v_precal_type;
                double          v_precal_value;
                double          v_precal_additional_value;
                double          v_precal_min_value;
                double          v_precal_max_value;
                char            v_value_type;
                int             v_scale;

                short           ind_precal_type = -1;
                short           ind_precal_value = -1;
                short           ind_precal_additional_value = -1;
                short           ind_precal_min_value = -1;
                short           ind_precal_max_value = -1;
                short           ind_value_type = -1;
                short           ind_scale = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_psp_id.len = strlen(csPspId);
        memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);
DEBUGLOG(("GetPspCosts psp_id = [%d][%.*s]\n",hv_psp_id.len,hv_psp_id.len,hv_psp_id.arr));

        hv_type = cType;
DEBUGLOG(("GetPspCosts type = [%c]\n",hv_type));

        hv_disabled = 0;

        /* EXEC SQL DECLARE c_cursor_getpspcosts CURSOR FOR
                select pc_precal_type,
                        pc_precal_value,
                        pc_precal_additional_value,
                        pc_precal_min_value,
                        pc_precal_max_value,
                        pc_value_type,
                        pc_scale
                  from psp_costs
                 where  pc_effect_date = (
                        select max(pc_effect_date)
                          from psp_costs
                         where pc_effect_date < sysdate
                           and pc_psp_id = :hv_psp_id
                           and pc_txn_type = :hv_type
                           and pc_disabled = :hv_disabled)
                           and pc_psp_id = :hv_psp_id
                           and pc_txn_type = :hv_type
                           and pc_disabled = :hv_disabled; */ 


        /* EXEC SQL OPEN c_cursor_getpspcosts; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0016;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )688;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_psp_id;
        sqlstm.sqhstl[0] = (unsigned long )12;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_type;
        sqlstm.sqhstl[1] = (unsigned long )1;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_disabled;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_psp_id;
        sqlstm.sqhstl[3] = (unsigned long )12;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_type;
        sqlstm.sqhstl[4] = (unsigned long )1;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_disabled;
        sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
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
        if (sqlca.sqlcode < 0) goto getpspcosts_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getpspcosts
                INTO
                        :v_precal_type:ind_precal_type,
                        :v_precal_value:ind_precal_value,
                        :v_precal_additional_value:ind_precal_additional_value,
                        :v_precal_min_value:ind_precal_min_value,
                        :v_precal_max_value:ind_precal_max_value,
                        :v_value_type:ind_value_type,
                        :v_scale:ind_scale; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )727;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_precal_type;
                sqlstm.sqhstl[0] = (unsigned long )1;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_precal_type;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_precal_value;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_precal_value;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_precal_additional_value;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_precal_additional_value;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_precal_min_value;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_precal_min_value;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_precal_max_value;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_precal_max_value;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_value_type;
                sqlstm.sqhstl[5] = (unsigned long )1;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_value_type;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_scale;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_scale;
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
                if (sqlca.sqlcode < 0) goto getpspcosts_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }
                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

                iRet = PD_FOUND;

DEBUGLOG(("GetPspCosts found record\n"));

/* precal_type */
                if (ind_precal_type >= 0) {
                        PutField_Char(myHash,"type",v_precal_type);
DEBUGLOG(("GetPspCosts precal_type = [%c]\n",v_precal_type));
                }

/* precal_value */
                if (ind_precal_value >= 0) {
                        PutField_Double(myHash,"value",v_precal_value);
DEBUGLOG(("GetPspCosts precal_value = [%f]\n",v_precal_value));
                }

/* precal_additional_value */
                if (ind_precal_additional_value >= 0) {
                        PutField_Double(myHash,"add_value",v_precal_additional_value);
DEBUGLOG(("GetPspCosts precal_additional_value = [%f]\n",v_precal_additional_value));
                }

/* precal_min_value */
                if (ind_precal_min_value >= 0) {
                        PutField_Double(myHash,"min_value",v_precal_min_value);
DEBUGLOG(("GetPspCosts precal_min_value = [%f]\n",v_precal_min_value));
                }

/* precal_max_value */
                if (ind_precal_max_value >= 0) {
                        PutField_Double(myHash,"max_value",v_precal_max_value);
DEBUGLOG(("GetPspCosts precal_max_value = [%f]\n",v_precal_max_value));
                }

/* value_type */
                if (ind_value_type >= 0) {
                        PutField_Char(myHash,"value_type",v_value_type);
DEBUGLOG(("GetPspCosts value_type = [%c]\n",v_value_type));
                }

/* scale */
                if (ind_scale >= 0) {
                        PutField_Int(myHash,"scale",v_scale);
DEBUGLOG(("GetPspCosts scale = [%d]\n",v_scale));
                }

                RecordSet_Add(myRec,myHash);
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getpspcosts; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )770;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getpspcosts_error;
}




DEBUGLOG(("GetPspCosts Normal Exit\n"));
        return  iRet;

getpspcosts_error:
DEBUGLOG(("getpspcosts_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("pr_bo_funct GetPspCosts: SP_INTERNAL_ERR \n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getpspcosts; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )785;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_NOT_FOUND;
}


//////////////////////////////////////////////////////////////
/////////////////////////Txn Element//////////////////////////

int     prbo_AddTxnAmtElement(hash_t* hContext)
{
         int     iRet = PD_OK;

        char    *csOrgTxnSeq;
        char    *csOrgTxnCcy;
        double  dTmp;
        char    cTmp;
        char    *csTmp;

        hash_t  *hRec;
        hRec = (hash_t*)  malloc (sizeof(hash_t));

        if (GetField_CString(hContext,"from_txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("AddTxnAmtElement:: org_txn_seq = [%s]\n",csOrgTxnSeq));
        }

        if (GetField_CString(hContext,"org_txn_ccy",&csOrgTxnCcy)) {
DEBUGLOG(("AddTxnAmtElement:: org_txn_ccy= [%s]\n",csOrgTxnCcy));
        }
        else {
DEBUGLOG((" AddTxnAmtElement:: org_txn_ccy is missing!!!, skip  AddTxnAmtElement\n"));
                FREE_ME(hRec);
                return iRet;
        }

        if (GetField_Double(hContext,"org_txn_amt",&dTmp) && iRet == PD_OK) {
                hash_init(hRec,0);

/* txn seq */
                PutField_CString(hRec,"txn_seq",csOrgTxnSeq);

/* chg type */
                PutField_CString(hRec,"txn_element_type",PD_ELEMENT_TXN_AMT);

/* party type */
                if (GetField_Char(hContext, "party_type", &cTmp)) {
                        PutField_Char(hRec,"party_type",cTmp);
DEBUGLOG(("AddTxnAmtElement:: party_type = [%c]\n",cTmp));
                } else {
                        PutField_Char(hRec,"party_type",PD_TYPE_MERCHANT);
                }
/* txn_ccy */
                PutField_CString(hRec,"ccy",csOrgTxnCcy);

/* amount */
                PutField_Double(hRec,"amount",dTmp);

/* user */      PutField_CString(hRec,"add_user",PD_UPDATE_USER);

/* amount type */
                if (GetField_CString(hContext, "amount_type", &csTmp)) {
                        PutField_CString(hRec,"amount_type",csTmp);
DEBUGLOG(("AddTxnAmtElement:: amount_type = [%s]\n",csTmp));
                } else {
                        PutField_CString(hRec,"amount_type",PD_CR);
                }

                iRet = prbo_AddElements(hRec);
                hash_destroy(hRec);
        }

        FREE_ME(hRec);
DEBUGLOG(("AddTxnAmtElement:: iRet = [%d]\n",iRet));
        return  iRet;
}

int     prbo_AddTxnFeeElements(hash_t* hContext)
{
        int     iRet = PD_OK;

        char    *csOrgTxnSeq;
        char    *csOrgTxnCcy;
        char    *csOrgDstTxnCcy;
        double  dTmp;
        char    cTmp;
        char    *csTmp;


        hash_t  *hRec;
        hRec = (hash_t*)  malloc (sizeof(hash_t));

        if (GetField_CString(hContext,"from_txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("AddTxnFeeElements:: org_txn_seq = [%s]\n",csOrgTxnSeq));
        }

        if (GetField_CString(hContext,"src_txn_fee_ccy",&csOrgTxnCcy)) {
DEBUGLOG(("AddTxnFeeElements:: src_txn_fee_ccy= [%s]\n",csOrgTxnCcy));
        }
        else {
DEBUGLOG(("AddTxnFeeElements:: src_txn_fee_ccy is missing!!!, skip AddTxnFeeElements\n"));
                FREE_ME(hRec);
                return iRet;
        }

        if (GetField_CString(hContext,"dst_txn_fee_ccy",&csOrgDstTxnCcy)) {
DEBUGLOG(("AddTxnFeeElements:: dst_txn_fee_ccy= [%s]\n",csOrgDstTxnCcy));
        }
/* merchant fee */
        if (GetField_Double(hContext,"src_txn_fee",&dTmp) && iRet == PD_OK) {

                if(dTmp>0){
DEBUGLOG(("AddTxnFeeElements:: src txn fee = [%lf]\n",dTmp));

                        hash_init(hRec,0);

/* txn seq */
                        PutField_CString(hRec,"txn_seq",csOrgTxnSeq);

/* chg type */
                        PutField_CString(hRec,"txn_element_type",PD_ELEMENT_TXN_FEE);

/* party type */
                        if (GetField_Char(hContext, "party_type", &cTmp)) {
                                PutField_Char(hRec,"party_type",cTmp);
                        } else {
                                PutField_Char(hRec,"party_type",PD_TYPE_MERCHANT);
                        }

/* txn_ccy */
                        PutField_CString(hRec,"ccy",csOrgTxnCcy);

/* fee */
                        PutField_Double(hRec,"amount",dTmp);

/* user */              PutField_CString(hRec,"add_user",PD_UPDATE_USER);

/* amount type */
                        if (GetField_CString(hContext, "amount_type", &csTmp)) {
                                PutField_CString(hRec,"amount_type",csTmp);
                        } else {
                                PutField_CString(hRec,"amount_type",PD_DR);
                        }

                        iRet = prbo_AddElements(hRec);
                        hash_destroy(hRec);
                }
        }


/* customer fee */
        if (GetField_Double(hContext,"dst_txn_fee",&dTmp) && iRet == PD_OK) {
DEBUGLOG(("AddTxnFeeElements:: dst_txn_fee = [%lf]\n",dTmp));

                if(dTmp>0){
                        hash_init(hRec,0);
/* txn seq */
                        PutField_CString(hRec,"txn_seq",csOrgTxnSeq);

/* chg type */
                        PutField_CString(hRec,"txn_element_type",PD_ELEMENT_TXN_FEE);


/* party type */
                        PutField_Char(hRec,"party_type",PD_TYPE_CUSTOMER);

/* txn_ccy */
                        PutField_CString(hRec,"ccy",csOrgDstTxnCcy);

/* fee */
                        PutField_Double(hRec,"amount",dTmp);
/* user */              PutField_CString(hRec,"add_user",PD_UPDATE_USER);
/* amount type */
                        if (GetField_CString(hContext, "amount_type", &csTmp)) {
                                PutField_CString(hRec,"amount_type",csTmp);
                        } else {
                                PutField_CString(hRec,"amount_type",PD_DR);
                        }

                        iRet = prbo_AddElements(hRec);
                        hash_destroy(hRec);
                }
        }


        FREE_ME(hRec);
DEBUGLOG(("AddFeeTxnChgLog:: iRet = [%d]\n",iRet));
        return  iRet;
}

int     prbo_AddMarkupAmtElement(hash_t* hContext)
{
         int     iRet = PD_OK;

        char    *csOrgTxnSeq;
        char    *csOrgTxnCcy;
        //char  *csTxnCode;
        char    *csTmp;
        double  dTmp;

        hash_t  *hRec;
        hRec = (hash_t*)  malloc (sizeof(hash_t));

        if (GetField_CString(hContext,"from_txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("AddMarkupAmtElement:: org_txn_seq = [%s]\n",csOrgTxnSeq));
        }
/*
        if(GetField_CString(hContext,"txn_code", &csTxnCode)){
DEBUGLOG(("AddMarkupAmtElement:: txn_code = [%s]\n",csTxnCode));
        }
*/
        if (GetField_CString(hContext,"org_txn_ccy",&csOrgTxnCcy)) {
DEBUGLOG(("AddMarkupAmtElement:: org_txn_ccy= [%s]\n",csOrgTxnCcy));
        }
        else {
DEBUGLOG((" AddMarkupAmtElement:: org_txn_ccy is missing!!!, skip  AddTxnAmtElement\n"));
                FREE_ME(hRec);
                return iRet;
        }

        if (GetField_Double(hContext,"markup_amt",&dTmp) && iRet == PD_OK) {
                hash_init(hRec,0);
/* txn seq */
                PutField_CString(hRec,"txn_seq",csOrgTxnSeq);

/* chg type */
                PutField_CString(hRec,"txn_element_type",PD_ELEMENT_MARKUP_AMT);
/* party type */
                PutField_Char(hRec,"party_type",PD_TYPE_CUSTOMER);

/* txn_ccy */
                PutField_CString(hRec,"ccy",csOrgTxnCcy);

/* amount */
                PutField_Double(hRec,"amount",dTmp);

/*markup rate*/
                if(GetField_Double(hContext,"markup_rate",&dTmp)){
                        PutField_Double(hRec,"rate",dTmp);
                }


/* user */      PutField_CString(hRec,"add_user",PD_UPDATE_USER);

                if (GetField_CString(hContext, "amount_type", &csTmp)) {
                        PutField_CString(hRec,"amount_type",csTmp);
                } else {

                        //if(!strcmp(csTxnCode))
                        PutField_CString(hRec,"amount_type",PD_DR);
                }

                iRet = prbo_AddElements(hRec);
                hash_destroy(hRec);
        }

        FREE_ME(hRec);
DEBUGLOG(("AddMarkupAmtElement:: iRet = [%d]\n",iRet));
        return  iRet;
}

int prbo_AddElements(const hash_t *hRls)
{
        char            *csTmp;
        char            cTmp;
        double          dTmp;


        /* EXEC SQL WHENEVER SQLERROR GOTO addelement_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        short           hv_return_value;

        /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

        /* varchar         hv_txn_element_type[PD_TXN_ELEMENT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_txn_element_type;

        char            hv_party_type;
        double          hv_amount;
        /* varchar         hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

        /* varchar         hv_amt_type[PD_AMT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_amt_type;

        /* varchar         hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;

        double          hv_rate;


        short           ind_txn_id = -1;
        short           ind_txn_element_type = -1;
        short           ind_party_type = -1;
        short           ind_amount = -1;
        short           ind_ccy = -1;
        short           ind_amt_type = -1;
        short           ind_add_user = -1;
        short           ind_rate = -1;

        /* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("AddElements: Begin\n"));

/* txn_seq */
        if (GetField_CString(hRls,"txn_seq",&csTmp)) {
                hv_txn_id.len = strlen(csTmp);
                memcpy(hv_txn_id.arr,csTmp,hv_txn_id.len);
                ind_txn_id = 0;
DEBUGLOG(("AddElements:txn_id = [%.*s][%d]\n",hv_txn_id.len,hv_txn_id.arr,hv_txn_id.len));
        }

/* txn_element_type */
        if (GetField_CString(hRls,"txn_element_type",&csTmp)) {
                hv_txn_element_type.len = strlen(csTmp);
                memcpy(hv_txn_element_type.arr,csTmp,hv_txn_element_type.len);
                ind_txn_element_type = 0;
DEBUGLOG(("AddElements:txn_element_type = [%.*s][%d]\n",hv_txn_element_type.len,hv_txn_element_type.arr,hv_txn_element_type.len));
        }
/* party type */
        if (GetField_Char(hRls,"party_type",&cTmp)) {
                hv_party_type = cTmp;
                ind_party_type = 0;
DEBUGLOG(("AddElements:party_type = [%c]\n",hv_party_type));
        }

/* amount */
        if (GetField_Double(hRls,"amount",&dTmp)) {
                hv_amount = dTmp;
                ind_amount = 0;
DEBUGLOG(("AddElements:amount = [%lf]\n",hv_amount));
        }

/* ccy */
        if (GetField_CString(hRls,"ccy",&csTmp)) {
                hv_ccy.len = strlen(csTmp);
                memcpy(hv_ccy.arr,csTmp,hv_ccy.len);
                ind_ccy = 0;
DEBUGLOG(("AddElements:ccy = [%.*s][%d]\n",hv_ccy.len,hv_ccy.arr,hv_ccy.len));
        }

/* amt_type */
        if (GetField_CString(hRls,"amount_type",&csTmp)) {
                hv_amt_type.len = strlen(csTmp);
                memcpy(hv_amt_type.arr,csTmp,hv_amt_type.len);
                ind_amt_type = 0;
DEBUGLOG(("AddElements:amt_type = [%.*s][%d]\n",hv_amt_type.len,hv_amt_type.arr,hv_amt_type.len));
        }

/* add user */
        if (GetField_CString(hRls,"add_user",&csTmp)) {
                hv_add_user.len = strlen(csTmp);
                memcpy(hv_add_user.arr,csTmp,hv_add_user.len);
                ind_add_user = 0;
DEBUGLOG(("AddElements:add_user = [%.*s][%d]\n",hv_add_user.len,hv_add_user.arr,hv_add_user.len));
        }
/* rate */
        if (GetField_Double(hRls,"rate",&dTmp)) {
                hv_rate = dTmp;
                ind_rate = 0;
DEBUGLOG(("AddElements:rate = [%lf]\n",hv_rate));
        }



        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_txn_elements_insert(
                                        :hv_txn_id:ind_txn_id,
                                        :hv_txn_element_type:ind_txn_element_type,
                                        :hv_party_type:ind_party_type,
                                        :hv_amount:ind_amount,
                                        :hv_ccy:ind_ccy,
                                        :hv_amt_type:ind_amt_type,
                                        :hv_rate:ind_rate,
                                        :hv_add_user:ind_add_user);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_txn_elements_insert ( :\
hv_txn_id:ind_txn_id , :hv_txn_element_type:ind_txn_element_type , :hv_party_\
type:ind_party_type , :hv_amount:ind_amount , :hv_ccy:ind_ccy , :hv_amt_type:\
ind_amt_type , :hv_rate:ind_rate , :hv_add_user:ind_add_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )800;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_element_type;
        sqlstm.sqhstl[2] = (unsigned long )6;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_txn_element_type;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_party_type;
        sqlstm.sqhstl[3] = (unsigned long )1;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_party_type;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_amount;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_amount;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_ccy;
        sqlstm.sqhstl[5] = (unsigned long )5;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_ccy;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_amt_type;
        sqlstm.sqhstl[6] = (unsigned long )4;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_amt_type;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_rate;
        sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_rate;
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
        if (sqlca.sqlcode < 0) goto addelement_error;
}



DEBUGLOG(("AddElements:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK) {
DEBUGLOG(("AddElements:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("pr_bo_funct AddElements: SP_OTHER_ERR \n");
DEBUGLOG(("AddElements: SP_OTHER_ERR\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("pr_bo_funct AddElements: SP_ERR \n");
DEBUGLOG(("AddElements: SP_ERR\n"));
                return PD_ERR;
        }


addelement_error:
DEBUGLOG(("addelement_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("pr_bo_funct AddElements: SP_INTERNAL_ERR \n");
DEBUGLOG(("AddElements: SP_INTERNAL_ERR \n"));
        return PD_INTERNAL_ERR;
}

int prbo_ProcessMerchantAdjAmount(hash_t *hContext)
{
        int     iRet = PD_OK;
        char    *csTxnCountry;
        char    *csTxnCcy;
        char    *csMerchantId;
        char    *csServiceCode;
        char    cDCType;
        double  dNetAmt=0.0;
        char    *csUser;
        double  dTmp;
        double  dAvaBal = 0.0;

        hash_t* hVal;
        hVal = (hash_t*) malloc (sizeof(hash_t));


DEBUGLOG(("ProcessMerchantAdjAmount()\n"));

/*txn country */
        if (GetField_CString(hContext,"txn_country",&csTxnCountry)) {
DEBUGLOG(("ProcessMerchantAdjAmount() txn_country = [%s]\n",csTxnCountry));
        }
        else {
DEBUGLOG(("ProcessMerchantAdjAmount() txn_country is missing!!!\n"));
        }

/*txn ccy */
        if (GetField_CString(hContext,"txn_ccy",&csTxnCcy)) {
DEBUGLOG(("ProcesseMerchantAdjAmount() txn_ccy = [%s]\n",csTxnCcy));
        }
        else {
DEBUGLOG(("ProcessMerchantAdjAmount() txn_ccy is missing!!!\n"));
        }
/*service Code */
        if (GetField_CString(hContext,"service_code",&csServiceCode)) {
DEBUGLOG(("ProcessMerchantAdjAmount() service_code = [%s]\n",csServiceCode));
        }
        else {
DEBUGLOG(("ProcessMerchantAdjAmount() service_code is missing!!!\n"));
        }

/*merchant id */
        if (GetField_CString(hContext,"merchant_id",&csMerchantId)) {
DEBUGLOG(("ProcessMerchantAdjAmount() merchant_id = [%s]\n",csMerchantId));
        }
        else {
DEBUGLOG(("ProcessMerchantAdjAmount() merchant_id is missing!!!\n"));
        }

/* net amount */
        if (GetField_Double(hContext,"net_amt",&dNetAmt)) {
DEBUGLOG(("BOBalance:ProcessMerchantAdjAmount() net_amt = [%lf]\n",dNetAmt));
        }
        else {
DEBUGLOG(("ProcessMerchantAdjAmount() net_amt is missing!!!\n"));
        }

/* credit or debit - real action */
        if (GetField_Char(hContext, "dc_type", &cDCType)) {
DEBUGLOG(("ProcessMerchantAdjAmount() cDCType = [%c]\n",cDCType));
        }
        else {
DEBUGLOG(("ProcessMerchantAdjAmount() cDCType is missing !!!\n"));
        }

        if (GetField_CString(hContext, "add_user", &csUser)) {
DEBUGLOG(("ProcessMerchantAdjAmount() User = [%s]\n",csUser));
        }
        else {
DEBUGLOG(("ProcessMerchantAdjAmount() User is missing !!!\n"));
        }


        if (iRet == PD_OK) {
                hash_init(hVal, 0);
DEBUGLOG(("ProcessMerchantAdjAmount(): GetSettAvalBalance\n"));

                if(prbo_GetSettAvalBalance(hVal, csMerchantId, csTxnCcy, csTxnCountry, csServiceCode, &dAvaBal) != PD_OK){
DEBUGLOG(("ProcessMerchantAdjAmount() GetOpenBalanceForUpdate Failed !\n"));
                        iRet = INT_ERR;
                } else {

DEBUGLOG(("ProcessMerchantAdjAmount() Available Sett Balance [%lf]\n", dAvaBal));

                        if (GetField_Double(hVal, "merchant_open_bal", &dTmp)) {
DEBUGLOG(("ProcessMerchantAdjAmount() GetOpenBalanceForUpdate open_bal = [%f]\n",dTmp));
                                PutField_Double(hContext, "merchant_open_bal", dTmp);
                        }
                        else {
                                PutField_Double(hContext, "merchant_open_bal", 0.0);
                        }

                        if (GetField_Double(hVal, "merchant_open_bal_settlement", &dTmp)) {
DEBUGLOG(("ProcessMerchantAdjAmount() GetOpenBalanceForUpdate open_bal_settlement = [%f]\n",dTmp));
                                PutField_Double(hContext, "merchant_open_bal_settlement", dTmp);
                        }
                        else {
                                PutField_Double(hContext, "merchant_open_bal_settlement", 0.0);
                        }
                }
                hash_destroy(hVal);
        }

	/*
        if (iRet == PD_OK) {
                // Chk Balance
                if (cDCType == PD_IND_DEBIT) {
                        if (dAvaBal < dNetAmt) {
DEBUGLOG(("BOBalance:ProcessMerchantAdjAmount() INSUFFICIENT_FUND\n"));
                                iRet = INT_INSUFFICIENT_FUND;
                        }
                }
        }
	*/

        if (iRet == PD_OK) {
DEBUGLOG(("ProcessMerchantAdjAmount() Call UpdateAdjBal\n"));
                if(prbo_UpdateAdjBal(csMerchantId,csTxnCountry,csTxnCcy, csServiceCode, dNetAmt, cDCType, csUser)!= PD_OK){
DEBUGLOG(("ProcessMerchantAdjAmount() UpdateSettBal Failed !\n"));
                        iRet = INT_ERR;
                }
        }
        if (iRet == PD_OK) {
                hash_init(hVal,0);

                if(prbo_GetCurrentValues(csMerchantId,csTxnCcy,csTxnCountry,csServiceCode,hVal)!=PD_ERR){
                        if(GetField_Double(hVal,"current_bal",&dTmp)){
                                PutField_Double(hContext,"current_bal",dTmp);
DEBUGLOG(("UpdateMerchantAdjAmount() current_bal= [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"total_float",&dTmp)){
                                PutField_Double(hContext,"total_float",dTmp);
DEBUGLOG(("UpdateMerchantAdjAmount() total_float= [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"current_bal_settlement",&dTmp)){
                                PutField_Double(hContext,"current_bal_settlement",dTmp);
DEBUGLOG(("UpdateMerchantAdjAmount() current_bal_settlement= [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"total_float_settlement",&dTmp)){
                                PutField_Double(hContext,"total_float_settlement",dTmp);
DEBUGLOG(("UpdateMerchantAdjAmount() total_float_settlement= [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"total_reserved_amount",&dTmp)){
                                PutField_Double(hContext,"total_reserved_amount",dTmp);
DEBUGLOG(("UpdateMerchantAdjAmount() total_reserved_amount= [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"total_hold",&dTmp)){
                                PutField_Double(hContext,"total_hold",dTmp);
DEBUGLOG(("UpdateMerchantAdjAmount() total_hold= [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"total_hold_settlement",&dTmp)){
                                PutField_Double(hContext,"total_hold_settlement",dTmp);
DEBUGLOG(("UpdateMerchantAdjAmount() total_hold_settlement= [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"total_float_after_payout",&dTmp)){
                                PutField_Double(hContext,"total_float_after_payout",dTmp);
DEBUGLOG(("UpdateMerchantAdjAmount() total_float_after_payout= [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"fundin_payout",&dTmp)){
                                PutField_Double(hContext,"fundin_payout",dTmp);
DEBUGLOG(("UpdateMerchantAdjAmount() fundin_payout= [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"reserved_payout",&dTmp)){
                                PutField_Double(hContext,"reserved_payout",dTmp);
DEBUGLOG(("UpdateMerchantAdjAmount() reserved_payout= [%f]\n",dTmp));
                        }
                }
                else {
DEBUGLOG(("UpdateMerchantAdjAmount() GetCurrentValue Failed !\n"));
                        iRet = INT_ERR;
                }

                hash_destroy(hVal);
        }


        FREE_ME(hVal);

DEBUGLOG(("UpdateMerchantAdjAmount()  exit = [%d]\n",iRet));

        return iRet;
}

int prbo_GetSettAvalBalance(hash_t* hContext,
                const char* csMerchantID,
                const char* csCurrencyId,
                const char* csCountryId,
                const char* csServiceCode,
                double  *dBal)
{
        *dBal = 0.0;
        int iRet = PD_OK;
    
        /* EXEC SQL WHENEVER SQLERROR GOTO getsettavalbal_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

    
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

    
                double          v_current_bal;
                double          v_current_bal_sett;
                double          v_total_float_sett;
                double          v_total_hold_sett;
                double          v_total_reserved_sett;

                short           ind_current_bal= -1;
                short           ind_current_bal_sett= -1;
                short           ind_total_float_sett= -1;
                short           ind_total_hold_sett= -1;
                short           ind_total_reserved_sett= -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_merchant_id.len = strlen(csMerchantID);
        memcpy(hv_merchant_id.arr,csMerchantID,hv_merchant_id.len);
DEBUGLOG(("GetSettAvalBalance merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

        hv_ccy_id.len = strlen(csCurrencyId);
        memcpy(hv_ccy_id.arr,csCurrencyId,hv_ccy_id.len);
DEBUGLOG(("GetSettAvalBalance ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

        hv_country_id.len = strlen(csCountryId);
        memcpy(hv_country_id.arr,csCountryId,hv_country_id.len);
DEBUGLOG(("GetSettAvalBalance country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

        hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("GetSettAvalBalance service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

        /* EXEC SQL DECLARE c_cursor_getsettavalbal CURSOR FOR
                select  m_current_bal_settlement,
                        m_total_float_settlement,
                        m_total_hold_settlement,
                        m_total_reserved_amount,
                        m_current_bal
                  from merchant_balance
                 where m_merchant_id = :hv_merchant_id
                   and m_currency_id = :hv_ccy_id
                   and m_country_id = :hv_country_id
                   and m_service_code = :hv_service_code
                 for update; */ 
        /* EXEC SQL OPEN c_cursor_getsettavalbal; */ 

{
                                    struct sqlexd sqlstm;
                                    sqlstm.sqlvsn = 12;
                                    sqlstm.arrsiz = 10;
                                    sqlstm.sqladtp = &sqladt;
                                    sqlstm.sqltdsp = &sqltds;
                                    sqlstm.stmt = sq0018;
                                    sqlstm.iters = (unsigned int  )1;
                                    sqlstm.offset = (unsigned int  )851;
                                    sqlstm.selerr = (unsigned short)1;
                                    sqlstm.cud = sqlcud0;
                                    sqlstm.sqlest = (unsigned char  *)&sqlca;
                                    sqlstm.sqlety = (unsigned short)4352;
                                    sqlstm.occurs = (unsigned int  )0;
                                    sqlstm.sqcmod = (unsigned int )0;
                                    sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
                                    sqlstm.sqhstl[0] = (unsigned long )17;
                                    sqlstm.sqhsts[0] = (         int  )0;
                                    sqlstm.sqindv[0] = (         short *)0;
                                    sqlstm.sqinds[0] = (         int  )0;
                                    sqlstm.sqharm[0] = (unsigned long )0;
                                    sqlstm.sqadto[0] = (unsigned short )0;
                                    sqlstm.sqtdso[0] = (unsigned short )0;
                                    sqlstm.sqhstv[1] = (unsigned char  *)&hv_ccy_id;
                                    sqlstm.sqhstl[1] = (unsigned long )5;
                                    sqlstm.sqhsts[1] = (         int  )0;
                                    sqlstm.sqindv[1] = (         short *)0;
                                    sqlstm.sqinds[1] = (         int  )0;
                                    sqlstm.sqharm[1] = (unsigned long )0;
                                    sqlstm.sqadto[1] = (unsigned short )0;
                                    sqlstm.sqtdso[1] = (unsigned short )0;
                                    sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
                                    sqlstm.sqhstl[2] = (unsigned long )4;
                                    sqlstm.sqhsts[2] = (         int  )0;
                                    sqlstm.sqindv[2] = (         short *)0;
                                    sqlstm.sqinds[2] = (         int  )0;
                                    sqlstm.sqharm[2] = (unsigned long )0;
                                    sqlstm.sqadto[2] = (unsigned short )0;
                                    sqlstm.sqtdso[2] = (unsigned short )0;
                                    sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
                                    sqlstm.sqhstl[3] = (unsigned long )5;
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
                                    if (sqlca.sqlcode < 0) goto getsettavalbal_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getsettavalbal
                INTO
                        :v_current_bal_sett:ind_current_bal_sett,
                        :v_total_float_sett:ind_total_float_sett,
                        :v_total_hold_sett:ind_total_hold_sett,
                        :v_total_reserved_sett:ind_total_reserved_sett,
                        :v_current_bal:ind_current_bal; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )882;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_current_bal_sett;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_current_bal_sett;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_total_float_sett;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_total_float_sett;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_total_hold_sett;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_total_hold_sett;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_total_reserved_sett;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_total_reserved_sett;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_current_bal;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_current_bal;
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
                if (sqlca.sqlcode < 0) goto getsettavalbal_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

// balance
                if(ind_current_bal_sett<0)
                        v_current_bal_sett = 0.0;
                if(ind_total_float_sett<0)
                        v_total_float_sett= 0.0;
                if(ind_total_hold_sett<0)
                        v_total_hold_sett= 0.0;
                if(ind_total_reserved_sett<0)
                        v_total_reserved_sett= 0.0;
                if(ind_current_bal<0)
                        v_current_bal= 0.0;

                *dBal=v_current_bal_sett-v_total_float_sett-v_total_hold_sett-v_total_reserved_sett;
DEBUGLOG(("GetSettAvalBalance balance = [%f]\n",*dBal));

                PutField_Double(hContext,"merchant_open_bal",v_current_bal);
                PutField_Double(hContext,"merchant_open_bal_settlement",v_current_bal_sett);

        }        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getsettavalbal; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )917;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getsettavalbal_error;
}



DEBUGLOG(("GetSettAvalBalance Normal Exit\n"));
        return iRet;

getsettavalbal_error:
DEBUGLOG(("getsettavalbal_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getsettavalbal; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )932;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        TxnAbort();
        return PD_ERR;
}

int prbo_UpdateAdjBal(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dNetAmt,
                char    cType,
                const char* csUser)

{

        /* EXEC SQL WHENEVER SQLERROR GOTO upd_adj_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                double          hv_amt;
                /* varchar         hv_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_user;


                short           ind_merchant_id = -1;
                short           ind_country_id = -1;
                short           ind_ccy_id = -1;
                short           ind_service_code = -1;
                short           ind_amt = -1;
                short           ind_user = -1;

                short           hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("UpdateAdjBal: Begin\n"));

        hv_merchant_id.len = strlen(csMerchantId);
        strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
        ind_merchant_id = 0;

        hv_country_id.len = strlen(csCountryId);
        strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
        ind_country_id = 0;

        hv_ccy_id.len = strlen(csCcy);
        strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
        ind_ccy_id = 0;

        hv_service_code.len = strlen(csServiceCode);
        strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
        ind_service_code = 0;

        if(cType==PD_IND_DEBIT){
                hv_amt = (-1)*dNetAmt;
                ind_amt= 0;
        }
        else{
                hv_amt = dNetAmt;
                ind_amt= 0;
        }
DEBUGLOG(("UpdateAdjBal:Netamt = [%f]\n",dNetAmt));
DEBUGLOG(("UpdateAdjBal:net_amt = [%f]\n",hv_amt));
DEBUGLOG(("UpdateAdjBal:type => [%c]\n",cType));

        hv_user.len = strlen(csUser);
        strncpy((char *)hv_user.arr, csUser, hv_user.len);
        ind_user = 0;
//DEBUGLOG(("UpdateAdjBal:TESTIING\n"));

                /* EXEC SQL EXECUTE
                   BEGIN

                        :hv_return_value := sp_merchant_bal_upd_adj_bal(
                                :hv_merchant_id:ind_merchant_id,
                                :hv_country_id:ind_country_id,
                                :hv_ccy_id:ind_ccy_id,
                                :hv_service_code:ind_service_code,
                                :hv_amt:ind_amt,
                                :hv_user:ind_user);

                   END;
                END-EXEC; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "begin :hv_return_value := sp_merchant_bal_up\
d_adj_bal ( :hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id ,\
 :hv_ccy_id:ind_ccy_id , :hv_service_code:ind_service_code , :hv_amt:ind_amt \
, :hv_user:ind_user ) ; END ;";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )947;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
                sqlstm.sqhstl[1] = (unsigned long )17;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
                sqlstm.sqhstl[2] = (unsigned long )4;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_country_id;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
                sqlstm.sqhstl[3] = (unsigned long )5;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
                sqlstm.sqhstl[4] = (unsigned long )5;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_service_code;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&hv_amt;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_amt;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&hv_user;
                sqlstm.sqhstl[6] = (unsigned long )22;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_user;
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
                if (sqlca.sqlcode < 0) goto upd_adj_error;
}



        if (hv_return_value == SP_OK)        {
DEBUGLOG(("UpdateAdjBal:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MerchantBlance::UpdateAdjBal: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateAdjBal: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("MerchantBlance::UpdateAdjBal: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateAdjBal: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }
upd_adj_error:
DEBUGLOG(("upd_sett_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int     prbo_AddReserveAmtElement(hash_t* hContext)
{
         int     iRet = PD_OK;

        char    *csOrgTxnSeq;
        char    *csOrgTxnCcy;
        char    *csTmp;
        double  dTmp;

        hash_t  *hRec;
        hRec = (hash_t*)  malloc (sizeof(hash_t));

        if (GetField_CString(hContext,"org_txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("AddReserveAmt:: org_txn_seq = [%s]\n",csOrgTxnSeq));
        }

        if (GetField_CString(hContext,"org_txn_ccy",&csOrgTxnCcy)) {
DEBUGLOG(("AddReserveAmt:: org_txn_ccy= [%s]\n",csOrgTxnCcy));
        }
        else {
DEBUGLOG((" AddReserveAmt:: org_txn_ccy is missing!!!, skip  AddTxnAmtElement\n"));
                FREE_ME(hRec);
                return iRet;
        }

        if (GetField_Double(hContext,"reserve_amt",&dTmp) && iRet == PD_OK) {
                hash_init(hRec,0);
                //DBObjPtr = CreateObj(DBPtr,"DBTxnElements","Add");

/* txn seq */
                PutField_CString(hRec,"txn_seq",csOrgTxnSeq);

/* chg type */
                PutField_CString(hRec,"txn_element_type",PD_ELEMENT_RES_AMT);

/* party type */
                PutField_Char(hRec,"party_type",PD_TYPE_MERCHANT);

/* txn_ccy */
                PutField_CString(hRec,"ccy",csOrgTxnCcy);
/* amount */
                PutField_Double(hRec,"amount",dTmp);

/* user */      PutField_CString(hRec,"add_user",PD_UPDATE_USER);

/* amount type */
                if (GetField_CString(hContext, "amount_type", &csTmp)) {
                        PutField_CString(hRec,"amount_type",csTmp);
                }
                else {
DEBUGLOG(("AddReserAmt: count not find amount_type\n"));
                }

                if (dTmp > 0.0) {
			iRet = prbo_AddElements(hRec);
                }
                hash_destroy(hRec);
        }

        FREE_ME(hRec);
DEBUGLOG(("AddReserveAmt:: iRet = [%d]\n",iRet));
        return  iRet;
}

int     prbo_AddPspTxnElement(hash_t* hRequest)
{
         int     iRet = PD_OK;

        char    *csOrgTxnSeq;
        char    *csOrgTxnCcy;
        double  dTmp;
        char    cTmp;
        char    *csTmp;

        hash_t  *hRec;
        hRec = (hash_t*)  malloc (sizeof(hash_t));

        if (GetField_CString(hRequest,"txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("AddPspTxnElement:: txn_seq = [%s]\n",csOrgTxnSeq));
        }

        if (GetField_CString(hRequest,"txn_ccy",&csOrgTxnCcy)) {
DEBUGLOG(("AddPspTxnElement:: txn_ccy= [%s]\n",csOrgTxnCcy));
        }
        else {
DEBUGLOG((" AddPspTxnElement:: txn_ccy is missing!!!, skip  AddPspTxnElement\n"));
                FREE_ME(hRec);
                return iRet;
        }
        if (GetField_Double(hRequest,"txn_amt",&dTmp) && iRet == PD_OK) {
                hash_init(hRec,0);
                //DBObjPtr = CreateObj(DBPtr,"DBTxnElements","Add");

/* txn seq */
                PutField_CString(hRec,"txn_seq",csOrgTxnSeq);

/* chg type */
                if(GetField_CString(hRequest,"txn_element_type",&csTmp)){
                        PutField_CString(hRec,"txn_element_type",csTmp);
                }

/* party type */
                if(GetField_Char(hRequest,"party_type",&cTmp)){
DEBUGLOG(("AddHoldAmt:: party_type= [%c]\n",cTmp));
                        PutField_Char(hRec,"party_type",cTmp);
                }
                else
                        PutField_Char(hRec,"party_type",PD_TYPE_MERCHANT);

/* txn_ccy */
                PutField_CString(hRec,"ccy",csOrgTxnCcy);

/* amount */
                PutField_Double(hRec,"amount",dTmp);

/* user */      PutField_CString(hRec,"add_user",PD_UPDATE_USER);

/*amount_type */
                if (GetField_CString(hRequest, "amount_type", &csTmp)) {
                        PutField_CString(hRec,"amount_type",csTmp);
                }

                //iRet = (unsigned long)(*DBObjPtr)(hRec);
		iRet = prbo_AddElements(hRec);

                hash_destroy(hRec);
        }

        FREE_ME(hRec);
DEBUGLOG(("AddPspTxnElement:: iRet = [%d]\n",iRet));
        return  iRet;
}

int     prbo_AddPayoutBalTransferElement(hash_t* hContext)
{
         int     iRet = PD_OK;

        char    *csOrgTxnSeq;
        char    *csOrgTxnCcy;
        double  dTmp;
        char    cTmp;
        char    *csTmp;

        hash_t  *hRec;
        hRec = (hash_t*)  malloc (sizeof(hash_t));

        if (GetField_CString(hContext,"from_txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("AddPayoutBalTransferElement:: org_txn_seq = [%s]\n",csOrgTxnSeq));
        }

        if (GetField_CString(hContext,"org_txn_ccy",&csOrgTxnCcy)) {
DEBUGLOG(("AddPayoutBalTransferElement:: org_txn_ccy= [%s]\n",csOrgTxnCcy));
        }
        else {
DEBUGLOG((" AddPayoutBalTransferElement:: org_txn_ccy is missing!!!, skip  AddPayoutBalTransferElement\n"));
                FREE_ME(hRec);
                return iRet;
        }

        if (GetField_Double(hContext,"org_txn_amt",&dTmp) && iRet == PD_OK) {
                hash_init(hRec,0);

/* txn seq */
                PutField_CString(hRec,"txn_seq",csOrgTxnSeq);

/* chg type */
                PutField_CString(hRec,"txn_element_type", "MAPO");

/* party type */
                if (GetField_Char(hContext, "party_type", &cTmp)) {
                        PutField_Char(hRec,"party_type",cTmp);
DEBUGLOG(("AddTxnAmtElement:: party_type = [%c]\n",cTmp));
                } else {
                        PutField_Char(hRec,"party_type",PD_TYPE_MERCHANT);
                }
/* txn_ccy */
                PutField_CString(hRec,"ccy",csOrgTxnCcy);

/* amount */
                PutField_Double(hRec,"amount",dTmp);

/* user */      PutField_CString(hRec,"add_user",PD_UPDATE_USER);

/* amount type */
                if (GetField_CString(hContext, "amount_type", &csTmp)) {
                        PutField_CString(hRec,"amount_type",csTmp);
DEBUGLOG(("AddTxnAmtElement:: amount_type = [%s]\n",csTmp));
                } else {
                        PutField_CString(hRec,"amount_type",PD_CR);
                }

                iRet = prbo_AddElements(hRec);
                hash_destroy(hRec);
        }

        FREE_ME(hRec);
DEBUGLOG(("AddTxnAmtElement:: iRet = [%d]\n",iRet));
        return  iRet;
}
