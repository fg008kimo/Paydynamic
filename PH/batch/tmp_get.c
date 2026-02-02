
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
           char  filnam[11];
};
static struct sqlcxp sqlfpn =
{
    10,
    "tmp_get.pc"
};


static unsigned int sqlctx = 83499;


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
"select th_txn_id ,th_transaction_amount ,th_client_ip ,th_local_tm_date ,th\
_local_tm_time ,th_status ,th_ar_ind  from txn_header ,txn_psp_detail where (\
(th_txn_id=tp_txn_id and th_local_tm_date between :b0 and :b1) and tp_psp_id=\
:b2) order by th_txn_id            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,264,0,9,149,0,0,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
32,0,0,1,0,0,13,151,0,0,7,0,0,1,0,2,9,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,1,
0,0,2,1,0,0,
75,0,0,1,0,0,15,223,0,0,0,0,0,1,0,
90,0,0,1,0,0,15,229,0,0,0,0,0,1,0,
105,0,0,2,0,0,32,230,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/08/29              LokMan Chow
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


#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode
#define	PD_MY_DELIMITOR	','
#define	PD_TR		"<tr>"
#define	PD_TD		"<td>"
#define	PD_TD_STYLE	"<td class=\"format\">"
#define	PD_TR_END	"</tr>"
#define	PD_TD_END	"</td>"

char    cs_txn_date_a[PD_DATE_LEN + 1];
char    cs_txn_date_b[PD_DATE_LEN + 1];
char	cs_psp_id[PD_PSP_ID_LEN + 1];
char    cDebug;

int parse_arg(int argc,char **argv);
int process_txn(unsigned char* csTxnDateA, unsigned char* csTxnDateB, unsigned char* csPspId);
int batch_init(int argc, char* argv[])
{

    if (argc < 2) {
        printf("usage:  -a txn_date_a -b txn_date_b  -p psp_id\n");
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
        	printf("usage:  -a txn_date_a -b txn_date_b  -p psp_id\n");
                return (iRet);
        }


	printf("<html><body><table>\n");
	printf("%s%sPH Txn ID%s%sTxn Amount%s%sClient IP%s%sLocal TM DateTime%s%sStatus%s%sAR Ind%s%s\n",PD_TR,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TD,PD_TD_END,PD_TR_END);
	printf("<style type=\"text/css\"> .format{ mso-number-format:'\\@';} </style>\n");


        iRet = process_txn((unsigned char *)cs_txn_date_a,(unsigned char *)cs_txn_date_b, (unsigned char *)cs_psp_id);

	printf("</table></body></html>\n");

	return iRet;


}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}




