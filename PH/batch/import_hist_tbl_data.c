
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
           char  filnam[24];
};
static struct sqlcxp sqlfpn =
{
    23,
    "import_hist_tbl_data.pc"
};


static unsigned int sqlctx = 636635523;


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
   unsigned char  *sqhstv[25];
   unsigned long  sqhstl[25];
            int   sqhsts[25];
            short *sqindv[25];
            int   sqinds[25];
   unsigned long  sqharm[25];
   unsigned long  *sqharc[25];
   unsigned short  sqadto[25];
   unsigned short  sqtdso[25];
} sqlstm = {12,25};

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
5,0,0,1,235,0,6,476,0,0,7,7,0,1,0,2,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,9,
0,0,1,9,0,0,
48,0,0,2,562,0,6,695,0,0,18,18,0,1,0,2,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,
1,4,0,0,1,4,0,0,1,4,0,0,
135,0,0,3,229,0,6,813,0,0,7,7,0,1,0,2,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,
9,0,0,1,9,0,0,
178,0,0,4,416,0,6,972,0,0,12,12,0,1,0,2,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,
1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,
241,0,0,5,236,0,6,1084,0,0,7,7,0,1,0,2,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,
9,0,0,1,9,0,0,
284,0,0,6,1021,0,6,1374,0,0,25,25,0,1,0,2,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,
0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,
4,0,0,
399,0,0,7,235,0,6,1498,0,0,7,7,0,1,0,2,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,
9,0,0,1,9,0,0,
442,0,0,8,510,0,6,1707,0,0,17,17,0,1,0,2,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,
0,1,4,0,0,1,4,0,0,
525,0,0,9,233,0,6,1824,0,0,7,7,0,1,0,2,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,
9,0,0,1,9,0,0,
568,0,0,10,438,0,6,2014,0,0,15,15,0,1,0,2,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,
0,0,
643,0,0,11,234,0,6,2129,0,0,7,7,0,1,0,2,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,
1,9,0,0,1,9,0,0,
686,0,0,12,517,0,6,2348,0,0,18,18,0,1,0,2,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,9,
0,0,1,9,0,0,1,9,0,0,1,3,0,0,
773,0,0,13,0,0,17,2419,0,0,1,1,0,1,0,1,9,0,0,
792,0,0,13,0,0,21,2420,0,0,0,0,0,1,0,
807,0,0,13,0,0,17,2434,0,0,1,1,0,1,0,1,9,0,0,
826,0,0,13,0,0,21,2435,0,0,0,0,0,1,0,
841,0,0,13,0,0,17,2475,0,0,1,1,0,1,0,1,9,0,0,
860,0,0,13,0,0,21,2476,0,0,0,0,0,1,0,
875,0,0,13,0,0,17,2490,0,0,1,1,0,1,0,1,9,0,0,
894,0,0,13,0,0,21,2491,0,0,0,0,0,1,0,
909,0,0,13,0,0,17,2529,0,0,1,1,0,1,0,1,9,0,0,
928,0,0,13,0,0,21,2530,0,0,0,0,0,1,0,
943,0,0,13,0,0,17,2544,0,0,1,1,0,1,0,1,9,0,0,
962,0,0,13,0,0,21,2545,0,0,0,0,0,1,0,
977,0,0,13,0,0,17,2584,0,0,1,1,0,1,0,1,9,0,0,
996,0,0,13,0,0,21,2585,0,0,0,0,0,1,0,
1011,0,0,13,0,0,17,2599,0,0,1,1,0,1,0,1,9,0,0,
1030,0,0,13,0,0,21,2600,0,0,0,0,0,1,0,
1045,0,0,13,0,0,17,2639,0,0,1,1,0,1,0,1,9,0,0,
1064,0,0,13,0,0,21,2640,0,0,0,0,0,1,0,
1079,0,0,13,0,0,17,2654,0,0,1,1,0,1,0,1,9,0,0,
1098,0,0,13,0,0,21,2655,0,0,0,0,0,1,0,
1113,0,0,13,0,0,17,2694,0,0,1,1,0,1,0,1,9,0,0,
1132,0,0,13,0,0,21,2695,0,0,0,0,0,1,0,
1147,0,0,13,0,0,17,2709,0,0,1,1,0,1,0,1,9,0,0,
1166,0,0,13,0,0,21,2710,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2016/02/04              Dirk Wong
Add 2 fields HistOlFeeSumDetail			   2016/03/03		   Dirk Wong
Add 4 fields HistBaidBalDetail			   2016/05/03		   Dirk Wong
Restructure program		   		   2016/06/16		   Dirk Wong
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include <math.h>
#include "utilitys.h"
#include "expat.h"
#include <curl/curl.h>
#include "myhash.h"
#include "ObjPtr.h"
#include "numutility.h"
#include "myrecordset.h"
#include "batchcommon.h"
#include "TxnSeq.h"
#include "import_hist_tbl_data.h"
#include "internal.h"

#define	TBL_HOFSB	1
#define	TBL_HOFSD	2
#define	TBL_HOBISB	3
#define	TBL_HOBISD	4
#define TBL_HOCSB	5
#define TBL_HOCSD	6
#define TBL_HOMBB	7
#define TBL_HOMBD	8
#define TBL_OHBB	9
#define TBL_OHBD	10
#define TBL_HBBB	11
#define TBL_HBBD	12

char	cs_table[PD_CODE_LEN + 1];
char    cs_date[PD_DATE_LEN + 1];

char    cDebug = 'Y';

int 	parse_arg(int argc,char **argv);
int	parse_file(FILE *file1, int iFileNum);

int	InsertHistOlFeeSumBatch(char csList[][IMPORT_FIELD_LEN]);
int	InsertHistOlFeeSumDetail(char csList[][IMPORT_FIELD_LEN]);
int	InsertHistOlBtInterSumBatch(char csList[][IMPORT_FIELD_LEN]);
int	InsertHistOlBtInterSumDetail(char csList[][IMPORT_FIELD_LEN]);
int	InsertHistOlCostSumBatch(char csList[][IMPORT_FIELD_LEN]);
int	InsertHistOlCostSumDetail(char csList[][IMPORT_FIELD_LEN]);
int	InsertHistOlMidBalBatch(char csList[][IMPORT_FIELD_LEN]);
int	InsertHistOlMidBalDetail(char csList[][IMPORT_FIELD_LEN]);
int	InsertOmiHistBalBatch(char csList[][IMPORT_FIELD_LEN]);
int	InsertOmiHistBalDetail(char csList[][IMPORT_FIELD_LEN]);
int	InsertHistBaidBalBatch(char csList[][IMPORT_FIELD_LEN]);
int	InsertHistBaidBalDetail(char csList[][IMPORT_FIELD_LEN]);

int	Delete_HOFS(const char* csDate);
int	Delete_HOBIS(const char* csDate);
int	Delete_HOCS(const char* csDate);
int	Delete_HOMB(const char* csDate);
int	Delete_OHB(const char* csDate);
int	Delete_HBB(const char* csDate);


int batch_init(int argc, char* argv[])
{
    if (argc < 3) {
        printf("usage:  -t Table -d Date\n");
        return FAILURE;
    }
    else
        return SUCCESS;
}



