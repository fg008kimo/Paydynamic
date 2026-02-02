
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
    "MerchantSettFloat.pc"
};


static unsigned int sqlctx = 78327851;


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

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,429,0,6,155,0,0,11,11,0,1,0,2,3,0,0,1,68,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,9,0,0,
64,0,0,2,70,0,4,214,0,0,1,0,0,1,0,2,68,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/08/21              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "MerchantSettFloat.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "internal.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void MerchantSettFloat(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const hash_t *hRec)
{
	char            *csTmp;
	double		dTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                unsigned long   hv_id;
		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar		hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

		/* varchar		hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

		/* varchar		hv_service[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service;

		double		hv_org_available_payout;
		double		hv_after_available_payout;
		double		hv_org_settlement_float;
		double		hv_after_settlement_float;
		/* varchar		hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;

               
		short		ind_id = -1;
		short		ind_merchant_id = -1;
		short		ind_country = -1;
		short		ind_ccy = -1;
		short		ind_service = -1;
		short		ind_org_available_payout = -1;
		short		ind_after_available_payout = -1;
		short		ind_org_settlement_float = -1;
		short		ind_after_settlement_float = -1;
                short           ind_add_user= -1;
 
                short           hv_return_value;
                /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

/*id*/
        if(GetField_CString(hRec,"id",&csTmp)){
                hv_id = ctol((const unsigned char*)csTmp,strlen(csTmp));
                ind_id= 0;
DEBUGLOG(("Add:id= [%ld]\n",hv_id));
        }

/* merchant_id */
        if(GetField_CString(hRec,"merchant_id",&csTmp)){
                hv_merchant_id.len = strlen(csTmp);
                memcpy(hv_merchant_id.arr, csTmp, hv_merchant_id.len);
                ind_merchant_id = 0;
DEBUGLOG(("Add:merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        }

/* txn_country */
        if(GetField_CString(hRec,"txn_country",&csTmp)){
                hv_country.len = strlen(csTmp);
                memcpy(hv_country.arr, csTmp, hv_country.len);
                ind_country = 0;
DEBUGLOG(("Add:country = [%.*s]\n",hv_country.len,hv_country.arr));
        }

/* txn_ccy */
        if(GetField_CString(hRec,"txn_ccy",&csTmp)){
                hv_ccy.len = strlen(csTmp);
                memcpy(hv_ccy.arr, csTmp, hv_ccy.len);
                ind_ccy = 0;
DEBUGLOG(("Add:ccy = [%.*s]\n",hv_ccy.len,hv_ccy.arr));
        }

/* service_code */
        if(GetField_CString(hRec,"service_code",&csTmp)){
                hv_service.len = strlen(csTmp);
                memcpy(hv_service.arr, csTmp, hv_service.len);
                ind_service = 0;
DEBUGLOG(("Add:service = [%.*s]\n",hv_service.len,hv_service.arr));
        }

/* org_available_payout */
        if(GetField_Double(hRec,"org_available_payout",&dTmp)){
		hv_org_available_payout = dTmp;
		ind_org_available_payout = 0;
DEBUGLOG(("Add:org_available_payout = [%lf]\n",hv_org_available_payout));
        } else {
		hv_org_available_payout = 0.0;	
		ind_org_available_payout = 0;
	}
	
/* after_available_payout */
        if(GetField_Double(hRec,"after_available_payout",&dTmp)){
		hv_after_available_payout = dTmp;
		ind_after_available_payout = 0;
DEBUGLOG(("Add:after_available_payout = [%lf]\n",hv_after_available_payout));
        } else {
		hv_after_available_payout = 0.0;
		ind_after_available_payout = 0;
	}
	

/* org_settlement_float */
        if(GetField_Double(hRec,"org_settlement_float",&dTmp)){
		hv_org_settlement_float = dTmp;
		ind_org_settlement_float = 0;
DEBUGLOG(("Add:org_settlement_float = [%lf]\n",hv_org_settlement_float));
        } else {
		hv_org_settlement_float = 0.0;
		ind_org_settlement_float = 0;
	}

/* after_settlement_float */
        if(GetField_Double(hRec,"after_settlement_float",&dTmp)){
		hv_after_settlement_float = dTmp;
		ind_after_settlement_float = 0;
DEBUGLOG(("Add:after_settlement_float = [%lf]\n",hv_after_settlement_float));
        } else {
		hv_after_settlement_float = 0.0;
		ind_after_settlement_float = 0;
	}

/*user*/
        if(GetField_CString(hRec,"add_user",&csTmp)){
                hv_add_user.len = strlen(csTmp);
                memcpy(hv_add_user.arr, csTmp, hv_add_user.len);
                ind_add_user= 0;
DEBUGLOG(("Add:add_user= [%.*s]\n",hv_add_user.len,hv_add_user.arr));
        }

	/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_merchant_sett_float_insert (
					:hv_id:ind_id,
					:hv_merchant_id:ind_merchant_id,
                                        :hv_country:ind_country,
                                        :hv_ccy:ind_ccy,
					:hv_service:ind_service,
                                        :hv_org_available_payout:ind_org_available_payout,
                                        :hv_after_available_payout:ind_after_available_payout,
					:hv_org_settlement_float:ind_org_settlement_float,
					:hv_after_settlement_float:ind_after_settlement_float,
                                        :hv_add_user:ind_add_user);
                END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merchant_sett_float_insert ( :\
hv_id:ind_id , :hv_merchant_id:ind_merchant_id , :hv_country:ind_country , :h\
v_ccy:ind_ccy , :hv_service:ind_service , :hv_org_available_payout:ind_org_av\
ailable_payout , :hv_after_available_payout:ind_after_available_payout , :hv_\
org_settlement_float:ind_org_settlement_float , :hv_after_settlement_float:in\
d_after_settlement_float , :hv_add_user:ind_add_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_id;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[2] = (unsigned long )17;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_merchant_id;
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
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_ccy;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_ccy;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_service;
 sqlstm.sqhstl[5] = (unsigned long )5;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_service;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_org_available_payout;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_org_available_payout;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_after_available_payout;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_after_available_payout;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_org_settlement_float;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_org_settlement_float;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_after_settlement_float;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_after_settlement_float;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_add_user;
 sqlstm.sqhstl[10] = (unsigned long )22;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_add_user;
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
ERRLOG("MerchantSettFloat_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("MerchantSettFloat_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MerchantSettFloat_Add: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}

int GetNextId(unsigned long *lId)
{
	int iRet = PD_OK;
	*lId = 0l;

	/* EXEC SQL WHENEVER SQLERROR GOTO GetNextId_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		unsigned long	v_id;

                short           ind_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        /* EXEC SQL SELECT NVL(max(sf_id), 0) 
                INTO    :v_id:ind_id
                FROM    merchant_sett_float; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select NVL ( max ( sf_id ) , 0 ) INTO :b0:b1 FROM me\
rchant_sett_float ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )64;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_id;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_id;
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
        if (sqlca.sqlcode < 0) goto GetNextId_error;
}



        if(ind_id>=0){
                *lId = v_id+1;
DEBUGLOG(("GetNextId  [%ld]\n", *lId)); 
        }

	return iRet;

GetNextId_error:
DEBUGLOG(("GetNextId_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

