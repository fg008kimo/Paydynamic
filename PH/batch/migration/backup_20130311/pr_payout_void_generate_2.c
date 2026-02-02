
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
           char  filnam[29];
};
static struct sqlcxp sqlfpn =
{
    28,
    "pr_payout_void_generate_2.pc"
};


static unsigned int sqlctx = 558977851;


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

 static char *sq0002 = 
"select prh_file_psp  from par_po_reversed_hd ,par_po_reversed_dt ,par_payou\
t_upload where (((pu_batch_id=:b0 and prd_po_file_id=pu_file_id) and prd_seq_\
nmb=:b1) and prd_psp_file_id=prh_file_id)           ";

 static char *sq0004 = 
"select tp_service_fee  from txn_psp_detail ,payout_generated_file_hd ,payou\
t_generated_file_dt where ((fd_upload_txn_id=:b0 and fd_file_id=fh_file_id) a\
nd fh_txn_id=tp_txn_id)           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,0,0,0,56,145,0,0,1,1,0,1,0,3,102,0,0,
24,0,0,1,80,0,6,147,0,0,2,2,0,1,0,2,3,0,0,2,102,0,0,
47,0,0,0,0,0,13,189,0,0,24,1,0,1,0,1,102,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
158,0,0,0,0,0,15,381,0,0,1,1,0,1,0,1,102,0,0,
177,0,0,0,0,0,78,382,0,0,1,1,0,1,0,3,102,0,0,
196,0,0,0,0,0,15,386,0,0,1,1,0,1,0,1,102,0,0,
215,0,0,0,0,0,78,387,0,0,1,1,0,1,0,3,102,0,0,
234,0,0,0,0,0,15,406,0,0,1,1,0,1,0,1,102,0,0,
253,0,0,0,0,0,78,407,0,0,1,1,0,1,0,3,102,0,0,
272,0,0,2,204,0,9,906,0,0,2,2,0,1,0,1,9,0,0,1,3,0,0,
295,0,0,2,0,0,13,908,0,0,1,0,0,1,0,2,9,0,0,
314,0,0,2,0,0,15,934,0,0,0,0,0,1,0,
329,0,0,2,0,0,15,944,0,0,0,0,0,1,0,
344,0,0,3,0,0,17,1005,0,0,1,1,0,1,0,1,9,0,0,
363,0,0,3,0,0,21,1006,0,0,0,0,0,1,0,
378,0,0,4,186,0,9,1048,0,0,1,1,0,1,0,1,9,0,0,
397,0,0,4,0,0,13,1050,0,0,1,0,0,1,0,2,4,0,0,
416,0,0,4,0,0,15,1066,0,0,0,0,0,1,0,
431,0,0,4,0,0,15,1076,0,0,0,0,0,1,0,
446,0,0,5,162,0,4,1105,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/12/31              Virginia Yun
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
#include "numutility.h"
#include "myrecordset.h"
#include "../batchcommon.h"
#include "TxnSeq.h"
#include "pr_payout_void_generate_2.h"
#include "internal.h"
#include "ObjPtr.h"
#include "pr_bo_funct.h"
#include "pr_par_funct.h"
#include "pr_log_funct.h"
#include "dbutility.h"
#include "pr_par_funct_2.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug = 'Y';

OBJPTR(DB);
OBJPTR(Txn);


int parse_txn(hash_t   *hMyHash);
int process_payout_psp_reversal(hash_t * hMyHash);
int GetPayoutReversedPSP(const char *csBatchId, int iSeqNum, recordset_t *myRec);
int CreateNewVOGTxn(hash_t *hMyHash);
int UpdateLogs(hash_t *hMyHash);
int UpdateByGenId(const hash_t *hRec);
int	GetPayoutServiceFee(const char *csUploadTxnId , hash_t *hTxn);
int	Reversed_record_exists(const char *csBatchId, int iSeqNum);
int	PSP_Reversal_Handle(hash_t *hMyHash);

int batch_init(int argc, char* argv[])
{
/*
    if (argc < 2) {
        printf("usage:  -h header_file -t detail_file\n");
        return FAILURE;
    }
    else
        return SUCCESS;
*/


	return SUCCESS;

}



