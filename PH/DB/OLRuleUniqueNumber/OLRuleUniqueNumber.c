
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
    "OLRuleUniqueNumber.pc"
};


static unsigned int sqlctx = 165220987;


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
   unsigned char  *sqhstv[12];
   unsigned long  sqhstl[12];
            int   sqhsts[12];
            short *sqindv[12];
            int   sqinds[12];
   unsigned long  sqharm[12];
   unsigned long  *sqharc[12];
   unsigned short  sqadto[12];
   unsigned short  sqtdso[12];
} sqlstm = {12,12};

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

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,0,0,0,56,96,0,0,1,1,0,1,0,3,102,0,0,
24,0,0,1,189,0,6,97,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,2,
102,0,0,
63,0,0,0,0,0,13,113,0,0,12,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,
4,0,0,2,4,0,0,2,3,0,0,2,4,0,0,2,4,0,0,2,1,0,0,2,3,0,0,
126,0,0,0,0,0,15,199,0,0,1,1,0,1,0,1,102,0,0,
145,0,0,0,0,0,78,200,0,0,1,1,0,1,0,3,102,0,0,
164,0,0,0,0,0,15,211,0,0,1,1,0,1,0,1,102,0,0,
183,0,0,0,0,0,78,212,0,0,1,1,0,1,0,3,102,0,0,
202,0,0,0,0,0,15,222,0,0,1,1,0,1,0,1,102,0,0,
221,0,0,0,0,0,78,223,0,0,1,1,0,1,0,3,102,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/10/09              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "OLRuleUniqueNumber.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void OLRuleUniqueNumber(char    cdebug)
{
        cDebug = cdebug;
}


