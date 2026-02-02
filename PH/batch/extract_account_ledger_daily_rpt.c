
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
           char  filnam[36];
};
static struct sqlcxp sqlfpn =
{
    35,
    "extract_account_ledger_daily_rpt.pc"
};


static unsigned int sqlctx = 167818821;


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
   unsigned char  *sqhstv[17];
   unsigned long  sqhstl[17];
            int   sqhsts[17];
            short *sqindv[17];
            int   sqinds[17];
   unsigned long  sqharm[17];
   unsigned long  *sqharc[17];
   unsigned short  sqadto[17];
   unsigned short  sqtdso[17];
} sqlstm = {12,17};

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
"SELECT MB_MERCHANT_ID , MB_COUNTRY , MB_CCY_ID , MB_SERVICE_CODE FROM MERCH\
ANT_BAL_ACCT ORDER BY MB_MERCHANT_ID , MB_COUNTRY , MB_CCY_ID , MB_SERVICE_CO\
DE            ";

 static char *sq0003 = 
"SELECT TXN_ID AS TXN_ID , TXN_CODE AS TXN_CODE , TXN_CODE_DESC AS TXN_DESC \
, OPEN_BAL AS OPEN_BALANCE , AMT_TYPE AS AMOUNT_TYPE , AMOUNT AS AMOUNT , BAL\
 AS BALANCE , TXN_ELEMENT_TYPE AS ELEMENT_TYPE , TXN_ELEMENT_TYPE_DESC AS TXN\
_ELEMENT_TYPE_DESC , EXEC_SEQ AS EXEC_SEQ , TXN_CCY AS TXN_CCY , APPROVAL_DAT\
E AS APPROVAL_DATE , CASE WHEN AMT_TYPE = 'CR' THEN AMOUNT ELSE 0 END AS CRED\
IT , CASE WHEN AMT_TYPE = 'DR' THEN AMOUNT ELSE 0 END AS DEBIT , APPROVAL_TIM\
ESTAMP , TO_CHAR ( APPROVAL_TIMESTAMP , 'YYYY-MM-DD HH24:MI:SS' ) AS FORMAT_T\
IMESTAMP , MERCHANT_REF AS MERCHANT_REF FROM TABLE ( LEDGER_PKG . F_CB_LEDGER\
 ( to_timestamp ( to_date ( :b0 , 'YYYYMMDD HH24:MI' ) ) , to_timestamp ( to_\
date ( :b0 , 'YYYYMMDD HH24:MI' ) + 1 ) , :b2 , :b3 , :b4 , :b5 ) ) ORDER BY \
APPROVAL_TIMESTAMP , EXEC_SEQ            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,166,0,9,231,0,2049,0,0,0,1,0,
20,0,0,1,0,0,13,234,0,0,4,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
51,0,0,1,0,0,15,432,0,0,0,0,0,1,0,
66,0,0,1,0,0,15,445,0,0,0,0,0,1,0,
81,0,0,2,0,0,32,446,0,0,0,0,0,1,0,
96,0,0,3,809,0,9,811,0,2049,6,6,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,
135,0,0,3,0,0,13,815,0,0,17,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,
4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,
218,0,0,3,0,0,15,1001,0,0,0,0,0,1,0,
233,0,0,3,0,0,15,1009,0,0,0,0,0,1,0,
248,0,0,4,0,0,32,1010,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                            Change Date     Change By
------------------------------------------    ------------    --------------
Init Version                                  2018/08/09      [TNY]
Add TxnBalanceLog validation, email alert     2020/03/15      [MIC]
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
#include "internal.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define PD_CURR_BALANCE	   'C'
#define PD_REC_ENABLED     0


#define PD_EML_FUNCT_PREGEN_RPT		"ACCT_LEDGER_RPT"
#define PD_ALERT_DATETIME_FORMAT        "%d-%b-%Y %H:%M:%S"




#define PD_RPT_GEN_SUCCESS			0			
#define PD_RPT_GEN_FAILURE			1

#define PD_SEND_EMAIL				2


OBJPTR(DB);
OBJPTR(BO);

char csDate[PD_DATE_LEN + 1];
char csInMerchantId[PD_MERCHANT_ID_LEN+1];
char csInCcyId[PD_COUNTRY_CODE_LEN+1];
char csInCountryCode[PD_CCY_ID_LEN+1];
char csInServiceCode[PD_SERVICE_CODE_LEN+1];

char csTmpYYYY[PD_YYYY_LEN+1];
char csTmpYYYYMM[PD_YYYYMM_LEN+1];

	
static char cDebug = 'Y';

int parse_arg(int argc,char **argv);

int process_data(const char* csTxnDate); 

int process_single_acct(const char* csTxnDate,
                        const char* csMerchantId,
                        const char* csCcyId,
                        const char* csCountryCode,
                        const char* csServiceCode);

int process_cbledger(const char* csMerchantId,
                     const char* csCcyId,
                     const char* csCountryCode,
                     const char* csServiceCode,
                     const char* csReportDate,
                     FILE *fp);

int mkFullPathDir(const char* csYearMthDy);

char* getYYYY(const char* csTxnDate);

char* getYYYYMM(const char* csTxnDate);

int chkSpInMID(const char* csMerchantId);

void format_commas(double dInNum, char* csOutNum);

int CreateAlertEmailTpl(hash_t *hData);

int batch_init(int argc, char* argv[])
{
	if (argc < 2) {
		printf("usage: -d Date\n");

		return FAILURE;
	}
	else if (argc > 3 && argc < 10) {
		printf("usage: -d Date"
		       " -m Merchant_ID"
		       " -o Country_code"
		       " -c CCY_ID"
		       " -s Service_code\n"
		);

		return FAILURE;
	}
	else
  		return SUCCESS;
}

