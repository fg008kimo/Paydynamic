
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
           char  filnam[25];
};
static struct sqlcxp sqlfpn =
{
    24,
    "check_missing_txn_log.pc"
};


static unsigned int sqlctx = 1163412739;


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
   unsigned char  *sqhstv[15];
   unsigned long  sqhstl[15];
            int   sqhsts[15];
            short *sqindv[15];
            int   sqinds[15];
   unsigned long  sqharm[15];
   unsigned long  *sqharc[15];
   unsigned short  sqadto[15];
   unsigned short  sqtdso[15];
} sqlstm = {12,15};

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
"SELECT psp_id , TO_CHAR ( sysdate , 'YYYYMMDDHH24MISS' ) sys_ts FROM psp_ur\
l WHERE effect_date <= to_char ( sysdate , 'YYYYMMDD' ) AND is_redirect_url =\
 1            ";

 static char *sq0003 = 
"pspd , psp_url purl , ( SELECT * FRO\
M ( SELECT prs_party_type , prs_party_id , prs_interval_start , prs_interval_\
end , prs_last_check_time , prs_alert_trigger_cnt FROM psp_redirect_setting W\
HERE ( ( prs_party_type = 'G' AND prs_party_id = '000' ) OR ( prs_party_type \
= 'P' and prs_party_id = :b4 ) ) ORDER BY DECODE ( prs_party_type , 'P' , 1 ,\
 'G' , 2 ) ) WHERE rownum = 1 ) rd_setting WHERE th_txn_id = tp_txn_id AND tp\
_psp_id = pspd . psp_id AND tp_psp_id = purl . psp_id AND tp_psp_id = :b4 AND\
 th_txn_code = 'DSI' AND th_create_timestamp >= TO_DATE ( :b0 , 'YYYYMMDDHH24\
MISS' ) - ( 1 / 24 / 60 ) * prs_interval_start AND th_create_timestamp < TO_D\
ATE ( :b0 , 'YYYYMMDDHH24MISS' ) - ( 1 / 24 / 60 ) * prs_interval_end AND th_\
create_timestamp >= prs_last_check_time AND NOT EXISTS ( SELECT null FROM psp\
_redirect_log WHERE prl_txn_id = th_txn_id ) ORDER BY th_create_timestamp , t\
h_txn_id            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,166,0,9,153,0,2049,0,0,0,1,0,
20,0,0,1,0,0,13,155,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
43,0,0,1,0,0,15,184,0,0,0,0,0,1,0,
58,0,0,1,0,0,15,194,0,0,0,0,0,1,0,
73,0,0,2,0,0,32,195,0,0,0,0,0,1,0,
88,0,0,3,1927,0,9,312,0,2049,8,8,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,9,0,0,1,9,0,0,
135,0,0,3,0,0,13,315,0,0,15,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,1,0,0,2,3,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
210,0,0,3,0,0,15,401,0,0,0,0,0,1,0,
225,0,0,3,0,0,15,448,0,0,0,0,0,1,0,
240,0,0,4,0,0,32,449,0,0,0,0,0,1,0,
255,0,0,5,0,0,17,490,0,0,1,1,0,1,0,1,9,0,0,
274,0,0,5,0,0,21,491,0,0,0,0,0,1,0,
289,0,0,6,0,0,32,502,0,0,0,0,0,1,0,
304,0,0,5,0,0,17,557,0,0,1,1,0,1,0,1,9,0,0,
323,0,0,5,0,0,21,558,0,0,0,0,0,1,0,
338,0,0,7,0,0,32,569,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2017/05/15              [WWK] 
Modify alert trigger condition			   2017/08/29		   [WWK]
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
#include "internal.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define	def_type_end_time	'E'
#define	def_type_max_txn_time	'M'
#define	def_type_reset_time	'R'

char cDebug;
int iTriggerCnt;
int init_search_ts = PD_TRUE;
int iUpdGlobalSetting = PD_TRUE;
char* cGlobalMaxTxnTS;

OBJPTR(BO);

