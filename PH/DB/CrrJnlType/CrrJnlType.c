
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
    "CrrJnlType.pc"
};


static unsigned int sqlctx = 604387;


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

 static char *sq0003 = 
"SELECT JNL . JNL_TYPE_ID , JNL . PREFIX , TC . TC_DESC , JEM . GROUP_ID , J\
EM . SINGLE FROM CRR_JNL_TYPE JNL , ( SELECT JNL_TYPE_ID , GROUP_ID , SINGLE \
, TXN_CODE FROM CRR_JNL_ENTRY_TYPE_MAPPING WHERE DISABLED = 0 GROUP BY JNL_TY\
PE_ID , GROUP_ID , SINGLE , TXN_CODE ) JEM , TXN_CODE TC WHERE JNL . POST_TYP\
E = 'A' AND JNL . DISABLED = 0 AND JNL . JNL_TYPE_ID = JEM . JNL_TYPE_ID AND \
TC . TC_CODE = JEM . TXN_CODE ORDER BY JNL . JNL_TYPE_ID ASC            ";

 static char *sq0004 = 
"SELECT JNL . JNL_TYPE_ID , JNL . PREFIX , JNL . NAME , JEM . COM_GROUP_ID ,\
 JEM . COM_IS_SINGLE FROM CRR_JNL_TYPE JNL , ( SELECT COM_JNL_TYPE_ID , COM_G\
ROUP_ID , COM_IS_SINGLE FROM CRR_OFL_JNL_ENTRY_TYPE_MAPPING WHERE COM_DISABLE\
D = 0 GROUP BY COM_JNL_TYPE_ID , COM_GROUP_ID , COM_IS_SINGLE ) JEM WHERE JNL\
 . POST_TYPE = 'F' AND JNL . DISABLED = 0 AND JNL . JNL_TYPE_ID = JEM . COM_J\
NL_TYPE_ID ORDER BY JNL . JNL_TYPE_ID ASC            ";

 static char *sq0005 = 
"SELECT JNL . JNL_TYPE_ID , JNL . PREFIX , JNL . NAME , JEM . CMM_GROUP_ID ,\
 JEM . CMM_IS_SINGLE FROM CRR_JNL_TYPE JNL , ( SELECT CMM_JNL_TYPE_ID , CMM_G\
ROUP_ID , CMM_IS_SINGLE FROM CRR_MI_JNL_ENTRY_TYPE_MAPPING WHERE CMM_DISABLED\
 = 0 GROUP BY CMM_JNL_TYPE_ID , CMM_GROUP_ID , CMM_IS_SINGLE ) JEM WHERE JNL \
. POST_TYPE = 'N' AND JNL . DISABLED = 0 AND JNL . JNL_TYPE_ID = JEM . CMM_JN\
L_TYPE_ID ORDER BY JNL . JNL_TYPE_ID ASC            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,143,0,6,51,0,0,2,2,0,1,0,2,3,0,0,1,3,0,0,
28,0,0,2,118,0,4,106,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,
55,0,0,3,455,0,9,174,0,2049,0,0,0,1,0,
70,0,0,3,0,0,13,176,0,0,5,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,
105,0,0,3,0,0,15,226,0,0,0,0,0,1,0,
120,0,0,3,0,0,15,239,0,0,0,0,0,1,0,
135,0,0,4,436,0,9,286,0,2049,0,0,0,1,0,
150,0,0,4,0,0,13,288,0,0,5,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,
185,0,0,4,0,0,15,338,0,0,0,0,0,1,0,
200,0,0,4,0,0,15,351,0,0,0,0,0,1,0,
215,0,0,5,435,0,9,398,0,2049,0,0,0,1,0,
230,0,0,5,0,0,13,400,0,0,5,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,
265,0,0,5,0,0,15,450,0,0,0,0,0,1,0,
280,0,0,5,0,0,15,463,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/07/29              Simon Fung
Add IsAutoPostJnl				   2014/01/14              Virginia Yun
Add CRR Offline					   2015/03/20		   Dirk Wong
Add MiniMMM CRR					   2015/12/22		   Dirk Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "CrrJnlType.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;
void CrrJnlType(char    cdebug)
{
	cDebug = cdebug;
}

