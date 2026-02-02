
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
    "ol_auto_gen_baid_acct.pc"
};


static unsigned int sqlctx = 1336781451;


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
   unsigned char  *sqhstv[4];
   unsigned long  sqhstl[4];
            int   sqhsts[4];
            short *sqindv[4];
            int   sqinds[4];
   unsigned long  sqharm[4];
   unsigned long  *sqharc[4];
   unsigned short  sqadto[4];
   unsigned short  sqtdso[4];
} sqlstm = {12,4};

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
"SELECT RAG_BAID_CAT_TYPE , OPD_BANK_ACCT_TYPE , OB_INT_BANK_CODE , OB_BANK_\
ACCT_NUM FROM OL_RULE_BAID_AUTO_GEN , OL_PSP_DETAIL , OL_BANK_ACCTS WHERE RAG\
_BANK_ACCT_TYPE = OPD_BANK_ACCT_TYPE AND RAG_DISABLE = :b0 AND OPD_PSP_ID = :\
b1 AND OB_IS_VIRTUAL = :b2 AND OB_ACCT_CCY = OPD_CURRENCY_ID            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,301,0,9,119,0,2049,3,3,0,1,0,1,3,0,0,1,9,0,0,1,3,0,0,
32,0,0,1,0,0,13,121,0,0,4,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
63,0,0,1,0,0,15,190,0,0,0,0,0,1,0,
78,0,0,1,0,0,15,206,0,0,0,0,0,1,0,
93,0,0,2,0,0,32,207,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/09/22              Dirk Wong 
Support default bank ac on temp/iq/pf		   2015/01/02		   Dirk Wong
Remove Input PspType and			   2015/10/29              Elvis Wong 
Not return error if baid acct exists	
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

char csTag[PD_TAG_LEN+1];
char csTmp[PD_TMP_BUF_LEN+1];
char cDebug;

char    cs_psp_id[PD_PSP_ID_LEN+1];

OBJPTR(Txn);
OBJPTR(DB);

int parse_arg(int argc,char **argv);

