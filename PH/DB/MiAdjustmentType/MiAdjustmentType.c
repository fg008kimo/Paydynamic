
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
    "MiAdjustmentType.pc"
};


static unsigned int sqlctx = 38817507;


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
   unsigned char  *sqhstv[11];
   unsigned long  sqhstl[11];
            int   sqhsts[11];
            short *sqindv[11];
            int   sqinds[11];
   unsigned long  sqharm[11];
   unsigned long  *sqharc[11];
   unsigned short  sqadto[11];
   unsigned short  sqtdso[11];
} sqlstm = {12,11};

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
"select max ( mat_code_in_num ) from mi_adjustment_type where mat_entity_typ\
e = :b0            ";

 static char *sq0005 = 
"select mat_desc , mat_amt_type , mat_bal_type , mat_nature , mat_is_prorata\
 , mat_disabled from mi_adjustment_type where mat_entity_type = :b0 and mat_c\
ode = :b1            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,94,0,9,57,0,2049,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,13,59,0,0,1,0,0,1,0,2,3,0,0,
43,0,0,1,0,0,15,73,0,0,0,0,0,1,0,
58,0,0,1,0,0,15,82,0,0,0,0,0,1,0,
73,0,0,2,346,0,6,202,0,0,11,11,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,9,0,0,1,
9,0,0,1,1,0,0,1,1,0,0,1,3,0,0,1,3,0,0,1,9,0,0,
132,0,0,3,312,0,6,348,0,0,10,10,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,1,0,0,1,1,0,0,1,3,0,0,1,3,0,0,1,9,0,0,
187,0,0,4,93,0,6,422,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
214,0,0,5,173,0,9,518,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
237,0,0,5,0,0,13,520,0,0,6,0,0,1,0,2,9,0,0,2,9,0,0,2,1,0,0,2,1,0,0,2,3,0,0,2,3,
0,0,
276,0,0,5,0,0,15,578,0,0,0,0,0,1,0,
291,0,0,5,0,0,15,594,0,0,0,0,0,1,0,
306,0,0,6,105,0,4,628,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/11/04              Dirk Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "MiAdjustmentType.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char    cDebug;

void MiAdjustmentType(char    cdebug)
{
        cDebug = cdebug;
}

