
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
    "par_payout_reversal_handler.pc"
};


static unsigned int sqlctx = 1384802043;


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
   unsigned char  *sqhstv[20];
   unsigned long  sqhstl[20];
            int   sqhsts[20];
            short *sqindv[20];
            int   sqinds[20];
   unsigned long  sqharm[20];
   unsigned long  *sqharc[20];
   unsigned short  sqadto[20];
   unsigned short  sqtdso[20];
} sqlstm = {12,20};

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
"select fd_file_id ,fd_batch_id ,fd_seq_num ,fd_txn_id ,fd_merchant_ref ,fd_\
country ,fd_identity_id ,fd_account_num ,fd_account_name ,fd_bank_name ,fd_ba\
nk_code ,fd_branch ,fd_phone_num ,fd_province ,fd_city ,fd_payout_amount ,fd_\
request_amount ,fd_payout_currency ,fd_request_currency ,fh_file_pid  from pa\
yout_generated_file_dt ,payout_generated_file_hd where ((fd_upload_txn_id=:b0\
 and fd_file_id=fh_file_id) and fd_status=:b1)           ";

 static char *sq0002 = 
"select th_input_channel ,th_process_code ,th_process_type ,th_client_id ,th\
_net_ccy ,tp_txn_amount ,tp_txn_ccy ,tp_psp_id ,tp_service_fee ,td_txn_countr\
y  from txn_header ,txn_detail ,txn_psp_detail where ((th_txn_id=:b0 and th_t\
xn_id=td_txn_id) and th_txn_id=tp_txn_id)           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,440,0,9,655,0,0,2,2,0,1,0,1,9,0,0,1,3,0,0,
28,0,0,1,0,0,13,657,0,0,20,0,0,1,0,2,9,0,0,2,68,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
123,0,0,1,0,0,15,826,0,0,0,0,0,1,0,
138,0,0,1,0,0,15,836,0,0,0,0,0,1,0,
153,0,0,2,281,0,9,898,0,0,1,1,0,1,0,1,9,0,0,
172,0,0,2,0,0,13,900,0,0,10,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
4,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,
227,0,0,2,0,0,15,985,0,0,0,0,0,1,0,
242,0,0,2,0,0,15,1001,0,0,0,0,0,1,0,
257,0,0,3,0,0,17,1059,0,0,1,1,0,1,0,1,9,0,0,
276,0,0,3,0,0,21,1060,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/10/05              LokMan Chow

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlca.h>
#include <sqlcpr.h>
#include "common.h"
#include "internal.h"
#include "utilitys.h"
#include "dbutility.h"
#include "../batchcommon.h"
#include "par_payout_reversal_handler.h"
#include "pr_bo_funct.h"
#include "pr_par_funct.h"
#include "ObjPtr.h"
#include "dbutility.h"

char	cDebug;

OBJPTR(DB);

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

int GetFileDetailByUploadTxnId(const hash_t *hTxn, recordset_t* myRec);
int GetOrgTxnDetails(const char *csTxnId, recordset_t* myRec);
int UpdateByGenId(const hash_t *hRec);

