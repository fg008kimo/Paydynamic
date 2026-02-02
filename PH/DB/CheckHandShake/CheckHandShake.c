
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
    "CheckHandShake.pc"
};


static unsigned int sqlctx = 9027603;


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

 static char *sq0002 = 
"SELECT CH_MAX_HANDSHAKE_COUNT , CH_MAX_INIT_COUNT , CH_DISABLED FROM CHECK_\
HAND_SHAKE WHERE CH_PARTY_ID = :b0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,356,0,6,118,0,0,9,9,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,
0,0,1,3,0,0,1,3,0,0,1,9,0,0,
56,0,0,2,121,0,9,198,0,2049,1,1,0,1,0,1,9,0,0,
75,0,0,2,0,0,13,202,0,0,3,0,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,
102,0,0,2,0,0,15,239,0,0,0,0,0,1,0,
117,0,0,3,0,0,17,349,0,0,1,1,0,1,0,1,9,0,0,
136,0,0,3,0,0,21,350,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2016/08/01              Dirk Wong
PRD306
 - Add GetThresholdByMerchantId Function
 - Add UpdateThresholdByMerchantId Function        2021/02/24              [ZBL]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "CheckHandShake.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


static char cDebug;

void CheckHandShake(char    cdebug)
{
        cDebug = cdebug;
}


