
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
           char  filnam[14];
};
static struct sqlcxp sqlfpn =
{
    13,
    "OLPspCosts.pc"
};


static unsigned int sqlctx = 642835;


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
   unsigned char  *sqhstv[18];
   unsigned long  sqhstl[18];
            int   sqhsts[18];
            short *sqindv[18];
            int   sqinds[18];
   unsigned long  sqharm[18];
   unsigned long  *sqharc[18];
   unsigned short  sqadto[18];
   unsigned short  sqtdso[18];
} sqlstm = {12,18};

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
"select opc_rule_id , opc_party_type , opc_party_id , opc_cat_id , opcc_txn_\
code , opcc_gen_txn_code , opcc_amt_type , opc_cal_method , opc_charge_period\
_type , opc_grouping_type , opc_costing_method , opc_value , opc_additional_v\
alue , opc_min_value , opc_max_value , opc_value_type , opc_scale , opc_disab\
led from ol_psp_costs , ol_psp_costs_category where opc_rule_id = :b0 and opc\
_cat_id = opcc_cat_id and opcc_txn_code = :b1            ";

 static char *sq0003 = 
"SELECT OPC_GROUPING_TYPE FROM OL_PSP_COSTS WHERE OPC_RULE_ID = :b0         \
   ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,0,0,0,56,139,0,0,1,1,0,1,0,3,102,0,0,
24,0,0,1,193,0,6,140,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,2,
102,0,0,
63,0,0,0,0,0,13,174,0,0,18,1,0,1,0,1,102,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,1,0,0,2,1,0,0,2,1,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,1,0,0,2,3,0,0,
150,0,0,0,0,0,15,305,0,0,1,1,0,1,0,1,102,0,0,
169,0,0,0,0,0,78,306,0,0,1,1,0,1,0,3,102,0,0,
188,0,0,0,0,0,15,314,0,0,1,1,0,1,0,1,102,0,0,
207,0,0,0,0,0,78,315,0,0,1,1,0,1,0,3,102,0,0,
226,0,0,0,0,0,15,326,0,0,1,1,0,1,0,1,102,0,0,
245,0,0,0,0,0,78,327,0,0,1,1,0,1,0,3,102,0,0,
264,0,0,2,440,0,9,433,0,2049,2,2,0,1,0,1,3,0,0,1,9,0,0,
287,0,0,2,0,0,13,435,0,0,18,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,1,0,0,2,1,0,0,2,1,0,0,2,1,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2,1,0,0,2,3,0,0,2,3,0,0,
374,0,0,2,0,0,15,582,0,0,0,0,0,1,0,
389,0,0,2,0,0,15,592,0,0,0,0,0,1,0,
404,0,0,3,78,0,9,616,0,2049,1,1,0,1,0,1,3,0,0,
423,0,0,3,0,0,13,618,0,0,1,0,0,1,0,2,1,0,0,
442,0,0,3,0,0,15,634,0,0,0,0,0,1,0,
457,0,0,3,0,0,15,644,0,0,0,0,0,1,0,
472,0,0,4,602,0,6,808,0,0,18,18,0,1,0,2,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,1,0,
0,1,3,0,0,1,3,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/12/22              Dirk Wong
Remove check disabled on GetOLPspCostsById	   2015/02/13		   Dirk Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "OLPspCosts.h"
#include "common.h"
#include "internal.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void OLPspCosts(char    cdebug)
{
        cDebug = cdebug;
}

