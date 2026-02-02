
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
    "check_exchange_rate.pc"
};


static unsigned int sqlctx = 290637859;


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
   unsigned char  *sqhstv[5];
   unsigned long  sqhstl[5];
            int   sqhsts[5];
            short *sqindv[5];
            int   sqinds[5];
   unsigned long  sqharm[5];
   unsigned long  *sqharc[5];
   unsigned short  sqadto[5];
   unsigned short  sqtdso[5];
} sqlstm = {12,5};

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

 static char *sq0003 = 
"select currency_id from currency where disabled = 0            ";

 static char *sq0004 = 
"SELECT ex_rate , to_char ( ex_effect_date , 'YYYY-MM-DD HH24:MI:SS' ) as ex\
_effect_date FROM exchange_rate WHERE ex_from_ccy_id = :b0:b1 AND ex_to_ccy_i\
d = :b2:b3 AND ex_effect_date = ( SELECT max ( ex_effect_date ) FROM exchange\
_rate WHERE ex_from_ccy_id = :b0:b5 AND ex_to_ccy_id = :b2:b7 AND ex_effect_d\
ate < NVL ( to_date ( :b8:b9 , 'YYYY-MM-DD HH24:MI:SS' ) , sysdate ) )       \
     ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,64,0,4,222,0,0,1,0,0,1,0,2,3,0,0,
24,0,0,2,92,0,4,261,0,0,1,0,0,1,0,2,3,0,0,
43,0,0,3,63,0,9,385,0,2049,0,0,0,1,0,
58,0,0,3,0,0,13,387,0,0,1,0,0,1,0,2,9,0,0,
77,0,0,3,0,0,15,412,0,0,0,0,0,1,0,
92,0,0,3,0,0,15,422,0,0,0,0,0,1,0,
107,0,0,4,388,0,9,614,0,2049,5,5,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
142,0,0,4,0,0,13,616,0,0,2,0,0,1,0,2,4,0,0,2,9,0,0,
165,0,0,4,0,0,15,639,0,0,0,0,0,1,0,
180,0,0,4,0,0,15,647,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/06/06              Virginia Yun
Support email alert template                       2014/07/14              Dirk Wong
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

#include "tpllib.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

OBJPTR(DB);
char    cDebug;

int check_job_processed(tpl_t *tpl);
int check_num_of_currency(int *iNumOfCurrency);
int check_num_of_update_ex_rate(int *iNumOfExRate);
int get_currency_list(recordset_t *rSetA, recordset_t *rSetB);
int check_ex_rate_value(tpl_t *tpl);
int check_ex_value(char *csFromCcy, char *csToCcy, char *csDate_1, char *csDate_2, double *dValue_1, double *dValue_2, tpl_t *tpl);
int get_ex_value(char *csFromCcyId, char *csToCcyId, char *csDateTime, hash_t *hRec);

//int	iTitle = 0;
int	tpl_create=0;
int	title_create=0;
int	iTplType;
char	*content;
char	csTag[PD_TAG_LEN+1];

int parse_arg(int argc,char **argv);

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int     iRet = parse_arg(argc,argv);

	if (iRet != SUCCESS) {
		iTplType = 0;
	}

	tpl_create=0;
	tpl_t *tpl = tpl_alloc();

	hash_t *hContext;
	hContext = (hash_t*)malloc(sizeof(hash_t));
	hash_init(hContext,0);

	if (tpl_load(tpl, "/home/php3dev/src/batch/check_exchange_rate.tpl") != TPL_OK)
	{
		(void)puts("Error loading template file!");
		return 0;
	}

	iRet = check_job_processed(tpl);

	iRet = check_ex_rate_value(tpl);

	if (tpl_create > 0)
	{
		content = malloc(tpl_length(tpl) + 1);
		tpl_get_content(tpl, content);
		(void)puts(content);
	}
	tpl_free(tpl);


	return iRet;

}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

int parse_arg(int argc,char **argv)
{
	char    c;

	if (argc < 2) {
		return PD_ERR;
	}
	while ((c = getopt(argc,argv,"t:")) != EOF) {
		switch (c) {
			case 't':
				iTplType = atoi(optarg);
				break;
			default:
				return PD_ERR;
		}
	}

	return SUCCESS;
}

