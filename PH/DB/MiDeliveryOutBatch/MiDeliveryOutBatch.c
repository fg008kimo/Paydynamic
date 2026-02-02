
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
    "MiDeliveryOutBatch.pc"
};


static unsigned int sqlctx = 155911627;


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
"select dob_seq , dob_txn_amt , dob_deliver_date , dob_amtdiff_reason , dob_\
amtdiff_ccy , dob_amtdiff_amt from mi_delivery_out_batch where dob_batch_id =\
 :b0 order by dob_seq            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,185,0,9,78,0,2049,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,13,80,0,0,6,0,0,1,0,2,3,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,
0,
63,0,0,1,0,0,15,139,0,0,0,0,0,1,0,
78,0,0,1,0,0,15,154,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2018/10/29              Philip Yu
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "MiDeliveryOutBatch.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "internal.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


static char    cDebug;

void MiDeliveryOutBatch(char    cdebug)
{
	cDebug = cdebug;
}


int GetDetailByBatchId(const char* csBatchId, recordset_t* myRec)
{
	char	csTag[PD_TAG_LEN+1];
	hash_t	*myHash;         
	int 	iDtlCnt = 0;

                
	/* EXEC SQL WHENEVER SQLERROR GOTO getDetailByBatchId_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_batch_id[PD_MI_BATCH_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;

                
		int	v_seq;
		double	v_txn_amt;
		/* varchar	v_deliver_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_deliver_date;

		/* varchar	v_amtdiff_reason[PD_MI_AR_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_amtdiff_reason;

		/* varchar	v_amtdiff_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_amtdiff_ccy;

		double	v_amtdiff_amt;

		short	ind_seq = -1;
		short	ind_txn_amt = -1;
		short	ind_deliver_date = -1;
		short	ind_amtdiff_reason = -1;
		short	ind_amtdiff_ccy = -1;
		short	ind_amtdiff_amt = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_batch_id.len = strlen(csBatchId);
	memcpy(hv_batch_id.arr,csBatchId,hv_batch_id.len);
DEBUGLOG(("GetDetailByBatchId batch_id = [%s]\n",csBatchId));

	/* EXEC SQL DECLARE c_cursor_getDetailByBatchId CURSOR FOR
		select	dob_seq,
			dob_txn_amt,
			dob_deliver_date,
			dob_amtdiff_reason,
			dob_amtdiff_ccy,
			dob_amtdiff_amt
		from mi_delivery_out_batch
		where dob_batch_id = :hv_batch_id
		order by dob_seq
		; */ 


	/* EXEC SQL OPEN c_cursor_getDetailByBatchId; */ 

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
 if (sqlca.sqlcode < 0) goto getDetailByBatchId_error;
}


		do{
			/* EXEC SQL FETCH c_cursor_getDetailByBatchId
			INTO
				:v_seq:ind_seq,
				:v_txn_amt:ind_txn_amt,
				:v_deliver_date:ind_deliver_date,
				:v_amtdiff_reason:ind_amtdiff_reason,
				:v_amtdiff_ccy:ind_amtdiff_ccy,
				:v_amtdiff_amt:ind_amtdiff_amt; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 6;
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
   sqlstm.sqhstv[0] = (unsigned char  *)&v_seq;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_seq;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_amt;
   sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_txn_amt;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_deliver_date;
   sqlstm.sqhstl[2] = (unsigned long )11;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_deliver_date;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_amtdiff_reason;
   sqlstm.sqhstl[3] = (unsigned long )13;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_amtdiff_reason;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_amtdiff_ccy;
   sqlstm.sqhstl[4] = (unsigned long )6;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_amtdiff_ccy;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_amtdiff_amt;
   sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_amtdiff_amt;
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
   if (sqlca.sqlcode < 0) goto getDetailByBatchId_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
			        break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

/* rec_seq */
			if(ind_seq>=0){
DEBUGLOG(("GetDetailByBatchId seq= [%d]\n",v_seq));

/* txnamt */
				if(ind_txn_amt>=0){
                   			PutField_Double(myHash,"txnamt",v_txn_amt);
DEBUGLOG(("GetDetailByBatchId txnamt= [txnamt] [%f]\n",v_txn_amt));
				}

/* deliver_date */
				if(ind_deliver_date>=0){
                   			v_deliver_date.arr[v_deliver_date.len]='\0';
                   			PutField_CString(myHash,"deliver_date",(const char*)v_deliver_date.arr);
DEBUGLOG(("GetDetailByBatchId deliver_date= [deliver_date] [%s]\n",v_deliver_date.arr));
				}

/* amtdiff_reason */
				if(ind_amtdiff_reason>=0){
					v_amtdiff_reason.arr[v_amtdiff_reason.len]='\0';
					PutField_CString(myHash,"amtdiff_reason",(const char*)v_amtdiff_reason.arr);
DEBUGLOG(("GetDetailByBatchId amtdiff_reason= [amtdiff_reason] [%s]\n",v_amtdiff_reason.arr));
				}

/* amtdiff_ccy */
				if(ind_amtdiff_ccy>=0){
                   			v_amtdiff_ccy.arr[v_amtdiff_ccy.len]='\0';
                   			PutField_CString(myHash,"amtdiff_ccy",(const char*)v_amtdiff_ccy.arr);
DEBUGLOG(("GetDetailByBatchId amtdiff_ccy= [amtdiff_ccy] [%s]\n",v_amtdiff_ccy.arr));
				}

/* amtdiff_amt */
				if(ind_amtdiff_amt>=0){
                   			PutField_Double(myHash, "amtdiff_amt", v_amtdiff_amt);
DEBUGLOG(("GetDetailByBatchId amtdiff_amt= [amtdiff_amt] [%f]\n",v_amtdiff_amt));
				}
			}

			iDtlCnt++;
			RecordSet_Add(myRec,myHash);

        }while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getDetailByBatchId; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )63;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getDetailByBatchId_error;
}



	if (iDtlCnt == 0) {
DEBUGLOG(("GetDetailByBatchId NO Record found, Normal Exit\n"));
		return PD_NOT_FOUND;
	} else {
DEBUGLOG(("GetDetailByBatchId [%d] record found, Normal Exit\n",iDtlCnt));
		return  PD_OK;
	}

getDetailByBatchId_error:
DEBUGLOG(("getDetailByBatchId_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MiDeliveryOutBatc_GetDetailByBatchId: SP_INTERNAL_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getDetailByBatchId; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
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


	return PD_ERR;
}

