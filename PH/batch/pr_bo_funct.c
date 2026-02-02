
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

 static char *sq0008 = 
"select m_total_float ,m_current_bal ,m_total_reserved_amount ,m_total_hold \
,m_settlement_in_transit  from merchant_balance where (((m_merchant_id=:b0 an\
d m_currency_id=:b1) and m_country_id=:b2) and m_service_code=:b3)           ";

 static char *sq0009 = 
"select m_current_bal ,m_total_float ,m_total_hold  from merchant_balance wh\
ere (((m_merchant_id=:b0 and m_currency_id=:b1) and m_country_id=:b2) and m_s\
ervice_code=:b3) for update ";

 static char *sq0019 = 
"select pc_precal_type ,pc_precal_value ,pc_precal_additional_value ,pc_prec\
al_min_value ,pc_precal_max_value ,pc_value_type ,pc_scale  from psp_costs wh\
ere (((pc_effect_date=(select max(pc_effect_date)  from psp_costs where (((pc\
_effect_date<sysdate and pc_psp_id=:b0) and pc_txn_type=:b1) and pc_disabled=\
:b2)) and pc_psp_id=:b0) and pc_txn_type=:b1) and pc_disabled=:b2)           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,77,0,4,41,0,0,1,0,0,1,0,2,9,0,0,
24,0,0,2,89,0,4,71,0,0,1,0,0,1,0,2,9,0,0,
43,0,0,3,110,0,4,99,0,0,1,0,0,1,0,2,9,0,0,
62,0,0,4,94,0,4,130,0,0,1,0,0,1,0,2,9,0,0,
81,0,0,5,241,0,6,717,0,0,8,8,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,
0,0,1,4,0,0,1,9,0,0,
128,0,0,6,223,0,6,733,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
4,0,0,1,9,0,0,
171,0,0,7,241,0,6,835,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
4,0,0,1,9,0,0,
214,0,0,8,229,0,9,939,0,0,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
245,0,0,8,0,0,13,941,0,0,5,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
280,0,0,8,0,0,15,988,0,0,0,0,0,1,0,
295,0,0,8,0,0,15,997,0,0,0,0,0,1,0,
310,0,0,9,180,0,9,1061,0,0,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
341,0,0,9,0,0,13,1063,0,0,3,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,
368,0,0,9,0,0,15,1089,0,0,0,0,0,1,0,
383,0,0,9,0,0,15,1106,0,0,0,0,0,1,0,
398,0,0,10,281,0,6,1181,0,0,8,8,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,4,0,0,1,9,0,0,
445,0,0,11,269,0,6,1291,0,0,8,8,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,2,4,0,0,
492,0,0,12,271,0,6,1410,0,0,8,8,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,3,0,0,1,4,0,0,1,9,0,0,
539,0,0,13,255,0,6,1426,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,3,0,0,1,9,0,0,
582,0,0,14,197,0,6,1534,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,
1,9,0,0,
621,0,0,15,201,0,6,1549,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,
1,9,0,0,
660,0,0,16,196,0,6,1651,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,
1,9,0,0,
699,0,0,17,200,0,6,1666,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,
1,9,0,0,
738,0,0,18,157,0,4,1749,0,0,6,3,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,
777,0,0,19,383,0,9,1976,0,0,6,6,0,1,0,1,9,0,0,1,1,0,0,1,3,0,0,1,9,0,0,1,1,0,0,
1,3,0,0,
816,0,0,19,0,0,13,1978,0,0,7,0,0,1,0,2,1,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,
1,0,0,2,3,0,0,
859,0,0,19,0,0,15,2044,0,0,0,0,0,1,0,
874,0,0,19,0,0,15,2055,0,0,0,0,0,1,0,
889,0,0,20,276,0,6,2411,0,0,9,9,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,1,0,0,1,4,0,0,
1,9,0,0,1,9,0,0,1,4,0,0,1,9,0,0,
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
#include "batchcommon.h"
#include "pr_bo_funct.h"

