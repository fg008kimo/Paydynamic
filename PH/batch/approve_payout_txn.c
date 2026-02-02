
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
    "approve_payout_txn.pc"
};


static unsigned int sqlctx = 152360139;


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
Init Version                                       2016/07/05              LokMan Chow
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

char    cs_txn_id[PD_TXN_SEQ_LEN+1];

char cDebug = 'Y';
OBJPTR(BO);
OBJPTR(DB);
OBJPTR(Txn);

int parse_arg(int argc,char **argv);

int batch_init(int argc, char* argv[])
{

    if (argc < 2) {
        printf("usage: -t txn_id \n");
        return FAILURE;
    }
    else
        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
        int     iRet = PD_OK;

	//char	*csTxnSeq;
	//char	*csBatchId;
	char	*csTmp;
	char    *csTxnCcy;
	//char    csTag[PD_TAG_LEN +1];
	double	dTmp=0.0;
	unsigned long	lBatchId;
	int	iTmp = 0;
	//int	iStatus = 0;
	//int	iCnt = 0;
	//int	i = 0;
	//char	*csIdentityId;
	//int	iChk = 0;
	hash_t  *hRec;
	hash_t  *hTxn;
        hTxn = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTxn,0);

	hash_t  *hContext;
        hContext = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hContext,0);

	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);


	iRet = parse_arg(argc,argv);

        if (iRet != SUCCESS) {
                printf("usage: -t txn_id\n");
                return (iRet);
        }

DEBUGLOG(("Authorize\n"));