int check_job_processed(tpl_t *tpl)
{
	int	iRet = SUCCESS;

	int	iNumOfCurrency = 0;
	int	iNumOfExRate = 0;

	iRet = check_num_of_currency(&iNumOfCurrency);

	if (iRet == SUCCESS) {
		iRet = check_num_of_update_ex_rate(&iNumOfExRate);
	
		if (iRet == SUCCESS) {
DEBUGLOG(("check_exchange_rate:: No. of Ccy Type [%d] , Today Total Created Ex Rate [%d]\n", iNumOfCurrency, iNumOfExRate));
//printf("No. of CCy Type [%d] , Today Total Created Ex Rate [%d]\n", iNumOfCurrency, iNumOfExRate);

			if ((iNumOfCurrency * iNumOfCurrency) != iNumOfExRate) {
DEBUGLOG(("check_exchange_rate:: Unmatch expected no. of record!\n"));
				//printf("UNMATCH expected no. of record!!\n");
				/*
				printf("======================================================================\n");
				printf("[No. of Currency Type		]: %d\n", iNumOfCurrency);
				printf("[Today Created Ex Rate Record	]: %d\n", iNumOfExRate);
				printf("[Result				]: Unmatch Expected no. of record\n");
				printf("======================================================================\n\n");
				*/
			
				/*
				printf("<br>\n"); 
				printf("Check No. of Exchange Record\n"); 
				printf("<table border=\"1\">\n");
				printf("<tr><td><b>No of Currency Type</b></td><td>%d</td></tr>\n", iNumOfCurrency);
				printf("<tr><td><b>Today Created Ex Rate Record</b></td><td>%d</td></tr>\n", iNumOfExRate);
				printf("<tr><td><b>Result</b></td><td><b>**Unmatch Expected no. of record**</b></td></tr>\n");
				printf("</table>\n");
				*/

				tpl_select_section(tpl, "TBL_TS_START");
				sprintf(csTag,"tpl%d",iTplType);
				tpl_set_field_fmt(tpl, "TPL_NUM", "%s", csTag);
				tpl_append_section(tpl);
				tpl_deselect_section(tpl);

				//Print timestamp row
				tpl_select_section(tpl, "TIMESTAMP");
				tpl_set_field_fmt(tpl, "tpl_Timestamp", write_tpl_timestamp());
				tpl_append_section(tpl);
				tpl_deselect_section(tpl);

				tpl_select_section(tpl, "TBL_TS_END");
				tpl_append_section(tpl);
				tpl_deselect_section(tpl);

				tpl_select_section(tpl, "TITLE1");
				tpl_set_field_fmt(tpl, "tpl_title", "%s", "Check No Of Exchange Record");
				tpl_append_section(tpl);
				tpl_deselect_section(tpl);

				tpl_select_section(tpl, "TABLE1_START");
				sprintf(csTag,"tpl%d",iTplType);
				tpl_set_field_fmt(tpl, "TPL_NUM", "%s", csTag);
				tpl_append_section(tpl);
				tpl_deselect_section(tpl);

				tpl_select_section(tpl, "CHK_NO_OF_EXCHANGE_RC");
				tpl_append_section(tpl);
	                        tpl_set_field_int(tpl, "NUM_OF_CCY", iNumOfCurrency);
	                        tpl_set_field_int(tpl, "NUM_OF_EX_RATE", iNumOfCurrency);
				tpl_deselect_section(tpl);

				tpl_select_section(tpl, "TABLE1_END");
				tpl_append_section(tpl);
				tpl_deselect_section(tpl);

				tpl_create = 1;
			}
		}

	}

	return iRet;

}



