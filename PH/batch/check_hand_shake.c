
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
    "check_hand_shake.pc"
};


static unsigned int sqlctx = 36311827;


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
   unsigned char  *sqhstv[11];
   unsigned long  sqhstl[11];
            int   sqhsts[11];
            short *sqindv[11];
            int   sqinds[11];
   unsigned long  sqharm[11];
   unsigned long  *sqharc[11];
   unsigned short  sqadto[11];
   unsigned short  sqtdso[11];
} sqlstm = {12,11};

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
"n ( 'DSI' ) ) on ( ( th_ar_ind is no\
t NULL and th_ar_ind = dm_ar_ind and th_status = dm_status ) or ( th_ar_ind i\
s NULL and th_status = dm_status ) ) and th_txn_code = dm_txn_code ) group by\
 th_merchant_id , name , th_status , th_ar_ind , dm_status_desc , th_sub_stat\
us , ds_name order by th_merchant_id            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,0,0,0,56,127,0,0,1,1,0,1,0,3,102,0,0,
24,0,0,1,81,0,6,128,0,0,2,2,0,1,0,2,3,0,0,2,102,0,0,
47,0,0,0,0,0,13,146,0,0,6,1,0,1,0,1,102,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,
9,0,0,
86,0,0,0,0,0,15,175,0,0,1,1,0,1,0,1,102,0,0,
105,0,0,0,0,0,78,176,0,0,1,1,0,1,0,3,102,0,0,
124,0,0,0,0,0,15,179,0,0,1,1,0,1,0,1,102,0,0,
143,0,0,0,0,0,78,180,0,0,1,1,0,1,0,3,102,0,0,
162,0,0,2,0,0,32,192,0,0,0,0,0,1,0,
177,0,0,3,1339,0,9,331,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
208,0,0,3,0,0,13,333,0,0,11,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,1,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
267,0,0,3,0,0,15,449,0,0,0,0,0,1,0,
282,0,0,3,0,0,15,525,0,0,0,0,0,1,0,
297,0,0,4,0,0,32,526,0,0,0,0,0,1,0,
312,0,0,5,116,0,5,547,0,0,1,1,0,1,0,1,9,0,0,
331,0,0,6,0,0,32,573,0,0,0,0,0,1,0,
346,0,0,7,170,0,4,596,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
369,0,0,8,127,0,5,619,0,0,1,1,0,1,0,1,9,0,0,
388,0,0,9,0,0,32,648,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/06/27              LokMan Chow
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
char    cs_max_hand_shake[PD_DATE_LEN + 1];
char    cs_check_period[PD_DATE_LEN + 1];
char	cs_txn_period[PD_DATE_LEN + 1];
char	cs_period_from[PD_DATE_LEN + 1];
char    cs_merchant_id[PD_PSP_ID_LEN + 1];
char    cs_min_total[PD_DATE_LEN + 1];
char	cs_cutoff_time[PD_DATETIME_LEN+1];
char	cs_buffer_period[PD_DATE_LEN + 1];
char    c_rc_ind;
char    cDebug;

OBJPTR(DB);
int process_txn(unsigned char* csCount, unsigned char* csMaxCnt);
int find_checking_parameters();
int update_last_check();
int update_cutoff_auto();
int batch_init(int argc, char* argv[])
{

/*    if (argc < 2) {
        printf("usage: -p psp_id\n");
        //return FAILURE;
    }
*/
    //else
        return SUCCESS;
}




int batch_proc(int argc, char* argv[])
{
        int     iRet;
/*
	iRet = parse_arg(argc,argv);
               
        if (iRet != SUCCESS) {
        	printf("usage: -p psp_id\n");
                return SUCCESS;
        }
*/	
/*
	strcpy(csPspName,getPspName((const unsigned  char*)cs_psp_id));
        csPspName[strlen(csPspName)]='\0';
*/
	iRet = update_cutoff_auto();

	if(iRet == SUCCESS)
		iRet = find_checking_parameters();

	if(iRet == SUCCESS){

        	iRet = process_txn((unsigned char*)cs_count,(unsigned char*)cs_max_hand_shake);


	}

	return iRet;


}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


