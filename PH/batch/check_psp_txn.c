
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
           char  filnam[17];
};
static struct sqlcxp sqlfpn =
{
    16,
    "check_psp_txn.pc"
};


static unsigned int sqlctx = 4549323;


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

 static char *sq0003 = 
"select count ( * ) , th_status , th_ar_ind , to_char ( sysdate , 'DD-MON-YY\
YY HH24:MI:SS' ) , to_char ( sysdate - ( :b0 / 1440 ) , 'DD-MON-YYYY HH24:MI:\
SS' ) , to_char ( to_date ( :b1 , 'YYYYMMDDHH24MISS' ) , 'DD-MON-YYYY HH24:MI\
:SS' ) from ( select th_txn_id , th_status , th_ar_ind , th_create_timestamp \
from txn_header , txn_psp_detail where th_txn_id = tp_txn_id and tp_psp_id = \
:b2 and th_txn_code in ( 'DSP' , 'MSI' , 'DSI' ) and th_merchant_id not in ( \
'M8000007' , 'M8000006' ) order by th_create_timestamp DESC ) where th_create\
_timestamp between to_date ( :b1 , 'YYYYMMDDHH24MISS' ) and sysdate - ( :b0 /\
 1440 ) and rownum <= :b5 group by th_ar_ind , th_status            ";

 static char *sq0005 = 
"select psp_name from psp_detail where psp_id = :b0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,0,0,0,56,136,0,0,1,1,0,1,0,3,102,0,0,
24,0,0,1,103,0,6,137,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,2,102,0,0,
51,0,0,0,0,0,13,156,0,0,6,1,0,1,0,1,102,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,
9,0,0,
90,0,0,0,0,0,15,189,0,0,1,1,0,1,0,1,102,0,0,
109,0,0,0,0,0,78,190,0,0,1,1,0,1,0,3,102,0,0,
128,0,0,0,0,0,15,193,0,0,1,1,0,1,0,1,102,0,0,
147,0,0,0,0,0,78,194,0,0,1,1,0,1,0,3,102,0,0,
166,0,0,2,0,0,32,206,0,0,0,0,0,1,0,
181,0,0,3,682,0,9,289,0,2049,6,6,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,3,0,0,
220,0,0,3,0,0,13,291,0,0,6,0,0,1,0,2,3,0,0,2,1,0,0,2,1,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,
259,0,0,3,0,0,15,348,0,0,0,0,0,1,0,
274,0,0,3,0,0,15,401,0,0,0,0,0,1,0,
289,0,0,4,0,0,32,402,0,0,0,0,0,1,0,
304,0,0,5,62,0,9,450,0,2049,1,1,0,1,0,1,9,0,0,
323,0,0,5,0,0,13,452,0,0,1,0,0,1,0,2,9,0,0,
342,0,0,5,0,0,15,469,0,0,0,0,0,1,0,
357,0,0,5,0,0,15,480,0,0,0,0,0,1,0,
372,0,0,6,389,0,5,500,0,0,2,2,0,1,0,1,9,0,0,1,9,0,0,
395,0,0,7,0,0,32,526,0,0,0,0,0,1,0,
410,0,0,8,442,0,4,548,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
437,0,0,9,399,0,5,571,0,0,2,2,0,1,0,1,9,0,0,1,9,0,0,
460,0,0,10,0,0,32,598,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/07/19              LokMan Chow
Include Mobile Payment (MSI)                       2013/03/12              Virginia Yun
table updated and support default rule		   2013/05/13		   LokMan Chow
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include "batchcommon.h"
#include "common.h"
#include "utilitys.h"
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"
#include "ObjPtr.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cs_rate[PD_DATE_LEN + 1];
char    cs_count[PD_DATE_LEN + 1];
char    cs_min_succ[PD_DATE_LEN + 1];
char    cs_check_period[PD_DATE_LEN + 1];
char	cs_txn_period[PD_DATE_LEN + 1];
char	cs_period_from[PD_DATE_LEN + 1];
char    cs_psp_id[PD_PSP_ID_LEN + 1];
char    cs_min_total[PD_DATE_LEN + 1];
char	cs_cutoff_time[PD_DATETIME_LEN+1];
char	cs_buffer_period[PD_DATE_LEN + 1];
char    c_rc_ind;
char	csPspName[PD_PSP_NAME_LEN +1];
char    cDebug;

