
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
           char  filnam[20];
};
static struct sqlcxp sqlfpn =
{
    19,
    "OLDefSubProvider.pc"
};


static unsigned int sqlctx = 39862587;


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

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,98,0,4,49,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
28,0,0,2,98,0,4,95,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/06/19              David Wong
Add GetSubProviderId				   2015/07/02		   Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "OLDefSubProvider.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char cDebug;

void OLDefSubProvider(char cdebug)
{
	cDebug = cdebug;
}


int GetSubProviderName(const unsigned char* csSubProviderId, hash_t *hRec)
{
	int iRet = NOT_FOUND;

	/* EXEC SQL WHENEVER SQLERROR GOTO subprovidername_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_sub_provider_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_sub_provider_id;

		/* varchar v_sub_provider_name[PD_CLIENT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_sub_provider_name;

		short ind_sub_provider_name = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_sub_provider_id.len = strlen((const char*)csSubProviderId);
	memcpy(hv_sub_provider_id.arr, csSubProviderId, hv_sub_provider_id.len);
DEBUGLOG(("GetSubProviderName: sub_provider_id = [%.*s]\n", hv_sub_provider_id.len, hv_sub_provider_id.arr));

	/* EXEC SQL
		select osp_sub_provider_name
		into :v_sub_provider_name:ind_sub_provider_name
		from ol_def_sub_provider
		where osp_sub_provider_id = :hv_sub_provider_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select osp_sub_provider_name into :b0:b1 from ol_def_sub_pr\
ovider where osp_sub_provider_id = :b2 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_sub_provider_name;
 sqlstm.sqhstl[0] = (unsigned long )53;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_sub_provider_name;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_sub_provider_id;
 sqlstm.sqhstl[1] = (unsigned long )12;
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
 if (sqlca.sqlcode < 0) goto subprovidername_error;
}



	if (ind_sub_provider_name >= 0) {
		v_sub_provider_name.arr[v_sub_provider_name.len] = '\0';
		PutField_CString(hRec, "sub_provider_name", (const char*)v_sub_provider_name.arr);
DEBUGLOG(("GetSubProviderName: sub_provider_name = [%s]\n", v_sub_provider_name.arr));
		iRet = FOUND;
	}

	if (iRet == FOUND) {
DEBUGLOG(("GetSubProviderName success [%d]\n", iRet));
	} else{
DEBUGLOG(("GetSubProviderName failed [%d]\n", iRet));
	}

	return iRet;

subprovidername_error:
DEBUGLOG(("subprovidername_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLDefSubProvider:: subprovidername_error code %d\n", sqlca.sqlcode);
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return NOT_FOUND;
}

int GetSubProviderId(const unsigned char* csSubProviderName, hash_t *hRec)
{
        int iRet = NOT_FOUND;

        /* EXEC SQL WHENEVER SQLERROR GOTO subproviderid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_sub_provider_name[PD_CLIENT_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_sub_provider_name;

                /* varchar v_sub_provider_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_sub_provider_id;

                short ind_sub_provider_id = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_sub_provider_name.len = strlen((const char*)csSubProviderName);
        memcpy(hv_sub_provider_name.arr, csSubProviderName, hv_sub_provider_name.len);
DEBUGLOG(("GetSubProviderId: sub_provider_name = [%.*s]\n", hv_sub_provider_name.len, hv_sub_provider_name.arr));

        /* EXEC SQL
                select osp_sub_provider_id
                into :v_sub_provider_id:ind_sub_provider_id
                from ol_def_sub_provider
                where osp_sub_provider_name = :hv_sub_provider_name; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select osp_sub_provider_id into :b0:b1 from ol_def_s\
ub_provider where osp_sub_provider_name = :b2 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )28;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_sub_provider_id;
        sqlstm.sqhstl[0] = (unsigned long )13;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_sub_provider_id;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_sub_provider_name;
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
        if (sqlca.sqlcode < 0) goto subproviderid_error;
}



        if (ind_sub_provider_id >= 0) {
                v_sub_provider_id.arr[v_sub_provider_id.len] = '\0';
                PutField_CString(hRec, "sub_provider_id", (const char*)v_sub_provider_id.arr);
DEBUGLOG(("GetSubProviderId: sub_provider_id = [%s]\n", v_sub_provider_id.arr));
                iRet = FOUND;
        }

        if (iRet == FOUND) {
DEBUGLOG(("GetSubProviderId success [%d]\n", iRet));
        } else{
DEBUGLOG(("GetSubProviderId failed [%d]\n", iRet));
        }

        return iRet;

subproviderid_error:
DEBUGLOG(("subproviderid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLDefSubProvider:: subproviderid_error code %d\n", sqlca.sqlcode);
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return NOT_FOUND;
}
