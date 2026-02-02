
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
           char  filnam[37];
};
static struct sqlcxp sqlfpn =
{
    36,
    "extract_client_txn_hist_daily_rpt.pc"
};


static unsigned int sqlctx = 560728507;


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
   unsigned char  *sqhstv[44];
   unsigned long  sqhstl[44];
            int   sqhsts[44];
            short *sqindv[44];
            int   sqinds[44];
   unsigned long  sqharm[44];
   unsigned long  *sqharc[44];
   unsigned short  sqadto[44];
   unsigned short  sqtdso[44];
} sqlstm = {12,44};

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
"INTERNAL_BANK_CODE = MBM_BANK_CODE A\
ND FE_DESC IS NOT NULL AND EC_CHANNEL IS NOT NULL ) bb ON bb . BANK_NAME = CO\
NSUMER_DEPOSIT_BANK AND TP_PSP_ID = PSP_ID WHERE 1 = 1 AND STATUS = 'Approved\
' AND bb . GRP IN ( SELECT DISTINCT GRP FROM MOB_BANK_MAP_VIEW ) GROUP BY SC_\
DESC , bb . MBM_FE_DESC , STATUS , TRANSACTION_CCY , CONSUMER_PAID_CCY , SC_C\
ODE ORDER BY SC_DESC , bb . MBM_FE_DESC , STATUS , TRANSACTION_CCY , CONSUMER\
_PAID_CCY , SC_CODE            ";

 static char *sq0003 = 
"AMP FROM ( SELECT DTR_TXN_ID , DTR_C\
REATE_USER AS MERCHANT_CREATE_USER , DTR_CREATE_TIMESTAMP AS MERCHANT_CREATE_\
TIMESTAMP , ROW_NUMBER ( ) OVER ( PARTITION BY DTR_TXN_ID ORDER BY DTR_CREATE\
_TIMESTAMP DESC ) AS ROWNO FROM DEPOSIT_TRACE WHERE DTR_PARTY_TYPE = 'M' ) WH\
ERE ROWNO = 1 ) MDT ON MDT . DTR_TXN_ID = TXN_ID LEFT JOIN ( SELECT DTR_TXN_I\
D , ADMIN_CREATE_USER , ADMIN_CREATE_TIMESTAMP FROM ( SELECT DTR_TXN_ID , CAS\
E WHEN DTR_UPDATE_USER IS NOT NULL THEN 'System Administrator' ELSE '' END AD\
MIN_CREATE_USER , DTR_CREATE_TIMESTAMP AS ADMIN_CREATE_TIMESTAMP , ROW_NUMBER\
 ( ) OVER ( PARTITION BY DTR_TXN_ID ORDER BY DTR_CREATE_TIMESTAMP DESC ) AS R\
OWNO FROM DEPOSIT_TRACE WHERE DTR_PARTY_TYPE = 'A' ) WHERE ROWNO = 1 ) ADT2 O\
N ADT2 . DTR_TXN_ID = TXN_ID WHERE 1 = 1 ORDER BY CREATE_TIMESTAMP DESC , TXN\
_ID DESC            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,1476,0,9,564,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
32,0,0,1,0,0,13,568,0,0,7,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,
0,0,2,4,0,0,
75,0,0,1,0,0,15,668,0,0,0,0,0,1,0,
90,0,0,1,0,0,15,677,0,0,0,0,0,1,0,
105,0,0,2,0,0,32,678,0,0,0,0,0,1,0,
120,0,0,3,4922,0,9,1087,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
147,0,0,3,0,0,13,1091,0,0,44,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,
0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,
0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
338,0,0,3,0,0,15,1606,0,0,0,0,0,1,0,
353,0,0,3,0,0,15,1614,0,0,0,0,0,1,0,
368,0,0,4,0,0,32,1615,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                            Change Date     Change By
------------------------------------------    ------------    --------------
Init Version                                  2019/11/20      [MIC]
Add checking record in PregenDailyReport      2020/03/18      [MIC]
PRD290 Add "Consumer Paid Amount" and	      2020/11/24      [ANC]
"Consumer Paid Currency" field 
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
#include "ObjPtr.h"
#include "dbutility.h"


#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define PD_REC_ENABLED     	0
#define PD_FILE_PREFIX	   	"client_txn_hist"
#define PD_UNUSED			"0"

OBJPTR(DB);

char csDate[PD_DATE_LEN + 1];
char csInMerchantId[PD_MERCHANT_ID_LEN+1];
char csInCcyId[PD_COUNTRY_CODE_LEN+1];
char csInCountryCode[PD_CCY_ID_LEN+1];
char csInServiceCode[PD_SERVICE_CODE_LEN+1];
char csInClientId[PD_CLIENT_ID_LEN+1];

char csTmpYYYY[PD_YYYY_LEN+1];
char csTmpYYYYMM[PD_YYYYMM_LEN+1];

static char cDebug = 'Y';

int parse_arg(int argc,char **argv);


int process_data(const char* csTxnDate);


int process_single_acct(const char* csTxnDate,
						const char* csClientId);

int process_clttxnhist(const char* csClientId,
                     const char* csReportDate,
                     FILE *fp);


					
int process_depositSumm(const char* csClientId,
					const char* csReportDate,
					FILE *fp);
					 
					 
int mkFullPathDir(const char* csYearMthDy);

char* getYYYY(const char* csTxnDate);

char* getYYYYMM(const char* csTxnDate);

int chkSpInClientID(const char* csClientId);

void format_commas(double dInNum, char* csOutNum);

int batch_init(int argc, char* argv[])
{
	if (argc < 3) {
		printf("usage: -d Date\n");

		return FAILURE;
	}
	
	else if (argc > 3 && argc < 5) {
		printf("usage: -d Date"
			" -c Client_ID\n");

		return FAILURE;
	}
	else
  		return SUCCESS;

}

int batch_proc(int argc, char* argv[])
{
	int iRet;

	iRet = parse_arg(argc,argv);
         
	if (iRet != SUCCESS) {
		if (argc < 3)
			printf("usage: -d Date\n");
		else if (argc > 3 && argc < 5) {
			printf("usage: -d Date"
			       " -c Client_ID\n");
		}
		return (iRet);
	}

	if (argc == 3){		
		iRet = process_data(csDate);
	}
	else{
		iRet = process_single_acct(csDate,csInClientId);
	}

	return iRet;
}

int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}



