
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
    "OLPayoutReturn.pc"
};


static unsigned int sqlctx = 10207563;


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
   unsigned char  *sqhstv[8];
   unsigned long  sqhstl[8];
            int   sqhsts[8];
            short *sqindv[8];
            int   sqinds[8];
   unsigned long  sqharm[8];
   unsigned long  *sqharc[8];
   unsigned short  sqadto[8];
   unsigned short  sqtdso[8];
} sqlstm = {12,8};

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
"SELECT txn_id , txn_code , txn_status , txn_ar_ind , txn_recon_status FROM \
table ( sp_ol_payout_rtn_get_list ( :b0 ) ) order by txn_id            ";

 static char *sq0004 = 
"SELECT otp_tracking_txn_id , oth_txn_id , obt_txn_id , olsd_stat_txn_id , o\
lsd_txn_amount , olsd_int_bank_code , olsd_bank_acct_num , obtr_batch_id FROM\
 ol_txn_psp_detail , ol_txn_header , ol_stmt_txn_relation , ol_baid_txn , ol_\
statement_detail , ol_bank_acct_id , ol_batch_txn_relation WHERE otp_grp_trac\
king_txn_id = :b0 AND otp_txn_id = oth_txn_id AND oth_status = 'C' AND oth_ar\
_ind = 'A' AND oth_recon_status = 'R' AND NOT EXISTS ( SELECT 1 FROM txn_code\
 WHERE tc_code = oth_txn_code AND ( tc_ofl_is_offset = 1 OR tc_ofl_is_void = \
1 ) ) AND oth_txn_id = ostp_txn_id AND ostp_stmt_txn_id = obt_txn_id AND obt_\
stat_txn_id = olsd_stat_txn_id AND obt_baid = obai_baid AND obai_category = '\
ITL_GEN' AND obtr_batch_type in ( 'G' , 'C' , 'I' ) AND obtr_txn_level in ( '\
T' , 'S' ) AND oth_txn_id = obtr_txn_id ORDER BY obtr_batch_id , obtr_relatio\
n_timestamp            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,159,0,6,63,0,0,5,5,0,1,0,2,3,0,0,1,9,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
40,0,0,2,146,0,9,147,0,2049,1,1,0,1,0,1,9,0,0,
59,0,0,2,0,0,13,149,0,0,5,0,0,1,0,2,9,0,0,2,9,0,0,2,1,0,0,2,1,0,0,2,1,0,0,
94,0,0,2,0,0,15,195,0,0,0,0,0,1,0,
109,0,0,2,0,0,15,211,0,0,0,0,0,1,0,
124,0,0,3,79,0,6,235,0,0,2,2,0,1,0,2,3,0,0,1,9,0,0,
147,0,0,4,868,0,9,327,0,2049,1,1,0,1,0,1,9,0,0,
166,0,0,4,0,0,13,329,0,0,8,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,
213,0,0,4,0,0,15,398,0,0,0,0,0,1,0,
228,0,0,4,0,0,15,415,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/01/27              Virginia Yun
Add Function CheckPayoutReconMulti                 2015/06/24              Virginia Yun
Add Function GetReconPattern                       2015/07/20              David Wong
SQL Tuning for GetReconPattern                     2018/06/19              Virginia Yun
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "OLPayoutReturn.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char    cDebug;

void OLPayoutReturn(char    cdebug)
{
        cDebug = cdebug;
}


