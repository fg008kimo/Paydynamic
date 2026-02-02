
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
    "OLSignAuthParam.pc"
};


static unsigned int sqlctx = 20453011;


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

 static char *sq0001 = 
"select osap_seq , osap_tag_name , osap_field_name from ol_sign_auth_param w\
here osap_channel_code = :b0 and osap_txn_code = :b1 and osap_version = :b2 a\
nd osap_direction = :b3 and osap_disabled = 0 order by osap_seq            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,227,0,9,86,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,1,0,0,
36,0,0,1,0,0,13,88,0,0,3,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,
63,0,0,1,0,0,15,131,0,0,0,0,0,1,0,
78,0,0,1,0,0,15,140,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2018. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description						Change Date			Change By
-------------------------------					------------			--------------
Init Version							2018/12/12			Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "OLSignAuthParam.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "internal.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char	cDebug;

void OLSignAuthParam(char	cdebug)
{
	cDebug = cdebug;
}

int GetParam(const char* csChannelCode,
             const char* csTxnCode,
	     const char* csVer,
	     const char cDirection,
             recordset_t* myRec)
{
        int iRet = PD_NOT_FOUND;
	int iCnt = 0;
        hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getparam_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_channel_code[PD_CHANNEL_CODE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_channel_code;

                /* varchar hv_txn_code[PD_TXN_CODE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_txn_code;

                /* varchar hv_ver[PD_OL_KEY_VER_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_ver;

		char   	hv_direction;

		int	v_seq;
                /* varchar v_tag_name[PD_TAG_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_tag_name;

                /* varchar v_field_name[PD_TAG_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_field_name;


		short   ind_seq = -1;
                short   ind_tag_name = -1;
                short   ind_field_name = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_channel_code.len = strlen(csChannelCode);
        memcpy(hv_channel_code.arr,csChannelCode,hv_channel_code.len);
DEBUGLOG(("GetParam: channel code = [%.*s][%d]\n",hv_channel_code.len,hv_channel_code.arr,hv_channel_code.len));

        hv_txn_code.len = strlen(csTxnCode);
        memcpy(hv_txn_code.arr,csTxnCode,hv_txn_code.len);
DEBUGLOG(("GetParam: txn code = [%.*s][%d]\n",hv_txn_code.len,hv_txn_code.arr,hv_txn_code.len));

	hv_ver.len = strlen(csVer);
        memcpy(hv_ver.arr,csVer,hv_ver.len);
DEBUGLOG(("GetParam: version = [%.*s][%d]\n",hv_ver.len,hv_ver.arr,hv_ver.len));

	hv_direction = cDirection;
DEBUGLOG(("GetParam: direction = [%c]\n",hv_direction));

        /* EXEC SQL DECLARE c_cursor_getparam CURSOR FOR
                 select osap_seq,
                        osap_tag_name,
                        osap_field_name
                   from ol_sign_auth_param
                  where osap_channel_code = :hv_channel_code
                    and osap_txn_code = :hv_txn_code
                    and osap_version = :hv_ver
                    and osap_direction = :hv_direction
		    and osap_disabled = 0
	       order by osap_seq; */ 
	

        /* EXEC SQL OPEN c_cursor_getparam; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
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
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_channel_code;
        sqlstm.sqhstl[0] = (unsigned long )6;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_code;
        sqlstm.sqhstl[1] = (unsigned long )6;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_ver;
        sqlstm.sqhstl[2] = (unsigned long )8;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_direction;
        sqlstm.sqhstl[3] = (unsigned long )1;
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
        if (sqlca.sqlcode < 0) goto getparam_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getparam
                INTO
                        :v_seq:ind_seq,
                        :v_tag_name:ind_tag_name,
                        :v_field_name:ind_field_name; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 4;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )36;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_seq;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_seq;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_tag_name;
                sqlstm.sqhstl[1] = (unsigned long )28;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_tag_name;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_field_name;
                sqlstm.sqhstl[2] = (unsigned long )28;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_field_name;
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
                if (sqlca.sqlcode < 0) goto getparam_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

		if (ind_seq >= 0) {
                        PutField_Int(myHash,"seq",v_seq);
DEBUGLOG((" seq = [%d]\n",v_seq));
                }

                if (ind_tag_name >= 0) {
                        v_tag_name.arr[v_tag_name.len] ='\0';
                        PutField_CString(myHash,"tag_name",(const char*)v_tag_name.arr);
DEBUGLOG((" tag_name = [%s]\n",v_tag_name.arr));
                }

                if (ind_field_name >= 0) {
                        v_field_name.arr[v_field_name.len] ='\0';
                        PutField_CString(myHash,"field_name",(const char*)v_field_name.arr);
DEBUGLOG((" field_name = [%s]\n",v_field_name.arr));
                }

		iCnt++;

                RecordSet_Add(myRec,myHash);

        }while(PD_TRUE);

	if (iCnt > 0) {
DEBUGLOG(("GetParam Found\n"));
		iRet = PD_FOUND;
	} else {
DEBUGLOG(("GetParam Not Found\n"));
	}

        /* EXEC SQL CLOSE c_cursor_getparam; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )63;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getparam_error;
}



DEBUGLOG(("GetParam Normal Exit iRet[%d]\n",iRet));
        return iRet;

getparam_error:
DEBUGLOG(("getparam_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getparam; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )78;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}

