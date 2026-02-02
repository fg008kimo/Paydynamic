
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
           char  filnam[27];
};
static struct sqlcxp sqlfpn =
{
    26,
    "get_bank_txn_check_list.pc"
};


static unsigned int sqlctx = 638716427;


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
   unsigned char  *sqhstv[2];
   unsigned long  sqhstl[2];
            int   sqhsts[2];
            short *sqindv[2];
            int   sqinds[2];
   unsigned long  sqharm[2];
   unsigned long  *sqharc[2];
   unsigned short  sqadto[2];
   unsigned short  sqtdso[2];
} sqlstm = {12,2};

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

 static char *sq0001 = 
"ED = 0 AND PP_PAY_METHOD = SP_PAY_ME\
THOD AND SP_DISABLED = 0 AND BS_SERVICE_CODE = SP_SERVICE_CODE AND BS_INT_BAN\
K_CODE = BC . BC_BANK_CODE AND BS_DISABLED = 0 ) AND EXISTS ( SELECT 1 FROM t\
xn_psp_detail WHERE TP_PSP_ID = PD . PSP_ID AND TP_CREATE_TIMESTAMP > sysdate\
 - 1 / 2 ) ORDER BY BC . BC_BANK_CODE , PD . PSP_ID ASC            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,1358,0,9,96,0,2049,0,0,0,1,0,
20,0,0,1,0,0,13,98,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
43,0,0,1,0,0,15,113,0,0,0,0,0,1,0,
58,0,0,1,0,0,15,120,0,0,0,0,0,1,0,
73,0,0,2,0,0,32,121,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/06/10              Stan Poon
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include "common.h"
#include "utilitys.h"
#include "batchcommon.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char	cDebug;

int batch_init(int argc, char* argv[])
{
        return SUCCESS;
}


int batch_terminate(int argc, char* argv[])
{
    return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{

        /* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar         v_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

		short           ind_psp_id = -1;
		short           ind_bank_code = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        /* EXEC SQL DECLARE c_cursor_getpspbank CURSOR FOR
		SELECT	PD.PSP_ID,
			BC.BC_BANK_CODE
		FROM	PSP_MASTER,
			PSP_DETAIL PD,
			PSP_COUNTRY PC,
			(SELECT	BC1.BC_PARTY_ID, BC1.BC_BANK_CODE
			FROM	BANK_TXN_CHECK BC1
			WHERE	BC1.BC_DISABLED = 0
			AND	(BC1.BC_PARTY_ID = '000'
				OR (BC1.BC_PARTY_ID <> '000' 
				AND NOT EXISTS (SELECT * FROM BANK_TXN_CHECK BC2
				WHERE BC2.BC_DISABLED = 0 AND BC2.BC_PARTY_ID = '000'
				AND BC2.BC_BANK_CODE = BC1.BC_BANK_CODE)))) BC
		WHERE	PM_CLIENT_ID = PD.CLIENT_ID
		AND	PM_STATUS = 'O'
		AND	PD.ONLINE_MODE = 'Y'
		AND	PD.STATUS = 'O'
		AND	PD.DISABLED = 0
		AND	PD.PSP_ID = PC.PSP_ID
		AND	(PD.PSP_ID = BC.BC_PARTY_ID OR BC.BC_PARTY_ID = '000')
		AND	EXISTS (SELECT *
			FROM	BANK_MAPPING
			WHERE	BM_PSP_CHANNEL_ID = NVL(PD.OVERRIDED_BANK_CODE_CHANNEL, PD.PSP_CHANNEL_CODE)
			AND	BM_INT_BANK_CODE = BC.BC_BANK_CODE
			AND	BM_COUNTRY = PC.COUNTRY
			AND	BM_DISABLED = 0)
		AND	EXISTS (SELECT *
			FROM	PSP_PAY_METHOD, SERVICE_PAY_METHOD, BANK_SERVICE_MAPPING
			WHERE	PP_COUNTRY = PC.COUNTRY
			AND	PP_PSP_ID = PD.PSP_ID
			AND	PP_DISABLED = 0
			AND	PP_PAY_METHOD = SP_PAY_METHOD
			AND	SP_DISABLED = 0
			AND	BS_SERVICE_CODE = SP_SERVICE_CODE
			AND	BS_INT_BANK_CODE = BC.BC_BANK_CODE
			AND	BS_DISABLED = 0)
		AND     EXISTS (SELECT 1
                        FROM txn_psp_detail
                        WHERE TP_PSP_ID = PD.PSP_ID
                        AND TP_CREATE_TIMESTAMP > sysdate - 1/2)
		ORDER BY BC.BC_BANK_CODE, PD.PSP_ID ASC; */ 


        /* EXEC SQL OPEN c_cursor_getpspbank; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 0;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlbuft((void **)0,
          "SELECT PD . PSP_ID , BC . BC_BANK_CODE FROM PSP_MASTER , PSP_DETA\
IL PD , PSP_COUNTRY PC , ( SELECT BC1 . BC_PARTY_ID , BC1 . BC_BANK_CODE FRO\
M BANK_TXN_CHECK BC1 WHERE BC1 . BC_DISABLED = 0 AND ( BC1 . BC_PARTY_ID = '\
000' OR ( BC1 . BC_PARTY_ID <> '000' AND NOT EXISTS ( SELECT * FROM BANK_TXN\
_CHECK BC2 WHERE BC2 . BC_DISABLED = 0 AND BC2 . BC_PARTY_ID = '000' AND BC2\
 . BC_BANK_CODE = BC1 . BC_BANK_CODE ) ) ) ) BC WHERE PM_CLIENT_ID = PD . CL\
IENT_ID AND PM_STATUS = 'O' AND PD . ONLINE_MODE = 'Y' AND PD . STATUS = 'O'\
 AND PD . DISABLED = 0 AND PD . PSP_ID = PC . PSP_ID AND ( PD . PSP_ID = BC \
. BC_PARTY_ID OR BC . BC_PARTY_ID = '000' ) AND EXISTS ( SELECT * FROM BANK_\
MAPPING WHERE BM_PSP_CHANNEL_ID = NVL ( PD . OVERRIDED_BANK_CODE_CHANNEL , P\
D . PSP_CHANNEL_CODE ) AND BM_INT_BANK_CODE = BC . BC_BANK_CODE AND BM_COUNT\
RY = PC . COUNTRY AND BM_DISABLED = 0 ) AND EXISTS ( SELECT * FROM PSP_PAY_M\
ETHOD , SERVICE_PAY_METHOD , BANK_SERVICE_MAPPING WHERE PP_COUNTRY = PC . CO\
UNTRY AND PP_PSP_ID = PD . PSP_ID AND PP_DISABL");
        sqlstm.stmt = sq0001;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )5;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto sql_error;
}


        do{
                /* EXEC SQL FETCH c_cursor_getpspbank
                INTO    :v_psp_id:ind_psp_id,
			:v_bank_code:ind_bank_code; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 2;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )20;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_psp_id;
                sqlstm.sqhstl[0] = (unsigned long )13;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_psp_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_bank_code;
                sqlstm.sqhstl[1] = (unsigned long )13;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_bank_code;
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
                if (sqlca.sqlcode < 0) goto sql_error;
}




                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		printf("%.*s;",v_psp_id.len,v_psp_id.arr);
		printf("%.*s;\n",v_bank_code.len,v_bank_code.arr);

	}while(PD_TRUE);


        /* EXEC SQL CLOSE c_cursor_getpspbank; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )43;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto sql_error;
}



        return SUCCESS;
sql_error:
    DEBUGLOG(("sql_error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getpspbank; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 2;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )58;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 2;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )73;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}
