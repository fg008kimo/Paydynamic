
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
           char  filnam[24];
};
static struct sqlcxp sqlfpn =
{
    23,
    "check_psp_txn_report.pc"
};


static unsigned int sqlctx = 582349243;


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
"d to_date ( :b1 , 'DD-MON-YYYY HH24:\
MI:SS' ) and exists ( select 1 from txn_psp_detail where tp_txn_id = th_txn_i\
d and tp_psp_id = :b2 ) order by th . th_approval_timestamp desc            ";

 static char *sq0002 = 
"select count ( 1 ) , th_client_ip from ( select th_txn_id , th_client_ip fr\
om txn_header where th_txn_code = 'DSI' and th_status = 'W' and th_sub_status\
 = '102' and th_client_id not in ( select epm_party_id from email_check_party\
_map where epm_name = 'CHECK_PSP_TXN' and epm_group = 'EXCLUDE' and epm_party\
_type = 'C' and epm_support_multi_entry = 1 ) and th_create_timestamp between\
 to_date ( :b0 , 'DD-MON-YYYY HH24:MI:SS' ) and to_date ( :b1 , 'DD-MON-YYYY \
HH24:MI:SS' ) and exists ( select 1 from txn_psp_detail where tp_txn_id = th_\
txn_id and tp_psp_id = :b2 ) order by th_create_timestamp desc ) where rownum\
 <= :b3 group by th_client_ip order by count ( 1 ) desc            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,1213,0,9,645,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
32,0,0,1,0,0,13,647,0,0,14,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,1,0,0,2,9,0,0,2,9,0,0,
103,0,0,1,0,0,15,773,0,0,0,0,0,1,0,
118,0,0,1,0,0,15,787,0,0,0,0,0,1,0,
133,0,0,2,681,0,9,1104,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,
164,0,0,2,0,0,13,1106,0,0,2,0,0,1,0,2,3,0,0,2,9,0,0,
187,0,0,2,0,0,15,1138,0,0,0,0,0,1,0,
202,0,0,2,0,0,15,1152,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2016/07/27              Elvis Wong
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

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

int    	i_rpt_id = 0;
char    cs_rpt_datetime[PD_DATETIME_LEN + 1];
char	cs_rpt_type[PD_PSP_REPORT_TYPE_LEN + 1];
char    cDebug;

OBJPTR(DB);

int parse_arg(int argc,char **argv);
int get_psp_check_report_parameter(const char *csCode, char *csVal);
int get_psp_check_report_log(recordset_t *rRecordSet);
int gen_last_deposit_approve_table(recordset_t *rRecordSet);
int get_last_deposit_approve_record(hash_t *hRec);
int gen_pending_count_by_customer_ip_table(const char *csThresVal, recordset_t *rRecordSet);
int get_pending_count_by_customer_ip_record(const hash_t* hRls, recordset_t *rRecordSet);

int batch_init(int argc, char* argv[])
{
	if (argc < 3) {
        	printf("usage: -i rpt_id -d rpt_datetime -t rpt_type\n");
        	//return FAILURE;
    	}
    	//else
        	return SUCCESS;
}

int batch_proc(int argc, char* argv[])
{
	int 	iRet = SUCCESS;
	int 	iDtlRet = PD_FOUND;	

	char    *csPspRptShow = (char*) malloc (PD_PSP_REPORT_VALUE_LEN + 1);
	char    *csPspRptExactCntVal = (char*) malloc (PD_PSP_REPORT_VALUE_LEN + 1);

        recordset_t	*rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	iRet = parse_arg(argc,argv);

        if (iRet != SUCCESS) {
                printf("usage: -i rpt_id -d rpt_datetime -t rpt_type\n");
                return SUCCESS;
        }

	// Get Psp Txn Check Report Parameter (code = SHOW)
	if (iRet == SUCCESS) {

		iDtlRet = get_psp_check_report_parameter(PD_PSP_REPORT_CODE_SHOW, csPspRptShow);
		if (iDtlRet == PD_FOUND) {

DEBUGLOG(("batch_proc:: csPspRptShow = [%s]\n",csPspRptShow));
			if (strcmp(csPspRptShow, PD_PSP_REPORT_VAL_ON)) {
                            	iRet = FAILURE;
DEBUGLOG(("batch_proc:: PSP Report Parameter Value OFF!!!\n"));
			}
		} else {
			iRet = FAILURE;
		}
	}

	// Get Psp Txn Check Report Log
	if (iRet == SUCCESS) {

		iDtlRet = get_psp_check_report_log(rRecordSet);
		if (iDtlRet != PD_FOUND) {
                        iRet = FAILURE;
                }
	} 

	// Generate Last Deposit Approve Table
	if (iRet == SUCCESS) {

		iRet = gen_last_deposit_approve_table(rRecordSet);
	}

	// Generate Pending Count By Customer IP Table
	if (iRet == SUCCESS) {

		// Get Psp Txn Check Report Parameter (code = EXACT_CNT_VALUE)
                iDtlRet = get_psp_check_report_parameter(PD_PSP_REPORT_CODE_EXACT_CNT_VALUE, csPspRptExactCntVal);
		if (iDtlRet == PD_FOUND) {

DEBUGLOG(("batch_proc:: csPspRptExactCntVal = [%s]\n",csPspRptExactCntVal));
			iRet = gen_pending_count_by_customer_ip_table(csPspRptExactCntVal, rRecordSet);
                } else {
                        iRet = FAILURE;
                }
	} 

	RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);

	FREE_ME(csPspRptShow);
	FREE_ME(csPspRptExactCntVal);

DEBUGLOG(("batch_proc:: return = [%d]\n", iRet));
	return iRet;
}

int batch_terminate(int argc, char* argv[])
{
        return SUCCESS;
}

