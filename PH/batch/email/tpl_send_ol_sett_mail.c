
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
           char  filnam[25];
};
static struct sqlcxp sqlfpn =
{
    24,
    "tpl_send_ol_sett_mail.pc"
};


static unsigned int sqlctx = 1381215083;


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
   unsigned char  *sqhstv[12];
   unsigned long  sqhstl[12];
            int   sqhsts[12];
            short *sqindv[12];
            int   sqinds[12];
   unsigned long  sqharm[12];
   unsigned long  *sqharc[12];
   unsigned short  sqadto[12];
   unsigned short  sqtdso[12];
} sqlstm = {12,12};

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
5,0,0,1,884,0,4,196,0,0,12,1,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/08/08              Virginia Yun
Update                                             2014/11/06              Stan Poon
*/

#include <sqlca.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "batchcommon.h"
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "myhash.h"
#include "myrecordset.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char	cs_txn_seq[PD_TXN_SEQ_LEN + 1];
char	cs_funct[PD_EML_FUNCT_LEN + 1];
char	c_party_type;
char	cs_party_id[PD_EML_PARTY_ID_LEN + 1];
char	c_send_mail;

OBJPTR(BO);

char	cDebug = 'Y';

int parse_arg(int argc, char **argv);
int process_ol_sett_data(tpl_t* tpl, const char* csTxnSeq);

int batch_init(int argc, char* argv[])
{
	int iRet = SUCCESS;

	iRet = parse_arg(argc, argv);

	return iRet;
}

int batch_proc(int argc, char* argv[])
{
	int iRet = SUCCESS, iDtlRet = SUCCESS;

	hash_t *hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec, 0);

	PutField_CString(hRec, "funct", cs_funct);
	PutField_Char(hRec, "party_type", c_party_type);
	PutField_CString(hRec, "party_id", cs_party_id);
	PutField_Char(hRec, "send_mail", c_send_mail);

	//
	//PutField_CString(hRec, "mail_to", "stan.poon@asiapsp.com");

	tpl_t *tpl = tpl_alloc();

	BOObjPtr = CreateObj(BOPtr,"BOAlertEmail","PrepareTemplate");
	if ((unsigned long)(*BOObjPtr)(hRec, tpl) != PD_OK) {
		iRet = FAILURE;
DEBUGLOG(("BOAlertEmail::PrepareTemplate() FAILURE!!!\n"));
	}


	iDtlRet = process_ol_sett_data(tpl, cs_txn_seq);
	if (iDtlRet == FOUND) {
DEBUGLOG(("process_ol_sett_data() FOUND\n"));

	} else if (iDtlRet == NOT_FOUND) {
DEBUGLOG(("process_ol_sett_data() NOT FOUND\n"));

	} else {
		iRet = FAILURE;
DEBUGLOG(("process_ol_sett_data() FAILURE!!!\n"));
	}


	BOObjPtr = CreateObj(BOPtr,"BOAlertEmail","SendEmailTpl");
	if ((unsigned long)(*BOObjPtr)(hRec, tpl) != PD_OK) {
		iRet = FAILURE;
DEBUGLOG(("BOALertEmail::SendEmailTpl() FAILURE!!!\n"));
	}

	tpl_free(tpl);

	hash_destroy(hRec);
	FREE_ME(hRec);

DEBUGLOG(("Ret = [%d]\n", iRet));

	return iRet;
}

int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

