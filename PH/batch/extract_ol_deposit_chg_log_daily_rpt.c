
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
           char  filnam[40];
};
static struct sqlcxp sqlfpn =
{
    39,
    "extract_ol_deposit_chg_log_daily_rpt.pc"
};


static unsigned int sqlctx = 597813691;


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
   unsigned char  *sqhstv[14];
   unsigned long  sqhstl[14];
            int   sqhsts[14];
            short *sqindv[14];
            int   sqinds[14];
   unsigned long  sqharm[14];
   unsigned long  *sqharc[14];
   unsigned short  sqadto[14];
   unsigned short  sqtdso[14];
} sqlstm = {12,14};

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
"SELECT MD_MERCHANT_ID FROM OL_MERCH_DETAIL ORDER BY MD_MERCHANT_ID         \
   ";

 static char *sq0003 = 
"HH24:MI:SS' ) AS UPDATE_TIMESTAMP FR\
OM OL_TXN_DEPOSIT_EDIT_LOG LEFT JOIN BANK_DESC ON BANK_DESC . INTERNAL_BANK_C\
ODE = OL_TXN_DEPOSIT_EDIT_LOG . OTC_BANK_CODE INNER JOIN OL_TXN_HEADER ON OL_\
TXN_HEADER . OTH_TXN_ID = OL_TXN_DEPOSIT_EDIT_LOG . OTC_TXN_ID INNER JOIN OL_\
TXN_DETAIL ON OL_TXN_DETAIL . OTD_TXN_ID = OL_TXN_DEPOSIT_EDIT_LOG . OTC_TXN_\
ID INNER JOIN OL_MERCH_DETAIL ON OL_MERCH_DETAIL . MD_MERCHANT_ID = OL_TXN_HE\
ADER . OTH_MERCHANT_ID LEFT JOIN USER_DETAIL EDIT_USER_DETAIL ON EDIT_USER_DE\
TAIL . USERNAME = OL_TXN_DEPOSIT_EDIT_LOG . OTC_CREATE_USER WHERE OL_TXN_HEAD\
ER . OTH_MERCHANT_ID = :b0 AND OL_TXN_DEPOSIT_EDIT_LOG . OTC_TXN_ID IN ( SELE\
CT OTC_TXN_ID FROM OL_TXN_DEPOSIT_EDIT_LOG WHERE OTC_CREATE_TIMESTAMP >= TO_D\
ATE ( :b1 , 'YYYY-MM-DD HH24:MI' ) AND OTC_CREATE_TIMESTAMP < TO_DATE ( :b1 ,\
 'YYYY-MM-DD HH24:MI' ) + 1 ) ORDER BY OTH_MERCHANT_REF , OTC_TXN_ID , OTC_EX\
EC_SEQ DESC            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,78,0,9,415,0,2049,0,0,0,1,0,
20,0,0,1,0,0,13,418,0,0,1,0,0,1,0,2,9,0,0,
39,0,0,1,0,0,15,440,0,0,0,0,0,1,0,
54,0,0,1,0,0,15,452,0,0,0,0,0,1,0,
69,0,0,2,0,0,32,453,0,0,0,0,0,1,0,
84,0,0,3,1930,0,9,569,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
111,0,0,3,0,0,13,573,0,0,14,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
182,0,0,3,0,0,15,744,0,0,0,0,0,1,0,
197,0,0,3,0,0,15,754,0,0,0,0,0,1,0,
212,0,0,4,0,0,32,755,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2019. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                            Change Date     Change By
------------------------------------------    ------------    --------------
Init Version                                  2019/12/02      Elvis Wong
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
#include "myrecordset.h"
#include "numutility.h"
#include "ObjPtr.h"
#include "dbutility.h"


#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define PD_REC_ENABLED     0
#define PD_FILE_PREFIX	   "ol_deposit_chg_log"

OBJPTR(DB);

char csInDate[PD_DATE_LEN + 1];
char csInMerchantId[PD_MERCHANT_ID_LEN+1];

static char cDebug = 'Y';

int parse_arg(int argc,char **argv);

int process_data(const char* csTxnDate); 

int process_single_acct(const char* csTxnDate, 
			const char* csMerchantId);

int get_merchant_id(recordset_t *rMerchantId);

