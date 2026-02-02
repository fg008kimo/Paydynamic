
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
    "extract_rptcommon.pc"
};


static unsigned int sqlctx = 80263259;


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
   unsigned char  *sqhstv[23];
   unsigned long  sqhstl[23];
            int   sqhsts[23];
            short *sqindv[23];
            int   sqinds[23];
   unsigned long  sqharm[23];
   unsigned long  *sqharc[23];
   unsigned short  sqadto[23];
   unsigned short  sqtdso[23];
} sqlstm = {12,23};

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
5,0,0,0,0,0,13,72,0,0,13,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,
0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,4,0,0,
72,0,0,0,0,0,13,215,0,0,23,1,0,1,0,1,102,0,0,2,9,0,0,2,1,0,0,2,1,0,0,2,3,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
179,0,0,0,0,0,13,430,0,0,9,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,4,0,0,2,3,0,0,2,4,0,0,
230,0,0,0,0,0,13,539,0,0,7,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,4,0,0,
273,0,0,0,0,0,13,634,0,0,7,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,
9,0,0,2,4,0,0,
316,0,0,0,0,0,13,733,0,0,8,1,0,1,0,1,102,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,
9,0,0,2,9,0,0,2,4,0,0,
363,0,0,0,0,0,13,860,0,0,19,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,4,0,
0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,
454,0,0,0,0,0,13,1044,0,0,19,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,4,0,
0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,
545,0,0,0,0,0,13,1213,0,0,12,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,
608,0,0,0,0,0,13,1347,0,0,12,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,
671,0,0,0,0,0,13,1476,0,0,10,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,
726,0,0,0,0,0,13,1584,0,0,6,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,3,0,0,
765,0,0,0,0,0,13,1671,0,0,8,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,4,0,0,
812,0,0,0,0,0,13,1755,0,0,8,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,4,0,0,
859,0,0,0,0,0,13,1839,0,0,8,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,4,0,0,
906,0,0,0,0,0,13,1925,0,0,8,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,4,0,0,
953,0,0,0,0,0,13,2004,0,0,8,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,4,0,0,
1000,0,0,0,0,0,13,2119,0,0,23,1,0,1,0,1,102,0,0,2,9,0,0,2,1,0,0,2,1,0,0,2,3,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
1107,0,0,0,0,0,13,2308,0,0,6,1,0,1,0,1,102,0,0,2,4,0,0,2,3,0,0,2,1,0,0,2,1,0,0,
2,9,0,0,
};


/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/02/03              Cody Chan
                                                   2012/07/13              Gilbert Lum

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlca.h>
#include <sqlcpr.h>
#include "common.h"
#include "utilitys.h"
#include "batchcommon.h"

char	cDebug;
#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define PD_MY_DELIMITOR ','
#define PD_TR           "<tr>"
#define PD_TD           "<td>"
#define PD_TD_STYLE     "<td class=\"format\">"
#define PD_TR_END       "</tr>"
#define PD_TD_END       "</td>"
#define START_POS       3
#define CONTENT_POS     9