int check_num_of_currency(int *iNumOfCurrency)
{
	int	iRet = FAILURE;

	/* EXEC SQL WHENEVER SQLERROR GOTO chkcurrency_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int    v_no_of_record;
		short  ind_no_of_record = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("check_exchange_rate:: check_num_of_record\n"));

        /* EXEC SQL
            SELECT COUNT(1) 
              INTO :v_no_of_record:ind_no_of_record
              FROM currency
             WHERE disabled =0; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select COUNT ( 1 ) INTO :b0:b1 FROM currency WHERE d\
isabled = 0 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )5;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_no_of_record;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_no_of_record;
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
        if (sqlca.sqlcode < 0) goto chkcurrency_error;
}



        if (ind_no_of_record >= 0) {

		iRet = SUCCESS;
                *iNumOfCurrency = v_no_of_record;

DEBUGLOG(("check_exchange_rate:: check_num_of_record Total_Record [%d]\n", *iNumOfCurrency));
	}

	return iRet;

chkcurrency_error:
DEBUGLOG(("check_exchange_rate.check_no_of_currency %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("check_exchange_rate.check_num_of_currency FAIL\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;

}

int check_num_of_update_ex_rate(int *iNumOfExRate)
{
	int	iRet = FAILURE;

	/* EXEC SQL WHENEVER SQLERROR GOTO chkexrate_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int    v_no_of_record;
		short  ind_no_of_record = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("check_exchange_rate:: check_num_of_update_ex_rate\n"));

        /* EXEC SQL
		SELECT count(1) 
		INTO :v_no_of_record:ind_no_of_record
		FROM exchange_rate
		WHERE ex_create_date >= trunc(sysdate); */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM exchange_rate WH\
ERE ex_create_date >= trunc ( sysdate ) ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )24;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_no_of_record;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_no_of_record;
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
        if (sqlca.sqlcode < 0) goto chkexrate_error;
}



        if (ind_no_of_record >= 0) {

		iRet = SUCCESS;
                *iNumOfExRate = v_no_of_record;

DEBUGLOG(("check_exchange_rate:: check_num_of_update_ex_rate Total_Record [%d]\n", *iNumOfExRate));
	}

	return iRet;

chkexrate_error:
DEBUGLOG(("check_exchange_rate.check_num_of_update_ex_rate %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("check_exchange_rate.check_num_of_update_ex_rate FAIL\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;

}

int check_ex_rate_value(tpl_t *tpl)
{
	int	iRet = SUCCESS;

        hash_t  *hRec_From;
        hash_t  *hRec_To;
	
	char	*csTmp_From;
	char	*csTmp_To;

	char	*csDate_1 = NULL;
	char	*csDate_2 = NULL;

	double  dValue_1;
	double  dValue_2;

	int	iTmpRet;

        recordset_t     *rRecordSet_From;
        rRecordSet_From = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet_From,0);

        recordset_t     *rRecordSet_To;
        rRecordSet_To = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet_To,0);

	iRet = get_currency_list(rRecordSet_From, rRecordSet_To);

	if (iRet == SUCCESS) {
		hRec_From = RecordSet_GetFirst(rRecordSet_From);
		while (hRec_From) {
			if (GetField_CString(hRec_From, "ccy", &csTmp_From)) {

				hRec_To = RecordSet_GetFirst(rRecordSet_To);
				while (hRec_To) {
					if (GetField_CString(hRec_To, "ccy", &csTmp_To)) {
DEBUGLOG(("==========================================\n"));
DEBUGLOG(("From [%s] To [%s]\n", csTmp_From, csTmp_To));

						if (strcmp(csTmp_From, csTmp_To)) {
DEBUGLOG(("Prepare for check_ex_value\n")); 
							iTmpRet = check_ex_value(csTmp_From, csTmp_To, csDate_1, csDate_2, &dValue_1, &dValue_2, tpl);
						}
                                                else {
DEBUGLOG(("Same Ccy, no need to check\n"));
						}
					}
					hRec_To = RecordSet_GetNext(rRecordSet_To);
				}

			}

			hRec_From = RecordSet_GetNext(rRecordSet_From);
		}

		if (title_create > 0)
		{
			tpl_select_section(tpl, "TABLE2_END");
			tpl_append_section(tpl);
			tpl_deselect_section(tpl);
		}

/*		if (iTitle == 1) {
			printf("</table>\n");
		}*/
	}

	

	RecordSet_Destroy(rRecordSet_From);
	FREE_ME(rRecordSet_From);

	RecordSet_Destroy(rRecordSet_To);
	FREE_ME(rRecordSet_To);

	return iRet;
	

}

