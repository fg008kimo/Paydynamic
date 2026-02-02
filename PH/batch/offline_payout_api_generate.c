
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
    "offline_payout_api_generate.pc"
};


static unsigned int sqlctx = 844790749;


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
Init Version                                       2017/03/29              Elvis Wong
Get pregen info by action_id                	   2017/07/06              Elvis Wong
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
#include "dbutility.h"


#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

int	iOnlinePayout;
char    cs_action_id[PD_TXN_SEQ_LEN + 1];
char    cs_user[PD_USER_LEN + 1];

char cDebug = 'Y';
OBJPTR(BO);
OBJPTR(DB);

int parse_arg(int argc,char **argv);

int batch_init(int argc, char* argv[])
{

    if (argc < 3) {
        printf("usage: -a action_id -o is_online -u user \n");
        return FAILURE;
    }
    else
        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
        int     iRet = PD_OK;

	int	iErrRetCode = 0;

	char    csLocalTxnDateTime[PD_DATETIME_LEN+1];
        char    csTmDate[PD_DATE_LEN+1];
        char    csTmTime[PD_TIME_LEN+1];
	char 	csTmpDate[PD_DATETIME_LEN +1];
	
	hash_t  *hRequest;
        hRequest = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hRequest,0);

	hash_t  *hContext;
        hContext = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hContext,0);

	hash_t  *hResponse;
        hResponse = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hResponse,0);

	hash_t *hTxn;
        hTxn = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTxn, 0);

	iRet = parse_arg(argc,argv);

        if (iRet != SUCCESS) {
		printf("1. usage: -a action_id -o is_online -u user \n");
		FREE_ME(hRequest);
		FREE_ME(hContext);
		FREE_ME(hResponse);
                return (iRet);
        }

DEBUGLOG(("batch_proc\n"));

	//lock the payout control, no other batch/generate can be done
DEBUGLOG(("batch_proc::Call DBPayoutActionLock::CheckTheActionCtl\n"));
	DBObjPtr = CreateObj(DBPtr,"DBPayoutActionLock","CheckTheActionCtl");
	iRet = (unsigned long)(*DBObjPtr)(PD_OFFLINE);
	if(iRet==PD_OK){
DEBUGLOG(("batch_proc::Call DBPayoutActionLock::TakeTheActionCtl\n"));
		DBObjPtr = CreateObj(DBPtr,"DBPayoutActionLock","TakeTheActionCtl");
		iRet = (unsigned long)(*DBObjPtr)(PD_OFFLINE);
		if(iRet!=PD_OK){
			TxnCommit();
DEBUGLOG(("batch_proc::Call TxnCommit()\n"));
		}
	}
	if(iRet!=PD_OK){
DEBUGLOG(("batch_proc::Call DBPayoutActionLock::ActionCtl Failed!!\n"));
ERRLOG("offline_payout_api_generate::batch_proc::Call DBPayoutActionLock::ActionCtl Failed!!\n");
           	iRet = INT_OTHER_PAYOUT_PROCESSING;
		PutField_Int(hContext,"internal_error",iRet);
              	FREE_ME(hRequest);
              	FREE_ME(hContext);
              	FREE_ME(hResponse);
              	return iRet;
       	}

	//action_id
DEBUGLOG(("batch_proc::action_id = [%s]\n",cs_action_id));
	PutField_CString(hContext,"action_id",cs_action_id);
	PutField_CString(hTxn,"action_id",cs_action_id);

	//online_payout
DEBUGLOG(("batch_proc::is_online_payout = [%d]\n",iOnlinePayout));
	PutField_Int(hContext,"online_payout",iOnlinePayout);

	//user