OBJPTR(DB);
int parse_arg(int argc,char **argv);
int process_txn(unsigned char* csPspId, unsigned char* csCount, unsigned char* csMinCnt);
int find_checking_parameters(unsigned char* csPspId);
int update_last_check(unsigned char* csPspId);
int update_cutoff_auto(unsigned char* csPspId);
char* getPspName(const unsigned  char* csPspId);
int batch_init(int argc, char* argv[])
{

    if (argc < 2) {
        printf("usage: -p psp_id\n");
        //return FAILURE;
    }
    //else
        return SUCCESS;
}




int batch_proc(int argc, char* argv[])
{
        int     iRet;

	iRet = parse_arg(argc,argv);
               
        if (iRet != SUCCESS) {
        	printf("usage: -p psp_id\n");
                return SUCCESS;
        }
	
	strcpy(csPspName,getPspName((const unsigned  char*)cs_psp_id));
        csPspName[strlen(csPspName)]='\0';

	iRet = update_cutoff_auto((unsigned char*)cs_psp_id);

	if(iRet == SUCCESS)
		iRet = find_checking_parameters((unsigned char*)cs_psp_id);

	if(iRet == SUCCESS){

        	iRet = process_txn((unsigned char*)cs_psp_id,(unsigned char*)cs_count,(unsigned char*)cs_min_succ);


	}

	return iRet;


}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