int process_deposit_change_log(const char* csReportDate,
			       const char* csMerchantId,
                     	       FILE *fp);
					 
int mkFullPathDir(const char* csYearMthDy);

char* getYYYY(const char* csTxnDate);

char* getYYYYMM(const char* csTxnDate);

int chkSpInMID(const char* csMerchantId);

void format_commas(double dInNum, char* csOutNum);

int batch_init(int argc, char* argv[])
{
	if (argc < 3) {
		printf("usage: -d Date\n");

		return FAILURE;
	}
	else if (argc > 3 && argc < 5) {
		printf("usage: -d Date -m Merchant_ID\n");

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
		if (argc < 3) {
			printf("usage: -d Date\n");
		}
		else if (argc > 3 && argc < 5) {
			printf("usage: -d Date -m Merchant_ID\n");
		}

		return (iRet);
	}

	if (argc == 3) {
		iRet = process_data(csInDate);
	}
	else
	{
		iRet = process_single_acct(csInDate,csInMerchantId);
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

	int     iDtlRet = PD_OK;
	int	iCnt = 0;

	hash_t *hMerchantId = NULL;
	recordset_t *rMerchantId;
        rMerchantId = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rMerchantId, 0);
	
DEBUGLOG(("start\n"));

	iDtlRet = get_merchant_id(rMerchantId);
	if (iDtlRet == PD_OK) {

		hMerchantId = RecordSet_GetFirst(rMerchantId);
        	while ((iRet == SUCCESS) && (hMerchantId)) {

			char *csMerchantId = NULL;

DEBUGLOG(("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"));
DEBUGLOG(("record = [%d]\n", iCnt));

/* merchant_id */
			if (GetField_CString(hMerchantId,"merchant_id",&csMerchantId)) 
			{
				iRet = process_single_acct(csTxnDate, csMerchantId);
        	       	}
			else
			{
				iRet = FAILURE;
			}

			if (iRet == SUCCESS)
			{
DEBUGLOG(("result = [SUCCESS]\n"));
			}
			else
			{
DEBUGLOG(("result = [FAIL]\n"));
			}
DEBUGLOG(("--------------------------------------------------------------------------------\n"));

			iCnt++;

			hMerchantId = RecordSet_GetNext(rMerchantId);
		}
	}
	else
	{
DEBUGLOG(("get_merchant_id: fail\n"));
		iRet = FAILURE;
	}

	RecordSet_Destroy(rMerchantId);
        FREE_ME(rMerchantId);

DEBUGLOG(("Exit, iRet = [%d]\n", iRet));
	return iRet;
}

int process_single_acct(const char* csTxnDate,
                        const char* csMerchantId)
{               
	int     iRet = SUCCESS;
	int	iDtlRet = PD_OK;

	char    csUploadFilename[PD_UPLOAD_FILENAME_LEN+1];
	char    csUploadFullFile[PD_PATH_LEN+1];
	char    csTmpCmd[PD_TMP_BUF_LEN+1];
	char    csYear[PD_YYYY_LEN+1];
	char    csYearMth[PD_YYYYMM_LEN+1];

	FILE    *fp;

	hash_t* hDepositChgLog;
	hDepositChgLog = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hDepositChgLog,0);
 
/* report_code */
 	PutField_CString(hDepositChgLog,"report_code",PD_OL_DEPOSIT_CHG_LOG_REPORT_CODE);
DEBUGLOG(("report_code = [%s]\n", PD_OL_DEPOSIT_CHG_LOG_REPORT_CODE));
	
/* disabled*/
        PutField_Int(hDepositChgLog,"disabled",PD_REC_ENABLED);
DEBUGLOG(("disabled = [%d]\n", PD_REC_ENABLED));

/* report_date */
        if (strlen(csTxnDate) > 0)
        {
                PutField_CString(hDepositChgLog,"report_date",csTxnDate);
DEBUGLOG(("report_date = [%s]\n", csTxnDate));
        }

/* merchant_id */
	if (strlen(csMerchantId) > 0)
	{
		PutField_CString(hDepositChgLog,"merchant_id",csMerchantId);
DEBUGLOG(("merchant_id = [%s]\n", csMerchantId));
	}
 
/* Skip the record if MID contains space */
        iDtlRet = chkSpInMID(csMerchantId);
	if (iDtlRet == PD_ERR)
	{
DEBUGLOG(("process_data:skip (MID contains space)\n"));
          	return SUCCESS;
	}

