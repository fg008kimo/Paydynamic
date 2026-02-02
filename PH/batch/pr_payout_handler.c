
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
           char  filnam[21];
};
static struct sqlcxp sqlfpn =
{
    20,
    "pr_payout_handler.pc"
};


static unsigned int sqlctx = 86058747;


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
   unsigned char  *sqhstv[13];
   unsigned long  sqhstl[13];
            int   sqhsts[13];
            short *sqindv[13];
            int   sqinds[13];
   unsigned long  sqharm[13];
   unsigned long  *sqharc[13];
   unsigned short  sqadto[13];
   unsigned short  sqtdso[13];
} sqlstm = {12,13};

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
"select ud_batch_id ,ud_seq_num ,ud_txn_id ,ud_aux_txn_id ,ud_merchant_ref ,\
ud_country ,ud_request_amount ,ud_request_currency ,ud_merchant_fee_ccy ,ud_m\
erchant_fee ,ud_markup_ccy ,ud_markup_amt ,ud_exchange_rate  from merchant_up\
load_file_detail where ud_vnc_ref_num=:b0 order by ud_batch_id,ud_seq_num    \
        ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,314,0,9,365,0,0,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,13,368,0,0,13,0,0,1,0,2,68,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,4,0,0,
91,0,0,1,0,0,15,475,0,0,0,0,0,1,0,
106,0,0,1,0,0,15,485,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/07/04              LokMan Chow

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
#include "batchcommon.h"
#include "pr_payout_handler.h"
#include "pr_bo_funct.h"
#include "ObjPtr.h"
#include "dbutility.h"

char	cDebug;

OBJPTR(DB);

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

int	GetPayoutDetailByVncRefNum(const char *csVNCRefNum,recordset_t* myRec);
int	format_data(hash_t *hMyHash, hash_t *hTxnHeader, hash_t *hContext, hash_t *hRequest);
int	handle_payout_balance(hash_t *hMyHash);
int     AddTxnLog(const hash_t *hContext,
                const hash_t* hRequest);
int     UpdateTxnLog(const hash_t *hContext,
                const hash_t* hRequest,
                const hash_t* hResponse);
int	add_txn_element(hash_t *hMyHash);  

