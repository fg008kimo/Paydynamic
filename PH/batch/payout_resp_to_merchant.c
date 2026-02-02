
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
           char  filnam[27];
};
static struct sqlcxp sqlfpn =
{
    26,
    "payout_resp_to_merchant.pc"
};


static unsigned int sqlctx = 915504315;


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
   unsigned char  *sqhstv[17];
   unsigned long  sqhstl[17];
            int   sqhsts[17];
            short *sqindv[17];
            int   sqinds[17];
   unsigned long  sqharm[17];
   unsigned long  *sqharc[17];
   unsigned short  sqadto[17];
   unsigned short  sqtdso[17];
} sqlstm = {12,17};

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
"select b.merchant_id  from clients a ,merch_detail b where ((a.type=:b0 and\
 b.client_id=a.client_id) and b.disabled=:b1)           ";

 static char *sq0005 = 
"select a.seq_num ,a.merchant_ref ,a.country ,a.identity_id ,a.account_name \
,a.account_num ,a.bank_name ,a.bank_code ,a.branch ,a.phone_num ,a.province ,\
a.city ,a.amount ,a.payout_currency ,a.dest_currency ,a.checksum ,c.th_txn_id\
  from payout_record a ,payout_header b ,txn_header c where (((((b.merchant_i\
d=:b0 and b.txn_date=:b1) and a.merchant_id=b.merchant_id) and a.batch_id=b.b\
atch_id) and c.th_merchant_ref=a.merchant_ref) and c.th_merchant_id=a.merchan\
t_id) order by a.seq_num            ";

 static char *sq0007 = 
"select a.seq_num ,a.merchant_ref ,a.country ,a.identity_id ,a.account_name \
,a.account_num ,a.bank_name ,a.bank_code ,a.branch ,a.phone_num ,a.province ,\
a.city ,a.amount ,a.payout_currency ,a.dest_currency ,a.checksum  from payout\
_record a ,payout_header b where (((((b.merchant_id=:b0 and b.txn_date=:b1) a\
nd a.merchant_id=b.merchant_id) and a.batch_id=b.batch_id) and a.status='R') \
and a.response_code>=1000) order by a.seq_num            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,131,0,9,168,0,0,2,2,0,1,0,1,1,0,0,1,3,0,0,
28,0,0,1,0,0,13,170,0,0,1,0,0,1,0,2,9,0,0,
47,0,0,1,0,0,15,189,0,0,0,0,0,1,0,
62,0,0,1,0,0,15,196,0,0,0,0,0,1,0,
77,0,0,2,0,0,32,197,0,0,0,0,0,1,0,
92,0,0,3,186,0,6,230,0,0,4,4,0,1,0,2,3,0,0,2,9,0,0,1,9,0,0,1,9,0,0,
123,0,0,4,0,0,32,256,0,0,0,0,0,1,0,
138,0,0,5,496,0,9,351,0,0,2,2,0,1,0,1,9,0,0,1,9,0,0,
161,0,0,5,0,0,13,353,0,0,17,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,
244,0,0,5,0,0,15,468,0,0,0,0,0,1,0,
259,0,0,5,0,0,15,475,0,0,0,0,0,1,0,
274,0,0,6,0,0,32,476,0,0,0,0,0,1,0,
289,0,0,7,440,0,9,566,0,0,2,2,0,1,0,1,9,0,0,1,9,0,0,
312,0,0,7,0,0,13,568,0,0,16,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,
391,0,0,7,0,0,15,680,0,0,0,0,0,1,0,
406,0,0,7,0,0,15,687,0,0,0,0,0,1,0,
421,0,0,8,0,0,32,688,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2010/11/23              LokMan Chow
only process merchant 8000000001                   2011/03/29              LokMan Chow
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


char    cs_date[PD_DATE_LEN + 1];
char    cs_filepath[PD_FILEPATH_LEN + 1];
char    cDebug;

