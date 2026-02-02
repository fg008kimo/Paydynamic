
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
           char  filnam[28];
};
static struct sqlcxp sqlfpn =
{
    27,
    "MerchantUploadFileHeader.pc"
};


static unsigned int sqlctx = 1437150651;


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
   unsigned char  *sqhstv[10];
   unsigned long  sqhstl[10];
            int   sqhsts[10];
            short *sqindv[10];
            int   sqinds[10];
   unsigned long  sqharm[10];
   unsigned long  *sqharc[10];
   unsigned short  sqadto[10];
   unsigned short  sqtdso[10];
} sqlstm = {12,10};

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
"select uh_merchant_id , uh_service_code , uh_filename , uh_status , uh_txn_\
count , uh_total_txn_amt , uh_posting_date from merchant_upload_file_header w\
here uh_batch_id = :b0 AND uh_disabled = :b1            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,0,0,17,111,0,0,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,21,112,0,0,0,0,0,1,0,
39,0,0,2,208,0,9,179,0,2049,2,2,0,1,0,1,68,0,0,1,3,0,0,
62,0,0,2,0,0,13,181,0,0,7,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,4,
0,0,2,9,0,0,
105,0,0,2,0,0,15,248,0,0,0,0,0,1,0,
120,0,0,2,0,0,15,258,0,0,0,0,0,1,0,
135,0,0,3,323,0,6,370,0,0,10,10,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,3,0,0,1,4,0,0,1,3,0,0,1,9,0,0,
190,0,0,4,88,0,4,426,0,0,1,0,0,1,0,2,9,0,0,
209,0,0,5,76,0,6,464,0,0,2,2,0,1,0,2,3,0,0,1,9,0,0,
232,0,0,6,122,0,4,522,0,0,3,2,0,1,0,2,9,0,0,1,9,0,0,1,3,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/08/22              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "MerchantUploadFileHeader.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "internal.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void MerchantUploadFileHeader(char    cdebug)
{
        cDebug = cdebug;
}


