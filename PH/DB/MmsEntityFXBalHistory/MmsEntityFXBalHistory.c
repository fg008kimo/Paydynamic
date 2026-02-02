
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
           char  filnam[25];
};
static struct sqlcxp sqlfpn =
{
    24,
    "MmsEntityFXBalHistory.pc"
};


static unsigned int sqlctx = 1298629347;


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

 static char *sq0002 = 
"SELECT MBH_FUNDS_DIRECTION , MBH_ENTITY_ID , MBH_ACR_IND , MBH_ORG_CCY , MB\
H_CCY , MBH_OLD_BAL , MBH_NEW_BAL , MBH_OLD_RATE , MBH_NEW_RATE FROM MMS_ENTI\
TY_FX_BAL_HISTORY WHERE MBH_FX_ID = :b0 AND MBH_FX_SEQ = :b1            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,394,0,6,160,0,0,13,13,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,1,1,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,1,3,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,9,0,0,
72,0,0,2,224,0,9,286,0,2049,2,2,0,1,0,1,9,0,0,1,3,0,0,
95,0,0,2,0,0,13,288,0,0,9,0,0,1,0,2,1,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,4,
0,0,2,4,0,0,2,4,0,0,2,4,0,0,
146,0,0,2,0,0,15,359,0,0,0,0,0,1,0,
161,0,0,2,0,0,15,377,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/04/29              Dirk Wong
some field updated	 			   2015/07/27		   LokMan Chow
Remove ratio					   2015/07/29		   LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "internal.h"
#include "utilitys.h"
#include "dbutility.h"
#include "MmsEntityFXBalHistory.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char    cDebug;

void MmsEntityFXBalHistory(char    cdebug)
{
        cDebug = cdebug;
}


