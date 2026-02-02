
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
           char  filnam[23];
};
static struct sqlcxp sqlfpn =
{
    22,
    "EmailSettingHistory.pc"
};


static unsigned int sqlctx = 298993379;


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
   unsigned char  *sqhstv[9];
   unsigned long  sqhstl[9];
            int   sqhsts[9];
            short *sqindv[9];
            int   sqinds[9];
   unsigned long  sqharm[9];
   unsigned long  *sqharc[9];
   unsigned short  sqadto[9];
   unsigned short  sqtdso[9];
} sqlstm = {12,9};

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
"SELECT ESH_LOG_SEQ FROM EMAIL_SETTING_HISTORY WHERE ESH_FUNCT = :b0:b1 AND \
ESH_PARTY_ID = :b2:b3 AND ESH_PARTY_TYPE = :b4:b5 ORDER BY ESH_LOG_SEQ DESC  \
          ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,162,0,9,88,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,1,0,0,
32,0,0,1,0,0,13,90,0,0,1,0,0,1,0,2,3,0,0,
51,0,0,1,0,0,15,109,0,0,0,0,0,1,0,
66,0,0,1,0,0,15,124,0,0,0,0,0,1,0,
81,0,0,2,285,0,6,221,0,0,9,9,0,1,0,2,3,0,0,1,1,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,3,
0,0,1,3,0,0,1,3,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/12/07              Elvis Wong
Delete AadOriginalLog and
Add AddLog					   2015/07/13		   Elvis Wong	
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlca.h>
#include "common.h"
#include "internal.h"
#include "utilitys.h"
#include "dbutility.h"
#include "EmailSettingHistory.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char	cDebug;

void EmailSettingHistory(char	cdebug)
{
	cDebug = cdebug;
}

