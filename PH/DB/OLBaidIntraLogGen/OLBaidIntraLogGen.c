
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
           char  filnam[21];
};
static struct sqlcxp sqlfpn =
{
    20,
    "OLBaidIntraLogGen.pc"
};


static unsigned int sqlctx = 79003771;


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
   unsigned char  *sqhstv[5];
   unsigned long  sqhstl[5];
            int   sqhsts[5];
            short *sqindv[5];
            int   sqinds[5];
   unsigned long  sqharm[5];
   unsigned long  *sqharc[5];
   unsigned short  sqadto[5];
   unsigned short  sqtdso[5];
} sqlstm = {12,5};

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
"SELECT oalg_stmt_txn_id , oalg_status , oalg_gen_txn_id_fr , oalg_gen_txn_i\
d_to , oalg_ret_code FROM ol_baid_intra_log_gen WHERE oalg_batch_id = :b0    \
        ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,160,0,9,69,0,2049,1,1,0,1,0,1,68,0,0,
24,0,0,1,0,0,13,72,0,0,5,0,0,1,0,2,9,0,0,2,1,0,0,2,9,0,0,2,9,0,0,2,3,0,0,
59,0,0,1,0,0,15,127,0,0,0,0,0,1,0,
74,0,0,0,0,0,56,190,0,0,1,1,0,1,0,3,102,0,0,
93,0,0,2,119,0,6,191,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,2,102,0,0,
120,0,0,0,0,0,13,208,0,0,3,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,
147,0,0,0,0,0,15,250,0,0,1,1,0,1,0,1,102,0,0,
166,0,0,0,0,0,78,251,0,0,1,1,0,1,0,3,102,0,0,
185,0,0,0,0,0,15,260,0,0,1,1,0,1,0,1,102,0,0,
204,0,0,0,0,0,78,261,0,0,1,1,0,1,0,3,102,0,0,
223,0,0,3,0,0,17,380,0,0,1,1,0,1,0,1,9,0,0,
242,0,0,3,0,0,21,381,0,0,0,0,0,1,0,
257,0,0,3,0,0,17,475,0,0,1,1,0,1,0,1,9,0,0,
276,0,0,3,0,0,21,476,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2020. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2020/08/21              [ZBL]
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlca.h>
#include "OLBaidIntraLogGen.h"
#include "common.h"
#include "dbutility.h"
#include "internal.h"
#include "utilitys.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char cDebug;

void OLBaidIntraLogGen(char cdebug)
{
	cDebug = cdebug;
}