int find_checking_parameters(unsigned char* csPspId)
{
	int     iRet = FAILURE;

	/* EXEC SQL WHENEVER SQLERROR GOTO find_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		short           hv_return_value;

		/* varchar hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;


		int	v_count;
		int	v_min_succ;
		int	v_min_total;
		int	v_buffer_period;
		/* varchar	v_cutoff_time[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_cutoff_time;


		short	ind_psp_id = -1;
		short	ind_count = -1;
		short	ind_min_succ = -1;
		short	ind_min_total = -1;
		short	ind_buffer_period = -1;
		short	ind_cutoff_time = -1;

		SQL_CURSOR      c_cursor_psp_check;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_psp_id.len = strlen((char*)csPspId);
        memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);

	/* EXEC SQL ALLOCATE       :c_cursor_psp_check; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_psp_check;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_psp_txn_check_find(:hv_psp_id:ind_psp_id,
								  :c_cursor_psp_check);


	END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 3;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_psp_txn_check_find ( :h\
v_psp_id:ind_psp_id , :c_cursor_psp_check ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )24;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_psp_id;
        sqlstm.sqhstl[1] = (unsigned long )12;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_psp_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&c_cursor_psp_check;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode < 0) goto find_error;
}



	if (hv_return_value > 0)  {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

		for (;;) {
			ind_count = -1;
			ind_min_succ = -1;
			ind_min_total = -1;
			ind_buffer_period = -1;
			ind_cutoff_time = -1;


                   /* EXEC SQL FETCH :c_cursor_psp_check
		   INTO
			:v_count:ind_count,
			:v_min_succ:ind_min_succ,
			:v_min_total:ind_min_total,
			:v_buffer_period:ind_buffer_period,
			:v_cutoff_time:ind_cutoff_time; */ 

{
                   struct sqlexd sqlstm;
                   sqlstm.sqlvsn = 12;
                   sqlstm.arrsiz = 6;
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
                   sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_psp_check;
                   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                   sqlstm.sqhsts[0] = (         int  )0;
                   sqlstm.sqindv[0] = (         short *)0;
                   sqlstm.sqinds[0] = (         int  )0;
                   sqlstm.sqharm[0] = (unsigned long )0;
                   sqlstm.sqadto[0] = (unsigned short )0;
                   sqlstm.sqtdso[0] = (unsigned short )0;
                   sqlstm.sqhstv[1] = (unsigned char  *)&v_count;
                   sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                   sqlstm.sqhsts[1] = (         int  )0;
                   sqlstm.sqindv[1] = (         short *)&ind_count;
                   sqlstm.sqinds[1] = (         int  )0;
                   sqlstm.sqharm[1] = (unsigned long )0;
                   sqlstm.sqadto[1] = (unsigned short )0;
                   sqlstm.sqtdso[1] = (unsigned short )0;
                   sqlstm.sqhstv[2] = (unsigned char  *)&v_min_succ;
                   sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
                   sqlstm.sqhsts[2] = (         int  )0;
                   sqlstm.sqindv[2] = (         short *)&ind_min_succ;
                   sqlstm.sqinds[2] = (         int  )0;
                   sqlstm.sqharm[2] = (unsigned long )0;
                   sqlstm.sqadto[2] = (unsigned short )0;
                   sqlstm.sqtdso[2] = (unsigned short )0;
                   sqlstm.sqhstv[3] = (unsigned char  *)&v_min_total;
                   sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
                   sqlstm.sqhsts[3] = (         int  )0;
                   sqlstm.sqindv[3] = (         short *)&ind_min_total;
                   sqlstm.sqinds[3] = (         int  )0;
                   sqlstm.sqharm[3] = (unsigned long )0;
                   sqlstm.sqadto[3] = (unsigned short )0;
                   sqlstm.sqtdso[3] = (unsigned short )0;
                   sqlstm.sqhstv[4] = (unsigned char  *)&v_buffer_period;
                   sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
                   sqlstm.sqhsts[4] = (         int  )0;
                   sqlstm.sqindv[4] = (         short *)&ind_buffer_period;
                   sqlstm.sqinds[4] = (         int  )0;
                   sqlstm.sqharm[4] = (unsigned long )0;
                   sqlstm.sqadto[4] = (unsigned short )0;
                   sqlstm.sqtdso[4] = (unsigned short )0;
                   sqlstm.sqhstv[5] = (unsigned char  *)&v_cutoff_time;
                   sqlstm.sqhstl[5] = (unsigned long )17;
                   sqlstm.sqhsts[5] = (         int  )0;
                   sqlstm.sqindv[5] = (         short *)&ind_cutoff_time;
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
                   if (sqlca.sqlcode == 1403) break;
                   if (sqlca.sqlcode < 0) goto find_error;
}



		   if(ind_count<0)
			   v_count = 0;
		   sprintf(cs_count,"%d",v_count);
printf("cs_count = [%s]\n",cs_count);

		   if(ind_min_succ<0)
			   v_min_succ = 0;
		   sprintf(cs_min_succ,"%d",v_min_succ);
printf("cs_min_succ = [%s]\n",cs_min_succ);

		   if(ind_min_total<0)
			   v_min_total= 0;
		   sprintf(cs_min_total,"%d",v_min_total);
printf("cs_min_total = [%s]\n",cs_min_total);

		   if(ind_buffer_period<0)
			   v_buffer_period= 0;
		   sprintf(cs_buffer_period,"%d",v_buffer_period);
printf("cs_buffer_period = [%s]\n",cs_buffer_period);

		   if(ind_cutoff_time>=0){
			   sprintf(cs_cutoff_time,"%.*s",v_cutoff_time.len,v_cutoff_time.arr);
printf("cs_cutoff_time= [%s]\n",cs_cutoff_time);
		   }
		}
		/* EXEC SQL CLOSE :c_cursor_psp_check; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )90;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_psp_check;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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


                /* EXEC SQL FREE :c_cursor_psp_check; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 6;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )109;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_psp_check;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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


	}
	else{
		/* EXEC SQL CLOSE :c_cursor_psp_check; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )128;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_psp_check;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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


                /* EXEC SQL FREE :c_cursor_psp_check; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 6;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )147;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_psp_check;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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


	}

	if((v_count)!=0)
		iRet = SUCCESS;

	return iRet;

find_error:
DEBUGLOG(("find_checking_parameters error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 6;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )166;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}


int process_txn(unsigned char* csPspId, unsigned char* csCount, unsigned char* csMinCnt)
{               
 
        int     iRet = SUCCESS;
        int     iChk = 0;
	int	iPending=0;
	int	iAccept=0;
	int	iReject=0;
	int	iTotal=0;
	int	iOthers=0;
	int	iCh=0;
	int	iCnt = atoi((char*)csCount);
	int	iMinCnt = atoi((char*)csMinCnt);
	int	iMinTotal = atoi((char*)cs_min_total);
	double	dRate=0.0;        
	double	dSuccRate=0.0;        

        /* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		
		/* varchar	hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar	hv_cutoff_time[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_cutoff_time;

		/* varchar	hv_buffer_period[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_buffer_period;

		int	hv_cnt;

		/* varchar	v_from_time[PD_TMP_BUF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_from_time;

		/* varchar	v_time[PD_TMP_BUF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_time;

		/* varchar	v_alert_time[PD_TMP_BUF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_alert_time;

		char	v_status;
		char	v_ar_ind;
		int	v_cnt;

		short	ind_from_time = -1;
		short	ind_time = -1;
		short	ind_alert_time = -1;
		short	ind_status = -1;
		short	ind_ar_ind = -1;
		short	ind_cnt = -1;


	/* EXEC SQL END DECLARE SECTION; */ 


	hv_psp_id.len = strlen((char*)csPspId);
        memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);

	hv_cutoff_time.len = strlen((char*)cs_cutoff_time);
        memcpy(hv_cutoff_time.arr,cs_cutoff_time,hv_cutoff_time.len);

	hv_buffer_period.len = strlen((char*)cs_buffer_period);
        memcpy(hv_buffer_period.arr,cs_buffer_period,hv_buffer_period.len);

	hv_cnt=iCnt;

        /* EXEC SQL DECLARE c_cursor_gettxn CURSOR FOR
		select  count(*),
         		th_status,
         		th_ar_ind,
			to_char(sysdate,'DD-MON-YYYY HH24:MI:SS'),
			to_char(sysdate - (:hv_buffer_period/1440) ,'DD-MON-YYYY HH24:MI:SS'),
			to_char(to_date(:hv_cutoff_time,'YYYYMMDDHH24MISS'),'DD-MON-YYYY HH24:MI:SS')
		from 	(select th_txn_id,
				th_status,
				th_ar_ind,
				th_create_timestamp
			 from	txn_header,
				txn_psp_detail
    			 where	th_txn_id = tp_txn_id
			 and	tp_psp_id  = :hv_psp_id
			 and	th_txn_code in ('DSP','MSI','DSI')
			 and	th_merchant_id not in ('M8000007','M8000006')
			 order by th_create_timestamp DESC)
		where	th_create_timestamp  between to_date(:hv_cutoff_time,'YYYYMMDDHH24MISS') and sysdate-(:hv_buffer_period/1440)
		and	rownum <= :hv_cnt
		group by th_ar_ind,
			 th_status; */ 

                
        /* EXEC SQL OPEN c_cursor_gettxn; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0003;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )181;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_buffer_period;
        sqlstm.sqhstl[0] = (unsigned long )10;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_cutoff_time;
        sqlstm.sqhstl[1] = (unsigned long )16;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_psp_id;
        sqlstm.sqhstl[2] = (unsigned long )12;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_cutoff_time;
        sqlstm.sqhstl[3] = (unsigned long )16;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_buffer_period;
        sqlstm.sqhstl[4] = (unsigned long )10;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_cnt;
        sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
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
        if (sqlca.sqlcode < 0) goto sql_error;
}


        do {    
                /* EXEC SQL FETCH c_cursor_gettxn
                INTO
		 	:v_cnt:ind_cnt,
         		:v_status:ind_status,
         		:v_ar_ind:ind_ar_ind,
		 	:v_alert_time:ind_alert_time,
		 	:v_time:ind_time,
		 	:v_from_time:ind_from_time; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 6;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )220;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_cnt;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_status;
                sqlstm.sqhstl[1] = (unsigned long )1;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_status;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_ar_ind;
                sqlstm.sqhstl[2] = (unsigned long )1;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_ar_ind;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_alert_time;
                sqlstm.sqhstl[3] = (unsigned long )259;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_alert_time;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_time;
                sqlstm.sqhstl[4] = (unsigned long )259;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_time;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_from_time;
                sqlstm.sqhstl[5] = (unsigned long )259;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_from_time;
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
                if (sqlca.sqlcode < 0) goto sql_error;
}




                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		iChk ++;

		if(ind_from_time<0){
			v_from_time.len=0;
			v_from_time.arr[0]='\0';
		}
		if(ind_time<0){
			v_time.len=0;
			v_time.arr[0]='\0';
		}

		if(ind_status>=0){
			if(v_status==PD_COMPLETE){
				if(ind_ar_ind>=0){
					if(v_ar_ind==PD_ACCEPT){
						if(ind_cnt>=0)
							iAccept = v_cnt;
					}
					else if(v_ar_ind==PD_REJECT){
						if(ind_cnt>=0)
							iReject = v_cnt;
					}
				}
				else{
					v_ar_ind=' ';
				}
			}
			else if(v_status==PD_TO_PSP){
				v_ar_ind=' ';
				if(ind_cnt>=0)
					iPending = v_cnt;
			}
			else{
				if(ind_ar_ind<0){
					v_ar_ind=' ';
				}
				if(ind_cnt>=0)
					iOthers = v_cnt;
			}
		}

 	}
        while(PD_TRUE && iRet == SUCCESS);
        /* EXEC SQL CLOSE c_cursor_gettxn; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )259;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto sql_error;
}



	if(iChk==0){
		return iRet;
	}

	iTotal = iAccept+iReject+iPending+iOthers;
	dRate = (double)iMinCnt/(double)iCnt;
	if(iTotal>iMinTotal){
		dSuccRate = (double)(iAccept+iReject)/(double)iTotal;
		if(iTotal<iCnt){
			if(dSuccRate<dRate){
				//printf("<tr><td>-</td><td>Successful rate is low: %.2f (Threshold: %.2f)</td></tr>",dSuccRate*100,dRate*100);
				iRet = FAILURE;
			}
		}
		else{
			if((iPending==iTotal) || ((iAccept+iReject) == 0)){
				//printf("<tr><td>-</td><td>All pending!!!!</td></tr>");
				iRet = FAILURE;
			}
			else{
				if((iAccept+iReject)<iMinCnt){
					//printf("<tr><td>-</td><td>Success rate is low: %.2f (Threshold: %.2f)</td></tr>",((double)iAccept/(double)iTotal)*100,dRate*100);
					iRet = FAILURE;
				}
			}

		}
		if(iRet == FAILURE){
			printf("=============================================================================\n");
			printf("[PSP Name]:	%s\n",csPspName);
			printf("[PSP ID]:	%s\n",csPspId);
			printf("[Success Count]:	%d\n",iAccept+iReject);
			printf("[Pending Count]:	%d\n",iPending);
			printf("[Total Count]:	%d\n",iTotal);
			printf("[Success Rate]:	%.2f%%\n",dSuccRate*100);
			printf("[Threshold Rate]:	%.2f%%\n",dRate*100);
			printf("[Duration]:	%.*s to %.*s\n",v_from_time.len,v_from_time.arr,v_time.len,v_time.arr);
			printf("=============================================================================\n");

			//printf("<tr align=\"center\"><td><b>%s</b> (%s)</td><td>%d</td><td>%d</td><td>%d</td><td>%.2f%%</td><td>%.2f%%</td>",csPspName,csPspId,iAccept+iReject,iPending,iTotal,dSuccRate*100,dRate*100);              
			//printf("<tr><td align=\"right\">Duration:</td><td colspan=\"5\">%.*s to %.*s</td></tr>",v_from_time.len,v_from_time.arr,v_time.len,v_time.arr);
			//printf("<tr><td colspan=\"6\"></td></tr>");
		}
		iCh = update_last_check(csPspId);
	}

        return iRet;
sql_error:
    DEBUGLOG(("process_txn error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_gettxn; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 6;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )274;
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
    sqlstm.arrsiz = 6;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )289;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int parse_arg(int argc,char **argv)
{
        char    c;
	strcpy(cs_psp_id,"");

        while ((c = getopt(argc,argv,"p:")) != EOF) {
                switch (c) {
                        case 'p':
                                strcpy(cs_psp_id, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_psp_id,""))
                return FAILURE;

        return SUCCESS;
}

char* getPspName(const unsigned char* csPspId)
{
	int iRet = PD_NOT_FOUND;
	
	/* EXEC SQL WHENEVER SQLERROR GOTO getname_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

                /* varchar         v_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_name;

                short           ind_name = -1;
                
        /* EXEC SQL END DECLARE SECTION; */ 

                        
        hv_psp_id.len = strlen((const char*)csPspId);
        memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);

	/* EXEC SQL DECLARE c_cursor_getname CURSOR FOR
                select psp_name
                  from psp_detail
                 where psp_id = :hv_psp_id; */ 


	/* EXEC SQL OPEN c_cursor_getname; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0005;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )304;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[0] = (unsigned long )12;
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
 if (sqlca.sqlcode < 0) goto getname_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getname
                INTO
                        :v_name:ind_name; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 6;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )323;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_name;
                sqlstm.sqhstl[0] = (unsigned long )53;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_name;
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
                if (sqlca.sqlcode < 0) goto getname_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

/* psp name */
                if (ind_name >= 0) {
                        v_name.arr[v_name.len] = '\0';
			iRet=PD_FOUND;
                }

	}
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getname; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )342;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getname_error;
}



	if(iRet==PD_FOUND)
	        return strdup((const char *)v_name.arr);
	else
		return strdup("");