int batch_proc(int argc, char* argv[])
{
	int iRet;
	int	iDtlRet;

	hash_t  *hData = NULL;
	hData = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hData,0);

	iRet = parse_arg(argc,argv);
	
	if (iRet != SUCCESS) {
		if (argc < 2)
			printf("usage: -d Date\n");
		else if (argc > 3 && argc < 10) {
			printf("usage: -d Date"
			       " -m Merchant_ID"
			       " -o Country_code"
			       " -c CCY_ID"
			       " -s Service_code\n"
			);
		}

		return (iRet);
	}

/* Check Balance completed */
	DBObjPtr = CreateObj(DBPtr,"DBTxnBalanceLog","IsCompleted");
	if ((unsigned long)(*DBObjPtr)(csDate, PD_TYPE_MERCHANT) == PD_TRUE) {
DEBUGLOG(("batch_proc:TxnBalanceLog.IsCompleted is TRUE\n"));
		if (argc == 3)
			iRet = process_data(csDate);
		else
			iRet = process_single_acct(csDate,csInMerchantId,csInCcyId,
									   csInCountryCode,csInServiceCode);
									   
		if(iRet == PD_OK)
		{
DEBUGLOG(("batch_proc:[Success] Account Ledger Daily Report Generated\n"));
			printf("%d\n", PD_RPT_GEN_SUCCESS);
		}
		else
		{
DEBUGLOG(("batch_proc:[Failure] Account Ledger Daily Report Not Generated\n"));
			printf("%d\n", PD_RPT_GEN_FAILURE);
		}
	}
