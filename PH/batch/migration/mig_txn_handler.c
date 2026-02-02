
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
    "mig_txn_handler.pc"
};


static unsigned int sqlctx = 20137723;


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
   unsigned char  *sqhstv[26];
   unsigned long  sqhstl[26];
            int   sqhsts[26];
            short *sqindv[26];
            int   sqinds[26];
   unsigned long  sqharm[26];
   unsigned long  *sqharc[26];
   unsigned short  sqadto[26];
   unsigned short  sqtdso[26];
} sqlstm = {12,26};

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
5,0,0,0,0,0,56,223,0,0,1,1,0,1,0,3,102,0,0,
24,0,0,1,138,0,6,234,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,2,102,0,0,
55,0,0,0,0,0,13,278,0,0,26,1,0,1,0,1,102,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,
174,0,0,0,0,0,15,496,0,0,1,1,0,1,0,1,102,0,0,
193,0,0,0,0,0,78,497,0,0,1,1,0,1,0,3,102,0,0,
212,0,0,0,0,0,15,501,0,0,1,1,0,1,0,1,102,0,0,
231,0,0,0,0,0,78,502,0,0,1,1,0,1,0,3,102,0,0,
250,0,0,0,0,0,15,524,0,0,1,1,0,1,0,1,102,0,0,
269,0,0,0,0,0,78,525,0,0,1,1,0,1,0,3,102,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/03/12              Virginia Yun
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include "../batchcommon.h"
#include "common.h"
#include "utilitys.h"
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"
#include "mig_txn_handler.h"
#include "ObjPtr.h"
#include "dbutility.h"

#include "mig_funct.h" 
#include "mig_deposit_handler.h"
#include "mig_adjustment_handler.h"
#include "mig_deposit_reserved_handler.h"
#include "mig_payout_handler.h"
#include "mig_payout_reversal_handler.h"
#include "mig_settlement_handler.h"

/*
#include "pr_bo_funct.h"
#include "pr_par_funct.h"
*/



#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define	PD_MY_DELIMITOR	","
#define	PD_MY_TOKEN	'"'

/*
#define	PD_MY_QS_TOEKN	'	'
#define	PD_MY_QE_TOEKN	'	'
#define	PD_MY_DAY_TOKEN	"-"
*/

#define	PD_CHAR		0x0D

/*
OBJPTR(DB);
OBJPTR(Txn);
OBJPTR(Channel);
OBJPTR(BO);
*/

char    cDebug;


char    cs_inputfile[PD_MAX_FILE_LEN + 1];
char	cs_process_id[PD_TMP_BUF_LEN + 1];
int	i_process_id = -1;
char	cs_file_date[PD_DATE_LEN + 1];

char	cOATEnv;
char	cChkMigPeriod;

int start_process();
int parse_txn(hash_t *hMyHash);
int parse_arg(int argc,char **argv);

