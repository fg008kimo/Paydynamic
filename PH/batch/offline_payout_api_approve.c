
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
           char  filnam[30];
};
static struct sqlcxp sqlfpn =
{
    29,
    "offline_payout_api_approve.pc"
};


static unsigned int sqlctx = 1725089155;


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
   unsigned char  *sqhstv[1];
   unsigned long  sqhstl[1];
            int   sqhsts[1];
            short *sqindv[1];
            int   sqinds[1];
   unsigned long  sqharm[1];
   unsigned long  *sqharc[1];
   unsigned short  sqadto[1];
   unsigned short  sqtdso[1];
} sqlstm = {12,1};

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
};


/*
PDProTech (c)2017. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2017/03/20              David Wong
Add ack batch_txn_seq				   2017/04/26		   LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include "batchcommon.h"
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"


#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cs_batch_id[PD_TXN_SEQ_LEN+1];
char    cs_count[PD_TXN_SEQ_LEN + 1];
char    cs_user[PD_USER_LEN + 1];
char    cs_ack_batch_seq[PD_TXN_SEQ_LEN + 1];
char	cs_mode[2];
char	cs_type[2];
char	cs_bank_name[PD_BANK_NAME_LEN + 1];
char	cs_total_amt[PD_AMOUNT_LEN + 1];
char	cs_min_amt[PD_AMOUNT_LEN + 1];
char	cs_max_amt[PD_AMOUNT_LEN + 1];
char	cs_approve_id[PD_TXN_SEQ_LEN + 1];
char	cs_pre_approve_id[PD_TXN_SEQ_LEN + 1];
char	c_mode;
char	c_type;

char cDebug = 'Y';
OBJPTR(Txn);
OBJPTR(BO);
OBJPTR(DB);

int parse_arg(int argc,char **argv);
int GetSeqList(hash_t *hTxn);
int GetPayoutRecord(const char * csBatchId, const int iSeqNum, hash_t *hTxn);


int batch_init(int argc, char* argv[])
{
	if (argc < 7) {
		printf("usage: -b batch_id -n total_count -u user\n");
		return FAILURE;
	} else
		return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int iRet = PD_OK;

	char *csTmp;
	char csTag[PD_TAG_LEN + 1];
	double dTmp = 0.0;
	int iCnt = 0;
	int iTotal = 0;
	int iBatchCnt = 0;
	int iLoop = 0;
	int iTmpRet = 0;
	int iTmp = 0;
	char *csTxnId;

	hash_t *hRequest;
	hRequest = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRequest, 0);

	hash_t *hContext;
	hContext = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hContext, 0);

	hash_t *hResponse;
	hResponse = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hResponse, 0);

	hash_t *hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn, 0);

	hash_t *hTmpRequest;
	hTmpRequest = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTmpRequest, 0);

	hash_t *hTmpContext;
	hTmpContext = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTmpContext, 0);

	hash_t *hTmpResponse;
	hTmpResponse = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTmpResponse, 0);

	iRet = parse_arg(argc, argv);

	if (iRet != SUCCESS) {
		printf("usage: -b batch_id -n total_count -u user\n");
		return(iRet);
	}

DEBUGLOG(("Authorize\n"));

DEBUGLOG(("Authorize:: batch_id = [%s]\n", cs_batch_id));
	PutField_CString(hRequest, "batch_id", cs_batch_id);
	PutField_CString(hContext, "batch_id", cs_batch_id);

	PutField_CString(hTmpContext, "batch_id", cs_batch_id);
	PutField_CString(hTmpContext, "txn_code", PD_OL_PAYOUT_API_APPROVE);
	PutField_Int(hTmpContext, "is_process_approve", PD_TRUE);

DEBUGLOG(("Authorize:: call BOOLPayout->GetPayoutApiRecords\n"));
	BOObjPtr = CreateObj(BOPtr, "BOOLPayout", "GetPayoutApiRecords");
	iRet = (unsigned long)(*BOObjPtr)(hTmpContext, hTmpRequest, hTmpResponse);
	if (iRet == PD_OK) {
		// merchant_id
		if (GetField_CString(hTmpContext, "merchant_id", &csTmp)) {
DEBUGLOG(("GetPayoutApiRecords:: merchant_id = [%s]\n", csTmp));
			PutField_CString(hRequest, "merchant_id", csTmp);
			PutField_CString(hContext, "merchant_id", csTmp);
		}

		// service_code
		if (GetField_CString(hTmpContext, "service_code", &csTmp)) {
DEBUGLOG(("GetPayoutApiRecords:: service_code = [%s]\n", csTmp));
			PutField_CString(hContext, "service_code", csTmp);
		}

		// txn_country
		if (GetField_CString(hTmpContext, "txn_country", &csTmp)) {
DEBUGLOG(("GetPayoutApiRecords:: txn_country = [%s]\n", csTmp));
			PutField_CString(hContext, "txn_country", csTmp);
		}

		// txn_ccy
		if (GetField_CString(hTmpContext, "txn_ccy", &csTmp)) {
DEBUGLOG(("GetPayoutApiRecords:: txn_ccy = [%s]\n", csTmp));
			PutField_CString(hContext, "txn_ccy", csTmp);
		}

		// total_cnt
		if (GetField_Int(hTmpContext, "total_cnt", &iBatchCnt)) {
DEBUGLOG(("GetPayoutApiRecords:: total_cnt = [%d]\n", iBatchCnt));
		}
	}

	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: call BOOLMerchant->GetMerchantDetail\n"));
		BOObjPtr = CreateObj(BOPtr, "BOOLMerchant", "GetMerchantDetail");
		iRet = (unsigned long)(*BOObjPtr)(hContext, hRequest);
	}

	if (iRet == PD_OK) {
		char* csValueTmp;
		csValueTmp = (char*) malloc (128);
		DBObjPtr = CreateObj(DBPtr, "DBSystemControl", "FindCode");
		if ((unsigned long)(DBObjPtr)("CTPHDATE", csValueTmp) == FOUND) {
DEBUGLOG(("Authorize:: PHDATE = [%s]\n", csValueTmp));
		} else {
			iRet = INT_ERR;
DEBUGLOG(("Authorize:: Unable to find CTPHDATE\n"));
ERRLOG("offline_payout_api_approve: Authorize:: Unable to find CTPHDATE\n");
		}
		int iDayOfWeek = day_of_week((const unsigned char *)csValueTmp);
		PutField_Int(hContext, "day_of_week", iDayOfWeek);
DEBUGLOG(("Authorize:: day_of_week = [%d]\n", iDayOfWeek));
		FREE_ME(csValueTmp);
	}

	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: call BOOLPayout->CheckAvalBalance\n"));
		BOObjPtr = CreateObj(BOPtr, "BOOLPayout", "CheckAvalBalance");
		iRet = (unsigned long)(*BOObjPtr)(hContext, hRequest);
	}

	if (iRet == PD_OK) {
		if (GetField_Double(hContext, "merchant_net_float", &dTmp)) {
			PutField_Double(hContext, "remain_merchant_net_float", dTmp);
DEBUGLOG(("Authorize:: merchant_net_float = [%lf]\n", dTmp));
		}
		if (GetField_Double(hContext, "merchant_reserved_po", &dTmp)) {
			PutField_Double(hContext, "remain_merchant_reserved_po", dTmp);
DEBUGLOG(("Authorize:: merchant_reserved_po = [%lf]\n", dTmp));
		}
		if (GetField_Double(hContext, "merchant_fundin_po", &dTmp)) {
DEBUGLOG(("Authorize:: merchant_fundin_po = [%lf]\n", dTmp));
		}
	}

DEBUGLOG(("Authorize:: add_user = [%s]\n", cs_user));
	PutField_CString(hContext, "update_user", cs_user);
	PutField_CString(hContext, "add_user", cs_user);

	PutField_CString(hContext, "txn_code", PD_OL_PAYOUT_API_APPROVE);
	PutField_CString(hContext, "channel_code", PD_CHANNEL_OMT);

	PutField_Int(hContext, "status", PAYOUT_MASTER_TRANSACTION_CONFIRMED);
	PutField_Int(hContext, "total_count", atoi(cs_count));

	if(cs_ack_batch_seq==NULL){
		char    csBatchTxnSeq[PD_TXN_SEQ_LEN +1];
		DBObjPtr = CreateObj(DBPtr,"DBOLTxnSeq","GetNextOmtTxnSeq");
		strcpy(csBatchTxnSeq,(*DBObjPtr)());
		PutField_CString(hContext,"batch_txn_seq",csBatchTxnSeq);
DEBUGLOG(("Authorize:: batch_txn_seq (new, ack use) = [%s]\n", csBatchTxnSeq));
	}
	else{
		PutField_CString(hContext,"batch_txn_seq",cs_ack_batch_seq);
DEBUGLOG(("Authorize:: batch_txn_seq (ack use) = [%s]\n", cs_ack_batch_seq));
	}

	if (iRet == PD_OK && GetField_Int(hContext, "total_count", &iCnt)) {
		for (iLoop = 0; iLoop < iBatchCnt; iLoop++) {
			sprintf(csTag, "org_txn_id_%d", iLoop);
			GetField_CString(hTmpContext, csTag, &csTxnId);

/* lock ol_txn_header record */
DEBUGLOG(("Authorize:: call DBOLTransaction->GetTxnIdForUpdateNoWaitWithSubStatus\n"));
			DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "GetTxnIdForUpdateNoWaitWithSubStatus");
			iTmpRet = (unsigned long)(*DBObjPtr)(csTxnId, PD_TO_PSP, PD_SYSTEM_CONFIRMED);
			if (iTmpRet != PD_OK) {
				continue;
			}

