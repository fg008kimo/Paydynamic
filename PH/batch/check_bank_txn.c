
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
    "check_bank_txn.pc"
};


static unsigned int sqlctx = 9072971;


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
   unsigned char  *sqhstv[9];
   unsigned long  sqhstl[9];
            int   sqhsts[9];
            short *sqindv[9];
            int   sqinds[9];
   unsigned long  sqharm[9];
   unsigned long  *sqharc[9];
   unsigned short  sqadto[9];
   unsigned short  sqtdso[9];
} sqlstm = {12,9};

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
"SELECT bc_check_count , bc_min_success_count , bc_min_total , bc_start_buff\
er_period , to_char ( case when sysdate - 1 / 2 - bc_cutoff_checking_time >= \
0 then sysdate - 1 / 2 else bc_cutoff_checking_time end , 'YYYYMMDDHH24MISS' \
) bc_new_cutoff_checking_time , to_char ( case when sysdate - 1 / 2 - bc_cuto\
ff_checking_time >= 0 then sysdate - 1 / 2 else bc_cutoff_checking_time end ,\
 'DD-MON-YYYY HH24:MI:SS' ) from_time , to_char ( sysdate - bc_start_buffer_p\
eriod / 1440 , 'DD-MON-YYYY HH24:MI:SS' ) to_time , psp_name , bank_name FROM\
 bank_txn_check , psp_detail , bank_desc WHERE bc_disabled = 0 AND bc_party_i\
d = case when ( select count ( * ) from bank_txn_check where bc_disabled = 0 \
and bc_party_id = :b0 and bc_bank_code = :b1 ) > 0 then :b0 else '000' end AN\
D bc_bank_code = :b1 AND psp_id = :b0 AND internal_bank_code = :b1           \
 ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,846,0,9,171,0,2049,6,6,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,
44,0,0,1,0,0,13,173,0,0,9,0,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,
95,0,0,1,0,0,15,221,0,0,0,0,0,1,0,
110,0,0,1,0,0,15,235,0,0,0,0,0,1,0,
125,0,0,2,0,0,32,236,0,0,0,0,0,1,0,
140,0,0,0,0,0,56,294,0,0,1,1,0,1,0,3,102,0,0,
159,0,0,3,169,0,6,295,0,0,6,6,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,3,
102,0,0,
198,0,0,0,0,0,13,309,0,0,4,1,0,1,0,1,102,0,0,2,3,0,0,2,1,0,0,2,1,0,0,
229,0,0,0,0,0,15,360,0,0,1,1,0,1,0,1,102,0,0,
248,0,0,0,0,0,78,361,0,0,1,1,0,1,0,3,102,0,0,
267,0,0,0,0,0,15,413,0,0,1,1,0,1,0,1,102,0,0,
286,0,0,0,0,0,78,414,0,0,1,1,0,1,0,3,102,0,0,
305,0,0,4,0,0,32,415,0,0,0,0,0,1,0,
320,0,0,5,222,0,5,443,0,0,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
347,0,0,6,0,0,32,459,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/06/10              Stan Poon
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlca.h>
#include <unistd.h>
#include "batchcommon.h"
#include "common.h"
#include "utilitys.h"
#include "myrecordset.h"
#include "ObjPtr.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cs_psp_id[PD_PSP_ID_LEN + 1];
char    cs_psp_name[PD_PSP_NAME_LEN + 1];
char    cs_bank_code[PD_BANK_CODE_LEN + 1];
char    cs_bank_name[PD_AC_BANK_NAME_LEN + 1];
char    cs_count[PD_DATE_LEN + 1];
char    cs_min_succ[PD_DATE_LEN + 1];
char    cs_min_total[PD_DATE_LEN + 1];
char	cs_cutoff_time[PD_DATETIME_LEN+1];
char	cs_buffer_period[PD_DATE_LEN + 1];
char	cs_from_time[PD_TIMESTAMP_LEN + 1];
char	cs_to_time[PD_TIMESTAMP_LEN + 1];
char    cDebug;

