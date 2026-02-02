
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
    "RuleAutoSettlement.pc"
};


static unsigned int sqlctx = 169231227;


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
   unsigned char  *sqhstv[8];
   unsigned long  sqhstl[8];
            int   sqhsts[8];
            short *sqindv[8];
            int   sqinds[8];
   unsigned long  sqharm[8];
   unsigned long  *sqharc[8];
   unsigned short  sqadto[8];
   unsigned short  sqtdso[8];
} sqlstm = {12,8};

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
5,0,0,1,272,0,6,119,0,0,8,8,0,1,0,2,3,0,0,1,3,0,0,1,1,0,0,1,9,0,0,1,4,0,0,1,9,
0,0,1,3,0,0,1,9,0,0,
52,0,0,2,0,0,17,263,0,0,1,1,0,1,0,1,9,0,0,
71,0,0,2,0,0,21,264,0,0,0,0,0,1,0,
86,0,0,3,90,0,4,303,0,0,3,2,0,1,0,2,3,0,0,1,3,0,0,1,1,0,0,
113,0,0,4,91,0,4,307,0,0,3,2,0,1,0,2,3,0,0,1,3,0,0,1,1,0,0,
140,0,0,0,0,0,56,399,0,0,1,1,0,1,0,3,102,0,0,
159,0,0,5,240,0,6,400,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
3,0,0,2,102,0,0,
202,0,0,0,0,0,13,424,0,0,6,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,1,0,0,2,
1,0,0,
241,0,0,0,0,0,15,465,0,0,1,1,0,1,0,1,102,0,0,
260,0,0,0,0,0,78,466,0,0,1,1,0,1,0,3,102,0,0,
279,0,0,0,0,0,15,471,0,0,1,1,0,1,0,1,102,0,0,
298,0,0,0,0,0,78,472,0,0,1,1,0,1,0,3,102,0,0,
317,0,0,0,0,0,15,478,0,0,1,1,0,1,0,1,102,0,0,
336,0,0,0,0,0,78,479,0,0,1,1,0,1,0,3,102,0,0,
355,0,0,0,0,0,15,486,0,0,1,1,0,1,0,1,102,0,0,
374,0,0,0,0,0,78,487,0,0,1,1,0,1,0,3,102,0,0,
};


/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/11/06              LokMan Chow
Add FindRule                                       2013/05/30              Stan Poon
Add GetRulesDetail				   2013/06/03		   LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "RuleAutoSettlement.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;
void RuleAutoSettlement(char    cdebug)
{
	cDebug = cdebug;
}

