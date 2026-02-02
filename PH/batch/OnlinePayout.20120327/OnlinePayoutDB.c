
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
           char  filnam[18];
};
static struct sqlcxp sqlfpn =
{
    17,
    "OnlinePayoutDB.pc"
};


static unsigned int sqlctx = 10195499;


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
   unsigned char  *sqhstv[16];
   unsigned long  sqhstl[16];
            int   sqhsts[16];
            short *sqindv[16];
            int   sqinds[16];
   unsigned long  sqharm[16];
   unsigned long  *sqharc[16];
   unsigned short  sqadto[16];
   unsigned short  sqtdso[16];
} sqlstm = {12,16};

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
"select uh_batch_id ,uh_merchant_id  from merchant_upload_file_header where \
(uh_status=:b0 and uh_service_code=:b1)           ";

 static char *sq0003 = 
"select ud_seq_num ,ud_txn_id ,ud_merchant_ref ,ud_country ,ud_identity_id ,\
ud_account_name ,ud_account_num ,ud_bank_name ,ud_bank_code ,ud_branch ,ud_ph\
one_num ,ud_province ,ud_city ,ud_payout_amount ,ud_payout_currency ,ud_reque\
st_currency  from merchant_upload_file_detail where (((ud_status=:b0 and ud_b\
atch_mode=:b1) and ud_disabled=:b2) and ud_batch_id=:b3)           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,125,0,9,122,0,0,2,2,0,1,0,1,3,0,0,1,9,0,0,
28,0,0,1,0,0,13,125,0,0,2,0,0,1,0,2,3,0,0,2,9,0,0,
51,0,0,1,0,0,15,203,0,0,0,0,0,1,0,
66,0,0,2,0,0,32,204,0,0,0,0,0,1,0,
81,0,0,3,373,0,9,296,0,0,4,4,0,1,0,1,3,0,0,1,1,0,0,1,3,0,0,1,3,0,0,
112,0,0,3,0,0,13,298,0,0,16,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,
2,9,0,0,
191,0,0,3,0,0,15,430,0,0,0,0,0,1,0,
206,0,0,3,0,0,15,436,0,0,0,0,0,1,0,
221,0,0,4,0,0,32,437,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/09/06              LokMan Chow
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include "common.h"
#include "utilitys.h"
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"
#include "ObjPtr.h"
#include "queue_utility.h"
#include "gateway.h"
#include "internal.h"
#include "OnlinePayout.h"


#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


#define	PD_TMP_TAG_LEN	25
char    cDebug = 'Y';

#define MY_TMP_TOKEN            "&"
#define MY_TMP_FIELD_TOKEN      "="
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);
OBJPTR(Channel);

int process_header(hash_t* hContext, hash_t* hRequest);
int process_txn(const char* csBatchId, const char* csMerchId, hash_t *hContext, hash_t* hRequest);
int BatchOnlineWithdrawAll(hash_t* hContext,hash_t* hRequest);
//int CheckAmount(hash_t* hContext,const hash_t* hReq);

int     AddWTBTxnLog(const hash_t *hContext,
                hash_t* hRequest);


int batch_init(int argc, char* argv[])
{
        return SUCCESS;
}

int batch_proc(int argc, char* argv[],hash_t *hContext,hash_t * hRequest)
{

        int     iRet;

	iRet = process_header(hContext,hRequest);

DEBUGLOG(("process_header iRet = [%d]\n",iRet));
	return iRet;	

}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


