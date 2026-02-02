
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
    "OLPayoutApiBatchHD.pc"
};


static unsigned int sqlctx = 163251451;


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

 static char *sq0002 = 
"select oah_txn_code , oah_status , oah_ret_code from ol_payout_api_batch_hd\
 where oah_batch_id = :b0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,201,0,6,96,0,0,6,6,0,1,0,2,3,0,0,1,68,0,0,1,9,0,0,1,1,0,0,1,3,0,0,1,9,
0,0,
44,0,0,2,112,0,9,169,0,2049,1,1,0,1,0,1,68,0,0,
63,0,0,2,0,0,13,171,0,0,3,0,0,1,0,2,9,0,0,2,1,0,0,2,3,0,0,
90,0,0,2,0,0,15,207,0,0,0,0,0,1,0,
105,0,0,2,0,0,15,217,0,0,0,0,0,1,0,
120,0,0,3,63,0,4,430,0,0,1,0,0,1,0,2,68,0,0,
139,0,0,4,0,0,17,525,0,0,1,1,0,1,0,1,9,0,0,
158,0,0,4,0,0,21,526,0,0,0,0,0,1,0,
173,0,0,5,129,0,4,623,0,0,4,3,0,1,0,2,9,0,0,1,9,0,0,1,9,0,0,1,1,0,0,
204,0,0,6,147,0,4,672,0,0,4,3,0,1,0,2,9,0,0,1,9,0,0,1,9,0,0,1,1,0,0,
235,0,0,7,124,0,4,716,0,0,3,2,0,1,0,2,9,0,0,1,9,0,0,1,1,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2017/03/13              Dirk Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "OLPayoutApiBatchHD.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "internal.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void OLPayoutApiBatchHD(char    cdebug)
{
        cDebug = cdebug;
}


