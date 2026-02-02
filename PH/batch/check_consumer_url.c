
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
           char  filnam[22];
};
static struct sqlcxp sqlfpn =
{
    21,
    "check_consumer_url.pc"
};


static unsigned int sqlctx = 145301371;


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
   unsigned char  *sqhstv[12];
   unsigned long  sqhstl[12];
            int   sqhsts[12];
            short *sqindv[12];
            int   sqinds[12];
   unsigned long  sqharm[12];
   unsigned long  *sqharc[12];
   unsigned short  sqadto[12];
   unsigned short  sqtdso[12];
} sqlstm = {12,12};

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
"re dm_type = 'A' and dm_txn_code in \
( 'DSI' ) ) on ( ( th_ar_ind is not NULL and th_ar_ind = dm_ar_ind and th_sta\
tus = dm_status ) or ( th_ar_ind is NULL and th_status = dm_status ) ) and th\
_txn_code = dm_txn_code ) WHERE td_fe_domain is not null and exists ( select \
1 from service_consumer_url where cu_service_code = cu_service_code and cu_me\
rchant_id = cu_merchant_id and cu_country = cu_country and cu_url = td_fe_dom\
ain ) group by th_merchant_id , short_name , td_fe_domain , th_status , th_ar\
_ind , dm_status_desc , th_sub_status , ds_name order by td_fe_domain        \
    ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,0,0,0,56,143,0,0,1,1,0,1,0,3,102,0,0,
24,0,0,1,115,0,6,144,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,2,102,0,0,
51,0,0,0,0,0,13,165,0,0,7,1,0,1,0,1,102,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,
3,0,0,2,9,0,0,
94,0,0,0,0,0,15,200,0,0,1,1,0,1,0,1,102,0,0,
113,0,0,0,0,0,78,201,0,0,1,1,0,1,0,3,102,0,0,
132,0,0,0,0,0,15,204,0,0,1,1,0,1,0,1,102,0,0,
151,0,0,0,0,0,78,205,0,0,1,1,0,1,0,3,102,0,0,
170,0,0,2,0,0,32,218,0,0,0,0,0,1,0,
185,0,0,3,1603,0,9,386,0,2049,5,5,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,
220,0,0,3,0,0,13,388,0,0,12,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,
1,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
283,0,0,3,0,0,15,517,0,0,0,0,0,1,0,
298,0,0,3,0,0,15,657,0,0,0,0,0,1,0,
313,0,0,4,0,0,32,658,0,0,0,0,0,1,0,
328,0,0,5,190,0,6,691,0,0,4,4,0,1,0,2,3,0,0,2,3,0,0,1,9,0,0,1,9,0,0,
359,0,0,6,0,0,32,724,0,0,0,0,0,1,0,
374,0,0,7,0,0,17,754,0,0,1,1,0,1,0,1,9,0,0,
393,0,0,7,0,0,21,755,0,0,0,0,0,1,0,
408,0,0,8,0,0,32,765,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/02/13              [MSN]
Only check the URL exists in service_consumer_url  2018/04/09	           [SWK]
PRD306 Revise Spelling Mistake                     2021/02/24              [ZBL]
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

char    cs_marchant_id[PD_MERCHANT_ID_LEN + 1];
char    cs_rate[PD_DATE_LEN + 1];
char    cs_count[PD_DATE_LEN + 1];
char    cs_max_hand_shake[PD_DATE_LEN + 1];
char    cs_max_init[PD_DATE_LEN + 1];
char    cs_check_period[PD_DATE_LEN + 1];
char	cs_txn_period[PD_DATE_LEN + 1];
char	cs_period_from[PD_DATE_LEN + 1];
char    cs_merchant_id[PD_PSP_ID_LEN + 1];
char    cs_min_total[PD_DATE_LEN + 1];
char	cs_cutoff_time[PD_DATETIME_LEN+1];
char	cs_buffer_period[PD_DATE_LEN + 1];
char    c_rc_ind;
static char cDebug = 'Y';

