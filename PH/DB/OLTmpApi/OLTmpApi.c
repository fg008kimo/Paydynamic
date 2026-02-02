
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
           char  filnam[12];
};
static struct sqlcxp sqlfpn =
{
    11,
    "OLTmpApi.pc"
};


static unsigned int sqlctx = 160643;


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
"select ota_tag_value from ol_tmp_api where ota_batch_id = :b0 and ota_tag_n\
ame = 'cnt' and ota_seq = 1 and ota_sub_seq = 1            ";

 static char *sq0002 = 
"select ota_tag_value from ol_tmp_api where ota_batch_id = :b0 and ota_tag_n\
ame = 'order' and ota_seq = 1 order by ota_sub_seq            ";

 static char *sq0003 = 
"select ota_seq , ota_sub_seq , ota_tag_value from ol_tmp_api where ota_batc\
h_id = :b0 and ota_tag_name = 'detail' order by ota_seq , ota_sub_seq        \
    ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,134,0,9,58,0,2049,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,13,60,0,0,1,0,0,1,0,2,9,0,0,
43,0,0,1,0,0,15,73,0,0,0,0,0,1,0,
58,0,0,1,0,0,15,83,0,0,0,0,0,1,0,
73,0,0,2,137,0,9,117,0,2049,1,1,0,1,0,1,9,0,0,
92,0,0,2,0,0,13,119,0,0,1,0,0,1,0,2,9,0,0,
111,0,0,2,0,0,15,141,0,0,0,0,0,1,0,
126,0,0,2,0,0,15,155,0,0,0,0,0,1,0,
141,0,0,3,156,0,9,201,0,2049,1,1,0,1,0,1,9,0,0,
160,0,0,3,0,0,13,203,0,0,3,0,0,1,0,2,3,0,0,2,3,0,0,2,9,0,0,
187,0,0,3,0,0,15,262,0,0,0,0,0,1,0,
202,0,0,3,0,0,15,278,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/07/22              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "OLTmpApi.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char cDebug;


void OLTmpApi(char cdebug)
{
	cDebug = cdebug;
}


