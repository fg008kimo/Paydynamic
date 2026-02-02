
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
    "RulePspLbPools.pc"
};


static unsigned int sqlctx = 10625171;


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

 static char *sq0001 = 
"SELECT RP_POOL_ID , RP_DESC , RP_POOL_LIMIT , RP_RATIO , RP_PRIORITY FROM R\
ULE_PSP_LB_POOLS WHERE RP_DISABLED = 0 and RP_CRITERIA_POOL_ID = :b0 order by\
 RP_PRIORITY desc            ";

 static char *sq0002 = 
"SELECT sum ( tc_total_counter ) , sum ( tc_counter ) , sum ( tc_total_req_c\
ounter ) , sum ( tc_req_counter ) FROM txn_counters WHERE tc_txn_code in ( 'D\
SI' , 'DSP' ) AND tc_country_id = :b0 AND tc_channel_code in ( 'WEB' , 'XPY' \
) AND tc_service_code = :b1 AND ( tc_pay_method = :b2 or tc_pay_method = '000\
' ) AND tc_type = :b3 AND tc_category = :b4 AND tc_party_type = :b5 AND TC_PA\
RTY_ID in ( SELECT rm_psp_id FROM rule_psp_lb_mapping WHERE rm_pool_id = :b6 \
AND rm_disabled = 0 ) AND tc_currency_id = :b7            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,181,0,9,73,0,2049,1,1,0,1,0,1,3,0,0,
24,0,0,1,0,0,13,75,0,0,5,0,0,1,0,2,3,0,0,2,9,0,0,2,4,0,0,2,3,0,0,2,3,0,0,
59,0,0,1,0,0,15,124,0,0,0,0,0,1,0,
74,0,0,1,0,0,15,139,0,0,0,0,0,1,0,
89,0,0,2,518,0,9,273,0,2049,8,8,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,1,0,0,1,9,0,0,
1,1,0,0,1,3,0,0,1,9,0,0,
136,0,0,2,0,0,13,275,0,0,4,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
167,0,0,2,0,0,15,308,0,0,0,0,0,1,0,
182,0,0,2,0,0,15,316,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/01/03              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "RulePspLbPools.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char    cDebug;

void RulePspLbPools(char    cdebug)
{
        cDebug = cdebug;
}


int GetDetailById(int iId,
                        recordset_t* myRec)
{

	int	iCnt = 0;
	hash_t	*myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getdetailbyid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		int	hv_id;

		int	v_pool_id;
		/* varchar	v_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_desc;

		double	v_pool_limit;
		int	v_ratio;
		int	v_priority;	

		short	ind_pool_id = -1;
		short	ind_desc = -1;
		short	ind_pool_limit = -1;
		short	ind_ratio = -1;
		short	ind_priority = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_id = iId;
DEBUGLOG(("GetDetailById: ID = [%d]\n",hv_id));

	/* EXEC SQL DECLARE c_cursor_getdetailbyid CURSOR FOR
		SELECT	RP_POOL_ID, 
			RP_DESC,
			RP_POOL_LIMIT,
			RP_RATIO,
			RP_PRIORITY
                  FROM RULE_PSP_LB_POOLS
                 WHERE RP_DISABLED = 0
                   and RP_CRITERIA_POOL_ID = :hv_id
		   order by RP_PRIORITY desc; */ 


	/* EXEC SQL OPEN c_cursor_getdetailbyid; */ 

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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_id;
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
 if (sqlca.sqlcode < 0) goto getdetailbyid_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getdetailbyid
                INTO
			:v_pool_id:ind_pool_id,
			:v_desc:ind_desc,
			:v_pool_limit:ind_pool_limit,
			:v_ratio:ind_ratio,
			:v_priority:ind_priority; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 5;
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
                sqlstm.sqhstv[0] = (unsigned char  *)&v_pool_id;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_pool_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_desc;
                sqlstm.sqhstl[1] = (unsigned long )53;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_desc;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_pool_limit;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_pool_limit;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_ratio;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_ratio;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_priority;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_priority;
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
                if (sqlca.sqlcode < 0) goto getdetailbyid_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }
		iCnt++;
		myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);
	
/* pool_id */
		if (ind_pool_id >= 0) {
DEBUGLOG(("GetDetailById: pool_id = [%d]\n",v_pool_id));
			PutField_Int(myHash,"pool_id",v_pool_id);
		}
