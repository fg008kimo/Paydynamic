
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
           char  filnam[31];
};
static struct sqlcxp sqlfpn =
{
    30,
    "check_frozen_fund_txn_alert.pc"
};


static unsigned int sqlctx = 1421193339;


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
"MP_FROZEN_TXN_ALERT t WHERE t . TFA_\
TXN_ID = OTH_TXN_ID ) ORDER BY oth_approval_timestamp            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,1125,0,9,149,0,2049,2,2,0,1,0,1,1,0,0,1,9,0,0,
28,0,0,1,0,0,13,151,0,0,11,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
87,0,0,1,0,0,15,260,0,0,0,0,0,1,0,
102,0,0,1,0,0,15,302,0,0,0,0,0,1,0,
117,0,0,2,0,0,32,303,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2016/01/18              Dirk Wong 
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

char csDate[PD_DATE_LEN+1];

char csTag[PD_TAG_LEN+1];
char csTmp[PD_TMP_BUF_LEN+1];
char cDebug;
int iCnt=0;

int iDynCnt=0;

OBJPTR(BO);
OBJPTR(DB);

int parse_arg(int argc,char **argv);

int batch_init(int argc, char* argv[])
{
        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int     iRet = parse_arg(argc,argv);

	hash_t *hContext;
	hash_t *hTmpFrozenTxnAlert;
	char	csTxnId[PD_TXN_SEQ_LEN+1];

	if (iRet != SUCCESS) {
		return FAILURE;
	}

	hContext = (hash_t*) malloc (sizeof(hash_t));
	hTmpFrozenTxnAlert = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hContext,0);
	hash_init(hTmpFrozenTxnAlert,0);

	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


