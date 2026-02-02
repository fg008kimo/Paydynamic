
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
           char  filnam[32];
};
static struct sqlcxp sqlfpn =
{
    31,
    "handle_auto_exp_off_stmt_txn.pc"
};


static unsigned int sqlctx = 2087588149;


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
   unsigned char  *sqhstv[8];
   unsigned long  sqhstl[8];
            int   sqhsts[8];
            short *sqindv[8];
            int   sqinds[8];
   unsigned long  sqharm[8];
   unsigned long  *sqharc[8];
   unsigned short  sqadto[8];
   unsigned short  sqtdso[8];
} sqlstm = {12,8};

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
"SELECT md_merchant_id , omb_int_bank_code , omb_bank_acct_num , md_stmt_aut\
o_expired_days , md_stmt_auto_expired_mins , omb_service_code , country FROM \
bank_desc , ol_bank_accts , ol_merchant_bank_acct , ol_merch_detail WHERE ( m\
d_stmt_auto_expired_days != 0 OR md_stmt_auto_expired_mins != 0 ) AND md_stat\
us = 'O' AND md_merchant_id = omb_merchant_id AND omb_status = 'O' AND omb_in\
t_bank_code = ob_int_bank_code AND omb_bank_acct_num = ob_bank_acct_num AND o\
b_shared_acct = 0 AND ob_int_bank_code = internal_bank_code ORDER BY md_merch\
ant_id , omb_int_bank_code , omb_bank_acct_num            ";

 static char *sq0003 = 
"SELECT oth_txn_id , otp_txn_ccy FROM ol_txn_psp_detail , ol_txn_header WHER\
E oth_txn_code = :b0 AND oth_status = :b1 AND oth_ar_ind = :b2 AND oth_sub_st\
atus = :b3 AND oth_create_timestamp < sysdate - ( :b4 + :b5 / ( 60 * 24 ) ) A\
ND oth_txn_id = otp_txn_id AND otp_bank_code = :b6 AND otp_bank_acct_num = :b\
7 AND otp_txn_hold_ind = 0 ORDER BY oth_txn_id            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,595,0,9,132,0,2049,0,0,0,1,0,
20,0,0,1,0,0,13,134,0,0,7,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,9,
0,0,2,9,0,0,
63,0,0,1,0,0,15,193,0,0,0,0,0,1,0,
78,0,0,1,0,0,15,202,0,0,0,0,0,1,0,
93,0,0,2,0,0,32,203,0,0,0,0,0,1,0,
108,0,0,3,364,0,9,285,0,2049,8,8,0,1,0,1,9,0,0,1,1,0,0,1,1,0,0,1,9,0,0,1,3,0,0,
1,3,0,0,1,9,0,0,1,9,0,0,
155,0,0,3,0,0,13,287,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
178,0,0,3,0,0,15,344,0,0,0,0,0,1,0,
193,0,0,3,0,0,15,361,0,0,0,0,0,1,0,
208,0,0,4,0,0,32,362,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2014. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/03/11              Virginia Yun
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
#include "dates.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

//char    cs_cutoff_date[PD_DATE_LEN + 1];
char    cDebug = 'Y';

OBJPTR(DB);
OBJPTR(Txn);

int parse_arg(int argc,char **argv);
int process_main(const char* csPostingDate);
int process_expiry_stmt(const char* csPostingDate,const char* csMerchantID, const char* csIntBankCode, const char* csBankAcctNum, int iStmtExpDays,int iStmtExpMins, const char* csServiceCode, const char* csCountry);
int process_expiry_by_txn(hash_t *hTxn);


int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}




int batch_proc(int argc, char* argv[])
{
        int     iRet;
	char	csPostingDate[PD_DATE_LEN +1];

	iRet = parse_arg(argc,argv);
               
        if (iRet != SUCCESS) {
       // 	printf("usage:  -d cutoff_date\n");
                return (iRet);
        }
	GetCurrHostPostingDate((unsigned char*)csPostingDate);
DEBUGLOG(("today is [%s]\n",csPostingDate));

	iRet = process_main(csPostingDate);

DEBUGLOG(("iRet = [%d]\n",iRet));

	return iRet;


}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