/* desc */
		if (ind_desc >= 0 ) {
			v_desc.arr[v_desc.len] = '\0';
DEBUGLOG(("GetDetailById: desc = [%s]\n",(char*)v_desc.arr));
			PutField_CString(myHash,"desc",(char*)v_desc.arr);
		}


/* pool limit */
		if (ind_pool_limit >= 0) {
DEBUGLOG(("GetDetailById: pool_limit = [%lf]\n",v_pool_limit));
			PutField_Double(myHash,"pool_limit",v_pool_limit);
		}

/* ratio */
		if (ind_ratio >= 0) {
DEBUGLOG(("GetDetailById: ratio = [%d]\n",v_ratio));
			PutField_Int(myHash,"ratio",v_ratio);
		}
/* priority */
		if (ind_priority >= 0) {
DEBUGLOG(("GetDetailById: priority = [%d]\n",v_priority));
			PutField_Int(myHash,"priority",v_priority);
		}
		RecordSet_Add(myRec,myHash);

	}
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getdetailbyid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )59;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getdetailbyid_error;
}



	if (iCnt > 0 ) {
DEBUGLOG(("GetDetailById Normal Exit\n"));
                return  PD_FOUND;
        }
        else {
DEBUGLOG(("GetDetailById Normal Exit, Not Found\n"));
                return PD_NOT_FOUND;
        }

