
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
    "MmsInstantPMAcctDt.pc"
};


static unsigned int sqlctx = 162824251;


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
"select mid_party_name , mid_mms_node_id from mms_instant_pm_acct_dt where m\
id_party_type = :b0 and mid_business_type = :b1 and mid_party_id = :b2       \
     ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,262,0,6,103,0,0,7,7,0,1,0,2,3,0,0,1,1,0,0,1,1,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,1,9,0,0,
48,0,0,2,157,0,9,190,0,2049,3,3,0,1,0,1,1,0,0,1,1,0,0,1,9,0,0,
75,0,0,2,0,0,13,192,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
98,0,0,2,0,0,15,218,0,0,0,0,0,1,0,
113,0,0,2,0,0,15,236,0,0,0,0,0,1,0,
128,0,0,3,101,0,6,269,0,0,3,3,0,1,0,2,3,0,0,1,1,0,0,1,1,0,0,
155,0,0,4,234,0,6,367,0,0,6,6,0,1,0,2,3,0,0,1,1,0,0,1,1,0,0,1,9,0,0,1,9,0,0,2,
9,0,0,
194,0,0,0,0,0,56,480,0,0,1,1,0,1,0,3,102,0,0,
213,0,0,5,225,0,6,481,0,0,6,6,0,1,0,2,3,0,0,1,1,0,0,1,1,0,0,1,9,0,0,1,9,0,0,2,
102,0,0,
252,0,0,0,0,0,13,503,0,0,4,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
283,0,0,0,0,0,15,536,0,0,1,1,0,1,0,1,102,0,0,
302,0,0,0,0,0,78,537,0,0,1,1,0,1,0,3,102,0,0,
321,0,0,0,0,0,15,542,0,0,1,1,0,1,0,1,102,0,0,
340,0,0,0,0,0,78,543,0,0,1,1,0,1,0,3,102,0,0,
359,0,0,0,0,0,15,548,0,0,1,1,0,1,0,1,102,0,0,
378,0,0,0,0,0,78,549,0,0,1,1,0,1,0,3,102,0,0,
397,0,0,0,0,0,15,553,0,0,1,1,0,1,0,1,102,0,0,
416,0,0,0,0,0,78,554,0,0,1,1,0,1,0,3,102,0,0,
435,0,0,0,0,0,15,564,0,0,1,1,0,1,0,1,102,0,0,
454,0,0,0,0,0,78,565,0,0,1,1,0,1,0,3,102,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/12/23              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "MmsInstantPMAcctDt.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char    cDebug;

