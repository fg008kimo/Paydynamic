
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
           char  filnam[17];
};
static struct sqlcxp sqlfpn =
{
    16,
    "MmsAffectFXDT.pc"
};


static unsigned int sqlctx = 5018619;


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
   unsigned char  *sqhstv[12];
   unsigned long  sqhstl[12];
            int   sqhsts[12];
            short *sqindv[12];
            int   sqinds[12];
   unsigned long  sqharm[12];
   unsigned long  *sqharc[12];
   unsigned short  sqadto[12];
   unsigned short  sqtdso[12];
} sqlstm = {12,12};

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
"SELECT MAF_FX_SEQ , MAF_DIRECTION , MAF_ENTITY_ID , MAF_ACR_IND , MAF_ORG_C\
CY , MAF_ORG_AMOUNT , MAF_CCY , MAF_AMOUNT , MAF_CALCULATE_IND FROM MMS_AFFEC\
T_FX_DT WHERE MAF_FX_ID = :b0 ORDER BY MAF_FX_SEQ            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,365,0,6,165,0,0,12,12,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,1,1,0,0,1,9,0,0,1,
3,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,4,0,0,1,3,0,0,1,9,0,0,
68,0,0,2,0,0,17,275,0,0,1,1,0,1,0,1,9,0,0,
87,0,0,2,0,0,21,276,0,0,0,0,0,1,0,
102,0,0,3,213,0,9,362,0,2049,1,1,0,1,0,1,9,0,0,
121,0,0,3,0,0,13,364,0,0,9,0,0,1,0,2,3,0,0,2,1,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,4,
0,0,2,9,0,0,2,4,0,0,2,3,0,0,
172,0,0,3,0,0,15,448,0,0,0,0,0,1,0,
187,0,0,3,0,0,15,466,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/07/23              Dirk Wong
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
#include "MmsAffectFXDT.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char    cDebug;