int process_data(const char* csTxnDate)
{               
	int     iRet = SUCCESS;
	char    csUploadFilename[PD_UPLOAD_FILENAME_LEN+1];
	char    csUploadFullFile[PD_PATH_LEN+1];
	char    csTmpCmd[PD_TMP_BUF_LEN+1];
	char    csYear[PD_YYYY_LEN+1];
	char    csYearMth[PD_YYYYMM_LEN+1];
	char	*csClientId;
	
	FILE    *fp;
	hash_t* hClientTxnHist;
	hClientTxnHist = (hash_t*) malloc (sizeof(hash_t));


/* Extract report data */
		hash_init(hClientTxnHist,0);
		PutField_CString(hClientTxnHist,"report_code",PD_CLIENT_TXN_HIST_REPORT_CODE);


		PutField_CString(hClientTxnHist,"code", PD_CTH_PREGEN_RPT_PARAM_CD);
		
		DBObjPtr = CreateObj(DBPtr,"DBPregenRptParam","GetVal");
		if ((*DBObjPtr)(hClientTxnHist) == PD_OK){
DEBUGLOG(("process_data:DBPregenRptParam GetVal Found\n"));
/* ClientId */
			if (GetField_CString(hClientTxnHist, "val", &csClientId)) {
DEBUGLOG(("process_data:ClientId = [%s]\n",csClientId));
			}
			else{
DEBUGLOG(("ClientId not found!!\n"));
ERRLOG("extract_client_txn_hist_daily_rpt:: process_data:: ClientId not found!!\n");
				return FAILURE;
			}
		}
		else{
DEBUGLOG(("process_data:DBPregenRptParam GetVal Not Found\n"));
ERRLOG("extract_client_txn_hist_daily_rpt:: process_data:: call PregenRptParam::Get Error!!\n");
			return FAILURE;
		}

	


/* Table Field  disabled*/
		PutField_Int(hClientTxnHist,"disabled",PD_REC_ENABLED);

/* Addition field Report Data */
		if (strlen(csTxnDate) > 0)
		{
			PutField_CString(hClientTxnHist,"report_date",csTxnDate);
		}

		
/* Only Generate report one time*/
/* Do not generate report again if generated report record exist in table */
		DBObjPtr = CreateObj(DBPtr,"DBPregenDailyReport","ChkCthExist");
		if ((*DBObjPtr)(hClientTxnHist) != PD_OK)
		{
DEBUGLOG(("process_data:ClientId[%s] TxnDate[%s] Report has generated already\n", csClientId, csTxnDate));
			return FAILURE;		
		}


		/* Skip the record if ClientID contains space */ 
		if (chkSpInClientID(csClientId) == PD_ERR){
DEBUGLOG(("process_data:unable to get ClientID contain space [%s]\n",csClientId));
			return FAILURE;
		}

		sprintf(csUploadFilename, 
				"%s_%s_%s.zip",
				PD_FILE_PREFIX,
				csClientId,
				csTxnDate);
		

		
		

/* Addition field Filename */
		PutField_CString(hClientTxnHist,"filename",csUploadFilename);
DEBUGLOG(("process_data:filename[%s]\n",csUploadFilename));

/* Addition field Update_user */
		PutField_CString(hClientTxnHist,"user",PD_UPDATE_USER);

/* Extract year and year month */
		strcpy(csYear, getYYYY(csTxnDate));

		strcpy(csYearMth, getYYYYMM(csTxnDate));


/* Check and make current balance report folder */
		if (mkFullPathDir(csTxnDate) != PD_OK)
		{
DEBUGLOG(("process_data:unable to create path [%s %s %s]\n",csYear, csYearMth, csTxnDate));
			return FAILURE;
		}

		sprintf(csUploadFullFile,"%s/%s/%s/%s/%s/%s_%s_%s.xls",  
				getenv("PREGEN_RPT_HOME"), PD_FILE_PREFIX, csYear, csYearMth, csTxnDate, PD_FILE_PREFIX, csClientId,
				csTxnDate);
		        
		fp = fopen(csUploadFullFile,"w");
		if (fp == NULL) {
DEBUGLOG(("process_data:unable to open [%s]\n",csUploadFullFile));
			return FAILURE;
		}
/* create xml header */
		fprintf(fp,"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
		fprintf(fp,"<?mso-application progid=\"Excel.Sheet\"?>\n");
		fprintf(fp,"<Workbook xmlns=\"urn:schemas-microsoft-com:office:spreadsheet\"\n");
		fprintf(fp,"\txmlns:o=\"urn:schemas-microsoft-com:office:office\"\n");
		fprintf(fp,"\t xmlns:x=\"urn:schemas-microsoft-com:office:excel\"\n");
		fprintf(fp,"\t xmlns:ss=\"urn:schemas-microsoft-com:office:spreadsheet\"\n");
		fprintf(fp,"\t xmlns:html=\"http://www.w3.org/TR/REC-html40\">\n");
		fprintf(fp,"<Styles>\n");
		fprintf(fp,"\t<Style ss:ID=\"shd\">\n");
		fprintf(fp,"\t\t<ss:Font ss:Bold=\"1\"/>\n");
		fprintf(fp,"\t\t<Alignment ss:Horizontal=\"Center\" ss:Vertical=\"Center\"/>\n");
		fprintf(fp,"\t</Style>\n");
		fprintf(fp,"\t<Style ss:ID=\"sdt\">\n");
		fprintf(fp,"\t\t<NumberFormat ss:Format=\"yyyy-mm-dd hh:mm:ss\"/>\n");
		fprintf(fp,"\t</Style>\n");
		fprintf(fp,"</Styles>\n");
		fprintf(fp,"<Worksheet ss:Name=\"Client Transaction History\">\n");
		fprintf(fp,"<Table>\n");


		fprintf(fp,"<Row>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Transaction ID</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Country</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Service</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Short Name</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Transaction Type</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Reference</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Holdback Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Holdback Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Status</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Callback Status</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Create Timestamp</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Approval Timestamp</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Remark</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Request Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Request Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Bank Name</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">EC Channel</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Consumer Payable Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Consumer Payable Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Unique Amount Markup</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Consumer Paid Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Consumer Paid Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Received Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Received Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Transaction Fee</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Transaction Fee Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Received Net Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Received Net Amount Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Payable Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Payable Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Consumer Received Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Consumer Received Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Paid Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Paid Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Paid Total Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Paid Total Amount Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Receivable Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Receivable Amount Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Receivable Net Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Receivable Net Amount Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Wire Net Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Wire Net Amount Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Beneficiary Bank Name</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Beneficiary Bank Account Number</Data></Cell>\n");
		fprintf(fp,"</Row>\n");




/* process Client Txn History data */
		if(iRet==PD_OK){
			if (process_clttxnhist(csClientId,
						csTxnDate,
						fp
				) == PD_OK){
			}
			else{
				iRet=PD_ERR;
DEBUGLOG(("process_clttxnhist failed!!!!!!\n"));
			}
		}
		
/* create deposit summary header */

		fprintf(fp,"<Row>\n");
		fprintf(fp,"</Row>\n");
		fprintf(fp,"<Row>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Deposit Summary</Data></Cell>\n");
		fprintf(fp,"</Row>\n");


		fprintf(fp,"<Row>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Service</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Status</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Transaction Amount Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Transaction Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Consumer Paid Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Consumer Paid Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Transaction Count </Data></Cell>\n");
		
		fprintf(fp,"</Row>\n");
		

/* process deposit summary data */
		if(iRet==PD_OK){
			if (process_depositSumm(csClientId,
						csTxnDate,
						fp
				) == PD_OK){
			}
			else{
				iRet=PD_ERR;
DEBUGLOG(("process_depositSumm failed!!!!!!\n"));
			}
		}
		
		if(iRet==PD_OK){
/* Addition field Status */
			PutField_Char(hClientTxnHist,"status",PD_PREGEN_RPT_COMPLETED); 
		}
		else{
/* Addition field Status */
			PutField_Char(hClientTxnHist,"status",PD_PREGEN_RPT_FAILURE);
		}
		
		
		
		

/* create xml footer */
		fprintf(fp, "</Table>\n");
		fprintf(fp, "</Worksheet>\n");
		fprintf(fp, "</Workbook>\n");

		fclose(fp);

/* zip the report */

		sprintf(csTmpCmd, 
				"zip_pregenrpt.sh %s %s %s %s %s %s %s 1>/dev/null",
				csTxnDate,
				csClientId,
				PD_UNUSED,
				PD_UNUSED,
				PD_UNUSED,
				getenv("PREGEN_RPT_HOME"),
				PD_FILE_PREFIX);
		
		if (system(csTmpCmd) == PD_ERR)
		{
DEBUGLOG(("extract_client_txn_hist_daily_rpt::zip: fail %s\n", csTmpCmd));
		}
		else
		{
DEBUGLOG(("extract_client_txn_hist_daily_rpt::zip: success %s\n", csTmpCmd));
		}


/* ChkExist Insert/update pregen_daily_report */
		DBObjPtr = CreateObj(DBPtr,"DBPregenDailyReport","ChkCthExist");
		if ((*DBObjPtr)(hClientTxnHist) != PD_OK) 
		{
			DBObjPtr = CreateObj(DBPtr,"DBPregenDailyReport","UpdateStatus");
			if ((*DBObjPtr)(hClientTxnHist) != PD_OK) 
				iRet = PD_ERR;
		}
		else
		{
			DBObjPtr = CreateObj(DBPtr,"DBPregenDailyReport","Add");
			if ((*DBObjPtr)(hClientTxnHist) != PD_OK) 
				iRet = PD_ERR;
		}

		if (iRet == PD_OK)
		{
DEBUGLOG(("extract_client_txn_hist_daily_rpt::commit: ClientId[%s] TxnDate[%s]\n", csClientId,csTxnDate));
			TxnCommit();
		}



		hash_destroy(hClientTxnHist);
		
	if (hClientTxnHist)
	{
		FREE_ME(hClientTxnHist);
	}

	return iRet;
}


int process_depositSumm(const char* csClientId,
                     const char* csReportDate,
                     FILE *fp)
{
	int   	iRet = SUCCESS;

	char csTmp[PD_TMP_BUF_LEN+1];
	char	csServiceDesc[PD_SERVICE_DESC_LEN+1];
	char	csStatus[PD_STATUS_DESC_LEN+1];      
	char	csTxnCurrency[PD_CCY_ID_LEN];
	double	dTxnAmount;
	double	dPaidAmount;
	char	csPaidCurrency[PD_CCY_ID_LEN];
	double	dTxnCnt;

	/* EXEC SQL WHENEVER SQLERROR GOTO depositSumm_sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

  
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	
		/* varchar hv_client_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_client_id;

		/* varchar	hv_report_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_report_date;

  
		/* varchar	v_service_desc[PD_SERVICE_DESC_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_service_desc;

		/* varchar	v_status[PD_STATUS_DESC_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_status;

		/* varchar	v_txn_currency[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_txn_currency;

		/* varchar	v_paid_currency[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_paid_currency;

		double	v_txn_amount;
		double	v_paid_amount;
		double	v_txn_cnt;	

		short ind_service_desc = -1;
		short ind_status       = -1;  
		short ind_txn_currency = -1;  
		short ind_txn_amount   = -1;  
		short ind_paid_amount  = -1;
		short ind_paid_currency= -1;
		short ind_txn_cnt      = -1;

		
		

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("process_depositSumm:Begin\n"));



	if(strlen(csClientId) > 0)
	{
		hv_client_id.len = strlen(csClientId);
		strncpy((char *)hv_client_id.arr, csClientId, hv_client_id.len);
DEBUGLOG(("process_depositSumm:client_id = [%.*s]\n",hv_client_id.len,hv_client_id.arr));
	} else {
DEBUGLOG(("process_depositSumm:client_id is missing\n"));
ERRLOG("extract_client_txn_hist_daily_rpt::process_depositSumm: client_id is missing\n");
		return PD_ERR;
	}



	if(strlen(csReportDate) > 0)
	{
		hv_report_date.len = strlen(csReportDate);
		strncpy((char *)hv_report_date.arr, csReportDate, hv_report_date.len);
DEBUGLOG(("process_depositSumm:report_date = [%.*s]\n",hv_report_date.len,hv_report_date.arr));
	} else {
DEBUGLOG(("process_depositSumm:report_date is missing\n"));
ERRLOG("extract_client_txn_hist_daily_rpt::process_depositSumm: report_date is missing\n");
		return PD_ERR;
	}

	
	/* EXEC SQL DECLARE c_cursor_getdepositSumm CURSOR FOR

		SELECT  SC_DESC AS SC_DESC,
			STATUS AS STATUS,
			TRANSACTION_CCY AS TRANSACTION_CCY,
			SUM(TRANSACTION_AMOUNT) AS COUNT_AMT,
			CONSUMER_PAID_CCY AS CONSUMER_PAID_CCY,
			SUM(CONSUMER_PAID_AMT) AS COUNT_PAID_AMT,
			count(TXN_ID) AS COUNT_TXN
		FROM (  select STATUS,
				TRANSACTION_CCY,
				TRANSACTION_AMOUNT,
				CONSUMER_PAID_CCY,
				CONSUMER_PAID_AMT,
				TXN_ID,
				ACK_STATUS,
				SERVICE_CODE,
				TXN_COUNTRY,
				CONSUMER_DEPOSIT_BANK,
				TP_PSP_ID
				from merch_rpt_all
				where client_id = :hv_client_id
				and create_timestamp >= to_date(:hv_report_date, 'yyyymmdd')
				and create_timestamp < to_date(:hv_report_date, 'yyyymmdd')+1
			) TXN_DETAIL
		LEFT JOIN   DEF_SUB_STATUS ACK_STATUS
		ON            ACK_STATUS = ACK_STATUS.DS_SUB_STATUS
		LEFT JOIN    DEF_SERVICE_CODE
		ON            SC_CODE = SERVICE_CODE
		LEFT JOIN    COUNTRY
		ON            COUNTRY_CODE = TXN_COUNTRY
		LEFT JOIN  (
					SELECT
						BANK_NAME ,
						MBM_FE_DESC ,
						PSP_ID ,
						EC_CHANNEL ,
						MOB_BANK_MAP_VIEW.GRP AS GRP
					FROM
						BANK_DESC ,
						MOB_BANK_MAP
						LEFT JOIN
						MOB_BANK_MAP_VIEW
						on MBM_BANK_CODE = MOB_BANK_MAP_VIEW.BANK_CODE
						AND MBM_GROUP = MOB_BANK_MAP_VIEW.GRP
						WHERE
						INTERNAL_BANK_CODE = MBM_BANK_CODE
						AND  FE_DESC IS NOT NULL
						AND  EC_CHANNEL IS NOT NULL
					) bb
		ON            bb.BANK_NAME = CONSUMER_DEPOSIT_BANK
					AND TP_PSP_ID = PSP_ID 
		WHERE 1=1 AND STATUS='Approved' AND bb.GRP IN (SELECT DISTINCT GRP FROM MOB_BANK_MAP_VIEW)  GROUP BY SC_DESC , bb.MBM_FE_DESC , STATUS , TRANSACTION_CCY , CONSUMER_PAID_CCY , SC_CODE  ORDER BY SC_DESC , bb.MBM_FE_DESC , STATUS , TRANSACTION_CCY , CONSUMER_PAID_CCY , SC_CODE; */ 


	/* EXEC SQL OPEN c_cursor_getdepositSumm; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "SELECT SC_DESC AS SC_DESC , STATUS AS STATUS , TRANSACTION_CCY AS TRANSA\
CTION_CCY , SUM ( TRANSACTION_AMOUNT ) AS COUNT_AMT , CONSUMER_PAID_CCY AS C\
ONSUMER_PAID_CCY , SUM ( CONSUMER_PAID_AMT ) AS COUNT_PAID_AMT , count ( TXN\
_ID ) AS COUNT_TXN FROM ( select STATUS , TRANSACTION_CCY , TRANSACTION_AMOU\
NT , CONSUMER_PAID_CCY , CONSUMER_PAID_AMT , TXN_ID , ACK_STATUS , SERVICE_C\
ODE , TXN_COUNTRY , CONSUMER_DEPOSIT_BANK , TP_PSP_ID from merch_rpt_all whe\
re client_id = :b0 and create_timestamp >= to_date ( :b1 , 'yyyymmdd' ) and \
create_timestamp < to_date ( :b1 , 'yyyymmdd' ) + 1 ) TXN_DETAIL LEFT JOIN D\
EF_SUB_STATUS ACK_STATUS ON ACK_STATUS = ACK_STATUS . DS_SUB_STATUS LEFT JOI\
N DEF_SERVICE_CODE ON SC_CODE = SERVICE_CODE LEFT JOIN COUNTRY ON COUNTRY_CO\
DE = TXN_COUNTRY LEFT JOIN ( SELECT BANK_NAME , MBM_FE_DESC , PSP_ID , EC_CH\
ANNEL , MOB_BANK_MAP_VIEW . GRP AS GRP FROM BANK_DESC , MOB_BANK_MAP LEFT JO\
IN MOB_BANK_MAP_VIEW on MBM_BANK_CODE = MOB_BANK_MAP_VIEW . BANK_CODE AND MB\
M_GROUP = MOB_BANK_MAP_VIEW . GRP WHERE ");
 sqlstm.stmt = sq0001;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_client_id;
 sqlstm.sqhstl[0] = (unsigned long )12;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_report_date;
 sqlstm.sqhstl[1] = (unsigned long )10;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_report_date;
 sqlstm.sqhstl[2] = (unsigned long )10;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto depositSumm_sql_error;
}


		

	do {
		/* EXEC SQL FETCH c_cursor_getdepositSumm
		INTO
			:v_service_desc:ind_service_desc,
			:v_status:ind_status,
			:v_txn_currency:ind_txn_currency,
			:v_txn_amount:ind_txn_amount,
			:v_paid_currency:ind_paid_currency,
			:v_paid_amount:ind_paid_amount,
			:v_txn_cnt:ind_txn_cnt
		; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )32;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_service_desc;
  sqlstm.sqhstl[0] = (unsigned long )53;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_service_desc;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[1] = (unsigned long )53;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_status;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_currency;
  sqlstm.sqhstl[2] = (unsigned long )5;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_txn_currency;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_amount;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_txn_amount;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_paid_currency;
  sqlstm.sqhstl[4] = (unsigned long )5;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_paid_currency;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_paid_amount;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_paid_amount;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_txn_cnt;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_txn_cnt;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto depositSumm_sql_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}
		
		fprintf(fp,"<Row>\n");

/* v_service_desc	*/
		if(ind_service_desc >= 0)
		{
			v_service_desc.arr[v_service_desc.len] = '\0';
			strcpy(csServiceDesc,(const char*)v_service_desc.arr);
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csServiceDesc);
/*DEBUGLOG(("process_client_txn_hist v_service_desc = [%s]\n", v_service_desc.arr));*/
		}
		else
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");
/* v_status	*/
		if(ind_status >= 0)
		{
			v_status.arr[v_status.len] = '\0';
			strcpy(csStatus,(const char*)v_status.arr);
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csStatus);
/*DEBUGLOG(("process_client_txn_hist v_status = [%s]\n", v_status.arr));*/
		}
		else
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");
/* v_txn_currency	*/
		if(ind_txn_currency >= 0)
		{
			v_txn_currency.arr[v_txn_currency.len] = '\0';
			strcpy(csTxnCurrency,(const char*)v_txn_currency.arr);
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csTxnCurrency);
/*DEBUGLOG(("process_client_txn_hist v_txn_currency = [%s]\n", v_txn_currency.arr));*/
		}
		else
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");
/*	v_txn_amount	*/
		if (ind_txn_amount >= 0)
		{
			dTxnAmount = v_txn_amount;
			format_commas(dTxnAmount, csTmp);
			/*fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%.2f</Data></Cell>\n",dTxnAmount);*/
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%s</Data></Cell>\n",csTmp);
/*DEBUGLOG(("process_client_txn_hist v_txn_amount = [%f]\n",v_txn_amount));*/
		}
		else
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">0</Data></Cell>\n");
/* 	v_paid_currency	*/
		if(ind_paid_currency >= 0)
		{
			v_paid_currency.arr[v_paid_currency.len] = '\0';
			strcpy(csPaidCurrency,(const char*)v_paid_currency.arr);
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csPaidCurrency);
/*DEBUGLOG(("process_client_txn_hist v_paid_currency = [%s]\n", v_paid_currency.arr));*/
		}
		else
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");
/*	v_paid_amount	*/
		if (ind_paid_amount >= 0)
		{
			dPaidAmount = v_paid_amount;
			format_commas(dPaidAmount, csTmp);
			/*fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%.2f</Data></Cell>\n",dPaidAmount);*/
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%s</Data></Cell>\n",csTmp);
/*DEBUGLOG(("process_client_txn_hist v_paid_amount = [%f]\n",v_paid_amount));*/
		}
		else
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">0</Data></Cell>\n");	
/*	v_txn_cnt	*/
		if (ind_txn_cnt >= 0)
		{
			dTxnCnt = v_txn_cnt;
			format_commas(dTxnCnt, csTmp);
			/*fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%.2f</Data></Cell>\n",dTxnCnt);*/
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%s</Data></Cell>\n",csTmp);
/*DEBUGLOG(("process_client_txn_hist v_txn_cnt = [%f]\n",v_txn_cnt));*/
		}
		else
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">0</Data></Cell>\n");


		fprintf(fp,"</Row>\n");
		

	
	
	} while (PD_TRUE);

	
	/* EXEC SQL CLOSE c_cursor_getdepositSumm; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )75;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto depositSumm_sql_error;
}


	

	return iRet;

depositSumm_sql_error:
DEBUGLOG(("extract_client_txn_hist_daily_rpt:process_depositSumm code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getdepositSumm; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )90;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	/* EXEC SQL ROLLBACK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )105;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



	return PD_ERR;
}



int process_clttxnhist(const char* csClientId,
                     const char* csReportDate,
                     FILE *fp)
{
	int   	iRet = SUCCESS;
	
	char	csTxnId[PD_TXN_SEQ_LEN+1];	
	char	csCountryName[PD_COUNTRY_NAME_LEN+1];	
	char	csServiceDesc[PD_SERVICE_DESC_LEN+1];	
	char	csMerShortName[PD_MERCH_SHORT_NAME_LEN+1];	
	char	csTxnDesc[PD_TXN_DESC_LEN+1];	
	char	csMerchantRef[PD_MERCHANT_REF_LEN+1];	
	char	csHoldbackCcy[PD_CCY_ID_LEN+1];	
	double	dHoldbackAmt;
	char	csStatus[PD_STATUS_DESC_LEN+1];	
	char	csAckStatus[PD_ACK_STATUS_NAME_LEN+1];	
	char	csCreateTimestamp[PD_TIMESTAMP_LEN+1];	
	char	csApprovalTimestamp[PD_TIMESTAMP_LEN+1];	
	char	csRemark[PD_REMARK_LEN+1];	
	double	dMerRequestAmt;
	char	csMerRequestCcy[PD_CCY_ID_LEN+1];	
	char	csBankName[PD_BANK_NAME_LEN+1];	
	char	csEcChannel[PD_EC_CHANNEL_LEN+1];	
	double	dConsumerPayableAmt;
	char	csConsumerPayableCcy[PD_CCY_ID_LEN+1];	
	double	dUniqueAmountMarkup;
	double	dConsumerPaidAmt;
	char	csConsumerPaidCcy[PD_CCY_ID_LEN+1];	
	double	dMerReceivedAmt;
	char	csMerReceivedCcy[PD_CCY_ID_LEN+1];	
	double	dTransactionFee;
	char	csTransactionFeeCcy[PD_CCY_ID_LEN+1];	
	double	dMerReceivedNetAmt;
	char	csMerReceivedNetCcy[PD_CCY_ID_LEN+1];	
	double	dMerPayableAmt;
	char	csMerPayableCcy[PD_CCY_ID_LEN+1];	
	double	dConsumerReceivedAmt;
	char	csConsumerReceivedCcy[PD_CCY_ID_LEN+1];	
	double	dMerPaidAmt;
	char	csMerPaidCcy[PD_CCY_ID_LEN+1];	
	double	dMerPaidTotalAmt;
	char	csMerPaidTotalCcy[PD_CCY_ID_LEN+1];	
	double	dMerReceivableAmt;
	char	csMerReceivableCcy[PD_CCY_ID_LEN+1];	
	double	dMerReceivableNetAmt;
	char	csMerReceivableNetCcy[PD_CCY_ID_LEN+1];	
	double	dFinalMerReceivedNetAmt;
	char	csFinalMerReceivedNetAmtCcy[PD_CCY_ID_LEN+1];	
	char	csBeneficiaryBankName[PD_BENEFICIARY_BANK_NAME_LEN+1];	
	char	csBeneficiaryBankAcNum[PD_BENEFICIARY_BANK_AC_NUM_LEN+1];  



	char csTmp[PD_TMP_BUF_LEN+1];


	/* EXEC SQL WHENEVER SQLERROR GOTO clttxnhist_sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

  
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar hv_client_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_client_id;

		/* varchar	hv_report_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_report_date;

    

		/* varchar	v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar	v_country_name[PD_COUNTRY_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_country_name;

		/* varchar	v_service_desc[PD_SERVICE_DESC_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_service_desc;

		/* varchar	v_mer_short_name[PD_MERCH_SHORT_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_mer_short_name;

		/* varchar	v_txn_desc[PD_TXN_DESC_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_desc;

		/* varchar	v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar	v_holdback_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_holdback_ccy;

		double	v_holdback_amt;
		/* varchar	v_status[PD_STATUS_DESC_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_status;

		/* varchar	v_ack_status[PD_ACK_STATUS_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_ack_status;

		/* varchar	v_create_timestamp[PD_TIMESTAMP_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_create_timestamp;

		/* varchar	v_approval_timestamp[PD_TIMESTAMP_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_approval_timestamp;

		/* varchar	v_remark[PD_REMARK_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;

		double	v_mer_request_amt;
		/* varchar	v_mer_request_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_mer_request_ccy;

		/* varchar	v_bank_name[PD_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

		/* varchar	v_ec_channel[PD_EC_CHANNEL_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_ec_channel;

		double	v_consumer_payable_amt;
		/* varchar	v_consumer_payable_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_consumer_payable_ccy;

		double	v_unique_amount_markup;
		double	v_consumer_paid_amt;
		/* varchar	v_consumer_paid_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_consumer_paid_ccy;

		double	v_mer_received_amt;
		/* varchar	v_mer_received_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_mer_received_ccy;

		double	v_transaction_fee;
		/* varchar	v_transaction_fee_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_transaction_fee_ccy;

		double	v_mer_received_net_amt;
		/* varchar	v_mer_received_net_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_mer_received_net_ccy;

		double	v_mer_payable_amt;
		/* varchar	v_mer_payable_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_mer_payable_ccy;

		double	v_consumer_received_amt;
		/* varchar	v_consumer_received_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_consumer_received_ccy;

		double	v_mer_paid_amt;
		/* varchar	v_mer_paid_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_mer_paid_ccy;

		double	v_mer_paid_total_amt;
		/* varchar	v_mer_paid_total_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_mer_paid_total_ccy;

		double	v_mer_receivable_amt;
		/* varchar	v_mer_receivable_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_mer_receivable_ccy;

		double	v_mer_receivable_net_amt;
		/* varchar	v_mer_receivable_net_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_mer_receivable_net_ccy;

		double	v_final_mer_received_net_amt;
		/* varchar	v_final_mer_received_net_amt_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_final_mer_received_net_amt_ccy;

		/* varchar	v_beneficiary_bank_name[PD_BENEFICIARY_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_beneficiary_bank_name;

		/* varchar	v_beneficiary_bank_ac_num[PD_BENEFICIARY_BANK_AC_NUM_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_beneficiary_bank_ac_num;


		short ind_txn_id = -1;
		short ind_country_name = -1;
		short ind_service_desc = -1;
		short ind_mer_short_name = -1;  
		short ind_txn_desc = -1;
		short ind_merchant_ref = -1;
		short ind_holdback_ccy = -1;
		short ind_holdback_amt = -1;
		short ind_status = -1;
		short ind_ack_status = -1;
		short ind_create_timestamp = -1;
		short ind_approval_timestamp = -1;
		short ind_remark = -1;
		short ind_mer_request_amt = -1;
		short ind_mer_request_ccy = -1;
		short ind_bank_name = -1;
		short ind_ec_channel = -1;
		short ind_consumer_payable_amt = -1;
		short ind_consumer_payable_ccy = -1;
		short ind_unique_amount_markup = -1;
		short ind_consumer_paid_amt = -1;
		short ind_consumer_paid_ccy = -1;
		short ind_mer_received_amt = -1;
		short ind_mer_received_ccy = -1;
		short ind_transaction_fee = -1;
		short ind_transaction_fee_ccy = -1;
		short ind_mer_received_net_amt = -1;
		short ind_mer_received_net_ccy = -1;
		short ind_mer_payable_amt = -1;
		short ind_mer_payable_ccy = -1;
		short ind_consumer_received_amt = -1;
		short ind_consumer_received_ccy = -1;
		short ind_mer_paid_amt = -1;
		short ind_mer_paid_ccy = -1;
		short ind_mer_paid_total_amt = -1;
		short ind_mer_paid_total_ccy = -1;
		short ind_mer_receivable_amt = -1;
		short ind_mer_receivable_ccy = -1;
		short ind_mer_receivable_net_amt = -1;
		short ind_mer_receivable_net_ccy = -1;
		short ind_final_mer_received_net_amt = -1;
		short ind_final_mer_received_net_amt_ccy = -1;
		short ind_beneficiary_bank_name = -1;
		short ind_beneficiary_bank_ac_num = -1;
		


	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("process_clttxnhist:Begin\n"));



	if(strlen(csClientId) > 0)
	{
		hv_client_id.len = strlen(csClientId);
		strncpy((char *)hv_client_id.arr, csClientId, hv_client_id.len);
DEBUGLOG(("process_clttxnhist:client_id = [%.*s]\n",hv_client_id.len,hv_client_id.arr));
	} else {
DEBUGLOG(("process_clttxnhist:client_id is missing\n"));
ERRLOG("extract_client_txn_hist_daily_rpt::process_clttxnhist: client_id is missing\n");
		return PD_ERR;
	}

	if(strlen(csReportDate) > 0)
	{
		hv_report_date.len = strlen(csReportDate);
		strncpy((char *)hv_report_date.arr, csReportDate, hv_report_date.len);
DEBUGLOG(("process_clttxnhist:report_date = [%.*s]\n",hv_report_date.len,hv_report_date.arr));
	} else {
DEBUGLOG(("process_clttxnhist:report_date is missing\n"));
ERRLOG("extract_client_txn_hist_daily_rpt::process_clttxnhist: report_date is missing\n");
		return PD_ERR;
	}
		
/* TXN */
	/* EXEC SQL DECLARE c_cursor_getclttxnhist CURSOR FOR

			  SELECT TXN_ID
					 AS TXN_ID,
				 COUNTRY.COUNTRY_NAME
					 AS COUNTRY_NAME,
				 SC_DESC
					 AS SERVICE_DESC,
				 MERCHANT_SHORT_NAME
					 AS SHORT_NAME,
				 TRANSACTION_TYPE
					 AS TXN_DESC,
				 DECODE (SC_CODE, 'VHS', 'N/A', MER_REFERENCE)
					 AS MERCHANT_REF,
				 HOLDBACK_CCY
					 AS HOLDBACK_CCY,
				 HOLDBACK_AMT
					 AS HOLDBACK_AMT,
				 STATUS
					 AS STATUS,
				 ACK_STATUS.DS_NAME
					 AS ACK_STATUS,
				 TO_CHAR(TXN_DETAIL.CREATE_TIMESTAMP, 'YYYY-MM-DD HH24:MI:SS')
					 AS CREATE_TIMESTAMP,
				 TO_CHAR(TXN_DETAIL.APPROVAL_TIMESTAMP, 'YYYY-MM-DD HH24:MI:SS')
					 AS APPROVAL_TIMESTAMP,
				 REMARK
					 AS REMARK,
				 MER_REQUEST_AMT
					 AS MER_REQUEST_AMT,
				 MER_REQUEST_CCY
					 AS MER_REQUEST_CCY,
				 CONSUMER_DEPOSIT_BANK
					 AS BANK_NAME,
				 EC_CHANNEL
					 AS EC_CHANNEL,
				 CONSUMER_PAYABLE_AMT
					 AS CONSUMER_PAYABLE_AMT,
				 CONSUMER_PAYABLE_CCY
					 AS CONSUMER_PAYABLE_CCY,
				 UNIQUE_AMOUNT_MARKUP
					 AS UNIQUE_AMOUNT_MARKUP,
				 CONSUMER_PAID_AMT
					 AS CONSUMER_PAID_AMT,
				 CONSUMER_PAID_CCY
					 AS CONSUMER_PAID_CCY,
				 MER_RECEIVED_AMT
					 AS MER_RECEIVED_AMT,
				 MER_RECEIVED_CCY
					 AS MER_RECEIVED_CCY,
				 TRANSACTION_FEE
					 AS TRANSACTION_FEE,
				 TRANSACTION_FEE_CCY
					 AS TRANSACTION_FEE_CCY,
				 MER_RECEIVED_NET_AMT
					 AS MER_RECEIVED_NET_AMT,
				 MER_RECEIVED_NET_AMT_CCY
					 AS MER_RECEIVED_NET_CCY,
				 MER_PAYABLE_AMOUNT
					 AS MER_PAYABLE_AMT,
				 MER_PAYABLE_CCY
					 AS MER_PAYABLE_CCY,
				 CONSUMER_RECEIVED_AMT
					 AS CONSUMER_RECEIVED_AMT,
				 CONSUMER_RECEIVED_CCY
					 AS CONSUMER_RECEIVED_CCY,
				 MER_PAID_AMOUNT
					 AS MER_PAID_AMT,
				 MER_PAID_CCY
					 AS MER_PAID_CCY,
				 MER_PAID_TOTAL_AMT
					 AS MER_PAID_TOTAL_AMT,
				 MER_PAID_TOTAL_AMT_CCY
					 AS MER_PAID_TOTAL_CCY,
				 MER_RECEIVABLE_AMT
					 AS MER_RECEIVABLE_AMT,
				 MER_RECEIVABLE_CCY
					 AS MER_RECEIVABLE_CCY,
				 MER_RECEIVABLE_NET_AMT
					 AS MER_RECEIVABLE_NET_AMT,
				 MER_RECEIVABLE_NET_AMT_CCY
					 AS MER_RECEIVABLE_NET_CCY,
				 FINAL_MER_RECEIVED_NET_AMT
					 AS FINAL_MER_RECEIVED_NET_AMT,
				 FINAL_MER_RECEIVED_NET_AMT_CCY
					 AS FINAL_MER_RECEIVED_NET_AMT_CCY,
				 BENEFICIARY_BANK_NAME
					 AS BENEFICIARY_BANK_NAME,
				 CASE
					 WHEN TXN_CODE = 'STR' THEN BENEFICIARY_BANK_AC_NUM
					 ELSE PAYOUT_ACCT_NUM
				 END
					 AS BENEFICIARY_BANK_AC_NUM
			FROM (	select CREATE_TIMESTAMP, 
					APPROVAL_TIMESTAMP,
					ACK_STATUS,
					SERVICE_CODE,
					TXN_COUNTRY,
					CONSUMER_DEPOSIT_BANK,
					TP_PSP_ID,
					TXN_ID,
					MERCHANT_SHORT_NAME,
					TRANSACTION_TYPE,
					MER_REFERENCE,
					HOLDBACK_CCY,
					HOLDBACK_AMT,
					STATUS,
					REMARK,
					MER_REQUEST_AMT,
					MER_REQUEST_CCY,
					CONSUMER_PAYABLE_AMT,
					CONSUMER_PAYABLE_CCY,
					UNIQUE_AMOUNT_MARKUP,
					CONSUMER_PAID_AMT,
					CONSUMER_PAID_CCY,
					MER_RECEIVED_AMT,
					MER_RECEIVED_CCY,
					TRANSACTION_FEE,
					TRANSACTION_FEE_CCY,
					MER_RECEIVED_NET_AMT,
					MER_RECEIVED_NET_AMT_CCY,
					MER_PAYABLE_AMOUNT,
					MER_PAYABLE_CCY,
					CONSUMER_RECEIVED_AMT,
					CONSUMER_RECEIVED_CCY,
					MER_PAID_AMOUNT,
					MER_PAID_CCY,
					MER_PAID_TOTAL_AMT,
					MER_PAID_TOTAL_AMT_CCY,
					MER_RECEIVABLE_AMT,
					MER_RECEIVABLE_CCY,
					MER_RECEIVABLE_NET_AMT,
					MER_RECEIVABLE_NET_AMT_CCY,
					FINAL_MER_RECEIVED_NET_AMT,
					FINAL_MER_RECEIVED_NET_AMT_CCY,
					BENEFICIARY_BANK_NAME,
					TXN_CODE,
					PAYOUT_ACCT_NUM,
					BENEFICIARY_BANK_AC_NUM
					from merch_rpt_all
					where client_id = :hv_client_id
					and CREATE_TIMESTAMP >= to_date(:hv_report_date, 'yyyymmdd')
					and CREATE_TIMESTAMP < to_date(:hv_report_date, 'yyyymmdd')+1
				) TXN_DETAIL
				 LEFT JOIN DEF_SUB_STATUS ACK_STATUS
					 ON ACK_STATUS = ACK_STATUS.DS_SUB_STATUS
				 LEFT JOIN DEF_SERVICE_CODE ON SC_CODE = SERVICE_CODE
				 LEFT JOIN COUNTRY ON COUNTRY_CODE = TXN_COUNTRY
				 LEFT JOIN
				 (SELECT BANK_NAME,
						 MBM_FE_DESC,
						 PSP_ID,
						 EC_CHANNEL
					FROM BANK_DESC,
						 MOB_BANK_MAP
						 LEFT JOIN MOB_BANK_MAP_VIEW
							 ON     MBM_BANK_CODE = MOB_BANK_MAP_VIEW.BANK_CODE
								AND MBM_GROUP = MOB_BANK_MAP_VIEW.GRP
				   WHERE     INTERNAL_BANK_CODE = MBM_BANK_CODE
						 AND FE_DESC IS NOT NULL
						 AND EC_CHANNEL IS NOT NULL
						 AND GRP = 'SEG_ECT') bb
					 ON bb.BANK_NAME = CONSUMER_DEPOSIT_BANK AND TP_PSP_ID = PSP_ID
				 LEFT JOIN
				 (SELECT DTR_ENQUIRY_STATUS, DTR_TXN_ID
					FROM (SELECT DTR_ENQUIRY_STATUS,
								 DTR_TXN_ID,
								 ROW_NUMBER ()
								 OVER (PARTITION BY DTR_TXN_ID
									   ORDER BY DTR_CREATE_TIMESTAMP DESC)
									 AS ROWNO
							FROM DEPOSIT_TRACE
						   WHERE DTR_ENQUIRY_STATUS IS NOT NULL)
				   WHERE ROWNO = 1) ADT
					 ON ADT.DTR_TXN_ID = TXN_ID
				 LEFT JOIN DEF_ENQUIRY_STATUS
					 ON DEF_ENQUIRY_STATUS.DE_CODE = ADT.DTR_ENQUIRY_STATUS
				 LEFT JOIN
				 (SELECT DTR_TXN_ID, MERCHANT_CREATE_USER, MERCHANT_CREATE_TIMESTAMP
					FROM (SELECT DTR_TXN_ID,
								 DTR_CREATE_USER
									 AS MERCHANT_CREATE_USER,
								 DTR_CREATE_TIMESTAMP
									 AS MERCHANT_CREATE_TIMESTAMP,
								 ROW_NUMBER ()
								 OVER (PARTITION BY DTR_TXN_ID
									   ORDER BY DTR_CREATE_TIMESTAMP DESC)
									 AS ROWNO
							FROM DEPOSIT_TRACE
						   WHERE DTR_PARTY_TYPE = 'M')
				   WHERE ROWNO = 1) MDT
					 ON MDT.DTR_TXN_ID = TXN_ID
				 LEFT JOIN
				 (SELECT DTR_TXN_ID, ADMIN_CREATE_USER, ADMIN_CREATE_TIMESTAMP
					FROM (SELECT DTR_TXN_ID,
								 CASE
									 WHEN DTR_UPDATE_USER IS NOT NULL
									 THEN
										 'System Administrator'
									 ELSE
										 ''
								 END
									 ADMIN_CREATE_USER,
								 DTR_CREATE_TIMESTAMP
									 AS ADMIN_CREATE_TIMESTAMP,
								 ROW_NUMBER ()
								 OVER (PARTITION BY DTR_TXN_ID
									   ORDER BY DTR_CREATE_TIMESTAMP DESC)
									 AS ROWNO
							FROM DEPOSIT_TRACE
						   WHERE DTR_PARTY_TYPE = 'A')
				   WHERE ROWNO = 1) ADT2
					 ON ADT2.DTR_TXN_ID = TXN_ID
		   WHERE 1 = 1
		ORDER BY CREATE_TIMESTAMP DESC, TXN_ID DESC; */ 

		
	/* EXEC SQL OPEN c_cursor_getclttxnhist; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "SELECT TXN_ID AS TXN_ID , COUNTRY . COUNTRY_NAME AS COUNTRY_NAME , SC_DE\
SC AS SERVICE_DESC , MERCHANT_SHORT_NAME AS SHORT_NAME , TRANSACTION_TYPE AS\
 TXN_DESC , DECODE ( SC_CODE , 'VHS' , 'N/A' , MER_REFERENCE ) AS MERCHANT_R\
EF , HOLDBACK_CCY AS HOLDBACK_CCY , HOLDBACK_AMT AS HOLDBACK_AMT , STATUS AS\
 STATUS , ACK_STATUS . DS_NAME AS ACK_STATUS , TO_CHAR ( TXN_DETAIL . CREATE\
_TIMESTAMP , 'YYYY-MM-DD HH24:MI:SS' ) AS CREATE_TIMESTAMP , TO_CHAR ( TXN_D\
ETAIL . APPROVAL_TIMESTAMP , 'YYYY-MM-DD HH24:MI:SS' ) AS APPROVAL_TIMESTAMP\
 , REMARK AS REMARK , MER_REQUEST_AMT AS MER_REQUEST_AMT , MER_REQUEST_CCY A\
S MER_REQUEST_CCY , CONSUMER_DEPOSIT_BANK AS BANK_NAME , EC_CHANNEL AS EC_CH\
ANNEL , CONSUMER_PAYABLE_AMT AS CONSUMER_PAYABLE_AMT , CONSUMER_PAYABLE_CCY \
AS CONSUMER_PAYABLE_CCY , UNIQUE_AMOUNT_MARKUP AS UNIQUE_AMOUNT_MARKUP , CON\
SUMER_PAID_AMT AS CONSUMER_PAID_AMT , CONSUMER_PAID_CCY AS CONSUMER_PAID_CCY\
 , MER_RECEIVED_AMT AS MER_RECEIVED_AMT , MER_RECEIVED_CCY AS MER_RECEIVED_C\
CY , TRANSACTION_FEE AS TRANSACTION_FEE ");
 sqlbuft((void **)0,
   ", TRANSACTION_FEE_CCY AS TRANSACTION_FEE_CCY , MER_RECEIVED_NET_AMT AS M\
ER_RECEIVED_NET_AMT , MER_RECEIVED_NET_AMT_CCY AS MER_RECEIVED_NET_CCY , MER\
_PAYABLE_AMOUNT AS MER_PAYABLE_AMT , MER_PAYABLE_CCY AS MER_PAYABLE_CCY , CO\
NSUMER_RECEIVED_AMT AS CONSUMER_RECEIVED_AMT , CONSUMER_RECEIVED_CCY AS CONS\
UMER_RECEIVED_CCY , MER_PAID_AMOUNT AS MER_PAID_AMT , MER_PAID_CCY AS MER_PA\
ID_CCY , MER_PAID_TOTAL_AMT AS MER_PAID_TOTAL_AMT , MER_PAID_TOTAL_AMT_CCY A\
S MER_PAID_TOTAL_CCY , MER_RECEIVABLE_AMT AS MER_RECEIVABLE_AMT , MER_RECEIV\
ABLE_CCY AS MER_RECEIVABLE_CCY , MER_RECEIVABLE_NET_AMT AS MER_RECEIVABLE_NE\
T_AMT , MER_RECEIVABLE_NET_AMT_CCY AS MER_RECEIVABLE_NET_CCY , FINAL_MER_REC\
EIVED_NET_AMT AS FINAL_MER_RECEIVED_NET_AMT , FINAL_MER_RECEIVED_NET_AMT_CCY\
 AS FINAL_MER_RECEIVED_NET_AMT_CCY , BENEFICIARY_BANK_NAME AS BENEFICIARY_BA\
NK_NAME , CASE WHEN TXN_CODE = 'STR' THEN BENEFICIARY_BANK_AC_NUM ELSE PAYOU\
T_ACCT_NUM END AS BENEFICIARY_BANK_AC_NUM FROM ( select CREATE_TIMESTAMP , A\
PPROVAL_TIMESTAMP , ACK_STATUS , SERVICE");
 sqlbuft((void **)0,
   "_CODE , TXN_COUNTRY , CONSUMER_DEPOSIT_BANK , TP_PSP_ID , TXN_ID , MERCH\
ANT_SHORT_NAME , TRANSACTION_TYPE , MER_REFERENCE , HOLDBACK_CCY , HOLDBACK_\
AMT , STATUS , REMARK , MER_REQUEST_AMT , MER_REQUEST_CCY , CONSUMER_PAYABLE\
_AMT , CONSUMER_PAYABLE_CCY , UNIQUE_AMOUNT_MARKUP , CONSUMER_PAID_AMT , CON\
SUMER_PAID_CCY , MER_RECEIVED_AMT , MER_RECEIVED_CCY , TRANSACTION_FEE , TRA\
NSACTION_FEE_CCY , MER_RECEIVED_NET_AMT , MER_RECEIVED_NET_AMT_CCY , MER_PAY\
ABLE_AMOUNT , MER_PAYABLE_CCY , CONSUMER_RECEIVED_AMT , CONSUMER_RECEIVED_CC\
Y , MER_PAID_AMOUNT , MER_PAID_CCY , MER_PAID_TOTAL_AMT , MER_PAID_TOTAL_AMT\
_CCY , MER_RECEIVABLE_AMT , MER_RECEIVABLE_CCY , MER_RECEIVABLE_NET_AMT , ME\
R_RECEIVABLE_NET_AMT_CCY , FINAL_MER_RECEIVED_NET_AMT , FINAL_MER_RECEIVED_N\
ET_AMT_CCY , BENEFICIARY_BANK_NAME , TXN_CODE , PAYOUT_ACCT_NUM , BENEFICIAR\
Y_BANK_AC_NUM from merch_rpt_all where client_id = :b0 and CREATE_TIMESTAMP \
>= to_date ( :b1 , 'yyyymmdd' ) and CREATE_TIMESTAMP < to_date ( :b1 , 'yyyy\
mmdd' ) + 1 ) TXN_DETAIL LEFT JOIN DEF_S");
 sqlbuft((void **)0,
   "UB_STATUS ACK_STATUS ON ACK_STATUS = ACK_STATUS . DS_SUB_STATUS LEFT JOI\
N DEF_SERVICE_CODE ON SC_CODE = SERVICE_CODE LEFT JOIN COUNTRY ON COUNTRY_CO\
DE = TXN_COUNTRY LEFT JOIN ( SELECT BANK_NAME , MBM_FE_DESC , PSP_ID , EC_CH\
ANNEL FROM BANK_DESC , MOB_BANK_MAP LEFT JOIN MOB_BANK_MAP_VIEW ON MBM_BANK_\
CODE = MOB_BANK_MAP_VIEW . BANK_CODE AND MBM_GROUP = MOB_BANK_MAP_VIEW . GRP\
 WHERE INTERNAL_BANK_CODE = MBM_BANK_CODE AND FE_DESC IS NOT NULL AND EC_CHA\
NNEL IS NOT NULL AND GRP = 'SEG_ECT' ) bb ON bb . BANK_NAME = CONSUMER_DEPOS\
IT_BANK AND TP_PSP_ID = PSP_ID LEFT JOIN ( SELECT DTR_ENQUIRY_STATUS , DTR_T\
XN_ID FROM ( SELECT DTR_ENQUIRY_STATUS , DTR_TXN_ID , ROW_NUMBER ( ) OVER ( \
PARTITION BY DTR_TXN_ID ORDER BY DTR_CREATE_TIMESTAMP DESC ) AS ROWNO FROM D\
EPOSIT_TRACE WHERE DTR_ENQUIRY_STATUS IS NOT NULL ) WHERE ROWNO = 1 ) ADT ON\
 ADT . DTR_TXN_ID = TXN_ID LEFT JOIN DEF_ENQUIRY_STATUS ON DEF_ENQUIRY_STATU\
S . DE_CODE = ADT . DTR_ENQUIRY_STATUS LEFT JOIN ( SELECT DTR_TXN_ID , MERCH\
ANT_CREATE_USER , MERCHANT_CREATE_TIMEST");
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )120;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_client_id;
 sqlstm.sqhstl[0] = (unsigned long )12;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_report_date;
 sqlstm.sqhstl[1] = (unsigned long )10;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_report_date;
 sqlstm.sqhstl[2] = (unsigned long )10;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto clttxnhist_sql_error;
}


	
	do {

		/* EXEC SQL FETCH c_cursor_getclttxnhist
		INTO
			:v_txn_id:ind_txn_id,       					
			:v_country_name:ind_country_name,                  
			:v_service_desc:ind_service_desc,                  
			:v_mer_short_name:ind_mer_short_name,                    
			:v_txn_desc:ind_txn_desc,                      
			:v_merchant_ref:ind_merchant_ref,                  
			:v_holdback_ccy:ind_holdback_ccy,                  
			:v_holdback_amt:ind_holdback_amt,                   
			:v_status:ind_status,                        
			:v_ack_status:ind_ack_status,                    
			:v_create_timestamp:ind_create_timestamp,              
			:v_approval_timestamp:ind_approval_timestamp,                   
			:v_remark:ind_remark,                        
			:v_mer_request_amt:ind_mer_request_amt,                
			:v_mer_request_ccy:ind_mer_request_ccy,               
			:v_bank_name:ind_bank_name,                     
			:v_ec_channel:ind_ec_channel,                    
			:v_consumer_payable_amt:ind_consumer_payable_amt,           
			:v_consumer_payable_ccy:ind_consumer_payable_ccy,          
			:v_unique_amount_markup:ind_unique_amount_markup,           
			:v_consumer_paid_amt:ind_consumer_paid_amt,              
			:v_consumer_paid_ccy:ind_consumer_paid_ccy,             
			:v_mer_received_amt:ind_mer_received_amt,               
			:v_mer_received_ccy:ind_mer_received_ccy,              
			:v_transaction_fee:ind_transaction_fee,                
			:v_transaction_fee_ccy:ind_transaction_fee_ccy,           
			:v_mer_received_net_amt:ind_mer_received_net_amt,           
			:v_mer_received_net_ccy:ind_mer_received_net_ccy,          
			:v_mer_payable_amt:ind_mer_payable_amt,                
			:v_mer_payable_ccy:ind_mer_payable_ccy,               
			:v_consumer_received_amt:ind_consumer_received_amt,          
			:v_consumer_received_ccy:ind_consumer_received_ccy,         
			:v_mer_paid_amt:ind_mer_paid_amt,                   
			:v_mer_paid_ccy:ind_mer_paid_ccy,                  
			:v_mer_paid_total_amt:ind_mer_paid_total_amt,             
			:v_mer_paid_total_ccy:ind_mer_paid_total_ccy,            
			:v_mer_receivable_amt:ind_mer_receivable_amt,             
			:v_mer_receivable_ccy:ind_mer_receivable_ccy,            
			:v_mer_receivable_net_amt:ind_mer_receivable_net_amt,         
			:v_mer_receivable_net_ccy:ind_mer_receivable_net_ccy,        
			:v_final_mer_received_net_amt:ind_final_mer_received_net_amt,     
			:v_final_mer_received_net_amt_ccy:ind_final_mer_received_net_amt_ccy,
			:v_beneficiary_bank_name:ind_beneficiary_bank_name,         
			:v_beneficiary_bank_ac_num:ind_beneficiary_bank_ac_num
		; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 44;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )147;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_txn_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_country_name;
  sqlstm.sqhstl[1] = (unsigned long )53;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_country_name;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_service_desc;
  sqlstm.sqhstl[2] = (unsigned long )53;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_service_desc;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_mer_short_name;
  sqlstm.sqhstl[3] = (unsigned long )23;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_mer_short_name;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_txn_desc;
  sqlstm.sqhstl[4] = (unsigned long )53;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_txn_desc;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_merchant_ref;
  sqlstm.sqhstl[5] = (unsigned long )53;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_merchant_ref;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_holdback_ccy;
  sqlstm.sqhstl[6] = (unsigned long )6;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_holdback_ccy;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_holdback_amt;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_holdback_amt;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[8] = (unsigned long )53;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_status;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_ack_status;
  sqlstm.sqhstl[9] = (unsigned long )53;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_ack_status;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_create_timestamp;
  sqlstm.sqhstl[10] = (unsigned long )23;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_create_timestamp;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_approval_timestamp;
  sqlstm.sqhstl[11] = (unsigned long )23;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_approval_timestamp;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_remark;
  sqlstm.sqhstl[12] = (unsigned long )258;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_remark;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_mer_request_amt;
  sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_mer_request_amt;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_mer_request_ccy;
  sqlstm.sqhstl[14] = (unsigned long )6;
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_mer_request_ccy;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_bank_name;
  sqlstm.sqhstl[15] = (unsigned long )153;
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_bank_name;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&v_ec_channel;
  sqlstm.sqhstl[16] = (unsigned long )153;
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)&ind_ec_channel;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)&v_consumer_payable_amt;
  sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)&ind_consumer_payable_amt;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)&v_consumer_payable_ccy;
  sqlstm.sqhstl[18] = (unsigned long )6;
  sqlstm.sqhsts[18] = (         int  )0;
  sqlstm.sqindv[18] = (         short *)&ind_consumer_payable_ccy;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)&v_unique_amount_markup;
  sqlstm.sqhstl[19] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[19] = (         int  )0;
  sqlstm.sqindv[19] = (         short *)&ind_unique_amount_markup;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)&v_consumer_paid_amt;
  sqlstm.sqhstl[20] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[20] = (         int  )0;
  sqlstm.sqindv[20] = (         short *)&ind_consumer_paid_amt;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)&v_consumer_paid_ccy;
  sqlstm.sqhstl[21] = (unsigned long )6;
  sqlstm.sqhsts[21] = (         int  )0;
  sqlstm.sqindv[21] = (         short *)&ind_consumer_paid_ccy;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)&v_mer_received_amt;
  sqlstm.sqhstl[22] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[22] = (         int  )0;
  sqlstm.sqindv[22] = (         short *)&ind_mer_received_amt;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)&v_mer_received_ccy;
  sqlstm.sqhstl[23] = (unsigned long )6;
  sqlstm.sqhsts[23] = (         int  )0;
  sqlstm.sqindv[23] = (         short *)&ind_mer_received_ccy;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)&v_transaction_fee;
  sqlstm.sqhstl[24] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[24] = (         int  )0;
  sqlstm.sqindv[24] = (         short *)&ind_transaction_fee;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)&v_transaction_fee_ccy;
  sqlstm.sqhstl[25] = (unsigned long )6;
  sqlstm.sqhsts[25] = (         int  )0;
  sqlstm.sqindv[25] = (         short *)&ind_transaction_fee_ccy;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)&v_mer_received_net_amt;
  sqlstm.sqhstl[26] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[26] = (         int  )0;
  sqlstm.sqindv[26] = (         short *)&ind_mer_received_net_amt;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)&v_mer_received_net_ccy;
  sqlstm.sqhstl[27] = (unsigned long )6;
  sqlstm.sqhsts[27] = (         int  )0;
  sqlstm.sqindv[27] = (         short *)&ind_mer_received_net_ccy;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)&v_mer_payable_amt;
  sqlstm.sqhstl[28] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[28] = (         int  )0;
  sqlstm.sqindv[28] = (         short *)&ind_mer_payable_amt;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
  sqlstm.sqhstv[29] = (unsigned char  *)&v_mer_payable_ccy;
  sqlstm.sqhstl[29] = (unsigned long )6;
  sqlstm.sqhsts[29] = (         int  )0;
  sqlstm.sqindv[29] = (         short *)&ind_mer_payable_ccy;
  sqlstm.sqinds[29] = (         int  )0;
  sqlstm.sqharm[29] = (unsigned long )0;
  sqlstm.sqadto[29] = (unsigned short )0;
  sqlstm.sqtdso[29] = (unsigned short )0;
  sqlstm.sqhstv[30] = (unsigned char  *)&v_consumer_received_amt;
  sqlstm.sqhstl[30] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[30] = (         int  )0;
  sqlstm.sqindv[30] = (         short *)&ind_consumer_received_amt;
  sqlstm.sqinds[30] = (         int  )0;
  sqlstm.sqharm[30] = (unsigned long )0;
  sqlstm.sqadto[30] = (unsigned short )0;
  sqlstm.sqtdso[30] = (unsigned short )0;
  sqlstm.sqhstv[31] = (unsigned char  *)&v_consumer_received_ccy;
  sqlstm.sqhstl[31] = (unsigned long )6;
  sqlstm.sqhsts[31] = (         int  )0;
  sqlstm.sqindv[31] = (         short *)&ind_consumer_received_ccy;
  sqlstm.sqinds[31] = (         int  )0;
  sqlstm.sqharm[31] = (unsigned long )0;
  sqlstm.sqadto[31] = (unsigned short )0;
  sqlstm.sqtdso[31] = (unsigned short )0;
  sqlstm.sqhstv[32] = (unsigned char  *)&v_mer_paid_amt;
  sqlstm.sqhstl[32] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[32] = (         int  )0;
  sqlstm.sqindv[32] = (         short *)&ind_mer_paid_amt;
  sqlstm.sqinds[32] = (         int  )0;
  sqlstm.sqharm[32] = (unsigned long )0;
  sqlstm.sqadto[32] = (unsigned short )0;
  sqlstm.sqtdso[32] = (unsigned short )0;
  sqlstm.sqhstv[33] = (unsigned char  *)&v_mer_paid_ccy;
  sqlstm.sqhstl[33] = (unsigned long )6;
  sqlstm.sqhsts[33] = (         int  )0;
  sqlstm.sqindv[33] = (         short *)&ind_mer_paid_ccy;
  sqlstm.sqinds[33] = (         int  )0;
  sqlstm.sqharm[33] = (unsigned long )0;
  sqlstm.sqadto[33] = (unsigned short )0;
  sqlstm.sqtdso[33] = (unsigned short )0;
  sqlstm.sqhstv[34] = (unsigned char  *)&v_mer_paid_total_amt;
  sqlstm.sqhstl[34] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[34] = (         int  )0;
  sqlstm.sqindv[34] = (         short *)&ind_mer_paid_total_amt;
  sqlstm.sqinds[34] = (         int  )0;
  sqlstm.sqharm[34] = (unsigned long )0;
  sqlstm.sqadto[34] = (unsigned short )0;
  sqlstm.sqtdso[34] = (unsigned short )0;
  sqlstm.sqhstv[35] = (unsigned char  *)&v_mer_paid_total_ccy;
  sqlstm.sqhstl[35] = (unsigned long )6;
  sqlstm.sqhsts[35] = (         int  )0;
  sqlstm.sqindv[35] = (         short *)&ind_mer_paid_total_ccy;
  sqlstm.sqinds[35] = (         int  )0;
  sqlstm.sqharm[35] = (unsigned long )0;
  sqlstm.sqadto[35] = (unsigned short )0;
  sqlstm.sqtdso[35] = (unsigned short )0;
  sqlstm.sqhstv[36] = (unsigned char  *)&v_mer_receivable_amt;
  sqlstm.sqhstl[36] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[36] = (         int  )0;
  sqlstm.sqindv[36] = (         short *)&ind_mer_receivable_amt;
  sqlstm.sqinds[36] = (         int  )0;
  sqlstm.sqharm[36] = (unsigned long )0;
  sqlstm.sqadto[36] = (unsigned short )0;
  sqlstm.sqtdso[36] = (unsigned short )0;
  sqlstm.sqhstv[37] = (unsigned char  *)&v_mer_receivable_ccy;
  sqlstm.sqhstl[37] = (unsigned long )6;
  sqlstm.sqhsts[37] = (         int  )0;
  sqlstm.sqindv[37] = (         short *)&ind_mer_receivable_ccy;
  sqlstm.sqinds[37] = (         int  )0;
  sqlstm.sqharm[37] = (unsigned long )0;
  sqlstm.sqadto[37] = (unsigned short )0;
  sqlstm.sqtdso[37] = (unsigned short )0;
  sqlstm.sqhstv[38] = (unsigned char  *)&v_mer_receivable_net_amt;
  sqlstm.sqhstl[38] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[38] = (         int  )0;
  sqlstm.sqindv[38] = (         short *)&ind_mer_receivable_net_amt;
  sqlstm.sqinds[38] = (         int  )0;
  sqlstm.sqharm[38] = (unsigned long )0;
  sqlstm.sqadto[38] = (unsigned short )0;
  sqlstm.sqtdso[38] = (unsigned short )0;
  sqlstm.sqhstv[39] = (unsigned char  *)&v_mer_receivable_net_ccy;
  sqlstm.sqhstl[39] = (unsigned long )6;
  sqlstm.sqhsts[39] = (         int  )0;
  sqlstm.sqindv[39] = (         short *)&ind_mer_receivable_net_ccy;
  sqlstm.sqinds[39] = (         int  )0;
  sqlstm.sqharm[39] = (unsigned long )0;
  sqlstm.sqadto[39] = (unsigned short )0;
  sqlstm.sqtdso[39] = (unsigned short )0;
  sqlstm.sqhstv[40] = (unsigned char  *)&v_final_mer_received_net_amt;
  sqlstm.sqhstl[40] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[40] = (         int  )0;
  sqlstm.sqindv[40] = (         short *)&ind_final_mer_received_net_amt;
  sqlstm.sqinds[40] = (         int  )0;
  sqlstm.sqharm[40] = (unsigned long )0;
  sqlstm.sqadto[40] = (unsigned short )0;
  sqlstm.sqtdso[40] = (unsigned short )0;
  sqlstm.sqhstv[41] = (unsigned char  *)&v_final_mer_received_net_amt_ccy;
  sqlstm.sqhstl[41] = (unsigned long )6;
  sqlstm.sqhsts[41] = (         int  )0;
  sqlstm.sqindv[41] = (         short *)&ind_final_mer_received_net_amt_ccy;
  sqlstm.sqinds[41] = (         int  )0;
  sqlstm.sqharm[41] = (unsigned long )0;
  sqlstm.sqadto[41] = (unsigned short )0;
  sqlstm.sqtdso[41] = (unsigned short )0;
  sqlstm.sqhstv[42] = (unsigned char  *)&v_beneficiary_bank_name;
  sqlstm.sqhstl[42] = (unsigned long )103;
  sqlstm.sqhsts[42] = (         int  )0;
  sqlstm.sqindv[42] = (         short *)&ind_beneficiary_bank_name;
  sqlstm.sqinds[42] = (         int  )0;
  sqlstm.sqharm[42] = (unsigned long )0;
  sqlstm.sqadto[42] = (unsigned short )0;
  sqlstm.sqtdso[42] = (unsigned short )0;
  sqlstm.sqhstv[43] = (unsigned char  *)&v_beneficiary_bank_ac_num;
  sqlstm.sqhstl[43] = (unsigned long )53;
  sqlstm.sqhsts[43] = (         int  )0;
  sqlstm.sqindv[43] = (         short *)&ind_beneficiary_bank_ac_num;
  sqlstm.sqinds[43] = (         int  )0;
  sqlstm.sqharm[43] = (unsigned long )0;
  sqlstm.sqadto[43] = (unsigned short )0;
  sqlstm.sqtdso[43] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto clttxnhist_sql_error;
}


	
		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}
		
		fprintf(fp,"<Row>\n");

/* v_txn_id	*/
		if(ind_txn_id >= 0)
		{
			v_txn_id.arr[v_txn_id.len] = '\0';	
			strcpy(csTxnId,(const char*)v_txn_id.arr);	
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csTxnId);	
/*DEBUGLOG(("process_client_txn_hist v_txn_id = [%s]\n", v_txn_id.arr));*/	
		}	
		else	
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");	
/* v_country_name	*/	
		if(ind_country_name >= 0)	
		{	
			v_country_name.arr[v_country_name.len] = '\0';	
			strcpy(csCountryName,(const char*)v_country_name.arr);	
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csCountryName);	
/*DEBUGLOG(("process_client_txn_hist v_country_name = [%s]\n", v_country_name.arr));*/	
		}	
		else	
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");	
/* v_service_desc	*/	
		if(ind_service_desc >= 0)	
		{	
			v_service_desc.arr[v_service_desc.len] = '\0';	
			strcpy(csServiceDesc,(const char*)v_service_desc.arr);	
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csServiceDesc);	
/*DEBUGLOG(("process_client_txn_hist v_service_desc = [%s]\n", v_service_desc.arr));*/	
		}	
		else	
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");	
/* v_mer_short_name	*/	
		if(ind_mer_short_name >= 0)	
		{	
			v_mer_short_name.arr[v_mer_short_name.len] = '\0';	
			strcpy(csMerShortName,(const char*)v_mer_short_name.arr);	
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csMerShortName);	
/*DEBUGLOG(("process_client_txn_hist v_mer_short_name = [%s]\n", v_mer_short_name.arr));*/	
		}	
		else	
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");	
/* v_txn_desc	*/	
		if(ind_txn_desc >= 0)	
		{	
			v_txn_desc.arr[v_txn_desc.len] = '\0';	
			strcpy(csTxnDesc,(const char*)v_txn_desc.arr);	
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csTxnDesc);	
/*DEBUGLOG(("process_client_txn_hist v_txn_desc = [%s]\n", v_txn_desc.arr));*/	
		}	
		else	
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");	
/* v_merchant_ref	*/	
		if(ind_merchant_ref >= 0)	
		{	
			v_merchant_ref.arr[v_merchant_ref.len] = '\0';	
			strcpy(csMerchantRef,(const char*)v_merchant_ref.arr);	
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csMerchantRef);	
/*DEBUGLOG(("process_client_txn_hist v_merchant_ref = [%s]\n", v_merchant_ref.arr));*/	
		}	
		else	
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");	
/* v_holdback_ccy	*/	
		if(ind_holdback_ccy >= 0)	
		{	
			v_holdback_ccy.arr[v_holdback_ccy.len] = '\0';	
			strcpy(csHoldbackCcy,(const char*)v_holdback_ccy.arr);	
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csHoldbackCcy);	
/*DEBUGLOG(("process_client_txn_hist v_holdback_ccy = [%s]\n", v_holdback_ccy.arr));*/	
		}	
		else	
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");	
/*	v_holdback_amt	*/	
		if (ind_holdback_amt >= 0)	
		{	
			dHoldbackAmt = v_holdback_amt;	
			format_commas(dHoldbackAmt, csTmp);	
			/*fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%.2f</Data></Cell>\n",dHoldbackAmt);*/	
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%s</Data></Cell>\n",csTmp);	
/*DEBUGLOG(("process_client_txn_hist v_holdback_amt = [%f]\n",v_holdback_amt));*/	
		}	
		else	
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">0</Data></Cell>\n");	
/* v_status	*/	
		if(ind_status >= 0)	
		{	
			v_status.arr[v_status.len] = '\0';	
			strcpy(csStatus,(const char*)v_status.arr);	
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csStatus);	
/*DEBUGLOG(("process_client_txn_hist v_status = [%s]\n", v_status.arr));*/	
		}	
		else	
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");	
/* v_ack_status	*/	
		if(ind_ack_status >= 0)	
		{	
			v_ack_status.arr[v_ack_status.len] = '\0';	
			strcpy(csAckStatus,(const char*)v_ack_status.arr);	
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csAckStatus);	
/*DEBUGLOG(("process_client_txn_hist v_ack_status = [%s]\n", v_ack_status.arr));*/	
		}	
		else	
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");		
/* v_create_timestamp	*/	
		if(ind_create_timestamp >= 0)	
		{	
			v_create_timestamp.arr[v_create_timestamp.len] = '\0';	
			strcpy(csCreateTimestamp,(const char*)v_create_timestamp.arr);	
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csCreateTimestamp);	
/*DEBUGLOG(("process_client_txn_hist v_create_timestamp = [%s]\n", v_create_timestamp.arr));*/	
		}	
		else	
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");	
/* v_approval_timestamp	*/	
		if(ind_approval_timestamp >= 0)	
		{	
			v_approval_timestamp.arr[v_approval_timestamp.len] = '\0';	
			strcpy(csApprovalTimestamp,(const char*)v_approval_timestamp.arr);	
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csApprovalTimestamp);	
/*DEBUGLOG(("process_client_txn_hist v_approval_timestamp = [%s]\n", v_approval_timestamp.arr));*/	
		}	
		else	
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");
/* v_remark	*/	
		if(ind_remark >= 0)	
		{	
			v_remark.arr[v_remark.len] = '\0';	
			strcpy(csRemark,(const char*)v_remark.arr);	
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csRemark);	
/*DEBUGLOG(("process_client_txn_hist v_remark = [%s]\n", v_remark.arr));*/	
		}	
		else	
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");
/*	v_mer_request_amt	*/	
		if (ind_mer_request_amt >= 0)	
		{	
			dMerRequestAmt = v_mer_request_amt;	
			format_commas(dMerRequestAmt, csTmp);	
			/*fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%.2f</Data></Cell>\n",dMerRequestAmt);*/	
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%s</Data></Cell>\n",csTmp);	
/*DEBUGLOG(("process_client_txn_hist v_mer_request_amt = [%f]\n",v_mer_request_amt));*/	
		}	
		else	
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">0</Data></Cell>\n");				
/* v_mer_request_ccy	*/	
		if(ind_mer_request_ccy >= 0)	
		{	
			v_mer_request_ccy.arr[v_mer_request_ccy.len] = '\0';	
			strcpy(csMerRequestCcy,(const char*)v_mer_request_ccy.arr);	
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csMerRequestCcy);		
/*DEBUGLOG(("process_client_txn_hist v_mer_request_ccy = [%s]\n", v_mer_request_ccy.arr));*/		
		}		
		else		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");