getname_error:
DEBUGLOG(("getname_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getname; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )357;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return strdup("");
}


int update_last_check(unsigned char* csPspId)
{
	int	iRet = SUCCESS;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;


        /* EXEC SQL END DECLARE SECTION; */ 


        hv_psp_id.len = strlen((char*)csPspId);
        memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);

        /* EXEC SQL UPDATE	psp_txn_checking
		 SET	pc_last_checking_time = sysdate,
			pc_update_timestamp = sysdate
		 WHERE	pc_party_id =
			(select case when ind = 1 
				then id 
				else '000' 
				end as party_id
			 from 
			   (select a.party_id as id,
				   b.ind  as ind
			    from 
				(select :hv_psp_id as party_id 
				 from dual) a 
				left join 
				(select pc_party_id, 1 as ind 
				 from psp_txn_checking) b 
				on a.party_id = b.pc_party_id) 
			 where id = :hv_psp_id); */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "update psp_txn_checking SET pc_last_checking_time = \
sysdate , pc_update_timestamp = sysdate WHERE pc_party_id = ( select case whe\
n ind = 1 then id else '000' end as party_id from ( select a . party_id as id\
 , b . ind as ind from ( select :b0 as party_id from dual ) a left join ( sel\
ect pc_party_id , 1 as ind from psp_txn_checking ) b on a . party_id = b . pc\
_party_id ) where id = :b0 ) ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )372;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_psp_id;
        sqlstm.sqhstl[0] = (unsigned long )12;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_psp_id;
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
        if (sqlca.sqlcode < 0) goto update_error;
}


	
	return iRet;

