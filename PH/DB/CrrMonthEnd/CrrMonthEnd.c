
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
    "CrrMonthEnd.pc"
};


static unsigned int sqlctx = 1211707;


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

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,199,0,6,87,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,9,0,
0,
44,0,0,2,0,0,17,185,0,0,1,1,0,1,0,1,9,0,0,
63,0,0,2,0,0,21,186,0,0,0,0,0,1,0,
78,0,0,2,0,0,17,243,0,0,1,1,0,1,0,1,9,0,0,
97,0,0,2,0,0,21,244,0,0,0,0,0,1,0,
112,0,0,3,156,0,6,285,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,
};


/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/05/19              Simon Fung
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "CrrMonthEnd.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;
void CrrMonthEnd(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const char* csTbYear, const char* csTbMonth, const int iClosed, const int iDisabled, const char* csCreateUser)
{
	/*
	char	*csTmp;
	char  cTmp;
	int		iTmp;
	*/
	
  /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

  /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


  /* EXEC SQL BEGIN DECLARE SECTION; */ 


  short 		hv_return_value;
	/* varchar		hv_tb_year[PD_ACC_YEAR_LEN]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_tb_year;

	/* varchar		hv_tb_month[PD_ACC_MONTH_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_tb_month;

	int				hv_closed;	
	int				hv_disabled;	
	/* varchar		hv_create_user[PD_CREATE_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;
	

	short		ind_tb_year = -1;
	short		ind_tb_month = -1;
	short		ind_closed = -1;
	short		ind_disabled = -1;
	short		ind_create_user = -1;

  /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

	/* Tb year */
	hv_tb_year.len = strlen(csTbYear);
	memcpy(hv_tb_year.arr,csTbYear,hv_tb_year.len);
	ind_tb_year = 0;
DEBUGLOG(("Add:tb_year = [%.*s]\n",hv_tb_year.len,hv_tb_year.arr));

	/* Tb month */
	hv_tb_month.len = strlen(csTbMonth);
	memcpy(hv_tb_month.arr,csTbMonth,hv_tb_month.len);
	ind_tb_month = 0;
DEBUGLOG(("Add:tb_month = [%.*s]\n",hv_tb_month.len,hv_tb_month.arr));

	/* closed */
	hv_closed = iClosed;
	ind_closed = 0;
DEBUGLOG(("Add:closed = [%d]\n",hv_closed));
	
	/* disabled */
	hv_disabled = iDisabled;
	ind_disabled = 0;
DEBUGLOG(("Add:disabled = [%d]\n",hv_disabled));
	
	/* create_user */
	hv_create_user.len = strlen(csCreateUser);
	memcpy(hv_create_user.arr,csCreateUser,hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));

	/* EXEC SQL EXECUTE BEGIN
			:hv_return_value := sp_crr_month_end_insert(
			:hv_tb_year:ind_tb_year,
			:hv_tb_month:ind_tb_month,
			:hv_closed:ind_closed,
			:hv_disabled:ind_disabled,
			:hv_create_user:ind_create_user
				);
				END;
				END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_crr_month_end_insert ( :hv_tb_\
year:ind_tb_year , :hv_tb_month:ind_tb_month , :hv_closed:ind_closed , :hv_di\
sabled:ind_disabled , :hv_create_user:ind_create_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_tb_year;
 sqlstm.sqhstl[1] = (unsigned long )6;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_tb_year;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_tb_month;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_tb_month;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_closed;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_closed;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_disabled;
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
 if (sqlca.sqlcode < 0) goto add_error;
}



DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
    
  if (hv_return_value == SP_OK) {
DEBUGLOG(("Add:Normal Exit\n"));
    return PD_OK;
  }

  if (hv_return_value == SP_OTHER_ERR)  {
		ERRLOG("CrrMonthEnd_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
    return PD_OTHER_ERR;
  }

  if (hv_return_value == SP_ERR)  {
		ERRLOG("CrrMonthEnd_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
    return PD_ERR;
  }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	ERRLOG("CrrMonthEnd: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_INTERNAL_ERR TxnAbort\n"));
  return PD_INTERNAL_ERR;
}

int Update(const char* csTbYear, const char* csTbMonth, const int iClosed, const int iDisabled, const char* csUpdateUser)
{
	/*
	char*	csTmp;
	*/
	char*	csBuf;
	//char*	csJnlId;
  
  
  /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

  /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


  /* EXEC SQL BEGIN DECLARE SECTION; */ 


	/* varchar 	hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


  /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
	csBuf = (char*) malloc (128);
	strcpy((char*)hv_dynstmt.arr,"update crr_month_end set update_timestamp = sysdate");

DEBUGLOG(("Update:tb_year = [%s]\n",csTbYear));
DEBUGLOG(("Update:tb_month = [%s]\n",csTbMonth));
DEBUGLOG(("Update:closed = [%d]\n",iClosed));
DEBUGLOG(("Update:disabled = [%d]\n",iDisabled));
DEBUGLOG(("Update:update_user = [%s]\n",csUpdateUser));

	/* closed  */
DEBUGLOG(("Update:closed = [%d]\n",iClosed));
	sprintf(csBuf,"%d",iClosed);
	strcat((char*)hv_dynstmt.arr, ",closed = ");
	strcat((char*)hv_dynstmt.arr, csBuf);
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	
	/* disabled  */
