
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
           char  filnam[26];
};
static struct sqlcxp sqlfpn =
{
    25,
    "processing_costs_daily.pc"
};


static unsigned int sqlctx = 1635663485;


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
   unsigned char  *sqhstv[7];
   unsigned long  sqhstl[7];
            int   sqhsts[7];
            short *sqindv[7];
            int   sqinds[7];
   unsigned long  sqharm[7];
   unsigned long  *sqharc[7];
   unsigned short  sqadto[7];
   unsigned short  sqtdso[7];
} sqlstm = {12,7};

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
"SELECT OTH_TXN_ID , OTP_BAID , OTH_TXN_CODE , OTH_TRANSACTION_AMOUNT , OTP_\
CHARGE_RULE_ID , OTP_TXN_CCY , COUNTRY FROM OL_TXN_HEADER , OL_TXN_PSP_DETAIL\
 , OL_BANK_ACCT_ID , BANK_DESC WHERE OTH_TXN_ID = OTP_TXN_ID AND OTP_BAID = O\
BAI_BAID AND OBAI_INT_BANK_CODE = INTERNAL_BANK_CODE AND OTH_APPROVAL_DATE < \
( SELECT SYS_VAL from SYSTEM_CONTROL WHERE SYS_CODE = 'CTPHDATE' ) AND OTP_PS\
P_ID = :b0 AND OTP_CHARGE_PERIOD_TYPE = :b1 AND OTP_CHARGE_TXN_CREATED = :b2 \
AND OTP_CHARGE_RULE_ID IS NOT NULL AND OBAI_CATEGORY NOT IN ( SELECT OPCE_EXC\
LUDE_ACCT_TYPE FROM OL_PSP_COSTS_EXCLUDE WHERE OTP_CHARGE_RULE_ID = OPCE_RULE\
_ID ) ORDER BY OTP_CHARGE_RULE_ID , OTH_TXN_CODE , OTP_BAID , OTH_TXN_ID     \
       ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,698,0,9,190,0,2049,3,3,0,1,0,1,9,0,0,1,1,0,0,1,3,0,0,
32,0,0,1,0,0,13,192,0,0,7,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,3,0,0,2,9,
0,0,2,9,0,0,
75,0,0,1,0,0,15,375,0,0,0,0,0,1,0,
90,0,0,2,0,0,32,376,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/12/23              [WWK]
Not create txn when provider cost is zero          2021/05/13              [MIC]
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlca.h>
#include <unistd.h>
#include "batchcommon.h"
#include "common.h"
#include "utilitys.h"
#include "internal.h"
#include "myrecordset.h"
#include "ObjPtr.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cs_psp_id[PD_PSP_ID_LEN + 1];
char    cs_baid[PD_BAID_LEN + 1];
char	cs_txn_id[PD_TXN_SEQ_LEN + 1];
char	cs_txn_code[PD_TXN_CODE_LEN + 1];
char	cs_txn_ccy[PD_CCY_ID_LEN + 1];
char	cs_country[PD_COUNTRY_LEN + 1];
char    cDebug;

OBJPTR(Channel);
OBJPTR(DB);
OBJPTR(BO);

int parse_arg(int argc,char **argv);

int process_daily_cal_txn(const char* csPspId);
int CreateNewTxn(hash_t* hRls, char* csChargeTxnSeq);
int UpdateTxnPspDetail(const char* csOrgTxnSeq, const char* csChargeTxnSeq);

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}

int batch_proc(int argc, char* argv[])
{
	int     iRet;

	iRet = parse_arg(argc,argv);

	if(iRet != SUCCESS)
printf("usage: -p psp_id\n");

	if(iRet == SUCCESS)
		iRet = process_daily_cal_txn(cs_psp_id);

	return iRet;
}

int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

int parse_arg(int argc,char **argv)
{
	if (argc < 3) {
		return PD_ERR;
	}

	char c;
	strcpy(cs_psp_id,"");

	while ((c = getopt(argc,argv,"p:")) != EOF) {
		switch (c) {
			case 'p':
				strcpy(cs_psp_id, optarg);
				break;
			default:
				return PD_ERR;
		}
	}

	if (!strcmp(cs_psp_id,""))
		return PD_ERR;

	return SUCCESS;
}

