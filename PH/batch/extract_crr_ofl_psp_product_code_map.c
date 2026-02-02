
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
           char  filnam[40];
};
static struct sqlcxp sqlfpn =
{
    39,
    "extract_crr_ofl_psp_product_code_map.pc"
};


static unsigned int sqlctx = 72684043;


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
   unsigned char  *sqhstv[3];
   unsigned long  sqhstl[3];
            int   sqhsts[3];
            short *sqindv[3];
            int   sqinds[3];
   unsigned long  sqharm[3];
   unsigned long  *sqharc[3];
   unsigned short  sqadto[3];
   unsigned short  sqtdso[3];
} sqlstm = {12,3};

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

 static char *sq0001 = 
"SELECT pm_psp_id , pm_business_type , pm_product_code FROM crr_psp_product_\
code_map WHERE pm_disabled = 0 AND pm_update_timestamp >= TO_DATE ( :b0 , 'YY\
YYMMDD' ) ORDER BY pm_psp_id            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,192,0,9,134,0,2049,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,13,136,0,0,3,0,0,1,0,2,9,0,0,2,1,0,0,2,9,0,0,
51,0,0,1,0,0,15,173,0,0,0,0,0,1,0,
66,0,0,1,0,0,15,181,0,0,0,0,0,1,0,
81,0,0,2,0,0,32,182,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version					   2015/03/10		   Dirk Wong
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
#include "ObjPtr.h"


#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define	PD_MY_DELIMITOR	','

OBJPTR(BO);

char    cs_date[PD_DATE_LEN + 1];
char	cs_mode[PD_DESC_LEN + 1];
char    cDebug = 'Y';

int parse_arg(int argc,char **argv);
int process_data(const char* csTxnDate, FILE *fp);

int batch_init(int argc, char* argv[])
{

    if (argc < 3) {
        printf("usage:  -d Date -m Mode(FULL/DELTA)\n");
        return FAILURE;
    }
    else
        return SUCCESS;
}




int batch_proc(int argc, char* argv[])
{
        int     iRet;
        char    cs_outfile_name[PD_MAX_FILE_LEN + 1];
        FILE    *fp;

	iRet = parse_arg(argc,argv);
               
        if (iRet != SUCCESS) {
		printf("usage:  -d Date -m Mode(FULL/DELTA)\n");
                return (iRet);
        }

        char    cs_yyyy[PD_YYYY_LEN+1];
        char    cs_yyyymm[PD_YYYY_LEN+PD_MM_LEN+1];
        strncpy(cs_yyyy,cs_date,4);
        strncpy(cs_yyyymm,cs_date,6);

        sprintf(cs_outfile_name, "%s/%s/%s/%s/crr_ofl_psp_product_code_map_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
        
        fp = fopen(cs_outfile_name,"w");
        if (fp == NULL) {
DEBUGLOG(("batch_proc:unable to open [%s]\n",cs_outfile_name));
                return FAILURE;
        }
        
        iRet = process_data(cs_date,fp);
        fclose(fp);
	return iRet;


}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}




int process_data(const char* csTxnDate, FILE *fp)
{               
        int     iRet = SUCCESS;
	char	csTmp[PD_TMP_BUF_LEN+1];

	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_date;


		/* varchar	v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		char	v_business_type;
		/* varchar	v_product_code[PD_PRODUCT_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_product_code;


		short	ind_psp_id = -1;
		short	ind_business_type = -1;
		short	ind_product_code = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_date.len = strlen((char*)cs_date);
	memcpy(hv_date.arr,cs_date,hv_date.len);

	if (!strcmp(cs_mode,"FULL")) {
		memcpy(hv_date.arr,"19900101",hv_date.len);
	};

	/* EXEC SQL DECLARE c_cursor_getpsplist CURSOR FOR
		SELECT	pm_psp_id,
			pm_business_type,
			pm_product_code
		FROM	crr_psp_product_code_map
		WHERE	pm_disabled = 0
		  AND	pm_update_timestamp >= TO_DATE(:hv_date,'YYYYMMDD')
		ORDER BY pm_psp_id; */ 


	/* EXEC SQL OPEN c_cursor_getpsplist; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0001;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_date;
 sqlstm.sqhstl[0] = (unsigned long )10;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto sql_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getpsplist
		INTO	:v_psp_id:ind_psp_id,
			:v_business_type:ind_business_type,
			:v_product_code:ind_product_code; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 3;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )24;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_psp_id;
  sqlstm.sqhstl[0] = (unsigned long )13;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_psp_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_business_type;
  sqlstm.sqhstl[1] = (unsigned long )1;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_business_type;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_product_code;
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_product_code;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto sql_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

/* Field #0 psp_id */
		if (ind_psp_id >= 0) {
			sprintf(csTmp,"%.*s",v_psp_id.len,v_psp_id.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		}
		else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #1 business_type */
		if (ind_business_type >= 0) {
			fprintf(fp,"%c%c",v_business_type,PD_MY_DELIMITOR);
		}
		else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #2 record_date */
		fprintf(fp,"%s%c",cs_date,PD_MY_DELIMITOR);

/* Field #3 product_code */
		if (ind_product_code >= 0) {
			sprintf(csTmp,"%.*s",v_product_code.len,v_product_code.arr);
			fprintf(fp,"%s",csTmp);
		}

/* new line */
		fprintf(fp,"\n");

 	} while (PD_TRUE);
	/* EXEC SQL CLOSE c_cursor_getpsplist; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )51;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto sql_error;
}



        return iRet;

sql_error:
DEBUGLOG(("extract_crr_ofl_psp_product_map error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getpsplist; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 3;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )66;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 3;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )81;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int parse_arg(int argc,char **argv)
{
        char    c;
        strcpy(cs_date,"");
	strcpy(cs_mode,"");

        while ((c = getopt(argc,argv,"d:m:")) != EOF) {
                switch (c) {
                        case 'd':
                                strcpy(cs_date, optarg);
                                break;
			case 'm':
				strcpy(cs_mode, optarg);
				break;
                        default:
                                return FAILURE;
                }
        }

        if ((!strcmp(cs_date,"")) || (!strcmp(cs_mode,"")))
                return FAILURE;

        return SUCCESS;
}