int process_header(const char* csMerchId,FILE *fp);
int process_txn(const char *csMerchId,FILE *fp);
int process_not_sent(const char *csMerchId,FILE *fp);
int getAllMerchId(char (*csMerchIdList)[PD_MERCHANT_ID_LEN+1]);



int batch_init(int argc, char* argv[])
{
    if (argc < 3) {
      	printf("usage: -d date -o outputfile path\n");
        return FAILURE;
    }
    else
        return SUCCESS;
}

int parse_arg(int argc,char **argv)
{
        char    c;
        strcpy(cs_date,"");
        strcpy(cs_filepath,"");

        while ((c = getopt(argc,argv,"d:o:")) != EOF) {
                switch (c) {
                        case 'd':
                                strcpy(cs_date, optarg);
                                break;
                        case 'o':
                                strcpy(cs_filepath, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_date,"") || !strcmp(cs_filepath,"") )
                return FAILURE;

        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
        int     iRet = SUCCESS;
        char    cs_outfile_name[PD_MAX_FILE_LEN + 1];
	char	csMerchIdList[MAX_MERCHANT_NUM][PD_MERCHANT_ID_LEN+1];
	FILE    *fp;
	int	iNumOfRecord = 0;
        
	iRet = parse_arg(argc,argv);
        if (iRet != SUCCESS) {
                printf("usage: -d date -o outputfile path\n");
                return (iRet);
        }

	if(iRet==SUCCESS){
		iNumOfRecord = getAllMerchId(csMerchIdList);
	}

	if(iNumOfRecord>0){
		int i;
		for(i=0;i<iNumOfRecord;i++){
			if(strcmp(csMerchIdList[i],"8000000001")){
                                continue;
                        }
			sprintf(cs_outfile_name, "%s/PAYOUT-%s-%s.csv",cs_filepath,csMerchIdList[i],cs_date);
			fp = fopen(cs_outfile_name,"w");
			if (fp != NULL) {
			

				iRet = process_header(csMerchIdList[i],fp);
				
				if(iRet==SUCCESS)
					iRet = process_txn(csMerchIdList[i],fp);
					if(iRet==SUCCESS)
						iRet = process_not_sent(csMerchIdList[i],fp);

			}
			else
DEBUGLOG(("batch_proc:unable to open [%s]\n",cs_outfile_name));

			fclose(fp);
		}
	}

	return iRet;


}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


int getAllMerchId(char (*csMerchIdList)[PD_MERCHANT_ID_LEN+1])
{
	int iRet = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO get_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		char		hv_type;
		int		hv_disabled;

		/* varchar		v_merch_id[PD_MERCHANT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merch_id;


		short		ind_merch_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_type = 'M';
	hv_disabled = 0;

	/* EXEC SQL DECLARE c_cursor_getmerchantid CURSOR FOR
		select	b.merchant_id
		from	clients a,
			merch_detail b
		where	a.type = :hv_type
		and	b.client_id = a.client_id
		and	b.disabled = :hv_disabled; */ 

		
	/* EXEC SQL OPEN c_cursor_getmerchantid; */ 

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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_type;
 sqlstm.sqhstl[0] = (unsigned long )1;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_disabled;
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


	do{
		/* EXEC SQL FETCH c_cursor_getmerchantid
		INTO	:v_merch_id:ind_merch_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 2;
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
  sqlstm.sqhstv[0] = (unsigned char  *)&v_merch_id;
  sqlstm.sqhstl[0] = (unsigned long )18;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_merch_id;
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



		
                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

/*merch_id*/
		if(ind_merch_id >= 0){
			strcpy(csMerchIdList[iRet],(const char*)v_merch_id.arr);
			csMerchIdList[iRet][v_merch_id.len]='\0';
DEBUGLOG(("Client type[%c]  Valid MerchId[%s]\n",hv_type,csMerchIdList[iRet]));
			iRet++;
		}

	}while(PD_TRUE);


	/* EXEC SQL CLOSE c_cursor_getmerchantid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )47;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto get_error;
}


        return iRet;

get_error:
    DEBUGLOG(("get merchant id: error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getmerchantid; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 2;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )62;
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
    sqlstm.arrsiz = 2;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )77;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return 0;
}


int process_header(const char* csMerchId,FILE *fp)
{
	int     iRet = SUCCESS;

	/* EXEC SQL WHENEVER SQLERROR GOTO header_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar         hv_txn_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_txn_date;

                /* varchar         hv_merch_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merch_id;


		int		v_num_of_rec;
		/* varchar		v_checksum[PD_CHECKSUM_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_checksum;


		short		ind_num_of_rec=-1;
		short		ind_checksum=-1;
	
	/* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_date.len = strlen(cs_date);
        memcpy(hv_txn_date.arr,cs_date,hv_txn_date.len);
DEBUGLOG(("process_header::txn_date = [%.*s]\n",hv_txn_date.len,hv_txn_date.arr));

        hv_merch_id.len = strlen(csMerchId);
        memcpy(hv_merch_id.arr,csMerchId,hv_merch_id.len);
DEBUGLOG(("process_header::merch_id = [%.*s]\n",hv_merch_id.len,hv_merch_id.arr));

	/* EXEC SQL EXECUTE
		BEGIN
                select  num_of_record,checksum
		into	:v_num_of_rec:ind_num_of_rec , :v_checksum:ind_checksum
		from	payout_header
		where	merchant_id=:hv_merch_id
		and	txn_date=:hv_txn_date;

		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin select num_of_record , checksum into :v_num_of_rec:in\
d_num_of_rec , :v_checksum:ind_checksum from payout_header where merchant_id \
= :hv_merch_id and txn_date = :hv_txn_date ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )92;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_num_of_rec;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_num_of_rec;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_checksum;
 sqlstm.sqhstl[1] = (unsigned long )19;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_checksum;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_merch_id;
 sqlstm.sqhstl[2] = (unsigned long )17;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_date;
 sqlstm.sqhstl[3] = (unsigned long )10;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto header_error;
}



	if(ind_num_of_rec<0)	v_num_of_rec=0;
	if(ind_checksum<0)	v_checksum.arr[0]='\0';


        fprintf(fp,"%.*s%s",hv_merch_id.len,hv_merch_id.arr,PD_MY_DELIMITOR);
        fprintf(fp,"%d%s",v_num_of_rec,PD_MY_DELIMITOR);
        fprintf(fp,"%.*s\n",v_checksum.len,v_checksum.arr);
	

	return iRet;

header_error:
    DEBUGLOG(("process_header error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )123;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}


int process_txn(const char* csMerchId,FILE *fp)
{               
 
        int     iRet = SUCCESS;
 
        /* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		
		/* varchar		hv_txn_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_txn_date;

		/* varchar		hv_merch_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merch_id;


		/* varchar		v_seq_num[PD_SEQ_NUM_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_seq_num;

		/* varchar		v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar 	v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		/* varchar 	v_identity_id[PD_IDENTITY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_identity_id;

		/* varchar 	v_account_num[PD_AC_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_num;

		/* varchar 	v_account_name[PD_ACC_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_name;

		/* varchar 	v_bank_name[PD_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_name;

		/* varchar 	v_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

		/* varchar 	v_branch[PD_BANK_BRANCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_branch;

		/* varchar		v_phone_num[PD_MOBILE_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_phone_num;

		/* varchar		v_province[PD_PROVINCE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_province;

		/* varchar		v_city[PD_CITY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_city;

		/* varchar		v_payout_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_payout_ccy;

		/* varchar		v_dest_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_dest_ccy;

		/* varchar		v_checksum[PD_CHECKSUM_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_checksum;

		/* varchar		v_amount[PD_AMOUNT_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[13]; } v_amount;

		/* varchar		v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;


                short           ind_seq_num = -1;
                short           ind_merchant_ref = -1;
                short           ind_country = -1;
                short           ind_identity_id = -1;
                short           ind_account_num = -1;
                short           ind_account_name = -1;
                short           ind_bank_name = -1;
                short           ind_bank_code = -1;
                short           ind_branch = -1;
                short           ind_phone_num = -1;
                short           ind_province = -1;
                short           ind_city = -1;
                short           ind_payout_ccy = -1;
                short           ind_dest_ccy = -1;
                short           ind_checksum = -1;
                short           ind_amount = -1;
		short		ind_txn_id = -1;


	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_date.len = strlen(cs_date);
        memcpy(hv_txn_date.arr,cs_date,hv_txn_date.len);
DEBUGLOG(("process_txn::txn_date = [%.*s]\n",hv_txn_date.len,hv_txn_date.arr));

        hv_merch_id.len = strlen(csMerchId);
        memcpy(hv_merch_id.arr,csMerchId,hv_merch_id.len);
DEBUGLOG(("process_txn::merch_id = [%.*s]\n",hv_merch_id.len,hv_merch_id.arr));


        /* EXEC SQL DECLARE c_cursor_gettxn CURSOR FOR
		select	a.seq_num,
                        a.merchant_ref,
                        a.country,
                        a.identity_id,
                        a.account_name,
                        a.account_num,
                        a.bank_name,
                        a.bank_code,
                        a.branch,
                        a.phone_num,
                        a.province,
                        a.city,
                        a.amount,
                        a.payout_currency,
                        a.dest_currency,
                        a.checksum,
			c.th_txn_id
  		   from payout_record a,
			payout_header b,
			txn_header c
		  where	b.merchant_id =:hv_merch_id
                    and b.txn_date =:hv_txn_date
		    and	a.merchant_id = b.merchant_id
		    and	a.batch_id = b.batch_id
		    and c.th_merchant_ref=a.merchant_ref
		    and c.th_merchant_id=a.merchant_id
		  order by a.seq_num; */ 

                
        /* EXEC SQL OPEN c_cursor_gettxn; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0005;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )138;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_merch_id;
        sqlstm.sqhstl[0] = (unsigned long )17;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_date;
        sqlstm.sqhstl[1] = (unsigned long )10;
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
			:v_seq_num:ind_seq_num,
                        :v_merchant_ref:ind_merchant_ref,
                        :v_country:ind_country,
                        :v_identity_id:ind_identity_id,
                        :v_account_name:ind_account_name,
                        :v_account_num:ind_account_num,
                        :v_bank_name:ind_bank_name,
                        :v_bank_code:ind_bank_code,
                        :v_branch:ind_branch,
                        :v_phone_num:ind_phone_num,
                        :v_province:ind_province,
                        :v_city:ind_city,
                        :v_amount:ind_amount,
                        :v_payout_ccy:ind_payout_ccy,
                        :v_dest_ccy:ind_dest_ccy,
                        :v_checksum:ind_checksum,
			:v_txn_id:ind_txn_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 17;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )161;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_seq_num;
                sqlstm.sqhstl[0] = (unsigned long )9;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_seq_num;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_merchant_ref;
                sqlstm.sqhstl[1] = (unsigned long )53;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_merchant_ref;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_country;
                sqlstm.sqhstl[2] = (unsigned long )5;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_country;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_identity_id;
                sqlstm.sqhstl[3] = (unsigned long )28;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_identity_id;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_account_name;
                sqlstm.sqhstl[4] = (unsigned long )28;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_account_name;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_account_num;
                sqlstm.sqhstl[5] = (unsigned long )28;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_account_num;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_bank_name;
                sqlstm.sqhstl[6] = (unsigned long )53;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_bank_name;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_bank_code;
                sqlstm.sqhstl[7] = (unsigned long )13;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_bank_code;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_branch;
                sqlstm.sqhstl[8] = (unsigned long )53;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_branch;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_phone_num;
                sqlstm.sqhstl[9] = (unsigned long )28;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_phone_num;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_province;
                sqlstm.sqhstl[10] = (unsigned long )23;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_province;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_city;
                sqlstm.sqhstl[11] = (unsigned long )23;
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_city;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
                sqlstm.sqhstv[12] = (unsigned char  *)&v_amount;
                sqlstm.sqhstl[12] = (unsigned long )15;
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_amount;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
                sqlstm.sqhstv[13] = (unsigned char  *)&v_payout_ccy;
                sqlstm.sqhstl[13] = (unsigned long )6;
                sqlstm.sqhsts[13] = (         int  )0;
                sqlstm.sqindv[13] = (         short *)&ind_payout_ccy;
                sqlstm.sqinds[13] = (         int  )0;
                sqlstm.sqharm[13] = (unsigned long )0;
                sqlstm.sqadto[13] = (unsigned short )0;
                sqlstm.sqtdso[13] = (unsigned short )0;
                sqlstm.sqhstv[14] = (unsigned char  *)&v_dest_ccy;
                sqlstm.sqhstl[14] = (unsigned long )6;
                sqlstm.sqhsts[14] = (         int  )0;
                sqlstm.sqindv[14] = (         short *)&ind_dest_ccy;
                sqlstm.sqinds[14] = (         int  )0;
                sqlstm.sqharm[14] = (unsigned long )0;
                sqlstm.sqadto[14] = (unsigned short )0;
                sqlstm.sqtdso[14] = (unsigned short )0;
                sqlstm.sqhstv[15] = (unsigned char  *)&v_checksum;
                sqlstm.sqhstl[15] = (unsigned long )19;
                sqlstm.sqhsts[15] = (         int  )0;
                sqlstm.sqindv[15] = (         short *)&ind_checksum;
                sqlstm.sqinds[15] = (         int  )0;
                sqlstm.sqharm[15] = (unsigned long )0;
                sqlstm.sqadto[15] = (unsigned short )0;
                sqlstm.sqtdso[15] = (unsigned short )0;
                sqlstm.sqhstv[16] = (unsigned char  *)&v_txn_id;
                sqlstm.sqhstl[16] = (unsigned long )19;
                sqlstm.sqhsts[16] = (         int  )0;
                sqlstm.sqindv[16] = (         short *)&ind_txn_id;
                sqlstm.sqinds[16] = (         int  )0;
                sqlstm.sqharm[16] = (unsigned long )0;
                sqlstm.sqadto[16] = (unsigned short )0;
                sqlstm.sqtdso[16] = (unsigned short )0;
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

/* Field #0 seq_num */
                if (ind_seq_num < 0 )
                        v_seq_num.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_seq_num.len,v_seq_num.arr,PD_MY_DELIMITOR);

/* Field #1 merchant_ref */
                if (ind_merchant_ref < 0 )
                        v_merchant_ref.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_merchant_ref.len,v_merchant_ref.arr,PD_MY_DELIMITOR);