int process_header(hash_t* hContext,hash_t* hRequest)
{
	int     iRet = PD_ERR;
	int     iTotalCnt = 0;
	int     iBatchCnt = 0;
	int     i, iStatus;
	char    csTag[PD_TMP_TAG_LEN +1];
	char    csBatchId[PD_TXN_SEQ_LEN +1];
	char    *csTmp;

	PutField_Int(hRequest,"total_record",iTotalCnt);


	/* EXEC SQL WHENEVER SQLERROR GOTO head_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int	hv_status;
		
		long	v_batch_id;
                /* varchar v_merchant_id[PD_MERCHANT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;


		short   ind_merchant_id = -1;
		short   ind_batch_id = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


        hv_status = PD_PAYOUTFILE_APPROVED;
DEBUGLOG(("process_header::status = [%d]\n",hv_status));

	hv_service_code.len = strlen("TLN");
	memcpy(hv_service_code.arr,"TLN",hv_service_code.len);
DEBUGLOG(("process_header::service_code = [%s]\n",hv_service_code.arr));
	PutField_CString(hRequest,"service_code",(const char*)hv_service_code.arr);


	/* EXEC SQL DECLARE c_cursor_getheader CURSOR FOR
		select	uh_batch_id,
			uh_merchant_id
		from	merchant_upload_file_header
		where	uh_status = :hv_status
		and	uh_service_code = :hv_service_code; */ 


	/* EXEC SQL OPEN c_cursor_getheader; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[1] = (unsigned long )5;
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
 if (sqlca.sqlcode < 0) goto head_error;
}



	do{
		/* EXEC SQL FETCH c_cursor_getheader
		INTO
			:v_batch_id:ind_batch_id,
			:v_merchant_id:ind_merchant_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 2;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )28;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_batch_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_merchant_id;
  sqlstm.sqhstl[1] = (unsigned long )18;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
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
  if (sqlca.sqlcode < 0) goto head_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }
		
		
		if(ind_merchant_id>=0)
			v_merchant_id.arr[v_merchant_id.len]='\0';


		if((ind_batch_id>=0) &&(ind_merchant_id>=0)){

			//search record details
			sprintf(csBatchId,"%ld",v_batch_id);
			iRet = process_txn((const char*)csBatchId,(const char*)v_merchant_id.arr,hContext,hRequest);
			PutField_Int(hRequest,"batch_cnt",iBatchCnt);

			sprintf(csTag,"batch_id_%d",iBatchCnt);
			PutField_CString(hContext,csTag,csBatchId);

			iBatchCnt++;
		}
	
	}while(PD_TRUE);

	GetField_Int(hRequest,"total_record",&iTotalCnt);

	if(iTotalCnt!=0){
//DEBUGLOG(("send BatchOnlineWithdrawAll [%d]:Total Amt[%d]\n",iTotalCnt,iTotalAmt));
		iRet = BatchOnlineWithdrawAll(hContext,hRequest);
DEBUGLOG(("BatchOnlineWithdrawAll RET = [%d]\n",iRet));
	}
	else{
		iRet = PD_SKIP_OK;
	}

	if(iRet == PD_OK){
		iStatus = PD_PAYOUTFILE_GENERATED;
	}
	else{
		iStatus = PD_PAYOUTFILE_DECLINED;
	}

	if(iRet!=PD_SKIP_OK){
		for(i=0;i<iBatchCnt;i++){
			PutField_Int(hContext,"status",iStatus);

			sprintf(csTag,"batch_id_%d",i);
			GetField_CString(hContext,csTag,&csTmp);
			PutField_CString(hContext,"batch_id",csTmp);

// update header status to  1 / 5 
			DBObjPtr = CreateObj(DBPtr,"DBMerchantUploadFileHeader","UpdateHeader");
			if((unsigned long int)(*DBObjPtr)(hContext) == PD_OK){
DEBUGLOG(("Update Payout Header Status Success: batch_id[%s]\n",csTmp));
				iRet = PD_OK;
			}
			else{
DEBUGLOG(("Update Payout Header Status Failed: batch_id[%s]\n",csTmp));
			}
		}
	}

	if(iStatus==PD_PAYOUTFILE_DECLINED){
		iRet = PD_SKIP_OK;
	}


	return iRet;

head_error:
    DEBUGLOG(("process_header error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getheader; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 2;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )51;
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
}


    return FAILURE;

}

int process_txn(const char* csBatchId, const char* csMerchId, hash_t *hContext,hash_t *hRequest)
{               
        int     iRet = PD_ERR;
	int	iTotalCnt = 0;
	char	csAmt[PD_AMOUNT_LEN+1];
	char	csTag[PD_TMP_TAG_LEN +1];
        
        /* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		
		int	hv_status;
		long	hv_batch_id;
		char	hv_batch_mode;
		int	hv_disabled;

		int	v_seq_num;
		/* varchar	v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar	v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar	v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		/* varchar	v_identity_id[PD_IDENTITY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_identity_id;

		/* varchar	v_account_num[PD_ACCOUNT_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_account_num;

		/* varchar	v_account_name[PD_ACCOUNT_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_account_name;

		/* varchar	v_bank_name[PD_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_name;

		/* varchar	v_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

		/* varchar	v_branch[PD_BANK_BRANCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_branch;

		/* varchar	v_phone[PD_MOBILE_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_phone;

		/* varchar	v_province[PD_PROVINCE_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } v_province;

		/* varchar	v_city[PD_CITY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_city;

		//varchar	v_amount[PD_AMOUNT_LEN+1];
		/* varchar	v_payout_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_payout_ccy;

		/* varchar	v_dest_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_dest_ccy;

		double	v_amount;

		short	ind_seq_num = -1;
		short	ind_txn_id= -1;
		short   ind_merchant_ref = -1;
		short   ind_country = -1;
		short	ind_identity_id = -1;
		short	ind_account_num	= -1;
		short	ind_account_name = -1;
		short	ind_bank_name = -1;
		short	ind_bank_code = -1;
		short	ind_branch = -1;
		short	ind_phone= -1;
		short	ind_city = -1;
		short	ind_province = -1;
		short	ind_amount = -1;
		short   ind_payout_ccy = -1;
		short   ind_dest_ccy = -1;


	/* EXEC SQL END DECLARE SECTION; */ 


	hv_batch_id = ctol((const unsigned char *)csBatchId,strlen(csBatchId));
DEBUGLOG(("process_txn::batch_id = [%ld]\n",hv_batch_id));

	hv_status = PAYOUT_MASTER_TRANSACTION_APPROVED;
	hv_batch_mode = PD_ONLINE;       
	hv_disabled = 0;

	GetField_Int(hRequest,"total_record",&iTotalCnt);	

	/* EXEC SQL DECLARE c_cursor_gettxn CURSOR FOR
		select	ud_seq_num,
			ud_txn_id,
		 	ud_merchant_ref,
         		ud_country,
         		ud_identity_id,
         		ud_account_name,
         		ud_account_num,
         		ud_bank_name,
         		ud_bank_code,
         		ud_branch,
         		ud_phone_num,
         		ud_province,
         		ud_city,
         		ud_payout_amount,
         		ud_payout_currency,
         		ud_request_currency
  		   from merchant_upload_file_detail
		  where ud_status = :hv_status
		  and	ud_batch_mode = :hv_batch_mode
		  and	ud_disabled = :hv_disabled
		  and	ud_batch_id = :hv_batch_id; */ 

                
        /* EXEC SQL OPEN c_cursor_gettxn; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0003;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )81;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_mode;
        sqlstm.sqhstl[1] = (unsigned long )1;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_disabled;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(long);
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
        if (sqlca.sqlcode < 0) goto sql_error;
}


        do {    
                /* EXEC SQL FETCH c_cursor_gettxn
                INTO
			:v_seq_num:ind_seq_num,
			:v_txn_id:ind_txn_id,
			:v_merchant_ref:ind_merchant_ref,
			:v_country:ind_country,
			:v_identity_id:ind_identity_id,
			:v_account_name:ind_account_name,
			:v_account_num:ind_account_num,
			:v_bank_name:ind_bank_name,
			:v_bank_code:ind_bank_code,
			:v_branch:ind_branch,
			:v_phone:ind_phone,
			:v_province:ind_province,
			:v_city:ind_city,
			:v_amount:ind_amount,
			:v_payout_ccy:ind_payout_ccy,
			:v_dest_ccy:ind_dest_ccy; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 16;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )112;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_seq_num;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_seq_num;
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
                sqlstm.sqhstv[2] = (unsigned char  *)&v_merchant_ref;
                sqlstm.sqhstl[2] = (unsigned long )53;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_merchant_ref;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_country;
                sqlstm.sqhstl[3] = (unsigned long )5;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_country;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_identity_id;
                sqlstm.sqhstl[4] = (unsigned long )28;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_identity_id;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_account_name;
                sqlstm.sqhstl[5] = (unsigned long )33;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_account_name;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_account_num;
                sqlstm.sqhstl[6] = (unsigned long )33;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_account_num;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_bank_name;
                sqlstm.sqhstl[7] = (unsigned long )53;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_bank_name;
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
                sqlstm.sqhstv[9] = (unsigned char  *)&v_branch;
                sqlstm.sqhstl[9] = (unsigned long )53;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_branch;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_phone;
                sqlstm.sqhstl[10] = (unsigned long )28;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_phone;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_province;
                sqlstm.sqhstl[11] = (unsigned long )22;
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_province;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
                sqlstm.sqhstv[12] = (unsigned char  *)&v_city;
                sqlstm.sqhstl[12] = (unsigned long )23;
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_city;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
                sqlstm.sqhstv[13] = (unsigned char  *)&v_amount;
                sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[13] = (         int  )0;
                sqlstm.sqindv[13] = (         short *)&ind_amount;
                sqlstm.sqinds[13] = (         int  )0;
                sqlstm.sqharm[13] = (unsigned long )0;
                sqlstm.sqadto[13] = (unsigned short )0;
                sqlstm.sqtdso[13] = (unsigned short )0;
                sqlstm.sqhstv[14] = (unsigned char  *)&v_payout_ccy;
                sqlstm.sqhstl[14] = (unsigned long )6;
                sqlstm.sqhsts[14] = (         int  )0;
                sqlstm.sqindv[14] = (         short *)&ind_payout_ccy;
                sqlstm.sqinds[14] = (         int  )0;
                sqlstm.sqharm[14] = (unsigned long )0;
                sqlstm.sqadto[14] = (unsigned short )0;
                sqlstm.sqtdso[14] = (unsigned short )0;
                sqlstm.sqhstv[15] = (unsigned char  *)&v_dest_ccy;
                sqlstm.sqhstl[15] = (unsigned long )6;
                sqlstm.sqhsts[15] = (         int  )0;
                sqlstm.sqindv[15] = (         short *)&ind_dest_ccy;
                sqlstm.sqinds[15] = (         int  )0;
                sqlstm.sqharm[15] = (unsigned long )0;
                sqlstm.sqadto[15] = (unsigned short )0;
                sqlstm.sqtdso[15] = (unsigned short )0;
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
		
		iRet = PD_OK;


/*seq_num*/
		if(ind_seq_num>=0){
			sprintf(csTag,"seq_num_%d",iTotalCnt);	
			PutField_Int(hRequest,csTag,v_seq_num);
		}

/* merchant_id */
		sprintf(csTag,"merchant_id_%d",iTotalCnt);	
		PutField_CString(hRequest,csTag,csMerchId);
		PutField_CString(hRequest,"merchant_id",csMerchId);
DEBUGLOG(("process_txn:: merchant_id_%d = [%s]\n",iTotalCnt,csMerchId));

/*txn_id*/
		if(ind_txn_id>=0){
			v_txn_id.arr[v_txn_id.len] = '\0';
			sprintf(csTag,"txn_seq_%d",iTotalCnt);	
			PutField_CString(hRequest,csTag,(const char*)v_txn_id.arr);
		}


/* merchant_ref */
		if(ind_merchant_ref>=0){
			v_merchant_ref.arr[v_merchant_ref.len] = '\0';
			sprintf(csTag,"reference_%d",iTotalCnt);	
			PutField_CString(hRequest,csTag,(const char*)v_merchant_ref.arr);
		}


/* pay_amount */
		if(ind_amount>=0){
			sprintf(csTag,"pay_amount_%d",iTotalCnt);
			//PutField_Double(hContext,csTag,v_amount);

			sprintf(csAmt,"%ld",double2long(v_amount));
			PutField_CString(hRequest,csTag,csAmt);
		}

/* currency_code */
		sprintf(csTag,"currency_code_%d",iTotalCnt);	
		PutField_CString(hRequest,csTag,"TWD");
		PutField_CString(hRequest,"txn_ccy","TWD");

/* country */
		if(ind_country>=0){
			v_country.arr[v_country.len] = '\0';
			sprintf(csTag,"country_%d",iTotalCnt);	
			PutField_CString(hRequest,csTag,(const char*)v_country.arr);
			PutField_CString(hRequest,"country",(const char*)v_country.arr);
		}

/* bank_code */
		if(ind_bank_code>=0){
			v_bank_code.arr[v_bank_code.len] = '\0';
			sprintf(csTag,"bank_code_%d",iTotalCnt);	
			PutField_CString(hRequest,csTag,(const char*)v_bank_code.arr);
		}

/* bank_name */
		if(ind_bank_name>=0){
			v_bank_name.arr[v_bank_name.len] = '\0';
			sprintf(csTag,"bank_name_%d",iTotalCnt);	
			PutField_CString(hRequest,csTag,(const char*)v_bank_name.arr);
		}


/* branch */
		if(ind_branch>=0){
			v_branch.arr[v_branch.len] = '\0';
			sprintf(csTag,"branch_name_%d",iTotalCnt);	
			PutField_CString(hRequest,csTag,(const char*)v_branch.arr);
		}

/* account_id */
		if(ind_account_num>=0){
			v_account_num.arr[v_account_num.len] = '\0';
			sprintf(csTag,"account_id_%d",iTotalCnt);	
			PutField_CString(hRequest,csTag,(const char*)v_account_num.arr);
		}

/* account_name */
		if(ind_account_name>=0){
			v_account_name.arr[v_account_name.len] = '\0';
			sprintf(csTag,"account_name_%d",iTotalCnt);	
			PutField_CString(hRequest,csTag,(const char*)v_account_name.arr);
		}

/* identity_id */
		if(ind_identity_id>=0){
			v_identity_id.arr[v_identity_id.len] = '\0';
			sprintf(csTag,"identity_id_%d",iTotalCnt);	
			PutField_CString(hRequest,csTag,(const char*)v_identity_id.arr);
		}

/* batch_id */
		sprintf(csTag,"batch_id_%d",iTotalCnt);	
		PutField_CString(hRequest,csTag,csBatchId);

		iTotalCnt++;


	}while(PD_TRUE);

	PutField_Int(hRequest,"total_record",iTotalCnt);

	//FREE_ME(csCcyCode);
	
	/* EXEC SQL CLOSE c_cursor_gettxn; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )191;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto sql_error;
}


	return iRet;
sql_error:
    DEBUGLOG(("process_txn error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_gettxn; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 16;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )206;
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
    sqlstm.arrsiz = 16;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )221;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}


int BatchOnlineWithdrawAll(hash_t* hContext,hash_t* hRequest) 
{
	int	iRet = PD_OK;
	char	*csPtr;
	char	csTag[PD_TAG_LEN +1];
	//char	*csMerchantId,*csMerchantRef;
	char	csTmp[ PD_TMP_BUF_LEN + 1];
	//char	*csTxnSeq;
	char	*csURL;
	double	dTmp;
	int	iBatchCnt;

	char*	csCode;
	char*	csValue;
	recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	hash_t *hRps;
	hash_t  *hRec;

        hRps = (hash_t*) malloc (sizeof(hash_t));


	int	iTotal,i;

	GetField_Int(hRequest,"batch_cnt",&iBatchCnt);

/* update context */

        DBObjPtr = CreateObj(DBPtr,"DBSystemControl","GetAllCodes");
        if ((*DBObjPtr)(rRecordSet) == PD_OK) {
DEBUGLOG(("UpdateContext: return \n"));
                hRec = RecordSet_GetFirst(rRecordSet);
                while (hRec) {
                        if (GetField_CString(hRec,"code",&csCode)) {
                                if (GetField_CString(hRec,"value",&csValue)) {
                                        if (!strcmp(csCode,"CTPHDATE")) {
DEBUGLOG(("UpdateContext:Current Processor Hub Date= [%s]\n",csValue));
                                                PutField_CString(hContext,"PHDATE",csValue);
                                        }
                                }
                        }
                        hRec = RecordSet_GetNext(rRecordSet);
                }
        }
        else {
DEBUGLOG(("UpdateContext:NOT RECORD\n"));
                iRet = PD_ERR;
ERRLOG("Internal Error:WEB Channel:SystemControl Record Not Found\n");
        }

        if (iRet == PD_OK) {
                DBObjPtr = CreateObj(DBPtr,"DBSystemParameter","FindCode");
                if ((unsigned long)(DBObjPtr)(PD_BASED_CCY,csValue) == FOUND) {
DEBUGLOG(("based ccy  = [%s]\n",csValue));
                        PutField_CString(hContext,"based_ccy",csValue);
                }
                else {
                        iRet = INT_ERR;
ERRLOG("Unable to find based ccy\n");
                }
        }
	

	RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);

	PutField_CString(hContext,"txn_code", PD_WITHDRAW_BATCH_TXN_CODE);
	PutField_CString(hContext,"channel_code","WEB");
	GetField_Int(hRequest,"total_record",&iTotal);