OBJPTR(DB);
int parse_arg(int argc,char **argv);
int process_txn(const unsigned char* csMerchantId);
int find_checking_parameters(const unsigned char* csMerchantId);
int isBackupDomain(const char* csDomain);
int DisableDomain(const char* csDomain);

int batch_init(int argc, char* argv[])
{

    if (argc < 2) {
        printf("usage: -m merchant_id\n");
	return FAILURE;
    }

    else
	return SUCCESS;
}




int batch_proc(int argc, char* argv[])
{
        int     iRet;

	iRet = parse_arg(argc,argv);
               
        if (iRet != SUCCESS) {
        	printf("usage: -m merchant_id\n");
                return SUCCESS;
        }

//	iRet = update_cutoff_auto((const unsigned char*)cs_merchant_id);
/*
	hash_t * hTxn;
	hTxn  = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn,0);
*/
	if(iRet == SUCCESS)

		iRet = find_checking_parameters((const unsigned char*)cs_merchant_id);

	if(iRet == SUCCESS){

        	iRet = process_txn((const unsigned char*)cs_merchant_id);

	}

//	FREE_ME(hTxn);
	return iRet;


}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


int find_checking_parameters(const unsigned char* csMerchantId)
{
	int     iRet = FAILURE;

//printf("---find_checking_parameters---\n");
	/* EXEC SQL WHENEVER SQLERROR GOTO find_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		short	hv_return_value;

		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_merchant_id;

		int	v_count;
		int	v_max_hand_shake;
		int	v_max_init;
		int	v_min_total;
		int	v_buffer_period;
		/* varchar	v_cutoff_time[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_cutoff_time;


		short	ind_merchant_id = -1;
		short	ind_count = -1;
		short	ind_max_hand_shake = -1;
		short	ind_max_init = -1;
		short	ind_min_total = -1;
		short	ind_buffer_period = -1;
		short	ind_cutoff_time = -1;

		SQL_CURSOR      c_cursor_hs_check;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_merchant_id.len = strlen((char*)csMerchantId);
        memcpy(hv_merchant_id.arr,cs_merchant_id,hv_merchant_id.len);
        ind_merchant_id = 0;

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
                        :hv_return_value := sp_check_hand_shake_init(:hv_merchant_id:ind_merchant_id,
								     :c_cursor_hs_check);


	END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 3;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_check_hand_shake_init (\
 :hv_merchant_id:ind_merchant_id , :c_cursor_hs_check ) ; END ;";
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[1] = (unsigned long )18;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&c_cursor_hs_check;
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
			ind_max_hand_shake = -1;
			ind_min_total = -1;
			ind_buffer_period = -1;
			ind_cutoff_time = -1;
			ind_max_init= -1;


                   /* EXEC SQL FETCH :c_cursor_hs_check
		   INTO
			:v_count:ind_count,
			:v_max_hand_shake:ind_max_hand_shake,
			:v_max_init:ind_max_init,
			:v_min_total:ind_min_total,
			:v_buffer_period:ind_buffer_period,
			:v_cutoff_time:ind_cutoff_time; */ 

{
                   struct sqlexd sqlstm;
                   sqlstm.sqlvsn = 12;
                   sqlstm.arrsiz = 7;
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
                   sqlstm.sqhstv[3] = (unsigned char  *)&v_max_init;
                   sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
                   sqlstm.sqhsts[3] = (         int  )0;
                   sqlstm.sqindv[3] = (         short *)&ind_max_init;
                   sqlstm.sqinds[3] = (         int  )0;
                   sqlstm.sqharm[3] = (unsigned long )0;
                   sqlstm.sqadto[3] = (unsigned short )0;
                   sqlstm.sqtdso[3] = (unsigned short )0;
                   sqlstm.sqhstv[4] = (unsigned char  *)&v_min_total;
                   sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
                   sqlstm.sqhsts[4] = (         int  )0;
                   sqlstm.sqindv[4] = (         short *)&ind_min_total;
                   sqlstm.sqinds[4] = (         int  )0;
                   sqlstm.sqharm[4] = (unsigned long )0;
                   sqlstm.sqadto[4] = (unsigned short )0;
                   sqlstm.sqtdso[4] = (unsigned short )0;
                   sqlstm.sqhstv[5] = (unsigned char  *)&v_buffer_period;
                   sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
                   sqlstm.sqhsts[5] = (         int  )0;
                   sqlstm.sqindv[5] = (         short *)&ind_buffer_period;
                   sqlstm.sqinds[5] = (         int  )0;
                   sqlstm.sqharm[5] = (unsigned long )0;
                   sqlstm.sqadto[5] = (unsigned short )0;
                   sqlstm.sqtdso[5] = (unsigned short )0;
                   sqlstm.sqhstv[6] = (unsigned char  *)&v_cutoff_time;
                   sqlstm.sqhstl[6] = (unsigned long )17;
                   sqlstm.sqhsts[6] = (         int  )0;
                   sqlstm.sqindv[6] = (         short *)&ind_cutoff_time;
                   sqlstm.sqinds[6] = (         int  )0;
                   sqlstm.sqharm[6] = (unsigned long )0;
                   sqlstm.sqadto[6] = (unsigned short )0;
                   sqlstm.sqtdso[6] = (unsigned short )0;
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

		   if(ind_max_init<0)
			   v_max_init= 0;
		   sprintf(cs_max_init,"%d",v_max_init);

		   if(ind_min_total<0)
			   v_min_total= 0;
		   sprintf(cs_min_total,"%d",v_min_total);

		   if(ind_buffer_period<0)
			   v_buffer_period= 0;
		   sprintf(cs_buffer_period,"%d",v_buffer_period);

		   if(ind_cutoff_time>=0){
			   sprintf(cs_cutoff_time,"%.*s",v_cutoff_time.len,v_cutoff_time.arr);
		   }

//printf("[%d][%d][%d][%d][%d][%s]\n",v_count,v_max_hand_shake,v_max_init,v_min_total,v_buffer_period,cs_cutoff_time);
		}
		/* EXEC SQL CLOSE :c_cursor_hs_check; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )94;
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
                sqlstm.arrsiz = 7;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )113;
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
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )132;
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
                sqlstm.arrsiz = 7;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )151;
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

//printf("---find_checking_parameters end---[%d]\n",iRet);
	return iRet;

find_error:
DEBUGLOG(("find_checking_parameters error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 7;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )170;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}


int process_txn(const unsigned char* csMerchantId)
{               
 
        int     iRet = SUCCESS;
        int     iResult = SUCCESS;
        int     iCheckHandShake = SUCCESS;
        int     iCheckInit = SUCCESS;
        int     iChk = 0;
	//int	iPending=0;
	//int	iAccept=0;
	//int	iReject=0;
	int	iTotal=0;
	//int	iOthers=0;
	int	iCnt = atoi((char*)cs_count);
	int	iMaxCnt = atoi((char*)cs_max_hand_shake);
	int	iMaxInitCnt = atoi((char*)cs_max_init);
	int	iMinTotal = atoi((char*)cs_min_total);
	double	dRate=0.0;        
	double	dIRate=0.0;        
	//double	dSuccRate=0.0;        
	char	csTag[PD_TAG_LEN+1];
	char	csTmpDomain[PD_FUNCTION_URL_LEN+1];
	csTmpDomain[0] = '\0';
	int	iDomainCnt = 0;
	int	iTotalCnt = 0;
	int	iSetCnt = 0;
	int	iHandShakeCnt = 0;
	int	iHandShake = 0;
	double	dHandShakeRate = 0.0;
	int	iInitCnt= 0;
	int	iInit= 0;
	double	dInitRate= 0.0;
	char	*csStatus;
	char	*csSubStatus;
	char	*csDomain;
	char	*csMerchId;
	char	*csShortName;
	int	iDis = PD_FALSE;

	hash_t *hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn,0);

//printf("---process_txn---\n");
        /* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		
		/* varchar	hv_cutoff_time[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_cutoff_time;

		/* varchar	hv_buffer_period[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } hv_buffer_period;

		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_merchant_id;


		/* varchar	v_merch_id[PD_MERCHANT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merch_id;

		/* varchar	v_short_name[PD_MERCH_SHORT_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_short_name;

		/* varchar	v_domain[PD_FUNCTION_URL_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_domain;

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

		short	ind_merch_id = -1;
		short	ind_short_name = -1;
		short	ind_domain= -1;
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
//printf("hv_cutoff_time = [%s]\n",hv_cutoff_time.arr);

	hv_buffer_period.len = strlen((char*)cs_buffer_period);
        memcpy(hv_buffer_period.arr,cs_buffer_period,hv_buffer_period.len);
//printf("hv_buffer_period= [%s]\n",hv_buffer_period.arr);

	hv_merchant_id.len = strlen((char*)csMerchantId);
        memcpy(hv_merchant_id.arr,cs_merchant_id,hv_merchant_id.len);
//printf("hv_merchant_id= [%s]\n",hv_merchant_id.arr);

        /* EXEC SQL DECLARE c_cursor_gettxn CURSOR FOR
		select  count(*),
			th_merchant_id,
			short_name,
			td_fe_domain,
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
				short_name,
				td_fe_domain,
			 	th_status,
				th_ar_ind,
				dm_status_desc,
				th_sub_status,
				ds_name
			 from (select th_txn_id,
				      th_merchant_id,
				      short_name,
				      th_txn_code,
				      th_status,
				      th_ar_ind,
				      th_sub_status,
				      ds_name,
				      td_fe_domain
				from txn_header,def_sub_status,merch_detail, txn_detail
				where th_txn_code in ('DSI')
				and   ds_sub_status = th_sub_status
				and   th_merchant_id = merchant_id
				and   th_txn_id = td_txn_id
				and   th_create_timestamp between to_date(:hv_cutoff_time,'YYYYMMDDHH24MISS') and sysdate-(:hv_buffer_period/1440)
				and   th_merchant_id = :hv_merchant_id 
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
		WHERE td_fe_domain is not null
                and exists (select 1
                            from service_consumer_url
                            where cu_service_code = cu_service_code
                            and cu_merchant_id = cu_merchant_id
                            and cu_country = cu_country 
                            and cu_url = td_fe_domain
                            )
		group by th_merchant_id,
			 short_name,
			 td_fe_domain,
         		 th_status,
			 th_ar_ind,
			 dm_status_desc,
			 th_sub_status,
			 ds_name
		order by td_fe_domain; */ 

                
        /* EXEC SQL OPEN c_cursor_gettxn; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlbuft((void **)0,
          "select count ( * ) , th_merchant_id , short_name , td_fe_domain ,\
 th_status , th_ar_ind , dm_status_desc , th_sub_status , ds_name , to_char \
( sysdate , 'DD-MON-YYYY HH24:MI:SS' ) , to_char ( sysdate - ( :b0 / 1440 ) \
, 'DD-MON-YYYY HH24:MI:SS' ) , to_char ( to_date ( :b1 , 'YYYYMMDDHH24MISS' \
) , 'DD-MON-YYYY HH24:MI:SS' ) from ( select th_merchant_id , short_name , t\
d_fe_domain , th_status , th_ar_ind , dm_status_desc , th_sub_status , ds_na\
me from ( select th_txn_id , th_merchant_id , short_name , th_txn_code , th_\
status , th_ar_ind , th_sub_status , ds_name , td_fe_domain from txn_header \
, def_sub_status , merch_detail , txn_detail where th_txn_code in ( 'DSI' ) \
and ds_sub_status = th_sub_status and th_merchant_id = merchant_id and th_tx\
n_id = td_txn_id and th_create_timestamp between to_date ( :b1 , 'YYYYMMDDHH\
24MISS' ) and sysdate - ( :b0 / 1440 ) and th_merchant_id = :b4 order by th_\
create_timestamp DESC ) left join ( select dm_txn_code , dm_status , dm_ar_i\
nd , dm_status_desc from def_txn_status_map whe");
        sqlstm.stmt = sq0003;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )185;
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
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[4] = (unsigned long )18;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
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


        do {    
                /* EXEC SQL FETCH c_cursor_gettxn
                INTO
		 	:v_cnt:ind_cnt,
			:v_merch_id:ind_merch_id,
			:v_short_name:ind_short_name,
         		:v_domain:ind_domain,
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
                sqlstm.arrsiz = 12;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&v_merch_id;
                sqlstm.sqhstl[1] = (unsigned long )18;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_merch_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_short_name;
                sqlstm.sqhstl[2] = (unsigned long )23;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_short_name;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_domain;
                sqlstm.sqhstl[3] = (unsigned long )53;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_domain;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_status;
                sqlstm.sqhstl[4] = (unsigned long )1;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_status;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_ar_ind;
                sqlstm.sqhstl[5] = (unsigned long )1;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_ar_ind;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_status_desc;
                sqlstm.sqhstl[6] = (unsigned long )53;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_status_desc;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_sub_status;
                sqlstm.sqhstl[7] = (unsigned long )6;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_sub_status;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_sub_status_desc;
                sqlstm.sqhstl[8] = (unsigned long )53;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_sub_status_desc;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_alert_time;
                sqlstm.sqhstl[9] = (unsigned long )259;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_alert_time;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_time;
                sqlstm.sqhstl[10] = (unsigned long )259;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_time;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_from_time;
                sqlstm.sqhstl[11] = (unsigned long )259;
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_from_time;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
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

		if(ind_domain>=0){
			v_domain.arr[v_domain.len]='\0';	
			if(strcmp((const char*)v_domain.arr,csTmpDomain)){
				strcpy(csTmpDomain,(const char*)v_domain.arr);
				csTmpDomain[v_domain.len]= '\0';

				iDomainCnt ++;
				sprintf(csTag,"domain_%d",iDomainCnt);
				PutField_CString(hTxn,csTag,csTmpDomain);
				sprintf(csTag,"domain_cnt");
				PutField_Int(hTxn,csTag,iDomainCnt);

				iSetCnt = 1;
				iTotalCnt = 0;
				iHandShakeCnt = 0;
				iInitCnt = 0;

			}
			else{
				iSetCnt++;
			}	
			sprintf(csTag,"set_cnt_%d",iDomainCnt);
			PutField_Int(hTxn,csTag,iSetCnt);
//printf("domain [%s]\n",v_domain.arr);
		}

		if(ind_merch_id>=0) {
			v_merch_id.arr[v_merch_id.len]='\0';	
			sprintf(csTag,"merch_id_%d",iDomainCnt);
			PutField_CString(hTxn,csTag,(const char*)v_merch_id.arr);
//printf("merch_id [%s][%d]\n",v_merch_id.arr,iDomainCnt);
		}
			
		if(ind_short_name>=0) {
			v_short_name.arr[v_short_name.len]='\0';	
			sprintf(csTag,"short_name_%d",iDomainCnt);
			PutField_CString(hTxn,csTag,(const char*)v_short_name.arr);
//printf("short_name [%s][%d]\n",v_short_name.arr,iDomainCnt);
		}

		if(ind_status>=0){
			sprintf(csTag,"status_%d_%d",iDomainCnt,iSetCnt);
			PutField_Char(hTxn,csTag,v_status);
//printf("status [%c]\n",v_status);
		}
		if(ind_ar_ind>=0){
			sprintf(csTag,"ar_ind_%d_%d",iDomainCnt,iSetCnt);
			PutField_Char(hTxn,csTag,v_ar_ind);
//printf("ar_ind [%c]\n",v_ar_ind);
		}
		if(ind_status_desc>=0){
			v_status_desc.arr[v_status_desc.len]='\0';	
			sprintf(csTag,"status_desc_%d_%d",iDomainCnt,iSetCnt);
			PutField_CString(hTxn,csTag,(const char*)v_status_desc.arr);
//printf("status desc [%s]\n",v_status_desc.arr);
		}
		if(ind_sub_status>=0){
			v_sub_status.arr[v_sub_status.len]='\0';	
			sprintf(csTag,"sub_status_%d_%d",iDomainCnt,iSetCnt);
			PutField_CString(hTxn,csTag,(const char*)v_sub_status.arr);
//printf("sub status [%s]\n",v_sub_status.arr);
		}
		if(ind_sub_status_desc>=0){
			v_sub_status_desc.arr[v_sub_status_desc.len]='\0';	
			sprintf(csTag,"sub_status_desc_%d_%d",iDomainCnt,iSetCnt);
			PutField_CString(hTxn,csTag,(const char*)v_sub_status_desc.arr);
//printf("sub status desc [%s]\n",v_sub_status_desc.arr);
		}
		if(ind_cnt>=0){
			if((!strcmp((const char*)v_sub_status.arr,PD_HAND_SHAKEN)) && (v_status!=PD_COMPLETE)){
				iHandShakeCnt = iHandShakeCnt + v_cnt;
				sprintf(csTag,"hand_shake_cnt_%d",iDomainCnt);
				PutField_Int(hTxn,csTag,iHandShakeCnt);
//printf("++++++++new hand shake count[%d]++++++++\n",iHandShakeCnt);
			}
			else if((!strcmp((const char*)v_sub_status.arr,PD_INITIATED)) && (v_status!=PD_COMPLETE)){
				iInitCnt = iInitCnt + v_cnt;
				sprintf(csTag,"init_cnt_%d",iDomainCnt);
				PutField_Int(hTxn,csTag,iInitCnt);
//printf("++++++++new init count[%d]++++++++\n",iInitCnt);
			}
			iTotalCnt = iTotalCnt + v_cnt;
			sprintf(csTag,"total_cnt_%d",iDomainCnt);
			PutField_Int(hTxn,csTag,iTotalCnt);

			sprintf(csTag,"cnt_%d_%d",iDomainCnt,iSetCnt);
			PutField_Int(hTxn,csTag,v_cnt);
//printf("count [%d]\n",v_cnt);
		}

 	}
        while(PD_TRUE && iRet == SUCCESS);
        /* EXEC SQL CLOSE c_cursor_gettxn; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )283;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto sql_error;
}



	if(iChk==0){
//printf("---process_txn return with 0 count!!!!!---\n");
		return FAILURE;
	}

	int i=0, j=0;
	int iSCnt=0, iMCnt=0, iCount=0;
	GetField_Int(hTxn,"domain_cnt",&iMCnt);
//printf("domain_count [%d]\n",iMCnt);

	int iOverallRet = FAILURE;

	for(i=1; i<=iMCnt; i++){
		iTotal = 0;
		iHandShake = 0;
		iInit = 0;
		iResult = SUCCESS;
		iCheckHandShake = SUCCESS;
		iCheckInit= SUCCESS;
		sprintf(csTag,"total_cnt_%d",i);
		GetField_Int(hTxn,csTag,&iTotal);
		sprintf(csTag,"hand_shake_cnt_%d",i);
		GetField_Int(hTxn,csTag,&iHandShake);
//printf("--------hand shake count[%d]--------\n",iHandShake);
		sprintf(csTag,"init_cnt_%d",i);
		GetField_Int(hTxn,csTag,&iInit);

		dRate = (double)iMaxCnt/(double)iCnt;
		dIRate = (double)iMaxInitCnt/(double)iCnt;
//printf("Rate [%lf]\n",dRate);
		if(iTotal>iMinTotal){
			dHandShakeRate = (double)iHandShake/(double)iTotal;
//printf("HandShake Rate [%lf]\n",dHandShakeRate);
			if(dRate<dHandShakeRate){
				iResult = FAILURE;
				iCheckHandShake = FAILURE;
			}
			dInitRate = (double)iInit/(double)iTotal;

			if(dIRate<dInitRate){
				iResult = FAILURE;
				iCheckInit = FAILURE;
			}

			if(iResult == FAILURE){
				iOverallRet = SUCCESS;
				sprintf(csTag,"merch_id_%d",i);
				GetField_CString(hTxn,csTag,&csMerchId);
				sprintf(csTag,"short_name_%d",i);
				GetField_CString(hTxn,csTag,&csShortName);
				sprintf(csTag,"domain_%d",i);
				printf("<tr><td>Merchant</td><td colspan=\"3\">%s (%s)</td></tr>\n",csShortName,csMerchId);
				GetField_CString(hTxn,csTag,&csDomain);
//printf("domain [%s]\n",csDomain);
				//printf("%s: Hand-Shake Rate [%lf] Threshold Rate [%lf]\n",csDomain,dHandShakeRate,dRate);
				printf("<tr><td>Domain:</td><td colspan=\"3\">%s</td></tr>\n",csDomain);
				if(iCheckHandShake == FAILURE){
					printf("<tr><td>Rate:</td><td colspan=\"2\"><font color=\"red\">Hand-Shake</td><td align=\"center\"><font color=\"red\">%.2f%%</td></tr>\n",dHandShakeRate*100);
					printf("<tr><td></td><td colspan=\"2\">Hand-Shake Threshold</td><td align=\"center\">%.2f%%</td></tr>\n",dRate*100);
				}
				if(iCheckInit == FAILURE){
					printf("<tr><td>Rate:</td><td colspan=\"2\"><font color=\"red\">Initiated</td><td align=\"center\"><font color=\"red\">%.2f%%</td></tr>\n",dInitRate*100);
					printf("<tr><td></td><td colspan=\"2\">Initiated Threshold</td><td align=\"center\">%.2f%%</td></tr>\n",dIRate*100);
				}
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
				printf("<tr><td>Duration:</td><td colspan=\"3\">%s to %s</td></tr>\n",v_from_time.arr,v_time.arr);


				iDis = isBackupDomain(csDomain);
				if(iDis==PD_FALSE){
					//disable domain
					if(DisableDomain(csDomain)==PD_OK){
						//alert domain disabled
						printf("<tr><td><b>Note:</b></td><td colspan=\"3\">[%s] was disabled now</td></tr>\n",csDomain);
					}
					else{
						//alert disable domain error
						printf("<tr><td><b>Warning:</b></td><td colspan=\"3\">Failed to disble [%s]!!!</td></tr>\n",csDomain);
					}
				}
				else if(iDis==PD_TRUE){
					//alert the domain is the backup one
					printf("<tr><td><b>Warning:</b></td><td colspan=\"3\">[%s] is the last one!!!</td></tr>\n",csDomain);
					FILE    *fout;
					char csPath[PD_TMP_BUF_LEN];
					sprintf(csPath,"%s/call_it.txt",getenv("LOGPATH"));
					fout = fopen(csPath,"w");
					if(fout){
						fprintf(fout,"<font color=\"red\">*Please Call IT Support</font>");
					}
					fclose(fout);
				}
				else if(iDis==PD_SKIP_OK){
					//alert already disabled
					printf("<tr><td><b>Note:</b></td><td colspan=\"3\">[%s] had been disabled already</td></tr>\n",csDomain);
				}
				else{
					//alert find domain error
					printf("<tr><td><b>Warning:</b></td><td colspan=\"3\">Failed to find [%s]!!!</td></tr>\n",csDomain);
				}
				printf("<tr><td colspan=\"4\"></td></tr>\n");

			}
			/*else{
				iRet = FAILURE;
			}*/
		}
		/*else{
			iRet = FAILURE;
		}*/
	}

	iRet = iOverallRet;
