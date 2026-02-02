
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
    "OLMerchDetail.pc"
};


static unsigned int sqlctx = 5056555;


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
   unsigned char  *sqhstv[26];
   unsigned long  sqhstl[26];
            int   sqhsts[26];
            short *sqindv[26];
            int   sqinds[26];
   unsigned long  sqharm[26];
   unsigned long  *sqharc[26];
   unsigned short  sqadto[26];
   unsigned short  sqtdso[26];
} sqlstm = {12,26};

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
"select md_name , md_short_name , md_brand_name , md_disabled , md_client_id\
 , md_approximate_fee_rate , md_status , md_allow_payout_dup_merch_ref , md_s\
ettlement_process_period , md_ignore_nack , md_payout_fe_display , md_deposit\
_request_ver , md_display_other_bank , md_is_more_restricted , md_support_pay\
out_grp , md_txn_auto_expired_days , md_txn_auto_expired_mins , md_stmt_auto_\
expired_days , md_stmt_auto_expired_mins , md_payout_checksum , md_address , \
md_allow_reserved , md_release_reserved_period from ol_merch_detail where md_\
merchant_id = :b0            ";

 static char *sq0007 = 
"select md_merchant_id , md_client_id , md_status , md_disabled from ol_merc\
h_detail where md_short_name = :b0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,1117,0,6,281,0,0,26,26,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
3,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,9,0,
0,1,9,0,0,
124,0,0,2,79,0,6,357,0,0,2,2,0,1,0,2,3,0,0,1,9,0,0,
147,0,0,3,566,0,9,487,0,2049,1,1,0,1,0,1,9,0,0,
166,0,0,3,0,0,13,489,0,0,23,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,
4,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,9,0,0,2,3,0,0,2,3,0,0,
273,0,0,3,0,0,15,673,0,0,0,0,0,1,0,
288,0,0,3,0,0,15,688,0,0,0,0,0,1,0,
303,0,0,4,186,0,4,714,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
326,0,0,5,0,0,17,977,0,0,1,1,0,1,0,1,9,0,0,
345,0,0,5,0,0,21,978,0,0,0,0,0,1,0,
360,0,0,6,79,0,4,1014,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
383,0,0,7,121,0,9,1081,0,2049,1,1,0,1,0,1,9,0,0,
402,0,0,7,0,0,13,1083,0,0,4,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,
433,0,0,7,0,0,15,1132,0,0,0,0,0,1,0,
448,0,0,7,0,0,15,1150,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/08/27              [SWK]
Add ChkOLMerchIDExist				   2013/09/10		   [MSN]
Add MD_DEPOSIT_REQUEST_VER                         2013/10/09              [STP]
Add address					   2014/10/03		   [WWK]
Add GetMerchByShortName				   2020/06/08		   [MIC]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "OLMerchDetail.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char    cDebug;

