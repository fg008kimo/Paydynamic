
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
           char  filnam[18];
};
static struct sqlcxp sqlfpn =
{
    17,
    "get_pay_select.pc"
};


static unsigned int sqlctx = 9708427;


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
   unsigned char  *sqhstv[11];
   unsigned long  sqhstl[11];
            int   sqhsts[11];
            short *sqindv[11];
            int   sqinds[11];
   unsigned long  sqharm[11];
   unsigned long  *sqharc[11];
   unsigned short  sqadto[11];
   unsigned short  sqtdso[11];
} sqlstm = {12,11};

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
"select file_seq ,seq_num ,merchant_ref ,account_name ,account_num ,bank_nam\
e ,branch ,province ,city ,amount ,currency  from pay_selection where status=\
'Y' order by seq_num            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,184,0,9,195,0,0,0,0,0,1,0,
20,0,0,1,0,0,13,197,0,0,11,0,0,1,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
79,0,0,1,0,0,15,286,0,0,0,0,0,1,0,
94,0,0,1,0,0,15,293,0,0,0,0,0,1,0,
109,0,0,2,0,0,32,294,0,0,0,0,0,1,0,
124,0,0,3,92,0,6,346,0,0,1,1,0,1,0,1,3,0,0,
143,0,0,4,0,0,32,359,0,0,0,0,0,1,0,
158,0,0,5,102,0,6,376,0,0,1,1,0,1,0,2,3,0,0,
177,0,0,6,0,0,32,393,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2010/12/15              LokMan Chow
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

OBJPTR(DB);
#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define	PD_MY_DELIMITOR		","
#define ALREADY_UPDATED 	10
#define MAX_MERCHANT_NUM	100
#define PD_FILEPATH_LEN		50
#define AMOUNT_LEN		12

char    cs_filepath[PD_FILEPATH_LEN + 1];
char	cs_amount[AMOUNT_LEN+1];
char	cs_mode[7]; //NORMAL, RETRY
char    cDebug;

int process_txn(FILE *fp,const char* csAmount,const char* csMode);
int UpdatePaySelection(const int iSeqNum, const int iRefNum, const char* csMerchRef);
int getLastRefNum();
int RollBackSelection(const int iRefNum);

int batch_init(int argc, char* argv[])
{
    if (argc < 3) {
      	printf("usage: -o outputfile path -a amount -m mode\n");
        return FAILURE;
    }
    else
        return SUCCESS;
}

