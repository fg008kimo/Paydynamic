
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
    "getdatacompare.pc"
};


static unsigned int sqlctx = 9426051;


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
//#include "common.h"
#include "utilitys.h"
#include "expat.h"
#include <curl/curl.h>
#include "myhash.h"
#include "ObjPtr.h"
#include "numutility.h"
#include "myrecordset.h"

#include "getdatacompare.h"
#include "TxnSeq.h"


OBJPTR(DB);
char    cDebug;

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}



int formatString(const char* csTxnId, const char* csPayMethod, hash_t* hPspRec, char* csFormattedString)
{
	char *csTmp;
	char *csTid = strdup("");
	char *csBatchId = strdup("");
	char *csTxnDate = strdup("");
	char *csBank = strdup("");
	char *csBranch = strdup("");
	char *csAccName = strdup("");
	char *csAccNum = strdup("");
	char *csErrCode = strdup("");
	char *csAmount = strdup("");
	char *csServiceFee = strdup("");
	char cArInd = 'A';
	char cQ = '"';
	double dAmount;
	double dServiceFee;

	if(GetField_CString(hPspRec,"tid",&csTid)){
DEBUGLOG(("formatString:: tid = [%s]\n",csTid));
	}
	
	if(GetField_CString(hPspRec,"batch_id",&csBatchId)){
DEBUGLOG(("formatString:: batch_id = [%s]\n",csBatchId));
	}
	
	if (GetField_Double(hPspRec,"txn_amt",&dAmount)){
		dtoc(dAmount,12,0,csAmount);
		trim_leading_zero(csAmount,csAmount);
DEBUGLOG(("formatString:: amount =[%s]\n",csAmount));
	}

	if (GetField_Double(hPspRec,"service_fee",&dServiceFee)){
		dtoc(dServiceFee,12,0,csServiceFee);
		trim_leading_zero(csServiceFee,csServiceFee);
DEBUGLOG(("formatString:: service_fee =[%s]\n",csServiceFee));
	}

	if(GetField_CString(hPspRec,"txn_date",&csTmp)){
		strncpy(csTxnDate,csTmp,20);
		strncpy(&csTxnDate[strlen("yyyy")],"-",20-4);
		strncpy(&csTxnDate[strlen("yyyy-")],&csTmp[strlen("yyyy")],20-5);
		strncpy(&csTxnDate[strlen("yyyy-mm")],"-",20-7);
		strncpy(&csTxnDate[strlen("yyyy-mm-")],&csTmp[strlen("yyyymm")],20-8);
		strncpy(&csTxnDate[strlen("yyyy-mm-dd")]," 00:00:00",20-10);
		csTxnDate[strlen(csTxnDate)]='\0';
DEBUGLOG(("formatString:: txn_date = [%s]\n",csTxnDate));
	}
	
	if (GetField_CString(hPspRec,"bank_code", &csBank)){
DEBUGLOG(("formatString:: bank_code = [%s]\n",csBank));
	}

	if (GetField_CString(hPspRec,"bank_branch", &csBranch)){
DEBUGLOG(("formatString:: bank_branch = [%s]\n",csBranch));
	}

	if (GetField_CString(hPspRec,"account_name", &csAccName)){
DEBUGLOG(("formatString:: account_name = [%s]\n",csAccName));
	}

	if (GetField_CString(hPspRec,"account_no", &csAccNum)){
DEBUGLOG(("formatString:: account_no = [%s]\n",csAccNum));
	}

	if (GetField_CString(hPspRec,"error_code", &csErrCode)){
		if(strcmp(csErrCode,"0")==0)
			memset(csErrCode,0,2);
DEBUGLOG(("formatString:: error_code = [%s]\n",csErrCode));
	}

	snprintf(csFormattedString,BUFFER_LEN,"%c%s%c,%c%s%c,%c%c%c,%c%s%c,%c%s%c,%c%s%c,%c%s%c,%c%s%c,%c%s%c,%c%s%c,%c%s%c,%c%s%c,%c%s%c,%c%s%c\n",cQ,csTid,cQ,cQ,csTxnDate,cQ,cQ,cArInd,cQ,cQ,csTxnId,cQ,cQ,csPayMethod,cQ,cQ,csAmount,cQ,cQ,csBank,cQ,cQ,csBranch,cQ,cQ,csAccName,cQ,cQ,csAccNum,cQ,cQ,csErrCode,cQ,cQ,csTxnDate,cQ,cQ,csServiceFee,cQ,cQ,csBatchId,cQ);
DEBUGLOG(("formatString:: [%s]\n",csFormattedString));


	FREE_ME(csTid);
	FREE_ME(csBatchId);
	FREE_ME(csTxnDate);
	FREE_ME(csBank);
	FREE_ME(csBranch);
	FREE_ME(csAccName);
	FREE_ME(csAccNum);
	FREE_ME(csErrCode);
	FREE_ME(csAmount);
	FREE_ME(csServiceFee);

	return SUCCESS;
		
	
DEBUGLOG(("formatString::Failed\n"));
	return FAILURE;
}

