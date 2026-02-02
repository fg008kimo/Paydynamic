
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
    "MerchantPayMethod.pc"
};


static unsigned int sqlctx = 78318635;


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
   unsigned char  *sqhstv[5];
   unsigned long  sqhstl[5];
            int   sqhsts[5];
            short *sqindv[5];
            int   sqinds[5];
   unsigned long  sqharm[5];
   unsigned long  *sqharc[5];
   unsigned short  sqadto[5];
   unsigned short  sqtdso[5];
} sqlstm = {12,5};

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
5,0,0,1,107,0,4,58,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
32,0,0,2,193,0,6,136,0,0,5,5,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,9,0,0,
67,0,0,3,0,0,17,235,0,0,1,1,0,1,0,1,9,0,0,
86,0,0,3,0,0,21,236,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/07/29              LokMan Chow
Add "Add" function                                 2012/05/28              Virginia Yun
Add "Update" function			           2012/06/13		   Virginia Yun

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "MerchantPayMethod.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char    cDebug;

void MerchantPayMethod(char    cdebug)
{
        cDebug = cdebug;
}

int FindMerchantPayMethod(const char* csMerchantId,
                        const char* csPayMethod)
{
	
        /* EXEC SQL WHENEVER SQLERROR GOTO find_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	hv_pay_method[PD_PAY_METHOD_LEN]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_pay_method;



		int    v_disabled;

                short   ind_disabled = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


	hv_merchant_id.len = strlen(csMerchantId);
        memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
DEBUGLOG(("FindMerchantPayMethod: merchant_id = [%.*s][%d]\n",hv_merchant_id.len,hv_merchant_id.arr,hv_merchant_id.len)); 

	hv_pay_method.len = strlen(csPayMethod);
        memcpy(hv_pay_method.arr,csPayMethod,hv_pay_method.len);
DEBUGLOG(("FindMerchantPayMethod: pay_method = [%.*s][%d]\n",hv_pay_method.len,hv_pay_method.arr,hv_pay_method.len)); 

	/* EXEC SQL select pm_disabled
                   into :v_disabled:ind_disabled
                   from merchant_pay_method
                  Where pm_merchant_id = :hv_merchant_id
                    And pm_pay_method = :hv_pay_method; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 3;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select pm_disabled into :b0:b1 from merchant_pay_method Whe\
re pm_merchant_id = :b2 And pm_pay_method = :b3 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_pay_method;
 sqlstm.sqhstl[2] = (unsigned long )6;
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
 if (sqlca.sqlcode < 0) goto find_error;
}



        if (ind_disabled >= 0) {
DEBUGLOG(("FindMerchantPayMethod: pm_disabled = [%d]\n",v_disabled));
                if (v_disabled != PD_DISABLED) {
DEBUGLOG(("FindMerchantPayMethod: return PD_OK [%d]\n", PD_OK));
                        return PD_OK;
		}
                else {
DEBUGLOG(("FindMerchantPayMethod: return PD_ERR [%d]\n", PD_ERR));
                        return PD_ERR;
		}
        }
DEBUGLOG(("FindMerchantPayMethod: [%s][%s] Pay Method not supported\n",csMerchantId,csPayMethod));

        return PD_ERR;
find_error:
DEBUGLOG(("find_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}

int Add(const hash_t *hRec)
{
	char *csTmp;
	int  iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar		hv_pay_method[PD_PAY_METHOD_LEN]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_pay_method;

		int		hv_disabled;
		/* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_merchant_id = -1;
		short		ind_pay_method = -1;
		short		ind_disabled = -1;
		short		ind_create_user = -1;

		short		hv_return_value;
	/* EXEC SQL ENd DECLARE SECTION; */ 


	DEBUGLOG(("Add: Begin\n"));

	if (GetField_CString(hRec, "merchant_id", &csTmp)) {
		hv_merchant_id.len = strlen(csTmp);
		strncpy((char *)hv_merchant_id.arr, csTmp, hv_merchant_id.len);
		ind_merchant_id = 0;
	}
DEBUGLOG(("Add:mechant_id = [%.*s]\n", hv_merchant_id.len, hv_merchant_id.arr));

	if (GetField_CString(hRec, "pay_method", &csTmp)) {
		hv_pay_method.len = strlen(csTmp);
		strncpy((char *)hv_pay_method.arr, csTmp, hv_pay_method.len);
		ind_pay_method = 0;
	}
DEBUGLOG(("Add:pay_method = [%.*s]\n", hv_pay_method.len, hv_pay_method.arr));

	if (GetField_Int(hRec, "disabled", &iTmp)) {
		hv_disabled = iTmp;
		ind_disabled = 0;
	}
DEBUGLOG(("Add:disabled = [%d]\n", hv_disabled));

	if (GetField_CString(hRec, "create_user", &csTmp)) {
		hv_create_user.len = strlen(csTmp);
		strncpy((char *)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user= 0;
	}
DEBUGLOG(("Add:create_user= [%.*s]\n", hv_create_user.len, hv_create_user.arr));

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_merchant_pay_method_insert(
						:hv_merchant_id:ind_merchant_id,
						:hv_pay_method:ind_pay_method,
						:hv_disabled:ind_disabled,
						:hv_create_user:ind_create_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merchant_pay_method_insert ( :\
hv_merchant_id:ind_merchant_id , :hv_pay_method:ind_pay_method , :hv_disabled\
:ind_disabled , :hv_create_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )32;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_pay_method;
 sqlstm.sqhstl[2] = (unsigned long )6;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_pay_method;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_disabled;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[4] = (unsigned long )22;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_create_user;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
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



	DEBUGLOG(("Add:Ret = [%d]\n", hv_return_value));
	if (hv_return_value == SP_OK) {
		DEBUGLOG(("Add:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
		ERRLOG("MerchantPayMethod_Add: SP_OTHER_ERR TxnAbort\n");
		DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
                ERRLOG("MerchantPayMethod_Add: SP_ERR TxnAbort\n");
                DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

add_error:
        DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
        DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;	
	

}


int Update(const hash_t *hRls)
{
	char	*csMerchantId = NULL;
	char	*csPayMethod = NULL;
	char	*csUser = NULL;
	int	iTmp;
	char	*csBuf;


        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar        hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
	csBuf = (char *)malloc(128);

        strcpy((char*)hv_dynstmt.arr,"update merchant_pay_method set pm_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);


        if (GetField_Int(hRls,"disabled",&iTmp)) {
DEBUGLOG(("Update:disabled = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",pm_disabled = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if (GetField_CString(hRls,"update_user",&csUser)) {
DEBUGLOG(("Update:update_user = [%s]\n",csUser));
                strcat((char*)hv_dynstmt.arr, ",pm_update_user = '");
                strcat((char*)hv_dynstmt.arr, csUser);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


        GetField_CString(hRls,"merchant_id",&csMerchantId);
DEBUGLOG(("Update: merchant_id = [%s]\n", csMerchantId));

	GetField_CString(hRls, "pay_method", &csPayMethod);
DEBUGLOG(("Update: pay_method = [%s]\n", csPayMethod));


        strcat((char *)hv_dynstmt.arr, " WHERE pm_merchant_id = '");
        strcat((char *)hv_dynstmt.arr, csMerchantId);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        strcat((char *)hv_dynstmt.arr, " AND pm_pay_method = '");
	strcat((char *)hv_dynstmt.arr, csPayMethod);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);


DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )67;
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
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )86;
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

ERRLOG("MerantantPayMethod:Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
        return PD_INTERNAL_ERR;

}

