
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
    "check_missing_stmt.pc"
};


static unsigned int sqlctx = 145426123;


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

 static char *sq0001 = 
"BD_INT_BANK_CODE = OB_INT_BANK_CODE \
AND OAUBD_BANK_ACCT_NUM = OB_BANK_ACCT_NUM AND OAUBD_INT_BANK_CODE = INTERNAL\
_BANK_CODE AND OB_INT_BANK_CODE = OBAI_INT_BANK_CODE AND OB_BANK_ACCT_NUM = O\
BAI_BANK_ACCT_NUM AND OBAI_PSP_ID = OPD_PSP_ID AND OPD_CLIENT_ID = PM_CLIENT_\
ID AND PM_CLIENT_ID = OAUS_PROVIDER_ID AND OB_ACCT_TYPE = OAUS_NATURE AND OFF\
LINE_DEPOSIT = :b2 AND OAUS_DISABLED = :b3 AND OB_ACCT_TYPE = :b0 AND OB_STAT\
US_TYPE = :b5 AND OB_SYS_SWITCH_ENABLED = :b6 AND OBAI_STATUS = :b7 AND OPD_S\
TATUS = :b8 AND OLSH_FILE_ID = MAX_OLSH_FILE_ID AND OLSH_CREATE_TIMESTAMP < T\
O_DATE ( :b9 , 'YYYYMMDDHH24MISS' ) - ( 1 / 24 / 60 ) * :b10 ORDER BY PM_CLIE\
NT_NAME , BANK_NAME , OB_BANK_ACCT_SHORT_NAME , OB_BANK_ACCT_NUM            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,1752,0,9,210,0,2049,11,11,0,1,0,1,9,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,9,0,
0,1,9,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,
64,0,0,1,0,0,13,212,0,0,7,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,
107,0,0,1,0,0,15,281,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2018/01/17              [ETN] 
Revise SQL					   2018/01/25              [WWK] 
Revise SQL					   2018/01/25              [WWK] 
Empty Provider when err [5040,5042,5062]	   2018/04/03		   [WWK]
Revise SQL					   2018/09/14		   [WMC]
PRD183 Change scan DB and check missing deposit    2018/11/29              [TNY]
bank statement from last 15 to 10 mins
Revise SQL for mask_bank_acct_num		   2019/04/23		   [MIC]
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
#include "internal.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char cs_nature[PD_TAG_LEN+1];
char cs_alert_ts[PD_DATETIME_LEN+1];
int i_interval;

char csTag[PD_TAG_LEN+1];
char csTmp[PD_TMP_BUF_LEN+1];
static char cDebug='Y';
int iCnt=0;
int iDynCnt=0;

OBJPTR(BO);

int parse_arg(int argc,char **argv);

int batch_init(int argc, char* argv[])
{
        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int     iRet = parse_arg(argc,argv);

	hash_t *hContext;

	if (iRet != SUCCESS) {
		return FAILURE;
	}

	hContext = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hContext,0);

	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


