
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
           char  filnam[22];
};
static struct sqlcxp sqlfpn =
{
    21,
    "tmp_ex_rate_report.pc"
};


static unsigned int sqlctx = 172105147;


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
   unsigned char  *sqhstv[3];
   unsigned long  sqhstl[3];
            int   sqhsts[3];
            short *sqindv[3];
            int   sqinds[3];
   unsigned long  sqharm[3];
   unsigned long  *sqharc[3];
   unsigned short  sqadto[3];
   unsigned short  sqtdso[3];
} sqlstm = {12,3};

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
"SELECT TO_CHAR ( TO_DATE ( :b0 , 'YYYYMMDD' ) , 'YYYYMMDD' ) - 1 + rownum A\
S d FROM all_objects WHERE TO_DATE ( :b0 , 'YYYYMMDD' ) - 1 + rownum <= TO_DA\
TE ( :b2 , 'YYYYMMDD' ) ORDER BY d DESC            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,203,0,9,220,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
32,0,0,1,0,0,13,232,0,0,1,0,0,1,0,2,9,0,0,
51,0,0,1,0,0,15,303,0,0,0,0,0,1,0,
66,0,0,1,0,0,15,316,0,0,0,0,0,1,0,
81,0,0,2,0,0,32,317,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/10/23	           Dirk Wong

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
#include "batchcommon.h"
#include "common.h"
#include "utilitys.h"
#include "myhash.h"
#include "eod_crr_glpost.h"
#include "ObjPtr.h"
#include <sqlca.h>

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define PD_MY_DELIMITOR ','

OBJPTR(Txn);

char    cDebug = 'Y';
char	cs_merch_id[PD_MERCHANT_ID_LEN + 1];
char    cs_country[PD_COUNTRY_CODE_LEN + 1];
char	cs_service_code[PD_SERVICE_CODE_LEN + 1];
char    cs_date_fr[PD_DATE_LEN + 1];
char    cs_date_to[PD_DATE_LEN + 1];
char	cs_time[PD_TIME_LEN + 1];

int parse_arg(int argc,char **argv);
int callMGTFXR(FILE *fp);

int batch_init(int argc, char* argv[])
{
	if (argc < 6) {
		printf("usage: -m MerchID -c Country -s Service -d StartDate -e EndDate -t Time\n");
	    return FAILURE;
	}
	else
	    return SUCCESS;
}

int batch_proc(int argc, char* argv[])
{
	int	iRet;
	char	cs_outfile_name[PD_MAX_FILE_LEN + 1];
	FILE	*fp;
	
	iRet = parse_arg(argc,argv);

	if (iRet != SUCCESS) {
    	printf("*usage: -m MerchID -c Country -s Service -d StartDate -e EndDate -t Time\n");
		return (iRet);
	}

	sprintf(cs_outfile_name, "%s/tmp_ex_rate_report.csv",getenv("HOME"));

	fp = fopen(cs_outfile_name,"w");
	if (fp == NULL) {
DEBUGLOG(("ERROR! unable to open file\n"));
		return FAILURE;
	}
			
	if (iRet == SUCCESS) {
DEBUGLOG(("MerchID = [%s]\n",cs_merch_id));
DEBUGLOG(("Country = [%s]\n",cs_country));
DEBUGLOG(("Service = [%s]\n",cs_service_code));
DEBUGLOG(("Start Date = [%s]\n",cs_date_fr));
DEBUGLOG(("End Date = [%s]\n",cs_date_to));
DEBUGLOG(("Time = [%s]\n",cs_time));
		
		iRet = callMGTFXR(fp);
	}

	fclose(fp);

DEBUGLOG(("End = [%d]\n",iRet));
	return iRet;

}

int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}
                     
int parse_arg(int argc,char **argv)
{
	char    c;
	          
	while ((c = getopt(argc,argv,"m:c:s:d:e:t:")) != EOF) {
	  switch (c) {
		case 'm':
				strcpy(cs_merch_id, optarg);
				break;
		case 'c':
				strcpy(cs_country, optarg);
				break;
		case 's':
				strcpy(cs_service_code, optarg);
				break;
		case 'd':
				strcpy(cs_date_fr, optarg);
				break;
		case 'e':
				strcpy(cs_date_to, optarg);
				break;
		case 't':
				strcpy(cs_time, optarg);
				break;				  
		  default:
				  return FAILURE;
	  }
	}       
	
	if ((!strcmp(cs_merch_id,"")) || (!strcmp(cs_country,"")) || (!strcmp(cs_service_code,""))  || (!strcmp(cs_date_fr,"")) || (!strcmp(cs_date_to,"")) || (!strcmp(cs_time,"")))
	  return FAILURE;
	  
	return SUCCESS; 
}

int callMGTFXR(FILE *fp) {
	int	iRet = PD_OK;
	char	csTag[PD_TAG_LEN +1];
	char	*csTmp;
	double	dTmp = 0.0;

	hash_t	*hReq;
	hReq = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hReq,0);

	hash_t	*hRsp;
	hRsp = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRsp,0);

	// merchant_id
DEBUGLOG(("callMGTFXR(): merchant_id = [%s]\n",cs_merch_id));
	PutField_CString(hReq,"merchant_id",cs_merch_id);

	// txn_country //
DEBUGLOG(("callMGTFXR(): txn_country = [%s]\n",cs_country));
	PutField_CString(hReq,"txn_country",cs_country);

	// service_code //
