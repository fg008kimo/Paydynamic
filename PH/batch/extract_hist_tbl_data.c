
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
           char  filnam[25];
};
static struct sqlcxp sqlfpn =
{
    24,
    "extract_hist_tbl_data.pc"
};


static unsigned int sqlctx = 1283869059;


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
   unsigned char  *sqhstv[24];
   unsigned long  sqhstl[24];
            int   sqhsts[24];
            short *sqindv[24];
            int   sqinds[24];
   unsigned long  sqharm[24];
   unsigned long  *sqharc[24];
   unsigned short  sqadto[24];
   unsigned short  sqtdso[24];
} sqlstm = {12,24};

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
"SELECT HB_BATCH_ID , to_char ( HB_START_DATE , 'yyyymmddhh24miss' ) , to_ch\
ar ( HB_END_DATE , 'yyyymmddhh24miss' ) , HB_DISABLED , to_char ( HB_CREATE_T\
IMESTAMP , 'yyyymmddhh24miss' ) , HB_CREATE_USER FROM HIST_OL_FEE_SUM_BATCH W\
HERE HB_START_DATE >= to_date ( :b0 , 'YYYYMMDD' ) AND HB_END_DATE < to_date \
( :b0 , 'YYYYMMDD' ) + 1 ORDER BY HB_BATCH_ID ASC            ";

 static char *sq0003 = 
"SELECT HD_BATCH_ID , HD_CLIENT_ID , HD_CLIENT_NAME , HD_MERCHANT_ID , HD_ME\
RCHANT_NAME , HD_COUNTRY , HD_SERVICE_CODE , HD_CCY , HD_TXN_CODE , HD_AMT , \
HD_AMT_HKD , HD_AMT_HKD_RATE , HD_AMT_USD , HD_AMT_USD_RATE , HD_TXN_COUNT , \
HD_IS_FEE , HD_IS_MARKUP FROM HIST_OL_FEE_SUM_DETAIL WHERE HD_BATCH_ID IN ( S\
ELECT HB_BATCH_ID FROM HIST_OL_FEE_SUM_BATCH WHERE HB_START_DATE >= to_date (\
 :b0 , 'YYYYMMDD' ) AND HB_END_DATE < to_date ( :b0 , 'YYYYMMDD' ) + 1 ) ORDE\
R BY HD_BATCH_ID , HD_MERCHANT_ID , HD_COUNTRY , HD_SERVICE_CODE , HD_CCY , H\
D_TXN_CODE , HD_IS_FEE , HD_IS_MARKUP            ";

 static char *sq0005 = 
"SELECT HB_BATCH_ID , to_char ( HB_START_DATE , 'yyyymmddhh24miss' ) , to_ch\
ar ( HB_END_DATE , 'yyyymmddhh24miss' ) , HB_DISABLED , to_char ( HB_CREATE_T\
IMESTAMP , 'yyyymmddhh24miss' ) , HB_CREATE_USER FROM HIST_OL_BT_INTER_SUM_BA\
TCH WHERE HB_START_DATE >= to_date ( :b0 , 'YYYYMMDD' ) AND HB_END_DATE < to_\
date ( :b0 , 'YYYYMMDD' ) + 1 ORDER BY HB_BATCH_ID ASC            ";

 static char *sq0007 = 
"SELECT HD_BATCH_ID , HD_CCY , HD_PRODUCT , HD_COUNT , HD_ACCUM_REQ_AMT , HD\
_ACCUM_VOID_AMT , HD_ACCUM_NET_AMT , HD_ACCUM_NET_AMT_HKD , HD_HKD_RATE , HD_\
ACCUM_NET_AMT_USD , HD_USD_RATE FROM HIST_OL_BT_INTER_SUM_DETAIL WHERE HD_BAT\
CH_ID IN ( SELECT HB_BATCH_ID FROM HIST_OL_BT_INTER_SUM_BATCH WHERE HB_START_\
DATE >= to_date ( :b0 , 'YYYYMMDD' ) AND HB_END_DATE < to_date ( :b0 , 'YYYYM\
MDD' ) + 1 ) ORDER BY HD_BATCH_ID , HD_CCY , HD_PRODUCT            ";

 static char *sq0009 = 
"SELECT HB_BATCH_ID , to_char ( HB_START_DATE , 'yyyymmddhh24miss' ) , to_ch\
ar ( HB_END_DATE , 'yyyymmddhh24miss' ) , HB_DISABLED , to_char ( HB_CREATE_T\
IMESTAMP , 'yyyymmddhh24miss' ) , HB_CREATE_USER FROM HIST_OL_COST_SUM_BATCH \
WHERE HB_START_DATE >= to_date ( :b0 , 'YYYYMMDD' ) AND HB_END_DATE < to_date\
 ( :b0 , 'YYYYMMDD' ) + 1 ORDER BY HB_BATCH_ID ASC            ";

 static char *sq0011 = 
"SELECT HD_BATCH_ID , HD_PARTY_TYPE , HD_ENTITY_ID , HD_ENTITY_NAME , HD_CLI\
ENT_NAME , HD_CCY , HD_COUNTRY , HD_PRODUCT , HD_TXN_TYPE , HD_COUNT , HD_ACC\
UM_COST_AMT , HD_ACCUM_REFUND_AMT , HD_ACCUM_VOID_AMT , HD_ACCUM_TOTAL_AMT , \
HD_ACCUM_COST_AMT_HKD , HD_ACCUM_REFUND_AMT_HKD , HD_ACCUM_VOID_AMT_HKD , HD_\
ACCUM_TOTAL_AMT_HKD , HD_ACCUM_COST_AMT_HKD_RATE , HD_ACCUM_COST_AMT_USD , HD\
_ACCUM_REFUND_AMT_USD , HD_ACCUM_VOID_AMT_USD , HD_ACCUM_TOTAL_AMT_USD , HD_A\
CCUM_COST_AMT_USD_RATE FROM HIST_OL_COST_SUM_DETAIL WHERE HD_BATCH_ID IN ( SE\
LECT HB_BATCH_ID FROM HIST_OL_COST_SUM_BATCH WHERE HB_START_DATE >= to_date (\
 :b0 , 'YYYYMMDD' ) AND HB_END_DATE < to_date ( :b0 , 'YYYYMMDD' ) + 1 ) ORDE\
R BY HD_BATCH_ID , HD_PARTY_TYPE , HD_ENTITY_ID , HD_ENTITY_NAME , HD_CCY , H\
D_COUNTRY , HD_PRODUCT , HD_TXN_TYPE            ";

 static char *sq0013 = 
"SELECT HB_BATCH_ID , to_char ( HB_START_DATE , 'yyyymmddhh24miss' ) , to_ch\
ar ( HB_END_DATE , 'yyyymmddhh24miss' ) , HB_DISABLED , to_char ( HB_CREATE_T\
IMESTAMP , 'yyyymmddhh24miss' ) , HB_CREATE_USER FROM HIST_OL_MID_BAL_BATCH W\
HERE HB_START_DATE >= to_date ( :b0 , 'YYYYMMDD' ) AND HB_END_DATE < to_date \
( :b0 , 'YYYYMMDD' ) + 1 ORDER BY HB_BATCH_ID ASC            ";

 static char *sq0015 = 
"SELECT HD_BATCH_ID , HD_CLIENT_ID , HD_MID_ID , HD_SERVICE_CODE , HD_CCY , \
HD_COUNTRY , HD_TXN_ID , HD_CURRENT_BAL , HD_HOLD_BAL , HD_LIEN , HD_MERCHANT\
_BAL , HD_BAL , HD_BAL_HKD , HD_BAL_HKD_RATE , HD_BAL_USD , HD_BAL_USD_RATE F\
ROM HIST_OL_MID_BAL_DETAIL WHERE HD_BATCH_ID IN ( SELECT HB_BATCH_ID FROM HIS\
T_OL_MID_BAL_BATCH WHERE HB_START_DATE >= to_date ( :b0 , 'YYYYMMDD' ) AND HB\
_END_DATE < to_date ( :b0 , 'YYYYMMDD' ) + 1 ) ORDER BY HD_BATCH_ID , HD_CLIE\
NT_ID , HD_MID_ID , HD_SERVICE_CODE , HD_CCY , HD_COUNTRY            ";

 static char *sq0017 = 
"SELECT OMI_BATCH_ID , to_char ( OMI_START_DATE , 'yyyymmddhh24miss' ) , to_\
char ( OMI_END_DATE , 'yyyymmddhh24miss' ) , OMI_DISABLED , to_char ( OMI_CRE\
ATE_TIMESTAMP , 'yyyymmddhh24miss' ) , OMI_CREATE_USER FROM OMI_HIST_BAL_BATC\
H WHERE OMI_START_DATE >= to_date ( :b0 , 'YYYYMMDD' ) AND OMI_END_DATE < to_\
date ( :b0 , 'YYYYMMDD' ) + 1 ORDER BY OMI_BATCH_ID ASC            ";

 static char *sq0019 = 
"SELECT OMID_BATCH_ID , OMID_MI_ID , OMID_ENTITY_TYPE , OMID_CCY , OMID_COUN\
TRY , OMID_TXN_ID , OMID_ACCT_BAL , OMID_INTRANSIT , OMID_AR_BAL , OMID_BAL ,\
 OMID_BAL_HKD , OMID_BAL_HKD_RATE , OMID_BAL_USD , OMID_BAL_USD_RATE FROM OMI\
_HIST_BAL_DETAIL WHERE OMID_BATCH_ID IN ( SELECT OMI_BATCH_ID FROM OMI_HIST_B\
AL_BATCH WHERE OMI_START_DATE >= to_date ( :b0 , 'YYYYMMDD' ) AND OMI_END_DAT\
E < to_date ( :b0 , 'YYYYMMDD' ) + 1 ) ORDER BY OMID_BATCH_ID , OMID_MI_ID , \
OMID_ENTITY_TYPE , OMID_CCY , OMID_COUNTRY            ";

 static char *sq0021 = 
"SELECT HB_BATCH_ID , to_char ( HB_START_DATE , 'yyyymmddhh24miss' ) , to_ch\
ar ( HB_END_DATE , 'yyyymmddhh24miss' ) , HB_DISABLED , to_char ( HB_CREATE_T\
IMESTAMP , 'yyyymmddhh24miss' ) , HB_CREATE_USER FROM HIST_BAID_BAL_BATCH WHE\
RE HB_START_DATE >= to_date ( :b0 , 'YYYYMMDD' ) AND HB_END_DATE < to_date ( \
:b0 , 'YYYYMMDD' ) + 1 ORDER BY HB_BATCH_ID ASC            ";

 static char *sq0023 = 