int batch_proc(int argc, char* argv[])
{
	char	cs_file1[PD_MAX_FILE_LEN + 1];
        FILE    *file1;
        int     iRet;

        iRet = parse_arg(argc,argv);
 
        if (iRet != SUCCESS){
		printf("usage:  -t Table -d Date\n");
                return (iRet);
	}

	char	cs_yyyy[PD_YYYY_LEN+1];
	char	cs_yyyymm[PD_YYYYMM_LEN+1];

	memset(cs_yyyy,0,PD_YYYY_LEN+1);
	memset(cs_yyyymm,0,PD_YYYYMM_LEN+1);
	strncpy(cs_yyyy,cs_date,4);
	strncpy(cs_yyyymm,cs_date,6);

//HIST_OL_FEE_SUM
	if ((!strcmp(cs_table,PD_TBL_HOFS)) || (!strcmp(cs_table,PD_TBL_ALL))) {

		iRet = Delete_HOFS(cs_date);

		sprintf(cs_file1, "%s/%s/%s/%s/hist_ol_fee_sum_batch_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
		file1 = fopen(cs_file1,"r");
		if (file1 == NULL) {
DEBUGLOG(("Error Opening file = [%s]\n",cs_file1));
			return FAILURE;
		} else {
			iRet = parse_file(file1, TBL_HOFSB);
		}
		fclose(file1);

		sprintf(cs_file1, "%s/%s/%s/%s/hist_ol_fee_sum_detail_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
		file1 = fopen(cs_file1,"r");
		if (file1 == NULL) {
DEBUGLOG(("Error Opening file = [%s]\n",cs_file1));
			return FAILURE;
		} else {
			iRet = parse_file(file1, TBL_HOFSD);
		}
		fclose(file1);

	}

//HIST_OL_BT_INTER_SUM
	if ((!strcmp(cs_table,PD_TBL_HOBIS)) || (!strcmp(cs_table,PD_TBL_ALL))) {

		iRet = Delete_HOBIS(cs_date);

		sprintf(cs_file1, "%s/%s/%s/%s/hist_ol_bt_inter_sum_batch_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
		file1 = fopen(cs_file1,"r");
		if (file1 == NULL) {
DEBUGLOG(("Error Opening file = [%s]\n",cs_file1));
			return FAILURE;
		} else {
			iRet = parse_file(file1, TBL_HOBISB);
		}
		fclose(file1);

		sprintf(cs_file1, "%s/%s/%s/%s/hist_ol_bt_inter_sum_detail_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
		file1 = fopen(cs_file1,"r");
		if (file1 == NULL) {
DEBUGLOG(("Error Opening file = [%s]\n",cs_file1));
			return FAILURE;
		} else {
			iRet = parse_file(file1, TBL_HOBISD);
		}
		fclose(file1);

	}

//HIST_OL_COST_SUM
	if ((!strcmp(cs_table,PD_TBL_HOCS)) || (!strcmp(cs_table,PD_TBL_ALL))) {

		iRet = Delete_HOCS(cs_date);

		sprintf(cs_file1, "%s/%s/%s/%s/hist_ol_cost_sum_batch_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
		file1 = fopen(cs_file1,"r");
		if (file1 == NULL) {
DEBUGLOG(("Error Opening file = [%s]\n",cs_file1));
			return FAILURE;
		} else {
			iRet = parse_file(file1, TBL_HOCSB);
		}
		fclose(file1);

		sprintf(cs_file1, "%s/%s/%s/%s/hist_ol_cost_sum_detail_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
		file1 = fopen(cs_file1,"r");
		if (file1 == NULL) {
DEBUGLOG(("Error Opening file = [%s]\n",cs_file1));
			return FAILURE;
		} else {
			iRet = parse_file(file1, TBL_HOCSD);
		}
		fclose(file1);

	}

//HIST_OL_MID_BAL
	if ((!strcmp(cs_table,PD_TBL_HOMB)) || (!strcmp(cs_table,PD_TBL_ALL))) {

		iRet = Delete_HOMB(cs_date);

		sprintf(cs_file1, "%s/%s/%s/%s/hist_ol_mid_bal_batch_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
		file1 = fopen(cs_file1,"r");
		if (file1 == NULL) {
DEBUGLOG(("Error Opening file = [%s]\n",cs_file1));
			return FAILURE;
		} else {
			iRet = parse_file(file1, TBL_HOMBB);
		}
		fclose(file1);

		sprintf(cs_file1, "%s/%s/%s/%s/hist_ol_mid_bal_detail_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
		file1 = fopen(cs_file1,"r");
		if (file1 == NULL) {
DEBUGLOG(("Error Opening file = [%s]\n",cs_file1));
			return FAILURE;
		} else {
			iRet = parse_file(file1, TBL_HOMBD);
		}
		fclose(file1);

	}

//OMI_HIST_BAL
	if ((!strcmp(cs_table,PD_TBL_OHB)) || (!strcmp(cs_table,PD_TBL_ALL))) {

		iRet = Delete_OHB(cs_date);

		sprintf(cs_file1, "%s/%s/%s/%s/omi_hist_bal_batch_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
		file1 = fopen(cs_file1,"r");
		if (file1 == NULL) {
DEBUGLOG(("Error Opening file = [%s]\n",cs_file1));
			return FAILURE;
		} else {
			iRet = parse_file(file1, TBL_OHBB);
		}
		fclose(file1);

		sprintf(cs_file1, "%s/%s/%s/%s/omi_hist_bal_detail_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
		file1 = fopen(cs_file1,"r");
		if (file1 == NULL) {
DEBUGLOG(("Error Opening file = [%s]\n",cs_file1));
			return FAILURE;
		} else {
			iRet = parse_file(file1, TBL_OHBD);
		}
		fclose(file1);

	}

//HIST_BAID_BAL
	if ((!strcmp(cs_table,PD_TBL_HBB)) || (!strcmp(cs_table,PD_TBL_ALL))) {

		iRet = Delete_HBB(cs_date);

		sprintf(cs_file1, "%s/%s/%s/%s/hist_baid_bal_batch_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
		file1 = fopen(cs_file1,"r");
		if (file1 == NULL) {
DEBUGLOG(("Error Opening file = [%s]\n",cs_file1));
			return FAILURE;
		} else {
			iRet = parse_file(file1, TBL_HBBB);
		}
		fclose(file1);

		sprintf(cs_file1, "%s/%s/%s/%s/hist_baid_bal_detail_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
		file1 = fopen(cs_file1,"r");
		if (file1 == NULL) {
DEBUGLOG(("Error Opening file = [%s]\n",cs_file1));
			return FAILURE;
		} else {
			iRet = parse_file(file1, TBL_HBBD);
		}
		fclose(file1);

	}


DEBUGLOG(("===== Finished!, iRet [%d] =====\n",iRet));

        return iRet;

}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}



int parse_arg(int argc,char **argv)
{
        char    c;
        strcpy(cs_date,"");

        while ((c = getopt(argc,argv,"t:d:")) != EOF) {
                switch (c) {
                        case 't':
                                strcpy(cs_table, optarg);
                                break;
                        case 'd':
                                strcpy(cs_date, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if ( (!strcmp(cs_date,"")) || (!strcmp(cs_date,"")) )
                return FAILURE;

        return SUCCESS;
}


int     parse_file(FILE *file1, int iFileNum)
{
        int     iRet = SUCCESS;
        char    csList[IMPORT_MAX_FIELD][IMPORT_FIELD_LEN];
        char    cs_input_buf[PD_MAX_BUFFER +1];
        char*   p;
        int     iCount;


	while (fgets(cs_input_buf,PD_MAX_BUFFER,file1) != NULL)
        {
                iCount = 0;
                if ((cs_input_buf[strlen(cs_input_buf) - 1] == 0x0A) || (cs_input_buf[strlen(cs_input_buf) - 1] == 0x0D))
                cs_input_buf[strlen(cs_input_buf) - 1] = '\0';
DEBUGLOG(("*[%s]\n",cs_input_buf));
                p = mystrtok(cs_input_buf,",");
                if (p == NULL)  {
                        return FAILURE;
                }

                if (strlen(p) > 0) {

                        if(p[strlen(p) - 1] == 0x0D)
                                p[strlen(p) - 1] = '\0';
                        strcpy(csList[iCount],p);
                }
                else {
                        csList[iCount][0] ='\0';
                }
                iCount++;

                while ( (p = mystrtok(NULL,",")) != NULL) {
                        if(p[strlen(p) - 1] == 0x0D)
                                p[strlen(p) - 1] = '\0';
                        strcpy(csList[iCount],p);
                        iCount++;
                }

		switch (iFileNum) {

			case 1:
				iRet = InsertHistOlFeeSumBatch(csList);
				break;
			case 2:
				iRet = InsertHistOlFeeSumDetail(csList);
				break;
			case 3:
				iRet = InsertHistOlBtInterSumBatch(csList);
				break;
			case 4:
				iRet = InsertHistOlBtInterSumDetail(csList);
				break;
			case 5:
				iRet = InsertHistOlCostSumBatch(csList);
				break;
			case 6:
				iRet = InsertHistOlCostSumDetail(csList);
				break;
			case 7:
				iRet = InsertHistOlMidBalBatch(csList);
				break;
			case 8:
				iRet = InsertHistOlMidBalDetail(csList);
				break;
			case 9:
				iRet = InsertOmiHistBalBatch(csList);
				break;
			case 10:
				iRet = InsertOmiHistBalDetail(csList);
				break;
			case 11:
				iRet = InsertHistBaidBalBatch(csList);
				break;
			case 12:
				iRet = InsertHistBaidBalDetail(csList);
				break;

		}

                if (iRet != SUCCESS)
                        break;

        }

DEBUGLOG(("Parsefile ret =[%d]\n",iRet));

        return iRet;
}

int     InsertHistOlFeeSumBatch(char csList[][IMPORT_FIELD_LEN])
{
        int     iRet = SUCCESS;
	int	iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO errorhistolfeesumbatch; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short		hv_return_value;

		int		hv_batch_id;
                /* varchar		hv_start_ts[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_start_ts;

                /* varchar		hv_end_ts[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_end_ts;

		int		hv_disabled;
                /* varchar		hv_create_ts[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_create_ts;

                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


                short           ind_batch_id = -1;
                short           ind_start_ts = -1;
                short           ind_end_ts = -1;
                short           ind_disabled = -1;
                short           ind_create_ts = -1;
                short           ind_create_user = -1;

        /* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("=== Insert HistOlFeeSumBatch2 ===\n"));


//batch_id
        if (strlen(csList[IDX_BATCH_ID]) > 0 ) {
		iTmp = atoi(csList[IDX_BATCH_ID]);
		hv_batch_id = iTmp;
		ind_batch_id = 0;
DEBUGLOG(("Insert batch_id = [%d]\n",hv_batch_id));
        }

//start_ts
        if (strlen(csList[IDX_START_TS]) > 0 ) {
                hv_start_ts.len = strlen(csList[IDX_START_TS]);
                memcpy(hv_start_ts.arr,csList[IDX_START_TS],hv_start_ts.len);
                ind_start_ts = 0;
DEBUGLOG(("Insert start_ts = [%.*s]\n",hv_start_ts.len,hv_start_ts.arr));
        }

//end_ts
        if (strlen(csList[IDX_END_TS]) > 0 ) {
                hv_end_ts.len = strlen(csList[IDX_END_TS]);
                memcpy(hv_end_ts.arr,csList[IDX_END_TS],hv_end_ts.len);
                ind_end_ts = 0;
DEBUGLOG(("Insert end_ts = [%.*s]\n",hv_end_ts.len,hv_end_ts.arr));
        }

//disabled
        if (strlen(csList[IDX_DISABLED]) > 0 ) {
		iTmp = atoi(csList[IDX_DISABLED]);
		hv_disabled = iTmp;
		ind_disabled = 0;
DEBUGLOG(("Insert disabled = [%d]\n",hv_disabled));
        }

//create_ts
        if (strlen(csList[IDX_CREATE_TS]) > 0 ) {
                hv_create_ts.len = strlen(csList[IDX_CREATE_TS]);
                memcpy(hv_create_ts.arr,csList[IDX_CREATE_TS],hv_create_ts.len);
                ind_create_ts = 0;
DEBUGLOG(("Insert create_ts = [%.*s]\n",hv_create_ts.len,hv_create_ts.arr));
        }

//create_user 
	hv_create_user.len = strlen(PD_UPDATE_USER);
	memcpy(hv_create_user.arr,PD_UPDATE_USER,hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("Insert detail create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_histolfeesumbatch_insert(
                                                :hv_batch_id:ind_batch_id,
						:hv_start_ts:ind_start_ts,
						:hv_end_ts:ind_end_ts,
                                                :hv_disabled:ind_disabled,
                                                :hv_create_ts:ind_create_ts,
                                                :hv_create_user:ind_create_user);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_histolfeesumbatch_inser\
t ( :hv_batch_id:ind_batch_id , :hv_start_ts:ind_start_ts , :hv_end_ts:ind_en\
d_ts , :hv_disabled:ind_disabled , :hv_create_ts:ind_create_ts , :hv_create_u\
ser:ind_create_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )5;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_batch_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_start_ts;
        sqlstm.sqhstl[2] = (unsigned long )16;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_start_ts;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_end_ts;
        sqlstm.sqhstl[3] = (unsigned long )16;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_end_ts;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_disabled;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_disabled;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_create_ts;
        sqlstm.sqhstl[5] = (unsigned long )16;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_create_ts;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
        sqlstm.sqhstl[6] = (unsigned long )22;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_create_user;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto errorhistolfeesumbatch;
}



	if (hv_return_value == SP_OK) {
		iRet = SUCCESS;
	}
	else {
DEBUGLOG(("error code %d from sp\n", hv_return_value));
		iRet = FAILURE;
	}

        return iRet;

errorhistolfeesumbatch:
DEBUGLOG(("insert_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}


int     InsertHistOlFeeSumDetail(char csList[][IMPORT_FIELD_LEN])
{
        int     iRet = SUCCESS;
	int	iTmp;
	double	dTmp;
	
	/* EXEC SQL WHENEVER SQLERROR GOTO errorhistolfeesumdetail; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short		hv_return_value;

		int		hv_batch_id;
		/* varchar		hv_client_id[10]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_client_id;

		/* varchar		hv_client_name[50]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_client_name;

                /* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar		hv_merchant_name[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_merchant_name;

                /* varchar		hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

                /* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                /* varchar		hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

                /* varchar		hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

		double		hv_amt;
		double		hv_amt_hkd;
		double		hv_amt_hkd_rate;
		double		hv_amt_usd;
		double		hv_amt_usd_rate;
		double		hv_txn_count;
		double		hv_is_fee;
		double		hv_is_markup;

                short           ind_batch_id = -1;
		short		ind_client_id = -1;
		short		ind_client_name = -1;
		short		ind_merchant_id = -1;
		short		ind_merchant_name = -1;
		short		ind_country = -1;
		short		ind_service_code = -1;
		short		ind_ccy = -1;
		short		ind_txn_code = -1;
		short		ind_amt = -1;
		short		ind_amt_hkd = -1;
		short		ind_amt_hkd_rate = -1;
		short		ind_amt_usd = -1;
		short		ind_amt_usd_rate = -1;
		short		ind_txn_count = -1;
		short		ind_is_fee = -1;
		short		ind_is_markup = -1;
		
        /* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("=== Insert HistOlFeeSumDetail2 ===\n"));


//batch_id
        if (strlen(csList[IDX_HOFSD_BATCH_ID]) > 0 ) {
		iTmp = atoi(csList[IDX_HOFSD_BATCH_ID]);
		hv_batch_id = iTmp;
		ind_batch_id = 0;
DEBUGLOG(("Insert batch_id = [%d]\n",hv_batch_id));
        }

//client_id
        if (strlen(csList[IDX_HOFSD_CLIENT_ID]) > 0 ) {
                hv_client_id.len = strlen(csList[IDX_HOFSD_CLIENT_ID]);
                memcpy(hv_client_id.arr,csList[IDX_HOFSD_CLIENT_ID],hv_client_id.len);
                ind_client_id = 0;
DEBUGLOG(("Insert client_id = [%.*s]\n",hv_client_id.len,hv_client_id.arr));
        }

//client_name
        if (strlen(csList[IDX_HOFSD_CLIENT_NAME]) > 0 ) {
                hv_client_name.len = strlen(csList[IDX_HOFSD_CLIENT_NAME]);
                memcpy(hv_client_name.arr,csList[IDX_HOFSD_CLIENT_NAME],hv_client_name.len);
                ind_client_name = 0;
DEBUGLOG(("Insert client_name = [%.*s]\n",hv_client_name.len,hv_client_name.arr));
        }

//merchant_id
        if (strlen(csList[IDX_HOFSD_MERCHANT_ID]) > 0 ) {
                hv_merchant_id.len = strlen(csList[IDX_HOFSD_MERCHANT_ID]);
                memcpy(hv_merchant_id.arr,csList[IDX_HOFSD_MERCHANT_ID],hv_merchant_id.len);
                ind_merchant_id = 0;
DEBUGLOG(("Insert merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        }

//merchant_name
        if (strlen(csList[IDX_HOFSD_MERCHANT_NAME]) > 0 ) {
                hv_merchant_name.len = strlen(csList[IDX_HOFSD_MERCHANT_NAME]);
                memcpy(hv_merchant_name.arr,csList[IDX_HOFSD_MERCHANT_NAME],hv_merchant_name.len);
                ind_merchant_name = 0;
DEBUGLOG(("Insert merchant_name = [%.*s]\n",hv_merchant_name.len,hv_merchant_name.arr));
        }

//country
	if (strlen(csList[IDX_HOFSD_COUNTRY]) > 0 ) {
                hv_country.len = strlen(csList[IDX_HOFSD_COUNTRY]);
                memcpy(hv_country.arr,csList[IDX_HOFSD_COUNTRY],hv_country.len);
                ind_country = 0;
DEBUGLOG(("Insert country = [%.*s]\n",hv_country.len,hv_country.arr));
        }

//service_code
	if (strlen(csList[IDX_HOFSD_SERVICE_CODE]) > 0 ) {
                hv_service_code.len = strlen(csList[IDX_HOFSD_SERVICE_CODE]);
                memcpy(hv_service_code.arr,csList[IDX_HOFSD_SERVICE_CODE],hv_service_code.len);
                ind_service_code = 0;
DEBUGLOG(("Insert service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));
        }

//ccy
	if (strlen(csList[IDX_HOFSD_CCY]) > 0 ) {
                hv_ccy.len = strlen(csList[IDX_HOFSD_CCY]);
                memcpy(hv_ccy.arr,csList[IDX_HOFSD_CCY],hv_ccy.len);
                ind_ccy = 0;
DEBUGLOG(("Insert ccy = [%.*s]\n",hv_ccy.len,hv_ccy.arr));
        }

//txn_code
	if (strlen(csList[IDX_HOFSD_TXN_CODE]) > 0 ) {
                hv_txn_code.len = strlen(csList[IDX_HOFSD_TXN_CODE]);
                memcpy(hv_txn_code.arr,csList[IDX_HOFSD_TXN_CODE],hv_txn_code.len);
                ind_txn_code = 0;
DEBUGLOG(("Insert txn_code = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));
        }

//amt
	if (strlen(csList[IDX_HOFSD_AMT]) > 0 ) {
                dTmp = string2double(csList[IDX_HOFSD_AMT]);
                hv_amt = dTmp;
                ind_amt = 0;
DEBUGLOG(("Insert amt = [%.2f]\n",hv_amt));
        }

//amt_hkd
	if (strlen(csList[IDX_HOFSD_AMT_HKD]) > 0 ) {
                dTmp = string2double(csList[IDX_HOFSD_AMT_HKD]);
                hv_amt_hkd = dTmp;
                ind_amt_hkd = 0;
DEBUGLOG(("Insert amt_hkd = [%.2f]\n",hv_amt_hkd));
        }

//amt_hkd_rate
	if (strlen(csList[IDX_HOFSD_AMT_HKD_RATE]) > 0 ) {
                dTmp = string2double(csList[IDX_HOFSD_AMT_HKD_RATE]);
                hv_amt_hkd_rate = dTmp;
                ind_amt_hkd_rate = 0;
DEBUGLOG(("Insert amt_hkd_rate = [%.5f]\n",hv_amt_hkd_rate));
        }

//amt_usd
	if (strlen(csList[IDX_HOFSD_AMT_USD]) > 0 ) {
                dTmp = string2double(csList[IDX_HOFSD_AMT_USD]);
                hv_amt_usd = dTmp;
                ind_amt_usd = 0;
DEBUGLOG(("Insert amt_usd = [%.2f]\n",hv_amt_usd));
        }

//amt_usd_rate
	if (strlen(csList[IDX_HOFSD_AMT_USD_RATE]) > 0 ) {
                dTmp = string2double(csList[IDX_HOFSD_AMT_USD_RATE]);
                hv_amt_usd_rate = dTmp;
                ind_amt_usd_rate = 0;
DEBUGLOG(("Insert amt_usd_rate = [%.5f]\n",hv_amt_usd_rate));
        }

//txn_count
	if (strlen(csList[IDX_HOFSD_TXN_COUNT]) > 0 ) {
                dTmp = string2double(csList[IDX_HOFSD_TXN_COUNT]);
                hv_txn_count = dTmp;
                ind_txn_count = 0;
DEBUGLOG(("Insert txn_count = [%.2f]\n",hv_txn_count));
        }

//is_fee
	if (strlen(csList[IDX_HOFSD_IS_FEE]) > 0 ) {
                dTmp = string2double(csList[IDX_HOFSD_IS_FEE]);
                hv_is_fee = dTmp;
                ind_is_fee = 0;
DEBUGLOG(("Insert is_fee = [%.2f]\n",hv_is_fee));
        }

//is_markup
	if (strlen(csList[IDX_HOFSD_IS_MARKUP]) > 0 ) {
                dTmp = string2double(csList[IDX_HOFSD_IS_MARKUP]);
                hv_is_markup = dTmp;
                ind_is_markup = 0;
DEBUGLOG(("Insert is_markup = [%.2f]\n",hv_is_markup));
        }


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_histolfeesumdetail_insert(
                                                :hv_batch_id:ind_batch_id,
						:hv_client_id:ind_client_id,
						:hv_client_name:ind_client_name,
						:hv_merchant_id:ind_merchant_id,
						:hv_merchant_name:ind_merchant_name,
						:hv_country:ind_country,
                                                :hv_service_code:ind_service_code,
                                                :hv_ccy:ind_ccy,
						:hv_txn_code:ind_txn_code,
						:hv_amt:ind_amt,
						:hv_amt_hkd:ind_amt_hkd,
						:hv_amt_hkd_rate:ind_amt_hkd_rate,
						:hv_amt_usd:ind_amt_usd,
						:hv_amt_usd_rate:ind_amt_usd_rate,
						:hv_txn_count:ind_txn_count,
						:hv_is_fee:ind_is_fee,
                                                :hv_is_markup:ind_is_markup);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 18;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_histolfeesumdetail_inse\
rt ( :hv_batch_id:ind_batch_id , :hv_client_id:ind_client_id , :hv_client_nam\
e:ind_client_name , :hv_merchant_id:ind_merchant_id , :hv_merchant_name:ind_m\
erchant_name , :hv_country:ind_country , :hv_service_code:ind_service_code , \
:hv_ccy:ind_ccy , :hv_txn_code:ind_txn_code , :hv_amt:ind_amt , :hv_amt_hkd:i\
nd_amt_hkd , :hv_amt_hkd_rate:ind_amt_hkd_rate , :hv_amt_usd:ind_amt_usd , :h\
v_amt_usd_rate:ind_amt_usd_rate , :hv_txn_count:ind_txn_count , :hv_is_fee:in\
d_is_fee , :hv_is_markup:ind_is_markup ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )48;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_batch_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_client_id;
        sqlstm.sqhstl[2] = (unsigned long )12;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_client_id;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_client_name;
        sqlstm.sqhstl[3] = (unsigned long )52;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_client_name;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[4] = (unsigned long )17;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_merchant_id;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_merchant_name;
        sqlstm.sqhstl[5] = (unsigned long )22;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_merchant_name;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_country;
        sqlstm.sqhstl[6] = (unsigned long )4;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_country;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[7] = (unsigned long )5;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_service_code;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_ccy;
        sqlstm.sqhstl[8] = (unsigned long )5;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_ccy;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_txn_code;
        sqlstm.sqhstl[9] = (unsigned long )5;
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&ind_txn_code;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&hv_amt;
        sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)&ind_amt;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&hv_amt_hkd;
        sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         short *)&ind_amt_hkd;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (unsigned char  *)&hv_amt_hkd_rate;
        sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         short *)&ind_amt_hkd_rate;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned long )0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
        sqlstm.sqhstv[13] = (unsigned char  *)&hv_amt_usd;
        sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[13] = (         int  )0;
        sqlstm.sqindv[13] = (         short *)&ind_amt_usd;
        sqlstm.sqinds[13] = (         int  )0;
        sqlstm.sqharm[13] = (unsigned long )0;
        sqlstm.sqadto[13] = (unsigned short )0;
        sqlstm.sqtdso[13] = (unsigned short )0;
        sqlstm.sqhstv[14] = (unsigned char  *)&hv_amt_usd_rate;
        sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[14] = (         int  )0;
        sqlstm.sqindv[14] = (         short *)&ind_amt_usd_rate;
        sqlstm.sqinds[14] = (         int  )0;
        sqlstm.sqharm[14] = (unsigned long )0;
        sqlstm.sqadto[14] = (unsigned short )0;
        sqlstm.sqtdso[14] = (unsigned short )0;
        sqlstm.sqhstv[15] = (unsigned char  *)&hv_txn_count;
        sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[15] = (         int  )0;
        sqlstm.sqindv[15] = (         short *)&ind_txn_count;
        sqlstm.sqinds[15] = (         int  )0;
        sqlstm.sqharm[15] = (unsigned long )0;
        sqlstm.sqadto[15] = (unsigned short )0;
        sqlstm.sqtdso[15] = (unsigned short )0;
        sqlstm.sqhstv[16] = (unsigned char  *)&hv_is_fee;
        sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[16] = (         int  )0;
        sqlstm.sqindv[16] = (         short *)&ind_is_fee;
        sqlstm.sqinds[16] = (         int  )0;
        sqlstm.sqharm[16] = (unsigned long )0;
        sqlstm.sqadto[16] = (unsigned short )0;
        sqlstm.sqtdso[16] = (unsigned short )0;
        sqlstm.sqhstv[17] = (unsigned char  *)&hv_is_markup;
        sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[17] = (         int  )0;
        sqlstm.sqindv[17] = (         short *)&ind_is_markup;
        sqlstm.sqinds[17] = (         int  )0;
        sqlstm.sqharm[17] = (unsigned long )0;
        sqlstm.sqadto[17] = (unsigned short )0;
        sqlstm.sqtdso[17] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto errorhistolfeesumdetail;
}



	if (hv_return_value == SP_OK) {
		iRet = SUCCESS;
	}
	else {
DEBUGLOG(("error code %d from sp\n", hv_return_value));
		iRet = FAILURE;
	}


        return iRet;

errorhistolfeesumdetail:
DEBUGLOG(("insert_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}


int	InsertHistOlBtInterSumBatch(char csList[][IMPORT_FIELD_LEN])
{
        int     iRet = SUCCESS;
	int	iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO error_hobis_batch; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short		hv_return_value;

		int		hv_batch_id;
                /* varchar		hv_start_ts[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_start_ts;

                /* varchar		hv_end_ts[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_end_ts;

		int		hv_disabled;
                /* varchar		hv_create_ts[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_create_ts;

                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


                short           ind_batch_id = -1;
                short           ind_start_ts = -1;
                short           ind_end_ts = -1;
                short           ind_disabled = -1;
                short           ind_create_ts = -1;
                short           ind_create_user = -1;

        /* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("=== Insert HistOlBtInterSumBatch2 ===\n"));


//batch_id
        if (strlen(csList[IDX_HOBISB_BATCH_ID]) > 0 ) {
		iTmp = atoi(csList[IDX_HOBISB_BATCH_ID]);
		hv_batch_id = iTmp;
		ind_batch_id = 0;
DEBUGLOG(("Insert batch_id = [%d]\n",hv_batch_id));
        }

//start_ts
        if (strlen(csList[IDX_HOBISB_START_TS]) > 0 ) {
                hv_start_ts.len = strlen(csList[IDX_HOBISB_START_TS]);
                memcpy(hv_start_ts.arr,csList[IDX_HOBISB_START_TS],hv_start_ts.len);
                ind_start_ts = 0;
DEBUGLOG(("Insert start_ts = [%.*s]\n",hv_start_ts.len,hv_start_ts.arr));
        }

//end_ts
        if (strlen(csList[IDX_HOBISB_END_TS]) > 0 ) {
                hv_end_ts.len = strlen(csList[IDX_HOBISB_END_TS]);
                memcpy(hv_end_ts.arr,csList[IDX_HOBISB_END_TS],hv_end_ts.len);
                ind_end_ts = 0;
DEBUGLOG(("Insert end_ts = [%.*s]\n",hv_end_ts.len,hv_end_ts.arr));
        }

//disabled
        if (strlen(csList[IDX_HOBISB_DISABLED]) > 0 ) {
		iTmp = atoi(csList[IDX_HOBISB_DISABLED]);
		hv_disabled = iTmp;
		ind_disabled = 0;
DEBUGLOG(("Insert disabled = [%d]\n",hv_disabled));
        }

//create_ts
        if (strlen(csList[IDX_HOBISB_CREATE_TS]) > 0 ) {
                hv_create_ts.len = strlen(csList[IDX_HOBISB_CREATE_TS]);
                memcpy(hv_create_ts.arr,csList[IDX_HOBISB_CREATE_TS],hv_create_ts.len);
                ind_create_ts = 0;
DEBUGLOG(("Insert create_ts = [%.*s]\n",hv_create_ts.len,hv_create_ts.arr));
        }

//create_user 
	hv_create_user.len = strlen(PD_UPDATE_USER);
	memcpy(hv_create_user.arr,PD_UPDATE_USER,hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("Insert detail create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_hobis_batch_insert(
                                                :hv_batch_id:ind_batch_id,
						:hv_start_ts:ind_start_ts,
						:hv_end_ts:ind_end_ts,
                                                :hv_disabled:ind_disabled,
                                                :hv_create_ts:ind_create_ts,
                                                :hv_create_user:ind_create_user);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 18;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_hobis_batch_insert ( :h\
v_batch_id:ind_batch_id , :hv_start_ts:ind_start_ts , :hv_end_ts:ind_end_ts ,\
 :hv_disabled:ind_disabled , :hv_create_ts:ind_create_ts , :hv_create_user:in\
d_create_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )135;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_batch_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_start_ts;
        sqlstm.sqhstl[2] = (unsigned long )16;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_start_ts;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_end_ts;
        sqlstm.sqhstl[3] = (unsigned long )16;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_end_ts;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_disabled;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_disabled;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_create_ts;
        sqlstm.sqhstl[5] = (unsigned long )16;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_create_ts;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
        sqlstm.sqhstl[6] = (unsigned long )22;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_create_user;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto error_hobis_batch;
}



	if (hv_return_value == SP_OK) {
		iRet = SUCCESS;
	}
	else {
DEBUGLOG(("error code %d from sp\n", hv_return_value));
		iRet = FAILURE;
	}


        return iRet;

error_hobis_batch:
DEBUGLOG(("insert_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}


int     InsertHistOlBtInterSumDetail(char csList[][IMPORT_FIELD_LEN])
{
        int     iRet = SUCCESS;
	int	iTmp;
	double	dTmp;
	
	/* EXEC SQL WHENEVER SQLERROR GOTO errorhobisdetail; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short		hv_return_value;

		int		hv_batch_id;
                /* varchar		hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

                /* varchar		hv_product[PD_PRODUCT_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_product;

		int		hv_count;
		double		hv_accum_req_amt;
		double		hv_accum_void_amt;
		double		hv_accum_net_amt;
		double		hv_accum_net_amt_hkd;
		double		hv_hkd_rate;
		double		hv_accum_net_amt_usd;
		double		hv_usd_rate;

                short           ind_batch_id = -1;
		short		ind_ccy = -1;
		short		ind_product = -1;
		short		ind_count = -1;
		short		ind_accum_req_amt = -1;
		short		ind_accum_void_amt = -1;
		short		ind_accum_net_amt = -1;
		short		ind_accum_net_amt_hkd = -1;
		short		ind_hkd_rate = -1;
		short		ind_accum_net_amt_usd = -1;
		short		ind_usd_rate = -1;
		
        /* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("=== Insert HistOlBtInterSumDetail2 ===\n"));


//batch_id
        if (strlen(csList[IDX_HOBISD_BATCH_ID]) > 0 ) {
		iTmp = atoi(csList[IDX_HOBISD_BATCH_ID]);
		hv_batch_id = iTmp;
		ind_batch_id = 0;
DEBUGLOG(("Insert batch_id = [%d]\n",hv_batch_id));
        }

//ccy
        if (strlen(csList[IDX_HOBISD_CCY]) > 0 ) {
                hv_ccy.len = strlen(csList[IDX_HOBISD_CCY]);
                memcpy(hv_ccy.arr,csList[IDX_HOBISD_CCY],hv_ccy.len);
                ind_ccy = 0;
DEBUGLOG(("Insert ccy = [%.*s]\n",hv_ccy.len,hv_ccy.arr));
        }

//product
	if (strlen(csList[IDX_HOBISD_PRODUCT]) > 0 ) {
                hv_product.len = strlen(csList[IDX_HOBISD_PRODUCT]);
                memcpy(hv_product.arr,csList[IDX_HOBISD_PRODUCT],hv_product.len);
                ind_product = 0;
DEBUGLOG(("Insert product = [%.*s]\n",hv_product.len,hv_product.arr));
        }

//count
	if (strlen(csList[IDX_HOBISD_COUNT]) > 0 ) {
		iTmp = atoi(csList[IDX_HOBISD_COUNT]);
                hv_count = iTmp;
                ind_count = 0;
DEBUGLOG(("Insert count = [%d]\n",hv_count));
        }

//accum_req_amt
	if (strlen(csList[IDX_HOBISD_ACCUM_REQ_AMT]) > 0 ) {
                dTmp = string2double(csList[IDX_HOBISD_ACCUM_REQ_AMT]);
                hv_accum_req_amt = dTmp;
                ind_accum_req_amt = 0;
DEBUGLOG(("Insert accum_req_amt = [%.2f]\n",hv_accum_req_amt));
        }

//accum_void_amt
	if (strlen(csList[IDX_HOBISD_ACCUM_VOID_AMT]) > 0 ) {
                dTmp = string2double(csList[IDX_HOBISD_ACCUM_VOID_AMT]);
                hv_accum_void_amt = dTmp;
                ind_accum_void_amt = 0;
DEBUGLOG(("Insert accum_void_amt = [%.2f]\n",hv_accum_void_amt));
        }

//accum_net_amt
	if (strlen(csList[IDX_HOBISD_ACCUM_NET_AMT]) > 0 ) {
                dTmp = string2double(csList[IDX_HOBISD_ACCUM_NET_AMT]);
                hv_accum_net_amt = dTmp;
                ind_accum_net_amt = 0;
DEBUGLOG(("Insert accum_net_amt = [%.2f]\n",hv_accum_net_amt));
        }

//accum_net_amt_hkd
	if (strlen(csList[IDX_HOBISD_ACCUM_NET_AMT_HKD]) > 0 ) {
                dTmp = string2double(csList[IDX_HOBISD_ACCUM_NET_AMT_HKD]);
                hv_accum_net_amt_hkd = dTmp;
                ind_accum_net_amt_hkd = 0;
DEBUGLOG(("Insert accum_net_amt_hkd = [%.2f]\n",hv_accum_net_amt_hkd));
        }

//hkd_rate
	if (strlen(csList[IDX_HOBISD_HKD_RATE]) > 0 ) {
                dTmp = string2double(csList[IDX_HOBISD_HKD_RATE]);
                hv_hkd_rate = dTmp;
                ind_hkd_rate = 0;
DEBUGLOG(("Insert hkd_rate = [%.5f]\n",hv_hkd_rate));
        }

//accum_net_amt_usd
	if (strlen(csList[IDX_HOBISD_ACCUM_NET_AMT_USD]) > 0 ) {
                dTmp = string2double(csList[IDX_HOBISD_ACCUM_NET_AMT_USD]);
                hv_accum_net_amt_usd = dTmp;
                ind_accum_net_amt_usd = 0;
DEBUGLOG(("Insert accum_net_amt_usd = [%.2f]\n",hv_accum_net_amt_usd));
        }

//amt_usd_rate
	if (strlen(csList[IDX_HOBISD_USD_RATE]) > 0 ) {
                dTmp = string2double(csList[IDX_HOBISD_USD_RATE]);
                hv_usd_rate = dTmp;
                ind_usd_rate = 0;
DEBUGLOG(("Insert usd_rate = [%.5f]\n",hv_usd_rate));
        }

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_hobis_detail_insert(
                                                :hv_batch_id:ind_batch_id,
						:hv_ccy:ind_ccy,
						:hv_product:ind_product,
                                                :hv_count:ind_count,
						:hv_accum_req_amt:ind_accum_req_amt,
						:hv_accum_void_amt:ind_accum_void_amt,
						:hv_accum_net_amt:ind_accum_net_amt,
						:hv_accum_net_amt_hkd:ind_accum_net_amt_hkd,
						:hv_hkd_rate:ind_hkd_rate,
						:hv_accum_net_amt_usd:ind_accum_net_amt_usd,
						:hv_usd_rate:ind_usd_rate);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 18;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_hobis_detail_insert ( :\
hv_batch_id:ind_batch_id , :hv_ccy:ind_ccy , :hv_product:ind_product , :hv_co\
unt:ind_count , :hv_accum_req_amt:ind_accum_req_amt , :hv_accum_void_amt:ind_\
accum_void_amt , :hv_accum_net_amt:ind_accum_net_amt , :hv_accum_net_amt_hkd:\
ind_accum_net_amt_hkd , :hv_hkd_rate:ind_hkd_rate , :hv_accum_net_amt_usd:ind\
_accum_net_amt_usd , :hv_usd_rate:ind_usd_rate ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )178;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_batch_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_ccy;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_ccy;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_product;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_product;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_count;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_count;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_accum_req_amt;
        sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_accum_req_amt;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_accum_void_amt;
        sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_accum_void_amt;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_accum_net_amt;
        sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_accum_net_amt;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_accum_net_amt_hkd;
        sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_accum_net_amt_hkd;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_hkd_rate;
        sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&ind_hkd_rate;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&hv_accum_net_amt_usd;
        sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)&ind_accum_net_amt_usd;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&hv_usd_rate;
        sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         short *)&ind_usd_rate;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto errorhobisdetail;
}



	if (hv_return_value == SP_OK) {
		iRet = SUCCESS;
	}
	else {
DEBUGLOG(("error code %d from sp\n", hv_return_value));
		iRet = FAILURE;
	}


        return iRet;

errorhobisdetail:
DEBUGLOG(("insert_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}


int	InsertHistOlCostSumBatch(char csList[][IMPORT_FIELD_LEN])
{
        int     iRet = SUCCESS;
	int	iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO error_hocs_batch; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short		hv_return_value;

		int		hv_batch_id;
                /* varchar		hv_start_ts[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_start_ts;

                /* varchar		hv_end_ts[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_end_ts;

		int		hv_disabled;
                /* varchar		hv_create_ts[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_create_ts;

                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


                short           ind_batch_id = -1;
                short           ind_start_ts = -1;
                short           ind_end_ts = -1;
                short           ind_disabled = -1;
                short           ind_create_ts = -1;
                short           ind_create_user = -1;

        /* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("=== Insert HistOlCostSumBatch2 ===\n"));


//batch_id
        if (strlen(csList[IDX_HOCSB_BATCH_ID]) > 0 ) {
		iTmp = atoi(csList[IDX_HOCSB_BATCH_ID]);
		hv_batch_id = iTmp;
		ind_batch_id = 0;
DEBUGLOG(("Insert batch_id = [%d]\n",hv_batch_id));
        }

//start_ts
        if (strlen(csList[IDX_HOCSB_START_TS]) > 0 ) {
                hv_start_ts.len = strlen(csList[IDX_HOCSB_START_TS]);
                memcpy(hv_start_ts.arr,csList[IDX_HOCSB_START_TS],hv_start_ts.len);
                ind_start_ts = 0;
DEBUGLOG(("Insert start_ts = [%.*s]\n",hv_start_ts.len,hv_start_ts.arr));
        }

//end_ts
        if (strlen(csList[IDX_HOCSB_END_TS]) > 0 ) {
                hv_end_ts.len = strlen(csList[IDX_HOCSB_END_TS]);
                memcpy(hv_end_ts.arr,csList[IDX_HOCSB_END_TS],hv_end_ts.len);
                ind_end_ts = 0;
DEBUGLOG(("Insert end_ts = [%.*s]\n",hv_end_ts.len,hv_end_ts.arr));
        }

//disabled
        if (strlen(csList[IDX_HOCSB_DISABLED]) > 0 ) {
		iTmp = atoi(csList[IDX_HOCSB_DISABLED]);
		hv_disabled = iTmp;
		ind_disabled = 0;
DEBUGLOG(("Insert disabled = [%d]\n",hv_disabled));
        }

//create_ts
        if (strlen(csList[IDX_HOCSB_CREATE_TS]) > 0 ) {
                hv_create_ts.len = strlen(csList[IDX_HOCSB_CREATE_TS]);
                memcpy(hv_create_ts.arr,csList[IDX_HOCSB_CREATE_TS],hv_create_ts.len);
                ind_create_ts = 0;
DEBUGLOG(("Insert create_ts = [%.*s]\n",hv_create_ts.len,hv_create_ts.arr));
        }

//create_user 
	hv_create_user.len = strlen(PD_UPDATE_USER);
	memcpy(hv_create_user.arr,PD_UPDATE_USER,hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("Insert detail create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_histolcostsumbatch_insert(
                                                :hv_batch_id:ind_batch_id,
						:hv_start_ts:ind_start_ts,
						:hv_end_ts:ind_end_ts,
                                                :hv_disabled:ind_disabled,
                                                :hv_create_ts:ind_create_ts,
                                                :hv_create_user:ind_create_user);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 18;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_histolcostsumbatch_inse\
rt ( :hv_batch_id:ind_batch_id , :hv_start_ts:ind_start_ts , :hv_end_ts:ind_e\
nd_ts , :hv_disabled:ind_disabled , :hv_create_ts:ind_create_ts , :hv_create_\
user:ind_create_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )241;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_batch_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_start_ts;
        sqlstm.sqhstl[2] = (unsigned long )16;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_start_ts;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_end_ts;
        sqlstm.sqhstl[3] = (unsigned long )16;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_end_ts;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_disabled;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_disabled;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_create_ts;
        sqlstm.sqhstl[5] = (unsigned long )16;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_create_ts;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
        sqlstm.sqhstl[6] = (unsigned long )22;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_create_user;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto error_hocs_batch;
}



	if (hv_return_value == SP_OK) {
		iRet = SUCCESS;
	}
	else {
DEBUGLOG(("error code %d from sp\n", hv_return_value));
		iRet = FAILURE;
	}


        return iRet;

error_hocs_batch:
DEBUGLOG(("insert_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}


int     InsertHistOlCostSumDetail(char csList[][IMPORT_FIELD_LEN])
{
        int     iRet = SUCCESS;
	int	iTmp;
	double	dTmp;
	
	/* EXEC SQL WHENEVER SQLERROR GOTO errorhistolcostsumdetail; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short		hv_return_value;

		int		hv_batch_id;
                /* varchar		hv_party_type[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_party_type;

                /* varchar		hv_entity_id[10]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_entity_id;

                /* varchar		hv_entity_name[50]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_entity_name;

                /* varchar		hv_client_name[50]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_client_name;

                /* varchar		hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

                /* varchar		hv_country[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

                /* varchar		hv_product[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_product;

                /* varchar		hv_txn_type[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_type;

		int		hv_count;
		double		hv_accum_cost_amt;
		double		hv_accum_refund_amt;
		double		hv_accum_void_amt;
		double		hv_accum_total_amt;
		double		hv_accum_cost_amt_hkd;
		double		hv_accum_refund_amt_hkd;
		double		hv_accum_void_amt_hkd;
		double		hv_accum_total_amt_hkd;
		double		hv_accum_cost_amt_hkd_rate;
		double		hv_accum_cost_amt_usd;
		double		hv_accum_refund_amt_usd;
		double		hv_accum_void_amt_usd;
		double		hv_accum_total_amt_usd;
		double		hv_accum_cost_amt_usd_rate;

                short           ind_batch_id = -1;
		short		ind_party_type = -1;
		short		ind_entity_id = -1;
		short		ind_entity_name = -1;
		short		ind_client_name = -1;
		short		ind_ccy = -1;
		short		ind_country = -1;
		short		ind_product = -1;
		short		ind_txn_type = -1;
		short		ind_count = -1;
		short		ind_accum_cost_amt = -1;
		short		ind_accum_refund_amt = -1;
		short		ind_accum_void_amt = -1;
		short		ind_accum_total_amt = -1;
		short		ind_accum_cost_amt_hkd = -1;
		short		ind_accum_refund_amt_hkd = -1;
		short		ind_accum_void_amt_hkd = -1;
		short		ind_accum_total_amt_hkd = -1;
		short		ind_accum_cost_amt_hkd_rate = -1;
		short		ind_accum_cost_amt_usd = -1;
		short		ind_accum_refund_amt_usd = -1;
		short		ind_accum_void_amt_usd = -1;
		short		ind_accum_total_amt_usd = -1;
		short		ind_accum_cost_amt_usd_rate = -1;
		
        /* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("=== Insert HistOlCostSumDetail2 ===\n"));


//batch_id
        if (strlen(csList[IDX_HOCSD_BATCH_ID]) > 0 ) {
		iTmp = atoi(csList[IDX_HOCSD_BATCH_ID]);
		hv_batch_id = iTmp;
		ind_batch_id = 0;
DEBUGLOG(("Insert batch_id = [%d]\n",hv_batch_id));
        }

//party_type
        if (strlen(csList[IDX_HOCSD_PARTY_TYPE]) > 0 ) {
                hv_party_type.len = strlen(csList[IDX_HOCSD_PARTY_TYPE]);
                memcpy(hv_party_type.arr,csList[IDX_HOCSD_PARTY_TYPE],hv_party_type.len);
                ind_party_type = 0;
DEBUGLOG(("Insert party_type = [%.*s]\n",hv_party_type.len,hv_party_type.arr));
        }

//entity_id
	if (strlen(csList[IDX_HOCSD_ENTITY_ID]) > 0 ) {
                hv_entity_id.len = strlen(csList[IDX_HOCSD_ENTITY_ID]);
                memcpy(hv_entity_id.arr,csList[IDX_HOCSD_ENTITY_ID],hv_entity_id.len);
                ind_entity_id = 0;
DEBUGLOG(("Insert entity_id = [%.*s]\n",hv_entity_id.len,hv_entity_id.arr));
        }

//entity_name
	if (strlen(csList[IDX_HOCSD_ENTITY_NAME]) > 0 ) {
                hv_entity_name.len = strlen(csList[IDX_HOCSD_ENTITY_NAME]);
                memcpy(hv_entity_name.arr,csList[IDX_HOCSD_ENTITY_NAME],hv_entity_name.len);
                ind_entity_name = 0;
DEBUGLOG(("Insert entity_name = [%.*s]\n",hv_entity_name.len,hv_entity_name.arr));
        }

//client_name
	if (strlen(csList[IDX_HOCSD_CLIENT_NAME]) > 0 ) {
                hv_client_name.len = strlen(csList[IDX_HOCSD_CLIENT_NAME]);
                memcpy(hv_client_name.arr,csList[IDX_HOCSD_CLIENT_NAME],hv_client_name.len);
                ind_client_name = 0;
DEBUGLOG(("Insert client_name = [%.*s]\n",hv_client_name.len,hv_client_name.arr));
        }

//ccy
	if (strlen(csList[IDX_HOCSD_CCY]) > 0 ) {
                hv_ccy.len = strlen(csList[IDX_HOCSD_CCY]);
                memcpy(hv_ccy.arr,csList[IDX_HOCSD_CCY],hv_ccy.len);
                ind_ccy = 0;
DEBUGLOG(("Insert ccy = [%.*s]\n",hv_ccy.len,hv_ccy.arr));
        }

//country
	if (strlen(csList[IDX_HOCSD_COUNTRY]) > 0 ) {
                hv_country.len = strlen(csList[IDX_HOCSD_COUNTRY]);
                memcpy(hv_country.arr,csList[IDX_HOCSD_COUNTRY],hv_country.len);
                ind_country = 0;
DEBUGLOG(("Insert country = [%.*s]\n",hv_country.len,hv_country.arr));
        }

//product
	if (strlen(csList[IDX_HOCSD_PRODUCT]) > 0 ) {
                hv_product.len = strlen(csList[IDX_HOCSD_PRODUCT]);
                memcpy(hv_product.arr,csList[IDX_HOCSD_PRODUCT],hv_product.len);
                ind_product = 0;
DEBUGLOG(("Insert product = [%.*s]\n",hv_product.len,hv_product.arr));
        }

//txn_type
	if (strlen(csList[IDX_HOCSD_TXN_TYPE]) > 0 ) {
                hv_txn_type.len = strlen(csList[IDX_HOCSD_TXN_TYPE]);
                memcpy(hv_txn_type.arr,csList[IDX_HOCSD_TXN_TYPE],hv_txn_type.len);
                ind_txn_type = 0;
DEBUGLOG(("Insert txn_type = [%.*s]\n",hv_txn_type.len,hv_txn_type.arr));
        }

//count
        if (strlen(csList[IDX_HOCSD_COUNT]) > 0 ) {
		iTmp = atoi(csList[IDX_HOCSD_COUNT]);
		hv_count = iTmp;
		ind_count = 0;
DEBUGLOG(("Insert count = [%d]\n",hv_count));
        }

//accum_cost_amt
	if (strlen(csList[IDX_HOCSD_ACCUM_COST_AMT]) > 0 ) {
                dTmp = string2double(csList[IDX_HOCSD_ACCUM_COST_AMT]);
                hv_accum_cost_amt = dTmp;
                ind_accum_cost_amt = 0;
DEBUGLOG(("Insert accum_cost_amt = [%.2f]\n",hv_accum_cost_amt));
        }

//accum_refund_amt
	if (strlen(csList[IDX_HOCSD_ACCUM_REFUND_AMT]) > 0 ) {
                dTmp = string2double(csList[IDX_HOCSD_ACCUM_REFUND_AMT]);
                hv_accum_refund_amt = dTmp;
                ind_accum_refund_amt = 0;
DEBUGLOG(("Insert accum_refund_amt = [%.2f]\n",hv_accum_refund_amt));
        }

//accum_void_amt
        if (strlen(csList[IDX_HOCSD_ACCUM_VOID_AMT]) > 0 ) {
                dTmp = string2double(csList[IDX_HOCSD_ACCUM_VOID_AMT]);
                hv_accum_void_amt = dTmp;
                ind_accum_void_amt = 0;
DEBUGLOG(("Insert accum_void_amt = [%.2f]\n",hv_accum_void_amt));
        }

//accum_total_amt
        if (strlen(csList[IDX_HOCSD_ACCUM_TOTAL_AMT]) > 0 ) {
                dTmp = string2double(csList[IDX_HOCSD_ACCUM_TOTAL_AMT]);
                hv_accum_total_amt = dTmp;
                ind_accum_total_amt = 0;
DEBUGLOG(("Insert accum_total_amt = [%.2f]\n",hv_accum_total_amt));
	}

//accum_cost_amt_hkd
        if (strlen(csList[IDX_HOCSD_ACCUM_COST_AMT_HKD]) > 0 ) {
                dTmp = string2double(csList[IDX_HOCSD_ACCUM_COST_AMT_HKD]);
                hv_accum_cost_amt_hkd = dTmp;
                ind_accum_cost_amt_hkd = 0;
DEBUGLOG(("Insert accum_cost_amt_hkd = [%.2f]\n",hv_accum_cost_amt_hkd));
        }

//accum_refund_amt_hkd
        if (strlen(csList[IDX_HOCSD_ACCUM_REFUND_AMT_HKD]) > 0 ) {
                dTmp = string2double(csList[IDX_HOCSD_ACCUM_REFUND_AMT_HKD]);
                hv_accum_refund_amt_hkd = dTmp;
                ind_accum_refund_amt_hkd = 0;
DEBUGLOG(("Insert accum_refund_amt_hkd = [%.2f]\n",hv_accum_refund_amt_hkd));
        }

//accum_void_amt_hkd
        if (strlen(csList[IDX_HOCSD_ACCUM_VOID_AMT_HKD]) > 0 ) {
                dTmp = string2double(csList[IDX_HOCSD_ACCUM_VOID_AMT_HKD]);
                hv_accum_void_amt_hkd = dTmp;
                ind_accum_void_amt_hkd = 0;
DEBUGLOG(("Insert accum_void_amt_hkd = [%.2f]\n",hv_accum_void_amt_hkd));
        }

//accum_total_amt_hkd
        if (strlen(csList[IDX_HOCSD_ACCUM_TOTAL_AMT_HKD]) > 0 ) {
                dTmp = string2double(csList[IDX_HOCSD_ACCUM_TOTAL_AMT_HKD]);
                hv_accum_total_amt_hkd = dTmp;
                ind_accum_total_amt_hkd = 0;
DEBUGLOG(("Insert accum_total_amt_hkd = [%.2f]\n",hv_accum_total_amt_hkd));
        }

//accum_cost_amt_hkd_rate
        if (strlen(csList[IDX_HOCSD_ACCUM_COST_AMT_HKD_RATE]) > 0 ) {
                dTmp = string2double(csList[IDX_HOCSD_ACCUM_COST_AMT_HKD_RATE]);
                hv_accum_cost_amt_hkd_rate = dTmp;
                ind_accum_cost_amt_hkd_rate = 0;
DEBUGLOG(("Insert accum_cost_amt_hkd_rate = [%.5f]\n",hv_accum_cost_amt_hkd_rate));
        }

//accum_cost_amt_usd
        if (strlen(csList[IDX_HOCSD_ACCUM_COST_AMT_USD]) > 0 ) {
                dTmp = string2double(csList[IDX_HOCSD_ACCUM_COST_AMT_USD]);
                hv_accum_cost_amt_usd = dTmp;
                ind_accum_cost_amt_usd = 0;
DEBUGLOG(("Insert accum_cost_amt_usd = [%.2f]\n",hv_accum_cost_amt_usd));
        }

//accum_refund_amt_usd
        if (strlen(csList[IDX_HOCSD_ACCUM_REFUND_AMT_USD]) > 0 ) {
                dTmp = string2double(csList[IDX_HOCSD_ACCUM_REFUND_AMT_USD]);
                hv_accum_refund_amt_usd = dTmp;
                ind_accum_refund_amt_usd = 0;
DEBUGLOG(("Insert accum_refund_amt_usd = [%.2f]\n",hv_accum_refund_amt_usd));
        }

//accum_void_amt_usd
        if (strlen(csList[IDX_HOCSD_ACCUM_VOID_AMT_USD]) > 0 ) {
                dTmp = string2double(csList[IDX_HOCSD_ACCUM_VOID_AMT_USD]);
                hv_accum_void_amt_usd = dTmp;
                ind_accum_void_amt_usd = 0;
DEBUGLOG(("Insert accum_void_amt_usd = [%.2f]\n",hv_accum_void_amt_usd));
        }

//accum_total_amt_usd
        if (strlen(csList[IDX_HOCSD_ACCUM_TOTAL_AMT_USD]) > 0 ) {
                dTmp = string2double(csList[IDX_HOCSD_ACCUM_TOTAL_AMT_USD]);
                hv_accum_total_amt_usd = dTmp;
                ind_accum_total_amt_usd = 0;
DEBUGLOG(("Insert accum_total_amt_usd = [%.2f]\n",hv_accum_total_amt_usd));
        }

//accum_cost_amt_usd_rate
        if (strlen(csList[IDX_HOCSD_ACCUM_COST_AMT_USD_RATE]) > 0 ) {
                dTmp = string2double(csList[IDX_HOCSD_ACCUM_COST_AMT_USD_RATE]);
                hv_accum_cost_amt_usd_rate = dTmp;
                ind_accum_cost_amt_usd_rate = 0;
DEBUGLOG(("Insert accum_cost_amt_usd_rate = [%.5f]\n",hv_accum_cost_amt_usd_rate));
        }


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_histolcostsumdetail_insert(
                                                :hv_batch_id:ind_batch_id,
						:hv_party_type:ind_party_type,
						:hv_entity_id:ind_entity_id,
                                                :hv_entity_name:ind_entity_name,
                                                :hv_client_name:ind_client_name,
                                                :hv_ccy:ind_ccy,
						:hv_country:ind_country,
						:hv_product:ind_product,
						:hv_txn_type:ind_txn_type,
						:hv_count:ind_count,
						:hv_accum_cost_amt:ind_accum_cost_amt,
						:hv_accum_refund_amt:ind_accum_refund_amt,
						:hv_accum_void_amt:ind_accum_void_amt,
						:hv_accum_total_amt:ind_accum_total_amt,
						:hv_accum_cost_amt_hkd:ind_accum_cost_amt_hkd,
						:hv_accum_refund_amt_hkd:ind_accum_refund_amt_hkd,
						:hv_accum_void_amt_hkd:ind_accum_void_amt_hkd,
						:hv_accum_total_amt_hkd:ind_accum_total_amt_hkd,
						:hv_accum_cost_amt_hkd_rate:ind_accum_cost_amt_hkd_rate,
						:hv_accum_cost_amt_usd:ind_accum_cost_amt_usd,
						:hv_accum_refund_amt_usd:ind_accum_refund_amt_usd,
						:hv_accum_void_amt_usd:ind_accum_void_amt_usd,
						:hv_accum_total_amt_usd:ind_accum_total_amt_usd,
                                                :hv_accum_cost_amt_usd_rate:ind_accum_cost_amt_usd_rate);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_histolcostsumdetail_ins\
ert ( :hv_batch_id:ind_batch_id , :hv_party_type:ind_party_type , :hv_entity_\
id:ind_entity_id , :hv_entity_name:ind_entity_name , :hv_client_name:ind_clie\
nt_name , :hv_ccy:ind_ccy , :hv_country:ind_country , :hv_product:ind_product\
 , :hv_txn_type:ind_txn_type , :hv_count:ind_count , :hv_accum_cost_amt:ind_a\
ccum_cost_amt , :hv_accum_refund_amt:ind_accum_refund_amt , :hv_accum_void_am\
t:ind_accum_void_amt , :hv_accum_total_amt:ind_accum_total_amt , :hv_accum_co\
st_amt_hkd:ind_accum_cost_amt_hkd , :hv_accum_refund_amt_hkd:ind_accum_refund\
_amt_hkd , :hv_accum_void_amt_hkd:ind_accum_void_amt_hkd , :hv_accum_total_am\
t_hkd:ind_accum_total_amt_hkd , :hv_accum_cost_amt_hkd_rate:ind_accum_cost_am\
t_hkd_rate , :hv_accum_cost_amt_usd:ind_accum_cost_amt_usd , :hv_accum_refund\
_amt_usd:ind_accum_refund_amt_usd , :hv_accum_void_amt_usd:ind_accum_void_amt\
_usd , :hv_accum_total_amt_usd:ind_accum_total_amt_usd , :hv_accum_cost_amt_u\
sd_rate:ind_accum_cost_amt_usd_rate ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )284;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_batch_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_party_type;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_party_type;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_entity_id;
        sqlstm.sqhstl[3] = (unsigned long )12;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_entity_id;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_entity_name;
        sqlstm.sqhstl[4] = (unsigned long )52;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_entity_name;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_client_name;
        sqlstm.sqhstl[5] = (unsigned long )52;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_client_name;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_ccy;
        sqlstm.sqhstl[6] = (unsigned long )5;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_ccy;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_country;
        sqlstm.sqhstl[7] = (unsigned long )4;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_country;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_product;
        sqlstm.sqhstl[8] = (unsigned long )5;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_product;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_txn_type;
        sqlstm.sqhstl[9] = (unsigned long )5;
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&ind_txn_type;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&hv_count;
        sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)&ind_count;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&hv_accum_cost_amt;
        sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         short *)&ind_accum_cost_amt;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (unsigned char  *)&hv_accum_refund_amt;
        sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         short *)&ind_accum_refund_amt;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned long )0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
        sqlstm.sqhstv[13] = (unsigned char  *)&hv_accum_void_amt;
        sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[13] = (         int  )0;
        sqlstm.sqindv[13] = (         short *)&ind_accum_void_amt;
        sqlstm.sqinds[13] = (         int  )0;
        sqlstm.sqharm[13] = (unsigned long )0;
        sqlstm.sqadto[13] = (unsigned short )0;
        sqlstm.sqtdso[13] = (unsigned short )0;
        sqlstm.sqhstv[14] = (unsigned char  *)&hv_accum_total_amt;
        sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[14] = (         int  )0;
        sqlstm.sqindv[14] = (         short *)&ind_accum_total_amt;
        sqlstm.sqinds[14] = (         int  )0;
        sqlstm.sqharm[14] = (unsigned long )0;
        sqlstm.sqadto[14] = (unsigned short )0;
        sqlstm.sqtdso[14] = (unsigned short )0;
        sqlstm.sqhstv[15] = (unsigned char  *)&hv_accum_cost_amt_hkd;
        sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[15] = (         int  )0;
        sqlstm.sqindv[15] = (         short *)&ind_accum_cost_amt_hkd;
        sqlstm.sqinds[15] = (         int  )0;
        sqlstm.sqharm[15] = (unsigned long )0;
        sqlstm.sqadto[15] = (unsigned short )0;
        sqlstm.sqtdso[15] = (unsigned short )0;
        sqlstm.sqhstv[16] = (unsigned char  *)&hv_accum_refund_amt_hkd;
        sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[16] = (         int  )0;
        sqlstm.sqindv[16] = (         short *)&ind_accum_refund_amt_hkd;
        sqlstm.sqinds[16] = (         int  )0;
        sqlstm.sqharm[16] = (unsigned long )0;
        sqlstm.sqadto[16] = (unsigned short )0;
        sqlstm.sqtdso[16] = (unsigned short )0;
        sqlstm.sqhstv[17] = (unsigned char  *)&hv_accum_void_amt_hkd;
        sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[17] = (         int  )0;
        sqlstm.sqindv[17] = (         short *)&ind_accum_void_amt_hkd;
        sqlstm.sqinds[17] = (         int  )0;
        sqlstm.sqharm[17] = (unsigned long )0;
        sqlstm.sqadto[17] = (unsigned short )0;
        sqlstm.sqtdso[17] = (unsigned short )0;
        sqlstm.sqhstv[18] = (unsigned char  *)&hv_accum_total_amt_hkd;
        sqlstm.sqhstl[18] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[18] = (         int  )0;
        sqlstm.sqindv[18] = (         short *)&ind_accum_total_amt_hkd;
        sqlstm.sqinds[18] = (         int  )0;
        sqlstm.sqharm[18] = (unsigned long )0;
        sqlstm.sqadto[18] = (unsigned short )0;
        sqlstm.sqtdso[18] = (unsigned short )0;
        sqlstm.sqhstv[19] = (unsigned char  *)&hv_accum_cost_amt_hkd_rate;
        sqlstm.sqhstl[19] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[19] = (         int  )0;
        sqlstm.sqindv[19] = (         short *)&ind_accum_cost_amt_hkd_rate;
        sqlstm.sqinds[19] = (         int  )0;
        sqlstm.sqharm[19] = (unsigned long )0;
        sqlstm.sqadto[19] = (unsigned short )0;
        sqlstm.sqtdso[19] = (unsigned short )0;
        sqlstm.sqhstv[20] = (unsigned char  *)&hv_accum_cost_amt_usd;
        sqlstm.sqhstl[20] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[20] = (         int  )0;
        sqlstm.sqindv[20] = (         short *)&ind_accum_cost_amt_usd;
        sqlstm.sqinds[20] = (         int  )0;
        sqlstm.sqharm[20] = (unsigned long )0;
        sqlstm.sqadto[20] = (unsigned short )0;
        sqlstm.sqtdso[20] = (unsigned short )0;
        sqlstm.sqhstv[21] = (unsigned char  *)&hv_accum_refund_amt_usd;
        sqlstm.sqhstl[21] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[21] = (         int  )0;
        sqlstm.sqindv[21] = (         short *)&ind_accum_refund_amt_usd;
        sqlstm.sqinds[21] = (         int  )0;
        sqlstm.sqharm[21] = (unsigned long )0;
        sqlstm.sqadto[21] = (unsigned short )0;
        sqlstm.sqtdso[21] = (unsigned short )0;
        sqlstm.sqhstv[22] = (unsigned char  *)&hv_accum_void_amt_usd;
        sqlstm.sqhstl[22] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[22] = (         int  )0;
        sqlstm.sqindv[22] = (         short *)&ind_accum_void_amt_usd;
        sqlstm.sqinds[22] = (         int  )0;
        sqlstm.sqharm[22] = (unsigned long )0;
        sqlstm.sqadto[22] = (unsigned short )0;
        sqlstm.sqtdso[22] = (unsigned short )0;
        sqlstm.sqhstv[23] = (unsigned char  *)&hv_accum_total_amt_usd;
        sqlstm.sqhstl[23] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[23] = (         int  )0;
        sqlstm.sqindv[23] = (         short *)&ind_accum_total_amt_usd;
        sqlstm.sqinds[23] = (         int  )0;
        sqlstm.sqharm[23] = (unsigned long )0;
        sqlstm.sqadto[23] = (unsigned short )0;
        sqlstm.sqtdso[23] = (unsigned short )0;
        sqlstm.sqhstv[24] = (unsigned char  *)&hv_accum_cost_amt_usd_rate;
        sqlstm.sqhstl[24] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[24] = (         int  )0;
        sqlstm.sqindv[24] = (         short *)&ind_accum_cost_amt_usd_rate;
        sqlstm.sqinds[24] = (         int  )0;
        sqlstm.sqharm[24] = (unsigned long )0;
        sqlstm.sqadto[24] = (unsigned short )0;
        sqlstm.sqtdso[24] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto errorhistolcostsumdetail;
}



	if (hv_return_value == SP_OK) {
		iRet = SUCCESS;
	}
	else {
DEBUGLOG(("error code %d from sp\n", hv_return_value));
		iRet = FAILURE;
	}

        return iRet;

errorhistolcostsumdetail:
DEBUGLOG(("insert_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}


int	InsertHistOlMidBalBatch(char csList[][IMPORT_FIELD_LEN])
{
        int     iRet = SUCCESS;
	int	iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO error_homb_batch; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short		hv_return_value;

		int		hv_batch_id;
                /* varchar		hv_start_ts[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_start_ts;

                /* varchar		hv_end_ts[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_end_ts;

		int		hv_disabled;
                /* varchar		hv_create_ts[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_create_ts;

                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


                short           ind_batch_id = -1;
                short           ind_start_ts = -1;
                short           ind_end_ts = -1;
                short           ind_disabled = -1;
                short           ind_create_ts = -1;
                short           ind_create_user = -1;

        /* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("=== Insert HistOlMidBalBatch2 ===\n"));


//batch_id
        if (strlen(csList[IDX_HOMBB_BATCH_ID]) > 0 ) {
		iTmp = atoi(csList[IDX_HOMBB_BATCH_ID]);
		hv_batch_id = iTmp;
		ind_batch_id = 0;
DEBUGLOG(("Insert batch_id = [%d]\n",hv_batch_id));
        }

//start_ts
        if (strlen(csList[IDX_HOMBB_START_TS]) > 0 ) {
                hv_start_ts.len = strlen(csList[IDX_HOMBB_START_TS]);
                memcpy(hv_start_ts.arr,csList[IDX_HOMBB_START_TS],hv_start_ts.len);
                ind_start_ts = 0;
DEBUGLOG(("Insert start_ts = [%.*s]\n",hv_start_ts.len,hv_start_ts.arr));
        }

//end_ts
        if (strlen(csList[IDX_HOMBB_END_TS]) > 0 ) {
                hv_end_ts.len = strlen(csList[IDX_HOMBB_END_TS]);
                memcpy(hv_end_ts.arr,csList[IDX_HOMBB_END_TS],hv_end_ts.len);
                ind_end_ts = 0;
DEBUGLOG(("Insert end_ts = [%.*s]\n",hv_end_ts.len,hv_end_ts.arr));
        }

//disabled
        if (strlen(csList[IDX_HOMBB_DISABLED]) > 0 ) {
		iTmp = atoi(csList[IDX_HOMBB_DISABLED]);
		hv_disabled = iTmp;
		ind_disabled = 0;
DEBUGLOG(("Insert disabled = [%d]\n",hv_disabled));
        }

//create_ts
        if (strlen(csList[IDX_HOMBB_CREATE_TS]) > 0 ) {
                hv_create_ts.len = strlen(csList[IDX_HOMBB_CREATE_TS]);
                memcpy(hv_create_ts.arr,csList[IDX_HOMBB_CREATE_TS],hv_create_ts.len);
                ind_create_ts = 0;
DEBUGLOG(("Insert create_ts = [%.*s]\n",hv_create_ts.len,hv_create_ts.arr));
        }

//create_user 
	hv_create_user.len = strlen(PD_UPDATE_USER);
	memcpy(hv_create_user.arr,PD_UPDATE_USER,hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("Insert detail create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_histolmidbalbatch_insert(
                                                :hv_batch_id:ind_batch_id,
						:hv_start_ts:ind_start_ts,
						:hv_end_ts:ind_end_ts,
                                                :hv_disabled:ind_disabled,
                                                :hv_create_ts:ind_create_ts,
                                                :hv_create_user:ind_create_user);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_histolmidbalbatch_inser\
t ( :hv_batch_id:ind_batch_id , :hv_start_ts:ind_start_ts , :hv_end_ts:ind_en\
d_ts , :hv_disabled:ind_disabled , :hv_create_ts:ind_create_ts , :hv_create_u\
ser:ind_create_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )399;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_batch_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_start_ts;
        sqlstm.sqhstl[2] = (unsigned long )16;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_start_ts;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_end_ts;
        sqlstm.sqhstl[3] = (unsigned long )16;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_end_ts;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_disabled;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_disabled;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_create_ts;
        sqlstm.sqhstl[5] = (unsigned long )16;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_create_ts;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
        sqlstm.sqhstl[6] = (unsigned long )22;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_create_user;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto error_homb_batch;
}



	if (hv_return_value == SP_OK) {
		iRet = SUCCESS;
	}
	else {
DEBUGLOG(("error code %d from sp\n", hv_return_value));
		iRet = FAILURE;
	}


        return iRet;

error_homb_batch:
DEBUGLOG(("insert_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}


int     InsertHistOlMidBalDetail(char csList[][IMPORT_FIELD_LEN])
{
	int     iRet = SUCCESS;
        int     iTmp;
        double  dTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO errorhistolmidbaldetail; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short           hv_return_value;

                int             hv_batch_id;
                /* varchar         hv_client_id[15]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_client_id;

                /* varchar         hv_mid_id[15]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_mid_id;

                /* varchar         hv_service_code[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                /* varchar         hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

                /* varchar         hv_country[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

                /* varchar         hv_txn_id[16]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

                double          hv_current_bal;
                double          hv_hold_bal;
                double          hv_lien;
                double          hv_merchant_bal;
                double          hv_bal;
                double          hv_bal_hkd;
                double          hv_bal_hkd_rate;
                double          hv_bal_usd;
                double          hv_bal_usd_rate;

		short		ind_batch_id = -1;
		short		ind_client_id = -1;
		short		ind_mid_id = -1;
		short		ind_service_code = -1;
		short		ind_ccy = -1;
		short		ind_country = -1;
		short		ind_txn_id = -1;
		short		ind_current_bal = -1;
		short		ind_hold_bal = -1;
		short		ind_lien = -1;
		short		ind_merchant_bal;
		short		ind_bal = -1;
		short		ind_bal_hkd = -1;
		short		ind_bal_hkd_rate = -1;
		short		ind_bal_usd = -1;
		short		ind_bal_usd_rate = -1;

        /* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("=== Insert HistOlMidBalDetail2 ===\n"));

//batch_id
        if (strlen(csList[IDX_HOMBD_BATCH_ID]) > 0 ) {
                iTmp = atoi(csList[IDX_HOMBD_BATCH_ID]);
                hv_batch_id = iTmp;
                ind_batch_id = 0;
DEBUGLOG(("Insert batch_id = [%d]\n",hv_batch_id));
        }

//client_id
        if (strlen(csList[IDX_HOMBD_CLIENT_ID]) > 0 ) {
                hv_client_id.len = strlen(csList[IDX_HOMBD_CLIENT_ID]);
                memcpy(hv_client_id.arr,csList[IDX_HOMBD_CLIENT_ID],hv_client_id.len);
                ind_client_id = 0;
DEBUGLOG(("Insert client_id = [%.*s]\n",hv_client_id.len,hv_client_id.arr));
        }

//mid_id
        if (strlen(csList[IDX_HOMBD_MID_ID]) > 0 ) {
                hv_mid_id.len = strlen(csList[IDX_HOMBD_MID_ID]);
                memcpy(hv_mid_id.arr,csList[IDX_HOMBD_MID_ID],hv_mid_id.len);
                ind_mid_id = 0;
DEBUGLOG(("Insert mid_id = [%.*s]\n",hv_mid_id.len,hv_mid_id.arr));
        }

//service_code
        if (strlen(csList[IDX_HOMBD_SERVICE_CODE]) > 0 ) {
                hv_service_code.len = strlen(csList[IDX_HOMBD_SERVICE_CODE]);
                memcpy(hv_service_code.arr,csList[IDX_HOMBD_SERVICE_CODE],hv_service_code.len);
                ind_service_code = 0;
DEBUGLOG(("Insert service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));
        }

//ccy
        if (strlen(csList[IDX_HOMBD_CCY]) > 0 ) {
                hv_ccy.len = strlen(csList[IDX_HOMBD_CCY]);
                memcpy(hv_ccy.arr,csList[IDX_HOMBD_CCY],hv_ccy.len);
                ind_ccy = 0;
DEBUGLOG(("Insert ccy = [%.*s]\n",hv_ccy.len,hv_ccy.arr));
        }

//country
        if (strlen(csList[IDX_HOMBD_COUNTRY]) > 0 ) {
                hv_country.len = strlen(csList[IDX_HOMBD_COUNTRY]);
                memcpy(hv_country.arr,csList[IDX_HOMBD_COUNTRY],hv_country.len);
                ind_country = 0;
DEBUGLOG(("Insert country = [%.*s]\n",hv_country.len,hv_country.arr));
        }

//txn_id
        if (strlen(csList[IDX_HOMBD_TXN_ID]) > 0 ) {
                hv_txn_id.len = strlen(csList[IDX_HOMBD_TXN_ID]);
                memcpy(hv_txn_id.arr,csList[IDX_HOMBD_TXN_ID],hv_txn_id.len);
                ind_txn_id = 0;
DEBUGLOG(("Insert txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
        }

//current_bal
        if (strlen(csList[IDX_HOMBD_CURRENT_BAL]) > 0 ) {
                dTmp = string2double(csList[IDX_HOMBD_CURRENT_BAL]);
                hv_current_bal = dTmp;
                ind_current_bal = 0;
DEBUGLOG(("Insert current_bal = [%.2f]\n",hv_current_bal));
        }

//hold_bal
        if (strlen(csList[IDX_HOMBD_HOLD_BAL]) > 0 ) {
                dTmp = string2double(csList[IDX_HOMBD_HOLD_BAL]);
                hv_hold_bal = dTmp;
                ind_hold_bal = 0;
DEBUGLOG(("Insert hold_bal = [%.2f]\n",hv_hold_bal));
        }

//lien
        if (strlen(csList[IDX_HOMBD_LIEN]) > 0 ) {
                dTmp = string2double(csList[IDX_HOMBD_LIEN]);
                hv_lien = dTmp;
                ind_lien = 0;
DEBUGLOG(("Insert lien = [%.2f]\n",hv_lien));
        }

//merchant_bal
        if (strlen(csList[IDX_HOMBD_MERCHANT_BAL]) > 0 ) {
                dTmp = string2double(csList[IDX_HOMBD_MERCHANT_BAL]);
                hv_merchant_bal = dTmp;
                ind_merchant_bal = 0;
DEBUGLOG(("Insert merchant_bal = [%.2f]\n",hv_merchant_bal));
        }

//bal
        if (strlen(csList[IDX_HOMBD_BAL]) > 0 ) {
                dTmp = string2double(csList[IDX_HOMBD_BAL]);
                hv_bal = dTmp;
                ind_bal = 0;
DEBUGLOG(("Insert bal = [%.2f]\n",hv_bal));
        }

//bal_hkd
        if (strlen(csList[IDX_HOMBD_BAL_HKD]) > 0 ) {
                dTmp = string2double(csList[IDX_HOMBD_BAL_HKD]);
                hv_bal_hkd = dTmp;
                ind_bal_hkd = 0;
DEBUGLOG(("Insert bal_hkd = [%.2f]\n",hv_bal_hkd));
        }

//bal_hkd_rate
        if (strlen(csList[IDX_HOMBD_BAL_HKD_RATE]) > 0 ) {
                dTmp = string2double(csList[IDX_HOMBD_BAL_HKD_RATE]);
                hv_bal_hkd_rate = dTmp;
                ind_bal_hkd_rate = 0;
DEBUGLOG(("Insert bal_hkd_rate = [%.5f]\n",hv_bal_hkd_rate));
        }

//bal_usd
        if (strlen(csList[IDX_HOMBD_BAL_USD]) > 0 ) {
                dTmp = string2double(csList[IDX_HOMBD_BAL_USD]);
                hv_bal_usd = dTmp;
                ind_bal_usd = 0;
DEBUGLOG(("Insert bal_usd = [%.2f]\n",hv_bal_usd));
        }

//bal_usd_rate
        if (strlen(csList[IDX_HOMBD_BAL_USD_RATE]) > 0 ) {
                dTmp = string2double(csList[IDX_HOMBD_BAL_USD_RATE]);
                hv_bal_usd_rate = dTmp;
                ind_bal_usd_rate = 0;
DEBUGLOG(("Insert bal_usd_rate = [%.5f]\n",hv_bal_usd_rate));
        }


/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_histolmidbaldetail_insert(
                                                :hv_batch_id:ind_batch_id,
                                                :hv_client_id:ind_client_id,
                                                :hv_mid_id:ind_mid_id,
                                                :hv_service_code:ind_service_code,
                                                :hv_ccy:ind_ccy,
                                                :hv_country:ind_country,
                                                :hv_txn_id:ind_txn_id,
                                                :hv_current_bal:ind_current_bal,
                                                :hv_hold_bal:ind_hold_bal,
                                                :hv_lien:ind_lien,
                                                :hv_merchant_bal:ind_merchant_bal,
                                                :hv_bal:ind_bal,
                                                :hv_bal_hkd:ind_bal_hkd,
                                                :hv_bal_hkd_rate:ind_bal_hkd_rate,
                                                :hv_bal_usd:ind_bal_usd,
                                                :hv_bal_usd_rate:ind_bal_usd_rate);
                END;
        END-EXEC; */ 

{
struct sqlexd sqlstm;
sqlstm.sqlvsn = 12;
sqlstm.arrsiz = 25;
sqlstm.sqladtp = &sqladt;
sqlstm.sqltdsp = &sqltds;
sqlstm.stmt = "begin :hv_return_value := sp_histolmidbaldetail_insert ( :hv\
_batch_id:ind_batch_id , :hv_client_id:ind_client_id , :hv_mid_id:ind_mid_id \
, :hv_service_code:ind_service_code , :hv_ccy:ind_ccy , :hv_country:ind_count\
ry , :hv_txn_id:ind_txn_id , :hv_current_bal:ind_current_bal , :hv_hold_bal:i\
nd_hold_bal , :hv_lien:ind_lien , :hv_merchant_bal:ind_merchant_bal , :hv_bal\
:ind_bal , :hv_bal_hkd:ind_bal_hkd , :hv_bal_hkd_rate:ind_bal_hkd_rate , :hv_\
bal_usd:ind_bal_usd , :hv_bal_usd_rate:ind_bal_usd_rate ) ; END ;";
sqlstm.iters = (unsigned int  )1;
sqlstm.offset = (unsigned int  )442;
sqlstm.cud = sqlcud0;
sqlstm.sqlest = (unsigned char  *)&sqlca;
sqlstm.sqlety = (unsigned short)4352;
sqlstm.occurs = (unsigned int  )0;
sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
sqlstm.sqhsts[0] = (         int  )0;
sqlstm.sqindv[0] = (         short *)0;
sqlstm.sqinds[0] = (         int  )0;
sqlstm.sqharm[0] = (unsigned long )0;
sqlstm.sqadto[0] = (unsigned short )0;
sqlstm.sqtdso[0] = (unsigned short )0;
sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
sqlstm.sqhsts[1] = (         int  )0;
sqlstm.sqindv[1] = (         short *)&ind_batch_id;
sqlstm.sqinds[1] = (         int  )0;
sqlstm.sqharm[1] = (unsigned long )0;
sqlstm.sqadto[1] = (unsigned short )0;
sqlstm.sqtdso[1] = (unsigned short )0;
sqlstm.sqhstv[2] = (unsigned char  *)&hv_client_id;
sqlstm.sqhstl[2] = (unsigned long )17;
sqlstm.sqhsts[2] = (         int  )0;
sqlstm.sqindv[2] = (         short *)&ind_client_id;
sqlstm.sqinds[2] = (         int  )0;
sqlstm.sqharm[2] = (unsigned long )0;
sqlstm.sqadto[2] = (unsigned short )0;
sqlstm.sqtdso[2] = (unsigned short )0;
sqlstm.sqhstv[3] = (unsigned char  *)&hv_mid_id;
sqlstm.sqhstl[3] = (unsigned long )17;
sqlstm.sqhsts[3] = (         int  )0;
sqlstm.sqindv[3] = (         short *)&ind_mid_id;
sqlstm.sqinds[3] = (         int  )0;
sqlstm.sqharm[3] = (unsigned long )0;
sqlstm.sqadto[3] = (unsigned short )0;
sqlstm.sqtdso[3] = (unsigned short )0;
sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
sqlstm.sqhstl[4] = (unsigned long )5;
sqlstm.sqhsts[4] = (         int  )0;
sqlstm.sqindv[4] = (         short *)&ind_service_code;
sqlstm.sqinds[4] = (         int  )0;
sqlstm.sqharm[4] = (unsigned long )0;
sqlstm.sqadto[4] = (unsigned short )0;
sqlstm.sqtdso[4] = (unsigned short )0;
sqlstm.sqhstv[5] = (unsigned char  *)&hv_ccy;
sqlstm.sqhstl[5] = (unsigned long )5;
sqlstm.sqhsts[5] = (         int  )0;
sqlstm.sqindv[5] = (         short *)&ind_ccy;
sqlstm.sqinds[5] = (         int  )0;
sqlstm.sqharm[5] = (unsigned long )0;
sqlstm.sqadto[5] = (unsigned short )0;
sqlstm.sqtdso[5] = (unsigned short )0;
sqlstm.sqhstv[6] = (unsigned char  *)&hv_country;
sqlstm.sqhstl[6] = (unsigned long )4;
sqlstm.sqhsts[6] = (         int  )0;
sqlstm.sqindv[6] = (         short *)&ind_country;
sqlstm.sqinds[6] = (         int  )0;
sqlstm.sqharm[6] = (unsigned long )0;
sqlstm.sqadto[6] = (unsigned short )0;
sqlstm.sqtdso[6] = (unsigned short )0;
sqlstm.sqhstv[7] = (unsigned char  *)&hv_txn_id;
sqlstm.sqhstl[7] = (unsigned long )18;
sqlstm.sqhsts[7] = (         int  )0;
sqlstm.sqindv[7] = (         short *)&ind_txn_id;
sqlstm.sqinds[7] = (         int  )0;
sqlstm.sqharm[7] = (unsigned long )0;
sqlstm.sqadto[7] = (unsigned short )0;
sqlstm.sqtdso[7] = (unsigned short )0;
sqlstm.sqhstv[8] = (unsigned char  *)&hv_current_bal;
sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
sqlstm.sqhsts[8] = (         int  )0;
sqlstm.sqindv[8] = (         short *)&ind_current_bal;
sqlstm.sqinds[8] = (         int  )0;
sqlstm.sqharm[8] = (unsigned long )0;
sqlstm.sqadto[8] = (unsigned short )0;
sqlstm.sqtdso[8] = (unsigned short )0;
sqlstm.sqhstv[9] = (unsigned char  *)&hv_hold_bal;
sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
sqlstm.sqhsts[9] = (         int  )0;
sqlstm.sqindv[9] = (         short *)&ind_hold_bal;
sqlstm.sqinds[9] = (         int  )0;
sqlstm.sqharm[9] = (unsigned long )0;
sqlstm.sqadto[9] = (unsigned short )0;
sqlstm.sqtdso[9] = (unsigned short )0;
sqlstm.sqhstv[10] = (unsigned char  *)&hv_lien;
sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
sqlstm.sqhsts[10] = (         int  )0;
sqlstm.sqindv[10] = (         short *)&ind_lien;
sqlstm.sqinds[10] = (         int  )0;
sqlstm.sqharm[10] = (unsigned long )0;
sqlstm.sqadto[10] = (unsigned short )0;
sqlstm.sqtdso[10] = (unsigned short )0;
sqlstm.sqhstv[11] = (unsigned char  *)&hv_merchant_bal;
sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
sqlstm.sqhsts[11] = (         int  )0;
sqlstm.sqindv[11] = (         short *)&ind_merchant_bal;
sqlstm.sqinds[11] = (         int  )0;
sqlstm.sqharm[11] = (unsigned long )0;
sqlstm.sqadto[11] = (unsigned short )0;
sqlstm.sqtdso[11] = (unsigned short )0;
sqlstm.sqhstv[12] = (unsigned char  *)&hv_bal;
sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
sqlstm.sqhsts[12] = (         int  )0;
sqlstm.sqindv[12] = (         short *)&ind_bal;
sqlstm.sqinds[12] = (         int  )0;
sqlstm.sqharm[12] = (unsigned long )0;
sqlstm.sqadto[12] = (unsigned short )0;
sqlstm.sqtdso[12] = (unsigned short )0;
sqlstm.sqhstv[13] = (unsigned char  *)&hv_bal_hkd;
sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
sqlstm.sqhsts[13] = (         int  )0;
sqlstm.sqindv[13] = (         short *)&ind_bal_hkd;
sqlstm.sqinds[13] = (         int  )0;
sqlstm.sqharm[13] = (unsigned long )0;
sqlstm.sqadto[13] = (unsigned short )0;
sqlstm.sqtdso[13] = (unsigned short )0;
sqlstm.sqhstv[14] = (unsigned char  *)&hv_bal_hkd_rate;
sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
sqlstm.sqhsts[14] = (         int  )0;
sqlstm.sqindv[14] = (         short *)&ind_bal_hkd_rate;
sqlstm.sqinds[14] = (         int  )0;
sqlstm.sqharm[14] = (unsigned long )0;
sqlstm.sqadto[14] = (unsigned short )0;
sqlstm.sqtdso[14] = (unsigned short )0;
sqlstm.sqhstv[15] = (unsigned char  *)&hv_bal_usd;
sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
sqlstm.sqhsts[15] = (         int  )0;
sqlstm.sqindv[15] = (         short *)&ind_bal_usd;
sqlstm.sqinds[15] = (         int  )0;
sqlstm.sqharm[15] = (unsigned long )0;
sqlstm.sqadto[15] = (unsigned short )0;
sqlstm.sqtdso[15] = (unsigned short )0;
sqlstm.sqhstv[16] = (unsigned char  *)&hv_bal_usd_rate;
sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
sqlstm.sqhsts[16] = (         int  )0;
sqlstm.sqindv[16] = (         short *)&ind_bal_usd_rate;
sqlstm.sqinds[16] = (         int  )0;
sqlstm.sqharm[16] = (unsigned long )0;
sqlstm.sqadto[16] = (unsigned short )0;
sqlstm.sqtdso[16] = (unsigned short )0;
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
if (sqlca.sqlcode < 0) goto errorhistolmidbaldetail;
}



	if (hv_return_value == SP_OK) {
		iRet = SUCCESS;
	}
	else {
DEBUGLOG(("error code %d from sp\n", hv_return_value));
		iRet = FAILURE;
	}


        return iRet;

errorhistolmidbaldetail:
DEBUGLOG(("insert_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}


int	InsertOmiHistBalBatch(char csList[][IMPORT_FIELD_LEN])
{
        int     iRet = SUCCESS;
	int	iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO error_ohb_batch; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short		hv_return_value;

		int		hv_batch_id;
                /* varchar		hv_start_ts[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_start_ts;

                /* varchar		hv_end_ts[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_end_ts;

		int		hv_disabled;
                /* varchar		hv_create_ts[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_create_ts;

                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


                short           ind_batch_id = -1;
                short           ind_start_ts = -1;
                short           ind_end_ts = -1;
                short           ind_disabled = -1;
                short           ind_create_ts = -1;
                short           ind_create_user = -1;

        /* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("=== Insert OmiHistBalBatch2 ===\n"));


//batch_id
        if (strlen(csList[IDX_OHBB_BATCH_ID]) > 0 ) {
		iTmp = atoi(csList[IDX_OHBB_BATCH_ID]);
		hv_batch_id = iTmp;
		ind_batch_id = 0;
DEBUGLOG(("Insert batch_id = [%d]\n",hv_batch_id));
        }

//start_ts
        if (strlen(csList[IDX_OHBB_START_TS]) > 0 ) {
                hv_start_ts.len = strlen(csList[IDX_OHBB_START_TS]);
                memcpy(hv_start_ts.arr,csList[IDX_OHBB_START_TS],hv_start_ts.len);
                ind_start_ts = 0;
DEBUGLOG(("Insert start_ts = [%.*s]\n",hv_start_ts.len,hv_start_ts.arr));
        }

//end_ts
        if (strlen(csList[IDX_OHBB_END_TS]) > 0 ) {
                hv_end_ts.len = strlen(csList[IDX_OHBB_END_TS]);
                memcpy(hv_end_ts.arr,csList[IDX_OHBB_END_TS],hv_end_ts.len);
                ind_end_ts = 0;
DEBUGLOG(("Insert end_ts = [%.*s]\n",hv_end_ts.len,hv_end_ts.arr));
        }

//disabled
        if (strlen(csList[IDX_OHBB_DISABLED]) > 0 ) {
		iTmp = atoi(csList[IDX_OHBB_DISABLED]);
		hv_disabled = iTmp;
		ind_disabled = 0;
DEBUGLOG(("Insert disabled = [%d]\n",hv_disabled));
        }

//create_ts
        if (strlen(csList[IDX_OHBB_CREATE_TS]) > 0 ) {
                hv_create_ts.len = strlen(csList[IDX_OHBB_CREATE_TS]);
                memcpy(hv_create_ts.arr,csList[IDX_OHBB_CREATE_TS],hv_create_ts.len);
                ind_create_ts = 0;
DEBUGLOG(("Insert create_ts = [%.*s]\n",hv_create_ts.len,hv_create_ts.arr));
        }

//create_user 
	hv_create_user.len = strlen(PD_UPDATE_USER);
	memcpy(hv_create_user.arr,PD_UPDATE_USER,hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("Insert detail create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_omihistbalbatch_insert(
                                                :hv_batch_id:ind_batch_id,
						:hv_start_ts:ind_start_ts,
						:hv_end_ts:ind_end_ts,
                                                :hv_disabled:ind_disabled,
                                                :hv_create_ts:ind_create_ts,
                                                :hv_create_user:ind_create_user);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_omihistbalbatch_insert \
( :hv_batch_id:ind_batch_id , :hv_start_ts:ind_start_ts , :hv_end_ts:ind_end_\
ts , :hv_disabled:ind_disabled , :hv_create_ts:ind_create_ts , :hv_create_use\
r:ind_create_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )525;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_batch_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_start_ts;
        sqlstm.sqhstl[2] = (unsigned long )16;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_start_ts;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_end_ts;
        sqlstm.sqhstl[3] = (unsigned long )16;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_end_ts;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_disabled;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_disabled;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_create_ts;
        sqlstm.sqhstl[5] = (unsigned long )16;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_create_ts;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
        sqlstm.sqhstl[6] = (unsigned long )22;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_create_user;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto error_ohb_batch;
}



	if (hv_return_value == SP_OK) {
		iRet = SUCCESS;
	}
	else {
DEBUGLOG(("error code %d from sp\n", hv_return_value));
		iRet = FAILURE;
	}


        return iRet;

error_ohb_batch:
DEBUGLOG(("insert_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}


int     InsertOmiHistBalDetail(char csList[][IMPORT_FIELD_LEN])
{
        int     iRet = SUCCESS;
	int	iTmp;
	double	dTmp;
	
	/* EXEC SQL WHENEVER SQLERROR GOTO erroromihistbaldetail; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short		hv_return_value;

		int		hv_batch_id;
                /* varchar		hv_mi_id[10]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_mi_id;

                /* varchar		hv_entity_type[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_entity_type;

                /* varchar		hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

                /* varchar		hv_country[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

                /* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		double		hv_acct_bal;
		double		hv_intransit;
		double		hv_ar_bal;
		double		hv_bal;
		double		hv_bal_hkd;
		double		hv_bal_hkd_rate;
		double		hv_bal_usd;
		double		hv_bal_usd_rate;

                short           ind_batch_id = -1;
		short		ind_mi_id = -1;
		short		ind_entity_type = -1;
		short		ind_ccy = -1;
		short		ind_country = -1;
		short		ind_txn_id = -1;
		short		ind_acct_bal = -1;
		short		ind_intransit = -1;
		short		ind_ar_bal = -1;
		short		ind_bal = -1;
		short		ind_bal_hkd = -1;
		short		ind_bal_hkd_rate = -1;
		short		ind_bal_usd = -1;
		short		ind_bal_usd_rate = -1;
		
        /* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("Insert OmiHistBalDetail2\n"));


//batch_id
        if (strlen(csList[IDX_OHBD_BATCH_ID]) > 0 ) {
		iTmp = atoi(csList[IDX_OHBD_BATCH_ID]);
		hv_batch_id = iTmp;
		ind_batch_id = 0;
DEBUGLOG(("Insert batch_id = [%d]\n",hv_batch_id));
        }

//mi_id
        if (strlen(csList[IDX_OHBD_MI_ID]) > 0 ) {
                hv_mi_id.len = strlen(csList[IDX_OHBD_MI_ID]);
                memcpy(hv_mi_id.arr,csList[IDX_OHBD_MI_ID],hv_mi_id.len);
                ind_mi_id = 0;
DEBUGLOG(("Insert mi_id = [%.*s]\n",hv_mi_id.len,hv_mi_id.arr));
        }

//entity_type
	if (strlen(csList[IDX_OHBD_ENTITY_TYPE]) > 0 ) {
                hv_entity_type.len = strlen(csList[IDX_OHBD_ENTITY_TYPE]);
                memcpy(hv_entity_type.arr,csList[IDX_OHBD_ENTITY_TYPE],hv_entity_type.len);
                ind_entity_type = 0;
DEBUGLOG(("Insert entity_type = [%.*s]\n",hv_entity_type.len,hv_entity_type.arr));
        }

//ccy
	if (strlen(csList[IDX_OHBD_CCY]) > 0 ) {
                hv_ccy.len = strlen(csList[IDX_OHBD_CCY]);
                memcpy(hv_ccy.arr,csList[IDX_OHBD_CCY],hv_ccy.len);
                ind_ccy = 0;
DEBUGLOG(("Insert ccy = [%.*s]\n",hv_ccy.len,hv_ccy.arr));
        }

//country
	if (strlen(csList[IDX_OHBD_COUNTRY]) > 0 ) {
                hv_country.len = strlen(csList[IDX_OHBD_COUNTRY]);
                memcpy(hv_country.arr,csList[IDX_OHBD_COUNTRY],hv_country.len);
                ind_country = 0;
DEBUGLOG(("Insert country = [%.*s]\n",hv_country.len,hv_country.arr));
        }

//txn_id
	if (strlen(csList[IDX_OHBD_TXN_ID]) > 0 ) {
                hv_txn_id.len = strlen(csList[IDX_OHBD_TXN_ID]);
                memcpy(hv_txn_id.arr,csList[IDX_OHBD_TXN_ID],hv_txn_id.len);
                ind_txn_id = 0;
DEBUGLOG(("Insert txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
        }

//acct_bal
	if (strlen(csList[IDX_OHBD_ACCT_BAL]) > 0 ) {
                dTmp = string2double(csList[IDX_OHBD_ACCT_BAL]);
                hv_acct_bal = dTmp;
                ind_acct_bal = 0;
DEBUGLOG(("Insert acct_bal = [%.2f]\n",hv_acct_bal));
        }

//intransit
	if (strlen(csList[IDX_OHBD_INTRANSIT]) > 0 ) {
                dTmp = string2double(csList[IDX_OHBD_INTRANSIT]);
                hv_intransit = dTmp;
                ind_intransit = 0;
DEBUGLOG(("Insert intransit = [%.2f]\n",hv_intransit));
        }

//ar_bal
	if (strlen(csList[IDX_OHBD_AR_BAL]) > 0 ) {
                dTmp = string2double(csList[IDX_OHBD_AR_BAL]);
                hv_ar_bal = dTmp;
                ind_ar_bal = 0;
DEBUGLOG(("Insert ar_bal = [%.2f]\n",hv_ar_bal));
        }

//bal
	if (strlen(csList[IDX_OHBD_BAL]) > 0 ) {
                dTmp = string2double(csList[IDX_OHBD_BAL]);
                hv_bal = dTmp;
                ind_bal = 0;
DEBUGLOG(("Insert bal = [%.2f]\n",hv_bal));
        }

//bal_hkd
	if (strlen(csList[IDX_OHBD_BAL_HKD]) > 0 ) {
                dTmp = string2double(csList[IDX_OHBD_BAL_HKD]);
                hv_bal_hkd = dTmp;
                ind_bal_hkd = 0;
DEBUGLOG(("Insert bal_hkd = [%.2f]\n",hv_bal_hkd));
        }

//bal_hkd_rate
	if (strlen(csList[IDX_OHBD_BAL_HKD_RATE]) > 0 ) {
                dTmp = string2double(csList[IDX_OHBD_BAL_HKD_RATE]);
                hv_bal_hkd_rate = dTmp;
                ind_bal_hkd_rate = 0;
DEBUGLOG(("Insert bal_hkd_rate = [%.5f]\n",hv_bal_hkd_rate));
        }

//bal_usd
	if (strlen(csList[IDX_OHBD_BAL_USD]) > 0 ) {
                dTmp = string2double(csList[IDX_OHBD_BAL_USD]);
                hv_bal_usd = dTmp;
                ind_bal_usd = 0;
DEBUGLOG(("Insert bal_usd = [%.2f]\n",hv_bal_usd));
        }

//bal_usd_rate
	if (strlen(csList[IDX_OHBD_BAL_USD_RATE]) > 0 ) {
                dTmp = string2double(csList[IDX_OHBD_BAL_USD_RATE]);
                hv_bal_usd_rate = dTmp;
                ind_bal_usd_rate = 0;
DEBUGLOG(("Insert bal_usd_rate = [%.5f]\n",hv_bal_usd_rate));
        }


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_omihistbaldetail_insert(
                                                :hv_batch_id:ind_batch_id,
						:hv_mi_id:ind_mi_id,
						:hv_entity_type:ind_entity_type,
                                                :hv_ccy:ind_ccy,
						:hv_country:ind_country,
						:hv_txn_id:ind_txn_id,
						:hv_acct_bal:ind_acct_bal,
						:hv_intransit:ind_intransit,
						:hv_ar_bal:ind_ar_bal,
						:hv_bal:ind_bal,
						:hv_bal_hkd:ind_bal_hkd,
						:hv_bal_hkd_rate:ind_bal_hkd_rate,
						:hv_bal_usd:ind_bal_usd,
						:hv_bal_usd_rate:ind_bal_usd_rate);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_omihistbaldetail_insert\
 ( :hv_batch_id:ind_batch_id , :hv_mi_id:ind_mi_id , :hv_entity_type:ind_enti\
ty_type , :hv_ccy:ind_ccy , :hv_country:ind_country , :hv_txn_id:ind_txn_id ,\
 :hv_acct_bal:ind_acct_bal , :hv_intransit:ind_intransit , :hv_ar_bal:ind_ar_\
bal , :hv_bal:ind_bal , :hv_bal_hkd:ind_bal_hkd , :hv_bal_hkd_rate:ind_bal_hk\
d_rate , :hv_bal_usd:ind_bal_usd , :hv_bal_usd_rate:ind_bal_usd_rate ) ; END \
;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )568;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_batch_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_mi_id;
        sqlstm.sqhstl[2] = (unsigned long )12;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_mi_id;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_entity_type;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_entity_type;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_ccy;
        sqlstm.sqhstl[4] = (unsigned long )5;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_ccy;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_country;
        sqlstm.sqhstl[5] = (unsigned long )4;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_country;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_txn_id;
        sqlstm.sqhstl[6] = (unsigned long )18;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_txn_id;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_acct_bal;
        sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_acct_bal;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_intransit;
        sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_intransit;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_ar_bal;
        sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&ind_ar_bal;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&hv_bal;
        sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)&ind_bal;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&hv_bal_hkd;
        sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         short *)&ind_bal_hkd;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (unsigned char  *)&hv_bal_hkd_rate;
        sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         short *)&ind_bal_hkd_rate;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned long )0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
        sqlstm.sqhstv[13] = (unsigned char  *)&hv_bal_usd;
        sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[13] = (         int  )0;
        sqlstm.sqindv[13] = (         short *)&ind_bal_usd;
        sqlstm.sqinds[13] = (         int  )0;
        sqlstm.sqharm[13] = (unsigned long )0;
        sqlstm.sqadto[13] = (unsigned short )0;
        sqlstm.sqtdso[13] = (unsigned short )0;
        sqlstm.sqhstv[14] = (unsigned char  *)&hv_bal_usd_rate;
        sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[14] = (         int  )0;
        sqlstm.sqindv[14] = (         short *)&ind_bal_usd_rate;
        sqlstm.sqinds[14] = (         int  )0;
        sqlstm.sqharm[14] = (unsigned long )0;
        sqlstm.sqadto[14] = (unsigned short )0;
        sqlstm.sqtdso[14] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto erroromihistbaldetail;
}



	if (hv_return_value == SP_OK) {
		iRet = SUCCESS;
	}
	else {
DEBUGLOG(("error code %d from sp\n", hv_return_value));
		iRet = FAILURE;
	}


        return iRet;

erroromihistbaldetail:
DEBUGLOG(("insert_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}


int	InsertHistBaidBalBatch(char csList[][IMPORT_FIELD_LEN])
{
        int     iRet = SUCCESS;
	int	iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO error_hbbb_batch; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short		hv_return_value;

		int		hv_batch_id;
                /* varchar		hv_start_ts[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_start_ts;

                /* varchar		hv_end_ts[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_end_ts;

		int		hv_disabled;
                /* varchar		hv_create_ts[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_create_ts;

                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


                short           ind_batch_id = -1;
                short           ind_start_ts = -1;
                short           ind_end_ts = -1;
                short           ind_disabled = -1;
                short           ind_create_ts = -1;
                short           ind_create_user = -1;

        /* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("Insert HistBaidBalBatch2\n"));


//batch_id
        if (strlen(csList[IDX_HBBB_BATCH_ID]) > 0 ) {
		iTmp = atoi(csList[IDX_HBBB_BATCH_ID]);
		hv_batch_id = iTmp;
		ind_batch_id = 0;
DEBUGLOG(("Insert batch_id = [%d]\n",hv_batch_id));
        }

//start_ts
        if (strlen(csList[IDX_HBBB_START_TS]) > 0 ) {
                hv_start_ts.len = strlen(csList[IDX_HBBB_START_TS]);
                memcpy(hv_start_ts.arr,csList[IDX_HBBB_START_TS],hv_start_ts.len);
                ind_start_ts = 0;
DEBUGLOG(("Insert start_ts = [%.*s]\n",hv_start_ts.len,hv_start_ts.arr));
        }

//end_ts
        if (strlen(csList[IDX_HBBB_END_TS]) > 0 ) {
                hv_end_ts.len = strlen(csList[IDX_HBBB_END_TS]);
                memcpy(hv_end_ts.arr,csList[IDX_HBBB_END_TS],hv_end_ts.len);
                ind_end_ts = 0;
DEBUGLOG(("Insert end_ts = [%.*s]\n",hv_end_ts.len,hv_end_ts.arr));
        }

//disabled
        if (strlen(csList[IDX_HBBB_DISABLED]) > 0 ) {
		iTmp = atoi(csList[IDX_HBBB_DISABLED]);
		hv_disabled = iTmp;
		ind_disabled = 0;
DEBUGLOG(("Insert disabled = [%d]\n",hv_disabled));
        }

//create_ts
        if (strlen(csList[IDX_HBBB_CREATE_TS]) > 0 ) {
                hv_create_ts.len = strlen(csList[IDX_HBBB_CREATE_TS]);
                memcpy(hv_create_ts.arr,csList[IDX_HBBB_CREATE_TS],hv_create_ts.len);
                ind_create_ts = 0;
DEBUGLOG(("Insert create_ts = [%.*s]\n",hv_create_ts.len,hv_create_ts.arr));
        }

//create_user 
	hv_create_user.len = strlen(PD_UPDATE_USER);
	memcpy(hv_create_user.arr,PD_UPDATE_USER,hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("Insert detail create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_histbaidbalbatch_insert(
                                                :hv_batch_id:ind_batch_id,
						:hv_start_ts:ind_start_ts,
						:hv_end_ts:ind_end_ts,
                                                :hv_disabled:ind_disabled,
                                                :hv_create_ts:ind_create_ts,
                                                :hv_create_user:ind_create_user);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_histbaidbalbatch_insert\
 ( :hv_batch_id:ind_batch_id , :hv_start_ts:ind_start_ts , :hv_end_ts:ind_end\
_ts , :hv_disabled:ind_disabled , :hv_create_ts:ind_create_ts , :hv_create_us\
er:ind_create_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )643;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_batch_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_start_ts;
        sqlstm.sqhstl[2] = (unsigned long )16;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_start_ts;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_end_ts;
        sqlstm.sqhstl[3] = (unsigned long )16;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_end_ts;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_disabled;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_disabled;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_create_ts;
        sqlstm.sqhstl[5] = (unsigned long )16;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_create_ts;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
        sqlstm.sqhstl[6] = (unsigned long )22;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_create_user;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto error_hbbb_batch;
}



	if (hv_return_value == SP_OK) {
		iRet = SUCCESS;
	}
	else {
DEBUGLOG(("error code %d from sp\n", hv_return_value));
		iRet = FAILURE;
	}


        return iRet;

error_hbbb_batch:
DEBUGLOG(("insert_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}


int     InsertHistBaidBalDetail(char csList[][IMPORT_FIELD_LEN])
{
	int     iRet = SUCCESS;
        int     iTmp;
        double  dTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO errorhistbaidbaldetail; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short           hv_return_value;

                int             hv_batch_id;
                /* varchar         hv_pid_id[10]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_pid_id;

                /* varchar         hv_baid[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

                /* varchar         hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

                /* varchar         hv_txn_id[16]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

                double          hv_in_transit;
                double          hv_lien;
                double          hv_available_bal;
                double          hv_bal;
                double          hv_bal_hkd;
                double          hv_bal_hkd_rate;
                double          hv_bal_usd;
                double          hv_bal_usd_rate;
		/* varchar		hv_cat[10]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_cat;

		/* varchar		hv_cat_desc[50]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_cat_desc;

		/* varchar		hv_acct_type[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_acct_type;

		int		hv_in_balance;

		short           ind_batch_id = -1;
                short           ind_pid_id = -1;
                short           ind_baid = -1;
                short           ind_ccy = -1;
                short           ind_txn_id = -1;
                short           ind_in_transit = -1;
                short           ind_lien = -1;
                short           ind_available_bal = -1;
                short           ind_bal = -1;
                short           ind_bal_hkd = -1;
                short           ind_bal_hkd_rate = -1;
                short           ind_bal_usd = -1;
                short           ind_bal_usd_rate = -1;
		short		ind_cat = -1;
		short		ind_cat_desc = -1;
		short		ind_acct_type = -1;
		short		ind_in_balance = -1;

        /* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("Insert HistBaidBalDetail2\n"));

//batch_id
        if (strlen(csList[IDX_HBBD_BATCH_ID]) > 0 ) {
                iTmp = atoi(csList[IDX_HBBD_BATCH_ID]);
                hv_batch_id = iTmp;
                ind_batch_id = 0;
DEBUGLOG(("Insert batch_id = [%d]\n",hv_batch_id));
        }

//pid_id
        if (strlen(csList[IDX_HBBD_PID_ID]) > 0 ) {
                hv_pid_id.len = strlen(csList[IDX_HBBD_PID_ID]);
                memcpy(hv_pid_id.arr,csList[IDX_HBBD_PID_ID],hv_pid_id.len);
                ind_pid_id = 0;
DEBUGLOG(("Insert pid_id = [%.*s]\n",hv_pid_id.len,hv_pid_id.arr));
        }

//baid
        if (strlen(csList[IDX_HBBD_BAID]) > 0 ) {
                hv_baid.len = strlen(csList[IDX_HBBD_BAID]);
                memcpy(hv_baid.arr,csList[IDX_HBBD_BAID],hv_baid.len);
                ind_baid = 0;
DEBUGLOG(("Insert baid = [%.*s]\n",hv_baid.len,hv_baid.arr));
        }

//ccy
        if (strlen(csList[IDX_HBBD_CCY]) > 0 ) {
                hv_ccy.len = strlen(csList[IDX_HBBD_CCY]);
                memcpy(hv_ccy.arr,csList[IDX_HBBD_CCY],hv_ccy.len);
                ind_ccy = 0;
DEBUGLOG(("Insert ccy = [%.*s]\n",hv_ccy.len,hv_ccy.arr));
        }

//txn_id
        if (strlen(csList[IDX_HBBD_TXN_ID]) > 0 ) {
                hv_txn_id.len = strlen(csList[IDX_HBBD_TXN_ID]);
                memcpy(hv_txn_id.arr,csList[IDX_HBBD_TXN_ID],hv_txn_id.len);
                ind_txn_id = 0;
DEBUGLOG(("Insert txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
        }

//in_transit
        if (strlen(csList[IDX_HBBD_IN_TRANSIT]) > 0 ) {
                dTmp = string2double(csList[IDX_HBBD_IN_TRANSIT]);
                hv_in_transit = dTmp;
                ind_in_transit = 0;
DEBUGLOG(("Insert in_transit = [%.2f]\n",hv_in_transit));
        }

//lien
        if (strlen(csList[IDX_HBBD_LIEN]) > 0 ) {
                dTmp = string2double(csList[IDX_HBBD_LIEN]);
                hv_lien = dTmp;
                ind_lien = 0;
DEBUGLOG(("Insert lien = [%.2f]\n",hv_lien));
        }

//available_bal
        if (strlen(csList[IDX_HBBD_AVAILABLE_BAL]) > 0 ) {
                dTmp = string2double(csList[IDX_HBBD_AVAILABLE_BAL]);
                hv_available_bal = dTmp;
                ind_available_bal = 0;
DEBUGLOG(("Insert available_bal = [%.2f]\n",hv_available_bal));
        }

//bal
        if (strlen(csList[IDX_HBBD_BAL]) > 0 ) {
                dTmp = string2double(csList[IDX_HBBD_BAL]);
                hv_bal = dTmp;
                ind_bal = 0;
DEBUGLOG(("Insert bal = [%.2f]\n",hv_bal));
        }

//bal_hkd
        if (strlen(csList[IDX_HBBD_BAL_HKD]) > 0 ) {
                dTmp = string2double(csList[IDX_HBBD_BAL_HKD]);
                hv_bal_hkd = dTmp;
                ind_bal_hkd = 0;
DEBUGLOG(("Insert bal_hkd = [%.2f]\n",hv_bal_hkd));
        }

//bal_hkd_rate
        if (strlen(csList[IDX_HBBD_BAL_HKD_RATE]) > 0 ) {
                dTmp = string2double(csList[IDX_HBBD_BAL_HKD_RATE]);
                hv_bal_hkd_rate = dTmp;
                ind_bal_hkd_rate = 0;
DEBUGLOG(("Insert bal_hkd_rate = [%.5f]\n",hv_bal_hkd_rate));
        }

//bal_usd
        if (strlen(csList[IDX_HBBD_BAL_USD]) > 0 ) {
                dTmp = string2double(csList[IDX_HBBD_BAL_USD]);
                hv_bal_usd = dTmp;
                ind_bal_usd = 0;
DEBUGLOG(("Insert bal_usd = [%.2f]\n",hv_bal_usd));
        }

//bal_usd_rate
        if (strlen(csList[IDX_HBBD_BAL_USD_RATE]) > 0 ) {
                dTmp = string2double(csList[IDX_HBBD_BAL_USD_RATE]);
                hv_bal_usd_rate = dTmp;
                ind_bal_usd_rate = 0;
DEBUGLOG(("Insert bal_usd_rate = [%.5f]\n",hv_bal_usd_rate));
        }

//cat
        if (strlen(csList[IDX_HBBD_CAT]) > 0 ) {
                hv_cat.len = strlen(csList[IDX_HBBD_CAT]);
                memcpy(hv_cat.arr,csList[IDX_HBBD_CAT],hv_cat.len);
                ind_cat = 0;
DEBUGLOG(("Insert cat = [%.*s]\n",hv_cat.len,hv_cat.arr));
        }

//cat_desc
        if (strlen(csList[IDX_HBBD_CAT_DESC]) > 0 ) {
                hv_cat_desc.len = strlen(csList[IDX_HBBD_CAT_DESC]);
                memcpy(hv_cat_desc.arr,csList[IDX_HBBD_CAT_DESC],hv_cat_desc.len);
                ind_cat_desc = 0;
DEBUGLOG(("Insert cat_desc = [%.*s]\n",hv_cat_desc.len,hv_cat_desc.arr));
        }

//acct_type
        if (strlen(csList[IDX_HBBD_ACCT_TYPE]) > 0 ) {
                hv_acct_type.len = strlen(csList[IDX_HBBD_ACCT_TYPE]);
                memcpy(hv_acct_type.arr,csList[IDX_HBBD_ACCT_TYPE],hv_acct_type.len);
                ind_acct_type = 0;
DEBUGLOG(("Insert acct_type = [%.*s]\n",hv_acct_type.len,hv_acct_type.arr));
        }

//in_balance
        if (strlen(csList[IDX_HBBD_IN_BALANCE]) > 0 ) {
                iTmp = atoi(csList[IDX_HBBD_IN_BALANCE]);
                hv_in_balance = iTmp;
                ind_in_balance = 0;
DEBUGLOG(("Insert in_balance = [%d]\n",hv_in_balance));
        }


/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_histbaidbaldetail_insert(
                                                :hv_batch_id:ind_batch_id,
                                                :hv_pid_id:ind_pid_id,
                                                :hv_baid:ind_baid,
                                                :hv_ccy:ind_ccy,
                                                :hv_txn_id:ind_txn_id,
                                                :hv_in_transit:ind_in_transit,
                                                :hv_lien:ind_lien,
                                                :hv_available_bal:ind_available_bal,
                                                :hv_bal:ind_bal,
                                                :hv_bal_hkd:ind_bal_hkd,
                                                :hv_bal_hkd_rate:ind_bal_hkd_rate,
                                                :hv_bal_usd:ind_bal_usd,
                                                :hv_bal_usd_rate:ind_bal_usd_rate,
						:hv_cat:ind_cat,
						:hv_cat_desc:ind_cat_desc,
						:hv_acct_type:ind_acct_type,
						:hv_in_balance:ind_in_balance);
                END;
        END-EXEC; */ 

{
struct sqlexd sqlstm;
sqlstm.sqlvsn = 12;
sqlstm.arrsiz = 25;
sqlstm.sqladtp = &sqladt;
sqlstm.sqltdsp = &sqltds;
sqlstm.stmt = "begin :hv_return_value := sp_histbaidbaldetail_insert ( :hv_\
batch_id:ind_batch_id , :hv_pid_id:ind_pid_id , :hv_baid:ind_baid , :hv_ccy:i\
nd_ccy , :hv_txn_id:ind_txn_id , :hv_in_transit:ind_in_transit , :hv_lien:ind\
_lien , :hv_available_bal:ind_available_bal , :hv_bal:ind_bal , :hv_bal_hkd:i\
nd_bal_hkd , :hv_bal_hkd_rate:ind_bal_hkd_rate , :hv_bal_usd:ind_bal_usd , :h\
v_bal_usd_rate:ind_bal_usd_rate , :hv_cat:ind_cat , :hv_cat_desc:ind_cat_desc\
 , :hv_acct_type:ind_acct_type , :hv_in_balance:ind_in_balance ) ; END ;";
sqlstm.iters = (unsigned int  )1;
sqlstm.offset = (unsigned int  )686;
sqlstm.cud = sqlcud0;
sqlstm.sqlest = (unsigned char  *)&sqlca;
sqlstm.sqlety = (unsigned short)4352;
sqlstm.occurs = (unsigned int  )0;
sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
sqlstm.sqhsts[0] = (         int  )0;
sqlstm.sqindv[0] = (         short *)0;
sqlstm.sqinds[0] = (         int  )0;
sqlstm.sqharm[0] = (unsigned long )0;
sqlstm.sqadto[0] = (unsigned short )0;
sqlstm.sqtdso[0] = (unsigned short )0;
sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
sqlstm.sqhsts[1] = (         int  )0;
sqlstm.sqindv[1] = (         short *)&ind_batch_id;
sqlstm.sqinds[1] = (         int  )0;
sqlstm.sqharm[1] = (unsigned long )0;
sqlstm.sqadto[1] = (unsigned short )0;
sqlstm.sqtdso[1] = (unsigned short )0;
sqlstm.sqhstv[2] = (unsigned char  *)&hv_pid_id;
sqlstm.sqhstl[2] = (unsigned long )12;
sqlstm.sqhsts[2] = (         int  )0;
sqlstm.sqindv[2] = (         short *)&ind_pid_id;
sqlstm.sqinds[2] = (         int  )0;
sqlstm.sqharm[2] = (unsigned long )0;
sqlstm.sqadto[2] = (unsigned short )0;
sqlstm.sqtdso[2] = (unsigned short )0;
sqlstm.sqhstv[3] = (unsigned char  *)&hv_baid;
sqlstm.sqhstl[3] = (unsigned long )22;
sqlstm.sqhsts[3] = (         int  )0;
sqlstm.sqindv[3] = (         short *)&ind_baid;
sqlstm.sqinds[3] = (         int  )0;
sqlstm.sqharm[3] = (unsigned long )0;
sqlstm.sqadto[3] = (unsigned short )0;
sqlstm.sqtdso[3] = (unsigned short )0;
sqlstm.sqhstv[4] = (unsigned char  *)&hv_ccy;
sqlstm.sqhstl[4] = (unsigned long )5;
sqlstm.sqhsts[4] = (         int  )0;
sqlstm.sqindv[4] = (         short *)&ind_ccy;
sqlstm.sqinds[4] = (         int  )0;
sqlstm.sqharm[4] = (unsigned long )0;
sqlstm.sqadto[4] = (unsigned short )0;
sqlstm.sqtdso[4] = (unsigned short )0;
sqlstm.sqhstv[5] = (unsigned char  *)&hv_txn_id;
sqlstm.sqhstl[5] = (unsigned long )18;
sqlstm.sqhsts[5] = (         int  )0;
sqlstm.sqindv[5] = (         short *)&ind_txn_id;
sqlstm.sqinds[5] = (         int  )0;
sqlstm.sqharm[5] = (unsigned long )0;
sqlstm.sqadto[5] = (unsigned short )0;
sqlstm.sqtdso[5] = (unsigned short )0;
sqlstm.sqhstv[6] = (unsigned char  *)&hv_in_transit;
sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
sqlstm.sqhsts[6] = (         int  )0;
sqlstm.sqindv[6] = (         short *)&ind_in_transit;
sqlstm.sqinds[6] = (         int  )0;
sqlstm.sqharm[6] = (unsigned long )0;
sqlstm.sqadto[6] = (unsigned short )0;
sqlstm.sqtdso[6] = (unsigned short )0;
sqlstm.sqhstv[7] = (unsigned char  *)&hv_lien;
sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
sqlstm.sqhsts[7] = (         int  )0;
sqlstm.sqindv[7] = (         short *)&ind_lien;
sqlstm.sqinds[7] = (         int  )0;
sqlstm.sqharm[7] = (unsigned long )0;
sqlstm.sqadto[7] = (unsigned short )0;
sqlstm.sqtdso[7] = (unsigned short )0;
sqlstm.sqhstv[8] = (unsigned char  *)&hv_available_bal;
sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
sqlstm.sqhsts[8] = (         int  )0;
sqlstm.sqindv[8] = (         short *)&ind_available_bal;
sqlstm.sqinds[8] = (         int  )0;
sqlstm.sqharm[8] = (unsigned long )0;
sqlstm.sqadto[8] = (unsigned short )0;
sqlstm.sqtdso[8] = (unsigned short )0;
sqlstm.sqhstv[9] = (unsigned char  *)&hv_bal;
sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
sqlstm.sqhsts[9] = (         int  )0;
sqlstm.sqindv[9] = (         short *)&ind_bal;
sqlstm.sqinds[9] = (         int  )0;
sqlstm.sqharm[9] = (unsigned long )0;
sqlstm.sqadto[9] = (unsigned short )0;
sqlstm.sqtdso[9] = (unsigned short )0;
sqlstm.sqhstv[10] = (unsigned char  *)&hv_bal_hkd;
sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
sqlstm.sqhsts[10] = (         int  )0;
sqlstm.sqindv[10] = (         short *)&ind_bal_hkd;
sqlstm.sqinds[10] = (         int  )0;
sqlstm.sqharm[10] = (unsigned long )0;
sqlstm.sqadto[10] = (unsigned short )0;
sqlstm.sqtdso[10] = (unsigned short )0;
sqlstm.sqhstv[11] = (unsigned char  *)&hv_bal_hkd_rate;
sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
sqlstm.sqhsts[11] = (         int  )0;
sqlstm.sqindv[11] = (         short *)&ind_bal_hkd_rate;
sqlstm.sqinds[11] = (         int  )0;
sqlstm.sqharm[11] = (unsigned long )0;
sqlstm.sqadto[11] = (unsigned short )0;
sqlstm.sqtdso[11] = (unsigned short )0;
sqlstm.sqhstv[12] = (unsigned char  *)&hv_bal_usd;
sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
sqlstm.sqhsts[12] = (         int  )0;
sqlstm.sqindv[12] = (         short *)&ind_bal_usd;
sqlstm.sqinds[12] = (         int  )0;
sqlstm.sqharm[12] = (unsigned long )0;
sqlstm.sqadto[12] = (unsigned short )0;
sqlstm.sqtdso[12] = (unsigned short )0;
sqlstm.sqhstv[13] = (unsigned char  *)&hv_bal_usd_rate;
sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
sqlstm.sqhsts[13] = (         int  )0;
sqlstm.sqindv[13] = (         short *)&ind_bal_usd_rate;
sqlstm.sqinds[13] = (         int  )0;
sqlstm.sqharm[13] = (unsigned long )0;
sqlstm.sqadto[13] = (unsigned short )0;
sqlstm.sqtdso[13] = (unsigned short )0;
sqlstm.sqhstv[14] = (unsigned char  *)&hv_cat;
sqlstm.sqhstl[14] = (unsigned long )12;
sqlstm.sqhsts[14] = (         int  )0;
sqlstm.sqindv[14] = (         short *)&ind_cat;
sqlstm.sqinds[14] = (         int  )0;
sqlstm.sqharm[14] = (unsigned long )0;
sqlstm.sqadto[14] = (unsigned short )0;
sqlstm.sqtdso[14] = (unsigned short )0;
sqlstm.sqhstv[15] = (unsigned char  *)&hv_cat_desc;
sqlstm.sqhstl[15] = (unsigned long )52;
sqlstm.sqhsts[15] = (         int  )0;
sqlstm.sqindv[15] = (         short *)&ind_cat_desc;
sqlstm.sqinds[15] = (         int  )0;
sqlstm.sqharm[15] = (unsigned long )0;
sqlstm.sqadto[15] = (unsigned short )0;
sqlstm.sqtdso[15] = (unsigned short )0;
sqlstm.sqhstv[16] = (unsigned char  *)&hv_acct_type;
sqlstm.sqhstl[16] = (unsigned long )5;
sqlstm.sqhsts[16] = (         int  )0;
sqlstm.sqindv[16] = (         short *)&ind_acct_type;
sqlstm.sqinds[16] = (         int  )0;
sqlstm.sqharm[16] = (unsigned long )0;
sqlstm.sqadto[16] = (unsigned short )0;
sqlstm.sqtdso[16] = (unsigned short )0;
sqlstm.sqhstv[17] = (unsigned char  *)&hv_in_balance;
sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
sqlstm.sqhsts[17] = (         int  )0;
sqlstm.sqindv[17] = (         short *)&ind_in_balance;
sqlstm.sqinds[17] = (         int  )0;
sqlstm.sqharm[17] = (unsigned long )0;
sqlstm.sqadto[17] = (unsigned short )0;
sqlstm.sqtdso[17] = (unsigned short )0;
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
if (sqlca.sqlcode < 0) goto errorhistbaidbaldetail;
}



	if (hv_return_value == SP_OK) {
		iRet = SUCCESS;
	}
	else {
DEBUGLOG(("error code %d from sp\n", hv_return_value));
		iRet = FAILURE;
	}


        return iRet;

errorhistbaidbaldetail:
DEBUGLOG(("insert_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}



int     Delete_HOFS(const char* csDate)
{
        char    *csBuf;

        /* EXEC SQL WHENEVER SQLERROR GOTO del_hofs_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar         hv_dynstmt[PD_TMP_MSG_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[2048]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("=== Delete_HOFS Start ===\n"));
        csBuf = (char*) malloc (PD_TMP_BUF_LEN);

/* delete hist_ol_fee_sum_detail_2 */
        strcpy((char*)hv_dynstmt.arr,"delete from hist_ol_fee_sum_detail_2 where hd_batch_id in (select hb_batch_id from hist_ol_fee_sum_batch_2 where ");

        strcat((char*)hv_dynstmt.arr, "hb_start_date >= to_date('");
        strcat((char*)hv_dynstmt.arr, csDate);
        strcat((char*)hv_dynstmt.arr, "','YYYYMMDD') and ");
        strcat((char*)hv_dynstmt.arr, "hb_end_date < to_date('");
        strcat((char*)hv_dynstmt.arr, csDate);
        strcat((char*)hv_dynstmt.arr, "','YYYYMMDD')+1)");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("delete [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )773;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
        sqlstm.sqhstl[0] = (unsigned long )2050;
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
        if (sqlca.sqlcode < 0) goto del_hofs_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )792;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto del_hofs_error;
}



/* delete hist_ol_fee_sum_batch_2 */
        strcpy((char*)hv_dynstmt.arr,"delete from hist_ol_fee_sum_batch_2 where ");

        strcat((char*)hv_dynstmt.arr, "hb_start_date >= to_date('");
        strcat((char*)hv_dynstmt.arr, csDate);
        strcat((char*)hv_dynstmt.arr, "','YYYYMMDD') and ");
        strcat((char*)hv_dynstmt.arr, "hb_end_date < to_date('");
        strcat((char*)hv_dynstmt.arr, csDate);
        strcat((char*)hv_dynstmt.arr, "','YYYYMMDD')+1");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("delete [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )807;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
        sqlstm.sqhstl[0] = (unsigned long )2050;
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
        if (sqlca.sqlcode < 0) goto del_hofs_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )826;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto del_hofs_error;
}



        return SUCCESS;

del_hofs_error:
DEBUGLOG(("del_hofs_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}


int     Delete_HOBIS(const char* csDate)
{
        char    *csBuf;

        /* EXEC SQL WHENEVER SQLERROR GOTO del_hobis_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar         hv_dynstmt[PD_TMP_MSG_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[2048]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("=== Delete_HOBIS Start ===\n"));
        csBuf = (char*) malloc (PD_TMP_BUF_LEN);

/* delete hist_ol_bt_inter_sum_detail_2 */
        strcpy((char*)hv_dynstmt.arr,"delete from hist_ol_bt_inter_sum_detail_2 where hd_batch_id in (select hb_batch_id from hist_ol_bt_inter_sum_batch_2 where ");

        strcat((char*)hv_dynstmt.arr, "hb_start_date >= to_date('");
        strcat((char*)hv_dynstmt.arr, csDate);
        strcat((char*)hv_dynstmt.arr, "','YYYYMMDD') and ");
        strcat((char*)hv_dynstmt.arr, "hb_end_date < to_date('");
        strcat((char*)hv_dynstmt.arr, csDate);
        strcat((char*)hv_dynstmt.arr, "','YYYYMMDD')+1)");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("delete [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )841;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
        sqlstm.sqhstl[0] = (unsigned long )2050;
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
        if (sqlca.sqlcode < 0) goto del_hobis_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )860;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto del_hobis_error;
}



/* delete hist_ol_bt_inter_sum_batch_2 */
        strcpy((char*)hv_dynstmt.arr,"delete from hist_ol_bt_inter_sum_batch_2 where ");

        strcat((char*)hv_dynstmt.arr, "hb_start_date >= to_date('");
        strcat((char*)hv_dynstmt.arr, csDate);
        strcat((char*)hv_dynstmt.arr, "','YYYYMMDD') and ");
        strcat((char*)hv_dynstmt.arr, "hb_end_date < to_date('");
        strcat((char*)hv_dynstmt.arr, csDate);
        strcat((char*)hv_dynstmt.arr, "','YYYYMMDD')+1");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("delete [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )875;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
        sqlstm.sqhstl[0] = (unsigned long )2050;
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
        if (sqlca.sqlcode < 0) goto del_hobis_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )894;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto del_hobis_error;
}



del_hobis_error:
DEBUGLOG(("del_hobis_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}


int     Delete_HOCS(const char* csDate)
{
        char    *csBuf;

        /* EXEC SQL WHENEVER SQLERROR GOTO del_hocs_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar         hv_dynstmt[PD_TMP_MSG_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[2048]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("=== Delete_HOCS Start ===\n"));
        csBuf = (char*) malloc (PD_TMP_BUF_LEN);

/* delete hist_ol_cost_sum_detail_2 */
        strcpy((char*)hv_dynstmt.arr,"delete from hist_ol_cost_sum_detail_2 where hd_batch_id in (select hb_batch_id from hist_ol_cost_sum_batch_2 where ");

        strcat((char*)hv_dynstmt.arr, "hb_start_date >= to_date('");
        strcat((char*)hv_dynstmt.arr, csDate);
        strcat((char*)hv_dynstmt.arr, "','YYYYMMDD') and ");
        strcat((char*)hv_dynstmt.arr, "hb_end_date < to_date('");
        strcat((char*)hv_dynstmt.arr, csDate);
        strcat((char*)hv_dynstmt.arr, "','YYYYMMDD')+1)");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("delete [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )909;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
        sqlstm.sqhstl[0] = (unsigned long )2050;
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
        if (sqlca.sqlcode < 0) goto del_hocs_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )928;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto del_hocs_error;
}



/* delete hist_ol_cost_sum_batch_2 */
        strcpy((char*)hv_dynstmt.arr,"delete from hist_ol_cost_sum_batch_2 where ");

        strcat((char*)hv_dynstmt.arr, "hb_start_date >= to_date('");
        strcat((char*)hv_dynstmt.arr, csDate);
        strcat((char*)hv_dynstmt.arr, "','YYYYMMDD') and ");
        strcat((char*)hv_dynstmt.arr, "hb_end_date < to_date('");
        strcat((char*)hv_dynstmt.arr, csDate);
        strcat((char*)hv_dynstmt.arr, "','YYYYMMDD')+1");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("delete [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )943;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
        sqlstm.sqhstl[0] = (unsigned long )2050;
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
        if (sqlca.sqlcode < 0) goto del_hocs_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )962;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto del_hocs_error;
}




del_hocs_error:
DEBUGLOG(("del_hocs_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}


int     Delete_HOMB(const char* csDate)
{
        char    *csBuf;

        /* EXEC SQL WHENEVER SQLERROR GOTO del_homb_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar         hv_dynstmt[PD_TMP_MSG_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[2048]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("=== Delete_HOMB Start ===\n"));
        csBuf = (char*) malloc (PD_TMP_BUF_LEN);

/* delete hist_ol_mid_bal_detail_2 */
        strcpy((char*)hv_dynstmt.arr,"delete from hist_ol_mid_bal_detail_2 where hd_batch_id in (select hb_batch_id from hist_ol_mid_bal_batch_2 where ");

        strcat((char*)hv_dynstmt.arr, "hb_start_date >= to_date('");
        strcat((char*)hv_dynstmt.arr, csDate);
        strcat((char*)hv_dynstmt.arr, "','YYYYMMDD') and ");
        strcat((char*)hv_dynstmt.arr, "hb_end_date < to_date('");
        strcat((char*)hv_dynstmt.arr, csDate);
        strcat((char*)hv_dynstmt.arr, "','YYYYMMDD')+1)");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("delete [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )977;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
        sqlstm.sqhstl[0] = (unsigned long )2050;
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
        if (sqlca.sqlcode < 0) goto del_homb_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )996;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto del_homb_error;
}



/* delete hist_ol_mid_bal_batch_2 */
        strcpy((char*)hv_dynstmt.arr,"delete from hist_ol_mid_bal_batch_2 where ");

        strcat((char*)hv_dynstmt.arr, "hb_start_date >= to_date('");
        strcat((char*)hv_dynstmt.arr, csDate);
        strcat((char*)hv_dynstmt.arr, "','YYYYMMDD') and ");
        strcat((char*)hv_dynstmt.arr, "hb_end_date < to_date('");
        strcat((char*)hv_dynstmt.arr, csDate);
        strcat((char*)hv_dynstmt.arr, "','YYYYMMDD')+1");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("delete [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1011;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
        sqlstm.sqhstl[0] = (unsigned long )2050;
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
        if (sqlca.sqlcode < 0) goto del_homb_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1030;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto del_homb_error;
}




del_homb_error:
DEBUGLOG(("del_homb_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}


int     Delete_OHB(const char* csDate)
{
        char    *csBuf;

        /* EXEC SQL WHENEVER SQLERROR GOTO del_ohb_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar         hv_dynstmt[PD_TMP_MSG_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[2048]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("=== Delete_OHB Start ===\n"));
        csBuf = (char*) malloc (PD_TMP_BUF_LEN);

/* delete omi_hist_bal_detail_2 */
        strcpy((char*)hv_dynstmt.arr,"delete from omi_hist_bal_detail_2 where omid_batch_id in (select omi_batch_id from omi_hist_bal_batch_2 where ");

        strcat((char*)hv_dynstmt.arr, "omi_start_date >= to_date('");
        strcat((char*)hv_dynstmt.arr, csDate);
        strcat((char*)hv_dynstmt.arr, "','YYYYMMDD') and ");
        strcat((char*)hv_dynstmt.arr, "omi_end_date < to_date('");
        strcat((char*)hv_dynstmt.arr, csDate);
        strcat((char*)hv_dynstmt.arr, "','YYYYMMDD')+1)");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("delete [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1045;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
        sqlstm.sqhstl[0] = (unsigned long )2050;
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
        if (sqlca.sqlcode < 0) goto del_ohb_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1064;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto del_ohb_error;
}



/* delete omi_hist_bal_batch_2 */
        strcpy((char*)hv_dynstmt.arr,"delete from omi_hist_bal_batch_2 where ");

        strcat((char*)hv_dynstmt.arr, "omi_start_date >= to_date('");
        strcat((char*)hv_dynstmt.arr, csDate);
        strcat((char*)hv_dynstmt.arr, "','YYYYMMDD') and ");
        strcat((char*)hv_dynstmt.arr, "omi_end_date < to_date('");
        strcat((char*)hv_dynstmt.arr, csDate);
        strcat((char*)hv_dynstmt.arr, "','YYYYMMDD')+1");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("delete [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1079;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
        sqlstm.sqhstl[0] = (unsigned long )2050;
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
        if (sqlca.sqlcode < 0) goto del_ohb_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1098;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto del_ohb_error;
}




del_ohb_error:
DEBUGLOG(("del_ohb_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}


int     Delete_HBB(const char* csDate)
{
        char    *csBuf;

        /* EXEC SQL WHENEVER SQLERROR GOTO del_hbb_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar         hv_dynstmt[PD_TMP_MSG_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[2048]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("=== Delete_HBB Start ===\n"));
        csBuf = (char*) malloc (PD_TMP_BUF_LEN);

/* delete hist_baid_bal_detail_2 */
        strcpy((char*)hv_dynstmt.arr,"delete from hist_baid_bal_detail_2 where hd_batch_id in (select hb_batch_id from hist_baid_bal_batch_2 where ");

        strcat((char*)hv_dynstmt.arr, "hb_start_date >= to_date('");
        strcat((char*)hv_dynstmt.arr, csDate);
        strcat((char*)hv_dynstmt.arr, "','YYYYMMDD') and ");
        strcat((char*)hv_dynstmt.arr, "hb_end_date < to_date('");
        strcat((char*)hv_dynstmt.arr, csDate);
        strcat((char*)hv_dynstmt.arr, "','YYYYMMDD')+1)");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("delete [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1113;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
        sqlstm.sqhstl[0] = (unsigned long )2050;
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
        if (sqlca.sqlcode < 0) goto del_hbb_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1132;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto del_hbb_error;
}



/* delete hist_baid_bal_batch_2 */
        strcpy((char*)hv_dynstmt.arr,"delete from hist_baid_bal_batch_2 where ");

        strcat((char*)hv_dynstmt.arr, "hb_start_date >= to_date('");
        strcat((char*)hv_dynstmt.arr, csDate);
        strcat((char*)hv_dynstmt.arr, "','YYYYMMDD') and ");
        strcat((char*)hv_dynstmt.arr, "hb_end_date < to_date('");
        strcat((char*)hv_dynstmt.arr, csDate);
        strcat((char*)hv_dynstmt.arr, "','YYYYMMDD')+1");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("delete [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1147;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
        sqlstm.sqhstl[0] = (unsigned long )2050;
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
        if (sqlca.sqlcode < 0) goto del_hbb_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 25;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1166;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto del_hbb_error;
}




del_hbb_error:
DEBUGLOG(("del_hbb_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}