int GetDetailByBatchId(const unsigned long lBatchId, recordset_t *rRec)
{
	int	iCnt = 0;
	int	iRet = PD_NOT_FOUND;
	hash_t	*hRec;

	/* EXEC SQL WHENEVER SQLERROR GOTO get_detail_by_batchid_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		unsigned long	hv_batch_id;

		/* varchar		v_stmt_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_stmt_txn_id;

		char		v_status;
		/* varchar		v_gen_txn_id_fr[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_gen_txn_id_fr;

		/* varchar		v_gen_txn_id_to[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_gen_txn_id_to;

		int		v_ret_code;

		short		ind_stmt_txn_id		= -1;
		short		ind_status		= -1;
		short		ind_gen_txn_id_fr	= -1;
		short		ind_gen_txn_id_to	= -1;
		short		ind_ret_code		= -1;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetDetailByBatchId: Begin\n"));

	/* batch_id */
	hv_batch_id = lBatchId;
DEBUGLOG(("- batch_id = [%lu]\n", hv_batch_id));

	/* EXEC SQL DECLARE c_cursor_getdetailbybatchid CURSOR FOR 
		SELECT	oalg_stmt_txn_id, 
			oalg_status, 
			oalg_gen_txn_id_fr, 
			oalg_gen_txn_id_to, 
			oalg_ret_code
		FROM	ol_baid_intra_log_gen 
		WHERE	oalg_batch_id = :hv_batch_id; */ 


	/* EXEC SQL OPEN c_cursor_getdetailbybatchid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0001;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
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
 if (sqlca.sqlcode < 0) goto get_detail_by_batchid_error;
}


	do
	{
		/* EXEC SQL FETCH c_cursor_getdetailbybatchid 
			INTO	:v_stmt_txn_id:ind_stmt_txn_id, 
				:v_status:ind_status, 
				:v_gen_txn_id_fr:ind_gen_txn_id_fr, 
				:v_gen_txn_id_to:ind_gen_txn_id_to, 
				:v_ret_code:ind_ret_code; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 5;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )24;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_stmt_txn_id;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_stmt_txn_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[1] = (unsigned long )1;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_status;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_gen_txn_id_fr;
  sqlstm.sqhstl[2] = (unsigned long )19;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_gen_txn_id_fr;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_gen_txn_id_to;
  sqlstm.sqhstl[3] = (unsigned long )19;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_gen_txn_id_to;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_ret_code;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_ret_code;
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
  if (sqlca.sqlcode < 0) goto get_detail_by_batchid_error;
}



		if (SQLCODE == SQL_NOT_FOUND)
			break;

		hRec = (hash_t*)malloc(sizeof(hash_t));
		hash_init(hRec, 0);

		/* stmt_txn_id */
		if (ind_stmt_txn_id >= 0)
		{
			v_stmt_txn_id.arr[v_stmt_txn_id.len] = '\0';
DEBUGLOG(("- stmt_txn_id = [%s]\n", v_stmt_txn_id.arr));
			PutField_CString(hRec, "stmt_txn_id", (const char*)v_stmt_txn_id.arr);
		}

		/* status */
		if (ind_status >= 0)
		{
DEBUGLOG(("- status = [%c]\n", v_status));
			PutField_Char(hRec, "status", v_status);
		}

		/* gen_txn_id_fr */
		if (ind_gen_txn_id_fr >= 0)
		{
			v_gen_txn_id_fr.arr[v_gen_txn_id_fr.len] = '\0';
DEBUGLOG(("- gen_txn_id_fr = [%s]\n", v_gen_txn_id_fr.arr));
			PutField_CString(hRec, "gen_txn_id_fr", (const char*)v_gen_txn_id_fr.arr);
		}

		/* gen_txn_id_to */
		if (ind_gen_txn_id_to >= 0)
		{
			v_gen_txn_id_to.arr[v_gen_txn_id_to.len] = '\0';
DEBUGLOG(("- gen_txn_id_to = [%s]\n", v_gen_txn_id_to.arr));
			PutField_CString(hRec, "gen_txn_id_to", (const char*)v_gen_txn_id_to.arr);
		}

		/* ret_code */
		if (ind_ret_code >= 0)
		{
DEBUGLOG(("- ret_code = [%d]\n", v_ret_code));
			PutField_Int(hRec, "ret_code", v_ret_code);
		}

		iCnt++;
		RecordSet_Add(rRec, hRec);
	} while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getdetailbybatchid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )59;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto get_detail_by_batchid_error;
}



	if (iCnt > 0)
	{
DEBUGLOG(("GetDetailByBatchId [%d] records found! Normal Exit\n", iCnt));
		iRet = PD_FOUND;
	}
	else
	{
DEBUGLOG(("GetDetailByBatchId no records found! Normal Exit\n"));
	}

	return iRet;

get_detail_by_batchid_error:
DEBUGLOG(("get_detail_by_batchid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLBaidIntraLogGen_GetDetailByBatchId: SP_INTERNAL_ERR\n");
DEBUGLOG(("GetDetailByBatchId: SP_INTERNAL_ERR\n"));
	return PD_ERR;
}

