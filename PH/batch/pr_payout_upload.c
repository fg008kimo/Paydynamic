
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
           char  filnam[20];
};
static struct sqlcxp sqlfpn =
{
    19,
    "pr_payout_upload.pc"
};


static unsigned int sqlctx = 43034539;


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
   unsigned char  *sqhstv[29];
   unsigned long  sqhstl[29];
            int   sqhsts[29];
            short *sqindv[29];
            int   sqinds[29];
   unsigned long  sqharm[29];
   unsigned long  *sqharc[29];
   unsigned short  sqadto[29];
   unsigned short  sqtdso[29];
} sqlstm = {12,29};

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
"select pmp_service ,pmp_ph_merch_id  from par_merch_profile where pmp_merch\
_account_nmb=:b0           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,81,0,4,280,0,0,1,0,0,1,0,2,9,0,0,
24,0,0,2,102,0,9,333,0,0,1,1,0,1,0,1,9,0,0,
43,0,0,2,0,0,13,335,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
66,0,0,2,0,0,15,363,0,0,0,0,0,1,0,
81,0,0,2,0,0,15,373,0,0,0,0,0,1,0,
96,0,0,3,369,0,6,483,0,0,11,11,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,4,0,0,1,3,0,0,
155,0,0,4,0,0,17,964,0,0,1,1,0,1,0,1,9,0,0,
174,0,0,4,0,0,21,965,0,0,0,0,0,1,0,
189,0,0,5,953,0,6,1267,0,0,29,29,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,4,0,0,1,9,
0,0,1,4,0,0,1,4,0,0,1,3,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/06/26              LokMan Chow
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include <math.h>
#include "utilitys.h"
#include "expat.h"
#include <curl/curl.h>
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"
#include "batchcommon.h"
#include "TxnSeq.h"
#include "pr_payout_upload.h"
#include "pr_bo_funct.h"
#include "internal.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug = 'Y';
char    cs_hdfile[PD_MAX_FILE_LEN + 1];
char    cs_dtfile[PD_MAX_FILE_LEN + 1];
char    cs_date[PD_DATE_LEN + 1];

int 	parse_arg(int argc,char **argv);
int     parse_header(FILE *fin,hash_t * hTxn);
int     process_header(hash_t *hTxn);
int     parse_detail(FILE *fin,hash_t * hTxn);
int     process_detail(hash_t *hTxn);
int	GenBatchId(char *csBatchId);
int	GetMerchantProfile(const char* csMerchAccNmb,hash_t *hTxn);
int     AddUploadHeader(const hash_t *hRls);
int 	UpdateUploadHeader(const hash_t *hRls);
int 	UpdateUploadDetail(const hash_t *hRls);
int     AddUploadDetail(const hash_t *hRls);
//char*	GetNextBatchTxnSeq();

int batch_init(int argc, char* argv[])
{
    if (argc < 3) {
        printf("usage:  -h header_file -t detail_file -d Date\n");
        return FAILURE;
    }
    else
        return SUCCESS;
}



int batch_proc(int argc, char* argv[])
{
        FILE    *fin;
        int     iRet;
	
	hash_t  *hTxn;
        hTxn = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTxn, 0);        

        iRet = parse_arg(argc,argv);

        if (iRet != SUCCESS){
		printf("usage:  -h header_file -t detail_file -d Date\n");
                return (iRet);
	}

        fin = fopen(cs_hdfile,"r");
        
        if (fin == NULL) {
DEBUGLOG(("Error Opening header file = [%s]\n",cs_hdfile));
                return FAILURE;
        }

        iRet = parse_header(fin,hTxn);
        fclose(fin);

	if (iRet != FAILURE)  {
        	fin = fopen(cs_dtfile,"r");
		
        	iRet = parse_detail(fin,hTxn);
        	fclose(fin);
	}

DEBUGLOG(("iRet = [%d]\n",iRet));

	FREE_ME(hTxn);
        return iRet;

}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

int	parse_header(FILE *fin,hash_t * hTxn) 
{
	int	iRet = SUCCESS;
	char	csList[IMPORT_MAX_FILE][IMPORT_FIELD_LEN];
	char    cs_input_buf[PD_MAX_BUFFER +1];;
	char    csTag[PD_TAG_LEN+1];
	char* p;
	int	iCount = 0;
	int	i= 0;
	int	iRecord = 0;

DEBUGLOG(("parse_header: Begin\n"));
	while( fgets(cs_input_buf, PD_MAX_BUFFER, fin) != NULL ){

		if ((cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A) || (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0D))
			cs_input_buf[strlen(cs_input_buf) - 1] = '\0';

		if(cs_input_buf[strlen(cs_input_buf) - 1] == 0x00)
			continue;

		i= 0;

		p = mystrtok(cs_input_buf,PD_MY_DELIMITOR);
                if (p != NULL){
                        strcpy(csList[i],p);
                        i++;

                        while ( (p = mystrtok(NULL,PD_MY_DELIMITOR)) != NULL) {
                                strcpy(csList[i],p);
                                i++;
                        }
                }
                else{
DEBUGLOG(("parse_header: Read Header Error\n"));
			iRet = FAILURE;
                        break;
                }

		iRecord++;
		PutField_Int(hTxn,"batch_count",iRecord);

		if(iRet==SUCCESS){
			for(iCount=0;iCount<i;iCount++){
				if(iCount==IDX_HEADER_REF_ID)
					sprintf(csTag,"ref_num_%d",iRecord);
				else if(iCount==IDX_HEADER_IMPORT_ERR)
					sprintf(csTag,"import_err_%d",iRecord);
				else if(iCount==IDX_HEADER_DATETIME)
					sprintf(csTag,"date_time_%d",iRecord);
				else if(iCount==IDX_HEADER_FILENAME)
					sprintf(csTag,"filename_%d",iRecord);
				else if(iCount==IDX_HEADER_FILEPREFIX)
					sprintf(csTag,"filename_prefix_%d",iRecord);
				else if(iCount==IDX_HEADER_TOTAL_COUNT)
					sprintf(csTag,"txn_count_%d",iRecord);
				else if(iCount==IDX_HEADER_TOTAL_AMT)
					sprintf(csTag,"total_txn_amt_%d",iRecord);
				else if(iCount==IDX_HEADER_STATUS)
					sprintf(csTag,"status_%d",iRecord);
				else if(iCount==IDX_HEADER_ACCT_NMB)
					sprintf(csTag,"acct_id_%d",iRecord);
				else
					sprintf(csTag,"not_care");

				PutField_CString(hTxn,csTag,csList[iCount]);
DEBUGLOG(("parse_header: Tag[%s]: [%s]\n",csTag,csList[iCount]));
			}

		}
	}

	iRet = process_header(hTxn);

	
	return iRet;
}

