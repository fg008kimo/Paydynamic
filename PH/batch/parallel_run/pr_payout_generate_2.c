
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
           char  filnam[24];
};
static struct sqlcxp sqlfpn =
{
    23,
    "pr_payout_generate_2.pc"
};


static unsigned int sqlctx = 688476987;


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
"select cp_preset_ph_pid ,cp_client_id  from par_client_psp_map where cp_psp\
_type_code=:b0           ";

 static char *sq0004 = 
"select ud_batch_id ,ud_txn_id  from merchant_upload_file_detail where (ud_v\
nc_ref_num=:b0 and ud_seq_num=:b1)           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,66,0,4,416,0,0,1,0,0,1,0,2,68,0,0,
24,0,0,2,100,0,9,474,0,0,1,1,0,1,0,1,9,0,0,
43,0,0,2,0,0,13,476,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
66,0,0,2,0,0,15,508,0,0,0,0,0,1,0,
81,0,0,2,0,0,15,542,0,0,0,0,0,1,0,
96,0,0,3,294,0,6,658,0,0,10,10,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,
9,0,0,1,3,0,0,1,4,0,0,1,9,0,0,1,3,0,0,
151,0,0,4,120,0,9,1070,0,0,2,2,0,1,0,1,9,0,0,1,3,0,0,
174,0,0,4,0,0,13,1072,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
197,0,0,4,0,0,15,1100,0,0,0,0,0,1,0,
212,0,0,4,0,0,15,1110,0,0,0,0,0,1,0,
227,0,0,5,739,0,6,1344,0,0,23,23,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,9,0,0,
1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,4,0,0,1,4,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,9,0,0,
334,0,0,6,0,0,17,1476,0,0,1,1,0,1,0,1,9,0,0,
353,0,0,6,0,0,21,1477,0,0,0,0,0,1,0,
368,0,0,6,0,0,17,1545,0,0,1,1,0,1,0,1,9,0,0,
387,0,0,6,0,0,21,1546,0,0,0,0,0,1,0,
402,0,0,7,147,0,4,1688,0,0,5,4,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,
437,0,0,8,86,0,4,1741,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/12/24              Virginia Yun
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
#include "../batchcommon.h"
#include "TxnSeq.h"
#include "pr_payout_generate_2.h"
#include "internal.h"
#include "ObjPtr.h"
#include "pr_bo_funct.h"
#include "pr_par_funct.h"
#include "pr_log_funct.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug = 'Y';
char    cs_hdfile[PD_MAX_FILE_LEN + 1];
char    cs_dtfile[PD_MAX_FILE_LEN + 1];
//char    csCcySet[10][4]={"CNY","HKD","GBP","USD","CAD","JPY"," ","EUR","TWD","INR"};

OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Channel);

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
//char*	GetNextMgtTxnSeq();
int	UpdateGenerateHeader(const hash_t *hRec);
int UpdateMerchantUploadFileDetail(const hash_t *hRls);
//int     GetStatusID(const char *csHDstatus, const char *csDTstatus, int *iStatusID);
int	CheckGeneratedHD(const char *csPspId,const char *csFileDate,const char *csFileSeq,const char *csFileName);
int	CheckGeneratedDT(hash_t * hTxn);