/* lock ol_payout_request */
DEBUGLOG(("Authorize:: call DBOLPayoutRequest->MatchOLPayoutRequestStatus_ForUpdate\n"));
			DBObjPtr = CreateObj(DBPtr, "DBOLPayoutRequest", "MatchOLPayoutRequestStatus_ForUpdate");
			iTmpRet = (unsigned long)(*DBObjPtr)(csTxnId, PAYOUT_MASTER_TRANSACTION_CONFIRMED);
			if (iTmpRet != PD_FOUND) {
				continue;
			}

//seq_num//
			sprintf(csTag, "seq_num_%d", iLoop);
			if (GetField_Int(hTmpRequest, csTag, &iTmp)) {
DEBUGLOG(("seq_num = [%d]\n", iTmp));
				PutField_Int(hContext, "seq_num", iTmp);
			}

//batch_id//
			sprintf(csTag, "batch_id_%d", iLoop);
			if (GetField_CString(hTmpRequest, csTag, &csTmp)) {
DEBUGLOG(("batch_id = [%s]\n", csTmp));
				PutField_CString(hContext, "batch_id", csTmp);
			}

//txn_seq//
			PutField_CString(hContext, "txn_seq", csTxnId);

//merchant_ref//
			sprintf(csTag, "merchant_ref_%d", iLoop);
			if (GetField_CString(hTmpRequest, csTag, &csTmp)) {
DEBUGLOG(("merchant_ref = [%s]\n", csTmp));
				PutField_CString(hContext, "merchant_ref", csTmp);
			}

