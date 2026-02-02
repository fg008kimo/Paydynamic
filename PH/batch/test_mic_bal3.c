
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
           char  filnam[17];
};
static struct sqlcxp sqlfpn =
{
    16,
    "test_mic_bal3.pc"
};


static unsigned int sqlctx = 5255443;


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

Change Description                            Change Date     Change By
------------------------------------------    ------------    --------------
Init Version                                  2020/02/26      Michael Chow
*/


#include <stdio.h>
#include <string.h>
#include <limits.h>
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
#include "ObjPtr.h"
#include "myrecordset.h"
#include "math.h"
#include "dbutility.h"


#define PD_FILE_DELIMITER	","


OBJPTR(DB);

static char cDebug = 'Y';
char *csDetailField[14] = {"Bank Account Provider", "Bank Account Nature", "Bank Name", "Bank Account Number", "Owner Name", "Province", "City", "Branch Name", "Initial Balance", "SMS Statement Enable", "Registered Mobile Number", "Apply Deposit Cost", "Merchant Short Name", "Bank Account Short Name"};


int parse_arg(int argc,char **argv);

int process_data(); 
					

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}

int batch_proc(int argc, char* argv[])
{
	int iRet;
	char    cs_input_buf[2048];
	char    csTmpBuf[2048];
	char    *csHeader = NULL;
	int i=0;
	FILE	*fin = NULL;
	fin = fopen("/nfs/dev/acct_file/2020/202006/20200602/raw/PFI0000000000000786", "r");
	fgets(cs_input_buf, sizeof(cs_input_buf), fin);
DEBUGLOG(("cs_input_buf:%s\n", cs_input_buf));
	if (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A) cs_input_buf[strlen(cs_input_buf) - 1] = '\0';
	if (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0D) cs_input_buf[strlen(cs_input_buf) - 1] = '\0';
	if(!strcmp(cs_input_buf,"")) {
DEBUGLOG(("Authorize() Empty header \n"));
	}
	strcpy(csTmpBuf, cs_input_buf);
	csHeader = mystrtok(csTmpBuf, PD_FILE_DELIMITER);
	/*if(csHeader == NULL) {
DEBUGLOG(("Authorize() Empty header \n"));
		return 0;
	}*/
	while (i<9) {
DEBUGLOG(("header = [%s]\n",csHeader));
		if(csHeader == NULL || strcmp(csHeader, csDetailField[i]) != 0)
		{
DEBUGLOG(("Authorize() Invalid header \n"));
			if(csHeader == NULL) {
DEBUGLOG(("Authorize() NULL \n"));
			}
		}
		csHeader = mystrtok(NULL, PD_FILE_DELIMITER);
		i++;
	}
	//iRet = process_data();

	return 0;
}

int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


int isNumericV2(const char *str) 
{
    while(*str != '.')
    {
        printf("checkV2:%d\r\n", *str);
        if(*str < '0' || *str > '9')
            return 0;
        str++;
    }
    return 1;
}

int isNumeric(const char *str) 
{
    while(*str != '\0')
    {
        printf("check:%d\r\n", *str);
        if(*str < '0' || *str > '9')
            return 0;
        str++;
    }
    return 1;
}


int process_data()
{               


   int left,right;
   int ret;
   int len=0;
   int integer=INT_MAX,deciaml=INT_MAX;
   //int deciaml=INT_MAX;
   //long integer=INT_MAX;
   printf("INT_MAX:%d\n\r", integer);
   char str_integer[20];
   char str_deciaml[20];
   char *csField = {"12231.250000"};
   char *p = (char*)strchr(csField, '.');
   if(p != NULL){
        len=strlen(p+1);
        printf("len:%d\n\r", len);
        printf("p+1:%c\n\r", *(p+1));
        if(len > 2) return 0;
        
        if(csField[0] != '-')
        {
            ret = isNumericV2(csField);
            printf("V2:%d\n\r", ret);
            if (ret == 0) return ret;
            ret = isNumeric(p+1);
            if (ret == 0) return ret;
        }
        else
        {
            ret = isNumericV2(&csField[1]);
            printf("V2:%d\n\r", ret);
            if (ret == 0) return ret;
            ret = isNumeric(p+1);
            if (ret == 0) return ret;
        }
        sscanf(csField, "%d.%d", &integer, &deciaml);
        //sscanf(csField, "%ld.%d", &integer, &deciaml);
        //sprintf(str_deciaml, "%d", deciaml);
        sprintf(str_deciaml, "%d", deciaml);
        printf("Left digits: %d\n\r",integer);
        //printf("Left digits: %ld\n\r",integer);
        printf("Right digits: %d\n\r",deciaml);
        //printf("Right digits: %d\n\r",deciaml);
        printf("dec:%s\n\r",str_deciaml);
        ret = isNumeric(str_deciaml);
        printf("ret:%d\n\r",ret);
        if(ret == 1)
            return (deciaml < 100) ? 1 : 0;
        else
            return 0;
   }
   else{
       if(csField[0] == '-')
       {
            printf("check neg\n\r");
            return (isNumeric(&csField[1]) == 1) ? 1 :0;
       }
       else
       {
            printf("not check neg\n\r");
            return (isNumeric(csField) == 1) ? 1 :0;
       }
   }

}


int parse_arg(int argc,char **argv)
{

	return SUCCESS;
}

