
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
    "deposit_req_fallback.pc"
};


static unsigned int sqlctx = 597742787;


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
#include "common.h"
#include "utilitys.h"
#include "curl/curl.h"
#include "ObjPtr.h"
#include "myrecordset.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define MY_PARSE_TOKEN            "&"
#define MY_PARSE_FIELD_TOKEN      "="
#define MY_OUT_TOKEN              ","

OBJPTR(DB);
OBJPTR(Txn);

char cDebug = 'Y';

char csDepositInFile[PD_UPLOAD_FILENAME_LEN + 1];
char csDepositOutFile[PD_UPLOAD_FILENAME_LEN + 1];

int parse_arg(int argc, char **argv);
int ReadFile();
int BreakDown(hash_t *hMyHash, char *inMsg);
int FormOutput(hash_t *hMyHash, char *csOutMsg);


int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int iRet = SUCCESS;

	iRet = parse_arg(argc, argv);

	if (iRet != SUCCESS) {
		printf("Usage: deposit_req_fallback.exec -s in_file_name -d out_file_name\n");
		return FAILURE;
	}


	iRet = ReadFile();

	return iRet;
}

int	ReadFile() {

	int iRet = SUCCESS;

        FILE    *fin  = NULL;
	FILE	*fout = NULL;

	char    cs_input_buf[PD_TMP_MSG_BUF_LEN *2];
	int     iCurrLine = 0;
	char    csTmpBuf[PD_TMP_MSG_BUF_LEN *2];
	char	csOutputBuf[PD_TMP_MSG_BUF_LEN];

	hash_t	*hOutputHash;

        hOutputHash = (hash_t*)  malloc (sizeof(hash_t));

printf(">> csDepositInFile  = [%s]\n", csDepositInFile);
printf(">> csDepositOutFile = [%s]\n", csDepositOutFile);

	fin  = fopen(csDepositInFile, "r");
	fout = fopen(csDepositOutFile, "w");

	if ((fin == NULL) || (fout == NULL)) {
		iRet = FAILURE;
printf(">> open file error [%s] [%s]\n", csDepositInFile, csDepositOutFile);
	} else {

		while (iRet == PD_OK && fgets(cs_input_buf, sizeof(cs_input_buf), fin) != NULL) {
        		hash_init(hOutputHash,0);
			iCurrLine++;

			if ((cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A) || (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0D)) {
				cs_input_buf[strlen(cs_input_buf) - 1] = '\0';
			}
			
			if (!strcmp(cs_input_buf, "")) {
				continue;
			}

			csTmpBuf[0]='\0';
			strcpy(csTmpBuf, cs_input_buf+1);
//printf(">> %s\n", csTmpBuf);

			iRet = BreakDown(hOutputHash, csTmpBuf);

			if (iRet == SUCCESS) {
				memset(csOutputBuf, 0, sizeof(csOutputBuf));
				iRet = FormOutput(hOutputHash, csOutputBuf);

			}

			if (iRet == SUCCESS) {
//printf(">> %s\n", csOutputBuf);
				fprintf(fout,"%s",csOutputBuf);
				fprintf(fout,"%c",0x0A);
			}

			hash_destroy(hOutputHash);
		}


	}

printf(">> Number of Record = [%d]\n", iCurrLine);

	FREE_ME(hOutputHash);

	fclose(fin);
	fclose(fout);


	return iRet;

}