int parse_arg(int argc, char **argv)
{
	int	iRet = SUCCESS;
	char	c;

	cs_txn_seq[0] = '\0';
	cs_funct[0] = '\0';
	c_party_type = ' ';
	cs_party_id[0] = '\0';
	c_send_mail = 'N';

	while ((c = getopt(argc,argv,"t:f:M:C:G:T:S:")) != EOF) {
		switch (c) {
			case 't':
				strcpy(cs_txn_seq, optarg);
				break;
			case 'f':
				strcpy(cs_funct, optarg);
				break;
			case 'M':
			case 'C':
			case 'G':
			case 'T':
				c_party_type = c;
				strcpy(cs_party_id, optarg);
				break;
			case 'S':
				c_send_mail = optarg[0];
				break;
			default:
				iRet = FAILURE;
				break;
		}
	}

	if (cs_txn_seq[0] == '\0') iRet = FAILURE;
	if (cs_funct[0] == '\0') iRet = FAILURE;

	if (c_send_mail == 'Y' && cs_party_id[0] == '\0') iRet = FAILURE;

	if (iRet != SUCCESS) {
printf("usage:  -t <txn_id>  -f <funct>\n");
printf("        -M/-C/-G <party_id>  -S <send[Y]>\n");
	}

	return iRet;
}

