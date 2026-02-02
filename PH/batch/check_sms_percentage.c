
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
           char  filnam[24];
};
static struct sqlcxp sqlfpn =
{
    23,
    "check_sms_percentage.pc"
};


static unsigned int sqlctx = 582330195;


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
   unsigned char  *sqhstv[7];
   unsigned long  sqhstl[7];
            int   sqhsts[7];
            short *sqindv[7];
            int   sqinds[7];
   unsigned long  sqharm[7];
   unsigned long  *sqharc[7];
   unsigned short  sqadto[7];
   unsigned short  sqtdso[7];
} sqlstm = {12,7};

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
"ISS' ) GROUP BY B . OB_OWNER_NAME , \
E . BANK_NAME , A . OBT_BANK_CODE , A . OBT_BANK_ACCT_NUM ORDER BY A . OBT_BA\
NK_CODE , A . OBT_BANK_ACCT_NUM            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,1180,0,9,135,0,2049,3,3,0,1,0,1,9,0,0,1,3,0,0,1,9,0,0,
32,0,0,1,0,0,13,137,0,0,7,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,
0,0,2,3,0,0,
75,0,0,1,0,0,15,208,0,0,0,0,0,1,0,
90,0,0,1,0,0,15,265,0,0,0,0,0,1,0,
105,0,0,2,0,0,32,266,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/07/29              Dirk Wong 
Mask bank owner name, bank acct num		   2019/04/18		   CheukFung Lee
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

char csCurrTime[PD_DATETIME_LEN+1];
int iInterval=0;
int iAlertPercentage=0;

char csTag[PD_TAG_LEN+1];
char csTmp[PD_TMP_BUF_LEN+1];
static char cDebug = 'Y';
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


