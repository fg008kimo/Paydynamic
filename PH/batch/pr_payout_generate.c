
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
    "pr_payout_generate.pc"
};


static unsigned int sqlctx = 172119075;


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
   unsigned char  *sqhstv[23];
   unsigned long  sqhstl[23];
            int   sqhsts[23];
            short *sqindv[23];
            int   sqinds[23];
   unsigned long  sqharm[23];
   unsigned long  *sqharc[23];
   unsigned short  sqadto[23];
   unsigned short  sqtdso[23];
} sqlstm = {12,23};

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
"select ppm_preset_pid  from par_psp_client_map where ppm_psp_type_cd=:b0   \
        ";

 static char *sq0004 = 
"select ud_batch_id ,ud_txn_id  from merchant_upload_file_detail where (ud_v\
nc_ref_num=:b0 and ud_seq_num=:b1)           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,66,0,4,325,0,0,1,0,0,1,0,2,68,0,0,
24,0,0,2,83,0,9,380,0,0,1,1,0,1,0,1,9,0,0,
43,0,0,2,0,0,13,382,0,0,1,0,0,1,0,2,9,0,0,
62,0,0,2,0,0,15,404,0,0,0,0,0,1,0,
77,0,0,2,0,0,15,445,0,0,0,0,0,1,0,
92,0,0,3,428,0,6,580,0,0,13,13,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,
9,0,0,1,3,0,0,1,4,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,4,0,0,1,3,0,0,
159,0,0,4,120,0,9,951,0,0,2,2,0,1,0,1,9,0,0,1,3,0,0,
182,0,0,4,0,0,13,953,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
205,0,0,4,0,0,15,981,0,0,0,0,0,1,0,
220,0,0,4,0,0,15,991,0,0,0,0,0,1,0,
235,0,0,5,739,0,6,1225,0,0,23,23,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,9,0,0,
1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,4,0,0,1,4,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,9,0,0,
342,0,0,6,0,0,17,1595,0,0,1,1,0,1,0,1,9,0,0,
361,0,0,6,0,0,21,1596,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/06/28              LokMan Chow
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
#include "pr_payout_generate.h"
#include "internal.h"
#include "ObjPtr.h"
#include "pr_bo_funct.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug = 'Y';
char    cs_hdfile[PD_MAX_FILE_LEN + 1];
char    cs_dtfile[PD_MAX_FILE_LEN + 1];
char    csCcySet[10][4]={"CNY","HKD","GBP","USD","CAD","JPY"," ","EUR","TWD","INR"};

OBJPTR(DB);

int 	parse_arg(int argc,char **argv);
int     parse_header(FILE *fin,hash_t * hTxn);
int     process_header(hash_t *hTxn);
int     parse_detail(FILE *fin,hash_t * hTxn);
int     process_detail(hash_t *hTxn);
int	GetFileId(unsigned long *lFileId);
int	ConvertField(hash_t *hTxn, const int iFile);
int     AddGenerateHeader(const hash_t *hRls);
int 	UpdateGenerateHeader(const hash_t *hRls);
int     AddGenerateDetail(const hash_t *hRls);
int	FindBatchId(hash_t *hTxn);
//char*	GetNextPayoutTxnSeq();
int	handle_psp_balance(hash_t * hTxn);
int	generate_new_txn(hash_t * hTxn);
//char*	GetNextMgtTxnSeq();
int	UpdateGenerateHeader(const hash_t *hRec);

int batch_init(int argc, char* argv[])
{
    if (argc < 2) {
        printf("usage:  -h header_file -t detail_file\n");
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
		printf("usage:  -h header_file -t detail_file\n");
                return (iRet);
	}

        fin = fopen(cs_hdfile,"r");
        
        if (fin == NULL) {
DEBUGLOG(("Error Opening header file = [%s]\n",cs_hdfile));
                return FAILURE;
        }


	if (parse_header(fin,hTxn) != FAILURE)  {
        	fin = fopen(cs_dtfile,"r");

        	iRet = parse_detail(fin,hTxn);
        	fclose(fin);
	}

	if (iRet != FAILURE)  {
		iRet = handle_psp_balance(hTxn);
	}

	if (iRet != FAILURE)  {
		iRet = generate_new_txn(hTxn);
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
		PutField_Int(hTxn,"file_count",iRecord);

		if(iRet==SUCCESS){
			for(iCount=0;iCount<i;iCount++){
				if(iCount==IDX_HEADER_FILE_ID)
					sprintf(csTag,"vnc_file_id_%d",iRecord);
				else if(iCount==IDX_HEADER_FILE_SEQ)
					sprintf(csTag,"file_seq_%d",iRecord);
				else if(iCount==IDX_HEADER_FILENAME)
					sprintf(csTag,"filename_%d",iRecord);
				else if(iCount==IDX_HEADER_FILE_DATE)
					sprintf(csTag,"date_%d",iRecord);
				else if(iCount==IDX_HEADER_TOTAL_COUNT)
					sprintf(csTag,"txn_count_%d",iRecord);
				else if(iCount==IDX_HEADER_TOTAL_AMT)
					sprintf(csTag,"total_txn_amt_%d",iRecord);
				else if(iCount==IDX_HEADER_STATUS)
					sprintf(csTag,"status_%d",iRecord);
				else if(iCount==IDX_HEADER_PSP)
					sprintf(csTag,"psp_%d",iRecord);
				else if(iCount==IDX_HEADER_MEMBER_FEE_CCY_ID)
					sprintf(csTag,"member_fee_ccy_%d",iRecord);
				else if(iCount==IDX_HEADER_MEMBER_FEE)
					sprintf(csTag,"member_fee_%d",iRecord);
				else if(iCount==IDX_HEADER_MERCHANT_FEE_CCY_ID)
					sprintf(csTag,"merchant_fee_ccy_%d",iRecord);
				else if(iCount==IDX_HEADER_MERCHANT_FEE)
					sprintf(csTag,"merchant_fee_%d",iRecord);
				else
					sprintf(csTag,"not_care");

				PutField_CString(hTxn,csTag,csList[iCount]);
DEBUGLOG(("parse_header: Tag[%s]: [%s]\n",csTag,csList[iCount]));
			}

		}
	}

	iRet = process_header(hTxn);

	fclose(fin);	
	return iRet;
}

