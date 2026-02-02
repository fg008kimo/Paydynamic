
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
           char  filnam[21];
};
static struct sqlcxp sqlfpn =
{
    20,
    "MmsAdjustmentType.pc"
};


static unsigned int sqlctx = 80498403;


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

 static char *sq0005 = 
"SELECT mat_desc , mat_amt_type , mat_bal_type , mat_nature , mat_disabled ,\
 mat_system_defined , mat_allow_modify , mat_allow_bal_negative FROM mms_adju\
stment_type WHERE mat_code = :b0            ";

 static char *sq0006 = 
"select max ( mat_code_in_num ) from mms_adjustment_type            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,448,0,6,185,0,0,13,13,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,
1,0,0,1,1,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,9,0,0,
72,0,0,2,0,0,17,375,0,0,1,1,0,1,0,1,9,0,0,
91,0,0,2,0,0,21,376,0,0,0,0,0,1,0,
106,0,0,3,69,0,6,412,0,0,2,2,0,1,0,2,3,0,0,1,9,0,0,
129,0,0,4,78,0,4,473,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
152,0,0,5,196,0,9,546,0,2049,1,1,0,1,0,1,9,0,0,
171,0,0,5,0,0,13,549,0,0,8,0,0,1,0,2,9,0,0,2,9,0,0,2,1,0,0,2,1,0,0,2,3,0,0,2,3,
0,0,2,3,0,0,2,3,0,0,
218,0,0,5,0,0,15,620,0,0,0,0,0,1,0,
233,0,0,5,0,0,15,634,0,0,0,0,0,1,0,
248,0,0,6,67,0,9,657,0,2049,0,0,0,1,0,
263,0,0,6,0,0,13,659,0,0,1,0,0,1,0,2,3,0,0,
282,0,0,6,0,0,15,671,0,0,0,0,0,1,0,
297,0,0,6,0,0,15,680,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/06/25              Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "internal.h"
#include "MmsAdjustmentType.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char    cDebug;

void MmsAdjustmentType(char    cdebug)
{
        cDebug = cdebug;
}