int GetMnlApproval(const int iJnlTypeId, int* iMnlApproval)
{
  /* EXEC SQL WHENEVER SQLERROR GOTO GetMnlApproval_error; */ 

  /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


  /* EXEC SQL BEGIN DECLARE SECTION; */ 


	int		hv_jnl_type_id;	
	int		hv_mnl_approval;	
	short		ind_mnl_approval = -1;

  /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetMnlApproval: Begin\n"));
		
	/* jnl_type_id */
	hv_jnl_type_id = iJnlTypeId;
DEBUGLOG(("GetMnlApproval:hv_jnl_type_id = [%d]\n",hv_jnl_type_id));

  /* EXEC SQL EXECUTE
		BEGIN
      SELECT MNL_APPROVAL INTO :hv_mnl_approval:ind_mnl_approval
			FROM CRR_JNL_TYPE 
			WHERE JNL_TYPE_ID = :hv_jnl_type_id
			AND DISABLED = 0;
    END;
  END-EXEC; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 2;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "begin SELECT MNL_APPROVAL INTO :hv_mnl_approval:ind_mnl_ap\
proval FROM CRR_JNL_TYPE WHERE JNL_TYPE_ID = :hv_jnl_type_id AND DISABLED = 0\
 ; END ;";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_mnl_approval;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_mnl_approval;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_jnl_type_id;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
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
  if (sqlca.sqlcode < 0) goto GetMnlApproval_error;
}


		
	if (ind_mnl_approval == -1) {
		hv_mnl_approval = 0;
	}

	*iMnlApproval = hv_mnl_approval;

DEBUGLOG(("GetMnlApproval:hv_mnl_approval = [%d]\n",hv_mnl_approval));
	
	return PD_OK;

GetMnlApproval_error:
DEBUGLOG(("GetMnlApproval_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	ERRLOG("CrrJnlType_GetMnlApproval: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_INTERNAL_ERR TxnAbort\n"));
	return PD_INTERNAL_ERR;
}

int IsAutoPostJnl(const unsigned char* csJnlTypePrefix)
{
	int iRet = PD_FALSE;

	/* EXEC SQL WHENEVER SQLERROR GOTO isautopostjnl_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_jnl_type_prefix[PD_JNL_TYPE_PREFIX_LEN]; */ 
struct { unsigned short len; unsigned char arr[5]; } hv_jnl_type_prefix;

		int     hv_disabled;

		short   ind_jnl_type_prefix = -1;
		short	ind_disabled = -1;

		int     v_cnt;
		short	ind_cnt = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_jnl_type_prefix.len = strlen((const char*)csJnlTypePrefix);
	memcpy(hv_jnl_type_prefix.arr, csJnlTypePrefix, hv_jnl_type_prefix.len);
DEBUGLOG(("IsAutoPostJnl: csJnlTypePrefix = [%.*s]\n", hv_jnl_type_prefix.len,hv_jnl_type_prefix.arr));
	ind_jnl_type_prefix = 0;

	hv_disabled=0;
	ind_disabled = 0;

	/* EXEC SQL SELECT count(1)
		INTO    :v_cnt:ind_cnt
		from    crr_jnl_type
		where   prefix = :hv_jnl_type_prefix
		and     disabled = :hv_disabled
		and     post_type in ('A', 'F'); */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 from crr_jnl_type where pref\
ix = :b2 and disabled = :b3 and post_type in ( 'A' , 'F' ) ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )28;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_cnt;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_jnl_type_prefix;
 sqlstm.sqhstl[1] = (unsigned long )7;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto isautopostjnl_error;
}


	
	if (ind_cnt < 0)
		v_cnt = 0;

	if (v_cnt > 0) {
		iRet = PD_TRUE;
	}

DEBUGLOG(("IsAutoPostJnl = [%d]\n",iRet));
	return iRet;