int process_daily_cal_txn(const char* csPspId)
{
	int	iRet = SUCCESS;

	int	i,j=0;
	char	csTmp[PD_TMP_BUF_LEN+1];
	char*	csTmp2;
	char	cTmp;
	int	iTmp=0;
	double	dTmp=0.0;
	double	dTotalAmt=0.0;

	int	iKeyCount = 0;
	char	csChargeTxnSeq[PD_TXN_SEQ_LEN+1];

	hash_t*	hTxnRecordset;
	hTxnRecordset = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxnRecordset,0);

	hash_t*	hContext;
	hContext = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hContext,0);

	DBObjPtr = CreateObj(DBPtr,"DBOLBankAcctId","GetBaidByPspCategory");
	if ((unsigned long)(*DBObjPtr)(csPspId,PD_BAID_CAT_IQ,hContext) == PD_OK) {
		if (GetField_CString(hContext,"baid",&csTmp)) {
DEBUGLOG(("PID [%s] Baid(IQ) = [%s]\n",csPspId,csTmp));
		}
	} else {
DEBUGLOG(("PID [%s] does not have BAID (IQ) acctount!\n",csPspId));
ERRLOG("processing_costs_daily PID [%s] does not have BAID (IQ) acctount!\n",csPspId);
		return FAILURE;
	}


	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		char	hv_charge_period_type;
		int	hv_charge_txn_created;

		/* varchar	v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar	v_baid[PD_BAID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_baid;

		/* varchar	v_txn_code[PD_TXN_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

		double	v_txn_amt;
		int	v_rule_id;
		/* varchar	v_txn_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

		/* varchar	v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;


		short	ind_txn_id = -1;
		short	ind_baid = -1;
		short	ind_txn_code = -1;
		short	ind_txn_amt = -1;
		short	ind_rule_id = -1;
		short	ind_txn_ccy = -1;
		short	ind_country = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_psp_id.len = strlen((char*)csPspId);
	memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);

	hv_charge_period_type = PD_COST_PERIOD_DAILY;

	hv_charge_txn_created = 0;
DEBUGLOG(("PID [%.*s] Start\n",hv_psp_id.len,hv_psp_id.arr));

	/* EXEC SQL DECLARE c_cursor_getdailycaltxn CURSOR FOR
		SELECT	OTH_TXN_ID,
			OTP_BAID,
			OTH_TXN_CODE, 
			OTH_TRANSACTION_AMOUNT,
			OTP_CHARGE_RULE_ID,
			OTP_TXN_CCY,
			COUNTRY
		FROM	OL_TXN_HEADER,
			OL_TXN_PSP_DETAIL,
			OL_BANK_ACCT_ID,
			BANK_DESC
		WHERE	OTH_TXN_ID=OTP_TXN_ID
		AND	OTP_BAID=OBAI_BAID
		AND	OBAI_INT_BANK_CODE=INTERNAL_BANK_CODE
		AND	OTH_APPROVAL_DATE < (SELECT SYS_VAL from SYSTEM_CONTROL WHERE SYS_CODE='CTPHDATE')
		AND	OTP_PSP_ID = :hv_psp_id
		AND	OTP_CHARGE_PERIOD_TYPE = :hv_charge_period_type
		AND	OTP_CHARGE_TXN_CREATED = :hv_charge_txn_created
		AND	OTP_CHARGE_RULE_ID IS NOT NULL
		AND	OBAI_CATEGORY NOT IN	(SELECT	OPCE_EXCLUDE_ACCT_TYPE
						 FROM	OL_PSP_COSTS_EXCLUDE 
						 WHERE	OTP_CHARGE_RULE_ID = OPCE_RULE_ID)
		ORDER BY	OTP_CHARGE_RULE_ID,
				OTH_TXN_CODE,
				OTP_BAID,
				OTH_TXN_ID; */ 


	/* EXEC SQL OPEN c_cursor_getdailycaltxn; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[0] = (unsigned long )12;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_charge_period_type;
 sqlstm.sqhstl[1] = (unsigned long )1;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_charge_txn_created;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto sql_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getdailycaltxn
		INTO
			:v_txn_id:ind_txn_id,
			:v_baid:ind_baid,
			:v_txn_code:ind_txn_code,
			:v_txn_amt:ind_txn_amt,
			:v_rule_id:ind_rule_id,
			:v_txn_ccy:ind_txn_ccy,
			:v_country:ind_country; */ 

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
  sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_txn_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_baid;
  sqlstm.sqhstl[1] = (unsigned long )23;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_baid;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_code;
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_txn_code;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_amt;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_txn_amt;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_rule_id;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_rule_id;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_txn_ccy;
  sqlstm.sqhstl[5] = (unsigned long )6;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_txn_ccy;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_country;
  sqlstm.sqhstl[6] = (unsigned long )5;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_country;
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
  if (sqlca.sqlcode < 0) goto sql_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
