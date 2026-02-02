
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
           char  filnam[37];
};
static struct sqlcxp sqlfpn =
{
    36,
    "ol_payout_recon_ignore_bank_match.pc"
};


static unsigned int sqlctx = 1049476683;


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
PDProTech (c)2021. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2021/02/02              [MIC]
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
#include "dbutility.h"
#include "utilitys.h"
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"
#include "ObjPtr.h"
#include "internal.h"
#include "math.h"



static char	cDebug = 'Y';

OBJPTR(Channel);
OBJPTR(DB);
OBJPTR(Txn);
OBJPTR(BO);



#define PD_PREV_STMT_DATE_FILTER	"prev_stmt_date_diff"
#define PD_NEXT_STMT_DATE_FILTER	"next_stmt_date_diff"



char	csInCreateTsFr[PD_DATE_LEN + PD_TIME_LEN + 1];
char	csInCreateTsTo[PD_DATE_LEN + PD_TIME_LEN + 1];
char	csInProvId[PD_CLIENT_ID_LEN + 1];
char	csInTrigSeq[PD_TMP_BUF_LEN + 1];



int parse_arg(int argc, char **argv);
int process_data(const char* csTrigSeq);
int GetStmtDateDiff(char *csPrevDateDiff, char *csNextDateDiff);
int CheckKeywords(hash_t *hContext);

int batch_init(int argc, char *argv[])
{
	return SUCCESS;
}

int batch_proc(int argc, char *argv[])
{
	int		iRet = FAILURE;
	int		iDtlRet = PD_ERR;
	
DEBUGLOG(("batch_proc: Start!\n"));

	iRet = parse_arg(argc, argv);
	
	if (iRet != SUCCESS) {
		if (argc < 9) {
			printf("usage: -f create_ts_fr -t create_ts_to -p prov_id -q trig_seq\n");
		}
		return (iRet);
	}
	
	if (argc == 9) {
		iDtlRet = process_data(csInTrigSeq);
		if (iDtlRet != PD_OK) {
			iRet = FAILURE;
		}
		
	}

	return iRet;
	
}

int process_data(const char* csTrigSeq)
{
	int     iRet = PD_OK;
	int     iDtlRet = PD_ERR;
	int     iUpdHdRet = PD_ERR;
	
	int     iIsPairUp = PD_FALSE;
	int     iPspDisabled;
	char	*csUser;
	
	char	*csPrevStmtDateDiff = (char*)malloc(200);
	char	*csNextStmtDateDiff = (char*)malloc(200);
	char	*csPspTxnId;
	char	*csBaidTxnId;
	char	*csPspId;

	char	cStatus;
	char	cHeaderStatus;

	unsigned long	lTrigSeq = 0;
		
	recordset_t *rBaidTxn;
	rBaidTxn = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rBaidTxn, 0);
	
	recordset_t *rPspTxn;
	rPspTxn = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rPspTxn, 0);
	
	hash_t* hTrigLog;
	hTrigLog = (hash_t*)malloc(sizeof(hash_t));
	hash_init(hTrigLog,0);
	
	hash_t* hList;
	hList = (hash_t*)malloc(sizeof(hash_t));
	//hash_init(hList,0);

	hash_t* hRec;
	hRec = (hash_t*)malloc(sizeof(hash_t));
	hash_init(hRec,0);
	
	hash_t* hTmp;
	
	hash_t* hChkKeywords;
	hChkKeywords = (hash_t*)malloc(sizeof(hash_t));
	hash_init(hChkKeywords,0);
	
	
	hash_t* hGetAttribute;
	hGetAttribute = (hash_t*)malloc(sizeof(hash_t));
	hash_init(hGetAttribute,0);
	


DEBUGLOG(("ol_payout_recon_ignore_bank_match:: process_data\n"));

	lTrigSeq = ctol((const unsigned char *)csTrigSeq, strlen(csTrigSeq));
DEBUGLOG(("process_data:: trigger_seq = [%lu]\n", lTrigSeq));

