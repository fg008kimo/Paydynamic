
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
           char  filnam[22];
};
static struct sqlcxp sqlfpn =
{
    21,
    "mig_payout_handler.pc"
};


static unsigned int sqlctx = 160245499;


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
5,0,0,1,0,0,17,349,0,0,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,21,350,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/07/04              LokMan Chow
Amend for Migration                                2013/03/21              Virginia Yun

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
#include "mig_payout_handler.h"
#include "mig_bo_funct.h"
#include "mig_funct.h"
#include "mig_log_funct.h"
#include "ObjPtr.h"
#include "dbutility.h"

char	cDebug;

OBJPTR(DB);

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

int	UpdateMerchantUploadFileHeader(const hash_t *hRls);
int     AssignValue(hash_t *hMyHash, hash_t *hContext, hash_t *hRequest);
int  	Mig_PayoutTransaction(hash_t *hContext, hash_t *hRequest, hash_t *hResponse);

int mig_payout_handler(hash_t *hMyHash)
{
	int iRet = SUCCESS;

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

	char	*csReqCcy;
	char	*csPayoutCcy;

	hash_t  *hContext, *hRequest, *hResponse;


	hContext = (hash_t *)malloc(sizeof(hash_t));
	hRequest = (hash_t *)malloc(sizeof(hRequest));
	hResponse = (hash_t *)malloc(sizeof(hResponse));

        hash_init (hContext, 0);
        hash_init (hRequest, 0);

	rRecordSet = (recordset_t *) malloc(sizeof(recordset_t));

        hash_init (hResponse, 0);

	int	iTmpRet = PD_NOT_FOUND;

DEBUGLOG(("mig_payout_handler:: START ======\n"));

	GetField_CString(hMyHash, "txn_nmb", &csVNCRefNum);

DEBUGLOG(("mig_payout_handler:: VNCRefNum [%s]\n", csVNCRefNum));

	iTmpRet = mf_ParTxnData_ChkExist(csVNCRefNum);

	if (iTmpRet == PD_FOUND) {
DEBUGLOG(("mig_payout_handler: unexpected record exists!\n"));			
		iRecExists = PD_TRUE;
		iRet = FAILURE;
	} else if (iTmpRet == PD_NOT_FOUND) {
DEBUGLOG(("mig_payout_handler: OK to process!\n"));
		iRecExists = PD_FALSE;
	} else {
DEBUGLOG(("mig_payout_handler: mf_ParTxnData_ChkExist failed!\n"));
		iRet = FAILURE;
	}


////////if txn exist before, do nothing and return iRet
////////else add new txn

	if(iRet == SUCCESS) {
		hash_destroy(hContext);
		hash_destroy(hRequest);

		hash_init(hContext, 0);
		hash_init(hRequest, 0);

		iRet = mf_get_merch_txn_info(hMyHash);

		if (iRet == SUCCESS) {
			GetField_CString(hMyHash, "txn_nmb", &csVNCRefNum);

			recordset_init(rRecordSet, 0);
			if (mf_GetPayoutDetailByVncRefNum(csVNCRefNum,rRecordSet) == PD_OK) {
                        	hRec = RecordSet_GetFirst(rRecordSet);
				while (hRec) {

					if (iRet == SUCCESS) {

						if(GetField_CString(hRec,"batch_id",&csTmp)){
							PutField_CString(hContext, "batch_id", csTmp);
DEBUGLOG(("mig_payout_handler:GetPayoutDetailByVncRefNum batch_id = [%s]\n",csTmp));
	                                	}

						if(GetField_Int(hRec,"seq_num",&iTmp)){
DEBUGLOG(("mig_payout_handler:GetPayoutDetailByVncRefNum seq_num = [%d]\n",iTmp));
							PutField_Int(hContext, "seq_num", iTmp);
       	                         		}

                                		if (GetField_CString(hRec, "merchant_upload_txn_seq", &csTmp)) {
                                        		PutField_CString(hContext, "merchant_upload_txn_seq", csTmp);
DEBUGLOG(("mig_payout_handler:GetPayoutDetailByVncRefNum merchant_upload_txn_seq = [%s]\n",csTmp));
                                		}

                                		if(GetField_CString(hRec,"country",&csTmp)){
                                        		PutField_CString(hContext, "txn_country", csTmp);
	                                        	PutField_CString(hRequest, "txn_country", csTmp);
DEBUGLOG(("mig_payout_handler:GetPayoutDetailByVncRefNum country = [%s]\n",csTmp));
                                		}

                                 		if (GetField_CString(hRec, "merchant_ref", &csTmp)) {
                                        		PutField_CString(hRequest, "merchant_ref", csTmp);
DEBUGLOG(("mig_payout_handler:GetPayoutDetailByVncRefNum merchant_ref = [%s]\n",csTmp));
                                		}

                                		if(GetField_CString(hRec,"payout_ccy",&csTmp)){
                                        		PutField_CString(hRequest, "dst_txn_ccy", csTmp);
DEBUGLOG(("mig_payout_handler:GetPayoutDetailByVncRefNum payout_ccy = [%s]\n",csTmp));
                                		}

                                		if(GetField_CString(hRec,"request_ccy",&csTmp)){
                                        		PutField_CString(hContext, "net_ccy", csTmp);
							PutField_CString(hContext, "txn_ccy", csTmp);
							PutField_CString(hRequest, "txn_ccy", csTmp);
DEBUGLOG(("mig_payout_handler:GetPayoutDetailByVncRefNum request_ccy = [%s]\n",csTmp));
                                		}


						if (GetField_CString(hRec, "request_ccy", &csReqCcy) &&
						    GetField_CString(hRec, "payout_ccy", &csPayoutCcy))  {

DEBUGLOG(("mig_payout_handler:GetPayoutDetailByVncRefNum request_ccy = [%s] payout_ccy= [%s]\n",csReqCcy, csPayoutCcy));
							if (strcmp(csReqCcy, csPayoutCcy)) {

DEBUGLOG(("mig_payout_handler:GetPayoutDetailByVncRefNum Difference in request_ccy and payout_ccy\n"));
								//iRet = FAILURE;
							}
						}
						else {
DEBUGLOG(("mig_payout_handler:GetPayoutDetailByVncRefNum cannot get request_ccy or payouy_ccy\n")); 
							iRet = FAILURE;
						}


                               			if(GetField_Double(hRec,"request_amount",&dTmp)){
DEBUGLOG(("mig_payou_handler:GetPayoutDetailByVncRefNum request_amount = [%lf]\n",dTmp));
                                        		PutField_Double(hRequest, "txn_amt", dTmp);
                                        		//PutField_Double(hRequest, "payout_amount", dTmp);
                                		}

						if (GetField_Double(hRec, "payout_amount", &dTmp)) {
DEBUGLOG(("mig_payou_handler:GetPayoutDetailByVncRefNum payout_amount = [%lf]\n",dTmp));
                                        		PutField_Double(hRequest, "payout_amount", dTmp);
						}

						if (GetField_CString(hRec, "merchant_fee_ccy", &csTmp)) {
DEBUGLOG(("mig_payou_handler:GetPayoutDetailByVncRefNum merchant_fee_ccy = [%s]\n",csTmp));
							PutField_CString(hContext, "merchant_fee_ccy", csTmp);
						}

						if (GetField_Double(hRec, "merchant_fee", &dTmp)) {
DEBUGLOG(("mig_payou_handler:GetPayoutDetailByVncRefNum merchant_fee = [%lf]\n", dTmp));
							PutField_Double(hContext, "merchant_fee", dTmp);
						}

						if (GetField_CString(hRec, "markup_ccy", &csTmp)) {
DEBUGLOG(("mig_payou_handler:GetPayoutDetailByVncRefNum markup_ccy = [%s]\n", csTmp));
							PutField_CString(hContext, "markup_ccy", csTmp);
						}
						if (GetField_Double(hRec, "markup_amt", &dTmp)) {
DEBUGLOG(("mig_payou_handler:GetPayoutDetailByVncRefNum markup_amt = [%lf]\n", dTmp));
							PutField_Double(hContext, "markup_amt", dTmp);
						}

						if (GetField_Double(hRec, "ex_rate", &dTmp)) {
DEBUGLOG(("mig_payou_handler:GetPayoutDetailByVncRefNum ex_rate = [%lf]\n", dTmp));
							PutField_Double(hContext, "ex_rate", dTmp);
						}

                                		if (GetField_CString(hRec, "stl_txn_bank_name", &csTmp)) {
DEBUGLOG(("mig_payou_handler:GetPayoutDetailByVncRefNum bank_name = [%s]\n",csTmp));
                                        		PutField_CString(hRequest, "bank_name", csTmp);
                                		}

                                		if (GetField_CString(hRec, "stl_txn_bank_code", &csTmp)) {
DEBUGLOG(("mig_payou_handler:GetPayoutDetailByVncRefNum bank_code = [%s]\n",csTmp));
                                        		PutField_CString(hRequest, "bank_code", csTmp);
                                		}

						if (GetField_CString(hRec, "stl_txn_branch", &csTmp)) {
DEBUGLOG(("mig_handler_2:GetPayoutDetailByVncRefNum branch= [%s]\n",csTmp));
                                        		PutField_CString(hRequest, "branch", csTmp);
                                		}

                                		if (GetField_CString(hRec, "stl_txn_account_id", &csTmp)) {
DEBUGLOG(("mig_payou_handler_2:GetPayoutDetailByVncRefNum account_id = [%s]\n",csTmp));
                                        		PutField_CString(hRequest, "account_id", csTmp);
                                		}

					
                                		if (GetField_CString(hRec, "stl_txn_account_name", &csTmp)) {
DEBUGLOG(("mig_payou_handler_2:GetPayoutDetailByVncRefNum account_name = [%s]\n",csTmp));
                                        		PutField_CString(hRequest, "account_name", csTmp);
                                		}


						if (iRet == SUCCESS) {
							iRet = AssignValue(hMyHash, hContext, hRequest);
						}

						if (iRet == SUCCESS) {
							iRet = Mig_PayoutTransaction(hContext, hRequest, hResponse);
						}

       	                         		if (iRet == SUCCESS) {
                                        		if (GetField_CString(hMyHash, "txn_nmb", &csTmp)) {
                                                		PutField_CString(hContext, "vnc_ref_num", csTmp);

DEBUGLOG(("mig_payout_handler: Update Header VNC Ref [%s]\n", csTmp));

								if (GetField_CString(hContext, "merchant_upload_txn_seq", &csTmp)) {
DEBUGLOG(("mig_payout_handler: Update Header txn_seq [%s]\n", csTmp));
									PutField_CString(hContext, "txn_seq", csTmp);
								}


								if (mf_UpdateHeaderVNCRef(hContext) == PD_OK) {
DEBUGLOG(("mig_payout_handler: UpdateHeaderVNCRef SUCC!\n"));
                           	 				} else {
DEBUGLOG(("mig_payout_handler: UpdateHeaderVNCRef FAILED!\n"));
									iRet = FAILURE;
                                                		}
                                        		}
                                		}
					}
					hRec = RecordSet_GetNext(rRecordSet);
				}
			}
			else {
DEBUGLOG(("mig_payout_handler:GetPayoutDetailByVncRefNum FAIL!\n"));
				iRet = FAILURE;
			}
		}	

	}
	else{
		//////do nothing
	}

	if (iRet == SUCCESS) {
DEBUGLOG(("payout_handler:UpdateProcessResult\n"));
		iRet = mf_UpdateProcessResult(hMyHash, "COMPLETE");
	}


        hash_destroy(hContext);
        hash_destroy(hRequest);
        hash_destroy(hResponse);

        FREE_ME(hContext);
        FREE_ME(hRequest);
        FREE_ME(hResponse);

        FREE_ME(rRecordSet);

DEBUGLOG(("payout_handler: iRet = [%d]\n",iRet));
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
ERRLOG("par_payout_handler_UpdateMerchantUploadFileHeader: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}

int     AssignValue(hash_t *hMyHash, hash_t *hContext, hash_t *hRequest)
{
        int     iRet = SUCCESS;
        char    *csTmp;
        int     iDayOfWeek = 0;

	char	*csLocalDate;
	char	*csLocalTime;
	char	csTxnDateTime[PD_DATE_LEN + PD_TIME_LEN + 1];


	PutField_CString(hContext, "channel_code", PD_CHANNEL_MGT);

        if (GetField_CString(hMyHash, "local_tm_date", &csTmp)) {
DEBUGLOG(("mig_payout_handler::AssignValue [%s]\n", csTmp));
                PutField_CString(hContext, "local_tm_date", csTmp);
        }
        if (GetField_CString(hMyHash, "local_tm_time", &csTmp)) {
DEBUGLOG(("mig_payout_handler::AssignValue [%s]\n", csTmp));
                PutField_CString(hContext, "local_tm_time", csTmp);
        }

	if (GetField_CString(hMyHash, "local_tm_date", &csLocalDate) &&
	    GetField_CString(hMyHash, "local_tm_time", &csLocalTime)) {

		PutField_CString(hContext, "tm_date", csLocalDate);
		PutField_CString(hContext, "tm_time", csLocalTime);

		sprintf(csTxnDateTime, "%s%s", csLocalDate, csLocalTime);

		PutField_CString(hContext, "transmission_datetime", csTxnDateTime);

	}


        if (GetField_CString(hMyHash, "post_date", &csTmp)) {
DEBUGLOG(("mig_payout_handler:: AssignValue post_date [%s]\n", csTmp));
                PutField_CString(hContext, "post_date", csTmp);
		
        }

	if (GetField_CString(hMyHash, "txn_date", &csTmp)) {
DEBUGLOG(("mig_payout_handler:: AssignValue PHDATE [%s]\n", csTmp));
                PutField_CString(hMyHash, "PHDATE", csTmp);

                PutField_CString(hContext, "approval_date", csTmp);

                iDayOfWeek=day_of_week((const unsigned char *)csTmp);
                PutField_Int(hContext,"day_of_week",iDayOfWeek);
	}

	if (GetField_CString(hMyHash, "txn_datetimestamp", &csTmp)) {
DEBUGLOG(("mig_payout_handler:: approval_timestamp [%s]\n", csTmp));
                PutField_CString(hContext, "approval_timestamp", csTmp);
	}

	if (GetField_CString(hMyHash, "post_datetime", &csTmp)) {
DEBUGLOG(("mig_payout_handler:: create_datetime [%s]\n", csTmp));
		PutField_CString(hContext, "create_datetime", csTmp);
	}
	if (GetField_CString(hMyHash, "txn_datetime", &csTmp)) {
DEBUGLOG(("mig_payout_handler:: update_datetime [%s]\n", csTmp));
		PutField_CString(hContext, "update_datetime", csTmp);
	}


        if (GetField_CString(hMyHash, "merchant_id", &csTmp)) {
DEBUGLOG(("mig_payout_handler:: AssignValue merchant_id [%s]\n", csTmp));
                PutField_CString(hContext, "merchant_id", csTmp);
                PutField_CString(hRequest, "merchant_id", csTmp);
        }


        if (GetField_CString(hMyHash, "txn_code", &csTmp)) {
DEBUGLOG(("mig_payout_handler:: AssignValue txn_code [%s]\n", csTmp));
                PutField_CString(hContext, "txn_code", csTmp);
        }


        if (GetField_CString(hMyHash, "service", &csTmp)) {
DEBUGLOG(("mig_payout_handler:: AssignValue service [%s]\n", csTmp));
                PutField_CString(hRequest, "service_code", csTmp);
                PutField_CString(hContext, "service_code", csTmp);
        }

	/*
        RemoveField_CString(hContext, "markup_ccy");
        RemoveField_Double(hContext, "markup_amt");
        RemoveField_Double(hContext, "markup_rate");
        RemoveField_Double(hContext, "ex_rate");
	*/


	iRet = mf_merchant_getmerchanttxninfo(hContext, hRequest);

	if (iRet == SUCCESS) {

	        if (GetField_CString(hContext, "merchant_client_id", &csTmp)) {
DEBUGLOG(("mig_payout_handler:: AssignValue merchant_client_id [%s]\n", csTmp));
			PutField_CString(hRequest, "client_id", csTmp);
			//PutField_CString(hContext, "merchant_client_id", csTmp);
        	}
	}


        PutField_Int(hContext,"db_commit",PD_FALSE);

        return (iRet);
}

int  	Mig_PayoutTransaction(hash_t *hContext, hash_t *hRequest, hash_t *hResponse)
{
	int 	iRet = PD_OK;
	char	*csTxnSeq;

	int	iTmp;
	char	*csTmp;

	hash_t 	*hHeader;
	hash_t 	*hDetail;
	hash_t	*hElement;
	hash_t	*hBalance;

	double	dTmp = 0.0;
	
	hHeader= (hash_t *)malloc(sizeof(hash_t));
	hash_init (hHeader, 0);
	
	hDetail = (hash_t *)malloc(sizeof(hash_t));
	hash_init (hDetail , 0);

	hElement = (hash_t *)malloc(sizeof(hash_t));
	hash_init (hElement, 0);
	
	hBalance = (hash_t *)malloc(sizeof(hash_t));
	hash_init(hBalance, 0);


	if (GetField_Int(hContext,"db_commit", &iTmp)) {
		PutField_Int(hHeader, "db_commit", iTmp);
	}


	if (GetField_CString(hContext, "merchant_upload_txn_seq", &csTxnSeq)) {
		PutField_CString(hHeader, "txn_seq", csTxnSeq);
		PutField_CString(hDetail, "txn_seq", csTxnSeq);
DEBUGLOG(("mig_payout_handler:: Mig_PayoutTransaction: Batch Seq (txn_seq) : [%s]\n",csTxnSeq));

		PutField_CString(hElement, "from_txn_seq", csTxnSeq);

        }	

	if (GetField_CString(hContext, "channel_code", &csTmp)) {
		PutField_CString(hHeader, "channel_code", csTmp);
	}

	PutField_Char(hHeader, "status", PD_PROCESSING);

	if (GetField_CString(hContext, "txn_code", &csTmp)) {
		PutField_CString(hHeader, "txn_code", csTmp);
	}

	PutField_CString(hHeader, "process_type", PD_PROCESS_TYPE_DEF);
	PutField_CString(hHeader, "process_code", PD_PROCESS_CODE_DEF);

	if (GetField_CString(hContext, "merchant_id", &csTmp)) {
		PutField_CString(hHeader, "merchant_id", csTmp);
		PutField_CString(hBalance, "merchant_id", csTmp);
	}

	if (GetField_CString(hRequest, "merchant_ref", &csTmp)) {
		PutField_CString(hHeader, "merchant_ref", csTmp);
	}

	if (GetField_CString(hContext, "merchant_client_id", &csTmp)) {
		PutField_CString(hHeader, "client_id", csTmp);
	}

	if (GetField_CString(hContext, "post_date", &csTmp)) {
		PutField_CString(hHeader, "host_posting_date", csTmp);
		PutField_CString(hBalance, "post_date", csTmp);
	}

	if (GetField_CString(hContext, "transmission_datetime", &csTmp)) {
		PutField_CString(hHeader, "transmission_datetime", csTmp);
	}

	if (GetField_CString(hContext, "tm_date", &csTmp)) {
		PutField_CString(hHeader, "tm_date", csTmp);
	}

	if (GetField_CString(hContext, "tm_time", &csTmp)) {
		PutField_CString(hHeader, "tm_time", csTmp);
	}

	if (GetField_CString(hContext, "local_tm_date", &csTmp)) {
		PutField_CString(hHeader, "local_tm_date", csTmp);
	}

	if (GetField_CString(hContext, "local_tm_time", &csTmp)) {
                PutField_CString(hHeader, "local_tm_time", csTmp);
	}

	if (GetField_CString(hContext, "service_code", &csTmp)) {
		PutField_CString(hHeader, "service_code", csTmp);
		PutField_CString(hBalance, "service", csTmp);
	}

	PutField_CString(hHeader, "add_user", PD_UPDATE_USER);
	PutField_CString(hHeader, "update_user", PD_UPDATE_USER);


	if (GetField_CString(hContext, "create_datetime", &csTmp)) {
		PutField_CString(hHeader, "create_datetime", csTmp);
	}

	if (GetField_CString(hContext, "update_datetime", &csTmp)) {
		PutField_CString(hHeader, "update_datetime", csTmp);
	}


	if (iRet == SUCCESS) {
		iRet = ml_Txn_Header_Add(hHeader);
	}

	if (iRet == SUCCESS) {
		PutField_CString(hDetail, "add_user", PD_UPDATE_USER);
		PutField_CString(hDetail, "update_user", PD_UPDATE_USER);

		if (GetField_CString(hContext, "txn_ccy", &csTmp)) {
			PutField_CString(hDetail, "txn_ccy", csTmp);
			PutField_CString(hBalance, "ccy", csTmp);
			PutField_CString(hElement, "org_txn_ccy", csTmp);

		}

		if (GetField_CString(hContext, "txn_country", &csTmp)) {
			PutField_CString(hDetail, "txn_country", csTmp);
			PutField_CString(hBalance, "country", csTmp);
		}

		iRet = ml_Txn_Detail_AddDetail(hDetail);
	}

	// Add Element (TAMT) 
	if (iRet == SUCCESS) {
DEBUGLOG(("mig_payout_handler:: Mig_PayoutTransaction: Add TAMT Element!\n"));
		if (GetField_Double(hRequest, "txn_amt", &dTmp)) {
			PutField_Double(hElement, "org_txn_amt", dTmp);
		}
		PutField_Char(hElement, "party_type", PD_TYPE_MERCHANT);
		PutField_CString(hElement,"amount_type",PD_DR);

		iRet = migbo_AddTxnAmtElement(hElement);

DEBUGLOG(("mig_payout_handler:: Mig_PayoutTransaction: Add TAMT Element Ret [%d]!\n", iRet));
	}


	// Exchange, Add Element (MAMT)
	if (iRet == SUCCESS) {
		double dTmpMarkupAmt = 0.0;
		double dTmpPayoutAmt = 0.0;
		double dMarkupRate= 0.0;

DEBUGLOG(("mig_payout_handler:: Mig_PayoutTransaction: Add MAMT Element!\n"));
		if (GetField_CString(hContext, "markup_ccy", &csTmp)) {
			PutField_CString(hElement, "org_txn_ccy", csTmp);
		}

		if (GetField_Double(hContext, "markup_amt", &dTmpMarkupAmt)) {
			PutField_Double(hElement, "markup_amt", dTmpMarkupAmt);

DEBUGLOG(("mig_payout_handler:: Mig_PayoutTransaction: markup_amt [%lf]\n", dTmpMarkupAmt));
			if (dTmpMarkupAmt > 0.0) {

				if (GetField_Double(hRequest, "payout_amount", &dTmpPayoutAmt)) {
					dMarkupRate = dTmpMarkupAmt / (dTmpMarkupAmt + dTmpPayoutAmt);
					dMarkupRate = newround(dMarkupRate, 5);

					PutField_Double(hElement, "markup_rate", dMarkupRate);

DEBUGLOG(("mig_payout_handler:: Mig_PayoutTransaction: markup_rate [%lf]\n", dMarkupRate));
				}

				PutField_CString(hElement,"amount_type",PD_DR);

				iRet = migbo_AddMarkupAmtElement(hElement);
			}
		}
	}

	// Fee
	if (iRet == SUCCESS) {
DEBUGLOG(("mig_payout_handler:: Mig_PayoutTransaction: Add TFEE Element!\n"));

		if (GetField_CString(hContext, "merchant_fee_ccy", &csTmp)) {
			PutField_CString(hElement, "src_txn_fee_ccy", csTmp);
		}
		PutField_Char(hElement, "party_type", PD_TYPE_MERCHANT);

		if (GetField_Double(hContext, "merchant_fee", &dTmp)) {
			PutField_Double(hElement, "src_txn_fee", dTmp);
		}
		PutField_CString(hElement, "amount_type", PD_DR);

		iRet = migbo_AddTxnFeeElements(hElement);

DEBUGLOG(("mig_payout_handler:: Mig_PayoutTransaction: Add TFEE Element Ret [%d]!\n", iRet));


	}


	//UpdateMerchantUploadFileDetail, still need to update?

	// handle_payout_balance
	if (iRet == SUCCESS) {

DEBUGLOG(("mig_payout_handler:: Mig_PayoutTransaction: mf_hanle_payout_balance!!\n"));

		if (GetField_Double(hRequest, "txn_amt", &dTmp)) {
			PutField_Double(hBalance, "amount", dTmp);
		}
		if (GetField_Double(hContext, "merchant_fee", &dTmp)) {
			PutField_Double(hBalance, "fee", dTmp);
		}

		PutField_Char(hBalance,"response_mode",PD_ACCEPT);

		iRet = mf_handle_payout_balance(hBalance);
DEBUGLOG(("mig_payout_handler:: Mig_PayoutTransaction: mf_hanle_payout_balance Ret[%d]!!\n", iRet));
	}


	// UpdateTxnLog
	if (iRet == SUCCESS) {
		double dTxnAmt = 0.0;
		double dNetAmt = 0.0;
		double dFee = 0.0;

		if (GetField_CString(hContext, "update_datetime", &csTmp)) {
			PutField_CString(hHeader, "update_datetime", csTmp);
		}
	
		PutField_Char(hHeader, "status", PD_COMPLETE);
		PutField_Char(hHeader, "ar_ind", PD_ACCEPT);
		PutField_CString(hHeader, "sub_status", PD_APPROVED_FOR_GENERATED);

		if (GetField_Double(hRequest, "txn_amt", &dTxnAmt)) {
			PutField_Double(hHeader, "txn_amt", dTxnAmt);
		}

		if (GetField_Double(hContext, "merchant_fee", &dFee)) {
			dNetAmt = dTxnAmt + dFee;
		} else {
			dNetAmt = dTxnAmt;
		}
		PutField_Double(hHeader, "net_amt", dNetAmt);

		if (GetField_CString(hContext, "net_ccy", &csTmp)) {
			PutField_CString(hHeader, "net_ccy", csTmp);
		}

                if (GetField_CString(hContext, "approval_date", &csTmp)) {
			PutField_CString(hHeader, "approval_date", csTmp);
		}

		if (GetField_CString(hContext, "approval_timestamp", &csTmp)) {
			PutField_CString(hHeader, "approval_timestamp", csTmp);
		}

		if (GetField_Double(hContext, "ex_rate", &dTmp)) {
			PutField_Double(hHeader, "ex_rate", dTmp);
		}


		iRet = ml_Txn_Header_Update(hHeader);
 
	}

	// UpdateTxnDetailOg
	if (iRet == SUCCESS) {
		if (GetField_Double(hBalance, "current_bal", &dTmp)) {
			PutField_Double(hDetail, "current_bal", dTmp);
		}
		if (GetField_Double(hBalance, "current_bal_settlement", &dTmp)) {
			PutField_Double(hDetail, "current_bal_settlement", dTmp);
		}

		if (GetField_Double(hBalance, "merchant_open_bal", &dTmp)) {
			PutField_Double(hDetail, "open_bal", dTmp);
		}
		if (GetField_Double(hBalance, "merchant_open_bal_settlement", &dTmp)) {
			PutField_Double(hDetail, "open_bal_settlement", dTmp);
		}
		if (GetField_Double(hBalance, "total_float", &dTmp)) {
			PutField_Double(hDetail, "total_float", dTmp);
		}
		if (GetField_Double(hBalance, "total_float_settlement", &dTmp)) {
			PutField_Double(hDetail, "total_float_settlement", dTmp);
		}
		if (GetField_Double(hBalance, "total_float_after_payout", &dTmp)) {
			PutField_Double(hDetail, "total_float_after_payout", dTmp);
		}
		if (GetField_Double(hBalance, "total_reserved_amount", &dTmp)) {
			PutField_Double(hDetail, "total_reserved_amount", dTmp);
		}
		if (GetField_Double(hBalance, "total_hold", &dTmp)) {
			PutField_Double(hDetail, "total_hold", dTmp);
		}
		if (GetField_Double(hBalance, "total_hold_settlement", &dTmp)) {
			PutField_Double(hDetail, "total_hold_settlement", dTmp);
		}
		if (GetField_Double(hBalance, "fundin_payout", &dTmp)) {
			PutField_Double(hDetail, "fundin_payout", dTmp);
		}
		if (GetField_Double(hBalance, "reserved_payout", &dTmp)) {
			PutField_Double(hDetail, "reserved_payout", dTmp);
		}

		if (GetField_CString(hRequest, "bank_name", &csTmp)) {
			PutField_CString(hDetail, "bank_name", csTmp);
		}
		if (GetField_CString(hRequest, "branch", &csTmp)) {
			PutField_CString(hDetail, "branch", csTmp);
		}
		if (GetField_CString(hRequest, "account_name", &csTmp)) {
			PutField_CString(hDetail, "account_name", csTmp);
		}
		if (GetField_CString(hRequest, "account_id", &csTmp)) {
			PutField_CString(hDetail, "account_id", csTmp);
		}

		iRet = ml_Txn_Detail_UpdateDetail(hDetail);
	}

DEBUGLOG(("mig_payout_handler:: Mig_PayoutTransaction: iRet [%d]\n", iRet));

        hash_destroy(hHeader);
        FREE_ME(hHeader);

        hash_destroy(hDetail);
        FREE_ME(hDetail);

        hash_destroy(hElement);
        FREE_ME(hElement);

        hash_destroy(hBalance);
        FREE_ME(hBalance);

	return iRet;
}
