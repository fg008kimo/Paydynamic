
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
           char  filnam[16];
};
static struct sqlcxp sqlfpn =
{
    15,
    "TxnSupported.pc"
};


static unsigned int sqlctx = 2755211;


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
   unsigned char  *sqhstv[3];
   unsigned long  sqhstl[3];
            int   sqhsts[3];
            short *sqindv[3];
            int   sqinds[3];
   unsigned long  sqharm[3];
   unsigned long  *sqharc[3];
   unsigned short  sqadto[3];
   unsigned short  sqtdso[3];
} sqlstm = {12,3};

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
5,0,0,1,99,0,4,58,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
32,0,0,2,102,0,4,108,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
59,0,0,3,103,0,4,162,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
86,0,0,4,100,0,4,213,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/05/18              Cody Chan
Add IsToMmsHost                                    2011/10/11              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "TxnSupported.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char    cDebug;

void TxnSupported(char    cdebug)
{
        cDebug = cdebug;
}


int FindTxnSupported(const char* csChannelCode,
                        const char* csTxnCode)
{
	
        /* EXEC SQL WHENEVER SQLERROR GOTO find_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_channel_code[PD_CHANNEL_CODE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_channel_code;

		/* varchar	hv_txn_code[PD_TXN_CODE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_txn_code;



		//char    v_support;
		int    v_support;

                short   ind_support = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


	hv_channel_code.len = strlen(csChannelCode);
        memcpy(hv_channel_code.arr,csChannelCode,hv_channel_code.len);
DEBUGLOG(("FindTxnSupported: channel code = [%.*s][%d]\n",hv_channel_code.len,hv_channel_code.arr,hv_channel_code.len)); 

	hv_txn_code.len = strlen(csTxnCode);
        memcpy(hv_txn_code.arr,csTxnCode,hv_txn_code.len);
DEBUGLOG(("FindTxnSupported: txn code = [%.*s][%d]\n",hv_txn_code.len,hv_txn_code.arr,hv_txn_code.len)); 

	/* EXEC SQL select ts_support
                   into :v_support:ind_support
                   from txn_supported
                  Where ts_channel_code = :hv_channel_code
                    And ts_txn_code = :hv_txn_code; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select ts_support into :b0:b1 from txn_supported Where ts_c\
hannel_code = :b2 And ts_txn_code = :b3 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_support;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_support;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_channel_code;
 sqlstm.sqhstl[1] = (unsigned long )6;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_code;
 sqlstm.sqhstl[2] = (unsigned long )6;
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
 if (sqlca.sqlcode < 0) goto find_error;
}



        if (ind_support >= 0) {
DEBUGLOG(("FindTxnSupported: tc_support = %d\n",v_support));
                if (v_support == PD_TRUE)
                        return PD_OK;
                else
                        return PD_ERR;
        }
DEBUGLOG(("FindTxnSupported: txn[%s] not supported\n",csTxnCode));

        return PD_ERR;
find_error:
DEBUGLOG(("find_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}


int IsDoLogging(const char* csChannelCode,
                const char* csTxnCode)
{
	
        /* EXEC SQL WHENEVER SQLERROR GOTO is_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_channel_code[PD_CHANNEL_CODE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_channel_code;

		/* varchar	hv_txn_code[PD_TXN_CODE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_txn_code;



		//char    v_do_logging;
		int    v_do_logging;

                short   ind_do_logging = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


	hv_channel_code.len = strlen(csChannelCode);
        memcpy(hv_channel_code.arr,csChannelCode,hv_channel_code.len);
DEBUGLOG(("IsDoLogging: channel code = [%.*s][%d]\n",hv_channel_code.len,hv_channel_code.arr,hv_channel_code.len)); 

	hv_txn_code.len = strlen(csTxnCode);
        memcpy(hv_txn_code.arr,csTxnCode,hv_txn_code.len);
DEBUGLOG(("IsDoLogging: txn code = [%.*s][%d]\n",hv_txn_code.len,hv_txn_code.arr,hv_txn_code.len)); 

	/* EXEC SQL select ts_do_logging
                   into :v_do_logging:ind_do_logging
                   from txn_supported
                  Where ts_channel_code = :hv_channel_code
                    And ts_txn_code = :hv_txn_code; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select ts_do_logging into :b0:b1 from txn_supported Where t\
s_channel_code = :b2 And ts_txn_code = :b3 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )32;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_do_logging;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_do_logging;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_channel_code;
 sqlstm.sqhstl[1] = (unsigned long )6;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_code;
 sqlstm.sqhstl[2] = (unsigned long )6;
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
 if (sqlca.sqlcode < 0) goto is_error;
}



        if (ind_do_logging >= 0) {
DEBUGLOG(("IsDoLogging: tc_do_logging = %d\n",v_do_logging));
                if (v_do_logging == PD_ADD_LOG)
                        return PD_ADD_LOG;
                else if(v_do_logging == PD_UPDATE_LOG_ONLY)
                        return PD_UPDATE_LOG_ONLY;
		else 
			return PD_NO_LOG;
        }
	else {
DEBUGLOG(("IsDoLogging: dont log\n"));
		return PD_NO_LOG;
	}

is_error:
DEBUGLOG(("is_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}



int IsToMmsHost(const char* csChannelCode,
                const char* csTxnCode)
{
	
        /* EXEC SQL WHENEVER SQLERROR GOTO istomms_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_channel_code[PD_CHANNEL_CODE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_channel_code;

		/* varchar	hv_txn_code[PD_TXN_CODE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_txn_code;


		//char    v_to_mms_host;
		int    v_to_mms_host;

                short   ind_to_mms_host = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


	hv_channel_code.len = strlen(csChannelCode);
        memcpy(hv_channel_code.arr,csChannelCode,hv_channel_code.len);
DEBUGLOG(("IsToMmsHost: channel code = [%.*s][%d]\n",hv_channel_code.len,hv_channel_code.arr,hv_channel_code.len)); 

	hv_txn_code.len = strlen(csTxnCode);
        memcpy(hv_txn_code.arr,csTxnCode,hv_txn_code.len);
DEBUGLOG(("IsToMmsHost: txn code = [%.*s][%d]\n",hv_txn_code.len,hv_txn_code.arr,hv_txn_code.len)); 

	/* EXEC SQL select ts_to_mms_host
                   into :v_to_mms_host:ind_to_mms_host
                   from txn_supported
                  Where ts_channel_code = :hv_channel_code
                    And ts_txn_code = :hv_txn_code; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select ts_to_mms_host into :b0:b1 from txn_supported Where \
ts_channel_code = :b2 And ts_txn_code = :b3 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )59;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_to_mms_host;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_to_mms_host;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_channel_code;
 sqlstm.sqhstl[1] = (unsigned long )6;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_code;
 sqlstm.sqhstl[2] = (unsigned long )6;
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
 if (sqlca.sqlcode < 0) goto istomms_error;
}



        if (ind_to_mms_host >= 0) {
DEBUGLOG(("IsToMmsHost: to_mms_host = %d\n",v_to_mms_host));
                if (v_to_mms_host == PD_TRUE) {
                        return PD_TO_MMS;  
                } else {
                        return PD_NOT_TO_MMS;
                }
        }
	else {
		return PD_NOT_TO_MMS;

        } 
istomms_error:
DEBUGLOG(("istomms_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_NOT_TO_MMS;
}


int IsInitTxn(const char* csChannelCode,
                const char* csTxnCode)
{
	
        /* EXEC SQL WHENEVER SQLERROR GOTO init_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_channel_code[PD_CHANNEL_CODE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_channel_code;

		/* varchar	hv_txn_code[PD_TXN_CODE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_txn_code;


		//char    v_init_txn;
		int    v_init_txn;

                short   ind_init_txn = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


	hv_channel_code.len = strlen(csChannelCode);
        memcpy(hv_channel_code.arr,csChannelCode,hv_channel_code.len);
DEBUGLOG(("IsInitTxn: channel code = [%.*s][%d]\n",hv_channel_code.len,hv_channel_code.arr,hv_channel_code.len)); 

	hv_txn_code.len = strlen(csTxnCode);
        memcpy(hv_txn_code.arr,csTxnCode,hv_txn_code.len);
DEBUGLOG(("IsInitTxn: txn code = [%.*s][%d]\n",hv_txn_code.len,hv_txn_code.arr,hv_txn_code.len)); 

	/* EXEC SQL select ts_init_txn
                   into :v_init_txn:ind_init_txn
                   from txn_supported
                  Where ts_channel_code = :hv_channel_code
                    And ts_txn_code = :hv_txn_code; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select ts_init_txn into :b0:b1 from txn_supported Where ts_\
channel_code = :b2 And ts_txn_code = :b3 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )86;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_init_txn;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_init_txn;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_channel_code;
 sqlstm.sqhstl[1] = (unsigned long )6;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_code;
 sqlstm.sqhstl[2] = (unsigned long )6;
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
 if (sqlca.sqlcode < 0) goto init_error;
}



        if (ind_init_txn >= 0) {
DEBUGLOG(("IsInitTxn: tc_init_txn = %d\n",v_init_txn));
                if (v_init_txn == PD_TRUE)
                        return PD_TRUE;
		else 
			return PD_FALSE;
        }
	else
		return PD_FALSE;

init_error:
DEBUGLOG(("is_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}