int	process_header(hash_t *hTxn)
{
	int	iRet = SUCCESS;
	int	iBatch = 0;
	int	i = 0;
	unsigned long   lBatchId = 0l;
	char    *csBatchId = strdup("");
	char    csTag[PD_TAG_LEN+1];
	char	*csTmp;
	double	dTmp=0.0;

	GetField_Int(hTxn,"batch_count",&iBatch);

	for(i=1;i<=iBatch;i++){
		if(GenBatchId(csBatchId)!= PD_OK){
DEBUGLOG(("process_header::GenBatchId Failed\n"));
ERRLOG("pr_payout_upload::process_header::GenBatchId Failed\n");
			iRet = FAILURE;
			break;
		}
		else {
DEBUGLOG(("process_header::GenBatchId batch_id = [%s]\n", csBatchId));
			PutField_CString(hTxn, "batch_id", csBatchId);
			lBatchId = ctol((const unsigned char *)csBatchId,strlen(csBatchId));
			sprintf(csTag,"ref_num_%d",i);
			GetField_CString(hTxn,csTag,&csTmp);
			//PutField_CString(hTxn,"vnc_ref_num",csTmp);
			sprintf(csTag,"%s_batch_id",csTmp);
			PutField_CString(hTxn,csTag,csBatchId);
			sprintf(csTag,"batch_id_%d",i);
			PutField_CString(hTxn,csTag,csBatchId);
DEBUGLOG(("process_header::GenBatchId batch_id = [%ld]\n", lBatchId));
		}

		sprintf(csTag,"acct_id_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			if(GetMerchantProfile(csTmp,hTxn)!=PD_OK){
DEBUGLOG(("process_header::GetMerchantProfile Failed\n"));
ERRLOG("pr_payout_upload::process_header::GetMerchantProfile Failed\n");
				iRet = FAILURE;
				break;
			}
		}

		sprintf(csTag,"filename_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			PutField_CString(hTxn,"filename",csTmp);
		}
		sprintf(csTag,"filename_prefix_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			PutField_CString(hTxn,"filename_prefix",csTmp);
		}
		sprintf(csTag,"txn_count_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			PutField_Int(hTxn,"txn_count",atoi(csTmp));
		}
		sprintf(csTag,"total_txn_amt_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			if(sscanf(csTmp,"%lf",&dTmp)==1)
				PutField_Double(hTxn,"txn_amt",dTmp);
		}
		sprintf(csTag,"status_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			PutField_Int(hTxn,"status",atoi(csTmp));
		}

		PutField_CString(hTxn,"posting_date",cs_date);

		if(AddUploadHeader(hTxn)!=PD_OK){
			iRet = FAILURE;
			break;
		}

	}


	FREE_ME(csBatchId);
	return iRet;
}


int GenBatchId(char *csBatchId)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO gen_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar v_batch_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_batch_id;

                short   ind_batch_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        /* EXEC SQL SELECT NVL(max(uh_batch_id), 0) + 1
                   INTO :v_batch_id:ind_batch_id
                FROM merchant_upload_file_header; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select (NVL(max(uh_batch_id),0)+1) into :b0:b1  from\
 merchant_upload_file_header ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )5;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
        sqlstm.sqhstl[0] = (unsigned long )19;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_batch_id;
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
        if (sqlca.sqlcode < 0) goto gen_error;
}



        if (ind_batch_id >= 0) {
                v_batch_id.arr[v_batch_id.len] = '\0';
                strcpy((char*)csBatchId,(const char*)v_batch_id.arr);

DEBUGLOG(("GenBatchId batch_id = [%s]\n", csBatchId));
                return PD_OK;
        }

DEBUGLOG(("GenBatchId NOT SUCC\n"));
        return PD_ERR;

gen_error:
DEBUGLOG(("gen_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}

int GetMerchantProfile(const char* csMerchAccNmb,
                hash_t *hTxn)
{
        int iRet = PD_OK;

        /* EXEC SQL WHENEVER SQLERROR GOTO getmerchant_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merch_account_nmb[PD_MERCH_ACCOUNT_NMB_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_merch_account_nmb;


                /* varchar         v_service[PD_SERVICE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service;

                /* varchar         v_ph_merch_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_ph_merch_id;


                short           ind_service = -1;
                short           ind_ph_merch_id = -1;


        /* EXEC SQL END DECLARE SECTION; */ 


        hv_merch_account_nmb.len = strlen(csMerchAccNmb);
        memcpy(hv_merch_account_nmb.arr,csMerchAccNmb,hv_merch_account_nmb.len);
DEBUGLOG(("GetMerchantProfile merch_account_nmb = [%.*s]\n",hv_merch_account_nmb.len,hv_merch_account_nmb.arr));

        /* EXEC SQL DECLARE c_cursor_getmerchant CURSOR FOR
                select 
                        pmp_service,
                        pmp_ph_merch_id
                  from par_merch_profile
                 where pmp_merch_account_nmb = :hv_merch_account_nmb; */ 


        /* EXEC SQL OPEN c_cursor_getmerchant; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0002;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )24;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_merch_account_nmb;
        sqlstm.sqhstl[0] = (unsigned long )52;
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
        if (sqlca.sqlcode < 0) goto getmerchant_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getmerchant
                INTO
                        :v_service:ind_service,
                        :v_ph_merch_id:ind_ph_merch_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 2;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )43;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_service;
                sqlstm.sqhstl[0] = (unsigned long )6;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_service;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_ph_merch_id;
                sqlstm.sqhstl[1] = (unsigned long )18;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_ph_merch_id;
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
                if (sqlca.sqlcode < 0) goto getmerchant_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        iRet = SQL_NOT_FOUND;
                        break;
                }

// service
                if (ind_service >= 0) {
                        v_service.arr[v_service.len] = '\0';
                        PutField_CString(hTxn,"service_code",(const char*)v_service.arr);
DEBUGLOG(("GetMerchantProfile service = [%s]\n",v_service.arr));
                }

// merchant_id
                if (ind_ph_merch_id >= 0) {
                        v_ph_merch_id.arr[v_ph_merch_id.len] = '\0';
                        PutField_CString(hTxn,"merchant_id",(const char*)v_ph_merch_id.arr);
DEBUGLOG(("GetMerchantProfile ph_merch_id = [%s]\n",v_ph_merch_id.arr));
                }

		break; //**************** only one now
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getmerchant; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )66;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getmerchant_error;
}



DEBUGLOG(("GetMerchantProfile Normal Exit\n"));
        if(iRet==0) return  PD_OK;
        else    return iRet;

getmerchant_error:
DEBUGLOG(("getmerchant_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getmerchant; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
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


        return PD_ERR;
}


int     AddUploadHeader(const hash_t *hRls)
{
        char            *csTmp;
        int             iTmp;
        double          dTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

                /* varchar         hv_filename[PD_FILENAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_filename;

                /* varchar         hv_filename_prefix[PD_FILENAME_PREFIX_LEN]; */ 
struct { unsigned short len; unsigned char arr[12]; } hv_filename_prefix;

                /* varchar         hv_posting_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_posting_date;

                int             hv_txn_count;
                double          hv_txn_amt;
                int             hv_status;

                short           ind_batch_id = -1;
                short           ind_txn_id = -1;
                short           ind_merchant_id = -1;
                short           ind_service_code = -1;
                short           ind_status = -1;
                short           ind_filename = -1;
                short           ind_filename_prefix = -1;
                short           ind_txn_count = -1;
                short           ind_txn_amt = -1;
                short           ind_posting_date = -1;

                short           hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("AddUploadHeader: Begin\n"));
/*batch_id*/
        if(GetField_CString(hRls,"batch_id",&csTmp)){
                hv_batch_id.len = strlen(csTmp);
                memcpy(hv_batch_id.arr, csTmp, hv_batch_id.len);
                ind_batch_id= 0;
DEBUGLOG(("Add:batch_id= [%.*s]\n",hv_batch_id.len,hv_batch_id.arr));
        }

