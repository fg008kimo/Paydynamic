
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
           char  filnam[25];
};
static struct sqlcxp sqlfpn =
{
    24,
    "manual_match_fallback.pc"
};


static unsigned int sqlctx = 1247446211;


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
   unsigned char  *sqhstv[10];
   unsigned long  sqhstl[10];
            int   sqhsts[10];
            short *sqindv[10];
            int   sqinds[10];
   unsigned long  sqharm[10];
   unsigned long  *sqharc[10];
   unsigned short  sqadto[10];
   unsigned short  sqtdso[10];
} sqlstm = {12,10};

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
"select oth_txn_id from ol_txn_header where oth_merchant_ref = :b0          \
  ";

 static char *sq0002 = 
"select oth_txn_id from ol_txn_header , ol_txn_psp_detail where oth_txn_id =\
 otp_txn_id and oth_input_channel = :b0 and oth_status = :b1 and oth_ar_ind =\
 :b2 and oth_txn_code = :b3 and oth_sub_status = :b4 and oth_deposit_amount =\
 :b5 and otp_txn_ccy = :b6 and otp_bank_code = :b7 and otp_bank_acct_num = :b\
8 and otp_txn_hold_ind = :b9 order by oth_approval_timestamp asc            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,77,0,9,158,0,2049,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,13,160,0,0,1,0,0,1,0,2,9,0,0,
43,0,0,1,0,0,15,177,0,0,0,0,0,1,0,
58,0,0,2,382,0,9,223,0,2049,10,10,0,1,0,1,9,0,0,1,1,0,0,1,1,0,0,1,9,0,0,1,9,0,
0,1,4,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,
113,0,0,2,0,0,13,226,0,0,1,0,0,1,0,2,9,0,0,
132,0,0,2,0,0,15,250,0,0,0,0,0,1,0,
147,0,0,3,0,0,32,267,0,0,0,0,0,1,0,
};


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include "common.h"
#include "utilitys.h"
#include "curl/curl.h"
#include "ObjPtr.h"
#include "myrecordset.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

OBJPTR(DB);
OBJPTR(Txn);

char cDebug = 'Y';
char csOmmMsg[PD_TMP_MSG_BUF_LEN + 1];

