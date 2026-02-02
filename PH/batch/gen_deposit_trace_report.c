
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
    "gen_deposit_trace_report.pc"
};


static unsigned int sqlctx = 1193366971;


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
   unsigned char  *sqhstv[9];
   unsigned long  sqhstl[9];
            int   sqhsts[9];
            short *sqindv[9];
            int   sqinds[9];
   unsigned long  sqharm[9];
   unsigned long  *sqharc[9];
   unsigned short  sqadto[9];
   unsigned short  sqtdso[9];
} sqlstm = {12,9};

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
5,0,0,0,0,0,56,181,0,0,1,1,0,1,0,3,102,0,0,
24,0,0,1,195,0,6,182,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,2,102,0,0,
55,0,0,0,0,0,13,208,0,0,9,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
106,0,0,0,0,0,15,304,0,0,1,1,0,1,0,1,102,0,0,
125,0,0,0,0,0,78,305,0,0,1,1,0,1,0,3,102,0,0,
144,0,0,0,0,0,15,312,0,0,1,1,0,1,0,1,102,0,0,
163,0,0,0,0,0,78,313,0,0,1,1,0,1,0,3,102,0,0,
};


/*
PDProTech (c)2019. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.
 
Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2019/08/12              [WMC]
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include "batchcommon.h"
#include "common.h"
#include "utilitys.h"
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"
#include "ObjPtr.h"
#include "internal.h"
#include "gen_deposit_trace_report.h"
#define __USE_XOPEN
#include <time.h>

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char cs_start_datetime[PD_TMP_BUF_LEN+1];
char cs_end_datetime[PD_TMP_BUF_LEN+1];

static char    cDebug='Y';

OBJPTR(DB);
OBJPTR(BO);

int parse_arg(int argc,char **argv);
int GetDepositTracerRecords(const char *csStartDatetime, const char *csEndDatetime, recordset_t* myRec);
int CreateAlertEmailTpl(recordset_t *rRecordset);

int batch_init(int argc, char* argv[])
{
        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int     iRet = SUCCESS;
	int     iDtlRet = PD_ERR;

	recordset_t *rRecordset;
        rRecordset = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordset, 0);

DEBUGLOG(("batch_proc: Start!\n"));

	iRet = parse_arg(argc,argv);
	if (iRet == SUCCESS) {
DEBUGLOG((" Start Datetime = [%s][%d]\n",cs_start_datetime,strlen(cs_start_datetime)));
DEBUGLOG((" End Datetime = [%s][%d]\n",cs_end_datetime,strlen(cs_end_datetime)));
	} else {
		printf("*usage: -s START_DATE -e END_DATE\n");
		return FAILURE;
	}

        if (iRet == SUCCESS) {

		// Get Deposit Trace Record(s)
                iDtlRet = GetDepositTracerRecords(cs_start_datetime, cs_end_datetime, rRecordset);
		if (iDtlRet == PD_FOUND) {

			// Create Alert Email Template
                        iDtlRet = CreateAlertEmailTpl(rRecordset);
                        if (iDtlRet != PD_OK) {

                                iRet = FAILURE;
                        }

                } else if (iDtlRet == PD_NOT_FOUND) {
DEBUGLOG((" No Alert Email Send!!\n"));	
		} else {

                        iRet = FAILURE;
                }		
	}

	RecordSet_Destroy(rRecordset);
        FREE_ME(rRecordset);	

DEBUGLOG(("batch_proc: iRet = [%d]\n", iRet));
	return iRet;
}


int batch_terminate(int argc, char* argv[])
{
        return SUCCESS;
}


int parse_arg(int argc, char **argv)
{
	char	c;
	strcpy(cs_start_datetime,"");
	strcpy(cs_end_datetime,"");

	if (argc < 4) {
DEBUGLOG(("argc = [%d]\n",argc));
		return FAILURE;
	}

	while ((c = getopt(argc,argv,"s:e:")) != EOF) {
		switch (c) {
			case 's':
                                strcpy(cs_start_datetime, optarg);
                                break;
			case 'e':
                                strcpy(cs_end_datetime, optarg);
                                break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(cs_start_datetime,"") || !strcmp(cs_end_datetime,""))
		return FAILURE;

        return SUCCESS;
}


int GetDepositTracerRecords(const char *csStartDatetime, const char *csEndDatetime, recordset_t* myRec)
{
	int     iCnt = 0;
        hash_t  *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getdeptrcrec_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

               	/* varchar         hv_start_datetime[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_start_datetime;

                /* varchar         hv_end_datetime[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_end_datetime;


		/* varchar         v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar         v_psp_channel[PD_AC_BANK_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_psp_channel;

		double		v_amt;
		/* varchar         v_create_datetime[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_create_datetime;

		/* varchar         v_merch_ref[PD_MERCHANT_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merch_ref;

		/* varchar         v_trace_result[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_trace_result;

		/* varchar         v_trace_creator[PD_USER_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_trace_creator;

		/* varchar         v_trace_timestamp[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_trace_timestamp;


		short           ind_txn_id = -1;
		short           ind_psp_channel = -1;
		short           ind_amt = -1;
		short           ind_create_datetime = -1;
		short           ind_merch_ref = -1;
		short           ind_trace_result = -1;
		short           ind_trace_creator = -1;
		short           ind_trace_timestamp = -1;
		
                short           hv_return_value;

		SQL_CURSOR      c_cursor_getdeptrcrec;
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetDepositTracerRecords: Begin\n"));

	hv_start_datetime.len = strlen(csStartDatetime);
        memcpy(hv_start_datetime.arr, csStartDatetime, hv_start_datetime.len);
//DEBUGLOG((" start_datetime = [%.*s]\n", hv_start_datetime.len, hv_start_datetime.arr));

	hv_end_datetime.len = strlen(csEndDatetime);
        memcpy(hv_end_datetime.arr, csEndDatetime, hv_end_datetime.len);
//DEBUGLOG((" end_datetime = [%.*s]\n", hv_end_datetime.len, hv_end_datetime.arr));

	/* EXEC SQL ALLOCATE       :c_cursor_getdeptrcrec; */ 

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
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getdeptrcrec;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto getdeptrcrec_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                                :hv_return_value := sp_get_deposit_trace_txn_rec(to_date(:hv_start_datetime, 'YYYYMMDDHH24MISS'),
									 	 to_date(:hv_end_datetime, 'YYYYMMDDHH24MISS'),
									 	 :c_cursor_getdeptrcrec);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_get_deposit_trace_txn_r\