//txn_country//
			sprintf(csTag, "txn_country_%d", iLoop);
			if (GetField_CString(hTmpRequest, csTag, &csTmp)) {
DEBUGLOG(("country = [%s]\n", csTmp));
				PutField_CString(hContext, "txn_country", csTmp);
			}

//identity_id//
			sprintf(csTag, "identity_id_%d", iLoop);
			if (GetField_CString(hTmpRequest, csTag, &csTmp)) {
DEBUGLOG(("identity_id = [%s]\n", csTmp));
				PutField_CString(hContext, "identity_id", csTmp);
			}

//account_num//
			sprintf(csTag, "account_id_%d", iLoop);
			if (GetField_CString(hTmpRequest, csTag, &csTmp)) {
DEBUGLOG(("account_num = [%s]\n", csTmp));
				PutField_CString(hContext, "account_num", csTmp);
			}

//account_name//
			sprintf(csTag, "account_name_%d", iLoop);
			if (GetField_CString(hTmpRequest, csTag, &csTmp)) {
DEBUGLOG(("account_name = [%s]\n", csTmp));
				PutField_CString(hContext, "account_name", csTmp);
			}

//bank_name//
			sprintf(csTag, "bank_name_%d", iLoop);
			if (GetField_CString(hTmpRequest, csTag, &csTmp)) {
DEBUGLOG(("bank_name = [%s]\n", csTmp));
				PutField_CString(hContext, "bank_name", csTmp);
			}

