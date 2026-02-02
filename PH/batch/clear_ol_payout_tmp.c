
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
           char  filnam[23];
};
static struct sqlcxp sqlfpn =
{
    22,
    "clear_ol_payout_tmp.pc"
};


static unsigned int sqlctx = 295638059;


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

 static char *sq0003 = 
"select oah_batch_id from ol_payout_api_batch_hd , ol_payout_api_batch_dt wh\
ere oah_batch_id = oad_batch_id and oah_create_timestamp < sysdate - :b0 grou\
p by oah_batch_id            ";

 static char *sq0008 = 
"select oap_batch_id from ol_payout_api_pregen_hd , ol_payout_api_pregen_dt \
where oap_batch_id = oag_batch_id and oap_create_timestamp < sysdate - :b0 gr\
oup by oap_batch_id            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,79,0,2,126,0,0,1,1,0,1,0,1,3,0,0,
24,0,0,2,0,0,32,136,0,0,0,0,0,1,0,
39,0,0,3,181,0,9,170,0,2049,1,1,0,1,0,1,3,0,0,
58,0,0,3,0,0,13,172,0,0,1,0,0,1,0,2,9,0,0,
77,0,0,3,0,0,15,194,0,0,0,0,0,1,0,
92,0,0,3,0,0,15,207,0,0,0,0,0,1,0,
107,0,0,4,60,0,2,229,0,0,1,1,0,1,0,1,9,0,0,
126,0,0,5,0,0,32,239,0,0,0,0,0,1,0,
141,0,0,6,60,0,2,259,0,0,1,1,0,1,0,1,9,0,0,
160,0,0,7,0,0,32,269,0,0,0,0,0,1,0,
175,0,0,8,183,0,9,302,0,2049,1,1,0,1,0,1,3,0,0,
194,0,0,8,0,0,13,304,0,0,1,0,0,1,0,2,9,0,0,
213,0,0,8,0,0,15,326,0,0,0,0,0,1,0,
228,0,0,8,0,0,15,339,0,0,0,0,0,1,0,
243,0,0,9,61,0,2,361,0,0,1,1,0,1,0,1,9,0,0,
262,0,0,10,0,0,32,371,0,0,0,0,0,1,0,
277,0,0,11,61,0,2,391,0,0,1,1,0,1,0,1,9,0,0,
296,0,0,12,0,0,32,401,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/05/21              LokMan Chow
Add house-keep for API Batch HD & DT		   2017/05/10		   LokMan Chow

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

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define NUM_OF_EXPIRY_DAY	14
int	num_of_day = NUM_OF_EXPIRY_DAY;

char    cDebug  = 'Y';

OBJPTR(DB);

