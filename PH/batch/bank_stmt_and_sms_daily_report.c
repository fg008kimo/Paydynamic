
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
           char  filnam[34];
};
static struct sqlcxp sqlfpn =
{
    33,
    "bank_stmt_and_sms_daily_report.pc"
};


static unsigned int sqlctx = 2034453947;


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
   unsigned char  *sqhstv[13];
   unsigned long  sqhstl[13];
            int   sqhsts[13];
            short *sqindv[13];
            int   sqinds[13];
   unsigned long  sqharm[13];
   unsigned long  *sqharc[13];
   unsigned short  sqadto[13];
   unsigned short  sqtdso[13];
} sqlstm = {12,13};

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

 static char *sq0002 = 
"BLED ) = 1 AND NVL ( OBL_SUPPORT_SMS\
_STMT , OB_SUPPORT_SMS_STMT ) = 1 ) XX , OL_BANK_ACCT_ID BAID , ( SELECT olsd\
_int_bank_code , olsd_bank_acct_num , olsd_baid , olsd_statement_ref , olsd_i\
nput_channel , olsd_create_timestamp FROM OL_STATEMENT_DETAIL , OL_BAID_TXN W\
HERE OLSD_CREATE_TIMESTAMP >= to_date ( :b1 , 'YYYYMMDD HH24MISS' ) AND OLSD_\
CREATE_TIMESTAMP < to_date ( :b6 , 'YYYYMMDD HH24MISS' ) AND OLSD_STAT_TXN_ID\
 = OBT_STAT_TXN_ID AND OBT_TXN_CODE = 'OBD' ) STMT WHERE XX . OB_INT_BANK_COD\
E = BAID . OBAI_INT_BANK_CODE AND XX . OB_BANK_ACCT_NUM = BAID . OBAI_BANK_AC\
CT_NUM AND BAID . OBAI_STATUS = 'O' AND XX . OB_INT_BANK_CODE = stmt . olsd_i\
nt_bank_code AND XX . OB_BANK_ACCT_NUM = stmt . olsd_bank_acct_num AND BAID .\
 OBAI_BAID = stmt . olsd_baid GROUP BY OB_INT_BANK_CODE , BANK_ABBREV_NAME , \
OB_BANK_ACCT_NAME , OB_OWNER_NAME , OB_BANK_ACCT_NUM , OBAI_BAID ORDER BY BAN\
K_ABBREV_NAME ASC , OB_BANK_ACCT_NAME ASC , OB_OWNER_NAME ASC , OB_BANK_ACCT_\
NUM ASC            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,140,0,4,285,0,0,3,1,0,1,0,2,9,0,0,2,9,0,0,1,9,0,0,
32,0,0,2,3027,0,9,495,0,2049,13,13,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
99,0,0,2,0,0,13,498,0,0,11,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
158,0,0,2,0,0,15,596,0,0,0,0,0,1,0,
173,0,0,2,0,0,15,610,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/05/20              Elvis Wong
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

#define PD_CURRENT_PH_DATE		"CTPHDATE"
#define PD_FR_REPORT_DATETIME_P1	"090000"
#define PD_TO_REPORT_DATETIME_P1	"120000"
#define PD_FR_REPORT_DATETIME_P2	"120000"
#define PD_TO_REPORT_DATETIME_P2	"150000"

OBJPTR(DB);
char    cDebug;


int check_bank_stmt_and_sms_count();
int get_report_date(const char *csCode, char *csReportDateValue, char *csReportDate);
int get_bank_stmt_and_sms_count(const char *csReportDate, const char *csFrDateTimeP1, const char *csToDateTimeP1, const char *csFrDateTimeP2, const char *csToDateTimeP2, recordset_t* rRecordSet);
int cal_bank_stmt_and_sms_rate(const int iStmtCnt, const int iSmsCnt, hash_t *hRls);


int batch_init(int argc, char* argv[])
{
        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
        int     iRet = SUCCESS;

	iRet = check_bank_stmt_and_sms_count();

	return iRet;
}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


int check_bank_stmt_and_sms_count()
{
	int     	iRet = SUCCESS;
	int		iDtlRet = PD_FOUND;

	int		iRecCnt = 0;
	
	int		iStmtCntP1 = 0;
	int		iSmsCntP1 = 0;
	int		iStmtCntP2 = 0;
	int		iSmsCntP2 = 0;

	double 	 	dStmtRateP1 = 0.0;
	double 	 	dSmsRateP1 = 0.0;
        double  	dStmtRateP2 = 0.0;
        double  	dSmsRateP2 = 0.0;

	char		*csIntBankCode = NULL;
	char		*csBankAbbrevName = NULL;
	char		*csBankAcctName = NULL;
	char		*csOwnerName = NULL;
	char		*csBankAcctNum = NULL;
	char		*csBaid = NULL;

	char   		*csCode = (char*) malloc (64);
	char   		*csReportDateValue = (char*) malloc (64);
	char   		*csReportDate = (char*) malloc (64);

	char    	csFrDateTimeP1[PD_DATETIME_LEN + 1];
	char    	csToDateTimeP1[PD_DATETIME_LEN + 1];
	char    	csFrDateTimeP2[PD_DATETIME_LEN + 1];
	char    	csToDateTimeP2[PD_DATETIME_LEN + 1];

	hash_t		*hRecRate;
	hRecRate = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hRecRate,0);

	hash_t          *hRec = NULL;
        recordset_t     *rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);
	
	// Get Report Date
	sprintf(csCode, "%s", PD_CURRENT_PH_DATE);
	iRet = get_report_date(csCode, csReportDateValue, csReportDate);