int GetOLPspCostsByParty(const hash_t* hRls, hash_t* myHash)
{
	int iRet = PD_NOT_FOUND;
        //hash_t *myHash;

	char*	csTmp;
	int	iCnt;

        /* EXEC SQL WHENEVER SQLERROR GOTO getolpspcostsbyparty_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		short		hv_return_value;

                /* varchar         hv_provider_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_provider_id;

                /* varchar         hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar		hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

		/* varchar		hv_org_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_org_txn_code;


		short		ind_provider_id = -1;
		short		ind_psp_id = -1;
		short		ind_baid = -1;
		short		ind_org_txn_code = -1;

		int		v_rule_id;
		/* varchar		v_party_type[PD_OFL_PARTY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_party_type;

		/* varchar		v_party_id[PD_BAID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_party_id;

		/* varchar		v_cat_id[PD_TAG_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_cat_id;

		/* varchar		v_txn_code[PD_TXN_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

		/* varchar		v_gen_txn_code[PD_TXN_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_gen_txn_code;

		/* varchar		v_amt_type[PD_AMT_TYPE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_amt_type;

		char		v_cal_method;
                char            v_charge_period_type;
		char		v_grouping_type;
		char		v_costing_method;
                double          v_value;
                double          v_additional_value;
		double		v_min_value;
		double		v_max_value;
		char		v_value_type;
		int		v_scale;

		short		ind_rule_id = -1;
		short		ind_party_type = -1;
		short		ind_party_id = -1;
		short		ind_cat_id = -1;
		short		ind_txn_code = -1;
		short		ind_gen_txn_code = -1;
		short		ind_amt_type = -1;
		short		ind_cal_method = -1;
                short           ind_charge_period_type = -1;
		short		ind_grouping_type = -1;
		short		ind_costing_method = -1;
                short           ind_value = -1;
                short           ind_additional_value = -1;
		short		ind_min_value = -1;
		short		ind_max_value = -1;
		short		ind_value_type = -1;
		short		ind_scale = -1;

		SQL_CURSOR      c_cursor_olpspcosts;
        /* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls,"provider_id",&csTmp)) {
		hv_provider_id.len = strlen(csTmp);
		memcpy(hv_provider_id.arr,csTmp,hv_provider_id.len);
DEBUGLOG(("GetOLPspCostsByParty provider_id = [%.*s]\n",hv_provider_id.len,hv_provider_id.arr));
		ind_provider_id = 0;
	} else {
		iRet = INT_ERR;
DEBUGLOG(("GetOLPspCostsByParty provider_id NOT FOUND!\n"));
ERRLOG("OLPspCosts::GetOLPspCostsByParty provider_id NOT FOUND!\n");
	}

	if (GetField_CString(hRls,"psp_id",&csTmp)) {
		hv_psp_id.len = strlen(csTmp);
		memcpy(hv_psp_id.arr,csTmp,hv_psp_id.len);
DEBUGLOG(("GetOLPspCostsByParty psp_id = [%.*s]\n",hv_psp_id.len,hv_psp_id.arr));
		ind_psp_id = 0;
	} else {
		iRet = INT_ERR;
DEBUGLOG(("GetOLPspCostsByParty psp_id NOT FOUND!\n"));
ERRLOG("OLPspCosts::GetOLPspCostsByParty psp_id NOT FOUND!\n");
	}

	if (GetField_CString(hRls,"baid",&csTmp)) {
		hv_baid.len = strlen(csTmp);
		memcpy(hv_baid.arr,csTmp,hv_baid.len);
DEBUGLOG(("GetOLPspCostsByParty baid = [%.*s]\n",hv_baid.len,hv_baid.arr));
		ind_baid = 0;
	} else {
		iRet = INT_ERR;
DEBUGLOG(("GetOLPspCostsByParty baid NOT FOUND!\n"));
ERRLOG("OLPspCosts::GetOLPspCostsByParty baid NOT FOUND!\n");
	}

	if (GetField_CString(hRls,"org_txn_code",&csTmp)) {
		hv_org_txn_code.len = strlen(csTmp);
		memcpy(hv_org_txn_code.arr,csTmp,hv_org_txn_code.len);
DEBUGLOG(("GetOLPspCostsByParty org_txn_code = [%.*s]\n",hv_org_txn_code.len,hv_org_txn_code.arr));
		ind_org_txn_code = 0;
	} else {
		iRet = INT_ERR;
DEBUGLOG(("GetOLPspCostsByParty org_txn_code NOT FOUND!\n"));
ERRLOG("OLPspCosts::GetOLPspCostsByParty org_txn_code NOT FOUND!\n");
	}

	/* EXEC SQL ALLOCATE :c_cursor_olpspcosts; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_olpspcosts;
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
 if (sqlca.sqlcode < 0) goto getolpspcostsbyparty_error;
}


	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_psp_costs_find(:hv_provider_id:ind_provider_id,
								:hv_psp_id:ind_psp_id,
								:hv_baid:ind_baid,
								:hv_org_txn_code:ind_org_txn_code,
								:c_cursor_olpspcosts);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_psp_costs_find ( :hv_provid\
er_id:ind_provider_id , :hv_psp_id:ind_psp_id , :hv_baid:ind_baid , :hv_org_t\
xn_code:ind_org_txn_code , :c_cursor_olpspcosts ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )24;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_provider_id;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_provider_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[2] = (unsigned long )12;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_psp_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_baid;
 sqlstm.sqhstl[3] = (unsigned long )22;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_baid;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_org_txn_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_org_txn_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&c_cursor_olpspcosts;
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
 if (sqlca.sqlcode < 0) goto getolpspcostsbyparty_error;
}



DEBUGLOG(("Find open cursor ++++++++++++++++++++++++++++++++++++++\n"));
	if (hv_return_value > 0)  {
DEBUGLOG(("Find Found\n"));
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

		for (;;) {

			ind_rule_id = -1;
			ind_party_type = -1;
			ind_party_id = -1;
			ind_cat_id = -1;
			ind_txn_code = -1;
			ind_gen_txn_code = -1;
			ind_amt_type = -1;
			ind_cal_method = -1;
                	ind_charge_period_type = -1;
			ind_grouping_type = -1;
			ind_costing_method = -1;
                        ind_value = -1;
                        ind_additional_value = -1;
			ind_min_value = -1;
			ind_max_value = -1;
			ind_value_type = -1;
			ind_scale = -1;

			/* EXEC SQL FETCH :c_cursor_olpspcosts
			INTO	:v_rule_id:ind_rule_id,
				:v_party_type:ind_party_type,
				:v_party_id:ind_party_id,
				:v_cat_id:ind_cat_id,
				:v_txn_code:ind_txn_code,
				:v_gen_txn_code:ind_gen_txn_code,
				:v_amt_type:ind_amt_type,
				:v_cal_method:ind_cal_method,
        	                :v_charge_period_type:ind_charge_period_type,
				:v_grouping_type:ind_grouping_type,
				:v_costing_method:ind_costing_method,
        	                :v_value:ind_value,
        	                :v_additional_value:ind_additional_value,
				:v_min_value:ind_min_value,
				:v_max_value:ind_max_value,
				:v_value_type:ind_value_type,
				:v_scale:ind_scale; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 18;
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
   sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_olpspcosts;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_rule_id;
   sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_rule_id;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_party_type;
   sqlstm.sqhstl[2] = (unsigned long )9;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_party_type;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_party_id;
   sqlstm.sqhstl[3] = (unsigned long )23;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_party_id;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_cat_id;
   sqlstm.sqhstl[4] = (unsigned long )28;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_cat_id;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_txn_code;
   sqlstm.sqhstl[5] = (unsigned long )6;
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_txn_code;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&v_gen_txn_code;
   sqlstm.sqhstl[6] = (unsigned long )6;
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_gen_txn_code;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&v_amt_type;
   sqlstm.sqhstl[7] = (unsigned long )5;
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         short *)&ind_amt_type;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
   sqlstm.sqhstv[8] = (unsigned char  *)&v_cal_method;
   sqlstm.sqhstl[8] = (unsigned long )1;
   sqlstm.sqhsts[8] = (         int  )0;
   sqlstm.sqindv[8] = (         short *)&ind_cal_method;
   sqlstm.sqinds[8] = (         int  )0;
   sqlstm.sqharm[8] = (unsigned long )0;
   sqlstm.sqadto[8] = (unsigned short )0;
   sqlstm.sqtdso[8] = (unsigned short )0;
   sqlstm.sqhstv[9] = (unsigned char  *)&v_charge_period_type;
   sqlstm.sqhstl[9] = (unsigned long )1;
   sqlstm.sqhsts[9] = (         int  )0;
   sqlstm.sqindv[9] = (         short *)&ind_charge_period_type;
   sqlstm.sqinds[9] = (         int  )0;
   sqlstm.sqharm[9] = (unsigned long )0;
   sqlstm.sqadto[9] = (unsigned short )0;
   sqlstm.sqtdso[9] = (unsigned short )0;
   sqlstm.sqhstv[10] = (unsigned char  *)&v_grouping_type;
   sqlstm.sqhstl[10] = (unsigned long )1;
   sqlstm.sqhsts[10] = (         int  )0;
   sqlstm.sqindv[10] = (         short *)&ind_grouping_type;
   sqlstm.sqinds[10] = (         int  )0;
   sqlstm.sqharm[10] = (unsigned long )0;
   sqlstm.sqadto[10] = (unsigned short )0;
   sqlstm.sqtdso[10] = (unsigned short )0;
   sqlstm.sqhstv[11] = (unsigned char  *)&v_costing_method;
   sqlstm.sqhstl[11] = (unsigned long )1;
   sqlstm.sqhsts[11] = (         int  )0;
   sqlstm.sqindv[11] = (         short *)&ind_costing_method;
   sqlstm.sqinds[11] = (         int  )0;
   sqlstm.sqharm[11] = (unsigned long )0;
   sqlstm.sqadto[11] = (unsigned short )0;
   sqlstm.sqtdso[11] = (unsigned short )0;
   sqlstm.sqhstv[12] = (unsigned char  *)&v_value;
   sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[12] = (         int  )0;
   sqlstm.sqindv[12] = (         short *)&ind_value;
   sqlstm.sqinds[12] = (         int  )0;
   sqlstm.sqharm[12] = (unsigned long )0;
   sqlstm.sqadto[12] = (unsigned short )0;
   sqlstm.sqtdso[12] = (unsigned short )0;
   sqlstm.sqhstv[13] = (unsigned char  *)&v_additional_value;
   sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[13] = (         int  )0;
   sqlstm.sqindv[13] = (         short *)&ind_additional_value;
   sqlstm.sqinds[13] = (         int  )0;
   sqlstm.sqharm[13] = (unsigned long )0;
   sqlstm.sqadto[13] = (unsigned short )0;
   sqlstm.sqtdso[13] = (unsigned short )0;
   sqlstm.sqhstv[14] = (unsigned char  *)&v_min_value;
   sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[14] = (         int  )0;
   sqlstm.sqindv[14] = (         short *)&ind_min_value;
   sqlstm.sqinds[14] = (         int  )0;
   sqlstm.sqharm[14] = (unsigned long )0;
   sqlstm.sqadto[14] = (unsigned short )0;
   sqlstm.sqtdso[14] = (unsigned short )0;
   sqlstm.sqhstv[15] = (unsigned char  *)&v_max_value;
   sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[15] = (         int  )0;
   sqlstm.sqindv[15] = (         short *)&ind_max_value;
   sqlstm.sqinds[15] = (         int  )0;
   sqlstm.sqharm[15] = (unsigned long )0;
   sqlstm.sqadto[15] = (unsigned short )0;
   sqlstm.sqtdso[15] = (unsigned short )0;
   sqlstm.sqhstv[16] = (unsigned char  *)&v_value_type;
   sqlstm.sqhstl[16] = (unsigned long )1;
   sqlstm.sqhsts[16] = (         int  )0;
   sqlstm.sqindv[16] = (         short *)&ind_value_type;
   sqlstm.sqinds[16] = (         int  )0;
   sqlstm.sqharm[16] = (unsigned long )0;
   sqlstm.sqadto[16] = (unsigned short )0;
   sqlstm.sqtdso[16] = (unsigned short )0;
   sqlstm.sqhstv[17] = (unsigned char  *)&v_scale;
   sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[17] = (         int  )0;
   sqlstm.sqindv[17] = (         short *)&ind_scale;
   sqlstm.sqinds[17] = (         int  )0;
   sqlstm.sqharm[17] = (unsigned long )0;
   sqlstm.sqadto[17] = (unsigned short )0;
   sqlstm.sqtdso[17] = (unsigned short )0;
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
   if (sqlca.sqlcode == 1403) break;
   if (sqlca.sqlcode < 0) goto getolpspcostsbyparty_error;
}



			iCnt++;

        	        iRet = PD_FOUND;

		/* rule_id */
			if (ind_rule_id >= 0) {
				PutField_Int(myHash,"rule_id",v_rule_id);
DEBUGLOG(("GetOLPspCostsByParty rule_id = [%d]\n",v_rule_id));
			}

		/* party_type */
			if (ind_party_type >= 0) {
				v_party_type.arr[v_party_type.len] = '\0';
				PutField_CString(myHash,"party_type",(const char*)v_party_type.arr);
DEBUGLOG(("GetOLPspCostsByParty party_type = [%s]\n",(const char*)v_party_type.arr));
			}

		/* party_id */
			if (ind_party_id >= 0) {
				v_party_id.arr[v_party_id.len] = '\0';
				PutField_CString(myHash,"party_id",(const char*)v_party_id.arr);
DEBUGLOG(("GetOLPspCostsByParty party_id = [%s]\n",(const char*)v_party_id.arr));
			}

		/* cat_id */
			if (ind_cat_id >= 0) {
				v_cat_id.arr[v_cat_id.len] = '\0';
				PutField_CString(myHash,"cat_id",(const char*)v_cat_id.arr);
DEBUGLOG(("GetOLPspCostsByParty cat_id = [%s]\n",(const char*)v_cat_id.arr));
			}

		/* txn_code */
			if (ind_txn_code >= 0) {
				v_txn_code.arr[v_txn_code.len] = '\0';
				PutField_CString(myHash,"txn_code",(const char*)v_txn_code.arr);
DEBUGLOG(("GetOLPspCostsByParty txn_code = [%s]\n",(const char*)v_txn_code.arr));
			}

		/* gen_txn_code */
			if (ind_gen_txn_code >= 0) {
				v_gen_txn_code.arr[v_gen_txn_code.len] = '\0';
				PutField_CString(myHash,"gen_txn_code",(const char*)v_gen_txn_code.arr);
DEBUGLOG(("GetOLPspCostsByParty gen_txn_code = [%s]\n",(const char*)v_gen_txn_code.arr));
			}

		/* amt_type */
			if (ind_amt_type >= 0) {
				v_amt_type.arr[v_amt_type.len] = '\0';
				PutField_CString(myHash,"amt_type",(const char*)v_amt_type.arr);
DEBUGLOG(("GetOLPspCostsByParty amt_type = [%s]\n",(const char*)v_amt_type.arr));
			}

		/* cal_method */
	                if (ind_cal_method >= 0) {
	                        PutField_Char(myHash,"cal_method",v_cal_method);
DEBUGLOG(("GetOLPspCostsByParty cal_method = [%c]\n",v_cal_method));
	                }

		/* charge_period_type */
	                if (ind_charge_period_type >= 0) {
	                        PutField_Char(myHash,"charge_period_type",v_charge_period_type);
DEBUGLOG(("GetOLPspCostsByParty charge_period_type = [%c]\n",v_charge_period_type));
	                }

		/* grouping_type */
			if (ind_grouping_type >= 0) {
				PutField_Char(myHash,"grouping_type",v_grouping_type);
DEBUGLOG(("GetOLPspCostsByParty grouping_type = [%c]\n",v_grouping_type));
			}

		/* costing_method */
			if (ind_costing_method >= 0) {
				PutField_Char(myHash,"costing_method",v_costing_method);
DEBUGLOG(("GetOLPspCostsByParty costing_method = [%c]\n",v_costing_method));
			}

		/* value */
	                if (ind_value >= 0) {
	                        PutField_Double(myHash,"value",v_value);
DEBUGLOG(("GetOLPspCostsByParty value = [%f]\n",v_value));
	                }

		/* additional_value */
	                if (ind_additional_value >= 0) {
	                        PutField_Double(myHash,"add_value",v_additional_value);
DEBUGLOG(("GetOLPspCostsByParty additional_value = [%f]\n",v_additional_value));
	                }

		/* min_value */
	                if (ind_min_value >= 0) {
	                        PutField_Double(myHash,"min_value",v_min_value);
DEBUGLOG(("GetOLPspCostsByParty min_value = [%f]\n",v_min_value));
	                }

		/* max_value */
	                if (ind_max_value >= 0) {
	                        PutField_Double(myHash,"max_value",v_max_value);
DEBUGLOG(("GetOLPspCostsByParty max_value = [%f]\n",v_max_value));
	                }

		/* value_type */
			if (ind_value_type >= 0) {
				PutField_Char(myHash,"value_type",v_value_type);
DEBUGLOG(("GetOLPspCostsByParty value_type = [%c]\n",v_value_type));
		}

		/* scale */
			if (ind_scale >= 0) {
				PutField_Int(myHash,"scale",v_scale);
DEBUGLOG(("GetOLPspCostsByParty scale = [%d]\n",v_scale));
	                }
	        }
		/* EXEC SQL CLOSE :c_cursor_olpspcosts; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 18;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )150;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_olpspcosts;
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
  if (sqlca.sqlcode < 0) goto getolpspcostsbyparty_error;
}


	        /* EXEC SQL FREE :c_cursor_olpspcosts; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 18;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.stmt = "";
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )169;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_olpspcosts;
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
         if (sqlca.sqlcode < 0) goto getolpspcostsbyparty_error;
}


DEBUGLOG(("Find Close cursor-------------------------------------\n"));

		return iRet;
	}
	else
	{
DEBUGLOG(("Find Not Found\n"));
		/* EXEC SQL CLOSE :c_cursor_olpspcosts; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 18;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )188;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_olpspcosts;
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
  if (sqlca.sqlcode < 0) goto getolpspcostsbyparty_error;
}


		/* EXEC SQL FREE :c_cursor_olpspcosts; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 18;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )207;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_olpspcosts;
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
  if (sqlca.sqlcode < 0) goto getolpspcostsbyparty_error;
}


DEBUGLOG(("Find Close cursor\n"));

		return PD_ERR;
	}

getolpspcostsbyparty_error:
DEBUGLOG(("getolpspcostsbyparty_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("GetOLPspCostsByParty: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE :c_cursor_olpspcosts; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )226;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_olpspcosts;
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
}


	/* EXEC SQL FREE :c_cursor_olpspcosts; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )245;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_olpspcosts;
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
}


        return PD_NOT_FOUND;
}

int GetOLPspCostsById(const hash_t* hRls, hash_t* hResponse)
{
	int iRet = PD_NOT_FOUND;
        //hash_t *myHash;

	char*	csTmp;
	int	iTmp;
	int	iCnt;

        /* EXEC SQL WHENEVER SQLERROR GOTO getolpspcostsbyid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		int		hv_rule_id;
		/* varchar		hv_org_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_org_txn_code;

		int		hv_disabled;

		int		v_rule_id;
		/* varchar		v_party_type[PD_OFL_PARTY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_party_type;

		/* varchar		v_party_id[PD_BAID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_party_id;

		/* varchar		v_cat_id[PD_TAG_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_cat_id;

		/* varchar		v_txn_code[PD_TXN_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

		/* varchar		v_gen_txn_code[PD_TXN_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_gen_txn_code;

		/* varchar		v_amt_type[PD_AMT_TYPE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_amt_type;

		char		v_cal_method;
                char            v_charge_period_type;
		char		v_grouping_type;
		char		v_costing_method;
                double          v_value;
                double          v_additional_value;
		double		v_min_value;
		double		v_max_value;
		char		v_value_type;
		int		v_scale;
		int		v_disabled;

		short		ind_rule_id = -1;
		short		ind_party_type = -1;
		short		ind_party_id = -1;
		short		ind_cat_id = -1;
		short		ind_txn_code = -1;
		short		ind_gen_txn_code = -1;
		short		ind_amt_type = -1;
		short		ind_cal_method = -1;
                short           ind_charge_period_type = -1;
		short		ind_grouping_type = -1;
		short		ind_costing_method = -1;
                short           ind_value = -1;
                short           ind_additional_value = -1;
		short		ind_min_value = -1;
		short		ind_max_value = -1;
		short		ind_value_type = -1;
		short		ind_scale = -1;
		short		ind_disabled = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_Int(hRls,"rule_id",&iTmp)) {
		hv_rule_id = iTmp;
DEBUGLOG(("GetOLPspCostsById rule_id = [%d]\n",hv_rule_id));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("GetOLPspCostsById rule_id NOT FOUND!\n"));
ERRLOG("OLPspCosts::GetOLPspCostsById rule_id NOT FOUND!\n");
	}

	if (GetField_CString(hRls,"org_txn_code",&csTmp)) {
		hv_org_txn_code.len = strlen(csTmp);
		memcpy(hv_org_txn_code.arr,csTmp,hv_org_txn_code.len);
DEBUGLOG(("GetOLPspCostsById org_txn_code = [%.*s]\n",hv_org_txn_code.len,hv_org_txn_code.arr));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("GetOLPspCostsById org_txn_code NOT FOUND!\n"));
ERRLOG("OLPspCosts::GetOLPspCostsById org_txn_code NOT FOUND!\n");
	}

	hv_disabled = 0;

	/* EXEC SQL DECLARE c_cursor_getolpspcostsbyid CURSOR FOR
		select	opc_rule_id,
			opc_party_type,
			opc_party_id,
			opc_cat_id,
			opcc_txn_code,
			opcc_gen_txn_code,
			opcc_amt_type,
			opc_cal_method,
			opc_charge_period_type,
			opc_grouping_type,
			opc_costing_method,
			opc_value,
			opc_additional_value,
			opc_min_value,
			opc_max_value,
			opc_value_type,
			opc_scale,
			opc_disabled
		from	ol_psp_costs,
			ol_psp_costs_category
		where	opc_rule_id = :hv_rule_id
		and	opc_cat_id = opcc_cat_id
		and	opcc_txn_code = :hv_org_txn_code; */ 


	/* EXEC SQL OPEN c_cursor_getolpspcostsbyid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )264;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_rule_id;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_org_txn_code;
 sqlstm.sqhstl[1] = (unsigned long )5;
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
 if (sqlca.sqlcode < 0) goto getolpspcostsbyid_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getolpspcostsbyid
		INTO	:v_rule_id:ind_rule_id,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_cat_id:ind_cat_id,
			:v_txn_code:ind_txn_code,
			:v_gen_txn_code:ind_gen_txn_code,
			:v_amt_type:ind_amt_type,
			:v_cal_method:ind_cal_method,
       	                :v_charge_period_type:ind_charge_period_type,
			:v_grouping_type:ind_grouping_type,
			:v_costing_method:ind_costing_method,
       	                :v_value:ind_value,
       	                :v_additional_value:ind_additional_value,
			:v_min_value:ind_min_value,
			:v_max_value:ind_max_value,
			:v_value_type:ind_value_type,
			:v_scale:ind_scale,
			:v_disabled:ind_disabled; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 18;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )287;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_rule_id;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_rule_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_party_type;
  sqlstm.sqhstl[1] = (unsigned long )9;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_party_type;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_party_id;
  sqlstm.sqhstl[2] = (unsigned long )23;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_party_id;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_cat_id;
  sqlstm.sqhstl[3] = (unsigned long )28;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_cat_id;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_txn_code;
  sqlstm.sqhstl[4] = (unsigned long )6;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_txn_code;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_gen_txn_code;
  sqlstm.sqhstl[5] = (unsigned long )6;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_gen_txn_code;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_amt_type;
  sqlstm.sqhstl[6] = (unsigned long )5;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_amt_type;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_cal_method;
  sqlstm.sqhstl[7] = (unsigned long )1;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_cal_method;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_charge_period_type;
  sqlstm.sqhstl[8] = (unsigned long )1;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_charge_period_type;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_grouping_type;
  sqlstm.sqhstl[9] = (unsigned long )1;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_grouping_type;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_costing_method;
  sqlstm.sqhstl[10] = (unsigned long )1;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_costing_method;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_value;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_value;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_additional_value;
  sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_additional_value;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_min_value;
  sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_min_value;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_max_value;
  sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_max_value;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_value_type;
  sqlstm.sqhstl[15] = (unsigned long )1;
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_value_type;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&v_scale;
  sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)&ind_scale;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)&v_disabled;
  sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)&ind_disabled;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto getolpspcostsbyid_error;
}



		iCnt++;

		//myHash = (hash_t*) malloc (sizeof(hash_t));
                //hash_init(myHash,0);

		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

       	        iRet = PD_FOUND;

	/* rule_id */
		if (ind_rule_id >= 0) {
			PutField_Int(hResponse,"rule_id",v_rule_id);
DEBUGLOG(("GetOLPspCostsById rule_id = [%d]\n",v_rule_id));
		}

	/* party_type */
		if (ind_party_type >= 0) {
			v_party_type.arr[v_party_type.len] = '\0';
			PutField_CString(hResponse,"party_type",(const char*)v_party_type.arr);
DEBUGLOG(("GetOLPspCostsById party_type = [%s]\n",(const char*)v_party_type.arr));
		}

	/* party_id */
		if (ind_party_id >= 0) {
			v_party_id.arr[v_party_id.len] = '\0';
			PutField_CString(hResponse,"party_id",(const char*)v_party_id.arr);
DEBUGLOG(("GetOLPspCostsById party_id = [%s]\n",(const char*)v_party_id.arr));
		}

	/* cat_id */
		if (ind_cat_id >= 0) {
			v_cat_id.arr[v_cat_id.len] = '\0';
			PutField_CString(hResponse,"cat_id",(const char*)v_cat_id.arr);
DEBUGLOG(("GetOLPspCostsById cat_id = [%s]\n",(const char*)v_cat_id.arr));
		}

	/* txn_code */
		if (ind_txn_code >= 0) {
			v_txn_code.arr[v_txn_code.len] = '\0';
			PutField_CString(hResponse,"txn_code",(const char*)v_txn_code.arr);
DEBUGLOG(("GetOLPspCostsById txn_code = [%s]\n",(const char*)v_txn_code.arr));
		}

	/* gen_txn_code */
		if (ind_gen_txn_code >= 0) {
			v_gen_txn_code.arr[v_gen_txn_code.len] = '\0';
			PutField_CString(hResponse,"gen_txn_code",(const char*)v_gen_txn_code.arr);
DEBUGLOG(("GetOLPspCostsById gen_txn_code = [%s]\n",(const char*)v_gen_txn_code.arr));
		}

	/* amt_type */
		if (ind_amt_type >= 0) {
			v_amt_type.arr[v_amt_type.len] = '\0';
			PutField_CString(hResponse,"amt_type",(const char*)v_amt_type.arr);
DEBUGLOG(("GetOLPspCostsById amt_type = [%s]\n",(const char*)v_amt_type.arr));
		}

	/* cal_method */
                if (ind_cal_method >= 0) {
                        PutField_Char(hResponse,"cal_method",v_cal_method);
DEBUGLOG(("GetOLPspCostsById cal_method = [%c]\n",v_cal_method));
                }

	/* charge_period_type */
                if (ind_charge_period_type >= 0) {
                        PutField_Char(hResponse,"charge_period_type",v_charge_period_type);
DEBUGLOG(("GetOLPspCostsById charge_period_type = [%c]\n",v_charge_period_type));
                }

	/* grouping_type */
		if (ind_grouping_type >= 0) {
			PutField_Char(hResponse,"grouping_type",v_grouping_type);
DEBUGLOG(("GetOLPspCostsById grouping_type = [%c]\n",v_grouping_type));
		}

	/* costing_method */
		if (ind_costing_method >= 0) {
			PutField_Char(hResponse,"costing_method",v_costing_method);
DEBUGLOG(("GetOLPspCostsById costing_method = [%c]\n",v_costing_method));
		}

	/* value */
                if (ind_value >= 0) {
                        PutField_Double(hResponse,"value",v_value);
DEBUGLOG(("GetOLPspCostsById value = [%f]\n",v_value));
                }

	/* additional_value */
                if (ind_additional_value >= 0) {
                        PutField_Double(hResponse,"add_value",v_additional_value);
DEBUGLOG(("GetOLPspCostsById additional_value = [%f]\n",v_additional_value));
                }

	/* min_value */
                if (ind_min_value >= 0) {
                        PutField_Double(hResponse,"min_value",v_min_value);
DEBUGLOG(("GetOLPspCostsById min_value = [%f]\n",v_min_value));
                }

	/* max_value */
                if (ind_max_value >= 0) {
                        PutField_Double(hResponse,"max_value",v_max_value);
DEBUGLOG(("GetOLPspCostsById max_value = [%f]\n",v_max_value));
                }

	/* value_type */
		if (ind_value_type >= 0) {
			PutField_Char(hResponse,"value_type",v_value_type);
DEBUGLOG(("GetOLPspCostsById value_type = [%c]\n",v_value_type));
	}

	/* scale */
		if (ind_scale >= 0) {
			PutField_Int(hResponse,"scale",v_scale);
DEBUGLOG(("GetOLPspCostsById scale = [%d]\n",v_scale));
                }

	/* disabled */
		if (ind_disabled >= 0) {
			PutField_Int(hResponse,"disabled",v_disabled);
DEBUGLOG(("GetOLPspCostsById disabled = [%d]\n",v_disabled));
		}
        }
	while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getolpspcostsbyid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )374;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getolpspcostsbyid_error;
}



