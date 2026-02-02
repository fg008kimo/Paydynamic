
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
    "MiEntityRsp.pc"
};


static unsigned int sqlctx = 1234123;


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

 static char *sq0001 = 
"select er_rsp_id , er_rsp_name , er_rsp_node_id , er_rsp_status from mi_ent\
ity_rsp where er_entity_id = :b0            ";

 static char *sq0002 = 
"select er_rsp_id , er_rsp_name , er_rsp_node_id , er_rsp_status , ba_status\
 , ba_currency from mi_entity_rsp , mi_entity_bal_acct where er_entity_id = :\
b0 and er_entity_id = ba_entity_id            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,119,0,9,66,0,2049,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,13,68,0,0,4,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
55,0,0,1,0,0,15,112,0,0,0,0,0,1,0,
70,0,0,1,0,0,15,123,0,0,0,0,0,1,0,
85,0,0,2,198,0,9,171,0,2049,1,1,0,1,0,1,9,0,0,
104,0,0,2,0,0,13,173,0,0,6,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,
143,0,0,2,0,0,15,237,0,0,0,0,0,1,0,
158,0,0,2,0,0,15,248,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version 			                   2015/11/04              Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "MiEntityRsp.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void MiEntityRsp(char    cdebug)
{
        cDebug = cdebug;
}


int GetRSPInfoByEntityId(const char* csEntityId,
                	hash_t* hRec)
{

        /* EXEC SQL WHENEVER SQLERROR GOTO getrspinfo_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_entity_id[PD_PSP_MID_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_entity_id;


                /* varchar         v_rsp_id[PD_MMS_RSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_rsp_id;

                /* varchar         v_name[PD_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_name;

		/* varchar		v_node_id[PD_MMS_NODE_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[6]; } v_node_id;

		/* varchar		v_status[PD_ACCOUNT_STATUS_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_status;


                short           ind_rsp_id = -1;
                short           ind_name = -1;
		short		ind_node_id = -1;
		short		ind_status = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


// entity_id
        hv_entity_id.len = strlen(csEntityId);
        memcpy(hv_entity_id.arr,csEntityId,hv_entity_id.len);
DEBUGLOG(("GetRSPInfoByEntityId entity_id = [%d][%.*s]\n",hv_entity_id.len,hv_entity_id.len,hv_entity_id.arr));

        /* EXEC SQL DECLARE c_cursor_getrspinfo CURSOR FOR
                select er_rsp_id,
		       er_rsp_name,
		       er_rsp_node_id,
		       er_rsp_status
                  from mi_entity_rsp
                 where er_entity_id = :hv_entity_id; */ 


        /* EXEC SQL OPEN c_cursor_getrspinfo; */ 

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
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_entity_id;
        sqlstm.sqhstl[0] = (unsigned long )52;
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
        if (sqlca.sqlcode < 0) goto getrspinfo_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getrspinfo
                INTO
                        :v_rsp_id:ind_rsp_id,
                        :v_name:ind_name,
			:v_node_id:ind_node_id,
			:v_status:ind_status; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 4;
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
                sqlstm.sqhstv[0] = (unsigned char  *)&v_rsp_id;
                sqlstm.sqhstl[0] = (unsigned long )23;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_rsp_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_name;
                sqlstm.sqhstl[1] = (unsigned long )53;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_name;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_node_id;
                sqlstm.sqhstl[2] = (unsigned long )8;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_node_id;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_status;
                sqlstm.sqhstl[3] = (unsigned long )5;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_status;
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
                if (sqlca.sqlcode < 0) goto getrspinfo_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

DEBUGLOG(("GetRSPInfoByEntityId found record\n"));

/* rsp_id */
		if (ind_rsp_id >= 0) {
                        v_rsp_id.arr[v_rsp_id.len] = '\0';
                        PutField_CString(hRec,"rsp_id",(const char*)v_rsp_id.arr);
DEBUGLOG(("GetRSPInfoByEntityId rsp_id = [%s]\n",v_rsp_id.arr));
                }

/* name */
                if (ind_name >= 0) {
                        v_name.arr[v_name.len] = '\0';
                        PutField_CString(hRec,"rsp_name",(const char*)v_name.arr);
DEBUGLOG(("GetRSPInfoByEntityId rsp_name = [%s]\n",v_name.arr));
                }

/* status */
                if (ind_status >= 0) {
                        v_status.arr[v_status.len] = '\0';
                        PutField_CString(hRec,"status",(const char*)v_status.arr);
DEBUGLOG(("GetRSPInfoByEntityId status = [%s]\n",v_status.arr));
                }

/* node_id */
                if (ind_node_id >= 0) {
                        v_node_id.arr[v_node_id.len] = '\0';
                        PutField_CString(hRec,"node_id",(const char*)v_node_id.arr);
DEBUGLOG(("GetRSPInfoByEntityId node_id = [%s]\n",v_node_id.arr));
                }

        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getrspinfo; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )55;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getrspinfo_error;
}




DEBUGLOG(("GetRSPInfoByEntityId Normal Exit\n"));
        return  PD_OK;

