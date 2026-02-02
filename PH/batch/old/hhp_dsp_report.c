
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
    "hhp_dsp_report.pc"
};


static unsigned int sqlctx = 9785787;


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
Init Version                                       2011/03/09              LokMan Chow
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
#include "hhp_dsp_report.h"


#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define	PD_MY_DELIMITOR	","
#define	PD_FILE_DELIMITOR "	"
#define	PD_MY_QS_TOEKN	'['
#define	PD_MY_QE_TOEKN	']'

#define	PD_CHAR		0x0D

char    cDebug;

char    cs_inputfile[PD_MAX_FILE_LEN + 1];
char    cs_outputfile[PD_MAX_FILE_LEN + 1];
char    cs_date[PD_MAX_FILE_LEN + 1];
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
	
	sscanf(cs_inputfile,"%*[^_]_%[^.tx]",cs_date);
printf("tmp date=[%s]\n",cs_date);

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
	char    csList[IMPORT_MAX_FIELD][IMPORT_FIELD_LEN];
        char    cs_input_buf[PD_MAX_BUFFER +1];;
	char	*p;
	char	csTmp[PD_MAX_BUFFER +1];
	double	dAmt;

/* Header */    
        iCount = 0;
        fgets(cs_input_buf,PD_MAX_BUFFER,fin);
        if (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A || cs_input_buf[strlen(cs_input_buf) - 1] == 0x10)
               cs_input_buf[strlen(cs_input_buf) - 1] = '\0';
	strcpy(cs_input_buf,TrimAllChar((const unsigned char*)cs_input_buf,strlen(cs_input_buf),PD_CHAR));

DEBUGLOG(("%s\n",cs_input_buf));
/*
        p = mystrtok(cs_input_buf,PD_MY_DELIMITOR);
        if (p == NULL)
                return FAILURE;
        strcpy(csList[iCount],p);
        iCount++;

        while ( (p = mystrtok(NULL,PD_MY_DELIMITOR)) != NULL) {
                strcpy(csList[iCount],p);
                iCount++;
        }

*/

        while (fgets(cs_input_buf,PD_MAX_BUFFER, fin) != NULL) {

        	if (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A)
                        cs_input_buf[strlen(cs_input_buf) - 1] = '\0';
		strcpy(cs_input_buf,TrimAllChar((const unsigned char*)cs_input_buf,strlen(cs_input_buf),PD_CHAR));
DEBUGLOG(("%s\n",cs_input_buf));
                iCount = 0;

                p = mystrtok(cs_input_buf,PD_FILE_DELIMITOR);
                if (p == NULL)
                        return FAILURE;
                strcpy(csTmp,TrimAllChar((const unsigned char*)p,strlen(p),PD_MY_QS_TOEKN));
                strcpy(csList[iCount],TrimAllChar((const unsigned char*)csTmp,strlen(csTmp),PD_MY_QE_TOEKN));
                iCount++;

                while ( (p = mystrtok(NULL,PD_FILE_DELIMITOR)) != NULL) {
                        strcpy(csTmp,TrimAllChar((const unsigned char*)p,strlen(p),PD_MY_QS_TOEKN));
                        strcpy(csList[iCount],TrimAllChar((const unsigned char*)csTmp,strlen(csTmp),PD_MY_QE_TOEKN));
                        iCount++;
                }

DEBUGLOG(("TXN_SEQ=[%s]\n",csList[IDX_TXN_SEQ]));
DEBUGLOG(("TID=[%s]\n",csList[IDX_TID]));
DEBUGLOG(("TXN_AMOUNT=[%s]\n",csList[IDX_TXN_AMOUNT]));
//DEBUGLOG(("TXN_DATE=[%s]\n",csList[IDX_TXN_DATE]));
DEBUGLOG(("STATUS=[%s]\n",csList[IDX_TXN_STATUS]));
	

/* Field #1 tid */
                fprintf(fout,"%.*s%s",(int)strlen(csList[IDX_TID]),csList[IDX_TID],PD_MY_DELIMITOR);


/* Field #0 txn_seq */
                fprintf(fout,"%.*s%s",(int)strlen(csList[IDX_TXN_SEQ]),csList[IDX_TXN_SEQ],PD_MY_DELIMITOR);


/* Field #2 txn_amount */
		sscanf(csList[IDX_TXN_AMOUNT],"%lf",&dAmt);
                fprintf(fout,"%.2f%s",dAmt,PD_MY_DELIMITOR);


/* Field #4 status */
		fprintf(fout,"%.*s%s",(int)strlen(csList[IDX_TXN_STATUS]),csList[IDX_TXN_STATUS],PD_MY_DELIMITOR);

// Field #5 txn_date 
		fprintf(fout,"%.*s-%.*s-%.*s",PD_YYYY_LEN,&cs_date[strlen(cs_date)-PD_DATE_LEN],PD_MM_LEN,&cs_date[strlen(cs_date)-PD_YYYY_LEN],PD_DD_LEN,&cs_date[strlen(cs_date)-PD_MM_LEN]);

                fprintf(fout,"\n");


		iRet = SUCCESS;
		//}
        }


	return iRet;
}

