
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
    "PayoutApproveTmp.pc"
};


static unsigned int sqlctx = 40587947;


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
   unsigned char  *sqhstv[39];
   unsigned long  sqhstl[39];
            int   sqhsts[39];
            short *sqindv[39];
            int   sqinds[39];
   unsigned long  sqharm[39];
   unsigned long  *sqharc[39];
   unsigned short  sqadto[39];
   unsigned short  sqtdso[39];
} sqlstm = {12,39};

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

 static char *sq0002 = 
"select uh_batch_id from payout_approve_tmp , merchant_upload_file_header , \
merchant_upload_file_detail where pt_id = :b0 and pt_txn_id = ud_txn_id and u\
d_batch_id = uh_batch_id group by uh_batch_id            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,0,0,0,56,146,0,0,1,1,0,1,0,3,102,0,0,
24,0,0,1,145,0,6,148,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,2,102,0,0,
55,0,0,0,0,0,13,204,0,0,39,1,0,1,0,1,102,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,
0,2,4,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,
0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,
226,0,0,0,0,0,15,507,0,0,1,1,0,1,0,1,102,0,0,
245,0,0,0,0,0,78,508,0,0,1,1,0,1,0,3,102,0,0,
264,0,0,0,0,0,15,518,0,0,1,1,0,1,0,1,102,0,0,
283,0,0,0,0,0,78,519,0,0,1,1,0,1,0,3,102,0,0,
302,0,0,2,209,0,9,561,0,2049,1,1,0,1,0,1,9,0,0,
321,0,0,2,0,0,13,563,0,0,1,0,0,1,0,2,9,0,0,
340,0,0,2,0,0,15,583,0,0,0,0,0,1,0,
355,0,0,2,0,0,15,596,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/04/30              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "PayoutApproveTmp.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "internal.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void PayoutApproveTmp(char    cdebug)
{
        cDebug = cdebug;
}

