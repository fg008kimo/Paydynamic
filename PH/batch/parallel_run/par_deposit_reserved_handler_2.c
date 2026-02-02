
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
           char  filnam[34];
};
static struct sqlcxp sqlfpn =
{
    33,
    "par_deposit_reserved_handler_2.pc"
};


static unsigned int sqlctx = 937484645;


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
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/02/19              Virginia Yun
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
#include "par_txn_handler.h"
#include "ObjPtr.h"
#include "dbutility.h"
#include "par_deposit_reserved_handler_2.h"
#include "pr_bo_funct.h"
#include "pr_par_funct.h"
#include "pr_par_funct_2.h"
#include "pr_log_funct.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define	PD_CHAR		0x0D

OBJPTR(DB);
OBJPTR(Txn);
OBJPTR(Channel);
OBJPTR(BO);

char    cDebug;

int  CreateNewDepositReservedTxn (hash_t *hMyHash);
int  CheckReversedSkipTxn(hash_t *hMyHash, hash_t *hTxnHeader);
int  HandleDepositReservedBalance(hash_t *hMyHash, hash_t *hMerchBalace);

int  process_deposit_reserved_approve(hash_t *hMyHash);
int  process_release_deposit_reserved(hash_t *hMyHash);



int deposit_reserved_handler_2(hash_t *hMyHash)
{
	int iRet = SUCCESS;
	//int iTmpRet;
	//int iRecExists = PD_TRUE;

	hash_t  *hTxnHeader;

	//recordset_t	*rRecordSet;
	//hash_t		*hRec;

	//char	*csTmp = NULL;

	//char	*csMerchNmb = NULL;
	//char	*csVNCRefNum = NULL;
        //char    csCountry [PD_COUNTRY_LEN + 1];
        //char    *csService = NULL;

	//int	iSkip;
	char	*csTxnStatus;

	hash_t 	*hContext, *hRequest, *hResponse;

	hTxnHeader = (hash_t *)malloc(sizeof(hash_t));
	hash_init (hTxnHeader, 0);

	hContext = (hash_t *)malloc(sizeof(hash_t));
	hRequest = (hash_t *)malloc(sizeof(hRequest));
	hResponse = (hash_t *)malloc(sizeof(hResponse));

	hash_init (hContext, 0);
	hash_init (hRequest, 0);
	hash_init (hResponse, 0);

	iRet = AssignTxnRecordDetail(hMyHash);

	if (iRet == SUCCESS) {
		GetField_CString(hMyHash, "txn_status", &csTxnStatus);

		if (!strcmp(csTxnStatus, "MERCHANT_RESERVE_REVERSED")) {
			//iRet = CreateNewDepositReservedTxn(hMyHash);

			if (iRet == SUCCESS) {
				iRet = process_release_deposit_reserved(hMyHash);
			}

			if (iRet == SUCCESS) {
				//Update to "COMPLETE"
				iRet = UpdateProcessResult(hMyHash, "COMPLETE");
			}
		}
		else {
			//Update to "SKIP"
			iRet = UpdateProcessResult(hMyHash, "REV-SKIP");
		}
	}
	
	hash_destroy(hTxnHeader);
	FREE_ME(hTxnHeader);
	
	hash_destroy(hContext);
	hash_destroy(hRequest);
	hash_destroy(hResponse);

	FREE_ME(hContext);
	FREE_ME(hRequest);
	FREE_ME(hResponse);

	//FREE_ME(rRecordSet);

	return iRet;
}



