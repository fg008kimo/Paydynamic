
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
    "gen_txn_detail_by_psp.pc"
};


static unsigned int sqlctx = 1236377483;


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
   unsigned char  *sqhstv[18];
   unsigned long  sqhstl[18];
            int   sqhsts[18];
            short *sqindv[18];
            int   sqinds[18];
   unsigned long  sqharm[18];
   unsigned long  *sqharc[18];
   unsigned short  sqadto[18];
   unsigned short  sqtdso[18];
} sqlstm = {12,18};

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
"select th_txn_id ,th_status ,th_ar_ind ,th_internal_code ,th_response_code \
,th_merchant_id ,th_merchant_ref ,tp_tid ,tp_txn_ccy ,th_transaction_amount ,\
tp_service_fee ,th_transmission_datetime ,th_local_tm_date ,th_local_tm_time \
,tp_txn_date ,th_host_posting_date ,tc_desc ,psp_name  from txn_header ,txn_d\
etail ,txn_psp_detail ,txn_code ,psp_detail where ((((((th_status<>'P' and tx\
n_header.th_txn_id=txn_detail.td_txn_id) and txn_header.th_txn_id=txn_psp_det\
ail.tp_txn_id) and txn_header.th_host_posting_date=:b0) and txn_header.th_txn\
_code=txn_code.tc_code) and txn_psp_detail.tp_psp_id=:b1) and psp_detail.psp_\
id=:b1) order by th_txn_id            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,652,0,9,174,0,0,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
32,0,0,1,0,0,13,176,0,0,18,0,0,1,0,2,9,0,0,2,1,0,0,2,1,0,0,2,3,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,
119,0,0,1,0,0,15,302,0,0,0,0,0,1,0,
134,0,0,1,0,0,15,308,0,0,0,0,0,1,0,
149,0,0,2,0,0,32,309,0,0,0,0,0,1,0,
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
#define	PD_MY_DELIMITOR	','
#define PD_TR           "<tr>"
#define PD_TD           "<td>"
#define PD_TD_STYLE     "<td class=\"format\">"
#define PD_TR_END       "</tr>"
#define PD_TD_END       "</td>"

char    cs_txn_date[PD_DATE_LEN + 1];
char	cs_psp_id[PD_PSP_ID_LEN +1];
char    cDebug;

int parse_arg(int argc,char **argv);
int process_txn(unsigned char* csTxnDate, unsigned char* csPspId);
int batch_init(int argc, char* argv[])
{

    if (argc < 2) {
        printf("usage: -d txn_date -p PSP ID\n");
        return FAILURE;
    }
    else
        return SUCCESS;
}




int batch_proc(int argc, char* argv[])
{
        int     iRet;

	iRet = parse_arg(argc,argv);
               
        if (iRet != SUCCESS) {
        	printf("usage: -d txn_date -p PSP ID\n");
                return (iRet);
        }
        
	printf("<html><body><table>\n");
	printf("%s%sPH Txn ID%s%sPH Txn Code%s%sPH Status%s%sAR_IND%s%sPH Response Code%s%sMerchant ID%s%sMerchant Refernece%s%sPSP Name%s%sPSP Txn ID%s%sTxn Ccy%s%sTxn Amount%s%sPSP Service%s%sPH Posting Date%s%sMerchant Txn Date%s%sPH Txn Date%s%sPSP Txn Date%s%s\n",PD_TR,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TR_END);
        printf("<style type=\"text/css\"> .format{ mso-number-format:'\\@';} </style>\n");


        iRet = process_txn((unsigned char*)cs_txn_date,(unsigned char*)cs_psp_id);

	printf("</table></body></html>\n");
	
	return iRet;


}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}