int CheckPayoutRtnAllow(const char* csTxnSeq,
			hash_t	*hRls)
{
	int	iRet = PD_ERR;


        /* EXEC SQL WHENEVER SQLERROR GOTO chkpayoutrtn_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		short	hv_return_value;

		/* varchar	hv_txn_seq[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_seq;


		int	v_recon_cnt;
		int	v_unrecon_cnt;
		int	v_level;

		short	ind_recon_cnt = -1;
		short	ind_unrecon_cnt = -1;
		short	ind_level = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_seq.len = strlen((const char*)csTxnSeq);
        memcpy(hv_txn_seq.arr, csTxnSeq, hv_txn_seq.len);
DEBUGLOG(("CheckPayoutRtnAllow: txn_Seq = [%.*s]\n", hv_txn_seq.len, hv_txn_seq.arr)); 

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_payout_rtn_allow_chk(:hv_txn_seq,
									:v_recon_cnt:ind_recon_cnt,
									:v_unrecon_cnt:ind_unrecon_cnt,
									:v_level:ind_level);

		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_payout_rtn_allow_chk ( :hv_\
txn_seq , :v_recon_cnt:ind_recon_cnt , :v_unrecon_cnt:ind_unrecon_cnt , :v_le\
vel:ind_level ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_seq;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_recon_cnt;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_recon_cnt;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&v_unrecon_cnt;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_unrecon_cnt;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&v_level;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_level;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto chkpayoutrtn_error;
}

	

        if (hv_return_value == SP_OK) {
DEBUGLOG(("CheckPayoutRtnAllow:: Allow To PayoutRtn\n"));

		if (ind_recon_cnt >= 0) {
DEBUGLOG(("CheckPayoutRtnAllow:: recon_cnt [%d]\n", v_recon_cnt));
			PutField_Int(hRls, "recon_cnt", v_recon_cnt);
		}


		if (ind_unrecon_cnt >= 0) {
DEBUGLOG(("CheckPayoutRtnAllow:: unrecon_cnt [%d]\n", v_unrecon_cnt));
			PutField_Int(hRls, "unrecon_cnt", v_unrecon_cnt);
		}

		if (ind_level >= 0) {
DEBUGLOG(("CheckPayoutRtnAllow:: level [%d]\n", v_level));
			PutField_Int(hRls, "level", v_level);
		}

		iRet = PD_OK;
	}
	else{
DEBUGLOG(("CheckPayoutRtnAllow:: Not Allow To PayoutRtn\n"));
	}

DEBUGLOG(("CheckPayoutRtnAllow PayoutRtn iRet = [%d]\n",iRet));

	return iRet;

chkpayoutrtn_error:
DEBUGLOG(("chkpayoutrtn_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}

int GetPayoutRtnList(const char* csTxnSeq,
			recordset_t *myRec)
{
	hash_t	*myHash;
	int	iCnt = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO getpayoutrtnlist_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_txn_seq[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_seq;


		/* varchar	v_txn_seq[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_seq;

		/* varchar v_txn_code[PD_TXN_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

		char	v_status;
		char	v_ar_ind;
		char	v_recon_status;

		short	ind_txn_seq = -1;
		short	ind_txn_code = -1;
		short	ind_status = -1;
		short	ind_ar_ind = -1;
		short	ind_recon_status = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_seq.len = strlen(csTxnSeq);
	memcpy(hv_txn_seq.arr, csTxnSeq, hv_txn_seq.len);

	/* EXEC SQL DECLARE c_cursor_get_payoutrtnlist CURSOR FOR
		SELECT txn_id,
                       txn_code,
                       txn_status,
                       txn_ar_ind,
		       txn_recon_status
                FROM   table(sp_ol_payout_rtn_get_list(:hv_txn_seq))
                order by txn_id; */ 


	/* EXEC SQL OPEN c_cursor_get_payoutrtnlist; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )40;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_txn_seq;
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
 if (sqlca.sqlcode < 0) goto getpayoutrtnlist_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_get_payoutrtnlist
		INTO	:v_txn_seq:ind_txn_seq,
			:v_txn_code:ind_txn_code,
			:v_status:ind_status,
			:v_ar_ind:ind_ar_ind,
			:v_recon_status:ind_recon_status; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 5;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )59;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_seq;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_txn_seq;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_code;
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_txn_code;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[2] = (unsigned long )1;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_status;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_ar_ind;
  sqlstm.sqhstl[3] = (unsigned long )1;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_ar_ind;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_recon_status;
  sqlstm.sqhstl[4] = (unsigned long )1;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_recon_status;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto getpayoutrtnlist_error;
}


		
		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

		if (ind_txn_seq >= 0) {
			v_txn_seq.arr[v_txn_seq.len] ='\0';
			PutField_CString(myHash,"txn_seq",(const char*)v_txn_seq.arr);
DEBUGLOG(("GetPayoutRtnList txn_seq = [%s]\n",v_txn_seq.arr));
		}

		if (ind_txn_code >= 0) {
			v_txn_code.arr[v_txn_code.len] ='\0';
			PutField_CString(myHash,"txn_code",(const char*)v_txn_code.arr);
DEBUGLOG(("GetPayoutRtnList txn_code = [%s]\n",v_txn_code.arr));
		}

		if (ind_status >= 0) {
			 PutField_Char(myHash,"status",v_status);
DEBUGLOG(("GetPayoutRtnList status = [%c]\n",v_status));
		}

		if (ind_ar_ind >= 0) {
			 PutField_Char(myHash,"ar_ind",v_ar_ind);
DEBUGLOG(("GetPayoutRtnList ar_ind = [%c]\n",v_ar_ind));
		}

		if (ind_recon_status >= 0) {
			 PutField_Char(myHash,"recon_status",v_recon_status);
DEBUGLOG(("GetPayoutRtnList recon_status = [%c]\n",v_recon_status));
		}

		RecordSet_Add(myRec, myHash);
	} while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_get_payoutrtnlist; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )94;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getpayoutrtnlist_error;
}




	if (iCnt > 0) {
DEBUGLOG(("GetPayoutRtnList Normal Exit\n"));
		return PD_OK;
	} else {
DEBUGLOG(("GetPayoutRtnList Normal Exit\n"));
		return PD_ERR;
	}

getpayoutrtnlist_error:
DEBUGLOG(("getpayoutrtnlist_error code %d\n", sqlca.sqlcode));
ERRLOG("OLPayoutReturn::Getpayoutrtnlist_error code %d\n", sqlca.sqlcode);
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_get_payoutrtnlist; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
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


        return PD_ERR;

}
			

int CheckPayoutReconMulti(const char* csTxnSeq)
{
	int     iRet = PD_ERR;

	/* EXEC SQL WHENEVER SQLERROR GOTO chkpayoutreconmulti_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		short   hv_return_value;

		/* varchar hv_txn_seq[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_seq;


	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_seq.len = strlen((const char*)csTxnSeq);
	memcpy(hv_txn_seq.arr, csTxnSeq, hv_txn_seq.len);
DEBUGLOG(("CheckPayoutReconMulti: txn_Seq = [%.*s]\n", hv_txn_seq.len, hv_txn_seq.arr));

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_payout_rtn_rc_multi_chk(:hv_txn_seq);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_payout_rtn_rc_multi_chk ( :\
hv_txn_seq ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )124;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_seq;
 sqlstm.sqhstl[1] = (unsigned long )18;
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
 if (sqlca.sqlcode < 0) goto chkpayoutreconmulti_error;
}



	if (hv_return_value == SP_OK) {
DEBUGLOG(("CheckPayoutReconMulti:: Allow To PayoutRtn\n"));
		iRet = PD_OK;
	}
	else{
DEBUGLOG(("CheckPayoutReconMulti:: Not Allow To PayoutRtn\n"));
	}

DEBUGLOG(("CheckPayoutReconMulti iRet = [%d]\n",iRet));

	return iRet;

chkpayoutreconmulti_error:
DEBUGLOG(("chkpayoutreconmulti_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPayoutReturn::chkpayoutreconmulti_error code %d\n", sqlca.sqlcode);
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int GetReconPattern(hash_t *hTxn, recordset_t *myRec)
{
	hash_t *myHash;
	int iCnt = 0;
	char *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO getreconpattern_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_merch_txn_seq[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_merch_txn_seq;


		/* varchar v_tracking_txn_seq[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_tracking_txn_seq;

		/* varchar	v_txn_seq[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_seq;

		/* varchar	v_baid_txn_seq[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_baid_txn_seq;

		/* varchar v_stmt_txn_seq[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_stmt_txn_seq;

		double	v_txn_amt;
		/* varchar	v_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

		/* varchar v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

		/* varchar v_batch_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_batch_id;


		short	ind_tracking_txn_seq = -1;
		short	ind_txn_seq = -1;
		short	ind_baid_txn_seq = -1;
		short	ind_stmt_txn_seq = -1;
		short	ind_txn_amt = -1;
		short	ind_bank_code = -1;
		short	ind_bank_acct_num = -1;
		short	ind_batch_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hTxn, "upload_txn_id", &csTmp)) {
		hv_merch_txn_seq.len = strlen(csTmp);
		memcpy(hv_merch_txn_seq.arr, csTmp, hv_merch_txn_seq.len);
DEBUGLOG(("GetReconPattern:: merch_txn_seq = [%.*s]\n", hv_merch_txn_seq.len, hv_merch_txn_seq.arr));
	}

	/* EXEC SQL DECLARE c_cursor_get_recon_pattern CURSOR FOR
		SELECT	otp_tracking_txn_id, oth_txn_id, obt_txn_id, olsd_stat_txn_id, olsd_txn_amount, olsd_int_bank_code, olsd_bank_acct_num, obtr_batch_id
		FROM	ol_txn_psp_detail,
			ol_txn_header,
			ol_stmt_txn_relation,
			ol_baid_txn,
			ol_statement_detail,
			ol_bank_acct_id,
			ol_batch_txn_relation
		WHERE otp_grp_tracking_txn_id = :hv_merch_txn_seq
		AND otp_txn_id = oth_txn_id
		AND oth_status = 'C'
		AND oth_ar_ind = 'A'
		AND oth_recon_status = 'R'
		AND NOT EXISTS
			(SELECT 1
			 FROM txn_code
			 WHERE tc_code = oth_txn_code
			 AND (tc_ofl_is_offset = 1 OR tc_ofl_is_void = 1))
		AND oth_txn_id = ostp_txn_id
		AND ostp_stmt_txn_id = obt_txn_id
		AND obt_stat_txn_id = olsd_stat_txn_id
		AND obt_baid = obai_baid
		AND obai_category = 'ITL_GEN'
		AND obtr_batch_type in ('G','C','I')
		AND obtr_txn_level in ('T', 'S')
		AND oth_txn_id = obtr_txn_id
		ORDER BY obtr_batch_id, obtr_relation_timestamp; */ 


	/* EXEC SQL OPEN c_cursor_get_recon_pattern; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0004;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )147;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_merch_txn_seq;
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
 if (sqlca.sqlcode < 0) goto getreconpattern_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_get_recon_pattern
			INTO	:v_tracking_txn_seq:ind_tracking_txn_seq,
				:v_txn_seq:ind_txn_seq,
				:v_baid_txn_seq:ind_baid_txn_seq,
				:v_stmt_txn_seq:ind_stmt_txn_seq,
				:v_txn_amt:ind_txn_amt,
				:v_bank_code:ind_bank_code,
				:v_bank_acct_num:ind_bank_acct_num,
				:v_batch_id:ind_batch_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 8;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )166;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_tracking_txn_seq;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_tracking_txn_seq;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_seq;
  sqlstm.sqhstl[1] = (unsigned long )19;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_txn_seq;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_baid_txn_seq;
  sqlstm.sqhstl[2] = (unsigned long )19;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_baid_txn_seq;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_stmt_txn_seq;
  sqlstm.sqhstl[3] = (unsigned long )19;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_stmt_txn_seq;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_txn_amt;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_txn_amt;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_bank_code;
  sqlstm.sqhstl[5] = (unsigned long )13;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_bank_code;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_bank_acct_num;
  sqlstm.sqhstl[6] = (unsigned long )53;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_bank_acct_num;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_batch_id;
  sqlstm.sqhstl[7] = (unsigned long )19;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_batch_id;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto getreconpattern_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash, 0);

		if (ind_tracking_txn_seq >= 0) {
			v_tracking_txn_seq.arr[v_tracking_txn_seq.len] = '\0';
			PutField_CString(myHash, "tracking_txn_seq", (const char*)v_tracking_txn_seq.arr);
DEBUGLOG(("GetReconPattern:: tracking_txn_seq[%d] = [%s]\n", iCnt, v_tracking_txn_seq.arr));
		}

		if (ind_txn_seq >= 0) {
			v_txn_seq.arr[v_txn_seq.len] = '\0';
			PutField_CString(myHash, "txn_seq", (const char*)v_txn_seq.arr);
DEBUGLOG(("GetReconPattern:: txn_seq[%d] = [%s]\n", iCnt, v_txn_seq.arr));
		}

		if (ind_baid_txn_seq >= 0) {
			v_baid_txn_seq.arr[v_baid_txn_seq.len] = '\0';
			PutField_CString(myHash, "baid_txn_seq", (const char*)v_baid_txn_seq.arr);
DEBUGLOG(("GetReconPattern:: baid_txn_seq[%d] = [%s]\n", iCnt, v_baid_txn_seq.arr));
		}

		if (ind_stmt_txn_seq >= 0) {
			v_stmt_txn_seq.arr[v_stmt_txn_seq.len] = '\0';
			PutField_CString(myHash, "stmt_txn_seq", (const char*)v_stmt_txn_seq.arr);
DEBUGLOG(("GetReconPattern:: stmt_txn_seq[%d] = [%s]\n", iCnt, v_stmt_txn_seq.arr));
		}

		if (ind_txn_amt >= 0) {
			PutField_Double(myHash, "txn_amt", v_txn_amt);
DEBUGLOG(("GetReconPattern:: txn_amt[%d] = [%lf]\n", iCnt, v_txn_amt));
                }

		if (ind_bank_code >= 0) {
			v_bank_code.arr[v_bank_code.len] = '\0';
			PutField_CString(myHash, "bank_code", (const char*)v_bank_code.arr);
DEBUGLOG(("GetReconPattern:: bank_code[%d] = [%s]\n", iCnt, v_bank_code.arr));
		}

		if (ind_bank_acct_num >= 0) {
			v_bank_acct_num.arr[v_bank_acct_num.len] = '\0';
			PutField_CString(myHash, "bank_acct_num", (const char*)v_bank_acct_num.arr);
DEBUGLOG(("GetReconPattern:: bank_acct_num[%d] = [%s]\n", iCnt, v_bank_acct_num.arr));
		}

		if (ind_batch_id >= 0) {
			v_batch_id.arr[v_batch_id.len] = '\0';
			PutField_CString(myHash, "batch_id", (const char*)v_batch_id.arr);
DEBUGLOG(("GetReconPattern:: batch_id[%d] = [%s]\n", iCnt, v_batch_id.arr));
		}

		RecordSet_Add(myRec, myHash);
	} while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_get_recon_pattern; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )213;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getreconpattern_error;
}



	PutField_Int(hTxn, "recon_pair_cnt", iCnt);

	if (iCnt > 0) {
DEBUGLOG(("GetReconPattern:: Normal Exit, return OK\n"));
		return PD_OK;
	} else {
DEBUGLOG(("GetReconPattern:: Normal Exit, return ERR\n"));
		return PD_ERR;
	}

getreconpattern_error:
DEBUGLOG(("getreconpattern_error code %d\n", sqlca.sqlcode));
ERRLOG("OLPayoutReturn::getreconpattern_error code %d\n", sqlca.sqlcode);
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_get_recon_pattern; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
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


	return PD_ERR;
}