int GetDetailBySelectedTxn(const hash_t *hTxn, recordset_t* myRec)
{
	hash_t *myHash;
	char	*csTmp;
	int	iTmp;
	int	iRet = PD_NOT_FOUND;

	/* EXEC SQL WHENEVER SQLERROR GOTO getdt_con_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		short           hv_return_value;

		/* varchar		hv_tmp_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_tmp_batch_id;

		int		hv_status;
		
		SQL_CURSOR      c_cursor_dtcon;

		/* varchar		v_batch_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_batch_id;

		int	        v_seq_num;
		/* varchar		v_merchant_id[PD_MERCHANT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar		v_service_code[PD_SERVICE_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		/* varchar		v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar         v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar		v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		/* varchar         v_identity_id[PD_IDENTITY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_identity_id;

		/* varchar         v_account_num[PD_AC_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_num;

		/* varchar         v_account_name[PD_ACC_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_account_name;

		/* varchar         v_bank_name[PD_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

		/* varchar         v_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

		/* varchar         v_branch[PD_BANK_BRANCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch;

		/* varchar		v_phone_num[PD_MOBILE_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_phone_num;

		/* varchar         v_province[PD_PROVINCE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_province;

		/* varchar		v_city[PD_CITY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_city;

		/* varchar		v_payout_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_payout_ccy;

		/* varchar		v_request_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_request_ccy;

		/* varchar		v_member_fee_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_member_fee_ccy;

		/* varchar		v_merchant_fee_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_merchant_fee_ccy;

		/* varchar		v_markup_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_markup_ccy;

		double		v_payout_amount;
		double		v_request_amount;
		double		v_member_fee;
		double		v_merchant_fee;
		double		v_markup_amt;
		double		v_ex_rate;
		int		v_status;
		/* varchar		v_resp_code[PD_RESPONSE_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_resp_code;

		/* varchar		v_remark[PD_REMARK_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;

		char		v_batch_mode;
		/* varchar		v_file_name[PD_FILENAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_file_name;

		/* varchar		v_psp_batch_id[PD_BATCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_psp_batch_id;

		/* varchar		v_fundout_date[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_fundout_date;

		/* varchar		v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		double		v_service_fee;
		/* varchar		v_file_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_file_id;

		int	        v_approve_id;


		short           ind_batch_id = -1;
		short           ind_seq_num = -1;
		short           ind_merchant_id = -1;
		short           ind_service_code = -1;
		short           ind_txn_id = -1;
		short           ind_merchant_ref = -1;
		short		ind_country = -1;
		short		ind_identity_id = -1;
		short           ind_account_num = -1;
		short           ind_account_name = -1;
		short           ind_bank_name = -1;
		short           ind_bank_code = -1;
		short		ind_branch = -1;
		short           ind_phone_num = -1;
		short		ind_province = -1;
		short		ind_city = -1;
		short		ind_payout_ccy = -1;
		short		ind_request_ccy = -1;
		short           ind_member_fee_ccy = -1;
		short           ind_merchant_fee_ccy = -1;
		short           ind_markup_ccy = -1;
		short           ind_payout_amount = -1;
		short           ind_request_amount = -1;
		short           ind_member_fee = -1;
		short		ind_merchant_fee = -1;
		short           ind_markup_amt = -1;
		short		ind_ex_rate = -1;
		short		ind_status = -1;
		short		ind_resp_code = -1;
		short           ind_remark = -1;
		short		ind_batch_mode;
		short           ind_file_name = -1;
		short           ind_psp_batch_id = -1;
		short           ind_psp_id = -1;
		short           ind_fundout_date = -1;
		short           ind_service_fee = -1;
		short           ind_file_id = -1;
		short           ind_approve_id = -1;

		short           ind_tmp_batch_id= -1;
		short           ind_in_status= -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	if(GetField_CString(hTxn,"tmp_batch_id",&csTmp)){
        	hv_tmp_batch_id.len = strlen(csTmp);
        	memcpy(hv_tmp_batch_id.arr,csTmp,hv_tmp_batch_id.len);
DEBUGLOG(("GetDetailBySelectedTxn tmp_batch_id = [%.*s]\n",hv_tmp_batch_id.len,hv_tmp_batch_id.arr));
		ind_tmp_batch_id= 0;
	}

	if(GetField_Int(hTxn,"status",&iTmp)){
        	hv_status= iTmp;
DEBUGLOG(("GetDetailBySelectedTxn status = [%d]\n",hv_status));
		ind_in_status= 0;
	}

	/* EXEC SQL ALLOCATE       :c_cursor_dtcon; */ 

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
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dtcon;
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
 if (sqlca.sqlcode < 0) goto getdt_con_error;
}



        	/* EXEC SQL EXECUTE
                	BEGIN
                        	:hv_return_value := sp_payout_approve_tmp_dt_get(
								:hv_tmp_batch_id:ind_tmp_batch_id,
								:hv_status:ind_in_status,
								:c_cursor_dtcon);
                	END;
        	END-EXEC; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 4;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.stmt = "begin :hv_return_value := sp_payout_approve_tmp_dt_\
get ( :hv_tmp_batch_id:ind_tmp_batch_id , :hv_status:ind_in_status , :c_curso\
r_dtcon ) ; END ;";
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
         sqlstm.sqhstv[1] = (unsigned char  *)&hv_tmp_batch_id;
         sqlstm.sqhstl[1] = (unsigned long )18;
         sqlstm.sqhsts[1] = (         int  )0;
         sqlstm.sqindv[1] = (         short *)&ind_tmp_batch_id;
         sqlstm.sqinds[1] = (         int  )0;
         sqlstm.sqharm[1] = (unsigned long )0;
         sqlstm.sqadto[1] = (unsigned short )0;
         sqlstm.sqtdso[1] = (unsigned short )0;
         sqlstm.sqhstv[2] = (unsigned char  *)&hv_status;
         sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
         sqlstm.sqhsts[2] = (         int  )0;
         sqlstm.sqindv[2] = (         short *)&ind_in_status;
         sqlstm.sqinds[2] = (         int  )0;
         sqlstm.sqharm[2] = (unsigned long )0;
         sqlstm.sqadto[2] = (unsigned short )0;
         sqlstm.sqtdso[2] = (unsigned short )0;
         sqlstm.sqhstv[3] = (unsigned char  *)&c_cursor_dtcon;
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
         if (sqlca.sqlcode < 0) goto getdt_con_error;
}



	if (hv_return_value > 0)  {
DEBUGLOG(("Find Found\n"));
		iRet = PD_FOUND;
                for (;;) {
                        myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);

			ind_batch_id = -1;
			ind_seq_num = -1;
			ind_merchant_id = -1;
			ind_service_code= -1;
			ind_txn_id = -1;
			ind_merchant_ref = -1;
			ind_country = -1;
			ind_identity_id = -1;
			ind_account_num = -1;
			ind_account_name = -1;
			ind_bank_name = -1;
			ind_bank_code = -1;
			ind_branch = -1;
			ind_phone_num = -1;
			ind_province = -1;
			ind_city = -1;
			ind_payout_ccy = -1;
			ind_request_ccy = -1;
			ind_member_fee_ccy = -1;
			ind_merchant_fee_ccy = -1;
			ind_markup_ccy = -1;
			ind_payout_amount = -1;
			ind_request_amount = -1;
			ind_member_fee = -1;
			ind_merchant_fee = -1;
			ind_markup_amt = -1;
			ind_ex_rate = -1;
			ind_status = -1;
			ind_resp_code = -1;
			ind_remark = -1;
			ind_batch_mode = -1;
			ind_file_name = -1;
			ind_psp_batch_id = -1;
			ind_psp_id = -1;
			ind_fundout_date = -1;
			ind_service_fee = -1;
			ind_file_id = -1;
			ind_approve_id = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_dtcon
                        INTO
				:v_batch_id:ind_batch_id,
				:v_seq_num:ind_seq_num,
				:v_txn_id:ind_txn_id,
				:v_merchant_ref:ind_merchant_ref,
				:v_country:ind_country,
				:v_identity_id:ind_identity_id,
				:v_account_num:ind_account_num,
				:v_account_name:ind_account_name,
				:v_bank_name:ind_bank_name,
				:v_bank_code:ind_bank_code,
				:v_branch:ind_branch,
				:v_phone_num:ind_phone_num,
				:v_province:ind_province,
				:v_city:ind_city,
				:v_payout_amount:ind_payout_amount,
				:v_request_amount:ind_request_amount,
				:v_payout_ccy:ind_payout_ccy,
				:v_request_ccy:ind_request_ccy,
				:v_member_fee_ccy:ind_member_fee_ccy,
				:v_member_fee:ind_member_fee,
				:v_merchant_fee_ccy:ind_merchant_fee_ccy,
				:v_merchant_fee:ind_merchant_fee,
				:v_markup_ccy:ind_markup_ccy,
				:v_markup_amt:ind_markup_amt,
				:v_ex_rate:ind_ex_rate,
				:v_status:ind_status,
				:v_resp_code:ind_resp_code,
				:v_remark:ind_remark,
				:v_batch_mode:ind_batch_mode,
				:v_file_name:ind_file_name,
				:v_psp_batch_id:ind_psp_batch_id,
				:v_fundout_date:ind_fundout_date,
				:v_service_fee:ind_service_fee,
				:v_psp_id:ind_psp_id,
				:v_file_id:ind_file_id,
				:v_approve_id:ind_approve_id,
				:v_merchant_id:ind_merchant_id,
				:v_service_code:ind_service_code; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 39;
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
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dtcon;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_batch_id;
                        sqlstm.sqhstl[1] = (unsigned long )19;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_batch_id;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_seq_num;
                        sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_seq_num;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_id;
                        sqlstm.sqhstl[3] = (unsigned long )19;
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_txn_id;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_merchant_ref;
                        sqlstm.sqhstl[4] = (unsigned long )53;
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_merchant_ref;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_country;
                        sqlstm.sqhstl[5] = (unsigned long )5;
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_country;
                        sqlstm.sqinds[5] = (         int  )0;
                        sqlstm.sqharm[5] = (unsigned long )0;
                        sqlstm.sqadto[5] = (unsigned short )0;
                        sqlstm.sqtdso[5] = (unsigned short )0;
                        sqlstm.sqhstv[6] = (unsigned char  *)&v_identity_id;
                        sqlstm.sqhstl[6] = (unsigned long )28;
                        sqlstm.sqhsts[6] = (         int  )0;
                        sqlstm.sqindv[6] = (         short *)&ind_identity_id;
                        sqlstm.sqinds[6] = (         int  )0;
                        sqlstm.sqharm[6] = (unsigned long )0;
                        sqlstm.sqadto[6] = (unsigned short )0;
                        sqlstm.sqtdso[6] = (unsigned short )0;
                        sqlstm.sqhstv[7] = (unsigned char  *)&v_account_num;
                        sqlstm.sqhstl[7] = (unsigned long )28;
                        sqlstm.sqhsts[7] = (         int  )0;
                        sqlstm.sqindv[7] = (         short *)&ind_account_num;
                        sqlstm.sqinds[7] = (         int  )0;
                        sqlstm.sqharm[7] = (unsigned long )0;
                        sqlstm.sqadto[7] = (unsigned short )0;
                        sqlstm.sqtdso[7] = (unsigned short )0;
                        sqlstm.sqhstv[8] = (unsigned char  *)&v_account_name;
                        sqlstm.sqhstl[8] = (unsigned long )103;
                        sqlstm.sqhsts[8] = (         int  )0;
                        sqlstm.sqindv[8] = (         short *)&ind_account_name;
                        sqlstm.sqinds[8] = (         int  )0;
                        sqlstm.sqharm[8] = (unsigned long )0;
                        sqlstm.sqadto[8] = (unsigned short )0;
                        sqlstm.sqtdso[8] = (unsigned short )0;
                        sqlstm.sqhstv[9] = (unsigned char  *)&v_bank_name;
                        sqlstm.sqhstl[9] = (unsigned long )153;
                        sqlstm.sqhsts[9] = (         int  )0;
                        sqlstm.sqindv[9] = (         short *)&ind_bank_name;
                        sqlstm.sqinds[9] = (         int  )0;
                        sqlstm.sqharm[9] = (unsigned long )0;
                        sqlstm.sqadto[9] = (unsigned short )0;
                        sqlstm.sqtdso[9] = (unsigned short )0;
                        sqlstm.sqhstv[10] = (unsigned char  *)&v_bank_code;
                        sqlstm.sqhstl[10] = (unsigned long )13;
                        sqlstm.sqhsts[10] = (         int  )0;
                        sqlstm.sqindv[10] = (         short *)&ind_bank_code;
                        sqlstm.sqinds[10] = (         int  )0;
                        sqlstm.sqharm[10] = (unsigned long )0;
                        sqlstm.sqadto[10] = (unsigned short )0;
                        sqlstm.sqtdso[10] = (unsigned short )0;
                        sqlstm.sqhstv[11] = (unsigned char  *)&v_branch;
                        sqlstm.sqhstl[11] = (unsigned long )153;
                        sqlstm.sqhsts[11] = (         int  )0;
                        sqlstm.sqindv[11] = (         short *)&ind_branch;
                        sqlstm.sqinds[11] = (         int  )0;
                        sqlstm.sqharm[11] = (unsigned long )0;
                        sqlstm.sqadto[11] = (unsigned short )0;
                        sqlstm.sqtdso[11] = (unsigned short )0;
                        sqlstm.sqhstv[12] = (unsigned char  *)&v_phone_num;
                        sqlstm.sqhstl[12] = (unsigned long )28;
                        sqlstm.sqhsts[12] = (         int  )0;
                        sqlstm.sqindv[12] = (         short *)&ind_phone_num;
                        sqlstm.sqinds[12] = (         int  )0;
                        sqlstm.sqharm[12] = (unsigned long )0;
                        sqlstm.sqadto[12] = (unsigned short )0;
                        sqlstm.sqtdso[12] = (unsigned short )0;
                        sqlstm.sqhstv[13] = (unsigned char  *)&v_province;
                        sqlstm.sqhstl[13] = (unsigned long )103;
                        sqlstm.sqhsts[13] = (         int  )0;
                        sqlstm.sqindv[13] = (         short *)&ind_province;
                        sqlstm.sqinds[13] = (         int  )0;
                        sqlstm.sqharm[13] = (unsigned long )0;
                        sqlstm.sqadto[13] = (unsigned short )0;
                        sqlstm.sqtdso[13] = (unsigned short )0;
                        sqlstm.sqhstv[14] = (unsigned char  *)&v_city;
                        sqlstm.sqhstl[14] = (unsigned long )103;
                        sqlstm.sqhsts[14] = (         int  )0;
                        sqlstm.sqindv[14] = (         short *)&ind_city;
                        sqlstm.sqinds[14] = (         int  )0;
                        sqlstm.sqharm[14] = (unsigned long )0;
                        sqlstm.sqadto[14] = (unsigned short )0;
                        sqlstm.sqtdso[14] = (unsigned short )0;
                        sqlstm.sqhstv[15] = (unsigned char  *)&v_payout_amount;
                        sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[15] = (         int  )0;
                        sqlstm.sqindv[15] = (         short *)&ind_payout_amount;
                        sqlstm.sqinds[15] = (         int  )0;
                        sqlstm.sqharm[15] = (unsigned long )0;
                        sqlstm.sqadto[15] = (unsigned short )0;
                        sqlstm.sqtdso[15] = (unsigned short )0;
                        sqlstm.sqhstv[16] = (unsigned char  *)&v_request_amount;
                        sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[16] = (         int  )0;
                        sqlstm.sqindv[16] = (         short *)&ind_request_amount;
                        sqlstm.sqinds[16] = (         int  )0;
                        sqlstm.sqharm[16] = (unsigned long )0;
                        sqlstm.sqadto[16] = (unsigned short )0;
                        sqlstm.sqtdso[16] = (unsigned short )0;
                        sqlstm.sqhstv[17] = (unsigned char  *)&v_payout_ccy;
                        sqlstm.sqhstl[17] = (unsigned long )6;
                        sqlstm.sqhsts[17] = (         int  )0;
                        sqlstm.sqindv[17] = (         short *)&ind_payout_ccy;
                        sqlstm.sqinds[17] = (         int  )0;
                        sqlstm.sqharm[17] = (unsigned long )0;
                        sqlstm.sqadto[17] = (unsigned short )0;
                        sqlstm.sqtdso[17] = (unsigned short )0;
                        sqlstm.sqhstv[18] = (unsigned char  *)&v_request_ccy;
                        sqlstm.sqhstl[18] = (unsigned long )6;
                        sqlstm.sqhsts[18] = (         int  )0;
                        sqlstm.sqindv[18] = (         short *)&ind_request_ccy;
                        sqlstm.sqinds[18] = (         int  )0;
                        sqlstm.sqharm[18] = (unsigned long )0;
                        sqlstm.sqadto[18] = (unsigned short )0;
                        sqlstm.sqtdso[18] = (unsigned short )0;
                        sqlstm.sqhstv[19] = (unsigned char  *)&v_member_fee_ccy;
                        sqlstm.sqhstl[19] = (unsigned long )6;
                        sqlstm.sqhsts[19] = (         int  )0;
                        sqlstm.sqindv[19] = (         short *)&ind_member_fee_ccy;
                        sqlstm.sqinds[19] = (         int  )0;
                        sqlstm.sqharm[19] = (unsigned long )0;
                        sqlstm.sqadto[19] = (unsigned short )0;
                        sqlstm.sqtdso[19] = (unsigned short )0;
                        sqlstm.sqhstv[20] = (unsigned char  *)&v_member_fee;
                        sqlstm.sqhstl[20] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[20] = (         int  )0;
                        sqlstm.sqindv[20] = (         short *)&ind_member_fee;
                        sqlstm.sqinds[20] = (         int  )0;
                        sqlstm.sqharm[20] = (unsigned long )0;
                        sqlstm.sqadto[20] = (unsigned short )0;
                        sqlstm.sqtdso[20] = (unsigned short )0;
                        sqlstm.sqhstv[21] = (unsigned char  *)&v_merchant_fee_ccy;
                        sqlstm.sqhstl[21] = (unsigned long )6;
                        sqlstm.sqhsts[21] = (         int  )0;
                        sqlstm.sqindv[21] = (         short *)&ind_merchant_fee_ccy;
                        sqlstm.sqinds[21] = (         int  )0;
                        sqlstm.sqharm[21] = (unsigned long )0;
                        sqlstm.sqadto[21] = (unsigned short )0;
                        sqlstm.sqtdso[21] = (unsigned short )0;
                        sqlstm.sqhstv[22] = (unsigned char  *)&v_merchant_fee;
                        sqlstm.sqhstl[22] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[22] = (         int  )0;
                        sqlstm.sqindv[22] = (         short *)&ind_merchant_fee;
                        sqlstm.sqinds[22] = (         int  )0;
                        sqlstm.sqharm[22] = (unsigned long )0;
                        sqlstm.sqadto[22] = (unsigned short )0;
                        sqlstm.sqtdso[22] = (unsigned short )0;
                        sqlstm.sqhstv[23] = (unsigned char  *)&v_markup_ccy;
                        sqlstm.sqhstl[23] = (unsigned long )6;
                        sqlstm.sqhsts[23] = (         int  )0;
                        sqlstm.sqindv[23] = (         short *)&ind_markup_ccy;
                        sqlstm.sqinds[23] = (         int  )0;
                        sqlstm.sqharm[23] = (unsigned long )0;
                        sqlstm.sqadto[23] = (unsigned short )0;
                        sqlstm.sqtdso[23] = (unsigned short )0;
                        sqlstm.sqhstv[24] = (unsigned char  *)&v_markup_amt;
                        sqlstm.sqhstl[24] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[24] = (         int  )0;
                        sqlstm.sqindv[24] = (         short *)&ind_markup_amt;
                        sqlstm.sqinds[24] = (         int  )0;
                        sqlstm.sqharm[24] = (unsigned long )0;
                        sqlstm.sqadto[24] = (unsigned short )0;
                        sqlstm.sqtdso[24] = (unsigned short )0;
                        sqlstm.sqhstv[25] = (unsigned char  *)&v_ex_rate;
                        sqlstm.sqhstl[25] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[25] = (         int  )0;
                        sqlstm.sqindv[25] = (         short *)&ind_ex_rate;
                        sqlstm.sqinds[25] = (         int  )0;
                        sqlstm.sqharm[25] = (unsigned long )0;
                        sqlstm.sqadto[25] = (unsigned short )0;
                        sqlstm.sqtdso[25] = (unsigned short )0;
                        sqlstm.sqhstv[26] = (unsigned char  *)&v_status;
                        sqlstm.sqhstl[26] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[26] = (         int  )0;
                        sqlstm.sqindv[26] = (         short *)&ind_status;
                        sqlstm.sqinds[26] = (         int  )0;
                        sqlstm.sqharm[26] = (unsigned long )0;
                        sqlstm.sqadto[26] = (unsigned short )0;
                        sqlstm.sqtdso[26] = (unsigned short )0;
                        sqlstm.sqhstv[27] = (unsigned char  *)&v_resp_code;
                        sqlstm.sqhstl[27] = (unsigned long )13;
                        sqlstm.sqhsts[27] = (         int  )0;
                        sqlstm.sqindv[27] = (         short *)&ind_resp_code;
                        sqlstm.sqinds[27] = (         int  )0;
                        sqlstm.sqharm[27] = (unsigned long )0;
                        sqlstm.sqadto[27] = (unsigned short )0;
                        sqlstm.sqtdso[27] = (unsigned short )0;
                        sqlstm.sqhstv[28] = (unsigned char  *)&v_remark;
                        sqlstm.sqhstl[28] = (unsigned long )258;
                        sqlstm.sqhsts[28] = (         int  )0;
                        sqlstm.sqindv[28] = (         short *)&ind_remark;
                        sqlstm.sqinds[28] = (         int  )0;
                        sqlstm.sqharm[28] = (unsigned long )0;
                        sqlstm.sqadto[28] = (unsigned short )0;
                        sqlstm.sqtdso[28] = (unsigned short )0;
                        sqlstm.sqhstv[29] = (unsigned char  *)&v_batch_mode;
                        sqlstm.sqhstl[29] = (unsigned long )1;
                        sqlstm.sqhsts[29] = (         int  )0;
                        sqlstm.sqindv[29] = (         short *)&ind_batch_mode;
                        sqlstm.sqinds[29] = (         int  )0;
                        sqlstm.sqharm[29] = (unsigned long )0;
                        sqlstm.sqadto[29] = (unsigned short )0;
                        sqlstm.sqtdso[29] = (unsigned short )0;
                        sqlstm.sqhstv[30] = (unsigned char  *)&v_file_name;
                        sqlstm.sqhstl[30] = (unsigned long )53;
                        sqlstm.sqhsts[30] = (         int  )0;
                        sqlstm.sqindv[30] = (         short *)&ind_file_name;
                        sqlstm.sqinds[30] = (         int  )0;
                        sqlstm.sqharm[30] = (unsigned long )0;
                        sqlstm.sqadto[30] = (unsigned short )0;
                        sqlstm.sqtdso[30] = (unsigned short )0;
                        sqlstm.sqhstv[31] = (unsigned char  *)&v_psp_batch_id;
                        sqlstm.sqhstl[31] = (unsigned long )23;
                        sqlstm.sqhsts[31] = (         int  )0;
                        sqlstm.sqindv[31] = (         short *)&ind_psp_batch_id;
                        sqlstm.sqinds[31] = (         int  )0;
                        sqlstm.sqharm[31] = (unsigned long )0;
                        sqlstm.sqadto[31] = (unsigned short )0;
                        sqlstm.sqtdso[31] = (unsigned short )0;
                        sqlstm.sqhstv[32] = (unsigned char  *)&v_fundout_date;
                        sqlstm.sqhstl[32] = (unsigned long )17;
                        sqlstm.sqhsts[32] = (         int  )0;
                        sqlstm.sqindv[32] = (         short *)&ind_fundout_date;
                        sqlstm.sqinds[32] = (         int  )0;
                        sqlstm.sqharm[32] = (unsigned long )0;
                        sqlstm.sqadto[32] = (unsigned short )0;
                        sqlstm.sqtdso[32] = (unsigned short )0;
                        sqlstm.sqhstv[33] = (unsigned char  *)&v_service_fee;
                        sqlstm.sqhstl[33] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[33] = (         int  )0;
                        sqlstm.sqindv[33] = (         short *)&ind_service_fee;
                        sqlstm.sqinds[33] = (         int  )0;
                        sqlstm.sqharm[33] = (unsigned long )0;
                        sqlstm.sqadto[33] = (unsigned short )0;
                        sqlstm.sqtdso[33] = (unsigned short )0;
                        sqlstm.sqhstv[34] = (unsigned char  *)&v_psp_id;
                        sqlstm.sqhstl[34] = (unsigned long )13;
                        sqlstm.sqhsts[34] = (         int  )0;
                        sqlstm.sqindv[34] = (         short *)&ind_psp_id;
                        sqlstm.sqinds[34] = (         int  )0;
                        sqlstm.sqharm[34] = (unsigned long )0;
                        sqlstm.sqadto[34] = (unsigned short )0;
                        sqlstm.sqtdso[34] = (unsigned short )0;
                        sqlstm.sqhstv[35] = (unsigned char  *)&v_file_id;
                        sqlstm.sqhstl[35] = (unsigned long )19;
                        sqlstm.sqhsts[35] = (         int  )0;
                        sqlstm.sqindv[35] = (         short *)&ind_file_id;
                        sqlstm.sqinds[35] = (         int  )0;
                        sqlstm.sqharm[35] = (unsigned long )0;
                        sqlstm.sqadto[35] = (unsigned short )0;
                        sqlstm.sqtdso[35] = (unsigned short )0;
                        sqlstm.sqhstv[36] = (unsigned char  *)&v_approve_id;
                        sqlstm.sqhstl[36] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[36] = (         int  )0;
                        sqlstm.sqindv[36] = (         short *)&ind_approve_id;
                        sqlstm.sqinds[36] = (         int  )0;
                        sqlstm.sqharm[36] = (unsigned long )0;
                        sqlstm.sqadto[36] = (unsigned short )0;
                        sqlstm.sqtdso[36] = (unsigned short )0;
                        sqlstm.sqhstv[37] = (unsigned char  *)&v_merchant_id;
                        sqlstm.sqhstl[37] = (unsigned long )18;
                        sqlstm.sqhsts[37] = (         int  )0;
                        sqlstm.sqindv[37] = (         short *)&ind_merchant_id;
                        sqlstm.sqinds[37] = (         int  )0;
                        sqlstm.sqharm[37] = (unsigned long )0;
                        sqlstm.sqadto[37] = (unsigned short )0;
                        sqlstm.sqtdso[37] = (unsigned short )0;
                        sqlstm.sqhstv[38] = (unsigned char  *)&v_service_code;
                        sqlstm.sqhstl[38] = (unsigned long )6;
                        sqlstm.sqhsts[38] = (         int  )0;
                        sqlstm.sqindv[38] = (         short *)&ind_service_code;
                        sqlstm.sqinds[38] = (         int  )0;
                        sqlstm.sqharm[38] = (unsigned long )0;
                        sqlstm.sqadto[38] = (unsigned short )0;
                        sqlstm.sqtdso[38] = (unsigned short )0;
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
                        if (sqlca.sqlcode < 0) goto getdt_con_error;
}





/*seq_num*/
			if(ind_seq_num>=0){
				PutField_Int(myHash,"seq_num",v_seq_num);
DEBUGLOG(("GetDetailBySelectedTxn seq_num=[%d]\n",v_seq_num));
			}