void MmsInstantPMAcctDt(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const hash_t *hRls)
{
	char  cTmp;
	char  *csTmp;
	/*int   iTmp;*/

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		char		hv_party_type;
		char		hv_business_type;
		/* varchar		hv_party_id[PD_MMS_PARTY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_party_id;

		/* varchar		hv_party_name[PD_MMS_PARTY_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_party_name;

		/* varchar		hv_mms_node_id[PD_MMS_MMC_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[5]; } hv_mms_node_id;

		/* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_party_type = -1;
		short		ind_business_type = -1;
		short		ind_party_id = -1;
		short		ind_party_name = -1;
		short		ind_mms_node_id = -1;
		short		ind_create_user = -1;

		short		hv_return_value;	
		
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

	if (GetField_Char(hRls, "party_type", &cTmp)) {	
		hv_party_type = cTmp;
		ind_party_type = 0;
	}
DEBUGLOG(("Add:party_type = [%c]\n",hv_party_type));

	if (GetField_Char(hRls, "business_type", &cTmp)) {
		hv_business_type = cTmp;
		ind_business_type = 0;
	}	
DEBUGLOG(("Add:business_type = [%c]\n",hv_business_type));

        if(GetField_CString(hRls,"party_id",&csTmp)) {
                hv_party_id.len = strlen(csTmp);
                strncpy((char*)hv_party_id.arr, csTmp, hv_party_id.len);
                ind_party_id = 0;
        }
DEBUGLOG(("Add:party_id = [%.*s]\n",hv_party_id.len, hv_party_id.arr));

        if(GetField_CString(hRls,"party_name",&csTmp)) {
                hv_party_name.len = strlen(csTmp);
                strncpy((char*)hv_party_name.arr, csTmp, hv_party_name.len);
                ind_party_name = 0;
        }
DEBUGLOG(("Add:party_name = [%.*s]\n",hv_party_name.len, hv_party_name.arr));

        if(GetField_CString(hRls,"mms_node_id",&csTmp)) {
                hv_mms_node_id.len = strlen(csTmp);
                strncpy((char*)hv_mms_node_id.arr, csTmp, hv_mms_node_id.len);
                ind_mms_node_id = 0;
        }
DEBUGLOG(("Add:mms_node_id = [%.*s]\n",hv_mms_node_id.len, hv_mms_node_id.arr));


        if(GetField_CString(hRls,"add_user",&csTmp))
        {
                hv_create_user.len = strlen(csTmp);
                strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
                ind_create_user = 0;
        }
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_mms_instant_pmacct_dt_ins(
						:hv_party_type:ind_party_type,
						:hv_business_type:ind_business_type,
						:hv_party_id:ind_party_id,
						:hv_party_name:ind_party_name,
						:hv_mms_node_id:ind_mms_node_id,
						:hv_create_user:ind_create_user); 
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_mms_instant_pmacct_dt_ins ( :h\
v_party_type:ind_party_type , :hv_business_type:ind_business_type , :hv_party\
_id:ind_party_id , :hv_party_name:ind_party_name , :hv_mms_node_id:ind_mms_no\
de_id , :hv_create_user:ind_create_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_party_type;
 sqlstm.sqhstl[1] = (unsigned long )1;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_party_type;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_business_type;
 sqlstm.sqhstl[2] = (unsigned long )1;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_business_type;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_party_id;
 sqlstm.sqhstl[3] = (unsigned long )17;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_party_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_party_name;
 sqlstm.sqhstl[4] = (unsigned long )52;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_party_name;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_mms_node_id;
 sqlstm.sqhstl[5] = (unsigned long )7;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_mms_node_id;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[6] = (unsigned long )22;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto add_error;
}



        DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
                DEBUGLOG(("Add:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
                ERRLOG("MmsInstantPMAcctDt_Add: SP_OTHER_ERR TxnAbort\n");
                DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
                ERRLOG("MmsInstantPMAcctDt_Add: SP_ERR TxnAbort\n");
                DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		TxnAbort();
                return PD_ERR;
        }


add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MmsInstantPMAcctDt_Add: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
        return PD_ERR;


}

int	GetSingleDetail(const char cPartyType, 
			const char cBusinessType,
			const char *csPartyId,
			hash_t *hContext)
{
	int 	iCnt = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO getsingledetail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		char		hv_party_type;
		char		hv_business_type;	
		/* varchar		hv_party_id [PD_MMS_PARTY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_party_id;


		/* varchar		v_party_name[PD_MMS_PARTY_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_party_name;

		/* varchar		v_mms_node_id[PD_MMS_MMC_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[6]; } v_mms_node_id;


		short		ind_party_name = -1;
		short		ind_mms_node_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_party_type = cPartyType;
DEBUGLOG(("GetSingleDetail party_type = [%.c]\n", hv_party_type));

	hv_business_type = cBusinessType;
DEBUGLOG(("GetSingleDetail business_type = [%.c]\n", hv_business_type));

	hv_party_id.len = strlen(csPartyId);
        memcpy(hv_party_id.arr, csPartyId, hv_party_id.len);
DEBUGLOG(("GetSingleDetail party_id = [%.*s]\n",hv_party_id.len, hv_party_id.arr));


        /* EXEC SQL DECLARE c_cursor_getsingledetail CURSOR FOR
		select mid_party_name,
	               mid_mms_node_id
		  from mms_instant_pm_acct_dt
		 where mid_party_type = :hv_party_type
		   and mid_business_type = :hv_business_type
		   and mid_party_id = :hv_party_id; */ 


        /* EXEC SQL OPEN c_cursor_getsingledetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0002;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )48;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_party_type;
        sqlstm.sqhstl[0] = (unsigned long )1;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_business_type;
        sqlstm.sqhstl[1] = (unsigned long )1;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_party_id;
        sqlstm.sqhstl[2] = (unsigned long )17;
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
        if (sqlca.sqlcode < 0) goto getsingledetail_error;
}


        do {
		/* EXEC SQL FETCH c_cursor_getsingledetail
		INTO	:v_party_name:ind_party_name,
			:v_mms_node_id:ind_mms_node_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )75;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_party_name;
  sqlstm.sqhstl[0] = (unsigned long )53;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_party_name;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_mms_node_id;
  sqlstm.sqhstl[1] = (unsigned long )8;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_mms_node_id;
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
  if (sqlca.sqlcode < 0) goto getsingledetail_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}	

		iCnt++;

/* party_name */	
		if (ind_party_name >= 0) {
			v_party_name.arr[v_party_name.len] = '\0';
			PutField_CString(hContext, "party_name", (const char *)v_party_name.arr);
DEBUGLOG(("GeSingleDetail party_name = [%s]\n",v_party_name.arr));
		}

/* mms_node_id */	
		if (ind_mms_node_id >= 0) {
			v_mms_node_id.arr[v_mms_node_id.len] = '\0';
			PutField_CString(hContext, "mms_node_id", (const char *)v_mms_node_id.arr);
DEBUGLOG(("GetSingleDetail mms_node_id = [%s]\n",v_mms_node_id.arr));
		}
	
	}
	while (PD_TRUE);
	/* EXEC SQL CLOSE c_cursor_getsingledetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )98;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getsingledetail_error;
}




        if (iCnt > 0 ) {
DEBUGLOG(("GetSingleDetail Normal Exit\n"));
                return  PD_OK;
        }
        else {
DEBUGLOG(("GetSingleDetail Normal Exit, Not Found\n"));
                /*return PD_ERR;*/
		return PD_NOT_FOUND;
        }


