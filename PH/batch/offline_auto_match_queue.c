
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
           char  filnam[28];
};
static struct sqlcxp sqlfpn =
{
    27,
    "offline_auto_match_queue.pc"
};


static unsigned int sqlctx = 1503386227;


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
"SELECT oth_txn_id FROM ol_txn_header , ol_txn_psp_detail WHERE oth_txn_id =\
 otp_txn_id AND oth_input_channel = :b0 AND oth_txn_code = :b1 AND oth_status\
 = :b2 AND oth_ar_ind = :b3 AND oth_sub_status = :b4 AND otp_txn_timestamp >=\
 sysdate - :b5 AND otp_txn_hold_ind = 0 AND otp_sys_match_ind = 1 ORDER BY ot\
p_txn_timestamp ASC            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,337,0,9,115,0,2049,6,6,0,1,0,1,9,0,0,1,9,0,0,1,1,0,0,1,1,0,0,1,9,0,0,1,
3,0,0,
44,0,0,1,0,0,13,117,0,0,1,0,0,1,0,2,9,0,0,
63,0,0,1,0,0,15,142,0,0,0,0,0,1,0,
78,0,0,1,0,0,15,155,0,0,0,0,0,1,0,
93,0,0,2,0,0,32,156,0,0,0,0,0,1,0,
};


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include "common.h"
#include "utilitys.h"
#include "curl/curl.h"
#include "ObjPtr.h"
#include "myrecordset.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

OBJPTR(DB);
OBJPTR(Txn);

