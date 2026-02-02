
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
           char  filnam[19];
};
static struct sqlcxp sqlfpn =
{
    18,
    "par_txn_handler.pc"
};


static unsigned int sqlctx = 20367099;


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
   unsigned char  *sqhstv[21];
   unsigned long  sqhstl[21];
            int   sqhsts[21];
            short *sqindv[21];
            int   sqinds[21];
   unsigned long  sqharm[21];
   unsigned long  *sqharc[21];
   unsigned short  sqadto[21];
   unsigned short  sqtdso[21];
} sqlstm = {12,21};

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
5,0,0,0,0,0,56,176,0,0,1,1,0,1,0,3,102,0,0,
24,0,0,1,72,0,6,178,0,0,2,2,0,1,0,2,3,0,0,2,102,0,0,
47,0,0,0,0,0,13,215,0,0,21,1,0,1,0,1,102,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
146,0,0,0,0,0,15,368,0,0,1,1,0,1,0,1,102,0,0,
165,0,0,0,0,0,15,372,0,0,1,1,0,1,0,1,102,0,0,
184,0,0,0,0,0,15,378,0,0,1,1,0,1,0,1,102,0,0,
203,0,0,0,0,0,15,390,0,0,1,1,0,1,0,1,102,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/06/08              Virginia Yun
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
#include "par_txn_handler.h"
#include "ObjPtr.h"
#include "dbutility.h"


#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define	PD_MY_DELIMITOR	","
#define	PD_MY_TOKEN	'"'

/*
#define	PD_MY_QS_TOEKN	'	'
#define	PD_MY_QE_TOEKN	'	'
#define	PD_MY_DAY_TOKEN	"-"
*/

#define	PD_CHAR		0x0D

OBJPTR(DB);
OBJPTR(Txn);
OBJPTR(Channel);
OBJPTR(BO);

char    cDebug='Y';


char    cs_inputfile[PD_MAX_FILE_LEN + 1];

int parse_arg(int argc,char **argv);
int start_process();
int parse_txn(hash_t *hMyHash);

int deposit_handler(hash_t *hMyHash);
int settlement_handler(hash_t *hMyHash);
int adjustment_handler(hash_t *hMyHash);
int payout_handler(hash_t *hMyHash);
int payout_reversal_handler(hash_t *hMyHash);
int format_data(hash_t *hMyHash, hash_t *hTxnHeader, hash_t *hContext, hash_t *hRequest);
int handle_deposit_balance(hash_t *hMyHash);