//printf("---process_txn End---\n");
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
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )298;
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
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )313;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int isBackupDomain(const char* csDomain)
{
	int iRet = PD_ERR;

        /* EXEC SQL WHENEVER SQLERROR GOTO is_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar hv_domain[PD_FUNCTION_URL_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_domain;

		/* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;


                int	v_backup;
                int	v_disabled;

                short   ind_backup = -1;
                short   ind_disabled = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_merchant_id.len = strlen(cs_merchant_id);
        memcpy(hv_merchant_id.arr,cs_merchant_id,hv_merchant_id.len);
DEBUGLOG(("isBackupDomain merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

        hv_domain.len = strlen(csDomain);
        memcpy(hv_domain.arr,csDomain,hv_domain.len);
DEBUGLOG(("isBackupDomain domain = [%.*s]\n",hv_domain.len,hv_domain.arr));

        /* EXEC SQL EXECUTE
        BEGIN
                select  cu_for_backup,
			cu_disabled
                into    :v_backup:ind_backup,
			:v_disabled:ind_disabled
                from    service_consumer_url
                where   cu_url=:hv_domain
                and     cu_merchant_id = :hv_merchant_id;

        END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin select cu_for_backup , cu_disabled into :v_bac\
kup:ind_backup , :v_disabled:ind_disabled from service_consumer_url where cu_\
url = :hv_domain and cu_merchant_id = :hv_merchant_id ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )328;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_backup;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_backup;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&v_disabled;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_disabled;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_domain;
        sqlstm.sqhstl[2] = (unsigned long )52;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[3] = (unsigned long )17;
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



        if(ind_disabled>=0){
		if(!v_disabled){
			if(ind_backup>=0){
DEBUGLOG(("isBackupDomain = [%d]\n",v_backup));
				iRet = v_backup;
        		}
		}
		else{
DEBUGLOG(("isBackupDomain domain already disabled\n"));
			iRet = PD_SKIP_OK;
		}
	}

        return iRet;

is_error:
    DEBUGLOG(("isBackupDomain error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    ERRLOG("check_consumer_url::isBackupDomain error code %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )359;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int DisableDomain(const char* csDomain)
{
	int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO disable_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


	strcpy((char*)hv_dynstmt.arr,"update service_consumer_url set cu_disabled = 1, cu_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	strcat((char *)hv_dynstmt.arr, " WHERE cu_url = '");
        strcat((char *)hv_dynstmt.arr, csDomain);
        strcat((char *)hv_dynstmt.arr, "'");
	strcat((char *)hv_dynstmt.arr, " AND cu_merchant_id = '");
        strcat((char *)hv_dynstmt.arr, cs_merchant_id);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("DisableDomain SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )374;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
        sqlstm.sqhstl[0] = (unsigned long )1026;
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
        if (sqlca.sqlcode < 0) goto disable_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )393;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto disable_error;
}


	
	return iRet;


disable_error:
    DEBUGLOG(("DisableDomain error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    ERRLOG("check_consumer_url::DisableDomain error code %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )408;
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
	strcpy(cs_merchant_id,"");

	while ((c = getopt(argc,argv,"m:")) != EOF) {
		switch (c) {
			case 'm':
				strcpy(cs_merchant_id, optarg);
				break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(cs_merchant_id,""))
		return FAILURE;

	return SUCCESS;
}