int batch_init(int argc, char* argv[])
{
        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int     iRet = parse_arg(argc,argv);
	int	iDtlRet = PD_OK;
	int	iIntError = FAILURE;

	hash_t	*hContext, *hRequest, *hResponse;

	char	csPhDate[PD_DATETIME_LEN + 1];
	char	csTmDateTime[PD_DATETIME_LEN + 1];
	char	csTmDate[PD_DATE_LEN + 1];
	char	csTmTime[PD_TIME_LEN + 1];

	hContext = (hash_t *)malloc(sizeof(hash_t));
	hRequest = (hash_t *)malloc(sizeof(hash_t));
	hResponse= (hash_t *)malloc(sizeof(hash_t));

	hash_init(hContext,   0);
	hash_init(hRequest,  0);
	hash_init(hResponse, 0);

	if (iRet != SUCCESS) {
printf("Error while reading args!\n");
	}

	hContext = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hContext,0);

	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		int	hv_rule_disabled;
		int	hv_is_virtual;

		/* varchar	v_cat_type[PD_BAID_CATEGORY_TYPE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_cat_type;

		/* varchar v_acct_type[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_acct_type;

		/* varchar	v_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

		/* varchar	v_bank_acct_num[PD_BANK_ACCT_NUM_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;


		short	ind_cat_type = -1;
		short	ind_acct_type = -1;
		short	ind_bank_code = -1;
		short	ind_bank_acct_num = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_psp_id.len = strlen(cs_psp_id);
	memcpy(hv_psp_id.arr,cs_psp_id,hv_psp_id.len);
	
	hv_rule_disabled = 0;

	hv_is_virtual = 1;

	/* EXEC SQL DECLARE c_cursor_getcattype CURSOR FOR
		SELECT	RAG_BAID_CAT_TYPE,
			OPD_BANK_ACCT_TYPE,
			OB_INT_BANK_CODE,
			OB_BANK_ACCT_NUM
		FROM	OL_RULE_BAID_AUTO_GEN,
			OL_PSP_DETAIL,
			OL_BANK_ACCTS
		WHERE	RAG_BANK_ACCT_TYPE = OPD_BANK_ACCT_TYPE
		  AND 	RAG_DISABLE = :hv_rule_disabled
		  AND	OPD_PSP_ID = :hv_psp_id
		  AND	OB_IS_VIRTUAL = :hv_is_virtual
		  AND	OB_ACCT_CCY = OPD_CURRENCY_ID
		; */ 


	/* EXEC SQL OPEN c_cursor_getcattype; */ 

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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_rule_disabled;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_is_virtual;
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
		/* EXEC SQL FETCH c_cursor_getcattype
		INTO
			:v_cat_type:ind_cat_type,
			:v_acct_type:ind_acct_type,
			:v_bank_code:ind_bank_code,
			:v_bank_acct_num:ind_bank_acct_num; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
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
  sqlstm.sqhstv[0] = (unsigned char  *)&v_cat_type;
  sqlstm.sqhstl[0] = (unsigned long )13;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_cat_type;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_acct_type;
  sqlstm.sqhstl[1] = (unsigned long )5;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_acct_type;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_bank_code;
  sqlstm.sqhstl[2] = (unsigned long )13;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_bank_code;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_bank_acct_num;
  sqlstm.sqhstl[3] = (unsigned long )53;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_bank_acct_num;
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



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		v_acct_type.arr[v_acct_type.len]='\0';

		v_cat_type.arr[v_cat_type.len]='\0';
		PutField_CString(hRequest, "category", (const char*)v_cat_type.arr);
printf("Acct Type [%s] Category [%s] is going to auto-gen!\n",(const char*)v_acct_type.arr,(const char*)v_cat_type.arr);

		PutField_CString(hRequest, "action", "A");
		PutField_CString(hRequest, "psp_id", cs_psp_id);
		PutField_CString(hRequest, "status", "O");
		PutField_CString(hRequest, "init_bal", "0.00");
		PutField_CString(hRequest, "add_user", PD_UPDATE_USER);

		v_bank_code.arr[v_bank_code.len] = '\0';
		PutField_CString(hRequest, "int_bank_code", (const char*)v_bank_code.arr);
printf("virtual bank code [%s] assigned\n",(const char*)v_bank_code.arr);
		v_bank_acct_num.arr[v_bank_acct_num.len] = '\0';
		PutField_CString(hRequest, "bank_acct_num", (const char*)v_bank_acct_num.arr);
printf("virtual bank acct num [%s] assigned\n",(const char*)v_bank_acct_num.arr);

		DBObjPtr = CreateObj(DBPtr, "DBSystemControl", "FindCode");
		if ((unsigned long)(*DBObjPtr)("CTPHDATE", csPhDate) == FOUND) {
printf("Current Processor Hub Date = [%s]\n", csPhDate);
			PutField_CString(hContext, "PHDATE", csPhDate);
		} else {
printf("Current Processor Hub Date Not Found\n");
			iRet = INT_ERR;
		}

		PutField_CString(hContext, "channel_code", PD_CHANNEL_OMT);

		strcpy(csTmDateTime, getdatetime());
		sprintf(csTmDate, "%.*s", PD_DATE_LEN, csTmDateTime);
		PutField_CString(hContext, "local_tm_date", csTmDate);
		sprintf(csTmTime, "%.*s", PD_TIME_LEN, &csTmDateTime[PD_DATE_LEN]);
		PutField_CString(hContext, "local_tm_time", csTmTime);

		if (iRet == SUCCESS) {
			TxnObjPtr = CreateObj(TxnPtr,"TxnOmtByUsBAI","Authorize");
			iDtlRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);

			if (iDtlRet == PD_OK) {
				if (GetField_Int(hContext, "internal_error", &iIntError)) {
DEBUGLOG(("TxnMgtByUsBAI:Authorize Return internal_error [%d]\n", iIntError));
printf("TxnMgtByUsBAI return error [%d]\n",iIntError);
					iRet = INT_ERR;
				}
printf("TxnMgtByUsBAI return success\n");
			} else if (iDtlRet == INT_BAID_UNDER_PSP_CAT_EXISTS) {
printf("TxnMgtByUsBAI:Authorize Return Baid Under PSP Category Exists: [%d]\n",iDtlRet);
			} else {
				iRet = iDtlRet;
printf("TxnMgtByUsBAI:Authorize Return error: [%d]\n",iRet);
			}
		}


	}
	while(PD_TRUE && iRet == SUCCESS);
	/* EXEC SQL CLOSE c_cursor_getcattype; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )63;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto sql_error;
}



	hash_destroy(hContext);
	hash_destroy(hRequest);
	hash_destroy(hResponse);

	FREE_ME(hContext);
	FREE_ME(hRequest);
	FREE_ME(hResponse);

	return iRet;

sql_error:
DEBUGLOG(("error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getcattype; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )78;
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
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )93;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int batch_terminate(int argc, char* argv[])
{
        return SUCCESS;
}


int parse_arg(int argc,char **argv)
{

        char    c;

	strcpy(cs_psp_id,"");

        if (argc < 3) {
                return PD_ERR;
        }
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

	cs_psp_id[strlen(cs_psp_id)]='\0';

        return SUCCESS;
}
