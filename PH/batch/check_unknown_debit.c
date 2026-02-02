
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
    "check_unknown_debit.pc"
};


static unsigned int sqlctx = 291132235;


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
   unsigned char  *sqhstv[4];
   unsigned long  sqhstl[4];
            int   sqhsts[4];
            short *sqindv[4];
            int   sqinds[4];
   unsigned long  sqharm[4];
   unsigned long  *sqharc[4];
   unsigned short  sqadto[4];
   unsigned short  sqtdso[4];
} sqlstm = {12,4};

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
"select bank_name , sp_mask_owner_name ( OB_INT_BANK_CODE , OB_OWNER_NAME ) \
, sp_mask_bank_acct_num ( OB_INT_BANK_CODE , OB_BANK_ACCT_NUM ) , obt_txn_amt\
 from bank_desc , ol_bank_accts , ol_bank_acct_id , ol_statement_detail , ol_\
baid_txn where obt_create_timestamp > sysdate - :b0 / 24 and obt_txn_code in \
( 'UBD' , 'USO' ) and obt_status = 'C' and obt_ar_ind = 'A' and mod ( obt_txn\
_amt , 1 ) = 0 and obt_txn_amt >= 100 and obt_baid = obai_baid and olsd_stat_\
txn_id = obt_stat_txn_id and internal_bank_code = obai_int_bank_code and olsd\
_int_bank_code = ob_int_bank_code and olsd_bank_acct_num = ob_bank_acct_num a\
nd exists ( select 1 from ol_psp_detail where opd_psp_id = obai_psp_id and op\
d_bank_acct_type = 'DSI' ) order by bank_name , ob_owner_name            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,764,0,9,133,0,2049,1,1,0,1,0,1,3,0,0,
24,0,0,1,0,0,13,135,0,0,4,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,
55,0,0,1,0,0,15,180,0,0,0,0,0,1,0,
70,0,0,1,0,0,15,189,0,0,0,0,0,1,0,
85,0,0,2,0,0,32,190,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/08/27              Virginia Yun
Add mask_bank_acct_num into process_txn		   2019/05/02		   Michael Chow
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


#define PD_OPEN_TAG             "<tr><td>"
#define PD_NEXT_TAG             "</td><td>"
#define PD_END_TAG              "</td></tr>"

OBJPTR(DB);
char    cDebug = 'Y';

char    cs_time[PD_DESC_LEN + 1];


int parse_arg(int argc, char **argv);
int process_txn();


int	iTitle = 0;


int batch_init(int argc, char* argv[])
{
        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
        int     iRet = SUCCESS;

	iRet = parse_arg(argc, argv);

	if (iRet != SUCCESS) {
		printf("usage: -t <check_timediff(in hour)>\n");
		return iRet;
	}

	iRet = process_txn();


	return iRet;


}

