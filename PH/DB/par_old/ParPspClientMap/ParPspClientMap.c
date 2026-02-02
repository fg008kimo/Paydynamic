
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
    "ParPspClientMap.pc"
};


static unsigned int sqlctx = 20040907;


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

 static char *sq0001 = 
"select bm_int_bank_code from bank_mapping , psp_detail , par_psp_client_map\
 where ppm_psp_type_cd = :b0 and ppm_preset_pid = psp_id and psp_channel_code\
 = bm_psp_channel_id and bm_ext_bank_code = :b1            ";

 static char *sq0002 = 
"select psp_detail . psp_id , psp_country . country from psp_country , psp_d\
etail , par_psp_client_map where ppm_psp_type_cd = :b0 and ppm_preset_pid = p\
sp_detail . psp_id and psp_detail . psp_id = psp_country . psp_id            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,211,0,9,68,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
28,0,0,1,0,0,13,70,0,0,1,0,0,1,0,2,9,0,0,
47,0,0,1,0,0,15,86,0,0,0,0,0,1,0,
62,0,0,1,0,0,15,95,0,0,0,0,0,1,0,
77,0,0,2,229,0,9,133,0,2049,1,1,0,1,0,1,9,0,0,
96,0,0,2,0,0,13,135,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
119,0,0,2,0,0,15,159,0,0,0,0,0,1,0,
134,0,0,2,0,0,15,168,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/07/03              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "ParPspClientMap.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void ParPspClientMap(char    cdebug)
{
        cDebug = cdebug;
}

int GetBankCode(hash_t *hRec) 
{
	int iRet = NOT_FOUND;
	char	*csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO get_bankcode_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_psp_type_cd[PAR_PD_PSP_TYPE_CD]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_psp_type_cd;

		/* varchar	hv_ext_bank_code[PD_EXT_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_ext_bank_code;


		/* varchar	v_int_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_int_bank_code;

		short	ind_int_bank_code = -1;
		

        /* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRec, "psp_type_code", &csTmp)) {
		hv_psp_type_cd.len = strlen(csTmp);
		memcpy(hv_psp_type_cd.arr, csTmp, hv_psp_type_cd.len);
DEBUGLOG(("GetBankCode: psp_type_code [%.*s]\n", hv_psp_type_cd.len, hv_psp_type_cd.arr));
	}

	if (GetField_CString(hRec, "gate_id", &csTmp)) {
		hv_ext_bank_code.len = strlen(csTmp);
		memcpy(hv_ext_bank_code.arr, csTmp, hv_ext_bank_code.len);
DEBUGLOG(("GetBankCode: ext_bank_code [%.*s]\n", hv_ext_bank_code.len, hv_ext_bank_code.arr));
	}

        /* EXEC SQL DECLARE c_cursor_get_bank_code CURSOR FOR
		select bm_int_bank_code
		  from bank_mapping, psp_detail, par_psp_client_map
		 where ppm_psp_type_cd = :hv_psp_type_cd
		   and ppm_preset_pid = psp_id
		   and psp_channel_code = bm_psp_channel_id
		   and bm_ext_bank_code = :hv_ext_bank_code; */ 


	/* EXEC SQL OPEN c_cursor_get_bank_code; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_psp_type_cd;
 sqlstm.sqhstl[0] = (unsigned long )52;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_ext_bank_code;
 sqlstm.sqhstl[1] = (unsigned long )22;
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
 if (sqlca.sqlcode < 0) goto get_bankcode_error;
}


	do {
		/* EXEc SQL FETCH c_cursor_get_bank_code
		INTO	:v_int_bank_code:ind_int_bank_code; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 2;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )28;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_int_bank_code;
  sqlstm.sqhstl[0] = (unsigned long )13;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_int_bank_code;
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
  if (sqlca.sqlcode < 0) goto get_bankcode_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}
		
		if (ind_int_bank_code >= 0) {
			v_int_bank_code.arr[v_int_bank_code.len]='\0';
			PutField_CString(hRec, "int_bank_code", (const char *)v_int_bank_code.arr);
DEBUGLOG(("GetBankCode: int_bank_code = [%s]\n", v_int_bank_code.arr));

			iRet = FOUND;
		}
	}while (PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_get_bank_code; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )47;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto get_bankcode_error;
}



DEBUGLOG(("GetBankCode iRet = [%d]\n",iRet));
        return iRet;

get_bankcode_error:
DEBUGLOG(("get_bankcode_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_get_bank_code; */ 

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
}


    return NOT_FOUND;

}

int GetPspID(hash_t *hRec)
{
        int iRet = NOT_FOUND;
        char    *csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO get_psp_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_psp_type_cd[PAR_PD_PSP_TYPE_CD]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_psp_type_cd;


                /* varchar v_psp_id [PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar	v_psp_country[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_psp_country;


		short	ind_psp_id;
		short	ind_psp_country;

        /* EXEC SQL END DECLARE SECTION; */ 


        if (GetField_CString(hRec, "psp_type_code", &csTmp)) {
                hv_psp_type_cd.len = strlen(csTmp);
                memcpy(hv_psp_type_cd.arr, csTmp, hv_psp_type_cd.len);
DEBUGLOG(("GetPspID: psp_type_code [%.*s]\n", hv_psp_type_cd.len, hv_psp_type_cd.arr));
        }


        /* EXEC SQL DECLARE c_cursor_get_pid CURSOR FOR
		select psp_detail.psp_id, psp_country.country
		  from psp_country, psp_detail, par_psp_client_map
		 where ppm_psp_type_cd = :hv_psp_type_cd
		   and ppm_preset_pid = psp_detail.psp_id
		   and psp_detail.psp_id = psp_country.psp_id; */ 


        /* EXEC SQL OPEN c_cursor_get_pid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0002;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )77;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_psp_type_cd;
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
        if (sqlca.sqlcode < 0) goto get_psp_error;
}


        do {
                /* EXEc SQL FETCH c_cursor_get_pid
                INTO    :v_psp_id:ind_psp_id,
			:v_psp_country:ind_psp_country; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 2;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )96;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&v_psp_country;
                sqlstm.sqhstl[1] = (unsigned long )5;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_psp_country;
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
                if (sqlca.sqlcode < 0) goto get_psp_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                if (ind_psp_id >= 0) {
                        v_psp_id.arr[v_psp_id.len]='\0';
                        PutField_CString(hRec, "psp_id", (const char *)v_psp_id.arr);
DEBUGLOG(("GetPspID: psp_id= [%s]\n", v_psp_id.arr));

                        iRet = FOUND;
                }

		if (ind_psp_country >= 0) {
                        v_psp_country.arr[v_psp_country.len]='\0';
                        PutField_CString(hRec, "psp_country", (const char *)v_psp_country.arr);
DEBUGLOG(("GetPspID: psp_country= [%s]\n", v_psp_country.arr));
		}

        }while (PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_get_pid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )119;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto get_psp_error;
}



DEBUGLOG(("GetPspID iRet = [%d]\n",iRet));
        return iRet;

get_psp_error:
DEBUGLOG(("get_psp_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_get_pid; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 2;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )134;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}

 
    return NOT_FOUND;

}