ec ( to_date ( :hv_start_datetime , 'YYYYMMDDHH24MISS' ) , to_date ( :hv_end_\
datetime , 'YYYYMMDDHH24MISS' ) , :c_cursor_getdeptrcrec ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )24;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_start_datetime;
        sqlstm.sqhstl[1] = (unsigned long )23;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_end_datetime;
        sqlstm.sqhstl[2] = (unsigned long )23;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&c_cursor_getdeptrcrec;
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
        if (sqlca.sqlcode < 0) goto getdeptrcrec_error;
}



DEBUGLOG((" hv_return_value = [%d]\n", hv_return_value));
        if (hv_return_value == SP_OK)
        {
		for (;;) {

			myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);

                        ind_txn_id = -1;
                        ind_psp_channel = -1;
                        ind_amt = -1;
                        ind_create_datetime = -1;
                        ind_merch_ref = -1;
                        ind_trace_result = -1;
                        ind_trace_creator = -1;
                        ind_trace_timestamp = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_getdeptrcrec

                        INTO
                                :v_txn_id:ind_txn_id,
                                :v_psp_channel:ind_psp_channel,
                                :v_amt:ind_amt,
                                :v_create_datetime:ind_create_datetime,
                                :v_merch_ref:ind_merch_ref,
                                :v_trace_result:ind_trace_result,
                                :v_trace_creator:ind_trace_creator,
                                :v_trace_timestamp:ind_trace_timestamp; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 9;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )55;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getdeptrcrec;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
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
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_psp_channel;
                        sqlstm.sqhstl[2] = (unsigned long )153;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_psp_channel;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_amt;
                        sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_amt;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_create_datetime;
                        sqlstm.sqhstl[4] = (unsigned long )23;
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_create_datetime;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_merch_ref;
                        sqlstm.sqhstl[5] = (unsigned long )53;
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_merch_ref;
                        sqlstm.sqinds[5] = (         int  )0;
                        sqlstm.sqharm[5] = (unsigned long )0;
                        sqlstm.sqadto[5] = (unsigned short )0;
                        sqlstm.sqtdso[5] = (unsigned short )0;
                        sqlstm.sqhstv[6] = (unsigned char  *)&v_trace_result;
                        sqlstm.sqhstl[6] = (unsigned long )53;
                        sqlstm.sqhsts[6] = (         int  )0;
                        sqlstm.sqindv[6] = (         short *)&ind_trace_result;
                        sqlstm.sqinds[6] = (         int  )0;
                        sqlstm.sqharm[6] = (unsigned long )0;
                        sqlstm.sqadto[6] = (unsigned short )0;
                        sqlstm.sqtdso[6] = (unsigned short )0;
                        sqlstm.sqhstv[7] = (unsigned char  *)&v_trace_creator;
                        sqlstm.sqhstl[7] = (unsigned long )23;
                        sqlstm.sqhsts[7] = (         int  )0;
                        sqlstm.sqindv[7] = (         short *)&ind_trace_creator;
                        sqlstm.sqinds[7] = (         int  )0;
                        sqlstm.sqharm[7] = (unsigned long )0;
                        sqlstm.sqadto[7] = (unsigned short )0;
                        sqlstm.sqtdso[7] = (unsigned short )0;
                        sqlstm.sqhstv[8] = (unsigned char  *)&v_trace_timestamp;
                        sqlstm.sqhstl[8] = (unsigned long )23;
                        sqlstm.sqhsts[8] = (         int  )0;
                        sqlstm.sqindv[8] = (         short *)&ind_trace_timestamp;
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
                        if (sqlca.sqlcode == 1403) break;
                        if (sqlca.sqlcode < 0) goto getdeptrcrec_error;
}



                        if (SQLCODE == SQL_NOT_FOUND) {
                                break;
                        }