int process_main(const char* csPostingDate)
{
        int     iRet = SUCCESS;

DEBUGLOG(("process_main\n"));
	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar	v_int_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_int_bank_code;

		/* varchar	v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

		int	v_stmt_auto_exp_days;
		int	v_stmt_auto_exp_mins;
		/* varchar	v_service_code[PD_SERVICE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		/* varchar	v_country[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		
		short	ind_merchant_id = -1;
		short	ind_int_bank_code = -1;
		short	ind_bank_acct_num = -1;
		short	ind_stmt_auto_exp_days = -1;
		short	ind_stmt_auto_exp_mins = -1;
		short	ind_service_code = -1;
		short	ind_country = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


        /* EXEC SQL DECLARE c_cursor_get_merch_detail CURSOR FOR
		SELECT md_merchant_id, 
                       omb_int_bank_code, 
                       omb_bank_acct_num, 
                       md_stmt_auto_expired_days, 
                       md_stmt_auto_expired_mins,
                       omb_service_code,
                       country
		FROM bank_desc, ol_bank_accts, ol_merchant_bank_acct, ol_merch_detail
		WHERE  (md_stmt_auto_expired_days != 0
                        OR
                        md_stmt_auto_expired_mins != 0
                       )
                AND md_status = 'O'
                AND md_merchant_id = omb_merchant_id
                AND omb_status = 'O'
                AND omb_int_bank_code = ob_int_bank_code
                AND omb_bank_acct_num = ob_bank_acct_num
                AND ob_shared_acct = 0
                AND ob_int_bank_code = internal_bank_code
/o
		AND omb_bank_acct_num = '6217007200007400982'
o/
		ORDER BY md_merchant_id, omb_int_bank_code, omb_bank_acct_num; */ 


        /* EXEC SQL OPEN c_cursor_get_merch_detail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 0;
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
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto sql_error;
}


        do {    
                /* EXEC SQL FETCH c_cursor_get_merch_detail
                INTO
			v_merchant_id:ind_merchant_id,
			v_int_bank_code:ind_int_bank_code,
			v_bank_acct_num:ind_bank_acct_num,
			v_stmt_auto_exp_days:ind_stmt_auto_exp_days,
			v_stmt_auto_exp_mins:ind_stmt_auto_exp_mins,
			v_service_code:ind_service_code,
			v_country:ind_country; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 7;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )20;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_merchant_id;
                sqlstm.sqhstl[0] = (unsigned long )18;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_merchant_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_int_bank_code;
                sqlstm.sqhstl[1] = (unsigned long )13;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_int_bank_code;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_bank_acct_num;
                sqlstm.sqhstl[2] = (unsigned long )53;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_bank_acct_num;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_stmt_auto_exp_days;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_stmt_auto_exp_days;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_stmt_auto_exp_mins;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_stmt_auto_exp_mins;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_service_code;
                sqlstm.sqhstl[5] = (unsigned long )6;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_service_code;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_country;
                sqlstm.sqhstl[6] = (unsigned long )5;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_country;
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
                        break;
                }

		if (ind_merchant_id >= 0) {
			v_merchant_id.arr[v_merchant_id.len] = '\0';	
DEBUGLOG(("merchant_id = [%s]\n",v_merchant_id.arr));
		}

		if (ind_int_bank_code >= 0) {
			v_int_bank_code.arr[v_int_bank_code.len] = '\0';	
DEBUGLOG(("int_bank_code = [%s]\n", v_int_bank_code.arr));
		}

		if (ind_bank_acct_num >= 0) {
			v_bank_acct_num.arr[v_bank_acct_num.len] = '\0';	
DEBUGLOG(("bank_acct_num = [%s]\n", v_bank_acct_num.arr));
		}	

		if (ind_stmt_auto_exp_days >= 0) {
DEBUGLOG(("stmt_auto_exp_days = [%d]\n", v_stmt_auto_exp_days));
		}

		if (ind_stmt_auto_exp_mins >= 0) {
DEBUGLOG(("stmt_auto_exp_mins = [%d]\n", v_stmt_auto_exp_mins));
		}

		if (ind_service_code >= 0) {
			v_service_code.arr[v_service_code.len] = '\0';	
DEBUGLOG(("service_code = [%s]\n", v_service_code.arr));
		}	

		if (ind_country >= 0) {
			v_country.arr[v_country.len] = '\0';	
DEBUGLOG(("country = [%s]\n", v_country.arr));
		}	


		if ((v_stmt_auto_exp_days > 0) || (v_stmt_auto_exp_mins > 0)) {
			if (iRet == SUCCESS) {
				iRet = process_expiry_stmt(csPostingDate,(const char*)v_merchant_id.arr, (const char *)v_int_bank_code.arr, (const char*)v_bank_acct_num.arr, v_stmt_auto_exp_days, v_stmt_auto_exp_mins, (const char*) v_service_code.arr, (const char*) v_country.arr);
			}
		}

DEBUGLOG(("===================================================\n"));


	} while(PD_TRUE && iRet == PD_OK );
        /* EXEC SQL CLOSE c_cursor_get_merch_detail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )63;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto sql_error;
}



	return	iRet;

sql_error:
    DEBUGLOG(("handle_auto_exp_off_stmt_txn process_main error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    ERRLOG("handle_auto_exp_off_stmt_txn::process_main sql error %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_get_merch_detail; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 7;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )78;
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
    sqlstm.offset = (unsigned int  )93;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}

int process_expiry_stmt(const char* csPostingDate,const char* csMerchantID, const char* csIntBankCode, const char* csBankAcctNum, int iStmtExpDays,int iStmtExpMins, const char* csServiceCode, const char* csCountry)
{               
        int     iRet = SUCCESS;


	hash_t*	hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));

DEBUGLOG(("*************Process Expiry Start******************\n"));

	/* EXEC SQL WHENEVER SQLERROR GOTO expiry_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

		char	hv_status;
		char	hv_ar_ind;
		/* varchar	hv_sub_status[PD_SUB_STATUS_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_sub_status;

		/* varchar	hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar	hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		int	hv_stmt_expired_days;
		int	hv_stmt_expired_mins;

		/* varchar	v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;


		short	ind_txn_id = -1;
		short	ind_txn_ccy = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_code.len = strlen(PD_BANK_DEPOSIT_TXN_CODE);
	memcpy(hv_txn_code.arr, PD_BANK_DEPOSIT_TXN_CODE, hv_txn_code.len);
DEBUGLOG(("process_expiry_stmt txn_code [%.*s]\n", hv_txn_code.len, hv_txn_code.arr));

	hv_status = PD_COMPLETE;
DEBUGLOG(("process_expiry_stmt status [%c]\n", hv_status));

	hv_ar_ind = PD_ACCEPT;
DEBUGLOG(("process_expiry_stmt ar_ind [%c]\n", hv_ar_ind));

	hv_sub_status.len = strlen(PD_UNALLOCATED);
	memcpy(hv_sub_status.arr, PD_UNALLOCATED, hv_sub_status.len);
DEBUGLOG(("process_expiry_stmt sub_status [%.*s]\n", hv_sub_status.len, hv_sub_status.arr));
	
	hv_int_bank_code.len = strlen(csIntBankCode);
	memcpy(hv_int_bank_code.arr, csIntBankCode, hv_int_bank_code.len);
DEBUGLOG(("process_expiry_stmt int_bank_code [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));
	
	hv_bank_acct_num.len = strlen(csBankAcctNum);
	memcpy(hv_bank_acct_num.arr, csBankAcctNum, hv_bank_acct_num.len);
DEBUGLOG(("process_expiry_stmt bank_acct_num [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));

	hv_stmt_expired_days = iStmtExpDays;
DEBUGLOG(("process_expiry_stmt stmt_expired_days = [%d]\n", hv_stmt_expired_days));
	
	hv_stmt_expired_mins = iStmtExpMins;
DEBUGLOG(("process_expiry_stmt stmt_expired_mins = [%d]\n", hv_stmt_expired_mins));


        /* EXEC SQL DECLARE c_cursor_get_expiry_list CURSOR FOR
		SELECT oth_txn_id, otp_txn_ccy
		FROM   ol_txn_psp_detail, ol_txn_header
		WHERE oth_txn_code = :hv_txn_code
		AND    oth_status = :hv_status
		AND    oth_ar_ind = :hv_ar_ind
		AND    oth_sub_status = :hv_sub_status
		AND    oth_create_timestamp < sysdate - (:hv_stmt_expired_days + :hv_stmt_expired_mins/(60*24))
		AND    oth_txn_id = otp_txn_id
                AND    otp_bank_code = :hv_int_bank_code 
                AND    otp_bank_acct_num = :hv_bank_acct_num
                AND    otp_txn_hold_ind = 0
/o
		AND    oth_txn_id = 'T000000000115192'
o/
		ORDER BY oth_txn_id; */ 


        /* EXEC SQL OPEN c_cursor_get_expiry_list; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0003;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )108;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_txn_code;
        sqlstm.sqhstl[0] = (unsigned long )5;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[1] = (unsigned long )1;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_ar_ind;
        sqlstm.sqhstl[2] = (unsigned long )1;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_sub_status;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_stmt_expired_days;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_stmt_expired_mins;
        sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_int_bank_code;
        sqlstm.sqhstl[6] = (unsigned long )12;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_bank_acct_num;
        sqlstm.sqhstl[7] = (unsigned long )52;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)0;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto expiry_error;
}


        do {    
                /* EXEC SQL FETCH c_cursor_get_expiry_list
                INTO
			v_txn_id:ind_txn_id,
			v_txn_ccy:ind_txn_ccy; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 8;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )155;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_ccy;
                sqlstm.sqhstl[1] = (unsigned long )6;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_txn_ccy;
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
                if (sqlca.sqlcode < 0) goto expiry_error;
}




                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		iRet = PD_OK;

                hash_init(hTxn,0);
		
		if (ind_txn_id >= 0) {
			v_txn_id.arr[v_txn_id.len]='\0';
			PutField_CString(hTxn,"txn_seq",(const char*)v_txn_id.arr);
DEBUGLOG(("process_expiry_stmt: txn_seq =[%.*s]\n", v_txn_id.len, v_txn_id.arr));
		}

		if (ind_txn_ccy >= 0) {
			v_txn_ccy.arr[v_txn_ccy.len]='\0';
			PutField_CString(hTxn,"txn_ccy",(const char*)v_txn_ccy.arr);
DEBUGLOG(("process_expiry_stmt: txn_ccy =[%.*s]\n", v_txn_ccy.len, v_txn_ccy.arr));
		}


		PutField_CString(hTxn, "posting_date", csPostingDate);
		PutField_CString(hTxn, "merchant_id", csMerchantID);
		PutField_CString(hTxn, "int_bank_code", csIntBankCode);
		PutField_CString(hTxn, "bank_acct_num", csBankAcctNum);
		PutField_CString(hTxn, "service_code", csServiceCode);
		PutField_CString(hTxn, "txn_country", csCountry);

		if (iRet == PD_OK) {
			iRet = process_expiry_by_txn(hTxn);

// For testing
//DEBUGLOG(("process_expiry_stmt rollback for testing!\n"));
//	TxnAbort();

			if (iRet == PD_OK)  {
DEBUGLOG(("process_expiry_stmt SUCC!!!\n"));
				iRet = SUCCESS;
				TxnCommit();
			}
			else  {
				iRet = FAILURE;
DEBUGLOG(("process_expiry_stmt FAIL!!!\n"));
				TxnAbort();
			}
		}

		hash_destroy(hTxn);
 	}
	while(PD_TRUE && iRet == PD_OK);

        /* EXEC SQL CLOSE c_cursor_get_expiry_list; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )178;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto expiry_error;
}



	if(iRet==SUCCESS){
DEBUGLOG(("process_expiry_stmt Normal Exit\n"));
	}
	else{
DEBUGLOG(("process_expiry_stmt Error[%d]\n",iRet));
	}

	FREE_ME(hTxn);
        return iRet;

expiry_error:
    DEBUGLOG(("process_expiry_stmt error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    ERRLOG("handle_auto_exp_off_stmt_txn::process_bucket sql error %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_get_expiry_list; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 8;
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


    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 8;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )208;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}


int parse_arg(int argc,char **argv)
{
/*
        char    c;
	strcpy(cs_cutoff_date,"");

        while ((c = getopt(argc,argv,"d:")) != EOF) {
                switch (c) {
                        case 'd':
                                strcpy(cs_cutoff_date, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_cutoff_date,"")) 
                return FAILURE;

*/
        return SUCCESS;
}



