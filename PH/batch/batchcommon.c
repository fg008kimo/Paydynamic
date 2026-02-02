
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
    "batchcommon.pc"
};


static unsigned int sqlctx = 1121371;


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

 static char *sq0006 = 
"select sys_val from system_control Where sys_code = 'LTPHDATE'            ";

 static char *sq0008 = 
"select sys_val from system_control Where sys_code = 'CTPHDATE'            ";

 static char *sq0010 = 
"select sys_val from system_control Where sys_code = 'LTEODDATE'            ";

 static char *sq0012 = 
"select sys_val from system_control Where sys_code = 'CTEODDATE'            ";

 static char *sq0016 = 
"SELECT rs_release_period FROM def_service_code , rule_service_release_perio\
d WHERE sc_code = rs_service_code AND rs_disabled = 0 AND rs_service_code = :\
b0 AND rs_release_type = :b1            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,0,0,31,52,0,0,0,0,0,1,0,
20,0,0,2,0,0,31,62,0,0,0,0,0,1,0,
35,0,0,3,0,0,31,73,0,0,0,0,0,1,0,
50,0,0,4,0,0,29,77,0,0,0,0,0,1,0,
65,0,0,5,0,0,32,98,0,0,0,0,0,1,0,
80,0,0,6,74,0,9,119,0,2049,0,0,0,1,0,
95,0,0,6,0,0,13,121,0,0,1,0,0,1,0,2,9,0,0,
114,0,0,6,0,0,15,137,0,0,0,0,0,1,0,
129,0,0,6,0,0,15,144,0,0,0,0,0,1,0,
144,0,0,7,0,0,32,145,0,0,0,0,0,1,0,
159,0,0,8,74,0,9,175,0,2049,0,0,0,1,0,
174,0,0,8,0,0,13,177,0,0,1,0,0,1,0,2,9,0,0,
193,0,0,8,0,0,15,192,0,0,0,0,0,1,0,
208,0,0,8,0,0,15,199,0,0,0,0,0,1,0,
223,0,0,9,0,0,32,200,0,0,0,0,0,1,0,
238,0,0,10,75,0,9,223,0,2049,0,0,0,1,0,
253,0,0,10,0,0,13,225,0,0,1,0,0,1,0,2,9,0,0,
272,0,0,10,0,0,15,240,0,0,0,0,0,1,0,
287,0,0,10,0,0,15,247,0,0,0,0,0,1,0,
302,0,0,11,0,0,32,248,0,0,0,0,0,1,0,
317,0,0,12,75,0,9,269,0,2049,0,0,0,1,0,
332,0,0,12,0,0,13,271,0,0,1,0,0,1,0,2,9,0,0,
351,0,0,12,0,0,15,286,0,0,0,0,0,1,0,
366,0,0,12,0,0,15,293,0,0,0,0,0,1,0,
381,0,0,13,0,0,32,294,0,0,0,0,0,1,0,
396,0,0,14,177,0,6,447,0,0,4,4,0,1,0,2,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
427,0,0,15,0,0,32,475,0,0,0,0,0,1,0,
442,0,0,16,192,0,9,517,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
465,0,0,16,0,0,13,519,0,0,1,0,0,1,0,2,3,0,0,
484,0,0,16,0,0,15,536,0,0,0,0,0,1,0,
499,0,0,16,0,0,15,545,0,0,0,0,0,1,0,
514,0,0,17,0,0,32,546,0,0,0,0,0,1,0,
529,0,0,18,175,0,6,588,0,0,5,5,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,2,9,0,0,
564,0,0,19,0,0,32,613,0,0,0,0,0,1,0,
579,0,0,20,139,0,6,644,0,0,3,3,0,1,0,2,9,0,0,1,9,0,0,1,9,0,0,
606,0,0,21,0,0,32,671,0,0,0,0,0,1,0,
621,0,0,22,160,0,6,707,0,0,4,4,0,1,0,1,9,0,0,1,9,0,0,1,3,0,0,2,9,0,0,
652,0,0,23,0,0,32,732,0,0,0,0,0,1,0,
};