/*Get trigger_status, create_user
by <trigger_seq> in OL_PAYOUT_RECON_TRIGGER_LOG*/

	DBObjPtr = CreateObj(DBPtr,"DBOLPayoutReconTriggerLog","GetHeaderByFileId");
	iDtlRet = (unsigned long)(*DBObjPtr)(lTrigSeq, hTrigLog);
	if(iDtlRet == PD_OK){
DEBUGLOG(("process_data:: call OLPayoutReconTriggerLog::GetHeaderByFileId Found!!\n"));
/*trigger_status*/
		if(GetField_Char(hTrigLog, "trigger_status", &cStatus)){
DEBUGLOG(("process_data:: trigger_status = [%c]\n", cStatus));
			if(cStatus != PD_TRIGGER_STATUS_INIT){
DEBUGLOG(("process_data:: trigger_status not [I]!!\n"));
				iRet = INT_ERR;
			}
		}
		else{
DEBUGLOG(("process_data:: trigger_status not found!!\n"));
ERRLOG("ol_payout_recon_ignore_bank_match:: process_data:: call OLPayoutReconTriggerLog::GetHeaderByFileId status not found!!\n");
			iRet = INT_ERR;
		}
/*create_user*/
		if(iRet == PD_OK){
			if(GetField_CString(hTrigLog, "create_user", &csUser)){
DEBUGLOG(("process_data:: create_user = [%s]\n", csUser));
			}
			else{
DEBUGLOG(("process_data:: create_user not found!!\n"));
ERRLOG("ol_payout_recon_ignore_bank_match:: process_data:: call OLPayoutReconTriggerLog::GetHeaderByFileId create_user not found!!\n");
				iRet = INT_ERR;
			}
		}
	}
	else{
DEBUGLOG(("process_data:: call DBOLPayoutReconTriggerLog::GetHeaderByFileId Error!!\n"));
ERRLOG("ol_payout_recon_ignore_bank_match:: process_data:: call OLPayoutReconTriggerLog::GetHeaderByFileId Error!!\n");
		iRet = INT_ERR;
	}

	
	

/*Lock record on table OL_PAYOUT_RECON_TRIGGER_LOG by TrigSeq*/
	if(iRet == PD_OK){
		DBObjPtr = CreateObj(DBPtr, "DBOLPayoutReconTriggerLog", "MatchHeaderStatusForUpdate");
		iDtlRet = (unsigned long)(*DBObjPtr)(lTrigSeq, PD_TRIGGER_STATUS_INIT);
		if(iDtlRet == PD_FOUND){
DEBUGLOG(("process_data:: call OLPayoutReconTriggerLog::MatchHeaderStatusForUpdate TrigSeq[%s] Status[%c] Success!!\n", csTrigSeq, PD_TRIGGER_STATUS_INIT));
		}
		else if(iDtlRet == PD_NOT_FOUND){
DEBUGLOG(("process_data:: call OLPayoutReconTriggerLog::MatchHeaderStatusForUpdate TrigSeq[%s] Status[%c] Not Found!!\n", csTrigSeq, PD_TRIGGER_STATUS_INIT));
			iRet = INT_ERR;
		}
		else{
DEBUGLOG(("process_data:: call OLPayoutReconTriggerLog::MatchHeaderStatusForUpdate TrigSeq[%s] Status[%c] Failure!!\n", csTrigSeq, PD_TRIGGER_STATUS_INIT));
ERRLOG("ol_payout_recon_ignore_bank_match:: process_data:: call OLPayoutReconTriggerLog::MatchHeaderStatusForUpdate Failure!!\n");
			iRet = INT_ERR;
		}
	}
	