/* Addition field Filename */
	sprintf(csUploadFilename, 
	        "%s_%s_%s.zip", 
		PD_FILE_PREFIX, 
		csMerchantId, 
		csTxnDate);

	PutField_CString(hDepositChgLog,"filename",csUploadFilename);
DEBUGLOG(("file_prefix = [%s]\n", PD_FILE_PREFIX));
DEBUGLOG(("filename = [%s]\n", csUploadFilename));

/* Addition field Update_user */
	PutField_CString(hDepositChgLog,"user",PD_UPDATE_USER);

/* Extract year and year month */
	strcpy(csYear, getYYYY(csTxnDate));

	strcpy(csYearMth, getYYYYMM(csTxnDate));

/* Check and make current balance report folder */
	iDtlRet = mkFullPathDir(csTxnDate);
	if (iDtlRet != PD_OK)
	{
DEBUGLOG(("process_data:unable to create path [%s]\n", csTxnDate));
		return FAILURE;
	}
	
	sprintf(csUploadFullFile,
		"%s/%s/%s/%s/%s/%s_%s_%s.xls",  
	        getenv("OL_PREGEN_RPT_HOME"), PD_FILE_PREFIX, csYear, csYearMth, csTxnDate, 
		PD_FILE_PREFIX,
	        csMerchantId,
	        csTxnDate);
DEBUGLOG(("full_filename = [%s]\n", csUploadFullFile));

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
	fprintf(fp,"<Worksheet ss:Name=\"Deposit Request Change Log\">\n");
	fprintf(fp,"<Table>\n");

/* create deposit change log txn header */
	fprintf(fp,"<Row>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Reference</Data></Cell>\n");
       	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Consumer Payable Amount Currency</Data></Cell>\n");
      	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Consumer Payable Amount</Data></Cell>\n");
      	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Consumer Deposit Date and Time</Data></Cell>\n");
      	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Beneficiary Bank Name</Data></Cell>\n");
     	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Bank Account Number</Data></Cell>\n");
    	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Consumer Deposit Bank</Data></Cell>\n");
    	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Consumer Provided Bank Reference</Data></Cell>\n");
    	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Reason for Edit</Data></Cell>\n");
     	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Update User</Data></Cell>\n");
     	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Update Timestamp</Data></Cell>\n");
	fprintf(fp,"</Row>\n");

/* process deposit change log data */
	iDtlRet = process_deposit_change_log(csTxnDate, csMerchantId, fp);
	if (iDtlRet == PD_OK)
	{
/* Addition field Status */
            	PutField_Char(hDepositChgLog,"status",PD_PREGEN_RPT_COMPLETED);

DEBUGLOG(("status = [%c]\n", PD_PREGEN_RPT_COMPLETED));
DEBUGLOG(("process_deposit_change_log: success\n"));
	}
	else
	{
/* Addition field Status */
               	PutField_Char(hDepositChgLog,"status",PD_PREGEN_RPT_FAILURE);

DEBUGLOG(("status = [%c]\n", PD_PREGEN_RPT_FAILURE));
DEBUGLOG(("process_deposit_change_log: fail\n"));

		iRet = FAILURE;
	}
			
/* create xml footer */
	fprintf(fp, "</Table>\n");
	fprintf(fp, "</Worksheet>\n");
	fprintf(fp, "</Workbook>\n");

	fclose(fp);

/* zip the report */
	sprintf(csTmpCmd, 
		"zip_ol_pregenrpt.sh %s %s %s %s 1>/dev/null",
		csTxnDate,
		getenv("OL_PREGEN_RPT_HOME"),
		PD_FILE_PREFIX,
		csMerchantId);

	iDtlRet = system(csTmpCmd);
	if (iDtlRet == PD_ERR)
	{
DEBUGLOG(("zip: fail [%s]\n", csTmpCmd));
	}
	else
	{
DEBUGLOG(("zip: success [%s]\n", csTmpCmd));
	}

