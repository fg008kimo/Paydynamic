
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
           char  filnam[28];
};
static struct sqlcxp sqlfpn =
{
    27,
    "MerchantSettlementDetail.pc"
};


static unsigned int sqlctx = 1436091435;


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
   unsigned char  *sqhstv[27];
   unsigned long  sqhstl[27];
            int   sqhsts[27];
            short *sqindv[27];
            int   sqinds[27];
   unsigned long  sqharm[27];
   unsigned long  *sqharc[27];
   unsigned short  sqadto[27];
   unsigned short  sqtdso[27];
} sqlstm = {12,27};

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
"select sd_merchant_id , sd_country_id , sd_service_code , sd_status , sd_re\
quest_ccy , sd_deliver_ccy , sd_inter_ccy , sd_request_amt , sd_deliver_amt ,\
 sd_inter_amt , sd_settlement_type , sd_client_sett_bank_id , sd_merchant_not\
ify_email , sd_country_subdivision , sd_city , sd_country from merchant_settl\
ement_detail where sd_txn_id = :b0            ";

 static char *sq0004 = 
"select sd_remark from merchant_settlement_detail where sd_txn_id = :b0     \
       ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,973,0,6,281,0,0,27,27,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
1,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,9,0,0,1,1,0,0,1,3,0,0,
1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,
128,0,0,2,0,0,17,653,0,0,1,1,0,1,0,1,9,0,0,
147,0,0,2,0,0,21,654,0,0,0,0,0,1,0,
162,0,0,3,352,0,9,744,0,2049,1,1,0,1,0,1,9,0,0,
181,0,0,3,0,0,13,746,0,0,16,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,1,0,0,2,3,0,0,2,3,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,
260,0,0,3,0,0,15,867,0,0,0,0,0,1,0,
275,0,0,3,0,0,15,882,0,0,0,0,0,1,0,
290,0,0,4,82,0,9,911,0,2049,1,1,0,1,0,1,9,0,0,
309,0,0,4,0,0,13,913,0,0,1,0,0,1,0,2,9,0,0,
328,0,0,4,0,0,15,931,0,0,0,0,0,1,0,
343,0,0,4,0,0,15,946,0,0,0,0,0,1,0,
358,0,0,5,147,0,6,996,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/07/11              LokMan Chow
add inter_ccy and inter_amt			   2013/05/10		   LokMan Chow
add receive_ccy and receive_amt			   2014/02/04              Virginia Yun
add 8 fields support multiple merch sett bank ac   2014/10/06		   Dirk Wong
Merchant Notify Email Option Support               2014/11/11              Elvis Wong
add 3 fields for address template		   2015/03/02		   Dirk Wong
add GetRemark					   2016/08/02		   Dirk Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "MerchantSettlementDetail.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void MerchantSettlementDetail(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const hash_t* hRls)
{
	char*	csTmp;
	char	cTmp;
	double	dTmp;
	int	iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	        hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar		hv_request_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_request_ccy;

		/* varchar		hv_deliver_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_deliver_ccy;

		/* varchar		hv_inter_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_inter_ccy;

		char		hv_status;
		double		hv_request_amt;
		double		hv_deliver_amt;
		double		hv_inter_amt;
		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;

		/* varchar 	hv_remark[PD_REMARK_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_remark;

		char		hv_type;
		int		hv_client_sett_bank_id;
		/* varchar		hv_beneficiary_bank_ac_name[PD_BENEFICIARY_BANK_AC_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_beneficiary_bank_ac_name;

		/* varchar		hv_beneficiary_bank_ac_num[PD_BENEFICIARY_BANK_AC_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_beneficiary_bank_ac_num;

		/* varchar		hv_beneficiary_bank_name[PD_BENEFICIARY_BANK_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_beneficiary_bank_name;

		/* varchar		hv_address[PD_COMPANY_ADDR_LEN]; */ 
struct { unsigned short len; unsigned char arr[200]; } hv_address;

		/* varchar		hv_swift_code[PD_COMPANY_SWIFT_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[80]; } hv_swift_code;

		/* varchar		hv_iban[PD_COMPANY_IBAN_LEN]; */ 
struct { unsigned short len; unsigned char arr[80]; } hv_iban;

		/* varchar		hv_bank_ac_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_bank_ac_ccy;

		int             hv_merchant_notify_email;
		/* varchar		hv_country_subdivision[PD_CLIENT_COUNTRY_SUBDIVISION_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_country_subdivision;

		/* varchar		hv_city[PD_CITY_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_city;

		/* varchar		hv_country[PD_CLIENT_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_country;


		short		ind_merchant_id = -1;
		short		ind_country_id = -1;
		short		ind_txn_id = -1;
		short		ind_service_code = -1;
		short		ind_request_ccy= -1;
		short		ind_deliver_ccy= -1;
		short		ind_inter_ccy= -1;
		short		ind_status= -1;
		short		ind_request_amt= -1;
		short		ind_deliver_amt= -1;
		short		ind_inter_amt= -1;
		short		ind_create_user = -1;
		short		ind_remark = -1;
		short		ind_type = -1;
		short		ind_client_sett_bank_id = -1;
		short		ind_beneficiary_bank_ac_name = -1;
		short		ind_beneficiary_bank_ac_num = -1;
		short		ind_beneficiary_bank_name = -1;
		short		ind_address = -1;
		short		ind_swift_code = -1;
		short		ind_iban = -1;
		short		ind_bank_ac_ccy = -1;
		short           ind_merchant_notify_email = -1;
		short		ind_country_subdivision = -1;
		short		ind_city = -1;
		short		ind_country = -1;

		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("Add: Begin\n"));

	if (GetField_CString(hRls,"merchant_id",&csTmp)) {
		hv_merchant_id.len = strlen(csTmp);
		strncpy((char *)hv_merchant_id.arr, csTmp, hv_merchant_id.len);
		ind_merchant_id = 0;
DEBUGLOG(("Add:merchant id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
	}
	
	if (GetField_CString(hRls,"txn_country",&csTmp)) {
		hv_country_id.len = strlen(csTmp);
		strncpy((char *)hv_country_id.arr, csTmp, hv_country_id.len);
		ind_country_id = 0;
DEBUGLOG(("Add:country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));
	}

	if (GetField_CString(hRls,"txn_seq",&csTmp)) {
		hv_txn_id.len = strlen(csTmp);
		strncpy((char *)hv_txn_id.arr, csTmp, hv_txn_id.len);
		ind_txn_id = 0;
DEBUGLOG(("Add:txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
	}

	if (GetField_CString(hRls,"service_code",&csTmp)) {
		hv_service_code.len = strlen(csTmp);
		strncpy((char *)hv_service_code.arr, csTmp, hv_service_code.len);
		ind_service_code = 0;
DEBUGLOG(("Add:service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));
	}

	if (GetField_Char(hRls,"status",&cTmp)) {
		hv_status = cTmp;
		ind_status = 0;
DEBUGLOG(("Add:status = [%c]\n",hv_status));
	}

	if (GetField_Char(hRls,"type",&cTmp)) {
		hv_type = cTmp;
		ind_type = 0;
DEBUGLOG(("Add:type = [%c]\n",hv_type));
	}
	if (GetField_CString(hRls,"request_ccy",&csTmp)) {
		hv_request_ccy.len = strlen(csTmp);
		strncpy((char *)hv_request_ccy.arr, csTmp, hv_request_ccy.len);
		ind_request_ccy= 0;
DEBUGLOG(("Add:request_ccy = [%.*s]\n",hv_request_ccy.len,hv_request_ccy.arr));
	}

	if (GetField_CString(hRls,"inter_ccy",&csTmp)) {
		hv_inter_ccy.len = strlen(csTmp);
		strncpy((char *)hv_inter_ccy.arr, csTmp, hv_inter_ccy.len);
		ind_inter_ccy= 0;
DEBUGLOG(("Add:inter_ccy = [%.*s]\n",hv_inter_ccy.len,hv_inter_ccy.arr));
	}

	if (GetField_CString(hRls,"deliver_ccy",&csTmp)) {
		hv_deliver_ccy.len = strlen(csTmp);
		strncpy((char *)hv_deliver_ccy.arr, csTmp, hv_deliver_ccy.len);
		ind_deliver_ccy= 0;
DEBUGLOG(("Add:deliver_ccy = [%.*s]\n",hv_deliver_ccy.len,hv_deliver_ccy.arr));
	}

	if (GetField_Double(hRls,"request_amt",&dTmp)) {
		hv_request_amt= dTmp;
		ind_request_amt= 0;
DEBUGLOG(("Add:request_amt = [%f]\n",hv_request_amt));
	}

	if (GetField_Double(hRls,"inter_amt",&dTmp)) {
		hv_inter_amt= dTmp;
		ind_inter_amt= 0;
DEBUGLOG(("Add:inter_amt = [%f]\n",hv_inter_amt));
	}

	if (GetField_Double(hRls,"deliver_amt",&dTmp)) {
		hv_deliver_amt= dTmp;
		ind_deliver_amt= 0;
DEBUGLOG(("Add:deliver_amt = [%f]\n",hv_deliver_amt));
	}

	if (GetField_CString(hRls,"remark",&csTmp)) {
		hv_remark.len = strlen(csTmp);
		strncpy((char *)hv_remark.arr, csTmp, hv_remark.len);
		ind_remark= 0;
DEBUGLOG(("Add:remark = [%.*s]\n",hv_remark.len,hv_remark.arr));
	}

	if (GetField_Int(hRls,"client_sett_bank_id",&iTmp)) {
		hv_client_sett_bank_id= iTmp;
		ind_client_sett_bank_id= 0;
DEBUGLOG(("Add:cleient_sett_bank_id = [%d]\n",hv_client_sett_bank_id));
	}

	if (GetField_CString(hRls,"beneficiary_bank_ac_name",&csTmp)) {
		hv_beneficiary_bank_ac_name.len = strlen(csTmp);
		strncpy((char *)hv_beneficiary_bank_ac_name.arr, csTmp, hv_beneficiary_bank_ac_name.len);
		ind_beneficiary_bank_ac_name= 0;
DEBUGLOG(("Add:beneficiary_bank_ac_name = [%.*s]\n",hv_beneficiary_bank_ac_name.len,hv_beneficiary_bank_ac_name.arr));
	}

	if (GetField_CString(hRls,"beneficiary_bank_ac_num",&csTmp)) {
		hv_beneficiary_bank_ac_num.len = strlen(csTmp);
		strncpy((char *)hv_beneficiary_bank_ac_num.arr, csTmp, hv_beneficiary_bank_ac_num.len);
		ind_beneficiary_bank_ac_num= 0;
DEBUGLOG(("Add:beneficiary_bank_ac_num = [%.*s]\n",hv_beneficiary_bank_ac_num.len,hv_beneficiary_bank_ac_num.arr));
	}

	if (GetField_CString(hRls,"beneficiary_bank_name",&csTmp)) {
		hv_beneficiary_bank_name.len = strlen(csTmp);
		strncpy((char *)hv_beneficiary_bank_name.arr, csTmp, hv_beneficiary_bank_name.len);
		ind_beneficiary_bank_name= 0;
DEBUGLOG(("Add:beneficiary_bank_name = [%.*s]\n",hv_beneficiary_bank_name.len,hv_beneficiary_bank_name.arr));
	}

	if (GetField_CString(hRls,"address",&csTmp)) {
		hv_address.len = strlen(csTmp);
		strncpy((char *)hv_address.arr, csTmp, hv_address.len);
		ind_address= 0;
DEBUGLOG(("Add:address = [%.*s]\n",hv_address.len,hv_address.arr));
	}

	if (GetField_CString(hRls,"swift_code",&csTmp)) {
		hv_swift_code.len = strlen(csTmp);
		strncpy((char *)hv_swift_code.arr, csTmp, hv_swift_code.len);
		ind_swift_code= 0;
DEBUGLOG(("Add:swift_code = [%.*s]\n",hv_swift_code.len,hv_swift_code.arr));
	}

	if (GetField_CString(hRls,"iban",&csTmp)) {
		hv_iban.len = strlen(csTmp);
		strncpy((char *)hv_iban.arr, csTmp, hv_iban.len);
		ind_iban= 0;
DEBUGLOG(("Add:iban = [%.*s]\n",hv_iban.len,hv_iban.arr));
	}

	if (GetField_CString(hRls,"bank_ac_ccy",&csTmp)) {
		hv_bank_ac_ccy.len = strlen(csTmp);
		strncpy((char *)hv_bank_ac_ccy.arr, csTmp, hv_bank_ac_ccy.len);
		ind_bank_ac_ccy= 0;
DEBUGLOG(("Add:bank_ac_ccy = [%.*s]\n",hv_bank_ac_ccy.len,hv_bank_ac_ccy.arr));
	}

	if (GetField_Int(hRls,"merchant_notify_email",&iTmp)) {
                hv_merchant_notify_email= iTmp;
                ind_merchant_notify_email= 0;
DEBUGLOG(("Add:merchant_notify_email = [%d]\n",hv_merchant_notify_email));
        }

	if (GetField_CString(hRls,"country_subdivision",&csTmp)) {
		hv_country_subdivision.len = strlen(csTmp);
		strncpy((char *)hv_country_subdivision.arr, csTmp, hv_country_subdivision.len);
		ind_country_subdivision= 0;
DEBUGLOG(("Add: = [%.*s]\n",hv_country_subdivision.len,hv_country_subdivision.arr));
	}

	if (GetField_CString(hRls,"city",&csTmp)) {
		hv_city.len = strlen(csTmp);
		strncpy((char *)hv_city.arr, csTmp, hv_city.len);
		ind_city= 0;
DEBUGLOG(("Add: = [%.*s]\n",hv_city.len,hv_city.arr));
	}

	if (GetField_CString(hRls,"country",&csTmp)) {
		hv_country.len = strlen(csTmp);
		strncpy((char *)hv_country.arr, csTmp, hv_country.len);
		ind_country= 0;
DEBUGLOG(("Add: = [%.*s]\n",hv_country.len,hv_country.arr));
	}

	if (GetField_CString(hRls,"add_user",&csTmp)) {
		hv_create_user.len = strlen(csTmp);
		strncpy((char *)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));
	}

	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_merch_settle_detail_insert(
				:hv_txn_id:ind_txn_id,
				:hv_merchant_id:ind_merchant_id,
				:hv_country_id:ind_country_id,
				:hv_service_code:ind_service_code,
				:hv_status:ind_status,
				:hv_request_ccy:ind_request_ccy,
				:hv_inter_ccy:ind_inter_ccy,
				:hv_deliver_ccy:ind_deliver_ccy,
				:hv_request_amt:ind_request_amt,
				:hv_inter_amt:ind_inter_amt,
				:hv_deliver_amt:ind_deliver_amt,
				:hv_remark:ind_remark,
				:hv_type:ind_type,
				:hv_client_sett_bank_id:ind_client_sett_bank_id,
				:hv_beneficiary_bank_ac_name:ind_beneficiary_bank_ac_name,
				:hv_beneficiary_bank_ac_num:ind_beneficiary_bank_ac_num,
				:hv_beneficiary_bank_name:ind_beneficiary_bank_name,
				:hv_address:ind_address,
				:hv_swift_code:ind_swift_code,
				:hv_iban:ind_iban,
				:hv_bank_ac_ccy:ind_bank_ac_ccy,
				:hv_merchant_notify_email:ind_merchant_notify_email,
				:hv_country_subdivision:ind_country_subdivision,
				:hv_city:ind_city,
				:hv_country:ind_country,
				:hv_create_user:ind_create_user);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 27;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merch_settle_detail_insert ( :\
hv_txn_id:ind_txn_id , :hv_merchant_id:ind_merchant_id , :hv_country_id:ind_c\
ountry_id , :hv_service_code:ind_service_code , :hv_status:ind_status , :hv_r\
equest_ccy:ind_request_ccy , :hv_inter_ccy:ind_inter_ccy , :hv_deliver_ccy:in\
d_deliver_ccy , :hv_request_amt:ind_request_amt , :hv_inter_amt:ind_inter_amt\
 , :hv_deliver_amt:ind_deliver_amt , :hv_remark:ind_remark , :hv_type:ind_typ\
e , :hv_client_sett_bank_id:ind_client_sett_bank_id , :hv_beneficiary_bank_ac\
_name:ind_beneficiary_bank_ac_name , :hv_beneficiary_bank_ac_num:ind_benefici\
ary_bank_ac_num , :hv_beneficiary_bank_name:ind_beneficiary_bank_name , :hv_a\
ddress:ind_address , :hv_swift_code:ind_swift_code , :hv_iban:ind_iban , :hv_\
bank_ac_ccy:ind_bank_ac_ccy , :hv_merchant_notify_email:ind_merchant_notify_e\
mail , :hv_country_subdivision:ind_country_subdivision , :hv_city:ind_city , \
:hv_country:ind_country , :hv_create_user:ind_create_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_txn_id;
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
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_country_id;
 sqlstm.sqhstl[3] = (unsigned long )4;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_country_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_service_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[5] = (unsigned long )1;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_status;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_request_ccy;
 sqlstm.sqhstl[6] = (unsigned long )5;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_request_ccy;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_inter_ccy;
 sqlstm.sqhstl[7] = (unsigned long )5;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_inter_ccy;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_deliver_ccy;
 sqlstm.sqhstl[8] = (unsigned long )5;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_deliver_ccy;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_request_amt;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_request_amt;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_inter_amt;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_inter_amt;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_deliver_amt;
 sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_deliver_amt;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_remark;
 sqlstm.sqhstl[12] = (unsigned long )257;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_remark;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_type;
 sqlstm.sqhstl[13] = (unsigned long )1;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_type;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_client_sett_bank_id;
 sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_client_sett_bank_id;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_beneficiary_bank_ac_name;
 sqlstm.sqhstl[15] = (unsigned long )102;
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_beneficiary_bank_ac_name;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_beneficiary_bank_ac_num;
 sqlstm.sqhstl[16] = (unsigned long )52;
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_beneficiary_bank_ac_num;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&hv_beneficiary_bank_name;
 sqlstm.sqhstl[17] = (unsigned long )102;
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&ind_beneficiary_bank_name;
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
 sqlstm.sqhstv[19] = (unsigned char  *)&hv_swift_code;
 sqlstm.sqhstl[19] = (unsigned long )82;
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)&ind_swift_code;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned long )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (unsigned char  *)&hv_iban;
 sqlstm.sqhstl[20] = (unsigned long )82;
 sqlstm.sqhsts[20] = (         int  )0;
 sqlstm.sqindv[20] = (         short *)&ind_iban;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned long )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (unsigned char  *)&hv_bank_ac_ccy;
 sqlstm.sqhstl[21] = (unsigned long )5;
 sqlstm.sqhsts[21] = (         int  )0;
 sqlstm.sqindv[21] = (         short *)&ind_bank_ac_ccy;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned long )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
 sqlstm.sqhstv[22] = (unsigned char  *)&hv_merchant_notify_email;
 sqlstm.sqhstl[22] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[22] = (         int  )0;
 sqlstm.sqindv[22] = (         short *)&ind_merchant_notify_email;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned long )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
 sqlstm.sqhstv[23] = (unsigned char  *)&hv_country_subdivision;
 sqlstm.sqhstl[23] = (unsigned long )102;
 sqlstm.sqhsts[23] = (         int  )0;
 sqlstm.sqindv[23] = (         short *)&ind_country_subdivision;
 sqlstm.sqinds[23] = (         int  )0;
 sqlstm.sqharm[23] = (unsigned long )0;
 sqlstm.sqadto[23] = (unsigned short )0;
 sqlstm.sqtdso[23] = (unsigned short )0;
 sqlstm.sqhstv[24] = (unsigned char  *)&hv_city;
 sqlstm.sqhstl[24] = (unsigned long )102;
 sqlstm.sqhsts[24] = (         int  )0;
 sqlstm.sqindv[24] = (         short *)&ind_city;
 sqlstm.sqinds[24] = (         int  )0;
 sqlstm.sqharm[24] = (unsigned long )0;
 sqlstm.sqadto[24] = (unsigned short )0;
 sqlstm.sqtdso[24] = (unsigned short )0;
 sqlstm.sqhstv[25] = (unsigned char  *)&hv_country;
 sqlstm.sqhstl[25] = (unsigned long )52;
 sqlstm.sqhsts[25] = (         int  )0;
 sqlstm.sqindv[25] = (         short *)&ind_country;
 sqlstm.sqinds[25] = (         int  )0;
 sqlstm.sqharm[25] = (unsigned long )0;
 sqlstm.sqadto[25] = (unsigned short )0;
 sqlstm.sqtdso[25] = (unsigned short )0;
 sqlstm.sqhstv[26] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[26] = (unsigned long )22;
 sqlstm.sqhsts[26] = (         int  )0;
 sqlstm.sqindv[26] = (         short *)&ind_create_user;
 sqlstm.sqinds[26] = (         int  )0;
 sqlstm.sqharm[26] = (unsigned long )0;
 sqlstm.sqadto[26] = (unsigned short )0;
 sqlstm.sqtdso[26] = (unsigned short )0;
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
ERRLOG("MerchantSettlementDetail::Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("MerchantSettlementDetail::Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
	return PD_ERR;

}


int Update(const hash_t* hRls)
{
	char*   csTmp;
	char*   csTxnId;
        char    cTmp;
        double  dTmp;
	char*   csBuf;
	int	iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update merchant_settlement_detail set sd_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	GetField_CString(hRls,"txn_seq",&csTxnId);
DEBUGLOG(("Update:txn_id = [%s]\n",csTxnId));

/* merchant_id */
        if (GetField_CString(hRls,"merchant_id",&csTmp)) {
DEBUGLOG(("Update: = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",sd_merchant_id = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* country_id */
        if (GetField_CString(hRls,"country_id",&csTmp)) {
DEBUGLOG(("Update:country_id = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",sd_country_id = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* service_code */
        if (GetField_CString(hRls,"service_code",&csTmp)) {
DEBUGLOG(("Update:service_code = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",sd_service_code = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* request_ccy */
        if (GetField_CString(hRls,"request_ccy",&csTmp)) {
DEBUGLOG(("Update:request_ccy = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",sd_request_ccy = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* deliver_ccy */
        if (GetField_CString(hRls,"deliver_ccy",&csTmp)) {
DEBUGLOG(("Update:deliver_ccy = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",sd_deliver_ccy = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* status */
        if (GetField_Char(hRls,"status",&cTmp)) {
DEBUGLOG(("Update:status = [%c]\n",cTmp));
                sprintf(csBuf,"%c",cTmp);
                strcat((char*)hv_dynstmt.arr, ",sd_status = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* request_amt */
        if (GetField_Double(hRls,"request_amt",&dTmp)) {
DEBUGLOG(("Update:request_amt = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",sd_request_amt = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* deliver_amt */
        if (GetField_Double(hRls,"deliver_amt",&dTmp)) {
DEBUGLOG(("Update:deliver_amt = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",sd_deliver_amt = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* remark*/
        if (GetField_CString(hRls,"remark",&csTmp)) {
DEBUGLOG(("Update:remark = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",sd_remark = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* approve_user */
        if (GetField_CString(hRls,"approve_user",&csTmp)) {
DEBUGLOG(("Update:approve_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",sd_approve_user = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* deliver_user */
        if (GetField_CString(hRls,"deliver_user",&csTmp)) {
DEBUGLOG(("Update:deliver_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",sd_deliver_user = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* deliver_date */
        if (GetField_CString(hRls,"deliver_date",&csTmp)) {
DEBUGLOG(("Update:deliver_date = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",sd_deliver_date = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* inter_ccy */
        if (GetField_CString(hRls,"inter_ccy",&csTmp)) {
DEBUGLOG(("Update:inter_ccy = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",sd_inter_ccy = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* inter_amt */
        if (GetField_Double(hRls,"inter_amt",&dTmp)) {
DEBUGLOG(("Update:inter_amt = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",sd_inter_amt = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* receive_ccy */
        if (GetField_CString(hRls,"receive_ccy",&csTmp)) {
DEBUGLOG(("Update:receive_ccy = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",sd_receive_net_ccy = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* receive_amt */
        if (GetField_Double(hRls,"receive_amt",&dTmp)) {
DEBUGLOG(("Update:receive_amt = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",sd_receive_net_amt = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* update_user */
        if (GetField_CString(hRls,"update_user",&csTmp)) {
DEBUGLOG(("Update:update_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",sd_update_user = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* bank_statement_date */
        if (GetField_CString(hRls,"bank_statement_date",&csTmp)) {
DEBUGLOG(("Update:bank_statement_date = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",sd_bank_statement_date = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* client_sett_bank_id */
	if (GetField_Int(hRls,"client_sett_bank_id",&iTmp)) {
DEBUGLOG(("Update:client_sett_bank_id = [%d]\n",iTmp));
		sprintf(csBuf,"%d",iTmp);
		strcat((char*)hv_dynstmt.arr, ",sd_client_sett_bank_id = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* beneficiary_bank_ac_name */
	if (GetField_CString(hRls,"beneficiary_bank_ac_name",&csTmp)) {
DEBUGLOG(("Update:beneficiary_bank_ac_name = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",sd_beneficiary_bank_ac_name = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* beneficiary_bank_ac_num */
	if (GetField_CString(hRls,"beneficiary_bank_ac_num",&csTmp)) {
DEBUGLOG(("Update:beneficiary_bank_ac_num = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",sd_beneficiary_bank_ac_num = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* beneficiary_bank_name */
	if (GetField_CString(hRls,"beneficiary_bank_name",&csTmp)) {
DEBUGLOG(("Update:beneficiary_bank_name = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",sd_beneficiary_bank_name = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* address */
	if (GetField_CString(hRls,"address",&csTmp)) {
DEBUGLOG(("Update:address = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",sd_address = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* swift_code */
	if (GetField_CString(hRls,"swift_code",&csTmp)) {
DEBUGLOG(("Update:swift_code = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",sd_swift_code = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* iban */
	if (GetField_CString(hRls,"iban",&csTmp)) {
DEBUGLOG(("Update:iban = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",sd_iban = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* bank_ac_ccy */
	if (GetField_CString(hRls,"bank_ac_ccy",&csTmp)) {
DEBUGLOG(("Update:bank_ac_ccy = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",sd_bank_ac_ccy = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* merchant_notify_email */
        if (GetField_Int(hRls,"merchant_notify_email",&iTmp)) {
DEBUGLOG(("Update:merchant_notify_email = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",sd_merchant_notify_email = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* country_subdivision */
	if (GetField_CString(hRls,"country_subdivision",&csTmp)) {
DEBUGLOG(("Update:country_subdivision = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",sd_country_subdivision = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* city */
	if (GetField_CString(hRls,"city",&csTmp)) {
DEBUGLOG(("Update:city = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",sd_city = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* country */
	if (GetField_CString(hRls,"country",&csTmp)) {
DEBUGLOG(("Update:country = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",sd_country = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	strcat((char *)hv_dynstmt.arr, " WHERE sd_txn_id = '");
        strcat((char *)hv_dynstmt.arr, csTxnId);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
        
        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 27;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )128;
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
        sqlstm.arrsiz = 27;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )147;
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

ERRLOG("Merchant_Settlement_Detail_Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;
}

int GetSettlementDetail(const char* csTxnID,
			recordset_t* myRec)
{
	int iCnt = 0;

	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO get_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


		/* varchar		v_merchant_id[PD_MERCHANT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar		v_country_id[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country_id;

		/* varchar		v_service_code[PD_SERVICE_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		/* varchar		v_request_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_request_ccy;

		/* varchar		v_deliver_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_deliver_ccy;

		/* varchar		v_inter_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_inter_ccy;

		double		v_request_amt;
		double		v_deliver_amt;
		double		v_inter_amt;
		char		v_status;
		char		v_sett_type;
		int		v_client_sett_bank_id;
		int             v_merchant_notify_email;
		/* varchar		v_country_subdivision[PD_CLIENT_COUNTRY_SUBDIVISION_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_country_subdivision;

		/* varchar		v_city[PD_CITY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_city;

		/* varchar		v_country[PD_CLIENT_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_country;


		short		ind_merchant_id=-1;
		short		ind_country_id=-1;
		short		ind_service_code=-1;
		short		ind_request_ccy=-1;
		short		ind_deliver_ccy=-1;
		short		ind_inter_ccy=-1;
		short		ind_request_amt=-1;
		short		ind_deliver_amt=-1;
		short		ind_inter_amt=-1;
		short		ind_status=-1;
		short		ind_sett_type=-1;
		short		ind_client_sett_bank_id=-1;
		short           ind_merchant_notify_email=-1;
		short		ind_country_subdivision=-1;
		short		ind_city=-1;
		short		ind_country=-1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_id.len = strlen(csTxnID);
	memcpy(hv_txn_id.arr,csTxnID,hv_txn_id.len);
DEBUGLOG(("GetSettlementDetail txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

	/* EXEC SQL DECLARE c_cursor_get CURSOR FOR
		select	sd_merchant_id,
			sd_country_id,
			sd_service_code,
			sd_status,
			sd_request_ccy,
			sd_deliver_ccy,
			sd_inter_ccy,
			sd_request_amt,
			sd_deliver_amt,
			sd_inter_amt,
                        sd_settlement_type,
			sd_client_sett_bank_id,
			sd_merchant_notify_email,
			sd_country_subdivision,
			sd_city,
			sd_country
		from	merchant_settlement_detail
		where	sd_txn_id = :hv_txn_id; */ 


	/* EXEC SQL OPEN c_cursor_get; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 27;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )162;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_txn_id;
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
 if (sqlca.sqlcode < 0) goto get_error;
}


	do{
		/* EXEC SQL FETCH c_cursor_get
		INTO
			:v_merchant_id:ind_merchant_id,
			:v_country_id:ind_country_id,
			:v_service_code:ind_service_code,
			:v_status:ind_status,
			:v_request_ccy:ind_request_ccy,
			:v_deliver_ccy:ind_deliver_ccy,
			:v_inter_ccy:ind_inter_ccy,
			:v_request_amt:ind_request_amt,
			:v_deliver_amt:ind_deliver_amt,
			:v_inter_amt:ind_inter_amt,
			:v_sett_type:ind_sett_type,
			:v_client_sett_bank_id:ind_client_sett_bank_id,
			:v_merchant_notify_email:ind_merchant_notify_email,
			:v_country_subdivision:ind_country_subdivision,
			:v_city:ind_city,
			:v_country:ind_country; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )181;
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
  sqlstm.sqhstv[1] = (unsigned char  *)&v_country_id;
  sqlstm.sqhstl[1] = (unsigned long )5;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_country_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_service_code;
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_service_code;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[3] = (unsigned long )1;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_status;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_request_ccy;
  sqlstm.sqhstl[4] = (unsigned long )6;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_request_ccy;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_deliver_ccy;
  sqlstm.sqhstl[5] = (unsigned long )6;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_deliver_ccy;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_inter_ccy;
  sqlstm.sqhstl[6] = (unsigned long )6;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_inter_ccy;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_request_amt;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_request_amt;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_deliver_amt;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_deliver_amt;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_inter_amt;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_inter_amt;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_sett_type;
  sqlstm.sqhstl[10] = (unsigned long )1;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_sett_type;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_client_sett_bank_id;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_client_sett_bank_id;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_merchant_notify_email;
  sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_merchant_notify_email;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_country_subdivision;
  sqlstm.sqhstl[13] = (unsigned long )103;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_country_subdivision;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_city;
  sqlstm.sqhstl[14] = (unsigned long )103;
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_city;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_country;
  sqlstm.sqhstl[15] = (unsigned long )53;
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_country;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto get_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		iCnt++;

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

		if (ind_merchant_id >= 0) {
			v_merchant_id.arr[v_merchant_id.len] ='\0';
			PutField_CString(myHash,"merchant_id",(const char*)v_merchant_id.arr);
DEBUGLOG(("GetSettlementDetail merchant_id = [%s]\n",v_merchant_id.arr));  
		}

		if (ind_country_id>= 0) {
			v_country_id.arr[v_country_id.len] ='\0';
			PutField_CString(myHash,"country_id",(const char*)v_country_id.arr);
DEBUGLOG(("GetSettlementDetail country_id = [%s]\n",v_country_id.arr));  
		}

		if (ind_service_code >= 0) {
			v_service_code.arr[v_service_code.len] ='\0';
			PutField_CString(myHash,"service_code",(const char*)v_service_code.arr);
DEBUGLOG(("GetSettlementDetail service_code = [%s]\n",v_service_code.arr));
		}

		if (ind_status >= 0) {
			PutField_Char(myHash,"status",v_status);
DEBUGLOG(("GetSettlementDetail status = [%c]\n",v_status));
		}

		if (ind_request_ccy>= 0) {
			v_request_ccy.arr[v_request_ccy.len] ='\0';
			PutField_CString(myHash,"request_ccy",(const char*)v_request_ccy.arr);
DEBUGLOG(("GetSettlementDetail request_ccy = [%s]\n",v_request_ccy.arr));
		}

		if (ind_inter_ccy>= 0) {
			v_inter_ccy.arr[v_inter_ccy.len] ='\0';
			PutField_CString(myHash,"inter_ccy",(const char*)v_inter_ccy.arr);
DEBUGLOG(("GetSettlementDetail inter_ccy = [%s]\n",v_inter_ccy.arr));
		}

		if (ind_deliver_ccy>= 0) {
			v_deliver_ccy.arr[v_deliver_ccy.len] ='\0';
			PutField_CString(myHash,"deliver_ccy",(const char*)v_deliver_ccy.arr);
DEBUGLOG(("GetSettlementDetail deliver_ccy = [%s]\n",v_deliver_ccy.arr));
		}

		if (ind_request_amt< 0)
			v_request_amt= 0.0;
		PutField_Double(myHash,"request_amt",v_request_amt);
DEBUGLOG(("GetSettlementDetail request_amt = [%f]\n",v_request_amt));

		if (ind_inter_amt< 0)
			v_inter_amt= 0.0;
		PutField_Double(myHash,"inter_amt",v_inter_amt);
DEBUGLOG(("GetSettlementDetail inter_amt = [%f]\n",v_inter_amt));

		if (ind_deliver_amt< 0)
			v_deliver_amt= 0.0;
		PutField_Double(myHash,"deliver_amt",v_deliver_amt);
DEBUGLOG(("GetSettlementDetail deliver_amt = [%f]\n",v_deliver_amt));

		if (ind_sett_type >= 0) {
			PutField_Char(myHash,"sett_type",v_sett_type);
DEBUGLOG(("GetSettlementDetail sett_type = [%c]\n",v_sett_type));
		}

		if (ind_client_sett_bank_id >= 0) {
			PutField_Int(myHash,"client_sett_bank_id",v_client_sett_bank_id);
DEBUGLOG(("GetSettlementDetail client_sett_bank_id = [%d]\n",v_client_sett_bank_id));
		}

		if (ind_merchant_notify_email >= 0) {
                        PutField_Int(myHash,"merchant_notify_email",v_merchant_notify_email);
DEBUGLOG(("GetSettlementDetail merchant_notify_email = [%d]\n",v_merchant_notify_email));
                }
	
		if (ind_country_subdivision>= 0) {
			v_country_subdivision.arr[v_country_subdivision.len] ='\0';
			PutField_CString(myHash,"country_subdivision",(const char*)v_country_subdivision.arr);
DEBUGLOG(("GetSettlementDetail country_subdivision = [%s]\n",v_country_subdivision.arr));
		}

		if (ind_city>= 0) {
			v_city.arr[v_city.len] ='\0';
			PutField_CString(myHash,"city",(const char*)v_city.arr);
DEBUGLOG(("GetSettlementDetail city = [%s]\n",v_city.arr));
		}

		if (ind_country>= 0) {
			v_country.arr[v_country.len] ='\0';
			PutField_CString(myHash,"country",(const char*)v_country.arr);
DEBUGLOG(("GetSettlementDetail country = [%s]\n",v_country.arr));
		}

		RecordSet_Add(myRec,myHash);

	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_get; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 27;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )260;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto get_error;
}



	if (iCnt > 0 ) {
DEBUGLOG(("GetSettlementDetail Normal Exit\n")); 
		return  PD_OK;
	}
	else {  
DEBUGLOG(("GetSettlementDetail Normal Exit, Not Found\n"));
		return PD_ERR;
	}

get_error:
DEBUGLOG(("get_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_get; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 27;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )275;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;

}


int GetRemark(const char* csTxnID, hash_t* hRls)
{
	int iCnt = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO getremark_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


		/* varchar		v_remark[PD_REMARK_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;

		short		ind_remark = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_id.len = strlen(csTxnID);
	memcpy(hv_txn_id.arr,csTxnID,hv_txn_id.len);
DEBUGLOG(("GetRemark txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

	/* EXEC SQL DECLARE c_cursor_getremark CURSOR FOR
		select	sd_remark
		from	merchant_settlement_detail
		where	sd_txn_id = :hv_txn_id; */ 


	/* EXEC SQL OPEN c_cursor_getremark; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 27;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0004;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )290;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_txn_id;
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
 if (sqlca.sqlcode < 0) goto getremark_error;
}


	do{
		/* EXEC SQL FETCH c_cursor_getremark
		INTO
			:v_remark:ind_remark; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 27;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )309;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_remark;
  sqlstm.sqhstl[0] = (unsigned long )258;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_remark;
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
  if (sqlca.sqlcode < 0) goto getremark_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		iCnt++;

		if (ind_remark >= 0) {
			v_remark.arr[v_remark.len] ='\0';
			PutField_CString(hRls,"remark",(const char*)v_remark.arr);
DEBUGLOG(("GetRemark remark = [%s]\n",v_remark.arr));  
		}
	}while(PD_TRUE);


	/* EXEC SQL CLOSE c_cursor_getremark; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 27;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )328;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getremark_error;
}



	if (iCnt > 0 ) {
DEBUGLOG(("GetRemark Normal Exit\n")); 
		return  PD_OK;
	}
	else {  
DEBUGLOG(("GetRemark Normal Exit, Not Found\n"));
		return PD_ERR;
	}

getremark_error:
DEBUGLOG(("getremark_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getremark; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 27;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )343;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int UpdateRemark(hash_t* hRls)
{
	char *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO updateremark_err; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		/* varchar	hv_remark[PD_REMARK_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_remark;

		/* varchar	hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;


		short	ind_txn_id = -1;
		short	ind_remark = -1;
		short	ind_update_user = -1;

		short	hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateRemark: Begin\n"));

//txn_id
	if (GetField_CString(hRls,"txn_seq",&csTmp)) {
		hv_txn_id.len = strlen(csTmp);
		strncpy((char*)hv_txn_id.arr, csTmp, hv_txn_id.len);
		ind_txn_id = 0;
DEBUGLOG(("UpdateRemark txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
	}

//remark
	if (GetField_CString(hRls,"remark",&csTmp)) {
		hv_remark.len = strlen(csTmp);
		strncpy((char*)hv_remark.arr, csTmp, hv_remark.len);
		ind_remark = 0;
DEBUGLOG(("UpdateRemark remark = [%.*s]\n",hv_remark.len,hv_remark.arr));
	}

//update_user
	if (GetField_CString(hRls,"update_user",&csTmp)) {
		hv_update_user.len = strlen(csTmp);
		strncpy((char*)hv_update_user.arr, csTmp, hv_update_user.len);
		ind_update_user = 0;
DEBUGLOG(("UpdateRemark update_user = [%.*s]\n",hv_update_user.len,hv_update_user.arr));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_merch_settle_dt_upd_remark(
								:hv_txn_id:ind_txn_id,
								:hv_remark:ind_remark,
								:hv_update_user:ind_update_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 27;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merch_settle_dt_upd_remark ( :\
hv_txn_id:ind_txn_id , :hv_remark:ind_remark , :hv_update_user:ind_update_use\
r ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )358;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_txn_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_remark;
 sqlstm.sqhstl[2] = (unsigned long )257;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_remark;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_update_user;
 sqlstm.sqhstl[3] = (unsigned long )22;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_update_user;
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
 if (sqlca.sqlcode < 0) goto updateremark_err;
}



DEBUGLOG(("UpdateRemark Ret = [%d]\n", hv_return_value));

	if (hv_return_value == SP_OK) {
DEBUGLOG(("UpdateRemark Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("UpdateRemark: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateRemark: SP_OTHER_ERR TxnAbort\n"));	
                return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("UpdateRemark: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateRemark: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

updateremark_err:
DEBUGLOG(("updateremark_err code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("UpdateRemark: SP_ERR TxnAbort\n");
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}