DEBUGLOG(("check_frozen_fund_txn_alert Start!\n"));

	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar hv_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_date;

		char	hv_ar_ind;

		/* varchar	v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar	v_bank_stmt_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_bank_stmt_id;

		/* varchar	v_txn_type[PD_DESC_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_type;

		/* varchar	v_pid[PD_DESC_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_pid;

		/* varchar	v_baid[PD_BAID_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_baid;

		/* varchar	v_txn_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

		double	v_txn_amt;
		/* varchar	v_cr_dr[2+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_cr_dr;

		/* varchar v_approval_ts[PD_TIMESTAMP_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_approval_ts;

		/* varchar v_create_user[PD_USER_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_create_user;

		/* varchar	v_approval_date[PD_DESC_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_approval_date;


		short	ind_txn_id = -1;
		short	ind_bank_stmt_id = -1;
		short	ind_txn_type = -1;
		short	ind_pid = -1;
		short	ind_baid = -1;
		short	ind_txn_ccy = -1;
		short	ind_txn_amt = -1;
		short	ind_cr_dr = -1;
		short	ind_approval_ts = -1;
		short	ind_create_user = -1;
		short	ind_approval_date = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_date.len = strlen(csDate);
	memcpy(hv_date.arr,csDate,hv_date.len);

	hv_ar_ind = PD_ACCEPT;

	/* EXEC SQL DECLARE c_cursor_getinfo CURSOR FOR


		SELECT  oth_txn_id,
			olsd_statement_ref,
			tc_desc,
			(select opd_psp_name from OL_PSP_DETAIL where OTP_PSP_ID = OPD_PSP_ID),
			obai_baid_name,
			oth_net_ccy,
			oth_transaction_amount,
			ote_amt_type,
			to_char(oth_approval_timestamp,'MM/DD/YYYY HH24:MI') approval_ts,
			oth_create_user,
			to_char(oth_approval_timestamp,'YYYY/MM/DD') approval_date
		FROM	OL_TXN_HEADER,
			OL_TXN_PSP_DETAIL,
			OL_TXN_ELEMENTS,
			OL_BANK_ACCT_ID,
			DEF_VIEW_TXNCODE_MAP,
			(SELECT OSTP_TXN_ID,
				OSTP_STMT_TXN_ID,
				OBT_STAT_TXN_ID,
				OLSD_STATEMENT_REF
			   FROM OL_STMT_TXN_RELATION, OL_BAID_TXN, OL_STATEMENT_DETAIL
			  WHERE OSTP_STMT_TXN_ID = OBT_TXN_ID
			    AND OBT_STAT_TXN_ID = OLSD_STAT_TXN_ID) t_stmt,
			TXN_CODE
		WHERE	OTH_TXN_CODE = VTM_TXN_CODE
		  AND	OTH_STATUS = OTH_STATUS
		  AND	OTH_AR_IND = :hv_ar_ind
		  AND	OTH_APPROVAL_DATE >= :hv_date
		  AND	VTM_VIEW_TYPE = 'FROZEN_FUND_TXN'
		  AND	OTH_TXN_ID = t_stmt.ostp_txn_id(+)
		  AND	OTH_TXN_ID = OTP_TXN_ID
		  AND	OTH_TXN_ID = OTE_TXN_ID
		  AND	OTP_BAID = OBAI_BAID
		  AND	OTH_TXN_CODE = TC_CODE
		  AND	NOT EXISTS ( SELECT NULL FROM TMP_FROZEN_TXN_ALERT t WHERE t.TFA_TXN_ID = OTH_TXN_ID )
		ORDER BY
			oth_approval_timestamp; */ 

		
	/* EXEC SQL OPEN c_cursor_getinfo; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "SELECT oth_txn_id , olsd_statement_ref , tc_desc , ( select opd_psp_name\
 from OL_PSP_DETAIL where OTP_PSP_ID = OPD_PSP_ID ) , obai_baid_name , oth_n\
et_ccy , oth_transaction_amount , ote_amt_type , to_char ( oth_approval_time\
stamp , 'MM/DD/YYYY HH24:MI' ) approval_ts , oth_create_user , to_char ( oth\
_approval_timestamp , 'YYYY/MM/DD' ) approval_date FROM OL_TXN_HEADER , OL_T\
XN_PSP_DETAIL , OL_TXN_ELEMENTS , OL_BANK_ACCT_ID , DEF_VIEW_TXNCODE_MAP , (\
 SELECT OSTP_TXN_ID , OSTP_STMT_TXN_ID , OBT_STAT_TXN_ID , OLSD_STATEMENT_RE\
F FROM OL_STMT_TXN_RELATION , OL_BAID_TXN , OL_STATEMENT_DETAIL WHERE OSTP_S\
TMT_TXN_ID = OBT_TXN_ID AND OBT_STAT_TXN_ID = OLSD_STAT_TXN_ID ) t_stmt , TX\
N_CODE WHERE OTH_TXN_CODE = VTM_TXN_CODE AND OTH_STATUS = OTH_STATUS AND OTH\
_AR_IND = :b0 AND OTH_APPROVAL_DATE >= :b1 AND VTM_VIEW_TYPE = 'FROZEN_FUND_\
TXN' AND OTH_TXN_ID = t_stmt . ostp_txn_id ( + ) AND OTH_TXN_ID = OTP_TXN_ID\
 AND OTH_TXN_ID = OTE_TXN_ID AND OTP_BAID = OBAI_BAID AND OTH_TXN_CODE = TC_\
CODE AND NOT EXISTS ( SELECT NULL FROM T");
 sqlstm.stmt = sq0001;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_ar_ind;
 sqlstm.sqhstl[0] = (unsigned long )1;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
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
			:v_txn_id:ind_txn_id,
			:v_bank_stmt_id:ind_bank_stmt_id,
			:v_txn_type:ind_txn_type,
			:v_pid:ind_pid,
			:v_baid:ind_baid,
			:v_txn_ccy:ind_txn_ccy,
			:v_txn_amt:ind_txn_amt,
			:v_cr_dr:ind_cr_dr,
			:v_approval_ts:ind_approval_ts,
			:v_create_user:ind_create_user,
			:v_approval_date:ind_approval_date; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 11;
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
  sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_txn_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_bank_stmt_id;
  sqlstm.sqhstl[1] = (unsigned long )19;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_bank_stmt_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_type;
  sqlstm.sqhstl[2] = (unsigned long )53;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_txn_type;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_pid;
  sqlstm.sqhstl[3] = (unsigned long )53;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_pid;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_baid;
  sqlstm.sqhstl[4] = (unsigned long )153;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_baid;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_txn_ccy;
  sqlstm.sqhstl[5] = (unsigned long )6;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_txn_ccy;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_txn_amt;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_txn_amt;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_cr_dr;
  sqlstm.sqhstl[7] = (unsigned long )5;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_cr_dr;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_approval_ts;
  sqlstm.sqhstl[8] = (unsigned long )23;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_approval_ts;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_create_user;
  sqlstm.sqhstl[9] = (unsigned long )23;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_create_user;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_approval_date;
  sqlstm.sqhstl[10] = (unsigned long )53;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_approval_date;
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
			if (iCnt == 0) {
DEBUGLOG(("No data found!\n"));
			}
			break;
		}

		/*
		if (ind_approval_date >= 0) {
			sprintf(csTmp,"%.*s",v_approval_date.len,v_approval_date.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,"G_APPROVAL_DATE","GLO","STR",csTmp);
		}
		*/

		if (ind_txn_id >= 0) {
			sprintf(csTag,"ftxn_id-%d",iCnt);
			sprintf(csTxnId,"%.*s",v_txn_id.len,v_txn_id.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","stbl_body-0",csTxnId);
		}

		if (ind_bank_stmt_id >= 0) {
			sprintf(csTag,"fbank_stmt_id-%d",iCnt);
			sprintf(csTmp,"%.*s",v_bank_stmt_id.len,v_bank_stmt_id.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","stbl_body-0",csTmp);
		} else {
			sprintf(csTag,"fbank_stmt_id-%d",iCnt);
			sprintf(csTmp," ");
			iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","stbl_body-0",csTmp);
		}

		if (ind_txn_type >= 0) {
			sprintf(csTag,"ftxn_type-%d",iCnt);
			sprintf(csTmp,"%.*s",v_txn_type.len,v_txn_type.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","stbl_body-0",csTmp);
		}

		if (ind_pid >= 0) {
			sprintf(csTag,"fpid-%d",iCnt);
			sprintf(csTmp,"%.*s",v_pid.len,v_pid.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","stbl_body-0",csTmp);
		}

		if (ind_baid >= 0) {
			sprintf(csTag,"fbaid-%d",iCnt);
			sprintf(csTmp,"%.*s",v_baid.len,v_baid.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","stbl_body-0",csTmp);
		}

		if (ind_txn_ccy >= 0) {
			sprintf(csTag,"ftxn_ccy-%d",iCnt);
			sprintf(csTmp,"%.*s",v_txn_ccy.len,v_txn_ccy.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","stbl_body-0",csTmp);
		}

		if (ind_txn_amt >= 0) {
			sprintf(csTag,"ftxn_amt-%d",iCnt);
			iDynCnt = set_tpl_dyn_double(hContext,iDynCnt,csTag,"DOU","stbl_body-0",v_txn_amt);
		}

		if (ind_cr_dr >= 0) {
			sprintf(csTag,"fcr_dr-%d",iCnt);
			sprintf(csTmp,"%.*s",v_cr_dr.len,v_cr_dr.arr);
			if (!strcmp(csTmp,PD_CR))
				sprintf(csTmp,"%s","Credit");
			else if (!strcmp(csTmp,PD_DR))
				sprintf(csTmp,"%s","Debit");
			iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","stbl_body-0",csTmp);
		}

		if (ind_approval_ts >= 0) {
			sprintf(csTag,"fapproval_ts-%d",iCnt);
			sprintf(csTmp,"%.*s",v_approval_ts.len,v_approval_ts.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","stbl_body-0",csTmp);
		}

		if (ind_create_user >= 0) {
			sprintf(csTag,"fcreate_user-%d",iCnt);
			sprintf(csTmp,"%.*s",v_create_user.len,v_create_user.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","stbl_body-0",csTmp);
		}

		iCnt++;

		PutField_CString(hTmpFrozenTxnAlert,"txn_seq",csTxnId);

		DBObjPtr = CreateObj(DBObjPtr,"DBTmpFrozenTxnAlert","Add");
		iRet = (unsigned long)((*DBObjPtr)(hTmpFrozenTxnAlert));
		if (iRet!=PD_OK) {
DEBUGLOG(("Call DBTmpFrozenTxnAlert::Add FAILED!\n"));
ERRLOG("check_frozen_fund_txn_alert Call DBTmpFrozenTxnAlert::Add FAILED\n");
		} else {
DEBUGLOG(("Call DBTmpFrozenTxnAlert::Add [%s] Success\n",csTxnId));
		}
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
 sqlstm.offset = (unsigned int  )87;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto sql_error;
}



	if (iCnt > 0) {
		iDynCnt = set_tpl_dyn_int(hContext, iDynCnt, "stbl_head-0", "SEC", "stbl_head-0", 0);
		iDynCnt = set_tpl_dyn_int(hContext, iDynCnt, "stbl_body-0", "SEC", "stbl_body-0", iCnt);

		/*
		sprintf(csTmp, "Frozen Fund Arrangement Email Notification");
		iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,"MAIL_SUBJECT","GLO","STR",csTmp);
		*/

		PutField_CString(hContext,"source","BATCH");
		PutField_CString(hContext,"funct","FROZEN_FUND_TXN");
		PutField_Char(hContext,"party_type",'G');
		PutField_CString(hContext,"party_id","000");

		PutField_Int(hContext,"total_dyn",iDynCnt);

		BOObjPtr = CreateObj(BOPtr,"BOAlertEmail","ProcessTpl");
		if((unsigned long)((*BOObjPtr)(hContext) != PD_OK)){
			iRet=INT_CODE_ERROR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("BOAlertEmail:ProcessTpl Failed\n"));
ERRLOG("check_frozen_fund_txn_alert BOAlertEmail::ProcessTpl Failed, iRet=%d\n", iRet);
		}
		else
		{
DEBUGLOG(("BOAlertEmail:ProcessTpl Success\n"));
		}
	}

DEBUGLOG(("check_frozen_fund_txn_alert normal exit!\n"));

	FREE_ME(hContext);
	FREE_ME(hTmpFrozenTxnAlert);

	return iRet;

sql_error:
DEBUGLOG(("check_frozen_fund_txn_alert error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getinfo; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 11;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )102;
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
    sqlstm.offset = (unsigned int  )117;
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
	strcpy(csDate,"");

        if (argc < 2) {
                return PD_ERR;
        }
        while ((c = getopt(argc,argv,"d:")) != EOF) {
                switch (c) {
                        case 'd':
                                strcpy(csDate,optarg);
                                break;
                        default:
                                return PD_ERR;
                }
        }

	if (!strcmp(csDate,""))
		return FAILURE;

        return SUCCESS;
}
