
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
           char  filnam[19];
};
static struct sqlcxp sqlfpn =
{
    18,
    "ParMerchProfile.pc"
};


static unsigned int sqlctx = 19887267;


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

 static char *sq0002 = 
"select pmp_username , pmp_api_merch_id , pmp_ack_url , pmp_payout_enable , \
pmp_service , pmp_ph_merch_id , client_id from par_merch_profile , merch_deta\
il where pmp_merch_account_nmb = :b0 and pmp_ph_merch_id = merchant_id       \
     ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,357,0,6,143,0,0,10,10,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
60,0,0,2,234,0,9,238,0,2049,1,1,0,1,0,1,9,0,0,
79,0,0,2,0,0,13,240,0,0,7,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,
122,0,0,2,0,0,15,312,0,0,0,0,0,1,0,
137,0,0,2,0,0,15,324,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/05/25              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "ParMerchProfile.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void ParMerchProfile(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const hash_t *hParMerchProfile)
{
	char            *csTmp;
	int		iTmp;

	//char		cTmp;
	//double		dTmp;
	

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merch_account_nmb[PD_MERCH_ACCOUNT_NMB_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_merch_account_nmb;

		/* varchar		hv_company[PD_COMPANY_LEN]; */ 
struct { unsigned short len; unsigned char arr[400]; } hv_company;

		/* varchar		hv_username[PD_USERNAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_username;

		/* varchar		hv_api_merch_id[PD_API_MERCH_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[30]; } hv_api_merch_id;

		/* varchar		hv_ack_url[PD_ACK_URL_LEN]; */ 
struct { unsigned short len; unsigned char arr[200]; } hv_ack_url;

		int		hv_payout_enable;
		/* varchar		hv_service[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service;

		/* varchar		hv_ph_merch_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_ph_merch_id;

		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;

	
		short		ind_merch_account_nmb = -1;
		short		ind_company = -1;
		short		ind_username = -1;
		short		ind_api_merch_id = -1;
		short		ind_ack_url = -1;
		short		ind_payout_enable = -1;
		short		ind_service = -1;
		short		ind_ph_merch_id = -1;
		short		ind_create_user = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



	DEBUGLOG(("Add: Begin\n"));

	if(GetField_CString(hParMerchProfile,"merch_account_nmb",&csTmp))
	{
		hv_merch_account_nmb.len = strlen(csTmp);
		strncpy((char *)hv_merch_account_nmb.arr, csTmp, hv_merch_account_nmb.len);
		ind_merch_account_nmb = 0;
	}
DEBUGLOG(("Add:merch_account_nmb = [%.*s]\n",hv_merch_account_nmb.len,hv_merch_account_nmb.arr));

	if(GetField_CString(hParMerchProfile,"company",&csTmp))
	{
		hv_company.len = strlen(csTmp);
		strncpy((char *)hv_company.arr, csTmp, hv_company.len);
		ind_company = 0;
	}
DEBUGLOG(("Add:company = [%.*s]\n",hv_company.len,hv_company.arr));


	if(GetField_CString(hParMerchProfile,"username",&csTmp))
	{
		hv_username.len = strlen(csTmp);
		strncpy((char *)hv_username.arr, csTmp, hv_username.len);
		ind_username = 0;
	}
DEBUGLOG(("Add:username = [%.*s]\n",hv_username.len,hv_username.arr));

	if(GetField_CString(hParMerchProfile,"api_merch_id",&csTmp))
	{
		hv_api_merch_id.len = strlen(csTmp);
		strncpy((char *)hv_api_merch_id.arr, csTmp, hv_api_merch_id.len);
		ind_api_merch_id= 0;
	}
DEBUGLOG(("Add:api_merch_id = [%.*s]\n",hv_api_merch_id.len,hv_api_merch_id.arr));

	if(GetField_CString(hParMerchProfile,"ack_url",&csTmp))
	{
		hv_ack_url.len = strlen(csTmp);
		strncpy((char *)hv_ack_url.arr, csTmp, hv_ack_url.len);
		ind_ack_url = 0;
	}
DEBUGLOG(("Add:ack_url = [%.*s]\n",hv_ack_url.len,hv_ack_url.arr));

	if (GetField_Int(hParMerchProfile, "payout_enable", &iTmp)) {
		hv_payout_enable = iTmp;
		ind_payout_enable = 0;
	}
DEBUGLOG(("Add:payout_enable = [%d]\n",hv_payout_enable));

	if(GetField_CString(hParMerchProfile,"service",&csTmp))
	{
		hv_service.len = strlen(csTmp);
		strncpy((char *)hv_service.arr, csTmp, hv_service.len);
		ind_service = 0;
	 }
DEBUGLOG(("Add:service = [%.*s]\n",hv_service.len,hv_service.arr));


	if(GetField_CString(hParMerchProfile,"merchant_id",&csTmp))
	{
		hv_ph_merch_id.len = strlen(csTmp);
		strncpy((char *)hv_ph_merch_id.arr, csTmp, hv_ph_merch_id.len);
		ind_ph_merch_id = 0;
	}
DEBUGLOG(("Add:merchant_id = [%.*s]\n",hv_ph_merch_id.len,hv_ph_merch_id.arr));


	if(GetField_CString(hParMerchProfile,"create_user",&csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char *)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
	}
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_par_merch_profile_insert(
				:hv_merch_account_nmb:ind_merch_account_nmb,
				:hv_company:ind_company,
				:hv_username:ind_username,
				:hv_api_merch_id:ind_api_merch_id,
				:hv_ack_url:ind_ack_url,
				:hv_payout_enable:ind_payout_enable,
				:hv_service:ind_service,
				:hv_ph_merch_id:ind_ph_merch_id,
				:hv_create_user:ind_create_user);
	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_par_merch_profile_insert ( :hv\
_merch_account_nmb:ind_merch_account_nmb , :hv_company:ind_company , :hv_user\
name:ind_username , :hv_api_merch_id:ind_api_merch_id , :hv_ack_url:ind_ack_u\
rl , :hv_payout_enable:ind_payout_enable , :hv_service:ind_service , :hv_ph_m\
erch_id:ind_ph_merch_id , :hv_create_user:ind_create_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merch_account_nmb;
 sqlstm.sqhstl[1] = (unsigned long )52;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merch_account_nmb;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_company;
 sqlstm.sqhstl[2] = (unsigned long )402;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_company;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_username;
 sqlstm.sqhstl[3] = (unsigned long )102;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_username;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_api_merch_id;
 sqlstm.sqhstl[4] = (unsigned long )32;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_api_merch_id;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_ack_url;
 sqlstm.sqhstl[5] = (unsigned long )202;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_ack_url;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_payout_enable;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_payout_enable;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_service;
 sqlstm.sqhstl[7] = (unsigned long )5;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_service;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_ph_merch_id;
 sqlstm.sqhstl[8] = (unsigned long )17;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_ph_merch_id;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[9] = (unsigned long )22;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_create_user;
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
		ERRLOG("ParMerchProfile_Add: SP_OTHER_ERR TxnAbort\n");
		DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
		ERRLOG("ParMerchProfile_Add: SP_ERR TxnAbort\n");
		DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

add_error:
	DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
	DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;


}



int GetMerchant(const char* csMerchAccNmb,
                recordset_t* myRec)
{
	int iRet = PD_OK;
                
        hash_t *myHash;
        /* EXEC SQL WHENEVER SQLERROR GOTO getmerchant_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

                        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merch_account_nmb[PD_MERCH_ACCOUNT_NMB_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_merch_account_nmb;


		/* varchar		v_username[PD_USERNAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_username;

		/* varchar		v_api_merch_id[PD_API_MERCH_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_api_merch_id;

		/* varchar		v_ack_url[PD_ACK_URL_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_ack_url;

		int		v_payout_enable;
		/* varchar		v_service[PD_SERVICE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service;

		/* varchar		v_ph_merch_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_ph_merch_id;

		/* varchar		v_client_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_client_id;


		short		ind_username = -1;
                short           ind_api_merch_id = -1;
		short		ind_ack_url = -1;
		short		ind_payout_enable = -1;
		short		ind_service = -1;
		short		ind_ph_merch_id = -1;
		short		ind_client_id = -1;
        
        
        /* EXEC SQL END DECLARE SECTION; */ 

       
	hv_merch_account_nmb.len = strlen(csMerchAccNmb);
        memcpy(hv_merch_account_nmb.arr,csMerchAccNmb,hv_merch_account_nmb.len);
DEBUGLOG(("GetMerchant merch_account_nmb = [%.*s]\n",hv_merch_account_nmb.len,hv_merch_account_nmb.arr));

        /* EXEC SQL DECLARE c_cursor_getmerchant CURSOR FOR
		select	pmp_username,
			pmp_api_merch_id,	
			pmp_ack_url,
			pmp_payout_enable,
			pmp_service,
			pmp_ph_merch_id,
			client_id
                  from par_merch_profile, merch_detail
		 where pmp_merch_account_nmb = :hv_merch_account_nmb
		   and pmp_ph_merch_id = merchant_id; */ 



        /* EXEC SQL OPEN c_cursor_getmerchant; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0002;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )60;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_merch_account_nmb;
        sqlstm.sqhstl[0] = (unsigned long )52;
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
        if (sqlca.sqlcode < 0) goto getmerchant_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getmerchant
                INTO
			:v_username:ind_username,
			:v_api_merch_id:ind_api_merch_id,
			:v_ack_url:ind_ack_url,
			:v_payout_enable:ind_payout_enable,
			:v_service:ind_service,
			:v_ph_merch_id:ind_ph_merch_id,
			:v_client_id:ind_client_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )79;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_username;
                sqlstm.sqhstl[0] = (unsigned long )103;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_username;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_api_merch_id;
                sqlstm.sqhstl[1] = (unsigned long )33;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_api_merch_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_ack_url;
                sqlstm.sqhstl[2] = (unsigned long )203;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_ack_url;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_payout_enable;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_payout_enable;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_service;
                sqlstm.sqhstl[4] = (unsigned long )6;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_service;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_ph_merch_id;
                sqlstm.sqhstl[5] = (unsigned long )18;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_ph_merch_id;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_client_id;
                sqlstm.sqhstl[6] = (unsigned long )13;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_client_id;
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
                if (sqlca.sqlcode < 0) goto getmerchant_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
			iRet = SQL_NOT_FOUND;
                        break;
                }

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

// username 
                if (ind_username >= 0) {
                        v_username.arr[v_username.len] = '\0';
                        PutField_CString(myHash,"username",(const char*)v_username.arr);
DEBUGLOG(("GetMerchant username = [%s]\n",v_username.arr));
                }

// api_merch_id
                if (ind_api_merch_id >= 0) {
                        v_api_merch_id.arr[v_api_merch_id.len] = '\0';
                        PutField_CString(myHash,"api_merch_id",(const char*)v_api_merch_id.arr);
DEBUGLOG(("GetMerchant api_merch_id = [%s]\n",v_api_merch_id.arr));
                }

// ack_url
                if (ind_ack_url >= 0) {
                        v_ack_url.arr[v_ack_url.len] = '\0';
                        PutField_CString(myHash,"ack_url",(const char*)v_ack_url.arr);
DEBUGLOG(("GetMerchant ack_url = [%s]\n",v_ack_url.arr));
                }

// payout_enable	
		if (ind_payout_enable >=0) {
			PutField_Int(myHash, "payout_enable", v_payout_enable);
DEBUGLOG(("GetMerchant payout_enable = [%d]\n", v_payout_enable));
		}

// service
		if (ind_service >= 0) {
                        v_service.arr[v_service.len] = '\0';
                        PutField_CString(myHash,"service",(const char*)v_service.arr);
DEBUGLOG(("GetMerchant service = [%s]\n",v_service.arr));
		}

// merchant_id
		if (ind_ph_merch_id >= 0) {
                        v_ph_merch_id.arr[v_ph_merch_id.len] = '\0';
                        PutField_CString(myHash,"merchant_id",(const char*)v_ph_merch_id.arr);
DEBUGLOG(("GetMerchant ph_merch_id = [%s]\n",v_ph_merch_id.arr));
		}

// client_id
		if (ind_client_id >= 0) {
                        v_client_id.arr[v_client_id.len] = '\0';
                        PutField_CString(myHash,"client_id",(const char*)v_client_id.arr);
DEBUGLOG(("GetMerchant client_id = [%s]\n",v_client_id.arr));
		}


                RecordSet_Add(myRec,myHash);
		break; //**************** only one now
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getmerchant; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )122;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getmerchant_error;
}



	

DEBUGLOG(("GetMerchant Normal Exit\n"));
        if(iRet==0) return  PD_OK;
	else	return iRet;

getmerchant_error:
DEBUGLOG(("getmerchant_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getmerchant; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )137;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


/*
int UpdateMerchantStatus(const hash_t *hRls)
{
        char*     csTmp;
        char*     csMerchantId;

        EXEC SQL WHENEVER SQLERROR GOTO updatestatus_error;
        EXEC SQL WHENEVER NOTFOUND CONTINUE;

        EXEC SQL BEGIN DECLARE SECTION;

                varchar        hv_dynstmt[1024];

        EXEC SQL END DECLARE SECTION;

DEBUGLOG(("UpdateMerchantStatus: Begin\n"));

        strcpy((char*)hv_dynstmt.arr,"update merch_detail set update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	GetField_CString(hRls,"merchant_id",&csMerchantId);
DEBUGLOG(("UpdateMerchantStatus: merchant_id = [%s]\n", csMerchantId));

//status 
        if (GetField_CString(hRls,"status",&csTmp)) {
DEBUGLOG(("UpdateMerchantStatus:status = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",status = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


//update_user
        if(GetField_CString(hRls,"update_user",&csTmp)){
DEBUGLOG(("UpdateMerchantStatus:update_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",update_user= '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        strcat((char *)hv_dynstmt.arr, " WHERE merchant_id = '");
        strcat((char *)hv_dynstmt.arr, csMerchantId);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
        
        EXEC SQL PREPARE PS FROM :hv_dynstmt;
        EXEC SQL EXECUTE PS;


DEBUGLOG(("Update Normal Exit\n"));
        return PD_OK;

updatestatus_error:
DEBUGLOG(("updatestatus_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        EXEC SQL WHENEVER SQLERROR CONTINUE;
ERRLOG("MerantDetail_UpdateMerchantStatus: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("UpdateMerchantStatus: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;

}
*/


