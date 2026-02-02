
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
           char  filnam[18];
};
static struct sqlcxp sqlfpn =
{
    17,
    "TxnBrowserInfo.pc"
};


static unsigned int sqlctx = 10873971;


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
5,0,0,1,176,0,6,88,0,0,5,5,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
40,0,0,2,96,0,6,153,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,1,1,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/03/25              LokMan Chow
Add UpdateDeviceType			   	   2017/10/24		   Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "TxnBrowserInfo.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;
void TxnBrowserInfo(char    cdebug)
{
        cDebug = cdebug;
}

int AddTxnBrowserInfo(const hash_t *hRls)
{
        char		*csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        short 		hv_return_value;

	/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;
	
	/* varchar		hv_user_agent[PD_REMARK_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_user_agent;

	/* varchar		hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;

	/* varchar		hv_client_ip[PD_IP_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_client_ip;


	short		ind_txn_id = -1;
	short		ind_user_agent = -1;
	short		ind_add_user = -1;
	short		ind_client_ip= -1;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("AddTxnBrowserInfo: Begin\n"));

/* txn_seq */
        if (GetField_CString(hRls,"txn_seq",&csTmp)) {
                hv_txn_id.len = strlen(csTmp);
                memcpy(hv_txn_id.arr,csTmp,hv_txn_id.len);
                ind_txn_id = 0;
DEBUGLOG(("AddTxnBrowserInfo:txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
        }
/* user agent */
        if (GetField_CString(hRls,"user_agent",&csTmp)) {
                hv_user_agent.len = strlen(csTmp);
                memcpy(hv_user_agent.arr,csTmp,hv_user_agent.len);
                ind_user_agent = 0;
DEBUGLOG(("AddTxnBrowserInfo:user_agent = [%.*s]\n",hv_user_agent.len,hv_user_agent.arr));
        }

/* add user */
        if (GetField_CString(hRls,"add_user",&csTmp)) {
                hv_add_user.len = strlen(csTmp);
                memcpy(hv_add_user.arr,csTmp,hv_add_user.len);
                ind_add_user = 0;
DEBUGLOG(("AddTxnBrowserInfo:add_user = [%.*s]\n",hv_add_user.len,hv_add_user.arr));
        }


/* client ip */
        if (GetField_CString(hRls,"ip_addr",&csTmp)) {
                hv_client_ip.len = strlen(csTmp);
                memcpy(hv_client_ip.arr,csTmp,hv_client_ip.len);
                ind_client_ip = 0;
DEBUGLOG(("AddTxnBrowserInfo:client_ip = [%.*s]\n",hv_client_ip.len,hv_client_ip.arr));
        }

	if(ind_user_agent==0){
	    /* EXEC SQL EXECUTE
                BEGIN
			:hv_return_value := sp_txn_browser_info_insert(
					:hv_txn_id:ind_txn_id,
					:hv_client_ip:ind_client_ip,
					:hv_user_agent:ind_user_agent,
					:hv_add_user:ind_add_user);
	        END;
            END-EXEC; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 5;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = "begin :hv_return_value := sp_txn_browser_info_insert ( \
:hv_txn_id:ind_txn_id , :hv_client_ip:ind_client_ip , :hv_user_agent:ind_user\
_agent , :hv_add_user:ind_add_user ) ; END ;";
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
     sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_id;
     sqlstm.sqhstl[1] = (unsigned long )18;
     sqlstm.sqhsts[1] = (         int  )0;
     sqlstm.sqindv[1] = (         short *)&ind_txn_id;
     sqlstm.sqinds[1] = (         int  )0;
     sqlstm.sqharm[1] = (unsigned long )0;
     sqlstm.sqadto[1] = (unsigned short )0;
     sqlstm.sqtdso[1] = (unsigned short )0;
     sqlstm.sqhstv[2] = (unsigned char  *)&hv_client_ip;
     sqlstm.sqhstl[2] = (unsigned long )27;
     sqlstm.sqhsts[2] = (         int  )0;
     sqlstm.sqindv[2] = (         short *)&ind_client_ip;
     sqlstm.sqinds[2] = (         int  )0;
     sqlstm.sqharm[2] = (unsigned long )0;
     sqlstm.sqadto[2] = (unsigned short )0;
     sqlstm.sqtdso[2] = (unsigned short )0;
     sqlstm.sqhstv[3] = (unsigned char  *)&hv_user_agent;
     sqlstm.sqhstl[3] = (unsigned long )257;
     sqlstm.sqhsts[3] = (         int  )0;
     sqlstm.sqindv[3] = (         short *)&ind_user_agent;
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



DEBUGLOG(("AddTxnBrowserInfo:Ret = [%d]\n",hv_return_value));
        	if (hv_return_value == SP_OK) {
DEBUGLOG(("AddTxnBrowserInfo:Normal Exit\n"));
        	        return PD_OK;
        	}

        	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("Transaction_AddTxnBrowserInfo: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("AddTxnBrowserInfo: SP_OTHER_ERR TxnAbort\n"));
			TxnAbort();
        	        return PD_OTHER_ERR;
        	}

        	if (hv_return_value == SP_ERR)  {
ERRLOG("Transaction_AddTxnBrowserInfo: SP_ERR TxnAbort\n");
DEBUGLOG(("AddTxnBrowserInfo: SP_ERR TxnAbort\n"));
			TxnAbort();
        	        return PD_ERR;
        	}
	}
	else{
DEBUGLOG(("AddTxnBrowserInfo:No user_agent, skip logging\n"));
		return PD_OK;
	}
	

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("Transaction_AddTxnBrowserInfo: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("AddTxnBrowserInfo: SP_INTERNAL_ERR TxnAbort\n"));
	TxnAbort();
        return PD_INTERNAL_ERR;
}

int UpdateDeviceType(const char* csTxnId, char cDeviceType)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO updatedevicetype_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		char	hv_device_type;

		short   hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_id.len = strlen(csTxnId);
        memcpy(hv_txn_id.arr, csTxnId, hv_txn_id.len);
DEBUGLOG(("UpdateDeviceType txn_id = [%.*s]\n", hv_txn_id.len, hv_txn_id.arr));

	hv_device_type = cDeviceType;
DEBUGLOG(("UpdateDeviceType device_type = [%c]\n", hv_device_type));

	/* EXEC SQL EXECUTE
                BEGIN
                :hv_return_value := sp_txn_brow_info_upd_dev_type(
                                        :hv_txn_id,
                                        :hv_device_type);

                END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_txn_brow_info_upd_dev_type ( :\
hv_txn_id , :hv_device_type ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_device_type;
 sqlstm.sqhstl[2] = (unsigned long )1;
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
 if (sqlca.sqlcode < 0) goto updatedevicetype_error;
}



DEBUGLOG(("UpdateDeviceType: RET = [%d]\n",hv_return_value));

        if (hv_return_value == SP_OK) {
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("TxnBrowserInfo:UpdateDeviceType: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateDeviceType: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR) {
ERRLOG("TxnBrowserInfo:UpdateDeviceType: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateDeviceType: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

        return PD_OK;

updatedevicetype_error:
DEBUGLOG(("updatedevicetype_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}
