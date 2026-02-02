
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
           char  filnam[15];
};
static struct sqlcxp sqlfpn =
{
    14,
    "MerchDetail.pc"
};


static unsigned int sqlctx = 1222699;


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
   unsigned char  *sqhstv[20];
   unsigned long  sqhstl[20];
            int   sqhsts[20];
            short *sqindv[20];
            int   sqinds[20];
   unsigned long  sqharm[20];
   unsigned long  *sqharc[20];
   unsigned short  sqadto[20];
   unsigned short  sqtdso[20];
} sqlstm = {12,20};

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
"select client_id , name , short_name , disabled , status , approximate_fee_\
rate , allow_reserved , release_reserved_period , allow_payout_dup_merch_ref \
, settlement_process_period , ignore_nack , payout_fe_display , success_callb\
ack_url , failure_callback_url , payout_checksum , daily_cap_fe_display , add\
ress , deposit_card_type_opt_enable from merch_detail where merchant_id = :b0\
            ";

 static char *sq0005 = 
"select merchant_id , merch_detail . client_id , name , merch_detail . statu\
s from merch_detail , clients where merch_detail . disabled = :b0 and clients\
 . status = 'O' and merch_detail . client_id = clients . client_id and client\
s . business_type = :b1            ";

 static char *sq0008 = 
"SELECT DEPOSIT_CARD_TYPE_OPT_ENABLE FROM MERCH_DETAIL WHERE MERCHANT_ID = :\
b0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,806,0,6,271,0,0,20,20,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
3,0,0,1,4,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,9,0,0,
1,9,0,0,1,9,0,0,1,3,0,0,1,9,0,0,1,9,0,0,
100,0,0,2,76,0,6,348,0,0,2,2,0,1,0,2,3,0,0,1,9,0,0,
123,0,0,3,395,0,9,468,0,2049,1,1,0,1,0,1,9,0,0,
142,0,0,3,0,0,13,470,0,0,18,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,
4,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,
2,3,0,0,2,9,0,0,2,3,0,0,
229,0,0,3,0,0,15,628,0,0,0,0,0,1,0,
244,0,0,3,0,0,15,640,0,0,0,0,0,1,0,
259,0,0,4,0,0,17,831,0,0,1,1,0,1,0,1,9,0,0,
278,0,0,4,0,0,21,832,0,0,0,0,0,1,0,
293,0,0,5,264,0,9,927,0,2049,2,2,0,1,0,1,3,0,0,1,1,0,0,
316,0,0,5,0,0,13,929,0,0,4,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
347,0,0,5,0,0,15,996,0,0,0,0,0,1,0,
362,0,0,5,0,0,15,1013,0,0,0,0,0,1,0,
377,0,0,6,199,0,4,1035,0,0,3,2,0,1,0,1,9,0,0,2,9,0,0,1,9,0,0,
404,0,0,7,73,0,4,1079,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
427,0,0,4,0,0,17,1158,0,0,1,1,0,1,0,1,9,0,0,
446,0,0,4,0,0,21,1159,0,0,0,0,0,1,0,
461,0,0,8,89,0,9,1202,0,2049,1,1,0,1,0,1,9,0,0,
480,0,0,8,0,0,13,1204,0,0,1,0,0,1,0,2,3,0,0,
499,0,0,8,0,0,15,1220,0,0,0,0,0,1,0,
514,0,0,8,0,0,15,1235,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2010/09/16              Cody Chan
delete key and sha_kay from table		   2011/01/07		   LokMan Chow
Add UpdateMerchantStatus                           2011/09/23              Virginia Yun
Add GetMerchantbyType                              2011/11/21              Virginia Yun
Add GenMerchantId, amend Add 			   2012/01/10	           Virginia Yun
Amend GenMerchantId use INIT_MID		   2012/05/31	           Virginia Yun
Amend UpdateMerchantStatus to handle update
	approximate_fee_rate and name		   2012/06/13	           Virginia Yun
Support allow_reserved, release_reserved_period,
        allow_payout_dup_merch_ref                 2012/08/16              Virginia Yun
Support settlement_process_period		   2012/08/30		   Virginia Yun
Add support_auto_sett, auto_sett_id		   2012/11/06		   LokMan Chow
Add short_name					   2012/12/06		   Stan Poon
Remove merchant_type				   2012/12/11		   LokMan Chow
Add ChkMerchIDExist				   2012/12/28		   Virginia Yun
Add ignore_nack					   2013/01/30		   LokMan Chow
Remove support_auto_sett, auto_sett_id		   2013/05/30		   Stan Poon
Add payout_fe_display				   2013/08/23		   David Wong
Add brand_name				           2013/09/05              Virginia Yun
Add daily_cap_fe_display			   2014/09/10		   Elvis Wong
Add address					   2014/09/30		   Dirk Wong
Add UpdateMerchCardTypeEnable to handle		   2016/09/29              Elvis Wong
	add enable_card_type
Amend UpdateMerchantStatus to handle	
	update enable_card_type
Amend GetMerchant to handle
	get enable_card_type