int handle_PayoutGen(hash_t * hContext);
int 	AssignValueforGenerate(hash_t *hContext, hash_t *hRequest);
int	AssignDateValue(hash_t *hTxn, hash_t *hContext, hash_t *hRequest);


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
	int	iCnt = 0;
	
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

	if (iRet != FAILURE) {
		GetField_Int(hTxn,"total_detail_record",&iCnt);
		if (iCnt > 0) {
			iRet = handle_PayoutGen(hTxn);
		}
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
	char	csTmpCcy [PD_CCY_ID_LEN + 1];
	char	csTmpPID [PD_PID_LEN + 1];

DEBUGLOG(("parse_header: Begin\n"));
	while( fgets(cs_input_buf, PD_MAX_BUFFER, fin) != NULL ){

		if ((cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A) || (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0D))
			cs_input_buf[strlen(cs_input_buf) - 1] = '\0';

		if(cs_input_buf[strlen(cs_input_buf) - 1] == 0x00)
			continue;

		i= 0;

		p = mystrtok(cs_input_buf,PD_MY_DELIMITOR);
                if (p != NULL){
                        strcpy(csList[i],TrimAllChar((const unsigned char*)p, strlen(p), PD_MY_TOKEN));
                        i++;

                        while ( (p = mystrtok(NULL,PD_MY_DELIMITOR)) != NULL) {
                                strcpy(csList[i],TrimAllChar((const unsigned char*)p, strlen(p), PD_MY_TOKEN));
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
				else if(iCount==IDX_HEADER_CCY_CD)
					sprintf(csTag,"ccy_%d",iRecord);
				//else if(iCount==IDX_HEADER_MEMBER_FEE_CCY_ID)
				//	sprintf(csTag,"member_fee_ccy_%d",iRecord);
				else if(iCount==IDX_HEADER_MEMBER_FEE)
					sprintf(csTag,"member_fee_%d",iRecord);
				else if(iCount==IDX_HEADER_POSTDATETIME)
					sprintf(csTag,"post_datetime_%d",iRecord);
				//else if(iCount==IDX_HEADER_MERCHANT_FEE_CCY_ID)
				//	sprintf(csTag,"merchant_fee_ccy_%d",iRecord);
				//else if(iCount==IDX_HEADER_MERCHANT_FEE)
				//	sprintf(csTag,"merchant_fee_%d",iRecord);
				else
					sprintf(csTag,"not_care");
	
				if (iCount == IDX_HEADER_PSP) {
					if (!strcmp(csList[iCount], "HAIPAY") || !strcmp(csList[iCount], "LINKINPAY")) {
						sprintf(csTmpPID, "%s", "HAIPAY0192");
					} else {
						sprintf(csTmpPID, "%s", csList[iCount]);
					}



					PutField_CString(hTxn, csTag, csTmpPID);
DEBUGLOG(("parse_header: Tag[%s]: [%s] [%s]\n",csTag, csList[iCount], csTmpPID));
				} 
				if (iCount == IDX_HEADER_CCY_CD) {
					if (strlen(csList[iCount])) {
						memset(csTmpCcy, 0, sizeof(csTmpCcy));
						if(!strcmp(csList[iCount],PD_CCY_ISO_RMB)){
							sprintf(csTmpCcy, "%s", PD_CCY_ISO_CNY);
						} else {
       	                                        	sprintf(csTmpCcy,"%s",csList[iCount]);
						}

						PutField_CString(hTxn,csTag,csTmpCcy);
DEBUGLOG(("parse_header: Tag[%s]: [%s]\n",csTag,csTmpCcy));
					}
				}

				if (iCount != IDX_HEADER_PSP && iCount != IDX_HEADER_CCY_CD) {
					PutField_CString(hTxn,csTag,csList[iCount]);
DEBUGLOG(("parse_header: Tag[%s]: [%s]\n",csTag,csList[iCount]));
				}
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
	int	iTmp = 0;
	unsigned long   lFileId = 0l;
	char    csFileId[PD_TXN_SEQ_LEN+1]; 
	char    csTag[PD_TAG_LEN+1];
	char	*csTmp;
	char	*csPspId;
	char	*csFileName;
	char	*csFileDate;
	char	*csFileSeq;
	char	*csVncFileId;
	double	dTmp=0.0;

	//int	iStatus;

	GetField_Int(hTxn,"file_count",&iFile);

	for(i=1;i<=iFile;i++){

		sprintf(csTag,"txn_count_%d",i);
		if (GetField_CString(hTxn, csTag, &csTmp)) {
			iTmp = atoi(csTmp);

			if (iTmp == 0) {
//DEBUGLOG(("process_header::Skip Header [%d]\n", i));
				continue;
			}
		}
DEBUGLOG(("process_header:: handle [%d]\n", i));


		if(GetFileId(&lFileId)!= PD_OK){
DEBUGLOG(("process_header::GetFileId Failed\n"));
ERRLOG("pr_payout_generate_2::process_header::GetFileId Failed\n");
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
ERRLOG("pr_payout_generate_2::process_header::ConvertField Failed\n");
			iRet = FAILURE;
			break;
		}

		sprintf(csTag,"psp_id_%d",i);
		if(GetField_CString(hTxn,csTag,&csPspId)){
			sprintf(csTag,"%s_psp_id",csFileId);
			PutField_CString(hTxn,csTag,csPspId);
		}

		sprintf(csTag,"psp_client_id_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			//sprintf(csTag,"%s_psp_client_id",csFileId);
			//PutField_CString(hTxn,csTag,csTmp);
		}

		sprintf(csTag,"filename_%d",i);
		if(GetField_CString(hTxn,csTag,&csFileName)){
			PutField_CString(hTxn,"filename",csFileName);
		}
		sprintf(csTag,"file_seq_%d",i);
		if(GetField_CString(hTxn,csTag,&csFileSeq)){
			if(is_numeric(csFileSeq))
				PutField_Int(hTxn,"seq_num",atoi(csFileSeq));
		}
		sprintf(csTag,"date_%d",i);
		if(GetField_CString(hTxn,csTag,&csFileDate)){
			PutField_CString(hTxn,"file_date",csFileDate);
		}
		sprintf(csTag,"txn_count_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			PutField_Int(hTxn,"txn_count",atoi(csTmp));
		}


		sprintf(csTag,"member_fee_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			if(sscanf(csTmp,"%lf",&dTmp)==1)
				PutField_Double(hTxn,"member_fee",dTmp);
		}
		sprintf(csTag,"ccy_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			PutField_CString(hTxn,"member_fee_ccy",csTmp);
			PutField_CString(hTxn,"ccy",csTmp);
		}
/*
		sprintf(csTag,"status_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){

			if (GetStatusID("HD", csTmp, &iStatus) != PD_OK) {
DEBUGLOG(("process_header::GetStatusID Failed\n"));
ERRLOG("process_header::GetStatusID Failed\n");
				iRet = FAILURE;
				break;
			}
DEBUGLOG(("process_header::GetStatusID [%s] [%d]\n", csTmp, iStatus));

			PutField_Int(hTxn,"status",iStatus);

			sprintf(csTag,"%s_status",csFileId);
			PutField_Int(hTxn,csTag,iStatus);
		}
*/
		//PutField_Int(hTxn,"status",PAYOUT_MASTER_TRANSACTION_GENERATED);
		PutField_Int(hTxn,"status",PD_PAYOUTFILE_PRE_GENERATED);
		sprintf(csTag,"%s_status",csFileId);
		//PutField_Int(hTxn,csTag,PAYOUT_MASTER_TRANSACTION_GENERATED);
		PutField_Int(hTxn,csTag,PD_PAYOUTFILE_PRE_GENERATED);


		sprintf(csTag,"skip_%d",i);
		if(CheckGeneratedHD(csPspId,csFileDate,csFileSeq,csFileName)!=PD_FOUND){
			PutField_Int(hTxn,csTag,PD_FALSE);
			if(AddGenerateHeader(hTxn)!=PD_OK){
ERRLOG("process_header::AddGenerateHeader Failed\n");
				iRet = FAILURE;
				break;
			}
		}
		else{
			PutField_Int(hTxn,csTag,PD_TRUE);
DEBUGLOG(("process_header::record found in HD, skip......\n"));
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
//	int	i = 0;
//	int	iCcy = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO getpsp_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_vnc_psp[PD_VNC_PSP_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_vnc_psp;


		/* varchar         v_ph_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_ph_psp_id;

                /* varchar         v_ph_psp_client_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_ph_psp_client_id;


		short           ind_ph_psp_id= -1;
                short           ind_ph_psp_client_id= -1;
        /* EXEC SQL END DECLARE SECTION; */ 


	sprintf(csTag,"psp_%d",iFile);
	if(GetField_CString(hTxn,csTag,&csTmp)){
        	hv_vnc_psp.len = strlen(csTmp);
        	memcpy(hv_vnc_psp.arr,csTmp,hv_vnc_psp.len);
DEBUGLOG(("ConvertField vnc_psp = [%.*s]\n",hv_vnc_psp.len,hv_vnc_psp.arr));
	}

        /* EXEC SQL DECLARE c_cursor_getpsp CURSOR FOR
                select 
			cp_preset_ph_pid,
			cp_client_id
                  from par_client_psp_map
                 where cp_psp_type_code = :hv_vnc_psp; */ 


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
                        :v_ph_psp_id:ind_ph_psp_id,
                        :v_ph_psp_client_id:ind_ph_psp_client_id; */ 

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
                sqlstm.sqhstv[0] = (unsigned char  *)&v_ph_psp_id;
                sqlstm.sqhstl[0] = (unsigned long )13;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_ph_psp_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_ph_psp_client_id;
                sqlstm.sqhstl[1] = (unsigned long )13;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_ph_psp_client_id;
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
// client_id
		if (ind_ph_psp_client_id >= 0) {
			v_ph_psp_client_id.arr[v_ph_psp_client_id.len] = '\0';
			PutField_CString(hTxn,"psp_client_id",(const char*)v_ph_psp_client_id.arr);
			sprintf(csTag,"psp_client_id_%d",iFile);
			PutField_CString(hTxn,csTag,(const char*)v_ph_psp_client_id.arr);
DEBUGLOG(("ConvertField ph_psp_client_id = [%s]\n",v_ph_psp_client_id.arr));
		}


		break; //// only one row
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getpsp; */ 

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
        if (sqlca.sqlcode < 0) goto getpsp_error;
}



	if(iRet!=PD_OK){
		return PD_ERR;
	}

	sprintf(csTag,"total_txn_amt_%d",iFile);

	if(GetField_CString(hTxn,csTag,&csTmp)){

		dTmp = atof(csTmp);
		PutField_Double(hTxn, "txn_amt", dTmp);
		PutField_Double(hTxn, csTag, dTmp);
		

/*
		if(is_numeric(csTmp)){
			dTmp = myctod((const unsigned char *)csTmp,strlen(csTmp) - PD_DECIMAL_LEN,PD_DECIMAL_LEN);
			PutField_Double(hTxn,"txn_amt",dTmp);
			PutField_Double(hTxn,csTag,dTmp);
DEBUGLOG(("ConvertField txn_amt = [%lf]\n",dTmp));
		}
*/
	
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

                /* varchar         hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

                int             hv_seq_num;
                int             hv_txn_count;
                double          hv_txn_amt;
                //double          hv_member_fee;
                int             hv_status;

                short           ind_file_id = -1;
                short           ind_psp_id = -1;
                short           ind_status = -1;
                short           ind_filename = -1;
                short           ind_seq_num= -1;
                short           ind_txn_count = -1;
                short           ind_txn_amt = -1;
                //short           ind_member_fee= -1;
                short           ind_ccy= -1;
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

/*ccy*/
        if(GetField_CString(hRls,"ccy",&csTmp)){
                hv_ccy.len = strlen(csTmp);
                memcpy(hv_ccy.arr, csTmp, hv_ccy.len);
                ind_ccy= 0;
DEBUGLOG(("Add:ccy = [%.*s]\n",hv_ccy.len,hv_ccy.arr));
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

/*member_fee
        if (GetField_Double(hRls,"member_fee",&dTmp)) {
                hv_member_fee= dTmp;
                ind_member_fee= 0;
DEBUGLOG(("Add:member_fee = [%lf]\n",hv_member_fee));
        }
*/
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
                                        :hv_ccy:ind_ccy,
                                        :hv_status:ind_status);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_insert_for_parallel_run\
 ( :hv_file_id:ind_file_id , :hv_file_date:ind_file_date , :hv_psp_id:ind_psp\
_id , :hv_seq_num:ind_seq_num , :hv_filename:ind_filename , :hv_txn_count:ind\
_txn_count , :hv_txn_amt:ind_txn_amt , :hv_ccy:ind_ccy , :hv_status:ind_statu\
s ) ; END ;";
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
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_ccy;
        sqlstm.sqhstl[8] = (unsigned long )5;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_ccy;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&ind_status;
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
	char	csTmpCcy [PD_CCY_ID_LEN + 1];

        while( fgets(cs_input_buf, PD_MAX_BUFFER, fin) != NULL ){

                if ((cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A) || (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0D))
                        cs_input_buf[strlen(cs_input_buf) - 1] = '\0';

                if(cs_input_buf[strlen(cs_input_buf) - 1] == 0x00)
                        continue;

DEBUGLOG(("parse_detail: DATA=[%s]\n",cs_input_buf));
                i= 0;

                p = mystrtok(cs_input_buf,PD_MY_DELIMITOR);
                if (p != NULL){
                        strcpy(csList[i],TrimAllChar((const unsigned char*)p, strlen(p), PD_MY_TOKEN));
                        i++;

                        while ( (p = mystrtok(NULL,PD_MY_DELIMITOR)) != NULL) {
                                strcpy(csList[i], TrimAllChar((const unsigned char*)p, strlen(p), PD_MY_TOKEN));
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
				else if(iCount==IDX_DETAIL_REQ_CCY_CD)
					sprintf(csTag,"request_currency_%d",iRec);
				else if(iCount==IDX_DETAIL_DST_CCY_CD)
					sprintf(csTag,"payout_currency_%d",iRec);
				else
					sprintf(csTag,"not_care");


				if(strlen(csList[iCount])){
					if(iCount==IDX_DETAIL_REQ_CCY_CD
					 ||iCount==IDX_DETAIL_DST_CCY_CD){
						if(!strcmp(csList[iCount],PD_CCY_ISO_RMB)){
							sprintf(csTmpCcy,"%s",PD_CCY_ISO_CNY);
						}
						else{
							sprintf(csTmpCcy,"%s",csList[iCount]);
						}
						PutField_CString(hTxn,csTag,csTmpCcy);
DEBUGLOG(("parse_detail: Tag[%s]: [%s]\n",csTag,csTmpCcy));
					}
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
	//int	iStatus= 0;
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

DEBUGLOG(("process_detail::psp_id = [%s] !!!!\n", csTmp));
			PutField_CString(hTxn,"psp_id",csTmp);
			PutField_CString(hTxn,"org_psp_id",csTmp);
		}

		DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextPayoutTxnSeq");
                strcpy(csTxnSeq, (*DBObjPtr)());

		//csTxnSeq  = strdup((char *)GetNextPayoutTxnSeq());
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
ERRLOG("process_detail: Found batch_id failed\n");
				iRet = FAILURE;
				break;
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

DEBUGLOG(("process_detail: payout_currency [%s][%s]\n", csTag, csTmp));

			PutField_CString(hTxn,"payout_currency",csTmp);
			sprintf(csTag,"%s_payout_currency",csFileId);

DEBUGLOG(("process_detail: payout_currency [%s][%s]\n", csTag, csTmp));

			PutField_CString(hTxn,csTag,csTmp);
		}
		sprintf(csTag,"payout_amount_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			if(sscanf(csTmp,"%lf",&dTmp)==1){
				PutField_Double(hTxn,"payout_amount",dTmp);
				PutField_Double(hTxn,"request_amount",dTmp);
				PutField_Double(hTxn,"org_dst_net_amt",dTmp);
			}
		}
		sprintf(csTag,"request_currency_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			PutField_CString(hTxn,"request_currency",csTmp);
		}
/*
		sprintf(csTag,"request_amount_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			if(sscanf(csTmp,"%lf",&dTmp)==1){
				PutField_Double(hTxn,"request_amount",dTmp);
			}
		}
*/

		//PutField_Int(hTxn,"status",PAYOUT_MASTER_TRANSACTION_GENERATED);
		PutField_Int(hTxn,"status",PAYOUT_MASTER_TRANSACTION_APPROVED);

		if(CheckGeneratedDT(hTxn)!=PD_FOUND){ //Check by upload_txn_id

			if(AddGenerateDetail(hTxn)!=PD_OK){
ERRLOG("process_detail: AddGenerateDetail failed\n");
				iRet = FAILURE;
				break;
			}

			if(UpdateMerchantUploadFileDetail(hTxn)!=PD_OK){
ERRLOG("process_detail: UpdateMerchantUploadFileDetail failed\n");
				iRet = FAILURE;
				break;
			}


			PutField_Char(hTxn,"txn_type",PD_TYPE_PAYOUT);

			RemoveField_Double(hTxn, "precal_fee");

			BOObjPtr = CreateObj(BOPtr,"BOPsp","CalPspCosts");
			if((unsigned long)(*BOObjPtr)(hTxn,hTxn)!=PD_OK){
ERRLOG("process_detail: CalPspCosts failed\n");
				iRet = FAILURE;
				break;
			}
			else{
				if(GetField_Double(hTxn,"precal_fee",&dTmp)){
DEBUGLOG(("process_detail: precal_fee [%lf]\n", dTmp));
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
		else{
DEBUGLOG(("process_detail::record found in DT, skip......\n"));
		}

	}

/*
	for(i=1; i<=iFile; i++){
		sprintf(csTag,"batch_id_%d",i);
		if(GetField_CString(hTxn,csTag,&csTmp)){
			PutField_CString(hTxn,"batch_id",csTmp);
			sprintf(csTag,"%s_vnc_ref_num",csTmp);
			if(GetField_CString(hTxn,csTag,&csTmp)){
				PutField_CString(hTxn,"vnc_ref_num",csTmp);
DEBUGLOG(("process_header: UpdateGenerateHeader = [%s]\n",csTmp));
				if(UpdateGenerateHeader(hTxn)!=PD_OK){
ERRLOG("process_detail: UpdateGenerateHeader failed\n");
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
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0004;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )151;
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
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )174;
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

                break; /////only one row
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getbatch; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )197;
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
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )212;
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
struct { unsigned short len; unsigned char arr[100]; } hv_account_name;

                /* varchar         hv_bank_name[PD_BANK_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_name;

                /* varchar         hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;

                /* varchar         hv_branch[PD_BANK_BRANCH_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_branch;

                /* varchar         hv_phone_num[PD_MOBILE_NO_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_phone_num;

                /* varchar         hv_province[PD_PROVINCE_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_province;

                /* varchar         hv_city[PD_CITY_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_city;

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
DEBUGLOG(("Add:account_name = [%.*s] [%d]\n",hv_account_name.len,hv_account_name.arr, hv_account_name.len));
        }

/*bank_name*/
        if(GetField_CString(hRls,"bank_name",&csTmp)){
                hv_bank_name.len = strlen(csTmp);
                memcpy(hv_bank_name.arr, csTmp, hv_bank_name.len);
                ind_bank_name = 0;
DEBUGLOG(("Add:bank_name = [%.*s] [%d]\n",hv_bank_name.len,hv_bank_name.arr, hv_bank_name.len));
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
                                        :hv_gen_txn_id:ind_gen_txn_id,
                                        :hv_txn_id:ind_txn_id,
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
_currency:ind_request_currency , :hv_gen_txn_id:ind_gen_txn_id , :hv_txn_id:i\
nd_txn_id , :hv_status:ind_status , :hv_add_user:ind_add_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )227;
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
        sqlstm.sqhstl[8] = (unsigned long )102;
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
        sqlstm.sqhstl[11] = (unsigned long )102;
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
        sqlstm.sqhstl[13] = (unsigned long )52;
        sqlstm.sqhsts[13] = (         int  )0;
        sqlstm.sqindv[13] = (         short *)&ind_province;
        sqlstm.sqinds[13] = (         int  )0;
        sqlstm.sqharm[13] = (unsigned long )0;
        sqlstm.sqadto[13] = (unsigned short )0;
        sqlstm.sqtdso[13] = (unsigned short )0;
        sqlstm.sqhstv[14] = (unsigned char  *)&hv_city;
        sqlstm.sqhstl[14] = (unsigned long )52;
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
        sqlstm.sqhstv[19] = (unsigned char  *)&hv_gen_txn_id;
        sqlstm.sqhstl[19] = (unsigned long )18;
        sqlstm.sqhsts[19] = (         int  )0;
        sqlstm.sqindv[19] = (         short *)&ind_gen_txn_id;
        sqlstm.sqinds[19] = (         int  )0;
        sqlstm.sqharm[19] = (unsigned long )0;
        sqlstm.sqadto[19] = (unsigned short )0;
        sqlstm.sqtdso[19] = (unsigned short )0;
        sqlstm.sqhstv[20] = (unsigned char  *)&hv_txn_id;
        sqlstm.sqhstl[20] = (unsigned long )18;
        sqlstm.sqhsts[20] = (         int  )0;
        sqlstm.sqindv[20] = (         short *)&ind_txn_id;
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

int UpdateMerchantUploadFileDetail(const hash_t *hRls)
{
	int	iRet = PD_OK;
	char*   csBuf;
        char*   csBatchId;
        char*   csSeqNum;
        int     iSeqNum;
        int     iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO updatedt_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateMerchantUploadFileDetail: Begin\n"));
        csBuf = (char*) malloc (128);
        csSeqNum = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update merchant_upload_file_detail set ud_update_timestamp = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        if(GetField_CString(hRls,"batch_id",&csBatchId)){
DEBUGLOG(("UpdateMerchantUploadFileDetail:batch_id = [%s]\n",csBatchId));
        }
        else{
                FREE_ME(csBuf);
DEBUGLOG(("UpdateMerchantUploadFileDetail batch_id not found\n"));
                return PD_ERR;
        }

        if(GetField_Int(hRls,"seq_num",&iSeqNum)){
                sprintf(csSeqNum,"%d",iSeqNum);
DEBUGLOG(("UpdateMerchantUploadFileDetail:seq_num = [%s]\n",csSeqNum));
        }
        else{
                FREE_ME(csSeqNum);
DEBUGLOG(("UpdateMerchantUploadFileDetail seq_num not found\n"));
                return PD_ERR;
        }

	if(GetField_CString(hRls,"file_id",&csBuf)){
DEBUGLOG(("UpdateMerchantUploadFileDetail: generated_file_id = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_generated_file_id = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	if(GetField_CString(hRls,"psp_id",&csBuf)){
DEBUGLOG(("UpdateMerchantUploadFileDetail: psp_id= [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",ud_psp_id = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	if(GetField_Int(hRls,"status",&iTmp)){
DEBUGLOG(("UpdateMerchantUploadFileDetail: status = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",ud_status = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        strcat((char*)hv_dynstmt.arr, " WHERE ud_batch_id = ");
        strcat((char*)hv_dynstmt.arr, csBatchId);
        strcat((char*)hv_dynstmt.arr, " AND ud_seq_num = ");
        strcat((char*)hv_dynstmt.arr, csSeqNum);
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
        sqlstm.offset = (unsigned int  )334;
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
        sqlstm.arrsiz = 23;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )353;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto updatedt_error;
}



        FREE_ME(csBuf);
        FREE_ME(csSeqNum);

DEBUGLOG(("UpdateMerchantUploadFileDetail Normal Exit\n"));
        return iRet;

updatedt_error:
DEBUGLOG(("updatedt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("par_payout_handler_UpdateMerchantUploadFileDetail: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
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
        sqlstm.offset = (unsigned int  )368;
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
        sqlstm.offset = (unsigned int  )387;
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

/*
int     GetStatusID(const char *csType, const char *csStatus, int *iStatusID)
{
        int iRet = PD_OK;

        EXEC SQL WHENEVER SQLERROR GOTO getstatusid_error;
        EXEC SQL WHENEVER NOTFOUND CONTINUE;

        EXEC SQL BEGIN DECLARE SECTION;
                varchar         hv_type[PD_PAYOUT_STATUS_TYPE_LEN];
                varchar         hv_status[PD_DESC_LEN];

                int             v_status_id;
                short           ind_status_id = -1;

        EXEC SQL END DECLARE SECTION;

        hv_type.len = strlen(csType);
        memcpy(hv_type.arr,csType,hv_type.len);
DEBUGLOG(("GetStatusID type = [%.*s]\n",hv_type.len,hv_type.arr));

        hv_status.len = strlen(csStatus);
        memcpy(hv_status.arr,csStatus,hv_status.len);
DEBUGLOG(("GetStatusID status = [%.*s]\n",hv_status.len,hv_status.arr));

        EXEC SQL DECLARE c_cursor_getstatusid CURSOR FOR
                select
                        ps_status_id
                  from par_payout_status
                 where ps_type = :hv_type
                   and ps_status = :hv_status;

        EXEC SQL OPEN c_cursor_getstatusid;
        do {
                EXEC SQL FETCH c_cursor_getstatusid
                INTO
                        :v_status_id:ind_status_id;

                if (SQLCODE == SQL_NOT_FOUND) {
                        iRet = SQL_NOT_FOUND;
                        break;
                }
// status_id
               if (ind_status_id>= 0) {
                        *iStatusID=v_status_id;
DEBUGLOG(("GetStatusID iStatusID = [%d]\n", *iStatusID));
                }

                break; ////////only one row
        }
        while(PD_TRUE);

        EXEC SQL CLOSE c_cursor_getstatusid;

DEBUGLOG(("GetStatusID Normal Exit\n"));
        if(iRet==0) return  PD_OK;
        else    return iRet;

getstatusid_error:
DEBUGLOG(("getstatusid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        EXEC SQL WHENEVER SQLERROR CONTINUE;
        EXEC SQL CLOSE c_cursor_getstatusid;
        return PD_ERR;
}
*/


int	CheckGeneratedHD(const char *csPspId,const char *csFileDate,const char *csFileSeq,const char *csFileName)
{
	int iRet = PD_FOUND;

        /* EXEC SQL WHENEVER SQLERROR GOTO checkhd_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

                /* varchar         hv_file_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_file_date;

                /* varchar         hv_file_name[PD_FILENAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_file_name;

                int		hv_file_seq;

		int		v_cnt;
		short		ind_cnt = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_psp_id.len = strlen(csPspId);
        memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);
DEBUGLOG(("CheckGeneratedHD psp_id = [%.*s]\n",hv_psp_id.len,hv_psp_id.arr));

        hv_file_date.len = strlen(csFileDate);
        memcpy(hv_file_date.arr,csFileDate,hv_file_date.len);
DEBUGLOG(("CheckGeneratedHD file_date = [%.*s]\n",hv_file_date.len,hv_file_date.arr));

        hv_file_seq = atoi(csFileSeq);
DEBUGLOG(("CheckGeneratedHD file_seq = [%d]\n",hv_file_seq));

        hv_file_name.len = strlen(csFileName);
        memcpy(hv_file_name.arr,csFileName,hv_file_name.len);
DEBUGLOG(("CheckGeneratedHD file_name = [%.*s]\n",hv_file_name.len,hv_file_name.arr));

        /* EXEC SQL SELECT count(*)
                INTO    :v_cnt:ind_cnt
                FROM    payout_generated_file_hd
		WHERE	fh_file_pid = :hv_psp_id
		AND	fh_file_date = :hv_file_date
		AND	fh_filename = :hv_file_name
		AND	fh_seq_num = :hv_file_seq; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 23;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count(*)  into :b0:b1  from payout_generated_\
file_hd where (((fh_file_pid=:b2 and fh_file_date=:b3) and fh_filename=:b4) a\
nd fh_seq_num=:b5)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )402;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_cnt;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_file_date;
        sqlstm.sqhstl[2] = (unsigned long )10;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_file_name;
        sqlstm.sqhstl[3] = (unsigned long )52;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_file_seq;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
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
        if (sqlca.sqlcode < 0) goto checkhd_error;
}



        if(ind_cnt>=0){
		if(v_cnt>0){
DEBUGLOG(("CheckGeneratedHD Found\n"));
		}
		else{
DEBUGLOG(("CheckGeneratedHD NOT FOUND\n"));
			iRet = PD_NOT_FOUND;
		}
        }
        else {
DEBUGLOG(("CheckGeneratedHD NOT FOUND\n"));
		iRet = PD_NOT_FOUND;
        }

	return iRet;	

checkhd_error:
DEBUGLOG(("checkhd_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_FOUND;
}

int	CheckGeneratedDT(hash_t * hTxn)
{
	int iRet = PD_FOUND;
	char	*csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO checkdt_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_upload_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_upload_txn_id;


		int		v_cnt;
		short		ind_cnt = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	if(GetField_CString(hTxn,"txn_id",&csTmp)){
		hv_upload_txn_id.len = strlen(csTmp);
		memcpy(hv_upload_txn_id.arr,csTmp,hv_upload_txn_id.len);
DEBUGLOG(("CheckGeneratedDT upload_txn_id = [%.*s]\n",hv_upload_txn_id.len,hv_upload_txn_id.arr));
	}

        /* EXEC SQL SELECT count(*)
                INTO    :v_cnt:ind_cnt
                FROM    payout_generated_file_dt
		WHERE	fd_upload_txn_id = :hv_upload_txn_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 23;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count(*)  into :b0:b1  from payout_generated_\
file_dt where fd_upload_txn_id=:b2";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )437;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_cnt;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_upload_txn_id;
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
        if (sqlca.sqlcode < 0) goto checkdt_error;
}



        if(ind_cnt>=0){
		if(v_cnt>0){
DEBUGLOG(("CheckGeneratedDT Found\n"));
		}
		else{
DEBUGLOG(("CheckGeneratedDT NOT FOUND\n"));
			iRet = PD_NOT_FOUND;
		}
        }
        else {
DEBUGLOG(("CheckGeneratedDT NOT FOUND\n"));
		iRet = PD_NOT_FOUND;
        }
	

	return iRet;	

checkdt_error:
DEBUGLOG(("checkdt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_FOUND;
}


int handle_PayoutGen(hash_t * hContext)
{
	int	iRet = SUCCESS;

	int	i = 0;
	char	*csTmp;
	int	iTmp = 0;
	char	*csPspId;
	int	iPspCnt = 0;
	char	*csPayoutCcy;
	char	*csPspCountry;
	char	csTmpBatch[PD_TXN_SEQ_LEN + 1];
	char    csTag[PD_TAG_LEN +1];

	double	dAmt = 0.0;
	double	dPspFee = 0.0;
	double	dBal = 0.0;
	double	dTmp = 0.0;
	double	dBatchAmt = 0.0;

	int	iBatchCnt = 0;

	hash_t	*hRec, *hDetail, *hTmpRec;
        recordset_t     *rRecordSet, *rTmpSet, *rDetailSet;

	hash_t   *hRequest, *hHeader;
	hash_t	 *hTxn, *hUploadTxn, *hElement;

        hRequest = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hRequest,0);
        hHeader= (hash_t*) malloc (sizeof(hash_t));
        hash_init(hHeader,0);

        hTxn= (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTxn,0);

        hUploadTxn = (hash_t*) malloc (sizeof(hash_t));

        hElement= (hash_t*) malloc (sizeof(hash_t));
	hash_init(hElement, 0);

        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        rTmpSet = (recordset_t*) malloc (sizeof(recordset_t));
        rDetailSet = (recordset_t*) malloc (sizeof(recordset_t));


        recordset_init(rRecordSet,0);


	iRet = AssignValueforGenerate(hContext, hRequest);

	if (iRet == SUCCESS) {

DEBUGLOG(("handle_PayoutGen::Call DBPayoutGeneratedFileHD:GetPreGenHeader\n"));
	        DBObjPtr = CreateObj(DBPtr,"DBPayoutGeneratedFileHD","GetPreGenHeader");
        	if((unsigned long)(*DBObjPtr)(PD_PAYOUTFILE_PRE_GENERATED,rRecordSet)==PD_OK){
                	hRec = RecordSet_GetFirst(rRecordSet);
                	while ((hRec) && (iRet==PD_OK)) {
				hash_destroy(hContext);
        			hash_init(hContext,0);
				

				hash_destroy(hHeader);
        			hash_init(hHeader,0);
				hash_destroy(hRequest);
				hash_init(hRequest, 0);
				hash_destroy(hTxn);
				hash_init(hTxn, 0);
				hash_destroy(hElement);
				hash_init(hElement, 0);

				iRet = AssignValueforGenerate(hContext, hRequest);

				if (iRet == SUCCESS) {

	                        	if(GetField_CString(hRec,"file_id",&csTmp)){
       	                         		PutField_CString(hHeader,"file_id",csTmp);
                                		PutField_CString(hTxn,"file_id",csTmp);
                                		PutField_CString(hRequest,"file_id",csTmp);
DEBUGLOG(("GetPreGenHeader::file_id = [%s]\n",csTmp));
                        		}
                        		if(GetField_Int(hRec,"seq_num",&iTmp)){
                                		PutField_Int(hTxn,"seq_num",iTmp);
DEBUGLOG(("GetPreGenHeader::seq_num = [%d]\n",iTmp));
                        		}
                        		if(GetField_CString(hRec,"file_date",&csTmp)){
                                		PutField_CString(hTxn,"file_date",csTmp);
DEBUGLOG(("GetPreGenHeader::file_date = [%s]\n",csTmp));
                        		}

                        		if(GetField_Int(hRec,"txn_count",&iTmp)){
                                		PutField_Int(hTxn,"txn_cnt",iTmp);
DEBUGLOG(("GetPreGenHeader::txn_count = [%d]\n",iTmp));
                        		}
                        		if(GetField_CString(hRec,"psp_id",&csPspId)){
                                		PutField_CString(hRequest,"psp_id",csPspId);
                                		PutField_CString(hTxn,"psp_id",csPspId);
                                		PutField_CString(hTxn,"org_psp_id",csPspId);
                                		iPspCnt++;
                                		PutField_Int(hContext,"psp_count",iPspCnt);
DEBUGLOG(("GetPreGenHeader::psp_id = [%s]\n",csPspId));
                        		}

					//*******************
					if (GetField_CString(hRec, "merchant_id", &csTmp)) {
						PutField_CString(hRequest, "merchant_id", csTmp);
DEBUGLOG(("GetPreGenHeader::merchant_id= [%s]\n",csTmp));
					}
					//*******************
						

	                        	if(GetField_CString(hRec,"payout_ccy",&csPayoutCcy)){
                                		PutField_CString(hContext,"org_psp_txn_ccy",csPayoutCcy);
                                		PutField_CString(hContext,"org_txn_ccy",csPayoutCcy);
DEBUGLOG(("GetPreGenHeader::payout_ccy = [%s]\n",csPayoutCcy));
                        		}

                        		if(GetField_Double(hRec,"total_txn_amt",&dAmt)){
                                		PutField_Double(hContext,"org_dst_net_amt",dAmt);
DEBUGLOG(("GetPreGenHeader::total_txn_amt = [%lf]\n",dAmt));
                        		}
			
                        		recordset_init(rTmpSet,0);
                        		DBObjPtr = CreateObj(DBPtr,"DBPspCountry","GetPspCountry");
					if((unsigned long) ((*DBObjPtr)(csPspId,rTmpSet))==PD_OK){
                                		hTmpRec = RecordSet_GetFirst(rTmpSet);
                                		while(hTmpRec){
                                        		if (GetField_CString(hTmpRec,"ccy_id",&csTmp)) {
DEBUGLOG(("GetPreGenHeader::ccy_id [%s] payoutccy [%s]\n",csTmp, csPayoutCcy));
                                                		if(strcmp(csTmp,csPayoutCcy)){
                                                        		continue;
                                                		}
                                        		}
                                        		if (GetField_CString(hTmpRec,"country",&csPspCountry)) {
                                                		PutField_CString(hContext,"txn_country",csPspCountry);
DEBUGLOG(("GetPreGenHeader::txn_country= [%s]\n",csPspCountry));
                                        		}
                                        		hTmpRec = RecordSet_GetNext(rTmpSet);
                                		}

	                        	}
                        		else{
DEBUGLOG(("GetPreGenHeader::txn_country not found!!\n"));
ERRLOG("pr_payout_generate_2::GetPreGenHeader::txn_country not found!!\n");
                                		iRet=INT_ERR;
                                		break;
                        		}
					RecordSet_Destroy(rTmpSet);


					iRet = AssignDateValue(hTxn, hContext, hRequest);


                        		if(iRet==PD_OK){
                                		dBal = 0.0;
DEBUGLOG(("handle_PayoutGen::Call DBPspBalance:GetAvalPspBalance\n"));
                                		DBObjPtr = CreateObj(DBPtr,"DBPspBalance","GetAvalPspBalance");
                                		if((unsigned long)(*DBObjPtr)(csPspId,
                                                        csPayoutCcy,
                                                        csPspCountry,
                                                        &dBal)==PD_OK){
DEBUGLOG(("GetAvalPspBalance balance = [%lf]\n",dBal));
                                        		PutField_Double(hTxn,"org_psp_bal",dBal);
                                		}
                                		else{
                                        		iRet = INT_ERR;
DEBUGLOG(("GetAvalPspBalance find balance failed!!!!\n"));
                                        		break;
                                		}
                        		}
                        		RemoveField_Int(hTxn,"txn_cnt");

                        		if(GetField_CString(hRec,"filename",&csTmp)){
                                		PutField_CString(hTxn,"filename",csTmp);
                                		PutField_CString(hRequest,"generated_file_name",csTmp);
DEBUGLOG(("GetPreGenHeader::filename = [%s]\n",csTmp));
                        		}

					if (iRet == PD_OK) {
                                		hash_t *hPsp;
                                		hPsp = (hash_t*) malloc (sizeof(hash_t));
                                		hash_init(hPsp,0);
                                		DBObjPtr = CreateObj(DBPtr,"DBPspDetail","GetPspDetail");
                                		if (!(*DBObjPtr)(csPspId, hPsp)) {
                                        		if (GetField_CString(hPsp,"client_id",&csTmp)) {
                                                		PutField_CString(hContext,"psp_client_id",csTmp);
                                                		PutField_CString(hRequest,"client_id",csTmp);
DEBUGLOG(("BOPayout::handle_PayoutGen: GetPspDetail - client id = [%s]\n",csTmp));
                                        		}
                                		}
                                		FREE_ME(hPsp);
                        		}

                        		if(iRet==PD_OK){
                                		PutField_Int(hHeader,"status",PD_PAYOUTFILE_GENERATED);
                                		DBObjPtr = CreateObj(DBPtr,"DBPayoutGeneratedFileHD","Update");
                                		if((unsigned long)(*DBObjPtr)(hHeader)!=PD_OK){
DEBUGLOG(("Authorize::PayoutGeneratedFileHD::Update Error!!!\n"));
                                        		iRet = INT_ERR;
                                		}
                        		}

	                        	i =0;
       	                 		csTmpBatch[0]='\0';
                        		PutField_Int(hTxn,"status",PAYOUT_MASTER_TRANSACTION_APPROVED);

                        		recordset_init(rDetailSet,0);
                        		hash_init(hUploadTxn,0);

DEBUGLOG(("handle_PayoutGen::Call DBPayoutGeneratedFileDT:GetDetail\n"));
                        		DBObjPtr = CreateObj(DBPtr,"DBPayoutGeneratedFileDT","GetDetail");
                        		if((unsigned long)(*DBObjPtr)(hTxn,rDetailSet)==PD_OK){
                                		hDetail = RecordSet_GetFirst(rDetailSet);
                                		while ((hDetail) && (iRet==PD_OK)){
                                        		if(GetField_CString(hDetail,"txn_id",&csTmp)){
                                                		sprintf(csTag,"txn_seq_%d",i);
                                                		PutField_CString(hContext,csTag,csTmp);
                                                		PutField_CString(hContext,"txn_seq",csTmp);
                                                		PutField_CString(hElement,"from_txn_seq",csTmp);
                                        		}
                                        		if(GetField_CString(hDetail,"upload_txn_id",&csTmp)){
                                                		PutField_CString(hUploadTxn,"txn_seq",csTmp);
                                        		}
                                        		if(GetField_CString(hDetail,"service_code",&csTmp)){
                                                		sprintf(csTag,"service_code_%d",i);
                                                		PutField_CString(hContext,csTag,csTmp);
                                        		}

                                        		sprintf(csTag,"dst_txn_ccy_%d",i);
                                        		PutField_CString(hRequest,csTag,csPayoutCcy);
                                        		sprintf(csTag,"txn_ccy_%d",i);
                                        		PutField_CString(hRequest,csTag,csPayoutCcy);
                                        		PutField_CString(hElement,"org_txn_ccy",csPayoutCcy);
                                        		PutField_CString(hElement,"src_txn_fee_ccy",csPayoutCcy);

                                        		sprintf(csTag,"psp_id_%d",i);
                                        		PutField_CString(hRequest,csTag,csPspId);


                                        		if(GetField_CString(hDetail,"batch_id",&csTmp)){
                                                		if(strcmp(csTmpBatch,csTmp)){
                                                        		strcpy(csTmpBatch,csTmp);
                                                        		csTmpBatch[strlen(csTmp)]='\0';
                                                        		sprintf(csTag,"assign_batch_%d",iBatchCnt);
                                                        		PutField_CString(hContext,csTag,csTmpBatch);
                                                        		iBatchCnt++;
                                                        		PutField_Int(hContext,"assign_batch_cnt",iBatchCnt);
                                                		}
                                                		sprintf(csTag,"batch_id_%d",i);
                                                		PutField_CString(hRequest,csTag,csTmpBatch);
DEBUGLOG(("handle_PayoutGen::GetDetail batch_id[%s]\n",csTmp));
                                        		}

                                        		if(GetField_Double(hDetail,"payout_amount",&dTmp)){
                                                		dBatchAmt=0;
                                                		sprintf(csTag,"%s_total_amt",csTmpBatch);
                                                		GetField_Double(hContext,csTag,&dBatchAmt);
                                                		dBatchAmt+=dTmp;
                                                		PutField_Double(hContext,csTag,dBatchAmt);

                                                		sprintf(csTag,"gen_payout_amt_%d",i);
                                                		PutField_Double(hRequest,csTag,dTmp);
                                                		PutField_Double(hElement,"org_txn_amt",dTmp);

DEBUGLOG(("handle_PayoutGen::GetDetail payout_amt[%lf]\n",dTmp));

	                                                	PutField_Double(hTxn,"org_dst_net_amt",dTmp);
                                                		PutField_Char(hTxn,"txn_type",PD_TYPE_PAYOUT);
DEBUGLOG(("handle_PayoutGen::Call BOPsp CalPspCosts\n"));

								//**** for parallel_run *****
								RemoveField_Double(hTxn, "precal_fee");
								RemoveField_Double(hContext, "precal_fee");
								RemoveField_Double(hElement, "src_txn_fee");
							
								

                                                		BOObjPtr = CreateObj(BOPtr,"BOPsp","CalPspCosts");
                                                		if((unsigned long)(*BOObjPtr)(hTxn,hRequest)==PD_OK){
                                                        		if(GetField_Double(hTxn,"precal_fee",&dTmp)){
DEBUGLOG(("handle_PayoutGen::CalPspCosts:psp_id [%s] precal_fee [%lf] i [%d]\n", csPspId, dTmp, i));
                                                                		dPspFee += dTmp;

                                                                		sprintf(csTag,"precal_fee_%d",i);
                                                                		PutField_Double(hRequest,csTag,dTmp);
                                                                		PutField_Double(hContext,"total_precal_fee",dPspFee);
                                                                		PutField_Double(hElement,"src_txn_fee",dTmp);
DEBUGLOG(("handle_PayoutGen::payout_fee[%lf]\n",dTmp));
                                                        		} 
                                                		}

                                        		}
                                        		if(GetField_Int(hDetail,"seq_num",&iTmp)){
                                                		sprintf(csTag,"seq_num_%d",i);
                                                		PutField_Int(hRequest,csTag,iTmp);
DEBUGLOG(("handle_PayoutGen::GetDetail seq_num[%d]\n",iTmp));
                                        		}
                                        		if(GetField_CString(hDetail,"txn_country",&csTmp)){
                                                		sprintf(csTag,"txn_country_%d",i);
                                                		PutField_CString(hRequest,csTag,csTmp);
                                                		//PutField_CString(hContext,"txn_country",csTmp);
DEBUGLOG(("handle_PayoutGen::GetDetail txn_country[%s]\n",csTmp));
                                        		}


                                        		if(iRet==PD_OK){
                                                		PutField_CString(hContext,"process_type","0000");
                                                		PutField_CString(hContext,"process_code","000000");
                                                		PutField_Int(hContext,"do_logging",PD_TRUE);
                                                		PutField_Int(hContext,"db_commit",PD_FALSE);

DEBUGLOG(("handle_PayoutGen::Call MGTChannel:AddTxnLog\n"));
                                                		ChannelObjPtr = CreateObj(ChannelPtr,"MGTChannel","AddTxnLog");
                                                		if((unsigned long) ((*ChannelObjPtr)(hContext,hRequest))!=PD_OK){
                                                        		iRet = INT_ERR;
DEBUGLOG(("handle_PayoutGen::MGTChannel:AddTxnLog Failed\n"));
                                                		}
								//********************************
								if (iRet == SUCCESS) {
									// for transmission_datetime, tm_date
									/*
									char *csTxnDate;
									char *csTxnTime;
									char csDateTime[PD_DATE_LEN + PD_TIME_LEN + 1];

									hash_t *hDateTxn;
									hDateTxn= (hash_t *)malloc(sizeof(hash_t));
									hash_init (hDateTxn, 0);


									if (GetField_CString(hContext, "txn_seq", &csTmp)) {
										PutField_CString(hDateTxn, "txn_seq", csTmp);
									}

									//if (GetField_CString(hTxn, "file_date", &csTxnDate)) 
									if (GetField_CString(hTxn, "local_tm_date", &csTxnDate)) {

										if (GetField_CString(hContext, "local_tm_time", &csTxnTime)) {
											sprintf(csDateTime, "%s%s", csTxnDate, csTxnTime);
											csDateTime[PD_DATE_LEN+PD_TIME_LEN] = '\0';
										} else {
											sprintf(csDateTime, "%s", csTxnDate);
											csDateTime[PD_DATE_LEN]='\0';
										}
                                        					PutField_CString(hDateTxn, "transmission_datetime",csDateTime);
										PutField_CString(hDateTxn, "tm_date", csTxnDate);
									}
DEBUGLOG(("pr_payout_generate_2:: special cater transmission_datetime!\n"));
									DBObjPtr = CreateObj(DBPtr, "DBTransaction","Update");

									if ((unsigned long)((*DBObjPtr)(hDateTxn)) == PD_OK) {
DEBUGLOG(("pr_payout_generate_2::CreateNewSettlementTxn: call DBTransaction.Update SUCC!\n"));
                                					}
				                                	else {
										iRet = FAILURE;
DEBUGLOG(("pr_payout_generate_2::CreateNewSettlementTxn: call DBTransaction.Update FAILED!\n"));
                                					}

                                					hash_destroy(hDateTxn);
									FREE_ME(hDateTxn);
									*/
                        					}

								//********************************

                                                		PutField_Int(hContext,"do_logging",PD_FALSE);
                                        		}


                                        		if(iRet==PD_OK){
                                                		PutField_CString(hUploadTxn,"sub_status",PD_APPROVED_AND_GENERATED);
DEBUGLOG(("handle_PayoutGen::Call DBTransaction:Update (UploadTxn)\n"));
                                                		DBObjPtr = CreateObj(DBPtr,"DBTransaction","Update");
                                                		if((unsigned long) ((*DBObjPtr)(hUploadTxn))!=PD_OK){
                                                        		iRet = INT_ERR;
DEBUGLOG(("handle_PayoutGen::DBTransaction:Update Failed\n"));
                                                		}
                                        		}
                                        		if(iRet==PD_OK){
                                                		PutField_Char(hElement,"party_type",PD_TYPE_PSP);
                                                		PutField_CString(hElement,"amount_type",PD_DR);
DEBUGLOG(("handle_PayoutGen::Call BOTxnElements:AddTxnAmtElement\n"));
                                                		BOObjPtr = CreateObj(BOPtr,"BOTxnElements","AddTxnAmtElement");
                                                		iRet = (unsigned long)(*BOObjPtr)(hElement);


                                                		if(iRet==PD_OK){
DEBUGLOG(("handle_PayoutGen::Call BOTxnElements:AddTxnFeeElements\n"));
                                                        		BOObjPtr = CreateObj(BOPtr,"BOTxnElements","AddTxnFeeElements");
                                                        		iRet = (unsigned long)(*BOObjPtr)(hElement);
                                                		}
                                        		}

                                        		i++;
                                        		PutField_Int(hRequest,"total_count",i);
                                        		PutField_Int(hContext,"total_cnt",i);
                                        		hDetail = RecordSet_GetNext(rDetailSet);
                                		}

                                		if(iRet==PD_OK){
                                        		PutField_Int(hTxn,"status",PAYOUT_MASTER_TRANSACTION_GENERATED);
                                        		DBObjPtr = CreateObj(DBPtr,"DBPayoutGeneratedFileDT","UpdateByFileId");
                                        		if((unsigned long)(*DBObjPtr)(hTxn)!=PD_OK){
                                                		iRet=INT_ERR;
DEBUGLOG(("handle_PayoutGen::DBPayoutGeneratedFileDT Update Failed!!!\n"));
ERRLOG("pr_payout_generate_2::handle_PayoutGen:DBPayoutGeneratedFileDT Update Failed!!!\n");
                                        		}
                                		}
                        		}

                        		hRec = RecordSet_GetNext(rRecordSet);

					if(iRet == PD_OK){

                                		PutField_Char(hContext,"response_mode",PD_ACCEPT);
                                		PutField_CString(hContext,"desc","Payout (PSP)");
                                		PutField_Char(hContext,"party_type",PD_TYPE_PSP);

                                		//if(GetField_CString(hContext,"PHDATE",&csTmp)){
                                        	// 	PutField_CString(hContext,"approval_date",csTmp);
                                		//}

DEBUGLOG(("handle_PayoutGen:: prepare for HandlePayoutBalance!\n"));
						RemoveField_CString(hContext, "bank_name");
						RemoveField_CString(hContext, "branch");
						RemoveField_CString(hContext, "account_id");
						RemoveField_CString(hContext, "account_name");


						BOObjPtr = CreateObj(BOPtr,"BOPayout","HandlePayoutBalance");
						if((unsigned long)(*BOObjPtr)(hContext,hRequest)!=PD_OK){
DEBUGLOG(("handle_PayoutGen::HandlePayoutBalance Failed!!!\n"));
ERRLOG("pr_payout_generate_2::handle_PayoutGen:HandlePayoutBalance Failed!!!\n");
                                        		iRet = INT_ERR;
                                		}
                        		}

                        		if(iRet==PD_OK){
						BOObjPtr = CreateObj(BOPtr,"BOPayout","UpdateDetail");
						if((unsigned long)(*BOObjPtr)(hContext,hRequest)!=PD_OK){
DEBUGLOG(("handle_PayoutGen::UpdateDetail Failed!!!\n"));
ERRLOG("pr_payout_generate_2::handle_PayoutGen:UpdateDetail Failed!!!\n");
                                        		iRet = INT_ERR;
                                		}
                        		}
                		}
			}
		}

        }

        FREE_ME(hTxn);
        FREE_ME(hUploadTxn);
        FREE_ME(hElement);
        RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);
        RecordSet_Destroy(rDetailSet);
        FREE_ME(rDetailSet);

	FREE_ME(rTmpSet);

	return iRet;
}

int 	AssignValueforGenerate(hash_t *hContext, hash_t *hRequest)
{

	int iRet = SUCCESS;

	// **** Assign Value *****
	PutField_CString(hContext, "txn_code", PD_PAYOUT_GENERATE);
	PutField_CString(hRequest, "txn_code", PD_PAYOUT_GENERATE);

	PutField_CString(hContext, "channel_code", PD_CHANNEL_MGT);


	return iRet;
}

int	AssignDateValue(hash_t *hTxn, hash_t *hContext, hash_t *hRequest)
{
	int	iRet = SUCCESS;

	char	*csTmp;

        time_t  ct;
        struct  tm *sct;
        char    sys_date[PD_DATE_LEN + 1];
        char    sys_time[PD_TIME_LEN + 1];

        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

        char    *csCode = strdup("");
        char    *csValue= strdup("");

	hash_t  *hRec;


	if (GetField_CString(hTxn,"file_date",&csTmp)) {
		//PutField_CString(hContext, "PHDATE", csTmp);
		//PutField_CString(hContext, "host_posting_date", csTmp);
		//PutField_CString(hContext, "approval_date", csTmp);

		//PutField_CString(hContext, "tm_date", csTmp);

		PutField_CString(hContext, "psp_date", csTmp);
	}


	DBObjPtr = CreateObj(DBPtr,"DBSystemControl","GetAllCodes");
	if ((*DBObjPtr)(rRecordSet) == PD_OK) {
DEBUGLOG(("AssignDateValue:: return \n"));
		hRec = RecordSet_GetFirst(rRecordSet);
		while (hRec) {
			if (GetField_CString(hRec,"code",&csCode)) {
				if (GetField_CString(hRec,"value",&csValue)) {
					if (!strcmp(csCode,"CTPHDATE")) {
DEBUGLOG(("UpdateContext:Current Processor Hub Date= [%s]\n",csValue));

						PutField_CString(hContext,"PHDATE",csValue);
						PutField_CString(hContext,"host_posting_date",csValue);
						PutField_CString(hContext,"approval_date",csValue);
						PutField_CString(hContext,"tm_date",csValue);
					}
				}
			}
			hRec = RecordSet_GetNext(rRecordSet);
		}
	}



	ct = time((time_t *) 0);
	sct = localtime(&ct);

	memset(sys_date, 0, sizeof(sys_date));
	memset(sys_time, 0, sizeof(sys_time));

	sprintf(sys_date, "%04d%02d%02d",sct->tm_year + 1900, sct->tm_mon + 1, sct->tm_mday);
	sprintf(sys_time, "%02d%02d%02d",sct->tm_hour, sct->tm_min, sct->tm_sec);

	PutField_CString(hContext, "local_tm_date", sys_date);
	PutField_CString(hContext, "local_tm_time", sys_time);


	PutField_CString(hContext, "add_user", PD_UPDATE_USER);
	PutField_CString(hContext, "update_user", PD_UPDATE_USER);


        RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);

        FREE_ME(csCode);
        FREE_ME(csValue);

	return iRet;
}