/* txn_id */
                        if(ind_txn_id>=0){
                                v_txn_id.arr[v_txn_id.len]='\0';
                                PutField_CString(myHash,"txn_id",(const char*)v_txn_id.arr);
//DEBUGLOG((" txn_id = [%s]\n",v_txn_id.arr));
                        }

/* psp_channel */
                        if(ind_psp_channel>=0){
                                v_psp_channel.arr[v_psp_channel.len]='\0';
                                PutField_CString(myHash,"psp_channel",(const char*)v_psp_channel.arr);
//DEBUGLOG((" psp_channel = [%s]\n",v_psp_channel.arr));
                        }

/* amt */
			if(ind_amt>=0){
				PutField_Double(myHash, "amt", v_amt);
//DEBUGLOG((" amt = [%f]\n",v_amt));
			}

/* create_datetime */
                        if(ind_create_datetime>=0){
                                v_create_datetime.arr[v_create_datetime.len]='\0';
                                PutField_CString(myHash,"create_datetime",(const char*)v_create_datetime.arr);
//DEBUGLOG((" create_datetime = [%s]\n",v_create_datetime.arr));
                        }

/* merch_ref */
                        if(ind_merch_ref>=0){
                                v_merch_ref.arr[v_merch_ref.len]='\0';
                                PutField_CString(myHash,"merch_ref",(const char*)v_merch_ref.arr);
//DEBUGLOG((" merch_ref = [%s]\n",v_merch_ref.arr));
                        }

/* trace_result */
                        if(ind_trace_result>=0){
                                v_trace_result.arr[v_trace_result.len]='\0';
                                PutField_CString(myHash,"trace_result",(const char*)v_trace_result.arr);
//DEBUGLOG((" trace_result = [%s]\n",v_trace_result.arr));
                        }