int Add(const hash_t *hRls)
{
	int	iTmp;

	char	cTmp;
	
	char	*csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO sync_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_code[PD_ADJ_TYPE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_code;

		int		hv_code_in_num;
		/* varchar		hv_desc[PD_ADJ_TYPE_DESC_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_desc;

		/* varchar		hv_amt_type[PD_AMT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_amt_type;

		char		hv_bal_type;
		char		hv_adj_nat;
		int		hv_disabled;
		int		hv_system_defined;
		int		hv_allow_modify;
		int		hv_allow_bal_negative;
		int		hv_adj_rpt_fe_display;
		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_code = -1;
		short		ind_code_in_num = -1;
		short		ind_desc = -1;
		short		ind_amt_type = -1;
		short		ind_bal_type = -1;
		short		ind_adj_nat = -1;
		short		ind_disabled = -1;
		short		ind_system_defined = -1;
		short		ind_allow_modify = -1;
		short		ind_allow_bal_negative = -1;
		short		ind_adj_rpt_fe_display = -1;
		short		ind_create_user = -1;
	
		short		hv_return_value;	
		
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

/* code */
        if(GetField_CString(hRls,"code",&csTmp)) {
                hv_code.len = strlen(csTmp);
                strncpy((char*)hv_code.arr, csTmp, hv_code.len);
                ind_code = 0;
DEBUGLOG(("Add:code = [%.*s]\n",hv_code.len, hv_code.arr));
        }

/* code_in_num */
        if(GetField_Int(hRls, "code_in_num", &iTmp)) {
                hv_code_in_num = iTmp;
                ind_code_in_num = 0;
DEBUGLOG(("Add:code_in_num = [%d]\n",hv_code_in_num));
        }

/* desc */
        if(GetField_CString(hRls,"desc",&csTmp)) {
                hv_desc.len = strlen(csTmp);
                strncpy((char*)hv_desc.arr, csTmp, hv_desc.len);
                ind_desc = 0;
DEBUGLOG(("Add:desc = [%.*s]\n",hv_desc.len, hv_desc.arr));
        }

/* amt_type */
        if(GetField_CString(hRls, "amt_type", &csTmp)) {
        	hv_amt_type.len = strlen(csTmp);
                strncpy((char*)hv_amt_type.arr, csTmp, hv_amt_type.len);
                ind_amt_type = 0;
DEBUGLOG(("Add:amt_type = [%.*s]\n",hv_amt_type.len, hv_amt_type.arr));
	}

/* bal_type */
        if(GetField_Char(hRls, "bal_type", &cTmp)) {
                hv_bal_type = cTmp;
                ind_bal_type = 0;
DEBUGLOG(("Add:bal_type = [%c]\n",hv_bal_type));
        }

/* adj_nat */
        if(GetField_Char(hRls, "adj_nat", &cTmp)) {
                hv_adj_nat = cTmp;
                ind_adj_nat = 0;
DEBUGLOG(("Add:adj_nat = [%c]\n",hv_adj_nat));
        }

/* disabled */
	if(GetField_Int(hRls, "disabled", &iTmp)) {
                hv_disabled = iTmp;
                ind_disabled = 0;
DEBUGLOG(("Add:disabled = [%d]\n",hv_disabled));
        } else {
		hv_disabled = 0;
		ind_disabled = 0;
DEBUGLOG(("Add:default disabled = [%d]\n",hv_disabled));
	}

/* system_defined */
        if(GetField_Int(hRls, "system_defined", &iTmp)) {
                hv_system_defined = iTmp;
                ind_system_defined = 0;
DEBUGLOG(("Add:system_defined = [%d]\n",hv_system_defined));
        } else {
		hv_system_defined = 0;
                ind_system_defined = 0;
DEBUGLOG(("Add:default system_defined = [%d]\n",hv_system_defined));
	}

/* allow_modify */
        if(GetField_Int(hRls, "allow_modify", &iTmp)) {
                hv_allow_modify = iTmp;
                ind_allow_modify = 0;
DEBUGLOG(("Add:allow_modify = [%d]\n",hv_allow_modify));
        } else {
		hv_allow_modify = 1;
                ind_allow_modify = 0;
DEBUGLOG(("Add:default allow_modify = [%d]\n",hv_allow_modify));
	}

/* allow_bal_negative */
        if(GetField_Int(hRls, "allow_bal_negative", &iTmp)) {
                hv_allow_bal_negative = iTmp;
                ind_allow_bal_negative = 0;
DEBUGLOG(("Add:allow_bal_negative = [%d]\n",hv_allow_bal_negative));
        } else {
		hv_allow_bal_negative = 0;
                ind_allow_bal_negative = 0;
DEBUGLOG(("Add:default allow_bal_negative = [%d]\n",hv_allow_bal_negative));
	}

/* adj_rpt_fe_display */
        if(GetField_Int(hRls, "adj_rpt_fe_display", &iTmp)) {
                hv_adj_rpt_fe_display = iTmp;
                ind_adj_rpt_fe_display = 0;
DEBUGLOG(("Add:adj_rpt_fe_display = [%d]\n",hv_adj_rpt_fe_display));
        } else {
		hv_adj_rpt_fe_display = 1;
                ind_adj_rpt_fe_display = 0;
DEBUGLOG(("Add:default adj_rpt_fe_display = [%d]\n",hv_adj_rpt_fe_display));
	}

/* create_user */
        if(GetField_CString(hRls,"create_user",&csTmp)) {
                hv_create_user.len = strlen(csTmp);
                strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
                ind_create_user = 0;
        }
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_mms_adj_type_insert(
								:hv_code:ind_code,
								:hv_code_in_num:ind_code_in_num,
								:hv_desc:ind_desc,
								:hv_amt_type:ind_amt_type,
								:hv_bal_type:ind_bal_type,
								:hv_adj_nat:ind_adj_nat,
								:hv_disabled:ind_disabled,
								:hv_system_defined:ind_system_defined,
								:hv_allow_modify:ind_allow_modify,
								:hv_allow_bal_negative:ind_allow_bal_negative,
								:hv_adj_rpt_fe_display:ind_adj_rpt_fe_display,
								:hv_create_user:ind_create_user); 
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_mms_adj_type_insert ( :hv_code\
:ind_code , :hv_code_in_num:ind_code_in_num , :hv_desc:ind_desc , :hv_amt_typ\
e:ind_amt_type , :hv_bal_type:ind_bal_type , :hv_adj_nat:ind_adj_nat , :hv_di\
sabled:ind_disabled , :hv_system_defined:ind_system_defined , :hv_allow_modif\
y:ind_allow_modify , :hv_allow_bal_negative:ind_allow_bal_negative , :hv_adj_\
rpt_fe_display:ind_adj_rpt_fe_display , :hv_create_user:ind_create_user ) ; E\
ND ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_code;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_code;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_code_in_num;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_code_in_num;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_desc;
 sqlstm.sqhstl[3] = (unsigned long )52;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_desc;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_amt_type;
 sqlstm.sqhstl[4] = (unsigned long )4;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_amt_type;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_bal_type;
 sqlstm.sqhstl[5] = (unsigned long )1;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_bal_type;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_adj_nat;
 sqlstm.sqhstl[6] = (unsigned long )1;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_adj_nat;
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
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_system_defined;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_system_defined;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_allow_modify;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_allow_modify;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_allow_bal_negative;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_allow_bal_negative;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_adj_rpt_fe_display;
 sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_adj_rpt_fe_display;
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
 if (sqlca.sqlcode < 0) goto sync_error;
}



DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("Add:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MmsAdjustmentType_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("MmsAdjustmentType_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

sync_error:
DEBUGLOG(("sync_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MmsAdjustmentType_Add: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int Update(const hash_t *hRls)
{
	int	iTmp;	

	char	cTmp;

	char	*csTmp;
	char    *csBuf;

        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar        	hv_dynstmt[PD_TMP_MSG_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[2048]; } hv_dynstmt;


		/* varchar 	hv_code[PD_ADJ_TYPE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_code;


		short 		ind_code = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	csBuf = (char*) malloc (512);

DEBUGLOG(("Update: Begin\n"));

        strcpy((char*)hv_dynstmt.arr,"update mms_adjustment_type set mat_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

/* code_in_num */
        if (GetField_Int(hRls,"code_in_num",&iTmp)) {
DEBUGLOG(("Update:update_code_in_num = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",mat_code_in_num = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* desc */
        if (GetField_CString(hRls,"desc",&csTmp)) {
DEBUGLOG(("Update:update_desc = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mat_desc = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* amt_type */
        if (GetField_CString(hRls,"amt_type",&csTmp)) {
DEBUGLOG(("Update:update_amt_type = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mat_amt_type = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* bal_type */
        if (GetField_Char(hRls,"bal_type",&cTmp)) {
DEBUGLOG(("Update:update_bal_type = [%c]\n",cTmp));
                sprintf(csBuf,"%c",cTmp);
                strcat((char*)hv_dynstmt.arr, ",mat_bal_type = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* adj_nat */
        if (GetField_Char(hRls,"adj_nat",&cTmp)) {
DEBUGLOG(("Update:update_adj_nat = [%c]\n",cTmp));
                sprintf(csBuf,"%c",cTmp);
                strcat((char*)hv_dynstmt.arr, ",mat_nature = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* disabled */
        if (GetField_Int(hRls,"disabled",&iTmp)) {
DEBUGLOG(("Update:update_disabled = [%d]\n",iTmp));
		sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",mat_disabled = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* system_defined */
        if (GetField_Int(hRls,"system_defined",&iTmp)) {
DEBUGLOG(("Update:update_system_defined = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",mat_system_defined = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* allow_modify */
        if (GetField_Int(hRls,"allow_modify",&iTmp)) {
DEBUGLOG(("Update:update_allow_modify = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",mat_allow_modify = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* allow_bal_negative */
        if (GetField_Int(hRls,"allow_bal_negative",&iTmp)) {
DEBUGLOG(("Update:update_allow_bal_negative = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",mat_allow_bal_negative = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* adj_rpt_fe_display */
        if (GetField_Int(hRls,"adj_rpt_fe_display",&iTmp)) {
DEBUGLOG(("Update:update_adj_rpt_fe_display = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",mat_adj_rpt_fe_display = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* update_user */
        if (GetField_CString(hRls,"update_user",&csTmp)) {
DEBUGLOG(("Update:update_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mat_update_user = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* Primary Key: code */
        if (GetField_CString(hRls,"code",&csTmp)) {
DEBUGLOG(("Update: code = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, " WHERE mat_code = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
       		strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

		hv_code.len = strlen(csTmp);
		strncpy((char*)hv_code.arr, csTmp, hv_code.len);
		ind_code = 0;
	}

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

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
        if (sqlca.sqlcode < 0) goto update_error;
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
        if (sqlca.sqlcode < 0) goto update_error;
}



DEBUGLOG(("Update Normal Exit\n"));
        return PD_OK;

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("MmsAdjustmentType:Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
        return PD_INTERNAL_ERR;
}

int Delete(const hash_t *hRls)
{
        char    *csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO delete_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar 	hv_code[PD_ADJ_TYPE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_code;


                short   	hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Delete: Begin\n"));

/* code */
        if(GetField_CString(hRls,"code",&csTmp)) {
                hv_code.len = strlen((const char*)csTmp);
                memcpy(hv_code.arr, csTmp, hv_code.len);
        }
DEBUGLOG(("Delete:code = [%.*s]\n",hv_code.len,hv_code.arr));

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_mms_adj_type_delete(
                                                :hv_code
                                                );
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_mms_adj_type_delete ( :\
hv_code ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )106;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_code;
        sqlstm.sqhstl[1] = (unsigned long )5;
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
ERRLOG("MmsAdjustmentType_Delete: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Delete: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("MmsAdjustmentType_Delete: SP_ERR TxnAbort\n");
DEBUGLOG(("Delete: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

delete_error:
DEBUGLOG(("delete_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MmsAdjustmentType_Delete: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_INTERNAL_ERR;
}

int Find(hash_t* hRls)
{
        int     iRet = PD_NOT_FOUND;

	char*	csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO find_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_code[PD_ADJ_TYPE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_code;


		int             v_disabled;	
        
		short 		ind_disabled = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Find()\n"));

/* code */
        if (GetField_CString(hRls,"code",&csTmp)) {
                hv_code.len = strlen(csTmp);
                strncpy((char*)hv_code.arr, csTmp, hv_code.len);
DEBUGLOG(("Find: code = [%.*s]\n", hv_code.len, hv_code.arr));
        }

        /* EXEC SQL	SELECT mat_disabled
			  INTO :v_disabled:ind_disabled	
	          	  FROM mms_adjustment_type
		 	 WHERE mat_code = :hv_code; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select mat_disabled INTO :b0:b1 FROM mms_adjustment_\
type WHERE mat_code = :b2 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )129;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_disabled;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_disabled;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_code;
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
        if (sqlca.sqlcode < 0) goto find_error;
}



/* disabled */
       	if (ind_disabled >= 0 ) {
		PutField_Int(hRls,"disabled",v_disabled);
DEBUGLOG(("Find: disabled = [%d]\n",v_disabled));
		iRet = PD_FOUND;
     	}

DEBUGLOG(("Find: Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

find_error:
DEBUGLOG(("find_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MmsAdjustmentType find_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int GetAdjustmentTypeRec(const char *csCode, hash_t *hRec)
{
	int iRet = PD_ERR;

	int iCnt = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO getadjustmenttype_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_code[PD_ADJ_TYPE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_code;


                /* varchar         v_desc[PD_ADJ_TYPE_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_desc;

		/* varchar		v_amt_type[PD_AMT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_amt_type;

		char		v_bal_type;
		char		v_nature;		
                int             v_disabled;
                int             v_system_defined;
                int             v_allow_modify;
                int             v_allow_bal_neg;

                short           ind_desc = -1;
                short           ind_amt_type = -1;
                short           ind_bal_type = -1;
                short           ind_nature = -1;
                short           ind_disabled = -1;
                short           ind_system_defined = -1;
                short           ind_allow_modify = -1;
                short           ind_allow_bal_neg = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


// code
	hv_code.len = strlen(csCode);
        memcpy(hv_code.arr,csCode,hv_code.len);
DEBUGLOG(("GetAdjustmentTypeRec code = [%.*s]\n",hv_code.len,hv_code.arr));

	/* EXEC SQL DECLARE c_cursor_getadjustmenttype CURSOR FOR
                SELECT  mat_desc,
			mat_amt_type,
			mat_bal_type,
			mat_nature,
		        mat_disabled,
  			mat_system_defined,
			mat_allow_modify,
			mat_allow_bal_negative
                FROM    mms_adjustment_type
                WHERE   mat_code = :hv_code; */ 


        /* EXEC SQL OPEN c_cursor_getadjustmenttype; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0005;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )152;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_code;
        sqlstm.sqhstl[0] = (unsigned long )5;
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
        if (sqlca.sqlcode < 0) goto getadjustmenttype_error;
}



	for (;;) {
                /* EXEC SQL FETCH c_cursor_getadjustmenttype
                INTO    :v_desc:ind_desc,
                        :v_amt_type:ind_amt_type,
                        :v_bal_type:ind_bal_type,
                        :v_nature:ind_nature,
                        :v_disabled:ind_disabled,
                        :v_system_defined:ind_system_defined,
                        :v_allow_modify:ind_allow_modify,
			:v_allow_bal_neg:ind_allow_bal_neg; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 13;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )171;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_desc;
                sqlstm.sqhstl[0] = (unsigned long )53;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_desc;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_amt_type;
                sqlstm.sqhstl[1] = (unsigned long )5;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_amt_type;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_bal_type;
                sqlstm.sqhstl[2] = (unsigned long )1;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_bal_type;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_nature;
                sqlstm.sqhstl[3] = (unsigned long )1;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_nature;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_disabled;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_disabled;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_system_defined;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_system_defined;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_allow_modify;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_allow_modify;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_allow_bal_neg;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_allow_bal_neg;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto getadjustmenttype_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		iCnt++;
	
/* desc */
                if (ind_desc >= 0) {
                        v_desc.arr[v_desc.len] = '\0';
                        PutField_CString(hRec, "desc", (const char*)v_desc.arr);
DEBUGLOG(("GetAdjustmentTypeRec desc = [%s]\n", (const char*)v_desc.arr));
                }

/* amt_type */
                if (ind_amt_type >= 0) {
                        v_amt_type.arr[v_amt_type.len] = '\0';
                        PutField_CString(hRec, "amt_type", (const char*)v_amt_type.arr);
DEBUGLOG(("GetAdjustmentTypeRec amt_type = [%s]\n", (const char*)v_amt_type.arr));
                }

/* bal_type */
		if (ind_bal_type >= 0) {
                        PutField_Char(hRec, "bal_type", v_bal_type);
DEBUGLOG(("GetAdjustmentTypeRec bal_type = [%c]\n", v_bal_type));
                }

/* nature */
                if (ind_nature >= 0) {
                        PutField_Char(hRec, "nature", v_nature);
DEBUGLOG(("GetAdjustmentTypeRec nature = [%c]\n", v_nature));
                }

/* disabled */
		if (ind_disabled >= 0) {
                        PutField_Int(hRec, "disabled", v_disabled);
DEBUGLOG(("GetAdjustmentTypeRec disabled = [%d]\n", v_disabled));

                }

/* system_defined */
                if (ind_system_defined >= 0) {
                        PutField_Int(hRec, "system_defined", v_system_defined);
DEBUGLOG(("GetAdjustmentTypeRec system_defined = [%d]\n", v_system_defined));

                }

/* allow_modify */
                if (ind_allow_modify >= 0) {
                        PutField_Int(hRec, "allow_modify", v_allow_modify);
DEBUGLOG(("GetAdjustmentTypeRec allow_modify = [%d]\n", v_allow_modify));

                }

/* allow_bal_neg */
                if (ind_allow_bal_neg >= 0) {
                        PutField_Int(hRec, "allow_bal_neg", v_allow_bal_neg);
DEBUGLOG(("GetAdjustmentTypeRec allow_bal_neg = [%d]\n", v_allow_bal_neg));

                }
        }

        /* EXEC SQL CLOSE c_cursor_getadjustmenttype; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )218;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getadjustmenttype_error;
}



	if (iCnt > 0 ) {
                iRet = PD_OK;
        }

DEBUGLOG(("GetAdjustmentTypeRec Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

getadjustmenttype_error:
DEBUGLOG(("getadjustmenttype_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MmsAdjustmentType getadjustmenttype_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        /* EXEC SQL CLOSE c_cursor_getadjustmenttype; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )233;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getadjustmenttype_error;
}


        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}	

int GetMaxCode(int  *iMaxCodeInNum)
{
        int iRet = PD_OK;

        /* EXEC SQL WHENEVER SQLERROR GOTO getmaxcode_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                int     v_code_in_num;

                short   ind_code_in_num = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        /* EXEC SQL DECLARE c_cursor_getmax_code CURSOR FOR
                select max(mat_code_in_num)
                  from mms_adjustment_type; */ 


        /* EXEC SQL OPEN c_cursor_getmax_code; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0006;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )248;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getmaxcode_error;
}



        /* EXEC SQL FETCH c_cursor_getmax_code
        INTO
                :v_code_in_num:ind_code_in_num; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )263;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_code_in_num;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_code_in_num;
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
        if (sqlca.sqlcode < 0) goto getmaxcode_error;
}



/* code_in_num */
        if (ind_code_in_num >=0) {
                *iMaxCodeInNum = v_code_in_num;
DEBUGLOG(("GetMaxCode code = [%d]\n",iMaxCodeInNum));
        } else {
DEBUGLOG(("GetMaxCode not found\n"));
        }

        /* EXEC SQL CLOSE c_cursor_getmax_code; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )282;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getmaxcode_error;
}



DEBUGLOG(("GetMaxCode Normal Exit iRet =[%d]\n",iRet));
        return iRet;

getmaxcode_error:
DEBUGLOG(("getmaxcode_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getmax_code; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )297;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}