int batch_proc(int argc, char* argv[])
{

	int	iRet = SUCCESS;

	int	iCnt = 0;
        char    csDate[PD_DATE_LEN + 1];

        hash_t  *myHash;
        myHash = (hash_t*) malloc (sizeof(hash_t));


	/* EXEC SQL WHENEVER SQLERROR GOTO get_void_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                SQL_CURSOR      c_cursor_txn_data;

                short           hv_return_value;
                int             v_txn_seq;
                /* varchar         v_post_date[PD_DATE_LEN + PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_post_date;

                /* varchar         v_txn_date[PD_DATE_LEN + PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_txn_date;

                /* varchar         v_txn_merch_nmb[PAR_TXN_MERCH_NMB_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_merch_nmb;

                /* varchar         v_txn_nmb[PAR_TXN_NMB_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_nmb;

                /* varchar         v_merch_ref[PD_MERCHANT_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merch_ref;

                /* varchar         v_txn_type[PAR_TXN_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_type;

                /* varchar         v_txn_status[PAR_TXN_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_status;

                /* varchar         v_txn_status_grp[PAR_TXN_STATUS_GRP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_status_grp;

                /* varchar         v_to_ccy[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_to_ccy;

                double          v_to_amount;
                /* varchar         v_ccy[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ccy;

                double          v_amount;
                double          v_fee;
                double          v_ex_rate;
                double          v_markup_amt;
                //double                v_balance;
                /* varchar         v_psp_type_code[PAR_PSP_TYPE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_type_code;

                /* varchar         v_psp_order_id[PAR_PSP_TYPE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_order_id;

                /* varchar         v_gate_id[PAR_GATE_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_gate_id;

                /* varchar         v_client_ip[PAR_CLIENT_IP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_client_ip;

                /* varchar         v_txn_note[PAR_TXN_NOTE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_note;

                /* varchar         v_psp_txn_id[PAR_PSP_TXN_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_psp_txn_id;

                /* varchar         v_psp_txn_date[PAR_PSP_TXN_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_psp_txn_date;


                short           ind_txn_seq = -1;
                short           ind_post_date = -1;
                short           ind_txn_date = -1;
                short           ind_txn_merch_nmb = -1;
                short           ind_txn_nmb = -1;
                short           ind_merch_ref = -1;
                short           ind_txn_type = -1;
                short           ind_txn_status = -1;
                short           ind_txn_status_grp = -1;
                short           ind_to_ccy = -1;
                short           ind_to_amount = -1;
                short           ind_ccy = -1;
                short           ind_amount = -1;
                short           ind_fee = -1;
                short           ind_ex_rate = -1;
                short           ind_markup_amt = -1;
                //short         ind_balance = -1;
                short           ind_psp_type_code = -1;
                short           ind_psp_order_id = -1;                
		short           ind_gate_id = -1;
                short           ind_client_ip = -1;
                short           ind_txn_note = -1;
                short           ind_psp_txn_id = -1;
                short           ind_psp_txn_date = -1;

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
        if (sqlca.sqlcode < 0) goto get_void_error;
}



        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_par_void_po_txn_data(:c_cursor_txn_data);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_par_void_po_txn_data ( \
:c_cursor_txn_data ) ; END ;";
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
        if (sqlca.sqlcode < 0) goto get_void_error;
}



        if (hv_return_value == 1) {
DEBUGLOG(("batch_proc:get_txn no more record to be processed!\n"));
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
                        //ind_balance = -1;
                        ind_psp_type_code = -1;
                        ind_psp_order_id = -1;
                        ind_gate_id = -1;
                        ind_client_ip = -1;
                        ind_txn_note = -1;
                        ind_txn_note = -1;
                        ind_psp_txn_id = -1;
                        ind_psp_txn_date = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_txn_data
                        INTO    :v_txn_seq:ind_txn_seq,
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
                        sqlstm.sqhstl[21] = (unsigned long )53;
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
                        if (sqlca.sqlcode < 0) goto get_void_error;
}



                        if (SQLCODE == SQL_NOT_FOUND) {
                                break;
                        }



DEBUGLOG(("batch_proc >>>>>>>>>>>>>>>>>>>>>>>>>\n"));

                        if (ind_txn_seq >= 0) {
DEBUGLOG(("batch_proc: [%d] sort_txn_seq = [%d]\n", iCnt, v_txn_seq));
                                PutField_Int(myHash, "sort_txn_seq", v_txn_seq);
                        }

                        if (ind_post_date >= 0) {
                                v_post_date.arr[v_post_date.len] = '\0';
DEBUGLOG(("batch_proc: [%d] post_date = [%.*s]\n",iCnt, v_post_date.len,v_post_date.arr));

                                strncpy(csDate, (const char *)v_post_date.arr, PD_DATE_LEN);
                                csDate[PD_DATE_LEN] = '\0';
//DEBUGLOG(("batch_proc: [%d] re-format post_date = [%s]\n",iCnt, csDate));

                                PutField_CString(myHash, "post_date", (const char *) csDate);
                                PutField_CString(myHash, "post_datetime", (const char*)v_post_date.arr);
                        }


                        if (ind_txn_date >= 0) {
                                v_txn_date.arr[v_txn_date.len] = '\0';
DEBUGLOG(("batch_proc: [%d] txn_date = [%.*s]\n",iCnt, v_txn_date.len,v_txn_date.arr));
                                PutField_CString(myHash, "txn_date", (const char *) v_txn_date.arr);
                        }
                        if (ind_txn_merch_nmb >= 0) {
                                v_txn_merch_nmb.arr[v_txn_merch_nmb.len] = '\0';
DEBUGLOG(("batch_proc: [%d] txn_merch_nmb = [%.*s]\n",iCnt, v_txn_merch_nmb.len,v_txn_merch_nmb.arr));
                                PutField_CString(myHash, "txn_merch_nmb", (const char *) v_txn_merch_nmb.arr);
                        }

                        if (ind_txn_nmb >= 0) {
                                v_txn_nmb.arr[v_txn_nmb.len] = '\0';
DEBUGLOG(("batch_proc: [%d] txn_nmb = [%.*s]\n",iCnt, v_txn_nmb.len,v_txn_nmb.arr));
                                PutField_CString(myHash, "txn_nmb", (const char *) v_txn_nmb.arr);
                        }

                        if (ind_merch_ref >=0) {
                                v_merch_ref.arr[v_merch_ref.len] = '\0';
//DEBUGLOG(("batch_proc: [%d] merch_ref = [%.*s]\n",iCnt, v_merch_ref.len, v_merch_ref.arr));
                                PutField_CString(myHash, "merch_ref", (const char *) v_merch_ref.arr);
                        }

                        if (ind_txn_type >=0) {
                                v_txn_type.arr[v_txn_type.len] = '\0';
DEBUGLOG(("batch_proc: [%d] txn_type = [%.*s]\n",iCnt, v_txn_type.len, v_txn_type.arr));
                                PutField_CString(myHash, "txn_type", (const char *) v_txn_type.arr);
                        }

                        if (ind_txn_status >=0) {
                                v_txn_status.arr[v_txn_status.len] = '\0';
DEBUGLOG(("batch_proc: [%d] txn_status = [%.*s]\n",iCnt, v_txn_status.len, v_txn_status.arr));
                                PutField_CString(myHash, "txn_status", (const char *) v_txn_status.arr);
                        }

                        if (ind_txn_status_grp >=0) {
                                v_txn_status_grp.arr[v_txn_status_grp.len] = '\0';
DEBUGLOG(("batch_proc: [%d] txn_status_grp = [%.*s]\n",iCnt, v_txn_status_grp.len, v_txn_status_grp.arr));
                                PutField_CString(myHash, "txn_status_grp", (const char *) v_txn_status_grp.arr);
                        }

                        if (ind_to_ccy >=0) {
                                v_to_ccy.arr[v_to_ccy.len] = '\0';
//DEBUGLOG(("batch_proc: [%d] to_ccy = [%.*s]\n",iCnt, v_to_ccy.len, v_to_ccy.arr));
                                PutField_CString(myHash, "to_ccy", (const char *) v_to_ccy.arr);
                        }

                        if (ind_to_amount >=0) {
//DEBUGLOG(("batch_proc: [%d] to_amount = [%lf]\n",iCnt, v_to_amount));
                                PutField_Double(myHash, "to_amount", v_to_amount);
                        }

                        if (ind_ccy >=0) {
                                v_ccy.arr[v_ccy.len] = '\0';
//DEBUGLOG(("batch_proc: [%d] ccy = [%.*s]\n",iCnt, v_ccy.len, v_ccy.arr));
                                PutField_CString(myHash, "ccy", (const char *) v_ccy.arr);
                        }

                        if (ind_amount >=0) {
//DEBUGLOG(("batch_proc: [%d] amount = [%lf]\n",iCnt, v_amount));
                                PutField_Double(myHash, "amount", v_amount);
                        }

                        if (ind_fee >=0) {
//DEBUGLOG(("batch_proc: [%d] fee = [%lf]\n",iCnt, v_fee));
                                PutField_Double(myHash, "fee", v_fee);
                        }

                        if (ind_ex_rate >= 0) {
//DEBUGLOG(("batch_proc: [%d] ex_rate = [%lf]\n",iCnt, v_ex_rate));
                                PutField_Double(myHash, "ex_rate", v_ex_rate);
                        }

                        if (ind_markup_amt >= 0) {
//DEBUGLOG(("batch_proc: [%d] markup_amt = [%lf]\n",iCnt, v_markup_amt));
                                PutField_Double(myHash, "markup_amt", v_markup_amt);
                        }

                        /*
                        if (ind_balance >= 0) {
DEBUGLOG(("batch_proc: [%d] balance = [%lf]\n",iCnt, v_balance));
                                PutField_Double(myHash, "balance", v_balance);
                        }
                        */
                        if (ind_psp_type_code >= 0) {
                                v_psp_type_code.arr[v_psp_type_code.len] = '\0';
DEBUGLOG(("batch_proc: [%d] psp_type_code = [%.*s]\n",iCnt, v_psp_type_code.len, v_psp_type_code.arr));
                                PutField_CString(myHash, "psp_type_code", (const char *) v_psp_type_code.arr);
                        }

                        if (ind_psp_order_id >= 0) {
                                v_psp_order_id.arr[v_psp_order_id.len] = '\0';
//DEBUGLOG(("batch_proc: [%d] psp_order_id = [%.*s]\n",iCnt, v_psp_order_id.len, v_psp_order_id.arr));
                                PutField_CString(myHash, "psp_order_id", (const char *) v_psp_order_id.arr);
                        }

                        if (ind_gate_id >= 0) {
                                v_gate_id.arr[v_gate_id.len] = '\0';
DEBUGLOG(("batch_proc: [%d] gate_id = [%.*s]\n",iCnt, v_gate_id.len, v_gate_id.arr));
                                PutField_CString(myHash, "gate_id", (const char *) v_gate_id.arr);
                        }

                        if (ind_client_ip >= 0) {
                                v_client_ip.arr[v_client_ip.len] = '\0';
//DEBUGLOG(("batch_proc: [%d] client_ip = [%.*s]\n",iCnt, v_client_ip.len, v_client_ip.arr));
                                PutField_CString(myHash, "client_ip", (const char *) v_client_ip.arr);
                        }      

                        if (ind_txn_note >= 0) {
                                v_txn_note.arr[v_txn_note.len] = '\0';
DEBUGLOG(("batch_proc: [%d] txn_note = [%.*s]\n",iCnt, v_txn_note.len, v_txn_note.arr));
                                PutField_CString(myHash, "remark", (const char *) v_txn_note.arr);
                        }      

                        if (ind_psp_txn_id >= 0) {
                                v_psp_txn_id.arr[v_psp_txn_id.len] = '\0';
DEBUGLOG(("batch_proc: [%d] psp_txn_id = [%.*s]\n",iCnt, v_psp_txn_id.len, v_psp_txn_id.arr));
                                PutField_CString(myHash, "psp_tid", (const char *) v_psp_txn_id.arr);
                        }      

                        if (ind_psp_txn_date >= 0) {
                                v_psp_txn_date.arr[v_psp_txn_date.len] = '\0';
DEBUGLOG(("batch_proc: [%d] psp_txn_date = [%.*s]\n",iCnt, v_psp_txn_date.len, v_psp_txn_date.arr));

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
                sqlstm.offset = (unsigned int  )158;
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
                if (sqlca.sqlcode < 0) goto get_void_error;
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
                sqlstm.offset = (unsigned int  )177;
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
                if (sqlca.sqlcode < 0) goto get_void_error;
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
                sqlstm.offset = (unsigned int  )196;
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
                if (sqlca.sqlcode < 0) goto get_void_error;
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
                sqlstm.offset = (unsigned int  )215;
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
                if (sqlca.sqlcode < 0) goto get_void_error;
}


DEBUGLOG(("batch_proc: exit with error\n"));
ERRLOG("batch_proc: exit with error\n");
                iRet = FAILURE;

        }