char	cDebug;
#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


///////////////////////////////////////////////
//////////////////Txn Seq//////////////////////
char* GetNextTxnSeq()
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

char* GetNextBatchTxnSeq()
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

char* GetNextMgtTxnSeq()
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


char* GetNextPayoutTxnSeq()
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
int UpdatePayoutAmount(hash_t* hContext)
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
        if (GetField_CString(hContext,"org_psp_id",&csOrgPspId)) {
DEBUGLOG(("UpdatePayoutAmount() org_psp_id = [%s]\n",csOrgPspId));
        }
        else {
                if(cParty==PD_TYPE_MERCHANT){
                        csOrgPspId = strdup("NA");
                }
                else{
DEBUGLOG(("UpdatePayoutAmount() org_psp_id is missing!!!\n"));
                }
        }

/*org psp ccy */
        if (GetField_CString(hContext,"org_psp_txn_ccy",&csOrgDstCcy)) {
DEBUGLOG(("UpdatePayoutAmount() org_psp_txn_ccy = [%s]\n",csOrgDstCcy));
        }
        else {
DEBUGLOG(("UpdatePayoutAmount() org_psp_txn_ccy is missing!!!\n"));
        }

/*org psp txn amount */
        if (GetField_Double(hContext,"org_dst_net_amt",&dOrgDstTxnAmt)) {
DEBUGLOG(("UpdatePayoutAmount() org_dst_net_amt = [%lf]\n",dOrgDstTxnAmt));
        }
        else {
DEBUGLOG(("UpdatePayoutAmount() org_dst_net_amt is missing!!!\n"));
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
                iRet = PayoutSuccess(hContext,
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
                iRet = PayoutVoided(hContext,
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

        if(cParty!=PD_TYPE_PSP){
                hVal = (hash_t*) malloc (sizeof(hash_t));
                hash_init(hVal,0);

                if(GetCurrentValues(csOrgMerchantId,csOrgTxnCcy,csOrgTxnCountry,csOrgServiceCode,hVal)!=PD_ERR){
                        if(GetField_Double(hVal,"current_bal",&dTmp)){
                                PutField_Double(hContext,"current_bal",dTmp);
DEBUGLOG((" current_bal= [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"total_float",&dTmp)){
                                PutField_Double(hContext,"total_float",dTmp);
DEBUGLOG((" total_float= [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"total_reserved_amount",&dTmp)){
                                PutField_Double(hContext,"total_reserved_amount",dTmp);
DEBUGLOG((" total_reserved_amount= [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"total_hold",&dTmp)){
                                PutField_Double(hContext,"total_hold",dTmp);
DEBUGLOG((" total_hold= [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"settlement_in_transit",&dTmp)){
                                PutField_Double(hContext,"settlement_in_transit",dTmp);
DEBUGLOG((" settlement_in_transit= [%f]\n",dTmp));
                        }
                }

                FREE_ME(hVal);

                if(cParty==PD_TYPE_MERCHANT)
                        FREE_ME(csOrgPspId);
        }

        if(cParty!=PD_TYPE_MERCHANT){

                hVal = (hash_t*) malloc (sizeof(hash_t));
                hash_init(hVal,0);

                if(GetBalance(csOrgPspId,csOrgTxnCountry,csOrgDstCcy,hVal)!=PD_ERR){
                        if(GetField_Double(hVal,"balance",&dTmp)){
                                PutField_Double(hContext,"psp_balance",dTmp);
DEBUGLOG(("psp_balance = [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"total_float",&dTmp)){
                                PutField_Double(hContext,"psp_total_float",dTmp);
DEBUGLOG(("psp_total_float = [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"total_hold",&dTmp)){
                                PutField_Double(hContext,"psp_total_hold",dTmp);
DEBUGLOG(("psp_total_hold = [%f]\n",dTmp));
                        }
                }

                FREE_ME(hVal);
        }

        return iRet;

}

int PayoutSuccess(hash_t* hContext,
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

DEBUGLOG(("PayoutSuccess()\n"));
DEBUGLOG(("PayoutSuccess() merchant = [%lf], psp = [%lf]\n",dNetAmount,dPspAmount));


        if (cParty==PD_TYPE_MERCHANT || cParty==PD_TYPE_GLOBAL) {
                if (UpdateAvalBal(hContext,
                                csMerchantID,
                                csCountry,
                                csMerchantCCY,
                                csServiceCode,
                                -dNetAmount,
                                PD_UPDATE_USER) != PD_OK) {
                        iRet = INT_ERR;
DEBUGLOG(("PayoutSuccess::UpdateAvalBal()  Failed\n"));
                }

                if (UpdateReserved(csMerchantID,
                                csCountry,
                                csMerchantCCY,
                                csServiceCode,
                                iDayOfWeek,
                                -dNetAmount,
                                PD_UPDATE_USER) != PD_OK) {
                        iRet = INT_ERR;
DEBUGLOG(("PayoutSuccess::UpdateReserved()  Failed\n"));
                }

        }


        if (cParty==PD_TYPE_PSP || cParty==PD_TYPE_GLOBAL) {
DEBUGLOG(("PayoutSuccess DebitPSP AvalBalance\n"));
                if (DebitBalance(csPspID,
                                csCountry,
                                csPspCCY,
                                PD_PSP_BAL,
                                dPspAmount,
                                PD_UPDATE_USER) != PD_OK) {
                        iRet = INT_ERR;
DEBUGLOG(("PayoutSuccess() DebitBalance Failed\n"));
                }
        }


DEBUGLOG(("PayoutSuccess() iRet = [%d]\n",iRet));
        return iRet;
}


int PayoutVoided(hash_t* hContext,
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

DEBUGLOG(("PayoutVoided()\n"));
DEBUGLOG(("PayoutVoided() merchant = [%lf], psp = [%lf]\n",dNetAmount,dPspAmount));


        if (cParty==PD_TYPE_MERCHANT || cParty==PD_TYPE_GLOBAL) {
                if (UpdateAvalBal(hContext,
                                csMerchantID,
                                csCountry,
                                csMerchantCCY,
                                csServiceCode,
                                dNetAmount,
                                PD_UPDATE_USER) != PD_OK) {
                        iRet = INT_ERR;
DEBUGLOG(("PayoutVoided::UpdateAvalBal() Failed\n"));
                }

                if (UpdateReserved(csMerchantID,
                                csCountry,
                                csMerchantCCY,
                                csServiceCode,
                                iDayOfWeek,
                                dNetAmount,
                                PD_UPDATE_USER) != PD_OK) {
                        iRet = INT_ERR;
DEBUGLOG(("PayoutVoided::UpdateReserved()  Failed\n"));
                }
        }

        if (cParty==PD_TYPE_PSP || cParty==PD_TYPE_GLOBAL) {
DEBUGLOG(("PayoutVoided CreditPSP AvalBalance\n"));
                if (CreditBalance(csPspID,
                                csCountry,
                                csPspCCY,
                                PD_PSP_BAL,
                                dPspAmount,
                                PD_UPDATE_USER) != PD_OK) {
                        iRet = INT_ERR;
DEBUGLOG(("PayoutVoided::CreditBalance() Failed\n"));
                }
        }

DEBUGLOG(("PayoutVoided() iRet = [%d]\n",iRet));
        return iRet;
}




////////////////////////////////////////////////
////////////////////Settlement//////////////////


int UpdateSettlementAmount(hash_t *hContext)
{
        int     iRet = PD_OK;
        char    *csTxnCode;
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

DEBUGLOG(("UpdateSettlementAmount() Update Avi Settlement Balance\n"));

        if(!strcmp(csTxnCode,PD_SETTLEMENT_REQUEST)){
                iRet = PD_OK;
        }

        else if(!strcmp(csTxnCode,PD_SETTLEMENT_CANCEL)){
                iRet = PD_OK;
        }
        else if(!strcmp(csTxnCode,PD_SETTLEMENT_APPROVAL)){
DEBUGLOG(("UpdateSettlementAmount() Call Settlement2InTransit[%c]\n",PD_S2I));
                iRet = Settlement2InTransit(csOrgMerchantId,
                                            csOrgTxnCountry,
					    csOrgTxnCcy,
					    csOrgServiceCode,
					    dOrgNetAmt,
					    dFee,
					    PD_S2I,
					    PD_UPDATE_USER);

        }

        else if(!strcmp(csTxnCode,PD_SETTLEMENT_DELIVERY)){
DEBUGLOG(("UpdateSettlementAmount() Call UpdateIntransit\n"));
		iRet = UpdateIntransit(csOrgMerchantId,
				       csOrgTxnCountry,
				       csOrgTxnCcy,
				       csOrgServiceCode,
				       (dOrgNetAmt)*(-1),
				       PD_UPDATE_USER);

        }


        else {
DEBUGLOG(("UpdateSettlementAmount() None Settlement txn\n"));
                return iRet;
        }

	hVal = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hVal,0);

DEBUGLOG(("UpdateSettlementAmount() Call GetCurrentValues\n"));
	if(GetCurrentValues(csOrgMerchantId,csOrgTxnCcy,csOrgTxnCountry,csOrgServiceCode,hVal)!=PD_ERR){
		if(GetField_Double(hVal,"current_bal",&dTmp)){
			PutField_Double(hContext,"current_bal",dTmp);
DEBUGLOG(("UpdateSettlementAmount()  current_bal= [%f]\n",dTmp));
		}
		if(GetField_Double(hVal,"total_float",&dTmp)){
			PutField_Double(hContext,"total_float",dTmp);
DEBUGLOG(("UpdateSettlementAmount()  total_float= [%f]\n",dTmp));
		}
		if(GetField_Double(hVal,"total_reserved_amount",&dTmp)){
			PutField_Double(hContext,"total_reserved_amount",dTmp);
DEBUGLOG(("UpdateSettlementAmount()  total_reserved_amount= [%f]\n",dTmp));
		}
		if(GetField_Double(hVal,"total_hold",&dTmp)){
			PutField_Double(hContext,"total_hold",dTmp);
DEBUGLOG(("UpdateSettlementAmount()  total_hold= [%f]\n",dTmp));
		}
		if(GetField_Double(hVal,"settlement_in_transit",&dTmp)){
			PutField_Double(hContext,"settlement_in_transit",dTmp);
DEBUGLOG(("UpdateSettlementAmount()  settlement_in_transit= [%f]\n",dTmp));
		}
	}

	FREE_ME(hVal);

DEBUGLOG(("iRet=[%d]\n",iRet));
        return iRet;
}


int Settlement2InTransit(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
                double  dFee,
                char    cDirection,
                const char* csUser)
{

        /* EXEC SQL WHENEVER SQLERROR GOTO s2i_error; */ 

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
                double          hv_fee;
                /* varchar         hv_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_user;



                short           ind_merchant_id = -1;
                short           ind_country_id = -1;
                short           ind_ccy_id = -1;
                short           ind_service_code = -1;
                short           ind_amt = -1;
                short           ind_fee = -1;
                short           ind_user = -1;

                short           hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("Settlement2InTransit: Begin\n"));

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

        hv_amt= dAmt;
        ind_amt= 0;
DEBUGLOG(("Settlement2InTransit:amt = [%f]\n",hv_amt));
DEBUGLOG(("Settlement2InTransit:direction => [%c]\n",cDirection));

        hv_fee= dFee;
        ind_fee= 0;
DEBUGLOG(("Settlement2InTransit:fee = [%f]\n",hv_fee));

        hv_user.len = strlen(csUser);
        strncpy((char *)hv_user.arr, csUser, hv_user.len);
        ind_user = 0;

        if(cDirection==PD_S2I){

                /* EXEC SQL EXECUTE
                   BEGIN

                        :hv_return_value := sp_merchant_balance_s2i(
                                :hv_merchant_id:ind_merchant_id,
                                :hv_country_id:ind_country_id,
                                :hv_ccy_id:ind_ccy_id,
                                :hv_service_code:ind_service_code,
                                :hv_amt:ind_amt,
                                :hv_fee:ind_fee,
                                :hv_user:ind_user);

                   END;
                END-EXEC; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 8;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "begin :hv_return_value := sp_merchant_balanc\
e_s2i ( :hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv\
_ccy_id:ind_ccy_id , :hv_service_code:ind_service_code , :hv_amt:ind_amt , :h\
v_fee:ind_fee , :hv_user:ind_user ) ; END ;";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )81;
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
                sqlstm.sqhstv[6] = (unsigned char  *)&hv_fee;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_fee;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&hv_user;
                sqlstm.sqhstl[7] = (unsigned long )22;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_user;
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
                if (sqlca.sqlcode < 0) goto s2i_error;
}


        }
        else{
                /* EXEC SQL EXECUTE
                   BEGIN

                        :hv_return_value := sp_merchant_balance_i2s(
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
                sqlstm.arrsiz = 8;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "begin :hv_return_value := sp_merchant_balanc\
e_i2s ( :hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv\
_ccy_id:ind_ccy_id , :hv_service_code:ind_service_code , :hv_amt:ind_amt , :h\
v_user:ind_user ) ; END ;";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )128;
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
                if (sqlca.sqlcode < 0) goto s2i_error;
}


        }
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("Settlement2InTransit:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("pr_bo_funct::Settlement2InTransit: SP_OTHER_ERR \n");
DEBUGLOG(("Settlement2InTransit: SP_OTHER_ERR \n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("pr_bo_funct::Settlement2InTransit: SP_ERR \n");
DEBUGLOG(("Settlement2InTransit: SP_ERR \n"));
                return PD_ERR;
        }
s2i_error:
DEBUGLOG(("s2i_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;


}

int UpdateIntransit(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dAmt,
                const char* csUser)

{

        /* EXEC SQL WHENEVER SQLERROR GOTO updateintransit_error; */ 

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



                short           ind_merchant_id = -1;
                short           ind_country_id = -1;
                short           ind_ccy_id = -1;
                short           ind_service_code = -1;
                short           ind_amt = -1;
                short           ind_create_user = -1;

                short           hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateIntransit: Begin\n"));

        hv_merchant_id.len = strlen(csMerchantId);
        strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
        ind_merchant_id = 0;
DEBUGLOG(("UpdateIntransit:merchant id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

        hv_country_id.len = strlen(csCountryId);
        strncpy((char *)hv_country_id.arr, csCountryId, hv_country_id.len);
        ind_country_id = 0;
DEBUGLOG(("UpdateIntransit:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

        hv_ccy_id.len = strlen(csCcy);
        strncpy((char *)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
        ind_ccy_id = 0;
DEBUGLOG(("UpdateIntransit:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

        hv_service_code.len = strlen(csServiceCode);
        strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
        ind_service_code = 0;
DEBUGLOG(("UpdateIntransit:ccy_id = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

        hv_amt= dAmt;
        ind_amt= 0;
DEBUGLOG(("UpdateIntransit:amt = [%f]\n",hv_amt));

        hv_create_user.len = strlen(csUser);
        strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
        ind_create_user = 0;
DEBUGLOG(("UpdateIntransit:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));

        /* EXEC SQL EXECUTE
            BEGIN

                :hv_return_value := sp_merch_balance_update_int(
                                :hv_merchant_id:ind_merchant_id,
                                :hv_country_id:ind_country_id,
                                :hv_ccy_id:ind_ccy_id,
                                :hv_service_code:ind_service_code,
                                :hv_amt:ind_amt,
                                :hv_create_user:ind_create_user);

            END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_merch_balance_update_in\
t ( :hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_ccy\
_id:ind_ccy_id , :hv_service_code:ind_service_code , :hv_amt:ind_amt , :hv_cr\
eate_user:ind_create_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )171;
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
        if (sqlca.sqlcode < 0) goto updateintransit_error;
}




DEBUGLOG(("UpdateIntransit:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("UpdateIntransit:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("pr_bo_funct::UpdateIntransit: SP_OTHER_ERR \n");
DEBUGLOG(("UpdateIntransit: SP_OTHER_ERR \n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("pr_bo_funct::UpdateIntransit: SP_ERR \n");
DEBUGLOG(("UpdateIntransit: SP_ERR \n"));
                return PD_ERR;
        }

updateintransit_error:
DEBUGLOG(("updateintransit_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


//////////////////////////////////////////////////////////////
////////////////////////Merchant Balance//////////////////////

int GetCurrentValues(const char* csMerchantID,
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
                double          v_settlement_in_transit;

                short           ind_total_float = -1;
                short           ind_current_bal= -1;
                short           ind_total_reserved_amount= -1;
                short           ind_total_hold= -1;
                short           ind_settlement_in_transit= -1;

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
                        m_settlement_in_transit
                  from  merchant_balance
                 where  m_merchant_id = :hv_merchant_id
                   and  m_currency_id = :hv_ccy_id
                   and  m_country_id = :hv_country_id
                   and  m_service_code = :hv_service_code; */ 


        /* EXEC SQL OPEN c_cursor_getcurrval; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0008;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )214;
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
                        :v_settlement_in_transit:ind_settlement_in_transit; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 8;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )245;
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
                sqlstm.sqhstv[4] = (unsigned char  *)&v_settlement_in_transit;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_settlement_in_transit;
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

//settlement_in_transit
                if(ind_settlement_in_transit<0)
                        v_settlement_in_transit= 0;
                PutField_Double(hVal,"settlement_in_transit",v_settlement_in_transit);
DEBUGLOG(("GetCurrentValues settlement_in_transit = [%f]\n",v_settlement_in_transit));

        }

        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getcurrval; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )280;
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
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )295;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int GetOpenBalanceForUpdate(hash_t* hContext,
                const char* csMerchantID,
                const char* csCurrencyId,
                const char* csCountryId,
                const char* csServiceCode)
{
        int iRet = PD_OK;
        double dBal = 0.0;
        double dFloat = 0.0;
        double dHold = 0.0;

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

                short           ind_current_bal= -1;
                short           ind_total_float= -1;
                short           ind_total_hold= -1;


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
                        m_total_hold
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
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0009;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )310;
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
                        :v_total_hold:ind_total_hold; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 8;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )341;
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

                dBal = v_current_bal;
                dFloat = v_total_float;
                dHold = v_total_hold;
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getopenbalforupdate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )368;
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
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )383;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}



int UpdateFloat(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                double  dCurrentAmt,
                double  dFloat,
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

                double          hv_current_amt;
                double          hv_float;
                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



                short           ind_merchant_id = -1;
                short           ind_country_id = -1;
                short           ind_ccy_id = -1;
                short           ind_service_code = -1;
                short           ind_current_amt = -1;
                short           ind_float = -1;
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

        hv_current_amt= dCurrentAmt;
        ind_current_amt= 0;
DEBUGLOG(("UpdatFloat:current_amt = [%f]\n",hv_current_amt));

        hv_float= dFloat;
        ind_float= 0;
DEBUGLOG(("UpdatFloat:float = [%f]\n",hv_float));

        hv_create_user.len = strlen(csUser);
        strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
        ind_create_user = 0;
DEBUGLOG(("UpdateFloat:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));

        /* EXEC SQL EXECUTE
            BEGIN

                :hv_return_value := sp_merchant_balance_insert_fl(
                                :hv_merchant_id:ind_merchant_id,
                                :hv_country_id:ind_country_id,
                                :hv_ccy_id:ind_ccy_id,
                                :hv_service_code:ind_service_code,
                                :hv_current_amt:ind_current_amt,
                                :hv_float:ind_float,
                                :hv_create_user:ind_create_user);

            END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_merchant_balance_insert\
_fl ( :hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_c\
cy_id:ind_ccy_id , :hv_service_code:ind_service_code , :hv_current_amt:ind_cu\
rrent_amt , :hv_float:ind_float , :hv_create_user:ind_create_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )398;
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
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_current_amt;
        sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_current_amt;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_float;
        sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_float;
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

int UpdateAvalBal(hash_t* hContext,
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
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_merch_balance_update_av\
al ( :hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv_cc\
y_id:ind_ccy_id , :hv_service_code:ind_service_code , :hv_amt:ind_amt , :hv_c\
reate_user:ind_create_user , :v_open_bal:ind_open_bal ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )445;
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



int UpdateReserved(const char* csMerchantId,
                const char* csCountryId,
                const char* csCcy,
                const char* csServiceCode,
                const int iDayOfWeek,
                double  dAmt,
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

                int             hv_day_of_week;
                double          hv_amt;
                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



                short           ind_merchant_id = -1;
                short           ind_country_id = -1;
                short           ind_ccy_id = -1;
                short           ind_service_code = -1;
                short           ind_day_of_week = -1;
                short           ind_amt = -1;
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

        hv_day_of_week= iDayOfWeek;
        ind_day_of_week= 0;
DEBUGLOG(("UpdatReserved:day_of_week = [%d]\n",hv_day_of_week));

        hv_amt= dAmt;
        ind_amt= 0;
DEBUGLOG(("UpdatReserved:reserved amt = [%f]\n",hv_amt));

        hv_create_user.len = strlen(csUser);
        strncpy((char *)hv_create_user.arr, csUser, hv_create_user.len);
        ind_create_user = 0;
DEBUGLOG(("UpdateReserved:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));

        if(dAmt!=0.0){
                /* EXEC SQL EXECUTE
                    BEGIN

                        :hv_return_value := sp_merchant_res_amt_add(
                                :hv_merchant_id:ind_merchant_id,
                                :hv_country_id:ind_country_id,
                                :hv_ccy_id:ind_ccy_id,
                                :hv_service_code:ind_service_code,
                                :hv_day_of_week:ind_day_of_week,
                                :hv_amt:ind_amt,
                                :hv_create_user:ind_create_user);

                    END;
                END-EXEC; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 8;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "begin :hv_return_value := sp_merchant_res_am\
t_add ( :hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :hv\
_ccy_id:ind_ccy_id , :hv_service_code:ind_service_code , :hv_day_of_week:ind_\
day_of_week , :hv_amt:ind_amt , :hv_create_user:ind_create_user ) ; END ;";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )492;
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
                sqlstm.sqhstv[5] = (unsigned char  *)&hv_day_of_week;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_day_of_week;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&hv_amt;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_amt;
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
                if (sqlca.sqlcode < 0) goto updatereserved_error;
}


        }
        else{
                /* EXEC SQL EXECUTE
                    BEGIN

                        :hv_return_value := sp_merchant_res_amt_reset(
                                :hv_merchant_id:ind_merchant_id,
                                :hv_country_id:ind_country_id,
                                :hv_ccy_id:ind_ccy_id,
                                :hv_service_code:ind_service_code,
                                :hv_day_of_week:ind_day_of_week,
                                :hv_create_user:ind_create_user);

                    END;
                END-EXEC; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 8;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "begin :hv_return_value := sp_merchant_res_am\
t_reset ( :hv_merchant_id:ind_merchant_id , :hv_country_id:ind_country_id , :\
hv_ccy_id:ind_ccy_id , :hv_service_code:ind_service_code , :hv_day_of_week:in\
d_day_of_week , :hv_create_user:ind_create_user ) ; END ;";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )539;
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
                sqlstm.sqhstv[5] = (unsigned char  *)&hv_day_of_week;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_day_of_week;
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




//////////////////////////////////////////////////////////////////////////////
///////////////////////////////////Psp Balance////////////////////////////////

int CreditBalance(const char* csPsp,
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
                sqlstm.arrsiz = 8;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "begin :hv_return_value := sp_psp_balance_cre\
dit ( :hv_psp_id:ind_psp_id , :hv_country_id:ind_country_id , :hv_ccy_id:ind_\
ccy_id , :hv_balance:ind_balance , :hv_create_user:ind_create_user ) ; END ;";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )582;
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
                sqlstm.arrsiz = 8;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "begin :hv_return_value := sp_psp_balance_cre\
dit_bal ( :hv_psp_id:ind_psp_id , :hv_country_id:ind_country_id , :hv_ccy_id:\
ind_ccy_id , :hv_balance:ind_balance , :hv_create_user:ind_create_user ) ; EN\
D ;";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )621;
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

int DebitBalance(const char* csPsp,
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
                sqlstm.arrsiz = 8;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "begin :hv_return_value := sp_psp_balance_deb\
it ( :hv_psp_id:ind_psp_id , :hv_country_id:ind_country_id , :hv_ccy_id:ind_c\
cy_id , :hv_balance:ind_balance , :hv_create_user:ind_create_user ) ; END ;";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )660;
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
                sqlstm.arrsiz = 8;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "begin :hv_return_value := sp_psp_balance_deb\
it_bal ( :hv_psp_id:ind_psp_id , :hv_country_id:ind_country_id , :hv_ccy_id:i\
nd_ccy_id , :hv_balance:ind_balance , :hv_create_user:ind_create_user ) ; END\
 ;";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )699;
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



int GetBalance(const char* csPspID,
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
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select pb_bal ,pb_total_float ,pb_total_hold into :b\
0:b1,:b2:b3,:b4:b5  from psp_balance where ((pb_psp_id=:b6 and pb_country_id=\
:b7) and pb_currency_id=:b8)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )738;
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


int CalPspCosts(hash_t *hContext,
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

        if (GetPspCosts(csOrgPspId, cType, rRecordSet)==PD_FOUND) {
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


int GetPspCosts(const char* csPspId,
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
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0019;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )777;
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
                sqlstm.arrsiz = 8;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )816;
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
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )859;
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
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )874;
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

int     AddTxnAmtElement(hash_t* hContext)
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

                iRet = AddElements(hRec);
                hash_destroy(hRec);
        }

        FREE_ME(hRec);
DEBUGLOG(("AddTxnAmtElement:: iRet = [%d]\n",iRet));
        return  iRet;
}

int     AddTxnFeeElements(hash_t* hContext)
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

                        iRet = AddElements(hRec);
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

                        iRet = AddElements(hRec);
                        hash_destroy(hRec);
                }
        }


        FREE_ME(hRec);
DEBUGLOG(("AddFeeTxnChgLog:: iRet = [%d]\n",iRet));
        return  iRet;
}

int     AddMarkupAmtElement(hash_t* hContext)
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

                iRet = AddElements(hRec);
                hash_destroy(hRec);
        }

        FREE_ME(hRec);
DEBUGLOG(("AddMarkupAmtElement:: iRet = [%d]\n",iRet));
        return  iRet;
}

int AddElements(const hash_t *hRls)
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
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_txn_elements_insert ( :\
hv_txn_id:ind_txn_id , :hv_txn_element_type:ind_txn_element_type , :hv_party_\
type:ind_party_type , :hv_amount:ind_amount , :hv_ccy:ind_ccy , :hv_amt_type:\
ind_amt_type , :hv_rate:ind_rate , :hv_add_user:ind_add_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )889;
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