int batch_init(int argc, char* argv[])
{
	if (argc < 1) {
		printf("usage: -d process_date -p process_id (0=ALL)\n");
		return FAILURE;
	} else {
		return SUCCESS;
	}

        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int	iRet = SUCCESS;
	
	/**/
        char	csOATEnv[PD_SP_VALUE_LEN + 1];
	/**/
	char	csChkMigPeriod[PD_SP_VALUE_LEN + 1];


	iRet = parse_arg(argc, argv);

	if (iRet == SUCCESS) {
		/**/
		if (mf_DefMisc_GetValue(MIG_OAT_ENV, csOATEnv) == FOUND) {
			cOATEnv = csOATEnv[0];
DEBUGLOG(("batch_proc OAT_Env = [%c]\n", cOATEnv));
		} else {
DEBUGLOG(("batch_proc: ParDefMisc_GetValue FAIL (OAT_ENV)!!\n"));
			iRet = FAILURE;
		}
		/**/

		if (mf_DefMisc_GetValue(MIG_CHK_MIG_PERIOD, csChkMigPeriod) == FOUND) {
			cChkMigPeriod = csChkMigPeriod[0];
DEBUGLOG(("batch_proc ChkMigPeriod = [%c]\n", cChkMigPeriod));
		} else {
DEBUGLOG(("batch_proc: ParDefMisc_GetValue FAIL (CHK_MIG_PERIOD)!!\n"));
			iRet = FAILURE;
		}
	}

	if (iRet == SUCCESS) {
		iRet = start_process();
	}

	return iRet;

}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


                        
int start_process() 
{
	int	iRet = SUCCESS;

	char	csDate[PD_DATE_LEN + 1];
	char	csDateTime[PD_DATE_LEN + PD_TIME_LEN + 1];
	char	csTmp[MIG_TXN_NOTE_LEN + 1];
	
	int	iCnt;
	hash_t	*myHash;

	myHash = (hash_t*) malloc (sizeof(hash_t));


        /* EXEC SQL WHENEVER SQLERROR GOTO get_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                SQL_CURSOR      c_cursor_txn_data;

		short		hv_return_value;

		/* varchar		hv_file_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } hv_file_date;

		int		hv_process_id;

		short		ind_file_date = -1;
		short		ind_process_id = -1;


		int		v_txn_seq;
		/* varchar		v_post_date[PD_DATE_LEN + PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_post_date;

		/* varchar		v_txn_date[MIG_TXN_DATETIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[22]; } v_txn_date;

		/* varchar		v_txn_merch_nmb[MIG_TXN_MERCH_NMB_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_merch_nmb;

		/* varchar		v_txn_nmb[MIG_TXN_NMB_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_nmb;

		/* varchar		v_merch_ref[PD_MERCHANT_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merch_ref;

		/* varchar		v_txn_type[MIG_TXN_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_type;

		/* varchar		v_txn_status[MIG_TXN_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_status;

		/* varchar		v_txn_status_grp[MIG_TXN_STATUS_GRP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_status_grp;

		/* varchar		v_to_ccy[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_to_ccy;

		double		v_to_amount;
		/* varchar		v_ccy[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ccy;

		double		v_amount;
		double		v_fee;
		double		v_ex_rate;
		double		v_markup_amt;
		/* varchar		v_psp_type_code[MIG_PSP_TYPE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_type_code;

		/* varchar		v_psp_order_id[MIG_PSP_TYPE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_order_id;

		/* varchar		v_gate_id[MIG_GATE_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_gate_id;

		/* varchar		v_client_ip[MIG_CLIENT_IP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_client_ip;

		/* varchar		v_txn_note[MIG_TXN_NOTE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[401]; } v_txn_note;

		/* varchar		v_psp_txn_id[MIG_PSP_TXN_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_psp_txn_id;

		/* varchar		v_psp_txn_date[MIG_PSP_TXN_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_psp_txn_date;

		/* varchar		v_mobile_nmb[PD_CUSTOMER_TEL_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_mobile_nmb;

		/* varchar		v_user_agent[PD_REMARK_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_user_agent;


		short		ind_txn_seq = -1;
		short		ind_post_date = -1;
		short		ind_txn_date = -1;
		short		ind_txn_merch_nmb = -1;
		short		ind_txn_nmb = -1;
		short		ind_merch_ref = -1;
		short		ind_txn_type = -1;
		short		ind_txn_status = -1;
		short		ind_txn_status_grp = -1;
		short		ind_to_ccy = -1;
		short		ind_to_amount = -1;
		short		ind_ccy = -1;
		short		ind_amount = -1;
		short		ind_fee = -1;
		short		ind_ex_rate = -1;
		short		ind_markup_amt = -1;
		short		ind_psp_type_code = -1;
		short		ind_psp_order_id = -1;
		short		ind_gate_id = -1;
		short		ind_client_ip = -1;
		short		ind_txn_note = -1;
		short		ind_psp_txn_id = -1;
		short		ind_psp_txn_date = -1;
		short		ind_mobile_nmb = -1;
		short		ind_user_agent = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	/* EXEC SQL ALLOCATE :c_cursor_txn_data; */ 

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
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_txn_data;
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
 if (sqlca.sqlcode < 0) goto get_error;
}



	hv_file_date.len = strlen(cs_file_date);
	memcpy(hv_file_date.arr, cs_file_date, hv_file_date.len);
	ind_file_date = 0;
DEBUGLOG(("file_date = [%.*s]\n", hv_file_date.len, hv_file_date.arr));

	hv_process_id = i_process_id;
	ind_process_id = 0;
