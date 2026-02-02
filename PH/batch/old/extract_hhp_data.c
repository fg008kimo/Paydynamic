
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
           char  filnam[20];
};
static struct sqlcxp sqlfpn =
{
    19,
    "extract_hhp_data.pc"
};


static unsigned int sqlctx = 40118659;


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
"select tp_txn_id ,tp_txn_amount ,tp_tid ,tp_fundin_date_short  from txn_psp\
_detail ,txn_header where (((((tp_txn_id=th_txn_id and th_status='C') and th_\
ar_ind='A') and tp_fundin_date_short=:b0) and tp_psp_id=:b1) and th_txn_code=\
:b2) order by tp_txn_id            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,264,0,9,142,0,0,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
32,0,0,1,0,0,13,144,0,0,4,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
63,0,0,1,0,0,15,191,0,0,0,0,0,1,0,
78,0,0,1,0,0,15,197,0,0,0,0,0,1,0,
93,0,0,2,0,0,32,198,0,0,0,0,0,1,0,
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
char    cs_date[PD_DATE_LEN + 1];
char    cDebug;

int parse_arg(int argc,char **argv);
int process_txn(const char* csPspId,const char* csTxnCode,
                FILE *fp);
int batch_init(int argc, char* argv[])
{

    if (argc < 4) {
        printf("usage:  -o ouputfile -d Date -p PSP ID -t Txn Code\n");
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
        	printf("usage:  -o ouputfile -d Date -p PSP ID -t Txn Code\n");
                return (iRet);
        }

	//if (CreateReportPath(cs_psp_id,cs_outfile_name) != SUCCESS) 
        //        return FAILURE;

        sprintf(cs_outfile_name, "%s/%s_%s.dat", getenv("REPORT_DATA"),cs_outputfile,cs_date);
        
        fp = fopen(cs_outfile_name,"w");
        if (fp == NULL) {
DEBUGLOG(("batch_proc:unable to open [%s]\n",cs_outfile_name));
                return FAILURE;
        }
        
        iRet = process_txn(cs_psp_id,cs_txn_code,fp);
        fclose(fp);
	return iRet;


}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}




int process_txn(const char* csPspId,const char* csTxnCode,
                FILE *fp)
{               
 
        int     iRet = SUCCESS;
	double	dTmp;
        
        /* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		
		/* varchar	hv_host_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_host_date;

		/* varchar	hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar	hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;


		/* varchar	v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar	v_tid[PD_PSP_TID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_tid;

		/* varchar	v_txn_amount[PD_AMOUNT_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[13]; } v_txn_amount;

		/* varchar	v_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_txn_date;


		short	ind_txn_id = -1;
		short	ind_tid = -1;
		short	ind_txn_amount = -1;
		short	ind_txn_date = -1;


	/* EXEC SQL END DECLARE SECTION; */ 


	hv_host_date.len = strlen(cs_date);
        memcpy(hv_host_date.arr,cs_date,hv_host_date.len);
DEBUGLOG(("process_txn::host_date = [%.*s]\n",hv_host_date.len,hv_host_date.arr));

        hv_psp_id.len = strlen(csPspId);
        memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);
DEBUGLOG(("process_txn::psp_id = [%.*s]\n",hv_psp_id.len,hv_psp_id.arr));

        hv_txn_code.len = strlen(csTxnCode);
        memcpy(hv_txn_code.arr,csTxnCode,hv_txn_code.len);
DEBUGLOG(("process_txn::txn_code = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));


        /* EXEC SQL DECLARE c_cursor_gettxn CURSOR FOR
		select 	tp_txn_id,
         		tp_txn_amount,
			tp_tid,
			tp_fundin_date_short
  		   from txn_psp_detail,
          		txn_header
		  where tp_txn_id = th_txn_id
		    and th_status = 'C'
                    and th_ar_ind = 'A'
                    and tp_fundin_date_short = :hv_host_date
                    and tp_psp_id = :hv_psp_id
		    and th_txn_code = :hv_txn_code
		order by tp_txn_id; */ 

                
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
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_host_date;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_code;
        sqlstm.sqhstl[2] = (unsigned long )5;
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
			:v_txn_id:ind_txn_id,
			:v_txn_amount:ind_txn_amount,
			:v_tid:ind_tid,
			:v_txn_date:ind_txn_date; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 4;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_amount;
                sqlstm.sqhstl[1] = (unsigned long )15;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_txn_amount;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_tid;
                sqlstm.sqhstl[2] = (unsigned long )53;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_tid;
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
		if(ind_tid < 0)
			v_tid.arr[0] = '\0';
		fprintf(fp,"%.*s%c",v_tid.len,v_tid.arr,PD_MY_DELIMITOR);

/* Field #1 txn_seq */
                if (ind_txn_id < 0 )
                        v_txn_id.arr[0] = '\0';
                fprintf(fp,"%.*s%c",v_txn_id.len,v_txn_id.arr,PD_MY_DELIMITOR);


/* Field #2 txn_amount */
                if (ind_txn_amount < 0 )
			v_txn_amount.arr[0] = '\0';
		v_txn_amount.arr[v_txn_amount.len] = '\0';

		//if(is_numeric(v_txn_amount.arr)==PD_TRUE){
		//	fprintf(fp,"%s%c",v_txn_amount.arr,PD_MY_DELIMITOR);
                //}
                //else{
			sscanf((const char*)v_txn_amount.arr,"%lf",&dTmp);
                	fprintf(fp,"%.2lf%c",dTmp,PD_MY_DELIMITOR);
		//}

/* Field #4 status */
		fprintf(fp,"Success%c",PD_MY_DELIMITOR);


/* Host Date*/
		fprintf(fp,"%.*s-%.*s-%.*s",PD_YYYY_LEN,v_txn_date.arr, PD_MM_LEN, &v_txn_date.arr[PD_YYYY_LEN],PD_DD_LEN, &v_txn_date.arr[PD_YYYYMM_LEN]);

		fprintf(fp,"\n");

 	}
        while(PD_TRUE && iRet == SUCCESS);

        /* EXEC SQL CLOSE c_cursor_gettxn; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )63;
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
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )78;
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
    sqlstm.offset = (unsigned int  )93;
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
        strcpy(cs_txn_code,"");
        strcpy(cs_date,"");

        while ((c = getopt(argc,argv,"o:p:t:d:")) != EOF) {
                switch (c) {
                        case 'o':
                                strcpy(cs_outputfile, optarg);
                                break;
                        case 'p':
                                strcpy(cs_psp_id, optarg);
                                break;
                        case 't':
                                strcpy(cs_txn_code, optarg);
                                break;
                        case 'd':
                                strcpy(cs_date, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_outputfile,"") || !strcmp(cs_psp_id,"") || !strcmp(cs_txn_code,"") ||!strcmp(cs_date,""))
                return FAILURE;

        return SUCCESS;
}