int Add(const hash_t *hRls)
{
	char	*csTmp;
	char	cTmp;
	int	iTmp;
	double	dTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_fx_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_fx_id;

		int		hv_fx_seq;
		/* varchar		hv_entity_id[PD_MMS_ENTITY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_entity_id;

		/* varchar		hv_org_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_org_ccy;

		/* varchar		hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

		int		hv_acr_ind;
		double		hv_old_bal;
		double		hv_new_bal;
		double		hv_old_rate;
		double		hv_new_rate;
		char		hv_funds_direction;
		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_fx_id = -1;
		short		ind_fx_seq = -1;
		short		ind_entity_id = -1;
		short		ind_org_ccy = -1;
		short		ind_ccy = -1;
		short		ind_acr_ind = -1;
		short		ind_old_bal = -1;
		short		ind_new_bal = -1;
		short		ind_old_rate = -1;
		short		ind_new_rate = -1;
		short		ind_funds_direction = -1;
		short		ind_create_user = -1;
	
		short		hv_return_value;	
		
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

        if(GetField_CString(hRls,"fx_id",&csTmp)) {
                hv_fx_id.len = strlen(csTmp);
                strncpy((char*)hv_fx_id.arr, csTmp, hv_fx_id.len);
                ind_fx_id = 0;
DEBUGLOG(("Add:fx_id = [%.*s]\n",hv_fx_id.len, hv_fx_id.arr));
	}

	if(GetField_Int(hRls,"fx_seq",&iTmp)) {
		hv_fx_seq = iTmp;
		ind_fx_seq = 0;
DEBUGLOG(("Add:fx_seq = [%d]\n",hv_fx_seq ));
	}

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

	if(GetField_Int(hRls,"acr_ind",&iTmp)) {
		hv_acr_ind = iTmp;
		ind_acr_ind = 0;
DEBUGLOG(("Add:acr_ind = [%d]\n", hv_acr_ind));
	}

        if(GetField_Double(hRls, "old_bal", &dTmp)) {
                hv_old_bal = dTmp;
                ind_old_bal = 0;
DEBUGLOG(("Add:old_bal = [%.2f]\n",hv_old_bal));
        }

        if(GetField_Double(hRls, "new_bal", &dTmp)) {
                hv_new_bal = dTmp;
                ind_new_bal = 0;
DEBUGLOG(("Add:new_bal = [%.2f]\n",hv_new_bal));
        }

        if(GetField_Double(hRls, "old_rate", &dTmp)) {
                hv_old_rate = dTmp;
                ind_old_rate = 0;
DEBUGLOG(("Add:old_rate = [%.5f]\n",hv_old_rate));
        }

        if(GetField_Double(hRls, "new_rate", &dTmp)) {
                hv_new_rate = dTmp;
                ind_new_rate = 0;
DEBUGLOG(("Add:new_rate = [%.5f]\n",hv_new_rate));
        }

	if(GetField_Char(hRls, "direction", &cTmp)) {
		hv_funds_direction = cTmp;
		ind_funds_direction = 0;
DEBUGLOG(("Add:funds_direction = [%c]\n",hv_funds_direction));
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
			:hv_return_value := sp_entity_fx_bal_hist_insert(
								:hv_fx_id:ind_fx_id,
								:hv_fx_seq:ind_fx_seq,
								:hv_funds_direction:ind_funds_direction,
								:hv_entity_id:ind_entity_id,
								:hv_org_ccy:ind_org_ccy,
								:hv_ccy:ind_ccy,
								:hv_acr_ind:ind_acr_ind,
								:hv_old_bal:ind_old_bal,
								:hv_new_bal:ind_new_bal,
								:hv_old_rate:ind_old_rate,
								:hv_new_rate:ind_new_rate,
								:hv_create_user:ind_create_user); 
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_entity_fx_bal_hist_insert ( :h\
v_fx_id:ind_fx_id , :hv_fx_seq:ind_fx_seq , :hv_funds_direction:ind_funds_dir\
ection , :hv_entity_id:ind_entity_id , :hv_org_ccy:ind_org_ccy , :hv_ccy:ind_\
ccy , :hv_acr_ind:ind_acr_ind , :hv_old_bal:ind_old_bal , :hv_new_bal:ind_new\
_bal , :hv_old_rate:ind_old_rate , :hv_new_rate:ind_new_rate , :hv_create_use\
r:ind_create_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_fx_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_fx_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_fx_seq;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_fx_seq;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_funds_direction;
 sqlstm.sqhstl[3] = (unsigned long )1;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_funds_direction;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_entity_id;
 sqlstm.sqhstl[4] = (unsigned long )22;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_entity_id;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_org_ccy;
 sqlstm.sqhstl[5] = (unsigned long )5;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_org_ccy;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_ccy;
 sqlstm.sqhstl[6] = (unsigned long )5;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_ccy;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_acr_ind;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_acr_ind;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_old_bal;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_old_bal;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_new_bal;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_new_bal;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_old_rate;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_old_rate;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_new_rate;
 sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_new_rate;
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
ERRLOG("MmsEntityFXBalHistory_Add: SP_OTHER_ERR \n");
DEBUGLOG(("Add: SP_OTHER_ERR \n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("MmsEntityFXBalHistory_Add: SP_ERR \n");
DEBUGLOG(("Add: SP_ERR \n"));
                return PD_ERR;
        }


add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MmsEntityFXBalHistory_Add: SP_INTERNAL_ERR \n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int GetFXBalHistory(const hash_t *hRls, recordset_t *myRec)
{
	int iRet = PD_OK;

	char*   csTmp;
	int     iTmp;
	int     iCnt;

	hash_t *myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO getfxbal_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	hv_fx_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_fx_id;

		int	hv_fx_seq;

		char	v_direction;
		/* varchar	v_entity_id[PD_MMS_ENTITY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_entity_id;

		int	v_acr_ind;
		/* varchar	v_org_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_org_ccy;

		/* varchar	v_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ccy;

		double	v_old_bal;
		double	v_new_bal;
		double	v_old_rate;
		double	v_new_rate;

		short	ind_direction = -1;
		short	ind_entity_id = -1;
		short	ind_acr_ind = -1;
		short	ind_org_ccy = -1;
		short	ind_ccy = -1;
		short	ind_old_bal = -1;
		short	ind_new_bal = -1;
		short	ind_old_rate = -1;
		short	ind_new_rate = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls, "fx_id", &csTmp)) {
		hv_fx_id.len = strlen(csTmp);
		memcpy(hv_fx_id.arr, csTmp, hv_fx_id.len);
DEBUGLOG(("GetFXBalHistory: fx_id = [%.*s]\n", hv_fx_id.len, hv_fx_id.arr));
	}
	else {
		iRet = INT_ERR;
DEBUGLOG(("GetFXBalHistory: fx_id NOT FOUND!\n"));
ERRLOG("MmsEntityFXBalHistory::GetFXBalHistory fx_id NOT FOUND!\n");
	}

	if(GetField_Int(hRls,"fx_seq",&iTmp)) {
		hv_fx_seq = iTmp;
DEBUGLOG(("GetFXBalHistory: fx_seq = [%d]\n", hv_fx_seq));
	}
	else {
		iRet = INT_ERR;
DEBUGLOG(("GetFXBalHistory: fx_seq NOT FOUND!\n"));
ERRLOG("MmsEntityFXBalHistory::GetFXBalHistory fx_seq NOT FOUND!\n");
	}


	if (iRet == PD_OK) {
		/* EXEC SQL DECLARE c_getfxdt CURSOR FOR
			SELECT	
				MBH_FUNDS_DIRECTION,
				MBH_ENTITY_ID,
				MBH_ACR_IND,
				MBH_ORG_CCY,
				MBH_CCY,
				MBH_OLD_BAL,
				MBH_NEW_BAL,
				MBH_OLD_RATE,
				MBH_NEW_RATE
			FROM	MMS_ENTITY_FX_BAL_HISTORY
			WHERE	MBH_FX_ID = :hv_fx_id
			AND 	MBH_FX_SEQ = :hv_fx_seq; */ 


		/* EXEC SQL OPEN c_getfxdt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = sq0002;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )72;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_fx_id;
  sqlstm.sqhstl[0] = (unsigned long )18;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_fx_seq;
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
  if (sqlca.sqlcode < 0) goto getfxbal_error;
}


		for (;;) {
			/* EXEC SQL FETCH c_getfxdt
			INTO
				:v_direction:ind_direction,
				:v_entity_id:ind_entity_id,
				:v_acr_ind:ind_acr_ind,
				:v_org_ccy:ind_org_ccy,
				:v_ccy:ind_ccy,
				:v_old_bal:ind_old_bal,
				:v_new_bal:ind_new_bal,
				:v_old_rate:ind_old_rate,
				:v_new_rate:ind_new_rate; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 13;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )95;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_direction;
   sqlstm.sqhstl[0] = (unsigned long )1;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_direction;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_entity_id;
   sqlstm.sqhstl[1] = (unsigned long )23;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_entity_id;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_acr_ind;
   sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_acr_ind;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_org_ccy;
   sqlstm.sqhstl[3] = (unsigned long )6;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_org_ccy;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_ccy;
   sqlstm.sqhstl[4] = (unsigned long )6;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_ccy;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_old_bal;
   sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_old_bal;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&v_new_bal;
   sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_new_bal;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&v_old_rate;
   sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         short *)&ind_old_rate;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
   sqlstm.sqhstv[8] = (unsigned char  *)&v_new_rate;
   sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[8] = (         int  )0;
   sqlstm.sqindv[8] = (         short *)&ind_new_rate;
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
   if (sqlca.sqlcode < 0) goto getfxbal_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			iCnt++;

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			if (ind_direction >= 0) {
				PutField_Char(myHash, "direction", v_direction);
DEBUGLOG(("GetFXBalHistory direction = [%c]\n", v_direction));
			}

			if (ind_entity_id >= 0) {
				v_entity_id.arr[v_entity_id.len] = '\0';
				PutField_CString(myHash,"entity_id",(const char*)v_entity_id.arr);
DEBUGLOG(("GetFXBalHistory entity_id = [%s]\n", (const char*)v_entity_id.arr));
			}

			if (ind_acr_ind >= 0) {
				PutField_Int(myHash, "acr_ind", v_acr_ind);
DEBUGLOG(("GetFXBalHistory acr_ind = [%d]\n", v_acr_ind));
			}

			if (ind_org_ccy >= 0) {
				v_org_ccy.arr[v_org_ccy.len] = '\0';
				PutField_CString(myHash,"org_ccy",(const char*)v_org_ccy.arr);
DEBUGLOG(("GetFXBalHistory org_ccy = [%s]\n", (const char*)v_org_ccy.arr));
			}

			if (ind_ccy >= 0) {
				v_ccy.arr[v_ccy.len] = '\0';
				PutField_CString(myHash,"ccy",(const char*)v_ccy.arr);
DEBUGLOG(("GetFXBalHistory ccy = [%s]\n", (const char*)v_ccy.arr));
			}

			if (ind_old_bal>= 0) {
				PutField_Double(myHash,"old_bal",v_old_bal);
DEBUGLOG(("GetFXBalHistory old_bal = [%lf]\n", v_old_bal));
			}

			if (ind_new_bal>= 0) {
				PutField_Double(myHash,"new_bal",v_new_bal);
DEBUGLOG(("GetFXBalHistory new_bal = [%lf]\n", v_new_bal));
			}

			if (ind_old_rate>= 0) {
				PutField_Double(myHash,"old_rate",v_old_rate);
DEBUGLOG(("GetFXBalHistory old_rate = [%lf]\n", v_old_rate));
			}

			if (ind_new_rate>= 0) {
				PutField_Double(myHash,"new_rate",v_new_rate);
DEBUGLOG(("GetFXBalHistory new_rate = [%lf]\n", v_new_rate));
			}

			RecordSet_Add(myRec, myHash);
		}
		/* EXEC SQL CLOSE c_getfxdt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )146;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto getfxbal_error;
}



		if (iCnt > 0) {
DEBUGLOG(("GetFXBalHistory: record found\n"));
		} else {
DEBUGLOG(("GetFXBalHistory no record found\n"));
ERRLOG("MmsEntityFXBalHistory::GetFXBalHistory no record found\n");
		}
	}

DEBUGLOG(("GetFXBalHistory Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getfxbal_error:
DEBUGLOG(("getfxbal_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MmsEntityFXBalHistory getfxbal_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL CLOSE c_getfxdt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )161;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getfxbal_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