/* trace_creator */
                        if(ind_trace_creator>=0){
                                v_trace_creator.arr[v_trace_creator.len]='\0';
                                PutField_CString(myHash,"trace_creator",(const char*)v_trace_creator.arr);
//DEBUGLOG((" trace_creator = [%s]\n",v_trace_creator.arr));
                        }

/* trace_timestamp */
                        if(ind_trace_timestamp>=0){
                                v_trace_timestamp.arr[v_trace_timestamp.len]='\0';
                                PutField_CString(myHash,"trace_timestamp",(const char*)v_trace_timestamp.arr);
//DEBUGLOG((" trace_timestamp = [%s]\n",v_trace_timestamp.arr));
                        }

			iCnt++;
			RecordSet_Add(myRec,myHash);
		}

DEBUGLOG(("GetDepositTracerRecords: Found\n"));
		return PD_FOUND;
        }
	else if (hv_return_value == SP_NOT_FOUND)
        {
DEBUGLOG(("GetDepositTracerRecords: Not Found\n"));
                return PD_NOT_FOUND;
        }
	else if (hv_return_value == SP_OTHER_ERR)
        {
DEBUGLOG(("GetDepositTracerRecords: SP_OTHER_ERR\n"));
ERRLOG("gen_deposit_trace_report:GetDepositTracerRecords SP_OTHER_ERR\n");
                return PD_OTHER_ERR;
        }
	else if (hv_return_value == SP_ERR)
        {
DEBUGLOG(("GetDepositTracerRecords: SP_ERR\n"));
ERRLOG("gen_deposit_trace_report:GetDepositTracerRecords SP_ERR\n");
                return PD_ERR;
        }

	/* EXEC SQL CLOSE :c_cursor_getdeptrcrec; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )106;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getdeptrcrec;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto getdeptrcrec_error;
}


        /* EXEC SQL FREE :c_cursor_getdeptrcrec; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )125;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getdeptrcrec;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode < 0) goto getdeptrcrec_error;
}



getdeptrcrec_error:
DEBUGLOG(("getdeptrcrec_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("gen_deposit_trace_report_Get: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE :c_cursor_getdeptrcrec; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )144;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getdeptrcrec;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
}


        /* EXEC SQL FREE :c_cursor_getdeptrcrec; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )163;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getdeptrcrec;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
}


        return PD_ERR;
}


int CreateAlertEmailTpl(recordset_t *rRecordset)
{
	int iRet = PD_OK;

	int iDynCnt = 0;
	int iCnt = 0;

	char csStartDatetime[PD_TIMESTAMP_LEN + 1];
        char csEndDatetime[PD_TIMESTAMP_LEN + 1];

	struct tm tStruct;

	hash_t *hRec;

	hash_t *hTemplate;
      	hTemplate = (hash_t*) malloc (sizeof(hash_t));
      	hash_init(hTemplate,0);
	
DEBUGLOG(("CreateAlertEmailTpl: Begin\n"));

	memset(csStartDatetime, 0, sizeof(csStartDatetime));
        memset(csEndDatetime, 0, sizeof(csEndDatetime));
	
	// Get Email Template Body Parameters	
	hRec = RecordSet_GetFirst(rRecordset);
    	while ((iRet == PD_OK) && (hRec)) {

		double dTmp = 0.0;

		char *csTmp = NULL;
	
		char csTag[PD_TAG_LEN+1];
		char csBuf[PD_TMP_BUF_LEN+1];
		
		memset(csTag, 0, sizeof(csTag));
		memset(csBuf, 0, sizeof(csBuf));

/* txn_id */
		if (GetField_CString(hRec,"txn_id",&csTmp)) {
DEBUGLOG((" [%d]txn_id = [%s]\n",iCnt,csTmp));
			sprintf(csTag, "ftxn_id-%d", iCnt);
                      	sprintf(csBuf, "%s", csTmp);
                     	iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, csTag, "STR", "stbl_body-0", csBuf);
		} else {
DEBUGLOG((" [%d]txn_id not found!!\n",iCnt));
ERRLOG("gen_deposit_trace_report:CreateAlertEmailTpl: txn_id not found!!\n");
			iRet = PD_ERR;
		}