void MmsAffectFXDT(char    cdebug)
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
		char		hv_direction;
		/* varchar		hv_entity_id[PD_MMS_ENTITY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_entity_id;

		int		hv_acr_ind;
		/* varchar		hv_org_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_org_ccy;

		/* varchar		hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

		double		hv_org_amount;
		double		hv_amount;
		//double		hv_aff_fx_amt;
		//double		hv_non_aff_fx_amt;
		int		hv_calculate_ind;
		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_fx_id = -1;
		short		ind_fx_seq = -1;
		short		ind_direction = -1;
		short		ind_entity_id = -1;
		short		ind_acr_ind = -1;
		short		ind_org_ccy = -1;
		short		ind_ccy = -1;
		short		ind_org_amount = -1;
		short		ind_amount = -1;
		//short		ind_aff_fx_amt = -1;
		///short		ind_non_aff_fx_amt = -1;
		short		ind_calculate_ind = -1;
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

	if(GetField_Int(hRls, "fx_seq", &iTmp)) {
		hv_fx_seq = iTmp;
		ind_fx_seq = 0;
DEBUGLOG(("Add:fx_seq = [%d]\n",hv_fx_seq));
	}

	if(GetField_Char(hRls,"direction",&cTmp)) {
		hv_direction = cTmp;
		ind_direction = 0;
DEBUGLOG(("Add:direction = [%c]\n",hv_direction,csTmp));
	}

        if(GetField_CString(hRls,"entity_id",&csTmp)) {
                hv_entity_id.len = strlen(csTmp);
                strncpy((char*)hv_entity_id.arr, csTmp, hv_entity_id.len);
                ind_entity_id = 0;
DEBUGLOG(("Add:entity_id = [%.*s]\n",hv_entity_id.len, hv_entity_id.arr));
	}

	if(GetField_Int(hRls, "acr_ind", &iTmp)) {
		hv_acr_ind = iTmp;
		ind_acr_ind = 0;
DEBUGLOG(("Add:acr_ind = [%d]\n",hv_acr_ind));
	}

        if(GetField_CString(hRls,"org_ccy",&csTmp)) {
                hv_org_ccy.len = strlen(csTmp);
                strncpy((char*)hv_org_ccy.arr, csTmp, hv_org_ccy.len);
                ind_org_ccy = 0;
DEBUGLOG(("Add:org_ccy = [%.*s]\n",hv_org_ccy.len, hv_org_ccy.arr));
        }

        if(GetField_Double(hRls, "org_amount", &dTmp)) {
                hv_org_amount = dTmp;
                ind_org_amount = 0;
DEBUGLOG(("Add:org_amount = [%.2f]\n",hv_org_amount));
        }

        if(GetField_CString(hRls,"ccy",&csTmp)) {
                hv_ccy.len = strlen(csTmp);
                strncpy((char*)hv_ccy.arr, csTmp, hv_ccy.len);
                ind_ccy = 0;
DEBUGLOG(("Add:ccy = [%.*s]\n",hv_ccy.len, hv_ccy.arr));
        }

        if(GetField_Double(hRls, "amount", &dTmp)) {
                hv_amount = dTmp;
                ind_amount = 0;
DEBUGLOG(("Add:amount = [%.2f]\n",hv_amount));
        }
/*
        if(GetField_Double(hRls, "aff_fx_amt", &dTmp)) {
                hv_aff_fx_amt = dTmp;
                ind_aff_fx_amt = 0;
DEBUGLOG(("Add:aff_fx_amt = [%.2f]\n",hv_aff_fx_amt));
        }

        if(GetField_Double(hRls, "non_aff_fx_amt", &dTmp)) {
                hv_non_aff_fx_amt = dTmp;
                ind_non_aff_fx_amt = 0;
DEBUGLOG(("Add:non_aff_fx_amt = [%.2f]\n",hv_non_aff_fx_amt));
        }
*/
	if(GetField_Int(hRls, "calculate_ind", &iTmp)) {
		hv_calculate_ind = iTmp;
		ind_calculate_ind = 0;
DEBUGLOG(("Add:calculate_ind = [%d]\n",hv_calculate_ind));
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
			:hv_return_value := sp_mms_affect_fxdt_insert(
								:hv_fx_id:ind_fx_id,
								:hv_fx_seq:ind_fx_seq,
								:hv_direction:ind_direction,
								:hv_entity_id:ind_entity_id,
								:hv_acr_ind:ind_acr_ind,
								:hv_org_ccy:ind_org_ccy,
								:hv_org_amount:ind_org_amount,
								:hv_ccy:ind_ccy,
								:hv_amount:ind_amount,
								//:hv_aff_fx_amt:ind_aff_fx_amt,
								//:hv_non_aff_fx_amt:ind_non_aff_fx_amt,
								:hv_calculate_ind:ind_calculate_ind,
								:hv_create_user:ind_create_user); 
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_mms_affect_fxdt_insert ( :hv_f\
x_id:ind_fx_id , :hv_fx_seq:ind_fx_seq , :hv_direction:ind_direction , :hv_en\
tity_id:ind_entity_id , :hv_acr_ind:ind_acr_ind , :hv_org_ccy:ind_org_ccy , :\
hv_org_amount:ind_org_amount , :hv_ccy:ind_ccy , :hv_amount:ind_amount , :hv_\
calculate_ind:ind_calculate_ind , :hv_create_user:ind_create_user ) ; END ;";
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
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_direction;
 sqlstm.sqhstl[3] = (unsigned long )1;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_direction;
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
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_acr_ind;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_acr_ind;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_org_ccy;
 sqlstm.sqhstl[6] = (unsigned long )5;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_org_ccy;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_org_amount;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_org_amount;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_ccy;
 sqlstm.sqhstl[8] = (unsigned long )5;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_ccy;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_amount;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_amount;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_calculate_ind;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_calculate_ind;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[11] = (unsigned long )22;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_create_user;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
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
ERRLOG("MmsAffectFXDT_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("MmsAffectFXDT_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }


add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MmsAffectFXDT_Add: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int Update(const hash_t *hRls)
{
        char    *csCalculateInd;
        char    *csBuf;
	char	*csTmp;
	int	iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar        hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
        csCalculateInd = (char *)malloc(128);
        csBuf = (char *)malloc(128);

        strcpy((char*)hv_dynstmt.arr,"update mms_affect_fx_dt set maf_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

/*calculate_ind*/
        if (GetField_Int(hRls,"calculate_ind",&iTmp)) {
DEBUGLOG(("Update: calculate_ind = [%d]\n",iTmp));
                sprintf(csCalculateInd,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",maf_calculate_ind = ");
                strcat((char*)hv_dynstmt.arr, csCalculateInd);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*update_user*/
        if (GetField_CString(hRls,"update_user",&csTmp)) {
DEBUGLOG(("Update:update_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",maf_update_user = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*Primary Key: fx_id*/
        if (GetField_CString(hRls,"fx_id",&csTmp)) {
DEBUGLOG(("Update: fx_id = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, " WHERE maf_fx_id = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
       		strcat((char*)hv_dynstmt.arr, "'");
	}

/*Primary Key: fx_seq*/
	if (GetField_Int(hRls,"fx_seq",&iTmp)) {
DEBUGLOG(("Update: fx_seq = [%d]\n", iTmp));
		sprintf(csBuf,"%d",iTmp);
		strcat((char*)hv_dynstmt.arr, " and maf_fx_seq = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
       		strcat((char*)hv_dynstmt.arr, " and maf_calculate_ind <> ");
                strcat((char*)hv_dynstmt.arr, csCalculateInd);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )68;
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
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )87;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_error;
}



        FREE_ME(csCalculateInd);
        FREE_ME(csBuf);
	
DEBUGLOG(("Update Normal Exit\n"));
        return PD_OK;

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("MmsAffectFXDT:Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
        return PD_INTERNAL_ERR;
}

int GetAffectFXDT(const hash_t *hRls, recordset_t *myRec)
{
	int iRet = PD_OK;

	char*   csTmp;
	int     iCnt;

	hash_t *myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO getfxbal_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	hv_fx_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_fx_id;


		int	v_fx_seq;
		char	v_direction;
		/* varchar	v_entity_id[PD_MMS_ENTITY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_entity_id;

		int	v_acr_ind;
		/* varchar	v_org_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_org_ccy;

		/* varchar	v_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ccy;

		double	v_org_amount;
		double	v_amount;
		//double	v_aff_fx_amt;
		//double	v_non_aff_fx_amt;
		int	v_calculate_ind;

		short	ind_fx_seq = -1;
		short	ind_direction = -1;
		short	ind_entity_id = -1;
		short	ind_acr_ind = -1;
		short	ind_org_ccy = -1;
		short	ind_ccy = -1;
		short	ind_org_amount = -1;
		short	ind_amount = -1;
		//short	ind_aff_fx_amt = -1;
		//short	ind_non_aff_fx_amt = -1;
		short	ind_calculate_ind = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls, "fx_id", &csTmp)) {
		hv_fx_id.len = strlen(csTmp);
		memcpy(hv_fx_id.arr, csTmp, hv_fx_id.len);
DEBUGLOG(("GetAffectFXDT: fx_id = [%.*s]\n", hv_fx_id.len, hv_fx_id.arr));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("GetAffectFXDT: fx_id NOT FOUND!\n"));
ERRLOG("MmsAffectFXDT::GetAffectFXDT fx_id NOT FOUND!\n");
	}

	if (iRet == PD_OK) {
		/* EXEC SQL DECLARE c_getfxdt CURSOR FOR
			SELECT	MAF_FX_SEQ,
				MAF_DIRECTION,
				MAF_ENTITY_ID,
				MAF_ACR_IND,
				MAF_ORG_CCY,
				MAF_ORG_AMOUNT,
				MAF_CCY,
				MAF_AMOUNT,
				--MAF_AFF_FX_AMT,
				--MAF_NON_AFF_FX_AMT,
				MAF_CALCULATE_IND
			FROM	MMS_AFFECT_FX_DT
			WHERE	MAF_FX_ID = :hv_fx_id
			ORDER BY MAF_FX_SEQ; */ 


		/* EXEC SQL OPEN c_getfxdt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = sq0003;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )102;
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
			INTO	:v_fx_seq:ind_fx_seq,
				:v_direction:ind_direction,
				:v_entity_id:ind_entity_id,
				:v_acr_ind:ind_acr_ind,
				:v_org_ccy:ind_org_ccy,
				:v_org_amount:ind_org_amount,
				:v_ccy:ind_ccy,
				:v_amount:ind_amount,
				//:v_aff_fx_amt:ind_aff_fx_amt,
				//:v_non_aff_fx_amt:ind_non_aff_fx_amt,
				:v_calculate_ind:ind_calculate_ind; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 12;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )121;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_fx_seq;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_fx_seq;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_direction;
   sqlstm.sqhstl[1] = (unsigned long )1;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_direction;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_entity_id;
   sqlstm.sqhstl[2] = (unsigned long )23;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_entity_id;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_acr_ind;
   sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_acr_ind;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_org_ccy;
   sqlstm.sqhstl[4] = (unsigned long )6;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_org_ccy;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_org_amount;
   sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_org_amount;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&v_ccy;
   sqlstm.sqhstl[6] = (unsigned long )6;
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_ccy;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&v_amount;
   sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         short *)&ind_amount;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
   sqlstm.sqhstv[8] = (unsigned char  *)&v_calculate_ind;
   sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[8] = (         int  )0;
   sqlstm.sqindv[8] = (         short *)&ind_calculate_ind;
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

			if (ind_fx_seq >= 0) {
				PutField_Int(myHash, "fx_seq", v_fx_seq);
DEBUGLOG(("GetAffectFXDT fx_seq = [%d]\n", v_fx_seq));
			}

			if (ind_direction >= 0) {
				PutField_Char(myHash, "direction", v_direction);
DEBUGLOG(("GetAffectFXDT direction = [%c]\n", v_direction));
			}

			if (ind_entity_id >= 0) {
				v_entity_id.arr[v_entity_id.len] = '\0';
				PutField_CString(myHash,"entity_id",(const char*)v_entity_id.arr);
DEBUGLOG(("GetAffectFXDT entity_id = [%s]\n", (const char*)v_entity_id.arr));
			}

			if (ind_acr_ind >= 0) {
				PutField_Int(myHash, "acr_ind", v_acr_ind);
DEBUGLOG(("GetAffectFXDT acr_ind = [%d]\n", v_acr_ind));
			}

			if (ind_org_ccy >= 0) {
				v_org_ccy.arr[v_org_ccy.len] = '\0';
				PutField_CString(myHash,"org_ccy",(const char*)v_org_ccy.arr);
DEBUGLOG(("GetAffectFXDT org_ccy = [%s]\n", (const char*)v_org_ccy.arr));
			}

			if (ind_org_amount >= 0) {
				PutField_Double(myHash,"org_amount",v_org_amount);
DEBUGLOG(("GetAffectFXDT org_amount = [%lf]\n", v_org_amount));
			}

			if (ind_ccy >= 0) {
				v_ccy.arr[v_ccy.len] = '\0';
				PutField_CString(myHash,"ccy",(const char*)v_ccy.arr);
DEBUGLOG(("GetAffectFXDT ccy = [%s]\n", (const char*)v_ccy.arr));
			}

			if (ind_amount >= 0) {
				PutField_Double(myHash,"amount",v_amount);
DEBUGLOG(("GetAffectFXDT amount = [%lf]\n", v_amount));
			}

/*
			if (ind_aff_fx_amt >= 0) {
				PutField_Double(myHash,"aff_fx_amt",v_aff_fx_amt);
DEBUGLOG(("GetAffectFXDT aff_fx_amt = [%lf]\n", v_aff_fx_amt));
			}

			if (ind_non_aff_fx_amt >= 0) {
				PutField_Double(myHash,"non_aff_fx_amt",v_non_aff_fx_amt);
DEBUGLOG(("GetAffectFXDT non_aff_fx_amt = [%lf]\n", v_non_aff_fx_amt));
			}
*/

			if (ind_calculate_ind >= 0) {
				PutField_Int(myHash, "calculate_ind", v_calculate_ind);
DEBUGLOG(("GetAffectFXDT calculate_ind = [%d]\n", v_calculate_ind));
			}

			RecordSet_Add(myRec, myHash);
		}
		/* EXEC SQL CLOSE c_getfxdt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 12;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )172;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto getfxbal_error;
}



		if (iCnt > 0) {
DEBUGLOG(("GetAffectFXDT: record found\n"));
		} else {
DEBUGLOG(("GetAffectFXDT no record found\n"));
ERRLOG("MmsAffectFXDT::GetAffectFXDT no record found\n");
		}
	}

DEBUGLOG(("GetAffectFXDT Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getfxbal_error:
DEBUGLOG(("getfxbal_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MmsAffectFXDT getfxbal_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL CLOSE c_getfxdt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )187;
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