char cDebug = 'Y';

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int iRet = PD_OK;
	int iTmpRet;
	int iEnable = PD_TRUE;

	hash_t *myHash;
	myHash = (hash_t*) malloc (sizeof(hash_t));

	char csBankStmtAuto[PD_SP_VALUE_LEN];
	char csStmtDateRange[PD_SP_VALUE_LEN];

	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_input_channel[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_input_channel;

		/* varchar hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

		char hv_status;
		char hv_ar_ind;
		/* varchar hv_sub_status[PD_SUB_STATUS_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_sub_status;

		int hv_stmt_date_range;

		/* varchar v_stmt_txn_id[PD_STMT_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_stmt_txn_id;

		short ind_stmt_txn_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	if (iRet == PD_OK) {
DEBUGLOG(("offline_auto_match_queue: call DBSystemParameter::FindCode()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBSystemParameter", "FindCode");
		if ((unsigned long)(*DBObjPtr)(PD_OFL_BANK_STMT_AUTO, csBankStmtAuto) == PD_FOUND) {
DEBUGLOG(("offline_auto_match_queue: bank_stmt_auto = [%d]\n", atoi(csBankStmtAuto)));
			if (atoi(csBankStmtAuto) != PD_TRUE) {
DEBUGLOG(("offline_auto_match_queue: auto match disabled\n"));
				iEnable = PD_FALSE;
			}
		} else {
DEBUGLOG(("offline_auto_match_queue: cannot find [%s] in system parameter\n", PD_OFL_BANK_STMT_AUTO));
ERRLOG("offline_auto_match_queue: cannot find [%s] in system parameter\n", PD_OFL_BANK_STMT_AUTO);
			iRet = PD_ERR;
		}
	}

	if (iRet == PD_OK && iEnable) {
DEBUGLOG(("offline_auto_match_queue: call DBSystemParameter::FindCode()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBSystemParameter", "FindCode");
		if ((unsigned long)(*DBObjPtr)(PD_OFL_STMT_DATE_RANGE, csStmtDateRange) == PD_FOUND) {
DEBUGLOG(("offline_auto_match_queue: stmt_date_range = [%d]\n", atoi(csStmtDateRange)));
		} else {
DEBUGLOG(("offline_auto_match_queue: cannot find [%s] in system parameter\n", PD_OFL_STMT_DATE_RANGE));
ERRLOG("offline_auto_match_queue: cannot find [%s] in system parameter\n", PD_OFL_STMT_DATE_RANGE);
			iRet = PD_ERR;
		}
	}

	if (iRet == PD_OK && iEnable) {
		hv_input_channel.len = strlen(PD_CHANNEL_OMT);
		memcpy(hv_input_channel.arr, PD_CHANNEL_OMT, hv_input_channel.len);

		hv_txn_code.len = strlen(PD_BANK_DEPOSIT_TXN_CODE);
		memcpy(hv_txn_code.arr, PD_BANK_DEPOSIT_TXN_CODE, hv_txn_code.len);

		hv_status = PD_COMPLETE;

		hv_ar_ind = PD_ACCEPT;

		hv_sub_status.len = strlen(PD_UNALLOCATED);
		memcpy(hv_sub_status.arr, PD_UNALLOCATED, hv_sub_status.len);

		hv_stmt_date_range = atoi(csStmtDateRange);

		/* EXEC SQL DECLARE c_cursor_getunallocatedrecords CURSOR FOR
			SELECT oth_txn_id
			FROM ol_txn_header, ol_txn_psp_detail
			WHERE oth_txn_id = otp_txn_id
			AND oth_input_channel = :hv_input_channel
			AND oth_txn_code = :hv_txn_code
			AND oth_status = :hv_status
			AND oth_ar_ind = :hv_ar_ind
			AND oth_sub_status = :hv_sub_status
//			AND oth_multi_match_ind = 0
			AND otp_txn_timestamp >= sysdate - :hv_stmt_date_range
			AND otp_txn_hold_ind = 0
			AND otp_sys_match_ind = 1
			ORDER BY otp_txn_timestamp ASC; */ 


		/* EXEC SQL OPEN c_cursor_getunallocatedrecords; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
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
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_input_channel;
  sqlstm.sqhstl[0] = (unsigned long )5;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_code;
  sqlstm.sqhstl[1] = (unsigned long )5;
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
  sqlstm.sqhstv[3] = (unsigned char  *)&hv_ar_ind;
  sqlstm.sqhstl[3] = (unsigned long )1;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&hv_sub_status;
  sqlstm.sqhstl[4] = (unsigned long )5;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&hv_stmt_date_range;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
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
  if (sqlca.sqlcode < 0) goto sql_error;
}


		for (;;) {
			/* EXEC SQL FETCH c_cursor_getunallocatedrecords
			INTO :v_stmt_txn_id:ind_stmt_txn_id; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 6;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )44;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_stmt_txn_id;
   sqlstm.sqhstl[0] = (unsigned long )19;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_stmt_txn_id;
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

			hash_init(myHash, 0);

			// stmt_txn_id
			if (ind_stmt_txn_id >= 0) {
				v_stmt_txn_id.arr[v_stmt_txn_id.len] = '\0';
				PutField_CString(myHash, "txn_seq", (const char*)v_stmt_txn_id.arr);
DEBUGLOG(("offline_auto_match_queue: stmt_txn_id = [%s]\n", (const char*)v_stmt_txn_id.arr));

				TxnObjPtr = CreateObj(TxnPtr, "TxnOmtByUsATM", "Authorize");
				iTmpRet = (unsigned long)(*TxnObjPtr)(myHash, myHash, myHash);
				if (iTmpRet != PD_OK) {
DEBUGLOG(("offline_auto_match_queue: call TxnOmtByUsATM:Authorize(%s) failed\n", (const char*)v_stmt_txn_id.arr));
ERRLOG("offline_auto_match_queue: call TxnOmtByUsATM:Authorize(%s) failed\n", (const char*)v_stmt_txn_id.arr);
				}
			}

			hash_destroy(myHash);
		}
		/* EXEC SQL CLOSE c_cursor_getunallocatedrecords; */ 

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
  if (sqlca.sqlcode < 0) goto sql_error;
}


	}

	FREE_ME(myHash);

DEBUGLOG(("offline_auto_match_queue: Normal Exit() iRet = [%d]\n", iRet));
	return iRet;

sql_error:
DEBUGLOG(("sql_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("offline_auto_match_queue:: sql error\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getunallocatedrecords; */ 

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


	/* EXEC SQL ROLLBACK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )93;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	FREE_ME(myHash);
	return FAILURE;
}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}
