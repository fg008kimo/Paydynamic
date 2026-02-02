
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
           char  filnam[39];
};
static struct sqlcxp sqlfpn =
{
    38,
    "extract_ol_poa_txn_detail_daily_rpt.pc"
};


static unsigned int sqlctx = 796096069;


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
   unsigned char  *sqhstv[22];
   unsigned long  sqhstl[22];
            int   sqhsts[22];
            short *sqindv[22];
            int   sqinds[22];
   unsigned long  sqharm[22];
   unsigned long  *sqharc[22];
   unsigned short  sqadto[22];
   unsigned short  sqtdso[22];
} sqlstm = {12,22};

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
"E_CODE_TXN ON DEF_SERVICE_CODE_TXN .\
 SC_CODE = OL_TXN_HEADER . OTH_SERVICE_CODE LEFT JOIN TXN_CODE ON TXN_CODE . \
TC_CODE = OL_TXN_HEADER . OTH_TXN_CODE LEFT JOIN DEF_SUB_STATUS ON DEF_SUB_ST\
ATUS . DS_SUB_STATUS = OL_TXN_HEADER . OTH_SUB_STATUS LEFT JOIN DEF_SUB_STATU\
S ACK_STATUS ON ACK_STATUS . DS_SUB_STATUS = OL_TXN_HEADER . OTH_ACK_STATUS L\
EFT JOIN OL_TXN_ELEMENTS TFEE ON OL_TXN_HEADER . OTH_TXN_ID = TFEE . OTE_TXN_\
ID AND TFEE . OTE_TXN_ELEMENT_TYPE = 'TFEE' AND TFEE . OTE_PARTY_TYPE = 'M' L\
EFT JOIN OL_TXN_DETAIL REFUND_PAYOUT ON REFUND_PAYOUT . OTD_TXN_ID = UFD . OU\
D_AUX_TXN_ID WHERE 1 = 1 AND ( UFD . OUD_DISABLED = 0 OR UFD . OUD_DISABLED I\
S NULL ) AND ( UFH . OUH_MERCHANT_ID = :b4 OR OL_TXN_HEADER . OTH_MERCHANT_ID\
 = :b4 ) ORDER BY UFD . OUD_CREATE_TIMESTAMP DESC , OL_TXN_HEADER . OTH_TXN_I\
D ASC , UFD . OUD_GENERATED_FILE_ID ASC , UFD . OUD_BATCH_ID ASC , UFD . OUD_\
SEQ_NUM ASC            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,78,0,9,146,0,2049,0,0,0,1,0,
20,0,0,1,0,0,13,150,0,0,1,0,0,1,0,2,9,0,0,
39,0,0,1,0,0,15,173,0,0,0,0,0,1,0,
54,0,0,1,0,0,15,184,0,0,0,0,0,1,0,
69,0,0,2,0,0,32,185,0,0,0,0,0,1,0,
84,0,0,3,6026,0,9,891,0,2049,6,6,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,
123,0,0,3,0,0,13,895,0,0,22,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,
2,9,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
226,0,0,3,0,0,15,1246,0,0,0,0,0,1,0,
241,0,0,3,0,0,15,1254,0,0,0,0,0,1,0,
256,0,0,4,0,0,32,1255,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2019. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description				Change Date	Change By
------------------------------------------	-------------	------------
Init Version					2020/01/20      [ZBL]
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include "batchcommon.h"
#include "common.h"
#include "dbutility.h"
#include "numutility.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "myhash.h"
#include "myrecordset.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define PD_REC_ENABLED	0
#define PD_FILE_PREFIX	"ol_poa_txn_detail"

static char	cDebug = 'Y';
char		csInDate[PD_DATE_LEN + 1];
char		csInMerchantId[PD_MERCHANT_ID_LEN + 1];

OBJPTR(DB);

char *	getYYYY(const char * csTxnDate);
char *	getYYYYMM(const char * csTxnDate);
int	chkSpInMID(const char* csMerchantId);
int	get_merchant_id(recordset_t * rMerchantId);
int	mkFullPathDir(const char * csYearMthDy);
int	parse_arg(int argc, char ** argv);
int	process_data(const char * csTxnDate);
int	process_single_acct(const char * csTxnDate, const char * csMerchantId);
int	process_payout_txn_detail(const char * csReportDate, const char * csMerchantId, FILE * fp);
void	format_commas(double dInNum, char * csOutNum);

int batch_init(int argc, char * argv[])
{
	if (argc < 3)
	{
		printf("usage: -d Date\n");
		return FAILURE;
	}
	else if (argc > 3 && argc < 5)
	{
		printf("usage: -d Date -m Merchant_ID\n");
		return FAILURE;
	}
	else
		return SUCCESS;
}

int batch_proc(int argc, char * argv[])
{
	int iRet;

	iRet = parse_arg(argc,argv);

	if (iRet != SUCCESS)
	{
		if (argc < 3)
			printf("usage: -d Date\n");
		else if (argc > 3 && argc < 5)
			printf("usage: -d Date -m Merchant_ID\n");

		return (iRet);
	}

	if (argc == 3)
		iRet = process_data(csInDate);
	else
		iRet = process_single_acct(csInDate, csInMerchantId);

	return iRet;
}

int batch_terminate(int argc, char * argv[])
{
	return SUCCESS;
}

char * getYYYY(const char * csTxnDate)
{
	static char csTmpYYYY[PD_YYYY_LEN + 1];

	strncpy(csTmpYYYY, csTxnDate, PD_YYYY_LEN);
	csTmpYYYY[PD_YYYY_LEN] = '\0';

	return csTmpYYYY;
}

char * getYYYYMM(const char * csTxnDate)
{
	static char csTmpYYYYMM[PD_YYYYMM_LEN + 1];

	strncpy(csTmpYYYYMM, csTxnDate, PD_YYYYMM_LEN);
	csTmpYYYYMM[PD_YYYYMM_LEN] = '\0';

	return csTmpYYYYMM;
}

int chkSpInMID(const char * csMerchantId)
{
	int iCnt;

	for (iCnt = 0; iCnt < strlen(csMerchantId); iCnt++)
		if (csMerchantId[iCnt] == 32)
			return PD_ERR;

	return PD_OK;
}

int get_merchant_id(recordset_t * rMerchantId)
{
	int	 iCnt = 0;
	hash_t * myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;


		short	ind_merchant_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	/* EXEC SQL DECLARE c_cursor_getolmerchdetail CURSOR FOR
		SELECT MD_MERCHANT_ID 
		FROM OL_MERCH_DETAIL 
		ORDER BY MD_MERCHANT_ID; */ 


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



	do
	{
		/* EXEC SQL FETCH c_cursor_getolmerchdetail
		INTO
			:v_merchant_id:ind_merchant_id; */ 

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



		if (SQLCODE == SQL_NOT_FOUND)
			break;

		myHash = (hash_t *)malloc(sizeof(hash_t));
		hash_init(myHash, 0);

		iCnt++;

		/* merchant_id */
		if (ind_merchant_id >= 0)
		{
			v_merchant_id.arr[v_merchant_id.len] = '\0';
			PutField_CString(myHash, "merchant_id", (const char *)v_merchant_id.arr);
		}

		RecordSet_Add(rMerchantId, myHash);

	} while(PD_TRUE);

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



	if (iCnt > 0)
		return PD_OK;
	else
		return PD_ERR;

sql_error:
DEBUGLOG(("extract_ol_poa_txn_detail_daily_rpt::get_merchant_id: error code %d\n", sqlca.sqlcode));
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
		iRet = PD_ERR;

	return iRet;
}

