
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
    "IttTaskLog.pc"
};


static unsigned int sqlctx = 636803;


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
   unsigned char  *sqhstv[13];
   unsigned long  sqhstl[13];
            int   sqhsts[13];
            short *sqindv[13];
            int   sqinds[13];
   unsigned long  sqharm[13];
   unsigned long  *sqharc[13];
   unsigned short  sqadto[13];
   unsigned short  sqtdso[13];
} sqlstm = {12,13};

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
5,0,0,1,390,0,6,166,0,0,13,13,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,
1,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,9,0,0,
72,0,0,2,0,0,17,270,0,0,1,1,0,1,0,1,9,0,0,
91,0,0,2,0,0,21,271,0,0,0,0,0,1,0,
106,0,0,2,0,0,17,361,0,0,1,1,0,1,0,1,9,0,0,
125,0,0,2,0,0,21,362,0,0,0,0,0,1,0,
140,0,0,3,146,0,4,391,0,0,1,0,0,1,0,2,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2016/07/26              Dirk Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "IttTaskLog.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char	cDebug;

void IttTaskLog(char	cdebug)
{
	cDebug = cdebug;
}


int Add(const hash_t *hIttTaskLog)
{
	char    *csTmp;
	char	cTmp;
	int     iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;

		int		hv_batch_seq;
		/* varchar		hv_api_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_api_code;

		/* varchar		hv_task_action[PD_CUSTOM_TAG_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_task_action;

		char		hv_action_type;
		/* varchar		hv_object[PD_CUSTOM_VALUE_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_object;

		/* varchar		hv_key[PD_REMARK_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_key;

		/* varchar		hv_field[PD_CUSTOM_VALUE_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_field;

		/* varchar		hv_value[PD_REMARK_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_value;

		/* varchar		hv_old_value[PD_REMARK_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_old_value;

		int		hv_ret_code;
		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_batch_id = -1;
		short		ind_batch_seq = -1;
		short		ind_api_code = -1;
		short		ind_task_action = -1;
		short		ind_action_type = -1;
		short		ind_object = -1;
		short		ind_key = -1;
		short		ind_field = -1;
		short		ind_value = -1;
		short		ind_old_value = -1;
		short		ind_ret_code = -1;
		short		ind_create_user = -1;

                short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

        if(GetField_CString(hIttTaskLog,"batch_id",&csTmp))
        {
                hv_batch_id.len = strlen(csTmp);
                strncpy((char *)hv_batch_id.arr, csTmp, hv_batch_id.len);
                ind_batch_id = 0;
DEBUGLOG(("Add:batch_id = [%.*s]\n",hv_batch_id.len,hv_batch_id.arr));
        }

        if (GetField_Int(hIttTaskLog,"batch_seq", &iTmp))
        {
                hv_batch_seq = iTmp;
                ind_batch_seq = 0;
DEBUGLOG(("Add:batch_seq = [%d]\n",hv_batch_seq));
        }

        if(GetField_CString(hIttTaskLog,"api_code",&csTmp))
        {
                hv_api_code.len = strlen(csTmp);
                strncpy((char *)hv_api_code.arr, csTmp, hv_api_code.len);
                ind_api_code = 0;
DEBUGLOG(("Add:api_code = [%.*s]\n",hv_api_code.len,hv_api_code.arr));
        }

        if(GetField_CString(hIttTaskLog,"task_action",&csTmp))
        {
                hv_task_action.len = strlen(csTmp);
                strncpy((char *)hv_task_action.arr, csTmp, hv_task_action.len);
                ind_task_action = 0;
DEBUGLOG(("Add:task_action = [%.*s]\n",hv_task_action.len,hv_task_action.arr));
        }

        if(GetField_Char(hIttTaskLog,"action_type",&cTmp))
        {
                hv_action_type = cTmp;
                ind_action_type = 0;
DEBUGLOG(("Add:action_type = [%c]\n",hv_action_type));
        }

        if(GetField_CString(hIttTaskLog,"object",&csTmp))
        {
                hv_object.len = strlen(csTmp);
                strncpy((char *)hv_object.arr, csTmp, hv_object.len);
                ind_object = 0;
DEBUGLOG(("Add:object = [%.*s]\n",hv_object.len,hv_object.arr));
        }

        if(GetField_CString(hIttTaskLog,"key",&csTmp))
        {
                hv_key.len = strlen(csTmp);
                strncpy((char *)hv_key.arr, csTmp, hv_key.len);
                ind_key = 0;
DEBUGLOG(("Add:key = [%.*s]\n",hv_key.len,hv_key.arr));
        }

        if(GetField_CString(hIttTaskLog,"field",&csTmp))
        {
                hv_field.len = strlen(csTmp);
                strncpy((char *)hv_field.arr, csTmp, hv_field.len);
                ind_field = 0;
DEBUGLOG(("Add:field = [%.*s]\n",hv_field.len,hv_field.arr));
        }

        if(GetField_CString(hIttTaskLog,"value",&csTmp))
        {
                hv_value.len = strlen(csTmp);
                strncpy((char *)hv_value.arr, csTmp, hv_value.len);
                ind_value = 0;
DEBUGLOG(("Add:value = [%.*s]\n",hv_value.len,hv_value.arr));
        }

        if(GetField_CString(hIttTaskLog,"old_value",&csTmp))
        {
                hv_old_value.len = strlen(csTmp);
                strncpy((char *)hv_old_value.arr, csTmp, hv_old_value.len);
                ind_old_value = 0;
DEBUGLOG(("Add:old_value = [%.*s]\n",hv_old_value.len,hv_old_value.arr));
        }
	
        if (GetField_Int(hIttTaskLog, "ret_code", &iTmp))
        {
                hv_ret_code = iTmp;
                ind_ret_code = 0;
DEBUGLOG(("Add:return_code = [%d]\n", hv_ret_code));
        }

        if(GetField_CString(hIttTaskLog,"create_user",&csTmp))
        {
                hv_create_user.len = strlen(csTmp);
                strncpy((char *)hv_create_user.arr, csTmp, hv_create_user.len);
                ind_create_user = 0;
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));
        }

	/* EXEC SQL EXECUTE
		BEGIN

		:hv_return_value := sp_itt_task_log_insert(
					:hv_batch_id:ind_batch_id,
					:hv_batch_seq:ind_batch_seq,
					:hv_api_code:ind_api_code,
					:hv_task_action:ind_task_action,
					:hv_action_type:ind_action_type,
					:hv_object:ind_object,
					:hv_key:ind_key,
					:hv_field:ind_field,
					:hv_value:ind_value,
					:hv_old_value:ind_old_value,
					:hv_ret_code:ind_ret_code,
					:hv_create_user:ind_create_user);


		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_itt_task_log_insert ( :hv_batc\
h_id:ind_batch_id , :hv_batch_seq:ind_batch_seq , :hv_api_code:ind_api_code ,\
 :hv_task_action:ind_task_action , :hv_action_type:ind_action_type , :hv_obje\
ct:ind_object , :hv_key:ind_key , :hv_field:ind_field , :hv_value:ind_value ,\
 :hv_old_value:ind_old_value , :hv_ret_code:ind_ret_code , :hv_create_user:in\
d_create_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_batch_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_batch_seq;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_batch_seq;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_api_code;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_api_code;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_task_action;
 sqlstm.sqhstl[4] = (unsigned long )22;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_task_action;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_action_type;
 sqlstm.sqhstl[5] = (unsigned long )1;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_action_type;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_object;
 sqlstm.sqhstl[6] = (unsigned long )52;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_object;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_key;
 sqlstm.sqhstl[7] = (unsigned long )257;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_key;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_field;
 sqlstm.sqhstl[8] = (unsigned long )52;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_field;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_value;
 sqlstm.sqhstl[9] = (unsigned long )257;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_value;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_old_value;
 sqlstm.sqhstl[10] = (unsigned long )257;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_old_value;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_ret_code;
 sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_ret_code;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[12] = (unsigned long )22;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_create_user;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
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
		ERRLOG("IttTaskLog_Add: SP_OTHER_ERR TxnAbort\n");
		DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
		ERRLOG("IttTaskLog_Add: SP_ERR TxnAbort\n");
		DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("IttTaskLog_Add: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int UpdateRetCodeByBatch(const hash_t *hIttTaskLog)
{
	char* csBatchId;

	char  *csTmp;
	char* csBuf;
	int   iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO updatebybatch_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;

	/* EXEC SQL END DECLARE SECTION; */ 


        if(GetField_CString(hIttTaskLog,"batch_id",&csBatchId))
        {
DEBUGLOG(("UpdateRetCodeByBatch:batch_id = [%s]\n",csBatchId));
        } else {
DEBUGLOG(("UpdateRetCodeByBatch:batch_id NOT FOUND!!\n"));
		return PD_ERR;
	}

DEBUGLOG(("UpdateRetCodeByBatch: Begin\n"));
	csBuf = (char *)malloc(128);

	strcpy((char*)hv_dynstmt.arr, "update itt_task_log set ttl_update_timestamp = sysdate");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

// ret_code
	if (GetField_Int(hIttTaskLog, "ret_code", &iTmp)) {
DEBUGLOG(("UpdateRetCodeByBatch: ret_code = [%d]\n", iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", ttl_ret_code = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// user
	if (GetField_CString(hIttTaskLog, "update_user", &csTmp)) {
DEBUGLOG(("UpdateRetCodeByBatch: user = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", ttl_update_user = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	strcat((char*)hv_dynstmt.arr, " WHERE ttl_batch_id = '");
	strcat((char*)hv_dynstmt.arr, csBatchId);
	strcat((char*)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n", hv_dynstmt.len, hv_dynstmt.arr));


	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )72;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
 sqlstm.sqhstl[0] = (unsigned long )1026;
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
 if (sqlca.sqlcode < 0) goto updatebybatch_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )91;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto updatebybatch_error;
}



	FREE_ME(csBuf);

DEBUGLOG(("UpdateRetCodeByBatch Normal Exit\n"));
	return PD_OK;

updatebybatch_error:
DEBUGLOG(("updatebybatch_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

DEBUGLOG(("UpdateRetCodeByBatch: SP_INTERNAL_ERR TxnAbort\n"));
ERRLOG("IttTaskLog_UpdateRetCodeByBatch: SP_INTERNAL_ERR TxnAbort\n");
	return PD_INTERNAL_ERR;
}


int UpdateRetCodeBySeq(const hash_t *hIttTaskLog)
{
	char* csBatchId;
	char* csBatchSeq;

	char  *csTmp;
	char* csBuf;
	int   iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO updatebyseq_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;

	/* EXEC SQL END DECLARE SECTION; */ 


	csBuf = (char *)malloc(128);
	csBatchSeq = (char *)malloc(128);

        if(GetField_CString(hIttTaskLog,"batch_id",&csBatchId))
        {
DEBUGLOG(("UpdateRetCodeBySeq:batch_id = [%s]\n",csBatchId));
        } else {
DEBUGLOG(("UpdateRetCodeBySeq:batch_id NOT FOUND!!\n"));
		return PD_ERR;
	}

        if (GetField_Int(hIttTaskLog,"batch_seq", &iTmp))
        {
		sprintf(csBatchSeq, "%d", iTmp);
DEBUGLOG(("UpdateRetCodeBySeq:batch_seq = [%d]\n",iTmp));
        } else {
DEBUGLOG(("UpdateRetCodeBySeq:batch_seq NOT FOUND!!\n"));
		return PD_ERR;
        }

DEBUGLOG(("UpdateRetCodeBySeq: Begin\n"));

	strcpy((char*)hv_dynstmt.arr, "update itt_task_log set ttl_update_timestamp = sysdate");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

// ret_code
	if (GetField_Int(hIttTaskLog, "ret_code", &iTmp)) {
DEBUGLOG(("UpdateRetCodeBySeq: ret_code = [%d]\n", iTmp));
		sprintf(csTmp, "%d", iTmp);

		strcat((char*)hv_dynstmt.arr, ", ttl_ret_code =");
		strcat((char*)hv_dynstmt.arr, csTmp);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// user
	if (GetField_CString(hIttTaskLog, "update_user", &csTmp)) {
DEBUGLOG(("UpdateRetCodeBySeq: user = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", ob_update_user = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	strcat((char*)hv_dynstmt.arr, " WHERE ttl_batch_id = '");
	strcat((char*)hv_dynstmt.arr, csBatchId);
	strcat((char*)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	strcat((char*)hv_dynstmt.arr, " AND batch_seq = '");
	strcat((char*)hv_dynstmt.arr, csBatchSeq);
	strcat((char*)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n", hv_dynstmt.len, hv_dynstmt.arr));


	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )106;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
 sqlstm.sqhstl[0] = (unsigned long )1026;
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
 if (sqlca.sqlcode < 0) goto updatebyseq_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )125;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto updatebyseq_error;
}



	FREE_ME(csBuf);
	FREE_ME(csBatchSeq);

DEBUGLOG(("UpdateRetCodeBySeq Normal Exit\n"));
	return PD_OK;

updatebyseq_error:
DEBUGLOG(("updatebyseq_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

DEBUGLOG(("UpdateRetCodeBySeq: SP_INTERNAL_ERR TxnAbort\n"));
ERRLOG("IttTaskLog_Update: SP_INTERNAL_ERR TxnAbort\n");
	return PD_INTERNAL_ERR;
}


char* GetNextITTTaskBatchSeq()
{
        /* EXEC SQL WHENEVER SQLERROR GOTO get_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_seq_no[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } hv_seq_no;

                short   ind_seq_no;
        /* EXEC SQL END DECLARE SECTION; */ 



	/* EXEC SQL SELECT tdp_value || TO_CHAR(ITT_TASK_BATCH_SEQ.NEXTVAL, 'FM099999999999')
		 INTO :hv_seq_no:ind_seq_no
		 FROM itt_def_prefix
		 WHERE tdp_prefix_code = 'ITT_LOG'; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select tdp_value || TO_CHAR ( ITT_TASK_BATCH_SEQ . NEXTVAL \
, 'FM099999999999' ) INTO :b0:b1 FROM itt_def_prefix WHERE tdp_prefix_code = \
'ITT_LOG' ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )140;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_seq_no;
 sqlstm.sqhstl[0] = (unsigned long )19;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_seq_no;
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
 if (sqlca.sqlcode < 0) goto get_error;
}




        if (ind_seq_no >= 0)  {
                hv_seq_no.arr[hv_seq_no.len] = '\0';
                return strdup((const char *) hv_seq_no.arr);
        }
        else
                return strdup("");

get_error:
DEBUGLOG(("get_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return strdup("");
}