/*batch_id*/
			if(ind_batch_id>=0){
				v_batch_id.arr[v_batch_id.len]='\0';
				PutField_CString(myHash,"batch_id",(const char*)v_batch_id.arr);
DEBUGLOG(("GetDetailBySelectedTxn batch_id=[%s]\n",v_batch_id.arr));
			}

/*merchant_id*/
			if(ind_merchant_id>=0){
				v_merchant_id.arr[v_merchant_id.len]='\0';
				PutField_CString(myHash,"merchant_id",(const char*)v_merchant_id.arr);
//DEBUGLOG(("GetDetailBySelectedTxn merchant_id=[%s]\n",v_merchant_id.arr));
			}

/*service_code*/
			if(ind_service_code>=0){
				v_service_code.arr[v_service_code.len]='\0';
				PutField_CString(myHash,"service_code",(const char*)v_service_code.arr);
//DEBUGLOG(("GetDetailBySelectedTxn service_code=[%s]\n",v_service_code.arr));
			}

/*txn_id*/
			if(ind_txn_id>=0){
				v_txn_id.arr[v_txn_id.len]='\0';
				PutField_CString(myHash,"txn_seq",(const char*)v_txn_id.arr);
DEBUGLOG(("GetDetailBySelectedTxn txn_id=[%s]\n",v_txn_id.arr));
			}

