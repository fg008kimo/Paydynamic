
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
           char  filnam[28];
};
static struct sqlcxp sqlfpn =
{
    27,
    "send_bal_channel_mq_test.pc"
};


static unsigned int sqlctx = 1862348171;


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
PDProTech (c)2020. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.
 
Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2020/03/03              [WMC]
Revised						   2020/04/03		   [MSN]
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
#include "utilitys.h"
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"
#include "ObjPtr.h"
#include "internal.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"
#include "dbutility.h"
#include "send_bal_channel_mq_test.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char cs_psp_channel[PD_PSP_CHANNEL_CODE_LEN+1];
char cs_txn_id[PD_TXN_SEQ_LEN + 1];

static char    cDebug='Y';

OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Msg);
OBJPTR(Txn);

int parse_arg(int argc,char **argv);

int batch_init(int argc, char* argv[])
{
        return SUCCESS;
}

int parse_arg(int argc, char **argv)
{
	char	c;
	strcpy(cs_txn_id,"");

	if (argc < 2) {
DEBUGLOG(("argc = [%d]\n",argc));
		return FAILURE;
	}

	while ((c = getopt(argc,argv,"t:")) != EOF) {
		switch (c) {
			case 't':
                                strcpy(cs_txn_id, optarg);
                                break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(cs_txn_id, ""))
		return FAILURE;

        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int     iRet = SUCCESS;
	char	*csPtr = NULL;
	char	csTag[PD_TAG_LEN + 1];

	hash_t  *hRequest;
	hRequest = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRequest,0);

	
DEBUGLOG(("batch_proc: Start!\n"));

	iRet = parse_arg(argc,argv);
	if (iRet != SUCCESS) {
		printf("*usage: -t txn_id\n");
		iRet = FAILURE;
	}

	if (iRet == SUCCESS) { 
		
		hash_t  *hIn;
		hIn = (hash_t*) malloc (sizeof(hash_t));
		hash_init(hIn,0);

		hash_t  *hOut;
		hOut = (hash_t*) malloc (sizeof(hash_t));
		hash_init(hOut,0);

DEBUGLOG(("GetTxnInfo(): txn_id = [%s]\n", cs_txn_id));
		PutField_CString(hRequest, "org_txn_seq", cs_txn_id);
		PutField_CString(hIn, "txn_seq", cs_txn_id);
		PutField_Int(hIn, "get_txn_header", PD_TRUE);
		PutField_Int(hIn, "get_txn_detail", PD_TRUE);
		PutField_Int(hIn, "get_txn_psp_detail", PD_TRUE);

		BOObjPtr = CreateObj(BOPtr, "BOTransaction", "GetTxnInfo");
                if((*BOObjPtr)(hIn, hOut) == PD_OK){
			sprintf(csTag, "txn_code");
			if (GetField_CString(hOut, csTag, &csPtr)) {
				PutField_CString(hRequest, "txn_code", csPtr);
DEBUGLOG((" %s = [%s]\n", csTag, csPtr));
			}

			sprintf(csTag, "merchant_id");
			if (GetField_CString(hOut, csTag, &csPtr)) {
				PutField_CString(hRequest, "org_merchant_id", csPtr);
DEBUGLOG((" %s = [%s]\n", csTag, csPtr));
			}

			sprintf(csTag, "service_code");
			if (GetField_CString(hOut, csTag, &csPtr)) {
				PutField_CString(hRequest, "org_service_code", csPtr);
DEBUGLOG((" %s = [%s]\n", csTag, csPtr));
			}

			sprintf(csTag, "txn_country");
			if (GetField_CString(hOut, csTag, &csPtr)) {
				PutField_CString(hRequest, "org_txn_country", csPtr);
DEBUGLOG((" %s = [%s]\n", csTag, csPtr));
			}

			sprintf(csTag, "net_ccy");
			if (GetField_CString(hOut, csTag, &csPtr)) {
				PutField_CString(hRequest, "org_txn_ccy", csPtr);
DEBUGLOG((" %s = [%s]\n", csTag, csPtr));
			}

			sprintf(csTag, "psp_id");
			if (GetField_CString(hOut, csTag, &csPtr)) {
				PutField_CString(hRequest, "org_psp_id", csPtr);
DEBUGLOG((" %s = [%s]\n", csTag, csPtr));
			}

			sprintf(csTag, "psp_txn_ccy");
			if (GetField_CString(hOut, csTag, &csPtr)) {
				PutField_CString(hRequest, "org_dst_txn_ccy", csPtr);
DEBUGLOG((" %s = [%s]\n", csTag, csPtr));
			}

		}
		else{
			iRet = FAILURE;
DEBUGLOG(("GetTxnInfo() failed!\n"));
		}

	}
	if (iRet == SUCCESS) { 
		/* test wrong info
			PutField_CString(hRequest, "org_merchant_id", "LMVNET01");
			PutField_CString(hRequest, "org_txn_ccy", "USD");
			PutField_CString(hRequest, "org_psp_id", "BF");
		*/


		PutField_Double(hRequest, "open_bal", 110889600.58);
		PutField_Double(hRequest, "current_bal", 110889636.38);
		PutField_Double(hRequest, "total_float", 35.8);
		PutField_Double(hRequest, "total_reserved_amount", 12210.27);
		PutField_Double(hRequest, "total_hold", 60);
		PutField_Double(hRequest, "fundin_payout", 110889520.58);
		PutField_Double(hRequest, "reserved_payout", 20);
		PutField_Double(hRequest, "total_float_after_payout", 0);
		PutField_Double(hRequest, "open_bal_settlement", 8410959803.63);
		PutField_Double(hRequest, "current_bal_settlement", 8410959816.79);
		PutField_Double(hRequest, "total_float_settlement", 1860);
		PutField_Double(hRequest, "total_hold_settlement", 40);
		PutField_Double(hRequest, "psp_balance", 486483.24);
		PutField_Double(hRequest, "psp_total_float", 191780.34);
		PutField_Double(hRequest, "psp_total_hold", 0);
	}

	if (iRet == SUCCESS) {
DEBUGLOG(("Call TxnBalOnUsCOM::DoLogging()\n"));
		//PutField_Int(hRequest, "do_db_log", PD_FALSE); //testing
		PutField_CString(hRequest, "approval_date", "20200409"); //testing
		TxnObjPtr = CreateObj(TxnPtr, "TxnBalOnUsCOM", "DoLogging");
		if((unsigned long)(*TxnObjPtr)(hRequest) != PD_OK){
DEBUGLOG(("DoLogging failed!\n"));
		}


DEBUGLOG(("Call TxnBalOnUsCOM::SendToQueue()\n"));
		PutField_CString(hRequest, "balcode", PD_CODE_UPDATEBAL);
		TxnObjPtr = CreateObj(TxnPtr, "TxnBalOnUsCOM", "SendToQueue");
		if((unsigned long)(*TxnObjPtr)(hRequest) != PD_OK){
			iRet = FAILURE;
DEBUGLOG(("SendToQueue failed!\n"));
		}
	}

DEBUGLOG(("batch_proc: iRet = [%d]\n", iRet));
	return iRet;
}