int GetEditCnt(const char *csBatchId,
	hash_t *hRec)
{
	int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO geteditcnt_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_batch_id[PD_BSE_BATCH_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;

		/* varchar	v_tag_value[PD_BSE_TAG_VALUE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4001]; } v_tag_value;

		short ind_tag_value = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_batch_id.len = strlen(csBatchId);
	memcpy(hv_batch_id.arr, csBatchId, hv_batch_id.len);
DEBUGLOG(("GetEditCnt:: batch_id = [%.*s]\n", hv_batch_id.len, hv_batch_id.arr));

	/* EXEC SQL DECLARE c_cursor_geteditcnt CURSOR FOR
		select ota_tag_value
		from ol_tmp_api
		where ota_batch_id = :hv_batch_id
		and ota_tag_name = 'cnt'
		and ota_seq = 1
		and ota_sub_seq = 1; */ 


	/* EXEC SQL OPEN c_cursor_geteditcnt; */ 

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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[0] = (unsigned long )18;
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
 if (sqlca.sqlcode < 0) goto geteditcnt_error;
}



	/* EXEC SQL FETCH c_cursor_geteditcnt
	INTO	:v_tag_value:ind_tag_value; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
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
 sqlstm.sqhstv[0] = (unsigned char  *)&v_tag_value;
 sqlstm.sqhstl[0] = (unsigned long )4003;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_tag_value;
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
 if (sqlca.sqlcode < 0) goto geteditcnt_error;
}



	/* tag_values */
	if (ind_tag_value >= 0) {
		v_tag_value.arr[v_tag_value.len] = '\0';
DEBUGLOG(("GetEditCnt:: tag_value = [%s]\n", v_tag_value.arr));
		PutField_CString(hRec, PD_BSE_CNT, (const char *)v_tag_value.arr);
	} else {
DEBUGLOG(("GetEditCnt:: get cnt error\n"));
		iRet = PD_ERR;
	}

	/* EXEC SQL CLOSE c_cursor_geteditcnt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )43;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto geteditcnt_error;
}



DEBUGLOG(("GetEditCnt:: Normal Exit [%d]\n", iRet));
	return iRet;

geteditcnt_error:
DEBUGLOG(("geteditcnt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLTmpApi_GetEditCnt: SP_INTERNAL_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_geteditcnt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
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


	return PD_ERR;
}


int GetEditOrder(const char *csBatchId,
	hash_t *hRec)
{
	int iRet = PD_OK;
	int iFound = 0;
	char csOrder[PD_MAX_BUFFER];
	csOrder[0] = '\0';

	/* EXEC SQL WHENEVER SQLERROR GOTO geteditorder_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_batch_id[PD_BSE_BATCH_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;

		/* varchar	v_tag_value[PD_BSE_TAG_VALUE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4001]; } v_tag_value;

		short ind_tag_value = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_batch_id.len = strlen(csBatchId);
	memcpy(hv_batch_id.arr, csBatchId, hv_batch_id.len);
DEBUGLOG(("GetEditOrder:: batch_id = [%.*s]\n", hv_batch_id.len, hv_batch_id.arr));

	/* EXEC SQL DECLARE c_cursor_geteditorder CURSOR FOR
		select ota_tag_value
		from ol_tmp_api
		where ota_batch_id = :hv_batch_id
		and ota_tag_name = 'order'
		and ota_seq = 1
		order by ota_sub_seq; */ 


	/* EXEC SQL OPEN c_cursor_geteditorder; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )73;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[0] = (unsigned long )18;
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
 if (sqlca.sqlcode < 0) goto geteditorder_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_geteditorder
		INTO	:v_tag_value:ind_tag_value; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 1;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )92;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_tag_value;
  sqlstm.sqhstl[0] = (unsigned long )4003;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_tag_value;
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
  if (sqlca.sqlcode < 0) goto geteditorder_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		/* tag_values */
		if (ind_tag_value >= 0) {
			v_tag_value.arr[v_tag_value.len] = '\0';
//DEBUGLOG(("GetEditOrder:: tag_value = [%s]\n", v_tag_value.arr));
			sprintf(csOrder, "%s%s", csOrder, (const char *)v_tag_value.arr);
//DEBUGLOG(("GetEditOrder:: csOrder = [%s]\n", csOrder));
			iFound++;
		} else {
DEBUGLOG(("GetEditOrder:: get order error\n"));
			iFound = 0;
			iRet = PD_ERR;
			break;
		}
	} while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_geteditorder; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )111;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto geteditorder_error;
}



	if (iFound > 0) {
		PutField_CString(hRec, PD_BSE_ORDER, (const char *)csOrder);
	}

DEBUGLOG(("GetEditOrder:: Normal Exit [%d]\n", iRet));
	return iRet;

