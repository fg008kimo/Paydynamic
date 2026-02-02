
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
           char  filnam[12];
};
static struct sqlcxp sqlfpn =
{
    11,
    "TxnBeUrl.pc"
};


static unsigned int sqlctx = 168955;


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
   unsigned char  *sqhstv[6];
   unsigned long  sqhstl[6];
            int   sqhsts[6];
            short *sqindv[6];
            int   sqinds[6];
   unsigned long  sqharm[6];
   unsigned long  *sqharc[6];
   unsigned short  sqadto[6];
   unsigned short  sqtdso[6];
} sqlstm = {12,6};

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

 static char *sq0003 = 
"SELECT SERVICE_CODE FROM TXN_BE_URL WHERE PSP_ID = :b0 AND TXN_CODE = :b1  \
          ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,169,0,6,88,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
36,0,0,0,0,0,56,191,0,0,1,1,0,1,0,3,102,0,0,
55,0,0,2,194,0,6,192,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,2,
102,0,0,
94,0,0,0,0,0,13,213,0,0,3,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,
121,0,0,0,0,0,15,242,0,0,1,1,0,1,0,1,102,0,0,
140,0,0,0,0,0,78,243,0,0,1,1,0,1,0,3,102,0,0,
159,0,0,0,0,0,15,247,0,0,1,1,0,1,0,1,102,0,0,
178,0,0,0,0,0,78,248,0,0,1,1,0,1,0,3,102,0,0,
197,0,0,0,0,0,15,259,0,0,1,1,0,1,0,1,102,0,0,
216,0,0,0,0,0,78,260,0,0,1,1,0,1,0,3,102,0,0,
235,0,0,3,85,0,9,534,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
258,0,0,3,0,0,13,538,0,0,1,0,0,1,0,2,9,0,0,
277,0,0,3,0,0,15,560,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/02/11              [MSN]
PRD332
 - Add GetTxnBeUrlByPspId                          2021/07/27              [MIC]
 - Add GetServiceCode                              2021/08/03              [ZBL]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "TxnBeUrl.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


static char cDebug;

void TxnBeUrl(char    cdebug)
{
        cDebug = cdebug;
}