DEBUGLOG(("No more record found, break\n"));
			break;
		}

		if (ind_baid>=0 && ind_rule_id>=0 && ind_txn_code>=0) {
			v_baid.arr[v_baid.len]='\0';
			strcpy((char*)cs_baid, (const char*)v_baid.arr);
			v_txn_code.arr[v_txn_code.len]='\0';
			strcpy((char*)cs_txn_code, (const char*)v_txn_code.arr);
			sprintf(csTmp,"hKey_%s_%d",(char*)cs_txn_code,v_rule_id);
			if (!GetField_CString(hTxnRecordset,csTmp,&csTmp)) {
				iKeyCount += 1;
				PutField_CString(hTxnRecordset,csTmp,csTmp);
DEBUGLOG(("process_daily_cal_txn >>> Key #%d found [%s]\n",iKeyCount,csTmp));
				sprintf(csTmp,"rule_%d_count",iKeyCount);
				iTmp = 1;
				PutField_Int(hTxnRecordset,csTmp,iTmp);

			//Static info
				sprintf(csTmp,"r_%d_rule_id",iKeyCount);
				PutField_Int(hTxnRecordset,csTmp,v_rule_id);
//DEBUGLOG(("process_daily_cal_txn [%s] = [%d]\n",csTmp,v_rule_id));
				sprintf(csTmp,"r_%d_txn_code",iKeyCount);
				PutField_CString(hTxnRecordset,csTmp,(char*)cs_txn_code);
//DEBUGLOG(("process_daily_cal_txn [%s] = [%s]\n",csTmp,(char*)cs_txn_code));
				if (ind_txn_ccy>=0) {
					v_txn_ccy.arr[v_txn_ccy.len]='\0';
					strcpy((char*)cs_txn_ccy, (const char*)v_txn_ccy.arr);
					sprintf(csTmp,"r_%d_txn_ccy",iKeyCount);
					PutField_CString(hTxnRecordset,csTmp,(char*)cs_txn_ccy);
//DEBUGLOG(("process_daily_cal_txn [%s] = [%s]\n",csTmp,(char*)cs_txn_ccy));
				}
				if (ind_country>=0) {
					v_country.arr[v_country.len]='\0';
					strcpy((char*)cs_country, (const char*)v_country.arr);
					sprintf(csTmp,"r_%d_country",iKeyCount);
					PutField_CString(hTxnRecordset,csTmp,(char*)cs_country);
//DEBUGLOG(("process_daily_cal_txn [%s] = [%s]\n",csTmp,(char*)cs_country));
				}
			} else {
				sprintf(csTmp,"rule_%d_count",iKeyCount);
				if(GetField_Int(hTxnRecordset,csTmp,&iTmp)) {
					iTmp += 1;
					PutField_Int(hTxnRecordset,csTmp,iTmp);
				}
			}
		}

		if (ind_txn_id>=0) {
			v_txn_id.arr[v_txn_id.len]='\0';
			strcpy((char*)cs_txn_id, (const char*)v_txn_id.arr);
			sprintf(csTmp,"r_%d_txn_id_%d",iKeyCount,iTmp);
			PutField_CString(hTxnRecordset,csTmp,(char*)cs_txn_id);
//DEBUGLOG(("process_daily_cal_txn [%s] = [%s]\n",csTmp,(char*)cs_txn_id));
		}

		if (ind_txn_amt>=0) {
			sprintf(csTmp,"r_%d_txn_amt_%d",iKeyCount,iTmp);
			PutField_Double(hTxnRecordset,csTmp,v_txn_amt);
//DEBUGLOG(("process_daily_cal_txn [%s] = [%f]\n",csTmp,v_txn_amt));
		}

	}
	while (PD_TRUE);