/*merchant_ref*/
			if(ind_merchant_ref>=0){
				v_merchant_ref.arr[v_merchant_ref.len]='\0';
				PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
//DEBUGLOG(("GetDetailBySelectedTxn merchant_ref= [%s]\n",v_merchant_ref.arr));
			}

/*country*/
			if(ind_country>=0){
				v_country.arr[v_country.len]='\0';
				PutField_CString(myHash,"txn_country",(const char*)v_country.arr);
DEBUGLOG(("GetDetailBySelectedTxn country= [%s]\n",v_country.arr));
			}

/*identity_id*/
			if(ind_identity_id>=0){
				v_identity_id.arr[v_identity_id.len]='\0';
				PutField_CString(myHash,"identity_id",(const char*)v_identity_id.arr);
//DEBUGLOG(("GetDetailBySelectedTxn identity_id= [%s]\n",v_identity_id.arr));
			}

/*account_num*/
			if(ind_account_num>=0){
				v_account_num.arr[v_account_num.len]='\0';
				PutField_CString(myHash,"account_num",(const char*)v_account_num.arr);
//DEBUGLOG(("GetDetailBySelectedTxn account_num= [%s]\n",v_account_num.arr));
			}

/*account_name*/
			if(ind_account_name>=0){
				v_account_name.arr[v_account_name.len]='\0';
				PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
//DEBUGLOG(("GetDetailBySelectedTxn account_name= [%s]\n",v_account_name.arr));
			}