int Replicate(const hash_t *hRec)
{
	char            *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO replicate_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		
		/* varchar         hv_replicate_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_replicate_psp_id;

		/* varchar         hv_create_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_create_psp_id;

		/* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_replicate_psp_id = -1;
		short		ind_create_psp_id = -1;
		short		ind_create_user = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



	DEBUGLOG(("Replicate: Begin\n"));


	if(GetField_CString(hRec,"replicate_psp_id",&csTmp))
	{
		hv_replicate_psp_id.len = strlen(csTmp);
		strncpy((char*)hv_replicate_psp_id.arr, csTmp, hv_replicate_psp_id.len);
		ind_replicate_psp_id = 0;
	}
DEBUGLOG(("Replicate:replicate_psp_id = [%.*s]\n",hv_replicate_psp_id.len,hv_replicate_psp_id.arr));

	if(GetField_CString(hRec,"create_psp_id",&csTmp))
	{
		hv_create_psp_id.len = strlen(csTmp);
		strncpy((char*)hv_create_psp_id.arr, csTmp, hv_create_psp_id.len);
		ind_create_psp_id = 0;
	}
DEBUGLOG(("Replicate:create_psp_id = [%.*s]\n",hv_create_psp_id.len,hv_create_psp_id.arr));



	if(GetField_CString(hRec,"create_user",&csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
	}
DEBUGLOG(("Replicate:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));



	FREE_ME(csTmp);


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_txn_be_url_rpl(
				:hv_replicate_psp_id:ind_replicate_psp_id,
				:hv_create_psp_id:ind_create_psp_id,
				:hv_create_user:ind_create_user
				);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_txn_be_url_rpl ( :hv_replicate\
_psp_id:ind_replicate_psp_id , :hv_create_psp_id:ind_create_psp_id , :hv_crea\
te_user:ind_create_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_replicate_psp_id;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_replicate_psp_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_create_psp_id;
 sqlstm.sqhstl[2] = (unsigned long )12;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_create_psp_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[3] = (unsigned long )22;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto replicate_error;
}




	DEBUGLOG(("Replicate:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
		DEBUGLOG(("Replicate:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
		ERRLOG("TxnBeUrl_Replicate: SP_OTHER_ERR TxnAbort\n");
		DEBUGLOG(("Replicate: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
		ERRLOG("TxnBeUrl_Replicate: SP_ERR TxnAbort\n");
		DEBUGLOG(("Replicate: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

	if (hv_return_value == SP_NOT_FOUND)  {
		ERRLOG("TxnBeUrl_Replicate: SP_NOT_FOUND TxnAbort\n");
		DEBUGLOG(("Replicate: SP_NOT_FOUND TxnAbort\n"));
		return PD_NOT_FOUND;
	}

replicate_error:
DEBUGLOG(("replicate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("TxnBeUrl_Replicate: SP_INTERNAL_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;


}


int GetBeUrl(const unsigned char* csTxnCode,
                const unsigned char* csServiceCode,
                const unsigned char* csPspId,
                recordset_t* myRec)
{
        int iRet = PD_ERR;
        char csURL[PD_TMP_BUF_LEN + 1];

        hash_t *myHash;
        /* EXEC SQL WHENEVER SQLERROR GOTO geturl_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short           hv_return_value;

                /* varchar         hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                /* varchar         hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

                /* varchar         hv_route_type[PD_ROUTE_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_route_type;


                /* varchar         v_path[PD_VALUE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_path;

                /* varchar         v_url[PD_VALUE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_url;


                short           ind_path = -1;
                short           ind_url = -1;
                short           ind_txn_code = -1;
                short           ind_service_code = -1;
                short           ind_psp_id = -1;
                short           ind_route_type = -1;

                 SQL_CURSOR      c_cursor_urldt;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_code.len = strlen((const char*)csTxnCode);
        memcpy(hv_txn_code.arr,csTxnCode,hv_txn_code.len);
DEBUGLOG(("GetBeUrl txn_code = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));
        ind_txn_code = 0;

        hv_service_code.len = strlen((const char*)csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("GetBeUrl service_code= [%.*s]\n",hv_service_code.len,hv_service_code.arr));
        ind_service_code = 0;

        hv_psp_id.len = strlen((const char*)csPspId);
        memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);
DEBUGLOG(("GetBeUrl psp_id = [%.*s]\n",hv_psp_id.len,hv_psp_id.arr));
        ind_psp_id = 0;

        hv_route_type.len = PD_ROUTE_TYPE_LEN;
        memcpy(hv_route_type.arr,PD_BE_TXN,hv_route_type.len);
DEBUGLOG(("GetBeUrl route_type = [%.*s]\n",hv_route_type.len,hv_route_type.arr));
        ind_route_type = 0;

        /* EXEC SQL ALLOCATE       :c_cursor_urldt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )36;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_urldt;
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
        if (sqlca.sqlcode < 0) goto geturl_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_txn_be_url_geturl(:hv_txn_code:ind_txn_code,
                                                                 :hv_service_code:ind_service_code,
                                                                 :hv_psp_id:ind_psp_id,
                                                                 :hv_route_type:ind_route_type,
                                                                 :c_cursor_urldt);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_txn_be_url_geturl ( :hv\
_txn_code:ind_txn_code , :hv_service_code:ind_service_code , :hv_psp_id:ind_p\
sp_id , :hv_route_type:ind_route_type , :c_cursor_urldt ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )55;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_service_code;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_psp_id;
        sqlstm.sqhstl[3] = (unsigned long )12;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_psp_id;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_route_type;
        sqlstm.sqhstl[4] = (unsigned long )4;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_route_type;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&c_cursor_urldt;
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
        if (sqlca.sqlcode < 0) goto geturl_error;
}



///////////////////////////////
        if (hv_return_value > 0)  {
DEBUGLOG(("Find Found\n"));
                for (;;) {
                        myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);

                        ind_path = -1;
                        ind_url = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_urldt
                        INTO
                                :v_url:ind_url,
                                :v_path:ind_path; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 6;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )94;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_urldt;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_url;
                        sqlstm.sqhstl[1] = (unsigned long )53;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_url;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_path;
                        sqlstm.sqhstl[2] = (unsigned long )53;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_path;
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
                        if (sqlca.sqlcode == 1403) break;
                        if (sqlca.sqlcode < 0) goto geturl_error;
}



                        if (ind_url >= 0) {
                                v_url.arr[v_url.len] = '\0';
                                strcpy((char*)csURL,(const char*)v_url.arr);
DEBUGLOG(("URL = [%s]\n",csURL));
                                if (ind_path >= 0) {
                                        v_path.arr[v_path.len] = '\0';
DEBUGLOG(("PATH = [%.*s]\n",v_path.len,v_path.arr));
                                        strcat((char*)csURL,(const char*)v_path.arr);
DEBUGLOG(("URL+PATH = [%s]\n",csURL));

                                        PutField_CString(myHash,"be_url",csURL);
DEBUGLOG(("GetBeUrl be_url = [%s]\n",csURL));
                                        iRet = PD_OK;

                                        RecordSet_Add(myRec,myHash);
                                }
                                else
DEBUGLOG(("PATH NOT FOUND\n"));
                        }
                        else
DEBUGLOG(("URL NOT FOUND\n"));


                }
		/* EXEC SQL CLOSE :c_cursor_urldt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )121;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_urldt;
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
  if (sqlca.sqlcode < 0) goto geturl_error;
}


		/* EXEC SQL FREE :c_cursor_urldt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )140;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_urldt;
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
  if (sqlca.sqlcode < 0) goto geturl_error;
}


                return iRet;
        }
        else {
		/* EXEC SQL CLOSE :c_cursor_urldt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )159;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_urldt;
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
  if (sqlca.sqlcode < 0) goto geturl_error;
}


		/* EXEC SQL FREE :c_cursor_urldt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )178;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_urldt;
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
  if (sqlca.sqlcode < 0) goto geturl_error;
}


DEBUGLOG(("Find Not Found\n"));
                return PD_ERR;
        }

///////////////////////////////

geturl_error:
DEBUGLOG(("geturl_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE :c_cursor_urldt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )197;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_urldt;
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


        /* EXEC SQL FREE :c_cursor_urldt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )216;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_urldt;
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



/*
int FindURL(const unsigned char* TxnCode,
		const unsigned char* ServiceCode,
                const unsigned char* PspId,
                unsigned char* URL)
{

	int iRet = NOT_FOUND;
	int iDomain = PD_FALSE;

        EXEC SQL WHENEVER SQLERROR GOTO find_error;
        EXEC SQL WHENEVER NOTFOUND CONTINUE;

        EXEC SQL BEGIN DECLARE SECTION;
                varchar hv_txn_code[PD_TXN_CODE_LEN];
                varchar hv_psp_id[PD_PSP_ID_LEN];
                varchar hv_def_psp_id[PD_PSP_ID_LEN];
                varchar hv_service_code[PD_SERVICE_CODE_LEN];
		varchar hv_route_type[PD_ROUTE_TYPE_LEN];
		char	hv_disabled;

                varchar v_url[PD_VALUE_LEN +1 ];
                varchar v_override_domain[PD_VALUE_LEN +1 ];
		varchar	v_path[PD_VALUE_LEN + 1];

                short   ind_url = -1;
                short   ind_override_domain = -1;
		short	ind_path = -1;
        EXEC SQL END DECLARE SECTION;

        hv_txn_code.len = strlen((const char*)TxnCode);
        memcpy(hv_txn_code.arr,TxnCode,hv_txn_code.len);
DEBUGLOG(("FindURL: Txn Code = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr)); 

        hv_psp_id.len = strlen((const char*)PspId);
        memcpy(hv_psp_id.arr,PspId,hv_psp_id.len);
DEBUGLOG(("FindURL: PspId = [%.*s]\n",hv_psp_id.len,hv_psp_id.arr)); 

        hv_service_code.len = strlen((const char*)ServiceCode);
        memcpy(hv_service_code.arr,ServiceCode,hv_service_code.len);
DEBUGLOG(("FindURL: ServiceCode = [%.*s]\n",hv_service_code.len,hv_service_code.arr)); 


	hv_route_type.len = PD_ROUTE_TYPE_LEN;
        memcpy(hv_route_type.arr,PD_BE_TXN,hv_route_type.len);
DEBUGLOG(("FindURL route_type = [%.*s]\n",hv_route_type.len,hv_route_type.arr));

	hv_disabled='0';

	EXEC SQL DECLARE c_cursor_geturl CURSOR FOR
        	select  a.url,
			b.override_domain,
			b.path
                from	service a,
			txn_be_url b
                where b.txn_code=:hv_txn_code
		and   b.psp_id=:hv_psp_id
		and   a.psp_id=:hv_psp_id
		and   b.service_code=:hv_service_code
		and   a.code=b.service_code
		and   b.disabled=:hv_disabled
		and   a.disabled=:hv_disabled
		and   a.route_type=:hv_route_type
		AND   a.effect_date  =
                        (SELECT max(effect_date)
                           FROM service
                          WHERE code=:hv_service_code
                          AND	disabled=:hv_disabled
			  and   route_type=:hv_route_type
			  and   psp_id=:hv_psp_id
                          AND	effect_date <= sysdate)
		AND   b.effect_date  =
                        (SELECT max(effect_date)
                           FROM txn_be_url
                          WHERE txn_code=:hv_txn_code
			    AND psp_id=:hv_psp_id
			    AND service_code=:hv_service_code
                            AND disabled=:hv_disabled
                            AND effect_date <= sysdate);


	EXEC SQL OPEN c_cursor_geturl;
	do{	
		EXEC SQL FETCH c_cursor_geturl
                INTO
			:v_url:ind_url,
			:v_override_domain:ind_override_domain,
			:v_path:ind_path;

		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		if(ind_override_domain >=0){
                	v_override_domain.arr[v_override_domain.len] = '\0';
                	strcpy((char*)URL,(const char*)v_override_domain.arr);
DEBUGLOG(("URL(Override) = [%s]\n",URL)); 
			iDomain = PD_TRUE;
		}
		else{
        		if (ind_url >= 0) {
                		v_url.arr[v_url.len] = '\0';
                		strcpy((char*)URL,(const char*)v_url.arr);
				iDomain = PD_TRUE;
DEBUGLOG(("URL = [%s]\n",URL)); 
			}
		}

		if(iDomain == PD_TRUE){
       	 		if (ind_path >= 0) {
               	 		v_path.arr[v_path.len] = '\0';
DEBUGLOG(("PATH = [%.*s]\n",v_path.len,v_path.arr)); 
                		strcat((char*)URL,(const char*)v_path.arr);
DEBUGLOG(("URL+PATH = [%s]\n",URL)); 	
                		iRet = FOUND;
			}
			else{
DEBUGLOG(("PATH NOT FOUND\n"));
			}
		}
		else{
DEBUGLOG(("URL NOT FOUND\n"));
		}
        }while(PD_TRUE);

	EXEC SQL CLOSE c_cursor_geturl;

	if(iRet!=FOUND){
        	hv_def_psp_id.len = strlen((const char*)PD_DEFAULT_PSP);
		memcpy(hv_def_psp_id.arr,PD_DEFAULT_PSP,hv_def_psp_id.len);
DEBUGLOG(("FindURL: PspId = [%.*s]\n",hv_def_psp_id.len,hv_def_psp_id.arr)); 


		EXEC SQL DECLARE c_cursor_getdefurl CURSOR FOR
			select  a.url,
				b.override_domain,
				b.path
			from	service a,
				txn_be_url b
			where b.txn_code=:hv_txn_code
			and   b.psp_id=:hv_psp_id
			and   a.psp_id=:hv_def_psp_id
			and   b.service_code=:hv_service_code
			and   a.code=b.service_code
			and   b.disabled=:hv_disabled
			and   a.disabled=:hv_disabled
			and   a.route_type=:hv_route_type
			AND   a.effect_date  =
				(SELECT max(effect_date)
				 FROM service
				 WHERE code=:hv_service_code
				 AND	disabled=:hv_disabled
				 and   route_type=:hv_route_type
				 and	psp_id =:hv_def_psp_id
				 AND	effect_date <= sysdate)
				AND   b.effect_date  =
					(SELECT max(effect_date)
					 FROM txn_be_url
					 WHERE txn_code=:hv_txn_code
					 AND psp_id=:hv_psp_id
					 AND service_code=:hv_service_code
					 AND disabled=:hv_disabled
					 AND effect_date <= sysdate);

		EXEC SQL OPEN c_cursor_getdefurl;
		do{	
			EXEC SQL FETCH c_cursor_getdefurl
				INTO
				:v_url:ind_url,
				:v_override_domain:ind_override_domain,
				:v_path:ind_path;

			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			if(ind_override_domain >=0){
                		v_override_domain.arr[v_override_domain.len] = '\0';
                		strcpy((char*)URL,(const char*)v_override_domain.arr);
DEBUGLOG(("URL(Override) = [%s]\n",URL)); 
				iDomain = PD_TRUE;
			}
			else{
        			if (ind_url >= 0) {
                			v_url.arr[v_url.len] = '\0';
                			strcpy((char*)URL,(const char*)v_url.arr);
					iDomain = PD_TRUE;
DEBUGLOG(("URL = [%s]\n",URL)); 
				}
			}

			if(iDomain == PD_TRUE){
       	 			if (ind_path >= 0) {
               	 			v_path.arr[v_path.len] = '\0';
DEBUGLOG(("PATH = [%.*s]\n",v_path.len,v_path.arr)); 
                			strcat((char*)URL,(const char*)v_path.arr);
DEBUGLOG(("URL+PATH = [%s]\n",URL)); 	
                			iRet = FOUND;
				}
				else{
DEBUGLOG(("PATH NOT FOUND\n"));
				}
			}
			else{
DEBUGLOG(("URL NOT FOUND\n"));
			}
		}while(PD_TRUE);

		EXEC SQL CLOSE c_cursor_getdefurl;
	}


	if(iRet!=FOUND){
DEBUGLOG(("URL Not Found!!!!!\n"));
	}
DEBUGLOG(("Find URL exit = [%d]\n",iRet));
	return iRet;

find_error:
DEBUGLOG(("find_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    EXEC SQL WHENEVER SQLERROR CONTINUE;
    return NOT_FOUND;
}
*/

int GetServiceCode(const char* csPspId, const char* csTxnCode, recordset_t* rRec)
{
	int	iCnt = 0;
	int	iRet = PD_NOT_FOUND;
	hash_t	*hRec;

	/* EXEC SQL WHENEVER SQLERROR GOTO get_service_code_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar		hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;


		/* varchar		v_service_code[PD_SERVICE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;


		short		ind_psp_id		= -1;
		short		ind_txn_code		= -1;
		short		ind_service_code	= -1;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetServiceCode: Begin\n"));

	/* psp_id */
	hv_psp_id.len = strlen(csPspId);
	memcpy(hv_psp_id.arr, csPspId, hv_psp_id.len);
	ind_psp_id = 0;

DEBUGLOG(("- psp_id = [%.*s]\n", hv_psp_id.len, hv_psp_id.arr));

	/* txn_code */
	hv_txn_code.len = strlen(csTxnCode);
	memcpy(hv_txn_code.arr, csTxnCode, hv_txn_code.len);
	ind_txn_code = 0;

DEBUGLOG(("- txn_code = [%.*s]\n", hv_txn_code.len, hv_txn_code.arr));

	/* EXEC SQL DECLARE c_cursor_getservicecode CURSOR FOR
		SELECT	SERVICE_CODE 
		FROM	TXN_BE_URL 
		WHERE	PSP_ID = :hv_psp_id 
			AND TXN_CODE = :hv_txn_code; */ 


	/* EXEC SQL OPEN c_cursor_getservicecode; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )235;
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
 if (sqlca.sqlcode < 0) goto get_service_code_error;
}



	do
	{
		/* EXEC SQL FETCH c_cursor_getservicecode 
		INTO 
			:v_service_code:ind_service_code; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )258;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_service_code;
  sqlstm.sqhstl[0] = (unsigned long )6;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_service_code;
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
  if (sqlca.sqlcode < 0) goto get_service_code_error;
}



		if (SQLCODE == SQL_NOT_FOUND)
			break;

		hRec = (hash_t*)malloc(sizeof(hash_t));
		hash_init(hRec, 0);

		/* service_code */
		if (ind_service_code >= 0)
		{
			v_service_code.arr[v_service_code.len] = '\0';
DEBUGLOG(("- service_code = [%s]\n", v_service_code.arr));
			PutField_CString(hRec, "service_code", (const char *)v_service_code.arr);
		}

		iCnt++;
		RecordSet_Add(rRec, hRec);
	} while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getservicecode; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )277;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto get_service_code_error;
}



	if (iCnt > 0)
	{
DEBUGLOG(("GetServiceCode [%d] records found! Normal Exit\n", iCnt));
		iRet = PD_FOUND;
	}
	else
	{
DEBUGLOG(("GetServiceCode no records found! Normal Exit\n"));
	}

	return iRet;

get_service_code_error:
DEBUGLOG(("get_service_code_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("TxnBeUrl_GetServiceCode: SP_INTERNAL_ERR\n");
DEBUGLOG(("GetServiceCode: SP_INTERNAL_ERR\n"));
	return PD_ERR;
}
