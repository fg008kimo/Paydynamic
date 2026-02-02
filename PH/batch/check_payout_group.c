
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
    "check_payout_group.pc"
};


static unsigned int sqlctx = 145444427;


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

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,0,0,0,56,113,0,0,1,1,0,1,0,3,102,0,0,
24,0,0,1,126,0,6,114,0,0,4,4,0,1,0,2,3,0,0,1,3,0,0,1,1,0,0,2,102,0,0,
55,0,0,0,0,0,13,133,0,0,4,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
86,0,0,0,0,0,15,167,0,0,1,1,0,1,0,1,102,0,0,
105,0,0,0,0,0,78,168,0,0,1,1,0,1,0,3,102,0,0,
124,0,0,0,0,0,15,171,0,0,1,1,0,1,0,1,102,0,0,
143,0,0,0,0,0,78,172,0,0,1,1,0,1,0,3,102,0,0,
162,0,0,2,144,0,6,229,0,0,4,4,0,1,0,2,3,0,0,1,1,0,0,1,9,0,0,1,9,0,0,
193,0,0,3,0,0,32,251,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/03/10              LokMan Chow
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

#define NUM_OF_EXPIRY_DAY	10
#define SUSPICIOUS_LIST		'B'

char    cDebug  = 'Y';

OBJPTR(DB);
int find_expired_account(recordset_t* myRec);
int delete_account(const hash_t* hTxn);

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
        int     iRet;
	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);

	hash_t  *hRec;

	iRet = find_expired_account(rRecordSet);

	if(iRet == SUCCESS){
		hRec = RecordSet_GetFirst(rRecordSet);
		while(hRec && iRet==SUCCESS){

        		iRet = delete_account(hRec);

			hRec = RecordSet_GetNext(rRecordSet);
		}

	}

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);
	return iRet;
}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