DEBUGLOG(("BatchOnlineWithdrawAll: total = [%d]\n",iTotal));


	for (i = 0 ; i < iTotal; i++) {

        	hash_init(hRps,0);


/* merchant_id */
		sprintf(csTag,"merchant_id_%d",i);
		if (GetField_CString(hRequest,csTag,&csPtr)) {
DEBUGLOG(("BatchOnlineWithdrawAll: [%s] = [%s]\n",csTag,csPtr));
			PutField_CString(hRequest,"merchant_id",csPtr);
			//csMerchantId = strdup(csPtr);
		}

/* merchant_ref */
		sprintf(csTag,"reference_%d",i);
		if (GetField_CString(hRequest,csTag,&csPtr)) {
DEBUGLOG(("BatchOnlineWithdrawAll: [%s] = [%s]\n",csTag,csPtr));
			PutField_CString(hRequest,"merchant_ref",csPtr);
			//csMerchantRef = strdup(csPtr);
		}
/* transaction_datetime */
		if (GetField_CString(hContext,"PHDATE",&csPtr)) {
DEBUGLOG(("BatchOnlineWithdrawAll: transmission_datetime = [%s]\n",csPtr));
			PutField_CString(hRequest,"transmission_datetime",csPtr);
		}


/* pay_amount */
		sprintf(csTag,"pay_amount_%d",i);
		if (GetField_CString(hRequest,csTag,&csPtr)) {
DEBUGLOG(("BatchOnlineWithdrawAll: [%s] = [%s]\n",csTag,csPtr));
			PutField_CString(hRequest,"txn_amt",csPtr);
		}

/* currency_code */
		sprintf(csTag,"currency_code_%d",i);
		if (GetField_CString(hRequest,csTag,&csPtr)) {
DEBUGLOG(("BatchOnlineWithdrawAll: [%s] = [%s]\n",csTag,csPtr));
			PutField_CString(hRequest,"txn_ccy",csPtr);
		}

/* country */
		sprintf(csTag,"country_%d",i);
		if (GetField_CString(hRequest,csTag,&csPtr)) {
DEBUGLOG(("BatchOnlineWithdrawAll: [%s] = [%s]\n",csTag,csPtr));
			PutField_CString(hRequest,"txn_country",csPtr);
		}

/* bank_code */
		sprintf(csTag,"bank_code_%d",i);
		if (GetField_CString(hRequest,csTag,&csPtr)) {
DEBUGLOG(("BatchOnlineWithdrawAll: [%s] = [%s]\n",csTag,csPtr));
			PutField_CString(hRequest,"bank_code",csPtr);
		}


/* branch_name */
		sprintf(csTag,"branch_name_%d",i);
		if (GetField_CString(hRequest,csTag,&csPtr)) {
DEBUGLOG(("BatchOnlineWithdrawAll: [%s] = [%s]\n",csTag,csPtr));
			PutField_CString(hRequest,"branch_name",csPtr);
		}

/* account_id */
		sprintf(csTag,"account_id_%d",i);
		if (GetField_CString(hRequest,csTag,&csPtr)) {
DEBUGLOG(("BatchOnlineWithdrawAll: [%s] = [%s]\n",csTag,csPtr));
			PutField_CString(hRequest,"account_id",csPtr);
		}

/* account_name */
		sprintf(csTag,"account_name_%d",i);
		if (GetField_CString(hRequest,csTag,&csPtr)) {
DEBUGLOG(("BatchOnlineWithdrawAll: [%s] = [%s]\n",csTag,csPtr));
			PutField_CString(hRequest,"account_name",csPtr);
		}


/* identity_id */
		sprintf(csTag,"identity_id_%d",i);
		if (GetField_CString(hRequest,csTag,&csPtr)) {
DEBUGLOG(("BatchOnlineWithdrawAll: [%s] = [%s]\n",csTag,csPtr));
			PutField_CString(hRequest,"identity_id",csPtr);
		}

/* batch_id */
		sprintf(csTag,"batch_id_%d",i);
		if (GetField_CString(hRequest,csTag,&csPtr)) {
DEBUGLOG(("BatchOnlineWithdrawAll: [%s] = [%s]\n",csTag,csPtr));
			PutField_CString(hRequest,"batch_id",csPtr);
		}

/*pay_method*/ ////////////hard code
DEBUGLOG(("BatchOnlineWithdrawAll: pay_method = [%s]\n","002"));
		PutField_CString(hRequest,"pay_method","002");

		 if (iRet == PD_OK) {
DEBUGLOG(("BatchOnlineWithdrawAll call TxnWebOnUsCOM\n"));
                        TxnObjPtr = CreateObj(TxnPtr,"TxnWebOnUsCOM","Authorize");
                        iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hRps);
                        if (GetField_Double(hContext,"dst_net_amt",&dTmp)) {
                                sprintf(csTag,"psp_txn_amt_%d",i);
                                PutField_Double(hRequest,csTag,dTmp);
DEBUGLOG(("BatchOnlineWithdrawAll::TxnWebOnUsCOM:Authorize: [%s]=[%lf]\n",csTag,dTmp));
                        }
                }       

		hash_destroy(hRps);