int batch_init(int argc, char* argv[])
{
        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int	iRet;

	iRet = start_process();

	return iRet;

}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


                        
int parse_arg(int argc,char **argv)
{               
        char    c;
        strcpy(cs_inputfile,"");
                        
        while ((c = getopt(argc,argv,"f:")) != EOF) {
                switch (c) {
                        case 'f':
                                strcpy(cs_inputfile, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }       
        
//DEBUGLOG(("[%s]\n",cs_inputfile));
        if (!strcmp(cs_inputfile,""))
                return FAILURE;
                
        return SUCCESS; 
}               


int start_process() 
{
	int	iRet = SUCCESS;

	
	int	iCnt;
	hash_t	*myHash;

	myHash = (hash_t*) malloc (sizeof(hash_t));


        /* EXEC SQL WHENEVER SQLERROR GOTO get_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                SQL_CURSOR      c_cursor_txn_data;

		short		hv_return_value;

		int		v_txn_seq;
		/* varchar		v_txn_date[PD_DATE_LEN + PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_txn_date;

		/* varchar		v_txn_merch_nmb[PAR_TXN_MERCH_NMB_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_merch_nmb;

		/* varchar		v_txn_nmb[PAR_TXN_NMB_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_nmb;

		/* varchar		v_merch_ref[PD_MERCHANT_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merch_ref;

		/* varchar		v_txn_type[PAR_TXN_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_type;

		/* varchar		v_txn_status[PAR_TXN_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_status;

		/* varchar		v_txn_status_grp[PAR_TXN_STATUS_GRP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_status_grp;

		/* varchar		v_to_ccy[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_to_ccy;

		double		v_to_amount;
		/* varchar		v_ccy[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ccy;

		double		v_amount;
		double		v_fee;
		double		v_ex_rate;
		double		v_markup_amt;
		double		v_balance;
		/* varchar		v_psp_type_code[PAR_PSP_TYPE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_type_code;

		/* varchar		v_psp_order_id[PAR_PSP_TYPE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_order_id;

		/* varchar		v_gate_id[PAR_GATE_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_gate_id;

		/* varchar		v_client_ip[PAR_CLIENT_IP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_client_ip;


		short		ind_txn_seq = -1;
		short		ind_txn_date = -1;
		short		ind_txn_merch_nmb = -1;
		short		ind_txn_nmb = -1;
		short		ind_merch_ref = -1;
		short		ind_txn_type = -1;
		short		ind_txn_status = -1;
		short		ind_txn_status_grp = -1;
		short		ind_to_ccy = -1;
		short		ind_to_amount = -1;
		short		ind_ccy = -1;
		short		ind_amount = -1;
		short		ind_fee = -1;
		short		ind_ex_rate = -1;
		short		ind_markup_amt = -1;
		short		ind_balance = -1;
		short		ind_psp_type_code = -1;
		short		ind_psp_order_id = -1;
		short		ind_gate_id = -1;
		short		ind_client_ip = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	/* EXEC SQL ALLOCATE :c_cursor_txn_data; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_txn_data;
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
 if (sqlca.sqlcode < 0) goto get_error;
}



	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_par_txn_data(:c_cursor_txn_data);	
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_par_txn_data ( :c_cursor_txn_d\
ata ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )24;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&c_cursor_txn_data;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto get_error;
}



	if (hv_return_value == 1) {
DEBUGLOG(("start_process:get_txn no more record to be processed!\n"));
	}
	else if (hv_return_value == SP_OK) {
		iCnt = 0;

                for (;;) {
			hash_init(myHash,0);

			ind_txn_seq = -1;
			ind_txn_date = -1;
			ind_txn_merch_nmb = -1;
			ind_txn_nmb = -1;
			ind_merch_ref = -1;
			ind_txn_type = -1;
			ind_txn_status = -1;
			ind_txn_status_grp = -1;
			ind_to_ccy = -1;
			ind_to_amount = -1;
			ind_ccy = -1;
			ind_amount = -1;
			ind_fee = -1;
			ind_ex_rate = -1;
			ind_markup_amt = -1;
			ind_balance = -1;
			ind_psp_type_code = -1;
			ind_psp_order_id = -1;
			ind_gate_id = -1;
			ind_client_ip = -1;
	
			/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_txn_data		
			INTO	:v_txn_seq:ind_txn_seq,
				:v_txn_date:ind_txn_date,
				:v_txn_merch_nmb:ind_txn_merch_nmb,
		  		:v_txn_nmb:ind_txn_nmb,
				:v_merch_ref:ind_merch_ref,
				:v_txn_type:ind_txn_type,
				:v_txn_status:ind_txn_status,
				:v_txn_status_grp:ind_txn_status_grp,
				:v_to_ccy:ind_to_ccy,
				:v_to_amount:ind_to_amount,
				:v_ccy:ind_ccy,
				:v_amount:ind_amount,
				:v_fee:ind_fee,
				:v_ex_rate:ind_ex_rate,
				:v_markup_amt:ind_markup_amt,
				:v_balance:ind_balance,
				:v_psp_type_code:ind_psp_type_code,
				:v_psp_order_id:ind_psp_order_id,
				:v_gate_id:ind_gate_id,
				:v_client_ip:ind_client_ip; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 21;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )47;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_txn_data;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_seq;
                        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_txn_seq;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_date;
                        sqlstm.sqhstl[2] = (unsigned long )17;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_txn_date;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_merch_nmb;
                        sqlstm.sqhstl[3] = (unsigned long )53;
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_txn_merch_nmb;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_txn_nmb;
                        sqlstm.sqhstl[4] = (unsigned long )19;
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_txn_nmb;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_merch_ref;
                        sqlstm.sqhstl[5] = (unsigned long )53;
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_merch_ref;
                        sqlstm.sqinds[5] = (         int  )0;
                        sqlstm.sqharm[5] = (unsigned long )0;
                        sqlstm.sqadto[5] = (unsigned short )0;
                        sqlstm.sqtdso[5] = (unsigned short )0;
                        sqlstm.sqhstv[6] = (unsigned char  *)&v_txn_type;
                        sqlstm.sqhstl[6] = (unsigned long )53;
                        sqlstm.sqhsts[6] = (         int  )0;
                        sqlstm.sqindv[6] = (         short *)&ind_txn_type;
                        sqlstm.sqinds[6] = (         int  )0;
                        sqlstm.sqharm[6] = (unsigned long )0;
                        sqlstm.sqadto[6] = (unsigned short )0;
                        sqlstm.sqtdso[6] = (unsigned short )0;
                        sqlstm.sqhstv[7] = (unsigned char  *)&v_txn_status;
                        sqlstm.sqhstl[7] = (unsigned long )53;
                        sqlstm.sqhsts[7] = (         int  )0;
                        sqlstm.sqindv[7] = (         short *)&ind_txn_status;
                        sqlstm.sqinds[7] = (         int  )0;
                        sqlstm.sqharm[7] = (unsigned long )0;
                        sqlstm.sqadto[7] = (unsigned short )0;
                        sqlstm.sqtdso[7] = (unsigned short )0;
                        sqlstm.sqhstv[8] = (unsigned char  *)&v_txn_status_grp;
                        sqlstm.sqhstl[8] = (unsigned long )53;
                        sqlstm.sqhsts[8] = (         int  )0;
                        sqlstm.sqindv[8] = (         short *)&ind_txn_status_grp;
                        sqlstm.sqinds[8] = (         int  )0;
                        sqlstm.sqharm[8] = (unsigned long )0;
                        sqlstm.sqadto[8] = (unsigned short )0;
                        sqlstm.sqtdso[8] = (unsigned short )0;
                        sqlstm.sqhstv[9] = (unsigned char  *)&v_to_ccy;
                        sqlstm.sqhstl[9] = (unsigned long )6;
                        sqlstm.sqhsts[9] = (         int  )0;
                        sqlstm.sqindv[9] = (         short *)&ind_to_ccy;
                        sqlstm.sqinds[9] = (         int  )0;
                        sqlstm.sqharm[9] = (unsigned long )0;
                        sqlstm.sqadto[9] = (unsigned short )0;
                        sqlstm.sqtdso[9] = (unsigned short )0;
                        sqlstm.sqhstv[10] = (unsigned char  *)&v_to_amount;
                        sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[10] = (         int  )0;
                        sqlstm.sqindv[10] = (         short *)&ind_to_amount;
                        sqlstm.sqinds[10] = (         int  )0;
                        sqlstm.sqharm[10] = (unsigned long )0;
                        sqlstm.sqadto[10] = (unsigned short )0;
                        sqlstm.sqtdso[10] = (unsigned short )0;
                        sqlstm.sqhstv[11] = (unsigned char  *)&v_ccy;
                        sqlstm.sqhstl[11] = (unsigned long )6;
                        sqlstm.sqhsts[11] = (         int  )0;
                        sqlstm.sqindv[11] = (         short *)&ind_ccy;
                        sqlstm.sqinds[11] = (         int  )0;
                        sqlstm.sqharm[11] = (unsigned long )0;
                        sqlstm.sqadto[11] = (unsigned short )0;
                        sqlstm.sqtdso[11] = (unsigned short )0;
                        sqlstm.sqhstv[12] = (unsigned char  *)&v_amount;
                        sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[12] = (         int  )0;
                        sqlstm.sqindv[12] = (         short *)&ind_amount;
                        sqlstm.sqinds[12] = (         int  )0;
                        sqlstm.sqharm[12] = (unsigned long )0;
                        sqlstm.sqadto[12] = (unsigned short )0;
                        sqlstm.sqtdso[12] = (unsigned short )0;
                        sqlstm.sqhstv[13] = (unsigned char  *)&v_fee;
                        sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[13] = (         int  )0;
                        sqlstm.sqindv[13] = (         short *)&ind_fee;
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
                        sqlstm.sqhstv[15] = (unsigned char  *)&v_markup_amt;
                        sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[15] = (         int  )0;
                        sqlstm.sqindv[15] = (         short *)&ind_markup_amt;
                        sqlstm.sqinds[15] = (         int  )0;
                        sqlstm.sqharm[15] = (unsigned long )0;
                        sqlstm.sqadto[15] = (unsigned short )0;
                        sqlstm.sqtdso[15] = (unsigned short )0;
                        sqlstm.sqhstv[16] = (unsigned char  *)&v_balance;
                        sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[16] = (         int  )0;
                        sqlstm.sqindv[16] = (         short *)&ind_balance;
                        sqlstm.sqinds[16] = (         int  )0;
                        sqlstm.sqharm[16] = (unsigned long )0;
                        sqlstm.sqadto[16] = (unsigned short )0;
                        sqlstm.sqtdso[16] = (unsigned short )0;
                        sqlstm.sqhstv[17] = (unsigned char  *)&v_psp_type_code;
                        sqlstm.sqhstl[17] = (unsigned long )53;
                        sqlstm.sqhsts[17] = (         int  )0;
                        sqlstm.sqindv[17] = (         short *)&ind_psp_type_code;
                        sqlstm.sqinds[17] = (         int  )0;
                        sqlstm.sqharm[17] = (unsigned long )0;
                        sqlstm.sqadto[17] = (unsigned short )0;
                        sqlstm.sqtdso[17] = (unsigned short )0;
                        sqlstm.sqhstv[18] = (unsigned char  *)&v_psp_order_id;
                        sqlstm.sqhstl[18] = (unsigned long )53;
                        sqlstm.sqhsts[18] = (         int  )0;
                        sqlstm.sqindv[18] = (         short *)&ind_psp_order_id;
                        sqlstm.sqinds[18] = (         int  )0;
                        sqlstm.sqharm[18] = (unsigned long )0;
                        sqlstm.sqadto[18] = (unsigned short )0;
                        sqlstm.sqtdso[18] = (unsigned short )0;
                        sqlstm.sqhstv[19] = (unsigned char  *)&v_gate_id;
                        sqlstm.sqhstl[19] = (unsigned long )53;
                        sqlstm.sqhsts[19] = (         int  )0;
                        sqlstm.sqindv[19] = (         short *)&ind_gate_id;
                        sqlstm.sqinds[19] = (         int  )0;
                        sqlstm.sqharm[19] = (unsigned long )0;
                        sqlstm.sqadto[19] = (unsigned short )0;
                        sqlstm.sqtdso[19] = (unsigned short )0;
                        sqlstm.sqhstv[20] = (unsigned char  *)&v_client_ip;
                        sqlstm.sqhstl[20] = (unsigned long )18;
                        sqlstm.sqhsts[20] = (         int  )0;
                        sqlstm.sqindv[20] = (         short *)&ind_client_ip;
                        sqlstm.sqinds[20] = (         int  )0;
                        sqlstm.sqharm[20] = (unsigned long )0;
                        sqlstm.sqadto[20] = (unsigned short )0;
                        sqlstm.sqtdso[20] = (unsigned short )0;
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
                        if (sqlca.sqlcode < 0) goto get_error;
}



                        if (SQLCODE == SQL_NOT_FOUND) {
                                break;
                        }

DEBUGLOG(("start_process >>>>>>>>>>>>>>>>>>>>>>>>>\n"));

			if (ind_txn_seq >= 0) {
DEBUGLOG(("start_process: [%d] sort_txn_seq = [%d]\n", iCnt, v_txn_seq));
				PutField_Int(myHash, "sort_txn_seq", v_txn_seq);
			}
			

			if (ind_txn_date >= 0) {
				v_txn_date.arr[v_txn_date.len] = '\0';
DEBUGLOG(("start_process: [%d] txn_date = [%.*s]\n",iCnt, v_txn_date.len,v_txn_date.arr));
				PutField_CString(myHash, "txn_date", (const char *) v_txn_date.arr);
			}

			if (ind_txn_merch_nmb >= 0) {
				v_txn_merch_nmb.arr[v_txn_merch_nmb.len] = '\0';
DEBUGLOG(("start_process: [%d] txn_merch_nmb = [%.*s]\n",iCnt, v_txn_merch_nmb.len,v_txn_merch_nmb.arr));
				PutField_CString(myHash, "txn_merch_nmb", (const char *) v_txn_merch_nmb.arr);
			}

			if (ind_txn_nmb >= 0) {
				v_txn_nmb.arr[v_txn_nmb.len] = '\0';
DEBUGLOG(("start_process: [%d] txn_nmb = [%.*s]\n",iCnt, v_txn_nmb.len,v_txn_nmb.arr));
				PutField_CString(myHash, "txn_nmb", (const char *) v_txn_nmb.arr);
			}

			if (ind_merch_ref >=0) {
				v_merch_ref.arr[v_merch_ref.len] = '\0';
DEBUGLOG(("start_process: [%d] merch_ref = [%.*s]\n",iCnt, v_merch_ref.len, v_merch_ref.arr));
				PutField_CString(myHash, "merch_ref", (const char *) v_merch_ref.arr);
			}
		
			if (ind_txn_type >=0) {
				v_txn_type.arr[v_txn_type.len] = '\0';
DEBUGLOG(("start_process: [%d] txn_type = [%.*s]\n",iCnt, v_txn_type.len, v_txn_type.arr));
				PutField_CString(myHash, "txn_type", (const char *) v_txn_type.arr);
			}

			if (ind_txn_status >=0) {
				v_txn_status.arr[v_txn_status.len] = '\0';
DEBUGLOG(("start_process: [%d] txn_status = [%.*s]\n",iCnt, v_txn_status.len, v_txn_status.arr));
				PutField_CString(myHash, "txn_status", (const char *) v_txn_status.arr);
			}

			if (ind_txn_status_grp >=0) {
				v_txn_status_grp.arr[v_txn_status_grp.len] = '\0';
DEBUGLOG(("start_process: [%d] txn_status_grp = [%.*s]\n",iCnt, v_txn_status_grp.len, v_txn_status_grp.arr));
				PutField_CString(myHash, "txn_status_grp", (const char *) v_txn_status_grp.arr);
			}

			if (ind_to_ccy >=0) {
				v_to_ccy.arr[v_to_ccy.len] = '\0';
DEBUGLOG(("start_process: [%d] to_ccy = [%.*s]\n",iCnt, v_to_ccy.len, v_to_ccy.arr));
				PutField_CString(myHash, "to_ccy", (const char *) v_to_ccy.arr);
			}

			if (ind_to_amount >=0) {
DEBUGLOG(("start_process: [%d] to_amount = [%lf]\n",iCnt, v_to_amount));
				PutField_Double(myHash, "to_amount", v_to_amount);
			}

			if (ind_ccy >=0) {
				v_ccy.arr[v_ccy.len] = '\0';
DEBUGLOG(("start_process: [%d] ccy = [%.*s]\n",iCnt, v_ccy.len, v_ccy.arr));
				PutField_CString(myHash, "ccy", (const char *) v_ccy.arr);
			}

			if (ind_amount >=0) {
DEBUGLOG(("start_process: [%d] amount = [%lf]\n",iCnt, v_amount));
				PutField_Double(myHash, "amount", v_amount);
			}

			if (ind_fee >=0) {
DEBUGLOG(("start_process: [%d] fee = [%lf]\n",iCnt, v_fee));
				PutField_Double(myHash, "fee", v_fee);
			}

			if (ind_ex_rate >= 0) {
DEBUGLOG(("start_process: [%d] ex_rate = [%lf]\n",iCnt, v_ex_rate));
				PutField_Double(myHash, "ex_rate", v_ex_rate);
			}

			if (ind_markup_amt >= 0) {
DEBUGLOG(("start_process: [%d] markup_amt = [%lf]\n",iCnt, v_markup_amt));
				PutField_Double(myHash, "markup_amt", v_markup_amt);
			}

			if (ind_balance >= 0) {
DEBUGLOG(("start_process: [%d] balance = [%lf]\n",iCnt, v_balance));
				PutField_Double(myHash, "balance", v_balance);
			}

			if (ind_psp_type_code >= 0) {
				v_psp_type_code.arr[v_psp_type_code.len] = '\0';
DEBUGLOG(("start_process: [%d] psp_type_code = [%.*s]\n",iCnt, v_psp_type_code.len, v_psp_type_code.arr));
				PutField_CString(myHash, "psp_type_code", (const char *) v_psp_type_code.arr);
			}
		
			if (ind_psp_order_id >= 0) {
				v_psp_order_id.arr[v_psp_order_id.len] = '\0';
DEBUGLOG(("start_process: [%d] psp_order_id = [%.*s]\n",iCnt, v_psp_order_id.len, v_psp_order_id.arr));
				PutField_CString(myHash, "psp_order_id", (const char *) v_psp_order_id.arr);
			}

			if (ind_gate_id >= 0) {
				v_gate_id.arr[v_gate_id.len] = '\0';
DEBUGLOG(("start_process: [%d] gate_id = [%.*s]\n",iCnt, v_gate_id.len, v_gate_id.arr));
				PutField_CString(myHash, "gate_id", (const char *) v_gate_id.arr);
			}
			
			if (ind_client_ip >= 0) {
				v_client_ip.arr[v_client_ip.len] = '\0';
DEBUGLOG(("start_process: [%d] client_ip = [%.*s]\n",iCnt, v_client_ip.len, v_client_ip.arr));
				PutField_CString(myHash, "client_ip", (const char *) v_client_ip.arr);
			}	


			iRet=parse_txn(myHash);
			if (iRet != SUCCESS) {
				break;
			}

			iCnt++;

			hash_destroy(myHash);
	
		}
		/* EXEC SQL CLOSE :c_cursor_txn_data; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )146;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_txn_data;
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
  if (sqlca.sqlcode < 0) goto get_error;
}




	} else if (hv_return_value == SP_OTHER_ERR) {
		/* EXEC SQL CLOSE :c_cursor_txn_data; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 21;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )165;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_txn_data;
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
  if (sqlca.sqlcode < 0) goto get_error;
}


DEBUGLOG(("start_process: exit with error\n"));
                iRet = FAILURE;
	
	}
	
	/* EXEC SQL CLOSE :c_cursor_txn_data; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 21;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )184;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_txn_data;
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
 if (sqlca.sqlcode < 0) goto get_error;
}


DEBUGLOG(("start_process: RET = [%d]\n", iRet));

	FREE_ME(myHash);


	return iRet;

get_error:
DEBUGLOG(("get_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE :c_cursor_txn_data; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 21;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )203;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_txn_data;
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
}


    FREE_ME(myHash);

    return PD_ERR;
}


int parse_txn (hash_t *hMyHash) {

	int 	iRet=SUCCESS;

	char	*csTmp;
	char	*csPreTxnType = NULL;
	char	*csCategory = NULL; 

	time_t	ct;
	struct	tm *sct;

	char	sys_date[PD_DATE_LEN + 1];
	char	sys_time[PD_TIME_LEN + 1];

	char	csTranDateTime[PD_DATE_LEN + PD_TIME_LEN + 1];	

	char	csPostDate[PD_SP_VALUE_LEN + 1];

DEBUGLOG(("parse_txn: BEGIN\n"));


        ct = time((time_t *) 0);
        sct = localtime(&ct);

        memset(sys_date, 0, sizeof(sys_date));
        memset(sys_time, 0, sizeof(sys_time));
        memset(csTranDateTime, 0, sizeof(csTranDateTime));

        sprintf(sys_date, "%04d%02d%02d",
                sct->tm_year + 1900, sct->tm_mon + 1, sct->tm_mday);

        sprintf(sys_time, "%02d%02d%02d",
                sct->tm_hour, sct->tm_min, sct->tm_sec);

DEBUGLOG(("parse_txn: sys_date [%s] sys_time [%s]\n", sys_date, sys_time));

        PutField_CString(hMyHash, "local_tm_date", sys_date);
        PutField_CString(hMyHash, "local_tm_time", sys_time);
	

//DEBUGLOG(("parse_txn: Get Post Date\n"));
	memset(csPostDate, 0, sizeof(csPostDate));

	DBObjPtr = CreateObj(DBPtr,"DBParDefMisc","GetValue");
	if (((unsigned long)(*DBObjPtr)(PAR_POST_DATE_CODE, &csPostDate)) == FOUND) {
DEBUGLOG(("parse_txn: Post Date [%s]\n", csPostDate));
		PutField_CString(hMyHash, "post_date", csPostDate);
	} else {
DEBUGLOG(("parse_txn: ParDefMisc:GetValue FAIL!!\n"));
		iRet = FAILURE;
	}


	if (iRet == SUCCESS) {
		if (GetField_CString(hMyHash, "txn_type", &csPreTxnType)) {
DEBUGLOG(("parse_txn: txn_type [%s]\n", csPreTxnType));

			DBObjPtr = CreateObj(DBPtr,"DBParCategory","GetCategory");
			if (((unsigned long)(*DBObjPtr)(csPreTxnType, hMyHash)) == PD_OK) {

				if (GetField_CString(hMyHash, "category", &csCategory)) {
DEBUGLOG(("parse_txn: category [%s]\n", csCategory));
				}
				if (GetField_CString(hMyHash, "txn_code", &csTmp)) {
DEBUGLOG(("parse_txn: txn_code [%s]\n", csTmp));
				}
				if (GetField_CString(hMyHash, "reversal_txn_code", &csTmp)) {
DEBUGLOG(("parse_txn: reversal_txn_code [%s]\n", csTmp));
				}
			}
			else {
DEBUGLOG(("parse_txn: ParCategory:GetCategory FAIL!\n"));
				iRet = FAILURE;
			}
		} 
		else {
DEBUGLOG(("parse_txn: txn_type is missing!\n"));
			iRet = FAILURE;
		}
	}
	
	if (iRet == SUCCESS) {
		if (!strcmp(csCategory, PAR_CAT_DEPOSIT)) {
			iRet = deposit_handler(hMyHash);
		} else if (!strcmp(csCategory, PAR_CAT_SETTLEMENT)) {
			iRet = settlement_handler(hMyHash);
		} else if (!strcmp(csCategory, PAR_CAT_ADJUSTEMENT)) {
			iRet = adjustment_handler(hMyHash);
		} else if (!strcmp(csCategory, PAR_CAT_PAYOUT)) {
			iRet = payout_handler(hMyHash);
		} else if (!strcmp(csCategory, PAR_CAT_PAYOUT_REVERSAL)) {
			iRet = payout_reversal_handler(hMyHash);
		} else {
DEBUGLOG(("parse_txn: not defined category [%s]\n", csCategory));
			iRet = FAILURE;
		}


		if (iRet == SUCCESS) {
			TxnCommit();
		}
		else {
			TxnAbort();
		}
	}

	return iRet;
}

int deposit_handler(hash_t *hMyHash)
{
	int iRet = SUCCESS;
	int iTmpRet;

	hash_t		*hTxnHeader;

	recordset_t	*rRecordSet;
	hash_t		*hRec;

	char	*csTmp = NULL;
	double	dTmp = 0.0;
	int	iTmp = 0;

	char	*csMerchNmb = NULL;
	char	*csVNCRefNum = NULL;
	char	csCountry [PD_COUNTRY_LEN + 1]; 
	char	*csService = NULL;

	char	*csPspID = NULL;	
	char	*csPspTypeCode = NULL;
	char	*csGateID = NULL;

	char	*csTxnStatus = NULL;

	int	iRecExists = PD_FALSE;
	//char	csTxnSeq[PD_TXN_SEQ_LEN +1];
	char	*csTxnSeq;

	char	*csOrgTxnSeq;

	char	cRecStatus;
	char	cRecARInd;
	char	*csRecTxnCode;
	
	int 	iInternalErr;

	hash_t 	*hContext, *hRequest, *hResponse;

	hTxnHeader = (hash_t *)malloc(sizeof(hash_t));
	hash_init (hTxnHeader, 0);

	hContext = (hash_t *)malloc(sizeof(hash_t));
	hRequest = (hash_t *)malloc(sizeof(hRequest));
	hResponse = (hash_t *)malloc(sizeof(hResponse));

	hash_init (hContext, 0);
	hash_init (hRequest, 0);
	hash_init (hResponse, 0);

	

	// Chk PH MID
	if (GetField_CString(hMyHash, "txn_merch_nmb", &csMerchNmb)) {
DEBUGLOG(("deposit_handler: txn_merch_nmb [%s]\n", csMerchNmb));
	}
	else {
DEBUGLOG(("deposit_handler: txn_merch_nmb missing!\n"));
		iRet = FAILURE;
	}

	rRecordSet = (recordset_t *)malloc(sizeof(recordset_t));

	recordset_init(rRecordSet, 0);
	if (iRet == SUCCESS) {

		DBObjPtr = CreateObj(DBPtr, "DBParMerchProfile", "GetMerchant");
		if ((unsigned long) (*DBObjPtr)(csMerchNmb, rRecordSet) != PD_OK) {
DEBUGLOG(("Calling ParMerchProfile.GetMerchant FAILED!\n"));
		} else {
DEBUGLOG(("Calling ParMerchProfile.GetMerchant SUCC!\n"));

			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if (GetField_CString(hRec, "service", &csTmp)) {
DEBUGLOG(("deposit_handler: ParMerchProfile.GetMerchant service [%s]!\n", csTmp));
					PutField_CString(hMyHash, "service", csTmp);
				}

				if (GetField_CString(hRec, "merchant_id", &csTmp)) {
DEBUGLOG(("deposit_handler: ParMerchProfile.GetMerchant merchant_id [%s]!\n", csTmp));
					PutField_CString(hMyHash, "merchant_id", csTmp);
				}

				if (GetField_CString(hRec, "client_id", &csTmp)) {
DEBUGLOG(("deposit_handler: ParMerchProfile.GetMerchant client_id [%s]!\n", csTmp));
					PutField_CString(hMyHash, "merchant_client_id", csTmp);
				}

				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
	}
	RecordSet_Destroy(rRecordSet);



	if (iRet == SUCCESS) {
		if (GetField_CString(hMyHash, "service", &csService)) {
			DBObjPtr = CreateObj(DBPtr, "DBService", "FindCountryByService");

			csCountry[0] = '\0';
			if ((unsigned long) (*DBObjPtr)(csService, csCountry) != FOUND) {
DEBUGLOG(("deposit_handler: DBService.FindCountryByService FAILED\n"));
				iRet = FAILURE;
			} else {
DEBUGLOG(("deposit_handler: DBService.FindCountryByService country [%s]\n", csCountry));

				PutField_CString(hMyHash, "country", csCountry);
			}


			recordset_init(rRecordSet, 0);
			if (iRet == SUCCESS) {
				DBObjPtr = CreateObj(DBPtr, "DBServicePayMethod","FindPayMethod");
				if ((unsigned long) (*DBObjPtr)(csService, rRecordSet) != PD_OK) {
DEBUGLOG(("deposit_handler: DBServicePayMethod:FindPayMethod FAILED!\n"));
				} else {
DEBUGLOG(("deposit_handler: DBServicePayMethod:FindPayMethod SUCC!\n"));
					hRec = RecordSet_GetFirst(rRecordSet);
					while (hRec) {
						if (GetField_CString(hRec, "pay_method", &csTmp)) {
DEBUGLOG(("deposit_handler: DBServicePayMethod:FindPayMethod pay_method [%s]!\n", csTmp));
							PutField_CString(hMyHash, "pay_method", csTmp);
						}
						hRec = RecordSet_GetNext(rRecordSet);
					}
				}

			}
			RecordSet_Destroy(rRecordSet);

		}
	}
	


	// Chk if exists in txn_header
	if (iRet == SUCCESS) {
		if (GetField_CString(hMyHash, "txn_nmb", &csVNCRefNum)) {
DEBUGLOG(("deposit_handler: txn_nmb [%s]\n", csVNCRefNum));
		}
		else {
DEBUGLOG(("deposit_handler: txn_nmb not found!\n"));
			iRet = FAILURE;
		}
	}

	if (iRet == SUCCESS) {
		DBObjPtr = CreateObj(DBPtr,"DBParTxnData","ChkExist");
		iTmpRet = ((unsigned long)(*DBObjPtr)(csVNCRefNum));
		
		if (iTmpRet == PD_FOUND) {
			iRecExists = PD_TRUE;

		} else if (iTmpRet == PD_NOT_FOUND) {
			iRecExists = PD_FALSE;

		} else {
DEBUGLOG(("deposit_handler: DBParTxnData:ChkExist FAILED!\n"));
			iRet = FAILURE;
		}
	}

	if (iRet == SUCCESS) {
		if (iRecExists == PD_FALSE) {
			// Create Record
			//csTxnSeq[0]= '\0';

                        DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextTxnSeq");
                        //strcpy(csTxnSeq,(*DBObjPtr)());
			csTxnSeq = strdup((char* )(*DBObjPtr)());
                        PutField_CString(hMyHash,"txn_seq",csTxnSeq);
DEBUGLOG(("deposit_handler: Generate (WEB) Txn Seq [%s]\n", csTxnSeq));

			PutField_CString(hTxnHeader, "txn_id", csTxnSeq);

			PutField_CString(hMyHash, "channel_code", "XPY");
			PutField_CString(hMyHash, "process_type", "0200");
			PutField_CString(hMyHash, "process_code", "200002");
			PutField_CString(hMyHash, "vnc_ref_num", csVNCRefNum);

			iRet = format_data(hMyHash, hTxnHeader, hContext, hRequest);

			if (iRet == SUCCESS) {
				ChannelObjPtr = CreateObj(ChannelPtr, "WEBChannel","AddTxnLog");
				if ((unsigned long)((*ChannelObjPtr)(hContext, hRequest)) == PD_OK) {
DEBUGLOG(("depoist_handler:MGTChannel.AddTxnLog  SUCC!\n"));

                        		DBObjPtr = CreateObj(DBPtr,"DBParTxnData","UpdateHeaderVNCRef");
					if ((unsigned long)(*DBObjPtr)(hContext) == PD_OK) {
DEBUGLOG(("depoist_handler:Deposit init record updated vnc_ref_num succ!\n"));
					}
					else {
DEBUGLOG(("depoist_handler:Deposit init record updated vnc_ref_num fail!\n"));
						iRet = FAILURE;
					}

        			}
				else {
DEBUGLOG(("depoist_handler:MGTChannel.AddTxnLog FAIL!\n"));
					iRet = FAILURE;
				}
			}
		

			PutField_CString(hContext, "psp_id", PD_DEFAULT_PSP);
			PutField_CString(hContext, "txn_desc", "DSP Initial Mode");

                        TxnObjPtr = CreateObj(TxnPtr,"TxnWebOnUsDSI","Authorize");
                        if ((unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse) == PD_OK) {
				if (GetField_Int(hContext, "internal_error", &iInternalErr)) {
DEBUGLOG(("depoist_handler:TxnWebOnUSDI:Authorize return internal_error [%d]\n", iInternalErr));
					iRet = FAILURE;
				}
			}
			else {
DEBUGLOG(("depoist_handler:TxnWebOnUSDI:Authorize FAIL\n"));
				iRet = FAILURE;
			}
			
			if (iRet == SUCCESS) {
				PutField_Char(hContext, "status", PD_INIT);
				PutField_CString(hContext, "sub_status", PD_INITIATED);

			 	ChannelObjPtr = CreateObj(ChannelPtr, "WEBChannel","UpdateTxnLog");
				if ((unsigned long)((*ChannelObjPtr)(hContext, hRequest, hResponse)) == PD_OK) {
DEBUGLOG(("depoist_handler:WEBChannel:UpdateTxnLog SUCC\n"));

				} else {
DEBUGLOG(("depoist_handler:WEBChannel:UpdateTxnLog FAIL\n"));
					iRet = FAILURE;
				}
			}	

			FREE_ME(csTxnSeq);

		} else if (iRecExists == PD_TRUE) {	
			// Get Record
                        DBObjPtr = CreateObj(DBPtr,"DBParTxnData","GetDepositTxnHeaderByVNCRefNum");
			if ((unsigned long)(*DBObjPtr)(csVNCRefNum, hTxnHeader) == PD_OK) {
				if (GetField_CString(hTxnHeader, "txn_id", &csTmp)) {
DEBUGLOG(("deposit_handler: ParTxnData:GetTxnHeaderByVNCRefNum txn_id [%s]\n", csTmp));
				}

				if (GetField_Char(hTxnHeader, "status", &cRecStatus)) {
DEBUGLOG(("deposit_handler: ParTxnData:GetTxnHeaderByVNCRefNum status [%c]\n", cRecStatus));
				}

				if (GetField_Char(hTxnHeader, "ar_ind", &cRecARInd)) {
DEBUGLOG(("deposit_handler: ParTxnData:GetTxnHeaderByVNCRefNum ar_ind [%c]\n", cRecARInd));
				}

				if (GetField_Char(hTxnHeader, "txn_code", &csRecTxnCode)) {
DEBUGLOG(("deposit_handler: ParTxnData:GetTxnHeaderByVNCRefNum txn_code [%s]\n", csRecTxnCode));
				}

				iRet = format_data(hMyHash, hTxnHeader, hContext, hRequest);
			}
			else {
DEBUGLOG(("deposit_handler: ParTxnData:GetTxnHeaderByVNCRefNum FAILE!\n"));
				iRet = FAILURE;
			}
		}


		if (iRet == SUCCESS) {
			if (GetField_CString(hMyHash, "txn_status", &csTxnStatus)) {	
DEBUGLOG(("deposit_handler: txn_status [%s]!\n", csTxnStatus));


				if (iRecExists == PD_TRUE) {
					if (!strcmp(csTxnStatus, "DEPOSIT_DEBIT_CARD_PENDING_PSP")) {
						if (GetField_Char(hTxnHeader, "status", &cRecStatus)) {
							if (cRecStatus == PD_TO_PSP) {
								iRet = FAILURE;
								iTmpRet = -100;
							}
						}
					}

					if (!strcmp(csTxnStatus, "DEPOSIT_DEBIT_CARD_APPROVED")) {
						if (GetField_Char(hTxnHeader, "status", &cRecStatus)) {
							if (cRecStatus == PD_COMPLETE) {
								if (GetField_Char(hTxnHeader, "ar_ind", &cRecARInd)) {
									if (cRecARInd == PD_ACCEPTED) {
										iRet = FAILURE;
										iTmpRet = -100;
									}
								}
							}
						}
					}

					if (!strcmp(csTxnStatus, "LIMIT_DECLINED") ||
				            !strcmp(csTxnStatus, "DEPOSIT_DEBIT_CARD_DECLINED")) {

						if (GetField_Char(hTxnHeader, "status", &cRecStatus)) {
                                                        if (cRecStatus == PD_COMPLETE) {
                                                                if (GetField_Char(hTxnHeader, "ar_ind", &cRecARInd)) {
                                                                        if (cRecARInd == PD_REJECTED) {
                                                                                iRet = FAILURE;
                                                                                iTmpRet = -100;
                                                                        }
                                                                }
                                                        }
                                                }
					}

					if (!strcmp(csTxnStatus, "DEPOSIT_DEBIT_CARD_REVERSED")) {
						if (GetField_CString(hTxnHeader, "txn_code", &csRecTxnCode)) {
							if (!strcmp(csRecTxnCode, "VDS")) {
								iRet = FAILURE;
								iTmpRet = -100;
							}
						}
					}


				}

			}
			else {
DEBUGLOG(("deposit_handler: txn_status not found !\n"));
				iRet = FAILURE;
			}
		
		}	
	
		// Chk Status 
		if (iRet == SUCCESS) {
			// PENDING
			if (!strcmp(csTxnStatus, "DEPOSIT_DEBIT_CARD_PENDING_PSP") || (iRecExists == PD_FALSE)) {
			
DEBUGLOG(("deposit_handler: prepare pending case!\n"));

				if (GetField_CString(hContext, "txn_seq", &csTmp)) {
					PutField_CString(hContext, "from_txn_seq", csTmp);
				}
				if (GetField_CString(hRequest, "txn_ccy", &csTmp)) {
					PutField_CString(hContext, "org_txn_ccy", csTmp);
				}
				if (GetField_Double(hContext, "txn_amt", &dTmp)) {
					PutField_Double(hContext, "org_txn_amt", dTmp);
				}

				PutField_Char(hContext, "party_type", PD_TYPE_MERCHANT);
				PutField_CString(hContext, "amount_type", PD_CR);


				BOObjPtr = CreateObj(BOPtr,"BOTxnElements","AddTxnAmtElement");
				iRet = (unsigned long)(*BOObjPtr)(hContext);			


				if (iRet == SUCCESS) {
DEBUGLOG(("deposit_handler: BOTxnElements.AddTxnAmtlements SUCC!\n"));
				} else {
DEBUGLOG(("deposit_handler: BOTxnElements.AddTxnAmtElements FAIL!\n"));
				}

				if (iRet == SUCCESS) {

					if (GetField_Double(hMyHash, "markup_amt", &dTmp)) {
						PutField_Double(hContext, "markup_amt", dTmp);
					}

					if (dTmp > 0.0) {
						PutField_CString(hContext,"amount_type",PD_DR);

						BOObjPtr = CreateObj(BOPtr,"BOTxnElements","AddMarkupAmtElement");
						iRet = (unsigned long)(*BOObjPtr)(hContext);			
	
						if (iRet == SUCCESS) {
DEBUGLOG(("deposit_handler: BOTxnElements.AddMarkupAmtElement SUCC!\n"));
						} else {
DEBUGLOG(("deposit_handler: BOTxnElements.AddMarkupAmtElement FAIL!\n"));
						}
					}
				}

				if (iRet == SUCCESS) {
					PutField_Char(hContext, "status", PD_TO_PSP);
					PutField_CString(hContext, "sub_status", PD_SENT_TO_PSP);

					// PspID
					if (GetField_CString(hMyHash, "psp_type_code", &csPspID)) {

DEBUGLOG(("deposit_handler: psp_id mapping...\n"));

						DBObjPtr = CreateObj(DBPtr,"DBParPspClientMap","GetPspID");
						if ((unsigned long)(*DBObjPtr)(hMyHash) == FOUND) {
							if (GetField_CString(hMyHash, "psp_id", &csTmp)) {
DEBUGLOG(("deposit_handler: psp_id [%s]\n", csTmp));
								PutField_CString(hContext, "psp_id", csTmp);
							}

							if (GetField_CString(hMyHash, "psp_country", &csTmp)) {
DEBUGLOG(("deposit_handler: psp_country [%s]\n", csTmp));
							}
						}
						else {
DEBUGLOG(("deposit_handler: DBParPspClientMap.GetPspID FAIL!\n"));
	
							iRet = FAILURE;
						}
					}

					// Get Bank Code
					if ((GetField_CString(hMyHash, "psp_type_code", &csPspTypeCode)) &&
					    (GetField_CString(hMyHash, "gate_id", &csGateID))) {

						DBObjPtr = CreateObj(DBPtr,"DBParPspClientMap","GetBankCode");
						if ((unsigned long)(*DBObjPtr)(hMyHash) == FOUND) {
							if (GetField_CString(hMyHash, "int_bank_code", &csTmp)) {
DEBUGLOG(("deposit_handler: DBParPspClientMap.GetBankCode [%s]\n", csTmp));
								PutField_CString(hContext, "internal_bank_code", csTmp);
							}
						}
						else {
DEBUGLOG(("deposit_handler: DBParPspClientMap.GetBankCode FAIL!\n"));
						}
					}
				
					// Fee Elements
					if (GetField_Double(hMyHash, "fee", &dTmp)) {
						if (dTmp > 0.0) {
							GetField_CString(hRequest, "txn_ccy", &csTmp);
							PutField_CString(hContext, "src_txn_fee_ccy", csTmp);

							PutField_Double(hContext, "src_txn_fee", dTmp);
							PutField_Char(hContext, "party_type", PD_TYPE_MERCHANT);
							PutField_CString(hContext, "amount_type", PD_DR);

						}
					}
				}

				if (iRet == SUCCESS) {
					// UpdateTxnLog
				 	ChannelObjPtr = CreateObj(ChannelPtr, "WEBChannel","UpdateTxnLog");
					if ((unsigned long)((*ChannelObjPtr)(hContext, hRequest, hResponse)) == PD_OK) {
DEBUGLOG(("depoist_handler:WEBChannel:UpdateTxnLog pending status SUCC\n"));

						//special handling txn_psp_detail
						hash_t	 *hPspDetail;
						hPspDetail = (hash_t *) malloc(sizeof(hash_t));
						hash_init(hPspDetail, 0);

						if (GetField_CString(hContext, "txn_seq", &csTmp)) {
							PutField_CString(hPspDetail, "txn_seq", csTmp);
						}
						if (GetField_CString(hContext, "psp_id", &csTmp)) {
							PutField_CString(hPspDetail, "psp_id", csTmp);
						}

						if (GetField_CString(hMyHash, "to_ccy", &csTmp)) {
							PutField_CString(hPspDetail, "txn_ccy", csTmp);
						}
						if (GetField_Double(hMyHash, "to_amount", &dTmp)) {
							PutField_Double(hPspDetail, "txn_amount", dTmp);
						}
						if (GetField_CString(hContext, "internal_bank_code", &csTmp)) {
							PutField_CString(hPspDetail, "bank_code", csTmp);
						}
						PutField_CString(hPspDetail, "update_user", "SYSTEM");

						DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Update");
						iRet = (unsigned long)(*DBObjPtr)(hPspDetail);

						hash_destroy(hPspDetail);
						FREE_ME(hPspDetail);


					} else {
DEBUGLOG(("depoist_handler:WEBChannel:UpdateTxnLog pending status FAIL\n"));
						iRet = FAILURE;
					}
				}	
			}
			
		}

		if (iRet == SUCCESS) {
			//DECLINED
			if (!strcmp(csTxnStatus, "LIMIT_DECLINED") || !strcmp(csTxnStatus, "DEPOSIT_DEBIT_CARD_DECLINED")) {

                                PutField_Char(hContext,"status",PD_COMPLETE);
                                PutField_Char(hContext,"ar_ind",PD_REJECT);
				PutField_CString(hContext, "sub_status", PD_PSP_REJECT);

			 	ChannelObjPtr = CreateObj(ChannelPtr, "WEBChannel","UpdateTxnLog");
				if ((unsigned long)((*ChannelObjPtr)(hContext, hRequest, hResponse)) == PD_OK) {
DEBUGLOG(("depoist_handler:WEBChannel:UpdateTxnLog declined status SUCC\n"));

				} else {
DEBUGLOG(("depoist_handler:WEBChannel:UpdateTxnLog declined status FAIL\n"));
					iRet = FAILURE;
				}
			
			}
		}
	
		if (iRet == SUCCESS) {
			// APPROVE
			if (!strcmp(csTxnStatus, "DEPOSIT_DEBIT_CARD_APPROVED") ||
				(!strcmp(csTxnStatus, "DEPOSIT_DEBIT_CARD_REVERSED") && (iRecExists == PD_FALSE))) {

DEBUGLOG(("prepare approve....\n"));
				//iRet = format_data(hMyHash, hTxnHeader, hContext, hRequest);
				

				// update balance only if status is approved
				if (!strcmp(csTxnStatus, "DEPOSIT_DEBIT_CARD_APPROVED") && (iRet == SUCCESS)) {


                                        // PspID
                                        if (GetField_CString(hMyHash, "psp_type_code", &csPspID)) {

DEBUGLOG(("deposit_handler: psp_id mapping...\n"));

                                                DBObjPtr = CreateObj(DBPtr,"DBParPspClientMap","GetPspID");
                                                if ((unsigned long)(*DBObjPtr)(hMyHash) == FOUND) {
                                                        if (GetField_CString(hMyHash, "psp_id", &csTmp)) {
DEBUGLOG(("deposit_handler: psp_id [%s]\n", csTmp));
                                                                PutField_CString(hContext, "psp_id", csTmp);
                                                        }

                                                        if (GetField_CString(hMyHash, "psp_country", &csTmp)) {
DEBUGLOG(("deposit_handler: psp_country [%s]\n", csTmp));
                                                        }
                                                }
                                                else {
DEBUGLOG(("deposit_handler: DBParPspClientMap.GetPspID FAIL!\n"));

                                                        iRet = FAILURE;
                                                }
                                        }




					if (GetField_CString(hMyHash, "post_date", &csTmp)) {
DEBUGLOG(("deposit_handler: (approve) approve_date [%s]\n", csTmp));
						PutField_CString(hContext, "approval_date", csTmp);
					}

					if (GetField_Double(hMyHash, "to_amount", &dTmp)) {
DEBUGLOG(("deposit_handler: (approve) to_amount [%lf]\n", dTmp));
						PutField_Double(hContext, "org_dst_net_amt", dTmp);
					}
					if (GetField_CString(hMyHash, "psp_id", &csTmp)) {
DEBUGLOG(("deposit_handler: (approve) psp_id [%s]\n", csTmp));
						PutField_CString(hContext, "org_psp_id", csTmp);
					}

					PutField_Char(hContext, "txn_type", 'D');

					BOObjPtr = CreateObj(BOPtr,"BOPsp","CalPspCosts");
					if ((unsigned long)(*BOObjPtr)(hContext, hRequest) == PD_OK) {
						if (GetField_Double(hContext, "precal_fee", &dTmp)) {
DEBUGLOG(("depoist_handler:precal_fee [%lf]\n",dTmp));
							PutField_Double(hMyHash, "precal_fee", dTmp);
						}
					}
					else {
DEBUGLOG(("depoist_handler:precal_fee FAIL!\n"));
						iRet = FAILURE;
					}
	
					if (iRet == SUCCESS) {
						// Handle Balance
						iRet = handle_deposit_balance(hMyHash);

						if (iRet != SUCCESS) {
DEBUGLOG(("depoist_handler:handle_deposit_balance FAIL\n"));
						} 
					}

				}

                                PutField_Char(hContext,"status",PD_COMPLETE);
                                PutField_Char(hContext,"ar_ind",PD_ACCEPT);
				PutField_CString(hContext, "sub_status", PD_ACK_TO_MERCHANT);
	

				if (iRet == SUCCESS) {

DEBUGLOG(("deposit_handler:: Call Update Transaction (Approved)!\n"));
					DBObjPtr = CreateObj(DBPtr,"DBTransaction","Update");
					iRet = (unsigned long)(*DBObjPtr)(hContext);
				}
				if (iRet == SUCCESS) {
					if (GetField_Double(hMyHash, "merchant_total_float", &dTmp)) {
DEBUGLOG(("deposit_handler:: (approve) merchant_total_float [%lf]\n", dTmp));
						PutField_Double(hContext, "total_float", dTmp);
					}
					if (GetField_Double(hMyHash, "merchant_current_bal", &dTmp)) {
DEBUGLOG(("deposit_handler:: (approve) merchant_current_bal [%lf]\n", dTmp));
						PutField_Double(hContext, "current_bal", dTmp);
					}
					if (GetField_Double(hMyHash, "merchant_total_reserved_amount", &dTmp)) {
DEBUGLOG(("deposit_handler:: (approve) merchant_total_reserved_amount [%lf]\n", dTmp));
						PutField_Double(hContext, "total_reserved_amount", dTmp);
					}
					if (GetField_Double(hMyHash, "merchant_total_hold", &dTmp)) {
DEBUGLOG(("deposit_handler:: (approve) merchant_total_hold [%lf]\n", dTmp));
						PutField_Double(hContext, "total_hold", dTmp);
					}
					if (GetField_Double(hMyHash, "merchant_settlement_in_transit", &dTmp)) {		
DEBUGLOG(("deposit_handler:: (approve) merchant_settlement_in_transit [%lf]\n", dTmp));
						PutField_Double(hContext, "settlement_in_transit", dTmp);
					}

					if (GetField_Double(hMyHash, "merchant_open_bal", &dTmp)) {
DEBUGLOG(("deposit_handler:: (approve) merchant_open_bal [%lf]\n", dTmp));
						PutField_Double(hContext, "open_bal", dTmp);
					}
					else {
						PutField_Double(hContext, "open_bal", 0.0);
					}



DEBUGLOG(("deposit_handler:: Call Update Transaction Detail (Approved)!\n"));
		                        DBObjPtr = CreateObj(DBPtr,"DBTransaction","UpdateDetail");
               		         	iRet = (unsigned long)(*DBObjPtr)(hContext);
                		}
		                if (iRet == SUCCESS) {

					if (GetField_Double(hMyHash, "precal_fee", &dTmp)) {
						PutField_Double(hContext, "service_fee", dTmp);
					}

					if (GetField_Double(hMyHash, "psp_balance", &dTmp)) {
						PutField_Double(hContext, "bal", dTmp);
					}

					if (GetField_Double(hMyHash, "psp_total_float", &dTmp)) {
						PutField_Double(hContext, "total_float", dTmp);
					}
					else {
						RemoveField_Double(hContext, "total_float");
					}

					if (GetField_Double(hMyHash, "psp_total_hold", &dTmp)) {
						PutField_Double(hContext, "total_hold", dTmp);
					}
					else {
						RemoveField_Double(hContext, "total_hold");
					}
			
					
					if (GetField_CString(hMyHash, "psp_txn_date", &csTmp)) {
						PutField_CString(hContext, "txn_date", csTmp);
						PutField_CString(hContext, "fundin_date_short", csTmp);
					}
					if (GetField_CString(hMyHash, "psp_txn_time", &csTmp)) {
						PutField_CString(hContext, "txn_time", csTmp);
					}
					if (GetField_CString(hMyHash, "psp_order_id", &csTmp)) {
						PutField_CString(hContext, "tid", csTmp);
					}
					if (GetField_CString(hMyHash, "txn_date", &csTmp)) {
						PutField_CString(hContext, "fundin_date", csTmp);
					}
	

DEBUGLOG(("deposit_handler:: Call Update TxnPspDetail (Approved)\n"));
					DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Update");
					iRet = (unsigned long)(*DBObjPtr)(hContext);
                		}
			}
		}

		if (iRet == SUCCESS) {
			// REVERSE
			hash_t *hNewRev;
			hNewRev = (hash_t *)malloc(sizeof(hash_t));
			hash_init(hNewRev, 0);

			if (!strcmp(csTxnStatus, "DEPOSIT_DEBIT_CARD_REVERSED")) {


				PutField_Char(hContext,"status",PD_REVERSED);
				PutField_Char(hContext,"ar_ind",PD_ACCEPT);
		        	PutField_CString(hContext, "sub_status", PD_VOID);

DEBUGLOG(("deposit_handler:: Call Update Transaction (Reversed)!\n"));
				DBObjPtr = CreateObj(DBPtr,"DBTransaction","Update");
				iRet = (unsigned long)(*DBObjPtr)(hContext);

				if (iRet == SUCCESS) {
					PutField_CString(hMyHash, "channel_code", "XPY");
					PutField_CString(hMyHash, "process_type", "0000");
					PutField_CString(hMyHash, "process_code", "000000");

					PutField_Int(hNewRev, "db_commit", PD_FALSE);

					// use vnc_ref_num as org_txn_id
					if (GetField_CString(hTxnHeader, "txn_id", &csTmp)) {
DEBUGLOG(("deposit_handler:: (org) txn_id = [%s]\n", csTmp));

						PutField_CString(hNewRev, "ele_org_txn_id", csTmp);

						if (iRecExists == PD_TRUE) {
							PutField_CString(hMyHash, "org_txn_id", csTmp);
							PutField_CString(hNewRev, "org_txn_seq", csTmp);
							PutField_CString(hNewRev, "org_txn_id", csTmp);


						}
						else {
							if (GetField_CString(hMyHash, "txn_nmb", &csTmp)) {
								PutField_CString(hNewRev, "org_txn_seq", csTmp);
							}
						}
					}

					
	                        	DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextMgtTxnSeq");
					csTxnSeq = strdup((char* )(*DBObjPtr)());	

					PutField_CString(hMyHash,"txn_seq",csTxnSeq);
DEBUGLOG(("deposit_handler: Generate (WEB)2 Txn Seq [%s]\n", csTxnSeq));
					PutField_CString(hNewRev, "txn_seq", csTxnSeq);
					PutField_CString(hTxnHeader, "txn_id", csTxnSeq);

					PutField_Char(hNewRev, "status", PD_COMPLETE);
					PutField_Char(hNewRev, "ar_ind", PD_ACCEPT);


					PutField_CString(hContext, "txn_code", "VDS");
					PutField_CString(hMyHash,  "txn_code", "VDS");

					iRet = format_data(hMyHash, hTxnHeader, hNewRev, hNewRev);

					if (GetField_CString(hNewRev, "PHDATE", &csTmp)) {
						PutField_CString(hNewRev, "host_posting_date", csTmp);
						PutField_CString(hNewRev, "approval_date", csTmp);
					}
					PutField_CString(hNewRev, "add_user", PD_UPDATE_USER);
					PutField_CString(hNewRev, "update_user", PD_UPDATE_USER);

					if (GetField_CString(hMyHash, "txn_nmb", &csTmp)) {
						PutField_CString(hNewRev, "vnc_ref_num", csTmp);
					}

					if (GetField_Double(hMyHash, "ex_rate", &dTmp)) {
						PutField_Double(hNewRev, "ex_rate", dTmp);
					}


					if (iRet == SUCCESS) {

						if (GetField_CString(hRequest, "merchant_id", &csTmp)) {
							PutField_CString(hNewRev, "merchant_id", csTmp);
						}

						if (GetField_CString(hNewRev, "merchant_client_id", &csTmp)) {
							PutField_CString(hNewRev, "client_id", csTmp);
						}

DEBUGLOG(("deposit_handler:: Call Add Transaction (Reversed)!\n"));
						DBObjPtr = CreateObj(DBPtr,"DBTransaction","Add");
						iRet = (unsigned long)(*DBObjPtr)(hNewRev);


						if (iRet == SUCCESS) {
							DBObjPtr = CreateObj(DBPtr,"DBTransaction","Update");
							iRet = (unsigned long)(*DBObjPtr)(hNewRev);
						}
						
					}

					if (iRet == SUCCESS) {
	                        		DBObjPtr = CreateObj(DBPtr,"DBParTxnData","UpdateHeaderVNCRef");
						iRet = (unsigned long)(*DBObjPtr)(hNewRev);
					}


					if (iRet == SUCCESS) {

                                                // Get Bank Code
                                                if ((GetField_CString(hMyHash, "psp_type_code", &csPspTypeCode)) &&
                                                      (GetField_CString(hMyHash, "gate_id", &csGateID))) {

                                                         DBObjPtr = CreateObj(DBPtr,"DBParPspClientMap","GetBankCode");
                                                         if ((unsigned long)(*DBObjPtr)(hMyHash) == FOUND) {
                                                                 if (GetField_CString(hMyHash, "int_bank_code", &csTmp)) {
DEBUGLOG(("deposit_handler: DBParPspClientMap.GetBankCode [%s] (reversed)\n", csTmp));
                                                                PutField_CString(hNewRev, "internal_bank_code", csTmp);
                                                                }
                                                        }
                                                        else {
DEBUGLOG(("deposit_handler: DBParPspClientMap.GetBankCode FAIL (reversed)!\n"));
                                                         }
                                                 }

						if (GetField_CString(hNewRev, "internal_bank_code", &csTmp)) {
							PutField_CString(hNewRev, "bank_code", csTmp);
						}


DEBUGLOG(("deposit_handler:: Call Add Transaction Detail (Reversed)!\n"));
						DBObjPtr = CreateObj(DBPtr,"DBTransaction","AddDetail");
						iRet = (unsigned long)(*DBObjPtr)(hNewRev);
					}

					if (iRet == SUCCESS) {

						if (GetField_CString(hMyHash, "psp_order_id", &csTmp)) {
							PutField_CString(hNewRev, "tid", csTmp);
						}

						if (GetField_CString(hMyHash, "psp_type_code", &csPspID)) {

DEBUGLOG(("deposit_handler: psp_id mapping (reversed)...\n"));

                                                	DBObjPtr = CreateObj(DBPtr,"DBParPspClientMap","GetPspID");
	                                                if ((unsigned long)(*DBObjPtr)(hMyHash) == FOUND) {
								if (GetField_CString(hMyHash, "psp_id", &csTmp)) {
DEBUGLOG(("deposit_handler: psp_id [%s] (reversed)\n", csTmp));
                                                                	PutField_CString(hNewRev, "psp_id", csTmp);
                                                        	}

	                                                        if (GetField_CString(hMyHash, "psp_country", &csTmp)) {
DEBUGLOG(("deposit_handler: psp_country [%s] (reversed)\n", csTmp));
								}
                                                	}
	                                                else {
DEBUGLOG(("deposit_handler: DBParPspClientMap.GetPspID FAIL (reversed)!\n"));

								iRet = FAILURE;
                                                	}
                                        	}

						PutField_CString(hNewRev, "desc", "Void Deposit");
						

DEBUGLOG(("deposit_handler:: Call Add Transaction TxnPspDetail (Reversed)!\n"));
						if (iRet == SUCCESS) {
							DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Add");
							iRet = (unsigned long)(*DBObjPtr)(hNewRev);
						}
					}

					if (iRet == SUCCESS) {
						PutField_Int(hMyHash, "void_flag", PD_TRUE);
						iRet = handle_deposit_balance(hMyHash);
					}


					if (iRet == SUCCESS) {
						if (GetField_Double(hMyHash, "merchant_total_float", &dTmp)) {
							PutField_Double(hNewRev, "total_float", dTmp);
						}
	                                        if (GetField_Double(hMyHash, "merchant_current_bal", &dTmp)) {
							PutField_Double(hNewRev, "current_bal", dTmp);
                                        	}
	                                        if (GetField_Double(hMyHash, "merchant_total_reserved_amount", &dTmp)) {
							PutField_Double(hNewRev, "total_reserved_amount", dTmp);
                                        	}
						if (GetField_Double(hMyHash, "merchant_total_hold", &dTmp)) {
                                                	PutField_Double(hNewRev, "total_hold", dTmp);
                                        	}
                                        	if (GetField_Double(hMyHash, "merchant_settlement_in_transit", &dTmp)) {
                                                	PutField_Double(hNewRev, "settlement_in_transit", dTmp);
                                        	}
                                        	if (GetField_Double(hMyHash, "merchant_open_bal", &dTmp)) {
                                                	PutField_Double(hNewRev, "open_bal", dTmp);
                                        	}

DEBUGLOG(("deposit_handler:: Call Update Transaction Detail (Reversed)!\n"));
	                                        DBObjPtr = CreateObj(DBPtr,"DBTransaction","UpdateDetail");
						iRet = (unsigned long)(*DBObjPtr)(hNewRev);
					}

                                	if (iRet == SUCCESS) {

                                        	if (GetField_Double(hMyHash, "precal_fee", &dTmp)) {
                                                	PutField_Double(hNewRev, "service_fee", dTmp);
                                        	}

	                                        if (GetField_Double(hMyHash, "psp_balance", &dTmp)) {
							PutField_Double(hNewRev, "bal", dTmp);
                                        	}

	                                        if (GetField_Double(hMyHash, "psp_total_float", &dTmp)) {
							PutField_Double(hNewRev, "total_float", dTmp);
                                        	}
	                                        else {
        	                                        RemoveField_Double(hNewRev, "total_float");
						}

	                                        if (GetField_Double(hMyHash, "psp_total_hold", &dTmp)) {
							PutField_Double(hNewRev, "total_hold", dTmp);
                                        	}
                                        	else {
                                              		RemoveField_Double(hNewRev, "total_hold");
                                        	}

						if (GetField_CString(hMyHash, "psp_txn_date", &csTmp)) {
							PutField_CString(hNewRev, "txn_date", csTmp);
						}
						

DEBUGLOG(("deposit_handler:: Call Update TxnPspDetail (Reversed)\n"));
	                                        DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Update");
						iRet = (unsigned long)(*DBObjPtr)(hNewRev);
                                	}


					if (iRet == SUCCESS) {
						// Chk Elements exists by org_txn_seq
						GetField_CString(hNewRev, "ele_org_txn_id", &csOrgTxnSeq);

DEBUGLOG(("deposit_handler:: Call ChkElementExists (Reversed) org_txn_id [%s]\n", csOrgTxnSeq));

						DBObjPtr = CreateObj(DBPtr,"DBParTxnData","ChkElementExist");
						if ((unsigned long)(*DBObjPtr)(csOrgTxnSeq) == PD_FOUND) {		

DEBUGLOG(("deposit_handler:: Call ChkElementExists (Reversed) FOUND!\n"));

							PutField_CString(hRequest, "org_txn_code", "DSI");
							PutField_CString(hNewRev, "txn_seq", csTxnSeq);
							PutField_CString(hNewRev, "org_txn_seq", csOrgTxnSeq);

							BOObjPtr = CreateObj(BOPtr,"BOTxnElements","VoidOrgTxnElements");
							iRet = (unsigned long)(*BOObjPtr)(hNewRev, hRequest);			
						} 
						else {
							//......... insert txn_element markup-> fee -> txnamt
						}
					} 


					FREE_ME(csTxnSeq);
				}
			}				
			hash_destroy(hNewRev);
			FREE_ME(hNewRev);
		}
	

	}


	if (iRet == SUCCESS) {
		PutField_CString(hMyHash, "proc_status", "COMPLETE");
		GetField_Int(hMyHash, "sort_txn_seq", &iTmp);

DEBUGLOG(("deposit_handler: Update TxnDataStatus\n"));

		DBObjPtr = CreateObj(DBPtr,"DBParTxnData","UpdateTxnDataStatus");
		if ((unsigned long)(*DBObjPtr)(hMyHash) == PD_OK) {
DEBUGLOG(("deposit_handler: Complete txn_data.seq [%d]\n", iTmp));
		}
	}
	
	if ((iRet != SUCCESS) && (iTmpRet == -100)) {
		PutField_CString(hMyHash, "proc_status", "SKIP");
		GetField_Int(hMyHash, "sort_txn_seq", &iTmp);

DEBUGLOG(("deposit_handler: Update TxnDataStatus\n"));

		DBObjPtr = CreateObj(DBPtr,"DBParTxnData","UpdateTxnDataStatus");
		if ((unsigned long)(*DBObjPtr)(hMyHash) == PD_OK) {
DEBUGLOG(("deposit_handler: skip txn_data.seq [%d]\n", iTmp));

			iRet = SUCCESS;	
		}
	}

	hash_destroy(hTxnHeader);
	FREE_ME(hTxnHeader);
	
	hash_destroy(hContext);
	hash_destroy(hRequest);
	hash_destroy(hResponse);

	FREE_ME(hContext);
	FREE_ME(hRequest);
	FREE_ME(hResponse);

	FREE_ME(rRecordSet);


	return iRet;
}

int settlement_handler(hash_t *hMyHash)
{
	int iRet = SUCCESS;

	return iRet;
}

int adjustment_handler(hash_t *hMyHash)
{
	int iRet = SUCCESS;

	return iRet;
	
}
int payout_handler(hash_t *hMyHash)
{
	int iRet = SUCCESS;

	return iRet;
}

int payout_reversal_handler(hash_t *hMyHash)
{
	int iRet = SUCCESS;
	
	return iRet;
}


int format_data(hash_t *hMyHash, hash_t *hTxnHeader, hash_t *hContext, hash_t *hRequest)
{
	int 	iRet = SUCCESS;
	char*	csTmp;

	char	*csTxnDateTime;
	char	csDate[PD_DATE_LEN + 1];
	char	csTime[PD_TIME_LEN + 1];
	double	dTxnAmount = 0.0;
	double  dTmp = 0.0;
	double  dFee = 0.0;
	double	dNetAmount = 0.0;

	if (GetField_CString(hTxnHeader, "txn_id", &csTmp)) {
DEBUGLOG(("format_data txn_id [%s]\n", csTmp));
		PutField_CString(hContext, "txn_seq", csTmp);
	}


	if (GetField_CString(hMyHash, "channel_code", &csTmp)) {
DEBUGLOG(("format_data channel_code [%s]\n", csTmp));
		PutField_CString(hContext, "channel_code", csTmp);
	}



	if (GetField_CString(hMyHash, "txn_code", &csTmp)) {
DEBUGLOG(("format_data txn_code [%s]\n", csTmp));
		PutField_CString(hContext, "txn_code", csTmp);
	}

	if (GetField_CString(hMyHash, "post_date", &csTmp)) {
DEBUGLOG(("format_data post_date [%s]\n", csTmp));
		PutField_CString(hContext, "PHDATE", csTmp);
	}


	if (GetField_CString(hMyHash, "local_tm_date", &csTmp)) {
DEBUGLOG(("format_data local_tm_date [%s]\n", csTmp));
		PutField_CString(hContext, "local_tm_date", csTmp);
	
	}
	
	if (GetField_CString(hMyHash, "local_tm_time", &csTmp)) {
DEBUGLOG(("format_data local_tm_time [%s]\n", csTmp));
		PutField_CString(hContext, "local_tm_time", csTmp);
	}

	if (GetField_CString(hMyHash, "process_type", &csTmp)) {
DEBUGLOG(("format_data process_type [%s]\n", csTmp));
		PutField_CString(hRequest, "process_type", csTmp);
	}

	if (GetField_CString(hMyHash, "process_code", &csTmp)) {
DEBUGLOG(("format_data process_code [%s]\n", csTmp));
		PutField_CString(hRequest, "process_code", csTmp);
	}


	if (GetField_CString(hMyHash, "merchant_id", &csTmp)) {
DEBUGLOG(("format_data merchant_id [%s]\n", csTmp));
		PutField_CString(hRequest, "merchant_id", csTmp);
	}

	if (GetField_CString(hMyHash, "merch_ref", &csTmp)) {
DEBUGLOG(("format_data merchant_ref [%s]\n", csTmp));
		PutField_CString(hRequest, "merchant_ref", csTmp);
	}


	if (GetField_CString(hMyHash, "txn_date", &csTxnDateTime)) {
DEBUGLOG(("format_data txn_date [%s]\n", csTxnDateTime));
		PutField_CString(hRequest, "transmission_datetime", csTxnDateTime);

		memset(csDate, 0, sizeof(csDate));
		memset(csTime, 0, sizeof(csTime));

		strncpy(csDate, csTxnDateTime, PD_DATE_LEN);
		strncpy(csTime, csTxnDateTime + PD_DATE_LEN, PD_TIME_LEN);

DEBUGLOG(("format_data tm_date [%s]\n", csDate));
DEBUGLOG(("format_data tm_time [%s]\n", csTime));

		PutField_CString(hRequest, "tm_date", csDate);
		PutField_CString(hRequest, "tm_time", csTime);

		PutField_CString(hMyHash, "psp_txn_date", csDate);
		PutField_CString(hMyHash, "psp_txn_time", csTime);
	}

	if (GetField_CString(hMyHash, "service", &csTmp)) {
DEBUGLOG(("format_data service [%s]\n", csTmp));
		PutField_CString(hRequest, "service_code", csTmp);
	}

	if (GetField_CString(hMyHash, "client_ip", &csTmp)) {
DEBUGLOG(("format_data client_ip [%s]\n", csTmp));
		PutField_CString(hRequest, "ip_addr", csTmp);
	}

	if (GetField_CString(hMyHash, "ccy", &csTmp)) {
DEBUGLOG(("format_data ccy [%s]\n", csTmp));
		PutField_CString(hRequest, "txn_ccy", csTmp);
	}

	if (GetField_CString(hMyHash, "country", &csTmp)) {
DEBUGLOG(("format_data country [%s]\n", csTmp));
		PutField_CString(hRequest, "txn_country", csTmp);
	}

	if (GetField_CString(hMyHash, "pay_method", &csTmp)) {
DEBUGLOG(("format_data pay_method [%s]\n", csTmp));
		PutField_CString(hRequest, "pay_method", csTmp);
		PutField_CString(hContext, "selected_pay_method", csTmp);
	}

	if (GetField_CString(hMyHash, "vnc_ref_num", &csTmp)) {
DEBUGLOG(("format_data vnc_ref_num [%s]\n", csTmp));
		PutField_CString(hContext, "vnc_ref_num", csTmp);
	}

	if (GetField_Double(hMyHash, "amount", &dTxnAmount)) {
DEBUGLOG(("format_data txn_amount [%lf]\n", dTxnAmount));
		PutField_Double(hContext, "txn_amt", dTxnAmount);
	}

	if (GetField_Double(hMyHash, "ex_rate", &dTmp)) {
DEBUGLOG(("format_data ex_rate [%lf]\n", dTmp));
		PutField_Double(hContext, "ex_rate", dTmp);
	}

	if (GetField_Double(hMyHash, "fee", &dFee)) {
DEBUGLOG(("format_data fee [%lf]\n", dFee));

	}

	if (dTxnAmount > 0.0) {
		dNetAmount = dTxnAmount - dFee;
DEBUGLOG(("format_data net_amount [%lf]\n", dNetAmount));
		PutField_Double(hContext, "net_amt", dNetAmount);
		PutField_Double(hMyHash, "net_amt", dNetAmount);
	}


	if (GetField_CString(hMyHash, "merchant_client_id", &csTmp)) {
DEBUGLOG(("format_data merchant_client_id [%s]\n", csTmp));
		PutField_CString(hContext, "merchant_client_id", csTmp);

	}

	return iRet;
	
}


int handle_deposit_balance(hash_t *hMyHash) {
	int	iRet = SUCCESS;

	char	*csMID = NULL;
	char	*csCcy = NULL;
	char	*csCountry = NULL;
	char	*csService = NULL;
	double	dAmount = 0.0;
	double	dTmp = 0.0;
	int	iVoidFlag = PD_FALSE;
	double	dFee = 0.0;
	double  dMarkupAmt = 0.0;

	char	*csPspID = NULL;
	char	*csPspCountry = NULL;
	double	dToAmount = 0.0;
	double	dPreCalFee = 0.0;
	char	*csToCcy = NULL;

	hash_t	*hMerchRec;
	hash_t	*hPspRec;

	hMerchRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hMerchRec ,0);

	hPspRec = (hash_t*) malloc(sizeof(hash_t));
	hash_init(hPspRec, 0);
	
	if (GetField_CString(hMyHash, "merchant_id", &csMID)) {
DEBUGLOG(("handle_deposit_balance: merchant_id [%s]\n", csMID));
	}
	else {
DEBUGLOG(("handle_deposit_balance: merchant_id missing\n"));
		iRet = FAILURE;
	}

	if (GetField_CString(hMyHash, "ccy", &csCcy)) {
DEBUGLOG(("handle_deposit_balance: ccy [%s]\n", csCcy));
	}
	else {
DEBUGLOG(("handle_deposit_balance: ccy missing\n"));
		iRet = FAILURE;
	}

	if (GetField_CString(hMyHash, "country", &csCountry)) {
DEBUGLOG(("handle_deposit_balance: country [%s]\n", csCountry));
	}
	else {
DEBUGLOG(("handle_deposit_balance: country missing\n"));
		iRet = FAILURE;
	}

	if (GetField_CString(hMyHash, "service", &csService)) {
DEBUGLOG(("handle_deposit_balance: service [%s]\n", csService));
	}
	else {
DEBUGLOG(("handle_deposit_balance: service missing\n"));
		iRet = FAILURE;
	}

	if (GetField_Double(hMyHash, "amount", &dAmount)) {
DEBUGLOG(("handle_deposit_balance: amount [%lf]\n", dAmount));
	}
	else {
DEBUGLOG(("handle_deposit_balance: amount missing\n"));
		iRet = FAILURE;
	}

	if (GetField_Double(hMyHash, "fee", &dFee)) {
DEBUGLOG(("handle_deposit_balance: fee[%lf]\n", dFee));
	}
	else {
DEBUGLOG(("handle_deposit_balance: fee missing\n"));
		iRet = FAILURE;
	}

	if (GetField_CString(hMyHash, "psp_id", &csPspID)) {
DEBUGLOG(("handle_deposit_balance: psp_id [%s]\n", csPspID));
	}
	else {
DEBUGLOG(("handle_deposit_balance: psp_id missing\n"));
		iRet = FAILURE;
	}

	if (GetField_CString(hMyHash, "psp_country", &csPspCountry)) {
DEBUGLOG(("handle_deposit_balance: psp_country [%s]\n", csPspCountry));
	}
	else {
DEBUGLOG(("handle_deposit_balance: psp_country missing\n"));
		iRet = FAILURE;
	}

	if (GetField_CString(hMyHash, "to_ccy", &csToCcy)) {
DEBUGLOG(("handle_deposit_balance: to_ccy [%s]\n", csToCcy));
	}
	else {
DEBUGLOG(("handle_deposit_balance: to_ccy missing\n"));
		iRet = FAILURE;
	}

	if (GetField_Double(hMyHash, "to_amount", &dToAmount)) {
DEBUGLOG(("handle_deposit_balance: to_amount [%lf]\n", dToAmount));
	}
	else {
DEBUGLOG(("handle_deposit_balance: to_amount missing\n"));
		iRet = FAILURE;
	}

	if (GetField_Double(hMyHash, "markup_amt", &dMarkupAmt)) {
DEBUGLOG(("handle_deposit_balance: markup_amt [%lf]\n", dMarkupAmt));
	}
	else {
DEBUGLOG(("handle_deposit_balance: markup_amt missing\n"));
		iRet = FAILURE;
	}

	if (GetField_Double(hMyHash, "precal_fee", &dPreCalFee)) {
DEBUGLOG(("handle_deposit_balance: precal_fee [%lf]\n", dPreCalFee));
	}



	if (iRet == SUCCESS) {
		DBObjPtr = CreateObj(DBPtr,"DBMerchantBalance","GetOpenBalanceForUpdate");
		if ((unsigned long)(*DBObjPtr)(hMerchRec, csMID, csCcy, csCountry, csService) == PD_OK) {
			if (GetField_Double(hMerchRec, "merchant_open_bal", &dTmp)) {
DEBUGLOG(("handle_deposit_balance: merchant_open_bal [%lf]\n", dTmp));
				PutField_Double(hMyHash, "merchant_open_bal", dTmp);
			}
		}
		else {
DEBUGLOG(("handle_deposit_balance: DBMerchantBalance.GetOpenBalanceForUpdate FAIL!\n"));
			iRet = FAILURE;
		}
	}

	if (iRet == SUCCESS) {

		if (GetField_Int(hMyHash, "void_flag", &iVoidFlag)) {
			if (iVoidFlag == PD_TRUE) {
				dAmount = (-1) * (dAmount - dFee - dMarkupAmt);
			}
			else {
				dAmount = dAmount - dFee - dMarkupAmt;
			}
		}
		else {
			dAmount = dAmount - dFee - dMarkupAmt;
		}
DEBUGLOG(("handle_deposit_balance: Merchant amount [%lf]\n", dAmount));


		DBObjPtr = CreateObj(DBPtr, "DBMerchantBalance","UpdateFloat");	
		if ((unsigned long)(*DBObjPtr)(csMID, csCountry, csCcy, csService, dAmount, 0.0, "SYSTEM") == PD_OK) {
DEBUGLOG(("handle_deposit_balance: DBMerchantBalance.UpdateFloat(Balance) SUCC!\n"));
		} else {
DEBUGLOG(("handle_deposit_balance: DBMerchantBalance.UpdateFloat(Balance) FAIL!\n"));
			iRet = FAILURE;
		}

	}

	if (iRet == SUCCESS) {
		if (GetField_Int(hMyHash, "void_flag", &iVoidFlag)) {
			if (iVoidFlag == PD_TRUE) {
				dToAmount = (-1)*(dToAmount + dPreCalFee);
			}
			else {
				dToAmount = dToAmount - dPreCalFee;
			}
		} else {
			dToAmount = dToAmount - dPreCalFee;
		}
DEBUGLOG(("handle_deposit_balance: PSP amount [%lf]\n", dToAmount));

                DBObjPtr = CreateObj(DBPtr, "DBPspBalance","CreditBalance");

		// PD_PSP_FLOAT? PD_PSP_BAL?	
                if ((unsigned long)(*DBObjPtr)(csPspID, csPspCountry, csToCcy, PD_PSP_BAL, dToAmount, "SYSTEM") == PD_OK) {
DEBUGLOG(("handle_deposit_balance: DBPspBalance.UpdateFloat(Balance) SUCC!\n"));
                } else {
DEBUGLOG(("handle_deposit_balance: DBPspBalance.UpdateFloat(Balance) FAIL!\n"));
                        iRet = FAILURE;
                }
	}

	if (iRet == SUCCESS) {
		DBObjPtr = CreateObj(DBPtr, "DBMerchantBalance","GetCurrentValues");
                if ((unsigned long)(*DBObjPtr)(csMID, csCcy, csCountry, csService, hMerchRec) == PD_OK) {
			if (GetField_Double(hMerchRec, "total_float", &dTmp)) {
DEBUGLOG(("handle_deposit_balance: DBMerchantBalance.GetCurrentValues total_float [%lf]!\n", dTmp));
				PutField_Double(hMyHash, "merchant_total_float", dTmp);
			}

			if (GetField_Double(hMerchRec, "current_bal", &dTmp)) {
DEBUGLOG(("handle_deposit_balance: DBMerchantBalance.GetCurrentValues current_bal [%lf]!\n", dTmp));
				PutField_Double(hMyHash, "merchant_current_bal", dTmp);
			}

			if (GetField_Double(hMerchRec, "total_reserved_amount" , &dTmp)) {
DEBUGLOG(("handle_deposit_balance: DBMerchantBalance.GetCurrentValues total_reserved_amount [%lf]!\n", dTmp));
				PutField_Double(hMyHash, "merchant_total_reserved_amount", dTmp);
			}

			if (GetField_Double(hMerchRec, "total_hold", &dTmp)) {
DEBUGLOG(("handle_deposit_balance: DBMerchantBalance.GetCurrentValues total_hold [%lf]!\n", dTmp));
				PutField_Double(hMyHash, "merchant_total_hold", dTmp);
			}

			if (GetField_Double(hMerchRec, "settlement_in_transit", &dTmp)) {
DEBUGLOG(("handle_deposit_balance: DBMerchantBalance.GetCurrentValues settlment_in_transit [%lf]!\n", dTmp));
				PutField_Double(hMyHash, "merchant_settlement_in_transit", dTmp);
			}
		}
		else {
DEBUGLOG(("handle_deposit_balance: DBMerchantBalance.GetCurrentValues FAIL!\n"));
			iRet = FAILURE;
		}	
	}

	if (iRet == SUCCESS) {
		DBObjPtr = CreateObj(DBPtr, "DBPspBalance","GetBalance");
                if ((unsigned long)(*DBObjPtr)(csPspID, csPspCountry, csToCcy, hPspRec) == PD_OK) {
			if (GetField_Double(hPspRec, "balance", &dTmp)) {
DEBUGLOG(("handle_deposit_balance: DBPspBalance.GetBalance balance [%lf]\n", dTmp));
				PutField_Double(hMyHash, "psp_balance", dTmp);
			}
			
			if (GetField_Double(hPspRec, "total_float", &dTmp)) {
DEBUGLOG(("handle_deposit_balance: DBPspBalance.GetBalance total_float [%lf]\n", dTmp));
				PutField_Double(hMyHash, "psp_total_float", dTmp);
			}

			if (GetField_Double(hPspRec, "total_hold", &dTmp)) {
DEBUGLOG(("handle_deposit_balance: DBPspBalance.GetBalance total_hold [%lf]\n", dTmp));
				PutField_Double(hMyHash, "psp_total_hold", dTmp);
			}
		}
		else {
DEBUGLOG(("handle_deposit_balance: DBPspBalance.GetBalance FAIL!\n"));
			iRet = FAILURE;
		}
		
	}

	hash_destroy(hMerchRec);
	hash_destroy(hPspRec);

	FREE_ME(hMerchRec);
	FREE_ME(hPspRec);

	return iRet;
 	
}