int get_currency_list(recordset_t *rSetFrom, recordset_t *rSetTo)
{
	int	iRet = FAILURE;

        hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getcurrencylist_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	v_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ccy;

		short	ind_ccy = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


        /* EXEC SQL DECLARE c_cursor_getcurrencylist CURSOR FOR
		select currency_id
                from   currency
                where  disabled = 0; */ 


	/* EXEC SQL OPEN c_cursor_getcurrencylist; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )43;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getcurrencylist_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getcurrencylist
		INTO 
			:v_ccy:ind_ccy; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 1;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )58;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_ccy;
  sqlstm.sqhstl[0] = (unsigned long )6;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_ccy;
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
  if (sqlca.sqlcode < 0) goto getcurrencylist_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iRet = SUCCESS;

		myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);
		//ccy 
		if (ind_ccy >= 0) {

				v_ccy.arr[v_ccy.len] = '\0';
				PutField_CString(myHash, "ccy", (const char *)v_ccy.arr);
DEBUGLOG(("check_exchange_rate:: get_currency_list ccy [%s]\n", v_ccy.arr));
		}

		RecordSet_Add(rSetFrom, myHash);
		RecordSet_Add(rSetTo, myHash);

	}
	while (PD_TRUE);
	/* EXEC SQL CLOSE c_cursor_getcurrencylist; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )77;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getcurrencylist_error;
}



	return iRet;


getcurrencylist_error:
DEBUGLOG(("check_exchange_rate.get_currency_list %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("check_exchange_rate.get_currency_list FAIL\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getcurrencylist; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )92;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return FAILURE;

}

int check_ex_value(char *csFromCcy, char *csToCcy, char *csDate_1, char *csDate_2, double *dValue_1, double *dValue_2, tpl_t *tpl)
{
	int	iRet = SUCCESS;

	hash_t	*hRec;
	char	csDateTime[PD_DATE_LEN + PD_TIME_LEN + 5 + 1]; // where 5 is the format string
	
	double	dRate1 = 0.0;
	double	dRate2 = 0.0;
	char	*csDate1 = NULL;
	char	*csDate2 = NULL;

	
	hRec = (hash_t*) malloc (sizeof(hash_t));

	memset(csDateTime, 0, sizeof(csDateTime));

	// Get Lastest Rate
	hash_init(hRec,0);
	iRet = get_ex_value(csFromCcy, csToCcy, csDateTime, hRec);
	if (iRet == SUCCESS) {
		if (GetField_Double(hRec, "rate", &dRate1)) {
DEBUGLOG(("check_ex_value::1: rate [%lf]\n", dRate1));
		}
		
		if (GetField_CString(hRec, "rec_date", &csDate1)) {
DEBUGLOG(("check_ex_value::1: rec_date [%s]\n", csDate1));
			strcpy(csDateTime, csDate1);
		}
	}
	hash_destroy(hRec);

	// Get Previous Record which before Lastest
	hash_init(hRec,0);

	iRet = get_ex_value(csFromCcy, csToCcy, csDateTime, hRec);
	if (iRet == SUCCESS) {
		if (GetField_Double(hRec, "rate", &dRate2)) {
DEBUGLOG(("check_ex_value::2: rate [%lf]\n", dRate2));
		}
		
		if (GetField_CString(hRec, "rec_date", &csDate2)) {
DEBUGLOG(("check_ex_value::2: rec_date [%s]\n", csDate2));
		}
	}

DEBUGLOG(("check_ex_value:: final: fr_ccy [%s] to_ccy [%s] rate1 [%lf] rate2 [%lf] date1 [%s] date2 [%s]\n", csFromCcy, csToCcy, dRate1, dRate2, csDate1, csDate2));

	if (dRate1 == dRate2) {
//		if (iTitle == 0) {
			/*
			printf("======================================================================\n");
			printf("Please attention that The following Ex Rate are the same!\n");
			printf("----------------------------------------------------------------------\n");
			*/
/*
			printf("<br>\n");
			printf("Please attention that the following Ex Rate are the same!\n");

			printf("<table border=\"1\">\n");
			printf("<tr align=\"center\"><th>Fr Ccy</th><th>To Ccy</th><th>Effect Date</th><th>Ex Rate</th></tr>\n");

			//iTitle = 1;
*/			
//		}

		if (tpl_create == 0)
		{
			tpl_select_section(tpl, "TBL_TS_START");
			sprintf(csTag,"tpl%d",iTplType);
			tpl_set_field_fmt(tpl, "TPL_NUM", "%s", csTag);
			tpl_append_section(tpl);
			tpl_deselect_section(tpl);

			//Print timestamp row
			tpl_select_section(tpl, "TIMESTAMP");
			tpl_set_field_fmt(tpl, "tpl_Timestamp", write_tpl_timestamp());
			tpl_append_section(tpl);
			tpl_deselect_section(tpl);

			tpl_select_section(tpl, "TBL_TS_END");
			tpl_append_section(tpl);
			tpl_deselect_section(tpl);

			tpl_create = 1;
		}

		if (title_create == 0)
		{
			tpl_select_section(tpl, "TABLE2_START");
			sprintf(csTag,"tpl%d",iTplType);
			tpl_set_field_fmt(tpl, "TPL_NUM", "%s", csTag);
			tpl_append_section(tpl);
			tpl_deselect_section(tpl);

			//print table head
			tpl_select_section(tpl, "SAME_EX_RATE_HEAD");
			tpl_append_section(tpl);
			tpl_deselect_section(tpl);

			title_create = 1;	
		}


DEBUGLOG(("FR CCY [%s] TO CCY [%s] RATE1[%lf] RATE2[%lf] DATE1[%s] DATE2[%s]\n", csFromCcy, csToCcy, dRate1, dRate2, csDate1, csDate2));
//printf("FR CCY [%s] TO CCY [%s] RATE1[%lf] RATE2[%lf] DATE1[%s] DATE2[%s]\n", csFromCcy, csToCcy, dRate1, dRate2, csDate1, csDate2);
			/*
			printf("[Fr Currency	]: [%s]\n", csFromCcy);
			printf("[To Currency	]: [%s]\n", csToCcy);
                        printf("[Effect Date	]: [%s] [%s]\n", csDate2, csDate1);
                        printf("[Ex Rate	]: [%lf]  [%lf]\n", dRate2, dRate1);
			printf("----------------------------------------------------------------------\n");
			*/

		//	printf("<tr><td>%s</td><td>%s</td><td>[%s][%s]</td><td>[%lf][%lf]</td></tr>\n", csFromCcy, csToCcy, csDate2, csDate1, dRate2, dRate1);

			//print table row
			tpl_select_section(tpl, "SAME_EX_RATE_ROW");
			tpl_set_field_fmt(tpl, "FROM_CCY", "%s", csFromCcy);
			tpl_set_field_fmt(tpl, "TO_CCY", "%s", csToCcy);
			tpl_set_field_fmt(tpl, "DATE1", "%s", csDate1);
			tpl_set_field_fmt(tpl, "DATE2", "%s", csDate2);
			tpl_set_field_fmt(tpl, "RATE1", "%lf", dRate1);
			tpl_set_field_fmt(tpl, "RATE2", "%lf", dRate2);
			tpl_append_section(tpl);
			tpl_deselect_section(tpl);
	}


	FREE_ME(hRec);

	return iRet;
}

