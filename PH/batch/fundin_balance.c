
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
    "fundin_balance.pc"
};


static unsigned int sqlctx = 9832691;


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
"select s_bank_ccy , t_ratio from ( select s_bank_ccy , sum ( s_ratio ) t_ra\
tio from seb_balance group by s_bank_ccy ) where t_ratio <> 1            ";

 static char *sq0003 = 
"select f_id , f_fundin_ccy , f_bank_ccy , f_fundin_amount , f_bank_amount ,\
 f_approval_timestamp , f_approval_user from funds_in where f_fundin_date <= \
:b0 and f_approval_user is NOT NULL and f_calculation_user is NULL order by f\
_id            ";

 static char *sq0005 = 
"select f_fundin_date , f_fundin_ccy , f_bank_ccy , f_fundin_amount , f_bank\
_amount , f_approval_timestamp , f_approval_user from funds_in where f_id = :\
b0 and f_approval_user is NOT NULL and f_calculation_user is NULL            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,148,0,9,155,0,2049,0,0,0,1,0,
20,0,0,1,0,0,13,157,0,0,2,0,0,1,0,2,9,0,0,2,4,0,0,
43,0,0,1,0,0,15,177,0,0,0,0,0,1,0,
58,0,0,1,0,0,15,187,0,0,0,0,0,1,0,
73,0,0,2,0,0,17,223,0,0,1,1,0,1,0,1,9,0,0,
92,0,0,2,0,0,21,224,0,0,0,0,0,1,0,
107,0,0,3,244,0,9,298,0,2049,1,1,0,1,0,1,9,0,0,
126,0,0,3,0,0,13,300,0,0,7,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,
0,0,2,9,0,0,
169,0,0,3,0,0,15,375,0,0,0,0,0,1,0,
184,0,0,3,0,0,15,401,0,0,0,0,0,1,0,
199,0,0,4,0,0,32,402,0,0,0,0,0,1,0,
214,0,0,5,229,0,9,464,0,2049,1,1,0,1,0,1,9,0,0,
233,0,0,5,0,0,13,466,0,0,7,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,
0,0,2,9,0,0,
276,0,0,5,0,0,15,654,0,0,0,0,0,1,0,
291,0,0,5,0,0,15,680,0,0,0,0,0,1,0,
306,0,0,6,0,0,32,681,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/04/11              LokMan Chow
add FindAllBalance				   2011/04/14		   LokMan Chow
add skip tolerance check			   2014/12/17		   LokMan Chow
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
#include "internal.h"
#include "utilitys.h"
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"
#include "ObjPtr.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cs_fundin_date[PD_DATE_LEN + 1];
char    cs_fundin_id[PD_TXN_SEQ_LEN + 1];
char    cs_check_rate[PD_TXN_SEQ_LEN + 1];
char    cs_skip_tol_check[PD_TXN_SEQ_LEN + 1];
int	iMode;
int	iCheckOandaRate;
int	iSkipTolCheck;
char    cDebug;

#define PD_TMP_TAG_LEN  25
#define	PD_INPUT_DATE	1 
#define PD_INPUT_ID	2

#define	FI_NEW_RATE_ERROR		99
#define	FI_NEW_W_OANDA_RATE_ERROR	98
#define	FI_INT_ERROR		88
#define	FI_INVALID_TXN		77
//#define PD_ROUND_UP_DEC 5

OBJPTR(DB);

int parse_arg(int argc,char **argv);
int process_fundin_by_date(unsigned char* csFundInDate, hash_t* hFundIn);
int process_fundin_by_id(unsigned char* csFundInId, hash_t* hFundIn);
int process_balance(hash_t* hFundIn);
int UpdateRateRatio(const hash_t* hFundIn);
int find_problem_ratio();
int adjust_ratio(const char* BankCcy, double dRatioDiff);

int batch_init(int argc, char* argv[])
{

    if (argc < 2) {
        printf("usage:  -d fundin_date -i fundin_id -c check oanda rate -k skip all tolerance checking\n");
        return FI_INVALID_TXN;
    }
    else
        return SUCCESS;
}




int batch_proc(int argc, char* argv[])
{
        int     iRet;

	iMode = PD_INPUT_DATE;

	iRet = parse_arg(argc,argv);
               
        if (iRet != SUCCESS) {
        	printf("usage:  -d fundin_date -i fundin_id -c check oanda rate -k skip all tolerance checking\n");
                return (iRet);
        }

	hash_t *hFundIn;
	hFundIn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hFundIn,0);

	if(iMode == PD_INPUT_DATE)
		iRet = process_fundin_by_date((unsigned char*)cs_fundin_date, hFundIn);
	else if(iMode == PD_INPUT_ID)
		iRet = process_fundin_by_id((unsigned char*)cs_fundin_id, hFundIn);
	else{
		iRet = FI_INT_ERROR;
	}

	if(iRet==SUCCESS){
		iRet = process_balance(hFundIn);
	}

	if(iRet==SUCCESS){
		find_problem_ratio();
	}
	else if(iRet==PD_NOT_FOUND){
		iRet = FI_INT_ERROR;
	}

DEBUGLOG(("iRet = [%d]\n",iRet));

	FREE_ME(hFundIn);
	return iRet;


}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


int find_problem_ratio()
{
	int iRet = SUCCESS;
	double	dRatioDiff = 0.0;

DEBUGLOG(("*****find_problem_ratio Start*****\n"));
	/* EXEC SQL WHENEVER SQLERROR GOTO proratio_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	v_bank_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_bank_ccy;

		double	v_ratio;

		short	ind_bank_ccy = -1;
		short	ind_ratio = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


        /* EXEC SQL DECLARE c_cursor_get_proratio CURSOR FOR
		select s_bank_ccy,
		       t_ratio
		from
		  (select s_bank_ccy,
			sum(s_ratio) t_ratio
		   from seb_balance
		   group by s_bank_ccy)
		where t_ratio <> 1; */ 


        /* EXEC SQL OPEN c_cursor_get_proratio; */ 

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
        if (sqlca.sqlcode < 0) goto proratio_error;
}


        do {    
                /* EXEC SQL FETCH c_cursor_get_proratio
                INTO
			:v_bank_ccy:ind_bank_ccy,
			:v_ratio:ind_ratio; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 2;
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
                sqlstm.sqhstv[0] = (unsigned char  *)&v_bank_ccy;
                sqlstm.sqhstl[0] = (unsigned long )6;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_bank_ccy;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_ratio;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_ratio;
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
                if (sqlca.sqlcode < 0) goto proratio_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		if(ind_bank_ccy>=0 && ind_ratio>=0){
			dRatioDiff = v_ratio - 1;
DEBUGLOG(("find_problem_ratio: bank_ccy =[%.*s] have ratio [%lf], ratio difference = [%lf]\n",v_bank_ccy.len,v_bank_ccy.arr,v_ratio,dRatioDiff));

			if(dRatioDiff<0.001 || dRatioDiff>-0.001)
				adjust_ratio( (const char*)v_bank_ccy.arr,dRatioDiff);
		}
			
 	}
        while(PD_TRUE && iRet == SUCCESS);

        /* EXEC SQL CLOSE c_cursor_get_proratio; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )43;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto proratio_error;
}



DEBUGLOG(("*****find_problem_ratio End*****\n"));
	return iRet;

proratio_error:
    DEBUGLOG(("find_problem_ratio error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    ERRLOG("fundin_balance sql error %d\n",sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_get_proratio; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 2;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )58;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FI_INT_ERROR;
}

int adjust_ratio(const char* csBankCcy, double dRatioDiff)
{
	int iRet = SUCCESS;
	char *csBuf;

DEBUGLOG(("*****adjust_ratio Start*****\n"));
	/* EXEC SQL WHENEVER SQLERROR GOTO adj_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


	/* EXEC SQL END DECLARE SECTION; */ 


	csBuf = (char*) malloc (128);
	sprintf(csBuf,"%lf",dRatioDiff);
	

	strcpy((char*)hv_dynstmt.arr,"update seb_balance set s_ratio = s_ratio-(");
	strcat((char*)hv_dynstmt.arr,csBuf);
	strcat((char*)hv_dynstmt.arr,")");
	strcat((char*)hv_dynstmt.arr," where s_ratio in ( select max(s_ratio) from seb_balance where s_bank_ccy = '");
	strcat((char*)hv_dynstmt.arr,csBankCcy);
	strcat((char*)hv_dynstmt.arr,"')");
	strcat((char*)hv_dynstmt.arr,"and s_bank_ccy = '");
	strcat((char*)hv_dynstmt.arr,csBankCcy);
	strcat((char*)hv_dynstmt.arr,"'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )73;
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
 if (sqlca.sqlcode < 0) goto adj_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )92;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto adj_error;
}



        FREE_ME(csBuf);

