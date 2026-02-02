
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
    "OLOtherBankMapping.pc"
};


static unsigned int sqlctx = 163845331;


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
   unsigned char  *sqhstv[5];
   unsigned long  sqhstl[5];
            int   sqhsts[5];
            short *sqindv[5];
            int   sqinds[5];
   unsigned long  sqharm[5];
   unsigned long  *sqharc[5];
   unsigned short  sqadto[5];
   unsigned short  sqtdso[5];
} sqlstm = {12,5};

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
"SELECT obm_int_bank_code , omb_bank_acct_num , ob_owner_name , ob_branch_na\
me FROM ol_other_bank_mapping , ol_merchant_bank_acct , ol_bank_accts , def_b\
ank , ol_bank_acct_id , ol_psp_detail WHERE obm_merchant_id = :b0:b1 AND obm_\
disabled = 0 AND omb_merchant_id = obm_merchant_id AND omb_int_bank_code = ob\
m_int_bank_code AND omb_service_code = :b2:b3 AND omb_disabled = 0 AND omb_st\
atus = 'O' AND ob_int_bank_code = omb_int_bank_code AND ob_bank_acct_num = om\
b_bank_acct_num AND ob_acct_ccy = :b4:b5 AND db_int_bank_code = obm_int_bank_\
code AND db_country = :b6:b7 AND obai_int_bank_code = ob_int_bank_code AND ob\
ai_bank_acct_num = ob_bank_acct_num AND obai_status = 'O' AND obai_psp_id = o\
pd_psp_id AND opd_disabled = 0 AND opd_status = 'O' AND sp_ol_get_allow_actio\
n ( ob_int_bank_code , ob_bank_acct_num , :b8 ) = 1 AND sp_ol_get_bank_acct_t\
ype ( ob_int_bank_code , ob_bank_acct_num ) = 'DSI' ORDER BY obm_priority des\
c , dbms_random . value ( 0 , 1 ) desc            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,972,0,9,120,0,2049,5,5,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
40,0,0,1,0,0,13,122,0,0,4,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
71,0,0,1,0,0,15,158,0,0,0,0,0,1,0,
86,0,0,1,0,0,15,173,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/10/09              David Wong
Amend GetOtherBankList                             2014/09/02              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "OLOtherBankMapping.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char cDebug;

void OLOtherBankMapping(char cdebug)
{
	cDebug = cdebug;
}