OBJPTR(DB);
int parse_arg(int argc,char **argv);
int process_txn(const char* csPspId, const char* csPspName, const char* csBankCode, const char* csBankName, const char* csCount, const char* csMinCnt);
int find_checking_parameters(const char* csPspId, const char* csBankCode);
int update_last_checking(const char* csPspId, const char* csBankCode);

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}

int batch_proc(int argc, char* argv[])
{
        int     iRet;

	iRet = parse_arg(argc,argv);

	if(iRet != SUCCESS)
printf("usage: -p psp_id -b bank_code\n");

	if(iRet == SUCCESS)
		iRet = find_checking_parameters(cs_psp_id,cs_bank_code);

	if(iRet == SUCCESS)
        	iRet = process_txn(cs_psp_id,cs_psp_name,cs_bank_code,cs_bank_name,cs_count,cs_min_succ);

	return iRet;
}

int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

int parse_arg(int argc,char **argv)
{
	if (argc < 5) {
		return PD_ERR;
	}

        char    c;
	strcpy(cs_bank_code,"");
	strcpy(cs_psp_id,"");

        while ((c = getopt(argc,argv,"p:b:")) != EOF) {
                switch (c) {
                        case 'p':
                                strcpy(cs_psp_id, optarg);
                                break;
                        case 'b':
                                strcpy(cs_bank_code, optarg);
                                break;
                        default:
                                return PD_ERR;
                }
        }

        if (!strcmp(cs_bank_code,"") || !strcmp(cs_psp_id,""))
                return PD_ERR;

        return SUCCESS;
}