/* Check Balance not yet completed */
	else {
DEBUGLOG(("batch_proc:TxnBalanceLog.IsCompleted is FALSE\n"));
		// Alert Email Funct
		PutField_CString(hData, "funct", PD_EML_FUNCT_PREGEN_RPT);
DEBUGLOG(("batch_proc:[Send Email] Balance Validation Fail: Account Ledger Daily Report Not Generated\n"));
		printf("%d\n", PD_SEND_EMAIL);

		iDtlRet = CreateAlertEmailTpl(hData);
		if (iDtlRet != PD_OK) {
			iRet = FAILURE;
		}

		hash_destroy(hData);
		FREE_ME(hData);
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
	char    csMerchantId[PD_MERCHANT_ID_LEN+1];
	char    csCountryCode[PD_COUNTRY_CODE_LEN+1];
	char    csCcyId[PD_CCY_ID_LEN+1];
	char    csServiceCode[PD_SERVICE_CODE_LEN+1];
	char    csUploadFilename[PD_UPLOAD_FILENAME_LEN+1];
	char    csUploadFullFile[PD_PATH_LEN+1];
	char    csTmp[PD_TMP_BUF_LEN+1];
	char    csTmpCmd[PD_TMP_BUF_LEN+1];
	char    csYear[PD_YYYY_LEN+1];
	char    csYearMth[PD_YYYYMM_LEN+1];
	FILE    *fp;
	hash_t* hAccBal;

	hAccBal = (hash_t*) malloc (sizeof(hash_t));

	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

  
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar v_merchant_id[PD_MERCHANT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar v_service_code[PD_SERVICE_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		/* varchar v_country_code[PD_COUNTRY_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country_code;

		/* varchar v_ccy_id[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ccy_id;

    
		short   ind_merchant_id  = -1;
		short   ind_service_code = -1;
		short   ind_country_code = -1;
		short   ind_ccy_id       = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	/* EXEC SQL DECLARE c_cursor_getMerBalAcct CURSOR FOR
		SELECT MB_MERCHANT_ID,
		       MB_COUNTRY,
		       MB_CCY_ID,
		       MB_SERVICE_CODE
		FROM MERCHANT_BAL_ACCT
		ORDER BY MB_MERCHANT_ID,MB_COUNTRY,MB_CCY_ID,MB_SERVICE_CODE
		; */ 


	/* EXEC SQL OPEN c_cursor_getMerBalAcct; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 0;
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
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto sql_error;
}



	do {
		/* EXEC SQL FETCH c_cursor_getMerBalAcct
		INTO :v_merchant_id:ind_merchant_id,
		     :v_country_code:ind_country_code,
		     :v_ccy_id:ind_ccy_id,
		     :v_service_code:ind_service_code; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )20;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_merchant_id;
  sqlstm.sqhstl[0] = (unsigned long )18;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_merchant_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_country_code;
  sqlstm.sqhstl[1] = (unsigned long )5;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_country_code;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_ccy_id;
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_ccy_id;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_service_code;
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_service_code;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto sql_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

/* Extract report data */
		hash_init(hAccBal,0);
 
/* Table Field merchant_id */
		if (ind_merchant_id >= 0)
		{
			sprintf(csTmp,"%.*s",v_merchant_id.len,v_merchant_id.arr);
			strcpy(csMerchantId, csTmp); 
			PutField_CString(hAccBal,"merchant_id",csTmp);
		}
  
/* Table Field country */
		if (ind_country_code >= 0)
		{
			sprintf(csTmp,"%.*s",v_country_code.len,v_country_code.arr);
			strcpy(csCountryCode, csTmp);
			PutField_CString(hAccBal,"country",csTmp);
		}

/* Table Field CCY_ID */
		if (ind_ccy_id >= 0)
		{
			sprintf(csTmp,"%.*s",v_ccy_id.len,v_ccy_id.arr);
			strcpy(csCcyId, csTmp);
			PutField_CString(hAccBal,"ccy",csTmp);
		}

/* Table Field service_code */
		if (ind_service_code >= 0)
		{
			sprintf(csTmp,"%.*s",v_service_code.len,v_service_code.arr);
			strcpy(csServiceCode, csTmp);
			PutField_CString(hAccBal,"service_code",csTmp);
		}

/* Table Field ledger_type */
		PutField_Char(hAccBal,"ledger_type",PD_CURR_BALANCE); 

/* Table Field  disabled*/
		PutField_Int(hAccBal,"disabled",PD_REC_ENABLED);

/* Addition field Report Data */
		if (strlen(csTxnDate) > 0)
		{
			PutField_CString(hAccBal,"report_date",csTxnDate);
		}

		/* Skip the record if MID contains space */ 
		if (chkSpInMID(csMerchantId) == PD_ERR)
			continue;

		sprintf(csUploadFilename, 
		        "curr_bal_%s_%s_%s_%s_%s.zip",
		        csMerchantId,
		        csCountryCode,
		        csCcyId,
		        csServiceCode,
		        csTxnDate);

/* Addition field Filename */
		PutField_CString(hAccBal,"filename",csUploadFilename);

/* Addition field Update_user */
		PutField_CString(hAccBal,"user",PD_UPDATE_USER);

/* Extract year and year month */
		strcpy(csYear, getYYYY(csTxnDate));

		strcpy(csYearMth, getYYYYMM(csTxnDate));

/* Check and make current balance report folder */
		if (mkFullPathDir(csTxnDate) != PD_OK)
		{
DEBUGLOG(("process_data:unable to create path [%s %s %s]\n",csYear, csYearMth, csTxnDate));
			return FAILURE;
		}

		sprintf(csUploadFullFile,"%s/%s/%s/%s/curr_bal_%s_%s_%s_%s_%s.xls",  
		        getenv("ALRPT_HOME"), csYear, csYearMth, csTxnDate,
		        csMerchantId, csCountryCode, csCcyId, csServiceCode, 
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
		fprintf(fp,"<Worksheet ss:Name=\"Account Ledger\">\n");
		fprintf(fp,"<Table>\n");
		fprintf(fp,"<Row>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Approval Time Stamp</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Transaction Type</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Sub Transaction Type</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Transaction ID</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Reference</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Currency</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Credit</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Debit</Data></Cell>\n");
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Balance</Data></Cell>\n");
		fprintf(fp,"</Row>\n");

/* process CB Ledger data */
		if (process_cbledger(csMerchantId,
		                     csCcyId,
		                     csCountryCode,
		                     csServiceCode,
		                     csTxnDate,
		                     fp
		    ) == PD_OK){
/* Addition field Status */
			PutField_Char(hAccBal,"status",PD_PREGEN_RPT_COMPLETED); 
		}
		else
		{
/* Addition field Status */
			PutField_Char(hAccBal,"status",PD_PREGEN_RPT_FAILURE);
			iRet=PD_ERR;
DEBUGLOG(("process_cbledger failed!!!!!!\n"));
		}

/* create xml footer */
		fprintf(fp, "</Table>\n");
		fprintf(fp, "</Worksheet>\n");
		fprintf(fp, "</Workbook>\n");

		fclose(fp);

/* zip the report */
		sprintf(csTmpCmd, 
		        "zip_alrpt.sh %s %s %s %s %s 1>/dev/null",
		        csTxnDate,
		        csMerchantId,
		        csCountryCode,
		        csCcyId,
		        csServiceCode);

		if (system(csTmpCmd) == PD_ERR)
		{
DEBUGLOG(("extract_account_ledger_daily_rpt::zip: fail %s\n", csTmpCmd));
		}
		else
		{
DEBUGLOG(("extract_account_ledger_daily_rpt::zip: success %s\n", csTmpCmd));
		}

/* ChkExist Insert/update acct_ldgr_rpt_hist */
		DBObjPtr = CreateObj(DBPtr,"DBAcctLedgerDailyReport","ChkExist");
		if ((*DBObjPtr)(hAccBal) != PD_OK) 
		{
			DBObjPtr = CreateObj(DBPtr,"DBAcctLedgerDailyReport","UpdateStatus");
			if ((*DBObjPtr)(hAccBal) != PD_OK) 
				iRet = PD_ERR;
		}
		else
		{
			DBObjPtr = CreateObj(DBPtr,"DBAcctLedgerDailyReport","Add");
			if ((*DBObjPtr)(hAccBal) != PD_OK) 
				iRet = PD_ERR;
		}

		if (iRet == PD_OK)
		{
DEBUGLOG(("extract_account_ledger_daily_rpt::commit: MerchantId[%s] Country[%s] CcyId[%s] ServiceCode[%s] TxnDate[%s]\n", csMerchantId,csCountryCode,csCcyId,csServiceCode,csTxnDate));
			TxnCommit();
		}

		hash_destroy(hAccBal);

	} while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getMerBalAcct; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )51;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto sql_error;
}



	if (hAccBal)
	{
		FREE_ME(hAccBal);
	}

	return iRet;

sql_error:
DEBUGLOG(("extract_account_ledger_daily_rpt::process_data: error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getMerBalAcct; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )66;
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
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )81;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



	if (hAccBal) 
	{
		hash_destroy(hAccBal);
	}
   	FREE_ME(hAccBal);

	return PD_ERR;
}

int process_single_acct(const char* csTxnDate,
                        const char* csMerchantId,
                        const char* csCcyId,
                        const char* csCountryCode,
                        const char* csServiceCode)
{               
	int     iRet = SUCCESS;
	char    csUploadFilename[PD_UPLOAD_FILENAME_LEN+1];
	char    csUploadFullFile[PD_PATH_LEN+1];
	char    csTmpCmd[PD_TMP_BUF_LEN+1];
	char    csYear[PD_YYYY_LEN+1];
	char    csYearMth[PD_YYYYMM_LEN+1];
	FILE    *fp;
	hash_t* hAccBal;


/* Report data */
	hAccBal = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hAccBal,0);
 
/* Table Field merchant_id */
	if (strlen(csMerchantId) > 0)
	{
		PutField_CString(hAccBal,"merchant_id",csMerchantId);
	}
  
/* Table Field country */
	if (strlen(csCountryCode) > 0)
	{
		PutField_CString(hAccBal,"country",csCountryCode);
	}

/* Table Field CCY_ID */
	if (strlen(csCcyId) > 0)
	{
		PutField_CString(hAccBal,"ccy",csCcyId);
	}

/* Table Field service_code */
	if (strlen(csServiceCode) >= 0)
	{
		PutField_CString(hAccBal,"service_code",csServiceCode);
	}

/* Table Field ledger_type */
	PutField_Char(hAccBal,"ledger_type",PD_CURR_BALANCE); 

/* Addition field Report Data */
	if (strlen(csTxnDate) > 0)
	{
		PutField_CString(hAccBal,"report_date",csTxnDate);
	}

	sprintf(csUploadFilename, 
	        "curr_bal_%s_%s_%s_%s_%s.zip", csMerchantId, csCountryCode,
	        csCcyId, csServiceCode, csTxnDate);

/* Addition field Filename */
	PutField_CString(hAccBal,"filename",csUploadFilename);

/* Addition field Update_user */
	PutField_CString(hAccBal,"user",PD_UPDATE_USER);

/* Extract year and year month */
	strcpy(csYear, getYYYY(csTxnDate));

	strcpy(csYearMth, getYYYYMM(csTxnDate));

/* Check and make current balance report folder */
	if (mkFullPathDir(csTxnDate) != PD_OK)
	{
DEBUGLOG(("process_single_acct:unable to create path [%s]\n", csTxnDate));
		return FAILURE;
	}

	sprintf(csUploadFullFile,"%s/%s/%s/%s/curr_bal_%s_%s_%s_%s_%s.xls",  
	        getenv("ALRPT_HOME"), csYear, csYearMth, csTxnDate,
	        csMerchantId, csCountryCode, csCcyId, csServiceCode, 
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
	fprintf(fp,"<Worksheet ss:Name=\"Account Ledger\">\n");
	fprintf(fp,"<Table>\n");
	fprintf(fp,"<Row>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Approval Time Stamp</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Transaction Type</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Sub Transaction Type</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Transaction ID</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Reference</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Currency</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Credit</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Debit</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Balance</Data></Cell>\n");
	fprintf(fp,"</Row>\n");

/* process CB Ledger data */
	if (process_cbledger(csMerchantId,
	                     csCcyId,
	                     csCountryCode,
	                     csServiceCode,
	                     csTxnDate,
	                     fp
	    ) == PD_OK){
/* Addition field Status */
		PutField_Char(hAccBal,"status",PD_PREGEN_RPT_COMPLETED); 
	}
	else
	{
/* Addition field Status */
		PutField_Char(hAccBal,"status",PD_PREGEN_RPT_FAILURE);
		iRet=PD_ERR;
DEBUGLOG(("process_cbledger failed!!!!!!\n"));
	}

/* create xml footer */
	fprintf(fp, "</Table>\n");
	fprintf(fp, "</Worksheet>\n");
	fprintf(fp, "</Workbook>\n");

	fclose(fp);

/* zip the report */
	sprintf(csTmpCmd, 
	        "zip_alrpt.sh %s %s %s %s %s 1>/dev/null",		
	        csTxnDate,
	        csMerchantId,
	        csCountryCode,
	        csCcyId,
	        csServiceCode);

	if (system(csTmpCmd) == PD_ERR)
	{
DEBUGLOG(("extract_account_ledger_daily_rpt::zip: fail %s\n", csTmpCmd));
	}
	else
	{
DEBUGLOG(("extract_account_ledger_daily_rpt::zip: success %s\n", csTmpCmd));
	}

/* ChkExist Insert/update acct_ldgr_rpt_hist */
	DBObjPtr = CreateObj(DBPtr,"DBAcctLedgerDailyReport","ChkExist");
	if ((*DBObjPtr)(hAccBal) > 0) 
	{
		DBObjPtr = CreateObj(DBPtr,"DBAcctLedgerDailyReport","UpdateStatus");
		if ((*DBObjPtr)(hAccBal) != PD_OK) 
			iRet = PD_ERR;
	}
	else
	{
		DBObjPtr = CreateObj(DBPtr,"DBAcctLedgerDailyReport","Add");
		if ((*DBObjPtr)(hAccBal) != PD_OK) 
			iRet = PD_ERR;
	}

	if (iRet == PD_OK)
	{
DEBUGLOG(("extract_account_ledger_daily_rpt::commit: MerchantId[%s] Country[%s] CcyId[%s] ServiceCode[%s] TxnDate[%s]\n", csMerchantId,csCountryCode,csCcyId,csServiceCode,csTxnDate));
		TxnCommit();
	}

	if (hAccBal)
	{
		hash_destroy(hAccBal);
		FREE_ME(hAccBal);
	}


	return iRet;
}

int process_cbledger(const char* csMerchantId,
                     const char* csCcyId,
                     const char* csCountryCode,
                     const char* csServiceCode,
                     const char* csReportDate,
                     FILE *fp)
{
	int   	iRet = SUCCESS;

	char    csTxnId[PD_TXN_ID_LEN+1];
	char    csTxnCode[PD_TXN_CODE_LEN+1];
	char    csTxnDesc[PD_DESC_LEN+1];
	double  dOpenBalance;
	char    csAmountType[PD_AMT_TYPE_LEN+1];
	double  dAmount;
	double  dBalance;
	char    csElementType[PD_TXN_ELEMENT_TYPE_LEN+1];
	char    csTxnElementTypeDesc[PD_DESC_LEN+1];
	int     iExecSeq;
	char    csTxnCcy[PD_CCY_ID_LEN+1];
	char    csApprovalDate[PD_DATE_LEN+1];
	double  dCredit;
	double  dDebit;
	char    csApprovalTimestamp[PD_TIMESTAMP_LEN+1];
	char    csMerchantRef[PD_MERCHANT_REF_LEN+1];
	char    csTmp[PD_TMP_BUF_LEN+1];


	/* EXEC SQL WHENEVER SQLERROR GOTO cbledger_sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

  
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar hv_country_code[PD_COUNTRY_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_code;

		/* varchar hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar	hv_report_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_report_date;

    
		/* varchar v_txn_id[PD_TXN_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_txn_id;

		/* varchar v_txn_code[PD_TXN_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

		/* varchar v_txn_desc[PD_DESC_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_desc;

		double  v_open_balance;
		/* varchar v_amount_type[PD_AMT_TYPE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_amount_type;

		double  v_amount;
		double  v_balance;
		/* varchar v_element_type[PD_TXN_ELEMENT_TYPE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_element_type;

		/* varchar v_txn_element_type_desc[PD_DESC_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_element_type_desc;

		int     v_exec_seq;
		/* varchar v_txn_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

		/* varchar v_approval_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } v_approval_date;

		double  v_credit;
		double  v_debit;
		/* varchar v_dummi_timestamp[PD_TIMESTAMP_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_dummi_timestamp;

		/* varchar v_approval_timestamp[PD_TIMESTAMP_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_approval_timestamp;

		/* varchar v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		
		short   ind_txn_id = -1;
		short   ind_txn_code = -1;
		short   ind_txn_desc = -1;
		short   ind_open_balance = -1;
		short   ind_amount_type = -1;
		short   ind_amount = -1;
		short   ind_balance = -1;
		short   ind_element_type = -1;
		short   ind_txn_element_type_desc = -1;
		short   ind_exec_seq = -1;
		short   ind_txn_ccy = -1;
		short   ind_approval_date = -1;
		short   ind_credit = -1;
		short   ind_debit = -1;
		short   ind_dummi_timestamp = -1;
		short   ind_approval_timestamp = -1;
		short   ind_merchant_ref = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("process_cbledger:Begin\n"));

	if(strlen(csMerchantId) > 0)
	{
		hv_merchant_id.len = strlen(csMerchantId);
		strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
DEBUGLOG(("process_cbledger:merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
	} else {
DEBUGLOG(("process_cbledger:merchant_id is missing\n"));
ERRLOG("extract_account_ledger_daily_rpt::process_cbledger: merchant_id is missing\n");
		return PD_ERR;
	}

	if(strlen(csCcyId) > 0)
	{
		hv_ccy_id.len = strlen(csCcyId);
		strncpy((char *)hv_ccy_id.arr, csCcyId, hv_ccy_id.len);
DEBUGLOG(("process_cbledger:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));
	} else {
DEBUGLOG(("process_cbledger:ccy_id is missing\n"));
ERRLOG("extract_account_ledger_daily_rpt::process_cbledger: ccy_id is missing\n");
		return PD_ERR;
	}

	if(strlen(csCountryCode) > 0)
	{
		hv_country_code.len = strlen(csCountryCode);
		strncpy((char *)hv_country_code.arr, csCountryCode, hv_country_code.len);
DEBUGLOG(("process_cbledger:country = [%.*s]\n",hv_country_code.len,hv_country_code.arr));
	} else {
DEBUGLOG(("process_cbledger:country is missing\n"));
ERRLOG("extract_account_ledger_daily_rpt::process_cbledger: country is missing\n");
		return PD_ERR;
	}

	if(strlen(csServiceCode) > 0)
	{
		hv_service_code.len = strlen(csServiceCode);
		strncpy((char *)hv_service_code.arr, csServiceCode, hv_service_code.len);
DEBUGLOG(("process_cbledger:service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));
	} else {
DEBUGLOG(("process_cbledger:service_code is missing\n"));
ERRLOG("extract_account_ledger_daily_rpt::process_cbledger: service_code is missing\n");
		return PD_ERR;
	}

	if(strlen(csReportDate) > 0)
	{
		hv_report_date.len = strlen(csReportDate);
		strncpy((char *)hv_report_date.arr, csReportDate, hv_report_date.len);
DEBUGLOG(("process_cbledger:report_date = [%.*s]\n",hv_report_date.len,hv_report_date.arr));
	} else {
DEBUGLOG(("process_cbledger:report_date is missing\n"));
ERRLOG("extract_account_ledger_daily_rpt::process_cbledger: report_date is missing\n");
		return PD_ERR;
	}


	/* EXEC SQL DECLARE c_cursor_getcbledger CURSOR FOR
		SELECT
		    TXN_ID AS TXN_ID,
		    TXN_CODE AS TXN_CODE,
		    TXN_CODE_DESC AS TXN_DESC,
		    OPEN_BAL AS OPEN_BALANCE,
		    AMT_TYPE AS AMOUNT_TYPE,
		    AMOUNT AS AMOUNT,
		    BAL AS BALANCE,
		    TXN_ELEMENT_TYPE AS ELEMENT_TYPE,
		    TXN_ELEMENT_TYPE_DESC AS TXN_ELEMENT_TYPE_DESC,
		    EXEC_SEQ AS EXEC_SEQ,
		    TXN_CCY AS TXN_CCY,
		    APPROVAL_DATE AS APPROVAL_DATE,
		    CASE WHEN AMT_TYPE = 'CR' THEN AMOUNT ELSE 0 END AS CREDIT,
		    CASE WHEN AMT_TYPE = 'DR' THEN AMOUNT ELSE 0 END AS DEBIT,
		    APPROVAL_TIMESTAMP,
		    TO_CHAR(APPROVAL_TIMESTAMP,'YYYY-MM-DD HH24:MI:SS') AS FORMAT_TIMESTAMP,
		    MERCHANT_REF AS MERCHANT_REF
		FROM TABLE(LEDGER_PKG.F_CB_LEDGER(
		    to_timestamp(to_date(:hv_report_date, 'YYYYMMDD HH24:MI')),
		    to_timestamp(to_date(:hv_report_date, 'YYYYMMDD HH24:MI') + 1),
		    :hv_merchant_id,
		    :hv_country_code,
		    :hv_service_code,
		    :hv_ccy_id
		)) ORDER BY APPROVAL_TIMESTAMP, EXEC_SEQ; */ 


        /* EXEC SQL OPEN c_cursor_getcbledger; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0003;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )96;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_report_date;
        sqlstm.sqhstl[0] = (unsigned long )10;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[2] = (unsigned long )17;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_country_code;
        sqlstm.sqhstl[3] = (unsigned long )4;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[4] = (unsigned long )5;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_ccy_id;
        sqlstm.sqhstl[5] = (unsigned long )5;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto cbledger_sql_error;
}



        do {

			/* EXEC SQL FETCH c_cursor_getcbledger
			INTO
			    :v_txn_id:ind_txn_id,
			    :v_txn_code:ind_txn_code,
			    :v_txn_desc:ind_txn_desc,
			    :v_open_balance:ind_open_balance,
			    :v_amount_type:ind_amount_type,
			    :v_amount:ind_amount,
			    :v_balance:ind_balance,
			    :v_element_type:ind_element_type,
			    :v_txn_element_type_desc:ind_txn_element_type_desc,
			    :v_exec_seq:ind_exec_seq,
			    :v_txn_ccy:ind_txn_ccy,
			    :v_approval_date:ind_approval_date,
			    :v_credit:ind_credit,
			    :v_debit:ind_debit,
			    :v_dummi_timestamp:ind_dummi_timestamp,
			    :v_approval_timestamp:ind_approval_timestamp,
			    :v_merchant_ref:ind_merchant_ref
			; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 17;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )135;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_id;
   sqlstm.sqhstl[0] = (unsigned long )23;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_txn_id;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_code;
   sqlstm.sqhstl[1] = (unsigned long )6;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_txn_code;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_desc;
   sqlstm.sqhstl[2] = (unsigned long )53;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_txn_desc;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_open_balance;
   sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_open_balance;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_amount_type;
   sqlstm.sqhstl[4] = (unsigned long )5;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_amount_type;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_amount;
   sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_amount;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&v_balance;
   sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_balance;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&v_element_type;
   sqlstm.sqhstl[7] = (unsigned long )7;
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         short *)&ind_element_type;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
   sqlstm.sqhstv[8] = (unsigned char  *)&v_txn_element_type_desc;
   sqlstm.sqhstl[8] = (unsigned long )53;
   sqlstm.sqhsts[8] = (         int  )0;
   sqlstm.sqindv[8] = (         short *)&ind_txn_element_type_desc;
   sqlstm.sqinds[8] = (         int  )0;
   sqlstm.sqharm[8] = (unsigned long )0;
   sqlstm.sqadto[8] = (unsigned short )0;
   sqlstm.sqtdso[8] = (unsigned short )0;
   sqlstm.sqhstv[9] = (unsigned char  *)&v_exec_seq;
   sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[9] = (         int  )0;
   sqlstm.sqindv[9] = (         short *)&ind_exec_seq;
   sqlstm.sqinds[9] = (         int  )0;
   sqlstm.sqharm[9] = (unsigned long )0;
   sqlstm.sqadto[9] = (unsigned short )0;
   sqlstm.sqtdso[9] = (unsigned short )0;
   sqlstm.sqhstv[10] = (unsigned char  *)&v_txn_ccy;
   sqlstm.sqhstl[10] = (unsigned long )6;
   sqlstm.sqhsts[10] = (         int  )0;
   sqlstm.sqindv[10] = (         short *)&ind_txn_ccy;
   sqlstm.sqinds[10] = (         int  )0;
   sqlstm.sqharm[10] = (unsigned long )0;
   sqlstm.sqadto[10] = (unsigned short )0;
   sqlstm.sqtdso[10] = (unsigned short )0;
   sqlstm.sqhstv[11] = (unsigned char  *)&v_approval_date;
   sqlstm.sqhstl[11] = (unsigned long )10;
   sqlstm.sqhsts[11] = (         int  )0;
   sqlstm.sqindv[11] = (         short *)&ind_approval_date;
   sqlstm.sqinds[11] = (         int  )0;
   sqlstm.sqharm[11] = (unsigned long )0;
   sqlstm.sqadto[11] = (unsigned short )0;
   sqlstm.sqtdso[11] = (unsigned short )0;
   sqlstm.sqhstv[12] = (unsigned char  *)&v_credit;
   sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[12] = (         int  )0;
   sqlstm.sqindv[12] = (         short *)&ind_credit;
   sqlstm.sqinds[12] = (         int  )0;
   sqlstm.sqharm[12] = (unsigned long )0;
   sqlstm.sqadto[12] = (unsigned short )0;
   sqlstm.sqtdso[12] = (unsigned short )0;
   sqlstm.sqhstv[13] = (unsigned char  *)&v_debit;
   sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[13] = (         int  )0;
   sqlstm.sqindv[13] = (         short *)&ind_debit;
   sqlstm.sqinds[13] = (         int  )0;
   sqlstm.sqharm[13] = (unsigned long )0;
   sqlstm.sqadto[13] = (unsigned short )0;
   sqlstm.sqtdso[13] = (unsigned short )0;
   sqlstm.sqhstv[14] = (unsigned char  *)&v_dummi_timestamp;
   sqlstm.sqhstl[14] = (unsigned long )23;
   sqlstm.sqhsts[14] = (         int  )0;
   sqlstm.sqindv[14] = (         short *)&ind_dummi_timestamp;
   sqlstm.sqinds[14] = (         int  )0;
   sqlstm.sqharm[14] = (unsigned long )0;
   sqlstm.sqadto[14] = (unsigned short )0;
   sqlstm.sqtdso[14] = (unsigned short )0;
   sqlstm.sqhstv[15] = (unsigned char  *)&v_approval_timestamp;
   sqlstm.sqhstl[15] = (unsigned long )23;
   sqlstm.sqhsts[15] = (         int  )0;
   sqlstm.sqindv[15] = (         short *)&ind_approval_timestamp;
   sqlstm.sqinds[15] = (         int  )0;
   sqlstm.sqharm[15] = (unsigned long )0;
   sqlstm.sqadto[15] = (unsigned short )0;
   sqlstm.sqtdso[15] = (unsigned short )0;
   sqlstm.sqhstv[16] = (unsigned char  *)&v_merchant_ref;
   sqlstm.sqhstl[16] = (unsigned long )53;
   sqlstm.sqhsts[16] = (         int  )0;
   sqlstm.sqindv[16] = (         short *)&ind_merchant_ref;
   sqlstm.sqinds[16] = (         int  )0;
   sqlstm.sqharm[16] = (unsigned long )0;
   sqlstm.sqadto[16] = (unsigned short )0;
   sqlstm.sqtdso[16] = (unsigned short )0;
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
   if (sqlca.sqlcode < 0) goto cbledger_sql_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			fprintf(fp,"<Row>\n");
/*	v_approval_timestamp	*/
			if (ind_approval_timestamp >= 0)
			{
				v_approval_timestamp.arr[v_approval_timestamp.len] = '\0';
				strcpy(csApprovalTimestamp,(const char*)v_approval_timestamp.arr);
				fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csApprovalTimestamp);
/*DEBUGLOG(("process_cbledger v_approval_timestamp = [%s]\n", v_approval_timestamp.arr));*/
			}
			else
				fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");

/* txn_desc	*/
			if(ind_txn_desc >= 0)
			{
				v_txn_desc.arr[v_txn_desc.len] = '\0';
				strcpy(csTxnDesc,(const char*)v_txn_desc.arr);
				fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csTxnDesc);
/*DEBUGLOG(("process_cbledger v_txn_desc = [%s]\n", v_txn_desc.arr));*/
			}
			else
				fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");