int CreateNewDepositReservedTxn (hash_t *hMyHash)
{
	int	iRet = SUCCESS;

	char	*csTxnSeq;
	hash_t	*hHeader, *hDetail;
	//int	iInitMode = PD_TRUE;
	char	*csVNCRefNum;

	char	*csTmp;
	double	dTmp = 0.0;
	int	iTmp;

	//char	csDate[PD_DATE_LEN + 1];
	//char	csTime[PD_TIME_LEN + 1];

	char	*csLocalDate;
	char	*csLocalTime;
	char	csLocalDateTime[PD_DATE_LEN + PD_TIME_LEN + 1];

	hHeader= (hash_t *) malloc (sizeof(hash_t));
	hash_init(hHeader, 0);

	hDetail = (hash_t *) malloc (sizeof(hash_t));
	hash_init(hDetail, 0);

	if (GetField_Int(hMyHash, "db_commit", &iTmp)) {
DEBUGLOG(("CreateNewDepositReservedTxn: db_commit [%d]\n", iTmp));
                PutField_Int(hHeader, "db_commit", iTmp);
	}


	csTxnSeq = strdup((char* )prbo_GetNextMgtTxnSeq());

	PutField_CString(hMyHash, "txn_seq", csTxnSeq);
DEBUGLOG(("CreateNewRecord: Generate TxnSeq [%s]\n", csTxnSeq));

	PutField_CString(hHeader, "txn_seq", csTxnSeq);
	PutField_CString(hDetail, "txn_seq", csTxnSeq);

	PutField_CString(hHeader, "add_user", PD_UPDATE_USER);
	PutField_CString(hDetail, "add_user", PD_UPDATE_USER);

	PutField_CString(hHeader, "channel_code", "MGT");

	PutField_Char(hHeader,"status",PD_PROCESSING);

	// There is no org_txn_seq in deposit reverse case
	/*
	if (GetField_CString(hMyHash, "org_txn_seq", &csTmp)) {
DEBUGLOG(("CreateNewRecord: org_txn_seq [%s]\n", csTmp));
		PutField_CString(hHeader, "org_txn_seq", csTmp);
	}
	*/

	if (GetField_CString(hMyHash, "txn_code", &csTmp)) {
DEBUGLOG(("CreateNewRecord: txn_code [%s]\n", csTmp));
		PutField_CString(hHeader, "txn_code", csTmp);
	}

	if (GetField_CString(hMyHash, "reverse_txn_code", &csTmp)) {
DEBUGLOG(("CreateNewRecord: reverse_txn_code [%s]\n", csTmp));
		PutField_CString(hHeader, "txn_code", csTmp);
	}


        if (GetField_CString(hMyHash, "txn_date", &csTmp)) {
DEBUGLOG(("CreateNewRecord: post_post [%s]\n", csTmp));
                PutField_CString(hMyHash, "PHDATE", csTmp);
                PutField_CString(hHeader, "host_posting_date", csTmp);
		PutField_CString(hHeader, "transmission_datetime",csTmp);
        }

	/*
	if (GetField_CString(hMyHash, "post_datetime", &csTmp)) {
		PutField_CString(hHeader, "transmission_datetime",csTmp);

		strncpy(csDate, csTmp, PD_DATE_LEN);
		csDate[PD_DATE_LEN] = '\0';
		strncpy(csTime, csTmp + PD_DATE_LEN, PD_TIME_LEN);

DEBUGLOG(("CreateNewRecord: tm_time [%s]\n", csTime));

		PutField_CString(hHeader, "tm_time", csTime);
	}
	*/


        if (GetField_CString(hMyHash, "local_tm_date", &csTmp)) {
DEBUGLOG(("CreateNewRecord: local_tm_date [%s]\n", csTmp));
                PutField_CString(hHeader, "local_tm_date", csTmp);
	}  

        if (GetField_CString(hMyHash, "local_tm_time", &csTmp)) {
DEBUGLOG(("CreateNewRecord: local_tm_time [%s]\n", csTmp));
                PutField_CString(hHeader, "local_tm_time", csTmp);
        }

        if (GetField_CString(hMyHash, "local_tm_date", &csLocalDate) &&
            GetField_CString(hMyHash, "local_tm_time", &csLocalTime)) {

                PutField_CString(hHeader, "tm_date", csLocalDate);
                PutField_CString(hHeader, "tm_time", csLocalTime);

                memset(csLocalDateTime, 0, sizeof(csLocalDateTime));
                sprintf(csLocalDateTime, "%s%s", csLocalDate, csLocalTime);

                PutField_CString(hHeader, "transmission_datetime",csLocalDateTime);
	}



	if (GetField_CString(hMyHash, "merchant_id", &csTmp)) {
DEBUGLOG(("CreateNewRecord: merchant_id [%s]\n", csTmp));
                PutField_CString(hHeader, "merchant_id", csTmp);
        }

	if (GetField_CString(hMyHash, "client_ip", &csTmp)) {
DEBUGLOG(("CreateNewRecord: client_ip [%s]\n", csTmp));
                PutField_CString(hHeader, "ip_addr", csTmp);
	}

        if (GetField_CString(hMyHash, "service", &csTmp)) {
DEBUGLOG(("CreateNewRecord: service [%s]\n", csTmp));
		PutField_CString(hHeader, "service_code", csTmp);
        }

	if (GetField_CString(hMyHash, "country", &csTmp)) {
DEBUGLOG(("CreateNewRecord: country [%s]\n", csTmp));
		PutField_CString(hDetail, "txn_country", csTmp);
	}


	if (GetField_CString(hMyHash, "ccy", &csTmp)) {
DEBUGLOG(("CreateNewRecord: ccy [%s]\n", csTmp));
		PutField_CString(hHeader, "net_ccy", csTmp);
		PutField_CString(hDetail, "txn_ccy", csTmp);
	}

	
	if (GetField_Double(hMyHash, "amount", &dTmp)) {
DEBUGLOG(("CreateNewRecord: request_amt [%d]\n", dTmp));
		PutField_Double(hHeader, "txn_amt", dTmp);
	}

	PutField_CString(hHeader, "update_user", PD_UPDATE_USER);
	PutField_CString(hDetail, "update_user", PD_UPDATE_USER);


DEBUGLOG(("CreateNewRecord: DBTransaction Add\n"));

	DBObjPtr = CreateObj(DBPtr,"DBTransaction","Add");
	iRet = (unsigned long) ((*DBObjPtr)(hHeader));

	//iRet = Txn_Header_Add(hHeader);

	if (iRet == PD_OK ) {
DEBUGLOG(("CreateNewRecord: DBTransaction AddDetail\n"));

		DBObjPtr = CreateObj(DBPtr,"DBTransaction","AddDetail");
		iRet = (unsigned long) ((*DBObjPtr)(hDetail));

		//iRet = Txn_Detail_AddDetail(hDetail);
	}


        if (iRet == PD_OK) {
                if (GetField_CString(hMyHash, "txn_nmb", &csVNCRefNum)) {
                        PutField_CString(hHeader, "vnc_ref_num", csVNCRefNum);

                        if (UpdateHeaderVNCRef(hHeader) == PD_OK) {
DEBUGLOG(("CreateNewRecord: updated vnc_ref_num succ!\n"));
                        }
                        else {  
DEBUGLOG(("CreateNewRecord: updated vnc_ref_num fail!\n"));
                                iRet = FAILURE; 
                        }               
                }
        }




        hash_destroy(hHeader);
        FREE_ME(hHeader);

        hash_destroy(hDetail);
        FREE_ME(hDetail);

	FREE_ME(csTxnSeq);

	return iRet;	
}




