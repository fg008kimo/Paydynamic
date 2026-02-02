
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
           char  filnam[24];
};
static struct sqlcxp sqlfpn =
{
    23,
    "customer_group_promo.pc"
};


static unsigned int sqlctx = 631167555;


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
   unsigned char  *sqhstv[7];
   unsigned long  sqhstl[7];
            int   sqhsts[7];
            short *sqindv[7];
            int   sqinds[7];
   unsigned long  sqharm[7];
   unsigned long  *sqharc[7];
   unsigned short  sqadto[7];
   unsigned short  sqtdso[7];
} sqlstm = {12,7};

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
"SELECT cpr_merchant_id , cpr_min_count , cpr_min_amount , cpr_min_day FROM \
customer_group_promo_rule WHERE cpr_disabled = 0            ";

 static char *sq0003 = 
"SELECT cgr_from_group_code , count ( cgr_group_code ) FROM customer_group_r\
ules WHERE cgr_disabled = 0 AND cgr_merchant_id = :b0 AND cgr_from_group_code\
 is not NULL GROUP BY cgr_from_group_code            ";

 static char *sq0004 = 
"SELECT td_customer_tag FROM txn_header , txn_detail , customer_group_detail\
 WHERE th_txn_code = 'DSI' AND th_ar_ind = 'A' AND th_txn_id = td_txn_id AND \
th_merchant_id = :b0 and td_customer_group = :b1 and td_customer_tag = cgd_cu\
st_id and cgd_code = :b1 AND cgd_merchant_id = :b0 and not exists ( select nu\
ll from customer_group_promo_list where cgl_cust_id = td_customer_tag ) group\
 by td_customer_tag having count ( th_txn_id ) >= :b4 and sum ( th_transactio\
n_amount ) >= :b5 and min ( th_host_posting_date ) <= ( select to_char ( to_d\
ate ( sys_val , 'YYYYMMDD' ) - :b6 , 'yyyymmdd' ) from system_control where s\
ys_code = 'CTPHDATE' )            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,67,0,6,137,0,0,1,1,0,1,0,2,3,0,0,
24,0,0,2,135,0,9,201,0,2049,0,0,0,1,0,
39,0,0,2,0,0,13,204,0,0,4,0,0,1,0,2,9,0,0,2,3,0,0,2,4,0,0,2,3,0,0,
70,0,0,2,0,0,15,245,0,0,0,0,0,1,0,
85,0,0,2,0,0,15,262,0,0,0,0,0,1,0,
100,0,0,3,205,0,9,300,0,2049,1,1,0,1,0,1,9,0,0,
119,0,0,3,0,0,13,303,0,0,2,0,0,1,0,2,9,0,0,2,3,0,0,
142,0,0,3,0,0,15,325,0,0,0,0,0,1,0,
157,0,0,3,0,0,15,342,0,0,0,0,0,1,0,
172,0,0,4,648,0,9,455,0,2049,7,7,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,
1,4,0,0,1,3,0,0,
215,0,0,4,0,0,13,458,0,0,1,0,0,1,0,2,9,0,0,
234,0,0,4,0,0,15,483,0,0,0,0,0,1,0,
249,0,0,4,0,0,15,500,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/10/31              LokMan Chow
add one promote requirement			   2014/10/31		   LokMan Chow
*/

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
#include "dbutility.h"
#include "batchcommon.h"
#include "myrecordset.h"
#include "ObjPtr.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cs_mode[PD_DATE_LEN + 1];
char	cDebug = 'Y';

OBJPTR(DB);

int clear_non_promoted();
int find_promo_rule(hash_t* hTxn);
int find_promo_group(hash_t* hTxn);
int find_promo_customer(hash_t* hTxn,recordset_t *myRec);
int process_promotion(recordset_t *rRecordSet);

int batch_init(int argc, char* argv[])
{
        return SUCCESS;
}


