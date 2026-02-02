
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
    "par_run_2.pc"
};


static unsigned int sqlctx = 317467;


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

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,0,0,0,56,184,0,0,1,1,0,1,0,3,102,0,0,
24,0,0,1,104,0,6,192,0,0,3,3,0,1,0,2,3,0,0,1,3,0,0,2,102,0,0,
51,0,0,0,0,0,13,232,0,0,24,1,0,1,0,1,102,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
162,0,0,0,0,0,15,420,0,0,1,1,0,1,0,1,102,0,0,
181,0,0,0,0,0,78,421,0,0,1,1,0,1,0,3,102,0,0,
200,0,0,0,0,0,15,425,0,0,1,1,0,1,0,1,102,0,0,
219,0,0,0,0,0,78,426,0,0,1,1,0,1,0,3,102,0,0,
238,0,0,0,0,0,15,448,0,0,1,1,0,1,0,1,102,0,0,
257,0,0,0,0,0,78,449,0,0,1,1,0,1,0,3,102,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/12/04              Virginia Yun
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include "../batchcommon.h"
#include "common.h"
#include "utilitys.h"
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"
#include "par_run_2.h"
#include "ObjPtr.h"
#include "dbutility.h"

#include "par_deposit_handler_2.h"
#include "par_settlement_handler_2.h"
#include "par_payout_handler_2.h"
#include "par_payout_reversal_handler_2.h"
#include "par_adjustment_handler_2.h"
#include "par_deposit_reserved_handler_2.h"

/*
#include "par_deposit_reserved_handler.h"
*/
#include "pr_bo_funct.h"
#include "pr_par_funct.h"



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

/*
OBJPTR(Txn);
OBJPTR(Channel);
OBJPTR(BO);
*/

char    cDebug;


char    cs_inputfile[PD_MAX_FILE_LEN + 1];
char	cs_process_id[PD_TMP_BUF_LEN + 1];
int	i_process_id = -1;


int parse_arg(int argc,char **argv);
int start_process();
int parse_txn(hash_t *hMyHash);

int batch_init(int argc, char* argv[])
{
	if (argc < 1) {
		printf("usage: -p process_id\n");
		return FAILURE;
	} else {
        	return SUCCESS;
	}
}