int process_txn(unsigned char* csTxnDate, unsigned char* csPspId)
{               
 
        int     iRet = SUCCESS;
	char	*csTmp;
        
        /* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		
		/* varchar	hv_txn_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_txn_date;

		/* varchar	hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;


		/* varchar	v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		char	v_status;
		char	v_ar_ind;
		int	v_internal_code;
		/* varchar	v_response_code[PD_RESPONSE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_response_code;

		/* varchar	v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar	v_merchant_ref[PD_MERCHANT_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar	v_tid[PD_MERCHANT_REF_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_tid;

		/* varchar	v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

		double	v_txn_amount;
		double	v_service_fee;
		/* varchar	v_merchant_txn_date[PD_DATE_LEN + PD_TIME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_merchant_txn_date;

		/* varchar	v_local_txn_date[PD_DATE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_local_txn_date;

		/* varchar	v_local_txn_time[PD_DATE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_local_txn_time;

		/* varchar	v_psp_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_psp_txn_date;

		/* varchar	v_host_posting_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_host_posting_date;

		/* varchar v_txn_code_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_code_desc;

		/* varchar v_psp_name[PD_PSP_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_psp_name;


		short	ind_txn_id = -1;
		short	ind_status = -1;
		short	ind_ar_ind = -1;
		short	ind_internal_code = -1;
		short	ind_response_code = -1;
		short	ind_merchant_id = -1;
		short	ind_merchant_ref = -1;
		short	ind_tid = -1;
		short	ind_txn_ccy = -1;
		short	ind_txn_amount = -1;
		short	ind_service_fee = -1;
		short	ind_merchant_txn_date = -1;
		short	ind_local_txn_date = -1;
		short	ind_local_txn_time = -1;
		short	ind_psp_txn_date = -1;
		short	ind_host_posting_date = -1;
		short	ind_txn_code_desc = -1;
		short	ind_psp_name = -1;


	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_date.len = strlen((const char*)csTxnDate);
        memcpy(hv_txn_date.arr,csTxnDate,hv_txn_date.len);

	hv_psp_id.len = strlen((const char*)csPspId);
        memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);

        /* EXEC SQL DECLARE c_cursor_gettxn CURSOR FOR
		select 	th_txn_id,
         		th_status,
         		th_ar_ind,
         		th_internal_code,
         		th_response_code,
         		th_merchant_id,
         		th_merchant_ref,
         		tp_tid,
         		tp_txn_ccy,
         		th_transaction_amount,
         		tp_service_fee,
			th_transmission_datetime,
         		th_local_tm_date,
         		th_local_tm_time,
         		tp_txn_date,
			th_host_posting_date,
			tc_desc,
			psp_name
		  from 	txn_header,
        		txn_detail,
        		txn_psp_detail,
			txn_code,
			psp_detail
		where th_status != 'P'
    		and txn_header.th_txn_id = txn_detail.td_txn_id
    		and txn_header.th_txn_id = txn_psp_detail.tp_txn_id
    		and txn_header.th_host_posting_date = :hv_txn_date
		and txn_header.th_txn_code = txn_code.tc_code
		and txn_psp_detail.tp_psp_id = :hv_psp_id
		and psp_detail.psp_id = :hv_psp_id
		order by th_txn_id; */ 

                
        /* EXEC SQL OPEN c_cursor_gettxn; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 3;
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
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_txn_date;
        sqlstm.sqhstl[0] = (unsigned long )10;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_psp_id;
        sqlstm.sqhstl[2] = (unsigned long )12;
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
        if (sqlca.sqlcode < 0) goto sql_error;
}


        do {    
                /* EXEC SQL FETCH c_cursor_gettxn
                INTO
		 	v_txn_id:ind_txn_id,
         		v_status:ind_status,
         		v_ar_ind:ind_ar_ind,
         		v_internal_code:ind_internal_code,
         		v_response_code:ind_response_code,
         		v_merchant_id:ind_merchant_id,
         		v_merchant_ref:ind_merchant_ref,
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
			v_psp_name:ind_psp_name; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 18;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )32;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&v_status;
                sqlstm.sqhstl[1] = (unsigned long )1;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_status;
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
                sqlstm.sqhstv[3] = (unsigned char  *)&v_internal_code;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_internal_code;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_response_code;
                sqlstm.sqhstl[4] = (unsigned long )7;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_response_code;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_merchant_id;
                sqlstm.sqhstl[5] = (unsigned long )18;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_merchant_id;
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
                sqlstm.sqhstv[7] = (unsigned char  *)&v_tid;
                sqlstm.sqhstl[7] = (unsigned long )53;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_tid;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_txn_ccy;
                sqlstm.sqhstl[8] = (unsigned long )6;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_txn_ccy;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_txn_amount;
                sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_txn_amount;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_service_fee;
                sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_service_fee;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_merchant_txn_date;
                sqlstm.sqhstl[11] = (unsigned long )17;
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_merchant_txn_date;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
                sqlstm.sqhstv[12] = (unsigned char  *)&v_local_txn_date;
                sqlstm.sqhstl[12] = (unsigned long )11;
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_local_txn_date;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
                sqlstm.sqhstv[13] = (unsigned char  *)&v_local_txn_time;
                sqlstm.sqhstl[13] = (unsigned long )11;
                sqlstm.sqhsts[13] = (         int  )0;
                sqlstm.sqindv[13] = (         short *)&ind_local_txn_time;
                sqlstm.sqinds[13] = (         int  )0;
                sqlstm.sqharm[13] = (unsigned long )0;
                sqlstm.sqadto[13] = (unsigned short )0;
                sqlstm.sqtdso[13] = (unsigned short )0;
                sqlstm.sqhstv[14] = (unsigned char  *)&v_psp_txn_date;
                sqlstm.sqhstl[14] = (unsigned long )11;
                sqlstm.sqhsts[14] = (         int  )0;
                sqlstm.sqindv[14] = (         short *)&ind_psp_txn_date;
                sqlstm.sqinds[14] = (         int  )0;
                sqlstm.sqharm[14] = (unsigned long )0;
                sqlstm.sqadto[14] = (unsigned short )0;
                sqlstm.sqtdso[14] = (unsigned short )0;
                sqlstm.sqhstv[15] = (unsigned char  *)&v_host_posting_date;
                sqlstm.sqhstl[15] = (unsigned long )11;
                sqlstm.sqhsts[15] = (         int  )0;
                sqlstm.sqindv[15] = (         short *)&ind_host_posting_date;
                sqlstm.sqinds[15] = (         int  )0;
                sqlstm.sqharm[15] = (unsigned long )0;
                sqlstm.sqadto[15] = (unsigned short )0;
                sqlstm.sqtdso[15] = (unsigned short )0;
                sqlstm.sqhstv[16] = (unsigned char  *)&v_txn_code_desc;
                sqlstm.sqhstl[16] = (unsigned long )53;
                sqlstm.sqhsts[16] = (         int  )0;
                sqlstm.sqindv[16] = (         short *)&ind_txn_code_desc;
                sqlstm.sqinds[16] = (         int  )0;
                sqlstm.sqharm[16] = (unsigned long )0;
                sqlstm.sqadto[16] = (unsigned short )0;
                sqlstm.sqtdso[16] = (unsigned short )0;
                sqlstm.sqhstv[17] = (unsigned char  *)&v_psp_name;
                sqlstm.sqhstl[17] = (unsigned long )18;
                sqlstm.sqhsts[17] = (         int  )0;
                sqlstm.sqindv[17] = (         short *)&ind_psp_name;
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
                if (sqlca.sqlcode < 0) goto sql_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }
		printf("%s",PD_TR);
/* txn id */
		if (ind_txn_id < 0 )
			v_txn_id.arr[0] = '\0';
		printf("%s%.*s%s",PD_TD_STYLE,v_txn_id.len,v_txn_id.arr,PD_TD_END);

/* txn_desc  */
		if (ind_txn_code_desc < 0 )
			v_txn_code_desc.arr[0] = '\0';
		printf("%s%.*s%s",PD_TD,v_txn_code_desc.len,v_txn_code_desc.arr,PD_TD_END);
/* status */
		if (ind_status < 0 )
			csTmp = strdup("");
		else {
			if (v_status == 'C')
				csTmp = strdup("Completed");
			else 
				csTmp = strdup("Pending");
		}
	 	printf("%s%s%s",PD_TD,csTmp,PD_TD_END);
		FREE_ME(csTmp);
/* ar ind */
		if (ind_ar_ind < 0 )
			csTmp = strdup("");
		else {
			if (v_ar_ind == 'A')
				csTmp = strdup("Accept");
			else 
				csTmp = strdup("Reject");
		}
	 	printf("%s%s%s",PD_TD,csTmp,PD_TD_END);
		FREE_ME(csTmp);

/* internal_code */
//		if (ind_internal_code < 0)
//			v_internal_code = 0;
//	 	printf("%s%d%s",PD_TD,v_internal_code,PD_TD_END);

/* response_code */
		if (ind_response_code < 0 )
			v_response_code.arr[0] = '\0';
		printf("%s%.*s%s",PD_TD,v_response_code.len,v_response_code.arr,PD_TD_END);

/* merchant_id */
		if (ind_merchant_id < 0 )
			v_merchant_id.arr[0] = '\0';
		printf("%s%.*s%s",PD_TD_STYLE,v_merchant_id.len,v_merchant_id.arr,PD_TD_END);

/* merchant_ref */
		if (ind_merchant_ref < 0 )
			v_merchant_ref.arr[0] = '\0';
		printf("%s%.*s%s",PD_TD_STYLE,v_merchant_ref.len,v_merchant_ref.arr,PD_TD_END);

/* psp_name */
		if(ind_psp_name < 0)
			v_psp_name.arr[0] = '\0';
		printf("%s%.*s%s",PD_TD,v_psp_name.len,v_psp_name.arr,PD_TD_END);

/* tid */
		if (ind_tid < 0 )
			v_tid.arr[0] = '\0';
		printf("%s%.*s%s",PD_TD_STYLE,v_tid.len,v_tid.arr,PD_TD_END);
/* txn_ccy */
		if (ind_txn_ccy < 0 )
			v_txn_ccy.arr[0] = '\0';
		printf("%s%.*s%s",PD_TD,v_txn_ccy.len,v_txn_ccy.arr,PD_TD_END);
/* txn_amount */
		if (ind_txn_amount < 0 )
			v_txn_amount = 0;	
		printf("%s%f%s",PD_TD,v_txn_amount,PD_TD_END);
/* service_fee */
		if (ind_service_fee < 0 )
			v_service_fee = 0;	
		printf("%s%f%s",PD_TD,v_service_fee,PD_TD_END);

/* host posting date */
		if (ind_host_posting_date < 0 )
			v_host_posting_date.arr[0] = '\0';
		printf("%s%.*s%s",PD_TD_STYLE,v_host_posting_date.len,v_host_posting_date.arr,PD_TD_END);

/* merchant_txn_date */
		if (ind_merchant_txn_date < 0 )
			v_merchant_txn_date.arr[0] = '\0';
		printf("%s%.*s%s",PD_TD_STYLE,v_merchant_txn_date.len,v_merchant_txn_date.arr,PD_TD_END);

/* local_txn_date */
		if (ind_local_txn_date < 0 )
			v_local_txn_date.arr[0] = '\0';

		if (ind_local_txn_time < 0 )
			v_local_txn_time.arr[0] = '\0';
		printf("%s%.*s %.*s%s",PD_TD_STYLE,v_local_txn_date.len,v_local_txn_date.arr,v_local_txn_time.len,v_local_txn_time.arr,PD_TD_END);

/* psp_txn_date */
		if (ind_psp_txn_date < 0 )
			v_psp_txn_date.arr[0] = '\0';
		printf("%s%.*s%s",PD_TD_STYLE,v_psp_txn_date.len,v_psp_txn_date.arr,PD_TD_END);

		printf("%s\n",PD_TR_END);
 	}
        while(PD_TRUE && iRet == SUCCESS);

        /* EXEC SQL CLOSE c_cursor_gettxn; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 18;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )119;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto sql_error;
}


        return iRet;
sql_error:
    DEBUGLOG(("process_txn error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_gettxn; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 18;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )134;
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
    sqlstm.arrsiz = 18;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )149;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}


int parse_arg(int argc,char **argv)
{
        char    c;
        strcpy(cs_txn_date,"");
        strcpy(cs_psp_id,"");

        while ((c = getopt(argc,argv,"d:p:")) != EOF) {
                switch (c) {
                        case 'd':
                                strcpy(cs_txn_date, optarg);
                                break;
                        case 'p':
                                strcpy(cs_psp_id, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_txn_date,"") || !strcmp(cs_psp_id,""))
                return FAILURE;

        return SUCCESS;
}