/*merchant_id*/
        if(GetField_CString(hRls,"merchant_id",&csTmp)){
                hv_merchant_id.len = strlen(csTmp);
                memcpy(hv_merchant_id.arr, csTmp, hv_merchant_id.len);
                ind_merchant_id = 0;
DEBUGLOG(("Add:merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        }

/*service_code*/
        if(GetField_CString(hRls,"service_code",&csTmp)){
                hv_service_code.len = strlen(csTmp);
                memcpy(hv_service_code.arr, csTmp, hv_service_code.len);
                ind_service_code= 0;
DEBUGLOG(("Add:service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));
        }

/*filename*/
        if(GetField_CString(hRls,"filename",&csTmp)){
                hv_filename.len = strlen(csTmp);
                memcpy(hv_filename.arr, csTmp, hv_filename.len);
                ind_filename= 0;
DEBUGLOG(("Add:filename = [%.*s]\n",hv_filename.len,hv_filename.arr));
        }

/*filename_prefix*/
        if(GetField_CString(hRls,"filename_prefix",&csTmp)){
                hv_filename_prefix.len = strlen(csTmp);
                memcpy(hv_filename_prefix.arr, csTmp, hv_filename_prefix.len);
                ind_filename_prefix= 0;
DEBUGLOG(("Add:filename_prefix = [%.*s]\n",hv_filename_prefix.len,hv_filename_prefix.arr));
        }

/*posting_date*/
        if(GetField_CString(hRls,"posting_date",&csTmp)){
                hv_posting_date.len = PD_DATE_LEN;
                memcpy(hv_posting_date.arr, csTmp, PD_DATE_LEN);
                ind_posting_date = 0;
DEBUGLOG(("Add:posting_date = [%.*s]\n",hv_posting_date.len,hv_posting_date.arr));
        }

/*status*/
        if(GetField_Int(hRls,"status",&iTmp)){
                hv_status = iTmp;
                ind_status = 0;
DEBUGLOG(("Add:status = [%d]\n",hv_status));
        }

/*txn_count*/
        if (GetField_Int(hRls,"txn_count",&iTmp)) {
                hv_txn_count = iTmp;
                ind_txn_count = 0;
DEBUGLOG(("Add:txn_count = [%d]\n",hv_txn_count));
        }

/*txn_amt*/
        if (GetField_Double(hRls,"txn_amt",&dTmp)) {
                hv_txn_amt= dTmp;
                ind_txn_amt= 0;
DEBUGLOG(("Add:txn_amt = [%lf]\n",hv_txn_amt));
        }

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_merch_upload_hd_insert(
                                        :hv_batch_id:ind_batch_id,
                                        :hv_txn_id:ind_txn_id,
                                        :hv_posting_date:ind_posting_date,
                                        :hv_merchant_id:ind_merchant_id,
                                        :hv_service_code:ind_service_code,
                                        :hv_filename:ind_filename,
                                        :hv_filename_prefix:ind_filename_prefix,
                                        :hv_txn_count:ind_txn_count,
                                        :hv_txn_amt:ind_txn_amt,
                                        :hv_status:ind_status);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_merch_upload_hd_insert \
( :hv_batch_id:ind_batch_id , :hv_txn_id:ind_txn_id , :hv_posting_date:ind_po\
sting_date , :hv_merchant_id:ind_merchant_id , :hv_service_code:ind_service_c\
ode , :hv_filename:ind_filename , :hv_filename_prefix:ind_filename_prefix , :\
hv_txn_count:ind_txn_count , :hv_txn_amt:ind_txn_amt , :hv_status:ind_status \
) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )96;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[1] = (unsigned long )18;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_batch_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_id;
        sqlstm.sqhstl[2] = (unsigned long )18;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_txn_id;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_posting_date;
        sqlstm.sqhstl[3] = (unsigned long )10;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_posting_date;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[4] = (unsigned long )17;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_merchant_id;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[5] = (unsigned long )5;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_service_code;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_filename;
        sqlstm.sqhstl[6] = (unsigned long )52;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_filename;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_filename_prefix;
        sqlstm.sqhstl[7] = (unsigned long )14;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_filename_prefix;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_txn_count;
        sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_txn_count;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_txn_amt;
        sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&ind_txn_amt;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)&ind_status;
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
        if (sqlca.sqlcode < 0) goto add_error;
}



DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("Add:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("AddUploadFileHeader_Add: SP_OTHER_ERR \n");
DEBUGLOG(("Add: SP_OTHER_ERR \n"));
		return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("AddUploadFileHeader_Add: SP_ERR \n");
DEBUGLOG(("Add: SP_ERR \n"));
		return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("AddUploadFileHeader_Add: SP_INTERNAL_ERR \n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}

int     parse_detail(FILE *fin,hash_t * hTxn)
{
        int     iRet = SUCCESS;
        char    csList[IMPORT_MAX_FILE][IMPORT_FIELD_LEN];
        char    cs_input_buf[PD_MAX_BUFFER +1];;
        char    csTag[PD_TAG_LEN+1];
        char* p;
        int     iCount = 0;
        int     i= 0;
        int     iRec= 0;
	char    csTmpCcy[PD_CCY_ID_LEN+1];

        while( fgets(cs_input_buf, PD_MAX_BUFFER, fin) != NULL ){

                if ((cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A) || (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0D))
                        cs_input_buf[strlen(cs_input_buf) - 1] = '\0';

                if(cs_input_buf[strlen(cs_input_buf) - 1] == 0x00)
                        continue;

DEBUGLOG(("parse_detail: DATA=[%s]\n",cs_input_buf));
                i= 0;

                p = mystrtok(cs_input_buf,PD_MY_DELIMITOR);
                if (p != NULL){
                        strcpy(csList[i],p);
                        i++;

                        while ( (p = mystrtok(NULL,PD_MY_DELIMITOR)) != NULL) {
                                strcpy(csList[i],p);
                                i++;
                        }
                }
                else{
DEBUGLOG(("parse_detail: Read Detail Error\n"));
                        iRet = FAILURE;
			break;
                }

		iRec++;
		PutField_Int(hTxn,"total_detail_record",iRec);

		if(iRet==PD_OK){
			for(iCount=0;iCount<i;iCount++){
				if(iCount==IDX_DETAIL_REF_ID)
					sprintf(csTag,"dt_ref_num_%d",iRec);
				else if(iCount==IDX_DETAIL_TXN_SEQ)
					sprintf(csTag,"vnc_ref_num_%d",iRec);
				else if(iCount==IDX_DETAIL_AUX_TXN_SEQ)
					sprintf(csTag,"aux_txn_seq_%d",iRec);
				else if(iCount==IDX_DETAIL_MERCHANT_REF)
					sprintf(csTag,"merchant_ref_%d",iRec);
				else if(iCount==IDX_DETAIL_SEQ_NUM)
					sprintf(csTag,"seq_num_%d",iRec);
				else if(iCount==IDX_DETAIL_COUNTRY)
					sprintf(csTag,"country_%d",iRec);
				else if(iCount==IDX_DETAIL_IDENTITY_ID)
					sprintf(csTag,"identity_id_%d",iRec);
				else if(iCount==IDX_DETAIL_ACCOUNT_NUM)
					sprintf(csTag,"account_num_%d",iRec);
				else if(iCount==IDX_DETAIL_ACCOUNT_NAME)
					sprintf(csTag,"account_name_%d",iRec);
				else if(iCount==IDX_DETAIL_BANK_NAME)
					sprintf(csTag,"bank_name_%d",iRec);
				else if(iCount==IDX_DETAIL_BANK_CODE)
					sprintf(csTag,"bank_code_%d",iRec);
				else if(iCount==IDX_DETAIL_BRANCH)
					sprintf(csTag,"branch_%d",iRec);
				else if(iCount==IDX_DETAIL_PHONE)
					sprintf(csTag,"phone_num_%d",iRec);
				else if(iCount==IDX_DETAIL_PROVINCE)
					sprintf(csTag,"province_%d",iRec);
				else if(iCount==IDX_DETAIL_CITY)
					sprintf(csTag,"city_%d",iRec);
				else if(iCount==IDX_DETAIL_REQ_AMT)
					sprintf(csTag,"request_amount_%d",iRec);
				else if(iCount==IDX_DETAIL_PAYOUT_AMT)
					sprintf(csTag,"payout_amount_%d",iRec);
				else if(iCount==IDX_DETAIL_REQ_CCY_CD)
					sprintf(csTag,"request_currency_%d",iRec);
				else if(iCount==IDX_DETAIL_DST_CCY_CD)
					sprintf(csTag,"payout_currency_%d",iRec);
				else if(iCount==IDX_DETAIL_MEMBER_FEE)
					sprintf(csTag,"member_fee_%d",iRec);
				else if(iCount==IDX_DETAIL_MERCHANT_FEE)
					sprintf(csTag,"merchant_fee_%d",iRec);
				else if(iCount==IDX_DETAIL_MARKUP)
					sprintf(csTag,"markup_%d",iRec);
				else if(iCount==IDX_DETAIL_MEMBER_FEE_CCY_ID)
					sprintf(csTag,"member_fee_ccy_%d",iRec);
				else if(iCount==IDX_DETAIL_MERCHANT_FEE_CCY_ID)
					sprintf(csTag,"merchant_fee_ccy_%d",iRec);
				else if(iCount==IDX_DETAIL_MARKUP_CCY_ID)
					sprintf(csTag,"markup_ccy_%d",iRec);
				else if(iCount==IDX_DETAIL_EX_RATE)
					sprintf(csTag,"ex_rate_%d",iRec);
				else if(iCount==IDX_DETAIL_TIME)
					sprintf(csTag,"time_%d",iRec);
				else if(iCount==IDX_DETAIL_REMARK)
					sprintf(csTag,"remark_%d",iRec);
				else if(iCount==IDX_DETAIL_STATUS)
					sprintf(csTag,"status_%d",iRec);
				else
					sprintf(csTag,"not_care");

				if(strlen(csList[iCount])){
					if(iCount==IDX_DETAIL_REQ_CCY_CD ||iCount==IDX_DETAIL_DST_CCY_CD){
						if(!strcmp(csList[iCount],PD_CCY_ISO_RMB)){
							sprintf(csTmpCcy,"%s",PD_CCY_ISO_CNY);
						}
						else{
							sprintf(csTmpCcy,"%s",csList[iCount]);
						}
						PutField_CString(hTxn,csTag,csTmpCcy);
DEBUGLOG(("parse_detail: Tag[%s]: [%s]\n",csTag,csTmpCcy));
					}
					/*
					else if(iCount==IDX_DETAIL_BANK_CODE){
						csList[iCount][3]='\0';
						PutField_CString(hTxn,csTag,csList[iCount]);
DEBUGLOG(("parse_detail: Tag[%s]: [%s]\n",csTag,csList[iCount]));
					}
					*/
					else{
						PutField_CString(hTxn,csTag,csList[iCount]);
DEBUGLOG(("parse_detail: Tag[%s]: [%s]\n",csTag,csList[iCount]));
					}
				}
			}

		}

	}
	iRet = process_detail(hTxn);

	return iRet;
}


int	process_detail(hash_t *hContext)
{
	int	iRet = SUCCESS;
	//int	iBatch = 0;
	int	i = 0;
	int	iTmp = 0;
	char    *csBatchId = NULL; 
	char    csTag[PD_TAG_LEN+1];
	char	*csTmp;
	double	dTmp=0.0;
	int	iCnt = 0;
	char    *csTxnSeq;
	hash_t  *hTxn;
        hTxn = (hash_t*) malloc (sizeof(hash_t));

	GetField_Int(hContext,"total_detail_record",&iCnt);

DEBUGLOG(("process_detail Begin [%d]\n",iCnt));

	for(i=1;i<=iCnt;i++){	
		hash_init(hTxn, 0);

		sprintf(csTag,"dt_ref_num_%d",i);
		if(GetField_CString(hContext,csTag,&csTmp)){
DEBUGLOG(("process_detail::dt_ref_num = [%s]\n", csTmp));
			sprintf(csTag,"%s_batch_id",csTmp);
			if(GetField_CString(hContext,csTag,&csBatchId)){
				PutField_CString(hTxn,"batch_id",csBatchId);
DEBUGLOG(("process_detail::GenBatchId batch_id = [%s]\n", csBatchId));
			}
		}

		sprintf(csTag,"vnc_ref_num_%d",i);
		if(GetField_CString(hContext,csTag,&csTmp)){
			//sprintf(csTag,"%s_vnc_ref_num",csBatchId);
			//PutField_CString(hTxn,csTag,csTmp);
			PutField_CString(hTxn,"vnc_ref_num",csTmp);
		}

		csTxnSeq  = strdup(GetNextBatchTxnSeq());
DEBUGLOG(("GenerateBatchSeq: [%d]=[%s]\n",i,csTxnSeq));
		sprintf(csTag,"txn_id_%d",i);
		PutField_CString(hTxn,"txn_id",csTxnSeq);

		sprintf(csTag,"aux_txn_seq_%d",i);
		if(GetField_CString(hContext,csTag,&csTmp)){
			PutField_CString(hTxn,"aux_txn_id",csTmp);
		}

		sprintf(csTag,"seq_num_%d",i);
		if(GetField_CString(hContext,csTag,&csTmp)){
			iTmp = atoi(csTmp);
			PutField_Int(hTxn,"seq_num",iTmp);
		}
		sprintf(csTag,"merchant_ref_%d",i);
		if(GetField_CString(hContext,csTag,&csTmp)){
			PutField_CString(hTxn,"merchant_ref",csTmp);
		}
		sprintf(csTag,"country_%d",i);
		if(GetField_CString(hContext,csTag,&csTmp)){
			PutField_CString(hTxn,"country",csTmp);
		}
		sprintf(csTag,"identity_id_%d",i);
		if(GetField_CString(hContext,csTag,&csTmp)){
			PutField_CString(hTxn,"identity_id",csTmp);
		}
		sprintf(csTag,"account_num_%d",i);
		if(GetField_CString(hContext,csTag,&csTmp)){
			PutField_CString(hTxn,"account_num",csTmp);
		}
		sprintf(csTag,"account_name_%d",i);
		if(GetField_CString(hContext,csTag,&csTmp)){
			PutField_CString(hTxn,"account_name",csTmp);
		}
		sprintf(csTag,"bank_name_%d",i);
		if(GetField_CString(hContext,csTag,&csTmp)){
			PutField_CString(hTxn,"bank_name",csTmp);
		}
		sprintf(csTag,"bank_code_%d",i);
		if(GetField_CString(hContext,csTag,&csTmp)){
			PutField_CString(hTxn,"bank_code",csTmp);
		}
		sprintf(csTag,"branch_%d",i);
		if(GetField_CString(hContext,csTag,&csTmp)){
			PutField_CString(hTxn,"branch",csTmp);
		}
		else{
			PutField_CString(hTxn,"branch","XXX");
		}
		sprintf(csTag,"phone_num_%d",i);
		if(GetField_CString(hContext,csTag,&csTmp)){
			PutField_CString(hTxn,"phone_num",csTmp);
		}
		sprintf(csTag,"province_%d",i);
		if(GetField_CString(hContext,csTag,&csTmp)){
			PutField_CString(hTxn,"province",csTmp);
		}
		sprintf(csTag,"city_%d",i);
		if(GetField_CString(hContext,csTag,&csTmp)){
			PutField_CString(hTxn,"city",csTmp);
		}
		sprintf(csTag,"payout_currency_%d",i);
		if(GetField_CString(hContext,csTag,&csTmp)){
			PutField_CString(hTxn,"payout_currency",csTmp);
			PutField_CString(hTxn,"member_fee_ccy",csTmp);
			PutField_CString(hTxn,"markup_ccy",csTmp);
		}
		sprintf(csTag,"payout_amount_%d",i);
		if(GetField_CString(hContext,csTag,&csTmp)){
			if(sscanf(csTmp,"%lf",&dTmp)==1)
				PutField_Double(hTxn,"payout_amount",dTmp);
		}
		sprintf(csTag,"request_currency_%d",i);
		if(GetField_CString(hContext,csTag,&csTmp)){
			PutField_CString(hTxn,"request_currency",csTmp);
			PutField_CString(hTxn,"merchant_fee_ccy",csTmp);
		}
		sprintf(csTag,"request_amount_%d",i);
		if(GetField_CString(hContext,csTag,&csTmp)){
			if(sscanf(csTmp,"%lf",&dTmp)==1){
				PutField_Double(hTxn,"request_amount",dTmp);
			}
		}
		sprintf(csTag,"merchant_fee_%d",i);
		if(GetField_CString(hContext,csTag,&csTmp)){
			if(sscanf(csTmp,"%lf",&dTmp)==1){
				PutField_Double(hTxn,"merchant_fee",dTmp);
			}
		}
		sprintf(csTag,"member_fee_%d",i);
		if(GetField_CString(hContext,csTag,&csTmp)){
			if(sscanf(csTmp,"%lf",&dTmp)==1){
				PutField_Double(hTxn,"member_fee",dTmp);
			}
		}
		sprintf(csTag,"markup_%d",i);
		if(GetField_CString(hContext,csTag,&csTmp)){
			if(sscanf(csTmp,"%lf",&dTmp)==1){
				PutField_Double(hTxn,"markup_amt",dTmp);
			}
		}
		sprintf(csTag,"ex_rate_%d",i);
		if(GetField_CString(hContext,csTag,&csTmp)){
			if(sscanf(csTmp,"%lf",&dTmp)==1)
				PutField_Double(hTxn,"ex_rate",dTmp);
		}
		sprintf(csTag,"remark_%d",i);
		if(GetField_CString(hContext,csTag,&csTmp)){
			PutField_CString(hTxn,"remark",csTmp);
		}
		sprintf(csTag,"status_%d",i);
		if(GetField_CString(hContext,csTag,&csTmp)){
			PutField_Int(hTxn,"status",atoi(csTmp));
		}

		PutField_Char(hTxn,"batch_mode",PD_OFFLINE);

		if(AddUploadDetail(hTxn)!=PD_OK){
			iRet = FAILURE;
			break;
		}
		if(UpdateUploadDetail(hTxn)!=PD_OK){
			iRet = FAILURE;
			break;
		}

		FREE_ME(csTxnSeq);
	}

	FREE_ME(hTxn);
	return iRet;
}

/*
int UpdateUploadHeader(const hash_t *hRls)
{
        char*   csBuf;
        char*   csBatchId;

        EXEC SQL WHENEVER SQLERROR GOTO updatehd_error;
        EXEC SQL WHENEVER NOTFOUND CONTINUE;

        EXEC SQL BEGIN DECLARE SECTION;

                varchar         hv_dynstmt[1024];

        EXEC SQL END DECLARE SECTION;


DEBUGLOG(("UpdateUploadHeader: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update merchant_upload_file_header set uh_update_timestamp = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        if(GetField_CString(hRls,"batch_id",&csBatchId)){
DEBUGLOG(("UpdateUploadHeader:batch_id = [%s]\n",csBatchId));
        }
        else{
                FREE_ME(csBuf);
DEBUGLOG(("UpdateUploadHeader batch_id not found\n"));
                return INT_ERR;
        }

	if(GetField_CString(hRls,"vnc_ref_num",&csBuf)){
DEBUGLOG(("UpdateUploadHeader:vnc_ref_num = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",uh_vnc_ref_num = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	strcat((char*)hv_dynstmt.arr, " WHERE uh_batch_id = ");
        strcat((char*)hv_dynstmt.arr, csBatchId);
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));


        EXEC SQL PREPARE PS FROM :hv_dynstmt;
        EXEC SQL EXECUTE PS;

        FREE_ME(csBuf);

DEBUGLOG(("UpdateUploadHeader Normal Exit\n"));
        return PD_OK;

updatehd_error:
DEBUGLOG(("updatehd_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("UpdateUploadHeader: SP_INTERNAL_ERR\n");
        EXEC SQL WHENEVER SQLERROR CONTINUE;
        return PD_INTERNAL_ERR;
}
*/

int UpdateUploadDetail(const hash_t *hRls)
{
        char*   csBuf;
        char*   csBatchId;
        char*   csSeqNum;
	char    cTmp;
	int	iSeqNum = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO updatedt_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateUploadDetail: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update merchant_upload_file_detail set ud_update_timestamp = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        if(GetField_CString(hRls,"batch_id",&csBatchId)){
DEBUGLOG(("UpdateUploadDetail:batch_id = [%s]\n",csBatchId));
        }
        else{
                FREE_ME(csBuf);
DEBUGLOG(("UpdateUploadDetail batch_id not found\n"));
                return INT_ERR;
        }
        if(GetField_Int(hRls,"seq_num",&iSeqNum)){
        	csSeqNum = (char*) malloc (128);
		sprintf(csSeqNum,"%d",iSeqNum);
DEBUGLOG(("UpdateUploadDetail:seq_num = [%d]\n",iSeqNum));
        }

	if(GetField_Char(hRls,"batch_mode",&cTmp)){
DEBUGLOG(("UpdateUploadDetail: batch_mode = [%c]\n",cTmp));
                sprintf(csBuf,"%c",cTmp);
                strcat((char*)hv_dynstmt.arr, ",ud_batch_mode = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
	
	if(GetField_CString(hRls,"vnc_ref_num",&csBuf)){
DEBUGLOG(("UpdateUploadDetail:vnc_ref_num = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_vnc_ref_num = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	strcat((char*)hv_dynstmt.arr, " WHERE ud_batch_id = ");
        strcat((char*)hv_dynstmt.arr, csBatchId);
	strcat((char*)hv_dynstmt.arr, " and ud_seq_num = ");
        strcat((char*)hv_dynstmt.arr, csSeqNum);
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));


        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )155;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
        sqlstm.sqhstl[0] = (unsigned long )1026;
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
        if (sqlca.sqlcode < 0) goto updatedt_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )174;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto updatedt_error;
}



        FREE_ME(csBuf);
        FREE_ME(csSeqNum);

DEBUGLOG(("UpdateUploadDetail Normal Exit\n"));
        return PD_OK;

updatedt_error:
DEBUGLOG(("updatedt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("UpdateUploadDetail: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_INTERNAL_ERR;
}

int     AddUploadDetail(const hash_t *hRls)
{
        char            *csTmp;
        int             iTmp;
        double          dTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

                /* varchar         hv_aux_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_aux_txn_id;

                int             hv_seq_num;
                /* varchar         hv_merchant_ref[PD_MERCHANT_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_merchant_ref;

                /* varchar         hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

                /* varchar         hv_identity_id[PD_IDENTITY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_identity_id;

                /* varchar         hv_account_num[PD_AC_NO_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_account_num;

                /* varchar         hv_account_name[PD_ACC_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_account_name;

                /* varchar         hv_bank_name[PD_BANK_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_name;

                /* varchar         hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;

                /* varchar         hv_branch[PD_BANK_BRANCH_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_branch;

                /* varchar         hv_phone_num[PD_MOBILE_NO_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_phone_num;

                /* varchar         hv_province[PD_PROVINCE_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_province;

                /* varchar         hv_city[PD_CITY_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_city;

                /* varchar         hv_payout_currency[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_payout_currency;

                /* varchar         hv_request_currency[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_request_currency;

                double          hv_payout_amount;
                double          hv_request_amount;
                /* varchar         hv_merchant_fee_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_merchant_fee_ccy;

                /* varchar         hv_member_fee_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_member_fee_ccy;

                double          hv_merchant_fee;
                double          hv_member_fee;
                /* varchar         hv_markup_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_markup_ccy;

                double          hv_markup_amt;
                double          hv_ex_rate;
                int             hv_status;
                /* varchar         hv_remark[PD_REMARK_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_remark;


                short           ind_batch_id= -1;
                short           ind_txn_id= -1;
                short           ind_aux_txn_id= -1;
                short           ind_seq_num = -1;
		short           ind_merchant_ref = -1;
                short           ind_country = -1;
                short           ind_identity_id = -1;
                short           ind_account_num = -1;
                short           ind_account_name = -1;
                short           ind_bank_name = -1;
                short           ind_bank_code = -1;
                short           ind_branch = -1;
                short           ind_phone_num = -1;
                short           ind_province = -1;
                short           ind_city = -1;
                short           ind_payout_currency = -1;
                short           ind_request_currency = -1;
                short           ind_payout_amount = -1;
                short           ind_request_amount = -1;
                short           ind_merchant_fee_ccy = -1;
                short           ind_member_fee_ccy = -1;
                short           ind_merchant_fee = -1;
                short           ind_member_fee = -1;
                short           ind_markup_ccy = -1;
                short           ind_markup_amt = -1;
                short           ind_ex_rate = -1;
                short           ind_status = -1;
                short           ind_remark = -1;

                short           hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("AddUploadDetail: Begin\n"));

/*batch_id*/
        if(GetField_CString(hRls,"batch_id",&csTmp)){
                hv_batch_id.len = strlen(csTmp);
                memcpy(hv_batch_id.arr, csTmp, hv_batch_id.len);
                ind_batch_id= 0;
DEBUGLOG(("Add:batch_id= [%.*s]\n",hv_batch_id.len,hv_batch_id.arr));
        }

/*txn_id*/
        if(GetField_CString(hRls,"txn_id",&csTmp)){
                hv_txn_id.len = strlen(csTmp);
                memcpy(hv_txn_id.arr, csTmp, hv_txn_id.len);
                ind_txn_id= 0;
DEBUGLOG(("Add:txn_id= [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
        }

/*aux_txn_id*/
        if(GetField_CString(hRls,"aux_txn_id",&csTmp)){
                hv_aux_txn_id.len = strlen(csTmp);
                memcpy(hv_aux_txn_id.arr, csTmp, hv_aux_txn_id.len);
                ind_aux_txn_id= 0;
DEBUGLOG(("Add:aux_txn_id= [%.*s]\n",hv_aux_txn_id.len,hv_aux_txn_id.arr));
        }

/*seq_num*/
        if(GetField_Int(hRls,"seq_num",&iTmp)){
                hv_seq_num = iTmp;
                ind_seq_num = 0;
DEBUGLOG(("Add:seq_num = [%d]\n",hv_seq_num));
        }

/*merchant ref no*/
        if(GetField_CString(hRls,"merchant_ref",&csTmp)){
                hv_merchant_ref.len = strlen(csTmp);
                memcpy(hv_merchant_ref.arr, csTmp, hv_merchant_ref.len);
                ind_merchant_ref = 0;
DEBUGLOG(("Add:merchant_ref = [%.*s]\n",hv_merchant_ref.len,hv_merchant_ref.arr));
        }
/*country*/
        if(GetField_CString(hRls,"country",&csTmp)){
                hv_country.len = strlen(csTmp);
                memcpy(hv_country.arr, csTmp, hv_country.len);
                ind_country = 0;
DEBUGLOG(("Add:country = [%.*s]\n",hv_country.len,hv_country.arr));
        }

/*identity id no*/
        if(GetField_CString(hRls,"identity_id",&csTmp)){
                hv_identity_id.len = strlen(csTmp);
                memcpy(hv_identity_id.arr, csTmp, hv_identity_id.len);
                ind_identity_id = 0;
DEBUGLOG(("Add:identity_id = [%.*s]\n",hv_identity_id.len,hv_identity_id.arr));
        }

/*account_num*/
        if(GetField_CString(hRls,"account_num",&csTmp)){
                hv_account_num.len = strlen(csTmp);
                memcpy(hv_account_num.arr, csTmp, hv_account_num.len);
                ind_account_num = 0;
DEBUGLOG(("Add:account_num = [%.*s]\n",hv_account_num.len,hv_account_num.arr));
        }

/*account name*/
        if(GetField_CString(hRls,"account_name",&csTmp)){
                hv_account_name.len = strlen(csTmp);
                memcpy(hv_account_name.arr, csTmp, hv_account_name.len);
                ind_account_name = 0;
DEBUGLOG(("Add:account_name = [%.*s]\n",hv_account_name.len,hv_account_name.arr));
        }

/*bank_name*/
        if(GetField_CString(hRls,"bank_name",&csTmp)){
                hv_bank_name.len = strlen(csTmp);
                memcpy(hv_bank_name.arr, csTmp, hv_bank_name.len);
                ind_bank_name = 0;
DEBUGLOG(("Add:bank_name = [%.*s]\n",hv_bank_name.len,hv_bank_name.arr));
        }
/*bank_code*/
        if(GetField_CString(hRls,"bank_code",&csTmp)){
                hv_bank_code.len = strlen(csTmp);
                memcpy(hv_bank_code.arr, csTmp, hv_bank_code.len);
                ind_bank_code= 0;
DEBUGLOG(("Add:bank_code= [%.*s]\n",hv_bank_code.len,hv_bank_code.arr));
        }

/*branch*/
        if(GetField_CString(hRls,"branch",&csTmp)){
                hv_branch.len = strlen(csTmp);
                memcpy(hv_branch.arr, csTmp, hv_branch.len);
                ind_branch = 0;
DEBUGLOG(("Add:branch = [%.*s]\n",hv_branch.len,hv_branch.arr));
        }

/*phone_num*/
        if(GetField_CString(hRls,"phone_num",&csTmp)){
                hv_phone_num.len = strlen(csTmp);
                memcpy(hv_phone_num.arr, csTmp, hv_phone_num.len);
                ind_phone_num = 0;
DEBUGLOG(("Add:phone_num = [%.*s]\n",hv_phone_num.len,hv_phone_num.arr));
        }

/*province*/
        if(GetField_CString(hRls,"province",&csTmp)){
                hv_province.len = strlen(csTmp);
                memcpy(hv_province.arr, csTmp, hv_province.len);
                ind_province = 0;
DEBUGLOG(("Add:province = [%.*s]\n",hv_province.len,hv_province.arr));
        }

/*city*/
        if(GetField_CString(hRls,"city",&csTmp)){
                hv_city.len = strlen(csTmp);
                memcpy(hv_city.arr, csTmp, hv_city.len);
                ind_city = 0;
DEBUGLOG(("Add:city = [%.*s]\n",hv_city.len,hv_city.arr));
        }
/*payout currency*/
        if(GetField_CString(hRls,"payout_currency",&csTmp)){
                hv_payout_currency.len = strlen(csTmp);
                memcpy(hv_payout_currency.arr, csTmp, hv_payout_currency.len);
                ind_payout_currency = 0;
DEBUGLOG(("Add:payout_currency = [%.*s]\n",hv_payout_currency.len,hv_payout_currency.arr));
        }

/*payout_amount*/
        if (GetField_Double(hRls,"payout_amount",&dTmp)) {
                hv_payout_amount = dTmp;
                ind_payout_amount = 0;
DEBUGLOG(("Add:payout_amount = [%lf]\n",hv_payout_amount));
        }

/*request currency*/
        if(GetField_CString(hRls,"request_currency",&csTmp)){
                hv_request_currency.len = strlen(csTmp);
                memcpy(hv_request_currency.arr, csTmp, hv_request_currency.len);
                ind_request_currency = 0;
DEBUGLOG(("Add:request_currency = [%.*s]\n",hv_request_currency.len,hv_request_currency.arr));
        }

/*request amount*/
        if (GetField_Double(hRls,"request_amount",&dTmp)) {
                hv_request_amount = dTmp;
                ind_request_amount = 0;
DEBUGLOG(("Add:request_amount = [%lf]\n",hv_request_amount));
        }

/*merchant_fee_ccy*/
        if(GetField_CString(hRls,"merchant_fee_ccy",&csTmp)){
                hv_merchant_fee_ccy.len = strlen(csTmp);
                memcpy(hv_merchant_fee_ccy.arr, csTmp, hv_merchant_fee_ccy.len);
                ind_merchant_fee_ccy= 0;
DEBUGLOG(("Add:merchant_fee_ccy = [%.*s]\n",hv_merchant_fee_ccy.len,hv_merchant_fee_ccy.arr));
        }

/*merchant_fee*/
        if (GetField_Double(hRls,"merchant_fee",&dTmp)) {
                hv_merchant_fee = dTmp;
                ind_merchant_fee = 0;
DEBUGLOG(("Add:merchant_fee = [%lf]\n",hv_merchant_fee));
        }
/*member_fee_ccy*/
        if(GetField_CString(hRls,"member_fee_ccy",&csTmp)){
                hv_member_fee_ccy.len = strlen(csTmp);
                memcpy(hv_member_fee_ccy.arr, csTmp, hv_member_fee_ccy.len);
                ind_member_fee_ccy= 0;
DEBUGLOG(("Add:member_fee_ccy = [%.*s]\n",hv_member_fee_ccy.len,hv_member_fee_ccy.arr));
        }

/*member_fee*/
        if (GetField_Double(hRls,"member_fee",&dTmp)) {
                hv_member_fee= dTmp;
                ind_member_fee= 0;
DEBUGLOG(("Add:member_fee = [%lf]\n",hv_member_fee));
        }

/*markup_ccy*/
        if(GetField_CString(hRls,"markup_ccy",&csTmp)){
                hv_markup_ccy.len = strlen(csTmp);
                memcpy(hv_markup_ccy.arr, csTmp, hv_markup_ccy.len);
                ind_markup_ccy= 0;
DEBUGLOG(("Add:markup_ccy = [%.*s]\n",hv_markup_ccy.len,hv_markup_ccy.arr));
        }

/*markup_amt*/
        if (GetField_Double(hRls,"markup_amt",&dTmp)) {
                hv_markup_amt= dTmp;
                ind_markup_amt= 0;
DEBUGLOG(("Add:markup_amt = [%lf]\n",hv_markup_amt));
        }

/*ex_rate*/
        if (GetField_Double(hRls,"ex_rate",&dTmp)) {
                hv_ex_rate= dTmp;
                ind_ex_rate= 0;
DEBUGLOG(("Add:ex_rate = [%lf]\n",hv_ex_rate));
        }

/*status*/
        if(GetField_Int(hRls,"status",&iTmp)){
                hv_status = iTmp;
                ind_status = 0;
DEBUGLOG(("Add:status = [%i]\n",hv_status));
        }
/*remark*/
        if(GetField_CString(hRls,"remark",&csTmp)){
                hv_remark.len = strlen(csTmp);
                memcpy(hv_remark.arr, csTmp, hv_remark.len);
                ind_remark = 0;
DEBUGLOG(("Add:remark = [%.*s]\n",hv_remark.len,hv_remark.arr));
        }

        FREE_ME(csTmp);

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_merch_upload_dt_insert(
                                        :hv_batch_id:ind_batch_id,
                                        :hv_seq_num:ind_seq_num,
                                        :hv_txn_id:ind_txn_id,
                                        :hv_aux_txn_id:ind_aux_txn_id,
                                        :hv_merchant_ref:ind_merchant_ref,
                                        :hv_country:ind_country,
                                        :hv_identity_id:ind_identity_id,
                                        :hv_account_num:ind_account_num,
                                        :hv_account_name:ind_account_name,
                                        :hv_bank_name:ind_bank_name,
                                        :hv_bank_code:ind_bank_code,
                                        :hv_branch:ind_branch,
                                        :hv_phone_num:ind_phone_num,
                                        :hv_province:ind_province,
                                        :hv_city:ind_city,
                                        :hv_payout_currency:ind_payout_currency,
                                        :hv_payout_amount:ind_payout_amount,
                                        :hv_request_currency:ind_request_currency,
                                        :hv_request_amount:ind_request_amount,
                                        :hv_merchant_fee_ccy:ind_merchant_fee_ccy,
                                        :hv_merchant_fee:ind_merchant_fee,
                                        :hv_member_fee_ccy:ind_member_fee_ccy,
                                        :hv_member_fee:ind_member_fee,
                                        :hv_markup_ccy:ind_markup_ccy,
                                        :hv_markup_amt:ind_markup_amt,
                                        :hv_ex_rate:ind_ex_rate,
                                        :hv_status:ind_status,
                                        :hv_remark:ind_remark);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 29;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_merch_upload_dt_insert \
( :hv_batch_id:ind_batch_id , :hv_seq_num:ind_seq_num , :hv_txn_id:ind_txn_id\
 , :hv_aux_txn_id:ind_aux_txn_id , :hv_merchant_ref:ind_merchant_ref , :hv_co\
untry:ind_country , :hv_identity_id:ind_identity_id , :hv_account_num:ind_acc\
ount_num , :hv_account_name:ind_account_name , :hv_bank_name:ind_bank_name , \
:hv_bank_code:ind_bank_code , :hv_branch:ind_branch , :hv_phone_num:ind_phone\
_num , :hv_province:ind_province , :hv_city:ind_city , :hv_payout_currency:in\
d_payout_currency , :hv_payout_amount:ind_payout_amount , :hv_request_currenc\
y:ind_request_currency , :hv_request_amount:ind_request_amount , :hv_merchant\
_fee_ccy:ind_merchant_fee_ccy , :hv_merchant_fee:ind_merchant_fee , :hv_membe\
r_fee_ccy:ind_member_fee_ccy , :hv_member_fee:ind_member_fee , :hv_markup_ccy\
:ind_markup_ccy , :hv_markup_amt:ind_markup_amt , :hv_ex_rate:ind_ex_rate , :\
hv_status:ind_status , :hv_remark:ind_remark ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )189;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[1] = (unsigned long )18;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_batch_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_seq_num;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_seq_num;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_id;
        sqlstm.sqhstl[3] = (unsigned long )18;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_txn_id;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_aux_txn_id;
        sqlstm.sqhstl[4] = (unsigned long )18;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_aux_txn_id;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_merchant_ref;
        sqlstm.sqhstl[5] = (unsigned long )52;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_merchant_ref;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_country;
        sqlstm.sqhstl[6] = (unsigned long )4;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_country;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_identity_id;
        sqlstm.sqhstl[7] = (unsigned long )27;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_identity_id;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_account_num;
        sqlstm.sqhstl[8] = (unsigned long )27;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_account_num;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_account_name;
        sqlstm.sqhstl[9] = (unsigned long )27;
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&ind_account_name;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&hv_bank_name;
        sqlstm.sqhstl[10] = (unsigned long )52;
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)&ind_bank_name;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&hv_bank_code;
        sqlstm.sqhstl[11] = (unsigned long )12;
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         short *)&ind_bank_code;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (unsigned char  *)&hv_branch;
        sqlstm.sqhstl[12] = (unsigned long )52;
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         short *)&ind_branch;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned long )0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
        sqlstm.sqhstv[13] = (unsigned char  *)&hv_phone_num;
        sqlstm.sqhstl[13] = (unsigned long )27;
        sqlstm.sqhsts[13] = (         int  )0;
        sqlstm.sqindv[13] = (         short *)&ind_phone_num;
        sqlstm.sqinds[13] = (         int  )0;
        sqlstm.sqharm[13] = (unsigned long )0;
        sqlstm.sqadto[13] = (unsigned short )0;
        sqlstm.sqtdso[13] = (unsigned short )0;
        sqlstm.sqhstv[14] = (unsigned char  *)&hv_province;
        sqlstm.sqhstl[14] = (unsigned long )22;
        sqlstm.sqhsts[14] = (         int  )0;
        sqlstm.sqindv[14] = (         short *)&ind_province;
        sqlstm.sqinds[14] = (         int  )0;
        sqlstm.sqharm[14] = (unsigned long )0;
        sqlstm.sqadto[14] = (unsigned short )0;
        sqlstm.sqtdso[14] = (unsigned short )0;
        sqlstm.sqhstv[15] = (unsigned char  *)&hv_city;
        sqlstm.sqhstl[15] = (unsigned long )22;
        sqlstm.sqhsts[15] = (         int  )0;
        sqlstm.sqindv[15] = (         short *)&ind_city;
        sqlstm.sqinds[15] = (         int  )0;
        sqlstm.sqharm[15] = (unsigned long )0;
        sqlstm.sqadto[15] = (unsigned short )0;
        sqlstm.sqtdso[15] = (unsigned short )0;
        sqlstm.sqhstv[16] = (unsigned char  *)&hv_payout_currency;
        sqlstm.sqhstl[16] = (unsigned long )5;
        sqlstm.sqhsts[16] = (         int  )0;
        sqlstm.sqindv[16] = (         short *)&ind_payout_currency;
        sqlstm.sqinds[16] = (         int  )0;
        sqlstm.sqharm[16] = (unsigned long )0;
        sqlstm.sqadto[16] = (unsigned short )0;
        sqlstm.sqtdso[16] = (unsigned short )0;
        sqlstm.sqhstv[17] = (unsigned char  *)&hv_payout_amount;
        sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[17] = (         int  )0;
        sqlstm.sqindv[17] = (         short *)&ind_payout_amount;
        sqlstm.sqinds[17] = (         int  )0;
        sqlstm.sqharm[17] = (unsigned long )0;
        sqlstm.sqadto[17] = (unsigned short )0;
        sqlstm.sqtdso[17] = (unsigned short )0;
        sqlstm.sqhstv[18] = (unsigned char  *)&hv_request_currency;
        sqlstm.sqhstl[18] = (unsigned long )5;
        sqlstm.sqhsts[18] = (         int  )0;
        sqlstm.sqindv[18] = (         short *)&ind_request_currency;
        sqlstm.sqinds[18] = (         int  )0;
        sqlstm.sqharm[18] = (unsigned long )0;
        sqlstm.sqadto[18] = (unsigned short )0;
        sqlstm.sqtdso[18] = (unsigned short )0;
        sqlstm.sqhstv[19] = (unsigned char  *)&hv_request_amount;
        sqlstm.sqhstl[19] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[19] = (         int  )0;
        sqlstm.sqindv[19] = (         short *)&ind_request_amount;
        sqlstm.sqinds[19] = (         int  )0;
        sqlstm.sqharm[19] = (unsigned long )0;
        sqlstm.sqadto[19] = (unsigned short )0;
        sqlstm.sqtdso[19] = (unsigned short )0;
        sqlstm.sqhstv[20] = (unsigned char  *)&hv_merchant_fee_ccy;
        sqlstm.sqhstl[20] = (unsigned long )5;
        sqlstm.sqhsts[20] = (         int  )0;
        sqlstm.sqindv[20] = (         short *)&ind_merchant_fee_ccy;
        sqlstm.sqinds[20] = (         int  )0;
        sqlstm.sqharm[20] = (unsigned long )0;
        sqlstm.sqadto[20] = (unsigned short )0;
        sqlstm.sqtdso[20] = (unsigned short )0;
        sqlstm.sqhstv[21] = (unsigned char  *)&hv_merchant_fee;
        sqlstm.sqhstl[21] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[21] = (         int  )0;
        sqlstm.sqindv[21] = (         short *)&ind_merchant_fee;
        sqlstm.sqinds[21] = (         int  )0;
        sqlstm.sqharm[21] = (unsigned long )0;
        sqlstm.sqadto[21] = (unsigned short )0;
        sqlstm.sqtdso[21] = (unsigned short )0;
        sqlstm.sqhstv[22] = (unsigned char  *)&hv_member_fee_ccy;
        sqlstm.sqhstl[22] = (unsigned long )5;
        sqlstm.sqhsts[22] = (         int  )0;
        sqlstm.sqindv[22] = (         short *)&ind_member_fee_ccy;
        sqlstm.sqinds[22] = (         int  )0;
        sqlstm.sqharm[22] = (unsigned long )0;
        sqlstm.sqadto[22] = (unsigned short )0;
        sqlstm.sqtdso[22] = (unsigned short )0;
        sqlstm.sqhstv[23] = (unsigned char  *)&hv_member_fee;
        sqlstm.sqhstl[23] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[23] = (         int  )0;
        sqlstm.sqindv[23] = (         short *)&ind_member_fee;
        sqlstm.sqinds[23] = (         int  )0;
        sqlstm.sqharm[23] = (unsigned long )0;
        sqlstm.sqadto[23] = (unsigned short )0;
        sqlstm.sqtdso[23] = (unsigned short )0;
        sqlstm.sqhstv[24] = (unsigned char  *)&hv_markup_ccy;
        sqlstm.sqhstl[24] = (unsigned long )5;
        sqlstm.sqhsts[24] = (         int  )0;
        sqlstm.sqindv[24] = (         short *)&ind_markup_ccy;
        sqlstm.sqinds[24] = (         int  )0;
        sqlstm.sqharm[24] = (unsigned long )0;
        sqlstm.sqadto[24] = (unsigned short )0;
        sqlstm.sqtdso[24] = (unsigned short )0;
        sqlstm.sqhstv[25] = (unsigned char  *)&hv_markup_amt;
        sqlstm.sqhstl[25] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[25] = (         int  )0;
        sqlstm.sqindv[25] = (         short *)&ind_markup_amt;
        sqlstm.sqinds[25] = (         int  )0;
        sqlstm.sqharm[25] = (unsigned long )0;
        sqlstm.sqadto[25] = (unsigned short )0;
        sqlstm.sqtdso[25] = (unsigned short )0;
        sqlstm.sqhstv[26] = (unsigned char  *)&hv_ex_rate;
        sqlstm.sqhstl[26] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[26] = (         int  )0;
        sqlstm.sqindv[26] = (         short *)&ind_ex_rate;
        sqlstm.sqinds[26] = (         int  )0;
        sqlstm.sqharm[26] = (unsigned long )0;
        sqlstm.sqadto[26] = (unsigned short )0;
        sqlstm.sqtdso[26] = (unsigned short )0;
        sqlstm.sqhstv[27] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[27] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[27] = (         int  )0;
        sqlstm.sqindv[27] = (         short *)&ind_status;
        sqlstm.sqinds[27] = (         int  )0;
        sqlstm.sqharm[27] = (unsigned long )0;
        sqlstm.sqadto[27] = (unsigned short )0;
        sqlstm.sqtdso[27] = (unsigned short )0;
        sqlstm.sqhstv[28] = (unsigned char  *)&hv_remark;
        sqlstm.sqhstl[28] = (unsigned long )257;
        sqlstm.sqhsts[28] = (         int  )0;
        sqlstm.sqindv[28] = (         short *)&ind_remark;
        sqlstm.sqinds[28] = (         int  )0;
        sqlstm.sqharm[28] = (unsigned long )0;
        sqlstm.sqadto[28] = (unsigned short )0;
        sqlstm.sqtdso[28] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto add_error;
}


DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("Add:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("AddUploadDetail_Add: SP_OTHER_ERR\n");
DEBUGLOG(("Add: SP_OTHER_ERR\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("AddUploadDetail_Add: SP_ERR\n");
DEBUGLOG(("Add: SP_ERR\n"));
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("AddUploadDetail_Add: SP_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}


int parse_arg(int argc,char **argv)
{
        char    c;
        strcpy(cs_dtfile,"");
        strcpy(cs_hdfile,"");
        strcpy(cs_date,"");

        while ((c = getopt(argc,argv,"h:t:d:")) != EOF) {
                switch (c) {
                        case 'h':
                                strcpy(cs_hdfile, optarg);
                                break;
                        case 't':
                                strcpy(cs_dtfile, optarg);
                                break;
                        case 'd':
                                strcpy(cs_date, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_hdfile,"") || !strcmp(cs_dtfile,"") || !strcmp(cs_date,""))
                return FAILURE;

        return SUCCESS;
}