int GetOtherBankList(const char* csMerchantId,
			const char* csCountry,
			const char* csAcctCcy,
			const char* csServiceCode,
			const char* csAction,
			hash_t *hRec)
{
	int iRet = PD_ERR;

	int iCnt = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO getotherbanklist_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

		/* varchar hv_acct_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_acct_ccy;

		/* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar hv_action[PD_ACCT_ACTION_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_action;

		/* varchar v_int_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_int_bank_code;

		/* varchar v_branch_name[PD_BANK_BRANCH_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch_name;

		/* varchar v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

		/* varchar v_owner_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_owner_name;


		short ind_merchant_id = -1;
		short ind_country = -1;
		short ind_acct_ccy = -1;
		short ind_service_code = -1;
		short ind_action = -1;
		short ind_int_bank_code = -1;
		short ind_branch_name = -1;
		short ind_bank_acct_num = -1;
		short ind_owner_name = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetOtherBankList: Begin\n"));

	hv_merchant_id.len = strlen(csMerchantId);
	strncpy((char*)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("GetOtherBankList: merchant_id = [%.*s]\n", hv_merchant_id.len, hv_merchant_id.arr));

	hv_country.len = strlen(csCountry);
	strncpy((char*)hv_country.arr, csCountry, hv_country.len);
	ind_country = 0;
DEBUGLOG(("GetOtherBankList: country = [%.*s]\n", hv_country.len, hv_country.arr));

	hv_acct_ccy.len = strlen(csAcctCcy);
	strncpy((char*)hv_acct_ccy.arr, csAcctCcy, hv_acct_ccy.len);
	ind_acct_ccy = 0;
DEBUGLOG(("GetOtherBankList: acct_ccy = [%.*s]\n", hv_acct_ccy.len, hv_acct_ccy.arr));

	hv_service_code.len = strlen(csServiceCode);
	strncpy((char*)hv_service_code.arr, csServiceCode, hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("GetOtherBankList: service_code = [%.*s]\n", hv_service_code.len, hv_service_code.arr));

	hv_action.len = strlen(csAction);
	strncpy((char*)hv_action.arr, csAction, hv_action.len);
	ind_action= 0;
DEBUGLOG(("GetOtherBankList: action = [%.*s]\n", hv_action.len, hv_action.arr));

	/* EXEC SQL DECLARE c_cursor CURSOR FOR
		SELECT	obm_int_bank_code, omb_bank_acct_num, ob_owner_name, ob_branch_name
		FROM	ol_other_bank_mapping, ol_merchant_bank_acct, ol_bank_accts, def_bank, ol_bank_acct_id, ol_psp_detail
		WHERE	obm_merchant_id = :hv_merchant_id:ind_merchant_id
		AND	obm_disabled = 0
		AND	omb_merchant_id = obm_merchant_id
		AND	omb_int_bank_code = obm_int_bank_code
		AND	omb_service_code = :hv_service_code:ind_service_code
		AND	omb_disabled = 0
		AND	omb_status = 'O'
		AND	ob_int_bank_code = omb_int_bank_code
		AND	ob_bank_acct_num = omb_bank_acct_num
		AND	ob_acct_ccy = :hv_acct_ccy:ind_acct_ccy
		/oAND	ob_status_type = 'A'o/
		AND	db_int_bank_code = obm_int_bank_code
		AND	db_country = :hv_country:ind_country
		AND	obai_int_bank_code = ob_int_bank_code
		AND	obai_bank_acct_num = ob_bank_acct_num
		AND	obai_status = 'O'
		AND	obai_psp_id = opd_psp_id
		AND	opd_disabled = 0
		AND	opd_status = 'O'
		/oAND	opd_bank_acct_type = 'DSI'o/
		AND     sp_ol_get_allow_action(ob_int_bank_code, ob_bank_acct_num, :hv_action) = 1
                AND     sp_ol_get_bank_acct_type(ob_int_bank_code, ob_bank_acct_num) = 'DSI'
		ORDER BY obm_priority desc, dbms_random.value(0, 1) desc; */ 


	/* EXEC SQL OPEN c_cursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[0] = (unsigned long )17;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_service_code;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_acct_ccy;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_acct_ccy;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_country;
 sqlstm.sqhstl[3] = (unsigned long )4;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_country;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_action;
 sqlstm.sqhstl[4] = (unsigned long )22;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto getotherbanklist_error;
}


	do {
		/* EXEC SQL FETCH c_cursor
		INTO
			:v_int_bank_code:ind_int_bank_code,
			:v_bank_acct_num:ind_bank_acct_num,
			:v_owner_name:ind_owner_name,
			:v_branch_name:ind_branch_name; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 5;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )40;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_int_bank_code;
  sqlstm.sqhstl[0] = (unsigned long )13;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_int_bank_code;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_bank_acct_num;
  sqlstm.sqhstl[1] = (unsigned long )53;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_bank_acct_num;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_owner_name;
  sqlstm.sqhstl[2] = (unsigned long )53;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_owner_name;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_branch_name;
  sqlstm.sqhstl[3] = (unsigned long )153;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_branch_name;
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
  if (sqlca.sqlcode < 0) goto getotherbanklist_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		if (ind_int_bank_code >= 0 && ind_bank_acct_num >= 0) {
			v_int_bank_code.arr[v_int_bank_code.len] = '\0';
			PutField_CString(hRec, "int_bank_code", (const char*)v_int_bank_code.arr);
DEBUGLOG(("GetOtherBankList: int_bank_code = [%s]\n", v_int_bank_code.arr));

			v_bank_acct_num.arr[v_bank_acct_num.len] = '\0';
			PutField_CString(hRec, "bank_acct_num", (const char*)v_bank_acct_num.arr);
DEBUGLOG(("GetOtherBankList: bank_acct_num = [%s]\n", v_bank_acct_num.arr));

                       	v_owner_name.arr[v_owner_name.len] = '\0';
                       	PutField_CString(hRec, "owner_name", (const char*)v_owner_name.arr);
DEBUGLOG(("GetOtherBankList: owner_name = [%s]\n", v_owner_name.arr));

			if (ind_branch_name >= 0) {
				v_branch_name.arr[v_branch_name.len] = '\0';
				PutField_CString(hRec, "branch_name", (const char*)v_branch_name.arr);
DEBUGLOG(("GetOtherBankList: branch_name = [%s]\n", v_branch_name.arr));
			}
			iCnt++;
		}

		break;
	}
	while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )71;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getotherbanklist_error;
}



	if (iCnt > 0 ) {
DEBUGLOG(("GetOtherBankList Normal Exit\n"));
		iRet = PD_OK;
	} else {
DEBUGLOG(("GetOtherBankList Normal Exit, Not Found\n"));
	}

	return iRet;

getotherbanklist_error:
DEBUGLOG(("getotherbanklist_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )86;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

