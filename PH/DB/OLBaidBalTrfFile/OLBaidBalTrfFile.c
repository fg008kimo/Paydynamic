
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
    "OLBaidBalTrfFile.pc"
};


static unsigned int sqlctx = 39442467;


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

 static char *sq0003 = 
"SELECT bbh_use_dummy_acct , bbh_rt_baid , bbd_seq , bbd_sr_bank_name , bbd_\
sr_bank_acct_num , bbd_sweep_out_amt , bbd_rt_bank_name , bbd_rt_bank_acct_nu\
m , bbd_create_user FROM ol_baid_bt_file_header , ol_baid_bt_file_detail WHER\
E bbh_file_id = bbd_file_id AND bbd_file_id = :b0 ORDER BY bbd_seq           \
 ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,467,0,6,168,0,0,11,11,0,1,0,2,3,0,0,1,68,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,
4,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
64,0,0,2,206,0,6,288,0,0,6,6,0,1,0,2,3,0,0,1,68,0,0,1,3,0,0,1,3,0,0,1,9,0,0,1,
9,0,0,
103,0,0,3,307,0,9,384,0,2049,1,1,0,1,0,1,68,0,0,
122,0,0,3,0,0,13,388,0,0,9,0,0,1,0,2,3,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,4,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,
173,0,0,3,0,0,15,479,0,0,0,0,0,1,0,
188,0,0,4,340,0,4,540,0,0,11,1,0,1,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
3,0,0,2,3,0,0,2,1,0,0,2,3,0,0,2,9,0,0,1,68,0,0,
247,0,0,5,119,0,4,675,0,0,3,2,0,1,0,2,9,0,0,1,68,0,0,1,1,0,0,
274,0,0,6,0,0,17,824,0,0,1,1,0,1,0,1,9,0,0,
293,0,0,6,0,0,21,825,0,0,0,0,0,1,0,
308,0,0,6,0,0,17,923,0,0,1,1,0,1,0,1,9,0,0,
327,0,0,6,0,0,21,924,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2020. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2020/12/03              [ZBL]
PRD314
 - Add GetDetailByFileId function
 - Add UpdateBTITxnId function                     2021/03/18              [ZBL]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlca.h>
#include "OLBaidBalTrfFile.h"
#include "common.h"
#include "dbutility.h"
#include "internal.h"
#include "utilitys.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char cDebug;

void OLBaidBalTrfFile(char cdebug)
{
	cDebug = cdebug;
}