DEBUGLOG(("batch_proc::add_user = [%s]\n",cs_user));
	PutField_CString(hContext,"add_user",cs_user);
	PutField_CString(hContext,"update_user",cs_user);

	//check system control
	if(iRet==PD_OK){
DEBUGLOG(("batch_proc::Call DBSystemControl::FindCode\n"));
        	DBObjPtr = CreateObj(DBPtr,"DBSystemControl","FindCode");
        	if ((unsigned long)(*DBObjPtr)("CTPHDATE",csTmpDate) == FOUND) {
DEBUGLOG(("batch_proc:Current Processor Hub Date= [%s]\n",csTmpDate));
                	PutField_CString(hContext,"PHDATE",csTmpDate);
			PutField_CString(hRequest,"report_date",csTmpDate);
        	} else {
                	iRet = INT_ERR;
DEBUGLOG(("batch_proc:NOT RECORD\n"));
ERRLOG("offline_payout_api_generate::batch_proc::Internal Error:WEB Channel:SystemControl Record Not Found\n");
        	}
	}

	//txn_code
	PutField_CString(hContext,"txn_code",PD_OL_PAYOUT_GENERATE);

	//channel_code
	PutField_CString(hContext,"channel_code","OMT");

	//datetime
	strcpy(csLocalTxnDateTime,getdatetime());
	sprintf(csTmDate,"%.*s",PD_DATE_LEN,csLocalTxnDateTime);
	PutField_CString(hContext,"local_tm_date",csTmDate);

	sprintf(csTmTime,"%.*s",PD_TIME_LEN,&csLocalTxnDateTime[PD_DATE_LEN]);
	PutField_CString(hContext,"local_tm_time",csTmTime);

	//call get payout api pregen records 
	if(iRet==PD_OK){
DEBUGLOG(("batch_proc:Call BOOLPayout:GetPayoutApiPregenRecords()\n"));
                BOObjPtr = CreateObj(BOPtr,"BOOLPayout","GetPayoutApiGenRecords");
                iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest,hResponse);
		if (iRet != PD_OK) {
DEBUGLOG(("batch_proc:Call BOOLPayout:GetPayoutApiPregenRecords Failed!!, iRet = [%d]\n",iRet));
ERRLOG("offline_payout_api_generate::batch_proc::Call BOOLPayout::GetPayoutApiPregenRecords Failed!!, iRet = [%d]\n",iRet);		
			PutField_Int(hContext,"internal_error",iRet);
		}
        }

	//call handle generate payout api
	if(iRet==PD_OK){
DEBUGLOG(("batch_proc:Call BOOLPayout:HandleGeneratePayoutApi()\n"));
		BOObjPtr = CreateObj(BOPtr,"BOOLPayout","HandleGeneratePayoutApi");
		iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest,hResponse);
		if (iRet != PD_OK) {
DEBUGLOG(("batch_proc:Call BOOLPayout:HandleGeneratePayoutApi Failed!! iRet = [%d]\n",iRet));
ERRLOG("offline_payout_api_generate::batch_proc::Call BOOLPayout::HandleGeneratePayoutApi Failed!! iRet = [%d]\n",iRet);		
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

	//handle error return code
        if ((iRet != INT_OTHER_PAYOUT_PROCESSING) && (GetField_Int(hContext,"internal_error",&iErrRetCode))) {
DEBUGLOG(("batch_proc::err_ret_code  = [%d]\n", iErrRetCode));
	
		TxnAbort();
DEBUGLOG(("batch_proc::Call TxnAbort()\n"));

		//check_status
		PutField_Int(hTxn, "check_status", PD_FALSE);

DEBUGLOG(("batch_proc::Call DBOLPayoutApiPregenHD:: MatchPregenStatus_ForUpdate\n"));
                DBObjPtr = CreateObj(DBPtr, "DBOLPayoutApiPregenHD", "MatchPregenStatus_ForUpdate");
                if (((unsigned long)(*DBObjPtr)(hTxn)) == PD_FOUND) {

			RemoveField_Int(hTxn, "check_status");
                        PutField_Int(hTxn,"gen_ret_code",iErrRetCode);
                        PutField_CString(hTxn,"update_user",cs_user);

DEBUGLOG(("batch_proc::Call DBOLPayoutApiPregenHD:: Update\n"));
                        DBObjPtr = CreateObj(DBPtr, "DBOLPayoutApiPregenHD", "Update");
                        iRet = (unsigned long)(*DBObjPtr)(hTxn);
                        if (iRet != PD_OK) {
DEBUGLOG(("batch_proc::Call DBOLPayoutApiPregenHD:: Update Failure!!!\n"));
ERRLOG("offline_payout_api_generate::batch_proc::Call DBOLPayoutApiPregenHD:: Update Failure!!!\n");
                                iRet = INT_ERR;
                        }
                } else {
DEBUGLOG(("batch_proc::Call DBOLPayoutApiPregenHD:: MatchPregenStatus_ForUpdate not found!!!\n"));
ERRLOG("offline_payout_api_generate::batch_proc::Call DBOLPayoutApiPregenHD:: MatchPregenStatus_ForUpdate not found!!!\n");
                        iRet = INT_TXN_STATUS_NOT_MATCH;
                }

                if (iRet == PD_OK) {
                        TxnCommit();
DEBUGLOG(("Authorize::Call TxnCommit()\n"));

                        iRet = iErrRetCode;
                }

		// remove internal_error
                RemoveField_Int(hContext, "internal_error");
	}
	
	//release the payout control 
        if (iRet != INT_OTHER_PAYOUT_PROCESSING) {
DEBUGLOG(("batch_proc:Call DBPayoutActionLock::ReleaseTheActionCtl\n"));
		DBObjPtr = CreateObj(DBPtr,"DBPayoutActionLock","ReleaseTheActionCtl");
		iRet = (unsigned long)(*DBObjPtr)(PD_OFFLINE);
		if (iRet != PD_OK) {
DEBUGLOG(("batch_proc:Call DBPayoutActionLock::ReleaseTheActionCtl Failure!!! iRet = [%d]\n",iRet));
ERRLOG("offline_payout_api_generate::batch_proc::Call DBPayoutActionLock:: ReleaseTheActionCtl Failure!!! iRet = [%d]\n",iRet);
			iRet = INT_ERR;
		}
	}

	FREE_ME(hRequest);
	FREE_ME(hContext);
        FREE_ME(hResponse);

	hash_destroy(hTxn);
        FREE_ME(hTxn);

DEBUGLOG(("offline_payout_api_generate Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}

int batch_terminate(int argc, char* argv[])
{
        return SUCCESS;
}


int parse_arg(int argc,char **argv)
{
        char    c;
        strcpy(cs_action_id,"");
        strcpy(cs_user,"");
	iOnlinePayout = PD_FALSE;

        while ((c = getopt(argc,argv,"u:a:o:")) != EOF) {
                switch (c) {
                        case 'a':
                                strcpy(cs_action_id, optarg);
                                break;
                        case 'o':
                                iOnlinePayout=atoi(optarg);
				break;
			case 'u':
                                strcpy(cs_user, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_action_id,"") || !strcmp(cs_user,""))
                return FAILURE;

        return SUCCESS;
}
