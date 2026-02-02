
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
    "get_ol_sett_email_body.pc"
};


static unsigned int sqlctx = 1804940157;


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
5,0,0,1,884,0,4,208,0,0,12,1,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/08/08              Virginia Yun
Update                                             2014/11/19              Elvis Wong
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
#include "dates.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

int 	iDynCnt=0;
char 	csTmp[PD_TMP_BUF_LEN+1];

char	cs_txn_seq[PD_TXN_SEQ_LEN + 1];
char    cs_merchant_id[PD_MERCHANT_ID_LEN + 1];
char    cs_funct[PD_CODE_LEN +1];
char    c_sett_type;
char    cs_sett_service[PD_SERVICE_CODE_LEN +1];
char    i_send_notify_email;

char    cDebug = 'Y';

OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);

int parse_arg(int argc,char **argv);
int process_get_ol_sett_data(hash_t* hRec, const char *csTxnSeq);
int process_get_exclude_data(hash_t* hRec, const char* csTxnSeq, const char* csFunct, const char* csSettService, int iSendNotifyEmail);

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}

int batch_proc(int argc, char* argv[])
{
        int     iRet = SUCCESS;

	hash_t *hRec = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hRec, 0);

	iRet = parse_arg(argc,argv);

        if (iRet != SUCCESS) {
		printf("usage:  -t txn_id -m merchant_id -f funct -s sett_type -c sett_service -e send_notify_email\n");
                return (iRet);
        }

	if(iRet == PD_OK){	
		iRet = process_get_exclude_data(hRec, cs_txn_seq, cs_funct, cs_sett_service, i_send_notify_email);
	}

	if(iRet == PD_OK){
		iRet = process_get_ol_sett_data(hRec, cs_txn_seq);
	}

	if(iRet == FOUND){

/* source */
                PutField_CString(hRec, "source", PD_EML_SOURCE_CHANNEL);
DEBUGLOG(("batch_proc:: source = [%s]\n", PD_EML_SOURCE_CHANNEL));

/* funct */
		PutField_CString(hRec, "funct", cs_funct);
DEBUGLOG(("batch_proc:: funct = [%s]\n", cs_funct));

/* party_id */
		PutField_CString(hRec, "party_id", cs_merchant_id);
DEBUGLOG(("batch_proc:: party_id = [%s]\n", cs_merchant_id));		

/* party_type */
		PutField_Char(hRec, "party_type", c_sett_type);
DEBUGLOG(("batch_proc:: party_type = [%c]\n", c_sett_type));		

		BOObjPtr = CreateObj(BOPtr,"BOAlertEmail","ProcessTpl");
               	if((unsigned long)((*BOObjPtr)(hRec) != PD_OK)){
             		iRet = FAILURE;
DEBUGLOG(("batch_proc:: BOAlertEmail Failed!!!\n"));
ERRLOG("get_ol_sett_email_body::batch_proc::BOAlertEmail Failed, iRet=%d\n", iRet);
             	} else {
			iRet = SUCCESS;
DEBUGLOG(("batch_proc:: BOAlertEmail Success!!!\n"));
                }
	}

	if (iRet != PD_OK) {
		iRet = FAILURE;
	}

	hash_destroy(hRec);
        FREE_ME(hRec);

	return iRet;
}

int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