int parse_arg(int argc, char ** argv)
{
	char c;

	strcpy(csInDate, "");
	strcpy(csInMerchantId, "");

	while ((c = getopt(argc, argv,"d:m:")) != EOF)
	{
		switch (c)
		{
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

	if (!strcmp(csInDate, ""))
		return FAILURE;

	if (argc > 3)
	{
		if (!strcmp(csInMerchantId, ""))
			return FAILURE;
	}

	return SUCCESS;
}

int process_data(const char * csTxnDate)
{
	int		iCnt = 0;
	int		iDtlRet = PD_OK;
	int		iRet = SUCCESS;
	hash_t *	hMerchantId = NULL;
	recordset_t *	rMerchantId;

	rMerchantId = (recordset_t *)malloc(sizeof(recordset_t));
	recordset_init(rMerchantId, 0);

DEBUGLOG(("start\n"));

	iDtlRet = get_merchant_id(rMerchantId);

	if (iDtlRet == PD_OK)
	{
		hMerchantId = RecordSet_GetFirst(rMerchantId);

		while ((iRet == SUCCESS) && (hMerchantId))
		{
			char * csMerchantId = NULL;

DEBUGLOG(("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"));
DEBUGLOG(("record = [%d]\n", iCnt));

			/* merchant_id */
			if (GetField_CString(hMerchantId, "merchant_id", &csMerchantId))
				iRet = process_single_acct(csTxnDate, csMerchantId);
			else
				iRet = FAILURE;

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

int process_single_acct(const char * csTxnDate, const char * csMerchantId)
{
	char	 csTmpCmd[PD_TMP_BUF_LEN + 1];
	char	 csUploadFilename[PD_UPLOAD_FILENAME_LEN + 1];
	char	 csUploadFullFile[PD_PATH_LEN + 1];
	char	 csYear[PD_YYYY_LEN + 1];
	char	 csYearMth[PD_YYYYMM_LEN + 1];
	int	 iDtlRet = PD_OK;
	int	 iRet = SUCCESS;
	FILE *   fp;
	hash_t * hPayoutTxnDetail;

	hPayoutTxnDetail = (hash_t *)malloc(sizeof(hash_t));
	hash_init(hPayoutTxnDetail, 0);
 
	/* report_code */
 	PutField_CString(hPayoutTxnDetail, "report_code", PD_OL_PAYOUT_TXN_DETAIL_REPORT_CODE);
DEBUGLOG(("report_code = [%s]\n", PD_OL_PAYOUT_TXN_DETAIL_REPORT_CODE));

	/* disabled*/
	PutField_Int(hPayoutTxnDetail, "disabled", PD_REC_ENABLED);
DEBUGLOG(("disabled = [%d]\n", PD_REC_ENABLED));

	/* report_date */
	if (strlen(csTxnDate) > 0)
	{
		PutField_CString(hPayoutTxnDetail, "report_date", csTxnDate);
DEBUGLOG(("report_date = [%s]\n", csTxnDate));
	}

	/* merchant_id */
	if (strlen(csMerchantId) > 0)
	{
		PutField_CString(hPayoutTxnDetail, "merchant_id", csMerchantId);
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

	PutField_CString(hPayoutTxnDetail, "filename", csUploadFilename);
DEBUGLOG(("file_prefix = [%s]\n", PD_FILE_PREFIX));
DEBUGLOG(("filename = [%s]\n", csUploadFilename));

	/* Addition field Update_user */
	PutField_CString(hPayoutTxnDetail, "user", PD_UPDATE_USER);

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
		getenv("OL_PREGEN_RPT_HOME"), 
		PD_FILE_PREFIX, 
		csYear, 
		csYearMth, 
		csTxnDate, 
		PD_FILE_PREFIX, 
		csMerchantId, 
		csTxnDate);

DEBUGLOG(("full_filename = [%s]\n", csUploadFullFile));

	fp = fopen(csUploadFullFile, "w");

	if (fp == NULL)
	{
DEBUGLOG(("process_data:unable to open [%s]\n", csUploadFullFile));
		return FAILURE;
	}

	/* Create xml header */
	fprintf(fp, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
	fprintf(fp, "<?mso-application progid=\"Excel.Sheet\"?>\n");
	fprintf(fp, "<Workbook xmlns=\"urn:schemas-microsoft-com:office:spreadsheet\"\n");
	fprintf(fp, "\txmlns:o=\"urn:schemas-microsoft-com:office:office\"\n");
	fprintf(fp, "\t xmlns:x=\"urn:schemas-microsoft-com:office:excel\"\n");
	fprintf(fp, "\t xmlns:ss=\"urn:schemas-microsoft-com:office:spreadsheet\"\n");
	fprintf(fp, "\t xmlns:html=\"http://www.w3.org/TR/REC-html40\">\n");
	fprintf(fp, "<Styles>\n");
	fprintf(fp, "\t<Style ss:ID=\"shd\">\n");
	fprintf(fp, "\t\t<ss:Font ss:Bold=\"1\"/>\n");
	fprintf(fp, "\t\t<Alignment ss:Horizontal=\"Center\" ss:Vertical=\"Center\"/>\n");
	fprintf(fp, "\t</Style>\n");
	fprintf(fp, "\t<Style ss:ID=\"sdt\">\n");
	fprintf(fp, "\t\t<NumberFormat ss:Format=\"yyyy-mm-dd hh:mm:ss\"/>\n");
	fprintf(fp, "\t</Style>\n");
	fprintf(fp, "</Styles>\n");
	fprintf(fp, "<Worksheet ss:Name=\"Payout Transaction Detail\">\n");
	fprintf(fp, "<Table>\n");

	/* Create payout transaction detail txn header */
	fprintf(fp,"<Row>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Seq. No.</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Transaction ID</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Country</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Service</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Reference</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Bank Name</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Bank Account Number</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Bank Account Name</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant File Name</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Request Amount Currency</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Request Amount</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Payable Amount Currency</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Payable Amount</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Consumer Received Amount Currency</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Consumer Received Amount</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Paid Amount Currency</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Paid Amount</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Payout Request Status</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Create Timestamp</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Approval Timestamp</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Last Update Timestamp</Data></Cell>\n");
//	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Request Timestamp</Data></Cell>\n");
//	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Request Channel</Data></Cell>\n");
//	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Callback Status</Data></Cell>\n");
//	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Payout Group</Data></Cell>\n");
	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Remark</Data></Cell>\n");
//	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">Merchant Remark</Data></Cell>\n");
//	fprintf(fp,"\t<Cell><Data ss:Type=\"String\">System Remark</Data></Cell>\n");
	fprintf(fp,"</Row>\n");

	/* Process payout transaction detail data */
	iDtlRet = process_payout_txn_detail(csTxnDate, csMerchantId, fp);

	if (iDtlRet == PD_OK)
	{
		/* Addition field Status */
		PutField_Char(hPayoutTxnDetail, "status", PD_PREGEN_RPT_COMPLETED);
DEBUGLOG(("status = [%c]\n", PD_PREGEN_RPT_COMPLETED));
DEBUGLOG(("process_payout_txn_detail: success\n"));
	}
	else
	{
		/* Addition field Status */
		PutField_Char(hPayoutTxnDetail, "status", PD_PREGEN_RPT_FAILURE);
DEBUGLOG(("status = [%c]\n", PD_PREGEN_RPT_FAILURE));
DEBUGLOG(("process_payout_txn_detail: fail\n"));

		iRet = FAILURE;
	}

	/* Create xml footer */
	fprintf(fp, "</Table>\n");
	fprintf(fp, "</Worksheet>\n");
	fprintf(fp, "</Workbook>\n");

	fclose(fp);

	/* Zip the report */
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

	/* ChkExist insert / update ol_pregen_daily_report */
	DBObjPtr = CreateObj(DBPtr, "DBOLPregenDailyReport", "ChkExist");
	iDtlRet = (unsigned long)(DBObjPtr)(hPayoutTxnDetail);

	if (iDtlRet > 0)
	{
		DBObjPtr = CreateObj(DBPtr, "DBOLPregenDailyReport", "UpdateStatus");
		iDtlRet = (unsigned long)(DBObjPtr)(hPayoutTxnDetail);

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
		DBObjPtr = CreateObj(DBPtr, "DBOLPregenDailyReport", "Add");
		iDtlRet = (unsigned long)(DBObjPtr)(hPayoutTxnDetail);

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

	if (hPayoutTxnDetail)
	{
		hash_destroy(hPayoutTxnDetail);
		FREE_ME(hPayoutTxnDetail);
	}

	return iRet;
}

int process_payout_txn_detail(const char * csReportDate, const char * csMerchantId, FILE * fp)
{
	int	iRet = PD_OK;
	char	csTxnId[PD_TXN_SEQ_LEN + 1];
	char	csCountry[PD_COUNTRY_NAME_LEN + 1];
	char	csService[PD_SERVICE_DESC_LEN + 1];
	char	csMerchantRef[PD_MERCHANT_REF_LEN + 1];
	char	csBankName[PD_AC_BANK_NAME_LEN + 1];
	char	csBankAcctNo[PD_AC_NO_LEN + 1];
	char	csBankAcctName[PD_AC_NAME_LEN + 1];
	char	csMerchantFileName[PD_SCRIPT_NAME_LEN + 1];
	char	csMerchantReqAmtCcy[PD_CCY_ID_LEN + 1];
	char	csMerchantPayableAmtCcy[PD_CCY_ID_LEN + 1];
	char	csConsumerRecvAmtCcy[PD_CCY_ID_LEN + 1];
	char	csMerchantPaidAmtCcy[PD_CCY_ID_LEN + 1];
	char	csStatus[PD_DESC_LEN + 1];
	char	csCreateTimestamp[PD_TIMESTAMP_LEN + 1];
	char	csApprovalTimestamp[PD_TIMESTAMP_LEN + 1];
	char	csLastUpdateTimestamp[PD_TIMESTAMP_LEN + 1];
//	char	csMerchantReqTimestamp[PD_TIMESTAMP_LEN + 1];
//	char	csReqChannel[PD_REQ_CHANNEL_LEN + 1];
//	char	csCallbackStatus[PD_STATUS_DESC_LEN + 1];
	char	csRemark[PD_REMARK_LEN + 1];
//	char	csPayoutRemark[PD_REMARK_LEN + 1];
//	char	csSystemRemark[PD_REMARK_LEN + 1];
	char	csTmp[PD_TMP_BUF_LEN + 1];
	double	dMerchantReqAmt;
	double	dMerchantPayableAmt;
	double	dConsumerRecvAmtCcy;
	double	dMerchantPaidAmt;

	/* EXEC SQL WHENEVER SQLERROR GOTO poatxndetail_sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

  
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	hv_report_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_report_date;


		int	v_seq_no;
		/* varchar	v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar	v_country[PD_COUNTRY_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_country;

		/* varchar	v_service[PD_SERVICE_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_service;

		/* varchar	v_merchant_ref[PD_MERCHANT_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar v_bank_name[PD_AC_BANK_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

		/* varchar	v_bank_acct_no[PD_AC_NO_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_bank_acct_no;

		/* varchar	v_bank_acct_name[PD_AC_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_bank_acct_name;

		/* varchar	v_merchant_file_name[PD_SCRIPT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_file_name;

		/* varchar	v_merchant_req_amt_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_merchant_req_amt_ccy;

		double	v_merchant_req_amt;
		/* varchar	v_merchant_payable_amt_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_merchant_payable_amt_ccy;

		double	v_merchant_payable_amt;
		/* varchar	v_consumer_recv_amt_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_consumer_recv_amt_ccy;

		double	v_consumer_recv_amt;
		/* varchar	v_merchant_paid_amt_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_merchant_paid_amt_ccy;

		double	v_merchant_paid_amt;
		/* varchar	v_status[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_status;

		/* varchar	v_create_timestamp[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_create_timestamp;

		/* varchar	v_approval_timestamp[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_approval_timestamp;

		/* varchar	v_last_update_timestamp[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_last_update_timestamp;

//		varchar	v_merchant_req_timestamp[PD_TIMESTAMP_LEN + 1];
//		varchar	v_req_channel[PD_REQ_CHANNEL_LEN + 1];
//		varchar	v_callback_status[PD_STATUS_DESC_LEN + 1];
//		char	v_merchant_group;
		/* varchar	v_remark[PD_REMARK_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;

//		varchar	v_payout_remark[PD_REMARK_LEN + 1];
//		varchar	v_system_remark[PD_REMARK_LEN + 1];
		
		short	ind_seq_no = -1;
		short	ind_txn_id = -1;
		short	ind_merchant_ref = -1;
		short	ind_country = -1;
		short	ind_service = -1;
		short	ind_bank_name = -1;
		short	ind_bank_acct_no = -1;
		short	ind_bank_acct_name = -1;
		short	ind_merchant_file_name = -1;
		short	ind_merchant_req_amt_ccy = -1;
		short	ind_merchant_req_amt = -1;
		short	ind_merchant_payable_amt_ccy = -1;
		short	ind_merchant_payable_amt = -1;
		short	ind_consumer_recv_amt_ccy = -1;
		short	ind_consumer_recv_amt = -1;
		short	ind_merchant_paid_amt_ccy = -1;
		short	ind_merchant_paid_amt = -1;
		short	ind_status = -1;
		short	ind_create_timestamp = -1;
		short	ind_approval_timestamp = -1;
		short	ind_last_update_timestamp = -1;
//		short	ind_merchant_req_timestamp = -1;
//		short	ind_upload_channel = -1;
//		short	ind_callback_status = -1;
//		short	ind_merchant_group = -1;
		short	ind_remark = -1;
//		short	ind_payout_remark = -1;
//		short	ind_system_remark = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("process_payout_txn_detail:Begin\n"));

	if (strlen(csReportDate) > 0)
	{
		hv_report_date.len = strlen(csReportDate);
		strncpy((char *)hv_report_date.arr, csReportDate, hv_report_date.len);
DEBUGLOG(("process_payout_txn_detail:report_date = [%.*s]\n", hv_report_date.len, hv_report_date.arr));
	}
	else
	{
DEBUGLOG(("process_payout_txn_detail:report_date is missing\n"));
ERRLOG("extract_ol_poa_txn_detail_daily_rpt::process_payout_txn_detail: report_date is missing\n");
		return PD_ERR;
	}

	if(strlen(csMerchantId) > 0)
	{
		hv_merchant_id.len = strlen(csMerchantId);
		strncpy((char *)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
DEBUGLOG(("process_payout_txn_detail:merchant_id = [%.*s]\n", hv_merchant_id.len, hv_merchant_id.arr));
	}
	else
	{
DEBUGLOG(("process_payout_txn_detail:merchant_id is missing\n"));
ERRLOG("extract_ol_poa_txn_detail_daily_rpt::process_payout_txn_detail: merchant_id is missing\n");
		return PD_ERR;
	}

	/* EXEC SQL DECLARE c_cursor_getpoatxndetail CURSOR FOR
		SELECT	OUD_SEQ_NUM AS SEQ_NO, 
			OUD_TXN_ID AS TXN_ID, 
			CASE
				WHEN COUNTRY.COUNTRY_NAME IS NOT NULL
				THEN
					COUNTRY.COUNTRY_NAME
				ELSE
					COUNTRY_TXN.COUNTRY_NAME
			END AS COUNTRY, 
			CASE
				WHEN DEF_SERVICE_CODE.SC_DESC IS NOT NULL
				THEN
					DEF_SERVICE_CODE.SC_DESC
				ELSE
					DEF_SERVICE_CODE_TXN.SC_DESC
			END AS SERVICE, 
			CASE
				WHEN OUD_MERCHANT_REF IS NOT NULL
				THEN
					OUD_MERCHANT_REF
				ELSE
					OL_TXN_HEADER.OTH_MERCHANT_REF
			END AS MERCHANT_REF, 
			CASE
				WHEN OUD_BANK_NAME IS NOT NULL
				THEN
					OUD_BANK_NAME
				ELSE
					OL_TXN_DETAIL.OTD_BANK_NAME
			END AS BANK_NAME, 
			CASE
				WHEN OUD_ACCOUNT_NUM IS NOT NULL
				THEN
					OUD_ACCOUNT_NUM
				ELSE
					OL_TXN_DETAIL.OTD_ACCOUNT_ID
			END AS BANK_ACCT_NO, 
			CASE
				WHEN OUD_ACCOUNT_NAME IS NOT NULL
				THEN
					OUD_ACCOUNT_NAME
				ELSE
					OL_TXN_DETAIL.OTD_ACCOUNT_NAME
			END AS BANK_ACCT_NAME, 
			OUH_FILENAME AS MERCHANT_FILE_NAME, 
			OUD_REQUEST_CURRENCY AS MERCHANT_REQ_AMT_CCY, 
			OUD_REQUEST_AMOUNT AS MERCHANT_REQ_AMT, 
			OUD_PAYOUT_CURRENCY AS MERCHANT_PAYABLE_AMT_CCY, 
			OUD_PAYOUT_AMOUNT AS MERCHANT_PAYABLE_AMT, 
			OUD_PAYOUT_CURRENCY AS CONSUMER_RECV_AMT_CCY, 
			OUD_PAYOUT_AMOUNT AS CONSUMER_RECV_AMT, 
			OL_TXN_HEADER.OTH_NET_CCY AS MERCHANT_PAID_AMT_CCY, 
			NVL (OL_TXN_HEADER.OTH_NET_AMOUNT, 0) - NVL (TFEE.OTE_AMOUNT, 0) AS MERCHANT_PAID_AMT, 
			DEF_PAYOUT_BATCH_STATUS.DP_MERCHANT_DESC AS STATUS, 
			TO_CHAR(OUD_CREATE_TIMESTAMP, 'YYYY-MM-DD HH24:MI:SS') AS CREATE_TIMESTAMP, 
			TO_CHAR(OL_TXN_HEADER.OTH_APPROVAL_TIMESTAMP, 'YYYY-MM-DD HH24:MI:SS') AS APPROVAL_TIMESTAMP, 
			TO_CHAR(OUD_UPDATE_TIMESTAMP, 'YYYY-MM-DD HH24:MI:SS') AS LAST_UPDATE_TIMESTAMP,  
//			TO_CHAR(TO_DATE(OL_TXN_HEADER.OTH_TRANSMISSION_DATETIME, 'YYYYMMDDHH24MISS'), 'YYYY-MM-DD HH24:MI:SS') AS MERCHANT_REQ_TIMESTAMP, 
/o			CASE
				WHEN OL_TXN_HEADER.OTH_UPLOAD_CHANNEL = 1
				THEN
					'API'
				ELSE
					'FILE UPLOAD'
			END AS REQ_CHANNEL, 
			ACK_STATUS.DS_NAME AS CALLBACK_STATUS, 
			OUD_MERCHANT_PAYOUT_GRP AS PAYOUT_GROUP, 
			OL_TXN_DETAIL.OTD_REMARK AS PAYOUT_REMARK, 
			REFUND_PAYOUT.OTD_REMARK AS SYSTEM_REMARK
o/
			OUD_REMARK AS REMARK
		FROM (
			SELECT	OUD_BATCH_ID, 
				OUD_TXN_ID, 
				OUD_AUX_TXN_ID, 
				OUD_SEQ_NUM, 
				OUD_MERCHANT_REF, 
				OUD_COUNTRY, 
				OUD_IDENTITY_ID, 
				OUD_ACCOUNT_NUM, 
				OUD_ACCOUNT_NAME, 
				OUD_BANK_NAME, 
				OUD_BANK_CODE, 
				OUD_BRANCH, 
				OUD_PHONE_NUM, 
				OUD_PROVINCE, 
				OUD_CITY, 
				OUD_PAYOUT_AMOUNT, 
				OUD_REQUEST_AMOUNT, 
				OUD_PAYOUT_CURRENCY, 
				OUD_REQUEST_CURRENCY, 
				OUD_MEMBER_FEE_CCY, 
				OUD_MEMBER_FEE, 
				OUD_MERCHANT_FEE_CCY, 
				OUD_MERCHANT_FEE, 
				OUD_MARKUP_CCY, 
				OUD_MARKUP_AMT, 
				OUD_EXCHANGE_RATE, 
				OUD_PAYOUT_TXN_NUM, 
				OUD_STATUS, 
				OUD_RESPONSE_CODE, 
				OUD_REMARK, 
				OUD_DISABLED, 
				OUD_BATCH_MODE, 
				OUD_GENERATED_FILE_ID, 
				OUD_GENERATED_FILE_NAME, 
				OUD_PSP_BATCH_ID, 
				OUD_FUNDOUT_DATE, 
				OUD_SERVICE_FEE, 
				OUD_TID, 
				OUD_PSP_ID, 
				OUD_APPROVE_ID, 
				OUD_VNC_REF_NUM, 
				OUD_PREGEN_PSP_ID, 
				OUD_PREGEN_FILE_ID, 
				OUD_PREAPPROVE_ID, 
				OUD_CREATE_TIMESTAMP, 
				OUD_UPDATE_TIMESTAMP, 
				OUD_UPDATE_USER, 
				OUD_CREATE_USER, 
				OUD_MERCHANT_PAYOUT_GRP, 
				OUD_PSP_PAYOUT_GRP, 
				OUD_PREGEN_BANK_CODE 
			FROM OL_MERCHANT_UPLOAD_FILE_DETAIL 
			WHERE 1 = 1 
				AND OUD_CREATE_TIMESTAMP >= TO_DATE(:hv_report_date, 'YYYY-MM-DD HH24:MI') 
				AND OUD_CREATE_TIMESTAMP < TO_DATE(:hv_report_date, 'YYYY-MM-DD HH24:MI') + 1
			UNION ALL 
			SELECT	NULL			AS OUD_BATCH_ID, 
				OPR_TXN_ID		AS OUD_TXN_ID, 
				OPR_AUX_TXN_ID		AS OUD_AUX_TXN_ID, 
				NULL			AS OUD_SEQ_NUM, 
				NULL			AS OUD_MERCHANT_REF, 
				NULL			AS OUD_COUNTRY, 
				NULL			AS OUD_IDENTITY_ID, 
				NULL			AS OUD_ACCOUNT_NUM, 
				NULL			AS OUD_ACCOUNT_NAME, 
				NULL			AS OUD_BANK_NAME, 
				NULL			AS OUD_BANK_CODE, 
				NULL			AS OUD_BRANCH, 
				NULL			AS OUD_PHONE_NUM, 
				NULL			AS OUD_PROVINCE, 
				NULL			AS OUD_CITY, 
				OPR_PAYOUT_AMOUNT	AS OUD_PAYOUT_AMOUNT, 
				OPR_REQUEST_AMOUNT	AS OUD_REQUEST_AMOUNT, 
				OPR_PAYOUT_CURRENCY	AS OUD_PAYOUT_CURRENCY, 
				OPR_REQUEST_CURRENCY	AS OUD_REQUEST_CURRENCY, 
				OPR_MEMBER_FEE_CCY	AS OUD_MEMBER_FEE_CCY, 
				OPR_MEMBER_FEE		AS OUD_MEMBER_FEE, 
				OPR_MERCHANT_FEE_CCY	AS OUD_MERCHANT_FEE_CCY, 
				OPR_MERCHANT_FEE	AS OUD_MERCHANT_FEE, 
				OPR_MARKUP_CCY		AS OUD_MARKUP_CCY, 
				OPR_MARKUP_AMT		AS OUD_MARKUP_AMT, 
				NULL			AS OUD_EXCHANGE_RATE, 
				NULL			AS OUD_PAYOUT_TXN_NUM, 
				OPR_STATUS		AS OUD_STATUS, 
				NULL			AS OUD_RESPONSE_CODE, 
				NULL			AS OUD_REMARK, 
				NULL			AS OUD_DISABLED, 
				NULL			AS OUD_BATCH_MODE, 
				OPR_GENERATED_FILE_ID	AS OUD_GENERATED_FILE_ID, 
				NULL			AS OUD_GENERATED_FILE_NAME, 
				NULL			AS OUD_PSP_BATCH_ID, 
				NULL			AS OUD_FUNDOUT_DATE, 
				NULL			AS OUD_SERVICE_FEE, 
				NULL			AS OUD_TID, 
				OPR_PSP_ID		AS OUD_PSP_ID, 
				NULL			AS OUD_APPROVE_ID, 
				NULL			AS OUD_VNC_REF_NUM, 
				NULL			AS OUD_PREGEN_PSP_ID, 
				NULL			AS OUD_PREGEN_FILE_ID, 
				NULL			AS OUD_PREAPPROVE_ID, 
				OPR_CREATE_TIMESTAMP	AS OUD_CREATE_TIMESTAMP, 
				OPR_UPDATE_TIMESTAMP	AS OUD_UPDATE_TIMESTAMP, 
				OPR_UPDATE_USER		AS OUD_UPDATE_USER, 
				OPR_CREATE_USER		AS OUD_CREATE_USER, 
				OPR_MERCHANT_PAYOUT_GRP	AS OUD_MERCHANT_PAYOUT_GRP, 
				OPR_PSP_PAYOUT_GRP	AS OUD_PSP_PAYOUT_GRP, 
				NULL			AS OUD_PREGEN_BANK_CODE
			FROM OL_PAYOUT_REQUEST 
			WHERE 1 = 1
				AND OPR_CREATE_TIMESTAMP >= TO_DATE(:hv_report_date, 'YYYY-MM-DD HH24:MI')
				AND OPR_CREATE_TIMESTAMP < TO_DATE(:hv_report_date, 'YYYY-MM-DD HH24:MI') + 1
			) UFD
		LEFT JOIN OL_TXN_HEADER 
			ON OL_TXN_HEADER.OTH_TXN_ID = UFD.OUD_TXN_ID 
		LEFT JOIN OL_TXN_DETAIL 
			ON OL_TXN_DETAIL.OTD_TXN_ID = OL_TXN_HEADER.OTH_TXN_ID 
		LEFT JOIN OL_MERCHANT_UPLOAD_FILE_HEADER UFH 
			ON UFH.OUH_BATCH_ID = UFD.OUD_BATCH_ID 
		LEFT JOIN DEF_PAYOUT_BATCH_STATUS 
			ON DEF_PAYOUT_BATCH_STATUS.DP_STATUS_ID = UFD.OUD_STATUS 
		LEFT JOIN COUNTRY 
			ON COUNTRY.COUNTRY_CODE = UFD.OUD_COUNTRY 
		LEFT JOIN COUNTRY COUNTRY_TXN 
			ON COUNTRY_TXN.COUNTRY_CODE = OL_TXN_DETAIL.OTD_TXN_COUNTRY 
		LEFT JOIN DEF_SERVICE_CODE 
			ON DEF_SERVICE_CODE.SC_CODE = UFH.OUH_SERVICE_CODE 
		LEFT JOIN DEF_SERVICE_CODE DEF_SERVICE_CODE_TXN 
			ON DEF_SERVICE_CODE_TXN.SC_CODE = OL_TXN_HEADER.OTH_SERVICE_CODE 
		LEFT JOIN TXN_CODE 
			ON TXN_CODE.TC_CODE = OL_TXN_HEADER.OTH_TXN_CODE 
		LEFT JOIN DEF_SUB_STATUS 
			ON DEF_SUB_STATUS.DS_SUB_STATUS = OL_TXN_HEADER.OTH_SUB_STATUS 
		LEFT JOIN DEF_SUB_STATUS ACK_STATUS 
			ON ACK_STATUS.DS_SUB_STATUS = OL_TXN_HEADER.OTH_ACK_STATUS 
		LEFT JOIN OL_TXN_ELEMENTS TFEE 
			ON OL_TXN_HEADER.OTH_TXN_ID = TFEE.OTE_TXN_ID 
				AND TFEE.OTE_TXN_ELEMENT_TYPE = 'TFEE' 
				AND TFEE.OTE_PARTY_TYPE = 'M' 
		LEFT JOIN OL_TXN_DETAIL REFUND_PAYOUT 
			ON REFUND_PAYOUT.OTD_TXN_ID = UFD.OUD_AUX_TXN_ID 
		WHERE 1 = 1 
			AND (UFD.OUD_DISABLED = 0 OR UFD.OUD_DISABLED IS NULL) 
			AND (UFH.OUH_MERCHANT_ID = :hv_merchant_id OR OL_TXN_HEADER.OTH_MERCHANT_ID = :hv_merchant_id) 
		ORDER BY UFD.OUD_CREATE_TIMESTAMP DESC, 
			OL_TXN_HEADER.OTH_TXN_ID ASC, 
			UFD.OUD_GENERATED_FILE_ID ASC, 
			UFD.OUD_BATCH_ID ASC, 
			UFD.OUD_SEQ_NUM ASC; */ 


	/* EXEC SQL OPEN c_cursor_getpoatxndetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "SELECT OUD_SEQ_NUM AS SEQ_NO , OUD_TXN_ID AS TXN_ID , CASE WHEN COUNTRY \
. COUNTRY_NAME IS NOT NULL THEN COUNTRY . COUNTRY_NAME ELSE COUNTRY_TXN . CO\
UNTRY_NAME END AS COUNTRY , CASE WHEN DEF_SERVICE_CODE . SC_DESC IS NOT NULL\
 THEN DEF_SERVICE_CODE . SC_DESC ELSE DEF_SERVICE_CODE_TXN . SC_DESC END AS \
SERVICE , CASE WHEN OUD_MERCHANT_REF IS NOT NULL THEN OUD_MERCHANT_REF ELSE \
OL_TXN_HEADER . OTH_MERCHANT_REF END AS MERCHANT_REF , CASE WHEN OUD_BANK_NA\
ME IS NOT NULL THEN OUD_BANK_NAME ELSE OL_TXN_DETAIL . OTD_BANK_NAME END AS \
BANK_NAME , CASE WHEN OUD_ACCOUNT_NUM IS NOT NULL THEN OUD_ACCOUNT_NUM ELSE \
OL_TXN_DETAIL . OTD_ACCOUNT_ID END AS BANK_ACCT_NO , CASE WHEN OUD_ACCOUNT_N\
AME IS NOT NULL THEN OUD_ACCOUNT_NAME ELSE OL_TXN_DETAIL . OTD_ACCOUNT_NAME \
END AS BANK_ACCT_NAME , OUH_FILENAME AS MERCHANT_FILE_NAME , OUD_REQUEST_CUR\
RENCY AS MERCHANT_REQ_AMT_CCY , OUD_REQUEST_AMOUNT AS MERCHANT_REQ_AMT , OUD\
_PAYOUT_CURRENCY AS MERCHANT_PAYABLE_AMT_CCY , OUD_PAYOUT_AMOUNT AS MERCHANT\
_PAYABLE_AMT , OUD_PAYOUT_CURRENCY AS CO");
 sqlbuft((void **)0,
   "NSUMER_RECV_AMT_CCY , OUD_PAYOUT_AMOUNT AS CONSUMER_RECV_AMT , OL_TXN_HE\
ADER . OTH_NET_CCY AS MERCHANT_PAID_AMT_CCY , NVL ( OL_TXN_HEADER . OTH_NET_\
AMOUNT , 0 ) - NVL ( TFEE . OTE_AMOUNT , 0 ) AS MERCHANT_PAID_AMT , DEF_PAYO\
UT_BATCH_STATUS . DP_MERCHANT_DESC AS STATUS , TO_CHAR ( OUD_CREATE_TIMESTAM\
P , 'YYYY-MM-DD HH24:MI:SS' ) AS CREATE_TIMESTAMP , TO_CHAR ( OL_TXN_HEADER \
. OTH_APPROVAL_TIMESTAMP , 'YYYY-MM-DD HH24:MI:SS' ) AS APPROVAL_TIMESTAMP ,\
 TO_CHAR ( OUD_UPDATE_TIMESTAMP , 'YYYY-MM-DD HH24:MI:SS' ) AS LAST_UPDATE_T\
IMESTAMP , OUD_REMARK AS REMARK FROM ( SELECT OUD_BATCH_ID , OUD_TXN_ID , OU\
D_AUX_TXN_ID , OUD_SEQ_NUM , OUD_MERCHANT_REF , OUD_COUNTRY , OUD_IDENTITY_I\
D , OUD_ACCOUNT_NUM , OUD_ACCOUNT_NAME , OUD_BANK_NAME , OUD_BANK_CODE , OUD\
_BRANCH , OUD_PHONE_NUM , OUD_PROVINCE , OUD_CITY , OUD_PAYOUT_AMOUNT , OUD_\
REQUEST_AMOUNT , OUD_PAYOUT_CURRENCY , OUD_REQUEST_CURRENCY , OUD_MEMBER_FEE\
_CCY , OUD_MEMBER_FEE , OUD_MERCHANT_FEE_CCY , OUD_MERCHANT_FEE , OUD_MARKUP\
_CCY , OUD_MARKUP_AMT , OUD_EXCHANGE_RAT");
 sqlbuft((void **)0,
   "E , OUD_PAYOUT_TXN_NUM , OUD_STATUS , OUD_RESPONSE_CODE , OUD_REMARK , O\
UD_DISABLED , OUD_BATCH_MODE , OUD_GENERATED_FILE_ID , OUD_GENERATED_FILE_NA\
ME , OUD_PSP_BATCH_ID , OUD_FUNDOUT_DATE , OUD_SERVICE_FEE , OUD_TID , OUD_P\
SP_ID , OUD_APPROVE_ID , OUD_VNC_REF_NUM , OUD_PREGEN_PSP_ID , OUD_PREGEN_FI\
LE_ID , OUD_PREAPPROVE_ID , OUD_CREATE_TIMESTAMP , OUD_UPDATE_TIMESTAMP , OU\
D_UPDATE_USER , OUD_CREATE_USER , OUD_MERCHANT_PAYOUT_GRP , OUD_PSP_PAYOUT_G\
RP , OUD_PREGEN_BANK_CODE FROM OL_MERCHANT_UPLOAD_FILE_DETAIL WHERE 1 = 1 AN\
D OUD_CREATE_TIMESTAMP >= TO_DATE ( :b0 , 'YYYY-MM-DD HH24:MI' ) AND OUD_CRE\
ATE_TIMESTAMP < TO_DATE ( :b0 , 'YYYY-MM-DD HH24:MI' ) + 1 UNION ALL SELECT \
NULL AS OUD_BATCH_ID , OPR_TXN_ID AS OUD_TXN_ID , OPR_AUX_TXN_ID AS OUD_AUX_\
TXN_ID , NULL AS OUD_SEQ_NUM , NULL AS OUD_MERCHANT_REF , NULL AS OUD_COUNTR\
Y , NULL AS OUD_IDENTITY_ID , NULL AS OUD_ACCOUNT_NUM , NULL AS OUD_ACCOUNT_\
NAME , NULL AS OUD_BANK_NAME , NULL AS OUD_BANK_CODE , NULL AS OUD_BRANCH , \
NULL AS OUD_PHONE_NUM , NULL AS OUD_PROV");
 sqlbuft((void **)0,
   "INCE , NULL AS OUD_CITY , OPR_PAYOUT_AMOUNT AS OUD_PAYOUT_AMOUNT , OPR_R\
EQUEST_AMOUNT AS OUD_REQUEST_AMOUNT , OPR_PAYOUT_CURRENCY AS OUD_PAYOUT_CURR\
ENCY , OPR_REQUEST_CURRENCY AS OUD_REQUEST_CURRENCY , OPR_MEMBER_FEE_CCY AS \
OUD_MEMBER_FEE_CCY , OPR_MEMBER_FEE AS OUD_MEMBER_FEE , OPR_MERCHANT_FEE_CCY\
 AS OUD_MERCHANT_FEE_CCY , OPR_MERCHANT_FEE AS OUD_MERCHANT_FEE , OPR_MARKUP\
_CCY AS OUD_MARKUP_CCY , OPR_MARKUP_AMT AS OUD_MARKUP_AMT , NULL AS OUD_EXCH\
ANGE_RATE , NULL AS OUD_PAYOUT_TXN_NUM , OPR_STATUS AS OUD_STATUS , NULL AS \
OUD_RESPONSE_CODE , NULL AS OUD_REMARK , NULL AS OUD_DISABLED , NULL AS OUD_\
BATCH_MODE , OPR_GENERATED_FILE_ID AS OUD_GENERATED_FILE_ID , NULL AS OUD_GE\
NERATED_FILE_NAME , NULL AS OUD_PSP_BATCH_ID , NULL AS OUD_FUNDOUT_DATE , NU\
LL AS OUD_SERVICE_FEE , NULL AS OUD_TID , OPR_PSP_ID AS OUD_PSP_ID , NULL AS\
 OUD_APPROVE_ID , NULL AS OUD_VNC_REF_NUM , NULL AS OUD_PREGEN_PSP_ID , NULL\
 AS OUD_PREGEN_FILE_ID , NULL AS OUD_PREAPPROVE_ID , OPR_CREATE_TIMESTAMP AS\
 OUD_CREATE_TIMESTAMP , OPR_UPDATE_TIMES");
 sqlbuft((void **)0,
   "TAMP AS OUD_UPDATE_TIMESTAMP , OPR_UPDATE_USER AS OUD_UPDATE_USER , OPR_\
CREATE_USER AS OUD_CREATE_USER , OPR_MERCHANT_PAYOUT_GRP AS OUD_MERCHANT_PAY\
OUT_GRP , OPR_PSP_PAYOUT_GRP AS OUD_PSP_PAYOUT_GRP , NULL AS OUD_PREGEN_BANK\
_CODE FROM OL_PAYOUT_REQUEST WHERE 1 = 1 AND OPR_CREATE_TIMESTAMP >= TO_DATE\
 ( :b0 , 'YYYY-MM-DD HH24:MI' ) AND OPR_CREATE_TIMESTAMP < TO_DATE ( :b0 , '\
YYYY-MM-DD HH24:MI' ) + 1 ) UFD LEFT JOIN OL_TXN_HEADER ON OL_TXN_HEADER . O\
TH_TXN_ID = UFD . OUD_TXN_ID LEFT JOIN OL_TXN_DETAIL ON OL_TXN_DETAIL . OTD_\
TXN_ID = OL_TXN_HEADER . OTH_TXN_ID LEFT JOIN OL_MERCHANT_UPLOAD_FILE_HEADER\
 UFH ON UFH . OUH_BATCH_ID = UFD . OUD_BATCH_ID LEFT JOIN DEF_PAYOUT_BATCH_S\
TATUS ON DEF_PAYOUT_BATCH_STATUS . DP_STATUS_ID = UFD . OUD_STATUS LEFT JOIN\
 COUNTRY ON COUNTRY . COUNTRY_CODE = UFD . OUD_COUNTRY LEFT JOIN COUNTRY COU\
NTRY_TXN ON COUNTRY_TXN . COUNTRY_CODE = OL_TXN_DETAIL . OTD_TXN_COUNTRY LEF\
T JOIN DEF_SERVICE_CODE ON DEF_SERVICE_CODE . SC_CODE = UFH . OUH_SERVICE_CO\
DE LEFT JOIN DEF_SERVICE_CODE DEF_SERVIC");
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )84;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_report_date;
 sqlstm.sqhstl[2] = (unsigned long )10;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_report_date;
 sqlstm.sqhstl[3] = (unsigned long )10;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[4] = (unsigned long )17;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[5] = (unsigned long )17;
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
 if (sqlca.sqlcode < 0) goto poatxndetail_sql_error;
}



	do
	{
		/* EXEC SQL FETCH c_cursor_getpoatxndetail
		INTO
			:v_seq_no:ind_seq_no, 
			:v_txn_id:ind_txn_id, 
			:v_country:ind_country, 
			:v_service:ind_service, 
			:v_merchant_ref:ind_merchant_ref, 
			:v_bank_name:ind_bank_name, 
			:v_bank_acct_no:ind_bank_acct_no, 
			:v_bank_acct_name:ind_bank_acct_name, 
			:v_merchant_file_name:ind_merchant_file_name, 
			:v_merchant_req_amt_ccy:ind_merchant_req_amt_ccy, 
			:v_merchant_req_amt:ind_merchant_req_amt, 
			:v_merchant_payable_amt_ccy:ind_merchant_payable_amt_ccy, 
			:v_merchant_payable_amt:ind_merchant_payable_amt, 
			:v_consumer_recv_amt_ccy:ind_consumer_recv_amt_ccy, 
			:v_consumer_recv_amt:ind_consumer_recv_amt, 
			:v_merchant_paid_amt_ccy:ind_merchant_paid_amt_ccy, 
			:v_merchant_paid_amt:ind_merchant_paid_amt, 
			:v_status:ind_status, 
			:v_create_timestamp:ind_create_timestamp, 
			:v_approval_timestamp:ind_approval_timestamp, 
			:v_last_update_timestamp:ind_last_update_timestamp, 
//			:v_merchant_req_timestamp:ind_merchant_req_timestamp, 
//			:v_req_channel:ind_req_channel, 
//			:v_callback_status:ind_callback_status, 
//			:v_merchant_group:ind_merchant_group, 
//			:v_payout_remark:ind_payout_remark, 
//			:v_system_remark:ind_system_remark;
			:v_remark:ind_remark; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 22;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )123;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_seq_no;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_seq_no;
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
  sqlstm.sqhstv[2] = (unsigned char  *)&v_country;
  sqlstm.sqhstl[2] = (unsigned long )53;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_country;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_service;
  sqlstm.sqhstl[3] = (unsigned long )53;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_service;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_merchant_ref;
  sqlstm.sqhstl[4] = (unsigned long )53;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_merchant_ref;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_bank_name;
  sqlstm.sqhstl[5] = (unsigned long )153;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_bank_name;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_bank_acct_no;
  sqlstm.sqhstl[6] = (unsigned long )28;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_bank_acct_no;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_bank_acct_name;
  sqlstm.sqhstl[7] = (unsigned long )103;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_bank_acct_name;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_merchant_file_name;
  sqlstm.sqhstl[8] = (unsigned long )53;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_merchant_file_name;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_merchant_req_amt_ccy;
  sqlstm.sqhstl[9] = (unsigned long )6;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_merchant_req_amt_ccy;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_merchant_req_amt;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_merchant_req_amt;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_merchant_payable_amt_ccy;
  sqlstm.sqhstl[11] = (unsigned long )6;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_merchant_payable_amt_ccy;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_merchant_payable_amt;
  sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_merchant_payable_amt;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_consumer_recv_amt_ccy;
  sqlstm.sqhstl[13] = (unsigned long )6;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_consumer_recv_amt_ccy;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_consumer_recv_amt;
  sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_consumer_recv_amt;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_merchant_paid_amt_ccy;
  sqlstm.sqhstl[15] = (unsigned long )6;
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_merchant_paid_amt_ccy;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&v_merchant_paid_amt;
  sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)&ind_merchant_paid_amt;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[17] = (unsigned long )53;
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)&ind_status;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)&v_create_timestamp;
  sqlstm.sqhstl[18] = (unsigned long )23;
  sqlstm.sqhsts[18] = (         int  )0;
  sqlstm.sqindv[18] = (         short *)&ind_create_timestamp;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)&v_approval_timestamp;
  sqlstm.sqhstl[19] = (unsigned long )23;
  sqlstm.sqhsts[19] = (         int  )0;
  sqlstm.sqindv[19] = (         short *)&ind_approval_timestamp;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)&v_last_update_timestamp;
  sqlstm.sqhstl[20] = (unsigned long )23;
  sqlstm.sqhsts[20] = (         int  )0;
  sqlstm.sqindv[20] = (         short *)&ind_last_update_timestamp;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)&v_remark;
  sqlstm.sqhstl[21] = (unsigned long )258;
  sqlstm.sqhsts[21] = (         int  )0;
  sqlstm.sqindv[21] = (         short *)&ind_remark;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto poatxndetail_sql_error;
}



		if (SQLCODE == SQL_NOT_FOUND)
			break;

		fprintf(fp,"<Row>\n");

		/* v_seq_no */
		if (ind_seq_no >= 0)
		{
			sprintf(csTmp, "%d", v_seq_no);
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", csTmp);
DEBUGLOG(("process_payout_txn_detail v_seq_no = [%d]\n", v_seq_no));
		}
		else
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");

		/* v_txn_id */
		if (ind_txn_id >= 0)
		{
			v_txn_id.arr[v_txn_id.len] = '\0';
			strcpy(csTxnId, (const char *)v_txn_id.arr);
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", csTxnId);
DEBUGLOG(("process_payout_txn_detail v_txn_id = [%s]\n", v_txn_id.arr));
		}
		else
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");

		/* v_country */
		if (ind_country >= 0)
		{
			v_country.arr[v_country.len] = '\0';
			strcpy(csCountry, (const char *)v_country.arr);
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", csCountry);
DEBUGLOG(("process_payout_txn_detail v_country = [%s]\n", v_country.arr));
		}
		else
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");

		/* v_service */
		if (ind_service >= 0)
		{
			v_service.arr[v_service.len] = '\0';
			strcpy(csService, (const char *)v_service.arr);
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", csService);
DEBUGLOG(("process_payout_txn_detail v_service = [%s]\n", v_service.arr));
		}
		else
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");

		/* v_merchant_ref */
		if (ind_merchant_ref >= 0)
		{
			v_merchant_ref.arr[v_merchant_ref.len] = '\0';
			strcpy(csMerchantRef, (const char *)v_merchant_ref.arr);
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", csMerchantRef);
DEBUGLOG(("process_payout_txn_detail v_merchant_ref = [%s]\n", v_merchant_ref.arr));
		}
		else
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");

		/* v_bank_name */
		if (ind_bank_name >= 0)
		{
			v_bank_name.arr[v_bank_name.len] = '\0';
			strcpy(csBankName, (const char *)v_bank_name.arr);
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", csBankName);
DEBUGLOG(("process_payout_txn_detail v_bank_name = [%s]\n", v_bank_name.arr));
		}
		else
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");

		/* v_bank_acct_no */
		if (ind_bank_acct_no >= 0)
		{
			v_bank_acct_no.arr[v_bank_acct_no.len] = '\0';
			strcpy(csBankAcctNo, (const char *)v_bank_acct_no.arr);
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", csBankAcctNo);
DEBUGLOG(("process_payout_txn_detail v_bank_acct_no = [%s]\n", v_bank_acct_no.arr));
		}
		else
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");

		/* v_bank_acct_name */
		if (ind_bank_acct_name >= 0)
		{
			v_bank_acct_name.arr[v_bank_acct_name.len] = '\0';
			strcpy(csBankAcctName, (const char *)v_bank_acct_name.arr);
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", csBankAcctName);
DEBUGLOG(("process_payout_txn_detail v_bank_acct_name = [%s]\n", v_bank_acct_name.arr));
		}
		else
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");

		/* v_merchant_file_name */
		if (ind_merchant_file_name >= 0)
		{
			v_merchant_file_name.arr[v_merchant_file_name.len] = '\0';
			strcpy(csMerchantFileName, (const char *)v_merchant_file_name.arr);
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", csMerchantFileName);
DEBUGLOG(("process_payout_txn_detail v_merchant_file_name = [%s]\n", v_merchant_file_name.arr));
		}
		else
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");

		/* v_merchant_req_amt_ccy */
		if (ind_merchant_req_amt_ccy >= 0)
		{
			v_merchant_req_amt_ccy.arr[v_merchant_req_amt_ccy.len] = '\0';
			strcpy(csMerchantReqAmtCcy, (const char *)v_merchant_req_amt_ccy.arr);
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", csMerchantReqAmtCcy);
DEBUGLOG(("process_payout_txn_detail v_merchant_req_amt_ccy = [%s]\n", v_merchant_req_amt_ccy.arr));
		}
		else
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");

		/* v_merchant_req_amt */
		if (ind_merchant_req_amt >= 0)
		{
			dMerchantReqAmt = v_merchant_req_amt;
			format_commas(dMerchantReqAmt, csTmp);
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", csTmp);
DEBUGLOG(("process_payout_txn_detail v_merchant_req_amt = [%f]\n", dMerchantReqAmt));
		}
		else
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");

		/* v_merchant_payable_amt_ccy */
		if (ind_merchant_payable_amt_ccy >= 0)
		{
			v_merchant_payable_amt_ccy.arr[v_merchant_payable_amt_ccy.len] = '\0';
			strcpy(csMerchantPayableAmtCcy, (const char *)v_merchant_payable_amt_ccy.arr);
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", csMerchantPayableAmtCcy);
DEBUGLOG(("process_payout_txn_detail v_merchant_payable_amt_ccy = [%s]\n", v_merchant_payable_amt_ccy.arr));
		}
		else
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");

		/* v_merchant_payable_amt */
		if (ind_merchant_req_amt >= 0)
		{
			dMerchantPayableAmt = v_merchant_payable_amt;
			format_commas(dMerchantPayableAmt, csTmp);
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", csTmp);
DEBUGLOG(("process_payout_txn_detail v_merchant_payable_amt = [%f]\n", dMerchantPayableAmt));
		}
		else
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");

		/* v_consumer_recv_amt_ccy */
		if (ind_consumer_recv_amt_ccy >= 0)
		{
			v_consumer_recv_amt_ccy.arr[v_consumer_recv_amt_ccy.len] = '\0';
			strcpy(csConsumerRecvAmtCcy, (const char *)v_consumer_recv_amt_ccy.arr);
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", csConsumerRecvAmtCcy);
DEBUGLOG(("process_payout_txn_detail v_consumer_recv_amt_ccy = [%s]\n", v_consumer_recv_amt_ccy.arr));
		}
		else
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");

		/* v_consumer_recv_amt */
		if (ind_consumer_recv_amt >= 0)
		{
			dConsumerRecvAmtCcy = v_consumer_recv_amt;
			format_commas(dConsumerRecvAmtCcy, csTmp);
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", csTmp);
DEBUGLOG(("process_payout_txn_detail v_consumer_recv_amt = [%f]\n", dConsumerRecvAmtCcy));
		}
		else
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");

		/* v_merchant_paid_amt_ccy */
		if (ind_merchant_paid_amt_ccy >= 0)
		{
			v_merchant_paid_amt_ccy.arr[v_merchant_paid_amt_ccy.len] = '\0';
			strcpy(csMerchantPaidAmtCcy, (const char *)v_merchant_paid_amt_ccy.arr);
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", csMerchantPaidAmtCcy);
DEBUGLOG(("process_payout_txn_detail v_merchant_paid_amt_ccy = [%s]\n", v_merchant_paid_amt_ccy.arr));
		}
		else
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");

		/* v_merchant_paid_amt */
		if (ind_consumer_recv_amt >= 0)
		{
			dMerchantPaidAmt = v_merchant_paid_amt;
			format_commas(dMerchantPaidAmt, csTmp);
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", csTmp);
DEBUGLOG(("process_payout_txn_detail v_merchant_paid_amt = [%f]\n", dMerchantPaidAmt));
		}
		else
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");

		/* v_status */
		if (ind_status >= 0)
		{
			v_status.arr[v_status.len] = '\0';
			strcpy(csStatus, (const char *)v_status.arr);
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", csStatus);
DEBUGLOG(("process_payout_txn_detail v_status = [%s]\n", v_status.arr));
		}
		else
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");

		/* v_create_timestamp */
		if (ind_create_timestamp >= 0)
		{
			v_create_timestamp.arr[v_create_timestamp.len] = '\0';
			strcpy(csCreateTimestamp, (const char *)v_create_timestamp.arr);
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", csCreateTimestamp);
DEBUGLOG(("process_payout_txn_detail v_create_timestamp = [%s]\n", v_create_timestamp.arr));
		}
		else
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");

		/* v_approval_timestamp */
		if (ind_approval_timestamp >= 0)
		{
			v_approval_timestamp.arr[v_approval_timestamp.len] = '\0';
			strcpy(csApprovalTimestamp, (const char *)v_approval_timestamp.arr);
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", csApprovalTimestamp);
DEBUGLOG(("process_payout_txn_detail v_approval_timestamp = [%s]\n", v_approval_timestamp.arr));
		}
		else
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");

		/* v_last_update_timestamp */
		if (ind_last_update_timestamp >= 0)
		{
			v_last_update_timestamp.arr[v_last_update_timestamp.len] = '\0';
			strcpy(csLastUpdateTimestamp, (const char *)v_last_update_timestamp.arr);
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", csLastUpdateTimestamp);
DEBUGLOG(("process_payout_txn_detail v_last_update_timestamp = [%s]\n", v_last_update_timestamp.arr));
		}
		else
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");

		/* v_merchant_req_timestamp */
/*
		if (ind_merchant_req_timestamp >= 0)
		{
			v_merchant_req_timestamp.arr[v_merchant_req_timestamp.len] = '\0';
			strcpy(csMerchantReqTimestamp, (const char *)v_merchant_req_timestamp.arr);
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", csMerchantReqTimestamp);
DEBUGLOG(("process_payout_txn_detail v_merchant_req_timestamp = [%s]\n", v_merchant_req_timestamp.arr));
		}
		else
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");
*/
		/* v_req_channel */
/*
		if (ind_req_channel >= 0)
		{
			v_req_channel.arr[v_req_channel.len] = '\0';
			strcpy(csReqChannel, (const char *)v_req_channel.arr);
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", csReqChannel);
DEBUGLOG(("process_payout_txn_detail v_req_channel = [%s]\n", v_req_channel.arr));
		}
		else
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");
*/
		/* v_callback_status */
/*
		if (ind_callback_status >= 0)
		{
			v_callback_status.arr[v_callback_status.len] = '\0';
			strcpy(csCallbackStatus, (const char *)v_callback_status.arr);
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", csCallbackStatus);
DEBUGLOG(("process_payout_txn_detail v_callback_status = [%s]\n", v_callback_status.arr));
		}
		else
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");
*/
		/* v_merchant_group */
/*
		if (ind_merchant_group >= 0)
		{
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\">%c</Data></Cell>\n", v_merchant_group);
DEBUGLOG(("process_payout_txn_detail v_merchant_group = [%c]\n", v_merchant_group));
		}
		else
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");
*/
		/* v_payout_remark */
/*
		if (ind_payout_remark >= 0)
		{
			v_payout_remark.arr[v_payout_remark.len] = '\0';
			strcpy(csPayoutRemark, (const char *)v_payout_remark.arr);
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", csPayoutRemark);
DEBUGLOG(("process_payout_txn_detail v_payout_remark = [%s]\n", v_payout_remark.arr));
		}
		else
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");
*/
		/* v_system_remark */
/*
		if (ind_system_remark >= 0)
		{
			v_system_remark.arr[v_system_remark.len] = '\0';
			strcpy(csSystemRemark, (const char *)v_system_remark.arr);
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", csSystemRemark);
DEBUGLOG(("process_payout_txn_detail v_system_remark = [%s]\n", v_system_remark.arr));
		}
		else
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");
*/

		/* v_remark */
		if (ind_remark >= 0)
		{
			v_remark.arr[v_remark.len] = '\0';
			strcpy(csRemark, (const char *)v_remark.arr);
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\">%s</Data></Cell>\n", csRemark);
DEBUGLOG(("process_payout_txn_detail v_remark = [%s]\n", v_remark.arr));
		}
		else
			fprintf(fp, "\t<Cell><Data ss:Type=\"String\"> </Data></Cell>\n");

		fprintf(fp,"</Row>\n");
	} while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getpoatxndetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 22;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )226;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto poatxndetail_sql_error;
}



	return iRet;

poatxndetail_sql_error:
DEBUGLOG(("extract_ol_poa_txn_detail_daily_rpt:process_payout_txn_detail code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getpoatxndetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 22;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )241;
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
 sqlstm.arrsiz = 22;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )256;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



	return PD_ERR;
}

void format_commas(double dInNum, char * csOutNum)
{
	char	csTmpNum[PD_TMP_BUF_LEN + 1];
	int	iCnt;
	int	iCnt2;

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

	iCnt2 = 3;

	for (iCnt = 3; iCnt < strlen(csOutNum); iCnt++)
	{
		csTmpNum[iCnt2] = csOutNum[iCnt];
		iCnt2++;

		if (((iCnt + 1) % 3 == 0) && (iCnt + 1 < strlen(csOutNum)))
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
