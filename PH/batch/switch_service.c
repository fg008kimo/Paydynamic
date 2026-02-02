
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
    "switch_service.pc"
};


static unsigned int sqlctx = 10774163;


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
   unsigned char  *sqhstv[2];
   unsigned long  sqhstl[2];
            int   sqhsts[2];
            short *sqindv[2];
            int   sqinds[2];
   unsigned long  sqharm[2];
   unsigned long  *sqharc[2];
   unsigned short  sqadto[2];
   unsigned short  sqtdso[2];
} sqlstm = {12,2};

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
"SELECT vp_code , vp_val FROM voucher_payment_parameter            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,66,0,9,98,0,2049,0,0,0,1,0,
20,0,0,1,0,0,13,101,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
43,0,0,1,0,0,15,121,0,0,0,0,0,1,0,
58,0,0,1,0,0,15,138,0,0,0,0,0,1,0,
73,0,0,2,0,0,17,317,0,0,1,1,0,1,0,1,9,0,0,
92,0,0,2,0,0,21,318,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/10/04              LokMan Chow
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
#include "dbutility.h"
#include "batchcommon.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cs_mode[PD_DATE_LEN + 1];
//char    cs_client_id[PD_CLIENT_ID_LEN + 1];
char	cDebug = 'Y';

int	parse_arg(int argc,char **argv);
int	switch_service(const hash_t* hTxn);
int	find_parameters(hash_t* hTxn);
//int	send_notification(const hash_t* hTxn);
int	update_value(const unsigned char* code,
                 const unsigned char* value);

int batch_init(int argc, char* argv[])
{
        return SUCCESS;
}


int batch_terminate(int argc, char* argv[])
{
    return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int iRet = SUCCESS;
	hash_t* hTxn;
	hTxn = (hash_t*)  malloc (sizeof(hash_t));
	hash_init(hTxn,0);

	iRet = parse_arg(argc,argv);
	if(iRet != SUCCESS){
		printf("usage: -m switch mode [P2S] / [S2P] / [CLS]\n");
		return (iRet);
	}

	if(iRet==SUCCESS){
		iRet = find_parameters(hTxn);
	}
	if(iRet==SUCCESS){
		if(strcmp(cs_mode,"CLS")){
			iRet = switch_service(hTxn);
		}
		else{
			iRet = close_sec_service(hTxn);
		}
	}
	FREE_ME(hTxn);
	return iRet;
}