/* put response to request */
                sprintf(csTag,"internal_error_%d",i);
                PutField_Int(hRequest,csTag,iRet);
DEBUGLOG(("BatchOnlineWithdrawAll: [%s] = [%d]\n",csTag,iRet));
                iRet = PD_OK; 
	}
	FREE_ME(hRps);

        if (iRet == PD_OK) {

/* psp Url */
	        if (GetField_CString(hContext,"psp_url",&csURL)) {
DEBUGLOG(("BatchOnlineWithdrawAll: psp_url = [%s]\n",csURL));
        	}
/* request_function */
        	if (GetField_CString(hContext,"request_function",&csPtr)) {
DEBUGLOG(("BatchOnlineWithdrawAll: request_function = [%s]\n",csPtr));
			strcpy(csTmp,csURL);
			strcat(csTmp,"/");
			strcat(csTmp,csPtr);
			PutField_CString(hRequest,"URL",csTmp);
DEBUGLOG(("BatchOnlineWithdrawAll: URL = [%s]\n",csTmp));
        	}

/* action */
        	if (GetField_CString(hContext,"action",&csPtr)) {
DEBUGLOG(("BatchOnlineWithdrawAll: action = [%s]\n",csPtr));
			strcpy(csTmp,csURL);
			strcat(csTmp,"/");
			strcat(csTmp,csPtr);
			PutField_CString(hRequest,"action",csTmp);
//DEBUGLOG(("BatchOnlineWithdrawAll: action = [%s]\n",csTmp));
        	}

/* access_key */
        	if (GetField_CString(hContext,"psp_key",&csPtr)) {
DEBUGLOG(("BatchOnlineWithdrawAll: access_key = [%s]\n",csPtr));
			PutField_CString(hRequest,"access_key",csPtr);
        	}
/*      
        	for (i = 0; i < iTotal; i ++ ) {
// txn_seq    
                	DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextBatchTxnSeq");
                	sprintf(csTag,"txn_seq_%d",i);
                	csTxnSeq  = strdup((*DBObjPtr)());
DEBUGLOG(("BatchOnlineWithdrawAll: %s = [%s]\n",csTag,csTxnSeq));
                	PutField_CString(hRequest,csTag,csTxnSeq);
                
                
        	}
*/
		iRet = AddWTBTxnLog(hContext,hRequest);

	}

	return iRet;
}