int parse_arg(int argc,char **argv)
{
        char    c;
        strcpy(cs_filepath,"");
	strcpy(cs_amount,"");
	strcpy(cs_mode,"");

        while ((c = getopt(argc,argv,"o:a:m:")) != EOF) {
                switch (c) {
                        case 'o':
                                strcpy(cs_filepath, optarg);
                                break;
                        case 'a':
                                strcpy(cs_amount, optarg);
                                break;
                        case 'm':
                                strcpy(cs_mode, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_filepath,"") || !strcmp(cs_amount,"") || !strcmp(cs_mode,""))
                return FAILURE;

        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
        int     iRet = SUCCESS;
        char    cs_outfile_name[PD_MAX_FILE_LEN + 1];
	FILE    *fp;
        
	iRet = parse_arg(argc,argv);
        if (iRet != SUCCESS) {
                printf("usage: -o outputfile path -a amount -m mode\n");
                return (iRet);
        }

	char csTime[PD_DATETIME_LEN + 1];
	strcpy(csTime,getdatetime());
	csTime[PD_DATETIME_LEN]='\0';

	sprintf(cs_outfile_name, "%s/PAY_SELECTION-%s-%s.txt",cs_filepath,csTime,cs_amount);
	fp = fopen(cs_outfile_name,"w");
	if (fp != NULL) {
		iRet = process_txn(fp,cs_amount,cs_mode);
	}
	else{
DEBUGLOG(("batch_proc:unable to open [%s]\n",cs_outfile_name));
	}

	fclose(fp);

	return iRet;


}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

int process_txn(FILE *fp, const char* csAmount, const char* csMode)
{               

 
        int     iRet = SUCCESS;
	int	iAmount = atoi(csAmount);

        /* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		
		/* varchar		v_file_seq[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_file_seq;

		int		v_seq_num;
		/* varchar		v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_merchant_ref;

		/* varchar 	v_account_num[PD_AC_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_num;

		/* varchar 	v_account_name[PD_ACC_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_name;

		/* varchar 	v_bank_name[PD_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_name;

		/* varchar 	v_branch[PD_BANK_BRANCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_branch;

		/* varchar		v_province[PD_PROVINCE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_province;

		/* varchar		v_city[PD_CITY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_city;

		/* varchar		v_payout_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_payout_ccy;

		/* varchar		v_amount[AMOUNT_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[13]; } v_amount;

		int		v_ref_num;

		short		ind_file_seq = -1;
                short           ind_seq_num = -1;
                short           ind_merchant_ref = -1;
                short           ind_account_num = -1;
                short           ind_account_name = -1;
                short           ind_bank_name = -1;
                short           ind_branch = -1;
                short           ind_province = -1;
                short           ind_city = -1;
                short           ind_payout_ccy = -1;
                short           ind_amount = -1;


	/* EXEC SQL END DECLARE SECTION; */ 


	if(strcmp(csMode,"RETRY")){
		v_ref_num = getLastRefNum() + 1;
		if(v_ref_num<0)
			return FAILURE;
	}
	else{
		v_ref_num = getLastRefNum();
		if(v_ref_num<0)
			return FAILURE;

		if(RollBackSelection(v_ref_num)!=SUCCESS)
			return FAILURE;
	}

        /* EXEC SQL DECLARE c_cursor_gettxn CURSOR FOR
		select  file_seq,
			seq_num,
                        merchant_ref,
                        account_name,
                        account_num,
                        bank_name,
                        branch,
                        province,
                        city,
                        amount,
                        currency
  		   from pay_selection
		   where status='Y'
		  order by seq_num; */ 

                
        /* EXEC SQL OPEN c_cursor_gettxn; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 0;
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
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto sql_error;
}


        do {    
                /* EXEC SQL FETCH c_cursor_gettxn
                INTO	:v_file_seq:ind_file_seq,
			:v_seq_num:ind_seq_num,
                        :v_merchant_ref:ind_merchant_ref,
                        :v_account_name:ind_account_name,
                        :v_account_num:ind_account_num,
                        :v_bank_name:ind_bank_name,
                        :v_branch:ind_branch,
                        :v_province:ind_province,
                        :v_city:ind_city,
                        :v_amount:ind_amount,
                        :v_payout_ccy:ind_payout_ccy; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 11;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )20;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_file_seq;
                sqlstm.sqhstl[0] = (unsigned long )19;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_file_seq;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_seq_num;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_seq_num;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_merchant_ref;
                sqlstm.sqhstl[2] = (unsigned long )28;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_merchant_ref;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_account_name;
                sqlstm.sqhstl[3] = (unsigned long )28;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_account_name;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_account_num;
                sqlstm.sqhstl[4] = (unsigned long )28;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_account_num;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_bank_name;
                sqlstm.sqhstl[5] = (unsigned long )53;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_bank_name;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_branch;
                sqlstm.sqhstl[6] = (unsigned long )28;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_branch;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_province;
                sqlstm.sqhstl[7] = (unsigned long )23;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_province;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_city;
                sqlstm.sqhstl[8] = (unsigned long )23;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_city;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_amount;
                sqlstm.sqhstl[9] = (unsigned long )15;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_amount;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_payout_ccy;
                sqlstm.sqhstl[10] = (unsigned long )6;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_payout_ccy;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
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

		if(ind_amount<0)
			continue;
		v_amount.arr[v_amount.len]='\0';
		if(atoi(v_amount.arr)<=iAmount){
			iAmount = iAmount - atoi(v_amount.arr);
		}
		else
			break;

/* Field #0 file_seq */
		if (ind_file_seq < 0 )
			v_file_seq.arr[0] = '\0';
		fprintf(fp,"%.*s%s",v_file_seq.len,v_file_seq.arr,PD_MY_DELIMITOR);


/* Field #1 merchant_ref */
                if (ind_merchant_ref < 0 )
                        v_merchant_ref.arr[0] = '\0';
		else
			v_merchant_ref.arr[v_merchant_ref.len] = '\0';
                fprintf(fp,"%.*s%s",v_merchant_ref.len,v_merchant_ref.arr,PD_MY_DELIMITOR);


/* Field #2 account_num */
                if (ind_account_num < 0 )
			v_account_num.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_account_num.len,v_account_num.arr,PD_MY_DELIMITOR);


/* Field #3  account_name*/
                if (ind_account_name < 0 )
                        v_account_name.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_account_name.len,v_account_name.arr,PD_MY_DELIMITOR);