int parse_arg(int argc,char **argv);
int GetRedirectPspId(recordset_t *rsRDPsp);
int ProcessCheckMissingTxn(char* csPspId, char* csSysTs, hash_t* hContext);
int UpdateLastCheckTime(char cPartyType, char* csPartyId, char* csTimestamp, char cUpdateType);
int InsertRDSetting(char* csPartyId, int iIntervalStart, int iIntervalEnd, int iTriggerCnt, char* csTimestamp);

int batch_init(int argc, char* argv[])
{
        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int     iRet = parse_arg(argc,argv);
	int	iDtlRet = SUCCESS;
	int	iCnt = 0;

	hash_t *hContext;

	if (iRet != SUCCESS) {
		return FAILURE;
	}

//DEBUGLOG(("Start check_missing_txn_log\n"));
//DEBUGLOG(("  iTriggerCnt [%d]\n",iTriggerCnt));

	hContext = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hContext,0);

	hash_t *hTmp = NULL;
	recordset_t *rsRDPsp = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rsRDPsp,0);

	iCnt = GetRedirectPspId(rsRDPsp);

	char*	csPspId = NULL;
	char*	csSysTs = NULL;

//DEBUGLOG(("Start loop PSP\n"));

	if (iCnt > 0) {
		hTmp = RecordSet_GetFirst(rsRDPsp);
		while (hTmp) {
			if (GetField_CString(hTmp,"psp_id",&csPspId)) {
//DEBUGLOG(("  psp_id = [%s]\n",csPspId));
			}

			if (GetField_CString(hTmp,"sys_ts",&csSysTs)) {
//DEBUGLOG(("  sys_ts = [%s]\n",csSysTs));
			}

			iDtlRet = ProcessCheckMissingTxn(csPspId,csSysTs,hContext);
			/*
			 * iDtlRet: PD_TRUE  (no missing / missing but no alert need)
			 *	    PD_FASLE (missing & alert)
			 *	    PD_ERR (error)
			 */

			if (iDtlRet == PD_FALSE) {
//DEBUGLOG(("!!Missing FOUND!!!\n"));
			} else if (iDtlRet == PD_ERR) {
DEBUGLOG(("!!ERROR!!!\n"));
				iRet = PD_ERR;
				break;
			}

			hTmp = RecordSet_GetNext(rsRDPsp);
		}

//DEBUGLOG(("End loop PSP\n"));
//DEBUGLOG(("  sys_ts = [%s]\n",csSysTs));

	}

DEBUGLOG(("Normal EXIT\n"));

	RecordSet_Destroy(rsRDPsp);
	FREE_ME(rsRDPsp);

	FREE_ME(hContext);

	return iRet;
}


int GetRedirectPspId(recordset_t *rsRDPsp)
{
	int iPspCnt = 0;
	hash_t *myHash;

//DEBUGLOG(("GetRedirectPspId() Start\n"));

	/* EXEC SQL WHENEVER SQLERROR GOTO get_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar	v_sys_ts[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_sys_ts;

		short	ind_psp_id = -1;
		short	ind_sys_ts = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	/* EXEC SQL DECLARE c_cursor_getredirectpid CURSOR FOR
		SELECT	psp_id,
			TO_CHAR(sysdate,'YYYYMMDDHH24MISS') sys_ts
		  FROM	psp_url
		 WHERE	effect_date <= to_char(sysdate,'YYYYMMDD')
		   AND	is_redirect_url = 1; */ 


	/* EXEC SQL OPEN c_cursor_getredirectpid; */ 

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
 if (sqlca.sqlcode < 0) goto get_error;
}


	do{
		/* EXEC SQL FETCH c_cursor_getredirectpid
		INTO	:v_psp_id:ind_psp_id,
			:v_sys_ts:ind_sys_ts; */ 

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
  sqlstm.sqhstv[0] = (unsigned char  *)&v_psp_id;
  sqlstm.sqhstl[0] = (unsigned long )13;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_psp_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_sys_ts;
  sqlstm.sqhstl[1] = (unsigned long )17;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_sys_ts;
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
  if (sqlca.sqlcode < 0) goto get_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

		//PSP_ID
		if (ind_psp_id >= 0) {
			v_psp_id.arr[v_psp_id.len] = '\0';
			PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
//DEBUGLOG(("PSP_ID with redirect URL: [%.*s]\n",v_psp_id.len,v_psp_id.arr));
		}

		//Start_system_timestamp
		if (ind_sys_ts >= 0) {
			v_sys_ts.arr[v_sys_ts.len] = '\0';
			PutField_CString(myHash,"sys_ts",(const char*)v_sys_ts.arr);
//DEBUGLOG(("System timestamp: [%.*s]\n",v_sys_ts.len,v_sys_ts.arr));
		}

		RecordSet_Add(rsRDPsp,myHash);
		iPspCnt++;
	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getredirectpid; */ 

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
 if (sqlca.sqlcode < 0) goto get_error;
}