Add IsCardTypeEnabled to handle
	check enable_card_type
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "MerchDetail.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void MerchDetail(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const hash_t *hMerchDetail)
{
	char            *csTmp;
	//char		cTmp;
	int		iTmp;
	double		dTmp;
	

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar		hv_client_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_client_id;

		/* varchar		hv_name[PD_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_name;

		/* varchar		hv_short_name[PD_MERCH_SHORT_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_short_name;

		int		hv_disabled;
		//char		hv_merchant_type;
		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;

		double		hv_fee_rate;
		/* varchar		hv_status[PD_ACCOUNT_STATUS_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_status;

                int             hv_allow_reserved;
                int             hv_release_reserved_period;
                int             hv_allow_payout_dup_merch_ref;
		int		hv_settlement_process_period;
		int		hv_ignore_nack;
		int		hv_payout_fe_display;
		/* varchar		hv_success_callback_url[PD_URL_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_success_callback_url;

		/* varchar		hv_failure_callback_url[PD_URL_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_failure_callback_url;

		/* varchar		hv_brand_name[PD_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_brand_name;

		int		hv_daily_cap_fe_display;
		/* varchar		hv_address[PD_COMPANY_ADDR_LEN]; */ 
struct { unsigned short len; unsigned char arr[200]; } hv_address;


		short		ind_merchant_id = -1;
		short		ind_client_id = -1;
		short		ind_name = -1;
		short		ind_short_name = -1;
		short		ind_disabled = -1;
		//short		ind_merchant_type = -1;
		short		ind_create_user = -1;
		short		ind_fee_rate = -1;
		short		ind_status = -1;
		short		ind_allow_reserved = -1;
		short		ind_release_reserved_period = -1;
		short		ind_allow_payout_dup_merch_ref = -1;
		short		ind_settlement_process_period = -1;
		short		ind_ignore_nack = -1;
		short		ind_payout_fe_display = -1;
		short		ind_success_callback_url = -1;
		short		ind_failure_callback_url = -1;
		short		ind_brand_name = -1;	
		short		ind_daily_cap_fe_display = -1;
		short		ind_address = -1;

		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



	DEBUGLOG(("Add: Begin\n"));

	if(GetField_CString(hMerchDetail,"merchant_id",&csTmp))
	{
		hv_merchant_id.len = strlen(csTmp);
		strncpy((char *)hv_merchant_id.arr, csTmp, hv_merchant_id.len);
		ind_merchant_id = 0;
	}
DEBUGLOG(("Add:merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	if(GetField_CString(hMerchDetail,"client_id",&csTmp))
	{
		hv_client_id.len = strlen(csTmp);
		strncpy((char *)hv_client_id.arr, csTmp, hv_client_id.len);
		ind_client_id = 0;
	}
DEBUGLOG(("Add:client_id = [%.*s]\n",hv_client_id.len,hv_client_id.arr));

	if(GetField_CString(hMerchDetail,"name",&csTmp))
	{
		hv_name.len = strlen(csTmp);
		strncpy((char *)hv_name.arr, csTmp, hv_name.len);
		ind_name = 0;
	}
DEBUGLOG(("Add:name = [%.*s]\n",hv_name.len,hv_name.arr));

	if(GetField_CString(hMerchDetail,"short_name",&csTmp))
	{
		hv_short_name.len = strlen(csTmp);
		strncpy((char *)hv_short_name.arr, csTmp, hv_short_name.len);
		ind_short_name = 0;
	}
DEBUGLOG(("Add:short_name = [%.*s]\n",hv_short_name.len,hv_short_name.arr));

	if (GetField_Int(hMerchDetail,"disabled", &iTmp)) 
	{
		hv_disabled = iTmp;
		ind_disabled = 0;
	}
DEBUGLOG(("Add:disabled = [%d]\n",hv_disabled));
/*
	if (GetField_Char(hMerchDetail,"merchant_type", &cTmp)) 
	{
		hv_merchant_type = cTmp;
		ind_merchant_type = 0;
DEBUGLOG(("Add:merchant_type = [%c]\n",hv_merchant_type));
	}
*/

	if(GetField_CString(hMerchDetail,"create_user",&csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char *)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
	}
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


	if (GetField_Double(hMerchDetail, "approximate_fee_rate", &dTmp)) 
	{
		hv_fee_rate = dTmp;
		ind_fee_rate = 0;
DEBUGLOG(("Add:fee_rate = [%lf]\n",hv_fee_rate));
	}

	if (GetField_CString(hMerchDetail, "status", &csTmp))
	{
                hv_status.len = strlen(csTmp);
                strncpy((char *)hv_status.arr, csTmp, hv_status.len);
                ind_status = 0;
DEBUGLOG(("Add:status = [%.*s]\n",hv_status.len, hv_status.arr));
	}

	if (GetField_Int(hMerchDetail, "allow_reserved", &iTmp)) 
	{
		hv_allow_reserved = iTmp;
		ind_allow_reserved = 0;
DEBUGLOG(("Add: allow_reserved = [%d]\n", hv_allow_reserved));
	}

        if (GetField_Int(hMerchDetail, "release_reserved_period", &iTmp))
        {
                hv_release_reserved_period = iTmp;
                ind_release_reserved_period = 0;
DEBUGLOG(("Add: release_reserved_period = [%d]\n", hv_release_reserved_period));
        }
	
        if (GetField_Int(hMerchDetail, "allow_payout_dup_merch_ref", &iTmp))
        {
                hv_allow_payout_dup_merch_ref = iTmp;
                ind_allow_payout_dup_merch_ref = 0;
DEBUGLOG(("Add: allow_payout_dup_merch_ref = [%d]\n", hv_allow_payout_dup_merch_ref));
        }
	
        if (GetField_Int(hMerchDetail, "settlement_process_period", &iTmp))
        {
                hv_settlement_process_period = iTmp;
                ind_settlement_process_period = 0;
DEBUGLOG(("Add: settlement_process_period = [%d]\n", hv_settlement_process_period));
        }

        if (GetField_Int(hMerchDetail, "ignore_nack", &iTmp))
        {
                hv_ignore_nack = iTmp;
                ind_ignore_nack = 0;
DEBUGLOG(("Add: ignore_nack = [%d]\n", hv_ignore_nack));
        }

	if (GetField_Int(hMerchDetail, "payout_fe_display", &iTmp))
	{
		hv_payout_fe_display = iTmp;
		ind_payout_fe_display = 0;
DEBUGLOG(("Add: payout_fe_display = [%d]\n", hv_payout_fe_display));
	}

	if (GetField_CString(hMerchDetail, "success_callback_url", &csTmp))
	{
                hv_success_callback_url.len = strlen(csTmp);
                strncpy((char *)hv_success_callback_url.arr, csTmp, hv_success_callback_url.len);
                ind_success_callback_url = 0;
DEBUGLOG(("Add:success_callback_url = [%.*s]\n",hv_success_callback_url.len, hv_success_callback_url.arr));
	}

	if (GetField_CString(hMerchDetail, "failure_callback_url", &csTmp))
	{
                hv_failure_callback_url.len = strlen(csTmp);
                strncpy((char *)hv_failure_callback_url.arr, csTmp, hv_failure_callback_url.len);
                ind_failure_callback_url = 0;
DEBUGLOG(("Add:failure_callback_url = [%.*s]\n",hv_failure_callback_url.len, hv_failure_callback_url.arr));
	}

	if (GetField_CString(hMerchDetail, "brand_name", &csTmp))
	{
                hv_brand_name.len = strlen(csTmp);
                strncpy((char *)hv_brand_name.arr, csTmp, hv_brand_name.len);
                ind_brand_name = 0;
DEBUGLOG(("Add: brand_name = [%.*s]\n",hv_brand_name.len, hv_brand_name.arr));
	}

	if (GetField_Int(hMerchDetail, "daily_cap_fe_display", &iTmp))
	{
		hv_daily_cap_fe_display = iTmp;
		ind_daily_cap_fe_display = 0;
DEBUGLOG(("Add: daily_cap_fe_display = [%d]\n", hv_daily_cap_fe_display));
	}

	if (GetField_CString(hMerchDetail, "address", &csTmp))
	{
		hv_address.len = strlen(csTmp);
		strncpy((char *)hv_address.arr, csTmp, hv_address.len);
		ind_address = 0;
DEBUGLOG(("Add: address = [%.*s]\n",hv_address.len,hv_address.arr));
	}


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_merch_detail_insert(
				:hv_merchant_id:ind_merchant_id,
				:hv_client_id:ind_client_id,
				:hv_name:ind_name,
				:hv_short_name:ind_short_name,
				:hv_disabled:ind_disabled,
				//:hv_merchant_type:ind_merchant_type,
				:hv_fee_rate:ind_fee_rate,
				:hv_status:ind_status,
				:hv_allow_reserved:ind_allow_reserved,
				:hv_release_reserved_period:ind_release_reserved_period,
				:hv_allow_payout_dup_merch_ref:ind_allow_payout_dup_merch_ref,
				:hv_settlement_process_period:ind_settlement_process_period,
				:hv_ignore_nack:ind_ignore_nack,
				:hv_payout_fe_display:ind_payout_fe_display,
				:hv_success_callback_url:ind_success_callback_url,
				:hv_failure_callback_url:ind_failure_callback_url,
                                :hv_brand_name:ind_brand_name,
				:hv_daily_cap_fe_display:ind_daily_cap_fe_display,
				:hv_address:ind_address,
				:hv_create_user:ind_create_user);


	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merch_detail_insert ( :hv_merc\
hant_id:ind_merchant_id , :hv_client_id:ind_client_id , :hv_name:ind_name , :\
hv_short_name:ind_short_name , :hv_disabled:ind_disabled , :hv_fee_rate:ind_f\
ee_rate , :hv_status:ind_status , :hv_allow_reserved:ind_allow_reserved , :hv\
_release_reserved_period:ind_release_reserved_period , :hv_allow_payout_dup_m\
erch_ref:ind_allow_payout_dup_merch_ref , :hv_settlement_process_period:ind_s\
ettlement_process_period , :hv_ignore_nack:ind_ignore_nack , :hv_payout_fe_di\
splay:ind_payout_fe_display , :hv_success_callback_url:ind_success_callback_u\
rl , :hv_failure_callback_url:ind_failure_callback_url , :hv_brand_name:ind_b\
rand_name , :hv_daily_cap_fe_display:ind_daily_cap_fe_display , :hv_address:i\
nd_address , :hv_create_user:ind_create_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_client_id;
 sqlstm.sqhstl[2] = (unsigned long )12;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_client_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_name;
 sqlstm.sqhstl[3] = (unsigned long )52;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_name;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_short_name;
 sqlstm.sqhstl[4] = (unsigned long )22;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_short_name;
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
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_fee_rate;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_fee_rate;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[7] = (unsigned long )4;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_status;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_allow_reserved;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_allow_reserved;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_release_reserved_period;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_release_reserved_period;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_allow_payout_dup_merch_ref;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_allow_payout_dup_merch_ref;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_settlement_process_period;
 sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_settlement_process_period;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_ignore_nack;
 sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_ignore_nack;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_payout_fe_display;
 sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_payout_fe_display;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_success_callback_url;
 sqlstm.sqhstl[14] = (unsigned long )257;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_success_callback_url;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_failure_callback_url;
 sqlstm.sqhstl[15] = (unsigned long )257;
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_failure_callback_url;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_brand_name;
 sqlstm.sqhstl[16] = (unsigned long )52;
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_brand_name;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&hv_daily_cap_fe_display;
 sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&ind_daily_cap_fe_display;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (unsigned char  *)&hv_address;
 sqlstm.sqhstl[18] = (unsigned long )202;
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)&ind_address;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[19] = (unsigned long )22;
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)&ind_create_user;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned long )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
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
		ERRLOG("MerchDetail_Add: SP_OTHER_ERR TxnAbort\n");
		DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
		ERRLOG("MerchDetail_Add: SP_ERR TxnAbort\n");
		DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

add_error:
	DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
	DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;


}