/*	v_txn_element_type_desc */
			if (ind_txn_element_type_desc >= 0)
			{
				v_txn_element_type_desc.arr[v_txn_element_type_desc.len] = '\0';
				strcpy(csTxnElementTypeDesc,(const char*)v_txn_element_type_desc.arr);
				fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csTxnElementTypeDesc);
/*DEBUGLOG(("process_cbledger v_txn_element_type_desc = [%s]\n", v_txn_element_type_desc.arr));*/
			}
			else
				fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");

/* txn_id */
			if(ind_txn_id >=0)
			{
				v_txn_id.arr[v_txn_id.len] = '\0';
				strcpy(csTxnId,(const char*)v_txn_id.arr);
				fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csTxnId);
/*DEBUGLOG(("process_cbledger v_txn_id = [%s]\n", v_txn_id.arr));*/
			}
			else
				fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");

/*	v_merchant_ref  */
			if (ind_merchant_ref >= 0)
			{
				v_merchant_ref.arr[v_merchant_ref.len] = '\0';
				strcpy(csMerchantRef,(const char*)v_merchant_ref.arr);
				fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csMerchantRef);
/*DEBUGLOG(("process_cbledger v_merchant_ref = [%s]\n", v_merchant_ref.arr));*/
			}
			else
				fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");