/*bank_name*/
			if(ind_bank_name>=0){
				v_bank_name.arr[v_bank_name.len]='\0';
				PutField_CString(myHash,"bank_name",(const char*)v_bank_name.arr);
//DEBUGLOG(("GetDetailBySelectedTxn bank_name= [%s]\n",v_bank_name.arr));
			}

/*bank_code*/
			if(ind_bank_code>=0){
				v_bank_code.arr[v_bank_code.len]='\0';
				PutField_CString(myHash,"bank_code",(const char*)v_bank_code.arr);
//DEBUGLOG(("GetDetailBySelectedTxn bank_code= [%s]\n",v_bank_code.arr));
			}

/*branch*/
			if(ind_branch>=0){
				v_branch.arr[v_branch.len]='\0';
				PutField_CString(myHash,"branch",(const char*)v_branch.arr);
//DEBUGLOG(("GetDetailBySelectedTxn branch= [%s]\n",v_branch.arr));
			}

/*phone_num*/
			if(ind_phone_num>=0){
				v_phone_num.arr[v_phone_num.len]='\0';
				PutField_CString(myHash,"phone_num",(const char*)v_phone_num.arr);
//DEBUGLOG(("GetDetailBySelectedTxn phone_num= [%s]\n",v_phone_num.arr));
			}