DEBUGLOG(("*****adjust_ratio End*****\n"));
	return iRet;

adj_error:
    DEBUGLOG(("adj_ratio error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    ERRLOG("fundin_balance sql error %d\n",sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return FI_INT_ERROR;
}

int process_fundin_by_date(unsigned char* csFundInDate, hash_t*	hFundIn)
{               
 
        int     iRet = SUCCESS;
	int	iCnt = 0;
	char    csTag[PD_TMP_TAG_LEN +1];
	double	dTotalFundIn = 0;

DEBUGLOG(("*****Process FundIn by Date Start*****[%s]\n",csFundInDate));

	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	hv_fundin_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_fundin_date;


		/* varchar	v_fundin_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_fundin_id;

		/* varchar	v_fundin_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_fundin_ccy;

		/* varchar	v_bank_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_bank_ccy;

		double	v_fundin_amount;
		double	v_bank_amount;
		/* varchar	v_approval_datetime[PD_DATETIME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_approval_datetime;

		/* varchar v_approval_user[PD_USER_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_approval_user;

		//varchar	v_cal_datetime[PD_DATETIME_LEN +1];
		//varchar v_cal_user[PD_USER_LEN +1];

		short	ind_fundin_id = -1;
		short	ind_fundin_ccy = -1;
		short	ind_bank_ccy = -1;
		short	ind_fundin_amount = -1;
		short	ind_bank_amount = -1;
		short	ind_approval_datetime = -1;
		short	ind_approval_user = -1;
		//short	ind_cal_datetime = -1;
		//short	ind_cal_user = -1;


	/* EXEC SQL END DECLARE SECTION; */ 


	hv_fundin_date.len = strlen((const char*)csFundInDate);
        memcpy(hv_fundin_date.arr,(const char*)csFundInDate,hv_fundin_date.len);


        /* EXEC SQL DECLARE c_cursor_get_fundin CURSOR FOR
		select 	f_id,
			f_fundin_ccy,
         		f_bank_ccy,
         		f_fundin_amount,
         		f_bank_amount,
			f_approval_timestamp,
			f_approval_user
		  from 	funds_in
		 where	f_fundin_date <= :hv_fundin_date
		 and	f_approval_user is NOT NULL
		 and	f_calculation_user is NULL
		 order by f_id; */ 

		
                
        /* EXEC SQL OPEN c_cursor_get_fundin; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0003;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )107;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_fundin_date;
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
                /* EXEC SQL FETCH c_cursor_get_fundin
                INTO
         		v_fundin_id:ind_fundin_id,
         		v_fundin_ccy:ind_fundin_ccy,
         		v_bank_ccy:ind_bank_ccy,
         		v_fundin_amount:ind_fundin_amount,
         		v_bank_amount:ind_bank_amount,
         		v_approval_datetime:ind_approval_datetime,
			v_approval_user:ind_approval_user; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 7;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )126;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_fundin_id;
                sqlstm.sqhstl[0] = (unsigned long )19;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_fundin_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_fundin_ccy;
                sqlstm.sqhstl[1] = (unsigned long )6;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_fundin_ccy;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_bank_ccy;
                sqlstm.sqhstl[2] = (unsigned long )6;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_bank_ccy;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_fundin_amount;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_fundin_amount;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_bank_amount;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_bank_amount;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_approval_datetime;
                sqlstm.sqhstl[5] = (unsigned long )17;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_approval_datetime;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_approval_user;
                sqlstm.sqhstl[6] = (unsigned long )23;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_approval_user;
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

/* approval and calculation user + time*/
		if ((ind_approval_datetime >= 0) && (ind_approval_user >= 0)){

/* fundin_id */
			if (ind_fundin_id >= 0){
				v_fundin_id.arr[v_fundin_id.len] = '\0';
				//sprintf(csTag,"fundin_id_%d",iCnt);
				PutField_CString(hFundIn,"fundsin_id",(const char *)v_fundin_id.arr);
DEBUGLOG(("Process FundIn by Date: %s =[%.*s]\n",csTag,v_fundin_id.len,v_fundin_id.arr));
			}

/* fundin_date*/
			//sprintf(csTag,"fundin_date_%d",iCnt);
			PutField_CString(hFundIn,"fundin_date",(const char *)csFundInDate);
DEBUGLOG(("Process FundIn by Date: fundin_date =[%s]\n",csFundInDate));
		
/* fundin_ccy */
			if (ind_fundin_ccy >= 0){
				v_fundin_ccy.arr[v_fundin_ccy.len] = '\0';
				sprintf(csTag,"fundin_ccy_%d",iCnt);
				PutField_CString(hFundIn,csTag,(const char *)v_fundin_ccy.arr);
DEBUGLOG(("Process FundIn by Date: %s =[%.*s]\n",csTag,v_fundin_ccy.len,v_fundin_ccy.arr));
			}

/* bank_ccy */
			if (ind_bank_ccy >= 0 ){
				v_bank_ccy.arr[v_bank_ccy.len] = '\0';
				sprintf(csTag,"bank_ccy_%d",iCnt);
				PutField_CString(hFundIn,csTag,(const char *)v_bank_ccy.arr);
DEBUGLOG(("Process FundIn by Date: %s =[%.*s]\n",csTag,v_bank_ccy.len,v_bank_ccy.arr));
			}

/* fundin_amount */
			if (ind_fundin_amount < 0 ){
DEBUGLOG(("Process FundIn by Date: fundin_amount missing!!\n"));
				iRet = INT_TXN_AMT_MISSING;
			}
			else{
				sprintf(csTag,"fundin_amount_%d",iCnt);
				PutField_Double(hFundIn,csTag,v_fundin_amount);
DEBUGLOG(("Process FundIn by Date: %s =[%f]\n",csTag,v_fundin_amount));

				dTotalFundIn +=v_fundin_amount;
			}

/* bank_amount */
			if (ind_bank_amount < 0 ){
DEBUGLOG(("Process FundIn by Date: bank_amount missing!!\n"));
				iRet = INT_TXN_AMT_MISSING;
			}
			else{
				sprintf(csTag,"bank_amount_%d",iCnt);
				PutField_Double(hFundIn,csTag,v_bank_amount);
DEBUGLOG(("Process FundIn by Date: %s =[%f]\n",csTag,v_bank_amount));
			}

			iCnt ++;
		}
 	}
        while(PD_TRUE && iRet == SUCCESS);

        /* EXEC SQL CLOSE c_cursor_get_fundin; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )169;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto sql_error;
}



	if(iCnt!=0){
		PutField_Int(hFundIn,"total_record",iCnt);
DEBUGLOG(("Process FundIn by Date: total_record=[%d]\n",iCnt));

	}
	else{
		iRet=PD_NOT_FOUND;
DEBUGLOG(("No Record Found\n"));
		return iRet;
	}

	if(iRet==SUCCESS){
DEBUGLOG(("Process FundIn by Date Normal Exit\n"));
	}
	else{
DEBUGLOG(("Process FundIn by Date Error\n"));
	}
        return iRet;

sql_error:
    DEBUGLOG(("process_fundin error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    ERRLOG("fundin_balance sql error %d\n",sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_get_fundin; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 7;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )184;
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
    sqlstm.offset = (unsigned int  )199;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FI_INT_ERROR;
}

int process_fundin_by_id(unsigned char* csFundInId, hash_t* hFundIn)
{               
 
        int     iRet = SUCCESS;
	int	iCnt = 0;
	char    csTag[PD_TMP_TAG_LEN +1];
	double	dTotalFundIn = 0;

DEBUGLOG(("*****Process FundIn Start*****[%s]\n",csFundInId));

	/* EXEC SQL WHENEVER SQLERROR GOTO sqlt_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	hv_fundin_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_fundin_id;


		/* varchar	v_fundin_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_fundin_date;

		/* varchar	v_fundin_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_fundin_ccy;

		/* varchar	v_bank_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_bank_ccy;

		double	v_fundin_amount;
		double	v_bank_amount;
		/* varchar	v_approval_datetime[PD_DATETIME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_approval_datetime;

		/* varchar v_approval_user[PD_USER_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_approval_user;

		//varchar	v_cal_datetime[PD_DATETIME_LEN +1];
		//varchar v_cal_user[PD_USER_LEN +1];

		short	ind_fundin_date = -1;
		short	ind_fundin_ccy = -1;
		short	ind_bank_ccy = -1;
		short	ind_fundin_amount = -1;
		short	ind_bank_amount = -1;
		short	ind_approval_datetime = -1;
		short	ind_approval_user = -1;
		//short	ind_cal_datetime = -1;
		//short	ind_cal_user = -1;


	/* EXEC SQL END DECLARE SECTION; */ 


	hv_fundin_id.len = strlen((const char*)csFundInId);
        memcpy(hv_fundin_id.arr,(const char*)csFundInId,hv_fundin_id.len);


        /* EXEC SQL DECLARE c_cursor_get_fundin_id CURSOR FOR
		select 	f_fundin_date,
			f_fundin_ccy,
         		f_bank_ccy,
         		f_fundin_amount,
         		f_bank_amount,
			f_approval_timestamp,
			f_approval_user
		  from 	funds_in
		 where	f_id = :hv_fundin_id
		 and	f_approval_user is NOT NULL
		 and	f_calculation_user is NULL; */ 

		
                
        /* EXEC SQL OPEN c_cursor_get_fundin_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0005;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )214;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_fundin_id;
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
        if (sqlca.sqlcode < 0) goto sqlt_error;
}


        do {    
                /* EXEC SQL FETCH c_cursor_get_fundin_id
                INTO
         		v_fundin_date:ind_fundin_date,
         		v_fundin_ccy:ind_fundin_ccy,
         		v_bank_ccy:ind_bank_ccy,
         		v_fundin_amount:ind_fundin_amount,
         		v_bank_amount:ind_bank_amount,
         		v_approval_datetime:ind_approval_datetime,
			v_approval_user:ind_approval_user; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 7;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )233;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_fundin_date;
                sqlstm.sqhstl[0] = (unsigned long )11;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_fundin_date;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_fundin_ccy;
                sqlstm.sqhstl[1] = (unsigned long )6;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_fundin_ccy;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_bank_ccy;
                sqlstm.sqhstl[2] = (unsigned long )6;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_bank_ccy;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_fundin_amount;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_fundin_amount;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_bank_amount;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_bank_amount;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_approval_datetime;
                sqlstm.sqhstl[5] = (unsigned long )17;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_approval_datetime;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_approval_user;
                sqlstm.sqhstl[6] = (unsigned long )23;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_approval_user;
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
                if (sqlca.sqlcode < 0) goto sqlt_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

/* approval and calculation user + time*/
		if ((ind_approval_datetime >= 0) && (ind_approval_user >= 0)){

/* fundin_date */
			if (ind_fundin_date>= 0){
				v_fundin_date.arr[v_fundin_date.len] = '\0';
				sprintf(csTag,"fundin_date");
				PutField_CString(hFundIn,csTag,(const char *)v_fundin_date.arr);
DEBUGLOG(("Process FundIn: %s =[%.*s]\n",csTag,v_fundin_date.len,v_fundin_date.arr));
			}

/* fundin_id*/
			//sprintf(csTag,"fundin_id_%d",iCnt);
			PutField_CString(hFundIn,"fundsin_id",(const char *)csFundInId);
DEBUGLOG(("Process FundIn: fundin_id =[%s]\n",csFundInId));
		
/* fundin_ccy */
			if (ind_fundin_ccy >= 0){
				v_fundin_ccy.arr[v_fundin_ccy.len] = '\0';
				sprintf(csTag,"fundin_ccy_%d",iCnt);
				PutField_CString(hFundIn,csTag,(const char *)v_fundin_ccy.arr);
DEBUGLOG(("Process FundIn: %s =[%.*s]\n",csTag,v_fundin_ccy.len,v_fundin_ccy.arr));
			}

/* bank_ccy */
			if (ind_bank_ccy >= 0 ){
				v_bank_ccy.arr[v_bank_ccy.len] = '\0';
				sprintf(csTag,"bank_ccy_%d",iCnt);
				PutField_CString(hFundIn,csTag,(const char *)v_bank_ccy.arr);
DEBUGLOG(("Process FundIn: %s =[%.*s]\n",csTag,v_bank_ccy.len,v_bank_ccy.arr));
			}

/* fundin_amount */
			if (ind_fundin_amount < 0 ){
DEBUGLOG(("Process FundIn: fundin_amount missing!!\n"));
				iRet = INT_TXN_AMT_MISSING;
			}
			else{
				sprintf(csTag,"fundin_amount_%d",iCnt);
				PutField_Double(hFundIn,csTag,v_fundin_amount);
DEBUGLOG(("Process FundIn: %s =[%f]\n",csTag,v_fundin_amount));

				dTotalFundIn +=v_fundin_amount;
			}

/* bank_amount */
			if (ind_bank_amount < 0 ){
DEBUGLOG(("Process FundIn: bank_amount missing!!\n"));
				iRet = INT_TXN_AMT_MISSING;
			}
			else{
				sprintf(csTag,"bank_amount_%d",iCnt);
				PutField_Double(hFundIn,csTag,v_bank_amount);
DEBUGLOG(("Process FundIn: %s =[%f]\n",csTag,v_bank_amount));
			}

			iCnt ++;
/*
////Check Input Rate with Oanda Rate
			if(iRet==PD_OK && iCheckOandaRate){
DEBUGLOG(("Chaeck Input rate with Oanda Rate and Org Rate\n"));
				double	dDefOandaThreshold=5.0;
				double	dDefThreshold=5.0;
				double	dOandaThreshold=5.0;
				double	dThreshold=5.0;
				double	dOandaRate=0.0;
				double	dOrgRate=0.0;
				double	dDiff = 0.0;
				double	dRate= 0.0;

				char*   csValueTmp;
				csValueTmp = (char*) malloc (128);
				DBObjPtr = CreateObj(DBPtr,"DBSystemParameter","FindCode");
				if ((unsigned long)(DBObjPtr)(PD_AVFX_OANDA_RATE_ALLOW_DIFF,csValueTmp) == FOUND) {
					sscanf(csValueTmp, "%lf",&dDefOandaThreshold);
DEBUGLOG(("Update RateRatio:: Default Input Rate & Oanda Rate difference threshold = [%lf]\n",dDefOandaThreshold));
				}
				if ((unsigned long)(DBObjPtr)(PD_AVFXRATE_ALLOW_DIFF,csValueTmp) == FOUND) {
					sscanf(csValueTmp, "%lf",&dDefThreshold);
DEBUGLOG(("Update RateRatio:: Default Input Rate & Org Rate difference threshold = [%lf]\n",dDefThreshold));
				}
				FREE_ME(csValueTmp);

				//find override tolerance
				DBObjPtr = CreateObj(DBPtr,"DBACRThreshold","FindTolerance");
				if ((unsigned long)(DBObjPtr)("OANDA",(const char *)v_bank_ccy.arr,&dOandaThreshold) != PD_FOUND) {
					dOandaThreshold = dDefOandaThreshold;
				}
				if ((unsigned long)(DBObjPtr)("ORG_ACR",(const char *)v_bank_ccy.arr,&dThreshold) != PD_FOUND) {
					dThreshold = dDefThreshold;
				}
DEBUGLOG(("OandaThreshold [%lf], dThreshold [%lf]\n",dOandaThreshold,dThreshold));

				//get oanda rate
				hash_t *hOanda;
				hOanda = (hash_t*) malloc (sizeof(hash_t));
				hash_init(hOanda,0);
				DBObjPtr = CreateObj(DBPtr,"DBExchangeRate","GetExchangeRate");
				if((unsigned long)(*DBObjPtr)((const char *)v_fundin_ccy.arr,(const char *)v_bank_ccy.arr,hOanda)==PD_OK){
					if(GetField_Double(hOanda,"rate",&dOandaRate)){
						dDiff = 0.0;
						dRate = newround((v_bank_amount/v_fundin_amount),PD_ROUND_UP_DEC);
						if(dRate>dOandaRate){
							dDiff = (dRate-dOandaRate)/dOandaRate;
DEBUGLOG(("Input rate [%lf] with difference Oanda Rate 1[%lf]\n",dRate,dDiff));
						}
						else{
							dDiff = (dOandaRate-dRate)/dOandaRate;
DEBUGLOG(("Input rate [%lf] with difference Oanda Rate 2 [%lf]\n",dRate,dDiff));
						}
						if(dDiff*100 >dOandaThreshold){
							if(!iSkipTolCheck){
DEBUGLOG(("Input rate & Oanda Rate with difference [%lf\%] > [%lf\%]!!!!\n",dDiff*100,dOandaThreshold));
ERRLOG("fundin_balance::Input rate & Oanda Rate with difference [%lf\%] > [%lf\%]!!!!\n",dDiff*100,dOandaThreshold);
								iRet = FI_NEW_W_OANDA_RATE_ERROR;
							}
							else{
DEBUGLOG(("Input rate & Oanda Rate with difference [%lf\%] > [%lf\%]. Ignore Checking\n",dDiff*100,dOandaThreshold));
							}
						}
					}
					else{
						iRet = FI_INT_ERROR;
					}
				}
				else{
					iRet = FI_INT_ERROR;
				}
				FREE_ME(hOanda);

				if(iRet==PD_OK){
					//get org ACR
					hash_t *hOrg;
					hOrg= (hash_t*) malloc (sizeof(hash_t));
					hash_init(hOrg,0);
					DBObjPtr = CreateObj(DBPtr,"DBSebBalance","FindBalanceByCcy");
					if ((unsigned long)(*DBObjPtr)((const char *)v_fundin_ccy.arr,
								       (const char *)v_bank_ccy.arr,
								       hOrg) == PD_FOUND) {
						
						if(GetField_Double(hOrg,"rate",&dOrgRate)){
							dDiff = 0.0;
							dRate = newround((v_fundin_amount/v_bank_amount),PD_ROUND_UP_DEC);
							if(dRate>dOrgRate){
								dDiff = (dRate-dOrgRate)/dOrgRate;
DEBUGLOG(("Input rate [%lf] with difference Org Rate 1[%lf]\n",dRate,dDiff));
							}
							else{
								dDiff = (dOrgRate-dRate)/dOrgRate;
DEBUGLOG(("Input rate [%lf] with difference Org Rate 2 [%lf]\n",dRate,dDiff));
							}
							if(dDiff*100 >dThreshold){
								if(!iSkipTolCheck){
DEBUGLOG(("Input rate & Org Rate with difference [%lf\%] > [%lf\%]!!!!\n",dDiff*100,dThreshold));
ERRLOG("fundin_balance::Input rate & Org Rate with difference [%lf\%] > [%lf\%]!!!!\n",dDiff*100,dThreshold);
									iRet = FI_NEW_RATE_ERROR;
								}
								else{
DEBUGLOG(("Input rate & Org Rate with difference [%lf\%] > [%lf\%]. Ignore Checking\n",dDiff*100,dThreshold));
								}
							}
						}
						else{
							iRet = FI_INT_ERROR;
						}
					}
					FREE_ME(hOrg);
				}
			}
*/
		}
 	}
        while(PD_TRUE && iRet == SUCCESS);

        /* EXEC SQL CLOSE c_cursor_get_fundin_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )276;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto sqlt_error;
}



	if(iCnt!=0){
		PutField_Int(hFundIn,"total_record",iCnt);
DEBUGLOG(("Process FundIn: total_record=[%d]\n",iCnt));

	}
	else{
		iRet=PD_NOT_FOUND;
DEBUGLOG(("No Record Found\n"));
		return iRet;
	}

	if(iRet==SUCCESS){
DEBUGLOG(("Process FundIn Normal Exit\n"));
	}
	else{
DEBUGLOG(("Process FundIn Error\n"));
	}
        return iRet;

sqlt_error:
    DEBUGLOG(("process_fundin error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    ERRLOG("fundin_balance sql error %d\n",sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_get_fundin_id; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 7;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )291;
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
    sqlstm.offset = (unsigned int  )306;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FI_INT_ERROR;
}

int process_balance(hash_t* hFundIn)
{
	int	iRet = PD_ERR;
	int	iTotal = 0;
	int	i,j, iCnt = 0;
	int	iProcess = 0;
	double	dTmpAmt= 0.0;
	double	dFundInAmt = 0.0;
	double	dBankAmt = 0.0;
	double	dOrgBankAmt = 0.0;
	double	dOrgRate= 0.0;
	double	dOrgRatio= 0.0;
	double	dOrgDspBal= 0.0;
	char	*csFromCcy;
	char	*csBankCcy;
	char	*csTmp = strdup("");
	char	*csBuf = strdup("");
	char	csTag[PD_TAG_LEN +1];

	double	dRate_N = 0.0;
	double	dRate_D = 0.0;
	//double	dRatio_N = 0.0;
	//double	dRatio_D = 0.0;

	hash_t  *hRec;
	hRec= (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hRec,0);

	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);


DEBUGLOG(("*****Process Balance Start*****\n"));

	if(GetField_Int(hFundIn,"total_record",&iTotal)){
DEBUGLOG(("Process Balance: total_record = [%d]\n", iTotal));
	}

	if(GetField_CString(hFundIn,"fundsin_id",&csTmp)){
DEBUGLOG(("Process Balance: fundsin_id = [%s]\n", csTmp));
	}

	if(GetField_CString(hFundIn,"fundin_date",&csTmp)){
DEBUGLOG(("Process Balance: fundin_date = [%s]\n", csTmp));
	}

	for(i=0; i<iTotal; i++){

////fundin_ccy////
		sprintf(csTag,"fundin_ccy_%d",i);
		if(GetField_CString(hFundIn,csTag,&csFromCcy)){
DEBUGLOG(("Process Balance: fundin_ccy = [%s]\n", csFromCcy));
		}

////fundin_amt////
		sprintf(csTag,"fundin_amount_%d",i);
		if(GetField_Double(hFundIn,csTag,&dFundInAmt)){
			dRate_N = dFundInAmt;
DEBUGLOG(("Process Balance: fundin_amt = [%f]\n", dFundInAmt));
		}

////bank_ccy////
		sprintf(csTag,"bank_ccy_%d",i);
		if(GetField_CString(hFundIn,csTag,&csBankCcy)){
			sprintf(csTag,"process_bank_ccy_%d",iProcess);
			PutField_CString(hFundIn,csTag,csBankCcy);
			iProcess++;
DEBUGLOG(("Process Balance: bank_ccy = [%s]\n", csBankCcy));
		}

////bank_amt////
		sprintf(csTag,"bank_amount_%d",i);
		if(GetField_Double(hFundIn,csTag,&dBankAmt)){
			dTmpAmt = 0.0;
			sprintf(csTag,"%s_ratio_D",csBankCcy);
			GetField_Double(hFundIn,csTag,&dTmpAmt);
			PutField_Double(hFundIn,csTag,dTmpAmt+dBankAmt);
			sprintf(csTag,"%s%s_ratio_N",csFromCcy,csBankCcy);
			PutField_Double(hFundIn,csTag,dBankAmt);

			dRate_D = dBankAmt;
			//dRatio_N = dBankAmt;
			//dRatio_D += dBankAmt;
DEBUGLOG(("Process Balance: bank_amt = [%f], %s_ratio_D = [%f] %s%s_ratio_N = [%f]\n", dBankAmt,csBankCcy,dTmpAmt+dBankAmt,csFromCcy,csBankCcy,dBankAmt));
		}


		hash_init(hRec,0);
		DBObjPtr = CreateObj(DBPtr,"DBSebBalance","FindBalanceByCcy");
		if ((unsigned long)(*DBObjPtr)(csFromCcy,csBankCcy,hRec) == PD_FOUND) {

DEBUGLOG(("Process Balance -> FindBalanceByCcy : SUCCESS\n"));

			strcpy(csTmp,csFromCcy);
			strcat(csTmp,csBankCcy);
			csTmp[strlen(csTmp)]='\0';
			sprintf(csTag,"have_ccy_%d",iCnt);
			PutField_CString(hFundIn,csTag,csTmp);
			iCnt++;

			if (GetField_Double(hRec,"bank_bal",&dOrgBankAmt)) {
				sprintf(csTag,"org_bank_amt_%d",i);
				PutField_Double(hFundIn,csTag,dOrgBankAmt);
DEBUGLOG(("FindBalanceByCcy : org_bank_amt = [%f]\n", dOrgBankAmt));
			}

			if (GetField_Double(hRec,"dsp_bal",&dOrgDspBal)) {
				sprintf(csTag,"org_dsp_bal_%d",i);
				PutField_Double(hFundIn,csTag,dOrgDspBal);
DEBUGLOG(("FindBalanceByCcy : org_dsp_bal = [%f]\n", dOrgDspBal));
			}

			if (GetField_Double(hRec,"rate",&dOrgRate)) {
				sprintf(csTag,"org_rate_%d",i);
				PutField_Double(hFundIn,csTag,dOrgRate);
DEBUGLOG(("FindBalanceByCcy : org_rate = [%f]\n", dOrgRate));
			}

			if (GetField_Double(hRec,"ratio",&dOrgRatio)) {
				sprintf(csTag,"org_ratio_%d",i);
				PutField_Double(hFundIn,csTag,dOrgRatio);
DEBUGLOG(("FindBalanceByCcy : org_ratio = [%f]\n", dOrgRatio));
			}

			if(dOrgBankAmt>0.0){
				dRate_N += (dOrgBankAmt*dOrgRate);
				dRate_D += dOrgBankAmt;
			}

			dTmpAmt = 0.0;
			sprintf(csTag,"%s_ratio_D",csBankCcy);
			GetField_Double(hFundIn,csTag,&dTmpAmt);
DEBUGLOG(("before adding: %s_ratio_D = [%f]\n",csBankCcy,dTmpAmt));
			if((dTmpAmt+dOrgBankAmt)>0.0){
				PutField_Double(hFundIn,csTag,dTmpAmt+dOrgBankAmt);
DEBUGLOG(("after adding: %s_ratio_D = [%f]\n",csBankCcy,dTmpAmt+dOrgBankAmt));
			}
			else{
DEBUGLOG(("nothing change: %s_ratio_D = [%f]\n",csBankCcy,dTmpAmt));
			}
				
			dTmpAmt = 0.0;
			sprintf(csTag,"%s%s_ratio_N",csFromCcy,csBankCcy);
			GetField_Double(hFundIn,csTag,&dTmpAmt);
DEBUGLOG(("before adding: %s%s_ratio_N = [%f]\n",csFromCcy,csBankCcy,dTmpAmt));
			if((dTmpAmt+dOrgBankAmt)>0.0){
				PutField_Double(hFundIn,csTag,dTmpAmt+dOrgBankAmt);
DEBUGLOG(("after adding: %s%s_ratio_N = [%f]\n",csFromCcy,csBankCcy,dTmpAmt+dOrgBankAmt));
			}
			else{
DEBUGLOG(("nothing change: %s%s_ratio_N = [%f]\n",csFromCcy,csBankCcy,dTmpAmt));
			}
		}

		sprintf(csTag,"cal_rate_n_%d",i);
		PutField_Double(hFundIn,csTag,dRate_N);
DEBUGLOG(("Process Balance : cal_rate_n = [%f]\n", dRate_N));

		sprintf(csTag,"cal_rate_d_%d",i);
		PutField_Double(hFundIn,csTag,dRate_D);
DEBUGLOG(("Process Balance : cal_rate_d = [%f]\n", dRate_D));

/*
		sprintf(csTag,"cal_ratio_n_%d",i);
		PutField_Double(hFundIn,csTag,dRatio_N);
DEBUGLOG(("Process Balance : cal_ratio_n = [%f]\n", dRatio_N));
*/
		dRate_N=0.0;
		dRate_D=0.0;
		//dRatio_N=0;

	}