//bank_code//
			sprintf(csTag, "bank_code_%d", iLoop);
			if (GetField_CString(hTmpRequest, csTag, &csTmp)) {
DEBUGLOG(("bank_code = [%s]\n", csTmp));
				PutField_CString(hContext, "bank_code", csTmp);
			}

//branch//
			sprintf(csTag, "branch_%d", iLoop);
			if (GetField_CString(hTmpRequest, csTag, &csTmp)) {
DEBUGLOG(("branch = [%s]\n", csTmp));
				PutField_CString(hContext, "branch", csTmp);
			}

//phone_num//
//province//
//city//

//payout_currency//
			sprintf(csTag, "dst_txn_ccy_%d", iLoop);
			if (GetField_CString(hTmpRequest, csTag, &csTmp)) {
DEBUGLOG(("payout_ccy = [%s]\n", csTmp));
				PutField_CString(hContext, "payout_ccy", csTmp);
				PutField_CString(hContext, "dst_txn_ccy", csTmp);
			}

//request_ccy//
			sprintf(csTag, "txn_ccy_%d", iLoop);
			if (GetField_CString(hTmpRequest, csTag, &csTmp)) {
DEBUGLOG(("request_ccy = [%s]\n", csTmp));
				PutField_CString(hContext, "request_ccy", csTmp);
				PutField_CString(hContext, "net_ccy", csTmp);
				PutField_CString(hContext, "txn_ccy", csTmp);
			}

//payout_amount//
			sprintf(csTag, "payout_amount_%d", iLoop);
			if (GetField_Double(hTmpRequest, csTag, &dTmp)) {
DEBUGLOG(("payout_amount = [%lf]\n", dTmp));
				PutField_Double(hContext, "payout_amount", dTmp);
			}

//request_amount//
			sprintf(csTag, "txn_amt_%d", iLoop);
			if (GetField_Double(hTmpRequest, csTag, &dTmp)) {
DEBUGLOG(("request_amount = [%lf]\n", dTmp));
				PutField_Double(hContext, "request_amount", dTmp);
				PutField_Double(hContext, "txn_amt", dTmp);
			}

//member_fee_ccy//
			sprintf(csTag, "member_fee_ccy_%d", iLoop);
			if (GetField_CString(hTmpRequest, csTag, &csTmp)) {
DEBUGLOG(("member_fee_ccy = [%s]\n", csTmp));
				PutField_CString(hContext, "member_fee_ccy", csTmp);
			}

//member_fee//
			sprintf(csTag, "member_fee_%d", iLoop);
			if (GetField_Double(hTmpRequest, csTag, &dTmp)) {
DEBUGLOG(("member_fee = [%lf]\n", dTmp));
				PutField_Double(hContext, "member_fee", dTmp);
			}