/*province*/
			if(ind_province>=0){
				v_province.arr[v_province.len]='\0';
				PutField_CString(myHash,"province",(const char*)v_province.arr);
//DEBUGLOG(("GetDetailBySelectedTxn province= [%s]\n",v_province.arr));
			}

/*city*/
			if(ind_city>=0){
				v_city.arr[v_city.len]='\0';
				PutField_CString(myHash,"city",(const char*)v_city.arr);
//DEBUGLOG(("GetDetailBySelectedTxn city= [%s]\n",v_city.arr));
			}

/*payout_currency*/
			if(ind_payout_ccy>=0){
				v_payout_ccy.arr[v_payout_ccy.len]='\0';
				PutField_CString(myHash,"payout_ccy",(const char*)v_payout_ccy.arr);
//DEBUGLOG(("GetDetailBySelectedTxn payout_ccy= [%s]\n",v_payout_ccy.arr));
			}

/*request_currency*/
			if(ind_request_ccy>=0){
				v_request_ccy.arr[v_request_ccy.len]='\0';
				PutField_CString(myHash,"request_ccy",(const char*)v_request_ccy.arr);
//DEBUGLOG(("GetDetailBySelectedTxn request_ccy= [%s]\n",v_request_ccy.arr));
			}

/*payout_amount*/
			if(ind_payout_amount>=0){
				PutField_Double(myHash,"payout_amount",v_payout_amount);
//DEBUGLOG(("GetDetailBySelectedTxn payout_amount = [%lf]\n",v_payout_amount));
			}