/* ChkExist Insert/update ol_pregen_daily_report */
	DBObjPtr = CreateObj(DBPtr,"DBOLPregenDailyReport","ChkExist");
	iDtlRet = (unsigned long)(DBObjPtr)(hDepositChgLog);
	if (iDtlRet > 0)
	{
		DBObjPtr = CreateObj(DBPtr,"DBOLPregenDailyReport","UpdateStatus");
		iDtlRet = (unsigned long)(DBObjPtr)(hDepositChgLog);
		if (iDtlRet == PD_OK)
		{
DEBUGLOG(("call DBOLPregenDailyReport: updatestatus: success\n"));
		}
		else
		{
DEBUGLOG(("call DBOLPregenDailyReport: updatestatus: fail\n"));
			iRet = FAILURE;
		}
	}
	else
	{
		DBObjPtr = CreateObj(DBPtr,"DBOLPregenDailyReport","Add");
		iDtlRet = (unsigned long)(DBObjPtr)(hDepositChgLog);
		if (iDtlRet == PD_OK)
		{
DEBUGLOG(("call DBOLPregenDailyReport: add: success\n"));
		}
		else
		{
DEBUGLOG(("call DBOLPregenDailyReport: add: fail\n"));
			iRet = FAILURE;
		}
	}

	if (iRet == SUCCESS)
	{
		TxnCommit();
DEBUGLOG(("commit pregen daily report data to database\n"));
	}

	if (hDepositChgLog)
	{
		hash_destroy(hDepositChgLog);
		FREE_ME(hDepositChgLog);
	}

	return iRet;
}

int get_merchant_id(recordset_t *rMerchantId)
{
	int 	iCnt = 0;

        hash_t *myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar v_merchant_id[PD_MERCHANT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;


                short   ind_merchant_id  = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        /* EXEC SQL DECLARE c_cursor_getolmerchdetail CURSOR FOR
                SELECT MD_MERCHANT_ID
                FROM OL_MERCH_DETAIL
                ORDER BY MD_MERCHANT_ID
                ; */ 


        /* EXEC SQL OPEN c_cursor_getolmerchdetail; */ 

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
                /* EXEC SQL FETCH c_cursor_getolmerchdetail
                INTO :v_merchant_id:ind_merchant_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 1;
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

		myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

                iCnt++;

/* merchant_id */
		if (ind_merchant_id >= 0) {
                        v_merchant_id.arr[v_merchant_id.len] = '\0';
                        PutField_CString(myHash, "merchant_id", (const char*)v_merchant_id.arr);
                }
		
		RecordSet_Add(rMerchantId,myHash);

	} while (PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getolmerchdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )39;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto sql_error;
}



	if (iCnt > 0) {
                return PD_OK;
        } else {
                return PD_ERR;
        }

sql_error:
DEBUGLOG(("extract_ol_deposit_chg_log_daily_rpt::get_merchant_id: error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getolmerchdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )54;
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
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )69;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;	
}