int payout_reversal_handler(hash_t *hMyHash)
{
	int iRet = SUCCESS;
	int iTmpRet;

	hash_t          *hTxnHeader;

	recordset_t     *rRecordSet;
	hash_t          *hRec;

	char    *csTmp = NULL;
	double  dReqAmt = 0.0;
	double  dMerchantFee = 0.0;
	double  dMarkup = 0.0;
	int     iTmp = 0;
	int     iStatus = 0;

	char    *csMerchNmb = NULL;
	char    *csVNCRefNum = NULL;
	char    *csUploadTxnId = NULL;
	char    *csOrgTxnId= NULL;

	int     iRecExists = PD_FALSE;
	char    csTxnSeq[PD_TXN_SEQ_LEN+1];

	rRecordSet = (recordset_t *)malloc(sizeof(recordset_t));
	recordset_init(rRecordSet, 0);

	hash_t  *hContext, *hRequest, *hResponse;

	hTxnHeader = (hash_t *)malloc(sizeof(hash_t));
	hash_init (hTxnHeader, 0);

	hContext = (hash_t *)malloc(sizeof(hash_t));
	hRequest = (hash_t *)malloc(sizeof(hRequest));
	hResponse = (hash_t *)malloc(sizeof(hResponse));

        hash_init (hContext, 0);
        hash_init (hRequest, 0);
        hash_init (hResponse, 0);

	// Chk PH MID
	if (GetField_CString(hMyHash, "txn_merch_nmb", &csMerchNmb)) {
DEBUGLOG(("payout_reversal_handler: txn_merch_nmb [%s]\n", csMerchNmb));
	}
	else {
DEBUGLOG(("payout_reversal_handler: txn_merch_nmb missing!\n"));
		iRet = FAILURE;
	}

	rRecordSet = (recordset_t *)malloc(sizeof(recordset_t));

	recordset_init(rRecordSet, 0);
	if (iRet == SUCCESS) {

		if (ParMerchProfile_GetMerchant(csMerchNmb, rRecordSet) != PD_OK) {
DEBUGLOG(("payout_reversal_handler: ParMerchProfile.GetMerchant FAILED!\n"));
		} else {
DEBUGLOG(("payout_reversal_handler: ParMerchProfile.GetMerchant SUCC!\n"));

			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {

				if (GetField_CString(hRec, "service", &csTmp)) {
DEBUGLOG(("payout_reversal_handler: ParMerchProfile.GetMerchant service [%s]!\n", csTmp));
					PutField_CString(hMyHash, "service", csTmp);
				}

				if (GetField_CString(hRec, "merchant_id", &csTmp)) {
DEBUGLOG(("payout_reversal_handler: ParMerchProfile.GetMerchant merchant_id [%s]!\n", csTmp));
					PutField_CString(hMyHash, "merchant_id", csTmp);
				}

				if (GetField_CString(hRec, "client_id", &csTmp)) {
DEBUGLOG(("payout_reversal_handler: ParMerchProfile.GetMerchant client_id [%s]!\n", csTmp));
					PutField_CString(hMyHash, "merchant_client_id", csTmp);
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
	}
	RecordSet_Destroy(rRecordSet);



	// Chk if exists in txn_header
	if (iRet == SUCCESS) {
		if (GetField_CString(hMyHash, "txn_nmb", &csVNCRefNum)) {
DEBUGLOG(("payout_reversal_handler: txn_nmb [%s]\n", csVNCRefNum));
		}
		else {
DEBUGLOG(("payout_reversal_handler: txn_nmb not found!\n"));
			iRet = FAILURE;
		}
	}

	if (iRet == SUCCESS) {
		iTmpRet = ParTxnData_ChkExist(csVNCRefNum);

		if (iTmpRet == PD_FOUND) {
			iRecExists = PD_TRUE;

		} else if (iTmpRet == PD_NOT_FOUND) {
			iRecExists = PD_FALSE;

		} else {
DEBUGLOG(("payout_reversal_handler: ParTxnData_ChkExist FAILED!\n"));
			iRet = FAILURE;
		}
	}

////////if txn exist before, do nothing and return iRet
////////else add new txn

	if(iRet == SUCCESS &&
	   iRecExists != PD_TRUE){
		strcpy(csTxnSeq,prbo_GetNextMgtTxnSeq());
		//csTxnSeq = strdup((char* )prbo_GetNextMgtTxnSeq());
		PutField_CString(hMyHash,"txn_seq",csTxnSeq);
DEBUGLOG(("payout_reversal_handler: Generate (MGT) Txn Seq [%s]\n", csTxnSeq));

		PutField_CString(hTxnHeader, "txn_id", csTxnSeq);

		PutField_CString(hMyHash, "channel_code", "MGT");
		PutField_CString(hMyHash, "process_type", "0000");
		PutField_CString(hMyHash, "process_code", "000000");
		PutField_CString(hMyHash, "vnc_ref_num", csVNCRefNum);
		PutField_Int(hMyHash, "internal_code", 0);
		PutField_CString(hMyHash, "response_code", "0");

		iRet = format_data(hMyHash, hTxnHeader, hContext, hRequest);

		if (iRet == SUCCESS) {
			if (PayoutAddTxnLog(hContext, hRequest) == PD_OK) {
DEBUGLOG(("payout_reversal_handler:PayoutAddTxnLog  SUCC!\n"));

				//DBObjPtr = CreateObj(DBPtr,"DBParTxnData","UpdateHeaderVNCRef");
				if (UpdateHeaderVNCRef(hContext) == PD_OK) {
DEBUGLOG(("payout_reversal_handler:Deposit init record updated vnc_ref_num succ!\n"));
				}
				else {
DEBUGLOG(("payout_reversal_handler:Deposit init record updated vnc_ref_num fail!\n"));
					iRet = FAILURE;
				}

			}
			else {
DEBUGLOG(("payout_reversal_handler:PayoutAddTxnLog FAIL!\n"));
				iRet = FAILURE;
			}
		}

//////check merchant_upload_file_detail
		if(iRet == SUCCESS){
			recordset_init(rRecordSet, 0);
			if(GetPayoutDetailByAuxVncRefNum(csVNCRefNum,rRecordSet)==PD_OK){
				hRec = RecordSet_GetFirst(rRecordSet);
				while (hRec) {
					if(GetField_CString(hRec,"txn_id",&csUploadTxnId)){
						PutField_CString(hTxnHeader, "org_txn_id", csUploadTxnId);
						PutField_CString(hMyHash, "upload_txn_id", csUploadTxnId);
DEBUGLOG(("GetPayoutDetailByAuxVncRefNum txn_id = [%s]\n",csUploadTxnId));
					}
					if(GetField_CString(hRec,"batch_id",&csTmp)){
						PutField_CString(hMyHash, "batch_id", csTmp);
DEBUGLOG(("GetPayoutDetailByAuxVncRefNum batch_id = [%s]\n",csTmp));
					}
					if(GetField_Int(hRec,"seq_num",&iTmp)){
DEBUGLOG(("GetPayoutDetailByAuxVncRefNum seq_num = [%d]\n",iTmp));
					}
					if(GetField_Int(hRec,"status",&iStatus)){
DEBUGLOG(("GetPayoutDetailByAuxVncRefNum status = [%d]\n",iStatus));
					}
					if(GetField_CString(hRec,"country",&csTmp)){
						PutField_CString(hMyHash, "country", csTmp);
DEBUGLOG(("GetPayoutDetailByAuxVncRefNum country = [%s]\n",csTmp));
					}
					if(GetField_CString(hRec,"payout_ccy",&csTmp)){
						PutField_CString(hContext, "net_ccy", csTmp);
DEBUGLOG(("GetPayoutDetailByAuxVncRefNum payout_ccy = [%s]\n",csTmp));
					}
					if(GetField_CString(hRec,"request_ccy",&csTmp)){
						PutField_CString(hMyHash, "ccy", csTmp);
DEBUGLOG(("GetPayoutDetailByAuxVncRefNum request_ccy = [%s]\n",csTmp));
					}
					if(GetField_Double(hRec,"request_amount",&dReqAmt)){
						PutField_Double(hMyHash,"amount",dReqAmt);
DEBUGLOG(("GetPayoutDetailByAuxVncRefNum request_amount = [%lf]\n",dReqAmt));
					}
					if(GetField_CString(hRec,"merchant_fee_ccy",&csTmp)){
DEBUGLOG(("GetPayoutDetailByAuxVncRefNum merchant_fee_ccy = [%s]\n",csTmp));
					}
					if(GetField_Double(hRec,"merchant_fee",&dMerchantFee)){
						//PutField_Double(hMyHash,"fee",dMerchantFee);
DEBUGLOG(("GetPayoutDetailByAuxVncRefNum merchant_fee = [%lf]\n",dMerchantFee));
					}
	
					if(GetField_CString(hRec,"markup_ccy",&csTmp)){
						PutField_CString(hMyHash, "markup_ccy", csTmp);
DEBUGLOG(("GetPayoutDetailByAuxVncRefNum markup_ccy = [%s]\n",csTmp));
					}
					if(GetField_Double(hRec,"markup_amt",&dMarkup)){
						//PutField_Double(hMyHash,"markup_amt",dMarkup);
DEBUGLOG(("GetPayoutDetailByAuxVncRefNum markup_amt = [%lf]\n",dMarkup));
					}
	
					hRec = RecordSet_GetNext(rRecordSet);
				}
			}
			else{
DEBUGLOG(("payout_reversal_handler:GetPayoutDetailByAuxVncRefNum FAIL!\n"));
				iRet = FAILURE;
			}

			RecordSet_Destroy(rRecordSet);
		}

		//////handle balance
		if (iRet == SUCCESS) {
			PutField_Char(hMyHash,"response_mode",PD_REVERSED);
			iRet = handle_payout_balance(hMyHash);
		}

		if (iRet == SUCCESS)
			PutField_Int(hMyHash, "approved", PD_TRUE);
			iRet = format_data(hMyHash, hTxnHeader, hContext, hRequest);

		/////txn element
		if (iRet == SUCCESS) {
			PutField_CString(hMyHash,"amount_type",PD_CR);

                        //PutField_Int(hMyHash, "payout_bal_transfer_flag", PD_TRUE);
                        //PutField_Int(hMyHash, "payout_void_flag", PD_FALSE);

			iRet = add_txn_element(hMyHash);
		}


		if (iRet == SUCCESS) {
			PutField_Char(hContext,"status",PD_COMPLETE);
			PutField_Char(hContext,"ar_ind",PD_ACCEPT);
			//PutField_CString(hContext,"sub_status",PD_APPROVED_FOR_GENERATED);
			PutField_CString(hContext,"sub_status",PD_REFUND_APPROVED);

			if (prpar_UpdateTxnLog(hContext, hRequest, hResponse) == PD_OK) {
DEBUGLOG(("payout_reversal_handler:UpdateTxnLog SUCC\n"));
			} else {
DEBUGLOG(("payout_reversal_handler:UpdateTxnLog FAIL\n"));
				iRet = FAILURE;
			}
		}

		if (iRet == SUCCESS) {
                	iRet = UpdateApprovalTimestamp(hContext);
		}

		//FREE_ME(csTxnSeq);

	}
	else{
		//////do nothing
	}


//////////////////////////////////////////
////////////////handle VOG////////////////
//////////////////////////////////////////

	double	dTmp = 0.0;
	int	iCnt = 0;
	char	csDate[PD_DATE_LEN+1];
	char	csTime[PD_TIME_LEN+1];
	char	*csTxnDateTime;
	hash_t  *hTxn;
	hTxn= (hash_t *)malloc(sizeof(hash_t));
	hash_init (hTxn, 0);
	hash_t  *hOrgGenTxn;
	hOrgGenTxn= (hash_t *)malloc(sizeof(hash_t));
	hash_init (hOrgGenTxn, 0);

        hash_init (hContext, 0);
        hash_init (hRequest, 0);

	if (iRet == SUCCESS){ //&&
	    //iStatus==PAYOUT_MASTER_TRANSACTION_GENERATED) {

		///find org_gen_txn_id
		recordset_init(rRecordSet, 0);
		if(GetFileDetailByUploadTxnId(hMyHash,rRecordSet)==PD_OK){
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if(GetField_CString(hRec,"txn_id",&csOrgTxnId)){
					PutField_CString(hContext,"org_txn_seq",csOrgTxnId);
					PutField_CString(hOrgGenTxn,"txn_id",csOrgTxnId);
DEBUGLOG(("GetFileDetailByUploadTxnId org_gen_txn_id = [%s]\n",csOrgTxnId));
					iCnt ++;
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}

		}
		if(iCnt==0){
			iRet = PD_SKIP_OK;
DEBUGLOG(("payout_reversal_handler:GetFileDetailByUploadTxnId Not Found.....Skip VOG......\n"));
		}
		RecordSet_Destroy(rRecordSet);

		//// Not handle VOG /////
		iRet = PD_SKIP_OK;

		if(iRet==SUCCESS){
			//get org txn details
			recordset_init(rRecordSet, 0);
			if(GetOrgTxnDetails(csOrgTxnId,rRecordSet)==PD_OK){
				hRec = RecordSet_GetFirst(rRecordSet);
				while (hRec) {
					if(GetField_CString(hRec,"channel_code",&csTmp)){
						PutField_CString(hContext,"channel_code",csTmp);
					}
					if(GetField_CString(hRec,"process_type",&csTmp)){
						PutField_CString(hRequest,"process_type",csTmp);
					}
					if(GetField_CString(hRec,"process_code",&csTmp)){
						PutField_CString(hRequest,"process_code",csTmp);
					}
					if(GetField_CString(hRec,"client_id",&csTmp)){
						PutField_CString(hContext,"client_id",csTmp);
					}
					if(GetField_Double(hRec,"txn_amt",&dTmp)){
						PutField_Double(hContext,"dst_net_amt",dTmp);
						PutField_Double(hContext,"amount",dTmp);
					}
					if(GetField_CString(hRec,"net_ccy",&csTmp)){
						PutField_CString(hContext,"net_ccy",csTmp);
					}
					if(GetField_CString(hRec,"txn_ccy",&csTmp)){
						PutField_CString(hRequest,"txn_ccy",csTmp);
						PutField_CString(hContext,"to_ccy",csTmp);
						PutField_CString(hContext,"ccy",csTmp);
					}
					if(GetField_CString(hRec,"txn_country",&csTmp)){
						PutField_CString(hRequest,"txn_country",csTmp);
						PutField_CString(hContext,"country",csTmp);
					}
					if(GetField_CString(hRec,"psp_id",&csTmp)){
						PutField_CString(hContext,"psp_id",csTmp);
					}
					if(GetField_Double(hRec,"service_fee",&dTmp)){
						////???? return psp fee????
						//PutField_Double(hContext,"precal_fee",dTmp);
						//PutField_Double(hContext,"fee",dTmp);
					}

					hRec = RecordSet_GetNext(rRecordSet);
				}
			}
			else{
				iRet = FAILURE;
DEBUGLOG(("payout_reversal_handler:GetOrgTxnDetails Failed\n"));
			}
		}

		if(iRet== SUCCESS){
			///generate new txn_id
			///add txn log
			//csTxnSeq = strdup((char* )prbo_GetNextMgtTxnSeq());
			strcpy(csTxnSeq,prbo_GetNextMgtTxnSeq());
			PutField_CString(hContext,"txn_seq",csTxnSeq);
			PutField_CString(hTxn,"txn_seq",csTxnSeq);
			PutField_CString(hOrgGenTxn,"aux_txn_id",csTxnSeq);
DEBUGLOG(("payout_reversal_handler: Generate (MGT) Txn Seq [%s]\n", csTxnSeq));

			PutField_CString(hContext,"txn_code",PD_PAYOUT_VOID_PSP);
			PutField_Int(hContext, "internal_code", 0);
			PutField_CString(hContext, "response_code", "0");
			PutField_CString(hContext, "vnc_ref_num", csVNCRefNum);
			PutField_CString(hContext,"desc","Payout Refund(PSP)");
			if (GetField_CString(hMyHash, "post_date", &csTmp)) {
				PutField_CString(hContext, "PHDATE", csTmp);
			}
			if (GetField_CString(hMyHash, "local_tm_date", &csTmp)) {
				PutField_CString(hContext, "local_tm_date", csTmp);
			}
			if (GetField_CString(hMyHash, "local_tm_time", &csTmp)) {
				PutField_CString(hContext, "local_tm_time", csTmp);
			}
			if (GetField_CString(hMyHash, "txn_date", &csTxnDateTime)) {
				PutField_CString(hRequest, "transmission_datetime", csTxnDateTime);

				csDate[0] = '\0';
				csTime[0] = '\0';

				strncpy(csDate, csTxnDateTime, PD_DATE_LEN);
				strncpy(csTime, csTxnDateTime + PD_DATE_LEN, PD_TIME_LEN);

				csDate[PD_DATE_LEN] = '\0';
				csTime[PD_TIME_LEN] = '\0';

				PutField_CString(hRequest, "tm_date", csDate);
				PutField_CString(hRequest, "tm_time", csTime);
				PutField_CString(hContext, "txn_date", csDate);
				PutField_CString(hContext, "approval_date", csDate);
			}

			if (PayoutAddTxnLog(hContext, hRequest) == PD_OK) {
DEBUGLOG(("payout_reversal_handler:PayoutAddTxnLog  SUCC!\n"));

                                if (UpdateHeaderVNCRef(hContext) == PD_OK) {
DEBUGLOG(("payout_reversal_handler:Deposit init record updated vnc_ref_num succ!\n"));
                                }
                                else {
DEBUGLOG(("payout_reversal_handler:Deposit init record updated vnc_ref_num fail!\n"));
                                        iRet = FAILURE;
                                }

                        }
                        else {
DEBUGLOG(("payout_reversal_handler:PayoutAddTxnLog FAIL!\n"));
                                iRet = FAILURE;
                        }

			if(iRet==SUCCESS){
DEBUGLOG(("payout_reversal_handler::Call DBTxnPspDetail:Add\n"));
                        	DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Add");
                        	if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK){
                                	iRet = FAILURE;
DEBUGLOG(("payout_reversal_handler::DBTxnPspDetail:Add Failed\n"));
                        	}
			}
		}

		if(iRet==SUCCESS){
			///handle psp balance
			PutField_Char(hContext,"response_mode",PD_REVERSED);
			PutField_Char(hContext,"party_type",PD_TYPE_PSP);
			if (prbo_UpdatePayoutAmount(hContext) == PD_OK) {
				if (GetField_Double(hContext, "psp_total_float", &dTmp)) {
					PutField_Double(hTxn,"total_float",dTmp);
DEBUGLOG(("UpdatePayoutAmount:total_float [%lf]!\n", dTmp));
				}
				if (GetField_Double(hContext, "psp_balance", &dTmp)) {
					PutField_Double(hTxn,"bal",dTmp);
DEBUGLOG(("UpdatePayoutAmount:psp_balance[%lf]!\n", dTmp));
				}
				if (GetField_Double(hContext, "psp_total_hold", &dTmp)) {
					PutField_Double(hTxn,"total_hold",dTmp);
DEBUGLOG(("UpdatePayoutAmount:total_hold [%lf]!\n", dTmp));
				}
			}
			else{
				iRet = FAILURE;
DEBUGLOG(("payout_reversal_handler::UpdatePayoutAmount Failed\n"));
			}
		}
		
		if(iRet==SUCCESS){
			///add elements
			PutField_CString(hContext,"amount_type",PD_CR);
			PutField_Char(hContext,"party_type",PD_TYPE_PSP);
			if(add_txn_element(hContext)!=SUCCESS){
				iRet = FAILURE;
DEBUGLOG(("payout_reversal_handler::add_txn_element Failed\n"));
			}
		}

		if(iRet==SUCCESS){
			///update txn log
			PutField_Char(hTxn,"status",PD_COMPLETE);
			PutField_Char(hTxn,"ar_ind",PD_ACCEPT);
			DBObjPtr = CreateObj(DBPtr,"DBTransaction","Update");
			if((unsigned long) ((*DBObjPtr)(hTxn))!=PD_OK){
				iRet = FAILURE;
DEBUGLOG(("payout_reversal_handler::DBTransaction:Update Failed\n"));
			}

			if(iRet==SUCCESS){
DEBUGLOG(("payout_reversal_handler::Call DBTxnPspDetail:Update\n"));
				DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Update");
				if((unsigned long) ((*DBObjPtr)(hTxn))!=PD_OK){
					iRet = FAILURE;
DEBUGLOG(("payout_reversal_handler::DBTxnPspDetail:Update Failed\n"));
				}
			}
		}

		if(iRet==SUCCESS){
			///update payout generated file detail status
			PutField_Int(hOrgGenTxn,"status",PAYOUT_MASTER_TRANSACTION_REVERSED);
			if(UpdateByGenId(hOrgGenTxn)!=PD_OK){
				iRet = FAILURE;
DEBUGLOG(("payout_reversal_handler::UpdateByGenId Failed\n"));
			}
		}		

	}

	if(iRet==PD_SKIP_OK)
		iRet = SUCCESS;

	if (iRet == SUCCESS) {
DEBUGLOG(("payout_reversal_handler:UpdateProcessResult\n"));
		if(iRecExists == PD_TRUE)
			iRet = UpdateProcessResult(hMyHash, "SKIP");
		else
			iRet = UpdateProcessResult(hMyHash, "COMPLETE");
	}

	hash_destroy(hTxnHeader);
        FREE_ME(hTxnHeader);

        hash_destroy(hContext);
        hash_destroy(hRequest);
        hash_destroy(hResponse);

        FREE_ME(hTxn);
        FREE_ME(hOrgGenTxn);
        FREE_ME(hContext);
        FREE_ME(hRequest);
        FREE_ME(hResponse);

        FREE_ME(rRecordSet);

DEBUGLOG(("payout_reversal_handler: iRet = [%d]\n",iRet));
	return iRet;
}



int GetFileDetailByUploadTxnId(const hash_t *hTxn, recordset_t* myRec)
{
        hash_t *myHash;
        char    csBatchId[PD_TXN_SEQ_LEN+1];
        char*   csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO getfiledetailbytxnid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_upload_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_upload_txn_id;

                int             hv_status;

                /* varchar         v_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_file_id;

                unsigned long   v_batch_id;
                int             v_seq_num;
                /* varchar         v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

                /* varchar         v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

                /* varchar         v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

                /* varchar         v_identity_id[PD_IDENTITY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_identity_id;

                /* varchar         v_account_num[PD_AC_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_num;

                /* varchar         v_account_name[PD_ACC_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_account_name;

                /* varchar         v_bank_name[PD_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_name;

                /* varchar         v_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

                /* varchar         v_branch[PD_BANK_BRANCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_branch;

                /* varchar         v_phone_num[PD_MOBILE_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_phone_num;

                /* varchar         v_province[PD_PROVINCE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_province;

                /* varchar         v_city[PD_CITY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_city;

                /* varchar         v_payout_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_payout_ccy;

                /* varchar         v_request_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_request_ccy;

                double          v_payout_amount;
                double          v_request_amount;
                /* varchar         v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;


                short           ind_file_id = -1;
                short           ind_batch_id = -1;
                short           ind_seq_num = -1;
                short           ind_txn_id = -1;
                short           ind_merchant_ref = -1;
                short           ind_country = -1;
                short           ind_identity_id = -1;
                short           ind_account_num = -1;
                short           ind_account_name = -1;
                short           ind_bank_name = -1;
                short           ind_bank_code = -1;
                short           ind_branch = -1;
                short           ind_phone_num = -1;
                short           ind_province = -1;
                short           ind_city = -1;
                short           ind_payout_ccy = -1;
                short           ind_request_ccy = -1;
                short           ind_payout_amount = -1;
                short           ind_request_amount = -1;
                short           ind_psp_id= -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_status = PAYOUT_MASTER_TRANSACTION_GENERATED;
        if(GetField_CString(hTxn,"upload_txn_id",&csTmp)){
                hv_upload_txn_id.len = strlen(csTmp);
                memcpy(hv_upload_txn_id.arr,csTmp,hv_upload_txn_id.len);
DEBUGLOG(("GetFileDetailByUploadTxnId upload_txn_id = [%.*s]\n",hv_upload_txn_id.len,hv_upload_txn_id.arr));
        }
/* EXEC SQL DECLARE c_cursor_getfiledetailbytxnid CURSOR FOR
                select  fd_file_id,
                        fd_batch_id,
                        fd_seq_num,
                        fd_txn_id,
                        fd_merchant_ref,
                        fd_country,
                        fd_identity_id,
                        fd_account_num,
                        fd_account_name,
                        fd_bank_name,
                        fd_bank_code,
                        fd_branch,
                        fd_phone_num,
                        fd_province,
                        fd_city,
                        fd_payout_amount,
                        fd_request_amount,
                        fd_payout_currency,
                        fd_request_currency,
                        fh_file_pid
                from    payout_generated_file_dt,
                        payout_generated_file_hd
                where   fd_upload_txn_id=:hv_upload_txn_id
                and     fd_file_id = fh_file_id
                and     fd_status =:hv_status; */ 

        /* EXEC SQL OPEN  c_cursor_getfiledetailbytxnid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
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
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_upload_txn_id;
        sqlstm.sqhstl[0] = (unsigned long )18;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode < 0) goto getfiledetailbytxnid_error;
}


        do{
                /* EXEC SQL FETCH c_cursor_getfiledetailbytxnid
                INTO
                        :v_file_id:ind_file_id,
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
                        :v_psp_id:ind_psp_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 20;
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
                sqlstm.sqhstv[0] = (unsigned char  *)&v_file_id;
                sqlstm.sqhstl[0] = (unsigned long )18;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_file_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_batch_id;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
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
                sqlstm.sqhstl[9] = (unsigned long )53;
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
                sqlstm.sqhstl[11] = (unsigned long )103;
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
                sqlstm.sqhstl[13] = (unsigned long )53;
                sqlstm.sqhsts[13] = (         int  )0;
                sqlstm.sqindv[13] = (         short *)&ind_province;
                sqlstm.sqinds[13] = (         int  )0;
                sqlstm.sqharm[13] = (unsigned long )0;
                sqlstm.sqadto[13] = (unsigned short )0;
                sqlstm.sqtdso[13] = (unsigned short )0;
                sqlstm.sqhstv[14] = (unsigned char  *)&v_city;
                sqlstm.sqhstl[14] = (unsigned long )53;
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
                sqlstm.sqhstv[19] = (unsigned char  *)&v_psp_id;
                sqlstm.sqhstl[19] = (unsigned long )13;
                sqlstm.sqhsts[19] = (         int  )0;
                sqlstm.sqindv[19] = (         short *)&ind_psp_id;
                sqlstm.sqinds[19] = (         int  )0;
                sqlstm.sqharm[19] = (unsigned long )0;
                sqlstm.sqadto[19] = (unsigned short )0;
                sqlstm.sqtdso[19] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto getfiledetailbytxnid_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);
/*file_id*/
                if(ind_file_id>=0){
                        v_file_id.arr[v_file_id.len]='\0';
                        PutField_CString(myHash,"file_id",(const char*)v_file_id.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId file_id= [%s]\n",v_file_id.arr));
                }


/*batch_id*/
                if(ind_batch_id>=0){
                        sprintf(csBatchId,"%ld",v_batch_id);
                        PutField_CString(myHash,"batch_id",csBatchId);
DEBUGLOG(("GetFileDetailByUploadTxnId batch_id= [%s]\n",csBatchId));
                }

/*seq_num*/
                if(ind_seq_num>=0){
                        PutField_Int(myHash,"seq_num",v_seq_num);
DEBUGLOG(("GetFileDetailByUploadTxnId seq_num= [%d]\n",v_seq_num));
                }


/*txn_id*/
                if(ind_txn_id>=0){
                        v_txn_id.arr[v_txn_id.len]='\0';
                        PutField_CString(myHash,"txn_id",(const char*)v_txn_id.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId txn_id= [%s]\n",v_txn_id.arr));
                }

/*merchant_ref*/
                if(ind_merchant_ref>=0){
                        v_merchant_ref.arr[v_merchant_ref.len]='\0';
                        PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId merchant_ref= [%s]\n",v_merchant_ref.arr));
                }
/*country*/
                if(ind_country>=0){
                        v_country.arr[v_country.len]='\0';
                        PutField_CString(myHash,"txn_country",(const char*)v_country.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId country= [%s]\n",v_country.arr));
                }

/*identity_id*/
                if(ind_identity_id>=0){
                        v_identity_id.arr[v_identity_id.len]='\0';
                        PutField_CString(myHash,"identity_id",(const char*)v_identity_id.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId identity_id= [%s]\n",v_identity_id.arr));
                }

/*account_num*/
                if(ind_account_num>=0){
                        v_account_num.arr[v_account_num.len]='\0';
                        PutField_CString(myHash,"account_num",(const char*)v_account_num.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId account_num= [%s]\n",v_account_num.arr));
                }

/*account_name*/
                if(ind_account_name>=0){
                        v_account_name.arr[v_account_name.len]='\0';
                        PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId account_name= [%s]\n",v_account_name.arr));
                }

/*bank_name*/
                if(ind_bank_name>=0){
                        v_bank_name.arr[v_bank_name.len]='\0';
                        PutField_CString(myHash,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId bank_name= [%s]\n",v_bank_name.arr));
        }
/*bank_code*/
                if(ind_bank_code>=0){
                        v_bank_code.arr[v_bank_code.len]='\0';
                        PutField_CString(myHash,"bank_code",(const char*)v_bank_code.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId bank_code= [%s]\n",v_bank_code.arr));
                }

/*branch*/
                if(ind_branch>=0){
                        v_branch.arr[v_branch.len]='\0';
                        PutField_CString(myHash,"branch",(const char*)v_branch.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId branch= [%s]\n",v_branch.arr));
                }

/*phone_num*/
                if(ind_phone_num>=0){
                        v_phone_num.arr[v_phone_num.len]='\0';
                        PutField_CString(myHash,"phone_num",(const char*)v_phone_num.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId phone_num= [%s]\n",v_phone_num.arr));
                }

/*province*/
                if(ind_province>=0){
                        v_province.arr[v_province.len]='\0';
                        PutField_CString(myHash,"province",(const char*)v_province.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId province= [%s]\n",v_province.arr));
                }

/*city*/
                if(ind_city>=0){
                        v_city.arr[v_city.len]='\0';
                        PutField_CString(myHash,"city",(const char*)v_city.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId city= [%s]\n",v_city.arr));
                }
/*payout_currency*/
                if(ind_payout_ccy>=0){
                        v_payout_ccy.arr[v_payout_ccy.len]='\0';
                        PutField_CString(myHash,"payout_ccy",(const char*)v_payout_ccy.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId payout_ccy= [%s]\n",v_payout_ccy.arr));
                }

/*request_currency*/
                if(ind_request_ccy>=0){
                        v_request_ccy.arr[v_request_ccy.len]='\0';
                        PutField_CString(myHash,"request_ccy",(const char*)v_request_ccy.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId request_ccy= [%s]\n",v_request_ccy.arr));
                }

/*payout_amount*/
                if(ind_payout_amount>=0){
                        PutField_Double(myHash,"payout_amount",v_payout_amount);
DEBUGLOG(("GetFileDetailByUploadTxnId payout_amount = [%lf]\n",v_payout_amount));
                }

/*request_amount*/
                if(ind_request_amount>=0){
                        PutField_Double(myHash,"request_amount",v_request_amount);
DEBUGLOG(("GetFileDetailByUploadTxnId request_amount = [%lf]\n",v_request_amount));
                }

/*psp_id*/
                if(ind_psp_id>=0){
                        v_psp_id.arr[v_psp_id.len]='\0';
                        PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId psp_id = [%s]\n",v_psp_id.arr));
                }

                RecordSet_Add(myRec,myHash);

        }while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getfiledetailbytxnid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 20;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )123;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getfiledetailbytxnid_error;
}



DEBUGLOG(("GetFileDetailByUploadTxnId Normal Exit\n"));
        return  PD_OK;

getfiledetailbytxnid_error:
DEBUGLOG(("getfiledetailbytxnid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("PayoutGeneratedFileDT_Get: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getfiledetailbytxnid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 20;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )138;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;

}

int GetOrgTxnDetails(const char *csTxnId, recordset_t* myRec)
{
	hash_t *myHash;
        int     iCnt = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO getorgdetails_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


                /* varchar         v_client_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_client_id;

                /* varchar         v_net_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_net_ccy;

                /* varchar         v_channel_code[PD_CHANNEL_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_channel_code;

                /* varchar         v_process_code[PD_PROCESS_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_process_code;

                /* varchar         v_process_type[PD_PROCESS_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_process_type;

                /* varchar         v_txn_ccy[PD_CCY_ID_LEN+ 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

                /* varchar         v_txn_country[PD_COUNTRY_LEN+ 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_txn_country;

                /* varchar         v_psp_id[PD_PSP_ID_LEN+ 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

                double          v_txn_amt;
                double          v_service_fee;

                short           ind_client_id = -1;
                short           ind_txn_amt = -1;
                short           ind_service_fee = -1;
                short           ind_net_ccy = -1;
                short           ind_channel_code = -1;
                short           ind_process_code= -1;
                short           ind_process_type= -1;
                short           ind_txn_ccy= -1;
                short           ind_txn_country= -1;
                short           ind_psp_id= -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_id.len = strlen(csTxnId);
        memcpy(hv_txn_id.arr,csTxnId,hv_txn_id.len);
DEBUGLOG(("GetOrgTxnDetails txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

	/* EXEC SQL DECLARE c_cursor_getorgdetails CURSOR FOR
                select th_input_channel,
                       th_process_code,
                       th_process_type,
                       th_client_id,
                       th_net_ccy,
                       tp_txn_amount,
                       tp_txn_ccy,
                       tp_psp_id,
                       tp_service_fee,
		       td_txn_country
                  from txn_header,
		       txn_detail,
		       txn_psp_detail
                 where th_txn_id = :hv_txn_id
		 and   th_txn_id = td_txn_id
		 and   th_txn_id = tp_txn_id; */ 

	
	/* EXEC SQL OPEN c_cursor_getorgdetails; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )153;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_txn_id;
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
 if (sqlca.sqlcode < 0) goto getorgdetails_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getorgdetails
                INTO
                        :v_channel_code:ind_channel_code,
                        :v_process_code:ind_process_code,
                        :v_process_type:ind_process_type,
                        :v_client_id:ind_client_id,
                        :v_net_ccy:ind_net_ccy,
                        :v_txn_amt:ind_txn_amt,
                        :v_txn_ccy:ind_txn_ccy,
                        :v_psp_id:ind_psp_id,
                        :v_service_fee:ind_service_fee,
                        :v_txn_country:ind_txn_country; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 20;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )172;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_channel_code;
                sqlstm.sqhstl[0] = (unsigned long )6;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_channel_code;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_process_code;
                sqlstm.sqhstl[1] = (unsigned long )9;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_process_code;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_process_type;
                sqlstm.sqhstl[2] = (unsigned long )7;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_process_type;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_client_id;
                sqlstm.sqhstl[3] = (unsigned long )13;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_client_id;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_net_ccy;
                sqlstm.sqhstl[4] = (unsigned long )6;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_net_ccy;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_txn_amt;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_txn_amt;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_txn_ccy;
                sqlstm.sqhstl[6] = (unsigned long )6;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_txn_ccy;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_psp_id;
                sqlstm.sqhstl[7] = (unsigned long )13;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_psp_id;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_service_fee;
                sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_service_fee;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_txn_country;
                sqlstm.sqhstl[9] = (unsigned long )5;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_txn_country;
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
                if (sqlca.sqlcode < 0) goto getorgdetails_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		iCnt++;

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

                if (ind_client_id >= 0) {
                        v_client_id.arr[v_client_id.len] ='\0';
                        PutField_CString(myHash,"client_id",(const char*)v_client_id.arr);
DEBUGLOG(("GetOrgTxnDetails client_id = [%s]\n",v_client_id.arr));
                }

                if (ind_process_code >= 0) {
                        v_process_code.arr[v_process_code.len] ='\0';
                        PutField_CString(myHash,"process_code",(const char*)v_process_code.arr);
DEBUGLOG(("GetOrgTxnDetails process_code = [%s]\n",v_process_code.arr));
                }

		if (ind_process_type >= 0) {
                        v_process_type.arr[v_process_type.len] ='\0';
                        PutField_CString(myHash,"process_type",(const char*)v_process_type.arr);
DEBUGLOG(("GetOrgTxnDetails process_type = [%s]\n",v_process_type.arr));
                }

                if (ind_txn_amt < 0)
                        v_txn_amt = 0.0;
                PutField_Double(myHash,"txn_amt",v_txn_amt);
DEBUGLOG(("GetOrgTxnDetails txn_amt = [%f]\n",v_txn_amt));

                if (ind_service_fee< 0)
                        v_service_fee= 0.0;
                PutField_Double(myHash,"service_fee",v_service_fee);
DEBUGLOG(("GetOrgTxnDetails service_fee = [%f]\n",v_service_fee));

                if (ind_txn_country>= 0) {
                        v_txn_country.arr[v_txn_country.len] ='\0';
                        PutField_CString(myHash,"txn_country",(const char*)v_txn_country.arr);
DEBUGLOG(("GetOrgTxnDetails txn_country = [%s]\n",v_txn_country.arr));
                }

                if (ind_txn_ccy >= 0) {
                        v_txn_ccy.arr[v_txn_ccy.len] ='\0';
                        PutField_CString(myHash,"txn_ccy",(const char*)v_txn_ccy.arr);
DEBUGLOG(("GetOrgTxnDetails txn_ccy = [%s]\n",v_txn_ccy.arr));
                }

                if (ind_net_ccy >= 0) {
                        v_net_ccy.arr[v_net_ccy.len] ='\0';
                        PutField_CString(myHash,"net_ccy",(const char*)v_net_ccy.arr);
DEBUGLOG(("GetOrgTxnDetails net_ccy = [%s]\n",v_net_ccy.arr));
                }

		if (ind_channel_code >= 0) {
                        v_channel_code.arr[v_channel_code.len] ='\0';
                        PutField_CString(myHash,"channel_code",(const char*)v_channel_code.arr);
DEBUGLOG(("GetOrgTxnDetails channel_code = [%s]\n",v_channel_code.arr));
                }

		if (ind_psp_id>= 0) {
                        v_psp_id.arr[v_psp_id.len] ='\0';
                        PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetOrgTxnDetails psp_id = [%s]\n",v_psp_id.arr));
                }


		RecordSet_Add(myRec,myHash);
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getorgdetails; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 20;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )227;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getorgdetails_error;
}




        if (iCnt > 0 ) {
DEBUGLOG(("GetOrgTxnDetails Normal Exit\n"));
                return  PD_OK;
        }
        else {
DEBUGLOG(("GetOrgTxnDetails Normal Exit, Not Found\n"));
                return PD_ERR;
        }

getorgdetails_error:
DEBUGLOG(("getorgdetails_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getorgdetails; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 20;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )242;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int UpdateByGenId(const hash_t *hRec)
{
        char*   csBuf;
        char*   csGenId;
        int     iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO updatebygen_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateByGenId: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update payout_generated_file_dt set fd_update_timestamp = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        if(GetField_CString(hRec,"txn_id",&csGenId)){
DEBUGLOG(("UpdateByGenId:txn_id = [%s]\n",csGenId));
        }
        else{
                FREE_ME(csBuf);
DEBUGLOG(("UpdateByGenId txn_id not found\n"));
                return INT_ERR;
        }

        if(GetField_Int(hRec,"status",&iTmp)){
DEBUGLOG(("UpdateByGenId: status = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",fd_status = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	if(GetField_CString(hRec,"aux_txn_id",&csBuf)){
DEBUGLOG(("UpdateByGenId: aux_txn_id = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",fd_aux_txn_id = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	strcat((char*)hv_dynstmt.arr, " WHERE fd_txn_id= '");
        strcat((char*)hv_dynstmt.arr, csGenId);
        strcat((char*)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));


        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 20;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )257;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
        sqlstm.sqhstl[0] = (unsigned long )1026;
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
        if (sqlca.sqlcode < 0) goto updatebygen_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 20;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )276;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto updatebygen_error;
}



        FREE_ME(csBuf);

DEBUGLOG(("UpdateByGenId Normal Exit\n"));
        return PD_OK;

updatebygen_error:
DEBUGLOG(("updatebygen_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("PayoutGeneratedFileDT_UpdateByGenId: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}
