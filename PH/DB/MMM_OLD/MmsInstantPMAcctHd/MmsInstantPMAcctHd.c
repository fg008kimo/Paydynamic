
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
           char  filnam[22];
};
static struct sqlcxp sqlfpn =
{
    21,
    "MmsInstantPMAcctHd.pc"
};


static unsigned int sqlctx = 162824187;


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
5,0,0,1,186,0,6,109,0,0,5,5,0,1,0,2,3,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,9,0,0,
40,0,0,2,0,0,17,236,0,0,1,1,0,1,0,1,9,0,0,
59,0,0,2,0,0,21,237,0,0,0,0,0,1,0,
74,0,0,3,186,0,4,302,0,0,5,4,0,1,0,2,3,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,3,0,0,
109,0,0,4,192,0,6,403,0,0,5,5,0,1,0,2,3,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/12/23              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "MmsInstantPMAcctHd.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;
void MmsInstantPMAcctHd(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const hash_t *hRls)
{
        char		*csTmp;
        char        	cTmp;


        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        short 		hv_return_value;

	char		hv_party_type;
	char		hv_business_type;
	char		hv_status;
	/* varchar		hv_last_update_datetime[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_last_update_datetime;

	/* varchar		hv_status_update_datetime[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_status_update_datetime;

	/* varchar		hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;




	short		ind_party_type = -1;
	short		ind_business_type = -1;
	short		ind_status = -1;
	short		ind_last_update_datetime = -1;
	short		ind_status_update_datetime = -1;
	short		ind_add_user = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));


/* party_type */ 
        if (GetField_Char(hRls,"party_type",&cTmp)) {
		hv_party_type = cTmp;
                ind_party_type = 0;
DEBUGLOG(("Add:party_type = [%c]\n",hv_party_type));
        }

/* business_type */ 
        if (GetField_Char(hRls,"business_type",&cTmp)) {
		hv_business_type = cTmp;
                ind_business_type = 0;
DEBUGLOG(("Add:business_type = [%c]\n",hv_business_type));
        }

/* Status */ 
        if (GetField_Char(hRls,"status",&cTmp)) {
		hv_status = cTmp;
                ind_status = 0;
DEBUGLOG(("Add:status = [%c]\n",hv_status));
        }


/* last_update_datetime */
        if (GetField_CString(hRls,"last_update_datetime",&csTmp)) {
                hv_last_update_datetime.len = strlen(csTmp);
                memcpy(hv_last_update_datetime.arr,csTmp,hv_last_update_datetime.len);
                ind_last_update_datetime = 0;
DEBUGLOG(("Add:last_update_datetime = [%.*s]\n",hv_last_update_datetime.len,hv_last_update_datetime.arr));
        }

/* add user */
        if (GetField_CString(hRls,"add_user",&csTmp)) {
                hv_add_user.len = strlen(csTmp);
                memcpy(hv_add_user.arr,csTmp,hv_add_user.len);
                ind_add_user = 0;
DEBUGLOG(("Add:add_user = [%.*s]\n",hv_add_user.len,hv_add_user.arr));
        }

/* status_update_datetime */
        if (GetField_CString(hRls,"status_update_datetime",&csTmp)) {
                hv_status_update_datetime.len = strlen(csTmp);
                memcpy(hv_status_update_datetime.arr,csTmp,hv_status_update_datetime.len);
                ind_status_update_datetime = 0;
DEBUGLOG(("Add:status_update_datetime = [%.*s]\n",hv_status_update_datetime.len,hv_status_update_datetime.arr));
        }

	/* EXEC SQL EXECUTE
                BEGIN
			:hv_return_value := sp_mms_instant_pmacct_hd_ins(
					:hv_party_type:ind_party_type,
					:hv_business_type:ind_business_type,
					:hv_status:ind_status,
					:hv_add_user:ind_add_user);
	        END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_mms_instant_pmacct_hd_ins ( :h\
v_party_type:ind_party_type , :hv_business_type:ind_business_type , :hv_statu\
s:ind_status , :hv_add_user:ind_add_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_party_type;
 sqlstm.sqhstl[1] = (unsigned long )1;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_party_type;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_business_type;
 sqlstm.sqhstl[2] = (unsigned long )1;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_business_type;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[3] = (unsigned long )1;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_status;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_add_user;
 sqlstm.sqhstl[4] = (unsigned long )22;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_add_user;
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



DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK) {
DEBUGLOG(("Add:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MmsInstantPMAcctHd_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("MmsInstantPMAcctHd_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		TxnAbort();
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("MmsInstantPMAcctHd_Add: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_INTERNAL_ERR TxnAbort\n"));
	TxnAbort();
        return PD_INTERNAL_ERR;
}

int Update(const hash_t *hRls)
{

	char*	csTmp;
	char	cTmp;
	char	cPartyType;
	char	cBusinessType;
	char*	csBuf;
        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


	/* varchar 	hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
	csBuf = (char*) malloc (128);
	strcpy((char*)hv_dynstmt.arr,"update mms_instant_pm_acct_hd set mia_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        GetField_Char(hRls,"party_type",&cPartyType);
DEBUGLOG(("Update:party_type = [%c]\n",cPartyType));

        GetField_Char(hRls,"business_type",&cBusinessType);
DEBUGLOG(("Update:business_type = [%c]\n",cBusinessType));


/* Status */ 
        if (GetField_Char(hRls,"status",&cTmp)) {
DEBUGLOG(("Update:status = [%c]\n",cTmp));
		sprintf(csBuf,"%c",cTmp);
		strcat((char*)hv_dynstmt.arr, ",mia_status = '");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* last_update_datetime  */
        if (GetField_CString(hRls,"last_update_datetime",&csTmp)) {
DEBUGLOG(("Update:last_update_datetime = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",mia_last_update_datetime = to_date('");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "', 'YYYYMMDDHH24MISS')");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* status_update_datetime */
        if (GetField_CString(hRls,"status_update_datetime",&csTmp)) {
DEBUGLOG(("Update:status_update_datetime = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",mia_status_update_datetime = to_date('");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "', 'YYYYMMDDHH24MISS')");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* add user */
        if (GetField_CString(hRls,"add_user",&csTmp)) {
DEBUGLOG(("Update:add_user = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",mia_create_user = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* update user */
        if (GetField_CString(hRls,"update_user",&csTmp)) {
DEBUGLOG(("Update:update_user = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",mia_update_user = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


	strcat((char *)hv_dynstmt.arr, " WHERE mid_party_type= '");
	sprintf(csBuf,"%c",cPartyType);
        strcat((char *)hv_dynstmt.arr, csBuf);
        strcat((char *)hv_dynstmt.arr, "'");
	strcat((char *)hv_dynstmt.arr, " AND mid_business_type= '");
	sprintf(csBuf,"%c",cBusinessType);
        strcat((char *)hv_dynstmt.arr, csBuf);
        strcat((char *)hv_dynstmt.arr, "'");
       	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )40;
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
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )59;
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

ERRLOG("MmsInstantPMAcctHd_Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
	TxnAbort();
        return PD_INTERNAL_ERR;
}

int ChkValidHeader(const hash_t *hRls)
{
        char        	cTmp;
	int		iTmp;

	int		iRet = PD_NOT_FOUND;

	/* EXEC SQL WHENEVER SQLERROR GOTO chkvalidateheader_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                char            hv_party_type;
                char            hv_business_type;
		char		hv_status;

		int		hv_refresh_interval;

		int		v_no_of_record;
		short		ind_no_of_record = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


/* party_type */ 
        if (GetField_Char(hRls,"party_type",&cTmp)) {
		hv_party_type = cTmp;
DEBUGLOG(("ChkValidHeader:party_type = [%c]\n",hv_party_type));
        }

/* business_type */ 
        if (GetField_Char(hRls,"business_type",&cTmp)) {
		hv_business_type = cTmp;
DEBUGLOG(("ChkValidHeader:business_type = [%c]\n",hv_business_type));
        }

/* Status */ 
        if (GetField_Char(hRls,"status",&cTmp)) {
		hv_status = cTmp;
DEBUGLOG(("ChkValidHeader:status = [%c]\n",hv_status));
        }

/* refresh interval */
	if (GetField_Int(hRls, "refresh_interval", &iTmp)) {
		hv_refresh_interval = iTmp;
DEBUGLOG(("ChkValidHeader:refresh_interval = [%d]\n", hv_refresh_interval));
	}


	/* EXEC SQL
		SELECT count(1)
		  INTO v_no_of_record:ind_no_of_record
		  FROM mms_instant_pm_acct_hd
		 WHERE mia_party_type = :hv_party_type
		   AND mia_business_type = :hv_business_type
		   AND mia_status = :hv_status
		   AND mia_lastupdate_datetime >= sysdate - :hv_refresh_interval / (60*24); */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count(1) into :b0:b1  from mms_instant_pm_acct_hd wh\
ere (((mia_party_type=:b2 and mia_business_type=:b3) and mia_status=:b4) and \
mia_lastupdate_datetime>=(sysdate-(:b5/(60* 24))))";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )74;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_no_of_record;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_no_of_record;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_party_type;
 sqlstm.sqhstl[1] = (unsigned long )1;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_business_type;
 sqlstm.sqhstl[2] = (unsigned long )1;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[3] = (unsigned long )1;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_refresh_interval;
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
 if (sqlca.sqlcode < 0) goto chkvalidateheader_error;
}



	if (ind_no_of_record >= 0) {
		if (v_no_of_record > 0) {
DEBUGLOG(("ChkValidHeader:FOUND\n"));
			iRet = PD_FOUND;
		}
	}	

        if (iRet!= PD_FOUND) {
DEBUGLOG(("ChkValidHeader NOT FOUND\n"));
        }


        return iRet;

chkvalidateheader_error:
DEBUGLOG(("chkvalidateheader_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;


}

int UpdateRec(const hash_t *hRls)
{
	char            *csTmp;
	char            cTmp;


	/* EXEC SQL WHENEVER SQLERROR GOTO updaterec_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		short           hv_return_value;

		char            hv_party_type;
		char            hv_business_type;
		char            hv_status;
		/*varchar         hv_last_update_datetime[PD_DATETIME_LEN];*/
		/* varchar         hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;


		short           ind_party_type = -1;
		short           ind_business_type = -1;
		short           ind_status = -1;
		/*short           ind_last_update_datetime = -1;*/
		short           ind_update_user = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateRec: Begin\n"));


/* party_type */
        if (GetField_Char(hRls,"party_type",&cTmp)) {
                hv_party_type = cTmp;
                ind_party_type = 0;
DEBUGLOG(("UpdateRec:party_type = [%c]\n",hv_party_type));
        }

/* business_type */
        if (GetField_Char(hRls,"business_type",&cTmp)) {
                hv_business_type = cTmp;
                ind_business_type = 0;
DEBUGLOG(("UpdateRec:business_type = [%c]\n",hv_business_type));
        }

/* Status */
        if (GetField_Char(hRls,"status",&cTmp)) {
                hv_status = cTmp;
                ind_status = 0;
DEBUGLOG(("UpdateRec:status = [%c]\n",hv_status));
        }

/* last_update_datetime */
/*
        if (GetField_CString(hRls,"last_update_datetime",&csTmp)) {
                hv_last_update_datetime.len = strlen(csTmp);
                memcpy(hv_last_update_datetime.arr,csTmp,hv_last_update_datetime.len);
                ind_last_update_datetime = 0;
DEBUGLOG(("UpdateRec:last_update_datetime = [%.*s]\n",hv_last_update_datetime.len,hv_last_update_datetime.arr));
        }
*/

/* update user */
        if (GetField_CString(hRls,"update_user",&csTmp)) {
                hv_update_user.len = strlen(csTmp);
                memcpy(hv_update_user.arr,csTmp,hv_update_user.len);
                ind_update_user = 0;
DEBUGLOG(("UpdateRec:update_user = [%.*s]\n",hv_update_user.len,hv_update_user.arr));
	}

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_mms_instant_pmacct_hd_upd(
                                        :hv_party_type:ind_party_type,
                                        :hv_business_type:ind_business_type,
                                        :hv_status:ind_status,
                                        :hv_update_user:ind_update_user);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_mms_instant_pmacct_hd_u\
pd ( :hv_party_type:ind_party_type , :hv_business_type:ind_business_type , :h\
v_status:ind_status , :hv_update_user:ind_update_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )109;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_party_type;
        sqlstm.sqhstl[1] = (unsigned long )1;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_party_type;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_business_type;
        sqlstm.sqhstl[2] = (unsigned long )1;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_business_type;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[3] = (unsigned long )1;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_status;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_update_user;
        sqlstm.sqhstl[4] = (unsigned long )22;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_update_user;
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
        if (sqlca.sqlcode < 0) goto updaterec_error;
}



DEBUGLOG(("UpdateRec:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK) {
DEBUGLOG(("UpdateRec:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MmsInstantPMAcctHd_UpdateRec: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateRec: SP_OTHER_ERR TxnAbort\n"));
                TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("MmsInstantPMAcctHd_UpdateRec: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateRec: SP_ERR TxnAbort\n"));
                TxnAbort();
                return PD_ERR;
        }

updaterec_error:
DEBUGLOG(("updaterec_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("MmsInstantPMAcctHd_UpdateRec: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("UpdateRec: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;

}