/* Field #2 country*/
                if (ind_country < 0 )
                        v_country.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_country.len,v_country.arr,PD_MY_DELIMITOR);

/* Field #3 ID*/
                if (ind_identity_id< 0 )
                        v_identity_id.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_identity_id.len,v_identity_id.arr,PD_MY_DELIMITOR);

/* Field #4 account_num */
                if (ind_account_num < 0 )
			v_account_num.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_account_num.len,v_account_num.arr,PD_MY_DELIMITOR);

/* Field #5 bank_code */
                if (ind_bank_code < 0 )
                        v_bank_code.arr[0] = '\0';
		fprintf(fp,"%.*s%s",v_bank_code.len,v_bank_code.arr,PD_MY_DELIMITOR);

/* Field #6  account_name*/
                if (ind_account_name < 0 )
                        v_account_name.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_account_name.len,v_account_name.arr,PD_MY_DELIMITOR);

/* Field #7  bank_name*/
                if (ind_bank_name< 0 )
                        v_bank_name.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_bank_name.len,v_bank_name.arr,PD_MY_DELIMITOR);

/* Field #8  branch*/
                if (ind_branch< 0 )
                        v_branch.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_branch.len,v_branch.arr,PD_MY_DELIMITOR);

/* Field #9 phone_num*/
                if (ind_phone_num< 0 )
                        v_phone_num.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_phone_num.len,v_phone_num.arr,PD_MY_DELIMITOR);