/* v_bank_name	*/		
		if(ind_bank_name >= 0)		
		{		
			v_bank_name.arr[v_bank_name.len] = '\0';		
			strcpy(csBankName,(const char*)v_bank_name.arr);		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csBankName);		
/*DEBUGLOG(("process_client_txn_hist v_bank_name = [%s]\n", v_bank_name.arr));*/		
		}		
		else		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");		
/* v_ec_channel	*/		
		if(ind_ec_channel >= 0)		
		{		
			v_ec_channel.arr[v_ec_channel.len] = '\0';		
			strcpy(csEcChannel,(const char*)v_ec_channel.arr);		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csEcChannel);		
/*DEBUGLOG(("process_client_txn_hist v_ec_channel = [%s]\n", v_ec_channel.arr));*/		
		}		
		else		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");
/*	v_consumer_payable_amt	*/		
	if (ind_consumer_payable_amt >= 0)		
	{		
		dConsumerPayableAmt = v_consumer_payable_amt;		
		format_commas(dConsumerPayableAmt, csTmp);		
		/*fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%.2f</Data></Cell>\n",dConsumerPayableAmt);*/		
		fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%s</Data></Cell>\n",csTmp);		
/*DEBUGLOG(("process_client_txn_hist v_consumer_payable_amt = [%f]\n",v_consumer_payable_amt));*/		
	}		
	else		
		fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">0</Data></Cell>\n");		