/*	v_txn_ccy	*/
			if (ind_txn_ccy >= 0)
			{
				v_txn_ccy.arr[v_txn_ccy.len] = '\0';
				strcpy(csTxnCcy,(const char*)v_txn_ccy.arr);
				fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csTxnCcy);
/*DEBUGLOG(("process_cbledger v_txn_ccy = [%s]\n", v_txn_ccy.arr));*/
			}
			else
				fprintf(fp,"\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");

/*	v_credit	*/
			if (ind_credit >= 0)
			{
				dCredit = v_credit;
				format_commas(dCredit, csTmp);
				/*fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%.2f</Data></Cell>\n",dCredit);*/
				fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%s</Data></Cell>\n",csTmp);
/*DEBUGLOG(("process_cbledger v_credit = [%f]\n",v_credit));*/
			}
			else
				fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">0</Data></Cell>\n");

/*	v_debit	*/
			if(ind_debit >= 0)
			{
				dDebit = v_debit;
				format_commas(dDebit, csTmp);
				/*fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%.2f</Data></Cell>\n",dDebit);*/
				fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%s</Data></Cell>\n",csTmp);
/*DEBUGLOG(("process_cbledger v_debit = [%f]\n",v_debit));*/
			}
			else
				fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">0</Data></Cell>\n");