int process_deposit_change_log(const char* csReportDate,
                     	       const char* csMerchantId, 	
                     	       FILE *fp)
{
	int   	iRet = PD_OK;

	double  dTmp;

	char    csTmp[PD_TMP_BUF_LEN+1];
	
	/* EXEC SQL WHENEVER SQLERROR GOTO dsichglog_sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

  
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	hv_report_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_report_date;

		
		/* varchar v_merchant_ref[PD_MERCHANT_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar v_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ccy;

		double  v_amt;
		/* varchar v_deposit_datetime[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_deposit_datetime;

		/* varchar v_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

		/* varchar v_bank_name[PD_AC_BANK_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

		/* varchar v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

		/* varchar v_deposit_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_deposit_bank_code;

		/* varchar v_deposit_bank[PD_AC_BANK_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_deposit_bank;

		/* varchar v_deposit_ref[PD_DEPOSITOR_PROV_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_deposit_ref;

		/* varchar v_reason_edit[PD_REASONEDIT_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_reason_edit;
	
		/* varchar v_update_user[PD_USER_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_update_user;
	
		/* varchar v_update_timestamp[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_update_timestamp;
	

		short   ind_merchant_ref = -1;
		short   ind_txn_id = -1;
		short   ind_ccy = -1;		
		short   ind_amt = -1;
		short   ind_deposit_datetime = -1;
		short   ind_bank_code = -1;
		short   ind_bank_name = -1;
		short	ind_bank_acct_num = -1;
		short	ind_deposit_bank_code = -1;
		short	ind_deposit_bank = -1;
		short	ind_deposit_ref = -1;
		short	ind_reason_edit = -1;
		short	ind_update_user = -1;
		short	ind_update_timestamp = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


//DEBUGLOG(("process_deposit_change_log:Begin\n"));

	if(strlen(csReportDate) > 0)
        {
                hv_report_date.len = strlen(csReportDate);
                strncpy((char *)hv_report_date.arr, csReportDate, hv_report_date.len);
//DEBUGLOG(("process_deposit_change_log:report_date = [%.*s]\n",hv_report_date.len,hv_report_date.arr));
        } else {
DEBUGLOG(("process_deposit_change_log:report_date is missing\n"));
ERRLOG("extract_ol_deposit_chg_log_daily_rpt::process_deposit_change_log: report_date is missing\n");
                return PD_ERR;
        }

	if(strlen(csMerchantId) > 0)
	{
		hv_merchant_id.len = strlen(csMerchantId);
		strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
//DEBUGLOG(("process_deposit_change_log:merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
	} else {
DEBUGLOG(("process_deposit_change_log:merchant_id is missing\n"));
ERRLOG("extract_ol_deposit_chg_log_daily_rpt::process_deposit_change_log: merchant_id is missing\n");
		return PD_ERR;
	}

	/* EXEC SQL DECLARE c_cursor_getdepositchglog CURSOR FOR
	
		SELECT 	OL_TXN_HEADER.OTH_MERCHANT_REF AS MERCHANT_REF,
       			OL_TXN_DEPOSIT_EDIT_LOG.OTC_TXN_ID AS TXN_ID,
       			OL_TXN_DETAIL.OTD_TXN_CCY AS CURRENCY,
       			OL_TXN_DEPOSIT_EDIT_LOG.OTC_AMOUNT AS AMOUNT,
       			TO_CHAR (TO_DATE (OL_TXN_DEPOSIT_EDIT_LOG.OTC_CUST_DEPOSIT_DATETIME, 'YYYYMMDDHH24MI'), 'YYYY-MM-DD HH24:MI') AS DEPOSIT_DATETIME,
       			OL_TXN_DEPOSIT_EDIT_LOG.OTC_BANK_CODE AS BANK_CODE,
       			BANK_DESC.BANK_NAME AS BANK_NAME,
       			SP_MASK_BANK_ACCT_NUM (OL_TXN_DEPOSIT_EDIT_LOG.OTC_BANK_CODE, OL_TXN_DEPOSIT_EDIT_LOG.OTC_BANK_ACCT_NUM) AS BANK_ACCT_NUM,
       			OL_TXN_DEPOSIT_EDIT_LOG.OTC_DEPOSIT_BANK_CODE AS DEPOSIT_BANK_CODE,
       			OL_TXN_DEPOSIT_EDIT_LOG.OTC_DEPOSIT_BANK AS DEPOSIT_BANK,
       			OL_TXN_DEPOSIT_EDIT_LOG.OTC_DEPOSIT_REF AS DEPOSIT_REF,
      	 		OL_TXN_DEPOSIT_EDIT_LOG.OTC_REASON_EDIT AS REASON_EDIT,
       			CASE
           			WHEN EDIT_USER_DETAIL.USER_TYPE_ID = 2 THEN 'System Administrator'
           			ELSE OL_TXN_DEPOSIT_EDIT_LOG.OTC_CREATE_USER
       			END AS UPDATE_USER,
       			TO_CHAR (OL_TXN_DEPOSIT_EDIT_LOG.OTC_CREATE_TIMESTAMP, 'YYYY-MM-DD HH24:MI:SS') AS UPDATE_TIMESTAMP
 		FROM 	OL_TXN_DEPOSIT_EDIT_LOG
       			LEFT JOIN BANK_DESC
           			ON BANK_DESC.INTERNAL_BANK_CODE = OL_TXN_DEPOSIT_EDIT_LOG.OTC_BANK_CODE
       			INNER JOIN OL_TXN_HEADER
           			ON OL_TXN_HEADER.OTH_TXN_ID = OL_TXN_DEPOSIT_EDIT_LOG.OTC_TXN_ID
       			INNER JOIN OL_TXN_DETAIL
           			ON OL_TXN_DETAIL.OTD_TXN_ID = OL_TXN_DEPOSIT_EDIT_LOG.OTC_TXN_ID
       			INNER JOIN OL_MERCH_DETAIL
           			ON OL_MERCH_DETAIL.MD_MERCHANT_ID = OL_TXN_HEADER.OTH_MERCHANT_ID
       			LEFT JOIN USER_DETAIL EDIT_USER_DETAIL
           			ON EDIT_USER_DETAIL.USERNAME = OL_TXN_DEPOSIT_EDIT_LOG.OTC_CREATE_USER
 		WHERE  	OL_TXN_HEADER.OTH_MERCHANT_ID = :hv_merchant_id
       		AND 	OL_TXN_DEPOSIT_EDIT_LOG.OTC_TXN_ID IN 	(SELECT OTC_TXN_ID
                  				  		FROM OL_TXN_DEPOSIT_EDIT_LOG
                 				  		WHERE OTC_CREATE_TIMESTAMP >= TO_DATE (:hv_report_date, 'YYYY-MM-DD HH24:MI')
                       				  		AND OTC_CREATE_TIMESTAMP < TO_DATE (:hv_report_date, 'YYYY-MM-DD HH24:MI') + 1)
		ORDER BY 	OTH_MERCHANT_REF, 
				OTC_TXN_ID, 
				OTC_EXEC_SEQ DESC; */ 


	/* EXEC SQL OPEN c_cursor_getdepositchglog; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "SELECT OL_TXN_HEADER . OTH_MERCHANT_REF AS MERCHANT_REF , OL_TXN_DEPOSIT\
_EDIT_LOG . OTC_TXN_ID AS TXN_ID , OL_TXN_DETAIL . OTD_TXN_CCY AS CURRENCY ,\
 OL_TXN_DEPOSIT_EDIT_LOG . OTC_AMOUNT AS AMOUNT , TO_CHAR ( TO_DATE ( OL_TXN\
_DEPOSIT_EDIT_LOG . OTC_CUST_DEPOSIT_DATETIME , 'YYYYMMDDHH24MI' ) , 'YYYY-M\
M-DD HH24:MI' ) AS DEPOSIT_DATETIME , OL_TXN_DEPOSIT_EDIT_LOG . OTC_BANK_COD\
E AS BANK_CODE , BANK_DESC . BANK_NAME AS BANK_NAME , SP_MASK_BANK_ACCT_NUM \
( OL_TXN_DEPOSIT_EDIT_LOG . OTC_BANK_CODE , OL_TXN_DEPOSIT_EDIT_LOG . OTC_BA\
NK_ACCT_NUM ) AS BANK_ACCT_NUM , OL_TXN_DEPOSIT_EDIT_LOG . OTC_DEPOSIT_BANK_\
CODE AS DEPOSIT_BANK_CODE , OL_TXN_DEPOSIT_EDIT_LOG . OTC_DEPOSIT_BANK AS DE\
POSIT_BANK , OL_TXN_DEPOSIT_EDIT_LOG . OTC_DEPOSIT_REF AS DEPOSIT_REF , OL_T\
XN_DEPOSIT_EDIT_LOG . OTC_REASON_EDIT AS REASON_EDIT , CASE WHEN EDIT_USER_D\
ETAIL . USER_TYPE_ID = 2 THEN 'System Administrator' ELSE OL_TXN_DEPOSIT_EDI\
T_LOG . OTC_CREATE_USER END AS UPDATE_USER , TO_CHAR ( OL_TXN_DEPOSIT_EDIT_L\
OG . OTC_CREATE_TIMESTAMP , 'YYYY-MM-DD ");
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )84;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[0] = (unsigned long )17;
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
 if (sqlca.sqlcode < 0) goto dsichglog_sql_error;
}


	
	do {
	
		/* EXEC SQL FETCH c_cursor_getdepositchglog
		INTO
			:v_merchant_ref:ind_merchant_ref,
			:v_txn_id:ind_txn_id,
			:v_ccy:ind_ccy,
			:v_amt:ind_amt,
			:v_deposit_datetime:ind_deposit_datetime,
			:v_bank_code:ind_bank_code,
			:v_bank_name:ind_bank_name,
			:v_bank_acct_num:ind_bank_acct_num,
			:v_deposit_bank_code:ind_deposit_bank_code,
			:v_deposit_bank:ind_deposit_bank,
			:v_deposit_ref:ind_deposit_ref,
			:v_reason_edit:ind_reason_edit,
			:v_update_user:ind_update_user,
			:v_update_timestamp:ind_update_timestamp
		; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )111;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_merchant_ref;
  sqlstm.sqhstl[0] = (unsigned long )53;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_merchant_ref;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[1] = (unsigned long )19;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_txn_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_ccy;
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_ccy;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_amt;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_amt;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_deposit_datetime;
  sqlstm.sqhstl[4] = (unsigned long )23;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_deposit_datetime;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_bank_code;
  sqlstm.sqhstl[5] = (unsigned long )13;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_bank_code;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_bank_name;
  sqlstm.sqhstl[6] = (unsigned long )153;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_bank_name;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_bank_acct_num;
  sqlstm.sqhstl[7] = (unsigned long )53;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_bank_acct_num;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_deposit_bank_code;
  sqlstm.sqhstl[8] = (unsigned long )13;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_deposit_bank_code;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_deposit_bank;
  sqlstm.sqhstl[9] = (unsigned long )153;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_deposit_bank;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_deposit_ref;
  sqlstm.sqhstl[10] = (unsigned long )153;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_deposit_ref;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_reason_edit;
  sqlstm.sqhstl[11] = (unsigned long )33;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_reason_edit;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_update_user;
  sqlstm.sqhstl[12] = (unsigned long )23;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_update_user;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_update_timestamp;
  sqlstm.sqhstl[13] = (unsigned long )23;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_update_timestamp;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto dsichglog_sql_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}
		
		fprintf(fp,"<Row>\n");

/* merchant_ref */
		if(ind_merchant_ref >= 0)
		{
			v_merchant_ref.arr[v_merchant_ref.len] = '\0';
			strcpy(csTmp,(const char*)v_merchant_ref.arr);
//DEBUGLOG(("process_deposit_change_log merchant_ref = [%s]\n", v_merchant_ref.arr));
		}
		else
                {
                        strcpy(csTmp," ");
                }
                fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csTmp);