"SELECT HD_BATCH_ID , HD_PID_ID , HD_BAID , HD_CCY , HD_TXN_ID , HD_IN_TRANS\
IT , HD_LIEN , HD_AVAILABLE_BAL , HD_BAL , HD_BAL_HKD , HD_BAL_HKD_RATE , HD_\
BAL_USD , HD_BAL_USD_RATE , HD_CAT , HD_CAT_DESC , HD_ACCT_TYPE , HD_IN_BALAN\
CE FROM HIST_BAID_BAL_DETAIL WHERE HD_BATCH_ID IN ( SELECT HB_BATCH_ID FROM H\
IST_BAID_BAL_BATCH WHERE HB_START_DATE >= to_date ( :b0 , 'YYYYMMDD' ) AND HB\
_END_DATE < to_date ( :b0 , 'YYYYMMDD' ) + 1 ) ORDER BY HD_BATCH_ID , HD_PID_\
ID , HD_BAID , HD_CCY , HD_CCY            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,367,0,9,303,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
28,0,0,1,0,0,13,305,0,0,6,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,
0,0,
67,0,0,1,0,0,15,361,0,0,0,0,0,1,0,
82,0,0,1,0,0,15,369,0,0,0,0,0,1,0,
97,0,0,2,0,0,32,370,0,0,0,0,0,1,0,
112,0,0,3,586,0,9,451,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
135,0,0,3,0,0,13,453,0,0,17,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,3,0,0,
2,3,0,0,2,3,0,0,
218,0,0,3,0,0,15,590,0,0,0,0,0,1,0,
233,0,0,3,0,0,15,598,0,0,0,0,0,1,0,
248,0,0,4,0,0,32,599,0,0,0,0,0,1,0,
263,0,0,5,372,0,9,646,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
286,0,0,5,0,0,13,648,0,0,6,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,
0,0,
325,0,0,5,0,0,15,704,0,0,0,0,0,1,0,
340,0,0,5,0,0,15,712,0,0,0,0,0,1,0,
355,0,0,6,0,0,32,713,0,0,0,0,0,1,0,
370,0,0,7,450,0,9,776,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
393,0,0,7,0,0,13,778,0,0,11,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,4,0,0,2,
4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
452,0,0,7,0,0,15,867,0,0,0,0,0,1,0,
467,0,0,7,0,0,15,875,0,0,0,0,0,1,0,
482,0,0,8,0,0,32,876,0,0,0,0,0,1,0,
497,0,0,9,368,0,9,923,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
520,0,0,9,0,0,13,925,0,0,6,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,
0,0,
559,0,0,9,0,0,15,981,0,0,0,0,0,1,0,
574,0,0,9,0,0,15,989,0,0,0,0,0,1,0,
589,0,0,10,0,0,32,990,0,0,0,0,0,1,0,
604,0,0,11,816,0,9,1091,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
627,0,0,11,0,0,13,1093,0,0,24,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,
0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
738,0,0,11,0,0,15,1279,0,0,0,0,0,1,0,
753,0,0,11,0,0,15,1287,0,0,0,0,0,1,0,
768,0,0,12,0,0,32,1288,0,0,0,0,0,1,0,
783,0,0,13,367,0,9,1335,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
806,0,0,13,0,0,13,1337,0,0,6,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,
9,0,0,
845,0,0,13,0,0,15,1393,0,0,0,0,0,1,0,
860,0,0,13,0,0,15,1401,0,0,0,0,0,1,0,
875,0,0,14,0,0,32,1402,0,0,0,0,0,1,0,
890,0,0,15,529,0,9,1480,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
913,0,0,15,0,0,13,1482,0,0,16,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,
0,2,4,0,0,
992,0,0,15,0,0,15,1610,0,0,0,0,0,1,0,
1007,0,0,15,0,0,15,1618,0,0,0,0,0,1,0,
1022,0,0,16,0,0,32,1619,0,0,0,0,0,1,0,
1037,0,0,17,373,0,9,1666,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
1060,0,0,17,0,0,13,1668,0,0,6,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,
2,9,0,0,
1099,0,0,17,0,0,15,1724,0,0,0,0,0,1,0,
1114,0,0,17,0,0,15,1732,0,0,0,0,0,1,0,
1129,0,0,18,0,0,32,1733,0,0,0,0,0,1,0,
1144,0,0,19,514,0,9,1804,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
1167,0,0,19,0,0,13,1806,0,0,14,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
1238,0,0,19,0,0,15,1919,0,0,0,0,0,1,0,
1253,0,0,15,0,0,15,1927,0,0,0,0,0,1,0,
1268,0,0,20,0,0,32,1928,0,0,0,0,0,1,0,
1283,0,0,21,365,0,9,1975,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
1306,0,0,21,0,0,13,1977,0,0,6,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,
2,9,0,0,
1345,0,0,21,0,0,15,2033,0,0,0,0,0,1,0,
1360,0,0,21,0,0,15,2041,0,0,0,0,0,1,0,
1375,0,0,22,0,0,32,2042,0,0,0,0,0,1,0,
1390,0,0,23,502,0,9,2123,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
1413,0,0,23,0,0,13,2125,0,0,17,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,3,0,0,
1496,0,0,23,0,0,15,2261,0,0,0,0,0,1,0,
1511,0,0,23,0,0,15,2269,0,0,0,0,0,1,0,
1526,0,0,24,0,0,32,2270,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version					   2016/02/04              Dirk Wong
Add 2 fields HistOlFeeSumDetail			   2016/03/04		   Dirk Wong
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

char	cs_table[PD_CODE_LEN + 1];
char    cs_date[PD_DATE_LEN + 1];

char    cDebug = 'Y';

int parse_arg(int argc,char **argv);
int process_hist_ol_fee_sum_batch(FILE *fp);
int process_hist_ol_fee_sum_detail(FILE *fp);
int process_hist_ol_bt_inter_sum_batch(FILE *fp);
int process_hist_ol_bt_inter_sum_detail(FILE *fp);
int process_hist_ol_cost_sum_batch(FILE *fp);
int process_hist_ol_cost_sum_detail(FILE *fp);
int process_hist_ol_mid_bal_batch(FILE *fp);
int process_hist_ol_mid_bal_detail(FILE *fp);
int process_omi_hist_bal_batch(FILE *fp);
int process_omi_hist_bal_detail(FILE *fp);
int process_hist_baid_bal_batch(FILE *fp);
int process_hist_baid_bal_detail(FILE *fp);

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
        int     iRet = SUCCESS;;
        char    cs_file1[PD_MAX_FILE_LEN + 1];
        char    cs_file2[PD_MAX_FILE_LEN + 1];
        char    cs_file3[PD_MAX_FILE_LEN + 1];
        char    cs_file4[PD_MAX_FILE_LEN + 1];
        char    cs_file5[PD_MAX_FILE_LEN + 1];
        char    cs_file6[PD_MAX_FILE_LEN + 1];
        char    cs_file7[PD_MAX_FILE_LEN + 1];
        char    cs_file8[PD_MAX_FILE_LEN + 1];
        char    cs_file9[PD_MAX_FILE_LEN + 1];
        char    cs_file10[PD_MAX_FILE_LEN + 1];
        char    cs_file11[PD_MAX_FILE_LEN + 1];
        char    cs_file12[PD_MAX_FILE_LEN + 1];
        FILE    *fp1, *fp2, *fp3, *fp4, *fp5, *fp6, *fp7, *fp8, *fp9, *fp10, *fp11, *fp12;

	iRet = parse_arg(argc,argv);
               
        if (iRet != SUCCESS) {
        	printf("usage:  -t Table -d Date\n");
                return (iRet);
        }

DEBUGLOG(("Table prefix [%s]\n",cs_table));
DEBUGLOG(("Start Date [%s]\n",cs_date));

        char    cs_yyyy[PD_YYYY_LEN+1];
        char    cs_yyyymm[PD_YYYY_LEN+PD_MM_LEN+1];
	memset(cs_yyyy,0,sizeof(cs_yyyy));
	memset(cs_yyyymm,0,sizeof(cs_yyyymm));
        strncpy(cs_yyyy,cs_date,4);
        strncpy(cs_yyyymm,cs_date,6);