/*	v_open_balance	*/
			if (ind_open_balance >= 0)
			{
				dOpenBalance = v_open_balance;
/*DEBUGLOG(("process_cbledger v_open_balance = [%f]\n",v_open_balance));*/
			}

/*	v_amount	*/
			if (ind_amount >= 0)
			{
				dAmount = v_amount;
/*DEBUGLOG(("process_cbledger v_amount = [%f]\n",v_amount));*/
			}

/* txn_code */
			if (ind_txn_code >=0 )
			{
				v_txn_code.arr[v_txn_code.len] = '\0';
				strcpy(csTxnCode,(const char*)v_txn_code.arr);
/*DEBUGLOG(("process_cbledger v_txn_code = [%s]\n", v_txn_code.arr));*/
			}

/*	v_amount_type	*/
			if (ind_amount_type >= 0)
			{
				v_amount_type.arr[v_amount_type.len] = '\0';
				strcpy(csAmountType,(const char*)v_amount_type.arr);
/*DEBUGLOG(("process_cbledger v_amount_type = [%s]\n", v_amount_type.arr));*/
			}

/*	v_balance	*/
			if(ind_balance >= 0)
			{
				dBalance  = v_balance;
/* debug  */
				format_commas(dBalance, csTmp);
				/*fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%.2f</Data></Cell>\n",dBalance);*/
				fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">%s</Data></Cell>\n",csTmp);