DEBUGLOG(("check_missing_stmt Start!\n"));

	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_acct_type[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_acct_type;

		/* varchar	hv_bank_acct_status[PD_ACCOUNT_STATUS_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_bank_acct_status;

		int	hv_sys_switch;
		/* varchar	hv_baid_status[PD_ACCOUNT_STATUS_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_baid_status;

		/* varchar	hv_pid_status[PD_ACCOUNT_STATUS_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_pid_status;

		/* varchar	hv_alert_ts[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_alert_ts;

		int	hv_interval;
		int	hv_offline_deposit;
		int	hv_auto_upload_provider_disabled;

		/* varchar	v_client_name[PD_CLIENT_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_client_name;

		/* varchar	v_bank_name[PD_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

		/* varchar v_bank_acct_short_name[PD_BANK_ACCT_SHORT_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_bank_acct_short_name;

		/* varchar v_mask_bank_acct_num[PD_BANK_ACCT_NUM_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_mask_bank_acct_num;
			
		/* varchar	v_last_stmt_filename[PD_UPLOAD_FILENAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_last_stmt_filename;

		/* varchar	v_last_stmt_upload_ts[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_last_stmt_upload_ts;

		/* varchar	v_create_user[PD_CREATE_USER_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_create_user;


		short	ind_client_name = -1;
		short	ind_bank_name = -1;
		short	ind_bank_acct_short_name = -1;
		short	ind_mask_bank_acct_num = -1;					
		short	ind_last_stmt_filename = -1;
		short	ind_last_stmt_upload_ts = -1;
		short	ind_create_user = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_acct_type.len = strlen(cs_nature);
	memcpy(hv_acct_type.arr,cs_nature,hv_acct_type.len);
/*PRD183 change from 15 to 10 mins
DEBUGLOG(("hv_acct_type = [%s]\n",hv_acct_type.arr));
*/
DEBUGLOG(("hv_acct_type = [%.*s]\n",hv_acct_type.len, hv_acct_type.arr));

	hv_bank_acct_status.len = strlen(PD_BANK_ACCT_STATUS_ACTIVE);
	memcpy(hv_bank_acct_status.arr,PD_BANK_ACCT_STATUS_ACTIVE,hv_bank_acct_status.len);
/*PRD183 change from 15 to 10 mins
DEBUGLOG(("hv_bank_acct_status = [%s]\n",hv_bank_acct_status.arr));
*/
DEBUGLOG(("hv_bank_acct_status = [%.*s]\n",hv_bank_acct_status.len, hv_bank_acct_status.arr));

	hv_sys_switch = PD_TRUE;
DEBUGLOG(("hv_sys_switch = [%d]\n", PD_TRUE));

	hv_baid_status.len = strlen(PD_BAID_STATUS_OPEN);
	memcpy(hv_baid_status.arr,PD_BAID_STATUS_OPEN,hv_baid_status.len);
/*PRD183 change from 15 to 10 mins
DEBUGLOG(("hv_baid_status = [%s]\n",hv_baid_status.arr));
*/
DEBUGLOG(("hv_baid_status = [%.*s]\n",hv_baid_status.len, hv_baid_status.arr));

	hv_pid_status.len = strlen(PD_ACC_OPEN);
	memcpy(hv_pid_status.arr,PD_ACC_OPEN,hv_pid_status.len);
/*PRD183 change from 15 to 10 mins
DEBUGLOG(("hv_pid_status = [%s]\n",hv_pid_status.arr));
*/
DEBUGLOG(("hv_pid_status = [%.*s]\n",hv_pid_status.len, hv_pid_status.arr));

	hv_alert_ts.len = strlen(cs_alert_ts);
	memcpy(hv_alert_ts.arr,cs_alert_ts,hv_alert_ts.len);
/*PRD183 change from 15 to 10 mins
DEBUGLOG(("hv_alert_ts = [%s]\n",hv_alert_ts.arr));
*/
DEBUGLOG(("hv_alert_ts = [%.*s]\n",hv_alert_ts.len, hv_alert_ts.arr));

	hv_interval = i_interval;
DEBUGLOG(("hv_interval = [%d]\n", i_interval));

	hv_offline_deposit = PD_TRUE;
DEBUGLOG(("hv_offline_deposit = [%d]\n", PD_TRUE));

	hv_auto_upload_provider_disabled = PD_FALSE;
DEBUGLOG(("auto_upload_provider_disabled = [%d]\n", PD_FALSE));


	/* EXEC SQL DECLARE c_cursor_getinfo CURSOR FOR
		SELECT	PM_CLIENT_NAME,
			BANK_NAME,
			OB_BANK_ACCT_SHORT_NAME,
			sp_mask_bank_acct_num(OB_INT_BANK_CODE,OB_BANK_ACCT_NUM),		
			OLSH_ORG_FILENAME, 
			TO_CHAR(OLSH_CREATE_TIMESTAMP,'YYYY-MM-DD HH24:MI:SS') OLSH_CREATE_TIMESTAMP,
			OLSH_CREATE_USER  
		FROM 	OL_STATEMENT_HEADER,
			(SELECT	OAUBD_INT_BANK_CODE, 
				OAUBD_BANK_ACCT_NUM, 
				MAX(OLSH_CREATE_TIMESTAMP) AS MAX_OLSH_CREATE_TIMESTAMP, 
				MAX(OLSH_FILE_ID) AS MAX_OLSH_FILE_ID
			 FROM	OL_STATEMENT_HEADER,
				(SELECT	OAUBD_INT_BANK_CODE, 
					OAUBD_BANK_ACCT_NUM
				 FROM	OL_AUTO_UPLOAD_BANK_DETAIL
				 WHERE	OAUBD_DISABLED = 0
				 AND	OAUBD_INT_BANK_CODE IN (SELECT OAUBD_INT_BANK_CODE 
								FROM   OL_AUTO_UPLOAD_BANK_DETAIL 
								WHERE  OAUBD_BANK_ACCT_NUM='000' 
								AND    OAUBD_ACCT_TYPE = :hv_acct_type
								AND    OAUBD_DISABLED = 0)
				 AND	OAUBD_ACCT_TYPE = :hv_acct_type) 
			 WHERE	OLSH_INT_BANK_CODE = OAUBD_INT_BANK_CODE 
			 AND	OLSH_BANK_ACCT_NUM = OAUBD_BANK_ACCT_NUM 
			 GROUP BY 
				OAUBD_INT_BANK_CODE, 
				OAUBD_BANK_ACCT_NUM),
			OL_AUTO_UPLOAD_STMT_SETTING, 
			OL_BANK_ACCTS,
			BANK_DESC,
			OL_BANK_ACCT_ID,
			OL_PSP_DETAIL,
			PSP_MASTER
		WHERE	OAUBD_INT_BANK_CODE = OB_INT_BANK_CODE
		AND	OAUBD_BANK_ACCT_NUM = OB_BANK_ACCT_NUM
		AND	OAUBD_INT_BANK_CODE = INTERNAL_BANK_CODE
		AND	OB_INT_BANK_CODE = OBAI_INT_BANK_CODE
		AND	OB_BANK_ACCT_NUM = OBAI_BANK_ACCT_NUM
		AND	OBAI_PSP_ID = OPD_PSP_ID
		AND	OPD_CLIENT_ID = PM_CLIENT_ID 
		AND	PM_CLIENT_ID = OAUS_PROVIDER_ID
		AND	OB_ACCT_TYPE = OAUS_NATURE
		AND	OFFLINE_DEPOSIT = :hv_offline_deposit
		AND	OAUS_DISABLED = :hv_auto_upload_provider_disabled
		AND	OB_ACCT_TYPE = :hv_acct_type
		AND	OB_STATUS_TYPE = :hv_bank_acct_status
		AND	OB_SYS_SWITCH_ENABLED = :hv_sys_switch
		AND	OBAI_STATUS = :hv_baid_status
		AND	OPD_STATUS = :hv_pid_status
		AND 	OLSH_FILE_ID = MAX_OLSH_FILE_ID
		AND	OLSH_CREATE_TIMESTAMP < TO_DATE(:hv_alert_ts,'YYYYMMDDHH24MISS') - (1/24/60)*:hv_interval
		ORDER BY
			PM_CLIENT_NAME,
			BANK_NAME,
			OB_BANK_ACCT_SHORT_NAME,
			OB_BANK_ACCT_NUM; */ 

	
	/* EXEC SQL OPEN c_cursor_getinfo; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "SELECT PM_CLIENT_NAME , BANK_NAME , OB_BANK_ACCT_SHORT_NAME , sp_mask_ba\
nk_acct_num ( OB_INT_BANK_CODE , OB_BANK_ACCT_NUM ) , OLSH_ORG_FILENAME , TO\
_CHAR ( OLSH_CREATE_TIMESTAMP , 'YYYY-MM-DD HH24:MI:SS' ) OLSH_CREATE_TIMEST\
AMP , OLSH_CREATE_USER FROM OL_STATEMENT_HEADER , ( SELECT OAUBD_INT_BANK_CO\
DE , OAUBD_BANK_ACCT_NUM , MAX ( OLSH_CREATE_TIMESTAMP ) AS MAX_OLSH_CREATE_\
TIMESTAMP , MAX ( OLSH_FILE_ID ) AS MAX_OLSH_FILE_ID FROM OL_STATEMENT_HEADE\
R , ( SELECT OAUBD_INT_BANK_CODE , OAUBD_BANK_ACCT_NUM FROM OL_AUTO_UPLOAD_B\
ANK_DETAIL WHERE OAUBD_DISABLED = 0 AND OAUBD_INT_BANK_CODE IN ( SELECT OAUB\
D_INT_BANK_CODE FROM OL_AUTO_UPLOAD_BANK_DETAIL WHERE OAUBD_BANK_ACCT_NUM = \
'000' AND OAUBD_ACCT_TYPE = :b0 AND OAUBD_DISABLED = 0 ) AND OAUBD_ACCT_TYPE\
 = :b0 ) WHERE OLSH_INT_BANK_CODE = OAUBD_INT_BANK_CODE AND OLSH_BANK_ACCT_N\
UM = OAUBD_BANK_ACCT_NUM GROUP BY OAUBD_INT_BANK_CODE , OAUBD_BANK_ACCT_NUM \
) , OL_AUTO_UPLOAD_STMT_SETTING , OL_BANK_ACCTS , BANK_DESC , OL_BANK_ACCT_I\
D , OL_PSP_DETAIL , PSP_MASTER WHERE OAU");
 sqlstm.stmt = sq0001;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_acct_type;
 sqlstm.sqhstl[0] = (unsigned long )5;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_acct_type;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_offline_deposit;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_auto_upload_provider_disabled;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_acct_type;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_bank_acct_status;
 sqlstm.sqhstl[5] = (unsigned long )4;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_sys_switch;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_baid_status;
 sqlstm.sqhstl[7] = (unsigned long )4;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)0;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_pid_status;
 sqlstm.sqhstl[8] = (unsigned long )4;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)0;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_alert_ts;
 sqlstm.sqhstl[9] = (unsigned long )16;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)0;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_interval;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)0;
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


	do {
		/* EXEC SQL FETCH c_cursor_getinfo
		INTO
			:v_client_name:ind_client_name,
			:v_bank_name:ind_bank_name,
			:v_bank_acct_short_name:ind_bank_acct_short_name,
			:v_mask_bank_acct_num:ind_mask_bank_acct_num,		
			:v_last_stmt_filename:ind_last_stmt_filename,
			:v_last_stmt_upload_ts:ind_last_stmt_upload_ts,
			:v_create_user:ind_create_user; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 11;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )64;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_client_name;
  sqlstm.sqhstl[0] = (unsigned long )53;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_client_name;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_bank_name;
  sqlstm.sqhstl[1] = (unsigned long )153;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_bank_name;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_bank_acct_short_name;
  sqlstm.sqhstl[2] = (unsigned long )23;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_bank_acct_short_name;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_mask_bank_acct_num;
  sqlstm.sqhstl[3] = (unsigned long )53;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_mask_bank_acct_num;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_last_stmt_filename;
  sqlstm.sqhstl[4] = (unsigned long )103;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_last_stmt_filename;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_last_stmt_upload_ts;
  sqlstm.sqhstl[5] = (unsigned long )23;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_last_stmt_upload_ts;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_create_user;
  sqlstm.sqhstl[6] = (unsigned long )23;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_create_user;
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
  if (sqlca.sqlcode < 0) goto sql_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			if (iCnt == 0) {
DEBUGLOG(("No data found!\n"));
			}
			break;
		}

		if (ind_client_name >= 0) {
                        sprintf(csTag, "fclient_name-%d", iCnt);
                        sprintf(csTmp, "%.*s", v_client_name.len, v_client_name.arr);
                        iDynCnt = set_tpl_dyn_cstring(hContext, iDynCnt, csTag, "STR", "stbl_body-0", csTmp);
DEBUGLOG(("cleint_name: %s\n", csTmp));
                }

		if (ind_bank_name >= 0) {
			sprintf(csTag, "fbank_name-%d", iCnt);
			sprintf(csTmp, "%.*s", v_bank_name.len, v_bank_name.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext, iDynCnt, csTag, "STR", "stbl_body-0", csTmp);
DEBUGLOG(("bank_name: %s\n", csTmp));
		}

		if (ind_bank_acct_short_name >= 0) {	
			sprintf(csTag, "fbank_acct_short_name-%d", iCnt);
			sprintf(csTmp, "%.*s", v_bank_acct_short_name.len, v_bank_acct_short_name.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext, iDynCnt, csTag, "STR", "stbl_body-0", csTmp);
DEBUGLOG(("bank_acct_short: %s\n", csTmp));
		}

		if (ind_mask_bank_acct_num >= 0) {
			sprintf(csTag, "fbank_acct_num-%d", iCnt);
			sprintf(csTmp, "%.*s", v_mask_bank_acct_num.len, v_mask_bank_acct_num.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext, iDynCnt, csTag, "STR", "stbl_body-0", csTmp);
DEBUGLOG(("mask_bank_acct_num: %s\n", csTmp));
		}


		if (ind_last_stmt_filename >= 0) {
			sprintf(csTag, "flast_stmt_filename-%d", iCnt);
			sprintf(csTmp, "%.*s", v_last_stmt_filename.len, v_last_stmt_filename.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext, iDynCnt, csTag, "STR", "stbl_body-0", csTmp);		
DEBUGLOG(("last_stmt_filename: %s\n", csTmp));
		}
		if (ind_last_stmt_upload_ts >= 0) {
			sprintf(csTag, "flast_stmt_upload_ts-%d", iCnt);
			sprintf(csTmp, "%.*s", v_last_stmt_upload_ts.len, v_last_stmt_upload_ts.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext, iDynCnt, csTag, "STR", "stbl_body-0", csTmp);
DEBUGLOG(("last_stmt_upload: %s\n", csTmp));
		}
		if (ind_create_user >= 0) {
			sprintf(csTag, "fcreate_user-%d", iCnt);
			sprintf(csTmp, "%.*s", v_create_user.len, v_create_user.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext, iDynCnt, csTag, "STR", "stbl_body-0", csTmp);
DEBUGLOG(("create_User: %s\n", csTmp));
		}

		iCnt++;
	}
	while(PD_TRUE && iRet == SUCCESS);

	/* EXEC SQL CLOSE c_cursor_getinfo; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )107;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto sql_error;
}



	if (iCnt > 0) {
		/*alert time */
		iDynCnt = set_tpl_dyn_int(hContext, iDynCnt, "stimestamp-0", "SEC", "stimestamp-0", 0);
		iDynCnt = set_tpl_dyn_cstring(hContext, iDynCnt, "ftimestamp-0", "STR", "stimestamp-0", write_tpl_timestamp()); 
		/*table head*/
		iDynCnt = set_tpl_dyn_int(hContext, iDynCnt, "stbl_head-0", "SEC", "stbl_head-0", 0);

		/*table body*/
		iDynCnt = set_tpl_dyn_int(hContext, iDynCnt, "stbl_body-0", "SEC", "stbl_body-0", iCnt);

		/*email title*/
		if (!strcmp(cs_nature,PD_NATURE_DEPOSIT)) {
			strcpy(cs_nature,PD_NATURE_DEPOSIT_NAME);
		} else if (!strcmp(cs_nature,PD_NATURE_PAYOUT)) {
			strcpy(cs_nature,PD_NATURE_PAYOUT_NAME);
		} else if (!strcmp(cs_nature,PD_NATURE_INTERMEDIATE)) {
			strcpy(cs_nature,PD_NATURE_INTERMEDIATE_NAME);
		}
		sprintf(csTmp, "Auto Upload %s Bank Statement - Missing Bank Statements", cs_nature);
		iDynCnt = set_tpl_dyn_cstring(hContext, iDynCnt, "MAIL_SUBJECT", "GLO", "STR", csTmp);

		PutField_CString(hContext, "source", PD_EML_SOURCE_BATCH);
		PutField_CString(hContext, "funct", PD_EML_FUNCT_CHK_MISS_STMT);
		PutField_Char(hContext, "party_type", PD_TYPE_GLOBAL);
		PutField_CString(hContext, "party_id", PD_EML_PARTY_ID_BATCH);

		PutField_Int(hContext, "total_dyn", iDynCnt);

		BOObjPtr = CreateObj(BOPtr, "BOAlertEmail", "ProcessTpl");
		if ((unsigned long)((*BOObjPtr)(hContext) != PD_OK)){
			iRet=INT_CODE_ERROR;
			PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("BOAlertEmail:ProcessTpl Failed\n"));
ERRLOG("check_new_baid_alert BOAlertEmail::ProcessTpl Failed, iRet=%d\n", iRet);
		}
		else
		{
DEBUGLOG(("BOAlertEmail:ProcessTpl Success\n"));
		}
	}

DEBUGLOG(("Missing Statements Alert normal exit!\n"));

	FREE_ME(hContext);

	return iRet;

sql_error:
DEBUGLOG(("checking_missing_stmt error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /*EXEC SQL WHENEVER SQLERROR CONTINUE;
    EXEC SQL CLOSE c_cursor_getinfo;
    EXEC SQL ROLLBACK RELEASE;*/
    return PD_ERR;
}


int batch_terminate(int argc, char* argv[])
{
        return SUCCESS;
}


int parse_arg(int argc, char **argv)
{
	char	c;
	strcpy(cs_nature,"");
	strcpy(cs_alert_ts,"");

	if (argc < 4) {
DEBUGLOG(("argc = [%d]\n",argc));
		return FAILURE;
	}

	while ((c = getopt(argc,argv,"n:t:i:")) != EOF) {
		switch (c) {
			case 'n':
				strcpy(cs_nature,optarg);
				break;
			case 't':
				strcpy(cs_alert_ts,optarg);
				break;
			case 'i':
				i_interval = atoi(optarg);
				break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(cs_nature,"") || !strcmp(cs_alert_ts,""))
		return FAILURE;


        return SUCCESS;
}