int get_ex_value(char *csFromCcyId, char *csToCcyId, char *csDateTime, hash_t *hRec)
{
	int	iRet = SUCCESS;

	/* EXEC SQL WHENEVER SQLERROR GOTO getexvalue_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_from_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_from_ccy_id;

                /* varchar         hv_to_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_to_ccy_id;

		/* varchar		hv_date_time[PD_DATE_LEN + PD_TIME_LEN + 5]; */ 
struct { unsigned short len; unsigned char arr[19]; } hv_date_time;


		short		ind_from_ccy_id = -1;
		short		ind_to_ccy_id = -1;
		short		ind_date_time = -1;

                double          v_rate;
		/* varchar		v_rec_date[PD_DATE_LEN + PD_TIME_LEN + 5 + 1]; */ 
struct { unsigned short len; unsigned char arr[20]; } v_rec_date;


		short		ind_rate = -1;
		short		ind_rec_date = -1;
		
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_from_ccy_id.len = strlen(csFromCcyId);
        memcpy(hv_from_ccy_id.arr, csFromCcyId, hv_from_ccy_id.len);
	ind_from_ccy_id = 0;
DEBUGLOG(("get_ex_value: from_ccy_id = [%.*s]\n",hv_from_ccy_id.len,hv_from_ccy_id.arr));

        hv_to_ccy_id.len = strlen(csToCcyId);
        memcpy(hv_to_ccy_id.arr, csToCcyId, hv_to_ccy_id.len);
	ind_to_ccy_id = 0;
DEBUGLOG(("get_ex_value: to_ccy_id = [%.*s]\n",hv_to_ccy_id.len,hv_to_ccy_id.arr));

	if (strlen(csDateTime) > 0) {
        	hv_date_time.len = strlen(csDateTime);
	        memcpy(hv_date_time.arr, csDateTime, hv_date_time.len);
DEBUGLOG(("get_ex_value: date_time = [%.*s]\n",hv_date_time.len,hv_date_time.arr));
		ind_date_time = 0;
	}

        /* EXEC SQL DECLARE c_cursor_getexvalue CURSOR FOR
                SELECT  ex_rate, to_char(ex_effect_date, 'YYYY-MM-DD HH24:MI:SS') as ex_effect_date
                FROM    exchange_rate
                WHERE   ex_from_ccy_id = :hv_from_ccy_id:ind_from_ccy_id
                AND     ex_to_ccy_id = :hv_to_ccy_id:ind_to_ccy_id
                AND     ex_effect_date  = (SELECT max(ex_effect_date)
                                             FROM exchange_rate
                                            WHERE ex_from_ccy_id = :hv_from_ccy_id:ind_from_ccy_id
                                              AND ex_to_ccy_id = :hv_to_ccy_id:ind_to_ccy_id
                                              AND ex_effect_date < NVL(to_date(:hv_date_time:ind_date_time, 'YYYY-MM-DD HH24:MI:SS'), sysdate)
					); */ 


        /* EXEC SQL OPEN c_cursor_getexvalue; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0004;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )107;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_from_ccy_id;
        sqlstm.sqhstl[0] = (unsigned long )5;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_from_ccy_id;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_to_ccy_id;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_to_ccy_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_from_ccy_id;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_from_ccy_id;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_to_ccy_id;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_to_ccy_id;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_date_time;
        sqlstm.sqhstl[4] = (unsigned long )21;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_date_time;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto getexvalue_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getexvalue
                INTO
                        :v_rate:ind_rate,
                        :v_rec_date:ind_rec_date; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 5;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )142;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_rate;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_rate;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_rec_date;
                sqlstm.sqhstl[1] = (unsigned long )22;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_rec_date;
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
                if (sqlca.sqlcode < 0) goto getexvalue_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }	

		// rate	
		if (ind_rate >= 0) {
			PutField_Double(hRec, "rate", v_rate);
DEBUGLOG(("get_ex_value:result:: rate [%f]\n", v_rate));
		}

		// rec_date
		if (ind_rec_date >= 0) {
			v_rec_date.arr[v_rec_date.len] = '\0';
			PutField_CString(hRec, "rec_date", (const char *)v_rec_date.arr);
DEBUGLOG(("get_ex_value:result:: rec_date [%s]\n", v_rec_date.arr));
		}
	} while (PD_TRUE);
	
	/* EXEC SQL CLOSE c_cursor_getexvalue; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )165;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getexvalue_error;
}


	return iRet;

getexvalue_error:
DEBUGLOG(("check_exchange_rate.get_ex_value %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("check_exchange_rate.get_ex_value FAIL\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getexvalue; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )180;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



        return FAILURE;
}