int	process_expiry_by_txn(hash_t *hTxn)
{
	int	iRet = SUCCESS;

	char    csTxnSeq[PD_TXN_SEQ_LEN +1];	
        char    csDateTime[PD_DATETIME_LEN +1];
        char    csDate[PD_DATE_LEN +1];
        char    csTime[PD_TIME_LEN +1];
	char	csPostingDate[PD_DATE_LEN +1];

	char	*csTmp = NULL;

	hash_t*	hCon;
	hash_t*	hReq;
	hash_t* hResponse;

	hCon = (hash_t*) malloc (sizeof(hash_t));
	hReq = (hash_t*) malloc (sizeof(hash_t));
	hResponse = (hash_t*) malloc (sizeof(hash_t));

	hash_init(hCon,0);
	hash_init(hReq,0);
	hash_init(hResponse,0);

	PutField_CString(hReq, "txn_code", PD_AUTO_EXPIRED_TXN_CODE);
DEBUGLOG(("process_expiry_by_txn : txn_code [%s]\n", PD_AUTO_EXPIRED_TXN_CODE));

	if (GetField_CString(hTxn, "txn_seq", &csTmp)) {
DEBUGLOG(("process_expiry_by_txn : org_txn_seq [%s]\n", csTmp));
		PutField_CString(hReq, "org_txn_seq", csTmp);
	}

	if (GetField_CString(hTxn, "merchant_id", &csTmp)) {
DEBUGLOG(("process_expiry_by_txn : merchant_id [%s]\n", csTmp));
		PutField_CString(hReq, "merchant_id", csTmp);
	}

	if (GetField_CString(hTxn, "txn_ccy", &csTmp)) {
DEBUGLOG(("process_expiry_by_txn : txn_ccy [%s]\n", csTmp));
		PutField_CString(hReq, "txn_ccy", csTmp);
	}

	if (GetField_CString(hTxn, "service_code", &csTmp)) {
DEBUGLOG(("process_expiry_by_txn : service_code [%s]\n", csTmp));
		PutField_CString(hReq, "service_code", csTmp);
	}

	if (GetField_CString(hTxn, "txn_country", &csTmp)) {
DEBUGLOG(("process_expiry_by_txn : txn_country [%s]\n", csTmp));
		PutField_CString(hReq, "txn_country", csTmp);
	}

	PutField_CString(hReq, "add_user", PD_UPDATE_USER);

	DBObjPtr = CreateObj(DBPtr, "DBOLTxnSeq", "GetNextOmtTxnSeq");
	strcpy(csTxnSeq, (*DBObjPtr)());
DEBUGLOG(("process_expiry_by_txn : txn_seq [%s]\n", csTxnSeq));
	PutField_CString(hCon, "txn_seq", csTxnSeq);

	PutField_CString(hCon, "channel_code", PD_CHANNEL_OMT);
	PutField_CString(hCon, "process_type", PD_PROCESS_TYPE_DEF);
	PutField_CString(hCon, "process_code", PD_PROCESS_CODE_DEF);



	GetCurrHostPostingDate((unsigned char*)csPostingDate);
	PutField_CString(hCon, "PHDATE", csPostingDate);

	/*
	if (GetField_CString(hTxn, "posting_date", &csTmp)) {
DEBUGLOG(("process_expiry_by_txn : posting_date [%s]\n", csTmp));
		PutField_CString(hCon, "PHDATE", csTmp);
	}
	*/
	

        strcpy(csDateTime,getdatetime());
        memcpy(csDate,&csDateTime[0],PD_DATE_LEN);
        csDate[PD_DATE_LEN] = '\0';

        memcpy(csTime,&csDateTime[PD_DATE_LEN],PD_TIME_LEN);
        csTime[PD_TIME_LEN] = '\0';

	PutField_CString(hCon,"transmission_datetime",csDateTime);
	PutField_CString(hCon,"tm_date",csDate);
	PutField_CString(hCon,"tm_time",csTime);
	PutField_CString(hCon,"local_tm_date",csDate);
	PutField_CString(hCon,"local_tm_time",csTime);

	PutField_Int(hCon, "has_merch_ref", PD_FALSE);


	if (iRet == SUCCESS) {
DEBUGLOG(("process_expiry_by_txn call TxnOmtByUsMRN::Authorize()\n"));
                TxnObjPtr = CreateObj(TxnPtr, "TxnOmtByUsMRN","Authorize");
                if ((unsigned long)(*TxnObjPtr)(hCon, hReq, hResponse) != PD_OK) {
                        iRet = FAILURE;
DEBUGLOG(("process_expiry_by_txn call TxnOmtByUsMRN::Authorize() failed\n"));
ERRLOG("handle_auto_exp_off_stmt_txn::process_expiry_by_txn call TxnOmtByUsMRN::Authorize() failed\n");
                } else {
DEBUGLOG(("process_expiry_by_txn call TxnOmtByUsMRN::Authorize() SUCC\n"));
                }
	}

	hash_destroy(hCon);
	hash_destroy(hReq);
	hash_destroy(hResponse);

	FREE_ME(hCon);
	FREE_ME(hReq);
	FREE_ME(hResponse);


	return iRet;
}
