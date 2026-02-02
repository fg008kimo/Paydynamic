
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
    "ypy_dsp_report.pc"
};


static unsigned int sqlctx = 11309499;


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
Init Version                                       2013/07/03              Virginia Yun
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
#include "utilitys.h"
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"
#include "ypy_dsp_report.h"


#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define	PD_MY_DELIMITOR	","
#define	PD_FILE_DELIMITOR ","

#define PD_DATE_DELIMITOR "/"
#define PD_TIME_DELIMITOR ":"

#define PD_MY_TOEKN '"'

#define	PD_CHAR		0x0D

char    cDebug='Y';

char    cs_inputfile[PD_MAX_FILE_LEN + 1];
char    cs_outputfile[PD_MAX_FILE_LEN + 1];
int parse_arg(int argc,char **argv);
int verify_file(FILE *fin,FILE *fout);
int process_file(FILE *fin);

void FormatTxnDate(char *csInDate, char *csOutDate);

int batch_init(int argc, char* argv[])
{

    if (argc < 3) {
    	printf("usage: -f input file -o ouputfile\n");
        return FAILURE;
    }
    else
        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	FILE	*fin,*fout;
	int	iRet;
	
	iRet = parse_arg(argc,argv);

	if (iRet != SUCCESS) {
    		printf("*usage: -f input file -o ouputfile\n");
		return (iRet);
	}

	fin = fopen(cs_inputfile,"r");
	if (fin == NULL) {
DEBUGLOG(("Error Opening file = [%s]\n",cs_inputfile));
		return FAILURE;
	}

	fout = fopen(cs_outputfile,"w");
	if (fout == NULL) {
DEBUGLOG(("Error Opefing file = [%s] for writ\n",cs_outputfile));
		fclose(fin);
		return FAILURE;
	}

DEBUGLOG(("Opened file = [%s] for writ\n",cs_outputfile));

	iRet = verify_file(fin,fout);
	fclose(fin);
	fclose(fout);

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
        strcpy(cs_outputfile,"");
                        
        while ((c = getopt(argc,argv,"f:o:")) != EOF) {
                switch (c) {
                        case 'f':
                                strcpy(cs_inputfile, optarg);
                                break;
                        case 'o':
                                strcpy(cs_outputfile, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }       
        
DEBUGLOG(("[%s][%s]\n",cs_inputfile,cs_outputfile));
        if (!strcmp(cs_inputfile,"") ||!strcmp(cs_outputfile,""))
                return FAILURE;
                
        return SUCCESS; 
}               


int verify_file(FILE *fin,FILE *fout)
{
        int     iRet = FAILURE;
	int	iCount = 0 ;
	char    csList[IMPORT_MAX_FIELD][IMPORT_FIELD_LEN];
	char    csHeader[IMPORT_MAX_FIELD][IMPORT_FIELD_LEN];
        char    cs_input_buf[PD_MAX_BUFFER +1];;
	char	*p;

	double	dFee = 0.0;

	char	csDate[PD_MAX_BUFFER + 1];


/*Header*/
/* 1st line */
	fgets(cs_input_buf,PD_MAX_BUFFER,fin);
DEBUGLOG(("%s\n",cs_input_buf));

        p = mystrtok(cs_input_buf,PD_MY_DELIMITOR);
        if (p == NULL)
                return FAILURE;
        strcpy(csHeader[iCount],p);
        iCount++;

        while ( (p = mystrtok(NULL,PD_MY_DELIMITOR)) != NULL) {
                strcpy(csHeader[iCount],p);
                iCount++;
        }

/*Content*/
        while (fgets(cs_input_buf,PD_MAX_BUFFER, fin) != NULL) {

		dFee = 0.0;

		memset(csList, 0, sizeof(csList));

        	if (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A)
                        cs_input_buf[strlen(cs_input_buf) - 1] = '\0';
		strcpy(cs_input_buf,TrimAllChar((const unsigned char*)cs_input_buf,strlen(cs_input_buf),PD_CHAR));
DEBUGLOG(("%s\n",cs_input_buf));
                iCount = 0;

                p = mystrtok(cs_input_buf,PD_FILE_DELIMITOR);
                if (p == NULL)
                        return FAILURE;
		strcpy(csList[iCount],TrimAllChar((const unsigned char *)p,strlen(p),PD_MY_TOEKN));
        	//strcpy(csList[iCount],p);
                iCount++;

                while ( (p = mystrtok(NULL,PD_FILE_DELIMITOR)) != NULL) {
			strcpy(csList[iCount],TrimAllChar((const unsigned char *)p,strlen(p),PD_MY_TOEKN));
        		//strcpy(csList[iCount],p);
                        iCount++;
                }

DEBUGLOG(("TXN_SEQ=[%s]\n",csList[IDX_TXN_SEQ]));
//DEBUGLOG(("TID=[%s]\n",csList[IDX_TID]));
DEBUGLOG(("TXN_AMOUNT=[%s]\n",csList[IDX_TXN_AMOUNT]));
DEBUGLOG(("SERVICE_FEE=[%s]\n",csList[IDX_SERVICE_FEE]));
DEBUGLOG(("TXN_DATE=[%s]\n",csList[IDX_TXN_DATE]));

		memset(csDate, 0, sizeof(csDate));
		FormatTxnDate(csList[IDX_TXN_DATE], csDate);


/* Field #0 txn_seq */
                fprintf(fout,"%.*s%s",(int)strlen(csList[IDX_TXN_SEQ]),csList[IDX_TXN_SEQ],PD_MY_DELIMITOR);


/* Field #1 tid */
                fprintf(fout,"%s",PD_MY_DELIMITOR);

/* Field #2 bank_bill_no */
                fprintf(fout,"%s",PD_MY_DELIMITOR);


/* Field #3 txn_amount */
                fprintf(fout,"%.*s%s",(int)strlen(csList[IDX_TXN_AMOUNT]),csList[IDX_TXN_AMOUNT],PD_MY_DELIMITOR);


/* Field #4 service_fee */
		dFee = 0.0;
		sscanf(csList[IDX_SERVICE_FEE],"%lf",&dFee);
                fprintf(fout,"%.2f%s",dFee,PD_MY_DELIMITOR);

/* Field #5 status */

                fprintf(fout,"%s",PD_MY_DELIMITOR);


/* Field #6 txn_date*/
                fprintf(fout,"%s", csDate);

		fprintf(fout,"\n");

		iRet = SUCCESS;
        }


	return iRet;
}


void FormatTxnDate(char *csInDate, char *csOutDate)
{
        char *tokenptr;
        char *dateptr;

        char  cs_date_buf[PD_MAX_BUFFER +1];
        char  cs_time_buf[PD_MAX_BUFFER +1];
        int   iCnt = 0;

        int   csDateList[IMPORT_MAX_FIELD];
        char  cs_buf[PD_MAX_BUFFER+1];

        memset(cs_date_buf, 0, sizeof(cs_date_buf));
        memset(cs_time_buf, 0, sizeof(cs_time_buf));

        memset(csDateList, 0, sizeof(csDateList));

        tokenptr = mystrtok(csInDate, " ");
        strcpy(cs_date_buf, tokenptr);

        while ( (tokenptr = mystrtok(NULL, " ")) != NULL) {
                strcpy(cs_time_buf, tokenptr);
        }

        dateptr = mystrtok(cs_date_buf, PD_DATE_DELIMITOR);
        csDateList[iCnt] = atoi(dateptr);

        while ( (dateptr = mystrtok(NULL,PD_DATE_DELIMITOR)) != NULL) {
                iCnt ++;
                csDateList[iCnt] = atoi(dateptr);
        }

        memset(cs_buf, 0, sizeof(cs_buf));
        sprintf(cs_buf, "%04d%02d%02d%s00", csDateList[IDX_YEAR],csDateList[IDX_MONTH],csDateList[IDX_DAY], cs_time_buf);


        sprintf(csOutDate, deleteCharacters(cs_buf, ":"));

}