DEBUGLOG(("process_daily_cal_txn START process psp costs...\n"));
	for (i=1;i<=iKeyCount;i++) {
DEBUGLOG(("Key %d::\n",i));
		dTotalAmt = 0.0;
		sprintf(csTmp,"r_%d_txn_ccy",i);
		if (GetField_CString(hTxnRecordset,csTmp,&csTmp2)) {
			PutField_CString(hContext,"txn_ccy",csTmp2);
//DEBUGLOG(("process_daily_cal_txn [%s] = [%s]\n",csTmp,csTmp2));
		}
		sprintf(csTmp,"r_%d_country",i);
		if (GetField_CString(hTxnRecordset,csTmp,&csTmp2)) {
			PutField_CString(hContext,"country",csTmp2);
//DEBUGLOG(("process_daily_cal_txn [%s] = [%s]\n",csTmp,csTmp2));
		}
		sprintf(csTmp,"r_%d_txn_code",i);
		if (GetField_CString(hTxnRecordset,csTmp,&csTmp2)) {
			PutField_CString(hContext,"org_txn_code",csTmp2);
//DEBUGLOG(("process_daily_cal_txn [%s] = [%s]\n",csTmp,csTmp2));
		}
		sprintf(csTmp,"r_%d_rule_id",i);
		if (GetField_Int(hTxnRecordset,csTmp,&iTmp)) {
			PutField_Int(hContext,"rule_id",iTmp);
//DEBUGLOG(("process_daily_cal_txn [%s] = [%d]\n",csTmp,iTmp));
		}
		DBObjPtr = CreateObj(DBPtr,"DBOLPspCosts","GetGroupingTypeById");
		if ((unsigned long)(*DBObjPtr)(iTmp,&cTmp) == PD_FOUND) {
//DEBUGLOG(("grouping type = [%c]\n",cTmp));
		}
		sprintf(csTmp,"rule_%d_count",i);
		if (GetField_Int(hTxnRecordset,csTmp,&iTmp)) {
			for (j=1;j<=iTmp;j++) {
				sprintf(csTmp,"r_%d_txn_id_%d",i,j);
				if (GetField_CString(hTxnRecordset,csTmp,&csTmp2)) {
					PutField_CString(hContext,"txn_id",csTmp2);
DEBUGLOG(("process_daily_cal_txn [%s] = [%s]\n",csTmp,csTmp2));
				}
				sprintf(csTmp,"r_%d_txn_amt_%d",i,j);
				if (GetField_Double(hTxnRecordset,csTmp,&dTmp)) {
//DEBUGLOG(("process_daily_cal_txn [%s] = [%f]\n",csTmp,dTmp));
				}

				if (cTmp == PD_COST_GROUPING_BATCH) {
					dTotalAmt += dTmp;
					PutField_Double(hContext,"txn_amt",dTotalAmt);
DEBUGLOG(("process_daily_cal_txn total_amt = [%f]\n",dTotalAmt));
				} else if (cTmp ==PD_COST_GROUPING_PER_TXN) {
					PutField_Double(hContext,"txn_amt",dTmp);
					BOObjPtr = CreateObj(BOPtr,"BOOLPspCosts","CalOLPspCostsByID");
					iRet = (unsigned long)(*BOObjPtr)(hContext,hContext);
					if (iRet == PD_OK) {
						if (GetField_Double(hContext,"precal_fee",&dTmp)) {
DEBUGLOG(("processdaily_cal_txn BOOLPspCosts:CalOLPspCostsByID precal_fee = [%f]\n",dTmp));
						} else {
DEBUGLOG(("processdaily_cal_txn BOOLPspCosts:CalOLPspCostsByID FAILED, iRet = [%d]\n",iRet));
						}
					}
					if(dTmp != 0.0) {
						CreateNewTxn(hContext,csChargeTxnSeq);
						sprintf(csTmp,"r_%d_txn_id_%d",i,j);
						if (GetField_CString(hTxnRecordset,csTmp,&csTmp2)) {
							UpdateTxnPspDetail(csTmp2,csChargeTxnSeq);
						}
					}
				}
			}

			if (cTmp == PD_COST_GROUPING_BATCH) {
				BOObjPtr = CreateObj(BOPtr,"BOOLPspCosts","CalOLPspCostsByID");
				iRet = (unsigned long)(*BOObjPtr)(hContext,hContext);
				if (iRet == PD_OK) {
					if (GetField_Double(hContext,"precal_fee",&dTmp)) {
DEBUGLOG(("processdaily_cal_txn BOOLPspCosts:CalOLPspCostsByID precal_fee = [%f]\n",dTmp));
					} else {
DEBUGLOG(("processdaily_cal_txn BOOLPspCosts:CalOLPspCostsByID FAILED, iRet = [%d]\n",iRet));
					}
				}
				if(dTmp != 0.0) {
					CreateNewTxn(hContext,csChargeTxnSeq);
					sprintf(csTmp,"rule_%d_count",i);
					if (GetField_Int(hTxnRecordset,csTmp,&iTmp)) {
						for (j=1;j<=iTmp;j++) {
							sprintf(csTmp,"r_%d_txn_id_%d",i,j);
							if (GetField_CString(hTxnRecordset,csTmp,&csTmp2)) {
								UpdateTxnPspDetail(csTmp2,csChargeTxnSeq);
							}
						}
					}
				}
			}
		}
	}
