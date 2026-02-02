
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
           char  filnam[13];
};
static struct sqlcxp sqlfpn =
{
    12,
    "test_vgt2.pc"
};


static unsigned int sqlctx = 328779;


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
PDProTech (c)2019. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.
 
Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2019/08/12              Virginia Yun
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include "batchcommon.h"
#include "common.h"
#include "utilitys.h"
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"
#include "ObjPtr.h"
#include "internal.h"
/* #include "test_vgt2.h"*/
#define __USE_XOPEN
#include <time.h>

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char cs_start_datetime[PD_TMP_BUF_LEN+1];
char cs_end_datetime[PD_TMP_BUF_LEN+1];

static char    cDebug='Y';

OBJPTR(DB);
OBJPTR(BO);

int parse_arg(int argc,char **argv);

//int GetNotifyList(const hash_t *hRls, recordset_t *myRec);

int batch_init(int argc, char* argv[])
{
        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int     iRet = SUCCESS;

/*

	recordset_t *rRecordset;
        rRecordset = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordset, 0);

	hash_t	*hMyHash = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hMyHash, 0);

	char	cPartyType = 'G';

*/

	char	csTmp[PD_MAX_FILE_LEN];
	FILE	*fin = NULL;
	
	int	dPre_DP = 0;
	int	dPost_DP = 0;

	int	dTmpRtn = 0;

	char	csField [PD_MAX_FILE_LEN];
	char	csTmpField [PD_MAX_FILE_LEN];


//DEBUGLOG(("batch_proc: Start!\n"));

	memset(csTmp, 0, sizeof(csTmp));

	memset(csField, 0, sizeof(csField));
	memset(csTmpField, 0, sizeof(csTmpField));

	strcpy(csField, "   王德隆");
	//strcpy(csField, "   王德隆");


char *pTrim;
short    org_len;

        pTrim = (char *) csField;
        org_len = strlen(csField);

printf("pTrim = [%s]\n", pTrim);
printf("org_len = [%d]\n", org_len);

	if (pTrim != NULL) {
		while (org_len > 0 && (*pTrim == ' ' || *pTrim == 0x00 || (int)*pTrim == 160)) {
				pTrim++;
				org_len--;
		}

		printf("test1... [%d]\n", (int)*pTrim);

	}

	printf("final.... [%s]\n", pTrim);
exit;




/*
	sprintf(csTmp, "北京农村商业银行abc北京农村商业银行");

	printf("csTmp=[%s] len=[%d]\n", csTmp, (int)strlen(csTmp));
*/

	

	strcpy(csTmpField, TrimAll((const unsigned char*)csField, strlen(csField)));

	printf("csTmpField = [%s]\n", csTmpField);


/*

	sprintf(csTmp, "99999999.99");	


	dTmpRtn = sscanf(csTmp, "%d.%d", &dPre_DP, &dPost_DP);
	printf("org [%s] Rtn [%d] Pre [%d] Post [%d]\n", csTmp, dTmpRtn, dPre_DP, dPost_DP);	


	if (sscanf(csTmp, "%d.%d", &dPre_DP, &dPost_DP) == 2) {
		printf("Pre [%d] Post [%d]\n", dPre_DP, dPost_DP);
	} else { 
		printf("ERROR....\n");
	} ;

	return iRet;

*/






/////////////////////////////////////
/*
	char    cs_input_buf[PD_TMP_MSG_BUF_LEN];
	char	*csField = NULL;
	char    csTmpBuf[PD_TMP_MSG_BUF_LEN];
	char    csTmpField[PD_TMP_MSG_BUF_LEN];

	fin=fopen("/home/phuser/Doc/temp_vg/20200529_PRD220/convertPRD220_sample_file.txt", "r");

	fgets(cs_input_buf, sizeof(cs_input_buf), fin);

	printf("cs_input_buf [%s]\n", cs_input_buf);


	while (fgets(cs_input_buf, sizeof(cs_input_buf), fin) != NULL) {
		if (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A) {
			cs_input_buf[strlen(cs_input_buf) - 1] = '\0';
		}

                if (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0D) {
			cs_input_buf[strlen(cs_input_buf) - 1] = '\0';
		}

		memset(csTmpBuf, 0, sizeof(csTmpBuf));

		strcpy(csTmpBuf, cs_input_buf);

printf("csTmpBuf [%s]\n", csTmpBuf);

		csField = mystrtok(csTmpBuf, ",");


		while (csField != NULL) {
			memset(csTmpField, 0, sizeof(csTmpField));

			strcpy(csTmpField, TrimAll((const unsigned char*)csField, strlen(csField)));


			int iNonAsciiCnt = 0;
			int iAsciiCnt    = 0;

			int j = 0;

			for (j = 0; j < strlen(csTmpField); j++) {
				if (!isascii (csTmpField[j])) {
					iNonAsciiCnt++;
				} else {
					iAsciiCnt++;
				}
			}
printf("csTmpField [%s] [%d] Ascii [%d] NonAscii [%d]\n", csTmpField, (int)strlen(csTmpField), iAsciiCnt, iNonAsciiCnt/3);





			int   iUTF8Len = 0;

			iUTF8Len = strlen_utf8(&csTmpField);

printf(">>> csTmpField [%s] [%d]\n", csTmpField, iUTF8Len);




			csField = mystrtok(NULL, ",");
			
		}

		
	}
	
	fclose(fin);	

*/
/////////////////////////////////////




	//iRet = parse_arg(argc,argv);


	


/*

	if (iRet == SUCCESS) {

		PutField_Char(hMyHash, "party_type", cPartyType);
		PutField_CString(hMyHash, "party_d", "000");
		PutField_CString(hMyHash, "funct", "DEP_TRC_TO_PSP");

		
		iRet = (unsigned long) GetNotifyList(hMyHash, rRecordset);


	}

        hash_destroy(hMyHash);
        FREE_ME(hMyHash);

	RecordSet_Destroy(rRecordset);
        FREE_ME(rRecordset);	
*/



//DEBUGLOG(("batch_proc: iRet = [%d]\n", iRet));


	return iRet;
}


int batch_terminate(int argc, char* argv[])
{
        return SUCCESS;
}


int parse_arg(int argc, char **argv)
{
/*
	char	c;
	strcpy(cs_start_datetime,"");
	strcpy(cs_end_datetime,"");

	if (argc < 4) {
DEBUGLOG(("argc = [%d]\n",argc));
		return FAILURE;
	}

	while ((c = getopt(argc,argv,"s:e:")) != EOF) {
		switch (c) {
			case 's':
                                strcpy(cs_start_datetime, optarg);
                                break;
			case 'e':
                                strcpy(cs_end_datetime, optarg);
                                break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(cs_start_datetime,"") || !strcmp(cs_end_datetime,""))
		return FAILURE;
*/


        return SUCCESS;
}




int strlen_utf8(char *s)
{
        int j = 0;
        while (*s) {
                if ((*s & 0xc0) != 0x80) j++;
                s++;
        }
        return j;
}