int parse_arg(int argc,char **argv)
{
        char    c;
	i_rpt_id = 0;
        strcpy(cs_rpt_datetime,"");
        strcpy(cs_rpt_type,"");

        while ((c = getopt(argc,argv,"i:d:t:")) != EOF) {
                switch (c) {
			case 'i':
				i_rpt_id = atoi(optarg);
				break;
                        case 'd':
                                strcpy(cs_rpt_datetime, optarg);
                                break;
			case 't':
                                strcpy(cs_rpt_type, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if ((i_rpt_id == 0) || (!strcmp(cs_rpt_datetime,"")) || (!strcmp(cs_rpt_type,"")))
                return FAILURE;

        return SUCCESS;
}

int get_psp_check_report_parameter(const char *csCode, char *csVal)
{
        int     iRet = PD_FOUND;

	char	*csTmp = NULL;

        hash_t  *hData;
        hData = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hData,0);

	// rpt_type
        PutField_CString(hData,"rpt_type",cs_rpt_type);
DEBUGLOG(("get_psp_check_report_parameter:: rpt_type = [%s]\n", cs_rpt_type));

	// code
        PutField_CString(hData,"code",csCode);
DEBUGLOG(("get_psp_check_report_parameter:: code = [%s]\n", csCode));

        // Get Psp Txn Check Report Parameter
DEBUGLOG(("get_psp_check_report_parameter:: Call DBPspTxnCheckReportParameter:: GetPspTxnCheckReportParameter\n"));
       	DBObjPtr = CreateObj(DBPtr,"DBPspTxnCheckReportParameter","GetPspTxnCheckReportParameter");
      	iRet = (unsigned long)(*DBObjPtr)(hData);
       	if (iRet != PD_FOUND) {
DEBUGLOG(("get_psp_check_report_parameter:: Call DBPspTxnCheckReportParameter:: GetPspTxnCheckReportParameter Not Found!!!\n"));
ERRLOG("check_psp_txn_report::get_psp_check_report_parameter::Call DBPspTxnCheckReportParameter::GetPspTxnCheckReportParameter Not Found!!!\n");
       	} else {

/* val */
           	if (GetField_CString(hData,"val",&csTmp)) {
			sprintf(csVal, "%s", csTmp);
DEBUGLOG(("get_psp_check_report_parameter:: Call DBPspTxnCheckReportParameter:: GetPspTxnCheckReportParameter:: val = [%s]\n",csVal));
               	} else {
DEBUGLOG(("get_psp_check_report_parameter:: Call DBPspTxnCheckReportParameter:: GetPspTxnCheckReportParameter invalid val!!!\n"));
ERRLOG("check_psp_txn_report::get_psp_check_report_parameter::Call DBPspTxnCheckReportParameter::GetPspTxnCheckReportParameter invalid val!!!\n");
		}
    	}

	FREE_ME(hData);

	return iRet;
}

int get_psp_check_report_log(recordset_t *rRecordSet)
{
	int     iRet = PD_FOUND;

	int     iCnt = 0;
        int     iTmp = 0;
        char    *csTmp = NULL;
        char    cTmp;

	hash_t  *hRec;

	hash_t  *hData;
        hData = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hData,0);

	// rpt_id
        PutField_Int(hData,"rpt_gen_id",i_rpt_id);
DEBUGLOG(("get_psp_check_report_log:: rpt_id = [%d]\n", i_rpt_id));

        // rpt_datetime
        PutField_CString(hData,"rpt_gen_datetime",cs_rpt_datetime);
DEBUGLOG(("get_psp_check_report_log:: rpt_datetime = [%s]\n", cs_rpt_datetime));

        // rpt_type
        PutField_CString(hData,"rpt_type",cs_rpt_type);
DEBUGLOG(("get_psp_check_report_log:: rpt_type = [%s]\n", cs_rpt_type));

DEBUGLOG(("get_psp_check_report_log:: Call DBPspTxnCheckReportLog:: GetPspTxnCheckReportLog\n"));
       	DBObjPtr = CreateObj(DBPtr,"DBPspTxnCheckReportLog","GetPspTxnCheckReportLog");
      	iRet = (unsigned long)(*DBObjPtr)(hData, rRecordSet);
    	if (iRet == PD_FOUND) {

              	hRec = RecordSet_GetFirst(rRecordSet);
              	while (hRec) {

/* seq */
                    	if (GetField_Int(hRec, "seq", &iTmp)) {
DEBUGLOG(("get_psp_check_report_log:: Call DBPspTxnCheckReportLog:: GetPspTxnCheckReportLog:: [%d][seq] = [%d]\n", iCnt, iTmp));
                      	}

/* party_type */
                    	if (GetField_Char(hRec, "party_type", &cTmp)) {
DEBUGLOG(("get_psp_check_report_log:: Call DBPspTxnCheckReportLog:: GetPspTxnCheckReportLog:: [%d][party_type] = [%c]\n", iCnt, cTmp));
                     	}

/* party_id */
                    	if (GetField_CString(hRec, "party_id", &csTmp)) {
DEBUGLOG(("get_psp_check_report_log:: Call DBPspTxnCheckReportLog:: GetPspTxnCheckReportLog:: [%d][party_id] = [%s]\n", iCnt, csTmp));
                     	}

/* party_name */
                     	if (GetField_CString(hRec, "party_name", &csTmp)) {
DEBUGLOG(("get_psp_check_report_log:: Call DBPspTxnCheckReportLog:: GetPspTxnCheckReportLog:: [%d][party_name] = [%s]\n", iCnt, csTmp));
                     	}

/* bank_code */
                   	if (GetField_CString(hRec, "bank_code", &csTmp)) {
DEBUGLOG(("get_psp_check_report_log:: Call DBPspTxnCheckReportLog:: GetPspTxnCheckReportLog:: [%d][bank_code] = [%s]\n", iCnt, csTmp));
                   	}

/* bank_name */
                      	if (GetField_CString(hRec, "bank_name", &csTmp)) {
DEBUGLOG(("get_psp_check_report_log:: Call DBPspTxnCheckReportLog:: GetPspTxnCheckReportLog:: [%d][bank_name] = [%s]\n", iCnt, csTmp));
                     	}

/* dur_start */
                     	if (GetField_CString(hRec, "dur_start", &csTmp)) {
DEBUGLOG(("get_psp_check_report_log:: Call DBPspTxnCheckReportLog:: GetPspTxnCheckReportLog:: [%d][dur_start] = [%s]\n", iCnt, csTmp));
                        }

/* dur_end */
                    	if (GetField_CString(hRec, "dur_end", &csTmp)) {
DEBUGLOG(("get_psp_check_report_log:: Call DBPspTxnCheckReportLog:: GetPspTxnCheckReportLog:: [%d][dur_end] = [%s]\n", iCnt, csTmp));
                      	}

/* succ_cnt */
                     	if (GetField_Int(hRec, "succ_cnt", &iTmp)) {
DEBUGLOG(("get_psp_check_report_log:: Call DBPspTxnCheckReportLog:: GetPspTxnCheckReportLog:: [%d][succ_cnt] = [%d]\n", iCnt, iTmp));
                      	}

/* pend_cnt */
                   	if (GetField_Int(hRec, "pend_cnt", &iTmp)) {
DEBUGLOG(("get_psp_check_report_log:: Call DBPspTxnCheckReportLog:: GetPspTxnCheckReportLog:: [%d][pend_cnt] = [%d]\n", iCnt, iTmp));
                     	}

/* total_cnt */
                   	if (GetField_Int(hRec, "total_cnt", &iTmp)) {
DEBUGLOG(("get_psp_check_report_log:: Call DBPspTxnCheckReportLog:: GetPspTxnCheckReportLog:: [%d][total_cnt] = [%d]\n", iCnt, iTmp));
                     	}

                      	iCnt++;

                	hRec = RecordSet_GetNext(rRecordSet);
             	}
    	} else if (iRet == PD_NOT_FOUND) {
DEBUGLOG(("get_psp_check_report_log:: Call DBPspTxnCheckReportLog:: GetPspTxnCheckReportLog Not Found!!!\n"));
	} else {
DEBUGLOG(("get_psp_check_report_log:: Call DBPspTxnCheckReportLog:: GetPspTxnCheckReportLog Error!!!\n"));
ERRLOG("check_psp_txn_report::get_psp_check_report_log::Call DBPspTxnCheckReportLog::GetPspTxnCheckReportLog Error!!!\n");
	}	

	FREE_ME(hData);	

	return iRet;
}

int gen_last_deposit_approve_table(recordset_t *rRecordSet)
{
	int     iRet = SUCCESS;
	int	iDtlRet = PD_NOT_FOUND;

	int	iCnt = 0;
	int	iFound = 0;	
	int	iSuccCnt = 0;	
	double  dTxnAmt = 0.0;
	double	dTmp = 0.0;
	char	*csPspId = NULL;
	char	*csPspName = NULL;
	char	*csDurStart = NULL;
	char	*csDurEnd = NULL;
	char	*csTxnId = NULL;
	char	*csUpdateTimestamp = NULL;
	char	*csCreateTimestamp = NULL;
	char	*csMerchShortName = NULL;
	char	*csMerchantRef = NULL;
	char	*csTxnCcy = NULL;
	char	*csBankName = NULL;
	char    *csApprovalTimestamp = NULL;	
	char	*csSubStatus = NULL;	
	char	*csStatusName = NULL;
	char	*csTmp = NULL;
	char    cStatus;
	char	cARInd;
	char	cPartyType;

	hash_t  *hRec;	

	hash_t  *hLastAppDepAddRec;
        hash_t  *hLastAppDepGetRec;
        recordset_t     *rLastAppDepRecordSet;
        rLastAppDepRecordSet = (recordset_t *)malloc (sizeof(recordset_t));
        recordset_init(rLastAppDepRecordSet,0);

	// Get Last Deposit Approve Record        
	hRec = RecordSet_GetFirst(rRecordSet);
       	while ((hRec) && (iRet == SUCCESS)) {

/* succ_cnt */
		if (GetField_Int(hRec,"succ_cnt",&iSuccCnt)) {
DEBUGLOG(("gen_last_deposit_approve_table:: [%d][succ_cnt] = [%d]\n",iCnt,iSuccCnt));
		}

		// Check Success Counter > 0 
		if (iSuccCnt > 0) {
		
			iDtlRet = get_last_deposit_approve_record(hRec);
			if (iDtlRet == PD_FOUND) {

				iFound++;

				hLastAppDepAddRec = (hash_t*) malloc (sizeof(hash_t));
                        	hash_init(hLastAppDepAddRec, 0);

/* party_type */	
				if (GetField_Char(hRec,"party_type",&cPartyType)) {
                			if (cPartyType == PD_TYPE_PSP) {
/* psp_id */
						if (GetField_CString(hRec,"party_id",&csTmp)) {
DEBUGLOG(("gen_last_deposit_approve_table:: [%d][psp_id] = [%s]\n",iCnt,csTmp));
							PutField_CString(hLastAppDepAddRec,"psp_id",csTmp);
        					}

/* psp_name */
        					if (GetField_CString(hRec,"party_name",&csTmp)) {
DEBUGLOG(("gen_last_deposit_approve_table:: [%d][psp_name] = [%s]\n",iCnt,csTmp));
							PutField_CString(hLastAppDepAddRec,"psp_name",csTmp);
        					}
					}
				}

/* dur_start */
        			if (GetField_CString(hRec,"dur_start",&csTmp)) {
DEBUGLOG(("gen_last_deposit_approve_table:: [%d][dur_start] = [%s]\n",iCnt,csTmp));
					PutField_CString(hLastAppDepAddRec,"dur_start",csTmp);
        			}

/* dur_end */
        			if (GetField_CString(hRec,"dur_end",&csTmp)) {
DEBUGLOG(("gen_last_deposit_approve_table:: [%d][dur_end] = [%s]\n",iCnt,csTmp));
					PutField_CString(hLastAppDepAddRec,"dur_end",csTmp);
        			}

/* txn_id */
        			if (GetField_CString(hRec,"txn_seq",&csTmp)) {
DEBUGLOG(("gen_last_deposit_approve_table:: [%d][txn_id] = [%s]\n",iCnt,csTmp));
					PutField_CString(hLastAppDepAddRec,"txn_seq",csTmp);
        			}

/* update_timestamp */
        			if (GetField_CString(hRec,"update_timestamp",&csTmp)) {
DEBUGLOG(("gen_last_deposit_approve_table:: [%d][update_timestamp] = [%s]\n",iCnt,csTmp));
					PutField_CString(hLastAppDepAddRec,"update_timestamp",csTmp);
        			}

/* create_timestamp */
        			if (GetField_CString(hRec,"create_timestamp",&csTmp)) {
DEBUGLOG(("gen_last_deposit_approve_table:: [%d][create_timestamp] = [%s]\n",iCnt,csTmp));
					PutField_CString(hLastAppDepAddRec,"create_timestamp",csTmp);
        			}

/* merch_short_name */
        			if (GetField_CString(hRec,"merch_short_name",&csTmp)) {
DEBUGLOG(("gen_last_deposit_approve_table:: [%d][merch_short_name] = [%s]\n",iCnt,csTmp));
					PutField_CString(hLastAppDepAddRec,"merch_short_name",csTmp);
        			}

/* merchant_reference */
        			if (GetField_CString(hRec,"merchant_ref",&csTmp)) {
DEBUGLOG(("gen_last_deposit_approve_table:: [%d][merchant_ref] = [%s]\n",iCnt,csTmp));
					PutField_CString(hLastAppDepAddRec,"merchant_ref",csTmp);
        			}

/* txn_ccy */
        			if (GetField_CString(hRec,"txn_ccy",&csTmp)) {
DEBUGLOG(("gen_last_deposit_approve_table:: [%d][txn_ccy] = [%s]\n",iCnt,csTmp));
					PutField_CString(hLastAppDepAddRec,"txn_ccy",csTmp);
       	 			}

/* txn_amt */
        			if (GetField_Double(hRec,"txn_amt",&dTmp)) {
DEBUGLOG(("gen_last_deposit_approve_table:: [%d][txn_amt] = [%.2f]\n",iCnt,dTmp));
					PutField_Double(hLastAppDepAddRec,"txn_amt",dTmp);
        			}

/* bank_name */
        			if (GetField_CString(hRec,"bank_name",&csTmp)) {
DEBUGLOG(("gen_last_deposit_approve_table:: [%d][bank_name] = [%s]\n",iCnt,csTmp));
					PutField_CString(hLastAppDepAddRec,"bank_name",csTmp);
        			}

/* status */
        			if (GetField_Char(hRec,"status",&cStatus)) {
DEBUGLOG(("gen_last_deposit_approve_table:: [%d][status] = [%c]\n",iCnt,cStatus));

/* ar_ind */	
					if (GetField_Char(hRec,"ar_ind",&cARInd)) {
DEBUGLOG(("gen_last_deposit_approve_table:: [%d][ar_ind] = [%c]\n",iCnt,cARInd));

						if ((cStatus = PD_COMPLETE) && (cARInd = PD_ACCEPT)) {
							PutField_CString(hLastAppDepAddRec,"status_name","Approved");
						}
					}
				}

/* sub_status */
        			if (GetField_CString(hRec,"sub_status",&csTmp)) {
DEBUGLOG(("gen_last_deposit_approve_table:: [%d][sub_status] = [%s]\n",iCnt,csTmp));
					PutField_CString(hLastAppDepAddRec,"sub_status",csTmp);
        			}

/* approval_timestamp */
        			if (GetField_CString(hRec,"approval_timestamp",&csTmp)) {
DEBUGLOG(("gen_last_deposit_approve_table:: [%d][approval_timestamp] = [%s]\n",iCnt,csTmp));
					PutField_CString(hLastAppDepAddRec,"approval_timestamp",csTmp);
        			}

				RecordSet_Add(rLastAppDepRecordSet, hLastAppDepAddRec);

			} else if (iDtlRet == PD_NOT_FOUND) {
DEBUGLOG(("gen_last_deposit_approve_table:: get_last_deposit_approve_record:: No Record Found!!!\n"));
			} else {
				iRet = FAILURE;
DEBUGLOG(("gen_last_deposit_approve_table:: get_last_deposit_approve_record:: Error!!!\n"));
ERRLOG("check_psp_txn_report::gen_last_deposit_approve_table::get_last_deposit_approve_record::Error!!!\n");
			}
		}

		iCnt++;

		hRec = RecordSet_GetNext(rRecordSet);
        }

	// Generate Last Deposit Approve Table
	if ((iRet == SUCCESS) && (iFound > 0)) {

		printf("<br><b>Last approved deposit</b><br>\n");
        	printf("<html><body><table border=\"1\">\n");
        	printf("<tr align=\"center\"><b><td>Duration Start</td><td>Duration End</td><td>PSP Account Name</td><td>Transaction ID</td><td>Last Update Date</td><td>Create Time</td><td>Merchant Short Name</td><td>Merchant Reference</td><td>Transaction Amount</td><td>Consumer Deposit Bank</td><td>Status</td><td>Sub Status</td><td>Approval Time</td></b></tr>\n");

		hLastAppDepGetRec = RecordSet_GetFirst(rLastAppDepRecordSet);
        	while (hLastAppDepGetRec) {

			GetField_CString(hLastAppDepGetRec,"psp_id",&csPspId);
			GetField_CString(hLastAppDepGetRec,"psp_name",&csPspName);
			GetField_CString(hLastAppDepGetRec,"dur_start",&csDurStart);
			GetField_CString(hLastAppDepGetRec,"dur_end",&csDurEnd);
			GetField_CString(hLastAppDepGetRec,"txn_seq",&csTxnId);
			GetField_CString(hLastAppDepGetRec,"update_timestamp",&csUpdateTimestamp);
			GetField_CString(hLastAppDepGetRec,"create_timestamp",&csCreateTimestamp);
			GetField_CString(hLastAppDepGetRec,"merch_short_name",&csMerchShortName);
			GetField_CString(hLastAppDepGetRec,"merchant_ref",&csMerchantRef);
			GetField_CString(hLastAppDepGetRec,"txn_ccy",&csTxnCcy);
			GetField_Double(hLastAppDepGetRec,"txn_amt",&dTxnAmt);
			GetField_CString(hLastAppDepGetRec,"bank_name",&csBankName);
			GetField_CString(hLastAppDepGetRec,"status_name",&csStatusName);			
			GetField_CString(hLastAppDepGetRec,"sub_status",&csSubStatus);
			GetField_CString(hLastAppDepGetRec,"approval_timestamp",&csApprovalTimestamp);

			//printf("<tr align=\"center\"><td>%s</td><td>%s</td><td>%s (%s)</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s %.2f</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>\n",csDurStart,csDurEnd,csPspName,csPspId,csTxnId,csUpdateTimestamp,csCreateTimestamp,csMerchShortName,csMerchantRef,csTxnCcy,dTxnAmt,csBankName,csStatusName,csSubStatus,csApprovalTimestamp);
			printf("<tr align=\"center\"><td>%s</td><td>%s</td><td>%s (%s)</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%.2f</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>\n",csDurStart,csDurEnd,csPspName,csPspId,csTxnId,csUpdateTimestamp,csCreateTimestamp,csMerchShortName,csMerchantRef,dTxnAmt,csBankName,csStatusName,csSubStatus,csApprovalTimestamp);
			
			hLastAppDepGetRec = RecordSet_GetNext(rLastAppDepRecordSet);
		}
	
		printf("</table></body></html>\n");
	}
	
	RecordSet_Destroy(rLastAppDepRecordSet);
        FREE_ME(rLastAppDepRecordSet);

	//FREE_ME(hLastAppDepAddRec);

DEBUGLOG(("gen_last_deposit_approve_table:: iRet = [%d]\n",iRet));
	return iRet;	
}

int get_last_deposit_approve_record(hash_t *hRec)
{
	int	iCnt = 0;
	char	cPartyType;
	char 	*csTmp = NULL;

	/* EXEC SQL WHENEVER SQLERROR GOTO getdeprec_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar 	hv_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } hv_psp_id;

		/* varchar         hv_dur_start[PD_TIMESTAMP_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_dur_start;

                /* varchar         hv_dur_end[PD_TIMESTAMP_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_dur_end;


                /* varchar         v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar         v_update_timestamp[PD_TIMESTAMP_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_update_timestamp;

		/* varchar         v_create_timestamp[PD_TIMESTAMP_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_create_timestamp;

		/* varchar         v_client_ip[PD_IP_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_client_ip;

		/* varchar         v_merch_short_name[PD_MERCH_SHORT_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_merch_short_name;

		/* varchar		v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar         v_txn_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

		double          v_txn_amt;
		/* varchar		v_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

		/* varchar 	v_bank_name[PD_AC_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

		char            v_status;
		char            v_ar_ind;
		/* varchar         v_sub_status[PD_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_sub_status;

		/* varchar         v_approval_timestamp[PD_TIMESTAMP_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_approval_timestamp;
			

		short           ind_txn_id = -1;
                short           ind_update_timestamp = -1;
                short           ind_create_timestamp = -1;
                short           ind_client_ip = -1;
                short           ind_merch_short_name = -1;
                short           ind_merchant_ref = -1;
                short           ind_txn_ccy = -1;
                short           ind_txn_amt = -1;
                short           ind_bank_code = -1;
                short           ind_bank_name = -1;
                short           ind_status = -1;
                short           ind_ar_ind = -1;
                short           ind_sub_status = -1;
                short           ind_approval_timestamp = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


// psp_id
       	if (GetField_Char(hRec,"party_type",&cPartyType)) {
             	if (cPartyType == PD_TYPE_PSP) {
			if (GetField_CString(hRec,"party_id",&csTmp)) {
DEBUGLOG(("get_last_deposit_approve_record:: psp_id = [%s]\n",csTmp));
				hv_psp_id.len = strlen((char*)csTmp);
        			memcpy(hv_psp_id.arr,csTmp,hv_psp_id.len);
			}
		}
	}

// dur_start
	if (GetField_CString(hRec,"dur_start",&csTmp)) {
DEBUGLOG(("get_last_deposit_approve_record:: dur_start = [%s]\n",csTmp));
        	hv_dur_start.len = strlen((char*)csTmp);
        	memcpy(hv_dur_start.arr,csTmp,hv_dur_start.len);
	}

// dur_end
	if (GetField_CString(hRec,"dur_end",&csTmp)) {
DEBUGLOG(("get_last_deposit_approve_record:: dur_end = [%s]\n",csTmp));
		hv_dur_end.len = strlen((char*)csTmp);
        	memcpy(hv_dur_end.arr,csTmp,hv_dur_end.len);
	}

	/* EXEC SQL DECLARE c_cursor_getdeprec CURSOR FOR

		select  th.th_txn_id,
			to_char(th.th_update_timestamp,'DD/MM/YYYY HH24:MI'),
			to_char(th.th_create_timestamp,'DD/MM/YYYY HH24:MI'),
			th.th_client_ip,
			md.short_name,
			th.th_merchant_ref,
			tp.tp_txn_ccy,
			tp.tp_txn_amount,
			bd.internal_bank_code,
			bd.bank_name,
			th.th_status,
			th.th_ar_ind,
			ds.ds_name,
			to_char(th.th_approval_timestamp,'DD/MM/YYYY HH24:MI')
		from 	txn_header th,
			txn_psp_detail tp,
			merch_detail md,
			bank_desc bd,
			def_sub_status ds
		where 	md.merchant_id = th.th_merchant_id
		and   	tp.tp_txn_id = th.th_txn_id
		and   	bd.internal_bank_code = tp.tp_bank_code
		and	ds.ds_sub_status = th.th_sub_status
		and   	th.th_txn_code = 'DSI'
		and   	th.th_status = 'C'
		and   	th.th_ar_ind = 'A'
		and   	th.th_client_id not in (           
                		select 	epm_party_id        
                		from 	email_check_party_map        
                		where 	epm_name = 'CHECK_PSP_TXN'        
                		and 	epm_group = 'EXCLUDE'        
                		and 	epm_party_type = 'C'        
                		and 	epm_support_multi_entry = 1        
                		/o'C1000002','C1000013'o/)         
		and 	th.th_create_timestamp between to_date(:hv_dur_start, 'DD-MON-YYYY HH24:MI:SS')                   
                            			and to_date(:hv_dur_end, 'DD-MON-YYYY HH24:MI:SS')
		and 	exists (select  1
            			from    txn_psp_detail
            			where   tp_txn_id = th_txn_id
            			and     tp_psp_id = :hv_psp_id)
		//order by th.th_create_timestamp desc;
		order by th.th_approval_timestamp desc; */ 


	/* EXEC SQL OPEN c_cursor_getdeprec; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "select th . th_txn_id , to_char ( th . th_update_timestamp , 'DD/MM/YYYY\
 HH24:MI' ) , to_char ( th . th_create_timestamp , 'DD/MM/YYYY HH24:MI' ) , \
th . th_client_ip , md . short_name , th . th_merchant_ref , tp . tp_txn_ccy\
 , tp . tp_txn_amount , bd . internal_bank_code , bd . bank_name , th . th_s\
tatus , th . th_ar_ind , ds . ds_name , to_char ( th . th_approval_timestamp\
 , 'DD/MM/YYYY HH24:MI' ) from txn_header th , txn_psp_detail tp , merch_det\
ail md , bank_desc bd , def_sub_status ds where md . merchant_id = th . th_m\
erchant_id and tp . tp_txn_id = th . th_txn_id and bd . internal_bank_code =\
 tp . tp_bank_code and ds . ds_sub_status = th . th_sub_status and th . th_t\
xn_code = 'DSI' and th . th_status = 'C' and th . th_ar_ind = 'A' and th . t\
h_client_id not in ( select epm_party_id from email_check_party_map where ep\
m_name = 'CHECK_PSP_TXN' and epm_group = 'EXCLUDE' and epm_party_type = 'C' \
and epm_support_multi_entry = 1 ) and th . th_create_timestamp between to_da\
te ( :b0 , 'DD-MON-YYYY HH24:MI:SS' ) an");
 sqlstm.stmt = sq0001;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_dur_start;
 sqlstm.sqhstl[0] = (unsigned long )23;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_dur_end;
 sqlstm.sqhstl[1] = (unsigned long )23;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[2] = (unsigned long )13;
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
 if (sqlca.sqlcode < 0) goto getdeprec_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getdeprec
		INTO
                        :v_txn_id:ind_txn_id,
                        :v_update_timestamp:ind_update_timestamp,
                        :v_create_timestamp:ind_create_timestamp,
                        :v_client_ip:ind_client_ip,
                        :v_merch_short_name:ind_merch_short_name,
			:v_merchant_ref:ind_merchant_ref,
			:v_txn_ccy:ind_txn_ccy,
			:v_txn_amt:ind_txn_amt,
			:v_bank_code:ind_bank_code,
			:v_bank_name:ind_bank_name,
			:v_status:ind_status,
			:v_ar_ind:ind_ar_ind,
			:v_sub_status:ind_sub_status,
                        :v_approval_timestamp:ind_approval_timestamp; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 14;
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
                sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_id;
                sqlstm.sqhstl[0] = (unsigned long )19;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_txn_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_update_timestamp;
                sqlstm.sqhstl[1] = (unsigned long )23;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_update_timestamp;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_create_timestamp;
                sqlstm.sqhstl[2] = (unsigned long )23;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_create_timestamp;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_client_ip;
                sqlstm.sqhstl[3] = (unsigned long )28;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_client_ip;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_merch_short_name;
                sqlstm.sqhstl[4] = (unsigned long )23;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_merch_short_name;
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
                sqlstm.sqhstv[6] = (unsigned char  *)&v_txn_ccy;
                sqlstm.sqhstl[6] = (unsigned long )6;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_txn_ccy;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_txn_amt;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_txn_amt;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_bank_code;
                sqlstm.sqhstl[8] = (unsigned long )13;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_bank_code;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_bank_name;
                sqlstm.sqhstl[9] = (unsigned long )153;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_bank_name;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_status;
                sqlstm.sqhstl[10] = (unsigned long )1;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_status;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_ar_ind;
                sqlstm.sqhstl[11] = (unsigned long )1;
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_ar_ind;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
                sqlstm.sqhstv[12] = (unsigned char  *)&v_sub_status;
                sqlstm.sqhstl[12] = (unsigned long )53;
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_sub_status;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
                sqlstm.sqhstv[13] = (unsigned char  *)&v_approval_timestamp;
                sqlstm.sqhstl[13] = (unsigned long )23;
                sqlstm.sqhsts[13] = (         int  )0;
                sqlstm.sqindv[13] = (         short *)&ind_approval_timestamp;
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
                if (sqlca.sqlcode < 0) goto getdeprec_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		if (iCnt > 0) {
			break;
		} else {
			// total_record
                	iCnt ++;
			PutField_Int(hRec,"total_record",iCnt);
		}

/* txn_id */
                if (ind_txn_id >= 0) {
                        v_txn_id.arr[v_txn_id.len] = '\0';
                        PutField_CString(hRec,"txn_seq",(const char*)v_txn_id.arr);
DEBUGLOG(("get_last_deposit_approve_record:: txn_id = [%s]\n",v_txn_id.arr));
                }

/* update_timestamp */
                if (ind_update_timestamp >= 0) {
                        v_update_timestamp.arr[v_update_timestamp.len] = '\0';
                        PutField_CString(hRec,"update_timestamp",(const char*)v_update_timestamp.arr);
DEBUGLOG(("get_last_deposit_approve_record:: update_timestamp = [%s]\n",v_update_timestamp.arr));
                }

/* create_timestamp */
                if (ind_create_timestamp >= 0) {
                        v_create_timestamp.arr[v_create_timestamp.len] = '\0';
                        PutField_CString(hRec,"create_timestamp",(const char*)v_create_timestamp.arr);
DEBUGLOG(("get_last_deposit_approve_record:: create_timestamp = [%s]\n",v_create_timestamp.arr));
                }

/* client_ip */
                if (ind_client_ip >= 0) {
                        v_client_ip.arr[v_client_ip.len] = '\0';
                        PutField_CString(hRec,"client_ip",(const char*)v_client_ip.arr);
DEBUGLOG(("get_last_deposit_approve_record:: client_ip = [%s]\n",v_client_ip.arr));
                }

/* merch_short_name */
                if (ind_merch_short_name >= 0) {
                        v_merch_short_name.arr[v_merch_short_name.len] = '\0';
                        PutField_CString(hRec,"merch_short_name",(const char*)v_merch_short_name.arr);
DEBUGLOG(("get_last_deposit_approve_record:: merch_short_name = [%s]\n",v_merch_short_name.arr));
                }

/* merchant_ref */
                if (ind_merchant_ref >= 0) {
                        v_merchant_ref.arr[v_merchant_ref.len] = '\0';
                        PutField_CString(hRec,"merchant_ref",(const char*)v_merchant_ref.arr);
DEBUGLOG(("get_last_deposit_approve_record:: merchant_ref = [%s]\n",v_merchant_ref.arr));
                }

/* txn_ccy */
                if (ind_txn_ccy >= 0) {
                        v_txn_ccy.arr[v_txn_ccy.len] = '\0';
                        PutField_CString(hRec,"txn_ccy",(const char*)v_txn_ccy.arr);
DEBUGLOG(("get_last_deposit_approve_record:: txn_ccy = [%s]\n",v_txn_ccy.arr));
                }

/* txn_amt */
		if (ind_txn_amt >= 0){
                        PutField_Double(hRec,"txn_amt",v_txn_amt);
DEBUGLOG(("get_last_deposit_approve_record:: txn_amt = [%lf]\n",v_txn_amt));
                }		
		
/* bank_code */
                if (ind_bank_code >= 0) {
                        v_bank_code.arr[v_bank_code.len] = '\0';
                        PutField_CString(hRec,"bank_code",(const char*)v_bank_code.arr);
DEBUGLOG(("get_last_deposit_approve_record:: bank_code = [%s]\n",v_bank_code.arr));
                }

/* bank_name */
                if (ind_bank_name >= 0) {
                        v_bank_name.arr[v_bank_name.len] = '\0';
                        PutField_CString(hRec,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG(("get_last_deposit_approve_record:: bank_name = [%s]\n",v_bank_name.arr));
                }

/* status */
                if (ind_status >= 0) {
                        PutField_Char(hRec,"status",v_status);
DEBUGLOG(("get_last_deposit_approve_record:: status = [%c]\n",v_status));
                }

/* ar_ind */
                if (ind_ar_ind >=  0) {
                        PutField_Char(hRec,"ar_ind",v_ar_ind);
DEBUGLOG(("get_last_deposit_approve_record:: ar_ind = [%c]\n",v_ar_ind));
                }

/* sub_status */
                if (ind_sub_status >= 0) {
                        v_sub_status.arr[v_sub_status.len] = '\0';
                        PutField_CString(hRec,"sub_status",(const char*)v_sub_status.arr);
DEBUGLOG(("get_last_deposit_approve_record:: sub_status = [%s]\n",v_sub_status.arr));
                }

/* approval_timestamp */
                if (ind_approval_timestamp >= 0) {
                        v_approval_timestamp.arr[v_approval_timestamp.len] = '\0';
                        PutField_CString(hRec,"approval_timestamp",(const char*)v_approval_timestamp.arr);
DEBUGLOG(("get_last_deposit_approve_record:: approval_timestamp = [%s]\n",v_approval_timestamp.arr));
                }
	} 
	while(PD_TRUE);
        
	/* EXEC SQL CLOSE c_cursor_getdeprec; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )103;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getdeprec_error;
}



	if (iCnt > 0) {
DEBUGLOG(("get_last_deposit_approve_record Normal Exit\n"));
                return  PD_FOUND;
        } else {
DEBUGLOG(("get_last_deposit_approve_record Normal Exit Not Found\n"));
                return  PD_NOT_FOUND;
        }

getdeprec_error:
DEBUGLOG(("getdeprec_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getdeprec; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 14;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )118;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int gen_pending_count_by_customer_ip_table(const char *csThresVal, recordset_t *rRecordSet)
{
	int     iRet = SUCCESS;
        int     iDtlRet = PD_NOT_FOUND;

	int	iCnt = 0;
	int	iSubCnt = 0;
	int	iThresVal = 0;
	int	iNumOfPendCntGTThresVal = 0;
	int	iNumOfPendCntEQThresVal = 0;
     	int    	iPendCntByIP = 0;
     	int    	iTotalPendCnt = 0;
	int	iFoundGTThresVal = 0;
	int	iFoundEQThresVal = 0;
	char    *csPspId = NULL;
	char    *csPspName = NULL;
	char    *csDurStart = NULL;
	char    *csDurEnd = NULL;
        char    *csClientIP = NULL;
        char    cPartyType;

        hash_t  *hRec;

	hash_t	*hIPRec;
	recordset_t	*rIPRecordSet;
        rIPRecordSet = (recordset_t *)malloc (sizeof(recordset_t));
	recordset_init(rIPRecordSet,0);

	hash_t  *hGTThresValAddRec;
	hash_t  *hGTThresValGetRec;
        recordset_t     *rGTThresValRecordSet;
        rGTThresValRecordSet = (recordset_t *)malloc (sizeof(recordset_t));
	recordset_init(rGTThresValRecordSet,0);

	hash_t  *hEQThresValAddRec;
        hash_t  *hEQThresValGetRec;
        recordset_t     *rEQThresValRecordSet;
        rEQThresValRecordSet = (recordset_t *)malloc (sizeof(recordset_t));
        recordset_init(rEQThresValRecordSet,0);

	// Threshold Value (Integer)
	iThresVal = atoi(csThresVal);

	// Get Pending Count Group By Customer IP Record
	if (iRet == SUCCESS) {

        	hRec = RecordSet_GetFirst(rRecordSet);
        	while ((hRec) && (iRet == SUCCESS)) {
			
			hEQThresValAddRec = (hash_t*) malloc (sizeof(hash_t));
                      	hash_init(hEQThresValAddRec, 0);

/* party_type, psp_id, psp_name, dur_start, dur_end, total_pend_cnt */
                   	if (GetField_Char(hRec,"party_type",&cPartyType)) { 
                           	if (cPartyType == PD_TYPE_PSP) {
                                    	GetField_CString(hRec,"party_id",&csPspId);
                                   	GetField_CString(hRec,"party_name",&csPspName);
					GetField_CString(hRec,"dur_start",&csDurStart);
                        		GetField_CString(hRec,"dur_end",&csDurEnd);
                        		GetField_Int(hRec,"pend_cnt",&iTotalPendCnt);

                                        PutField_CString(hEQThresValAddRec,"psp_id",csPspId);
                                        PutField_CString(hEQThresValAddRec,"psp_name",csPspName);
                                        PutField_CString(hEQThresValAddRec,"dur_start",csDurStart);
                                        PutField_CString(hEQThresValAddRec,"dur_end",csDurEnd);
                            	}
                      	}

			iNumOfPendCntGTThresVal = 0;
			iNumOfPendCntEQThresVal = 0;

        		recordset_init(rIPRecordSet,0);
         	       	
			iDtlRet = get_pending_count_by_customer_ip_record(hRec, rIPRecordSet);
                	if (iDtlRet == PD_FOUND) {

DEBUGLOG(("gen_pending_count_by_customer_ip_table:: [%d][psp_id] = [%s]\n",iCnt,csPspId));
DEBUGLOG(("gen_pending_count_by_customer_ip_table:: [%d][psp_name] = [%s]\n",iCnt,csPspName));
DEBUGLOG(("gen_pending_count_by_customer_ip_table:: [%d][dur_start] = [%s]\n",iCnt,csDurStart));
DEBUGLOG(("gen_pending_count_by_customer_ip_table:: [%d][dur_end] = [%s]\n",iCnt,csDurEnd));
DEBUGLOG(("gen_pending_count_by_customer_ip_table:: [%d][total_pend_cnt] = [%d]\n",iCnt,iTotalPendCnt));

				hIPRec = RecordSet_GetFirst(rIPRecordSet);
				while (hIPRec) {

					hGTThresValAddRec = (hash_t*) malloc (sizeof(hash_t));
                        		hash_init(hGTThresValAddRec, 0);

					PutField_CString(hGTThresValAddRec,"psp_id",csPspId);
					PutField_CString(hGTThresValAddRec,"psp_name",csPspName);
					PutField_CString(hGTThresValAddRec,"dur_start",csDurStart);
					PutField_CString(hGTThresValAddRec,"dur_end",csDurEnd);

/* client_ip */
                                	if (GetField_CString(hIPRec,"client_ip",&csClientIP)) {
DEBUGLOG(("gen_pending_count_by_customer_ip_table:: [%d][%d][client_ip] = [%s]\n",iCnt,iSubCnt,csClientIP));
						PutField_CString(hGTThresValAddRec,"client_ip",csClientIP);
                                	}

/* pend_cnt_by_ip */
                                	if (GetField_Int(hIPRec,"pend_cnt_by_ip",&iPendCntByIP)) {
DEBUGLOG(("gen_pending_count_by_customer_ip_table:: [%d][%d][pend_cnt_by_ip] = [%d]\n",iCnt,iSubCnt,iPendCntByIP));
						PutField_Int(hGTThresValAddRec,"pend_cnt_by_ip",iPendCntByIP);
                                	}
		
					// Check iPendCntByIP
                                       	if (iPendCntByIP > iThresVal) {

						iFoundGTThresVal++;

						iNumOfPendCntGTThresVal++;
DEBUGLOG(("gen_pending_count_by_customer_ip_table:: [%d][%d][iNumOfPendCntGTThresVal] = [%d]\n",iCnt,iSubCnt,iNumOfPendCntGTThresVal));

                                                PutField_Int(hGTThresValAddRec,"ttl_pend_cnt_gt_thres_val",iNumOfPendCntGTThresVal);

						RecordSet_Add(rGTThresValRecordSet, hGTThresValAddRec);
					} else if (iPendCntByIP == iThresVal) {

                                                iFoundEQThresVal++;

                                                iNumOfPendCntEQThresVal++;
DEBUGLOG(("gen_pending_count_by_customer_ip_table:: [%d][%d][iNumOfPendCntEQThresVal] = [%d]\n",iCnt,iSubCnt,iNumOfPendCntEQThresVal));
                                        }

					iSubCnt++;

					hIPRec = RecordSet_GetNext(rIPRecordSet);
				}
			} else if (iDtlRet == PD_NOT_FOUND) {
DEBUGLOG(("gen_pending_count_by_customer_ip_table:: get_pending_count_by_customer_ip_record:: No Record Found!!!\n"));
                	} else {
DEBUGLOG(("gen_pending_count_by_customer_ip_table:: get_pending_count_by_customer_ip_record:: Error!!!\n"));
ERRLOG("check_psp_txn_report::gen_pending_count_by_customer_ip_table::get_pending_count_by_customer_ip_record::Error!!!\n");
                        	iRet = FAILURE;
                	}

			RecordSet_Destroy(rIPRecordSet);

			if (iNumOfPendCntEQThresVal > 0) {

				PutField_Int(hEQThresValAddRec,"ttl_pend_cnt_eq_thres_val",iNumOfPendCntEQThresVal);

				RecordSet_Add(rEQThresValRecordSet, hEQThresValAddRec);
			}

			iCnt++;

	                hRec = RecordSet_GetNext(rRecordSet);
        	}
	}