int find_checking_parameters(const char* csPspId, const char* csBankCode)
{
DEBUGLOG(("find() start psp_id=[%s], bank_code=[%s]\n",csPspId,csBankCode));
	int     iRet = SUCCESS;

	/* EXEC SQL WHENEVER SQLERROR GOTO find_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;

		int	v_count;
		int	v_min_succ;
		int	v_min_total;
		int	v_buffer_period;
		/* varchar	v_cutoff_time[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_cutoff_time;

		/* varchar	v_from_time[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_from_time;

		/* varchar	v_to_time[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_to_time;

		/* varchar v_psp_name[PD_PSP_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_name;

		/* varchar v_bank_name[PD_AC_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;


		short	ind_count = -1;
		short	ind_min_succ = -1;
		short	ind_min_total = -1;
		short	ind_buffer_period = -1;
		short	ind_cutoff_time = -1;
		short	ind_from_time = -1;
		short	ind_to_time = -1;
		short	ind_psp_name = -1;
		short	ind_bank_name = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_psp_id.len = strlen((char*)csPspId);
        memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);

	hv_bank_code.len = strlen((char*)csBankCode);
        memcpy(hv_bank_code.arr,csBankCode,hv_bank_code.len);

	/* EXEC SQL DECLARE c_cursor_get_check CURSOR FOR
        	SELECT	bc_check_count,
			bc_min_success_count,
			bc_min_total,
			bc_start_buffer_period,
			to_char(case when sysdate-1/2 - bc_cutoff_checking_time >= 0 then
				sysdate-1/2
			else
				bc_cutoff_checking_time
			end,'YYYYMMDDHH24MISS') bc_new_cutoff_checking_time,
			to_char(case when sysdate-1/2 - bc_cutoff_checking_time >= 0 then
				sysdate-1/2
			else
				bc_cutoff_checking_time
			end,'DD-MON-YYYY HH24:MI:SS') from_time,
			to_char(sysdate-bc_start_buffer_period/1440,'DD-MON-YYYY HH24:MI:SS') to_time,
			psp_name,
			bank_name
		FROM	bank_txn_check,
			psp_detail,
			bank_desc
		WHERE	bc_disabled = 0
			AND bc_party_id = case when 
				(select	count(*) from bank_txn_check
				 where	bc_disabled = 0
				 and	bc_party_id = :hv_psp_id and bc_bank_code = :hv_bank_code) > 0
				then :hv_psp_id else '000'
			end
			AND bc_bank_code = :hv_bank_code
			AND psp_id = :hv_psp_id
			AND internal_bank_code = :hv_bank_code; */ 

	/* EXEC SQL OPEN c_cursor_get_check; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[0] = (unsigned long )12;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_code;
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
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_bank_code;
 sqlstm.sqhstl[3] = (unsigned long )12;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[4] = (unsigned long )12;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_bank_code;
 sqlstm.sqhstl[5] = (unsigned long )12;
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
 if (sqlca.sqlcode < 0) goto find_error;
}



	/* EXEC SQL FETCH c_cursor_get_check
	INTO
		:v_count:ind_count,
		:v_min_succ:ind_min_succ,
		:v_min_total:ind_min_total,
		:v_buffer_period:ind_buffer_period,
		:v_cutoff_time:ind_cutoff_time,
		:v_from_time:ind_from_time,
		:v_to_time:ind_to_time,
		:v_psp_name:ind_psp_name,
		:v_bank_name:ind_bank_name; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )44;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqfoff = (         int )0;
 sqlstm.sqfmod = (unsigned int )2;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_count;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_count;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_min_succ;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_min_succ;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_min_total;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_min_total;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&v_buffer_period;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_buffer_period;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&v_cutoff_time;
 sqlstm.sqhstl[4] = (unsigned long )17;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_cutoff_time;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&v_from_time;
 sqlstm.sqhstl[5] = (unsigned long )23;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_from_time;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&v_to_time;
 sqlstm.sqhstl[6] = (unsigned long )23;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_to_time;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&v_psp_name;
 sqlstm.sqhstl[7] = (unsigned long )53;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_psp_name;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&v_bank_name;
 sqlstm.sqhstl[8] = (unsigned long )153;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_bank_name;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
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



	if (ind_count < 0)
		v_count = 0;
	sprintf(cs_count,"%d",v_count);

	if (ind_min_succ < 0)
		v_min_succ = 0;
	sprintf(cs_min_succ,"%d",v_min_succ);

	if (ind_min_total < 0)
		v_min_total = 0;
	sprintf(cs_min_total,"%d",v_min_total);

	if (ind_buffer_period < 0)
		v_buffer_period = 0;
	sprintf(cs_buffer_period,"%d",v_buffer_period);

	if (ind_cutoff_time >= 0) {
		sprintf(cs_cutoff_time,"%.*s",v_cutoff_time.len,v_cutoff_time.arr);
	}

	if (ind_from_time >= 0) {
		sprintf(cs_from_time,"%.*s",v_from_time.len,v_from_time.arr);
	}

	if (ind_to_time >= 0) {
		sprintf(cs_to_time,"%.*s",v_to_time.len,v_to_time.arr);
	}

	if (ind_psp_name >= 0) {
		sprintf(cs_psp_name,"%.*s",v_psp_name.len,v_psp_name.arr);
	}

	if (ind_bank_name >= 0) {
		sprintf(cs_bank_name,"%.*s",v_bank_name.len,v_bank_name.arr);
	}

	/* EXEC SQL CLOSE c_cursor_get_check; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )95;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto find_error;
}



	if(v_count == 0) {
		iRet = SUCCESS;
	}

DEBUGLOG(("find() %s;%s;%s;%s;%s;\n",cs_count,cs_min_succ,cs_min_total,cs_buffer_period,cs_cutoff_time));
DEBUGLOG(("find() iRet = [%d]\n",iRet));
	return iRet;

find_error:
DEBUGLOG(("find_checking_parameters error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_get_check; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 9;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )110;
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
    sqlstm.arrsiz = 9;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )125;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}

int process_txn(const char* csPspId, const char* csPspName, const char* csBankCode, const char* csBankName, const char* csCount, const char* csMinCnt)
{               
DEBUGLOG(("process_txn() start psp_id=[%s], bank_code=[%s]\n",csPspId,csBankCode));
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

		/* varchar	hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;

		/* varchar	hv_cutoff_time[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_cutoff_time;

		/* varchar	hv_buffer_period[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_buffer_period;

		int	hv_cnt;

		char	v_status;
		char	v_ar_ind;
		int	v_cnt;

		short	ind_status = -1;
		short	ind_ar_ind = -1;
		short	ind_cnt = -1;

		SQL_CURSOR	c_cursor_psp_bank_performance;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_psp_id.len = strlen((char*)csPspId);
        memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);

	hv_bank_code.len = strlen((char*)csBankCode);
        memcpy(hv_bank_code.arr,csBankCode,hv_bank_code.len);

	hv_cutoff_time.len = strlen((char*)cs_cutoff_time);
        memcpy(hv_cutoff_time.arr,cs_cutoff_time,hv_cutoff_time.len);

	hv_buffer_period.len = strlen((char*)cs_buffer_period);
        memcpy(hv_buffer_period.arr,cs_buffer_period,hv_buffer_period.len);

	hv_cnt=iCnt;

	/* EXEC SQL ALLOCATE	:c_cursor_psp_bank_performance; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )140;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_psp_bank_performance;
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
 if (sqlca.sqlcode < 0) goto sql_error;
}


	/* EXEC SQL EXECUTE
		BEGIN
			BANK_TXN_CHECK_PKG.P_PSP_BANK_PERFORMANCE(:hv_psp_id,
								:hv_bank_code,
								:hv_cutoff_time,
								:hv_buffer_period,
								:hv_cnt,
								:c_cursor_psp_bank_performance);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin BANK_TXN_CHECK_PKG . P_PSP_BANK_PERFORMANCE ( :hv_psp\
_id , :hv_bank_code , :hv_cutoff_time , :hv_buffer_period , :hv_cnt , :c_curs\
or_psp_bank_performance ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )159;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_code;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_cutoff_time;
 sqlstm.sqhstl[2] = (unsigned long )16;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_buffer_period;
 sqlstm.sqhstl[3] = (unsigned long )10;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_cnt;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&c_cursor_psp_bank_performance;
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




DEBUGLOG(("process_txn() selected\n"));
        for (;;) {
		/* EXEC SQL FETCH :c_cursor_psp_bank_performance
                INTO
		 	:v_cnt:ind_cnt,
         		:v_status:ind_status,
         		:v_ar_ind:ind_ar_ind; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )198;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_psp_bank_performance;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_cnt;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_cnt;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[2] = (unsigned long )1;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_status;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_ar_ind;
  sqlstm.sqhstl[3] = (unsigned long )1;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_ar_ind;
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


DEBUGLOG(("process_txn() fetched\n"));

                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		iChk ++;

//printf("status:[%c] ind:[%c] cnt:[%d]\n",v_status,v_ar_ind,v_cnt);

		if(ind_status>=0){
			if(v_status==PD_COMPLETE){
				if(ind_ar_ind>=0){
					if(v_ar_ind==PD_ACCEPT){
						if(ind_cnt>=0)
							iAccept += v_cnt;
//printf("Accept\n");
					}
					else if(v_ar_ind==PD_REJECT){
						if(ind_cnt>=0)
							iReject += v_cnt;
//printf("Reject\n");
					}
				}
				else{
					v_ar_ind=' ';
//printf("Not Count\n");
				}
			}
			else if(v_status==PD_TO_PSP){
				v_ar_ind=' ';
				if(ind_cnt>=0)
					iPending += v_cnt;
//printf("Pending\n");
			}
			else{
				if(ind_ar_ind<0){
					v_ar_ind=' ';
				}
				if(ind_cnt>=0)
					iOthers += v_cnt;
//printf("Other\n");
			}
		}

 	}
	/* EXEC SQL CLOSE :c_cursor_psp_bank_performance; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )229;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_psp_bank_performance;
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
 if (sqlca.sqlcode < 0) goto sql_error;
}


	/* EXEC SQL FREE :c_cursor_psp_bank_performance; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )248;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_psp_bank_performance;
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
 if (sqlca.sqlcode < 0) goto sql_error;
}



	if(iChk==0){
DEBUGLOG(("process_txn() iRet = [%d]\n",iRet));
		return iRet;
	}

//printf("iAccept:[%d] iReject:[%d] iPending:[%d] iOthers:[%d]\n",iAccept,iReject,iPending,iOthers);

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
printf("<tr><td><b>%s</b>(%s)</td>",csPspName,csPspId);
printf("<td>%s</td>",csBankName);
printf("<td>%d</td>",iAccept+iReject);
printf("<td>%d</td>",iPending);
printf("<td>%d</td>",iTotal);
printf("<td>%.2f%%</td>",dSuccRate*100);
printf("<td>%.2f%%</td></tr>\n",dRate*100);
printf("<tr><td></td><td colspan='6'>Duration:%s to %s</td></tr>\n",cs_from_time,cs_to_time);
		}
		iCh = update_last_checking(csPspId, csBankCode);
DEBUGLOG(("process_txn() %d/%d = [%.2f] [%.2f]\n",iAccept+iReject,iTotal,dSuccRate,dRate));
	}

DEBUGLOG(("process_txn() iRet = [%d]\n",iRet));
        return iRet;
sql_error:
    DEBUGLOG(("process_txn error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE :c_cursor_psp_bank_performance; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 9;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )267;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_psp_bank_performance;
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
}


    /* EXEC SQL FREE :c_cursor_psp_bank_performance; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 9;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )286;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_psp_bank_performance;
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
}


    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 9;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )305;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}

int update_last_checking(const char* csPspId, const char* csBankCode)
{
DEBUGLOG(("find::update_last_checking() party_id=[%s] bank_code=[%s]\n",csPspId,csBankCode));
	int	iRet = SUCCESS;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;

		/* varchar	hv_cutoff_time[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_cutoff_time;


	/* EXEC SQL END DECLARE SECTION; */ 


	hv_psp_id.len = strlen((char*)csPspId);
	memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);

	hv_bank_code.len = strlen((char*)csBankCode);
	memcpy(hv_bank_code.arr,csBankCode,hv_bank_code.len);

	hv_cutoff_time.len = strlen((char*)cs_cutoff_time);
	memcpy(hv_cutoff_time.arr,cs_cutoff_time,hv_cutoff_time.len);

       	/* EXEC SQL
		UPDATE	bank_txn_check
		SET	bc_cutoff_checking_time = TO_DATE(:hv_cutoff_time,'YYYYMMDDHH24MISS'),
 			bc_last_checking_time = sysdate,
			bc_update_timestamp = sysdate
 		WHERE	bc_disabled = 0
		AND	bc_party_id = :hv_psp_id
		AND	bc_bank_code = :hv_bank_code; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "update bank_txn_check SET bc_cutoff_checking_time = \
TO_DATE ( :b0 , 'YYYYMMDDHH24MISS' ) , bc_last_checking_time = sysdate , bc_u\
pdate_timestamp = sysdate WHERE bc_disabled = 0 AND bc_party_id = :b1 AND bc_\
bank_code = :b2 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )320;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_cutoff_time;
        sqlstm.sqhstl[0] = (unsigned long )16;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_code;
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
        if (sqlca.sqlcode < 0) goto update_error;
}


	
DEBUGLOG(("find::update_last_checking() iRet = [%d]\n",iRet));
	return iRet;

update_error:
DEBUGLOG(("update_last_check error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 9;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )347;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}

