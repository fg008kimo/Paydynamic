
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
           char  filnam[21];
};
static struct sqlcxp sqlfpn =
{
    20,
    "check_abc_convert.pc"
};


static unsigned int sqlctx = 72562555;


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
PDProTech (c)2018. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2018/11/02              [WMC]
Add fsync to process file			   2018/11/05		   [WMC]
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
#include "math.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char cDebug = 'Y';

char csProcessFile[PD_MAX_FILE_LEN + 1];

int parse_arg(int argc, char **argv);
int strlen_content(char *s);


int batch_init(int argc, char *argv[])
{
	if (argc < 3) {
		printf("usage: -o process_file\n");
		return FAILURE;
	}
	else
		return SUCCESS;
}


int batch_proc(int argc, char *argv[])
{
	int iRet = SUCCESS;
	
	int iCheckLine = 4;
	int iTotalLine = 0, iSBlankLine = 0, iEBlankLine = 0; 
	int iLineCnt = 0;
	char cs_input_buf[PD_TMP_MSG_BUF_LEN];
	FILE *fproc;
	
	memset(cs_input_buf, 0, sizeof(cs_input_buf));

DEBUGLOG(("batch_proc: start\n"));

	iRet = parse_arg(argc, argv);

	if (iRet != SUCCESS) {
		printf("*usage: -o process_file\n");
		return iRet;
	}

DEBUGLOG(("process_file = [%s]\n", csProcessFile));

	fproc = fopen(csProcessFile, "r");
	if (fproc == NULL) {
DEBUGLOG(("Error opening file = [%s]\n", csProcessFile));
ERRLOG("check_abc_convert: batch_proc: Error opening file = [%s]\n", csProcessFile);
		return FAILURE;
	} else {

		// Calculate Total/Starting Blank/Ending Blank Line
		while (fgets(cs_input_buf, sizeof(cs_input_buf), fproc) != NULL) {
                 	if (strlen_content(cs_input_buf) == 0) {
                              	iSBlankLine++;
                      	} else {
                              	break;
                     	}
              	}
		rewind(fproc);
               	while (fgets(cs_input_buf, sizeof(cs_input_buf), fproc) != NULL) {
                   	if (strlen_content(cs_input_buf) == 0) {
                            	iEBlankLine++;
                     	} else {
                              	iEBlankLine = 0;
                    	}
			iTotalLine++;
              	}
DEBUGLOG(("total line = [%d], starting blank line = [%d], ending blank line = [%d]\n", iTotalLine, iSBlankLine, iEBlankLine));

		// Debug Title and Record Line
		rewind(fproc);
               	while (fgets(cs_input_buf, sizeof(cs_input_buf), fproc) != NULL) {

                      	iLineCnt++;

			if (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A) cs_input_buf[strlen(cs_input_buf) - 1] = '\0';
                       	if (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0D) cs_input_buf[strlen(cs_input_buf) - 1] = '\0';

                     	if ((iLineCnt > iSBlankLine) && (iLineCnt <= (iSBlankLine + iCheckLine))) {
DEBUGLOG(("line %03d [%s]\n", iLineCnt, cs_input_buf));
			}
             	}
	}

	fsync(fileno(fproc));
	fflush(fproc);
	
	fclose(fproc);

DEBUGLOG(("batch_proc: iRet = [%d]\n", iRet));
	return SUCCESS;
}


int batch_terminate(int argc, char *argv[])
{
	return SUCCESS;
}


int parse_arg(int argc, char **argv)
{
	char c;
	strcpy(csProcessFile, "");

	while ((c = getopt(argc, argv, "o:")) != EOF) {
		switch (c) {
			case 'o':
				strcpy(csProcessFile, optarg);
				break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(csProcessFile, ""))
		return FAILURE;

	return SUCCESS;
}


int strlen_content(char *s)
{
        int j = 0;
        while (*s) {
                if ((*s & 0xc0) == 0x00 || (*s & 0xc0) == 0x40) {
                        if ((*s >= '0' && *s <= '9') ||
                            (*s >= 'A' && *s <= 'Z') ||
                            (*s >= 'a' && *s <= 'z')) {
                                j++;
                        }
                } else if ((*s & 0xc0) == 0xc0) {
                        j++;
                }
                s++;
        }
        return j;
}