/* Field #10 province*/
                if (ind_province< 0 )
                        v_province.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_province.len,v_province.arr,PD_MY_DELIMITOR);

/* Field #11 city*/
                if (ind_city< 0 )
                        v_city.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_city.len,v_city.arr,PD_MY_DELIMITOR);

/* Field #12 amount*/
                if (ind_amount< 0 )
                        v_amount.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_amount.len,v_amount.arr,PD_MY_DELIMITOR);

/* Field #13 payout_ccy*/
                if (ind_payout_ccy< 0 )
                        v_payout_ccy.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_payout_ccy.len,v_payout_ccy.arr,PD_MY_DELIMITOR);

/* Field #14 dest_ccy*/
                if (ind_dest_ccy< 0 )
                        v_dest_ccy.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_dest_ccy.len,v_dest_ccy.arr,PD_MY_DELIMITOR);

/* Field #15  checksum*/
                if (ind_checksum< 0 )
                        v_checksum.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_checksum.len,v_checksum.arr,PD_MY_DELIMITOR);

/* Field #16  txn_id*/
		if (ind_txn_id< 0 )
			v_txn_id.arr[0] = '\0';
		fprintf(fp,"%.*s\n",v_txn_id.len,v_txn_id.arr);


	}
	while(PD_TRUE && iRet == SUCCESS);

	

	/* EXEC SQL CLOSE c_cursor_gettxn; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )244;
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
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )259;
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
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )274;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}

int process_not_sent(const char* csMerchId,FILE *fp)
{               
 
        int     iRet = SUCCESS;
 
        /* EXEC SQL WHENEVER SQLERROR GOTO not_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		
		/* varchar		hv_txn_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_txn_date;

		/* varchar		hv_merch_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merch_id;


		/* varchar		v_seq_num[PD_SEQ_NUM_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_seq_num;

		/* varchar		v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar 	v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		/* varchar 	v_identity_id[PD_IDENTITY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_identity_id;

		/* varchar 	v_account_num[PD_AC_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_num;

		/* varchar 	v_account_name[PD_ACC_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_name;

		/* varchar 	v_bank_name[PD_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_name;

		/* varchar 	v_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

		/* varchar 	v_branch[PD_BANK_BRANCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_branch;

		/* varchar		v_phone_num[PD_MOBILE_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_phone_num;

		/* varchar		v_province[PD_PROVINCE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_province;

		/* varchar		v_city[PD_CITY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_city;

		/* varchar		v_payout_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_payout_ccy;

		/* varchar		v_dest_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_dest_ccy;

		/* varchar		v_checksum[PD_CHECKSUM_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_checksum;

		/* varchar		v_amount[PD_AMOUNT_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[13]; } v_amount;


                short           ind_seq_num = -1;
                short           ind_merchant_ref = -1;
                short           ind_country = -1;
                short           ind_identity_id = -1;
                short           ind_account_num = -1;
                short           ind_account_name = -1;
                short           ind_bank_name = -1;
                short           ind_bank_code = -1;
                short           ind_branch = -1;
                short           ind_phone_num = -1;
                short           ind_province = -1;
                short           ind_city = -1;
                short           ind_payout_ccy = -1;
                short           ind_dest_ccy = -1;
                short           ind_checksum = -1;
                short           ind_amount = -1;


	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_date.len = strlen(cs_date);
        memcpy(hv_txn_date.arr,cs_date,hv_txn_date.len);
DEBUGLOG(("process_txn::txn_date = [%.*s]\n",hv_txn_date.len,hv_txn_date.arr));

        hv_merch_id.len = strlen(csMerchId);
        memcpy(hv_merch_id.arr,csMerchId,hv_merch_id.len);
DEBUGLOG(("process_txn::merch_id = [%.*s]\n",hv_merch_id.len,hv_merch_id.arr));


        /* EXEC SQL DECLARE c_cursor_getnot CURSOR FOR
		select	a.seq_num,
                        a.merchant_ref,
                        a.country,
                        a.identity_id,
                        a.account_name,
                        a.account_num,
                        a.bank_name,
                        a.bank_code,
                        a.branch,
                        a.phone_num,
                        a.province,
                        a.city,
                        a.amount,
                        a.payout_currency,
                        a.dest_currency,
                        a.checksum
  		   from payout_record a,
			payout_header b
		  where	b.merchant_id =:hv_merch_id
                    and b.txn_date =:hv_txn_date
		    and	a.merchant_id = b.merchant_id
		    and	a.batch_id = b.batch_id
		    and a.status ='R'
		    and a.response_code >=1000
		  order by a.seq_num; */ 

                
        /* EXEC SQL OPEN c_cursor_getnot; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0007;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )289;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_merch_id;
        sqlstm.sqhstl[0] = (unsigned long )17;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_date;
        sqlstm.sqhstl[1] = (unsigned long )10;
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
        if (sqlca.sqlcode < 0) goto not_error;
}


        do {    
                /* EXEC SQL FETCH c_cursor_getnot
                INTO	
			:v_seq_num:ind_seq_num,
                        :v_merchant_ref:ind_merchant_ref,
                        :v_country:ind_country,
                        :v_identity_id:ind_identity_id,
                        :v_account_name:ind_account_name,
                        :v_account_num:ind_account_num,
                        :v_bank_name:ind_bank_name,
                        :v_bank_code:ind_bank_code,
                        :v_branch:ind_branch,
                        :v_phone_num:ind_phone_num,
                        :v_province:ind_province,
                        :v_city:ind_city,
                        :v_amount:ind_amount,
                        :v_payout_ccy:ind_payout_ccy,
                        :v_dest_ccy:ind_dest_ccy,
                        :v_checksum:ind_checksum; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 17;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )312;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_seq_num;
                sqlstm.sqhstl[0] = (unsigned long )9;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_seq_num;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_merchant_ref;
                sqlstm.sqhstl[1] = (unsigned long )53;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_merchant_ref;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_country;
                sqlstm.sqhstl[2] = (unsigned long )5;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_country;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_identity_id;
                sqlstm.sqhstl[3] = (unsigned long )28;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_identity_id;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_account_name;
                sqlstm.sqhstl[4] = (unsigned long )28;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_account_name;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_account_num;
                sqlstm.sqhstl[5] = (unsigned long )28;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_account_num;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_bank_name;
                sqlstm.sqhstl[6] = (unsigned long )53;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_bank_name;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_bank_code;
                sqlstm.sqhstl[7] = (unsigned long )13;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_bank_code;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_branch;
                sqlstm.sqhstl[8] = (unsigned long )53;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_branch;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_phone_num;
                sqlstm.sqhstl[9] = (unsigned long )28;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_phone_num;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_province;
                sqlstm.sqhstl[10] = (unsigned long )23;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_province;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_city;
                sqlstm.sqhstl[11] = (unsigned long )23;
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_city;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
                sqlstm.sqhstv[12] = (unsigned char  *)&v_amount;
                sqlstm.sqhstl[12] = (unsigned long )15;
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_amount;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
                sqlstm.sqhstv[13] = (unsigned char  *)&v_payout_ccy;
                sqlstm.sqhstl[13] = (unsigned long )6;
                sqlstm.sqhsts[13] = (         int  )0;
                sqlstm.sqindv[13] = (         short *)&ind_payout_ccy;
                sqlstm.sqinds[13] = (         int  )0;
                sqlstm.sqharm[13] = (unsigned long )0;
                sqlstm.sqadto[13] = (unsigned short )0;
                sqlstm.sqtdso[13] = (unsigned short )0;
                sqlstm.sqhstv[14] = (unsigned char  *)&v_dest_ccy;
                sqlstm.sqhstl[14] = (unsigned long )6;
                sqlstm.sqhsts[14] = (         int  )0;
                sqlstm.sqindv[14] = (         short *)&ind_dest_ccy;
                sqlstm.sqinds[14] = (         int  )0;
                sqlstm.sqharm[14] = (unsigned long )0;
                sqlstm.sqadto[14] = (unsigned short )0;
                sqlstm.sqtdso[14] = (unsigned short )0;
                sqlstm.sqhstv[15] = (unsigned char  *)&v_checksum;
                sqlstm.sqhstl[15] = (unsigned long )19;
                sqlstm.sqhsts[15] = (         int  )0;
                sqlstm.sqindv[15] = (         short *)&ind_checksum;
                sqlstm.sqinds[15] = (         int  )0;
                sqlstm.sqharm[15] = (unsigned long )0;
                sqlstm.sqadto[15] = (unsigned short )0;
                sqlstm.sqtdso[15] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto not_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

/* Field #0 seq_num */
                if (ind_seq_num < 0 )
                        v_seq_num.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_seq_num.len,v_seq_num.arr,PD_MY_DELIMITOR);