DEBUGLOG(("process_id = [%d]\n", i_process_id));

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_par_mig_txn_data(:hv_file_date:ind_file_date, 
                                                                :hv_process_id:ind_process_id, 
                                                                :c_cursor_txn_data);	
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_par_mig_txn_data ( :hv_file_da\
te:ind_file_date , :hv_process_id:ind_process_id , :c_cursor_txn_data ) ; END\
 ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_file_date;
 sqlstm.sqhstl[1] = (unsigned long )11;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_file_date;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_process_id;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_process_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&c_cursor_txn_data;
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
 if (sqlca.sqlcode < 0) goto get_error;
}



	if (hv_return_value == 1) {
DEBUGLOG(("start_process:get_txn no more record to be processed!\n"));
	}
	else if (hv_return_value == SP_OK) {
		iCnt = 0;

                for (;;) {
			hash_init(myHash,0);

			ind_txn_seq = -1;
			ind_post_date = -1;
			ind_txn_date = -1;
			ind_txn_merch_nmb = -1;
			ind_txn_nmb = -1;
			ind_merch_ref = -1;
			ind_txn_type = -1;
			ind_txn_status = -1;
			ind_txn_status_grp = -1;
			ind_to_ccy = -1;
			ind_to_amount = -1;
			ind_ccy = -1;
			ind_amount = -1;
			ind_fee = -1;
			ind_ex_rate = -1;
			ind_markup_amt = -1;
			ind_psp_type_code = -1;
			ind_psp_order_id = -1;
			ind_gate_id = -1;
			ind_client_ip = -1;
			ind_txn_note = -1;
			ind_psp_txn_id = -1;
			ind_psp_txn_date = -1;
			ind_mobile_nmb = -1;
			ind_user_agent= -1;
	
			/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_txn_data		
			INTO	:v_txn_seq:ind_txn_seq,
				:v_post_date:ind_post_date,
				:v_txn_date:ind_txn_date,
				:v_txn_merch_nmb:ind_txn_merch_nmb,
		  		:v_txn_nmb:ind_txn_nmb,
				:v_merch_ref:ind_merch_ref,
				:v_txn_type:ind_txn_type,
				:v_txn_status:ind_txn_status,
				:v_txn_status_grp:ind_txn_status_grp,
				:v_to_ccy:ind_to_ccy,
				:v_to_amount:ind_to_amount,
				:v_ccy:ind_ccy,
				:v_amount:ind_amount,
				:v_fee:ind_fee,
				:v_ex_rate:ind_ex_rate,
				:v_markup_amt:ind_markup_amt,
				:v_psp_type_code:ind_psp_type_code,
				:v_psp_order_id:ind_psp_order_id,
				:v_gate_id:ind_gate_id,
				:v_client_ip:ind_client_ip,
				:v_txn_note:ind_txn_note,
				:v_psp_txn_id:ind_psp_txn_id,
				:v_psp_txn_date:ind_psp_txn_date,
				:v_mobile_nmb:ind_mobile_nmb,
				:v_user_agent:ind_user_agent 
			; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 26;
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
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_txn_data;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_seq;
                        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_txn_seq;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_post_date;
                        sqlstm.sqhstl[2] = (unsigned long )17;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_post_date;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_date;
                        sqlstm.sqhstl[3] = (unsigned long )24;
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_txn_date;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_txn_merch_nmb;
                        sqlstm.sqhstl[4] = (unsigned long )53;
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_txn_merch_nmb;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_txn_nmb;
                        sqlstm.sqhstl[5] = (unsigned long )19;
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_txn_nmb;
                        sqlstm.sqinds[5] = (         int  )0;
                        sqlstm.sqharm[5] = (unsigned long )0;
                        sqlstm.sqadto[5] = (unsigned short )0;
                        sqlstm.sqtdso[5] = (unsigned short )0;
                        sqlstm.sqhstv[6] = (unsigned char  *)&v_merch_ref;
                        sqlstm.sqhstl[6] = (unsigned long )53;
                        sqlstm.sqhsts[6] = (         int  )0;
                        sqlstm.sqindv[6] = (         short *)&ind_merch_ref;
                        sqlstm.sqinds[6] = (         int  )0;
                        sqlstm.sqharm[6] = (unsigned long )0;
                        sqlstm.sqadto[6] = (unsigned short )0;
                        sqlstm.sqtdso[6] = (unsigned short )0;
                        sqlstm.sqhstv[7] = (unsigned char  *)&v_txn_type;
                        sqlstm.sqhstl[7] = (unsigned long )53;
                        sqlstm.sqhsts[7] = (         int  )0;
                        sqlstm.sqindv[7] = (         short *)&ind_txn_type;
                        sqlstm.sqinds[7] = (         int  )0;
                        sqlstm.sqharm[7] = (unsigned long )0;
                        sqlstm.sqadto[7] = (unsigned short )0;
                        sqlstm.sqtdso[7] = (unsigned short )0;
                        sqlstm.sqhstv[8] = (unsigned char  *)&v_txn_status;
                        sqlstm.sqhstl[8] = (unsigned long )53;
                        sqlstm.sqhsts[8] = (         int  )0;
                        sqlstm.sqindv[8] = (         short *)&ind_txn_status;
                        sqlstm.sqinds[8] = (         int  )0;
                        sqlstm.sqharm[8] = (unsigned long )0;
                        sqlstm.sqadto[8] = (unsigned short )0;
                        sqlstm.sqtdso[8] = (unsigned short )0;
                        sqlstm.sqhstv[9] = (unsigned char  *)&v_txn_status_grp;
                        sqlstm.sqhstl[9] = (unsigned long )53;
                        sqlstm.sqhsts[9] = (         int  )0;
                        sqlstm.sqindv[9] = (         short *)&ind_txn_status_grp;
                        sqlstm.sqinds[9] = (         int  )0;
                        sqlstm.sqharm[9] = (unsigned long )0;
                        sqlstm.sqadto[9] = (unsigned short )0;
                        sqlstm.sqtdso[9] = (unsigned short )0;
                        sqlstm.sqhstv[10] = (unsigned char  *)&v_to_ccy;
                        sqlstm.sqhstl[10] = (unsigned long )6;
                        sqlstm.sqhsts[10] = (         int  )0;
                        sqlstm.sqindv[10] = (         short *)&ind_to_ccy;
                        sqlstm.sqinds[10] = (         int  )0;
                        sqlstm.sqharm[10] = (unsigned long )0;
                        sqlstm.sqadto[10] = (unsigned short )0;
                        sqlstm.sqtdso[10] = (unsigned short )0;
                        sqlstm.sqhstv[11] = (unsigned char  *)&v_to_amount;
                        sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[11] = (         int  )0;
                        sqlstm.sqindv[11] = (         short *)&ind_to_amount;
                        sqlstm.sqinds[11] = (         int  )0;
                        sqlstm.sqharm[11] = (unsigned long )0;
                        sqlstm.sqadto[11] = (unsigned short )0;
                        sqlstm.sqtdso[11] = (unsigned short )0;
                        sqlstm.sqhstv[12] = (unsigned char  *)&v_ccy;
                        sqlstm.sqhstl[12] = (unsigned long )6;
                        sqlstm.sqhsts[12] = (         int  )0;
                        sqlstm.sqindv[12] = (         short *)&ind_ccy;
                        sqlstm.sqinds[12] = (         int  )0;
                        sqlstm.sqharm[12] = (unsigned long )0;
                        sqlstm.sqadto[12] = (unsigned short )0;
                        sqlstm.sqtdso[12] = (unsigned short )0;
                        sqlstm.sqhstv[13] = (unsigned char  *)&v_amount;
                        sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[13] = (         int  )0;
                        sqlstm.sqindv[13] = (         short *)&ind_amount;
                        sqlstm.sqinds[13] = (         int  )0;
                        sqlstm.sqharm[13] = (unsigned long )0;
                        sqlstm.sqadto[13] = (unsigned short )0;
                        sqlstm.sqtdso[13] = (unsigned short )0;
                        sqlstm.sqhstv[14] = (unsigned char  *)&v_fee;
                        sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[14] = (         int  )0;
                        sqlstm.sqindv[14] = (         short *)&ind_fee;
                        sqlstm.sqinds[14] = (         int  )0;
                        sqlstm.sqharm[14] = (unsigned long )0;
                        sqlstm.sqadto[14] = (unsigned short )0;
                        sqlstm.sqtdso[14] = (unsigned short )0;
                        sqlstm.sqhstv[15] = (unsigned char  *)&v_ex_rate;
                        sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[15] = (         int  )0;
                        sqlstm.sqindv[15] = (         short *)&ind_ex_rate;
                        sqlstm.sqinds[15] = (         int  )0;
                        sqlstm.sqharm[15] = (unsigned long )0;
                        sqlstm.sqadto[15] = (unsigned short )0;
                        sqlstm.sqtdso[15] = (unsigned short )0;
                        sqlstm.sqhstv[16] = (unsigned char  *)&v_markup_amt;
                        sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[16] = (         int  )0;
                        sqlstm.sqindv[16] = (         short *)&ind_markup_amt;
                        sqlstm.sqinds[16] = (         int  )0;
                        sqlstm.sqharm[16] = (unsigned long )0;
                        sqlstm.sqadto[16] = (unsigned short )0;
                        sqlstm.sqtdso[16] = (unsigned short )0;
                        sqlstm.sqhstv[17] = (unsigned char  *)&v_psp_type_code;
                        sqlstm.sqhstl[17] = (unsigned long )53;
                        sqlstm.sqhsts[17] = (         int  )0;
                        sqlstm.sqindv[17] = (         short *)&ind_psp_type_code;
                        sqlstm.sqinds[17] = (         int  )0;
                        sqlstm.sqharm[17] = (unsigned long )0;
                        sqlstm.sqadto[17] = (unsigned short )0;
                        sqlstm.sqtdso[17] = (unsigned short )0;
                        sqlstm.sqhstv[18] = (unsigned char  *)&v_psp_order_id;
                        sqlstm.sqhstl[18] = (unsigned long )53;
                        sqlstm.sqhsts[18] = (         int  )0;
                        sqlstm.sqindv[18] = (         short *)&ind_psp_order_id;
                        sqlstm.sqinds[18] = (         int  )0;
                        sqlstm.sqharm[18] = (unsigned long )0;
                        sqlstm.sqadto[18] = (unsigned short )0;
                        sqlstm.sqtdso[18] = (unsigned short )0;
                        sqlstm.sqhstv[19] = (unsigned char  *)&v_gate_id;
                        sqlstm.sqhstl[19] = (unsigned long )53;
                        sqlstm.sqhsts[19] = (         int  )0;
                        sqlstm.sqindv[19] = (         short *)&ind_gate_id;
                        sqlstm.sqinds[19] = (         int  )0;
                        sqlstm.sqharm[19] = (unsigned long )0;
                        sqlstm.sqadto[19] = (unsigned short )0;
                        sqlstm.sqtdso[19] = (unsigned short )0;
                        sqlstm.sqhstv[20] = (unsigned char  *)&v_client_ip;
                        sqlstm.sqhstl[20] = (unsigned long )103;
                        sqlstm.sqhsts[20] = (         int  )0;
                        sqlstm.sqindv[20] = (         short *)&ind_client_ip;
                        sqlstm.sqinds[20] = (         int  )0;
                        sqlstm.sqharm[20] = (unsigned long )0;
                        sqlstm.sqadto[20] = (unsigned short )0;
                        sqlstm.sqtdso[20] = (unsigned short )0;
                        sqlstm.sqhstv[21] = (unsigned char  *)&v_txn_note;
                        sqlstm.sqhstl[21] = (unsigned long )403;
                        sqlstm.sqhsts[21] = (         int  )0;
                        sqlstm.sqindv[21] = (         short *)&ind_txn_note;
                        sqlstm.sqinds[21] = (         int  )0;
                        sqlstm.sqharm[21] = (unsigned long )0;
                        sqlstm.sqadto[21] = (unsigned short )0;
                        sqlstm.sqtdso[21] = (unsigned short )0;
                        sqlstm.sqhstv[22] = (unsigned char  *)&v_psp_txn_id;
                        sqlstm.sqhstl[22] = (unsigned long )33;
                        sqlstm.sqhsts[22] = (         int  )0;
                        sqlstm.sqindv[22] = (         short *)&ind_psp_txn_id;
                        sqlstm.sqinds[22] = (         int  )0;
                        sqlstm.sqharm[22] = (unsigned long )0;
                        sqlstm.sqadto[22] = (unsigned short )0;
                        sqlstm.sqtdso[22] = (unsigned short )0;
                        sqlstm.sqhstv[23] = (unsigned char  *)&v_psp_txn_date;
                        sqlstm.sqhstl[23] = (unsigned long )17;
                        sqlstm.sqhsts[23] = (         int  )0;
                        sqlstm.sqindv[23] = (         short *)&ind_psp_txn_date;
                        sqlstm.sqinds[23] = (         int  )0;
                        sqlstm.sqharm[23] = (unsigned long )0;
                        sqlstm.sqadto[23] = (unsigned short )0;
                        sqlstm.sqtdso[23] = (unsigned short )0;
                        sqlstm.sqhstv[24] = (unsigned char  *)&v_mobile_nmb;
                        sqlstm.sqhstl[24] = (unsigned long )23;
                        sqlstm.sqhsts[24] = (         int  )0;
                        sqlstm.sqindv[24] = (         short *)&ind_mobile_nmb;
                        sqlstm.sqinds[24] = (         int  )0;
                        sqlstm.sqharm[24] = (unsigned long )0;
                        sqlstm.sqadto[24] = (unsigned short )0;
                        sqlstm.sqtdso[24] = (unsigned short )0;
                        sqlstm.sqhstv[25] = (unsigned char  *)&v_user_agent;
                        sqlstm.sqhstl[25] = (unsigned long )258;
                        sqlstm.sqhsts[25] = (         int  )0;
                        sqlstm.sqindv[25] = (         short *)&ind_user_agent;
                        sqlstm.sqinds[25] = (         int  )0;
                        sqlstm.sqharm[25] = (unsigned long )0;
                        sqlstm.sqadto[25] = (unsigned short )0;
                        sqlstm.sqtdso[25] = (unsigned short )0;
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
                        if (sqlca.sqlcode < 0) goto get_error;
}



                        if (SQLCODE == SQL_NOT_FOUND) {
                                break;
                        }

DEBUGLOG(("start_process >>>>>>>>>>>>>>>>>>>>>>>>>\n"));

			if (ind_txn_seq >= 0) {
DEBUGLOG(("start_process: [%d] sort_txn_seq = [%d]\n", iCnt, v_txn_seq));
				PutField_Int(myHash, "sort_txn_seq", v_txn_seq);
			}

			if (ind_post_date >= 0) {
				v_post_date.arr[v_post_date.len] = '\0';
//DEBUGLOG(("start_process: [%d] post_date = [%.*s]\n",iCnt, v_post_date.len,v_post_date.arr));
	
				strncpy(csDate, (const char *)v_post_date.arr, PD_DATE_LEN);
				csDate[PD_DATE_LEN] = '\0';
//DEBUGLOG(("start_process: [%d] re-format post_date = [%s]\n",iCnt, csDate));

				PutField_CString(myHash, "post_date", (const char *) csDate);
				PutField_CString(myHash, "post_datetime", (const char*)v_post_date.arr);
			}
			

			if (ind_txn_date >= 0) {
				v_txn_date.arr[v_txn_date.len] = '\0';
DEBUGLOG(("start_process: [%d] txn_date = [%.*s]\n",iCnt, v_txn_date.len,v_txn_date.arr));

				strncpy(csDate, (const char*) v_txn_date.arr, PD_DATE_LEN);
				csDate[PD_DATE_LEN] = '\0';

				strncpy(csDateTime, (const char *)v_txn_date.arr, PD_DATE_LEN + PD_TIME_LEN);
				csDateTime[PD_DATE_LEN + PD_TIME_LEN] = '\0';

//DEBUGLOG(("start_process: [%d] re-format txn_date [%s] txn_date_time = [%s]\n",iCnt, csDate, csDateTime));

				PutField_CString(myHash, "txn_date", (const char*) csDate);
				PutField_CString(myHash, "txn_datetime", (const char*) csDateTime);
				PutField_CString(myHash, "txn_datetimestamp", (const char *) v_txn_date.arr);

			}

			if (ind_txn_merch_nmb >= 0) {
				v_txn_merch_nmb.arr[v_txn_merch_nmb.len] = '\0';
DEBUGLOG(("start_process: [%d] txn_merch_nmb = [%.*s]\n",iCnt, v_txn_merch_nmb.len,v_txn_merch_nmb.arr));
				PutField_CString(myHash, "txn_merch_nmb", (const char *) v_txn_merch_nmb.arr);
			}

			if (ind_txn_nmb >= 0) {
				v_txn_nmb.arr[v_txn_nmb.len] = '\0';
DEBUGLOG(("start_process: [%d] txn_nmb = [%.*s]\n",iCnt, v_txn_nmb.len,v_txn_nmb.arr));
				PutField_CString(myHash, "txn_nmb", (const char *) v_txn_nmb.arr);
			}

			if (ind_merch_ref >=0) {
				v_merch_ref.arr[v_merch_ref.len] = '\0';
//DEBUGLOG(("start_process: [%d] merch_ref = [%.*s]\n",iCnt, v_merch_ref.len, v_merch_ref.arr));
				PutField_CString(myHash, "merch_ref", (const char *) v_merch_ref.arr);
			}
		
			if (ind_txn_type >=0) {
				v_txn_type.arr[v_txn_type.len] = '\0';
DEBUGLOG(("start_process: [%d] txn_type = [%.*s]\n",iCnt, v_txn_type.len, v_txn_type.arr));
				PutField_CString(myHash, "txn_type", (const char *) v_txn_type.arr);
			}

			if (ind_txn_status >=0) {
				v_txn_status.arr[v_txn_status.len] = '\0';
DEBUGLOG(("start_process: [%d] txn_status = [%.*s]\n",iCnt, v_txn_status.len, v_txn_status.arr));
				PutField_CString(myHash, "txn_status", (const char *) v_txn_status.arr);
			}

			if (ind_txn_status_grp >=0) {
				v_txn_status_grp.arr[v_txn_status_grp.len] = '\0';
//DEBUGLOG(("start_process: [%d] txn_status_grp = [%.*s]\n",iCnt, v_txn_status_grp.len, v_txn_status_grp.arr));
				PutField_CString(myHash, "txn_status_grp", (const char *) v_txn_status_grp.arr);
			}

			if (ind_to_ccy >=0) {
				v_to_ccy.arr[v_to_ccy.len] = '\0';
//DEBUGLOG(("start_process: [%d] to_ccy = [%.*s]\n",iCnt, v_to_ccy.len, v_to_ccy.arr));
				PutField_CString(myHash, "to_ccy", (const char *) v_to_ccy.arr);
			}

			if (ind_to_amount >=0) {
//DEBUGLOG(("start_process: [%d] to_amount = [%lf]\n",iCnt, v_to_amount));
				PutField_Double(myHash, "to_amount", v_to_amount);
			}

			if (ind_ccy >=0) {
				v_ccy.arr[v_ccy.len] = '\0';
//DEBUGLOG(("start_process: [%d] ccy = [%.*s]\n",iCnt, v_ccy.len, v_ccy.arr));
				PutField_CString(myHash, "ccy", (const char *) v_ccy.arr);
			}

			if (ind_amount >=0) {
//DEBUGLOG(("start_process: [%d] amount = [%lf]\n",iCnt, v_amount));
				PutField_Double(myHash, "amount", v_amount);
			}

			if (ind_fee >=0) {
//DEBUGLOG(("start_process: [%d] fee = [%lf]\n",iCnt, v_fee));
				PutField_Double(myHash, "fee", v_fee);
			}

			if (ind_ex_rate >= 0) {
//DEBUGLOG(("start_process: [%d] ex_rate = [%lf]\n",iCnt, v_ex_rate));
				PutField_Double(myHash, "ex_rate", v_ex_rate);
			}

			if (ind_markup_amt >= 0) {
//DEBUGLOG(("start_process: [%d] markup_amt = [%lf]\n",iCnt, v_markup_amt));
				PutField_Double(myHash, "markup_amt", v_markup_amt);
			}


			if (ind_psp_type_code >= 0) {
				v_psp_type_code.arr[v_psp_type_code.len] = '\0';
DEBUGLOG(("start_process: [%d] psp_type_code = [%.*s]\n",iCnt, v_psp_type_code.len, v_psp_type_code.arr));
				PutField_CString(myHash, "psp_type_code", (const char *) v_psp_type_code.arr);
			}
		
			if (ind_psp_order_id >= 0) {
				v_psp_order_id.arr[v_psp_order_id.len] = '\0';
//DEBUGLOG(("start_process: [%d] psp_order_id = [%.*s]\n",iCnt, v_psp_order_id.len, v_psp_order_id.arr));
				PutField_CString(myHash, "psp_order_id", (const char *) v_psp_order_id.arr);
			}

			if (ind_gate_id >= 0) {
				v_gate_id.arr[v_gate_id.len] = '\0';
DEBUGLOG(("start_process: [%d] gate_id = [%.*s]\n",iCnt, v_gate_id.len, v_gate_id.arr));
				PutField_CString(myHash, "gate_id", (const char *) v_gate_id.arr);
			}
			
			if (ind_client_ip >= 0) {
				v_client_ip.arr[v_client_ip.len] = '\0';
//DEBUGLOG(("start_process: [%d] client_ip = [%.*s]\n",iCnt, v_client_ip.len, v_client_ip.arr));
				PutField_CString(myHash, "client_ip", (const char *) v_client_ip.arr);
			}	

			if (ind_txn_note >= 0) {
				v_txn_note.arr[v_txn_note.len] = '\0';
//DEBUGLOG(("start_process: [%d] txn_note = [%.*s]\n",iCnt, v_txn_note.len, v_txn_note.arr));
				strncpy(csTmp, (const char *) v_txn_note.arr, PD_REMARK_LEN);
				csTmp[PD_REMARK_LEN] = '\0';
	
				PutField_CString(myHash, "remark", (const char *) csTmp);
			}	
			
			if (ind_psp_txn_id >= 0) {
				v_psp_txn_id.arr[v_psp_txn_id.len] = '\0';
//DEBUGLOG(("start_process: [%d] psp_txn_id = [%.*s]\n",iCnt, v_psp_txn_id.len, v_psp_txn_id.arr));
				PutField_CString(myHash, "psp_tid", (const char *) v_psp_txn_id.arr);
			}	

			if (ind_psp_txn_date >= 0) {
				v_psp_txn_date.arr[v_psp_txn_date.len] = '\0';
//DEBUGLOG(("start_process: [%d] psp_txn_date = [%.*s]\n",iCnt, v_psp_txn_date.len, v_psp_txn_date.arr));

				PutField_CString(myHash, "psp_txn_datetime", (const char *) v_psp_txn_date.arr);

				strncpy(csDate, (const char *)v_psp_txn_date.arr, PD_DATE_LEN);
				csDate[PD_DATE_LEN] = '\0';

				PutField_CString(myHash, "psp_txn_date", (const char *) csDate);
			}	

			if (ind_mobile_nmb >= 0) {
				v_mobile_nmb.arr[v_mobile_nmb.len] = '\0';
//DEBUGLOG(("start_process: [%d] mobile_nmb = [%.*s]\n",iCnt, v_mobile_nmb.len, v_mobile_nmb.arr));
				PutField_CString(myHash, "mobile_nmb", (const char *) v_mobile_nmb.arr);
			}

			if (ind_user_agent >= 0) {
				v_user_agent.arr[v_user_agent.len] = '\0';
//DEBUGLOG(("start_process: [%d] user_agenet= [%.*s]\n",iCnt, v_user_agent.len, v_user_agent.arr));
				PutField_CString(myHash, "user_agent", (const char *) v_user_agent.arr);
			}


			iRet=parse_txn(myHash);
			if (iRet != SUCCESS) {
				break;
			}

			iCnt++;

			hash_destroy(myHash);
	
		}
		/* EXEC SQL CLOSE :c_cursor_txn_data; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 26;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )174;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_txn_data;
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
  if (sqlca.sqlcode < 0) goto get_error;
}


 	        /* EXEC SQL FREE :c_cursor_txn_data; */ 