int AddDetail(const hash_t *hIn)
{
	char	*csTmp;
	double	dTmp;
	int	iTmp;
	int	iRet = PD_ERR;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_detail_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		unsigned long	hv_file_id;
		int		hv_seq;
		/* varchar		hv_sender_bank_name[PD_BANK_ACCT_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_sender_bank_name;

		/* varchar		hv_sender_bank_acct_num[PD_BANK_ACCT_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_sender_bank_acct_num;

		double		hv_sweep_out_amt;
		/* varchar		hv_receiver_bank_name[PD_BANK_ACCT_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_receiver_bank_name;

		/* varchar		hv_receiver_bank_acct_num[PD_BANK_ACCT_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_receiver_bank_acct_num;

		/* varchar		hv_sweep_out_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_sweep_out_txn_id;

		/* varchar		hv_sweep_in_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_sweep_in_txn_id;

		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_file_id			= -1;
		short		ind_seq				= -1;
		short		ind_sender_bank_name		= -1;
		short		ind_sender_bank_acct_num	= -1;
		short		ind_sweep_out_amt		= -1;
		short		ind_receiver_bank_name		= -1;
		short		ind_receiver_bank_acct_num	= -1;
		short		ind_sweep_out_txn_id		= -1;
		short		ind_sweep_in_txn_id		= -1;
		short		ind_create_user			= -1;

		short		hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("AddDetail: Begin\n"));

	/* file_id */
	if (GetField_CString(hIn, "file_id", &csTmp))
	{
		hv_file_id = (unsigned long)ctol((const unsigned char*)csTmp, strlen(csTmp));
		ind_file_id = 0;

DEBUGLOG(("- file_id = [%lu]\n", hv_file_id));
	}

	/* seq */
	if (GetField_Int(hIn, "seq", &iTmp))
	{
		hv_seq = iTmp;
		ind_seq = 0;

DEBUGLOG(("- seq = [%d]\n", hv_seq));
	}

	/* sender_bank_name */
	if (GetField_CString(hIn, "sender_bank_name", &csTmp))
	{
		hv_sender_bank_name.len = strlen(csTmp);
		memcpy(hv_sender_bank_name.arr, csTmp, hv_sender_bank_name.len);
		ind_sender_bank_name = 0;

DEBUGLOG(("- sender_bank_name = [%.*s]\n", hv_sender_bank_name.len, hv_sender_bank_name.arr));
	}

	/* sender_bank_acct_num */
	if (GetField_CString(hIn, "sender_bank_acct_num", &csTmp))
	{
		hv_sender_bank_acct_num.len = strlen(csTmp);
		memcpy(hv_sender_bank_acct_num.arr, csTmp, hv_sender_bank_acct_num.len);
		ind_sender_bank_acct_num = 0;

DEBUGLOG(("- sender_bank_acct_num = [%.*s]\n", hv_sender_bank_acct_num.len, hv_sender_bank_acct_num.arr));
	}

	/* sweep_out_amt */
	if (GetField_Double(hIn, "sweep_out_amt", &dTmp))
	{
		hv_sweep_out_amt = dTmp;
		ind_sweep_out_amt = 0;

DEBUGLOG(("- sweep_out_amt = [%lf]\n", hv_sweep_out_amt));
	}

	/* receiver_bank_name */
	if (GetField_CString(hIn, "receiver_bank_name", &csTmp))
	{
		hv_receiver_bank_name.len = strlen(csTmp);
		memcpy(hv_receiver_bank_name.arr, csTmp, hv_receiver_bank_name.len);
		ind_receiver_bank_name = 0;

DEBUGLOG(("- receiver_bank_name = [%.*s]\n", hv_receiver_bank_name.len, hv_receiver_bank_name.arr));
	}

	/* receiver_bank_acct_num */
	if (GetField_CString(hIn, "receiver_bank_acct_num", &csTmp))
	{
		hv_receiver_bank_acct_num.len = strlen(csTmp);
		memcpy(hv_receiver_bank_acct_num.arr, csTmp, hv_receiver_bank_acct_num.len);
		ind_receiver_bank_acct_num = 0;

DEBUGLOG(("- receiver_bank_acct_num = [%.*s]\n", hv_receiver_bank_acct_num.len, hv_receiver_bank_acct_num.arr));
	}

	/* sweep_out_txn_id */
	if (GetField_CString(hIn, "sweep_out_txn_id", &csTmp))
	{
		hv_sweep_out_txn_id.len = strlen(csTmp);
		memcpy(hv_sweep_out_txn_id.arr, csTmp, hv_sweep_out_txn_id.len);
		ind_sweep_out_txn_id = 0;

DEBUGLOG(("- sweep_out_txn_id = [%.*s]\n", hv_sweep_out_txn_id.len, hv_sweep_out_txn_id.arr));
	}

	/* sweep_in_txn_id */
	if (GetField_CString(hIn, "sweep_in_txn_id", &csTmp))
	{
		hv_sweep_in_txn_id.len = strlen(csTmp);
		memcpy(hv_sweep_in_txn_id.arr, csTmp, hv_sweep_in_txn_id.len);
		ind_sweep_in_txn_id = 0;

DEBUGLOG(("- sweep_in_txn_id = [%.*s]\n", hv_sweep_in_txn_id.len, hv_sweep_in_txn_id.arr));
	}

	/* create_user */
	if (GetField_CString(hIn, "create_user", &csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		memcpy(hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;

DEBUGLOG(("- create_user = [%.*s]\n", hv_create_user.len, hv_create_user.arr));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_baid_bt_file_detail_ins(
				:hv_file_id:ind_file_id, 
				:hv_seq:ind_seq, 
				:hv_sender_bank_name:ind_sender_bank_name, 
				:hv_sender_bank_acct_num:ind_sender_bank_acct_num, 
				:hv_sweep_out_amt:ind_sweep_out_amt, 
				:hv_receiver_bank_name:ind_receiver_bank_name, 
				:hv_receiver_bank_acct_num:ind_receiver_bank_acct_num, 
				:hv_sweep_out_txn_id:ind_sweep_out_txn_id, 
				:hv_sweep_in_txn_id:ind_sweep_in_txn_id, 
				:hv_create_user:ind_create_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_baid_bt_file_detail_ins ( :\
hv_file_id:ind_file_id , :hv_seq:ind_seq , :hv_sender_bank_name:ind_sender_ba\
nk_name , :hv_sender_bank_acct_num:ind_sender_bank_acct_num , :hv_sweep_out_a\
mt:ind_sweep_out_amt , :hv_receiver_bank_name:ind_receiver_bank_name , :hv_re\
ceiver_bank_acct_num:ind_receiver_bank_acct_num , :hv_sweep_out_txn_id:ind_sw\
eep_out_txn_id , :hv_sweep_in_txn_id:ind_sweep_in_txn_id , :hv_create_user:in\
d_create_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_file_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_seq;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_seq;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_sender_bank_name;
 sqlstm.sqhstl[3] = (unsigned long )52;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_sender_bank_name;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_sender_bank_acct_num;
 sqlstm.sqhstl[4] = (unsigned long )52;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_sender_bank_acct_num;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_sweep_out_amt;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_sweep_out_amt;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_receiver_bank_name;
 sqlstm.sqhstl[6] = (unsigned long )52;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_receiver_bank_name;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_receiver_bank_acct_num;
 sqlstm.sqhstl[7] = (unsigned long )52;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_receiver_bank_acct_num;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_sweep_out_txn_id;
 sqlstm.sqhstl[8] = (unsigned long )18;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_sweep_out_txn_id;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_sweep_in_txn_id;
 sqlstm.sqhstl[9] = (unsigned long )18;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_sweep_in_txn_id;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[10] = (unsigned long )22;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto add_detail_error;
}



DEBUGLOG(("AddDetail: Ret = [%d]\n", hv_return_value));

	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("AddDetail: Normal Exit\n"));
		iRet = PD_OK;
	}
	else if (hv_return_value == SP_OTHER_ERR)
	{
ERRLOG("OLBaidBalTrfFile_AddDetail: SP_OTHER_ERR\n");
DEBUGLOG(("AddDetail: SP_OTHER_ERR\n"));
		iRet = PD_OTHER_ERR;
	}
	else if (hv_return_value == SP_ERR)
	{
ERRLOG("OLBaidBalTrfFile_AddDetail: SP_ERR\n");
DEBUGLOG(("AddDetail: SP_ERR\n"));
	}

	return iRet;

add_detail_error:
DEBUGLOG(("add_detail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLBaidBalTrfFile_AddDetail: SP_INTERNAL_ERR\n");
DEBUGLOG(("AddDetail: SP_INTERNAL_ERR\n"));
	return PD_ERR;
}

int AddError(const hash_t *hIn)
{
	char	*csTmp;
	int	iTmp;
	int	iRet = PD_ERR;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		unsigned long	hv_file_id;
		int		hv_seq;
		int		hv_msg_code;
		/* varchar		hv_line_content[PD_CONTENT_LEN]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_line_content;

		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_file_id		= -1;
		short		ind_seq			= -1;
		short		ind_msg_code		= -1;
		short		ind_line_content	= -1;
		short		ind_create_user		= -1;

		short		hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("AddError: Begin\n"));

	/* file_id */
	if (GetField_CString(hIn, "file_id", &csTmp))
	{
		hv_file_id = (unsigned long)ctol((const unsigned char*)csTmp, strlen(csTmp));
		ind_file_id = 0;

DEBUGLOG(("- file_id = [%lu]\n", hv_file_id));
	}

	/* seq */
	if (GetField_Int(hIn, "seq", &iTmp))
	{
		hv_seq = iTmp;
		ind_seq = 0;

DEBUGLOG(("- seq = [%d]\n", hv_seq));
	}

	/* msg_code */
	if (GetField_Int(hIn, "msg_code", &iTmp))
	{
		hv_msg_code = iTmp;
		ind_msg_code = 0;

DEBUGLOG(("- msg_code = [%d]\n", hv_msg_code));
	}

	/* line_content */
	if (GetField_CString(hIn, "line_content", &csTmp))
	{
		hv_line_content.len = strlen(csTmp);
		memcpy(hv_line_content.arr, csTmp, hv_line_content.len);
		ind_line_content = 0;

DEBUGLOG(("- line_content = [%.*s]\n", hv_line_content.len, hv_line_content.arr));
	}

	/* create_user */
	if (GetField_CString(hIn, "create_user", &csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		memcpy(hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;

DEBUGLOG(("- create_user = [%.*s]\n", hv_create_user.len, hv_create_user.arr));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_baid_bt_file_error_ins(
				:hv_file_id:ind_file_id, 
				:hv_seq:ind_seq, 
				:hv_msg_code:ind_msg_code, 
				:hv_line_content:ind_line_content, 
				:hv_create_user:ind_create_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_baid_bt_file_error_ins ( :h\
v_file_id:ind_file_id , :hv_seq:ind_seq , :hv_msg_code:ind_msg_code , :hv_lin\
e_content:ind_line_content , :hv_create_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )64;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_file_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_seq;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_seq;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_msg_code;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_msg_code;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_line_content;
 sqlstm.sqhstl[4] = (unsigned long )1026;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_line_content;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[5] = (unsigned long )22;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto add_error_error;
}



DEBUGLOG(("AddError: Ret = [%d]\n", hv_return_value));

	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("AddError: Normal Exit\n"));
		iRet = PD_OK;
	}
	else if (hv_return_value == SP_OTHER_ERR)
	{
ERRLOG("OLBaidBalTrfFile_AddError: SP_OTHER_ERR\n");
DEBUGLOG(("AddError: SP_OTHER_ERR\n"));
		iRet = PD_OTHER_ERR;
	}
	else if (hv_return_value == SP_ERR)
	{
ERRLOG("OLBaidBalTrfFile_AddError: SP_ERR\n");
DEBUGLOG(("AddError: SP_ERR\n"));
	}

	return iRet;

add_error_error:
DEBUGLOG(("add_error_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLBaidBalTrfFile_AddError: SP_INTERNAL_ERR\n");
DEBUGLOG(("AddError: SP_INTERNAL_ERR\n"));
	return PD_ERR;
}

int GetDetailByFileId(unsigned long lFileId, recordset_t *rRec)
{
	int	iCnt = 0;
	int	iRet = PD_NOT_FOUND;
	hash_t	*hRec;

	/* EXEC SQL WHENEVER SQLERROR GOTO get_detail_by_fileid_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		unsigned long	hv_file_id;

		int		v_use_dummy_acct;
		/* varchar		v_receiver_baid[PD_BAID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_receiver_baid;

		int		v_seq;
		/* varchar		v_sender_bank_name[PD_BANK_ACCT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_sender_bank_name;

		/* varchar		v_sender_bank_acct_num[PD_BANK_ACCT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_sender_bank_acct_num;

		double		v_sweep_out_amt;
		/* varchar		v_receiver_bank_name[PD_BANK_ACCT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_receiver_bank_name;

		/* varchar		v_receiver_bank_acct_num[PD_BANK_ACCT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_receiver_bank_acct_num;

		/* varchar		v_create_user[PD_USER_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_create_user;


		short		ind_use_dummy_acct		= -1;
		short		ind_receiver_baid		= -1;
		short		ind_seq				= -1;
		short		ind_sender_bank_name		= -1;
		short		ind_sender_bank_acct_num	= -1;
		short		ind_sweep_out_amt		= -1;
		short		ind_receiver_bank_name		= -1;
		short		ind_receiver_bank_acct_num	= -1;
		short		ind_create_user			= -1;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetDetailByFileId: Begin\n"));

	/* file_id */
	hv_file_id = lFileId;
DEBUGLOG(("- file_id = [%lu]\n", hv_file_id));

	/* EXEC SQL DECLARE c_cursor_getdetailbyfileid CURSOR FOR
		SELECT	bbh_use_dummy_acct, 
			bbh_rt_baid, 
			bbd_seq, 
			bbd_sr_bank_name, 
			bbd_sr_bank_acct_num, 
			bbd_sweep_out_amt, 
			bbd_rt_bank_name, 
			bbd_rt_bank_acct_num, 
			bbd_create_user 
		FROM	ol_baid_bt_file_header, 
			ol_baid_bt_file_detail 
		WHERE	bbh_file_id = bbd_file_id 
			AND bbd_file_id = :hv_file_id 
		ORDER BY bbd_seq; */ 


	/* EXEC SQL OPEN c_cursor_getdetailbyfileid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )103;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_file_id;
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
 if (sqlca.sqlcode < 0) goto get_detail_by_fileid_error;
}



	do
	{
		/* EXEC SQL FETCH c_cursor_getdetailbyfileid 
		INTO
			:v_use_dummy_acct:ind_use_dummy_acct, 
			:v_receiver_baid:ind_receiver_baid, 
			:v_seq:ind_seq, 
			:v_sender_bank_name:ind_sender_bank_name, 
			:v_sender_bank_acct_num:ind_sender_bank_acct_num, 
			:v_sweep_out_amt:ind_sweep_out_amt, 
			:v_receiver_bank_name:ind_receiver_bank_name, 
			:v_receiver_bank_acct_num:ind_receiver_bank_acct_num, 
			:v_create_user:ind_create_user; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 11;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )122;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_use_dummy_acct;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_use_dummy_acct;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_receiver_baid;
  sqlstm.sqhstl[1] = (unsigned long )23;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_receiver_baid;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_seq;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_seq;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_sender_bank_name;
  sqlstm.sqhstl[3] = (unsigned long )53;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_sender_bank_name;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_sender_bank_acct_num;
  sqlstm.sqhstl[4] = (unsigned long )53;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_sender_bank_acct_num;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_sweep_out_amt;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_sweep_out_amt;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_receiver_bank_name;
  sqlstm.sqhstl[6] = (unsigned long )53;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_receiver_bank_name;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_receiver_bank_acct_num;
  sqlstm.sqhstl[7] = (unsigned long )53;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_receiver_bank_acct_num;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_create_user;
  sqlstm.sqhstl[8] = (unsigned long )23;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_create_user;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto get_detail_by_fileid_error;
}



		if (SQLCODE == SQL_NOT_FOUND)
			break;

		hRec = (hash_t*)malloc(sizeof(hash_t));
		hash_init(hRec, 0);

		/* use_dummy_acct */
		if (ind_use_dummy_acct >= 0)
		{
DEBUGLOG(("- use_dummy_acct = [%d]\n", v_use_dummy_acct));
			PutField_Int(hRec, "use_dummy_acct", v_use_dummy_acct);
		}

		/* receiver_baid */
		if (ind_receiver_baid >= 0)
		{
			v_receiver_baid.arr[v_receiver_baid.len] = '\0';
DEBUGLOG(("- receiver_baid = [%s]\n", v_receiver_baid.arr));
			PutField_CString(hRec, "receiver_baid", (const char*)v_receiver_baid.arr);
		}

		/* seq */
		if (ind_seq >= 0)
		{
DEBUGLOG(("- [%d] seq = [%d]\n", iCnt, v_seq));
			PutField_Int(hRec, "seq", v_seq);
		}

		/* sender_bank_name */
		if (ind_sender_bank_name >= 0)
		{
			v_sender_bank_name.arr[v_sender_bank_name.len] = '\0';
DEBUGLOG(("- [%d] sender_bank_name = [%s]\n", iCnt, v_sender_bank_name.arr));
			PutField_CString(hRec, "sender_bank_name", (const char*)v_sender_bank_name.arr);
		}

		/* sender_bank_acct_num */
		if (ind_sender_bank_acct_num >= 0)
		{
			v_sender_bank_acct_num.arr[v_sender_bank_acct_num.len] = '\0';
DEBUGLOG(("- [%d] sender_bank_acct_num = [%s]\n", iCnt, v_sender_bank_acct_num.arr));
			PutField_CString(hRec, "sender_bank_acct_num", (const char*)v_sender_bank_acct_num.arr);
		}

		/* sweep_out_amt */
		if (ind_sweep_out_amt >= 0)
		{
DEBUGLOG(("- [%d] sweep_out_amt = [%lf]\n", iCnt, v_sweep_out_amt));
			PutField_Double(hRec, "sweep_out_amt", v_sweep_out_amt);
		}

		/* receiver_bank_name */
		if (ind_receiver_bank_name >= 0)
		{
			v_receiver_bank_name.arr[v_receiver_bank_name.len] = '\0';
DEBUGLOG(("- [%d] receiver_bank_name = [%s]\n", iCnt, v_receiver_bank_name.arr));
			PutField_CString(hRec, "receiver_bank_name", (const char*)v_receiver_bank_name.arr);
		}

		/* receiver_bank_acct_num */
		if (ind_receiver_bank_acct_num >= 0)
		{
			v_receiver_bank_acct_num.arr[v_receiver_bank_acct_num.len] = '\0';
DEBUGLOG(("- [%d] receiver_bank_acct_num = [%s]\n", iCnt, v_receiver_bank_acct_num.arr));
			PutField_CString(hRec, "receiver_bank_acct_num", (const char*)v_receiver_bank_acct_num.arr);
		}

		/* create_user */
		if (ind_create_user >= 0)
		{
			v_create_user.arr[v_create_user.len] = '\0';
DEBUGLOG(("- [%d] create_user = [%s]\n", iCnt, v_create_user.arr));
			PutField_CString(hRec, "create_user", (const char*)v_create_user.arr);
		}

		iCnt++;
		RecordSet_Add(rRec, hRec);
	} while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getdetailbyfileid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )173;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto get_detail_by_fileid_error;
}



	if (iCnt > 0)
	{
DEBUGLOG(("GetDetailByFileId [%d] records found! Normal Exit\n", iCnt));
		iRet = PD_FOUND;
	}
	else
	{
DEBUGLOG(("GetDetailByFileId no records found! Normal Exit\n"));
	}

	return iRet;

get_detail_by_fileid_error:
DEBUGLOG(("get_detail_by_fileid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int GetHeaderByFileId(unsigned long lFileId, hash_t *hOut)
{
	int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO get_header_by_fileid_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		unsigned long	hv_file_id;

		/* varchar		v_sender_client_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_sender_client_id;

		int		v_use_dummy_acct;
		/* varchar		v_receiver_baid[PD_BAID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_receiver_baid;

		/* varchar		v_raw_filename[PD_UPLOAD_FILENAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_raw_filename;

		/* varchar		v_convert_filename[PD_UPLOAD_FILENAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_convert_filename;

		int		v_total_count;
		int		v_accept_count;
		char		v_status;
		int		v_msg_code;
		/* varchar		v_create_user[PD_USER_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_create_user;


		short		ind_sender_client_id	= -1;
		short		ind_use_dummy_acct	= -1;
		short		ind_receiver_baid	= -1;
		short		ind_raw_filename	= -1;
		short		ind_convert_filename	= -1;
		short		ind_total_count		= -1;
		short		ind_accept_count	= -1;
		short		ind_status		= -1;
		short		ind_msg_code		= -1;
		short		ind_create_user		= -1;
		
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetHeaderByFileId: Begin\n"));

	/* file_id */
	hv_file_id = lFileId;
DEBUGLOG(("- file_id = [%lu]\n", hv_file_id));

	/* EXEC SQL 
		SELECT	bbh_sr_client_id, 
			bbh_use_dummy_acct, 
			bbh_rt_baid, 
			bbh_raw_filename, 
			bbh_convert_filename, 
			bbh_total_count, 
			bbh_accept_count, 
			bbh_status, 
			bbh_msg_code, 
			bbh_create_user
		INTO	:v_sender_client_id:ind_sender_client_id, 
			:v_use_dummy_acct:ind_use_dummy_acct, 
			:v_receiver_baid:ind_receiver_baid, 
			:v_raw_filename:ind_raw_filename, 
			:v_convert_filename:ind_convert_filename, 
			:v_total_count:ind_total_count, 
			:v_accept_count:ind_accept_count, 
			:v_status:ind_status, 
			:v_msg_code:ind_msg_code, 
			:v_create_user:ind_create_user
		FROM	ol_baid_bt_file_header 
		WHERE	bbh_file_id = :hv_file_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select bbh_sr_client_id , bbh_use_dummy_acct , bbh_rt_baid \
, bbh_raw_filename , bbh_convert_filename , bbh_total_count , bbh_accept_coun\
t , bbh_status , bbh_msg_code , bbh_create_user INTO :b0:b1 , :b2:b3 , :b4:b5\
 , :b6:b7 , :b8:b9 , :b10:b11 , :b12:b13 , :b14:b15 , :b16:b17 , :b18:b19 FRO\
M ol_baid_bt_file_header WHERE bbh_file_id = :b20 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )188;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_sender_client_id;
 sqlstm.sqhstl[0] = (unsigned long )13;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_sender_client_id;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_use_dummy_acct;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_use_dummy_acct;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_receiver_baid;
 sqlstm.sqhstl[2] = (unsigned long )23;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_receiver_baid;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&v_raw_filename;
 sqlstm.sqhstl[3] = (unsigned long )103;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_raw_filename;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&v_convert_filename;
 sqlstm.sqhstl[4] = (unsigned long )103;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_convert_filename;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&v_total_count;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_total_count;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&v_accept_count;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_accept_count;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&v_status;
 sqlstm.sqhstl[7] = (unsigned long )1;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_status;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&v_msg_code;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_msg_code;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&v_create_user;
 sqlstm.sqhstl[9] = (unsigned long )23;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_create_user;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto get_header_by_fileid_error;
}



	/* sender_client_id */
	if (ind_sender_client_id >= 0)
	{
		v_sender_client_id.arr[v_sender_client_id.len] = '\0';
DEBUGLOG(("- sender_client_id = [%s]\n", v_sender_client_id.arr));
		PutField_CString(hOut, "sender_client_id", (const char *)v_sender_client_id.arr);
	}

	/* use_dummy_acct */
	if (ind_use_dummy_acct >= 0)
	{
DEBUGLOG(("- use_dummy_acct = [%d]\n", v_use_dummy_acct));
		PutField_Int(hOut, "use_dummy_acct", v_use_dummy_acct);
	}

	/* receiver_baid */
	if (ind_receiver_baid >= 0)
	{
		v_receiver_baid.arr[v_receiver_baid.len] = '\0';
DEBUGLOG(("- receiver_baid = [%s]\n", v_receiver_baid.arr));
		PutField_CString(hOut, "receiver_baid", (const char *)v_receiver_baid.arr);
	}

	/* raw_filename */
	if (ind_raw_filename >= 0)
	{
		v_raw_filename.arr[v_raw_filename.len] = '\0';
DEBUGLOG(("- raw_filename = [%s]\n", v_raw_filename.arr));
		PutField_CString(hOut, "raw_filename", (const char *)v_raw_filename.arr);
	}

	/* convert_filename */
	if (ind_convert_filename >= 0)
	{
		v_convert_filename.arr[v_convert_filename.len] = '\0';
DEBUGLOG(("- convert_filename = [%s]\n", v_convert_filename.arr));
		PutField_CString(hOut, "convert_filename", (const char *)v_convert_filename.arr);
	}

	/* total_count */
	if (ind_total_count >= 0)
	{
DEBUGLOG(("- total_count = [%d]\n", v_total_count));
		PutField_Int(hOut, "total_count", v_total_count);
	}

	/* accept_count */
	if (ind_accept_count >= 0)
	{
DEBUGLOG(("- accept_count = [%d]\n", v_accept_count));
		PutField_Int(hOut, "accept_count", v_accept_count);
	}

	/* status */
	if (ind_status >= 0)
	{
DEBUGLOG(("- status = [%c]\n", v_status));
		PutField_Char(hOut, "status", v_status);
	}

	/* msg_code */
	if (ind_msg_code >= 0)
	{
DEBUGLOG(("- msg_code = [%d]\n", v_msg_code));
		PutField_Int(hOut, "msg_code", v_msg_code);
	}

	/* create_user */
	if (ind_create_user >= 0)
	{
		v_create_user.arr[v_create_user.len] = '\0';
DEBUGLOG(("- create_user = [%s]\n", v_create_user.arr));
		PutField_CString(hOut, "create_user", (const char *)v_create_user.arr);
	}
	
DEBUGLOG(("GetHeaderByFileId: Normal Exit\n"));
	return iRet;

get_header_by_fileid_error:
DEBUGLOG(("get_header_by_fileid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int MatchHeaderStatusForUpdate(unsigned long lFileId, const char cStatus)
{
	int iRet = PD_NOT_FOUND;

	/* EXEC SQL WHENEVER SQLERROR GOTO match_header_status_for_update_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		unsigned long	hv_file_id;
		char		hv_status;

		/* varchar		v_create_user[PD_USER_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_create_user;


		short		ind_create_user = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("MatchHeaderStatusForUpdate: Begin\n"));

	/* file_id */
	hv_file_id = lFileId;
DEBUGLOG(("- file_id = [%lu]\n", hv_file_id));

	/* status */
	hv_status = cStatus;
DEBUGLOG(("- status = [%c]\n", hv_status));

	/* EXEC SQL 
		SELECT	bbh_create_user 
		INTO	:v_create_user:ind_create_user 
		FROM	ol_baid_bt_file_header 
		WHERE	bbh_file_id = :hv_file_id AND 
			bbh_status = :hv_status 
		FOR UPDATE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select bbh_create_user INTO :b0:b1 FROM ol_baid_bt_file_hea\
der WHERE bbh_file_id = :b2 AND bbh_status = :b3 FOR UPDATE ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )247;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_create_user;
 sqlstm.sqhstl[0] = (unsigned long )23;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_create_user;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
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
 if (sqlca.sqlcode < 0) goto match_header_status_for_update_error;
}



	/* create_user */
	if (ind_create_user >= 0)
	{
DEBUGLOG(("MatchHeaderStatusForUpdate: Normal Exit\n"));
		iRet = PD_FOUND;
	}
	else
	{
DEBUGLOG(("MatchHeaderStatusForUpdate: Normal Exit, Not Found\n"));
	}

	return iRet;

match_header_status_for_update_error:
DEBUGLOG(("match_header_status_for_update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int UpdateHeader(const hash_t *hIn)
{
	char	cTmp;
	char	*csBuf;
	char	*csFileId;
	char	*csTmp;
	int	iTmp;
	int	iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_header_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_dynstmt[PD_TMP_MSG_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[2048]; } hv_dynstmt;

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateHeader: Begin\n"));

	csBuf = (char*)malloc(PD_TMP_BUF_LEN);

	strcpy((char*)hv_dynstmt.arr, "UPDATE ol_baid_bt_file_header SET bbh_update_timestamp = SYSDATE");
	hv_dynstmt.len = strlen((const char *)hv_dynstmt.arr);

	/* file_id */
	if (GetField_CString(hIn, "file_id", &csFileId))
	{
DEBUGLOG(("- file_id = [%s]\n", csFileId));
	}
	else
	{
		FREE_ME(csBuf);
DEBUGLOG(("UpdateHeader: file_id not found\n"));

		return PD_ERR;
	}

	/* receiver_baid */
	if (GetField_CString(hIn, "receiver_baid", &csTmp))
	{
		strcat((char *)hv_dynstmt.arr, ", bbh_rt_baid = '");
		strcat((char *)hv_dynstmt.arr, csTmp);
		strcat((char *)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char *)hv_dynstmt.arr);

DEBUGLOG(("- receiver_baid = [%s]\n", csTmp));
	}

	/* convert_filename */
	if (GetField_CString(hIn, "convert_filename", &csTmp))
	{
		strcat((char*)hv_dynstmt.arr, ", bbh_convert_filename = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- convert_filename = [%s]\n", csTmp));
	}

	/* total_count */
	if (GetField_Int(hIn, "total_count", &iTmp))
	{
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", bbh_total_count = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- total_count = [%d]\n", iTmp));
	}

	/* accept_count */
	if (GetField_Int(hIn, "accept_count", &iTmp))
	{
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", bbh_accept_count = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- accept_count = [%d]\n", iTmp));
	}

	/* status */
	if (GetField_Char(hIn, "status", &cTmp))
	{
		sprintf(csBuf, "%c", cTmp);
		strcat((char*)hv_dynstmt.arr, ", bbh_status = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- status = [%c]\n", cTmp));
	}

	/* msg_code */
	if (GetField_Int(hIn, "msg_code", &iTmp))
	{
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", bbh_msg_code = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- msg_code = [%d]\n", iTmp));
	}

	/* update_user */
	if (GetField_CString(hIn, "update_user", &csTmp))
	{
		strcat((char*)hv_dynstmt.arr, ", bbh_update_user = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- update_user = [%s]\n", csTmp));
	}

	/* file_id */
	strcat((char*)hv_dynstmt.arr, " WHERE bbh_file_id = ");
	strcat((char*)hv_dynstmt.arr, csFileId);
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- SQL = [%.*s]\n", hv_dynstmt.len, hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )274;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
 sqlstm.sqhstl[0] = (unsigned long )2050;
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
 if (sqlca.sqlcode < 0) goto update_header_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )293;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto update_header_error;
}



	FREE_ME(csBuf);