/* psp_channel */
		if (iRet == PD_OK) {
                	if (GetField_CString(hRec,"psp_channel",&csTmp)) {
DEBUGLOG((" [%d]psp_channel = [%s]\n",iCnt,csTmp));
                	        sprintf(csTag, "fpsp_channel-%d", iCnt);
                	        sprintf(csBuf, "%s", csTmp);
                	        iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, csTag, "STR", "stbl_body-0", csBuf);
                	} else {
DEBUGLOG((" [%d]psp_channel not found!!\n",iCnt));
ERRLOG("gen_deposit_trace_report:CreateAlertEmailTpl: psp_channel not found!!\n");
                	        iRet = PD_ERR;
                	}
		}

/* amt */
		if (iRet == PD_OK) {
			if (GetField_Double(hRec,"amt",&dTmp)) {
DEBUGLOG((" [%d]amt = [%lf]\n",iCnt,dTmp));		
				sprintf(csTag, "famt-%d", iCnt);
				sprintf(csBuf, "%s", commaprintdouble(dTmp,PD_DECIMAL_LEN));
                	        iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, csTag, "STR", "stbl_body-0", csBuf);
			} else {
DEBUGLOG((" [%d]amt not found!!\n",iCnt));
ERRLOG("gen_deposit_trace_report:CreateAlertEmailTpl: amt not found!!\n");
                	        iRet = PD_ERR;
			}
		}

/* create_datetime */
		if (iRet == PD_OK) {
                	if (GetField_CString(hRec,"create_datetime",&csTmp)) {
DEBUGLOG((" [%d]create_datetime = [%s]\n",iCnt,csTmp));
                	        sprintf(csTag, "fcreate_datetime-%d", iCnt);
                	        sprintf(csBuf, "%s", csTmp);
                	        iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, csTag, "STR", "stbl_body-0", csBuf);
                	} else {
DEBUGLOG((" [%d]create_datetime not found!!\n",iCnt));
ERRLOG("gen_deposit_trace_report:CreateAlertEmailTpl: create_datetime not found!!\n");
                	        iRet = PD_ERR;
			}
		}

/* merch_ref */
		if (iRet == PD_OK) {
                	if (GetField_CString(hRec,"merch_ref",&csTmp)) {
DEBUGLOG((" [%d]merch_ref = [%s]\n",iCnt,csTmp));
                	        sprintf(csTag, "fmerch_ref-%d", iCnt);
                	        sprintf(csBuf, "%s", csTmp);
                	        iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, csTag, "STR", "stbl_body-0", csBuf);
                	} else {
DEBUGLOG((" [%d]merch_ref not found!!\n",iCnt));
ERRLOG("gen_deposit_trace_report:CreateAlertEmailTpl: merch_ref not found!!\n");
                	        iRet = PD_ERR;
			}
		}

/* trace_result */
		if (iRet == PD_OK) {
                	if (GetField_CString(hRec,"trace_result",&csTmp)) {
DEBUGLOG((" [%d]trace_result = [%s]\n",iCnt,csTmp));
                	        sprintf(csTag, "ftrace_result-%d", iCnt);
                	        sprintf(csBuf, "%s", csTmp);
                	        iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, csTag, "STR", "stbl_body-0", csBuf);
               	 	} else {
DEBUGLOG((" [%d]trace_result = [ ]\n",iCnt));
				sprintf(csTag, "ftrace_result-%d", iCnt);
				sprintf(csBuf, "%s", " ");
			}
			iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, csTag, "STR", "stbl_body-0", csBuf);
		}

