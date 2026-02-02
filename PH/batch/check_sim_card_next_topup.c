
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
           char  filnam[29];
};
static struct sqlcxp sqlfpn =
{
    28,
    "check_sim_card_next_topup.pc"
};


static unsigned int sqlctx = 1445634091;


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
   unsigned char  *sqhstv[9];
   unsigned long  sqhstl[9];
            int   sqhsts[9];
            short *sqindv[9];
            int   sqinds[9];
   unsigned long  sqharm[9];
   unsigned long  *sqharc[9];
   unsigned short  sqadto[9];
   unsigned short  sqtdso[9];
} sqlstm = {12,9};

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
"SELECT TO_CHAR ( TRUNC ( SYSDATE ) + 14 , 'YYYYMMDD' ) FROM DUAL           \
 ";

 static char *sq0002 = 
"SELECT A . OSC_MOBILE , E . OB_OWNER_NAME , F . BANK_NAME , G . AS_DESC , B\
 . DSC_CARRIER_NAME , C . COUNTRY_NAME , D . DSCS_STATUS_DESC , A . OSC_NEXT_\
TOPUP_DATE , A . OSC_REMARKS FROM OL_SIM_CARDS A , OL_DEF_SIM_CARRIERS B , CO\
UNTRY C , OL_DEF_SIM_CARD_STATUS D , OL_BANK_ACCTS E , BANK_DESC F , OL_DEF_A\
CCT_STATUS G WHERE A . OSC_CARRIERS = B . DSC_CARRIER_CODE AND A . OSC_COUNTR\
Y = C . COUNTRY_CODE AND A . OSC_STATUS = D . DSCS_STATUS_CODE AND A . OSC_MO\
BILE = E . OB_REGISTERED_MOBILE ( + ) AND A . OSC_NEXT_TOPUP_DATE <= :b0 AND \
A . OSC_STATUS != 'D' AND ( A . OSC_SIM_NATURE IS NULL OR A . OSC_SIM_NATURE \
= :b1 ) AND E . OB_INT_BANK_CODE = F . INTERNAL_BANK_CODE AND E . OB_STATUS_T\
YPE = G . AS_TYPE ORDER BY A . OSC_NEXT_TOPUP_DATE , A . OSC_MOBILE          \
  ";

 static char *sq0003 = 
"SELECT A . OSC_MOBILE , E . OB_OWNER_NAME , F . BANK_NAME , G . AS_DESC , B\
 . DSC_CARRIER_NAME , C . COUNTRY_NAME , D . DSCS_STATUS_DESC , A . OSC_NEXT_\
TOPUP_DATE , A . OSC_REMARKS FROM OL_SIM_CARDS A , OL_DEF_SIM_CARRIERS B , CO\
UNTRY C , OL_DEF_SIM_CARD_STATUS D , OL_BANK_ACCTS E , BANK_DESC F , OL_DEF_A\
CCT_STATUS G WHERE A . OSC_CARRIERS = B . DSC_CARRIER_CODE AND A . OSC_COUNTR\
Y = C . COUNTRY_CODE AND A . OSC_STATUS = D . DSCS_STATUS_CODE AND A . OSC_MO\
BILE = E . OB_REGISTERED_MOBILE ( + ) AND A . OSC_NEXT_TOPUP_DATE <= :b0 AND \
A . OSC_STATUS != 'D' AND A . OSC_SIM_NATURE = :b1 AND E . OB_INT_BANK_CODE =\
 F . INTERNAL_BANK_CODE AND E . OB_STATUS_TYPE = G . AS_TYPE ORDER BY A . OSC\
_NEXT_TOPUP_DATE , A . OSC_MOBILE            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,76,0,9,99,0,2049,0,0,0,1,0,
20,0,0,1,0,0,13,101,0,0,1,0,0,1,0,2,9,0,0,
39,0,0,1,0,0,15,110,0,0,0,0,0,1,0,
54,0,0,2,770,0,9,147,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
77,0,0,2,0,0,13,149,0,0,9,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,
128,0,0,2,0,0,15,205,0,0,0,0,0,1,0,
143,0,0,3,736,0,9,268,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
166,0,0,3,0,0,13,270,0,0,9,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,
217,0,0,3,0,0,15,326,0,0,0,0,0,1,0,
232,0,0,1,0,0,15,377,0,0,0,0,0,1,0,
247,0,0,2,0,0,15,378,0,0,0,0,0,1,0,
262,0,0,3,0,0,15,379,0,0,0,0,0,1,0,
277,0,0,4,0,0,32,380,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/09/12              Dirk Wong 
Modify to send alert within 14 Days		   2015/02/05		   Dirk Wong
#1175, modify alert content			   2015/08/19		   Dirk Wong
#1254, add bank name, bank status		   2015/12/14		   Elvis Wong
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