/* ccy */
		if (ind_ccy >= 0)
		{
			v_ccy.arr[v_ccy.len] = '\0';
			strcpy(csTmp,(const char*)v_ccy.arr);
//DEBUGLOG(("process_deposit_change_log ccy = [%s]\n", v_ccy.arr));
		}
		else
                {
                        strcpy(csTmp," ");
                }
                fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csTmp);
	
/* amt */
		if (ind_amt >= 0)
		{
			dTmp = v_amt;
			format_commas(dTmp, csTmp);
//DEBUGLOG(("process_deposit_change_log amt = [%f]\n",v_amt));
		}
		else
                {
                        strcpy(csTmp," ");
                }
                fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csTmp);

/* deposit_datetime */
                if (ind_deposit_datetime >= 0)
                {
                        v_deposit_datetime.arr[v_deposit_datetime.len] = '\0';
                        strcpy(csTmp,(const char*)v_deposit_datetime.arr);
//DEBUGLOG(("process_deposit_change_log deposit_datetime = [%s]\n", v_deposit_datetime.arr));
                }
		else
                {
                        strcpy(csTmp," ");
                }
                fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csTmp);

/* bank_name */
                if (ind_bank_name >= 0)
                {
                        v_bank_name.arr[v_bank_name.len] = '\0';
                        strcpy(csTmp,(const char*)v_bank_name.arr);
//DEBUGLOG(("process_deposit_change_log bank_name = [%s]\n", v_bank_name.arr));
                }
		else
                {
                        strcpy(csTmp," ");
                }
                fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csTmp);

