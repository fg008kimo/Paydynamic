
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
    "OLDepositRequest.pc"
};


static unsigned int sqlctx = 40001739;


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

 static char *sq0004 = 
"SELECT OLDD_DEPOSIT_SEQ , OLDD_INT_BANK_CODE , OLDD_BANK_ACCT_NUM , OLDD_SE\
RVICE_CODE , OLDD_COUNTRY , OLDD_MERCHANT_REF , OLDD_CUST_DEPOSIT_DATETIME , \
OLDD_DEPOSIT_BANK , OLDD_DEPOSIT_REF , OLDD_DEPOSIT_AMOUNT , OLDD_DEPOSIT_CCY\
 , OLDD_DEPOSIT_FLOW , OLDD_CUST_DEPOSIT_DT_PROV FROM OL_DEPOSIT_REQUEST_DETA\
IL WHERE OLDD_FILE_ID = :b0:b1 ORDER BY OLDD_DEPOSIT_SEQ            ";

 static char *sq0011 = 
"select deposit_bank_code from ( select db_bank_code as deposit_bank_code fr\
om ol_deposit_request_bank where db_bank_name = :b0 union select internal_ban\
k_code as deposit_bank_code from bank_desc where bank_name = :b0 ) order by d\
eposit_bank_code            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,207,0,4,68,0,0,4,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,1,0,0,
36,0,0,2,176,0,4,124,0,0,5,1,0,1,0,2,9,0,0,2,9,0,0,2,1,0,0,2,1,0,0,1,9,0,0,
71,0,0,3,165,0,4,196,0,0,5,1,0,1,0,2,9,0,0,2,9,0,0,2,1,0,0,2,1,0,0,1,9,0,0,
106,0,0,4,374,0,9,306,0,2049,1,1,0,1,0,1,9,0,0,
125,0,0,4,0,0,13,308,0,0,13,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,1,0,0,2,3,0,0,
192,0,0,4,0,0,15,409,0,0,0,0,0,1,0,
207,0,0,4,0,0,15,426,0,0,0,0,0,1,0,
222,0,0,5,87,0,4,443,0,0,1,0,0,1,0,2,9,0,0,
241,0,0,6,155,0,4,497,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
268,0,0,7,375,0,6,639,0,0,11,11,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,
1,4,0,0,1,3,0,0,1,1,0,0,1,1,0,0,1,9,0,0,1,9,0,0,
327,0,0,8,0,0,17,762,0,0,1,1,0,1,0,1,9,0,0,
346,0,0,8,0,0,21,763,0,0,0,0,0,1,0,
361,0,0,9,611,0,6,929,0,0,16,16,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,1,0,0,1,3,0,
0,1,9,0,0,
440,0,0,8,0,0,17,1035,0,0,1,1,0,1,0,1,9,0,0,
459,0,0,8,0,0,21,1036,0,0,0,0,0,1,0,
474,0,0,10,190,0,4,1074,0,0,3,2,0,1,0,2,9,0,0,1,9,0,0,1,9,0,0,
501,0,0,11,257,0,9,1135,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
524,0,0,11,0,0,13,1137,0,0,1,0,0,1,0,2,9,0,0,
543,0,0,11,0,0,15,1154,0,0,0,0,0,1,0,
558,0,0,11,0,0,15,1162,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/09/27              Stan Poon
Add GetDepositHeader GetDepositDetail		   2013/11/11		   Stan Poon
Add GetDepositBankCode			           2013/11/12	  	   Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "OLDepositRequest.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char	cDebug;

void OLDepositRequest(char	cdebug)
{
	cDebug = cdebug;
}

