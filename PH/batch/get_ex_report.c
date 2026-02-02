
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
           char  filnam[17];
};
static struct sqlcxp sqlfpn =
{
    16,
    "get_ex_report.pc"
};


static unsigned int sqlctx = 4854203;


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
Init Version                                       2014/11/14              LokMan Chow
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

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define	TEST_AMT 10000.0

char	cs_merchant_id[PD_MERCHANT_ID_LEN+1];
char	cs_country[PD_COUNTRY_LEN+1];
char	cs_service_code[PD_SERVICE_CODE_LEN+1];
char	cs_datetime[PD_DATETIME_LEN+1];
char	cs_from_ccy[PD_CCY_ID_LEN+1];
char	cs_to_ccy[PD_CCY_ID_LEN+1];
char	cs_txn_code[PD_TXN_CODE_LEN+1];
char	cs_channel_code[PD_CHANNEL_CODE_LEN+1];


char    cDebug  = 'Y';

OBJPTR(DB);
OBJPTR(BO);

int parse_arg(int argc,char **argv);
int request_fx_rate();

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
        int     iRet;

	iRet = parse_arg(argc,argv);
	if(iRet == SUCCESS)
		iRet = request_fx_rate();

	return iRet;
}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


int request_fx_rate()
{
	int	iRet = SUCCESS;

	hash_t  *hRequest;
	hRequest = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRequest,0);

	hash_t  *hContext;
	hContext = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hContext,0);

	char	*csInterCcy;
	char	*csTmp;

	int	iTxnTypeCnt = 1;
	int	iFromCcyCnt = 1;
	int	iToCcyCnt = 1;
	int	iType = 0;
	int	iFrom = 0;
	int	iTo = 0;
	int	iSkip = PD_FALSE;

	char	cExParty;