//HIST_OL_FEE_SUM
	if ( (!strcmp(cs_table, PD_TBL_HOFS)) || (!strcmp(cs_table, PD_TBL_ALL)) ) {
DEBUGLOG(("----- Start HIST_OL_FEE_SUM_BATCH -----\n"));
	        sprintf(cs_file1, "%s/%s/%s/%s/hist_ol_fee_sum_batch_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
	        fp1 = fopen(cs_file1,"w");
	        if (fp1 == NULL) {
DEBUGLOG(("batch_proc:unable to open [%s]\n",cs_file1));
	                return FAILURE;
	        }
	        iRet = process_hist_ol_fee_sum_batch(fp1);
	        fclose(fp1);

DEBUGLOG(("----- Start HIST_OL_FEE_SUM_DETAIL -----\n"));
	        sprintf(cs_file2, "%s/%s/%s/%s/hist_ol_fee_sum_detail_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
	        fp2 = fopen(cs_file2,"w");
	        if (fp2 == NULL) {
DEBUGLOG(("batch_proc:unable to open [%s]\n",cs_file2));
	                return FAILURE;
	        }
	        iRet = process_hist_ol_fee_sum_detail(fp2);
	        fclose(fp2);
	}


//HIST_OL_BT_INTER_SUM
	if ( (!strcmp(cs_table, PD_TBL_HOBIS)) || (!strcmp(cs_table, PD_TBL_ALL)) ) {
DEBUGLOG(("----- Start HIST_OL_BT_INTER_SUM_BATCH -----\n"));
	        sprintf(cs_file3, "%s/%s/%s/%s/hist_ol_bt_inter_sum_batch_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
	        fp3 = fopen(cs_file3,"w");
	        if (fp3 == NULL) {
DEBUGLOG(("batch_proc:unable to open [%s]\n",cs_file3));
	                return FAILURE;
	        }
	        iRet = process_hist_ol_bt_inter_sum_batch(fp3);
	        fclose(fp3);

DEBUGLOG(("----- Start HIST_OL_BT_INTER_SUM_DETAIL -----\n"));
	        sprintf(cs_file4, "%s/%s/%s/%s/hist_ol_bt_inter_sum_detail_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
	        fp4 = fopen(cs_file4,"w");
	        if (fp4 == NULL) {
DEBUGLOG(("batch_proc:unable to open [%s]\n",cs_file4));
	                return FAILURE;
	        }
	        iRet = process_hist_ol_bt_inter_sum_detail(fp4);
	        fclose(fp4);
	}


//HIST_OL_COST_SUM
	if ( (!strcmp(cs_table, PD_TBL_HOCS)) || (!strcmp(cs_table, PD_TBL_ALL)) ) {
DEBUGLOG(("----- Start HIST_OL_COST_SUM_BATCH -----\n"));
	        sprintf(cs_file5, "%s/%s/%s/%s/hist_ol_cost_sum_batch_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
	        fp5 = fopen(cs_file5,"w");
	        if (fp5 == NULL) {
DEBUGLOG(("batch_proc:unable to open [%s]\n",cs_file5));
	                return FAILURE;
	        }
	        iRet = process_hist_ol_cost_sum_batch(fp5);
	        fclose(fp5);

DEBUGLOG(("----- Start HIST_OL_COST_SUM_DETAIL -----\n"));
	        sprintf(cs_file6, "%s/%s/%s/%s/hist_ol_cost_sum_detail_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
	        fp6 = fopen(cs_file6,"w");
	        if (fp6 == NULL) {
DEBUGLOG(("batch_proc:unable to open [%s]\n",cs_file6));
	                return FAILURE;
	        }
	        iRet = process_hist_ol_cost_sum_detail(fp6);
	        fclose(fp6);
	}


//HIST_OL_MID_BAL
	if ( (!strcmp(cs_table, PD_TBL_HOMB)) || (!strcmp(cs_table, PD_TBL_ALL)) ) {
DEBUGLOG(("----- Start HIST_OL_MID_BAL_BATCH -----\n"));
	        sprintf(cs_file7, "%s/%s/%s/%s/hist_ol_mid_bal_batch_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
	        fp7 = fopen(cs_file7,"w");
	        if (fp7 == NULL) {
DEBUGLOG(("batch_proc:unable to open [%s]\n",cs_file7));
	                return FAILURE;
	        }
	        iRet = process_hist_ol_mid_bal_batch(fp7);
	        fclose(fp7);

DEBUGLOG(("----- Start HIST_OL_MID_BAL_DETAIL -----\n"));
	        sprintf(cs_file8, "%s/%s/%s/%s/hist_ol_mid_bal_detail_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
	        fp8 = fopen(cs_file8,"w");
	        if (fp8 == NULL) {
DEBUGLOG(("batch_proc:unable to open [%s]\n",cs_file8));
	                return FAILURE;
	        }
	        iRet = process_hist_ol_mid_bal_detail(fp8);
	        fclose(fp8);
	}


//OMI_HIST_BAL
	if ( (!strcmp(cs_table, PD_TBL_OHB)) || (!strcmp(cs_table, PD_TBL_ALL)) ) {
DEBUGLOG(("----- Start OMI_HIST_BAL_BATCH -----\n"));
	        sprintf(cs_file9, "%s/%s/%s/%s/omi_hist_bal_batch_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
	        fp9 = fopen(cs_file9,"w");
	        if (fp9 == NULL) {
DEBUGLOG(("batch_proc:unable to open [%s]\n",cs_file9));
	                return FAILURE;
	        }
	        iRet = process_omi_hist_bal_batch(fp9);
	        fclose(fp9);

DEBUGLOG(("----- Start OMI_HIST_BAL_DETAIL -----\n"));
	        sprintf(cs_file10, "%s/%s/%s/%s/omi_hist_bal_detail_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
	        fp10 = fopen(cs_file10,"w");
	        if (fp10 == NULL) {
DEBUGLOG(("batch_proc:unable to open [%s]\n",cs_file10));
	                return FAILURE;
	        }
	        iRet = process_omi_hist_bal_detail(fp10);
	        fclose(fp10);
	}


//HIST_BAID_BAL
	if ( (!strcmp(cs_table, PD_TBL_HBB)) || (!strcmp(cs_table, PD_TBL_ALL)) ) {
DEBUGLOG(("----- Start HIST_BAID_BAL_BATCH -----\n"));
	        sprintf(cs_file11, "%s/%s/%s/%s/hist_baid_bal_batch_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
	        fp11 = fopen(cs_file11,"w");
	        if (fp11 == NULL) {
DEBUGLOG(("batch_proc:unable to open [%s]\n",cs_file11));
	                return FAILURE;
	        }
	        iRet = process_hist_baid_bal_batch(fp11);
	        fclose(fp11);

DEBUGLOG(("----- Start HIST_BAID_BAL_DETAIL -----\n"));
	        sprintf(cs_file12, "%s/%s/%s/%s/hist_baid_bal_detail_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
	        fp12 = fopen(cs_file12,"w");
	        if (fp12 == NULL) {
DEBUGLOG(("batch_proc:unable to open [%s]\n",cs_file12));
	                return FAILURE;
	        }
	        iRet = process_hist_baid_bal_detail(fp12);
	        fclose(fp12);
	}


	return iRet;
}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}



int process_hist_ol_fee_sum_batch(FILE *fp)
{               
        int     iRet = SUCCESS;
	char	csTmp[PD_TMP_BUF_LEN+1];

	/* EXEC SQL WHENEVER SQLERROR GOTO error_histolfeesumbatch; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } hv_date;


		int	v_batch_id;
		/* varchar	v_start_ts[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_start_ts;

		/* varchar	v_end_ts[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_end_ts;

		int	v_disabled;
		/* varchar	v_create_ts[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_create_ts;

		/* varchar	v_create_user[PD_USER_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_create_user;


		short	ind_batch_id = -1;
		short	ind_start_ts = -1;
		short	ind_end_ts = -1;
		short	ind_disabled = -1;
		short	ind_create_ts = -1;
		short	ind_create_user = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_date.len = strlen(cs_date);
	memcpy(hv_date.arr,cs_date,hv_date.len);

	/* EXEC SQL DECLARE c_cursor_histolfeesumbatch CURSOR FOR
		SELECT	HB_BATCH_ID,
			to_char(HB_START_DATE,'yyyymmddhh24miss'),
			to_char(HB_END_DATE,'yyyymmddhh24miss'),
			HB_DISABLED,
			to_char(HB_CREATE_TIMESTAMP,'yyyymmddhh24miss'),
			HB_CREATE_USER
		  FROM	HIST_OL_FEE_SUM_BATCH
		 WHERE	HB_START_DATE >= to_date(:hv_date,'YYYYMMDD')
		   AND	HB_END_DATE < to_date(:hv_date,'YYYYMMDD')+1
		ORDER BY
			HB_BATCH_ID ASC; */ 


	/* EXEC SQL OPEN c_cursor_histolfeesumbatch; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
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
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_date;
 sqlstm.sqhstl[1] = (unsigned long )11;
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
 if (sqlca.sqlcode < 0) goto error_histolfeesumbatch;
}


	do {
		/* EXEC SQL FETCH c_cursor_histolfeesumbatch
		INTO	:v_batch_id:ind_batch_id,
			:v_start_ts:ind_start_ts,
			:v_end_ts:ind_end_ts,
			:v_disabled:ind_disabled,
			:v_create_ts:ind_create_ts,
			:v_create_user:ind_create_user; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )28;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_batch_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_start_ts;
  sqlstm.sqhstl[1] = (unsigned long )17;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_start_ts;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_end_ts;
  sqlstm.sqhstl[2] = (unsigned long )17;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_end_ts;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_disabled;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_disabled;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_create_ts;
  sqlstm.sqhstl[4] = (unsigned long )17;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_create_ts;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_create_user;
  sqlstm.sqhstl[5] = (unsigned long )23;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_create_user;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto error_histolfeesumbatch;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

/* Field #0 batch_id */
		if (ind_batch_id >= 0) {
			fprintf(fp,"%d%c",v_batch_id,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #1 start_ts */
		if (ind_start_ts >= 0) {
			sprintf(csTmp,"%.*s",v_start_ts.len,v_start_ts.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #2 end_ts */
		if (ind_end_ts >= 0) {
			sprintf(csTmp,"%.*s",v_end_ts.len,v_end_ts.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #3 disabled */
		if (ind_disabled >= 0) {
			fprintf(fp,"%d%c",v_disabled,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #4 create_ts */
		if (ind_create_ts >= 0) {
			sprintf(csTmp,"%.*s",v_create_ts.len,v_create_ts.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #5 create_user */
		if (ind_create_user>= 0) {
			sprintf(csTmp,"%.*s",v_create_user.len,v_create_user.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* new line */
		fprintf(fp,"\n");

 	} while (PD_TRUE);
	/* EXEC SQL CLOSE c_cursor_histolfeesumbatch; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )67;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto error_histolfeesumbatch;
}



        return iRet;

error_histolfeesumbatch:
DEBUGLOG(("hist_ol_fee_sum_batch error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_histolfeesumbatch; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 6;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )82;
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
    sqlstm.arrsiz = 6;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )97;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int process_hist_ol_fee_sum_detail(FILE *fp)
{ 
        int     iRet = SUCCESS;
	char	csTmp[PD_TMP_BUF_LEN+1];

	/* EXEC SQL WHENEVER SQLERROR GOTO error_histolfeesumdetail; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } hv_date;


		int	v_batch_id;
		/* varchar	v_client_id[10+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_client_id;

		/* varchar	v_client_name[50+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_client_name;

		/* varchar	v_merchant_id[PD_MERCHANT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar	v_merchant_name[20+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_merchant_name;

		/* varchar	v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		/* varchar	v_service_code[PD_SERVICE_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		/* varchar	v_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ccy;

		/* varchar	v_txn_code[PD_TXN_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

		double	v_amt;
		double	v_amt_hkd;
		double	v_amt_hkd_rate;
		double	v_amt_usd;
		double	v_amt_usd_rate;
		int	v_txn_count;
		int	v_is_fee;
		int	v_is_markup;

		short	ind_batch_id = -1;
		short	ind_client_id = -1;
		short	ind_client_name = -1;
		short	ind_merchant_id = -1;
		short	ind_merchant_name = -1;
		short	ind_country = -1;
		short	ind_service_code = -1;
		short	ind_ccy = -1;
		short	ind_txn_code = -1;
		short	ind_amt = -1;
		short	ind_amt_hkd = -1;
		short	ind_amt_hkd_rate = -1;
		short	ind_amt_usd = -1;
		short	ind_amt_usd_rate = -1;
		short	ind_txn_count = -1;
		short	ind_is_fee = -1;
		short	ind_is_markup = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_date.len = strlen(cs_date);
	memcpy(hv_date.arr,cs_date,hv_date.len);

	/* EXEC SQL DECLARE c_cursor_histolfeesumdetail CURSOR FOR
		SELECT	HD_BATCH_ID,
			HD_CLIENT_ID,
			HD_CLIENT_NAME,
			HD_MERCHANT_ID,
			HD_MERCHANT_NAME,
			HD_COUNTRY, 
			HD_SERVICE_CODE, 
			HD_CCY, 
			HD_TXN_CODE, 
			HD_AMT, 
			HD_AMT_HKD, 
			HD_AMT_HKD_RATE,
			HD_AMT_USD, 
			HD_AMT_USD_RATE, 
			HD_TXN_COUNT, 
			HD_IS_FEE, 
			HD_IS_MARKUP 
		  FROM	HIST_OL_FEE_SUM_DETAIL
		 WHERE	HD_BATCH_ID IN (SELECT HB_BATCH_ID FROM HIST_OL_FEE_SUM_BATCH
					 WHERE HB_START_DATE >= to_date(:hv_date,'YYYYMMDD')
					   AND HB_END_DATE < to_date(:hv_date,'YYYYMMDD')+1)
		ORDER BY
			HD_BATCH_ID, HD_MERCHANT_ID, HD_COUNTRY, HD_SERVICE_CODE, HD_CCY, HD_TXN_CODE, HD_IS_FEE, HD_IS_MARKUP; */ 


	/* EXEC SQL OPEN c_cursor_histolfeesumdetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )112;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_date;
 sqlstm.sqhstl[1] = (unsigned long )11;
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
 if (sqlca.sqlcode < 0) goto error_histolfeesumdetail;
}


	do {
		/* EXEC SQL FETCH c_cursor_histolfeesumdetail
		INTO	:v_batch_id:ind_batch_id,
			:v_client_id:ind_client_id,
			:v_client_name:ind_client_name,
			:v_merchant_id:ind_merchant_id,
			:v_merchant_name:ind_merchant_name,
			:v_country:ind_country,
			:v_service_code:ind_service_code,
			:v_ccy:ind_ccy,
			:v_txn_code:ind_txn_code,
			:v_amt:ind_amt,
			:v_amt_hkd:ind_amt_hkd,
			:v_amt_hkd_rate:ind_amt_hkd_rate,
			:v_amt_usd:ind_amt_usd,
			:v_amt_usd_rate:ind_amt_usd_rate,
			:v_txn_count:ind_txn_count,
			:v_is_fee:ind_is_fee,
			:v_is_markup:ind_is_markup; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )135;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_batch_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_client_id;
  sqlstm.sqhstl[1] = (unsigned long )13;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_client_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_client_name;
  sqlstm.sqhstl[2] = (unsigned long )53;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_client_name;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_merchant_id;
  sqlstm.sqhstl[3] = (unsigned long )18;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_merchant_id;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_merchant_name;
  sqlstm.sqhstl[4] = (unsigned long )23;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_merchant_name;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_country;
  sqlstm.sqhstl[5] = (unsigned long )5;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_country;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_service_code;
  sqlstm.sqhstl[6] = (unsigned long )6;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_service_code;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_ccy;
  sqlstm.sqhstl[7] = (unsigned long )6;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_ccy;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_txn_code;
  sqlstm.sqhstl[8] = (unsigned long )6;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_txn_code;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_amt;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_amt;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_amt_hkd;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_amt_hkd;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_amt_hkd_rate;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_amt_hkd_rate;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_amt_usd;
  sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_amt_usd;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_amt_usd_rate;
  sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_amt_usd_rate;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_txn_count;
  sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_txn_count;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_is_fee;
  sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_is_fee;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&v_is_markup;
  sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)&ind_is_markup;
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
  if (sqlca.sqlcode < 0) goto error_histolfeesumdetail;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

/* Field #0 batch_id */
		if (ind_batch_id >= 0) {
			fprintf(fp,"%d%c",v_batch_id,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #1 client_id */
		if (ind_client_id >= 0) {
			sprintf(csTmp,"%.*s",v_client_id.len,v_client_id.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #2 client_name */
		if (ind_client_name >= 0) {
			sprintf(csTmp,"%.*s",v_client_name.len,v_client_name.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #3 merchant_id */
		if (ind_merchant_id >= 0) {
			sprintf(csTmp,"%.*s",v_merchant_id.len,v_merchant_id.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #4 merchant_name */
		if (ind_merchant_name >= 0) {
			sprintf(csTmp,"%.*s",v_merchant_name.len,v_merchant_name.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #5 country */
		if (ind_country >= 0) {
			sprintf(csTmp,"%.*s",v_country.len,v_country.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #6 service_code */
		if (ind_service_code >= 0) {
			sprintf(csTmp,"%.*s",v_service_code.len,v_service_code.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #7 ccy */
		if (ind_ccy >= 0) {
			sprintf(csTmp,"%.*s",v_ccy.len,v_ccy.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #8 txn_code */
		if (ind_txn_code >= 0) {
			sprintf(csTmp,"%.*s",v_txn_code.len,v_txn_code.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #9 amt */
		if (ind_amt >= 0) {
			fprintf(fp,"%.2f%c",v_amt,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #10 amt_hkd */
		if (ind_amt_hkd >= 0) {
			fprintf(fp,"%.2f%c",v_amt_hkd,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #11 amt_hkd_rate */
		if (ind_amt_hkd_rate >= 0) {
			fprintf(fp,"%.5f%c",v_amt_hkd_rate,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #12 amt_usd */
		if (ind_amt_usd >= 0) {
			fprintf(fp,"%.2f%c",v_amt_usd,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #13 amt_usd_rate */
		if (ind_amt_usd_rate >= 0) {
			fprintf(fp,"%.5f%c",v_amt_usd_rate,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #14 txn_count */
		if (ind_txn_count >= 0) {
			fprintf(fp,"%d%c",v_txn_count,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #15 is_fee */
		if (ind_is_fee >= 0) {
			fprintf(fp,"%d%c",v_is_fee,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #16 is_markup */
		if (ind_is_markup >= 0) {
			fprintf(fp,"%d%c",v_is_markup,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* new line */
		fprintf(fp,"\n");

 	} while (PD_TRUE);
	/* EXEC SQL CLOSE c_cursor_histolfeesumdetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )218;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto error_histolfeesumdetail;
}



        return iRet;

error_histolfeesumdetail:
DEBUGLOG(("hist_ol_fee_sum_detail error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_histolfeesumdetail; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )233;
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
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )248;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int process_hist_ol_bt_inter_sum_batch(FILE *fp)
{               
        int     iRet = SUCCESS;
	char	csTmp[PD_TMP_BUF_LEN+1];

	/* EXEC SQL WHENEVER SQLERROR GOTO error_histolbtintersumbatch; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } hv_date;


		int	v_batch_id;
		/* varchar	v_start_ts[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_start_ts;

		/* varchar	v_end_ts[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_end_ts;

		int	v_disabled;
		/* varchar	v_create_ts[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_create_ts;

		/* varchar	v_create_user[PD_USER_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_create_user;


		short	ind_batch_id = -1;
		short	ind_start_ts = -1;
		short	ind_end_ts = -1;
		short	ind_disabled = -1;
		short	ind_create_ts = -1;
		short	ind_create_user = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_date.len = strlen(cs_date);
	memcpy(hv_date.arr,cs_date,hv_date.len);

	/* EXEC SQL DECLARE c_cursor_histolbtintersumbatch CURSOR FOR
		SELECT	HB_BATCH_ID,
			to_char(HB_START_DATE,'yyyymmddhh24miss'),
			to_char(HB_END_DATE,'yyyymmddhh24miss'),
			HB_DISABLED,
			to_char(HB_CREATE_TIMESTAMP,'yyyymmddhh24miss'),
			HB_CREATE_USER
		  FROM	HIST_OL_BT_INTER_SUM_BATCH
		 WHERE	HB_START_DATE >= to_date(:hv_date,'YYYYMMDD')
		   AND	HB_END_DATE < to_date(:hv_date,'YYYYMMDD')+1
		ORDER BY
			HB_BATCH_ID ASC; */ 


	/* EXEC SQL OPEN c_cursor_histolbtintersumbatch; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0005;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )263;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_date;
 sqlstm.sqhstl[1] = (unsigned long )11;
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
 if (sqlca.sqlcode < 0) goto error_histolbtintersumbatch;
}


	do {
		/* EXEC SQL FETCH c_cursor_histolbtintersumbatch
		INTO	:v_batch_id:ind_batch_id,
			:v_start_ts:ind_start_ts,
			:v_end_ts:ind_end_ts,
			:v_disabled:ind_disabled,
			:v_create_ts:ind_create_ts,
			:v_create_user:ind_create_user; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )286;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_batch_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_start_ts;
  sqlstm.sqhstl[1] = (unsigned long )17;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_start_ts;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_end_ts;
  sqlstm.sqhstl[2] = (unsigned long )17;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_end_ts;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_disabled;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_disabled;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_create_ts;
  sqlstm.sqhstl[4] = (unsigned long )17;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_create_ts;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_create_user;
  sqlstm.sqhstl[5] = (unsigned long )23;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_create_user;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto error_histolbtintersumbatch;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

/* Field #0 batch_id */
		if (ind_batch_id >= 0) {
			fprintf(fp,"%d%c",v_batch_id,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #1 start_ts */
		if (ind_start_ts >= 0) {
			sprintf(csTmp,"%.*s",v_start_ts.len,v_start_ts.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #2 end_ts */
		if (ind_end_ts >= 0) {
			sprintf(csTmp,"%.*s",v_end_ts.len,v_end_ts.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #3 disabled */
		if (ind_disabled >= 0) {
			fprintf(fp,"%d%c",v_disabled,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #4 create_ts */
		if (ind_create_ts >= 0) {
			sprintf(csTmp,"%.*s",v_create_ts.len,v_create_ts.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #5 create_user */
		if (ind_create_user>= 0) {
			sprintf(csTmp,"%.*s",v_create_user.len,v_create_user.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* new line */
		fprintf(fp,"\n");

 	} while (PD_TRUE);
	/* EXEC SQL CLOSE c_cursor_histolbtintersumbatch; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )325;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto error_histolbtintersumbatch;
}



        return iRet;

error_histolbtintersumbatch:
DEBUGLOG(("hist_ol_bt_inter_sum_batch error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_histolbtintersumbatch; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )340;
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
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )355;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int process_hist_ol_bt_inter_sum_detail(FILE *fp)
{
        int     iRet = SUCCESS;
	char	csTmp[PD_TMP_BUF_LEN+1];

	/* EXEC SQL WHENEVER SQLERROR GOTO err_histolbtintersumdetail; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } hv_date;


		int	v_batch_id;
		/* varchar	v_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ccy;

		/* varchar	v_product[PD_PRODUCT_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_product;

		int	v_count;
		double	v_accum_req_amt;
		double	v_accum_void_amt;
		double	v_accum_net_amt;
		double	v_accum_net_amt_hkd;
		double	v_hkd_rate;
		double	v_accum_net_amt_usd;
		double	v_usd_rate;

		short	ind_batch_id = -1;
		short	ind_ccy = -1;
		short	ind_product = -1;
		short	ind_count = -1;
		short	ind_accum_req_amt = -1;
		short	ind_accum_void_amt = -1;
		short	ind_accum_net_amt = -1;
		short	ind_accum_net_amt_hkd = -1;
		short	ind_hkd_rate = -1;
		short	ind_accum_net_amt_usd = -1;
		short	ind_usd_rate = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_date.len = strlen(cs_date);
	memcpy(hv_date.arr,cs_date,hv_date.len);

	/* EXEC SQL DECLARE c_histolbtintersumdetail CURSOR FOR
		SELECT	HD_BATCH_ID,
			HD_CCY,
			HD_PRODUCT, 
			HD_COUNT, 
			HD_ACCUM_REQ_AMT,
			HD_ACCUM_VOID_AMT, 
			HD_ACCUM_NET_AMT, 
			HD_ACCUM_NET_AMT_HKD, 
			HD_HKD_RATE, 
			HD_ACCUM_NET_AMT_USD, 
			HD_USD_RATE 
		  FROM	HIST_OL_BT_INTER_SUM_DETAIL
		 WHERE	HD_BATCH_ID IN (SELECT HB_BATCH_ID FROM HIST_OL_BT_INTER_SUM_BATCH
					 WHERE HB_START_DATE >= to_date(:hv_date,'YYYYMMDD')
					   AND HB_END_DATE < to_date(:hv_date,'YYYYMMDD')+1)
		ORDER BY
			HD_BATCH_ID, HD_CCY, HD_PRODUCT; */ 


	/* EXEC SQL OPEN c_histolbtintersumdetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0007;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )370;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_date;
 sqlstm.sqhstl[1] = (unsigned long )11;
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
 if (sqlca.sqlcode < 0) goto err_histolbtintersumdetail;
}


	do {
		/* EXEC SQL FETCH c_histolbtintersumdetail
		INTO	:v_batch_id:ind_batch_id,
			:v_ccy:ind_ccy,
			:v_product:ind_product,
			:v_count:ind_count,
			:v_accum_req_amt:ind_accum_req_amt,
			:v_accum_void_amt:ind_accum_void_amt,
			:v_accum_net_amt:ind_accum_net_amt,
			:v_accum_net_amt_hkd:ind_accum_net_amt_hkd,
			:v_hkd_rate:ind_hkd_rate,
			:v_accum_net_amt_usd:ind_accum_net_amt_usd,
			:v_usd_rate:ind_usd_rate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )393;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_batch_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_ccy;
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_ccy;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_product;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_count;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_count;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_accum_req_amt;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_accum_req_amt;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_accum_void_amt;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_accum_void_amt;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_accum_net_amt;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_accum_net_amt;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_accum_net_amt_hkd;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_accum_net_amt_hkd;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_hkd_rate;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_hkd_rate;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_accum_net_amt_usd;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_accum_net_amt_usd;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_usd_rate;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_usd_rate;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto err_histolbtintersumdetail;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

/* Field #0 batch_id */
		if (ind_batch_id >= 0) {
			fprintf(fp,"%d%c",v_batch_id,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #1 ccy */
		if (ind_ccy >= 0) {
			sprintf(csTmp,"%.*s",v_ccy.len,v_ccy.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #2 product */
		if (ind_product >= 0) {
			sprintf(csTmp,"%.*s",v_product.len,v_product.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #3 count */
		if (ind_count >= 0) {
			fprintf(fp,"%d%c",v_count,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #4 accum_req_amt */
		if (ind_accum_req_amt >= 0) {
			fprintf(fp,"%.2f%c",v_accum_req_amt,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #5 accum_void_amt */
		if (ind_accum_void_amt >= 0) {
			fprintf(fp,"%.2f%c",v_accum_void_amt,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #6 accum_net_amt */
		if (ind_accum_net_amt >= 0) {
			fprintf(fp,"%.2f%c",v_accum_net_amt,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #7 accum_net_amt_hkd */
		if (ind_accum_net_amt_hkd >= 0) {
			fprintf(fp,"%.2f%c",v_accum_net_amt_hkd,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #8 hkd_rate */
		if (ind_hkd_rate >= 0) {
			fprintf(fp,"%.5f%c",v_hkd_rate,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #9 accum_net_amt_usd */
		if (ind_accum_net_amt_usd >= 0) {
			fprintf(fp,"%.2f%c",v_accum_net_amt_usd,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #10 usd_rate */
		if (ind_usd_rate >= 0) {
			fprintf(fp,"%.5f%c",v_usd_rate,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* new line */
		fprintf(fp,"\n");

 	} while (PD_TRUE);
	/* EXEC SQL CLOSE c_histolbtintersumdetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )452;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto err_histolbtintersumdetail;
}



        return iRet;

err_histolbtintersumdetail:
DEBUGLOG(("hist_ol_bt_inter_sum_detail error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_histolbtintersumdetail; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )467;
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
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )482;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int process_hist_ol_cost_sum_batch(FILE *fp)
{               
        int     iRet = SUCCESS;
	char	csTmp[PD_TMP_BUF_LEN+1];

	/* EXEC SQL WHENEVER SQLERROR GOTO error_histolcostsumbatch; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } hv_date;


		int	v_batch_id;
		/* varchar	v_start_ts[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_start_ts;

		/* varchar	v_end_ts[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_end_ts;

		int	v_disabled;
		/* varchar	v_create_ts[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_create_ts;

		/* varchar	v_create_user[PD_USER_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_create_user;


		short	ind_batch_id = -1;
		short	ind_start_ts = -1;
		short	ind_end_ts = -1;
		short	ind_disabled = -1;
		short	ind_create_ts = -1;
		short	ind_create_user = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_date.len = strlen(cs_date);
	memcpy(hv_date.arr,cs_date,hv_date.len);

	/* EXEC SQL DECLARE c_cursor_histolcostsumbatch CURSOR FOR
		SELECT	HB_BATCH_ID,
			to_char(HB_START_DATE,'yyyymmddhh24miss'),
			to_char(HB_END_DATE,'yyyymmddhh24miss'),
			HB_DISABLED,
			to_char(HB_CREATE_TIMESTAMP,'yyyymmddhh24miss'),
			HB_CREATE_USER
		  FROM	HIST_OL_COST_SUM_BATCH
		 WHERE	HB_START_DATE >= to_date(:hv_date,'YYYYMMDD')
		   AND	HB_END_DATE < to_date(:hv_date,'YYYYMMDD')+1
		ORDER BY
			HB_BATCH_ID ASC; */ 


	/* EXEC SQL OPEN c_cursor_histolcostsumbatch; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0009;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )497;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_date;
 sqlstm.sqhstl[1] = (unsigned long )11;
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
 if (sqlca.sqlcode < 0) goto error_histolcostsumbatch;
}


	do {
		/* EXEC SQL FETCH c_cursor_histolcostsumbatch
		INTO	:v_batch_id:ind_batch_id,
			:v_start_ts:ind_start_ts,
			:v_end_ts:ind_end_ts,
			:v_disabled:ind_disabled,
			:v_create_ts:ind_create_ts,
			:v_create_user:ind_create_user; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )520;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_batch_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_start_ts;
  sqlstm.sqhstl[1] = (unsigned long )17;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_start_ts;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_end_ts;
  sqlstm.sqhstl[2] = (unsigned long )17;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_end_ts;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_disabled;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_disabled;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_create_ts;
  sqlstm.sqhstl[4] = (unsigned long )17;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_create_ts;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_create_user;
  sqlstm.sqhstl[5] = (unsigned long )23;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_create_user;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto error_histolcostsumbatch;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

/* Field #0 batch_id */
		if (ind_batch_id >= 0) {
			fprintf(fp,"%d%c",v_batch_id,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #1 start_ts */
		if (ind_start_ts >= 0) {
			sprintf(csTmp,"%.*s",v_start_ts.len,v_start_ts.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #2 end_ts */
		if (ind_end_ts >= 0) {
			sprintf(csTmp,"%.*s",v_end_ts.len,v_end_ts.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #3 disabled */
		if (ind_disabled >= 0) {
			fprintf(fp,"%d%c",v_disabled,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #4 create_ts */
		if (ind_create_ts >= 0) {
			sprintf(csTmp,"%.*s",v_create_ts.len,v_create_ts.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #5 create_user */
		if (ind_create_user>= 0) {
			sprintf(csTmp,"%.*s",v_create_user.len,v_create_user.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* new line */
		fprintf(fp,"\n");

 	} while (PD_TRUE);
	/* EXEC SQL CLOSE c_cursor_histolcostsumbatch; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )559;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto error_histolcostsumbatch;
}



        return iRet;

error_histolcostsumbatch:
DEBUGLOG(("hist_ol_cost_sum_batch error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_histolcostsumbatch; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )574;
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
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )589;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int process_hist_ol_cost_sum_detail(FILE *fp)
{               
        int     iRet = SUCCESS;
	char	csTmp[PD_TMP_BUF_LEN+1];

	/* EXEC SQL WHENEVER SQLERROR GOTO error_histolcostsumdetail; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } hv_date;


		int	v_batch_id;
		/* varchar	v_party_type[PD_MMS_ENTITY_TYPE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_party_type;

		/* varchar	v_entity_id[PD_CLIENT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_entity_id;

		/* varchar	v_entity_name[PD_CLIENT_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_entity_name;

		/* varchar	v_client_name[PD_CLIENT_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_client_name;

		/* varchar	v_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ccy;

		/* varchar	v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		/* varchar	v_product[PD_PRODUCT_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_product;

		/* varchar	v_txn_type[PD_TXN_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_type;

		int	v_count;
		double	v_accum_cost_amt;
		double	v_accum_refund_amt;
		double	v_accum_void_amt;
		double	v_accum_total_amt;
		double	v_accum_cost_amt_hkd;
		double	v_accum_refund_amt_hkd;
		double	v_accum_void_amt_hkd;
		double	v_accum_total_amt_hkd;
		double	v_accum_cost_amt_hkd_rate;
		double	v_accum_cost_amt_usd;
		double	v_accum_refund_amt_usd;
		double	v_accum_void_amt_usd;
		double	v_accum_total_amt_usd;
		double	v_accum_cost_amt_usd_rate;

		short	ind_batch_id = -1;
		short	ind_party_type = -1;
		short	ind_entity_id = -1;
		short	ind_entity_name = -1;
		short	ind_client_name = -1;
		short	ind_ccy = -1;
		short	ind_country = -1;
		short	ind_product = -1;
		short	ind_txn_type = -1;
		short	ind_count = -1;
		short	ind_accum_cost_amt = -1;
		short	ind_accum_refund_amt = -1;
		short	ind_accum_void_amt = -1;
		short	ind_accum_total_amt = -1;
		short	ind_accum_cost_amt_hkd = -1;
		short	ind_accum_refund_amt_hkd = -1;
		short	ind_accum_void_amt_hkd = -1;
		short	ind_accum_total_amt_hkd = -1;
		short	ind_accum_cost_amt_hkd_rate = -1;
		short	ind_accum_cost_amt_usd = -1;
		short	ind_accum_refund_amt_usd = -1;
		short	ind_accum_void_amt_usd = -1;
		short	ind_accum_total_amt_usd = -1;
		short	ind_accum_cost_amt_usd_rate = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_date.len = strlen(cs_date);
	memcpy(hv_date.arr,cs_date,hv_date.len);

	/* EXEC SQL DECLARE c_cursor_histolcostsumdetail CURSOR FOR
		SELECT	HD_BATCH_ID,
			HD_PARTY_TYPE,
			HD_ENTITY_ID, 
			HD_ENTITY_NAME, 
			HD_CLIENT_NAME, 
			HD_CCY,
			HD_COUNTRY,
			HD_PRODUCT,
			HD_TXN_TYPE, 
			HD_COUNT,
			HD_ACCUM_COST_AMT, 
			HD_ACCUM_REFUND_AMT, 
			HD_ACCUM_VOID_AMT, 
			HD_ACCUM_TOTAL_AMT, 
			HD_ACCUM_COST_AMT_HKD, 
			HD_ACCUM_REFUND_AMT_HKD, 
			HD_ACCUM_VOID_AMT_HKD, 
			HD_ACCUM_TOTAL_AMT_HKD,
			HD_ACCUM_COST_AMT_HKD_RATE, 
			HD_ACCUM_COST_AMT_USD, 
			HD_ACCUM_REFUND_AMT_USD, 
			HD_ACCUM_VOID_AMT_USD, 
			HD_ACCUM_TOTAL_AMT_USD,
			HD_ACCUM_COST_AMT_USD_RATE
		  FROM	HIST_OL_COST_SUM_DETAIL
		 WHERE	HD_BATCH_ID IN (SELECT HB_BATCH_ID FROM HIST_OL_COST_SUM_BATCH
					 WHERE HB_START_DATE >= to_date(:hv_date,'YYYYMMDD')
					   AND HB_END_DATE < to_date(:hv_date,'YYYYMMDD')+1)
		ORDER BY
			HD_BATCH_ID, HD_PARTY_TYPE, HD_ENTITY_ID, HD_ENTITY_NAME, HD_CCY, HD_COUNTRY, HD_PRODUCT, HD_TXN_TYPE; */ 

	/* EXEC SQL OPEN c_cursor_histolcostsumdetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0011;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )604;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_date;
 sqlstm.sqhstl[1] = (unsigned long )11;
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
 if (sqlca.sqlcode < 0) goto error_histolcostsumdetail;
}


	do {
		/* EXEC SQL FETCH c_cursor_histolcostsumdetail
		INTO	:v_batch_id:ind_batch_id,
			:v_party_type:ind_party_type,
			:v_entity_id:ind_entity_id,
			:v_entity_name:ind_entity_name,
			:v_client_name:ind_client_name,
			:v_ccy:ind_ccy,
			:v_country:ind_country,
			:v_product:ind_product,
			:v_txn_type:ind_txn_type,
			:v_count:ind_count,
			:v_accum_cost_amt:ind_accum_cost_amt,
			:v_accum_refund_amt:ind_accum_refund_amt,
			:v_accum_void_amt:ind_accum_void_amt,
			:v_accum_total_amt:ind_accum_total_amt,
			:v_accum_cost_amt_hkd:ind_accum_cost_amt_hkd,
			:v_accum_refund_amt_hkd:ind_accum_refund_amt_hkd,
			:v_accum_void_amt_hkd:ind_accum_void_amt_hkd,
			:v_accum_total_amt_hkd:ind_accum_total_amt_hkd,
			:v_accum_cost_amt_hkd_rate:ind_accum_cost_amt_hkd_rate,
			:v_accum_cost_amt_usd:ind_accum_cost_amt_usd,
			:v_accum_refund_amt_usd:ind_accum_refund_amt_usd,
			:v_accum_void_amt_usd:ind_accum_void_amt_usd,
			:v_accum_total_amt_usd:ind_accum_total_amt_usd,
			:v_accum_cost_amt_usd_rate:ind_accum_cost_amt_usd_rate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 24;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )627;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_batch_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_party_type;
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_party_type;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_entity_id;
  sqlstm.sqhstl[2] = (unsigned long )13;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_entity_id;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_entity_name;
  sqlstm.sqhstl[3] = (unsigned long )53;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_entity_name;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_client_name;
  sqlstm.sqhstl[4] = (unsigned long )53;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_client_name;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_ccy;
  sqlstm.sqhstl[5] = (unsigned long )6;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_ccy;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_country;
  sqlstm.sqhstl[6] = (unsigned long )5;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_country;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_product;
  sqlstm.sqhstl[7] = (unsigned long )6;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_product;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_txn_type;
  sqlstm.sqhstl[8] = (unsigned long )6;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_txn_type;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_count;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_count;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_accum_cost_amt;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_accum_cost_amt;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_accum_refund_amt;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_accum_refund_amt;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_accum_void_amt;
  sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_accum_void_amt;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_accum_total_amt;
  sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_accum_total_amt;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_accum_cost_amt_hkd;
  sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_accum_cost_amt_hkd;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_accum_refund_amt_hkd;
  sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_accum_refund_amt_hkd;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&v_accum_void_amt_hkd;
  sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)&ind_accum_void_amt_hkd;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)&v_accum_total_amt_hkd;
  sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)&ind_accum_total_amt_hkd;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)&v_accum_cost_amt_hkd_rate;
  sqlstm.sqhstl[18] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[18] = (         int  )0;
  sqlstm.sqindv[18] = (         short *)&ind_accum_cost_amt_hkd_rate;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)&v_accum_cost_amt_usd;
  sqlstm.sqhstl[19] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[19] = (         int  )0;
  sqlstm.sqindv[19] = (         short *)&ind_accum_cost_amt_usd;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)&v_accum_refund_amt_usd;
  sqlstm.sqhstl[20] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[20] = (         int  )0;
  sqlstm.sqindv[20] = (         short *)&ind_accum_refund_amt_usd;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)&v_accum_void_amt_usd;
  sqlstm.sqhstl[21] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[21] = (         int  )0;
  sqlstm.sqindv[21] = (         short *)&ind_accum_void_amt_usd;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)&v_accum_total_amt_usd;
  sqlstm.sqhstl[22] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[22] = (         int  )0;
  sqlstm.sqindv[22] = (         short *)&ind_accum_total_amt_usd;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)&v_accum_cost_amt_usd_rate;
  sqlstm.sqhstl[23] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[23] = (         int  )0;
  sqlstm.sqindv[23] = (         short *)&ind_accum_cost_amt_usd_rate;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto error_histolcostsumdetail;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

/* Field #0 batch_id */
		if (ind_batch_id >= 0) {
			fprintf(fp,"%d%c",v_batch_id,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #1 party_type */
		if (ind_party_type >= 0) {
			sprintf(csTmp,"%.*s",v_party_type.len,v_party_type.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #2 entity_id */
		if (ind_entity_id >= 0) {
			sprintf(csTmp,"%.*s",v_entity_id.len,v_entity_id.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #3 entity_name */
		if (ind_entity_name >= 0) {
			sprintf(csTmp,"%.*s",v_entity_name.len,v_entity_name.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #4 client_name */
		if (ind_client_name >= 0) {
			sprintf(csTmp,"%.*s",v_client_name.len,v_client_name.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #5 ccy */
		if (ind_ccy >= 0) {
			sprintf(csTmp,"%.*s",v_ccy.len,v_ccy.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #6 country */
		if (ind_country >= 0) {
			sprintf(csTmp,"%.*s",v_country.len,v_country.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #7 product */
		if (ind_product >= 0) {
			sprintf(csTmp,"%.*s",v_product.len,v_product.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #8 txn_type */
		if (ind_txn_type >= 0) {
			sprintf(csTmp,"%.*s",v_txn_type.len,v_txn_type.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #9 count */
		if (ind_count >= 0) {
			fprintf(fp,"%d%c",v_count,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #10 accum_cost_amt */
		if (ind_accum_cost_amt >= 0) {
			fprintf(fp,"%.2f%c",v_accum_cost_amt,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #11 accum_refund_amt */
		if (ind_accum_refund_amt >= 0) {
			fprintf(fp,"%.2f%c",v_accum_refund_amt,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #12 accum_void */
		if (ind_accum_void_amt >= 0) {
			fprintf(fp,"%.2f%c",v_accum_void_amt,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #13 accum_total_amt */
		if (ind_accum_total_amt >= 0) {
			fprintf(fp,"%.2f%c",v_accum_total_amt,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #14 accum_cost_amt_hkd */
		if (ind_accum_cost_amt_hkd >= 0) {
			fprintf(fp,"%.2f%c",v_accum_cost_amt_hkd,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #15 accum_refund_amt_hkd */
		if (ind_accum_refund_amt_hkd >= 0) {
			fprintf(fp,"%.2f%c",v_accum_refund_amt_hkd,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #16 accum_void_hkd */
		if (ind_accum_void_amt_hkd >= 0) {
			fprintf(fp,"%.2f%c",v_accum_void_amt_hkd,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #17 accum_total_amt_hkd */
		if (ind_accum_total_amt_hkd >= 0) {
			fprintf(fp,"%.2f%c",v_accum_total_amt_hkd,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #18 accum_cost_amt_hkd_rate */
		if (ind_accum_cost_amt_hkd_rate >= 0) {
			fprintf(fp,"%.5f%c",v_accum_cost_amt_hkd_rate,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #19 accum_cost_amt_usd */
		if (ind_accum_cost_amt_usd >= 0) {
			fprintf(fp,"%.2f%c",v_accum_cost_amt_usd,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #20 accum_refund_amt_usd */
		if (ind_accum_refund_amt_usd >= 0) {
			fprintf(fp,"%.2f%c",v_accum_refund_amt_usd,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #21 accum_void_usd */
		if (ind_accum_void_amt_usd >= 0) {
			fprintf(fp,"%.2f%c",v_accum_void_amt_usd,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #22 accum_total_amt_usd */
		if (ind_accum_total_amt_usd >= 0) {
			fprintf(fp,"%.2f%c",v_accum_total_amt_usd,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #23 accum_cost_amt_usd_rate */
		if (ind_accum_cost_amt_usd_rate >= 0) {
			fprintf(fp,"%.5f%c",v_accum_cost_amt_usd_rate,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* new line */
		fprintf(fp,"\n");

 	} while (PD_TRUE);
	/* EXEC SQL CLOSE c_cursor_histolcostsumdetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 24;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )738;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto error_histolcostsumdetail;
}



        return iRet;

error_histolcostsumdetail:
DEBUGLOG(("hist_ol_cost_sum_detail error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_histolcostsumdetail; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 24;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )753;
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
    sqlstm.arrsiz = 24;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )768;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int process_hist_ol_mid_bal_batch(FILE *fp)
{               
        int     iRet = SUCCESS;
	char	csTmp[PD_TMP_BUF_LEN+1];

	/* EXEC SQL WHENEVER SQLERROR GOTO error_histolmidbalbatch; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } hv_date;


		int	v_batch_id;
		/* varchar	v_start_ts[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_start_ts;

		/* varchar	v_end_ts[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_end_ts;

		int	v_disabled;
		/* varchar	v_create_ts[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_create_ts;

		/* varchar	v_create_user[PD_USER_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_create_user;


		short	ind_batch_id = -1;
		short	ind_start_ts = -1;
		short	ind_end_ts = -1;
		short	ind_disabled = -1;
		short	ind_create_ts = -1;
		short	ind_create_user = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_date.len = strlen(cs_date);
	memcpy(hv_date.arr,cs_date,hv_date.len);

	/* EXEC SQL DECLARE c_cursor_histolmidbalbatch CURSOR FOR
		SELECT	HB_BATCH_ID,
			to_char(HB_START_DATE,'yyyymmddhh24miss'),
			to_char(HB_END_DATE,'yyyymmddhh24miss'),
			HB_DISABLED,
			to_char(HB_CREATE_TIMESTAMP,'yyyymmddhh24miss'),
			HB_CREATE_USER
		  FROM	HIST_OL_MID_BAL_BATCH
		 WHERE	HB_START_DATE >= to_date(:hv_date,'YYYYMMDD')
		   AND	HB_END_DATE < to_date(:hv_date,'YYYYMMDD')+1
		ORDER BY
			HB_BATCH_ID ASC; */ 


	/* EXEC SQL OPEN c_cursor_histolmidbalbatch; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 24;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0013;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )783;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_date;
 sqlstm.sqhstl[1] = (unsigned long )11;
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
 if (sqlca.sqlcode < 0) goto error_histolmidbalbatch;
}


	do {
		/* EXEC SQL FETCH c_cursor_histolmidbalbatch
		INTO	:v_batch_id:ind_batch_id,
			:v_start_ts:ind_start_ts,
			:v_end_ts:ind_end_ts,
			:v_disabled:ind_disabled,
			:v_create_ts:ind_create_ts,
			:v_create_user:ind_create_user; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 24;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )806;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_batch_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_start_ts;
  sqlstm.sqhstl[1] = (unsigned long )17;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_start_ts;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_end_ts;
  sqlstm.sqhstl[2] = (unsigned long )17;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_end_ts;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_disabled;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_disabled;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_create_ts;
  sqlstm.sqhstl[4] = (unsigned long )17;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_create_ts;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_create_user;
  sqlstm.sqhstl[5] = (unsigned long )23;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_create_user;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto error_histolmidbalbatch;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

/* Field #0 batch_id */
		if (ind_batch_id >= 0) {
			fprintf(fp,"%d%c",v_batch_id,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #1 start_ts */
		if (ind_start_ts >= 0) {
			sprintf(csTmp,"%.*s",v_start_ts.len,v_start_ts.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #2 end_ts */
		if (ind_end_ts >= 0) {
			sprintf(csTmp,"%.*s",v_end_ts.len,v_end_ts.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #3 disabled */
		if (ind_disabled >= 0) {
			fprintf(fp,"%d%c",v_disabled,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #4 create_ts */
		if (ind_create_ts >= 0) {
			sprintf(csTmp,"%.*s",v_create_ts.len,v_create_ts.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #5 create_user */
		if (ind_create_user>= 0) {
			sprintf(csTmp,"%.*s",v_create_user.len,v_create_user.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* new line */
		fprintf(fp,"\n");

 	} while (PD_TRUE);
	/* EXEC SQL CLOSE c_cursor_histolmidbalbatch; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 24;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )845;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto error_histolmidbalbatch;
}



        return iRet;

error_histolmidbalbatch:
DEBUGLOG(("hist_ol_mid_bal_batch error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_histolmidbalbatch; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 24;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )860;
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
    sqlstm.arrsiz = 24;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )875;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int process_hist_ol_mid_bal_detail(FILE *fp)
{               
        int     iRet = SUCCESS;
	char	csTmp[PD_TMP_BUF_LEN+1];

	/* EXEC SQL WHENEVER SQLERROR GOTO error_histolmidbaldetail; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } hv_date;


		int	v_batch_id;
		/* varchar	v_client_id[15+1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_client_id;

		/* varchar	v_mid_id[15+1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_mid_id;

		/* varchar	v_service_code[PD_SERVICE_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		/* varchar	v_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ccy;

		/* varchar	v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		/* varchar	v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		double	v_current_bal;
		double	v_hold_bal;
		double	v_lien;
		double	v_merchant_bal;
		double	v_bal;
		double	v_bal_hkd;
		double	v_bal_hkd_rate;
		double	v_bal_usd;
		double	v_bal_usd_rate;

		short	ind_batch_id = -1;
		short	ind_client_id = -1;
		short	ind_mid_id = -1;
		short	ind_service_code = -1;
		short	ind_ccy = -1;
		short	ind_country = -1;
		short	ind_txn_id = -1;
		short	ind_current_bal = -1;
		short	ind_hold_bal = -1;
		short	ind_lien = -1;
		short	ind_merchant_bal = -1;
		short	ind_bal = -1;
		short	ind_bal_hkd = -1;
		short	ind_bal_hkd_rate = -1;
		short	ind_bal_usd = -1;
		short	ind_bal_usd_rate = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_date.len = strlen(cs_date);
	memcpy(hv_date.arr,cs_date,hv_date.len);

	/* EXEC SQL DECLARE c_cursor_histolmidbaldetail CURSOR FOR
		SELECT	HD_BATCH_ID,
			HD_CLIENT_ID,
			HD_MID_ID, 
			HD_SERVICE_CODE, 
			HD_CCY, 
			HD_COUNTRY, 
			HD_TXN_ID, 
			HD_CURRENT_BAL, 
			HD_HOLD_BAL, 
			HD_LIEN,
			HD_MERCHANT_BAL, 
			HD_BAL, 
			HD_BAL_HKD, 
			HD_BAL_HKD_RATE, 
			HD_BAL_USD, 
			HD_BAL_USD_RATE
		  FROM	HIST_OL_MID_BAL_DETAIL
		 WHERE	HD_BATCH_ID IN (SELECT HB_BATCH_ID FROM HIST_OL_MID_BAL_BATCH
					 WHERE HB_START_DATE >= to_date(:hv_date,'YYYYMMDD')
					   AND HB_END_DATE < to_date(:hv_date,'YYYYMMDD')+1)
		ORDER BY
			HD_BATCH_ID, HD_CLIENT_ID, HD_MID_ID, HD_SERVICE_CODE, HD_CCY, HD_COUNTRY; */ 


	/* EXEC SQL OPEN c_cursor_histolmidbaldetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 24;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0015;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )890;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_date;
 sqlstm.sqhstl[1] = (unsigned long )11;
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
 if (sqlca.sqlcode < 0) goto error_histolmidbaldetail;
}


	do {
		/* EXEC SQL FETCH c_cursor_histolmidbaldetail
		INTO	:v_batch_id:ind_batch_id,
			:v_client_id:ind_client_id,
			:v_mid_id:ind_mid_id,
			:v_service_code:ind_service_code,
			:v_ccy:ind_ccy,
			:v_country:ind_country,
			:v_txn_id:ind_txn_id,
			:v_current_bal:ind_current_bal,
			:v_hold_bal:ind_hold_bal,
			:v_lien:ind_lien,
			:v_merchant_bal:ind_merchant_bal,
			:v_bal:ind_bal,
			:v_bal_hkd:ind_bal_hkd,
			:v_bal_hkd_rate:ind_bal_hkd_rate,
			:v_bal_usd:ind_bal_usd,
			:v_bal_usd_rate:ind_bal_usd_rate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 24;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )913;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_batch_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_client_id;
  sqlstm.sqhstl[1] = (unsigned long )18;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_client_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_mid_id;
  sqlstm.sqhstl[2] = (unsigned long )18;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_mid_id;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_service_code;
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_service_code;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_ccy;
  sqlstm.sqhstl[4] = (unsigned long )6;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_ccy;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_country;
  sqlstm.sqhstl[5] = (unsigned long )5;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_country;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[6] = (unsigned long )19;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_txn_id;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_current_bal;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_current_bal;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_hold_bal;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_hold_bal;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_lien;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_lien;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_merchant_bal;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_merchant_bal;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_bal;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_bal;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_bal_hkd;
  sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_bal_hkd;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_bal_hkd_rate;
  sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_bal_hkd_rate;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_bal_usd;
  sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_bal_usd;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_bal_usd_rate;
  sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_bal_usd_rate;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto error_histolmidbaldetail;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

/* Field #0 batch_id */
		if (ind_batch_id >= 0) {
			fprintf(fp,"%d%c",v_batch_id,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #1 client_id */
		if (ind_client_id >= 0) {
			sprintf(csTmp,"%.*s",v_client_id.len,v_client_id.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #2 mid_id */
		if (ind_mid_id >= 0) {
			sprintf(csTmp,"%.*s",v_mid_id.len,v_mid_id.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #3 service_code */
		if (ind_service_code >= 0) {
			sprintf(csTmp,"%.*s",v_service_code.len,v_service_code.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #4 ccy */
		if (ind_ccy >= 0) {
			sprintf(csTmp,"%.*s",v_ccy.len,v_ccy.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #5 country */
		if (ind_country >= 0) {
			sprintf(csTmp,"%.*s",v_country.len,v_country.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #6 txn_id */
		if (ind_txn_id >= 0) {
			sprintf(csTmp,"%.*s",v_txn_id.len,v_txn_id.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #7 current_bal */
		if (ind_current_bal >= 0) {
			fprintf(fp,"%.2f%c",v_current_bal,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #8 hold_bal */
		if (ind_hold_bal >= 0) {
			fprintf(fp,"%.2f%c",v_hold_bal,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #9 lien */
		if (ind_lien >= 0) {
			fprintf(fp,"%.2f%c",v_lien,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #10 merchant_bal */
		if (ind_merchant_bal >= 0) {
			fprintf(fp,"%.2f%c",v_merchant_bal,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #11 bal */
		if (ind_bal >= 0) {
			fprintf(fp,"%.2f%c",v_bal,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #12 bal_hkd */
		if (ind_bal_hkd >= 0) {
			fprintf(fp,"%.2f%c",v_bal_hkd,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #13 bal_hkd_rate */
		if (ind_bal_hkd_rate >= 0) {
			fprintf(fp,"%.5f%c",v_bal_hkd_rate,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #14 bal_usd */
		if (ind_bal_usd >= 0) {
			fprintf(fp,"%.2f%c",v_bal_usd,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #15 bal_usd_rate */
		if (ind_bal_usd_rate >= 0) {
			fprintf(fp,"%.5f%c",v_bal_usd_rate,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* new line */
		fprintf(fp,"\n");

 	} while (PD_TRUE);
	/* EXEC SQL CLOSE c_cursor_histolmidbaldetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 24;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )992;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto error_histolmidbaldetail;
}



        return iRet;

error_histolmidbaldetail:
DEBUGLOG(("hist_ol_mid_bal_detail error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_histolmidbaldetail; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 24;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1007;
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
    sqlstm.arrsiz = 24;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1022;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int process_omi_hist_bal_batch(FILE *fp)
{               
        int     iRet = SUCCESS;
	char	csTmp[PD_TMP_BUF_LEN+1];

	/* EXEC SQL WHENEVER SQLERROR GOTO error_omihistbalbatch; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } hv_date;


		int	v_batch_id;
		/* varchar	v_start_ts[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_start_ts;

		/* varchar	v_end_ts[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_end_ts;

		int	v_disabled;
		/* varchar	v_create_ts[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_create_ts;

		/* varchar	v_create_user[PD_USER_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_create_user;


		short	ind_batch_id = -1;
		short	ind_start_ts = -1;
		short	ind_end_ts = -1;
		short	ind_disabled = -1;
		short	ind_create_ts = -1;
		short	ind_create_user = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_date.len = strlen(cs_date);
	memcpy(hv_date.arr,cs_date,hv_date.len);

	/* EXEC SQL DECLARE c_cursor_omihistbalbatch CURSOR FOR
		SELECT	OMI_BATCH_ID,
			to_char(OMI_START_DATE,'yyyymmddhh24miss'),
			to_char(OMI_END_DATE,'yyyymmddhh24miss'),
			OMI_DISABLED,
			to_char(OMI_CREATE_TIMESTAMP,'yyyymmddhh24miss'),
			OMI_CREATE_USER
		  FROM	OMI_HIST_BAL_BATCH
		 WHERE	OMI_START_DATE >= to_date(:hv_date,'YYYYMMDD')
		   AND	OMI_END_DATE < to_date(:hv_date,'YYYYMMDD')+1
		ORDER BY
			OMI_BATCH_ID ASC; */ 


	/* EXEC SQL OPEN c_cursor_omihistbalbatch; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 24;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0017;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1037;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_date;
 sqlstm.sqhstl[1] = (unsigned long )11;
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
 if (sqlca.sqlcode < 0) goto error_omihistbalbatch;
}


	do {
		/* EXEC SQL FETCH c_cursor_omihistbalbatch
		INTO	:v_batch_id:ind_batch_id,
			:v_start_ts:ind_start_ts,
			:v_end_ts:ind_end_ts,
			:v_disabled:ind_disabled,
			:v_create_ts:ind_create_ts,
			:v_create_user:ind_create_user; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 24;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1060;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_batch_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_start_ts;
  sqlstm.sqhstl[1] = (unsigned long )17;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_start_ts;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_end_ts;
  sqlstm.sqhstl[2] = (unsigned long )17;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_end_ts;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_disabled;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_disabled;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_create_ts;
  sqlstm.sqhstl[4] = (unsigned long )17;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_create_ts;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_create_user;
  sqlstm.sqhstl[5] = (unsigned long )23;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_create_user;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto error_omihistbalbatch;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

/* Field #0 batch_id */
		if (ind_batch_id >= 0) {
			fprintf(fp,"%d%c",v_batch_id,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #1 start_ts */
		if (ind_start_ts >= 0) {
			sprintf(csTmp,"%.*s",v_start_ts.len,v_start_ts.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #2 end_ts */
		if (ind_end_ts >= 0) {
			sprintf(csTmp,"%.*s",v_end_ts.len,v_end_ts.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #3 disabled */
		if (ind_disabled >= 0) {
			fprintf(fp,"%d%c",v_disabled,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #4 create_ts */
		if (ind_create_ts >= 0) {
			sprintf(csTmp,"%.*s",v_create_ts.len,v_create_ts.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #5 create_user */
		if (ind_create_user>= 0) {
			sprintf(csTmp,"%.*s",v_create_user.len,v_create_user.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* new line */
		fprintf(fp,"\n");

 	} while (PD_TRUE);
	/* EXEC SQL CLOSE c_cursor_omihistbalbatch; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 24;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1099;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto error_omihistbalbatch;
}



        return iRet;

error_omihistbalbatch:
DEBUGLOG(("omi_hist_bal_batch error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_omihistbalbatch; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 24;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1114;
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
    sqlstm.arrsiz = 24;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1129;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int process_omi_hist_bal_detail(FILE *fp)
{               
        int     iRet = SUCCESS;
	char	csTmp[PD_TMP_BUF_LEN+1];

	/* EXEC SQL WHENEVER SQLERROR GOTO error_omihistbaldetail; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } hv_date;


		int	v_batch_id;
		/* varchar	v_mi_id[10+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_mi_id;

		/* varchar	v_entity_type[3+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_entity_type;

		/* varchar	v_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ccy;

		/* varchar	v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		/* varchar	v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		double	v_acct_bal;
		double	v_intransit;
		double	v_ar_bal;
		double	v_bal;
		double	v_bal_hkd;
		double	v_bal_hkd_rate;
		double	v_bal_usd;
		double	v_bal_usd_rate;

		short	ind_batch_id = -1;
		short	ind_mi_id = -1;
		short	ind_entity_type = -1;
		short	ind_ccy = -1;
		short	ind_country = -1;
		short	ind_txn_id = -1;
		short	ind_acct_bal = -1;
		short	ind_intransit = -1;
		short	ind_ar_bal = -1;
		short	ind_bal = -1;
		short	ind_bal_hkd = -1;
		short	ind_bal_hkd_rate = -1;
		short	ind_bal_usd = -1;
		short	ind_bal_usd_rate = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_date.len = strlen(cs_date);
	memcpy(hv_date.arr,cs_date,hv_date.len);

	/* EXEC SQL DECLARE c_cursor_omihistbaldetail CURSOR FOR
		SELECT	OMID_BATCH_ID,
			OMID_MI_ID, 
			OMID_ENTITY_TYPE, 
			OMID_CCY, 
			OMID_COUNTRY, 
			OMID_TXN_ID, 
			OMID_ACCT_BAL, 
			OMID_INTRANSIT, 
			OMID_AR_BAL,
			OMID_BAL, 
			OMID_BAL_HKD, 
			OMID_BAL_HKD_RATE, 
			OMID_BAL_USD, 
			OMID_BAL_USD_RATE
		  FROM	OMI_HIST_BAL_DETAIL
		 WHERE	OMID_BATCH_ID IN (SELECT OMI_BATCH_ID FROM OMI_HIST_BAL_BATCH
					   WHERE OMI_START_DATE >= to_date(:hv_date,'YYYYMMDD')
					     AND OMI_END_DATE < to_date(:hv_date,'YYYYMMDD')+1)
		ORDER BY
			OMID_BATCH_ID, OMID_MI_ID, OMID_ENTITY_TYPE, OMID_CCY, OMID_COUNTRY; */ 

	/* EXEC SQL OPEN c_cursor_omihistbaldetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 24;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0019;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1144;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_date;
 sqlstm.sqhstl[1] = (unsigned long )11;
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
 if (sqlca.sqlcode < 0) goto error_omihistbaldetail;
}


	do {
		/* EXEC SQL FETCH c_cursor_omihistbaldetail
		INTO	:v_batch_id:ind_batch_id,
			:v_mi_id:ind_mi_id,
			:v_entity_type:ind_entity_type,
			:v_ccy:ind_ccy,
			:v_country:ind_country,
			:v_txn_id:ind_txn_id,
			:v_acct_bal:ind_acct_bal,
			:v_intransit:ind_intransit,
			:v_ar_bal:ind_ar_bal,
			:v_bal:ind_bal,
			:v_bal_hkd:ind_bal_hkd,
			:v_bal_hkd_rate:ind_bal_hkd_rate,
			:v_bal_usd:ind_bal_usd,
			:v_bal_usd_rate:ind_bal_usd_rate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 24;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1167;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_batch_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_mi_id;
  sqlstm.sqhstl[1] = (unsigned long )13;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_mi_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_entity_type;
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_entity_type;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_ccy;
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_ccy;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_country;
  sqlstm.sqhstl[4] = (unsigned long )5;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_country;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[5] = (unsigned long )19;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_txn_id;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_acct_bal;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_acct_bal;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_intransit;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_intransit;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_ar_bal;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_ar_bal;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_bal;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_bal;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_bal_hkd;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_bal_hkd;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_bal_hkd_rate;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_bal_hkd_rate;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_bal_usd;
  sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_bal_usd;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_bal_usd_rate;
  sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_bal_usd_rate;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto error_omihistbaldetail;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

/* Field #0 batch_id */
		if (ind_batch_id >= 0) {
			fprintf(fp,"%d%c",v_batch_id,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #1 mi_id */
		if (ind_mi_id >= 0) {
			sprintf(csTmp,"%.*s",v_mi_id.len,v_mi_id.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #2 entity_type */
		if (ind_entity_type >= 0) {
			sprintf(csTmp,"%.*s",v_entity_type.len,v_entity_type.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #3 ccy */
		if (ind_ccy >= 0) {
			sprintf(csTmp,"%.*s",v_ccy.len,v_ccy.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #4 country */
		if (ind_country >= 0) {
			sprintf(csTmp,"%.*s",v_country.len,v_country.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #5 txn_id */
		if (ind_txn_id >= 0) {
			sprintf(csTmp,"%.*s",v_txn_id.len,v_txn_id.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #6 acct_bal */
		if (ind_acct_bal >= 0) {
			fprintf(fp,"%.2f%c",v_acct_bal,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #7 intransit */
		if (ind_intransit >= 0) {
			fprintf(fp,"%.2f%c",v_intransit,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #8 ar_bal */
		if (ind_ar_bal >= 0) {
			fprintf(fp,"%.2f%c",v_ar_bal,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #9 bal */
		if (ind_bal >= 0) {
			fprintf(fp,"%.2f%c",v_bal,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #10 bal_hkd */
		if (ind_bal_hkd >= 0) {
			fprintf(fp,"%.2f%c",v_bal_hkd,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #11 bal_hkd_rate */
		if (ind_bal_hkd_rate >= 0) {
			fprintf(fp,"%.5f%c",v_bal_hkd_rate,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #12 bal_usd */
		if (ind_bal_usd >= 0) {
			fprintf(fp,"%.2f%c",v_bal_usd,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #13 bal_usd_rate */
		if (ind_bal_usd_rate >= 0) {
			fprintf(fp,"%.5f%c",v_bal_usd_rate,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* new line */
		fprintf(fp,"\n");

 	} while (PD_TRUE);
	/* EXEC SQL CLOSE c_cursor_omihistbaldetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 24;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1238;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto error_omihistbaldetail;
}



        return iRet;

error_omihistbaldetail:
DEBUGLOG(("omi_hist_bal_detail error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_histolmidbaldetail; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 24;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1253;
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
    sqlstm.arrsiz = 24;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1268;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int process_hist_baid_bal_batch(FILE *fp)
{               
        int     iRet = SUCCESS;
	char	csTmp[PD_TMP_BUF_LEN+1];

	/* EXEC SQL WHENEVER SQLERROR GOTO error_histbaidbalbatch; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } hv_date;


		int	v_batch_id;
		/* varchar	v_start_ts[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_start_ts;

		/* varchar	v_end_ts[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_end_ts;

		int	v_disabled;
		/* varchar	v_create_ts[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_create_ts;

		/* varchar	v_create_user[PD_USER_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_create_user;


		short	ind_batch_id = -1;
		short	ind_start_ts = -1;
		short	ind_end_ts = -1;
		short	ind_disabled = -1;
		short	ind_create_ts = -1;
		short	ind_create_user = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_date.len = strlen(cs_date);
	memcpy(hv_date.arr,cs_date,hv_date.len);

	/* EXEC SQL DECLARE c_cursor_histbaidbalbatch CURSOR FOR
		SELECT	HB_BATCH_ID,
			to_char(HB_START_DATE,'yyyymmddhh24miss'),
			to_char(HB_END_DATE,'yyyymmddhh24miss'),
			HB_DISABLED,
			to_char(HB_CREATE_TIMESTAMP,'yyyymmddhh24miss'),
			HB_CREATE_USER
		  FROM	HIST_BAID_BAL_BATCH
		 WHERE	HB_START_DATE >= to_date(:hv_date,'YYYYMMDD')
		   AND	HB_END_DATE < to_date(:hv_date,'YYYYMMDD')+1
		ORDER BY
			HB_BATCH_ID ASC; */ 


	/* EXEC SQL OPEN c_cursor_histbaidbalbatch; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 24;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0021;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1283;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_date;
 sqlstm.sqhstl[1] = (unsigned long )11;
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
 if (sqlca.sqlcode < 0) goto error_histbaidbalbatch;
}


	do {
		/* EXEC SQL FETCH c_cursor_histbaidbalbatch
		INTO	:v_batch_id:ind_batch_id,
			:v_start_ts:ind_start_ts,
			:v_end_ts:ind_end_ts,
			:v_disabled:ind_disabled,
			:v_create_ts:ind_create_ts,
			:v_create_user:ind_create_user; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 24;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1306;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_batch_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_start_ts;
  sqlstm.sqhstl[1] = (unsigned long )17;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_start_ts;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_end_ts;
  sqlstm.sqhstl[2] = (unsigned long )17;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_end_ts;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_disabled;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_disabled;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_create_ts;
  sqlstm.sqhstl[4] = (unsigned long )17;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_create_ts;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_create_user;
  sqlstm.sqhstl[5] = (unsigned long )23;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_create_user;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto error_histbaidbalbatch;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

/* Field #0 batch_id */
		if (ind_batch_id >= 0) {
			fprintf(fp,"%d%c",v_batch_id,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #1 start_ts */
		if (ind_start_ts >= 0) {
			sprintf(csTmp,"%.*s",v_start_ts.len,v_start_ts.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #2 end_ts */
		if (ind_end_ts >= 0) {
			sprintf(csTmp,"%.*s",v_end_ts.len,v_end_ts.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #3 disabled */
		if (ind_disabled >= 0) {
			fprintf(fp,"%d%c",v_disabled,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #4 create_ts */
		if (ind_create_ts >= 0) {
			sprintf(csTmp,"%.*s",v_create_ts.len,v_create_ts.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #5 create_user */
		if (ind_create_user>= 0) {
			sprintf(csTmp,"%.*s",v_create_user.len,v_create_user.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* new line */
		fprintf(fp,"\n");

 	} while (PD_TRUE);
	/* EXEC SQL CLOSE c_cursor_histbaidbalbatch; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 24;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1345;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto error_histbaidbalbatch;
}



        return iRet;

error_histbaidbalbatch:
DEBUGLOG(("hist_baid_bal_batch error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_histbaidbalbatch; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 24;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1360;
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
    sqlstm.arrsiz = 24;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1375;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int process_hist_baid_bal_detail(FILE *fp)
{               
        int     iRet = SUCCESS;
	char	csTmp[PD_TMP_BUF_LEN+1];

	/* EXEC SQL WHENEVER SQLERROR GOTO error_histbaidbaldetail; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } hv_date;


		int	v_batch_id;
		/* varchar	v_pid_id[10+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_pid_id;

		/* varchar	v_baid[20+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_baid;

		/* varchar	v_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ccy;

		/* varchar	v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		double	v_intransit;
		double	v_lien;
		double	v_available_bal;
		double	v_bal;
		double	v_bal_hkd;
		double	v_bal_hkd_rate;
		double	v_bal_usd;
		double	v_bal_usd_rate;
		/* varchar	v_cat[10+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_cat;

		/* varchar	v_cat_desc[50+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_cat_desc;

		/* varchar	v_acct_type[3+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_acct_type;

		int	v_in_balance;

		short	ind_batch_id = -1;
		short	ind_pid_id = -1;
		short	ind_baid = -1;
		short	ind_ccy = -1;
		short	ind_txn_id = -1;
		short	ind_intransit = -1;
		short	ind_lien = -1;
		short	ind_available_bal = -1;
		short	ind_bal = -1;
		short	ind_bal_hkd = -1;
		short	ind_bal_hkd_rate = -1;
		short	ind_bal_usd = -1;
		short	ind_bal_usd_rate = -1;
		short	ind_cat = -1;
		short	ind_cat_desc = -1;
		short	ind_acct_type = -1;
		short	ind_in_balance = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_date.len = strlen(cs_date);
	memcpy(hv_date.arr,cs_date,hv_date.len);

	/* EXEC SQL DECLARE c_cursor_histbaidbaldetail CURSOR FOR
		SELECT	HD_BATCH_ID,
			HD_PID_ID,
			HD_BAID, 
			HD_CCY, 
			HD_TXN_ID, 
			HD_IN_TRANSIT, 
			HD_LIEN,
			HD_AVAILABLE_BAL, 
			HD_BAL, 
			HD_BAL_HKD, 
			HD_BAL_HKD_RATE, 
			HD_BAL_USD, 
			HD_BAL_USD_RATE,
			HD_CAT,
			HD_CAT_DESC,
			HD_ACCT_TYPE,
			HD_IN_BALANCE
		  FROM	HIST_BAID_BAL_DETAIL
		 WHERE	HD_BATCH_ID IN (SELECT HB_BATCH_ID FROM HIST_BAID_BAL_BATCH
					 WHERE HB_START_DATE >= to_date(:hv_date,'YYYYMMDD')
					   AND HB_END_DATE < to_date(:hv_date,'YYYYMMDD')+1)
		ORDER BY
			HD_BATCH_ID, HD_PID_ID, HD_BAID, HD_CCY, HD_CCY; */ 


	/* EXEC SQL OPEN c_cursor_histbaidbaldetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 24;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0023;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1390;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_date;
 sqlstm.sqhstl[1] = (unsigned long )11;
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
 if (sqlca.sqlcode < 0) goto error_histbaidbaldetail;
}


	do {
		/* EXEC SQL FETCH c_cursor_histbaidbaldetail
		INTO	:v_batch_id:ind_batch_id,
			:v_pid_id:ind_pid_id,
			:v_baid:ind_baid,
			:v_ccy:ind_ccy,
			:v_txn_id:ind_txn_id,
			:v_intransit:ind_intransit,
			:v_lien:ind_lien,
			:v_available_bal:ind_available_bal,
			:v_bal:ind_bal,
			:v_bal_hkd:ind_bal_hkd,
			:v_bal_hkd_rate:ind_bal_hkd_rate,
			:v_bal_usd:ind_bal_usd,
			:v_bal_usd_rate:ind_bal_usd_rate,
			:v_cat:ind_cat,
			:v_cat_desc:ind_cat_desc,
			:v_acct_type:ind_acct_type,
			:v_in_balance:ind_in_balance; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 24;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1413;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_batch_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_pid_id;
  sqlstm.sqhstl[1] = (unsigned long )13;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_pid_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_baid;
  sqlstm.sqhstl[2] = (unsigned long )23;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_baid;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_ccy;
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_ccy;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[4] = (unsigned long )19;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_txn_id;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_intransit;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_intransit;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_lien;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_lien;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_available_bal;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_available_bal;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_bal;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_bal;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_bal_hkd;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_bal_hkd;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_bal_hkd_rate;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_bal_hkd_rate;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_bal_usd;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_bal_usd;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_bal_usd_rate;
  sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_bal_usd_rate;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_cat;
  sqlstm.sqhstl[13] = (unsigned long )13;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_cat;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_cat_desc;
  sqlstm.sqhstl[14] = (unsigned long )53;
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_cat_desc;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_acct_type;
  sqlstm.sqhstl[15] = (unsigned long )6;
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_acct_type;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&v_in_balance;
  sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)&ind_in_balance;
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
  if (sqlca.sqlcode < 0) goto error_histbaidbaldetail;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

/* Field #0 batch_id */
		if (ind_batch_id >= 0) {
			fprintf(fp,"%d%c",v_batch_id,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #1 pid_id */
		if (ind_pid_id >= 0) {
			sprintf(csTmp,"%.*s",v_pid_id.len,v_pid_id.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #2 baid */
		if (ind_baid >= 0) {
			sprintf(csTmp,"%.*s",v_baid.len,v_baid.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #3 ccy */
		if (ind_ccy >= 0) {
			sprintf(csTmp,"%.*s",v_ccy.len,v_ccy.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #4 txn_id */
		if (ind_txn_id >= 0) {
			sprintf(csTmp,"%.*s",v_txn_id.len,v_txn_id.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #5 intransit */
		if (ind_intransit >= 0) {
			fprintf(fp,"%.2f%c",v_intransit,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #6 lien */
		if (ind_lien >= 0) {
			fprintf(fp,"%.2f%c",v_lien,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #7 available_bal */
		if (ind_available_bal >= 0) {
			fprintf(fp,"%.2f%c",v_available_bal,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #8 bal */
		if (ind_bal >= 0) {
			fprintf(fp,"%.2f%c",v_bal,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #9 bal_hkd */
		if (ind_bal_hkd >= 0) {
			fprintf(fp,"%.2f%c",v_bal_hkd,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #10 bal_hkd_rate */
		if (ind_bal_hkd_rate >= 0) {
			fprintf(fp,"%.5f%c",v_bal_hkd_rate,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #11 bal_usd */
		if (ind_bal_usd >= 0) {
			fprintf(fp,"%.2f%c",v_bal_usd,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #12 bal_usd_rate */
		if (ind_bal_usd_rate >= 0) {
			fprintf(fp,"%.5f%c",v_bal_usd_rate,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #13 cat */
		if (ind_cat >= 0) {
			sprintf(csTmp,"%.*s",v_cat.len,v_cat.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #14 cat_desc */
		if (ind_cat_desc >= 0) {
			sprintf(csTmp,"%.*s",v_cat_desc.len,v_cat_desc.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #15 acct_type */
		if (ind_acct_type >= 0) {
			sprintf(csTmp,"%.*s",v_acct_type.len,v_acct_type.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #16 in_balance */
		if (ind_in_balance >= 0) {
			fprintf(fp,"%d%c",v_in_balance,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* new line */
		fprintf(fp,"\n");

 	} while (PD_TRUE);
	/* EXEC SQL CLOSE c_cursor_histbaidbaldetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 24;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1496;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto error_histbaidbaldetail;
}



        return iRet;

error_histbaidbaldetail:
DEBUGLOG(("hist_baid_bal_detail error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_histbaidbaldetail; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 24;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1511;
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
    sqlstm.arrsiz = 24;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1526;
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

        if ( (!strcmp(cs_table,"")) || (!strcmp(cs_date,"")) )
                return FAILURE;

        return SUCCESS;
}