void OLMerchDetail(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const hash_t *hOLMerchDetail)
{
	char	*csTmp;
	int	iTmp;
	double	dTmp;
	
	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar		hv_name[PD_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_name;

		/* varchar		hv_short_name[PD_MERCH_SHORT_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_short_name;

		/* varchar         hv_brand_name[PD_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_brand_name;

		int		hv_disabled;
		/* varchar		hv_client_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_client_id;

		double		hv_approximate_fee_rate;
		/* varchar		hv_status[PD_ACCOUNT_STATUS_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_status;

		int		hv_allow_reserved;
		int		hv_release_reserved_period;
		int		hv_allow_payout_dup_merch_ref;
		int		hv_settlement_process_period;
		int		hv_ignore_nack;
		int		hv_payout_fe_display;
		int		hv_deposit_req_ver;
		int		hv_display_other_bank;
		int		hv_is_more_restricted;
		int		hv_support_payout_grp;
		int		hv_txn_auto_expired_days;
		int		hv_txn_auto_expired_mins;
		int		hv_stmt_auto_expired_days;
		int		hv_stmt_auto_expired_mins;
		int		hv_po_checksum;
		/* varchar		hv_address[PD_COMPANY_ADDR_LEN]; */ 
struct { unsigned short len; unsigned char arr[200]; } hv_address;

		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_merchant_id = -1;
		short		ind_name = -1;
		short		ind_short_name = -1;
		short		ind_brand_name = -1;
		short		ind_disabled = -1;
		short		ind_client_id = -1;
		short		ind_approximate_fee_rate = -1;
		short		ind_status = -1;
		short		ind_allow_reserved = -1;
		short		ind_release_reserved_period = -1;
		short		ind_allow_payout_dup_merch_ref = -1;
		short		ind_settlement_process_period = -1;
		short		ind_ignore_nack = -1;
		short		ind_payout_fe_display = -1;
		short		ind_deposit_req_ver = -1;
		short		ind_display_other_bank = -1;
		short		ind_is_more_restricted = -1;
		short		ind_support_payout_grp;
		short		ind_txn_auto_expired_days = -1;
		short		ind_txn_auto_expired_mins = -1;
		short		ind_stmt_auto_expired_days = -1;
		short		ind_stmt_auto_expired_mins = -1;
		short		ind_po_checksum = -1;
		short		ind_address = -1;
		short		ind_create_user = -1;

		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

	if(GetField_CString(hOLMerchDetail,"merchant_id",&csTmp))
	{
		hv_merchant_id.len = strlen(csTmp);
		strncpy((char *)hv_merchant_id.arr, csTmp, hv_merchant_id.len);
		ind_merchant_id = 0;
DEBUGLOG(("Add:merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
	}

	if(GetField_CString(hOLMerchDetail,"name",&csTmp))
	{
		hv_name.len = strlen(csTmp);
		strncpy((char *)hv_name.arr, csTmp, hv_name.len);
		ind_name = 0;
DEBUGLOG(("Add:name = [%.*s]\n",hv_name.len,hv_name.arr));
	}

	if(GetField_CString(hOLMerchDetail,"short_name",&csTmp))
	{
		hv_short_name.len = strlen(csTmp);
		strncpy((char *)hv_short_name.arr, csTmp, hv_short_name.len);
		ind_short_name = 0;
DEBUGLOG(("Add:short_name = [%.*s]\n",hv_short_name.len,hv_short_name.arr));
	}

	if(GetField_CString(hOLMerchDetail,"brand_name",&csTmp))
	{
		hv_brand_name.len = strlen(csTmp);
		strncpy((char *)hv_brand_name.arr, csTmp, hv_brand_name.len);
		ind_brand_name = 0;
DEBUGLOG(("Add:brand_name = [%.*s]\n",hv_brand_name.len,hv_brand_name.arr));
	}

	if (GetField_Int(hOLMerchDetail,"disabled", &iTmp)) 
	{
		hv_disabled = iTmp;
		ind_disabled = 0;
DEBUGLOG(("Add:disabled = [%d]\n",hv_disabled));
	}

	if(GetField_CString(hOLMerchDetail,"client_id",&csTmp))
	{
		hv_client_id.len = strlen(csTmp);
		strncpy((char *)hv_client_id.arr, csTmp, hv_client_id.len);
		ind_client_id = 0;
DEBUGLOG(("Add:client_id = [%.*s]\n",hv_client_id.len,hv_client_id.arr));
	}

	if (GetField_Double(hOLMerchDetail, "approximate_fee_rate", &dTmp)) 
	{
		hv_approximate_fee_rate = dTmp;
		ind_approximate_fee_rate = 0;
DEBUGLOG(("Add:fee_rate = [%lf]\n",hv_approximate_fee_rate));
	}

	if (GetField_CString(hOLMerchDetail, "status", &csTmp))
	{
		hv_status.len = strlen(csTmp);
		strncpy((char *)hv_status.arr, csTmp, hv_status.len);
		ind_status = 0;
DEBUGLOG(("Add:status = [%.*s]\n",hv_status.len, hv_status.arr));
	}

	if (GetField_Int(hOLMerchDetail, "allow_reserved", &iTmp))
	{
		hv_allow_reserved = iTmp;
		ind_allow_reserved = 0;
DEBUGLOG(("Add:allow_reserved = [%d]\n",hv_allow_reserved));
	}

	if (GetField_Int(hOLMerchDetail, "release_reserved_period", &iTmp))
	{
		hv_release_reserved_period = iTmp;
		ind_release_reserved_period = 0;
DEBUGLOG(("Add:release_reserved_period = [%d]\n",hv_release_reserved_period));
	}

	if (GetField_Int(hOLMerchDetail, "allow_payout_dup_merch_ref", &iTmp))
	{
		hv_allow_payout_dup_merch_ref = iTmp;
		ind_allow_payout_dup_merch_ref = 0;
DEBUGLOG(("Add: allow_payout_dup_merch_ref = [%d]\n", hv_allow_payout_dup_merch_ref));
	}


	if (GetField_Int(hOLMerchDetail, "settlement_process_period", &iTmp))
	{
		hv_settlement_process_period = iTmp;
		ind_settlement_process_period = 0;
DEBUGLOG(("Add: settlement_process_period = [%d]\n", hv_settlement_process_period));
	}

	if (GetField_Int(hOLMerchDetail, "ignore_nack", &iTmp))
	{
		hv_ignore_nack = iTmp;
		ind_ignore_nack = 0;
DEBUGLOG(("Add: ignore_nack = [%d]\n", hv_ignore_nack));
	}

	if (GetField_Int(hOLMerchDetail, "payout_fe_display", &iTmp))
	{
		hv_payout_fe_display = iTmp;
		ind_payout_fe_display = 0;
DEBUGLOG(("Add: payout_fe_display = [%d]\n", hv_payout_fe_display));
	}

	if (GetField_Int(hOLMerchDetail, "deposit_req_ver", &iTmp))
	{
		hv_deposit_req_ver = iTmp;
		ind_deposit_req_ver = 0;
DEBUGLOG(("Add: deposit_req_ver = [%d]\n", hv_deposit_req_ver));
	}

	if (GetField_Int(hOLMerchDetail, "display_other_bank", &iTmp))
	{
		hv_display_other_bank = iTmp;
		ind_display_other_bank = 0;
DEBUGLOG(("Add: display_other_bank = [%d]\n", hv_display_other_bank));
	}

	if (GetField_Int(hOLMerchDetail, "is_more_restricted", &iTmp))
	{
		hv_is_more_restricted = iTmp;
		ind_is_more_restricted = 0;
DEBUGLOG(("Add: is_more_restricted = [%d]\n", hv_is_more_restricted));
	}

	if (GetField_Int(hOLMerchDetail, "support_payout_grp", &iTmp))
	{
		hv_support_payout_grp = iTmp;
		ind_support_payout_grp = 0;
DEBUGLOG(("Add: support_payout_grp = [%d]\n", hv_support_payout_grp));
	}

	if (GetField_Int(hOLMerchDetail, "txn_auto_expired_days", &iTmp)) {
		hv_txn_auto_expired_days = iTmp;
		ind_txn_auto_expired_days = 0;
DEBUGLOG(("Add: txn_auto_expired_days = [%d]\n", hv_txn_auto_expired_days));
	}

	if (GetField_Int(hOLMerchDetail, "txn_auto_expired_mins", &iTmp)) {
		hv_txn_auto_expired_mins = iTmp;
		ind_txn_auto_expired_mins = 0;
DEBUGLOG(("Add: txn_auto_expired_mins = [%d]\n", hv_txn_auto_expired_mins));
	}

	if (GetField_Int(hOLMerchDetail, "stmt_auto_expired_days", &iTmp)) {
		hv_stmt_auto_expired_days = iTmp;
		ind_stmt_auto_expired_days = 0;
DEBUGLOG(("Add: stmt_auto_expired_days = [%d]\n", hv_stmt_auto_expired_days));
	}

	if (GetField_Int(hOLMerchDetail, "stmt_auto_expired_mins", &iTmp)) {
		hv_stmt_auto_expired_mins = iTmp;
		ind_stmt_auto_expired_mins = 0;
DEBUGLOG(("Add: stmt_auto_expired_mins = [%d]\n", hv_stmt_auto_expired_mins));
	}

	if (GetField_Int(hOLMerchDetail, "po_checksum", &iTmp))
	{
		hv_po_checksum= iTmp;
		ind_po_checksum= 0;
DEBUGLOG(("Add: payout_checksum = [%d]\n", hv_po_checksum));
	}

	if (GetField_CString(hOLMerchDetail, "address", &csTmp))
	{
		hv_address.len = strlen(csTmp);
		strncpy((char *)hv_address.arr, csTmp, hv_address.len);
		ind_address = 0;
DEBUGLOG(("Add: address = [%s]\n", hv_address));
	}

	if(GetField_CString(hOLMerchDetail,"create_user",&csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char *)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));
	}

	/* EXEC SQL EXECUTE
		BEGIN

		:hv_return_value := sp_ol_merch_detail_insert(
				:hv_merchant_id:ind_merchant_id,
				:hv_name:ind_name,
				:hv_short_name:ind_short_name,
				:hv_brand_name:ind_brand_name,
				:hv_disabled:ind_disabled,
				:hv_client_id:ind_client_id,
				:hv_approximate_fee_rate:ind_approximate_fee_rate,
				:hv_status:ind_status,
				:hv_allow_payout_dup_merch_ref:ind_allow_payout_dup_merch_ref,
				:hv_settlement_process_period:ind_settlement_process_period,
				:hv_ignore_nack:ind_ignore_nack,
				:hv_payout_fe_display:ind_payout_fe_display,
				:hv_deposit_req_ver:ind_deposit_req_ver,
				:hv_display_other_bank:ind_display_other_bank,
				:hv_is_more_restricted:ind_is_more_restricted,
				:hv_support_payout_grp:ind_support_payout_grp,
				:hv_txn_auto_expired_days:ind_txn_auto_expired_days,
				:hv_txn_auto_expired_mins:ind_txn_auto_expired_mins,
				:hv_stmt_auto_expired_days:ind_stmt_auto_expired_days,
				:hv_stmt_auto_expired_mins:ind_stmt_auto_expired_mins,
				:hv_allow_reserved:ind_allow_reserved,
				:hv_release_reserved_period:ind_release_reserved_period,
				:hv_po_checksum:ind_po_checksum,
				:hv_address:ind_address,
				:hv_create_user:ind_create_user);
	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 26;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "begin :hv_return_value := sp_ol_merch_detail_insert ( :hv_merchant_id:in\
d_merchant_id , :hv_name:ind_name , :hv_short_name:ind_short_name , :hv_bran\
d_name:ind_brand_name , :hv_disabled:ind_disabled , :hv_client_id:ind_client\
_id , :hv_approximate_fee_rate:ind_approximate_fee_rate , :hv_status:ind_sta\
tus , :hv_allow_payout_dup_merch_ref:ind_allow_payout_dup_merch_ref , :hv_se\
ttlement_process_period:ind_settlement_process_period , :hv_ignore_nack:ind_\
ignore_nack , :hv_payout_fe_display:ind_payout_fe_display , :hv_deposit_req_\
ver:ind_deposit_req_ver , :hv_display_other_bank:ind_display_other_bank , :h\
v_is_more_restricted:ind_is_more_restricted , :hv_support_payout_grp:ind_sup\
port_payout_grp , :hv_txn_auto_expired_days:ind_txn_auto_expired_days , :hv_\
txn_auto_expired_mins:ind_txn_auto_expired_mins , :hv_stmt_auto_expired_days\
:ind_stmt_auto_expired_days , :hv_stmt_auto_expired_mins:ind_stmt_auto_expir\
ed_mins , :hv_allow_reserved:ind_allow_reserved , :hv_release_reserved_perio\
d:ind_release_reserved_period , :hv_po_c");
 sqlstm.stmt = "hecksum:ind_po_checksum , :hv_address:ind_address , :hv_cre\
ate_user:ind_create_user ) ; END ;";
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_name;
 sqlstm.sqhstl[2] = (unsigned long )52;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_name;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_short_name;
 sqlstm.sqhstl[3] = (unsigned long )22;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_short_name;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_brand_name;
 sqlstm.sqhstl[4] = (unsigned long )52;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_brand_name;
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
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_client_id;
 sqlstm.sqhstl[6] = (unsigned long )12;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_client_id;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_approximate_fee_rate;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_approximate_fee_rate;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[8] = (unsigned long )4;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_status;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_allow_payout_dup_merch_ref;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_allow_payout_dup_merch_ref;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_settlement_process_period;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_settlement_process_period;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_ignore_nack;
 sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_ignore_nack;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_payout_fe_display;
 sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_payout_fe_display;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_deposit_req_ver;
 sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_deposit_req_ver;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_display_other_bank;
 sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_display_other_bank;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_is_more_restricted;
 sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_is_more_restricted;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_support_payout_grp;
 sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_support_payout_grp;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&hv_txn_auto_expired_days;
 sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&ind_txn_auto_expired_days;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (unsigned char  *)&hv_txn_auto_expired_mins;
 sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)&ind_txn_auto_expired_mins;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (unsigned char  *)&hv_stmt_auto_expired_days;
 sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)&ind_stmt_auto_expired_days;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned long )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (unsigned char  *)&hv_stmt_auto_expired_mins;
 sqlstm.sqhstl[20] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[20] = (         int  )0;
 sqlstm.sqindv[20] = (         short *)&ind_stmt_auto_expired_mins;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned long )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (unsigned char  *)&hv_allow_reserved;
 sqlstm.sqhstl[21] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[21] = (         int  )0;
 sqlstm.sqindv[21] = (         short *)&ind_allow_reserved;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned long )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
 sqlstm.sqhstv[22] = (unsigned char  *)&hv_release_reserved_period;
 sqlstm.sqhstl[22] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[22] = (         int  )0;
 sqlstm.sqindv[22] = (         short *)&ind_release_reserved_period;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned long )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
 sqlstm.sqhstv[23] = (unsigned char  *)&hv_po_checksum;
 sqlstm.sqhstl[23] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[23] = (         int  )0;
 sqlstm.sqindv[23] = (         short *)&ind_po_checksum;
 sqlstm.sqinds[23] = (         int  )0;
 sqlstm.sqharm[23] = (unsigned long )0;
 sqlstm.sqadto[23] = (unsigned short )0;
 sqlstm.sqtdso[23] = (unsigned short )0;
 sqlstm.sqhstv[24] = (unsigned char  *)&hv_address;
 sqlstm.sqhstl[24] = (unsigned long )202;
 sqlstm.sqhsts[24] = (         int  )0;
 sqlstm.sqindv[24] = (         short *)&ind_address;
 sqlstm.sqinds[24] = (         int  )0;
 sqlstm.sqharm[24] = (unsigned long )0;
 sqlstm.sqadto[24] = (unsigned short )0;
 sqlstm.sqtdso[24] = (unsigned short )0;
 sqlstm.sqhstv[25] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[25] = (unsigned long )22;
 sqlstm.sqhsts[25] = (         int  )0;
 sqlstm.sqindv[25] = (         short *)&ind_create_user;
 sqlstm.sqinds[25] = (         int  )0;
 sqlstm.sqharm[25] = (unsigned long )0;
 sqlstm.sqadto[25] = (unsigned short )0;
 sqlstm.sqtdso[25] = (unsigned short )0;
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
		ERRLOG("OLMerchDetail_Add: SP_OTHER_ERR TxnAbort\n");
		DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
		ERRLOG("OLMerchDetail_Add: SP_ERR TxnAbort\n");
		DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLMerchDetail_Add: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int Delete(const char* merchant_id)
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
		:hv_return_value := sp_ol_merch_detail_delete(
				:hv_merchant_id);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 26;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_merch_detail_delete ( :hv_m\
erchant_id ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )124;
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
		ERRLOG("OLMerchDetail_Delete: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Delete: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
		ERRLOG("OLMerchDetail_Delete: SP_ERR TxnAbort\n");
DEBUGLOG(("Delete: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

delete_error:
DEBUGLOG(("delete_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLMerchDetail_Delete: SP_INTERNAL_ERR TxnAbort\n");
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

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;


		/* varchar		v_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_name;

		/* varchar		v_short_name[PD_MERCH_SHORT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_short_name;

		/* varchar		v_brand_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_brand_name;

		int		v_disabled;
		/* varchar		v_client_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_client_id;

		double		v_approximate_fee_rate;
		/* varchar		v_status[PD_ACCOUNT_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_status;

		int		v_allow_payout_dup_merch_ref;
		int		v_settlement_process_period;
		int		v_ignore_nack;
		int		v_payout_fe_display;
		int		v_deposit_req_ver;
		int		v_display_other_bank;
		int		v_is_more_restricted;
		int		v_support_payout_grp;
		int		v_txn_auto_expired_days;
		int		v_txn_auto_expired_mins;
		int		v_stmt_auto_expired_days;
		int		v_stmt_auto_expired_mins;
		int		v_po_checksum;
		/* varchar		v_address[PD_COMPANY_ADDR_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_address;

		int		v_allow_reserved;
		int		v_release_reserved_period;

		short		ind_name = -1;
		short		ind_short_name = -1;
		short		ind_brand_name = -1;
		short		ind_disabled = -1;
		short		ind_client_id = -1;
		short		ind_approximate_fee_rate = -1;
		short		ind_status = -1;
		short		ind_allow_payout_dup_merch_ref = -1;
		short		ind_settlement_process_period = -1;
		short		ind_ignore_nack= -1;
		short		ind_payout_fe_display = -1;
		short		ind_deposit_req_ver= -1;
		short		ind_display_other_bank = -1;
		short		ind_is_more_restricted = -1;
		short		ind_support_payout_grp= -1;
		short		ind_txn_auto_expired_days = -1;
		short		ind_txn_auto_expired_mins = -1;
		short		ind_stmt_auto_expired_days = -1;
		short		ind_stmt_auto_expired_mins = -1;
		short		ind_address = -1;
		short		ind_po_checksum = -1;
		short		ind_allow_reserved = -1;
		short		ind_release_reserved_period = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_merchant_id.len = strlen(csMerchantID);
	memcpy(hv_merchant_id.arr,csMerchantID,hv_merchant_id.len);
DEBUGLOG(("GetMerchant merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	/* EXEC SQL DECLARE c_cursor_getmerchant CURSOR FOR
		select	md_name, 
			md_short_name,
			md_brand_name,
			md_disabled,
			md_client_id,
			md_approximate_fee_rate,
			md_status,
			md_allow_payout_dup_merch_ref,
			md_settlement_process_period,
			md_ignore_nack,
			md_payout_fe_display,
			md_deposit_request_ver,
			md_display_other_bank,
			md_is_more_restricted,
			md_support_payout_grp,
			md_txn_auto_expired_days,
			md_txn_auto_expired_mins,
			md_stmt_auto_expired_days,
			md_stmt_auto_expired_mins,
			md_payout_checksum,
			md_address,
			md_allow_reserved,
			md_release_reserved_period
		from ol_merch_detail 
		where md_merchant_id = :hv_merchant_id; */ 


	/* EXEC SQL OPEN c_cursor_getmerchant; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 26;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )147;
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
			:v_name:ind_name,
			:v_short_name:ind_short_name,
			:v_brand_name:ind_brand_name,
			:v_disabled:ind_disabled,
			:v_client_id:ind_client_id,
			:v_approximate_fee_rate:ind_approximate_fee_rate,
			:v_status:ind_status,
			:v_allow_payout_dup_merch_ref:ind_allow_payout_dup_merch_ref,
			:v_settlement_process_period:ind_settlement_process_period,
			:v_ignore_nack:ind_ignore_nack,
			:v_payout_fe_display:ind_payout_fe_display,
			:v_deposit_req_ver:ind_deposit_req_ver,
			:v_display_other_bank:ind_display_other_bank,
			:v_is_more_restricted:ind_is_more_restricted,
			:v_support_payout_grp:ind_support_payout_grp,
			:v_txn_auto_expired_days:ind_txn_auto_expired_days,
			:v_txn_auto_expired_mins:ind_txn_auto_expired_mins,
			:v_stmt_auto_expired_days:ind_stmt_auto_expired_days,
			:v_stmt_auto_expired_mins:ind_stmt_auto_expired_mins,
			:v_po_checksum:ind_po_checksum,
			:v_address:ind_address,
			:v_allow_reserved:ind_allow_reserved,
			:v_release_reserved_period:ind_release_reserved_period; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 26;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )166;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_name;
  sqlstm.sqhstl[0] = (unsigned long )53;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_name;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_short_name;
  sqlstm.sqhstl[1] = (unsigned long )23;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_short_name;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_brand_name;
  sqlstm.sqhstl[2] = (unsigned long )53;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_brand_name;
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
  sqlstm.sqhstv[4] = (unsigned char  *)&v_client_id;
  sqlstm.sqhstl[4] = (unsigned long )13;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_client_id;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_approximate_fee_rate;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_approximate_fee_rate;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[6] = (unsigned long )5;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_status;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_allow_payout_dup_merch_ref;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_allow_payout_dup_merch_ref;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_settlement_process_period;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_settlement_process_period;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_ignore_nack;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_ignore_nack;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_payout_fe_display;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_payout_fe_display;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_deposit_req_ver;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_deposit_req_ver;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_display_other_bank;
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_display_other_bank;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_is_more_restricted;
  sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_is_more_restricted;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_support_payout_grp;
  sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_support_payout_grp;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_txn_auto_expired_days;
  sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_txn_auto_expired_days;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&v_txn_auto_expired_mins;
  sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)&ind_txn_auto_expired_mins;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)&v_stmt_auto_expired_days;
  sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)&ind_stmt_auto_expired_days;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)&v_stmt_auto_expired_mins;
  sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[18] = (         int  )0;
  sqlstm.sqindv[18] = (         short *)&ind_stmt_auto_expired_mins;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)&v_po_checksum;
  sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[19] = (         int  )0;
  sqlstm.sqindv[19] = (         short *)&ind_po_checksum;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)&v_address;
  sqlstm.sqhstl[20] = (unsigned long )203;
  sqlstm.sqhsts[20] = (         int  )0;
  sqlstm.sqindv[20] = (         short *)&ind_address;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)&v_allow_reserved;
  sqlstm.sqhstl[21] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[21] = (         int  )0;
  sqlstm.sqindv[21] = (         short *)&ind_allow_reserved;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)&v_release_reserved_period;
  sqlstm.sqhstl[22] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[22] = (         int  )0;
  sqlstm.sqindv[22] = (         short *)&ind_release_reserved_period;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
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

/* brand_name */
		if (ind_brand_name >= 0) {
			v_brand_name.arr[v_brand_name.len] = '\0';
			PutField_CString(myHash,"merchant_brand_name",(const char*)v_brand_name.arr);
DEBUGLOG(("GetMerchant merchant_brand_name = [%s]\n",v_brand_name.arr));
		}

/* disabled */
		if (ind_disabled >= 0) {
			PutField_Int(myHash,"disabled",v_disabled);
DEBUGLOG(("GetMerchant disabled  = [%d]\n",v_disabled));
		}


/* client_id */
		if (ind_client_id >= 0) {
			v_client_id.arr[v_client_id.len] = '\0';
			PutField_CString(myHash,"merchant_client_id",(const char*)v_client_id.arr);
DEBUGLOG(("GetMerchant client_id = [%s]\n",v_client_id.arr));
		}

/* approximate_fee_rate */
		if (ind_approximate_fee_rate >= 0) {
			PutField_Double(myHash,"approximate_fee_rate",v_approximate_fee_rate);
DEBUGLOG(("GetMerchant approximate_fee_rate = [%lf]\n",v_approximate_fee_rate));
		}

/* status */
		if (ind_status >= 0) {
			v_status.arr[v_status.len] = '\0';
			PutField_CString(myHash,"status",(const char*)v_status.arr);
DEBUGLOG(("GetMerchant status = [%s]\n",v_status.arr));
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

/* deposit_req_ver */
		if (ind_deposit_req_ver >= 0) {
			PutField_Int(myHash,"deposit_req_ver", v_deposit_req_ver);
DEBUGLOG(("GetMerchant deposit_req_ver = [%d]\n",v_deposit_req_ver));
		}
/* display_other_bank */
		if (ind_display_other_bank >= 0) {
			PutField_Int(myHash,"display_other_bank", v_display_other_bank);
DEBUGLOG(("GetMerchant display_other_bank = [%d]\n",v_display_other_bank));
		}

/* is_more_restricted */
		if (ind_is_more_restricted >= 0) {
			PutField_Int(myHash, "is_more_restricted", v_is_more_restricted);
DEBUGLOG(("GetMerchant is_more_restricted = [%d]\n", v_is_more_restricted));
		}

/* support_payout_grp */
		if (ind_support_payout_grp>= 0) {
			PutField_Int(myHash, "support_payout_grp", v_support_payout_grp);
DEBUGLOG(("GetMerchant support_payout_grp = [%d]\n", v_support_payout_grp));
		}

/* txn_auto_expired_days */
		if (ind_txn_auto_expired_days >= 0) {
			PutField_Int(myHash, "txn_auto_expired_days", v_txn_auto_expired_days);
DEBUGLOG(("GetMerchant txn_auto_expired_days = [%d]\n", v_txn_auto_expired_days));
		}

/* txn_auto_expired_mins */
		if (ind_txn_auto_expired_mins >= 0) {
			PutField_Int(myHash, "txn_auto_expired_mins", v_txn_auto_expired_mins);
DEBUGLOG(("GetMerchant txn_auto_expired_mins = [%d]\n", v_txn_auto_expired_mins));
		}

/* stmt_auto_expired_days */
		if (ind_stmt_auto_expired_days >= 0) {
			PutField_Int(myHash, "stmt_auto_expired_days", v_stmt_auto_expired_days);
DEBUGLOG(("GetMerchant stmt_auto_expired_days = [%d]\n", v_stmt_auto_expired_days));
		}

/* stmt_auto_expired_mins */
		if (ind_stmt_auto_expired_mins >= 0) {
			PutField_Int(myHash, "stmt_auto_expired_mins", v_stmt_auto_expired_mins);
DEBUGLOG(("GetMerchant stmt_auto_expired_mins = [%d]\n", v_stmt_auto_expired_mins));
		}

/* po_checksum */
		if (ind_po_checksum>= 0) {
			PutField_Int(myHash, "po_checksum", v_po_checksum);
DEBUGLOG(("GetMerchant payout_checksum = [%d]\n", v_po_checksum));
		}

/* address */
		if (ind_address >= 0) {
			v_address.arr[v_address.len] = '\0';
			PutField_CString(myHash,"address",(const char*)v_address.arr);
DEBUGLOG(("GetMerchant address = [%s]\n",v_address.arr));
		}

/* allow_reserved */
		if (ind_allow_reserved >= 0) {
			PutField_Int(myHash, "allow_reserved", v_allow_reserved);
DEBUGLOG(("GetMerchant allow_reserved = [%d]\n", v_allow_reserved));
		}

/* release_reserved_period */
		if (ind_release_reserved_period >= 0) {
			PutField_Int(myHash, "release_reserved_period", v_release_reserved_period);
DEBUGLOG(("GetMerchant release_reserved_period = [%d]\n", v_release_reserved_period));
		}

		RecordSet_Add(myRec,myHash);
		break; //**************** only one now
	}
	while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getmerchant; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 26;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )273;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getmerchant_error;
}