/* v_consumer_payable_ccy	*/		
		if(ind_consumer_payable_ccy >= 0)		
		{		
			v_consumer_payable_ccy.arr[v_consumer_payable_ccy.len] = '\0';		
			strcpy(csConsumerPayableCcy,(const char*)v_consumer_payable_ccy.arr);		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csConsumerPayableCcy);		
/*DEBUGLOG(("process_client_txn_hist v_consumer_payable_ccy = [%s]\n", v_consumer_payable_ccy.arr));*/		
		}		
		else		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");			
/*	v_unique_amount_markup	*/		
		if (ind_unique_amount_markup >= 0)		
		{		
			dUniqueAmountMarkup = v_unique_amount_markup;		
			format_commas(dUniqueAmountMarkup, csTmp);		
			/*fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%.2f</Data></Cell>\n",dUniqueAmountMarkup);*/		
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%s</Data></Cell>\n",csTmp);		
/*DEBUGLOG(("process_client_txn_hist v_unique_amount_markup = [%f]\n",v_unique_amount_markup));*/		
		}		
		else		
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">0</Data></Cell>\n");		
/*	v_consumer_paid_amt	*/		
		if (ind_consumer_paid_amt >= 0)		
		{		
			dConsumerPaidAmt = v_consumer_paid_amt;		
			format_commas(dConsumerPaidAmt, csTmp);		
			/*fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%.2f</Data></Cell>\n",dConsumerPaidAmt);*/		
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%s</Data></Cell>\n",csTmp);		
/*DEBUGLOG(("process_client_txn_hist v_consumer_paid_amt = [%f]\n",v_consumer_paid_amt));*/		
		}		
		else		
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">0</Data></Cell>\n");		
/* v_consumer_paid_ccy	*/		
		if(ind_consumer_paid_ccy >= 0)		
		{		
			v_consumer_paid_ccy.arr[v_consumer_paid_ccy.len] = '\0';		
			strcpy(csConsumerPaidCcy,(const char*)v_consumer_paid_ccy.arr);		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csConsumerPaidCcy);		
