
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
           char  filnam[23];
};
static struct sqlcxp sqlfpn =
{
    22,
    "merchant_dsp_report.pc"
};


static unsigned int sqlctx = 313414075;


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
Init Version                                       2010/10/25              Cody Chan
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
#include "merchant_dsp_report.h"


#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define	PD_MY_DELIMITOR	","
#define	PD_MY_FL_TOEKN	'"'
#define	PD_MATCH_TOEKN	"\t" //0x09
#define	PD_CHAR		0x0D

char    cDebug;

char    cs_inputfile[PD_MAX_FILE_LEN + 1];
char    cs_outputfile[PD_MAX_FILE_LEN + 1];
int parse_arg(int argc,char **argv);
int verify_file(FILE *fin,FILE *fout);
int process_file(FILE *fin);

int batch_init(int argc, char* argv[])
{

    if (argc < 2) {
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
	int	iCount;
	char    csList[IMPORT_MAX_FILE][IMPORT_FIELD_LEN];
        char    cs_input_buf[PD_MAX_BUFFER +1];;
	char	*p;
	char	csCcy[PD_CCY_ID_LEN+1];
	char	*csCountry;

/* Header */    
/*        iCount = 0;
        fgets(cs_input_buf,PD_MAX_BUFFER,fin);
        if (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A || cs_input_buf[strlen(cs_input_buf) - 1] == 0x10)
               cs_input_buf[strlen(cs_input_buf) - 1] = '\0';
	strcpy(cs_input_buf,TrimAllChar((const unsigned char *)cs_input_buf,strlen(cs_input_buf),PD_CHAR));

DEBUGLOG(("%s\n",cs_input_buf));
*/
        while (fgets(cs_input_buf,PD_MAX_BUFFER, fin) != NULL) {

        	if (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A)
                        cs_input_buf[strlen(cs_input_buf) - 1] = '\0';
		strcpy(cs_input_buf,TrimAllChar((const unsigned char *)cs_input_buf,strlen(cs_input_buf),PD_CHAR));
DEBUGLOG(("%s\n",cs_input_buf));
                iCount = 0;

                p = mystrtok(cs_input_buf,(char*)PD_MY_DELIMITOR);
                if (p == NULL)
                        return FAILURE;
                strcpy(csList[iCount],TrimAllChar((const unsigned char *)p,strlen(p),PD_MY_FL_TOEKN));
                iCount++;

                while ( (p = mystrtok(NULL,(char*)PD_MY_DELIMITOR)) != NULL) {
                        strcpy(csList[iCount],TrimAllChar((const unsigned char *)p,strlen(p),PD_MY_FL_TOEKN));
                        iCount++;
                }
DEBUGLOG(("MERCH_REF=[%s]\n",csList[IDX_MERCH_REF]));
DEBUGLOG(("TXN_DATE=[%s]\n",csList[IDX_TXN_DATE]));
DEBUGLOG(("TXN_AMOUNT=[%s]\n",csList[IDX_TXN_AMOUNT]));
DEBUGLOG(("STATUS=[%s]\n",csList[IDX_STATUS]));
DEBUGLOG(("MERCHANT_ID=[%s]\n",csList[IDX_MERCHANT_ID]));
		
		strcpy(csCcy,csList[IDX_TXN_AMOUNT]);
		csCcy[PD_CCY_ID_LEN]='\0';
		if(!strcmp(csCcy,PD_CCY_ISO_TWD))
			csCountry = strdup(PD_TAIWAN);
		else
			csCountry = strdup(PD_CHINA);

/* Field #0 merch_ref */
                fprintf(fout,"%.*s%s",(int)strlen(csList[IDX_MERCH_REF]),csList[IDX_MERCH_REF],PD_MY_DELIMITOR);


/* Field #1 txn_date */
                fprintf(fout,"%.*s%s",(int)strlen(csList[IDX_TXN_DATE]),csList[IDX_TXN_DATE],PD_MY_DELIMITOR);
                //fprintf(fout,"%.*s%.*s%.*s%s",PD_MONTH_LEN+1,csList[IDX_TXN_DATE],PD_DAY_LEN+1,&csList[IDX_TXN_DATE][PD_MONTH_LEN+1],PD_YEAR_LEN,&csList[IDX_TXN_DATE][PD_MONTH_LEN+1+PD_DAY_LEN+1],PD_MY_DELIMITOR);

/*status*/
		fprintf(fout,"%.*s%s",(int)strlen(csList[IDX_STATUS]),csList[IDX_STATUS],PD_MY_DELIMITOR);


/* Field #2 txn_amount */
                fprintf(fout,"%.*s%s",(int)(strlen(csList[IDX_TXN_AMOUNT])),csList[IDX_TXN_AMOUNT],PD_MY_DELIMITOR);

/*Field #3 NULL*/
		fprintf(fout," %s",PD_MY_DELIMITOR);

/*Field #4 merchant_id*/
		fprintf(fout,"%.*s%s",(int)(strlen(csList[IDX_MERCHANT_ID])),csList[IDX_MERCHANT_ID],PD_MY_DELIMITOR);

/*Field #5 country*/
		fprintf(fout,"%.*s",(int)(strlen(csCountry)),csCountry);

                fprintf(fout,"\n");
		memset(cs_input_buf,0,sizeof(cs_input_buf));

		FREE_ME(csCountry);
        }

	return iRet;
}

