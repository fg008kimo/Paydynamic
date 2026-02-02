
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
           char  filnam[14];
};
static struct sqlcxp sqlfpn =
{
    13,
    "MmsTxnCode.pc"
};


static unsigned int sqlctx = 642467;


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
   unsigned char  *sqhstv[4];
   unsigned long  sqhstl[4];
            int   sqhsts[4];
            short *sqindv[4];
            int   sqinds[4];
   unsigned long  sqharm[4];
   unsigned long  *sqharc[4];
   unsigned short  sqadto[4];
   unsigned short  sqtdso[4];
} sqlstm = {12,4};

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
5,0,0,1,131,0,4,57,0,0,4,1,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,1,9,0,0,
36,0,0,2,133,0,4,128,0,0,4,2,0,1,0,2,9,0,0,2,9,0,0,1,9,0,0,1,9,0,0,
67,0,0,3,125,0,4,186,0,0,4,2,0,1,0,2,9,0,0,2,9,0,0,1,9,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/11/17              LokMan Chow
Add Find Code by Type				   2011/11/22		   Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "MmsTxnCode.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char    cDebug;

void MmsTxnCode(char    cdebug)
{
        cDebug = cdebug;
}


int FindProcessCode(const unsigned char* TxnCode,
		unsigned char* TxnCodeDesc,
                unsigned char* ProcessType,
                unsigned char* ProcessCode)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO find_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar v_process_type[PD_PROCESS_TYPE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_process_type;

                /* varchar v_process_code[PD_PROCESS_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_process_code;


                /* varchar hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

		/* varchar	v_txn_desc[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_desc;


                short   ind_process_type= -1;
                short   ind_process_code= -1;
		short	ind_txn_desc = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_code.len = strlen((const char*)TxnCode);
        memcpy(hv_txn_code.arr,TxnCode,hv_txn_code.len);
DEBUGLOG(("FindProcessCode: txn_code = [%.*s][%d]\n",hv_txn_code.len,hv_txn_code.arr,hv_txn_code.len)); 


        /* EXEC SQL SELECT mtc_process_code,
			mtc_process_type,
			mtc_desc
                   INTO :v_process_code:ind_process_code,
			:v_process_type:ind_process_type,
			:v_txn_desc:ind_txn_desc
                   FROM mms_txn_code
                  WHERE mtc_code=:hv_txn_code
                 and ROWNUM <= 1; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select mtc_process_code ,mtc_process_type ,mtc_desc \
into :b0:b1,:b2:b3,:b4:b5  from mms_txn_code where (mtc_code=:b6 and ROWNUM<=\
1)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )5;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_process_code;
        sqlstm.sqhstl[0] = (unsigned long )9;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_process_code;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&v_process_type;
        sqlstm.sqhstl[1] = (unsigned long )7;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_process_type;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_desc;
        sqlstm.sqhstl[2] = (unsigned long )53;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_txn_desc;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_code;
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
        if (sqlca.sqlcode < 0) goto find_error;
}



	if (ind_txn_desc >= 0) {
		v_txn_desc.arr[v_txn_desc.len] = '\0';
		strcpy((char*)TxnCodeDesc,(const char*)v_txn_desc.arr);
DEBUGLOG(("Txn Code Desc= [%s]\n",TxnCodeDesc)); 
	}

	if (ind_process_code >= 0) {
		v_process_code.arr[v_process_code.len] = '\0';
		strcpy((char*)ProcessCode,(const char*)v_process_code.arr);
DEBUGLOG(("Process Code = [%s]\n",ProcessCode));
		
		if(ind_process_type >= 0){
			v_process_type.arr[v_process_type.len] = '\0';
			strcpy((char*)ProcessType,(const char*)v_process_type.arr);
DEBUGLOG(("Process Type = [%s]\n",ProcessType));
			
DEBUGLOG(("iRet =  FOUND\n"));
			return FOUND;
		}
	}


DEBUGLOG(("iRet =  NOT FOUND\n"));
        return NOT_FOUND;

find_error:
DEBUGLOG(("find_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return NOT_FOUND;
}


int FindTxnCode(unsigned char* TxnCode,
                unsigned char* TxnCodeDesc,
                const unsigned char* ProcessType,
                const unsigned char* ProcessCode)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO find_txncode_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_process_type[PD_PROCESS_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_process_type;

                /* varchar hv_process_code[PD_PROCESS_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_process_code;


                /* varchar v_txn_code[PD_TXN_CODE_LEN +1 ]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

                /* varchar v_txn_desc[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_desc;


                short   ind_txn_code = -1;
                short   ind_txn_desc = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_process_type.len = strlen((const char*)ProcessType);
        memcpy(hv_process_type.arr,ProcessType,hv_process_type.len);
DEBUGLOG(("FindTxnCode: Process Type = [%.*s][%d]\n",hv_process_type.len,hv_process_type.arr,PD_PROCESS_TYPE_LEN));

        hv_process_code.len = strlen((const char*)ProcessCode);
        memcpy(hv_process_code.arr,ProcessCode,hv_process_code.len);
DEBUGLOG(("FindTxnCode: ProcessCode = [%.*s]\n",hv_process_code.len,hv_process_code.arr));


        /* EXEC SQL SELECT MTC_CODE,MTC_DESC
                   INTO :v_txn_code:ind_txn_code,
                        :v_txn_desc:ind_txn_desc
                FROM MMS_TXN_CODE
                WHERE MTC_PROCESS_TYPE =:hv_process_type and MTC_PROCESS_CODe = :hv_process_code
                 and ROWNUM <= 1; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select MTC_CODE ,MTC_DESC into :b0:b1,:b2:b3  from M\
MS_TXN_CODE where ((MTC_PROCESS_TYPE=:b4 and MTC_PROCESS_CODe=:b5) and ROWNUM\
<=1)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )36;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_code;
        sqlstm.sqhstl[0] = (unsigned long )6;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_txn_code;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_desc;
        sqlstm.sqhstl[1] = (unsigned long )53;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_txn_desc;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_process_type;
        sqlstm.sqhstl[2] = (unsigned long )6;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_process_code;
        sqlstm.sqhstl[3] = (unsigned long )8;
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
        if (sqlca.sqlcode < 0) goto find_txncode_error;
}



        if (ind_txn_code >= 0) {
                v_txn_code.arr[v_txn_code.len] = '\0';
                strcpy((char*)TxnCode,(const char*)v_txn_code.arr);
DEBUGLOG(("Txn Code = [%s]\n",TxnCode));
                if (ind_txn_desc >= 0) {
                        v_txn_desc.arr[v_txn_desc.len] = '\0';
                        strcpy((char*)TxnCodeDesc,(const char*)v_txn_desc.arr);
DEBUGLOG(("Txn Code Desc= [%s]\n",TxnCodeDesc));
                        }
                return FOUND;
        }

DEBUGLOG(("Txn Code  NOT FOUND\n"));
        return NOT_FOUND;
find_txncode_error:
DEBUGLOG(("find_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return NOT_FOUND;
}



int FindTxnCodeByType(unsigned char* TxnCode,
                unsigned char* TxnCodeDesc,
                const char* FromType,
                const char* ToType)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO find_txncodebytype_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_from_type[PD_MMS_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_from_type;

                /* varchar hv_to_type[PD_MMS_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_to_type;


                /* varchar v_txn_code[PD_TXN_CODE_LEN +1 ]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

                /* varchar v_txn_desc[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_desc;


                short   ind_txn_code = -1;
                short   ind_txn_desc = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_from_type.len = strlen((const char*)FromType);
        memcpy(hv_from_type.arr,FromType,hv_from_type.len);
DEBUGLOG(("FindTxnCodeByType:From Type = [%.*s]\n",hv_from_type.len,hv_from_type.arr));

        hv_to_type.len = strlen((const char*)ToType);
        memcpy(hv_to_type.arr,ToType,hv_to_type.len);
DEBUGLOG(("FindTxnCodeByType: ToType = [%.*s]\n",hv_to_type.len,hv_to_type.arr));


        /* EXEC SQL SELECT MTC_CODE,MTC_DESC
                   INTO :v_txn_code:ind_txn_code,
                        :v_txn_desc:ind_txn_desc
                FROM MMS_TXN_CODE
                WHERE MTC_FROM_TYPE =:hv_from_type and MTC_TO_TYPE = :hv_to_type
                 and ROWNUM <= 1; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select MTC_CODE ,MTC_DESC into :b0:b1,:b2:b3  from M\
MS_TXN_CODE where ((MTC_FROM_TYPE=:b4 and MTC_TO_TYPE=:b5) and ROWNUM<=1)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )67;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_code;
        sqlstm.sqhstl[0] = (unsigned long )6;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_txn_code;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_desc;
        sqlstm.sqhstl[1] = (unsigned long )53;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_txn_desc;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_from_type;
        sqlstm.sqhstl[2] = (unsigned long )6;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_to_type;
        sqlstm.sqhstl[3] = (unsigned long )6;
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
        if (sqlca.sqlcode < 0) goto find_txncodebytype_error;
}



        if (ind_txn_code >= 0) {
                v_txn_code.arr[v_txn_code.len] = '\0';
                strcpy((char*)TxnCode,(const char*)v_txn_code.arr);
DEBUGLOG(("FindTxnCodeByType:Txn Code = [%s]\n",TxnCode));
                if (ind_txn_desc >= 0) {
                        v_txn_desc.arr[v_txn_desc.len] = '\0';
                        strcpy((char*)TxnCodeDesc,(const char*)v_txn_desc.arr);
DEBUGLOG(("FindTxnCodeByType:Txn Code Desc= [%s]\n",TxnCodeDesc));
                        }
                return FOUND;
        }

DEBUGLOG(("FindTxnCodeByType:Txn Code  NOT FOUND\n"));
        return NOT_FOUND;
find_txncodebytype_error:
DEBUGLOG(("find_txncodebytype_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return NOT_FOUND;
}