int payout_handler(hash_t *hMyHash)
{
	int iRet = SUCCESS;
	int iTmpRet;

	hash_t          *hTxnHeader;

	recordset_t     *rRecordSet;
	hash_t          *hRec;

	char    *csTmp = NULL;
	double  dTmp = 0.0;
	double  dReqAmt = 0.0;
	double  dMerchantFee = 0.0;
	double  dMarkup = 0.0;
	int     iTmp = 0;

	char    *csMerchNmb = NULL;
	char    *csVNCRefNum = NULL;

	int     iRecExists = PD_FALSE;
	char    *csTxnSeq;

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
DEBUGLOG(("payout_handler: txn_merch_nmb [%s]\n", csMerchNmb));
	}
	else {
DEBUGLOG(("payout_handler: txn_merch_nmb missing!\n"));
		iRet = FAILURE;
	}

	rRecordSet = (recordset_t *)malloc(sizeof(recordset_t));

	recordset_init(rRecordSet, 0);
	if (iRet == SUCCESS) {

		DBObjPtr = CreateObj(DBPtr, "DBParMerchProfile", "GetMerchant");
		if ((unsigned long) (*DBObjPtr)(csMerchNmb, rRecordSet) != PD_OK) {
DEBUGLOG(("Calling ParMerchProfile.GetMerchant FAILED!\n"));
		} else {
DEBUGLOG(("Calling ParMerchProfile.GetMerchant SUCC!\n"));

			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {

				if (GetField_CString(hRec, "service", &csTmp)) {
DEBUGLOG(("payout_handler: ParMerchProfile.GetMerchant service [%s]!\n", csTmp));
					PutField_CString(hMyHash, "service", csTmp);
				}

				if (GetField_CString(hRec, "merchant_id", &csTmp)) {
DEBUGLOG(("payout_handler: ParMerchProfile.GetMerchant merchant_id [%s]!\n", csTmp));
					PutField_CString(hMyHash, "merchant_id", csTmp);
				}

				if (GetField_CString(hRec, "client_id", &csTmp)) {
DEBUGLOG(("payout_handler: ParMerchProfile.GetMerchant client_id [%s]!\n", csTmp));
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
DEBUGLOG(("payout_handler: txn_nmb [%s]\n", csVNCRefNum));
		}
		else {
DEBUGLOG(("payout_handler: txn_nmb not found!\n"));
			iRet = FAILURE;
		}
	}

	if (iRet == SUCCESS) {
		DBObjPtr = CreateObj(DBPtr,"DBParTxnData","ChkExist");
		iTmpRet = ((unsigned long)(*DBObjPtr)(csVNCRefNum));

		if (iTmpRet == PD_FOUND) {
			iRecExists = PD_TRUE;

		} else if (iTmpRet == PD_NOT_FOUND) {
			iRecExists = PD_FALSE;

		} else {
DEBUGLOG(("payout_handler: DBParTxnData:ChkExist FAILED!\n"));
			iRet = FAILURE;
		}
	}

////////if txn exist before, do nothing and return iRet
////////else add new txn

	if(iRet == SUCCESS &&
	   iRecExists != PD_TRUE){
		csTxnSeq = strdup((char* )GetNextMgtTxnSeq());
		PutField_CString(hMyHash,"txn_seq",csTxnSeq);
DEBUGLOG(("payout_handler: Generate (MGT) Txn Seq [%s]\n", csTxnSeq));

		PutField_CString(hTxnHeader, "txn_id", csTxnSeq);

		PutField_CString(hMyHash, "channel_code", "MGT");
		PutField_CString(hMyHash, "process_type", "0000");
		PutField_CString(hMyHash, "process_code", "000000");
		PutField_CString(hMyHash, "vnc_ref_num", csVNCRefNum);

		iRet = format_data(hMyHash, hTxnHeader, hContext, hRequest);

		if (iRet == SUCCESS) {
			if (AddTxnLog(hContext, hRequest) == PD_OK) {
DEBUGLOG(("payout_handler:AddTxnLog  SUCC!\n"));

				DBObjPtr = CreateObj(DBPtr,"DBParTxnData","UpdateHeaderVNCRef");
				if ((unsigned long)(*DBObjPtr)(hContext) == PD_OK) {
DEBUGLOG(("payout_handler:Deposit init record updated vnc_ref_num succ!\n"));
				}
				else {
DEBUGLOG(("payout_handler:Deposit init record updated vnc_ref_num fail!\n"));
					iRet = FAILURE;
				}

			}
			else {
DEBUGLOG(("payout_handler:AddTxnLog FAIL!\n"));
				iRet = FAILURE;
			}
		}

//////check merchant_upload_file_detail
		if(iRet == SUCCESS){
			recordset_init(rRecordSet, 0);
			if(GetPayoutDetailByVncRefNum(csVNCRefNum,rRecordSet)==PD_OK){
				hRec = RecordSet_GetFirst(rRecordSet);
				while (hRec) {
					if(GetField_CString(hRec,"batch_id",&csTmp)){
DEBUGLOG(("GetPayoutDetailByVncRefNum batch_id = [%s]\n",csTmp));
					}
					if(GetField_Int(hRec,"seq_num",&iTmp)){
DEBUGLOG(("GetPayoutDetailByVncRefNum seq_num = [%d]\n",iTmp));
					}
					if(GetField_CString(hRec,"country",&csTmp)){
						PutField_CString(hMyHash, "country", csTmp);
DEBUGLOG(("GetPayoutDetailByVncRefNum country = [%s]\n",csTmp));
					}
					if(GetField_CString(hRec,"request_ccy",&csTmp)){
						PutField_CString(hMyHash, "ccy", csTmp);
DEBUGLOG(("GetPayoutDetailByVncRefNum request_ccy = [%s]\n",csTmp));
					}
					if(GetField_Double(hRec,"request_amount",&dTmp)){
DEBUGLOG(("GetPayoutDetailByVncRefNum request_amount = [%lf]\n",dTmp));

						dReqAmt += dTmp;
						PutField_Double(hMyHash,"amount",dReqAmt);
DEBUGLOG(("GetPayoutDetailByVncRefNum total_request_amount = [%lf]\n",dReqAmt));
					}
					if(GetField_CString(hRec,"merchant_fee_ccy",&csTmp)){
DEBUGLOG(("GetPayoutDetailByVncRefNum merchant_fee_ccy = [%s]\n",csTmp));
					}
					if(GetField_Double(hRec,"merchant_fee",&dTmp)){
DEBUGLOG(("GetPayoutDetailByVncRefNum merchant_fee = [%lf]\n",dTmp));

						dMerchantFee += dTmp;
						PutField_Double(hMyHash,"fee",dMerchantFee);
DEBUGLOG(("GetPayoutDetailByVncRefNum total_merchant_fee = [%lf]\n",dMerchantFee));
					}
	
					if(GetField_CString(hRec,"markup_ccy",&csTmp)){
						PutField_CString(hMyHash, "markup_ccy", csTmp);
DEBUGLOG(("GetPayoutDetailByVncRefNum markup_ccy = [%s]\n",csTmp));
					}
					if(GetField_Double(hRec,"markup_amt",&dTmp)){
DEBUGLOG(("GetPayoutDetailByVncRefNum markup_amt = [%lf]\n",dTmp));

						dMarkup += dTmp;
						PutField_Double(hMyHash,"markup_amt",dMarkup);
DEBUGLOG(("GetPayoutDetailByVncRefNum total_markup_amt = [%lf]\n",dMarkup));
					}
	
					hRec = RecordSet_GetNext(rRecordSet);
				}
			}
			else{
DEBUGLOG(("payout_handler:GetPayoutDetailByVncRefNum FAIL!\n"));
				iRet = FAILURE;
			}

			RecordSet_Destroy(rRecordSet);
		}

		//////handle balance
		if (iRet == SUCCESS) {
			iRet = handle_payout_balance(hMyHash);
		}

		if (iRet == SUCCESS)
			iRet = format_data(hMyHash, hTxnHeader, hContext, hRequest);

		/////txn element
		if (iRet == SUCCESS) {
			iRet = add_txn_element(hMyHash);
		}

		if (iRet == SUCCESS) {
			PutField_Char(hContext,"status",PD_COMPLETE);
			PutField_Char(hContext,"ar_ind",PD_ACCEPT);
			PutField_CString(hContext,"sub_status",PD_APPROVED_FOR_GENERATED);

			if (UpdateTxnLog(hContext, hRequest, hResponse) == PD_OK) {
DEBUGLOG(("payout_handler:UpdateTxnLog SUCC\n"));
			} else {
DEBUGLOG(("payout_handler:UpdateTxnLog FAIL\n"));
				iRet = FAILURE;
			}
		}
		FREE_ME(csTxnSeq);

	}
	else{
		//////do nothing
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

	return iRet;
}



int GetPayoutDetailByVncRefNum(const char *csVNCRefNum,recordset_t* myRec)
{
	hash_t *myHash;
	char    csBatchId[PD_TXN_SEQ_LEN+1];

        /* EXEC SQL WHENEVER SQLERROR GOTO getdetail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_vnc_ref_num[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_vnc_ref_num;


		unsigned long   v_batch_id;
                int             v_seq_num;
                /* varchar         v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

                /* varchar         v_aux_txn_seq[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_aux_txn_seq;

                /* varchar         v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

                /* varchar         v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

                /* varchar         v_request_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_request_ccy;

                /* varchar         v_merchant_fee_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_merchant_fee_ccy;

                /* varchar         v_markup_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_markup_ccy;

                double          v_request_amount;
                double          v_merchant_fee;
                double          v_markup_amt;
                double          v_ex_rate;

                short           ind_batch_id = -1;
		short           ind_seq_num = -1;
                short           ind_txn_id = -1;
                short           ind_aux_txn_seq = -1;
                short           ind_merchant_ref = -1;
                short           ind_country = -1;
                short           ind_request_ccy = -1;
                short           ind_merchant_fee_ccy = -1;
                short           ind_markup_ccy = -1;
                short           ind_request_amount = -1;
                short           ind_merchant_fee = -1;
                short           ind_markup_amt = -1;
                short           ind_ex_rate = -1;

	/* EXEC SQL END DECLARE SECTION; */ 



        hv_vnc_ref_num.len = strlen(csVNCRefNum);
        memcpy(hv_vnc_ref_num.arr,csVNCRefNum,hv_vnc_ref_num.len);
DEBUGLOG(("GetPayoutDetailByVncRefNum vnc_ref_num = [%.*s]\n",hv_vnc_ref_num.len,hv_vnc_ref_num.arr));

	/* EXEC SQL DECLARE c_cursor_getdetail CURSOR FOR
                select  ud_batch_id,
                        ud_seq_num,
			ud_txn_id,
                        ud_aux_txn_id,
                        ud_merchant_ref,
                        ud_country,
                        ud_request_amount,
                        ud_request_currency,
                        ud_merchant_fee_ccy,
                        ud_merchant_fee,
                        ud_markup_ccy,
                        ud_markup_amt,
                        ud_exchange_rate
                from    merchant_upload_file_detail
                where   ud_vnc_ref_num=:hv_vnc_ref_num
                order by ud_batch_id, ud_seq_num; */ 


	/* EXEC SQL OPEN  c_cursor_getdetail; */ 

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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_vnc_ref_num;
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
 if (sqlca.sqlcode < 0) goto getdetail_error;
}



        do{
                /* EXEC SQL FETCH c_cursor_getdetail
                INTO
                        :v_batch_id:ind_batch_id,
                        :v_seq_num:ind_seq_num,
                        :v_txn_id:ind_txn_id,
                        :v_aux_txn_seq:ind_aux_txn_seq,
                        :v_merchant_ref:ind_merchant_ref,
                        :v_country:ind_country,
                        :v_request_amount:ind_request_amount,
                        :v_request_ccy:ind_request_ccy,
                        :v_merchant_fee_ccy:ind_merchant_fee_ccy,
                        :v_merchant_fee:ind_merchant_fee,
                        :v_markup_ccy:ind_markup_ccy,
                        :v_markup_amt:ind_markup_amt,
                        :v_ex_rate:ind_ex_rate; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 13;
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
                sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_batch_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_seq_num;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_seq_num;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_id;
                sqlstm.sqhstl[2] = (unsigned long )19;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_txn_id;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_aux_txn_seq;
                sqlstm.sqhstl[3] = (unsigned long )19;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_aux_txn_seq;
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
                sqlstm.sqhstv[6] = (unsigned char  *)&v_request_amount;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_request_amount;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_request_ccy;
                sqlstm.sqhstl[7] = (unsigned long )6;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_request_ccy;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_merchant_fee_ccy;
                sqlstm.sqhstl[8] = (unsigned long )6;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_merchant_fee_ccy;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_merchant_fee;
                sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_merchant_fee;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_markup_ccy;
                sqlstm.sqhstl[10] = (unsigned long )6;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_markup_ccy;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_markup_amt;
                sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_markup_amt;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
                sqlstm.sqhstv[12] = (unsigned char  *)&v_ex_rate;
                sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_ex_rate;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto getdetail_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

/*batch_id*/
                if(ind_batch_id>=0){
                        sprintf(csBatchId,"%ld",v_batch_id);
DEBUGLOG(("GetPayoutDetailByVncRefNum batch_id=[%ld]\n",v_batch_id));
                        PutField_CString(myHash,"batch_id",csBatchId);
                }

/*seq_num*/
                if(ind_seq_num>=0){
                        PutField_Int(myHash,"seq_num",v_seq_num);
DEBUGLOG(("GetPayoutDetailByVncRefNum seq_num=[%d]\n",v_seq_num));
                }

/*aux_txn_seq*/
                if(ind_aux_txn_seq>=0){
                        v_aux_txn_seq.arr[v_aux_txn_seq.len]='\0';
                        PutField_CString(myHash,"aux_txn_seq",(const char*)v_aux_txn_seq.arr);
DEBUGLOG(("GetPayoutDetailByVncRefNum aux_txn_seq=[%s]\n",v_aux_txn_seq.arr));
                }


/*merchant_ref*/
                if(ind_merchant_ref>=0){
                        v_merchant_ref.arr[v_merchant_ref.len]='\0';
                        PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
DEBUGLOG(("GetPayoutDetailByVncRefNum merchant_ref= [%s]\n",v_merchant_ref.arr));
                }

/*country*/
                if(ind_country>=0){
                        v_country.arr[v_country.len]='\0';
                        PutField_CString(myHash,"country",(const char*)v_country.arr);
DEBUGLOG(("GetPayoutDetailByVncRefNum country= [%s]\n",v_country.arr));
                }

/*request_currency*/
                if(ind_request_ccy>=0){
                        v_request_ccy.arr[v_request_ccy.len]='\0';
                        PutField_CString(myHash,"request_ccy",(const char*)v_request_ccy.arr);
DEBUGLOG(("GetPayoutDetailByVncRefNum request_ccy= [%s]\n",v_request_ccy.arr));
                }

/*request_amount*/
                if(ind_request_amount>=0){
                        PutField_Double(myHash,"request_amount",v_request_amount);
DEBUGLOG(("GetPayoutDetailByVncRefNum request_amount = [%lf]\n",v_request_amount));
        }

/*merchant_fee_ccy*/
                if(ind_merchant_fee_ccy>=0){
                        v_merchant_fee_ccy.arr[v_merchant_fee_ccy.len]='\0';
                        PutField_CString(myHash,"merchant_fee_ccy",(const char*)v_merchant_fee_ccy.arr);
DEBUGLOG(("GetPayoutDetailByVncRefNum merchant_fee_ccy= [%s]\n",v_merchant_fee_ccy.arr));
                }

/*merchant_fee*/
                if(ind_merchant_fee>=0){
                        PutField_Double(myHash,"merchant_fee",v_merchant_fee);
DEBUGLOG(("GetPayoutDetailByVncRefNum merchant_fee = [%lf]\n",v_merchant_fee));
                }

/*markup_ccy*/
                if(ind_markup_ccy>=0){
                        v_markup_ccy.arr[v_markup_ccy.len]='\0';
                        PutField_CString(myHash,"markup_ccy",(const char*)v_markup_ccy.arr);
DEBUGLOG(("GetPayoutDetailByVncRefNum markup_ccy= [%s]\n",v_markup_ccy.arr));
                }

/*markup_amt*/
                if(ind_markup_amt>=0){
                        PutField_Double(myHash,"markup_amt",v_markup_amt);
DEBUGLOG(("GetPayoutDetailByVncRefNum markup_amt = [%lf]\n",v_markup_amt));
                }

/*ex_rate*/
                if(ind_ex_rate>=0){
                        PutField_Double(myHash,"ex_rate",v_ex_rate);
DEBUGLOG(("GetPayoutDetailByVncRefNum ex_rate = [%lf]\n",v_ex_rate));
                }

		RecordSet_Add(myRec,myHash);

        }while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )91;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getdetail_error;
}



