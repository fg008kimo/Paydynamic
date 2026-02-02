
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
           char  filnam[11];
};
static struct sqlcxp sqlfpn =
{
    10,
    "TxnCode.pc"
};


static unsigned int sqlctx = 84387;


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
   unsigned char  *sqhstv[22];
   unsigned long  sqhstl[22];
            int   sqhsts[22];
            short *sqindv[22];
            int   sqinds[22];
   unsigned long  sqharm[22];
   unsigned long  *sqharc[22];
   unsigned short  sqadto[22];
   unsigned short  sqtdso[22];
} sqlstm = {12,22};

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
5,0,0,1,130,0,4,76,0,0,4,2,0,1,0,2,9,0,0,2,9,0,0,1,9,0,0,1,9,0,0,
36,0,0,2,133,0,4,138,0,0,4,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
67,0,0,3,86,0,4,185,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
90,0,0,4,84,0,4,231,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
113,0,0,5,81,0,4,277,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
136,0,0,6,89,0,4,321,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
159,0,0,7,90,0,4,366,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
182,0,0,8,70,0,4,409,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
205,0,0,9,926,0,6,686,0,0,22,22,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,
0,1,3,0,0,1,3,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,9,0,0,
308,0,0,10,180,0,6,816,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,
9,0,0,
347,0,0,11,69,0,6,876,0,0,2,2,0,1,0,2,3,0,0,1,9,0,0,
370,0,0,12,127,0,4,933,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
393,0,0,13,117,0,4,979,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
416,0,0,14,61,0,4,1024,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2010/09/02              Cody Chan
change field type: voidible, apply_limit	   2011/12/14		   LokMan Chow
add new functions Add, Upate, Delete (for Adj)     2012/01/27		   Virginia Yun
Add new field : fe_display			   2012/03/15	           Virginia Yun
split field fe_display to merchant_fe_display
and admin_fe_display				   2012/11/26		   LokMan Chow
add offline display indicators                     2013/11/13              Virginia Yun
add offline additional fields                      2015/01/09              Virginia Yun
add IsOffset, AllowCancel, FindVoidTxnCode	   2015/01/15		   Dirk Wong
add AllowFeInit	   				   2015/01/20		   Elvis Wong
add GetVoidTxnCode				   2015/01/21		   Dirk Wong
add IsVoid					   2015/03/18		   Elvis Wong		
add GetInitPFCodeByDesc				   2015/05/27		   LokMan Chow
add GetAmtTypeByPFInitType			   2015/06/10		   LokMan Chow
add mi_fe_display, mi_ofl_fe_display		   2015/11/05		   Dirk Wong
add GetTxnDesc					   2016/04/13		   Elvis Wong	
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "TxnCode.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char    cDebug;

void TxnCode(char    cdebug)
{
        cDebug = cdebug;
}