DEBUGLOG(("gen_pending_count_by_customer_ip_table:: iFoundGTThresVal = [%d]\n",iFoundGTThresVal));
DEBUGLOG(("gen_pending_count_by_customer_ip_table:: iFoundEQThresVal = [%d]\n",iFoundEQThresVal));

	// Generate Table "Customer pending count > Threshold Value"
	if ((iRet == SUCCESS) && (iFoundGTThresVal > 0)) {

		printf("<br><b>Customer pending count > %d</b><br>\n",iThresVal);
                printf("<html><body><table border=\"1\">\n");
                printf("<tr align=\"center\"><b><td>Duration Start</td><td>Duration End</td><td>PSP Account Name</td><td>Cust IP</td><td>Pending Count</td></b></tr>\n");

		hGTThresValGetRec = RecordSet_GetFirst(rGTThresValRecordSet);
                while (hGTThresValGetRec) {

			iNumOfPendCntGTThresVal = 0;

			GetField_CString(hGTThresValGetRec,"psp_id",&csPspId);
                        GetField_CString(hGTThresValGetRec,"psp_name",&csPspName);
                        GetField_CString(hGTThresValGetRec,"dur_start",&csDurStart);
                        GetField_CString(hGTThresValGetRec,"dur_end",&csDurEnd);
			GetField_CString(hGTThresValGetRec,"client_ip",&csClientIP);			
			GetField_Int(hGTThresValGetRec,"pend_cnt_by_ip",&iPendCntByIP);
			GetField_Int(hGTThresValGetRec,"ttl_pend_cnt_gt_thres_val",&iNumOfPendCntGTThresVal);

			if (iNumOfPendCntGTThresVal > 0) {

				printf("<tr align=\"center\"><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%d</td></tr>\n",csDurStart,csDurEnd,csPspName,csClientIP,iPendCntByIP);
			}

			hGTThresValGetRec = RecordSet_GetNext(rGTThresValRecordSet);
		}	

		printf("</table></body></html>\n");
	}

	// Generate Table "Number of customer with pending count = Threshold Value"
	if ((iRet == SUCCESS) && (iFoundEQThresVal > 0)) {

		printf("<br><b>Number of customer with pending count = %d</b><br>\n",iThresVal);
        	printf("<html><body><table border=\"1\">\n");
        	printf("<tr align=\"center\"><b><td>Duration Start</td><td>Duration End</td><td>PSP Account Name</td><td>#cust with pending=%d</td></b></tr>\n",iThresVal);
		
		hEQThresValGetRec = RecordSet_GetFirst(rEQThresValRecordSet);
               	while (hEQThresValGetRec) {

			iNumOfPendCntEQThresVal = 0;

                      	GetField_CString(hEQThresValGetRec,"psp_id",&csPspId);
                       	GetField_CString(hEQThresValGetRec,"psp_name",&csPspName);
                        GetField_CString(hEQThresValGetRec,"dur_start",&csDurStart);
                       	GetField_CString(hEQThresValGetRec,"dur_end",&csDurEnd);
                      	GetField_Int(hEQThresValGetRec,"ttl_pend_cnt_eq_thres_val",&iNumOfPendCntEQThresVal);

			if (iNumOfPendCntEQThresVal > 0) {

				printf("<tr align=\"center\"><td>%s</td><td>%s</td><td>%s</td><td>%d</td></tr>\n",csDurStart,csDurEnd,csPspName,iNumOfPendCntEQThresVal);
			}

			hEQThresValGetRec = RecordSet_GetNext(rEQThresValRecordSet);
		}

		printf("</table></body></html>\n");
	}

        FREE_ME(rIPRecordSet);

	RecordSet_Destroy(rGTThresValRecordSet);
        FREE_ME(rGTThresValRecordSet);

	//FREE_ME(hGTThresValAddRec);

	RecordSet_Destroy(rEQThresValRecordSet);
        FREE_ME(rEQThresValRecordSet);

        //FREE_ME(hEQThresValAddRec);

