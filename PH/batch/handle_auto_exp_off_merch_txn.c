
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
           char  filnam[33];
};
static struct sqlcxp sqlfpn =
{
    32,
    "handle_auto_exp_off_merch_txn.pc"
};


static unsigned int sqlctx = 119759563;


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
   unsigned char  *sqhstv[4];
   unsigned long  sqhstl[4];
            int   sqhsts[4];
            short *sqindv[4];
            int   sqinds[4];
   unsigned long  sqharm[4];
   unsigned long  *sqharc[4];
   unsigned short  sqadto[4];
   unsigned short  sqtdso[4];
} sqlstm = {12,4};

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
"SELECT md_merchant_id , oth_txn_id , md_txn_auto_expired_days , md_txn_auto\
_expired_mins FROM ol_txn_header , ol_merch_detail WHERE ( md_txn_auto_expire\
d_days != 0 OR md_txn_auto_expired_mins != 0 ) AND oth_merchant_id = md_merch\
ant_id AND oth_txn_code = :b0 AND oth_status = :b1 AND oth_ar_ind is null AND\
 oth_create_timestamp < sysdate - ( md_txn_auto_expired_days + md_txn_auto_ex\
pired_mins / ( 60 * 24 ) ) ORDER BY md_merchant_id , oth_txn_id            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,458,0,9,195,0,2049,2,2,0,1,0,1,9,0,0,1,1,0,0,
28,0,0,1,0,0,13,198,0,0,4,0,0,1,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,
59,0,0,1,0,0,15,242,0,0,0,0,0,1,0,
74,0,0,1,0,0,15,252,0,0,0,0,0,1,0,
89,0,0,2,0,0,32,253,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2014. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/02/28              Virginia Yun
Add handling of deposit match pair                 2014/04/16              David Wong
Handle sub_status requirement                      2014/04/24              Virginia Yun
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
#include "dates.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define LOCK_FAILURE    99999

char    cDebug = 'Y';
int	avai_po_percentage = 0;

OBJPTR(DB);
OBJPTR(BO);

int parse_arg(int argc,char **argv);
int process_main();
int get_expired_list(recordset_t* myRec);
int get_txn_list(const char* csMerchantId, int iTxnAutoExpDays, int iTxnAutoExpMins, recordset_t *rRecordSet);
int process_txn(const char *csMerchantID, const char *csTxnSeq);


int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}

int batch_proc(int argc, char* argv[])
{
        int     iRet;

	iRet = parse_arg(argc,argv);
               
        if (iRet != SUCCESS) {
       // 	printf("usage:  -d cutoff_date\n");
                return (iRet);
        }

	iRet = process_main();

DEBUGLOG(("iRet = [%d]\n",iRet));

	return iRet;


}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


int process_main()
{
	int iRet = SUCCESS;

	hash_t *hRec;

	char	*csMerchantID;
	char	*csTxnSeq;
	int	iRecNo;
	int	iTmpRet;

	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));

	recordset_init(rRecordSet,0);

DEBUGLOG(("process_main\n"));

	iRet = get_expired_list(rRecordSet);

	if (iRet == SUCCESS) {

DEBUGLOG(("prepare process update\n")); 
		hRec = RecordSet_GetFirst(rRecordSet);
		while (hRec) {
DEBUGLOG(("===process update ===\n"));

			if (GetField_Int(hRec, "rec_no", &iRecNo)) {
DEBUGLOG(("process_main rec_no [%d]\n", iRecNo));
			}
			
			if (GetField_CString(hRec, "merchant_id", &csMerchantID)) {
DEBUGLOG(("process_main merchant_id [%s]\n", csMerchantID));
			}

			if (GetField_CString(hRec, "txn_seq", &csTxnSeq)) {
DEBUGLOG(("process_main txn_seq [%s]\n", csTxnSeq));
			}

			// Lock Record and Update
			iTmpRet = process_txn(csMerchantID, csTxnSeq);
			if (iTmpRet == LOCK_FAILURE) {
				iRet = FAILURE;
				break;
			}

			hRec = RecordSet_GetNext(rRecordSet);
		}
	}

        RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);

	return iRet;
}


