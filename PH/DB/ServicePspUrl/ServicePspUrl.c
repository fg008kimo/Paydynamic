
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
           char  filnam[17];
};
static struct sqlcxp sqlfpn =
{
    16,
    "ServicePspUrl.pc"
};


static unsigned int sqlctx = 5168955;


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

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,197,0,6,97,0,0,5,5,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
40,0,0,2,121,0,6,168,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
67,0,0,3,192,0,6,273,0,0,5,5,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
102,0,0,0,0,0,56,370,0,0,1,1,0,1,0,3,102,0,0,
121,0,0,4,163,0,6,371,0,0,5,5,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,2,102,0,0,
156,0,0,0,0,0,13,389,0,0,2,1,0,1,0,1,102,0,0,2,9,0,0,
179,0,0,0,0,0,15,402,0,0,1,1,0,1,0,1,102,0,0,
198,0,0,0,0,0,78,403,0,0,1,1,0,1,0,3,102,0,0,
217,0,0,0,0,0,15,411,0,0,1,1,0,1,0,1,102,0,0,
236,0,0,0,0,0,78,412,0,0,1,1,0,1,0,3,102,0,0,
255,0,0,5,120,0,4,451,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
282,0,0,6,0,0,17,564,0,0,1,1,0,1,0,1,9,0,0,
301,0,0,6,0,0,21,565,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/04/05              [MSN]
PRD332
 - Add Add / Delete / UpdateServicePspUrl          2021/07/29              [ZBL]
 - Add Replicate                                                           [MIC]
 - Add FindServicePspUrl                           2021/08/09              [ZBL]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "ServicePspUrl.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


static char cDebug;

