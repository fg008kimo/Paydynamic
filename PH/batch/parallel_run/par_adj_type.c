
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
           char  filnam[16];
};
static struct sqlcxp sqlfpn =
{
    15,
    "par_adj_type.pc"
};


static unsigned int sqlctx = 2516579;


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
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/06/27              Virginia Yun
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include "../batchcommon.h"
#include "common.h"
#include "utilitys.h"
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"
#include "par_adj_type.h"
#include "ObjPtr.h"


#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define	PD_MY_DELIMITOR	","
#define	PD_MY_TOKEN	'"'

#define	PD_CHAR		0x0D

OBJPTR(DB);
OBJPTR(Txn);
OBJPTR(Channel);

char    cDebug='Y';


char    cs_inputfile[PD_MAX_FILE_LEN + 1];

int parse_arg(int argc,char **argv);
int verify_file(FILE *fin, hash_t *hContext, hash_t *hRequest, hash_t *hResponse);
int process_txn(char csInList[][IMPORT_FIELD_LEN], hash_t *hContext, hash_t *hRequest, hash_t *hResponse);

int batch_init(int argc, char* argv[])
{

    if (argc < 1) {
    	printf("usage: -f input file\n");
        return FAILURE;
    }
    else
        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	FILE	*fin;
	int	iRet;

        hash_t          *hContext, *hRequest, *hResponse;

        hContext = (hash_t *)malloc(sizeof(hash_t));
        hRequest = (hash_t *)malloc(sizeof(hash_t));
        hResponse= (hash_t *)malloc(sizeof(hash_t));

        hash_init(hContext,   0);
        hash_init(hRequest,  0);
        hash_init(hResponse, 0);

	
	iRet = parse_arg(argc,argv);

	if (iRet != SUCCESS) {
    		printf("*usage: -f input file\n");
		return (iRet);
	}

	fin = fopen(cs_inputfile,"r");
	if (fin == NULL) {
DEBUGLOG(("Error Opening file = [%s]\n",cs_inputfile));
		return FAILURE;
	}

	ChannelObjPtr = CreateObj(ChannelPtr, "MGTChannel","UpdateContext");
	iRet = (unsigned long)((*ChannelObjPtr)(hContext));

	if (iRet == PD_OK) {
		iRet = verify_file(fin, hContext, hRequest, hResponse);	
	} else {
DEBUGLOG(("Error UpdateContext\n"));
	}


	fclose(fin);

	hash_destroy(hContext);
	hash_destroy(hRequest);
	hash_destroy(hResponse);

	FREE_ME(hContext);
	FREE_ME(hRequest);
	FREE_ME(hResponse);

	return iRet;

}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


                        
int parse_arg(int argc,char **argv)
{               
        char    c;
        strcpy(cs_inputfile,"");
                        
        while ((c = getopt(argc,argv,"f:")) != EOF) {
                switch (c) {
                        case 'f':
                                strcpy(cs_inputfile, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }       
        
DEBUGLOG(("[%s]\n",cs_inputfile));
        if (!strcmp(cs_inputfile,""))
                return FAILURE;
                
        return SUCCESS; 
}               


int verify_file(FILE *fin, hash_t *hContext, hash_t *hRequest, hash_t *hResponse)
{
        int     iRet = FAILURE;

	int	iCount;
        char    cs_input_buf[PD_MAX_BUFFER +1]; /*read buffer*/
	char	*p;
	char    csList[IMPORT_MAX_FIELD][IMPORT_FIELD_LEN];

	int	iRowCnt = 0;


/* Header */    
        iCount = 0;
	iRowCnt = 0;


        fgets(cs_input_buf,PD_MAX_BUFFER,fin);
        if (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A || cs_input_buf[strlen(cs_input_buf) - 1] == 0x10)
               cs_input_buf[strlen(cs_input_buf) - 1] = '\0';
	strcpy(cs_input_buf,TrimAllChar((const unsigned char*)cs_input_buf,strlen(cs_input_buf),PD_CHAR));
	iRowCnt++;

/* End of Header */

        while (fgets(cs_input_buf,PD_MAX_BUFFER, fin) != NULL) {
		iRowCnt++;

        	if (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A)
                        cs_input_buf[strlen(cs_input_buf) - 1] = '\0';
		strcpy(cs_input_buf,TrimAllChar((const unsigned char*)cs_input_buf,strlen(cs_input_buf),PD_CHAR));
DEBUGLOG(("%s\n",cs_input_buf));

                iCount = 0;

                p = mystrtok(cs_input_buf,PD_MY_DELIMITOR);
                if (p == NULL)
                        return FAILURE;

		strcpy(csList[iCount],TrimAllChar((const unsigned char*)p, strlen(p), PD_MY_TOKEN));
                iCount++;

                while ( (p = mystrtok(NULL,PD_MY_DELIMITOR)) != NULL) {
			strcpy(csList[iCount],TrimAllChar((const unsigned char*)p, strlen(p), PD_MY_TOKEN));
                        iCount++;
                }

DEBUGLOG((">>>>>>>>>> File Line[%d] <<<<<<<<<< \n",iRowCnt));

		iRet=process_txn(csList, hContext, hRequest, hResponse);

		if (iRet != SUCCESS) {
			break;
		}	

        }


	return iRet;
}

int process_txn(char csInList[][IMPORT_FIELD_LEN], hash_t *hContext, hash_t *hRequest, hash_t *hResponse)
{
	int iRet = SUCCESS;
	int iIntError;

	char	csDesc[PD_ADJ_TYPE_DESC_LEN + 1];


DEBUGLOG(("PARTY_TYPE=[%s]\n",csInList[PAR_IDX_PARTY_TYPE]));
DEBUGLOG(("DC_IND=[%s]\n",csInList[PAR_IDX_DC_IND]));
DEBUGLOG(("PLATFORM=[%s]\n",csInList[PAR_IDX_PLATFORM]));
DEBUGLOG(("DESC=[%s]\n",csInList[PAR_IDX_DESC]));
DEBUGLOG(("DUAL_CONTROL=[%s]\n",csInList[PAR_IDX_DUAL_CONTROL]));
DEBUGLOG(("FEE_TYPE=[%s]\n",csInList[PAR_IDX_FEE_TYPE]));
DEBUGLOG(("APPLY_FEE=[%s]\n",csInList[PAR_IDX_APPLY_FEE]));
DEBUGLOG(("VOIDABLE=[%s]\n",csInList[PAR_IDX_VOIDABLE]));


	PutField_CString(hRequest, "party_type", csInList[PAR_IDX_PARTY_TYPE]);
	PutField_CString(hRequest, "dc_ind", csInList[PAR_IDX_DC_IND]);

	memset(csDesc, 0, sizeof(csDesc));	
	sprintf(csDesc, "%s%s", csInList[PAR_IDX_PLATFORM], csInList[PAR_IDX_DESC]);
	PutField_CString(hRequest, "desc", csDesc);

	PutField_CString(hRequest, "dual_control", csInList[PAR_IDX_DUAL_CONTROL]);
	PutField_CString(hRequest, "fee_type", csInList[PAR_IDX_FEE_TYPE]);
	PutField_CString(hRequest, "disabled", "0");
	PutField_CString(hRequest, "add_user", "SYSTEM");
	
	PutField_CString(hRequest, "action", "A");
	PutField_CString(hRequest, "apply_fee", csInList[PAR_IDX_APPLY_FEE]);
	//PutField_CString(hRequest, "voidable", csInList[PAR_IDX_VOIDABLE]);



DEBUGLOG(("Calling TxnMgtByUsATD::Authorize\n"));
	TxnObjPtr = CreateObj(TxnPtr,"TxnMgtByUsATD","Authorize");
	iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);

	if (iRet == PD_OK) {
		if (GetField_Int(hContext, "internal_error", &iIntError)) {
DEBUGLOG(("Calling TxnMgtByUsATD::Authorize Return internal_error [%d]\n", iIntError));
			iRet = FAILURE;
		}
	}


DEBUGLOG(("RETURN: par_adj_type iRet [%d]\n", iRet));

	return iRet;
}