DEBUGLOG(("process_daily_cal_txn process psp costs finish\n"));

	FREE_ME(hTxnRecordset);
	FREE_ME(hContext);

DEBUGLOG(("iRet = [%d]\n",iRet));

	return iRet;

sql_error:
DEBUGLOG(("process_daily_cal_txn error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getdailycaltxn; */ 

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
}


    /* EXEC SQL ROLLBACK RELEASE; */ 

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


    return PD_ERR;
}





int CreateNewTxn(hash_t* hRls, char* csChargeTxnSeq) {
	int iRet = SUCCESS;

	char* csTmp;
	char cTmp;
	char* csAmtType;
	double dAmt = 0.0;
	
	char csLocalTxnDateTime[PD_DATETIME_LEN+1];
	char csTmDate[PD_DATE_LEN+1];
	char csTmTime[PD_TIME_LEN+1];
	char csTmpDate[PD_DATETIME_LEN +1];

	hash_t          *hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn,0);

	hash_t          *hRec;
	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec,0);

	hash_t          *hDtl;
	hDtl = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hDtl,0);

	csChargeTxnSeq[0]='\0';
	csLocalTxnDateTime[0]='\0';
	DBObjPtr = CreateObj(DBPtr,"DBOLTxnSeq","GetNextOmtTxnSeq");
	strcpy((char*)csChargeTxnSeq,(*DBObjPtr)());

	DBObjPtr = CreateObj(DBPtr,"DBSystemControl","FindCode");
	if ((unsigned long)(*DBObjPtr)("CTPHDATE",csTmpDate) == FOUND) {
		PutField_CString(hTxn,"report_date",csTmpDate);
	}

	if (GetField_CString(hRls,"gen_txn_code",&csTmp)) {
DEBUGLOG(("new txn_code = [%s]\n", csTmp));
		PutField_CString(hTxn,"txn_code",csTmp);
	} else iRet = FAILURE;

	if (GetField_Double(hRls,"precal_fee",&dAmt)) {
DEBUGLOG(("precal_fee = [%f]\n",dAmt));
		PutField_Double(hTxn,"txn_amt",dAmt);
		PutField_Double(hTxn,"net_amt",dAmt);
		PutField_Double(hTxn,"display_amt",dAmt);
	} else iRet = FAILURE;

	PutField_CString(hTxn,"txn_seq", (const char*)csChargeTxnSeq);
	PutField_CString(hDtl,"txn_seq", (const char*)csChargeTxnSeq);
	PutField_Int(hTxn,"do_logging",PD_ADD_LOG);
	PutField_CString(hTxn,"channel_code",PD_CHANNEL_OMT);
	PutField_Char(hTxn,"status",PD_COMPLETE);
	PutField_Char(hTxn,"ar_ind",PD_ACCEPT);
	PutField_CString(hTxn, "sub_status", PD_APPROVED);
	PutField_CString(hTxn,"host_posting_date",csTmpDate);
	PutField_Int(hTxn,"internal_code",0);
	PutField_CString(hTxn,"response_code","0");