int GetMaxCode(const char *csEntityType,
		  int  *iMaxCodeInNum)
{
        int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO getmaxcode_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_entity_type[PD_MMS_ENTITY_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_entity_type;


		int	v_code_in_num;

		short	ind_code_in_num = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_entity_type.len = strlen(csEntityType);
	memcpy(hv_entity_type.arr,csEntityType,hv_entity_type.len);
DEBUGLOG(("GetMaxCode entity_type = [%.*s]\n",hv_entity_type.len,hv_entity_type.arr));

	/* EXEC SQL DECLARE c_cursor_getmax_code CURSOR FOR
		select max(mat_code_in_num)
		  from mi_adjustment_type
 		 where mat_entity_type = :hv_entity_type; */ 

	
	/* EXEC SQL OPEN c_cursor_getmax_code; */ 

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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_entity_type;
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
 if (sqlca.sqlcode < 0) goto getmaxcode_error;
}



	/* EXEC SQL FETCH c_cursor_getmax_code
	INTO
		:v_code_in_num:ind_code_in_num; */ 

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



	if (ind_code_in_num >=0) {
		*iMaxCodeInNum = v_code_in_num;
DEBUGLOG(("GetMaxCode code = [%d]\n",iMaxCodeInNum));

	}
	else {
DEBUGLOG(("GetMaxCode not found\n"));

	}

	/* EXEC SQL CLOSE c_cursor_getmax_code; */ 

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

int Add(const hash_t *hRls)
{
	char  cTmp;
	char  *csTmp;
	int   iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_entity_type[PD_MMS_ENTITY_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_entity_type;

		/* varchar		hv_code[PD_ADJ_TYPE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_code;

		int		hv_code_in_num;
		/* varchar		hv_desc[PD_ADJ_TYPE_DESC_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_desc;

		/* varchar		hv_amt_type[PD_AMT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_amt_type;

		char		hv_bal_type;
		char		hv_nature;
		int		hv_is_prorata;
		int		hv_disabled;
		/* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



		short		ind_entity_type = -1;
		short		ind_code = -1;
		short		ind_code_in_num = -1;
		short		ind_desc = -1;
		short		ind_amt_type = -1;
		short		ind_bal_type = -1;
		short		ind_nature = -1;
		short		ind_is_prorata = 1;
		short		ind_disabled = -1;
		short		ind_create_user = -1;
	
		short		hv_return_value;	
		
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

//entity_type
	if (GetField_CString(hRls, "entity_type", &csTmp)) {	
		hv_entity_type.len = strlen(csTmp);
		strncpy((char*)hv_entity_type.arr, csTmp, hv_entity_type.len);
		ind_entity_type = 0;
	}
DEBUGLOG(("Add:entity_type = [%.*s]\n",hv_entity_type.len,hv_entity_type.arr));

//code
        if(GetField_CString(hRls,"code",&csTmp)) {
                hv_code.len = strlen(csTmp);
                strncpy((char*)hv_code.arr, csTmp, hv_code.len);
                ind_code = 0;
        }
DEBUGLOG(("Add:code = [%.*s]\n",hv_code.len, hv_code.arr));

//code_in_num
	if(GetField_Int(hRls, "code_in_num", &iTmp)) {
		hv_code_in_num = iTmp;
		ind_code_in_num= 0;
	}
DEBUGLOG(("Add:code_in_num = [%d]\n",hv_code_in_num));

//desc
        if(GetField_CString(hRls,"desc",&csTmp)) {
                hv_desc.len = strlen(csTmp);
                strncpy((char*)hv_desc.arr, csTmp, hv_desc.len);
                ind_desc = 0;
        }
DEBUGLOG(("Add:desc = [%.*s]\n",hv_desc.len, hv_desc.arr));

//amt_type
        if(GetField_CString(hRls,"amt_type",&csTmp)) {
                hv_amt_type.len = strlen(csTmp);
                strncpy((char*)hv_amt_type.arr, csTmp, hv_amt_type.len);
                ind_amt_type = 0;
        }
DEBUGLOG(("Add:code = [%.*s]\n",hv_code.len, hv_code.arr));

//bal_type
	if(GetField_Char(hRls, "bal_type", &cTmp)) {
		hv_bal_type = cTmp;
		ind_bal_type = 0;
DEBUGLOG(("Add:bal_type = [%c]\n",hv_bal_type));
	}

//nature
	if(GetField_Char(hRls, "nature", &cTmp)) {
		hv_nature = cTmp;
		ind_nature = 0;
DEBUGLOG(("Add:nature = [%c]\n",hv_nature));
	}

//is_prorata
        if(GetField_Int(hRls, "is_prorata", &iTmp)) {
                hv_is_prorata = iTmp;
                ind_is_prorata = 0;
        }
DEBUGLOG(("Add:is_prorata = [%d]\n",hv_is_prorata));

//disabled
        if(GetField_Int(hRls, "disabled", &iTmp)) {
                hv_disabled = iTmp;
                ind_disabled = 0;
        }
DEBUGLOG(("Add:disabled = [%d]\n",hv_disabled));

//create_user
        if(GetField_CString(hRls,"create_user",&csTmp))
        {
                hv_create_user.len = strlen(csTmp);
                strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
                ind_create_user = 0;
        }
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_mi_adjustment_type_insert(
						:hv_entity_type:ind_entity_type,
						:hv_code:ind_code,
						:hv_code_in_num:ind_code_in_num,
						:hv_desc:ind_desc,
						:hv_amt_type:ind_amt_type,
						:hv_bal_type:ind_bal_type,
						:hv_nature:ind_nature,
						:hv_is_prorata:ind_is_prorata,
						:hv_disabled:ind_disabled,
						:hv_create_user:ind_create_user
						); 
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_mi_adjustment_type_insert ( :h\
v_entity_type:ind_entity_type , :hv_code:ind_code , :hv_code_in_num:ind_code_\
in_num , :hv_desc:ind_desc , :hv_amt_type:ind_amt_type , :hv_bal_type:ind_bal\
_type , :hv_nature:ind_nature , :hv_is_prorata:ind_is_prorata , :hv_disabled:\
ind_disabled , :hv_create_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )73;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_entity_type;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_entity_type;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_code;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_code;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_code_in_num;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_code_in_num;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_desc;
 sqlstm.sqhstl[4] = (unsigned long )52;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_desc;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_amt_type;
 sqlstm.sqhstl[5] = (unsigned long )4;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_amt_type;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_bal_type;
 sqlstm.sqhstl[6] = (unsigned long )1;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_bal_type;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_nature;
 sqlstm.sqhstl[7] = (unsigned long )1;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_nature;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_is_prorata;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_is_prorata;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_disabled;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[10] = (unsigned long )22;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_create_user;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
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
                ERRLOG("MiAdjustmentType_Add: SP_OTHER_ERR TxnAbort\n");
                DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
                ERRLOG("MiAdjustmentType_Add: SP_ERR TxnAbort\n");
                DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }


add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MiAdjustmentType_Add: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;


}


int Update(const hash_t *hRls)
{

	char	cTmp;
	char	*csTmp;
	int	iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO update_miadjtype_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_entity_type[PD_MMS_ENTITY_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_entity_type;

		/* varchar	hv_code[PD_ADJ_TYPE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_code;

		/* varchar	hv_desc[PD_ADJ_TYPE_DESC_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_desc;

		/* varchar	hv_amt_type[PD_AMT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_amt_type;

		char	hv_bal_type;
		char	hv_nature;
		int	hv_is_prorata;
		int	hv_disabled;
		/* varchar hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;


		short	ind_entity_type = -1;
		short	ind_code = -1;
		short	ind_desc = -1;
		short	ind_amt_type = -1;
		short	ind_bal_type = -1;
		short	ind_nature = -1;
		short	ind_is_prorata = -1;
		short	ind_disabled = -1;
		short	ind_update_user = -1;

		short   hv_return_value;
		
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update Mi Adj Type: Begin\n"));

	if (GetField_CString(hRls, "entity_type", &csTmp)) {
		hv_entity_type.len = strlen((const char*)csTmp);
		memcpy(hv_entity_type.arr, csTmp, hv_entity_type.len);
		ind_entity_type = 0;
	}
DEBUGLOG(("Update Mi Adj Type:entity_type = [%.*s]\n",hv_entity_type.len,hv_entity_type.arr));

	if (GetField_CString(hRls,"code",&csTmp)) {
		hv_code.len = strlen((const char*)csTmp);
		memcpy(hv_code.arr, csTmp, hv_code.len);
		ind_code = 0;
	}
DEBUGLOG(("Update Mi Adj Type:code = [%.*s]\n",hv_code.len, hv_code.arr));

	if (GetField_CString(hRls,"desc",&csTmp)) {
		hv_desc.len = strlen((const char*)csTmp);
		memcpy(hv_desc.arr, csTmp, hv_desc.len);
		ind_desc = 0;
        }
DEBUGLOG(("Update Mi Adj Type: desc = [%.*s]\n",hv_desc.len, hv_desc.arr));

	if (GetField_CString(hRls,"amt_type",&csTmp)) {
		hv_amt_type.len = strlen((const char*)csTmp);
		memcpy(hv_amt_type.arr, csTmp, hv_amt_type.len);
		ind_amt_type = 0;
        }
DEBUGLOG(("Update Mi Adj Type: amt_type = [%.*s]\n",hv_amt_type.len, hv_amt_type.arr));

        if (GetField_Char(hRls,"bal_type",&cTmp)) {
		hv_bal_type = cTmp;
		ind_bal_type = 0;
DEBUGLOG(("Update Mi Adj Type: bal_type = [%c]\n", hv_bal_type));
        }

        if (GetField_Char(hRls,"nature",&cTmp)) {
		hv_nature = cTmp;
		ind_nature = 0;
DEBUGLOG(("Update Mi Adj Type: nature = [%c]\n", hv_nature));
        }

        if (GetField_Int(hRls,"is_prorata",&iTmp)) {
		hv_is_prorata = iTmp;
		ind_is_prorata = 0;
DEBUGLOG(("Update Mi Adj Type: is_prorata = [%d]\n", hv_is_prorata));
        }

        if (GetField_Int(hRls,"disabled",&iTmp)) {
		hv_disabled = iTmp;
		ind_disabled = 0;
        }
DEBUGLOG(("Update Mi Adj Type: disabled = [%d]\n", hv_disabled));


//update_user
        if(GetField_CString(hRls,"update_user",&csTmp)){
		hv_update_user.len = strlen((const char *)csTmp);
		memcpy(hv_update_user.arr, csTmp, hv_update_user.len);
		ind_update_user = 0;
        }
DEBUGLOG(("Update Mi Adj Type: update_user = [%.*s]\n",hv_update_user.len, hv_update_user.arr));

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_mi_adjustment_type_update(
						:hv_entity_type:ind_entity_type,
						:hv_code:ind_code,
						:hv_desc:ind_desc,
						:hv_amt_type:ind_amt_type,
						:hv_bal_type:ind_bal_type,
						:hv_nature:ind_nature,
						:hv_is_prorata:ind_is_prorata,
						:hv_disabled:ind_disabled,
						:hv_update_user:ind_update_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_mi_adjustment_type_update ( :h\
v_entity_type:ind_entity_type , :hv_code:ind_code , :hv_desc:ind_desc , :hv_a\
mt_type:ind_amt_type , :hv_bal_type:ind_bal_type , :hv_nature:ind_nature , :h\
v_is_prorata:ind_is_prorata , :hv_disabled:ind_disabled , :hv_update_user:ind\
_update_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )132;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_entity_type;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_entity_type;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_code;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_code;
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
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_nature;
 sqlstm.sqhstl[6] = (unsigned long )1;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_nature;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_is_prorata;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_is_prorata;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_disabled;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_update_user;
 sqlstm.sqhstl[9] = (unsigned long )22;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_update_user;
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
 if (sqlca.sqlcode < 0) goto update_miadjtype_error;
}




	if (hv_return_value == SP_OK) {
DEBUGLOG(("Update Mi Adj Type Normal Exit\n"));
		return 	PD_OK;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("MiAdjustmentType_Update: SP_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("MiAdjustmentType_Update: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}


update_miadjtype_error:
DEBUGLOG(("update_miadjtype_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("MiAdjustmentType_Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;
}


int Delete (const hash_t *hRls)
{
	char	*csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO delete_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_entity_type[PD_MMS_ENTITY_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_entity_type;

		/* varchar	hv_code[PD_ADJ_TYPE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_code;


		short   hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Delete: Begin\n"));

	if(GetField_CString(hRls,"entity_type",&csTmp)) {
		hv_entity_type.len = strlen((const char*)csTmp);
		memcpy(hv_entity_type.arr, csTmp, hv_entity_type.len);
        }
DEBUGLOG(("Delete:entity_type = [%.*s]\n",hv_entity_type.len,hv_entity_type.arr));


        if(GetField_CString(hRls,"code",&csTmp)) {
		hv_code.len = strlen((const char*)csTmp);
		memcpy(hv_code.arr, csTmp, hv_code.len);
        }
DEBUGLOG(("Delete:code = [%.*s]\n",hv_code.len,hv_code.arr));

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_mi_adjustment_type_delete(	
						:hv_entity_type,
						:hv_code
						);

		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_mi_adjustment_type_delete ( :h\
v_entity_type , :hv_code ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )187;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_entity_type;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_code;
 sqlstm.sqhstl[2] = (unsigned long )5;
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
                ERRLOG("MiAdjustmentType_Delete: SP_OTHER_ERR TxnAbort\n");
                DEBUGLOG(("Delete: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
                ERRLOG("MiAdjustmentType_Delete: SP_ERR TxnAbort\n");
                DEBUGLOG(("Delete: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

delete_error:
DEBUGLOG(("delete_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MiAdjustmentType_Delete: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;	

}


int	GetMiAdjustmentTypeRec(const char *csEntityType, 
			       const char *csCode ,
			       recordset_t *myRec)
{
	int 	iCnt = 0;
	hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO isbyprorata_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_entity_type[PD_MMS_ENTITY_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_entity_type;

		/* varchar		hv_code[PD_ADJ_TYPE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_code;

		//int		hv_disabled;

		/* varchar		v_desc[PD_ADJ_TYPE_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_desc;

		/* varchar		v_amt_type[PD_AMT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_amt_type;

		char		v_bal_type;
		char		v_nature;
		int		v_is_prorata;
		int		v_disabled;

		short		ind_desc = -1;
		short		ind_amt_type = -1;
		short		ind_bal_type = -1;
		short		ind_nature = -1;
		short		ind_is_prorata = -1;
		short		ind_disabled = -1;


        /* EXEC SQL END DECLARE SECTION; */ 


        hv_entity_type.len = strlen(csEntityType);
        memcpy(hv_entity_type.arr,csEntityType,hv_entity_type.len);
DEBUGLOG(("GetMiAdjustmentTypeRec entity_type = [%.*s]\n", hv_entity_type.len,hv_entity_type.arr));

        hv_code.len = strlen(csCode);
        memcpy(hv_code.arr,csCode,hv_code.len);
DEBUGLOG(("GetMiAdjustmentTypeRec code = [%.*s]\n",hv_code.len,hv_code.arr));


	//hv_disabled = 0;


        /* EXEC SQL DECLARE c_cursor_getmiadjtype CURSOR FOR
		select	mat_desc,
			mat_amt_type,
		       	mat_bal_type,
		       	mat_nature,
			mat_is_prorata,	
	                mat_disabled
		  from	mi_adjustment_type
		 where	mat_entity_type = :hv_entity_type
		   and	mat_code = :hv_code; */ 

		   //and mat_disabled = :hv_disabled;

        /* EXEC SQL OPEN c_cursor_getmiadjtype; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0005;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )214;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_entity_type;
        sqlstm.sqhstl[0] = (unsigned long )5;
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
        if (sqlca.sqlcode < 0) goto isbyprorata_error;
}


        do {
		/* EXEC SQL FETCH c_cursor_getmiadjtype
		INTO	:v_desc:ind_desc,
			:v_amt_type:ind_amt_type,
			:v_bal_type:ind_bal_type,
			:v_nature:ind_nature,
			:v_is_prorata:ind_is_prorata,
			:v_disabled:ind_disabled; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 11;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )237;
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
  sqlstm.sqhstv[4] = (unsigned char  *)&v_is_prorata;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_is_prorata;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_disabled;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_disabled;
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
  if (sqlca.sqlcode < 0) goto isbyprorata_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}	

		iCnt++;

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

// desc 
		if (ind_desc >= 0) {
			v_desc.arr[v_desc.len] = '\0';
			PutField_CString(myHash, "desc", (const char *)v_desc.arr);
DEBUGLOG(("GetMiAdjustmentTypeRec desc = [%s]\n",v_desc.arr));
		}

// amt_type 
		if (ind_amt_type >= 0) {
			v_amt_type.arr[v_amt_type.len] = '\0';
			PutField_CString(myHash, "amt_type", (const char *)v_amt_type.arr);
DEBUGLOG(("GetMiAdjustmentTypeRec amt_type = [%s]\n",v_amt_type.arr));
		}

// bal_type 
		if (ind_bal_type >= 0) {
			PutField_Char(myHash, "bal_type", v_bal_type);
DEBUGLOG(("GetMiAdjustmentTypeRec bal_type = [%c]\n", v_bal_type));
		}

// nature 
		if (ind_nature >= 0) {
			PutField_Char(myHash, "nature", v_nature);
DEBUGLOG(("GetMiAdjustmentTypeRec nature = [%c]\n", v_nature));
		}

// is_prorata 
		if (ind_is_prorata >= 0) {
			PutField_Int(myHash, "is_prorata", v_is_prorata);
DEBUGLOG(("GetMiAdjustmentTypeRec is_prorata = [%d]\n", v_is_prorata));
		}

// disabled 
		if (ind_disabled >= 0) {
			PutField_Int(myHash, "disabled", v_disabled);
DEBUGLOG(("GetMiAdjustmentTypeRec disabled = [%d]\n", v_disabled));
		}

		RecordSet_Add(myRec, myHash);
	}
	while (PD_TRUE);
	/* EXEC SQL CLOSE c_cursor_getmiadjtype; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )276;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto isbyprorata_error;
}



        if (iCnt > 0 ) {
DEBUGLOG(("GetMiAdjustmentTypeRec Normal Exit\n"));
                return  PD_OK;
        }
        else {
DEBUGLOG(("GetMiAdjustmentTypeRec Normal Exit, Not Found\n"));
                return PD_ERR;
        }


isbyprorata_error:
DEBUGLOG(("getadjustmenttype_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getmiadjtype; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )291;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;

}


int	IsByProrata(const char *csEntityType, 
			       const char *csCode)
{
	int 	iRet = PD_FALSE;

        /* EXEC SQL WHENEVER SQLERROR GOTO isbyprorata_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_entity_type[PD_MMS_ENTITY_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_entity_type;

		/* varchar		hv_code[PD_ADJ_TYPE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_code;


		int		v_is_prorata;

		short		ind_is_prorata = -1;


        /* EXEC SQL END DECLARE SECTION; */ 


        hv_entity_type.len = strlen(csEntityType);
        memcpy(hv_entity_type.arr,csEntityType,hv_entity_type.len);
DEBUGLOG(("IsByProrata entity_type = [%.*s]\n", hv_entity_type.len,hv_entity_type.arr));

        hv_code.len = strlen(csCode);
        memcpy(hv_code.arr,csCode,hv_code.len);
DEBUGLOG(("IsByProrata code = [%.*s]\n",hv_code.len,hv_code.arr));


        /* EXEC SQL 
		select	
			mat_is_prorata
		INTO	:v_is_prorata:ind_is_prorata
		  from	mi_adjustment_type
		 where	mat_entity_type = :hv_entity_type
		   and	mat_code = :hv_code; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select mat_is_prorata INTO :b0:b1 from mi_adjustment\
_type where mat_entity_type = :b2 and mat_code = :b3 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )306;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_is_prorata;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_is_prorata;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_entity_type;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_code;
        sqlstm.sqhstl[2] = (unsigned long )5;
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
        if (sqlca.sqlcode < 0) goto isbyprorata_error;
}



// is_prorata 
		if (ind_is_prorata >= 0) {
			iRet = v_is_prorata;
DEBUGLOG(("IsByProrata is_prorata = [%d]\n", v_is_prorata));
		}

DEBUGLOG(("IsByProrata Normal Exit\n"));
                return iRet;

isbyprorata_error:
DEBUGLOG(("getadjustmenttype_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}