int process_txn()
{
	int	iRet = SUCCESS;
	int	iCnt = 0;

	int	iTimeDiff = 0;

	if(sscanf(cs_time, "%d", &iTimeDiff) == 1) {
DEBUGLOG(("check_unknown_debit:: TimeDiff [%d]\n", iTimeDiff));
	} else {
		iRet = FAILURE;
		return iRet;
	}

	/* EXEC SQL WHENEVER SQLERROR GOTO chkunknowndr_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                int     hv_time_diff;

                /* varchar v_bank_name[PD_BANK_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

                /* varchar v_owner_name[PD_OWNER_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_owner_name;

		/* varchar v_mask_bank_acct_num[PD_BANK_ACCT_NUM_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_mask_bank_acct_num;
			//mic
		double  v_deposit_amt;

		short	ind_bank_name = -1;
		short	ind_owner_name = -1;
		short   ind_mask_bank_acct_num = -1;					//mic
		short	ind_deposit_amt;

        /* EXEC SQL END DECLARE SECTION; */ 



	hv_time_diff = iTimeDiff;

        /* EXEC SQL DECLARE c_unknown_debit CURSOR FOR
		//mic select bank_name, ob_owner_name, obt_txn_amt
 		select bank_name,							//mic
		sp_mask_owner_name(OB_INT_BANK_CODE,OB_OWNER_NAME), 			//mic
		sp_mask_bank_acct_num(OB_INT_BANK_CODE,OB_BANK_ACCT_NUM), 		//mic
		obt_txn_amt								//mic 
		from bank_desc,ol_bank_accts,  ol_bank_acct_id, ol_statement_detail, ol_baid_txn
		where obt_create_timestamp > sysdate - :hv_time_diff / 24
		and obt_txn_code in ('UBD', 'USO')
		and obt_status = 'C'
		and obt_ar_ind = 'A'
		and mod(obt_txn_amt, 1) = 0
		and obt_txn_amt >= 100
		and obt_baid = obai_baid
		and olsd_stat_txn_id = obt_stat_txn_id
		and internal_bank_code = obai_int_bank_code
		and olsd_int_bank_code = ob_int_bank_code
		and olsd_bank_acct_num = ob_bank_acct_num
		and exists (select 1
				from ol_psp_detail
				where opd_psp_id = obai_psp_id
				and opd_bank_acct_type = 'DSI'
				)
		order by bank_name, ob_owner_name; */ 


        /* EXEC SQL OPEN c_unknown_debit; */ 

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
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_time_diff;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode < 0) goto chkunknowndr_error;
}


        for (;;) {
                /* EXEC SQL FETCH c_unknown_debit 
                INTO
                        :v_bank_name:ind_bank_name,
                        :v_owner_name:ind_owner_name,
			:v_mask_bank_acct_num:ind_mask_bank_acct_num,			//mic
                        :v_deposit_amt:ind_deposit_amt; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 4;
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
                sqlstm.sqhstv[0] = (unsigned char  *)&v_bank_name;
                sqlstm.sqhstl[0] = (unsigned long )153;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_bank_name;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_owner_name;
                sqlstm.sqhstl[1] = (unsigned long )53;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_owner_name;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_mask_bank_acct_num;
                sqlstm.sqhstl[2] = (unsigned long )53;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_mask_bank_acct_num;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_deposit_amt;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_deposit_amt;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto chkunknowndr_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                iCnt++;


printf("%s",PD_OPEN_TAG);

                if (ind_bank_name>= 0) {
                        v_bank_name.arr[v_bank_name.len]='\0';
printf("%s",(char*)v_bank_name.arr);
DEBUGLOG(("check_unknown_debit() [%d] bank_name= [%s]\n", iCnt, v_bank_name.arr));
                }

printf("%s",PD_NEXT_TAG);

                if (ind_owner_name>= 0) {
                        v_owner_name.arr[v_owner_name.len]='\0';
printf("%s",(char*)v_owner_name.arr);
DEBUGLOG(("check_unknown_debit() [%d] owner_name = [%s]\n", iCnt, v_owner_name.arr));
                }
//mic
printf("%s",PD_NEXT_TAG);
                if (ind_mask_bank_acct_num>= 0) {
                        v_mask_bank_acct_num.arr[v_mask_bank_acct_num.len]='\0';
printf("%s",(char*)v_mask_bank_acct_num.arr);
DEBUGLOG(("check_unknown_debit() [%d] mask_bank_acct_num = [%s]\n", iCnt, v_mask_bank_acct_num.arr));
                }
//mic
printf("%s",PD_NEXT_TAG);

                if (ind_deposit_amt>= 0) {
printf("%.2lf", v_deposit_amt);
DEBUGLOG(("check_unknown_debit() [%d] deposit_amt = [%.2lf]\n", iCnt, v_deposit_amt));
                }
printf("%s\n", PD_END_TAG);
	}
        /* EXEC SQL CLOSE c_unknown_debit; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )55;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto chkunknowndr_error;
}



DEBUGLOG(("check_unknown_debit() iRet = [%d]\n",iRet));
        return iRet;

chkunknowndr_error:
DEBUGLOG(("check_unknown_debit error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_unknown_debit; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )70;
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
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )85;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}



int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

int parse_arg(int argc, char **argv)
{
        char    c;

        while ((c = getopt(argc, argv, "t:")) != EOF) {
                switch (c) {
                        case 't':
                                strcpy(cs_time, optarg);
                                cs_time[strlen(cs_time)] = '\0';
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_time, ""))
                return FAILURE;


        return SUCCESS;
}