int     AddWTBTxnLog(const hash_t *hContext,
                	hash_t* hRequest)

{
        int iRet = PD_OK;
	int	iTotal,i;
	int	iInternalErr = 0;

        char    *csTmp = strdup("");
	char	csTag[PD_TAG_LEN +1];
        char	*csBatchId;
	int	iSeqNum;

	GetField_Int(hRequest,"total_record",&iTotal);
DEBUGLOG(("AddTxnLog:: total_record = [%d]\n",iTotal));

	for (i = 0; i < iTotal; i++) {

		sprintf(csTag,"internal_error_%d",i);
		GetField_Int(hRequest,csTag,&iInternalErr);
DEBUGLOG(("AddTxnLog: %s = [%d]\n",csTag,iInternalErr));

		if (iInternalErr == INT_DUP_MERCHANT_REF)
			continue; //skip
		
		sprintf(csTag,"batch_id_%d",i);
DEBUGLOG(("try to get %s\n",csTag));
        	if (GetField_CString(hRequest,csTag,&csBatchId)) {
DEBUGLOG(("AddTxnLog:: batch_id = [%s]\n",csBatchId));

			sprintf(csTag,"seq_num_%d",i);
			if (GetField_Int(hRequest,csTag,&iSeqNum)) {
DEBUGLOG(("AddTxnLog:: seq_num = [%d]\n",iSeqNum));
                        }
                
                	PutField_CString(hRequest,"add_user",PD_UPDATE_USER);

                	PutField_Int(hRequest,"status",PAYOUT_MASTER_TRANSACTION_TO_PSP);

                        DBObjPtr = CreateObj(DBPtr,"DBMerchantUploadFileDetail","UpdateDetailByBatchId");
                        iRet = (unsigned long) ((*DBObjPtr)(csBatchId,iSeqNum,hRequest));

        	}
        	else
                	iRet = PD_ERR;
	}

        FREE_ME(csTmp);
DEBUGLOG(("AddTxnLog RET = [%d]\n",iRet));
        return  iRet;

}
        