/*
Partnerdelight. (c)2010. All rights reserved. No part of this software may be reproduced in any form without written 
permission of an authorized representative of Partnerdelight


Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2010/08/13              Cody Chan
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sqlcpr.h>
#include <sys/types.h>
#include <time.h>

#include "common.h"
#include "utilitys.h"
#include "private_key.h"
#include "dbuser.h"
#include "dbutility.h"
#include "myrecordset.h"
#include "queue_utility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define MY_WEB_TOKEN            "&"
#define MY_WEB_FIELD_TOKEN      "="

char    cDebug;
int         	return_code;

int sql_error(char *msg);
int batch_init(int argc, char** argv);
int batch_proc(int argc, char** argv);
int batch_terminate(int argc, char** argv);
int is_non_holidays(const char* csCountry, const char* csDate);
char* mon_fmt_int2char(int iMon);

int main(int argc, char*argv[])
{

	ConnectDB();

	return_code=batch_init(argc, argv);
        if (return_code == FAILURE) {
DEBUGLOG(("main: section validation error\n"));
            	/* EXEC SQL ROLLBACK; */ 

{
             struct sqlexd sqlstm;
             sqlstm.sqlvsn = 12;
             sqlstm.arrsiz = 0;
             sqlstm.sqladtp = &sqladt;
             sqlstm.sqltdsp = &sqltds;
             sqlstm.iters = (unsigned int  )1;
             sqlstm.offset = (unsigned int  )5;
             sqlstm.cud = sqlcud0;
             sqlstm.sqlest = (unsigned char  *)&sqlca;
             sqlstm.sqlety = (unsigned short)4352;
             sqlstm.occurs = (unsigned int  )0;
             sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


                return(FAILURE);
        }
    	else
        {
/* DEBUGLOG(("main: batch_init() success\n")); */
                return_code=batch_proc(argc, argv);
/* DEBUGLOG(("main: batch_proc return code [%d]\n",return_code));  */
                if (return_code != SUCCESS)
                {
                /* EXEC SQL ROLLBACK; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 0;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )20;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


                        /*return(FAILURE); */
                        return(return_code);
                }
        }

        return_code=batch_terminate(argc, argv);
    /*    printf("main: batch_terminate return code [%d]\n", return_code); */

/* DEBUGLOG(("RET = [%d][%d]\n",return_code,SUCCESS)); */
        if (return_code != SUCCESS) {
            /* EXEC SQL ROLLBACK; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 0;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )35;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


DEBUGLOG(("Rollback\n"));
	}
        else {
                /* EXEC SQL COMMIT WORK; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 0;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )50;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


/* DEBUGLOG(("Commit\n")); */
	}
        return(SUCCESS);
}


int sql_error(char *msg)
{
        char err_msg[128];
        size_t buf_len, msg_len;

        printf("Oracle Error: return code [%d]\n", sqlca.sqlcode);

        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 


        printf("%s\n", msg);
        buf_len = sizeof (err_msg);
        sqlglm((unsigned char *)err_msg, &buf_len, &msg_len);
        printf("%.*s\n", (int)msg_len, err_msg);

        /* EXEC SQL ROLLBACK RELEASE; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 0;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )65;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


DEBUGLOG(("Rollback\n"));
        return FAILURE;
}
int GetLastHostPostingDate(unsigned char* csLastPostingDate)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar v_value[PD_VALUE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_value;


                short   ind_value = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        /* EXEC SQL DECLARE c_cursor_getdate CURSOR FOR
                select sys_val
                  from system_control
                 Where sys_code = 'LTPHDATE'; */ 


        /* EXEC SQL OPEN c_cursor_getdate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 0;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0006;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )80;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto sql_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getdate
                INTO
                        :v_value:ind_value; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 1;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )95;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_value;
                sqlstm.sqhstl[0] = (unsigned long )53;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_value;
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
                if (sqlca.sqlcode < 0) goto sql_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                if (ind_value >= 0) {
                        v_value.arr[v_value.len] = '\0';
                        strcpy((char*)csLastPostingDate,(const char*)v_value.arr);
/* DEBUGLOG(("GetLastHostPostingDate:: lms_date = [%s]\n",csLastPostingDate)); */
                }
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getdate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )114;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto sql_error;
}



        return SUCCESS;