///////////////////////////////

	DBObjPtr = CreateObj(DBPtr,"DBSebBalance","FindAllBalance");
	if ((unsigned long)(*DBObjPtr)(rRecordSet) == PD_FOUND) {

DEBUGLOG(("Process Balance -> FindAllBalance : SUCCESS\n"));

		i = iTotal;
		hRec = RecordSet_GetFirst(rRecordSet);
		while(hRec){
			iRet = PD_OK;
			if(GetField_CString(hRec,"from_ccy",&csFromCcy)){
				strcpy(csBuf,csFromCcy);
				sprintf(csTag,"fundin_ccy_%d",i);
				PutField_CString(hFundIn,csTag,csFromCcy);
DEBUGLOG(("FindAllBalance : from_ccy = [%s]\n",csFromCcy));
			}
			if(GetField_CString(hRec,"bank_ccy",&csBankCcy)){
				strcat(csBuf,csBankCcy);
				sprintf(csTag,"bank_ccy_%d",i);
				PutField_CString(hFundIn,csTag,csBankCcy);
DEBUGLOG(("FindAllBalance : bank_ccy = [%s]\n",csBankCcy));
			}
			csBuf[strlen(csBuf)]='\0';

			for(j=0;j<iCnt;j++){
				sprintf(csTag,"have_ccy_%d",j);
				if(GetField_CString(hFundIn,csTag,&csTmp)){
					if(strcmp(csTmp,csBuf)==0){
						iRet = PD_FOUND;
					}
				}
			}
			for(j=0;j<iProcess;j++){
				sprintf(csTag,"process_bank_ccy_%d",j);
				if(GetField_CString(hFundIn,csTag,&csTmp)){
					if(strcmp(csTmp,csBankCcy)){
						iRet = PD_SKIP_OK;
					}
				}
			}


			if(iRet==PD_FOUND){
DEBUGLOG(("FindAllBalance : Record already processed, ignore\n"));
			}
			else if(iRet==PD_SKIP_OK){
DEBUGLOG(("FindAllBalance : bank ccy not affected, ignore\n"));
			}
			else{			
				dOrgBankAmt = 0.0;
				dOrgRate = 0.0;
				dOrgRatio = 0.0;
				
				if (GetField_Double(hRec,"bank_bal",&dOrgBankAmt)) {
					sprintf(csTag,"org_bank_amt_%d",i);
					PutField_Double(hFundIn,csTag,dOrgBankAmt);
DEBUGLOG(("FindAllBalance : org_bank_amt = [%f]\n", dOrgBankAmt));
				}
	
				if (GetField_Double(hRec,"rate",&dOrgRate)) {
					sprintf(csTag,"org_rate_%d",i);
					PutField_Double(hFundIn,csTag,dOrgRate);
DEBUGLOG(("FindAllBalance : org_rate = [%f]\n", dOrgRate));
				}
	
				if (GetField_Double(hRec,"ratio",&dOrgRatio)) {
					sprintf(csTag,"org_ratio_%d",i);
					PutField_Double(hFundIn,csTag,dOrgRatio);
DEBUGLOG(("FindAllBalance : org_ratio = [%f]\n", dOrgRatio));
				}

				if(dOrgBankAmt>0.0){
					dRate_N += newround((dOrgBankAmt*dOrgRate),PD_DECIMAL_LEN);
					dRate_D += dOrgBankAmt;
					//dRatio_N += dOrgBankAmt;
					//dRatio_D += dOrgBankAmt;

					dTmpAmt = 0.0;
					sprintf(csTag,"%s_ratio_D",csBankCcy);
					GetField_Double(hFundIn,csTag,&dTmpAmt);
DEBUGLOG(("before adding: %s_ratio_D = [%f]\n",csBankCcy,dTmpAmt));
					PutField_Double(hFundIn,csTag,dTmpAmt+dOrgBankAmt);
DEBUGLOG(("after adding: %s_ratio_D = [%f]\n",csBankCcy,dTmpAmt+dOrgBankAmt));
					dTmpAmt = 0.0;
					sprintf(csTag,"%s%s_ratio_N",csFromCcy,csBankCcy);
					GetField_Double(hFundIn,csTag,&dTmpAmt);
DEBUGLOG(("before adding: %s%s_ratio_N = [%f]\n",csFromCcy,csBankCcy,dTmpAmt));
					PutField_Double(hFundIn,csTag,dTmpAmt+dOrgBankAmt);
DEBUGLOG(("after adding: %s%s_ratio_N = [%f]\n",csFromCcy,csBankCcy,dTmpAmt+dOrgBankAmt));
				}
				else{
					dRate_N = dOrgRate;
					dRate_D = 1.0;
				}

				sprintf(csTag,"cal_rate_n_%d",i);
				PutField_Double(hFundIn,csTag,dRate_N);
DEBUGLOG(("Process Balance : cal_rate_n = [%f]\n", dRate_N));

				sprintf(csTag,"cal_rate_d_%d",i);
				PutField_Double(hFundIn,csTag,dRate_D);
DEBUGLOG(("Process Balance : cal_rate_d = [%f]\n", dRate_D));
				

				dRate_N=0.0;
				dRate_D=0.0;
//				dRatio_N=0;

				i++;
			}
			if(iRet==PD_SKIP_OK) iRet = PD_OK;
			hRec = RecordSet_GetNext(rRecordSet);
		}
	}