int  process_deposit_reserved_approve(hash_t *hMyHash)
{
	int	iRet = SUCCESS;

	char	*csTmp = NULL;
	double	dTmp = 0.0;
	//char	cTmp;
	int	iTmp;

	char	*csTxnCode = NULL;

	hash_t	*hTxnElement;
	hash_t	*hDetail;
	hash_t	*hHeader;
	hash_t 	*hMerchBalance;
	
	char	csDate[PD_DATE_LEN + 1];
	

	hTxnElement= (hash_t *) malloc (sizeof(hash_t));
	hash_init(hTxnElement, 0);

	hDetail = (hash_t *) malloc(sizeof(hash_t));
	hash_init(hDetail, 0);

	hHeader= (hash_t *) malloc(sizeof(hash_t));
	hash_init(hHeader, 0);

	hMerchBalance = (hash_t *) malloc(sizeof(hash_t));
	hash_init(hMerchBalance, 0);

	PutField_Int(hHeader, "db_commit", PD_FALSE);

	PutField_CString(hHeader, "add_user", PD_UPDATE_USER);
	PutField_CString(hDetail, "add_user", PD_UPDATE_USER);

	PutField_CString(hHeader, "update_user", PD_UPDATE_USER);
	PutField_CString(hDetail, "update_user", PD_UPDATE_USER);

        if (GetField_Int(hMyHash, "db_commit", &iTmp)) {
                PutField_Int(hHeader, "db_commit", iTmp);
        }


	if (GetField_CString(hMyHash, "txn_date", &csTmp)) {
DEBUGLOG(("process_deposit_reserved_approve: approve_date [%s]\n", csTmp));

		strncpy(csDate, csTmp, PD_DATE_LEN);
		csDate[PD_DATE_LEN] = '\0';

DEBUGLOG(("process_deposit_reserved_approve: re-format approve_date [%s]\n", csDate));

		PutField_CString(hHeader, "approval_date", csDate);
	}

	PutField_CString(hHeader, "sub_status", PD_APPROVED);

	if (GetField_CString(hMyHash, "txn_code", &csTxnCode)) {
DEBUGLOG(("process_deposit_reserved_approve: txn_code [%s]\n", csTxnCode));
		PutField_CString(hHeader, "txn_code", csTxnCode);
	}

	if (GetField_CString(hMyHash, "txn_seq", &csTmp)) {
DEBUGLOG(("process_deposit_reserved_approve: txn_seq [%s]\n", csTmp));
		PutField_CString(hHeader, "txn_seq", csTmp);
		PutField_CString(hDetail, "txn_seq", csTmp);

		//PutField_CString(hTxnElement, "from_txn_seq", csTmp);
		PutField_CString(hTxnElement, "org_txn_seq", csTmp);
	}

	if (GetField_CString(hMyHash, "ccy", &csTmp)) {
DEBUGLOG(("process_deposit_reserved_approve: ccy [%s]\n", csTmp));
		PutField_CString(hDetail, "txn_ccy", csTmp);

		PutField_CString(hTxnElement, "org_txn_ccy", csTmp);
		PutField_CString(hTxnElement, "org_txn_fee_ccy", csTmp);
	}

	if (GetField_CString(hMyHash, "country", &csTmp)) {
DEBUGLOG(("process_deposit_reserved_approve: country [%s]\n", csTmp));
		PutField_CString(hDetail, "txn_country", csTmp);
	}

	iRet = HandleDepositReservedBalance(hMyHash, hMerchBalance);


	if (iRet == SUCCESS)  {
		if (GetField_Double(hMerchBalance, "merchant_open_bal", &dTmp)) {
DEBUGLOG(("process_deposit_reserved_approve: open_bal [%lf]\n", dTmp));
			PutField_Double(hDetail, "open_bal", dTmp);
		}
		if (GetField_Double(hMerchBalance, "merchant_open_bal_settlement", &dTmp)) {
DEBUGLOG(("process_deposit_reserved_approve: open_bal_settlement [%lf]\n", dTmp));
			PutField_Double(hDetail, "open_bal_settlement", dTmp);
		}

		if (GetField_Double(hMerchBalance, "total_float", &dTmp)) {
DEBUGLOG(("process_deposit_reserved_approve: total_float [%lf]\n", dTmp));
			PutField_Double(hDetail, "total_float", dTmp);
		}

		if (GetField_Double(hMerchBalance, "current_bal", &dTmp)) {
DEBUGLOG(("process_deposit_reserved_approve: current_bal [%lf]\n", dTmp));
			PutField_Double(hDetail, "current_bal", dTmp);
		}

		if (GetField_Double(hMerchBalance, "total_reserved_amount", &dTmp)) {
DEBUGLOG(("process_deposit_reserved_approve: total_reserved_amount [%lf]\n", dTmp));
			PutField_Double(hDetail, "total_reserved_amount", dTmp);
		}
		if (GetField_Double(hMerchBalance, "total_hold", &dTmp)) {
DEBUGLOG(("process_deposit_reserved_approve: total_hold [%lf]\n", dTmp));
			PutField_Double(hDetail, "total_hold", dTmp);
		}
		if (GetField_Double(hMerchBalance, "total_float_settlement", &dTmp)) {
DEBUGLOG(("process_deposit_reserved_approve: total_float_settlement [%lf]\n", dTmp));
			PutField_Double(hDetail, "total_float_settlement", dTmp);
		}

		if (GetField_Double(hMerchBalance, "current_bal_settlement", &dTmp)) {
DEBUGLOG(("process_deposit_reserved_approve: current_bal_settlement[%lf]\n", dTmp));
			PutField_Double(hDetail, "current_bal_settlement", dTmp);
		}

		if (GetField_Double(hMerchBalance, "total_hold_settlement", &dTmp)) {
DEBUGLOG(("process_deposit_reserved_approve: total_hold_settlement [%lf]\n", dTmp));
			PutField_Double(hDetail, "total_hold_settlement", dTmp);
		}
		if (GetField_Double(hMerchBalance, "total_float_after_payout", &dTmp)) {
DEBUGLOG(("process_deposit_reserved_approve: total_float_after_payout [%lf]\n", dTmp));
			PutField_Double(hDetail, "total_float_after_payout", dTmp);
		}

		if (GetField_Double(hMerchBalance, "fundin_payout", &dTmp)) {
DEBUGLOG(("process_deposit_reserved_approve: fundin_payout [%lf]\n", dTmp));
			PutField_Double(hDetail, "fundin_payout", dTmp);
		}
		if (GetField_Double(hMerchBalance, "reserved_payout", &dTmp)) {
DEBUGLOG(("process_deposit_reserved_approve: reserved_payout [%lf]\n", dTmp));
			PutField_Double(hDetail, "reserved_payout", dTmp);
		}

		if (GetField_Double(hMyHash, "net_amt", &dTmp)) {
DEBUGLOG(("process_deposit_reserved_approve: net_amt [%lf]\n", dTmp));
			PutField_Double(hHeader, "net_amt", dTmp);
		}
	}

	if (iRet == SUCCESS) {
DEBUGLOG(("CreateNewRecord: DBTransaction AddDetail\n"));
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","AddDetail");
		iRet = (unsigned long) ((*DBObjPtr)(hDetail));
		/*
		iRet = Txn_Detail_AddDetail(hDetail);
		*/
	}

	if (iRet == SUCCESS) {
DEBUGLOG(("CreateNewRecord: DBTransaction UpdateDetail\n"));
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","UpdateDetail");
		iRet = (unsigned long) ((*DBObjPtr)(hDetail));

		//iRet = Txn_Detail_UpdateDetail(hDetail);
	}


	if (iRet == SUCCESS) {
		// Element Amt
		if (GetField_Double(hMyHash, "amount", &dTmp)) {
			PutField_Double(hHeader, "txn_amt", dTmp);

			//PutField_Double(hTxnElement, "org_txn_amt", dTmp);
			PutField_Double(hTxnElement, "reserve_amt", dTmp);

			PutField_Char(hTxnElement, "party_type", PD_TYPE_MERCHANT);
		}

		PutField_CString(hTxnElement, "amount_type",  PD_DR);
  		/*
		if (GetField_Char(hMyHash, "dc_ind", &cTmp)) {
			if (cTmp == PD_ADJ_TYPE_CREDIT) {
				PutField_CString(hTxnElement, "amount_type", PD_CR);
			}
			if (cTmp == PD_ADJ_TYPE_DEBIT) {
				PutField_CString(hTxnElement, "amount_type", PD_DR);
			}
		}
		*/

		iRet = prbo_AddReserveAmtElement(hTxnElement);
	}

    

	if (iRet == SUCCESS) {

		PutField_Char(hHeader, "status", PD_COMPLETE);
		PutField_Char(hHeader, "ar_ind", PD_ACCEPT);

		PutField_CString(hHeader, "process_type", "0000");
		PutField_CString(hHeader, "process_code", "000000");


		if (GetField_CString(hMyHash, "merchant_client_id", &csTmp)) {
			PutField_CString(hHeader, "client_id", csTmp);
		}

		if (GetField_CString(hMyHash, "service", &csTmp)) {
			PutField_CString(hHeader, "service_code", csTmp);
		}

DEBUGLOG(("process_deposit_reserved_approve: DBTransaction Update\n"));
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","Update");
		iRet = (unsigned long) ((*DBObjPtr)(hHeader));
		//iRet = Txn_Header_Update(hHeader);
	}

	/*

        if (iRet == SUCCESS) {
		iRet = UpdateApprovalTimestamp(hHeader);
        }
	*/


	hash_destroy(hTxnElement);
	FREE_ME(hTxnElement);

	hash_destroy(hDetail);
	FREE_ME(hDetail);

	hash_destroy(hHeader);
	FREE_ME(hHeader);

	hash_destroy(hMerchBalance);
	FREE_ME(hMerchBalance);


	return iRet;
}