/*DEBUGLOG(("process_client_txn_hist v_consumer_paid_ccy = [%s]\n", v_consumer_paid_ccy.arr));*/		
		}		
		else		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");		
/*	v_mer_received_amt	*/		
		if (ind_mer_received_amt >= 0)		
		{		
			dMerReceivedAmt = v_mer_received_amt;		
			format_commas(dMerReceivedAmt, csTmp);		
			/*fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%.2f</Data></Cell>\n",dMerReceivedAmt);*/		
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%s</Data></Cell>\n",csTmp);		
/*DEBUGLOG(("process_client_txn_hist v_mer_received_amt = [%f]\n",v_mer_received_amt));*/		
		}		
		else		
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">0</Data></Cell>\n");		
/* v_mer_received_ccy	*/		
		if(ind_mer_received_ccy >= 0)		
		{		
			v_mer_received_ccy.arr[v_mer_received_ccy.len] = '\0';		
			strcpy(csMerReceivedCcy,(const char*)v_mer_received_ccy.arr);		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csMerReceivedCcy);		
/*DEBUGLOG(("process_client_txn_hist v_mer_received_ccy = [%s]\n", v_mer_received_ccy.arr));*/		
		}		
		else		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");		
/*	v_transaction_fee	*/		
		if (ind_transaction_fee >= 0)		
		{		
			dTransactionFee = v_transaction_fee;		
			format_commas(dTransactionFee, csTmp);		
			/*fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%.2f</Data></Cell>\n",dTransactionFee);*/		
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%s</Data></Cell>\n",csTmp);		
/*DEBUGLOG(("process_client_txn_hist v_transaction_fee = [%f]\n",v_transaction_fee));*/		
		}		
		else		
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">0</Data></Cell>\n");		
/* v_transaction_fee_ccy	*/		
		if(ind_transaction_fee_ccy >= 0)		
		{		
			v_transaction_fee_ccy.arr[v_transaction_fee_ccy.len] = '\0';		
			strcpy(csTransactionFeeCcy,(const char*)v_transaction_fee_ccy.arr);		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csTransactionFeeCcy);		
