
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
    "get_auto_upload_provider.pc"
};


static unsigned int sqlctx = 1322883387;


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
   unsigned char  *sqhstv[1];
   unsigned long  sqhstl[1];
            int   sqhsts[1];
            short *sqindv[1];
            int   sqinds[1];
   unsigned long  sqharm[1];
   unsigned long  *sqharc[1];
   unsigned short  sqadto[1];
   unsigned short  sqtdso[1];
} sqlstm = {12,1};

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
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2018/07/06              [WMC]
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
#include "internal.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"
#include "dbutility.h"
#include "get_auto_upload_provider.h"

OBJPTR(DB);

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define PD_PROCESS_ALL_PROVIDER	"ALL"

static char    cDebug='Y';

char cs_nature_path[PD_TMP_BUF_LEN + 1];
char cs_provider_path[PD_TMP_BUF_LEN + 1];
char cs_process_bank[PD_TMP_BUF_LEN + 1];
int  int_job_seq;
int  int_bank_exclude;

int parse_arg(int argc,char **argv);


int batch_init(int argc, char* argv[])
{
    if (argc < 11) {
    	//printf("usage: -s job_seq -n nature_path -p provider_path -b process_bank -d bank_exclude\n");
        return FAILURE;
    }
    else
        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int	iRet = SUCCESS;
	int	iDtlRet = PD_FOUND;
	//int	iTmpRet = PD_OK;

	char	*csProviderPath = NULL;

	hash_t  *hProvider = NULL;
	recordset_t *rProvider;
        rProvider = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rProvider, 0);

DEBUGLOG(("batch_proc: start\n"));

	iRet = parse_arg(argc,argv);

	if (iRet != SUCCESS) {
    		//printf("*usage: -s job_seq -n nature_path -p provider_path -b process_bank -d bank_exclude\n");
		return (iRet);
	}

DEBUGLOG(("batch_proc: job_seq = [%d]\n",int_job_seq));
DEBUGLOG(("batch_proc: nature_path = [%s]\n",cs_nature_path));
DEBUGLOG(("batch_proc: provider_path = [%s]\n",cs_provider_path));
DEBUGLOG(("batch_proc: process_bank = [%s]\n",cs_process_bank));
DEBUGLOG(("batch_proc: bank_exclude = [%d]\n",int_bank_exclude));

	if (iRet == SUCCESS) {

		if (!strcmp(cs_provider_path, PD_PROCESS_ALL_PROVIDER)) {
	
			// Get Provider Path
			DBObjPtr = CreateObj(DBPtr,"DBOLAutoUploadStmtSetting","GetDetailByNaturePath");
            		iDtlRet = (unsigned long)(DBObjPtr)(cs_nature_path,rProvider); 
			if (iDtlRet == PD_FOUND) {
DEBUGLOG(("batch_proc: DBOLAutoUploadStmtSetting: GetDetailByNaturePath Found!!\n"));

				hProvider = RecordSet_GetFirst(rProvider);
                		while ((iRet == SUCCESS) && (hProvider)) {

/* provider_path */
                        		if (GetField_CString(hProvider,"provider_path",&csProviderPath)) {
DEBUGLOG(("batch_proc: provider_path = [%s]\n", csProviderPath));

                        			printf("%s\n", csProviderPath);
					} else {
DEBUGLOG(("batch_proc: provider_path is missing!!\n"));
ERRLOG("get_auto_upload_provider: batch_proc: provider_path is missing!!\n");
                        	        	iRet = FAILURE;
                        		}

					hProvider = RecordSet_GetNext(rProvider);
				}
			} else if (iDtlRet == PD_NOT_FOUND) {
DEBUGLOG(("batch_proc: DBOLAutoUploadStmtSetting: GetDetailByNaturePath Not Found!!\n"));

/*
				hash_t  *hUpdateJob = NULL;
			        hUpdateJob = (hash_t*) malloc (sizeof(hash_t));
        			hash_init(hUpdateJob,0);

        			PutField_Int(hUpdateJob, "job_seq", iJobSeq);
        			PutField_CString(hUpdateJob, "nature_path", cs_nature_path);
        			PutField_CString(hUpdateJob, "provider_path", cs_provider_path);
        			PutField_CString(hUpdateJob, "process_bank", cs_bank_short_name);
        			PutField_Int(hUpdateJob, "exclude_mode", iBankExclude);
        			PutField_Char(hUpdateJob, "status", PD_AUTO_UPL_JOB_STATUS_COMPLETE);
        			PutField_CString(hUpdateJob, "update_user", PD_UPDATE_USER);

				// Update Job Status
        			DBObjPtr = CreateObj(DBPtr,"DBOLAutoUploadJobStatus","UpdateStatus");
        			if ((unsigned long)(DBObjPtr)(hUpdateJob) == PD_OK) {
DEBUGLOG(("batch_proc: DBOLAutoUploadJobStatus: UpdateStatus to [%c] Success!!\n", cStatus));
DEBUGLOG(("batch_proc: DBOLAutoUploadJobStatus: UpdateStatus TxnCommit()\n"));
                			TxnCommit();
        			} else {
DEBUGLOG(("batch_proc: DBOLAutoUploadJobStatus: UpdateStatus Failed!!\n"));
ERRLOG("get_auto_upload_provider: batch_proc: DBOLAutoUploadJobStatus: UpdateStatus Failed!!\n");
                			iRet = FAILURE;
        			}

        			hash_destroy(hUpdateJob);
 	      			FREE_ME(hUpdateJob);
*/	
			
				iRet = FAILURE;
               		} else {
DEBUGLOG(("batch_proc: DBOLAutoUploadStmtSetting: GetDetailByNaturePath Failed!!\n"));
ERRLOG("get_auto_upload_provider: batch_proc: DBOLAutoUploadStmtSetting: GetDetailByNaturePath Failed!!\n");
                 		iRet = FAILURE;
              		}
		} else {
			printf("%s\n", cs_provider_path);
		}
	}

	RecordSet_Destroy(rProvider);
        FREE_ME(rProvider);

DEBUGLOG(("batch_proc: iRet = [%d]\n", iRet));
	return iRet;
}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

                        
int parse_arg(int argc,char **argv)
{               
        char    c;
	strcpy(cs_nature_path,"");
        strcpy(cs_provider_path,"");
        strcpy(cs_process_bank,"");
        int_job_seq = 0;
        int_bank_exclude = 0;

        while ((c = getopt(argc,argv,"s:n:p:b:d:")) != EOF) {
                switch (c) {
			case 's':
                                int_job_seq = atoi(optarg);
                                break;
                        case 'n':
                                strcpy(cs_nature_path, optarg);
                                break;
                        case 'p':
                                strcpy(cs_provider_path, optarg);
                                break;
                        case 'b':
                                strcpy(cs_process_bank, optarg);
                                break;
                        case 'd':
                                int_bank_exclude = atoi(optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }       
        
	if (!strcmp(cs_nature_path,"") || !strcmp(cs_provider_path,"") || !strcmp(cs_process_bank,""))
                return FAILURE;
                
        return SUCCESS; 
}