/* Field #4  bank_name*/
                if (ind_bank_name< 0 )
                        v_bank_name.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_bank_name.len,v_bank_name.arr,PD_MY_DELIMITOR);

/* Field #5  branch*/
                if (ind_branch< 0 )
                        v_branch.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_branch.len,v_branch.arr,PD_MY_DELIMITOR);

/* Field #6 amount*/
                //if (ind_amount< 0 )
		//	v_amount.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_amount.len,v_amount.arr,PD_MY_DELIMITOR);

/* Field #7 payout_ccy*/
                if (ind_payout_ccy< 0 )
                        v_payout_ccy.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_payout_ccy.len,v_payout_ccy.arr,PD_MY_DELIMITOR);

/* Field #8 province*/
                if (ind_province< 0 )
                        v_province.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_province.len,v_province.arr,PD_MY_DELIMITOR);

/* Field #9 city*/
                if (ind_city< 0 )
                        v_city.arr[0] = '\0';
                fprintf(fp,"%.*s\n",v_city.len,v_city.arr);


		UpdatePaySelection(v_seq_num,v_ref_num,v_merchant_ref.arr);

	}
	while(PD_TRUE && iRet == SUCCESS);

	

	/* EXEC SQL CLOSE c_cursor_gettxn; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )79;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto sql_error;
}


DEBUGLOG(("RET = [%d]\n",iRet));
        return iRet;
sql_error:
    DEBUGLOG(("process_txn error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_gettxn; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 11;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )94;
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
    sqlstm.arrsiz = 11;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )109;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}



int UpdatePaySelection(const int iSeqNum, const int iRefNum, const char* csMerchRef)
{
	int iRet = SUCCESS;
	char *csSeqNum=strdup("");
	char *csRefNum=strdup("");
	hash_t *hUpd;
	hUpd = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hUpd,0);

	sprintf(csSeqNum,"%d",iSeqNum);
	sprintf(csRefNum,"%d",iRefNum);

	PutField_Char(hUpd,"status",'X');
	PutField_CString(hUpd,"ref_num",csRefNum);
	PutField_CString(hUpd,"merchant_ref",csMerchRef);
	PutField_CString(hUpd,"seq_num",csSeqNum);
	DBObjPtr = CreateObj(DBPtr,"DBPaySelection","UpdateStatus");
	if((unsigned long int)(*DBObjPtr)(hUpd) == SUCCESS){
DEBUGLOG(("Update Payout Status Success:SeqNum[%s] MerchRef[%s]\n",csSeqNum,csMerchRef));
	}
	else{
DEBUGLOG(("Update Payout Status Failed:SeqNum[%s] MerchRef[%s]\n",csSeqNum,csMerchRef));
		iRet = FAILURE;
	}

	hash_destroy(hUpd);
	FREE_ME(hUpd);
	FREE_ME(csSeqNum);
	FREE_ME(csRefNum);

	return iRet;

}

int RollBackSelection(const int iRefNum)
{
	int iRet = SUCCESS;
	/* EXEC SQL WHENEVER SQLERROR GOTO rollback_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int     v_ref_num;
	/* EXEC SQL END DECLARE SECTION; */ 

	
	v_ref_num=iRefNum;

	/* EXEC SQL EXECUTE
                BEGIN
			UPDATE	pay_selection
			SET	status='Y', ref_num=0
			where	ref_num=:v_ref_num;
		END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin UPDATE pay_selection SET status = 'Y' , ref_num = 0 w\
here ref_num = :v_ref_num ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )124;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_ref_num;
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
 if (sqlca.sqlcode < 0) goto rollback_error;
}



	return iRet;
rollback_error:
    DEBUGLOG(("rollback selection error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 11;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )143;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}

int getLastRefNum()
{
	int iResult = 0;
	/* EXEC SQL WHENEVER SQLERROR GOTO get_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		int	v_ref_num;
		short	ind_ref_num = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        /* EXEC SQL EXECUTE
                BEGIN
                        SELECT  max(ref_num)
                        INTO    :v_ref_num:ind_ref_num
                        FROM    pay_selection
                        WHERE   status='X';
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin SELECT max ( ref_num ) INTO :v_ref_num:ind_ref\
_num FROM pay_selection WHERE status = 'X' ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )158;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_ref_num;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_ref_num;
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



	if(ind_ref_num>=0)
		iResult = v_ref_num;

	return iResult;
get_error:
    DEBUGLOG(("get last ref_num error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 11;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )177;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return -100;
}