/*request_amount*/
			if(ind_request_amount>=0){
				PutField_Double(myHash,"request_amount",v_request_amount);
DEBUGLOG(("GetDetailBySelectedTxn request_amount = [%lf]\n",v_request_amount));
			}

/*member_fee_ccy*/
			if(ind_member_fee_ccy>=0){
				v_member_fee_ccy.arr[v_member_fee_ccy.len]='\0';
				PutField_CString(myHash,"member_fee_ccy",(const char*)v_member_fee_ccy.arr);
//DEBUGLOG(("GetDetailBySelectedTxn member_fee_ccy= [%s]\n",v_member_fee_ccy.arr));
			}

/*member_fee*/
			if(ind_member_fee>=0){
				PutField_Double(myHash,"member_fee",v_member_fee);
//DEBUGLOG(("GetDetailBySelectedTxn member_fee = [%lf]\n",v_member_fee));
			}

/*merchant_fee_ccy*/
			if(ind_merchant_fee_ccy>=0){
				v_merchant_fee_ccy.arr[v_merchant_fee_ccy.len]='\0';
				PutField_CString(myHash,"merchant_fee_ccy",(const char*)v_merchant_fee_ccy.arr);
//DEBUGLOG(("GetDetailBySelectedTxn merchant_fee_ccy= [%s]\n",v_merchant_fee_ccy.arr));
			}

/*merchant_fee*/
			if(ind_merchant_fee>=0){
				PutField_Double(myHash,"merchant_fee",v_merchant_fee);
//DEBUGLOG(("GetDetailBySelectedTxn merchant_fee = [%lf]\n",v_merchant_fee));
			}

/*markup_ccy*/
			if(ind_markup_ccy>=0){
				v_markup_ccy.arr[v_markup_ccy.len]='\0';
				PutField_CString(myHash,"markup_ccy",(const char*)v_markup_ccy.arr);
//DEBUGLOG(("GetDetailBySelectedTxn markup_ccy= [%s]\n",v_markup_ccy.arr));
			}

/*markup_amt*/
			if(ind_markup_amt>=0){
				PutField_Double(myHash,"markup_amt",v_markup_amt);
//DEBUGLOG(("GetDetailBySelectedTxn markup_amt = [%lf]\n",v_markup_amt));
			}

/*ex_rate*/
			if(ind_ex_rate>=0){
				PutField_Double(myHash,"ex_rate",v_ex_rate);
//DEBUGLOG(("GetDetailBySelectedTxn ex_rate = [%lf]\n",v_ex_rate));
			}

/*status*/
			if(ind_status>=0){
				PutField_Int(myHash,"status",v_status);
DEBUGLOG(("GetDetailBySelectedTxn status = [%d]\n",v_status));
			}

/*resp_code*/
			if(ind_resp_code>=0){
				v_resp_code.arr[v_resp_code.len]='\0';
				PutField_CString(myHash,"resp_code",(const char*)v_resp_code.arr);
//DEBUGLOG(("GetDetailBySelectedTxn resp_code= [%s]\n",v_resp_code.arr));
			}

/*remark*/
			if(ind_remark>=0){
				v_remark.arr[v_remark.len]='\0';
				PutField_CString(myHash,"remark",(const char*)v_remark.arr);
//DEBUGLOG(("GetDetailBySelectedTxn remark= [%s]\n",v_remark.arr));
			}

/*file_name*/
			if(ind_file_name>=0){
				v_file_name.arr[v_file_name.len]='\0';
				PutField_CString(myHash,"file_name",(const char*)v_file_name.arr);
//DEBUGLOG(("GetDetailBySelectedTxn file_name= [%s]\n",v_file_name.arr));
			}

