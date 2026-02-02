
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
           char  filnam[14];
};
static struct sqlcxp sqlfpn =
{
    13,
    "test_elvis.pc"
};


static unsigned int sqlctx = 656387;


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
#include "utilitys.h"
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"
#include "ObjPtr.h"
#include "dates.h"
#include "dbutility.h"
#include <sys/stat.h>

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char cDebug = 'Y';

OBJPTR(Txn);
OBJPTR(DB);
OBJPTR(Channel);

int parse_arg(int argc, char **argv);
int process_main();


int batch_init(int argc, char* argv[])
{
printf("argc = [%d]\n", argc);
	if (argc > 10) {
		printf("usage: -f input_file\n");
		return FAILURE;
	}
	else
		return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int 	iRet = SUCCESS;
	int	iTmpRet = PD_OK;
	int     iIntError = FAILURE;

	char    csTmDateTime[PD_DATETIME_LEN + 1];
        char    csTmDate[PD_DATE_LEN + 1];
        char    csTmTime[PD_TIME_LEN + 1];

	char    *csTxnSeq;

        hash_t *hContext;
        hContext = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hContext, 0);

        hash_t *hRequest;
        hRequest = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hRequest, 0);

        hash_t *hResponse;
        hResponse = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hResponse, 0);

	iRet = parse_arg(argc, argv);

	if (iRet != SUCCESS) {
		printf("usage: -f input_file\n");
		return (iRet);
	}

	PutField_Int(hContext, "db_commit", PD_FALSE);
	
	strcpy(csTmDateTime, getdatetime());
       	sprintf(csTmDate, "%.*s", PD_DATE_LEN, csTmDateTime);
     	PutField_CString(hContext, "PHDATE", csTmDate);
     	PutField_CString(hContext, "local_tm_date", csTmDate);
     	sprintf(csTmTime, "%.*s", PD_TIME_LEN, &csTmDateTime[PD_DATE_LEN]);
      	PutField_CString(hContext, "local_tm_time", csTmTime);

	PutField_CString(hRequest, "report_date", csTmDate);

	PutField_CString(hContext, "approval_date", csTmDate);
	PutField_CString(hContext, "approval_timestamp", csTmDateTime);
	
	PutField_CString(hRequest,"baid","BAID001852");
	PutField_CString(hContext,"baid_psp_id","P9000365");
	PutField_CString(hContext,"baid_status","O");
	PutField_CString(hContext,"baid_category","ITL_GEN");

	PutField_CString(hRequest,"txn_country","CN");
	PutField_CString(hRequest,"txn_ccy","CNY");
	PutField_Double(hContext,"txn_amt",650);	
	PutField_CString(hContext,"net_ccy","CNY");
	PutField_Double(hContext,"net_amt",650);
	PutField_Double(hContext,"display_amt",650);

	PutField_Double(hContext,"ex_rate",1);
	PutField_Char(hContext,"ex_party",'I');

	PutField_CString(hRequest,"dt_merch_type_1","1");
	PutField_CString(hRequest,"dt_country_1","CN");
	PutField_CString(hRequest,"dt_merch_amt_1","650");

	PutField_Int(hContext,"total_cnt",1);

	PutField_CString(hRequest, "add_user", PD_UPDATE_USER);

DEBUGLOG(("  Call OLTxnSeq:GetNextOmtTxnSeq\n"));
     	DBObjPtr = CreateObj(DBPtr,"DBOLTxnSeq","GetNextOmtTxnSeq");
      	csTxnSeq  = strdup((*DBObjPtr)());
DEBUGLOG(("  >> GenerateBatchSeq: [%s]\n",csTxnSeq));
     	PutField_CString(hContext,"txn_seq",csTxnSeq);
       	FREE_ME(csTxnSeq);
	
	PutField_CString(hRequest,"ip_addr","192.168.100.24");
	PutField_CString(hContext,"process_type",PD_PROCESS_TYPE_DEF);
      	PutField_CString(hContext,"process_code",PD_PROCESS_CODE_DEF);
      	PutField_CString(hContext,"txn_code","OPT");
       	PutField_CString(hContext,"channel_code",PD_CHANNEL_OMT);
       	PutField_Int(hContext,"do_logging",PD_TRUE);