//Get from recordset
	PutField_CString(hTxn,"net_ccy",(char*)cs_txn_ccy);
	PutField_CString(hTxn,"txn_ccy",(char*)cs_txn_ccy);
	PutField_CString(hTxn,"txn_country",(char*)cs_country);

// Get Exchange Rate
	if (iRet == SUCCESS) {
		PutField_CString(hTxn,"dst_txn_ccy",(char*)cs_txn_ccy);
DEBUGLOG(("CreateNewTxn Call BOExchange: GetExchangeInfo\n"));
		BOObjPtr = CreateObj(BOPtr, "BOExchange", "GetExchangeInfo");
		iRet = (unsigned long)(*BOObjPtr)(hTxn, hTxn);
		if (iRet != PD_OK) {
DEBUGLOG(("CreateNewTxn:: Call: BOExchange.GetExchangeInfo failed, return = [%d]\n", iRet));
ERRLOG("TxnOmtByUsPBF::SetFrTxnRecord:: Call: BOExchange.GetExhcnageInfo failed, return = [%d]\n", iRet);
		} else {
			if (GetField_Char(hTxn,"ex_party",&cTmp)) {
				PutField_Char(hTxn,"ex_supplier",cTmp);
			}
		}
	}

	PutField_Int(hTxn,"db_commit",PD_FALSE);
	PutField_CString(hTxn,"process_code","000000");
	PutField_CString(hTxn,"process_type","0000");
	PutField_Char(hTxn, "recon_status", PD_UNRECONCILED);

	strcpy(csLocalTxnDateTime,getdatetime());
	sprintf(csTmDate,"%.*s",PD_DATE_LEN,csLocalTxnDateTime);
	PutField_CString(hTxn,"local_tm_date",csTmDate);
	sprintf(csTmTime,"%.*s",PD_TIME_LEN,&csLocalTxnDateTime[PD_DATE_LEN]);
	PutField_CString(hTxn,"local_tm_time",csTmTime);
	PutField_CString(hTxn,"tm_time",csTmTime);