int  process_release_deposit_reserved(hash_t *hMyHash)
{
	int iRet = SUCCESS;

	char	*csTxnSeq;
	//char	*csOrgTxnSeq;

	char	*csTmp;
	double  dTmp;
	//char	cTmp;
	//int	iTmp;
	
	char	csDate[PD_DATE_LEN + 1];
	int	iRecordExists = PD_FALSE;


	hash_t 	*hHeader, *hTxnElement, *hMerchBalance, *hDetail;

	hHeader= (hash_t *) malloc(sizeof(hash_t));
	hash_init(hHeader, 0);

	hTxnElement = (hash_t *) malloc(sizeof(hash_t));
	hash_init(hTxnElement, 0);

	hMerchBalance= (hash_t *) malloc(sizeof(hash_t));
	hash_init(hMerchBalance, 0);

	hDetail= (hash_t *) malloc(sizeof(hash_t));
	hash_init(hDetail, 0);

	PutField_Int(hHeader, "db_commit", PD_FALSE);


	PutField_CString(hHeader, "add_user", PD_UPDATE_USER);
	PutField_CString(hDetail, "add_user", PD_UPDATE_USER);

	PutField_CString(hHeader, "update_user", PD_UPDATE_USER);
	PutField_CString(hDetail, "update_user", PD_UPDATE_USER);

	//PutField_Char(hHeader, "status", PD_REVERSED);
	//PutField_Char(hHeader, "ar_ind", PD_ACCEPT);
	//PutField_CString(hHeader, "sub_status", PD_VOID);


	if (GetField_CString(hMyHash, "txn_seq", &csTxnSeq)) {
		PutField_CString(hHeader, "txn_seq", csTxnSeq);
	}

        if (GetField_Int(hMyHash, "record_exists", &iRecordExists)) {
DEBUGLOG(("process_release_deposit_reserved : record_exists [%d]\n", iRecordExists));
        }

	
        if (iRecordExists == PD_FALSE) {
DEBUGLOG(("process_release_deposit_reserved : set posting date\n")); 
		if (GetField_CString(hMyHash, "txn_date", &csTmp)) {
			PutField_CString(hHeader, "host_posting_date", csTmp);
			PutField_CString(hHeader, "approval_date", csTmp);
		}
	}

	if (iRecordExists == PD_TRUE) {
		if (GetField_CString(hMyHash, "post_date", &csTmp)) {
			PutField_CString(hHeader, "host_posting_date", csTmp);
			PutField_CString(hHeader, "approval_date", csTmp);
		}

		if (GetField_CString(hMyHash, "txn_date", &csTmp)) {
DEBUGLOG(("process_release_deposit_reserved: org reserved_release_date [%s]\n", csTmp));

			strncpy(csDate, csTmp, PD_DATE_LEN);	
			csDate[PD_DATE_LEN] = '\0';

			PutField_CString(hHeader, "reserved_release_date", csDate);
		}


DEBUGLOG(("process_release_deposit_reserved: Transaction Update\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTransaction", "Update");
		iRet = (unsigned long) ((*DBObjPtr)(hHeader));
		//iRet = Txn_Header_Update(hHeader);

		/*
		if (iRet == SUCCESS) {
			iRet = UpdateApprovalTimestamp(hHeader);
        	}
		*/
	}

	if (iRet == SUCCESS) {
		PutField_Int(hMyHash, "init_mode", PD_FALSE);

		//PutField_CString(hMyHash, "org_txn_seq", csTxnSeq);

		if (GetField_CString(hMyHash, "reversal_txn_code", &csTmp)) {
			PutField_CString(hHeader, "txn_code", csTmp);
			PutField_CString(hMyHash, "reverse_txn_code", csTmp);
		}
DEBUGLOG(("Create NewDepositReservedTxn\n"));
		iRet = CreateNewDepositReservedTxn(hMyHash);
	}

	if (iRet == SUCCESS) {
		//GetField_CString(hMyHash, "org_txn_seq", &csOrgTxnSeq);
		GetField_CString(hMyHash, "txn_seq", &csTxnSeq);

		PutField_CString(hTxnElement, "from_txn_seq", csTxnSeq);
		PutField_CString(hTxnElement, "org_txn_seq", csTxnSeq);
		PutField_CString(hHeader, "txn_seq", csTxnSeq);
		PutField_CString(hDetail, "txn_seq", csTxnSeq);
	}



	if (GetField_CString(hMyHash, "txn_date", &csTmp)) {
DEBUGLOG(("process_release_deposit_reserved: approve_date [%s]\n", csTmp));

		strncpy(csDate, csTmp, PD_DATE_LEN);	
		csDate[PD_DATE_LEN] = '\0';
DEBUGLOG(("process_release_deposit_reserved: re-format approve_date [%s]\n", csDate));

                PutField_CString(hHeader, "approval_date", csDate);

	}

	PutField_Char(hHeader, "status", PD_COMPLETE);
	PutField_Char(hHeader, "ar_ind", PD_ACCEPT);
	//RemoveField_CString(hHeader, "sub_status");
	PutField_CString(hHeader, "sub_status", PD_APPROVED);

	PutField_Int(hMyHash, "void_flag", PD_TRUE);


        if (GetField_CString(hMyHash, "ccy", &csTmp)) {
DEBUGLOG(("process_release_deposit_reserved: ccy [%s]\n", csTmp));
                PutField_CString(hDetail, "txn_ccy", csTmp);
                PutField_CString(hTxnElement, "org_txn_ccy", csTmp);
                PutField_CString(hTxnElement, "org_txn_fee_ccy", csTmp);
        }

        if (GetField_CString(hMyHash, "country", &csTmp)) {
DEBUGLOG(("process_release_deposit_reserved: country [%s]\n", csTmp));
                PutField_CString(hDetail, "txn_country", csTmp);
        }

        iRet = HandleDepositReservedBalance(hMyHash, hMerchBalance);


	if (iRet == SUCCESS)  {
                if (GetField_Double(hMerchBalance, "merchant_open_bal", &dTmp)) {
DEBUGLOG(("process_release_deposit_reserved: open_bal [%lf]\n", dTmp));
                        PutField_Double(hDetail, "open_bal", dTmp);
                }
		if (GetField_Double(hMerchBalance, "merchant_open_bal_settlement", &dTmp)) {
DEBUGLOG(("process_release_deposit_reserved: open_bal_settlement  [%lf]\n", dTmp));
                        PutField_Double(hDetail, "open_bal_settlement", dTmp);
		}

                if (GetField_Double(hMerchBalance, "current_bal", &dTmp)) {
DEBUGLOG(("process_release_deposit_reserved: current_bal [%lf]\n", dTmp));
                        PutField_Double(hDetail, "current_bal", dTmp);
                }

                if (GetField_Double(hMerchBalance, "total_float", &dTmp)) {
DEBUGLOG(("process_release_deposit_reserved: total_float [%lf]\n", dTmp));
                        PutField_Double(hDetail, "total_float", dTmp);
                }

                if (GetField_Double(hMerchBalance, "current_bal_settlement", &dTmp)) {
DEBUGLOG(("process_release_deposit_reserved: current_bal_settlement [%lf]\n", dTmp));
                        PutField_Double(hDetail, "current_bal_settlement", dTmp);
                }

                if (GetField_Double(hMerchBalance, "total_float_settlement", &dTmp)) {
DEBUGLOG(("process_release_deposit_reserved: total_float_settlement [%lf]\n", dTmp));
                        PutField_Double(hDetail, "total_float_settlement", dTmp);
                }

                if (GetField_Double(hMerchBalance, "total_reserved_amount", &dTmp)) {
DEBUGLOG(("process_release_deposit_reserved: total_reserved_amount [%lf]\n", dTmp));
                        PutField_Double(hDetail, "total_reserved_amount", dTmp);
                }
                if (GetField_Double(hMerchBalance, "total_hold", &dTmp)) {
DEBUGLOG(("process_release_deposit_reserved: total_hold [%lf]\n", dTmp));
                        PutField_Double(hDetail, "total_hold", dTmp);
                }
                if (GetField_Double(hMerchBalance, "total_hold_settlement", &dTmp)) {
DEBUGLOG(("process_release_deposit_reserved: total_hold_settlement [%lf]\n", dTmp));
                        PutField_Double(hDetail, "total_hold_settlement", dTmp);
                }
                if (GetField_Double(hMerchBalance, "total_float_after_payout", &dTmp)) {
DEBUGLOG(("process_release_deposit_reserved: total_float_after_payout [%lf]\n", dTmp));
                        PutField_Double(hDetail, "total_float_after_payout", dTmp);
                }
                if (GetField_Double(hMerchBalance, "fundin_payout", &dTmp)) {
DEBUGLOG(("process_release_deposit_reserved: fundin_payout[%lf]\n", dTmp));
                        PutField_Double(hDetail, "fundin_payout", dTmp);
                }

                if (GetField_Double(hMerchBalance, "reserved_payout", &dTmp)) {
DEBUGLOG(("process_release_deposit_reserved: reserved_payout [%lf]\n", dTmp));
                        PutField_Double(hDetail, "reserved_payout", dTmp);
                }
                if (GetField_Double(hMyHash, "net_amt", &dTmp)) {
DEBUGLOG(("process_release_deposit_reserved: net_amt [%lf]\n", dTmp));
                        PutField_Double(hHeader, "net_amt", dTmp);
                }
        }


        if (iRet == SUCCESS) {
DEBUGLOG(("process_release_deposit_reserved: DBTransaction AddDetail\n"));
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","AddDetail");
                iRet = (unsigned long) ((*DBObjPtr)(hDetail));
		//iRet = Txn_Detail_AddDetail(hDetail);
        }

        if (iRet == SUCCESS) {
DEBUGLOG(("process_release_deposit_reserved: DBTransaction UpdateDetail\n"));
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","UpdateDetail");
                iRet = (unsigned long) ((*DBObjPtr)(hDetail));

		//iRet = Txn_Detail_UpdateDetail(hDetail);
        }

        if (iRet == SUCCESS) {
                // Element Amt
                if (GetField_Double(hMyHash, "amount", &dTmp)) {
                        PutField_Double(hHeader, "txn_amt", dTmp);

                        //PutField_Double(hTxnElement, "org_txn_amt", dTmp);
                        PutField_Double(hTxnElement, "reserve_amt", dTmp);
                        PutField_Char(hTxnElement, "party_type", PD_TYPE_MERCHANT);
                }

		PutField_CString(hTxnElement, "amount_type",  PD_CR);
		/*

                if (GetField_Char(hMyHash, "dc_ind", &cTmp)) {
                        if (cTmp == PD_ADJ_TYPE_CREDIT) {
                                PutField_CString(hTxnElement, "amount_type", PD_DR);
                        }
                        if (cTmp == PD_ADJ_TYPE_DEBIT) {
                                PutField_CString(hTxnElement, "amount_type", PD_CR);
                        }
                }
		*/


DEBUGLOG(("process_release_deposit_reserved: AddTxnAmtElement\n"));
                iRet = prbo_AddReserveAmtElement(hTxnElement);
        }




        if (iRet == SUCCESS) {

                PutField_Char(hHeader, "status", PD_COMPLETE);
                PutField_Char(hHeader, "ar_ind", PD_ACCEPT);

                PutField_CString(hHeader, "process_type", "0000");
                PutField_CString(hHeader, "process_code", "000000");


                if (GetField_CString(hMyHash, "merchant_client_id", &csTmp)) {
                        PutField_CString(hHeader, "client_id", csTmp);
                }

                if (GetField_CString(hMyHash, "service", &csTmp)) {
                        PutField_CString(hHeader, "service_code", csTmp);
                }

DEBUGLOG(("process_release_deposit_reserved: DBTransaction Update\n"));
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","Update");
                iRet = (unsigned long) ((*DBObjPtr)(hHeader));

		//iRet = Txn_Header_Update(hHeader);
        }

	/*
        if (iRet == SUCCESS) {
		iRet = UpdateApprovalTimestamp(hHeader);
        }
	*/



	hash_destroy(hHeader);
	FREE_ME(hHeader);

	hash_destroy(hTxnElement);
	FREE_ME(hTxnElement);

	hash_destroy(hMerchBalance);
	FREE_ME(hMerchBalance);

	hash_destroy(hDetail);
	FREE_ME(hDetail);

	return iRet;
}


int	HandleDepositReservedBalance(hash_t *hMyHash, hash_t *hMerchBalance)
{

	int	iRet = SUCCESS;

	char	*csTxnCode = NULL;
	char	*csTxnStatus = NULL;
	//char	cDCInd;

	double	dAmt = 0.0;
	//double	dFee = 0.0;
	double	dNetAmt = 0.0;
	double	dTmpNetAmt = 0.0;

	char	*csMID;
	char	*csCountry;
	char	*csCcy;
	char	*csService;
	//char	*csUser;

	double	dTmp = 0.0;
	
	int	iVoidFlag = PD_FALSE;	

        //recordset_t     *rRecordSet;
        //hash_t          *hRec;

        //rRecordSet = (recordset_t *)malloc(sizeof(recordset_t));
        //recordset_init(rRecordSet, 0);

	if (GetField_CString(hMyHash, "txn_code", &csTxnCode)) {
DEBUGLOG(("HandleDepositReservedBalance: txn_code [%s]\n", csTxnCode));
	}

	if (GetField_CString(hMyHash, "txn_status", &csTxnStatus)) {
DEBUGLOG(("HandleDepositReservedBalance: txn_status [%s]\n", csTxnStatus));
	}


        if (iRet == PD_OK) {
                if (GetField_Double(hMyHash, "amount", &dAmt)) {
DEBUGLOG(("HandleDepositReservedBalance: amount [%lf]\n", dAmt));
                }

		/*
                if (GetField_Double(hMyHash, "fee", &dFee)) {
DEBUGLOG(("HandleDepositReservedBalance: fee [%lf]\n", dFee));
                }
		*/

		// !!!!! if reserved,  -> positive; else if release, -> negative
		if (!strcmp(csTxnStatus, "MERCHANT_RESERVE_REVERSED")) {
			dTmpNetAmt =  (-1) * dAmt;
		} else {
			dTmpNetAmt =  dAmt;
		}

		dNetAmt = dAmt;

DEBUGLOG(("HandleDepositReservedBalance: net_amt[%lf]\n", dNetAmt));

		PutField_Double(hMyHash, "net_amt", dNetAmt);
		PutField_Double(hMerchBalance, "net_amt", dNetAmt);
        }

	if (iRet == PD_OK) {
		if (GetField_Int(hMyHash, "void_flag", &iVoidFlag)) {
DEBUGLOG(("HandleDepositReservedBalance: void_flag [%d]\n", iVoidFlag));
		}
		else {
			iVoidFlag = PD_FALSE;
		}

		PutField_Int(hMerchBalance, "void_flag", iVoidFlag);

		if (GetField_CString(hMyHash, "merchant_id", &csMID)) {
DEBUGLOG(("HandleDepositReservedBalance: merchant_id [%s]\n", csMID));
			PutField_CString(hMerchBalance, "merchant_id", csMID);
		}
	
		if (GetField_CString(hMyHash, "country", &csCountry)) {
DEBUGLOG(("HandleDepositReservedBalance: country [%s]\n", csCountry));
			PutField_CString(hMerchBalance, "txn_country", csCountry);
		}

		if (GetField_CString(hMyHash, "ccy", &csCcy)) {
DEBUGLOG(("HandleDepositReservedBalance: ccy [%s]\n", csCcy));
			PutField_CString(hMerchBalance, "txn_ccy", csCcy);
		}

		if (GetField_CString(hMyHash, "service", &csService)) {
DEBUGLOG(("HandleDepositReservedBalance: service [%s]\n", csService));
			PutField_CString(hMerchBalance, "service_code", csService);
		}

		PutField_CString(hMerchBalance, "add_user", PD_UPDATE_USER);
		
		iRet = prbo_GetOpenBalanceForUpdate(hMerchBalance, csMID, csCcy, csCountry, csService);

		if (iRet == SUCCESS) {
			if (GetField_Double(hMerchBalance, "merchant_open_bal", &dTmp)) {
DEBUGLOG(("HandleDepositReservedBalance: merchant_open_bal [%lf]\n", dTmp));
			}

			if (GetField_Double(hMerchBalance, "merchant_open_bal_settlement", &dTmp)) {
DEBUGLOG(("HandleDepositReservedBalance: merchant_open_bal_settlement [%lf]\n", dTmp));
			}
		}
			
	
		if (iRet == SUCCESS) {	
			iRet = prbo_UpdateReserved(csMID, csCountry, csCcy, csService, dTmpNetAmt, PD_UPDATE_USER);
		}

		if (iRet == SUCCESS) {
			iRet = prbo_GetCurrentValues(csMID, csCcy, csCountry, csService, hMerchBalance);
		}


		if (iRet == SUCCESS) {	

			if (GetField_Double(hMerchBalance, "current_bal", &dTmp)) {
DEBUGLOG(("HandleDepositReservedBalance: current_bal[%lf]\n", dTmp));
			}

			if (GetField_Double(hMerchBalance, "total_float", &dTmp)) {
DEBUGLOG(("HandleDepositReservedBalance: total_float[%lf]\n", dTmp));
			}

			if (GetField_Double(hMerchBalance, "current_bal_settlement", &dTmp)) {
DEBUGLOG(("HandleDepositReservedBalance: current_bal_settlement [%lf]\n", dTmp));
			}

			if (GetField_Double(hMerchBalance, "total_float_settlement", &dTmp)) {
DEBUGLOG(("HandleDepositReservedBalance: total_float_settlement [%lf]\n", dTmp));
			}

			if (GetField_Double(hMerchBalance, "total_reserved_amount", &dTmp)) {
DEBUGLOG(("HandleDepositReservedBalance: total_reserved_amount [%lf]\n", dTmp));
			}

			if (GetField_Double(hMerchBalance, "total_hold", &dTmp)) {
DEBUGLOG(("HandleDepositReservedBalance: total_hold [%lf]\n", dTmp));
			}

			if (GetField_Double(hMerchBalance, "total_hold_settlement", &dTmp)) {
DEBUGLOG(("HandleDepositReservedBalance: total_hold_settlement [%lf]\n", dTmp));
			}
			if (GetField_Double(hMerchBalance, "total_hold_after_payout", &dTmp)) {
DEBUGLOG(("HandleDepositReservedBalance: total_hold_after_payout [%lf]\n", dTmp));
			}

			if (GetField_Double(hMerchBalance, "fundin_payout", &dTmp)) {
DEBUGLOG(("HandleDepositReservedBalance: fundin_payout [%lf]\n", dTmp));
			}
			if (GetField_Double(hMerchBalance, "reserved_payout", &dTmp)) {
DEBUGLOG(("HandleDepositReservedBalance: reserved_payout [%lf]\n", dTmp));
			}

		}

	}



        //RecordSet_Destroy(rRecordSet);
        //FREE_ME(rRecordSet);

        return iRet;
}