/*Update <OL_PAYOUT_RECON_TRIGGER_LOG.PRL_TRIGGER_STATUS> to P */

	if(iRet == PD_OK){
		PutField_CString(hTrigLog,"trigger_seq",csTrigSeq);
		PutField_Char(hTrigLog, "trigger_status", PD_TRIGGER_STATUS_PROCESS); 

		DBObjPtr = CreateObj(DBPtr, "DBOLPayoutReconTriggerLog", "UpdateHeader");
		iUpdHdRet = (unsigned long)(*DBObjPtr)(hTrigLog);
		if(iUpdHdRet == PD_OK){
DEBUGLOG(("process_data:: call ol_payout_recon_ignore_bank_match::UpdateHeader TrigSeq[%s] status[%c] Success!!\n", csTrigSeq, PD_TRIGGER_STATUS_PROCESS));
			TxnCommit();
		}
		else{
DEBUGLOG(("process_data:: call ol_payout_recon_ignore_bank_match::UpdateHeader TrigSeq[%s] status[%c] Failure!!\n", csTrigSeq, PD_TRIGGER_STATUS_PROCESS));
ERRLOG("ol_payout_recon_ignore_bank_match:: process_data:: call DBOLPayoutReconTriggerLog::UpdateHeader Failure!!\n");
			iRet = INT_ERR;
		}
	}


	/* payout recon start */

	if (iRet == PD_OK) {
	/*TODO : Get csPrevStmtDateDiff, csNextStmtDateDiff*/
		iDtlRet = GetStmtDateDiff(csPrevStmtDateDiff, csNextStmtDateDiff);
		if(iDtlRet != PD_OK) {
DEBUGLOG(("process_data:: call GetStmtDateDiff ret_code[%d] Failure!!\n", iDtlRet));
			iRet = INT_ERR;
		}
		else{
DEBUGLOG(("process_data:: call GetStmtDateDiff ret_code[%d] Success!!\n", iDtlRet));
		}
		
		

		
		
	
	/* Get psp_txn_id in recordset */
		DBObjPtr = CreateObj(DBPtr, "DBOLPspDetail", "GetPspIdByClientIdAcctType");
		iDtlRet = (unsigned long)(*DBObjPtr)(csInProvId, PD_NATURE_PAYOUT, hGetAttribute);
		if(iDtlRet == PD_FOUND){
DEBUGLOG(("process_data:: call OLPspDetail::GetPspIdByClientIdAcctType Found!!\n"));
			if (GetField_CString(hGetAttribute, "psp_id", &csPspId)) {
DEBUGLOG(("process_data::  psp_id = [%s]\n", csPspId));
				PutField_CString(hRec, "psp_id", csPspId);
			}
			else{
DEBUGLOG((" psp_id not found!!\n"));
ERRLOG("ol_payout_recon_ignore_bank_match:: process_data:: call OLPspDetail::GetPspIdByClientIdAcctType psp_id not found!!\n");
				iRet = INT_ERR;
			}
			
			if(GetField_Int(hGetAttribute, "psp_disabled", &iPspDisabled)){
DEBUGLOG(("process_data:: psp_disabled = [%d]\n", iPspDisabled));
				if(iPspDisabled == PD_DISABLED){
					iRet = INT_ERR;
				}
			}
			else{
DEBUGLOG(("process_data:: psp_disabled not found!!\n"));
ERRLOG("ol_payout_recon_ignore_bank_match:: process_data:: call OLPspDetail::GetPspIdByClientIdAcctType psp_disabled not found!!\n");
				iRet = INT_ERR;
			}
		}
		else{
DEBUGLOG(("process_data:: call DBOLPspDetail::GetPspIdByClientIdAcctType Error!!\n"));
ERRLOG("ol_payout_recon_ignore_bank_match:: process_data:: call OLPspDetail::GetPspIdByClientIdAcctType Error!!\n");
			iRet = INT_ERR;
		}
		
		
		PutField_CString(hRec, "create_ts_from", csInCreateTsFr);
		PutField_CString(hRec, "create_ts_to", csInCreateTsTo);
		DBObjPtr = CreateObj(DBPtr, "DBOLTxnPspDetail", "GetPayoutReconPspTxn");
		iDtlRet = (unsigned long)(*DBObjPtr)(hRec, rPspTxn);
		if(iDtlRet == PD_OK) {
			hTmp = RecordSet_GetFirst(rPspTxn);
			while (hTmp) {
				iIsPairUp = PD_FALSE;
				if (GetField_CString(hTmp, "psp_txn_id", &csPspTxnId)) {
	/* psp_txn_id found */
DEBUGLOG(("process_data:: psp_txn_id = [%s]\n", csPspTxnId));


	/* prepare for GetPayoutReconBaidTxn */
					RecordSet_Destroy(rBaidTxn);
					recordset_init(rBaidTxn, 0);
					PutField_CString(hRec, "psp_id", csPspId);
					PutField_CString(hRec, "psp_txn_id", csPspTxnId);
					PutField_CString(hRec, "prev_stmt_date_diff", csPrevStmtDateDiff);
					PutField_CString(hRec, "next_stmt_date_diff", csNextStmtDateDiff);
					
	/* Get baid_txn_id in recordset */
					DBObjPtr = CreateObj(DBPtr, "DBOLBAIDTxn", "GetPayoutReconBaidTxn");
					iDtlRet = (unsigned long)(*DBObjPtr)(hRec, rBaidTxn);
					if (iDtlRet == PD_OK) {
						hTmp = RecordSet_GetFirst(rBaidTxn);
						while (hTmp && iIsPairUp == PD_FALSE) {
							if (GetField_CString(hTmp, "baid_txn_id", &csBaidTxnId)) {
	/* baid_txn_id found */
DEBUGLOG(("process_data:: baid_txn_id = [%s]\n", csBaidTxnId));

	/* check keywords */
								hash_destroy(hChkKeywords);
								hash_init(hChkKeywords, 0);
								PutField_CString(hChkKeywords, "baid_txn_id", csBaidTxnId);
								if (CheckKeywords(hChkKeywords) != PD_OK) {
DEBUGLOG(("process_data:: keywords not match\n"));
DEBUGLOG(("process_data:: --------------------------------------------------\n"));
									hTmp = RecordSet_GetNext(rBaidTxn);
									continue;
								}

	/*keywords match*/
	/* TODO: set hold_recon to true (PspTxn) */
	
	
	/* set hold_recon to true (BaidTxn) */
								hash_init(hList, 0);
								PutField_CString(hList, "txn_seq", csBaidTxnId);
								PutField_CString(hList, "update_user", csUser);
								PutField_Int(hList, "hold_recon", PD_TRUE);
DEBUGLOG(("process_data:: call DBOLBAIDTxn::Update()\n"));
								DBObjPtr = CreateObj(DBPtr, "DBOLBAIDTxn", "Update");
								iDtlRet = (unsigned long)(*DBObjPtr)(hList);
								if (iDtlRet == PD_OK) {
DEBUGLOG(("process_data:: Update [%s] hold_recon success\n", csBaidTxnId));
								} else {
DEBUGLOG(("process_data:: Update [%s] hold_recon failed\n", csBaidTxnId));
								}
								hash_destroy(hList);	
								
	/* add into list */
								hash_init(hList, 0);
								PutField_CString(hList, "psp_txn_id", csPspTxnId);
								PutField_CString(hList, "baid_txn_id", csBaidTxnId);
								PutField_CString(hList, "create_user", csUser);
DEBUGLOG(("process_data:: call DBOLWaitPayoutReconCfmList::Add()\n"));
								DBObjPtr = CreateObj(DBPtr, "DBOLWaitPayoutReconCfmList", "Add");
								iDtlRet = (unsigned long)(*DBObjPtr)(hList);
								if (iDtlRet == PD_OK) {
DEBUGLOG(("process_data:: Add PspTxnId[%s], BaidTxnId [%s] to OLWaitPayoutReconCfmList success\n", csPspTxnId, csBaidTxnId));
								} 
								else {
DEBUGLOG(("process_data:: Add PspTxnId [%s], BaidTxnId [%s] to OLWaitPayoutReconCfmList failed\n", csPspTxnId, csBaidTxnId));
								}
								hash_destroy(hList);
								iIsPairUp = PD_TRUE;
							}
							else{
DEBUGLOG(("process_data:: baid_txn_id not found!!\n"));
							}
							hTmp = RecordSet_GetNext(rBaidTxn);
						
						}
					
					}
				}
				else{
DEBUGLOG(("process_data:: psp_txn_id not found!!\n"));
				
				}
				
				hTmp = RecordSet_GetNext(rPspTxn);

			}
		}
	}

	
	if(iRet == PD_OK){
		TxnCommit();
	}
	else{
		TxnAbort();
	}

	/*Prepare for update OLPayoutReconTriggerLog*/
	PutField_CString(hTrigLog,"trigger_seq",csTrigSeq);
	PutField_CString(hTrigLog, "update_user", csUser);
	
	cHeaderStatus = PD_TRIGGER_STATUS_COMPLETED;
	PutField_Char(hTrigLog, "trigger_status", PD_TRIGGER_STATUS_COMPLETED);

	DBObjPtr = CreateObj(DBPtr, "DBOLPayoutReconTriggerLog", "UpdateHeader");
	iUpdHdRet = (unsigned long)(*DBObjPtr)(hTrigLog);
	if(iUpdHdRet == PD_OK){
DEBUGLOG(("process_data:: call DBOLPayoutReconTriggerLog::UpdateHeader TrigSeq[%s] status[%c] ret_code[%d] Success!!\n", csTrigSeq, cHeaderStatus, iUpdHdRet));
	}
	else{
DEBUGLOG(("process_data:: call DBOLPayoutReconTriggerLog::UpdateHeader TrigSeq[%s] status[%c] ret_code[%d] Failure!!\n", csTrigSeq, cHeaderStatus, iUpdHdRet));
ERRLOG("ol_payout_recon_ignore_bank_match:: process_data:: call DBOLPayoutReconTriggerLog::UpdateHeader Failure!!\n");
		iRet = INT_ERR;

	}
	
	hash_destroy(hTrigLog);
	FREE_ME(hTrigLog);
	
	//hash_destroy(hList);
	FREE_ME(hList);
	
	hash_destroy(hRec);
	FREE_ME(hRec);
	
	
	hash_destroy(hChkKeywords);
	FREE_ME(hChkKeywords);
	
	hash_destroy(hGetAttribute);
	FREE_ME(hGetAttribute);
	
	
	FREE_ME(csPrevStmtDateDiff);
	FREE_ME(csNextStmtDateDiff);
	
	RecordSet_Destroy(rBaidTxn);
	FREE_ME(rBaidTxn);
	
	RecordSet_Destroy(rPspTxn);
	FREE_ME(rPspTxn);

	
	
