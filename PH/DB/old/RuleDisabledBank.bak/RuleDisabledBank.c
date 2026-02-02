
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
           char  filnam[20];
};
static struct sqlcxp sqlfpn =
{
    19,
    "RuleDisabledBank.pc"
};


static unsigned int sqlctx = 42205299;


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
   unsigned char  *sqhstv[10];
   unsigned long  sqhstl[10];
            int   sqhsts[10];
            short *sqindv[10];
            int   sqinds[10];
   unsigned long  sqharm[10];
   unsigned long  *sqharc[10];
   unsigned short  sqadto[10];
   unsigned short  sqtdso[10];
} sqlstm = {12,10};

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
"select rb_rule_disabled_bank_id ,rb_disabled_bank_type ,rb_channel_code ,rb\
_client_id ,rb_psp_id ,rb_scheduler_id  from rule_disabled_bank where (rb_int\
_bank_code=:b0 and rb_disabled=:b1)           ";

 static char *sq0004 = 
"select rb_int_bank_code ,rb_disabled_bank_type ,rb_channel_code ,rb_client_\
id ,rb_psp_id ,rb_scheduler_id ,rb_disabled  from rule_disabled_bank where rb\
_rule_disabled_bank_id=:b0 for update ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,365,0,6,126,0,0,10,10,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,3,0,0,1,3,0,0,1,9,0,0,2,3,0,0,
60,0,0,2,0,0,17,272,0,0,1,1,0,1,0,1,9,0,0,
79,0,0,2,0,0,21,273,0,0,0,0,0,1,0,
94,0,0,3,198,0,9,346,0,0,2,2,0,1,0,1,9,0,0,1,3,0,0,
117,0,0,3,0,0,13,348,0,0,6,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,
0,0,
156,0,0,3,0,0,15,408,0,0,0,0,0,1,0,
171,0,0,3,0,0,15,423,0,0,0,0,0,1,0,
186,0,0,4,190,0,9,479,0,0,1,1,0,1,0,1,3,0,0,
205,0,0,4,0,0,13,481,0,0,7,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,
0,0,2,3,0,0,
248,0,0,4,0,0,15,550,0,0,0,0,0,1,0,
263,0,0,4,0,0,15,565,0,0,0,0,0,1,0,
278,0,0,5,92,0,6,588,0,0,2,2,0,1,0,2,3,0,0,1,3,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/01/06              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "RuleDisabledBank.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char    cDebug;

void RuleDisabledBank(char    cdebug)
{
        cDebug = cdebug;
}