DEBUGLOG(("Update:disabled = [%d]\n",iDisabled));
	sprintf(csBuf,"%d",iDisabled);
	strcat((char*)hv_dynstmt.arr, ",disabled = ");
	strcat((char*)hv_dynstmt.arr, csBuf);
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	
	/* update_user */
DEBUGLOG(("Update:update_user = [%s]\n",csUpdateUser));
	strcat((char*)hv_dynstmt.arr, ",update_user = '");
	strcat((char*)hv_dynstmt.arr, csUpdateUser);
	strcat((char*)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	
	strcat((char *)hv_dynstmt.arr, " WHERE tb_year = '");
  strcat((char *)hv_dynstmt.arr, csTbYear);
  strcat((char *)hv_dynstmt.arr, "'");
	strcat((char *)hv_dynstmt.arr, " AND tb_month = '");
  strcat((char *)hv_dynstmt.arr, csTbMonth);
  strcat((char *)hv_dynstmt.arr, "'");  
 	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )44;
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
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )63;
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
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	ERRLOG("CrrMonthEnd_Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Delete: SP_INTERNAL_ERR TxnAbort\n"));
	return PD_INTERNAL_ERR;
}

int Delete(const char* csTbYear, const char* csTbMonth, const char* csUpdateUser)
{

	//char*	csTmp;
	char*	csBuf;
	//char*	csJnlId;
  
  /* EXEC SQL WHENEVER SQLERROR GOTO delete_error; */ 

  /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


  /* EXEC SQL BEGIN DECLARE SECTION; */ 


	/* varchar 	hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


  /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Delete: Begin\n"));
	csBuf = (char*) malloc (128);
	strcpy((char*)hv_dynstmt.arr,"update crr_month_end set update_timestamp = sysdate, disabled = 0");

DEBUGLOG(("Delete:tb_year = [%s]\n",csTbYear));
DEBUGLOG(("Delete:tb_month = [%s]\n",csTbMonth));
DEBUGLOG(("Delete:update_user = [%s]\n",csUpdateUser));
	
		/* update_user */
DEBUGLOG(("Update:update_user = [%s]\n",csUpdateUser));
	strcat((char*)hv_dynstmt.arr, ",update_user = '");
	strcat((char*)hv_dynstmt.arr, csUpdateUser);
	strcat((char*)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	
	strcat((char *)hv_dynstmt.arr, " WHERE tb_year = '");
  strcat((char *)hv_dynstmt.arr, csTbYear);
  strcat((char *)hv_dynstmt.arr, "'");
	strcat((char *)hv_dynstmt.arr, " AND tb_month = '");
  strcat((char *)hv_dynstmt.arr, csTbMonth);
  strcat((char *)hv_dynstmt.arr, "'");  
 	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )78;
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
 if (sqlca.sqlcode < 0) goto delete_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )97;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto delete_error;
}



	FREE_ME(csBuf);

DEBUGLOG(("Delete Normal Exit\n"));
	return PD_OK;

delete_error:
DEBUGLOG(("delete_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	ERRLOG("CrrMonthEnd_Delete: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Delete: SP_INTERNAL_ERR TxnAbort\n"));
	return PD_INTERNAL_ERR;
}

int Get(const char* csTbYear, const char* csTbMonth, hash_t* hRec)
{

	/* EXEC SQL WHENEVER SQLERROR GOTO get_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	
	/* varchar		hv_tb_year[PD_ACC_YEAR_LEN]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_tb_year;

	/* varchar		hv_tb_month[PD_ACC_MONTH_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_tb_month;

	int			hv_disabled = 0;	
	int			v_closed;	

	short		ind_closed = -1;
	
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_tb_year.len = strlen(csTbYear);
	memcpy(hv_tb_year.arr, csTbYear, hv_tb_year.len);
DEBUGLOG(("Get tb_year = [%.*s]\n",hv_tb_year.len,hv_tb_year.arr));

	hv_tb_month.len = strlen(csTbMonth);
	memcpy(hv_tb_month.arr, csTbMonth, hv_tb_month.len);
DEBUGLOG(("Get tb_month = [%.*s]\n",hv_tb_month.len,hv_tb_month.arr));

	/* EXEC SQL EXECUTE
		BEGIN
		SELECT CLOSED INTO :v_closed:ind_closed
			FROM CRR_MONTH_END 
			WHERE TB_YEAR = :hv_tb_year
			AND TB_MONTH = :hv_tb_month
			AND DISABLED = :hv_disabled;
    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin SELECT CLOSED INTO :v_closed:ind_closed FROM CRR_MONT\
H_END WHERE TB_YEAR = :hv_tb_year AND TB_MONTH = :hv_tb_month AND DISABLED = \
:hv_disabled ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )112;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_closed;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_closed;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_tb_year;
 sqlstm.sqhstl[1] = (unsigned long )6;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_tb_month;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto get_error;
}


        	
	if (ind_closed == -1) {
DEBUGLOG(("Accounting month closing status not found, use default\n"));
		v_closed = 0;
	}
	
DEBUGLOG(("Get closed = [%d]\n",v_closed));
	
	PutField_CString(hRec,"tb_year",csTbYear);
	PutField_CString(hRec,"tb_month",csTbMonth);
	PutField_Int(hRec,"closed",v_closed);
	
DEBUGLOG(("Get Normal Exit\n"));
	return  PD_OK;

get_error:
DEBUGLOG(("get_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}