int find_expired_account(recordset_t* myRec)
{
	int     iRet = FAILURE;
	hash_t *myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO find_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		short	hv_return_value;

		int	hv_exp_day;
		char	hv_group;

		/* varchar	v_acct_num[PD_AC_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_acct_num;

		/* varchar	v_acct_name[PD_ACC_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_acct_name;

		/* varchar	v_post_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_post_date;


		short	ind_acct_num= -1;
		short	ind_acct_name= -1;
		short	ind_post_date= -1;

		short	ind_exp_day= -1;
		short	ind_group= -1;

		SQL_CURSOR      c_cursor_hs_check;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_exp_day = NUM_OF_EXPIRY_DAY;
        ind_exp_day= 0;

	hv_group = SUSPICIOUS_LIST;
        ind_group= 0;

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
                        :hv_return_value := sp_check_payout_group(:hv_exp_day:ind_exp_day,
								  :hv_group:ind_group,
								  :c_cursor_hs_check);


	END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_check_payout_group ( :h\
v_exp_day:ind_exp_day , :hv_group:ind_group , :c_cursor_hs_check ) ; END ;";
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_exp_day;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_exp_day;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_group;
        sqlstm.sqhstl[2] = (unsigned long )1;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_group;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&c_cursor_hs_check;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode < 0) goto find_error;
}



	if (hv_return_value > 0)  {

		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

		for (;;) {
			ind_acct_num= -1;
			ind_acct_name= -1;
			ind_post_date= -1;


                   /* EXEC SQL FETCH :c_cursor_hs_check
		   INTO
			:v_acct_num:ind_acct_num,
			:v_acct_name:ind_acct_name,
			:v_post_date:ind_post_date; */ 

{
                   struct sqlexd sqlstm;
                   sqlstm.sqlvsn = 12;
                   sqlstm.arrsiz = 4;
                   sqlstm.sqladtp = &sqladt;
                   sqlstm.sqltdsp = &sqltds;
                   sqlstm.iters = (unsigned int  )1;
                   sqlstm.offset = (unsigned int  )55;
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
                   sqlstm.sqhstv[1] = (unsigned char  *)&v_acct_num;
                   sqlstm.sqhstl[1] = (unsigned long )28;
                   sqlstm.sqhsts[1] = (         int  )0;
                   sqlstm.sqindv[1] = (         short *)&ind_acct_num;
                   sqlstm.sqinds[1] = (         int  )0;
                   sqlstm.sqharm[1] = (unsigned long )0;
                   sqlstm.sqadto[1] = (unsigned short )0;
                   sqlstm.sqtdso[1] = (unsigned short )0;
                   sqlstm.sqhstv[2] = (unsigned char  *)&v_acct_name;
                   sqlstm.sqhstl[2] = (unsigned long )103;
                   sqlstm.sqhsts[2] = (         int  )0;
                   sqlstm.sqindv[2] = (         short *)&ind_acct_name;
                   sqlstm.sqinds[2] = (         int  )0;
                   sqlstm.sqharm[2] = (unsigned long )0;
                   sqlstm.sqadto[2] = (unsigned short )0;
                   sqlstm.sqtdso[2] = (unsigned short )0;
                   sqlstm.sqhstv[3] = (unsigned char  *)&v_post_date;
                   sqlstm.sqhstl[3] = (unsigned long )11;
                   sqlstm.sqhsts[3] = (         int  )0;
                   sqlstm.sqindv[3] = (         short *)&ind_post_date;
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
                   if (sqlca.sqlcode == 1403) break;
                   if (sqlca.sqlcode < 0) goto find_error;
}



		   	myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

/* acct_num*/
			if (ind_acct_num>=  0) {
				v_acct_num.arr[v_acct_num.len] = '\0';
				PutField_CString(myHash,"acct_num",(const char*)v_acct_num.arr);
DEBUGLOG(("check_payout_group: acct_num = [%s]\n",v_acct_num.arr));
			}

/* acct_name*/
			if (ind_acct_name>=  0) {
				v_acct_name.arr[v_acct_name.len] = '\0';
				PutField_CString(myHash,"acct_name",(const char*)v_acct_name.arr);
DEBUGLOG(("check_payout_group: acct_name = [%s]\n",v_acct_name.arr));
			}

/*post_date*/
			if (ind_post_date >= 0) {
				v_post_date.arr[v_post_date.len] ='\0';
				PutField_CString(myHash,"post_date",(const char*)v_post_date.arr);
DEBUGLOG(("check_payout_group: post_date = [%s]\n",v_post_date.arr));
			}

			RecordSet_Add(myRec,myHash);

			iRet = SUCCESS;
		}
		/* EXEC SQL CLOSE :c_cursor_hs_check; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
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
                sqlstm.arrsiz = 4;
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
  sqlstm.arrsiz = 4;
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
                sqlstm.arrsiz = 4;
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


DEBUGLOG(("check_payout_group: iRet = [%d]\n",iRet));
	return iRet;

find_error:
DEBUGLOG(("find_expired_account error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return FAILURE;
}


int delete_account(const hash_t* hTxn)
{
	int	iRet = SUCCESS;
	char	*csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_acct_num[PD_AC_NO_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_acct_num;

		/* varchar hv_acct_name[PD_ACC_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_acct_name;

		/* varchar hv_post_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_post_date;

		char    hv_group;

		short	ind_group = -1;
		short	ind_acct_num = -1;
		short	ind_acct_name = -1;

		short	hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


	if(GetField_CString(hTxn,"acct_num",&csTmp)){
		hv_acct_num.len = strlen((char*)csTmp);
		strcpy((char*)hv_acct_num.arr,(char*)csTmp);
		ind_acct_num = 0;
DEBUGLOG(("delete_account: acct_num = [%s]\n",hv_acct_num.arr));
	}
	if(GetField_CString(hTxn,"acct_name",&csTmp)){
		hv_acct_name.len = strlen((char*)csTmp);
		strcpy((char*)hv_acct_name.arr,(char*)csTmp);
		ind_acct_name = 0;
DEBUGLOG(("delete_account: acct_name = [%s]\n",hv_acct_name.arr));
	}
	if(GetField_CString(hTxn,"post_date",&csTmp)){
		hv_post_date.len = strlen((char*)csTmp);
		strcpy((char*)hv_post_date.arr,(char*)csTmp);
DEBUGLOG(("delete_account: post_date = [%s]\n",hv_post_date.arr));
	}

	hv_group = SUSPICIOUS_LIST;
	ind_group = 0;

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_ol_payout_grp_list_delete(
								  :hv_group:ind_group,
								  :hv_acct_num:ind_acct_num,
								  :hv_acct_name:ind_acct_name);


	END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_payout_grp_list_dele\
te ( :hv_group:ind_group , :hv_acct_num:ind_acct_num , :hv_acct_name:ind_acct\
_name ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )162;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_group;
        sqlstm.sqhstl[1] = (unsigned long )1;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_group;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_acct_num;
        sqlstm.sqhstl[2] = (unsigned long )27;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_acct_num;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_acct_name;
        sqlstm.sqhstl[3] = (unsigned long )102;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_acct_name;
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
        if (sqlca.sqlcode < 0) goto update_error;
}



	if (hv_return_value > 0){
		iRet = FAILURE;
	}

DEBUGLOG(("delete_account result[%d]\n",hv_return_value));
	return iRet;

update_error:
DEBUGLOG(("delete_account error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )193;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}
