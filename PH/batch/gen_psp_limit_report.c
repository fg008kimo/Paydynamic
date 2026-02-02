
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
    "gen_psp_limit_report.pc"
};


static unsigned int sqlctx = 616784315;


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

 static char *sq0003 = 
" CURRENCY_ID AND normal_summary . ME\
RCHANT_ID = overflow_summary . MERCHANT_ID AND normal_summary . CURRENCY_ID =\
 overflow_summary . CURRENCY_ID AND sarip_summary . MERCHANT_ID = overflow_su\
mmary . MERCHANT_ID AND sarip_summary . CURRENCY_ID = overflow_summary . CURR\
ENCY_ID GROUP BY normal_summary . SHORT_NAME , normal_summary . CURRENCY_ID ,\
 normal_summary . CUSTOMER_SEGMENT_CODE , normal_summary . CUSTOMER_SEGMENT_D\
ESC , normal_summary . REMAINING_LIMIT , sarip_summary . SARIP_REMAINING_LIMI\
T , overflow_summary . OVERFLOW_REMAINING_LIMIT ORDER BY normal_summary . SHO\
RT_NAME , normal_summary . CURRENCY_ID , normal_summary . CUSTOMER_SEGMENT_CO\
DE , normal_summary . CUSTOMER_SEGMENT_DESC            ";

 static char *sq0005 = 
"SELECT NVL ( SUM ( REMAINING_LIMIT ) , 0 ) AS REMAINING_LIMIT FROM ( SELECT\
 MERCHANT_ID AS MERCHANT_ID , SHORT_NAME AS SHORT_NAME , PSP_CLIENT_ID AS PSP\
_CLIENT_ID , PSP_ID AS PSP_ID , CURRENCY_ID AS CURRENCY_ID , LIMIT AS LIMIT ,\
 CG_CODE AS CUSTOMER_SEGMENT_CODE , CG_DESC AS CUSTOMER_SEGMENT_DESC , CASE W\
HEN ( REMAINING_LIMIT > 0 ) THEN REMAINING_LIMIT ELSE 0 END AS REMAINING_LIMI\
T , MIN ( MIN_TRANSACTION_AMOUNT ) AS MIN_TRANSACTION_AMOUNT , MAX ( MAX_TRAN\
SACTION_AMOUNT ) AS MAX_TRANSACTION_AMOUNT FROM PSP_LIMIT_MERCHANT_VIEW LEFT \
JOIN CUSTOMER_GROUP ON CUSTOMER_GROUP . CG_CODE = CUSTOMER_SEGMENT WHERE MERC\
HANT_ID IN ( SELECT EPM_PARTY_ID FROM EMAIL_CHECK_PARTY_MAP WHERE EPM_NAME = \
'PSP_LIMIT' AND EPM_GROUP = :b0 AND EPM_PARTY_TYPE = 'M' AND EPM_SUPPORT_MULT\
I_ENTRY = 1 ) GROUP BY MERCHANT_ID , SHORT_NAME , PSP_CLIENT_ID , PSP_ID , CU\
RRENCY_ID , LIMIT , REMAINING_LIMIT , CG_CODE , CG_DESC ) summary            ";

 static char *sq0007 = 
"ARY_PID_GROUP_DESC , NORMAL_SUMMARY_\
CUST_SEG_CODE , NORMAL_SUMMARY_CUST_SEG_DESC            ";

 static char *sq0009 = 
"ENT_DESC            ";

 static char *sq0011 = 
"_CODE , CG_DESC ) summary           \
 ";

 static char *sq0013 = 
"_GROUP . CG_CODE = PSP_LIMIT_MERCHAN\
T_VIEW . CUSTOMER_SEGMENT WHERE MERCHANT_ID IN ( SELECT EPM_PARTY_ID FROM EMA\
IL_CHECK_PARTY_MAP WHERE EPM_NAME = 'PSP_LIMIT' AND EPM_GROUP = :b0 AND EPM_P\
ARTY_TYPE = 'M' AND EPM_SUPPORT_MULTI_ENTRY = 1 ) GROUP BY CLIENT_ID , CLIENT\
_NAME , BUSINESS_TYPE , PSP_CLIENT_ID , PSP_CLIENT_NAME , PSP_ID , PSP_NAME ,\
 PSP_REMARK , CURRENCY_ID , LIMIT , REMAINING_LIMIT , CUSTOMER_SEGMENT , CG_D\
ESC ) summary WHERE 1 = 1 ORDER BY CUSTOMER_SEGMENT , CLIENT_NAME , UPPER ( P\
SP_NAME ) , CURRENCY_ID            ";

 static char *sq0015 = 
"_GROUP . CG_CODE = PSP_LIMIT_MERCHAN\
T_VIEW . CUSTOMER_SEGMENT WHERE MERCHANT_ID IN ( SELECT EPM_PARTY_ID FROM EMA\
IL_CHECK_PARTY_MAP WHERE EPM_NAME = 'PSP_LIMIT' AND EPM_GROUP = :b0 AND EPM_P\
ARTY_TYPE = 'M' AND EPM_SUPPORT_MULTI_ENTRY = 1 ) AND psp_id in ( select psp_\
id from psp_detail where pid_group = 'GRP_O' ) GROUP BY CLIENT_ID , CLIENT_NA\
ME , BUSINESS_TYPE , PSP_CLIENT_ID , PSP_CLIENT_NAME , PSP_ID , PSP_NAME , PS\
P_REMARK , CURRENCY_ID , LIMIT , REMAINING_LIMIT , CUSTOMER_SEGMENT , CG_DESC\
 ) summary WHERE 1 = 1 ORDER BY CUSTOMER_SEGMENT , CLIENT_NAME , UPPER ( PSP_\
NAME ) , CURRENCY_ID            ";

 static char *sq0017 = 
"ROM PSP_LIMIT_MERCHANT_VIEW LEFT JOI\
N DEF_PID_GROUP ON DEF_PID_GROUP . DG_CODE = PSP_LIMIT_MERCHANT_VIEW . PID_GR\
OUP LEFT JOIN CUSTOMER_GROUP ON CUSTOMER_GROUP . CG_CODE = PSP_LIMIT_MERCHANT\
_VIEW . CUSTOMER_SEGMENT WHERE MERCHANT_ID IN ( SELECT EPM_PARTY_ID FROM EMAI\
L_CHECK_PARTY_MAP WHERE EPM_NAME = 'PSP_LIMIT' AND EPM_GROUP = :b0 AND EPM_PA\
RTY_TYPE = 'M' AND EPM_SUPPORT_MULTI_ENTRY = 1 ) GROUP BY BUSINESS_TYPE , PSP\
_CLIENT_ID , PSP_CLIENT_NAME , PSP_ID , PSP_NAME , PSP_REMARK , CURRENCY_ID ,\
 LIMIT , REMAINING_LIMIT , PID_GROUP , DG_DESC , CUSTOMER_SEGMENT , CG_DESC )\
 summary WHERE 1 = 1 ORDER BY PID_GROUP , CUSTOMER_SEGMENT , UPPER ( PSP_NAME\
 ) , CURRENCY_ID            ";

 static char *sq0019 = 
"SELECT PSP_CLIENT_ID AS PSP_CLIENT_ID , PSP_CLIENT_NAME AS PSP_CLIENT_NAME \
, PSP_ID AS PSP_ID , PSP_NAME AS PSP_NAME , PSP_REMARK AS PSP_REMARK , CURREN\
CY_ID AS CURRENCY_ID , LIMIT AS LIMIT , REMAINING_LIMIT AS REMAINING_LIMIT , \
MIN ( MIN_TRANSACTION_AMOUNT ) AS MIN_TRANSACTION_AMOUNT , MAX ( MAX_TRANSACT\
ION_AMOUNT ) AS MAX_TRANSACTION_AMOUNT , NVL ( CUSTOMER_SEGMENT , '-' ) AS CU\
STOMER_SEGMENT , POOL_ID AS POOL_ID , POOL_RM_RATIO , RM_PRIORITY FROM PSP_LI\
MIT_MERCHANT_VIEW LEFT JOIN CUSTOMER_GROUP ON CUSTOMER_GROUP . CG_CODE = PSP_\
LIMIT_MERCHANT_VIEW . CUSTOMER_SEGMENT , RULE_PSP_LB_MAPPING WHERE SERVICE_CO\
DE = :b0 AND ( POOL_ID = :b1 or :b1 = '000' ) AND POOL_ID = RM_POOL_ID AND PS\
P_ID = RM_PSP_ID AND RM_DISABLED = 0 GROUP BY PSP_CLIENT_ID , PSP_CLIENT_NAME\
 , PSP_ID , PSP_NAME , PSP_REMARK , CURRENCY_ID , LIMIT , REMAINING_LIMIT , C\
USTOMER_SEGMENT , POOL_ID , POOL_RM_RATIO , RM_PRIORITY ORDER BY POOL_ID , CU\
STOMER_SEGMENT , UPPER ( PSP_NAME ) , CURRENCY_ID            ";

 static char *sq0021 = 
"SELECT PG_PARTY_TYPE , PG_PARTY_ID , PG_SERVICE_CODE FROM PSP_LIMIT_GEN WHE\
RE PG_DISABLED = 0 ORDER BY PG_PARTY_TYPE , PG_PARTY_ID , PG_SERVICE_CODE    \
        ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,252,0,4,233,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
28,0,0,2,0,0,32,255,0,0,0,0,0,1,0,
43,0,0,3,4803,0,9,484,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
70,0,0,3,0,0,13,486,0,0,7,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,
0,0,2,4,0,0,
113,0,0,3,0,0,15,576,0,0,0,0,0,1,0,
128,0,0,3,0,0,15,585,0,0,0,0,0,1,0,
143,0,0,4,0,0,32,586,0,0,0,0,0,1,0,
158,0,0,5,922,0,9,650,0,2049,1,1,0,1,0,1,9,0,0,
177,0,0,5,0,0,13,652,0,0,1,0,0,1,0,2,4,0,0,
196,0,0,5,0,0,15,680,0,0,0,0,0,1,0,
211,0,0,5,0,0,15,691,0,0,0,0,0,1,0,
226,0,0,6,0,0,32,692,0,0,0,0,0,1,0,
241,0,0,7,6236,0,9,992,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
268,0,0,7,0,0,13,994,0,0,9,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,4,0,0,2,4,0,0,2,4,0,0,
319,0,0,7,0,0,15,1099,0,0,0,0,0,1,0,
334,0,0,7,0,0,15,1108,0,0,0,0,0,1,0,
349,0,0,8,0,0,32,1109,0,0,0,0,0,1,0,
364,0,0,9,2068,0,9,1244,0,2049,1,1,0,1,0,1,9,0,0,
383,0,0,9,0,0,13,1246,0,0,7,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,4,0,0,
426,0,0,9,0,0,15,1321,0,0,0,0,0,1,0,
441,0,0,9,0,0,15,1330,0,0,0,0,0,1,0,
456,0,0,10,0,0,32,1331,0,0,0,0,0,1,0,
471,0,0,11,1061,0,9,1404,0,2049,1,1,0,1,0,1,9,0,0,
490,0,0,11,0,0,13,1406,0,0,1,0,0,1,0,2,4,0,0,
509,0,0,11,0,0,15,1439,0,0,0,0,0,1,0,
524,0,0,11,0,0,15,1450,0,0,0,0,0,1,0,
539,0,0,12,0,0,32,1451,0,0,0,0,0,1,0,
554,0,0,13,1557,0,9,1591,0,2049,1,1,0,1,0,1,9,0,0,
573,0,0,13,0,0,13,1593,0,0,12,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,3,0,0,
636,0,0,13,0,0,15,1714,0,0,0,0,0,1,0,
651,0,0,13,0,0,15,1726,0,0,0,0,0,1,0,
666,0,0,14,0,0,32,1727,0,0,0,0,0,1,0,
681,0,0,15,1631,0,9,1871,0,2049,1,1,0,1,0,1,9,0,0,
700,0,0,15,0,0,13,1873,0,0,12,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,3,0,0,
763,0,0,15,0,0,15,1982,0,0,0,0,0,1,0,
778,0,0,15,0,0,15,1993,0,0,0,0,0,1,0,
793,0,0,16,0,0,32,1994,0,0,0,0,0,1,0,
808,0,0,17,1704,0,9,2151,0,2049,1,1,0,1,0,1,9,0,0,
827,0,0,17,0,0,13,2153,0,0,13,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,3,0,0,
894,0,0,17,0,0,15,2281,0,0,0,0,0,1,0,
909,0,0,17,0,0,15,2293,0,0,0,0,0,1,0,
924,0,0,18,0,0,32,2294,0,0,0,0,0,1,0,
939,0,0,19,983,0,9,2396,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
966,0,0,19,0,0,13,2398,0,0,14,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
1037,0,0,19,0,0,15,2522,0,0,0,0,0,1,0,
1052,0,0,19,0,0,15,2534,0,0,0,0,0,1,0,
1067,0,0,20,0,0,32,2535,0,0,0,0,0,1,0,
1082,0,0,21,160,0,9,2569,0,2049,0,0,0,1,0,
1097,0,0,21,0,0,13,2572,0,0,3,0,0,1,0,2,1,0,0,2,9,0,0,2,9,0,0,
1124,0,0,21,0,0,15,2607,0,0,0,0,0,1,0,
1139,0,0,21,0,0,15,2617,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/06/13		   Stan Poon
Add Pool Level					   2014/10/16		   Stan Poon
PRD038 Changes, Remove ratio column	   	   2017/02/06		   Dirk Wong
   >> Bug fix for PRD038			   2017/02/10		   Dirk Wong
Fix SARIP                                          2017/02/14              Virginia Yun
Add Function
	- mpg_psp_limit_report_summary_so
	- mpg_psp_limit_report_summary
	- mpg_psp_limit_report_summary_total
	- mpg_psp_limit_report_merchant		   2017/11/30		   Elvis Wong
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlca.h>
#include <unistd.h>
#include <math.h>
#include "batchcommon.h"
#include "common.h"
#include "utilitys.h"
#include "myrecordset.h"
#include "hash.h"
#include "ObjPtr.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define PD_OPEN_TAG             "<tr><td>"
#define PD_OPEN_TAG_CS          "<tr><td style=text-align:right;>"
#define PD_OPEN_TAG_CS_RED      "<tr><td style=text-align:right;color:red>"
#define PD_NEXT_TAG             "</td><td>"
#define PD_NEXT_TAG_CS          "</td><td style=text-align:right;>"
#define PD_NEXT_TAG_CS_RED      "</td><td style=text-align:right;color:red>"
#define PD_END_TAG              "</td></tr>"
#define PD_CARRIAGE_RETURN      "<br>"

int i_mpg_show_sarip_overflow = PD_FALSE;
int i_show_empty_cust_seg = PD_FALSE;
int i_show_empty_pid_grp = PD_FALSE;
char cDebug = 'Y'; 

OBJPTR(DB);

int parse_arg(int argc, char **argv);
int process_txn();
int get_phase(char* csCheckGroup);
int psp_limit_report_summary(char* csCheckGroup);
int psp_limit_report_summary_total(char* csCheckGroup);
int mpg_psp_limit_report_summary_so(char* csCheckGroup);
int mpg_psp_limit_report_summary(char* csCheckGroup);
int mpg_psp_limit_report_summary_total(char* csCheckGroup);
int psp_limit_report_merchant(char* csCheckGroup, int iShowEmptyCSegment);
int psp_limit_report_group_o(char* csCheckGroup);
int mpg_psp_limit_report_merchant(char* csCheckGroup, int iShowEmptyPIDGroup, int iShowEmptyCSegment);
int psp_limit_report_group_pool(char* csPoolId, char *csServiceCode);
int find_limit_to_gen(recordset_t *myRec);

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}

int batch_proc(int argc, char* argv[])
{
	int iRet;

	iRet = parse_arg(argc, argv);

	if (iRet != SUCCESS) {
printf("usage: \n");
	} else {
		process_txn();
	}

	return iRet;
}

int process_txn()
{
	int	iRet = SUCCESS;

	//int 	iVNCPhase = 0;
	int 	iMPGPhase = 0;
	char 	*csPartyId = NULL, *csServiceCode = NULL;

	//iVNCPhase = get_phase(EML_CHK_GRP_VNCINC);
//DEBUGLOG(("find VNET segment phase = [%d]\n", iVNCPhase));

	iMPGPhase = get_phase(EML_CHK_GRP_MPGINC);
DEBUGLOG(("find Vmobile segment phase = [%d]\n", iMPGPhase));

	if (iMPGPhase > 0) {
printf("<h1>PSP Limit Report (Merchant)</h1>\n");
printf("%s",PD_CARRIAGE_RETURN);
printf("<h2>Limit Report Summary (VNET)</h2>\n");
        } else {
printf("<h1>PSP Limit Report (Merchant)</h1>\n");
printf("<h2>Limit Report Summary</h2>\n");
        }

	// PSP Limit Report Summary (VNET)
	if (iRet == PD_OK) {
		iRet = psp_limit_report_summary(EML_CHK_GRP_VNCINC);
DEBUGLOG(("psp_limit_report_summary (VNET) iRet = [%d]\n",iRet));
	}

	if (iRet == PD_OK) {
		iRet = psp_limit_report_summary_total(EML_CHK_GRP_VNCINC);
DEBUGLOG(("psp_limit_report_summary_total (VNET) iRet = [%d]\n",iRet));
	}

	// PSP Limit Report Summary (Vmobile)
	if (iMPGPhase > 0) {
		if (iRet == PD_OK) {
			if (i_mpg_show_sarip_overflow == PD_TRUE) {
               			iRet = mpg_psp_limit_report_summary_so(EML_CHK_GRP_MPGINC);
DEBUGLOG(("mpg_psp_limit_report_summary_so (Vmobile) iRet = [%d]\n",iRet));
			} else {
				iRet = mpg_psp_limit_report_summary(EML_CHK_GRP_MPGINC);
DEBUGLOG(("mpg_psp_limit_report_summary (Vmobile) iRet = [%d]\n",iRet));
			}
			
			//iRet = mpg_psp_limit_report_summary_total(EML_CHK_GRP_MPGINC);
//DEBUGLOG(("mpg_psp_limit_report_summary_total (Vmobile) iRet = [%d]\n",iRet));
printf("</table>\n");
        	}

printf("%s",PD_CARRIAGE_RETURN);
printf("<h2>VNET</h2>\n");
	}

	// PSP Limit Report (VNET)
	if (iRet == PD_OK) {
		iRet = psp_limit_report_group_o(EML_CHK_GRP_VNCINC);
DEBUGLOG(("psp_limit_report_group_o (VNET) iRet = [%d]\n",iRet));
	}

	if (iRet == PD_OK) {
		iRet = psp_limit_report_merchant(EML_CHK_GRP_VNCINC, PD_FALSE);
DEBUGLOG(("psp_limit_report_merchant (VNET) iRet = [%d]\n",iRet));
	}

	// PSP Limit Report (VMobile)
	if (iMPGPhase > 0) {
        	if (iRet == PD_OK) {
printf("%s",PD_CARRIAGE_RETURN);
printf("<h2>Vmobile</h2>\n");
        	        iRet = mpg_psp_limit_report_merchant(EML_CHK_GRP_MPGINC, i_show_empty_pid_grp, i_show_empty_cust_seg);
DEBUGLOG(("mpg_psp_limit_report_merchant (Vmobile) iRet = [%d]\n",iRet));
        	}
	} else {
                if (iRet == PD_OK) {
printf("<h2>Mobile</h2>\n");
			iRet = psp_limit_report_merchant(EML_CHK_GRP_MPGINC, PD_TRUE);
DEBUGLOG(("psp_limit_report_merchant (Vmobile) iRet = [%d]\n",iRet));
		}
	}

	recordset_t *myRec = (recordset_t*) malloc (sizeof(myRec));
	recordset_init(myRec,0);

	hash_t *myHash = NULL;

	if (iRet == PD_OK) {
		iRet = find_limit_to_gen(myRec);
DEBUGLOG(("find_limit_to_gen iRet = [%d]\n",iRet));
	}

	if (iMPGPhase > 0) {
printf("%s",PD_CARRIAGE_RETURN);
//printf("<h2>Pool</h2>\n");
	}


	// PSP Limit Report (Pool)
	if (iRet == PD_OK) {

		int	iPoolCnt = 0;
		myHash = RecordSet_GetFirst(myRec);
		while (myHash) {
DEBUGLOG(("psp_limit_report_group_pool \n"));
			csPartyId = NULL;
			csServiceCode = NULL;
			GetField_CString(myHash,"party_id",&csPartyId);
			GetField_CString(myHash,"service_code",&csServiceCode);

			iPoolCnt++;
			if (iPoolCnt == 1) {
printf("<h2>Pool</h2>\n");
			}

			iRet = psp_limit_report_group_pool(csPartyId, csServiceCode);
DEBUGLOG(("psp_limit_report_group_pool iRet = [%d]\n",iRet));
			myHash = RecordSet_GetNext(myRec);
		}
	}

	RecordSet_Destroy(myRec);
	//FREE_ME(myRec);

	return iRet;
}