int process_txn(unsigned char* csTxnDateA, unsigned char* csTxnDateB, unsigned char* csPspId)
{               
 
        int     iRet = SUCCESS;
        
        /* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		
		/* varchar	hv_txn_date_a[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_txn_date_a;

		/* varchar	hv_txn_date_b[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_txn_date_b;

		/* varchar	hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;


		char	v_status;
		char	v_ar_ind;
		/* varchar	v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		double	v_txn_amount;
		/* varchar	v_local_tm_date[PD_DATE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_local_tm_date;

		/* varchar	v_local_tm_time[PD_DATE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_local_tm_time;

		/* varchar	v_client_ip[PD_IP_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_client_ip;


		short	ind_txn_id = -1;
		short	ind_txn_amount = -1;
		short	ind_client_ip = -1;
		short	ind_local_tm_date = -1;
		short	ind_local_tm_time = -1;
		short   ind_status = -1;
		short   ind_ar_ind = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_date_a.len = strlen((const char*)csTxnDateA);
        memcpy(hv_txn_date_a.arr,csTxnDateA,hv_txn_date_a.len);

	hv_txn_date_b.len = strlen((const char*)csTxnDateB);
        memcpy(hv_txn_date_b.arr,csTxnDateB,hv_txn_date_b.len);

	hv_psp_id.len = strlen((const char*) csPspId);
        memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);

	//hv_status = 'W';

        /* EXEC SQL DECLARE c_cursor_gettxn CURSOR FOR
		select 	th_txn_id,
         		th_transaction_amount,
			th_client_ip,
         		th_local_tm_date,
         		th_local_tm_time,
			th_status,
			th_ar_ind
		  from 	txn_header,
        		txn_psp_detail
    		where th_txn_id = tp_txn_id
    		and th_local_tm_date between :hv_txn_date_a and :hv_txn_date_b
		and tp_psp_id = :hv_psp_id
		//and th_status = :hv_status
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
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_txn_date_a;
        sqlstm.sqhstl[0] = (unsigned long )10;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_date_b;
        sqlstm.sqhstl[1] = (unsigned long )10;
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
         		v_txn_amount:ind_txn_amount,
			v_client_ip:ind_client_ip,
         		v_local_tm_date:ind_local_tm_date,
         		v_local_tm_time:ind_local_tm_time,
			v_status:ind_status,
			v_ar_ind:ind_ar_ind; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 7;
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
                sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_txn_amount;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_client_ip;
                sqlstm.sqhstl[2] = (unsigned long )28;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_client_ip;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_local_tm_date;
                sqlstm.sqhstl[3] = (unsigned long )11;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_local_tm_date;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_local_tm_time;
                sqlstm.sqhstl[4] = (unsigned long )11;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_local_tm_time;
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
		printf("%s",PD_TR);
/* txn id */
		if (ind_txn_id < 0 )
			v_txn_id.arr[0] = '\0';
		printf("%s%.*s%s",PD_TD_STYLE,v_txn_id.len,v_txn_id.arr,PD_TD_END);

/* txn_amount */
		if (ind_txn_amount < 0 )
			v_txn_amount = 0;	
		printf("%s%f%s",PD_TD,v_txn_amount,PD_TD_END);

/* client ip*/
		if (ind_client_ip < 0 )
			v_client_ip.arr[0] = '\0';
		printf("%s%.*s%s",PD_TD_STYLE,v_client_ip.len,v_client_ip.arr,PD_TD_END);

/* local_tm_date */
		if (ind_local_tm_date < 0 )
			v_local_tm_date.arr[0] = '\0';

		if (ind_local_tm_time < 0 )
			v_local_tm_time.arr[0] = '\0';
		printf("%s%.*s %.*s%s",PD_TD_STYLE,v_local_tm_date.len,v_local_tm_date.arr,v_local_tm_time.len,v_local_tm_time.arr,PD_TD_END);

/* status*/
		if (ind_status < 0 ){
			printf("%s%s",PD_TD,PD_TD_END);
		}
		else{
			if(v_status=='C'){
				printf("%sComplete%s",PD_TD,PD_TD_END);
			}
			else if(v_status=='W'){
				printf("%sPending%s",PD_TD,PD_TD_END);
			}
			else{
				printf("%s%c%s",PD_TD,v_status,PD_TD_END);
			}
		}
/* ar_ind*/
		if (ind_ar_ind < 0 ){
			printf("%s%s",PD_TD,PD_TD_END);
		}
		else{
			if(v_ar_ind=='A'){
				printf("%sAccept%s",PD_TD,PD_TD_END);
			}
			else if(v_ar_ind=='R'){
				printf("%sReject%s",PD_TD,PD_TD_END);
			}
			else{
				printf("%s%c%s",PD_TD,v_ar_ind,PD_TD_END);
			}
		}

		printf("%s\n",PD_TR_END);
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
        sqlstm.offset = (unsigned int  )75;
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
    sqlstm.offset = (unsigned int  )90;
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
    sqlstm.offset = (unsigned int  )105;
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
	strcpy(cs_txn_date_a,"");
	strcpy(cs_txn_date_b,"");
	strcpy(cs_psp_id,"");

        while ((c = getopt(argc,argv,"a:b:p:")) != EOF) {
                switch (c) {
                        case 'a':
                                strcpy(cs_txn_date_a, optarg);
                                break;
                        case 'b':
                                strcpy(cs_txn_date_b, optarg);
                                break;
                        case 'p':
                                strcpy(cs_psp_id, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_txn_date_a,"") || !strcmp(cs_txn_date_b,"") || !strcmp(cs_psp_id,""))
                return FAILURE;

        return SUCCESS;
}