getdetailbyid_error:
DEBUGLOG(("getdetailbyid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getdetailbyid; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 5;
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


    return PD_NOT_FOUND;
}

int GetPspPoolsTotal(int iId,
		  const char* csServiceCode,
		  const char* csTxnCountry,
		  const char* csTxnCcy,
		  const char* csPayMethod,
                  double *dCurr,
		  double *dTotalCurr,
                  double *dReqCurr,
		  double *dTotalReqCurr)
{

	int	iRet = PD_OK;
	

        /* EXEC SQL WHENEVER SQLERROR GOTO getpsppoolslimit_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		int	hv_id;
		char	hv_party_type;
		char	hv_counter_type;
		/* varchar	hv_category_type[PD_CATEGORY_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_category_type;

		/* varchar	hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar	hv_txn_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_txn_country;

		/* varchar	hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;

		/* varchar	hv_pay_method[PD_PAY_METHOD_LEN]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_pay_method;

	
		double	v_curr;
		double	v_total_curr;

		double	v_req_curr;
		double	v_total_req_curr;

		short	ind_curr = -1;
		short	ind_total_curr = -1;
		short	ind_req_curr = -1;
		short	ind_total_req_curr = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	*dCurr = 0.0;
	hv_id = iId;
DEBUGLOG(("GetPspPoolsTotal: ID = [%d]\n",hv_id));

/* party type */
	hv_party_type = PD_TYPE_PSP;
DEBUGLOG(("GetPspPoolsTotal: party_type = [%c]\n",hv_party_type));

/* counter type */
	hv_counter_type = PD_DAILY;
DEBUGLOG(("GetPspPoolsTotal: counter_type = [%c]\n",hv_counter_type));

/* category type */
	hv_category_type.len = strlen(PD_VALUE_TYPE_AMT);
	strcpy((char*)hv_category_type.arr,PD_VALUE_TYPE_AMT);
DEBUGLOG(("GetPspPoolsTotal: category_type = [%.*s]\n",hv_category_type.len,hv_category_type.arr));

/* service_code */
	hv_service_code.len = strlen(csServiceCode);
	memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("GetPspPoolsTotal: service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

/* txn_country */
	hv_txn_country.len = strlen(csTxnCountry);
	memcpy(hv_txn_country.arr,csTxnCountry,hv_txn_country.len);
DEBUGLOG(("GetPspPoolsTotal: txn_country = [%.*s]\n",hv_txn_country.len,hv_txn_country.arr));

/* txn_ccy */
	hv_txn_ccy.len = strlen(csTxnCcy);
	memcpy(hv_txn_ccy.arr,csTxnCcy,hv_txn_ccy.len);
DEBUGLOG(("GetPspPoolsTotal: txn_ccy = [%.*s]\n",hv_txn_ccy.len,hv_txn_ccy.arr));

/* pay_method */
	hv_pay_method.len = strlen(csPayMethod);
	memcpy(hv_pay_method.arr,csPayMethod,hv_pay_method.len);
DEBUGLOG(("GetPspPoolsTotal: pay_method = [%.*s]\n",hv_pay_method.len,hv_pay_method.arr));

	/* EXEC SQL DECLARE c_cursor_getpsppoolslimit CURSOR FOR
/o
		SELECT sum(tc_total_counter),
		       sum(tc_counter),
		       sum(tc_total_req_counter),
		       sum(tc_req_counter)
  		  FROM txn_counters
		 WHERE tc_txn_code in ('DSI','DSP')
   		   AND tc_country_id = :hv_txn_country
   		   AND tc_channel_code in ('WEB','XPY')
   		   AND tc_service_code = :hv_service_code
   		   AND (tc_pay_method = :hv_pay_method or tc_pay_method = '000')
   		   AND tc_type = :hv_counter_type
   		   AND tc_category = :hv_category_type
   		   AND tc_party_type = :hv_party_type
   		   AND TC_PARTY_ID in 
			(SELECT rm_psp_id
   			   FROM rule_psp_lb_mapping,
            		        psp_detail a,
            			clients b
   			  WHERE rm_pool_id = :hv_id
    			    AND rm_disabled = 0
    			    AND rm_psp_id = a.psp_id
    			    AND a.disabled = 0
    			    AND a.online_mode = 'Y'
    			    AND a.status = 'O'
    			    AND a.client_id = b.client_id
    			    AND b.status = 'O')
   		   AND tc_currency_id = :hv_txn_ccy;

o/
/o sum up all if the psp is disabled or offlineo/
                SELECT sum(tc_total_counter),
                       sum(tc_counter),
                       sum(tc_total_req_counter),
                       sum(tc_req_counter)
                  FROM txn_counters
                 WHERE tc_txn_code in ('DSI','DSP')
                   AND tc_country_id = :hv_txn_country
                   AND tc_channel_code in ('WEB','XPY')
                   AND tc_service_code = :hv_service_code
                   AND (tc_pay_method = :hv_pay_method or tc_pay_method = '000')
                   AND tc_type = :hv_counter_type
                   AND tc_category = :hv_category_type
                   AND tc_party_type = :hv_party_type
                   AND TC_PARTY_ID in
                        (SELECT rm_psp_id
                           FROM rule_psp_lb_mapping
                          WHERE rm_pool_id = :hv_id
                            AND rm_disabled = 0)
                   AND tc_currency_id = :hv_txn_ccy; */ 

	
	/* EXEC SQL OPEN c_cursor_getpsppoolslimit; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )89;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_txn_country;
 sqlstm.sqhstl[0] = (unsigned long )4;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_pay_method;
 sqlstm.sqhstl[2] = (unsigned long )6;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_counter_type;
 sqlstm.sqhstl[3] = (unsigned long )1;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_category_type;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_party_type;
 sqlstm.sqhstl[5] = (unsigned long )1;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_id;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_txn_ccy;
 sqlstm.sqhstl[7] = (unsigned long )5;
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
 if (sqlca.sqlcode < 0) goto getpsppoolslimit_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getpsppoolslimit
                INTO
			:v_total_curr:ind_total_curr,
			:v_curr:ind_curr,
			:v_total_req_curr:ind_total_req_curr,
			:v_req_curr:ind_req_curr; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 8;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )136;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_total_curr;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_total_curr;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_curr;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_curr;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_total_req_curr;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_total_req_curr;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_req_curr;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_req_curr;
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
                if (sqlca.sqlcode < 0) goto getpsppoolslimit_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }
		if (ind_curr >= 0) 
			*dCurr = v_curr;
		else 
			*dCurr = 0.0;
				
		if (ind_total_curr >= 0) 
			*dTotalCurr = v_total_curr;
		else
			*dTotalCurr = 0.0;

		if (ind_req_curr >= 0) 
			*dReqCurr = v_req_curr;
		else 
			*dReqCurr = 0.0;
				
		if (ind_total_req_curr >= 0) 
			*dTotalReqCurr = v_total_req_curr;
		else
			*dTotalReqCurr = 0.0;
	}
        while(PD_TRUE);

DEBUGLOG(("GetPspPoolsTotal limit = [%f]\n",*dCurr));
        /* EXEC SQL CLOSE c_cursor_getpsppoolslimit; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )167;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getpsppoolslimit_error;
}



	return iRet;

getpsppoolslimit_error:
DEBUGLOG(("getpsppoolslimit_erro code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getpsppoolslimit; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 8;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )182;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}

