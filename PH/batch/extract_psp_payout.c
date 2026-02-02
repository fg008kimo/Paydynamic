
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
           char  filnam[22];
};
static struct sqlcxp sqlfpn =
{
    21,
    "extract_psp_payout.pc"
};


static unsigned int sqlctx = 160534571;


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
   unsigned char  *sqhstv[6];
   unsigned long  sqhstl[6];
            int   sqhsts[6];
            short *sqindv[6];
            int   sqinds[6];
   unsigned long  sqharm[6];
   unsigned long  *sqharc[6];
   unsigned short  sqadto[6];
   unsigned short  sqtdso[6];
} sqlstm = {12,6};

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
"select a.tp_tid ,a.tp_txn_id ,a.tp_txn_date ,a.tp_txn_amount ,a.tp_service_\
fee ,a.tp_batch_id  from txn_psp_detail a ,txn_header b where (((((a.tp_txn_i\
d=b.th_txn_id and b.th_status=:b0) and B.TH_AR_IND=:b1) and a.tp_txn_date=:b2\
) and a.tp_psp_id=:b3) and b.th_txn_code in (:b4,:b5)) order by a.tp_batch_id\
            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,318,0,9,158,0,0,6,6,0,1,0,1,1,0,0,1,1,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,
44,0,0,1,0,0,13,160,0,0,6,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,
0,0,
83,0,0,1,0,0,15,209,0,0,0,0,0,1,0,
98,0,0,1,0,0,15,215,0,0,0,0,0,1,0,
113,0,0,2,0,0,32,216,0,0,0,0,0,1,0,
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

char    cs_outputfile[PD_MAX_FILE_LEN + 1];
char    cs_psp_id[PD_PSP_ID_LEN + 1];
char    cs_txn_code[PD_TXN_CODE_LEN + 1];
char    cs_txn_code_b[PD_TXN_CODE_LEN + 1];
char    cs_date[PD_DATE_LEN + 1];
char    cDebug;

int parse_arg(int argc,char **argv);
int process_txn(const unsigned char* csPspId,const unsigned char* csTxnCode,const unsigned char* csTxnCodeB,
                FILE *fp);
int batch_init(int argc, char* argv[])
{

    if (argc < 4) {
        printf("usage:  -o ouputfile -d Date -p PSP ID -t Txn Code -x Txn Code 2\n");
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
        	printf("usage:  -o ouputfile -d Date -p PSP ID -t Txn Code -x Txn Code 2\n");
                return (iRet);
        }
        
        
	//if (CreateReportPath("TWV",cs_outfile_name) != SUCCESS) 
        //        return FAILURE;

        sprintf(cs_outfile_name, "%s/%s_%s.dat", getenv("REPORT_DATA"),cs_outputfile,cs_date);
        
        fp = fopen(cs_outfile_name,"w");
        if (fp == NULL) {
DEBUGLOG(("batch_proc:unable to open [%s]\n",cs_outfile_name));
                return FAILURE;
        }
        
        iRet = process_txn((unsigned char*)cs_psp_id,(unsigned char*)cs_txn_code,(unsigned char*)cs_txn_code_b,fp);
        fclose(fp);
	return iRet;


}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}




int process_txn(const unsigned char* csPspId,const unsigned char* csTxnCode,const unsigned char* csTxnCodeB,
                FILE *fp)
{               
 
        int     iRet = SUCCESS;
        
        /* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		
		/* varchar	hv_host_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_host_date;

		/* varchar	hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar	hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

		/* varchar	hv_txn_code_b[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code_b;

		char	hv_status;
		char	hv_ar_ind;

		/* varchar	v_tid[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_tid;

		/* varchar	v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar	v_batch_id[PD_BATCH_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_batch_id;

		/* varchar	v_txn_date[PD_DATETIME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_txn_date;

		double	v_txn_amount;
		double	v_service_fee;

		short	ind_tid = -1;
		short	ind_txn_id = -1;
		short	ind_batch_id = -1;
		short	ind_txn_date = -1;
		short	ind_txn_amount = -1;
		short	ind_service_fee = -1;


	/* EXEC SQL END DECLARE SECTION; */ 


	hv_host_date.len = strlen((const char*)cs_date);
        memcpy(hv_host_date.arr,cs_date,hv_host_date.len);
DEBUGLOG(("process_txn::host_date = [%.*s]\n",hv_host_date.len,hv_host_date.arr));

        hv_psp_id.len = strlen((const char*)csPspId);
        memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);
DEBUGLOG(("process_txn::psp_id = [%.*s]\n",hv_psp_id.len,hv_psp_id.arr));

        hv_txn_code.len = strlen((const char*)csTxnCode);
        memcpy(hv_txn_code.arr,csTxnCode,hv_txn_code.len);
