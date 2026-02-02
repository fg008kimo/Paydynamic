
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
    "RuleAmount.pc"
};


static unsigned int sqlctx = 659707;


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

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,279,0,6,136,0,0,10,10,0,1,0,2,3,0,0,1,1,0,0,1,4,0,0,1,4,0,0,1,9,0,0,1,
3,0,0,1,4,0,0,1,4,0,0,1,9,0,0,2,3,0,0,
60,0,0,2,0,0,17,275,0,0,1,1,0,1,0,1,9,0,0,
79,0,0,2,0,0,21,276,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/12/12		   Stan Poon
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "RuleAmount.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char	cDebug;
void RuleAmount(char	cdebug){

	cDebug = cdebug;
}

int Add(const hash_t *hRls,
	int *iAmtId)
{

DEBUGLOG(("Add Begins\n"));

	int	iTmp = 0;
	double	dTmp = 0.0;
	char	cTmp;
	char*	csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		
		char		hv_type;
		double		hv_value;
		double		hv_add_value;
		/* varchar		hv_desc[PD_DESC_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_desc;

		int		hv_disabled;
		double		hv_min_value;
		double		hv_max_value;
		/* varchar	 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_type = -1;
		short		ind_value = -1;
		short		ind_add_value = -1;
		short		ind_desc = -1;
		short		ind_disabled = -1;
		short		ind_min_value = -1;
		short		ind_max_value = -1;
		short		ind_create_user = -1;

		int		v_id = -1;

		short		hv_return_value = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	
	if (GetField_Char(hRls,"type",&cTmp)) {
		hv_type = cTmp;
		ind_type = 0;
DEBUGLOG(("Add type [%c]\n",cTmp));
	}else {
DEBUGLOG(("Add type [%c]\n",cTmp));
	}

	if (GetField_Double(hRls,"value",&dTmp)) {
		hv_value = dTmp;
		ind_value = 0;
DEBUGLOG(("Add value [%f]\n",dTmp));
	}else {
DEBUGLOG(("Add value [%f]\n",dTmp));
	}
	
	if (GetField_Double(hRls,"add_value",&dTmp)) {
		hv_add_value = dTmp;
		ind_add_value = 0;
DEBUGLOG(("Add add_value [%f]\n",dTmp));
	}else {
DEBUGLOG(("Add add_value [%f]\n",dTmp));
	}
	
	if (GetField_CString(hRls,"desc",&csTmp)) {
		hv_desc.len = strlen(csTmp);
		memcpy(hv_desc.arr, csTmp, hv_desc.len);
DEBUGLOG(("Add desc = [%.*s]\n",hv_desc.len,hv_desc.arr));
		ind_desc = 0;
	}else {
DEBUGLOG(("Add desc [%s]\n",csTmp));
	}
	
	if (GetField_Int(hRls,"disabled",&iTmp)) {
		hv_disabled = iTmp;
		ind_disabled = 0;
DEBUGLOG(("Add disabled [%d]\n",iTmp));
	}else {
DEBUGLOG(("Add disabled [%d]\n",iTmp));
	}
	
	if (GetField_Double(hRls,"min_value",&dTmp)) {
		hv_min_value = dTmp;
		ind_min_value = 0;
DEBUGLOG(("Add min_value [%f]\n",dTmp));
	}else {
DEBUGLOG(("Add min_value [%f]\n",dTmp));
	}
	
	if (GetField_Double(hRls,"max_value",&dTmp)) {
		hv_max_value = dTmp;
		ind_max_value = 0;
DEBUGLOG(("Add max_value [%f]\n",dTmp));
	}else {
DEBUGLOG(("Add max_value [%f]\n",dTmp));
	}

	if (GetField_CString(hRls,"create_user",&csTmp)) {
		hv_create_user.len = strlen(csTmp);
		memcpy(hv_create_user.arr,csTmp,hv_create_user.len);
DEBUGLOG(("Add create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));
		ind_create_user = 0;
	}else {
DEBUGLOG(("Add create_user [%s]\n",csTmp));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_rule_amount_insert(:hv_type:ind_type,
								:hv_value:ind_value,
								:hv_add_value:ind_add_value,
								:hv_desc:ind_desc,
								:hv_disabled:ind_disabled,
								:hv_min_value:ind_min_value,
								:hv_max_value:ind_max_value,
								:hv_create_user:ind_create_user,
								:v_id);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_rule_amount_insert ( :hv_type:\
ind_type , :hv_value:ind_value , :hv_add_value:ind_add_value , :hv_desc:ind_d\
esc , :hv_disabled:ind_disabled , :hv_min_value:ind_min_value , :hv_max_value\
:ind_max_value , :hv_create_user:ind_create_user , :v_id ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_type;
 sqlstm.sqhstl[1] = (unsigned long )1;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_type;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_value;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_value;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_add_value;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_add_value;
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
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_min_value;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_min_value;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_max_value;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_max_value;
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
 sqlstm.sqhstv[9] = (unsigned char  *)&v_id;
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



	if (hv_return_value == 0) {
		*iAmtId = v_id;
DEBUGLOG(("Add Success\n"));
DEBUGLOG(("Add *iAmtId = [%i]\n",*iAmtId));
		return PD_OK;
	}
	else {
DEBUGLOG(("Add Fail\n"));
		return PD_ERR;
	}


add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("RuleAmount_Add: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int Update(const hash_t *hRls)
{
	char	cTmp;
	int	iTmp;
	double	dTmp;
	char*	csBuf = (char*)malloc(128);
	
	/* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		
		/* varchar		hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
	strcpy((char*)hv_dynstmt.arr,"update rule_amount set ra_update_timestamp = sysdate");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

/*type*/
	if (GetField_Char(hRls,"type",&cTmp)) {
DEBUGLOG(("Update:type = [%c]\n",cTmp));
		sprintf(csBuf,"%c",cTmp);
		strcat((char*)hv_dynstmt.arr, ",ra_type = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/*add_value*/
	if (GetField_Int(hRls,"add_value",&iTmp)) {
DEBUGLOG(("Update:add_value = [%d]\n",iTmp));
		sprintf(csBuf,"%d",iTmp);
		strcat((char*)hv_dynstmt.arr, ",ra_add_value = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/*value*/
	if (GetField_Double(hRls,"value",&dTmp)) {
DEBUGLOG(("Update:value = [%f]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",ra_value = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
}

/*desc*/
	if (GetField_CString(hRls,"desc",&csBuf)) {
DEBUGLOG(("Update:desc = [%s]\n",csBuf));
		strcat((char*)hv_dynstmt.arr, ",ra_desc= '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}	

/*disabled*/
	if (GetField_Int(hRls,"disabled",&iTmp)) {
DEBUGLOG(("Update:disabled = [%d]\n",iTmp));
		sprintf(csBuf,"%d",iTmp);
		strcat((char*)hv_dynstmt.arr, ",ra_disabled = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/*min_value*/
	if (GetField_Double(hRls,"min_value",&dTmp)) {
DEBUGLOG(("Update:disabled = [%f]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",ra_min_value = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/*max_value*/
	if (GetField_Double(hRls,"max_value",&dTmp)) {
DEBUGLOG(("Update:disabled = [%f]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",ra_max_value = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/*update_user*/
	if (GetField_CString(hRls,"update_user",&csBuf)) {
DEBUGLOG(("Update:update_user = [%s]\n",csBuf));
		strcat((char*)hv_dynstmt.arr, ",ra_update_user= '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}	

	if (GetField_Int(hRls,"id",&iTmp)) {
		sprintf(csBuf, "%d", iTmp);
		strcat((char *)hv_dynstmt.arr, " WHERE ra_id = ");
		strcat((char *)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
	}else {
DEBUGLOG(("RA_ID not found!!!"));
		return PD_ERR;
	}
	
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
ERRLOG("RuleAmount_Update: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}