int UpdateHeader(const hash_t *hRls)
{
	char*   csBuf;
	char*	csBatchId;
	int	iTmp = 0;
	double	dTmp = 0.0;

	/* EXEC SQL WHENEVER SQLERROR GOTO updatehd_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar		hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateHeader: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update merchant_upload_file_header set uh_update_timestamp = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	if(GetField_CString(hRls,"batch_id",&csBatchId)){
DEBUGLOG(("UpdateHeader:batch_id = [%s]\n",csBatchId));
	}
	else{
		FREE_ME(csBuf);
DEBUGLOG(("UpdateHeader batch_id not found\n"));
        	return INT_ERR;
	}

	if(GetField_Int(hRls,"status",&iTmp)){
DEBUGLOG(("UpdateHeader:status = [%d]\n",iTmp));
		sprintf(csBuf,"%d",iTmp);
		strcat((char*)hv_dynstmt.arr, ",uh_status =");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	if(GetField_CString(hRls,"update_user",&csBuf)){
DEBUGLOG(("UpdateHeader:update_user = [%s]\n",csBuf));
		strcat((char*)hv_dynstmt.arr, ",uh_update_user = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	if(GetField_CString(hRls,"posting_date",&csBuf)){
DEBUGLOG(("UpdateHeader:posting_date = [%s]\n",csBuf));
		strcat((char*)hv_dynstmt.arr, ",uh_posting_date = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	if(GetField_Int(hRls,"total_txn_cnt",&iTmp)){
DEBUGLOG(("UpdateHeader:total_txn_cnt = [%d]\n",iTmp));
		sprintf(csBuf,"%d",iTmp);
		strcat((char*)hv_dynstmt.arr, ",uh_txn_count =");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	if(GetField_Double(hRls,"total_txn_amt",&dTmp)){
DEBUGLOG(("UpdateHeader:total_txn_amt = [%lf]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",uh_total_txn_amt =");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	
	strcat((char*)hv_dynstmt.arr, " WHERE uh_batch_id = ");
	strcat((char*)hv_dynstmt.arr, csBatchId);
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));


	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
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
 if (sqlca.sqlcode < 0) goto updatehd_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )24;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto updatehd_error;
}



	FREE_ME(csBuf);

DEBUGLOG(("UpdateHeader Normal Exit\n"));
        return PD_OK;

updatehd_error:
DEBUGLOG(("updatehd_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MerchantUploadFileHeader_UpdateHeader: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
        return PD_INTERNAL_ERR;
}



int GetHeader(const unsigned long lBatchId, recordset_t* myRec)
{
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO getpayout_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		unsigned long   hv_batch_id;
		int		hv_disabled;

		/* varchar		v_merchant_id[PD_MERCHANT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar		v_service_code[PD_SERVICE_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		/* varchar		v_filename[PD_FILENAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_filename;

		/* varchar		v_posting_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_posting_date;

		int		v_txn_count;
		double		v_txn_amt;
		int		v_status;

		short           ind_merchant_id = -1;
		short		ind_service_code = -1;
		short		ind_status = -1;
		short		ind_filename = -1;
		short		ind_txn_count = -1;
		short		ind_txn_amt = -1;
		short		ind_posting_date = -1;

	/* EXEC SQL END DECLARE SECTION; */ 

/*
	hv_batch_id.len = strlen(csBatchId);
	memcpy(hv_batch_id.arr,csBatchId,hv_batch_id.len);
DEBUGLOG(("GetTxnHeader batch_id = [%.*s]\n",hv_batch_id.len,hv_batch_id.arr));
*/
	hv_batch_id = lBatchId;
DEBUGLOG(("GetTxnHeader batch_id = [%ld]\n",hv_batch_id));
	
	hv_disabled = 0;

	/* EXEC SQL DECLARE c_cursor_getpayout CURSOR FOR
		select	uh_merchant_id,
			uh_service_code,
			uh_filename,
			uh_status,
			uh_txn_count,
			uh_total_txn_amt,
			uh_posting_date
		from	merchant_upload_file_header
		where	uh_batch_id =:hv_batch_id
		AND	uh_disabled =:hv_disabled; */ 


	/* EXEC SQL OPEN  c_cursor_getpayout; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )39;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto getpayout_error;
}


	do{
		/* EXEC SQL FETCH c_cursor_getpayout
		INTO
			:v_merchant_id:ind_merchant_id,
			:v_service_code:ind_service_code,
			:v_filename:ind_filename,
			:v_status:ind_status,
			:v_txn_count:ind_txn_count,
			:v_txn_amt:ind_txn_amt,
			:v_posting_date:ind_posting_date; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )62;
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
  sqlstm.sqhstv[1] = (unsigned char  *)&v_service_code;
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_service_code;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_filename;
  sqlstm.sqhstl[2] = (unsigned long )53;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_filename;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_status;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_txn_count;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_txn_count;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_txn_amt;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_txn_amt;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_posting_date;
  sqlstm.sqhstl[6] = (unsigned long )11;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_posting_date;
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
  if (sqlca.sqlcode < 0) goto getpayout_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

/*merchant_id*/
		if(ind_merchant_id>=0){
			v_merchant_id.arr[v_merchant_id.len]='\0';
			PutField_CString(myHash,"merchant_id",(const char*)v_merchant_id.arr);
DEBUGLOG(("GetHeader merchant_id=[%s]\n",v_merchant_id.arr));
		}

/*service_code*/
		if(ind_service_code>=0){
			v_service_code.arr[v_service_code.len]='\0';
			PutField_CString(myHash,"service_code",(const char*)v_service_code.arr);
DEBUGLOG(("GetHeader service_code=[%s]\n",v_service_code.arr));
		}

/*filename*/
		if(ind_filename>=0){
			v_filename.arr[v_filename.len]='\0';
			PutField_CString(myHash,"filename",(const char*)v_filename.arr);
DEBUGLOG(("GetHeader filename = [%s]\n",v_filename.arr));
		}

/*status*/
		if(ind_status>=0){
			PutField_Int(myHash,"status",v_status);
DEBUGLOG(("GetHeader status = [%d]\n",v_status));
		}

/*txn_count*/
		if(ind_txn_count>=0){
			PutField_Int(myHash,"txn_count",v_txn_count);
DEBUGLOG(("GetHeader txn_count = [%d]\n",v_txn_count));
		}

/*txn_amt*/
		if(ind_txn_amt>=0){
			PutField_Double(myHash,"txn_amt",v_txn_amt);
DEBUGLOG(("GetHeader txn_amt= [%lf]\n",v_txn_amt));
		}

/*posting_date*/
		if(ind_posting_date>=0){
			v_posting_date.arr[v_posting_date.len]='\0';
			PutField_CString(myHash,"posting_date",(const char*)v_posting_date.arr);
DEBUGLOG(("GetHeader posting_date = [%s]\n",v_posting_date.arr));
		}

		RecordSet_Add(myRec,myHash);

	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getpayout; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )105;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getpayout_error;
}



DEBUGLOG(("GetHeader Normal Exit\n"));
	return  PD_OK;

