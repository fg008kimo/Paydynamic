
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
    "extract_merchant_dsp_data.pc"
};


static unsigned int sqlctx = 933523581;


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
   unsigned char  *sqhstv[7];
   unsigned long  sqhstl[7];
            int   sqhsts[7];
            short *sqindv[7];
            int   sqinds[7];
   unsigned long  sqharm[7];
   unsigned long  *sqharc[7];
   unsigned short  sqadto[7];
   unsigned short  sqtdso[7];
} sqlstm = {12,7};

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
"select th_merchant_ref ,th_host_posting_date ,th_transaction_amount ,th_net\
_ccy ,th_txn_id ,th_status ,th_ar_ind  from txn_header where ((th_txn_code in\
 ('DSP','DSI') and th_host_posting_date=:b0) and th_merchant_id=:b1) order by\
 th_merchant_ref            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,257,0,9,203,0,0,2,2,0,1,0,1,9,0,0,1,9,0,0,
28,0,0,1,0,0,13,205,0,0,7,0,0,1,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,1,
0,0,2,1,0,0,
71,0,0,1,0,0,15,271,0,0,0,0,0,1,0,
86,0,0,1,0,0,15,277,0,0,0,0,0,1,0,
101,0,0,2,0,0,32,278,0,0,0,0,0,1,0,
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

#define	PD_MY_DELIMITOR		','
//#define MERCH_REF_HEAD_LEN	4
//#define MERCH_REF_TAIL_LEN	6
#define MAX_MERCHANT_NUM        100

char    cs_outfile[PD_MAX_FILE_LEN + 1];
char    cs_merchant_id[PD_PSP_ID_LEN + 1];
char    cs_txn_code[PD_TXN_CODE_LEN + 1];
char    cs_date[PD_DATE_LEN + 1];
char    cDebug='Y';

int process_txn(const char* csPspId,const char* csTxnCode,const char* csMerchId,
                FILE *fp);
//int getAllMerchId(char (*csMerchIdList)[PD_MERCHANT_ID_LEN+1]);

int batch_init(int argc, char* argv[])
{

	if (argc < 4) {
        	printf("usage:  -o ouputfile -d Date -m Merchant ID -t Txn Code\n");
        	return FAILURE;
	}

	return SUCCESS;
}