void insertDataToFile(const char* csFormattedString)
{
	FILE* pFile;
	pFile = fopen(DATA_FROM_DB, "at");
	if(!pFile){
DEBUGLOG(("Cannot insert Data To File[%s]\n",DATA_FROM_DB));
			return;
	}
	else{
		fputs(csFormattedString,pFile);
	}

	fclose(pFile);
		
}

int getDetailsFromDB(const char* csDate)
{
	recordset_t	*rRecordSetTxnId;
        rRecordSetTxnId = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSetTxnId,0);

	recordset_t	*rRecordSetPspDetail;
        rRecordSetPspDetail = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSetPspDetail,0);

	recordset_t	*rRecordSetTxnDetail;
        rRecordSetTxnDetail = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSetTxnDetail,0);

	hash_t  *hRec;
	hash_t	*hPspRec;
	hash_t	*hTxnRec;
	char	*csTmp;
	char	*csOutput = strdup("");
	char	csTxnId[LIST_MAX][PD_TXN_SEQ_LEN+1];
	char	csPayMethod[LIST_MAX][PD_PAY_METHOD_LEN+1];

	int iNumOfRec=0;
	char cArInd = 'A';///A = accept

	DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnIdByTxnDateAndArInd");

	if ((unsigned long int)(*DBObjPtr)(csDate,cArInd,rRecordSetTxnId) == PD_OK) {
		hRec = RecordSet_GetFirst(rRecordSetTxnId);
		while(hRec){
			if(GetField_CString(hRec,"txn_id",&csTmp)){
				strncpy(csTxnId[iNumOfRec],csTmp,PD_TXN_SEQ_LEN);
				csTxnId[iNumOfRec][PD_TXN_SEQ_LEN]='\0';
				iNumOfRec++;
			}

			hRec = RecordSet_GetNext(rRecordSetTxnId);
		}
	}

	int i;
	for(i=0; i<iNumOfRec; i++){
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnDetail");
		if ((unsigned long int)(*DBObjPtr)(csTxnId[i],rRecordSetTxnDetail) == PD_OK) {
			hTxnRec = RecordSet_GetFirst(rRecordSetTxnDetail);

			if(GetField_CString(hTxnRec,"pay_method",&csTmp)){
				strncpy(csPayMethod[i],csTmp,PD_PAY_METHOD_LEN);
				csPayMethod[i][strlen(csTmp)]='\0';
			}
		}
		RecordSet_Destroy(rRecordSetTxnDetail);
	}


	for(i=0; i<iNumOfRec; i++){
		DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","GetTxnPspDetail");
		if ((unsigned long int)(*DBObjPtr)(csTxnId[i],rRecordSetPspDetail) == PD_OK) {
			hPspRec = RecordSet_GetFirst(rRecordSetPspDetail);
			if(formatString(csTxnId[i],csPayMethod[i],hPspRec, csOutput)==SUCCESS){
				insertDataToFile(csOutput);

			}
			RecordSet_Destroy(rRecordSetPspDetail);
		}
	}

	RecordSet_Destroy(rRecordSetTxnId);
	FREE_ME(rRecordSetTxnId);
	FREE_ME(rRecordSetTxnDetail)
	FREE_ME(rRecordSetPspDetail);
	FREE_ME(csOutput);
	return SUCCESS;
}


void clearFiles()
{
	FILE *pFile;

	pFile = fopen(DATA_FROM_DB,"w");
	fclose(pFile);

}

int batch_proc(int argc, char* argv[])
{
	clearFiles();
	insertDataToFile(DATA_FORMAT);

	char *csDate  = strdup("");
	strcpy(csDate,argv[1]);
	csDate[strlen("yyyymmdd")]='\0';

DEBUGLOG(("Start reading DB\n"));	
	if(getDetailsFromDB(csDate)!=SUCCESS){
		FREE_ME(csDate);
		return FAILURE;
	}

	FREE_ME(csDate);
DEBUGLOG(("process end\n"));
	return SUCCESS;

}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}