void ServicePspUrl(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const hash_t* hServicePspUrl)
{
	char *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar		hv_service_psp_url[PD_SERVICE_PSP_URL_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_service_psp_url;

		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_psp_id		= -1;
		short		ind_service_code	= -1;
		short		ind_service_psp_url	= -1;
		short		ind_create_user		= -1;

		short		hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

	/* psp_id */
	if (GetField_CString(hServicePspUrl, "psp_id", &csTmp))
	{
		hv_psp_id.len = strlen(csTmp);
		memcpy(hv_psp_id.arr, csTmp, hv_psp_id.len);
		ind_psp_id = 0;

DEBUGLOG(("- psp_id = [%.*s]\n", hv_psp_id.len, hv_psp_id.arr));
	}

	/* service_code */
	if (GetField_CString(hServicePspUrl, "service_code", &csTmp))
	{
		hv_service_code.len = strlen(csTmp);
		memcpy(hv_service_code.arr, csTmp, hv_service_code.len);
		ind_service_code = 0;

DEBUGLOG(("- service_code = [%.*s]\n", hv_service_code.len, hv_service_code.arr));
	}

	/* service_psp_url */
	if (GetField_CString(hServicePspUrl, "service_psp_url", &csTmp))
	{
		hv_service_psp_url.len = strlen(csTmp);
		memcpy(hv_service_psp_url.arr, csTmp, hv_service_psp_url.len);
		ind_service_psp_url = 0;

DEBUGLOG(("- service_psp_url = [%.*s]\n", hv_service_psp_url.len, hv_service_psp_url.arr));
	}

	/* create_user */
	if (GetField_CString(hServicePspUrl, "create_user", &csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		memcpy(hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;

DEBUGLOG(("- create_user = [%.*s]\n", hv_create_user.len, hv_create_user.arr));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_service_psp_url_insert(
				:hv_psp_id:ind_psp_id,
				:hv_service_code:ind_service_code,
				:hv_service_psp_url:ind_service_psp_url,
				:hv_create_user:ind_create_user); 
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_service_psp_url_insert ( :hv_p\
sp_id:ind_psp_id , :hv_service_code:ind_service_code , :hv_service_psp_url:in\
d_service_psp_url , :hv_create_user:ind_create_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_psp_id;
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
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_psp_url;
 sqlstm.sqhstl[3] = (unsigned long )52;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_service_psp_url;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[4] = (unsigned long )22;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto add_error;
}



DEBUGLOG(("Add:Ret = [%d]\n", hv_return_value));

	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("Add:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)
	{
ERRLOG("ServicePspUrl_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)
	{
ERRLOG("ServicePspUrl_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("ServicePspUrl_Add: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int Delete(const char* csPspId, const char* csServiceCode)
{
	int iRet = PD_ERR;

	/* EXEC SQL WHENEVER SQLERROR GOTO delete_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;


		short		ind_psp_id		= -1;
		short		ind_service_code	= -1;

		short		hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


	/* psp_id */
	hv_psp_id.len = strlen(csPspId);
	memcpy(hv_psp_id.arr, csPspId, hv_psp_id.len);
	ind_psp_id = 0;

DEBUGLOG(("- psp_id = [%.*s]\n", hv_psp_id.len, hv_psp_id.arr));

	/* service_code */
	hv_service_code.len = strlen(csServiceCode);
	memcpy(hv_service_code.arr, csServiceCode, hv_service_code.len);
	ind_service_code = 0;

DEBUGLOG(("- service_code = [%.*s]\n", hv_service_code.len, hv_service_code.arr));

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_service_psp_url_delete(
				:hv_psp_id:ind_psp_id, 
				:hv_service_code:ind_service_code);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_service_psp_url_delete ( :hv_p\
sp_id:ind_psp_id , :hv_service_code:ind_service_code ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )40;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_service_code;
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
 if (sqlca.sqlcode < 0) goto delete_error;
}



DEBUGLOG(("Delete: Ret = [%d]\n", hv_return_value));

	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("Delete: Normal Exit\n"));
		iRet = PD_OK;
	}
	else if (hv_return_value == SP_OTHER_ERR)
	{
ERRLOG("ServicePspUrl_Delete: SP_OTHER_ERR\n");
DEBUGLOG(("Delete: SP_OTHER_ERR\n"));
		iRet = PD_OTHER_ERR;
	}
	else if (hv_return_value == SP_ERR)
	{
ERRLOG("ServicePspUrl_Delete: SP_ERR\n");
DEBUGLOG(("Delete: SP_ERR\n"));
	}

	return iRet;

delete_error:
DEBUGLOG(("delete_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("ServicePspUrl_Delete: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("ServicePspUrl_Delete: SP_INTERNAL_ERR\n");
DEBUGLOG(("Delete: SP_INTERNAL_ERR\n"));
	return PD_ERR;
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

		/* varchar         hv_url[PD_VALUE_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_url;

		/* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_replicate_psp_id = -1;
		short		ind_create_psp_id = -1;
		short		ind_url = -1;
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


	if(GetField_CString(hRec,"service_psp_url",&csTmp))
	{
		hv_url.len = strlen(csTmp);
		strncpy((char*)hv_url.arr, csTmp, hv_url.len);
		ind_url = 0;
	}
DEBUGLOG(("Replicate:service_psp_url = [%.*s]\n",hv_url.len,hv_url.arr));



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

		:hv_return_value := sp_service_psp_url_rpl(
				:hv_replicate_psp_id:ind_replicate_psp_id,
				:hv_create_psp_id:ind_create_psp_id,
				:hv_url:ind_url,
				:hv_create_user:ind_create_user
				);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_service_psp_url_rpl ( :hv_repl\
icate_psp_id:ind_replicate_psp_id , :hv_create_psp_id:ind_create_psp_id , :hv\
_url:ind_url , :hv_create_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )67;
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
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_url;
 sqlstm.sqhstl[3] = (unsigned long )52;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_url;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[4] = (unsigned long )22;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto replicate_error;
}




	DEBUGLOG(("Replicate:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
		DEBUGLOG(("Replicate:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
		ERRLOG("PspUrl_Replicate: SP_OTHER_ERR TxnAbort\n");
		DEBUGLOG(("Replicate: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
		ERRLOG("PspUrl_Replicate: SP_ERR TxnAbort\n");
		DEBUGLOG(("Replicate: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}


	if (hv_return_value == SP_NOT_FOUND)  {
		ERRLOG("PspUrl_Replicate: SP_NOT_FOUND TxnAbort\n");
		DEBUGLOG(("Replicate: SP_NOT_FOUND TxnAbort\n"));
		return PD_NOT_FOUND;
	}

replicate_error:
DEBUGLOG(("replicate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("PspUrl_Replicate: SP_INTERNAL_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;


}








int FindURL(const unsigned char* csServiceCode,
	    const unsigned char* csPspId,
                unsigned char* csURL)
{
	int iRet = NOT_FOUND;
	hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO find_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		short           hv_return_value;

                /* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		int	hv_disabled;

                /* varchar v_url[PD_VALUE_LEN +1 ]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_url;


		SQL_CURSOR      c_cursor_urldt;

                short   ind_url = -1;
                short   ind_service_code = -1;
                short   ind_psp_id = -1;
                short   ind_disabled = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_service_code.len = strlen((const char*)csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("FindURL: csServiceCode = [%.*s]\n",hv_service_code.len,hv_service_code.arr)); 
        ind_service_code = 0;

	hv_psp_id.len = strlen((const char*)csPspId);
        memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);
DEBUGLOG(("FindURL: psp_id = [%.*s]\n",hv_psp_id.len,hv_psp_id.arr));
        ind_psp_id = 0;

	hv_disabled=0;
        ind_disabled = 0;

	/* EXEC SQL ALLOCATE       :c_cursor_urldt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )102;
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
 if (sqlca.sqlcode < 0) goto find_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_service_psp_geturl(:hv_service_code:ind_service_code,
                                                                 :hv_psp_id:ind_psp_id,
								 :hv_disabled:ind_disabled,
                                                                 :c_cursor_urldt);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_service_psp_geturl ( :h\
v_service_code:ind_service_code , :hv_psp_id:ind_psp_id , :hv_disabled:ind_di\
sabled , :c_cursor_urldt ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )121;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_service_code;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_psp_id;
        sqlstm.sqhstl[2] = (unsigned long )12;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_psp_id;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_disabled;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_disabled;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&c_cursor_urldt;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode < 0) goto find_error;
}



	if (hv_return_value > 0)  {
DEBUGLOG(("Find Found\n"));
                for (;;) {
                        myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);

                        ind_url = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_urldt
                        INTO
                                :v_url:ind_url; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 5;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )156;
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
                        if (sqlca.sqlcode < 0) goto find_error;
}



			if (ind_url >= 0) {
                        	v_url.arr[v_url.len] = '\0';
                        	strcpy((char*)csURL,(const char*)v_url.arr);
				iRet = FOUND;
DEBUGLOG(("URL = [%s]\n",csURL));
			}
		}
	}
	
	/* EXEC SQL CLOSE :c_cursor_urldt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )179;
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
 if (sqlca.sqlcode < 0) goto find_error;
}


	/* EXEC SQL FREE :c_cursor_urldt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )198;
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
 if (sqlca.sqlcode < 0) goto find_error;
}



DEBUGLOG(("RET = [%d]\n",iRet));
	return iRet;

find_error:
DEBUGLOG(("find_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL CLOSE :c_cursor_urldt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )217;
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
 if (sqlca.sqlcode < 0) goto find_error;
}


	/* EXEC SQL FREE :c_cursor_urldt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )236;
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
 if (sqlca.sqlcode < 0) goto find_error;
}


    	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    	return NOT_FOUND;
}

int FindServicePspUrl(const unsigned char* csServiceCode, const unsigned char* csPspId)
{
	int iRet = PD_NOT_FOUND;

	/* EXEC SQL WHENEVER SQLERROR GOTO find_service_psp_url_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar		hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;


		int		v_count;

		short		ind_service_code	= -1;
		short		ind_psp_id		= -1;
		short		ind_count		= -1;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("FindServicePspUrl: Begin\n"));

	/* service_code */
	hv_service_code.len = strlen((const char*)csServiceCode);
	memcpy(hv_service_code.arr, csServiceCode, hv_service_code.len);
	ind_service_code = 0;

DEBUGLOG(("- service_code = [%.*s]\n", hv_service_code.len, hv_service_code.arr));

	/* psp_id */
	hv_psp_id.len = strlen((const char*)csPspId);
	memcpy(hv_psp_id.arr, csPspId, hv_psp_id.len);
	ind_psp_id = 0;

DEBUGLOG(("- psp_id = [%.*s]\n", hv_psp_id.len, hv_psp_id.arr));

	/* EXEC SQL 
		SELECT	COUNT(*) 
		INTO	:v_count:ind_count 
		FROM	SERVICE_PSP_URL 
		WHERE	PU_SERVICE_CODE = :hv_service_code AND 
			PU_PSP_ID = :hv_psp_id AND 
			PU_DISABLED = 0; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select COUNT ( * ) INTO :b0:b1 FROM SERVICE_PSP_URL WHERE P\
U_SERVICE_CODE = :b2 AND PU_PSP_ID = :b3 AND PU_DISABLED = 0 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )255;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_count;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_count;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[2] = (unsigned long )12;
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
 if (sqlca.sqlcode < 0) goto find_service_psp_url_error;
}



	/* count */
	if (ind_count >= 0)
	{
		if (v_count > 0)
		{
DEBUGLOG(("FindServicePspUrl: Normal Exit\n"));
			iRet = PD_FOUND;
		}
		else
		{
DEBUGLOG(("FindServicePspUrl: Normal Exit, Not Found\n"));
		}
	}

	return iRet;

find_service_psp_url_error:
DEBUGLOG(("find_service_psp_url_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("ServicePspUrl_FindServicePspUrl: SP_INTERNAL_ERR\n");
DEBUGLOG(("ServicePspUrl: SP_INTERNAL_ERR\n"));
	return PD_ERR;
}

int UpdateServicePspUrl(const hash_t* hServicePspUrl)
{
	char	*csBuf;
	char	*csPspId;
	char	*csServiceCode;
	char	*csTmp;
	int	iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_service_psp_url_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_dynstmt[PD_TMP_MSG_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[2048]; } hv_dynstmt;

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateServicePspUrl: Begin\n"));

	csBuf = (char*)malloc(PD_TMP_BUF_LEN);

	strcpy((char*)hv_dynstmt.arr, "UPDATE service_psp_url SET pu_update_timestamp = SYSDATE");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	/* psp_id */
	if (GetField_CString(hServicePspUrl, "psp_id", &csPspId))
	{
DEBUGLOG(("- psp_id = [%s]\n", csPspId));
	}
	else
	{
		FREE_ME(csBuf);
DEBUGLOG(("UpdateServicePspUrl: psp_id not found\n"));

		return PD_ERR;
	}

	/* service_code */
	if (GetField_CString(hServicePspUrl, "service_code", &csServiceCode))
	{
DEBUGLOG(("- service_code = [%s]\n", csServiceCode));
	}
	else
	{
		FREE_ME(csBuf);
DEBUGLOG(("UpdateServicePspUrl: service_code not found\n"));

		return PD_ERR;
	}

	/* service_psp_url */
	if (GetField_CString(hServicePspUrl, "service_psp_url", &csTmp))
	{
		strcat((char*)hv_dynstmt.arr, ", pu_url = '");
		strcat((char*)hv_dynstmt.arr, ESC_string(csTmp));
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- service_psp_url = [%s]\n", csTmp));
	}

	/* update_user */
	if (GetField_CString(hServicePspUrl, "update_user", &csTmp))
	{
		strcat((char*)hv_dynstmt.arr, ", pu_update_user = '");
		strcat((char*)hv_dynstmt.arr, ESC_string(csTmp));
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- update_user = [%s]\n", csTmp));
	}

	/* psp_id / service_code */
	strcat((char*)hv_dynstmt.arr, " WHERE pu_psp_id = '");
	strcat((char*)hv_dynstmt.arr, ESC_string(csPspId));
	strcat((char *)hv_dynstmt.arr, "' AND pu_service_code = '");
	strcat((char *)hv_dynstmt.arr, ESC_string(csServiceCode));
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
 sqlstm.offset = (unsigned int  )282;
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
 if (sqlca.sqlcode < 0) goto update_service_psp_url_error;
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
 sqlstm.offset = (unsigned int  )301;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto update_service_psp_url_error;
}



	FREE_ME(csBuf);

DEBUGLOG(("UpdateServicePspUrl: Normal Exit\n"));
	return iRet;

update_service_psp_url_error:
DEBUGLOG(("update_service_psp_url_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("ServicePspUrl_UpdateServicePspUrl: SP_INTERNAL_ERR\n");
DEBUGLOG(("UpdateServicePspUrl: SP_INTERNAL_ERR\n"));
	return PD_ERR;
}