int	process_header(hash_t *hTxn)
{
	int	iRet = SUCCESS;
	int	iFile = 0;
	int	i = 0;
	//int	iTmp = 0;
	unsigned long   lFileId = 0l;
	char    csFileId[PD_TXN_SEQ_LEN+1]; 
	char    csTag[PD_TAG_LEN+1];
	char	*csTmp;
	char	*csVncFileId;
	double	dTmp=0.0;

	GetField_Int(hTxn,"file_count",&iFile);

	for(i=1;i<=iFile;i++){
		if(GetFileId(&lFileId)!= PD_OK){
DEBUGLOG(("process_header::GetFileId Failed\n"));
ERRLOG("pr_payout_generate::process_header::GetFileId Failed\n");
			iRet = FAILURE;
			break;
		}
		else {
DEBUGLOG(("process_header::GetFileId file_id = [%ld]\n", lFileId));
			sprintf(csFileId,"%ld",lFileId);
			sprintf(csTag,"vnc_file_id_%d",i);
			GetField_CString(hTxn,csTag,&csVncFileId);

DEBUGLOG(("process_header:: [%s] = [%s]\n", csTag,csVncFileId));
			sprintf(csTag,"file_id_%d",i);
			PutField_CString(hTxn,csTag,csFileId);
			PutField_CString(hTxn,"file_id",csFileId);

			sprintf(csTag,"vnc_%s_new",csVncFileId);
			PutField_CString(hTxn,csTag,csFileId);
DEBUGLOG(("process_header:: [%s] = [%s]\n", csTag,csFileId));
		}

		if(ConvertField(hTxn,i)!=PD_OK){
DEBUGLOG(("process_header::ConvertField Failed\n"));
ERRLOG("pr_payout_generate::process_header::ConvertField Failed\n");
			iRet = FAILURE;
			break;
		}

		sprintf(csTag,"psp_id_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			sprintf(csTag,"%s_psp_id",csFileId);
			PutField_CString(hTxn,csTag,csTmp);
		}

		sprintf(csTag,"filename_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			PutField_CString(hTxn,"filename",csTmp);
		}
		sprintf(csTag,"file_seq_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			if(is_numeric(csTmp))
				PutField_Int(hTxn,"seq_num",atoi(csTmp));
		}
		sprintf(csTag,"date_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			PutField_CString(hTxn,"file_date",csTmp);
		}
		sprintf(csTag,"txn_count_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			PutField_Int(hTxn,"txn_count",atoi(csTmp));
		}
		sprintf(csTag,"merchant_fee_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			if(sscanf(csTmp,"%lf",&dTmp)==1)
				PutField_Double(hTxn,"merchant_fee",dTmp);
		}
		sprintf(csTag,"merchant_fee_ccy_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			PutField_CString(hTxn,"merchant_fee_ccy",csTmp);
		}
		sprintf(csTag,"member_fee_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			if(sscanf(csTmp,"%lf",&dTmp)==1)
				PutField_Double(hTxn,"membe_fee",dTmp);
		}
		sprintf(csTag,"member_fee_ccy_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			PutField_CString(hTxn,"member_fee_ccy",csTmp);
		}
		sprintf(csTag,"status_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			PutField_Int(hTxn,"status",atoi(csTmp));
			sprintf(csTag,"%s_status",csFileId);
			PutField_Int(hTxn,csTag,atoi(csTmp));
		}

		if(AddGenerateHeader(hTxn)!=PD_OK){
			iRet = FAILURE;
			break;
		}

	}

	return iRet;
}


int GetFileId(unsigned long *lFileId)
{
        int iRet = PD_OK;
        *lFileId = 0l;

        /* EXEC SQL WHENEVER SQLERROR GOTO GetFileId_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                unsigned long   v_file_id;

                short           ind_file_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        /* EXEC SQL SELECT max(fh_file_id)
                INTO    :v_file_id:ind_file_id
                FROM    payout_generated_file_hd; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select max(fh_file_id) into :b0:b1  from payout_gene\
rated_file_hd ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )5;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_file_id;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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
        if (sqlca.sqlcode < 0) goto GetFileId_error;
}



        if(ind_file_id>=0){
DEBUGLOG(("GetFileId Found\n"));
                *lFileId = v_file_id+1;
        }
        else {
DEBUGLOG(("GetFileId Start by 1\n"));
                *lFileId = 1;
        }

        return iRet;

GetFileId_error:
DEBUGLOG(("GetFileId_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int ConvertField(hash_t *hTxn, const int iFile)
{
        int iRet = PD_OK;
	char    csTag[PD_TAG_LEN+1];
	char	*csTmp;
	double	dTmp;
	int	i = 0;
	int	iCcy = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO getpsp_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_vnc_psp[PD_VNC_PSP_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_vnc_psp;


                /* varchar         v_ph_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_ph_psp_id;


                short           ind_ph_psp_id= -1;
        /* EXEC SQL END DECLARE SECTION; */ 


	sprintf(csTag,"psp_%d",iFile);
	if(GetField_CString(hTxn,csTag,&csTmp)){
        	hv_vnc_psp.len = strlen(csTmp);
        	memcpy(hv_vnc_psp.arr,csTmp,hv_vnc_psp.len);
DEBUGLOG(("ConvertField vnc_psp = [%.*s]\n",hv_vnc_psp.len,hv_vnc_psp.arr));
	}

        /* EXEC SQL DECLARE c_cursor_getpsp CURSOR FOR
                select 
			ppm_preset_pid
                  from par_psp_client_map
                 where ppm_psp_type_cd = :hv_vnc_psp; */ 


        /* EXEC SQL OPEN c_cursor_getpsp; */ 

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
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_vnc_psp;
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
        if (sqlca.sqlcode < 0) goto getpsp_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getpsp
                INTO
                        :v_ph_psp_id:ind_ph_psp_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 1;
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
                sqlstm.sqhstv[0] = (unsigned char  *)&v_ph_psp_id;
                sqlstm.sqhstl[0] = (unsigned long )13;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_ph_psp_id;
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
                if (sqlca.sqlcode < 0) goto getpsp_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        iRet = SQL_NOT_FOUND;
                        break;
                }

// psp_id
                if (ind_ph_psp_id >= 0) {
                        v_ph_psp_id.arr[v_ph_psp_id.len] = '\0';
                        PutField_CString(hTxn,"psp_id",(const char*)v_ph_psp_id.arr);
			sprintf(csTag,"psp_id_%d",iFile);
                        PutField_CString(hTxn,csTag,(const char*)v_ph_psp_id.arr);
DEBUGLOG(("ConvertField ph_psp_id = [%s]\n",v_ph_psp_id.arr));
                }

		break; //**************** only one now
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getpsp; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )62;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getpsp_error;
}



	if(iRet!=PD_OK){
		return PD_ERR;
	}

	for(i=0;i<2;i++){
		if(i==0)
			sprintf(csTag,"merchant_fee_ccy_%d",iFile);
		else
			sprintf(csTag,"member_fee_ccy_%d",iFile);

		if(GetField_CString(hTxn,csTag,&csTmp)){
			if(is_numeric(csTmp)){
				iCcy = atoi(csTmp)-1;
				PutField_CString(hTxn,csTag,csCcySet[iCcy]);
			}
			else{
				RemoveField_CString(hTxn,csTag);
			}
		}
	}

	sprintf(csTag,"total_txn_amt_%d",iFile);
	if(GetField_CString(hTxn,csTag,&csTmp)){
		if(is_numeric(csTmp)){
			dTmp = myctod((const unsigned char *)csTmp,strlen(csTmp) - PD_DECIMAL_LEN,PD_DECIMAL_LEN);
			PutField_Double(hTxn,"txn_amt",dTmp);
			PutField_Double(hTxn,csTag,dTmp);
DEBUGLOG(("ConvertField txn_amt = [%lf]\n",dTmp));
		}
	}