int FindTxnCode(unsigned char* TxnCode,
		unsigned char* TxnCodeDesc,
                const unsigned char* ProcessType,
                const unsigned char* ProcessCode)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO find_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_process_type[PD_PROCESS_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_process_type;

                /* varchar hv_process_code[PD_PROCESS_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_process_code;


                /* varchar v_txn_code[PD_TXN_CODE_LEN +1 ]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

		/* varchar	v_txn_desc[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_desc;


                short   ind_txn_code = -1;
		short	ind_txn_desc = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_process_type.len = strlen((const char*)ProcessType);
        memcpy(hv_process_type.arr,ProcessType,hv_process_type.len);
DEBUGLOG(("FindTxnCode: Process Type = [%.*s][%d]\n",hv_process_type.len,hv_process_type.arr,PD_PROCESS_TYPE_LEN)); 

        hv_process_code.len = strlen((const char*)ProcessCode);
        memcpy(hv_process_code.arr,ProcessCode,hv_process_code.len);
DEBUGLOG(("FindTxnCode: ProcessCode = [%.*s]\n",hv_process_code.len,hv_process_code.arr)); 



        /* EXEC SQL SELECT TC_CODE,TC_DESC
                   INTO :v_txn_code:ind_txn_code,
			:v_txn_desc:ind_txn_desc
                FROM TXN_CODE
                WHERE TC_PROCESS_TYPE =:hv_process_type and TC_PROCESS_CODe = :hv_process_code
                 and ROWNUM <= 1; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select TC_CODE , TC_DESC INTO :b0:b1 , :b2:b3 FROM T\
XN_CODE WHERE TC_PROCESS_TYPE = :b4 and TC_PROCESS_CODe = :b5 and ROWNUM <= 1\
 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )5;
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
        if (sqlca.sqlcode < 0) goto find_error;
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
find_error:
DEBUGLOG(("find_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return NOT_FOUND;
}


int IsVoidable(const unsigned char* TxnCode,
		const unsigned char* ProcessType,
		const unsigned char* ProcessCode)
{
	int	iRet = PD_FALSE;
        /* EXEC SQL WHENEVER SQLERROR GOTO is_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

                /* varchar hv_process_type[PD_PROCESS_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_process_type;

                /* varchar hv_process_code[PD_PROCESS_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_process_code;

	
		//char	v_voidable;
		int	v_voidable;

		short	ind_voidable = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_code.len = strlen((const char*)TxnCode);
        memcpy(hv_txn_code.arr,TxnCode,hv_txn_code.len);
DEBUGLOG(("IsVoidable: TxnCode = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr)); 

        hv_process_type.len = strlen((const char*)ProcessType);
        memcpy(hv_process_type.arr,ProcessType,hv_process_type.len);
DEBUGLOG(("IsVoidable: Process Type = [%.*s]\n",hv_process_type.len,hv_process_type.arr)); 

        hv_process_code.len = strlen((const char*)ProcessCode);
        memcpy(hv_process_code.arr,ProcessCode,hv_process_code.len);
DEBUGLOG(("IsVoidable: ProcessCode = [%.*s]\n",hv_process_code.len,hv_process_code.arr)); 


        /* EXEC SQL SELECT TC_VOIDABLE 
                INTO :v_voidable:ind_voidable
                FROM TXN_CODE
                WHERE	TC_PROCESS_TYPE =:hv_process_type
		and	TC_PROCESS_CODE = :hv_process_code
		and	TC_CODE = :hv_txn_code
                and ROWNUM <= 1; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select TC_VOIDABLE INTO :b0:b1 FROM TXN_CODE WHERE T\
C_PROCESS_TYPE = :b2 and TC_PROCESS_CODE = :b3 and TC_CODE = :b4 and ROWNUM <\
= 1 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )36;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_voidable;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_voidable;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_process_type;
        sqlstm.sqhstl[1] = (unsigned long )6;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_process_code;
        sqlstm.sqhstl[2] = (unsigned long )8;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
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
        if (sqlca.sqlcode < 0) goto is_error;
}



        if (ind_voidable >= 0) {
DEBUGLOG(("Voidable = [%d]\n",v_voidable));
		if(v_voidable==PD_TRUE){
			iRet = PD_TRUE;
		}
	}
	else{
DEBUGLOG(("Record Not Found[%s]\n",TxnCode));
	}

DEBUGLOG(("IsVoidable iRet = [%d]\n",iRet));
	return iRet;

is_error:
DEBUGLOG(("is_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}


int IsOffset(const unsigned char* TxnCode)
{
	int	iRet = PD_FALSE;
        /* EXEC SQL WHENEVER SQLERROR GOTO is_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

	
		int	v_offset;
		short	ind_offset = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_code.len = strlen((const char*)TxnCode);
        memcpy(hv_txn_code.arr,TxnCode,hv_txn_code.len);
DEBUGLOG(("IsOffset: TxnCode = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr)); 

        /* EXEC SQL
		SELECT	TC_OFL_IS_OFFSET 
                INTO	:v_offset:ind_offset
                FROM	TXN_CODE
                WHERE	TC_CODE = :hv_txn_code
                and ROWNUM <= 1; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select TC_OFL_IS_OFFSET INTO :b0:b1 FROM TXN_CODE WH\
ERE TC_CODE = :b2 and ROWNUM <= 1 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )67;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_offset;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_offset;
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
        if (sqlca.sqlcode < 0) goto is_error;
}



        if (ind_offset >= 0) {
DEBUGLOG(("offset = [%d]\n",v_offset));
		if(v_offset==PD_TRUE){
			iRet = PD_TRUE;
		}
	}
	else{
DEBUGLOG(("Record Not Found[%s]\n",TxnCode));
	}

DEBUGLOG(("IsOffset iRet = [%d]\n",iRet));
	return iRet;

is_error:
DEBUGLOG(("is_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}


int IsVoid(const unsigned char* TxnCode)
{
        int     iRet = PD_FALSE;
        /* EXEC SQL WHENEVER SQLERROR GOTO is_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;


                int     v_void;
                short   ind_void = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_code.len = strlen((const char*)TxnCode);
        memcpy(hv_txn_code.arr,TxnCode,hv_txn_code.len);
DEBUGLOG(("IsVoid: TxnCode = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));

        /* EXEC SQL
                SELECT  TC_OFL_IS_VOID
                INTO    :v_void:ind_void
                FROM    TXN_CODE
                WHERE   TC_CODE = :hv_txn_code
                and ROWNUM <= 1; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select TC_OFL_IS_VOID INTO :b0:b1 FROM TXN_CODE WHER\
E TC_CODE = :b2 and ROWNUM <= 1 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )90;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_void;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_void;
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
        if (sqlca.sqlcode < 0) goto is_error;
}



        if (ind_void >= 0) {
DEBUGLOG(("IsVoid = [%d]\n",v_void));
                if(v_void==PD_TRUE){
                        iRet = PD_TRUE;
                }
        }
        else{
DEBUGLOG(("Record Not Found[%s]\n",TxnCode));
        }

DEBUGLOG(("IsVoid iRet = [%d]\n",iRet));
        return iRet;

is_error:
DEBUGLOG(("is_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}


int OflIsVoidable(const unsigned char* TxnCode)
{
	int	iRet = PD_FALSE;
        /* EXEC SQL WHENEVER SQLERROR GOTO is_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

	
		int	v_voidable;
		short	ind_voidable = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_code.len = strlen((const char*)TxnCode);
        memcpy(hv_txn_code.arr,TxnCode,hv_txn_code.len);
DEBUGLOG(("IsVoidable: TxnCode = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr)); 

        /* EXEC SQL SELECT TC_VOIDABLE 
                INTO	:v_voidable:ind_voidable
                FROM	TXN_CODE
                WHERE	TC_CODE = :hv_txn_code
                and ROWNUM <= 1; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select TC_VOIDABLE INTO :b0:b1 FROM TXN_CODE WHERE T\
C_CODE = :b2 and ROWNUM <= 1 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )113;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_voidable;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_voidable;
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
        if (sqlca.sqlcode < 0) goto is_error;
}



        if (ind_voidable >= 0) {
DEBUGLOG(("Voidable = [%d]\n",v_voidable));
		if(v_voidable==PD_TRUE){
			iRet = PD_TRUE;
		}
	}
	else{
DEBUGLOG(("Record Not Found[%s]\n",TxnCode));
	}

DEBUGLOG(("IsVoidable iRet = [%d]\n",iRet));
	return iRet;

is_error:
DEBUGLOG(("is_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}


int AllowCancel(const unsigned char* TxnCode)
{
	int	iRet = PD_FALSE;
        /* EXEC SQL WHENEVER SQLERROR GOTO is_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

	
		int	v_allow_cancel;
		short	ind_allow_cancel = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_code.len = strlen((const char*)TxnCode);
        memcpy(hv_txn_code.arr,TxnCode,hv_txn_code.len);
DEBUGLOG(("AllowCancel: TxnCode = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr)); 

                /* EXEC SQL
		SELECT	TC_OFL_ALLOW_CANCEL
                INTO	:v_allow_cancel:ind_allow_cancel
                FROM	TXN_CODE
                WHERE	TC_CODE = :hv_txn_code
                and ROWNUM <= 1; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 4;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "select TC_OFL_ALLOW_CANCEL INTO :b0:b1 FROM \
TXN_CODE WHERE TC_CODE = :b2 and ROWNUM <= 1 ";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )136;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_allow_cancel;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_allow_cancel;
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
                if (sqlca.sqlcode < 0) goto is_error;
}



        if (ind_allow_cancel >= 0) {
DEBUGLOG(("allow_cancel = [%d]\n",v_allow_cancel));
		if(v_allow_cancel==PD_TRUE){
			iRet = PD_TRUE;
		}
	}
	else{
DEBUGLOG(("Record Not Found[%s]\n",TxnCode));
	}

DEBUGLOG(("AllowCancel iRet = [%d]\n",iRet));
	return iRet;

is_error:
DEBUGLOG(("is_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}

int AllowFeInit(const unsigned char* TxnCode)
{
        int     iRet = PD_FALSE;
        /* EXEC SQL WHENEVER SQLERROR GOTO is_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;


                int     v_allow_fe_init;
                short   ind_allow_fe_init = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_code.len = strlen((const char*)TxnCode);
        memcpy(hv_txn_code.arr,TxnCode,hv_txn_code.len);
DEBUGLOG(("AllowFeInit: TxnCode = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));

        /* EXEC SQL
                SELECT  TC_OFL_ALLOW_FE_INIT
                INTO    :v_allow_fe_init:ind_allow_fe_init
                FROM    TXN_CODE
                WHERE   TC_CODE = :hv_txn_code
                and ROWNUM <= 1; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select TC_OFL_ALLOW_FE_INIT INTO :b0:b1 FROM TXN_COD\
E WHERE TC_CODE = :b2 and ROWNUM <= 1 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )159;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_allow_fe_init;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_allow_fe_init;
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
        if (sqlca.sqlcode < 0) goto is_error;
}



        if (ind_allow_fe_init >= 0) {
DEBUGLOG(("allow_fe_init = [%d]\n",v_allow_fe_init));
                if(v_allow_fe_init==PD_TRUE){
                        iRet = PD_TRUE;
                }
        }
        else{
DEBUGLOG(("Record Not Found[%s]\n",TxnCode));
        }

DEBUGLOG(("AllowFeInit iRet = [%d]\n",iRet));
        return iRet;

is_error:
DEBUGLOG(("is_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}

int FindVoidTxnCode(const unsigned char* csTxnCode,unsigned char* csVoidTxnCode)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO find_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;


                /* varchar v_void_txn_code[PD_TXN_CODE_LEN +1 ]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_void_txn_code;

                short   ind_void_txn_code = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_code.len = strlen((const char*)csTxnCode);
        memcpy(hv_txn_code.arr,csTxnCode,hv_txn_code.len);
DEBUGLOG(("FindVoidTxnCode: TxnCode = [%s]\n",hv_txn_code.arr)); 

        /* EXEC SQL SELECT TC_OFL_VOID_CODE
                   INTO :v_void_txn_code:ind_void_txn_code
                FROM TXN_CODE
                WHERE TC_CODE = :hv_txn_code; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select TC_OFL_VOID_CODE INTO :b0:b1 FROM TXN_CODE WH\
ERE TC_CODE = :b2 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )182;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_void_txn_code;
        sqlstm.sqhstl[0] = (unsigned long )6;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_void_txn_code;
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
        if (sqlca.sqlcode < 0) goto find_error;
}



        if (ind_void_txn_code >= 0) {
                v_void_txn_code.arr[v_void_txn_code.len] = '\0';
                strcpy((char*)csVoidTxnCode,(const char*)v_void_txn_code.arr);
DEBUGLOG(("Void Txn Code = [%s]\n",csVoidTxnCode)); 
	
                return FOUND;
        }

DEBUGLOG(("Void Txn Code NOT FOUND\n"));
        return NOT_FOUND;
find_error:
DEBUGLOG(("find_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return NOT_FOUND;
}

int Add(const hash_t *hRls)
{
        char  *csTmp;
        int   iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

                /* varchar         hv_process_type[PD_PROCESS_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_process_type;

                /* varchar         hv_process_code[PD_PROCESS_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_process_code;

                /* varchar         hv_desc[PD_DESC_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_desc;

		int	        hv_voidable;
                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;

		//int		hv_fe_display;
		int		hv_merchant_fe_display;
		int		hv_admin_fe_display;
		int		hv_merchant_txn_display;
		int		hv_psp_txn_display;
		int		hv_mi_fe_display;
		int		hv_ofl_fe_display;
		int		hv_ofl_merchant_fe_display;
		int		hv_ofl_merchant_txn_display;
		int		hv_ofl_provider_txn_display;
		int		hv_mi_ofl_fe_display;
		int		hv_ofl_is_offset;
		/* varchar		hv_ofl_void_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ofl_void_code;

		int		hv_ofl_is_void;
		int		hv_ofl_allow_cancel;
		int		hv_ofl_allow_fe_init;
		

                short           ind_txn_code = -1;
                short           ind_process_type = -1;
                short           ind_process_code = -1;
                short           ind_desc = -1;
                short           ind_voidable = -1;
                short           ind_create_user = -1;
		//short		ind_fe_display = -1;
		short		ind_merchant_fe_display = -1;
		short		ind_admin_fe_display = -1;
		short		ind_merchant_txn_display = -1;
		short		ind_psp_txn_display = -1;
		short		ind_mi_fe_display = -1;
		short		ind_ofl_fe_display = -1;
		short		ind_ofl_merchant_fe_display = -1;
		short		ind_ofl_merchant_txn_display = -1;
		short		ind_ofl_provider_txn_display = -1;
		short		ind_mi_ofl_fe_display = -1;
		short		ind_ofl_is_offset = -1;
		short		ind_ofl_void_code = -1;
		short		ind_ofl_is_void = -1;
		short		ind_ofl_allow_cancel = -1;
		short		ind_ofl_allow_fe_init = -1;

                short           hv_return_value;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

        if(GetField_CString(hRls,"txn_code",&csTmp)) {
                hv_txn_code.len = strlen(csTmp);
                strncpy((char*)hv_txn_code.arr, csTmp, hv_txn_code.len);
                ind_txn_code = 0;
        }
DEBUGLOG(("Add:txn_code = [%.*s]\n",hv_txn_code.len, hv_txn_code.arr));

        if(GetField_CString(hRls,"process_type",&csTmp)) {
                hv_process_type.len = strlen(csTmp);
                strncpy((char*)hv_process_type.arr, csTmp, hv_process_type.len);
                ind_process_type = 0;
        }
DEBUGLOG(("Add:process_type = [%.*s]\n",hv_process_type.len, hv_process_type.arr));

        if(GetField_CString(hRls,"process_code",&csTmp)) {
                hv_process_code.len = strlen(csTmp);
                strncpy((char*)hv_process_code.arr, csTmp, hv_process_code.len);
                ind_process_code = 0;
        }
DEBUGLOG(("Add:process_code = [%.*s]\n",hv_process_code.len, hv_process_code.arr));

        if(GetField_CString(hRls,"desc",&csTmp)) {
                hv_desc.len = strlen(csTmp);
                strncpy((char*)hv_desc.arr, csTmp, hv_desc.len);
                ind_desc = 0;
        }
DEBUGLOG(("Add:desc = [%.*s]\n",hv_desc.len, hv_desc.arr));

/*
        if(GetField_Int(hRls, "apply_fee", &iTmp)) {
                hv_apply_fee = iTmp;
                ind_apply_fee = 0;
        }
DEBUGLOG(("Add:apply_fee = [%d]\n",hv_apply_fee));
*/

        if(GetField_Int(hRls, "voidable", &iTmp)) {
                hv_voidable = iTmp;
                ind_voidable = 0;
        }
DEBUGLOG(("Add:voidable = [%d]\n",hv_voidable));

/*
        if(GetField_Int(hRls, "apply_limit", &iTmp)) {
                hv_apply_limit = iTmp;
                ind_apply_limit = 0;
        }
DEBUGLOG(("Add:apply_limit = [%d]\n",hv_apply_limit));
*/

        if(GetField_CString(hRls,"create_user",&csTmp))
        {
                hv_create_user.len = strlen(csTmp);
                strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
                ind_create_user = 0;
        }
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


        if(GetField_Int(hRls, "fe_display", &iTmp)) {
                hv_admin_fe_display = iTmp;
                ind_admin_fe_display = 0;
DEBUGLOG(("Add:admin_fe_display = [%d]\n",hv_admin_fe_display));
        } else {
                hv_admin_fe_display = PD_TRUE;
                ind_admin_fe_display = 0;
	}


        if(GetField_Int(hRls, "merchant_fe_display", &iTmp)) {
                hv_merchant_fe_display = iTmp;
                ind_merchant_fe_display = 0;
DEBUGLOG(("Add:merchant_fe_display = [%d]\n",hv_merchant_fe_display));
        } else {
                hv_merchant_fe_display = PD_FALSE;
                ind_merchant_fe_display = 0;
	}

	if(GetField_Int(hRls, "merchant_txn_display", &iTmp)) {
                hv_merchant_txn_display = iTmp;
                ind_merchant_txn_display = 0;
DEBUGLOG(("Add:merchant_txn_display = [%d]\n",hv_merchant_txn_display));
        } else {
                hv_merchant_txn_display = PD_FALSE;
                ind_merchant_txn_display = 0;
        }

	if(GetField_Int(hRls, "psp_txn_display", &iTmp)) {
                hv_psp_txn_display = iTmp;
                ind_psp_txn_display = 0;
DEBUGLOG(("Add:psp_txn_display = [%d]\n",hv_psp_txn_display));
        } else {
                hv_psp_txn_display = PD_FALSE;
                ind_psp_txn_display = 0;
        }

	if(GetField_Int(hRls, "mi_fe_display", &iTmp)) {
                hv_mi_fe_display = iTmp;
                ind_mi_fe_display = 0;
DEBUGLOG(("Add:mi_fe_display = [%d]\n",hv_mi_fe_display));
        } else {
                hv_mi_fe_display = PD_FALSE;
                ind_mi_fe_display = 0;
        }

	if(GetField_Int(hRls, "ofl_fe_display", &iTmp)) {
                hv_ofl_fe_display = iTmp;
                ind_ofl_fe_display = 0;
DEBUGLOG(("Add:ofl_fe_display = [%d]\n",hv_ofl_fe_display ));
        } else {
                hv_ofl_fe_display = PD_FALSE;
                ind_ofl_fe_display = 0;
        }

	if(GetField_Int(hRls, "ofl_merchant_fe_display", &iTmp)) {
                hv_ofl_merchant_fe_display = iTmp;
                ind_ofl_merchant_fe_display = 0;
DEBUGLOG(("Add:ofl_merchant_fe_display = [%d]\n",hv_ofl_merchant_fe_display ));
        } else {
                hv_ofl_merchant_fe_display = PD_FALSE;
                ind_ofl_merchant_fe_display = 0;
        }

	if(GetField_Int(hRls, "ofl_merchant_txn_display", &iTmp)) {
                hv_ofl_merchant_txn_display = iTmp;
                ind_ofl_merchant_txn_display = 0;
DEBUGLOG(("Add:ofl_merchant_txn_display = [%d]\n",hv_ofl_merchant_txn_display ));
        } else {
                hv_ofl_merchant_txn_display = PD_FALSE;
                ind_ofl_merchant_txn_display = 0;
        }

	if(GetField_Int(hRls, "ofl_provider_txn_display", &iTmp)) {
                hv_ofl_provider_txn_display = iTmp;
                ind_ofl_provider_txn_display = 0;
DEBUGLOG(("Add:ofl_provider_txn_display = [%d]\n",hv_ofl_provider_txn_display ));
        } else {
                hv_ofl_provider_txn_display = PD_FALSE;
                ind_ofl_provider_txn_display = 0;
        }

	if(GetField_Int(hRls, "mi_ofl_fe_display", &iTmp)) {
                hv_mi_ofl_fe_display = iTmp;
                ind_mi_ofl_fe_display = 0;
DEBUGLOG(("Add:ofl_mi_ofl_fe_display = [%d]\n",hv_mi_ofl_fe_display ));
        } else {
                hv_mi_ofl_fe_display = PD_FALSE;
                ind_mi_ofl_fe_display = 0;
        }

	if(GetField_Int(hRls, "ofl_is_offset", &iTmp)) {
                hv_ofl_is_offset = iTmp;
                ind_ofl_is_offset = 0;
DEBUGLOG(("Add:ofl_is_offset = [%d]\n",hv_ofl_is_offset));
        } else {
                hv_ofl_is_offset = PD_FALSE;
                ind_ofl_is_offset = 0;
        }

        if(GetField_CString(hRls,"ofl_void_code",&csTmp)) {
                hv_ofl_void_code.len = strlen(csTmp);
                strncpy((char*)hv_ofl_void_code.arr, csTmp, hv_ofl_void_code.len);
                ind_ofl_void_code = 0;
DEBUGLOG(("Add: ofl_void_code = [%.*s]\n",hv_ofl_void_code.len, hv_ofl_void_code.arr));
        }

	if(GetField_Int(hRls, "ofl_is_void", &iTmp)) {
                hv_ofl_is_void = iTmp;
                ind_ofl_is_void = 0;
DEBUGLOG(("Add:ofl_is_void = [%d]\n",hv_ofl_is_void));
        } else {
                hv_ofl_is_void = PD_FALSE;
                ind_ofl_is_void = 0;
        }

	if(GetField_Int(hRls, "ofl_allow_cancel", &iTmp)) {
                hv_ofl_allow_cancel = iTmp;
                ind_ofl_allow_cancel = 0;
DEBUGLOG(("Add:ofl_allow_cancel = [%d]\n",hv_ofl_allow_cancel));
        } else {
                hv_ofl_allow_cancel = PD_FALSE;
                ind_ofl_allow_cancel = 0;
        }

	if(GetField_Int(hRls, "ofl_allow_fe_init", &iTmp)) {
                hv_ofl_allow_fe_init = iTmp;
                ind_ofl_allow_fe_init = 0;
DEBUGLOG(("Add:ofl_allow_fe_init = [%d]\n",hv_ofl_allow_fe_init));
        } else {
                hv_ofl_allow_fe_init = PD_FALSE;
                ind_ofl_allow_fe_init = 0;
        }

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_txn_code_insert(
						:hv_txn_code:ind_txn_code,
						:hv_process_type:ind_process_type,
						:hv_process_code:ind_process_code,
						:hv_desc:ind_desc,
						:hv_voidable:ind_voidable,
						:hv_admin_fe_display:ind_admin_fe_display,
						:hv_merchant_fe_display:ind_merchant_fe_display,
						:hv_merchant_txn_display:ind_merchant_txn_display,
						:hv_psp_txn_display:ind_psp_txn_display,
						:hv_mi_fe_display:ind_mi_fe_display,
                                                :hv_ofl_fe_display:ind_ofl_fe_display,
                                                :hv_ofl_merchant_fe_display:ind_ofl_merchant_fe_display,
                                                :hv_ofl_merchant_txn_display:ind_ofl_merchant_txn_display,
                                                :hv_ofl_provider_txn_display:ind_ofl_provider_txn_display,
                                                :hv_mi_ofl_fe_display:ind_mi_ofl_fe_display,
						:hv_ofl_is_offset:ind_ofl_is_offset,
						:hv_ofl_void_code:ind_ofl_void_code,
                                                :hv_ofl_is_void:ind_ofl_is_void,
						:hv_ofl_allow_cancel:ind_ofl_allow_cancel,
						:hv_ofl_allow_fe_init:ind_ofl_allow_fe_init,
                                                :hv_create_user:ind_create_user);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 22;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_txn_code_insert ( :hv_t\
xn_code:ind_txn_code , :hv_process_type:ind_process_type , :hv_process_code:i\
nd_process_code , :hv_desc:ind_desc , :hv_voidable:ind_voidable , :hv_admin_f\
e_display:ind_admin_fe_display , :hv_merchant_fe_display:ind_merchant_fe_disp\
lay , :hv_merchant_txn_display:ind_merchant_txn_display , :hv_psp_txn_display\
:ind_psp_txn_display , :hv_mi_fe_display:ind_mi_fe_display , :hv_ofl_fe_displ\
ay:ind_ofl_fe_display , :hv_ofl_merchant_fe_display:ind_ofl_merchant_fe_displ\
ay , :hv_ofl_merchant_txn_display:ind_ofl_merchant_txn_display , :hv_ofl_prov\
ider_txn_display:ind_ofl_provider_txn_display , :hv_mi_ofl_fe_display:ind_mi_\
ofl_fe_display , :hv_ofl_is_offset:ind_ofl_is_offset , :hv_ofl_void_code:ind_\
ofl_void_code , :hv_ofl_is_void:ind_ofl_is_void , :hv_ofl_allow_cancel:ind_of\
l_allow_cancel , :hv_ofl_allow_fe_init:ind_ofl_allow_fe_init , :hv_create_use\
r:ind_create_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )205;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_code;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_txn_code;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_process_type;
        sqlstm.sqhstl[2] = (unsigned long )6;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_process_type;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_process_code;
        sqlstm.sqhstl[3] = (unsigned long )8;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_process_code;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_desc;
        sqlstm.sqhstl[4] = (unsigned long )52;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_desc;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_voidable;
        sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_voidable;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_admin_fe_display;
        sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_admin_fe_display;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_merchant_fe_display;
        sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_merchant_fe_display;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_merchant_txn_display;
        sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_merchant_txn_display;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_psp_txn_display;
        sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&ind_psp_txn_display;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&hv_mi_fe_display;
        sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)&ind_mi_fe_display;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&hv_ofl_fe_display;
        sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         short *)&ind_ofl_fe_display;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (unsigned char  *)&hv_ofl_merchant_fe_display;
        sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         short *)&ind_ofl_merchant_fe_display;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned long )0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
        sqlstm.sqhstv[13] = (unsigned char  *)&hv_ofl_merchant_txn_display;
        sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[13] = (         int  )0;
        sqlstm.sqindv[13] = (         short *)&ind_ofl_merchant_txn_display;
        sqlstm.sqinds[13] = (         int  )0;
        sqlstm.sqharm[13] = (unsigned long )0;
        sqlstm.sqadto[13] = (unsigned short )0;
        sqlstm.sqtdso[13] = (unsigned short )0;
        sqlstm.sqhstv[14] = (unsigned char  *)&hv_ofl_provider_txn_display;
        sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[14] = (         int  )0;
        sqlstm.sqindv[14] = (         short *)&ind_ofl_provider_txn_display;
        sqlstm.sqinds[14] = (         int  )0;
        sqlstm.sqharm[14] = (unsigned long )0;
        sqlstm.sqadto[14] = (unsigned short )0;
        sqlstm.sqtdso[14] = (unsigned short )0;
        sqlstm.sqhstv[15] = (unsigned char  *)&hv_mi_ofl_fe_display;
        sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[15] = (         int  )0;
        sqlstm.sqindv[15] = (         short *)&ind_mi_ofl_fe_display;
        sqlstm.sqinds[15] = (         int  )0;
        sqlstm.sqharm[15] = (unsigned long )0;
        sqlstm.sqadto[15] = (unsigned short )0;
        sqlstm.sqtdso[15] = (unsigned short )0;
        sqlstm.sqhstv[16] = (unsigned char  *)&hv_ofl_is_offset;
        sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[16] = (         int  )0;
        sqlstm.sqindv[16] = (         short *)&ind_ofl_is_offset;
        sqlstm.sqinds[16] = (         int  )0;
        sqlstm.sqharm[16] = (unsigned long )0;
        sqlstm.sqadto[16] = (unsigned short )0;
        sqlstm.sqtdso[16] = (unsigned short )0;
        sqlstm.sqhstv[17] = (unsigned char  *)&hv_ofl_void_code;
        sqlstm.sqhstl[17] = (unsigned long )5;
        sqlstm.sqhsts[17] = (         int  )0;
        sqlstm.sqindv[17] = (         short *)&ind_ofl_void_code;
        sqlstm.sqinds[17] = (         int  )0;
        sqlstm.sqharm[17] = (unsigned long )0;
        sqlstm.sqadto[17] = (unsigned short )0;
        sqlstm.sqtdso[17] = (unsigned short )0;
        sqlstm.sqhstv[18] = (unsigned char  *)&hv_ofl_is_void;
        sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[18] = (         int  )0;
        sqlstm.sqindv[18] = (         short *)&ind_ofl_is_void;
        sqlstm.sqinds[18] = (         int  )0;
        sqlstm.sqharm[18] = (unsigned long )0;
        sqlstm.sqadto[18] = (unsigned short )0;
        sqlstm.sqtdso[18] = (unsigned short )0;
        sqlstm.sqhstv[19] = (unsigned char  *)&hv_ofl_allow_cancel;
        sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[19] = (         int  )0;
        sqlstm.sqindv[19] = (         short *)&ind_ofl_allow_cancel;
        sqlstm.sqinds[19] = (         int  )0;
        sqlstm.sqharm[19] = (unsigned long )0;
        sqlstm.sqadto[19] = (unsigned short )0;
        sqlstm.sqtdso[19] = (unsigned short )0;
        sqlstm.sqhstv[20] = (unsigned char  *)&hv_ofl_allow_fe_init;
        sqlstm.sqhstl[20] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[20] = (         int  )0;
        sqlstm.sqindv[20] = (         short *)&ind_ofl_allow_fe_init;
        sqlstm.sqinds[20] = (         int  )0;
        sqlstm.sqharm[20] = (unsigned long )0;
        sqlstm.sqadto[20] = (unsigned short )0;
        sqlstm.sqtdso[20] = (unsigned short )0;
        sqlstm.sqhstv[21] = (unsigned char  *)&hv_create_user;
        sqlstm.sqhstl[21] = (unsigned long )22;
        sqlstm.sqhsts[21] = (         int  )0;
        sqlstm.sqindv[21] = (         short *)&ind_create_user;
        sqlstm.sqinds[21] = (         int  )0;
        sqlstm.sqharm[21] = (unsigned long )0;
        sqlstm.sqadto[21] = (unsigned short )0;
        sqlstm.sqtdso[21] = (unsigned short )0;
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
                ERRLOG("TxnCode_Add: SP_OTHER_ERR TxnAbort\n");
                DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
                ERRLOG("TxnCode_Add: SP_ERR TxnAbort\n");
                DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("TxnCode_Add: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_INTERNAL_ERR;

}