/* bank_acct_num */
                if (ind_bank_acct_num >= 0)
                {
                        v_bank_acct_num.arr[v_bank_acct_num.len] = '\0';
                        strcpy(csTmp,(const char*)v_bank_acct_num.arr);
//DEBUGLOG(("process_deposit_change_log bank_acct_num = [%s]\n", v_bank_acct_num.arr));
                }
		else
                {
                        strcpy(csTmp," ");
                }
                fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csTmp);

/* deposit_bank */
                if (ind_deposit_bank >= 0)
                {
                        v_deposit_bank.arr[v_deposit_bank.len] = '\0';
                        strcpy(csTmp,(const char*)v_deposit_bank.arr);
//DEBUGLOG(("process_deposit_change_log deposit_bank = [%s]\n", v_deposit_bank.arr));
                }
                else
                {
                        strcpy(csTmp," ");
                }
                fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csTmp);

/* deposit_ref */
                if (ind_deposit_ref >= 0)
                {
                        v_deposit_ref.arr[v_deposit_ref.len] = '\0';
                        strcpy(csTmp,(const char*)v_deposit_ref.arr);
//DEBUGLOG(("process_deposit_change_log deposit_ref = [%s]\n", v_deposit_ref.arr));
                }
                else
		{
			strcpy(csTmp," ");
		}
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csTmp);

