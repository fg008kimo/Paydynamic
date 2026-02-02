
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
    "par_payout_handler_2.pc"
};


static unsigned int sqlctx = 648322715;


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
5,0,0,1,0,0,17,337,0,0,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,21,338,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/12/18              Virginia Yun

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
#include "par_payout_handler_2.h"
#include "pr_bo_funct.h"
#include "pr_par_funct.h"
#include "pr_par_funct_2.h"
#include "ObjPtr.h"
#include "dbutility.h"

char	cDebug;

OBJPTR(DB);
OBJPTR(Txn);

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


int	UpdateMerchantUploadFileHeader(const hash_t *hRls);
int	AssignValue(hash_t *hMyHash, hash_t *hContext, hash_t *hRequest);

int payout_handler_2(hash_t *hMyHash)
{
	int iRet = SUCCESS;
	//int iTmpRet;

	hash_t          *hTxnHeader;

	recordset_t     *rRecordSet;
	hash_t          *hRec;

	char    *csTmp = NULL;
	double  dTmp = 0.0;
	//double  dReqAmt = 0.0;
	//double  dMerchantFee = 0.0;
	//double  dMarkup = 0.0;
	int     iTmp = 0;

	//char    *csMerchNmb = NULL;
	char    *csVNCRefNum = NULL;

	int     iRecExists = PD_FALSE;
	//char    *csTxnSeq;

	hash_t  *hContext, *hRequest, *hResponse;

	hTxnHeader = (hash_t *)malloc(sizeof(hash_t));
	hash_init (hTxnHeader, 0);

	hContext = (hash_t *)malloc(sizeof(hash_t));
	hRequest = (hash_t *)malloc(sizeof(hRequest));
	hResponse = (hash_t *)malloc(sizeof(hResponse));

        hash_init (hContext, 0);
        hash_init (hRequest, 0);
        hash_init (hResponse, 0);

	rRecordSet = (recordset_t *)malloc(sizeof(recordset_t));

	// Chk PH MID
	iRet = AssignTxnRecordDetail(hMyHash);

	// Chk if exists in txn_header
	if (iRet == SUCCESS) {
		GetField_Int(hMyHash, "record_exists", &iRecExists);

		if (iRecExists == PD_TRUE) {
DEBUGLOG(("payout_handler_2: unexpected record exists!\n"));
			iRet = FAILURE;
		}
	}

////////if txn exist before, do nothing and return iRet
////////else add new txn

	if(iRet == SUCCESS) {
		hash_destroy(hContext);
		hash_destroy(hRequest);

        	hash_init (hContext, 0);
	        hash_init (hRequest, 0);

		iRet = AssignTxnRecordDetail(hMyHash);


		GetField_CString(hMyHash, "txn_nmb", &csVNCRefNum);

		PutField_CString(hContext, "channel_code", "MGT");
		recordset_init(rRecordSet, 0);
		if (GetPayoutDetailByVncRefNum(csVNCRefNum,rRecordSet) == PD_OK) {
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if(GetField_CString(hRec,"batch_id",&csTmp)){
					PutField_CString(hContext, "batch_id", csTmp);
DEBUGLOG(("payout_handler_2:GetPayoutDetailByVncRefNum batch_id = [%s]\n",csTmp));
				}
		
				if(GetField_Int(hRec,"seq_num",&iTmp)){
DEBUGLOG(("payout_handler_2:GetPayoutDetailByVncRefNum seq_num = [%d]\n",iTmp));
					PutField_Int(hContext, "seq_num", iTmp);
				}

				if (GetField_CString(hRec, "merchant_upload_txn_seq", &csTmp)) {
					PutField_CString(hContext, "merchant_upload_txn_seq", csTmp);
DEBUGLOG(("payout_handler_2:GetPayoutDetailByVncRefNum merchant_upload_txn_seq = [%s]\n",csTmp));
				}

				if(GetField_CString(hRec,"country",&csTmp)){
					PutField_CString(hContext, "txn_country", csTmp);
					PutField_CString(hRequest, "txn_country", csTmp);
DEBUGLOG(("payout_handler_2:GetPayoutDetailByVncRefNum country = [%s]\n",csTmp));
				}

				if (GetField_CString(hRec, "merchant_ref", &csTmp)) {
					PutField_CString(hRequest, "merchant_ref", csTmp);
DEBUGLOG(("payout_handler_2:GetPayoutDetailByVncRefNum merchant_ref = [%s]\n",csTmp));
				}

				if(GetField_CString(hRec,"payout_ccy",&csTmp)){
					PutField_CString(hRequest, "dst_txn_ccy", csTmp);
DEBUGLOG(("payout_handler_2:GetPayoutDetailByVncRefNum payout_ccy = [%s]\n",csTmp));
				}


				if(GetField_CString(hRec,"request_ccy",&csTmp)){
					PutField_CString(hContext, "net_ccy", csTmp);
					PutField_CString(hContext, "txn_ccy", csTmp);
					PutField_CString(hRequest, "txn_ccy", csTmp);
DEBUGLOG(("payout_handler_2:GetPayoutDetailByVncRefNum request_ccy = [%s]\n",csTmp));
				}

				if(GetField_Double(hRec,"request_amount",&dTmp)){
DEBUGLOG(("payou_handler_2:GetPayoutDetailByVncRefNum request_amount = [%lf]\n",dTmp));
					PutField_Double(hRequest, "txn_amt", dTmp);
					PutField_Double(hRequest, "payout_amount", dTmp);
				}

				if (GetField_CString(hRec, "stl_txn_bank_name", &csTmp)) {
DEBUGLOG(("payou_handler_2:GetPayoutDetailByVncRefNum bank_name = [%s]\n",csTmp));
					PutField_CString(hRequest, "bank_name", csTmp);
				}
				
				if (GetField_CString(hRec, "stl_txn_bank_code", &csTmp)) {
DEBUGLOG(("payou_handler_2:GetPayoutDetailByVncRefNum bank_code = [%s]\n",csTmp));
					PutField_CString(hRequest, "bank_code", csTmp);
				}

				if (GetField_CString(hRec, "stl_txn_branch", &csTmp)) {
DEBUGLOG(("payou_handler_2:GetPayoutDetailByVncRefNum branch= [%s]\n",csTmp));
					PutField_CString(hRequest, "branch", csTmp);
				}

				if (GetField_CString(hRec, "stl_txn_account_id", &csTmp)) {
DEBUGLOG(("payou_handler_2:GetPayoutDetailByVncRefNum account_id = [%s]\n",csTmp));
					PutField_CString(hRequest, "account_id", csTmp);
				}

				if (GetField_CString(hRec, "stl_txn_account_name", &csTmp)) {
DEBUGLOG(("payou_handler_2:GetPayoutDetailByVncRefNum account_name = [%s]\n",csTmp));
					PutField_CString(hRequest, "account_name", csTmp);
				}
			
				if (iRet == SUCCESS) {
					// need assign value before ..?
					iRet = AssignValue(hMyHash, hContext, hRequest);
				}	

				// call TxnParByUsPOT.Authorize 
				if (iRet == SUCCESS) {
DEBUGLOG(("payou_handler_2:Calling TxnParByUsPOT \n")); 
					TxnObjPtr = CreateObj(TxnPtr,"TxnParByUsPOT","Authorize");
					iRet = (unsigned long)(*TxnObjPtr)(hContext, hRequest, hResponse);
DEBUGLOG(("payou_handler_2:Calling TxnParByUsPOT return [%d]\n", iRet)); 
				}

				if (iRet == SUCCESS) {
					//iRet = UpdateApprovalTimestamp(hContext);
				} 
				else {
DEBUGLOG(("payou_handler_2: break as iRet = [%d].....\n", iRet));
					break;
				}


				if (iRet == SUCCESS) {
					if (GetField_CString(hMyHash, "txn_nmb", &csTmp)) {
						PutField_CString(hContext, "vnc_ref_num", csTmp);

						if (UpdateHeaderVNCRef(hContext) == PD_OK) {
DEBUGLOG(("payout_handler_2: UpdateHeaderVNCRef SUCC!\n")); 
						} else {
DEBUGLOG(("payout_handler_2: UpdateHeaderVNCRef FAILED!\n")); 
						}
					}
				}

				if (iRet == SUCCESS) {
					// for transmission_datetime, tm_date
					/*
                                	hash_t *hDateTxn;
                                	hDateTxn= (hash_t *)malloc(sizeof(hash_t));
                                	hash_init (hDateTxn, 0);
				
					char	csDate[PD_DATE_LEN + 1];		
					

					if (GetField_CString(hRec, "merchant_upload_txn_seq", &csTmp)) {
						PutField_CString(hDateTxn, "txn_seq", csTmp);
					}

					if (GetField_CString(hMyHash, "post_datetime", &csTmp)) {
                                        	PutField_CString(hDateTxn, "transmission_datetime",csTmp);

						strncpy(csDate, csTmp, PD_DATE_LEN);
                                        	csDate[PD_DATE_LEN] = '\0';

						PutField_CString(hDateTxn, "tm_date", csDate);
                                	}

DEBUGLOG(("payout_handler_2:: special cater transmission_datetime!\n"));
                                	DBObjPtr = CreateObj(DBPtr, "DBTransaction","Update");

                                	if ((unsigned long)((*DBObjPtr)(hDateTxn)) == PD_OK) {
DEBUGLOG(("payout_handler_2::CreateNewSettlementTxn: call DBTransaction.Update SUCC!\n"));
                                	}
                                	else {
                                        	iRet = FAILURE;
DEBUGLOG(("par_settlement_handler_2::CreateNewSettlementTxn: call DBTransaction.Update FAILED!\n"));
                                	}
					*/

				}



				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
		else {
DEBUGLOG(("payout_handler_2:GetPayoutDetailByVncRefNum FAIL!\n"));
			iRet = FAILURE;
		}
		RecordSet_Destroy(rRecordSet);
	}


	if (iRet == SUCCESS) {
DEBUGLOG(("payout_handler_2:UpdateProcessResult\n"));
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

        FREE_ME(hContext);
        FREE_ME(hRequest);
        FREE_ME(hResponse);

        FREE_ME(rRecordSet);

DEBUGLOG(("payout_handler_2: iRet = [%d]\n",iRet));
	return iRet;
}


int UpdateMerchantUploadFileHeader(const hash_t *hRls)
{
	int	iRet = SUCCESS;
	char*   csBuf;
        char*   csBatchId;

        /* EXEC SQL WHENEVER SQLERROR GOTO updatehd_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateMerchantUploadFileHeader: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update merchant_upload_file_header set uh_update_timestamp = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        if(GetField_CString(hRls,"batch_id",&csBatchId)){
DEBUGLOG(("UpdateMerchantUploadFileHeader:batch_id = [%s]\n",csBatchId));
        }
        else{
                FREE_ME(csBuf);
DEBUGLOG(("UpdateMerchantUploadFileHeader batch_id not found\n"));
                return INT_ERR;
        }

	if(GetField_CString(hRls,"txn_seq",&csBuf)){
DEBUGLOG(("UpdateMerchantUploadFileHeader:txn_id = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",uh_txn_id = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


	strcat((char*)hv_dynstmt.arr, " WHERE uh_batch_id = ");
        strcat((char*)hv_dynstmt.arr, csBatchId);
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));


        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

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
        if (sqlca.sqlcode < 0) goto updatehd_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )24;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto updatehd_error;
}



        FREE_ME(csBuf);

DEBUGLOG(("UpdateMerchantUploadFileHeader Normal Exit\n"));
        return iRet;

updatehd_error:
DEBUGLOG(("updatehd_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("par_payout_handler_2_UpdateMerchantUploadFileHeader: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}

int	AssignValue(hash_t *hMyHash, hash_t *hContext, hash_t *hRequest)
{
	int	iRet = SUCCESS;
	char	*csTmp;
	char	csDate[PD_DATE_LEN + 1];
	int	iDayOfWeek = 0;

	if (GetField_CString(hMyHash, "local_tm_date", &csTmp)) {
DEBUGLOG(("par_payout_handler_2::AssignValue [%s]\n", csTmp));
                PutField_CString(hContext, "local_tm_date", csTmp);
        }
        if (GetField_CString(hMyHash, "local_tm_time", &csTmp)) {
DEBUGLOG(("par_payout_handler_2::AssignValue [%s]\n", csTmp));
                PutField_CString(hContext, "local_tm_time", csTmp);
        }

        if (GetField_CString(hMyHash, "merchant_id", &csTmp)) {
DEBUGLOG(("par_payout_handler_2:: AssignValue merchant_id [%s]\n", csTmp));
                PutField_CString(hContext, "merchant_id", csTmp);
                PutField_CString(hRequest, "merchant_id", csTmp);
        }

	/*
	if (GetField_CString(hMyHash, "post_date", &csTmp)) {
DEBUGLOG(("par_payout_handler_2:: AssignValue PHDATE [%s]\n", csTmp));
                PutField_CString(hContext, "PHDATE", csTmp);

	}
	*/
	if (GetField_CString(hMyHash, "txn_date", &csTmp)) {
DEBUGLOG(("par_payout_handler_2:: AssignValue PHDATE [%s]\n", csTmp));

		PutField_CString(hMyHash, "post_date", csTmp);
                PutField_CString(hContext, "PHDATE", csTmp);
	}


	if (GetField_CString(hMyHash, "txn_date", &csTmp)) {
		strncpy(csDate, csTmp, PD_DATE_LEN);
		csDate[PD_DATE_LEN] = '\0';
		PutField_CString(hContext, "approval_date", csDate);

                iDayOfWeek=day_of_week((const unsigned char *)csDate);
                PutField_Int(hContext,"day_of_week",iDayOfWeek);
	}

	if (GetField_CString(hMyHash, "txn_code", &csTmp)) {
DEBUGLOG(("par_payout_handler_2:: AssignValue txn_code [%s]\n", csTmp));
		PutField_CString(hContext, "txn_code", csTmp);
	}

	if (GetField_CString(hMyHash, "merchant_client_id", &csTmp)) {
DEBUGLOG(("par_payout_handler_2:: AssignValue merchant_client_id [%s]\n", csTmp));
		PutField_CString(hRequest, "client_id", csTmp);
		PutField_CString(hContext, "merchant_client_id", csTmp);
	}

	if (GetField_CString(hMyHash, "service", &csTmp)) {
DEBUGLOG(("par_payout_handler_2:: AssignValue service [%s]\n", csTmp));
		PutField_CString(hRequest, "service_code", csTmp);
		PutField_CString(hContext, "service_code", csTmp);
	}

	RemoveField_CString(hContext, "markup_ccy");
	RemoveField_Double(hContext, "markup_amt");
	RemoveField_Double(hContext, "markup_rate");
	RemoveField_Double(hContext, "ex_rate");


	PutField_Int(hContext,"db_commit",PD_FALSE);

	return (iRet);
}