getsingledetail_error:
DEBUGLOG(("getsingledetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getsingledetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )113;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}

 
        return PD_ERR;

}


int Delete (const char cPartyType,
		const char cBusinessType)
{
/*
	char	cTmp;
	char	*csTmp;
*/

        /* EXEC SQL WHENEVER SQLERROR GOTO delete_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		char	hv_party_type;
		char	hv_business_type;


		short   hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Delete: Begin\n"));

	hv_party_type = cPartyType;
DEBUGLOG(("Delete:party_type = [%.c]\n", hv_party_type));

	hv_business_type = cBusinessType;
DEBUGLOG(("Delete:business_type = [%.c]\n", hv_business_type));

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_mms_instant_pmacct_dt_del(	
						:hv_party_type,
						:hv_business_type
						);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_mms_instant_pmacct_dt_del ( :h\
v_party_type , :hv_business_type ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )128;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_party_type;
 sqlstm.sqhstl[1] = (unsigned long )1;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_business_type;
 sqlstm.sqhstl[2] = (unsigned long )1;
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
 if (sqlca.sqlcode < 0) goto delete_error;
}




DEBUGLOG(("Delete:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
                DEBUGLOG(("Delete:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
                ERRLOG("MmsInstantPMAcctDt_Delete: SP_OTHER_ERR TxnAbort\n");
                DEBUGLOG(("Delete: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
                ERRLOG("MmsInstantPMAcctDt_Delete: SP_ERR TxnAbort\n");
                DEBUGLOG(("Delete: SP_ERR TxnAbort\n"));
		TxnAbort();
                return PD_ERR;
        }

delete_error:
DEBUGLOG(("delete_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MmsInstantPMAcctDt_Delete: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
        return PD_ERR;	

}


int GetNextPartyId(const hash_t *hRec, 
                   char *csNextPartyId)
{
	
	char cTmp;
	char *csTmp = NULL;
	

        /* EXEC SQL WHENEVER SQLERROR GOTO getnextpartyid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		short		hv_return_value;

                char            hv_party_type;
                char            hv_business_type;
                /* varchar         hv_last_party_id[PD_MMS_PARTY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_last_party_id;

                /* varchar         hv_mms_node_id[PD_MMS_MMC_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_mms_node_id;


                /* varchar         v_party_id[PD_MMS_PARTY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;


		short		ind_party_type = -1;
		short		ind_business_type = -1;
		short		ind_last_party_id = -1;
		short		ind_mms_node_id = -1;

                short           ind_party_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_Char(hRec, "party_type", &cTmp)) {
        	hv_party_type = cTmp;
		ind_party_type = 0;
DEBUGLOG(("GetNextPartyId party_type = [%c]\n",hv_party_type));
	}

	if (GetField_Char(hRec, "business_type", &cTmp)) {
        	hv_business_type = cTmp;
		ind_business_type = 0;
DEBUGLOG(("GetNextPartyId business_type = [%c]\n",hv_business_type));
	}

	if (GetField_CString(hRec, "last_party_id", &csTmp)) {
        	hv_last_party_id.len = strlen(csTmp);
        	memcpy(hv_last_party_id.arr, csTmp, hv_last_party_id.len);
		ind_last_party_id = 0;
DEBUGLOG(("GetNextPartyId last_party_id = [%d][%.*s]\n",hv_last_party_id.len,hv_last_party_id.len,hv_last_party_id.arr));
	}

	if (GetField_CString(hRec, "mms_node_id", &csTmp)) {
        	hv_mms_node_id.len = strlen(csTmp);
	        memcpy(hv_mms_node_id.arr, csTmp, hv_mms_node_id.len);
		ind_mms_node_id = 0;
DEBUGLOG(("GetNextPartyId mms_node_id = [%.*s]\n",hv_mms_node_id.len, hv_mms_node_id.arr));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_mms_instant_pmacct_dt_next(:hv_party_type:ind_party_type,
									  :hv_business_type:ind_business_type,
									  :hv_last_party_id:ind_last_party_id,
									  :hv_mms_node_id:ind_mms_node_id,
									  :v_party_id:ind_party_id);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_mms_instant_pmacct_dt_next ( :\
hv_party_type:ind_party_type , :hv_business_type:ind_business_type , :hv_last\
_party_id:ind_last_party_id , :hv_mms_node_id:ind_mms_node_id , :v_party_id:i\
nd_party_id ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )155;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_party_type;
 sqlstm.sqhstl[1] = (unsigned long )1;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_party_type;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_business_type;
 sqlstm.sqhstl[2] = (unsigned long )1;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_business_type;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_last_party_id;
 sqlstm.sqhstl[3] = (unsigned long )17;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_last_party_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_mms_node_id;
 sqlstm.sqhstl[4] = (unsigned long )8;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_mms_node_id;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&v_party_id;
 sqlstm.sqhstl[5] = (unsigned long )18;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_party_id;
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
 if (sqlca.sqlcode < 0) goto getnextpartyid_error;
}




	if (hv_return_value == SP_OK) {
		if (ind_party_id >= 0) {
	                v_party_id.arr[v_party_id.len] = '\0';
			strcpy(csNextPartyId, (const char*) v_party_id.arr);
DEBUGLOG(("GetNextPartyId next party_id = [%s] [%s]\n",v_party_id.arr, csNextPartyId));

DEBUGLOG(("GetNextPartyId Normal Exit\n"));
                	return PD_OK;
		}
	}
	else if (hv_return_value == SP_OTHER_ERR) {
DEBUGLOG(("GetNextPartyId Other error\n"));
		return PD_ERR;
	}
	else  {
DEBUGLOG(("GetNextPartyId Normal Exit, no more next party_id\n"));
		return PD_NOT_FOUND;
	}

getnextpartyid_error:
DEBUGLOG(("getnextpartyid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;


}



int     GetDetailbyRange(const hash_t *hRec,
                        recordset_t *myRec)
{
	int     iRet = PD_OK;
        int	iCnt = 0;

	char    *csTmp = NULL;
	char    cTmp;
	int     iRowNum = 0;

        hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getdetailbyrange_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		short		hv_return_value;

                char            hv_party_type;
                char            hv_business_type;
                /* varchar         hv_req_mms_node_id[PD_MMS_MMC_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[5]; } hv_req_mms_node_id;
 
                /* varchar         hv_st_party_id[PD_MMS_PARTY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_st_party_id;


                /* varchar         v_party_id[PD_MMS_PARTY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;

                /* varchar         v_party_name[PD_MMS_PARTY_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_party_name;

                /* varchar         v_mms_node_id[PD_MMS_MMC_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[6]; } v_mms_node_id;


		short		ind_party_type = -1;
		short		ind_business_type = -1;
		short		ind_req_mms_node_id = -1;
		short		ind_st_party_id = -1;

                short           ind_party_id = -1;
                short           ind_party_name = -1;
                short           ind_mms_node_id = -1;

		SQL_CURSOR	c_cursor_id;

        /* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_Char(hRec, "party_type", &cTmp)) {
		hv_party_type = cTmp;
		ind_party_type = 0;
DEBUGLOG(("GetDetailbyRange party_type = [%.c]\n", hv_party_type));
	}

	if (GetField_Char(hRec, "business_type", &cTmp)) {
        	hv_business_type = cTmp;
		ind_business_type = 0;
DEBUGLOG(("GetDetailbyRange business_type = [%.c]\n", hv_business_type));
	}

	if (GetField_CString(hRec, "mms_node_id", &csTmp)) {
        	hv_req_mms_node_id.len = strlen(csTmp);
        	memcpy(hv_req_mms_node_id.arr, csTmp, hv_req_mms_node_id.len);
		ind_req_mms_node_id = 0;
DEBUGLOG(("GetDetailbyRange req_mms_node_id = [%.*s]\n",hv_req_mms_node_id.len, hv_req_mms_node_id.arr));
		
	}

	if (GetField_CString(hRec, "start_party_id", &csTmp)) {
        	hv_st_party_id.len = strlen(csTmp);
	        memcpy(hv_st_party_id.arr, csTmp, hv_st_party_id.len);
		ind_st_party_id = 0;
DEBUGLOG(("GetDetailbyRange st_party_id = [%d][%.*s]\n",hv_st_party_id.len,hv_st_party_id.len,hv_st_party_id.arr));
	}

	if (GetField_Int(hRec, "max_rtn", &iRowNum)) {
DEBUGLOG(("GetDetailbyRange max_rtn = [%d]\n", iRowNum));
	}


	/* EXEC SQL ALLOCATE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )194;
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
 if (sqlca.sqlcode < 0) goto getdetailbyrange_error;
}


	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_mms_instant_pmacct_dt_rec(:hv_party_type:ind_party_type,
								         :hv_business_type:ind_business_type,
								         :hv_req_mms_node_id:ind_req_mms_node_id,
								         :hv_st_party_id:ind_st_party_id,
								         :c_cursor_id);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_mms_instant_pmacct_dt_rec ( :h\
v_party_type:ind_party_type , :hv_business_type:ind_business_type , :hv_req_m\
ms_node_id:ind_req_mms_node_id , :hv_st_party_id:ind_st_party_id , :c_cursor_\
id ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )213;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_party_type;
 sqlstm.sqhstl[1] = (unsigned long )1;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_party_type;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_business_type;
 sqlstm.sqhstl[2] = (unsigned long )1;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_business_type;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_req_mms_node_id;
 sqlstm.sqhstl[3] = (unsigned long )7;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_req_mms_node_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_st_party_id;
 sqlstm.sqhstl[4] = (unsigned long )17;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_st_party_id;
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
 if (sqlca.sqlcode < 0) goto getdetailbyrange_error;
}




	if (hv_return_value == SP_OK) {
DEBUGLOG(("GetDetailbyRange found record\n"));
		for (;;) {
			myHash = (hash_t*) malloc(sizeof(hash_t));
			hash_init(myHash, 0);

                	ind_party_id = -1;
                	ind_party_name = -1;
                	ind_mms_node_id = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_id
                        INTO    :v_party_id:ind_party_id,
                                :v_party_name:ind_party_name,
                                :v_mms_node_id:ind_mms_node_id; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 7;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )252;
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
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_party_id;
                        sqlstm.sqhstl[1] = (unsigned long )18;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_party_id;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_party_name;
                        sqlstm.sqhstl[2] = (unsigned long )53;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_party_name;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_mms_node_id;
                        sqlstm.sqhstl[3] = (unsigned long )8;
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_mms_node_id;
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
                        if (sqlca.sqlcode == 1403) break;
                        if (sqlca.sqlcode < 0) goto getdetailbyrange_error;
}



                        if (SQLCODE == SQL_NOT_FOUND) {
                                break;
                        }

                        if (iCnt < iRowNum + 1 || iRowNum == 0) {

                                if (ind_party_id >= 0) {
		                        v_party_id.arr[v_party_id.len] = '\0';
					PutField_CString(myHash, "party_id", (const char *)v_party_id.arr);
DEBUGLOG(("GetDetailbyRange [%05d] party_id = [%.*s]\n",iCnt, v_party_id.len, v_party_id.arr));
                                }

                		if (ind_party_name >= 0) {
					v_party_name.arr[v_party_name.len] = '\0';
					PutField_CString(myHash, "party_name", (const char *)v_party_name.arr);
DEBUGLOG(("GetDetailbyRange [%05d] party_name = [%.*s]\n",iCnt, v_party_name.len, v_party_name.arr));
        		        }

				if (ind_mms_node_id >= 0) {
					v_mms_node_id.arr[v_mms_node_id.len] = '\0';
					PutField_CString(myHash, "mms_node_id", (const char *)v_mms_node_id.arr);
DEBUGLOG(("GetDetailbyRange [%05d] mms_node_id = [%.*s]\n",iCnt, v_mms_node_id.len, v_mms_node_id.arr));
                		}

                		iCnt++;
				RecordSet_Add(myRec, myHash);
			}
		}
		/* EXEC SQL CLOSE :c_cursor_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )283;
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
  if (sqlca.sqlcode < 0) goto getdetailbyrange_error;
}


		/* EXEC SQL FREE :c_cursor_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )302;
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
  if (sqlca.sqlcode < 0) goto getdetailbyrange_error;
}


DEBUGLOG(("GetDetailbyRange Normal Exit\n"));
		return iRet;
	}
	else if (hv_return_value == SP_OTHER_ERR) {
		/* EXEC SQL CLOSE :c_cursor_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )321;
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
  if (sqlca.sqlcode < 0) goto getdetailbyrange_error;
}


		/* EXEC SQL FREE :c_cursor_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )340;
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
  if (sqlca.sqlcode < 0) goto getdetailbyrange_error;
}


DEBUGLOG(("GetDetailbyRange Exit with error\n"));
                return PD_ERR;
	}
        else {
                /* EXEC SQL CLOSE :c_cursor_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 7;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )359;
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
                if (sqlca.sqlcode < 0) goto getdetailbyrange_error;
}


		/* EXEC SQL FREE :c_cursor_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )378;
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
  if (sqlca.sqlcode < 0) goto getdetailbyrange_error;
}


DEBUGLOG(("GetDetailbyRange Normal Exit, no record found\n"));
                return PD_OK;
        }
        /* EXEC SQL CLOSE :c_cursor_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )397;
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
        if (sqlca.sqlcode < 0) goto getdetailbyrange_error;
}


	/* EXEC SQL FREE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )416;
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
 if (sqlca.sqlcode < 0) goto getdetailbyrange_error;
}


DEBUGLOG(("RET = [%d]\n",iRet));
        return iRet;


getdetailbyrange_error:
DEBUGLOG(("getdetailbyrange_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MMSInstantPMAcctDt_GetDetailByRange: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE :c_cursor_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )435;
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
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )454;
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