///////////////////////////////

//	PutField_Double(hFundIn,"cal_ratio_d",dRatio_D);
//DEBUGLOG(("Process Balance: cal_ratio_d = [%f]\n", dRatio_D));

	PutField_Int(hFundIn,"total_record",i);
DEBUGLOG(("Process Balance: total_record = [%d]\n", i));

	iRet = UpdateRateRatio(hFundIn);


	if(iRet==PD_OK){
DEBUGLOG(("Process Balance Normal Exit\n"));
	}
	else{
DEBUGLOG(("Process Balance Error [%d]\n",iRet));
ERRLOG("fundin_balance::Process Balance Error [%d]\n",iRet);
	}

	FREE_ME(csTmp);
	FREE_ME(csBuf);
	FREE_ME(hRec);
	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);
	return iRet;


}


int UpdateRateRatio(const hash_t* hFundIn)
{
	int	iRet = PD_OK;
	
	double	dNumerator=0.0;
	double	dDenominator=0.0;
	double	dRate=0.0;
	double	dRatio=0.0;
	double	dOrgRate=0.0;
	double	dOrgRatio=0.0;
	double	dOrgDspBal=0.0;
	double	dDspBal=0.0;
	double	dTmp=0.0;
	double	dFundinAmt=0.0;
	double	dBankAmt=0.0;
	//double	dDefThreshold=5.0;
	//double	dOandaRate=0.0;
	//double	dDefOandaThreshold=5.0;
	//double	dThreshold=5.0;
	//double	dOandaThreshold=5.0;
	//double	dDiff=0.0;
	int	iTotal=0;
	int	i=0;
	char	*csTmp;
	char	*csBankCcy;
	char	*csFromCcy;
	char	csTag[PD_TAG_LEN +1];

	hash_t *hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn,0);
	
