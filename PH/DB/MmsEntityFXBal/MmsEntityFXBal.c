
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
    "MmsEntityFXBal.pc"
};


static unsigned int sqlctx = 10145355;


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
5,0,0,1,231,0,6,116,0,0,8,8,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,4,
0,0,1,4,0,0,1,9,0,0,
52,0,0,2,0,0,17,245,0,0,1,1,0,1,0,1,9,0,0,
71,0,0,2,0,0,21,246,0,0,0,0,0,1,0,
86,0,0,3,158,0,4,329,0,0,6,4,0,1,0,2,4,0,0,2,4,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,
0,0,
125,0,0,4,169,0,4,442,0,0,6,4,0,1,0,2,4,0,0,2,4,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
3,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/04/29              Dirk Wong
Remove Ratio					   2015/07/29		   LokMan Chow
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
#include "MmsEntityFXBal.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char    cDebug;

void MmsEntityFXBal(char    cdebug)
{
        cDebug = cdebug;
}


int Add(const hash_t *hRls)
{
	char	*csTmp;
	int	iTmp;
	double	dTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_entity_id[PD_MMS_ENTITY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_entity_id;

		/* varchar		hv_org_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_org_ccy;

		/* varchar		hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

		int		hv_acr_ind;
		double		hv_bal;
		double		hv_rate;
		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_entity_id = -1;
		short		ind_org_ccy = -1;
		short		ind_ccy = -1;
		short		ind_acr_ind = -1;
		short		ind_bal = -1;
		short		ind_rate = -1;
		short		ind_create_user = -1;
	
		short		hv_return_value;	
		
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

        if(GetField_CString(hRls,"entity_id",&csTmp)) {
                hv_entity_id.len = strlen(csTmp);
                strncpy((char*)hv_entity_id.arr, csTmp, hv_entity_id.len);
                ind_entity_id = 0;
DEBUGLOG(("Add:entity_id = [%.*s]\n",hv_entity_id.len, hv_entity_id.arr));
	}

        if(GetField_CString(hRls,"org_ccy",&csTmp)) {
                hv_org_ccy.len = strlen(csTmp);
                strncpy((char*)hv_org_ccy.arr, csTmp, hv_org_ccy.len);
                ind_org_ccy = 0;
DEBUGLOG(("Add:org_ccy = [%.*s]\n",hv_org_ccy.len, hv_org_ccy.arr));
        }

        if(GetField_CString(hRls,"ccy",&csTmp)) {
                hv_ccy.len = strlen(csTmp);
                strncpy((char*)hv_ccy.arr, csTmp, hv_ccy.len);
                ind_ccy = 0;
DEBUGLOG(("Add:ccy = [%.*s]\n",hv_ccy.len, hv_ccy.arr));
        }

	if(GetField_Int(hRls, "acr_ind", &iTmp)) {
		hv_acr_ind = iTmp;
		ind_acr_ind = 0;
DEBUGLOG(("Add:acr_ind = [%d]\n",hv_acr_ind));
	}

        if(GetField_Double(hRls, "bal", &dTmp)) {
                hv_bal = dTmp;
                ind_bal = 0;
DEBUGLOG(("Add:bal = [%.2f]\n",hv_bal));
        }

        if(GetField_Double(hRls, "rate", &dTmp)) {
                hv_rate = dTmp;
                ind_rate = 0;
DEBUGLOG(("Add:rate = [%.5f]\n",hv_rate));
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
			:hv_return_value := sp_entity_fx_bal_insert(
								:hv_entity_id:ind_entity_id,
								:hv_org_ccy:ind_org_ccy,
								:hv_ccy:ind_ccy,
								:hv_acr_ind:ind_acr_ind,
								:hv_bal:ind_bal,
								:hv_rate:ind_rate,
								:hv_create_user:ind_create_user); 
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_entity_fx_bal_insert ( :hv_ent\
ity_id:ind_entity_id , :hv_org_ccy:ind_org_ccy , :hv_ccy:ind_ccy , :hv_acr_in\
d:ind_acr_ind , :hv_bal:ind_bal , :hv_rate:ind_rate , :hv_create_user:ind_cre\
ate_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_entity_id;
 sqlstm.sqhstl[1] = (unsigned long )22;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_entity_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_org_ccy;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_org_ccy;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_ccy;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_acr_ind;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_acr_ind;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_bal;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_bal;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_rate;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_rate;
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
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("Add:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MmsEntityFXBal_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("MmsEntityFXBal_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }


add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MmsEntityFXBal_Add: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int Update(const hash_t *hRls)
{
        char    *csBuf;
	char	*csTmp;
	int	iTmp;
	double	dTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar        hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
        csBuf = (char *)malloc(128);

        strcpy((char*)hv_dynstmt.arr,"update mms_entity_fx_bal set mfb_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

/*bal*/
        if (GetField_Double(hRls,"bal",&dTmp)) {
DEBUGLOG(("Update: bal = [%lf]\n",dTmp));
                sprintf(csBuf,"%lf",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mfb_bal = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*rate*/
        if (GetField_Double(hRls,"rate",&dTmp)) {
DEBUGLOG(("Update: rate = [%lf]\n",dTmp));
                sprintf(csBuf,"%lf",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mfb_rate = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*update_user*/
        if (GetField_CString(hRls,"update_user",&csTmp)) {
DEBUGLOG(("Update:update_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mfb_update_user = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*Primary Key: entity_id*/
        if (GetField_CString(hRls,"entity_id",&csTmp)) {
DEBUGLOG(("Update: entity_id = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, " WHERE mfb_entity_id = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
       		strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/*Primary Key: org_ccy*/
        if (GetField_CString(hRls,"org_ccy",&csTmp)) {
DEBUGLOG(("Update: org_ccy = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, " AND mfb_org_ccy = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
       		strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/*Primary Key: ccy*/
        if (GetField_CString(hRls,"ccy",&csTmp)) {
DEBUGLOG(("Update: ccy = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, " AND mfb_ccy = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
       		strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/*Primary Key: acr_ind*/
	if (GetField_Int(hRls,"acr_ind",&iTmp)) {
DEBUGLOG(("Update: acr_ind = [%d]\n", iTmp));
		sprintf(csBuf,"%d",iTmp);
		strcat((char*)hv_dynstmt.arr, " AND mfb_acr_ind = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

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
	
DEBUGLOG(("Update Normal Exit\n"));
        return PD_OK;

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("MmsEntityFXBal:Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
        return PD_INTERNAL_ERR;
}

int GetFxBal(const hash_t *hRls, hash_t *myHash)
{
	int iRet = PD_OK;

	char*   csTmp;
	int	iTmp;
	int     iCnt = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO getfxbal_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	/* varchar	hv_entity_id[PD_MMS_ENTITY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_entity_id;

	/* varchar	hv_org_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_org_ccy;

	/* varchar	hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

	int	hv_acr_ind;

	double	v_bal;
	double	v_rate;

	short	ind_bal = -1;
	short	ind_rate = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls, "entity_id", &csTmp)) {
		hv_entity_id.len = strlen(csTmp);
		memcpy(hv_entity_id.arr, csTmp, hv_entity_id.len);
DEBUGLOG(("GetFXBal: entity_id = [%.*s]\n", hv_entity_id.len, hv_entity_id.arr));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("GetFXBal: entity_id NOT FOUND!\n"));
ERRLOG("MmsEntityFXBal::GetFXBal entity_id NOT FOUND!\n");
	}

	if (GetField_CString(hRls, "org_ccy", &csTmp)) {
		hv_org_ccy.len = strlen(csTmp);
		memcpy(hv_org_ccy.arr, csTmp, hv_org_ccy.len);
DEBUGLOG(("GetFXBal: org_ccy = [%.*s]\n", hv_org_ccy.len, hv_org_ccy.arr));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("GetFXBal: org_ccy NOT FOUND!\n"));
ERRLOG("MmsEntityFXBal::GetFXBal org_ccy NOT FOUND!\n");
	}

	if (GetField_CString(hRls, "ccy", &csTmp)) {
		hv_ccy.len = strlen(csTmp);
		memcpy(hv_ccy.arr, csTmp, hv_ccy.len);
DEBUGLOG(("GetFXBal: ccy = [%.*s]\n", hv_ccy.len, hv_ccy.arr));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("GetFXBal: ccy NOT FOUND!\n"));
ERRLOG("MmsEntityFXBal::GetFXBal ccy NOT FOUND!\n");
	}

	if (GetField_Int(hRls, "acr_ind", &iTmp)) {
		hv_acr_ind = iTmp;
DEBUGLOG(("GetFXBal: acr_ind = [%d]\n", hv_acr_ind));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("GetFXBal: acr_ind NOT FOUND!\n"));
ERRLOG("MmsEntityFXBal::GetFXBal acr_ind NOT FOUND!\n");
	}


	if (iRet == PD_OK) {
		/* EXEC SQL 
			SELECT	MFB_BAL,
				MFB_RATE
			INTO	:v_bal:ind_bal,
				:v_rate:ind_rate
			FROM	MMS_ENTITY_FX_BAL
			WHERE	MFB_ENTITY_ID = :hv_entity_id
			  AND	MFB_ORG_CCY = :hv_org_ccy
			  AND	MFB_CCY = :hv_ccy
			  AND	MFB_ACR_IND = :hv_acr_ind; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 8;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select MFB_BAL , MFB_RATE INTO :b0:b1 , :b2:b3 FROM MMS_EN\
TITY_FX_BAL WHERE MFB_ENTITY_ID = :b4 AND MFB_ORG_CCY = :b5 AND MFB_CCY = :b6\
 AND MFB_ACR_IND = :b7 ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )86;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_bal;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_bal;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_rate;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_rate;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_entity_id;
  sqlstm.sqhstl[2] = (unsigned long )22;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&hv_org_ccy;
  sqlstm.sqhstl[3] = (unsigned long )5;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&hv_ccy;
  sqlstm.sqhstl[4] = (unsigned long )5;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&hv_acr_ind;
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
  if (sqlca.sqlcode < 0) goto getfxbal_error;
}




		if (ind_bal >= 0) {
			PutField_Double(myHash, "bal", v_bal);
			iCnt ++;
DEBUGLOG(("GetFXBal bal = [%.2f]\n", v_bal));
		}

		if (ind_rate >= 0) {
			PutField_Double(myHash, "rate", v_rate);
DEBUGLOG(("GetFXBal rate = [%.5f]\n", v_rate));
		}

	}

	if (iCnt > 0) {
		iRet = PD_FOUND;
DEBUGLOG(("GetFXBal: record found\n"));
	}
	else {
DEBUGLOG(("GetFXBal: no record found\n"));
		iRet = PD_NOT_FOUND;
	}

DEBUGLOG(("GetFXBal Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getfxbal_error:
DEBUGLOG(("getfxbal_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MmsEntityFXBal getfxbal_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return INT_ERR;
}

int GetFxBalForUpdate(const hash_t *hRls, hash_t *myHash)
{
	int iRet = PD_OK;

	char*   csTmp;
	int	iTmp;
	int     iCnt = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO getfxbalforupd_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	hv_entity_id[PD_MMS_ENTITY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_entity_id;

		/* varchar	hv_org_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_org_ccy;

		/* varchar	hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

		int	hv_acr_ind;

		double	v_bal;
		double	v_rate;

		short	ind_bal = -1;
		short	ind_rate = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls, "entity_id", &csTmp)) {
		hv_entity_id.len = strlen(csTmp);
		memcpy(hv_entity_id.arr, csTmp, hv_entity_id.len);
DEBUGLOG(("GetFxBalForUpdate: entity_id = [%.*s]\n", hv_entity_id.len, hv_entity_id.arr));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("GetFxBalForUpdate: entity_id NOT FOUND!\n"));
ERRLOG("MmsEntityFXBal::GetFxBalForUpdate entity_id NOT FOUND!\n");
	}

	if (GetField_CString(hRls, "org_ccy", &csTmp)) {
		hv_org_ccy.len = strlen(csTmp);
		memcpy(hv_org_ccy.arr, csTmp, hv_org_ccy.len);
DEBUGLOG(("GetFxBalForUpdate: org_ccy = [%.*s]\n", hv_org_ccy.len, hv_org_ccy.arr));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("GetFxBalForUpdate: org_ccy NOT FOUND!\n"));
ERRLOG("MmsEntityFXBal::GetFxBalForUpdate org_ccy NOT FOUND!\n");
	}

	if (GetField_CString(hRls, "ccy", &csTmp)) {
		hv_ccy.len = strlen(csTmp);
		memcpy(hv_ccy.arr, csTmp, hv_ccy.len);
DEBUGLOG(("GetFxBalForUpdate: ccy = [%.*s]\n", hv_ccy.len, hv_ccy.arr));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("GetFxBalForUpdate: ccy NOT FOUND!\n"));
ERRLOG("MmsEntityFXBal::GetFxBalForUpdate ccy NOT FOUND!\n");
	}

	if (GetField_Int(hRls, "acr_ind", &iTmp)) {
		hv_acr_ind = iTmp;
DEBUGLOG(("GetFxBalForUpdate: acr_ind = [%d]\n", hv_acr_ind));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("GetFxBalForUpdate: acr_ind NOT FOUND!\n"));
ERRLOG("MmsEntityFXBal::GetFxBalForUpdate acr_ind NOT FOUND!\n");
	}


	if (iRet == PD_OK) {
		/* EXEC SQL 
			SELECT	MFB_BAL,
				MFB_RATE
			INTO	:v_bal:ind_bal,
				:v_rate:ind_rate
			FROM	MMS_ENTITY_FX_BAL
			WHERE	MFB_ENTITY_ID = :hv_entity_id
			  AND	MFB_ORG_CCY = :hv_org_ccy
			  AND	MFB_CCY = :hv_ccy
			  AND	MFB_ACR_IND = :hv_acr_ind
			FOR UPDATE; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 8;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select MFB_BAL , MFB_RATE INTO :b0:b1 , :b2:b3 FROM MMS_EN\
TITY_FX_BAL WHERE MFB_ENTITY_ID = :b4 AND MFB_ORG_CCY = :b5 AND MFB_CCY = :b6\
 AND MFB_ACR_IND = :b7 FOR UPDATE ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )125;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_bal;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_bal;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_rate;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_rate;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_entity_id;
  sqlstm.sqhstl[2] = (unsigned long )22;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&hv_org_ccy;
  sqlstm.sqhstl[3] = (unsigned long )5;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&hv_ccy;
  sqlstm.sqhstl[4] = (unsigned long )5;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&hv_acr_ind;
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
  if (sqlca.sqlcode < 0) goto getfxbalforupd_error;
}




		if (ind_bal >= 0) {
			PutField_Double(myHash, "bal", v_bal);
			iCnt ++;
DEBUGLOG(("GetFxBalForUpdate bal = [%.2f]\n", v_bal));
		}

		if (ind_rate >= 0) {
			PutField_Double(myHash, "rate", v_rate);
DEBUGLOG(("GetFxBalForUpdate rate = [%.5f]\n", v_rate));
		}

	}

	if (iCnt > 0) {
		iRet = PD_FOUND;
DEBUGLOG(("GetFXBalForUpdate: record found\n"));
	}
	else {
DEBUGLOG(("GetFXBalForUpdate no record found\n"));
		iRet = PD_NOT_FOUND;
	}

DEBUGLOG(("GetFxBalForUpdate Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getfxbalforupd_error:
DEBUGLOG(("getfxbalforupd_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MmsEntityFXBal getfxbalforupd_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return INT_ERR;
}