int CheckUploadedMerchantRef(const char *csMerchantID, const char *csMerchRef)
{
        int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO checkuploadedref_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	hv_merch_ref[PD_DEPOSIT_MERCH_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_merch_ref;

		char	hv_status;
		int	v_cnt;

		short	ind_merchant_id = -1;
		short	ind_merch_ref= -1;
		short	ind_status = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_merchant_id.len = strlen(csMerchantID);
DEBUGLOG(("CheckUploadedMerchantRef merchant_id = [%s]\n",csMerchantID));
	strncpy((char*)hv_merchant_id.arr,csMerchantID,hv_merchant_id.len);
	ind_merchant_id = 0;

	hv_status = PD_DEPOSIT_FILE_PENDING;
	ind_status = 0;

	hv_merch_ref.len = strlen(csMerchRef);
DEBUGLOG(("CheckUploadedMerchantRef merch_ref = [%s]\n",csMerchRef));
	if (hv_merch_ref.len > PD_DEPOSIT_MERCH_REF_LEN) {
		iRet = NOT_FOUND;
	} else {
		strncpy((char*)hv_merch_ref.arr,csMerchRef,hv_merch_ref.len);
		ind_merch_ref = 0;

		/* EXEC SQL	SELECT	COUNT(*)
				INTO	v_cnt
				FROM	OL_DEPOSIT_REQUEST_HEADER,
					OL_DEPOSIT_REQUEST_DETAIL
				WHERE	OLDH_FILE_ID = OLDD_FILE_ID
				AND	OLDH_MERCHANT_ID = :hv_merchant_id:ind_merchant_id
				AND	OLDD_MERCHANT_REF = :hv_merch_ref:ind_merch_ref
				AND	OLDH_STATUS = :hv_status:ind_status; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select COUNT ( * ) INTO :b0 FROM OL_DEPOSIT_REQUEST_HEADER\
 , OL_DEPOSIT_REQUEST_DETAIL WHERE OLDH_FILE_ID = OLDD_FILE_ID AND OLDH_MERCH\
ANT_ID = :b1:b2 AND OLDD_MERCHANT_REF = :b3:b4 AND OLDH_STATUS = :b5:b6 ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
  sqlstm.sqhstl[1] = (unsigned long )17;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_merch_ref;
  sqlstm.sqhstl[2] = (unsigned long )27;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_merch_ref;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&hv_status;
  sqlstm.sqhstl[3] = (unsigned long )1;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_status;
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
  if (sqlca.sqlcode < 0) goto checkuploadedref_error;
}



		if (v_cnt > 0) {
			iRet = FOUND;
DEBUGLOG(("CheckUploadedMerchantRef [%d] FOUND!!!\n",v_cnt));
		} else {
			iRet = NOT_FOUND;
DEBUGLOG(("CheckUploadedMerchantRef NOT FOUND\n"));
		}
	}

DEBUGLOG(("CheckUploadedMerchantRef Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

checkuploadedref_error:
DEBUGLOG(("checkuploadedref_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int GetDepositHeaderForUpdate(const char *csFileId, hash_t *myHash)
{
        int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO getdepositheader_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

		/* varchar		v_filename[PD_UPLOAD_FILENAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_filename;

		/* varchar		v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		char		v_status;
		char		v_party;

		short		ind_file_id = -1;
		short		ind_filename = -1;
		short		ind_merchant_id = -1;
		short		ind_status = -1;
		short		ind_party = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_file_id.len = strlen(csFileId);
	strncpy((char*)hv_file_id.arr,csFileId,hv_file_id.len);
	ind_file_id = 0;
DEBUGLOG(("GetDepositHeaderForUpdate file_id = [%.*s]\n",hv_file_id.len,hv_file_id.arr));

	/* EXEC SQL	SELECT	OLDH_FILENAME,
				OLDH_MERCHANT_ID,
				OLDH_STATUS,
				OLDH_PARTY
			INTO	:v_filename:ind_filename,
				:v_merchant_id:ind_merchant_id,
				:v_status:ind_status,
				:v_party:ind_party
			FROM	OL_DEPOSIT_REQUEST_HEADER
			WHERE	OLDH_FILE_ID = :hv_file_id:ind_file_id
			FOR	UPDATE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select OLDH_FILENAME , OLDH_MERCHANT_ID , OLDH_STATUS , OLD\
H_PARTY INTO :b0:b1 , :b2:b3 , :b4:b5 , :b6:b7 FROM OL_DEPOSIT_REQUEST_HEADER\
 WHERE OLDH_FILE_ID = :b8:b9 FOR UPDATE ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )36;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_filename;
 sqlstm.sqhstl[0] = (unsigned long )103;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_filename;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&v_status;
 sqlstm.sqhstl[2] = (unsigned long )1;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_status;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&v_party;
 sqlstm.sqhstl[3] = (unsigned long )1;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_party;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[4] = (unsigned long )18;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_file_id;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto getdepositheader_error;
}



	if (ind_filename >= 0) {
		v_filename.arr[v_filename.len] = '\0';
		PutField_CString(myHash,"filename",(char*)v_filename.arr);
DEBUGLOG(("GetDepositHeaderForUpdate filename = [%s]\n",(char*)v_filename.arr));
	}

	if (ind_merchant_id >= 0) {
		v_merchant_id.arr[v_merchant_id.len] = '\0';
		PutField_CString(myHash,"merchant_id",(char*)v_merchant_id.arr);
DEBUGLOG(("GetDepositHeaderForUpdate merchant_id = [%s]\n",(char*)v_merchant_id.arr));
	}

	if (ind_status >= 0) {
		PutField_Char(myHash,"status",v_status);
DEBUGLOG(("GetDepositHeaderForUpdate status = [%c]\n",v_status));
	}

	if (ind_party >= 0) {
		PutField_Char(myHash,"party",v_party);
DEBUGLOG(("GetDepositHeaderForUpdate party = [%c]\n",v_party));
	}

DEBUGLOG(("GetDepositHeaderForUpdate Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getdepositheader_error:
DEBUGLOG(("getdepositheader_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int GetDepositHeader(const char *csFileId, hash_t *myHash)
{
        int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO getdepositheader_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

		/* varchar		v_filename[PD_UPLOAD_FILENAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_filename;

		/* varchar		v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		char		v_status;
		char		v_party;

		short		ind_file_id = -1;
		short		ind_filename = -1;
		short		ind_merchant_id = -1;
		short		ind_status = -1;
		short		ind_party = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_file_id.len = strlen(csFileId);
	strncpy((char*)hv_file_id.arr,csFileId,hv_file_id.len);
	ind_file_id = 0;
DEBUGLOG(("GetDepositHeader file_id = [%.*s]\n",hv_file_id.len,hv_file_id.arr));

	/* EXEC SQL	SELECT	OLDH_FILENAME,
				OLDH_MERCHANT_ID,
				OLDH_STATUS,
				OLDH_PARTY
			INTO	:v_filename:ind_filename,
				:v_merchant_id:ind_merchant_id,
				:v_status:ind_status,
				:v_party:ind_party
			FROM	OL_DEPOSIT_REQUEST_HEADER
			WHERE	OLDH_FILE_ID = :hv_file_id:ind_file_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select OLDH_FILENAME , OLDH_MERCHANT_ID , OLDH_STATUS , OLD\
H_PARTY INTO :b0:b1 , :b2:b3 , :b4:b5 , :b6:b7 FROM OL_DEPOSIT_REQUEST_HEADER\
 WHERE OLDH_FILE_ID = :b8:b9 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )71;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_filename;
 sqlstm.sqhstl[0] = (unsigned long )103;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_filename;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&v_status;
 sqlstm.sqhstl[2] = (unsigned long )1;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_status;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&v_party;
 sqlstm.sqhstl[3] = (unsigned long )1;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_party;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[4] = (unsigned long )18;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_file_id;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto getdepositheader_error;
}



	if (ind_filename >= 0) {
		v_filename.arr[v_filename.len] = '\0';
		PutField_CString(myHash,"filename",(char*)v_filename.arr);
DEBUGLOG(("GetDepositHeader filename = [%s]\n",(char*)v_filename.arr));
	}

	if (ind_merchant_id >= 0) {
		v_merchant_id.arr[v_merchant_id.len] = '\0';
		PutField_CString(myHash,"merchant_id",(char*)v_merchant_id.arr);
DEBUGLOG(("GetDepositHeader merchant_id = [%s]\n",(char*)v_merchant_id.arr));
	}

	if (ind_status >= 0) {
		PutField_Char(myHash,"status",v_status);
DEBUGLOG(("GetDepositHeader status = [%c]\n",v_status));
	}

	if (ind_party >= 0) {
		PutField_Char(myHash,"party",v_party);
DEBUGLOG(("GetDepositHeader party = [%c]\n",v_party));
	}

DEBUGLOG(("GetDepositHeader Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getdepositheader_error:
DEBUGLOG(("getdepositheader_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int GetDepositDetail(const char *csFileId, recordset_t *myRec)
{
        int iRet = PD_OK;
	int iCnt = 0;

	hash_t *myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO getdepositdetail_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

		int		v_deposit_seq;
		/* varchar		v_int_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_int_bank_code;

		/* varchar		v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

		/* varchar		v_service_code[PD_SERVICE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		/* varchar		v_country[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		/* varchar		v_merch_ref[PD_DEPOSIT_MERCH_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_merch_ref;

		/* varchar		v_cust_deposit_datetime[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_cust_deposit_datetime;

		/* varchar		v_deposit_bank[PD_BANK_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_deposit_bank;

		/* varchar		v_deposit_ref[PD_DEPOSITOR_PROV_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_deposit_ref;

		double		v_deposit_amount;
		/* varchar		v_deposit_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_deposit_ccy;

		char		v_deposit_flow;
		int		v_cust_deposit_dt_prov;

		short		ind_file_id = -1;
		short		ind_deposit_seq = -1;
		short		ind_int_bank_code = -1;
		short		ind_bank_acct_num = -1;
		short		ind_service_code = -1;
		short		ind_country = -1;
		short		ind_merch_ref = -1;
		short		ind_cust_deposit_datetime= -1;
		short		ind_deposit_bank = -1;
		short		ind_deposit_ref = -1;
		short		ind_deposit_amount = -1;
		short		ind_deposit_ccy = -1;
		short		ind_deposit_flow = -1;
		short		ind_cust_deposit_dt_prov = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_file_id.len = strlen(csFileId);
	strncpy((char*)hv_file_id.arr,csFileId,hv_file_id.len);
	ind_file_id = 0;
DEBUGLOG(("GetDepositDetail file_id = [%.*s]\n",hv_file_id.len,hv_file_id.arr));

	/* EXEC SQL DECLARE getdepositdetailcursor CURSOR FOR
		SELECT	OLDD_DEPOSIT_SEQ,
			OLDD_INT_BANK_CODE,
			OLDD_BANK_ACCT_NUM,
			OLDD_SERVICE_CODE,
			OLDD_COUNTRY,
			OLDD_MERCHANT_REF,
			OLDD_CUST_DEPOSIT_DATETIME,
			OLDD_DEPOSIT_BANK,
			OLDD_DEPOSIT_REF,
			OLDD_DEPOSIT_AMOUNT,
			OLDD_DEPOSIT_CCY,
			OLDD_DEPOSIT_FLOW,
			OLDD_CUST_DEPOSIT_DT_PROV
		FROM	OL_DEPOSIT_REQUEST_DETAIL
		WHERE	OLDD_FILE_ID = :hv_file_id:ind_file_id
		ORDER BY OLDD_DEPOSIT_SEQ; */ 


	/* EXEC SQL OPEN getdepositdetailcursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0004;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )106;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[0] = (unsigned long )18;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_file_id;
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
 if (sqlca.sqlcode < 0) goto getdepositdetail_error;
}


	for (;;) {
		/* EXEC SQL FETCH getdepositdetailcursor
		INTO	:v_deposit_seq:ind_deposit_seq,
			:v_int_bank_code:ind_int_bank_code,
			:v_bank_acct_num:ind_bank_acct_num,
			:v_service_code:ind_service_code,
			:v_country:ind_country,
			:v_merch_ref:ind_merch_ref,
			:v_cust_deposit_datetime:ind_cust_deposit_datetime,
			:v_deposit_bank:ind_deposit_bank,
			:v_deposit_ref:ind_deposit_ref,
			:v_deposit_amount:ind_deposit_amount,
			:v_deposit_ccy:ind_deposit_ccy,
			:v_deposit_flow:ind_deposit_flow,
			:v_cust_deposit_dt_prov:ind_cust_deposit_dt_prov; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )125;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_deposit_seq;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_deposit_seq;
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
  sqlstm.sqhstv[2] = (unsigned char  *)&v_bank_acct_num;
  sqlstm.sqhstl[2] = (unsigned long )53;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_bank_acct_num;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_service_code;
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_service_code;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_country;
  sqlstm.sqhstl[4] = (unsigned long )5;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_country;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_merch_ref;
  sqlstm.sqhstl[5] = (unsigned long )28;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_merch_ref;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_cust_deposit_datetime;
  sqlstm.sqhstl[6] = (unsigned long )17;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_cust_deposit_datetime;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_deposit_bank;
  sqlstm.sqhstl[7] = (unsigned long )153;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_deposit_bank;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_deposit_ref;
  sqlstm.sqhstl[8] = (unsigned long )153;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_deposit_ref;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_deposit_amount;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_deposit_amount;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_deposit_ccy;
  sqlstm.sqhstl[10] = (unsigned long )6;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_deposit_ccy;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_deposit_flow;
  sqlstm.sqhstl[11] = (unsigned long )1;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_deposit_flow;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_cust_deposit_dt_prov;
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_cust_deposit_dt_prov;
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
  if (sqlca.sqlcode < 0) goto getdepositdetail_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

		if (ind_deposit_seq >= 0) {
			PutField_Int(myHash,"deposit_seq",v_deposit_seq);
DEBUGLOG(("GetDepositDetail deposit_seq = [%d]\n",v_deposit_seq));
		}

		if (ind_int_bank_code >= 0) {
			v_int_bank_code.arr[v_int_bank_code.len] = '\0';
			PutField_CString(myHash,"int_bank_code",(char*)v_int_bank_code.arr);
DEBUGLOG(("GetDepositDetail int_bank_code = [%s]\n",(char*)v_int_bank_code.arr));
		}

		if (ind_bank_acct_num >= 0) {
			v_bank_acct_num.arr[v_bank_acct_num.len] = '\0';
			PutField_CString(myHash,"bank_acct_num",(char*)v_bank_acct_num.arr);
DEBUGLOG(("GetDepositDetail bank_acct_num = [%s]\n",(char*)v_bank_acct_num.arr));
		}

		if (ind_service_code >= 0) {
			v_service_code.arr[v_service_code.len] = '\0';
			PutField_CString(myHash,"service_code",(char*)v_service_code.arr);
DEBUGLOG(("GetDepositDetail service_code = [%s]\n",(char*)v_service_code.arr));
		}

		if (ind_country >= 0) {
			v_country.arr[v_country.len] = '\0';
			PutField_CString(myHash,"country",(char*)v_country.arr);
DEBUGLOG(("GetDepositDetail country = [%s]\n",(char*)v_country.arr));
		}

		if (ind_merch_ref >= 0) {
			v_merch_ref.arr[v_merch_ref.len] = '\0';
			PutField_CString(myHash,"merch_ref",(char*)v_merch_ref.arr);
DEBUGLOG(("GetDepositDetail merch_ref = [%s]\n",(char*)v_merch_ref.arr));
		}

		if (ind_cust_deposit_datetime >= 0) {
			v_cust_deposit_datetime.arr[v_cust_deposit_datetime.len] = '\0';
			PutField_CString(myHash,"cust_deposit_datetime",(char*)v_cust_deposit_datetime.arr);
DEBUGLOG(("GetDepositDetail cust_deposit_datetime = [%s]\n",(char*)v_cust_deposit_datetime.arr));
		}

		if (ind_deposit_bank >= 0) {
			v_deposit_bank.arr[v_deposit_bank.len] = '\0';
			PutField_CString(myHash,"deposit_bank",(char*)v_deposit_bank.arr);
DEBUGLOG(("GetDepositDetail deposit_bank = [%s]\n",(char*)v_deposit_bank.arr));
		}

		if (ind_deposit_ref >= 0) {
			v_deposit_ref.arr[v_deposit_ref.len] = '\0';
			PutField_CString(myHash,"deposit_ref",(char*)v_deposit_ref.arr);
DEBUGLOG(("GetDepositDetail deposit_ref = [%s]\n",(char*)v_deposit_ref.arr));
		}

		if (ind_deposit_amount >= 0) {
			PutField_Double(myHash,"deposit_amount",v_deposit_amount);
DEBUGLOG(("GetDepositDetail deposit_amount = [%.2lf]\n",v_deposit_amount));
		}

		if (ind_deposit_ccy >= 0) {
			v_deposit_ccy.arr[v_deposit_ccy.len] = '\0';
			PutField_CString(myHash,"deposit_ccy",(char*)v_deposit_ccy.arr);
DEBUGLOG(("GetDepositDetail deposit_ccy = [%s]\n",(char*)v_deposit_ccy.arr));
		}

		if (ind_deposit_flow >= 0) {
			PutField_Char(myHash,"deposit_flow",v_deposit_flow);
DEBUGLOG(("GetDepositDetail deposit_flow = [%c]\n",v_deposit_flow));
		}

		if (ind_cust_deposit_dt_prov >= 0) {
			PutField_Int(myHash,"cust_deposit_dt_prov",v_cust_deposit_dt_prov);
DEBUGLOG(("GetDepositDetail cust_deposit_dt_prov = [%.2lf]\n",v_cust_deposit_dt_prov));
		}

		RecordSet_Add(myRec,myHash);

	}
	/* EXEC SQL CLOSE getdepositdetailcursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )192;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getdepositdetail_error;
}



	if (iCnt > 0) {
		iRet = PD_OK;
DEBUGLOG(("GetDepositDetail [%d] records FOUND\n",iCnt));
	} else {
		iRet = PD_ERR;
DEBUGLOG(("GetDepositDetail records NOT FOUND!!!\n"));
ERRLOG("OLDepositRequest:: GetDepositDetail NOT FOUND!!!\n");
	}

DEBUGLOG(("GetDepositDetail Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getdepositdetail_error:
DEBUGLOG(("getdepositdetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL CLOSE getdepositdetailcursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )207;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getdepositdetail_error;
}


        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int GetNextFileId(char *csFileId)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO getnextfileid_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	v_file_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_file_id;

		short	ind_file_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        /* EXEC SQL SELECT TO_CHAR(odi_file_seq.NEXTVAL, 'FM0999999999999999')
        	   INTO :v_file_id:ind_file_id
                 FROM dual; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select TO_CHAR ( odi_file_seq . NEXTVAL , 'FM0999999\
999999999' ) INTO :b0:b1 FROM dual ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )222;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_file_id;
        sqlstm.sqhstl[0] = (unsigned long )19;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_file_id;
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
        if (sqlca.sqlcode < 0) goto getnextfileid_error;
}



/*	EXEC SQL	SELECT	NVL(MAX(OLDH_FILE_ID),0) + 1
			INTO	:v_file_id:ind_file_id
			FROM	OL_DEPOSIT_REQUEST_HEADER;
*/

	if (ind_file_id >= 0) {
		v_file_id.arr[v_file_id.len] = '\0';
		strcpy(csFileId,(const char*)v_file_id.arr);
DEBUGLOG(("GenFileId file_id = [%s]\n", csFileId));
		return PD_OK;
	}

DEBUGLOG(("GetNextFileId FAILURE!!!\n"));
	return PD_ERR;;

getnextfileid_error:
DEBUGLOG(("getnextfileid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int CheckFileExist(const char* csMerchantId, const char* csFilename)
{
        int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO checkheader_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_filename[PD_UPLOAD_FILENAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_filename;

		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		int	v_cnt;

		short	ind_filename = -1;
		short	ind_merchant_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_merchant_id.len = strlen(csMerchantId);
	strncpy((char*)hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("CheckFileExist merchant_id = [%s]\n",csMerchantId));

	hv_filename.len = strlen(csFilename);
	strncpy((char*)hv_filename.arr,csFilename,hv_filename.len);
	ind_filename = 0;
DEBUGLOG(("CheckFileExist filename = [%s]\n",csFilename));

	/* EXEC SQL	SELECT	COUNT(*)
			INTO	:v_cnt
			FROM	OL_DEPOSIT_REQUEST_HEADER
			WHERE	OLDH_MERCHANT_ID = :hv_merchant_id:ind_merchant_id
			AND	OLDH_ORG_FILENAME = :hv_filename:ind_filename
			AND	OLDH_STATUS in ('W','A'); */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select COUNT ( * ) INTO :b0 FROM OL_DEPOSIT_REQUEST_HEADER \
WHERE OLDH_MERCHANT_ID = :b1:b2 AND OLDH_ORG_FILENAME = :b3:b4 AND OLDH_STATU\
S in ( 'W' , 'A' ) ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )241;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_filename;
 sqlstm.sqhstl[2] = (unsigned long )102;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_filename;
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
 if (sqlca.sqlcode < 0) goto checkheader_error;
}



	if (v_cnt>0) {
		iRet = FOUND;
DEBUGLOG(("CheckFileExist merchant_id [%s] filename [%s] FOUND\n",csMerchantId,csFilename));
	} else {
		iRet = NOT_FOUND;
DEBUGLOG(("CheckFileExist merchant_id [%s] filename [%s] NOT FOUND\n",csMerchantId,csFilename));
	}

DEBUGLOG(("CheckFileExist Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

checkheader_error:
DEBUGLOG(("checkheader_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int AddHeader(const hash_t *hRls)
{
	char	*csTmp;
	int	iTmp;
	double	dTmp;
	char	cTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_header_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

		/* varchar		hv_filename[PD_UPLOAD_FILENAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_filename;

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		int		hv_accept_count;
		double		hv_accept_amount;
		int		hv_total_count;
		char		hv_status;
		char		hv_party;
		/* varchar		hv_org_filename[PD_UPLOAD_FILENAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_org_filename;

		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_file_id = -1;
		short		ind_filename = -1;
		short		ind_merchant_id = -1;
		short		ind_accept_count = -1;
		short		ind_accept_amount = -1;
		short		ind_total_count = -1;
		short		ind_status = -1;
		short		ind_party = -1;
		short		ind_org_filename = -1;
		short		ind_create_user = -1;

		short		hv_return_value;

	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls,"file_id",&csTmp)) {
		hv_file_id.len = strlen(csTmp);
		strncpy((char*)hv_file_id.arr, csTmp, hv_file_id.len);
		ind_file_id = 0;
DEBUGLOG(("AddHeader:file_id = [%.*s]\n",hv_file_id.len, hv_file_id.arr));
	} else {
DEBUGLOG(("AddHeader:file_id NOT FOUND!!!\n"));
	}

	if (GetField_CString(hRls,"new_file_name",&csTmp)) {
		hv_filename.len = strlen(csTmp);
		strncpy((char*)hv_filename.arr, csTmp, hv_filename.len);
		ind_filename = 0;
DEBUGLOG(("AddHeader:filename = [%.*s]\n",hv_filename.len, hv_filename.arr));
	} else {
DEBUGLOG(("AddHeader:filename NOT FOUND!!!\n"));
	}

	if (GetField_CString(hRls,"merchant_id",&csTmp)) {
		hv_merchant_id.len = strlen(csTmp);
		strncpy((char*)hv_merchant_id.arr, csTmp, hv_merchant_id.len);
		ind_merchant_id = 0;
DEBUGLOG(("AddHeader:merchant_id = [%.*s]\n",hv_merchant_id.len, hv_merchant_id.arr));
	}

	hv_accept_count = 0;
	if (GetField_Int(hRls, "accept_count", &iTmp)) {
		hv_accept_count = iTmp;
DEBUGLOG(("AddHeader:accept_count = [%d]\n",hv_accept_count));
	}
	ind_accept_count = 0;

	hv_accept_amount = 0;
	if (GetField_Double(hRls, "accept_amount", &dTmp)) {
		hv_accept_amount = dTmp;
DEBUGLOG(("AddHeader:accept_amount = [%lf]\n",hv_accept_amount));
	}
	ind_accept_amount = 0;

	hv_total_count = 0;
	if (GetField_Int(hRls, "total_count", &iTmp)) {
		hv_total_count = iTmp;
DEBUGLOG(("AddHeader:total_count = [%d]\n",hv_total_count));
	}
	ind_total_count = 0;

	if (GetField_Char(hRls,"status",&cTmp))
	{
		hv_status = cTmp;
		ind_status = 0;
DEBUGLOG(("AddHeader:status = [%c]\n",hv_status));
	}

	if (GetField_Char(hRls,"party",&cTmp))
	{
		hv_party = cTmp;
		ind_party = 0;
DEBUGLOG(("AddHeader:party = [%c]\n",hv_party));
	}

	if (GetField_CString(hRls,"in_file_name",&csTmp)) {
		hv_org_filename.len = strlen(csTmp);
		strncpy((char*)hv_org_filename.arr, csTmp, hv_org_filename.len);
		ind_org_filename = 0;
DEBUGLOG(("AddHeader:org_filename = [%.*s]\n",hv_org_filename.len, hv_org_filename.arr));
	} else {
DEBUGLOG(("AddHeader:org_filename NOT FOUND!!!\n"));
	}

	if (GetField_CString(hRls,"create_user",&csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
DEBUGLOG(("AddHeader:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));
	} else {
DEBUGLOG(("AddHeader:create_user NOT FOUND!!!\n"));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_deposit_header_insert(
						:hv_file_id:ind_file_id,
						:hv_filename:ind_filename,
						:hv_merchant_id:ind_merchant_id,
						:hv_accept_count:ind_accept_count,
						:hv_accept_amount:ind_accept_amount,
						:hv_total_count:ind_total_count,
						:hv_status:ind_status,
						:hv_party:ind_party,
						:hv_org_filename:ind_org_filename,
						:hv_create_user:ind_create_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_deposit_header_insert ( :hv\
_file_id:ind_file_id , :hv_filename:ind_filename , :hv_merchant_id:ind_mercha\
nt_id , :hv_accept_count:ind_accept_count , :hv_accept_amount:ind_accept_amou\
nt , :hv_total_count:ind_total_count , :hv_status:ind_status , :hv_party:ind_\
party , :hv_org_filename:ind_org_filename , :hv_create_user:ind_create_user )\
 ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )268;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_file_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_filename;
 sqlstm.sqhstl[2] = (unsigned long )102;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_filename;
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
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_accept_count;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_accept_count;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_accept_amount;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_accept_amount;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_total_count;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_total_count;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[7] = (unsigned long )1;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_status;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_party;
 sqlstm.sqhstl[8] = (unsigned long )1;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_party;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_org_filename;
 sqlstm.sqhstl[9] = (unsigned long )102;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_org_filename;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[10] = (unsigned long )22;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto add_header_error;
}



DEBUGLOG(("AddHeader:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("AddHeader:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLDepositRequest_AddHeader: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("AddHeader: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLDepositRequest_AddHeader: SP_ERR TxnAbort\n");
DEBUGLOG(("AddHeader: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

add_header_error:
DEBUGLOG(("add_header_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLDepositRequest_AddHeader: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int UpdateHeader(const hash_t *hRls)
{
	char	*csTmp;
	char	*csFileId;
	int	iTmp;
	double	dTmp;
	char 	cTmp;

	char*	csBuf;
	csBuf = (char *) malloc(128);

        /* EXEC SQL WHENEVER SQLERROR GOTO update_header_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar	hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


        strcpy((char*)hv_dynstmt.arr,"update ol_deposit_request_header set oldh_update_timestamp = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	if (!GetField_CString(hRls,"file_id",&csFileId)) {
DEBUGLOG(("UpdateHeader: file_id NOT FOUND!!!\n"));
	}

/* update_user */
        if (GetField_CString(hRls,"update_user",&csTmp)) {
DEBUGLOG(("UpdateHeader:update_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",oldh_update_user= '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* accept_count */
	if (GetField_Int(hRls,"accept_count",&iTmp)) {
DEBUGLOG(("UpdateHeader:accept_count += [%d]\n",iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ",oldh_accept_count = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* accept_amount */
	if (GetField_Double(hRls,"accept_amount",&dTmp)) {
DEBUGLOG(("UpdateHeader:accept_amount += [%lf]\n",dTmp));
		sprintf(csBuf, "%lf", dTmp);
		strcat((char*)hv_dynstmt.arr, ",oldh_accept_amount = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* total_count */
	if (GetField_Int(hRls,"total_count",&iTmp)) {
DEBUGLOG(("UpdateHeader:total_count += [%d]\n",iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ",oldh_total_count = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* status */
	if (GetField_Char(hRls,"status",&cTmp)) {
DEBUGLOG(("UpdateHeader:status = [%c]\n",cTmp));
		sprintf(csBuf, "%c", cTmp);
		strcat((char*)hv_dynstmt.arr, ",oldh_status = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

        strcat((char *)hv_dynstmt.arr, " WHERE oldh_file_id = '");
        strcat((char *)hv_dynstmt.arr, csFileId);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )327;
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
        if (sqlca.sqlcode < 0) goto update_header_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )346;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_header_error;
}



	FREE_ME(csBuf);

DEBUGLOG(("UpdateHeader Normal Exit\n"));
        return PD_OK;

update_header_error:
DEBUGLOG(("update_Header_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLDepositRequest_UpdateHeader: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("UpdateHeader: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;
}


int AddDetail(hash_t *hRls)
{
	int	iTmp;
	char	*csTmp;
	char	cTmp;
	double	dTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_detail_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

		int		hv_deposit_seq;
		/* varchar		hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar		hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar		hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

		/* varchar		hv_merch_ref[PD_DEPOSIT_MERCH_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_merch_ref;

		/* varchar		hv_cust_deposit_datetime[PD_TIMESTAMP_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_cust_deposit_datetime;

		/* varchar		hv_deposit_bank[PD_BANK_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_deposit_bank;

		/* varchar		hv_deposit_ref[PD_DEPOSITOR_PROV_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_deposit_ref;

		double		hv_deposit_amount;
		/* varchar		hv_deposit_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_deposit_ccy;

		char		hv_deposit_flow;
		int		hv_cust_deposit_dt_prov;
		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_file_id = -1;
		short		ind_deposit_seq = -1;
		short		ind_int_bank_code = -1;
		short		ind_bank_acct_num = -1;
		short		ind_service_code = -1;
		short		ind_country = -1;
		short		ind_merch_ref = -1;
		short		ind_cust_deposit_datetime = -1;
		short		ind_deposit_bank = -1;
		short		ind_deposit_ref = -1;
		short		ind_deposit_amount = -1;
		short		ind_deposit_ccy = -1;
		short		ind_deposit_flow = -1;
		short		ind_cust_deposit_dt_prov = -1;
		short		ind_create_user = -1;

		short		hv_return_value;

	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls,"file_id",&csTmp)) {
		hv_file_id.len = strlen(csTmp);
		strncpy((char*)hv_file_id.arr, csTmp, hv_file_id.len);
		ind_file_id = 0;
DEBUGLOG(("AddDetail: file_id = [%.*s]\n",hv_file_id.len, hv_file_id.arr));
	}

	if (GetField_Int(hRls, "deposit_seq", &iTmp)) {
		hv_deposit_seq = iTmp;
		ind_deposit_seq = 0;
DEBUGLOG(("AddDetail: deposit_seq = [%d]\n",hv_deposit_seq));
	}

	if (GetField_CString(hRls,"int_bank_code",&csTmp)) {
		hv_int_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_int_bank_code.arr, csTmp, hv_int_bank_code.len);
		ind_int_bank_code = 0;
DEBUGLOG(("AddDetail: int_bank_code = [%.*s]\n",hv_int_bank_code.len, hv_int_bank_code.arr));
	}

	if (GetField_CString(hRls,"bank_acct_num",&csTmp)) {
		hv_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_num.arr, csTmp, hv_bank_acct_num.len);
		ind_bank_acct_num = 0;
DEBUGLOG(("AddDetail: bank_acct_num = [%.*s]\n",hv_bank_acct_num.len, hv_bank_acct_num.arr));
	}

	if (GetField_CString(hRls,"service_code",&csTmp)) {
		hv_service_code.len = strlen(csTmp);
		strncpy((char*)hv_service_code.arr, csTmp, hv_service_code.len);
		ind_service_code = 0;
DEBUGLOG(("AddDetail :service_code = [%.*s]\n",hv_service_code.len, hv_service_code.arr));
	}

	if (GetField_CString(hRls,"country",&csTmp)) {
		hv_country.len = strlen(csTmp);
		strncpy((char*)hv_country.arr, csTmp, hv_country.len);
		ind_country = 0;
DEBUGLOG(("AddDetail: country = [%.*s]\n",hv_country.len, hv_country.arr));
	}

	if (GetField_CString(hRls,"merch_ref",&csTmp)) {
		hv_merch_ref.len = strlen(csTmp);
		strncpy((char*)hv_merch_ref.arr, csTmp, hv_merch_ref.len);
		ind_merch_ref = 0;
DEBUGLOG(("AddDetail: merch_ref = [%.*s]\n",hv_merch_ref.len, hv_merch_ref.arr));
	}

	if (GetField_CString(hRls,"cust_deposit_datetime",&csTmp)) {
		hv_cust_deposit_datetime.len = strlen(csTmp);
		strncpy((char*)hv_cust_deposit_datetime.arr, csTmp, hv_cust_deposit_datetime.len);
		ind_cust_deposit_datetime = 0;
DEBUGLOG(("AddDetail: cust_deposit_datetime = [%.*s]\n",hv_cust_deposit_datetime.len, hv_cust_deposit_datetime.arr));
	}

	if (GetField_CString(hRls,"deposit_bank",&csTmp)) {
		hv_deposit_bank.len = strlen(csTmp);
		strncpy((char*)hv_deposit_bank.arr, csTmp, hv_deposit_bank.len);
		ind_deposit_bank = 0;
DEBUGLOG(("AddDetail: deposit_bank = [%.*s]\n",hv_deposit_bank.len, hv_deposit_bank.arr));
	}

	if (GetField_CString(hRls,"deposit_ref",&csTmp)) {
		hv_deposit_ref.len = strlen(csTmp);
		strncpy((char*)hv_deposit_ref.arr, csTmp, hv_deposit_ref.len);
		ind_deposit_ref = 0;
DEBUGLOG(("AddDetail: deposit_ref = [%.*s]\n",hv_deposit_ref.len, hv_deposit_ref.arr));
	}

	if (GetField_Double(hRls,"deposit_amount",&dTmp)) {
		hv_deposit_amount = dTmp;
		ind_deposit_amount = 0;
DEBUGLOG(("AddDetail: deposit_amount = [%.2f]\n",hv_deposit_amount));
	}

	if (GetField_CString(hRls,"deposit_ccy",&csTmp)) {
		hv_deposit_ccy.len = strlen(csTmp);
		strncpy((char*)hv_deposit_ccy.arr, csTmp, hv_deposit_ccy.len);
		ind_deposit_ccy = 0;
DEBUGLOG(("AddDetail: deposit_ccy = [%.*s]\n",hv_deposit_ccy.len, hv_deposit_ccy.arr));
	}

	if (GetField_Char(hRls,"deposit_flow",&cTmp)) {
		hv_deposit_flow = cTmp;
		ind_deposit_flow = 0;
DEBUGLOG(("AddDetail: deposit_flow = [%c]\n",hv_deposit_flow));
	}

	if (GetField_Int(hRls,"cust_deposit_dt_prov",&iTmp)) {
		hv_cust_deposit_dt_prov = iTmp;
		ind_cust_deposit_dt_prov = 0;
DEBUGLOG(("AddDetail: cust_deposit_dt_prov = [%d]\n",hv_cust_deposit_dt_prov));
	}

	if (GetField_CString(hRls,"create_user",&csTmp)) {
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
DEBUGLOG(("AddDetail: create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_deposit_detail_insert(
						:hv_file_id:ind_file_id,
						:hv_deposit_seq:ind_deposit_seq,
						:hv_int_bank_code:ind_int_bank_code,
						:hv_bank_acct_num:ind_bank_acct_num,
						:hv_service_code:ind_service_code,
						:hv_country:ind_country,
						:hv_merch_ref:ind_merch_ref,
						:hv_cust_deposit_datetime:ind_cust_deposit_datetime,
						:hv_deposit_bank:ind_deposit_bank,
						:hv_deposit_ref:ind_deposit_ref,
						:hv_deposit_amount:ind_deposit_amount,
						:hv_deposit_ccy:ind_deposit_ccy,
						:hv_deposit_flow:ind_deposit_flow,
						:hv_cust_deposit_dt_prov:ind_cust_deposit_dt_prov,
						:hv_create_user:ind_create_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_deposit_detail_insert ( :hv\
_file_id:ind_file_id , :hv_deposit_seq:ind_deposit_seq , :hv_int_bank_code:in\
d_int_bank_code , :hv_bank_acct_num:ind_bank_acct_num , :hv_service_code:ind_\
service_code , :hv_country:ind_country , :hv_merch_ref:ind_merch_ref , :hv_cu\
st_deposit_datetime:ind_cust_deposit_datetime , :hv_deposit_bank:ind_deposit_\
bank , :hv_deposit_ref:ind_deposit_ref , :hv_deposit_amount:ind_deposit_amoun\
t , :hv_deposit_ccy:ind_deposit_ccy , :hv_deposit_flow:ind_deposit_flow , :hv\
_cust_deposit_dt_prov:ind_cust_deposit_dt_prov , :hv_create_user:ind_create_u\
ser ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )361;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_file_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_deposit_seq;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_deposit_seq;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[3] = (unsigned long )12;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[4] = (unsigned long )52;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_bank_acct_num;
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
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_country;
 sqlstm.sqhstl[6] = (unsigned long )4;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_country;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_merch_ref;
 sqlstm.sqhstl[7] = (unsigned long )27;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_merch_ref;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_cust_deposit_datetime;
 sqlstm.sqhstl[8] = (unsigned long )22;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_cust_deposit_datetime;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_deposit_bank;
 sqlstm.sqhstl[9] = (unsigned long )152;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_deposit_bank;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_deposit_ref;
 sqlstm.sqhstl[10] = (unsigned long )152;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_deposit_ref;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_deposit_amount;
 sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_deposit_amount;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_deposit_ccy;
 sqlstm.sqhstl[12] = (unsigned long )5;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_deposit_ccy;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_deposit_flow;
 sqlstm.sqhstl[13] = (unsigned long )1;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_deposit_flow;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_cust_deposit_dt_prov;
 sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_cust_deposit_dt_prov;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[15] = (unsigned long )22;
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto add_detail_error;
}



DEBUGLOG(("AddDetail:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("AddDetail:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLDepositRequest_AddDetail: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("AddDetail: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLDepositRequest_AddDetail: SP_ERR TxnAbort\n");
DEBUGLOG(("AddDetail: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

add_detail_error:
DEBUGLOG(("add_detail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLDepositRequest_AddDetail: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int UpdateDetail(const hash_t *hRls)
{
	char	*csTmp;
	char	*csFileId;
	int	iSeq;

	char*	csBuf;
	csBuf = (char *) malloc(128);

        /* EXEC SQL WHENEVER SQLERROR GOTO update_detail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar	hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


        strcpy((char*)hv_dynstmt.arr,"update ol_deposit_request_detail set oldd_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	if (!GetField_CString(hRls,"file_id",&csFileId)) {
DEBUGLOG(("UpdateDetail: file_id NOT FOUND!!!\n"));
	}

	if (!GetField_Int(hRls,"deposit_seq",&iSeq)) {
DEBUGLOG(("UpdateDetail: seq NOT FOUND!!!\n"));
	}

/* update_user */
        if (GetField_CString(hRls,"update_user",&csTmp)) {
DEBUGLOG(("UpdateDetail:update_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",oldd_update_user= '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* txn_seq */
        if (GetField_CString(hRls,"txn_seq",&csTmp)) {
DEBUGLOG(("UpdateDetail:txn_seq = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",oldd_txn_id= '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        strcat((char *)hv_dynstmt.arr, " WHERE oldd_file_id = '");
        strcat((char *)hv_dynstmt.arr, csFileId);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	sprintf(csTmp,"%i",iSeq);
        strcat((char *)hv_dynstmt.arr, " AND oldd_DEPOSIT_SEQ = ");
        strcat((char *)hv_dynstmt.arr, csTmp);
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 16;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )440;
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
        if (sqlca.sqlcode < 0) goto update_detail_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 16;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )459;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_detail_error;
}



	FREE_ME(csBuf);

DEBUGLOG(("UpdateDetail Normal Exit\n"));
        return PD_OK;

update_detail_error:
DEBUGLOG(("update_Detail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLDepositRequest_UpdateDetail: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("UpdateDetail: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;
}


int GetBankCode(const char *csBankName,
			char *csBankCode)
{
        int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO getmaxcode_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_bank_desc[PD_BANK_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_bank_desc;

		/* varchar	v_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;


		short	ind_bank_code = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_bank_desc.len = strlen(csBankName);
	memcpy(hv_bank_desc.arr, csBankName, hv_bank_desc.len);
DEBUGLOG(("GetBankCode bank_name = [%.*s]\n",hv_bank_desc.len,hv_bank_desc.arr));

	/* EXEC SQL SELECT INTERNAL_BANK_CODE
		 INTO	:v_bank_code:ind_bank_code
		 FROM	BANK_DESC
		 WHERE	EXISTS (SELECT * FROM OL_DEPOSIT_REQUEST_BANK
				WHERE	DB_BANK_NAME = :hv_bank_desc
				AND	DB_BANK_CODE = INTERNAL_BANK_CODE)
		 OR	BANK_NAME = :hv_bank_desc; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select INTERNAL_BANK_CODE INTO :b0:b1 FROM BANK_DESC WHERE \
EXISTS ( SELECT * FROM OL_DEPOSIT_REQUEST_BANK WHERE DB_BANK_NAME = :b2 AND D\
B_BANK_CODE = INTERNAL_BANK_CODE ) OR BANK_NAME = :b2 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )474;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_bank_code;
 sqlstm.sqhstl[0] = (unsigned long )13;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_bank_code;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_desc;
 sqlstm.sqhstl[1] = (unsigned long )152;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_desc;
 sqlstm.sqhstl[2] = (unsigned long )152;
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
 if (sqlca.sqlcode < 0) goto getmaxcode_error;
}



	if (ind_bank_code >=0) {
		v_bank_code.arr[v_bank_code.len] = '\0';
		strcpy(csBankCode, (char*)v_bank_code.arr);
DEBUGLOG(("GetBankCode bank_code = [%s]\n",(char*)v_bank_code.arr));
		iRet = PD_FOUND;
	} else {
		iRet = PD_NOT_FOUND;
DEBUGLOG(("GetBankCode not found!!!\n"));
	}

DEBUGLOG(("GetBankCode Normal Exit iRet =[%d]\n",iRet));
	return iRet;

getmaxcode_error:
DEBUGLOG(("getmaxcode_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}

int GetDepositBankCode(const char *csBankName,
			char *csBankCode)
{
        int iRet = PD_NOT_FOUND;

	/* EXEC SQL WHENEVER SQLERROR GOTO getdepositbankcode_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_bank_desc[PD_BANK_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_bank_desc;

		/* varchar	v_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;


		short	ind_bank_code = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_bank_desc.len = strlen(csBankName);
	memcpy(hv_bank_desc.arr, csBankName, hv_bank_desc.len);
DEBUGLOG(("GetDepositBankCode bank_name = [%.*s]\n",hv_bank_desc.len,hv_bank_desc.arr));

	/* EXEC SQL DECLARE c_cursor_getdepositbankcode CURSOR FOR
		select deposit_bank_code 
		from (
			select db_bank_code as deposit_bank_code
			from ol_deposit_request_bank
			where db_bank_name = :hv_bank_desc
			union
			select internal_bank_code as deposit_bank_code
			from bank_desc 
			where bank_name = :hv_bank_desc
		) order by deposit_bank_code; */ 


	/* EXEC SQL OPEN c_cursor_getdepositbankcode; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0011;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )501;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_bank_desc;
 sqlstm.sqhstl[0] = (unsigned long )152;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_desc;
 sqlstm.sqhstl[1] = (unsigned long )152;
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
 if (sqlca.sqlcode < 0) goto getdepositbankcode_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getdepositbankcode
		INTO 	:v_bank_code:ind_bank_code; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )524;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_bank_code;
  sqlstm.sqhstl[0] = (unsigned long )13;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_bank_code;
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
  if (sqlca.sqlcode < 0) goto getdepositbankcode_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		if (ind_bank_code >=0) {
			v_bank_code.arr[v_bank_code.len] = '\0';
			strcpy(csBankCode, (char*)v_bank_code.arr);
DEBUGLOG(("GetDepositBankCode bank_code = [%s]\n",(char*)v_bank_code.arr));
			iRet = PD_FOUND;
		} 
		break;

	} while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getdepositbankcode; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )543;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getdepositbankcode_error;
}



DEBUGLOG(("GetDepositBankCode Normal Exit iRet =[%d]\n",iRet));
	return iRet;

getdepositbankcode_error:
DEBUGLOG(("getdepositbankcode_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL CLOSE c_cursor_getdepositbankcode; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )558;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getdepositbankcode_error;
}


        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}