{
          struct sqlexd sqlstm;
          sqlstm.sqlvsn = 12;
          sqlstm.arrsiz = 26;
          sqlstm.sqladtp = &sqladt;
          sqlstm.sqltdsp = &sqltds;
          sqlstm.stmt = "";
          sqlstm.iters = (unsigned int  )1;
          sqlstm.offset = (unsigned int  )193;
          sqlstm.cud = sqlcud0;
          sqlstm.sqlest = (unsigned char  *)&sqlca;
          sqlstm.sqlety = (unsigned short)4352;
          sqlstm.occurs = (unsigned int  )0;
          sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_txn_data;
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
          if (sqlca.sqlcode < 0) goto get_error;
}

 


	} else if (hv_return_value == SP_OTHER_ERR) {
		/* EXEC SQL CLOSE :c_cursor_txn_data; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 26;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )212;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_txn_data;
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
  if (sqlca.sqlcode < 0) goto get_error;
}


                /* EXEC SQL FREE :c_cursor_txn_data; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 26;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )231;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_txn_data;
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
                if (sqlca.sqlcode < 0) goto get_error;
}


DEBUGLOG(("start_process: exit with error\n"));
ERRLOG("start_process: exit with error\n");
                iRet = FAILURE;
	
	}
	
	//EXEC SQL CLOSE :c_cursor_txn_data;
        //EXEC SQL FREE :c_cursor_txn_data;
DEBUGLOG(("start_process: FINAL RET = [%d]\n", iRet));

	FREE_ME(myHash);


	return iRet;

get_error:
DEBUGLOG(("get_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));

ERRLOG("start_process: error_code %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE :c_cursor_txn_data; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 26;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )250;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_txn_data;
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


    /* EXEC SQL FREE :c_cursor_txn_data; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 26;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )269;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_txn_data;
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


    FREE_ME(myHash);

    return PD_ERR;
}


int parse_txn (hash_t *hMyHash) {

	int 	iRet=SUCCESS;
	int	iTmpRet;

	char	*csTxnStatus;
	char	*csTmp;
	char	*csPreTxnType = NULL;
	char	*csCategory = NULL; 

	char	csDate[PD_DATE_LEN + 1];
	char	csTime[PD_TIME_LEN + 1];

	//char	csAutoRecon[PD_SP_VALUE_LEN + 1];
	//char	cTmp;

	char	*csMerchNmb;
	char	*csTxnDate;

	int	iMigPeriod = PD_FALSE;

	
DEBUGLOG(("parse_txn: BEGIN\n"));
	// Check need to process

	if (cChkMigPeriod == PD_YES) {
		GetField_CString(hMyHash, "txn_merch_nmb", &csMerchNmb);
		GetField_CString(hMyHash, "txn_date", &csTxnDate);

		iTmpRet = mf_ChkValidMigPeriod(csMerchNmb, csTxnDate);

		if (iTmpRet == PD_FOUND) {
DEBUGLOG(("MerchNmb [%s] TxnDate [%s] in migration period!\n", csMerchNmb, csTxnDate));
			iMigPeriod = PD_TRUE;
		}
		else if (iTmpRet == PD_NOT_FOUND) {
DEBUGLOG(("MerchNmb [%s] TxnDate [%s] NOT in migration period, ignore!\n", csMerchNmb, csTxnDate));
			iMigPeriod = PD_FALSE;
			
		} else {
DEBUGLOG(("Error on mf_ChkValidMigPeriod...\n"));
			iRet = FAILURE;
		}
	
	}

	if (iRet == SUCCESS) {
		if (iMigPeriod == PD_FALSE) {
			iRet = mf_UpdateProcessResult(hMyHash, "NOT_MIG");
		}  else {
//DEBUGLOG(("In Migration Period and start..\n"));
			GetField_CString(hMyHash, "txn_status", &csTxnStatus);

			if (strcmp(csTxnStatus, "NEW") == 0) {
DEBUGLOG(("parse_txn: NEW case --> skip\n"));
				iRet = mf_UpdateProcessResult(hMyHash, "NEW-SKIP");
			} else {

				//GetField_CString(hMyHash, "txn_datetime", &csTmp);
				GetField_CString(hMyHash, "post_datetime", &csTmp);

				strncpy(csDate, csTmp, PD_DATE_LEN);
				csDate[PD_DATE_LEN] = '\0';
				strncpy(csTime, csTmp + PD_DATE_LEN, PD_TIME_LEN);
				csTime[PD_TIME_LEN] = '\0';

//DEBUGLOG(("parse_txn: Txn Date [%s] Txn Time [%s]\n", csDate, csTime));

       		 		PutField_CString(hMyHash, "local_tm_date", csDate);
		        	PutField_CString(hMyHash, "local_tm_time", csTime);

				/*
				if (mf_DefMisc_GetValue(MIG_AUTO_RECON, csAutoRecon) == FOUND) {
					cTmp = csAutoRecon[0];
DEBUGLOG(("parse_txn: Auto_recon [%c]\n", cTmp));
					PutField_Char(hMyHash, "auto_recon", cTmp);
				} else {
DEBUGLOG(("parse_txn: ParDefMisc_GetValue FAIL (Auto-Recon)!!\n"));
					iRet = FAILURE;
				}
				*/
				PutField_Char(hMyHash, "auto_recon", PD_YES);

				if (iRet == SUCCESS) {
					if (GetField_CString(hMyHash, "txn_type", &csPreTxnType)) {
//DEBUGLOG(("parse_txn: txn_type [%s]\n", csPreTxnType));
						if (mf_Category_GetCategory(csPreTxnType, hMyHash) == PD_OK) {

							if (GetField_CString(hMyHash, "category", &csCategory)) {
DEBUGLOG(("parse_txn: category [%s]\n", csCategory));
							}
							if (GetField_CString(hMyHash, "txn_code", &csTmp)) {
DEBUGLOG(("parse_txn: txn_code [%s]\n", csTmp));
							}
							if (GetField_CString(hMyHash, "reversal_txn_code", &csTmp)) {
DEBUGLOG(("parse_txn: reversal_txn_code [%s]\n", csTmp));
							}
							if (GetField_CString(hMyHash, "reversal_fee_txn_code", &csTmp)) {
DEBUGLOG(("parse_txn: reversal_fee_txn_code [%s]\n", csTmp));
							}
						}
						else {
DEBUGLOG(("parse_txn: ParCategory:GetCategory FAIL!\n"));
							iRet = FAILURE;
						}
					}
				}

				/* No need to replace  PID*/
				if (iRet == SUCCESS) {
					if (cOATEnv == PD_YES) {
						char *csPSPTypeCode;

						if (GetField_CString(hMyHash, "psp_type_code", &csPSPTypeCode)) {
							if (!strcmp(csPSPTypeCode, "PROCHUB")) {
								PutField_CString(hMyHash, "psp_type_code", "PROCHUB");
DEBUGLOG(("parse_txn: Assign PROCHUB to replace [%s]\n", csPSPTypeCode));
							} else if (!strcmp(csPSPTypeCode, "PROCHUB_51EPAY0412")) {
								PutField_CString(hMyHash, "psp_type_code", "PROCHUB_51EPAY0412");
DEBUGLOG(("parse_txn: Assign PROCHUB_51EPAY0412 to replace [%s]\n", csPSPTypeCode));

							} else {
								PutField_CString(hMyHash, "psp_type_code", "HAIPAY2202");
DEBUGLOG(("parse_txn: Assign HAIPAY2202 to replace [%s]\n", csPSPTypeCode));
							}
						}
					}
				}
				/**/


				if (iRet == SUCCESS) {
//DEBUGLOG(("will do Category [%s]\n", csCategory));
					if (!strcmp(csCategory, MIG_CAT_DEPOSIT)) {
						iRet = mig_deposit_handler(hMyHash);
					}	 
					else if (!strcmp(csCategory, MIG_CAT_ADJUSTEMENT)) {
						iRet = mig_adjustment_handler(hMyHash);
					}
					else if (!strcmp(csCategory, MIG_CAT_RESERVE)) {
						iRet = mig_deposit_reserved_handler(hMyHash);
					}
					else if (!strcmp(csCategory, MIG_CAT_PAYOUT)) {
						iRet = mig_payout_handler(hMyHash);
					} 
					else if (!strcmp(csCategory, MIG_CAT_PAYOUT_REVERSAL)) {
						iRet = mig_payout_reversal_handler(hMyHash);
					} 
					else if (!strcmp(csCategory, MIG_CAT_SETTLEMENT)) {
						iRet = mig_settlement_handler(hMyHash);
					} 
					else {
DEBUGLOG(("parse_txn: not defined category [%s]\n", csCategory));
						iRet = FAILURE;
					}
				}
			}
		}
	}

	if (iRet == SUCCESS) {
		TxnCommit();
	}
	else {
ERRLOG("mig_txn_handler error.....\n");
		TxnAbort();
	}


	return iRet;
}


int parse_arg(int argc,char **argv)
{
        char    c;

        strcpy(cs_process_id, "");

        while ((c = getopt(argc,argv,"d:p:")) != EOF) {
                switch (c) {
			case 'd':
				strcpy(cs_file_date, optarg);
				break;
                        case 'p':
                                strcpy(cs_process_id, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_file_date, "") || !strcmp(cs_process_id,"")) {
                return FAILURE;
        } else {

                i_process_id = atoi(cs_process_id);
DEBUGLOG(("process_id [%d]\n", i_process_id));

                if (i_process_id < 0) {
                        return FAILURE;
                }

        }

        return SUCCESS;
}