int parse_arg(int argc,char **argv)
{
        char    c;
        strcpy(cs_outfile,"");
        strcpy(cs_merchant_id,"");
        strcpy(cs_txn_code,"");
        strcpy(cs_date,"");

        while ((c = getopt(argc,argv,"o:m:t:d:")) != EOF) {
                switch (c) {
                        case 'o':
                                strcpy(cs_outfile, optarg);
                                break;
                        case 'm':
                                strcpy(cs_merchant_id, optarg);
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

        if (!strcmp(cs_outfile,"") || !strcmp(cs_merchant_id,"") || !strcmp(cs_txn_code,"") || !strcmp(cs_date,""))
                return FAILURE;

        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
        int     iRet = SUCCESS;
        char    cs_outfile_name[PD_MAX_FILE_LEN + 1];
        FILE    *fp;
	//int	iNumOfRecord = 0;
	//char    csMerchIdList[MAX_MERCHANT_NUM][PD_MERCHANT_ID_LEN+1];
        
	iRet = parse_arg(argc,argv);

        if (iRet != SUCCESS){
        	printf("usage:  -o ouputfile -d Date -m Merchant ID -t Txn Code\n");
                return (iRet);
        }
 
        /*
	if(iRet==SUCCESS){
                iNumOfRecord = getAllMerchId(csMerchIdList);
        }
	*/

	//if(iNumOfRecord>0){
	//	int i;
        //        for(i=0;i<iNumOfRecord;i++){
        		sprintf(cs_outfile_name, "%s/%s-%s-%s.dat", getenv("REPORT_DATA"),cs_outfile,cs_merchant_id,cs_date);
        
        		fp = fopen(cs_outfile_name,"w");
        		if (fp == NULL) {
DEBUGLOG(("batch_proc:unable to open [%s]\n",cs_outfile_name));
        		}
			else{
				iRet = process_txn(cs_merchant_id,cs_txn_code,cs_merchant_id,fp);
DEBUGLOG(("process_txn: iRet [%d]\n",iRet));
			}
        
        		fclose(fp);
	//	}
	//}
	//else{
//DEBUGLOG(("batch_proc: Merchant ID not found\n"));
//	}
	return iRet;


}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}




int process_txn(const char* csPspId,const char* csTxnCode,const char* csMerchId,
                FILE *fp)
{               
 	char    *csTmp;// = strdup("");
        int     iRet = SUCCESS;
        
        /* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		
		/* varchar	hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

		//varchar hv_psp_id[PD_PSP_ID_LEN];
		/* varchar	hv_host_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_host_date;

		/* varchar hv_merch_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merch_id;

		char	v_status;
		char	v_ar_ind;

		/* varchar	v_txn_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

		/* varchar	v_txn_id[PD_TXN_SEQ_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar	v_merch_ref[PD_MERCHANT_REF_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merch_ref;

		/* varchar	v_txn_date[PD_DATE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_txn_date;

		double	v_txn_amount;

		short	ind_txn_ccy = -1;
		short	ind_txn_id = -1;
		short	ind_merch_ref = -1;
		short	ind_txn_date = -1;
		short	ind_txn_amount = -1;
		short	ind_status= -1;
		short	ind_ar_ind= -1;


	/* EXEC SQL END DECLARE SECTION; */ 


	hv_host_date.len = strlen(cs_date);
        memcpy(hv_host_date.arr,cs_date,hv_host_date.len);
DEBUGLOG(("process_txn::host_date = [%.*s]\n",hv_host_date.len,hv_host_date.arr));

        hv_txn_code.len = strlen(csTxnCode);
        memcpy(hv_txn_code.arr,csTxnCode,hv_txn_code.len);
DEBUGLOG(("process_txn::txn_code = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));
/*
        hv_psp_id.len = strlen(csPspId);
        memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);
DEBUGLOG(("process_txn::psp_id= [%.*s]\n",hv_psp_id.len,hv_psp_id.arr));
*/
        hv_merch_id.len = strlen(csMerchId);
        memcpy(hv_merch_id.arr,csMerchId,hv_merch_id.len);
DEBUGLOG(("process_txn::merch_id= [%.*s]\n",hv_merch_id.len,hv_merch_id.arr));


        /* EXEC SQL DECLARE c_cursor_gettxn CURSOR FOR
		select 	th_merchant_ref,
         		th_host_posting_date,
         		th_transaction_amount,
			th_net_ccy,
			th_txn_id,
			th_status,
			th_ar_ind
  		   from txn_header 
		  where th_txn_code in ('DSP','DSI') 
                    and th_host_posting_date= :hv_host_date
		    //and tp_txn_id = th_txn_id
		    //and tp_psp_id = :hv_psp_id
		    and th_merchant_id = :hv_merch_id
		   order by th_merchant_ref; */ 

                
        /* EXEC SQL OPEN c_cursor_gettxn; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_merch_id;
        sqlstm.sqhstl[1] = (unsigned long )17;
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
        if (sqlca.sqlcode < 0) goto sql_error;
}


        do {    
                /* EXEC SQL FETCH c_cursor_gettxn
                INTO
			:v_merch_ref:ind_merch_ref,
			:v_txn_date:ind_txn_date,
			:v_txn_amount:ind_txn_amount,
			:v_txn_ccy:ind_txn_ccy,
			:v_txn_id:ind_txn_id,
			:v_status:ind_status,
			:v_ar_ind:ind_ar_ind; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 7;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )28;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_merch_ref;
                sqlstm.sqhstl[0] = (unsigned long )53;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_merch_ref;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_date;
                sqlstm.sqhstl[1] = (unsigned long )11;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_txn_date;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_amount;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_txn_amount;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_ccy;
                sqlstm.sqhstl[3] = (unsigned long )6;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_txn_ccy;
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
                sqlstm.sqhstv[5] = (unsigned char  *)&v_status;
                sqlstm.sqhstl[5] = (unsigned long )1;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_status;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_ar_ind;
                sqlstm.sqhstl[6] = (unsigned long )1;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_ar_ind;
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
                if (sqlca.sqlcode < 0) goto sql_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

/* Field #0 merch_ref */
                if (ind_merch_ref < 0 )
                        v_merch_ref.arr[0] = '\0';
		fprintf(fp,"%.*s%c",v_merch_ref.len,v_merch_ref.arr,PD_MY_DELIMITOR);


/* Field #1 txn_date */
                if (ind_txn_date < 0 )
                        v_txn_date.arr[0] = '\0';
                fprintf(fp,"%.*s/%.*s/%.*s%c",PD_MONTH_LEN,&v_txn_date.arr[PD_MONTH_OS],PD_DAY_LEN,&v_txn_date.arr[PD_DATE_OS],PD_YEAR_LEN,v_txn_date.arr,PD_MY_DELIMITOR);

/*status*/
		if(ind_status < 0)
			csTmp = strdup("");
		else
                {
                        if(v_status == 'W')
                                csTmp = strdup("PENDING");
                        else if(v_status == 'P')
                                csTmp = strdup("PROCESSING");
                        else{
                                if(ind_ar_ind < 0)
					csTmp = strdup("");
				else
                                {
                                        if (v_ar_ind == 'A')
                                                csTmp = strdup("APPROVED");
                                        else
                                                csTmp = strdup("REJECTED");
                                }
                        }
                }
		fprintf(fp,"%s%c",csTmp,PD_MY_DELIMITOR);
		FREE_ME(csTmp);
		
/* Field #2 ccy_id & txn_amount */
		if (ind_txn_ccy < 0 )
			v_txn_ccy.arr[0] = '\0';
		fprintf(fp,"%.*s",v_txn_ccy.len,v_txn_ccy.arr);

                if (ind_txn_amount < 0 )
			v_txn_amount = 0.0;
                fprintf(fp,"%.2f%c",v_txn_amount,PD_MY_DELIMITOR);

/* Field #3 txn_id */
		fprintf(fp,"%.*s",v_txn_id.len,v_txn_id.arr);

		fprintf(fp,"\n");

 	}
        while(PD_TRUE && iRet == SUCCESS);

        /* EXEC SQL CLOSE c_cursor_gettxn; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )71;
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
    sqlstm.arrsiz = 7;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )86;
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
    sqlstm.arrsiz = 7;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )101;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}


/*
int getAllMerchId(char (*csMerchIdList)[PD_MERCHANT_ID_LEN+1])
{
        int iRet = 0;
        EXEC SQL WHENEVER SQLERROR GOTO get_error;
        EXEC SQL WHENEVER NOTFOUND CONTINUE;

        EXEC SQL BEGIN DECLARE SECTION;
                char            hv_type;
                int             hv_disabled;

                varchar         v_merch_id[PD_MERCHANT_ID_LEN+1];

                short           ind_merch_id = -1;
        EXEC SQL END DECLARE SECTION;

        hv_type = 'M';
        hv_disabled = 0;

        EXEC SQL DECLARE c_cursor_getmerchantid CURSOR FOR
                select  b.merchant_id
                from    clients a,
                        merch_detail b
                where   a.type = :hv_type
                and     b.client_id = a.client_id
                and     b.disabled = :hv_disabled;

        EXEC SQL OPEN c_cursor_getmerchantid;
        do{
                EXEC SQL FETCH c_cursor_getmerchantid
                INTO    :v_merch_id:ind_merch_id;


                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

///merch_id///
                if(ind_merch_id >= 0){
                        ///hardcode
                        ///strcpy(csMerchIdList[iRet],"888000130");
                        ///csMerchIdList[iRet][strlen("888000130")]='\0';
			////
                        strcpy(csMerchIdList[iRet],v_merch_id.arr);
                        csMerchIdList[iRet][v_merch_id.len]='\0';
DEBUGLOG(("Client type[%c]  Valid MerchId[%s]\n",hv_type,csMerchIdList[iRet]));
                        iRet++;
                }

        }while(PD_TRUE);


        EXEC SQL CLOSE c_cursor_getmerchantid;
	return iRet;

get_error:
    DEBUGLOG(("get merchant id: error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    EXEC SQL WHENEVER SQLERROR CONTINUE;
    EXEC SQL CLOSE c_cursor_getmerchantid;
    EXEC SQL ROLLBACK RELEASE;
    return 0;
}
*/