/*DEBUGLOG(("process_cbledger v_balance = [%f]\n",v_balance));*/
			}
			else
				fprintf(fp,"\t<Cell><Data ss:Type=\"Number\">0</Data></Cell>\n");

/*	v_element_type  */
			if (ind_element_type >= 0)
			{
				v_element_type.arr[v_element_type.len] = '\0';
				strcpy(csElementType,(const char*)v_element_type.arr);
/*DEBUGLOG(("process_cbledger v_element_type = [%s]\n", v_element_type.arr));*/
			}

/*	v_exec_seq	*/
			if (ind_exec_seq >= 0)
			{
				iExecSeq = v_exec_seq;
/*DEBUGLOG(("process_cbledger v_exec_seq = [%d]\n",v_exec_seq));*/
			}

/*	v_approval_date */
			if (ind_approval_date >= 0)
			{
				v_approval_date.arr[v_approval_date.len] = '\0';
				strcpy(csApprovalDate,(const char*)v_approval_date.arr);
/*DEBUGLOG(("process_cbledger v_approval_date = [%s]\n", v_approval_date.arr));*/
			}

			fprintf(fp,"</Row>\n");

        } while (PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getcbledger; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )218;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto cbledger_sql_error;
}



	return iRet;

cbledger_sql_error:
DEBUGLOG(("extract_account_ledger_daily_rpt:process_cbledger code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getcbledger; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )233;
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
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )248;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



	return PD_ERR;
}