geteditorder_error:
DEBUGLOG(("geteditorder_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLTmpApi_GetEditOrder: SP_INTERNAL_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_geteditorder; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )126;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}


int GetEditDetail(const char *csBatchId,
	hash_t *hRec)
{
	int iRet = PD_OK;
	int iDetailCnt = 0;
	char csTag[PD_TAG_LEN + 1];
	char csDetail[PD_MAX_BUFFER];
	csDetail[0] = '\0';
	int iLastSeq = 0;
	char *csTmp = NULL;
	int iDBCnt = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO geteditdetail_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_batch_id[PD_BSE_BATCH_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;


		int v_seq;
		int v_sub_seq;
		/* varchar	v_tag_value[PD_BSE_TAG_VALUE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4001]; } v_tag_value;


		short ind_seq = -1;
		short ind_sub_seq = -1;
		short ind_tag_value = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	GetField_CString(hRec, "cnt", &csTmp);
	iDBCnt = atoi(csTmp);

	hv_batch_id.len = strlen(csBatchId);
	memcpy(hv_batch_id.arr, csBatchId, hv_batch_id.len);
DEBUGLOG(("GetEditDetail:: batch_id = [%.*s]\n", hv_batch_id.len, hv_batch_id.arr));

	/* EXEC SQL DECLARE c_cursor_geteditdetail CURSOR FOR
		select ota_seq, ota_sub_seq, ota_tag_value
		from ol_tmp_api
		where ota_batch_id = :hv_batch_id
		and ota_tag_name = 'detail'
		order by ota_seq, ota_sub_seq; */ 


	/* EXEC SQL OPEN c_cursor_geteditdetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )141;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[0] = (unsigned long )18;
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
 if (sqlca.sqlcode < 0) goto geteditdetail_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_geteditdetail
		INTO	:v_seq:ind_seq,
			:v_sub_seq:ind_sub_seq,
			:v_tag_value:ind_tag_value; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 3;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )160;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_seq;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_seq;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_sub_seq;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_sub_seq;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_tag_value;
  sqlstm.sqhstl[2] = (unsigned long )4003;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_tag_value;
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
  if (sqlca.sqlcode < 0) goto geteditdetail_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		/* tag seq */
		if (ind_seq >= 0) {
//DEBUGLOG(("GetEditDetail:: seq = [%d]\n", v_seq));
		} else {
DEBUGLOG(("GetEditDetail:: get seq error\n"));
			iRet = PD_ERR;
			break;
		}

		/* tag_sub_seq */
		if (ind_sub_seq >= 0) {
//DEBUGLOG(("GetEditDetail:: sub_seq = [%d]\n", v_sub_seq));
		} else {
DEBUGLOG(("GetEditDetail:: get sub_seq error\n"));
			iRet = PD_ERR;
			break;
		}

		/* tag_values */
		if (ind_tag_value >= 0) {
			v_tag_value.arr[v_tag_value.len] = '\0';
//DEBUGLOG(("GetEditDetail:: tag_value = [%s]\n", v_tag_value.arr));
		} else {
DEBUGLOG(("GetEditDetail:: get detail error\n"));
			iRet = PD_ERR;
			break;
		}

		if (v_seq != iLastSeq) {
			if (iLastSeq != 0) {
				// put last csDetail into hash
				iDetailCnt++;
				sprintf(csTag, "dt_i_%d", iLastSeq);
//DEBUGLOG(("GetEditDetail:: %s = [%s]\n", csTag, csDetail));
				PutField_CString(hRec, csTag, (const char *)csDetail);
			}
			csDetail[0] = '\0';
		}

		sprintf(csDetail, "%s%s", csDetail, (const char *)v_tag_value.arr);
		iLastSeq = v_seq;
	} while (PD_TRUE);

	if ((iRet == PD_OK) && (iLastSeq != 0)) {
		iDetailCnt++;
		sprintf(csTag, "dt_i_%d", iLastSeq);
//DEBUGLOG(("GetEditDetail:: %s = [%s]\n", csTag, csDetail));
		PutField_CString(hRec, csTag, (const char *)csDetail);
	}

	/* EXEC SQL CLOSE c_cursor_geteditdetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )187;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto geteditdetail_error;
}



DEBUGLOG(("GetEditDetail:: iDetailCnt = [%d], iDBCnt = [%d]\n", iDetailCnt, iDBCnt));
	if (iDetailCnt != iDBCnt) {
DEBUGLOG(("GetEditDetail:: count not match\n"));
		iRet = PD_ERR;
	}

DEBUGLOG(("GetEditDetail:: Normal Exit [%d]\n", iRet));
	return iRet;

geteditdetail_error:
DEBUGLOG(("geteditdetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLTmpApi_GetEditDetail: SP_INTERNAL_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_geteditdetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )202;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