isautopostjnl_error:
DEBUGLOG(("isautopostjnl_error:code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_FALSE;
}

int GetNewAutoPostJnl(recordset_t* myRec)
{
	int	iCnt = 0;
	hash_t	*myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO getjnl_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		int	v_jnl_type_id;
		/* varchar	v_prefix[PD_JNL_TYPE_PREFIX_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[6]; } v_prefix;

		/* varchar	v_desc[PD_DESCRIPTION_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_desc;

		int	v_group_id;
		int	v_single;

		short	ind_jnl_type_id;
		short	ind_prefix = -1;
		short	ind_desc = -1;
		short	ind_group_id = -1;
		short	ind_single = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetNewAutoPostJnl: Begin\n"));

	/* EXEC SQL DECLARE getjnlcursor CURSOR FOR
		SELECT  JNL.JNL_TYPE_ID,
			JNL.PREFIX,
			TC.TC_DESC,
			JEM.GROUP_ID,
			JEM.SINGLE
		FROM    CRR_JNL_TYPE JNL,
			(SELECT	JNL_TYPE_ID, GROUP_ID, SINGLE, TXN_CODE
			FROM	CRR_JNL_ENTRY_TYPE_MAPPING
			WHERE	DISABLED = 0
			GROUP BY JNL_TYPE_ID, GROUP_ID, SINGLE, TXN_CODE) JEM,
			TXN_CODE TC
		WHERE   JNL.POST_TYPE = 'A'
		AND	JNL.DISABLED = 0
		AND	JNL.JNL_TYPE_ID = JEM.JNL_TYPE_ID
		AND	TC.TC_CODE = JEM.TXN_CODE
		ORDER BY JNL.JNL_TYPE_ID ASC; */ 


	/* EXEC SQL OPEN getjnlcursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )55;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getjnl_error;
}


	for (;;) {
		/* EXEC SQL FETCH getjnlcursor
		INTO    :v_jnl_type_id:ind_jnl_type_id,
			:v_prefix:ind_prefix,
			:v_desc:ind_desc,
			:v_group_id:ind_group_id,
			:v_single:ind_single; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 5;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )70;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_jnl_type_id;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_jnl_type_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_prefix;
  sqlstm.sqhstl[1] = (unsigned long )8;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_prefix;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_desc;
  sqlstm.sqhstl[2] = (unsigned long )103;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_desc;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_group_id;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_group_id;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_single;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_single;
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
  if (sqlca.sqlcode < 0) goto getjnl_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

/* jnl_type_id */
		if (ind_jnl_type_id >= 0) {
			PutField_Int(myHash, "jnl_type_id", v_jnl_type_id);
DEBUGLOG(("GetNewAutoPostJnl jnl_type_id = [%d]\n",v_jnl_type_id));
		}

/* prefix */
		if (ind_prefix>=0) {
			v_prefix.arr[v_prefix.len] = '\0';
			PutField_CString(myHash,"prefix",(char*)v_prefix.arr);
DEBUGLOG(("GetNewAutoPostJnl prefix = [%s]\n",(char*)v_prefix.arr));
		}

/* desc */
		if (ind_desc>=0) {
			v_desc.arr[v_desc.len] = '\0';
			PutField_CString(myHash,"desc",(char*)v_desc.arr);
DEBUGLOG(("GetNewAutoPostJnl desc = [%s]\n",(char*)v_desc.arr));
		}

/* group_id */
		if (ind_group_id >= 0) {
			PutField_Int(myHash, "group_id", v_group_id);
DEBUGLOG(("GetNewAutoPostJnl group_id = [%d]\n",v_group_id));
		}

/* single */
		if (ind_single >= 0) {
			PutField_Int(myHash, "single", v_single);
DEBUGLOG(("GetNewAutoPostJnl single = [%d]\n",v_single));
		}

		RecordSet_Add(myRec,myHash);
	}
	/* EXEC SQL CLOSE getjnlcursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )105;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getjnl_error;
}



	if (iCnt > 0) {
		return FOUND;
DEBUGLOG(("GetNewAutoPostJnl FOUND %d JNL\n",iCnt));
	} else {
		return NOT_FOUND;
DEBUGLOG(("GetNewAutoPostJnl NOT FOUND\n"));
	}

getjnl_error:
DEBUGLOG(("getjnl_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL CLOSE getjnlcursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )120;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getjnl_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_INTERNAL_ERR;
}

int GetOfflineAutoPostJnl(recordset_t* myRec)
{
	int	iCnt = 0;
	hash_t	*myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO getofljnl_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		int	v_jnl_type_id;
		/* varchar	v_prefix[PD_JNL_TYPE_PREFIX_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[6]; } v_prefix;

		/* varchar	v_desc[PD_DESCRIPTION_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_desc;

		int	v_group_id;
		int	v_single;

		short	ind_jnl_type_id;
		short	ind_prefix = -1;
		short	ind_desc = -1;
		short	ind_group_id = -1;
		short	ind_single = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetOfflineAutoPostJnl: Begin\n"));

	/* EXEC SQL DECLARE getofljnlcursor CURSOR FOR
		SELECT  JNL.JNL_TYPE_ID,
			JNL.PREFIX,
			JNL.NAME,
			JEM.COM_GROUP_ID,
			JEM.COM_IS_SINGLE
		FROM    CRR_JNL_TYPE JNL,
			(SELECT	COM_JNL_TYPE_ID, COM_GROUP_ID, COM_IS_SINGLE
			FROM	CRR_OFL_JNL_ENTRY_TYPE_MAPPING
			WHERE	COM_DISABLED = 0
			GROUP BY COM_JNL_TYPE_ID, COM_GROUP_ID, COM_IS_SINGLE) JEM
		WHERE   JNL.POST_TYPE = 'F'
		AND	JNL.DISABLED = 0
		AND	JNL.JNL_TYPE_ID = JEM.COM_JNL_TYPE_ID
		ORDER BY JNL.JNL_TYPE_ID ASC; */ 


	/* EXEC SQL OPEN getofljnlcursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0004;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )135;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getofljnl_error;
}


	for (;;) {
		/* EXEC SQL FETCH getofljnlcursor
		INTO    :v_jnl_type_id:ind_jnl_type_id,
			:v_prefix:ind_prefix,
			:v_desc:ind_desc,
			:v_group_id:ind_group_id,
			:v_single:ind_single; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 5;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )150;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_jnl_type_id;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_jnl_type_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_prefix;
  sqlstm.sqhstl[1] = (unsigned long )8;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_prefix;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_desc;
  sqlstm.sqhstl[2] = (unsigned long )103;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_desc;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_group_id;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_group_id;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_single;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_single;
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
  if (sqlca.sqlcode < 0) goto getofljnl_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

/* jnl_type_id */
		if (ind_jnl_type_id >= 0) {
			PutField_Int(myHash, "jnl_type_id", v_jnl_type_id);
DEBUGLOG(("GetOfflineAutoPostJnl jnl_type_id = [%d]\n",v_jnl_type_id));
		}

/* prefix */
		if (ind_prefix>=0) {
			v_prefix.arr[v_prefix.len] = '\0';
			PutField_CString(myHash,"prefix",(char*)v_prefix.arr);
DEBUGLOG(("GetOfflineAutoPostJnl prefix = [%s]\n",(char*)v_prefix.arr));
		}

/* desc */
		if (ind_desc>=0) {
			v_desc.arr[v_desc.len] = '\0';
			PutField_CString(myHash,"desc",(char*)v_desc.arr);
DEBUGLOG(("GetOfflineAutoPostJnl desc = [%s]\n",(char*)v_desc.arr));
		}

/* group_id */
		if (ind_group_id >= 0) {
			PutField_Int(myHash, "group_id", v_group_id);
DEBUGLOG(("GetOfflineAutoPostJnl group_id = [%d]\n",v_group_id));
		}

/* single */
		if (ind_single >= 0) {
			PutField_Int(myHash, "single", v_single);
DEBUGLOG(("GetOfflineAutoPostJnl single = [%d]\n",v_single));
		}

		RecordSet_Add(myRec,myHash);
	}
	/* EXEC SQL CLOSE getofljnlcursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )185;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getofljnl_error;
}



	if (iCnt > 0) {
		return FOUND;
DEBUGLOG(("GetOfflineAutoPostJnl FOUND %d JNL\n",iCnt));
	} else {
		return NOT_FOUND;
DEBUGLOG(("GetOfflineAutoPostJnl NOT FOUND\n"));
	}

getofljnl_error:
DEBUGLOG(("getofljnl_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL CLOSE getofljnlcursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )200;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getofljnl_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_INTERNAL_ERR;
}

int GetMiAutoPostJnl(recordset_t* myRec)
{
	int	iCnt = 0;
	hash_t	*myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO getmijnl_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		int	v_jnl_type_id;
		/* varchar	v_prefix[PD_JNL_TYPE_PREFIX_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[6]; } v_prefix;

		/* varchar	v_desc[PD_DESCRIPTION_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_desc;

		int	v_group_id;
		int	v_single;

		short	ind_jnl_type_id;
		short	ind_prefix = -1;
		short	ind_desc = -1;
		short	ind_group_id = -1;
		short	ind_single = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetMiAutoPostJnl: Begin\n"));

	/* EXEC SQL DECLARE getmijnlcursor CURSOR FOR
		SELECT  JNL.JNL_TYPE_ID,
			JNL.PREFIX,
			JNL.NAME,
			JEM.CMM_GROUP_ID,
			JEM.CMM_IS_SINGLE
		FROM    CRR_JNL_TYPE JNL,
			(SELECT	CMM_JNL_TYPE_ID, CMM_GROUP_ID, CMM_IS_SINGLE
			FROM	CRR_MI_JNL_ENTRY_TYPE_MAPPING
			WHERE	CMM_DISABLED = 0
			GROUP BY CMM_JNL_TYPE_ID, CMM_GROUP_ID, CMM_IS_SINGLE) JEM
		WHERE   JNL.POST_TYPE = 'N'
		AND	JNL.DISABLED = 0
		AND	JNL.JNL_TYPE_ID = JEM.CMM_JNL_TYPE_ID
		ORDER BY JNL.JNL_TYPE_ID ASC; */ 


	/* EXEC SQL OPEN getmijnlcursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0005;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )215;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getmijnl_error;
}


	for (;;) {
		/* EXEC SQL FETCH getmijnlcursor
		INTO    :v_jnl_type_id:ind_jnl_type_id,
			:v_prefix:ind_prefix,
			:v_desc:ind_desc,
			:v_group_id:ind_group_id,
			:v_single:ind_single; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 5;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )230;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_jnl_type_id;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_jnl_type_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_prefix;
  sqlstm.sqhstl[1] = (unsigned long )8;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_prefix;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_desc;
  sqlstm.sqhstl[2] = (unsigned long )103;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_desc;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_group_id;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_group_id;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_single;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_single;
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
  if (sqlca.sqlcode < 0) goto getmijnl_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

/* jnl_type_id */
		if (ind_jnl_type_id >= 0) {
			PutField_Int(myHash, "jnl_type_id", v_jnl_type_id);
DEBUGLOG(("GetMiAutoPostJnl jnl_type_id = [%d]\n",v_jnl_type_id));
		}