int mkFullPathDir(const char * csYearMthDy) 
{
	int  iRet = SUCCESS;
	char csTmpCmd[PD_TMP_BUF_LEN+1];

	sprintf(csTmpCmd, 
	        "mkdir_acctledger_tree.sh %s 1> /dev/null",		
	        csYearMthDy);
	
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

int chkSpInMID(const char* csMerchantId)
{
	int iCnt = 0;

	for (iCnt; iCnt < strlen(csMerchantId); iCnt++)
		if (csMerchantId[iCnt] == 32)
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
	strcpy(csInMerchantId,"");
	strcpy(csInCcyId,"");
	strcpy(csInCountryCode,"");
	strcpy(csInServiceCode,"");

	while ((c = getopt(argc,argv,"d:m:c:o:s:")) != EOF) {
		switch (c) {
			case 'd':
				strcpy(csDate, optarg);
				break;
			case 'm':
				strcpy(csInMerchantId, optarg);
				break;
			case 'c':
				strcpy(csInCcyId, optarg);
				break;
			case 'o':
				strcpy(csInCountryCode, optarg);
				break;
			case 's':
				strcpy(csInServiceCode, optarg);
				break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(csDate,""))
		return FAILURE;

	if (argc > 3) {
		if (!strcmp(csInMerchantId,""))
			return FAILURE;

		if (!strcmp(csInCcyId,""))
			return FAILURE;

		if (!strcmp(csInCountryCode,""))
			return FAILURE;

		if (!strcmp(csInServiceCode,""))
			return FAILURE;
	}

	return SUCCESS;
}




int CreateAlertEmailTpl(hash_t *hData)
{
	int iRet = PD_OK;

	int iDynCnt = 0;

	char *csFunct = NULL;

	char csAlertDateTime[PD_TIMESTAMP_LEN + 1];
	char csStatus[PD_TMP_BUF_LEN + 1];
	char csTmpBuf[PD_TMP_BUF_LEN + 1];

	time_t  tNow = time(NULL);
	struct  tm tStruct = *localtime(&tNow);

	hash_t *hTemplate;
	hTemplate = (hash_t*) malloc(sizeof(hash_t));
	hash_init(hTemplate,0);

DEBUGLOG(("CreateAlertEmailTpl: Begin\n"));

	memset(csAlertDateTime, 0, sizeof(csAlertDateTime));
	memset(csStatus, 0, sizeof(csStatus));
	memset(csTmpBuf, 0, sizeof(csTmpBuf));

/* funct */
	if (GetField_CString(hData,"funct",&csFunct)) {
DEBUGLOG((" funct = [%s]\n",csFunct));
		PutField_CString(hTemplate, "funct", csFunct);
	} else {
DEBUGLOG((" funct not exists\n"));
		iRet = INT_ERR;
	}

/* Alert Date Time */
	if (iRet == PD_OK) {
		strftime(csAlertDateTime, sizeof(csAlertDateTime), PD_ALERT_DATETIME_FORMAT, &tStruct);

		iDynCnt = set_tpl_dyn_int(hTemplate, iDynCnt, "stimestamp-0", "SEC", "stimestamp-0", 0);
		iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, "ftimestamp-0", "STR", "stimestamp-0", csAlertDateTime);
		//iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, "ftimestamp-0", "STR", "stimestamp-0", write_tpl_timestamp());

/* Report Date */
DEBUGLOG((" report date = [%s]\n",csDate));

		iDynCnt = set_tpl_dyn_int(hTemplate, iDynCnt, "sreportdate-0", "SEC", "sreportdate-0", 0);
		iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, "freportdate-0", "STR", "sreportdate-0", csDate);

/* Error Message */
		sprintf(csTmpBuf, "Running Balance Patching Incomplete");
DEBUGLOG((" Error Message = [%s]\n",csTmpBuf));

		iDynCnt = set_tpl_dyn_int(hTemplate, iDynCnt, "serrormsg-0", "SEC", "serrormsg-0", 0);
		iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, "ferrormsg-0", "STR", "serrormsg-0", csTmpBuf);			
	}

	// Process Alert Email Template
	if (iRet == PD_OK) {
		PutField_CString(hTemplate, "source", PD_EML_SOURCE_BATCH);
  		PutField_Char(hTemplate, "party_type", PD_TYPE_GLOBAL);
		PutField_CString(hTemplate, "party_id", PD_EML_PARTY_ID_BATCH);	
   		PutField_Int(hTemplate, "total_dyn", iDynCnt);

		BOObjPtr = CreateObj(BOPtr, "BOAlertEmail", "ProcessTpl");
		iRet = (unsigned long)((*BOObjPtr)(hTemplate));
		if (iRet == PD_OK) {
DEBUGLOG((" BOAlertEmail:ProcessTpl Success\n"));
		} else {
DEBUGLOG((" BOAlertEmail:ProcessTpl Failed\n"));
			PutField_Int(hTemplate, "internal_error", iRet);
		}	
	}

	hash_destroy(hTemplate);
	FREE_ME(hTemplate);

DEBUGLOG(("CreateAlertEmailTpl: iRet = [%d]\n", iRet));
	return iRet;
}

