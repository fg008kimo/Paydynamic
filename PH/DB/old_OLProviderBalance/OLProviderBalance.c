
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
    "OLProviderBalance.pc"
};


static unsigned int sqlctx = 82369779;


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
   unsigned char  *sqhstv[6];
   unsigned long  sqhstl[6];
            int   sqhsts[6];
            short *sqindv[6];
            int   sqinds[6];
   unsigned long  sqharm[6];
   unsigned long  *sqharc[6];
   unsigned short  sqadto[6];
   unsigned short  sqtdso[6];
} sqlstm = {12,6};

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

 static char *sq0004 = 
"select ol_pb_bal , ol_pb_total_hold from ol_provider_balance where ol_pb_pr\
ovider_id = :b0 and ol_pb_currency_id = :b1 and ol_pb_country_id = :b2 for up\
date ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,211,0,6,95,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,9,0,
0,
44,0,0,2,167,0,4,178,0,0,5,3,0,1,0,2,4,0,0,2,4,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
79,0,0,3,206,0,6,277,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,9,
0,0,
118,0,0,4,157,0,9,367,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
145,0,0,4,0,0,13,369,0,0,2,0,0,1,0,2,4,0,0,2,4,0,0,
168,0,0,4,0,0,15,389,0,0,0,0,0,1,0,
183,0,0,4,0,0,15,398,0,0,0,0,0,1,0,
198,0,0,5,178,0,4,440,0,0,5,3,0,1,0,2,4,0,0,2,4,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/10/11              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "OLProviderBalance.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void OLProviderBalance(char    cdebug)
{
        cDebug = cdebug;
}

int UpdateBalance(const char* csPsp,
		const char* csCountryId,
		const char* csCcy,
		const char  cType, 
		double dAmt,
		char* csUpdateUser)
		