int     UpdatePreTWVRespTxnLog(hash_t *hContext,
                        hash_t* hResponse)

{
        int     iRet = PD_OK;
        char    *csTmp;
        char    csStatus[PD_TAG_LEN +1];
	char	csTag[PD_TAG_LEN +1];
	char	*csTxnId;
	int	iTotal = 0,i;
	int	iStatus;
	int	iBatchId;

        hash_t  *hTxn;
        hTxn = (hash_t*)  malloc (sizeof(hash_t));

DEBUGLOG(("OnlinePayout::UpdateRespTxnLog()\n"));

	if (GetField_Int(hResponse,"total_record",&iTotal)) {
		for (i = 0 ; i < iTotal; i++) {
        		hash_init(hTxn,0);
			iStatus = 0;
			iBatchId = 0;
/* txn_seq from response */
			sprintf(csTag,"txn_seq_%d",i);
	        	if (GetField_CString(hResponse,csTag,&csTxnId)) {
DEBUGLOG(("UpdateTxnLog RESP:: %s = [%s]\n",csTag,csTxnId));
       	         		PutField_CString(hTxn,"txn_seq",csTxnId);
       			}
/* tid*/
			sprintf(csTag,"tid_%d",i);
        		if (GetField_CString(hResponse,csTag,&csTmp)) {
DEBUGLOG(("UpdateTxnLog RESP:: %s = [%s]\n",csTag,csTmp));
                		PutField_CString(hTxn,"tid",csTmp);
        		}

/* status */    
			sprintf(csTag,"record_status_%d",i);
        		if (GetField_Int(hResponse,csTag,&iStatus)) {
DEBUGLOG(("UpdateTxnLog RESP:: %s = [%d]\n",csTag,iStatus))
				
				sprintf(csStatus,"%d",iStatus);
                		PutField_CString(hTxn,"resp_code",csStatus);

				if(iStatus!=1){
					///void payout txn
					TxnObjPtr = CreateObj(TxnPtr,"TxnWebOnUsWTV","Authorize");
					iRet = (unsigned long)(*TxnObjPtr)(hContext,hTxn,hResponse);
				}
        		}

/* batch_id */  
        		if (GetField_Int(hResponse,"psp_batch_id",&iBatchId)) {
DEBUGLOG(("UpdateTxnLog RESP:: psp_batch_id = [%d]\n",iBatchId))
				sprintf(csTag,"%d",iBatchId);
                		PutField_CString(hTxn,"psp_batch_id",csTag);
        		}
                

                	DBObjPtr = CreateObj(DBPtr,"DBMerchantUploadFileDetail","UpdateDetailByTxnId");
                	iRet = (unsigned long)(*DBObjPtr)(csTxnId,hTxn);
DEBUGLOG(("UpdateTxnLog RESP::DBMerchantUploadFileDetail:UpdateDetailByTxnId iRet = [%d]\n",iRet));
        


        		hash_destroy(hTxn);
		}
	}
        FREE_ME(hTxn);

DEBUGLOG(("UpdateRespTxnLog Exit [%d]\n",iRet));
        return iRet;
}