getpayout_error:
DEBUGLOG(("getpayout_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MerchantUploadFileHeader_Get: SP_INTERNAL_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getpayout; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )120;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;

}


int     Add(const hash_t *hRls)
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

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_service_code;

                /* varchar         hv_filename[PD_FILENAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } hv_filename;

                /* varchar         hv_posting_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } hv_posting_date;

                int             hv_txn_count;
                double          hv_txn_amt;
                int             hv_status;
                /* varchar         hv_user[PD_USER_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_user;


		short           ind_batch_id = -1;
		short           ind_merchant_id = -1;
		short		ind_service_code = -1;
		short		ind_status = -1;
		short		ind_filename = -1;
		short		ind_txn_count = -1;
		short		ind_txn_amt = -1;
		short		ind_posting_date = -1;
		short		ind_user = -1;

		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("Add: Begin\n"));

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

/*user*/
        if(GetField_CString(hRls,"add_user",&csTmp)){
                hv_user.len = strlen(csTmp);
                memcpy(hv_user.arr, csTmp, hv_user.len);
                ind_user= 0;
DEBUGLOG(("Add:user = [%.*s]\n",hv_user.len,hv_user.arr));
        }

	/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_merch_upload_hd_insert(
                                        :hv_batch_id:ind_batch_id,
                                        :hv_posting_date:ind_posting_date,
                                        :hv_merchant_id:ind_merchant_id,
                                        :hv_service_code:ind_service_code,
                                        :hv_filename:ind_filename,
                                        :hv_txn_count:ind_txn_count,
                                        :hv_txn_amt:ind_txn_amt,
                                        :hv_status:ind_status,
                                        :hv_user:ind_user);
                END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merch_upload_hd_insert ( :hv_b\
atch_id:ind_batch_id , :hv_posting_date:ind_posting_date , :hv_merchant_id:in\
d_merchant_id , :hv_service_code:ind_service_code , :hv_filename:ind_filename\
 , :hv_txn_count:ind_txn_count , :hv_txn_amt:ind_txn_amt , :hv_status:ind_sta\
tus , :hv_user:ind_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )135;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_posting_date;
 sqlstm.sqhstl[2] = (unsigned long )11;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_posting_date;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[3] = (unsigned long )17;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )6;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_service_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_filename;
 sqlstm.sqhstl[5] = (unsigned long )53;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_filename;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_txn_count;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_txn_count;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_txn_amt;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_txn_amt;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_status;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_user;
 sqlstm.sqhstl[9] = (unsigned long )23;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_user;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
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
                ERRLOG("MerchantUploadFileHeader_Add: SP_OTHER_ERR \n");
                DEBUGLOG(("Add: SP_OTHER_ERR \n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
                ERRLOG("MerchantUploadFileHeader_Add: SP_ERR \n");
                DEBUGLOG(("Add: SP_ERR \n"));
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MerchantUploadFileHeader_Add: SP_INTERNAL_ERR \n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

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
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select NVL ( max ( uh_batch_id ) , 0 ) + 1 INTO :b0:\
b1 FROM merchant_upload_file_header ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )190;
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

int Delete(const unsigned char* batch_id)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO delete_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;


                short   hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_batch_id.len = strlen((const char*)batch_id);
        memcpy(hv_batch_id.arr,batch_id,hv_batch_id.len);
DEBUGLOG(("Delete: batch_id = [%.*s]\n",hv_batch_id.len,hv_batch_id.arr));

        /* EXEC SQL EXECUTE
            BEGIN

                :hv_return_value := sp_merch_upload_hd_delete(
                                :hv_batch_id);

            END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_merch_upload_hd_delete \
( :hv_batch_id ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )209;
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
        if (sqlca.sqlcode < 0) goto delete_error;
}




DEBUGLOG(("Delete:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("Delete:Normal Exit\n"));
                return PD_OK;
        }
        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MerchantUploadFileHeader_Delete: SP_OTHER_ERR\n");
DEBUGLOG(("Delete: SP_OTHER_ERR\n"));
                return PD_OTHER_ERR;
        }
        if (hv_return_value == SP_ERR)  {
ERRLOG("MerchantUploadFileHeader_Delete: SP_ERR\n");
DEBUGLOG(("Delete: SP_ERR\n"));
                return PD_ERR;
        }

delete_error:
DEBUGLOG(("delete_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MerchantUploadFileHeader_Delete: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}

int MatchBatchStatus_ForUpdate(const char* csBatchId,
                 	       const int iStatus)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO MatchBatchStatus_ForUpdate_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;

                int             hv_status;

                /* varchar         v_merchant_id[PD_MERCHANT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

                short           ind_merchant_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_batch_id.len = strlen(csBatchId);
        memcpy(hv_batch_id.arr,csBatchId,hv_batch_id.len);
DEBUGLOG(("MatchBatchStatus_ForUpdate batch_id = [%.*s]\n",hv_batch_id.len,hv_batch_id.arr));

        hv_status = iStatus;
DEBUGLOG(("MatchBatchStatus_ForUpdate status = [%d]\n",hv_status));

        /* EXEC SQL SELECT uh_merchant_id
                INTO    :v_merchant_id:ind_merchant_id
                FROM    merchant_upload_file_header
                WHERE   uh_batch_id = :hv_batch_id
                and     uh_status = :hv_status
                for update; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select uh_merchant_id INTO :b0:b1 FROM merchant_uplo\
ad_file_header WHERE uh_batch_id = :b2 and uh_status = :b3 for update ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )232;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_merchant_id;
        sqlstm.sqhstl[0] = (unsigned long )18;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_merchant_id;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[1] = (unsigned long )18;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_status;
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
        if (sqlca.sqlcode < 0) goto MatchBatchStatus_ForUpdate_error;
}




        if(ind_merchant_id>=0){
DEBUGLOG(("MatchBatchStatus_ForUpdate Found\n"));
                return PD_FOUND;
        }
        else {
DEBUGLOG(("MatchBatchStatus_ForUpdate Not Found\n"));
                return PD_NOT_FOUND;
        }


MatchBatchStatus_ForUpdate_error:
DEBUGLOG(("MatchBatchStatus_ForUpdate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}
