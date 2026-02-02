
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
           char  filnam[19];
};
static struct sqlcxp sqlfpn =
{
    18,
    "EmailNotifyList.pc"
};


static unsigned int sqlctx = 18682379;


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

 static char *sq0002 = 
"SELECT EL_ID FROM EMAIL_NOTIFY_LIST ORDER BY EL_ID DESC            ";

 static char *sq0003 = 
"SELECT EL_ID FROM EMAIL_NOTIFY_LIST WHERE EL_EMAIL = :b0:b1            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,69,0,4,53,0,0,2,1,0,1,0,2,9,0,0,1,3,0,0,
28,0,0,2,67,0,9,97,0,2049,0,0,0,1,0,
43,0,0,2,0,0,13,99,0,0,1,0,0,1,0,2,3,0,0,
62,0,0,2,0,0,15,118,0,0,0,0,0,1,0,
77,0,0,2,0,0,15,133,0,0,0,0,0,1,0,
92,0,0,3,71,0,9,169,0,2049,1,1,0,1,0,1,9,0,0,
111,0,0,3,0,0,13,171,0,0,1,0,0,1,0,2,3,0,0,
130,0,0,3,0,0,15,190,0,0,0,0,0,1,0,
145,0,0,3,0,0,15,205,0,0,0,0,0,1,0,
160,0,0,4,72,0,4,233,0,0,2,1,0,1,0,2,3,0,0,1,3,0,0,
183,0,0,5,157,0,6,308,0,0,4,4,0,1,0,2,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/11/04              Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlca.h>
#include "common.h"
#include "internal.h"
#include "utilitys.h"
#include "dbutility.h"
#include "EmailNotifyList.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char	cDebug;

void EmailNotifyList(char cdebug)
{
	cDebug = cdebug;
}


