
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
    "OLAdjustmentType.pc"
};


static unsigned int sqlctx = 39735011;


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

 static char *sq0001 = 
"select max ( oat_code_in_num ) from ol_adjustment_type where oat_party_type\
 = :b0            ";

 static char *sq0003 = 
"select oat_dc_ind , oat_desc , oat_disabled , oat_allow_modify , oat_allow_\
bal_negative , oat_bal_type from ol_adjustment_type where oat_party_type = :b\
0 and oat_code = :b1            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,93,0,9,58,0,2049,1,1,0,1,0,1,1,0,0,
24,0,0,1,0,0,13,60,0,0,1,0,0,1,0,2,3,0,0,
43,0,0,1,0,0,15,74,0,0,0,0,0,1,0,
58,0,0,1,0,0,15,83,0,0,0,0,0,1,0,
73,0,0,2,308,0,6,192,0,0,10,10,0,1,0,2,3,0,0,1,1,0,0,1,9,0,0,1,3,0,0,1,1,0,0,1,
9,0,0,1,3,0,0,1,9,0,0,1,1,0,0,1,1,0,0,
128,0,0,3,184,0,9,292,0,2049,2,2,0,1,0,1,1,0,0,1,9,0,0,
151,0,0,3,0,0,13,294,0,0,6,0,0,1,0,2,1,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,1,
0,0,
190,0,0,3,0,0,15,353,0,0,0,0,0,1,0,
205,0,0,3,0,0,15,369,0,0,0,0,0,1,0,
220,0,0,4,250,0,6,455,0,0,8,8,0,1,0,2,3,0,0,1,1,0,0,1,9,0,0,1,1,0,0,1,9,0,0,1,
3,0,0,1,9,0,0,1,1,0,0,
267,0,0,5,92,0,6,526,0,0,3,3,0,1,0,2,3,0,0,1,1,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/11/07              David Wong
Add Adjustment nature type			   2014/07/02		   Dirk Wong
Add balance type				   2016/01/05		   LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "OLAdjustmentType.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char    cDebug;

void OLAdjustmentType(char    cdebug)
{
        cDebug = cdebug;
}

