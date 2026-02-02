
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
    "create_payout_txn.pc"
};


static unsigned int sqlctx = 75224267;


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
Init Version                                       2016/07/04              LokMan Chow
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
OBJPTR(Channel);

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
	char    csLocalTxnDateTime[PD_DATETIME_LEN+1];
        char    csTmDate[PD_DATE_LEN+1];
        char    csTmTime[PD_TIME_LEN+1];
	double	dTmp=0.0;
	unsigned long	lBatchId;
	//int	iTmp = 0;
	//int	iStatus = 0;
	//int	iCnt = 0;
	//int	i = 0;
	//char	*csIdentityId;
	//int	iChk = 0;
	hash_t  *hRec;
	hash_t  *hTxn;
        hTxn = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTxn,0);

	hash_t  *hRequest;
        hRequest = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hRequest,0);

	hash_t  *hContext;
        hContext = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hContext,0);

	hash_t  *hResponse;
        hResponse = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hResponse,0);

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
	PutField_CString(hTxn,"txn_id",cs_txn_id);
	PutField_CString(hRequest,"txn_id",cs_txn_id);

	char csTmpDate[PD_DATETIME_LEN +1];
        DBObjPtr = CreateObj(DBPtr,"DBSystemControl","FindCode");

        if ((unsigned long)(*DBObjPtr)("CTPHDATE",csTmpDate) == FOUND) {
DEBUGLOG(("Authorize:Current Processor Hub Date= [%s]\n",csTmpDate));
                PutField_CString(hContext,"PHDATE",csTmpDate);
        }
        else {
DEBUGLOG(("Authorize:NOT RECORD\n"));
                iRet = INT_ERR;
ERRLOG("Authorize::Internal Error:WEB Channel:SystemControl Record Not Found\n");
        }

	if(iRet == PD_OK){
DEBUGLOG(("Authorize::call OLMerchantUploadFileDetail->GetDetailByTxnId\n"));
                DBObjPtr = CreateObj(DBPtr,"DBOLMerchantUploadFileDetail","GetDetailByTxnId");
                iRet = (unsigned long)(*DBObjPtr)(cs_txn_id,rRecordSet);
		if(iRet==PD_OK){
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if(GetField_CString(hRec,"merchant_ref",&csTmp)){
					PutField_CString(hRequest,"merchant_ref",csTmp);
				}
				if(GetField_CString(hRec,"txn_country",&csTmp)){
					PutField_CString(hContext,"txn_country",csTmp);
					PutField_CString(hRequest,"txn_country",csTmp);
				}
				if(GetField_CString(hRec,"bank_name",&csTmp)){
					PutField_CString(hRequest,"bank_name",csTmp);
				}
				if(GetField_CString(hRec,"request_ccy",&csTmp)){
					if(strcmp(csTmp,"RMB"))
						csTxnCcy = strdup(csTmp);
					else
						csTxnCcy = strdup(PD_CCY_ISO_CNY);
					PutField_CString(hRequest,"txn_ccy",csTxnCcy);
					PutField_CString(hContext,"txn_ccy",csTxnCcy);
					PutField_CString(hContext,"net_ccy",csTxnCcy);
					FREE_ME(csTxnCcy);

				}
				if (GetField_Double(hRec,"request_amount",&dTmp)) {
					PutField_Double(hContext,"txn_amt",dTmp);
				}
				if(GetField_CString(hRec,"batch_id",&csTmp)){
					lBatchId = ctol((const unsigned char *)csTmp,strlen(csTmp));
				}
				hRec = RecordSet_GetNext(rRecordSet);
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
						PutField_CString(hRequest,"merchant_id",csTmp);
					}
					if(GetField_CString(hRec,"service_code",&csTmp)){
						PutField_CString(hContext,"service_code",csTmp);
						PutField_CString(hRequest,"service_code",csTmp);
					}
					hRec = RecordSet_GetNext(rRecordSet);
				}
			}
		}
        }

	if(iRet == PD_OK){
DEBUGLOG(("Authorize::call BOOLMerchant->GetMerchantTxnInfo\n"));
                BOObjPtr = CreateObj(BOPtr,"BOOLMerchant","GetMerchantTxnInfo");
                iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
        }


	if(iRet == PD_OK){
		if(GetField_CString(hContext,"merchant_client_id",&csTmp)){
			PutField_CString(hRequest,"client_id",csTmp);
		}

		PutField_CString(hContext,"txn_seq",cs_txn_id);
		PutField_CString(hContext,"process_type","0000");
		PutField_CString(hContext,"process_code","000000");
		PutField_CString(hContext,"txn_code",PD_OL_PAYOUT_APPROVE);
		PutField_CString(hContext,"channel_code","OMT");
		PutField_Int(hContext,"do_logging",PD_TRUE);

		strcpy(csLocalTxnDateTime,getdatetime());
		sprintf(csTmDate,"%.*s",PD_DATE_LEN,csLocalTxnDateTime);
		PutField_CString(hContext,"local_tm_date",csTmDate);

		sprintf(csTmTime,"%.*s",PD_TIME_LEN,&csLocalTxnDateTime[PD_DATE_LEN]);
		PutField_CString(hContext,"local_tm_time",csTmTime);

DEBUGLOG(("Authorize::Call OMTChannel:AddTxnLog\n"));
		ChannelObjPtr = CreateObj(ChannelPtr,"OMTChannel","AddTxnLog");
		if((unsigned long) ((*ChannelObjPtr)(hContext,hRequest))!=PD_OK){
			iRet = INT_ERR;
DEBUGLOG(("Authorize::OMTChannel:AddTxnLog Failed\n"));
		}

		if(iRet==PD_OK){
			PutField_CString(hContext,"sub_status",PD_UPLOAD_CONFIRMED);
			PutField_Char(hContext,"status",PD_TO_PSP);
			PutField_Int(hContext,"internal_code",PD_OK);
			PutField_CString(hContext,"response_code","0");
DEBUGLOG(("Authorize::Call OMTChannel:UpdateTxnLog\n"));
			ChannelObjPtr = CreateObj(ChannelPtr,"OMTChannel","UpdateTxnLog");
			if((unsigned long) ((*ChannelObjPtr)(hContext,hRequest,hResponse))!=PD_OK){
				iRet = INT_ERR;
DEBUGLOG(("Authorize::OMTChannel:AddTxnLog Failed\n"));
			}
			PutField_Int(hContext,"do_logging",PD_FALSE);

			if(iRet == PD_OK){
DEBUGLOG(("Authorize::Call OMTChannel:UpdateTxnDetailLog\n"));
				ChannelObjPtr = CreateObj(ChannelPtr,"OMTChannel","UpdateTxnDetailLog");
				if((unsigned long) ((*ChannelObjPtr)(hContext,hRequest,hResponse))!=PD_OK){
					iRet = INT_ERR;
DEBUGLOG(("Authorize::OMTChannel:AddTxnDetailLog Failed\n"));
				}
			}

		}

	}


DEBUGLOG(("TxnOmtByUsPOC Normal Exit() iRet = [%d]\n",iRet));
	FREE_ME(hTxn);
	FREE_ME(hRequest);
	FREE_ME(hContext);
	FREE_ME(hResponse);
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