int find_parameters(hash_t* hTxn)
{
	int	iCnt = 0;

DEBUGLOG(("find_parameters: Begin\n"));
	/* EXEC SQL WHENEVER SQLERROR GOTO find_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar v_code[PD_SP_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_code;

		/* varchar v_value[PD_SP_VALUE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_value;


		short   ind_code = -1;
		short   ind_value = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	/* EXEC SQL DECLARE c_cursor_getallcodes CURSOR FOR
		SELECT  vp_code,
			vp_val
		FROM    voucher_payment_parameter; */ 


	/* EXEC SQL OPEN c_cursor_getallcodes; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 0;
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
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto find_error;
}


	do {

		/* EXEC SQL FETCH c_cursor_getallcodes
		INTO
			:v_code:ind_code,
			:v_value:ind_value; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 2;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )20;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_code;
  sqlstm.sqhstl[0] = (unsigned long )53;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_code;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_value;
  sqlstm.sqhstl[1] = (unsigned long )53;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_value;
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
  if (sqlca.sqlcode < 0) goto find_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		if (ind_code >= 0 && ind_value >= 0) {
			v_code.arr[v_code.len] ='\0';
			v_value.arr[v_value.len] ='\0';
			PutField_CString(hTxn,(const char*)v_code.arr,(const char*)v_value.arr);
DEBUGLOG(("find_parameters : [%s] = [%s]\n",v_code.arr,v_value.arr));

			iCnt ++;
		}
	}
	while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getallcodes; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )43;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto find_error;
}




	if(iCnt==0){
DEBUGLOG(("find_parameters Record Not Found!\n"));
		return PD_SKIP_OK;
	}
	else{
DEBUGLOG(("find_parameters Record Found!\n"));
		return SUCCESS;
	}

find_error:
DEBUGLOG(("find_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("switch_service::find_error code %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getallcodes; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 2;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )58;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}



int switch_service(const hash_t* hTxn)
{
	int	iRet = PD_SKIP_OK;
	int	iUpdate = PD_FALSE;
	char	csTag[PD_TAG_LEN+1];
	char	csToTag[PD_TAG_LEN+1];
	char	csVPClose[PD_TAG_LEN+1];
	char*	csTmp;
	char	cAutoSwitch = PD_NO;
	char	cToEnable = PD_NO;
	char*	csPriService;
	char*	csToService;
	char*	csToStatus = NULL;
	char*	csPriStatus = NULL;

	if(GetField_CString(hTxn,PD_AUTO_SWITCH,&csTmp)){
		cAutoSwitch = csTmp[0];
DEBUGLOG(("switch_service: [%s] = [%c]\n",PD_AUTO_SWITCH,cAutoSwitch));
	}

	if(cAutoSwitch == PD_YES){
		if(GetField_CString(hTxn,PD_PRIMARY_SERVICE,&csPriService)){
			sprintf(csTag,"%s%s",csPriService,PD_VP_SWITCH_TO);
			if(GetField_CString(hTxn,csTag,&csToService)){
				sprintf(csTag,"%s%s",csToService,PD_VP_STATUS);
				if(GetField_CString(hTxn,csTag,&csToStatus)){
DEBUGLOG(("switch_service: [%s] = [%s]\n",csTag,csToStatus));
				}
				sprintf(csTag,"%s%s",csToService,PD_VP_ENABLE);
				if(GetField_CString(hTxn,csTag,&csTmp)){
					cToEnable = csTmp[0];
DEBUGLOG(("switch_service: [%s] = [%c]\n",csTag,cToEnable));
				}
			}
			sprintf(csTag,"%s%s",csPriService,PD_VP_STATUS);
			if(GetField_CString(hTxn,csTag,&csPriStatus)){
DEBUGLOG(("switch_service: [%s] = [%s]\n",csTag,csPriStatus));
			}
		}

		if(!strcmp(cs_mode,"S2P")){
			if(!strcmp(csPriStatus,PD_VP_CLOSE) &&
			   !strcmp(csToStatus,PD_VP_OPEN)){

				iUpdate = PD_TRUE;
			}
		}
		else if(!strcmp(cs_mode,"P2S")){
			if(cToEnable==PD_YES &&
		   	   !strcmp(csPriStatus,PD_VP_OPEN) &&
			   !strcmp(csToStatus,PD_VP_CLOSE)){

				iUpdate = PD_TRUE;
			}
		}
	}

	if(iUpdate == PD_TRUE){
		if(!strcmp(cs_mode,"P2S")){
			sprintf(csTag,"%s%s",csPriService,PD_VP_STATUS);
			sprintf(csToTag,"%s%s",csToService,PD_VP_STATUS);
			sprintf(csVPClose,"%s",PD_VP_CLOSE);
		}
		else{
			sprintf(csTag,"%s%s",csToService,PD_VP_STATUS);
			sprintf(csToTag,"%s%s",csPriService,PD_VP_STATUS);
			sprintf(csVPClose,"%s",PD_VP_WAITING_TO_CLOSE);
		}

		if(update_value((const unsigned char*)csTag,(const unsigned char*)csVPClose)==SUCCESS &&
		   update_value((const unsigned char*)csToTag,(const unsigned char*)PD_VP_OPEN)==SUCCESS){
			iRet = SUCCESS;
		}
		else{
			iRet = FAILURE;
		}
	}

DEBUGLOG(("switch_service Normal Exit [%d]\n",iRet));
	return iRet;
}

int close_sec_service(const hash_t* hTxn)
{
	int	iRet = PD_SKIP_OK;
	int	iUpdate = PD_FALSE;
	char	csTag[PD_TAG_LEN+1];
	char	csVPClose[PD_TAG_LEN+1];
	char*	csTmp;
	char	cAutoSwitch = PD_NO;
	char	cToEnable = PD_NO;
	char*	csPriService;
	char*	csToService;
	char*	csToStatus = NULL;
	char*	csPriStatus = NULL;

	if(GetField_CString(hTxn,PD_AUTO_SWITCH,&csTmp)){
		cAutoSwitch = csTmp[0];
DEBUGLOG(("close_sec_service: [%s] = [%c]\n",PD_AUTO_SWITCH,cAutoSwitch));
	}

	if(cAutoSwitch == PD_YES){
		if(GetField_CString(hTxn,PD_PRIMARY_SERVICE,&csPriService)){
			sprintf(csTag,"%s%s",csPriService,PD_VP_SWITCH_TO);
			if(GetField_CString(hTxn,csTag,&csToService)){
				sprintf(csTag,"%s%s",csToService,PD_VP_STATUS);
				if(GetField_CString(hTxn,csTag,&csToStatus)){
DEBUGLOG(("close_sec_service: [%s] = [%s]\n",csTag,csToStatus));
				}
			}
			sprintf(csTag,"%s%s",csPriService,PD_VP_STATUS);
			if(GetField_CString(hTxn,csTag,&csPriStatus)){
DEBUGLOG(("close_sec_service: [%s] = [%s]\n",csTag,csPriStatus));
			}
		}

		if(!strcmp(cs_mode,"CLS")){
			if(!strcmp(csPriStatus,PD_VP_OPEN) &&
			   !strcmp(csToStatus,PD_VP_WAITING_TO_CLOSE)){

				iUpdate = PD_TRUE;
			}
		}
	}

	if(iUpdate == PD_TRUE){
		if(!strcmp(cs_mode,"CLS")){
			sprintf(csTag,"%s%s",csToService,PD_VP_STATUS);
			sprintf(csVPClose,"%s",PD_VP_CLOSE);
		}

		if(update_value((const unsigned char*)csTag,(const unsigned char*)csVPClose)==SUCCESS){
			iRet = SUCCESS;
		}
		else{
			iRet = FAILURE;
		}
	}

DEBUGLOG(("switch_service Normal Exit [%d]\n",iRet));
	return iRet;
}

int update_value(const unsigned char* code,
                 const unsigned char* value)
{
        char*   csBuf;

        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("update_value: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update voucher_payment_parameter set vp_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        strcat((char*)hv_dynstmt.arr, ",vp_val = '");
        strcat((char*)hv_dynstmt.arr, (const char*)value);
        strcat((char*)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        strcat((char *)hv_dynstmt.arr, " WHERE vp_code = '");
        strcat((char *)hv_dynstmt.arr, (const char*)code);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )73;
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
        if (sqlca.sqlcode < 0) goto update_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )92;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_error;
}



        FREE_ME(csBuf);
DEBUGLOG(("update_value Normal Exit\n"));
        return SUCCESS;

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("VoucherPaymentParameter: update_value: SP_INTERNAL_ERR\n");
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return FAILURE;
}


/*
int	send_notification(const hash_t* hTxn)
{
	int	iRet = SUCCESS;
	char*	csPriService;
	char*	csToService;
	char	csTag[PD_TAG_LEN+1];
	
DEBUGLOG(("send_notification: Begin\n"));

	if(GetField_CString(hTxn,PD_PRIMARY_SERVICE,&csPriService)){
		sprintf(csTag,"%s%s",csPriService,PD_VP_SWITCH_TO);
		if(GetField_CString(hTxn,csTag,&csToService)){
DEBUGLOG(("send_notification: Primary Service [%s], Secondary Service [%s]\n",csPriService,csToService));
		}
	}

	if(!strcmp(cs_mode,"P2S")){
DEBUGLOG(("send_notification: Primary -> Secondary\n"));
		//send notification "VHS" on
		//call xxx.sh csToService cs_client_id "enable"
	}
	else{
DEBUGLOG(("send_notification: Secondary -> Primary\n"));
		//send notification "VHS" off
		//call xxx.sh csToService cs_client_id "disable"
	}

	return iRet;
}
*/

int parse_arg(int argc,char **argv)
{
	char    c;
	strcpy(cs_mode,"");
	//strcpy(cs_client_id,"");

	while ((c = getopt(argc,argv,"m:")) != EOF) {
		switch (c) {
			case 'm':
				strcpy(cs_mode, optarg);
				cs_mode[strlen(cs_mode)]='\0';
				break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(cs_mode,""))
		return FAILURE;

	return SUCCESS;
}