//merchant_fee_ccy//
			sprintf(csTag, "merchant_fee_ccy_%d", iLoop);
			if (GetField_CString(hTmpRequest, csTag, &csTmp)) {
DEBUGLOG(("merchant_fee_ccy = [%s]\n", csTmp));
				PutField_CString(hContext, "merchant_fee_ccy", csTmp);
			}

//merchant_fee//
			sprintf(csTag, "org_merchant_fee_%d", iLoop);
			if (GetField_Double(hTmpRequest, csTag, &dTmp)) {
DEBUGLOG(("merchant_fee = [%lf]\n", dTmp));
				PutField_Double(hContext, "merchant_fee", dTmp);
			}

//markup_ccy//
			sprintf(csTag, "markup_ccy_%d", iLoop);
			if (GetField_CString(hTmpRequest, csTag, &csTmp)) {
DEBUGLOG(("markup_ccy = [%s]\n", csTmp));
				PutField_CString(hContext, "markup_ccy", csTmp);
			}

//markup_amt//
			sprintf(csTag, "markup_amt_%d", iLoop);
			if (GetField_Double(hTmpRequest, csTag, &dTmp)) {
DEBUGLOG(("markup_amt = [%lf]\n", dTmp));
				PutField_Double(hContext, "markup_amt", dTmp);
			}

//ex_rate//
//resp_code//
//remark//
//batch_mode//

			TxnObjPtr = CreateObj(TxnPtr, "TxnOmtByUsPIT", "Authorize");
			iRet = (unsigned long)(*TxnObjPtr)(hContext, hContext, hContext);
			if (iRet != PD_OK) {
				break;
			}

			iTotal++;
			PutField_Int(hContext, "process_count", iTotal);

			if (iTotal >= iCnt) {
				break;
			}
		}
	}

DEBUGLOG(("Authorize:: call OLPayoutApiBatchHD->Update\n"));
	hash_init(hTxn, 0);
	PutField_CString(hTxn, "batch_id", cs_batch_id);
	PutField_CString(hTxn, "txn_code", PD_OL_PAYOUT_API_APPROVE);
	PutField_Char(hTxn, "status", PD_OL_PO_API_COMPLETE);
	PutField_CString(hTxn, "update_user", cs_user);
	if (iRet != PD_OK) {
		PutField_Int(hTxn, "ret_code", iRet);
	}
	DBObjPtr = CreateObj(DBPtr, "DBOLPayoutApiBatchHD", "Update");
	if ((unsigned long)((*DBObjPtr)(hTxn)) != PD_OK) {
		iRet = INT_ERR;
DEBUGLOG(("Authorize:: DBOLPayoutApiBatchHD: Update Failed\n"));
ERRLOG("Authorize:: DBOLPayoutApiBatchHD: Update Failed\n");
	}
	hash_destroy(hTxn);

DEBUGLOG(("offline_payout_api_approve Normal Exit() count [%d], iRet = [%d]\n", iTotal, iRet));

	FREE_ME(hRequest);
	FREE_ME(hContext);
	FREE_ME(hResponse);
	FREE_ME(hTxn);
	FREE_ME(hTmpRequest);
	FREE_ME(hTmpContext);
	FREE_ME(hTmpResponse);
	return SUCCESS;
}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


int parse_arg(int argc, char **argv)
{
	char c;
	strcpy(cs_batch_id, "");
	strcpy(cs_count, "");
	strcpy(cs_user, "");
	strcpy(cs_ack_batch_seq, "");

	while ((c = getopt(argc, argv, "b:n:l:u:k:")) != EOF) {
		switch (c) {
			case 'b':
				strcpy(cs_batch_id, optarg);
				break;
			case 'n':
				strcpy(cs_count, optarg);
				break;
			case 'u':
				strcpy(cs_user, optarg);
				break;
			case 'k':
				strcpy(cs_ack_batch_seq, optarg);
				break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(cs_batch_id, "") || !strcmp(cs_count, "") || !strcmp(cs_user, ""))
		return FAILURE;

	return SUCCESS;
}

