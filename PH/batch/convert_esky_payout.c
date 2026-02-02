
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
    "convert_esky_payout.pc"
};


static unsigned int sqlctx = 306750507;


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
Init Version                                       2011/01/12              LokMan Chow
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
#include "convert_esky_payout.h"
#include "langconvert.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

//#define	PD_TAB_DELIMITOR 0x09
#define	PD_TAB_DELIMITOR "	"
#define	PD_MY_DELIMITOR	 ","
#define	PD_MY_FL_TOEKN	 '"'
#define PD_DEFAULT_INPUTCODING  "UTF-8"
#define PD_DEFAULT_OUTPUTCODING  "UTF-8"
#define PD_CODING_LEN	10
#define	PD_CHAR		0x0D

char    cDebug;

char    cs_inputfile[PD_MAX_FILE_LEN + 1];
char    cs_outputfile[PD_MAX_FILE_LEN + 1];
char    cs_inputcoding[PD_CODING_LEN + 1];
char    cs_outputcoding[PD_CODING_LEN + 1];
int parse_arg(int argc,char **argv);
int verify_file(FILE *fin,FILE *fout);
int process_file(FILE *fin);

int batch_init(int argc, char* argv[])
{

    if (argc < 4) {
    	printf("usage: -f input file -o ouputfile -i input coding -c output coding\n");
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
    		printf("*usage: -f input file -o ouputfile -i input coding -c output coding\n");
		return (iRet);
	}

	fin = fopen(cs_inputfile,"r");
	if (fin == NULL) {
DEBUGLOG(("Error Opening file = [%s]\n",cs_inputfile));
		return FAILURE;
	}

	fout = fopen(cs_outputfile,"w");
	if (fout == NULL) {
DEBUGLOG(("Error Opefing file = [%s] for write\n",cs_outputfile));
		fclose(fin);
		return FAILURE;
	}

DEBUGLOG(("Opened file = [%s] for write\n",cs_outputfile));

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
        strcpy(cs_outputcoding,"");
        strcpy(cs_inputcoding,"");
                        
        while ((c = getopt(argc,argv,"f:o:i:c:")) != EOF) {
                switch (c) {
                        case 'f':
                                strcpy(cs_inputfile, optarg);
                                break;
                        case 'o':
                                strcpy(cs_outputfile, optarg);
                                break;
                        case 'i':
                                strcpy(cs_inputcoding, optarg);
                                break;
                        case 'c':
                                strcpy(cs_outputcoding, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }       
        
        if (!strcmp(cs_inputfile,"") ||!strcmp(cs_outputfile,""))
                return FAILURE;

	if (!strcmp(cs_inputcoding,""))
		strcpy(cs_inputcoding,PD_DEFAULT_INPUTCODING);

	if (!strcmp(cs_outputcoding,""))
		strcpy(cs_outputcoding,PD_DEFAULT_OUTPUTCODING);
                
DEBUGLOG(("[%s][%s][%s->%s]\n",cs_inputfile,cs_outputfile,cs_inputcoding,cs_outputcoding));
        return SUCCESS; 
}               


int verify_file(FILE *fin,FILE *fout)
{
        int     iRet = FAILURE;
	int	iCount;
	int	iRec, a;
	char    csList[IMPORT_MAX_FIELD][IMPORT_FIELD_LEN];
        char    cs_input_buf[PD_MAX_BUFFER +1];;
	char	*p;
	double dAmt;

/* Header */    
        iCount = 0;
	for(a=0;a<2;a++){
        	fgets(cs_input_buf,PD_MAX_BUFFER,fin);
        	if (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A || cs_input_buf[strlen(cs_input_buf) - 1] == 0x10)
               		cs_input_buf[strlen(cs_input_buf) - 1] = '\0';
//		strcpy(cs_input_buf,TrimAllChar(cs_input_buf,strlen(cs_input_buf),PD_CHAR));
DEBUGLOG(("%s\n",cs_input_buf));
	}


	iRec=1;	
        while (fgets(cs_input_buf,PD_MAX_BUFFER, fin) != NULL) {

        	if (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A)
                        cs_input_buf[strlen(cs_input_buf) - 1] = '\0';
		strcpy(cs_input_buf,TrimAllChar((const unsigned char *)cs_input_buf,strlen(cs_input_buf),PD_CHAR));
DEBUGLOG(("%s\n",cs_input_buf));
                iCount = 0;

                p = mystrtok(cs_input_buf,PD_TAB_DELIMITOR);
                if (p == NULL)
                        return FAILURE;
                strcpy(csList[iCount],TrimAllChar((const unsigned char *)p,strlen(p),PD_MY_FL_TOEKN));
                iCount++;

                while ( (p = mystrtok(NULL,PD_TAB_DELIMITOR)) != NULL) {
                        strcpy(csList[iCount],TrimAllChar((const unsigned char *)p,strlen(p),PD_MY_FL_TOEKN));
                        iCount++;
                }
/*
DEBUGLOG(("TXN_NUM=[%s]\n",csList[IDX_TXN_NUM]));
DEBUGLOG(("NAME=[%s]\n",csList[IDX_NAME]));
DEBUGLOG(("ID_NUM=[%s]\n",csList[IDX_ID_NUM]));
DEBUGLOG(("MOBILE=[%s]\n",csList[IDX_MOBILE]));
DEBUGLOG(("ACC_NUM=[%s]\n",csList[IDX_ACC_NUM]));
DEBUGLOG(("BANK_NAME=[%s]\n",csList[IDX_BANK_NAME]));
DEBUGLOG(("BRANCH=[%s]\n",csList[IDX_BRANCH]));
DEBUGLOG(("TXN_AMOUNT=[%s]\n",csList[IDX_TXN_AMOUNT]));
*/	
//iRec=1;	

// Field #0 seq_num
//                fprintf(fout,"%d%s",iRec,PD_MY_DELIMITOR);

/* Field #1 txn_num */
		fprintf(fout,"%.*s%s",(int)strlen(csList[IDX_TXN_NUM]),csList[IDX_TXN_NUM],PD_MY_DELIMITOR);

/* Field #2 name */
                fprintf(fout,"%.*s%s",(int)strlen(csList[IDX_NAME]),code_convert(cs_inputcoding,cs_outputcoding,csList[IDX_NAME]),PD_MY_DELIMITOR);
                //fprintf(fout,"%.*s%s",(int)strlen(csList[IDX_NAME]),csList[IDX_NAME],PD_MY_DELIMITOR);

/* Field #3 id_num */
	  	//fprintf(fout,"%.*s%s",(int)strlen(csList[IDX_ID_NUM]),code_convert(cs_inputcoding,cs_outputcoding,csList[IDX_ID_NUM]),PD_MY_DELIMITOR);
	  	fprintf(fout,"%.*s%s",(int)strlen(csList[IDX_ID_NUM]),csList[IDX_ID_NUM],PD_MY_DELIMITOR);

/* Field #4 mobile */
                //fprintf(fout,"%.*s%s",(int)strlen(csList[IDX_MOBILE]),code_convert(cs_inputcoding,cs_outputcoding,csList[IDX_MOBILE]),PD_MY_DELIMITOR);
                fprintf(fout,"%.*s%s",(int)strlen(csList[IDX_MOBILE]),csList[IDX_MOBILE],PD_MY_DELIMITOR);

/* Field #5 bank_name */
                fprintf(fout,"%.*s%s",(int)strlen(csList[IDX_BANK_NAME]),code_convert(cs_inputcoding,cs_outputcoding,csList[IDX_BANK_NAME]),PD_MY_DELIMITOR);
                //fprintf(fout,"%.*s%s",(int)strlen(csList[IDX_BANK_NAME]),csList[IDX_BANK_NAME],PD_MY_DELIMITOR);

/* Field #6 province */
		fprintf(fout,"%.*s",(int)strlen(csList[IDX_PROVINCE]),code_convert(cs_inputcoding,cs_outputcoding,csList[IDX_PROVINCE]));

/* Field #7 city */
		fprintf(fout,"%.*s",(int)strlen(csList[IDX_CITY]),code_convert(cs_inputcoding,cs_outputcoding,csList[IDX_CITY]));

/* Field #8 branch */
                fprintf(fout,"%.*s%s",(int)strlen(csList[IDX_BRANCH]),code_convert(cs_inputcoding,cs_outputcoding,csList[IDX_BRANCH]),PD_MY_DELIMITOR);
                //fprintf(fout,"%.*s%s",(int)strlen(csList[IDX_BRANCH]),csList[IDX_BRANCH],PD_MY_DELIMITOR);

/* Field #9 acc_num */
                //fprintf(fout,"%.*s%s",(int)strlen(csList[IDX_ACC_NUM]),code_convert(cs_inputcoding,cs_outputcoding,csList[IDX_ACC_NUM]),PD_MY_DELIMITOR);
                fprintf(fout,"%.*s%s",(int)strlen(csList[IDX_ACC_NUM]),csList[IDX_ACC_NUM],PD_MY_DELIMITOR);

/* Field #8 txn_amount */
		if(is_numeric(csList[IDX_TXN_AMOUNT])==PD_TRUE)
			fprintf(fout,"%.*s",(int)strlen(csList[IDX_TXN_AMOUNT]),csList[IDX_TXN_AMOUNT]);

		else{
			sscanf(csList[IDX_TXN_AMOUNT],"%lf",&dAmt);
			fprintf(fout,"%.2f",dAmt);
		}

                fprintf(fout,"\n");
		memset(cs_input_buf,0,sizeof(cs_input_buf));
		iRet = SUCCESS;
		iRec ++;
        }


	return iRet;
}