int parse_arg(int argc,char **argv);
int delete_gen_tmp();
int get_api_batch(recordset_t     *rBatch);
int delete_api_batch_dt(const char* batch_id);
int delete_api_batch_hd(const char* batch_id);
int get_gen_batch(recordset_t     *rBatch);
int delete_gen_batch_dt(const char* batch_id);
int delete_gen_batch_hd(const char* batch_id);

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
        int     iRet;
	char	*csBatchId = NULL;
	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);

	hash_t *hRec;

	iRet = parse_arg(argc,argv);
	if(iRet == SUCCESS)
		iRet = delete_gen_tmp();

	if(iRet == SUCCESS){

		if(get_api_batch(rRecordSet)==SUCCESS){

			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if(GetField_CString(hRec,"batch_id",&csBatchId)){
					if(delete_api_batch_dt(csBatchId)==SUCCESS){
						iRet = delete_api_batch_hd(csBatchId);
					}
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
		RecordSet_Destroy(rRecordSet);


		if(get_gen_batch(rRecordSet)==SUCCESS){

			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if(GetField_CString(hRec,"batch_id",&csBatchId)){
					if(delete_gen_batch_dt(csBatchId)==SUCCESS){
						iRet = delete_gen_batch_hd(csBatchId);
					}
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
		RecordSet_Destroy(rRecordSet);

	}


	FREE_ME(rRecordSet);
	return iRet;
}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


int delete_gen_tmp()
{
	int	iRet = SUCCESS;

	/* EXEC SQL WHENEVER SQLERROR GOTO delete_gen_tmp_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		int	hv_num_of_day;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_num_of_day = num_of_day;

        /* EXEC SQL 
		delete from ol_payout_generated_tmp
		where opt_create_timestamp < sysdate - :hv_num_of_day; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "delete from ol_payout_generated_tmp where opt_create\
_timestamp < sysdate - :b0 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )5;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_num_of_day;
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
        if (sqlca.sqlcode < 0) goto delete_gen_tmp_error;
}



	return iRet;

delete_gen_tmp_error:
DEBUGLOG(("delete_gen_tmp error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )24;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}



int get_api_batch(recordset_t     *rBatch)
{
	int     iRet = SUCCESS;
	int	iCnt = 0;
	hash_t *myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO get_api_batch_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int     hv_num_of_day;

		/* varchar	v_batch_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_batch_id;

		short	ind_batch_id = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_num_of_day = num_of_day;

	/* EXEC SQL DECLARE c_cursor_get_api_batch CURSOR FOR
		select	oah_batch_id
		from	ol_payout_api_batch_hd,
			ol_payout_api_batch_dt
		where oah_batch_id = oad_batch_id
		and oah_create_timestamp < sysdate - :hv_num_of_day
		group by oah_batch_id; */ 



	/* EXEC SQL OPEN c_cursor_get_api_batch; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )39;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_num_of_day;
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
 if (sqlca.sqlcode < 0) goto get_api_batch_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_get_api_batch
		INTO
			:v_batch_id:ind_batch_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 1;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )58;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_batch_id;
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
  if (sqlca.sqlcode < 0) goto get_api_batch_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

		if (ind_batch_id >= 0) {
			v_batch_id.arr[v_batch_id.len] ='\0';
			PutField_CString(myHash,"batch_id",(const char*)v_batch_id.arr);
		}

		RecordSet_Add(rBatch,myHash);
	}
	while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_get_api_batch; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )77;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto get_api_batch_error;
}



	if (iCnt > 0 )
		iRet = SUCCESS;
	else
		iRet = FAILURE;

	return	iRet;

get_api_batch_error:
DEBUGLOG(("get_api_batch_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_get_api_batch; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )92;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return FAILURE;
}



int delete_api_batch_dt(const char* batch_id)
{
        int     iRet = SUCCESS;

        /* EXEC SQL WHENEVER SQLERROR GOTO delete_api_batch_dt_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar     hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;



        /* EXEC SQL END DECLARE SECTION; */ 


	hv_batch_id.len = strlen(batch_id);
	memcpy(hv_batch_id.arr,batch_id,hv_batch_id.len);        

        /* EXEC SQL
                delete from ol_payout_api_batch_dt
                where  oad_batch_id = :hv_batch_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "delete from ol_payout_api_batch_dt where oad_batch_i\
d = :b0 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )107;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_batch_id;
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
        if (sqlca.sqlcode < 0) goto delete_api_batch_dt_error;
}



        return iRet;

delete_api_batch_dt_error:
DEBUGLOG(("delete_api_batch_dt error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )126;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}

int delete_api_batch_hd(const char* batch_id)
{
        int     iRet = SUCCESS;

        /* EXEC SQL WHENEVER SQLERROR GOTO delete_api_batch_hd_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar     hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;



        /* EXEC SQL END DECLARE SECTION; */ 


	hv_batch_id.len = strlen(batch_id);
	memcpy(hv_batch_id.arr,batch_id,hv_batch_id.len);        

        /* EXEC SQL
                delete from ol_payout_api_batch_hd
                where oah_batch_id = :hv_batch_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "delete from ol_payout_api_batch_hd where oah_batch_i\
d = :b0 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )141;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_batch_id;
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
        if (sqlca.sqlcode < 0) goto delete_api_batch_hd_error;
}



        return iRet;

delete_api_batch_hd_error:
DEBUGLOG(("delete_api_batch_hd error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )160;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}


int get_gen_batch(recordset_t     *rBatch)
{
	int     iRet = SUCCESS;
	int	iCnt = 0;
	hash_t *myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO get_gen_batch_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int     hv_num_of_day;

		/* varchar	v_batch_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_batch_id;

		short	ind_batch_id = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_num_of_day = num_of_day;

	/* EXEC SQL DECLARE c_cursor_get_gen_batch CURSOR FOR
		select	oap_batch_id
		from	ol_payout_api_pregen_hd,
			ol_payout_api_pregen_dt
		where oap_batch_id = oag_batch_id
		and oap_create_timestamp < sysdate - :hv_num_of_day
		group by oap_batch_id; */ 



	/* EXEC SQL OPEN c_cursor_get_gen_batch; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0008;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )175;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_num_of_day;
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
 if (sqlca.sqlcode < 0) goto get_gen_batch_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_get_gen_batch
		INTO
			:v_batch_id:ind_batch_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 1;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )194;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_batch_id;
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
  if (sqlca.sqlcode < 0) goto get_gen_batch_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

		if (ind_batch_id >= 0) {
			v_batch_id.arr[v_batch_id.len] ='\0';
			PutField_CString(myHash,"batch_id",(const char*)v_batch_id.arr);
		}

		RecordSet_Add(rBatch,myHash);
	}
	while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_get_gen_batch; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )213;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto get_gen_batch_error;
}



	if (iCnt > 0 )
		iRet = SUCCESS;
	else
		iRet = FAILURE;

	return	iRet;

get_gen_batch_error:
DEBUGLOG(("get_gen_batch_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_get_gen_batch; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )228;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return FAILURE;
}



int delete_gen_batch_dt(const char* batch_id)
{
        int     iRet = SUCCESS;

        /* EXEC SQL WHENEVER SQLERROR GOTO delete_gen_batch_dt_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar     hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;



        /* EXEC SQL END DECLARE SECTION; */ 


	hv_batch_id.len = strlen(batch_id);
	memcpy(hv_batch_id.arr,batch_id,hv_batch_id.len);        

        /* EXEC SQL
                delete from ol_payout_api_pregen_dt
                where  oag_batch_id = :hv_batch_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "delete from ol_payout_api_pregen_dt where oag_batch_\
id = :b0 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )243;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_batch_id;
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
        if (sqlca.sqlcode < 0) goto delete_gen_batch_dt_error;
}



        return iRet;

delete_gen_batch_dt_error:
DEBUGLOG(("delete_gen_batch_dt error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )262;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}

int delete_gen_batch_hd(const char* batch_id)
{
        int     iRet = SUCCESS;

        /* EXEC SQL WHENEVER SQLERROR GOTO delete_gen_batch_hd_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar     hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;



        /* EXEC SQL END DECLARE SECTION; */ 


	hv_batch_id.len = strlen(batch_id);
	memcpy(hv_batch_id.arr,batch_id,hv_batch_id.len);        

        /* EXEC SQL
                delete from ol_payout_api_pregen_hd
                where oap_batch_id = :hv_batch_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "delete from ol_payout_api_pregen_hd where oap_batch_\
id = :b0 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )277;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_batch_id;
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
        if (sqlca.sqlcode < 0) goto delete_gen_batch_hd_error;
}



        return iRet;

delete_gen_batch_hd_error:
DEBUGLOG(("delete_gen_batch_hd error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )296;
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

        while ((c = getopt(argc,argv,"d:")) != EOF) {
                switch (c) {
                        case 'd':
                                num_of_day = atoi(optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        return SUCCESS;
}