int find_checking_parameters()
{
	int     iRet = FAILURE;

	/* EXEC SQL WHENEVER SQLERROR GOTO find_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		short	hv_return_value;

		int	v_count;
		int	v_max_hand_shake;
		int	v_min_total;
		int	v_buffer_period;
		/* varchar	v_cutoff_time[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_cutoff_time;


		short	ind_count = -1;
		short	ind_max_hand_shake = -1;
		short	ind_min_total = -1;
		short	ind_buffer_period = -1;
		short	ind_cutoff_time = -1;

		SQL_CURSOR      c_cursor_hs_check;

	/* EXEC SQL END DECLARE SECTION; */ 


	/* EXEC SQL ALLOCATE       :c_cursor_hs_check; */ 

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
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_hs_check;
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
                        :hv_return_value := sp_hand_shake_check_find(:c_cursor_hs_check);


	END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_hand_shake_check_find (\
 :c_cursor_hs_check ) ; END ;";
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
        sqlstm.sqhstv[1] = (unsigned char  *)&c_cursor_hs_check;
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
        if (sqlca.sqlcode < 0) goto find_error;
}



	if (hv_return_value > 0)  {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

		for (;;) {
			ind_count = -1;
			ind_max_hand_shake = -1;
			ind_min_total = -1;
			ind_buffer_period = -1;
			ind_cutoff_time = -1;


                   /* EXEC SQL FETCH :c_cursor_hs_check
		   INTO
			:v_count:ind_count,
			:v_max_hand_shake:ind_max_hand_shake,
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
                   sqlstm.offset = (unsigned int  )47;
                   sqlstm.selerr = (unsigned short)1;
                   sqlstm.cud = sqlcud0;
                   sqlstm.sqlest = (unsigned char  *)&sqlca;
                   sqlstm.sqlety = (unsigned short)4352;
                   sqlstm.occurs = (unsigned int  )0;
                   sqlstm.sqfoff = (         int )0;
                   sqlstm.sqfmod = (unsigned int )2;
                   sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_hs_check;
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
                   sqlstm.sqhstv[2] = (unsigned char  *)&v_max_hand_shake;
                   sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
                   sqlstm.sqhsts[2] = (         int  )0;
                   sqlstm.sqindv[2] = (         short *)&ind_max_hand_shake;
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

		   if(ind_max_hand_shake<0)
			   v_max_hand_shake = 0;
		   sprintf(cs_max_hand_shake,"%d",v_max_hand_shake);

		   if(ind_min_total<0)
			   v_min_total= 0;
		   sprintf(cs_min_total,"%d",v_min_total);

		   if(ind_buffer_period<0)
			   v_buffer_period= 0;
		   sprintf(cs_buffer_period,"%d",v_buffer_period);

		   if(ind_cutoff_time>=0){
			   sprintf(cs_cutoff_time,"%.*s",v_cutoff_time.len,v_cutoff_time.arr);
		   }
//printf("[%d][%d][%d][%d][%s]\n",v_count,v_max_hand_shake,v_min_total,v_buffer_period,cs_cutoff_time);
		}
		/* EXEC SQL CLOSE :c_cursor_hs_check; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )86;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_hs_check;
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


                /* EXEC SQL FREE :c_cursor_hs_check; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 6;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )105;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_hs_check;
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
		/* EXEC SQL CLOSE :c_cursor_hs_check; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )124;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_hs_check;
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


                /* EXEC SQL FREE :c_cursor_hs_check; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 6;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )143;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_hs_check;
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
    sqlstm.offset = (unsigned int  )162;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}


int process_txn(unsigned char* csCount, unsigned char* csMaxCnt)
{               
 
        int     iRet = SUCCESS;
        int     iResult = SUCCESS;
        int     iChk = 0;
	//int	iPending=0;
	//int	iAccept=0;
	//int	iReject=0;
	int	iTotal=0;
	//int	iOthers=0;
	int	iCh=0;
	int	iCnt = atoi((char*)csCount);
	int	iMaxCnt = atoi((char*)csMaxCnt);
	int	iMinTotal = atoi((char*)cs_min_total);
	double	dRate=0.0;        
	//double	dSuccRate=0.0;        
	char	*csMerchantId=NULL;
	char	csTag[PD_TAG_LEN+1];
	char	csTmpMerchantId[PD_MERCHANT_ID_LEN+1];
	csTmpMerchantId[0] = '\0';
	int	iMerchantCnt = 0;
	int	iTotalCnt = 0;
	int	iSetCnt = 0;
	int	iHandShakeCnt = 0;
	int	iHandShake = 0;
	double	dHandShakeRate = 0.0;
	char	*csMerchantName;
	char	*csStatus;
	char	*csSubStatus;
	

	hash_t *hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn,0);

        /* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		
		/* varchar	hv_cutoff_time[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_cutoff_time;

		/* varchar	hv_buffer_period[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } hv_buffer_period;


		/* varchar	v_merchant_id[PD_MERCHANT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar	v_merchant_name[PD_DESC_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_name;

		/* varchar	v_status_desc[PD_DESC_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_status_desc;

		/* varchar	v_sub_status[PD_SUB_STATUS_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_sub_status;

		/* varchar	v_sub_status_desc[PD_DESC_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_sub_status_desc;

		/* varchar	v_from_time[PD_TMP_BUF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_from_time;

		/* varchar	v_time[PD_TMP_BUF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_time;

		/* varchar	v_alert_time[PD_TMP_BUF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_alert_time;

		char	v_status;
		char	v_ar_ind;
		int	v_cnt;

		short	ind_merchant_id = -1;
		short	ind_merchant_name = -1;
		short	ind_status_desc = -1;
		short	ind_sub_status = -1;
		short	ind_sub_status_desc = -1;
		short	ind_from_time = -1;
		short	ind_time = -1;
		short	ind_alert_time = -1;
		short	ind_status = -1;
		short	ind_ar_ind = -1;
		short	ind_cnt = -1;


	/* EXEC SQL END DECLARE SECTION; */ 


	hv_cutoff_time.len = strlen((char*)cs_cutoff_time);
        memcpy(hv_cutoff_time.arr,cs_cutoff_time,hv_cutoff_time.len);

	hv_buffer_period.len = strlen((char*)cs_buffer_period);
        memcpy(hv_buffer_period.arr,cs_buffer_period,hv_buffer_period.len);


        /* EXEC SQL DECLARE c_cursor_gettxn CURSOR FOR
		select  count(*),
			th_merchant_id,
			name,
         		th_status,
         		th_ar_ind,
			dm_status_desc,
			th_sub_status,
			ds_name,
			to_char(sysdate,'DD-MON-YYYY HH24:MI:SS'),
			to_char(sysdate - (:hv_buffer_period/1440) ,'DD-MON-YYYY HH24:MI:SS'),
			to_char(to_date(:hv_cutoff_time,'YYYYMMDDHH24MISS'),'DD-MON-YYYY HH24:MI:SS')
		from 	
			(select th_merchant_id,
				name,
			 	th_status,
				th_ar_ind,
				dm_status_desc,
				th_sub_status,
				ds_name
			 from (select th_txn_id,
				      th_merchant_id,
				      name,
				      th_txn_code,
				      th_status,
				      th_ar_ind,
				      th_sub_status,
				      ds_name
				from txn_header,def_sub_status,merch_detail
				where th_txn_code in ('DSI')
				and   ds_sub_status = th_sub_status
				and   th_merchant_id = merchant_id
				and   th_create_timestamp between to_date(:hv_cutoff_time,'YYYYMMDDHH24MISS') and sysdate-(:hv_buffer_period/1440)
				and   th_merchant_id not in ('M8000007','M8000006','M8000021','M8000016','M8000032')
				order by th_create_timestamp DESC)
			      left join
				(select dm_txn_code,
				 	dm_status,
					dm_ar_ind,
					dm_status_desc
				 from   def_txn_status_map
				 where  dm_type = 'A'
				 and    dm_txn_code in ('DSI'))
				on  ((th_ar_ind is not NULL and th_ar_ind = dm_ar_ind and th_status = dm_status) 
						or (th_ar_ind is NULL and th_status = dm_status))
				and th_txn_code = dm_txn_code
     			)
		group by th_merchant_id,
			 name,
         		 th_status,
			 th_ar_ind,
			 dm_status_desc,
			 th_sub_status,
			 ds_name
		order by th_merchant_id; */ 

                
        /* EXEC SQL OPEN c_cursor_gettxn; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlbuft((void **)0,
          "select count ( * ) , th_merchant_id , name , th_status , th_ar_in\
d , dm_status_desc , th_sub_status , ds_name , to_char ( sysdate , 'DD-MON-Y\
YYY HH24:MI:SS' ) , to_char ( sysdate - ( :b0 / 1440 ) , 'DD-MON-YYYY HH24:M\
I:SS' ) , to_char ( to_date ( :b1 , 'YYYYMMDDHH24MISS' ) , 'DD-MON-YYYY HH24\
:MI:SS' ) from ( select th_merchant_id , name , th_status , th_ar_ind , dm_s\
tatus_desc , th_sub_status , ds_name from ( select th_txn_id , th_merchant_i\
d , name , th_txn_code , th_status , th_ar_ind , th_sub_status , ds_name fro\
m txn_header , def_sub_status , merch_detail where th_txn_code in ( 'DSI' ) \
and ds_sub_status = th_sub_status and th_merchant_id = merchant_id and th_cr\
eate_timestamp between to_date ( :b1 , 'YYYYMMDDHH24MISS' ) and sysdate - ( \
:b0 / 1440 ) and th_merchant_id not in ( 'M8000007' , 'M8000006' , 'M8000021\
' , 'M8000016' , 'M8000032' ) order by th_create_timestamp DESC ) left join \
( select dm_txn_code , dm_status , dm_ar_ind , dm_status_desc from def_txn_s\
tatus_map where dm_type = 'A' and dm_txn_code i");
        sqlstm.stmt = sq0003;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )177;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_buffer_period;
        sqlstm.sqhstl[0] = (unsigned long )11;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_cutoff_time;
        sqlstm.sqhstl[1] = (unsigned long )17;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_cutoff_time;
        sqlstm.sqhstl[2] = (unsigned long )17;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_buffer_period;
        sqlstm.sqhstl[3] = (unsigned long )11;
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
        if (sqlca.sqlcode < 0) goto sql_error;
}


        do {    
                /* EXEC SQL FETCH c_cursor_gettxn
                INTO
		 	:v_cnt:ind_cnt,
         		:v_merchant_id:ind_merchant_id,
         		:v_merchant_name:ind_merchant_name,
         		:v_status:ind_status,
         		:v_ar_ind:ind_ar_ind,
         		:v_status_desc:ind_status_desc,
         		:v_sub_status:ind_sub_status,
         		:v_sub_status_desc:ind_sub_status_desc,
		 	:v_alert_time:ind_alert_time,
		 	:v_time:ind_time,
		 	:v_from_time:ind_from_time; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 11;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )208;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&v_merchant_id;
                sqlstm.sqhstl[1] = (unsigned long )18;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_merchant_name;
                sqlstm.sqhstl[2] = (unsigned long )53;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_merchant_name;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_status;
                sqlstm.sqhstl[3] = (unsigned long )1;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_status;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_ar_ind;
                sqlstm.sqhstl[4] = (unsigned long )1;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_ar_ind;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_status_desc;
                sqlstm.sqhstl[5] = (unsigned long )53;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_status_desc;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_sub_status;
                sqlstm.sqhstl[6] = (unsigned long )6;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_sub_status;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_sub_status_desc;
                sqlstm.sqhstl[7] = (unsigned long )53;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_sub_status_desc;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_alert_time;
                sqlstm.sqhstl[8] = (unsigned long )259;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_alert_time;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_time;
                sqlstm.sqhstl[9] = (unsigned long )259;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_time;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_from_time;
                sqlstm.sqhstl[10] = (unsigned long )259;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_from_time;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
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
		else{
			v_from_time.arr[v_from_time.len]='\0';
		}
		if(ind_time<0){
			v_time.len=0;
			v_time.arr[0]='\0';
		}
		else{
			v_time.arr[v_time.len]='\0';
		}

		if(ind_merchant_id>=0){
			v_merchant_id.arr[v_merchant_id.len]='\0';	
			if(strcmp((const char*)v_merchant_id.arr,csTmpMerchantId)){
				strcpy(csTmpMerchantId,(const char*)v_merchant_id.arr);
				csTmpMerchantId[v_merchant_id.len]= '\0';

				iMerchantCnt ++;
				sprintf(csTag,"merchant_id_%d",iMerchantCnt);
				PutField_CString(hTxn,csTag,csTmpMerchantId);
				sprintf(csTag,"merchant_cnt");
				PutField_Int(hTxn,csTag,iMerchantCnt);

				iSetCnt = 1;
				iTotalCnt = 0;
				iHandShakeCnt = 0;
			}
			else{
				iSetCnt++;
			}	
			sprintf(csTag,"set_cnt_%d",iMerchantCnt);
			PutField_Int(hTxn,csTag,iSetCnt);
//printf("merchant_id [%s]\n",v_merchant_id.arr);
		}
		if(ind_merchant_name>=0){
			v_merchant_name.arr[v_merchant_name.len]='\0';	
			sprintf(csTag,"merchant_name_%d",iMerchantCnt);
			PutField_CString(hTxn,csTag,(const char*)v_merchant_name.arr);
//printf("merchant_name [%s]\n",v_merchant_name.arr);
		}
		if(ind_status>=0){
			sprintf(csTag,"status_%d_%d",iMerchantCnt,iSetCnt);
			PutField_Char(hTxn,csTag,v_status);
//printf("status [%c]\n",v_status);
		}
		if(ind_ar_ind>=0){
			sprintf(csTag,"ar_ind_%d_%d",iMerchantCnt,iSetCnt);
			PutField_Char(hTxn,csTag,v_ar_ind);
//printf("ar_ind [%c]\n",v_ar_ind);
		}
		if(ind_status_desc>=0){
			v_status_desc.arr[v_status_desc.len]='\0';	
			sprintf(csTag,"status_desc_%d_%d",iMerchantCnt,iSetCnt);
			PutField_CString(hTxn,csTag,(const char*)v_status_desc.arr);
//printf("status desc [%s]\n",v_status_desc.arr);
		}
		if(ind_sub_status>=0){
			v_sub_status.arr[v_sub_status.len]='\0';	
			sprintf(csTag,"sub_status_%d_%d",iMerchantCnt,iSetCnt);
			PutField_CString(hTxn,csTag,(const char*)v_sub_status.arr);
//printf("sub status [%s]\n",v_sub_status.arr);
		}
		if(ind_sub_status_desc>=0){
			v_sub_status_desc.arr[v_sub_status_desc.len]='\0';	
			sprintf(csTag,"sub_status_desc_%d_%d",iMerchantCnt,iSetCnt);
			PutField_CString(hTxn,csTag,(const char*)v_sub_status_desc.arr);
//printf("sub status desc [%s]\n",v_sub_status_desc.arr);
		}
		if(ind_cnt>=0){
			if(!strcmp((const char*)v_sub_status.arr,PD_HAND_SHAKEN)){
				iHandShakeCnt = iHandShakeCnt + v_cnt;
				sprintf(csTag,"hand_shake_cnt_%d",iMerchantCnt);
				PutField_Int(hTxn,csTag,iHandShakeCnt);
//printf("++++++++new hand shake count[%d]++++++++\n",iHandShakeCnt);
			}
			/*else{
				iNormalCnt = iNormalCnt + v_cnt;
				sprintf(csTag,"norman_cnt_%d",iMerchantCnt);
				PutField_Int(hTxn,csTag,iNormalCnt);
			}*/
			iTotalCnt = iTotalCnt + v_cnt;
			sprintf(csTag,"total_cnt_%d",iMerchantCnt);
			PutField_Int(hTxn,csTag,iTotalCnt);

			sprintf(csTag,"cnt_%d_%d",iMerchantCnt,iSetCnt);
			PutField_Int(hTxn,csTag,v_cnt);
//printf("count [%d]\n",v_cnt);
		}

 	}
        while(PD_TRUE && iRet == SUCCESS);
        /* EXEC SQL CLOSE c_cursor_gettxn; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )267;
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

	int i=0, j=0;
	int iSCnt=0, iMCnt=0, iCount=0;
	GetField_Int(hTxn,"merchant_cnt",&iMCnt);
//printf("merchant_count [%d]\n",iMCnt);

	for(i=1; i<=iMCnt; i++){
		iTotal = 0;
		iHandShake = 0;
		iResult = SUCCESS;
		sprintf(csTag,"total_cnt_%d",i);
		GetField_Int(hTxn,csTag,&iTotal);
		sprintf(csTag,"hand_shake_cnt_%d",i);
		GetField_Int(hTxn,csTag,&iHandShake);
//printf("--------hand shake count[%d]--------\n",iHandShake);

		dRate = (double)iMaxCnt/(double)iCnt;
//printf("Rate [%lf]\n",dRate);
		if(iTotal>iMinTotal){
			dHandShakeRate = (double)iHandShake/(double)iTotal;
//printf("HandShake Rate [%lf]\n",dHandShakeRate);
			if(dRate<dHandShakeRate){
				iResult = FAILURE;
				iRet = FAILURE;
			}
			

			if(iResult == FAILURE){
				sprintf(csTag,"merchant_id_%d",i);
				GetField_CString(hTxn,csTag,&csMerchantId);
//printf("merchant_id[%s]\n",csMerchantId);
				sprintf(csTag,"merchant_name_%d",i);
				GetField_CString(hTxn,csTag,&csMerchantName);
//printf("merchant_name[%s]\n",csMerchantName);
				//printf("%s(%s)Hand-Shake Rate [%lf] Threshold Rate [%lf]\n",csMerchantName,csMerchantId,dHandShakeRate,dRate);
				printf("<tr><td>Merchant:</td><td colspan=\"3\"><b>%s</b> (%s)</td></tr>\n",csMerchantName,csMerchantId);
				printf("<tr><td>Rate:</td><td colspan=\"2\">Hand-Shake</td><td align=\"center\">%.2f%%</td></tr>\n",dHandShakeRate*100);
				printf("<tr><td></td><td colspan=\"2\">Threshold</td><td align=\"center\">%.2f%%</td></tr>\n",dRate*100);

				iSCnt=0;
				sprintf(csTag,"set_cnt_%d",i);
				GetField_Int(hTxn,csTag,&iSCnt);
//printf("set count [%d]\n",iSCnt);
				for(j=1; j<=iSCnt; j++){
					sprintf(csTag,"status_desc_%d_%d",i,j);
					GetField_CString(hTxn,csTag,&csStatus);
//printf("Status[%s]\n",csStatus);
					sprintf(csTag,"sub_status_desc_%d_%d",i,j);
					GetField_CString(hTxn,csTag,&csSubStatus);
//printf("Sub Status[%s]\n",csSubStatus);
					sprintf(csTag,"cnt_%d_%d",i,j);
					GetField_Int(hTxn,csTag,&iCount);
//printf("count [%d]\n",iCount);

					//printf("[%d],%s,%s,%d\n",j,csStatus,csSubStatus,iCount); 
					printf("<tr align=\"center\"><td>Status[%d]:</td><td>%s</td><td>%s</td><td>%d</td></tr>\n",j,csStatus,csSubStatus,iCount); 
				}
				printf("<tr><td align=\"right\" colspan=\"3\">Total Transaction Count:</td><td align=\"center\">%d</td></tr>\n",iTotal); 
				printf("<tr><td colspan=\"4\"></td></tr>\n");
			}
		}
	}
	printf("<tr><td>Duration:</td><td colspan=\"3\">%s to %s</td></tr>\n",v_from_time.arr,v_time.arr);
	iCh = update_last_check();

	FREE_ME(hTxn);
        return iRet;
sql_error:
    DEBUGLOG(("process_txn error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_gettxn; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 11;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )282;
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
    sqlstm.arrsiz = 11;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )297;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}



int update_last_check()
{
	int	iRet = SUCCESS;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;


        /* EXEC SQL END DECLARE SECTION; */ 


	hv_merchant_id.len = strlen("000");
        memcpy(hv_merchant_id.arr,"000",hv_merchant_id.len);

        /* EXEC SQL UPDATE	check_hand_shake
		 SET	ch_last_checking_time = sysdate,
			ch_update_timestamp = sysdate
		 WHERE	ch_party_id = :hv_merchant_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "update check_hand_shake SET ch_last_checking_time = \
sysdate , ch_update_timestamp = sysdate WHERE ch_party_id = :b0 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )312;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[0] = (unsigned long )17;
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
        if (sqlca.sqlcode < 0) goto update_error;
}


		/*	(select case when ind = 1 
				then id 
				else '000' 
				end as party_id
			 from 
			   (select a.party_id as id,
				   b.ind  as ind
			    from 
				(select :hv_merchant_id as party_id 
				 from dual) a 
				left join 
				(select hc_party_id, 1 as ind 
				 from check_hand_shake) b 
				on a.party_id = b.hc_party_id) 
			 where id = :hv_merchant_id);
		*/
	return iRet;