int parse_arg(int argc,char **argv)
{
	char    c;

	strcpy(cs_txn_seq,"");
	strcpy(cs_merchant_id,"");
	strcpy(cs_funct,"");
	c_sett_type = ' ';
	strcpy(cs_sett_service,"");
	i_send_notify_email = 0;

	while ((c = getopt(argc,argv,"t:m:f:s:c:e:")) != EOF) {
		switch (c) {
			case 't':
				strcpy(cs_txn_seq, optarg);
				break;
			case 'm':
				strcpy(cs_merchant_id, optarg);
				break;
			case 'f':
				strcpy(cs_funct, optarg);
				break;
			case 's':
				c_sett_type = optarg[0];
                                break;
			case 'c':
                                strcpy(cs_sett_service, optarg);
                                break;
			case 'e':
				i_send_notify_email = atoi(optarg);
                                break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(cs_txn_seq, "") || !strcmp(cs_merchant_id,"") || !strcmp(cs_funct,"") || c_sett_type==' ' || !strcmp(cs_sett_service,""))
		return FAILURE;

	return SUCCESS;
}

int process_get_ol_sett_data(hash_t* hRec, const char* csTxnSeq)
{
        int iRet = FOUND;

        /* EXEC SQL WHENEVER SQLERROR GOTO processemail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_txn_seq[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_seq;


                /* varchar v_brand_name[PD_EML_FIELD_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_brand_name;

                /* varchar v_merchant_id[PD_EML_FIELD_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_id;

                /* varchar v_short_name[PD_EML_FIELD_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_short_name;

                /* varchar v_request_datetime[PD_EML_FIELD_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_request_datetime;

                /* varchar v_approve_datetime[PD_EML_FIELD_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_approve_datetime;

                /* varchar v_country_name[PD_EML_FIELD_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_country_name;

                /* varchar v_service_desc[PD_EML_FIELD_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_service_desc;

                /* varchar v_request_ccy[PD_EML_FIELD_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_request_ccy;

                /* varchar v_request_amt[PD_EML_FIELD_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_request_amt;

                /* varchar v_deliver_ccy[PD_EML_FIELD_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_deliver_ccy;

                /* varchar v_deliver_amt[PD_EML_FIELD_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_deliver_amt;


                short   ind_brand_name = -1;
                short   ind_merchant_id = -1;
                short   ind_short_name = -1;
                short   ind_request_datetime = -1;
                short   ind_approve_datetime = -1;
                short   ind_country_name = -1;
                short   ind_service_desc = -1;
                short   ind_request_ccy = -1;
                short   ind_request_amt = -1;
                short   ind_deliver_ccy = -1;
                short   ind_deliver_amt = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


// txn_seq
        hv_txn_seq.len = strlen(csTxnSeq);
        memcpy(hv_txn_seq.arr,csTxnSeq,hv_txn_seq.len);
DEBUGLOG(("process_get_ol_sett_data txn_seq = [%.*s]\n",hv_txn_seq.len,hv_txn_seq.arr));

	sprintf(csTmp,"%.*s",hv_txn_seq.len,hv_txn_seq.arr);
        iDynCnt = set_tpl_dyn_cstring(hRec,iDynCnt,"TXN_ID","GLO","STR",csTmp);

        /* EXEC SQL
                SELECT  NVL(MD_BRAND_NAME, 'OPTIMAL PAYMENTS PH-OFFLINE SYSTEM'),
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
                INTO    :v_brand_name:ind_brand_name,
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
                FROM    COUNTRY,
                        DEF_SERVICE_CODE,
                        OL_MERCH_DETAIL,
                        OL_MERCHANT_SETTLEMENT_DETAIL,
                        OL_TXN_HEADER
                WHERE   OTH_TXN_ID = :hv_txn_seq
                AND     OTH_TXN_CODE = 'OSR'
                AND     OTH_STATUS = 'C'
                AND     OTH_AR_IND = 'A'
                AND     OTH_TXN_ID = OSD_TXN_ID
                AND     OTH_MERCHANT_ID = OSD_MERCHANT_ID
                AND     OSD_MERCHANT_ID = MD_MERCHANT_ID
                AND     OSD_COUNTRY_ID = COUNTRY_CODE
                AND     OSD_SERVICE_CODE = SC_CODE; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select NVL ( MD_BRAND_NAME , 'OPTIMAL PAYMENTS PH-OF\
FLINE SYSTEM' ) , OSD_MERCHANT_ID , MD_SHORT_NAME , TO_CHAR ( OTH_CREATE_TIME\
STAMP , 'YYYY-MM-DD HH24:MI:SS' ) , TO_CHAR ( OTH_APPROVAL_TIMESTAMP , 'YYYY-\
MM-DD HH24:MI:SS' ) , COUNTRY_NAME , SC_DESC , OSD_REQUEST_CCY , TO_CHAR ( NV\
L ( OSD_REQUEST_AMT , 0 ) , 'FM999,999,990.00' ) , OSD_DELIVER_CCY , TO_CHAR \
( NVL ( OSD_DELIVER_AMT , 0 ) , 'FM999,999,990.00' ) INTO :b0:b1 , :b2:b3 , :\
b4:b5 , :b6:b7 , :b8:b9 , :b10:b11 , :b12:b13 , :b14:b15 , :b16:b17 , :b18:b1\
9 , :b20:b21 FROM COUNTRY , DEF_SERVICE_CODE , OL_MERCH_DETAIL , OL_MERCHANT_\
SETTLEMENT_DETAIL , OL_TXN_HEADER WHERE OTH_TXN_ID = :b22 AND OTH_TXN_CODE = \
'OSR' AND OTH_STATUS = 'C' AND OTH_AR_IND = 'A' AND OTH_TXN_ID = OSD_TXN_ID A\
ND OTH_MERCHANT_ID = OSD_MERCHANT_ID AND OSD_MERCHANT_ID = MD_MERCHANT_ID AND\
 OSD_COUNTRY_ID = COUNTRY_CODE AND OSD_SERVICE_CODE = SC_CODE ";
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
DEBUGLOG(("process_get_ol_sett_data brand_name = [%s]\n",v_brand_name.arr));

		//PutField_CString(hRec, "brand_name", (char*)v_brand_name.arr);

		sprintf(csTmp,"%.*s",v_brand_name.len,v_brand_name.arr);
		iDynCnt = set_tpl_dyn_cstring(hRec,iDynCnt,"BRAND_NAME","GLO","STR",csTmp);
        }

// merchant_id
        if (ind_merchant_id >= 0) {
                v_merchant_id.arr[v_merchant_id.len] ='\0';
DEBUGLOG(("process_get_ol_sett_data merchant_id = [%s]\n",v_merchant_id.arr));

		//PutField_CString(hRec, "merchant_id", (char*)v_merchant_id.arr);

		sprintf(csTmp,"%.*s",v_merchant_id.len,v_merchant_id.arr);
                iDynCnt = set_tpl_dyn_cstring(hRec,iDynCnt,"MERCHANT_ID","GLO","STR",csTmp);
        }

// short_name
        if (ind_short_name >= 0) {
                v_short_name.arr[v_short_name.len] ='\0';
DEBUGLOG(("process_get_ol_sett_data short_name = [%s]\n",v_short_name.arr));

		//PutField_CString(hRec, "short_name", (char*)v_short_name.arr);

		sprintf(csTmp,"%.*s",v_short_name.len,v_short_name.arr);
                iDynCnt = set_tpl_dyn_cstring(hRec,iDynCnt,"SHORT_NAME","GLO","STR",csTmp);
        }

// request_datetime
        if (ind_request_datetime >= 0) {
                v_request_datetime.arr[v_request_datetime.len] ='\0';
DEBUGLOG(("process_get_ol_sett_data request_datetime = [%s]\n",v_request_datetime.arr));

		//PutField_CString(hRec, "request_date_time", (char*)v_request_datetime.arr);

		sprintf(csTmp,"%.*s",v_request_datetime.len,v_request_datetime.arr);
		iDynCnt = set_tpl_dyn_cstring(hRec,iDynCnt,"REQUEST_DATE_TIME","GLO","STR",csTmp);
        }

// approve_datetime
        if (ind_approve_datetime >= 0) {
                v_approve_datetime.arr[v_approve_datetime.len] ='\0';
DEBUGLOG(("process_get_ol_sett_data approve_datetime = [%s]\n",v_approve_datetime.arr));

		//PutField_CString(hRec, "approve_date_time", (char*)v_approve_datetime.arr);
		
		sprintf(csTmp,"%.*s",v_approve_datetime.len,v_approve_datetime.arr);
                iDynCnt = set_tpl_dyn_cstring(hRec,iDynCnt,"APPROVE_DATE_TIME","GLO","STR",csTmp);
        }

// country_name
        if (ind_country_name >= 0) {
                v_country_name.arr[v_country_name.len] ='\0';
DEBUGLOG(("process_get_ol_sett_data country_name = [%s]\n",v_country_name.arr));

		//PutField_CString(hRec, "country_name", (char*)v_country_name.arr);

		sprintf(csTmp,"%.*s",v_country_name.len,v_country_name.arr);
                iDynCnt = set_tpl_dyn_cstring(hRec,iDynCnt,"COUNTRY_NAME","GLO","STR",csTmp);
        }

// service_desc
        if (ind_service_desc >= 0) {
                v_service_desc.arr[v_service_desc.len] ='\0';
DEBUGLOG(("process_get_ol_sett_data service_desc = [%s]\n",v_service_desc.arr));

		//PutField_CString(hRec, "service_desc", (char*)v_service_desc.arr);

		sprintf(csTmp,"%.*s",v_service_desc.len,v_service_desc.arr);
                iDynCnt = set_tpl_dyn_cstring(hRec,iDynCnt,"SERVICE_DESC","GLO","STR",csTmp);
        }

// request_ccy
        if (ind_request_ccy >= 0) {
                v_request_ccy.arr[v_request_ccy.len] ='\0';
DEBUGLOG(("process_get_ol_sett_data request_ccy = [%s]\n",v_request_ccy.arr));

		//PutField_CString(hRec, "request_ccy", (char*)v_request_ccy.arr);

		sprintf(csTmp,"%.*s",v_request_ccy.len,v_request_ccy.arr);
                iDynCnt = set_tpl_dyn_cstring(hRec,iDynCnt,"REQUEST_CCY","GLO","STR",csTmp);
        }

// request_amt
        if (ind_request_amt >= 0) {
                v_request_amt.arr[v_request_amt.len] ='\0';
DEBUGLOG(("process_get_ol_sett_data request_amt = [%f]\n",v_request_amt));

		//PutField_CString(hRec, "request_amt", (char*)v_request_amt.arr);

		sprintf(csTmp,"%.*s",v_request_amt.len,v_request_amt.arr);
                iDynCnt = set_tpl_dyn_cstring(hRec,iDynCnt,"REQUEST_AMT","GLO","STR",csTmp);
        }

// deliver_ccy
        if (ind_deliver_ccy >= 0) {
                v_deliver_ccy.arr[v_deliver_ccy.len] ='\0';
DEBUGLOG(("process_get_ol_sett_data deliver_ccy = [%s]\n",v_deliver_ccy.arr));

		//PutField_CString(hRec, "delivery_ccy", (char*)v_deliver_ccy.arr);

		sprintf(csTmp,"%.*s",v_deliver_ccy.len,v_deliver_ccy.arr);
                iDynCnt = set_tpl_dyn_cstring(hRec,iDynCnt,"DELIVER_CCY","GLO","STR",csTmp);
        }

// deliver_amt
        if (ind_deliver_amt >= 0) {
                v_deliver_amt.arr[v_deliver_amt.len] ='\0';
DEBUGLOG(("process_get_ol_sett_data deliver_amt = [%f]\n",v_deliver_amt));

		//PutField_CString(hRec, "delivery_amt", (char*)v_deliver_amt.arr);
		        
		sprintf(csTmp,"%.*s",v_deliver_amt.len,v_deliver_amt.arr);
                iDynCnt = set_tpl_dyn_cstring(hRec,iDynCnt,"DELIVER_AMT","GLO","STR",csTmp);
	}

	PutField_Int(hRec, "total_dyn", iDynCnt);
DEBUGLOG(("process_get_ol_sett_data total_dyn = [%d]\n",iDynCnt));

DEBUGLOG(("process_get_ol_sett_data() Normal Exit iRet = [%d]\n",iRet));
        return iRet;

processemail_error:
DEBUGLOG(("processemail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("get_ol_sett_email_body::process_get_ol_sett_data sql error %d\n", sqlca.sqlcode);
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int process_get_exclude_data(hash_t* hRec, const char* csTxnSeq, const char* csFunct, const char* csSettService, int iSendNotifyEmail)
{
	int iRet = PD_OK;

	int iSendMerchantNotifyEmail = 0;

	hash_t *hRecExclude;

	recordset_t *rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet, 0);	

DEBUGLOG(("process_get_exclude_data:: csTxnSeq = [%s]\n", csTxnSeq));
DEBUGLOG(("process_get_exclude_data:: csFunct = [%s]\n", csFunct));

/* service_code */
      	PutField_CString(hRec,"service_code",csSettService);
DEBUGLOG(("process_get_exclude_data:: service_code = [%s]\n",csSettService));

      	if (!strcmp(csFunct, PD_EML_FUNCT_OL_SETT_ADMIN))
      	{
/* notify_email */
       		PutField_Int(hRec,"notify_email",iSendNotifyEmail);
DEBUGLOG(("process_get_exclude_data:: notify_email = [%d]\n",iSendNotifyEmail));
      	}
     	else if (!strcmp(csFunct, PD_EML_FUNCT_OL_SETT_MERCH))
     	{
DEBUGLOG(("process_get_exclude_data:: Call DBOLMerchantSettlementDetail:: GetSettlementDetail\n"));

              	DBObjPtr = CreateObj(DBPtr,"DBOLMerchantSettlementDetail","GetSettlementDetail");
             	if((unsigned long)(*DBObjPtr)(csTxnSeq,rRecordSet)==PD_OK) {
DEBUGLOG(("process_get_exclude_data:: found record!!!\n"));
                   	hRecExclude = RecordSet_GetFirst(rRecordSet);
                     	while (hRecExclude) {

/* merchant_notify_email */
                      		if (GetField_Int(hRecExclude, "merchant_notify_email", &iSendMerchantNotifyEmail)) {
DEBUGLOG(("process_get_exclude_data:: merchant_notify_email = [%d]\n",iSendMerchantNotifyEmail));
                                  	PutField_Int(hRec,"merchant_notify_email",iSendMerchantNotifyEmail);
                            	}

                             	hRecExclude = RecordSet_GetNext(rRecordSet);
                   	}
           	} else {
DEBUGLOG(("process_get_exclude_data:: GetSettlementDetail:: not found record!!!\n"));
ERRLOG("get_ol_sett_email_body::process_get_exclude_data::GetSettlementRecords::GetSettlementDetail::not found record!!\n");
           	}
   	}

	RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);

DEBUGLOG(("process_get_exclude_data:: iRet = [%d]\n", iRet));
	return iRet;
}
