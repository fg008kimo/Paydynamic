
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
    "TestNini.pc"
};


static unsigned int sqlctx = 162915;


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
   unsigned char  *sqhstv[7];
   unsigned long  sqhstl[7];
            int   sqhsts[7];
            short *sqindv[7];
            int   sqinds[7];
   unsigned long  sqharm[7];
   unsigned long  *sqharc[7];
   unsigned short  sqadto[7];
   unsigned short  sqtdso[7];
} sqlstm = {12,7};

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

 static char *sq0002 = 
"SELECT tn_service_code , tn_sys_support , tn_daily_limit , tn_desc FROM tes\
t_nini WHERE tn_txn_code = :b0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,144,0,4,61,0,0,5,2,0,1,0,2,3,0,0,2,4,0,0,2,9,0,0,1,9,0,0,1,9,0,0,
40,0,0,2,117,0,9,147,0,2049,1,1,0,1,0,1,9,0,0,
59,0,0,2,0,0,13,150,0,0,4,0,0,1,0,2,9,0,0,2,3,0,0,2,4,0,0,2,9,0,0,
90,0,0,2,0,0,15,196,0,0,0,0,0,1,0,
105,0,0,3,227,0,6,295,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,3,0,0,1,
9,0,0,1,9,0,0,
148,0,0,4,0,0,17,423,0,0,1,1,0,1,0,1,9,0,0,
167,0,0,4,0,0,21,424,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2019/11/14              Caroline Yeh
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "TestNini.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "internal.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;


void TestNini(char cdebug){
	cDebug = cdebug;
}