int Add(hash_t *hRls)
{
	char  *csTmp;
	int   iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar		hv_disabled_bank_type[PD_DISABLED_BANK_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_disabled_bank_type;

		/* varchar		hv_channel_code[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel_code;

		/* varchar		hv_client_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_client_id;

		/* varchar		hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		int		hv_scheduler_id;
		int		hv_disabled;
		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_int_bank_code = -1;
		short		ind_disabled_bank_type = -1;
		short		ind_channel_code = -1;
		short		ind_client_id = -1;
		short		ind_psp_id = -1;
		short		ind_scheduler_id = -1;
		short		ind_disabled = -1;
		short		ind_create_user = -1;
	
		short		hv_return_value;	

		int		v_rule_disabled_bank_id;
		
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

	if (GetField_CString(hRls, "int_bank_code", &csTmp)) {
                hv_int_bank_code.len = strlen(csTmp);
                strncpy((char*)hv_int_bank_code.arr, csTmp, hv_int_bank_code.len);
                ind_int_bank_code = 0;
DEBUGLOG(("Add:int_bank_code = [%.*s]\n",hv_int_bank_code.len, hv_int_bank_code.arr));
	}

	if (GetField_CString(hRls, "disabled_bank_type", &csTmp)) {
                hv_disabled_bank_type.len = strlen(csTmp);
                strncpy((char*)hv_disabled_bank_type.arr, csTmp, hv_disabled_bank_type.len);
                ind_disabled_bank_type = 0;
DEBUGLOG(("Add:disabled_bank_type = [%.*s]\n",hv_disabled_bank_type.len, hv_disabled_bank_type.arr));
	}	

	if (GetField_CString(hRls, "channel_code", &csTmp)) {
                hv_channel_code.len = strlen(csTmp);
                strncpy((char*)hv_channel_code.arr, csTmp, hv_channel_code.len);
                ind_channel_code = 0;
DEBUGLOG(("Add:channel_code = [%.*s]\n",hv_channel_code.len, hv_channel_code.arr));
	}	

	if (GetField_CString(hRls, "client_id", &csTmp)) {
                hv_client_id.len = strlen(csTmp);
                strncpy((char*)hv_client_id.arr, csTmp, hv_client_id.len);
                ind_client_id= 0;
DEBUGLOG(("Add:client_id = [%.*s]\n",hv_client_id.len, hv_client_id.arr));
	}	

        if (GetField_CString(hRls, "psp_id", &csTmp)) {
                hv_psp_id.len = strlen(csTmp);
                strncpy((char*)hv_psp_id.arr, csTmp, hv_psp_id.len);
                ind_psp_id= 0;
DEBUGLOG(("Add:psp_id = [%.*s]\n",hv_psp_id.len, hv_psp_id.arr));
        }

        if(GetField_Int(hRls, "scheduler_id", &iTmp)) {
                hv_scheduler_id = iTmp;
                ind_scheduler_id = 0;
DEBUGLOG(("Add:scheduler_id = [%d]\n",hv_disabled));
	}

        if(GetField_Int(hRls, "disabled", &iTmp)) {
                hv_disabled = iTmp;
                ind_disabled = 0;
        }
	else {
		hv_disabled = 0;
                ind_disabled = 0;
	}
DEBUGLOG(("Add:disabled = [%d]\n",hv_disabled));


        if(GetField_CString(hRls,"create_user",&csTmp))
        {
                hv_create_user.len = strlen(csTmp);
                strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
                ind_create_user = 0;
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));
        }

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_rule_disabled_bank_insert(
						:hv_int_bank_code:ind_int_bank_code,
						:hv_disabled_bank_type:ind_disabled_bank_type,
						:hv_channel_code:ind_channel_code,
						:hv_client_id:ind_client_id,
						:hv_psp_id:ind_psp_id,
						:hv_scheduler_id:ind_scheduler_id,
						:hv_disabled:ind_disabled,
						:hv_create_user:ind_create_user,
						:v_rule_disabled_bank_id); 
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_rule_disabled_bank_insert ( :h\
v_int_bank_code:ind_int_bank_code , :hv_disabled_bank_type:ind_disabled_bank_\
type , :hv_channel_code:ind_channel_code , :hv_client_id:ind_client_id , :hv_\
psp_id:ind_psp_id , :hv_scheduler_id:ind_scheduler_id , :hv_disabled:ind_disa\
bled , :hv_create_user:ind_create_user , :v_rule_disabled_bank_id ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_disabled_bank_type;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_disabled_bank_type;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_channel_code;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_channel_code;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_client_id;
 sqlstm.sqhstl[4] = (unsigned long )12;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_client_id;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[5] = (unsigned long )12;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_psp_id;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_scheduler_id;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_scheduler_id;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_disabled;
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
 sqlstm.sqhstv[9] = (unsigned char  *)&v_rule_disabled_bank_id;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)0;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
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
		PutField_Int(hRls, "rule_disbaled_bank_id", v_rule_disabled_bank_id);

DEBUGLOG(("Add:disabled_bank_id = [%d]\n",v_rule_disabled_bank_id));
                DEBUGLOG(("Add:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
                ERRLOG("RuleDisabledBank_Add: SP_OTHER_ERR TxnAbort\n");
                DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
                ERRLOG("RuleDisabledBank_Add: SP_ERR TxnAbort\n");
                DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }


add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("RuleDisabledBank_Add: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;


}

int Update(const hash_t *hRls)
{
	int	iRuleId;

	char	*csTmp;
	char	iTmp;
	char	*csBuf;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	/* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));

        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update rule_disabled_bank set rb_update_timestamp = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        GetField_Int(hRls,"rule_disabled_bank_id",&iRuleId);
DEBUGLOG(("Update:rule_disabled_bank_id = [%d]\n",iRuleId));

/* int_bank_code */
	if (GetField_CString(hRls, "int_bank_code", &csTmp)) {
DEBUGLOG(("Update:int_bank_code = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",rb_int_bank_code = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* disabled_bank_type */
        if (GetField_CString(hRls, "disabled_bank_type", &csTmp)) {
DEBUGLOG(("Update:disabled_bank_type = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",rb_disabled_bank_type = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* channel_code */
        if (GetField_CString(hRls, "channel_code", &csTmp)) {
DEBUGLOG(("Update:channel_code = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",rb_channel_code = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* client_id */
        if (GetField_CString(hRls, "client_id", &csTmp)) {
DEBUGLOG(("Update:client_id = [%s]\n",csTmp)); 
                strcat((char*)hv_dynstmt.arr, ",rb_client_id = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* psp_id */
        if (GetField_CString(hRls, "psp_id", &csTmp)) { 
DEBUGLOG(("Update:psp_id = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",rb_psp_id = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* scheduler_id */
        if (GetField_Int(hRls, "scheduler_id", &iTmp)) { 
DEBUGLOG(("Update:scheduler_id = [%d]\n",iTmp));
		sprintf(csBuf, "%d", iTmp);
                strcat((char*)hv_dynstmt.arr, ",rb_scheduler_id = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* disabled */
        if (GetField_Int(hRls, "disabled", &iTmp)) { 
DEBUGLOG(("Update:disabled = [%d]\n",iTmp));
		sprintf(csBuf, "%d", iTmp);
                strcat((char*)hv_dynstmt.arr, ",rb_disabled = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	strcat((char *)hv_dynstmt.arr, " WHERE rb_rule_disabled_bank_id = '");
	sprintf(csBuf, "%d", iRuleId);
        strcat((char *)hv_dynstmt.arr, csBuf);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )60;
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
        if (sqlca.sqlcode < 0) goto update_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )79;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_error;
}



        FREE_ME(csBuf);


DEBUGLOG(("Update Normal Exit\n"));
        return PD_OK;

update_error: 
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("RuleDisabledBank_Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;


}

int FindByBankCode (const char *csIntBankCode,
 	   	recordset_t *myRec)
{
	int iRet = PD_OK;
	int iCnt = 0;

        hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO findbybankcode_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		int		hv_disabled;

		int		v_rule_disabled_bank_id;
		/* varchar		v_disabled_bank_type[PD_DISABLED_BANK_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_disabled_bank_type;

		/* varchar		v_channel_code[PD_CHANNEL_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_channel_code;

		/* varchar		v_client_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_client_id;

		/* varchar		v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		int		v_scheduler_id;

		//int		v_disabled;

                short           ind_rule_disabled_bank_id = -1;
                short           ind_disabled_bank_type = -1;
                short           ind_channel_code = -1;
                short           ind_client_id = -1;
                short           ind_psp_id = -1;
                short           ind_scheduler_id = -1;

                //short           ind_disabled = -1;


        /* EXEC SQL END DECLARE SECTION; */ 


	hv_int_bank_code.len = strlen(csIntBankCode);
	memcpy(hv_int_bank_code.arr, csIntBankCode, hv_int_bank_code.len);
DEBUGLOG(("FindByBankCode IntBankCode = [%.*s]\n",hv_int_bank_code.len, hv_int_bank_code.arr));

	hv_disabled = 0;

        /* EXEC SQL DECLARE c_cursor_findbybankcode CURSOR FOR
                select  rb_rule_disabled_bank_id,
			rb_disabled_bank_type,
			rb_channel_code,
			rb_client_id,
			rb_psp_id,
			rb_scheduler_id
                  from rule_disabled_bank
                 where rb_int_bank_code = :hv_int_bank_code
		  and  rb_disabled = :hv_disabled; */ 


        /* EXEC SQL OPEN c_cursor_findbybankcode; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0003;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )94;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_int_bank_code;
        sqlstm.sqhstl[0] = (unsigned long )12;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_disabled;
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
        if (sqlca.sqlcode < 0) goto findbybankcode_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_findbybankcode
                INTO    :v_rule_disabled_bank_id:ind_rule_disabled_bank_id,
                        :v_disabled_bank_type:ind_disabled_bank_type,
                        :v_channel_code:ind_channel_code,
                        :v_client_id:ind_client_id,
                        :v_psp_id:ind_psp_id,
                        :v_scheduler_id: ind_scheduler_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )117;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_rule_disabled_bank_id;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_rule_disabled_bank_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_disabled_bank_type;
                sqlstm.sqhstl[1] = (unsigned long )6;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_disabled_bank_type;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_channel_code;
                sqlstm.sqhstl[2] = (unsigned long )6;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_channel_code;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_client_id;
                sqlstm.sqhstl[3] = (unsigned long )13;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_client_id;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_psp_id;
                sqlstm.sqhstl[4] = (unsigned long )13;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_psp_id;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_scheduler_id;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_scheduler_id;
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
                if (sqlca.sqlcode < 0) goto findbybankcode_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                iCnt++;

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

/* rule_disabled_bank_id */
		if (ind_rule_disabled_bank_id >= 0) {
			PutField_Int(myHash, "rule_disabled_bank_id", v_rule_disabled_bank_id);
DEBUGLOG(("FindByBankCode rule_disabled_bnak_id = [%d]\n",v_rule_disabled_bank_id));	
		}

/* disabled_bank_type */
		if (ind_disabled_bank_type >= 0) {
                        v_disabled_bank_type.arr[v_disabled_bank_type.len] = '\0';
                        PutField_CString(myHash, "disabled_bank_type", (const char *)v_disabled_bank_type.arr);
DEBUGLOG(("FindByBankCode disabled_bank_type = [%s]\n",v_disabled_bank_type.arr));
		}

/* channel_code */
		if (ind_channel_code >= 0) {
                        v_channel_code.arr[v_channel_code.len] = '\0';
                        PutField_CString(myHash, "channel_code", (const char *)v_channel_code.arr);
DEBUGLOG(("FindByBankCode channel_code = [%s]\n",v_channel_code.arr));
		}

/* client_id */
		if (ind_client_id >= 0) {
                        v_client_id.arr[v_client_id.len] = '\0';
                        PutField_CString(myHash, "client_id", (const char *)v_client_id.arr);
DEBUGLOG(("FindByBankCode client_id= [%s]\n",v_client_id.arr));
		}

/* psp_id */
		if (ind_psp_id >= 0) {
                        v_psp_id.arr[v_psp_id.len] = '\0';
                        PutField_CString(myHash, "psp_id", (const char *)v_psp_id.arr);
DEBUGLOG(("FindByBankCode psp_id= [%s]\n",v_psp_id.arr));
		}

/* scheduler_id */
		if (ind_scheduler_id >= 0) {
			PutField_Int(myHash, "scheduler_id", v_scheduler_id);
DEBUGLOG(("FindByBankCode scheduler_id = [%d]\n",v_scheduler_id));	
		}

                RecordSet_Add(myRec, myHash);
        }
        while (PD_TRUE);
        /* EXEC SQL CLOSE c_cursor_findbybankcode; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )156;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto findbybankcode_error;
}



        if (iCnt > 0 ) {
DEBUGLOG(("FindByBankCode Normal Exit\n"));
                return  iRet;
        }
        else {
DEBUGLOG(("FindByBankCode Normal Exit, Not Found\n"));
                return iRet; 
        }

findbybankcode_error:
DEBUGLOG(("findbybankcode_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_findbybankcode; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )171;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;


}

int FindByRuleIdforUpdate(const int iRuleId,
 	   		hash_t *myHash)
{
	int iRet = PD_OK;
	int iCnt = 0;

//        hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO findbyruleidforupdate_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		int		hv_rule_disabled_bank_id;

		/* varchar		v_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_int_bank_code;

		/* varchar		v_disabled_bank_type[PD_DISABLED_BANK_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_disabled_bank_type;

		/* varchar		v_channel_code[PD_CHANNEL_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_channel_code;

		/* varchar		v_client_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_client_id;

		/* varchar		v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		int		v_scheduler_id;
		int		v_disabled;

		short		ind_int_bank_code = -1;
                short           ind_disabled_bank_type = -1;
                short           ind_channel_code = -1;
                short           ind_client_id = -1;
                short           ind_psp_id = -1;
                short           ind_scheduler_id = -1;
                short           ind_disabled = -1;


        /* EXEC SQL END DECLARE SECTION; */ 



	hv_rule_disabled_bank_id = iRuleId;
DEBUGLOG(("FindByRuleIdForUpdate Rule_disabled_bank_id = [%d]\n", hv_rule_disabled_bank_id));


        /* EXEC SQL DECLARE c_cursor_findbyruleidforupdate CURSOR FOR
                select  rb_int_bank_code,
			rb_disabled_bank_type,
			rb_channel_code,
			rb_client_id,
			rb_psp_id,
			rb_scheduler_id,
			rb_disabled
                  from rule_disabled_bank
                 where rb_rule_disabled_bank_id = :hv_rule_disabled_bank_id
		  for update; */ 


        /* EXEC SQL OPEN c_cursor_findbyruleidforupdate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0004;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )186;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_rule_disabled_bank_id;
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
        if (sqlca.sqlcode < 0) goto findbyruleidforupdate_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_findbyruleidforupdate
                INTO    :v_int_bank_code:ind_int_bank_code,
                        :v_disabled_bank_type:ind_disabled_bank_type,
                        :v_channel_code:ind_channel_code,
                        :v_client_id:ind_client_id,
                        :v_psp_id:ind_psp_id,
                        :v_scheduler_id:ind_scheduler_id,
                        :v_disabled:ind_disabled; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )205;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_int_bank_code;
                sqlstm.sqhstl[0] = (unsigned long )12;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_int_bank_code;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_disabled_bank_type;
                sqlstm.sqhstl[1] = (unsigned long )6;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_disabled_bank_type;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_channel_code;
                sqlstm.sqhstl[2] = (unsigned long )6;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_channel_code;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_client_id;
                sqlstm.sqhstl[3] = (unsigned long )13;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_client_id;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_psp_id;
                sqlstm.sqhstl[4] = (unsigned long )13;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_psp_id;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_scheduler_id;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_scheduler_id;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_disabled;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_disabled;
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
                if (sqlca.sqlcode < 0) goto findbyruleidforupdate_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                iCnt++;

/*
                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);
*/

/* int_bank_code */
		if (ind_int_bank_code >= 0) {
                        v_int_bank_code.arr[v_int_bank_code.len] = '\0';
                        PutField_CString(myHash, "int_bank_code", (const char *)v_int_bank_code.arr);
DEBUGLOG(("FindByRuleIdforUpdate int_bank_code = [%s]\n",v_int_bank_code.arr));
		}

/* disabled_bank_type */
		if (ind_disabled_bank_type >= 0) {
                        v_disabled_bank_type.arr[v_disabled_bank_type.len] = '\0';
                        PutField_CString(myHash, "disabled_bank_type", (const char *)v_disabled_bank_type.arr);
DEBUGLOG(("FindByRuleIdforUpdate disabled_bank_type = [%s]\n",v_disabled_bank_type.arr));
		}

/* channel_code */
		if (ind_channel_code >= 0) {
                        v_channel_code.arr[v_channel_code.len] = '\0';
                        PutField_CString(myHash, "channel_code", (const char *)v_channel_code.arr);
DEBUGLOG(("FindByRuleIdforUpdate channel_code = [%s]\n",v_channel_code.arr));
		}

/* client_id */
		if (ind_client_id >= 0) {
                        v_client_id.arr[v_client_id.len] = '\0';
                        PutField_CString(myHash, "client_id", (const char *)v_client_id.arr);
DEBUGLOG(("FindByRuleIdforUpdate client_id= [%s]\n",v_client_id.arr));
		}

/* psp_id */
		if (ind_psp_id >= 0) {
                        v_psp_id.arr[v_psp_id.len] = '\0';
                        PutField_CString(myHash, "psp_id", (const char *)v_psp_id.arr);
DEBUGLOG(("FindByRuleIdforUpdate psp_id= [%s]\n",v_psp_id.arr));
		}

/* scheduler_id */
		if (ind_scheduler_id >= 0) {
			PutField_Int(myHash, "scheduler_id", v_scheduler_id);
DEBUGLOG(("FindByRuleIdforUpdate scheduler_id = [%d]\n",v_scheduler_id));	
		}

/* disabled */
		if (ind_disabled >= 0) {
			PutField_Int(myHash, "disabled", v_disabled);
DEBUGLOG(("FindByRuleIdforUpdate disabled = [%d]\n",v_disabled));	
		}

        }
        while (PD_TRUE);
        /* EXEC SQL CLOSE c_cursor_findbyruleidforupdate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )248;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto findbyruleidforupdate_error;
}



        if (iCnt > 0 ) {
DEBUGLOG(("FindByRuleIdforUpdate Normal Exit\n"));
                return  iRet;
        }
        else {
DEBUGLOG(("FindByRuleIdforUpdate Normal Exit, Not Found\n"));
                return iRet; 
        }

findbyruleidforupdate_error:
DEBUGLOG(("findbyruleidforupdate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_findbyruleidforupdate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )263;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;


}


int Delete (const int iRuleId) 
{
        /* EXEC SQL WHENEVER SQLERROR GOTO delete_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                int     hv_rule_disabled_bank_id;

                short   hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Delete: Begin\n"));
	
	hv_rule_disabled_bank_id = iRuleId;
DEBUGLOG(("Delete:rule_disabled_bank_id = [%d]\n",hv_rule_disabled_bank_id));

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rule_disabled_bank_delete(
                                                :hv_rule_disabled_bank_id
                                                );

                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_rule_disabled_bank_dele\
te ( :hv_rule_disabled_bank_id ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )278;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_rule_disabled_bank_id;
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
        if (sqlca.sqlcode < 0) goto delete_error;
}




DEBUGLOG(("Delete:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
                DEBUGLOG(("Delete:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
                ERRLOG("RuleDisabledBank_Delete: SP_OTHER_ERR TxnAbort\n");
                DEBUGLOG(("Delete: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
                ERRLOG("RuleDisabledBank_Delete: SP_ERR TxnAbort\n");
                DEBUGLOG(("Delete: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

delete_error:
DEBUGLOG(("delete_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("RuleDisabledBank_Delete: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}

