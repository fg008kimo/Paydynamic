
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
    "inq_alp_pend_txn.pc"
};


static unsigned int sqlctx = 40148427;


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
   unsigned char  *sqhstv[1];
   unsigned long  sqhstl[1];
            int   sqhsts[1];
            short *sqindv[1];
            int   sqinds[1];
   unsigned long  sqharm[1];
   unsigned long  *sqharc[1];
   unsigned short  sqadto[1];
   unsigned short  sqtdso[1];
} sqlstm = {12,1};

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
"select th_txn_id  from txn_psp_detail ,txn_header ,psp_detail where (((((((\
tp_txn_id=th_txn_id and th_status='W') and tp_create_timestamp>(sysdate-(:b0/\
24))) and tp_create_timestamp<(sysdate-(0.5/24))) and tp_psp_id=psp_id) and p\
sp_channel_code='ALP') and disabled=0) and th_txn_code in ('DSI','DSP')) orde\
r by th_create_timestamp            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,342,0,9,168,0,0,1,1,0,1,0,1,3,0,0,
24,0,0,1,0,0,13,170,0,0,1,0,0,1,0,2,9,0,0,
43,0,0,1,0,0,15,196,0,0,0,0,0,1,0,
58,0,0,1,0,0,15,204,0,0,0,0,0,1,0,
73,0,0,2,0,0,32,205,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/05/22              Virginia Yun
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
#include "ObjPtr.h"
#include "dbutility.h"
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"
#include "inq_alp_pend_txn.h"


#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

OBJPTR(Txn);
OBJPTR(DB);
OBJPTR(Channel);

char    cDebug='Y';

int	iTimeInterval = 0;
recordset_t *rRecordSet;

int parse_arg(int argc,char **argv);
int process_gettxn(hash_t *hContext, hash_t *hRequest);
int process_inqtxn(hash_t *hContext, hash_t *hRequest, hash_t *hResponse);

int batch_init(int argc, char* argv[])
{
	if (argc < 2) {
		printf("usage: -t time_interval (in hour)\n");
		return FAILURE;
	}
	else 
		return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int	iRet;
	
        hash_t  *hContext, *hRequest, *hResponse;

        hContext = (hash_t *)malloc(sizeof(hash_t));
        hRequest = (hash_t *)malloc(sizeof(hash_t));
        hResponse= (hash_t *)malloc(sizeof(hash_t));

        hash_init(hContext,  0);
        hash_init(hRequest,  0);
        hash_init(hResponse, 0);

	
	iRet = parse_arg(argc,argv);

	if (iRet != SUCCESS) {
    		printf("usage: -t time_interval (in hour)\n");
		return (iRet);
	}

	iRet = process_gettxn(hContext, hRequest);

	if (iRet == SUCCESS) {
		iRet = process_inqtxn(hContext, hRequest, hResponse);
	}

	hash_destroy(hContext);
	hash_destroy(hRequest);
	hash_destroy(hResponse);

	FREE_ME(hContext);
	FREE_ME(hRequest);
	FREE_ME(hResponse);

	return iRet;

}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


                        
int parse_arg(int argc,char **argv)
{               
        char    c;
	char	csTmp[PD_TMP_BUF_LEN + 1];
                        
        while ((c = getopt(argc,argv,"t:")) != EOF) {
                switch (c) {
                        case 't':
				memset(csTmp, 0, sizeof(csTmp));
                                strcpy(csTmp, optarg);
				iTimeInterval = atoi(csTmp);
                                break;
                        default:
                                return FAILURE;
                }
        }       
        
DEBUGLOG(("TimeInteval[%d]\n",iTimeInterval));
                
        return SUCCESS; 
}               