DEBUGLOG(("check_bank_stmt_and_sms_count:: report_date_value = [%s]\n", csReportDateValue));
DEBUGLOG(("check_bank_stmt_and_sms_count:: report_date = [%s]\n", csReportDate));
	
	// Set Report Date Time Period
	if (iRet == SUCCESS) {

		// Set From Date Time and To Date Time (Time Period 1)
		sprintf(csFrDateTimeP1, "%s %s", csReportDateValue, PD_FR_REPORT_DATETIME_P1);
		sprintf(csToDateTimeP1, "%s %s", csReportDateValue, PD_TO_REPORT_DATETIME_P1);

DEBUGLOG(("check_bank_stmt_and_sms_count:: fr_date_time_p1 = [%s]\n", csFrDateTimeP1));
DEBUGLOG(("check_bank_stmt_and_sms_count:: to_date_time_p1 = [%s]\n", csToDateTimeP1));

		// Set Set From Date Time and To Date Time (Time Period 2)
		sprintf(csFrDateTimeP2, "%s %s", csReportDateValue, PD_FR_REPORT_DATETIME_P2);
		sprintf(csToDateTimeP2, "%s %s", csReportDateValue, PD_TO_REPORT_DATETIME_P2);

DEBUGLOG(("check_bank_stmt_and_sms_count:: fr_date_time_p2 = [%s]\n", csFrDateTimeP2));
DEBUGLOG(("check_bank_stmt_and_sms_count:: to_date_time_p2 = [%s]\n", csToDateTimeP2));
	}

	// Get Bank Stmt and SMS Count
	if (iRet == SUCCESS) {

        	iDtlRet = get_bank_stmt_and_sms_count(csReportDateValue, csFrDateTimeP1, csToDateTimeP1, csFrDateTimeP2, csToDateTimeP2, rRecordSet);
	
		if (iDtlRet == PD_FOUND) {

			// Title
			printf("<br>\n");
        		printf("<table border=\"1\">\n");
			printf("<tr><th>Report Date: </th><th align=\"left\" colspan=\"11\">%s</th></tr>\n", csReportDate);
			printf("<tr><th>Result: </th><th align=\"left\" colspan=\"11\">Success</th></tr>\n");
        		printf("<tr align=\"center\"><th>Bank Name</th><th>Bank Account Name</th><th>Owner Name</th><th>Bank Account Number</th><th>Statement Count during 09:00 - 12:00</th><th>Statement Pct (%%) during 09:00 - 12:00</th><th>SMS Count during 09:00 - 12:00</th><th>SMS Pct (%%) during 09:00 - 12:00</th><th>Statement Count during 12:00 - 15:00</th><th>Statement Pct (%%) during 12:00 - 15:00</th><th>SMS Count during 12:00 - 15:00</th><th>SMS Pct (%%) during 12:00 - 15:00</th></tr>\n");

			hRec = RecordSet_GetFirst(rRecordSet);
                	while (hRec) {
	
				iRecCnt++;			
DEBUGLOG(("check_bank_stmt_and_sms_count:: rec = [%d]\n", iRecCnt));

/* int_bank_code */
                        	if (GetField_CString(hRec, "int_bank_code", &csIntBankCode)) {
DEBUGLOG(("check_bank_stmt_and_sms_count:: int_bank_code = [%s]\n", csIntBankCode));
                        	}

/* bank_abbrev_name */
                        	if (GetField_CString(hRec, "bank_abbrev_name", &csBankAbbrevName)) {
DEBUGLOG(("check_bank_stmt_and_sms_count:: bank_abbrev_name = [%s]\n", csBankAbbrevName));
                        	}

/* bank_acct_name */
                        	if (GetField_CString(hRec, "bank_acct_name", &csBankAcctName)) {
DEBUGLOG(("check_bank_stmt_and_sms_count:: bank_acct_name = [%s]\n", csBankAcctName));
                        	}

/* owner_name */
                        	if (GetField_CString(hRec, "owner_name", &csOwnerName)) {
DEBUGLOG(("check_bank_stmt_and_sms_count:: owner_name = [%s]\n", csOwnerName));
                        	}

/* bank_acct_num */
                        	if (GetField_CString(hRec, "bank_acct_num", &csBankAcctNum)) {
DEBUGLOG(("check_bank_stmt_and_sms_count:: bank_acct_num = [%s]\n", csBankAcctNum));
                        	}

/* baid */
                        	if (GetField_CString(hRec, "baid", &csBaid)) {
DEBUGLOG(("check_bank_stmt_and_sms_count:: baid = [%s]\n", csBaid));
                        	}

/* stmt_cnt_p1 */
                        	if (GetField_Int(hRec, "stmt_cnt_p1", &iStmtCntP1)) {
DEBUGLOG(("check_bank_stmt_and_sms_count:: stmt_cnt_p1 = [%d]\n", iStmtCntP1));
                        	}

/* sms_cnt_p1 */
                        	if (GetField_Int(hRec, "sms_cnt_p1", &iSmsCntP1)) {
DEBUGLOG(("check_bank_stmt_and_sms_count:: sms_cnt_p1 = [%d]\n", iSmsCntP1));
                        	}
	
				iRet = cal_bank_stmt_and_sms_rate(iStmtCntP1, iSmsCntP1, hRecRate);

				if (iRet == SUCCESS) {
/* stmt_rate_p1 */
                        		if (GetField_Double(hRecRate, "stmt_rate", &dStmtRateP1)) {
DEBUGLOG(("check_bank_stmt_and_sms_count:: stmt_rate_p1 = [%.2f]\n", dStmtRateP1));
                        		}				

/* sms_rate_p1 */
                                	if (GetField_Double(hRecRate, "sms_rate", &dSmsRateP1)) {
DEBUGLOG(("check_bank_stmt_and_sms_count:: sms_rate_p1 = [%.2f]\n", dSmsRateP1));
                                	}
				}

/* stmt_cnt_p2 */
                                if (GetField_Int(hRec, "stmt_cnt_p2", &iStmtCntP2)) {
DEBUGLOG(("check_bank_stmt_and_sms_count:: stmt_cnt_p2 = [%d]\n", iStmtCntP2));
                                }

/* sms_cnt_p2 */
                                if (GetField_Int(hRec, "sms_cnt_p2", &iSmsCntP2)) {
DEBUGLOG(("check_bank_stmt_and_sms_count:: sms_cnt_p2 = [%d]\n", iSmsCntP2));
                                }

                                iRet = cal_bank_stmt_and_sms_rate(iStmtCntP2, iSmsCntP2, hRecRate);

                                if (iRet == SUCCESS) {
/* stmt_rate_p2 */
                                        if (GetField_Double(hRecRate, "stmt_rate", &dStmtRateP2)) {
DEBUGLOG(("check_bank_stmt_and_sms_count:: stmt_rate_p2 = [%.2f]\n", dStmtRateP2));
                                        }

/* sms_rate_p2 */
                                        if (GetField_Double(hRecRate, "sms_rate", &dSmsRateP2)) {
DEBUGLOG(("check_bank_stmt_and_sms_count:: sms_rate_p2 = [%.2f]\n", dSmsRateP2));
                                        }
                                }

				// Record
				printf("<tr><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%d</td><td>%.2f%%</td><td>%d</td><td>%.2f%%</td><td>%d</td><td>%.2f%%</td><td>%d</td><td>%.2f%%</td></tr>\n", csBankAbbrevName, csBankAcctName, csOwnerName, csBankAcctNum, iStmtCntP1, dStmtRateP1*100, iSmsCntP1, dSmsRateP1*100, iStmtCntP2, dStmtRateP2*100, iSmsCntP2, dSmsRateP2*100);
			
                        	hRec = RecordSet_GetNext(rRecordSet);
                	}

			// Close
			printf("</table>\n");
		} else if (iDtlRet == PD_NOT_FOUND) {
			printf("<br>\n");
        		printf("<table border=\"1\">\n");
			printf("<tr><th align=\"left\">Report Date: </th><th align=\"left\">%s</th></tr>\n", csReportDate);
                        printf("<tr><th align=\"left\">Result: </th><th align=\"left\">No Bank Statement and SMS Record Found during 09:00 - 12:00 and 12:00 and 15:00</th></tr>\n");		
			printf("</table>\n");
		} else {
			iRet = iDtlRet;
		}
	}

	FREE_ME(csCode);
	FREE_ME(csReportDateValue);
	FREE_ME(csReportDate);

	hash_destroy(hRecRate);
        FREE_ME(hRecRate);

	RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);

	return iRet;
}