sql_error:
    DEBUGLOG(("get_error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getdate; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )129;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )144;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}



int GetCurrHostPostingDate(unsigned char* csCurrHostPostingDate)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO getcurrlmsdate_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar v_value[PD_VALUE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_value;


                short   ind_value = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        /* EXEC SQL DECLARE c_cursor_getcurrlmsdate CURSOR FOR
                select sys_val
                  from system_control
                 Where sys_code = 'CTPHDATE'; */ 


/*
        EXEC SQL DECLARE c_cursor_getcurrlmsdate CURSOR FOR
                select sys_val
                  from system_control
                 Where sys_code = 'CTPHDATE';
*/

        /* EXEC SQL OPEN c_cursor_getcurrlmsdate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0008;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )159;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getcurrlmsdate_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getcurrlmsdate
                INTO
                        :v_value:ind_value; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 1;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )174;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_value;
                sqlstm.sqhstl[0] = (unsigned long )53;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_value;
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
                if (sqlca.sqlcode < 0) goto getcurrlmsdate_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                if (ind_value >= 0) {
                        v_value.arr[v_value.len] = '\0';
                        strcpy((char*)csCurrHostPostingDate,(const char*)v_value.arr);
                }
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getcurrlmsdate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )193;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getcurrlmsdate_error;
}



        return SUCCESS;
getcurrlmsdate_error:
    DEBUGLOG(("get_error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getcurrlmsdate; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )208;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )223;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}



int GetLastEODDate(unsigned char* csLastEODDate)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO geteoddate_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar v_value[PD_VALUE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_value;


                short   ind_value = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        /* EXEC SQL DECLARE c_cursor_geteoddate CURSOR FOR
                select sys_val
                  from system_control
                 Where sys_code = 'LTEODDATE'; */ 


        /* EXEC SQL OPEN c_cursor_geteoddate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0010;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )238;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto geteoddate_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_geteoddate
                INTO
                        :v_value:ind_value; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 1;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )253;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_value;
                sqlstm.sqhstl[0] = (unsigned long )53;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_value;
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
                if (sqlca.sqlcode < 0) goto geteoddate_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                if (ind_value >= 0) {
                        v_value.arr[v_value.len] = '\0';
                        strcpy((char*)csLastEODDate,(const char*)v_value.arr);
                }
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_geteoddate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )272;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto geteoddate_error;
}



        return SUCCESS;
geteoddate_error:
    DEBUGLOG(("geteoddate_error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_geteoddate; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )287;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )302;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}

int GetCurrEODDate(unsigned char* csCurrEODDate)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO getcurreoddate_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar v_value[PD_VALUE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_value;


                short   ind_value = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        /* EXEC SQL DECLARE c_cursor_getcurreoddate CURSOR FOR
                select sys_val
                  from system_control
                 Where sys_code = 'CTEODDATE'; */ 


        /* EXEC SQL OPEN c_cursor_getcurreoddate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0012;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )317;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getcurreoddate_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getcurreoddate
                INTO
                        :v_value:ind_value; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 1;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )332;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_value;
                sqlstm.sqhstl[0] = (unsigned long )53;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_value;
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
                if (sqlca.sqlcode < 0) goto getcurreoddate_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                if (ind_value >= 0) {
                        v_value.arr[v_value.len] = '\0';
                        strcpy((char*)csCurrEODDate,(const char*)v_value.arr);
                }
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getcurreoddate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )351;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getcurreoddate_error;
}



        return SUCCESS;
getcurreoddate_error:
    DEBUGLOG(("getcurreoddate_error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getcurreoddate; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )366;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )381;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}


int CreateReportPath(unsigned char* csPspId,unsigned char* csCurrentPath)
{
	char    csHostDate[PD_DATE_LEN + 1];
	char    cs_outfile_name[PD_MAX_FILE_LEN + 1];

        if (GetCurrEODDate((unsigned char*)csHostDate) != SUCCESS)
                return FAILURE;

/* create report path */
        sprintf((char*)csCurrentPath, "%s", getenv("REPORT_HOME"));
        sprintf((char*)cs_outfile_name, "mkdir %s >/dev/null 2>&1", csCurrentPath);
        system(cs_outfile_name);

        sprintf((char*)csCurrentPath, "%s/%.*s", getenv("REPORT_HOME"),PD_YYYY_LEN,csHostDate);
        sprintf((char*)cs_outfile_name, "mkdir %s >/dev/null 2>&1", csCurrentPath);
        system(cs_outfile_name);

        sprintf((char*)csCurrentPath, "%s/%.*s/%s", getenv("REPORT_HOME"),PD_YYYY_LEN,csHostDate,csPspId);
        sprintf((char*)cs_outfile_name, "mkdir %s >/dev/null 2>&1", csCurrentPath);
        system(cs_outfile_name);

        sprintf((char*)csCurrentPath, "%s/%.*s/%s/%.*s", getenv("REPORT_HOME"),PD_YYYY_LEN,csHostDate,csPspId,PD_YYYYMM_LEN,csHostDate);
        sprintf((char*)cs_outfile_name, "mkdir %s >/dev/null 2>&1", csCurrentPath);
        system(cs_outfile_name);

        sprintf((char*)csCurrentPath, "%s/%.*s/%s/%.*s/%s", getenv("REPORT_HOME"), PD_YYYY_LEN,csHostDate,csPspId,PD_YYYYMM_LEN,csHostDate,csHostDate);
        sprintf((char*)cs_outfile_name, "mkdir %s >/dev/null 2>&1", csCurrentPath);

        system(cs_outfile_name);

/* create report data folder if not created */
        sprintf((char*)cs_outfile_name, "mkdir %s >/dev/null 2>&1", getenv("REPORT_DATA"));
       system(cs_outfile_name);

	return SUCCESS;
}


int CreateReportPathD(unsigned char* csCurrentPath)
{
	char    csHostDate[PD_DATE_LEN + 1];
	char    cs_outfile_name[PD_MAX_FILE_LEN + 1];

        if (GetCurrEODDate((unsigned char *)csHostDate) != SUCCESS)
                return FAILURE;

/* create report path */
        sprintf((char*)csCurrentPath, "%s", getenv("REPORT_HOME"));
        sprintf((char*)cs_outfile_name, "mkdir %s >/dev/null 2>&1", csCurrentPath);
        system(cs_outfile_name);

        sprintf((char*)csCurrentPath, "%s/%.*s", getenv("REPORT_HOME"),PD_YYYY_LEN,csHostDate);
        sprintf((char*)cs_outfile_name, "mkdir %s >/dev/null 2>&1", csCurrentPath);
        system(cs_outfile_name);

        sprintf((char*)csCurrentPath, "%s/%.*s/%.*s", getenv("REPORT_HOME"),PD_YYYY_LEN,csHostDate,PD_YYYYMM_LEN,csHostDate);
        sprintf((char*)cs_outfile_name, "mkdir %s >/dev/null 2>&1", csCurrentPath);
        system(cs_outfile_name);

        sprintf((char*)csCurrentPath, "%s/%.*s/%.*s/%s", getenv("REPORT_HOME"), PD_YYYY_LEN,csHostDate,PD_YYYYMM_LEN,csHostDate,csHostDate);
        sprintf((char*)cs_outfile_name, "mkdir %s >/dev/null 2>&1", csCurrentPath);

        system(cs_outfile_name);

/* create report data folder if not created */
        sprintf((char*)cs_outfile_name, "mkdir %s >/dev/null 2>&1", getenv("REPORT_DATA"));
       system(cs_outfile_name);

	return SUCCESS;
}


int CreateReportPathCustomized(unsigned char* csCurrentPath,const char* csHostDate)
{
        char    cs_outfile_name[PD_MAX_FILE_LEN + 1];

/* create report path */
        sprintf((char*)csCurrentPath, "%s", getenv("REPORT_HOME"));
        sprintf((char*)cs_outfile_name, "mkdir %s >/dev/null 2>&1", csCurrentPath);
        system(cs_outfile_name);

        sprintf((char*)csCurrentPath, "%s/%.*s", getenv("REPORT_HOME"),PD_YYYY_LEN,csHostDate);
        sprintf((char*)cs_outfile_name, "mkdir %s >/dev/null 2>&1", csCurrentPath);
        system(cs_outfile_name);

        sprintf((char*)csCurrentPath, "%s/%.*s/%.*s", getenv("REPORT_HOME"),PD_YYYY_LEN,csHostDate,PD_YYYYMM_LEN,csHostDate);
        sprintf((char*)cs_outfile_name, "mkdir %s >/dev/null 2>&1", csCurrentPath);
        system(cs_outfile_name);

        sprintf((char*)csCurrentPath, "%s/%.*s/%.*s/%s", getenv("REPORT_HOME"), PD_YYYY_LEN,csHostDate,PD_YYYYMM_LEN,csHostDate,csHostDate);
        sprintf((char*)cs_outfile_name, "mkdir %s >/dev/null 2>&1", csCurrentPath);

        system(cs_outfile_name);

/* create report data folder if not created */
        sprintf((char*)cs_outfile_name, "mkdir %s >/dev/null 2>&1", getenv("REPORT_DATA"));
       system(cs_outfile_name);

        return SUCCESS;
}


int is_weekend(const char* csDate)
{
        int iRet = PD_FALSE;
        int iDow;

        iDow = day_of_week((const unsigned char *)csDate);
DEBUGLOG(("is_weekend: date[%s] day of week [%d]\n",csDate,iDow));
        if((iDow==0)||(iDow==6)){
                iRet = PD_TRUE;
        }

        return iRet;
}


int is_holidays(const char* csCountry, const char* csServiceCode, const char* csDate)
{
        int iRet = PD_FALSE;

        /* EXEC SQL WHENEVER SQLERROR GOTO is_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

                /* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                /* varchar hv_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_date;


                /* varchar v_desc[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_desc;


                short   ind_desc = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_date.len = strlen(csDate);
        memcpy(hv_date.arr,csDate,hv_date.len);
DEBUGLOG(("is_holidays date = [%.*s]\n",hv_date.len,hv_date.arr));

        hv_country.len = strlen(csCountry);
        memcpy(hv_country.arr,csCountry,hv_country.len);
DEBUGLOG(("is_holidays country = [%.*s]\n",hv_country.len,hv_country.arr));

        hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("is_holidays service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

        /* EXEC SQL EXECUTE
        BEGIN
                select  h_desc
                into    :v_desc:ind_desc
                from    holiday
                where   h_date=:hv_date
                and     h_country=:hv_country
                and     h_service_code=:hv_service_code
		and	h_is_non_holiday = 0;

        END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin select h_desc into :v_desc:ind_desc from holid\
ay where h_date = :hv_date and h_country = :hv_country and h_service_code = :\
hv_service_code and h_is_non_holiday = 0 ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )396;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_desc;
        sqlstm.sqhstl[0] = (unsigned long )53;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_desc;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_date;
        sqlstm.sqhstl[1] = (unsigned long )10;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_country;
        sqlstm.sqhstl[2] = (unsigned long )4;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
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
        if (sqlca.sqlcode < 0) goto is_error;
}



        if(ind_desc>=0){
DEBUGLOG(("is holiday [%.*s]\n",v_desc.len,v_desc.arr));
                iRet = PD_TRUE;
        }
/*	if(is_weekend(csDate)==PD_TRUE){
		iRet = is_non_holidays(csCountry,csDate);
        }
*/
        return iRet;

is_error:
    DEBUGLOG(("is_holidays error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    ERRLOG("handle_daily_float::is_holidays error code %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )427;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}


int FindServiceReleasePeriod(const char* csServiceCode,
				const char* csReleaseType,	
				int* iReleasePeriod)
{

        int     iRet = SUCCESS;

DEBUGLOG(("FindServiceReleasePeriod\n"));
        /* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar	hv_release_type[PD_RLS_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_release_type;

                short   v_release_period;

                short   ind_release_period = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("FindServiceRelease service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

	hv_release_type.len = strlen(csReleaseType);
        memcpy(hv_release_type.arr,csReleaseType,hv_release_type.len);
DEBUGLOG(("FindServiceRelease release_type = [%.*s]\n",hv_release_type.len,hv_release_type.arr));

        /* EXEC SQL DECLARE c_cursor_get_service CURSOR FOR
                SELECT  rs_release_period
                  FROM  def_service_code,
                        rule_service_release_period
                 WHERE sc_code = rs_service_code
                   AND rs_disabled = 0
		   AND rs_service_code = :hv_service_code
                   AND rs_release_type = :hv_release_type; */ 


        /* EXEC SQL OPEN c_cursor_get_service; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0016;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )442;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_release_type;
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
        if (sqlca.sqlcode < 0) goto sql_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_get_service
                INTO
                        v_release_period:ind_release_period; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 4;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )465;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_release_period;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_release_period;
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
                if (sqlca.sqlcode < 0) goto sql_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                if (ind_release_period >= 0) {
DEBUGLOG(("FindServiceReleasePeriod release period = [%d]\n",v_release_period));
			*iReleasePeriod = v_release_period;
                }
		else 
			*iReleasePeriod = 0;


        }while(PD_TRUE);
        /* EXEC SQL CLOSE c_cursor_get_service; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )484;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto sql_error;
}



        return  iRet;

sql_error:
    DEBUGLOG(("FindServiceReleasePeriod error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    ERRLOG("batchcomm::FindServiceReleasePeriod sql error %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_get_service; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )499;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )514;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}

char* FindPostingDate(const char* csCountry,
			const char* csServiceCode,
			const char* csCurrentPostingDate,
				int iReleasePeriod)
{

	static	char	csDate[PD_DATE_LEN +1];

DEBUGLOG(("FindPostingDate\n"));
        /* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

		/* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar	hv_posting_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_posting_date;

                short   hv_release_period;

		/* varchar	v_posting_date[PD_DATE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_posting_date;


		short	ind_posting_date = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


	hv_country.len = strlen(csCountry);
        memcpy(hv_country.arr,csCountry,hv_country.len);
DEBUGLOG(("FindPostingDate country = [%.*s]\n",hv_country.len,hv_country.arr));

	hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("FindPostingDate service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

	hv_posting_date.len = strlen(csCurrentPostingDate);
        memcpy(hv_posting_date.arr,csCurrentPostingDate,hv_posting_date.len);
DEBUGLOG(("FindPostingDate CurrentPostingDate = [%.*s]\n",hv_posting_date.len,hv_posting_date.arr));

	hv_release_period = iReleasePeriod;
DEBUGLOG(("FindPostingDate release period = [%d]\n",hv_release_period));

        /* EXEC SQL EXECUTE
        BEGIN
                select  release_pkg.find_release_date(:hv_posting_date,:hv_country,:hv_service_code,:hv_release_period)
                into    :v_posting_date:ind_posting_date
                from    dual;

        END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin select release_pkg . find_release_date ( :hv_p\
osting_date , :hv_country , :hv_service_code , :hv_release_period ) into :v_p\
osting_date:ind_posting_date from dual ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )529;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_posting_date;
        sqlstm.sqhstl[0] = (unsigned long )10;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_country;
        sqlstm.sqhstl[1] = (unsigned long )4;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_release_period;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&v_posting_date;
        sqlstm.sqhstl[4] = (unsigned long )11;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_posting_date;
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
        if (sqlca.sqlcode < 0) goto sql_error;
}




	if (ind_posting_date >= 0) {
		v_posting_date.arr[v_posting_date.len] = '\0';
DEBUGLOG(("FindPostingDate posting_date = [%.*s]\n",v_posting_date.len,v_posting_date.arr));
		strcpy(csDate,(const char*)v_posting_date.arr);
	}
	else {
		csDate[0] ='\0';
	}
        return csDate;

sql_error:
    DEBUGLOG(("FindPostingDate error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    ERRLOG("batchcomm::FindServiceReleasePeriod sql error %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )564;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return NULL;
}


int is_non_holidays(const char* csCountry, const char* csDate)
{
        int iRet = PD_FALSE;

        /* EXEC SQL WHENEVER SQLERROR GOTO isn_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

                /* varchar hv_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_date;


                /* varchar v_desc[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_desc;


                short   ind_desc = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_date.len = strlen(csDate);
        memcpy(hv_date.arr,csDate,hv_date.len);
DEBUGLOG(("is_non_holidays date = [%.*s]\n",hv_date.len,hv_date.arr));

        hv_country.len = strlen(csCountry);
        memcpy(hv_country.arr,csCountry,hv_country.len);
DEBUGLOG(("is_non_holidays country = [%.*s]\n",hv_country.len,hv_country.arr));

        /* EXEC SQL EXECUTE
        BEGIN
                select  h_desc
                into    :v_desc:ind_desc
                from    holiday
                where   h_date=:hv_date
                and     h_country=:hv_country
		and	h_is_non_holiday = 1;

        END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin select h_desc into :v_desc:ind_desc from holid\
ay where h_date = :hv_date and h_country = :hv_country and h_is_non_holiday =\
 1 ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )579;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_desc;
        sqlstm.sqhstl[0] = (unsigned long )53;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_desc;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_date;
        sqlstm.sqhstl[1] = (unsigned long )10;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_country;
        sqlstm.sqhstl[2] = (unsigned long )4;
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
        if (sqlca.sqlcode < 0) goto isn_error;
}



        if(ind_desc>=0){
DEBUGLOG(("Non-Holiday!! [%.*s]\n",v_desc.len,v_desc.arr));
        }
        else{
DEBUGLOG(("Holiday\n"));
                iRet = PD_TRUE;
        }

        return iRet;

isn_error:
    DEBUGLOG(("is_non_holidays error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("batchcommon::is_holidays error code %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )606;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}

char* FindVNCPostingDate(const char* csCountry,
                        const char* csCurrentPostingDate,
                                int iReleasePeriod)
{

        static  char    csDate[PD_DATE_LEN +1];

DEBUGLOG(("FindVNCPostingDate\n"));
        /* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

                /* varchar hv_posting_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_posting_date;

                short   hv_release_period;

                /* varchar v_posting_date[PD_DATE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_posting_date;


                short   ind_posting_date = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_country.len = strlen(csCountry);
        memcpy(hv_country.arr,csCountry,hv_country.len);
DEBUGLOG(("FindVNCPostingDate country = [%.*s]\n",hv_country.len,hv_country.arr));

        hv_posting_date.len = strlen(csCurrentPostingDate);
        memcpy(hv_posting_date.arr,csCurrentPostingDate,hv_posting_date.len);
DEBUGLOG(("FindVNCPostingDate CurrentPostingDate = [%.*s]\n",hv_posting_date.len,hv_posting_date.arr));

        hv_release_period = iReleasePeriod;
DEBUGLOG(("FindVNCPostingDate release period = [%d]\n",hv_release_period));

        /* EXEC SQL EXECUTE
        BEGIN
                select  release_pkg.find_vnc_release_date(:hv_posting_date,:hv_country,:hv_release_period)
                into    :v_posting_date:ind_posting_date
                from    dual;

        END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin select release_pkg . find_vnc_release_date ( :\
hv_posting_date , :hv_country , :hv_release_period ) into :v_posting_date:ind\
_posting_date from dual ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )621;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_posting_date;
        sqlstm.sqhstl[0] = (unsigned long )10;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_country;
        sqlstm.sqhstl[1] = (unsigned long )4;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_release_period;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&v_posting_date;
        sqlstm.sqhstl[3] = (unsigned long )11;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_posting_date;
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
        if (sqlca.sqlcode < 0) goto sql_error;
}




        if (ind_posting_date >= 0) {
                v_posting_date.arr[v_posting_date.len] = '\0';
DEBUGLOG(("FindVNCPostingDate posting_date = [%.*s]\n",v_posting_date.len,v_posting_date.arr));
                strcpy(csDate,(const char*)v_posting_date.arr);
        }
        else {
                csDate[0] ='\0';
        }
        return csDate;

sql_error:
    DEBUGLOG(("FindVNCPostingDate error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    ERRLOG("batchcomm::FindServiceReleasePeriod sql error %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )652;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return NULL;
}