update_error:
DEBUGLOG(("update_last_check error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 6;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )395;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}


int update_cutoff_auto(unsigned char* csPspId)
{
	int	iRet = SUCCESS;

	/* EXEC SQL WHENEVER SQLERROR GOTO updatecutoff_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;


		int	v_time_diff;
		short	ind_time_diff = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_psp_id.len = strlen((char*)csPspId);
        memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);

	/* EXEC SQL SELECT to_char(sysdate-1/2,'YYYYMMDDHH24MI') - to_char(pc_cutoff_checking_time,'YYYYMMDDHH24MI')
		 INTO	:v_time_diff:ind_time_diff
		 FROM	psp_txn_checking
		 WHERE	pc_party_id =
			(select case when ind = 1 
				then id 
				else '000' 
				end as party_id
			 from 
			   (select a.party_id as id,
				   b.ind  as ind
			    from 
				(select :hv_psp_id as party_id 
				 from dual) a 
				left join 
				(select pc_party_id, 1 as ind 
				 from psp_txn_checking) b 
				on a.party_id = b.pc_party_id) 
			 where id = :hv_psp_id); */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select to_char ( sysdate - 1 / 2 , 'YYYYMMDDHH24MI' ) - to_\
char ( pc_cutoff_checking_time , 'YYYYMMDDHH24MI' ) INTO :b0:b1 FROM psp_txn_\
checking WHERE pc_party_id = ( select case when ind = 1 then id else '000' en\
d as party_id from ( select a . party_id as id , b . ind as ind from ( select\
 :b2 as party_id from dual ) a left join ( select pc_party_id , 1 as ind from\
 psp_txn_checking ) b on a . party_id = b . pc_party_id ) where id = :b2 ) ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )410;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_time_diff;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_time_diff;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[2] = (unsigned long )12;
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
 if (sqlca.sqlcode < 0) goto updatecutoff_error;
}



	
	if(ind_time_diff>=0){
		if(v_time_diff>0){
        		/* EXEC SQL UPDATE	psp_txn_checking
		 		 SET	pc_cutoff_checking_time = sysdate-1/2,
					pc_update_timestamp = sysdate
				  WHERE	pc_party_id =
					(select case when ind = 1 
						 then id 
						 else '000' 
				 		end as party_id
				 	 from 
				 	     (select a.party_id as id,
				  		     b.ind  as ind
				  		from 
				  		     (select :hv_psp_id as party_id 
				   		      from dual) a 
				  		      left join 
				  		     (select pc_party_id, 1 as ind 
				   		      from psp_txn_checking) b 
				  		      on a.party_id = b.pc_party_id) 
				 	 where id = :hv_psp_id); */ 

{
          struct sqlexd sqlstm;
          sqlstm.sqlvsn = 12;
          sqlstm.arrsiz = 6;
          sqlstm.sqladtp = &sqladt;
          sqlstm.sqltdsp = &sqltds;
          sqlstm.stmt = "update psp_txn_checking SET pc_cutoff_checking_tim\
e = sysdate - 1 / 2 , pc_update_timestamp = sysdate WHERE pc_party_id = ( sel\
ect case when ind = 1 then id else '000' end as party_id from ( select a . pa\
rty_id as id , b . ind as ind from ( select :b0 as party_id from dual ) a lef\
t join ( select pc_party_id , 1 as ind from psp_txn_checking ) b on a . party\
_id = b . pc_party_id ) where id = :b0 ) ";
          sqlstm.iters = (unsigned int  )1;
          sqlstm.offset = (unsigned int  )437;
          sqlstm.cud = sqlcud0;
          sqlstm.sqlest = (unsigned char  *)&sqlca;
          sqlstm.sqlety = (unsigned short)4352;
          sqlstm.occurs = (unsigned int  )0;
          sqlstm.sqhstv[0] = (unsigned char  *)&hv_psp_id;
          sqlstm.sqhstl[0] = (unsigned long )12;
          sqlstm.sqhsts[0] = (         int  )0;
          sqlstm.sqindv[0] = (         short *)0;
          sqlstm.sqinds[0] = (         int  )0;
          sqlstm.sqharm[0] = (unsigned long )0;
          sqlstm.sqadto[0] = (unsigned short )0;
          sqlstm.sqtdso[0] = (unsigned short )0;
          sqlstm.sqhstv[1] = (unsigned char  *)&hv_psp_id;
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
          if (sqlca.sqlcode < 0) goto updatecutoff_error;
}


		}
	}	
	return iRet;

updatecutoff_error:
DEBUGLOG(("update_cutoff error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 6;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )460;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}