int process_ol_sett_data(tpl_t* tpl, const char* csTxnSeq)
{
	int iRet = FOUND;

	/* EXEC SQL WHENEVER SQLERROR GOTO processemail_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_txn_seq[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_seq;


		/* varchar	v_brand_name[PD_EML_FIELD_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_brand_name;

		/* varchar	v_merchant_id[PD_EML_FIELD_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_id;

		/* varchar	v_short_name[PD_EML_FIELD_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_short_name;

		/* varchar	v_request_datetime[PD_EML_FIELD_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_request_datetime;

		/* varchar	v_approve_datetime[PD_EML_FIELD_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_approve_datetime;

		/* varchar	v_country_name[PD_EML_FIELD_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_country_name;

		/* varchar	v_service_desc[PD_EML_FIELD_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_service_desc;

		/* varchar	v_request_ccy[PD_EML_FIELD_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_request_ccy;

		/* varchar	v_request_amt[PD_EML_FIELD_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_request_amt;

		/* varchar	v_deliver_ccy[PD_EML_FIELD_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_deliver_ccy;

		/* varchar	v_deliver_amt[PD_EML_FIELD_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_deliver_amt;


		short	ind_brand_name = -1;
		short	ind_merchant_id = -1;
		short	ind_short_name = -1;
		short	ind_request_datetime = -1;
		short	ind_approve_datetime = -1;
		short	ind_country_name = -1;
		short	ind_service_desc = -1;
		short	ind_request_ccy = -1;
		short	ind_request_amt = -1;
		short	ind_deliver_ccy = -1;
		short	ind_deliver_amt = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


// txn_seq
	hv_txn_seq.len = strlen(csTxnSeq);
	memcpy(hv_txn_seq.arr,csTxnSeq,hv_txn_seq.len);
DEBUGLOG(("process_ol_sett_data txn_seq = [%.*s]\n",hv_txn_seq.len,hv_txn_seq.arr));

	tpl_set_field_fmt_global(tpl,"TXN_ID","%s",csTxnSeq);

	/* EXEC SQL
		SELECT	NVL(MD_BRAND_NAME, 'OPTIMAL PAYMENTS PH-OFFLINE SYSTEM'),
			OSD_MERCHANT_ID,
			MD_SHORT_NAME,
			TO_CHAR(OTH_CREATE_TIMESTAMP, 'YYYY-MM-DD HH24:MI:SS'),
			TO_CHAR(OTH_APPROVAL_TIMESTAMP, 'YYYY-MM-DD HH24:MI:SS'),
			COUNTRY_NAME,
			SC_DESC,
			OSD_REQUEST_CCY,
			TO_CHAR(NVL(OSD_REQUEST_AMT, 0), 'FM999,999,990.00'),
			OSD_DELIVER_CCY,
			TO_CHAR(NVL(OSD_DELIVER_AMT, 0), 'FM999,999,990.00')
		INTO	:v_brand_name:ind_brand_name,
			:v_merchant_id:ind_merchant_id,
			:v_short_name:ind_short_name,
			:v_request_datetime:ind_request_datetime,
			:v_approve_datetime:ind_approve_datetime,
			:v_country_name:ind_country_name,
			:v_service_desc:ind_service_desc,
			:v_request_ccy:ind_request_ccy,
			:v_request_amt:ind_request_amt,
			:v_deliver_ccy:ind_deliver_ccy,
			:v_deliver_amt:ind_deliver_amt
		FROM	COUNTRY,
			DEF_SERVICE_CODE,
			OL_MERCH_DETAIL,
			OL_MERCHANT_SETTLEMENT_DETAIL,
			OL_TXN_HEADER
		WHERE	OTH_TXN_ID = :hv_txn_seq
		AND	OTH_TXN_CODE = 'OSR'
		AND	OTH_STATUS = 'C'
		AND	OTH_AR_IND = 'A'
		AND	OTH_TXN_ID = OSD_TXN_ID
		AND	OTH_MERCHANT_ID = OSD_MERCHANT_ID
		AND	OSD_MERCHANT_ID = MD_MERCHANT_ID
		AND	OSD_COUNTRY_ID = COUNTRY_CODE
		AND	OSD_SERVICE_CODE = SC_CODE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select NVL ( MD_BRAND_NAME , 'OPTIMAL PAYMENTS PH-OFFLINE S\
YSTEM' ) , OSD_MERCHANT_ID , MD_SHORT_NAME , TO_CHAR ( OTH_CREATE_TIMESTAMP ,\
 'YYYY-MM-DD HH24:MI:SS' ) , TO_CHAR ( OTH_APPROVAL_TIMESTAMP , 'YYYY-MM-DD H\
H24:MI:SS' ) , COUNTRY_NAME , SC_DESC , OSD_REQUEST_CCY , TO_CHAR ( NVL ( OSD\
_REQUEST_AMT , 0 ) , 'FM999,999,990.00' ) , OSD_DELIVER_CCY , TO_CHAR ( NVL (\
 OSD_DELIVER_AMT , 0 ) , 'FM999,999,990.00' ) INTO :b0:b1 , :b2:b3 , :b4:b5 ,\
 :b6:b7 , :b8:b9 , :b10:b11 , :b12:b13 , :b14:b15 , :b16:b17 , :b18:b19 , :b2\
0:b21 FROM COUNTRY , DEF_SERVICE_CODE , OL_MERCH_DETAIL , OL_MERCHANT_SETTLEM\
ENT_DETAIL , OL_TXN_HEADER WHERE OTH_TXN_ID = :b22 AND OTH_TXN_CODE = 'OSR' A\
ND OTH_STATUS = 'C' AND OTH_AR_IND = 'A' AND OTH_TXN_ID = OSD_TXN_ID AND OTH_\
MERCHANT_ID = OSD_MERCHANT_ID AND OSD_MERCHANT_ID = MD_MERCHANT_ID AND OSD_CO\
UNTRY_ID = COUNTRY_CODE AND OSD_SERVICE_CODE = SC_CODE ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_brand_name;
 sqlstm.sqhstl[0] = (unsigned long )53;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_brand_name;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )53;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_short_name;
 sqlstm.sqhstl[2] = (unsigned long )53;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_short_name;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&v_request_datetime;
 sqlstm.sqhstl[3] = (unsigned long )53;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_request_datetime;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&v_approve_datetime;
 sqlstm.sqhstl[4] = (unsigned long )53;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_approve_datetime;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&v_country_name;
 sqlstm.sqhstl[5] = (unsigned long )53;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_country_name;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&v_service_desc;
 sqlstm.sqhstl[6] = (unsigned long )53;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_service_desc;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&v_request_ccy;
 sqlstm.sqhstl[7] = (unsigned long )53;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_request_ccy;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&v_request_amt;
 sqlstm.sqhstl[8] = (unsigned long )53;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_request_amt;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&v_deliver_ccy;
 sqlstm.sqhstl[9] = (unsigned long )53;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_deliver_ccy;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&v_deliver_amt;
 sqlstm.sqhstl[10] = (unsigned long )53;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_deliver_amt;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_txn_seq;
 sqlstm.sqhstl[11] = (unsigned long )18;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto processemail_error;
}


	
// brand_name
	if (ind_brand_name >= 0) {
		v_brand_name.arr[v_brand_name.len] ='\0';
DEBUGLOG(("process_ol_sett_data brand_name = [%s]\n",v_brand_name.arr));

		tpl_set_field_fmt_global(tpl,"BRAND_NAME","%s",v_brand_name.arr);
	}

// merchant_id
	if (ind_merchant_id >= 0) {
		v_merchant_id.arr[v_merchant_id.len] ='\0';
DEBUGLOG(("process_ol_sett_data merchant_id = [%s]\n",v_merchant_id.arr));

		tpl_set_field_fmt_global(tpl,"MERCHANT_ID","%s",v_merchant_id.arr);
	}

// short_name
	if (ind_short_name >= 0) {
		v_short_name.arr[v_short_name.len] ='\0';
DEBUGLOG(("process_ol_sett_data short_name = [%s]\n",v_short_name.arr));

		tpl_set_field_fmt_global(tpl,"SHORT_NAME","%s",v_short_name.arr);
	}

// request_datetime
	if (ind_request_datetime >= 0) {
		v_request_datetime.arr[v_request_datetime.len] ='\0';
DEBUGLOG(("process_ol_sett_data request_datetime = [%s]\n",v_request_datetime.arr));

		tpl_set_field_fmt_global(tpl,"REQUEST_DATE_TIME","%s",v_request_datetime.arr);
	}

// approve_datetime
	if (ind_approve_datetime >= 0) {
		v_approve_datetime.arr[v_approve_datetime.len] ='\0';
DEBUGLOG(("process_ol_sett_data approve_datetime = [%s]\n",v_approve_datetime.arr));

		tpl_set_field_fmt_global(tpl,"APPROVE_DATE_TIME","%s",v_approve_datetime.arr);
	}

// country_name
	if (ind_country_name >= 0) {
		v_country_name.arr[v_country_name.len] ='\0';
DEBUGLOG(("process_ol_sett_data country_name = [%s]\n",v_country_name.arr));

		tpl_set_field_fmt_global(tpl,"COUNTRY_NAME","%s",v_country_name.arr);
	}

// service_desc
	if (ind_service_desc >= 0) {
		v_service_desc.arr[v_service_desc.len] ='\0';
DEBUGLOG(("process_ol_sett_data service_desc = [%s]\n",v_service_desc.arr));

		tpl_set_field_fmt_global(tpl,"SERVICE_DESC","%s",v_service_desc.arr);
	}

// request_ccy
	if (ind_request_ccy >= 0) {
		v_request_ccy.arr[v_request_ccy.len] ='\0';
DEBUGLOG(("process_ol_sett_data request_ccy = [%s]\n",v_request_ccy.arr));

		tpl_set_field_fmt_global(tpl,"REQUEST_CCY","%s",v_request_ccy.arr);
	}

// request_amt
	if (ind_request_amt >= 0) {
		v_request_amt.arr[v_request_amt.len] ='\0';
DEBUGLOG(("process_ol_sett_data request_amt = [%f]\n",v_request_amt));

		tpl_set_field_fmt_global(tpl,"REQUEST_AMT","%s",v_request_amt.arr);
	}

// deliver_ccy
	if (ind_deliver_ccy >= 0) {
                v_deliver_ccy.arr[v_deliver_ccy.len] ='\0';
DEBUGLOG(("process_ol_sett_data deliver_ccy = [%s]\n",v_deliver_ccy.arr));

		tpl_set_field_fmt_global(tpl,"DELIVER_CCY","%s",v_deliver_ccy.arr);
	}

// deliver_amt
	if (ind_deliver_amt >= 0) {
                v_deliver_amt.arr[v_deliver_amt.len] ='\0';
DEBUGLOG(("process_ol_sett_data deliver_amt = [%f]\n",v_deliver_amt));

		tpl_set_field_fmt_global(tpl,"DELIVER_AMT","%s",v_deliver_amt.arr);
	}

DEBUGLOG(("process_ol_sett_data() Normal Exit iRet = [%d]\n",iRet));
	return iRet;

processemail_error:
DEBUGLOG(("processemail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