int GetEmailAddress(hash_t *hRls)
{
	int iRet = FOUND;
	int iTmp = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO getemailaddress_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int	hv_email_id;
		/* varchar	v_email_address[PD_EML_EMAIL_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_email_address;


		short	ind_email_address = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_Int(hRls,"mail_id",&iTmp)) {
		hv_email_id = iTmp;
DEBUGLOG(("GetEmailAddress() email_id = [%d]\n", hv_email_id));
	}

	/* EXEC SQL
		SELECT	EL_EMAIL
		INTO	:v_email_address:ind_email_address
		FROM	EMAIL_NOTIFY_LIST
		WHERE	EL_ID = :hv_email_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select EL_EMAIL INTO :b0:b1 FROM EMAIL_NOTIFY_LIST WHERE EL\
_ID = :b2 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_email_address;
 sqlstm.sqhstl[0] = (unsigned long )103;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_email_address;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_email_id;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto getemailaddress_error;
}



	if (ind_email_address >= 0) {
		v_email_address.arr[v_email_address.len]='\0';
		PutField_CString(hRls,"mail_address",(char*)v_email_address.arr);
DEBUGLOG(("GetEmailAddress() email_address = [%s]\n",(char*)v_email_address.arr));
	} else {
		iRet = NOT_FOUND;
	}

DEBUGLOG(("GetEmailAddress() Normal Exit iRet = [%d]\n",iRet));
	return iRet;

getemailaddress_error:
DEBUGLOG(("getemailaddress_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int GetLatestEmailId(hash_t *hRls)
{
        int iRet = NOT_FOUND;
	int iCnt = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO getlatestemailid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                int 	v_email_id;

                short   ind_email_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	/* EXEC SQL DECLARE c_cursor_getlatestemailid CURSOR FOR
		SELECT  EL_ID
                FROM    EMAIL_NOTIFY_LIST
		ORDER BY EL_ID DESC; */ 


	/* EXEC SQL OPEN c_cursor_getlatestemailid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )28;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getlatestemailid_error;
}


        do {
		/* EXEC SQL FETCH c_cursor_getlatestemailid
                INTO    :v_email_id:ind_email_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 2;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )43;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_email_id;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_email_id;
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
  if (sqlca.sqlcode < 0) goto getlatestemailid_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                if (iCnt >= 1) {
                        break;
                }

                iCnt++;

        	if (ind_email_id >= 0) {
                	PutField_Int(hRls,"mail_id",v_email_id);
DEBUGLOG(("GetLatestEmailId() email_id = [%d]\n",v_email_id));
		}       

	} while (PD_TRUE);
        /* EXEC SQL CLOSE c_cursor_getlatestemailid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )62;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getlatestemailid_error;
}



        if (iCnt > 0 ) {
DEBUGLOG(("GetLatestEmailId() Found!!!\n"));
                iRet = FOUND;
        }

DEBUGLOG(("GetLatestEmailId() Normal Exit iRet = [%d]\n",iRet));
        return iRet;

getlatestemailid_error:
DEBUGLOG(("getlatestemailid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("EmailNotifyList getlatestemailid_error_error code %d\n", sqlca.sqlcode);
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getlatestemailid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )77;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int CheckEmailAddressRecord(hash_t *hRls)
{
	int iRet = NOT_FOUND;
		
	int iCnt = 0;
	char *csTmp;
	
        /* EXEC SQL WHENEVER SQLERROR GOTO checkemailaddress_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_email_address[PD_EML_EMAIL_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } hv_email_address;

		int	v_email_id;		

                short   ind_email_address = -1;
                short   ind_email_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


/* mail_addr */
        if (GetField_CString(hRls,"mail_addr",&csTmp)) {
                hv_email_address.len = strlen(csTmp);
                ind_email_address = 0;
                strncpy((char*)hv_email_address.arr, csTmp, hv_email_address.len);
DEBUGLOG(("CheckEmailAddressRecord email_address = [%.*s]\n", hv_email_address.len, hv_email_address.arr));
        }
              
	/* EXEC SQL DECLARE c_cursor_checkemailaddress CURSOR FOR
		SELECT  EL_ID
           	FROM    EMAIL_NOTIFY_LIST
            	WHERE   EL_EMAIL = :hv_email_address:ind_email_address; */ 


	/* EXEC SQL OPEN c_cursor_checkemailaddress; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )92;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_email_address;
 sqlstm.sqhstl[0] = (unsigned long )103;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_email_address;
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
 if (sqlca.sqlcode < 0) goto checkemailaddress_error;
}


	do {
                /* EXEC SQL FETCH c_cursor_checkemailaddress
                INTO    :v_email_id:ind_email_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 2;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )111;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_email_id;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_email_id;
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
                if (sqlca.sqlcode < 0) goto checkemailaddress_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                if (iCnt >= 1) {
                        break;
                }

                iCnt++;		

		if (ind_email_id >= 0) {
                	PutField_Int(hRls,"mail_id",v_email_id);
DEBUGLOG(("CheckEmailAddressRecord() email_id = [%d]\n",v_email_id));
        	}

	} while (PD_TRUE);
        /* EXEC SQL CLOSE c_cursor_checkemailaddress; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )130;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto checkemailaddress_error;
}



	if (iCnt > 0 ) {
DEBUGLOG(("CheckEmailAddressRecord() Found!!!\n"));
                iRet = FOUND;
        }

DEBUGLOG(("CheckEmailAddressRecord() Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

checkemailaddress_error:
DEBUGLOG(("checkemailaddress_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("EmailNotifyList checkemailaddress_error code %d\n", sqlca.sqlcode);
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_checkemailaddress; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )145;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;	
}

int CheckEmailIdRecord(hash_t *hRls)
{
	int iRet = NOT_FOUND;

        int iTmp = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO checkemailid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                int     hv_email_id;
		int     v_cnt;

                short   ind_email_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


/* mail_id */
        if (GetField_Int(hRls,"mail_id",&iTmp)) {
                hv_email_id = iTmp;
                ind_email_id = 0;
DEBUGLOG(("CheckEmailIdRecord email_id = [%d]\n", hv_email_id));
        }

        /* EXEC SQL
                SELECT  COUNT(*)
		INTO    :v_cnt
                FROM    EMAIL_NOTIFY_LIST
                WHERE   EL_ID = :hv_email_id:ind_email_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select COUNT ( * ) INTO :b0 FROM EMAIL_NOTIFY_LIST W\
HERE EL_ID = :b1:b2 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )160;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_email_id;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_email_id;
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
        if (sqlca.sqlcode < 0) goto checkemailid_error;
}



	if (v_cnt>0) {
                iRet = FOUND;
DEBUGLOG(("CheckEmailIdRecord() FOUND\n"));
        } else {
                iRet = NOT_FOUND;
DEBUGLOG(("CheckEmailIdRecord() NOT FOUND\n"));
        }

DEBUGLOG(("CheckEmailIdRecord() Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

checkemailid_error:
DEBUGLOG(("checkemailid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int Add(const hash_t *hRls)
{
        char    *csTmp;
        int     iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                int             hv_email_id;
                /* varchar         hv_email_addr[PD_EML_EMAIL_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } hv_email_addr;

                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


                short           ind_email_id = -1;
                short           ind_email_addr = -1;
                short           ind_create_user = -1;

                short           hv_return_value;

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

/* mail_id */
        if(GetField_Int(hRls, "mail_id", &iTmp)) {
                hv_email_id = iTmp;
                ind_email_id = 0;
DEBUGLOG(("Add: mail_id = [%d]\n",hv_email_id));
        }

/* mail_addr */
        if(GetField_CString(hRls,"mail_addr",&csTmp)) {
                hv_email_addr.len = strlen(csTmp);
                strncpy((char*)hv_email_addr.arr, csTmp, hv_email_addr.len);
                ind_email_addr = 0;
        }
DEBUGLOG(("Add: mail_addr = [%.*s]\n",hv_email_addr.len, hv_email_addr.arr));

/* create_user */
        if(GetField_CString(hRls,"create_user",&csTmp)) {
                hv_create_user.len = strlen(csTmp);
                strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
                ind_create_user = 0;
        } else if(GetField_CString(hRls,"update_user",&csTmp)) {
                hv_create_user.len = strlen(csTmp);
                strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
                ind_create_user = 0;
        }
DEBUGLOG(("Add: create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));

	/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_email_notify_list_insert(
                                                :hv_email_id:ind_email_id,
                                                :hv_email_addr:ind_email_addr,
                                                :hv_create_user:ind_create_user);
                END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_email_notify_list_insert ( :hv\
_email_id:ind_email_id , :hv_email_addr:ind_email_addr , :hv_create_user:ind_\
create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )183;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_email_id;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_email_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_email_addr;
 sqlstm.sqhstl[2] = (unsigned long )103;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_email_addr;
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
 if (sqlca.sqlcode < 0) goto add_error;
}



DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("Add:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("EmailNotifyList_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("EmailNotifyList_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("EmailNotifyList_Add: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}