int get_report_date(const char *csCode, char *csReportDateValue, char *csReportDate)
{
	int	iRet = FAILURE;

	/* EXEC SQL WHENEVER SQLERROR GOTO get_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_code[PD_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_code;


                /* varchar v_value[PD_VALUE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_value;

                /* varchar v_date[PD_DATE_LEN + 5 + 1]; */ 
struct { unsigned short len; unsigned char arr[14]; } v_date;

                short   ind_value = -1;
                short   ind_date = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


// code
        hv_code.len = strlen(csCode);
        memcpy(hv_code.arr,csCode,hv_code.len);
DEBUGLOG(("get_report_date: code = [%.*s]\n",hv_code.len,hv_code.arr));

        /* EXEC SQL SELECT sys_val,
			to_char(to_date(sys_val, 'YYYYMMDD'), 'DD-MON-YYYY') 
                 INTO :v_value:ind_value,
		      :v_date:ind_date		
		 FROM SYSTEM_CONTROL
                 WHERE SYS_CODE = :hv_code; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 3;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select sys_val , to_char ( to_date ( sys_val , 'YYYY\
MMDD' ) , 'DD-MON-YYYY' ) INTO :b0:b1 , :b2:b3 FROM SYSTEM_CONTROL WHERE SYS_\
CODE = :b4 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )5;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_value;
        sqlstm.sqhstl[0] = (unsigned long )53;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_value;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&v_date;
        sqlstm.sqhstl[1] = (unsigned long )16;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_date;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_code;
        sqlstm.sqhstl[2] = (unsigned long )12;
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
        if (sqlca.sqlcode < 0) goto get_error;
}



/* value */
        if (ind_value >= 0) {
                v_value.arr[v_value.len] = '\0';
                strcpy((char*)csReportDateValue,(const char*)v_value.arr);
DEBUGLOG(("get_report_date: value = [%s]\n",csReportDateValue));
                iRet = SUCCESS;
        }

/* date */
	if (ind_date >= 0) {
                v_date.arr[v_date.len] = '\0';
                strcpy((char*)csReportDate,(const char*)v_date.arr);
DEBUGLOG(("get_report_date: date = [%s]\n",csReportDate));
                iRet = SUCCESS;
        }

DEBUGLOG(("get_report_date: iRet = [%d]\n", iRet));

get_error:
DEBUGLOG(("get_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return iRet;
}


int get_bank_stmt_and_sms_count(const char *csReportDate, const char *csFrDateTimeP1, const char *csToDateTimeP1, const char *csFrDateTimeP2, const char *csToDateTimeP2, recordset_t* rRecordSet)
{
	int     iRet = PD_NOT_FOUND;

	int	iCnt = 0;

	hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getcount_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_report_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } hv_report_date;

		/* varchar		hv_fr_date_time_p1[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_fr_date_time_p1;

		/* varchar		hv_to_date_time_p1[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_to_date_time_p1;

		/* varchar		hv_fr_date_time_p2[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_fr_date_time_p2;
	
		/* varchar		hv_to_date_time_p2[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_to_date_time_p2;
	

		/* varchar		v_report_date[PD_DATE_LEN + 5 + 1]; */ 
struct { unsigned short len; unsigned char arr[14]; } v_report_date;

		/* varchar         v_int_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_int_bank_code;

		/* varchar 	v_bank_abbrev_name[PD_EXT_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_bank_abbrev_name;

		/* varchar         v_bank_acct_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_name;

		/* varchar         v_owner_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_owner_name;

		/* varchar         v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

		/* varchar         v_baid[PD_BAID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_baid;
                
		int             v_stmt_cnt_p1;
		int             v_sms_cnt_p1;
		int             v_stmt_cnt_p2;
		int             v_sms_cnt_p2;
	
		short		ind_report_date = -1;
		short           ind_int_bank_code = -1;
                short           ind_bank_abbrev_name = -1;
		short		ind_bank_acct_name = -1;
		short		ind_owner_name = -1;	
                short           ind_bank_acct_num = -1;
                short           ind_baid = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


// report_date
	if (strlen(csReportDate) > 0) {
                hv_report_date.len = strlen(csReportDate);
                memcpy(hv_report_date.arr, csReportDate, hv_report_date.len);
DEBUGLOG(("get_bank_stmt_and_sms_count: report_date = [%.*s]\n",hv_report_date.len,hv_report_date.arr));
        }

// fr_date_time_p1
	if (strlen(csFrDateTimeP1) > 0) {
                hv_fr_date_time_p1.len = strlen(csFrDateTimeP1);
                memcpy(hv_fr_date_time_p1.arr, csFrDateTimeP1, hv_fr_date_time_p1.len);
DEBUGLOG(("get_bank_stmt_and_sms_count: fr_date_time_p1 = [%.*s]\n",hv_fr_date_time_p1.len,hv_fr_date_time_p1.arr));
        }

// to_date_time_p1
	if (strlen(csToDateTimeP1) > 0) {
                hv_to_date_time_p1.len = strlen(csToDateTimeP1);
                memcpy(hv_to_date_time_p1.arr, csToDateTimeP1, hv_to_date_time_p1.len);
DEBUGLOG(("get_bank_stmt_and_sms_count: to_date_time_p1 = [%.*s]\n",hv_to_date_time_p1.len,hv_to_date_time_p1.arr));
        }

// fr_date_time_p2
	if (strlen(csFrDateTimeP2) > 0) {
                hv_fr_date_time_p2.len = strlen(csFrDateTimeP2);
                memcpy(hv_fr_date_time_p2.arr, csFrDateTimeP2, hv_fr_date_time_p2.len);
DEBUGLOG(("get_bank_stmt_and_sms_count: fr_date_time_p2 = [%.*s]\n",hv_fr_date_time_p2.len,hv_fr_date_time_p2.arr));
        }

// to_date_time_p2
	if (strlen(csToDateTimeP2) > 0) {
                hv_to_date_time_p2.len = strlen(csToDateTimeP2);
                memcpy(hv_to_date_time_p2.arr, csToDateTimeP2, hv_to_date_time_p2.len);
DEBUGLOG(("get_bank_stmt_and_sms_count: to_date_time_p2 = [%.*s]\n",hv_to_date_time_p2.len,hv_to_date_time_p2.arr));
        }

	/* EXEC SQL DECLARE c_cursor_getcount CURSOR FOR
      		SELECT 	to_date(:hv_report_date, 'YYYYMMDD') REPORT_DATE,
        		OB_INT_BANK_CODE,
			BANK_ABBREV_NAME,
        		OB_BANK_ACCT_NAME,
        		OB_OWNER_NAME,
        		OB_BANK_ACCT_NUM,
       	 		OBAI_BAID,
        		SUM (CASE 
        			WHEN olsd_input_channel='BNK_STMT'
				AND  (OLSD_CREATE_TIMESTAMP >= to_date(:hv_fr_date_time_p1, 'YYYYMMDD HH24MISS')
                        	      AND OLSD_CREATE_TIMESTAMP < to_date(:hv_to_date_time_p1, 'YYYYMMDD HH24MISS'))
				THEN 1 
        			ELSE 0
        			END
        		) STMS_COUNT_P1,
        		SUM (CASE 
        			WHEN olsd_input_channel='SMS_STMT'
			        AND  (OLSD_CREATE_TIMESTAMP >= to_date(:hv_fr_date_time_p1, 'YYYYMMDD HH24MISS')
                                      AND OLSD_CREATE_TIMESTAMP < to_date(:hv_to_date_time_p1, 'YYYYMMDD HH24MISS')) 
				THEN 1 
        			ELSE 0
        			END
       			) SMS_COUNT_P1,
   			SUM (CASE
                                WHEN olsd_input_channel='BNK_STMT'
                                AND  (OLSD_CREATE_TIMESTAMP >= to_date(:hv_fr_date_time_p2, 'YYYYMMDD HH24MISS')
                                      AND OLSD_CREATE_TIMESTAMP < to_date(:hv_to_date_time_p2, 'YYYYMMDD HH24MISS'))
                                THEN 1
                                ELSE 0
                                END
                        ) STMS_COUNT_P2,
                        SUM (CASE
                                WHEN olsd_input_channel='SMS_STMT'
                                AND  (OLSD_CREATE_TIMESTAMP >= to_date(:hv_fr_date_time_p2, 'YYYYMMDD HH24MISS')
                                      AND OLSD_CREATE_TIMESTAMP < to_date(:hv_to_date_time_p2, 'YYYYMMDD HH24MISS'))
                                THEN 1
                                ELSE 0
                                END
                        ) SMS_COUNT_P2
      		FROM	(SELECT OB_INT_BANK_CODE,
        			OB_BANK_ACCT_NAME,
        			OB_OWNER_NAME,
        			OB_BANK_ACCT_NUM,
				BANK_ABBREV_NAME,
        			NVL(OBL_SYS_SWITCH_ENABLED, OB_SYS_SWITCH_ENABLED), 
        			NVL(OBL_SUPPORT_SMS_STMT, OB_SUPPORT_SMS_STMT)
        		FROM	(SELECT	OB_INT_BANK_CODE,
          				OB_BANK_ACCT_NAME,
          				OB_OWNER_NAME,
          				OB_BANK_ACCT_NUM,
          				OB_SYS_SWITCH_ENABLED, 
          				OB_SUPPORT_SMS_STMT 
          			FROM	OL_BANK_ACCTS) ACCT,
				(SELECT	INTERNAL_BANK_CODE,
        				BANK_ABBREV_NAME
          			FROM	BANK_DESC) BANK,
        			(SELECT	DISTINCT OBL_LOG_SEQ,
          				OBL_INT_BANK_CODE,
          				OBL_BANK_ACCT_NAME,
          				OBL_OWNER_NAME,
          				OBL_BANK_ACCT_NUM,
          				OBL_SYS_SWITCH_ENABLED, 
          				OBL_SUPPORT_SMS_STMT 
          			FROM 	OL_BANK_ACCTS_LOG 
          			WHERE 	OBL_UPDATE_TIMESTAMP >= to_date(:hv_fr_date_time_p1, 'YYYYMMDD HH24MISS')
          			AND 	OBL_UPDATE_TIMESTAMP < to_date(:hv_to_date_time_p2, 'YYYYMMDD HH24MISS')
          			AND 	OBL_SYS_SWITCH_ENABLED = 1 
          			AND 	OBL_SUPPORT_SMS_STMT = 1) LG
        		WHERE 	OB_INT_BANK_CODE = OBL_INT_BANK_CODE(+)
        		AND	OB_BANK_ACCT_NUM = OBL_BANK_ACCT_NUM(+)
        		AND	OB_INT_BANK_CODE = INTERNAL_BANK_CODE
 			AND	NVL(OBL_SYS_SWITCH_ENABLED, OB_SYS_SWITCH_ENABLED) = 1
        		AND	NVL(OBL_SUPPORT_SMS_STMT, OB_SUPPORT_SMS_STMT) = 1) XX, 
			OL_BANK_ACCT_ID BAID,
        		(SELECT olsd_int_bank_code,
          			olsd_bank_acct_num,
          			olsd_baid,
          			olsd_statement_ref,
          			olsd_input_channel,
				olsd_create_timestamp
          		FROM 	OL_STATEMENT_DETAIL,
				OL_BAID_TXN
          		WHERE	OLSD_CREATE_TIMESTAMP >= to_date(:hv_fr_date_time_p1, 'YYYYMMDD HH24MISS')
         	 	AND 	OLSD_CREATE_TIMESTAMP < to_date(:hv_to_date_time_p2, 'YYYYMMDD HH24MISS')
          		AND 	OLSD_STAT_TXN_ID = OBT_STAT_TXN_ID
         		AND 	OBT_TXN_CODE ='OBD') STMT
      		WHERE 	XX.OB_INT_BANK_CODE = BAID.OBAI_INT_BANK_CODE
      		AND 	XX.OB_BANK_ACCT_NUM = BAID.OBAI_BANK_ACCT_NUM
      		AND 	BAID.OBAI_STATUS='O'
      		AND 	XX.OB_INT_BANK_CODE = stmt.olsd_int_bank_code
      		AND 	XX.OB_BANK_ACCT_NUM = stmt.olsd_bank_acct_num
      		AND 	BAID.OBAI_BAID = stmt.olsd_baid
      		GROUP BY	OB_INT_BANK_CODE,
  				BANK_ABBREV_NAME,
        			OB_BANK_ACCT_NAME,
        			OB_OWNER_NAME,
        			OB_BANK_ACCT_NUM,
        			OBAI_BAID
		ORDER BY 	BANK_ABBREV_NAME ASC, 
				OB_BANK_ACCT_NAME ASC,
				OB_OWNER_NAME ASC,
				OB_BANK_ACCT_NUM ASC; */ 

        /* EXEC SQL OPEN c_cursor_getcount; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlbuft((void **)0,
          "SELECT to_date ( :b0 , 'YYYYMMDD' ) REPORT_DATE , OB_INT_BANK_COD\
E , BANK_ABBREV_NAME , OB_BANK_ACCT_NAME , OB_OWNER_NAME , OB_BANK_ACCT_NUM \
, OBAI_BAID , SUM ( CASE WHEN olsd_input_channel = 'BNK_STMT' AND ( OLSD_CRE\
ATE_TIMESTAMP >= to_date ( :b1 , 'YYYYMMDD HH24MISS' ) AND OLSD_CREATE_TIMES\
TAMP < to_date ( :b2 , 'YYYYMMDD HH24MISS' ) ) THEN 1 ELSE 0 END ) STMS_COUN\
T_P1 , SUM ( CASE WHEN olsd_input_channel = 'SMS_STMT' AND ( OLSD_CREATE_TIM\
ESTAMP >= to_date ( :b1 , 'YYYYMMDD HH24MISS' ) AND OLSD_CREATE_TIMESTAMP < \
to_date ( :b2 , 'YYYYMMDD HH24MISS' ) ) THEN 1 ELSE 0 END ) SMS_COUNT_P1 , S\
UM ( CASE WHEN olsd_input_channel = 'BNK_STMT' AND ( OLSD_CREATE_TIMESTAMP >\
= to_date ( :b5 , 'YYYYMMDD HH24MISS' ) AND OLSD_CREATE_TIMESTAMP < to_date \
( :b6 , 'YYYYMMDD HH24MISS' ) ) THEN 1 ELSE 0 END ) STMS_COUNT_P2 , SUM ( CA\
SE WHEN olsd_input_channel = 'SMS_STMT' AND ( OLSD_CREATE_TIMESTAMP >= to_da\
te ( :b5 , 'YYYYMMDD HH24MISS' ) AND OLSD_CREATE_TIMESTAMP < to_date ( :b6 ,\
 'YYYYMMDD HH24MISS' ) ) THEN 1 ELSE 0 END ) SM");
        sqlbuft((void **)0,
          "S_COUNT_P2 FROM ( SELECT OB_INT_BANK_CODE , OB_BANK_ACCT_NAME , O\
B_OWNER_NAME , OB_BANK_ACCT_NUM , BANK_ABBREV_NAME , NVL ( OBL_SYS_SWITCH_EN\
ABLED , OB_SYS_SWITCH_ENABLED ) , NVL ( OBL_SUPPORT_SMS_STMT , OB_SUPPORT_SM\
S_STMT ) FROM ( SELECT OB_INT_BANK_CODE , OB_BANK_ACCT_NAME , OB_OWNER_NAME \
, OB_BANK_ACCT_NUM , OB_SYS_SWITCH_ENABLED , OB_SUPPORT_SMS_STMT FROM OL_BAN\
K_ACCTS ) ACCT , ( SELECT INTERNAL_BANK_CODE , BANK_ABBREV_NAME FROM BANK_DE\
SC ) BANK , ( SELECT DISTINCT OBL_LOG_SEQ , OBL_INT_BANK_CODE , OBL_BANK_ACC\
T_NAME , OBL_OWNER_NAME , OBL_BANK_ACCT_NUM , OBL_SYS_SWITCH_ENABLED , OBL_S\
UPPORT_SMS_STMT FROM OL_BANK_ACCTS_LOG WHERE OBL_UPDATE_TIMESTAMP >= to_date\
 ( :b1 , 'YYYYMMDD HH24MISS' ) AND OBL_UPDATE_TIMESTAMP < to_date ( :b6 , 'Y\
YYYMMDD HH24MISS' ) AND OBL_SYS_SWITCH_ENABLED = 1 AND OBL_SUPPORT_SMS_STMT \
= 1 ) LG WHERE OB_INT_BANK_CODE = OBL_INT_BANK_CODE ( + ) AND OB_BANK_ACCT_N\
UM = OBL_BANK_ACCT_NUM ( + ) AND OB_INT_BANK_CODE = INTERNAL_BANK_CODE AND N\
VL ( OBL_SYS_SWITCH_ENABLED , OB_SYS_SWITCH_ENA");
        sqlstm.stmt = sq0002;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )32;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_report_date;
        sqlstm.sqhstl[0] = (unsigned long )11;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_fr_date_time_p1;
        sqlstm.sqhstl[1] = (unsigned long )17;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_to_date_time_p1;
        sqlstm.sqhstl[2] = (unsigned long )17;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_fr_date_time_p1;
        sqlstm.sqhstl[3] = (unsigned long )17;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_to_date_time_p1;
        sqlstm.sqhstl[4] = (unsigned long )17;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_fr_date_time_p2;
        sqlstm.sqhstl[5] = (unsigned long )17;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_to_date_time_p2;
        sqlstm.sqhstl[6] = (unsigned long )17;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_fr_date_time_p2;
        sqlstm.sqhstl[7] = (unsigned long )17;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)0;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_to_date_time_p2;
        sqlstm.sqhstl[8] = (unsigned long )17;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)0;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_fr_date_time_p1;
        sqlstm.sqhstl[9] = (unsigned long )17;
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)0;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&hv_to_date_time_p2;
        sqlstm.sqhstl[10] = (unsigned long )17;
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)0;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&hv_fr_date_time_p1;
        sqlstm.sqhstl[11] = (unsigned long )17;
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         short *)0;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (unsigned char  *)&hv_to_date_time_p2;
        sqlstm.sqhstl[12] = (unsigned long )17;
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         short *)0;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned long )0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto getcount_error;
}



        for (;;) {
                /* EXEC SQL FETCH c_cursor_getcount
                INTO    :v_report_date:ind_report_date,
			:v_int_bank_code:ind_int_bank_code,
			:v_bank_abbrev_name:ind_bank_abbrev_name,
			:v_bank_acct_name:ind_bank_acct_name,
			:v_owner_name:ind_owner_name,
			:v_bank_acct_num:ind_bank_acct_num,
			:v_baid:ind_baid,
			:v_stmt_cnt_p1,
			:v_sms_cnt_p1,
			:v_stmt_cnt_p2,
			:v_sms_cnt_p2; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 13;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )99;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_report_date;
                sqlstm.sqhstl[0] = (unsigned long )16;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_report_date;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_int_bank_code;
                sqlstm.sqhstl[1] = (unsigned long )13;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_int_bank_code;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_bank_abbrev_name;
                sqlstm.sqhstl[2] = (unsigned long )23;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_bank_abbrev_name;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_bank_acct_name;
                sqlstm.sqhstl[3] = (unsigned long )53;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_bank_acct_name;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_owner_name;
                sqlstm.sqhstl[4] = (unsigned long )53;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_owner_name;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_bank_acct_num;
                sqlstm.sqhstl[5] = (unsigned long )53;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_bank_acct_num;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_baid;
                sqlstm.sqhstl[6] = (unsigned long )23;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_baid;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_stmt_cnt_p1;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)0;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_sms_cnt_p1;
                sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)0;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_stmt_cnt_p2;
                sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)0;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_sms_cnt_p2;
                sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)0;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto getcount_error;
}


			
                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash, 0);

		iCnt++;

		// report_date
		if (ind_report_date >= 0) {
                        v_report_date.arr[v_report_date.len] = '\0';
                        PutField_CString(myHash, "report_date", (const char*)v_report_date.arr);
DEBUGLOG(("get_bank_stmt_and_sms_count: int_report_date = [%s]\n", (const char*)v_report_date.arr));
                }

                // int_bank_code
                if (ind_int_bank_code >= 0) {
                        v_int_bank_code.arr[v_int_bank_code.len] = '\0';
                        PutField_CString(myHash, "int_bank_code", (const char*)v_int_bank_code.arr);
DEBUGLOG(("get_bank_stmt_and_sms_count: int_bank_code = [%s]\n", (const char*)v_int_bank_code.arr));
                }

		// bank_abbrev_name
		if (ind_bank_abbrev_name >= 0) {
                        v_bank_abbrev_name.arr[v_bank_abbrev_name.len] = '\0';
                        PutField_CString(myHash, "bank_abbrev_name", (const char*)v_bank_abbrev_name.arr);
DEBUGLOG(("get_bank_stmt_and_sms_count: bank_abbrev_name = [%s]\n", (const char*)v_bank_abbrev_name.arr));
                }
				
		// bank_acct_name
		if (ind_bank_acct_name >= 0) {
                        v_bank_acct_name.arr[v_bank_acct_name.len] = '\0';
                        PutField_CString(myHash, "bank_acct_name", (const char*)v_bank_acct_name.arr);
DEBUGLOG(("get_bank_stmt_and_sms_count: bank_acct_name = [%s]\n", (const char*)v_bank_acct_name.arr));
                }

		// owner_name
		if (ind_owner_name >= 0) {
                        v_owner_name.arr[v_owner_name.len] = '\0';
                        PutField_CString(myHash, "owner_name", (const char*)v_owner_name.arr);
DEBUGLOG(("get_bank_stmt_and_sms_count: owner_name = [%s]\n", (const char*)v_owner_name.arr));
                }
	
		// bank_acct_num
		if (ind_bank_acct_num >= 0) {
                        v_bank_acct_num.arr[v_bank_acct_num.len] = '\0';
                        PutField_CString(myHash, "bank_acct_num", (const char*)v_bank_acct_num.arr);
DEBUGLOG(("get_bank_stmt_and_sms_count: bank_acct_num = [%s]\n", (const char*)v_bank_acct_num.arr));
                }
	
		// baid
		if (ind_baid >= 0) {
                        v_baid.arr[v_baid.len] = '\0';
                        PutField_CString(myHash, "baid", (const char*)v_baid.arr);
DEBUGLOG(("get_bank_stmt_and_sms_count: baid = [%s]\n", (const char*)v_baid.arr));
                }

		// stmt_cnt_p1
		if (v_stmt_cnt_p1>=0) {
                	PutField_Int(myHash, "stmt_cnt_p1", v_stmt_cnt_p1);
DEBUGLOG(("get_bank_stmt_and_sms_count: stmt_cnt_p1 = [%d]\n", v_stmt_cnt_p1));
        	}

		// sms_cnt_p1
		if (v_sms_cnt_p1>=0) {
                        PutField_Int(myHash, "sms_cnt_p1", v_sms_cnt_p1);
DEBUGLOG(("get_bank_stmt_and_sms_count: sms_cnt_p1 = [%d]\n", v_sms_cnt_p1));
                }	

		// stmt_cnt_p2
		if (v_stmt_cnt_p2>=0) {
                        PutField_Int(myHash, "stmt_cnt_p2", v_stmt_cnt_p2);
DEBUGLOG(("get_bank_stmt_and_sms_count: stmt_cnt_p2 = [%d]\n", v_stmt_cnt_p2));
                }

		// v_sms_cnt_p2
		if (v_sms_cnt_p2>=0) {
                        PutField_Int(myHash, "sms_cnt_p2", v_sms_cnt_p2);
DEBUGLOG(("get_bank_stmt_and_sms_count: sms_cnt_p2 = [%d]\n", v_sms_cnt_p2));
                }

                RecordSet_Add(rRecordSet, myHash);
        }

        /* EXEC SQL CLOSE c_cursor_getcount; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )158;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getcount_error;
}



	if (iCnt > 0) {
		iRet = PD_FOUND;
	} 

DEBUGLOG(("get_bank_stmt_and_sms_count: Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

getcount_error:
DEBUGLOG(("getcount_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("bank_stmt_and_sms_daily_report getcount_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        /* EXEC SQL CLOSE c_cursor_getcount; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )173;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getcount_error;
}


        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}


int cal_bank_stmt_and_sms_rate(const int iStmtCnt, const int iSmsCnt, hash_t *hRls)
{
	int	iRet = SUCCESS;

	int	iTotalCnt = 0;

	double	dStmtRate = 0.0;
	double	dSmsRate = 0.0;

	// Total Count
	iTotalCnt = iStmtCnt + iSmsCnt;

	if (iTotalCnt > 0) {

		// Cal Stmt Percentage Rate
		dStmtRate = (double)iStmtCnt/(double)iTotalCnt;

		// Cal Sms Percentage Rate
		dSmsRate = (double)iSmsCnt/(double)iTotalCnt;	
	} 
	
	// Stmt Percentage Rate
	PutField_Double(hRls,"stmt_rate",dStmtRate);
DEBUGLOG(("cal_bank_stmt_and_sms_rate: stmt_rate = [%1f]\n", dStmtRate));

	// Sms Percentage Rate
	PutField_Double(hRls,"sms_rate",dSmsRate);
DEBUGLOG(("cal_bank_stmt_and_sms_rate: sms_rate = [%1f]\n", dSmsRate));			

	return iRet;
}