//DEBUGLOG(("GetRedirectPspId() Normal Exit, total_count = [%d]\n",iPspCnt));

	return iPspCnt;

get_error:
    DEBUGLOG(("getredirectpspid: error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getredirectpid; */ 

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


    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 2;
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


    return PD_ERR;
}


int ProcessCheckMissingTxn(char *csPID, char *csSysTs, hash_t *hContext)
{
	int iDtlRet = SUCCESS;
	int iCnt = 0;
	int iCheckNoAlert = PD_TRUE;
	char cPartyType = PD_TYPE_GLOBAL;

	char *csMaxTxnTS = (char*) malloc (64);
	char *csResetTS = (char*) malloc (64);

	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


//DEBUGLOG(("check_missing_txn_log Start!\n"));

	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar hv_sys_ts[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_sys_ts;


		/* varchar	v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar	v_txn_create_ts[PD_CUSTOM_VALUE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_create_ts;

		/* varchar v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar v_psp_name[PD_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_name;

		/* varchar	v_url[PD_TLG_URL_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_url;

		/* varchar	v_start_ts[PD_CUSTOM_VALUE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_start_ts;

		/* varchar	v_end_ts[PD_CUSTOM_VALUE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_end_ts;

		int	v_interval_start;
		int	v_interval_end;
		char	v_party_type;
		int	v_trigger_cnt;
		int	v_total_cnt;
		/* varchar	v_max_txn_ts_char[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_max_txn_ts_char;

		/* varchar	v_reset_ts_char[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_reset_ts_char;

		/* varchar	v_end_ts_char[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_end_ts_char;


		short	ind_txn_id = -1;
		short	ind_txn_create_ts = -1;
		short	ind_psp_id = -1;
		short	ind_psp_name = -1;
		short	ind_url = -1;
		short	ind_start_ts = -1;
		short	ind_end_ts = -1;
		short	ind_interval_start = -1;
		short	ind_interval_end = -1;
		short	ind_party_type = -1;
		short	ind_trigger_cnt = -1;
		short	ind_total_cnt = -1;
		short	ind_max_txn_ts_char = -1;
		short	ind_reset_ts_char = -1;
		short	ind_end_ts_char = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_psp_id.len = strlen(csPID);
	memcpy(hv_psp_id.arr,csPID,hv_psp_id.len);
//DEBUGLOG(("  psp_id = [%.*s]\n",hv_psp_id.len,hv_psp_id.arr));

	hv_sys_ts.len = strlen(csSysTs);
	memcpy(hv_sys_ts.arr,csSysTs,hv_sys_ts.len);
//DEBUGLOG(("  sys_ts = [%.*s]\n",hv_sys_ts.len,hv_sys_ts.arr));

	/* EXEC SQL DECLARE c_cursor_getinfo CURSOR FOR

		SELECT	th_txn_id,
			TO_CHAR(th_create_timestamp,'DD MON YYYY HH24:MI:SS') AS txn_create_ts,
			pspd.psp_id,
			pspd.psp_name,
			purl.url,
			TO_CHAR(GREATEST(prs_last_check_time,TO_DATE(:hv_sys_ts,'YYYYMMDDHH24MISS') - (1/24/60)*prs_interval_start),'DD MON YYYY HH24:MI:SS') AS start_ts,
			TO_CHAR(TO_DATE(:hv_sys_ts,'YYYYMMDDHH24MISS') - (1/24/60)*prs_interval_end,'DD MON YYYY HH24:MI:SS') AS end_ts,
			rd_setting.prs_interval_start,
			rd_setting.prs_interval_end,
			rd_setting.prs_party_type,
			rd_setting.prs_alert_trigger_cnt,
			count(*) over () as total_cnt,
			TO_CHAR(max(th_create_timestamp) over (),'YYYYMMDDHH24MISS') AS max_txn_ts_char,
			TO_CHAR(GREATEST(prs_last_check_time,TO_DATE(:hv_sys_ts,'YYYYMMDDHH24MISS') - (1/24/60)*prs_interval_start),'YYYYMMDDHH24MISS') AS reset_ts_char,
			TO_CHAR(TO_DATE(:hv_sys_ts,'YYYYMMDDHH24MISS') - (1/24/60)*prs_interval_end,'YYYYMMDDHH24MISS') AS end_ts_char
		  FROM	txn_header,
			txn_psp_detail,
			psp_detail pspd,
			psp_url purl,
			(SELECT *
			   FROM (SELECT	prs_party_type,
					prs_party_id,
					prs_interval_start,
					prs_interval_end,
					prs_last_check_time,
					prs_alert_trigger_cnt
				   FROM	psp_redirect_setting
				  WHERE	((prs_party_type = 'G' AND prs_party_id = '000') OR
					 (prs_party_type = 'P' and prs_party_id = :hv_psp_id))
				 ORDER BY
					DECODE(prs_party_type, 'P', 1, 'G', 2)
				)
			 WHERE rownum = 1) rd_setting
		 WHERE	th_txn_id = tp_txn_id
		   AND	tp_psp_id = pspd.psp_id
		   AND	tp_psp_id = purl.psp_id
		   AND	tp_psp_id = :hv_psp_id
		   AND	th_txn_code = 'DSI'
		   AND	th_create_timestamp >= TO_DATE(:hv_sys_ts,'YYYYMMDDHH24MISS') - (1/24/60)*prs_interval_start
		   AND	th_create_timestamp < TO_DATE(:hv_sys_ts,'YYYYMMDDHH24MISS') - (1/24/60)*prs_interval_end
		   AND	th_create_timestamp >= prs_last_check_time
		   AND	NOT EXISTS (SELECT null
				      FROM psp_redirect_log
				     WHERE prl_txn_id = th_txn_id)
		 ORDER BY
			th_create_timestamp,
			th_txn_id; */ 


	/* EXEC SQL OPEN c_cursor_getinfo; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "SELECT th_txn_id , TO_CHAR ( th_create_timestamp , 'DD MON YYYY HH24:MI:\
SS' ) AS txn_create_ts , pspd . psp_id , pspd . psp_name , purl . url , TO_C\
HAR ( GREATEST ( prs_last_check_time , TO_DATE ( :b0 , 'YYYYMMDDHH24MISS' ) \
- ( 1 / 24 / 60 ) * prs_interval_start ) , 'DD MON YYYY HH24:MI:SS' ) AS sta\
rt_ts , TO_CHAR ( TO_DATE ( :b0 , 'YYYYMMDDHH24MISS' ) - ( 1 / 24 / 60 ) * p\
rs_interval_end , 'DD MON YYYY HH24:MI:SS' ) AS end_ts , rd_setting . prs_in\
terval_start , rd_setting . prs_interval_end , rd_setting . prs_party_type ,\
 rd_setting . prs_alert_trigger_cnt , count ( * ) over ( ) as total_cnt , TO\
_CHAR ( max ( th_create_timestamp ) over ( ) , 'YYYYMMDDHH24MISS' ) AS max_t\
xn_ts_char , TO_CHAR ( GREATEST ( prs_last_check_time , TO_DATE ( :b0 , 'YYY\
YMMDDHH24MISS' ) - ( 1 / 24 / 60 ) * prs_interval_start ) , 'YYYYMMDDHH24MIS\
S' ) AS reset_ts_char , TO_CHAR ( TO_DATE ( :b0 , 'YYYYMMDDHH24MISS' ) - ( 1\
 / 24 / 60 ) * prs_interval_end , 'YYYYMMDDHH24MISS' ) AS end_ts_char FROM t\
xn_header , txn_psp_detail , psp_detail ");
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )88;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_sys_ts;
 sqlstm.sqhstl[0] = (unsigned long )16;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_sys_ts;
 sqlstm.sqhstl[1] = (unsigned long )16;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_sys_ts;
 sqlstm.sqhstl[2] = (unsigned long )16;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_sys_ts;
 sqlstm.sqhstl[3] = (unsigned long )16;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[4] = (unsigned long )12;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[5] = (unsigned long )12;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_sys_ts;
 sqlstm.sqhstl[6] = (unsigned long )16;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_sys_ts;
 sqlstm.sqhstl[7] = (unsigned long )16;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto sql_error;
}



	do {
		/* EXEC SQL FETCH c_cursor_getinfo
		INTO
			:v_txn_id:ind_txn_id,
			:v_txn_create_ts:ind_txn_create_ts,
			:v_psp_id:ind_psp_id,
			:v_psp_name:ind_psp_name,
			:v_url:ind_url,
			:v_start_ts:ind_start_ts,
			:v_end_ts:ind_end_ts,
			:v_interval_start:ind_interval_start,
			:v_interval_end:ind_interval_end,
			:v_party_type:ind_party_type,	
			:v_trigger_cnt:ind_trigger_cnt,
			:v_total_cnt:ind_total_cnt,
			:v_max_txn_ts_char:ind_max_txn_ts_char,
			:v_reset_ts_char:ind_reset_ts_char,
			:v_end_ts_char:ind_end_ts_char; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )135;
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
  sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_create_ts;
  sqlstm.sqhstl[1] = (unsigned long )53;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_txn_create_ts;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_psp_id;
  sqlstm.sqhstl[2] = (unsigned long )13;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_psp_id;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_psp_name;
  sqlstm.sqhstl[3] = (unsigned long )53;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_psp_name;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_url;
  sqlstm.sqhstl[4] = (unsigned long )103;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_url;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_start_ts;
  sqlstm.sqhstl[5] = (unsigned long )53;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_start_ts;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_end_ts;
  sqlstm.sqhstl[6] = (unsigned long )53;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_end_ts;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_interval_start;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_interval_start;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_interval_end;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_interval_end;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_party_type;
  sqlstm.sqhstl[9] = (unsigned long )1;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_party_type;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_trigger_cnt;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_trigger_cnt;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_total_cnt;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_total_cnt;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_max_txn_ts_char;
  sqlstm.sqhstl[12] = (unsigned long )17;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_max_txn_ts_char;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_reset_ts_char;
  sqlstm.sqhstl[13] = (unsigned long )17;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_reset_ts_char;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_end_ts_char;
  sqlstm.sqhstl[14] = (unsigned long )17;
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_end_ts_char;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
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
			if (iCnt == 0) {
//DEBUGLOG(("  No data found!\n"));
			}
			break;
		}

		v_max_txn_ts_char.arr[v_max_txn_ts_char.len] = '\0';
		sprintf(csMaxTxnTS,"%.*s",v_max_txn_ts_char.len,v_max_txn_ts_char.arr);

		v_reset_ts_char.arr[v_reset_ts_char.len] = '\0';
		sprintf(csResetTS,"%.*s",v_reset_ts_char.len,v_reset_ts_char.arr);

		if (ind_trigger_cnt >= 0) {
			iTriggerCnt = v_trigger_cnt;
		}

		if (ind_total_cnt >= 0) {
			if (v_total_cnt <= iTriggerCnt) {
				iCnt = v_total_cnt;
				break;
			}
		}

		if (iCnt == 0) {
			if (ind_start_ts >= 0 && ind_end_ts >= 0) {
				v_start_ts.arr[v_start_ts.len] = '\0';
				v_end_ts.arr[v_end_ts.len] = '\0';
printf("Deposit search period: %.*s to %.*s<br>\n",v_start_ts.len,v_start_ts.arr,v_end_ts.len,v_end_ts.arr);
			}

			if (ind_url >= 0) {
				v_url.arr[v_url.len] = '\0';
printf("Redirect URL: %.*s<br>\n",v_url.len,v_url.arr);
			}

			if (ind_psp_name >= 0) {
				v_psp_name.arr[v_psp_name.len] = '\0';
printf("PSP account name: %.*s<br>\n",v_psp_name.len,v_psp_name.arr);
			}


printf("<table border=1><tr><td>Transaction ID</td><td>Transaction creation time</td></tr>\n");
		}

printf("<tr>");

		if (ind_txn_id >= 0) {
			v_txn_id.arr[v_txn_id.len] = '\0';
printf("<td>%.*s</td>",v_txn_id.len,v_txn_id.arr);
DEBUGLOG(("MISSING: txn_id [%.*s]\n",v_txn_id.len,v_txn_id.arr));
		}

		if (ind_txn_create_ts >= 0) {
			v_txn_create_ts.arr[v_txn_create_ts.len] = '\0';
printf("<td>%.*s</td>",v_txn_create_ts.len,v_txn_create_ts.arr);
		}

printf("</tr>\n");


		if (ind_party_type >= 0) {
			cPartyType = v_party_type;
		}

		iCnt++;
	}
	while(PD_TRUE);
	/* EXEC SQL CLOSE c_cursor_getinfo; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )210;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto sql_error;
}




	if (iCnt == 0) {
		//No Missing, reset time = end time
		iDtlRet = UpdateLastCheckTime(PD_TYPE_PSP,csPID,csSysTs,def_type_end_time);

	} else if (iCnt <= iTriggerCnt) {
		//Missing found but <= trigger count, no email alert
DEBUGLOG(("  PID [%s] count [%d], normal exit!\n",csPID,iCnt));

		if (v_party_type == 'G') {
			iDtlRet = InsertRDSetting(csPID,v_interval_start,v_interval_end,v_trigger_cnt,csResetTS);
		} else {
			iDtlRet = UpdateLastCheckTime(PD_TYPE_PSP,csPID,csResetTS,def_type_reset_time);
		}

	} else {
		//Missing found, alert trigger, need to send email alert
DEBUGLOG(("  PID [%s] count [%d] >= [%d], Alert Trigger!!\n",csPID,iCnt,iTriggerCnt));
printf("</table><br><!--ALERT_SENT-->\n");

		if (v_party_type == 'G') {
			iDtlRet = InsertRDSetting(csPID,v_interval_start,v_interval_end,v_trigger_cnt,csMaxTxnTS);
		} else {
			iDtlRet = UpdateLastCheckTime(PD_TYPE_PSP,csPID,csMaxTxnTS,def_type_max_txn_time);
		}

		iCheckNoAlert = PD_FALSE;
	}


	if (iDtlRet != PD_OK) {
DEBUGLOG(("Call UpdateLastCheckTime() ERROR found\n"));
		return iDtlRet;
	}


	FREE_ME(csMaxTxnTS);
	FREE_ME(csResetTS);

	return iCheckNoAlert;

sql_error:
DEBUGLOG(("check_missing_txn_log error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getinfo; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 15;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )225;
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
    sqlstm.arrsiz = 15;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )240;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int UpdateLastCheckTime(char cPartyType, char *csPartyId, char *csTimestamp, char cUpdateType)
{
	char* csBuf;
	/* EXEC SQL WHENEVER SQLERROR GOTO updateglobal_err; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;

	/* EXEC SQL END DECLARE SECTION; */ 


	csBuf = (char*) malloc (128);

	strcpy((char*)hv_dynstmt.arr,"UPDATE psp_redirect_setting");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	strcat((char *)hv_dynstmt.arr, " SET prs_update_timestamp = sysdate, prs_last_check_time = TO_DATE('");
	strcat((char *)hv_dynstmt.arr, csTimestamp);
	strcat((char *)hv_dynstmt.arr, "','YYYYMMDDHH24MISS')");

	//cUpdateType ['E'] = 'End time', need to calculate by sysdate - interval_end
	if (cUpdateType == def_type_end_time) {
		strcat((char *)hv_dynstmt.arr, " - (1/24/60) * prs_interval_end ");
	}

	strcat((char *)hv_dynstmt.arr, " WHERE prs_party_type = '");
	sprintf(csBuf,"%c",cPartyType);
	strcat((char *)hv_dynstmt.arr, csBuf);
	strcat((char *)hv_dynstmt.arr, "'");

	strcat((char *)hv_dynstmt.arr, " AND prs_party_id = '");
	strcat((char *)hv_dynstmt.arr, csPartyId);
	strcat((char *)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

//DEBUGLOG(("UpdateLastCheckTime sql [%s]\n",hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )255;
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
 if (sqlca.sqlcode < 0) goto updateglobal_err;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )274;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto updateglobal_err;
}



	FREE_ME(csBuf);

	return PD_OK;

updateglobal_err:
    DEBUGLOG(("Update Last Checking Time error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    ERRLOG("check_missing_txn_log::Update Last Checking Time error code %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 15;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )289;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int InsertRDSetting(char *csPartyId, int iIntervalStart, int iIntervalEnd, int iTriggerCnt, char *csTimestamp)
{
	char* csBuf;
	/* EXEC SQL WHENEVER SQLERROR GOTO insert_err; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;

	/* EXEC SQL END DECLARE SECTION; */ 


	csBuf = (char*) malloc (128);

	strcpy((char*)hv_dynstmt.arr,"INSERT INTO psp_redirect_setting (prs_party_type, prs_party_id, prs_interval_start, prs_interval_end, prs_alert_trigger_cnt, ");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	strcat((char *)hv_dynstmt.arr, "prs_last_check_time, prs_create_timestamp, prs_update_timestamp, prs_create_user, prs_update_user) VALUES (");

	strcat((char *)hv_dynstmt.arr, "'");
	sprintf(csBuf,"%c",PD_TYPE_PSP);
	strcat((char *)hv_dynstmt.arr, csBuf);
	strcat((char *)hv_dynstmt.arr, "', ");

	strcat((char *)hv_dynstmt.arr, "'");
	strcat((char *)hv_dynstmt.arr, csPartyId);
	strcat((char *)hv_dynstmt.arr, "', ");

	sprintf(csBuf,"%d",iIntervalStart);
	strcat((char *)hv_dynstmt.arr, csBuf);
	strcat((char *)hv_dynstmt.arr, ", ");

	sprintf(csBuf,"%d",iIntervalEnd);
	strcat((char *)hv_dynstmt.arr, csBuf);
	strcat((char *)hv_dynstmt.arr, ", ");

	sprintf(csBuf,"%d",iTriggerCnt);
	strcat((char *)hv_dynstmt.arr, csBuf);
	strcat((char *)hv_dynstmt.arr, ", ");

	strcat((char *)hv_dynstmt.arr, "TO_DATE('");
	strcat((char *)hv_dynstmt.arr, csTimestamp);
	strcat((char *)hv_dynstmt.arr, "','YYYYMMDDHH24MISS')");
	strcat((char *)hv_dynstmt.arr, ", ");

	strcat((char *)hv_dynstmt.arr, "sysdate, sysdate, 'SYSTEM', 'SYSTEM')");

	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

//DEBUGLOG(("InsertRDSetting sql [%s]\n",hv_dynstmt.arr));
DEBUGLOG(("  New rule insert for PID [%s]\n", csPartyId));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )304;
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
 if (sqlca.sqlcode < 0) goto insert_err;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )323;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto insert_err;
}



	FREE_ME(csBuf);

	return PD_OK;

insert_err:
    DEBUGLOG(("Insert RD Setting error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    ERRLOG("check_missing_txn_log::Insert RD Setting error code %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 15;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )338;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int batch_terminate(int argc, char* argv[])
{
        return SUCCESS;
}


int parse_arg(int argc,char **argv)
{
        return SUCCESS;
}