/*DEBUGLOG(("process_client_txn_hist v_transaction_fee_ccy = [%s]\n", v_transaction_fee_ccy.arr));*/		
		}		
		else		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");		
/*	v_mer_received_net_amt	*/		
		if (ind_mer_received_net_amt >= 0)		
		{		
			dMerReceivedNetAmt = v_mer_received_net_amt;		
			format_commas(dMerReceivedNetAmt, csTmp);		
			/*fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%.2f</Data></Cell>\n",dMerReceivedNetAmt);*/		
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%s</Data></Cell>\n",csTmp);		
/*DEBUGLOG(("process_client_txn_hist v_mer_received_net_amt = [%f]\n",v_mer_received_net_amt));*/		
		}		
		else		
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">0</Data></Cell>\n");		
/* v_mer_received_net_ccy	*/		
		if(ind_mer_received_net_ccy >= 0)		
		{		
			v_mer_received_net_ccy.arr[v_mer_received_net_ccy.len] = '\0';		
			strcpy(csMerReceivedNetCcy,(const char*)v_mer_received_net_ccy.arr);		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csMerReceivedNetCcy);		
/*DEBUGLOG(("process_client_txn_hist v_mer_received_net_ccy = [%s]\n", v_mer_received_net_ccy.arr));*/		
		}		
		else		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");		