DEBUGLOG(("*****Update Rate/Ratio Start*****\n"));
/*
DEBUGLOG(("Update RateRatio::DBSystemParameter->FindCode\n"));
	char*   csValueTmp;
	csValueTmp = (char*) malloc (128);
	DBObjPtr = CreateObj(DBPtr,"DBSystemParameter","FindCode");
	if ((unsigned long)(DBObjPtr)(PD_AVFXRATE_ALLOW_DIFF,csValueTmp) == FOUND) {
		sscanf(csValueTmp, "%lf",&dDefThreshold);
DEBUGLOG(("Update RateRatio:: Default New Rate difference threshold = [%lf]\n",dDefThreshold));
	}

	if ((unsigned long)(DBObjPtr)(PD_AVFX_OANDA_RATE_ALLOW_DIFF,csValueTmp) == FOUND) {
		sscanf(csValueTmp, "%lf",&dDefOandaThreshold);
DEBUGLOG(("Update RateRatio:: Default New Rate & Oanda Rate difference threshold = [%lf]\n",dDefOandaThreshold));
	}
	FREE_ME(csValueTmp);
*/

	if(GetField_Int(hFundIn,"total_record",&iTotal)){
DEBUGLOG(("Update RateRatio: total_record = [%d]\n", iTotal));
	}

	if(GetField_CString(hFundIn,"fundsin_id",&csTmp)){
		PutField_CString(hTxn,"fundsin_id",csTmp);
DEBUGLOG(("Update RateRatio: fundin_id = [%s]\n", csTmp));
	}

	if(GetField_CString(hFundIn,"fundin_date",&csTmp)){
		PutField_CString(hTxn,"fundin_date",csTmp);
DEBUGLOG(("Update RateRatio: fundin_date = [%s]\n", csTmp));
	}

	for(i=0; i<iTotal; i++){

DEBUGLOG(("Update RateRatio: process record[%d]\n", i));

////fundin_id////
/*
		sprintf(csTag,"fundin_id_%d",i);
                if(GetField_CString(hFundIn,csTag,&csTmp)){
			PutField_CString(hTxn,"fundsin_id",csTmp);
DEBUGLOG(("Update RateRatio: fundin_id = [%s]\n", csTmp));
		}

////fundin_date////
		//sprintf(csTag,"fundin_date_%d",i);
                if(GetField_CString(hFundIn,"fundin_date",&csTmp)){
			PutField_CString(hTxn,"fundin_date",csTmp);
DEBUGLOG(("Update RateRatio: fundin_date = [%s]\n", csTmp));
                }
*/

////fundin_ccy////
		sprintf(csTag,"fundin_ccy_%d",i);
                if(GetField_CString(hFundIn,csTag,&csFromCcy)){
			PutField_CString(hTxn,"from_ccy",csFromCcy);
			PutField_CString(hTxn,"fundin_ccy",csFromCcy);
DEBUGLOG(("Update RateRatio: fundin_ccy = [%s]\n", csFromCcy));
		}

////fundin_amt////
		sprintf(csTag,"fundin_amount_%d",i);
		if(!GetField_Double(hFundIn,csTag,&dFundinAmt)){
			dFundinAmt = 0.0;
		}
		PutField_Double(hTxn,"fundin_amt",dFundinAmt);
DEBUGLOG(("Update RateRatio: fundin_amt = [%f]\n", dFundinAmt));

////bank_ccy////
		sprintf(csTag,"bank_ccy_%d",i);
		if(GetField_CString(hFundIn,csTag,&csBankCcy)){
			PutField_CString(hTxn,"bank_ccy",csBankCcy);
DEBUGLOG(("Update RateRatio: bank_ccy = [%s]\n", csBankCcy));
		}

////bank_amt////
		sprintf(csTag,"bank_amount_%d",i);
		if(!GetField_Double(hFundIn,csTag,&dBankAmt)){
			dBankAmt = 0.0;
		}
		PutField_Double(hTxn,"bank_amt",dBankAmt);
DEBUGLOG(("Update RateRatio: bank_amt = [%f] (new)\n", dBankAmt));

////org_dsp_bal////
		sprintf(csTag,"org_dsp_bal_%d",i);
                if(GetField_Double(hFundIn,csTag,&dOrgDspBal)){
DEBUGLOG(("Update RateRatio: org_dsp_bal = [%f]\n", dOrgDspBal));
			dDspBal = dBankAmt + dOrgDspBal;
			PutField_Double(hTxn,"dsp_bal",dBankAmt);
DEBUGLOG(("Update RateRatio: bank_bal = [%f] (total)\n", dDspBal));
		}

		sprintf(csTag,"org_bank_amt_%d",i);
                if(GetField_Double(hFundIn,csTag,&dTmp)){
                        dBankAmt += dTmp;
DEBUGLOG(("Update RateRatio: bank_amt = [%f] (org)\n", dTmp));
                }
		PutField_Double(hTxn,"bank_bal",dBankAmt);
DEBUGLOG(("Update RateRatio: bank_bal = [%f] (total)\n", dBankAmt));


////org_rate////
		sprintf(csTag,"org_rate_%d",i);
                if(GetField_Double(hFundIn,csTag,&dOrgRate)){
                        PutField_Double(hTxn,"org_rate",dOrgRate);
DEBUGLOG(("Update RateRatio: org_rate = [%f]\n", dOrgRate));
                }
		else{
			dOrgRate = 0.0;
                        PutField_Double(hTxn,"org_rate",dOrgRate);
DEBUGLOG(("Update RateRatio: org_rate = [%f] (no org rate)\n", dOrgRate));
		}

////org_ratio////
		sprintf(csTag,"org_ratio_%d",i);
                if(GetField_Double(hFundIn,csTag,&dOrgRatio)){
                        PutField_Double(hTxn,"org_ratio",dOrgRatio);
DEBUGLOG(("Update RateRatio: org_ratio = [%f]\n", dOrgRatio));
                }


////rate////
		sprintf(csTag,"cal_rate_n_%d",i);
                if(GetField_Double(hFundIn,csTag,&dNumerator)){
			if(dNumerator!=0){
				sprintf(csTag,"cal_rate_d_%d",i);
                		if(!GetField_Double(hFundIn,csTag,&dDenominator)){
DEBUGLOG(("Failed to calculate rate!!!!\n"));
ERRLOG("fundin_balance::Failed to calculate rate!!!!\n");
					iRet = FI_INT_ERROR;
				}
			}
			
		}
		else{
DEBUGLOG(("Failed to calculate rate!!!!\n"));
ERRLOG("fundin_balance::Failed to calculate rate!!!!\n");
			iRet = FI_INT_ERROR;
		}
/*
		if(iRet==PD_OK && !iSkipTolCheck){
			//find override tolerance
			DBObjPtr = CreateObj(DBPtr,"DBACRThreshold","FindTolerance");
			if ((unsigned long)(DBObjPtr)("OANDA",csBankCcy,&dOandaThreshold) != PD_FOUND) {
				dOandaThreshold = dDefOandaThreshold;
			}
			if ((unsigned long)(DBObjPtr)("ORG_ACR",csBankCcy,&dThreshold) != PD_FOUND) {
				dThreshold = dDefThreshold;
			}
DEBUGLOG(("OandaThreshold [%lf], dThreshold [%lf]\n",dOandaThreshold,dThreshold));
		}
*/
		if(iRet==PD_OK){
			if((dNumerator==0.0)||(dNumerator==0.0)){
				dRate = 0.0;
			}
			else{
				dRate = newround((dNumerator/dDenominator),PD_ROUND_UP_DEC);
			}

			if(dRate<0.0){
DEBUGLOG(("Calculate rate Error!!!!\n"));
ERRLOG("fundin_balance::Calculate rate Error!!!!\n");
				iRet = FI_INT_ERROR;
			}
			else{
				if(dOrgRate>0.0){
/*
					dDiff = 0.0;
					if(dRate>dOrgRate){
						dDiff = (dRate-dOrgRate)/dOrgRate;
DEBUGLOG(("New rate [%lf] with difference 1[%lf]\n",dRate,dDiff));
					}
					else{
						dDiff = (dOrgRate-dRate)/dOrgRate;
DEBUGLOG(("New rate [%lf] with difference 2 [%lf]\n",dRate,dDiff));
					}
					if(!iSkipTolCheck){
						if(dDiff*100 > dThreshold){
DEBUGLOG(("New rate with difference [%lf\%] > [%lf\%]!!!!\n",dDiff*100,dThreshold));
ERRLOG("fundin_balance::New rate with difference [%lf\%] > [%lf\%]!!!!\n",dDiff*100,dThreshold);
							iRet = FI_NEW_RATE_ERROR;
						}
					}
*/
					if(iRet == PD_OK){
						PutField_Double(hTxn,"rate",dRate);
DEBUGLOG(("Update RateRatio: rate = [%f]\n", dRate));
					}
				}
				else if(dOrgRate==0.0 && dRate > 0.0){
					PutField_Double(hTxn,"rate",dRate);
DEBUGLOG(("Update RateRatio: rate = [%f]\n", dRate));
				}
				else if(dOrgRate==0.0 && dRate ==0.0){
					RemoveField_Double(hTxn,"rate");
                                }
/*
				if(iRet==PD_OK && iCheckOandaRate && !iSkipTolCheck && dRate > 0.0 && dDiff>0.0){
					//get oanda rate
					hash_t *hOanda;
					hOanda = (hash_t*) malloc (sizeof(hash_t));
					hash_init(hOanda,0);
					DBObjPtr = CreateObj(DBPtr,"DBExchangeRate","GetExchangeRate");
					if((unsigned long)(*DBObjPtr)(csBankCcy,csFromCcy,hOanda)==PD_OK){
						if(GetField_Double(hOanda,"rate",&dOandaRate)){
							dDiff = 0.0;
							if(dRate>dOandaRate){
								dDiff = (dRate-dOandaRate)/dOandaRate;
DEBUGLOG(("New rate [%lf] with difference Oanda Rate 1[%lf]\n",dRate,dDiff));
							}
							else{
								dDiff = (dOandaRate-dRate)/dOandaRate;
DEBUGLOG(("New rate [%lf] with difference Oanda Rate 2 [%lf]\n",dRate,dDiff));
							}
							if(dDiff*100 >dOandaThreshold){
DEBUGLOG(("New rate & Oanda Rate with difference [%lf] > [%lf]!!!!\n",dDiff*100,dOandaThreshold));
ERRLOG("fundin_balance::New rate & Oanda Rate with difference [%lf] > [%lf]!!!!\n",dDiff*100,dOandaThreshold);
								RemoveField_Double(hTxn,"rate");
								iRet = FI_NEW_W_OANDA_RATE_ERROR;
							}
						}
						else{
							iRet = FI_INT_ERROR;
						}
					}
					else{
						iRet = FI_INT_ERROR;
					}
					FREE_ME(hOanda);
				}
*/
			}
		}

////ratio////
		if(iRet == PD_OK){
			dDenominator = 0.0;
			sprintf(csTag,"%s_ratio_D",csBankCcy);
			GetField_Double(hFundIn,csTag,&dDenominator);
DEBUGLOG(("before Calculation: %s_ratio_D = [%f]\n",csBankCcy,dDenominator));
			dNumerator = 0.0;
			sprintf(csTag,"%s%s_ratio_N",csFromCcy,csBankCcy);
			GetField_Double(hFundIn,csTag,&dNumerator);
DEBUGLOG(("before Calculation: %s%s_ratio_N = [%f]\n",csFromCcy,csBankCcy,dNumerator));
/*
			sprintf(csTag,"cal_ratio_n_%d",i);
                	if(GetField_Double(hFundIn,csTag,&dNumerator)){
				if(!GetField_Double(hFundIn,"cal_ratio_d",&dDenominator)){
DEBUGLOG(("Failed to calculate ratio!!!!\n"));
ERRLOG("fundin_balance::Failed to calculate ratio!!!!\n");
					iRet = FI_INT_ERROR;
				}
			}
			else{
DEBUGLOG(("Failed to calculate ratio!!!!\n"));
ERRLOG("fundin_balance::Failed to calculate ratio!!!!\n");
				iRet = FI_INT_ERROR;
			}
*/
			if((iRet==PD_OK)&&(dDenominator>0.0)){
				dRatio = newround((dNumerator/dDenominator),PD_ROUND_UP_DEC);
				if(dRatio<0){
DEBUGLOG(("Calculate ratio Error!!!!\n"));
ERRLOG("fundin_balance::Calculate ratio Error!!!!\n");
					iRet = FI_INT_ERROR;
				}
				else{
					PutField_Double(hTxn,"ratio",dRatio);
DEBUGLOG(("Update RateRatio: ratio = [%f]\n", dRatio));
				}
			}
			else{
				PutField_Double(hTxn,"ratio",0.0);
DEBUGLOG(("Update RateRatio: ratio = [0.0]\n"));
			}
		}

		PutField_CString(hTxn,"add_user",PD_UPDATE_USER);
		PutField_CString(hTxn,"cal_user",PD_UPDATE_USER);

		if(iRet==PD_OK){
DEBUGLOG(("*****Update SebBalance table*****\n"));
			DBObjPtr = CreateObj(DBPtr,"DBSebBalance","Add");
			iRet = (unsigned long)(*DBObjPtr)(hTxn);
                }

		if(iRet==PD_OK){
			if(dFundinAmt!=0){
DEBUGLOG(("*****Update FundsIn table*****\n"));
				DBObjPtr = CreateObj(DBPtr,"DBFundsIn","UpdateCal");
				iRet = (unsigned long)(*DBObjPtr)(hTxn);
			}
		}

		if(iRet==PD_OK){
DEBUGLOG(("*****Update FundsIn History table*****\n"));
			DBObjPtr = CreateObj(DBPtr,"DBFundsInHistory","Add");
			iRet = (unsigned long)(*DBObjPtr)(hTxn);
		}
	}



	if(iRet==PD_OK){
DEBUGLOG(("Update RateRatio Normal Exit\n"));
	}
	else{
DEBUGLOG(("Update RateRatio Error [%d]\n",iRet));
ERRLOG("fundin_balance::Update RateRatio Error [%d]\n",iRet);
	}

	FREE_ME(hTxn);
	return iRet;
}



int parse_arg(int argc,char **argv)
{
        char    c;
	strcpy(cs_fundin_date,"");
	strcpy(cs_fundin_id,"");
	strcpy(cs_check_rate,"");
	iCheckOandaRate = PD_FALSE;
	strcpy(cs_skip_tol_check,"");
	iSkipTolCheck = PD_FALSE;

        while ((c = getopt(argc,argv,"d:i:c:k:")) != EOF) {
                switch (c) {
                        case 'd':
                                strcpy(cs_fundin_date, optarg);
                                break;
                        case 'i':
                                strcpy(cs_fundin_id, optarg);
                                break;
                        case 'c':
				strcpy(cs_check_rate, optarg);
				iCheckOandaRate = atoi(cs_check_rate);
				break;
                        case 'k':
				strcpy(cs_skip_tol_check, optarg);
				iSkipTolCheck = atoi(cs_skip_tol_check);
				break;
                        default:
                                return FI_INVALID_TXN;
                }
        }

        if (!strcmp(cs_fundin_date,"") && !strcmp(cs_fundin_id,"")) 
                return FI_INVALID_TXN;

	if(strlen(cs_fundin_id)>0){
		iMode = PD_INPUT_ID;
	}

        return SUCCESS;
}