int Add(const hash_t *hRec)
{
	char            *csTmp;
	char		cTmp;
        int             iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                unsigned long   hv_batch_id;
		/* varchar		hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

		char		hv_status;
		int		hv_ret_code;
		/* varchar		hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;

                
                short           ind_batch_id= -1;
                short           ind_txn_code= -1;
                short           ind_status= -1;
                short           ind_ret_code= -1;
                short           ind_add_user= -1;
                
                short           hv_return_value;
                /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

//batch_id
        if(GetField_CString(hRec,"batch_id",&csTmp)){
                hv_batch_id = ctol((const unsigned char*)csTmp,strlen(csTmp));
                ind_batch_id= 0;
DEBUGLOG(("Add:batch_id= [%ld]\n",hv_batch_id));
        }

//txn_code
        if(GetField_CString(hRec,"txn_code",&csTmp)){
                hv_txn_code.len = strlen(csTmp);
                memcpy(hv_txn_code.arr, csTmp, hv_txn_code.len);
                ind_txn_code= 0;
DEBUGLOG(("Add:txn_code= [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));
        }

//status
        if(GetField_Char(hRec,"status",&cTmp)){
                hv_status = cTmp;
                ind_status= 0;
DEBUGLOG(("Add:status= [%.c]\n",hv_status));
        }

//ret_code
        if(GetField_Int(hRec,"ret_code",&iTmp)){
                hv_ret_code = iTmp;
                ind_ret_code= 0;
DEBUGLOG(("Add:ret_code= [%d]\n",hv_ret_code));
        }

//user
        if(GetField_CString(hRec,"add_user",&csTmp)){
                hv_add_user.len = strlen(csTmp);
                memcpy(hv_add_user.arr, csTmp, hv_add_user.len);
                ind_add_user= 0;
DEBUGLOG(("Add:add_user= [%.*s]\n",hv_add_user.len,hv_add_user.arr));
        }

	/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_ol_payout_api_batch_hd_add(
                                        :hv_batch_id:ind_batch_id,
                                        :hv_txn_code:ind_txn_code,
                                        :hv_status:ind_status,
					:hv_ret_code:ind_ret_code,
                                        :hv_add_user:ind_add_user);
                END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_payout_api_batch_hd_add ( :\
hv_batch_id:ind_batch_id , :hv_txn_code:ind_txn_code , :hv_status:ind_status \
, :hv_ret_code:ind_ret_code , :hv_add_user:ind_add_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_batch_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_code;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_txn_code;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[3] = (unsigned long )1;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_status;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_ret_code;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_ret_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_add_user;
 sqlstm.sqhstl[5] = (unsigned long )22;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_add_user;
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
 if (sqlca.sqlcode < 0) goto add_error;
}


                
DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("Add:Normal Exit\n"));
                return PD_OK;
        }
                
        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("OLPayoutApiBatchHD_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("OLPayoutApiBatchHD_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPayoutApiBatchHD_Add: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}


int GetHeader(const hash_t* hRec,recordset_t* myRec)
{
	hash_t *myHash;
	char*	csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO getheader_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		unsigned long	hv_batch_id;

		/* varchar		v_txn_code[PD_TXN_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

		char		v_status;
		int        	v_ret_code;

		short		ind_txn_code = -1;
		short           ind_status= -1;
                short           ind_ret_code= -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	if(GetField_CString(hRec,"batch_id",&csTmp)){
		hv_batch_id= (unsigned long)ctol((const unsigned char*)csTmp,strlen(csTmp));
DEBUGLOG(("GetHeader batch_id = [%ld]\n",hv_batch_id));
	}

	/* EXEC SQL DECLARE c_cursor_getheader CURSOR FOR
		select
			oah_txn_code,
			oah_status,
			oah_ret_code
		from	ol_payout_api_batch_hd
		where	oah_batch_id =:hv_batch_id; */ 


	/* EXEC SQL OPEN  c_cursor_getheader; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )44;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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
 if (sqlca.sqlcode < 0) goto getheader_error;
}


	do{
		/* EXEC SQL FETCH c_cursor_getheader
		INTO
			:v_txn_code:ind_txn_code,
                        :v_status:ind_status,
			:v_ret_code:ind_ret_code; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )63;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_code;
  sqlstm.sqhstl[0] = (unsigned long )6;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_txn_code;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[1] = (unsigned long )1;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_status;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_ret_code;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_ret_code;
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
  if (sqlca.sqlcode < 0) goto getheader_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

//txn_code
		if(ind_txn_code>=0){
			v_txn_code.arr[v_txn_code.len]='\0';
			PutField_CString(myHash,"txn_code",(const char*)v_txn_code.arr);
DEBUGLOG(("GetHeader txn_code = [%s]\n",v_txn_code.arr));
		}

//status
                if(ind_status>=0){
                        PutField_Char(myHash,"status",v_status);
DEBUGLOG(("GetHeader status = [%c]\n",v_status));
                }

//ret_code
                if(ind_ret_code>=0){
                        PutField_Int(myHash,"ret_code",v_ret_code);
DEBUGLOG(("GetHeader ret_code = [%d]\n",v_ret_code));
        	}

		RecordSet_Add(myRec,myHash);

	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getheader; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )90;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getheader_error;
}



DEBUGLOG(("GetHeader Normal Exit\n"));
	return  PD_OK;

getheader_error:
DEBUGLOG(("getheader_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPayoutApiBatchHD_Get: SP_INTERNAL_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getheader; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
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


	return PD_ERR;

}


/*
int GetNextFileId(unsigned long *lFileId)
{
	int iRet = PD_OK;
	*lFileId = 0l;

	EXEC SQL WHENEVER SQLERROR GOTO GetNextFileId_error;
        EXEC SQL WHENEVER NOTFOUND CONTINUE;

        EXEC SQL BEGIN DECLARE SECTION;
		unsigned long	v_file_id;

                short           ind_file_id = -1;

        EXEC SQL END DECLARE SECTION;

        EXEC SQL SELECT max(ofh_file_id)
                INTO    :v_file_id:ind_file_id
                FROM    ol_payout_generated_file_hd;

        if(ind_file_id>=0){
DEBUGLOG(("GetNextFileId Found\n"));
                *lFileId = v_file_id+1;
        }
        else {
DEBUGLOG(("GetNextFileId Start by 1\n"));
                *lFileId = 1;
        }

	return iRet;

GetNextFileId_error:
DEBUGLOG(("GetNextFileId_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        EXEC SQL WHENEVER SQLERROR CONTINUE;
        return PD_ERR;
}
*/


/*
int GetPreGenHeader(const int iStatus, recordset_t* myRec)
{
	hash_t *myHash;

	EXEC SQL WHENEVER SQLERROR GOTO getpreheader_error;
	EXEC SQL WHENEVER NOTFOUND CONTINUE;

	EXEC SQL BEGIN DECLARE SECTION;
		int		hv_status;

		varchar		v_file_id[PD_TXN_SEQ_LEN+1];
		varchar		v_filename[PD_FILENAME_LEN+1];
		varchar		v_file_date[PD_DATE_LEN+1];
		varchar         v_psp_id[PD_PSP_ID_LEN+1];
		varchar         v_bank_code[PD_BANK_CODE_LEN+1];
                varchar         v_payout_ccy[PD_CCY_ID_LEN+1];
                double          v_total_txn_amt;
		int		v_txn_count;
		int		v_seq_num;

		short		ind_file_id = -1;
		short		ind_filename = -1;
		short           ind_file_date= -1;
                short           ind_psp_id= -1;
                short           ind_bank_code= -1;
                short           ind_payout_ccy= -1;
                short           ind_total_txn_amt= -1;
                short           ind_txn_count= -1;
                short           ind_seq_num= -1;


	EXEC SQL END DECLARE SECTION;

	//hv_status = PD_PAYOUTFILE_PRE_GENERATED;
	hv_status = iStatus;
	

	EXEC SQL DECLARE c_cursor_getpreheader CURSOR FOR
		select  ofh_file_id,
			ofh_seq_num,
			ofh_filename,
			ofh_file_date,
			ofh_file_pid,
			ofh_file_bank_code,
                        ofh_txn_count,
                        ofh_total_txn_amt,
			ofh_ccy_id
		from	ol_payout_generated_file_hd
		where	ofh_status=:hv_status
		for update;

	EXEC SQL OPEN  c_cursor_getpreheader;
	do{
		EXEC SQL FETCH c_cursor_getpreheader
		INTO	:v_file_id:ind_file_id,
			:v_seq_num:ind_seq_num,
			:v_filename:ind_filename,
			:v_file_date:ind_file_date,
                        :v_psp_id:ind_psp_id,
                        :v_bank_code:ind_bank_code,
                        :v_txn_count:ind_txn_count,
                        :v_total_txn_amt:ind_total_txn_amt,
                        :v_payout_ccy:ind_payout_ccy;

		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

//file_id
		if(ind_file_id>=0){
			v_file_id.arr[v_file_id.len]='\0';
			PutField_CString(myHash,"file_id",(const char*)v_file_id.arr);
DEBUGLOG(("GetPreGenHeader file_id = [%s]\n",v_file_id.arr));
		}

//seq_num
                if(ind_seq_num>=0){
                        PutField_Int(myHash,"seq_num",v_seq_num);
DEBUGLOG(("GetPreGenHeader seq_num = [%d]\n",v_seq_num));
        	}

//filename
		if(ind_filename>=0){
			v_filename.arr[v_filename.len]='\0';
			PutField_CString(myHash,"filename",(const char*)v_filename.arr);
DEBUGLOG(("GetPreGenHeader filename = [%s]\n",v_filename.arr));
		}

//file_date
                if(ind_file_date>=0){
                        v_file_date.arr[v_file_date.len]='\0';
                        PutField_CString(myHash,"file_date",(const char*)v_file_date.arr);
DEBUGLOG(("GetPreGenHeader file_date = [%s]\n",v_file_date.arr));
                }

//psp_id
                if(ind_psp_id>=0){
                        v_psp_id.arr[v_psp_id.len]='\0';
                        PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetPreGenHeader psp_id= [%s]\n",v_psp_id.arr));
                }

//bank_code
                if(ind_bank_code>=0){
                        v_bank_code.arr[v_bank_code.len]='\0';
                        PutField_CString(myHash,"file_bank_code",(const char*)v_bank_code.arr);
DEBUGLOG(("GetPreGenHeader bank_code= [%s]\n",v_bank_code.arr));
                }

//payout_currency
                if(ind_payout_ccy>=0){
                        v_payout_ccy.arr[v_payout_ccy.len]='\0';
                        PutField_CString(myHash,"payout_ccy",(const char*)v_payout_ccy.arr);
DEBUGLOG(("GetPreGenHeader payout_ccy= [%s]\n",v_payout_ccy.arr));
                }

//total_txn_amt
                if(ind_total_txn_amt>=0){
                        PutField_Double(myHash,"total_txn_amt",v_total_txn_amt);
DEBUGLOG(("GetPreGenHeader total_txn_amt = [%lf]\n",v_total_txn_amt));
        	}

//txn_count
                if(ind_txn_count>=0){
                        PutField_Int(myHash,"txn_count",v_txn_count);
DEBUGLOG(("GetPreGenHeader txn_count = [%d]\n",v_txn_count));
        	}


		RecordSet_Add(myRec,myHash);

	}while(PD_TRUE);

	EXEC SQL CLOSE c_cursor_getpreheader;

DEBUGLOG(("GetPreGenHeader Normal Exit\n"));
	return  PD_OK;

getpreheader_error:
DEBUGLOG(("getpreheader_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPayoutApiBatchHD_GetPreGen: SP_INTERNAL_ERR\n");
	EXEC SQL WHENEVER SQLERROR CONTINUE;
	EXEC SQL CLOSE c_cursor_getpreheader;
	return PD_ERR;

}
*/



int GetNextSeq()
{
	int iRet = PD_ERR;

	/* EXEC SQL WHENEVER SQLERROR GOTO GetNextSeq_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		unsigned long	hv_next_seq;
                short		ind_next_seq = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        /* EXEC SQL
		SELECT	ol_payout_api_batch_seq.nextval
                INTO    :hv_next_seq:ind_next_seq
                FROM    dual; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select ol_payout_api_batch_seq . nextval INTO :b0:b1\
 FROM dual ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )120;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_next_seq;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_next_seq;
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
        if (sqlca.sqlcode < 0) goto GetNextSeq_error;
}



        if(ind_next_seq>=0){
DEBUGLOG(("GetNextSeq Found\n"));
                return hv_next_seq;
        }
        else {
DEBUGLOG(("GetNextSeq ERROR\n"));
        }

	return iRet;

GetNextSeq_error:
DEBUGLOG(("GetNextSeq_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}



int Update(const hash_t *hRec)
{
        char*   csBuf;
        char*   csBatchId;
	char	cTmp;
	int	iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("Update: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update ol_payout_api_batch_hd set oah_update_timestamp = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        if(GetField_CString(hRec,"batch_id",&csBatchId)){
DEBUGLOG(("Update:batch_id = [%s]\n",csBatchId));
	}
	else{
		FREE_ME(csBuf);
DEBUGLOG(("Update batch_id not found\n"));
        	return INT_ERR;
	}

	if(GetField_CString(hRec,"txn_code",&csBuf)){
DEBUGLOG(("Update: txn_code = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oah_txn_code= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Char(hRec,"status",&cTmp)){
DEBUGLOG(("Update: status = [%c]\n",cTmp));
                sprintf(csBuf,"%c",cTmp);
                strcat((char*)hv_dynstmt.arr, ",oah_status = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_Int(hRec,"ret_code",&iTmp)){
DEBUGLOG(("Update: return_code = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",oah_ret_code = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	if(GetField_CString(hRec,"update_user",&csBuf)){
DEBUGLOG(("Update: update_user = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",oah_update_user = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	strcat((char*)hv_dynstmt.arr, " WHERE oah_batch_id= ");
        strcat((char*)hv_dynstmt.arr, csBatchId);
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));


        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )139;
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
        if (sqlca.sqlcode < 0) goto update_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )158;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_error;
}



        FREE_ME(csBuf);

DEBUGLOG(("UpdateStatus Normal Exit\n"));
        return PD_OK;

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPayoutApiBatchHD_Update: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_INTERNAL_ERR;
}


/*
int Delete(const unsigned char* file_id)
{
        EXEC SQL WHENEVER SQLERROR GOTO delete_error;
        EXEC SQL WHENEVER NOTFOUND CONTINUE;

        EXEC SQL BEGIN DECLARE SECTION;
                varchar hv_file_id[PD_TXN_SEQ_LEN];

                short   hv_return_value;
        EXEC SQL END DECLARE SECTION;

        hv_file_id.len = strlen((const char*)file_id);
        memcpy(hv_file_id.arr,file_id,hv_file_id.len);
DEBUGLOG(("Delete: file_id = [%.*s]\n",hv_file_id.len,hv_file_id.arr));

        EXEC SQL EXECUTE
            BEGIN

                :hv_return_value := sp_ol_payout_gen_hd_delete(
                                :hv_file_id);

            END;
        END-EXEC;


DEBUGLOG(("Delete:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("Delete:Normal Exit\n"));
                return PD_OK;
        }
	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("OLPayoutApiBatchHD_Delete: SP_OTHER_ERR\n");
DEBUGLOG(("Delete: SP_OTHER_ERR\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("OLPayoutApiBatchHD_Delete: SP_ERR\n");
DEBUGLOG(("Delete: SP_ERR\n"));
                return PD_ERR;
        }

delete_error:
DEBUGLOG(("delete_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPayoutApiBatchHD_Delete: SP_INTERNAL_ERR TxnAbort\n");
        EXEC SQL WHENEVER SQLERROR CONTINUE;
        return PD_ERR;

}
*/

int MatchBatchStatus(const char* csBatchId,
		const char* csTxnCode,
		const char cStatus)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO MatchBatchStatus_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;

		/* varchar hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

		char hv_status;

		/* varchar v_batch_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_batch_id;

		short ind_batch_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_batch_id.len = strlen(csBatchId);
	memcpy(hv_batch_id.arr, csBatchId, hv_batch_id.len);
DEBUGLOG(("MatchBatchStatus batch_id = [%.*s]\n", hv_batch_id.len, hv_batch_id.arr));

	hv_txn_code.len = strlen(csTxnCode);
	memcpy(hv_txn_code.arr, csTxnCode, hv_txn_code.len);
DEBUGLOG(("MatchBatchStatus txn_code = [%.*s]\n", hv_txn_code.len, hv_txn_code.arr));

	hv_status = cStatus;
DEBUGLOG(("MatchBatchStatus status = [%c]\n", hv_status));

	/* EXEC SQL SELECT oah_batch_id
		INTO :v_batch_id:ind_batch_id
		FROM ol_payout_api_batch_hd
		WHERE oah_batch_id = :hv_batch_id
		AND oah_txn_code = :hv_txn_code
		AND oah_status = :hv_status; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select oah_batch_id INTO :b0:b1 FROM ol_payout_api_batch_hd\
 WHERE oah_batch_id = :b2 AND oah_txn_code = :b3 AND oah_status = :b4 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )173;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
 sqlstm.sqhstl[0] = (unsigned long )19;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_batch_id;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
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
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[3] = (unsigned long )1;
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
 if (sqlca.sqlcode < 0) goto MatchBatchStatus_error;
}



	if (ind_batch_id >= 0) {
DEBUGLOG(("MatchBatchStatus Found\n"));
		return PD_FOUND;
	} else {
DEBUGLOG(("MatchBatchStatus Not Found\n"));
		return PD_NOT_FOUND;
	}

MatchBatchStatus_error:
DEBUGLOG(("MatchBatchStatus_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int MatchBatchStatus_ForUpdate(const char* csBatchId,
		const char* csTxnCode,
		const char cStatus)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO MatchBatchStatus_ForUpdate_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;

		/* varchar hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

		char hv_status;

		/* varchar v_batch_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_batch_id;

		short ind_batch_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_batch_id.len = strlen(csBatchId);
	memcpy(hv_batch_id.arr, csBatchId, hv_batch_id.len);
DEBUGLOG(("MatchBatchStatus_ForUpdate batch_id = [%.*s]\n", hv_batch_id.len, hv_batch_id.arr));

	hv_txn_code.len = strlen(csTxnCode);
	memcpy(hv_txn_code.arr, csTxnCode, hv_txn_code.len);
DEBUGLOG(("MatchBatchStatus_ForUpdate txn_code = [%.*s]\n", hv_txn_code.len, hv_txn_code.arr));

	hv_status = cStatus;
DEBUGLOG(("MatchBatchStatus_ForUpdate status = [%c]\n", hv_status));

	/* EXEC SQL SELECT oah_batch_id
		INTO :v_batch_id:ind_batch_id
		FROM ol_payout_api_batch_hd
		WHERE oah_batch_id = :hv_batch_id
		AND oah_txn_code = :hv_txn_code
		AND oah_status = :hv_status
		FOR UPDATE NOWAIT; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select oah_batch_id INTO :b0:b1 FROM ol_payout_api_batch_hd\
 WHERE oah_batch_id = :b2 AND oah_txn_code = :b3 AND oah_status = :b4 FOR UPD\
ATE NOWAIT ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )204;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
 sqlstm.sqhstl[0] = (unsigned long )19;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_batch_id;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
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
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[3] = (unsigned long )1;
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
 if (sqlca.sqlcode < 0) goto MatchBatchStatus_ForUpdate_error;
}



	if (ind_batch_id >= 0) {
DEBUGLOG(("MatchBatchStatus_ForUpdate Found\n"));
		return PD_FOUND;
	} else {
DEBUGLOG(("MatchBatchStatus_ForUpdate Not Found\n"));
		return PD_NOT_FOUND;
	}

MatchBatchStatus_ForUpdate_error:
DEBUGLOG(("MatchBatchStatus_ForUpdate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int MatchBatchStatus_ForUpdate_ByBatchId(const char* csBatchId,
                const char cStatus)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO MatchStatus_ForUpdate_ByBatchId_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;

                char hv_status;

                /* varchar v_batch_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_batch_id;

                short ind_batch_id = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_batch_id.len = strlen(csBatchId);
        memcpy(hv_batch_id.arr, csBatchId, hv_batch_id.len);
DEBUGLOG(("MatchBatchStatus_ForUpdate_ByBatchId batch_id = [%.*s]\n", hv_batch_id.len, hv_batch_id.arr));

        hv_status = cStatus;
DEBUGLOG(("MatchBatchStatus_ForUpdate_ByBatchId status = [%c]\n", hv_status));

        /* EXEC SQL SELECT oah_batch_id
                INTO :v_batch_id:ind_batch_id
                FROM ol_payout_api_batch_hd
                WHERE oah_batch_id = :hv_batch_id
                AND oah_status = :hv_status
                FOR UPDATE NOWAIT; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select oah_batch_id INTO :b0:b1 FROM ol_payout_api_b\
atch_hd WHERE oah_batch_id = :b2 AND oah_status = :b3 FOR UPDATE NOWAIT ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )235;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
        sqlstm.sqhstl[0] = (unsigned long )19;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_batch_id;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[1] = (unsigned long )18;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[2] = (unsigned long )1;
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
        if (sqlca.sqlcode < 0) goto MatchStatus_ForUpdate_ByBatchId_error;
}



        if (ind_batch_id >= 0) {
DEBUGLOG(("MatchBatchStatus_ForUpdate_ByBatchId Found\n"));
                return PD_FOUND;
        } else {
DEBUGLOG(("MatchBatchStatus_ForUpdate_ByBatchId Not Found\n"));
                return PD_NOT_FOUND;
        }

MatchStatus_ForUpdate_ByBatchId_error:
DEBUGLOG(("MatchStatus_ForUpdate_ByBatchId error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