int get_expired_list(recordset_t* myRec)
{
        int     iRet = SUCCESS;

	int	iCnt = 0;

	hash_t *myHash;

        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));

DEBUGLOG(("get_expired_list\n"));
        /* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

                char    hv_status;

                /* varchar v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

                int     v_txn_auto_exp_days;
                int     v_txn_auto_exp_mins;

                short   ind_merchant_id = -1;
		short	ind_txn_id = -1;
                short   ind_txn_auto_exp_days = -1;
                short   ind_txn_auto_exp_mins = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("get_expired_list\n"));

        hv_txn_code.len = strlen(PD_INITIAL_OLN_TXN_CODE);
        memcpy(hv_txn_code.arr, PD_INITIAL_OLN_TXN_CODE, hv_txn_code.len);
DEBUGLOG(("get_expired_list txn_code [%.*s]\n", hv_txn_code.len, hv_txn_code.arr));

        hv_status = PD_TO_PSP;
DEBUGLOG(("get_expired_list status [%c]\n", hv_status));


        /* EXEC SQL DECLARE c_cursor_get_list CURSOR FOR
		SELECT md_merchant_id, 
                       oth_txn_id, 
                       md_txn_auto_expired_days, 
                       md_txn_auto_expired_mins
		FROM ol_txn_header, ol_merch_detail
		WHERE  (md_txn_auto_expired_days != 0
			OR
			md_txn_auto_expired_mins != 0
		       )
		AND   oth_merchant_id = md_merchant_id
		AND   oth_txn_code = :hv_txn_code
		AND oth_status = :hv_status
		AND oth_ar_ind is null
		AND oth_create_timestamp < sysdate - (md_txn_auto_expired_days + md_txn_auto_expired_mins/(60*24))
		ORDER BY md_merchant_id, oth_txn_id; */ 


        /* EXEC SQL OPEN c_cursor_get_list; */ 

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
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_txn_code;
        sqlstm.sqhstl[0] = (unsigned long )5;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[1] = (unsigned long )1;
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

                /* EXEC SQL FETCH c_cursor_get_list
                INTO
                        v_merchant_id:ind_merchant_id,
			v_txn_id:ind_txn_id,
                        v_txn_auto_exp_days:ind_txn_auto_exp_days,
                        v_txn_auto_exp_mins:ind_txn_auto_exp_mins; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 4;
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
                sqlstm.sqhstv[0] = (unsigned char  *)&v_merchant_id;
                sqlstm.sqhstl[0] = (unsigned long )18;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_merchant_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_id;
                sqlstm.sqhstl[1] = (unsigned long )19;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_txn_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_auto_exp_days;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_txn_auto_exp_days;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_auto_exp_mins;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_txn_auto_exp_mins;
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
                if (sqlca.sqlcode < 0) goto sql_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }


		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash, 0);

		iCnt++;
		PutField_Int(myHash, "rec_no", iCnt);
DEBUGLOG(("get_expired_list rec_no = [%d]\n", iCnt));

                if (ind_merchant_id >= 0) {
                        v_merchant_id.arr[v_merchant_id.len] = '\0';
			PutField_CString(myHash, "merchant_id", (const char *)v_merchant_id.arr);
DEBUGLOG(("get_expired_list merchant_id = [%s]\n", v_merchant_id.arr));
                }

		if (ind_txn_id >= 0) {
                        v_txn_id.arr[v_txn_id.len] = '\0';
			PutField_CString(myHash, "txn_seq", (const char *)v_txn_id.arr);
DEBUGLOG(("get_expired_list txn_id = [%s]\n", v_txn_id.arr));
		}

                if (ind_txn_auto_exp_days >= 0) {
			PutField_Int(myHash, "txn_auto_exp_days", v_txn_auto_exp_days);
DEBUGLOG(("get_expired_list txn_auto_exp_days = [%d]\n", v_txn_auto_exp_days));
                }

                if (ind_txn_auto_exp_mins >= 0) {
			PutField_Int(myHash, "txn_auto_exp_days", v_txn_auto_exp_days);
DEBUGLOG(("get_expired_list txn_auto_exp_mins = [%d]\n", v_txn_auto_exp_mins));
                }

		RecordSet_Add(myRec, myHash);
	} while (PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_get_list; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )59;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto sql_error;
}



	return	iRet;

sql_error:
    DEBUGLOG(("process_main error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    ERRLOG("handle_auto_exp_off_merch_txn::process_main sql error %d\n", sqlca.sqlcode);

    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_get_list; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )74;
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
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )89;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;

}

int process_txn(const char *csMerchantID, const char *csTxnSeq)
{
	int	iRet = SUCCESS;

	hash_t *hRec;
	recordset_t* myRec;

        hash_t *hTxn;
        hTxn = (hash_t*) malloc (sizeof(hash_t));

	char	*csTxnMerchantID;	
	char	*csTxnCode;
	char	cStatus;
	char	cArInd;
	char	*csSubStatus;

DEBUGLOG(("============ process_txn ===========\n"));

	// Lock Record
	if (iRet == SUCCESS) {
DEBUGLOG(("process_txn  call DBOLTransaction:: MatchRespTxn()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "MatchRespTxn");
		if ((unsigned long)(*DBObjPtr)(csTxnSeq,PD_TO_PSP) != PD_FOUND) {
                        iRet = LOCK_FAILURE;
DEBUGLOG(("process_txn call DBOLTransaction MatchRespTxn [%s] FAILURE!!!\n", csTxnSeq));
ERRLOG("handle_auto_exp_off_merch_txn::process_txn DBOLTransaction MatchRespTxn [%s] FAILURE!!!\n", csTxnSeq);

printf("<tr><td>%s</td><td>Lock data error cause expiry job end</td>\n", csTxnSeq);
                }
	
	}

	if (iRet == SUCCESS) {
		myRec = (recordset_t*) malloc (sizeof(recordset_t));
		recordset_init(myRec,0);

DEBUGLOG(("process_txn  call DBOLTransaction:: GetTxnHeader()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "GetTxnHeader");
                if ((unsigned long)(*DBObjPtr)(csTxnSeq, myRec) != PD_OK) {
			iRet = FAILURE;
DEBUGLOG(("process_txn call DBOLTransaction:: GetTxnHeader [%s] FAILURE!!!\n", csTxnSeq));
ERRLOG("handle_auto_exp_off_merch_txn:: process_txn call DBOLTransaction:: GetTxnHeader [%s] FAILURE!!!\n", csTxnSeq);
		} else {
			hRec = RecordSet_GetFirst(myRec);
			if (hRec) {
				if (GetField_CString(hRec, "merchant_id", &csTxnMerchantID)) {
DEBUGLOG(("process_txn call DBOLTransaction:: GetTxnHeader() merchant_id = [%s]\n",csTxnMerchantID));
				}
				if (GetField_CString(hRec,"txn_code",&csTxnCode)) {
DEBUGLOG(("process_txn call DBOLTransaction:: GetTxnHeader() txn_code = [%s]\n",csTxnCode));
				}
				if (GetField_Char(hRec,"status",&cStatus)) {
DEBUGLOG(("process_txn call DBOLTransaction:: GetTxnHeader() status = [%c]\n",cStatus));
				}
				if (GetField_CString(hRec,"sub_status",&csSubStatus)) {
DEBUGLOG(("process_txn call DBOLTransaction:: GetTxnHeader() sub_status = [%s]\n",csSubStatus));
				}

				// Check Data Match 
				if (GetField_Char(hRec,"ar_ind",&cArInd)) {
DEBUGLOG(("process_txn call DBOLTransaction:: GetTxnHeader() ar_ind = [%c]\n",cArInd));
					// Not expect to get ar_ind
					iRet = FAILURE;
				}

				if (strcmp(csTxnMerchantID, csMerchantID)) {
					iRet = FAILURE;
DEBUGLOG(("process_txn call DBOLTransaction:: GetTxnHeader() Merchant ID difference [%s] [%s]\n", csTxnMerchantID, csMerchantID));
				}
				if (strcmp(csTxnCode, PD_INITIAL_OLN_TXN_CODE)) {
					iRet = FAILURE;
DEBUGLOG(("process_txn call DBOLTransaction:: GetTxnHeader() Txn Code difference [%s] [%s]\n", csTxnCode, PD_INITIAL_OLN_TXN_CODE));
				}
				if (cStatus != PD_TO_PSP) {
					iRet = FAILURE;
DEBUGLOG(("process_txn call DBOLTransaction:: GetTxnHeader() Status difference [%c] [%c]\n", cStatus, PD_TO_PSP));
				}

				/*
				if (strcmp(csSubStatus, PD_SENT_TO_PSP)) {
					iRet = FAILURE;
DEBUGLOG(("process_txn call DBOLTransaction:: GetTxnHeader() SubStatus difference [%s] [%s]\n", csSubStatus, PD_SENT_TO_PSP));
				}
				*/

				hRec = RecordSet_GetNext(myRec);
			}

			// handle deposit match pair
			if (iRet == SUCCESS) {
DEBUGLOG(("process_txn call BOOLDepositMatch::HandleDepositMatchPair()\n"));
				BOObjPtr = CreateObj(BOPtr, "BOOLDepositMatch", "HandleDepositMatchPair");
				if ((unsigned long)(*BOObjPtr)("0000000000000000", csTxnSeq, 'D', PD_UPDATE_USER) != PD_OK) {
printf("<tr><td>%s</td><td>Handle Deposit Match Pair Failed</td>\n", csTxnSeq);
					iRet = FAILURE;
DEBUGLOG(("process_txn call BOOLDepositMatch::HandleDepositMatchPair() FAILURE!!!\n"));
ERRLOG("handle_auto_exp_off_merch_txn::process_txn call BOOLDepositMatch::HandleDepositMatchPair() FAILURE!!!\n");
				}
			}

			// if match, Update 
			if (iRet == SUCCESS) {
				hash_init(hTxn, 0);

				PutField_CString(hTxn,"txn_seq", csTxnSeq);

				//PutField_Char(hTxn,"status", PD_COMPLETE);
				PutField_Char(hTxn,"status", PD_EXPIRED);

				PutField_Char(hTxn,"ar_ind", PD_REJECT);
				//PutField_CString(hTxn,"sub_status", PD_AUTO_EXPIRED);
				PutField_CString(hTxn,"update_user",PD_UPDATE_USER);

DEBUGLOG(("process_txn call DBOLTransaction::Update()\n"));
				DBObjPtr = CreateObj(DBObjPtr, "DBOLTransaction", "Update");
				if ((unsigned long)(*DBObjPtr)(hTxn) == PD_OK) {
DEBUGLOG(("process_txn call DBOLTransaction::Update() Success\n"));

printf("<tr><td>%s</td><td>Succ to Expiry</td>\n", csTxnSeq);

				} else {
printf("<tr><td>%s</td><td>UPdate Transaction Failed</td>\n", csTxnSeq);
					iRet = FAILURE;
DEBUGLOG(("process_txn call DBOLTransaction::Update() FAILURE!!!\n"));
ERRLOG("handle_auto_exp_off_merch_txn::process_txn call DBOLTransaction::Update() FAILURE!!!\n");
				}

				hash_destroy(hTxn);
			} else {
printf("<tr><td>%s</td><td>Data Changed before Expiry</td>\n", csTxnSeq);
			}
		}
		
		RecordSet_Destroy(myRec);
		FREE_ME(myRec)
	} 

	if (iRet == SUCCESS) {
DEBUGLOG(("process_txn Commit!\n"));
		TxnCommit();
	} else {
DEBUGLOG(("process_txn Rollback!\n"));
		TxnAbort();
	}

	// for testing 
	//TxnAbort();
//DEBUGLOG(("process_txn Rollback for testing....!\n"));


	FREE_ME(hTxn);
	return iRet;
}


int parse_arg(int argc,char **argv)
{
/*
        char    c;
	strcpy(cs_cutoff_date,"");

        while ((c = getopt(argc,argv,"d:")) != EOF) {
                switch (c) {
                        case 'd':
                                strcpy(cs_cutoff_date, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_cutoff_date,"")) 
                return FAILURE;

*/
        return SUCCESS;
}