getrspinfo_error:
DEBUGLOG(("getrspinfo_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MiEntityRsp_Get: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getrspinfo; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )70;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int GetRSPAcctInfoByEntityId(const char* csEntityId,
                recordset_t* myRec)
{
	hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getrspacctinfo_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_entity_id[PD_PSP_MID_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_entity_id;


                /* varchar         v_rsp_id[PD_MMS_RSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_rsp_id;

                /* varchar         v_name[PD_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_name;

		/* varchar		v_node_id[PD_MMS_NODE_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[6]; } v_node_id;

		/* varchar		v_status[PD_ACCOUNT_STATUS_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_status;

		/* varchar		v_bal_status[PD_ACCOUNT_STATUS_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_bal_status;

		/* varchar		v_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ccy;


                short           ind_rsp_id = -1;
                short           ind_name = -1;
		short		ind_node_id = -1;
		short		ind_status = -1;
		short		ind_bal_status= -1;
		short		ind_ccy = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


// entity_id
        hv_entity_id.len = strlen(csEntityId);
        memcpy(hv_entity_id.arr,csEntityId,hv_entity_id.len);
DEBUGLOG(("GetRSPAcctInfoByEntityId entity_id = [%d][%.*s]\n",hv_entity_id.len,hv_entity_id.len,hv_entity_id.arr));

        /* EXEC SQL DECLARE c_cursor_getrspacctinfo CURSOR FOR
                select er_rsp_id,
		       er_rsp_name,
		       er_rsp_node_id,
		       er_rsp_status,
		       ba_status,
		       ba_currency
                  from mi_entity_rsp, mi_entity_bal_acct
                 where er_entity_id = :hv_entity_id
		 and   er_entity_id = ba_entity_id; */ 


        /* EXEC SQL OPEN c_cursor_getrspacctinfo; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0002;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )85;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_entity_id;
        sqlstm.sqhstl[0] = (unsigned long )52;
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
        if (sqlca.sqlcode < 0) goto getrspacctinfo_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getrspacctinfo
                INTO
                        :v_rsp_id:ind_rsp_id,
                        :v_name:ind_name,
			:v_node_id:ind_node_id,
			:v_status:ind_status,
			:v_bal_status:ind_bal_status,
			:v_ccy:ind_ccy; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 6;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )104;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_rsp_id;
                sqlstm.sqhstl[0] = (unsigned long )23;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_rsp_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_name;
                sqlstm.sqhstl[1] = (unsigned long )53;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_name;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_node_id;
                sqlstm.sqhstl[2] = (unsigned long )8;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_node_id;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_status;
                sqlstm.sqhstl[3] = (unsigned long )5;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_status;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_bal_status;
                sqlstm.sqhstl[4] = (unsigned long )5;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_bal_status;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_ccy;
                sqlstm.sqhstl[5] = (unsigned long )6;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_ccy;
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
                if (sqlca.sqlcode < 0) goto getrspacctinfo_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

DEBUGLOG(("GetRSPAcctInfoByEntityId found record\n"));

		myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash, 0);

/* rsp_id */
		if (ind_rsp_id >= 0) {
                        v_rsp_id.arr[v_rsp_id.len] = '\0';
                        PutField_CString(myHash,"rsp_id",(const char*)v_rsp_id.arr);
DEBUGLOG(("GetRSPAcctInfoByEntityId rsp_id = [%s]\n",v_rsp_id.arr));
                }

/* name */
                if (ind_name >= 0) {
                        v_name.arr[v_name.len] = '\0';
                        PutField_CString(myHash,"rsp_name",(const char*)v_name.arr);
DEBUGLOG(("GetRSPAcctInfoByEntityId rsp_name = [%s]\n",v_name.arr));
                }

/* ccy */
                if (ind_ccy>= 0) {
                        v_ccy.arr[v_ccy.len] = '\0';
                        PutField_CString(myHash,"ccy",(const char*)v_ccy.arr);
DEBUGLOG(("GetRSPAcctInfoByEntityId ccy = [%s]\n",v_ccy.arr));
                }

/* status */
                if (ind_status >= 0) {
                        v_status.arr[v_status.len] = '\0';
                        PutField_CString(myHash,"status",(const char*)v_status.arr);
DEBUGLOG(("GetRSPAcctInfoByEntityId status = [%s]\n",v_status.arr));
                }

/* bal_status */
                if (ind_bal_status >= 0) {
                        v_bal_status.arr[v_bal_status.len] = '\0';
                        PutField_CString(myHash,"bal_status",(const char*)v_bal_status.arr);
DEBUGLOG(("GetRSPAcctInfoByEntityId balance status = [%s]\n",v_bal_status.arr));
                }

/* node_id */
                if (ind_node_id >= 0) {
                        v_node_id.arr[v_node_id.len] = '\0';
                        PutField_CString(myHash,"node_id",(const char*)v_node_id.arr);
DEBUGLOG(("GetRSPAcctInfoByEntityId node_id = [%s]\n",v_node_id.arr));
                }

                RecordSet_Add(myRec, myHash);
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getrspacctinfo; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )143;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getrspacctinfo_error;
}




DEBUGLOG(("GetRSPAcctInfoByEntityId Normal Exit\n"));
        return  PD_OK;

getrspacctinfo_error:
DEBUGLOG(("getrspacctinfo_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MiEntityRsp_Get: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getrspacctinfo; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )158;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}