/*	v_mer_payable_amt	*/		
		if (ind_mer_payable_amt >= 0)		
		{		
			dMerPayableAmt = v_mer_payable_amt;		
			format_commas(dMerPayableAmt, csTmp);		
			/*fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%.2f</Data></Cell>\n",dMerPayableAmt);*/		
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%s</Data></Cell>\n",csTmp);		
/*DEBUGLOG(("process_client_txn_hist v_mer_payable_amt = [%f]\n",v_mer_payable_amt));*/		
		}		
		else		
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">0</Data></Cell>\n");		
/* v_mer_payable_ccy	*/		
		if(ind_mer_payable_ccy >= 0)		
		{		
			v_mer_payable_ccy.arr[v_mer_payable_ccy.len] = '\0';		
			strcpy(csMerPayableCcy,(const char*)v_mer_payable_ccy.arr);		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csMerPayableCcy);		
/*DEBUGLOG(("process_client_txn_hist v_mer_payable_ccy = [%s]\n", v_mer_payable_ccy.arr));*/		
		}		
		else		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");		
/*	v_consumer_received_amt	*/		
		if (ind_consumer_received_amt >= 0)		
		{		
			dConsumerReceivedAmt = v_consumer_received_amt;		
			format_commas(dConsumerReceivedAmt, csTmp);		
			/*fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%.2f</Data></Cell>\n",dConsumerReceivedAmt);*/		
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%s</Data></Cell>\n",csTmp);		
/*DEBUGLOG(("process_client_txn_hist v_consumer_received_amt = [%f]\n",v_consumer_received_amt));*/		
		}		
		else		
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">0</Data></Cell>\n");		
/* v_consumer_received_ccy	*/		
		if(ind_consumer_received_ccy >= 0)		
		{		
			v_consumer_received_ccy.arr[v_consumer_received_ccy.len] = '\0';		
			strcpy(csConsumerReceivedCcy,(const char*)v_consumer_received_ccy.arr);		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csConsumerReceivedCcy);		
/*DEBUGLOG(("process_client_txn_hist v_consumer_received_ccy = [%s]\n", v_consumer_received_ccy.arr));*/		
		}		
		else		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");		
/*	v_mer_paid_amt	*/		
		if (ind_mer_paid_amt >= 0)		
		{		
			dMerPaidAmt = v_mer_paid_amt;		
			format_commas(dMerPaidAmt, csTmp);		
			/*fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%.2f</Data></Cell>\n",dMerPaidAmt);*/		
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%s</Data></Cell>\n",csTmp);		
/*DEBUGLOG(("process_client_txn_hist v_mer_paid_amt = [%f]\n",v_mer_paid_amt));*/		
		}		
		else		
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">0</Data></Cell>\n");		
/* v_mer_paid_ccy	*/		
		if(ind_mer_paid_ccy >= 0)		
		{		
			v_mer_paid_ccy.arr[v_mer_paid_ccy.len] = '\0';		
			strcpy(csMerPaidCcy,(const char*)v_mer_paid_ccy.arr);		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csMerPaidCcy);		
/*DEBUGLOG(("process_client_txn_hist v_mer_paid_ccy = [%s]\n", v_mer_paid_ccy.arr));*/		
		}		
		else		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");		
/*	v_mer_paid_total_amt	*/		
		if (ind_mer_paid_total_amt >= 0)		
		{		
			dMerPaidTotalAmt = v_mer_paid_total_amt;		
			format_commas(dMerPaidTotalAmt, csTmp);		
			/*fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%.2f</Data></Cell>\n",dMerPaidTotalAmt);*/		
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%s</Data></Cell>\n",csTmp);		
/*DEBUGLOG(("process_client_txn_hist v_mer_paid_total_amt = [%f]\n",v_mer_paid_total_amt));*/		
		}		
		else		
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">0</Data></Cell>\n");		
/* v_mer_paid_total_ccy	*/		
		if(ind_mer_paid_total_ccy >= 0)		
		{		
			v_mer_paid_total_ccy.arr[v_mer_paid_total_ccy.len] = '\0';		
			strcpy(csMerPaidTotalCcy,(const char*)v_mer_paid_total_ccy.arr);		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csMerPaidTotalCcy);		
/*DEBUGLOG(("process_client_txn_hist v_mer_paid_total_ccy = [%s]\n", v_mer_paid_total_ccy.arr));*/		
		}		
		else		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");		
/*	v_mer_receivable_amt	*/		
		if (ind_mer_receivable_amt >= 0)		
		{		
			dMerReceivableAmt = v_mer_receivable_amt;		
			format_commas(dMerReceivableAmt, csTmp);		
			/*fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%.2f</Data></Cell>\n",dMerReceivableAmt);*/		
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%s</Data></Cell>\n",csTmp);		
/*DEBUGLOG(("process_client_txn_hist v_mer_receivable_amt = [%f]\n",v_mer_receivable_amt));*/		
		}		
		else		
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">0</Data></Cell>\n");		
/* v_mer_receivable_ccy	*/		
		if(ind_mer_receivable_ccy >= 0)		
		{		
			v_mer_receivable_ccy.arr[v_mer_receivable_ccy.len] = '\0';		
			strcpy(csMerReceivableCcy,(const char*)v_mer_receivable_ccy.arr);		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csMerReceivableCcy);		
/*DEBUGLOG(("process_client_txn_hist v_mer_receivable_ccy = [%s]\n", v_mer_receivable_ccy.arr));*/		
		}		
		else		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");		
/*	v_mer_receivable_net_amt	*/		
		if (ind_mer_receivable_net_amt >= 0)		
		{		
			dMerReceivableNetAmt = v_mer_receivable_net_amt;		
			format_commas(dMerReceivableNetAmt, csTmp);		
			/*fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%.2f</Data></Cell>\n",dMerReceivableNetAmt);*/		
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%s</Data></Cell>\n",csTmp);		
/*DEBUGLOG(("process_client_txn_hist v_mer_receivable_net_amt = [%f]\n",v_mer_receivable_net_amt));*/		
		}		
		else		
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">0</Data></Cell>\n");		
/* v_mer_receivable_net_ccy	*/		
		if(ind_mer_receivable_net_ccy >= 0)		
		{		
			v_mer_receivable_net_ccy.arr[v_mer_receivable_net_ccy.len] = '\0';		
			strcpy(csMerReceivableNetCcy,(const char*)v_mer_receivable_net_ccy.arr);		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csMerReceivableNetCcy);		
/*DEBUGLOG(("process_client_txn_hist v_mer_receivable_net_ccy = [%s]\n", v_mer_receivable_net_ccy.arr));*/		
		}		
		else		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");		
/*	v_final_mer_received_net_amt	*/		
		if (ind_final_mer_received_net_amt >= 0)		
		{		
			dFinalMerReceivedNetAmt = v_final_mer_received_net_amt;		
			format_commas(dFinalMerReceivedNetAmt, csTmp);		
			/*fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%.2f</Data></Cell>\n",dFinalMerReceivedNetAmt);*/		
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%s</Data></Cell>\n",csTmp);		
/*DEBUGLOG(("process_client_txn_hist v_final_mer_received_net_amt = [%f]\n",v_final_mer_received_net_amt));*/		
		}
		else
			fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">0</Data></Cell>\n");
/* v_final_mer_received_net_amt_ccy	*/		
		if(ind_final_mer_received_net_amt_ccy >= 0)		
		{		
			v_final_mer_received_net_amt_ccy.arr[v_final_mer_received_net_amt_ccy.len] = '\0';		
			strcpy(csFinalMerReceivedNetAmtCcy,(const char*)v_final_mer_received_net_amt_ccy.arr);		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csFinalMerReceivedNetAmtCcy);		
/*DEBUGLOG(("process_client_txn_hist v_final_mer_received_net_amt_ccy = [%s]\n", v_final_mer_received_net_amt_ccy.arr));*/		
		}		
		else		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");		
/* v_beneficiary_bank_name	*/		
		if(ind_beneficiary_bank_name >= 0)		
		{		
			v_beneficiary_bank_name.arr[v_beneficiary_bank_name.len] = '\0';		
			strcpy(csBeneficiaryBankName,(const char*)v_beneficiary_bank_name.arr);		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csBeneficiaryBankName);		
/*DEBUGLOG(("process_client_txn_hist v_beneficiary_bank_name = [%s]\n", v_beneficiary_bank_name.arr));*/		
		}		
		else		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");		
/* v_beneficiary_bank_ac_num	*/		
		if(ind_beneficiary_bank_ac_num >= 0)		
		{		
			v_beneficiary_bank_ac_num.arr[v_beneficiary_bank_ac_num.len] = '\0';		
			strcpy(csBeneficiaryBankAcNum,(const char*)v_beneficiary_bank_ac_num.arr);		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csBeneficiaryBankAcNum);		