int GetMaxCode(const char cPartyType,
		  int  *iMaxCodeInNum)
{
        int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO getmaxcode_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		char	hv_party_type;

		int	v_code_in_num;

		short	ind_code_in_num = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_party_type = cPartyType;
DEBUGLOG(("GetMaxCode party_type = [%c]\n",hv_party_type));

	/* EXEC SQL DECLARE c_cursor_getmax_code CURSOR FOR
		select max(oat_code_in_num)
		  from ol_adjustment_type
 		 where oat_party_type = :hv_party_type; */ 

	
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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_party_type;
 sqlstm.sqhstl[0] = (unsigned long )1;
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
DEBUGLOG(("GetMaxCode code = [%d]\n",*iMaxCodeInNum));

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

		char		hv_party_type;
		char	 	hv_dc_ind;	
		/* varchar		hv_desc[PD_ADJ_TYPE_DESC_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_desc;

		/* varchar		hv_code[PD_ADJ_TYPE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_code;

		int		hv_code_in_num;
		int		hv_disabled;
		/* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;

		char		hv_nature;
		char		hv_bal_type;


		short		ind_party_type = -1;
		short		ind_dc_ind = -1;
		short		ind_desc = -1;
		short		ind_code = -1;
		short		ind_code_in_num = -1;
		short		ind_disabled = -1;
		short		ind_create_user = -1;
		short		ind_nature = -1;
		short		ind_bal_type = -1;

		short		hv_return_value;	
		
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));


	if (GetField_Char(hRls, "party_type", &cTmp)) {	
		hv_party_type = cTmp;
		ind_party_type = 0;
DEBUGLOG(("Add:party_type = [%c]\n",hv_party_type));
	}

	if (GetField_Char(hRls, "dc_ind", &cTmp)) {
		hv_dc_ind = cTmp;
		ind_dc_ind = 0;
DEBUGLOG(("Add:dc_ind = [%c]\n",hv_dc_ind));
	}	

        if(GetField_CString(hRls,"desc",&csTmp)) {
                hv_desc.len = strlen(csTmp);
                strncpy((char*)hv_desc.arr, csTmp, hv_desc.len);
                ind_desc = 0;
DEBUGLOG(("Add:desc = [%.*s]\n",hv_desc.len, hv_desc.arr));
        }

        if(GetField_CString(hRls,"code",&csTmp)) {
                hv_code.len = strlen(csTmp);
                strncpy((char*)hv_code.arr, csTmp, hv_code.len);
                ind_code = 0;
DEBUGLOG(("Add:code = [%.*s]\n",hv_code.len, hv_code.arr));
        }

	if(GetField_Int(hRls, "code_in_num", &iTmp)) {
		hv_code_in_num = iTmp;
		ind_code_in_num= 0;
DEBUGLOG(("Add:code_in_num = [%d]\n",hv_code_in_num));
	}

        if(GetField_Int(hRls, "disabled", &iTmp)) {
                hv_disabled = iTmp;
                ind_disabled = 0;
DEBUGLOG(("Add:disabled = [%d]\n",hv_disabled));
        }

        if(GetField_CString(hRls,"create_user",&csTmp))
        {
                hv_create_user.len = strlen(csTmp);
                strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
                ind_create_user = 0;
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));
        }

	if(GetField_Char(hRls,"nature",&cTmp))
	{
		hv_nature = cTmp;
		ind_nature = 0;
DEBUGLOG(("Add:nature = [%c]\n",hv_nature));
	}

	if(GetField_Char(hRls,"bal_type",&cTmp)){
		hv_bal_type = cTmp;
		ind_bal_type = 0;
DEBUGLOG(("Add:bal_type = [%c]\n",hv_bal_type));
	}
	else{
		if(hv_party_type == PD_TYPE_MERCHANT){
			hv_bal_type = PD_MERCH_AVA_SETT_POOL;
			ind_bal_type = 0;
DEBUGLOG(("Add:bal_type = [%c](default)\n",hv_bal_type));
		}
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_adjustment_type_insert(
						:hv_party_type:ind_party_type,
						:hv_code:ind_code,
						:hv_code_in_num:ind_code_in_num,
						:hv_dc_ind:ind_dc_ind,
						:hv_desc:ind_desc,
						:hv_disabled:ind_disabled,
						:hv_create_user:ind_create_user,
						:hv_nature:ind_nature,
						:hv_bal_type:ind_bal_type); 
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_adjustment_type_insert ( :h\
v_party_type:ind_party_type , :hv_code:ind_code , :hv_code_in_num:ind_code_in\
_num , :hv_dc_ind:ind_dc_ind , :hv_desc:ind_desc , :hv_disabled:ind_disabled \
, :hv_create_user:ind_create_user , :hv_nature:ind_nature , :hv_bal_type:ind_\
bal_type ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_party_type;
 sqlstm.sqhstl[1] = (unsigned long )1;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_party_type;
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
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_dc_ind;
 sqlstm.sqhstl[4] = (unsigned long )1;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_dc_ind;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_desc;
 sqlstm.sqhstl[5] = (unsigned long )52;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_desc;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_disabled;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[7] = (unsigned long )22;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_create_user;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_nature;
 sqlstm.sqhstl[8] = (unsigned long )1;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_nature;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_bal_type;
 sqlstm.sqhstl[9] = (unsigned long )1;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_bal_type;
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
DEBUGLOG(("Add:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("OLAdjustmentType_Add: SP_OTHER_ERR\n");
DEBUGLOG(("Add: SP_OTHER_ERR\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("OLAdjustmentType_Add: SP_ERR\n");
DEBUGLOG(("Add: SP_ERR\n"));
                return PD_ERR;
        }


add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLAdjustmentType_Add: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;


}

int	GetAdjustmentTypeRec(const char cPartyType, 
				const char *csCode ,
				recordset_t *myRec)
{
	int 	iCnt = 0;
	hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getadjustmenttype_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		char		hv_party_type;
		/* varchar		hv_code[PD_ADJ_TYPE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_code;

		/*int		hv_disabled;*/

		char		v_dc_ind;
		/* varchar		v_desc[PD_ADJ_TYPE_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_desc;

		int		v_disabled;
		int		v_allow_modify;
		int		v_allow_bal_neg;
		char		v_bal_type;

		short		ind_dc_ind = -1;
		short		ind_desc = -1;
		short		ind_disabled = -1;
		short		ind_allow_modify = -1;
		short		ind_allow_bal_neg = -1;
		short		ind_bal_type = -1;


        /* EXEC SQL END DECLARE SECTION; */ 


	hv_party_type = cPartyType;
DEBUGLOG(("GetAdjustmentTypeRec party_type = [%.c]\n", hv_party_type));

        hv_code.len = strlen(csCode);
        memcpy(hv_code.arr,csCode,hv_code.len);
DEBUGLOG(("GetAdjustmentTypeRec code = [%.*s]\n",hv_code.len,hv_code.arr));


	/*hv_disabled = 0;*/


        /* EXEC SQL DECLARE c_cursor_getadjtype CURSOR FOR
		select oat_dc_ind,
		       oat_desc,
	               oat_disabled,
		       oat_allow_modify,
		       oat_allow_bal_negative,
		       oat_bal_type
		  from ol_adjustment_type
		 where oat_party_type = :hv_party_type
		   and oat_code = :hv_code; */ 

		   /*and oat_disabled = :hv_disabled;*/

        /* EXEC SQL OPEN c_cursor_getadjtype; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0003;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )128;
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
        if (sqlca.sqlcode < 0) goto getadjustmenttype_error;
}


        do {
		/* EXEC SQL FETCH c_cursor_getadjtype
		INTO	:v_dc_ind:ind_dc_ind,
			:v_desc:ind_desc,
			:v_disabled:ind_disabled,
			:v_allow_modify:ind_allow_modify,
			:v_allow_bal_neg:ind_allow_bal_neg,
			:v_bal_type:ind_bal_type; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 10;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )151;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_dc_ind;
  sqlstm.sqhstl[0] = (unsigned long )1;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_dc_ind;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_desc;
  sqlstm.sqhstl[1] = (unsigned long )53;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_desc;
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
  sqlstm.sqhstv[3] = (unsigned char  *)&v_allow_modify;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_allow_modify;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_allow_bal_neg;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_allow_bal_neg;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_bal_type;
  sqlstm.sqhstl[5] = (unsigned long )1;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_bal_type;
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
  if (sqlca.sqlcode < 0) goto getadjustmenttype_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}	

		iCnt++;

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

/* dc_ind */
		if (ind_dc_ind >= 0) {
			PutField_Char(myHash, "dc_ind", v_dc_ind);
DEBUGLOG(("GetAdjustmentTypeRec dc_ind = [%c]\n",v_dc_ind));
		}

/* desc */	
		if (ind_desc >= 0) {
			v_desc.arr[v_desc.len] = '\0';
			PutField_CString(myHash, "desc", (const char *)v_desc.arr);
DEBUGLOG(("GetAdjustmentTypeRec desc = [%s]\n",v_desc.arr));

		}

/* disabled */
		if (ind_disabled >= 0) {
			PutField_Int(myHash, "disabled", v_disabled);
DEBUGLOG(("GetAdjustmentTypeRec disabled = [%d]\n", v_disabled));

		}

/* allow_modify */
		if (ind_allow_modify >= 0) {
			PutField_Int(myHash, "allow_modify", v_allow_modify);
DEBUGLOG(("GetAdjustmentTypeRec allow_modify = [%d]\n", v_allow_modify));
		}

/* allow_bal_neg*/
		if (ind_allow_bal_neg >= 0) {
			PutField_Int(myHash, "allow_bal_neg", v_allow_bal_neg);
DEBUGLOG(("GetAdjustmentTypeRec allow_bal_neg = [%d]\n", v_allow_bal_neg));
		}
	
/* bal_type */
		if (ind_bal_type >= 0) {
			PutField_Char(myHash, "bal_type", v_bal_type);
DEBUGLOG(("GetAdjustmentTypeRec bal_type = [%c]\n",v_bal_type));
		}

		RecordSet_Add(myRec, myHash);
	}
	while (PD_TRUE);
	/* EXEC SQL CLOSE c_cursor_getadjtype; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )190;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getadjustmenttype_error;
}



        if (iCnt > 0 ) {
DEBUGLOG(("GetAdjustmentTypeRec Normal Exit\n"));
                return  PD_OK;
        }
        else {
DEBUGLOG(("GetAdjustmentTypeRec Normal Exit, Not Found\n"));
                return PD_ERR;
        }


getadjustmenttype_error:
DEBUGLOG(("getadjustmenttype_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getadjtype; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )205;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;

}


int Update(const hash_t *hRls)
{

	char	cTmp;
	char	*csTmp;
	int	iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO update_adjtype_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		char	hv_party_type;
		/* varchar	hv_code[PD_ADJ_TYPE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_code;

		char    hv_dc_ind;
		/* varchar	hv_desc[PD_ADJ_TYPE_DESC_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_desc;

		/* varchar hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;

		int	hv_disabled;
		char	hv_bal_type;

		short	ind_party_type = -1;
		short	ind_code = -1;
		short	ind_dc_ind = -1;
		short	ind_desc = -1;
		short	ind_update_user = -1;
		short	ind_disabled = -1;
		short	ind_bal_type = -1;

		short   hv_return_value;
		
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update Adj Type: Begin\n"));

	if (GetField_Char(hRls, "party_type", &cTmp)) {
		hv_party_type = cTmp;
		ind_party_type = 0;
DEBUGLOG(("Update Adj Type:party_type = [%c]\n",hv_party_type));
	}

	if (GetField_CString(hRls,"code",&csTmp)) {
		hv_code.len = strlen((const char*)csTmp);
		memcpy(hv_code.arr, csTmp, hv_code.len);
		ind_code = 0;
	}
DEBUGLOG(("Update Adj Type:code = [%.*s]\n",hv_code.len, hv_code.arr));

	if (GetField_Char(hRls, "dc_ind", &cTmp)) {
		hv_dc_ind = cTmp;
		ind_dc_ind = 0;
DEBUGLOG(("Update Adj Type:dc_ind = [%c]\n",hv_dc_ind));
	}

        if (GetField_CString(hRls,"desc",&csTmp)) {
		hv_desc.len = strlen((const char*)csTmp);
		memcpy(hv_desc.arr, csTmp, hv_desc.len);
		ind_desc = 0;
DEBUGLOG(("Update Adj Type: desc = [%.*s]\n",hv_desc.len, hv_desc.arr));
        }

        if (GetField_Int(hRls,"disabled",&iTmp)) {
		hv_disabled = iTmp;
		ind_disabled = 0;
DEBUGLOG(("Update Adj Type: disabled = [%d]\n", hv_disabled));
        }

	if(GetField_Char(hRls,"bal_type",&cTmp)){
		hv_bal_type = cTmp;
		ind_bal_type = 0;
DEBUGLOG(("Update Adj Type: bal_type = [%c]\n",hv_bal_type));
	}

/*update_user*/
        if(GetField_CString(hRls,"update_user",&csTmp)){
		hv_update_user.len = strlen((const char *)csTmp);
		memcpy(hv_update_user.arr, csTmp, hv_update_user.len);
		ind_update_user = 0;
DEBUGLOG(("Update:Adj Type: update_user = [%.*s]\n",hv_update_user.len, hv_update_user.arr));
        }


	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_adjustment_type_update(
						:hv_party_type:ind_party_type,
						:hv_code:ind_code,
						:hv_dc_ind:ind_dc_ind,
						:hv_desc:ind_desc,
						:hv_disabled:ind_disabled,
						:hv_update_user:ind_update_user,
						:hv_bal_type:ind_bal_type);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_adjustment_type_update ( :h\
v_party_type:ind_party_type , :hv_code:ind_code , :hv_dc_ind:ind_dc_ind , :hv\
_desc:ind_desc , :hv_disabled:ind_disabled , :hv_update_user:ind_update_user \
, :hv_bal_type:ind_bal_type ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )220;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_code;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_code;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_dc_ind;
 sqlstm.sqhstl[3] = (unsigned long )1;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_dc_ind;
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
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_disabled;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_update_user;
 sqlstm.sqhstl[6] = (unsigned long )22;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_update_user;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_bal_type;
 sqlstm.sqhstl[7] = (unsigned long )1;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_bal_type;
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
 if (sqlca.sqlcode < 0) goto update_adjtype_error;
}




	if (hv_return_value == SP_OK) {
DEBUGLOG(("Update Adj Type Normal Exit\n"));
		return 	PD_OK;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLAdjustmentType_Update: SP_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLAdjustmentType_Update: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}