DEBUGLOG(("GetPayoutDetailByVncRefNum Normal Exit\n"));
        return  PD_OK;

getdetail_error:
DEBUGLOG(("getdetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("pr_payout_handler_GetPayoutDetailByVncRefNum: SP_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )106;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
	
}

int format_data(hash_t *hMyHash, hash_t *hTxnHeader, hash_t *hContext, hash_t *hRequest)
{
	int     iRet = SUCCESS;
        char*   csTmp;

        char    *csTxnDateTime;
        char    csDate[PD_DATE_LEN + 1];
        char    csTime[PD_TIME_LEN + 1];
        double  dTxnAmount = 0.0;
        double  dTmp = 0.0;
        double  dFee = 0.0;
        double  dNetAmount = 0.0;

        if (GetField_CString(hTxnHeader, "txn_id", &csTmp)) {
DEBUGLOG(("format_data txn_id [%s]\n", csTmp));
                PutField_CString(hContext, "txn_seq", csTmp);
        }

        if (GetField_CString(hMyHash, "channel_code", &csTmp)) {
DEBUGLOG(("format_data channel_code [%s]\n", csTmp));
                PutField_CString(hContext, "channel_code", csTmp);
        }

        if (GetField_CString(hMyHash, "txn_code", &csTmp)) {
DEBUGLOG(("format_data txn_code [%s]\n", csTmp));
                PutField_CString(hContext, "txn_code", csTmp);
        }

        if (GetField_CString(hMyHash, "post_date", &csTmp)) {
DEBUGLOG(("format_data post_date [%s]\n", csTmp));
                PutField_CString(hContext, "PHDATE", csTmp);
        }

        if (GetField_CString(hMyHash, "local_tm_date", &csTmp)) {
DEBUGLOG(("format_data local_tm_date [%s]\n", csTmp));
                PutField_CString(hContext, "local_tm_date", csTmp);
        }

	if (GetField_CString(hMyHash, "local_tm_time", &csTmp)) {
DEBUGLOG(("format_data local_tm_time [%s]\n", csTmp));
                PutField_CString(hContext, "local_tm_time", csTmp);
        }

        if (GetField_CString(hMyHash, "process_type", &csTmp)) {
DEBUGLOG(("format_data process_type [%s]\n", csTmp));
                PutField_CString(hRequest, "process_type", csTmp);
        }

        if (GetField_CString(hMyHash, "process_code", &csTmp)) {
DEBUGLOG(("format_data process_code [%s]\n", csTmp));
                PutField_CString(hRequest, "process_code", csTmp);
        }

        if (GetField_CString(hMyHash, "merchant_id", &csTmp)) {
DEBUGLOG(("format_data merchant_id [%s]\n", csTmp));
                PutField_CString(hRequest, "merchant_id", csTmp);
        }
/*
        if (GetField_CString(hMyHash, "merch_ref", &csTmp)) {
DEBUGLOG(("format_data merchant_ref [%s]\n", csTmp));
                PutField_CString(hRequest, "merchant_ref", csTmp);
        }
*/
	if (GetField_CString(hMyHash, "txn_date", &csTxnDateTime)) {
DEBUGLOG(("format_data txn_date [%s]\n", csTxnDateTime));
                PutField_CString(hRequest, "transmission_datetime", csTxnDateTime);

                csDate[0] = '\0';
                csTime[0] = '\0';

                strncpy(csDate, csTxnDateTime, PD_DATE_LEN);
                strncpy(csTime, csTxnDateTime + PD_DATE_LEN, PD_TIME_LEN);

DEBUGLOG(("format_data tm_date [%s]\n", csDate));
DEBUGLOG(("format_data tm_time [%s]\n", csTime));

                PutField_CString(hRequest, "tm_date", csDate);
                PutField_CString(hRequest, "tm_time", csTime);

                PutField_CString(hMyHash, "psp_txn_date", csDate);
                PutField_CString(hMyHash, "psp_txn_time", csTime);
        }

        if (GetField_CString(hMyHash, "service", &csTmp)) {
DEBUGLOG(("format_data service [%s]\n", csTmp));
                PutField_CString(hRequest, "service_code", csTmp);
        }

        if (GetField_CString(hMyHash, "client_ip", &csTmp)) {
DEBUGLOG(("format_data client_ip [%s]\n", csTmp));
                PutField_CString(hRequest, "ip_addr", csTmp);
        }

        if (GetField_CString(hMyHash, "ccy", &csTmp)) {
DEBUGLOG(("format_data ccy [%s]\n", csTmp));
                PutField_CString(hRequest, "txn_ccy", csTmp);
        }

        if (GetField_CString(hMyHash, "country", &csTmp)) {
DEBUGLOG(("format_data country [%s]\n", csTmp));
                PutField_CString(hRequest, "txn_country", csTmp);
        }
/*
	if (GetField_CString(hMyHash, "pay_method", &csTmp)) {
DEBUGLOG(("format_data pay_method [%s]\n", csTmp));
                PutField_CString(hRequest, "pay_method", csTmp);
                PutField_CString(hContext, "selected_pay_method", csTmp);
        }
*/
        if (GetField_CString(hMyHash, "vnc_ref_num", &csTmp)) {
DEBUGLOG(("format_data vnc_ref_num [%s]\n", csTmp));
                PutField_CString(hContext, "vnc_ref_num", csTmp);
        }

        if (GetField_Double(hMyHash, "amount", &dTxnAmount)) {
DEBUGLOG(("format_data txn_amount [%lf]\n", dTxnAmount));
                PutField_Double(hContext, "txn_amt", dTxnAmount);
        }

        if (GetField_Double(hMyHash, "ex_rate", &dTmp)) {
DEBUGLOG(("format_data ex_rate [%lf]\n", dTmp));
                PutField_Double(hContext, "ex_rate", dTmp);
        }

        if (GetField_Double(hMyHash, "fee", &dFee)) {
DEBUGLOG(("format_data fee [%lf]\n", dFee));

        }

        if (GetField_CString(hMyHash, "markup_ccy", &csTmp)) {
DEBUGLOG(("format_data markup_ccy [%s]\n", csTmp));
                PutField_CString(hContext, "markup_ccy", csTmp);
        }

        if (GetField_Double(hMyHash, "markup_amt", &dTmp)) {
DEBUGLOG(("format_data markup_amt [%lf]\n", dTmp));
                PutField_Double(hContext, "markup_amt", dTmp);
        }

        if (dTxnAmount > 0.0) {
                dNetAmount = dTxnAmount + dFee;
DEBUGLOG(("format_data net_amount [%lf]\n", dNetAmount));
                PutField_Double(hContext, "net_amt", dNetAmount);
                PutField_Double(hMyHash, "net_amt", dNetAmount);
        }


        if (GetField_CString(hMyHash, "merchant_client_id", &csTmp)) {
DEBUGLOG(("format_data merchant_client_id [%s]\n", csTmp));
                PutField_CString(hContext, "merchant_client_id", csTmp);
        }

	if (GetField_Double(hMyHash, "merchant_open_bal", &dTmp)) {
DEBUGLOG(("format_data merchant_open_bal [%lf]\n", dTmp));
                PutField_Double(hContext, "merchant_open_bal", dTmp);
	}

        if (GetField_Double(hMyHash, "total_float", &dTmp)) {
DEBUGLOG(("format_data total_float [%lf]\n", dTmp));
                PutField_Double(hContext, "total_float", dTmp);
        }

        if (GetField_Double(hMyHash, "current_bal", &dTmp)) {
DEBUGLOG(("format_data current_bal [%lf]\n", dTmp));
                PutField_Double(hContext, "current_bal", dTmp);
        }

        if (GetField_Double(hMyHash, "total_reserved_amount", &dTmp)) {
DEBUGLOG(("format_data total_reserved_amount [%lf]\n", dTmp));
                PutField_Double(hContext, "total_reserved_amount", dTmp);
        }

        if (GetField_Double(hMyHash, "total_hold", &dTmp)) {
DEBUGLOG(("format_data total_hold [%lf]\n", dTmp));
                PutField_Double(hContext, "total_hold", dTmp);
        }

        if (GetField_Double(hMyHash, "settlement_in_transit", &dTmp)) {
DEBUGLOG(("format_data settlement_in_transit [%lf]\n", dTmp));
                PutField_Double(hContext, "settlement_in_transit", dTmp);
        }




        return iRet;
}



