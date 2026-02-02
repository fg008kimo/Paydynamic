
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
           char  filnam[14];
};
static struct sqlcxp sqlfpn =
{
    13,
    "exportdata.pc"
};


static unsigned int sqlctx = 625667;


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
   unsigned char  *sqhstv[19];
   unsigned long  sqhstl[19];
            int   sqhsts[19];
            short *sqindv[19];
            int   sqinds[19];
   unsigned long  sqharm[19];
   unsigned long  *sqharc[19];
   unsigned short  sqadto[19];
   unsigned short  sqtdso[19];
} sqlstm = {12,19};

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
"select a.th_txn_id ,a.th_input_channel ,a.th_status ,a.th_ar_ind ,a.th_txn_\
code ,a.th_client_id ,a.th_merchant_id ,a.th_merchant_ref ,a.th_transaction_a\
mount ,a.th_net_amount ,a.th_local_tm_date ,a.th_local_tm_time ,b.td_txn_ccy \
,b.td_txn_country ,b.td_pay_method ,b.td_bank_code ,c.tp_tid ,a.th_response_c\
ode ,c.tp_psp_id  from txn_header a ,txn_detail b ,txn_psp_detail c where ((a\
.th_transmission_datetime=:b0 and a.th_txn_id=b.td_txn_id) and a.th_txn_id=c.\
tp_txn_id) order by th_txn_id            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,501,0,9,205,0,0,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,13,207,0,0,19,0,0,1,0,2,9,0,0,2,9,0,0,2,1,0,0,2,1,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
115,0,0,1,0,0,15,340,0,0,0,0,0,1,0,
130,0,0,1,0,0,15,346,0,0,0,0,0,1,0,
145,0,0,2,0,0,32,347,0,0,0,0,0,1,0,
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

char    cs_outfile[PD_MAX_FILE_LEN + 1];
char    cs_date[PD_DATE_LEN + 1];
char    cDebug;

int process_txn(FILE *fp);

int batch_init(int argc, char* argv[])
{
    if (argc < 3) {
        printf("usage:  -o ouputfile -d Date\n");
        return FAILURE;
    }
    else
        return SUCCESS;
}


int parse_arg(int argc,char **argv)
{
        char    c;
        strcpy(cs_outfile,"");
        strcpy(cs_date,"");

        //while ((c = getopt(argc,argv,"o:")) != EOF && c != 0xff) {
        while ((c = getopt(argc,argv,"o:d:")) != EOF) {
                switch (c) {
                        case 'o':
                                strcpy(cs_outfile, optarg);
                                break;
                        case 'd':
                                strcpy(cs_date, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_outfile,"") || !strcmp(cs_date,""))
                return FAILURE;

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
        
        sprintf(cs_outfile_name, "mkdir %s/%s >/dev/null 2>&1", getenv("REPORT_HOME"), cs_date);
        system(cs_outfile_name); 
        sprintf(cs_outfile_name, "%s/%s/%s%s.dat", getenv("REPORT_HOME"),cs_date,cs_outfile,cs_date);
        
        fp = fopen(cs_outfile_name,"w");
        if (fp == NULL) {
DEBUGLOG(("batch_proc:unable to open [%s]\n",cs_outfile_name));
                return FAILURE;
        }

	fprintf(fp,"Txn ID,Txn Date,Channel,Psp ID,Status,Ar Ind,Txn Code,Client ID,Merchant ID,Merchant Ref,Local Date,Local Time,Currency,Country,Pay Method,Bank Code,Txn Amount,Net Amount,Tid,Response Code\n");
        
        iRet = process_txn(fp);
        fclose(fp);
	return iRet;


}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}