int get_phase(char* csCheckGroup)
{
	int	iRet = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO get_phase_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar hv_check_group[EML_CHK_GRP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } hv_check_group;


                int  	v_phase;
                short   ind_phase = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


/* check_group */
        hv_check_group.len = strlen((char*)csCheckGroup);
        memcpy(hv_check_group.arr,csCheckGroup,hv_check_group.len);
DEBUGLOG(("get_phase: check_group = [%.*s]\n",hv_check_group.len,hv_check_group.arr));

        /* EXEC SQL
		SELECT MAX(CGM_PHASE)
		INTO :v_phase:ind_phase
		FROM CUSTOMER_GROUP_MERCHANT, EMAIL_CHECK_PARTY_MAP
		WHERE CGM_MERCHANT_ID = EPM_PARTY_ID
		AND CGM_DISABLED  = 0
		AND EPM_GROUP = :hv_check_group
		AND EPM_PARTY_TYPE = 'M'
		AND EPM_NAME = 'PSP_LIMIT'
		AND EPM_SUPPORT_MULTI_ENTRY = 1; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select MAX ( CGM_PHASE ) INTO :b0:b1 FROM CUSTOMER_G\
ROUP_MERCHANT , EMAIL_CHECK_PARTY_MAP WHERE CGM_MERCHANT_ID = EPM_PARTY_ID AN\
D CGM_DISABLED = 0 AND EPM_GROUP = :b2 AND EPM_PARTY_TYPE = 'M' AND EPM_NAME \
= 'PSP_LIMIT' AND EPM_SUPPORT_MULTI_ENTRY = 1 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )5;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_phase;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_phase;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_check_group;
        sqlstm.sqhstl[1] = (unsigned long )13;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
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
        if (sqlca.sqlcode < 0) goto get_phase_error;
}



	if (ind_phase>= 0) {
                iRet = v_phase;
        }
            
DEBUGLOG(("get_phase: phase = [%d]\n",iRet));
	return iRet;

get_phase_error:
DEBUGLOG(("get_phase_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 2;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )28;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int psp_limit_report_summary(char* csCheckGroup)
{
	int     iRet = SUCCESS;

printf("<table border='1'>\n");
printf("<tr><th>Merchant Short Name</th><th>Customer Segment</th><th>PSP Remaining Limit (Normal)</th><th>PSP Remaining Limit (SARIP)</th><th>PSP Remaining Limit (Overflow)</th></tr>\n");

	/* EXEC SQL WHENEVER SQLERROR GOTO summary_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar hv_check_group[EML_CHK_GRP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } hv_check_group;


		/* varchar	v_short_name[PD_MERCH_SHORT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_short_name;

		/* varchar	v_currency[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

		/* varchar	v_cg_code[PD_CUSTOMER_GROUP_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_cg_code;

		/* varchar	v_cg_desc[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_cg_desc;

		double	v_remaining_limit_normal;
		double	v_remaining_limit_sarip;
		double	v_remaining_limit_overflow;
		//int	v_cnt;

		short	ind_short_name = -1;
		short	ind_currency = -1;
		short	ind_cg_code = -1;
		short	ind_cg_desc = -1;
		short	ind_remaining_limit_normal = -1;
		short	ind_remaining_limit_sarip = -1;
		short	ind_remaining_limit_overflow = -1;
		//short	ind_cnt = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_check_group.len = strlen((char*)csCheckGroup);
	memcpy(hv_check_group.arr,csCheckGroup,hv_check_group.len);

	/* EXEC SQL DECLARE c_summary CURSOR FOR
		SELECT 	normal_summary.SHORT_NAME,
			normal_summary.CURRENCY_ID,
			normal_summary.CUSTOMER_SEGMENT_CODE,
			normal_summary.CUSTOMER_SEGMENT_DESC,
			normal_summary.REMAINING_LIMIT,
			sarip_summary.SARIP_REMAINING_LIMIT,
			overflow_summary.OVERFLOW_REMAINING_LIMIT
		FROM 	(
			SELECT 	MERCHANT_ID, 
				SHORT_NAME,
				CURRENCY_ID,
				CUSTOMER_SEGMENT_CODE,
				CUSTOMER_SEGMENT_DESC,
				NVL(SUM(REMAINING_LIMIT), 0) AS REMAINING_LIMIT
			FROM (
					SELECT 	MERCHANT_ID AS MERCHANT_ID,
						SHORT_NAME AS SHORT_NAME,
						PSP_CLIENT_ID,
						PSP_ID,
						CURRENCY_ID  AS CURRENCY_ID,
						CG_CODE AS CUSTOMER_SEGMENT_CODE,
						CG_DESC AS CUSTOMER_SEGMENT_DESC,	
						CASE
						WHEN (REMAINING_LIMIT > 0)
						THEN REMAINING_LIMIT
						ELSE 0
						END  AS REMAINING_LIMIT,
						MIN(MIN_TRANSACTION_AMOUNT) AS MIN_TRANSACTION_AMOUNT,
						MAX(MAX_TRANSACTION_AMOUNT) AS MAX_TRANSACTION_AMOUNT
					from PSP_LIMIT_MERCHANT_VIEW
					LEFT JOIN CUSTOMER_GROUP ON CUSTOMER_GROUP.CG_CODE = CUSTOMER_SEGMENT
					WHERE MERCHANT_ID IN   (SELECT EPM_PARTY_ID
								FROM EMAIL_CHECK_PARTY_MAP
								WHERE EPM_NAME = 'PSP_LIMIT'
								AND EPM_GROUP =  :hv_check_group
								AND EPM_PARTY_TYPE = 'M'
								AND EPM_SUPPORT_MULTI_ENTRY = 1
								)
					AND SERVICE_CODE = 'VNC'
					AND CG_CODE IN ('GRP_A',
							'GRP_B',
							'GRP_C',	
							'GRP_N'
							)
					GROUP BY	MERCHANT_ID,
							SHORT_NAME,
							PSP_CLIENT_ID,
							PSP_ID,
							CURRENCY_ID,
							CG_CODE,
							CG_DESC,
							REMAINING_LIMIT
				)
			GROUP BY 	MERCHANT_ID, 
					SHORT_NAME,
					CURRENCY_ID,
					CUSTOMER_SEGMENT_CODE,
					CUSTOMER_SEGMENT_DESC
		)  normal_summary,
		(SELECT MERCHANT_ID, 
			SHORT_NAME,
			CURRENCY_ID,
			CUSTOMER_SEGMENT_CODE,
			CUSTOMER_SEGMENT_DESC,
			NVL(SUM(REMAINING_LIMIT), 0) AS SARIP_REMAINING_LIMIT
		FROM (	
			SELECT 	MERCHANT_ID AS MERCHANT_ID,
				SHORT_NAME AS SHORT_NAME,
				PSP_CLIENT_ID AS PSP_CLIENT_ID,
				PSP_ID AS PSP_ID,
				CURRENCY_ID AS CURRENCY_ID,
				LIMIT AS LIMIT,
				CG_CODE AS CUSTOMER_SEGMENT_CODE,
				CG_DESC AS CUSTOMER_SEGMENT_DESC,
				CASE
					WHEN (REMAINING_LIMIT > 0)
					THEN REMAINING_LIMIT
					ELSE 0
				END AS REMAINING_LIMIT,
				MIN(MIN_TRANSACTION_AMOUNT) AS MIN_TRANSACTION_AMOUNT,
				MAX(MAX_TRANSACTION_AMOUNT) AS MAX_TRANSACTION_AMOUNT
			FROM PSP_LIMIT_MERCHANT_VIEW
			LEFT JOIN CUSTOMER_GROUP ON CUSTOMER_GROUP.CG_CODE = CUSTOMER_SEGMENT
			WHERE MERCHANT_ID IN (	SELECT EPM_PARTY_ID
						FROM EMAIL_CHECK_PARTY_MAP
						WHERE EPM_NAME = 'PSP_LIMIT'
						AND EPM_GROUP = :hv_check_group
						AND EPM_PARTY_TYPE = 'M'
						AND EPM_SUPPORT_MULTI_ENTRY = 1
						)
			AND SERVICE_CODE = 'VNC'
			AND CG_CODE IS NULL
			AND (	(allow_special_region =1 ) or
				(MAX_TRANSACTION_AMOUNT > 0 
				AND MAX_TRANSACTION_AMOUNT <= (select to_number(sp_val)
                                                        	from system_parameter
                                                        	where sp_code = 'LB_SMALL_AMT')
								)
			)
			GROUP BY	MERCHANT_ID,
					SHORT_NAME,
					PSP_CLIENT_ID,
					PSP_ID,
                            		CURRENCY_ID,
					LIMIT,
					REMAINING_LIMIT,
					CG_CODE,
					CG_DESC
		)
		GROUP BY 	MERCHANT_ID, 
				SHORT_NAME,
				CURRENCY_ID,
				CUSTOMER_SEGMENT_CODE,
				CUSTOMER_SEGMENT_DESC
		) sarip_summary,
		(SELECT MERCHANT_ID, 
			SHORT_NAME,
			CURRENCY_ID,
	                CUSTOMER_SEGMENT_CODE,
			CUSTOMER_SEGMENT_DESC,
			NVL(SUM(REMAINING_LIMIT), 0) AS OVERFLOW_REMAINING_LIMIT
		FROM (
			SELECT 	MERCHANT_ID AS MERCHANT_ID,
				SHORT_NAME AS SHORT_NAME,
				PSP_CLIENT_ID AS PSP_CLIENT_ID,
				PSP_ID AS PSP_ID,
				CURRENCY_ID AS CURRENCY_ID,
				LIMIT AS LIMIT,
				CG_CODE AS CUSTOMER_SEGMENT_CODE,
				CG_DESC AS CUSTOMER_SEGMENT_DESC,
				CASE
					WHEN (REMAINING_LIMIT > 0)
					THEN REMAINING_LIMIT
					ELSE 0
				END AS REMAINING_LIMIT,
				MIN(MIN_TRANSACTION_AMOUNT) AS MIN_TRANSACTION_AMOUNT,
				MAX(MAX_TRANSACTION_AMOUNT) AS MAX_TRANSACTION_AMOUNT
			FROM PSP_LIMIT_MERCHANT_VIEW
			LEFT JOIN CUSTOMER_GROUP ON CUSTOMER_GROUP.CG_CODE = CUSTOMER_SEGMENT
			WHERE MERCHANT_ID IN   (SELECT EPM_PARTY_ID
						FROM EMAIL_CHECK_PARTY_MAP
						WHERE EPM_NAME = 'PSP_LIMIT'
						AND EPM_GROUP = :hv_check_group
						AND EPM_PARTY_TYPE = 'M'
						AND EPM_SUPPORT_MULTI_ENTRY = 1
						)
			AND SERVICE_CODE = 'VNC'
			AND ALLOW_SPECIAL_REGION = 0
			AND MAX_TRANSACTION_AMOUNT = 0
			AND CG_CODE IS NULL
			GROUP BY	MERCHANT_ID,
					SHORT_NAME,
					PSP_CLIENT_ID,
					PSP_ID,
                            		CURRENCY_ID,
					LIMIT,
					REMAINING_LIMIT,
					CG_CODE,
					CG_DESC
		)
		GROUP BY 	MERCHANT_ID, 
				SHORT_NAME,
				CURRENCY_ID,
				CUSTOMER_SEGMENT_CODE,
				CUSTOMER_SEGMENT_DESC                                                       
		) overflow_summary
		WHERE normal_summary.MERCHANT_ID = sarip_summary.MERCHANT_ID
		AND normal_summary.CURRENCY_ID = sarip_summary.CURRENCY_ID
		AND normal_summary.MERCHANT_ID = overflow_summary.MERCHANT_ID
		AND normal_summary.CURRENCY_ID = overflow_summary.CURRENCY_ID
		AND sarip_summary.MERCHANT_ID = overflow_summary.MERCHANT_ID
		AND sarip_summary.CURRENCY_ID = overflow_summary.CURRENCY_ID
		GROUP BY 	normal_summary.SHORT_NAME,
				normal_summary.CURRENCY_ID,
				normal_summary.CUSTOMER_SEGMENT_CODE,
				normal_summary.CUSTOMER_SEGMENT_DESC,
				normal_summary.REMAINING_LIMIT,
				sarip_summary.SARIP_REMAINING_LIMIT,
				overflow_summary.OVERFLOW_REMAINING_LIMIT
		ORDER BY	normal_summary.SHORT_NAME,
				normal_summary.CURRENCY_ID,
				normal_summary.CUSTOMER_SEGMENT_CODE,
				normal_summary.CUSTOMER_SEGMENT_DESC; */ 

			
		

	/* EXEC SQL OPEN c_summary; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "SELECT normal_summary . SHORT_NAME , normal_summary . CURRENCY_ID , norm\
al_summary . CUSTOMER_SEGMENT_CODE , normal_summary . CUSTOMER_SEGMENT_DESC \
, normal_summary . REMAINING_LIMIT , sarip_summary . SARIP_REMAINING_LIMIT ,\
 overflow_summary . OVERFLOW_REMAINING_LIMIT FROM ( SELECT MERCHANT_ID , SHO\
RT_NAME , CURRENCY_ID , CUSTOMER_SEGMENT_CODE , CUSTOMER_SEGMENT_DESC , NVL \
( SUM ( REMAINING_LIMIT ) , 0 ) AS REMAINING_LIMIT FROM ( SELECT MERCHANT_ID\
 AS MERCHANT_ID , SHORT_NAME AS SHORT_NAME , PSP_CLIENT_ID , PSP_ID , CURREN\
CY_ID AS CURRENCY_ID , CG_CODE AS CUSTOMER_SEGMENT_CODE , CG_DESC AS CUSTOME\
R_SEGMENT_DESC , CASE WHEN ( REMAINING_LIMIT > 0 ) THEN REMAINING_LIMIT ELSE\
 0 END AS REMAINING_LIMIT , MIN ( MIN_TRANSACTION_AMOUNT ) AS MIN_TRANSACTIO\
N_AMOUNT , MAX ( MAX_TRANSACTION_AMOUNT ) AS MAX_TRANSACTION_AMOUNT from PSP\
_LIMIT_MERCHANT_VIEW LEFT JOIN CUSTOMER_GROUP ON CUSTOMER_GROUP . CG_CODE = \
CUSTOMER_SEGMENT WHERE MERCHANT_ID IN ( SELECT EPM_PARTY_ID FROM EMAIL_CHECK\
_PARTY_MAP WHERE EPM_NAME = 'PSP_LIMIT' ");
 sqlbuft((void **)0,
   "AND EPM_GROUP = :b0 AND EPM_PARTY_TYPE = 'M' AND EPM_SUPPORT_MULTI_ENTRY\
 = 1 ) AND SERVICE_CODE = 'VNC' AND CG_CODE IN ( 'GRP_A' , 'GRP_B' , 'GRP_C'\
 , 'GRP_N' ) GROUP BY MERCHANT_ID , SHORT_NAME , PSP_CLIENT_ID , PSP_ID , CU\
RRENCY_ID , CG_CODE , CG_DESC , REMAINING_LIMIT ) GROUP BY MERCHANT_ID , SHO\
RT_NAME , CURRENCY_ID , CUSTOMER_SEGMENT_CODE , CUSTOMER_SEGMENT_DESC ) norm\
al_summary , ( SELECT MERCHANT_ID , SHORT_NAME , CURRENCY_ID , CUSTOMER_SEGM\
ENT_CODE , CUSTOMER_SEGMENT_DESC , NVL ( SUM ( REMAINING_LIMIT ) , 0 ) AS SA\
RIP_REMAINING_LIMIT FROM ( SELECT MERCHANT_ID AS MERCHANT_ID , SHORT_NAME AS\
 SHORT_NAME , PSP_CLIENT_ID AS PSP_CLIENT_ID , PSP_ID AS PSP_ID , CURRENCY_I\
D AS CURRENCY_ID , LIMIT AS LIMIT , CG_CODE AS CUSTOMER_SEGMENT_CODE , CG_DE\
SC AS CUSTOMER_SEGMENT_DESC , CASE WHEN ( REMAINING_LIMIT > 0 ) THEN REMAINI\
NG_LIMIT ELSE 0 END AS REMAINING_LIMIT , MIN ( MIN_TRANSACTION_AMOUNT ) AS M\
IN_TRANSACTION_AMOUNT , MAX ( MAX_TRANSACTION_AMOUNT ) AS MAX_TRANSACTION_AM\
OUNT FROM PSP_LIMIT_MERCHANT_VIEW LEFT J");
 sqlbuft((void **)0,
   "OIN CUSTOMER_GROUP ON CUSTOMER_GROUP . CG_CODE = CUSTOMER_SEGMENT WHERE \
MERCHANT_ID IN ( SELECT EPM_PARTY_ID FROM EMAIL_CHECK_PARTY_MAP WHERE EPM_NA\
ME = 'PSP_LIMIT' AND EPM_GROUP = :b0 AND EPM_PARTY_TYPE = 'M' AND EPM_SUPPOR\
T_MULTI_ENTRY = 1 ) AND SERVICE_CODE = 'VNC' AND CG_CODE IS NULL AND ( ( all\
ow_special_region = 1 ) or ( MAX_TRANSACTION_AMOUNT > 0 AND MAX_TRANSACTION_\
AMOUNT <= ( select to_number ( sp_val ) from system_parameter where sp_code \
= 'LB_SMALL_AMT' ) ) ) GROUP BY MERCHANT_ID , SHORT_NAME , PSP_CLIENT_ID , P\
SP_ID , CURRENCY_ID , LIMIT , REMAINING_LIMIT , CG_CODE , CG_DESC ) GROUP BY\
 MERCHANT_ID , SHORT_NAME , CURRENCY_ID , CUSTOMER_SEGMENT_CODE , CUSTOMER_S\
EGMENT_DESC ) sarip_summary , ( SELECT MERCHANT_ID , SHORT_NAME , CURRENCY_I\
D , CUSTOMER_SEGMENT_CODE , CUSTOMER_SEGMENT_DESC , NVL ( SUM ( REMAINING_LI\
MIT ) , 0 ) AS OVERFLOW_REMAINING_LIMIT FROM ( SELECT MERCHANT_ID AS MERCHAN\
T_ID , SHORT_NAME AS SHORT_NAME , PSP_CLIENT_ID AS PSP_CLIENT_ID , PSP_ID AS\
 PSP_ID , CURRENCY_ID AS CURRENCY_ID , L");
 sqlbuft((void **)0,
   "IMIT AS LIMIT , CG_CODE AS CUSTOMER_SEGMENT_CODE , CG_DESC AS CUSTOMER_S\
EGMENT_DESC , CASE WHEN ( REMAINING_LIMIT > 0 ) THEN REMAINING_LIMIT ELSE 0 \
END AS REMAINING_LIMIT , MIN ( MIN_TRANSACTION_AMOUNT ) AS MIN_TRANSACTION_A\
MOUNT , MAX ( MAX_TRANSACTION_AMOUNT ) AS MAX_TRANSACTION_AMOUNT FROM PSP_LI\
MIT_MERCHANT_VIEW LEFT JOIN CUSTOMER_GROUP ON CUSTOMER_GROUP . CG_CODE = CUS\
TOMER_SEGMENT WHERE MERCHANT_ID IN ( SELECT EPM_PARTY_ID FROM EMAIL_CHECK_PA\
RTY_MAP WHERE EPM_NAME = 'PSP_LIMIT' AND EPM_GROUP = :b0 AND EPM_PARTY_TYPE \
= 'M' AND EPM_SUPPORT_MULTI_ENTRY = 1 ) AND SERVICE_CODE = 'VNC' AND ALLOW_S\
PECIAL_REGION = 0 AND MAX_TRANSACTION_AMOUNT = 0 AND CG_CODE IS NULL GROUP B\
Y MERCHANT_ID , SHORT_NAME , PSP_CLIENT_ID , PSP_ID , CURRENCY_ID , LIMIT , \
REMAINING_LIMIT , CG_CODE , CG_DESC ) GROUP BY MERCHANT_ID , SHORT_NAME , CU\
RRENCY_ID , CUSTOMER_SEGMENT_CODE , CUSTOMER_SEGMENT_DESC ) overflow_summary\
 WHERE normal_summary . MERCHANT_ID = sarip_summary . MERCHANT_ID AND normal\
_summary . CURRENCY_ID = sarip_summary .");
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )43;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_check_group;
 sqlstm.sqhstl[0] = (unsigned long )13;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_check_group;
 sqlstm.sqhstl[1] = (unsigned long )13;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_check_group;
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
 if (sqlca.sqlcode < 0) goto summary_error;
}


	for (;;) {
		/* EXEC SQL FETCH c_summary
		INTO
			:v_short_name:ind_short_name,
			:v_currency:ind_currency,
			:v_cg_code:ind_cg_code,
			:v_cg_desc:ind_cg_desc,
			:v_remaining_limit_normal:ind_remaining_limit_normal,
			:v_remaining_limit_sarip:ind_remaining_limit_sarip,
			:v_remaining_limit_overflow:ind_remaining_limit_overflow; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )70;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_short_name;
  sqlstm.sqhstl[0] = (unsigned long )23;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_short_name;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_currency;
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_currency;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_cg_code;
  sqlstm.sqhstl[2] = (unsigned long )13;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_cg_code;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_cg_desc;
  sqlstm.sqhstl[3] = (unsigned long )53;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_cg_desc;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_remaining_limit_normal;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_remaining_limit_normal;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_remaining_limit_sarip;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_remaining_limit_sarip;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_remaining_limit_overflow;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_remaining_limit_overflow;
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
  if (sqlca.sqlcode < 0) goto summary_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

printf("%s",PD_OPEN_TAG);

		if (ind_short_name >= 0) {
			v_short_name.arr[v_short_name.len]='\0';
printf("%s",(char*)v_short_name.arr);
DEBUGLOG(("psp_limit_report_summary() short_name = [%s]\n",v_short_name.arr));
		}

printf("%s",PD_NEXT_TAG);

		if (ind_currency >= 0) {
			v_currency.arr[v_currency.len]='\0';
DEBUGLOG(("psp_limit_report_summary() currency = [%s]\n",v_currency.arr));
		}

		if (ind_cg_code >= 0) {
			v_cg_code.arr[v_cg_code.len]='\0';
DEBUGLOG(("psp_limit_report_summary() cg_code = [%s]\n",v_cg_code.arr));
		}

		if (ind_cg_desc >= 0) {
			v_cg_desc.arr[v_cg_desc.len]='\0';
printf("%s",(char*)v_cg_desc.arr);
DEBUGLOG(("psp_limit_report_summary() cg_desc = [%s]\n",v_cg_desc.arr));
		}

		if (ind_remaining_limit_normal >= 0) {
			if (v_remaining_limit_normal > 1E-9) {
printf("%s",PD_NEXT_TAG_CS);
printf("%s",commaprintdouble(v_remaining_limit_normal,2));
			} else {
printf("%s",PD_NEXT_TAG_CS_RED);
printf("-%s",commaprintdouble(fabs(v_remaining_limit_normal),2));
			}
DEBUGLOG(("psp_remaining_limit_normal_report_summary() remaining_limit_normal = [%.2lf]\n",v_remaining_limit_normal));
		} else {
printf("%s",PD_NEXT_TAG_CS_RED);
		}

		if (ind_remaining_limit_sarip >= 0) {
			if (v_remaining_limit_sarip > 1E-9) {
printf("%s",PD_NEXT_TAG_CS);
printf("%s",commaprintdouble(v_remaining_limit_sarip,2));
			} else {
printf("%s",PD_NEXT_TAG_CS_RED);
printf("-%s",commaprintdouble(fabs(v_remaining_limit_sarip),2));
			}
//printf("%.2lf",v_remaining_limit_sarip);
DEBUGLOG(("psp_remaining_limit_sarip_report_summary() remaining_limit_sarip = [%.2lf]\n",v_remaining_limit_sarip));
		} else {
printf("%s",PD_NEXT_TAG_CS_RED);
		}

		if (ind_remaining_limit_overflow >= 0) {
			if (v_remaining_limit_overflow > 1E-9) {
printf("%s",PD_NEXT_TAG_CS);
printf("%s",commaprintdouble(v_remaining_limit_overflow,2));
			} else {
printf("%s",PD_NEXT_TAG_CS_RED);
printf("-%s",commaprintdouble(fabs(v_remaining_limit_overflow),2));
			}
//printf("%.2lf",v_remaining_limit_overflow);
DEBUGLOG(("psp_remaining_limit_overflow_report_summary() remaining_limit_overflow = [%.2lf]\n",v_remaining_limit_overflow));
		} else {
printf("%s",PD_NEXT_TAG_CS_RED);
		}

printf("%s\n",PD_END_TAG);

		/*	
		if (ind_cnt >= 0) {
DEBUGLOG(("psp_limit_report_summary() cnt = [%d]\n",v_cnt));
		}	
		*/

	}
	/* EXEC SQL CLOSE c_summary; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )113;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto summary_error;
}



DEBUGLOG(("psp_limit_report_summary() iRet = [%d]\n",iRet));
	return iRet;

summary_error:
DEBUGLOG(("psp_limit_report_summary error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_summary; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 7;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )128;
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
    sqlstm.offset = (unsigned int  )143;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int psp_limit_report_summary_total(char* csCheckGroup)
{
	int     iRet = SUCCESS;

	/* EXEC SQL WHENEVER SQLERROR GOTO summary_total_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar hv_check_group[EML_CHK_GRP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } hv_check_group;


		double	v_remaining_limit;
		short	ind_remaining_limit = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_check_group.len = strlen((char*)csCheckGroup);
	memcpy(hv_check_group.arr,csCheckGroup,hv_check_group.len);

	/* EXEC SQL DECLARE c_summary_total CURSOR FOR
		SELECT NVL(SUM(REMAINING_LIMIT), 0) AS REMAINING_LIMIT
		FROM (
			SELECT MERCHANT_ID AS MERCHANT_ID,
				SHORT_NAME AS SHORT_NAME,
				PSP_CLIENT_ID AS PSP_CLIENT_ID,
				PSP_ID AS PSP_ID,
				CURRENCY_ID AS CURRENCY_ID,
				LIMIT AS LIMIT,
				CG_CODE AS CUSTOMER_SEGMENT_CODE,
				CG_DESC AS CUSTOMER_SEGMENT_DESC,
				CASE
					WHEN (REMAINING_LIMIT > 0)
						THEN REMAINING_LIMIT
					ELSE 0
					END AS REMAINING_LIMIT,
				MIN(MIN_TRANSACTION_AMOUNT) AS MIN_TRANSACTION_AMOUNT,
				MAX(MAX_TRANSACTION_AMOUNT) AS MAX_TRANSACTION_AMOUNT
			FROM PSP_LIMIT_MERCHANT_VIEW
			LEFT JOIN CUSTOMER_GROUP ON CUSTOMER_GROUP.CG_CODE = CUSTOMER_SEGMENT
			WHERE MERCHANT_ID IN   (SELECT EPM_PARTY_ID
						FROM EMAIL_CHECK_PARTY_MAP
						WHERE EPM_NAME = 'PSP_LIMIT'
						AND EPM_GROUP = :hv_check_group
						AND EPM_PARTY_TYPE = 'M'
						AND EPM_SUPPORT_MULTI_ENTRY = 1
						)
				/o AND SERVICE_CODE = 'VNC' o/
			GROUP BY MERCHANT_ID,
				SHORT_NAME,
				PSP_CLIENT_ID,
				PSP_ID,
				CURRENCY_ID,
				LIMIT,
				REMAINING_LIMIT,
				CG_CODE,
				CG_DESC
			) summary; */ 



	/* EXEC SQL OPEN c_summary_total; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0005;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )158;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_check_group;
 sqlstm.sqhstl[0] = (unsigned long )13;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto summary_total_error;
}


	for (;;) {
		/* EXEC SQL FETCH c_summary_total
		INTO
			:v_remaining_limit:ind_remaining_limit; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )177;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_remaining_limit;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_remaining_limit;
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
  if (sqlca.sqlcode < 0) goto summary_total_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

printf("%sTotal",PD_OPEN_TAG);
printf("%s",PD_NEXT_TAG);
		if (ind_remaining_limit >= 0) {
			if (v_remaining_limit > 1E-9) {
printf("%s",PD_NEXT_TAG_CS);
printf("%s",commaprintdouble(v_remaining_limit,2));
			} else {
printf("%s",PD_NEXT_TAG_CS_RED);
printf("-%s",commaprintdouble(fabs(v_remaining_limit),2));
			}
//printf("%.2lf",v_remaining_limit);
DEBUGLOG(("psp_limit_report_summary_total() remaining_limit = [%.2lf]\n",v_remaining_limit));
		} else {
printf("%s",PD_NEXT_TAG_CS_RED);
		}
printf("%s",PD_NEXT_TAG_CS);
printf("%s",PD_NEXT_TAG_CS);
printf("%s\n",PD_END_TAG);

	}
	/* EXEC SQL CLOSE c_summary_total; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )196;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto summary_total_error;
}



printf("</table>\n");

DEBUGLOG(("psp_limit_report_summary_total() iRet = [%d]\n",iRet));
	return iRet;

summary_total_error:
DEBUGLOG(("psp_limit_report_summary_total error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_summary_total; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 7;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )211;
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
    sqlstm.offset = (unsigned int  )226;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int mpg_psp_limit_report_summary_so(char* csCheckGroup)
{
	int     iRet = SUCCESS;

//printf("<h1>PSP Limit Report (Merchant)</h1>\n");
printf("%s",PD_CARRIAGE_RETURN);
printf("<h2>Limit Report Summary (Vmobile)</h2>\n");
printf("<table border='1'>\n");

printf("<tr><th>Merchant Short Name</th><th>PID Group</th><th>Customer Segment</th><th>PSP Remaining Limit (Normal)</th><th>PSP Remaining Limit (SARIP)</th><th>PSP Remaining Limit (Overflow)</th></tr>\n");

	/* EXEC SQL WHENEVER SQLERROR GOTO mpg_summary_so_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar hv_check_group[EML_CHK_GRP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } hv_check_group;

	
		/* varchar	v_short_name[PD_MERCH_SHORT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_short_name;

		/* varchar	v_currency[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

		/* varchar v_pid_code[PD_CUSTOMER_GROUP_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_pid_code;

	       	/* varchar v_pid_desc[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_pid_desc;

		/* varchar	v_cg_code[PD_CUSTOMER_GROUP_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_cg_code;

		/* varchar	v_cg_desc[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_cg_desc;

		double	v_remaining_limit_normal;
		double	v_remaining_limit_sarip;
		double	v_remaining_limit_overflow;
		//int	v_cnt;

		short	ind_short_name = -1;
		short	ind_currency = -1;
		short   ind_pid_code = -1;
        	short   ind_pid_desc = -1;
		short	ind_cg_code = -1;
		short	ind_cg_desc = -1;
		short	ind_remaining_limit_normal = -1;
		short	ind_remaining_limit_sarip = -1;
		short	ind_remaining_limit_overflow = -1;
		//short	ind_cnt = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_check_group.len = strlen((char*)csCheckGroup);
	memcpy(hv_check_group.arr,csCheckGroup,hv_check_group.len);
	
	/* EXEC SQL DECLARE c_mpg_summary_so CURSOR FOR
		SELECT 	NORMAL_SUMMARY_SHORT_NAME,
                        NORMAL_SUMMARY_CURRENCY_ID,
                        NORMAL_SUMMARY_PID_GROUP_CODE,
                        NORMAL_SUMMARY_PID_GROUP_DESC,
                        NORMAL_SUMMARY_CUST_SEG_CODE,
                        NORMAL_SUMMARY_CUST_SEG_DESC,
                        NORMAL_SUMMARY_REMAINING_LIMIT,
                        SARIP_SUMMARY_REMAINING_LIMIT,
                        OVERFL_SUMMARY_REMAINING_LIMIT 
		FROM 	(
			SELECT  normal_summary.MERCHANT_ID AS NORMAL_SUMMARY_MERCHANT_ID,
                                normal_summary.SHORT_NAME AS NORMAL_SUMMARY_SHORT_NAME,
                                normal_summary.CURRENCY_ID AS NORMAL_SUMMARY_CURRENCY_ID,
                                normal_summary.PID_GROUP_CODE AS NORMAL_SUMMARY_PID_GROUP_CODE,
                                normal_summary.PID_GROUP_DESC AS NORMAL_SUMMARY_PID_GROUP_DESC,
                                normal_summary.CUSTOMER_SEGMENT_CODE AS NORMAL_SUMMARY_CUST_SEG_CODE,
                                normal_summary.CUSTOMER_SEGMENT_DESC AS NORMAL_SUMMARY_CUST_SEG_DESC,
                                normal_summary.REMAINING_LIMIT AS NORMAL_SUMMARY_REMAINING_LIMIT,
                                NVL(sarip_summary.SARIP_REMAINING_LIMIT,'0') SARIP_SUMMARY_REMAINING_LIMIT,
                                NVL(overflow_summary.OVERFLOW_REMAINING_LIMIT,'0') OVERFL_SUMMARY_REMAINING_LIMIT   
			FROM 	(	
				SELECT 	MERCHANT_ID, 
					SHORT_NAME,
					CURRENCY_ID,
					PID_GROUP_CODE,
					PID_GROUP_DESC,
					CUSTOMER_SEGMENT_CODE,
					CUSTOMER_SEGMENT_DESC,
					NVL(SUM(REMAINING_LIMIT), 0) AS REMAINING_LIMIT
				FROM (
						SELECT 	MERCHANT_ID AS MERCHANT_ID,
							SHORT_NAME AS SHORT_NAME,
							PSP_CLIENT_ID,
							PSP_ID,
							CURRENCY_ID  AS CURRENCY_ID,
							DG_CODE AS PID_GROUP_CODE,
							DG_DESC AS PID_GROUP_DESC,
							CG_CODE AS CUSTOMER_SEGMENT_CODE,
							CG_DESC AS CUSTOMER_SEGMENT_DESC,	
							CASE
								WHEN (REMAINING_LIMIT > 0)
								THEN REMAINING_LIMIT
								ELSE 0
							END  AS REMAINING_LIMIT,
							MIN(MIN_TRANSACTION_AMOUNT) AS MIN_TRANSACTION_AMOUNT,
							MAX(MAX_TRANSACTION_AMOUNT) AS MAX_TRANSACTION_AMOUNT
						from PSP_LIMIT_MERCHANT_VIEW
						LEFT JOIN DEF_PID_GROUP ON DEF_PID_GROUP.DG_CODE = PID_GROUP
						LEFT JOIN CUSTOMER_GROUP ON CUSTOMER_GROUP.CG_CODE = CUSTOMER_SEGMENT
						WHERE MERCHANT_ID IN   (SELECT EPM_PARTY_ID
									FROM EMAIL_CHECK_PARTY_MAP 
									     --CUSTOMER_GROUP_MERCHANT
									WHERE EPM_NAME = 'PSP_LIMIT'
									AND EPM_GROUP = :hv_check_group
									AND EPM_PARTY_TYPE = 'M'
									AND EPM_SUPPORT_MULTI_ENTRY = 1
									--AND CGM_MERCHANT_ID = EPM_PARTY_ID
                                                                        --AND CGM_PHASE > 0
                                                                        --AND CGM_DISABLED = 0
									)
						AND SERVICE_CODE = 'MPG'
						AND CG_CODE IN ('GRP_A',
								'GRP_B',
								'GRP_N',	
								'GRP_Q',
								'GRP_T',
								'GRP_W'
								)
						GROUP BY	MERCHANT_ID,
								SHORT_NAME,
								PSP_CLIENT_ID,
								PSP_ID,
								CURRENCY_ID,
								DG_CODE,
								DG_DESC,
								CG_CODE,
								CG_DESC,
								REMAINING_LIMIT
					)
				GROUP BY 	MERCHANT_ID, 
						SHORT_NAME,
						CURRENCY_ID,
						PID_GROUP_CODE,
						PID_GROUP_DESC,
						CUSTOMER_SEGMENT_CODE,
						CUSTOMER_SEGMENT_DESC
			)  normal_summary
			LEFT JOIN 	
			(SELECT MERCHANT_ID, 
				SHORT_NAME,
				CURRENCY_ID,
				PID_GROUP_CODE,
				PID_GROUP_DESC,
				CUSTOMER_SEGMENT_CODE,
				CUSTOMER_SEGMENT_DESC,
				NVL(SUM(REMAINING_LIMIT), 0) AS SARIP_REMAINING_LIMIT
			FROM (	
				SELECT 	MERCHANT_ID AS MERCHANT_ID,
					SHORT_NAME AS SHORT_NAME,
					PSP_CLIENT_ID AS PSP_CLIENT_ID,
					PSP_ID AS PSP_ID,
					CURRENCY_ID AS CURRENCY_ID,
					LIMIT AS LIMIT,
					DG_CODE AS PID_GROUP_CODE,
					DG_DESC AS PID_GROUP_DESC,
					CG_CODE AS CUSTOMER_SEGMENT_CODE,
					CG_DESC AS CUSTOMER_SEGMENT_DESC,
					CASE
						WHEN (REMAINING_LIMIT > 0)
						THEN REMAINING_LIMIT
						ELSE 0
					END AS REMAINING_LIMIT,
					MIN(MIN_TRANSACTION_AMOUNT) AS MIN_TRANSACTION_AMOUNT,
					MAX(MAX_TRANSACTION_AMOUNT) AS MAX_TRANSACTION_AMOUNT
				FROM PSP_LIMIT_MERCHANT_VIEW
				LEFT JOIN DEF_PID_GROUP ON DEF_PID_GROUP.DG_CODE = PID_GROUP
				LEFT JOIN CUSTOMER_GROUP ON CUSTOMER_GROUP.CG_CODE = CUSTOMER_SEGMENT
				WHERE MERCHANT_ID IN (	SELECT EPM_PARTY_ID
							FROM EMAIL_CHECK_PARTY_MAP 
							     --CUSTOMER_GROUP_MERCHANT
							WHERE EPM_NAME = 'PSP_LIMIT'
							AND EPM_GROUP = :hv_check_group
							AND EPM_PARTY_TYPE = 'M'
							AND EPM_SUPPORT_MULTI_ENTRY = 1
							--AND CGM_MERCHANT_ID = EPM_PARTY_ID
                                                        --AND CGM_PHASE > 0
                                                        --AND CGM_DISABLED = 0
							)
				AND SERVICE_CODE = 'MPG'
				AND CG_CODE IS NULL
				AND (	(allow_special_region =1 ) or
					(MAX_TRANSACTION_AMOUNT > 0 
					AND MAX_TRANSACTION_AMOUNT <= (select to_number(sp_val)
        	                                                       from system_parameter
        	                                                       where sp_code = 'LB_SMALL_AMT')
								      )
				)
				GROUP BY	MERCHANT_ID,
						SHORT_NAME,
						PSP_CLIENT_ID,
						PSP_ID,
                	            		CURRENCY_ID,
						LIMIT,
						REMAINING_LIMIT,
						DG_CODE,
						DG_DESC,
						CG_CODE,
						CG_DESC
			)
			GROUP BY 	MERCHANT_ID, 
					SHORT_NAME,
					CURRENCY_ID,
					PID_GROUP_CODE,
					PID_GROUP_DESC,
					CUSTOMER_SEGMENT_CODE,
					CUSTOMER_SEGMENT_DESC
			) sarip_summary
			ON (
				normal_summary.MERCHANT_ID = sarip_summary.MERCHANT_ID
                        	AND normal_summary.CURRENCY_ID = sarip_summary.CURRENCY_ID
                        	AND normal_summary.PID_GROUP_CODE = sarip_summary.PID_GROUP_CODE 
			)
			LEFT JOIN
			(SELECT MERCHANT_ID, 
				SHORT_NAME,
				CURRENCY_ID,
				PID_GROUP_CODE,
				PID_GROUP_DESC,
		                CUSTOMER_SEGMENT_CODE,
				CUSTOMER_SEGMENT_DESC,
				NVL(SUM(REMAINING_LIMIT), 0) AS OVERFLOW_REMAINING_LIMIT
			FROM (
				SELECT 	MERCHANT_ID AS MERCHANT_ID,
					SHORT_NAME AS SHORT_NAME,
					PSP_CLIENT_ID AS PSP_CLIENT_ID,
					PSP_ID AS PSP_ID,
					CURRENCY_ID AS CURRENCY_ID,
					LIMIT AS LIMIT,
					DG_CODE AS PID_GROUP_CODE,
					DG_DESC AS PID_GROUP_DESC,
					CG_CODE AS CUSTOMER_SEGMENT_CODE,
					CG_DESC AS CUSTOMER_SEGMENT_DESC,
					CASE
						WHEN (REMAINING_LIMIT > 0)
						THEN REMAINING_LIMIT
						ELSE 0
					END AS REMAINING_LIMIT,
					MIN(MIN_TRANSACTION_AMOUNT) AS MIN_TRANSACTION_AMOUNT,
					MAX(MAX_TRANSACTION_AMOUNT) AS MAX_TRANSACTION_AMOUNT
				FROM PSP_LIMIT_MERCHANT_VIEW
				LEFT JOIN DEF_PID_GROUP ON DEF_PID_GROUP.DG_CODE = PID_GROUP
				LEFT JOIN CUSTOMER_GROUP ON CUSTOMER_GROUP.CG_CODE = CUSTOMER_SEGMENT
				WHERE MERCHANT_ID IN   (SELECT EPM_PARTY_ID
							FROM EMAIL_CHECK_PARTY_MAP 
							     --CUSTOMER_GROUP_MERCHANT
							WHERE EPM_NAME = 'PSP_LIMIT'
							AND EPM_GROUP = :hv_check_group
							AND EPM_PARTY_TYPE = 'M'
							AND EPM_SUPPORT_MULTI_ENTRY = 1
							--AND CGM_MERCHANT_ID = EPM_PARTY_ID
                                                      	--AND CGM_PHASE > 0
                                                     	--AND CGM_DISABLED = 0
							)
				AND SERVICE_CODE = 'MPG'
				AND ALLOW_SPECIAL_REGION = 0
				AND MAX_TRANSACTION_AMOUNT = 0
				AND CG_CODE IS NULL
				GROUP BY	MERCHANT_ID,
						SHORT_NAME,
						PSP_CLIENT_ID,
						PSP_ID,
        	                    		CURRENCY_ID,
						LIMIT,
						REMAINING_LIMIT,
						DG_CODE,
						DG_DESC,
						CG_CODE,
						CG_DESC
			)
			GROUP BY 	MERCHANT_ID, 
					SHORT_NAME,
					CURRENCY_ID,
					PID_GROUP_CODE,
					PID_GROUP_DESC,
					CUSTOMER_SEGMENT_CODE,
					CUSTOMER_SEGMENT_DESC                                                       
			) overflow_summary
			ON (
				normal_summary.MERCHANT_ID = overflow_summary.MERCHANT_ID
                        	AND normal_summary.CURRENCY_ID = overflow_summary.CURRENCY_ID
                        	AND normal_summary.PID_GROUP_CODE = overflow_summary.PID_GROUP_CODE 
                        )
		)
		GROUP BY 	NORMAL_SUMMARY_SHORT_NAME,
                                NORMAL_SUMMARY_CURRENCY_ID,
                                NORMAL_SUMMARY_PID_GROUP_CODE,
                                NORMAL_SUMMARY_PID_GROUP_DESC,
                                NORMAL_SUMMARY_CUST_SEG_CODE,
                                NORMAL_SUMMARY_CUST_SEG_DESC,
                                NORMAL_SUMMARY_REMAINING_LIMIT,
                                SARIP_SUMMARY_REMAINING_LIMIT,
                                OVERFL_SUMMARY_REMAINING_LIMIT
               	ORDER BY        NORMAL_SUMMARY_SHORT_NAME,
                       		NORMAL_SUMMARY_CURRENCY_ID,
                       		/oNORMAL_SUMMARY_PID_GROUP_CODE,o/
                       		NORMAL_SUMMARY_PID_GROUP_DESC,
                        	NORMAL_SUMMARY_CUST_SEG_CODE,
                       		NORMAL_SUMMARY_CUST_SEG_DESC; */ 


	/* EXEC SQL OPEN c_mpg_summary_so; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "SELECT NORMAL_SUMMARY_SHORT_NAME , NORMAL_SUMMARY_CURRENCY_ID , NORMAL_S\
UMMARY_PID_GROUP_CODE , NORMAL_SUMMARY_PID_GROUP_DESC , NORMAL_SUMMARY_CUST_\
SEG_CODE , NORMAL_SUMMARY_CUST_SEG_DESC , NORMAL_SUMMARY_REMAINING_LIMIT , S\
ARIP_SUMMARY_REMAINING_LIMIT , OVERFL_SUMMARY_REMAINING_LIMIT FROM ( SELECT \
normal_summary . MERCHANT_ID AS NORMAL_SUMMARY_MERCHANT_ID , normal_summary \
. SHORT_NAME AS NORMAL_SUMMARY_SHORT_NAME , normal_summary . CURRENCY_ID AS \
NORMAL_SUMMARY_CURRENCY_ID , normal_summary . PID_GROUP_CODE AS NORMAL_SUMMA\
RY_PID_GROUP_CODE , normal_summary . PID_GROUP_DESC AS NORMAL_SUMMARY_PID_GR\
OUP_DESC , normal_summary . CUSTOMER_SEGMENT_CODE AS NORMAL_SUMMARY_CUST_SEG\
_CODE , normal_summary . CUSTOMER_SEGMENT_DESC AS NORMAL_SUMMARY_CUST_SEG_DE\
SC , normal_summary . REMAINING_LIMIT AS NORMAL_SUMMARY_REMAINING_LIMIT , NV\
L ( sarip_summary . SARIP_REMAINING_LIMIT , '0' ) SARIP_SUMMARY_REMAINING_LI\
MIT , NVL ( overflow_summary . OVERFLOW_REMAINING_LIMIT , '0' ) OVERFL_SUMMA\
RY_REMAINING_LIMIT FROM ( SELECT MERCHAN");
 sqlbuft((void **)0,
   "T_ID , SHORT_NAME , CURRENCY_ID , PID_GROUP_CODE , PID_GROUP_DESC , CUST\
OMER_SEGMENT_CODE , CUSTOMER_SEGMENT_DESC , NVL ( SUM ( REMAINING_LIMIT ) , \
0 ) AS REMAINING_LIMIT FROM ( SELECT MERCHANT_ID AS MERCHANT_ID , SHORT_NAME\
 AS SHORT_NAME , PSP_CLIENT_ID , PSP_ID , CURRENCY_ID AS CURRENCY_ID , DG_CO\
DE AS PID_GROUP_CODE , DG_DESC AS PID_GROUP_DESC , CG_CODE AS CUSTOMER_SEGME\
NT_CODE , CG_DESC AS CUSTOMER_SEGMENT_DESC , CASE WHEN ( REMAINING_LIMIT > 0\
 ) THEN REMAINING_LIMIT ELSE 0 END AS REMAINING_LIMIT , MIN ( MIN_TRANSACTIO\
N_AMOUNT ) AS MIN_TRANSACTION_AMOUNT , MAX ( MAX_TRANSACTION_AMOUNT ) AS MAX\
_TRANSACTION_AMOUNT from PSP_LIMIT_MERCHANT_VIEW LEFT JOIN DEF_PID_GROUP ON \
DEF_PID_GROUP . DG_CODE = PID_GROUP LEFT JOIN CUSTOMER_GROUP ON CUSTOMER_GRO\
UP . CG_CODE = CUSTOMER_SEGMENT WHERE MERCHANT_ID IN ( SELECT EPM_PARTY_ID F\
ROM EMAIL_CHECK_PARTY_MAP WHERE EPM_NAME = 'PSP_LIMIT' AND EPM_GROUP = :b0 A\
ND EPM_PARTY_TYPE = 'M' AND EPM_SUPPORT_MULTI_ENTRY = 1 ) AND SERVICE_CODE =\
 'MPG' AND CG_CODE IN ( 'GRP_A' , 'GRP_B");
 sqlbuft((void **)0,
   "' , 'GRP_N' , 'GRP_Q' , 'GRP_T' , 'GRP_W' ) GROUP BY MERCHANT_ID , SHORT\
_NAME , PSP_CLIENT_ID , PSP_ID , CURRENCY_ID , DG_CODE , DG_DESC , CG_CODE ,\
 CG_DESC , REMAINING_LIMIT ) GROUP BY MERCHANT_ID , SHORT_NAME , CURRENCY_ID\
 , PID_GROUP_CODE , PID_GROUP_DESC , CUSTOMER_SEGMENT_CODE , CUSTOMER_SEGMEN\
T_DESC ) normal_summary LEFT JOIN ( SELECT MERCHANT_ID , SHORT_NAME , CURREN\
CY_ID , PID_GROUP_CODE , PID_GROUP_DESC , CUSTOMER_SEGMENT_CODE , CUSTOMER_S\
EGMENT_DESC , NVL ( SUM ( REMAINING_LIMIT ) , 0 ) AS SARIP_REMAINING_LIMIT F\
ROM ( SELECT MERCHANT_ID AS MERCHANT_ID , SHORT_NAME AS SHORT_NAME , PSP_CLI\
ENT_ID AS PSP_CLIENT_ID , PSP_ID AS PSP_ID , CURRENCY_ID AS CURRENCY_ID , LI\
MIT AS LIMIT , DG_CODE AS PID_GROUP_CODE , DG_DESC AS PID_GROUP_DESC , CG_CO\
DE AS CUSTOMER_SEGMENT_CODE , CG_DESC AS CUSTOMER_SEGMENT_DESC , CASE WHEN (\
 REMAINING_LIMIT > 0 ) THEN REMAINING_LIMIT ELSE 0 END AS REMAINING_LIMIT , \
MIN ( MIN_TRANSACTION_AMOUNT ) AS MIN_TRANSACTION_AMOUNT , MAX ( MAX_TRANSAC\
TION_AMOUNT ) AS MAX_TRANSACTION_AMOUNT ");
 sqlbuft((void **)0,
   "FROM PSP_LIMIT_MERCHANT_VIEW LEFT JOIN DEF_PID_GROUP ON DEF_PID_GROUP . \
DG_CODE = PID_GROUP LEFT JOIN CUSTOMER_GROUP ON CUSTOMER_GROUP . CG_CODE = C\
USTOMER_SEGMENT WHERE MERCHANT_ID IN ( SELECT EPM_PARTY_ID FROM EMAIL_CHECK_\
PARTY_MAP WHERE EPM_NAME = 'PSP_LIMIT' AND EPM_GROUP = :b0 AND EPM_PARTY_TYP\
E = 'M' AND EPM_SUPPORT_MULTI_ENTRY = 1 ) AND SERVICE_CODE = 'MPG' AND CG_CO\
DE IS NULL AND ( ( allow_special_region = 1 ) or ( MAX_TRANSACTION_AMOUNT > \
0 AND MAX_TRANSACTION_AMOUNT <= ( select to_number ( sp_val ) from system_pa\
rameter where sp_code = 'LB_SMALL_AMT' ) ) ) GROUP BY MERCHANT_ID , SHORT_NA\
ME , PSP_CLIENT_ID , PSP_ID , CURRENCY_ID , LIMIT , REMAINING_LIMIT , DG_COD\
E , DG_DESC , CG_CODE , CG_DESC ) GROUP BY MERCHANT_ID , SHORT_NAME , CURREN\
CY_ID , PID_GROUP_CODE , PID_GROUP_DESC , CUSTOMER_SEGMENT_CODE , CUSTOMER_S\
EGMENT_DESC ) sarip_summary ON ( normal_summary . MERCHANT_ID = sarip_summar\
y . MERCHANT_ID AND normal_summary . CURRENCY_ID = sarip_summary . CURRENCY_\
ID AND normal_summary . PID_GROUP_CODE =");
 sqlbuft((void **)0,
   " sarip_summary . PID_GROUP_CODE ) LEFT JOIN ( SELECT MERCHANT_ID , SHORT\
_NAME , CURRENCY_ID , PID_GROUP_CODE , PID_GROUP_DESC , CUSTOMER_SEGMENT_COD\
E , CUSTOMER_SEGMENT_DESC , NVL ( SUM ( REMAINING_LIMIT ) , 0 ) AS OVERFLOW_\
REMAINING_LIMIT FROM ( SELECT MERCHANT_ID AS MERCHANT_ID , SHORT_NAME AS SHO\
RT_NAME , PSP_CLIENT_ID AS PSP_CLIENT_ID , PSP_ID AS PSP_ID , CURRENCY_ID AS\
 CURRENCY_ID , LIMIT AS LIMIT , DG_CODE AS PID_GROUP_CODE , DG_DESC AS PID_G\
ROUP_DESC , CG_CODE AS CUSTOMER_SEGMENT_CODE , CG_DESC AS CUSTOMER_SEGMENT_D\
ESC , CASE WHEN ( REMAINING_LIMIT > 0 ) THEN REMAINING_LIMIT ELSE 0 END AS R\
EMAINING_LIMIT , MIN ( MIN_TRANSACTION_AMOUNT ) AS MIN_TRANSACTION_AMOUNT , \
MAX ( MAX_TRANSACTION_AMOUNT ) AS MAX_TRANSACTION_AMOUNT FROM PSP_LIMIT_MERC\
HANT_VIEW LEFT JOIN DEF_PID_GROUP ON DEF_PID_GROUP . DG_CODE = PID_GROUP LEF\
T JOIN CUSTOMER_GROUP ON CUSTOMER_GROUP . CG_CODE = CUSTOMER_SEGMENT WHERE M\
ERCHANT_ID IN ( SELECT EPM_PARTY_ID FROM EMAIL_CHECK_PARTY_MAP WHERE EPM_NAM\
E = 'PSP_LIMIT' AND EPM_GROUP = :b0 AND ");
 sqlbuft((void **)0,
   "EPM_PARTY_TYPE = 'M' AND EPM_SUPPORT_MULTI_ENTRY = 1 ) AND SERVICE_CODE \
= 'MPG' AND ALLOW_SPECIAL_REGION = 0 AND MAX_TRANSACTION_AMOUNT = 0 AND CG_C\
ODE IS NULL GROUP BY MERCHANT_ID , SHORT_NAME , PSP_CLIENT_ID , PSP_ID , CUR\
RENCY_ID , LIMIT , REMAINING_LIMIT , DG_CODE , DG_DESC , CG_CODE , CG_DESC )\
 GROUP BY MERCHANT_ID , SHORT_NAME , CURRENCY_ID , PID_GROUP_CODE , PID_GROU\
P_DESC , CUSTOMER_SEGMENT_CODE , CUSTOMER_SEGMENT_DESC ) overflow_summary ON\
 ( normal_summary . MERCHANT_ID = overflow_summary . MERCHANT_ID AND normal_\
summary . CURRENCY_ID = overflow_summary . CURRENCY_ID AND normal_summary . \
PID_GROUP_CODE = overflow_summary . PID_GROUP_CODE ) ) GROUP BY NORMAL_SUMMA\
RY_SHORT_NAME , NORMAL_SUMMARY_CURRENCY_ID , NORMAL_SUMMARY_PID_GROUP_CODE ,\
 NORMAL_SUMMARY_PID_GROUP_DESC , NORMAL_SUMMARY_CUST_SEG_CODE , NORMAL_SUMMA\
RY_CUST_SEG_DESC , NORMAL_SUMMARY_REMAINING_LIMIT , SARIP_SUMMARY_REMAINING_\
LIMIT , OVERFL_SUMMARY_REMAINING_LIMIT ORDER BY NORMAL_SUMMARY_SHORT_NAME , \
NORMAL_SUMMARY_CURRENCY_ID , NORMAL_SUMM");
 sqlstm.stmt = sq0007;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )241;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_check_group;
 sqlstm.sqhstl[0] = (unsigned long )13;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_check_group;
 sqlstm.sqhstl[1] = (unsigned long )13;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_check_group;
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
 if (sqlca.sqlcode < 0) goto mpg_summary_so_error;
}


	for (;;) {
		/* EXEC SQL FETCH c_mpg_summary_so
		INTO
			:v_short_name:ind_short_name,
			:v_currency:ind_currency,
			:v_pid_code:ind_pid_code,
                        :v_pid_desc:ind_pid_desc,
			:v_cg_code:ind_cg_code,
			:v_cg_desc:ind_cg_desc,
			:v_remaining_limit_normal:ind_remaining_limit_normal,
			:v_remaining_limit_sarip:ind_remaining_limit_sarip,
			:v_remaining_limit_overflow:ind_remaining_limit_overflow; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )268;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_short_name;
  sqlstm.sqhstl[0] = (unsigned long )23;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_short_name;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_currency;
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_currency;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_pid_code;
  sqlstm.sqhstl[2] = (unsigned long )13;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_pid_code;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_pid_desc;
  sqlstm.sqhstl[3] = (unsigned long )53;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_pid_desc;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_cg_code;
  sqlstm.sqhstl[4] = (unsigned long )13;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_cg_code;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_cg_desc;
  sqlstm.sqhstl[5] = (unsigned long )53;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_cg_desc;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_remaining_limit_normal;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_remaining_limit_normal;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_remaining_limit_sarip;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_remaining_limit_sarip;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_remaining_limit_overflow;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_remaining_limit_overflow;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto mpg_summary_so_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

printf("%s",PD_OPEN_TAG);

		if (ind_short_name >= 0) {
			v_short_name.arr[v_short_name.len]='\0';
printf("%s",(char*)v_short_name.arr);
DEBUGLOG(("mpg_psp_limit_report_summary_so() short_name = [%s]\n",v_short_name.arr));
		}

		if (ind_currency >= 0) {
			v_currency.arr[v_currency.len]='\0';
DEBUGLOG(("mpg_psp_limit_report_summary_so() currency = [%s]\n",v_currency.arr));
		}

                if (ind_pid_code >= 0) {
                        v_pid_code.arr[v_pid_code.len]='\0';
DEBUGLOG(("mpg_psp_limit_report_summary_so() pid_code = [%s]\n",v_pid_code.arr));
                }

printf("%s",PD_NEXT_TAG);

                if (ind_pid_desc >= 0) {
                        v_pid_desc.arr[v_pid_desc.len]='\0';
printf("%s",(char*)v_pid_desc.arr);
DEBUGLOG(("mpg_psp_limit_report_summary_so() pid_desc = [%s]\n",v_pid_desc.arr));
                }

		if (ind_cg_code >= 0) {
			v_cg_code.arr[v_cg_code.len]='\0';
DEBUGLOG(("mpg_psp_limit_report_summary_so() cg_code = [%s]\n",v_cg_code.arr));
		}

printf("%s",PD_NEXT_TAG);

		if (ind_cg_desc >= 0) {
			v_cg_desc.arr[v_cg_desc.len]='\0';
printf("%s",(char*)v_cg_desc.arr);
DEBUGLOG(("mpg_psp_limit_report_summary_so() cg_desc = [%s]\n",v_cg_desc.arr));
		}

		if (ind_remaining_limit_normal >= 0) {
			if (v_remaining_limit_normal > 1E-9) {
printf("%s",PD_NEXT_TAG_CS);
printf("%s",commaprintdouble(v_remaining_limit_normal,2));
			} else {
printf("%s",PD_NEXT_TAG_CS_RED);
printf("-%s",commaprintdouble(fabs(v_remaining_limit_normal),2));
			}
DEBUGLOG(("psp_remaining_limit_normal_report_summary() remaining_limit_normal = [%.2lf]\n",v_remaining_limit_normal));
		} else {
printf("%s",PD_NEXT_TAG_CS_RED);
		}

		if (ind_remaining_limit_sarip >= 0) {
			if (v_remaining_limit_sarip > 1E-9) {
printf("%s",PD_NEXT_TAG_CS);
printf("%s",commaprintdouble(v_remaining_limit_sarip,2));
			} else {
printf("%s",PD_NEXT_TAG_CS_RED);
printf("-%s",commaprintdouble(fabs(v_remaining_limit_sarip),2));
			}
//printf("%.2lf",v_remaining_limit_sarip);
DEBUGLOG(("psp_remaining_limit_sarip_report_summary() remaining_limit_sarip = [%.2lf]\n",v_remaining_limit_sarip));
		} else {
printf("%s",PD_NEXT_TAG_CS_RED);
		}

		if (ind_remaining_limit_overflow >= 0) {
			if (v_remaining_limit_overflow > 1E-9) {
printf("%s",PD_NEXT_TAG_CS);
printf("%s",commaprintdouble(v_remaining_limit_overflow,2));
			} else {
printf("%s",PD_NEXT_TAG_CS_RED);
printf("-%s",commaprintdouble(fabs(v_remaining_limit_overflow),2));
			}
//printf("%.2lf",v_remaining_limit_overflow);
DEBUGLOG(("psp_remaining_limit_overflow_report_summary() remaining_limit_overflow = [%.2lf]\n",v_remaining_limit_overflow));
		} else {
printf("%s",PD_NEXT_TAG_CS_RED);
		}

printf("%s\n",PD_END_TAG);

		/*	
		if (ind_cnt >= 0) {
DEBUGLOG(("mpg_psp_limit_report_summary_so() cnt = [%d]\n",v_cnt));
		}	
		*/

	}
	/* EXEC SQL CLOSE c_mpg_summary_so; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )319;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto mpg_summary_so_error;
}



DEBUGLOG(("mpg_psp_limit_report_summary_so() iRet = [%d]\n",iRet));
	return iRet;

mpg_summary_so_error:
DEBUGLOG(("mpg_psp_limit_report_summary_so error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_mpg_summary_so; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 9;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )334;
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
    sqlstm.arrsiz = 9;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )349;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int mpg_psp_limit_report_summary(char* csCheckGroup)
{
	int     iRet = SUCCESS;

//printf("<h1>PSP Limit Report (Merchant)</h1>\n");
printf("%s",PD_CARRIAGE_RETURN);
printf("<h2>Limit Report Summary (Vmobile)</h2>\n");
printf("<table border='1'>\n");

printf("<tr><th>Merchant Short Name</th><th>PID Group</th><th>Customer Segment</th><th>PSP Remaining Limit (Normal)</th></tr>\n");

		/* EXEC SQL WHENEVER SQLERROR GOTO mpg_summary_error; */ 

		/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


		/* EXEC SQL BEGIN DECLARE SECTION; */ 


			/* varchar hv_check_group[EML_CHK_GRP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } hv_check_group;

	
			/* varchar	v_short_name[PD_MERCH_SHORT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_short_name;

			/* varchar	v_currency[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

			/* varchar v_pid_code[PD_CUSTOMER_GROUP_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_pid_code;

	                /* varchar v_pid_desc[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_pid_desc;

			/* varchar	v_cg_code[PD_CUSTOMER_GROUP_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_cg_code;

			/* varchar	v_cg_desc[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_cg_desc;

			double	v_remaining_limit_normal;
			//int	v_cnt;

			short	ind_short_name = -1;
			short	ind_currency = -1;
			short   ind_pid_code = -1;
        	        short   ind_pid_desc = -1;
			short	ind_cg_code = -1;
			short	ind_cg_desc = -1;
			short	ind_remaining_limit_normal = -1;
			//short	ind_cnt = -1;

		/* EXEC SQL END DECLARE SECTION; */ 

	
		hv_check_group.len = strlen((char*)csCheckGroup);
		memcpy(hv_check_group.arr,csCheckGroup,hv_check_group.len);
	
		/* EXEC SQL DECLARE c_mpg_summary CURSOR FOR
			SELECT 	normal_summary.SHORT_NAME,
				normal_summary.CURRENCY_ID,
				normal_summary.PID_GROUP_CODE,
				normal_summary.PID_GROUP_DESC,
				normal_summary.CUSTOMER_SEGMENT_CODE,
				normal_summary.CUSTOMER_SEGMENT_DESC,
				normal_summary.REMAINING_LIMIT
			FROM 	(
				SELECT 	MERCHANT_ID, 
					SHORT_NAME,
					CURRENCY_ID,
					PID_GROUP_CODE,
					PID_GROUP_DESC,
					CUSTOMER_SEGMENT_CODE,
					CUSTOMER_SEGMENT_DESC,
					NVL(SUM(REMAINING_LIMIT), 0) AS REMAINING_LIMIT
				FROM (
						SELECT 	MERCHANT_ID AS MERCHANT_ID,
							SHORT_NAME AS SHORT_NAME,
							PSP_CLIENT_ID,
							PSP_ID,
							CURRENCY_ID  AS CURRENCY_ID,
							DG_CODE AS PID_GROUP_CODE,
							DG_DESC AS PID_GROUP_DESC,
							CG_CODE AS CUSTOMER_SEGMENT_CODE,
							CG_DESC AS CUSTOMER_SEGMENT_DESC,	
							CASE
								WHEN (REMAINING_LIMIT > 0)
								THEN REMAINING_LIMIT
								ELSE 0
							END  AS REMAINING_LIMIT,
							MIN(MIN_TRANSACTION_AMOUNT) AS MIN_TRANSACTION_AMOUNT,
							MAX(MAX_TRANSACTION_AMOUNT) AS MAX_TRANSACTION_AMOUNT
						from PSP_LIMIT_MERCHANT_VIEW
						LEFT JOIN DEF_PID_GROUP ON DEF_PID_GROUP.DG_CODE = PID_GROUP
						LEFT JOIN CUSTOMER_GROUP ON CUSTOMER_GROUP.CG_CODE = CUSTOMER_SEGMENT
						WHERE MERCHANT_ID IN   (SELECT EPM_PARTY_ID
									FROM EMAIL_CHECK_PARTY_MAP 
									     --CUSTOMER_GROUP_MERCHANT
									WHERE EPM_NAME = 'PSP_LIMIT'
									AND EPM_GROUP =  :hv_check_group
									AND EPM_PARTY_TYPE = 'M'
									AND EPM_SUPPORT_MULTI_ENTRY = 1
									--AND CGM_MERCHANT_ID = EPM_PARTY_ID
									--AND CGM_PHASE > 0
									--AND CGM_DISABLED = 0
									)
						AND SERVICE_CODE = 'MPG'
						AND CG_CODE IN ('GRP_A',
								'GRP_B',
								'GRP_N',	
								'GRP_Q',
								'GRP_T',
								'GRP_W'
								)
						GROUP BY	MERCHANT_ID,
								SHORT_NAME,
								PSP_CLIENT_ID,
								PSP_ID,
								CURRENCY_ID,
								DG_CODE,
								DG_DESC,
								CG_CODE,
								CG_DESC,
								REMAINING_LIMIT
					)
				GROUP BY 	MERCHANT_ID, 
						SHORT_NAME,
						CURRENCY_ID,
						PID_GROUP_CODE,
						PID_GROUP_DESC,
						CUSTOMER_SEGMENT_CODE,
						CUSTOMER_SEGMENT_DESC
			)  normal_summary
			GROUP BY 	normal_summary.SHORT_NAME,
					normal_summary.CURRENCY_ID,
					normal_summary.PID_GROUP_CODE,
					normal_summary.PID_GROUP_DESC,
					normal_summary.CUSTOMER_SEGMENT_CODE,
					normal_summary.CUSTOMER_SEGMENT_DESC,
					normal_summary.REMAINING_LIMIT
			ORDER BY        normal_summary.SHORT_NAME,
                                        normal_summary.CURRENCY_ID,
                                        --normal_summary.PID_GROUP_CODE,
                                        normal_summary.PID_GROUP_DESC,
                                        normal_summary.CUSTOMER_SEGMENT_CODE,
                                        normal_summary.CUSTOMER_SEGMENT_DESC; */ 


	/* EXEC SQL OPEN c_mpg_summary; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "SELECT normal_summary . SHORT_NAME , normal_summary . CURRENCY_ID , norm\
al_summary . PID_GROUP_CODE , normal_summary . PID_GROUP_DESC , normal_summa\
ry . CUSTOMER_SEGMENT_CODE , normal_summary . CUSTOMER_SEGMENT_DESC , normal\
_summary . REMAINING_LIMIT FROM ( SELECT MERCHANT_ID , SHORT_NAME , CURRENCY\
_ID , PID_GROUP_CODE , PID_GROUP_DESC , CUSTOMER_SEGMENT_CODE , CUSTOMER_SEG\
MENT_DESC , NVL ( SUM ( REMAINING_LIMIT ) , 0 ) AS REMAINING_LIMIT FROM ( SE\
LECT MERCHANT_ID AS MERCHANT_ID , SHORT_NAME AS SHORT_NAME , PSP_CLIENT_ID ,\
 PSP_ID , CURRENCY_ID AS CURRENCY_ID , DG_CODE AS PID_GROUP_CODE , DG_DESC A\
S PID_GROUP_DESC , CG_CODE AS CUSTOMER_SEGMENT_CODE , CG_DESC AS CUSTOMER_SE\
GMENT_DESC , CASE WHEN ( REMAINING_LIMIT > 0 ) THEN REMAINING_LIMIT ELSE 0 E\
ND AS REMAINING_LIMIT , MIN ( MIN_TRANSACTION_AMOUNT ) AS MIN_TRANSACTION_AM\
OUNT , MAX ( MAX_TRANSACTION_AMOUNT ) AS MAX_TRANSACTION_AMOUNT from PSP_LIM\
IT_MERCHANT_VIEW LEFT JOIN DEF_PID_GROUP ON DEF_PID_GROUP . DG_CODE = PID_GR\
OUP LEFT JOIN CUSTOMER_GROUP ON CUSTOMER");
 sqlbuft((void **)0,
   "_GROUP . CG_CODE = CUSTOMER_SEGMENT WHERE MERCHANT_ID IN ( SELECT EPM_PA\
RTY_ID FROM EMAIL_CHECK_PARTY_MAP WHERE EPM_NAME = 'PSP_LIMIT' AND EPM_GROUP\
 = :b0 AND EPM_PARTY_TYPE = 'M' AND EPM_SUPPORT_MULTI_ENTRY = 1 ) AND SERVIC\
E_CODE = 'MPG' AND CG_CODE IN ( 'GRP_A' , 'GRP_B' , 'GRP_N' , 'GRP_Q' , 'GRP\
_T' , 'GRP_W' ) GROUP BY MERCHANT_ID , SHORT_NAME , PSP_CLIENT_ID , PSP_ID ,\
 CURRENCY_ID , DG_CODE , DG_DESC , CG_CODE , CG_DESC , REMAINING_LIMIT ) GRO\
UP BY MERCHANT_ID , SHORT_NAME , CURRENCY_ID , PID_GROUP_CODE , PID_GROUP_DE\
SC , CUSTOMER_SEGMENT_CODE , CUSTOMER_SEGMENT_DESC ) normal_summary GROUP BY\
 normal_summary . SHORT_NAME , normal_summary . CURRENCY_ID , normal_summary\
 . PID_GROUP_CODE , normal_summary . PID_GROUP_DESC , normal_summary . CUSTO\
MER_SEGMENT_CODE , normal_summary . CUSTOMER_SEGMENT_DESC , normal_summary .\
 REMAINING_LIMIT ORDER BY normal_summary . SHORT_NAME , normal_summary . CUR\
RENCY_ID , normal_summary . PID_GROUP_DESC , normal_summary . CUSTOMER_SEGME\
NT_CODE , normal_summary . CUSTOMER_SEGM");
 sqlstm.stmt = sq0009;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )364;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_check_group;
 sqlstm.sqhstl[0] = (unsigned long )13;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto mpg_summary_error;
}


	for (;;) {
		/* EXEC SQL FETCH c_mpg_summary
		INTO
			:v_short_name:ind_short_name,
			:v_currency:ind_currency,
			:v_pid_code:ind_pid_code,
                        :v_pid_desc:ind_pid_desc,
			:v_cg_code:ind_cg_code,
			:v_cg_desc:ind_cg_desc,
			:v_remaining_limit_normal:ind_remaining_limit_normal; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )383;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_short_name;
  sqlstm.sqhstl[0] = (unsigned long )23;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_short_name;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_currency;
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_currency;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_pid_code;
  sqlstm.sqhstl[2] = (unsigned long )13;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_pid_code;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_pid_desc;
  sqlstm.sqhstl[3] = (unsigned long )53;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_pid_desc;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_cg_code;
  sqlstm.sqhstl[4] = (unsigned long )13;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_cg_code;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_cg_desc;
  sqlstm.sqhstl[5] = (unsigned long )53;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_cg_desc;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_remaining_limit_normal;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_remaining_limit_normal;
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
  if (sqlca.sqlcode < 0) goto mpg_summary_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

printf("%s",PD_OPEN_TAG);

		if (ind_short_name >= 0) {
			v_short_name.arr[v_short_name.len]='\0';
printf("%s",(char*)v_short_name.arr);
DEBUGLOG(("mpg_psp_limit_report_summary() short_name = [%s]\n",v_short_name.arr));
		}

		if (ind_currency >= 0) {
			v_currency.arr[v_currency.len]='\0';
DEBUGLOG(("mpg_psp_limit_report_summary() currency = [%s]\n",v_currency.arr));
		}

                if (ind_pid_code >= 0) {
                        v_pid_code.arr[v_pid_code.len]='\0';
DEBUGLOG(("mpg_psp_limit_report_summary() pid_code = [%s]\n",v_pid_code.arr));
                }

printf("%s",PD_NEXT_TAG);

                if (ind_pid_desc >= 0) {
                        v_pid_desc.arr[v_pid_desc.len]='\0';
printf("%s",(char*)v_pid_desc.arr);
DEBUGLOG(("mpg_psp_limit_report_summary() pid_desc = [%s]\n",v_pid_desc.arr));
                }

		if (ind_cg_code >= 0) {
			v_cg_code.arr[v_cg_code.len]='\0';
DEBUGLOG(("mpg_psp_limit_report_summary() cg_code = [%s]\n",v_cg_code.arr));
		}

printf("%s",PD_NEXT_TAG);

		if (ind_cg_desc >= 0) {
			v_cg_desc.arr[v_cg_desc.len]='\0';
printf("%s",(char*)v_cg_desc.arr);
DEBUGLOG(("mpg_psp_limit_report_summary() cg_desc = [%s]\n",v_cg_desc.arr));
		}

		if (ind_remaining_limit_normal >= 0) {
			if (v_remaining_limit_normal > 1E-9) {
printf("%s",PD_NEXT_TAG_CS);
printf("%s",commaprintdouble(v_remaining_limit_normal,2));
			} else {
printf("%s",PD_NEXT_TAG_CS_RED);
printf("-%s",commaprintdouble(fabs(v_remaining_limit_normal),2));
			}
DEBUGLOG(("psp_remaining_limit_normal_report_summary() remaining_limit_normal = [%.2lf]\n",v_remaining_limit_normal));
		} else {
printf("%s",PD_NEXT_TAG_CS_RED);
		}

printf("%s\n",PD_END_TAG);

		/*	
		if (ind_cnt >= 0) {
DEBUGLOG(("mpg_psp_limit_report_summary() cnt = [%d]\n",v_cnt));
		}	
		*/

	}
	/* EXEC SQL CLOSE c_mpg_summary; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )426;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto mpg_summary_error;
}



DEBUGLOG(("mpg_psp_limit_report_summary() iRet = [%d]\n",iRet));
	return iRet;

mpg_summary_error:
DEBUGLOG(("mpg_psp_limit_report_summary error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_mpg_summary; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 9;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )441;
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
    sqlstm.arrsiz = 9;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )456;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int mpg_psp_limit_report_summary_total(char* csCheckGroup)
{
	int     iRet = SUCCESS;

	/* EXEC SQL WHENEVER SQLERROR GOTO mpg_summary_total_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar hv_check_group[EML_CHK_GRP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } hv_check_group;


		double	v_remaining_limit;
		short	ind_remaining_limit = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_check_group.len = strlen((char*)csCheckGroup);
	memcpy(hv_check_group.arr,csCheckGroup,hv_check_group.len);

	/* EXEC SQL DECLARE c_mpg_summary_total CURSOR FOR
		SELECT NVL(SUM(REMAINING_LIMIT), 0) AS REMAINING_LIMIT
		FROM (
			SELECT MERCHANT_ID AS MERCHANT_ID,
				SHORT_NAME AS SHORT_NAME,
				PSP_CLIENT_ID AS PSP_CLIENT_ID,
				PSP_ID AS PSP_ID,
				CURRENCY_ID AS CURRENCY_ID,
				LIMIT AS LIMIT,
				DG_CODE AS PID_GROUP_CODE,
				DG_DESC AS PID_GROUP_DESC,
				CG_CODE AS CUSTOMER_SEGMENT_CODE,
				CG_DESC AS CUSTOMER_SEGMENT_DESC,
				CASE
					WHEN (REMAINING_LIMIT > 0)
						THEN REMAINING_LIMIT
					ELSE 0
					END AS REMAINING_LIMIT,
				MIN(MIN_TRANSACTION_AMOUNT) AS MIN_TRANSACTION_AMOUNT,
				MAX(MAX_TRANSACTION_AMOUNT) AS MAX_TRANSACTION_AMOUNT
			FROM PSP_LIMIT_MERCHANT_VIEW
			LEFT JOIN DEF_PID_GROUP ON DEF_PID_GROUP.DG_CODE = PID_GROUP
			LEFT JOIN CUSTOMER_GROUP ON CUSTOMER_GROUP.CG_CODE = CUSTOMER_SEGMENT
			WHERE MERCHANT_ID IN   (SELECT EPM_PARTY_ID
						FROM EMAIL_CHECK_PARTY_MAP 
						     --CUSTOMER_GROUP_MERCHANT
						WHERE EPM_NAME = 'PSP_LIMIT'
						AND EPM_GROUP = :hv_check_group
						AND EPM_PARTY_TYPE = 'M'
						AND EPM_SUPPORT_MULTI_ENTRY = 1
						--AND CGM_MERCHANT_ID = EPM_PARTY_ID
						--AND CGM_PHASE > 0
						--AND CGM_DISABLED = 0
						)
				/o AND SERVICE_CODE = 'MPG' o/
			GROUP BY MERCHANT_ID,
				SHORT_NAME,
				PSP_CLIENT_ID,
				PSP_ID,
				CURRENCY_ID,
				LIMIT,
				REMAINING_LIMIT,
				DG_CODE,
				DG_DESC,
				CG_CODE,
				CG_DESC
			) summary; */ 



	/* EXEC SQL OPEN c_mpg_summary_total; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "SELECT NVL ( SUM ( REMAINING_LIMIT ) , 0 ) AS REMAINING_LIMIT FROM ( SEL\
ECT MERCHANT_ID AS MERCHANT_ID , SHORT_NAME AS SHORT_NAME , PSP_CLIENT_ID AS\
 PSP_CLIENT_ID , PSP_ID AS PSP_ID , CURRENCY_ID AS CURRENCY_ID , LIMIT AS LI\
MIT , DG_CODE AS PID_GROUP_CODE , DG_DESC AS PID_GROUP_DESC , CG_CODE AS CUS\
TOMER_SEGMENT_CODE , CG_DESC AS CUSTOMER_SEGMENT_DESC , CASE WHEN ( REMAININ\
G_LIMIT > 0 ) THEN REMAINING_LIMIT ELSE 0 END AS REMAINING_LIMIT , MIN ( MIN\
_TRANSACTION_AMOUNT ) AS MIN_TRANSACTION_AMOUNT , MAX ( MAX_TRANSACTION_AMOU\
NT ) AS MAX_TRANSACTION_AMOUNT FROM PSP_LIMIT_MERCHANT_VIEW LEFT JOIN DEF_PI\
D_GROUP ON DEF_PID_GROUP . DG_CODE = PID_GROUP LEFT JOIN CUSTOMER_GROUP ON C\
USTOMER_GROUP . CG_CODE = CUSTOMER_SEGMENT WHERE MERCHANT_ID IN ( SELECT EPM\
_PARTY_ID FROM EMAIL_CHECK_PARTY_MAP WHERE EPM_NAME = 'PSP_LIMIT' AND EPM_GR\
OUP = :b0 AND EPM_PARTY_TYPE = 'M' AND EPM_SUPPORT_MULTI_ENTRY = 1 ) GROUP B\
Y MERCHANT_ID , SHORT_NAME , PSP_CLIENT_ID , PSP_ID , CURRENCY_ID , LIMIT , \
REMAINING_LIMIT , DG_CODE , DG_DESC , CG");
 sqlstm.stmt = sq0011;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )471;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_check_group;
 sqlstm.sqhstl[0] = (unsigned long )13;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto mpg_summary_total_error;
}


	for (;;) {
		/* EXEC SQL FETCH c_mpg_summary_total
		INTO
			:v_remaining_limit:ind_remaining_limit; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )490;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_remaining_limit;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_remaining_limit;
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
  if (sqlca.sqlcode < 0) goto mpg_summary_total_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

printf("%sTotal",PD_OPEN_TAG);
printf("%s",PD_NEXT_TAG);
printf("%s",PD_NEXT_TAG);
		if (ind_remaining_limit >= 0) {
			if (v_remaining_limit > 1E-9) {
printf("%s",PD_NEXT_TAG_CS);
printf("%s",commaprintdouble(v_remaining_limit,2));
			} else {
printf("%s",PD_NEXT_TAG_CS_RED);
printf("-%s",commaprintdouble(fabs(v_remaining_limit),2));
			}
//printf("%.2lf",v_remaining_limit);
DEBUGLOG(("mpg_psp_limit_report_summary_total() remaining_limit = [%.2lf]\n",v_remaining_limit));
		} else {
printf("%s",PD_NEXT_TAG_CS_RED);
		}

		if (i_mpg_show_sarip_overflow == PD_TRUE) {
printf("%s",PD_NEXT_TAG_CS);
printf("%s",PD_NEXT_TAG_CS);
		}		

printf("%s\n",PD_END_TAG);

	}
	/* EXEC SQL CLOSE c_mpg_summary_total; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )509;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto mpg_summary_total_error;
}



printf("</table>\n");

DEBUGLOG(("mpg_psp_limit_report_summary_total() iRet = [%d]\n",iRet));
	return iRet;

mpg_summary_total_error:
DEBUGLOG(("mpg_psp_limit_report_summary_total error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_mpg_summary_total; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 9;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )524;
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
    sqlstm.arrsiz = 9;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )539;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int psp_limit_report_merchant(char* csCheckGroup, int iShowEmptyCSegment)
{
	int     iRet = SUCCESS;
	int	iCnt = 0;
	char	csCSegment[PD_DESC_LEN + 1];
	strcpy(csCSegment,"");

	/* EXEC SQL WHENEVER SQLERROR GOTO merchant_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar hv_check_group[EML_CHK_GRP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } hv_check_group;


		//varchar	v_merchant_id[PD_MERCHANT_ID_LEN + 1];
		/* varchar	v_client_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_client_id;

		/* varchar	v_client_name[PD_CLIENT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_client_name;

		/* varchar	v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar	v_psp_name[PD_PSP_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_name;

		/* varchar	v_remark[PD_REMARK_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;

		/* varchar	v_currency[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

		//double	v_ratio;
		/* varchar	v_customer_segment[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_customer_segment;

		double	v_limit;
		double	v_remaining_limit;
		double	v_min_txn_amount;
		double	v_max_txn_amount;
		//int	v_criteria_pool_id;
		//int	v_pool_id;
		int	v_cnt;

		//short	ind_merchant_id = -1;
		short	ind_client_id = -1;
		short	ind_client_name = -1;
		short	ind_psp_id = -1;
		short	ind_psp_name = -1;
		short	ind_remark = -1;
		short	ind_currency = -1;
		//short	ind_ratio = -1;
		short	ind_customer_segment = -1;
		short	ind_limit = -1;
		short	ind_remaining_limit = -1;
		short	ind_min_txn_amount = -1;
		short	ind_max_txn_amount = -1;
		//short	ind_criteria_pool_id = -1;
		//short	ind_pool_id = -1;
		short	ind_cnt = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_check_group.len = strlen((char*)csCheckGroup);
	memcpy(hv_check_group.arr,csCheckGroup,hv_check_group.len);

	/* EXEC SQL DECLARE c_merchant CURSOR FOR
		SELECT	/o CLIENT_ID AS CLIENT_ID,
			CLIENT_NAME AS CLIENT_NAME,o/
			--MERCHANT_ID AS MERCHANT_ID,
			/oSHORT_NAME AS SHORT_NAME,
			BUSINESS_TYPE AS BUSINESS_TYPE, o/
			PSP_CLIENT_ID AS PSP_CLIENT_ID,
			PSP_CLIENT_NAME AS PSP_CLIENT_NAME,
			PSP_ID AS PSP_ID,
			PSP_NAME AS PSP_NAME,
			PSP_REMARK AS PSP_REMARK,
			CURRENCY_ID AS CURRENCY_ID,
			LIMIT AS LIMIT,
			REMAINING_LIMIT AS REMAINING_LIMIT,
			MIN_TRANSACTION_AMOUNT AS MIN_TRANSACTION_AMOUNT,
			MAX_TRANSACTION_AMOUNT AS MAX_TRANSACTION_AMOUNT,
			NVL(CUSTOMER_SEGMENT_DESC,'-') AS CUSTOMER_SEGMENT,
			--CRITERIA_POOL_ID AS CRITERIA_POOL_ID,
			--POOL_ID AS POOL_ID,
			/oPOOL_RATIO AS POOL_RATIO_BAK, o/
			--POOL_RM_RATIO AS POOL_RATIO,
			count(*) OVER () AS TOTAL_ROWS
		FROM (
			SELECT CLIENT_ID AS CLIENT_ID,
				CLIENT_NAME AS CLIENT_NAME,
				--MERCHANT_ID AS MERCHANT_ID,
				--SHORT_NAME AS SHORT_NAME,
				BUSINESS_TYPE AS BUSINESS_TYPE,
				PSP_CLIENT_ID AS PSP_CLIENT_ID,
				PSP_CLIENT_NAME AS PSP_CLIENT_NAME,
				PSP_ID AS PSP_ID,
				PSP_NAME AS PSP_NAME,
				PSP_REMARK AS PSP_REMARK,
				CURRENCY_ID AS CURRENCY_ID,
				LIMIT AS LIMIT,
				REMAINING_LIMIT AS REMAINING_LIMIT,
				MIN(MIN_TRANSACTION_AMOUNT) AS MIN_TRANSACTION_AMOUNT,
				MAX(MAX_TRANSACTION_AMOUNT) AS MAX_TRANSACTION_AMOUNT,
				CUSTOMER_SEGMENT AS CUSTOMER_SEGMENT_CODE,
				CUSTOMER_GROUP.CG_DESC AS CUSTOMER_SEGMENT_DESC
				/oCRITERIA_POOL_ID AS CRITERIA_POOL_ID,
				POOL_ID AS POOL_ID,
				POOL_RATIO AS POOL_RATIO,
				POOL_RM_RATIO AS POOL_RM_RATIOo/
			FROM PSP_LIMIT_MERCHANT_VIEW
			LEFT JOIN CUSTOMER_GROUP ON CUSTOMER_GROUP.CG_CODE = PSP_LIMIT_MERCHANT_VIEW.CUSTOMER_SEGMENT
			WHERE MERCHANT_ID IN   (SELECT EPM_PARTY_ID
						FROM EMAIL_CHECK_PARTY_MAP
						WHERE EPM_NAME = 'PSP_LIMIT'
						AND EPM_GROUP = :hv_check_group
						AND EPM_PARTY_TYPE = 'M'
						AND EPM_SUPPORT_MULTI_ENTRY = 1
						)
			GROUP BY CLIENT_ID,
				CLIENT_NAME,
				--MERCHANT_ID,
				--SHORT_NAME,
				BUSINESS_TYPE,
				PSP_CLIENT_ID,
				PSP_CLIENT_NAME,
				PSP_ID,
				PSP_NAME,
				PSP_REMARK,
				CURRENCY_ID,
				LIMIT,
				REMAINING_LIMIT,
				CUSTOMER_SEGMENT,
				CG_DESC
				/oCRITERIA_POOL_ID,
				POOL_ID,
				POOL_RATIO,
				POOL_RM_RATIOo/
			) summary
		WHERE 1 = 1
		ORDER BY
			CUSTOMER_SEGMENT,
			--MERCHANT_ID,
			CLIENT_NAME,
			--SHORT_NAME,
			UPPER(PSP_NAME),
			CURRENCY_ID; */ 


	/* EXEC SQL OPEN c_merchant; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "SELECT PSP_CLIENT_ID AS PSP_CLIENT_ID , PSP_CLIENT_NAME AS PSP_CLIENT_NA\
ME , PSP_ID AS PSP_ID , PSP_NAME AS PSP_NAME , PSP_REMARK AS PSP_REMARK , CU\
RRENCY_ID AS CURRENCY_ID , LIMIT AS LIMIT , REMAINING_LIMIT AS REMAINING_LIM\
IT , MIN_TRANSACTION_AMOUNT AS MIN_TRANSACTION_AMOUNT , MAX_TRANSACTION_AMOU\
NT AS MAX_TRANSACTION_AMOUNT , NVL ( CUSTOMER_SEGMENT_DESC , '-' ) AS CUSTOM\
ER_SEGMENT , count ( * ) OVER ( ) AS TOTAL_ROWS FROM ( SELECT CLIENT_ID AS C\
LIENT_ID , CLIENT_NAME AS CLIENT_NAME , BUSINESS_TYPE AS BUSINESS_TYPE , PSP\
_CLIENT_ID AS PSP_CLIENT_ID , PSP_CLIENT_NAME AS PSP_CLIENT_NAME , PSP_ID AS\
 PSP_ID , PSP_NAME AS PSP_NAME , PSP_REMARK AS PSP_REMARK , CURRENCY_ID AS C\
URRENCY_ID , LIMIT AS LIMIT , REMAINING_LIMIT AS REMAINING_LIMIT , MIN ( MIN\
_TRANSACTION_AMOUNT ) AS MIN_TRANSACTION_AMOUNT , MAX ( MAX_TRANSACTION_AMOU\
NT ) AS MAX_TRANSACTION_AMOUNT , CUSTOMER_SEGMENT AS CUSTOMER_SEGMENT_CODE ,\
 CUSTOMER_GROUP . CG_DESC AS CUSTOMER_SEGMENT_DESC FROM PSP_LIMIT_MERCHANT_V\
IEW LEFT JOIN CUSTOMER_GROUP ON CUSTOMER");
 sqlstm.stmt = sq0013;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )554;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_check_group;
 sqlstm.sqhstl[0] = (unsigned long )13;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto merchant_error;
}


	for (;;) {
		/* EXEC SQL FETCH c_merchant
		INTO
			:v_client_id:ind_client_id,
			:v_client_name:ind_client_name,
			:v_psp_id:ind_psp_id,
			:v_psp_name:ind_psp_name,
			:v_remark:ind_remark,
			:v_currency:ind_currency,
			:v_limit:ind_limit,
			:v_remaining_limit:ind_remaining_limit,
			:v_min_txn_amount:ind_min_txn_amount,
			:v_max_txn_amount:ind_max_txn_amount,
			:v_customer_segment:ind_customer_segment,
			:v_cnt:ind_cnt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )573;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_client_id;
  sqlstm.sqhstl[0] = (unsigned long )13;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_client_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_client_name;
  sqlstm.sqhstl[1] = (unsigned long )53;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_client_name;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_psp_id;
  sqlstm.sqhstl[2] = (unsigned long )13;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_psp_id;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_psp_name;
  sqlstm.sqhstl[3] = (unsigned long )53;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_psp_name;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_remark;
  sqlstm.sqhstl[4] = (unsigned long )258;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_remark;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_currency;
  sqlstm.sqhstl[5] = (unsigned long )6;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_currency;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_limit;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_limit;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_remaining_limit;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_remaining_limit;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_min_txn_amount;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_min_txn_amount;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_max_txn_amount;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_max_txn_amount;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_customer_segment;
  sqlstm.sqhstl[10] = (unsigned long )53;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_customer_segment;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_cnt;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_cnt;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto merchant_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

		if (ind_customer_segment >= 0) {
			v_customer_segment.arr[v_customer_segment.len]='\0';

			if (!strcmp((char*)v_customer_segment.arr,"-") && !iShowEmptyCSegment) continue;

			if (strcmp(csCSegment,(char*)v_customer_segment.arr)) {
				strcpy(csCSegment,(char*)v_customer_segment.arr);

if (iCnt > 1) printf("</table>\n");
if (strcmp(csCSegment,"-")) printf("<h2>%s</h2>\n",csCSegment);

printf("<table border='1'>\n");
printf("<tr><th>PSP Name</th><th>PSP Account Name</th><th>Remark</th><th>Currency</th><th>Customer Segment</th><th>PID Limit</th><th>PSP Remaining Limit</th></tr>\n");
			}
		}

		if (ind_client_id >= 0) {
			v_client_id.arr[v_client_id.len]='\0';
DEBUGLOG(("psp_limit_report_merchant() client_id = [%s]\n",v_client_id.arr));
		}

printf("%s",PD_OPEN_TAG);

		if (ind_client_name >= 0) {
			v_client_name.arr[v_client_name.len]='\0';
printf("%s",(char*)v_client_name.arr);
DEBUGLOG(("psp_limit_report_merchant() client_name = [%s]\n",v_client_name.arr));
		}

		if (ind_psp_id >= 0) {
			v_psp_id.arr[v_psp_id.len]='\0';
DEBUGLOG(("psp_limit_report_merchant() psp_id = [%s]\n",v_psp_id.arr));
		}

printf("%s",PD_NEXT_TAG);

		if (ind_psp_name >= 0) {
			v_psp_name.arr[v_psp_name.len]='\0';
printf("%s",(char*)v_psp_name.arr);
DEBUGLOG(("psp_limit_report_merchant() psp_name = [%s]\n",v_psp_name.arr));
		}

printf("%s",PD_NEXT_TAG);

		if (ind_remark >= 0) {
			v_remark.arr[v_remark.len]='\0';
printf("%s",(char*)v_remark.arr);
DEBUGLOG(("psp_limit_report_merchant() remark = [%s]\n",v_remark.arr));
		}

printf("%s",PD_NEXT_TAG);

		if (ind_currency >= 0) {
			v_currency.arr[v_currency.len]='\0';
printf("%s",(char*)v_currency.arr);
DEBUGLOG(("psp_limit_report_merchant() currency = [%s]\n",v_currency.arr));
		}

printf("%s",PD_NEXT_TAG);

		if (ind_customer_segment >= 0) {
			v_customer_segment.arr[v_customer_segment.len]='\0';
printf("%s",(char*)v_customer_segment.arr);
DEBUGLOG(("psp_limit_report_merchant() customer_segment = [%s]\n",v_customer_segment.arr));
		}

		if (ind_limit >= 0) {
			if (v_limit > 1E-9) {
printf("%s",PD_NEXT_TAG_CS);
printf("%s",commaprintdouble(v_limit,2));
			} else {
printf("%s",PD_NEXT_TAG_CS_RED);
printf("-%s",commaprintdouble(fabs(v_limit),2));
			}
//printf("%.2lf",v_limit);
DEBUGLOG(("psp_limit_report_merchant() limit = [%.2lf]\n",v_limit));
		} else {
printf("%s",PD_NEXT_TAG_CS_RED);
		}

		if (ind_remaining_limit >= 0) {
			if (v_remaining_limit > 1E-9) {
printf("%s",PD_NEXT_TAG_CS);
printf("%s",commaprintdouble(v_remaining_limit,2));
			} else {
printf("%s",PD_NEXT_TAG_CS_RED);
printf("-%s",commaprintdouble(fabs(v_remaining_limit),2));
			}
//printf("%.2lf",v_remaining_limit);
DEBUGLOG(("psp_limit_report_merchant() remaining_limit = [%.2lf]\n",v_remaining_limit));
		} else {
printf("%s",PD_NEXT_TAG_CS_RED);
		}

printf("%s\n",PD_END_TAG);

		if (ind_cnt >= 0) {
DEBUGLOG(("psp_limit_report_merchant() cnt = [%d]\n",v_cnt));
		}
	}
	/* EXEC SQL CLOSE c_merchant; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )636;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto merchant_error;
}



//if (iCnt > 1) printf("</table>\n");
if (iCnt >= 1) printf("</table>\n");

DEBUGLOG(("psp_limit_report_merchant() iRet = [%d]\n",iRet));
	return iRet;

merchant_error:
DEBUGLOG(("psp_limit_report_merchant error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_merchant; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )651;
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
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )666;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int psp_limit_report_group_o(char* csCheckGroup)
{
	int     iRet = SUCCESS;
	int	iCnt = 0;

printf("<h2>%s</h2>\n","Segment Overflow");

printf("<table border='1'>\n");
printf("<tr><th>PSP Name</th><th>PSP Account Name</th><th>Remark</th><th>Currency</th><th>Customer Segment</th><th>PID Limit</th><th>PSP Remaining Limit</th></tr>\n");

	/* EXEC SQL WHENEVER SQLERROR GOTO merchant_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar hv_check_group[EML_CHK_GRP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } hv_check_group;


		//varchar	v_merchant_id[PD_MERCHANT_ID_LEN + 1];
		/* varchar	v_client_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_client_id;

		/* varchar	v_client_name[PD_CLIENT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_client_name;

		/* varchar	v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar	v_psp_name[PD_PSP_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_name;

		/* varchar	v_remark[PD_REMARK_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;

		/* varchar	v_currency[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

		//double	v_ratio;
		/* varchar	v_customer_segment[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_customer_segment;

		double	v_limit;
		double	v_remaining_limit;
		double	v_min_txn_amount;
		double	v_max_txn_amount;
		//int	v_criteria_pool_id;
		//int	v_pool_id;
		int	v_cnt;

		//short	ind_merchant_id = -1;
		short	ind_client_id = -1;
		short	ind_client_name = -1;
		short	ind_psp_id = -1;
		short	ind_psp_name = -1;
		short	ind_remark = -1;
		short	ind_currency = -1;
		//short	ind_ratio = -1;
		short	ind_customer_segment = -1;
		short	ind_limit = -1;
		short	ind_remaining_limit = -1;
		short	ind_min_txn_amount = -1;
		short	ind_max_txn_amount = -1;
		//short	ind_criteria_pool_id = -1;
		//short	ind_pool_id = -1;
		short	ind_cnt = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_check_group.len = strlen((char*)csCheckGroup);
	memcpy(hv_check_group.arr,csCheckGroup,hv_check_group.len);

	/* EXEC SQL DECLARE c_group_o CURSOR FOR
		SELECT	/o CLIENT_ID AS CLIENT_ID,
			CLIENT_NAME AS CLIENT_NAME,
			MERCHANT_ID AS MERCHANT_ID,o/
			/oSHORT_NAME AS SHORT_NAME,
			BUSINESS_TYPE AS BUSINESS_TYPE, o/
			PSP_CLIENT_ID AS PSP_CLIENT_ID,
			PSP_CLIENT_NAME AS PSP_CLIENT_NAME,
			PSP_ID AS PSP_ID,
			PSP_NAME AS PSP_NAME,
			PSP_REMARK AS PSP_REMARK,
			CURRENCY_ID AS CURRENCY_ID,
			LIMIT AS LIMIT,
			REMAINING_LIMIT AS REMAINING_LIMIT,
			MIN_TRANSACTION_AMOUNT AS MIN_TRANSACTION_AMOUNT,
			MAX_TRANSACTION_AMOUNT AS MAX_TRANSACTION_AMOUNT,
			NVL(CUSTOMER_SEGMENT_DESC,'-') AS CUSTOMER_SEGMENT,
			--CRITERIA_POOL_ID AS CRITERIA_POOL_ID,
			--POOL_ID AS POOL_ID,
			/oPOOL_RATIO AS POOL_RATIO_BAK, o/
			--POOL_RM_RATIO AS POOL_RATIO,
			count(*) OVER () AS TOTAL_ROWS
		FROM (
			SELECT CLIENT_ID AS CLIENT_ID,
				CLIENT_NAME AS CLIENT_NAME,
				--MERCHANT_ID AS MERCHANT_ID,
				--SHORT_NAME AS SHORT_NAME,
				BUSINESS_TYPE AS BUSINESS_TYPE,
				PSP_CLIENT_ID AS PSP_CLIENT_ID,
				PSP_CLIENT_NAME AS PSP_CLIENT_NAME,
				PSP_ID AS PSP_ID,
				PSP_NAME AS PSP_NAME,
				PSP_REMARK AS PSP_REMARK,
				CURRENCY_ID AS CURRENCY_ID,
				LIMIT AS LIMIT,
				REMAINING_LIMIT AS REMAINING_LIMIT,
				MIN(MIN_TRANSACTION_AMOUNT) AS MIN_TRANSACTION_AMOUNT,
				MAX(MAX_TRANSACTION_AMOUNT) AS MAX_TRANSACTION_AMOUNT,
				CUSTOMER_SEGMENT AS CUSTOMER_SEGMENT_CODE,
				CUSTOMER_GROUP.CG_DESC AS CUSTOMER_SEGMENT_DESC
				--CRITERIA_POOL_ID AS CRITERIA_POOL_ID,
				--POOL_ID AS POOL_ID,
				--POOL_RATIO AS POOL_RATIO,
				--POOL_RM_RATIO AS POOL_RM_RATIO
			FROM PSP_LIMIT_MERCHANT_VIEW
			LEFT JOIN CUSTOMER_GROUP ON CUSTOMER_GROUP.CG_CODE = PSP_LIMIT_MERCHANT_VIEW.CUSTOMER_SEGMENT
			WHERE MERCHANT_ID IN   (SELECT EPM_PARTY_ID
						FROM EMAIL_CHECK_PARTY_MAP
						WHERE EPM_NAME = 'PSP_LIMIT'
						AND EPM_GROUP = :hv_check_group
						AND EPM_PARTY_TYPE = 'M'
						AND EPM_SUPPORT_MULTI_ENTRY = 1
						)
			AND psp_id in ( select psp_id from psp_detail where pid_group = 'GRP_O')
			GROUP BY CLIENT_ID,
				CLIENT_NAME,
				--MERCHANT_ID,
				--SHORT_NAME,
				BUSINESS_TYPE,
				PSP_CLIENT_ID,
				PSP_CLIENT_NAME,
				PSP_ID,
				PSP_NAME,
				PSP_REMARK,
				CURRENCY_ID,
				LIMIT,
				REMAINING_LIMIT,
				CUSTOMER_SEGMENT,
				CG_DESC
				--CRITERIA_POOL_ID,
				--POOL_ID,
				--POOL_RATIO,
				--POOL_RM_RATIO
			) summary
		WHERE 1 = 1
		ORDER BY 
			--MERCHANT_ID,
			CUSTOMER_SEGMENT,
			CLIENT_NAME,
			--SHORT_NAME,
			UPPER(PSP_NAME),
			CURRENCY_ID; */ 


	/* EXEC SQL OPEN c_group_o; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "SELECT PSP_CLIENT_ID AS PSP_CLIENT_ID , PSP_CLIENT_NAME AS PSP_CLIENT_NA\
ME , PSP_ID AS PSP_ID , PSP_NAME AS PSP_NAME , PSP_REMARK AS PSP_REMARK , CU\
RRENCY_ID AS CURRENCY_ID , LIMIT AS LIMIT , REMAINING_LIMIT AS REMAINING_LIM\
IT , MIN_TRANSACTION_AMOUNT AS MIN_TRANSACTION_AMOUNT , MAX_TRANSACTION_AMOU\
NT AS MAX_TRANSACTION_AMOUNT , NVL ( CUSTOMER_SEGMENT_DESC , '-' ) AS CUSTOM\
ER_SEGMENT , count ( * ) OVER ( ) AS TOTAL_ROWS FROM ( SELECT CLIENT_ID AS C\
LIENT_ID , CLIENT_NAME AS CLIENT_NAME , BUSINESS_TYPE AS BUSINESS_TYPE , PSP\
_CLIENT_ID AS PSP_CLIENT_ID , PSP_CLIENT_NAME AS PSP_CLIENT_NAME , PSP_ID AS\
 PSP_ID , PSP_NAME AS PSP_NAME , PSP_REMARK AS PSP_REMARK , CURRENCY_ID AS C\
URRENCY_ID , LIMIT AS LIMIT , REMAINING_LIMIT AS REMAINING_LIMIT , MIN ( MIN\
_TRANSACTION_AMOUNT ) AS MIN_TRANSACTION_AMOUNT , MAX ( MAX_TRANSACTION_AMOU\
NT ) AS MAX_TRANSACTION_AMOUNT , CUSTOMER_SEGMENT AS CUSTOMER_SEGMENT_CODE ,\
 CUSTOMER_GROUP . CG_DESC AS CUSTOMER_SEGMENT_DESC FROM PSP_LIMIT_MERCHANT_V\
IEW LEFT JOIN CUSTOMER_GROUP ON CUSTOMER");
 sqlstm.stmt = sq0015;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )681;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_check_group;
 sqlstm.sqhstl[0] = (unsigned long )13;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto merchant_error;
}


	for (;;) {
		/* EXEC SQL FETCH c_group_o
		INTO
			//:v_merchant_id:ind_merchant_id,
			:v_client_id:ind_client_id,
			:v_client_name:ind_client_name,
			:v_psp_id:ind_psp_id,
			:v_psp_name:ind_psp_name,
			:v_remark:ind_remark,
			:v_currency:ind_currency,
			:v_limit:ind_limit,
			:v_remaining_limit:ind_remaining_limit,
			:v_min_txn_amount:ind_min_txn_amount,
			:v_max_txn_amount:ind_max_txn_amount,
			:v_customer_segment:ind_customer_segment,
			//:v_criteria_pool_id:ind_criteria_pool_id,
			//:v_pool_id:ind_pool_id,
			//:v_ratio:ind_ratio,
			:v_cnt:ind_cnt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )700;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_client_id;
  sqlstm.sqhstl[0] = (unsigned long )13;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_client_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_client_name;
  sqlstm.sqhstl[1] = (unsigned long )53;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_client_name;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_psp_id;
  sqlstm.sqhstl[2] = (unsigned long )13;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_psp_id;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_psp_name;
  sqlstm.sqhstl[3] = (unsigned long )53;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_psp_name;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_remark;
  sqlstm.sqhstl[4] = (unsigned long )258;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_remark;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_currency;
  sqlstm.sqhstl[5] = (unsigned long )6;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_currency;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_limit;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_limit;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_remaining_limit;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_remaining_limit;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_min_txn_amount;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_min_txn_amount;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_max_txn_amount;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_max_txn_amount;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_customer_segment;
  sqlstm.sqhstl[10] = (unsigned long )53;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_customer_segment;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_cnt;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_cnt;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto merchant_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

		if (ind_client_id >= 0) {
			v_client_id.arr[v_client_id.len]='\0';
DEBUGLOG(("psp_limit_report_group_o() client_id = [%s]\n",v_client_id.arr));
		}

printf("%s",PD_OPEN_TAG);

		if (ind_client_name >= 0) {
			v_client_name.arr[v_client_name.len]='\0';
printf("%s",(char*)v_client_name.arr);
DEBUGLOG(("psp_limit_report_group_o() client_name = [%s]\n",v_client_name.arr));
		}

		if (ind_psp_id >= 0) {
			v_psp_id.arr[v_psp_id.len]='\0';
DEBUGLOG(("psp_limit_report_group_o() psp_id = [%s]\n",v_psp_id.arr));
		}

printf("%s",PD_NEXT_TAG);

		if (ind_psp_name >= 0) {
			v_psp_name.arr[v_psp_name.len]='\0';
printf("%s",(char*)v_psp_name.arr);
DEBUGLOG(("psp_limit_report_group_o() psp_name = [%s]\n",v_psp_name.arr));
		}

printf("%s",PD_NEXT_TAG);

		if (ind_remark >= 0) {
			v_remark.arr[v_remark.len]='\0';
printf("%s",(char*)v_remark.arr);
DEBUGLOG(("psp_limit_report_group_o() remark = [%s]\n",v_remark.arr));
		}

printf("%s",PD_NEXT_TAG);

		if (ind_currency >= 0) {
			v_currency.arr[v_currency.len]='\0';
printf("%s",(char*)v_currency.arr);
DEBUGLOG(("psp_limit_report_group_o() currency = [%s]\n",v_currency.arr));
		}

printf("%s",PD_NEXT_TAG);

		if (ind_customer_segment >= 0) {
			v_customer_segment.arr[v_customer_segment.len]='\0';
printf("%s",(char*)v_customer_segment.arr);
DEBUGLOG(("psp_limit_report_group_o() customer_segment = [%s]\n",v_customer_segment.arr));
		}

		if (ind_limit >= 0) {
			if (v_limit > 1E-9) {
printf("%s",PD_NEXT_TAG_CS);
printf("%s",commaprintdouble(v_limit,2));
			} else {
printf("%s",PD_NEXT_TAG_CS_RED);
printf("-%s",commaprintdouble(fabs(v_limit),2));
			}
//printf("%.2lf",v_limit);
DEBUGLOG(("psp_limit_report_group_o() limit = [%.2lf]\n",v_limit));
		} else {
printf("%s",PD_NEXT_TAG_CS_RED);
		}

		if (ind_remaining_limit >= 0) {
			if (v_remaining_limit > 1E-9) {
printf("%s",PD_NEXT_TAG_CS);
printf("%s",commaprintdouble(v_remaining_limit,2));
			} else {
printf("%s",PD_NEXT_TAG_CS_RED);
printf("-%s",commaprintdouble(fabs(v_remaining_limit),2));
			}
//printf("%.2lf",v_remaining_limit);
DEBUGLOG(("psp_limit_report_group_o() remaining_limit = [%.2lf]\n",v_remaining_limit));
		} else {
printf("%s",PD_NEXT_TAG_CS_RED);
		}

printf("%s\n",PD_END_TAG);

		if (ind_cnt >= 0) {
DEBUGLOG(("psp_limit_report_group_o() cnt = [%d]\n",v_cnt));
		}
	}
	/* EXEC SQL CLOSE c_group_o; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )763;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto merchant_error;
}



printf("</table>\n");

DEBUGLOG(("psp_limit_report_group_o() iRet = [%d]\n",iRet));
	return iRet;

merchant_error:
DEBUGLOG(("psp_limit_report_group_o error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_group_o; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )778;
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
    sqlstm.arrsiz = 12;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )793;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int mpg_psp_limit_report_merchant(char* csCheckGroup, int iShowEmptyPIDGroup, int iShowEmptyCSegment)
{
	int     iRet = SUCCESS;
	int	iCnt = 0;
	char	csPIDGroup[PD_DESC_LEN + 1];
	char	csCSegment[PD_DESC_LEN + 1];
	strcpy(csPIDGroup,"");
	strcpy(csCSegment,"");

	/* EXEC SQL WHENEVER SQLERROR GOTO mpg_merchant_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar hv_check_group[EML_CHK_GRP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } hv_check_group;


		//varchar	v_merchant_id[PD_MERCHANT_ID_LEN + 1];
		/* varchar	v_client_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_client_id;

		/* varchar	v_client_name[PD_CLIENT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_client_name;

		/* varchar	v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar	v_psp_name[PD_PSP_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_name;

		/* varchar	v_remark[PD_REMARK_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;

		/* varchar	v_currency[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

		//double	v_ratio;
		/* varchar v_pid_group[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_pid_group;

		/* varchar	v_customer_segment[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_customer_segment;

		double	v_limit;
		double	v_remaining_limit;
		double	v_min_txn_amount;
		double	v_max_txn_amount;
		//int	v_criteria_pool_id;
		//int	v_pool_id;
		int	v_cnt;

		//short	ind_merchant_id = -1;
		short	ind_client_id = -1;
		short	ind_client_name = -1;
		short	ind_psp_id = -1;
		short	ind_psp_name = -1;
		short	ind_remark = -1;
		short	ind_currency = -1;
		//short	ind_ratio = -1;
		short	ind_pid_group = -1;
		short	ind_customer_segment = -1;
		short	ind_limit = -1;
		short	ind_remaining_limit = -1;
		short	ind_min_txn_amount = -1;
		short	ind_max_txn_amount = -1;
		//short	ind_criteria_pool_id = -1;
		//short	ind_pool_id = -1;
		short	ind_cnt = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_check_group.len = strlen((char*)csCheckGroup);
	memcpy(hv_check_group.arr,csCheckGroup,hv_check_group.len);

	/* EXEC SQL DECLARE c_mpg_merchant CURSOR FOR
		SELECT	/o CLIENT_ID AS CLIENT_ID,
			CLIENT_NAME AS CLIENT_NAME,o/
			--MERCHANT_ID AS MERCHANT_ID,
			/oSHORT_NAME AS SHORT_NAME,
			BUSINESS_TYPE AS BUSINESS_TYPE, o/
			PSP_CLIENT_ID AS PSP_CLIENT_ID,
			PSP_CLIENT_NAME AS PSP_CLIENT_NAME,
			PSP_ID AS PSP_ID,
			PSP_NAME AS PSP_NAME,
			PSP_REMARK AS PSP_REMARK,
			CURRENCY_ID AS CURRENCY_ID,
			LIMIT AS LIMIT,
			REMAINING_LIMIT AS REMAINING_LIMIT,
			MIN_TRANSACTION_AMOUNT AS MIN_TRANSACTION_AMOUNT,
			MAX_TRANSACTION_AMOUNT AS MAX_TRANSACTION_AMOUNT,
			NVL(PID_GROUP_DESC,'-') AS PID_GROUP,
			NVL(CUSTOMER_SEGMENT_DESC,'-') AS CUSTOMER_SEGMENT,
			--CRITERIA_POOL_ID AS CRITERIA_POOL_ID,
			--POOL_ID AS POOL_ID,
			/oPOOL_RATIO AS POOL_RATIO_BAK, o/
			--POOL_RM_RATIO AS POOL_RATIO,
			count(*) OVER () AS TOTAL_ROWS
		FROM (
			SELECT 
				--CLIENT_ID AS CLIENT_ID,
				--CLIENT_NAME AS CLIENT_NAME,
				--MERCHANT_ID AS MERCHANT_ID,
				--SHORT_NAME AS SHORT_NAME,
				BUSINESS_TYPE AS BUSINESS_TYPE,
				PSP_CLIENT_ID AS PSP_CLIENT_ID,
				PSP_CLIENT_NAME AS PSP_CLIENT_NAME,
				PSP_ID AS PSP_ID,
				PSP_NAME AS PSP_NAME,
				PSP_REMARK AS PSP_REMARK,
				CURRENCY_ID AS CURRENCY_ID,
				LIMIT AS LIMIT,
				REMAINING_LIMIT AS REMAINING_LIMIT,
				MIN(MIN_TRANSACTION_AMOUNT) AS MIN_TRANSACTION_AMOUNT,
				MAX(MAX_TRANSACTION_AMOUNT) AS MAX_TRANSACTION_AMOUNT,
				PID_GROUP AS PID_GROUP_CODE,
                                DEF_PID_GROUP.DG_DESC AS PID_GROUP_DESC,
				CUSTOMER_SEGMENT AS CUSTOMER_SEGMENT_CODE,
				CUSTOMER_GROUP.CG_DESC AS CUSTOMER_SEGMENT_DESC
				/oCRITERIA_POOL_ID AS CRITERIA_POOL_ID,
				POOL_ID AS POOL_ID,
				POOL_RATIO AS POOL_RATIO,
				POOL_RM_RATIO AS POOL_RM_RATIOo/
			FROM PSP_LIMIT_MERCHANT_VIEW
			LEFT JOIN DEF_PID_GROUP ON DEF_PID_GROUP.DG_CODE = PSP_LIMIT_MERCHANT_VIEW.PID_GROUP
			LEFT JOIN CUSTOMER_GROUP ON CUSTOMER_GROUP.CG_CODE = PSP_LIMIT_MERCHANT_VIEW.CUSTOMER_SEGMENT
			WHERE MERCHANT_ID IN   (SELECT EPM_PARTY_ID
						FROM EMAIL_CHECK_PARTY_MAP 
						     --CUSTOMER_GROUP_MERCHANT
						WHERE EPM_NAME = 'PSP_LIMIT'
						AND EPM_GROUP = :hv_check_group
						AND EPM_PARTY_TYPE = 'M'
						AND EPM_SUPPORT_MULTI_ENTRY = 1
						--AND CGM_MERCHANT_ID = EPM_PARTY_ID
						--AND CGM_PHASE > 0
						--AND CGM_DISABLED = 0
						)
			GROUP BY 
				--CLIENT_ID,
				--CLIENT_NAME,
				--MERCHANT_ID,
				--SHORT_NAME,
				BUSINESS_TYPE,
				PSP_CLIENT_ID,
				PSP_CLIENT_NAME,
				PSP_ID,
				PSP_NAME,
				PSP_REMARK,
				CURRENCY_ID,
				LIMIT,
				REMAINING_LIMIT,
				PID_GROUP,
                                DG_DESC,
				CUSTOMER_SEGMENT,
				CG_DESC
				/oCRITERIA_POOL_ID,
				POOL_ID,
				POOL_RATIO,
				POOL_RM_RATIOo/
			) summary
		WHERE 1 = 1
		ORDER BY
			PID_GROUP,
			CUSTOMER_SEGMENT,
			--MERCHANT_ID,
			--CLIENT_NAME,
			--SHORT_NAME,
			UPPER(PSP_NAME),
			CURRENCY_ID; */ 


	/* EXEC SQL OPEN c_mpg_merchant; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "SELECT PSP_CLIENT_ID AS PSP_CLIENT_ID , PSP_CLIENT_NAME AS PSP_CLIENT_NA\
ME , PSP_ID AS PSP_ID , PSP_NAME AS PSP_NAME , PSP_REMARK AS PSP_REMARK , CU\
RRENCY_ID AS CURRENCY_ID , LIMIT AS LIMIT , REMAINING_LIMIT AS REMAINING_LIM\
IT , MIN_TRANSACTION_AMOUNT AS MIN_TRANSACTION_AMOUNT , MAX_TRANSACTION_AMOU\
NT AS MAX_TRANSACTION_AMOUNT , NVL ( PID_GROUP_DESC , '-' ) AS PID_GROUP , N\
VL ( CUSTOMER_SEGMENT_DESC , '-' ) AS CUSTOMER_SEGMENT , count ( * ) OVER ( \
) AS TOTAL_ROWS FROM ( SELECT BUSINESS_TYPE AS BUSINESS_TYPE , PSP_CLIENT_ID\
 AS PSP_CLIENT_ID , PSP_CLIENT_NAME AS PSP_CLIENT_NAME , PSP_ID AS PSP_ID , \
PSP_NAME AS PSP_NAME , PSP_REMARK AS PSP_REMARK , CURRENCY_ID AS CURRENCY_ID\
 , LIMIT AS LIMIT , REMAINING_LIMIT AS REMAINING_LIMIT , MIN ( MIN_TRANSACTI\
ON_AMOUNT ) AS MIN_TRANSACTION_AMOUNT , MAX ( MAX_TRANSACTION_AMOUNT ) AS MA\
X_TRANSACTION_AMOUNT , PID_GROUP AS PID_GROUP_CODE , DEF_PID_GROUP . DG_DESC\
 AS PID_GROUP_DESC , CUSTOMER_SEGMENT AS CUSTOMER_SEGMENT_CODE , CUSTOMER_GR\
OUP . CG_DESC AS CUSTOMER_SEGMENT_DESC F");
 sqlstm.stmt = sq0017;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )808;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_check_group;
 sqlstm.sqhstl[0] = (unsigned long )13;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto mpg_merchant_error;
}


	for (;;) {
		/* EXEC SQL FETCH c_mpg_merchant
		INTO
			:v_client_id:ind_client_id,
			:v_client_name:ind_client_name,
			:v_psp_id:ind_psp_id,
			:v_psp_name:ind_psp_name,
			:v_remark:ind_remark,
			:v_currency:ind_currency,
			:v_limit:ind_limit,
			:v_remaining_limit:ind_remaining_limit,
			:v_min_txn_amount:ind_min_txn_amount,
			:v_max_txn_amount:ind_max_txn_amount,
			:v_pid_group:ind_pid_group,
			:v_customer_segment:ind_customer_segment,
			:v_cnt:ind_cnt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )827;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_client_id;
  sqlstm.sqhstl[0] = (unsigned long )13;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_client_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_client_name;
  sqlstm.sqhstl[1] = (unsigned long )53;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_client_name;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_psp_id;
  sqlstm.sqhstl[2] = (unsigned long )13;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_psp_id;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_psp_name;
  sqlstm.sqhstl[3] = (unsigned long )53;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_psp_name;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_remark;
  sqlstm.sqhstl[4] = (unsigned long )258;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_remark;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_currency;
  sqlstm.sqhstl[5] = (unsigned long )6;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_currency;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_limit;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_limit;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_remaining_limit;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_remaining_limit;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_min_txn_amount;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_min_txn_amount;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_max_txn_amount;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_max_txn_amount;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_pid_group;
  sqlstm.sqhstl[10] = (unsigned long )53;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_pid_group;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_customer_segment;
  sqlstm.sqhstl[11] = (unsigned long )53;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_customer_segment;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_cnt;
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_cnt;
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
  if (sqlca.sqlcode < 0) goto mpg_merchant_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

		if (ind_pid_group >= 0) {
                        v_pid_group.arr[v_pid_group.len]='\0';

                        if (!strcmp((char*)v_pid_group.arr,"-") && !iShowEmptyPIDGroup) continue;

                        if (strcmp(csPIDGroup,(char*)v_pid_group.arr)) {
                                strcpy(csPIDGroup,(char*)v_pid_group.arr);

if (iCnt > 1) printf("</table>\n");
if (strcmp(csPIDGroup,"-")) printf("<h2>%s</h2>\n",csPIDGroup);

printf("<table border='1'>\n");
printf("<tr><th>PSP Name</th><th>PSP Account Name</th><th>Remark</th><th>Currency</th><th>Customer Segment</th><th>PID Limit</th><th>PSP Remaining Limit</th></tr>\n");
                        }
                }

		if (ind_customer_segment >= 0) {
			v_customer_segment.arr[v_customer_segment.len]='\0';

			if (!strcmp((char*)v_customer_segment.arr,"-") && !iShowEmptyCSegment) continue;
		}

		if (ind_client_id >= 0) {
			v_client_id.arr[v_client_id.len]='\0';
DEBUGLOG(("mpg_psp_limit_report_merchant() client_id = [%s]\n",v_client_id.arr));
		}

printf("%s",PD_OPEN_TAG);

		if (ind_client_name >= 0) {
			v_client_name.arr[v_client_name.len]='\0';
printf("%s",(char*)v_client_name.arr);
DEBUGLOG(("mpg_psp_limit_report_merchant() client_name = [%s]\n",v_client_name.arr));
		}

		if (ind_psp_id >= 0) {
			v_psp_id.arr[v_psp_id.len]='\0';
DEBUGLOG(("mpg_psp_limit_report_merchant() psp_id = [%s]\n",v_psp_id.arr));
		}

printf("%s",PD_NEXT_TAG);

		if (ind_psp_name >= 0) {
			v_psp_name.arr[v_psp_name.len]='\0';
printf("%s",(char*)v_psp_name.arr);
DEBUGLOG(("mpg_psp_limit_report_merchant() psp_name = [%s]\n",v_psp_name.arr));
		}

printf("%s",PD_NEXT_TAG);

		if (ind_remark >= 0) {
			v_remark.arr[v_remark.len]='\0';
printf("%s",(char*)v_remark.arr);
DEBUGLOG(("mpg_psp_limit_report_merchant() remark = [%s]\n",v_remark.arr));
		}

printf("%s",PD_NEXT_TAG);

		if (ind_currency >= 0) {
			v_currency.arr[v_currency.len]='\0';
printf("%s",(char*)v_currency.arr);
DEBUGLOG(("mpg_psp_limit_report_merchant() currency = [%s]\n",v_currency.arr));
		}

printf("%s",PD_NEXT_TAG);

		if (ind_customer_segment >= 0) {
			v_customer_segment.arr[v_customer_segment.len]='\0';
printf("%s",(char*)v_customer_segment.arr);
DEBUGLOG(("mpg_psp_limit_report_merchant() customer_segment = [%s]\n",v_customer_segment.arr));
		}

		if (ind_limit >= 0) {
			if (v_limit > 1E-9) {
printf("%s",PD_NEXT_TAG_CS);
printf("%s",commaprintdouble(v_limit,2));
			} else {
printf("%s",PD_NEXT_TAG_CS_RED);
printf("-%s",commaprintdouble(fabs(v_limit),2));
			}
//printf("%.2lf",v_limit);
DEBUGLOG(("mpg_psp_limit_report_merchant() limit = [%.2lf]\n",v_limit));
		} else {
printf("%s",PD_NEXT_TAG_CS_RED);
		}

		if (ind_remaining_limit >= 0) {
			if (v_remaining_limit > 1E-9) {
printf("%s",PD_NEXT_TAG_CS);
printf("%s",commaprintdouble(v_remaining_limit,2));
			} else {
printf("%s",PD_NEXT_TAG_CS_RED);
printf("-%s",commaprintdouble(fabs(v_remaining_limit),2));
			}
//printf("%.2lf",v_remaining_limit);
DEBUGLOG(("mpg_psp_limit_report_merchant() remaining_limit = [%.2lf]\n",v_remaining_limit));
		} else {
printf("%s",PD_NEXT_TAG_CS_RED);
		}

printf("%s\n",PD_END_TAG);

		if (ind_cnt >= 0) {
DEBUGLOG(("mpg_psp_limit_report_merchant() cnt = [%d]\n",v_cnt));
		}
	}
	/* EXEC SQL CLOSE c_mpg_merchant; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )894;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto mpg_merchant_error;
}



//if (iCnt > 1) printf("</table>\n");
if (iCnt >= 1) printf("</table>\n");

DEBUGLOG(("mpg_psp_limit_report_merchant() iRet = [%d]\n",iRet));
	return iRet;

mpg_merchant_error:
DEBUGLOG(("mpg_psp_limit_report_merchant error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_mpg_merchant; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )909;
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
    sqlstm.arrsiz = 13;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )924;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int psp_limit_report_group_pool(char *csPoolId, char *csServiceCode)
{
	int     iRet = SUCCESS;
	int	iCnt = 0;
	int	iPool = -1;

	/* EXEC SQL WHENEVER SQLERROR GOTO service_pool_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar hv_pool_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_pool_id;


		/* varchar	v_client_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_client_id;

		/* varchar	v_client_name[PD_CLIENT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_client_name;

		/* varchar	v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar	v_psp_name[PD_PSP_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_name;

		/* varchar	v_remark[PD_REMARK_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;

		/* varchar	v_currency[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

		int	v_pool_id;
		int	v_ratio;
		int	v_priority;
		/* varchar	v_customer_segment[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_customer_segment;

		double	v_limit;
		double	v_remaining_limit;
		double	v_min_txn_amount;
		double	v_max_txn_amount;
		//int	v_criteria_pool_id;

		short	ind_client_id = -1;
		short	ind_client_name = -1;
		short	ind_psp_id = -1;
		short	ind_psp_name = -1;
		short	ind_remark = -1;
		short	ind_currency = -1;
		short	ind_pool_id = -1;
		short	ind_ratio = -1;
		short	ind_priority = -1;
		short	ind_customer_segment = -1;
		short	ind_limit = -1;
		short	ind_remaining_limit = -1;
		short	ind_min_txn_amount = -1;
		short	ind_max_txn_amount = -1;
		//short	ind_criteria_pool_id = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_pool_id.len = strlen((char*)csPoolId);
	memcpy(hv_pool_id.arr,csPoolId,hv_pool_id.len);

	hv_service_code.len = strlen((char*)csServiceCode);
	memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);

	/* EXEC SQL DECLARE c_service_pool CURSOR FOR
		SELECT	PSP_CLIENT_ID AS PSP_CLIENT_ID,
			PSP_CLIENT_NAME AS PSP_CLIENT_NAME,
			PSP_ID AS PSP_ID,
			PSP_NAME AS PSP_NAME,
			PSP_REMARK AS PSP_REMARK,
			CURRENCY_ID AS CURRENCY_ID,
			LIMIT AS LIMIT,
			REMAINING_LIMIT AS REMAINING_LIMIT,
			MIN(MIN_TRANSACTION_AMOUNT) AS MIN_TRANSACTION_AMOUNT,
			MAX(MAX_TRANSACTION_AMOUNT) AS MAX_TRANSACTION_AMOUNT,
			NVL(CUSTOMER_SEGMENT,'-') AS CUSTOMER_SEGMENT,
			--CRITERIA_POOL_ID AS CRITERIA_POOL_ID,
			POOL_ID AS POOL_ID,
			POOL_RM_RATIO,
			RM_PRIORITY
		FROM PSP_LIMIT_MERCHANT_VIEW
		LEFT JOIN CUSTOMER_GROUP ON CUSTOMER_GROUP.CG_CODE = PSP_LIMIT_MERCHANT_VIEW.CUSTOMER_SEGMENT,
		RULE_PSP_LB_MAPPING
		WHERE SERVICE_CODE = :hv_service_code
		AND (POOL_ID = :hv_pool_id or :hv_pool_id = '000')
		AND POOL_ID = RM_POOL_ID
		AND PSP_ID = RM_PSP_ID
		AND RM_DISABLED = 0
		GROUP BY PSP_CLIENT_ID,
			PSP_CLIENT_NAME,
			PSP_ID,
			PSP_NAME,
			PSP_REMARK,
			CURRENCY_ID,
			LIMIT,
			REMAINING_LIMIT,
			CUSTOMER_SEGMENT,
			--CRITERIA_POOL_ID,
			POOL_ID,
			POOL_RM_RATIO,
			RM_PRIORITY
		ORDER BY
			POOL_ID,
			CUSTOMER_SEGMENT,
			UPPER(PSP_NAME),
			CURRENCY_ID; */ 


	/* EXEC SQL OPEN c_service_pool; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0019;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )939;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[0] = (unsigned long )5;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_pool_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_pool_id;
 sqlstm.sqhstl[2] = (unsigned long )17;
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
 if (sqlca.sqlcode < 0) goto service_pool_error;
}


	for (;;) {
		/* EXEC SQL FETCH c_service_pool
		INTO
			:v_client_id:ind_client_id,
			:v_client_name:ind_client_name,
			:v_psp_id:ind_psp_id,
			:v_psp_name:ind_psp_name,
			:v_remark:ind_remark,
			:v_currency:ind_currency,
			:v_limit:ind_limit,
			:v_remaining_limit:ind_remaining_limit,
			:v_min_txn_amount:ind_min_txn_amount,
			:v_max_txn_amount:ind_max_txn_amount,
			:v_customer_segment:ind_customer_segment,
			//:v_criteria_pool_id:ind_criteria_pool_id,
			:v_pool_id:ind_pool_id,
			:v_ratio:ind_ratio,
			:v_priority:ind_priority; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )966;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_client_id;
  sqlstm.sqhstl[0] = (unsigned long )13;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_client_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_client_name;
  sqlstm.sqhstl[1] = (unsigned long )53;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_client_name;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_psp_id;
  sqlstm.sqhstl[2] = (unsigned long )13;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_psp_id;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_psp_name;
  sqlstm.sqhstl[3] = (unsigned long )53;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_psp_name;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_remark;
  sqlstm.sqhstl[4] = (unsigned long )258;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_remark;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_currency;
  sqlstm.sqhstl[5] = (unsigned long )6;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_currency;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_limit;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_limit;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_remaining_limit;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_remaining_limit;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_min_txn_amount;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_min_txn_amount;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_max_txn_amount;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_max_txn_amount;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_customer_segment;
  sqlstm.sqhstl[10] = (unsigned long )53;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_customer_segment;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_pool_id;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_pool_id;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_ratio;
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_ratio;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_priority;
  sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_priority;
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
  if (sqlca.sqlcode < 0) goto service_pool_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

		if (ind_pool_id >= 0) {
DEBUGLOG(("psp_limit_report_group_pool() pool_id = [%d]\n",(int)v_pool_id));
			if (iPool != v_pool_id) {
				iPool = v_pool_id;
if (iCnt > 1) printf("</table>\n");
printf("<h2>%s %d</h2>\n","Pool",iPool);

printf("<table border='1'>\n");
//printf("<tr><th>PSP Name</th><th>PSP Account Name</th><th>Remark</th><th>Currency</th><th>Ratio</th><th>Customer Segment</th><th>PID Limit</th><th>PSP Remaining Limit</th></tr>\n");
printf("<tr><th>PSP Name</th><th>PSP Account Name</th><th>Remark</th><th>Currency<th>Priority</th><th>PID Limit</th><th>PSP Remaining Limit</th></tr>\n");
			}
		}

		if (ind_client_id >= 0) {
			v_client_id.arr[v_client_id.len]='\0';
DEBUGLOG(("psp_limit_report_group_pool() client_id = [%s]\n",v_client_id.arr));
		}

printf("%s",PD_OPEN_TAG);

		if (ind_client_name >= 0) {
			v_client_name.arr[v_client_name.len]='\0';
printf("%s",(char*)v_client_name.arr);
DEBUGLOG(("psp_limit_report_group_pool() client_name = [%s]\n",v_client_name.arr));
		}

		if (ind_psp_id >= 0) {
			v_psp_id.arr[v_psp_id.len]='\0';
DEBUGLOG(("psp_limit_report_group_pool() psp_id = [%s]\n",v_psp_id.arr));
		}

printf("%s",PD_NEXT_TAG);

		if (ind_psp_name >= 0) {
			v_psp_name.arr[v_psp_name.len]='\0';
printf("%s",(char*)v_psp_name.arr);
DEBUGLOG(("psp_limit_report_group_pool() psp_name = [%s]\n",v_psp_name.arr));
		}

printf("%s",PD_NEXT_TAG);

		if (ind_remark >= 0) {
			v_remark.arr[v_remark.len]='\0';
printf("%s",(char*)v_remark.arr);
DEBUGLOG(("psp_limit_report_group_pool() remark = [%s]\n",v_remark.arr));
		}

printf("%s",PD_NEXT_TAG);

		if (ind_currency >= 0) {
			v_currency.arr[v_currency.len]='\0';
printf("%s",(char*)v_currency.arr);
DEBUGLOG(("psp_limit_report_group_pool() currency = [%s]\n",v_currency.arr));
		}

printf("%s",PD_NEXT_TAG_CS);

		if (ind_priority >= 0) {
printf("%d",(int)v_priority);
DEBUGLOG(("psp_limit_report_group_pool() priority = [%d]\n",(int)v_priority));
		}

//printf("%s",PD_NEXT_TAG);
//
//		if (ind_customer_segment >= 0) {
//			v_customer_segment.arr[v_customer_segment.len]='\0';
//printf("%s",(char*)v_customer_segment.arr);
//DEBUGLOG(("psp_limit_report_group_pool() customer_segment = [%s]\n",v_customer_segment.arr));
//		}

		if (ind_limit >= 0) {
			if (v_limit > 1E-9) {
printf("%s",PD_NEXT_TAG_CS);
printf("%s",commaprintdouble(v_limit,2));
			} else {
printf("%s",PD_NEXT_TAG_CS_RED);
printf("-%s",commaprintdouble(fabs(v_limit),2));
			}
//printf("%.2lf",v_limit);
DEBUGLOG(("psp_limit_report_group_pool() limit = [%.2lf]\n",v_limit));
		} else {
printf("%s",PD_NEXT_TAG_CS_RED);
		}

		if (ind_remaining_limit >= 0) {
			if (v_remaining_limit > 1E-9) {
printf("%s",PD_NEXT_TAG_CS);
printf("%s",commaprintdouble(v_remaining_limit,2));
			} else {
printf("%s",PD_NEXT_TAG_CS_RED);
printf("-%s",commaprintdouble(fabs(v_remaining_limit),2));
			}
//printf("%.2lf",v_remaining_limit);
DEBUGLOG(("psp_limit_report_group_pool() remaining_limit = [%.2lf]\n",v_remaining_limit));
		} else {
printf("%s",PD_NEXT_TAG_CS_RED);
		}

printf("%s\n",PD_END_TAG);
	}
	/* EXEC SQL CLOSE c_service_pool; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1037;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto service_pool_error;
}



//if (iCnt > 1) printf("</table>\n");
if (iCnt >= 1) printf("</table>\n");

DEBUGLOG(("psp_limit_report_group_pool() iRet = [%d]\n",iRet));
	return iRet;

service_pool_error:
DEBUGLOG(("psp_limit_report_group_pool error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_service_pool; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 14;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1052;
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
    sqlstm.offset = (unsigned int  )1067;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int find_limit_to_gen(recordset_t *myRec)
{
	int	iRet = SUCCESS;

	hash_t *myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO find_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		char	v_party_type;
		/* varchar	v_party_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;

		/* varchar	v_service_code[PD_SERVICE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;


		short	ind_party_type = -1;
		short	ind_party_id = -1;
		short	ind_service_code = -1;

	/* EXEC SQL END DECLARE SECTION; */ 

	
	/* EXEC SQL DECLARE c_cursor_findlimittogen CURSOR FOR
		SELECT	PG_PARTY_TYPE,
			PG_PARTY_ID,
			PG_SERVICE_CODE
		FROM	PSP_LIMIT_GEN
		WHERE	PG_DISABLED = 0
		ORDER BY PG_PARTY_TYPE, PG_PARTY_ID, PG_SERVICE_CODE; */ 


	/* EXEC SQL OPEN c_cursor_findlimittogen; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0021;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1082;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto find_error;
}



	for (;;) {
		/* EXEC SQL FETCH c_cursor_findlimittogen
		INTO	:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_service_code:ind_service_code; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 14;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1097;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_party_type;
  sqlstm.sqhstl[0] = (unsigned long )1;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_party_type;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_party_id;
  sqlstm.sqhstl[1] = (unsigned long )18;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_party_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_service_code;
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_service_code;
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
  if (sqlca.sqlcode < 0) goto find_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash, 0);

		// party_type
		if (ind_party_type >= 0) {
			PutField_Char(myHash, "party_type", v_party_type);
DEBUGLOG(("find_limit_gen party_type = [%c]\n", v_party_type));
		}

		// party_id
		if (ind_party_id >= 0) {
			v_party_id.arr[v_party_id.len] = '\0';
			PutField_CString(myHash, "party_id", (const char*)v_party_id.arr);
DEBUGLOG(("find_limit_gen party_id = [%s]\n", (const char*)v_party_id.arr));
		}

		// service_code
		if (ind_service_code >= 0) {
			v_service_code.arr[v_service_code.len] = '\0';
			PutField_CString(myHash, "service_code", (const char*)v_service_code.arr);
DEBUGLOG(("find_limit_gen service_code = [%s]\n", (const char*)v_service_code.arr));
		}

		RecordSet_Add(myRec, myHash);
	}

	/* EXEC SQL CLOSE c_cursor_findlimittogen; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1124;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto find_error;
}



DEBUGLOG(("find_limit_gen Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

find_error:
DEBUGLOG(("find_limit_to_gen error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("gen_psp_limit_report find_limit_gen code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL CLOSE c_cursor_findlimittogen; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1139;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto find_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


int parse_arg(int argc, char **argv)
{
	return SUCCESS;
}