int GetDetailByTxnId(hash_t *hRec)
{
	int	iRet = PD_NOT_FOUND;

        char    *csTmp = NULL;

        /* EXEC SQL WHENEVER SQLERROR GOTO getdetailbytxnid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


                short           ind_txn_id = -1;

		SQL_CURSOR      c_cursor_getdetailbytxnid;

		/* varchar         v_gen_txn_id_fr[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_gen_txn_id_fr;

                /* varchar         v_gen_txn_id_to[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_gen_txn_id_to;


                short           ind_gen_txn_id_fr = -1;
                short           ind_gen_txn_id_to = -1;

                short           hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetDetailByTxnId: Begin\n"));

/* txn_id */
        if(GetField_CString(hRec,"txn_id",&csTmp))
        {
                hv_txn_id.len = strlen(csTmp);
                strncpy((char *)hv_txn_id.arr, csTmp, hv_txn_id.len);
                ind_txn_id = 0;
DEBUGLOG(("GetDetailByTxnId: txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
        } else {
DEBUGLOG(("GetDetailByTxnId: txn_id is missing\n"));
ERRLOG("OLBaidIntraLogGen: GetDetailByTxnId: txn_id is missing\n");
                return PD_ERR;
        }

	/* EXEC SQL ALLOCATE       :c_cursor_getdetailbytxnid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )74;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getdetailbytxnid;
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
 if (sqlca.sqlcode < 0) goto getdetailbytxnid_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_ol_intra_log_gen_get_detail(:hv_txn_id:ind_txn_id,
								       	   :c_cursor_getdetailbytxnid);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_intra_log_gen_get_de\
tail ( :hv_txn_id:ind_txn_id , :c_cursor_getdetailbytxnid ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )93;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&c_cursor_getdetailbytxnid;
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
        if (sqlca.sqlcode < 0) goto getdetailbytxnid_error;
}



DEBUGLOG(("GetDetailByTxnId: Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("GetDetailByTxnId: Found\n"));
		for (;;) {

                        ind_gen_txn_id_fr = -1;
                        ind_gen_txn_id_to = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_getdetailbytxnid
			INTO
                     		:v_gen_txn_id_fr:ind_gen_txn_id_fr,
                     		:v_gen_txn_id_to:ind_gen_txn_id_to; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 5;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )120;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getdetailbytxnid;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_gen_txn_id_fr;
                        sqlstm.sqhstl[1] = (unsigned long )18;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_gen_txn_id_fr;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_gen_txn_id_to;
                        sqlstm.sqhstl[2] = (unsigned long )18;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_gen_txn_id_to;
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
                        if (sqlca.sqlcode < 0) goto getdetailbytxnid_error;
}



                        if (SQLCODE == SQL_NOT_FOUND) {
                                break;
                        }

/* gen_txn_id_fr */
                        if (ind_gen_txn_id_fr >= 0) {
                                v_gen_txn_id_fr.arr[v_gen_txn_id_fr.len]='\0';
                                PutField_CString(hRec,"gen_txn_id_fr",(const char*)v_gen_txn_id_fr.arr);
DEBUGLOG(("GetDetailByTxnId: gen_txn_id_fr = [%s]\n",v_gen_txn_id_fr.arr));
                        }

/* gen_txn_id_to */
                        if (ind_gen_txn_id_to >= 0) {
                                v_gen_txn_id_to.arr[v_gen_txn_id_to.len]='\0';
                                PutField_CString(hRec,"gen_txn_id_to",(const char*)v_gen_txn_id_to.arr);
DEBUGLOG(("GetDetailByTxnId: gen_txn_id_to = [%s]\n",v_gen_txn_id_to.arr));
                        } 
		}

                iRet = PD_FOUND;
        }
        else if (hv_return_value == SP_NOT_FOUND)
        {
DEBUGLOG(("GetDetailByTxnId: Not Found\n"));
                iRet = PD_NOT_FOUND;
        }
        else if (hv_return_value == SP_OTHER_ERR)  {
DEBUGLOG(("GetDetailByTxnId: SP_OTHER_ERR TxnAbort\n"));
ERRLOG("OLBaidIntraLogGen_GetDetailByTxnId: SP_OTHER_ERR TxnAbort\n");
                iRet = PD_OTHER_ERR;
        }
        else if (hv_return_value == SP_ERR)  {
DEBUGLOG(("GetDetailByTxnId: SP_ERR TxnAbort\n"));
ERRLOG("OLBaidIntraLogGen_GetDetailByTxnId: SP_ERR TxnAbort\n");
                iRet = PD_ERR;
        }
	
	/* EXEC SQL CLOSE :c_cursor_getdetailbytxnid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )147;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getdetailbytxnid;
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
 if (sqlca.sqlcode < 0) goto getdetailbytxnid_error;
}


        /* EXEC SQL FREE :c_cursor_getdetailbytxnid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )166;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getdetailbytxnid;
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
        if (sqlca.sqlcode < 0) goto getdetailbytxnid_error;
}



	return iRet;

getdetailbytxnid_error:
DEBUGLOG(("getdetailbytxnid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBaidIntraLogGen_GetDetailByTxnId: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE :c_cursor_getdetailbytxnid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )185;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getdetailbytxnid;
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


        /* EXEC SQL FREE :c_cursor_getdetailbytxnid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )204;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getdetailbytxnid;
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

int UpdateByStmtTxnId(const hash_t *hIn)
{
	char	cTmp;
	char	*csBuf;
	char	*csBatchId = NULL;
	char	*csStmtTxnId = NULL;
	int	iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_by_stmt_txn_id_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_dynstmt[PD_TMP_MSG_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[2048]; } hv_dynstmt;

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateByStmtTxnId: Begin\n"));

	csBuf = (char*)malloc(PD_TMP_BUF_LEN);

	strcpy((char*)hv_dynstmt.arr, "UPDATE ol_baid_intra_log_gen SET oalg_update_timestamp = SYSDATE");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	/* batch_id */
	if (GetField_CString(hIn, "batch_id", &csBatchId))
	{
DEBUGLOG(("- batch_id = [%s]\n", csBatchId));
	}
	else
	{
		FREE_ME(csBuf);
DEBUGLOG(("UpdateByStmtTxnId: batch_id not found\n"));

		return PD_ERR;
	}

	/* stmt_txn_id */
	if (GetField_CString(hIn, "stmt_txn_id", &csStmtTxnId))
	{
DEBUGLOG(("- stmt_txn_id = [%s]\n", csStmtTxnId));
	}
	else
	{
		FREE_ME(csBuf);
DEBUGLOG(("UpdateByStmtTxnId: stmt_txn_id not found\n"));

		return PD_ERR;
	}

	/* status */
	if (GetField_Char(hIn, "status", &cTmp))
	{
		sprintf(csBuf, "%c", cTmp);
		strcat((char*)hv_dynstmt.arr, ", oalg_status = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- status = [%c]\n", cTmp));
	}

	/* gen_txn_id_fr */
	if (GetField_CString(hIn, "gen_txn_id_fr", &csBuf))
	{
		strcat((char*)hv_dynstmt.arr, ", oalg_gen_txn_id_fr = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- gen_txn_id_fr = [%s]\n", csBuf));
	}

	/* gen_txn_id_to */
	if (GetField_CString(hIn, "gen_txn_id_to", &csBuf))
	{
		strcat((char*)hv_dynstmt.arr, ", oalg_gen_txn_id_to = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- gen_txn_id_to = [%s]\n", csBuf));
	}

	/* ret_code */
	if (GetField_Int(hIn, "ret_code", &iTmp))
	{
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", oalg_ret_code = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- ret_code = [%d]\n", iTmp));
	}

	/* update_user */
	if (GetField_CString(hIn, "update_user", &csBuf))
	{
		strcat((char*)hv_dynstmt.arr, ", oalg_update_user = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- update_user = [%s]\n", csBuf));
	}

	/* batch_id / stmt_txn_id */
	strcat((char*)hv_dynstmt.arr, " WHERE oalg_batch_id = ");
	strcat((char*)hv_dynstmt.arr, csBatchId);
	strcat((char*)hv_dynstmt.arr, " AND oalg_stmt_txn_id = '");
	strcat((char*)hv_dynstmt.arr, csStmtTxnId);
	strcat((char*)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- SQL = [%.*s]\n", hv_dynstmt.len, hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )223;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
 sqlstm.sqhstl[0] = (unsigned long )2050;
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
 if (sqlca.sqlcode < 0) goto update_by_stmt_txn_id_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )242;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto update_by_stmt_txn_id_error;
}



	FREE_ME(csBuf);