int Delete(const char* merchant_id, const char* name)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO delete_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;


		short	hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



	hv_merchant_id.len = strlen((const char*)merchant_id);
	memcpy(hv_merchant_id.arr,merchant_id,hv_merchant_id.len);
DEBUGLOG(("Delete: merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	/* EXEC SQL EXECUTE
	    BEGIN
		
		:hv_return_value := sp_merch_detail_delete(
				:hv_merchant_id);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merch_detail_delete ( :hv_merc\
hant_id ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )100;
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
 if (sqlca.sqlcode < 0) goto delete_error;
}




	DEBUGLOG(("Delete:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("Delete:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
		ERRLOG("MerchDetail_Delete: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Delete: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
		ERRLOG("MerchDetail_Delete: SP_ERR TxnAbort\n");
DEBUGLOG(("Delete: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

delete_error:
	DEBUGLOG(("delete_error code %d\n", sqlca.sqlcode));
	DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;

}


int GetMerchant(const char* csMerchantID,
                recordset_t* myRec)
{
	int iRet = 0;
                
        hash_t *myHash;
        /* EXEC SQL WHENEVER SQLERROR GOTO getmerchant_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

                        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;


		/* varchar		v_status[PD_ACCOUNT_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_status;

		/* varchar		v_client_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_client_id;

                /* varchar         v_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_name;

		/* varchar		v_short_name[PD_MERCH_SHORT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_short_name;

		int		v_disabled;
		double		v_fee_rate;
		//char		v_type;
                int		v_allow_reserved;
                int             v_release_reserved_period;
                int             v_allow_payout_dup_merch_ref;
		int		v_settlement_process_period;
		int		v_ignore_nack;
		int		v_payout_fe_display;
		/* varchar		v_success_callback_url[PD_URL_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_success_callback_url;

		/* varchar		v_failure_callback_url[PD_URL_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_failure_callback_url;

		int		v_po_checksum;
		int		v_daily_cap_fe_display;
		/* varchar		v_address[PD_COMPANY_ADDR_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_address;

		int		v_enable_card_type;

		short		ind_client_id = -1;
                short           ind_name = -1;
		short		ind_short_name = -1;
		short		ind_disabled = -1;
		short		ind_status = -1;
		short		ind_fee_rate = -1;
		//short		ind_type = -1;
                short	        ind_allow_reserved = -1;
                short	        ind_release_reserved_period = -1;
                short	        ind_allow_payout_dup_merch_ref = -1;
		short		ind_settlement_process_period = -1;
		short		ind_ignore_nack= -1;
		short		ind_payout_fe_display = -1;
		short		ind_success_callback_url = -1;
		short		ind_failure_callback_url = -1;
		short		ind_po_checksum= -1;
		short		ind_daily_cap_fe_display = -1;
		short		ind_address = -1;
		short		ind_enable_card_type = -1;
 
        /* EXEC SQL END DECLARE SECTION; */ 

        
        hv_merchant_id.len = strlen(csMerchantID);
        memcpy(hv_merchant_id.arr,csMerchantID,hv_merchant_id.len);
DEBUGLOG(("GetMerchant merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

        /* EXEC SQL DECLARE c_cursor_getmerchant CURSOR FOR
                select client_id,
		       name,
		       short_name,
		       disabled,
		       status,
		       //merchant_type,
		       approximate_fee_rate,
                       allow_reserved,
                       release_reserved_period,
                       allow_payout_dup_merch_ref,
		       settlement_process_period,
		       ignore_nack,
		       payout_fe_display,
		       success_callback_url,
		       failure_callback_url,
		       payout_checksum,
		       daily_cap_fe_display,
		       address,
		       deposit_card_type_opt_enable
                  from merch_detail 
		 where merchant_id = :hv_merchant_id; */ 



        /* EXEC SQL OPEN c_cursor_getmerchant; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 20;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0003;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )123;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[0] = (unsigned long )17;
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
			:v_client_id:ind_client_id,
			:v_name:ind_name,
			:v_short_name:ind_short_name,
			:v_disabled:ind_disabled,
			:v_status:ind_status,
			//:v_type:ind_type,
			:v_fee_rate:ind_fee_rate,
                        :v_allow_reserved:ind_allow_reserved,
                        :v_release_reserved_period:ind_release_reserved_period,
			:v_allow_payout_dup_merch_ref:ind_allow_payout_dup_merch_ref,
			:v_settlement_process_period:ind_settlement_process_period,
			:v_ignore_nack:ind_ignore_nack,
			:v_payout_fe_display:ind_payout_fe_display,
			:v_success_callback_url:ind_success_callback_url,
			:v_failure_callback_url:ind_failure_callback_url,
			:v_po_checksum:ind_po_checksum,
			:v_daily_cap_fe_display:ind_daily_cap_fe_display,
			:v_address:ind_address,
			:v_enable_card_type:ind_enable_card_type; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 20;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )142;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_client_id;
                sqlstm.sqhstl[0] = (unsigned long )13;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_client_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_name;
                sqlstm.sqhstl[1] = (unsigned long )53;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_name;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_short_name;
                sqlstm.sqhstl[2] = (unsigned long )23;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_short_name;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_disabled;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_disabled;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_status;
                sqlstm.sqhstl[4] = (unsigned long )5;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_status;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_fee_rate;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_fee_rate;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_allow_reserved;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_allow_reserved;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_release_reserved_period;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_release_reserved_period;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_allow_payout_dup_merch_ref;
                sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_allow_payout_dup_merch_ref;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_settlement_process_period;
                sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_settlement_process_period;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_ignore_nack;
                sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_ignore_nack;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_payout_fe_display;
                sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_payout_fe_display;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
                sqlstm.sqhstv[12] = (unsigned char  *)&v_success_callback_url;
                sqlstm.sqhstl[12] = (unsigned long )258;
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_success_callback_url;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
                sqlstm.sqhstv[13] = (unsigned char  *)&v_failure_callback_url;
                sqlstm.sqhstl[13] = (unsigned long )258;
                sqlstm.sqhsts[13] = (         int  )0;
                sqlstm.sqindv[13] = (         short *)&ind_failure_callback_url;
                sqlstm.sqinds[13] = (         int  )0;
                sqlstm.sqharm[13] = (unsigned long )0;
                sqlstm.sqadto[13] = (unsigned short )0;
                sqlstm.sqtdso[13] = (unsigned short )0;
                sqlstm.sqhstv[14] = (unsigned char  *)&v_po_checksum;
                sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[14] = (         int  )0;
                sqlstm.sqindv[14] = (         short *)&ind_po_checksum;
                sqlstm.sqinds[14] = (         int  )0;
                sqlstm.sqharm[14] = (unsigned long )0;
                sqlstm.sqadto[14] = (unsigned short )0;
                sqlstm.sqtdso[14] = (unsigned short )0;
                sqlstm.sqhstv[15] = (unsigned char  *)&v_daily_cap_fe_display;
                sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[15] = (         int  )0;
                sqlstm.sqindv[15] = (         short *)&ind_daily_cap_fe_display;
                sqlstm.sqinds[15] = (         int  )0;
                sqlstm.sqharm[15] = (unsigned long )0;
                sqlstm.sqadto[15] = (unsigned short )0;
                sqlstm.sqtdso[15] = (unsigned short )0;
                sqlstm.sqhstv[16] = (unsigned char  *)&v_address;
                sqlstm.sqhstl[16] = (unsigned long )203;
                sqlstm.sqhsts[16] = (         int  )0;
                sqlstm.sqindv[16] = (         short *)&ind_address;
                sqlstm.sqinds[16] = (         int  )0;
                sqlstm.sqharm[16] = (unsigned long )0;
                sqlstm.sqadto[16] = (unsigned short )0;
                sqlstm.sqtdso[16] = (unsigned short )0;
                sqlstm.sqhstv[17] = (unsigned char  *)&v_enable_card_type;
                sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[17] = (         int  )0;
                sqlstm.sqindv[17] = (         short *)&ind_enable_card_type;
                sqlstm.sqinds[17] = (         int  )0;
                sqlstm.sqharm[17] = (unsigned long )0;
                sqlstm.sqadto[17] = (unsigned short )0;
                sqlstm.sqtdso[17] = (unsigned short )0;
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

/* client_id */
                if (ind_client_id >= 0) {
                        v_client_id.arr[v_client_id.len] = '\0';
                        PutField_CString(myHash,"merchant_client_id",(const char*)v_client_id.arr);
DEBUGLOG(("GetMerchant client_id = [%s]\n",v_client_id.arr));
                }

/* name */
                if (ind_name >= 0) {
                        v_name.arr[v_name.len] = '\0';
                        PutField_CString(myHash,"merchant_name",(const char*)v_name.arr);
DEBUGLOG(("GetMerchant merchant_name = [%s]\n",v_name.arr));
                }

/* short_name */
                if (ind_short_name >= 0) {
                        v_short_name.arr[v_short_name.len] = '\0';
                        PutField_CString(myHash,"merchant_short_name",(const char*)v_short_name.arr);
DEBUGLOG(("GetMerchant merchant_short_name = [%s]\n",v_short_name.arr));
                }

/* disabled */
		if (ind_disabled >= 0) {
                        PutField_Int(myHash,"disabled",v_disabled);
DEBUGLOG(("GetMerchant disabled  = [%d]\n",v_disabled));
		}

/* status */
                if (ind_status >= 0) {
                        v_status.arr[v_status.len] = '\0';
                        PutField_CString(myHash,"status",(const char*)v_status.arr);
DEBUGLOG(("GetMerchant status = [%s]\n",v_status.arr));
                }


/* merchant type
		if (ind_type >= 0) {
			PutField_Char(myHash,"merchant_type",v_type);
DEBUGLOG(("GetMerchant merchant_type = [%c]\n",v_type));
		}	
*/


/* approximate_fee_rate */
		if (ind_fee_rate >= 0) {
                        PutField_Double(myHash,"approximate_fee_rate",v_fee_rate);
DEBUGLOG(("GetMerchant approximate_fee_rate = [%lf]\n",v_fee_rate));
		}

/* allow_reserved */
		if (ind_allow_reserved >= 0) {
                        PutField_Int(myHash,"allow_reserved",v_allow_reserved);
DEBUGLOG(("GetMerchant allow_reserved = [%d]\n",v_allow_reserved));
		}

/* release_reserved_period */
		if (ind_release_reserved_period >= 0) {
                        PutField_Int(myHash,"release_reserved_period", v_release_reserved_period);
DEBUGLOG(("GetMerchant release_reserved_period = [%d]\n",v_release_reserved_period));
		}

/* allow_payout_dup_merch_ref */
		if (ind_allow_payout_dup_merch_ref >= 0) {
                        PutField_Int(myHash,"allow_payout_dup_merch_ref", v_allow_payout_dup_merch_ref);
DEBUGLOG(("GetMerchant allow_payout_dup_merch_ref = [%d]\n",v_allow_payout_dup_merch_ref));
		}

/* settlement_process_period */
		if (ind_settlement_process_period >= 0) {
                        PutField_Int(myHash,"settlment_process_period", v_settlement_process_period);
DEBUGLOG(("GetMerchant settlement_process_period = [%d]\n",v_settlement_process_period));
		}

/* ignore_nack */
		if (ind_ignore_nack >= 0) {
                        PutField_Int(myHash,"ignore_nack", v_ignore_nack);
DEBUGLOG(("GetMerchant ignore_nack = [%d]\n",v_ignore_nack));
		}

/* payout_fe_display */
		if (ind_payout_fe_display >= 0) {
			PutField_Int(myHash, "payout_fe_display", v_payout_fe_display);
DEBUGLOG(("GetMerchant payout_fe_display = [%d]\n", v_payout_fe_display));
		}

/* success_callback_url */
                if (ind_success_callback_url >= 0) {
                        v_success_callback_url.arr[v_success_callback_url.len] = '\0';
                        PutField_CString(myHash, "merchant_success_callback_url", (const char*)v_success_callback_url.arr);
DEBUGLOG(("GetMerchant success_callback_url = [%s]\n", v_success_callback_url.arr));
                }

/* failure_callback_url */
                if (ind_failure_callback_url >= 0) {
                        v_failure_callback_url.arr[v_failure_callback_url.len] = '\0';
                        PutField_CString(myHash, "merchant_failure_callback_url", (const char*)v_failure_callback_url.arr);
DEBUGLOG(("GetMerchant failure_callback_url = [%s]\n", v_failure_callback_url.arr));
                }

/* po_checksum */
                if (ind_po_checksum>= 0) {
                        PutField_Int(myHash, "po_checksum", v_po_checksum);
DEBUGLOG(("GetMerchant payout_checksum = [%d]\n", v_po_checksum));
                }

/* daily_cap_fe_display */
		if (ind_daily_cap_fe_display >= 0) {
			PutField_Int(myHash, "daily_cap_fe_display", v_daily_cap_fe_display);
DEBUGLOG(("GetMerchant daily_cap_fe_display = [%d]\n", v_daily_cap_fe_display));
		}

/* address */
		if (ind_address >= 0) {
			PutField_CString(myHash, "address", (const char*)v_address.arr);
DEBUGLOG(("GetMerchant address = [%s]\n", v_address.arr));
		}

/* enable_card_type */
                if (ind_enable_card_type >= 0) {
                        PutField_Int(myHash, "enable_card_type", v_enable_card_type);
DEBUGLOG(("GetMerchant enable_card_type = [%d]\n", v_enable_card_type));
                }

                RecordSet_Add(myRec,myHash);
		break; //**************** only one now
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getmerchant; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 20;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )229;
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
        sqlstm.arrsiz = 20;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )244;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int UpdateMerchantStatus(const hash_t *hRls)
{
        char*     csTmp;
        char*     csMerchantId;

	char*	  csBuf;
	double	dTmp;
 	int	iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO updatestatus_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar        hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateMerchantStatus: Begin\n"));

        csBuf = (char*) malloc (128);	

        strcpy((char*)hv_dynstmt.arr,"update merch_detail set update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	GetField_CString(hRls,"merchant_id",&csMerchantId);
DEBUGLOG(("UpdateMerchantStatus: merchant_id = [%s]\n", csMerchantId));

/*status */
        if (GetField_CString(hRls,"status",&csTmp)) {
DEBUGLOG(("UpdateMerchantStatus:status = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",status = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* name */
	if (GetField_CString(hRls, "name", &csTmp)) {
DEBUGLOG(("UpdateMerchantStatus:name= [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",name = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* short_name */
	if (GetField_CString(hRls, "short_name", &csTmp)) {
DEBUGLOG(("UpdateMerchantStatus:short_name= [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",short_name = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* approximate_fee_rate*/
        if (GetField_Double(hRls,"approximate_fee_rate",&dTmp)) {
DEBUGLOG(("UpdateMerchantStatus:approximate_fee_rate = [%f]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",approximate_fee_rate = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* allow_reserved */
	if (GetField_Int(hRls, "allow_reserved", &iTmp)) {
DEBUGLOG(("UpdateMerchantStatus:allow_reserved = [%d]\n",iTmp));
		sprintf(csBuf, "%d", iTmp);
                strcat((char*)hv_dynstmt.arr, ", allow_reserved = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* release_reserved_period */
	if (GetField_Int(hRls, "release_reserved_period", &iTmp)) {
DEBUGLOG(("UpdateMerchantStatus:release_reserved_period = [%d]\n",iTmp));
		sprintf(csBuf, "%d", iTmp);
                strcat((char*)hv_dynstmt.arr, ", release_reserved_period = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* allow_pyaout_dup_merch_ref */
	if (GetField_Int(hRls, "allow_payout_dup_merch_ref", &iTmp)) {
DEBUGLOG(("UpdateMerchantStatus:allow_payout_dup_merch_ref = [%d]\n",iTmp));
		sprintf(csBuf, "%d", iTmp);
                strcat((char*)hv_dynstmt.arr, ", allow_payout_dup_merch_ref = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* settlement_process_period */
	if (GetField_Int(hRls, "settlement_process_period", &iTmp)) {
DEBUGLOG(("UpdateMerchantStatus:settlement_process_period = [%d]\n",iTmp));
		sprintf(csBuf, "%d", iTmp);
                strcat((char*)hv_dynstmt.arr, ", settlement_process_period = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* ignore_nack */
	if (GetField_Int(hRls, "ignore_nack", &iTmp)) {
DEBUGLOG(("UpdateMerchantStatus:ignore_nack = [%d]\n",iTmp));
		sprintf(csBuf, "%d", iTmp);
                strcat((char*)hv_dynstmt.arr, ", ignore_nack = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* payout_fe_display */
	if (GetField_Int(hRls, "payout_fe_display", &iTmp)) {
DEBUGLOG(("UpdateMerchantStatus:payout_fe_display = [%d]\n", iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", payout_fe_display = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* success_callback_url */
	if (GetField_CString(hRls, "success_callback_url", &csTmp)) {
DEBUGLOG(("UpdateMerchantStatus:success_callback_url= [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",success_callback_url = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* failure_callback_url */
	if (GetField_CString(hRls, "failure_callback_url", &csTmp)) {
DEBUGLOG(("UpdateMerchantStatus:failure_callback_url= [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",failure_callback_url = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* brand_name */
	if (GetField_CString(hRls, "brand_name", &csTmp)) {
DEBUGLOG(("UpdateMerchantStatus:brand_name = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",brand_name = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* daily_cap_fe_display */
	if (GetField_Int(hRls, "daily_cap_fe_display", &iTmp)) {
DEBUGLOG(("UpdateMerchantStatus:daily_cap_fe_display = [%d]\n", iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", daily_cap_fe_display = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* address */
	if (GetField_CString(hRls, "address", &csTmp)) {
DEBUGLOG(("UpdateMerchantStatus:address = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",address = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* enable_card_type */
        if (GetField_Int(hRls, "enable_card_type", &iTmp)) {
DEBUGLOG(("UpdateMerchantStatus:enable_card_type = [%d]\n", iTmp));
                sprintf(csBuf, "%d", iTmp);
                strcat((char*)hv_dynstmt.arr, ", deposit_card_type_opt_enable = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*update_user*/
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
        
        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 20;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )259;
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
        if (sqlca.sqlcode < 0) goto updatestatus_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 20;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )278;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto updatestatus_error;
}



	FREE_ME(csBuf);

DEBUGLOG(("Update Normal Exit\n"));
        return PD_OK;

updatestatus_error:
DEBUGLOG(("updatestatus_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("MerantDetail_UpdateMerchantStatus: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("UpdateMerchantStatus: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;

}

int GetMerchantByType(const char cType,
                      recordset_t* myRec)
{
	/*int iRet = 0;*/
        int iCnt = 0;
                
	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO getmerchantbytype_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

                        
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

                char            hv_type;
                int             hv_disabled;
		
		//varchar		hv_st_mid[PD_MERCHANT_ID_LEN + 1];

                /* varchar         v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar		v_client_id[PD_CLIENT_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_client_id;

                /* varchar         v_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_name;

		/* varchar		v_status[PD_ACCOUNT_STATUS_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_status;


                short           ind_merchant_id = -1;
		short		ind_client_id = -1;
                short           ind_name = -1;
		short		ind_status = -1;
        
        
	/* EXEC SQL END DECLARE SECTION; */ 

       
        /* 
	hv_merchant_id.len = strlen(csMerchantID);
	memcpy(hv_merchant_id.arr,csMerchantID,hv_merchant_id.len);
DEBUGLOG(("GetMerchantByType merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        */

	hv_type = cType;
DEBUGLOG(("GetMerchantByType type = [%c]\n",hv_type));

        hv_disabled = 0;

/*
	hv_st_mid.len = strlen(csMid);
	memcpy(hv_st_mid.arr, csMid, hv_st_mid.len);
DEBUGLOG(("GetMerchantByType st_mid = [%d][%.*s]\n",hv_st_mid.len,hv_st_mid.len,hv_st_mid.arr));	

        hv_no_of_record = iRtnRecord;
DEBUGLOG(("GetMerchantByType hv_no_of_record = [%d]\n",hv_no_of_record));

*/
        /* EXEC SQL DECLARE c_cursor_getmerchantbytype CURSOR FOR
		/o
		select b.merchant_id,
		       b.client_id,
	               b.name,
		       b.status 
		from (
			select a.*
			  from merch_detail a
			 where a.disabled = :hv_disabled
			   and a.merchant_type = :hv_type
			   and a.merchant_id >= decode(:hv_st_mid, '<NULL>', a.merchant_id, :hv_st_mid) 
			order by a.merchant_id
	             ) b
		where rownum < :hv_no_of_record + 1;
		o/
                        select merchant_id, 
				merch_detail.client_id,
				name,
				merch_detail.status
                          from merch_detail,
				clients
                         where merch_detail.disabled = :hv_disabled
			 and   clients.status = 'O'
			 and   merch_detail.client_id = clients.client_id
                         and   clients.business_type= :hv_type; */ 



	/* EXEC SQL OPEN c_cursor_getmerchantbytype; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0005;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )293;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_type;
 sqlstm.sqhstl[1] = (unsigned long )1;
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
 if (sqlca.sqlcode < 0) goto getmerchantbytype_error;
}


	do {
                /* EXEC SQL FETCH c_cursor_getmerchantbytype
                INTO
			:v_merchant_id:ind_merchant_id,
			:v_client_id:ind_client_id,
			:v_name:ind_name,
			:v_status:ind_status; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 20;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )316;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_merchant_id;
                sqlstm.sqhstl[0] = (unsigned long )18;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_merchant_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_client_id;
                sqlstm.sqhstl[1] = (unsigned long )13;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_client_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_name;
                sqlstm.sqhstl[2] = (unsigned long )53;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_name;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_status;
                sqlstm.sqhstl[3] = (unsigned long )5;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_status;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto getmerchantbytype_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                iCnt++;

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

/* merchant_id */
                if (ind_merchant_id >= 0) {
                        v_merchant_id.arr[v_merchant_id.len] = '\0';
                        PutField_CString(myHash,"merchant_id",(const char*)v_merchant_id.arr);
DEBUGLOG(("GetMerchantByType merchant_id = [%s]\n",v_merchant_id.arr));
                }

/* client_id */
                if (ind_client_id >= 0) {
                        v_client_id.arr[v_client_id.len] = '\0';
                        PutField_CString(myHash,"merchant_client_id",(const char*)v_client_id.arr);
DEBUGLOG(("GetMerchant client_id = [%s]\n",v_client_id.arr));
                }

/* name */
                if (ind_name >= 0) {
                        v_name.arr[v_name.len] = '\0';
                        PutField_CString(myHash,"merchant_name",(const char*)v_name.arr);
DEBUGLOG(("GetMerchant merchant_name = [%s]\n",v_name.arr));
                }


/* disabled */
/*
		if (ind_disabled >= 0) {
                        PutField_Int(myHash,"disabled",v_disabled);
DEBUGLOG(("GetMerchant disabled  = [%d]\n",v_disabled));
		}
*/

/* status */
                if (ind_status >= 0) {
                        v_status.arr[v_status.len] = '\0';
                        PutField_CString(myHash,"status",(const char*)v_status.arr);
DEBUGLOG(("GetMerchant status = [%s]\n",v_status.arr));
                }

/* approximate_fee_rate */
/*
		if (ind_fee_rate >= 0) {
                        PutField_Double(myHash,"approximate_fee_rate",v_fee_rate);
DEBUGLOG(("GetMerchant approximate_fee_rate = [%lf]\n",v_fee_rate));
		}

*/

                RecordSet_Add(myRec,myHash);
		/*break;*/ //**************** only one now
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getmerchantbytype; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 20;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )347;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getmerchantbytype_error;
}



        if (iCnt > 0) {
DEBUGLOG(("GetMerchantByType Normal Exit\n"));
		return PD_OK;
        }
	else {
DEBUGLOG(("GetMerchantByType Normal Exit, Not Found\n"));
		/*return PD_ERR;*/
		return PD_OK;
	}
         

getmerchantbytype_error:
DEBUGLOG(("getmerchantbytype_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getmerchantbytype; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 20;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )362;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int GenMerchantId(char *csMid)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO gen_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_init_mid[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_init_mid;


                /* varchar v_mid[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_mid;

                short   ind_mid = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_init_mid.len = strlen(PD_INIT_MID);
	memcpy(hv_init_mid.arr, PD_INIT_MID, hv_init_mid.len);
DEBUGLOG(("GenMerchantId init_mid = [%d][%.*s]\n",hv_init_mid.len, hv_init_mid.len, hv_init_mid.arr));

        /* EXEC SQL SELECT to_char(NVL(max(to_number(merchant_id)), :hv_init_mid) + 1) merchant_id
                   INTO :v_mid:ind_mid
                FROM merch_detail 
                WHERE length(merchant_id) >= 10
		  AND merchant_id like substr(:hv_init_mid, 1, 1) || '%'; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 20;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select to_char ( NVL ( max ( to_number ( merchant_id\
 ) ) , :b0 ) + 1 ) merchant_id INTO :b1:b2 FROM merch_detail WHERE length ( m\
erchant_id ) >= 10 AND merchant_id like substr ( :b0 , 1 , 1 ) || '%' ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )377;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_init_mid;
        sqlstm.sqhstl[0] = (unsigned long )17;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&v_mid;
        sqlstm.sqhstl[1] = (unsigned long )18;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_mid;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_init_mid;
        sqlstm.sqhstl[2] = (unsigned long )17;
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
        if (sqlca.sqlcode < 0) goto gen_error;
}



        if (ind_mid >= 0) {
                v_mid.arr[v_mid.len] = '\0';
                strcpy((char*)csMid,(const char*)v_mid.arr);

DEBUGLOG(("GenMerchantId mid = [%s]\n", csMid));
                return PD_OK;
        }

DEBUGLOG(("GenMerchantId NOT SUCC\n"));
        return PD_ERR;

gen_error:
DEBUGLOG(("gen_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;

}

int	ChkMerchIDExist(const char *csMID)
{
	int	iRet = PD_NOT_FOUND;

        /* EXEC SQL WHENEVER SQLERROR GOTO chkmerchidexist_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;


                int             v_no_of_record;
                short           ind_no_of_record = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


	hv_merchant_id.len = strlen(csMID);
	memcpy(hv_merchant_id.arr, csMID, hv_merchant_id.len);

DEBUGLOG(("ChkMerchIDExist = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

        /* EXEC SQL
                SELECT count(1)
                   INTO :v_no_of_record:ind_no_of_record
                   FROM merch_detail
                  WHERE merchant_id = :hv_merchant_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 20;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM merch_detail WHE\
RE merchant_id = :b2 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )404;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_no_of_record;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_no_of_record;
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
        if (sqlca.sqlcode < 0) goto chkmerchidexist_error;
}



        if (ind_no_of_record >= 0) {
                if (v_no_of_record > 0) {
DEBUGLOG(("ChkMerchIDExist FOUND\n"));
                        iRet = PD_FOUND;
                }
        }

        if (iRet!= PD_FOUND) {
DEBUGLOG(("ChkMerchIDExist NOT FOUND\n"));
        }

        return iRet;

chkmerchidexist_error:
DEBUGLOG(("ChkMerchIDExist_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 


        return PD_ERR;	

}

int UpdateMerchCardTypeEnable(const hash_t *hRls)
{
        char*     csTmp;
        char*     csMerchantId;

        char*     csBuf;
        int     iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO updatecardtype_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar        hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateMerchCardTypeEnable: Begin\n"));

        csBuf = (char*) malloc (128);

        strcpy((char*)hv_dynstmt.arr,"update merch_detail set update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        GetField_CString(hRls,"merchant_id",&csMerchantId);
DEBUGLOG(("UpdateMerchCardTypeEnable: merchant_id = [%s]\n", csMerchantId));

/* enable_card_type */
        if (GetField_Int(hRls, "enable_card_type", &iTmp)) {
DEBUGLOG(("UpdateMerchCardTypeEnable:enable_card_type = [%d]\n", iTmp));
                sprintf(csBuf, "%d", iTmp);
                strcat((char*)hv_dynstmt.arr, ", deposit_card_type_opt_enable = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*update_user*/
        if(GetField_CString(hRls,"update_user",&csTmp)){
DEBUGLOG(("UpdateMerchCardTypeEnable:update_user = [%s]\n",csTmp));
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

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 20;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )427;
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
        if (sqlca.sqlcode < 0) goto updatecardtype_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 20;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )446;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto updatecardtype_error;
}



        FREE_ME(csBuf);

DEBUGLOG(("Update Normal Exit\n"));
        return PD_OK;

updatecardtype_error:
DEBUGLOG(("updatecardtype_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("MerantDetail_UpdateMerchCardTypeEnable: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("UpdateMerchCardTypeEnable: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;
}

int IsCardTypeEnabled(const char* csMerchantID)
{
	int iRet = PD_FALSE;

        /* EXEC SQL WHENEVER SQLERROR GOTO iscardtypeenabled_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;


		int             v_enable_card_type;	

                short           ind_enable_card_type = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	// merchant_id
	hv_merchant_id.len = strlen(csMerchantID);
        memcpy(hv_merchant_id.arr,csMerchantID,hv_merchant_id.len);
DEBUGLOG(("IsCardTypeEnabled merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	/* EXEC SQL DECLARE c_cursor_iscardtypeenabled CURSOR FOR
                SELECT  DEPOSIT_CARD_TYPE_OPT_ENABLE
                FROM    MERCH_DETAIL
                WHERE   MERCHANT_ID = :hv_merchant_id; */ 

		
        /* EXEC SQL OPEN c_cursor_iscardtypeenabled; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 20;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0008;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )461;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[0] = (unsigned long )17;
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
        if (sqlca.sqlcode < 0) goto iscardtypeenabled_error;
}


	do {
                /* EXEC SQL FETCH c_cursor_iscardtypeenabled
                INTO    
			:v_enable_card_type:ind_enable_card_type; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 20;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )480;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_enable_card_type;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_enable_card_type;
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
                if (sqlca.sqlcode < 0) goto iscardtypeenabled_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

/* enable_card_type */
                if (ind_enable_card_type >= 0) {
DEBUGLOG(("IsCardTypeEnabled() enable_card_type = [%d]\n",v_enable_card_type));
			iRet = v_enable_card_type;
                }

		break;
        } while (PD_TRUE);
        /* EXEC SQL CLOSE c_cursor_iscardtypeenabled; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 20;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )499;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto iscardtypeenabled_error;
}



        if (iRet == PD_TRUE) {
DEBUGLOG(("IsCardTypeEnabled true [%d]\n",iRet));
        } else {
DEBUGLOG(("IsCardTypeEnabled false [%d]\n",iRet));
        }

        return iRet;

iscardtypeenabled_error:
DEBUGLOG(("iscardtypeenabled_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("IsCardTypeEnabled::iscardtypeenabled_error code %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_iscardtypeenabled; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )514;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}