int batch_proc(int argc, char* argv[])
{
	int	iRet;

	iRet = parse_arg(argc, argv);

DEBUGLOG(("batch_proc START\n"));

	iRet = start_process();

	return iRet;

}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


                        
int start_process() 
{
	int	iRet = SUCCESS;

	char	csDate[PD_DATE_LEN + 1];
	char	csTmp[PAR_TXN_NOTE_LEN + 1];
	
	int	iCnt;
	hash_t	*myHash;

	myHash = (hash_t*) malloc (sizeof(hash_t));


        /* EXEC SQL WHENEVER SQLERROR GOTO get_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                SQL_CURSOR      c_cursor_txn_data;

		short		hv_return_value;

		int		hv_process_id;
		short		ind_process_id = -1;

		int		v_txn_seq;
		/* varchar		v_post_date[PD_DATE_LEN + PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_post_date;

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
		/* varchar		v_psp_type_code[PAR_PSP_TYPE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_type_code;

		/* varchar		v_psp_order_id[PAR_PSP_TYPE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_order_id;

		/* varchar		v_gate_id[PAR_GATE_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_gate_id;

		/* varchar		v_client_ip[PAR_CLIENT_IP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_client_ip;

		/* varchar		v_txn_note[PAR_TXN_NOTE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[401]; } v_txn_note;

		/* varchar		v_psp_txn_id[PAR_PSP_TXN_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_psp_txn_id;

		/* varchar		v_psp_txn_date[PAR_PSP_TXN_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_psp_txn_date;


		short		ind_txn_seq = -1;
		short		ind_post_date = -1;
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
		short		ind_psp_type_code = -1;
		short		ind_psp_order_id = -1;
		short		ind_gate_id = -1;
		short		ind_client_ip = -1;
		short		ind_txn_note = -1;
		short		ind_psp_txn_id = -1;
		short		ind_psp_txn_date = -1;

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



	hv_process_id = i_process_id;
	ind_process_id = 0;

DEBUGLOG(("process_id = [%d]\n", i_process_id));


	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_par_txn_data(:hv_process_id:ind_process_id, :c_cursor_txn_data);	
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_par_txn_data ( :hv_process_id:\
ind_process_id , :c_cursor_txn_data ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_process_id;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_process_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&c_cursor_txn_data;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
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
			ind_post_date = -1;
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
			ind_psp_type_code = -1;
			ind_psp_order_id = -1;
			ind_gate_id = -1;
			ind_client_ip = -1;
			ind_txn_note = -1;
			ind_psp_txn_id = -1;
			ind_psp_txn_date = -1;
	
			/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_txn_data		
			INTO	:v_txn_seq:ind_txn_seq,
				:v_post_date:ind_post_date,
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
				:v_psp_type_code:ind_psp_type_code,
				:v_psp_order_id:ind_psp_order_id,
				:v_gate_id:ind_gate_id,
				:v_client_ip:ind_client_ip,
				:v_txn_note:ind_txn_note,
				:v_psp_txn_id:ind_psp_txn_id,
				:v_psp_txn_date:ind_psp_txn_date ; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 24;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )51;
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
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_post_date;
                        sqlstm.sqhstl[2] = (unsigned long )17;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_post_date;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_date;
                        sqlstm.sqhstl[3] = (unsigned long )17;
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_txn_date;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_txn_merch_nmb;
                        sqlstm.sqhstl[4] = (unsigned long )53;
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_txn_merch_nmb;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_txn_nmb;
                        sqlstm.sqhstl[5] = (unsigned long )19;
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_txn_nmb;
                        sqlstm.sqinds[5] = (         int  )0;
                        sqlstm.sqharm[5] = (unsigned long )0;
                        sqlstm.sqadto[5] = (unsigned short )0;
                        sqlstm.sqtdso[5] = (unsigned short )0;
                        sqlstm.sqhstv[6] = (unsigned char  *)&v_merch_ref;
                        sqlstm.sqhstl[6] = (unsigned long )53;
                        sqlstm.sqhsts[6] = (         int  )0;
                        sqlstm.sqindv[6] = (         short *)&ind_merch_ref;
                        sqlstm.sqinds[6] = (         int  )0;
                        sqlstm.sqharm[6] = (unsigned long )0;
                        sqlstm.sqadto[6] = (unsigned short )0;
                        sqlstm.sqtdso[6] = (unsigned short )0;
                        sqlstm.sqhstv[7] = (unsigned char  *)&v_txn_type;
                        sqlstm.sqhstl[7] = (unsigned long )53;
                        sqlstm.sqhsts[7] = (         int  )0;
                        sqlstm.sqindv[7] = (         short *)&ind_txn_type;
                        sqlstm.sqinds[7] = (         int  )0;
                        sqlstm.sqharm[7] = (unsigned long )0;
                        sqlstm.sqadto[7] = (unsigned short )0;
                        sqlstm.sqtdso[7] = (unsigned short )0;
                        sqlstm.sqhstv[8] = (unsigned char  *)&v_txn_status;
                        sqlstm.sqhstl[8] = (unsigned long )53;
                        sqlstm.sqhsts[8] = (         int  )0;
                        sqlstm.sqindv[8] = (         short *)&ind_txn_status;
                        sqlstm.sqinds[8] = (         int  )0;
                        sqlstm.sqharm[8] = (unsigned long )0;
                        sqlstm.sqadto[8] = (unsigned short )0;
                        sqlstm.sqtdso[8] = (unsigned short )0;
                        sqlstm.sqhstv[9] = (unsigned char  *)&v_txn_status_grp;
                        sqlstm.sqhstl[9] = (unsigned long )53;
                        sqlstm.sqhsts[9] = (         int  )0;
                        sqlstm.sqindv[9] = (         short *)&ind_txn_status_grp;
                        sqlstm.sqinds[9] = (         int  )0;
                        sqlstm.sqharm[9] = (unsigned long )0;
                        sqlstm.sqadto[9] = (unsigned short )0;
                        sqlstm.sqtdso[9] = (unsigned short )0;
                        sqlstm.sqhstv[10] = (unsigned char  *)&v_to_ccy;
                        sqlstm.sqhstl[10] = (unsigned long )6;
                        sqlstm.sqhsts[10] = (         int  )0;
                        sqlstm.sqindv[10] = (         short *)&ind_to_ccy;
                        sqlstm.sqinds[10] = (         int  )0;
                        sqlstm.sqharm[10] = (unsigned long )0;
                        sqlstm.sqadto[10] = (unsigned short )0;
                        sqlstm.sqtdso[10] = (unsigned short )0;
                        sqlstm.sqhstv[11] = (unsigned char  *)&v_to_amount;
                        sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[11] = (         int  )0;
                        sqlstm.sqindv[11] = (         short *)&ind_to_amount;
                        sqlstm.sqinds[11] = (         int  )0;
                        sqlstm.sqharm[11] = (unsigned long )0;
                        sqlstm.sqadto[11] = (unsigned short )0;
                        sqlstm.sqtdso[11] = (unsigned short )0;
                        sqlstm.sqhstv[12] = (unsigned char  *)&v_ccy;
                        sqlstm.sqhstl[12] = (unsigned long )6;
                        sqlstm.sqhsts[12] = (         int  )0;
                        sqlstm.sqindv[12] = (         short *)&ind_ccy;
                        sqlstm.sqinds[12] = (         int  )0;
                        sqlstm.sqharm[12] = (unsigned long )0;
                        sqlstm.sqadto[12] = (unsigned short )0;
                        sqlstm.sqtdso[12] = (unsigned short )0;
                        sqlstm.sqhstv[13] = (unsigned char  *)&v_amount;
                        sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[13] = (         int  )0;
                        sqlstm.sqindv[13] = (         short *)&ind_amount;
                        sqlstm.sqinds[13] = (         int  )0;
                        sqlstm.sqharm[13] = (unsigned long )0;
                        sqlstm.sqadto[13] = (unsigned short )0;
                        sqlstm.sqtdso[13] = (unsigned short )0;
                        sqlstm.sqhstv[14] = (unsigned char  *)&v_fee;
                        sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[14] = (         int  )0;
                        sqlstm.sqindv[14] = (         short *)&ind_fee;
                        sqlstm.sqinds[14] = (         int  )0;
                        sqlstm.sqharm[14] = (unsigned long )0;
                        sqlstm.sqadto[14] = (unsigned short )0;
                        sqlstm.sqtdso[14] = (unsigned short )0;
                        sqlstm.sqhstv[15] = (unsigned char  *)&v_ex_rate;
                        sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[15] = (         int  )0;
                        sqlstm.sqindv[15] = (         short *)&ind_ex_rate;
                        sqlstm.sqinds[15] = (         int  )0;
                        sqlstm.sqharm[15] = (unsigned long )0;
                        sqlstm.sqadto[15] = (unsigned short )0;
                        sqlstm.sqtdso[15] = (unsigned short )0;
                        sqlstm.sqhstv[16] = (unsigned char  *)&v_markup_amt;
                        sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[16] = (         int  )0;
                        sqlstm.sqindv[16] = (         short *)&ind_markup_amt;
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
                        sqlstm.sqhstv[21] = (unsigned char  *)&v_txn_note;
                        sqlstm.sqhstl[21] = (unsigned long )403;
                        sqlstm.sqhsts[21] = (         int  )0;
                        sqlstm.sqindv[21] = (         short *)&ind_txn_note;
                        sqlstm.sqinds[21] = (         int  )0;
                        sqlstm.sqharm[21] = (unsigned long )0;
                        sqlstm.sqadto[21] = (unsigned short )0;
                        sqlstm.sqtdso[21] = (unsigned short )0;
                        sqlstm.sqhstv[22] = (unsigned char  *)&v_psp_txn_id;
                        sqlstm.sqhstl[22] = (unsigned long )33;
                        sqlstm.sqhsts[22] = (         int  )0;
                        sqlstm.sqindv[22] = (         short *)&ind_psp_txn_id;
                        sqlstm.sqinds[22] = (         int  )0;
                        sqlstm.sqharm[22] = (unsigned long )0;
                        sqlstm.sqadto[22] = (unsigned short )0;
                        sqlstm.sqtdso[22] = (unsigned short )0;
                        sqlstm.sqhstv[23] = (unsigned char  *)&v_psp_txn_date;
                        sqlstm.sqhstl[23] = (unsigned long )17;
                        sqlstm.sqhsts[23] = (         int  )0;
                        sqlstm.sqindv[23] = (         short *)&ind_psp_txn_date;
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

			if (ind_post_date >= 0) {
				v_post_date.arr[v_post_date.len] = '\0';
//DEBUGLOG(("start_process: [%d] post_date = [%.*s]\n",iCnt, v_post_date.len,v_post_date.arr));
	
				strncpy(csDate, (const char *)v_post_date.arr, PD_DATE_LEN);
				csDate[PD_DATE_LEN] = '\0';
//DEBUGLOG(("start_process: [%d] re-format post_date = [%s]\n",iCnt, csDate));

				PutField_CString(myHash, "post_date", (const char *) csDate);
				PutField_CString(myHash, "post_datetime", (const char*)v_post_date.arr);
			}
			

			if (ind_txn_date >= 0) {
				v_txn_date.arr[v_txn_date.len] = '\0';
//DEBUGLOG(("start_process: [%d] txn_date = [%.*s]\n",iCnt, v_txn_date.len,v_txn_date.arr));
				PutField_CString(myHash, "txn_date", (const char *) v_txn_date.arr);
			}

			if (ind_txn_merch_nmb >= 0) {
				v_txn_merch_nmb.arr[v_txn_merch_nmb.len] = '\0';
//DEBUGLOG(("start_process: [%d] txn_merch_nmb = [%.*s]\n",iCnt, v_txn_merch_nmb.len,v_txn_merch_nmb.arr));
				PutField_CString(myHash, "txn_merch_nmb", (const char *) v_txn_merch_nmb.arr);
			}

			if (ind_txn_nmb >= 0) {
				v_txn_nmb.arr[v_txn_nmb.len] = '\0';
//DEBUGLOG(("start_process: [%d] txn_nmb = [%.*s]\n",iCnt, v_txn_nmb.len,v_txn_nmb.arr));
				PutField_CString(myHash, "txn_nmb", (const char *) v_txn_nmb.arr);
			}

			if (ind_merch_ref >=0) {
				v_merch_ref.arr[v_merch_ref.len] = '\0';
//DEBUGLOG(("start_process: [%d] merch_ref = [%.*s]\n",iCnt, v_merch_ref.len, v_merch_ref.arr));
				PutField_CString(myHash, "merch_ref", (const char *) v_merch_ref.arr);
			}
		
			if (ind_txn_type >=0) {
				v_txn_type.arr[v_txn_type.len] = '\0';
//DEBUGLOG(("start_process: [%d] txn_type = [%.*s]\n",iCnt, v_txn_type.len, v_txn_type.arr));
				PutField_CString(myHash, "txn_type", (const char *) v_txn_type.arr);
			}

			if (ind_txn_status >=0) {
				v_txn_status.arr[v_txn_status.len] = '\0';
//DEBUGLOG(("start_process: [%d] txn_status = [%.*s]\n",iCnt, v_txn_status.len, v_txn_status.arr));
				PutField_CString(myHash, "txn_status", (const char *) v_txn_status.arr);
			}

			if (ind_txn_status_grp >=0) {
				v_txn_status_grp.arr[v_txn_status_grp.len] = '\0';
//DEBUGLOG(("start_process: [%d] txn_status_grp = [%.*s]\n",iCnt, v_txn_status_grp.len, v_txn_status_grp.arr));
				PutField_CString(myHash, "txn_status_grp", (const char *) v_txn_status_grp.arr);
			}

			if (ind_to_ccy >=0) {
				v_to_ccy.arr[v_to_ccy.len] = '\0';
//DEBUGLOG(("start_process: [%d] to_ccy = [%.*s]\n",iCnt, v_to_ccy.len, v_to_ccy.arr));
				PutField_CString(myHash, "to_ccy", (const char *) v_to_ccy.arr);
			}

			if (ind_to_amount >=0) {
//DEBUGLOG(("start_process: [%d] to_amount = [%lf]\n",iCnt, v_to_amount));
				PutField_Double(myHash, "to_amount", v_to_amount);
			}

			if (ind_ccy >=0) {
				v_ccy.arr[v_ccy.len] = '\0';
//DEBUGLOG(("start_process: [%d] ccy = [%.*s]\n",iCnt, v_ccy.len, v_ccy.arr));
				PutField_CString(myHash, "ccy", (const char *) v_ccy.arr);
			}

			if (ind_amount >=0) {
//DEBUGLOG(("start_process: [%d] amount = [%lf]\n",iCnt, v_amount));
				PutField_Double(myHash, "amount", v_amount);
			}

			if (ind_fee >=0) {
//DEBUGLOG(("start_process: [%d] fee = [%lf]\n",iCnt, v_fee));
				PutField_Double(myHash, "fee", v_fee);
			}

			if (ind_ex_rate >= 0) {
//DEBUGLOG(("start_process: [%d] ex_rate = [%lf]\n",iCnt, v_ex_rate));
				PutField_Double(myHash, "ex_rate", v_ex_rate);
			}

			if (ind_markup_amt >= 0) {
//DEBUGLOG(("start_process: [%d] markup_amt = [%lf]\n",iCnt, v_markup_amt));
				PutField_Double(myHash, "markup_amt", v_markup_amt);
			}

			if (ind_psp_type_code >= 0) {
				v_psp_type_code.arr[v_psp_type_code.len] = '\0';
//DEBUGLOG(("start_process: [%d] psp_type_code = [%.*s]\n",iCnt, v_psp_type_code.len, v_psp_type_code.arr));
				PutField_CString(myHash, "psp_type_code", (const char *) v_psp_type_code.arr);
			}
		
			if (ind_psp_order_id >= 0) {
				v_psp_order_id.arr[v_psp_order_id.len] = '\0';
//DEBUGLOG(("start_process: [%d] psp_order_id = [%.*s]\n",iCnt, v_psp_order_id.len, v_psp_order_id.arr));
				PutField_CString(myHash, "psp_order_id", (const char *) v_psp_order_id.arr);
			}

			if (ind_gate_id >= 0) {
				v_gate_id.arr[v_gate_id.len] = '\0';
//DEBUGLOG(("start_process: [%d] gate_id = [%.*s]\n",iCnt, v_gate_id.len, v_gate_id.arr));
				PutField_CString(myHash, "gate_id", (const char *) v_gate_id.arr);
			}
			
			if (ind_client_ip >= 0) {
				v_client_ip.arr[v_client_ip.len] = '\0';
//DEBUGLOG(("start_process: [%d] client_ip = [%.*s]\n",iCnt, v_client_ip.len, v_client_ip.arr));
				PutField_CString(myHash, "client_ip", (const char *) v_client_ip.arr);
			}	

			if (ind_txn_note >= 0) {
				v_txn_note.arr[v_txn_note.len] = '\0';
//DEBUGLOG(("start_process: [%d] txn_note = [%.*s]\n",iCnt, v_txn_note.len, v_txn_note.arr));
				strncpy(csTmp, (const char *) v_txn_note.arr, PD_REMARK_LEN);
				csTmp[PD_REMARK_LEN] = '\0';
	
				PutField_CString(myHash, "remark", (const char *) csTmp);
			}	
			
			if (ind_psp_txn_id >= 0) {
				v_psp_txn_id.arr[v_psp_txn_id.len] = '\0';
//DEBUGLOG(("start_process: [%d] psp_txn_id = [%.*s]\n",iCnt, v_psp_txn_id.len, v_psp_txn_id.arr));
				PutField_CString(myHash, "psp_tid", (const char *) v_psp_txn_id.arr);
			}	

			if (ind_psp_txn_date >= 0) {
				v_psp_txn_date.arr[v_psp_txn_date.len] = '\0';
//DEBUGLOG(("start_process: [%d] psp_txn_date = [%.*s]\n",iCnt, v_psp_txn_date.len, v_psp_txn_date.arr));

				strncpy(csDate, (const char *)v_psp_txn_date.arr, PD_DATE_LEN);
				csDate[PD_DATE_LEN] = '\0';

				PutField_CString(myHash, "psp_txn_date", (const char *) csDate);
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
  sqlstm.arrsiz = 24;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )162;
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


 	        /* EXEC SQL FREE :c_cursor_txn_data; */ 

{
          struct sqlexd sqlstm;
          sqlstm.sqlvsn = 12;
          sqlstm.arrsiz = 24;
          sqlstm.sqladtp = &sqladt;
          sqlstm.sqltdsp = &sqltds;
          sqlstm.stmt = "";
          sqlstm.iters = (unsigned int  )1;
          sqlstm.offset = (unsigned int  )181;
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
  sqlstm.arrsiz = 24;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )200;
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


                /* EXEC SQL FREE :c_cursor_txn_data; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 24;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )219;
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
ERRLOG("start_process: exit with error\n");
                iRet = FAILURE;
	
	}
	
	//EXEC SQL CLOSE :c_cursor_txn_data;
        //EXEC SQL FREE :c_cursor_txn_data;
DEBUGLOG(("start_process: FINAL RET = [%d]\n", iRet));

	FREE_ME(myHash);


	return iRet;

get_error:
DEBUGLOG(("get_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));

ERRLOG("start_process: error_code %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE :c_cursor_txn_data; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 24;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )238;
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


    /* EXEC SQL FREE :c_cursor_txn_data; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 24;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )257;
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

	//char	csPostDate[PD_SP_VALUE_LEN + 1];
	//char	csCutOffDate[PD_SP_VALUE_LEN + 1];

	char	csAutoRecon[PD_SP_VALUE_LEN + 1];
	char	cTmp;

        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	char    *csCode = strdup("");
	char    *csValue= strdup("");

/*	 hash_t  *hRec; */

DEBUGLOG(("parse_txn: BEGIN\n"));


        ct = time((time_t *) 0);
        sct = localtime(&ct);

	
	sys_date[0] = '\0';
	sys_time[0] = '\0';
	csTranDateTime[0] = '\0';

        sprintf(sys_date, "%04d%02d%02d",
                sct->tm_year + 1900, sct->tm_mon + 1, sct->tm_mday);

        sprintf(sys_time, "%02d%02d%02d",
                sct->tm_hour, sct->tm_min, sct->tm_sec);

//DEBUGLOG(("parse_txn: sys_date [%s] sys_time [%s]\n", sys_date, sys_time));

        PutField_CString(hMyHash, "local_tm_date", sys_date);
        PutField_CString(hMyHash, "local_tm_time", sys_time);
	

	if (ParDefMisc_GetValue(PAR_AUTO_RECON, csAutoRecon) == FOUND) {
//DEBUGLOG(("parse_txn: Auto Recon [%s]\n", csAutoRecon));
		cTmp = csAutoRecon[0];

		PutField_Char(hMyHash, "auto_recon", cTmp);
	} else {
DEBUGLOG(("parse_txn: ParDefMisc_GetValue FAIL (Auto-Recon)!!\n"));
		iRet = FAILURE;
	}

	if (iRet == SUCCESS) {
/*
		DBObjPtr = CreateObj(DBPtr,"DBSystemControl","GetAllCodes");
		if ((*DBObjPtr)(rRecordSet) == PD_OK) {
DEBUGLOG(("parse_txn:: return \n"));
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
                        	if (GetField_CString(hRec,"code",&csCode)) {
                                	if (GetField_CString(hRec,"value",&csValue)) {
                                        	if (!strcmp(csCode,"CTPHDATE")) {
DEBUGLOG(("UpdateContext:Current Processor Hub Date= [%s]\n",csValue));
                                                	PutField_CString(hMyHash,"txn_date",csValue);
                                        	}
                                	}
                        	}
	                        hRec = RecordSet_GetNext(rRecordSet);
			}
		}
*/
		char csTmpDate[PD_DATETIME_LEN +1];
        	DBObjPtr = CreateObj(DBPtr,"DBSystemControl","FindCode");

        	if ((unsigned long)(*DBObjPtr)("CTPHDATE",csTmpDate) == FOUND) {
DEBUGLOG(("UpdateContext:Current Processor Hub Date= [%s]\n",csTmpDate));
                       	PutField_CString(hMyHash,"txn_date",csTmpDate);
        	}
        }


	if (iRet == SUCCESS) {
		if (GetField_CString(hMyHash, "txn_type", &csPreTxnType)) {
//DEBUGLOG(("parse_txn: txn_type [%s]\n", csPreTxnType));

			if (ParCategory_GetCategory(csPreTxnType, hMyHash) == PD_OK) {

				if (GetField_CString(hMyHash, "category", &csCategory)) {
DEBUGLOG(("parse_txn: category [%s]\n", csCategory));
				}
				if (GetField_CString(hMyHash, "txn_code", &csTmp)) {
//DEBUGLOG(("parse_txn: txn_code [%s]\n", csTmp));
				}
				if (GetField_CString(hMyHash, "reversal_txn_code", &csTmp)) {
//DEBUGLOG(("parse_txn: reversal_txn_code [%s]\n", csTmp));
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
		GetField_CString(hMyHash, "txn_status", &csTmp);
		if (strcmp(csTmp, "NEW")) {
			if (!strcmp(csCategory, PAR_CAT_DEPOSIT)) {
DEBUGLOG(("parse_txn:: process Deposit!!\n"));
				iRet = deposit_handler_2(hMyHash);
			}	 
			else if (!strcmp(csCategory, PAR_CAT_SETTLEMENT)) {
				iRet = settlement_handler_2(hMyHash);
			} 
			else if (!strcmp(csCategory, PAR_CAT_ADJUSTEMENT)) {
				//iRet = adjustment_handler_2(hMyHash);
				iRet = UpdateProcessResult(hMyHash, "ADJ-SKIP");
			}
			else if (!strcmp(csCategory, PAR_CAT_PAYOUT)) {
				iRet = payout_handler_2(hMyHash);
			} 
			else if (!strcmp(csCategory, PAR_CAT_PAYOUT_REVERSAL)) {
				//iRet = payout_reversal_handler_2(hMyHash);
				iRet = UpdateProcessResult(hMyHash, "PORV-SKIP");
			} 
			else if (!strcmp(csCategory, PAR_CAT_RESERVE)) {
				iRet = deposit_reserved_handler_2(hMyHash);
				//iRet = UpdateProcessResult(hMyHash, "RES-SKIP");
			}
			else {
DEBUGLOG(("parse_txn: not defined category [%s]\n", csCategory));
				iRet = FAILURE;
			}
		}
		else {
DEBUGLOG(("parse_txn: SKIP....\n"));
			iRet = UpdateProcessResult(hMyHash, "NEW-SKIP");
		}


		if (iRet == SUCCESS) {
			TxnCommit();
		}
		else {
			TxnAbort();
		}
	}

        RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);

	FREE_ME(csCode);
	FREE_ME(csValue);

	return iRet;
}



int parse_arg(int argc,char **argv)
{
        char    c;

	strcpy(cs_process_id, "");

        while ((c = getopt(argc,argv,"p:")) != EOF) {
                switch (c) {
                        case 'p':
                                strcpy(cs_process_id, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_process_id,"")) {
                return FAILURE;
	} else {

		i_process_id = atoi(cs_process_id);
DEBUGLOG(("process_id [%d]\n", i_process_id));

		if (i_process_id < 0) {
			return FAILURE;
		}
		
	}

        return SUCCESS;
}