DEBUGLOG(("UpdateByStmtTxnId: Normal Exit\n"));
	return PD_OK;

update_by_stmt_txn_id_error:
DEBUGLOG(("update_by_stmt_txn_id_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLBaidIntraLogGen_UpdateByStmtTxnId: SP_INTERNAL_ERR\n");
DEBUGLOG(("UpdateByStmtTxnId: SP_INTERNAL_ERR\n"));
	return PD_ERR;
}

int UpdateByTxnId(const hash_t *hIn)
{
	int     iRet = PD_OK;

	int	iTmp;
	char	cTmp;	
	char	*csTxnSeq = NULL;
        char    *csBuf;

        /* EXEC SQL WHENEVER SQLERROR GOTO updatebytxnid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateByTxnId: Begin\n"));

	csBuf = (char *)malloc(PD_TMP_BUF_LEN);

	strcpy((char *)hv_dynstmt.arr, "UPDATE ol_baid_intra_log_gen SET oalg_update_timestamp = SYSDATE");
        hv_dynstmt.len = strlen((const char *)hv_dynstmt.arr);

/* txn_id */
        if (GetField_CString(hIn,"txn_id", &csTxnSeq))
        {
DEBUGLOG(("UpdateByTxnId: txn_id = [%s]\n", csTxnSeq));
        } else {
DEBUGLOG(("UpdateByTxnId: txn_id is missing\n"));
ERRLOG("OLBaidIntraLogGen: UpdateByTxnId: txn_id is missing\n");
		FREE_ME(csBuf);
                return PD_ERR;
        }

/* status */
        if (GetField_Char(hIn,"status", &cTmp))
        {
DEBUGLOG(("UpdateByTxnId: status = [%c]\n", cTmp));
		sprintf(csBuf, "%c", cTmp);
                strcat((char*)hv_dynstmt.arr, ", oalg_status = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* ret_code */
        if (GetField_Int(hIn, "ret_code", &iTmp))
        {
DEBUGLOG(("UpdateByTxnId: ret_code = [%d]\n", iTmp));
                sprintf(csBuf, "%d", iTmp);
                strcat((char*)hv_dynstmt.arr, ", oalg_ret_code = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* update_user */
        if (GetField_CString(hIn,"update_user", &csBuf))
        {
DEBUGLOG(("UpdateByTxnId: update_user = [%s]\n", csBuf));
                strcat((char*)hv_dynstmt.arr, ", oalg_update_user = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        /* txn_id */
        strcat((char *)hv_dynstmt.arr, " WHERE (oalg_gen_txn_id_fr = '");
        strcat((char *)hv_dynstmt.arr, csTxnSeq);
        strcat((char *)hv_dynstmt.arr, "'");
        strcat((char *)hv_dynstmt.arr, " OR oalg_gen_txn_id_to = '");
	strcat((char *)hv_dynstmt.arr, csTxnSeq);
        strcat((char *)hv_dynstmt.arr, "')");
	strcat((char *)hv_dynstmt.arr, " AND oalg_status = 'A' AND oalg_ret_code = 0");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n", hv_dynstmt.len, hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )257;
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
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )276;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto updatebytxnid_error;
}



        FREE_ME(csBuf);

DEBUGLOG(("UpdateByTxnId: Normal Exit\n"));
        return iRet;

updatebytxnid_error:
DEBUGLOG(("updatebytxnid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLBaidIntraLogGen_UpdateByTxnId: SP_INTERNAL_ERR\n");
DEBUGLOG(("UpdateByTxnId: SP_INTERNAL_ERR\n"));
        return PD_ERR;
}