int Update(const hash_t *hRls)
{
        char    *csTmp;
	int	iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

                /* varchar         hv_desc[PD_DESC_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_desc;

                /* varchar         hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;

		int	        hv_voidable;
		int		hv_fe_display;

		short		ind_txn_code = -1;
		short		ind_desc = -1;
		short		ind_update_user = -1;
		short		ind_voidable = -1;
		short		ind_fe_display = -1;

                short   	hv_return_value;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update : Begin\n"));

        if (GetField_CString(hRls,"txn_code",&csTmp)) {
                hv_txn_code.len = strlen((const char*)csTmp);
                memcpy(hv_txn_code.arr, csTmp, hv_txn_code.len);

		ind_txn_code = 0;
        }
DEBUGLOG(("Update :txn_code = [%.*s]\n",hv_txn_code.len, hv_txn_code.arr));

        if (GetField_CString(hRls,"desc",&csTmp)) {
                hv_desc.len = strlen((const char*)csTmp);
                memcpy(hv_desc.arr, csTmp, hv_desc.len);

		ind_desc = 0;
        }
DEBUGLOG(("Update :desc = [%.*s]\n",hv_desc.len, hv_desc.arr));


        if(GetField_CString(hRls,"update_user",&csTmp)){
                hv_update_user.len = strlen((const char *)csTmp);
                memcpy(hv_update_user.arr, csTmp, hv_update_user.len);

		ind_update_user = -1;
        }
DEBUGLOG(("Update :update_user = [%.*s]\n",hv_update_user.len, hv_update_user.arr));

/*
	if(GetField_Int(hRls, "apply_fee", &iTmp)) {
                hv_apply_fee = iTmp;
                ind_apply_fee = 0;

DEBUGLOG(("Update : apply_fee = [%d]\n",hv_apply_fee));
	}
*/

	if (GetField_Int(hRls, "voidable", &iTmp)) {
		hv_voidable = iTmp;
		ind_voidable = 0;
DEBUGLOG(("Update : voidable = [%d]\n",hv_voidable));
	}

	if (GetField_Int(hRls, "fe_display", &iTmp)) {
		hv_fe_display = iTmp;
		ind_fe_display = 0;
DEBUGLOG(("Update : fe_display = [%d]\n",hv_fe_display));
	}



       /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_txn_code_update(
                                                :hv_txn_code:ind_txn_code,
                                                :hv_desc:ind_desc,
						:hv_voidable:ind_voidable,
						:hv_fe_display:ind_fe_display,
                                                :hv_update_user);
                END;
        END-EXEC; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 12;
       sqlstm.arrsiz = 22;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.stmt = "begin :hv_return_value := sp_txn_code_update ( :hv_tx\
n_code:ind_txn_code , :hv_desc:ind_desc , :hv_voidable:ind_voidable , :hv_fe_\
display:ind_fe_display , :hv_update_user ) ; END ;";
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )308;
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
       sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_code;
       sqlstm.sqhstl[1] = (unsigned long )5;
       sqlstm.sqhsts[1] = (         int  )0;
       sqlstm.sqindv[1] = (         short *)&ind_txn_code;
       sqlstm.sqinds[1] = (         int  )0;
       sqlstm.sqharm[1] = (unsigned long )0;
       sqlstm.sqadto[1] = (unsigned short )0;
       sqlstm.sqtdso[1] = (unsigned short )0;
       sqlstm.sqhstv[2] = (unsigned char  *)&hv_desc;
       sqlstm.sqhstl[2] = (unsigned long )52;
       sqlstm.sqhsts[2] = (         int  )0;
       sqlstm.sqindv[2] = (         short *)&ind_desc;
       sqlstm.sqinds[2] = (         int  )0;
       sqlstm.sqharm[2] = (unsigned long )0;
       sqlstm.sqadto[2] = (unsigned short )0;
       sqlstm.sqtdso[2] = (unsigned short )0;
       sqlstm.sqhstv[3] = (unsigned char  *)&hv_voidable;
       sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[3] = (         int  )0;
       sqlstm.sqindv[3] = (         short *)&ind_voidable;
       sqlstm.sqinds[3] = (         int  )0;
       sqlstm.sqharm[3] = (unsigned long )0;
       sqlstm.sqadto[3] = (unsigned short )0;
       sqlstm.sqtdso[3] = (unsigned short )0;
       sqlstm.sqhstv[4] = (unsigned char  *)&hv_fe_display;
       sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
       sqlstm.sqhsts[4] = (         int  )0;
       sqlstm.sqindv[4] = (         short *)&ind_fe_display;
       sqlstm.sqinds[4] = (         int  )0;
       sqlstm.sqharm[4] = (unsigned long )0;
       sqlstm.sqadto[4] = (unsigned short )0;
       sqlstm.sqtdso[4] = (unsigned short )0;
       sqlstm.sqhstv[5] = (unsigned char  *)&hv_update_user;
       sqlstm.sqhstl[5] = (unsigned long )22;
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
       if (sqlca.sqlcode < 0) goto update_error;
}




        if (hv_return_value == SP_OK) {
DEBUGLOG(("Update Normal Exit\n"));
                return  PD_OK;
        }

        if (hv_return_value == SP_ERR) {
ERRLOG("TxnCode_Update: SP_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

        if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("TxnCode_Update: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

update_error:
DEBUGLOG(("update_code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("TxnCode_Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
        return PD_INTERNAL_ERR;
}


int Delete (const hash_t *hRls)
{
        char    *csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO delete_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_txn_code[PD_ADJ_TYPE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;


                short   hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Delete: Begin\n"));

        if(GetField_CString(hRls,"txn_code",&csTmp)) {
                hv_txn_code.len = strlen((const char*)csTmp);
                memcpy(hv_txn_code.arr, csTmp, hv_txn_code.len);
        }
DEBUGLOG(("Delete:txn_code = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_txn_code_delete(
                                                :hv_txn_code
                                                );

                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 22;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_txn_code_delete ( :hv_t\
xn_code ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )347;
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
        if (sqlca.sqlcode < 0) goto delete_error;
}




DEBUGLOG(("Delete:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
                DEBUGLOG(("Delete:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
                ERRLOG("TxnCode_Delete: SP_OTHER_ERR TxnAbort\n");
                DEBUGLOG(("Delete: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
                ERRLOG("TxnCode_Delete: SP_ERR TxnAbort\n");
                DEBUGLOG(("Delete: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

delete_error:
DEBUGLOG(("delete_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("TxnCode_Delete: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_INTERNAL_ERR;

}


int GetInitPFCodeByDesc(const unsigned char* TxnDesc, unsigned char* TxnCode)
{
	int	iRet = PD_NOT_FOUND;
        /* EXEC SQL WHENEVER SQLERROR GOTO getcodebydesc_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_desc[PD_DESC_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_desc;

	
                /* varchar v_txn_code[PD_TXN_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

		short	ind_txn_code= -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_desc.len = strlen((const char*)TxnDesc);
        memcpy(hv_desc.arr,TxnDesc,hv_desc.len);
DEBUGLOG(("GetInitPFCodeByDesc: TxnDesc = [%.*s]\n",hv_desc.len,hv_desc.arr)); 

        /* EXEC SQL SELECT tc_code
                INTO	:v_txn_code:ind_txn_code
                FROM	txn_code,ol_pf_txn_init_code
                WHERE	tc_desc = :hv_desc
		and	opic_txn_code = tc_code
                and ROWNUM <= 1; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 22;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select tc_code INTO :b0:b1 FROM txn_code , ol_pf_txn\
_init_code WHERE tc_desc = :b2 and opic_txn_code = tc_code and ROWNUM <= 1 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )370;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_desc;
        sqlstm.sqhstl[1] = (unsigned long )52;
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
        if (sqlca.sqlcode < 0) goto getcodebydesc_error;
}



	if (ind_txn_code>= 0) {
		v_txn_code.arr[v_txn_code.len] = '\0';
		strcpy((char*)TxnCode,(const char*)v_txn_code.arr);
DEBUGLOG(("GetInitPFCodeByDesc = [%.*s]\n",v_txn_code.len,v_txn_code.arr));
		iRet = PD_FOUND;
	}
	else{
DEBUGLOG(("Record Not Found[%s]\n",TxnDesc));
	}

DEBUGLOG(("GetInitPFCodeByDesc iRet = [%d]\n",iRet));
	return iRet;

getcodebydesc_error:
DEBUGLOG(("getcodebydesc_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}


int GetAmtTypeByPFInitType(const unsigned char* TxnDesc, unsigned char* AmtType)
{
	int	iRet = PD_NOT_FOUND;
        /* EXEC SQL WHENEVER SQLERROR GOTO getamttypebydesc_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_desc[PD_DESC_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_desc;

	
                /* varchar v_amt_type[PD_AMT_TYPE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_amt_type;

		short	ind_amt_type = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_desc.len = strlen((const char*)TxnDesc);
        memcpy(hv_desc.arr,TxnDesc,hv_desc.len);
DEBUGLOG(("GetAmtTypeByPFInitType: TxnDesc = [%.*s]\n",hv_desc.len,hv_desc.arr)); 

        /* EXEC SQL SELECT opic_amt_type
                INTO	:v_amt_type:ind_amt_type
                FROM	txn_code,ol_pf_txn_init_code
                WHERE	tc_desc = :hv_desc
		and	opic_txn_code = tc_code; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 22;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select opic_amt_type INTO :b0:b1 FROM txn_code , ol_\
pf_txn_init_code WHERE tc_desc = :b2 and opic_txn_code = tc_code ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )393;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_amt_type;
        sqlstm.sqhstl[0] = (unsigned long )5;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_amt_type;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_desc;
        sqlstm.sqhstl[1] = (unsigned long )52;
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
        if (sqlca.sqlcode < 0) goto getamttypebydesc_error;
}



	if (ind_amt_type>= 0) {
		v_amt_type.arr[v_amt_type.len] = '\0';
		strcpy((char*)AmtType,(const char*)v_amt_type.arr);
DEBUGLOG(("GetAmtTypeByPFInitType = [%.*s]\n",v_amt_type.len,v_amt_type.arr));
		iRet = PD_FOUND;
	}
	else{
DEBUGLOG(("Record Not Found[%s]\n",TxnDesc));
	}

DEBUGLOG(("GetAmtTypeByPFInitType iRet = [%d]\n",iRet));
	return iRet;

getamttypebydesc_error:
DEBUGLOG(("getamttypebydesc_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}

int GetTxnDesc(const unsigned char* TxnCode, unsigned char* TxnDesc)
{
        int     iRet = PD_NOT_FOUND;

        /* EXEC SQL WHENEVER SQLERROR GOTO gettxndesc_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

                
		/* varchar v_desc[PD_DESC_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_desc;

                short   ind_desc = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_code.len = strlen((const char*)TxnCode);
        memcpy(hv_txn_code.arr,TxnCode,hv_txn_code.len);
DEBUGLOG(("GetTxnDesc: TxnCode = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));

        /* EXEC SQL SELECT tc_desc
                INTO    :v_desc:ind_desc
                FROM    txn_code
                WHERE   tc_code = :hv_txn_code; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 22;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select tc_desc INTO :b0:b1 FROM txn_code WHERE tc_co\
de = :b2 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )416;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_desc;
        sqlstm.sqhstl[0] = (unsigned long )53;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_desc;
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
        if (sqlca.sqlcode < 0) goto gettxndesc_error;
}



        if (ind_desc >= 0) {
                v_desc.arr[v_desc.len] = '\0';
                strcpy((char*)TxnDesc,(const char*)v_desc.arr);
DEBUGLOG(("GetTxnDesc: TxnDesc = [%.*s]\n",v_desc.len,v_desc.arr));
                iRet = PD_FOUND;
        }
        else{
DEBUGLOG(("GetTxnDesc: Record Not Found[%s]\n",TxnCode));
        }

DEBUGLOG(("GetTxnDesc iRet = [%d]\n",iRet));
        return iRet;

gettxndesc_error:
DEBUGLOG(("gettxndesc_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}