DEBUGLOG(("process_txn::txn_code = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));

        hv_txn_code_b.len = strlen((const char*)csTxnCodeB);
        memcpy(hv_txn_code_b.arr,csTxnCodeB,hv_txn_code_b.len);
DEBUGLOG(("process_txn::txn_code_b = [%.*s]\n",hv_txn_code_b.len,hv_txn_code_b.arr));

        hv_status = 'C';
        hv_ar_ind = 'A';

        /* EXEC SQL DECLARE c_cursor_gettxn CURSOR FOR
		select	a.tp_tid,
			a.tp_txn_id,
		 	a.tp_txn_date,
         		a.tp_txn_amount,
         		a.tp_service_fee,
         		a.tp_batch_id
  		   from txn_psp_detail a,
          		txn_header b
		  where a.tp_txn_id = b.th_txn_id
		    and b.th_status = :hv_status
                    and B.TH_AR_IND = :hv_ar_ind
                    and a.tp_txn_date = :hv_host_date
                    and a.tp_psp_id = :hv_psp_id
		    and b.th_txn_code in (:hv_txn_code,:hv_txn_code_b)
		order by a.tp_batch_id; */ 

                
        /* EXEC SQL OPEN c_cursor_gettxn; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
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
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[0] = (unsigned long )1;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_ar_ind;
        sqlstm.sqhstl[1] = (unsigned long )1;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_host_date;
        sqlstm.sqhstl[2] = (unsigned long )10;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_psp_id;
        sqlstm.sqhstl[3] = (unsigned long )12;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_code;
        sqlstm.sqhstl[4] = (unsigned long )5;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_txn_code_b;
        sqlstm.sqhstl[5] = (unsigned long )5;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
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
        if (sqlca.sqlcode < 0) goto sql_error;
}


        do {    
                /* EXEC SQL FETCH c_cursor_gettxn
                INTO	:v_tid:ind_tid,
			:v_txn_id:ind_txn_id,
			:v_txn_date:ind_txn_date,
			:v_txn_amount:ind_txn_amount,
			:v_service_fee:ind_service_fee,
			:v_batch_id:ind_batch_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 6;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )44;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_tid;
                sqlstm.sqhstl[0] = (unsigned long )53;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_tid;
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
                sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_date;
                sqlstm.sqhstl[2] = (unsigned long )17;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_txn_date;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_amount;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_txn_amount;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_service_fee;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_service_fee;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_batch_id;
                sqlstm.sqhstl[5] = (unsigned long )23;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_batch_id;
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
                if (sqlca.sqlcode < 0) goto sql_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }


/* Field #0 tid */
                if (ind_tid < 0 )
                        v_tid.arr[0] = '\0';
                fprintf(fp,"%.*s%c",v_tid.len,v_tid.arr,PD_MY_DELIMITOR);

/* Field #1 txn_date */
                if (ind_txn_date < 0 )
                        v_txn_date.arr[0] = '\0';
                fprintf(fp,"%.*s-%.*s-%.*s%c",PD_YEAR_LEN,v_txn_date.arr,PD_MONTH_LEN,&v_txn_date.arr[PD_MONTH_OS],PD_DAY_LEN,&v_txn_date.arr[PD_DATE_OS],PD_MY_DELIMITOR);

/* Field #2 batch_id */
                if (ind_batch_id < 0 )
                        v_batch_id.arr[0] = '\0';
                fprintf(fp,"%.*s%c",v_batch_id.len,v_batch_id.arr,PD_MY_DELIMITOR);

/* Field #3 txn_id */
                if (ind_txn_id < 0 )
                        v_txn_id.arr[0] = '\0';
                fprintf(fp,"%.*s%c",v_txn_id.len,v_txn_id.arr,PD_MY_DELIMITOR);


/* Field #4 txn_amount */
                if (ind_txn_amount < 0 )
			v_txn_amount = 0.0;
                fprintf(fp,"%ld%c",(long)v_txn_amount,PD_MY_DELIMITOR);

/* Field #5 service_fee */
                if (ind_service_fee < 0 )
			v_service_fee = 0.0;
                fprintf(fp,"%ld",(long)v_service_fee);

		fprintf(fp,"\n");

 	}
        while(PD_TRUE && iRet == SUCCESS);

        /* EXEC SQL CLOSE c_cursor_gettxn; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )83;
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
    sqlstm.arrsiz = 6;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )98;
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
    sqlstm.offset = (unsigned int  )113;
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
        strcpy(cs_outputfile,"");
        strcpy(cs_psp_id,"");
        strcpy(cs_date,"");
        strcpy(cs_txn_code,"");
        strcpy(cs_txn_code_b,"");

        while ((c = getopt(argc,argv,"o:d:p:t:x:")) != EOF) {
                switch (c) {
                        case 'o':
                                strcpy(cs_outputfile, optarg);
                                break;
                        case 'd':
                                strcpy(cs_date, optarg);
                                break;
                        case 'p':
                                strcpy(cs_psp_id, optarg);
                                break;
                        case 't':
                                strcpy(cs_txn_code, optarg);
                                break;
                        case 'x':
                                strcpy(cs_txn_code_b, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_outputfile,"") || !strcmp(cs_date,"") || !strcmp(cs_psp_id,"") || !strcmp(cs_txn_code,"") || !strcmp(cs_txn_code_b,""))
                return FAILURE;

        return SUCCESS;
}