DEBUGLOG(("GetMerchant Normal Exit\n"));
	if(iRet==0) {
		return  PD_OK;
	}
	else {
		return iRet;
	}

getmerchant_error:
DEBUGLOG(("getmerchant_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLMerchDetail_GetMerchant: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getmerchant; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 26;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )288;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}


int GetDepositRequestVer(const char* csMerchantID,
				hash_t* hRls)
{
	int iRet = 0;
                
	/* EXEC SQL WHENEVER SQLERROR GOTO getdepositver_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

                        
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;


		int		v_deposit_req_ver;

		short		ind_deposit_req_ver= -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_merchant_id.len = strlen(csMerchantID);
	memcpy(hv_merchant_id.arr,csMerchantID,hv_merchant_id.len);
DEBUGLOG(("GetDepositRequestVer merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	/* EXEC SQL SELECT	md_deposit_request_ver
		INTO	:v_deposit_req_ver:ind_deposit_req_ver
		FROM	ol_merch_detail,
			clients
		WHERE	md_merchant_id = :hv_merchant_id
		AND	md_client_id = client_id
		AND	md_disabled = 0
		AND	md_status = 'O'
		AND	status = 'O'; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 26;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select md_deposit_request_ver INTO :b0:b1 FROM ol_merch_det\
ail , clients WHERE md_merchant_id = :b2 AND md_client_id = client_id AND md_\
disabled = 0 AND md_status = 'O' AND status = 'O' ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )303;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_deposit_req_ver;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_deposit_req_ver;
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
 if (sqlca.sqlcode < 0) goto getdepositver_error;
}




/* deposit_req_ver */
	if (ind_deposit_req_ver >= 0) {
DEBUGLOG(("GetDepositRequestVer deposit_req_ver = [%d]\n",v_deposit_req_ver));
		PutField_Int(hRls,"deposit_req_ver", v_deposit_req_ver);
		iRet = PD_FOUND;
	} else {
DEBUGLOG(("GetDepositRequestVer deposit_req_ver NOT FOUND!!!\n"));
		iRet = PD_NOT_FOUND;
	}

DEBUGLOG(("GetDepositRequestVer Normal Exit\n"));
	return iRet;

getdepositver_error:
DEBUGLOG(("getdepositver_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLMerchDetail_GetDepositRequestVer: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int Update(const hash_t *hRls)
{
	char*     csTmp;
	char*     csMerchantId;

	char*	  csBuf;
	double	dTmp;
	int	iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar        hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));

	csBuf = (char*) malloc (128);	

	strcpy((char*)hv_dynstmt.arr,"update ol_merch_detail set md_update_timestamp  = sysdate");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	GetField_CString(hRls,"merchant_id",&csMerchantId);
DEBUGLOG(("Update: merchant_id = [%s]\n", csMerchantId));

/* name */
	if (GetField_CString(hRls, "name", &csTmp)) {
DEBUGLOG(("Update: name= [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",md_name = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* short_name */
	if (GetField_CString(hRls, "short_name", &csTmp)) {
DEBUGLOG(("Update: short_name= [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",md_short_name = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* brand_name */
	if (GetField_CString(hRls, "brand_name", &csTmp)) {
DEBUGLOG(("Update: brand_name= [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",md_brand_name = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* approximate_fee_rate*/
	if (GetField_Double(hRls,"approximate_fee_rate",&dTmp)) {
DEBUGLOG(("Update: approximate_fee_rate = [%f]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",md_approximate_fee_rate = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/*status */
	if (GetField_CString(hRls,"status",&csTmp)) {
DEBUGLOG(("Update: status = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",md_status = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		 hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* allow_pyaout_dup_merch_ref */
	if (GetField_Int(hRls, "allow_payout_dup_merch_ref", &iTmp)) {
DEBUGLOG(("Update: allow_payout_dup_merch_ref = [%d]\n",iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", md_allow_payout_dup_merch_ref = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* settlement_process_period */
	if (GetField_Int(hRls, "settlement_process_period", &iTmp)) {
DEBUGLOG(("Update: settlement_process_period = [%d]\n",iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", md_settlement_process_period = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* ignore_nack */
	if (GetField_Int(hRls, "ignore_nack", &iTmp)) {
DEBUGLOG(("Update: ignore_nack = [%d]\n",iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", md_ignore_nack = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* payout_fe_display */
	if (GetField_Int(hRls, "payout_fe_display", &iTmp)) {
DEBUGLOG(("Update: payout_fe_display = [%d]\n", iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", md_payout_fe_display = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* deposit_req_ver */
	if (GetField_Int(hRls, "deposit_req_ver", &iTmp)) {
DEBUGLOG(("Update: deposit_req_ver = [%d]\n",iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", md_deposit_request_ver = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* display_other_bank */
	if (GetField_Int(hRls, "display_other_bank", &iTmp)) {
DEBUGLOG(("Update: display_other_bank = [%d]\n", iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", md_display_other_bank = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* is_more_restricted */
	if (GetField_Int(hRls, "is_more_restricted", &iTmp)) {
DEBUGLOG(("Update: is_more_restricted = [%d]\n", iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", md_is_more_restricted = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* support_payout_grp */
	if (GetField_Int(hRls, "support_payout_grp", &iTmp)) {
DEBUGLOG(("Update: support_payout_grp = [%d]\n", iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", md_support_payout_grp= ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* txn_auto_expired_days */
	if (GetField_Int(hRls, "txn_auto_expired_days", &iTmp)) {
DEBUGLOG(("Update: txn_auto_expired_days = [%d]\n", iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", md_txn_auto_expired_days = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* txn_auto_expired_mins */
	if (GetField_Int(hRls, "txn_auto_expired_mins", &iTmp)) {
DEBUGLOG(("Update: txn_auto_expired_mins = [%d]\n", iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", md_txn_auto_expired_mins = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* stmt_auto_expired_days */
	if (GetField_Int(hRls, "stmt_auto_expired_days", &iTmp)) {
DEBUGLOG(("Update: stmt_auto_expired_days = [%d]\n", iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", md_stmt_auto_expired_days = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* stmt_auto_expired_mins */
	if (GetField_Int(hRls, "stmt_auto_expired_mins", &iTmp)) {
DEBUGLOG(("Update: stmt_auto_expired_mins = [%d]\n", iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", md_stmt_auto_expired_mins = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* po_checksum */
	if (GetField_Int(hRls, "po_checksum", &iTmp)) {
DEBUGLOG(("Update: payout_checksum = [%d]\n", iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", md_payout_checksum = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* address */
	if (GetField_CString(hRls, "address", &csTmp)) {
DEBUGLOG(("Update: address = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ",md_address= '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* allow_reserved */
	if (GetField_Int(hRls, "allow_reserved", &iTmp)) {
DEBUGLOG(("Update: allow_reserved = [%d]\n",iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", md_allow_reserved = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* release_reserved_period */
	if (GetField_Int(hRls, "release_reserved_period", &iTmp)) {
DEBUGLOG(("Update: release_reserved_period = [%d]\n",iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", md_release_reserved_period = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/*update_user*/
	if(GetField_CString(hRls,"update_user",&csTmp)){
DEBUGLOG(("Update: update_user = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",md_update_user= '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	strcat((char *)hv_dynstmt.arr, " WHERE md_merchant_id = '");
	strcat((char *)hv_dynstmt.arr, csMerchantId);
	strcat((char *)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
        
	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 26;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )326;
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
 sqlstm.arrsiz = 26;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )345;
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

ERRLOG("OLMerchDetail_Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
	return PD_INTERNAL_ERR;
}


int     ChkOLMerchIDExist(const char *csMID)
{
        int     iRet = PD_NOT_FOUND;

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

DEBUGLOG(("ChkOLMerchIDExist = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

        /* EXEC SQL
                SELECT count(1)
                   INTO :v_no_of_record:ind_no_of_record
                   FROM ol_merch_detail
                  WHERE md_merchant_id = :hv_merchant_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 26;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM ol_merch_detail \
WHERE md_merchant_id = :b2 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )360;
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
DEBUGLOG(("ChkOLMerchIDExist FOUND\n"));
                        iRet = PD_FOUND;
                }
        }

        if (iRet!= PD_FOUND) {
DEBUGLOG(("ChkOLMerchIDExist NOT FOUND\n"));
        }

        return iRet;

chkmerchidexist_error:
DEBUGLOG(("ChkOLMerchIDExist_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}




int GetMerchByShortName(const char* csMerchName, hash_t* hRec)
{
	int iRet = PD_NOT_FOUND;
	int iCnt = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO getmerch_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar     hv_short_name[PD_MERCH_SHORT_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_short_name;

		
		/* varchar		v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar		v_client_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_client_id;

		/* varchar		v_status[PD_ACCOUNT_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_status;

		int		v_disabled;

		short		ind_merchant_id = -1;
		short		ind_client_id = -1;
		short		ind_status = -1;
		short		ind_disabled = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_short_name.len = strlen(csMerchName);
	memcpy(hv_short_name.arr, csMerchName, hv_short_name.len);
DEBUGLOG(("GetMerchByShortName short_name = [%.*s]\n", hv_short_name.len, hv_short_name.arr));



	/* EXEC SQL DECLARE c_cursor_getmerch CURSOR FOR
		select	md_merchant_id,
			md_client_id,
			md_status,
			md_disabled
		from ol_merch_detail 
		where md_short_name =:hv_short_name; */ 



	/* EXEC SQL OPEN c_cursor_getmerch; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 26;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0007;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )383;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_short_name;
 sqlstm.sqhstl[0] = (unsigned long )22;
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
 if (sqlca.sqlcode < 0) goto getmerch_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getmerch
		INTO	:v_merchant_id:ind_merchant_id,
			:v_client_id:ind_client_id,
			:v_status:ind_status,
			:v_disabled:ind_disabled
		; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 26;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )402;
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
  sqlstm.sqhstv[2] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[2] = (unsigned long )5;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_status;
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
  if (sqlca.sqlcode < 0) goto getmerch_error;
}


	
		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}
DEBUGLOG(("GetMerchByShortName found record\n"));
		
		if(iCnt >= 1){
DEBUGLOG(("GetMerchByShortName found duplicate record\n"));
			iRet = PD_NOT_FOUND;
			break;
		}

/* merchant_id */
		if (ind_merchant_id >= 0) {
			v_merchant_id.arr[v_merchant_id.len] = '\0';
			PutField_CString(hRec,"merchant_id",(const char*)v_merchant_id.arr);
DEBUGLOG(("GetMerchByShortName merchant_id = [%s]\n",v_merchant_id.arr));
		}
/* client_id */
		if (ind_client_id >= 0) {
			v_client_id.arr[v_client_id.len] = '\0';
			PutField_CString(hRec,"merchant_client_id",(const char*)v_client_id.arr);
DEBUGLOG(("GetMerchByShortName client_id = [%s]\n",v_client_id.arr));
		}
/* merch_status */
		if (ind_status >= 0) {
			v_status.arr[v_status.len] = '\0';
			PutField_CString(hRec,"merch_status",(const char*)v_status.arr);
DEBUGLOG(("GetMerchByShortName merch_status = [%s]\n",v_status.arr));
		}
/* merch_disabled */
		if (ind_disabled >= 0) {
			PutField_Int(hRec,"merch_disabled", v_disabled);
DEBUGLOG(("GetMerchByShortName merch_disabled = [%d]\n",v_disabled));
		}	

		
		iCnt++;
		iRet = PD_FOUND;
	
	}
	while(PD_TRUE);
	
	/* EXEC SQL CLOSE c_cursor_getmerch; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 26;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )433;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getmerch_error;
}


	
	

	if (iRet == PD_FOUND) {
DEBUGLOG(("GetMerchByShortName found unique record\n"));
	}
	else{
DEBUGLOG(("GetMerchByShortName found duplicate or No record\n"));
	}

DEBUGLOG(("GetMerchByShortName: Normal Exit\n"));
	return iRet;

getmerch_error:
DEBUGLOG(("getmerch_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getmerch; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 26;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )448;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;

}