int BreakDown(hash_t *hMyHash, char *inMsg)
{
	int	iRet = SUCCESS;

	char	*csPtr;
	char    *csTag;
	char	*csTmp;
	
	hash_t	*hRec;

        hRec = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hRec,0);

        if (Str2Cls(hRec,(char*)inMsg,MY_PARSE_TOKEN, MY_PARSE_FIELD_TOKEN) == PD_OK) {
                csTag = (char*) malloc (PD_TMP_BUF_LEN +1);
                csTmp = (char*) malloc (PD_TMP_BUF_LEN +1);

/* merchant_ref */
		if (GetField_CString(hRec, "mer_ref", &csPtr)) {
			PutField_CString(hMyHash, "merchant_ref", csPtr);
		}
/* ccy */
		if (GetField_CString(hRec, "ccy", &csPtr)) {
			PutField_CString(hMyHash, "txn_ccy", csPtr);
		}

/* transaction_amount */
		if (GetField_CString(hRec,"txn_amt",&csPtr)) {
                        PutField_CString(hMyHash,"txn_amt",csPtr);
                }
	
/* bank_acct_num */
                if (GetField_CString(hRec,"bank_acct_num",&csPtr)) {
                        PutField_CString(hMyHash,"bank_acct_num",csPtr);
		}

/* deposit_bank */
		if (GetField_CString(hRec,"deposit_bank",&csPtr)) {
                        PutField_CString(hMyHash,"deposit_bank",csPtr);
		}

/* deposit_flow */
		if (GetField_CString(hRec,"deposit_flow",&csPtr)) {
                        PutField_CString(hMyHash,"deposit_flow",csPtr);
                }

/* cust_deposit_datetime */
		if (GetField_CString(hRec,"cust_deposit_date",&csPtr)) {
                        PutField_CString(hMyHash,"cust_deposit_datetime",csPtr);
		}

/* deposit_ref */
		if (GetField_CString(hRec,"deposit_ref",&csPtr)) {
			PutField_CString(hMyHash,"deposit_ref",csPtr);
		}
	}
	else {
printf(">>BreakDown Error\n");
		iRet = FAILURE;
	}

	return iRet;
}

int FormOutput(hash_t *hMyHash, char *csOutMsg)
{
	int	iRet = SUCCESS;

	char	*csPtr;

/* merchant_ref */
	if (GetField_CString(hMyHash, "merchant_ref", &csPtr)) {
		strcat(csOutMsg,csPtr);
	}
	strcat(csOutMsg, MY_OUT_TOKEN);

/* ccy */
	if (GetField_CString(hMyHash, "txn_ccy", &csPtr)) {
		strcat(csOutMsg,csPtr);
	}
	strcat(csOutMsg, MY_OUT_TOKEN);

/* transaction_amount */
	if (GetField_CString(hMyHash, "txn_amt", &csPtr)) {
		strcat(csOutMsg,csPtr);
	}
	strcat(csOutMsg, MY_OUT_TOKEN);

/* bank_acct_num */
	if (GetField_CString(hMyHash, "bank_acct_num", &csPtr)) {
		strcat(csOutMsg,csPtr);
	}
	strcat(csOutMsg, MY_OUT_TOKEN);

/* deposit_bank */
	if (GetField_CString(hMyHash, "deposit_bank", &csPtr)) {
		strcat(csOutMsg,csPtr);
	}
	strcat(csOutMsg, MY_OUT_TOKEN);

/* deposit_flow */
	if (GetField_CString(hMyHash, "deposit_flow", &csPtr)) {
		strcat(csOutMsg,csPtr);
	}
	strcat(csOutMsg, MY_OUT_TOKEN);

/* cust_deposit_datetime */
	if (GetField_CString(hMyHash, "cust_deposit_datetime", &csPtr)) {
		strcat(csOutMsg,csPtr);
	}
	strcat(csOutMsg, MY_OUT_TOKEN);

/* deposit_ref */
	if (GetField_CString(hMyHash, "deposit_ref", &csPtr)) {
		strcat(csOutMsg,csPtr);
	}

	return iRet;
}



int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


int parse_arg(int argc, char **argv)
{
	char c;
	strcpy(csDepositInFile, ""); 
	strcpy(csDepositOutFile, ""); 

	while ((c = getopt(argc, argv, "s:d:")) != EOF) {
		switch (c) {
			case 's':
				strcpy(csDepositInFile, optarg);
				break;
			case 'd':
				strcpy(csDepositOutFile, optarg);
				break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(csDepositInFile, "") || !strcmp(csDepositOutFile, "")) {
		return FAILURE;
	}

	return SUCCESS;
}