/* Field #1 merchant_ref */
                if (ind_merchant_ref < 0 )
                        v_merchant_ref.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_merchant_ref.len,v_merchant_ref.arr,PD_MY_DELIMITOR);

/* Field #2 country*/
                if (ind_country < 0 )
                        v_country.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_country.len,v_country.arr,PD_MY_DELIMITOR);

/* Field #3 ID*/
                if (ind_identity_id< 0 )
                        v_identity_id.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_identity_id.len,v_identity_id.arr,PD_MY_DELIMITOR);

/* Field #4 account_num */
                if (ind_account_num < 0 )
			v_account_num.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_account_num.len,v_account_num.arr,PD_MY_DELIMITOR);

/* Field #5 bank_code */
                if (ind_bank_code < 0 )
                        v_bank_code.arr[0] = '\0';
		fprintf(fp,"%.*s%s",v_bank_code.len,v_bank_code.arr,PD_MY_DELIMITOR);

/* Field #6  account_name*/
                if (ind_account_name < 0 )
                        v_account_name.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_account_name.len,v_account_name.arr,PD_MY_DELIMITOR);

/* Field #7  bank_name*/
                if (ind_bank_name< 0 )
                        v_bank_name.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_bank_name.len,v_bank_name.arr,PD_MY_DELIMITOR);