int process_txn(FILE *fp)
{               
 
        int     iRet = SUCCESS;
        
        /* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		
		/* varchar	hv_host_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_host_date;


		///from header///
                /* varchar         v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

                /* varchar         v_channel_code[PD_CHANNEL_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_channel_code;

                char            v_status;
                char            v_ar_ind;
                /* varchar         v_txn_code[PD_TXN_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

                /* varchar         v_client_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_client_id;

                /* varchar         v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

                /* varchar         v_merchant_ref[PD_MERCHANT_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_merchant_ref;

                double          v_txn_amt;
                double          v_net_amt;
                /* varchar         v_local_tm_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_local_tm_date;

                /* varchar         v_local_tm_time[PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_local_tm_time;

                /* varchar         v_error_code[PD_ERROR_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_error_code;

                /////////////////

                ///from detail///
                /* varchar         v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

                /* varchar         v_txn_country[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_txn_country;

                /* varchar         v_pay_method[PD_PAY_METHOD_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_pay_method;

                /* varchar         v_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

                /////////////////

                ///from psp_detail///
                /* varchar         v_tid[PD_MERCHANT_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_tid;

		/* varchar		v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

                /////////////////////

                short           ind_txn_id = -1;
                short           ind_channel_code = -1;
                short           ind_status = -1;
                short           ind_ar_ind = -1;
                short           ind_txn_code = -1;
                short           ind_client_id = -1;
                short           ind_merchant_id = -1;
                short           ind_merchant_ref = -1;
                short           ind_txn_amt = -1;
                short           ind_net_amt = -1;
                short           ind_local_tm_date = -1;
                short           ind_local_tm_time = -1;

                short           ind_txn_ccy = -1;
                short           ind_txn_country = -1;
                short           ind_pay_method = -1;
                short           ind_bank_code = -1;

                short           ind_tid = -1;
                short           ind_error_code = -1;
		short		ind_psp_id = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_host_date.len = strlen(cs_date);
        memcpy(hv_host_date.arr,cs_date,hv_host_date.len);
DEBUGLOG(("process_txn::host_date = [%.*s]\n",hv_host_date.len,hv_host_date.arr));


        /* EXEC SQL DECLARE c_cursor_gettxn CURSOR FOR
                select  a.th_txn_id,
                        a.th_input_channel,
                        a.th_status,
                        a.th_ar_ind,
                        a.th_txn_code,
                        a.th_client_id,
                        a.th_merchant_id,
                        a.th_merchant_ref,
                        a.th_transaction_amount,
                        a.th_net_amount,
                        a.th_local_tm_date,
                        a.th_local_tm_time,
                        b.td_txn_ccy,
                        b.td_txn_country,
                        b.td_pay_method,
                        b.td_bank_code,
                        c.tp_tid,
                        a.th_response_code,
			c.tp_psp_id

                from    txn_header a,
                        txn_detail b,
                        txn_psp_detail c
                where   a.th_transmission_datetime = :hv_host_date
                and     a.th_txn_id=b.td_txn_id
                and     a.th_txn_id=c.tp_txn_id
                order by  th_txn_id; */ 


        /* EXEC SQL OPEN c_cursor_gettxn; */ 

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
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_host_date;
        sqlstm.sqhstl[0] = (unsigned long )10;
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
                /* EXEC SQL FETCH c_cursor_gettxn
                INTO
			:v_txn_id:ind_txn_id,
                        :v_channel_code:ind_channel_code,
                        :v_status:ind_status,
                        :v_ar_ind:ind_ar_ind,
                        :v_txn_code:ind_txn_code,
                        :v_client_id:ind_client_id,
                        :v_merchant_id:ind_merchant_id,
                        :v_merchant_ref:ind_merchant_ref,
                        :v_txn_amt:ind_txn_amt,
                        :v_net_amt:ind_net_amt,
                        :v_local_tm_date:ind_local_tm_date,
                        :v_local_tm_time:ind_local_tm_time,
                        :v_txn_ccy:ind_txn_ccy,
                        :v_txn_country:ind_txn_country,
                        :v_pay_method:ind_pay_method,
                        :v_bank_code:ind_bank_code,
                        :v_tid:ind_tid,
                        :v_error_code:ind_error_code,
			:v_psp_id:ind_psp_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 19;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&v_channel_code;
                sqlstm.sqhstl[1] = (unsigned long )6;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_channel_code;
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
                sqlstm.sqhstv[4] = (unsigned char  *)&v_txn_code;
                sqlstm.sqhstl[4] = (unsigned long )6;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_txn_code;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_client_id;
                sqlstm.sqhstl[5] = (unsigned long )13;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_client_id;
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
                sqlstm.sqhstl[7] = (unsigned long )28;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_merchant_ref;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_txn_amt;
                sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_txn_amt;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_net_amt;
                sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_net_amt;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_local_tm_date;
                sqlstm.sqhstl[10] = (unsigned long )11;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_local_tm_date;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_local_tm_time;
                sqlstm.sqhstl[11] = (unsigned long )9;
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_local_tm_time;
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
                sqlstm.sqhstv[13] = (unsigned char  *)&v_txn_country;
                sqlstm.sqhstl[13] = (unsigned long )5;
                sqlstm.sqhsts[13] = (         int  )0;
                sqlstm.sqindv[13] = (         short *)&ind_txn_country;
                sqlstm.sqinds[13] = (         int  )0;
                sqlstm.sqharm[13] = (unsigned long )0;
                sqlstm.sqadto[13] = (unsigned short )0;
                sqlstm.sqtdso[13] = (unsigned short )0;
                sqlstm.sqhstv[14] = (unsigned char  *)&v_pay_method;
                sqlstm.sqhstl[14] = (unsigned long )7;
                sqlstm.sqhsts[14] = (         int  )0;
                sqlstm.sqindv[14] = (         short *)&ind_pay_method;
                sqlstm.sqinds[14] = (         int  )0;
                sqlstm.sqharm[14] = (unsigned long )0;
                sqlstm.sqadto[14] = (unsigned short )0;
                sqlstm.sqtdso[14] = (unsigned short )0;
                sqlstm.sqhstv[15] = (unsigned char  *)&v_bank_code;
                sqlstm.sqhstl[15] = (unsigned long )13;
                sqlstm.sqhsts[15] = (         int  )0;
                sqlstm.sqindv[15] = (         short *)&ind_bank_code;
                sqlstm.sqinds[15] = (         int  )0;
                sqlstm.sqharm[15] = (unsigned long )0;
                sqlstm.sqadto[15] = (unsigned short )0;
                sqlstm.sqtdso[15] = (unsigned short )0;
                sqlstm.sqhstv[16] = (unsigned char  *)&v_tid;
                sqlstm.sqhstl[16] = (unsigned long )28;
                sqlstm.sqhsts[16] = (         int  )0;
                sqlstm.sqindv[16] = (         short *)&ind_tid;
                sqlstm.sqinds[16] = (         int  )0;
                sqlstm.sqharm[16] = (unsigned long )0;
                sqlstm.sqadto[16] = (unsigned short )0;
                sqlstm.sqtdso[16] = (unsigned short )0;
                sqlstm.sqhstv[17] = (unsigned char  *)&v_error_code;
                sqlstm.sqhstl[17] = (unsigned long )9;
                sqlstm.sqhsts[17] = (         int  )0;
                sqlstm.sqindv[17] = (         short *)&ind_error_code;
                sqlstm.sqinds[17] = (         int  )0;
                sqlstm.sqharm[17] = (unsigned long )0;
                sqlstm.sqadto[17] = (unsigned short )0;
                sqlstm.sqtdso[17] = (unsigned short )0;
                sqlstm.sqhstv[18] = (unsigned char  *)&v_psp_id;
                sqlstm.sqhstl[18] = (unsigned long )13;
                sqlstm.sqhsts[18] = (         int  )0;
                sqlstm.sqindv[18] = (         short *)&ind_psp_id;
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
                if (sqlca.sqlcode < 0) goto sql_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

/* Field #0 txn_id */
                if (ind_txn_id < 0 )
                        v_txn_id.arr[0] = '\0';
                fprintf(fp,"%.*s%c",v_txn_id.len,v_txn_id.arr,PD_MY_DELIMITOR);

/* Field #1 txn_date */
                fprintf(fp,"%.*s-%.*s-%.*s%c",PD_YEAR_LEN,cs_date,PD_MONTH_LEN,&cs_date[PD_MONTH_OS],PD_DAY_LEN,&cs_date[PD_MONTH_OS],PD_MY_DELIMITOR);

/* Field #2 channel_code */
		if(ind_channel_code < 0)
			v_channel_code.arr[0] = '\0';
                fprintf(fp,"%.*s%c",v_channel_code.len,v_channel_code.arr,PD_MY_DELIMITOR);

/*Field #  psp_id*/
		if(ind_psp_id< 0)
			v_psp_id.arr[0] = '\0';
                fprintf(fp,"%.*s%c",v_psp_id.len,v_psp_id.arr,PD_MY_DELIMITOR);


/*Field #3 status*/
		if(ind_status < 0)
			v_status = ' ';
		fprintf(fp,"%c%c",v_status,PD_MY_DELIMITOR);

/*Field #4 ar_ind*/
		if(ind_ar_ind < 0)
			v_ar_ind = ' ';
		fprintf(fp,"%c%c",v_ar_ind,PD_MY_DELIMITOR);

/* Field #5 txn_code */
                if (ind_txn_code < 0 )
                        v_txn_code.arr[0] = '\0';
                fprintf(fp,"%.*s%c",v_txn_code.len,v_txn_code.arr,PD_MY_DELIMITOR);

/* Field #6 client_id*/
                if (ind_client_id < 0 )
                        v_client_id.arr[0] = '\0';
                fprintf(fp,"%.*s%c",v_client_id.len,v_client_id.arr,PD_MY_DELIMITOR);


/* Field #7 merch_id  */
                if (ind_merchant_id < 0 )
                        v_merchant_id.arr[0] = '\0';
                fprintf(fp,"%.*s%c",v_merchant_id.len,v_merchant_id.arr,PD_MY_DELIMITOR);

/* Field #8 merch_ref*/
                if (ind_merchant_ref < 0 )
                        v_merchant_ref.arr[0] = '\0';
                fprintf(fp,"%.*s%c",v_merchant_ref.len,v_merchant_ref.arr,PD_MY_DELIMITOR);

/* Field #9 local_date */
		if(ind_local_tm_date < 0)
			v_local_tm_date.arr[0] = '\0';
                fprintf(fp,"%.*s-%.*s-%.*s%c",PD_YEAR_LEN,v_local_tm_date.arr,PD_MONTH_LEN,&v_local_tm_date.arr[PD_MONTH_OS],PD_DAY_LEN,&v_local_tm_date.arr[PD_MONTH_OS],PD_MY_DELIMITOR);

/* Field #10 local_time */
		if(ind_local_tm_time < 0)
                        v_local_tm_time.arr[0] = '\0';
                fprintf(fp,"%.*s%c",v_local_tm_time.len,v_local_tm_time.arr,PD_MY_DELIMITOR);


/* Field #11 currency*/
                if (ind_txn_ccy < 0 )
                        v_txn_ccy.arr[0] = '\0';
                fprintf(fp,"%.*s%c",v_txn_ccy.len,v_txn_ccy.arr,PD_MY_DELIMITOR);

/* Field #12 country*/
                if (ind_txn_country < 0 )
                        v_txn_country.arr[0] = '\0';
                fprintf(fp,"%.*s%c",v_txn_country.len,v_txn_country.arr,PD_MY_DELIMITOR);

/* Field #13 pay_method*/
                if (ind_pay_method < 0 )
                        v_pay_method.arr[0] = '\0';
                fprintf(fp,"%.*s%c",v_pay_method.len,v_pay_method.arr,PD_MY_DELIMITOR);

/* Field #14 bank_code*/
                if (ind_bank_code < 0 )
                        v_bank_code.arr[0] = '\0';
                fprintf(fp,"%.*s%c",v_bank_code.len,v_bank_code.arr,PD_MY_DELIMITOR);

/* Field #15 txn_amt */
                if (ind_txn_amt < 0 )
			v_txn_amt = 0.0;
                fprintf(fp,"%ld%c",(long)v_txn_amt,PD_MY_DELIMITOR);

/* Field #16 net_amount */
                if (ind_net_amt < 0 )
			v_net_amt = 0.0;
                fprintf(fp,"%ld%c",(long)v_net_amt,PD_MY_DELIMITOR);

/* Field #17 tid */
                if (ind_tid < 0 )
                        v_tid.arr[0] = '\0';
                fprintf(fp,"%.*s%c",v_tid.len,v_tid.arr,PD_MY_DELIMITOR);


/* Field #18 error_code*/
                if (ind_error_code < 0 )
                        v_error_code.arr[0] = '\0';
                fprintf(fp,"%.*s",v_error_code.len,v_error_code.arr);

		fprintf(fp,"\n");

 	}
        while(PD_TRUE && iRet == SUCCESS);

        /* EXEC SQL CLOSE c_cursor_gettxn; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )115;
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
    sqlstm.arrsiz = 19;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )130;
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
    sqlstm.arrsiz = 19;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )145;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}