DEBUGLOG(("Authorize::txn_id= [%s]\n",cs_txn_id));

	if(iRet == PD_OK){
DEBUGLOG(("Authorize::call OLMerchantUploadFileDetail->GetDetailByTxnId\n"));
                DBObjPtr = CreateObj(DBPtr,"DBOLMerchantUploadFileDetail","GetDetailByTxnId");
                iRet = (unsigned long)(*DBObjPtr)(cs_txn_id,rRecordSet);
		if(iRet==PD_OK){
			hRec= RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if(GetField_CString(hRec,"account_num",&csTmp)){
					PutField_CString(hContext,"account_id",csTmp);
				}
				if(GetField_CString(hRec,"payout_ccy",&csTmp)){
					PutField_CString(hContext,"dst_txn_ccy",csTmp);
				}
				if(GetField_CString(hRec,"request_ccy",&csTmp)){
					if(strcmp(csTmp,"RMB"))
						csTxnCcy = strdup(csTmp);
					else
						csTxnCcy = strdup(PD_CCY_ISO_CNY);
					PutField_CString(hContext,"txn_ccy",csTxnCcy);
					PutField_CString(hContext,"net_ccy",csTxnCcy);
					FREE_ME(csTxnCcy);

				}
				if (GetField_Double(hRec,"request_amount",&dTmp)) {
					PutField_Double(hContext,"txn_amt",dTmp);
				}
				if(GetField_CString(hRec,"batch_id",&csTmp)){
					lBatchId = ctol((const unsigned char *)csTmp,strlen(csTmp));
					PutField_CString(hContext,"batch_id",csTmp);
				}
				if(GetField_Int(hRec,"seq_num",&iTmp)){
					PutField_Int(hContext,"seq_num",iTmp);
				}
				if (GetField_CString(hRec,"txn_country",&csTmp)) {
					PutField_CString(hContext,"txn_country",csTmp);
				}
				
				hRec= RecordSet_GetNext(rRecordSet);
			}
		}
		RecordSet_Destroy(rRecordSet);

		if(iRet==PD_OK){
			recordset_init(rRecordSet,0);
			
			DBObjPtr = CreateObj(DBPtr,"DBOLMerchantUploadFileHeader","GetHeader");
			iRet = (unsigned long)(*DBObjPtr)(lBatchId,rRecordSet);
			if(iRet==PD_OK){
				hRec = RecordSet_GetFirst(rRecordSet);
				while (hRec) {
					if(GetField_CString(hRec,"merchant_id",&csTmp)){
						PutField_CString(hContext,"merchant_id",csTmp);
					}
					if(GetField_CString(hRec,"service_code",&csTmp)){
						PutField_CString(hContext,"service_code",csTmp);
					}
					hRec = RecordSet_GetNext(rRecordSet);
				}
			}
		}
        }

	if(iRet == PD_OK){
DEBUGLOG(("Authorize::call BOOLMerchant->GetMerchantTxnInfo\n"));
                BOObjPtr = CreateObj(BOPtr,"BOOLMerchant","GetMerchantTxnInfo");
                iRet = (unsigned long)(*BOObjPtr)(hContext,hContext);
        }

	char csTmpDate[PD_DATETIME_LEN +1];
        DBObjPtr = CreateObj(DBPtr,"DBSystemControl","FindCode");

        if ((unsigned long)(*DBObjPtr)("CTPHDATE",csTmpDate) == FOUND) {
DEBUGLOG(("Authorize:Current Processor Hub Date= [%s]\n",csTmpDate));
		int iDayOfWeek=day_of_week((const unsigned char *)csTmpDate);
                PutField_Int(hContext,"day_of_week",iDayOfWeek);
DEBUGLOG(("Authorize::day_of_week = [%d]\n",iDayOfWeek));
        }
        else {
DEBUGLOG(("Authorize:NOT RECORD\n"));
                iRet = INT_ERR;
ERRLOG("Authorize::Internal Error:WEB Channel:SystemControl Record Not Found\n");
        }

	if(iRet==PD_OK){
DEBUGLOG(("Authorize::call BOOLPayout->CheckAvalBalance\n"));
                BOObjPtr = CreateObj(BOPtr,"BOOLPayout","CheckAvalBalance");
                iRet = (unsigned long)(*BOObjPtr)(hContext,hContext);
        }

        if(iRet==PD_OK){
                if(GetField_Double(hContext,"merchant_net_float",&dTmp)){
                        PutField_Double(hContext,"remain_merchant_net_float",dTmp);
DEBUGLOG(("Authorize::merchant_net_float = [%lf]\n",dTmp));
                }
                if(GetField_Double(hContext,"merchant_reserved_po",&dTmp)){
                        PutField_Double(hContext,"remain_merchant_reserved_po",dTmp);
DEBUGLOG(("Authorize::merchant_reserved_po = [%lf]\n",dTmp));
                }
                if(GetField_Double(hContext,"merchant_fundin_po",&dTmp)){
DEBUGLOG(("Authorize::merchant_fundin_po = [%lf]\n",dTmp));
                }
        }

	if(iRet == PD_OK){
		PutField_CString(hContext,"txn_seq",cs_txn_id);
		PutField_CString(hContext,"txn_code",PD_OL_PAYOUT_APPROVE);
		PutField_CString(hContext,"channel_code",PD_CHANNEL_OMT);
		PutField_CString(hContext,"update_user",PD_UPDATE_USER);
		PutField_CString(hContext,"add_user",PD_UPDATE_USER);

		PutField_Int(hContext,"status",PAYOUT_MASTER_TRANSACTION_CONFIRMED);

		TxnObjPtr = CreateObj(TxnPtr,"TxnOmtByUsPOT","Authorize");
		iRet = (unsigned long)(*TxnObjPtr)(hContext,hContext,hContext);
		
	}


DEBUGLOG(("TxnOmtByUsPOC Normal Exit() iRet = [%d]\n",iRet));
	FREE_ME(hTxn);
	FREE_ME(hContext);
	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);
	return iRet;
}

int batch_terminate(int argc, char* argv[])
{
        return SUCCESS;
}


int parse_arg(int argc,char **argv)
{
        char    c;
        strcpy(cs_txn_id,"");

        while ((c = getopt(argc,argv,"t:")) != EOF) {
                switch (c) {
                        case 't':
                                strcpy(cs_txn_id, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_txn_id,"")) 
                return FAILURE;

        return SUCCESS;
}