/* trace_creator */
		if (iRet == PD_OK) {
                	if (GetField_CString(hRec,"trace_creator",&csTmp)) {
DEBUGLOG((" [%d]trace_creator = [%s]\n",iCnt,csTmp));
                	        sprintf(csTag, "ftrace_creator-%d", iCnt);
                	        sprintf(csBuf, "%s", csTmp);
                	} else {
DEBUGLOG((" [%d]trace_creator = [ ]\n",iCnt));
                	        sprintf(csTag, "ftrace_creator-%d", iCnt);
                	        sprintf(csBuf, "%s", " ");		
			}
			iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, csTag, "STR", "stbl_body-0", csBuf);
		}

/* trace_timestamp */
		if (iRet == PD_OK) {
                	if (GetField_CString(hRec,"trace_timestamp",&csTmp)) {
DEBUGLOG((" [%d]trace_timestamp = [%s]\n",iCnt,csTmp));
                	        sprintf(csTag, "ftrace_timestamp-%d", iCnt);
                	        sprintf(csBuf, "%s", csTmp);
                	        iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, csTag, "STR", "stbl_body-0", csBuf);
                	} else {
DEBUGLOG((" [%d]trace_timestamp = [ ]\n",iCnt));
                	        sprintf(csTag, "ftrace_timestamp-%d", iCnt);
                	        sprintf(csBuf, "%s", " ");
			}
			iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, csTag, "STR", "stbl_body-0", csBuf);
		}

		iCnt++;

              	hRec = RecordSet_GetNext(rRecordset);
	}

	if (iRet == PD_OK) {

            	// Record(s) Exists
             	if (iCnt > 0) {

			// Get Email Template Global Parameters
			/* start datetime */
			memset(&tStruct, 0, sizeof(struct tm));
			strptime(cs_start_datetime, PD_IN_DATETIME_FORMAT, &tStruct);
                    	strftime(csStartDatetime, sizeof(csStartDatetime), PD_TITLE_DATETIME_FORMAT, &tStruct);
			iDynCnt = set_tpl_dyn_cstring(hTemplate,iDynCnt,"fstart_datetime","GLO","STR",csStartDatetime);

			/* end datetime */
			memset(&tStruct, 0, sizeof(struct tm));
                        strptime(cs_end_datetime, PD_IN_DATETIME_FORMAT, &tStruct);
                        strftime(csEndDatetime, sizeof(csEndDatetime), PD_TITLE_DATETIME_FORMAT, &tStruct);
			iDynCnt = set_tpl_dyn_cstring(hTemplate,iDynCnt,"fend_datetime","GLO","STR",csEndDatetime);

			// Get Email Template Section Parameters
			iDynCnt = set_tpl_dyn_int(hTemplate, iDynCnt, "stbl_head-0", "SEC", "stbl_head-0", 0);
                       	iDynCnt = set_tpl_dyn_int(hTemplate, iDynCnt, "stbl_body-0", "SEC", "stbl_body-0", iCnt);

	    		PutField_CString(hTemplate, "funct", PD_EML_FUNCT_DEP_TRC_REPORT);
	    		PutField_CString(hTemplate, "source", PD_EML_SOURCE_BATCH);
	  		PutField_Char(hTemplate, "party_type", PD_TYPE_GLOBAL);
	    		PutField_CString(hTemplate, "party_id", PD_EML_PARTY_ID_BATCH);	
	   		PutField_Int(hTemplate, "total_dyn", iDynCnt);

			// Call BOAlertEmail
			BOObjPtr = CreateObj(BOPtr, "BOAlertEmail", "ProcessTpl");
			iRet = (unsigned long)((*BOObjPtr)(hTemplate));
	            	if (iRet == PD_OK) {
DEBUGLOG((" BOAlertEmail:ProcessTpl Success!!\n"));
			} else {
DEBUGLOG((" BOAlertEmail:ProcessTpl Failure!!\n"));
	                   	PutField_Int(hTemplate, "internal_error", iRet);
	            	}	
		}
	}

	hash_destroy(hTemplate);
      	FREE_ME(hTemplate);

DEBUGLOG(("CreateAlertEmailTpl: iRet = [%d]\n", iRet));
	return iRet;
}