DEBUGLOG(("ConvertField Normal Exit [%d]\n",iRet));
		return iRet;

getpsp_error:
DEBUGLOG(("getpsp_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getpsp; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )77;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int     AddGenerateHeader(const hash_t *hRls)
{
        char            *csTmp;
        int             iTmp;
        double          dTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

                /* varchar         hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

                /* varchar         hv_filename[PD_FILENAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_filename;

                /* varchar         hv_file_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_file_date;

                /* varchar         hv_merchant_fee_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_merchant_fee_ccy;

                /* varchar         hv_member_fee_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_member_fee_ccy;

                int             hv_seq_num;
                int             hv_txn_count;
                double          hv_txn_amt;
                double          hv_merchant_fee;
                double          hv_member_fee;
                int             hv_status;

                short           ind_file_id = -1;
                short           ind_psp_id = -1;
                short           ind_status = -1;
                short           ind_filename = -1;
                short           ind_seq_num= -1;
                short           ind_txn_count = -1;
                short           ind_txn_amt = -1;
                short           ind_merchant_fee= -1;
                short           ind_member_fee= -1;
                short           ind_merchant_fee_ccy= -1;
                short           ind_member_fee_ccy= -1;
                short           ind_file_date = -1;

                short           hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("AddGenerateHeader: Begin\n"));
/*file_id*/
        if(GetField_CString(hRls,"file_id",&csTmp)){
                hv_file_id.len = strlen(csTmp);
                memcpy(hv_file_id.arr, csTmp, hv_file_id.len);
                ind_file_id= 0;
DEBUGLOG(("Add:file_id= [%.*s]\n",hv_file_id.len,hv_file_id.arr));
        }

/*psp_id*/
        if(GetField_CString(hRls,"psp_id",&csTmp)){
                hv_psp_id.len = strlen(csTmp);
                memcpy(hv_psp_id.arr, csTmp, hv_psp_id.len);
                ind_psp_id = 0;
DEBUGLOG(("Add:psp_id = [%.*s]\n",hv_psp_id.len,hv_psp_id.arr));
        }

/*filename*/
        if(GetField_CString(hRls,"filename",&csTmp)){
                hv_filename.len = strlen(csTmp);
                memcpy(hv_filename.arr, csTmp, hv_filename.len);
                ind_filename= 0;
DEBUGLOG(("Add:filename = [%.*s]\n",hv_filename.len,hv_filename.arr));
        }

/*member_fee_ccy*/
        if(GetField_CString(hRls,"member_fee_ccy",&csTmp)){
                hv_member_fee_ccy.len = strlen(csTmp);
                memcpy(hv_member_fee_ccy.arr, csTmp, hv_member_fee_ccy.len);
                ind_member_fee_ccy= 0;
DEBUGLOG(("Add:member_fee_ccy = [%.*s]\n",hv_member_fee_ccy.len,hv_member_fee_ccy.arr));
        }

/*merchant_fee_ccy*/
        if(GetField_CString(hRls,"merchant_fee_ccy",&csTmp)){
                hv_merchant_fee_ccy.len = strlen(csTmp);
                memcpy(hv_merchant_fee_ccy.arr, csTmp, hv_merchant_fee_ccy.len);
                ind_merchant_fee_ccy= 0;
DEBUGLOG(("Add:merchant_fee_ccy = [%.*s]\n",hv_merchant_fee_ccy.len,hv_merchant_fee_ccy.arr));
        }

/*file_date*/
        if(GetField_CString(hRls,"file_date",&csTmp)){
                hv_file_date.len = PD_DATE_LEN;
                memcpy(hv_file_date.arr, csTmp, PD_DATE_LEN);
                ind_file_date = 0;
DEBUGLOG(("Add:file_date = [%.*s]\n",hv_file_date.len,hv_file_date.arr));
        }

/*seq_num*/
        if(GetField_Int(hRls,"seq_num",&iTmp)){
                hv_seq_num= iTmp;
                ind_seq_num= 0;
DEBUGLOG(("Add:seq_num = [%d]\n",hv_seq_num));
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

/*merchant_fee*/
        if (GetField_Double(hRls,"merchant_fee",&dTmp)) {
                hv_merchant_fee= dTmp;
                ind_merchant_fee= 0;
DEBUGLOG(("Add:merchant_fee = [%lf]\n",hv_merchant_fee));
        }

/*member_fee*/
        if (GetField_Double(hRls,"member_fee",&dTmp)) {
                hv_member_fee= dTmp;
                ind_member_fee= 0;
DEBUGLOG(("Add:member_fee = [%lf]\n",hv_member_fee));
        }

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_insert_for_parallel_run(
                                        :hv_file_id:ind_file_id,
                                        :hv_file_date:ind_file_date,
                                        :hv_psp_id:ind_psp_id,
                                        :hv_seq_num:ind_seq_num,
                                        :hv_filename:ind_filename,
                                        :hv_txn_count:ind_txn_count,
                                        :hv_txn_amt:ind_txn_amt,
                                        :hv_merchant_fee_ccy:ind_merchant_fee_ccy,
                                        :hv_member_fee_ccy:ind_member_fee_ccy,
                                        :hv_merchant_fee:ind_merchant_fee,
                                        :hv_member_fee:ind_member_fee,
                                        :hv_status:ind_status);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_insert_for_parallel_run\
 ( :hv_file_id:ind_file_id , :hv_file_date:ind_file_date , :hv_psp_id:ind_psp\
_id , :hv_seq_num:ind_seq_num , :hv_filename:ind_filename , :hv_txn_count:ind\
_txn_count , :hv_txn_amt:ind_txn_amt , :hv_merchant_fee_ccy:ind_merchant_fee_\
ccy , :hv_member_fee_ccy:ind_member_fee_ccy , :hv_merchant_fee:ind_merchant_f\
ee , :hv_member_fee:ind_member_fee , :hv_status:ind_status ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )92;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_file_date;
        sqlstm.sqhstl[2] = (unsigned long )10;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_file_date;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_psp_id;
        sqlstm.sqhstl[3] = (unsigned long )12;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_psp_id;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_seq_num;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_seq_num;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_filename;
        sqlstm.sqhstl[5] = (unsigned long )52;
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
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_merchant_fee_ccy;
        sqlstm.sqhstl[8] = (unsigned long )5;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_merchant_fee_ccy;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_member_fee_ccy;
        sqlstm.sqhstl[9] = (unsigned long )5;
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&ind_member_fee_ccy;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&hv_merchant_fee;
        sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)&ind_merchant_fee;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&hv_member_fee;
        sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         short *)&ind_member_fee;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         short *)&ind_status;
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
        if (sqlca.sqlcode < 0) goto add_error;
}



DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("Add:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("AddGenerateHeader_Add: SP_OTHER_ERR \n");
DEBUGLOG(("Add: SP_OTHER_ERR \n"));
		return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("AddGenerateHeader_Add: SP_ERR \n");
DEBUGLOG(("Add: SP_ERR \n"));
		return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("AddGenerateHeader_Add: SP_INTERNAL_ERR \n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}

int     parse_detail(FILE *fin,hash_t *hTxn)
{
        int     iRet = SUCCESS;
        char    csList[IMPORT_MAX_FILE][IMPORT_FIELD_LEN];
        char    cs_input_buf[PD_MAX_BUFFER +1];;
        char    csTag[PD_TAG_LEN+1];
        char* p;
        int     iCount = 0;
        int     i= 0;
        int     iRec= 0;

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
				if(iCount==IDX_DETAIL_FILE_ID)
					sprintf(csTag,"dt_file_id_%d",iRec);
				else if(iCount==IDX_DETAIL_REF_ID)
					sprintf(csTag,"upload_ref_id_%d",iRec);
				else if(iCount==IDX_DETAIL_TXN_SEQ)
					sprintf(csTag,"vnc_ref_num_%d",iRec);
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
				else if(iCount==IDX_DETAIL_PAYOUT_AMT)
					sprintf(csTag,"payout_amount_%d",iRec);
				else if(iCount==IDX_DETAIL_REQ_CCY_ID)
					sprintf(csTag,"request_currency_%d",iRec);
				else if(iCount==IDX_DETAIL_DST_CCY_ID)
					sprintf(csTag,"payout_currency_%d",iRec);
				else
					sprintf(csTag,"not_care");

				PutField_CString(hTxn,csTag,csList[iCount]);
DEBUGLOG(("parse_detail: Tag[%s]: [%s]\n",csTag,csList[iCount]));
			}

		}

	}


	iRet = process_detail(hTxn);

	return iRet;
}


int	process_detail(hash_t *hTxn)
{
	int	iRet = SUCCESS;
	//int	iFile = 0;
	int	i = 0;
	int	iTmp = 0;
	char    *csFileId; 
	char    *csVncFileId; 
	char    csTag[PD_TAG_LEN+1];
	char	*csTmp;
	double	dTmp=0.0;
	double	dPrecalFee=0.0;
	int	iCnt = 0;
	int	iStatus= 0;
	char    *csTxnSeq = strdup("");

	GetField_Int(hTxn,"total_detail_record",&iCnt);

DEBUGLOG(("process_detail Begin [%d]\n",iCnt));

	for(i=1;i<=iCnt;i++){	
		sprintf(csTag,"dt_file_id_%d",i);
		if(GetField_CString(hTxn,csTag,&csVncFileId)){
DEBUGLOG(("process_detail::dt_file_id = [%s]\n", csVncFileId));
			sprintf(csTag,"vnc_%s_new",csVncFileId);
			if(GetField_CString(hTxn,csTag,&csFileId)){
				PutField_CString(hTxn,"file_id",csFileId);
DEBUGLOG(("process_detail::file_id = [%s]\n", csFileId));
			}
		}

		sprintf(csTag,"%s_psp_id",csFileId);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			PutField_CString(hTxn,"psp_id",csTmp);
			PutField_CString(hTxn,"org_psp_id",csTmp);
		}

		csTxnSeq  = strdup(GetNextPayoutTxnSeq());
DEBUGLOG(("GetNextPayoutTxnSeq: [%d]=[%s]\n",i,csTxnSeq));
		PutField_CString(hTxn,"gen_txn_id",csTxnSeq);

		sprintf(csTag,"seq_num_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			iTmp = atoi(csTmp);
			PutField_Int(hTxn,"seq_num",iTmp);
		}

		sprintf(csTag,"vnc_ref_num_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			PutField_CString(hTxn,"vnc_ref_num",csTmp);
			if(FindBatchId(hTxn)!=PD_OK){
DEBUGLOG(("process_detail: Found batch_id failed\n"));
			}
		}

		sprintf(csTag,"merchant_ref_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			PutField_CString(hTxn,"merchant_ref",csTmp);
		}
		sprintf(csTag,"country_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			PutField_CString(hTxn,"country",csTmp);
			sprintf(csTag,"%s_country",csFileId);
			PutField_CString(hTxn,csTag,csTmp);
		}
		sprintf(csTag,"identity_id_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			PutField_CString(hTxn,"identity_id",csTmp);
		}
		sprintf(csTag,"account_num_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			PutField_CString(hTxn,"account_num",csTmp);
		}
		sprintf(csTag,"account_name_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			PutField_CString(hTxn,"account_name",csTmp);
		}
		sprintf(csTag,"bank_name_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			PutField_CString(hTxn,"bank_name",csTmp);
		}
		sprintf(csTag,"bank_code_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			PutField_CString(hTxn,"bank_code",csTmp);
		}
		sprintf(csTag,"branch_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			PutField_CString(hTxn,"branch",csTmp);
		}
		sprintf(csTag,"phone_num_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			PutField_CString(hTxn,"phone_num",csTmp);
		}
		sprintf(csTag,"province_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			PutField_CString(hTxn,"province",csTmp);
		}
		sprintf(csTag,"city_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			PutField_CString(hTxn,"city",csTmp);
		}
		sprintf(csTag,"payout_currency_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			if(is_numeric(csTmp)){
				PutField_CString(hTxn,"payout_currency",csCcySet[atoi(csTmp)-1]);
				sprintf(csTag,"%s_payout_currency",csFileId);
				PutField_CString(hTxn,csTag,csCcySet[atoi(csTmp)-1]);
			}
		}
		sprintf(csTag,"payout_amount_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			if(sscanf(csTmp,"%lf",&dTmp)==1){
				PutField_Double(hTxn,"payout_amount",dTmp);
				PutField_Double(hTxn,"org_dst_net_amt",dTmp);
			}
		}
		sprintf(csTag,"request_currency_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			if(is_numeric(csTmp))
				PutField_CString(hTxn,"request_currency",csCcySet[atoi(csTmp)-1]);
		}
		sprintf(csTag,"request_amount_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			if(sscanf(csTmp,"%lf",&dTmp)==1){
				PutField_Double(hTxn,"request_amount",dTmp);
			}
		}
		sprintf(csTag,"%s_status",csFileId);
		if(GetField_Int(hTxn,csTag,&iTmp)){
			if(iTmp==PD_PAYOUTFILE_GENERATED ||
			   iTmp==PD_PAYOUTFILE_PARTIAL_GENERATED)
				iStatus = PAYOUT_MASTER_TRANSACTION_GENERATED;
			else if(iTmp==PD_PAYOUTFILE_REVERSED)
				iStatus = PAYOUT_MASTER_TRANSACTION_REVERSED;

			PutField_Int(hTxn,"status",iStatus);
		}

		if(AddGenerateDetail(hTxn)!=PD_OK){
			iRet = FAILURE;
			break;
		}

		PutField_Char(hTxn,"txn_type",PD_TYPE_PAYOUT);
		if(CalPspCosts(hTxn,hTxn)!=PD_OK){
			iRet = FAILURE;
			break;
		}
		else{
			if(GetField_Double(hTxn,"precal_fee",&dTmp)){
				sprintf(csTag,"precal_fee_%d",i);
				PutField_Double(hTxn,csTag,dTmp);

				dPrecalFee=0.0;
				sprintf(csTag,"%s_total_precal_fee",csFileId);
				GetField_Double(hTxn,csTag,&dPrecalFee);
				dPrecalFee += dTmp;
				PutField_Double(hTxn,csTag,dPrecalFee);
			}
		}

	}