int GetOLRuleUniqueNumber(const char* csTxnCode,
			  const char* csPartyType,
			  const char* csPartyId,
			  hash_t* hTxn)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO getrule_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

		/* varchar         hv_party_id[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_party_id;

		/* varchar		hv_party_type[PD_OFL_PARTY_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_party_type;

		int             hv_disabled;

		/* varchar		v_rule_party_type[PD_OFL_PARTY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_rule_party_type;

		/* varchar		v_client_id[PD_CLIENT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_client_id;

		/* varchar		v_prov[PD_CLIENT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_prov;

		char		v_direction;
		char		v_auto_extend;
		int             v_cnt;
		int             v_check_interval;
		double          v_range_end;
		double          v_step_size;
		double          v_extend_amount;
		double          v_max_range_amount;

		short		ind_txn_code = -1;
		short		ind_party_id = -1;
		short		ind_party_type = -1;
		short		ind_disabled = -1;

		short		ind_rule_party_type = -1;
		short		ind_client_id = -1;
		short		ind_prov = -1;
		short		ind_direction = -1;
		short		ind_auto_extend = -1;
		short		ind_cnt = -1;
		short           ind_check_interval = -1;
		short		ind_range_end = -1;
		short		ind_step_size = -1;
		short		ind_extend_amount = -1;
		short		ind_max_range_amount = -1;

		SQL_CURSOR      c_cursor_id;
		short		hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_code.len = strlen(csTxnCode);
	memcpy(hv_txn_code.arr,csTxnCode,hv_txn_code.len);
DEBUGLOG(("GetOLRuleUniqueNumber txn_code = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));
	ind_txn_code = 0;

	hv_party_id.len = strlen(csPartyId);
	memcpy(hv_party_id.arr,csPartyId,hv_party_id.len);
DEBUGLOG(("GetOLRuleUniqueNumber party_id = [%.*s]\n",hv_party_id.len,hv_party_id.arr));
	ind_party_id = 0;

	hv_party_type.len = strlen(csPartyType);
	memcpy(hv_party_type.arr,csPartyType,hv_party_type.len);
DEBUGLOG(("GetOLRuleUniqueNumber party_type = [%.*s]\n",hv_party_type.len,hv_party_type.arr));
	ind_party_type = 0;

	hv_disabled = 0;
	ind_disabled = 0;

	/* EXEC SQL ALLOCATE       :c_cursor_id; */ 

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
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto getrule_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
			:hv_return_value := sp_get_rule_unique_num(:hv_txn_code:ind_txn_code,
							     :hv_party_id:ind_party_id,
                                                             :hv_party_type:ind_party_type,
							     :hv_disabled:ind_disabled,
							     :c_cursor_id);

                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_get_rule_unique_num ( :\
hv_txn_code:ind_txn_code , :hv_party_id:ind_party_id , :hv_party_type:ind_par\
ty_type , :hv_disabled:ind_disabled , :c_cursor_id ) ; END ;";
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_code;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_txn_code;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_party_id;
        sqlstm.sqhstl[2] = (unsigned long )22;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_party_id;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_party_type;
        sqlstm.sqhstl[3] = (unsigned long )8;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_party_type;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_disabled;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_disabled;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&c_cursor_id;
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
        if (sqlca.sqlcode < 0) goto getrule_error;
}



	if (hv_return_value > 0 ) {
DEBUGLOG(("GetOLRuleUniqueNumber: Found!\n"));
                for (;;) {

			/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_id
                        INTO
				:v_rule_party_type:ind_rule_party_type,
				:v_client_id:ind_client_id,
				:v_prov:ind_prov,
				:v_auto_extend:ind_auto_extend,
				:v_extend_amount:ind_extend_amount,
				:v_max_range_amount:ind_max_range_amount,
				:v_check_interval:ind_check_interval,
				:v_range_end:ind_range_end,
				:v_step_size:ind_step_size,
				:v_direction:ind_direction,
				:v_cnt:ind_cnt; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 12;
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
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_rule_party_type;
                        sqlstm.sqhstl[1] = (unsigned long )9;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_rule_party_type;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_client_id;
                        sqlstm.sqhstl[2] = (unsigned long )13;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_client_id;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_prov;
                        sqlstm.sqhstl[3] = (unsigned long )13;
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_prov;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_auto_extend;
                        sqlstm.sqhstl[4] = (unsigned long )1;
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_auto_extend;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_extend_amount;
                        sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_extend_amount;
                        sqlstm.sqinds[5] = (         int  )0;
                        sqlstm.sqharm[5] = (unsigned long )0;
                        sqlstm.sqadto[5] = (unsigned short )0;
                        sqlstm.sqtdso[5] = (unsigned short )0;
                        sqlstm.sqhstv[6] = (unsigned char  *)&v_max_range_amount;
                        sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[6] = (         int  )0;
                        sqlstm.sqindv[6] = (         short *)&ind_max_range_amount;
                        sqlstm.sqinds[6] = (         int  )0;
                        sqlstm.sqharm[6] = (unsigned long )0;
                        sqlstm.sqadto[6] = (unsigned short )0;
                        sqlstm.sqtdso[6] = (unsigned short )0;
                        sqlstm.sqhstv[7] = (unsigned char  *)&v_check_interval;
                        sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[7] = (         int  )0;
                        sqlstm.sqindv[7] = (         short *)&ind_check_interval;
                        sqlstm.sqinds[7] = (         int  )0;
                        sqlstm.sqharm[7] = (unsigned long )0;
                        sqlstm.sqadto[7] = (unsigned short )0;
                        sqlstm.sqtdso[7] = (unsigned short )0;
                        sqlstm.sqhstv[8] = (unsigned char  *)&v_range_end;
                        sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[8] = (         int  )0;
                        sqlstm.sqindv[8] = (         short *)&ind_range_end;
                        sqlstm.sqinds[8] = (         int  )0;
                        sqlstm.sqharm[8] = (unsigned long )0;
                        sqlstm.sqadto[8] = (unsigned short )0;
                        sqlstm.sqtdso[8] = (unsigned short )0;
                        sqlstm.sqhstv[9] = (unsigned char  *)&v_step_size;
                        sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[9] = (         int  )0;
                        sqlstm.sqindv[9] = (         short *)&ind_step_size;
                        sqlstm.sqinds[9] = (         int  )0;
                        sqlstm.sqharm[9] = (unsigned long )0;
                        sqlstm.sqadto[9] = (unsigned short )0;
                        sqlstm.sqtdso[9] = (unsigned short )0;
                        sqlstm.sqhstv[10] = (unsigned char  *)&v_direction;
                        sqlstm.sqhstl[10] = (unsigned long )1;
                        sqlstm.sqhsts[10] = (         int  )0;
                        sqlstm.sqindv[10] = (         short *)&ind_direction;
                        sqlstm.sqinds[10] = (         int  )0;
                        sqlstm.sqharm[10] = (unsigned long )0;
                        sqlstm.sqadto[10] = (unsigned short )0;
                        sqlstm.sqtdso[10] = (unsigned short )0;
                        sqlstm.sqhstv[11] = (unsigned char  *)&v_cnt;
                        sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[11] = (         int  )0;
                        sqlstm.sqindv[11] = (         short *)&ind_cnt;
                        sqlstm.sqinds[11] = (         int  )0;
                        sqlstm.sqharm[11] = (unsigned long )0;
                        sqlstm.sqadto[11] = (unsigned short )0;
                        sqlstm.sqtdso[11] = (unsigned short )0;
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
                        if (sqlca.sqlcode < 0) goto getrule_error;
}




			if (SQLCODE == SQL_NOT_FOUND) {
				break;
                        }

			if(ind_cnt<0)
				v_cnt = 0;
/*selected party type*/
			if (ind_rule_party_type >= 0) {
                                v_rule_party_type.arr[v_rule_party_type.len]='\0';
                                PutField_CString(hTxn,"selected_party_type",(const char *)v_rule_party_type.arr);
DEBUGLOG(("GetOLRuleUniqueNumber selected party_type= [%.*s]\n",v_rule_party_type.len,v_rule_party_type.arr));
                        }

/*client_id*/
			if (ind_client_id >= 0) {
                                v_client_id.arr[v_client_id.len]='\0';
                                PutField_CString(hTxn,"client_id",(const char *)v_client_id.arr);
DEBUGLOG(("GetOLRuleUniqueNumber client_id = [%.*s]\n",v_client_id.len,v_client_id.arr));
                        }

/*provider*/
			if (ind_prov >= 0) {
                                v_prov.arr[v_prov.len]='\0';
                                PutField_CString(hTxn,"provider",(const char *)v_prov.arr);
DEBUGLOG(("GetOLRuleUniqueNumber provider = [%.*s]\n",v_prov.len,v_prov.arr));
                        }


/* operate_direction */
			if (ind_direction>= 0) {
				PutField_Char(hTxn,"direction",v_direction);
DEBUGLOG(("GetOLRuleUniqueNumber operate_direction = [%c]\n",v_direction));
			}

/* auto_extend */
			if (ind_auto_extend >= 0) {
				PutField_Char(hTxn,"auto_extend",v_auto_extend);
DEBUGLOG(("GetOLRuleUniqueNumber auto_extend = [%c]\n",v_auto_extend));
			}

/* extend_amount */
			if (ind_extend_amount >= 0) {
				PutField_Double(hTxn,"extend_amount",v_extend_amount);
DEBUGLOG(("GetOLRuleUniqueNumber extend_amount = [%f]\n",v_extend_amount));
			}

/* max_range_amount */
			if (ind_max_range_amount >= 0) {
				PutField_Double(hTxn,"max_range_amount",v_max_range_amount);
DEBUGLOG(("GetOLRuleUniqueNumber max_range_amount = [%f]\n",v_max_range_amount));
			}

/* check_interval */
			if (ind_check_interval >= 0) {
				PutField_Int(hTxn,"check_interval",v_check_interval);
DEBUGLOG(("GetOLRuleUniqueNumber check_interval = [%d]\n",v_check_interval));
			}

/* range_end */
			if (ind_range_end >= 0) {
				PutField_Double(hTxn,"range_end",v_range_end);
DEBUGLOG(("GetOLRuleUniqueNumber range_end = [%f]\n",v_range_end));
			}

/* step_size */
			if (ind_step_size>= 0) {
				PutField_Double(hTxn,"step_size",v_step_size);
DEBUGLOG(("GetOLRuleUniqueNumber step_size = [%f]\n",v_step_size));
			}

		}
		/* EXEC SQL CLOSE :c_cursor_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )126;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
  if (sqlca.sqlcode < 0) goto getrule_error;
}


                /* EXEC SQL FREE :c_cursor_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 12;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )145;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
                if (sqlca.sqlcode < 0) goto getrule_error;
}


		if(v_cnt>0){
DEBUGLOG(("GetOLRuleUniqueNumber Rule Found\n"));
			return  PD_FOUND;
		}
		else{
DEBUGLOG(("GetOLRuleUniqueNumber Rule Not Found\n"));
			return  PD_NOT_FOUND;
		}
	}
        else {
                /* EXEC SQL CLOSE :c_cursor_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 12;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )164;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
                if (sqlca.sqlcode < 0) goto getrule_error;
}


                /* EXEC SQL FREE :c_cursor_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 12;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )183;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
                if (sqlca.sqlcode < 0) goto getrule_error;
}


DEBUGLOG(("GetOLRuleUniqueNumber: exit with error\n"));
                return PD_NOT_FOUND;
        }

getrule_error:
DEBUGLOG(("getrule_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLRuleUniqueNumber_Get: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )202;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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


        /* EXEC SQL FREE :c_cursor_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )221;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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


        return PD_ERR;
}