int handle_payout_balance(hash_t *hMyHash)
{
        int     iRet = SUCCESS;

        char    *csMID = NULL;
        char    *csCcy = NULL;
        char    *csCountry = NULL;
        char    *csService = NULL;
        char    *csTmp= NULL;
        double  dAmount = 0.0;
        double  dTmp = 0.0;
        int     iDayOfWeek= 0;
        double  dFee = 0.0;
        double  dNetAmt = 0.0;

        if (GetField_CString(hMyHash, "merchant_id", &csMID)) {
DEBUGLOG(("handle_payout_balance: merchant_id [%s]\n", csMID));
        }
        else {
DEBUGLOG(("handle_payout_balance: merchant_id missing\n"));
                iRet = FAILURE;
        }

        if (GetField_CString(hMyHash, "ccy", &csCcy)) {
DEBUGLOG(("handle_payout_balance: ccy [%s]\n", csCcy));
        }
        else {
DEBUGLOG(("handle_payout_balance: ccy missing\n"));
                iRet = FAILURE;
        }
        if (GetField_CString(hMyHash, "country", &csCountry)) {
DEBUGLOG(("handle_payout_balance: country [%s]\n", csCountry));
        }
        else {
DEBUGLOG(("handle_payout_balance: country missing\n"));
                iRet = FAILURE;
        }

        if (GetField_CString(hMyHash, "service", &csService)) {
DEBUGLOG(("handle_payout_balance: service [%s]\n", csService));
        }
        else {
DEBUGLOG(("handle_payout_balance: service missing\n"));
                iRet = FAILURE;
        }

        if (GetField_Double(hMyHash, "amount", &dAmount)) {
DEBUGLOG(("handle_payout_balance: amount [%lf]\n", dAmount));
		dNetAmt += dAmount;
        }
        else {
DEBUGLOG(("handle_payout_balance: amount missing\n"));
                iRet = FAILURE;
        }

        if (GetField_Double(hMyHash, "fee", &dFee)) {
DEBUGLOG(("handle_payout_balance: fee[%lf]\n", dFee));
		dNetAmt += dFee;
        }
        else {
DEBUGLOG(("handle_payout_balance: fee missing\n"));
                iRet = FAILURE;
        }

	if (GetField_CString(hMyHash, "post_date", &csTmp)) {
		iDayOfWeek = day_of_week((const unsigned char*)csTmp);
		PutField_Int(hMyHash,"day_of_week",iDayOfWeek);
	}

	PutField_Double(hMyHash,"net_amt",dNetAmt);
	PutField_Char(hMyHash,"response_mode",PD_ACCEPT);
	PutField_Char(hMyHash,"party_type",PD_TYPE_MERCHANT);
	

	if (iRet == SUCCESS) {
                if (GetOpenBalanceForUpdate(hMyHash, csMID, csCcy, csCountry, csService) == PD_OK) {
                        if (GetField_Double(hMyHash, "merchant_open_bal", &dTmp)) {
DEBUGLOG(("handle_payout_balance: merchant_open_bal [%lf]\n", dTmp));
                        }
                }
                else {
DEBUGLOG(("handle_payout_balance: GetOpenBalanceForUpdate FAIL!\n"));
                        iRet = FAILURE;
                }
        }

        if (iRet == SUCCESS) {
		if (UpdatePayoutAmount(hMyHash) == PD_OK) {
			if (GetField_Double(hMyHash, "total_float", &dTmp)) {
DEBUGLOG(("handle_payout_balance:total_float [%lf]!\n", dTmp));
			}

                        if (GetField_Double(hMyHash, "current_bal", &dTmp)) {
DEBUGLOG(("handle_payout_balance:current_bal [%lf]!\n", dTmp));
			}

			if (GetField_Double(hMyHash, "total_reserved_amount" , &dTmp)) {
DEBUGLOG(("handle_payout_balance:total_reserved_amount [%lf]!\n", dTmp));
			}

			if (GetField_Double(hMyHash, "total_hold", &dTmp)) {
DEBUGLOG(("handle_payout_balance:total_hold [%lf]!\n", dTmp));
			}

			if (GetField_Double(hMyHash, "settlement_in_transit", &dTmp)) {
DEBUGLOG(("handle_payout_balance:settlment_in_transit [%lf]!\n", dTmp));
			}

		}
		else {
DEBUGLOG(("handle_payout_balance: UpdatePayoutAmount FAIL!\n"));
                        iRet = FAILURE;
                }

        }
        return iRet;
}