DEBUGLOG(("batch_proc: FINAL RET = [%d]\n", iRet));

        FREE_ME(myHash);

        return iRet;

get_void_error:
DEBUGLOG(("get_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));

ERRLOG("batch_proc: error_code %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE :c_cursor_txn_data; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 24;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )234;
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
    sqlstm.offset = (unsigned int  )253;
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


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}



/*
int parse_arg(int argc,char **argv)
{
	char    c;
	strcpy(cs_dtfile,"");
	strcpy(cs_hdfile,"");

	while ((c = getopt(argc,argv,"h:t:d:")) != EOF) {
		switch (c) {
			case 'h':
				strcpy(cs_hdfile, optarg);
				break;
			case 't':
				strcpy(cs_dtfile, optarg);
				break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(cs_hdfile,"") || !strcmp(cs_dtfile,""))
		return FAILURE;

        return SUCCESS;
}
*/


int parse_txn(hash_t   *hMyHash) {

	int	iRet = SUCCESS;

	char	*csTmp;

        time_t  ct;
        struct  tm *sct;
        char    sys_date[PD_DATE_LEN + 1];
        char    sys_time[PD_TIME_LEN + 1];
        char    csTranDateTime[PD_DATE_LEN + PD_TIME_LEN + 1];

        ct = time((time_t *) 0);
        sct = localtime(&ct);

        sys_date[0] = '\0';
        sys_time[0] = '\0';
        csTranDateTime[0] = '\0';

        sprintf(sys_date, "%04d%02d%02d",
                sct->tm_year + 1900, sct->tm_mon + 1, sct->tm_mday);

        sprintf(sys_time, "%02d%02d%02d",
                sct->tm_hour, sct->tm_min, sct->tm_sec);

        PutField_CString(hMyHash, "local_tm_date", sys_date);
        PutField_CString(hMyHash, "local_tm_time", sys_time);

	if (iRet == SUCCESS) {
		GetField_CString(hMyHash, "txn_status", &csTmp);

		if (!strcmp(csTmp, "NEW")) {

			PutField_CString(hMyHash, "void_po_status", "NEW-SKIP");
			iRet = UpdateVoidPOTxnStatus(hMyHash);

		} else if (!strcmp(csTmp, "PAYOUT_CREDIT_ADJUSTMENT_APPROVED")) {

			iRet = process_payout_psp_reversal(hMyHash);

			if (iRet == PD_SKIP_OK) {
				PutField_CString(hMyHash, "void_po_status", "VOID-SKIP");
				iRet = UpdateVoidPOTxnStatus(hMyHash);
			}

			if (iRet == SUCCESS) {
				PutField_CString(hMyHash, "void_po_status", "COMPLETE");
	                        iRet = UpdateVoidPOTxnStatus(hMyHash);
			}

		}
		else {
			iRet = FAILURE;
		}


		if (iRet == SUCCESS) {
			TxnCommit();
		} else {
			TxnAbort();
		}
	}




	return iRet;
}



int process_payout_psp_reversal(hash_t * hMyHash) {

	int	iRet = SUCCESS;

	int	iTmpRet = SUCCESS;

	char	*csVNCRefNum;
	char	*csUploadTxnId;
	char	*csBatchId;
	int     iSeqNum;
	int	iStatus;
	char	*csPSPID;

	char	csVOATxnSeq[PD_TXN_SEQ_LEN + 1];
	int	iNormalCase = PD_FALSE;

	char	*csTmp;
	int	iCnt = 0;
	double	dTmp;


        recordset_t     *rRecordSet;
        hash_t          *hRec;

	hash_t		*hTxn;
	hTxn = (hash_t*)malloc(sizeof(hash_t));


	GetField_CString(hMyHash, "txn_nmb", &csVNCRefNum);

	// Find the VOA txn_seq 

	iRet = GetPORevTxnSeqByVNCRefNum(csVNCRefNum, csVOATxnSeq);

	if (iRet != SUCCESS) {
DEBUGLOG(("pr_payout_void_generate_2:: GetPORevTxnSeqByVNCRefNum ERROR\n"));
	} else {
DEBUGLOG(("pr_payout_void_generate_2:: GetPORevTxnSeqByVNCRefNum vnc_ref_num [%s] VOA txn_seq [%s]\n", csVNCRefNum, csVOATxnSeq));
	}

	if (iRet == SUCCESS) {
		rRecordSet = (recordset_t *)malloc(sizeof(recordset_t));
		recordset_init(rRecordSet, 0);

		//from table:merchant_upload_file_detail
		if (GetPayoutDetailByAuxVncRefNum(csVOATxnSeq, rRecordSet)==PD_OK){
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				iCnt++;

				if(GetField_CString(hRec,"txn_id",&csUploadTxnId)){
					PutField_CString(hMyHash, "upload_txn_id", csUploadTxnId);
DEBUGLOG(("process_payout_psp_reversal::GetPayoutDetailByAuxVncRefNum txn_id = [%s]\n",csUploadTxnId));
				}

				if(GetField_CString(hRec,"batch_id",&csBatchId)){
					PutField_CString(hMyHash, "batch_id", csBatchId);
DEBUGLOG(("process_payout_psp_reversal::GetPayoutDetailByAuxVncRefNum batch_id = [%s]\n",csBatchId));
				}

				if(GetField_Int(hRec,"seq_num",&iSeqNum)){
DEBUGLOG(("process_payout_psp_reversal::GetPayoutDetailByAuxVncRefNum seq_num = [%d]\n",iSeqNum));
				}

				if(GetField_Int(hRec,"status",&iStatus)){
DEBUGLOG(("process_payout_psp_reversal::GetPayoutDetailByAuxVncRefNum status = [%d]\n",iStatus));
				}

				if(GetField_CString(hRec,"country",&csTmp)){
					PutField_CString(hMyHash, "country", csTmp);
DEBUGLOG(("process_payout_psp_reversal::GetPayoutDetailByAuxVncRefNum country = [%s]\n",csTmp));
				}

				hRec = RecordSet_GetNext(rRecordSet);
			}
		} else {
DEBUGLOG(("process_payout_psp_reversal::Get PayoutByAuxVncRefNum FAILURE!\n"));
			iRet = FAILURE;
		}
		RecordSet_Destroy(rRecordSet);
	}

	if (iCnt == 0) {
DEBUGLOG(("process_payout_psp_reversal::Get PayoutByAuxVncRefNum NO RECORD FOUND!\n"));
		iRet = FAILURE;
	}

	if (iRet == SUCCESS) {
		if (Reversed_record_exists(csBatchId, iSeqNum) == PD_NOT_FOUND) {

DEBUGLOG(("process_payout_psp_reversal::!!! Batchid [%s] SeqNum [%d] not in reversed psp_file list!\n"));
			iRet = PD_SKIP_OK;
		}
	}


	PutField_Int(hMyHash,"return_pspfee",PD_FALSE);

	if (iRet == SUCCESS) {

		iTmpRet = prpar2_GetPOGTxnIDByVOATxnID(csVOATxnSeq, hMyHash);

		if (iTmpRet == PD_NOT_FOUND) {
DEBUGLOG(("process_payout_psp_reversal:: not exists payout_generated record!\n"));
			iNormalCase = PD_FALSE;
		} else if (iTmpRet == PD_ERR) {
			iRet = FAILURE;
DEBUGLOG(("process_payout_psp_reversal::prpar2_GetPOGTxnIDByVOATxnID FAILED!\n"));
		} else {
			GetField_CString(hMyHash, "poa_txn_id", &csTmp);
DEBUGLOG(("process_payout_psp_reversal::prpar2_GetPOGTxnIDByVOATxnID poa_txn_id [%s]\n", csTmp));

			GetField_CString(hMyHash, "pog_txn_id", &csTmp);
DEBUGLOG(("process_payout_psp_reversal::prpar2_GetPOGTxnIDByVOATxnID pog_txn_id [%s]\n", csTmp));

			
	
			iNormalCase = PD_TRUE;
DEBUGLOG(("process_payout_psp_reversal:: exists in payout_generated!\n"));
		}

		if (iRet == SUCCESS) {
			PutField_Int(hMyHash, "pog_record_exists", iNormalCase);
		}
	}


	if (iRet == SUCCESS) {
		PutField_Int(hMyHash, "return_pspfee", PD_FALSE);
		
		if (iNormalCase == PD_TRUE) {
			if (GetPayoutServiceFee(csUploadTxnId, hMyHash) == SUCCESS) {
				if (GetField_Double(hMyHash, "service_fee", &dTmp)) {
DEBUGLOG(("process_payout_psp_reversal::Get service_fee [%lf]\n", dTmp));
				}
			}
		}
	}

	// To find PSP
	if (iRet == SUCCESS) {
		if (iNormalCase == PD_FALSE) {
			recordset_init(rRecordSet, 0);

			if (GetPayoutReversedPSP(csBatchId, iSeqNum, rRecordSet) == PD_OK) {
				hRec = RecordSet_GetFirst(rRecordSet);

				while (hRec) {
					if (GetField_CString(hRec, "reversed_psp_id", &csTmp)) {		
						PutField_CString(hMyHash, "psp_type_code", csTmp);
DEBUGLOG(("process_payout_psp_reversal: GetPayoutReversedPSP psp_id [%s]\n", csTmp));
					}
					hRec = RecordSet_GetNext(rRecordSet);
				}
			}
			else {
DEBUGLOG(("process_payout_psp_reversal::GetPayoutReversedPSP FAILURE!\n"));
				iRet = FAILURE;
			}
			RecordSet_Destroy(rRecordSet);

			if (iRet == SUCCESS) {
				hash_init(hTxn, 0);
	
				// GetClient ID by PSP
				GetField_CString(hMyHash, "psp_type_code", &csTmp);
				PutField_CString(hTxn, "psp_type_code", csTmp);

				iRet = GetPSPRelatedInfo(hTxn);

				if (iRet == SUCCESS) {
					if (GetField_CString(hTxn, "psp_id", &csPSPID)) {
DEBUGLOG(("process_payout_psp_reversal psp_id = [%s]\n"));
						PutField_CString(hMyHash, "vog_psp_id", csPSPID);
					} else {
						iRet = FAILURE;
DEBUGLOG(("process_payout_psp_reversal psp_id FAILURE\n")); 
					}

					if (GetField_CString(hTxn, "psp_country", &csTmp)) {
DEBUGLOG(("process_payout_psp_reversal psp_country = [%s]\n"));
						PutField_CString(hMyHash, "psp_country", csPSPID);
					}
				}
				hash_destroy(hTxn);
			}

			if (iRet == SUCCESS) {
				hash_init(hTxn, 0);

				if (par_GetPspDetail(csPSPID, hTxn) == PD_OK) {
					if (GetField_CString(hTxn, "client_id", &csTmp)) {
DEBUGLOG(("process_payout_psp_reversal client_id = [%s]\n", csTmp));
						PutField_CString(hMyHash, "client_id", csTmp);
					}
				} else {
					iRet = FAILURE;
DEBUGLOG(("process_payout_psp_reversal getpspid FAILURE\n")); 
				}

				hash_destroy(hTxn);
			}
		}
	}

	
	if (iRet == SUCCESS) {
		iRet = PSP_Reversal_Handle(hMyHash);
	}



	FREE_ME(hTxn);

	return iRet;
}



int	PSP_Reversal_Handle(hash_t *hMyHash)
{
	int		iRet = SUCCESS;

	char		*csTmp;
	int		iTmp;

	char		*csTxnSeq= strdup("");
	char		csDate[PD_DATE_LEN + 1];

	hash_t		*hContext, *hRequest, *hResponse;

	hContext = (hash_t*)malloc(sizeof(hash_t));
	hRequest = (hash_t*)malloc(sizeof(hash_t));
	hResponse = (hash_t*)malloc(sizeof(hash_t));

	hash_init(hContext, 0);
	hash_init(hRequest, 0);
	hash_init(hResponse, 0);

	if (GetField_CString(hMyHash, "poa_txn_id", &csTxnSeq)) {
DEBUGLOG(("PSP_Reversal_Handle:: POG TxnID [%s]\n", csTxnSeq));
	} else {
/*
                DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextPayoutTxnSeq");
                strcpy(csTxnSeq, (*DBObjPtr)());
DEBUGLOG(("PSP_Reversal_Handle:: Gen New POG TxnID [%s]\n", csTxnSeq));
*/
	}
	PutField_CString(hContext, "org_txn_seq", csTxnSeq);


	PutField_CString(hRequest, "add_user", PD_UPDATE_USER);
	PutField_CString(hContext, "update_user", PD_UPDATE_USER);


	if (GetField_CString(hMyHash, "remark", &csTmp)) {
		PutField_CString(hRequest, "remark", csTmp);
	}

	if (GetField_Int(hMyHash,"return_pspfee", &iTmp)) {
		PutField_Int(hRequest, "return_mfee", iTmp);
	}

	PutField_CString(hRequest, "org_txn_code", PD_PAYOUT_GENERATE);
	PutField_CString(hContext, "txn_code", PD_PAYOUT_VOID_PSP);

	PutField_Int(hContext, "db_commit", PD_FALSE);
	PutField_Int(hContext,"do_logging",PD_NO_LOG);


	if (GetField_CString(hMyHash, "txn_date", &csTmp)) {

		PutField_CString(hContext, "transmission_datetime", csTmp);

		strncpy(csDate, csTmp, PD_DATE_LEN);
		csDate[PD_DATE_LEN] = '\0';

		PutField_CString(hContext, "PHDATE", csDate);
	}

	if (GetField_Int(hMyHash, "pog_record_exists", &iTmp)) {
		PutField_Int(hContext, "pog_record_exists", iTmp);
	}

	if (GetField_CString(hMyHash, "batch_id", &csTmp)) {
		PutField_CString(hContext, "batch_id", csTmp);
	}	

	if (GetField_Int(hMyHash, "seq_num", &iTmp)) {
		PutField_Int(hContext, "seq_num", iTmp);
	}


	if (GetField_CString(hMyHash, "local_tm_date", &csTmp)) {
		PutField_CString(hContext, "local_tm_date", csTmp);
	}

	if (GetField_CString(hMyHash, "local_tm_time", &csTmp)) {
		PutField_CString(hContext, "local_tm_time", csTmp);
	}

	if (GetField_CString(hMyHash, "client_id", &csTmp)) {
		PutField_CString(hContext, "client_id", csTmp);
	}

	if (GetField_CString(hMyHash, "psp_country", &csTmp)) {
		PutField_CString(hContext, "psp_country", csTmp);
	}
	
	if (GetField_CString(hMyHash, "vog_psp_id", &csTmp)) {
		PutField_CString(hContext, "vog_psp_id", csTmp);
	}



	if (iRet == SUCCESS) {
DEBUGLOG(("PSP_Reversal_Handle::call TxnParByUsVOG.Authorize\n"));

                TxnObjPtr = CreateObj(TxnPtr,"TxnParByUsVOG","Authorize");
                iRet = (unsigned long)(*TxnObjPtr)(hContext, hRequest, hResponse);

DEBUGLOG(("PSP_Reversal_Handle::TxnParByUsVOG.Authorize return [%d]\n",iRet));

        }

	if (iRet == SUCCESS) {
//PutField_CString("approval_date");
//PutField_CString("sub_status", PD_REFUND_APPROVED);

	}




	hash_destroy(hContext);
	hash_destroy(hRequest);
	hash_destroy(hResponse);

	FREE_ME(hContext);
	FREE_ME(hRequest);
	FREE_ME(hResponse);

	FREE_ME(csTxnSeq);

	return iRet;

}

int	GetPayoutReversedPSP(const char *csBatchId, int iSeqNum, recordset_t *myRec)
{

	int	iRet = FAILURE;
        hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO get_reverse_psp_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;

		int		hv_seq_num;
	

		/* varchar		v_psp_id[PAR_PSP_TYPE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_id;

		short		ind_psp_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 



	hv_batch_id.len=strlen(csBatchId);
	memcpy(hv_batch_id.arr, csBatchId, hv_batch_id.len);
DEBUGLOG(("GetPayoutReversedPSP batch_id = [%.*s]\n", hv_batch_id.len, hv_batch_id.arr));

	hv_seq_num = iSeqNum;


        /* EXEC SQL DECLARE c_cursor_get_psp CURSOR FOR
		select prh_file_psp
		from par_po_reversed_hd, par_po_reversed_dt, par_payout_upload
		where pu_batch_id = :hv_batch_id
		and prd_po_file_id = pu_file_id
		and prd_seq_nmb = :hv_seq_num
		and prd_psp_file_id = prh_file_id; */ 

	
	/* EXEC SQL OPEN c_cursor_get_psp; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 24;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )272;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[0] = (unsigned long )18;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_seq_num;
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
 if (sqlca.sqlcode < 0) goto get_reverse_psp_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_get_psp
		INTO	
			:v_psp_id:ind_psp_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 24;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )295;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_psp_id;
  sqlstm.sqhstl[0] = (unsigned long )53;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_psp_id;
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
  if (sqlca.sqlcode < 0) goto get_reverse_psp_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*)malloc(sizeof(hash_t));
		hash_init(myHash, 0);


		if (ind_psp_id >= 0) {
			v_psp_id.arr[v_psp_id.len] = '\0';
			PutField_CString(myHash, "reversed_psp_id", (const char *)v_psp_id.arr);
DEBUGLOG(("GetPayoutReversedPSP psp_id [%s]\n", v_psp_id.arr));
		}

		RecordSet_Add(myRec, myHash);

		iRet = SUCCESS;
		
		break;

	} while (PD_TRUE);
	
	/* EXEC SQL CLOSE c_cursor_get_psp; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 24;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )314;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto get_reverse_psp_error;
}



DEBUGLOG(("GetPayoutReversedPSP Normal Exit Ret [%d]\n", iRet));
	return iRet;

get_reverse_psp_error:
DEBUGLOG(("getd_everse_psp_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("GetPayoutReversedPSP : SP_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_get_psp; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 24;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )329;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;

}



int UpdateByGenId(const hash_t *hRec)
{
        char*   csBuf;
        char*   csGenId;
        int     iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO updatebygen_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateByGenId: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update payout_generated_file_dt set fd_update_timestamp = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        if(GetField_CString(hRec,"txn_id",&csGenId)){
DEBUGLOG(("UpdateByGenId:txn_id = [%s]\n",csGenId));
        }
        else{
                FREE_ME(csBuf);
DEBUGLOG(("UpdateByGenId txn_id not found\n"));
                return INT_ERR;
        }

        if(GetField_Int(hRec,"status",&iTmp)){
DEBUGLOG(("UpdateByGenId: status = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",fd_status = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRec,"aux_txn_id",&csBuf)){
DEBUGLOG(("UpdateByGenId: aux_txn_id = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",fd_aux_txn_id = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
        //strcat((char*)hv_dynstmt.arr, " WHERE fd_txn_id= '");
        strcat((char*)hv_dynstmt.arr, " WHERE fd_upload_txn_id = '");
        strcat((char*)hv_dynstmt.arr, csGenId);
        strcat((char*)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));


        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 24;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )344;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
        sqlstm.sqhstl[0] = (unsigned long )1026;
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
        if (sqlca.sqlcode < 0) goto updatebygen_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 24;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )363;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto updatebygen_error;
}



        FREE_ME(csBuf);

DEBUGLOG(("UpdateByGenId Normal Exit\n"));
        return PD_OK;

updatebygen_error:
DEBUGLOG(("updatebygen_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("PayoutGeneratedFileDT_UpdateByGenId: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int	GetPayoutServiceFee(const char *csUploadTxnId , hash_t *hTxn)
{

	int	iRet = SUCCESS;

        /* EXEC SQL WHENEVER SQLERROR GOTO get_payout_service_fee; */ 
 
        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_upload_txn_id [PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_upload_txn_id;


		double          v_service_fee;
		short		ind_service_fee = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_upload_txn_id.len=strlen(csUploadTxnId);
	memcpy(hv_upload_txn_id.arr, csUploadTxnId, hv_upload_txn_id.len);
DEBUGLOG(("GetPayoutServiceFee upload_txn_id = [%s]\n", hv_upload_txn_id.arr));

        /* EXEC SQL DECLARE c_cursor_get_service_fee CURSOR FOR
		select /ofh_txn_id , o/tp_service_fee
		from txn_psp_detail, payout_generated_file_hd, payout_generated_file_dt
		where fd_upload_txn_id = :hv_upload_txn_id
		and fd_file_id = fh_file_id
		and fh_txn_id = tp_txn_id; */ 

	
	/* EXEC SQL OPEN c_cursor_get_service_fee; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 24;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0004;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )378;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_upload_txn_id;
 sqlstm.sqhstl[0] = (unsigned long )18;
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
 if (sqlca.sqlcode < 0) goto get_payout_service_fee;
}


	do {
		/* EXEC SQL FETCH c_cursor_get_service_fee
		INTO	
			:v_service_fee:ind_service_fee; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 24;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )397;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_service_fee;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_service_fee;
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
  if (sqlca.sqlcode < 0) goto get_payout_service_fee;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		if (ind_service_fee >= 0) {
			PutField_Double(hTxn, "service_fee", v_service_fee);
		}

		break;

	} while (PD_TRUE);
	
	/* EXEC SQL CLOSE c_cursor_get_service_fee; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 24;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )416;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto get_payout_service_fee;
}



DEBUGLOG(("GetPayoutService Fee Normal Exit Ret [%d]\n", iRet));
	return iRet;

get_payout_service_fee:
DEBUGLOG(("get_payout_service_fee code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("GetPayoutServiceFee: SP_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_get_service_fee; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 24;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )431;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;

}

int	Reversed_record_exists(const char *csBatchId, int iSeqNum)
{

	int	iRet = PD_NOT_FOUND;

        /* EXEC SQL WHENEVER SQLERROR GOTO reversed_record_exists_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;

		int		hv_seq_num;

		int		v_no_of_record;
		short		ind_no_of_record = -1;	

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_batch_id.len=strlen(csBatchId);
	memcpy(hv_batch_id.arr, csBatchId, hv_batch_id.len);
DEBUGLOG(("GetPayoutReversedPSP batch_id = [%s]\n", hv_batch_id.arr));

	hv_seq_num = iSeqNum;


	/* EXEC SQL
		select count(1)
		into   :v_no_of_record:ind_no_of_record
		from   par_payout_upload, par_po_reversed_dt
		where pu_batch_id = :hv_batch_id
		and prd_po_file_id = pu_file_id
		and prd_seq_nmb = :hv_seq_num
                and rownum = 1; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 24;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count(1) into :b0:b1  from par_payout_upload ,par_po\
_reversed_dt where (((pu_batch_id=:b2 and prd_po_file_id=pu_file_id) and prd_\
seq_nmb=:b3) and rownum=1)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )446;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_seq_num;
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
 if (sqlca.sqlcode < 0) goto reversed_record_exists_error;
}



	if (ind_no_of_record >= 0) {
		if (v_no_of_record > 0) {
DEBUGLOG(("Reversed_record_exists FOUND\n"));
                        iRet = PD_FOUND;
                }
	}

	if (iRet != PD_FOUND) {
DEBUGLOG(("Reversed_record_exists NOT FOUND\n"));
	}

	
	return iRet;

reversed_record_exists_error:
DEBUGLOG(("reversed_record_exists_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("Reversed_record_exists: SP_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}