DEBUGLOG(("ol_payout_recon_ignore_bank_match:: process_data() Normal Exit! iRet = [%d]\n", iRet));
	return iRet;
	
}



int CheckKeywords(hash_t *hContext)
{

	int iRet = PD_OK;
	int iTmpRet;
	
	char *csBaidTxnId;
	char *csTmp;
	
	hash_t *hStmtDtl;
	hStmtDtl = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hStmtDtl, 0);

	recordset_t *rKeywords;
	rKeywords = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rKeywords, 0);

	
	// baid_txn_id
	if (iRet == PD_OK) {
		if (!GetField_CString(hContext, "baid_txn_id", &csBaidTxnId)) {
DEBUGLOG(("  CheckKeywords:: baid_txn_id not found\n"));
			iRet = PD_ERR;
		} else {
DEBUGLOG(("  CheckKeywords:: baid_txn_id = [%s]\n", csBaidTxnId));
		}
	}
	
	// get statement details by baid txn id
	if (iRet == PD_OK) {
DEBUGLOG(("  CheckKeywords() call DBOLStatement::GetStmtDtlByBAIDTxnId()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLStatement", "GetStmtDtlByBAIDTxnId");
		iTmpRet = (unsigned long)(*DBObjPtr)(csBaidTxnId, hStmtDtl);
		if (iTmpRet != PD_OK) {
DEBUGLOG(("  CheckKeywords() call DBOLStatement::GetStmtDtlByBAIDTxnId() failed\n"));
			iRet = PD_ERR;
		} else {
			// format_id
			if (!GetField_CString(hStmtDtl, "format_id", &csTmp)) {
DEBUGLOG(("  CheckKeywords:: format_id not found\n"));
				iRet = PD_ERR;
			} else {
DEBUGLOG(("  CheckKeywords:: format_id = [%s]\n", csTmp));
			}

			// int_bank_code
			if (iRet == PD_OK) {
				if (!GetField_CString(hStmtDtl, "int_bank_code", &csTmp)) {
DEBUGLOG(("  CheckKeywords:: int_bank_code not found\n"));
					iRet = PD_ERR;
				} else {
DEBUGLOG(("  CheckKeywords:: int_bank_code = [%s]\n", csTmp));
					}
			}

			// acct_ccy
			if (iRet == PD_OK) {
				if (!GetField_CString(hStmtDtl, "txn_ccy", &csTmp)) {
DEBUGLOG(("  CheckKeywords:: txn_ccy not found\n"));
					iRet = PD_ERR;
				} else {
DEBUGLOG(("  CheckKeywords:: txn_ccy = [%s]\n", csTmp));
					PutField_CString(hStmtDtl, "acct_ccy", csTmp);
				}
			}

			if (iRet == PD_OK) {
			//POA
				PutField_CString(hStmtDtl, "bank_acct_type", PD_NATURE_PAYOUT);
			//OBP
				PutField_CString(hStmtDtl, "baid_txn_code", PD_OFFLINE_PAYOUT_TXN_CODE);
			}
		}
	}
	

	// get keywords
	if (iRet == PD_OK) {
DEBUGLOG(("  CheckKeywords() call DBOLStmtFormat::GetTxnCodeKeywordsSingle()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLStmtFormat", "GetTxnCodeKeywordsSingle");
		iTmpRet = (unsigned long)(*DBObjPtr)(hStmtDtl, rKeywords);
		if (iTmpRet != PD_FOUND) {
DEBUGLOG(("  CheckKeywords() call DBOLStmtFormat::GetTxnCodeKeywordsSingle() is not found\n"));
			iRet = PD_ERR;
		}
		else{
DEBUGLOG(("  CheckKeywords() call DBOLStmtFormat::GetTxnCodeKeywordsSingle() Found\n"));
			iRet = PD_OK;
		}
	}

	// check keywords
	if (iRet == PD_OK) {
DEBUGLOG(("  CheckKeywords() call BOOLBankStmt::CheckKeywords()\n"));
		BOObjPtr = CreateObj(BOPtr, "BOOLBankStmt", "CheckKeywords");
		iTmpRet = (unsigned long)(*BOObjPtr)(hStmtDtl, rKeywords);
		if (iTmpRet != PD_OK) {
DEBUGLOG(("  CheckKeywords() call BOOLBankStmt::CheckKeywords() failed\n"));
			iRet = PD_ERR;
		}
		else{
DEBUGLOG(("  CheckKeywords() call BOOLBankStmt::CheckKeywords() success\n"));
			iRet = PD_OK;
		
		}
	}
	
	
	// hash destroy
	hash_destroy(hStmtDtl);
	FREE_ME(hStmtDtl);
	// recordset destroy
	RecordSet_Destroy(rKeywords);
	FREE_ME(rKeywords);
	
	return iRet;

}


int GetStmtDateDiff(char *csPrevDateDiff, char *csNextDateDiff)
{
	int iRet = PD_ERR;
	int iDtlRet = PD_ERR;
	int iRuleId = 0;
	int iSubRuleId = 0;
	int iActionFilterId = 0;
	
	char* csActionType;
	char* csFilter;
	char* csOperator;
	char* csLeftOperand;
	char* csRightOperand;

	
	recordset_t *rGetAttribute;
	rGetAttribute = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rGetAttribute, 0);
	
	hash_t* hIn;
	hIn = (hash_t*)malloc(sizeof(hash_t));
	hash_init(hIn,0);
	
	hash_t* hMatchAction;
	hMatchAction = (hash_t*)malloc(sizeof(hash_t));
	hash_init(hMatchAction,0);
	
	hash_t* hGetAttri;
	
	
	
	/*OLStmtMatchEngine.pc :: GetStmtMatchEngine*/
	
	PutField_CString(hIn, "trigger_type", PD_TRIGGER_SYSTEM);
	PutField_CString(hIn, "input_channel", PD_CHANNEL_OMT);
	PutField_CString(hIn, "bank_acct_type", PD_NATURE_PAYOUT);
	PutField_CString(hIn, "baid_txn_code", PD_OFFLINE_PAYOUT_TXN_CODE);
	

	DBObjPtr = CreateObj(DBPtr,"DBOLStmtMatchEngine","GetStmtMatchEngine");
	iDtlRet = (unsigned long)(*DBObjPtr)(hIn, hMatchAction);
	if(iDtlRet == PD_OK){
DEBUGLOG(("  GetStmtDateDiff:: call DBOLStmtMatchEngine::GetStmtMatchEngine ret_code[%d] Success!!\n", iDtlRet));
		/*rule_id*/
		if(GetField_Int(hMatchAction, "rule_id", &iRuleId)){
DEBUGLOG(("  GetStmtDateDiff:: rule_id = [%d]\n", iRuleId));
			iRet = PD_OK;
		}
		else{
DEBUGLOG(("  GetStmtDateDiff:: rule_id is missing!!!\n"));
ERRLOG("ol_payout_recon_ignore_bank_match:: process_data:: GetStmtDateDiff() rule_id is missing!!!\n");
			iRet = PD_ERR;
		}
	}
	else{
DEBUGLOG(("  GetStmtDateDiff: call OLStmtMatchEngine::GetStmtMatchEngine Error!!\n"));
ERRLOG("ol_payout_recon_ignore_bank_match:: process_data:: GetStmtDateDiff:: call OLStmtMatchEngine::GetStmtMatchEngine Error!!\n");
		iRet = INT_ERR;
	}
	
	
	/*OLStmtMatchRuleGroup.pc :: GetStmtMatchRule*/
	if (iRet == PD_OK) {
		PutField_Int(hIn, "rule_id", iRuleId);
		DBObjPtr = CreateObj(DBPtr,"DBOLStmtMatchRuleGroup","GetStmtMatchRule");
		iDtlRet = (unsigned long)(*DBObjPtr)(hIn, rGetAttribute);
		if(iDtlRet == PD_OK){
DEBUGLOG(("  GetStmtDateDiff:: call DBOLStmtMatchRuleGroup::GetStmtMatchRule ret_code[%d] Success!!\n", iDtlRet));
			hGetAttri = RecordSet_GetFirst(rGetAttribute);
			while (hGetAttri) {
				/*sub_rule_id*/
				if(GetField_Int(hGetAttri, "sub_rule_id", &iSubRuleId)){
DEBUGLOG(("  GetStmtDateDiff:: sub_rule_id = [%d]\n", iSubRuleId));
					iRet = PD_OK;
				}
				else{
DEBUGLOG(("  GetStmtDateDiff:: sub_rule_id is missing!!!\n"));
ERRLOG("ol_payout_recon_ignore_bank_match:: process_data:: GetStmtDateDiff() sub_rule_id is missing!!!\n");
					iRet = PD_ERR;
				}
				hGetAttri = RecordSet_GetNext(rGetAttribute);
			}

		}
		else{
DEBUGLOG(("  GetStmtDateDiff: call OLStmtMatchRuleGroup::GetStmtMatchRule Error!!\n"));
ERRLOG("ol_payout_recon_ignore_bank_match:: process_data:: GetStmtDateDiff:: call OLStmtMatchRuleGroup::GetStmtMatchRule Error!!\n");
			iRet = INT_ERR;
		}
		
	}
	

	
	
	/*OLStmtMatchRule.pc :: GetStmtMatchSubRule*/
	if (iRet == PD_OK) {

		RecordSet_Destroy(rGetAttribute);
		recordset_init(rGetAttribute, 0);
		PutField_Int(hIn, "rule_id", iRuleId);
		PutField_Int(hIn, "sub_rule_id", iSubRuleId);
		
		DBObjPtr = CreateObj(DBPtr,"DBOLStmtMatchRule","GetStmtMatchSubRule");
		iDtlRet = (unsigned long)(*DBObjPtr)(hIn, rGetAttribute);
		
		if(iDtlRet == PD_OK){
DEBUGLOG(("  GetStmtDateDiff:: call DBOLStmtMatchRule::GetStmtMatchSubRule ret_code[%d] Success!!\n", iDtlRet));
			hGetAttri = RecordSet_GetFirst(rGetAttribute);
			while (hGetAttri) {
				/*action_type*/
				if(GetField_CString(hGetAttri, "action_type", &csActionType)){
DEBUGLOG(("  GetStmtDateDiff:: action_type = [%s]\n", csActionType));
					iRet = PD_OK;
				}
				else{
DEBUGLOG(("  GetStmtDateDiff:: action_type is missing!!!\n"));
ERRLOG("ol_payout_recon_ignore_bank_match:: process_data:: GetStmtDateDiff() action_type is missing!!!\n");
					iRet = PD_ERR;
				}
				/*action_filter_id*/
				if(iRet == PD_OK){
					if(GetField_Int(hGetAttri, "action_filter_id", &iActionFilterId)){
DEBUGLOG(("  GetStmtDateDiff:: action_filter_id = [%d]\n", iActionFilterId));
						iRet = PD_OK;
					}
					else{
DEBUGLOG(("  GetStmtDateDiff:: action_filter_id is missing!!!\n"));
ERRLOG("ol_payout_recon_ignore_bank_match:: process_data:: GetStmtDateDiff() action_filter_id is missing!!!\n");
						iRet = PD_ERR;
					}
				}
				hGetAttri = RecordSet_GetNext(rGetAttribute);
			}
		}
		else{
DEBUGLOG(("  GetStmtDateDiff: call OLStmtMatchRule::GetStmtMatchSubRule Error!!\n"));
ERRLOG("ol_payout_recon_ignore_bank_match:: process_data:: GetStmtDateDiff:: call OLStmtMatchRule::GetStmtMatchSubRule Error!!\n");
			iRet = INT_ERR;
		}
	}


	/*OLStmtMatchFilter.pc :: GetStmtMatchFilter*/
	
	if (iRet == PD_OK) {
		PutField_CString(hIn, "action_type", csActionType);
		PutField_Int(hIn, "action_filter_id", iActionFilterId);
		PutField_CString(hIn, "first_party", PD_BAID_TXN_PARTY);
		PutField_CString(hIn, "second_party", PD_PSP_TXN_PARTY);

		RecordSet_Destroy(rGetAttribute);
		recordset_init(rGetAttribute, 0);

		DBObjPtr = CreateObj(DBPtr,"DBOLStmtMatchFilter","GetStmtMatchFilter");
		iDtlRet = (unsigned long)(*DBObjPtr)(hIn, hIn, rGetAttribute);
		
		if(iDtlRet == PD_OK){
DEBUGLOG(("  GetStmtDateDiff:: call DBOLStmtMatchFilter::GetStmtMatchFilter ret_code[%d] Success!!\n", iDtlRet));
			hGetAttri = RecordSet_GetFirst(rGetAttribute);
			while (hGetAttri) {
				/*filter*/
				if(GetField_CString(hGetAttri, "filter", &csFilter)){
DEBUGLOG(("  GetStmtDateDiff:: filter = [%s]\n", csFilter));
					iRet = PD_OK;
				}
				else{
DEBUGLOG(("  GetStmtDateDiff:: filter is missing!!!\n"));
ERRLOG("ol_payout_recon_ignore_bank_match:: process_data:: GetStmtDateDiff() filter is missing!!!\n");
					iRet = PD_ERR;
				}
				
				if(!strcmp(csFilter, PD_PREV_STMT_DATE_FILTER)
				|| !strcmp(csFilter, PD_NEXT_STMT_DATE_FILTER)){
					/*operator*/
					if(iRet == PD_OK){
						if(GetField_CString(hGetAttri, "operator", &csOperator)){
DEBUGLOG(("  GetStmtDateDiff:: operator = [%s]\n", csOperator));
							iRet = PD_OK;
						}
						else{
DEBUGLOG(("  GetStmtDateDiff:: operator is missing!!!\n"));
ERRLOG("ol_payout_recon_ignore_bank_match:: process_data:: GetStmtDateDiff() operator is missing!!!\n");
							iRet = PD_ERR;
						}
					}
					/*left_operand*/
					if(iRet == PD_OK){
						if(GetField_CString(hGetAttri, "left_operand", &csLeftOperand)){
DEBUGLOG(("  GetStmtDateDiff:: left_operand = [%s]\n", csLeftOperand));
							iRet = PD_OK;
						}
						else{
DEBUGLOG(("  GetStmtDateDiff:: left_operand is missing!!!\n"));
ERRLOG("ol_payout_recon_ignore_bank_match:: process_data:: GetStmtDateDiff() left_operand is missing!!!\n");
							iRet = PD_ERR;
						}
					}
					/*right_operand*/	
					if(iRet == PD_OK){
						if(GetField_CString(hGetAttri, "right_operand", &csRightOperand)){
DEBUGLOG(("  GetStmtDateDiff:: right_operand = [%s]\n", csRightOperand));
							iRet = PD_OK;
						}
						else{
DEBUGLOG(("  GetStmtDateDiff:: right_operand is missing!!!\n"));
ERRLOG("ol_payout_recon_ignore_bank_match:: process_data:: GetStmtDateDiff() right_operand is missing!!!\n");
							iRet = PD_ERR;
						}
					}
					
					/*prev_stmt_date_diff*/
					if(!strcmp(csFilter, PD_PREV_STMT_DATE_FILTER)){
						sprintf(csPrevDateDiff, "%s %s %s", csLeftOperand, csOperator, csRightOperand);
DEBUGLOG(("  GetStmtDateDiff:: PrevDateDiff = [%s]\n", csPrevDateDiff));
					}
					
					/*next_stmt_date_diff*/
					if(!strcmp(csFilter, PD_NEXT_STMT_DATE_FILTER)){
						sprintf(csNextDateDiff, "%s %s %s", csLeftOperand, csOperator, csRightOperand);
DEBUGLOG(("  GetStmtDateDiff:: NextDateDiff = [%s]\n", csNextDateDiff));
					}
				}
				
				hGetAttri = RecordSet_GetNext(rGetAttribute);
				
			}	
		}
		else{
DEBUGLOG(("  GetStmtDateDiff: call OLStmtMatchFilter::GetStmtMatchFilter Error!!\n"));
ERRLOG("ol_payout_recon_ignore_bank_match:: process_data:: GetStmtDateDiff:: call OLStmtMatchFilter::GetStmtMatchFilter Error!!\n");
			iRet = INT_ERR;
		}
	}
	

	
	// hash destroy
	hash_destroy(hIn);
	FREE_ME(hIn);

	hash_destroy(hMatchAction);
	FREE_ME(hMatchAction);
	
	RecordSet_Destroy(rGetAttribute);
	FREE_ME(rGetAttribute);
	
	return iRet;
}




int batch_terminate(int argc, char *argv[])
{
	return SUCCESS;
}



/*eval ol_payout_recon_ignore_bank_match.exec -f $1 -t $2 -p $3 -q $4*/
int parse_arg(int argc, char **argv)
{
	char c;

	strcpy(csInCreateTsFr, "");
	strcpy(csInCreateTsTo, "");
	strcpy(csInProvId, "");
	strcpy(csInTrigSeq, "");

	if (argc < 9)
	{
DEBUGLOG(("- argc = [%d]\n", argc));
		return FAILURE;
	}

	while ((c = getopt(argc, argv, "f:t:p:q:")) != EOF)
	{
		switch (c)
		{
			case 'f':
				strcpy(csInCreateTsFr, optarg);
				break;
			case 't':
				strcpy(csInCreateTsTo, optarg);
				break;
			case 'p':
				strcpy(csInProvId, optarg);
				break;
			case 'q':
				strcpy(csInTrigSeq, optarg);
				break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(csInCreateTsFr, "") ||
		!strcmp(csInCreateTsTo, "") ||
		!strcmp(csInProvId, "") ||
		!strcmp(csInTrigSeq, "")
		)
		return FAILURE;

	return SUCCESS;
}
