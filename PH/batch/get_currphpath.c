
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
    "get_currphpath.pc"
};


static unsigned int sqlctx = 9682235;


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
   unsigned char  *sqhstv[2];
   unsigned long  sqhstl[2];
            int   sqhsts[2];
            short *sqindv[2];
            int   sqinds[2];
   unsigned long  sqharm[2];
   unsigned long  *sqharc[2];
   unsigned short  sqadto[2];
   unsigned short  sqtdso[2];
} sqlstm = {12,2};

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
5,0,0,1,61,0,4,84,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
28,0,0,2,61,0,4,120,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
};


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


#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

int CreateCurrReportPath(unsigned char* csDate, unsigned char* csPspName, unsigned char* csCountry, unsigned char* csCurrentPath);
int GetCountry(unsigned char* csPspId, unsigned char* csCountry);
int GetPspName(unsigned char* csPspId, unsigned char* csPspName);

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}

int batch_proc(int argc, char* argv[])
{
        char    cs_outfile_name[PD_MAX_FILE_LEN + 1];
        char    cs_country[PD_COUNTRY_LEN + 1];
        char    cs_psp_name[PD_PSP_NAME_LEN + 1];

	if(argc==3){
		if(GetCountry((unsigned char*)argv[2],(unsigned char*)cs_country) != SUCCESS)
			return FAILURE;

		if(GetPspName((unsigned char*)argv[2],(unsigned char*)cs_psp_name) != SUCCESS)
			return FAILURE;

		if (CreateCurrReportPath((unsigned char*)argv[1],
					(unsigned char*)cs_psp_name,
					(unsigned char*)cs_country,
					(unsigned char*)cs_outfile_name) != SUCCESS)
			return FAILURE;
	}

	else{
		//if (CreateCurrReportPath(NULL,cs_outfile_name) != SUCCESS) 
                	return FAILURE;
	}
	
	printf("%s",cs_outfile_name);

	return SUCCESS;


}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


int GetCountry(unsigned char* csPspId, unsigned char* csCountry)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO getcountry_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;


                /* varchar         v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

                short           ind_country= -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_psp_id.len = strlen((const char*)csPspId);
        memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);

	/* EXEC SQL SELECT country 
		INTO :v_country:ind_country
		FROM psp_country
		WHERE psp_id = :hv_psp_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select country into :b0:b1  from psp_country where psp_id=:\
b2";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_country;
 sqlstm.sqhstl[0] = (unsigned long )5;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_country;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto getcountry_error;
}



	if (ind_country >= 0) {
		v_country.arr[v_country.len] = '\0';
                strcpy((char*)csCountry,(const char*)v_country.arr);
		return SUCCESS;
	}
	else
	{
		return FAILURE;
	}

getcountry_error:
	return FAILURE;

}

int GetPspName(unsigned char* csPspId, unsigned char* csPspName)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO getname_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;


                /* varchar         v_psp_name[PD_PSP_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_name;

                short           ind_psp_name= -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_psp_id.len = strlen((const char*)csPspId);
        memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);

	/* EXEC SQL SELECT psp_name
		INTO :v_psp_name:ind_psp_name
		FROM psp_detail
		WHERE psp_id = :hv_psp_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select psp_name into :b0:b1  from psp_detail where psp_id=:\
b2";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )28;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_psp_name;
 sqlstm.sqhstl[0] = (unsigned long )53;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_psp_name;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto getname_error;
}



	if (ind_psp_name >= 0) {
		v_psp_name.arr[v_psp_name.len] = '\0';
                strcpy((char*)csPspName,(const char*)v_psp_name.arr);
		return SUCCESS;
	}
	else
	{
		return FAILURE;
	}

getname_error:
	return FAILURE;
}

int CreateCurrReportPath(unsigned char* csDate, unsigned char* csPspName, unsigned char* csCountry, unsigned char* csCurrentPath)
{
        char    csHostDate[PD_DATE_LEN + 1];
        char    cs_outfile_name[PD_MAX_FILE_LEN + 1];

	if(strcmp((const char *)csDate,"N")){
		strcpy(csHostDate,(const char *)csDate);
		csHostDate[PD_DATE_LEN]='\0';
	}
	else{
        	if (GetCurrHostPostingDate((unsigned char *)csHostDate) != SUCCESS)
                	return FAILURE;
	}

/* create report path */
        sprintf((char *)csCurrentPath, "%s", getenv("REPORT_HOME"));
        sprintf(cs_outfile_name, "mkdir %s >/dev/null 2>&1", csCurrentPath);
        system(cs_outfile_name);

        sprintf((char *)csCurrentPath, "%s/%.*s", getenv("REPORT_HOME"),PD_YYYY_LEN,csHostDate);
        sprintf(cs_outfile_name, "mkdir %s >/dev/null 2>&1", csCurrentPath);
        system(cs_outfile_name);

        sprintf((char *)csCurrentPath, "%s/%.*s/%.*s", getenv("REPORT_HOME"),PD_YYYY_LEN,csHostDate,PD_YYYYMM_LEN,csHostDate);
        sprintf(cs_outfile_name, "mkdir %s >/dev/null 2>&1", csCurrentPath);
        system(cs_outfile_name);

        sprintf((char *)csCurrentPath, "%s/%.*s/%.*s/%s", getenv("REPORT_HOME"),PD_YYYY_LEN,csHostDate,PD_YYYYMM_LEN,csHostDate,csHostDate);
        sprintf(cs_outfile_name, "mkdir %s >/dev/null 2>&1", csCurrentPath);
        system(cs_outfile_name);

        sprintf((char *)csCurrentPath, "%s/%.*s/%.*s/%s/%s", getenv("REPORT_HOME"),PD_YYYY_LEN,csHostDate,PD_YYYYMM_LEN,csHostDate,csHostDate,csCountry);
        sprintf(cs_outfile_name, "mkdir %s >/dev/null 2>&1", csCurrentPath);
        system(cs_outfile_name);

        sprintf((char *)csCurrentPath, "%s/%.*s/%.*s/%s/%s/%s", getenv("REPORT_HOME"),PD_YYYY_LEN,csHostDate,PD_YYYYMM_LEN,csHostDate,csHostDate,csCountry,csPspName);
        sprintf(cs_outfile_name, "mkdir %s >/dev/null 2>&1", csCurrentPath);
        system(cs_outfile_name);

/* create report data folder if not created */
        sprintf(cs_outfile_name, "mkdir %s >/dev/null 2>&1", getenv("REPORT_DATA"));
       system(cs_outfile_name);

        return SUCCESS;
}
