
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
    "ServicePayMethod.pc"
};


static unsigned int sqlctx = 41335851;


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
   unsigned char  *sqhstv[3];
   unsigned long  sqhstl[3];
            int   sqhsts[3];
            short *sqindv[3];
            int   sqinds[3];
   unsigned long  sqharm[3];
   unsigned long  *sqharc[3];
   unsigned short  sqadto[3];
   unsigned short  sqtdso[3];
} sqlstm = {12,3};

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
"select sp_pay_method from service_pay_method Where sp_service_code = :b0 an\
d sp_disabled = '0'            ";

 static char *sq0003 = 
"select pp_psp_id from service_pay_method , psp_pay_method , psp_detail , ps\
p_master Where sp_service_code = :b0 and pp_pay_method = sp_pay_method and ps\
p_id = pp_psp_id and pm_client_id = client_id and disabled = 0 and status = '\
O' and pm_status = 'O' and sp_disabled = 0 and pp_disabled = 0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,107,0,4,55,0,0,3,2,0,1,0,2,1,0,0,1,9,0,0,1,9,0,0,
32,0,0,2,106,0,9,104,0,2049,1,1,0,1,0,1,9,0,0,
51,0,0,2,0,0,13,106,0,0,1,0,0,1,0,2,9,0,0,
70,0,0,2,0,0,15,127,0,0,0,0,0,1,0,
85,0,0,2,0,0,15,136,0,0,0,0,0,1,0,
100,0,0,3,303,0,9,176,0,2049,1,1,0,1,0,1,9,0,0,
119,0,0,3,0,0,13,178,0,0,1,0,0,1,0,2,9,0,0,
138,0,0,3,0,0,15,199,0,0,0,0,0,1,0,
153,0,0,3,0,0,15,208,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/07/29              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "ServicePayMethod.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char    cDebug;

void ServicePayMethod(char    cdebug)
{
        cDebug = cdebug;
}

int IsServicePayMethodSupported(const char* csServiceCode,
                        const char* csPayMethod)
{
	
        /* EXEC SQL WHENEVER SQLERROR GOTO supp_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar	hv_pay_method[PD_PAY_METHOD_LEN]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_pay_method;



		char    v_disabled;

                short   ind_disabled = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


	hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("FindServicePayMethod: service_code = [%.*s][%d]\n",hv_service_code.len,hv_service_code.arr,hv_service_code.len)); 

	hv_pay_method.len = strlen(csPayMethod);
        memcpy(hv_pay_method.arr,csPayMethod,hv_pay_method.len);
DEBUGLOG(("FindServicePayMethod: pay_method = [%.*s][%d]\n",hv_pay_method.len,hv_pay_method.arr,hv_pay_method.len)); 

	/* EXEC SQL select sp_disabled
                   into :v_disabled:ind_disabled
                   from service_pay_method
                  Where sp_service_code = :hv_service_code
                    And sp_pay_method = :hv_pay_method; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select sp_disabled into :b0:b1 from service_pay_method Wher\
e sp_service_code = :b2 And sp_pay_method = :b3 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_disabled;
 sqlstm.sqhstl[0] = (unsigned long )1;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_disabled;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_pay_method;
 sqlstm.sqhstl[2] = (unsigned long )6;
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
 if (sqlca.sqlcode < 0) goto supp_error;
}



        if (ind_disabled >= 0) {
DEBUGLOG(("FindServicePayMethod: sp_disabled = %c\n",v_disabled));
                if (v_disabled != PD_DISABLED)
                        return PD_TRUE;
                else
                        return PD_FALSE;
        }
DEBUGLOG(("FindServicePayMethod: [%s][%s] Pay Method not supported\n",csServiceCode,csPayMethod));

        return PD_FALSE;
supp_error:
DEBUGLOG(("supp_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}

int FindPayMethod(const char* csServiceCode,
                  recordset_t* myRec)
{
	hash_t *myHash;
	
        /* EXEC SQL WHENEVER SQLERROR GOTO find_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;


		/* varchar	v_pay_method[PD_PAY_METHOD_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_pay_method;


                short   ind_pay_method = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


	hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("FindPayMethod: service_code = [%.*s][%d]\n",hv_service_code.len,hv_service_code.arr,hv_service_code.len)); 

	/* EXEC SQL DECLARE c_cursor_find CURSOR FOR
		select	sp_pay_method
		from	service_pay_method
		Where	sp_service_code = :hv_service_code
		and	sp_disabled = '0'; */ 


	/* EXEC SQL OPEN c_cursor_find; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )32;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[0] = (unsigned long )5;
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


        do {
                /* EXEC SQL FETCH c_cursor_find
                INTO
			:v_pay_method:ind_pay_method; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 3;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )51;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_pay_method;
                sqlstm.sqhstl[0] = (unsigned long )7;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_pay_method;
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



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

        	if (ind_pay_method >= 0) {
			v_pay_method.arr[v_pay_method.len] ='\0';
			PutField_CString(myHash,"pay_method",(const char*)v_pay_method.arr);
DEBUGLOG(("FindPayMethod: pay_method = [%s]\n",v_pay_method.arr));
        	}

		RecordSet_Add(myRec,myHash);

	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_find; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )70;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto find_error;
}



DEBUGLOG(("FindPayMethod Normal Exit\n"));
        return PD_OK;

find_error:
DEBUGLOG(("find_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_find; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 3;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )85;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}

int GetPayMethodInfo(const char* csServiceCode,
			recordset_t* myRec)
{
	hash_t *myHash;
	
        /* EXEC SQL WHENEVER SQLERROR GOTO get_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;


		/* varchar	v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;


                short   ind_psp_id = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


	hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("GetPayMethodInfo: service_code = [%.*s][%d]\n",hv_service_code.len,hv_service_code.arr,hv_service_code.len)); 

	/* EXEC SQL DECLARE c_cursor_get CURSOR FOR
		select	pp_psp_id
		from	service_pay_method,
			psp_pay_method,
			psp_detail,
			psp_master
		Where	sp_service_code = :hv_service_code
		and	pp_pay_method = sp_pay_method
		and	psp_id = pp_psp_id
		and	pm_client_id = client_id
		and	disabled = 0
		and	status = 'O'
		and	pm_status = 'O'
		and	sp_disabled = 0
		and	pp_disabled = 0; */ 


	/* EXEC SQL OPEN c_cursor_get; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )100;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[0] = (unsigned long )5;
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
 if (sqlca.sqlcode < 0) goto get_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_get
                INTO
			:v_psp_id:ind_psp_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 3;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )119;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_psp_id;
                sqlstm.sqhstl[0] = (unsigned long )13;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_psp_id;
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
                if (sqlca.sqlcode < 0) goto get_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

        	if (ind_psp_id >= 0) {
			v_psp_id.arr[v_psp_id.len] ='\0';
			PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetPayMethodInfo: psp_id = [%s]\n",v_psp_id.arr));
        	}

		RecordSet_Add(myRec,myHash);

	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_get; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )138;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto get_error;
}



DEBUGLOG(("GetPayMethodInfo Normal Exit\n"));
        return PD_OK;

get_error:
DEBUGLOG(("get_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_get; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 3;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )153;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}