update_adjtype_error:
DEBUGLOG(("update_adjtype_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLAdjustmentType_Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;
}

int Delete (const hash_t *hRls)
{
	char	cTmp;
	char	*csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO delete_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		char	hv_party_type;
		/* varchar	hv_code[PD_ADJ_TYPE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_code;


		short   hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Delete: Begin\n"));

	if(GetField_Char(hRls,"party_type",&cTmp)) {
		hv_party_type = cTmp;
        }
DEBUGLOG(("Delete:party_type = [%c]\n",hv_party_type));


        if(GetField_CString(hRls,"code",&csTmp)) {
		hv_code.len = strlen((const char*)csTmp);
		memcpy(hv_code.arr, csTmp, hv_code.len);
        }
DEBUGLOG(("Delete:code = [%.*s]\n",hv_code.len,hv_code.arr));

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_adjustment_type_delete(	
						:hv_party_type,
						:hv_code
						);

		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_adjustment_type_delete ( :h\
v_party_type , :hv_code ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )267;
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
                ERRLOG("OLAdjustmentType_Delete: SP_OTHER_ERR TxnAbort\n");
                DEBUGLOG(("Delete: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
                ERRLOG("OLAdjustmentType_Delete: SP_ERR TxnAbort\n");
                DEBUGLOG(("Delete: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

delete_error:
DEBUGLOG(("delete_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLAdjustmentType_Delete: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;	

}