DEBUGLOG(("GetOLPspCostsById Normal Exit\n"));
	return  iRet;

getolpspcostsbyid_error:
DEBUGLOG(("getolpspcostsbyid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("GetOlPspCostsById: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getolpspcostsbyid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )389;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_NOT_FOUND;
}

int GetGroupingTypeById(int iRuleId, char *cGroupingType) {
	int	iRet = PD_NOT_FOUND;

	/* EXEC SQL WHENEVER SQLERROR GOTO getgroupingtypebyid_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int	hv_rule_id;

		char	v_grouping_type;
		short	ind_grouping_type;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_rule_id = iRuleId;

	/* EXEC SQL DECLARE c_cursor_getgroupingtypebyid CURSOR FOR
		SELECT	OPC_GROUPING_TYPE
		FROM	OL_PSP_COSTS
		WHERE	OPC_RULE_ID = :hv_rule_id; */ 


	/* EXEC SQL OPEN c_cursor_getgroupingtypebyid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )404;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_rule_id;
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
 if (sqlca.sqlcode < 0) goto getgroupingtypebyid_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getgroupingtypebyid
		INTO	:v_grouping_type:ind_grouping_type; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 18;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )423;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_grouping_type;
  sqlstm.sqhstl[0] = (unsigned long )1;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_grouping_type;
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
  if (sqlca.sqlcode < 0) goto getgroupingtypebyid_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		if (ind_grouping_type>=0) {
			*cGroupingType = v_grouping_type;
DEBUGLOG(("GetGroupingTypeById cGroupingType = [%c]\n",v_grouping_type));
		}

		iRet = PD_FOUND;
	}
	while (PD_TRUE);
	
	/* EXEC SQL CLOSE c_cursor_getgroupingtypebyid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )442;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getgroupingtypebyid_error;
}



DEBUGLOG(("GetGroupingTypeById Normal Exit\n"));
	return iRet;

getgroupingtypebyid_error:
DEBUGLOG(("getgroupingtypebyid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("getgroupingtypebyid: SP_INTERNAL_ERR TxnAbort\n");
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getgroupingtypebyid; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 18;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )457;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_NOT_FOUND;
}

int Add(const hash_t *hRls)
{
	char	cTmp;
	char*	csTmp;
	int	iTmp;
	double	dTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int		hv_rule_id;
		/* varchar         hv_party_type[PD_OFL_PARTY_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_party_type;

                /* varchar         hv_party_id[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_party_id;

                /* varchar		hv_cat_id[PD_TAG_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_cat_id;

		/* varchar		hv_effect_date[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_effect_date;

                char            hv_cal_method;
                char            hv_charge_period_type;
                char            hv_grouping_type;
                char            hv_costing_method;
                double          hv_value;
                double          hv_additional_value;
                double          hv_min_value;
                double          hv_max_value;
                char            hv_value_type;
                int             hv_scale;
		int		hv_disabled;
		/* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_rule_id = -1;
		short		ind_party_type = -1;
		short		ind_party_id = -1;
		short		ind_cat_id = -1;
		short		ind_effect_date = -1;
                short           ind_cal_method = -1;
                short           ind_charge_period_type = -1;
                short           ind_grouping_type = -1;
                short           ind_costing_method = -1;
                short           ind_value = -1;
                short           ind_additional_value = -1;
                short           ind_min_value = -1;
                short           ind_max_value = -1;
                short           ind_value_type = -1;
                short           ind_scale = -1;
		short		ind_disabled = -1;
		short		ind_create_user = -1;

		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("Add: Begin\n"));

	if (GetField_Int(hRls,"rule_id",&iTmp)) {
		hv_rule_id = iTmp;
		ind_rule_id = 0;
DEBUGLOG(("Add: rule_id = [%d]\n",hv_rule_id));
	}

	if (GetField_CString(hRls,"party_type",&csTmp)) {
		hv_party_type.len = strlen(csTmp);
		strncpy((char*)hv_party_type.arr, csTmp, hv_party_type.len);
		ind_party_type = 0;
DEBUGLOG(("Add: party_type = [%s]\n",(char*)hv_party_type.arr));
	}

	if (GetField_CString(hRls,"party_id",&csTmp)) {
		hv_party_id.len = strlen(csTmp);
		strncpy((char*)hv_party_id.arr, csTmp, hv_party_id.len);
		ind_party_id = 0;
DEBUGLOG(("Add: party_id = [%s]\n",(char*)hv_party_id.arr));
	}

	if (GetField_CString(hRls,"cat_id",&csTmp)) {
		hv_cat_id.len = strlen(csTmp);
		strncpy((char*)hv_cat_id.arr, csTmp, hv_cat_id.len);
		ind_cat_id = 0;
DEBUGLOG(("Add: cat_id = [%s]\n",(char*)hv_cat_id.arr));
	}

	if (GetField_CString(hRls,"effect_date",&csTmp)) {
		hv_effect_date.len = strlen(csTmp);
		strncpy((char*)hv_effect_date.arr,csTmp,hv_effect_date.len);
		ind_effect_date = 0;
DEBUGLOG(("Add: effect_date = [%s]\n",(char*)hv_effect_date.arr));
	}

	if (GetField_Char(hRls, "cal_method", &cTmp)) {
                hv_cal_method = cTmp;
                ind_cal_method = 0;
DEBUGLOG(("Add: cal_method = [%c]\n",hv_cal_method));
	}

	if (GetField_Char(hRls, "charge_period_type", &cTmp)) {
                hv_charge_period_type = cTmp;
                ind_charge_period_type= 0;
DEBUGLOG(("Add: charge_period_type = [%c]\n",hv_charge_period_type));
	}

	if (GetField_Char(hRls, "grouping_type", &cTmp)) {
                hv_grouping_type = cTmp;
                ind_grouping_type = 0;
DEBUGLOG(("Add: grouping_type = [%c]\n",hv_grouping_type));
	}

	if (GetField_Char(hRls, "costing_method", &cTmp)) {
                hv_costing_method = cTmp;
                ind_costing_method = 0;
DEBUGLOG(("Add: costing_method = [%c]\n",hv_costing_method));
	}

	if (GetField_Double(hRls, "value", &dTmp)) {
		hv_value = dTmp;
		ind_value = 0;
DEBUGLOG(("Add: value = [%.f]\n",hv_value));
	}

	if (GetField_Double(hRls, "additional_value", &dTmp)) {
		hv_additional_value = dTmp;
		ind_additional_value = 0;
DEBUGLOG(("Add: additional_value = [%.f]\n",hv_additional_value));
	}

	if (GetField_Double(hRls, "min_value", &dTmp)) {
		hv_min_value = dTmp;
		ind_min_value = 0;
DEBUGLOG(("Add: min_value = [%.f]\n",hv_min_value));
	}

	if (GetField_Double(hRls, "max_value", &dTmp)) {
		hv_max_value = dTmp;
		ind_max_value = 0;
DEBUGLOG(("Add: max_value = [%.f]\n",hv_max_value));
	}

	if (GetField_Char(hRls, "value_type", &cTmp)) {
		hv_value_type = cTmp;
		ind_value_type = 0;
DEBUGLOG(("Add: value_type = [%c]\n",hv_value_type));
	}

	if (GetField_Int(hRls, "scale", &iTmp)) {
		hv_scale = iTmp;
		ind_scale = 0;
DEBUGLOG(("Add: scale = [%d]\n",hv_scale));
	}

	if (GetField_Int(hRls,"disabled",&iTmp)) {
		hv_disabled = iTmp;
		ind_disabled = 0;
DEBUGLOG(("Add: disabled = [%d]\n",hv_disabled));
	}

	if(GetField_CString(hRls,"create_user",&csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
	}
DEBUGLOG(("Add: create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_psp_costs_insert(
						:hv_rule_id:ind_rule_id,
						:hv_party_type:ind_party_type,
						:hv_party_id:ind_party_id,
						:hv_cat_id:ind_cat_id,
						:hv_effect_date:ind_effect_date,
						:hv_cal_method:ind_cal_method,
						:hv_charge_period_type:ind_charge_period_type,
						:hv_grouping_type:ind_grouping_type,
						:hv_costing_method:ind_costing_method,
						:hv_value:ind_value,
						:hv_additional_value:ind_additional_value,
						:hv_min_value:ind_min_value,
						:hv_max_value:ind_max_value,
						:hv_value_type:ind_value_type,
						:hv_scale:ind_scale,
						:hv_disabled:ind_disabled,
                                                :hv_create_user:ind_create_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_psp_costs_insert ( :hv_rule\
_id:ind_rule_id , :hv_party_type:ind_party_type , :hv_party_id:ind_party_id ,\
 :hv_cat_id:ind_cat_id , :hv_effect_date:ind_effect_date , :hv_cal_method:ind\
_cal_method , :hv_charge_period_type:ind_charge_period_type , :hv_grouping_ty\
pe:ind_grouping_type , :hv_costing_method:ind_costing_method , :hv_value:ind_\
value , :hv_additional_value:ind_additional_value , :hv_min_value:ind_min_val\
ue , :hv_max_value:ind_max_value , :hv_value_type:ind_value_type , :hv_scale:\
ind_scale , :hv_disabled:ind_disabled , :hv_create_user:ind_create_user ) ; E\
ND ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )472;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_rule_id;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_rule_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_party_type;
 sqlstm.sqhstl[2] = (unsigned long )8;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_party_type;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_party_id;
 sqlstm.sqhstl[3] = (unsigned long )22;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_party_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_cat_id;
 sqlstm.sqhstl[4] = (unsigned long )27;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_cat_id;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_effect_date;
 sqlstm.sqhstl[5] = (unsigned long )16;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_effect_date;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_cal_method;
 sqlstm.sqhstl[6] = (unsigned long )1;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_cal_method;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_charge_period_type;
 sqlstm.sqhstl[7] = (unsigned long )1;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_charge_period_type;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_grouping_type;
 sqlstm.sqhstl[8] = (unsigned long )1;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_grouping_type;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_costing_method;
 sqlstm.sqhstl[9] = (unsigned long )1;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_costing_method;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_value;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_value;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_additional_value;
 sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_additional_value;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_min_value;
 sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_min_value;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_max_value;
 sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_max_value;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_value_type;
 sqlstm.sqhstl[14] = (unsigned long )1;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_value_type;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_scale;
 sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_scale;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_disabled;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[17] = (unsigned long )22;
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&ind_create_user;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
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
ERRLOG("OLPspCosts_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	} 

	if (hv_return_value == SP_ERR)  {
ERRLOG("OLPspCosts_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPspCosts_Add: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}