int batch_terminate(int argc, char* argv[])
{
    return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int iRet = SUCCESS;
	int iRuleCnt = 0;
	int i = 0;
	int iTmp = 0;
	double	dTmp;
	char *csMerchantId;
	char csTag[PD_TAG_LEN+1];

	hash_t* hTxn;
	hTxn = (hash_t*)  malloc (sizeof(hash_t));
	hash_init(hTxn,0);

	hash_t* hPromo;
	hPromo = (hash_t*)  malloc (sizeof(hash_t));
	hash_init(hPromo,0);

	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);

	if(iRet==SUCCESS){
		iRet = clear_non_promoted();
	}

	if(iRet==SUCCESS){
		iRet = find_promo_rule(hTxn);
	}
	if(iRet==SUCCESS){
		GetField_Int(hTxn,"rule_count",&iRuleCnt);
		for(i=0; i<iRuleCnt; i++){
			hash_init(hPromo,0);
			sprintf(csTag,"merchant_id_%d",i);
			if(GetField_CString(hTxn,csTag,&csMerchantId)){
				PutField_CString(hPromo,"merchant_id",csMerchantId);
				iRet = find_promo_group(hPromo);

				if(iRet==SUCCESS){
					sprintf(csTag,"min_count_%d",i);
					GetField_Int(hTxn,csTag,&iTmp);
					PutField_Int(hPromo,"min_count",iTmp);

					sprintf(csTag,"min_amount_%d",i);
					GetField_Double(hTxn,csTag,&dTmp);
					PutField_Double(hPromo,"min_amount",dTmp);

					sprintf(csTag,"min_day_%d",i);
					GetField_Int(hTxn,csTag,&iTmp);
					PutField_Int(hPromo,"min_day",iTmp);

					iRet = find_promo_customer(hPromo,rRecordSet);
					if(iRet == PD_SKIP_OK)
						iRet=SUCCESS;
				}
				if(iRet==SUCCESS){
					iRet = process_promotion(rRecordSet);
				}
			}
			if(iRet!=SUCCESS)
				break;
		}
	}
	FREE_ME(hTxn);
	FREE_ME(hPromo);
	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);
	return iRet;
}