int     AddTxnLog(const hash_t *hContext,
                const hash_t* hRequest)
{
        hash_t  *hTxn;
        char    *csTmp;
        char    *csTxnSeq;
        int iRet = PD_OK;

        hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTxn,0);
        if (GetField_CString(hContext,"txn_seq",&csTxnSeq)) {
DEBUGLOG(("AddTxnLog:: txn_seq = [%s]\n",csTxnSeq));
                PutField_CString(hTxn,"txn_seq",csTxnSeq);

                if (GetField_CString(hContext,"add_user",&csTmp)) {
DEBUGLOG(("AddTxnLog:: add_user = [%s]\n",csTmp));
                        PutField_CString(hTxn,"add_user",csTmp);
                }
                else{
                        PutField_CString(hTxn,"add_user",PD_UPDATE_USER);
                }

                if (GetField_CString(hContext,"channel_code",&csTmp)) {
DEBUGLOG(("AddTxnLog:: channel_code = [%s]\n",csTmp));
                        PutField_CString(hTxn,"channel_code",csTmp);
                }
                if (GetField_CString(hRequest,"merchant_id",&csTmp)) {
DEBUGLOG(("AddTxnLog:: merchant_id = [%s]\n",csTmp));
                        PutField_CString(hTxn,"merchant_id",csTmp);
                }
                if (GetField_CString(hRequest,"service_code",&csTmp)) {
DEBUGLOG(("AddTxnLog:: service_code = [%s]\n",csTmp));
                        PutField_CString(hTxn,"service_code",csTmp);
                }
                if (GetField_CString(hContext,"txn_code",&csTmp)) {
DEBUGLOG(("AddTxnLog:: txn_code = [%s]\n",csTmp));
                        PutField_CString(hTxn,"txn_code",csTmp);
                }

                if (GetField_CString(hContext,"PHDATE",&csTmp)) {
DEBUGLOG(("AddTxnLog:: host_posting_date = [%s]\n",csTmp));
                        PutField_CString(hTxn,"host_posting_date",csTmp);
                        PutField_CString(hTxn,"transmission_datetime",csTmp);
                        PutField_CString(hTxn,"tm_date",csTmp);
                }
                if (GetField_CString(hContext,"local_tm_date",&csTmp)) {
DEBUGLOG(("AddTxnLog:: local_tm_date = [%s]\n",csTmp));
                        PutField_CString(hTxn,"local_tm_date",csTmp);
                }
                if (GetField_CString(hContext,"local_tm_time",&csTmp)) {
DEBUGLOG(("AddTxnLog:: local_tm_time = [%s]\n",csTmp));
                        PutField_CString(hTxn,"local_tm_time",csTmp);
                }

/* request */
                /* client ip */
                if (GetField_CString(hRequest,"ip_addr",&csTmp)) {
DEBUGLOG(("AddTxnLog:: client_ip = [%s]\n",csTmp));
                        PutField_CString(hTxn,"ip_addr",csTmp);
                }

                PutField_Char(hTxn,"status",PD_PROCESSING);

                DBObjPtr = CreateObj(DBPtr,"DBTransaction","Add");
                iRet = (unsigned long) ((*DBObjPtr)(hTxn));

                char *csTxnCcy, *csTxnCountry;
                if (GetField_CString(hRequest,"txn_ccy",&csTxnCcy) && iRet == PD_OK) {
DEBUGLOG(("AddTxnLog:: txn_ccy = [%s]\n",csTxnCcy));
                        hash_t* hDetail;
                        hDetail = (hash_t*)  malloc (sizeof(hash_t));
                        hash_init(hDetail,0);

                        PutField_CString(hDetail,"txn_seq",csTxnSeq);
                        PutField_CString(hDetail,"txn_ccy",csTxnCcy);

                        if (GetField_CString(hTxn, "add_user", &csTmp)) {
                                PutField_CString(hDetail,"add_user",csTmp);
                        }

                        if (GetField_CString(hRequest,"txn_country",&csTxnCountry))
                                PutField_CString(hDetail,"txn_country",csTxnCountry);
                        DBObjPtr = CreateObj(DBPtr,"DBTransaction","AddDetail");
                        iRet = (unsigned long) ((*DBObjPtr)(hDetail));

                        hash_destroy(hDetail);
                        FREE_ME(hDetail);
                }

        }
        else
                iRet = PD_ERR;

        hash_destroy(hTxn);
        FREE_ME(hTxn);
        FREE_ME(csTmp);