DEBUGLOG(("check_sms_perecntage Start!\n"));

	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar hv_curr_time[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_curr_time;

		int	hv_interval;

		/* varchar	v_owner_name[PD_OWNER_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_owner_name;

		/* varchar	v_bank_name[PD_BANK_ACCT_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_name;

		/* varchar v_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

		/* varchar	v_bank_acct_num[PD_BANK_ACCT_NUM_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

		int	v_omt_cnt;
		int	v_sms_cnt;
		int	v_ttl_deposit_cnt;

		short	ind_owner_name = -1;
		short	ind_bank_name = -1;
		short	ind_bank_code = -1;
		short	ind_bank_acct_num = -1;
		short	ind_omt_cnt = -1;
		short	ind_sms_cnt = -1;
		short	ind_ttl_deposit_cnt = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_curr_time.len = strlen(csCurrTime);
	memcpy(hv_curr_time.arr,csCurrTime,hv_curr_time.len);
DEBUGLOG(("curr_time = [%s]\n",hv_curr_time.arr));

	hv_interval = iInterval;
DEBUGLOG(("interval = [%d]\n",hv_interval));

	/* EXEC SQL DECLARE c_cursor_getinfo CURSOR FOR
		SELECT	sp_mask_owner_name(A.OBT_BANK_CODE, B.OB_OWNER_NAME),
			E.BANK_NAME,
			A.OBT_BANK_CODE,
			sp_mask_bank_acct_num(A.OBT_BANK_CODE, A.OBT_BANK_ACCT_NUM),
			sum(decode(C.OLSD_INPUT_CHANNEL,'BNK_STMT',1,0)) as omt_cnt,
			sum(decode(C.OLSD_INPUT_CHANNEL,'SMS_STMT',1,0)) as sms_cnt,
			count(1) as ttl_cnt_deposit
		FROM	ol_baid_txn A,
			ol_bank_accts B,
			ol_statement_detail C,
			(SELECT sp_val FROM system_parameter WHERE sp_code='OFL_SMS_STMT_UPL') D,
			bank_desc E
		WHERE	D.sp_val = 1
		  AND	A.obt_bank_code = B.ob_int_bank_code
		  AND	A.obt_bank_acct_num = B.ob_bank_acct_num
		  AND	A.obt_stat_txn_id = C.olsd_stat_txn_id
		  AND	B.ob_int_bank_code = E.internal_bank_code
		  AND	A.obt_txn_code = 'OBD'
		  AND	A.obt_status = 'C'
		  AND	A.obt_ar_ind = 'A'
		  AND	B.ob_support_sms_stmt = 1
		  AND	B.OB_SYS_SWITCH_ENABLED = 1
		  AND	A.obt_create_timestamp >= to_date(:hv_curr_time,'YYYYMMDDHH24MISS') - (1/24/60)*:hv_interval
		  AND	A.obt_create_timestamp < to_date(:hv_curr_time,'YYYYMMDDHH24MISS')
		GROUP BY
			B.OB_OWNER_NAME,
			E.BANK_NAME,
			A.OBT_BANK_CODE,
			A.OBT_BANK_ACCT_NUM
		ORDER BY
			A.OBT_BANK_CODE,
			A.OBT_BANK_ACCT_NUM; */ 



	/* EXEC SQL OPEN c_cursor_getinfo; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "SELECT sp_mask_owner_name ( A . OBT_BANK_CODE , B . OB_OWNER_NAME ) , E \
. BANK_NAME , A . OBT_BANK_CODE , sp_mask_bank_acct_num ( A . OBT_BANK_CODE \
, A . OBT_BANK_ACCT_NUM ) , sum ( decode ( C . OLSD_INPUT_CHANNEL , 'BNK_STM\
T' , 1 , 0 ) ) as omt_cnt , sum ( decode ( C . OLSD_INPUT_CHANNEL , 'SMS_STM\
T' , 1 , 0 ) ) as sms_cnt , count ( 1 ) as ttl_cnt_deposit FROM ol_baid_txn \
A , ol_bank_accts B , ol_statement_detail C , ( SELECT sp_val FROM system_pa\
rameter WHERE sp_code = 'OFL_SMS_STMT_UPL' ) D , bank_desc E WHERE D . sp_va\
l = 1 AND A . obt_bank_code = B . ob_int_bank_code AND A . obt_bank_acct_num\
 = B . ob_bank_acct_num AND A . obt_stat_txn_id = C . olsd_stat_txn_id AND B\
 . ob_int_bank_code = E . internal_bank_code AND A . obt_txn_code = 'OBD' AN\
D A . obt_status = 'C' AND A . obt_ar_ind = 'A' AND B . ob_support_sms_stmt \
= 1 AND B . OB_SYS_SWITCH_ENABLED = 1 AND A . obt_create_timestamp >= to_dat\
e ( :b0 , 'YYYYMMDDHH24MISS' ) - ( 1 / 24 / 60 ) * :b1 AND A . obt_create_ti\
mestamp < to_date ( :b0 , 'YYYYMMDDHH24M");
 sqlstm.stmt = sq0001;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_curr_time;
 sqlstm.sqhstl[0] = (unsigned long )17;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_interval;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_curr_time;
 sqlstm.sqhstl[2] = (unsigned long )17;
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
 if (sqlca.sqlcode < 0) goto sql_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getinfo
		INTO
			:v_owner_name:ind_owner_name,
			:v_bank_name:ind_bank_name,
			:v_bank_code:ind_bank_code,
			:v_bank_acct_num:ind_bank_acct_num,
			:v_omt_cnt:ind_omt_cnt,
			:v_sms_cnt:ind_sms_cnt,
			:v_ttl_deposit_cnt:ind_ttl_deposit_cnt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )32;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_owner_name;
  sqlstm.sqhstl[0] = (unsigned long )53;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_owner_name;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_bank_name;
  sqlstm.sqhstl[1] = (unsigned long )53;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_bank_name;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_bank_code;
  sqlstm.sqhstl[2] = (unsigned long )13;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_bank_code;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_bank_acct_num;
  sqlstm.sqhstl[3] = (unsigned long )53;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_bank_acct_num;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_omt_cnt;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_omt_cnt;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_sms_cnt;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_sms_cnt;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_ttl_deposit_cnt;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_ttl_deposit_cnt;
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

		if (ind_sms_cnt >= 0 && ind_ttl_deposit_cnt >= 0) {
			// percentage
			sprintf(csTag,"fsms_percentage-%d",iCnt);
			double dTmp = 0.0;
			dTmp = ((double)v_sms_cnt/(double)v_ttl_deposit_cnt)*100;

			if (dTmp <= iAlertPercentage) {
				sprintf(csTmp,"%.2f%c",((double)v_sms_cnt/(double)v_ttl_deposit_cnt)*100,'%');
				iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","stbl_body-0",csTmp);

				if (ind_owner_name >= 0) {
					// Owner name
					sprintf(csTag,"fowner_name-%d",iCnt);
					sprintf(csTmp,"%.*s",v_owner_name.len,v_owner_name.arr);
					iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","stbl_body-0",csTmp);
				}

				if (ind_bank_name >= 0) {
					// Bank Name
					sprintf(csTag,"fbank_name-%d",iCnt);
					sprintf(csTmp,"%.*s",v_bank_name.len,v_bank_name.arr);
					iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","stbl_body-0",csTmp);
				}

				if (ind_bank_acct_num >= 0) {
					// Bank Acct Num
					sprintf(csTag,"fbank_acct_num-%d",iCnt);
					sprintf(csTmp,"%.*s",v_bank_acct_num.len,v_bank_acct_num.arr);
					iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","stbl_body-0",csTmp);
				}

				if (ind_omt_cnt >= 0) {
					// omt_cnt
					sprintf(csTag,"fomt_cnt-%d",iCnt);
					iDynCnt = set_tpl_dyn_int(hContext,iDynCnt,csTag,"INT","stbl_body-0",v_omt_cnt);
				}

				if (ind_sms_cnt >= 0) {
					// sms_cnt
					sprintf(csTag,"fsms_cnt-%d",iCnt);
					iDynCnt = set_tpl_dyn_int(hContext,iDynCnt,csTag,"INT","stbl_body-0",v_sms_cnt);
				}

				if (ind_ttl_deposit_cnt >= 0) {
					// ttl_deposit_cnt
					sprintf(csTag,"fttl_deposit_cnt-%d",iCnt);
					iDynCnt = set_tpl_dyn_int(hContext,iDynCnt,csTag,"INT","stbl_body-0",v_ttl_deposit_cnt);
				}

				iCnt ++;
			}
		}
	}
	while(PD_TRUE && iRet == SUCCESS);
	/* EXEC SQL CLOSE c_cursor_getinfo; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )75;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto sql_error;
}



	if (iCnt > 0) {
		/*stimestamp*/
		iDynCnt = set_tpl_dyn_int(hContext,iDynCnt,"stimestamp-0","SEC","stimestamp-0",0);

		/*ftimestamp*/
		iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,"ftimestamp-0","STR","stimestamp-0",write_tpl_timestamp());

		/*finterval*/
		iDynCnt = set_tpl_dyn_int(hContext,iDynCnt,"finterval-0","INT","stimestamp-0",iInterval);

		/*falertpercent*/
		iDynCnt = set_tpl_dyn_int(hContext,iDynCnt,"falertpercent-0","INT","stimestamp-0",iAlertPercentage);

		/*stitle*/
		iDynCnt = set_tpl_dyn_int(hContext,iDynCnt,"stitle-0","SEC","stitle-0",0);

		/*ftitle*/
		sprintf(csTmp, "SMS Percentage Alert");
		iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,"ftitle-0","STR","stitle-0",csTmp);

		iDynCnt = set_tpl_dyn_int(hContext, iDynCnt, "stbl_head-0", "SEC", "stbl_head-0", 0);
		iDynCnt = set_tpl_dyn_int(hContext, iDynCnt, "stbl_body-0", "SEC", "stbl_body-0", iCnt);

		iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,"subject","GLO","STR","SMS Percentage Alert");

		PutField_CString(hContext,"source","BATCH");
		PutField_CString(hContext,"funct","SMS_PERCENTAGE");
		PutField_Char(hContext,"party_type",'G');
		PutField_CString(hContext,"party_id","000");

		PutField_Int(hContext,"total_dyn",iDynCnt);

		BOObjPtr = CreateObj(BOPtr,"BOAlertEmail","ProcessTpl");
		if((unsigned long)((*BOObjPtr)(hContext) != PD_OK)){
			iRet=INT_CODE_ERROR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("BOAlertEmail:ProcessTpl Failed\n"));
ERRLOG("check_sms_perecntage BOAlertEmail::ProcessTpl Failed, iRet=%d\n", iRet);
		}
		else
		{
DEBUGLOG(("BOAlertEmail:ProcessTpl Success\n"));
		}
	}

DEBUGLOG(("check_sms_perecntage normal exit!\n"));

	FREE_ME(hContext);

	return iRet;

sql_error:
DEBUGLOG(("check_sms_perecntage error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getinfo; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 7;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )90;
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
    sqlstm.arrsiz = 7;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )105;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int batch_terminate(int argc, char* argv[])
{
        return SUCCESS;
}


int parse_arg(int argc,char **argv)
{

        char    c;

        if (argc < 4) {
                return PD_ERR;
        }
        while ((c = getopt(argc,argv,"t:i:p:")) != EOF) {
                switch (c) {
                        case 't':
                                memcpy(csCurrTime,optarg,PD_DATETIME_LEN);
                                break;
                        case 'i':
                                iInterval = atoi(optarg);
                                break;
                        case 'p':
                                iAlertPercentage = atoi(optarg);
                                break;
                        default:
                                return PD_ERR;
                }
        }

        return SUCCESS;
}