/*
	GetField_Int(hTxn,"file_count",&iFile);
DEBUGLOG(("process_header: file_count = [%d]\n",iFile));
	for(i=1; i<=iFile; i++){
		sprintf(csTag,"batch_id_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			PutField_CString(hTxn,"batch_id",csTmp);
			sprintf(csTag,"%s_vnc_ref_num",csTmp);
			if(GetField_CString(hTxn,csTag,&csTmp)){
				PutField_CString(hTxn,"vnc_ref_num",csTmp);
DEBUGLOG(("process_header: UpdateGenerateHeader = [%s]\n",csTmp));
				if(UpdateGenerateHeader(hTxn)!=PD_OK){
					iRet = FAILURE;
				}
			}
		}
	}
*/
	FREE_ME(csTxnSeq);
	return iRet;
}





int FindBatchId(hash_t *hTxn)
{
        int iRet = PD_OK;
	int iTmp;
	char* csVncRefNum;

        /* EXEC SQL WHENEVER SQLERROR GOTO getbatch_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_vnc_ref_num[PD_MERCH_ACCOUNT_NMB_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_vnc_ref_num;

		int		hv_seq_num;

                /* varchar         v_batch_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_batch_id;

                /* varchar         v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;


                short           ind_batch_id = -1;
                short           ind_txn_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	if(GetField_CString(hTxn,"vnc_ref_num",&csVncRefNum)){
        	hv_vnc_ref_num.len = strlen(csVncRefNum);
        	memcpy(hv_vnc_ref_num.arr,csVncRefNum,hv_vnc_ref_num.len);
DEBUGLOG(("FindBatchId vnc_ref_num = [%.*s]\n",hv_vnc_ref_num.len,hv_vnc_ref_num.arr));
	}

	if(GetField_Int(hTxn,"seq_num",&iTmp)){
		hv_seq_num = iTmp;
DEBUGLOG(("FindBatchId seq_num = [%d]\n",hv_seq_num));
	}

        /* EXEC SQL DECLARE c_cursor_getbatch CURSOR FOR
                select
                        ud_batch_id,
			ud_txn_id
                from	merchant_upload_file_detail
                where	ud_vnc_ref_num = :hv_vnc_ref_num
		and	ud_seq_num = :hv_seq_num; */ 


        /* EXEC SQL OPEN c_cursor_getbatch; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0004;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )159;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_vnc_ref_num;
        sqlstm.sqhstl[0] = (unsigned long )52;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_seq_num;
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
        if (sqlca.sqlcode < 0) goto getbatch_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getbatch
                INTO
                        :v_batch_id:ind_batch_id,
                        :v_txn_id:ind_txn_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 13;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )182;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
                sqlstm.sqhstl[0] = (unsigned long )19;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_batch_id;
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
                if (sqlca.sqlcode < 0) goto getbatch_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        iRet = SQL_NOT_FOUND;
                        break;
                }

// batch_id
                if (ind_batch_id >= 0) {
                        v_batch_id.arr[v_batch_id.len] = '\0';
                        PutField_CString(hTxn,"batch_id",(const char*)v_batch_id.arr);
DEBUGLOG(("FindBatchId batch_id = [%s]\n",v_batch_id.arr));
                }

//txn_id 
                if (ind_txn_id >= 0) {
                        v_txn_id.arr[v_txn_id.len] = '\0';
                        PutField_CString(hTxn,"txn_id",(const char*)v_txn_id.arr);
DEBUGLOG(("FindBatchId txn_id = [%s]\n",v_txn_id.arr));
                }

                break; //**************** only one now
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getbatch; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )205;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getbatch_error;
}



DEBUGLOG(("FindBatchId Normal Exit\n"));
        if(iRet==0) return  PD_OK;
        else    return iRet;

getbatch_error:
DEBUGLOG(("getbatch_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getbatch; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )220;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}



int     AddGenerateDetail(const hash_t *hRls)
{
        char            *csTmp;
        int             iTmp;
        double          dTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;

                /* varchar         hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

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
                int             hv_status;
                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

                /* varchar         hv_gen_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_gen_txn_id;

                /* varchar         hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;


                short           ind_batch_id= -1;
                short           ind_file_id= -1;
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
                short           ind_status = -1;
                short           ind_txn_id= -1;
                short           ind_gen_txn_id= -1;
                short           ind_add_user= -1;

                short           hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("AddGenerateDetail: Begin\n"));

/*batch_id*/
        if(GetField_CString(hRls,"batch_id",&csTmp)){
                hv_batch_id.len = strlen(csTmp);
                memcpy(hv_batch_id.arr, csTmp, hv_batch_id.len);
                ind_batch_id= 0;
DEBUGLOG(("Add:batch_id= [%.*s]\n",hv_batch_id.len,hv_batch_id.arr));
        }

/*file_id*/
        if(GetField_CString(hRls,"file_id",&csTmp)){
                hv_file_id.len = strlen(csTmp);
                memcpy(hv_file_id.arr, csTmp, hv_file_id.len);
                ind_file_id= 0;
DEBUGLOG(("Add:file_id= [%.*s]\n",hv_file_id.len,hv_file_id.arr));
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

/*status*/
        if(GetField_Int(hRls,"status",&iTmp)){
                hv_status = iTmp;
                ind_status = 0;
DEBUGLOG(("Add:status = [%i]\n",hv_status));
        }

/*txn_id*/
        if(GetField_CString(hRls,"txn_id",&csTmp)){
                hv_txn_id.len = strlen(csTmp);
                memcpy(hv_txn_id.arr, csTmp, hv_txn_id.len);
                ind_txn_id= 0;
DEBUGLOG(("Add:txn_id= [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
        }

/*gen_txn_id*/
        if(GetField_CString(hRls,"gen_txn_id",&csTmp)){
                hv_gen_txn_id.len = strlen(csTmp);
                memcpy(hv_gen_txn_id.arr, csTmp, hv_gen_txn_id.len);
                ind_gen_txn_id= 0;
DEBUGLOG(("Add:gen_txn_id= [%.*s]\n",hv_gen_txn_id.len,hv_gen_txn_id.arr));
        }

	hv_add_user.len = strlen(PD_UPDATE_USER);
	memcpy(hv_add_user.arr, PD_UPDATE_USER, hv_add_user.len);
	ind_add_user= 0;

        FREE_ME(csTmp);

        /* EXEC SQL EXECUTE
                BEGIN
			:hv_return_value := sp_payout_gen_dt_insert(
                                        :hv_file_id:ind_file_id,
                                        :hv_batch_id:ind_batch_id,
                                        :hv_seq_num:ind_seq_num,
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
                                        :hv_payout_amount:ind_payout_amount,
                                        :hv_request_amount:ind_request_amount,
                                        :hv_payout_currency:ind_payout_currency,
                                        :hv_request_currency:ind_request_currency,
                                        :hv_txn_id:ind_txn_id,
                                        :hv_gen_txn_id:ind_gen_txn_id,
                                        :hv_status:ind_status,
                                        :hv_add_user:ind_add_user);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 23;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_payout_gen_dt_insert ( \
:hv_file_id:ind_file_id , :hv_batch_id:ind_batch_id , :hv_seq_num:ind_seq_num\
 , :hv_merchant_ref:ind_merchant_ref , :hv_country:ind_country , :hv_identity\
_id:ind_identity_id , :hv_account_num:ind_account_num , :hv_account_name:ind_\
account_name , :hv_bank_name:ind_bank_name , :hv_bank_code:ind_bank_code , :h\
v_branch:ind_branch , :hv_phone_num:ind_phone_num , :hv_province:ind_province\
 , :hv_city:ind_city , :hv_payout_amount:ind_payout_amount , :hv_request_amou\
nt:ind_request_amount , :hv_payout_currency:ind_payout_currency , :hv_request\
_currency:ind_request_currency , :hv_txn_id:ind_txn_id , :hv_gen_txn_id:ind_g\
en_txn_id , :hv_status:ind_status , :hv_add_user:ind_add_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )235;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[2] = (unsigned long )18;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_batch_id;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_seq_num;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_seq_num;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_merchant_ref;
        sqlstm.sqhstl[4] = (unsigned long )52;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_merchant_ref;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_country;
        sqlstm.sqhstl[5] = (unsigned long )4;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_country;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_identity_id;
        sqlstm.sqhstl[6] = (unsigned long )27;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_identity_id;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_account_num;
        sqlstm.sqhstl[7] = (unsigned long )27;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_account_num;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_account_name;
        sqlstm.sqhstl[8] = (unsigned long )27;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_account_name;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_bank_name;
        sqlstm.sqhstl[9] = (unsigned long )52;
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&ind_bank_name;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&hv_bank_code;
        sqlstm.sqhstl[10] = (unsigned long )12;
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)&ind_bank_code;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&hv_branch;
        sqlstm.sqhstl[11] = (unsigned long )52;
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         short *)&ind_branch;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (unsigned char  *)&hv_phone_num;
        sqlstm.sqhstl[12] = (unsigned long )27;
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         short *)&ind_phone_num;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned long )0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
        sqlstm.sqhstv[13] = (unsigned char  *)&hv_province;
        sqlstm.sqhstl[13] = (unsigned long )22;
        sqlstm.sqhsts[13] = (         int  )0;
        sqlstm.sqindv[13] = (         short *)&ind_province;
        sqlstm.sqinds[13] = (         int  )0;
        sqlstm.sqharm[13] = (unsigned long )0;
        sqlstm.sqadto[13] = (unsigned short )0;
        sqlstm.sqtdso[13] = (unsigned short )0;
        sqlstm.sqhstv[14] = (unsigned char  *)&hv_city;
        sqlstm.sqhstl[14] = (unsigned long )22;
        sqlstm.sqhsts[14] = (         int  )0;
        sqlstm.sqindv[14] = (         short *)&ind_city;
        sqlstm.sqinds[14] = (         int  )0;
        sqlstm.sqharm[14] = (unsigned long )0;
        sqlstm.sqadto[14] = (unsigned short )0;
        sqlstm.sqtdso[14] = (unsigned short )0;
        sqlstm.sqhstv[15] = (unsigned char  *)&hv_payout_amount;
        sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[15] = (         int  )0;
        sqlstm.sqindv[15] = (         short *)&ind_payout_amount;
        sqlstm.sqinds[15] = (         int  )0;
        sqlstm.sqharm[15] = (unsigned long )0;
        sqlstm.sqadto[15] = (unsigned short )0;
        sqlstm.sqtdso[15] = (unsigned short )0;
        sqlstm.sqhstv[16] = (unsigned char  *)&hv_request_amount;
        sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[16] = (         int  )0;
        sqlstm.sqindv[16] = (         short *)&ind_request_amount;
        sqlstm.sqinds[16] = (         int  )0;
        sqlstm.sqharm[16] = (unsigned long )0;
        sqlstm.sqadto[16] = (unsigned short )0;
        sqlstm.sqtdso[16] = (unsigned short )0;
        sqlstm.sqhstv[17] = (unsigned char  *)&hv_payout_currency;
        sqlstm.sqhstl[17] = (unsigned long )5;
        sqlstm.sqhsts[17] = (         int  )0;
        sqlstm.sqindv[17] = (         short *)&ind_payout_currency;
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
        sqlstm.sqhstv[19] = (unsigned char  *)&hv_txn_id;
        sqlstm.sqhstl[19] = (unsigned long )18;
        sqlstm.sqhsts[19] = (         int  )0;
        sqlstm.sqindv[19] = (         short *)&ind_txn_id;
        sqlstm.sqinds[19] = (         int  )0;
        sqlstm.sqharm[19] = (unsigned long )0;
        sqlstm.sqadto[19] = (unsigned short )0;
        sqlstm.sqtdso[19] = (unsigned short )0;
        sqlstm.sqhstv[20] = (unsigned char  *)&hv_gen_txn_id;
        sqlstm.sqhstl[20] = (unsigned long )18;
        sqlstm.sqhsts[20] = (         int  )0;
        sqlstm.sqindv[20] = (         short *)&ind_gen_txn_id;
        sqlstm.sqinds[20] = (         int  )0;
        sqlstm.sqharm[20] = (unsigned long )0;
        sqlstm.sqadto[20] = (unsigned short )0;
        sqlstm.sqtdso[20] = (unsigned short )0;
        sqlstm.sqhstv[21] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[21] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[21] = (         int  )0;
        sqlstm.sqindv[21] = (         short *)&ind_status;
        sqlstm.sqinds[21] = (         int  )0;
        sqlstm.sqharm[21] = (unsigned long )0;
        sqlstm.sqadto[21] = (unsigned short )0;
        sqlstm.sqtdso[21] = (unsigned short )0;
        sqlstm.sqhstv[22] = (unsigned char  *)&hv_add_user;
        sqlstm.sqhstl[22] = (unsigned long )22;
        sqlstm.sqhsts[22] = (         int  )0;
        sqlstm.sqindv[22] = (         short *)&ind_add_user;
        sqlstm.sqinds[22] = (         int  )0;
        sqlstm.sqharm[22] = (unsigned long )0;
        sqlstm.sqadto[22] = (unsigned short )0;
        sqlstm.sqtdso[22] = (unsigned short )0;
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
ERRLOG("AddGenerateDetail_Add: SP_OTHER_ERR\n");
DEBUGLOG(("Add: SP_OTHER_ERR\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("AddGenerateDetail_Add: SP_ERR\n");
DEBUGLOG(("Add: SP_ERR\n"));
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("AddGenerateDetail_Add: SP_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}

int handle_psp_balance(hash_t * hTxn)
{
	int	iRet = SUCCESS;
	int	i= 0;
	int	iFile = 0;
	char    csTag[PD_TAG_LEN+1];
	char	*csFileId=NULL;
	char	*csPspId=NULL;
	char	*csCcy=NULL;
	char	*csCountry=NULL;
	double	dTmp= 0.0;
	double	dPspAmt= 0.0;
	double	dFee= 0.0;

	
	GetField_Int(hTxn,"file_count",&iFile);

	for(i=1;i<=iFile;i++){
		sprintf(csTag,"psp_id_%d",iFile);
		if(GetField_CString(hTxn,csTag,&csPspId)){
DEBUGLOG(("handle_psp_balance: psp_id [%s]\n",csPspId));
		}
		sprintf(csTag,"file_id_%d",iFile);
		if(GetField_CString(hTxn,csTag,&csFileId)){
			sprintf(csTag,"%s_payout_currency",csFileId);
			if(GetField_CString(hTxn,csTag,&csCcy)){
DEBUGLOG(("handle_psp_balance: ccy [%s]\n",csCcy));
			}
			sprintf(csTag,"%s_country",csFileId);
			if(GetField_CString(hTxn,csTag,&csCountry)){
DEBUGLOG(("handle_psp_balance: country [%s]\n",csCountry));
			}
			sprintf(csTag,"%s_total_precal_fee",csFileId);
			if(GetField_Double(hTxn,csTag,&dFee)){
DEBUGLOG(("handle_psp_balance: psp_fee [%lf]\n",dFee));
			}
		}
		sprintf(csTag,"total_txn_amt_%d",iFile);
		if(GetField_Double(hTxn,csTag,&dPspAmt)){
DEBUGLOG(("handle_psp_balance: psp_amt [%lf]\n",dPspAmt));
		}

		if(DebitBalance(csPspId,csCountry,csCcy,PD_PSP_BAL,dPspAmt-dFee,PD_UPDATE_USER) != PD_OK){
DEBUGLOG(("handle_psp_balance: DebitBalance Failed\n"));
			iRet = FAILURE;
			break;
		}

		hash_t *hVal;
		hVal = (hash_t*) malloc (sizeof(hash_t));
                hash_init(hVal,0);

                if(GetBalance(csPspId,csCountry,csCcy,hVal)!=PD_ERR){
			sprintf(csTag,"psp_balance_%d",iFile);
                        if(GetField_Double(hVal,"balance",&dTmp)){
                                PutField_Double(hTxn,csTag,dTmp);
DEBUGLOG(("handle_psp_balance:psp_balance = [%f]\n",dTmp));
                        }
			sprintf(csTag,"psp_total_float_%d",iFile);
                        if(GetField_Double(hVal,"total_float",&dTmp)){
                                PutField_Double(hTxn,csTag,dTmp);
DEBUGLOG(("handle_psp_balance:psp_total_float = [%f]\n",dTmp));
                        }
			sprintf(csTag,"psp_total_hold_%d",iFile);
                        if(GetField_Double(hVal,"total_hold",&dTmp)){
                                PutField_Double(hTxn,csTag,dTmp);
DEBUGLOG(("handle_psp_balance:psp_total_hold = [%f]\n",dTmp));
                        }
                }
                FREE_ME(hVal);
	}
	return iRet;
}




int generate_new_txn(hash_t * hContext)
{
	int	iRet = SUCCESS;
        char    *csTmp;
        char    *csFileId;
        double  dTmp;
        //char    cPartyType;
        hash_t  *hTxn;
        hTxn= (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTxn,0);
	int	i = 0;
	int	iFile = 0;
	char    *csTxnSeq; 
	char    csTag[PD_TAG_LEN+1];
	time_t  ct;
        struct  tm *sct;

        char    sys_date[PD_DATE_LEN + 1];
        char    sys_time[PD_TIME_LEN + 1];

	
	GetField_Int(hContext,"file_count",&iFile);
	for(i=1;i<=iFile;i++){

DEBUGLOG(("generate_new_txn for file [%d]\n",iFile));

		csTxnSeq  = strdup(GetNextMgtTxnSeq());
DEBUGLOG(("GetNextMgtTxnSeq: [%d]=[%s]\n",i,csTxnSeq));
                PutField_CString(hTxn,"txn_seq",csTxnSeq);
		//sprintf(csTag,"txn_seq_%d",iFile);
		//PutField_CString(hContext,csTag,csTxnSeq);

		PutField_CString(hTxn,"channel_code","MGT");
		PutField_CString(hTxn,"txn_code","POG");
		PutField_CString(hTxn,"desc","Payout File Generated");

		sprintf(csTag,"date_%d",iFile);
		if (GetField_CString(hContext,csTag,&csTmp)) {
DEBUGLOG(("generate_new_txn:: host_posting_date = [%s]\n",csTmp));
			PutField_CString(hTxn,"host_posting_date",csTmp);
			PutField_CString(hTxn,"transmission_datetime",csTmp);
			PutField_CString(hTxn,"tm_date",csTmp);
			PutField_CString(hTxn,"txn_date",csTmp);
			PutField_CString(hTxn,"approval_date",csTmp);
		}

		ct = time((time_t *) 0);
		sct = localtime(&ct);

		memset(sys_date, 0, sizeof(sys_date));
		memset(sys_time, 0, sizeof(sys_time));

		sprintf(sys_date, "%04d%02d%02d",sct->tm_year + 1900, sct->tm_mon + 1, sct->tm_mday);
		sprintf(sys_time, "%02d%02d%02d",sct->tm_hour, sct->tm_min, sct->tm_sec);

		PutField_CString(hTxn, "local_tm_date", sys_date);
		PutField_CString(hTxn, "local_tm_time", sys_time);
DEBUGLOG(("generate_new_txn:: local_tm_date = [%s]\n",sys_date));
DEBUGLOG(("generate_new_txn:: local_tm_time = [%s]\n",sys_time));

		PutField_CString(hTxn,"add_user",PD_UPDATE_USER);
		PutField_CString(hTxn,"process_type","0000");
		PutField_CString(hTxn,"process_code","000000");

		sprintf(csTag,"file_id_%d",iFile);
                if(GetField_CString(hContext,csTag,&csFileId)){
			PutField_CString(hTxn,"file_id",csFileId);

			sprintf(csTag,"%s_payout_currency",csFileId);
			if(GetField_CString(hContext,csTag,&csTmp)){
DEBUGLOG(("generate_new_txn:: txn_ccy = [%s]\n",csTmp));
				PutField_CString(hTxn,"txn_ccy",csTmp);
				PutField_CString(hTxn,"ccy",csTmp);
			}
			sprintf(csTag,"%s_country",csFileId);
			if(GetField_CString(hContext,csTag,&csTmp)){
DEBUGLOG(("generate_new_txn:: txn_country = [%s]\n",csTmp));
				PutField_CString(hTxn,"txn_country",csTmp);
			}
			sprintf(csTag,"%s_total_precal_fee",csFileId);
			if(GetField_Double(hContext,csTag,&dTmp)){
				PutField_Double(hTxn,"service_fee",dTmp);
DEBUGLOG(("generate_new_txn:: service_fee = [%lf]\n",dTmp));
			}
                }
                sprintf(csTag,"total_txn_amt_%d",iFile);
                if(GetField_Double(hContext,csTag,&dTmp)){
			PutField_Double(hTxn,"txn_amt",dTmp);
			PutField_Double(hTxn,"amount",dTmp);
DEBUGLOG(("generate_new_txn:: txn_amt = [%lf]\n",dTmp));
                }

		sprintf(csTag,"psp_id_%d",iFile);
		if(GetField_CString(hContext,csTag,&csTmp)){
DEBUGLOG(("generate_new_txn:: psp_id = [%s]\n",csTmp));
			PutField_CString(hTxn,"psp_id",csTmp);
		}

		sprintf(csTag,"psp_balance_%d",iFile);
		if (GetField_Double(hContext,csTag,&dTmp)) {
			PutField_Double(hTxn,"bal",dTmp);
DEBUGLOG(("generate_new_txn:: psp_balance = [%f]\n",dTmp));
		}
		sprintf(csTag,"psp_total_float_%d",iFile);
		if (GetField_Double(hContext,csTag,&dTmp)) {
			PutField_Double(hTxn,"total_float",dTmp);
DEBUGLOG(("generate_new_txn:: psp_total_float = [%f]\n",dTmp));
		}
		sprintf(csTag,"psp_total_hold_%d",iFile);
		if (GetField_Double(hContext,csTag,&dTmp)) {
			PutField_Double(hTxn,"total_hold",dTmp);
DEBUGLOG(("generate_new_txn:: psp_total_hold = [%f]\n",dTmp));
		}

		PutField_Char(hTxn,"status",PD_COMPLETE);
		PutField_CString(hTxn,"sub_status",PD_APPROVED_AND_GENERATED);
		PutField_Char(hTxn,"ar_ind",PD_ACCEPT);
		PutField_Int(hTxn,"internal_code",PD_OK);
		PutField_CString(hTxn,"response_code","0");

		DBObjPtr = CreateObj(DBPtr,"DBTransaction","Add");
		if((unsigned long)((*DBObjPtr)(hTxn)) == PD_OK){
DEBUGLOG(("generate_new_txn::Call DBTransaction:Update\n"));
			DBObjPtr = CreateObj(DBPtr,"DBTransaction","Update");
			if((unsigned long) ((*DBObjPtr)(hTxn))!=PD_OK){
				iRet = FAILURE;
DEBUGLOG(("generate_new_txn::DBTransaction:Update Failed\n"));
			}

DEBUGLOG(("generate_new_txn::Call DBTransaction:AddDetail\n"));
			DBObjPtr = CreateObj(DBPtr,"DBTransaction","AddDetail");
			if((unsigned long) ((*DBObjPtr)(hTxn))!=PD_OK){
				iRet = FAILURE;
DEBUGLOG(("generate_new_txn::DBTransaction:AddDetail Failed\n"));
			}

DEBUGLOG(("generate_new_txn::Call DBTxnPspDetail:Add\n"));
			DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Add");
			if((unsigned long) ((*DBObjPtr)(hTxn))!=PD_OK){
				iRet = FAILURE;
DEBUGLOG(("generate_new_txn::DBTxnPspDetail:Add Failed\n"));
			}
			else{
DEBUGLOG(("generate_new_txn::Call DBTxnPspDetail:Update\n"));
				DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Update");
				if((unsigned long) ((*DBObjPtr)(hTxn))!=PD_OK){
					iRet = FAILURE;
DEBUGLOG(("generate_new_txn::DBTxnPspDetail:Update Failed\n"));
				}
			}
		}

		if(iRet == SUCCESS){
			PutField_CString(hTxn,"txn_element_type",PD_ELEMENT_TXN_AMT);
			PutField_Char(hTxn,"party_type",PD_TYPE_PSP);
			PutField_CString(hTxn,"amount_type",PD_DR);
			if(AddElements(hTxn)!=PD_OK){
DEBUGLOG(("generate_new_txn::AddElementsFailed\n"));
				iRet = FAILURE;
			}

			sprintf(csTag,"%s_total_precal_fee",csFileId);
			if(GetField_Double(hContext,csTag,&dTmp)){
				if(dTmp>0.0){
DEBUGLOG(("generate_new_txn::AddElements(Fee) [%lf]\n",dTmp));
					PutField_CString(hTxn,"txn_element_type",PD_ELEMENT_TXN_FEE);
					PutField_Double(hTxn,"amount",dTmp);
					PutField_CString(hTxn,"amount_type",PD_CR);
					if(AddElements(hTxn)!=PD_OK){
DEBUGLOG(("generate_new_txn::AddElements(Fee) Failed\n"));
						iRet = FAILURE;
					}
				}
			}
		}

		if(iRet == SUCCESS){
			if(UpdateGenerateHeader(hTxn)!=PD_OK){
DEBUGLOG(("generate_new_txn::UpdateGenerateHeader Failed\n"));
				iRet = FAILURE;
			}
		}
	
		FREE_ME(csTxnSeq);
	}

	FREE_ME(hTxn);
	return iRet;
}


int UpdateGenerateHeader(const hash_t *hRec)
{
	char*   csBuf;
        char*   csFileId;
        //int     iTmp;
        //double  dTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateGenerateHeader: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update payout_generated_file_hd set fh_update_timestamp = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        if(GetField_CString(hRec,"file_id",&csFileId)){
DEBUGLOG(("Update:file_id = [%s]\n",csFileId));
        }
        else{
                FREE_ME(csBuf);
DEBUGLOG(("Update file_id not found\n"));
                return INT_ERR;
        }

	if(GetField_CString(hRec,"txn_seq",&csBuf)){
DEBUGLOG(("Update: txn_seq = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",fh_txn_id = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


        strcat((char*)hv_dynstmt.arr, " WHERE fh_file_id= ");
        strcat((char*)hv_dynstmt.arr, csFileId);
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));


        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 23;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )342;
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
        sqlstm.arrsiz = 23;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )361;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_error;
}



        FREE_ME(csBuf);

DEBUGLOG(("Update Normal Exit\n"));
        return PD_OK;

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("PayoutGeneratedFileHD_Update: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_INTERNAL_ERR;
}


int parse_arg(int argc,char **argv)
{
	char    c;
	strcpy(cs_dtfile,"");
	strcpy(cs_hdfile,"");

	while ((c = getopt(argc,argv,"h:t:d:")) != EOF) {
		switch (c) {
			case 'h':
				strcpy(cs_hdfile, optarg);
				break;
			case 't':
				strcpy(cs_dtfile, optarg);
				break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(cs_hdfile,"") || !strcmp(cs_dtfile,""))
		return FAILURE;

        return SUCCESS;
}