DEBUGLOG(("gen_pending_count_by_customer_ip_table:: iRet = [%d]\n",iRet));
        return iRet;
}

int get_pending_count_by_customer_ip_record(const hash_t *hRls, recordset_t *rRecordSet)
{
        int     iCnt = 0;
        int	iTmp = 0;
	char    cPartyType;
        char    *csTmp = NULL;
	hash_t  *hRec;

        /* EXEC SQL WHENEVER SQLERROR GOTO getpendcnt_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } hv_psp_id;

		/* varchar         hv_dur_start[PD_TIMESTAMP_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_dur_start;

                /* varchar         hv_dur_end[PD_TIMESTAMP_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_dur_end;

		int     	hv_total_pend_cnt;

                /* varchar         v_client_ip[PD_IP_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_client_ip;

		int		v_pend_cnt_by_ip;

                short           ind_client_ip = -1;
                short           ind_pend_cnt_by_ip = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


// psp_id
        if (GetField_Char(hRls,"party_type",&cPartyType)) {
                if (cPartyType == PD_TYPE_PSP) {
                        if (GetField_CString(hRls,"party_id",&csTmp)) {
DEBUGLOG(("get_pending_count_by_customer_ip_record:: psp_id = [%s]\n",csTmp));
                                hv_psp_id.len = strlen((char*)csTmp);
                                memcpy(hv_psp_id.arr,csTmp,hv_psp_id.len);
                        }
                }
        }

// dur_start
        if (GetField_CString(hRls,"dur_start",&csTmp)) {
DEBUGLOG(("get_pending_count_by_customer_ip_record:: dur_start = [%s]\n",csTmp));
                hv_dur_start.len = strlen((char*)csTmp);
                memcpy(hv_dur_start.arr,csTmp,hv_dur_start.len);
        }

// dur_end
        if (GetField_CString(hRls,"dur_end",&csTmp)) {
DEBUGLOG(("get_pending_count_by_customer_ip_record:: dur_end = [%s]\n",csTmp));
                hv_dur_end.len = strlen((char*)csTmp);
                memcpy(hv_dur_end.arr,csTmp,hv_dur_end.len);
        }

// total_pend_cnt
	if (GetField_Int(hRls,"pend_cnt",&iTmp)) {
DEBUGLOG(("get_pending_count_by_customer_ip_record:: total_pend_cnt = [%d]\n",iTmp));
		hv_total_pend_cnt = iTmp;
	}

	/* EXEC SQL DECLARE c_cursor_getpendcnt CURSOR FOR
	
		select  count(1),
			th_client_ip
		from    (select th_txn_id,                    
    				th_client_ip
    			from    txn_header                  
    			where   th_txn_code = 'DSI'
   		 	and     th_status = 'W'      
   		 	and     th_sub_status = '102'      
    			and     th_client_id not in (select 	epm_party_id        
                				    from 	email_check_party_map        
                				    where 	epm_name = 'CHECK_PSP_TXN'        
               	 				    and	 	epm_group = 'EXCLUDE'        
                				    and 	epm_party_type = 'C'        
                				    and 	epm_support_multi_entry = 1        
                				    /o'C1000002','C1000013'o/)                    
    			and     th_create_timestamp between to_date(:hv_dur_start, 'DD-MON-YYYY HH24:MI:SS')                   
                                    			and to_date(:hv_dur_end, 'DD-MON-YYYY HH24:MI:SS')         
    			and     exists (select  1            
            				from    txn_psp_detail           
            				where   tp_txn_id = th_txn_id            
            				and     tp_psp_id = :hv_psp_id)            
            		order by th_create_timestamp desc)
		where rownum <= :hv_total_pend_cnt      
		group by th_client_ip
		order by count(1) desc; */ 
  

	/* EXEC SQL OPEN c_cursor_getpendcnt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )133;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_dur_start;
 sqlstm.sqhstl[0] = (unsigned long )23;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_dur_end;
 sqlstm.sqhstl[1] = (unsigned long )23;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[2] = (unsigned long )13;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_total_pend_cnt;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto getpendcnt_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getpendcnt
                INTO
                        :v_pend_cnt_by_ip:ind_pend_cnt_by_ip,
			:v_client_ip:ind_client_ip; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 14;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )164;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_pend_cnt_by_ip;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_pend_cnt_by_ip;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_client_ip;
                sqlstm.sqhstl[1] = (unsigned long )28;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_client_ip;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto getpendcnt_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                iCnt ++;

		hRec = (hash_t*) malloc (sizeof(hash_t));
                hash_init(hRec, 0);

/* pend_cnt_by_ip */
                if (ind_pend_cnt_by_ip >= 0) {
                        PutField_Int(hRec,"pend_cnt_by_ip",v_pend_cnt_by_ip);
DEBUGLOG(("get_pending_count_by_customer_ip_record:: pend_cnt = [%d]\n", v_pend_cnt_by_ip));
                }

/* client_ip */
                if (ind_client_ip >= 0) {
                        v_client_ip.arr[v_client_ip.len] = '\0';
                        PutField_CString(hRec,"client_ip",(const char*)v_client_ip.arr);
DEBUGLOG(("get_pending_count_by_customer_ip_record:: client_ip = [%s]\n",v_client_ip.arr));
                }

		RecordSet_Add(rRecordSet, hRec);

	}
        while(PD_TRUE);
        
	/* EXEC SQL CLOSE c_cursor_getpendcnt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )187;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getpendcnt_error;
}



        if (iCnt > 0) {
DEBUGLOG(("get_pending_count_by_customer_ip_record Normal Exit\n"));
                return  PD_FOUND;
        } else {
DEBUGLOG(("get_pending_count_by_customer_ip_record Not Found\n"));
                return  PD_NOT_FOUND;
        }

getpendcnt_error:
DEBUGLOG(("getpendcnt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getpendcnt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 14;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )202;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