int Add(hash_t *hRls)
{
	char	*csTmp;
	char	cTmp;
	int	iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int		hv_sett_id;
		char		hv_sett_type;
		/* varchar		hv_sett_value[PD_SETT_VALUE_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_sett_value;

		double		hv_sett_min_amount;
		/* varchar		hv_desc[PD_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_desc;

		int		hv_disabled;
		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_sett_id = -1;
		short		ind_sett_type = -1;
		short		ind_sett_value = -1;
		short		ind_sett_min_amount = -1;
		short		ind_desc = -1;
		short		ind_disabled = -1;
		short		ind_create_user = -1;

		short		hv_return_value;

	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("Add: Begin\n"));

	if (GetField_Int(hRls, "auto_sett_id", &iTmp))
	{
		hv_sett_id = iTmp;
		ind_sett_id = 0;
DEBUGLOG(("Add:auto_sett_id = [%d]\n",hv_sett_id));
	}


	if (GetField_Char(hRls,"sett_type", &cTmp))
	{
		hv_sett_type = cTmp;
		ind_sett_type = 0;
DEBUGLOG(("Add:sett_type = [%c]\n",hv_sett_type));
	}

	if(GetField_CString(hRls,"sett_value",&csTmp))
	{
		hv_sett_value.len = strlen(csTmp);
		strncpy((char *)hv_sett_value.arr, csTmp, hv_sett_value.len);
		ind_sett_value = 0;
DEBUGLOG(("Add:sett_value = [%.*s]\n",hv_sett_value.len,hv_sett_value.arr));
	}

	if (GetField_CString(hRls, "sett_min_amount", &csTmp))
	{
		if (strlen(csTmp) > 0) {
			hv_sett_min_amount = atof(csTmp);
DEBUGLOG(("Add:sett_min_amount = [%lf]\n",hv_sett_min_amount));
			ind_sett_min_amount = 0;
		}
	}

	if(GetField_CString(hRls,"desc",&csTmp))
	{
		hv_desc.len = strlen(csTmp);
		strncpy((char *)hv_desc.arr, csTmp, hv_desc.len);
		ind_desc = 0;
DEBUGLOG(("Add:desc = [%.*s]\n",hv_desc.len,hv_desc.arr));
	}

	if (GetField_Int(hRls, "disabled", &iTmp))
	{
		hv_disabled = iTmp;
		ind_disabled = 0;
DEBUGLOG(("Add:disabled = [%d]\n",hv_disabled));
	}

	if(GetField_CString(hRls,"create_user",&csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char *)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));
	}

	/* EXEC SQL EXECUTE
	    BEGIN
		:hv_return_value := sp_rule_auto_sett_insert(
				:hv_sett_id:ind_sett_id,
				:hv_sett_type:ind_sett_type,
				:hv_sett_value:ind_sett_value,
				:hv_sett_min_amount:ind_sett_min_amount,
				:hv_desc:ind_desc,
				:hv_disabled:ind_disabled,
				:hv_create_user:ind_create_user);
	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_rule_auto_sett_insert ( :hv_se\
tt_id:ind_sett_id , :hv_sett_type:ind_sett_type , :hv_sett_value:ind_sett_val\
ue , :hv_sett_min_amount:ind_sett_min_amount , :hv_desc:ind_desc , :hv_disabl\
ed:ind_disabled , :hv_create_user:ind_create_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_sett_id;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_sett_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_sett_type;
 sqlstm.sqhstl[2] = (unsigned long )1;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_sett_type;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_sett_value;
 sqlstm.sqhstl[3] = (unsigned long )22;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_sett_value;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_sett_min_amount;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_sett_min_amount;
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
	if (hv_return_value == SP_OK) {
DEBUGLOG(("Add:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("RuleAutoSettlement_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("RuleAutoSettlement_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int Update(const hash_t *hRls, char cDefType, int isDefType)
{
	char*	csTmp;
	char*	csBuf;
	char*	csRuleId;
	double	dTmp;
	int	iTmp;
	char	cTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));

	csBuf = (char*) malloc (128);
	csRuleId = (char*) malloc (128);

	strcpy((char*)hv_dynstmt.arr,"update rule_auto_settlement set rs_update_timestamp  = sysdate");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

/* auto_sett_id */
	if (GetField_Int(hRls, "auto_sett_id", &iTmp)) {
		sprintf(csRuleId, "%d", iTmp);
DEBUGLOG(("Update:auto_sett_id = [%d]\n",iTmp));
	}

/* sett_type */
	if (GetField_Char(hRls, "sett_type", &cTmp)) {
DEBUGLOG(("Update:sett_type = [%c]\n",cTmp));
		sprintf(csBuf, "%c", cTmp);
		strcat((char*)hv_dynstmt.arr, ", rs_type = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* sett_value */
	if (GetField_CString(hRls, "sett_value", &csTmp)) {
DEBUGLOG(("Update:sett_value = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",rs_value = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* sett_min_amount*/
	if (GetField_CString(hRls,"sett_min_amount",&csTmp)) {
		dTmp = atof(csTmp);
DEBUGLOG(("Update:sett_min_amount = [%f]\n",dTmp));
		strcat((char*)hv_dynstmt.arr, ",rs_min_amount = ");
		if (strlen(csTmp) > 0) {
			strcat((char*)hv_dynstmt.arr, csTmp);
		} else {
			strcat((char*)hv_dynstmt.arr, "NULL");
		}

		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* desc */
	if (GetField_CString(hRls, "desc", &csTmp)) {
DEBUGLOG(("Update:desc = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",rs_desc = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* disabled */
	if (GetField_Int(hRls, "disabled", &iTmp)) {
DEBUGLOG(("Update:disabled = [%d]\n",iTmp));
		sprintf(csTmp,"%d",iTmp);
		strcat((char*)hv_dynstmt.arr, ",rs_disabled = ");
		strcat((char*)hv_dynstmt.arr, csTmp);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/*update_user*/
	if(GetField_CString(hRls,"update_user",&csTmp)){
DEBUGLOG(("Update:update_user = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ", rs_update_user= '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	strcat((char *)hv_dynstmt.arr, " WHERE rs_id = ");
	strcat((char *)hv_dynstmt.arr, csRuleId);
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	if (isDefType == 1) strcat((char *)hv_dynstmt.arr, " AND rs_type = '");
	else strcat((char *)hv_dynstmt.arr, " AND rs_type <> '");
	sprintf(csBuf, "%c", cDefType);
	strcat((char *)hv_dynstmt.arr, csBuf);
	strcat((char*)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )52;
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
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )71;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto update_error;
}



	FREE_ME(csBuf);
	FREE_ME(csRuleId);

DEBUGLOG(("Update Normal Exit\n"));
	return PD_OK;

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("RuleAutoSettlement_Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
	return PD_INTERNAL_ERR;

}

int FindRule(int iAutoSettId, char cType, int isType)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO findrule_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 
	

	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		int	v_count;

		int	hv_id;
		char	hv_type;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_id = iAutoSettId;
DEBUGLOG(("FindRule auto_sett_id = [%d]\n",iAutoSettId));

	hv_type = cType;
DEBUGLOG(("FindRule rule type = [%c]\n",cType));

	if (isType == 1) {
		/* EXEC SQL SELECT COUNT(*) INTO :v_count
			FROM rule_auto_settlement
			WHERE rs_id = :hv_id and rs_type = :hv_type; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 8;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select COUNT ( * ) INTO :b0 FROM rule_auto_settlement WHER\
E rs_id = :b1 and rs_type = :b2 ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )86;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_count;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_id;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_type;
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
  if (sqlca.sqlcode < 0) goto findrule_error;
}


	} else if (isType == 0){
		/* EXEC SQL SELECT COUNT(*) INTO :v_count
			FROM rule_auto_settlement
			WHERE rs_id = :hv_id and rs_type <> :hv_type; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 8;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select COUNT ( * ) INTO :b0 FROM rule_auto_settlement WHER\
E rs_id = :b1 and rs_type <> :b2 ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )113;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_count;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_id;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_type;
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
  if (sqlca.sqlcode < 0) goto findrule_error;
}


	}

	if (v_count <= 0) {
		return PD_NOT_FOUND;
	}

	return PD_FOUND;

findrule_error:
DEBUGLOG(("findrule code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int GetRulesDetail(hash_t* hTxn, recordset_t *myRec)
{
	int	iRet = PD_OK;
	hash_t	*myHash;
	char	*csTmp;
	int	iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO getdetail_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 
	

	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar hv_currency_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_currency_id;

		/* varchar hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

		int	hv_settle_id;

		/* varchar	v_last_sett_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_last_sett_date;

		/* varchar	v_sett_value[PD_SETT_VALUE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_sett_value;

		double	v_min_amt;
		char	v_rule_type;
		char	v_status;
		
		short	ind_service_code = -1;
		short	ind_merchant_id = -1;
		short	ind_currency_id = -1;
		short	ind_country = -1;
		short	ind_settle_id = -1;
		short	ind_last_sett_date = -1;
		short	ind_sett_value = -1;
		short	ind_min_amt = -1;
		short	ind_rule_type = -1;
		short	ind_status = -1;

		short   hv_return_value;
		SQL_CURSOR      c_cursor_getdetail;

	/* EXEC SQL END DECLARE SECTION; */ 


	if(GetField_CString(hTxn,"merchant_id",&csTmp)){
		hv_merchant_id.len = strlen(csTmp);
		memcpy(hv_merchant_id.arr,csTmp,hv_merchant_id.len);
		ind_merchant_id = 0;
DEBUGLOG(("GetRulesDetail merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        }

	if(GetField_CString(hTxn,"service_code",&csTmp)){
		hv_service_code.len = strlen(csTmp);
		memcpy(hv_service_code.arr,csTmp,hv_service_code.len);
		ind_service_code = 0;
DEBUGLOG(("GetRulesDetail service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));
        }

	if(GetField_CString(hTxn,"txn_ccy",&csTmp)){
		hv_currency_id.len = strlen(csTmp);
		memcpy(hv_currency_id.arr,csTmp,hv_currency_id.len);
		ind_currency_id = 0;
DEBUGLOG(("GetRulesDetail txn_ccy = [%.*s]\n",hv_currency_id.len,hv_currency_id.arr));
        }

	if(GetField_CString(hTxn,"txn_country",&csTmp)){
		hv_country.len = strlen(csTmp);
		memcpy(hv_country.arr,csTmp,hv_country.len);
		ind_country = 0;
DEBUGLOG(("GetRulesDetail country = [%.*s]\n",hv_country.len,hv_country.arr));
        }

	if(GetField_Int(hTxn,"settle_id",&iTmp)){
		hv_settle_id = iTmp;
		ind_settle_id= 0;
DEBUGLOG(("GetRulesDetail settle_id = [%d]\n",hv_settle_id));
        }

	/* EXEC SQL ALLOCATE       :c_cursor_getdetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )140;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getdetail;
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
 if (sqlca.sqlcode < 0) goto getdetail_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_auto_settle_rule_dt(:hv_merchant_id:ind_merchant_id,
								:hv_service_code:ind_service_code,
								:hv_country:ind_country,
								:hv_currency_id:ind_currency_id,
								:hv_settle_id:ind_settle_id,
								:c_cursor_getdetail);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_auto_settle_rule_dt ( :\
hv_merchant_id:ind_merchant_id , :hv_service_code:ind_service_code , :hv_coun\
try:ind_country , :hv_currency_id:ind_currency_id , :hv_settle_id:ind_settle_\
id , :c_cursor_getdetail ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )159;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[1] = (unsigned long )17;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_service_code;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_country;
        sqlstm.sqhstl[3] = (unsigned long )4;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_country;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_currency_id;
        sqlstm.sqhstl[4] = (unsigned long )5;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_currency_id;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_settle_id;
        sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_settle_id;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&c_cursor_getdetail;
        sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)0;
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
        if (sqlca.sqlcode < 0) goto getdetail_error;
}



	if (hv_return_value > 0 ) {
DEBUGLOG(("GetRulesDetail: Found!\n"));
		for (;;) {
			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			ind_last_sett_date = -1;
			ind_sett_value = -1;
			ind_min_amt = -1;
			ind_rule_type = -1;
			ind_status = -1;

			/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_getdetail
                        INTO    :v_last_sett_date:ind_last_sett_date,
                                :v_sett_value:ind_sett_value,
                                :v_min_amt:ind_min_amt,
                                :v_rule_type:ind_rule_type,
                                :v_status:ind_status; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 8;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )202;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getdetail;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_last_sett_date;
                        sqlstm.sqhstl[1] = (unsigned long )11;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_last_sett_date;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_sett_value;
                        sqlstm.sqhstl[2] = (unsigned long )23;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_sett_value;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_min_amt;
                        sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_min_amt;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_rule_type;
                        sqlstm.sqhstl[4] = (unsigned long )1;
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_rule_type;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_status;
                        sqlstm.sqhstl[5] = (unsigned long )1;
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_status;
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
                        if (sqlca.sqlcode == 1403) break;
                        if (sqlca.sqlcode < 0) goto getdetail_error;
}



                        if (SQLCODE == SQL_NOT_FOUND) {
                                break;
                        }

			if(ind_last_sett_date>=0){
				v_last_sett_date.arr[v_last_sett_date.len] = '\0';
				PutField_CString(myHash,"last_sett_date",(const char*)v_last_sett_date.arr);
DEBUGLOG(("GetRulesDetail: last_sett_date = [%s]\n",v_last_sett_date.arr));
			}

			if(ind_sett_value>=0){
				v_sett_value.arr[v_sett_value.len] = '\0';
				PutField_CString(myHash,"sett_value",(const char*)v_sett_value.arr);
DEBUGLOG(("GetRulesDetail: sett_value = [%s]\n",v_sett_value.arr));
			}

			if(ind_rule_type>=0){
				PutField_Char(myHash,"rule_type",v_rule_type);
DEBUGLOG(("GetRulesDetail: rule_type = [%c]\n",v_rule_type));
			}

			if(ind_status>=0){
				PutField_Char(myHash,"status",v_status);
DEBUGLOG(("GetRulesDetail: status = [%c]\n",v_status));
			}

			if(ind_min_amt<0)
				v_min_amt = 0.0;
			PutField_Double(myHash,"sett_min_amount",v_min_amt);
DEBUGLOG(("GetRulesDetail: min_amt = [%lf]\n",v_min_amt));


			RecordSet_Add(myRec,myHash);
		}
		/* EXEC SQL CLOSE :c_cursor_getdetail; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 8;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )241;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getdetail;
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
  if (sqlca.sqlcode < 0) goto getdetail_error;
}


                /* EXEC SQL FREE :c_cursor_getdetail; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 8;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )260;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getdetail;
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
                if (sqlca.sqlcode < 0) goto getdetail_error;
}


DEBUGLOG(("GetRulesDetail: exit with ok\n"));
                return PD_OK;
        }
        else {
                /* EXEC SQL CLOSE :c_cursor_getdetail; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 8;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )279;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getdetail;
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
                if (sqlca.sqlcode < 0) goto getdetail_error;
}


                /* EXEC SQL FREE :c_cursor_getdetail; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 8;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )298;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getdetail;
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
                if (sqlca.sqlcode < 0) goto getdetail_error;
}


DEBUGLOG(("GetRulesDetail: exit with error\n"));
                return PD_ERR;
        }


        /* EXEC SQL CLOSE :c_cursor_getdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )317;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getdetail;
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
        if (sqlca.sqlcode < 0) goto getdetail_error;
}


        /* EXEC SQL FREE :c_cursor_getdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )336;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getdetail;
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
        if (sqlca.sqlcode < 0) goto getdetail_error;
}



	return iRet;

getdetail_error:
DEBUGLOG(("getdetail code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL CLOSE :c_cursor_getdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )355;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getdetail;
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
        if (sqlca.sqlcode < 0) goto getdetail_error;
}


        /* EXEC SQL FREE :c_cursor_getdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )374;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getdetail;
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
        if (sqlca.sqlcode < 0) goto getdetail_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}
