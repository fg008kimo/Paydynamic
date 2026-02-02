
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
           char  filnam[23];
};
static struct sqlcxp sqlfpn =
{
    22,
    "OLAutoMatchCriteria.pc"
};


static unsigned int sqlctx = 322762419;


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
   unsigned char  *sqhstv[3];
   unsigned long  sqhstl[3];
            int   sqhsts[3];
            short *sqindv[3];
            int   sqinds[3];
   unsigned long  sqharm[3];
   unsigned long  *sqharc[3];
   unsigned short  sqadto[3];
   unsigned short  sqtdso[3];
} sqlstm = {12,3};

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
"select amm_pool_id , amp_match_rule_type , amr_tag_name from OL_AUTO_MATCH_\
MAPPING , OL_AUTO_MATCH_POOLS , OL_DEF_AUTO_MATCH_RULE where amm_merchant_id \
= :b0 and amm_disabled = 0 and amm_pool_id = amp_pool_id and amp_disabled = 0\
 and amp_match_rule_type = amr_type order by amm_priority desc , amr_order as\
c            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,319,0,9,71,0,2049,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,13,74,0,0,3,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,
51,0,0,1,0,0,15,123,0,0,0,0,0,1,0,
66,0,0,1,0,0,15,144,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/11/11              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "OLAutoMatchCriteria.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char cDebug;

void OLAutoMatchCriteria(char cdebug)
{
	cDebug = cdebug;
}

int GetAutoMatchCriteria(const char *csMerchantId,
				recordset_t *myRec)
{
	int iRet = PD_OK;
	int iCnt = 0;
	int iLastPoolId;
	int iIndex;

	char *csTag = (char*) malloc (64);

	hash_t *myHash;
	myHash = (hash_t*) malloc (sizeof(hash_t));
	hash_init(myHash, 0);

	/* EXEC SQL WHENEVER SQLERROR GOTO getautomatchcriteria_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		int	v_pool_id;
		/* varchar	v_match_rule_type[PD_MATCH_RULE_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_match_rule_type;

		/* varchar	v_tag_name[PD_TAG_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_tag_name;


		short	ind_pool_id = -1;
		short	ind_match_rule_type = -1;
		short	ind_tag_name = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_merchant_id.len = strlen(csMerchantId);
	strncpy((char*)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
DEBUGLOG(("GetAutoMatchCriteria: merchant_id = [%.*s]\n", hv_merchant_id.len, (const char*)hv_merchant_id.arr));

	/* EXEC SQL DECLARE c_cursor CURSOR FOR
		select	amm_pool_id, amp_match_rule_type, amr_tag_name
		from	OL_AUTO_MATCH_MAPPING, OL_AUTO_MATCH_POOLS, OL_DEF_AUTO_MATCH_RULE
		where	amm_merchant_id = :hv_merchant_id
		and	amm_disabled = 0
		and	amm_pool_id = amp_pool_id
		and	amp_disabled = 0
		and	amp_match_rule_type = amr_type
		order by amm_priority desc, amr_order asc; */ 


	/* EXEC SQL OPEN c_cursor; */ 

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
 if (sqlca.sqlcode < 0) goto getautomatchcriteria_error;
}



	for (;;) {
		/* EXEC SQL FETCH c_cursor
		INTO	:v_pool_id:ind_pool_id,
			:v_match_rule_type:ind_match_rule_type,
			:v_tag_name:ind_tag_name; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 3;
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
  sqlstm.sqhstv[1] = (unsigned char  *)&v_match_rule_type;
  sqlstm.sqhstl[1] = (unsigned long )13;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_match_rule_type;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_tag_name;
  sqlstm.sqhstl[2] = (unsigned long )28;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_tag_name;
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
  if (sqlca.sqlcode < 0) goto getautomatchcriteria_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

/* pool_id */
		if (ind_pool_id >= 0) {
			if (iCnt == 1) {
DEBUGLOG(("GetAutoMatchCriteria: pool_id = [%d]\n", v_pool_id));
				PutField_Int(myHash, "pool_id", v_pool_id);
				iLastPoolId = v_pool_id;
				iIndex = 0;
			} else {
				if (v_pool_id != iLastPoolId) {
					PutField_Int(myHash, "field_cnt", iIndex);
					RecordSet_Add(myRec, myHash);
					myHash = (hash_t*) malloc (sizeof(hash_t));
					hash_init(myHash, 0);
DEBUGLOG(("GetAutoMatchCriteria: pool_id = [%d]\n", v_pool_id));
					PutField_Int(myHash, "pool_id", v_pool_id);
					iLastPoolId = v_pool_id;
					iIndex = 0;
				}
			}
		}

		iIndex++;

/* match_rule_type */
		if (ind_match_rule_type >= 0) {
			v_match_rule_type.arr[v_match_rule_type.len] = '\0';
			sprintf(csTag, "match_rule_type_%d", iIndex);
			PutField_CString(myHash, csTag, (const char*)v_match_rule_type.arr);
		}

/* tag_name */
		if (ind_tag_name >= 0) {
			v_tag_name.arr[v_tag_name.len] = '\0';
			sprintf(csTag, "tag_name_%d", iIndex);
			PutField_CString(myHash, csTag, (const char*)v_tag_name.arr);
		}
	}

	/* EXEC SQL CLOSE c_cursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )51;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getautomatchcriteria_error;
}



	if (iCnt > 0 ) {
		PutField_Int(myHash, "field_cnt", iIndex);
		RecordSet_Add(myRec, myHash);
		iRet = PD_OK;
	} else {
DEBUGLOG(("GetAutoMatchCriteria not found\n"));
		iRet = PD_ERR;
	}

	FREE_ME(csTag);

DEBUGLOG(("GetAutoMatchCriteria Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getautomatchcriteria_error:
DEBUGLOG(("getautomatchcriteria_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLAutoMatchCriteria getautomatchcriteria_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL CLOSE c_cursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )66;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getautomatchcriteria_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