/*DEBUGLOG(("process_client_txn_hist v_beneficiary_bank_ac_num = [%s]\n", v_beneficiary_bank_ac_num.arr));*/		
		}		
		else		
			fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");		
			

		fprintf(fp,"</Row>\n");

	} while (PD_TRUE);
	
	/* EXEC SQL CLOSE c_cursor_getclttxnhist; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 44;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )338;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto clttxnhist_sql_error;
}


		
	return iRet;

clttxnhist_sql_error:
DEBUGLOG(("extract_client_txn_hist_daily_rpt:process_clttxnhist code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getclttxnhist; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 44;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )353;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	/* EXEC SQL ROLLBACK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 44;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )368;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



	return PD_ERR;
}

int process_single_acct(const char* csTxnDate,
						const char* csClientId)
{

	int     iRet = SUCCESS;
	char    csUploadFilename[PD_UPLOAD_FILENAME_LEN+1];
	char    csUploadFullFile[PD_PATH_LEN+1];
	char    csTmpCmd[PD_TMP_BUF_LEN+1];
	char    csYear[PD_YYYY_LEN+1];
	char    csYearMth[PD_YYYYMM_LEN+1];
	FILE    *fp;
	hash_t* hClientTxnHist;
	hClientTxnHist = (hash_t*) malloc (sizeof(hash_t));


/* Extract report data */
		hash_init(hClientTxnHist,0);
		PutField_CString(hClientTxnHist,"report_code",PD_CLIENT_TXN_HIST_REPORT_CODE);

/* Table Field  disabled*/
		PutField_Int(hClientTxnHist,"disabled",PD_REC_ENABLED);

/* Addition field Report Data */
		if (strlen(csTxnDate) > 0)
		{
			PutField_CString(hClientTxnHist,"report_date",csTxnDate);
		}

/* Only Generate report one time*/
/* Do not generate report again if generated report record exist in table */
		DBObjPtr = CreateObj(DBPtr,"DBPregenDailyReport","ChkCthExist");
		if ((*DBObjPtr)(hClientTxnHist) != PD_OK)
		{
DEBUGLOG(("process_single_acct:ClientId[%s] TxnDate[%s] Report has generated already\n", csClientId, csTxnDate));
			return FAILURE;		
		}


		/* Skip the record if ClientID contains space */ 
		if (chkSpInClientID(csClientId) == PD_ERR){
DEBUGLOG(("process_single_acct:unable to get ClientID contain space [%s]\n",csClientId));
			return FAILURE;
		}

		sprintf(csUploadFilename, 
				"%s_%s_%s.zip",
				PD_FILE_PREFIX,
				csClientId,
				csTxnDate);
		

		
		

/* Addition field Filename */
		PutField_CString(hClientTxnHist,"filename",csUploadFilename);
DEBUGLOG(("process_single_acct:filename[%s]\n",csUploadFilename));

/* Addition field Update_user */
		PutField_CString(hClientTxnHist,"user",PD_UPDATE_USER);

/* Extract year and year month */
		strcpy(csYear, getYYYY(csTxnDate));

		strcpy(csYearMth, getYYYYMM(csTxnDate));


/* Check and make current balance report folder */
		if (mkFullPathDir(csTxnDate) != PD_OK)
		{
DEBUGLOG(("process_single_acct:unable to create path [%s %s %s]\n",csYear, csYearMth, csTxnDate));
			return FAILURE;
		}

		sprintf(csUploadFullFile,"%s/%s/%s/%s/%s/%s_%s_%s.xls",  
				getenv("PREGEN_RPT_HOME"), PD_FILE_PREFIX, csYear, csYearMth, csTxnDate, PD_FILE_PREFIX, csClientId,
				csTxnDate);
		
		
		        
		fp = fopen(csUploadFullFile,"w");
		if (fp == NULL) {
DEBUGLOG(("process_single_acct:unable to open [%s]\n",csUploadFullFile));
			return FAILURE;
		}
/* create xml header */
		fprintf(fp,"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
		fprintf(fp,"<?mso-application progid=\"Excel.Sheet\"?>\n");
		fprintf(fp,"<Workbook xmlns=\"urn:schemas-microsoft-com:office:spreadsheet\"\n");
		fprintf(fp,"\txmlns:o=\"urn:schemas-microsoft-com:office:office\"\n");
		fprintf(fp,"\t xmlns:x=\"urn:schemas-microsoft-com:office:excel\"\n");
		fprintf(fp,"\t xmlns:ss=\"urn:schemas-microsoft-com:office:spreadsheet\"\n");
		fprintf(fp,"\t xmlns:html=\"http://www.w3.org/TR/REC-html40\">\n");
		fprintf(fp,"<Styles>\n");
		fprintf(fp,"\t<Style ss:ID=\"shd\">\n");
		fprintf(fp,"\t\t<ss:Font ss:Bold=\"1\"/>\n");
		fprintf(fp,"\t\t<Alignment ss:Horizontal=\"Center\" ss:Vertical=\"Center\"/>\n");
		fprintf(fp,"\t</Style>\n");
		fprintf(fp,"\t<Style ss:ID=\"sdt\">\n");
		fprintf(fp,"\t\t<NumberFormat ss:Format=\"yyyy-mm-dd hh:mm:ss\"/>\n");
		fprintf(fp,"\t</Style>\n");
		fprintf(fp,"</Styles>\n");
		fprintf(fp,"<Worksheet ss:Name=\"Client Transaction History\">\n");
		fprintf(fp,"<Table>\n");


		fprintf(fp,"<Row>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Transaction ID</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Country</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Service</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Short Name</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Transaction Type</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Reference</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Holdback Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Holdback Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Status</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Callback Status</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Create Timestamp</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Approval Timestamp</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Remark</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Request Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Request Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Bank Name</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">EC Channel</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Consumer Payable Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Consumer Payable Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Unique Amount Markup</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Consumer Paid Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Consumer Paid Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Received Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Received Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Transaction Fee</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Transaction Fee Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Received Net Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Received Net Amount Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Payable Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Payable Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Consumer Received Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Consumer Received Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Paid Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Paid Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Paid Total Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Paid Total Amount Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Receivable Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Receivable Amount Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Receivable Net Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Receivable Net Amount Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Wire Net Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Wire Net Amount Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Beneficiary Bank Name</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Beneficiary Bank Account Number</Data></Cell>\n");
		fprintf(fp,"</Row>\n");




/* process Client Txn History data */
		if(iRet==PD_OK){
			if (process_clttxnhist(csClientId,
						csTxnDate,
						fp
				) == PD_OK){
			}
			else{
				iRet=PD_ERR;
DEBUGLOG(("process_clttxnhist failed!!!!!!\n"));
			}
		}
		
/* create deposit summary header */

		fprintf(fp,"<Row>\n");
		fprintf(fp,"</Row>\n");
		fprintf(fp,"<Row>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Deposit Summary</Data></Cell>\n");
		fprintf(fp,"</Row>\n");


		fprintf(fp,"<Row>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Service</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Status</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Transaction Amount Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Transaction Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Consumer Paid Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Consumer Paid Amount</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Transaction Count </Data></Cell>\n");
		
		fprintf(fp,"</Row>\n");
		

/* process deposit summary data */
		if(iRet==PD_OK){
			if (process_depositSumm(csClientId,
						csTxnDate,
						fp
				) == PD_OK){
			}
			else{
				iRet=PD_ERR;
DEBUGLOG(("process_depositSumm failed!!!!!!\n"));
			}
		}
		
		if(iRet==PD_OK){
/* Addition field Status */
			PutField_Char(hClientTxnHist,"status",PD_PREGEN_RPT_COMPLETED); 
		}
		else{
/* Addition field Status */
			PutField_Char(hClientTxnHist,"status",PD_PREGEN_RPT_FAILURE);
		}
		
		
		
		

/* create xml footer */
		fprintf(fp, "</Table>\n");
		fprintf(fp, "</Worksheet>\n");
		fprintf(fp, "</Workbook>\n");

		fclose(fp);

/* zip the report */

		sprintf(csTmpCmd, 
				"zip_pregenrpt.sh %s %s %s %s %s %s %s 1>/dev/null",
				csTxnDate,
				csClientId,
				PD_UNUSED,
				PD_UNUSED,
				PD_UNUSED,
				getenv("PREGEN_RPT_HOME"),
				PD_FILE_PREFIX);
		
		if (system(csTmpCmd) == PD_ERR)
		{
DEBUGLOG(("extract_client_txn_hist_daily_rpt::zip: fail %s\n", csTmpCmd));
		}
		else
		{
DEBUGLOG(("extract_client_txn_hist_daily_rpt::zip: success %s\n", csTmpCmd));
		}


/* ChkExist Insert/update pregen_daily_report */
		DBObjPtr = CreateObj(DBPtr,"DBPregenDailyReport","ChkCthExist");
		if ((*DBObjPtr)(hClientTxnHist) != PD_OK) 
		{
			DBObjPtr = CreateObj(DBPtr,"DBPregenDailyReport","UpdateStatus");
			if ((*DBObjPtr)(hClientTxnHist) != PD_OK) 
				iRet = PD_ERR;
		}
		else
		{
			DBObjPtr = CreateObj(DBPtr,"DBPregenDailyReport","Add");
			if ((*DBObjPtr)(hClientTxnHist) != PD_OK) 
				iRet = PD_ERR;
		}

		if (iRet == PD_OK)
		{
DEBUGLOG(("extract_client_txn_hist_daily_rpt::commit: ClientId[%s] TxnDate[%s]\n", csClientId,csTxnDate));
			TxnCommit();
		}



		hash_destroy(hClientTxnHist);
		
	if (hClientTxnHist)
	{
		FREE_ME(hClientTxnHist);
	}

	return iRet;
}


int mkFullPathDir(const char * csYearMthDy) 
{
	int  iRet = SUCCESS;
	char csTmpCmd[PD_TMP_BUF_LEN+1];

	
	sprintf(csTmpCmd, 
			"mkdir_pregenrpt_tree.sh %s %s %s 1> /dev/null",		
			csYearMthDy, getenv("PREGEN_RPT_HOME"),PD_FILE_PREFIX);
	
	if (system(csTmpCmd) == PD_ERR)
	{
		iRet = PD_ERR;
	}

	return iRet;
}

char* getYYYY(const char* csTxnDate)
{

	strncpy(csTmpYYYY, csTxnDate, PD_YYYY_LEN);
	csTmpYYYY[PD_YYYY_LEN] = '\0';

	return csTmpYYYY;
}

char* getYYYYMM(const char* csTxnDate)
{

	strncpy(csTmpYYYYMM, csTxnDate, PD_YYYYMM_LEN);
	csTmpYYYYMM[PD_YYYYMM_LEN] = '\0';

	return csTmpYYYYMM;
}



int chkSpInClientID(const char* csClientId)
{
	int iCnt;

	for (iCnt = 0;iCnt < strlen(csClientId);iCnt++)
		if (csClientId[iCnt] == 32)
			return PD_ERR;

	return SUCCESS;
}


void format_commas(double dInNum, char* csOutNum)
{
	char csTmpNum[PD_TMP_BUF_LEN+1];
	int  iCnt;
	int  iCnt2;

	sprintf(csTmpNum, "%.2f", dInNum);

	if (strlen(csTmpNum) <= 6)
	{
		strcpy (csOutNum, csTmpNum);

		return;
	}
	
	/* Reverse order */
	iCnt2 = 0;
	for (iCnt = strlen(csTmpNum) - 1; iCnt >= 0; iCnt--)
	{
		csOutNum[iCnt2] = csTmpNum[iCnt];
		iCnt2++;
	}
	csOutNum[iCnt2] = '\0';

	csTmpNum[0] = csOutNum[0];
	csTmpNum[1] = csOutNum[1];
	csTmpNum[2] = csOutNum[2];
	iCnt2=3;
	for (iCnt = 3; iCnt < strlen(csOutNum); iCnt++)
	{
		csTmpNum[iCnt2] = csOutNum[iCnt];
		iCnt2++;
		if (((iCnt+1) % 3 == 0) && (iCnt+1 < strlen(csOutNum)))
		{
			csTmpNum[iCnt2] = ',';
			iCnt2++;
		}
	}
	csTmpNum[iCnt2] = '\0';

	/* Reverse order */
	iCnt2 = 0;
	for (iCnt = strlen(csTmpNum) - 1; iCnt >= 0; iCnt--)
	{
		csOutNum[iCnt2] = csTmpNum[iCnt];
		iCnt2++;
	}
	csOutNum[iCnt2] = '\0';
	
	return;
}

int parse_arg(int argc,char **argv)
{
	char c;
	strcpy(csDate,"");
	strcpy(csInClientId,"");
	
	
	while ((c = getopt(argc,argv,"d:c:")) != EOF) {
		switch (c) {
			case 'd':
				strcpy(csDate, optarg);
				break;
			case 'c':
				strcpy(csInClientId, optarg);
				break;
		}
	}

	


	if (!strcmp(csDate,""))
		return FAILURE;


	if (argc > 3) {
DEBUGLOG(("parse_arg: csDate csInClientId[%s %s]\n",csDate, csInClientId));	
		if (!strcmp(csInClientId,""))
			return FAILURE;
	}


	return SUCCESS;
}