int parse_arg(int argc, char **argv);

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int iRet = SUCCESS;
	int iStmtTxnIdCnt = 0;
	char *csTag = (char*) malloc (1024);

	char cMatchingType;
	int iOverrideAmt;
	char csMerchRef[PD_MERCHANT_REF_LEN + 1];
	char csChannelCode[PD_CHANNEL_CODE_LEN + 1];
	char csTxnCode[PD_TXN_CODE_LEN + 1];
	char csSubStatus[PD_SUB_STATUS_LEN + 1];
	char csTxnCcy[PD_CCY_ID_LEN + 1];
	char csBankCode[PD_BANK_CODE_LEN + 1];
	char csBankAcctNum[PD_BANK_ACCT_NUM_LEN + 1];
	char cStatus;
	char cArInd;
	double dDepositAmt = 0.0;
	int iTxnHoldInd = 0;

	iRet = parse_arg(argc, argv);

	if (iRet != SUCCESS) {
		printf("Usage: manual_match_fallback.exec -m omm_msg\n");
		return FAILURE;
	}

	hash_t *hRequest;
	hRequest = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRequest, 0);

	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_merchant_ref[PD_MERCHANT_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_merchant_ref;

		/* varchar hv_channel_code[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel_code;

		/* varchar hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

		/* varchar hv_sub_status[PD_SUB_STATUS_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_sub_status;

		/* varchar hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;

		/* varchar hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;

		/* varchar hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		char hv_status;
		char hv_ar_ind;
		double hv_deposit_amt;
		int hv_txn_hold_ind;

		/* varchar v_merch_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_merch_txn_id;

		/* varchar v_stmt_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_stmt_txn_id;


		short ind_merch_txn_id = -1;
		short ind_stmt_txn_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	char *csTmp;
	int i_field_cnt = 0;
	csTmp = mystrtok(csOmmMsg, ",");
	while (csTmp != NULL) {
		i_field_cnt++;
		switch (i_field_cnt) {
			case 1:
				cMatchingType = csTmp[0];
DEBUGLOG(("[1][cMatchingType] = [%c]\n", cMatchingType));
				break;
			case 2:
				iOverrideAmt = atoi(csTmp);
DEBUGLOG(("[2][iOverrideAmt] = [%d]\n", iOverrideAmt));
				break;
			case 3:
				strcpy(csMerchRef, csTmp);
DEBUGLOG(("[3][csMerchRef] = [%s]\n", csMerchRef));
				break;
			case 4:
				strcpy(csChannelCode, csTmp);
DEBUGLOG(("[4][csChannelCode] = [%s]\n", csChannelCode));
				break;
			case 5:
				strcpy(csTxnCode, csTmp);
DEBUGLOG(("[5][csTxnCode] = [%s]\n", csTxnCode));
				break;
			case 6:
				strcpy(csSubStatus, csTmp);
DEBUGLOG(("[6][csSubStatus] = [%s]\n", csSubStatus));
				break;
			case 7:
				strcpy(csTxnCcy, csTmp);
DEBUGLOG(("[7][csTxnCcy] = [%s]\n", csTxnCcy));
				break;
			case 8:
				strcpy(csBankCode, csTmp);
DEBUGLOG(("[8][csBankCode] = [%s]\n", csBankCode));
				break;
			case 9:
				strcpy(csBankAcctNum, csTmp);
DEBUGLOG(("[9][csBankAcctNum] = [%s]\n", csBankAcctNum));
				break;
			case 10:
				cStatus = csTmp[0];
DEBUGLOG(("[10][cStatus] = [%c]\n", cStatus));
				break;
			case 11:
				cArInd = csTmp[0];
DEBUGLOG(("[11][cArInd] = [%c]\n", cArInd));
				break;
			case 12:
				sscanf(csTmp, "%lf", &dDepositAmt);
DEBUGLOG(("[12][dDepositAmt] = [%lf]\n", dDepositAmt));
				break;
			case 13:
				iTxnHoldInd = atoi(csTmp);
DEBUGLOG(("[13][iTxnHoldInd] = [%d]\n", iTxnHoldInd));
				break;
			default:
DEBUGLOG(("error\n"));
		}
		csTmp = mystrtok(NULL, ",");
	}

	hv_merchant_ref.len = strlen(csMerchRef);
	memcpy(hv_merchant_ref.arr, csMerchRef, hv_merchant_ref.len);

	/* EXEC SQL DECLARE c_cursor_get_merch_txn_id CURSOR FOR
		select oth_txn_id
		from ol_txn_header
		where oth_merchant_ref = :hv_merchant_ref; */ 


	/* EXEC SQL OPEN c_cursor_get_merch_txn_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_ref;
 sqlstm.sqhstl[0] = (unsigned long )52;
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



	/* EXEC SQL FETCH c_cursor_get_merch_txn_id
	INTO :v_merch_txn_id:ind_merch_txn_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )24;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqfoff = (         int )0;
 sqlstm.sqfmod = (unsigned int )2;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_merch_txn_id;
 sqlstm.sqhstl[0] = (unsigned long )19;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_merch_txn_id;
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



	if (SQLCODE == SQL_NOT_FOUND) {
DEBUGLOG(("manual_match_fallback: merch_txn_id not found\n"));
		return FAILURE;
	}

	// merch_txn_id
	if (ind_merch_txn_id >= 0) {
		v_merch_txn_id.arr[v_merch_txn_id.len] = '\0';
DEBUGLOG(("manual_match_fallback: merch_txn_id = [%s]\n", (const char*)v_merch_txn_id.arr));
	} else {
DEBUGLOG(("manual_match_fallback: merch_txn_id is empty\n"));
		return FAILURE;
	}

	/* EXEC SQL CLOSE c_cursor_get_merch_txn_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )43;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto sql_error;
}





	hv_channel_code.len = strlen(csChannelCode);
	memcpy(hv_channel_code.arr, csChannelCode, hv_channel_code.len);

	hv_txn_code.len = strlen(csTxnCode);
	memcpy(hv_txn_code.arr, csTxnCode, hv_txn_code.len);

	hv_sub_status.len = strlen(csSubStatus);
	memcpy(hv_sub_status.arr, csSubStatus, hv_sub_status.len);

	hv_txn_ccy.len = strlen(csTxnCcy);
	memcpy(hv_txn_ccy.arr, csTxnCcy, hv_txn_ccy.len);

	hv_bank_code.len = strlen(csBankCode);
	memcpy(hv_bank_code.arr, csBankCode, hv_bank_code.len);

	hv_bank_acct_num.len = strlen(csBankAcctNum);
	memcpy(hv_bank_acct_num.arr, csBankAcctNum, hv_bank_acct_num.len);

	hv_status = cStatus;

	hv_ar_ind = cArInd;

	hv_deposit_amt = dDepositAmt;

	hv_txn_hold_ind = iTxnHoldInd;

	/* EXEC SQL DECLARE c_cursor_get_stmt_txn_id cURSOR FOR
		select oth_txn_id
		from ol_txn_header, ol_txn_psp_detail
		where oth_txn_id = otp_txn_id
		and oth_input_channel = :hv_channel_code
		and oth_status = :hv_status
		and oth_ar_ind = :hv_ar_ind
		and oth_txn_code = :hv_txn_code
		and oth_sub_status = :hv_sub_status
		and oth_deposit_amount = :hv_deposit_amt
		and otp_txn_ccy = :hv_txn_ccy
		and otp_bank_code = :hv_bank_code
		and otp_bank_acct_num = :hv_bank_acct_num
		and otp_txn_hold_ind = :hv_txn_hold_ind
		order by oth_approval_timestamp asc; */ 


	/* EXEC SQL OPEN c_cursor_get_stmt_txn_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )58;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_channel_code;
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
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_code;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_sub_status;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_deposit_amt;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_txn_ccy;
 sqlstm.sqhstl[6] = (unsigned long )5;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_bank_code;
 sqlstm.sqhstl[7] = (unsigned long )12;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)0;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[8] = (unsigned long )52;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)0;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_txn_hold_ind;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)0;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
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



	for (;;) {
		/* EXEC SQL FETCH c_cursor_get_stmt_txn_id
		INTO :v_stmt_txn_id:ind_stmt_txn_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 10;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )113;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_stmt_txn_id;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_stmt_txn_id;
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



		if (SQLCODE == SQL_NOT_FOUND) {
			if (iStmtTxnIdCnt == 0) {
DEBUGLOG(("manual_match_fallback: stmt_txn_id not found\n"));
				return FAILURE;
			} else {
				break;
			}
		}

		iStmtTxnIdCnt++;

		// stmt_txn_id
		if (ind_stmt_txn_id >= 0) {
			v_stmt_txn_id.arr[v_stmt_txn_id.len] = '\0';
DEBUGLOG(("manual_match_fallback: stmt_txn_id = [%s]\n", (const char*)v_stmt_txn_id.arr));
		} else {
DEBUGLOG(("manual_match_fallback: stmt_txn_id is empty\n"));
			return FAILURE;
		}
	}

	/* EXEC SQL CLOSE c_cursor_get_stmt_txn_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )132;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto sql_error;
}



	hash_destroy(hRequest);
	FREE_ME(hRequest);

	FREE_ME(csTag);

DEBUGLOG(("manual_match_fallback: Normal Exit() iRet = [%d]\n", iRet));
	return iRet;

sql_error:
DEBUGLOG(("sql_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("manual_match_fallback:: sql error\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

//EXEC SQL CLOSE c_cursor_get_merch_txn_id
//EXEC SQL CLOSE c_cursor_get_stmt_txn_id;
	/* EXEC SQL ROLLBACK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )147;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	FREE_ME(hRequest);
	return FAILURE;
}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


int parse_arg(int argc, char **argv)
{
	char c;
	strcpy(csOmmMsg, "");

	while ((c = getopt(argc, argv, "m:")) != EOF) {
		switch (c) {
			case 'm':
				strcpy(csOmmMsg, optarg);
				break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(csOmmMsg, "")) {
		return FAILURE;
	}

	return SUCCESS;
}