DEBUGLOG(("Authorize\n"));

	PutField_CString(hContext,"merchant_id",cs_merchant_id);
	PutField_CString(hRequest,"merchant_id",cs_merchant_id);
	PutField_CString(hRequest,"txn_country",cs_country);
	PutField_CString(hRequest,"service_code",cs_service_code);
	PutField_CString(hContext,"datetime",cs_datetime);
	PutField_Double(hContext,"txn_amt",TEST_AMT);

	if(iRet==PD_OK){
///get merchant_client_id
DEBUGLOG(("GetMerchantDetail\n"));
		BOObjPtr = CreateObj(BOPtr,"BOMerchant","GetMerchantDetail");
		iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
	}

	if(iRet == PD_OK){
		PutField_Int(hContext,"get_info_only",PD_TRUE);

		for(iType=1; iType<=iTxnTypeCnt; iType++){
			PutField_CString(hContext,"channel_code",cs_channel_code);
			PutField_CString(hContext,"txn_code",cs_txn_code);

			for(iFrom=1; iFrom<=iFromCcyCnt; iFrom++){
				PutField_CString(hContext,"txn_ccy",cs_from_ccy);
				PutField_CString(hRequest,"txn_ccy",cs_from_ccy);

				for(iTo=1; iTo<=iToCcyCnt; iTo++){
					PutField_CString(hContext,"dst_txn_ccy",cs_to_ccy);

					if((iFromCcyCnt+iToCcyCnt)>2){
						if(!strcmp(cs_from_ccy,cs_to_ccy)){
							iSkip = PD_TRUE;
						}
					}

					if(iSkip == PD_FALSE){
						double	dExRate = 0.0;
						double	dExRateMU = 0.0;
						double	dMarkupRate = 0.0;
						double	dOrgExRate = 0.0;
						double	dInterRate = 0.0;
						double	dOrgIntExRate = 0.0;
						RemoveField_Double(hContext,"ex_int_rate");
						RemoveField_Double(hContext,"inter_rate");
						RemoveField_CString(hContext,"inter_ccy");

						BOObjPtr = CreateObj(BOPtr,"BOExchange","GetExchangeInfoByDate");
						if ((*BOObjPtr)(hContext,hRequest) == PD_OK) {
DEBUGLOG(("GetExchangeInfoByDate Success\n"));
							if(GetField_CString(hContext,"markup_ccy",&csTmp)){
DEBUGLOG(("GetExchangeInfoByDate::Markup Ccy=[%s]\n",csTmp));
							}
							if(GetField_Double(hContext,"markup_rate",&dMarkupRate)){
DEBUGLOG(("GetExchangeInfoByDate::Markup rate=[%lf]\n",dMarkupRate));
							}
							if(GetField_Double(hContext,"org_ex_rate",&dOrgExRate)){
DEBUGLOG(("GetExchangeInfoByDate::Exchange rate (OANDA)=[%lf]\n",dOrgExRate));
							}
							if(GetField_Double(hContext,"ex_int_rate",&dOrgIntExRate)){
DEBUGLOG(("GetExchangeInfoByDate::Exchange rate (OANDA+ACR)=[%lf]\n",dOrgIntExRate));
							}
							if(GetField_Double(hContext,"inter_rate",&dInterRate)){
DEBUGLOG(("GetExchangeInfoByDate::Inter rate=[%lf]\n",dInterRate));
							}
							if(GetField_CString(hContext,"inter_ccy",&csInterCcy)){
DEBUGLOG(("GetExchangeInfoByDate::Inter Ccy=[%s]\n",csInterCcy));
							}
							else{
								GetField_CString(hContext,"dst_txn_ccy",&csInterCcy);
DEBUGLOG(("GetExchangeInfoByDate::Inter Ccy (same with dest ccy)=[%s]\n",csInterCcy));
							}
							if(GetField_Double(hContext,"ex_rate",&dExRate)){
DEBUGLOG(("GetExchangeInfoByDate::Final Exchange rate=[%lf]\n",dExRate));
							}

							if(GetField_Double(hContext,"ex_rate_w_mu",&dExRateMU)){
DEBUGLOG(("GetExchangeInfoByDate::Final Exchange Rate (With Markup)=[%lf]\n",dExRateMU));
							}
							
							if(GetField_Char(hContext,"ex_party",&cExParty)){
DEBUGLOG(("GetExchangeInfoByDate::Final Exchange Rate Party=[%c]\n",cExParty));
							}

							printf("%.*s-%.*s-%.*s,%lf,%lf,%f\n",4,cs_datetime,2,&cs_datetime[4],2,&cs_datetime[6],dOrgExRate,dExRate,dExRateMU);

						}
					}
				}
			}
		}

	}

	FREE_ME(hContext);
	FREE_ME(hRequest);
DEBUGLOG(("TxnMgtByUsFXR Normal Exit() iRet = [%d]\n",iRet));

	return iRet;
}


int parse_arg(int argc,char **argv)
{
        char    c;
	strcpy(cs_merchant_id,"");
	strcpy(cs_country,"");
	strcpy(cs_txn_code,"");
	strcpy(cs_service_code,"");
	strcpy(cs_datetime,"");
	strcpy(cs_from_ccy,"");
	strcpy(cs_to_ccy,"");
	strcpy(cs_channel_code,"");

        while ((c = getopt(argc,argv,"m:c:x:s:d:f:t:h:")) != EOF) {
                switch (c) {
			case 'm':
				strcpy(cs_merchant_id,optarg);
				break;
			case 'c':
				strcpy(cs_country,optarg);
				break;
			case 'x':
				strcpy(cs_txn_code,optarg);
				break;
			case 's':
				strcpy(cs_service_code,optarg);
				break;
			case 'd':
				strcpy(cs_datetime,optarg);
				break;
			case 'f':
				strcpy(cs_from_ccy,optarg);
				break;
			case 't':
				strcpy(cs_to_ccy,optarg);
				break;
			case 'h':
				strcpy(cs_channel_code,optarg);
				break;
                        default:
                                return FAILURE;
                }
        }

	if(!(strlen(cs_merchant_id) 
		&& strlen(cs_country) 
		&& strlen(cs_txn_code) 
		&& strlen(cs_service_code) 
		&& strlen(cs_channel_code) 
		&& strlen(cs_datetime) 
		&& strlen(cs_from_ccy) 
		&& strlen(cs_to_ccy)))
		return FAILURE;

        return SUCCESS;
}
