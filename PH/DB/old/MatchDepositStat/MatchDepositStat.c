
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
           char  filnam[20];
};
static struct sqlcxp sqlfpn =
{
    19,
    "MatchDepositStat.pc"
};


static unsigned int sqlctx = 38751371;


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

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,278,0,6,101,0,0,9,9,0,1,0,2,3,0,0,1,9,0,0,1,1,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,1,4,0,0,1,4,0,0,1,4,0,0,
56,0,0,2,119,0,6,158,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,1,1,0,0,
};


/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/09/17              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "MatchDepositStat.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;
void MatchDepositStat(char    cdebug)
{
        cDebug = cdebug;
}

int UpdateStat(const char* csTxnDate,
           const char  cType,
           const char* csPartyId,
           const char* csFromCcy,
           const char* csToCcy,
           double	dFromAmt,
           double	dToAmt,
           double	dExRate)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

    
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short           hv_return_value;

		char		hv_party_type;
		/* varchar		hv_party_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_party_id;

		/* varchar		hv_txn_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_txn_date;

		/* varchar		hv_from_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_from_ccy;

		/* varchar		hv_to_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_to_ccy;

		double		hv_from_amt;
		double		hv_to_amt;
		double		hv_ex_rate;

		short		ind_party_type = -1;
		short		ind_party_id = -1;
		short		ind_txn_date = -1;
		short		ind_from_ccy = -1;
		short		ind_to_ccy = -1;
		short		ind_from_amt= -1;
		short		ind_to_amt= -1;
		short		ind_ex_rate= -1;

    
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_party_type = cType;
DEBUGLOG(("UpdateStat party_type = [%c]\n",hv_party_type));
	ind_party_type = 0;

        hv_party_id.len = strlen(csPartyId);
        memcpy(hv_party_id.arr,csPartyId,hv_party_id.len);
DEBUGLOG(("UpdateStat party_id = [%.*s]\n",hv_party_id.len,hv_party_id.arr));
	ind_party_id = 0;

        hv_txn_date.len = strlen(csTxnDate);
        memcpy(hv_txn_date.arr,csTxnDate,hv_txn_date.len);
DEBUGLOG(("UpdateStat txn_date = [%.*s]\n",hv_txn_date.len,hv_txn_date.arr));
	ind_txn_date = 0;

        hv_from_ccy.len = strlen(csFromCcy);
        memcpy(hv_from_ccy.arr,csFromCcy,hv_from_ccy.len);
DEBUGLOG(("UpdateStat from_ccy = [%.*s]\n",hv_from_ccy.len,hv_from_ccy.arr));
	ind_from_ccy = 0;

        hv_to_ccy.len = strlen(csToCcy);
        memcpy(hv_to_ccy.arr,csToCcy,hv_to_ccy.len);
DEBUGLOG(("UpdateStat to_ccy = [%.*s]\n",hv_to_ccy.len,hv_to_ccy.arr));
	ind_to_ccy = 0;

        hv_from_amt = dFromAmt;
DEBUGLOG(("UpdateStat from_amt = [%lf]\n",hv_from_amt));
	ind_from_amt = 0;

        hv_to_amt = dToAmt;
DEBUGLOG(("UpdateStat to_amt = [%lf]\n",hv_to_amt));
	ind_to_amt = 0;

        hv_ex_rate= dExRate;
DEBUGLOG(("UpdateStat ex_rate = [%lf]\n",hv_ex_rate));
	ind_ex_rate = 0;

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_metch_dsp_stat_update(:hv_txn_date:ind_txn_date,
									:hv_party_type:ind_party_type,
									:hv_party_id:ind_party_id,
									:hv_from_ccy:ind_from_ccy,
									:hv_to_ccy:ind_to_ccy,
									:hv_from_amt:ind_from_amt,
									:hv_to_amt:ind_to_amt,
									:hv_ex_rate:ind_ex_rate);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_metch_dsp_stat_update (\
 :hv_txn_date:ind_txn_date , :hv_party_type:ind_party_type , :hv_party_id:ind\
_party_id , :hv_from_ccy:ind_from_ccy , :hv_to_ccy:ind_to_ccy , :hv_from_amt:\
ind_from_amt , :hv_to_amt:ind_to_amt , :hv_ex_rate:ind_ex_rate ) ; END ;";
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_date;
        sqlstm.sqhstl[1] = (unsigned long )10;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_txn_date;
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
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_from_ccy;
        sqlstm.sqhstl[4] = (unsigned long )5;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_from_ccy;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_to_ccy;
        sqlstm.sqhstl[5] = (unsigned long )5;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_to_ccy;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_from_amt;
        sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_from_amt;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_to_amt;
        sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_to_amt;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_ex_rate;
        sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_ex_rate;
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
        if (sqlca.sqlcode < 0) goto update_error;
}



        if (hv_return_value == 0)  {
DEBUGLOG(("UpdateStat OK\n"));
                return PD_OK;
        }
        else {
DEBUGLOG(("UpdateStat Failed\n"));
                return PD_ERR;
        }


update_error:
ERRLOG("MatchDepositStat::update_error code %d\n", sqlca.sqlcode);
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int ResetStat(const char* csTxnDate,
           const char  cType)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO reset_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

    
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short           hv_return_value;

		char		hv_party_type;
		/* varchar		hv_txn_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_txn_date;


		short		ind_party_type = -1;
		short		ind_txn_date = -1;
    
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_party_type = cType;
DEBUGLOG(("ResetStat party_type = [%c]\n",hv_party_type));
	ind_party_type = 0;

        hv_txn_date.len = strlen(csTxnDate);
        memcpy(hv_txn_date.arr,csTxnDate,hv_txn_date.len);
DEBUGLOG(("ResetStat txn_date = [%.*s]\n",hv_txn_date.len,hv_txn_date.arr));
	ind_txn_date = 0;

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_metch_dsp_stat_reset(:hv_txn_date:ind_txn_date,
								    :hv_party_type:ind_party_type);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_metch_dsp_stat_reset ( \
:hv_txn_date:ind_txn_date , :hv_party_type:ind_party_type ) ; END ;";
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_date;
        sqlstm.sqhstl[1] = (unsigned long )10;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_txn_date;
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
        if (sqlca.sqlcode < 0) goto reset_error;
}



        if (hv_return_value == 0)  {
DEBUGLOG(("ResetStat OK\n"));
                return PD_OK;
        }
        else {
DEBUGLOG(("ResetStat Failed\n"));
                return PD_ERR;
        }


reset_error:
ERRLOG("MatchDepositStat::reset_error code %d\n", sqlca.sqlcode);
DEBUGLOG(("reset_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}
