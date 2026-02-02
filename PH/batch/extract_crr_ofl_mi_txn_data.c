
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
           char  filnam[31];
};
static struct sqlcxp sqlfpn =
{
    30,
    "extract_crr_ofl_mi_txn_data.pc"
};


static unsigned int sqlctx = 562136963;


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
   unsigned char  *sqhstv[17];
   unsigned long  sqhstl[17];
            int   sqhsts[17];
            short *sqindv[17];
            int   sqinds[17];
   unsigned long  sqharm[17];
   unsigned long  *sqharc[17];
   unsigned short  sqadto[17];
   unsigned short  sqtdso[17];
} sqlstm = {12,17};

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
"element_type = 'UDPA' ) t3_udpa , ( \
select ote_txn_id , ote_ccy , ote_amount from ol_txn_elements where ote_txn_e\
lement_type in ( 'TFEE' , 'INCT' ) ) t4_fee where oth_txn_id = otd_txn_id ( +\
 ) and oth_txn_id = otm_txn_id and oth_txn_id = t1_intr . ote_txn_id ( + ) an\
d oth_txn_id = t2_ovpa . ote_txn_id ( + ) and oth_txn_id = t3_udpa . ote_txn_\
id ( + ) and oth_txn_id = t4_fee . ote_txn_id ( + ) and oth_approval_date = :\
b0 order by oth_txn_id desc            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,1484,0,9,205,0,2049,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,13,207,0,0,17,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,
9,0,0,2,4,0,0,
107,0,0,1,0,0,15,347,0,0,0,0,0,1,0,
122,0,0,1,0,0,15,355,0,0,0,0,0,1,0,
137,0,0,2,0,0,32,356,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version					   2015/12/30              Dirk Wong
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
char    cDebug = 'Y';

int parse_arg(int argc,char **argv);
int process_data(const char* csTxnDate, FILE *fp);