/* reason_edit */
                if (ind_reason_edit >= 0)
                {
                        v_reason_edit.arr[v_reason_edit.len] = '\0';
                        strcpy(csTmp,(const char*)v_reason_edit.arr);
//DEBUGLOG(("process_deposit_change_log reason_edit = [%s]\n", v_reason_edit.arr));*/
		}
                else
		{
			strcpy(csTmp," ");
		}		
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csTmp);

/* update_user */
                if (ind_update_user >= 0)
                {
                        v_update_user.arr[v_update_user.len] = '\0';
                        strcpy(csTmp,(const char*)v_update_user.arr);
//DEBUGLOG(("process_deposit_change_log update_user = [%s]\n", v_update_user.arr));
                }
                else
		{
			strcpy(csTmp," ");
		}		
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csTmp);		

/* update_timestamp */
                if (ind_update_timestamp >= 0)
                {
                        v_update_timestamp.arr[v_update_timestamp.len] = '\0';
                        strcpy(csTmp,(const char*)v_update_timestamp.arr);
//DEBUGLOG(("process_deposit_change_log update_timestamp = [%s]\n", v_update_timestamp.arr));
                }
                else
		{
			strcpy(csTmp," ");
		}
		fprintf(fp,"\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n",csTmp);		

		fprintf(fp,"</Row>\n");

	} while (PD_TRUE);
	
	/* EXEC SQL CLOSE c_cursor_getdepositchglog; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )182;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto dsichglog_sql_error;
}


		
	return iRet;

//DEBUGLOG(("process_deposit_change_log: Exit, iRet = [%d]\n", iRet));

dsichglog_sql_error:
DEBUGLOG(("extract_ol_deposit_chg_log_daily_rpt:process_deposit_change_log code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getdepositchglog; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )197;
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
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )212;
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
	int  iRet = PD_OK;
	char csTmpCmd[PD_TMP_BUF_LEN+1];

	
	sprintf(csTmpCmd, 
		"mkdir_ol_pregenrpt_tree.sh %s %s %s 1> /dev/null",		
		csYearMthDy, 
		getenv("OL_PREGEN_RPT_HOME"),
		PD_FILE_PREFIX);
	
	if (system(csTmpCmd) == PD_ERR)
	{
		iRet = PD_ERR;
	}

	return iRet;
}

char* getYYYY(const char* csTxnDate)
{
	static char csTmpYYYY[PD_YYYY_LEN+1];

	strncpy(csTmpYYYY, csTxnDate, PD_YYYY_LEN);
	csTmpYYYY[PD_YYYY_LEN] = '\0';

	return csTmpYYYY;
}

char* getYYYYMM(const char* csTxnDate)
{
	static char csTmpYYYYMM[PD_YYYYMM_LEN+1];

	strncpy(csTmpYYYYMM, csTxnDate, PD_YYYYMM_LEN);
	csTmpYYYYMM[PD_YYYYMM_LEN] = '\0';

	return csTmpYYYYMM;
}

int chkSpInMID(const char* csMerchantId)
{
	int iCnt;

	for (iCnt = 0; iCnt < strlen(csMerchantId); iCnt++)
		if (csMerchantId[iCnt] == 32)
			return PD_ERR;

	return PD_OK;
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
	strcpy(csInDate,"");
	strcpy(csInMerchantId,"");

	while ((c = getopt(argc,argv,"d:m:")) != EOF) {
		switch (c) {
			case 'd':
				strcpy(csInDate, optarg);
				break;
			case 'm':
				strcpy(csInMerchantId, optarg);
				break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(csInDate,""))
		return FAILURE;

	if (argc > 3) {
		if (!strcmp(csInMerchantId,""))
			return FAILURE;
	}

	return SUCCESS;
}