DEBUGLOG(("UpdateHeader: Normal Exit\n"));
	return iRet;

update_header_error:
DEBUGLOG(("update_header_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLBaidBalTrfFile_UpdateHeader: SP_INTERNAL_ERR\n");
DEBUGLOG(("UpdateHeader: SP_INTERNAL_ERR\n"));
	return PD_ERR;
}

int UpdateBTITxnId(const hash_t *hIn)
{
	char	*csBuf;
	char	*csFileId;
	char	*csTmp;
	int	iSeq;
	int	iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_btitxnid_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_dynstmt[PD_TMP_MSG_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[2048]; } hv_dynstmt;

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateBTITxnId: Begin\n"));

	csBuf = (char*)malloc(PD_TMP_BUF_LEN);

	strcpy((char *)hv_dynstmt.arr, "UPDATE ol_baid_bt_file_detail SET bbd_update_timestamp = SYSDATE");

	/* file_id */
	if (GetField_CString(hIn, "file_id", &csFileId))
	{
DEBUGLOG(("- file_id = [%s]\n", csFileId));
	}
	else
	{
		FREE_ME(csBuf);
DEBUGLOG(("UpdateBTITxnId: file_id not found\n"));

		return PD_ERR;
	}

	/* seq */
	if (GetField_Int(hIn, "seq", &iSeq))
	{
DEBUGLOG(("- seq = [%d]\n", iSeq));
	}
	else
	{
		FREE_ME(csBuf);
DEBUGLOG(("UpdateBTITxnId: seq not found\n"));

		return PD_ERR;
	}

	/* sweep_out_txn_id */
	if (GetField_CString(hIn, "sweep_out_txn_id", &csTmp))
	{
		strcat((char*)hv_dynstmt.arr, ", bbd_sweep_out_txn_id = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char *)hv_dynstmt.arr);

DEBUGLOG(("- sweep_out_txn_id = [%s]\n", csTmp));
	}

	/* sweep_in_txn_id */
	if (GetField_CString(hIn, "sweep_in_txn_id", &csTmp))
	{
		strcat((char*)hv_dynstmt.arr, ", bbd_sweep_in_txn_id = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char *)hv_dynstmt.arr);

DEBUGLOG(("- sweep_in_txn_id = [%s]\n", csTmp));
	}

	/* file_id */
	strcat((char*)hv_dynstmt.arr, " WHERE bbd_file_id = ");
	strcat((char*)hv_dynstmt.arr, csFileId);
	hv_dynstmt.len = strlen((const char *)hv_dynstmt.arr);

	/* seq */
	sprintf(csBuf, "%d", iSeq);
	strcat((char*)hv_dynstmt.arr, " AND bbd_seq = ");
	strcat((char*)hv_dynstmt.arr, csBuf);
	hv_dynstmt.len = strlen((const char *)hv_dynstmt.arr);

DEBUGLOG(("- SQL = [%.*s]\n", hv_dynstmt.len, hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )308;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
 sqlstm.sqhstl[0] = (unsigned long )2050;
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
 if (sqlca.sqlcode < 0) goto update_btitxnid_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )327;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto update_btitxnid_error;
}



	FREE_ME(csBuf);

DEBUGLOG(("UpdateBTITxnId: Normal Exit\n"));
	return iRet;

update_btitxnid_error:
DEBUGLOG(("update_btitxnid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLBaidBalTrfFile_UpdateBTITxnId: SP_INTERNAL_ERR\n");
DEBUGLOG(("UpdateBTITxnId: SP_INTERNAL_ERR\n"));
	return PD_ERR;
}