int batch_init(int argc, char* argv[])
{

    if (argc < 2) {
        printf("usage:  -d Date\n");
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
        	printf("usage:  -o ouputfile -d Date\n");
                return (iRet);
        }

        char    cs_yyyy[PD_YYYY_LEN+1];
        char    cs_yyyymm[PD_YYYY_LEN+PD_MM_LEN+1];
        strncpy(cs_yyyy,cs_date,4);
        strncpy(cs_yyyymm,cs_date,6);

        sprintf(cs_outfile_name, "%s/%s/%s/%s/crr_ofl_mi_txn_data_%s.csv",getenv("REPORT_HOME"),cs_yyyy,cs_yyyymm,cs_date,cs_date);
        
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

		/* varchar	hv_approval_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } hv_approval_date;


		/* varchar	v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar	v_txn_code[PD_TXN_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

		/* varchar	v_approval_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_approval_date;

		/* varchar	v_entity_id[PD_MMS_ENTITY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_entity_id;

		/* varchar	v_party_type[PD_MMS_ENTITY_TYPE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_party_type;

		/* varchar	v_party_id[PD_MMS_ENTITY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_party_id;

		/* varchar v_txn_product[PD_PRODUCT_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_product;

		/* varchar	v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		/* varchar	v_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ccy;

		double	v_txn_amt;
		/* varchar	v_net_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_net_ccy;

		double	v_net_amt;
		double	v_intr_amt;
		double	v_ovpa_amt;
		double	v_udpa_amt;
		/* varchar	v_fee_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_fee_ccy;

		double	v_fee_amt;

		short	ind_txn_id = -1;
		short	ind_txn_code = -1;
		short	ind_approval_date = -1;
		short	ind_entity_id = 1;
		short	ind_party_type = -1;
		short	ind_party_id = -1;
		short	ind_txn_product = -1;
		short	ind_country = -1;
		short	ind_ccy = -1;
		short	ind_txn_amt = -1;
		short	ind_net_ccy = -1;
		short	ind_net_amt = -1;
		short	ind_intr_amt = -1;
		short	ind_ovpa_amt = -1;
		short	ind_udpa_amt = -1;
		short	ind_fee_ccy = -1;
		short	ind_fee_amt = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_approval_date.len = strlen(cs_date);
	memcpy(hv_approval_date.arr,cs_date,hv_approval_date.len);

	/* EXEC SQL DECLARE c_cursor_gettxndata CURSOR FOR
		select	oth_txn_id,
			oth_txn_code,
			oth_approval_date,
			otm_entity_Id,
			otm_party_type,
			otm_party_id,
			otm_txn_product,
			nvl(otd_txn_country,otm_txn_country) country,
			otd_txn_ccy,
			CASE WHEN nvl(nvl(oth_deposit_amount,oth_display_amount),oth_transaction_amount) <= 0
			     THEN oth_transaction_amount
			     ELSE nvl(nvl(oth_deposit_amount,oth_display_amount),oth_transaction_amount)
			     END  txn_amt,
			oth_net_ccy,
			oth_net_amount,
			nvl(t1_intr.ote_amount,0) intr_amt,
			nvl(t2_ovpa.ote_amount,0) ovpa_amt,
			nvl(t3_udpa.ote_amount,0) udpa_amt,
			nvl(t4_fee.ote_ccy,oth_net_ccy) fee_ccy,
			nvl(t4_fee.ote_amount,0) fee_amt
		from	ol_txn_header th,
			ol_txn_detail,
			ol_txn_mi_detail,
			(select	ote_txn_id,
				ote_ccy,
				ote_amount
			 from	ol_txn_elements 
			 where	ote_txn_element_type = 'INTR'
			 ) t1_intr,
			(select	ote_txn_id,
				ote_ccy,
				ote_amount
			 from	ol_txn_elements 
			 where	ote_txn_element_type = 'OVPA'
			 ) t2_ovpa,
			(select	ote_txn_id,
				ote_ccy,
				ote_amount
			 from	ol_txn_elements 
			 where	ote_txn_element_type = 'UDPA'
			 ) t3_udpa,
			(select	ote_txn_id,
				ote_ccy,
				ote_amount
			 from	ol_txn_elements 
			 where	ote_txn_element_type in ('TFEE','INCT')
			 ) t4_fee
		where	oth_txn_id = otd_txn_id(+)
		  and	oth_txn_id = otm_txn_id
		  and	oth_txn_id = t1_intr.ote_txn_id(+)
		  and	oth_txn_id = t2_ovpa.ote_txn_id(+)
		  and	oth_txn_id = t3_udpa.ote_txn_id(+)
		  and	oth_txn_id = t4_fee.ote_txn_id(+)
		  and	oth_approval_date = :hv_approval_date
		order by
			oth_txn_id desc; */ 

	/* EXEC SQL OPEN c_cursor_gettxndata; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "select oth_txn_id , oth_txn_code , oth_approval_date , otm_entity_Id , o\
tm_party_type , otm_party_id , otm_txn_product , nvl ( otd_txn_country , otm\
_txn_country ) country , otd_txn_ccy , CASE WHEN nvl ( nvl ( oth_deposit_amo\
unt , oth_display_amount ) , oth_transaction_amount ) <= 0 THEN oth_transact\
ion_amount ELSE nvl ( nvl ( oth_deposit_amount , oth_display_amount ) , oth_\
transaction_amount ) END txn_amt , oth_net_ccy , oth_net_amount , nvl ( t1_i\
ntr . ote_amount , 0 ) intr_amt , nvl ( t2_ovpa . ote_amount , 0 ) ovpa_amt \
, nvl ( t3_udpa . ote_amount , 0 ) udpa_amt , nvl ( t4_fee . ote_ccy , oth_n\
et_ccy ) fee_ccy , nvl ( t4_fee . ote_amount , 0 ) fee_amt from ol_txn_heade\
r th , ol_txn_detail , ol_txn_mi_detail , ( select ote_txn_id , ote_ccy , ot\
e_amount from ol_txn_elements where ote_txn_element_type = 'INTR' ) t1_intr \
, ( select ote_txn_id , ote_ccy , ote_amount from ol_txn_elements where ote_\
txn_element_type = 'OVPA' ) t2_ovpa , ( select ote_txn_id , ote_ccy , ote_am\
ount from ol_txn_elements where ote_txn_");
 sqlstm.stmt = sq0001;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_approval_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
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
		/* EXEC SQL FETCH c_cursor_gettxndata
		INTO	:v_txn_id:ind_txn_id,
			:v_txn_code:ind_txn_code,
			:v_approval_date:ind_approval_date,
			:v_entity_id:ind_entity_id,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_txn_product:ind_txn_product,
			:v_country:ind_country,
			:v_ccy:ind_ccy,
			:v_txn_amt:ind_txn_amt,
			:v_net_ccy:ind_net_ccy,
			:v_net_amt:ind_net_amt,
			:v_intr_amt:ind_intr_amt,
			:v_ovpa_amt:ind_ovpa_amt,
			:v_udpa_amt:ind_udpa_amt,
			:v_fee_ccy:ind_fee_ccy,
			:v_fee_amt:ind_fee_amt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
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
  sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_txn_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_code;
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_txn_code;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_approval_date;
  sqlstm.sqhstl[2] = (unsigned long )11;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_approval_date;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_entity_id;
  sqlstm.sqhstl[3] = (unsigned long )23;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_entity_id;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_party_type;
  sqlstm.sqhstl[4] = (unsigned long )6;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_party_type;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_party_id;
  sqlstm.sqhstl[5] = (unsigned long )23;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_party_id;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_txn_product;
  sqlstm.sqhstl[6] = (unsigned long )6;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_txn_product;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_country;
  sqlstm.sqhstl[7] = (unsigned long )5;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_country;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_ccy;
  sqlstm.sqhstl[8] = (unsigned long )6;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_ccy;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_txn_amt;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_txn_amt;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_net_ccy;
  sqlstm.sqhstl[10] = (unsigned long )6;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_net_ccy;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_net_amt;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_net_amt;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_intr_amt;
  sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_intr_amt;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_ovpa_amt;
  sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_ovpa_amt;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_udpa_amt;
  sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_udpa_amt;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_fee_ccy;
  sqlstm.sqhstl[15] = (unsigned long )6;
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_fee_ccy;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&v_fee_amt;
  sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)&ind_fee_amt;
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
  if (sqlca.sqlcode < 0) goto sql_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

/* Field #0 txn_id */
		if (ind_txn_id >= 0) {
			sprintf(csTmp,"%.*s",v_txn_id.len,v_txn_id.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #1 txn_code */
		if (ind_txn_code >= 0) {
			sprintf(csTmp,"%.*s",v_txn_code.len,v_txn_code.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #2 approval_date */
		if (ind_approval_date >= 0) {
			sprintf(csTmp,"%.*s",v_approval_date.len,v_approval_date.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #3 entity_id */
		if (ind_entity_id >= 0) {
			sprintf(csTmp,"%.*s",v_entity_id.len,v_entity_id.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #4 party_type */
		if (ind_party_type >= 0) {
			sprintf(csTmp,"%.*s",v_party_type.len,v_party_type.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #5 party_id */
		if (ind_party_id >= 0) {
			sprintf(csTmp,"%.*s",v_party_id.len,v_party_id.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #6 txn_product */
		if (ind_txn_product >= 0) {
			sprintf(csTmp,"%.*s",v_txn_product.len,v_txn_product.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #7 country */
		if (ind_country >= 0) {
			sprintf(csTmp,"%.*s",v_country.len,v_country.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #8 ccy */
		if (ind_ccy >= 0) {
			sprintf(csTmp,"%.*s",v_ccy.len,v_ccy.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #9 txn_amt */
		if (ind_txn_amt >= 0) {
			fprintf(fp,"%.2f%c",v_txn_amt,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #10 net_ccy */
		if (ind_net_ccy >= 0) {
			sprintf(csTmp,"%.*s",v_net_ccy.len,v_net_ccy.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #11 net_amt */
		if (ind_net_amt >= 0) {
			fprintf(fp,"%.2f%c",v_net_amt,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #12 intr_amt */
		if (ind_intr_amt >= 0) {
			fprintf(fp,"%.2f%c",v_intr_amt,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #13 ovpa_amt */
		if (ind_ovpa_amt >= 0) {
			fprintf(fp,"%.2f%c",v_ovpa_amt,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #14 udpa_amt */
		if (ind_udpa_amt >= 0) {
			fprintf(fp,"%.2f%c",v_udpa_amt,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #15 fee_ccy */
		if (ind_fee_ccy >= 0) {
			sprintf(csTmp,"%.*s",v_fee_ccy.len,v_fee_ccy.arr);
			fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* Field #16 fee_amt */
		if (ind_fee_amt >= 0) {
			fprintf(fp,"%.2f%c",v_fee_amt,PD_MY_DELIMITOR);
		} else
			fprintf(fp,"%c",PD_MY_DELIMITOR);

/* new line */
		fprintf(fp,"\n");

 	} while (PD_TRUE);
	/* EXEC SQL CLOSE c_cursor_gettxndata; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )107;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto sql_error;
}



        return iRet;

sql_error:
DEBUGLOG(("extract_crr_ofl_txn_data error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_gettxndata; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )122;
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
    sqlstm.offset = (unsigned int  )137;
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

        while ((c = getopt(argc,argv,"d:")) != EOF) {
                switch (c) {
                        case 'd':
                                strcpy(cs_date, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_date,""))
                return FAILURE;

        return SUCCESS;
}