int GetDetail(const char* csTxnCode, const char* csServiceCode, hash_t * hRec)
{

	/* EXEC SQL WHENEVER SQLERROR GOTO getdetail_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;


		int		    v_sys_support;
		double		v_daily_limit;
		/* varchar		v_desc[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_desc;


		short		ind_sys_support = -1;
		short		ind_daily_limit = -1;
		short		ind_desc = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	/* txn_code */
	hv_txn_code.len = strlen(csTxnCode);
	memcpy(hv_txn_code.arr, csTxnCode, hv_txn_code.len);
DEBUGLOG(("GetDetail: csTxnCode = [%.*s]\n", hv_txn_code.len, hv_txn_code.arr));


    /* service_code */
    	hv_service_code.len = strlen(csServiceCode);
    	memcpy(hv_service_code.arr, csServiceCode, hv_service_code.len);
DEBUGLOG(("GetDetail: csServiceCode = [%.*s]\n", hv_service_code.len, hv_service_code.arr));

	/* EXEC SQL SELECT tn_sys_support,
			tn_daily_limit,
			tn_desc
		INTO	:v_sys_support:ind_sys_support,
			:v_daily_limit:ind_daily_limit,
			:v_desc:ind_desc
		FROM test_nini
		WHERE tn_txn_code = :hv_txn_code AND tn_service_code = :hv_service_code; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select tn_sys_support , tn_daily_limit , tn_desc INTO :b0:b\
1 , :b2:b3 , :b4:b5 FROM test_nini WHERE tn_txn_code = :b6 AND tn_service_cod\
e = :b7 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_sys_support;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_sys_support;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_daily_limit;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_daily_limit;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_desc;
 sqlstm.sqhstl[2] = (unsigned long )53;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_desc;
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
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto getdetail_error;
}




		/* flag */
		if (ind_sys_support >= 0)
		{
DEBUGLOG(("GetDetail sys_support = [%d]\n", v_sys_support));
			PutField_Int(hRec, "sys_support", v_sys_support);
		}else{
				return PD_NOT_FOUND;
		}

		/* daily_limit */
		if (ind_daily_limit >= 0)
		{
DEBUGLOG(("GetDetail daily_limit = [%lf]\n", ind_daily_limit));
			PutField_Double(hRec, "daily_limit", v_daily_limit);
		}else{
         				return PD_NOT_FOUND;
         		}

		/* desc */
		if (ind_desc >= 0)
		{
			v_desc.arr[v_desc.len] = '\0';
DEBUGLOG(("GetDetail desc = [%s]\n", v_desc.arr));
			PutField_CString(hRec, "desc", (const char *)v_desc.arr);
		}else{
       			return PD_NOT_FOUND;
       		}

DEBUGLOG(("GetDetail Normal Exit\n"));
		return PD_FOUND;


getdetail_error:
DEBUGLOG(("getbytxncode_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;


}
int GetDetailByTxnCode(const char* csTxnCode,   recordset_t * myRec)
{



	/* EXEC SQL WHENEVER SQLERROR GOTO get_detail_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_txn_code[PD_TXN_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_txn_code;

		/* varchar         v_service_code[PD_SERVICE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		int             v_sys_support;
		double          v_daily_limit;
		/* varchar         v_desc[PD_DESC_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } v_desc;

		
		short		ind_service_code = -1;
		short		ind_sys_support = -1;
		short		ind_daily_limit = -1;
		short		ind_desc = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hash_t  * myHash;
	int	iCnt = 0;
/* txn_code */
	hv_txn_code.len = strlen(csTxnCode);
	memcpy(hv_txn_code.arr, csTxnCode, hv_txn_code.len);
DEBUGLOG(("GetDetailByTxnCode: csTxnCode = [%.*s]\n", hv_txn_code.len, hv_txn_code.arr));

	/* EXEC SQL DECLARE c_cursor_getdetail CURSOR FOR 
		SELECT  tn_service_code, 
			tn_sys_support, 
			tn_daily_limit, 
			tn_desc
		FROM test_nini
		WHERE tn_txn_code = :hv_txn_code; */ 


	/* EXEC SQL OPEN c_cursor_getdetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )40;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_txn_code;
 sqlstm.sqhstl[0] = (unsigned long )6;
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
 if (sqlca.sqlcode < 0) goto get_detail_error;
}


	do
	{
		/* EXEC SQL FETCH c_cursor_getdetail
			INTO	:v_service_code:ind_service_code, 
				:v_sys_support:ind_sys_support, 
				:v_daily_limit:ind_daily_limit, 
				:v_desc:ind_desc; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 5;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )59;
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
  sqlstm.sqhstv[1] = (unsigned char  *)&v_sys_support;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_sys_support;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_daily_limit;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_daily_limit;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_desc;
  sqlstm.sqhstl[3] = (unsigned long )52;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_desc;
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
  if (sqlca.sqlcode < 0) goto get_detail_error;
}



		if (SQLCODE == SQL_NOT_FOUND)
			break;

		myHash = (hash_t *)malloc(sizeof(hash_t));
		hash_init(myHash, 0);
		
		/* service_code */
		if (ind_service_code >= 0)
		{
			v_service_code.arr[v_service_code.len] = '\0';
DEBUGLOG(("GetDetailByTxnCode service_code = [%s]\n", v_service_code.arr));
			PutField_CString(myHash, "service_code", (const char *)v_service_code.arr);
		}

		/* sys_support */
		if (ind_sys_support >= 0)
		{
DEBUGLOG(("GetDetailByTxnCode sys_support = [%d]\n", v_sys_support));
			PutField_Int(myHash, "sys_support", v_sys_support);
		}

		/* daily_limit */
		if (ind_daily_limit >= 0)
		{
DEBUGLOG(("GetDetailByTxnCode daily_limit = [%lf]\n", v_daily_limit));
			PutField_Double(myHash, "daily_limit", v_daily_limit);
		}

		/* desc */
		if (ind_desc >= 0)
		{
			v_desc.arr[v_desc.len] = '\0';
DEBUGLOG(("GetDetailByTxnCode desc = [%s]\n", v_desc.arr));
			PutField_CString(myHash, "desc", (const char *)v_desc.arr);
		}	


		iCnt++;
		RecordSet_Add(myRec, myHash);
	} while (PD_TRUE);
	/* EXEC SQL CLOSE c_cursor_getdetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )90;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto get_detail_error;
}



	if (iCnt > 0)
	{
DEBUGLOG(("GetDetailByTxnCode Normal Exit\n"));
		return PD_FOUND;
	}
	else
	{
DEBUGLOG(("GetDetailByTxnCode Normal Exit, Not Found\n"));
		return PD_NOT_FOUND;
	}

get_detail_error:
DEBUGLOG(("get_detail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("TestNini_Get: SP_INTERNAL_ERR\n");
/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;

}




int     Add(const hash_t *hRls)
{
        char            *csTmp;
        int             iTmp;
        double          dTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                /* varchar         hv_desc[PD_DESC_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_desc;

                int             hv_sys_support;
                double          hv_daily_limit;
                /* varchar         hv_user[PD_USER_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_user;


		short           ind_txn_code = -1;
		short		ind_service_code = -1;
		short		ind_desc = -1;
		short		ind_sys_support = -1;
		short		ind_daily_limit = -1;
		short		ind_user = -1;

		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



	DEBUGLOG(("Add: Begin\n"));

	/*txn_code*/
        if(GetField_CString(hRls,"txn_code",&csTmp)){
                hv_txn_code.len = strlen(csTmp);
                memcpy(hv_txn_code.arr, csTmp, hv_txn_code.len);
                ind_txn_code = 0;
DEBUGLOG(("Add: txn_code = [%c]\n", hv_txn_code));
        }

	/*service_code*/
        if(GetField_CString(hRls,"service_code",&csTmp)){
                hv_service_code.len = strlen(csTmp);
                memcpy(hv_service_code.arr, csTmp, hv_service_code.len);
                ind_service_code= 0;
DEBUGLOG(("Add:service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));
        }

	/*sys_support*/
        if (GetField_Int(hRls,"sys_support",&iTmp)) {
                hv_sys_support = iTmp;
                ind_sys_support = 0;
		DEBUGLOG(("Add:sys_support = [%d]\n",hv_sys_support));
        }

	/*daily_limit*/
        if (GetField_Double(hRls,"daily_limit",&dTmp)) {
                hv_daily_limit= dTmp;
                ind_daily_limit= 0;
		DEBUGLOG(("Add:daily_limit = [%lf]\n",hv_daily_limit));
        }

	/*desc*/
        if(GetField_CString(hRls,"desc",&csTmp)){
                hv_desc.len = strlen(csTmp);
                memcpy(hv_desc.arr, csTmp, hv_desc.len);
                ind_desc= 0;
DEBUGLOG(("Add:desc = [%.*s]\n",hv_desc.len,hv_desc.arr));
	}
	/*user*/
        if(GetField_CString(hRls,"add_user",&csTmp)){
                hv_user.len = strlen(csTmp);
                memcpy(hv_user.arr, csTmp, hv_user.len);
                ind_user= 0;
		DEBUGLOG(("Add:user = [%.*s]\n",hv_user.len,hv_user.arr));
        }
	/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_test_nini_insert(
                                        :hv_txn_code:ind_txn_code,
                                        :hv_service_code:ind_service_code,
                                        :hv_daily_limit:ind_daily_limit,
                                        :hv_sys_support:ind_sys_support,
                                        :hv_desc:ind_desc,
					:hv_user:ind_user
                                        );
                END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_test_nini_insert ( :hv_txn_cod\
e:ind_txn_code , :hv_service_code:ind_service_code , :hv_daily_limit:ind_dail\
y_limit , :hv_sys_support:ind_sys_support , :hv_desc:ind_desc , :hv_user:ind_\
user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )105;
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
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_daily_limit;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_daily_limit;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_sys_support;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_sys_support;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_desc;
 sqlstm.sqhstl[5] = (unsigned long )52;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_desc;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_user;
 sqlstm.sqhstl[6] = (unsigned long )23;
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
 if (sqlca.sqlcode < 0) goto add_error;
}



	DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
                DEBUGLOG(("Add:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
                ERRLOG("TestNini_Add: SP_OTHER_ERR \n");
                DEBUGLOG(("Add: SP_OTHER_ERR \n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
                ERRLOG("TestNini_Add: SP_ERR \n");
                DEBUGLOG(("Add: SP_ERR \n"));
                return PD_ERR;
        }

	add_error:
		DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
		DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
		ERRLOG("TestNini_Add: SP_INTERNAL_ERR \n");
        	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        	return PD_ERR;

}


int Update(const hash_t *hRls)
{
	char*   csBuf;
	int	iTmp = 0;
	double	dTmp = 0.0;
	char* csTxnCode;
	char* csServiceCode;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar		hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


	/* EXEC SQL END DECLARE SECTION; */ 



	DEBUGLOG(("Update: Begin\n"));
        csBuf = (char*) malloc (255);
        strcpy((char*)hv_dynstmt.arr,"update test_nini set tn_update_timestamp = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	/* txn_code */
	if (GetField_CString(hRls, "txn_code", &csTxnCode))
	{
DEBUGLOG(("Update: txn_code = [%s]\n", csTxnCode));
	}
	else
	{
		FREE_ME(csBuf);
DEBUGLOG(("Update txn_code not found\n"));
		return PD_NOT_FOUND;
	}


	/* service_code */
	if (GetField_CString(hRls, "service_code", &csServiceCode))
	{
DEBUGLOG(("Update: service_code = [%s]\n", csServiceCode));
	}
	else
	{
		FREE_ME(csBuf);
DEBUGLOG(("Update service_code not found\n"));
		return PD_NOT_FOUND;
	}

	if(GetField_Int(hRls,"sys_support",&iTmp)){
		DEBUGLOG(("Update:sys_support = [%d]\n",iTmp));
		sprintf(csBuf,"%d",iTmp);
		strcat((char*)hv_dynstmt.arr, ",tn_sys_support =");
		strcat((char*)hv_dynstmt.arr, csBuf);
	}

	if(GetField_Double(hRls,"daily_limit",&dTmp)){
		DEBUGLOG(("Update:daily_limit = [%lf]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",tn_daily_limit =");
		strcat((char*)hv_dynstmt.arr, csBuf);
	}

	if(GetField_CString(hRls,"desc",&csBuf)){
		DEBUGLOG(("Update:desc = [%s]\n",csBuf));
		strcat((char*)hv_dynstmt.arr, ",tn_desc = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
	}

	if(GetField_CString(hRls,"update_user",&csBuf)){
		DEBUGLOG(("Update: update_user = [%s]\n",csBuf));
		strcat((char*)hv_dynstmt.arr, ",tn_update_user= '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
	}

	strcat((char*)hv_dynstmt.arr, " WHERE tn_txn_code = '");
	strcat((char*)hv_dynstmt.arr, csTxnCode);
	strcat((char*)hv_dynstmt.arr, "' and tn_service_code = '");
	strcat((char*)hv_dynstmt.arr, csServiceCode);
	strcat((char*)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));


	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )148;
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
 if (sqlca.sqlcode < 0) goto update_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )167;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto update_error;
}



	FREE_ME(csBuf);

	DEBUGLOG(("Update Normal Exit\n"));
        return PD_OK;

	update_error:
		DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
		DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
		ERRLOG("Test_Nini_Update: SP_INTERNAL_ERR\n");
	        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        	return PD_INTERNAL_ERR;
}