DEBUGLOG(("  >> Call OMTChannel:AddTxnLog\n"));
      	ChannelObjPtr = CreateObj(ChannelPtr,"OMTChannel","AddTxnLog");
       	iTmpRet = (unsigned long)(*ChannelObjPtr)(hContext,hRequest);
     	if (iTmpRet != PD_OK) {
DEBUGLOG(("  >>   OMTChannel:AddTxnLog Failed\n"));
             	iRet = FAILURE;
     	}

	if(iRet==SUCCESS){
            	PutField_Int(hContext,"internal_code",PD_OK);
              	PutField_CString(hContext,"response_code","0");
             	PutField_Char(hContext,"ar_ind",PD_ACCEPT);
              	PutField_Char(hContext,"status",PD_COMPLETE);
              	PutField_CString(hContext,"sub_status","118");
              	PutField_Char(hContext,"recon_status",'U');

DEBUGLOG(("  >> Call OMTChannel:UpdateTxnLog\n"));
              	ChannelObjPtr = CreateObj(ChannelPtr,"OMTChannel","UpdateTxnLog");
            	iTmpRet = (unsigned long)(*ChannelObjPtr)(hContext,hRequest,hResponse);
             	if (iTmpRet != PD_OK) {
DEBUGLOG(("  >>   OMTChannel:AddTxnDetailLog Failed\n"));
                     	iRet = FAILURE;
             	}
            	PutField_Int(hContext,"do_logging",PD_FALSE);

            	if(iRet == SUCCESS){
DEBUGLOG(("  >> Call OMTChannel:UpdateTxnDetailLog\n"));
                    	ChannelObjPtr = CreateObj(ChannelPtr,"OMTChannel","UpdateTxnDetailLog");
                    	iTmpRet = (unsigned long)(*ChannelObjPtr)(hContext,hRequest,hResponse);
                    	if (iTmpRet != PD_OK) {
                           	iRet = FAILURE;
DEBUGLOG(("  >>   OMTChannel:AddTxnDetailLog Failed\n"));
                     	}
           	}
      	}

	if (iRet == SUCCESS) {
DEBUGLOG(("  Call TxnOmtByUsCOM:Authorize\n"));
            	TxnObjPtr = CreateObj(TxnPtr,"TxnOmtByUsCOM","Authorize");
            	iTmpRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
             	if (iTmpRet == PD_OK) {
                 	if (GetField_Int(hContext, "internal_error", &iIntError)) {
DEBUGLOG(("  >> TxnMgtByUsCOM:Authorize Return internal_error [%d]\n", iIntError));
                          	iTmpRet = iIntError;
                               	iRet = FAILURE;
                    	}
             	} else {
                   	iRet = FAILURE;
             	}
      	}

	if (iRet == SUCCESS) {
DEBUGLOG(("  Call TxnOmtByUsOPT:Authorize\n"));
     		TxnObjPtr = CreateObj(TxnPtr, "TxnOmtByUsOPT", "Authorize");
     		iTmpRet = (unsigned long)(*TxnObjPtr)(hContext, hRequest, hResponse);
		if (iTmpRet == PD_OK) {
                    	if (GetField_Int(hContext, "internal_error", &iIntError)) {
DEBUGLOG(("  >> TxnOmtByUsOPT:Authorize Return internal_error [%d]\n", iIntError));
                            	iTmpRet = iIntError;
                              	iRet = FAILURE;
                     	}
             	} else {
                     	iRet = FAILURE;
              	}
	}

	if (iRet == SUCCESS) {
             	TxnCommit();
      	} else {
              	TxnAbort();
     	}

	hash_destroy(hResponse);
	FREE_ME(hResponse);
	hash_destroy(hRequest);
        FREE_ME(hRequest);
	hash_destroy(hContext);
        FREE_ME(hContext);

DEBUGLOG(("iRet = [%d]\n", iRet));
	return iRet;
}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


int parse_arg(int argc, char **argv)
{
	return SUCCESS;
}