DEBUGLOG(("AddTxnLog RET = [%d]\n",iRet));
        return  iRet;
}

int     UpdateTxnLog(const hash_t *hContext,
                const hash_t* hRequest,
                const hash_t* hResponse)
{
        hash_t  *hTxn;
        char    *csTxnSeq;

        int     iRet = PD_OK;
        int     iTmp;
        char    cTmp;
        double  dTmp;
        char*   csPtr;

        hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTxn,0);

        if (GetField_CString(hContext,"txn_seq",&csTxnSeq)) {
DEBUGLOG(("UpdateTxnLog:: txn_seq = [%s]\n",csTxnSeq));
                PutField_CString(hTxn,"txn_seq",csTxnSeq);

                if (GetField_CString(hContext,"update_user",&csPtr)) {
DEBUGLOG(("UpdateTxnLog:: add_user = [%s]\n",csPtr));
                        PutField_CString(hTxn,"update_user",csPtr);
                }
                else{
                        PutField_CString(hTxn,"update_user",PD_UPDATE_USER);
                }

                if (GetField_CString(hContext,"org_txn_seq",&csPtr)) {
DEBUGLOG(("UpdateTxnLog:: org_txn_seq = [%s]\n",csPtr));
                        PutField_CString(hTxn,"org_txn_seq",csPtr);
                }
                if (GetField_CString(hContext,"process_code",&csPtr)) {
DEBUGLOG(("UpdateTxnLog:: process_code = [%s]\n",csPtr));
                        PutField_CString(hTxn,"process_code",csPtr);
                }
                if (GetField_CString(hContext,"process_type",&csPtr)) {
DEBUGLOG(("UpdateTxnLog:: process_type = [%s]\n",csPtr));
                        PutField_CString(hTxn,"process_type",csPtr);
                }
                if (GetField_Char(hContext,"status",&cTmp)) {
DEBUGLOG(("UpdateTxnLog:: status = [%c]\n",cTmp));
                        PutField_Char(hTxn,"status",cTmp);
                }
                if (GetField_CString(hContext,"sub_status",&csPtr)) {
DEBUGLOG(("UpdateTxnLog:: sub_status = [%s]\n",csPtr));
                        PutField_CString(hTxn,"sub_status",csPtr);
                }

                if (GetField_Char(hContext,"ar_ind",&cTmp)) {
DEBUGLOG(("UpdateTxnLog:: ar_ind = [%c]\n",cTmp));
                        PutField_Char(hTxn,"ar_ind",cTmp);
                }

                if (GetField_Int(hContext,"internal_code",&iTmp)) {
DEBUGLOG(("UpdateTxnLog:: internal_code = [%d]\n",iTmp));
                        PutField_Int(hTxn,"internal_code",iTmp);
                }

                if (GetField_CString(hResponse,"response_code",&csPtr)) {
DEBUGLOG(("UpdateTxnLog:: response_code = [%s]\n",csPtr));
                        PutField_CString(hTxn,"response_code",csPtr);
                }
                else if (GetField_CString(hContext,"response_code",&csPtr)) {
DEBUGLOG(("UpdateTxnLog:: response_code = [%s]\n",csPtr));
                        PutField_CString(hTxn,"response_code",csPtr);
                }

                if (GetField_CString(hContext,"merchant_client_id",&csPtr)) {
DEBUGLOG(("UpdateTxnLog:: client_id = [%s]\n",csPtr));
                        PutField_CString(hTxn,"client_id",csPtr);
                }

                if (GetField_Double(hContext,"txn_amt",&dTmp)) {
DEBUGLOG(("UpdateTxnLog:: txn_amt = [%f]\n",dTmp));
                        PutField_Double(hTxn,"txn_amt",dTmp);
                }

                if (GetField_Double(hContext,"net_amt",&dTmp)) {
DEBUGLOG(("UpdateTxnLog:: net_amt = [%f]\n",dTmp));
                        PutField_Double(hTxn,"net_amt",dTmp);
                }

/* net ccy */
                if (GetField_CString(hContext,"net_ccy",&csPtr)) {
DEBUGLOG(("UpdateTxnLog:: net_ccy = [%s]\n",csPtr));
                        PutField_CString(hTxn,"net_ccy",csPtr);
                }

                if (GetField_Double(hContext,"ex_rate",&dTmp)) {
DEBUGLOG(("UpdateTxnLog:: ex_rate = [%f]\n",dTmp));
                        PutField_Double(hTxn,"ex_rate",dTmp);
                }

                if (GetField_Char(hContext,"ex_party",&cTmp)) {
DEBUGLOG(("UpdateTxnLog:: ex_supplier = [%f]\n",cTmp));
                        PutField_Char(hTxn,"ex_supplier",cTmp);
                }

/* markup ccy */
                if(GetField_CString(hContext,"markup_ccy",&csPtr)){
DEBUGLOG(("UpdateTxnLog:: markup_ccy = [%s]\n",csPtr));
                        PutField_CString(hTxn,"markup_ccy",csPtr);
                }
/* markup rate */
                if(GetField_Double(hContext,"markup_rate",&dTmp)){
DEBUGLOG(("UpdateTxnLog:: markup_rate = [%f]\n",dTmp));
                        PutField_Double(hTxn,"markup_rate",dTmp);
                }
/* markup amount */
                if(GetField_Double(hContext,"markup_amt",&dTmp)){
DEBUGLOG(("UpdateTxnLog:: markup_amount = [%f]\n",dTmp));
                        PutField_Double(hTxn,"markup_amt",dTmp);
                }
/* dst_txn_amt */
                if(GetField_Double(hContext,"dst_txn_amt",&dTmp)){
DEBUGLOG(("UpdateTxnLog:: dst_txn_amt = [%f]\n",dTmp));
                        PutField_Double(hTxn,"dst_txn_amt",dTmp);
                }

/* settlement_txn_amt */
                if(GetField_Double(hContext,"settlement_txn_amt",&dTmp)){
DEBUGLOG(("UpdateTxnLog:: settlement_txn_amt = [%f]\n",dTmp));
                        PutField_Double(hTxn,"settlement_txn_amt",dTmp);
                }

                if (GetField_CString(hContext,"merchant_id",&csPtr)) {
DEBUGLOG(("UpdateTxnLog:: merchant_id = [%s]\n",csPtr));
                        PutField_CString(hTxn,"merchant_id",csPtr);
                }

                if (GetField_CString(hContext,"merchant_ref",&csPtr)) {
DEBUGLOG(("UpdateTxnLog:: merchant_ref = [%s]\n",csPtr));
                        PutField_CString(hTxn,"merchant_ref",csPtr);
                }

                if (GetField_CString(hContext,"service_code",&csPtr)) {
DEBUGLOG(("UpdateTxnLog:: service_code = [%s]\n",csPtr));
                        PutField_CString(hTxn,"service_code",csPtr);
                }

                if (GetField_CString(hContext,"approval_date",&csPtr)) {
DEBUGLOG(("UpdateTxnLog:: approval_date = [%s]\n",csPtr));
                        PutField_CString(hTxn,"approval_date",csPtr);
                }

                if (GetField_CString(hContext,"new_txn_code",&csPtr)) {
DEBUGLOG(("UpdateTxnLog:: new_txn_code = [%s]\n",csPtr));
                        PutField_CString(hTxn,"txn_code",csPtr);
                }
/* update txn header */
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","Update");
                iRet = (unsigned long)(*DBObjPtr)(hTxn);
        }
        else
                iRet = PD_ERR;

	if(iRet == PD_OK){
/* open_bal */
                if (GetField_Double(hContext,"merchant_open_bal",&dTmp)) {
                        PutField_Double(hTxn,"open_bal",dTmp);
DEBUGLOG(("UpdateTxnDetailLog:: open_bal= [%f]\n",dTmp));
                }

/* current_bal */
                if (GetField_Double(hContext,"current_bal",&dTmp)) {
                        PutField_Double(hTxn,"current_bal",dTmp);
DEBUGLOG(("UpdateTxnDetailLog:: current_bal= [%f]\n",dTmp));
                }

/* total_float*/
                if (GetField_Double(hContext,"total_float",&dTmp)) {
                        PutField_Double(hTxn,"total_float",dTmp);
DEBUGLOG(("UpdateTxnDetailLog:: total_float= [%f]\n",dTmp));
                }

/* total_reserved_amount*/
                if (GetField_Double(hContext,"total_reserved_amount",&dTmp)) {
                        PutField_Double(hTxn,"total_reserved_amount",dTmp);
DEBUGLOG(("UpdateTxnDetailLog:: total_reserved_amount= [%f]\n",dTmp));
                }

/* total_hold*/
                if (GetField_Double(hContext,"total_hold",&dTmp)) {
                        PutField_Double(hTxn,"total_hold",dTmp);
DEBUGLOG(("UpdateTxnDetailLog:: total_hold= [%f]\n",dTmp));
                }

/* settlement_in_transit*/
                if (GetField_Double(hContext,"settlement_in_transit",&dTmp)) {
                        PutField_Double(hTxn,"settlement_in_transit",dTmp);
DEBUGLOG(("UpdateTxnDetailLog:: settlement_in_transit= [%f]\n",dTmp));
                }

                DBObjPtr = CreateObj(DBPtr,"DBTransaction","UpdateDetail");
                iRet = (unsigned long)(*DBObjPtr)(hTxn);
	}