int batch_terminate(int argc, char* argv[])
{
        return SUCCESS;
}

int batch_proc_org(int argc, char* argv[])
{
	int     iRet = SUCCESS;
	
	int     iSendLen;
        long    lKey;
	//long	lResponseQueueMtype;
        hex_t   *h_msg;
        struct 	msg_t *msg;
	char    csTmpChannelCode[PD_CHANNEL_CODE_LEN + 1];
	char    csTxnId[PD_TXN_SEQ_LEN + 1];

	hash_t  *hRequest;
        hRequest = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hRequest,0);

        hash_t  *hContext;
        hContext = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hContext,0);

        hash_t  *hResponse;
        hResponse = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hResponse,0);

DEBUGLOG(("batch_proc: Start!\n"));

	iRet = parse_arg(argc,argv);
	if (iRet != SUCCESS) {
		printf("*usage: -c psp_channel\n");
		return FAILURE;
	}

	if (iRet == SUCCESS) { 

DEBUGLOG(("psp_channel_code = [%s]\n", cs_psp_channel));

		// FormatMsg and Send to Queue
		//sprintf(csTxnId, "0000000007128912");
		sprintf(csTxnId, "G000091363538410");
		
		PutField_CString(hRequest, "txnid", csTxnId);
DEBUGLOG(("txn_seq = [%s]\n", csTxnId));
		PutField_CString(hRequest, "balcode", "UPDBAL");
DEBUGLOG(("balcode = [%s]\n", "UPDBAL"));
		PutField_CString(hRequest, "txncode", "DSI");
DEBUGLOG(("txncode = [%s]\n", "DSI"));
                PutField_CString(hRequest, "country", "CN");
DEBUGLOG(("txncode = [%s]\n", "CN"));
                PutField_CString(hRequest, "mid", "K000000001");
DEBUGLOG(("txncode = [%s]\n", "K000000001"));
		PutField_CString(hRequest, "ccy", "CNY");
DEBUGLOG(("txncode = [%s]\n", "CNY"));
                PutField_CString(hRequest, "service_code", "VNC");
DEBUGLOG(("txncode = [%s]\n", "VNC"));
                PutField_Double(hRequest, "bal", 1000000.01);
DEBUGLOG(("txncode = [%lf]\n", 1000000.01));
                PutField_Double(hRequest, "float", 20000.02);
DEBUGLOG(("txncode = [%lf]\n", 20000.02));
                PutField_Double(hRequest, "holdback", 3000.03);
DEBUGLOG(("txncode = [%lf]\n", 3000.03));
                PutField_Double(hRequest, "hold", 4000.04);
DEBUGLOG(("txncode = [%lf]\n", 4000.04));
                PutField_Double(hRequest, "bal_sett", 500000.50);
DEBUGLOG(("txncode = [%lf]\n", 5000.50));
                PutField_Double(hRequest, "float_sett", 6000.00);
DEBUGLOG(("txncode = [%lf]\n", 6000.00));
                PutField_Double(hRequest, "hold_sett", 700.07);
DEBUGLOG(("txncode = [%lf]\n", 700.07));
                PutField_Double(hRequest, "fundin_po", 80.08);
DEBUGLOG(("txncode = [%lf]\n", 80.08));
                PutField_Double(hRequest, "resv_po", 9.09);
DEBUGLOG(("txncode = [%lf]\n", 9.09));
                PutField_Double(hRequest, "afpo_float", 0.01);
DEBUGLOG(("txncode = [%lf]\n", 0.01));
                PutField_CString(hRequest, "psp_id", "PROD_VNC");
DEBUGLOG(("txncode = [%s]\n", "PROD_VNC"));
                PutField_CString(hRequest, "psp_ccy", "CNY");
DEBUGLOG(("txncode = [%s]\n", "CNY"));
                PutField_Double(hRequest, "psp_bal", 11111111.11);
DEBUGLOG(("txncode = [%lf]\n", 11111111.11));
                PutField_Double(hRequest, "psp_float", 2222222.22);
DEBUGLOG(("txncode = [%lf]\n", 2222222.22));
                PutField_Double(hRequest, "psp_hold", 33333.33);
DEBUGLOG(("txncode = [%lf]\n", 33333.33));

		sprintf(csTmpChannelCode, "%c%c%cMsg", cs_psp_channel[0], tolower(cs_psp_channel[1]), tolower(cs_psp_channel[2]));

DEBUGLOG(("Call %s:FormatMsg\n", csTmpChannelCode));
                MsgObjPtr = CreateObj(MsgPtr, csTmpChannelCode, "FormatMsg");
                h_msg = (hex_t*) malloc (sizeof(hex_t));
                if ((*MsgObjPtr)(hRequest, h_msg->msg, &h_msg->len) == PD_OK) {

                        lKey = GetMQKey((const unsigned char *)"BALREQQ");

                        msg = (struct msg_t*)malloc(sizeof(struct msg_t) + MAX_MSG_SIZE);
                        msg->mtype  = ctol((const unsigned char *)csTxnId, strlen(csTxnId));
			memset(msg->mtext, 0, sizeof(msg->mtext));
                        MQ_build_header((unsigned char*)msg->mtext,
                                        //MQ_RESP,
                                        MQ_REQ,
                                        cs_psp_channel,
                                        0,
                                        NULL,
                                        0);
                        memcpy(&msg->mtext[MQ_HEADER_LEN], h_msg->msg, h_msg->len);
                        msg->mtext[MQ_HEADER_LEN + h_msg->len] = '\0';
                        iSendLen = MQ_HEADER_LEN + h_msg->len;
DEBUGLOG(("send msg = [%s] send len = [%d]\n", msg->mtext, iSendLen));
DEBUGLOG(("key = [%ld][%ld]\n", lKey, msg->mtype));

                        if (MQSend(lKey, msg, iSendLen) != MQ_OK ) {
DEBUGLOG(("Sent Error\n"));
                                iRet = FAILURE;
                        }			
		} else {
                        iRet = FAILURE;
DEBUGLOG(("Call %s:FormatMsg FAILED\n", csTmpChannelCode));
                }

                FREE_ME(msg);
                FREE_ME(h_msg);
	}

	hash_destroy(hRequest);
        FREE_ME(hRequest);
        hash_destroy(hContext);
        FREE_ME(hContext);
        hash_destroy(hResponse);
        FREE_ME(hResponse);
	
DEBUGLOG(("batch_proc: normal exit!\n"));

	return iRet;
}



int parse_arg_org(int argc, char **argv)
{
	char	c;
	strcpy(cs_psp_channel,"");

	if (argc < 2) {
DEBUGLOG(("argc = [%d]\n",argc));
		return FAILURE;
	}

	while ((c = getopt(argc,argv,"c:")) != EOF) {
		switch (c) {
			case 'c':
                                strcpy(cs_psp_channel, optarg);
                                break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(cs_psp_channel,""))
		return FAILURE;

        return SUCCESS;
}