/* prefix */
		if (ind_prefix>=0) {
			v_prefix.arr[v_prefix.len] = '\0';
			PutField_CString(myHash,"prefix",(char*)v_prefix.arr);
DEBUGLOG(("GetMiAutoPostJnl prefix = [%s]\n",(char*)v_prefix.arr));
		}

/* desc */
		if (ind_desc>=0) {
			v_desc.arr[v_desc.len] = '\0';
			PutField_CString(myHash,"desc",(char*)v_desc.arr);
DEBUGLOG(("GetMiAutoPostJnl desc = [%s]\n",(char*)v_desc.arr));
		}

/* group_id */
		if (ind_group_id >= 0) {
			PutField_Int(myHash, "group_id", v_group_id);
DEBUGLOG(("GetMiAutoPostJnl group_id = [%d]\n",v_group_id));
		}

/* single */
		if (ind_single >= 0) {
			PutField_Int(myHash, "single", v_single);
DEBUGLOG(("GetMiAutoPostJnl single = [%d]\n",v_single));
		}

		RecordSet_Add(myRec,myHash);
	}
	/* EXEC SQL CLOSE getmijnlcursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )265;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getmijnl_error;
}



	if (iCnt > 0) {
		return FOUND;
DEBUGLOG(("GetMiAutoPostJnl FOUND %d JNL\n",iCnt));
	} else {
		return NOT_FOUND;
DEBUGLOG(("GetMiAutoPostJnl NOT FOUND\n"));
	}

getmijnl_error:
DEBUGLOG(("getmijnl_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL CLOSE getmijnlcursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )280;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getmijnl_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_INTERNAL_ERR;
}