/* Field #8  branch*/
                if (ind_branch< 0 )
                        v_branch.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_branch.len,v_branch.arr,PD_MY_DELIMITOR);

/* Field #9 phone_num*/
                if (ind_phone_num< 0 )
                        v_phone_num.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_phone_num.len,v_phone_num.arr,PD_MY_DELIMITOR);

/* Field #10 province*/
                if (ind_province< 0 )
                        v_province.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_province.len,v_province.arr,PD_MY_DELIMITOR);

/* Field #11 city*/
                if (ind_city< 0 )
                        v_city.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_city.len,v_city.arr,PD_MY_DELIMITOR);

/* Field #12 amount*/
                if (ind_amount< 0 )
                        v_amount.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_amount.len,v_amount.arr,PD_MY_DELIMITOR);

/* Field #13 payout_ccy*/
                if (ind_payout_ccy< 0 )
                        v_payout_ccy.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_payout_ccy.len,v_payout_ccy.arr,PD_MY_DELIMITOR);

/* Field #14 dest_ccy*/
                if (ind_dest_ccy< 0 )
                        v_dest_ccy.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_dest_ccy.len,v_dest_ccy.arr,PD_MY_DELIMITOR);

/* Field #15  checksum*/
                if (ind_checksum< 0 )
                        v_checksum.arr[0] = '\0';
                fprintf(fp,"%.*s%s",v_checksum.len,v_checksum.arr,PD_MY_DELIMITOR);

/* Field #16  txn_id=NULL*/
		fprintf(fp,"\n");


	}
	while(PD_TRUE && iRet == SUCCESS);

	

	/* EXEC SQL CLOSE c_cursor_getnot; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 17;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )391;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto not_error;
}


DEBUGLOG(("RET = [%d]\n",iRet));
        return iRet;
not_error:
    DEBUGLOG(("process_not_sent error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getnot; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )406;
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
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )421;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}