DEBUGLOG(("UpdateTxnLog iRet = [%d]\n",iRet));
        hash_destroy(hTxn);
        FREE_ME(hTxn);

        return  iRet;
}


int add_txn_element(hash_t *hMyHash)
{
        int     iRet = SUCCESS;
	char	*csTmp;
	double	dTmp;
	hash_t *hTxn;
	
        hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTxn,0);

	if(GetField_CString(hMyHash,"txn_seq",&csTmp)){
		PutField_CString(hTxn,"from_txn_seq",csTmp);
	}
	if(GetField_CString(hMyHash,"ccy",&csTmp)){
		PutField_CString(hTxn,"org_txn_ccy",csTmp);
		PutField_CString(hTxn,"src_txn_fee_ccy",csTmp);
	}
	if(GetField_Double(hMyHash,"amount",&dTmp)){
		PutField_Double(hTxn,"org_txn_amt",dTmp);
	}
	PutField_CString(hTxn,"amount_type",PD_DR);
	PutField_Char(hTxn,"party_type",PD_TYPE_MERCHANT);
	
DEBUGLOG(("AddTxnAmtElement\n"));
	if(AddTxnAmtElement(hTxn)!=PD_OK){
		iRet = FAILURE;
DEBUGLOG(("AddTxnAmtElement Failed\n"));
	}

	if(iRet==SUCCESS){
		if(GetField_Double(hMyHash,"fee",&dTmp)){
			PutField_Double(hTxn,"src_txn_fee",dTmp);
		}

DEBUGLOG(("AddTxnFeeElements\n"));
		if(AddTxnFeeElements(hTxn)!=PD_OK){
			iRet = FAILURE;
DEBUGLOG(("AddTxnFeeElements Failed\n"));
		}
	}

	if(iRet==SUCCESS){
		if(GetField_CString(hMyHash,"markup_ccy",&csTmp)){
			PutField_CString(hTxn,"org_txn_ccy",csTmp);
		}
		if(GetField_Double(hMyHash,"markup_amt",&dTmp)){
			PutField_Double(hTxn,"markup_amt",dTmp);
		}

		if(dTmp>0.0){
DEBUGLOG(("AddMarkupAmtElement\n"));
			if(AddMarkupAmtElement(hTxn)!=PD_OK){
				iRet = FAILURE;
DEBUGLOG(("AddMarkupAmtElement Failed\n"));
			}
		}
	}

	FREE_ME(hTxn);
	return iRet;
}