int Add(const hash_t *hRls)
{
	char	*csTmp;
	int	iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_party_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_party_id;

		int		hv_check_count;
		int		hv_max_handshake_count;
		int		hv_disabled;
		int		hv_start_buffer_period;
		int		hv_min_total;
		int		hv_max_init_count;
		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_party_id = -1;
		short		ind_check_count = -1;
		short		ind_max_handshake_count = -1;
		short		ind_disabled = -1;
		short		ind_start_buffer_period = -1;
		short		ind_min_total = -1;
		short		ind_max_init_count = -1;
		short		ind_create_user = -1;
	
		short		hv_return_value;	
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

        if(GetField_CString(hRls,"party_id",&csTmp)) {
                hv_party_id.len = strlen(csTmp);
                strncpy((char*)hv_party_id.arr, csTmp, hv_party_id.len);
                ind_party_id = 0;
        }

        if(GetField_Int(hRls, "check_count", &iTmp)) {
                hv_check_count = iTmp;
                ind_check_count = 0;
DEBUGLOG(("Add:check_count = [%d]\n",hv_check_count));
        }

        if(GetField_Int(hRls, "max_handshake_count", &iTmp)) {
                hv_max_handshake_count = iTmp;
                ind_max_handshake_count = 0;
DEBUGLOG(("Add:max_handshake_count = [%d]\n",hv_max_handshake_count));
        }

        hv_disabled = PD_FALSE;
        ind_disabled = 0;
DEBUGLOG(("Add:disabled = [%d]\n",PD_FALSE));

        if(GetField_Int(hRls, "start_buffer_period", &iTmp)) {
                hv_start_buffer_period = iTmp;
                ind_start_buffer_period = 0;
DEBUGLOG(("Add:start_buffer_period = [%d]\n",hv_start_buffer_period));
        }

        if(GetField_Int(hRls, "min_total", &iTmp)) {
                hv_min_total = iTmp;
                ind_min_total = 0;
DEBUGLOG(("Add:min_total = [%d]\n",hv_min_total));
        }

        if(GetField_Int(hRls, "max_init_count", &iTmp)) {
                hv_max_init_count = iTmp;
                ind_max_init_count = 0;
DEBUGLOG(("Add:max_init_count = [%d]\n",hv_max_init_count));
        }

        if(GetField_CString(hRls,"create_user",&csTmp)) {
                hv_create_user.len = strlen(csTmp);
                strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
                ind_create_user = 0;
        } else if(GetField_CString(hRls,"update_user",&csTmp)) {
                hv_create_user.len = strlen(csTmp);
                strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
                ind_create_user = 0;
        }
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_check_hand_shake_insert(
						:hv_party_id:ind_party_id,
						:hv_check_count:ind_check_count,
						:hv_max_handshake_count:ind_max_handshake_count,
						:hv_disabled:ind_disabled,
						:hv_start_buffer_period:ind_start_buffer_period,
						:hv_min_total:ind_min_total,
						:hv_max_init_count:ind_max_init_count,
						:hv_create_user:ind_create_user); 
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_check_hand_shake_insert ( :hv_\
party_id:ind_party_id , :hv_check_count:ind_check_count , :hv_max_handshake_c\
ount:ind_max_handshake_count , :hv_disabled:ind_disabled , :hv_start_buffer_p\
eriod:ind_start_buffer_period , :hv_min_total:ind_min_total , :hv_max_init_co\
unt:ind_max_init_count , :hv_create_user:ind_create_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_party_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_party_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_check_count;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_check_count;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_max_handshake_count;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_max_handshake_count;
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
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_start_buffer_period;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_start_buffer_period;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_min_total;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_min_total;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_max_init_count;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_max_init_count;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[8] = (unsigned long )22;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto add_error;
}



DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("Add:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("CheckHandShake_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("CheckHandShake_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }


add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("CheckHandShake_Add: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int GetThresholdByMID(const char *csMerchantId, recordset_t *rRec)
{
	int	iCnt = 0;
	int	iRet = PD_NOT_FOUND;
	hash_t	*hRec;

	/* EXEC SQL WHENEVER SQLERROR GOTO get_threshold_by_mid_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;


		int		v_max_handshake_count;
		int		v_max_init_count;
		int		v_disabled;

		short		ind_merchant_id			= -1;
		short		ind_max_handshake_count		= -1;
		short		ind_max_init_count		= -1;
		short		ind_disabled			= -1;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetThresholdByMID: Begin\n"));

	/* merchant_id */
	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
	ind_merchant_id = 0;

DEBUGLOG(("- merchant_id = [%.*s]\n", hv_merchant_id.len, hv_merchant_id.arr));

	/* EXEC SQL DECLARE c_cursor_getthresholdbymid CURSOR FOR
		SELECT	CH_MAX_HANDSHAKE_COUNT, 
			CH_MAX_INIT_COUNT, 
			CH_DISABLED 
		FROM	CHECK_HAND_SHAKE 
		WHERE	CH_PARTY_ID = :hv_merchant_id; */ 


	/* EXEC SQL OPEN c_cursor_getthresholdbymid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )56;
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
 if (sqlca.sqlcode < 0) goto get_threshold_by_mid_error;
}



	do
	{
		/* EXEC SQL FETCH c_cursor_getthresholdbymid 
		INTO
			:v_max_handshake_count:ind_max_handshake_count, 
			:v_max_init_count:ind_max_init_count, 
			:v_disabled:ind_disabled; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
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
  sqlstm.sqhstv[0] = (unsigned char  *)&v_max_handshake_count;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_max_handshake_count;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_max_init_count;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_max_init_count;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_disabled;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_disabled;
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
  if (sqlca.sqlcode < 0) goto get_threshold_by_mid_error;
}



		if (SQLCODE == SQL_NOT_FOUND)
			break;

		hRec = (hash_t*)malloc(sizeof(hash_t));
		hash_init(hRec, 0);

		/* max_handshake_count */
		if (ind_max_handshake_count >= 0)
		{
			PutField_Int(hRec, "max_handshake_count", v_max_handshake_count);
DEBUGLOG(("- [%d] max_handshake_count = [%d]\n", iCnt, v_max_handshake_count));
		}

		/* max_init_count */
		if (ind_max_init_count >= 0)
		{
			PutField_Int(hRec, "max_init_count", v_max_init_count);
DEBUGLOG(("- [%d] max_init_count = [%d]\n", iCnt, v_max_init_count));
		}

		/* disabled */
		if (ind_disabled >= 0)
		{
			PutField_Int(hRec, "disabled", v_disabled);
DEBUGLOG(("- [%d] disabled = [%d]\n", iCnt, v_disabled));
		}

		iCnt++;
		RecordSet_Add(rRec, hRec);
	} while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getthresholdbymid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )102;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto get_threshold_by_mid_error;
}



	if (iCnt > 0)
	{
DEBUGLOG(("GetThresholdByMID [%d] records found! Normal Exit\n", iCnt));
		iRet = PD_FOUND;
	}
	else
	{
DEBUGLOG(("GetThresholdByMID no records found! Normal Exit\n"));
	}

	return iRet;

get_threshold_by_mid_error:
DEBUGLOG(("get_threshold_by_mid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("CheckHandShake_GetThresholdByMID: SP_INTERNAL_ERR\n");
DEBUGLOG(("GetThresholdByMID: SP_INTERNAL_ERR\n"));
	return PD_ERR;
}

int UpdateThresholdByMID(const hash_t *hRls)
{
	char	*csBuf;
	char	*csMerchantId;
	char	*csTmp;
	int	iTmp;
	int	iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_threshold_by_mid_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_dynstmt[PD_TMP_MSG_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[2048]; } hv_dynstmt;

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateThresholdByMID: Begin\n"));

	csBuf = (char*)malloc(PD_TMP_BUF_LEN);

	strcpy((char*)hv_dynstmt.arr, "UPDATE check_hand_shake SET ch_update_timestamp = SYSDATE");
	hv_dynstmt.len = strlen((const char *)hv_dynstmt.arr);

	/* merchant_id */
	if (GetField_CString(hRls, "merchant_id", &csMerchantId))
	{
DEBUGLOG(("- merchant_id = [%s]\n", csMerchantId));
	}
	else
	{
		FREE_ME(csBuf);
DEBUGLOG(("UpdateThresholdByMID: merchant_id not found\n"));

		return PD_ERR;
	}

	/* max_handshake_count */
	if (GetField_Int(hRls, "max_handshake_count", &iTmp))
	{
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", ch_max_handshake_count = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- max_handshake_count = [%d]\n", iTmp));
	}

	/* max_init_count */
	if (GetField_Int(hRls, "max_init_count", &iTmp))
	{
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", ch_max_init_count = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- max_init_count = [%d]\n", iTmp));
	}

	/* disabled */
	if (GetField_Int(hRls, "disabled", &iTmp))
	{
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", ch_disabled = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- disabled = [%d]\n", iTmp));
	}

	/* update_user */
	if (GetField_CString(hRls, "update_user", &csTmp))
	{
		strcat((char*)hv_dynstmt.arr, ", ch_update_user = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- update_user = [%s]\n", csTmp));
	}

	/* merchant_id */
	strcat((char*)hv_dynstmt.arr, " WHERE ch_party_id = '");
	strcat((char*)hv_dynstmt.arr, csMerchantId);
	strcat((char*)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("- SQL = [%.*s]\n", hv_dynstmt.len, hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )117;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
 sqlstm.sqhstl[0] = (unsigned long )2050;
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
 if (sqlca.sqlcode < 0) goto update_threshold_by_mid_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )136;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto update_threshold_by_mid_error;
}



	FREE_ME(csBuf);

DEBUGLOG(("UpdateThresholdByMID: Normal Exit\n"));
	return iRet;

update_threshold_by_mid_error:
DEBUGLOG(("update_threshold_by_mid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("CheckHandShake_UpdateThresholdByMID: SP_INTERNAL_ERR\n");
DEBUGLOG(("UpdateThresholdByMID: SP_INTERNAL_ERR\n"));
	return PD_ERR;
}
