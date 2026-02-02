
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
    "extract_hpy_data.pc"
};


static unsigned int sqlctx = 40125059;


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


#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define	PD_MY_DELIMITOR	','

OBJPTR(BO);

char    cs_outputfile[PD_MAX_FILE_LEN + 1];
char    cs_psp_id[PD_PSP_ID_LEN + 1];
char    cs_date[PD_DATE_LEN + 1];
char    cDebug = 'Y';

int parse_arg(int argc,char **argv);
int process_txn(const char* csPspId,const char* csTxnDate,
                FILE *fp);
int batch_init(int argc, char* argv[])
{

    if (argc < 4) {
        printf("usage:  -o ouputfile -d Date -p PSP ID\n");
        return FAILURE;
    }
    else
        return SUCCESS;
}




int batch_proc(int argc, char* argv[])
{
        int     iRet;
        char    cs_outfile_name[PD_MAX_FILE_LEN + 1];
        FILE    *fp;

	iRet = parse_arg(argc,argv);
               
        if (iRet != SUCCESS) {
        	printf("usage:  -o ouputfile -d Date -p PSP ID\n");
                return (iRet);
        }

        sprintf(cs_outfile_name, "%s/%s_%s.dat", getenv("REPORT_DATA"),cs_outputfile,cs_date);
        
        fp = fopen(cs_outfile_name,"w");
        if (fp == NULL) {
DEBUGLOG(("batch_proc:unable to open [%s]\n",cs_outfile_name));
                return FAILURE;
        }
        
        iRet = process_txn(cs_psp_id,cs_date,fp);
        fclose(fp);
	return iRet;


}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}




int process_txn(const char* csPspId,const char* csTxnDate,
                FILE *fp)
{               
 
        int     iRet = SUCCESS;
	double	dTmp=0.0;
	char	*csTmp;
	hash_t	*hRec;

	recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	BOObjPtr = CreateObj(BOPtr,"BOReport","GetPspDepositTxn");
	if((unsigned long)(*BOObjPtr)(csPspId,csTxnDate,rRecordSet)==PD_OK){
		hRec = RecordSet_GetFirst(rRecordSet);
		while(hRec){
/* Field #0 txn_seq */
                	if (GetField_CString(hRec,"txn_id",&csTmp))
                		fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
			else
				fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #1 tid */
                	if (GetField_CString(hRec,"tid",&csTmp))
                		fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
			else
				fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #2 bank bill no*/
                	if (GetField_CString(hRec,"bank_bill_no",&csTmp))
                		fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
			else
				fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #3 txn_amount */
			if (GetField_CString(hRec,"amount",&csTmp))
				sscanf(csTmp,"%lf",&dTmp);
                	fprintf(fp,"%.2lf%c",dTmp,PD_MY_DELIMITOR);

/* Field #4 service_fee */
                        if (!GetField_Double(hRec,"service_fee",&dTmp)){
                                dTmp = 0.0;
                        }
                        fprintf(fp,"%.2lf%c",dTmp,PD_MY_DELIMITOR);

/* Field #5 status */
			fprintf(fp,"Success%c",PD_MY_DELIMITOR);

/* Field #6 fundin date*/
			if (GetField_CString(hRec,"fundin_date",&csTmp)){
				if(strlen(csTmp)==PD_DATETIME_LEN)
                        		fprintf(fp,"%.*s00",(int)strlen(csTmp)-2,csTmp);
                		else if(strlen(csTmp)==PD_DATE_LEN)
                        		fprintf(fp,"%.*s000000",(int)strlen(csTmp),csTmp);
                		else
                        		fprintf(fp,"%.*s",(int)strlen(csTmp),csTmp);
			}

			fprintf(fp,"\n");
			hRec = RecordSet_GetNext(rRecordSet);
		}
 	}

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);
        return iRet;
}


int parse_arg(int argc,char **argv)
{
        char    c;
        strcpy(cs_outputfile,"");
        strcpy(cs_psp_id,"");
        strcpy(cs_date,"");

        while ((c = getopt(argc,argv,"o:p:d:")) != EOF) {
                switch (c) {
                        case 'o':
                                strcpy(cs_outputfile, optarg);
                                break;
                        case 'p':
                                strcpy(cs_psp_id, optarg);
                                break;
                        case 'd':
                                strcpy(cs_date, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_outputfile,"") || !strcmp(cs_psp_id,"") || !strcmp(cs_date,""))
                return FAILURE;

        return SUCCESS;
}