DEBUGLOG(("callMGTFXR(): service = [%s]\n",cs_service_code));
	PutField_CString(hReq,"service_code",cs_service_code);

	// from_ccy //
	PutField_CString(hReq,"fr_ccy","CNY");

	// to_ccy //
	PutField_CString(hReq,"to_ccy","HKD");
	PutField_CString(hReq,"dst_txn_ccy","HKD");

	// total_cnt //
	PutField_Int(hReq,"total_cnt",2);

	// channel_code_1 //
	PutField_CString(hReq,"dt_channel_1","WEB");

	// type_1 //
	PutField_CString(hReq,"dt_type_1","DSI");

	// desc_1 //
	PutField_CString(hReq,"dt_desc_1","Deposit");

	// channel_code_2 //
	PutField_CString(hReq,"dt_channel_2","MGT");

	// type_2 //
	PutField_CString(hReq,"dt_type_2","POA");

	// desc_2 //
	PutField_CString(hReq,"dt_desc_2","Payout");

	// post_user //
DEBUGLOG(("callMGTFXR(): post_user = [%s]\n",PD_UPDATE_USER));
	PutField_CString(hReq,"post_user",PD_UPDATE_USER);
			

	// time //
DEBUGLOG(("callMGTFXR(): time = [%s]\n",cs_time));

	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar hv_date_fr[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_date_fr;

		/* varchar hv_date_to[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_date_to;


		/* varchar	v_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_date;

		short	ind_date = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_date_fr.len = strlen(cs_date_fr);
	memcpy(hv_date_fr.arr,cs_date_fr,hv_date_fr.len);

	hv_date_to.len = strlen(cs_date_to);
	memcpy(hv_date_to.arr,cs_date_to,hv_date_to.len);

	/* EXEC SQL DECLARE c_cursor_getinfo CURSOR FOR

		SELECT	TO_CHAR(TO_DATE(:hv_date_fr, 'YYYYMMDD'),'YYYYMMDD') - 1 + rownum AS d
		  FROM	all_objects
		 WHERE	TO_DATE(:hv_date_fr, 'YYYYMMDD') - 1 + rownum <= TO_DATE(:hv_date_to, 'YYYYMMDD')
		ORDER BY d DESC; */ 


	/* EXEC SQL OPEN c_cursor_getinfo; */ 

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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_date_fr;
 sqlstm.sqhstl[0] = (unsigned long )10;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_date_fr;
 sqlstm.sqhstl[1] = (unsigned long )10;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_date_to;
 sqlstm.sqhstl[2] = (unsigned long )10;
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



	fprintf(fp,"%s%c%s%c%s%c%s%c%s%c%s%c%s\n",
			"Date/Time",PD_MY_DELIMITOR,
			"Transaction Type",PD_MY_DELIMITOR,
			"From Currency",PD_MY_DELIMITOR,
			"To Currency",PD_MY_DELIMITOR,
			"SOR",PD_MY_DELIMITOR,
			"ACR/O",PD_MY_DELIMITOR,
			"Favouable Rate before Markup");

	do {
		/* EXEC SQL FETCH c_cursor_getinfo
		INTO
			:v_date:ind_date; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 3;
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
  sqlstm.sqhstv[0] = (unsigned char  *)&v_date;
  sqlstm.sqhstl[0] = (unsigned long )11;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_date;
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
  if (sqlca.sqlcode < 0) goto sql_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
DEBUGLOG(("Finish!\n"));
			break;
		}

		if (ind_date >= 0) {
			sprintf(csTag,"%.*s%s",v_date.len,v_date.arr,cs_time);
DEBUGLOG(("CallMGTFXR(): datetime = [%s]\n",csTag));
			PutField_CString(hReq,"datetime",csTag);
		}
		fprintf(fp,"%s%c",csTag,PD_MY_DELIMITOR);

		// Call TxnObj
		TxnObjPtr = CreateObj(TxnPtr,"TxnMgtByUsFXR","Authorize");
		iRet = (unsigned long) ((*TxnObjPtr)(hReq,hReq,hRsp));

		if (GetField_CString(hRsp,"txn_type_1",&csTmp)) {
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		}

		if (GetField_CString(hRsp,"ccy_1",&csTmp)) {
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		}

		if (GetField_CString(hRsp,"to_ccy_1",&csTmp)) {
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		}

		if (GetField_Double(hRsp,"ext_rate_1",&dTmp)) {
			fprintf(fp,"%f%c",dTmp,PD_MY_DELIMITOR);
		}

		if (GetField_Double(hRsp,"ex_int_rate_1",&dTmp)) {
			fprintf(fp,"%f%c",dTmp,PD_MY_DELIMITOR);
		}

		if (GetField_Double(hRsp,"rate_1",&dTmp)) {
			fprintf(fp,"%f\n",dTmp);
		}

		fprintf(fp,"%s%c",csTag,PD_MY_DELIMITOR);

		if (GetField_CString(hRsp,"txn_type_2",&csTmp)) {
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		}

		if (GetField_CString(hRsp,"ccy_2",&csTmp)) {
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		}

		if (GetField_CString(hRsp,"to_ccy_2",&csTmp)) {
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		}

		if (GetField_Double(hRsp,"ext_rate_2",&dTmp)) {
			fprintf(fp,"%f%c",dTmp,PD_MY_DELIMITOR);
		}

		if (GetField_Double(hRsp,"ex_int_rate_2",&dTmp)) {
			fprintf(fp,"%f%c",dTmp,PD_MY_DELIMITOR);
		}

		if (GetField_Double(hRsp,"rate_2",&dTmp)) {
			fprintf(fp,"%f\n",dTmp);
		}

	} while(PD_TRUE && iRet == SUCCESS);
	/* EXEC SQL CLOSE c_cursor_getinfo; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )51;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto sql_error;
}




	FREE_ME(hReq);
	FREE_ME(hRsp);
	
DEBUGLOG(("End callMGTFXR and return:[%d]\n",iRet));
	return iRet;

sql_error:
DEBUGLOG(("check_new_baid_alert error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getinfo; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 3;
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


    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 3;
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