update_error:
DEBUGLOG(("update_last_check error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 11;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )331;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}


int update_cutoff_auto()
{
	int	iRet = SUCCESS;

//printf("---update_cutoff_auto---\n");
	/* EXEC SQL WHENEVER SQLERROR GOTO updatecutoff_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;


		int	v_time_diff;
		short	ind_time_diff = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_merchant_id.len = strlen("000");
        memcpy(hv_merchant_id.arr,"000",hv_merchant_id.len);

	/* EXEC SQL SELECT to_char(sysdate-1/24,'YYYYMMDDHH24MI') - to_char(ch_cutoff_checking_time,'YYYYMMDDHH24MI')
		 INTO	:v_time_diff:ind_time_diff
		 FROM	check_hand_shake
		 WHERE	ch_party_id = :hv_merchant_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select to_char ( sysdate - 1 / 24 , 'YYYYMMDDHH24MI' ) - to\
_char ( ch_cutoff_checking_time , 'YYYYMMDDHH24MI' ) INTO :b0:b1 FROM check_h\
and_shake WHERE ch_party_id = :b2 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )346;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
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


		/*	(select case when ind = 1 
				then id 
				else '000' 
				end as party_id
			 from 
			   (select a.party_id as id,
				   b.ind  as ind
			    from 
				(select :hv_merchant_id as party_id 
				 from dual) a 
				left join 
				(select ch_party_id, 1 as ind 
				 from check_hand_shake) b 
				on a.party_id = b.ch_party_id) 
			 where id = :hv_merchant_id);
		*/
	
	if(ind_time_diff>=0){
		if(v_time_diff>0){
        		/* EXEC SQL UPDATE	check_hand_shake
		 		 SET	ch_cutoff_checking_time = sysdate-1/24,
					ch_update_timestamp = sysdate
				  WHERE	ch_party_id = :hv_merchant_id; */ 

{
          struct sqlexd sqlstm;
          sqlstm.sqlvsn = 12;
          sqlstm.arrsiz = 11;
          sqlstm.sqladtp = &sqladt;
          sqlstm.sqltdsp = &sqltds;
          sqlstm.stmt = "update check_hand_shake SET ch_cutoff_checking_tim\
e = sysdate - 1 / 24 , ch_update_timestamp = sysdate WHERE ch_party_id = :b0 ";
          sqlstm.iters = (unsigned int  )1;
          sqlstm.offset = (unsigned int  )369;
          sqlstm.cud = sqlcud0;
          sqlstm.sqlest = (unsigned char  *)&sqlca;
          sqlstm.sqlety = (unsigned short)4352;
          sqlstm.occurs = (unsigned int  )0;
          sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
          sqlstm.sqhstl[0] = (unsigned long )17;
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
          if (sqlca.sqlcode < 0) goto updatecutoff_error;
}


				/*	(select case when ind = 1 
						 then id 
						 else '000' 
				 		end as party_id
				 	 from 
				 	     (select a.party_id as id,
				  		     b.ind  as ind
				  		from 
				  		     (select :hv_merchant_id as party_id 
				   		      from dual) a 
				  		      left join 
				  		     (select ch_party_id, 1 as ind 
				   		      from check_hand_shake) b 
				  		      on a.party_id = b.ch_party_id) 
				 	 where id = :hv_merchant_id);
				*/
		}
	}	
//printf("---update_cutoff_auto--- [%d]\n",iRet);
	return iRet;

updatecutoff_error:
DEBUGLOG(("update_cutoff error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 11;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )388;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}