int process_gettxn(hash_t *hContext, hash_t *hRequest)
{
	int 	iRet = SUCCESS;

	char	csTag[PD_TAG_LEN  + 1];
	int 	iCnt = 0;


DEBUGLOG(("process_gettxn start\n"));
	rRecordSet = (recordset_t*) malloc(sizeof(recordset_t));
	recordset_init(rRecordSet, 0);

	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int	hv_time_interval;
		
		/* varchar	v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		short	ind_txn_id = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_time_interval = iTimeInterval;


        /* EXEC SQL DECLARE c_cursor_gettxn CURSOR FOR
                select  th_txn_id
                   from txn_psp_detail,
                        txn_header,
			psp_detail
                  where tp_txn_id = th_txn_id
                    and th_status = 'W'
                    and tp_create_timestamp > sysdate - (:hv_time_interval/24)
		    and tp_create_timestamp < sysdate - (0.5/24)
                    and tp_psp_id = psp_id
		    and psp_channel_code = 'ALP'
                    and disabled = 0
                    and th_txn_code in ('DSI', 'DSP')
		order by th_create_timestamp ; */ 


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
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_time_interval;
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
        if (sqlca.sqlcode < 0) goto sql_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_gettxn
		INTO	:v_txn_id:ind_txn_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 1;
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


		if (ind_txn_id >= 0) {

			iCnt++;

			v_txn_id.arr[v_txn_id.len] = '\0';

			memset(csTag, 0, sizeof(csTag));
			sprintf(csTag, "txn_id_%d", iCnt);
			PutField_CString(hRequest, csTag, (const char*)v_txn_id.arr);

DEBUGLOG(("pending %s = [%s]\n", csTag, v_txn_id.arr));

			PutField_Int(hRequest, "total_cnt", iCnt);
		}


	} while (PD_TRUE && iRet == SUCCESS);

	/* EXEC SQL CLOSE c_cursor_gettxn; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )43;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto sql_error;
}



	return iRet;

sql_error:
DEBUGLOG(("process_gettxn error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_gettxn; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
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


	/* EXEC SQL ROLLBACK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )73;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return FAILURE;

}

int process_inqtxn(hash_t *hContext, hash_t *hRequest, hash_t *hResponse)
{
	
	int 	iRet = SUCCESS;
	int	iTmpRet = FAILURE;

	int 	iTotalCnt = 0;
	char	csTag[PD_TAG_LEN  + 1];
	char	*csPtr;
	int	i;

	char    csTxnSeq[PD_TXN_SEQ_LEN +1];
	char    csLocalTxnDateTime[PD_DATETIME_LEN +1];

	if (GetField_Int(hRequest, "total_cnt", &iTotalCnt)) {

		for (i = 1; i < iTotalCnt + 1; i++) {
			DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextTxnSeq");
			strcpy(csTxnSeq,(*DBObjPtr)());
			PutField_CString(hContext,"txn_seq",csTxnSeq);
			strcpy(csLocalTxnDateTime,getdatetime());
			PutField_CString((hash_t*)hRequest,"local_tm_datetime",csLocalTxnDateTime);

			memset(csTag, 0, sizeof(csTag));
			sprintf(csTag, "txn_id_%d", i);

			if (GetField_CString(hRequest, csTag, &csPtr)) {
DEBUGLOG(("Record [%d] txn_id = [%s]\n", i, csPtr));

				PutField_CString(hContext, "org_txn_id", csPtr);
				PutField_CString(hContext, "org_txn_code", PD_POLL_TXN_CODE);
				ChannelObjPtr = CreateObj(ChannelPtr,"WEBChannel","UpdateContext");
				iTmpRet = (unsigned long)((*ChannelObjPtr)(hContext));

				if (iTmpRet == PD_OK) {
DEBUGLOG(("Calling TxnAlpByUsINQ::Authorize\n"));
					TxnObjPtr = CreateObj(TxnPtr,"TxnAlpByUsINQ","Authorize");
					iTmpRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);

					if (iTmpRet == PD_OK) {
DEBUGLOG(("txn_id = [%s] commit\n", csPtr));
						TxnCommit();
					} else {
DEBUGLOG(("txn_id = [%s] abort\n", csPtr));
						TxnAbort();
					}
				}
			}
		} // end for loop
	}

	return iRet;

}