{

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_provider_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_provider_id;

		/* varchar		hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		double		hv_balance;
		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



		short		ind_provider_id = -1;
		short		ind_country_id = -1;
		short		ind_ccy_id = -1;
		short		ind_balance = -1;
		short		ind_create_user = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateBalance: Begin\n"));


	hv_provider_id.len = strlen(csPsp);
	strncpy((char*)hv_provider_id.arr, csPsp, hv_provider_id.len);
	ind_provider_id = 0;
DEBUGLOG(("UpdateBalance:provider_id = [%.*s]\n",hv_provider_id.len,hv_provider_id.arr));

	hv_country_id.len = strlen(csCountryId);
	strncpy((char*)hv_country_id.arr, csCountryId, hv_country_id.len);
	ind_country_id = 0;
DEBUGLOG(("UpdateBalance:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

	hv_ccy_id.len = strlen(csCcy);
	strncpy((char*)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
	ind_ccy_id = 0;
DEBUGLOG(("UpdateBalance:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

	if(cType == PD_IND_CREDIT){
		hv_balance= dAmt;
DEBUGLOG(("UpdateBalance:credit balance = [%f]\n",hv_balance));
	}
	else{
		hv_balance= (-1)*dAmt;
DEBUGLOG(("UpdateBalance:debit balance = [%f]\n",(-1)*hv_balance));
	}
	ind_balance= 0;


	hv_create_user.len = strlen(csUpdateUser);
	strncpy((char*)hv_create_user.arr, csUpdateUser, hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("UpdateBalance:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


		/* EXEC SQL EXECUTE
		    BEGIN

			:hv_return_value := sp_ol_provider_bal_update(
				:hv_provider_id:ind_provider_id,
				:hv_country_id:ind_country_id,
				:hv_ccy_id:ind_ccy_id,
				:hv_balance:ind_balance,
				:hv_create_user:ind_create_user);

		    END;
		END-EXEC; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "begin :hv_return_value := sp_ol_provider_bal_update ( :hv_\
provider_id:ind_provider_id , :hv_country_id:ind_country_id , :hv_ccy_id:ind_\
ccy_id , :hv_balance:ind_balance , :hv_create_user:ind_create_user ) ; END ;";
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
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_provider_id;
  sqlstm.sqhstl[1] = (unsigned long )12;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_provider_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
  sqlstm.sqhstl[2] = (unsigned long )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_country_id;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
  sqlstm.sqhstl[3] = (unsigned long )5;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&hv_balance;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_balance;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&hv_create_user;
  sqlstm.sqhstl[5] = (unsigned long )22;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_create_user;
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
  if (sqlca.sqlcode < 0) goto add_error;
}



DEBUGLOG(("UpdateBalance:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("UpdateBalance:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("OLProviderBalance_UpdateBalance: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateBalance: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("OLProviderBalance_UpdateBalance: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateBalance: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLProviderBalance_UpdateBalance: SP_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
	return PD_ERR;


}



int GetBalance(const char* csPspID,
		const char* csCountryId,
		const char* csCurrencyId,
		hash_t *hVal)
{
	int iRet = PD_OK;
                
        /* EXEC SQL WHENEVER SQLERROR GOTO get_bal_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

                        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_provider_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_provider_id;

		/* varchar		hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                
		double		v_balance;
		double		v_total_hold;

		short		ind_balance= -1;
		short		ind_total_hold= -1;
        
        
        /* EXEC SQL END DECLARE SECTION; */ 

        
        hv_provider_id.len = strlen(csPspID);
        memcpy(hv_provider_id.arr,csPspID,hv_provider_id.len);
DEBUGLOG(("GetBalance provider_id = [%.*s]\n",hv_provider_id.len,hv_provider_id.arr));

        hv_country_id.len = strlen(csCountryId);
        memcpy(hv_country_id.arr,csCountryId,hv_country_id.len);
DEBUGLOG(("GetBalance country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));
        
        hv_ccy_id.len = strlen(csCurrencyId);
        memcpy(hv_ccy_id.arr,csCurrencyId,hv_ccy_id.len);
DEBUGLOG(("GetBalance ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));
        
        /* EXEC SQL select	ol_pb_bal,
			ol_pb_total_hold
		 into	:v_balance:ind_balance,
			:v_total_hold:ind_total_hold
                 from	ol_provider_balance
		 where	ol_pb_provider_id = :hv_provider_id
		 and    ol_pb_country_id = :hv_country_id
		 and	ol_pb_currency_id = :hv_ccy_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select ol_pb_bal , ol_pb_total_hold into :b0:b1 , :b\
2:b3 from ol_provider_balance where ol_pb_provider_id = :b4 and ol_pb_country\
_id = :b5 and ol_pb_currency_id = :b6 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )44;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_balance;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_balance;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&v_total_hold;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_total_hold;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_provider_id;
        sqlstm.sqhstl[2] = (unsigned long )12;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_country_id;
        sqlstm.sqhstl[3] = (unsigned long )4;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_ccy_id;
        sqlstm.sqhstl[4] = (unsigned long )5;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
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
        if (sqlca.sqlcode < 0) goto get_bal_error;
}




// balance
        if(ind_balance<0)
		v_balance = 0;
	PutField_Double(hVal,"balance",v_balance);
DEBUGLOG(("GetBalance balance = [%f]\n",v_balance));

        if(ind_total_hold<0)
		v_total_hold = 0;
	PutField_Double(hVal,"total_hold",v_total_hold);
DEBUGLOG(("GetBalance total_hold = [%f]\n",v_total_hold));


DEBUGLOG(("GetBalance Normal Exit\n"));
	return iRet;

get_bal_error:
DEBUGLOG(("get_bal_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLProviderBalance_Get: SP_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}



int UpdateHoldBalance(const char* csPsp,
		const char* csCountryId,
		const char* csCcy,
		char  cType,
		double dAmt,
		char* csUpdateUser)
		
{

	/* EXEC SQL WHENEVER SQLERROR GOTO hold_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_provider_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_provider_id;

		/* varchar		hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		double		hv_hold;
		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



		short		ind_provider_id = -1;
		short		ind_country_id = -1;
		short		ind_ccy_id = -1;
		short		ind_hold = -1;
		short		ind_create_user = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateHoldBalance: Begin\n"));


	hv_provider_id.len = strlen(csPsp);
	strncpy((char*)hv_provider_id.arr, csPsp, hv_provider_id.len);
	ind_provider_id = 0;
DEBUGLOG(("UpdateHoldBalance:provider_id = [%.*s]\n",hv_provider_id.len,hv_provider_id.arr));

	hv_country_id.len = strlen(csCountryId);
	strncpy((char*)hv_country_id.arr, csCountryId, hv_country_id.len);
	ind_country_id = 0;
DEBUGLOG(("UpdateHoldBalance:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

	hv_ccy_id.len = strlen(csCcy);
	strncpy((char*)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
	ind_ccy_id = 0;
DEBUGLOG(("UpdateHoldBalance:ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

	if(cType!=PD_HOLD){
		hv_hold= (-1)*dAmt;
DEBUGLOG(("UpdateHoldBalance:unhold = [%f]\n",(-1)*hv_hold));
	}
	else{
		hv_hold= dAmt;
DEBUGLOG(("UpdateHoldBalance:hold = [%f]\n",hv_hold));
	}
	ind_hold= 0;

	hv_create_user.len = strlen(csUpdateUser);
	strncpy((char*)hv_create_user.arr, csUpdateUser, hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("UpdateHoldBalance:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


		/* EXEC SQL EXECUTE
		    BEGIN

			:hv_return_value := sp_ol_provider_hold_update(
				:hv_provider_id:ind_provider_id,
				:hv_country_id:ind_country_id,
				:hv_ccy_id:ind_ccy_id,
				:hv_hold:ind_hold,
				:hv_create_user:ind_create_user);

		    END;
		END-EXEC; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "begin :hv_return_value := sp_ol_provider_hold_update ( :hv\
_provider_id:ind_provider_id , :hv_country_id:ind_country_id , :hv_ccy_id:ind\
_ccy_id , :hv_hold:ind_hold , :hv_create_user:ind_create_user ) ; END ;";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )79;
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
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_provider_id;
  sqlstm.sqhstl[1] = (unsigned long )12;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_provider_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
  sqlstm.sqhstl[2] = (unsigned long )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_country_id;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
  sqlstm.sqhstl[3] = (unsigned long )5;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&hv_hold;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_hold;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&hv_create_user;
  sqlstm.sqhstl[5] = (unsigned long )22;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_create_user;
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
  if (sqlca.sqlcode < 0) goto hold_error;
}



DEBUGLOG(("UpdateHoldBalance:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("UpdateHoldBalance:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("OLProviderBalance_UpdateHoldBalance: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateHoldBalance: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("OLProviderBalance_UpdateHoldBalance: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateHoldBalance: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

hold_error:
DEBUGLOG(("hold_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLProviderBalance_UpdateHoldBalance: SP_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
	return PD_ERR;


}

int 	GetAvalOLProviderBalance(const char *csPspID,
			const char *csCurrencyId,
			const char *csCountryId,
			double *dBal)
{
        *dBal = 0.0;
        int iRet = PD_OK;

        /* EXEC SQL WHENEVER SQLERROR GOTO getavalbal_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_provider_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_provider_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;


                double          v_current_bal;
                double          v_total_hold;

                short           ind_current_bal= -1;
                short           ind_total_hold= -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_provider_id.len = strlen(csPspID);
        memcpy(hv_provider_id.arr, csPspID, hv_provider_id.len);
DEBUGLOG(("GetAvalOLProviderBalance provider_id = [%.*s]\n",hv_provider_id.len,hv_provider_id.arr));

        hv_ccy_id.len = strlen(csCurrencyId);
        memcpy(hv_ccy_id.arr,csCurrencyId,hv_ccy_id.len);
DEBUGLOG(("GetAvalOLProviderBalance ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

        hv_country_id.len = strlen(csCountryId);
        memcpy(hv_country_id.arr,csCountryId,hv_country_id.len);
DEBUGLOG(("GetAvalOLProviderBalance country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

        /* EXEC SQL DECLARE c_cursor_getavalbal CURSOR FOR
                select  ol_pb_bal,
                        ol_pb_total_hold
                  from ol_provider_balance
                 where ol_pb_provider_id = :hv_provider_id
                   and ol_pb_currency_id = :hv_ccy_id
                   and ol_pb_country_id = :hv_country_id
                 for update; */ 


       /* EXEC SQL OPEN c_cursor_getavalbal; */ 

{
       struct sqlexd sqlstm;
       sqlstm.sqlvsn = 12;
       sqlstm.arrsiz = 6;
       sqlstm.sqladtp = &sqladt;
       sqlstm.sqltdsp = &sqltds;
       sqlstm.stmt = sq0004;
       sqlstm.iters = (unsigned int  )1;
       sqlstm.offset = (unsigned int  )118;
       sqlstm.selerr = (unsigned short)1;
       sqlstm.cud = sqlcud0;
       sqlstm.sqlest = (unsigned char  *)&sqlca;
       sqlstm.sqlety = (unsigned short)4352;
       sqlstm.occurs = (unsigned int  )0;
       sqlstm.sqcmod = (unsigned int )0;
       sqlstm.sqhstv[0] = (unsigned char  *)&hv_provider_id;
       sqlstm.sqhstl[0] = (unsigned long )12;
       sqlstm.sqhsts[0] = (         int  )0;
       sqlstm.sqindv[0] = (         short *)0;
       sqlstm.sqinds[0] = (         int  )0;
       sqlstm.sqharm[0] = (unsigned long )0;
       sqlstm.sqadto[0] = (unsigned short )0;
       sqlstm.sqtdso[0] = (unsigned short )0;
       sqlstm.sqhstv[1] = (unsigned char  *)&hv_ccy_id;
       sqlstm.sqhstl[1] = (unsigned long )5;
       sqlstm.sqhsts[1] = (         int  )0;
       sqlstm.sqindv[1] = (         short *)0;
       sqlstm.sqinds[1] = (         int  )0;
       sqlstm.sqharm[1] = (unsigned long )0;
       sqlstm.sqadto[1] = (unsigned short )0;
       sqlstm.sqtdso[1] = (unsigned short )0;
       sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
       sqlstm.sqhstl[2] = (unsigned long )4;
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
       if (sqlca.sqlcode < 0) goto getavalbal_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getavalbal
                INTO
                        :v_current_bal:ind_current_bal,
                        :v_total_hold:ind_total_hold; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 6;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )145;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_current_bal;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_current_bal;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_total_hold;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_total_hold;
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
                if (sqlca.sqlcode < 0) goto getavalbal_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

// balance
                if((ind_current_bal<0) || (ind_total_hold<0))
                        *dBal = 0.0;

                else{
                        *dBal=v_current_bal-v_total_hold;
DEBUGLOG(("GetAvalOLProviderBalance balance = [%f]\n",*dBal));
                }
	}
	while (PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getavalbal; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )168;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getavalbal_error;
}



DEBUGLOG(("GetAvalOLProviderBalance Normal Exit\n"));
        return iRet;

getavalbal_error:
DEBUGLOG(("getavalbal_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getavalbal; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )183;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        TxnAbort();
        return PD_ERR;
}


int GetBalanceForUpdate(const char* csPspID,
                const char* csCountryId,
                const char* csCurrencyId,
                hash_t *hVal)
{
        int iRet = PD_OK;
    
        /* EXEC SQL WHENEVER SQLERROR GOTO get_bal_update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

    
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_provider_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_provider_id;

                /* varchar         hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

                /* varchar         hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

    
                double          v_balance;
                double          v_total_hold;

                short           ind_balance= -1;
                short           ind_total_hold= -1;
    

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_provider_id.len = strlen(csPspID);
        memcpy(hv_provider_id.arr,csPspID,hv_provider_id.len);
DEBUGLOG(("GetBalanceForUpdate provider_id = [%.*s]\n",hv_provider_id.len,hv_provider_id.arr));

        hv_country_id.len = strlen(csCountryId);
        memcpy(hv_country_id.arr,csCountryId,hv_country_id.len);
DEBUGLOG(("GetBalanceForUpdate country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));

        hv_ccy_id.len = strlen(csCurrencyId);
        memcpy(hv_ccy_id.arr,csCurrencyId,hv_ccy_id.len);
DEBUGLOG(("GetBalanceForUpdate ccy_id = [%.*s]\n",hv_ccy_id.len,hv_ccy_id.arr));

        /* EXEC SQL select ol_pb_bal,
                        ol_pb_total_hold
                 into   :v_balance:ind_balance,
                        :v_total_hold:ind_total_hold
                 from   ol_provider_balance
                 where  ol_pb_provider_id = :hv_provider_id
                 and    ol_pb_country_id = :hv_country_id
                 and    ol_pb_currency_id = :hv_ccy_id
		 for update ; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select ol_pb_bal , ol_pb_total_hold into :b0:b1 , :b\
2:b3 from ol_provider_balance where ol_pb_provider_id = :b4 and ol_pb_country\
_id = :b5 and ol_pb_currency_id = :b6 for update ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )198;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_balance;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_balance;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&v_total_hold;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_total_hold;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_provider_id;
        sqlstm.sqhstl[2] = (unsigned long )12;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_country_id;
        sqlstm.sqhstl[3] = (unsigned long )4;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_ccy_id;
        sqlstm.sqhstl[4] = (unsigned long )5;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
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
        if (sqlca.sqlcode < 0) goto get_bal_update_error;
}




// balance
        if(ind_balance<0)
                v_balance = 0;
        PutField_Double(hVal,"balance",v_balance);
DEBUGLOG(("GetBalanceForUpdate balance = [%f]\n",v_balance));

        if(ind_total_hold<0)
                v_total_hold = 0;
        PutField_Double(hVal,"total_hold",v_total_hold);
DEBUGLOG(("GetBalanceForUpdate total_hold = [%f]\n",v_total_hold));


DEBUGLOG(("GetBalanceForUpdate Normal Exit\n"));
        return iRet;

get_bal_update_error:
DEBUGLOG(("get_bal_update error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLProviderBalance_Get: SP_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