int Extract_RPT001(const char* csFileName, SQL_CURSOR c_input_cursor)
{
	int	iRet = SUCCESS;
DEBUGLOG(("Extract_RPT001\n"));
	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt001_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar v_txn_id[PD_TXN_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_txn_id;

		/* varchar v_merchant_ref[PD_MERCHANT_REF_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

                /* varchar v_txn_code[PD_TXN_CODE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

                /* varchar v_txn_code_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_code_desc;

                double  v_open_bal;
                double  v_current_bal;
                /* varchar v_txn_element_type[PD_TXN_ELEMENT_TYPE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_txn_element_type;

                /* varchar v_txn_element_type_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_element_type_desc;

                int     v_exec_seq;
                /* varchar v_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ccy;

                /* varchar v_amt_type[PD_AMT_TYPE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_amt_type;

                double  v_bal;

                short   ind_txn_id = -1;
		short	ind_merchant_ref = -1;
                short   ind_txn_code = -1;
                short   ind_txn_code_desc = -1;
                short   ind_open_bal = -1;
                short   ind_current_bal = -1;
                short   ind_txn_element_type = -1;
                short   ind_txn_element_type_desc = -1;
                short   ind_exec_seq = -1;
                short   ind_ccy = -1;
                short   ind_amt_type = -1;
                short   ind_bal = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                /* EXEC SQL FETCH :c_input_cursor
                INTO
                        :v_txn_id:ind_txn_id,
                        :v_merchant_ref:ind_merchant_ref,
                        :v_txn_code:ind_txn_code,
                        :v_txn_code_desc:ind_txn_code_desc,
                        :v_open_bal:ind_open_bal,
                        :v_current_bal:ind_current_bal,
                        :v_txn_element_type:ind_txn_element_type,
                        :v_txn_element_type_desc:ind_txn_element_type_desc,
                        :v_exec_seq:ind_exec_seq,
                        :v_ccy:ind_ccy,
                        :v_amt_type:ind_amt_type,
                        :v_bal:ind_bal; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 13;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )5;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_id;
                sqlstm.sqhstl[1] = (unsigned long )23;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_txn_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_merchant_ref;
                sqlstm.sqhstl[2] = (unsigned long )53;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_merchant_ref;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_code;
                sqlstm.sqhstl[3] = (unsigned long )6;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_txn_code;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_txn_code_desc;
                sqlstm.sqhstl[4] = (unsigned long )53;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_txn_code_desc;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_open_bal;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_open_bal;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_current_bal;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_current_bal;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_txn_element_type;
                sqlstm.sqhstl[7] = (unsigned long )7;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_txn_element_type;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_txn_element_type_desc;
                sqlstm.sqhstl[8] = (unsigned long )53;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_txn_element_type_desc;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_exec_seq;
                sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_exec_seq;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_ccy;
                sqlstm.sqhstl[10] = (unsigned long )6;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_ccy;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_amt_type;
                sqlstm.sqhstl[11] = (unsigned long )5;
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_amt_type;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
                sqlstm.sqhstv[12] = (unsigned char  *)&v_bal;
                sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_bal;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
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
                if (sqlca.sqlcode == 1403) break;
                if (sqlca.sqlcode < 0) goto extract_rpt001_error;
}


/* txn id */
		v_txn_id.arr[v_txn_id.len] = '\0';
/* merchant ref */
		v_merchant_ref.arr[v_merchant_ref.len] = '\0';
/* txn code */
		v_txn_code.arr[v_txn_code.len] = '\0';
/* txn code desc */
		v_txn_code_desc.arr[v_txn_code.len] = '\0';
/*open bal */
		if (ind_open_bal < 0) 
			v_open_bal = 0.0;

/*current bal */
		if (ind_current_bal < 0) 
			v_current_bal = 0.0;
/*txn element */
		v_txn_element_type.arr[v_txn_element_type.len] = '\0';
/*txn element desc */
		v_txn_element_type_desc.arr[v_txn_element_type_desc.len] = '\0';

/*exec seq */
		if (ind_exec_seq < 0) 
			v_exec_seq = 0;

/*ccy */
		v_ccy.arr[v_ccy.len] = '\0';
/*amt_type */
		v_amt_type.arr[v_amt_type.len] = '\0';
/*bal */
		if (ind_bal < 0) 
			v_bal = 0.0;
	}


	return iRet;
extract_rpt001_error:
DEBUGLOG(("extract_rpt001 code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}




int Extract_RPT002(const char* csFileName, SQL_CURSOR c_input_cursor)
{
DEBUGLOG(("Extract_RPT002\n"));
	int	iRet = SUCCESS;

	char	*csStatus;
	char	*csAr;
	char	*csEcRef;
	char	csEc2Ref[PD_TMP_BUF_LEN+1];

	char	csLine[PD_TMP_BUF_LEN*20+1];

	FILE *fp;
	fp = fopen(csFileName,"w");
	if (fp == NULL) {
DEBUGLOG(("Extract_RPT002:unable to open [%s]\n",csFileName));
                return FAILURE;
	}
DEBUGLOG(("Testing open file!!\n"));

	fprintf(fp,"<html><body><table>\n");

	fprintf(fp,"%s%sPH Txn ID%s%sPH Txn Code%s%sPH Status%s%sAR_IND%s%sClient Name%s%sMerchant ID%s%sMerchant Refernece%s%sEC2 Refernece%s%sPSP Name%s%sPSP Txn ID%s%sBank Bill No.%s%sTxn Ccy%s%sTxn Amount%s%sPSP Service Fee%s%sPH Posting Date%s%sMerchant Txn Date%s%sPH Txn Date%s%sPSP Txn Date%s%sLast Update Date%s%s\n",PD_TR,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TR_END);
DEBUGLOG(("Testing open filebbbb!!\n"));
	fprintf(fp,"<style type=\"text/css\"> .format{ mso-number-format:'\\@';} </style>\n");
	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt002_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


                //varchar hv_txn_date[PD_DATE_LEN];

                /* varchar v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

                char    v_status;
                char    v_ar_ind;
                int     v_internal_code;
                /* varchar v_response_code[PD_RESPONSE_CODE_LEN + 3]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_response_code;

                //varchar v_response_code[6 + 1];
                /* varchar v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

                /* varchar v_merchant_ref[PD_MERCHANT_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

                /* varchar v_psp_name[PD_PSP_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_name;

                /* varchar v_tid[PD_MERCHANT_REF_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_tid;

                /* varchar v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

                double  v_txn_amount;
                double  v_service_fee;
                /* varchar v_merchant_txn_date[PD_DATE_LEN + PD_TIME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_merchant_txn_date;

                /* varchar v_local_txn_date[PD_DATE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_local_txn_date;

                /* varchar v_local_txn_time[PD_DATE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_local_txn_time;

                /* varchar v_psp_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_psp_txn_date;

                /* varchar v_host_posting_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_host_posting_date;

                /* varchar v_txn_code_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_code_desc;

                /* varchar v_txn_code[PD_TXN_CODE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

                /* varchar v_client_name[PD_CLIENT_NAME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_client_name;

                /* varchar v_last_updatetime[PD_DATE_LEN + PD_TIME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_last_updatetime;

                /* varchar v_bill_no[PD_BANK_BILL_NO_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bill_no;


                short   ind_txn_id = -1;
                short   ind_status = -1;
                short   ind_ar_ind = -1;
                short   ind_internal_code = -1;
                short   ind_response_code = -1;
                short   ind_merchant_id = -1;
                short   ind_merchant_ref = -1;
                short   ind_psp_name = -1;
                short   ind_tid = -1;
                short   ind_txn_ccy = -1;
                short   ind_txn_amount = -1;
                short   ind_service_fee = -1;
                short   ind_merchant_txn_date = -1;
                short   ind_local_txn_date = -1;
                short   ind_local_txn_time = -1;
                short   ind_psp_txn_date = -1;
                short   ind_host_posting_date = -1;
                short   ind_txn_code_desc = -1;
                short   ind_txn_code = -1;
                short   ind_client_name = -1;
                short   ind_last_updatetime = -1;
                short   ind_bill_no = -1;


        /* EXEC SQL END DECLARE SECTION; */ 

	
	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                /* EXEC SQL FETCH :c_input_cursor
                INTO
			:v_txn_id:ind_txn_id,
                        :v_ar_ind:ind_ar_ind,
                        :v_status:ind_status,
                        :v_internal_code:ind_internal_code,
                        :v_response_code:ind_response_code,
                        :v_merchant_id:ind_merchant_id,
                        :v_merchant_ref:ind_merchant_ref,
                        :v_psp_name:ind_psp_name,
                        :v_tid:ind_tid,
                        :v_txn_ccy:ind_txn_ccy,
                        :v_txn_amount:ind_txn_amount,
                        :v_service_fee:ind_service_fee,
                        :v_merchant_txn_date:ind_merchant_txn_date,
                        :v_local_txn_date:ind_local_txn_date,
                        :v_local_txn_time:ind_local_txn_time,
                        :v_psp_txn_date:ind_psp_txn_date,
                        :v_host_posting_date:ind_host_posting_date,
                        :v_txn_code_desc:ind_txn_code_desc,
                        :v_txn_code:ind_txn_code,
                        :v_last_updatetime:ind_last_updatetime,
                        :v_client_name:ind_client_name,
                        :v_bill_no:ind_bill_no; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 23;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )72;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_id;
                sqlstm.sqhstl[1] = (unsigned long )19;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_txn_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_ar_ind;
                sqlstm.sqhstl[2] = (unsigned long )1;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_ar_ind;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_status;
                sqlstm.sqhstl[3] = (unsigned long )1;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_status;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_internal_code;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_internal_code;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_response_code;
                sqlstm.sqhstl[5] = (unsigned long )9;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_response_code;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_merchant_id;
                sqlstm.sqhstl[6] = (unsigned long )18;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_merchant_id;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_merchant_ref;
                sqlstm.sqhstl[7] = (unsigned long )53;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_merchant_ref;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_psp_name;
                sqlstm.sqhstl[8] = (unsigned long )53;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_psp_name;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_tid;
                sqlstm.sqhstl[9] = (unsigned long )53;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_tid;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_txn_ccy;
                sqlstm.sqhstl[10] = (unsigned long )6;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_txn_ccy;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_amount;
                sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_txn_amount;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
                sqlstm.sqhstv[12] = (unsigned char  *)&v_service_fee;
                sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_service_fee;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
                sqlstm.sqhstv[13] = (unsigned char  *)&v_merchant_txn_date;
                sqlstm.sqhstl[13] = (unsigned long )17;
                sqlstm.sqhsts[13] = (         int  )0;
                sqlstm.sqindv[13] = (         short *)&ind_merchant_txn_date;
                sqlstm.sqinds[13] = (         int  )0;
                sqlstm.sqharm[13] = (unsigned long )0;
                sqlstm.sqadto[13] = (unsigned short )0;
                sqlstm.sqtdso[13] = (unsigned short )0;
                sqlstm.sqhstv[14] = (unsigned char  *)&v_local_txn_date;
                sqlstm.sqhstl[14] = (unsigned long )11;
                sqlstm.sqhsts[14] = (         int  )0;
                sqlstm.sqindv[14] = (         short *)&ind_local_txn_date;
                sqlstm.sqinds[14] = (         int  )0;
                sqlstm.sqharm[14] = (unsigned long )0;
                sqlstm.sqadto[14] = (unsigned short )0;
                sqlstm.sqtdso[14] = (unsigned short )0;
                sqlstm.sqhstv[15] = (unsigned char  *)&v_local_txn_time;
                sqlstm.sqhstl[15] = (unsigned long )11;
                sqlstm.sqhsts[15] = (         int  )0;
                sqlstm.sqindv[15] = (         short *)&ind_local_txn_time;
                sqlstm.sqinds[15] = (         int  )0;
                sqlstm.sqharm[15] = (unsigned long )0;
                sqlstm.sqadto[15] = (unsigned short )0;
                sqlstm.sqtdso[15] = (unsigned short )0;
                sqlstm.sqhstv[16] = (unsigned char  *)&v_psp_txn_date;
                sqlstm.sqhstl[16] = (unsigned long )11;
                sqlstm.sqhsts[16] = (         int  )0;
                sqlstm.sqindv[16] = (         short *)&ind_psp_txn_date;
                sqlstm.sqinds[16] = (         int  )0;
                sqlstm.sqharm[16] = (unsigned long )0;
                sqlstm.sqadto[16] = (unsigned short )0;
                sqlstm.sqtdso[16] = (unsigned short )0;
                sqlstm.sqhstv[17] = (unsigned char  *)&v_host_posting_date;
                sqlstm.sqhstl[17] = (unsigned long )11;
                sqlstm.sqhsts[17] = (         int  )0;
                sqlstm.sqindv[17] = (         short *)&ind_host_posting_date;
                sqlstm.sqinds[17] = (         int  )0;
                sqlstm.sqharm[17] = (unsigned long )0;
                sqlstm.sqadto[17] = (unsigned short )0;
                sqlstm.sqtdso[17] = (unsigned short )0;
                sqlstm.sqhstv[18] = (unsigned char  *)&v_txn_code_desc;
                sqlstm.sqhstl[18] = (unsigned long )53;
                sqlstm.sqhsts[18] = (         int  )0;
                sqlstm.sqindv[18] = (         short *)&ind_txn_code_desc;
                sqlstm.sqinds[18] = (         int  )0;
                sqlstm.sqharm[18] = (unsigned long )0;
                sqlstm.sqadto[18] = (unsigned short )0;
                sqlstm.sqtdso[18] = (unsigned short )0;
                sqlstm.sqhstv[19] = (unsigned char  *)&v_txn_code;
                sqlstm.sqhstl[19] = (unsigned long )6;
                sqlstm.sqhsts[19] = (         int  )0;
                sqlstm.sqindv[19] = (         short *)&ind_txn_code;
                sqlstm.sqinds[19] = (         int  )0;
                sqlstm.sqharm[19] = (unsigned long )0;
                sqlstm.sqadto[19] = (unsigned short )0;
                sqlstm.sqtdso[19] = (unsigned short )0;
                sqlstm.sqhstv[20] = (unsigned char  *)&v_last_updatetime;
                sqlstm.sqhstl[20] = (unsigned long )17;
                sqlstm.sqhsts[20] = (         int  )0;
                sqlstm.sqindv[20] = (         short *)&ind_last_updatetime;
                sqlstm.sqinds[20] = (         int  )0;
                sqlstm.sqharm[20] = (unsigned long )0;
                sqlstm.sqadto[20] = (unsigned short )0;
                sqlstm.sqtdso[20] = (unsigned short )0;
                sqlstm.sqhstv[21] = (unsigned char  *)&v_client_name;
                sqlstm.sqhstl[21] = (unsigned long )53;
                sqlstm.sqhsts[21] = (         int  )0;
                sqlstm.sqindv[21] = (         short *)&ind_client_name;
                sqlstm.sqinds[21] = (         int  )0;
                sqlstm.sqharm[21] = (unsigned long )0;
                sqlstm.sqadto[21] = (unsigned short )0;
                sqlstm.sqtdso[21] = (unsigned short )0;
                sqlstm.sqhstv[22] = (unsigned char  *)&v_bill_no;
                sqlstm.sqhstl[22] = (unsigned long )53;
                sqlstm.sqhsts[22] = (         int  )0;
                sqlstm.sqindv[22] = (         short *)&ind_bill_no;
                sqlstm.sqinds[22] = (         int  )0;
                sqlstm.sqharm[22] = (unsigned long )0;
                sqlstm.sqadto[22] = (unsigned short )0;
                sqlstm.sqtdso[22] = (unsigned short )0;
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
                if (sqlca.sqlcode == 1403) break;
                if (sqlca.sqlcode < 0) goto extract_rpt002_error;
}



/* txn id */
		v_txn_id.arr[v_txn_id.len] = '\0';

/* txn_desc */
		v_txn_code_desc.arr[v_txn_code_desc.len] = '\0';

/* status */
		if (ind_status < 0 ){
			csStatus = strdup("");
		}else {
			if (v_status == 'C')
				csStatus = strdup("Completed");
			else if(v_status == 'W') 
				csStatus = strdup("Pending");
			else
				csStatus = strdup("Processing");
		}

/* ar ind */
		if (ind_ar_ind < 0 )
			csAr = strdup("");
		else {
			if (v_ar_ind == 'A')
				csAr = strdup("Accept");
			else 
				csAr = strdup("Reject");
		}


/* internal_code */
//		if (ind_internal_code < 0)
//			v_internal_code = 0;

/* response_code */
		v_response_code.arr[v_response_code.len] = '\0';

/* client_name */
		v_client_name.arr[v_client_name.len] = '\0';

/* merchant_id */
		v_merchant_id.arr[v_merchant_id.len] = '\0';

/* merchant_ref */
		v_merchant_ref.arr[v_merchant_ref.len] = '\0';

/* EC2_ref */
		v_txn_code.arr[v_txn_code.len] = '\0';

		csEcRef = strdup("");

		if(strncmp((const char*)v_txn_code.arr,PD_DEPOSIT_TXN_CODE,PD_TXN_CODE_LEN)==0){
			strcpy(csEcRef,(const char *)v_merchant_ref.arr);
			csEcRef[v_merchant_ref.len]='\0';
			sprintf(csEc2Ref, "%c%s", csEcRef[START_POS],&csEcRef[CONTENT_POS]);
		}
		else
			csEc2Ref[0] = '\0';

/* psp_name */
		v_psp_name.arr[v_psp_name.len] = '\0';

/* tid */
		v_tid.arr[v_tid.len] = '\0';

/* bank_bill_no */
                if (ind_bill_no< 0 ){
                        strcpy((char*)v_bill_no.arr,"N/A");
                        v_bill_no.len=strlen("N/A");
                }

/* txn_ccy */
		v_txn_ccy.arr[v_txn_ccy.len] = '\0';

/* txn_amount */
		if (ind_txn_amount < 0 )
			v_txn_amount = 0;

/* service_fee */
		if (ind_service_fee < 0 )
			v_service_fee = 0;

/* host posting date */
		v_host_posting_date.arr[v_host_posting_date.len] = '\0';

/* merchant_txn_date */
                v_merchant_txn_date.arr[v_merchant_txn_date.len] = '\0';

/* local_txn_date and time*/
                v_local_txn_date.arr[v_local_txn_date.len] = '\0';

                v_local_txn_time.arr[v_local_txn_time.len] = '\0';
                //printf("%s%.*s %.*s%s",PD_TD_STYLE,v_local_txn_date.len,v_local_txn_date.arr,v_local_txn_time.len,v_local_txn_time.arr,PD_TD_END);

/* psp_txn_date */
                v_psp_txn_date.arr[v_psp_txn_date.len] = '\0';

/* last_updatetime */
                v_last_updatetime.arr[v_last_updatetime.len] = '\0';
	
		sprintf(csLine, "%s%s%.*s%s %s%.*s%s %s%s%s %s%s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%f%s %s%f%s %s%.*s%s   %s%.*s%s   %s%.*s %.*s%s   %s%.*s%s   %s%.*s%s%s",
			PD_TR, PD_TD_STYLE,v_txn_id.len,v_txn_id.arr,PD_TD_END,
			PD_TD,v_txn_code_desc.len,v_txn_code_desc.arr,PD_TD_END,
			PD_TD,csStatus,PD_TD_END,
			PD_TD,csAr,PD_TD_END,
			//PD_TD,v_response_code.len,v_response_code.arr,PD_TD_END,
			PD_TD,v_client_name.len,v_client_name.arr,PD_TD_END,
			PD_TD_STYLE,v_merchant_id.len,v_merchant_id.arr,PD_TD_END,
			PD_TD_STYLE,v_merchant_ref.len,v_merchant_ref.arr,PD_TD_END,
			PD_TD_STYLE,csEc2Ref,PD_TD_END,
			PD_TD,v_psp_name.len,v_psp_name.arr,PD_TD_END,
			PD_TD_STYLE,v_tid.len,v_tid.arr,PD_TD_END,
			PD_TD_STYLE,v_bill_no.len,v_bill_no.arr,PD_TD_END,
			PD_TD,v_txn_ccy.len,v_txn_ccy.arr,PD_TD_END,
			PD_TD,v_txn_amount,PD_TD_END,
			PD_TD,v_service_fee,PD_TD_END,
			PD_TD_STYLE,v_host_posting_date.len,v_host_posting_date.arr,PD_TD_END,
			PD_TD_STYLE,v_merchant_txn_date.len,v_merchant_txn_date.arr,PD_TD_END,
			PD_TD_STYLE,v_local_txn_date.len,v_local_txn_date.arr,v_local_txn_time.len,v_local_txn_time.arr,PD_TD_END,
			PD_TD_STYLE,v_psp_txn_date.len,v_psp_txn_date.arr,PD_TD_END,
			PD_TD_STYLE,v_last_updatetime.len,v_last_updatetime.arr,PD_TD_END, PD_TR_END

			);


		fprintf(fp,"%s\n",csLine);

	        FREE_ME(csStatus);
       		FREE_ME(csAr);
	        FREE_ME(csEcRef);
	}
	fprintf(fp,"</table></body></html>\n");
	fclose(fp);
DEBUGLOG(("Extract_RPT002 iRet = [%d]\n",iRet));

	return iRet;
extract_rpt002_error:
DEBUGLOG(("extract_rpt002 code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	fclose(fp);
        return FAILURE;
}


int Extract_RPT003(const char* csFileName, SQL_CURSOR c_input_cursor)
{
DEBUGLOG(("Extract_RPT003\n"));
	int	iRet = SUCCESS;

	char	csLine[PD_TMP_BUF_LEN*8+1];

	FILE *fp;
	fp = fopen(csFileName,"w");
	if (fp == NULL) {
DEBUGLOG(("Extract_RPT003:unable to open [%s]\n",csFileName));
                return FAILURE;
	}

	fprintf(fp,"<html><body><table>\n");
	fprintf(fp,"%s%sDate%s%sTxn Desc%s%sService Desc%s%sPSP Name%s%sTxn_ccy%s%sTransaction Amount%s%sTransaction Count%s%sAverage Transaction Amount%s%s\n",PD_TR,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TR_END);
	fprintf(fp,"<style type=\"text/css\"> .format{ mso-number-format:'\\@';} </style>\n");


	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt003_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar v_host_posting_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_host_posting_date;

                /* varchar v_txn_code_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_code_desc;

                /* varchar v_service_code_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_service_code_desc;

		/* varchar v_psp_name[PD_PSP_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_name;

                /* varchar v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

                double  v_txn_amount;
		int	v_count;
                double  v_avg_txn_amount;

		short   ind_host_posting_date = -1;
		short   ind_txn_code_desc = -1;
		short   ind_service_code_desc = -1;
		short   ind_psp_name = -1;
		short   ind_txn_ccy = -1;
		short	ind_txn_amount = -1;
		short	ind_count = -1;
		short	ind_avg_txn_amount = -1;

        /* EXEC SQL END DECLARE SECTION; */ 

	
	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                /* EXEC SQL FETCH :c_input_cursor
                INTO
                        :v_host_posting_date:ind_host_posting_date,
			:v_txn_code_desc:ind_txn_code_desc,
			:v_service_code_desc:ind_service_code_desc,
                        :v_psp_name:ind_psp_name,
			:v_txn_ccy:ind_txn_ccy,
			:v_txn_amount:ind_txn_amount,
			:v_count:ind_count,
			:v_avg_txn_amount:ind_avg_txn_amount; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 23;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )179;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_host_posting_date;
                sqlstm.sqhstl[1] = (unsigned long )11;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_host_posting_date;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_code_desc;
                sqlstm.sqhstl[2] = (unsigned long )53;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_txn_code_desc;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_service_code_desc;
                sqlstm.sqhstl[3] = (unsigned long )53;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_service_code_desc;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_psp_name;
                sqlstm.sqhstl[4] = (unsigned long )53;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_psp_name;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_txn_ccy;
                sqlstm.sqhstl[5] = (unsigned long )6;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_txn_ccy;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_txn_amount;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_txn_amount;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_count;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_count;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_avg_txn_amount;
                sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_avg_txn_amount;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
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
                if (sqlca.sqlcode == 1403) break;
                if (sqlca.sqlcode < 0) goto extract_rpt003_error;
}



/* host posting date */
		v_host_posting_date.arr[v_host_posting_date.len] = '\0';

/* txn_desc */
		v_txn_code_desc.arr[v_txn_code_desc.len] = '\0';

/* service_desc */
		v_service_code_desc.arr[v_service_code_desc.len] = '\0';

/* psp_name */
		v_psp_name.arr[v_psp_name.len] = '\0';

/* txn_ccy */
		v_txn_ccy.arr[v_txn_ccy.len] = '\0';

/* txn_amount */
		if (ind_txn_amount < 0) 
			v_txn_amount = 0.0;

/*count*/
		if (ind_count < 0) 
			v_count = 0;

/*avg amount*/
		if (ind_avg_txn_amount < 0) 
			v_avg_txn_amount = 0.0;

		sprintf(csLine, "%s%s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%f%s %s%d%s %s%f%s%s",
			PD_TR, PD_TD_STYLE,v_host_posting_date.len,v_host_posting_date.arr,PD_TD_END,
			PD_TD,v_txn_code_desc.len,v_txn_code_desc.arr,PD_TD_END,
			PD_TD,v_service_code_desc.len,v_service_code_desc.arr,PD_TD_END,
			PD_TD,v_psp_name.len,v_psp_name.arr,PD_TD_END,
			PD_TD,v_txn_ccy.len,v_txn_ccy.arr,PD_TD_END,
			PD_TD,v_txn_amount,PD_TD_END,
			PD_TD,v_count,PD_TD_END,
			PD_TD,v_avg_txn_amount,PD_TD_END, PD_TR_END

			);

		fprintf(fp,"%s\n",csLine);
	}
	fprintf(fp,"</table></body></html>\n");
	fclose(fp);
DEBUGLOG(("Extract_RPT003 iRet = [%d]\n",iRet));

	return iRet;
extract_rpt003_error:
DEBUGLOG(("extract_rpt003 code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	fclose(fp);
        return FAILURE;
}


int Extract_RPT004(const char* csFileName, SQL_CURSOR c_input_cursor)
{
DEBUGLOG(("Extract_RPT004\n"));
	int	iRet = SUCCESS;

	char	csLine[PD_TMP_BUF_LEN*8+1];

	FILE *fp;
	fp = fopen(csFileName,"w");
	if (fp == NULL) {
DEBUGLOG(("Extract_RPT004:unable to open [%s]\n",csFileName));
                return FAILURE;
	}

	fprintf(fp,"<html><body><table>\n");
	fprintf(fp,"%s%sMerchant ID%s%sMerchant Name%s%sService Desc%s%sCurrency%s%sAmount Type%s%sTotal Amount%s%s\n",PD_TR,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TR_END);
	fprintf(fp,"<style type=\"text/css\"> .format{ mso-number-format:'\\@';} </style>\n");


	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt004_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

                /* varchar v_merchant_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_name;

                /* varchar v_service_code_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_service_code_desc;

                /* varchar v_te_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_te_ccy;

                /* varchar v_te_amt_type[PD_AMT_TYPE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_te_amt_type;

                double  v_te_amount;

		short   ind_merchant_id = -1;
		short   ind_merchant_name = -1;
		short   ind_service_code_desc = -1;
		short   ind_te_ccy = -1;
                short   ind_te_amt_type = -1;
		short	ind_te_amount = -1;

        /* EXEC SQL END DECLARE SECTION; */ 



	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                /* EXEC SQL FETCH :c_input_cursor
                INTO
                        :v_merchant_id:ind_merchant_id,
                        :v_merchant_name:ind_merchant_name,
			:v_service_code_desc:ind_service_code_desc,
			:v_te_ccy:ind_te_ccy,
                        :v_te_amt_type:ind_te_amt_type,
                        :v_te_amount:ind_te_amount; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 23;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )230;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_merchant_id;
                sqlstm.sqhstl[1] = (unsigned long )18;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_merchant_name;
                sqlstm.sqhstl[2] = (unsigned long )53;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_merchant_name;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_service_code_desc;
                sqlstm.sqhstl[3] = (unsigned long )53;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_service_code_desc;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_te_ccy;
                sqlstm.sqhstl[4] = (unsigned long )6;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_te_ccy;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_te_amt_type;
                sqlstm.sqhstl[5] = (unsigned long )5;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_te_amt_type;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_te_amount;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_te_amount;
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
                if (sqlca.sqlcode == 1403) break;
                if (sqlca.sqlcode < 0) goto extract_rpt004_error;
}



/* merchant_id */
                v_merchant_id.arr[v_merchant_id.len] = '\0';

/* merchant_name */
		v_merchant_name.arr[v_merchant_name.len] = '\0';

/* service_desc */
		v_service_code_desc.arr[v_service_code_desc.len] = '\0';

/* te_ccy */
		v_te_ccy.arr[v_te_ccy.len] = '\0';

/* te_amount_type */
		v_te_amt_type.arr[v_te_amt_type.len] = '\0';

/* te_amount */
		if (ind_te_amount < 0) 
			v_te_amount = 0.0;

	sprintf(csLine, "%s%s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%f%s%s",
			PD_TR, PD_TD_STYLE,v_merchant_id.len,v_merchant_id.arr,PD_TD_END,
			PD_TD,v_merchant_name.len,v_merchant_name.arr,PD_TD_END,
			PD_TD,v_service_code_desc.len,v_service_code_desc.arr,PD_TD_END,
			PD_TD,v_te_ccy.len,v_te_ccy.arr,PD_TD_END,
			PD_TD,v_te_amt_type.len,v_te_amt_type.arr,PD_TD_END,
			PD_TD,v_te_amount,PD_TD_END, PD_TR_END

			);

		fprintf(fp,"%s\n",csLine);
	}
	fprintf(fp,"</table></body></html>\n");
	fclose(fp);
DEBUGLOG(("Extract_RPT004 iRet = [%d]\n",iRet));

	return iRet;
extract_rpt004_error:
DEBUGLOG(("extract_rpt004 code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return FAILURE;
}


int Extract_RPT005(const char* csFileName, SQL_CURSOR c_input_cursor)
{
DEBUGLOG(("Extract_RPT005\n"));
	int	iRet = SUCCESS;

	char	csLine[PD_TMP_BUF_LEN*8+1];

	FILE *fp;
	fp = fopen(csFileName,"w");
	if (fp == NULL) {
DEBUGLOG(("Extract_RPT005:unable to open [%s]\n",csFileName));
                return FAILURE;
	}

	fprintf(fp,"<html><body><table>\n");
	fprintf(fp,"%s%sTxn Desc%s%sStatus%s%sTransaction Count%s%sCurrency%s%sMarkup Amount%s%s\n",PD_TR,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TR_END);
	fprintf(fp,"<style type=\"text/css\"> .format{ mso-number-format:'\\@';} </style>\n");


	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt005_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar v_txn_code_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_code_desc;

                /* varchar v_dm_status_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_dm_status_desc;

		int	v_count;
                /* varchar v_te_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_te_ccy;

                /* varchar v_te_amt_type[PD_AMT_TYPE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_te_amt_type;

                double  v_te_amount;

		short   ind_txn_code_desc = -1;
		short   ind_dm_status_desc = -1;
		short	ind_count = -1;
		short   ind_te_ccy = -1;
                short   ind_te_amt_type = -1;
		short	ind_te_amount = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                /* EXEC SQL FETCH :c_input_cursor
                INTO
			:v_txn_code_desc:ind_txn_code_desc,
			:v_dm_status_desc:ind_dm_status_desc,
			:v_count:ind_count,
                        :v_te_amt_type:ind_te_amt_type,
			:v_te_ccy:ind_te_ccy,
                        :v_te_amount:ind_te_amount; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 23;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )273;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_code_desc;
                sqlstm.sqhstl[1] = (unsigned long )53;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_txn_code_desc;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_dm_status_desc;
                sqlstm.sqhstl[2] = (unsigned long )53;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_dm_status_desc;
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
                sqlstm.sqhstv[4] = (unsigned char  *)&v_te_amt_type;
                sqlstm.sqhstl[4] = (unsigned long )5;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_te_amt_type;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_te_ccy;
                sqlstm.sqhstl[5] = (unsigned long )6;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_te_ccy;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_te_amount;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_te_amount;
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
                if (sqlca.sqlcode == 1403) break;
                if (sqlca.sqlcode < 0) goto extract_rpt005_error;
}



/* txn_desc */
		v_txn_code_desc.arr[v_txn_code_desc.len] = '\0';

/* Status_desc */
		v_dm_status_desc.arr[v_dm_status_desc.len] = '\0';

/*count*/
		if (ind_count < 0) 
			v_count = 0;

/* te_ccy */
		v_te_ccy.arr[v_te_ccy.len] = '\0';

/* te_amount_type */
		v_te_amt_type.arr[v_te_amt_type.len] = '\0';

/* te_amount */
		if (ind_te_amount < 0) 
			v_te_amount = 0.0;

	sprintf(csLine, "%s%s%.*s%s %s%.*s%s %s%d%s %s%.*s%s %s%f%s%s",
			PD_TR, PD_TD,v_txn_code_desc.len,v_txn_code_desc.arr,PD_TD_END,
			PD_TD,v_dm_status_desc.len,v_dm_status_desc.arr,PD_TD_END,
			PD_TD,v_count,PD_TD_END,
			/*PD_TD,v_te_amt_type.len,v_te_amt_type.arr,PD_TD_END,*/
			PD_TD,v_te_ccy.len,v_te_ccy.arr,PD_TD_END,
			PD_TD,v_te_amount,PD_TD_END, PD_TR_END

			);

		fprintf(fp,"%s\n",csLine);
	}
	fprintf(fp,"</table></body></html>\n");
	fclose(fp);
DEBUGLOG(("Extract_RPT005 iRet = [%d]\n",iRet));

	return iRet;
extract_rpt005_error:
DEBUGLOG(("extract_rpt005 code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	fclose(fp);
        return FAILURE;
}


int Extract_RPT006(const char* csFileName, SQL_CURSOR c_input_cursor)
{
DEBUGLOG(("Extract_RPT006\n"));
	int	iRet = SUCCESS;

	char	csLine[PD_TMP_BUF_LEN*8+1];

	FILE *fp;
	fp = fopen(csFileName,"w");
	if (fp == NULL) {
DEBUGLOG(("Extract_RPT006:unable to open [%s]\n",csFileName));
                return FAILURE;
	}

	fprintf(fp,"<html><body><table>\n");
	fprintf(fp,"%s%sTransaction Count%s%sMember Amount Type%s%sMember Currency%s%sMember Fee%s%sMerchant Amount Type%s%sMerchant Currency%s%sMerchant Fee%s%s\n",PD_TR,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TR_END);
	fprintf(fp,"<style type=\"text/css\"> .format{ mso-number-format:'\\@';} </style>\n");


	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt006_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		int	v_count;
                /* varchar v_member_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_member_ccy;

                /* varchar v_member_amt_type[PD_AMT_TYPE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_member_amt_type;

                double  v_member_amount;
                /* varchar v_merchant_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_merchant_ccy;

                /* varchar v_merchant_amt_type[PD_AMT_TYPE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_merchant_amt_type;

                double  v_merchant_amount;

		short	ind_count = -1;
		short   ind_member_ccy = -1;
                short   ind_member_amt_type = -1;
		short	ind_member_amount = -1;
		short   ind_merchant_ccy = -1;
                short   ind_merchant_amt_type = -1;
		short	ind_merchant_amount = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                /* EXEC SQL FETCH :c_input_cursor
                INTO
			:v_count:ind_count,
                        :v_member_amt_type:ind_member_amt_type,
			:v_member_ccy:ind_member_ccy,
                        :v_member_amount:ind_member_amount,
                        :v_merchant_amt_type:ind_merchant_amt_type,
			:v_merchant_ccy:ind_merchant_ccy,
                        :v_merchant_amount:ind_merchant_amount; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 23;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )316;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_count;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_count;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_member_amt_type;
                sqlstm.sqhstl[2] = (unsigned long )5;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_member_amt_type;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_member_ccy;
                sqlstm.sqhstl[3] = (unsigned long )6;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_member_ccy;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_member_amount;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_member_amount;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_merchant_amt_type;
                sqlstm.sqhstl[5] = (unsigned long )5;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_merchant_amt_type;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_merchant_ccy;
                sqlstm.sqhstl[6] = (unsigned long )6;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_merchant_ccy;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_merchant_amount;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_merchant_amount;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
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
                if (sqlca.sqlcode == 1403) break;
                if (sqlca.sqlcode < 0) goto extract_rpt006_error;
}



/*count*/
		if (ind_count < 0) 
			v_count = 0;

/* member_ccy */
		v_member_ccy.arr[v_member_ccy.len] = '\0';

/* member_amount_type */
		v_member_amt_type.arr[v_member_amt_type.len] = '\0';

/* member_amount */
		if (ind_member_amount < 0) 
			v_member_amount = 0.0;

/* merchant_ccy */
		v_merchant_ccy.arr[v_merchant_ccy.len] = '\0';

/* merchant_amount_type */
		v_merchant_amt_type.arr[v_merchant_amt_type.len] = '\0';

/* merchant_amount */
		if (ind_merchant_amount < 0) 
			v_merchant_amount = 0.0;

	sprintf(csLine, "%s%s%d%s %s%.*s%s %s%.*s%s %s%f%s %s%.*s%s %s%.*s%s %s%f%s%s",
			PD_TR, PD_TD,v_count,PD_TD_END,
			PD_TD,v_member_amt_type.len,v_member_amt_type.arr,PD_TD_END,
			PD_TD,v_member_ccy.len,v_member_ccy.arr,PD_TD_END,
			PD_TD,v_member_amount,PD_TD_END,
			PD_TD,v_merchant_amt_type.len,v_merchant_amt_type.arr,PD_TD_END,
			PD_TD,v_merchant_ccy.len,v_merchant_ccy.arr,PD_TD_END,
			PD_TD,v_merchant_amount,PD_TD_END, PD_TR_END

			);

		fprintf(fp,"%s\n",csLine);
	}
	fprintf(fp,"</table></body></html>\n");
	fclose(fp);
DEBUGLOG(("Extract_RPT006 iRet = [%d]\n",iRet));

	return iRet;
extract_rpt006_error:
DEBUGLOG(("extract_rpt006 code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	fclose(fp);
        return FAILURE;
}


int Extract_RPT007(const char* csFileName, SQL_CURSOR c_input_cursor)
{
DEBUGLOG(("Extract_RPT007\n"));
	int	iRet = SUCCESS;

	char	csLine[PD_TMP_BUF_LEN*8+1];

	FILE *fp;
	fp = fopen(csFileName,"w");
	if (fp == NULL) {
DEBUGLOG(("Extract_RPT007:unable to open [%s]\n",csFileName));
                return FAILURE;
	}

	fprintf(fp,"<html><body><table>\n");
	fprintf(fp,"%s%sCreate Date%s%sLast Update Date%s%sApproval Date%s%sTxn ID%s%sPSP Name%s%sMerchant ID%s%sMerchant Ref%s%sMerchant Name%s%sStatus%s%sSubstatus Desc%s%sTxn Currency%s%sTransaction Amount%s%sNet Amount%s%sExchange Rate%s%sFee Currency%s%sFee%s%sCurrency%s%sRequested Amount%s%s\n",PD_TR,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TR_END);
	fprintf(fp,"<style type=\"text/css\"> .format{ mso-number-format:'\\@';} </style>\n");


	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt007_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar v_create_timestamp[PD_DATETIME_LEN + 1 + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_create_timestamp;

                /* varchar v_update_timestamp[PD_DATETIME_LEN + 1 + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_update_timestamp;

                /* varchar v_approval_timestamp[PD_DATETIME_LEN + 1 + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_approval_timestamp;

                /* varchar v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar v_psp_name[PD_PSP_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_name;

                /* varchar v_merchant_ref[PD_MERCHANT_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

                /* varchar v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

                /* varchar v_merchant_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_name;

                /* varchar v_dm_status_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_dm_status_desc;

                /* varchar v_sub_status_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_sub_status_desc;

                /* varchar v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

                double  v_txn_amount;
                double  v_net_amount;
                double  v_ex_rate;
                /* varchar v_fee_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_fee_ccy;

                double  v_fee;
                /* varchar v_req_amt_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_req_amt_ccy;

                double  v_requested_amount;

		short   ind_create_timestamp = -1;
		short   ind_update_timestamp = -1;
		short   ind_approval_timestamp = -1;
		short	ind_txn_id = -1;
		short   ind_psp_name = -1;
                short   ind_merchant_ref = -1;
                short   ind_merchant_id = -1;
		short   ind_merchant_name = -1;
		short   ind_dm_status_desc = -1;
		short   ind_sub_status_desc = -1;
		short   ind_txn_ccy = -1;
		short	ind_txn_amount = -1;
		short	ind_net_amount = -1;
		short	ind_ex_rate = -1;
		short   ind_fee_ccy = -1;
		short	ind_fee = -1;
		short   ind_req_amt_ccy = -1;
		short	ind_requested_amount = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                /* EXEC SQL FETCH :c_input_cursor
                INTO
                        :v_create_timestamp:ind_create_timestamp,
                        :v_update_timestamp:ind_update_timestamp,
                        :v_approval_timestamp:ind_approval_timestamp,
			:v_txn_id:ind_txn_id,
                        :v_psp_name:ind_psp_name,
                        :v_merchant_ref:ind_merchant_ref,
                        :v_merchant_id:ind_merchant_id,
                        :v_merchant_name:ind_merchant_name,
                        :v_dm_status_desc:ind_dm_status_desc,
                        :v_sub_status_desc:ind_sub_status_desc,
                        :v_txn_amount:ind_txn_amount,
                        :v_txn_ccy:ind_txn_ccy,
                        :v_net_amount:ind_net_amount,
                        :v_ex_rate:ind_ex_rate,
                        :v_fee:ind_fee,
                        :v_fee_ccy:ind_fee_ccy,
                        :v_requested_amount:ind_requested_amount,
                        :v_req_amt_ccy:ind_req_amt_ccy; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 23;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )363;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_create_timestamp;
                sqlstm.sqhstl[1] = (unsigned long )18;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_create_timestamp;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_update_timestamp;
                sqlstm.sqhstl[2] = (unsigned long )18;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_update_timestamp;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_approval_timestamp;
                sqlstm.sqhstl[3] = (unsigned long )18;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_approval_timestamp;
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
                sqlstm.sqhstv[5] = (unsigned char  *)&v_psp_name;
                sqlstm.sqhstl[5] = (unsigned long )53;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_psp_name;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_merchant_ref;
                sqlstm.sqhstl[6] = (unsigned long )53;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_merchant_ref;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_merchant_id;
                sqlstm.sqhstl[7] = (unsigned long )18;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_merchant_id;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_merchant_name;
                sqlstm.sqhstl[8] = (unsigned long )53;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_merchant_name;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_dm_status_desc;
                sqlstm.sqhstl[9] = (unsigned long )53;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_dm_status_desc;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_sub_status_desc;
                sqlstm.sqhstl[10] = (unsigned long )53;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_sub_status_desc;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_amount;
                sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_txn_amount;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
                sqlstm.sqhstv[12] = (unsigned char  *)&v_txn_ccy;
                sqlstm.sqhstl[12] = (unsigned long )6;
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_txn_ccy;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
                sqlstm.sqhstv[13] = (unsigned char  *)&v_net_amount;
                sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[13] = (         int  )0;
                sqlstm.sqindv[13] = (         short *)&ind_net_amount;
                sqlstm.sqinds[13] = (         int  )0;
                sqlstm.sqharm[13] = (unsigned long )0;
                sqlstm.sqadto[13] = (unsigned short )0;
                sqlstm.sqtdso[13] = (unsigned short )0;
                sqlstm.sqhstv[14] = (unsigned char  *)&v_ex_rate;
                sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[14] = (         int  )0;
                sqlstm.sqindv[14] = (         short *)&ind_ex_rate;
                sqlstm.sqinds[14] = (         int  )0;
                sqlstm.sqharm[14] = (unsigned long )0;
                sqlstm.sqadto[14] = (unsigned short )0;
                sqlstm.sqtdso[14] = (unsigned short )0;
                sqlstm.sqhstv[15] = (unsigned char  *)&v_fee;
                sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[15] = (         int  )0;
                sqlstm.sqindv[15] = (         short *)&ind_fee;
                sqlstm.sqinds[15] = (         int  )0;
                sqlstm.sqharm[15] = (unsigned long )0;
                sqlstm.sqadto[15] = (unsigned short )0;
                sqlstm.sqtdso[15] = (unsigned short )0;
                sqlstm.sqhstv[16] = (unsigned char  *)&v_fee_ccy;
                sqlstm.sqhstl[16] = (unsigned long )6;
                sqlstm.sqhsts[16] = (         int  )0;
                sqlstm.sqindv[16] = (         short *)&ind_fee_ccy;
                sqlstm.sqinds[16] = (         int  )0;
                sqlstm.sqharm[16] = (unsigned long )0;
                sqlstm.sqadto[16] = (unsigned short )0;
                sqlstm.sqtdso[16] = (unsigned short )0;
                sqlstm.sqhstv[17] = (unsigned char  *)&v_requested_amount;
                sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[17] = (         int  )0;
                sqlstm.sqindv[17] = (         short *)&ind_requested_amount;
                sqlstm.sqinds[17] = (         int  )0;
                sqlstm.sqharm[17] = (unsigned long )0;
                sqlstm.sqadto[17] = (unsigned short )0;
                sqlstm.sqtdso[17] = (unsigned short )0;
                sqlstm.sqhstv[18] = (unsigned char  *)&v_req_amt_ccy;
                sqlstm.sqhstl[18] = (unsigned long )6;
                sqlstm.sqhsts[18] = (         int  )0;
                sqlstm.sqindv[18] = (         short *)&ind_req_amt_ccy;
                sqlstm.sqinds[18] = (         int  )0;
                sqlstm.sqharm[18] = (unsigned long )0;
                sqlstm.sqadto[18] = (unsigned short )0;
                sqlstm.sqtdso[18] = (unsigned short )0;
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
                if (sqlca.sqlcode == 1403) break;
                if (sqlca.sqlcode < 0) goto extract_rpt007_error;
}



/* create_updatetime */
                v_create_timestamp.arr[v_create_timestamp.len] = '\0';

/* last_updatetime */
                v_update_timestamp.arr[v_update_timestamp.len] = '\0';

/* approval_updatetime */
                v_approval_timestamp.arr[v_approval_timestamp.len] = '\0';

/* txn id */
		v_txn_id.arr[v_txn_id.len] = '\0';

/* psp_name */
		v_psp_name.arr[v_psp_name.len] = '\0';

/* merchant_ref */
		v_merchant_ref.arr[v_merchant_ref.len] = '\0';

/* merchant_id */
		v_merchant_id.arr[v_merchant_id.len] = '\0';

/* merchant_name */
		v_merchant_name.arr[v_merchant_name.len] = '\0';

/* Status_desc */
		v_dm_status_desc.arr[v_dm_status_desc.len] = '\0';

/* sub_Status_desc */
		v_sub_status_desc.arr[v_sub_status_desc.len] = '\0';

/* txn_amount */
		if (ind_txn_amount < 0 )
			v_txn_amount = 0;

/* txn_ccy */
		v_txn_ccy.arr[v_txn_ccy.len] = '\0';

/* net_amount */
		if (ind_net_amount < 0 )
			v_net_amount = 0;

/* ex_rate */
		if (ind_ex_rate < 0 )
			v_ex_rate = 0;

/* fee */
		if (ind_fee < 0 )
			v_fee = 0;

/* fee_ccy */
		v_fee_ccy.arr[v_fee_ccy.len] = '\0';

/* requested_amount */
		if (ind_requested_amount < 0 )
			v_requested_amount = 0;

/* req_amt_ccy */
		v_req_amt_ccy.arr[v_req_amt_ccy.len] = '\0';

		sprintf(csLine, "%s%s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%f%s %s%f%s %s%f%s %s%.*s%s %s%f%s %s%.*s%s %s%f%s%s",
			PD_TR, PD_TD_STYLE,v_create_timestamp.len,v_create_timestamp.arr,PD_TD_END,
			PD_TD_STYLE,v_update_timestamp.len,v_update_timestamp.arr,PD_TD_END,
			PD_TD_STYLE,v_approval_timestamp.len,v_approval_timestamp.arr,PD_TD_END,
			PD_TD_STYLE,v_txn_id.len,v_txn_id.arr,PD_TD_END,
			PD_TD,v_psp_name.len,v_psp_name.arr,PD_TD_END,
			PD_TD_STYLE,v_merchant_id.len,v_merchant_id.arr,PD_TD_END,
			PD_TD_STYLE,v_merchant_ref.len,v_merchant_ref.arr,PD_TD_END,
			PD_TD,v_merchant_name.len,v_merchant_name.arr,PD_TD_END,
			PD_TD,v_dm_status_desc.len,v_dm_status_desc.arr,PD_TD_END,
			PD_TD,v_sub_status_desc.len,v_sub_status_desc.arr,PD_TD_END,
			PD_TD,v_txn_ccy.len,v_txn_ccy.arr,PD_TD_END,
			PD_TD,v_txn_amount,PD_TD_END,
			PD_TD,v_net_amount,PD_TD_END,
			PD_TD,v_ex_rate,PD_TD_END,
			PD_TD,v_fee_ccy.len,v_fee_ccy.arr,PD_TD_END,
			PD_TD,v_fee,PD_TD_END,
			PD_TD,v_req_amt_ccy.len,v_req_amt_ccy.arr,PD_TD_END,
			PD_TD,v_requested_amount,PD_TD_END, PD_TR_END
			);

		fprintf(fp,"%s\n",csLine);
	}
	fprintf(fp,"</table></body></html>\n");

	fclose(fp);
DEBUGLOG(("Extract_RPT007 iRet = [%d]\n",iRet));

	return iRet;
extract_rpt007_error:
DEBUGLOG(("extract_rpt007 code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	fclose(fp);
        return FAILURE;
}


int Extract_RPT008(const char* csFileName, SQL_CURSOR c_input_cursor)
{
DEBUGLOG(("Extract_RPT008\n"));
	int	iRet = SUCCESS;

	char	csLine[PD_TMP_BUF_LEN*8+1];

	FILE *fp;
	fp = fopen(csFileName,"w");
	if (fp == NULL) {
DEBUGLOG(("Extract_RPT008:unable to open [%s]\n",csFileName));
                return FAILURE;
	}

	fprintf(fp,"<html><body><table>\n");
	fprintf(fp,"%s%sCreate date%s%sLast Update date%s%sApproval date%s%sTxn ID%s%sTxn code Desc%s%sMerchant ID%s%sMerchant Ref%s%sMerchant Name%s%sStatus%s%sSubstatus Desc%s%sTxn Currency%s%sTransaction Amount%s%sNet Amount%s%sExchange Rate%s%sFee Currency%s%sFee%s%sCurrency%s%sRequested Amount%s%s\n",PD_TR,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TR_END);
	fprintf(fp,"<style type=\"text/css\"> .format{ mso-number-format:'\\@';} </style>\n");


	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt008_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar v_create_timestamp[PD_DATETIME_LEN + 1 + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_create_timestamp;

                /* varchar v_update_timestamp[PD_DATETIME_LEN + 1 + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_update_timestamp;

                /* varchar v_approval_timestamp[PD_DATETIME_LEN + 1 + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_approval_timestamp;

                /* varchar v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

                /* varchar v_txn_code_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_code_desc;

                /* varchar v_merchant_ref[PD_MERCHANT_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

                /* varchar v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

                /* varchar v_merchant_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_name;

                /* varchar v_dm_status_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_dm_status_desc;

                /* varchar v_sub_status_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_sub_status_desc;

                /* varchar v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

                double  v_txn_amount;
                double  v_net_amount;
                double  v_ex_rate;
                /* varchar v_fee_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_fee_ccy;

                double  v_fee;
                /* varchar v_req_amt_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_req_amt_ccy;

                double  v_requested_amount;

		short   ind_create_timestamp = -1;
		short   ind_update_timestamp = -1;
		short   ind_approval_timestamp = -1;
		short	ind_txn_id = -1;
                short   ind_txn_code_desc = -1;
                short   ind_merchant_ref = -1;
                short   ind_merchant_id = -1;
		short   ind_merchant_name = -1;
		short   ind_dm_status_desc = -1;
		short   ind_sub_status_desc = -1;
		short   ind_txn_ccy = -1;
		short	ind_txn_amount = -1;
		short	ind_net_amount = -1;
		short	ind_ex_rate = -1;
		short   ind_fee_ccy = -1;
		short	ind_fee = -1;
		short   ind_req_amt_ccy = -1;
		short	ind_requested_amount = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                /* EXEC SQL FETCH :c_input_cursor
                INTO
                        :v_create_timestamp:ind_create_timestamp,
                        :v_update_timestamp:ind_update_timestamp,
                        :v_approval_timestamp:ind_approval_timestamp,
			:v_txn_id:ind_txn_id,
                        :v_merchant_ref:ind_merchant_ref,
                        :v_txn_code_desc:ind_txn_code_desc,
                        :v_merchant_id:ind_merchant_id,
                        :v_merchant_name:ind_merchant_name,
                        :v_dm_status_desc:ind_dm_status_desc,
                        :v_sub_status_desc:ind_sub_status_desc,
                        :v_txn_amount:ind_txn_amount,
                        :v_txn_ccy:ind_txn_ccy,
                        :v_net_amount:ind_net_amount,
                        :v_ex_rate:ind_ex_rate,
                        :v_fee:ind_fee,
                        :v_fee_ccy:ind_fee_ccy,
                        :v_requested_amount:ind_requested_amount,
                        :v_req_amt_ccy:ind_req_amt_ccy; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 23;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )454;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_create_timestamp;
                sqlstm.sqhstl[1] = (unsigned long )18;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_create_timestamp;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_update_timestamp;
                sqlstm.sqhstl[2] = (unsigned long )18;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_update_timestamp;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_approval_timestamp;
                sqlstm.sqhstl[3] = (unsigned long )18;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_approval_timestamp;
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
                sqlstm.sqhstv[5] = (unsigned char  *)&v_merchant_ref;
                sqlstm.sqhstl[5] = (unsigned long )53;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_merchant_ref;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_txn_code_desc;
                sqlstm.sqhstl[6] = (unsigned long )53;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_txn_code_desc;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_merchant_id;
                sqlstm.sqhstl[7] = (unsigned long )18;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_merchant_id;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_merchant_name;
                sqlstm.sqhstl[8] = (unsigned long )53;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_merchant_name;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_dm_status_desc;
                sqlstm.sqhstl[9] = (unsigned long )53;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_dm_status_desc;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_sub_status_desc;
                sqlstm.sqhstl[10] = (unsigned long )53;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_sub_status_desc;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_amount;
                sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_txn_amount;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
                sqlstm.sqhstv[12] = (unsigned char  *)&v_txn_ccy;
                sqlstm.sqhstl[12] = (unsigned long )6;
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_txn_ccy;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
                sqlstm.sqhstv[13] = (unsigned char  *)&v_net_amount;
                sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[13] = (         int  )0;
                sqlstm.sqindv[13] = (         short *)&ind_net_amount;
                sqlstm.sqinds[13] = (         int  )0;
                sqlstm.sqharm[13] = (unsigned long )0;
                sqlstm.sqadto[13] = (unsigned short )0;
                sqlstm.sqtdso[13] = (unsigned short )0;
                sqlstm.sqhstv[14] = (unsigned char  *)&v_ex_rate;
                sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[14] = (         int  )0;
                sqlstm.sqindv[14] = (         short *)&ind_ex_rate;
                sqlstm.sqinds[14] = (         int  )0;
                sqlstm.sqharm[14] = (unsigned long )0;
                sqlstm.sqadto[14] = (unsigned short )0;
                sqlstm.sqtdso[14] = (unsigned short )0;
                sqlstm.sqhstv[15] = (unsigned char  *)&v_fee;
                sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[15] = (         int  )0;
                sqlstm.sqindv[15] = (         short *)&ind_fee;
                sqlstm.sqinds[15] = (         int  )0;
                sqlstm.sqharm[15] = (unsigned long )0;
                sqlstm.sqadto[15] = (unsigned short )0;
                sqlstm.sqtdso[15] = (unsigned short )0;
                sqlstm.sqhstv[16] = (unsigned char  *)&v_fee_ccy;
                sqlstm.sqhstl[16] = (unsigned long )6;
                sqlstm.sqhsts[16] = (         int  )0;
                sqlstm.sqindv[16] = (         short *)&ind_fee_ccy;
                sqlstm.sqinds[16] = (         int  )0;
                sqlstm.sqharm[16] = (unsigned long )0;
                sqlstm.sqadto[16] = (unsigned short )0;
                sqlstm.sqtdso[16] = (unsigned short )0;
                sqlstm.sqhstv[17] = (unsigned char  *)&v_requested_amount;
                sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[17] = (         int  )0;
                sqlstm.sqindv[17] = (         short *)&ind_requested_amount;
                sqlstm.sqinds[17] = (         int  )0;
                sqlstm.sqharm[17] = (unsigned long )0;
                sqlstm.sqadto[17] = (unsigned short )0;
                sqlstm.sqtdso[17] = (unsigned short )0;
                sqlstm.sqhstv[18] = (unsigned char  *)&v_req_amt_ccy;
                sqlstm.sqhstl[18] = (unsigned long )6;
                sqlstm.sqhsts[18] = (         int  )0;
                sqlstm.sqindv[18] = (         short *)&ind_req_amt_ccy;
                sqlstm.sqinds[18] = (         int  )0;
                sqlstm.sqharm[18] = (unsigned long )0;
                sqlstm.sqadto[18] = (unsigned short )0;
                sqlstm.sqtdso[18] = (unsigned short )0;
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
                if (sqlca.sqlcode == 1403) break;
                if (sqlca.sqlcode < 0) goto extract_rpt008_error;
}



/* create_updatetime */
                v_create_timestamp.arr[v_create_timestamp.len] = '\0';

/* last_updatetime */
                v_update_timestamp.arr[v_update_timestamp.len] = '\0';

/* approval_updatetime */
                v_approval_timestamp.arr[v_approval_timestamp.len] = '\0';

/* txn id */
		v_txn_id.arr[v_txn_id.len] = '\0';

/* txn_desc */
		v_txn_code_desc.arr[v_txn_code_desc.len] = '\0';

/* merchant_ref */
		v_merchant_ref.arr[v_merchant_ref.len] = '\0';

/* merchant_id */
		v_merchant_id.arr[v_merchant_id.len] = '\0';

/* merchant_name */
		v_merchant_name.arr[v_merchant_name.len] = '\0';

/* Status_desc */
		v_dm_status_desc.arr[v_dm_status_desc.len] = '\0';

/* sub_Status_desc */
		v_sub_status_desc.arr[v_sub_status_desc.len] = '\0';

/* txn_amount */
		if (ind_txn_amount < 0 )
			v_txn_amount = 0;

/* txn_ccy */
		v_txn_ccy.arr[v_txn_ccy.len] = '\0';

/* net_amount */
		if (ind_net_amount < 0 )
			v_net_amount = 0;

/* ex_rate */
		if (ind_ex_rate < 0 )
			v_ex_rate = 0;

/* fee */
		if (ind_fee < 0 )
			v_fee = 0;

/* fee_ccy */
		v_fee_ccy.arr[v_fee_ccy.len] = '\0';

/* requested_amount */
		if (ind_requested_amount < 0 )
			v_requested_amount = 0;

/* req_amt_ccy */
		v_req_amt_ccy.arr[v_req_amt_ccy.len] = '\0';

		sprintf(csLine, "%s%s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%f%s %s%f%s %s%f%s %s%.*s%s %s%f%s %s%.*s%s %s%f%s%s",
			PD_TR, PD_TD_STYLE,v_create_timestamp.len,v_create_timestamp.arr,PD_TD_END,
			PD_TD_STYLE,v_update_timestamp.len,v_update_timestamp.arr,PD_TD_END,
			PD_TD_STYLE,v_approval_timestamp.len,v_approval_timestamp.arr,PD_TD_END,
			PD_TD_STYLE,v_txn_id.len,v_txn_id.arr,PD_TD_END,
			PD_TD,v_txn_code_desc.len,v_txn_code_desc.arr,PD_TD_END,
			PD_TD_STYLE,v_merchant_id.len,v_merchant_id.arr,PD_TD_END,
			PD_TD_STYLE,v_merchant_ref.len,v_merchant_ref.arr,PD_TD_END,
			PD_TD,v_merchant_name.len,v_merchant_name.arr,PD_TD_END,
			PD_TD,v_dm_status_desc.len,v_dm_status_desc.arr,PD_TD_END,
			PD_TD,v_sub_status_desc.len,v_sub_status_desc.arr,PD_TD_END,
			PD_TD,v_txn_ccy.len,v_txn_ccy.arr,PD_TD_END,
			PD_TD,v_txn_amount,PD_TD_END,
			PD_TD,v_net_amount,PD_TD_END,
			PD_TD,v_ex_rate,PD_TD_END,
			PD_TD,v_fee_ccy.len,v_fee_ccy.arr,PD_TD_END,
			PD_TD,v_fee,PD_TD_END,
			PD_TD,v_req_amt_ccy.len,v_req_amt_ccy.arr,PD_TD_END,
			PD_TD,v_requested_amount,PD_TD_END, PD_TR_END
			);

		fprintf(fp,"%s\n",csLine);
	}
	fprintf(fp,"</table></body></html>\n");
	fclose(fp);
DEBUGLOG(("Extract_RPT008 iRet = [%d]\n",iRet));

	return iRet;
extract_rpt008_error:
DEBUGLOG(("extract_rpt008 code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	fclose(fp);
        return FAILURE;
}


int Extract_RPT009(const char* csFileName, SQL_CURSOR c_input_cursor)
{
DEBUGLOG(("Extract_RPT009\n"));
	int	iRet = SUCCESS;

	char	csLine[PD_TMP_BUF_LEN*8+1];

	FILE *fp;
	fp = fopen(csFileName,"w");
	if (fp == NULL) {
DEBUGLOG(("Extract_RPT009:unable to open [%s]\n",csFileName));
                return FAILURE;
	}

	fprintf(fp,"<html><body><table>\n");
	fprintf(fp,"%s%sMerchant ID%s%sMerchant Name%s%sService Desc%s%sApproval Date%s%sCurrent Balance%s%sTotal Float%s%sTotal Reserved Amount%s%sTotal Hold%s%sSettlement in Transit%s%sCurrency%s%sStatus%s%s\n",PD_TR,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TR_END);
	fprintf(fp,"<style type=\"text/css\"> .format{ mso-number-format:'\\@';} </style>\n");


	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt009_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

                /* varchar v_merchant_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_name;

                /* varchar v_service_code_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_service_code_desc;

                /* varchar v_approval_timestamp[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_approval_timestamp;

                double  v_current_bal;
                double  v_total_float;
                double  v_total_reserved_amt;
                double  v_total_hold;
                double  v_settlement_in_transit;
                /* varchar v_mb_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_mb_ccy;

                /* varchar v_ds_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_ds_desc;


		short   ind_merchant_id = -1;
		short   ind_merchant_name = -1;
		short   ind_service_code_desc = -1;
		short   ind_approval_timestamp = -1;
                short   ind_current_bal = -1;
                short	ind_total_float = -1;
                short   ind_total_reserved_amt = -1;
                short   ind_total_hold = -1;
                short   ind_settlement_in_transit = -1;
		short   ind_mb_ccy = -1;
                short   ind_ds_desc = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                /* EXEC SQL FETCH :c_input_cursor
                INTO
                        :v_merchant_id:ind_merchant_id,
                        :v_merchant_name:ind_merchant_name,
			:v_service_code_desc:ind_service_code_desc,
                        :v_approval_timestamp:ind_approval_timestamp,
                        :v_current_bal:ind_current_bal,
                        :v_total_float:ind_total_float,
                        :v_total_reserved_amt:ind_total_reserved_amt,
                        :v_total_hold:ind_total_hold,
                        :v_settlement_in_transit:ind_settlement_in_transit,
			:v_mb_ccy:ind_mb_ccy,
                        :v_ds_desc:ind_ds_desc; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 23;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )545;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_merchant_id;
                sqlstm.sqhstl[1] = (unsigned long )18;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_merchant_name;
                sqlstm.sqhstl[2] = (unsigned long )53;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_merchant_name;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_service_code_desc;
                sqlstm.sqhstl[3] = (unsigned long )53;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_service_code_desc;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_approval_timestamp;
                sqlstm.sqhstl[4] = (unsigned long )11;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_approval_timestamp;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_current_bal;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_current_bal;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_total_float;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_total_float;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_total_reserved_amt;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_total_reserved_amt;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_total_hold;
                sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_total_hold;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_settlement_in_transit;
                sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_settlement_in_transit;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_mb_ccy;
                sqlstm.sqhstl[10] = (unsigned long )6;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_mb_ccy;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_ds_desc;
                sqlstm.sqhstl[11] = (unsigned long )53;
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_ds_desc;
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
                if (sqlca.sqlcode == 1403) break;
                if (sqlca.sqlcode < 0) goto extract_rpt009_error;
}



/* merchant_id */
                v_merchant_id.arr[v_merchant_id.len] = '\0';

/* merchant_name */
		v_merchant_name.arr[v_merchant_name.len] = '\0';

/* service_desc */
		v_service_code_desc.arr[v_service_code_desc.len] = '\0';

/* approval_updatetime */
                v_approval_timestamp.arr[v_approval_timestamp.len] = '\0';

/*current bal */
		if (ind_current_bal < 0) 
			v_current_bal = 0.0;

/*total float */
		if (ind_total_float < 0) 
			v_total_float = 0.0;

/*total reserved amount*/
		if (ind_total_reserved_amt < 0) 
			v_total_reserved_amt = 0.0;

/*total hold */
		if (ind_total_hold < 0) 
			v_total_hold = 0.0;

/*settlement in transit*/
		if (ind_settlement_in_transit < 0) 
			v_settlement_in_transit = 0.0;

/* mb_ccy */
		v_mb_ccy.arr[v_mb_ccy.len] = '\0';

/* status */
		v_ds_desc.arr[v_ds_desc.len] = '\0';

	sprintf(csLine, "%s%s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%f%s %s%f%s %s%f%s %s%f%s %s%f%s %s%.*s%s %s%.*s%s%s",
			PD_TR, PD_TD_STYLE,v_merchant_id.len,v_merchant_id.arr,PD_TD_END,
			PD_TD,v_merchant_name.len,v_merchant_name.arr,PD_TD_END,
			PD_TD,v_service_code_desc.len,v_service_code_desc.arr,PD_TD_END,
			PD_TD_STYLE,v_approval_timestamp.len,v_approval_timestamp.arr,PD_TD_END,
			PD_TD,v_current_bal,PD_TD_END,
			PD_TD,v_total_float,PD_TD_END,
			PD_TD,v_total_reserved_amt,PD_TD_END,
			PD_TD,v_total_hold,PD_TD_END,
			PD_TD,v_settlement_in_transit,PD_TD_END,
			PD_TD,v_mb_ccy.len,v_mb_ccy.arr,PD_TD_END,
			PD_TD,v_ds_desc.len,v_ds_desc.arr,PD_TD_END, PD_TR_END

			);

		fprintf(fp,"%s\n",csLine);
	}
	fprintf(fp,"</table></body></html>\n");
	fclose(fp);
DEBUGLOG(("Extract_RPT009 iRet = [%d]\n",iRet));

	return iRet;
extract_rpt009_error:
DEBUGLOG(("extract_rpt009 code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	fclose(fp);
        return FAILURE;
}


int Extract_RPT010(const char* csFileName, SQL_CURSOR c_input_cursor)
{
DEBUGLOG(("Extract_RPT010\n"));
	int	iRet = SUCCESS;

	char	csLine[PD_TMP_BUF_LEN*8+1];

	FILE *fp;
	fp = fopen(csFileName,"w");
	if (fp == NULL) {
DEBUGLOG(("Extract_RPT010:unable to open [%s]\n",csFileName));
                return FAILURE;
	}

	fprintf(fp,"<html><body><table>\n");
	fprintf(fp,"%s%sApproval date%s%sTxn ID%s%sMerchant ID%s%sMerchant Name%s%sTxn Type%s%sStatus%s%sSubstatus%s%sCurrency%s%sTxn Amount%s%sFee Currency%s%sFee%s%s\n",PD_TR,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TR_END);
	fprintf(fp,"<style type=\"text/css\"> .format{ mso-number-format:'\\@';} </style>\n");

	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt010_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar v_approval_timestamp[PD_DATETIME_LEN +1 + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_approval_timestamp;

                /* varchar v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

                /* varchar v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

                /* varchar v_merchant_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_name;

		/* varchar v_txn_type[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_type;

                /* varchar v_dm_status_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_dm_status_desc;

                /* varchar v_sub_status_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_sub_status_desc;

                double  v_txn_amount;
                /* varchar v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

                double  v_fee;
                /* varchar v_fee_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_fee_ccy;


		short   ind_approval_timestamp = -1;
		short	ind_txn_id = -1;
                short   ind_merchant_id = -1;
		short   ind_merchant_name = -1;
                short   ind_txn_type= -1;
		short   ind_dm_status_desc = -1;
		short   ind_sub_status_desc = -1;
		short	ind_txn_amount = -1;
		short   ind_txn_ccy = -1;
		short	ind_fee = -1;
		short   ind_fee_ccy = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                /* EXEC SQL FETCH :c_input_cursor
                INTO
                        :v_approval_timestamp:ind_approval_timestamp,
			:v_txn_id:ind_txn_id,
                        :v_merchant_id:ind_merchant_id,
                        :v_merchant_name:ind_merchant_name,
                        :v_txn_type:ind_txn_type,
                        :v_dm_status_desc:ind_dm_status_desc,
                        :v_sub_status_desc:ind_sub_status_desc,
                        :v_txn_amount:ind_txn_amount,
                        :v_txn_ccy:ind_txn_ccy,
                        :v_fee:ind_fee,
                        :v_fee_ccy:ind_fee_ccy; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 23;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )608;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_approval_timestamp;
                sqlstm.sqhstl[1] = (unsigned long )18;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_approval_timestamp;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_id;
                sqlstm.sqhstl[2] = (unsigned long )19;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_txn_id;
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
                sqlstm.sqhstl[4] = (unsigned long )53;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_merchant_name;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_txn_type;
                sqlstm.sqhstl[5] = (unsigned long )53;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_txn_type;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_dm_status_desc;
                sqlstm.sqhstl[6] = (unsigned long )53;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_dm_status_desc;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_sub_status_desc;
                sqlstm.sqhstl[7] = (unsigned long )53;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_sub_status_desc;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_txn_amount;
                sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_txn_amount;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_txn_ccy;
                sqlstm.sqhstl[9] = (unsigned long )6;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_txn_ccy;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_fee;
                sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_fee;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_fee_ccy;
                sqlstm.sqhstl[11] = (unsigned long )6;
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_fee_ccy;
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
                if (sqlca.sqlcode == 1403) break;
                if (sqlca.sqlcode < 0) goto extract_rpt010_error;
}



/* approval_updatetime */
                v_approval_timestamp.arr[v_approval_timestamp.len] = '\0';

/* txn id */
		v_txn_id.arr[v_txn_id.len] = '\0';

/* merchant_id */
		v_merchant_id.arr[v_merchant_id.len] = '\0';

/* merchant_name */
		v_merchant_name.arr[v_merchant_name.len] = '\0';

/* txn type */
		v_txn_type.arr[v_txn_type.len] = '\0';

/* Status_desc */
		v_dm_status_desc.arr[v_dm_status_desc.len] = '\0';

/* sub_Status_desc */
		v_sub_status_desc.arr[v_sub_status_desc.len] = '\0';

/* txn_amount */
		if (ind_txn_amount < 0 )
			v_txn_amount = 0;

/* txn_ccy */
		v_txn_ccy.arr[v_txn_ccy.len] = '\0';


/* fee */
		if (ind_fee < 0 )
			v_fee = 0;

/* fee_ccy */
		v_fee_ccy.arr[v_fee_ccy.len] = '\0';

		sprintf(csLine, "%s%s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%f%s %s%.*s%s %s%f%s%s",
			PD_TR, PD_TD_STYLE,v_approval_timestamp.len,v_approval_timestamp.arr,PD_TD_END,
			PD_TD_STYLE,v_txn_id.len,v_txn_id.arr,PD_TD_END,
			PD_TD_STYLE,v_merchant_id.len,v_merchant_id.arr,PD_TD_END,
			PD_TD,v_merchant_name.len,v_merchant_name.arr,PD_TD_END,
			PD_TD,v_txn_type.len,v_txn_type.arr,PD_TD_END,
			PD_TD,v_dm_status_desc.len,v_dm_status_desc.arr,PD_TD_END,
			PD_TD,v_sub_status_desc.len,v_sub_status_desc.arr,PD_TD_END,
			PD_TD,v_txn_ccy.len,v_txn_ccy.arr,PD_TD_END,
			PD_TD,v_txn_amount,PD_TD_END,
			PD_TD,v_fee_ccy.len,v_fee_ccy.arr,PD_TD_END,
			PD_TD,v_fee,PD_TD_END, PD_TR_END
			);

		fprintf(fp,"%s\n",csLine);
	}
	fprintf(fp,"</table></body></html>\n");

	fclose(fp);
DEBUGLOG(("Extract_RPT010 iRet = [%d]\n",iRet));

	return iRet;
extract_rpt010_error:
DEBUGLOG(("extract_rpt010 code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	fclose(fp);
        return FAILURE;
}


int Extract_RPT011(const char* csFileName, SQL_CURSOR c_input_cursor)
{
DEBUGLOG(("Extract_RPT011\n"));
	int	iRet = SUCCESS;

	char	csLine[PD_TMP_BUF_LEN*8+1];

	FILE *fp;
	fp = fopen(csFileName,"w");
	if (fp == NULL) {
DEBUGLOG(("Extract_RPT011:unable to open [%s]\n",csFileName));
                return FAILURE;
	}

	fprintf(fp,"<html><body><table>\n");
	fprintf(fp,"%s%sTxn ID%s%sTxn Code%s%sTxn Date%s%sPSP ID%s%sPSP Name%s%sCurrency%s%sTxn Amount%s%sService Fee%s%s\n",PD_TR,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TR_END);
	fprintf(fp,"<style type=\"text/css\"> .format{ mso-number-format:'\\@';} </style>\n");


	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt011_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar v_txn_id[PD_TXN_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_txn_id;

                /* varchar v_txn_code[PD_TXN_CODE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

                /* varchar v_txn_code_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_code_desc;

                /* varchar v_txn_date[PD_DATE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_txn_date;

		/* varchar v_psp_id[PD_PSP_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar v_psp_name[PD_PSP_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_name;

		/* varchar v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

		double  v_txn_amount;
		double  v_service_fee;

                short   ind_txn_id = -1;
                short   ind_txn_code = -1;
                short   ind_txn_code_desc = -1;
                short   ind_txn_date = -1;
                short   ind_psp_id = -1;
		short   ind_psp_name = -1;
                short   ind_txn_ccy = -1;
                short   ind_txn_amount = -1;
                short   ind_service_fee = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                /* EXEC SQL FETCH :c_input_cursor
                INTO
                        :v_txn_id:ind_txn_id,
			:v_txn_code:ind_txn_code,
			:v_txn_code_desc:ind_txn_code_desc,
                        :v_txn_date:ind_txn_date,
                        :v_psp_id:ind_psp_id,
                        :v_psp_name:ind_psp_name,
			:v_txn_ccy:ind_txn_ccy,
			:v_txn_amount:ind_txn_amount,
			:v_service_fee:ind_service_fee; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 23;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )671;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_id;
                sqlstm.sqhstl[1] = (unsigned long )23;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_txn_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_code;
                sqlstm.sqhstl[2] = (unsigned long )6;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_txn_code;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_code_desc;
                sqlstm.sqhstl[3] = (unsigned long )53;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_txn_code_desc;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_txn_date;
                sqlstm.sqhstl[4] = (unsigned long )11;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_txn_date;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_psp_id;
                sqlstm.sqhstl[5] = (unsigned long )13;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_psp_id;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_psp_name;
                sqlstm.sqhstl[6] = (unsigned long )53;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_psp_name;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_txn_ccy;
                sqlstm.sqhstl[7] = (unsigned long )6;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_txn_ccy;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_txn_amount;
                sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_txn_amount;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_service_fee;
                sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_service_fee;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
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
                if (sqlca.sqlcode == 1403) break;
                if (sqlca.sqlcode < 0) goto extract_rpt011_error;
}



/* txn id */
		v_txn_id.arr[v_txn_id.len] = '\0';

/* txn code */
		v_txn_code.arr[v_txn_code.len] = '\0';

/* txn_desc */
		v_txn_code_desc.arr[v_txn_code_desc.len] = '\0';

/*txn date */
		v_txn_date.arr[v_txn_date.len] = '\0';

/* psp id */
		v_psp_id.arr[v_psp_id.len] = '\0';

/* psp_name */
		v_psp_name.arr[v_psp_name.len] = '\0';

/* txn_ccy */
		v_txn_ccy.arr[v_txn_ccy.len] = '\0';

/* txn_amount */
		if (ind_txn_amount < 0) 
			v_txn_amount = 0.0;

/* Service_fee */
		if (ind_service_fee < 0) 
			v_service_fee = 0.0;

		sprintf(csLine, "%s%s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%.*s%s %s%f%s %s%f%s%s",
			PD_TR, PD_TD_STYLE,v_txn_id.len,v_txn_id.arr,PD_TD_END,
			PD_TD,v_txn_code_desc.len,v_txn_code_desc.arr,PD_TD_END,
			PD_TD,v_txn_date.len,v_txn_date.arr,PD_TD_END,
			PD_TD_STYLE,v_psp_id.len,v_psp_id.arr,PD_TD_END,
			PD_TD,v_psp_name.len,v_psp_name.arr,PD_TD_END,
			PD_TD,v_txn_ccy.len,v_txn_ccy.arr,PD_TD_END,
			PD_TD,v_txn_amount,PD_TD_END,
			PD_TD,v_service_fee,PD_TD_END, PD_TR_END
			);

		fprintf(fp,"%s\n",csLine);
	}
	fprintf(fp,"</table></body></html>\n");

	fclose(fp);
DEBUGLOG(("Extract_RPT011 iRet = [%d]\n",iRet));

	return iRet;
extract_rpt011_error:
DEBUGLOG(("extract_rpt011 code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	fclose(fp);
        return FAILURE;
}


int Extract_RPT013(const char* csFileName, SQL_CURSOR c_input_cursor)
{
DEBUGLOG(("Extract_RPT013\n"));
	int	iRet = SUCCESS;

	char	csLine[PD_TMP_BUF_LEN*8+1];

	FILE *fp;
	fp = fopen(csFileName,"w");
	if (fp == NULL) {
DEBUGLOG(("Extract_RPT013:unable to open [%s]\n",csFileName));
                return FAILURE;
	}

	fprintf(fp,"<html><body><table>\n");
	fprintf(fp,"%s%sTxn Desc%s%sService Desc%s%sStatus%s%sTransaction Count%s%s\n",PD_TR,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TR_END);
	fprintf(fp,"<style type=\"text/css\"> .format{ mso-number-format:'\\@';} </style>\n");

	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt013_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar v_txn_code_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_code_desc;

		/* varchar v_service_code[PD_SERVICE_CODE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

                /* varchar v_service_code_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_service_code_desc;

                /* varchar v_dm_status_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_dm_status_desc;

		int	v_count;

		short   ind_txn_code_desc = -1;
		short   ind_service_code = -1;
		short   ind_service_code_desc = -1;
		short   ind_dm_status_desc = -1;
		short	ind_count = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                /* EXEC SQL FETCH :c_input_cursor
                INTO
			:v_txn_code_desc:ind_txn_code_desc,
			:v_service_code:ind_service_code,
			:v_service_code_desc:ind_service_code_desc,
			:v_dm_status_desc:ind_dm_status_desc,
			:v_count:ind_count; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 23;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )726;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_code_desc;
                sqlstm.sqhstl[1] = (unsigned long )53;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_txn_code_desc;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_service_code;
                sqlstm.sqhstl[2] = (unsigned long )6;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_service_code;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_service_code_desc;
                sqlstm.sqhstl[3] = (unsigned long )53;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_service_code_desc;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_dm_status_desc;
                sqlstm.sqhstl[4] = (unsigned long )53;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_dm_status_desc;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_count;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_count;
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
                if (sqlca.sqlcode == 1403) break;
                if (sqlca.sqlcode < 0) goto extract_rpt013_error;
}



/* txn_desc */
		v_txn_code_desc.arr[v_txn_code_desc.len] = '\0';

/* service_code */
		v_service_code.arr[v_service_code.len] = '\0';

/* service_desc */
		v_service_code_desc.arr[v_service_code_desc.len] = '\0';

/* status */
		v_dm_status_desc.arr[v_dm_status_desc.len] = '\0';

/*count*/
		if (ind_count < 0) 
			v_count = 0;

		sprintf(csLine, "%s%s%.*s%s %s%.*s%s %s%.*s%s %s%d%s%s",
			PD_TR, PD_TD,v_txn_code_desc.len,v_txn_code_desc.arr,PD_TD_END,
			PD_TD,v_service_code_desc.len,v_service_code_desc.arr,PD_TD_END,
			PD_TD,v_dm_status_desc.len,v_dm_status_desc.arr,PD_TD_END,
			PD_TD,v_count,PD_TD_END, PD_TR_END
			);

		fprintf(fp,"%s\n",csLine);
	}
	fprintf(fp,"</table></body></html>\n");

	fclose(fp);
DEBUGLOG(("Extract_RPT013 iRet = [%d]\n",iRet));

	return iRet;
extract_rpt013_error:
DEBUGLOG(("extract_rpt013 code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	fclose(fp);
        return FAILURE;
}


int Extract_RPT_ESKY(const char* csFileName, SQL_CURSOR c_input_cursor)
{
DEBUGLOG(("Extract_RPT_ESKY\n"));
	int	iRet = SUCCESS;
	double	dAmt;
	char	csDate[PD_DATETIME_LEN+1];
	char	csLine[PD_TMP_BUF_LEN*2+1];

	FILE *fp;
	fp = fopen(csFileName,"w");
	if (fp == NULL) {
DEBUGLOG(("Extract_RPT_ESKY:unable to open [%s]\n",csFileName));
                return FAILURE;
	}

	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt_esky_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar v_txn_id[PD_TXN_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_txn_id;

                /* varchar v_tid[PD_PSP_TID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_tid;

                /* varchar v_txn_date[PD_DATE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_txn_date;

                /* varchar v_fundin_date[PD_DATETIME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_fundin_date;

                /* varchar v_bank_bill_no[PD_BANK_BILL_NO_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_bill_no;

                /* varchar v_amt[PD_AMOUNT_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[13]; } v_amt;

                double  v_fee;

                short   ind_txn_id = -1;
                short   ind_tid = -1;
                short   ind_txn_date = -1;
                short   ind_fundin_date = -1;
                short   ind_bank_bill_no = -1;
                short   ind_amt = -1;
                short   ind_fee = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                /* EXEC SQL FETCH :c_input_cursor
                INTO
                        :v_tid:ind_tid,
                        :v_txn_id:ind_txn_id,
                        :v_txn_date:ind_txn_date,
                        :v_fundin_date:ind_fundin_date,
                        :v_bank_bill_no:ind_bank_bill_no,
                        :v_amt:ind_amt,
                        :v_fee:ind_fee; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 23;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )765;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_tid;
                sqlstm.sqhstl[1] = (unsigned long )53;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_tid;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_id;
                sqlstm.sqhstl[2] = (unsigned long )23;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_txn_id;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_date;
                sqlstm.sqhstl[3] = (unsigned long )11;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_txn_date;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_fundin_date;
                sqlstm.sqhstl[4] = (unsigned long )17;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_fundin_date;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_bank_bill_no;
                sqlstm.sqhstl[5] = (unsigned long )53;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_bank_bill_no;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_amt;
                sqlstm.sqhstl[6] = (unsigned long )15;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_amt;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_fee;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_fee;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
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
                if (sqlca.sqlcode == 1403) break;
                if (sqlca.sqlcode < 0) goto extract_rpt_esky_error;
}


/* txn id */
		v_txn_id.arr[v_txn_id.len] = '\0';
/* tid */
		v_tid.arr[v_tid.len] = '\0';
/*fundin date */
		v_fundin_date.arr[v_fundin_date.len] = '\0';
		if(strlen((const char*)v_fundin_date.arr)==PD_DATETIME_LEN)
                	sprintf(csDate,"%.*s00",(int)strlen((const char*)v_fundin_date.arr)-2,v_fundin_date.arr);
		else if(strlen((const char*)v_fundin_date.arr)==PD_DATE_LEN)
			sprintf(csDate,"%.*s000000",(int)strlen((const char*)v_fundin_date.arr),v_fundin_date.arr);
		else
			sprintf(csDate,"%.*s",(int)strlen((const char*)v_fundin_date.arr),v_fundin_date.arr);
/*amt */
		v_amt.arr[v_amt.len] = '\0';
		sscanf((const char*)v_amt.arr,"%lf",&dAmt);
/*fee */
		if (ind_fee < 0) 
			v_fee = 0.0;

		sprintf(csLine,"%s,%s,%.2lf,%.2lf,Success,%s",v_txn_id.arr,v_tid.arr,dAmt,v_fee,csDate);
		fprintf(fp,"%s\n",csLine);
	}

	fclose(fp);
DEBUGLOG(("Extract_RPT_ESKY iRet = [%d]\n",iRet));
	return iRet;

extract_rpt_esky_error:
DEBUGLOG(("extract_rpt_esky code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	fclose(fp);
        return FAILURE;
}


int Extract_RPT_YPY(const char* csFileName, SQL_CURSOR c_input_cursor)
{
DEBUGLOG(("Extract_RPT_YPY\n"));
	int	iRet = SUCCESS;
	double	dAmt;
	char	csDate[PD_DATETIME_LEN+1];
	char	csLine[PD_TMP_BUF_LEN*2+1];

	FILE *fp;
	fp = fopen(csFileName,"w");
	if (fp == NULL) {
DEBUGLOG(("Extract_RPT_YPY:unable to open [%s]\n",csFileName));
                return FAILURE;
	}

	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt_ypy_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar v_txn_id[PD_TXN_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_txn_id;

                /* varchar v_tid[PD_PSP_TID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_tid;

                /* varchar v_txn_date[PD_DATE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_txn_date;

                /* varchar v_fundin_date[PD_DATETIME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_fundin_date;

                /* varchar v_bank_bill_no[PD_BANK_BILL_NO_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_bill_no;

                /* varchar v_amt[PD_AMOUNT_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[13]; } v_amt;

                double  v_fee;

                short   ind_txn_id = -1;
                short   ind_tid = -1;
                short   ind_txn_date = -1;
                short   ind_fundin_date = -1;
                short   ind_bank_bill_no = -1;
                short   ind_amt = -1;
                short   ind_fee = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                /* EXEC SQL FETCH :c_input_cursor
                INTO
                        :v_tid:ind_tid,
                        :v_txn_id:ind_txn_id,
                        :v_txn_date:ind_txn_date,
                        :v_fundin_date:ind_fundin_date,
                        :v_bank_bill_no:ind_bank_bill_no,
                        :v_amt:ind_amt,
                        :v_fee:ind_fee; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 23;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )812;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_tid;
                sqlstm.sqhstl[1] = (unsigned long )53;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_tid;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_id;
                sqlstm.sqhstl[2] = (unsigned long )23;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_txn_id;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_date;
                sqlstm.sqhstl[3] = (unsigned long )11;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_txn_date;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_fundin_date;
                sqlstm.sqhstl[4] = (unsigned long )17;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_fundin_date;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_bank_bill_no;
                sqlstm.sqhstl[5] = (unsigned long )53;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_bank_bill_no;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_amt;
                sqlstm.sqhstl[6] = (unsigned long )15;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_amt;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_fee;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_fee;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
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
                if (sqlca.sqlcode == 1403) break;
                if (sqlca.sqlcode < 0) goto extract_rpt_ypy_error;
}


/* txn id */
		v_txn_id.arr[v_txn_id.len] = '\0';
/* tid */
		v_tid.arr[v_tid.len] = '\0';
/*fundin date */
		v_fundin_date.arr[v_fundin_date.len] = '\0';
		if(strlen((const char*)v_fundin_date.arr)==PD_DATETIME_LEN)
                	sprintf(csDate,"%.*s00",(int)strlen((const char*)v_fundin_date.arr)-2,v_fundin_date.arr);
		else if(strlen((const char*)v_fundin_date.arr)==PD_DATE_LEN)
			sprintf(csDate,"%.*s000000",(int)strlen((const char*)v_fundin_date.arr),v_fundin_date.arr);
		else
			sprintf(csDate,"%.*s",(int)strlen((const char*)v_fundin_date.arr),v_fundin_date.arr);
/*amt */
		v_amt.arr[v_amt.len] = '\0';
		sscanf((const char*)v_amt.arr,"%lf",&dAmt);
/*fee */
		if (ind_fee < 0) 
			v_fee = 0.0;

		sprintf(csLine,"%s,%s,%.2lf,%.2lf,Success,%s",v_txn_id.arr,v_tid.arr,dAmt,v_fee,csDate);
		fprintf(fp,"%s\n",csLine);
	}

	fclose(fp);
DEBUGLOG(("Extract_RPT_YPY iRet = [%d]\n",iRet));
	return iRet;

extract_rpt_ypy_error:
DEBUGLOG(("extract_rpt_ypy code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	fclose(fp);
        return FAILURE;
}


int Extract_RPT_HCP(const char* csFileName, SQL_CURSOR c_input_cursor)
{
DEBUGLOG(("Extract_RPT_HCP\n"));
	int	iRet = SUCCESS;
	double	dAmt;
	char	csDate[PD_DATETIME_LEN+1];
	char	csLine[PD_TMP_BUF_LEN*2+1];

	FILE *fp;
	fp = fopen(csFileName,"w");
	if (fp == NULL) {
DEBUGLOG(("Extract_RPT_HCP:unable to open [%s]\n",csFileName));
                return FAILURE;
	}

	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt_hcp_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar v_txn_id[PD_TXN_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_txn_id;

                /* varchar v_tid[PD_PSP_TID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_tid;

                /* varchar v_txn_date[PD_DATE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_txn_date;

                /* varchar v_fundin_date[PD_DATETIME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_fundin_date;

                /* varchar v_bank_bill_no[PD_BANK_BILL_NO_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_bill_no;

                /* varchar v_amt[PD_AMOUNT_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[13]; } v_amt;

                double  v_fee;

                short   ind_txn_id = -1;
                short   ind_tid = -1;
                short   ind_txn_date = -1;
                short   ind_fundin_date = -1;
                short   ind_bank_bill_no = -1;
                short   ind_amt = -1;
                short   ind_fee = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                /* EXEC SQL FETCH :c_input_cursor
                INTO
                        :v_tid:ind_tid,
                        :v_txn_id:ind_txn_id,
                        :v_txn_date:ind_txn_date,
                        :v_fundin_date:ind_fundin_date,
                        :v_bank_bill_no:ind_bank_bill_no,
                        :v_amt:ind_amt,
                        :v_fee:ind_fee; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 23;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )859;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_tid;
                sqlstm.sqhstl[1] = (unsigned long )53;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_tid;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_id;
                sqlstm.sqhstl[2] = (unsigned long )23;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_txn_id;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_date;
                sqlstm.sqhstl[3] = (unsigned long )11;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_txn_date;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_fundin_date;
                sqlstm.sqhstl[4] = (unsigned long )17;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_fundin_date;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_bank_bill_no;
                sqlstm.sqhstl[5] = (unsigned long )53;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_bank_bill_no;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_amt;
                sqlstm.sqhstl[6] = (unsigned long )15;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_amt;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_fee;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_fee;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
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
                if (sqlca.sqlcode == 1403) break;
                if (sqlca.sqlcode < 0) goto extract_rpt_hcp_error;
}


/* txn id */
		v_txn_id.arr[v_txn_id.len] = '\0';
/* tid */
		v_tid.arr[v_tid.len] = '\0';
/* bank bill no*/
		v_bank_bill_no.arr[v_bank_bill_no.len] = '\0';
/*fundin date */
		v_fundin_date.arr[v_fundin_date.len] = '\0';
		if(strlen((const char*)v_fundin_date.arr)==PD_DATETIME_LEN)
                	sprintf(csDate,"%.*s00",(int)strlen((const char*)v_fundin_date.arr)-2,v_fundin_date.arr);
		else if(strlen((const char*)v_fundin_date.arr)==PD_DATE_LEN)
			sprintf(csDate,"%.*s000000",(int)strlen((const char*)v_fundin_date.arr),v_fundin_date.arr);
		else
			sprintf(csDate,"%.*s",(int)strlen((const char*)v_fundin_date.arr),v_fundin_date.arr);
/*amt */
		v_amt.arr[v_amt.len] = '\0';
		sscanf((const char*)v_amt.arr,"%lf",&dAmt);
/*fee */
		if (ind_fee < 0) 
			v_fee = 0.0;

		sprintf(csLine,"%s,%s,%s,%.2lf,Success",v_txn_id.arr,v_tid.arr,v_bank_bill_no.arr,dAmt);
		fprintf(fp,"%s\n",csLine);
	}

	fclose(fp);
DEBUGLOG(("Extract_RPT_HCP iRet = [%d]\n",iRet));
	return iRet;

extract_rpt_hcp_error:
DEBUGLOG(("extract_rpt_hcp code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	fclose(fp);
        return FAILURE;
}



int Extract_RPT_TWV(const char* csFileName, SQL_CURSOR c_input_cursor)
{
DEBUGLOG(("Extract_RPT_TWV\n"));
	int	iRet = SUCCESS;
	char	csDate[PD_DATETIME_LEN+1];
	char	csLine[PD_TMP_BUF_LEN*2+1];

	FILE *fp;
	fp = fopen(csFileName,"w");
	if (fp == NULL) {
DEBUGLOG(("Extract_RPT_TWV:unable to open [%s]\n",csFileName));
                return FAILURE;
	}

	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt_twv_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar v_txn_id[PD_TXN_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_txn_id;

                /* varchar v_tid[PD_PSP_TID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_tid;

                /* varchar v_txn_date[PD_DATE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_txn_date;

                /* varchar v_fundin_date[PD_DATETIME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_fundin_date;

                /* varchar v_bank_bill_no[PD_BANK_BILL_NO_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_bill_no;

                /* varchar v_amt[PD_AMOUNT_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[13]; } v_amt;

                double  v_fee;

                short   ind_txn_id = -1;
                short   ind_tid = -1;
                short   ind_txn_date = -1;
                short   ind_fundin_date = -1;
                short   ind_bank_bill_no = -1;
                short   ind_amt = -1;
                short   ind_fee = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                /* EXEC SQL FETCH :c_input_cursor
                INTO
                        :v_tid:ind_tid,
                        :v_txn_id:ind_txn_id,
                        :v_txn_date:ind_txn_date,
                        :v_fundin_date:ind_fundin_date,
                        :v_bank_bill_no:ind_bank_bill_no,
                        :v_amt:ind_amt,
                        :v_fee:ind_fee; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 23;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )906;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_tid;
                sqlstm.sqhstl[1] = (unsigned long )53;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_tid;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_id;
                sqlstm.sqhstl[2] = (unsigned long )23;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_txn_id;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_date;
                sqlstm.sqhstl[3] = (unsigned long )11;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_txn_date;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_fundin_date;
                sqlstm.sqhstl[4] = (unsigned long )17;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_fundin_date;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_bank_bill_no;
                sqlstm.sqhstl[5] = (unsigned long )53;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_bank_bill_no;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_amt;
                sqlstm.sqhstl[6] = (unsigned long )15;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_amt;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_fee;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_fee;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
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
                if (sqlca.sqlcode == 1403) break;
                if (sqlca.sqlcode < 0) goto extract_rpt_twv_error;
}


/* txn id */
		v_txn_id.arr[v_txn_id.len] = '\0';
/* tid */
		v_tid.arr[v_tid.len] = '\0';
/*txn date */
		v_txn_date.arr[v_txn_date.len] = '\0';
/*fundin date */
		v_fundin_date.arr[v_fundin_date.len] = '\0';
		sprintf(csDate,"%.*s",PD_DATE_LEN,v_fundin_date.arr);
/*amt */
		v_amt.arr[v_amt.len] = '\0';
/*fee */
		if (ind_fee < 0) 
			v_fee = 0.0;

		sprintf(csLine,"%s,%s,%s,,WebATM,%s,%s,%ld",v_txn_id.arr,v_tid.arr,v_txn_date.arr,v_amt.arr,csDate,(long)v_fee);
		fprintf(fp,"%s\n",csLine);
	}

	fclose(fp);
DEBUGLOG(("Extract_RPT_TWV iRet = [%d]\n",iRet));
	return iRet;

extract_rpt_twv_error:
DEBUGLOG(("extract_rpt_twv code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	fclose(fp);
        return FAILURE;
}


int Extract_RPT_ALP(const char* csFileName, SQL_CURSOR c_input_cursor)
{
DEBUGLOG(("Extract_RPT_ALP\n"));
	int	iRet = SUCCESS;
	char	csDate[PD_DATETIME_LEN+1];
	char	csLine[PD_TMP_BUF_LEN*2+1];

	FILE *fp;
	fp = fopen(csFileName,"w");
	if (fp == NULL) {
DEBUGLOG(("Extract_RPT_ALP:unable to open [%s]\n",csFileName));
                return FAILURE;
	}

	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt_alp_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar v_txn_id[PD_TXN_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_txn_id;

                /* varchar v_tid[PD_PSP_TID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_tid;

                /* varchar v_txn_date[PD_DATE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_txn_date;

                /* varchar v_fundin_date[PD_DATETIME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_fundin_date;

                /* varchar v_bank_bill_no[PD_BANK_BILL_NO_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_bill_no;

                /* varchar v_amt[PD_AMOUNT_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[13]; } v_amt;

                double  v_fee;

                short   ind_txn_id = -1;
                short   ind_tid = -1;
                short   ind_txn_date = -1;
                short   ind_fundin_date = -1;
                short   ind_bank_bill_no = -1;
                short   ind_amt = -1;
                short   ind_fee = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                /* EXEC SQL FETCH :c_input_cursor
                INTO
                        :v_tid:ind_tid,
                        :v_txn_id:ind_txn_id,
                        :v_txn_date:ind_txn_date,
                        :v_fundin_date:ind_fundin_date,
                        :v_bank_bill_no:ind_bank_bill_no,
                        :v_amt:ind_amt,
                        :v_fee:ind_fee; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 23;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )953;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_tid;
                sqlstm.sqhstl[1] = (unsigned long )53;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_tid;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_id;
                sqlstm.sqhstl[2] = (unsigned long )23;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_txn_id;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_date;
                sqlstm.sqhstl[3] = (unsigned long )11;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_txn_date;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_fundin_date;
                sqlstm.sqhstl[4] = (unsigned long )17;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_fundin_date;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_bank_bill_no;
                sqlstm.sqhstl[5] = (unsigned long )53;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_bank_bill_no;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_amt;
                sqlstm.sqhstl[6] = (unsigned long )15;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_amt;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_fee;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_fee;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
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
                if (sqlca.sqlcode == 1403) break;
                if (sqlca.sqlcode < 0) goto extract_rpt_alp_error;
}


/* txn id */
		v_txn_id.arr[v_txn_id.len] = '\0';
/* tid */
		v_tid.arr[v_tid.len] = '\0';
/*amt */
		v_amt.arr[v_amt.len] = '\0';
/*fee */
		if (ind_fee < 0) 
			v_fee = 0.0;
/*fundin date */
		v_fundin_date.arr[v_fundin_date.len] = '\0';
		sprintf(csDate,"%.*s",PD_DATE_LEN,v_fundin_date.arr);

		sprintf(csLine,"%s|%s|%s|%ld|%s",v_txn_id.arr,v_tid.arr,v_amt.arr,(long)v_fee,csDate);
		fprintf(fp,"%s\n",csLine);
	}

	fclose(fp);
DEBUGLOG(("Extract_RPT_ALP iRet = [%d]\n",iRet));
	return iRet;

extract_rpt_alp_error:
DEBUGLOG(("extract_rpt_alp code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	fclose(fp);
        return FAILURE;
}


int Extract_RPT_DETAIL(const char* csFileName, SQL_CURSOR c_input_cursor)
{
DEBUGLOG(("Extract_RPT_DETAIL\n"));
	int	iRet = SUCCESS;
	//double	dAmt;
	//char	csDate[PD_DATETIME_LEN+1];
	//char	csLine[PD_TMP_BUF_LEN*2+1];
	char	*csEcRef;

	FILE *fp;
	fp = fopen(csFileName,"w");
	if (fp == NULL) {
DEBUGLOG(("Extract_RPT_DETAIL:unable to open [%s]\n",csFileName));
                return FAILURE;
	}

	fprintf(fp,"<html><body><table>\n");
        fprintf(fp,"%s%sPH Txn ID%s%sPH Txn Code%s%sPH Status%s%sAR_IND%s%sPH Response Code%s%sClient Name%s%sMerchant ID%s%sMerchant Refernece%s%sEC2 Refernece%s%sPSP Name%s%sPSP Txn ID%s%sBank Bill No.%s%sTxn Ccy%s%sTxn Amount%s%sPSP Service Fee%s%sPH Posting Date%s%sMerchant Txn Date%s%sPH Txn Date%s%sPSP Txn Date%s%sLast Update Date%s%s\n",PD_TR,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TR_END);
        fprintf(fp,"<style type=\"text/css\"> .format{ mso-number-format:'\\@';} </style>\n");



	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt_detail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		char    v_status;
		char    v_ar_ind;
		int     v_internal_code;
		/* varchar v_response_code[PD_RESPONSE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_response_code;

		/* varchar v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar v_merchant_ref[PD_MERCHANT_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar v_psp_name[PD_PSP_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_name;

		/* varchar v_tid[PD_MERCHANT_REF_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_tid;

		/* varchar v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

		double  v_txn_amount;
		double  v_service_fee;
		/* varchar v_merchant_txn_date[PD_DATETIME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_merchant_txn_date;

		/* varchar v_local_txn_date[PD_DATE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_local_txn_date;

		/* varchar v_local_txn_time[PD_DATE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_local_txn_time;

		/* varchar v_psp_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_psp_txn_date;

		/* varchar v_host_posting_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_host_posting_date;

		/* varchar v_txn_code_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_code_desc;

		/* varchar v_txn_code[PD_TXN_CODE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

		/* varchar v_client_name[PD_CLIENT_NAME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_client_name;

		/* varchar v_last_updatetime[PD_DATETIME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_last_updatetime;

		/* varchar v_bill_no[PD_BANK_BILL_NO_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bill_no;


		short   ind_txn_id = -1;
		short   ind_status = -1;
		short   ind_ar_ind = -1;
		short   ind_internal_code = -1;
		short   ind_response_code = -1;
		short   ind_merchant_id = -1;
		short   ind_merchant_ref = -1;
		short   ind_psp_name = -1;
		short   ind_tid = -1;
		short   ind_txn_ccy = -1;
		short   ind_txn_amount = -1;
		short   ind_service_fee = -1;
		short   ind_merchant_txn_date = -1;
		short   ind_local_txn_date = -1;
		short   ind_local_txn_time = -1;
		short   ind_psp_txn_date = -1;
		short   ind_host_posting_date = -1;
		short   ind_txn_code_desc = -1;
		short   ind_txn_code = -1;
		short   ind_client_name = -1;
		short   ind_last_updatetime = -1;
		short   ind_bill_no = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                /* EXEC SQL FETCH :c_input_cursor
                INTO
			v_txn_id:ind_txn_id,
			v_status:ind_status,
			v_ar_ind:ind_ar_ind,
			v_internal_code:ind_internal_code,
			v_response_code:ind_response_code,
			v_merchant_id:ind_merchant_id,
			v_merchant_ref:ind_merchant_ref,
			v_psp_name:ind_psp_name,
			v_tid:ind_tid,
			v_txn_ccy:ind_txn_ccy,
			v_txn_amount:ind_txn_amount,
			v_service_fee:ind_service_fee,
			v_merchant_txn_date:ind_merchant_txn_date,
			v_local_txn_date:ind_local_txn_date,
			v_local_txn_time:ind_local_txn_time,
			v_psp_txn_date:ind_psp_txn_date,
			v_host_posting_date:ind_host_posting_date,
			v_txn_code_desc:ind_txn_code_desc,
			v_txn_code:ind_txn_code,
			v_last_updatetime:ind_last_updatetime,
			v_client_name:ind_client_name,
			v_bill_no:ind_bill_no; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 23;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )1000;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_id;
                sqlstm.sqhstl[1] = (unsigned long )19;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_txn_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_status;
                sqlstm.sqhstl[2] = (unsigned long )1;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_status;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_ar_ind;
                sqlstm.sqhstl[3] = (unsigned long )1;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_ar_ind;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_internal_code;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_internal_code;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_response_code;
                sqlstm.sqhstl[5] = (unsigned long )7;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_response_code;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_merchant_id;
                sqlstm.sqhstl[6] = (unsigned long )18;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_merchant_id;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_merchant_ref;
                sqlstm.sqhstl[7] = (unsigned long )53;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_merchant_ref;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_psp_name;
                sqlstm.sqhstl[8] = (unsigned long )53;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_psp_name;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_tid;
                sqlstm.sqhstl[9] = (unsigned long )53;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_tid;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_txn_ccy;
                sqlstm.sqhstl[10] = (unsigned long )6;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_txn_ccy;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_amount;
                sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_txn_amount;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
                sqlstm.sqhstv[12] = (unsigned char  *)&v_service_fee;
                sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_service_fee;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
                sqlstm.sqhstv[13] = (unsigned char  *)&v_merchant_txn_date;
                sqlstm.sqhstl[13] = (unsigned long )17;
                sqlstm.sqhsts[13] = (         int  )0;
                sqlstm.sqindv[13] = (         short *)&ind_merchant_txn_date;
                sqlstm.sqinds[13] = (         int  )0;
                sqlstm.sqharm[13] = (unsigned long )0;
                sqlstm.sqadto[13] = (unsigned short )0;
                sqlstm.sqtdso[13] = (unsigned short )0;
                sqlstm.sqhstv[14] = (unsigned char  *)&v_local_txn_date;
                sqlstm.sqhstl[14] = (unsigned long )11;
                sqlstm.sqhsts[14] = (         int  )0;
                sqlstm.sqindv[14] = (         short *)&ind_local_txn_date;
                sqlstm.sqinds[14] = (         int  )0;
                sqlstm.sqharm[14] = (unsigned long )0;
                sqlstm.sqadto[14] = (unsigned short )0;
                sqlstm.sqtdso[14] = (unsigned short )0;
                sqlstm.sqhstv[15] = (unsigned char  *)&v_local_txn_time;
                sqlstm.sqhstl[15] = (unsigned long )11;
                sqlstm.sqhsts[15] = (         int  )0;
                sqlstm.sqindv[15] = (         short *)&ind_local_txn_time;
                sqlstm.sqinds[15] = (         int  )0;
                sqlstm.sqharm[15] = (unsigned long )0;
                sqlstm.sqadto[15] = (unsigned short )0;
                sqlstm.sqtdso[15] = (unsigned short )0;
                sqlstm.sqhstv[16] = (unsigned char  *)&v_psp_txn_date;
                sqlstm.sqhstl[16] = (unsigned long )11;
                sqlstm.sqhsts[16] = (         int  )0;
                sqlstm.sqindv[16] = (         short *)&ind_psp_txn_date;
                sqlstm.sqinds[16] = (         int  )0;
                sqlstm.sqharm[16] = (unsigned long )0;
                sqlstm.sqadto[16] = (unsigned short )0;
                sqlstm.sqtdso[16] = (unsigned short )0;
                sqlstm.sqhstv[17] = (unsigned char  *)&v_host_posting_date;
                sqlstm.sqhstl[17] = (unsigned long )11;
                sqlstm.sqhsts[17] = (         int  )0;
                sqlstm.sqindv[17] = (         short *)&ind_host_posting_date;
                sqlstm.sqinds[17] = (         int  )0;
                sqlstm.sqharm[17] = (unsigned long )0;
                sqlstm.sqadto[17] = (unsigned short )0;
                sqlstm.sqtdso[17] = (unsigned short )0;
                sqlstm.sqhstv[18] = (unsigned char  *)&v_txn_code_desc;
                sqlstm.sqhstl[18] = (unsigned long )53;
                sqlstm.sqhsts[18] = (         int  )0;
                sqlstm.sqindv[18] = (         short *)&ind_txn_code_desc;
                sqlstm.sqinds[18] = (         int  )0;
                sqlstm.sqharm[18] = (unsigned long )0;
                sqlstm.sqadto[18] = (unsigned short )0;
                sqlstm.sqtdso[18] = (unsigned short )0;
                sqlstm.sqhstv[19] = (unsigned char  *)&v_txn_code;
                sqlstm.sqhstl[19] = (unsigned long )6;
                sqlstm.sqhsts[19] = (         int  )0;
                sqlstm.sqindv[19] = (         short *)&ind_txn_code;
                sqlstm.sqinds[19] = (         int  )0;
                sqlstm.sqharm[19] = (unsigned long )0;
                sqlstm.sqadto[19] = (unsigned short )0;
                sqlstm.sqtdso[19] = (unsigned short )0;
                sqlstm.sqhstv[20] = (unsigned char  *)&v_last_updatetime;
                sqlstm.sqhstl[20] = (unsigned long )17;
                sqlstm.sqhsts[20] = (         int  )0;
                sqlstm.sqindv[20] = (         short *)&ind_last_updatetime;
                sqlstm.sqinds[20] = (         int  )0;
                sqlstm.sqharm[20] = (unsigned long )0;
                sqlstm.sqadto[20] = (unsigned short )0;
                sqlstm.sqtdso[20] = (unsigned short )0;
                sqlstm.sqhstv[21] = (unsigned char  *)&v_client_name;
                sqlstm.sqhstl[21] = (unsigned long )53;
                sqlstm.sqhsts[21] = (         int  )0;
                sqlstm.sqindv[21] = (         short *)&ind_client_name;
                sqlstm.sqinds[21] = (         int  )0;
                sqlstm.sqharm[21] = (unsigned long )0;
                sqlstm.sqadto[21] = (unsigned short )0;
                sqlstm.sqtdso[21] = (unsigned short )0;
                sqlstm.sqhstv[22] = (unsigned char  *)&v_bill_no;
                sqlstm.sqhstl[22] = (unsigned long )53;
                sqlstm.sqhsts[22] = (         int  )0;
                sqlstm.sqindv[22] = (         short *)&ind_bill_no;
                sqlstm.sqinds[22] = (         int  )0;
                sqlstm.sqharm[22] = (unsigned long )0;
                sqlstm.sqadto[22] = (unsigned short )0;
                sqlstm.sqtdso[22] = (unsigned short )0;
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
                if (sqlca.sqlcode == 1403) break;
                if (sqlca.sqlcode < 0) goto extract_rpt_detail_error;
}




		fprintf(fp,"%s",PD_TR);
/* txn id */
		v_txn_id.arr[v_txn_id.len] = '\0';
		fprintf(fp,"%s%.*s%s",PD_TD_STYLE,v_txn_id.len,v_txn_id.arr,PD_TD_END);

/* txn_desc  */
		v_txn_code_desc.arr[v_txn_code_desc.len] = '\0';
		fprintf(fp,"%s%.*s%s",PD_TD,v_txn_code_desc.len,v_txn_code_desc.arr,PD_TD_END);
/* status */
		if (ind_status < 0 )
			fprintf(fp,"%s%s",PD_TD,PD_TD_END);
		else {
			if (v_status == 'C')
				fprintf(fp,"%sCompleted%s",PD_TD,PD_TD_END);
			else if(v_status == 'W')
				fprintf(fp,"%sPending%s",PD_TD,PD_TD_END);
			else
				fprintf(fp,"%sProcessing%s",PD_TD,PD_TD_END);
		}
/* ar ind */
		if (ind_ar_ind < 0 )
			fprintf(fp,"%s%s",PD_TD,PD_TD_END);
		else {
			if (v_ar_ind == 'A')
				fprintf(fp,"%sAccept%s",PD_TD,PD_TD_END);
			else
				fprintf(fp,"%sReject%s",PD_TD,PD_TD_END);
		}

/* response_code */
                v_response_code.arr[v_response_code.len] = '\0';
		fprintf(fp,"%s%.*s%s",PD_TD,v_response_code.len,v_response_code.arr,PD_TD_END);

/* client_name */
                v_client_name.arr[v_client_name.len] = '\0';
		fprintf(fp,"%s%.*s%s",PD_TD,v_client_name.len,v_client_name.arr,PD_TD_END);

/* merchant_id */
                v_merchant_id.arr[v_merchant_id.len] = '\0';
		fprintf(fp,"%s%.*s%s",PD_TD_STYLE,v_merchant_id.len,v_merchant_id.arr,PD_TD_END);

/* merchant_ref */
		v_merchant_ref.arr[v_merchant_ref.len] = '\0';
		fprintf(fp,"%s%.*s%s",PD_TD_STYLE,v_merchant_ref.len,v_merchant_ref.arr,PD_TD_END);

/* EC2_ref */
		v_txn_code.arr[v_txn_code.len] = '\0';

		if(strncmp((const char*)v_txn_code.arr,PD_DEPOSIT_TXN_CODE,PD_TXN_CODE_LEN)==0){
			csEcRef = strdup("");
			strcpy(csEcRef,(const char*)v_merchant_ref.arr);
			csEcRef[v_merchant_ref.len]='\0';
			fprintf(fp,"%s%c%s%s",PD_TD_STYLE,csEcRef[START_POS],&csEcRef[CONTENT_POS],PD_TD_END);
			FREE_ME(csEcRef);
		}
		else
			fprintf(fp,"%s%s",PD_TD_STYLE,PD_TD_END);

/* psp_name */
		v_psp_name.arr[v_psp_name.len] = '\0';
		fprintf(fp,"%s%.*s%s",PD_TD,v_psp_name.len,v_psp_name.arr,PD_TD_END);

/* tid */
		v_tid.arr[v_tid.len] = '\0';
		fprintf(fp,"%s%.*s%s",PD_TD_STYLE,v_tid.len,v_tid.arr,PD_TD_END);

/* bank_bill_no */
                if (ind_bill_no< 0 ){
			strcpy((char*)v_bill_no.arr,"N/A");
			v_bill_no.len=strlen("N/A");
		}
		v_bill_no.arr[v_bill_no.len] = '\0';
		fprintf(fp,"%s%.*s%s",PD_TD_STYLE,v_bill_no.len,v_bill_no.arr,PD_TD_END);

/* txn_ccy */
		v_txn_ccy.arr[v_txn_ccy.len] = '\0';
		fprintf(fp,"%s%.*s%s",PD_TD,v_txn_ccy.len,v_txn_ccy.arr,PD_TD_END);

/* txn_amount */
		v_txn_amount = 0;
		fprintf(fp,"%s%f%s",PD_TD,v_txn_amount,PD_TD_END);

/* service_fee */
		v_service_fee = 0;
		fprintf(fp,"%s%f%s",PD_TD,v_service_fee,PD_TD_END);

/* host posting date */
		v_host_posting_date.arr[v_host_posting_date.len] = '\0';
		fprintf(fp,"%s%.*s%s",PD_TD_STYLE,v_host_posting_date.len,v_host_posting_date.arr,PD_TD_END);

/* merchant_txn_date */
		v_merchant_txn_date.arr[v_merchant_txn_date.len] = '\0';
		fprintf(fp,"%s%.*s%s",PD_TD_STYLE,v_merchant_txn_date.len,v_merchant_txn_date.arr,PD_TD_END);

/* local_txn_date */
		v_local_txn_date.arr[v_local_txn_date.len] = '\0';
		v_local_txn_time.arr[v_local_txn_time.len] = '\0';
		fprintf(fp,"%s%.*s %.*s%s",PD_TD_STYLE,v_local_txn_date.len,v_local_txn_date.arr,v_local_txn_time.len,v_local_txn_time.arr,PD_TD_END);

/* psp_txn_date */
		v_psp_txn_date.arr[v_psp_txn_date.len] = '\0';
		fprintf(fp,"%s%.*s%s",PD_TD_STYLE,v_psp_txn_date.len,v_psp_txn_date.arr,PD_TD_END);

/* last_updatetime */
		v_last_updatetime.arr[v_last_updatetime.len] = '\0';
		fprintf(fp,"%s%.*s%s",PD_TD_STYLE,v_last_updatetime.len,v_last_updatetime.arr,PD_TD_END);

		fprintf(fp,"%s\n",PD_TR_END);

	}

	fprintf(fp,"</table></body></html>\n");
	fclose(fp);
DEBUGLOG(("Extract_RPT_DETAIL iRet = [%d]\n",iRet));
	return iRet;

extract_rpt_detail_error:
DEBUGLOG(("extract_rpt_detail code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	fclose(fp);
        return FAILURE;
}


int Extract_RPT_SUMMARY(const char* csFileName, SQL_CURSOR c_input_cursor)
{
DEBUGLOG(("Extract_RPT_SUMMARY\n"));
	int	iRet = SUCCESS;
	char	*csStatus=strdup(" ");

	FILE *fp;
	fp = fopen(csFileName,"w");
	if (fp == NULL) {
DEBUGLOG(("Extract_RPT_SUMMARY:unable to open [%s]\n",csFileName));
                return FAILURE;
	}

	fprintf(fp,"<html><body><table>\n");
        fprintf(fp,"<tr><td>Txn Deail Summary</td></tr>\n");
        fprintf(fp,"<tr><td></td></tr>\n");
	fprintf(fp,"<tr><td>Txn Type</td><td>Status</td><td>Count</td><td>Amount</td></tr>\n");

	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt_summary_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar v_txn_type[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_type;

		char	v_status;
		char	v_ar_ind;
		double	v_amount;
		int	v_count;

                short   ind_txn_type= -1;
                short   ind_status= -1;
                short   ind_ar_ind= -1;
                short   ind_amount= -1;
                short   ind_count= -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                /* EXEC SQL FETCH :c_input_cursor
                INTO
                        :v_amount:ind_amount,
                        :v_count:ind_count,
                        :v_status:ind_status,
                        :v_ar_ind:ind_ar_ind,
                        :v_txn_type:ind_txn_type; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 23;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )1107;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)0;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_amount;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_amount;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_count;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_count;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_status;
                sqlstm.sqhstl[3] = (unsigned long )1;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_status;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_ar_ind;
                sqlstm.sqhstl[4] = (unsigned long )1;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_ar_ind;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_txn_type;
                sqlstm.sqhstl[5] = (unsigned long )53;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_txn_type;
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
                if (sqlca.sqlcode == 1403) break;
                if (sqlca.sqlcode < 0) goto extract_rpt_summary_error;
}



/* txn type */
		v_txn_type.arr[v_txn_type.len] = '\0';

/*status*/
		if(ind_ar_ind>=0){
			if(v_ar_ind==PD_ACCEPT)
				csStatus=strdup("Accepted");
			else if(v_ar_ind==PD_REJECT)
				csStatus=strdup("Rejected");
		}
		else{
			if(v_status==PD_TO_PSP)
				csStatus=strdup("Pending");
			else
				csStatus=strdup("Other");
		}

/*count*/
		if (ind_count < 0) 
			v_count = 0;
/*amount*/
		if (ind_amount < 0) 
			v_amount = 0.0;

		fprintf(fp,"<tr><td>[%s]</td><td>%s</td><td>%d</td><td>%f</td></tr>\n",v_txn_type.arr,csStatus,v_count,v_amount);
	}

	fprintf(fp,"</table></body></html>\n");
	FREE_ME(csStatus);
	fclose(fp);
DEBUGLOG(("Extract_RPT_SUMMARY iRet = [%d]\n",iRet));
	return iRet;

extract_rpt_summary_error:
DEBUGLOG(("extract_rpt_summary code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	FREE_ME(csStatus);
	fclose(fp);
        return FAILURE;
}



char *GetFileName(const unsigned char* csPspName, const char* cs_eod_date)
{
	static  char cs_filename[PD_TMP_BUF_LEN + 1];

	sprintf(cs_filename, "%s/%s_DSP_%s.dat", getenv("REPORT_DATA"),csPspName,cs_eod_date);

	return cs_filename;
}

char *GetTxnDetailFileName(const unsigned char* csPspName, const unsigned char* csCountry, const char* cs_eod_date, const char* csType)
{
	static  char cs_detailfilename[PD_MAX_FILE_LEN + 1];
	char	cs_tmp[PD_MAX_FILE_LEN+1];

/* create report path */
        sprintf(cs_detailfilename, "%s", getenv("REPORT_HOME"));
        sprintf(cs_tmp, "mkdir %s >/dev/null 2>&1", cs_detailfilename);
        system(cs_tmp);

        sprintf(cs_detailfilename, "%s/%.*s", getenv("REPORT_HOME"),PD_YYYY_LEN,cs_eod_date);
        sprintf(cs_tmp, "mkdir %s >/dev/null 2>&1", cs_detailfilename);
        system(cs_tmp);

        sprintf(cs_detailfilename, "%s/%.*s/%.*s", getenv("REPORT_HOME"),PD_YYYY_LEN,cs_eod_date,PD_YYYYMM_LEN,cs_eod_date);
        sprintf(cs_tmp, "mkdir %s >/dev/null 2>&1", cs_detailfilename);
        system(cs_tmp);

        sprintf(cs_detailfilename, "%s/%.*s/%.*s/%s", getenv("REPORT_HOME"),PD_YYYY_LEN,cs_eod_date,PD_YYYYMM_LEN,cs_eod_date,cs_eod_date);
        sprintf(cs_tmp, "mkdir %s >/dev/null 2>&1", cs_detailfilename);
        system(cs_tmp);

        sprintf(cs_detailfilename, "%s/%.*s/%.*s/%s/%s", getenv("REPORT_HOME"),PD_YYYY_LEN,cs_eod_date,PD_YYYYMM_LEN,cs_eod_date,cs_eod_date,csCountry);
        sprintf(cs_tmp, "mkdir %s >/dev/null 2>&1", cs_detailfilename);
        system(cs_tmp);

        sprintf(cs_detailfilename, "%s/%.*s/%.*s/%s/%s/%s", getenv("REPORT_HOME"),PD_YYYY_LEN,cs_eod_date,PD_YYYYMM_LEN,cs_eod_date,cs_eod_date,csCountry,csPspName);
        sprintf(cs_tmp, "mkdir %s >/dev/null 2>&1", cs_detailfilename);
        system(cs_tmp);

	if(!strcmp(csType,"daily"))
		sprintf(cs_detailfilename, "%s/%.*s/%.*s/%s/%s/%s/TXN_DETAIL.xls",getenv("REPORT_HOME"),PD_YYYY_LEN,cs_eod_date,PD_YYYYMM_LEN,cs_eod_date,cs_eod_date,csCountry,csPspName);

	else if(!strcmp(csType,"summary"))
		sprintf(cs_detailfilename, "%s/%.*s/%.*s/%s/%s/%s/TXN_DETAIL_SUMMARY.xls",getenv("REPORT_HOME"),PD_YYYY_LEN,cs_eod_date,PD_YYYYMM_LEN,cs_eod_date,cs_eod_date,csCountry,csPspName);

	else if(!strcmp(csType,"live"))
		sprintf(cs_detailfilename, "%s/%.*s/%.*s/%s/%s/%s/TXN_DETAIL_LIVE.xls",getenv("REPORT_HOME"),PD_YYYY_LEN,cs_eod_date,PD_YYYYMM_LEN,cs_eod_date,cs_eod_date,csCountry,csPspName);

	else if(!strcmp(csType,"livesummary"))
		sprintf(cs_detailfilename, "%s/%.*s/%.*s/%s/%s/%s/TXN_DETAIL_LIVE_SUMMARY.xls",getenv("REPORT_HOME"),PD_YYYY_LEN,cs_eod_date,PD_YYYYMM_LEN,cs_eod_date,cs_eod_date,csCountry,csPspName);


	return cs_detailfilename;
}