int clear_non_promoted()
{

	/* EXEC SQL WHENEVER SQLERROR GOTO delete_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                short   hv_return_value;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("clear_non_promoted: Begin\n"));


       /* EXEC SQL EXECUTE
                BEGIN
			:hv_return_value := sp_customer_grp_pmlist_delete();

                END;
        END-EXEC; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 12;
       sqlstm.arrsiz = 1;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.stmt = "begin :hv_return_value := sp_customer_grp_pmlist_dele\
te ( ) ; END ;";
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
       if (sqlca.sqlcode < 0) goto delete_error;
}



DEBUGLOG(("clear_non_promoted:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("clear_non_promoted:Normal Exit\n"));
                return SUCCESS;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("customer_group_promo: clear_non_promoted: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("clear_non_promoted: SP_OTHER_ERR TxnAbort\n"));
                return PD_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("customer_group_promo: clear_non_promoted: SP_ERR TxnAbort\n");
DEBUGLOG(("clear_non_promoted: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

delete_error:
DEBUGLOG(("delete_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("customer_group_promo: clear_non_promoted: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int find_promo_rule(hash_t* hTxn)
{
	int	iCnt = 0;
	char csTag[PD_TAG_LEN+1];

DEBUGLOG(("find_promo_rule: Begin\n"));
	/* EXEC SQL WHENEVER SQLERROR GOTO find_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		int	v_min_count;
		double	v_min_amount;
		int	v_min_day;

		short   ind_merchant_id= -1;
		short   ind_min_count = -1;
		short   ind_min_amount = -1;
		short   ind_min_day = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	/* EXEC SQL DECLARE c_cursor_getallcodes CURSOR FOR
		SELECT  cpr_merchant_id,
			cpr_min_count,
			cpr_min_amount,
			cpr_min_day
		FROM    customer_group_promo_rule
		WHERE   cpr_disabled = 0; */ 


	/* EXEC SQL OPEN c_cursor_getallcodes; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )24;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto find_error;
}


	do {

		/* EXEC SQL FETCH c_cursor_getallcodes
		INTO
			:v_merchant_id:ind_merchant_id,
			:v_min_count:ind_min_count,
			:v_min_amount:ind_min_amount,
			:v_min_day:ind_min_day; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )39;
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
  sqlstm.sqhstv[1] = (unsigned char  *)&v_min_count;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_min_count;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_min_amount;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_min_amount;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_min_day;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_min_day;
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
  if (sqlca.sqlcode < 0) goto find_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		if (ind_merchant_id>= 0) {
			v_merchant_id.arr[v_merchant_id.len] ='\0';
			sprintf(csTag,"merchant_id_%d",iCnt);
			PutField_CString(hTxn,csTag,(const char*)v_merchant_id.arr);
DEBUGLOG(("find_promo_rule :[%d] merchant_id = [%s]\n",iCnt,v_merchant_id.arr));
		}

		if(ind_min_count<0)
			v_min_count = 0;
		sprintf(csTag,"min_count_%d",iCnt);
		PutField_Int(hTxn,csTag,v_min_count);
DEBUGLOG(("find_promo_rule :[%d] min_count = [%d]\n",iCnt,v_min_count));

		if(ind_min_amount<0)
			v_min_amount = 0;
		sprintf(csTag,"min_amount_%d",iCnt);
		PutField_Double(hTxn,csTag,v_min_amount);
DEBUGLOG(("find_promo_rule :[%d] min_amount = [%lf]\n",iCnt,v_min_amount));

		if(ind_min_day<0)
			v_min_day = 0;
		sprintf(csTag,"min_day_%d",iCnt);
		PutField_Int(hTxn,csTag,v_min_day);
DEBUGLOG(("find_promo_rule :[%d] min_day = [%d]\n",iCnt,v_min_day));

		iCnt ++;
		PutField_Int(hTxn,"rule_count",iCnt);
	}
	while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getallcodes; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )70;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto find_error;
}




	if(iCnt==0){
DEBUGLOG(("find_promo_rule Record Not Found!\n"));
		return PD_SKIP_OK;
	}
	else{
DEBUGLOG(("find_promo_rule Record Found!\n"));
		return SUCCESS;
	}

find_error:
DEBUGLOG(("find_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("switch_service::find_error code %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getallcodes; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )85;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}


int find_promo_group(hash_t* hTxn)
{
	char	*csTmp;

DEBUGLOG(("find_promo_group: Begin\n"));
	/* EXEC SQL WHENEVER SQLERROR GOTO findg_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar v_from_group[PD_CUSTOMER_GROUP_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_from_group;

		int	v_to_group_cnt;

		short   ind_from_group = -1;
		short   ind_to_group_cnt = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hTxn,"merchant_id",&csTmp)) {
		hv_merchant_id.len = strlen(csTmp);
		memcpy(hv_merchant_id.arr,csTmp,hv_merchant_id.len);
DEBUGLOG(("find_promo_group: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        }

	/* EXEC SQL DECLARE c_cursor_getgrp CURSOR FOR
		SELECT  
			cgr_from_group_code,
			count(cgr_group_code)
		FROM    customer_group_rules
		WHERE   cgr_disabled = 0
		AND	cgr_merchant_id = :hv_merchant_id
		AND	cgr_from_group_code is not NULL
		GROUP BY cgr_from_group_code; */ 


	/* EXEC SQL OPEN c_cursor_getgrp; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )100;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[0] = (unsigned long )17;
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
 if (sqlca.sqlcode < 0) goto findg_error;
}


	do {

		/* EXEC SQL FETCH c_cursor_getgrp
		INTO
			:v_from_group:ind_from_group,
			:v_to_group_cnt:ind_to_group_cnt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )119;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_from_group;
  sqlstm.sqhstl[0] = (unsigned long )13;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_from_group;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_to_group_cnt;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_to_group_cnt;
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
  if (sqlca.sqlcode < 0) goto findg_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		if (ind_from_group>= 0) {
			v_from_group.arr[v_from_group.len] ='\0';
			PutField_CString(hTxn,"from_group",(const char*)v_from_group.arr);
DEBUGLOG(("find_promo_group :from_group = [%s]\n",v_from_group.arr));
		}

		if (ind_to_group_cnt < 0)
			v_to_group_cnt = 0;
DEBUGLOG(("find_promo_group :to_group_cnt = [%d]\n",v_to_group_cnt));

	}
	while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getgrp; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )142;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto findg_error;
}




	if(v_to_group_cnt==0){
DEBUGLOG(("find_promo_group Record Not Found!\n"));
		return PD_SKIP_OK;
	}
	else{
DEBUGLOG(("find_promo_group Record Found!\n"));
		return SUCCESS;
	}

findg_error:
DEBUGLOG(("findg_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("customer_group_promo::findg_error code %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getgrp; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )157;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}


int find_promo_customer(hash_t* hTxn,recordset_t *myRec)
{
	int	iCnt = 0;
	hash_t *myHash;
	char	*csTmp;
	int	iTmp;
	double	dTmp;

DEBUGLOG(("find_promo_customer: Begin\n"));
	recordset_init(myRec,0);

	/* EXEC SQL WHENEVER SQLERROR GOTO findc_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_merchant_id;

		/* varchar hv_from_group[PD_CUSTOMER_GROUP_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } hv_from_group;

		int	hv_min_count;
		double	hv_min_amount;
		int	hv_min_day;

		/* varchar v_customer_id[PD_CUSTOMER_TAG_LEN+ 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_customer_id;


		short   ind_customer_id= -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hTxn,"merchant_id",&csTmp)) {
		hv_merchant_id.len = strlen(csTmp);
		memcpy(hv_merchant_id.arr,csTmp,hv_merchant_id.len);
		hv_merchant_id.arr[hv_merchant_id.len] = '\0';
DEBUGLOG(("find_promo_customer: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        }

	if (GetField_CString(hTxn,"from_group",&csTmp)) {
		hv_from_group.len = strlen(csTmp);
		memcpy(hv_from_group.arr,csTmp,hv_from_group.len);
		hv_from_group.arr[hv_from_group.len] = '\0';
DEBUGLOG(("find_promo_customer: from_group = [%.*s]\n",hv_from_group.len,hv_from_group.arr));
        }

	if (GetField_Int(hTxn,"min_count",&iTmp)) {
		hv_min_count= iTmp;
DEBUGLOG(("find_promo_customer: min_count = [%d]\n",hv_min_count));
        }

	if (GetField_Double(hTxn,"min_amount",&dTmp)) {
		hv_min_amount= dTmp;
DEBUGLOG(("find_promo_customer: min_amount = [%lf]\n",hv_min_amount));
        }

	if (GetField_Int(hTxn,"min_day",&iTmp)) {
		hv_min_day= iTmp;
DEBUGLOG(("find_promo_customer: min_day = [%d]\n",hv_min_day));
        }

	/* EXEC SQL DECLARE c_cursor_getcust CURSOR FOR
/o
		select	td_customer_tag
		from	customer_group_detail,
			(SELECT	td_customer_tag, 
				count(th_txn_id) as count, 
				sum(th_transaction_amount) as amount
			FROM (SELECT th_txn_id, th_transaction_amount, td_customer_tag 
                    		FROM customer_group_detail,
                 	     	    (SELECT th_txn_id,
                         	     	    th_transaction_amount,
					    td_customer_tag
				     FROM txn_header, txn_detail
				     WHERE th_txn_code = 'DSI'
				     AND th_ar_ind = 'A'
				     AND th_merchant_id = :hv_merchant_id
				     AND th_txn_id = td_txn_id
				     AND td_customer_group = :hv_from_group)
                    	 	WHERE cgd_cust_id = td_customer_tag
			 	AND  cgd_code = :hv_from_group
			 	AND  cgd_merchant_id = :hv_merchant_id
				and (select cgl_cust_id from customer_group_promo_list where cgl_cust_id = td_customer_tag) is NULL
			      )
 			group by td_customer_tag)
 		where	count >= :hv_min_count
 		and	amount >= :hv_min_amount
		and	cgd_cust_id = td_customer_tag
		and	to_date((select min(th_host_posting_date)
				from txn_header, txn_detail
				where th_txn_id = td_txn_id 
				and th_txn_code = 'DSI'
				and th_ar_ind = 'A'
				AND td_customer_group = :hv_from_group
				and td_customer_tag = cgd_cust_id), 'YYYYMMDD') + :hv_min_day <= to_date((select sys_val from system_control where sys_code = 'CTPHDATE'),'YYYYMMDD');
o/
		SELECT	td_customer_tag
		FROM  txn_header , txn_detail ,  customer_group_detail
		WHERE th_txn_code = 'DSI'
		AND th_ar_ind = 'A'
		AND th_txn_id = td_txn_id
		AND th_merchant_id= :hv_merchant_id
		and td_customer_group = :hv_from_group
		and td_customer_tag = cgd_cust_id
		and cgd_code = :hv_from_group
		AND cgd_merchant_id = :hv_merchant_id
		and not exists (select null
				from customer_group_promo_list
				where cgl_cust_id = td_customer_tag)
		group by td_customer_tag
		having count ( th_txn_id )>= :hv_min_count
		and sum ( th_transaction_amount ) >= :hv_min_amount
		and min ( th_host_posting_date ) <=  (select to_char(to_date ( sys_val , 'YYYYMMDD' ) - :hv_min_day,'yyyymmdd') from system_control  where  sys_code = 'CTPHDATE' ); */ 


	/* EXEC SQL OPEN c_cursor_getcust; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0004;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )172;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[0] = (unsigned long )18;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_from_group;
 sqlstm.sqhstl[1] = (unsigned long )13;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_from_group;
 sqlstm.sqhstl[2] = (unsigned long )13;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[3] = (unsigned long )18;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_min_count;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_min_amount;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_min_day;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto findc_error;
}


	do {

		/* EXEC SQL FETCH c_cursor_getcust
		INTO
			:v_customer_id:ind_customer_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )215;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_customer_id;
  sqlstm.sqhstl[0] = (unsigned long )13;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_customer_id;
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
  if (sqlca.sqlcode < 0) goto findc_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

		PutField_CString(myHash,"merchant_id",(const char*)hv_merchant_id.arr);
		PutField_CString(myHash,"from_group",(const char*)hv_from_group.arr);

		if (ind_customer_id>= 0) {
			v_customer_id.arr[v_customer_id.len] ='\0';
			PutField_CString(myHash,"customer_id",(const char*)v_customer_id.arr);
DEBUGLOG(("find_promo_customer : customer_id = [%s]\n",v_customer_id.arr));
		}

		iCnt ++;
		RecordSet_Add(myRec,myHash);
	}
	while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getcust; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )234;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto findc_error;
}




	if(iCnt==0){
DEBUGLOG(("find_promo_customer Record Not Found!\n"));
		return PD_SKIP_OK;
	}
	else{
DEBUGLOG(("find_promo_customer Record Found!\n"));
		return SUCCESS;
	}

findc_error:
DEBUGLOG(("findc_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("customer_group_promo::findc_error code %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getcust; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 7;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )249;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}


int process_promotion(recordset_t *rRecordSet)
{
	char *csMerchantId;
	char *csCustId;
	char *csFromGroup;
	hash_t* hRec, *hTxn;
	
DEBUGLOG(("process_promotion\n"));
	hTxn = (hash_t*)  malloc (sizeof(hash_t));
	hash_init(hTxn,0);

	hRec = RecordSet_GetFirst(rRecordSet);
	while (hRec) {
		hash_init(hTxn,0);
		if(GetField_CString(hRec,"merchant_id",&csMerchantId)){
			PutField_CString(hTxn,"merchant_id",csMerchantId);
		}
		if(GetField_CString(hRec,"customer_id",&csCustId)){
			PutField_CString(hTxn,"customer_tag",csCustId);
		}
		if(GetField_CString(hRec,"from_group",&csFromGroup)){
			PutField_CString(hTxn,"from_group",csFromGroup);
		}

		PutField_CString(hTxn,"create_user",PD_UPDATE_USER);

		//insert to promo table
DEBUGLOG(("process_promotion: Call DBCustomerGroupPromoList:Add [%s][%s][%s]\n",csMerchantId,csCustId,csFromGroup));
		DBObjPtr = CreateObj(DBPtr,"DBCustomerGroupPromoList","Add");
                if ((unsigned long)(DBObjPtr)(hTxn) != PD_OK) {
DEBUGLOG(("process_promotion: DBCustomerGroupPromoList: Add Failed!!!!\n"));
		}

		hRec = RecordSet_GetNext(rRecordSet);
	}


	FREE_ME(hTxn);
DEBUGLOG(("process_promotion Normal Exit\n"));
	return SUCCESS;
}