int iTplType=0;
char csTag[PD_TAG_LEN+1];
char csTmp[PD_TMP_BUF_LEN+1];
char cDebug;

int iDynCnt=0;

OBJPTR(BO);

int parse_arg(int argc,char **argv);

int batch_init(int argc, char* argv[])
{
        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int     iRet = parse_arg(argc,argv);
	int	iChk = 0;

	hash_t *hContext;

	if (iRet != SUCCESS) {
		iTplType = 0;
	}

	hContext = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hContext,0);

	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar hv_alert_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } hv_alert_date;

		/* varchar	hv_sim_nature[PD_ACCT_TYPE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_sim_nature;

		short	ind_alert_date = -1;

		/* varchar	v_mobile[PD_CUSTOMER_TEL_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_mobile;

		/* varchar	v_owner_name[PD_BANK_ACCT_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_owner_name;

		/* varchar v_bank_name[PD_AC_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

		/* varchar v_bank_status[PD_DESC_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_status;

		/* varchar	v_carriers[PD_DESC_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_carriers;

		/* varchar	v_country[PD_DESC_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_country;

		/* varchar v_status[PD_DESC_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_status;

		/* varchar	v_next_topup_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_next_topup_date;

		/* varchar	v_remarks[PD_SIM_CARDS_REMARKS_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_remarks;


		short	ind_mobile = -1;
		short	ind_owner_name = -1;
		short 	ind_bank_name = -1;
		short	ind_bank_status = -1;
		short	ind_carriers = -1;
		short	ind_country = -1;
		short	ind_status = -1;
		short	ind_next_topup_date = -1;
		short	ind_remarks = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	/* EXEC SQL DECLARE c_cursor_getalertdate CURSOR FOR
		SELECT	TO_CHAR(TRUNC(SYSDATE)+14,'YYYYMMDD')
		FROM	DUAL; */ 


	/* EXEC SQL OPEN c_cursor_getalertdate; */ 

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
 if (sqlca.sqlcode < 0) goto sql_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getalertdate
		INTO
			:hv_alert_date:ind_alert_date; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 1;
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
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_alert_date;
  sqlstm.sqhstl[0] = (unsigned long )11;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_alert_date;
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
	}
	while(PD_TRUE);
	/* EXEC SQL CLOSE c_cursor_getalertdate; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )39;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto sql_error;
}



	hv_sim_nature.len = strlen(PD_NATURE_DEPOSIT);
	memcpy(hv_sim_nature.arr,PD_NATURE_DEPOSIT,hv_sim_nature.len);

//Deposit and New
	/* EXEC SQL DECLARE c_cursor_getdsilist CURSOR FOR
		SELECT  A.OSC_MOBILE,
			E.OB_OWNER_NAME,
			F.BANK_NAME,
			G.AS_DESC,
			B.DSC_CARRIER_NAME,
			C.COUNTRY_NAME,
			D.DSCS_STATUS_DESC,
			A.OSC_NEXT_TOPUP_DATE,
			A.OSC_REMARKS
		FROM    OL_SIM_CARDS A,
			OL_DEF_SIM_CARRIERS B,
			COUNTRY C,
			OL_DEF_SIM_CARD_STATUS D,
			OL_BANK_ACCTS E,
			BANK_DESC F,
			OL_DEF_ACCT_STATUS G
		WHERE   A.OSC_CARRIERS = B.DSC_CARRIER_CODE
		  AND	A.OSC_COUNTRY = C.COUNTRY_CODE
		  AND	A.OSC_STATUS = D.DSCS_STATUS_CODE
		  AND	A.OSC_MOBILE = E.OB_REGISTERED_MOBILE(+)
		  AND	A.OSC_NEXT_TOPUP_DATE <= :hv_alert_date
		  AND	A.OSC_STATUS != 'D'
		  AND	(A.OSC_SIM_NATURE IS NULL OR
			 A.OSC_SIM_NATURE = :hv_sim_nature)
		  AND	E.OB_INT_BANK_CODE = F.INTERNAL_BANK_CODE
		  AND	E.OB_STATUS_TYPE = G.AS_TYPE 	
		ORDER BY
			A.OSC_NEXT_TOPUP_DATE,
			A.OSC_MOBILE; */ 
	

	/* EXEC SQL OPEN c_cursor_getdsilist; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )54;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_alert_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_sim_nature;
 sqlstm.sqhstl[1] = (unsigned long )6;
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
 if (sqlca.sqlcode < 0) goto sql_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getdsilist
		INTO
			:v_mobile:ind_mobile,
			:v_owner_name:ind_owner_name,
			:v_bank_name:ind_bank_name,
			:v_bank_status:ind_bank_status,
			:v_carriers:ind_carriers,
			:v_country:ind_country,
			:v_status:ind_status,
			:v_next_topup_date:ind_next_topup_date,
			:v_remarks:ind_remarks; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )77;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_mobile;
  sqlstm.sqhstl[0] = (unsigned long )23;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_mobile;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_owner_name;
  sqlstm.sqhstl[1] = (unsigned long )53;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_owner_name;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_bank_name;
  sqlstm.sqhstl[2] = (unsigned long )153;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_bank_name;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_bank_status;
  sqlstm.sqhstl[3] = (unsigned long )53;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_bank_status;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_carriers;
  sqlstm.sqhstl[4] = (unsigned long )53;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_carriers;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_country;
  sqlstm.sqhstl[5] = (unsigned long )53;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_country;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[6] = (unsigned long )53;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_status;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_next_topup_date;
  sqlstm.sqhstl[7] = (unsigned long )11;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_next_topup_date;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_remarks;
  sqlstm.sqhstl[8] = (unsigned long )103;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_remarks;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
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

		/*fmobile*/
			sprintf(csTag,"fmobile-%d",iChk);
			sprintf(csTmp,"%.*s",v_mobile.len,v_mobile.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","stbl_body-0",csTmp);
		/*fowner_name*/
			sprintf(csTag,"fowner_name-%d",iChk);
			sprintf(csTmp,"%.*s",v_owner_name.len,v_owner_name.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","stbl_body-0",csTmp);
		/*fbank_name*/
			sprintf(csTag,"fbank_name-%d",iChk);
                        sprintf(csTmp,"%.*s",v_bank_name.len,v_bank_name.arr);
                        iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","stbl_body-0",csTmp);			
		/*fbank_status*/
			sprintf(csTag,"fbank_status-%d",iChk);
                        sprintf(csTmp,"%.*s",v_bank_status.len,v_bank_status.arr);
                        iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","stbl_body-0",csTmp);		
		/*fcarriers*/
			sprintf(csTag,"fcarriers-%d",iChk);
			sprintf(csTmp,"%.*s",v_carriers.len,v_carriers.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","stbl_body-0",csTmp);
		/*fcountry*/
			sprintf(csTag,"fcountry-%d",iChk);
			sprintf(csTmp,"%.*s",v_country.len,v_country.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","stbl_body-0",csTmp);
		/*fstatus*/
			sprintf(csTag,"fstatus-%d",iChk);
			sprintf(csTmp,"%.*s",v_status.len,v_status.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","stbl_body-0",csTmp);
		/*fnext_topup_date*/
			sprintf(csTag,"fnext_topup_date-%d",iChk);
			sprintf(csTmp,"%.*s",v_next_topup_date.len,v_next_topup_date.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","stbl_body-0",csTmp);
		/*fremarks*/
			sprintf(csTag,"fremarks-%d",iChk);
			sprintf(csTmp,"%.*s",v_remarks.len,v_remarks.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","stbl_body-0",csTmp);

		iChk ++;
	}
	while(PD_TRUE && iRet == SUCCESS);
	/* EXEC SQL CLOSE c_cursor_getdsilist; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )128;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto sql_error;
}



/*stimestamp*/
	iDynCnt = set_tpl_dyn_int(hContext,iDynCnt,"stimestamp-0","SEC","stimestamp-0",0);
/*ftimestamp*/
	iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,"ftimestamp-0","STR","stimestamp-0",write_tpl_timestamp());

/*stitle*/
	iDynCnt = set_tpl_dyn_int(hContext,iDynCnt,"stitle-0","SEC","stitle-0",0);
/*ftitle*/
	sprintf(csTmp, "Sim Cards Topup Next hit on %.*s",hv_alert_date.len,hv_alert_date.arr);
	iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,"ftitle-0","STR","stitle-0",csTmp);

	if (iChk == 0)
	{
		//Print no record
		iDynCnt = set_tpl_dyn_int(hContext, iDynCnt, "stbl_norecord-0", "SEC", "stbl_norecord-0", 0);
		sprintf(csTmp,"%.*s",hv_alert_date.len,hv_alert_date.arr);
		iDynCnt = set_tpl_dyn_cstring(hContext, iDynCnt, "fnext_topup_date-0", "STR", "stbl_norecord-0", csTmp);
	}
	else
	{
		iDynCnt = set_tpl_dyn_int(hContext, iDynCnt, "stbl_head-0", "SEC", "stbl_head-0", 0);
		iDynCnt = set_tpl_dyn_int(hContext, iDynCnt, "stbl_body-0", "SEC", "stbl_body-0", iChk);
	}


//Payout
	iChk = 0;

	hv_sim_nature.len = strlen(PD_NATURE_PAYOUT);
	memcpy(hv_sim_nature.arr,PD_NATURE_PAYOUT,hv_sim_nature.len);

	/* EXEC SQL DECLARE c_cursor_getpoalist CURSOR FOR
		SELECT  A.OSC_MOBILE,
			E.OB_OWNER_NAME,
			F.BANK_NAME,
			G.AS_DESC,
			B.DSC_CARRIER_NAME,
			C.COUNTRY_NAME,
			D.DSCS_STATUS_DESC,
			A.OSC_NEXT_TOPUP_DATE,
			A.OSC_REMARKS
		FROM    OL_SIM_CARDS A,
			OL_DEF_SIM_CARRIERS B,
			COUNTRY C,
			OL_DEF_SIM_CARD_STATUS D,
			OL_BANK_ACCTS E,
			BANK_DESC F,
                        OL_DEF_ACCT_STATUS G
		WHERE   A.OSC_CARRIERS = B.DSC_CARRIER_CODE
		  AND	A.OSC_COUNTRY = C.COUNTRY_CODE
		  AND	A.OSC_STATUS = D.DSCS_STATUS_CODE
		  AND	A.OSC_MOBILE = E.OB_REGISTERED_MOBILE(+)
		  AND	A.OSC_NEXT_TOPUP_DATE <= :hv_alert_date
		  AND	A.OSC_STATUS != 'D'
		  AND	A.OSC_SIM_NATURE = :hv_sim_nature
		  AND   E.OB_INT_BANK_CODE = F.INTERNAL_BANK_CODE
                  AND   E.OB_STATUS_TYPE = G.AS_TYPE
		ORDER BY
			A.OSC_NEXT_TOPUP_DATE,
			A.OSC_MOBILE; */ 
	

	/* EXEC SQL OPEN c_cursor_getpoalist; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )143;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_alert_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_sim_nature;
 sqlstm.sqhstl[1] = (unsigned long )6;
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
 if (sqlca.sqlcode < 0) goto sql_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getpoalist
		INTO
			:v_mobile:ind_mobile,
			:v_owner_name:ind_owner_name,
			:v_bank_name:ind_bank_name,
			:v_bank_status:ind_bank_status,
			:v_carriers:ind_carriers,
			:v_country:ind_country,
			:v_status:ind_status,
			:v_next_topup_date:ind_next_topup_date,
			:v_remarks:ind_remarks; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )166;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_mobile;
  sqlstm.sqhstl[0] = (unsigned long )23;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_mobile;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_owner_name;
  sqlstm.sqhstl[1] = (unsigned long )53;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_owner_name;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_bank_name;
  sqlstm.sqhstl[2] = (unsigned long )153;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_bank_name;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_bank_status;
  sqlstm.sqhstl[3] = (unsigned long )53;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_bank_status;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_carriers;
  sqlstm.sqhstl[4] = (unsigned long )53;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_carriers;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_country;
  sqlstm.sqhstl[5] = (unsigned long )53;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_country;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[6] = (unsigned long )53;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_status;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_next_topup_date;
  sqlstm.sqhstl[7] = (unsigned long )11;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_next_topup_date;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_remarks;
  sqlstm.sqhstl[8] = (unsigned long )103;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_remarks;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
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

		/*fmobile*/
			sprintf(csTag,"fpoa_mobile-%d",iChk);
			sprintf(csTmp,"%.*s",v_mobile.len,v_mobile.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","spoa_body-0",csTmp);
		/*fowner_name*/
			sprintf(csTag,"fpoa_owner_name-%d",iChk);
			sprintf(csTmp,"%.*s",v_owner_name.len,v_owner_name.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","spoa_body-0",csTmp);
		/*fbank_name*/
			sprintf(csTag,"fpoa_bank_name-%d",iChk);
                        sprintf(csTmp,"%.*s",v_bank_name.len,v_bank_name.arr);
                        iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","spoa_body-0",csTmp);
		/*fbank_status*/
			sprintf(csTag,"fpoa_bank_status-%d",iChk);
                        sprintf(csTmp,"%.*s",v_bank_status.len,v_bank_status.arr);
                        iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","spoa_body-0",csTmp);
		/*fcarriers*/
			sprintf(csTag,"fpoa_carriers-%d",iChk);
			sprintf(csTmp,"%.*s",v_carriers.len,v_carriers.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","spoa_body-0",csTmp);
		/*fcountry*/
			sprintf(csTag,"fpoa_country-%d",iChk);
			sprintf(csTmp,"%.*s",v_country.len,v_country.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","spoa_body-0",csTmp);
		/*fstatus*/
			sprintf(csTag,"fpoa_status-%d",iChk);
			sprintf(csTmp,"%.*s",v_status.len,v_status.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","spoa_body-0",csTmp);
		/*fnext_topup_date*/
			sprintf(csTag,"fpoa_next_topup_date-%d",iChk);
			sprintf(csTmp,"%.*s",v_next_topup_date.len,v_next_topup_date.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","spoa_body-0",csTmp);
		/*fremarks*/
			sprintf(csTag,"fpoa_remarks-%d",iChk);
			sprintf(csTmp,"%.*s",v_remarks.len,v_remarks.arr);
			iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,csTag,"STR","spoa_body-0",csTmp);

		iChk ++;
	}
	while(PD_TRUE && iRet == SUCCESS);
	/* EXEC SQL CLOSE c_cursor_getpoalist; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )217;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto sql_error;
}



/*stimestamp*/
	iDynCnt = set_tpl_dyn_int(hContext,iDynCnt,"spoa_ts-0","SEC","spoa_ts-0",0);
/*ftimestamp*/
	iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,"fpoa_ts-0","STR","spoa_ts-0",write_tpl_timestamp());

	if (iChk == 0)
	{
		//Print no record
		iDynCnt = set_tpl_dyn_int(hContext, iDynCnt, "spoa_norecord-0", "SEC", "spoa_norecord-0", 0);
		sprintf(csTmp,"%.*s",hv_alert_date.len,hv_alert_date.arr);
		iDynCnt = set_tpl_dyn_cstring(hContext, iDynCnt, "fpoa_next_topup_date-0", "STR", "spoa_tbl_norecord-0", csTmp);
	}
	else
	{
		iDynCnt = set_tpl_dyn_int(hContext, iDynCnt, "spoa_head-0", "SEC", "spoa_head-0", 0);
		iDynCnt = set_tpl_dyn_int(hContext, iDynCnt, "spoa_body-0", "SEC", "spoa_body-0", iChk);
	}


//Global Variables
	iDynCnt = set_tpl_dyn_cstring(hContext,iDynCnt,"MAIL_SUBJECT","GLO","STR","Sim Cards Top-up Next Two Weeks");

	PutField_CString(hContext,"source","BATCH");
	PutField_CString(hContext,"funct","SIM_CARD_REPORT");
	PutField_Char(hContext,"party_type",'G');
	PutField_CString(hContext,"party_id","000");

	PutField_Int(hContext,"total_dyn",iDynCnt);

	BOObjPtr = CreateObj(BOPtr,"BOAlertEmail","ProcessTpl");
	if((unsigned long)((*BOObjPtr)(hContext) != PD_OK)){
		iRet=INT_CODE_ERROR;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::ProcessTpl Failed\n"));
ERRLOG("TxnMgtByUsALT::Authorize::ProcessTpl Failed, iRet=%d\n", iRet);
	}
	else
	{
DEBUGLOG(("Authorize::ProcessTpl Success\n"));
	}

	FREE_ME(hContext);

	return iRet;

sql_error:
DEBUGLOG(("check_sim_card_next_topup error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getalertdate; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 9;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )232;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    /* EXEC SQL CLOSE c_cursor_getdsilist; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 9;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )247;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    /* EXEC SQL CLOSE c_cursor_getpoalist; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 9;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )262;
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
    sqlstm.arrsiz = 9;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )277;
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
/*
        char    c;

        if (argc < 2) {
                return PD_ERR;
        }
        while ((c = getopt(argc,argv,"t:")) != EOF) {
                switch (c) {
                        case 't':
                                iTplType = atoi(optarg);
                                break;
                        default:
                                return PD_ERR;
                }
        }
*/
        return SUCCESS;
}