DEBUGLOG(("CreateNewTxn TxnId = [%s]\n",csChargeTxnSeq));
	if(iRet==PD_OK){
		ChannelObjPtr = CreateObj(ChannelPtr,"OMTChannel","AddTxnLog");
		iRet = (unsigned long)(*ChannelObjPtr)(hTxn,hTxn);
DEBUGLOG(("CreateNewTxn iRet [%d]\n",iRet));
	}

	if (iRet == PD_OK) {
DEBUGLOG(("CreateNewTxn:: ready to do update balance\n"));
		//do update balance
		PutField_CString(hTxn,"psp_id",cs_psp_id);
		if (GetField_CString(hRls,"baid",&csTmp)) {
			PutField_CString(hTxn,"baid",csTmp);
		}
		if(GetField_CString(hRls,"amt_type",&csAmtType)) {
			if(!strcmp(csAmtType,PD_CR))
				cTmp = PD_IND_CREDIT;
			else
				cTmp = PD_IND_DEBIT;
			PutField_Char(hTxn,"amt_type",cTmp);
		}
		PutField_CString(hTxn,"pool",PD_ACCT_BAL_POOL);
		BOObjPtr = CreateObj(BOPtr, "BOOLBalance", "UpdateAmount");
		iRet = (unsigned long)(*BOObjPtr)(hTxn);
DEBUGLOG(("CreateNewTxn:: call BOOLBalance:UpdateAmount iRet=[%d]\n",iRet));
	}

	if (iRet == PD_OK) {
		//Get BAID info
		hash_init(hRec,0);
DEBUGLOG(("CreateNewTxn:: ready to add+update ol_txn_psp_detail\n"));
		if (GetField_CString(hRls,"baid",&csTmp)) {
DEBUGLOG(("CreateNewTxn:: call DBOLBankAcctId:GetBankAcctIdDtl\n"));
			DBObjPtr = CreateObj(DBPtr, "DBOLBankAcctId","GetBankAcctIdDtl");
			iRet = (unsigned long)(*DBObjPtr)(csTmp,hRec);
			if (iRet == PD_OK) {
				if (GetField_CString(hRec,"int_bank_code",&csTmp)) {
					PutField_CString(hTxn,"bank_code",csTmp);
				}
				if (GetField_CString(hRec,"bank_acct_num",&csTmp)) {
					PutField_CString(hTxn,"bank_acct_num",csTmp);
				}
			}
		}

		//add+update ol_txn_psp_detail
		PutField_Double(hTxn,"txn_amount",dAmt);
		PutField_CString(hTxn,"add_user",PD_UPDATE_USER);
		PutField_CString(hTxn,"update_user",PD_UPDATE_USER);
		PutField_CString(hDtl,"update_user",PD_UPDATE_USER);
		PutField_CString(hTxn,"txn_date",csTmDate);
		PutField_CString(hTxn,"txn_time",csTmTime);
		DBObjPtr = CreateObj(DBPtr, "DBOLTxnPspDetail", "Add");
		iRet = (unsigned long)(*DBObjPtr)(hTxn);
		if(iRet==PD_OK){
			DBObjPtr = CreateObj(DBPtr, "DBOLTxnPspDetail", "Update");
			iRet = (unsigned long)(*DBObjPtr)(hTxn);
		}
DEBUGLOG(("CreateNewTxn:: call DBOLTxnPspDetail:Add/Update iRet=[%d]\n",iRet));
	}

	if (iRet == PD_OK) {
DEBUGLOG(("CreateNewTxn:: ready to update ol_txn_elements\n"));
		//update ol_txn_elements
		PutField_CString(hTxn,"txn_element_type",PD_ELEMENT_TXN_AMT);
		PutField_CString(hTxn,"amount_type",csAmtType);
		BOObjPtr = CreateObj(BOPtr,"BOOLTxnElements","AddPspTxnElement");
		iRet = (unsigned long)(*BOObjPtr)(hTxn);
DEBUGLOG(("CreateNewTxn:: call DBOLTxnElements:AddPspTxnElement iRet=[%d]\n",iRet));
	}

	if (iRet == PD_OK) {
DEBUGLOG(("CreateNewTxn:: ready to update txn_header\n"));
		//update txn_header
		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "Update");
		if((unsigned long)(*DBObjPtr)(hTxn)!=PD_OK){
			iRet = FAILURE;
DEBUGLOG(("CreateNewTxn:: update header failed\n"));
		}
	}

	if (iRet == PD_OK) {
DEBUGLOG(("CreateNewTxn:: ready to update txn_detail\n"));
		//update txn_detail
		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "UpdateDetail");
		if((unsigned long)(*DBObjPtr)(hDtl)!=PD_OK){
			iRet = FAILURE;
DEBUGLOG(("CreateNewTxn:: update detail failed\n"));
ERRLOG("processing_costs_daily CreateNewTxn:: update detail failed\n");
		}
	}

	FREE_ME(hTxn);
	FREE_ME(hDtl);

	return iRet;
}


int UpdateTxnPspDetail(const char* csOrgTxnSeq, const char* csChargeTxnSeq) {
	int iRet = SUCCESS;

DEBUGLOG(("UpdateTxnPspDetail orgTxnSeq = [%s], newTxnSeq = [%s]\n", csOrgTxnSeq, csChargeTxnSeq));

	hash_t  *hRls;

	hRls = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRls, 0);

	PutField_CString(hRls,"txn_seq",csOrgTxnSeq);
	PutField_CString(hRls,"charge_txn_id",csChargeTxnSeq);
	PutField_Int(hRls,"charge_txn_created",1);
	PutField_CString(hRls,"update_user",PD_UPDATE_USER);

	DBObjPtr = CreateObj(DBPtr,"DBOLTxnPspDetail","Update");
	if ((unsigned long)(*DBObjPtr)(hRls) == PD_OK) {
DEBUGLOG(("update ol_txn_psp_detail success\n"));
	} else {
		iRet = FAILURE;
DEBUGLOG(("update ol_txn_psp_detail fail\n"));
ERRLOG("processing_costs_daily update ol_txn_psp_detail fail\n");
	}

	FREE_ME(hRls);

	return iRet;
}