int GetLatestLogSeq(hash_t *hRls)
{
        int iRet = NOT_FOUND;
        
	int iCnt = 0;
	char cTmp;
	char *csTmp;
	
        /* EXEC SQL WHENEVER SQLERROR GOTO getlatestlogseq_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_funct[PD_EML_FUNCT_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_funct;

		/* varchar         hv_party_id[PD_EML_PARTY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_party_id;

		char            hv_party_type;
                int     	v_log_seq;

		short           ind_funct = -1;
		short           ind_party_id = -1;
		short		ind_party_type = -1;
                short   	ind_log_seq = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


/* funct */
        if (GetField_CString(hRls,"funct",&csTmp)) {
                hv_funct.len = strlen(csTmp);
                ind_funct = 0;
                strncpy((char*)hv_funct.arr, csTmp, hv_funct.len);
DEBUGLOG(("GetLatestLogSeq funct = [%.*s]\n", hv_funct.len, hv_funct.arr));
        }

/* party_id */
	if (GetField_CString(hRls,"party_id",&csTmp)) {
                hv_party_id.len = strlen(csTmp);
                ind_party_id = 0;
                strncpy((char*)hv_party_id.arr, csTmp, hv_party_id.len);
DEBUGLOG(("GetLatestLogSeq party_id = [%.*s]\n", hv_party_id.len, hv_party_id.arr));
        }

/* party_type */
	if (GetField_Char(hRls,"party_type",&cTmp)) {
                hv_party_type = cTmp;
                ind_party_type = 0;
DEBUGLOG(("GetLatestLogSeq party_type = [%c]\n", hv_party_type));
        }

        /* EXEC SQL DECLARE c_cursor_getlatestlogseq CURSOR FOR
                SELECT  ESH_LOG_SEQ
                FROM    EMAIL_SETTING_HISTORY
		WHERE	ESH_FUNCT = :hv_funct:ind_funct
		AND	ESH_PARTY_ID = :hv_party_id:ind_party_id
		AND	ESH_PARTY_TYPE = :hv_party_type:ind_party_type
                ORDER BY ESH_LOG_SEQ DESC; */ 


        /* EXEC SQL OPEN c_cursor_getlatestlogseq; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 3;
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
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_funct;
        sqlstm.sqhstl[0] = (unsigned long )17;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_funct;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_party_id;
        sqlstm.sqhstl[1] = (unsigned long )17;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_party_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_party_type;
        sqlstm.sqhstl[2] = (unsigned long )1;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_party_type;
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
        if (sqlca.sqlcode < 0) goto getlatestlogseq_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getlatestlogseq
                INTO    :v_log_seq:ind_log_seq; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 3;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )32;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_log_seq;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_log_seq;
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
                if (sqlca.sqlcode < 0) goto getlatestlogseq_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                if (iCnt >= 1) {
                        break;
                }

                iCnt++;

                if (ind_log_seq >= 0) {
                        PutField_Int(hRls,"log_seq",v_log_seq);
DEBUGLOG(("GetLatestLogSeq() log_seq = [%d]\n",v_log_seq));
                }

        } while (PD_TRUE);
        /* EXEC SQL CLOSE c_cursor_getlatestlogseq; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 3;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )51;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getlatestlogseq_error;
}



        if (iCnt > 0 ) {
DEBUGLOG(("() Found!!!\n"));
                iRet = FOUND;
        }

DEBUGLOG(("GetLatestLogSeq() Normal Exit iRet = [%d]\n",iRet));
        return iRet;

getlatestlogseq_error:
DEBUGLOG(("getlatestlogseq_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("EmailSettingHistory getlatestlogseq_error_error code %d\n", sqlca.sqlcode);
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getlatestlogseq; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 3;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )66;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int AddLog(hash_t *hRls)
{
        int iRet = PD_OK;

	int iTmp = 0;
        char cTmp;
        char *csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO addlog_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_funct[PD_EML_FUNCT_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_funct;

                /* varchar         hv_party_id[PD_EML_PARTY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_party_id;

                char            hv_party_type;
		int             hv_log_seq;
		int             hv_default;
		int             hv_disabled;
                int     	hv_email_id;
                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short           ind_funct = -1;
                short           ind_party_id = -1;
                short           ind_party_type = -1;
		short           ind_log_seq = -1;
		short           ind_default = -1;
		short           ind_disabled = -1;
                short   	ind_email_id = -1;
                short   	ind_create_user = -1;

		short           hv_return_value;

        /* EXEC SQL END DECLARE SECTION; */ 


/* log_seq */
	if (GetField_Int(hRls,"log_seq",&iTmp)) {
                hv_log_seq = iTmp;
                ind_log_seq = 0;
DEBUGLOG(("AddLog log_seq = [%d]\n", hv_log_seq));
        }

/* funct */
        if (GetField_CString(hRls,"funct",&csTmp)) {
                hv_funct.len = strlen(csTmp);
                ind_funct = 0;
                strncpy((char*)hv_funct.arr, csTmp, hv_funct.len);
DEBUGLOG(("AddLog funct = [%.*s]\n", hv_funct.len, hv_funct.arr));
        }

/* party_id */
        if (GetField_CString(hRls,"party_id",&csTmp)) {
                hv_party_id.len = strlen(csTmp);
                ind_party_id = 0;
                strncpy((char*)hv_party_id.arr, csTmp, hv_party_id.len);
DEBUGLOG(("AddLog party_id = [%.*s]\n", hv_party_id.len, hv_party_id.arr));
        }

/* party_type */
        if (GetField_Char(hRls,"party_type",&cTmp)) {
                hv_party_type = cTmp;
                ind_party_type = 0;
DEBUGLOG(("AddLog party_type = [%c]\n", hv_party_type));
        }

/* email_id */
	if (GetField_Int(hRls,"mail_id",&iTmp)) {
                hv_email_id = iTmp;
                ind_email_id = 0;
DEBUGLOG(("AddLog mail_id = [%d]\n", hv_email_id));
	}

/* default */
	if (GetField_Int(hRls, "default", &iTmp)) {
                hv_default = iTmp;
                ind_default = 0;
DEBUGLOG(("AddLog default = [%d]\n",hv_default));
        }

/* disabled */
        if (GetField_Int(hRls, "disabled", &iTmp)) {
                hv_disabled = iTmp;
                ind_disabled = 0;
DEBUGLOG(("AddLog disabled = [%d]\n",hv_disabled));
        }

/* create_user */
	if (GetField_CString(hRls,"create_user",&csTmp)) {
                hv_create_user.len = strlen(csTmp);
                ind_create_user = 0;
                strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
DEBUGLOG(("AddLog create_user = [%.*s]\n", hv_create_user.len, hv_create_user.arr));
	}

	/* EXEC SQL EXECUTE
          	BEGIN
                    	:hv_return_value := sp_email_sett_hist_insert(
                         			:hv_party_type:ind_party_type,
                                        	:hv_party_id:ind_party_id,
                                        	:hv_funct:ind_funct,
                                        	:hv_email_id:ind_email_id,
                                        	:hv_default:ind_default,
                                        	:hv_disabled:ind_disabled,
						:hv_log_seq:ind_log_seq,
						:hv_create_user:ind_create_user);
            	END;
     	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_email_sett_hist_insert ( :hv_p\
arty_type:ind_party_type , :hv_party_id:ind_party_id , :hv_funct:ind_funct , \
:hv_email_id:ind_email_id , :hv_default:ind_default , :hv_disabled:ind_disabl\
ed , :hv_log_seq:ind_log_seq , :hv_create_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )81;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_party_id;
 sqlstm.sqhstl[2] = (unsigned long )17;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_party_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_funct;
 sqlstm.sqhstl[3] = (unsigned long )17;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_funct;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_email_id;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_email_id;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_default;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_default;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_disabled;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_log_seq;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_log_seq;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[8] = (unsigned long )22;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_create_user;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto addlog_error;
}



       	if (hv_return_value == SP_OK)
       	{
DEBUGLOG(("AddLog: Normal Exit\n"));
       	}

      	if (hv_return_value == SP_OTHER_ERR)
       	{
DEBUGLOG(("AddLog: SP_OTHER_ERR\n"));
             	return PD_OTHER_ERR;
   	}

     	if (hv_return_value == SP_ERR)
      	{
DEBUGLOG(("AddLog: SP_ERR\n"));
           	return PD_ERR;
     	}

DEBUGLOG(("AddLog() Normal Exit iRet = [%d]\n",iRet));
        return iRet;

addlog_error:
DEBUGLOG(("addlog_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("EmailSettingHistory:AddLog: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("AddLog: SP_INTERNAL_ERR TxnAbort\n"));
        return PD_ERR;
}