/*psp_batch_id*/	
			if(ind_psp_batch_id>=0){
				v_psp_batch_id.arr[v_psp_batch_id.len]='\0';
				PutField_CString(myHash,"psp_batch_id",(const char*)v_psp_batch_id.arr);
//DEBUGLOG(("GetDetailBySelectedTxn psp_batch_id= [%s]\n",v_psp_batch_id.arr));
			}

/*fundout_date*/
			if(ind_fundout_date>=0){
				v_fundout_date.arr[v_fundout_date.len]='\0';
				PutField_CString(myHash,"fundout_date",(const char*)v_fundout_date.arr);
//DEBUGLOG(("GetDetailBySelectedTxn fundout_date= [%s]\n",v_fundout_date.arr));
			}

/*service_fee*/
			if(ind_service_fee>=0){
				PutField_Double(myHash,"service_fee",v_service_fee);
//DEBUGLOG(("GetDetailBySelectedTxn service_fee= [%lf]\n",v_service_fee));
			}

/*psp_id*/	
			if(ind_psp_id>=0){
				v_psp_id.arr[v_psp_id.len]='\0';
				PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
//DEBUGLOG(("GetDetailBySelectedTxn psp_id= [%s]\n",v_psp_id.arr));
			}

/*file_id*/	
			if(ind_file_id>=0){
				v_file_id.arr[v_file_id.len]='\0';
				PutField_CString(myHash,"file_id",(const char*)v_file_id.arr);
//DEBUGLOG(("GetDetailBySelectedTxn file_id= [%s]\n",v_file_id.arr));
			}

/*batch_mode*/
			if(ind_batch_mode>=0){
				PutField_Char(myHash,"batch_mode",v_batch_mode);
//DEBUGLOG(("GetDetailBySelectedTxn batch_mode= [%c]\n",v_batch_mode));
			}

/*approve_id*/
			if(ind_approve_id>=0){
				PutField_Int(myHash,"approve_id",v_approve_id);
//DEBUGLOG(("GetDetailBySelectedTxn approve_id= [%lf]\n",v_approve_id));
			}

			RecordSet_Add(myRec,myHash);

		}
	}

	/* EXEC SQL CLOSE :c_cursor_dtcon; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )226;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dtcon;
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
 if (sqlca.sqlcode < 0) goto getdt_con_error;
}


	/* EXEC SQL FREE :c_cursor_dtcon; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )245;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dtcon;
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
 if (sqlca.sqlcode < 0) goto getdt_con_error;
}



DEBUGLOG(("GetDetailBySelectedTxn Normal Exit [%d]\n",iRet));
	return  iRet;

getdt_con_error:
DEBUGLOG(("getdt_con_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("DBPayoutApproveTmp GetDetailBySelectedTxn: SP_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE :c_cursor_dtcon; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )264;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dtcon;
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


	/* EXEC SQL FREE :c_cursor_dtcon; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )283;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dtcon;
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


	return PD_ERR;
}


int GetOrgBatchId(hash_t *hTxn)
{
	int	iRet = PD_ERR;
	int	iCnt = 0;
	char	*csTmp;
	char	csTag[PD_TAG_LEN+1];

        /* EXEC SQL WHENEVER SQLERROR GOTO holdgenid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_tmp_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_tmp_batch_id;


		/* varchar	v_batch_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_batch_id;


		short	ind_batch_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetOrgBatchId: Begin\n"));

	if(GetField_CString(hTxn,"tmp_batch_id",&csTmp)){
		hv_tmp_batch_id.len = strlen(csTmp);
		memcpy(hv_tmp_batch_id.arr,csTmp,hv_tmp_batch_id.len);
DEBUGLOG(("GetOrgBatchId tmp_batch_id = [%.*s]\n",hv_tmp_batch_id.len,hv_tmp_batch_id.arr));
	}

	/* EXEC SQL DECLARE c_cursor_orgid CURSOR FOR
		select	uh_batch_id
		from	payout_approve_tmp, 
		    	merchant_upload_file_header,
		     	merchant_upload_file_detail
	 	where 	pt_id = :hv_tmp_batch_id
		and 	pt_txn_id = ud_txn_id
		and 	ud_batch_id = uh_batch_id
		group by uh_batch_id; */ 


	/* EXEC SQL OPEN  c_cursor_orgid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )302;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_tmp_batch_id;
 sqlstm.sqhstl[0] = (unsigned long )18;
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
 if (sqlca.sqlcode < 0) goto holdgenid_error;
}


	do{
		/* EXEC SQL FETCH c_cursor_orgid
			INTO
				:v_batch_id:ind_batch_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 39;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )321;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_batch_id;
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
  if (sqlca.sqlcode < 0) goto holdgenid_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		if(ind_batch_id>=0){
			v_batch_id.arr[v_batch_id.len]='\0';
			sprintf(csTag,"org_batch_id_%d",iCnt);
			PutField_CString(hTxn,csTag,(const char*)v_batch_id.arr);
DEBUGLOG(("GetOrgBatchId org batch_id [%d] = [%s]\n",iCnt+1,v_batch_id.arr));

			iCnt ++;
			PutField_Int(hTxn,"org_batch_id_cnt",iCnt);
		}

	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_orgid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )340;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto holdgenid_error;
}



	if(iCnt > 0)
		iRet = PD_OK;

DEBUGLOG(("GetOrgBatchId Exit [%d]\n",iRet));
        return iRet;

holdgenid_error:
DEBUGLOG(("holdgenid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("PayoutApproveTmp_GetOrgBatchId: SP_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_orgid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 39;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )355;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return INT_ERR;
}
